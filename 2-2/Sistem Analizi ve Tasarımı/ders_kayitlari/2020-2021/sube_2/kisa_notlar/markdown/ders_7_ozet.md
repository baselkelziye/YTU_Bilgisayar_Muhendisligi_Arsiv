# Ders 7 Çalışma Özeti

## Genel Konular

- Önceki konuların yeri ve iki analiz yolu
  - Gereksinim analizinde işlevsel (yapısal) çözümleme yolu önceki derste işlendi: veri akış diyagramları, süreç formları, yapısal dil, karar tablosu ve karar ağacı.
  - İkinci yol nesneye yönelik çözümlemedir. Hoca bunu "problem uzayının modellenmesi" diye adlandırır: "problem uzayı" dediğinde nesneye yönelik, "işlevsel" dediğinde veri akış diyagramlarıyla yapılan çözümleme kastedilir.
- Problem uzayının modellenmesi (ekrandan, 00:10:00)
  - Amaç gerçek dünyanın (problemin) doğru, anlaşılır ve sınanabilir modelini oluşturmaktır.
  - Problemin anlaşılması aşamasıdır; teknik yorumdan çok müşteri isterleri ön plandadır.
  - İsteklerin modellenmesi (use case) nesneye dayalı değildi; burası nesneye dayalıdır.
  - Gerçek dünyadaki kavramsal sınıflar ve nesneler, o anda görülen özellikleri ve aralarındaki ilişkiler (bağlantılar) yer alır. Yazılım nesneleri henüz düşünülmez.
  - Model UML ile görselleştirilir, oluşacak sistem anlaşılır ve tasarıma girdi sağlanır (sorumlulukları atamak üzere).
  - Analiz "ne?" sorusunu cevaplar (ne kavramlar var, ne oluyor); tasarım "nasıl?" sorusunu cevaplar (nasıl çalışır, nasıl hizmet sunar).
- Kavramsal sınıf diyagramı (ekrandan, 00:15:00)
  - Analiz modelini gösteren, sınıf diyagramının özel bir hâlidir. Öğeleri: kavramsal sınıf (concept, domain object), bağlantı (association), çoğullama (multiplicity), nitelikler (attributes).
  - Slayttaki market (satış) örneği:

    ```text
    SalesLineItem [quantity]  0..1 --Records-sale-of-- 1  Item
    SalesLineItem 1..*        --Contained-in--       1  Sale [date, time]
    Item *                    --Stocked-in--         1  Store [address, name]
    Store 1                   --Houses--           1..* Register
    Sale 0..1                 --Captured-on--        1  Register
    Sale 1                    --Paid-by--            1  Payment [amount]
    ```

  - Müşteri (aktör) bu diyagramda gösterilmedi. Kavramsal sınıf diyagramında aktörler genellikle konmaz, ama yazılım sınıfları oluşurken büyük olasılıkla sınıf olarak yer alırlar.
- Analiz modelinden tasarıma örnek: öğrenci ve ders
  - Analizde "Öğrenci (adı)" ve "Ders (ders numarası)" kavramları ve "öğrenci ders alır" bağlantısı bulunur. Tasarımda bunlar `Student` (private `name: String`, `getAverage()`) ve `Course` (`courseNumber: String`, private `grade`, `getGrade()`) yazılım sınıflarına dönüşür.
  - Ders kodu harf de içerdiği için (BLM2042) string olarak modellenir. Not içeride 100 üzerinden tutulup `getGrade()` ile harf, 4'lük ya da 10'luk karşılık olarak dışarı verilebilir: veri gizli, hizmetler farklılaşabilir.
- Kavramsal sınıfların bulunması (ekrandan, 00:25:00)
  - Gerçek dünyadaki somut ya da soyut varlıklar aranır. Üç yaklaşım vardır:
    - Kategori listesi: deneyimle sık karşılaşılan kategoriler (ders, öğrenci, not). Görünen sınıfları bulur, ama alana özgü sınıfları (örneğin satış satırı) gözden kaçırma olasılığı yüksektir.
    - Senaryolardaki isimler ve isim tamlamaları: tüm isimler aday sınıf olarak alınır; çoğunlukla fazla sınıf çıkar ve elenir.
    - Var olan model güncellemesi: daha önce yapılmış ya da yayımlanmış modellerin uyarlanması.
  - Yeni ve tanınmayan bir problem uzayında en doğru yol senaryolardan yola çıkmaktır.
- Örnek: isim işaretleme (ekrandan, 00:30:00)
  - "Process Sale" senaryosunda işaretlenen isimler: Customer, POS checkout, goods, services, Cashier, sale, item identifier, sale line item, item description, price, total, price rules, taxes, payment, Accounting, commissions, Inventory, receipt; nakit ödeme uzantısında (7a) cash, amount tendered, balance due.
  - "System" işaretlenmez, çünkü çözülmeye çalışılan problemin kendisidir.
- Gereksiz sınıfların elenmesi (ekrandan, 00:35:00)
  - Fazlalık sınıflar: aynı unsuru ifade edenlerden daha tanımlayıcı olan kalır (kişi, müşteri: Müşteri).
  - İlgisiz sınıflar: çözümle ilgisi olmayan ya da o aşamada ilgilenilmeyecek sınıflar (yalnız nakit ödeme çözülürken Kredi Kartı).
  - Belirsiz sınıflar: sınırları iyi çizilmemiş, kaba ve geniş tanımlı, genellikle birden fazla sınıftan oluşan ya da başka sınıfın parçası olanlar (Muhasebe Sistemi).
  - Nitelikler: kendi başına varlığı anlamlı olmayan, sınıfların özellikleri olanlar (Miktar).
  - İşlemler: yalnız nesnelere uygulanan işlemler sınıf olmaz; sınıfın kendi nitelikleri olmalı ve hizmet alışverişi yapmalıdır (Ödeme: miktar, para birimi, tarih ...).
  - Roller: sınıflar arası ilişki olan roller sınıf olamaz.
  - Gerçekleme elemanları: yazılım sınıfları (arayüz düğmeleri, veri tabanı nesneleri) bu uzayda yer almaz.
  - Sınıf testi soruları: kavramla ilgili veri saklanması gerekiyor mu, farklı değerler alabilecek birden çok özelliği var mı, kavramdan birçok nesne türeyebilir mi, uygulamanın kapsama alanı içinde mi, sınırları iyi çizilmiş ve tanımı yapılabiliyor mu?
- Betimleme sınıfı (description, specification) ihtiyacı (ekrandan, 00:40:00)
  - Satışta nesneler ürünleri tutarsa, bir cinsten tüm ürünler satıldığında hiç nesne kalmaz ve bilgi kaybı olur. Bu yüzden ortak özellikler ayrı bir sınıfta tutulabilir.
  - İlk model: `Item [description, price, serial number, itemID]`. Düzeltilmiş model: `ProductSpecification [description, price, itemID]` 1 --Describes-- * `Item [serial number]`.
  - Gerçek dünyada "ürün tanımı" diye bir nesne yoktur, ama veri kaybını önlemek için kullanılır. Seri numarası takibi gerekiyorsa (örneğin garanti) farklı bir kavram (servis takibi gibi) gerekebilir.
- Sınıf gösterimi
  - Sınıf genellikle üç bölmeli çizilir: ad, özellikler, metotlar. Kavramsal sınıflar iki bölmelidir (ad ve öz nitelikler), çünkü davranışlar henüz eklenmez.
  - UML esnek bir dildir: dört ya da beş bölmeli sınıflar (istisnalar, tetiklenen olaylar gibi) da tanımlanabilir.
- Bağlantıların belirlenmesi (ekrandan, 00:45:00)
  - Bir nesnenin kaç nesneyle ilişkili olacağı çoğullama ile gösterilir.
  - Bağlantılara tip-fiil-tip biçiminde doğru isimler verilir ("öğrenci alır ders"). Bazı bağlantıların unutulması tasarımı çok etkilemez; kavramsal sınıfların doğru bulunması daha önemlidir. Fazla bağlantı anlaşılırlığı azaltır.
  - Yaygın bağlantılar listesinden (fiziksel barındırma, mantıksal barındırma, kayıt ilişkisi, kullanım ilişkisi, tanım, sahiplik ...) ya da kullanım senaryolarındaki fiillerden yararlanılır.
- Gereksiz bağlantıların elenmesi (ekrandan, 00:50:00)
  - Elenen sınıflar arası, sistemin amacı dışındaki ve gerçeklemeyi ilgilendiren bağlantılar gereksizdir.
  - Faaliyetler bağlantı değil etkileşimdir ("ATM kredi kartı kabul eder" ileride bir metot çağrısı olur).
  - Üçlü bağlantılar ikili hâle çevrilir: "Memur hesapla ilgili işlemleri girer" yerine "Memur işlemleri girer. İşlemler hesapla ilgilidir."
- Örnek bağlantılar (ekrandan, 00:55:00)

  ```text
  Store 1    --Contains--     1..* Register
  Register 1 --Captures--     1..* Sale
  Sale 1     --Paid-by--      1    Payment
  Airline 1  --Employs--      1..* Person
  Person 1..*  --Assigned-to--  *  Flight
  Flight *   --Assigned-to--  1    Plane
  Person 1   --Supervises--   *    Person
  ```

- Satış sisteminin tam kavramsal modeli (ekrandan, 01:10:00; 01:30:00)

  ```text
  ProductCatalog 1   --Contains--          1..* ProductSpecification [itemID, description, price]
  ProductCatalog 1   --Used-by--           *    Store [name, address]
  ProductSpecification 1 --Describes--     *    Item
  Store 1            --Stocks--            *    Item
  Store 1            --Houses--            1..* Register [id]
  Ledger 1           --Records-accounts-for-- 1 Store
  Ledger 1           --Logs-completed--    *    Sale [date, time, /total]
  SalesLineItem [quantity] 1..* --Contained-in-- 1 Sale
  SalesLineItem 0..1 --Records-sale-of--   1..* Item
  Sale 0..1          --Captured-on--       1    Register
  Sale 1             --Paid-by--           1    Payment [amount]
  Sale 1             --Is-for--            1    Customer
  Register 1         --Works-on (Cashier'dan okunur)-- 1 Cashier [id]
  ```

  <!-- BELİRSİZ: Records-sale-of bağlantısının Item ucundaki çoğullama karede "1..*" okunuyor; ürün tanımının üstünde ayrıca bir "1" var. Basit diyagramda (00:15:00) bu uç "1" idi. -->

- Özelliklerin belirlenmesi (ekrandan, 01:20:00)
  - Özellik: nesne yaratıldığında nesneye özgü değer alabilen veridir. Senaryolarla ilgili nitelikler bulunmalı ve basit veri tipleriyle ifade edilmelidir.
  - Birimi varsa (para gibi) basit özellik olarak yazmak doğru değildir; karmaşık tipteyse başka bir sınıf olma olasılığı yüksektir: birden fazla alansa (telefon numarası, ad soyad), işlem yapılıyorsa (kredi kartı ve doğrulama), kendi nitelikleri varsa (fiyat ve geçerlilik tarihi).
  - Slayt örneği: `Cashier [name, currentRegister]` yanlıştır (currentRegister basit bir özellik değil); doğrusu `Cashier [name]` 1 --Uses-- 1 `Register [number]`.
- Özellik ayrıntıları (ekrandan, 01:25:00)
  - `Sale`: `- dateTime : Date`, `- / total : Money`. `-` private görünürlük, `/` türetilmiş (diğer niteliklerden hesaplanan) nitelik demektir.
  - `Math`: `+ pi : Real = 3.14 {readOnly}`. `+` public görünürlük, `{readOnly}` sabit değer (bir dilde `final`, başka bir dilde `const`).
  - `Person`: `firstName`, `middleName : [0..1]`, `lastName`. `[0..1]` seçime bağlı (opsiyonel) değerdir.
- Use case modeli, alan modeli ve tasarım modeli ilişkisi (ekrandan, 01:40:00)
  - Use case'ler (Process Sale), sistem sıralama diyagramları (makeNewSale, enterItem(id, quantity), endSale, makePayment(amount)) ve sözleşmeler (Operation: enterItem; Post-conditions: bir SalesLineItem örneği oluşturuldu) alan modelini (Sale 1 -- 1..* SalesLineItem) besler.
  - Alan modeli tasarım modelini besler: `:Register` nesnesine `enterItem(itemID, quantity)` gelir, `:Register` `spec := getProductSpec(itemID)` ile `:ProductCatalog`'dan ürün tanımını alır, `addLineItem(spec, quantity)` ile `:Sale`'e satır ekler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kavramsal sınıflar yazılım sınıfları değildir
  - Analizde yalnız problem uzayının kavramları modellenir. Arayüz, veri tabanı erişimi gibi yazılım uzayının ayrıntıları bu modele girmez.
- Her isim sınıf değildir
  - Senaryolardaki isimler yalnız adaydır. Tutar, miktar gibi isimler büyük olasılıkla bir sınıfın özelliği olur; toplam tutar o anda hesaplanan bir değerdir, ayrı sınıf olmaz.
- Bağlantılara mutlaka isim verilmeli
  - Bir bağlantının adı (fiili) yazılamıyorsa o bağlantı büyük olasılıkla gereksizdir. Az bağlantı az bağımlılık demektir.
- Tek bir doğru model yoktur
  - Farklı analistler farklı varsayımlarla farklı modeller çıkarabilir: muhasebe tarafını, müşteriyi ya da kasiyeri modelden çıkarmak varsayıma göre doğru sayılabilir. Ama senaryoda bir kavramın rolü ve sorumluluğu varsa modelde bulunmalıdır.
- Kavramsal modelde davranış (metot) yoktur
  - Analiz "ne" sorusunu sorar. `getTotal()`, `getSubTotal()`, `getPrice()` gibi metotlar işin nasıl yapılacağının ayrıntısıdır ve tasarımda belirlenir.
- Model hem teknik hem teknik olmayan tarafa hitap eder
  - Müşteri diyagramı anlayıp düzeltme önerebilir (örneğin birden çok ödeme türü); yazılımcı da yazılım sınıflarını eklemeye bu temelden başlar.

## Kısa Tekrar Notları

- Problem uzayının modellenmesi = nesneye yönelik analiz; sonuç kavramsal sınıf diyagramıdır (alan modeli, domain model).
- Analiz "ne", tasarım "nasıl" sorusunu cevaplar.
- Kavramsal sınıf diyagramı: kavramsal sınıflar, bağlantılar, çoğullamalar, nitelikler. Metot yoktur, sınıflar iki bölmelidir.
- Kavramsal sınıf bulma: kategori listesi, senaryolardaki isimler, var olan model güncellemesi. En iyisi senaryolardaki isimleri işaretlemektir.
- Elenecekler: fazlalık, ilgisiz, belirsiz sınıflar; nitelikler; işlemler; roller; gerçekleme elemanları.
- Betimleme sınıfı (ProductSpecification), tüm nesneler yok olduğunda bilgi kaybını önler.
- Bağlantılar senaryolardaki fiillerden bulunur, tip-fiil-tip biçiminde adlandırılır; üçlü bağlantılar ikiliye çevrilir.
- Özellikler basit veri tipinde olmalı; birimli, çok alanlı, işlem yapan ya da kendi niteliği olan özellik ayrı sınıftır.
- Gösterimler: `-` private, `+` public, `/` türetilmiş, `{readOnly}` sabit, `[0..1]` opsiyonel.
- Süreç: use case'ler, alan modeli, tasarım modeli (sıralama diyagramları), gerçekleştirme.

## Detaylı Açıklamalar

- Nesneye yönelik analizin mantığı
  - İşlevsel çözümlemede sistem işlev gruplarına (kayıt, hesaplama, fatura işlemleri) bölünür. Nesneye yönelik çözümlemede ise gerçek dünyadaki nesneler bulunup yazılımın içine onların gerçek hayattaki hâlleriyle konmaya çalışılır. Nesne, bir sınıf şablonundan türetilen, görünen özellikleri ve başka nesnelerle ilişkileri olan yapısal birimdir. Analizde yazılım nesneleri değil kavramsal nesneler düşünülür; bunun için use case belgelerinin üzerinden geçilerek kavramsal sınıflar bulunur ve UML sınıf diyagramıyla gösterilir.
- Market örneğinin gözlemle kurulması
  - Hoca örneği bir market ziyaretiyle anlattı: dükkân, kasa, ürünler, satış ve ödeme gözlenir. Kasiyer ürünün barkodunu okutur, miktar girer (örneğin "3 x"), ekranda ve fişte her ürün satır satır görünür; sonunda genel toplam alınır ve ödeme yapılır. Bu gözlemden satış, satış satırı (miktar özelliğiyle) ve ödeme (tutar özelliğiyle) kavramları çıkar. Satış ile ödeme arasındaki 1-1 çoğullama, gözlenen basit dükkânın yalnız nakit ve tek ödeme kabul ettiğini gösterir; parçalı ödeme ayrı bir senaryodur. Bir satışta en az bir, en fazla n satış satırı vardır.
- Senaryodan aday sınıf bulma ve eleme
  - Senaryo metnindeki isimler ve isim tamlamaları kalemle işaretlenir (ortaokul dil bilgisi gibi). Daha önce işaretlenen isim yeniden işaretlenmez; "new sale" gibi sıfatlı ifadede yalnız isim (sale) alınır. Ardından eleme yapılır: kişi ve müşteri aynı kavramsa daha tanımlayıcı olan "müşteri" kalır ve senaryolar da buna göre güncellenir; nakit ödeme senaryosu çözülürken kredi kartı ilgisizdir; muhasebe sistemi belirsiz ve kompozit bir kavramdır, belki yalnız onun bir arayüzüyle konuşulur; "amount tendered" (verilen miktar) kendi başına anlamlı değildir, ödemenin bir özelliğidir. Bir kavram için "hakkında veri tutmam gerekiyor mu, ondan birçok nesne türetebilir miyim?" diye sorulur: birden çok müşteri ve ürün nesnesi olabilir, ama toplam tutar o anda hesaplanan bir değerdir.
- Betimleme sınıfı örneği
  - Dükkândaki her ekmek ayrı bir nesne olsun; 50 ekmek satıldığında hiç ekmek nesnesi kalmaz ve ekmeği tanımlayan veri (ad, fiyat, KDV oranı) kaybolur. Bu yüzden `ProductSpecification` tanıtılır: ad, fiyat ve ürün kodu burada tutulur; `Item`'da yalnız seri numarası kalır. Bir tanım n tane ürünü tanımlar. Bu çözüm her satış sisteminde aynı olmak zorunda değildir; örneğin seri numarasıyla garanti takibi gereken bir işte servis takibi gibi başka bir kavram gerekebilir.
- Tam modelin okunması
  - Modelin merkezinde dükkân vardır. Dükkân ürünleri stoklar; ürün tanımları bir ürün kataloğunda tutulur ve katalog dükkân tarafından kullanılır. Katalog kavramı zorunlu değildir: doğrudan "Store contains ProductSpecification" da denebilirdi; bu farklı ama yanlış olmayan bir çözümdür. Dükkân bir ya da daha çok kasa barındırır, kasiyer kasada çalışır (okla okuma yönü gösterilir). Kasiyer ile fiyat arasına bağlantı çizilmez; bu bilgi kasa ve satış üzerinden zaten akar. Satış en fazla bir kasada kaydedilir, her satışın bir ödemesi ve bir müşterisi, bir ile n arası satış satırı vardır; satış satırı da Records-sale-of bağlantısıyla ürüne bağlanır. Satıştaki `/total` türetilmiş bir özelliktir: satır miktarları ve ürün tanımlarından gelen fiyatlarla hesaplanır.
  - Müşteri farklı ödeme türleri kabul ettiğini söylerse ödeme için bir genelleştirme ilişkisi eklenir: `Payment` altında `CashPayment`, `CreditCardPayment`, `CouponPayment` (hocanın tahtada çizdiği ek).
- Karmaşık özelliğin sınıfa dönüşmesi
  - Ürün tanımındaki fiyatın bir geçerlilik tarihi varsa, fiyat ayrı bir `Price [validDate]` kavramı olur ve ürün tanımına 1-1 bir bağlantıyla (describes gibi) bağlanır (hocanın tahtada çizdiği ek). Kasiyerin kasası da kendi özellikleri olan bir kavram olduğu için özellik yerine bağlantıyla gösterilir.
  - `Date` ve `Money` gibi tipler normalde ayrı kavram olarak gösterilmelidir; diyagramı sade tutmak için bunlar bir kenarda bir kez gösterilip özelliklerin tipi olarak yazılabilir.
- Alan modelinden tasarıma geçiş
  - Use case'teki "Cashier enters item identifier" adımı tasarımda `enterItem` metodu olur. Kasiyer kasaya ürün kodunu ve miktarı (örneğin 3 adet) verir; kasa ürün kataloğundan ürün bilgilerini (ad, fiyat, vergi) ister, sonra satışa satır ekler. Her sorumluluk için ayrı bir sıralama diyagramı gerekir. Böylece iş analizinden kavrama, kavramdan çözüme, çözümden gerçekleştirmeye gidilir.

> **Ders sonrası not:** Hoca tam modeldeki `Ledger` sınıfını "muhasebeci" diye okudu. `Ledger` büyük olasılıkla bir kişi değil, muhasebe defteri (hesap kayıt defteri) kavramıdır; satışların kaydını tutan budur.

> **Ders sonrası not:** Hoca 869 ile başlayan barkodların 8 haneli olduğunu söyledi. Türkiye ön ekli (869) ürün barkodları büyük olasılıkla 13 haneli EAN-13 kodlarıdır; 8 haneli EAN-8 kodları da vardır ama yaygın market barkodu 13 hanelidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
