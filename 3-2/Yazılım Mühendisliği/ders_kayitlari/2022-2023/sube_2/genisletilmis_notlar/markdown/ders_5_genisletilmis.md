# Ders 5 Genişletilmiş Notu: Kullanım Şemaları, Alan Modeli ve Tasarım Ölçütleri (Bağlaşım ve Uyum)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kullanım Şemaları (Use Case Diagrams)
- 2. Satış Senaryosunun Kullanım Şemasını Birlikte Çizmek
- 3. Nesneye Yönelik Çözümleme: Sınıfların Belirlenmesi
- 4. NextGenPOS Örneğinde Aday Sınıfların Elenmesi
- 5. Alan Modelinin (Sınıf Şemasının) Kurulması
- 6. Satış Kalemi: Araya Giren İlişki Nesnesi
- 7. Çözümleme Aşamasını Tamamlamak
- 8. Nesneye Yönelik Tasarım Sürecine Giriş
- 9. Tasarım Ölçütleri
- 10. Bağlaşım (Coupling)
- 11. Uyum (Cohesion)
- 12. Veritabanı Sorumluluğu Kimde Olmalı?
- Örnek Sorular
- Dersin Toparlaması

## 1. Kullanım Şemaları (Use Case Diagrams)

Önceki derste kullanım senaryosu metinleri yazılmıştı. Bu metinler sistemin davranışını ayrıntılı tanımlamak için çok iyi araçlardır, ama ayrıntıların yanında sistemin geneline de bakabilmek gerekir. Kullanım şemaları, kullanım senaryolarının birbiriyle ilişkileri üzerinden sisteme genel bir bakış sağlar.

### 1.1 Çizim kuralları

Slayttaki "Kullanım Şemaları – Use Case Schemas / Çizim Kuralları" sayfasında (ekrandan, 00:15:00) şu öğeler vardır:

- **Use case (işlev):** Öyküsü yazılan her kullanım senaryosu bir elipsle gösterilir.
- **İnsan aktör (kullanıcılar):** Çöp adamla çizilir, altına kişi türü adı yazılır.
- **İnsan olmayan aktör:** Başka bir yazılım ya da donanım bileşenidir. Dikdörtgen içinde `<<actor>> HW/SW Element` biçiminde, UML stereotip karakterleri içinde "actor" yazılarak gösterilir.
- **Etkileşim (kullanım):** Aktörü senaryoya bağlayan düz çizgidir; ok ucu yoktur.
- **İlişki (benzeşim):** Senaryolar arasındaki kesikli oktur.

Slayttaki genel örnekte bir kişi türü Use Case A'ya düz çizgiyle bağlıdır. Use Case A'nın elipsi ikiye bölünmüştür, alt bölümde "Extension Points: Adım K, Adım L" yazar. Use Case B, A'ya `<<extends>>` ile bağlıdır; A ise Use Case C'ye `<<includes>>` ile bağlıdır. C'ye insan olmayan bir aktör bağlıdır.

Senaryoya yalnız **birinci aktör** bağlanır. Bir sistemde çok sayıda kullanım senaryosu olacağından bütün aktörler bağlanırsa çizgiler birbirine karışır ve şemanın okunabilirliği çok düşer.

### 1.2 Include ve extend

Senaryolar arasında iki tür ilişki vardır:

- **`<<include>>` (içerme):** Adı üstünde, bir senaryonun başka bir senaryoyu içermesidir. Ön koşul olarak da düşünülebilir. Örneğin satış senaryosu başlamadan önce kasiyerin sisteme giriş yapmış olması gerekiyordu; bu yüzden satıştan login'e bir include oku çizilir.
- **`<<extend>>` (genişletme):** Bir senaryonun diğerinin alternatif senaryosu olması anlamına gelir. Örneğin ürün iptali, satışın alternatif senaryosudur.

Okun yönünü bulmanın kolay yolu ilişkiyi İngilizce cümle gibi okumaktır. "Sales includes login" doğru bir cümledir, bu yüzden include oku satıştan login'e doğrudur. "Cancellation extends sales" ya da "cancellation is an alternative scenario of sales" doğrudur, bu yüzden extend oku iptalden satışa doğrudur. Ters yönde çizilen oklar yanlıştır.

> **Hocanın vurgusu:** Kullanım şeması çizerken include ve extend ilişkilerinin adlarını doğru yazmak yetmez. Okların yönünü ve okların gövdesini (kesikli çizgi) de doğru çizmek gerekir; bunların hepsine tek tek bakılır.

Hoca birkaç örnek daha verdi. Her satış mutlaka bir ödeme içerir, bu yüzden "satış include ödeme" yazılır ve ok satıştan ödemeye gider. Ödemenin bir alternatif senaryosu olarak **provizyon alma** düşünülür. Provizyon, kredi kartı ya da başka bir kartla ödeme yapılacağı zaman yapılan denetimdir: kartta yeterli bakiye var mı, kart bilgileri doğru girilmiş mi, kartın süresi geçmiş mi, kart çalıntı ya da iptal edilmiş olarak işaretlenmiş mi? Bunların hepsi doğruysa ödeme kabul edilir. Her ödeme kartla yapılmadığı, nakit de olabildiği için her ödeme provizyon gerektirmez. Bu yüzden provizyondan ödemeye bir extend oku çizilir.

### 1.3 Senaryolar arasında kalıtım

Kullanım şeması araçlarında bir genelleme (generalization) oku da vardır. Kullanım senaryoları arasında da sınıflardaki kalıtımla aynı mantıkta bir kalıtım ilişkisi kurulabilir. Hoca, bunun mutlaka kullanılması gereken bir örnek bulamadığını, include ve extend'in hemen her durumu kapsadığını söyledi. Buradaki "extends" kelimesinin Java'daki kalıtım anahtar kelimesi `extends` ile karıştırılmaması gerekir; genelleme okunun üstüne "extends" yazmak yanlış olur.

> **Hocanın vurgusu:** Deneyimli tasarımcılar, sınıf tasarımında da tam oturan bir "is-a" ilişkisi yoksa kalıtım dışındaki çözümleri tercih eder. Bu yüzden kullanım şemalarına da kalıtımı sokmaya gerek görülmedi; yalnız var olduğu bilinmelidir.

## 2. Satış Senaryosunun Kullanım Şemasını Birlikte Çizmek

Hoca, önceki derste yazılan satış kullanım öyküsünden yola çıkarak şemayı bir UML aracında (Violet UML Editor) derste birlikte çizdi. Öyküde (ekrandan, 00:20:00) birincil aktör kasiyerdir; ilgililer kasiyer, satıcı ve müşteridir; ön koşul kasiyerin kimliğinin doğrulanması, son koşullar ödemenin tahsil edilmesi, satışın kaydedilmesi ve fişin yazılmasıdır.

Çizim adımları şöyle ilerledi:

- Satış senaryosu bir elips olarak konur. Birinci aktör Kasiyer çöp adamla çizilir ve Satış'a düz çizgiyle bağlanır.
- Ön koşul kasiyerin kimliğinin doğrulanmasıdır. Her satış ön koşul olarak kimlik doğrulamayı gerektirdiği için Satış `<<include>>` Kimlik Doğrulama çizilir.
- Diğer ilgililer şemada gösterilmez. Son koşullarda yazanlar ana metinde de geçtiği için ek bir senaryo çıkmaz.
- Kasiyerin yeni bir satış işlemi başlatması ayrıntılı anlatılmaya ihtiyaç duyduğu için Satış `<<include>>` Yeni Satış Başlat eklenir.
- Barkod girmek basit bir iştir (barkodu okuyucuya göstermek); ayrı bir senaryo olmasına gerek yoktur. Toplam hesaplama da basit bir işlemdir. Ödemenin yapılması ise ayrıntılıdır, bu yüzden Satış `<<include>>` Ödeme eklenir.
- Alternatif senaryolardan Geçersiz Barkod ve Ürün İptal (müşterinin bir ürünü alış-verişten çıkarmak istemesi) Satış'ı `<<extend>>` eder.
- Provizyon, Ödeme'yi `<<extend>>` eder, çünkü nakit ödemede provizyon gerekmez.

Ortaya çıkan şema (ekrandan, 00:25:00):

| Kaynak | İlişki | Hedef |
|---|---|---|
| Kasiyer | düz çizgi | Satış |
| Satış | `<<include>>` | Kimlik Doğrulama |
| Satış | `<<include>>` | Yeni Satış Başlat |
| Satış | `<<include>>` | Ödeme |
| Geçersiz Barkod | `<<extend>>` | Satış |
| Ürün İptal | `<<extend>>` | Satış |
| Provizyon | `<<extend>>` | Ödeme |

**Soru (hocanın öngördüğü itiraz):** Kasiyer zaten giriş yapmışsa tekrar giriş yapmaz; o zaman bu ilişki extend olmamalı mı? **Cevap:** Bu durum alternatif senaryoda yer alır. Extend yalnız alternatif senaryoda yer alan durumlar için düşünülür. Ana akışta her satış kimlik doğrulamayı içerdiği için ilişki include'dur.

Araçla ilgili pratik bir not: elipsin boyu yazılan metne göre büyür; uzun bir ad yeni satıra bölünerek daha toplu bir elips elde edilebilir. Etiketler okunaksız kalıyorsa farklı yerleşimler denenebilir.

### 2.1 Ödeme türleri üzerine bir düşünce alıştırması

Hoca, ödeme ile provizyon arasındaki kısmı ayrı bir şemaya alıp bir alternatif tartıştı (ekrandan, 00:45:00). Ödeme'den Nakit, Kredi/Banka Kartı ve Yemek Kartı senaryolarını genelleme (kalıtım) okuyla türetti; Provizyon yine Ödeme'yi genişletiyordu. Burada bir sorun vardır: kalıtımda üst senaryodaki her şey alt senaryolara geçer, dolayısıyla Provizyon'un extend ilişkisi nakit ödemede de varmış gibi görünür, oysa nakit ödemede provizyon gerekmez. Hoca bu çözümü beğenmedi.

Ardından kalıtım kullanmadan bir çözüm kurdu: ödeme bazen provizyon gerektirir; ödeme bazen nakit, bazen kredi/banka kartı, bazen yemek kartıyla yapılır. Bunlara bir fiş basma ve bir fatura basma senaryosu eklenebilir (örneğin büyük yapı marketlerde fatura isteyip istemediğiniz sorulur, marketlerde sorulmaz). <!-- BELİRSİZ: Fiş basma ve fatura basma senaryolarının diğer senaryolara hangi ilişkiyle bağlandığı karede görünmüyor, altyazıdan da net çıkmıyor. --> Hoca, bunların gereksinimlerde geçmediğini, yalnız gerçek hayat deneyimine dayanan bir "fikir jimnastiği" olarak tartışıldığını belirtti ve kalıtım kullanmadan da ayrıntılı bir çözüm kurulabildiğine dikkat çekti.

## 3. Nesneye Yönelik Çözümleme: Sınıfların Belirlenmesi

Çözümleme aşamasında nesnelerin ve aralarındaki ilişkilerin de belirlenmesi gerekir; bu, sınıf şeması çizilerek yapılır. Sınıf şemasının çizim kuralları Nesneye Yönelik Programlama dersinde görülmüştü. Ancak birden fazla tasarım alternatifi varsa hangisinin en iyi olduğu orada ayrıntılı işlenmemişti; o dersin sınavlarında genelde hazır bir tasarım verilip kodlanması istenirdi. Gereksinimlerden tasarıma geçmek için kod deneyimi bir altyapı sağlar. Daha iyi tasarım yapmak için tasarım kalıplarını (design patterns) öğrenmek de yararlıdır; hoca bunlara ileride kısa bir giriş yapacağını söyledi.

Yazılım bir gerçek dünya problemini kolaylaştırmak için geliştirilir. Problem alanındaki varlıklar kodda nesnelere karşılık gelir. Bu nesneler ve aralarındaki ilişkilere göre bir sınıf şeması oluşturulur. Bu şemaya **alan modeli** (domain model) denir.

### 3.1 Önerilen yöntem

Slayttaki "Sınıfların Belirlenmesi" sayfası (ekrandan, 00:25:00) yöntemi şöyle verir:

- Kullanıcı gereksinimleri belgesinden ve kullanım senaryolarından sınıflar elde edilir.
  - Metinlerdeki bütün isimler taranır ve aday sınıflar elde edilir.
  - Adaylar aşağıdaki kurallardan birini sağlamalıdır:
    1. **Saklanan bilgi:** Sistemin çalışması süresince bu varlığın durumu saklanmalıdır.
    2. **Gereksinim duyulan hizmetler:** Bu varlığın hizmetlerine ihtiyaç duyan başka varlıklar vardır.
    3. **Gerekli varlıklar:** Problemin çözümü ile ilgili bilgi üreten veya problemin çözümü için bilgi tüketen varlıklar.
- Değinilen kurallardan birini sağlayamayan adaylar, bir başka sınıfın üye alanı olarak değerlendirilebilir.
- Örnek gereksinim belgesinden (metin ve senaryolardan) sınıflar oluşturulur.

Bir aday bu kurallardan en az birini sağlıyorsa gerekli bir varlıktır ve alan modeline girer.

### 3.2 Çözümlemede "ne?", tasarımda "nasıl?"

Çözümleme aşamasında "ne?" sorusu sorulur, "nasıl?" sorusu sorulmaz. Bu yüzden alan modelinde nesneler, üye alanlar ve aralarındaki ilişkiler düşünülür, **metotlar düşünülmez**. Tasarım aşamasında alan modeli için oluşturulan üye alanlar sınıf şemasına aktarılır, metotlar eklenir ve şema güncellenir.

Üye alanlar metindeki **sıfatlara**, metotlar ise **eylemlere** bakılarak belirlenir. Eylemler çözümleme aşamasında düşünülmez, ama tasarım aşamasında bunlar göz önüne alınarak metotlar oluşturulur.

Sorumlulukların doğru dağıtılması önemlidir. Genel kural şudur: bir bilgiyle ilgili davranış o bilgiyle aynı sınıfta yer almalıdır. Bu yüzden analiz aşamasında hangi bilginin hangi sınıfta yer alacağına doğru karar vermek önemlidir; yanlış karar verilse bile tasarım aşamasında düzeltilebilir.

Sınıflar arasındaki ilişki türleri (bire çok, birebir, iki yönlü, tek yönlü, kalıtım yani özelleşme ve genelleşme) Nesneye Yönelik Programlama dersinde ayrıntılı işlenmişti.

## 4. NextGenPOS Örneğinde Aday Sınıfların Elenmesi

### 4.1 Gereksinim belgesi

Örnek gereksinim belgesi "NextGenPOS Perakende Satış Programı"dır (ekrandan, 00:35:00):

> Eski yazılım ihtiyaçlarımızı karşılayamadığından, yenilenecek donanımla birlikte perakende satış programımızın da yenilenmesine gerek duyuyoruz. Program kasada yapılan alış-veriş işlemlerine yardımcı olmalıdır. Yapılan her işlem program tarafından saklanmalı; mali bilgiler harici bütçe sistemine, mal çıkış bilgileri ise harici envanter sistemine iletilmelidir. Saklanan işlemler üzerinde daha sonra raporlamalar ve analizler yapılabilmelidir. Sistem yapılan alış-verişler karşılığında müşteriye fiş vermelidir. Yapılan her satış için KDV de hesaplanarak ayrıca belirtilmelidir. Şirketimizin birden fazla şubesi olup tüm şubelerdeki işlemler merkezi sunucuya iletilmelidir.

Satış kullanım öyküsünün ana akışı ise şöyledir (ekrandan, 01:25:00): müşteri kasaya alacağı ürünlerle gelir; kasiyer yeni bir satış işlemi başlatır; kasiyer ürünün barkodunu girer; sistem bir satış kalemi maddesi oluşturur, bu maddede ürün tanımı, fiyatı ve toplam bedel (aynı maldan birden fazla alınmış olabilir) yer alır; kasiyer 3. ve 4. adımları müşterinin alacağı tüm ürünler için tekrarlar; sistem toplam bedeli KDV ile birlikte hesaplar; kasiyer müşteriye toplamı bildirir ve ödeme ister; müşteri ödemeyi yapar ve sistem ödemeyi tahsil eder; sistem tamamlanan işlemin kaydını tutmayı tamamlar ve harici envanter ile mali sistemlere gerekli bilgileri gönderir; sistem fiş verir; müşteri ürünlerle birlikte ayrılır.

### 4.2 İsimlerin toplanması

Hoca metni okuyarak isimleri bir metin dosyasına yazdı (ekrandan, 00:35:00 ve 00:40:00). İlk cümle neden yeni yazılım gerektiğini anlattığı için atlandı. "Program" ve "sistem" zaten yazılmaya çalışılan sistemin kendisidir. "İşlem" ve "mali bilgi" çok genel kavramlardır; işlem aslında alış-veriş işlemidir. Bu aşamada problem alanına odaklanmak için harici bütçe ve envanter sistemleri dışarıda bırakıldı. Rapor ve analiz aynı şey sayıldı. Öyküden kasiyer, ödeme, ürün ve barkod adayları da eklendi. Böylece aday listesi şu oldu: Kasa, Alış-veriş, Rapor, Fiş, Müşteri, Satış, KDV, Şube, Kasiyer, Ödeme, Ürün, Barkod.

### 4.3 Kuralların uygulanması

Hoca her adayı üç kurala karşı denedi. Sonuç (ekrandan, 00:55:00):

| Aday | Karar | Gerekçe |
|---|---|---|
| Kasa | + | Yapılan bütün işlemler saklanacak, raporlar tutulacak; saklanan bilgi kuralını sağlar. |
| Alış-veriş | − | Satış ile eş anlamlı, aynı şey. |
| Rapor | − | Aslında gerekir ama sade tutmak için "üretilebilir bilgi" gerekçesiyle alınmadı. |
| Fiş | − | Tamamen üretilebilir bilgidir, gerekmez. Tek tip olduğu kabul edilir. |
| Müşteri | − | Sadakat/müşteri kartı (loyalty card) gereksinimlerde yok. |
| Satış | + | Kayıtları saklanır, ürün ekleme/çıkarma gibi hizmetler gerekir, bilgi üretir. |
| KDV | − | Ürünün üye alanı. |
| Şube | + | Şube bilgisi problemin çözümünde kullanılır. |
| Kasiyer | + | Kullanıcı hesabı saklanır; ders notunda sadeleştirme için alınmamıştı ama çok karıştırmıyor. |
| Ödeme | + | Kartlı ödemelerin onay bilgileri saklanmalıdır. |
| Ürün | + | Hepsini sağlar. |
| Barkod | − | Ürünün üye alanı. |

Adaylar üzerine ayrıntılar:

**Alış-veriş ve satış.** Alış-veriş başta bütün kuralları sağlıyor gibi göründü: hem tamamlanınca kaydı tutulur hem de alış-veriş sırasında ürün ekleme, çıkarma gibi hizmetler gerekir. Ancak satışa gelindiğinde ikisinin eş anlamlı olduğu görüldü: müşteri açısından alış, market açısından veriş yani satıştır. Hoca "satış" kelimesini tutmayı tercih etti ve alış-verişi eledi.

**Rapor ve fiş.** Rapor, yapılan işlemlerden yola çıkarak üretilen bir bilgidir. Fiş de bir kâğıt parçasıdır ve sistemde ayrıca saklanmaz; alış-veriş işlemlerinin kaydı zaten saklandığı için fiş her an yeniden üretilebilir. Hoca rapor için bir parantez açtı: gün sonu raporu, kasiyer raporu, genel satış raporu gibi farklı rapor türleri olacak ve her birinin biçimi ve içeriği farklı olacaktır. Bu bilgiler bir rapor sınıfında ve büyük olasılıkla onun alt sınıflarında tutulurdu; yani rapor aslında gereklidir. Yalnız çözümü karmaşıklaştırmamak için alınmadı. Fişin farklı türleri de yoktur; yemek kartıyla ödemede basılan ek çıktı gibi ayrıntılar dışarıda bırakıldı ve fişin tek tip olduğu kabul edildi.

**Müşteri.** Müşterinin bilgisi saklanmaz, hizmetlerine de ihtiyaç duyulmaz. Müşteri süreçte vardır ama sistemde onun bir metodunu çalıştırmak gerekmez; satışı kasiyer başlatır. Bazı büyük marketlerde sadakat kartı (loyalty card) uygulamaları vardır. Bunlar, firmanın kârlılığını artırmak için veri madenciliğiyle müşteri alışkanlıklarından kampanya üretmeye yöneliktir; örneğin çikolata alanın gofret de aldığı, cips alanın gazlı içecek de aldığı keşfedilir ve bu ürünler birlikte kampanyaya konur. Bu gereksinim örnekte olmadığı için müşteri elendi.

**KDV.** KDV saklanması gereken bir bilgi gibi görünür, çünkü toplam KDV hesaplanacaktır. Ancak KDV farklı ürünlerde farklı değer alır; ürüne bağlıdır.

> **Hocanın vurgusu:** KDV başlı başına bir şey, bir sınıf değildir. Ürünün üye alanı olmalıdır. Buna dikkat edin.

**Şube.** Şube için saklanan bilgi kuralı başta açık görünmedi. Hoca gerçek bir market fişini inceledi: fişte firmanın adı, satışın yapıldığı şubenin adresi ve vergi numarası, işlem tarihi, saati ve fiş numarası yazar. Tarih, saat ve fiş numarası şubeyle ilgili değildir; ama şubenin adı ve adresi fişte kullanılan bilgilerdir. Bu yüzden şube, problemin çözümüyle ilgili bilgi üreten gerekli bir varlıktır.

**Kasiyer.** Kasiyer giriş yapacağı için her kasiyerin bir kullanıcı hesabı olacaktır; bu hem saklanan bilgi hem gereksinim duyulan hizmet anlamında gereklidir. Hoca ders notunda sadeleştirmek için kasiyeri almamıştı, derste ise eklemeyi tercih etti.

**Ödeme.** Ödeme miktarı satışın toplamından üretilebileceği için saklanmasa da olur gibi düşünülebilir. Ancak kartla ödemede fişin yanında bir slip de basılır; bir kopyası müşteriye verilir, bir kopyası kasada kalır. Kâğıt kaybolabilir ya da yazıcının kâğıdı bitmiş olabilir. Slipte onay kodu, kartın son dört hanesi ve miktar gibi bilgiler yazar. Bu bilgilerin kasada saklanması önemli olduğu için ödeme alındı.

**Ürün ve barkod.** Ürün bütün kuralları sağlar; fiyatı ve KDV'si vardır. Barkod bilgisine ihtiyaç vardır ama barkod ürünün barkodudur, bu yüzden ürünün bir üye alanıdır.

## 5. Alan Modelinin (Sınıf Şemasının) Kurulması

Seçilen varlıklardan bir sınıf şeması çizildi. Üye alanların bu aşamada çok ayrıntılı düşünülmesi gerekmez; bulunanlar hemen eklenir. Üye alanı olmayan bir sınıf elbette olmaz. Ayrıca bir sınıftan diğerine çizilen her ok, okun başlangıcındaki sınıfa bitişteki sınıf türünden bir üye alan eklemek demektir; bu yüzden oklarla gösterilen üye alanlar ayrıca yazılmaz.

Hoca bir sınıfı şemaya koyduğunda önceden konmuş sınıflarla ilişkisini unutmadan hemen çizmeyi tercih etti. Adım adım:

- **Kasa → Satış (1 - \*):** Yapılan satış işlemleri kasada saklanır. Belirli bir kasada o gün hiç satış yapılmamış olabilir, bu yüzden çok tarafı `*` (sıfır olabilir) yazılır.
- **Şube → Kasa (1 - 1..\*), bütün-parça:** Kasalar şubelerde yer alır. Bir şubede en az bir kasa bulunması gibi mali kurallar olduğu için ilişki daha sıkıdır ve şubeden kasaya bütün-parça (aggregation) oku çizildi. Sıfır kasalı şube olamaz, bu yüzden kasa tarafına `1..*` yazıldı.
- **Şube ile satış arasında ilişki yok:** Şubede kasaların bilgisi, kasalarda da satışların bilgisi vardır. Bir şubenin satışları sorgulanmak istenirse kasa nesneleri üzerinden kümülatif olarak bulunur.
- **Kasa → Kasiyer (1 - 0..1):** Kasiyerlerin listesinin şubede tutulmasına gerek yoktur. Kasiyer kasaya giriş yaptığı için o anda oturum açmış kasiyer kasada tutulur. Kasada o anda kimse oturum açmamış olabilir, bu yüzden `0..1` yazıldı. Hesap bilgilerinin nerede saklanacağı ve kimlik doğrulamanın nasıl yapılacağı altyapıya yönelik bir tasarım kararıdır; burada düşünülmedi.
- **Satış → Kasiyer (1 - 1):** Fişin altında satışı yapan kasiyerin adı (kısaltılarak) yazar. Bu yüzden her satışın hangi kasiyer tarafından yapıldığı tutulur. Satıştan kasaya ters yönlü bir ok çizilseydi kasiyere oradan da ulaşılabilirdi, ama bu ters yönlü ilişkiye gerek yoktur.

> **Hocanın vurgusu:** Çift yönlü ilişkilerde tutarlılık denetimi epey ek iş ve çaba gerektirir. KISS (Keep It Simple) ilkesine uyun; ihtiyaç olandan fazlasına ulaşmaya çalışmak mantıksızdır.

- **Satış → Ödeme (1 - 1):** Kredi kartıyla, taksitle bile olsa her satış mutlaka bir ödeme içerir.
- **Şube → Ürün (1 - \*), bütün-parça:** Barkod okutulunca o barkodun hangi ürüne karşılık geldiği bilgisi bir yerde tutulmalıdır. Bir mağazaya yeni bir ürün geldiğinde (örneğin bir tahta kalemi, barkodu ve 20 liralık fiyatıyla) bu bilgiyi bütün kasalara tek tek yüklemek mantıklı değildir. Kasa zaten şubeyle bütün-parça ilişkisi içindedir, bu yüzden ürün bilgileri şubeye girilir. Kasa bir barkod girildiğinde ilgili ürünü şube üzerinden sorar. Bazı ürünler sürekli satılır, bazıları belirli günlerde gelir; bu yüzden ürün tarafına `*` yazıldı.

### 5.1 Üye alanların türleri

**Barkod: `String`.** Hoca bir ürünün barkodunun hanelerini saydı: 13 hane. Bu kadar uzun bir sayı `int`'e sığmaz, `long` gerekir. Rakamlardan oluşsa bile barkodu `String` tutmak daha mantıklıdır. Ayrıca kitaplarda barkod yerine ISBN numarası kullanılır ve ISBN'de X harfi bulunabilir; barkodlarda sayı dışı karakter geçebilir.

> **Ek bilgi (derste anlatılmadı):** Market ürünlerindeki 13 haneli barkodlar büyük olasılıkla EAN-13 standardındadır. 13 haneli bir sayı Java'da `int` (en çok yaklaşık 2,1 milyar) sınırını aşar, `long` sınırına ise sığar. ISBN-10'da son kontrol hanesi 10 değerini aldığında X ile yazılır.

**KDV ve fiyat: `float`.** Adlandırma standardında alanlar küçük harfle başlar, ama KDV bir kısaltma olduğu için büyük harfle yazıldı. KDV ondalıklıdır; oranlar çok fazla hassasiyet gerektirmediği için `double` yerine `float` yeterlidir. Fiyat da kuruşlu olabileceği için ondalıklıdır.

Şemanın ilk hâli (ekrandan, 01:25:00) şöyleydi: Ürün (barkod: String; fiyat, KDV: float), Şube, Kasa, Satış, Ödeme, Kasiyer. Satış ile Ürün arasında doğrudan bir ilişki (1 - 1..\*) vardı. Bu ilişki bir sonraki bölümde değiştirildi.

## 6. Satış Kalemi: Araya Giren İlişki Nesnesi

Hoca gerçek bir örnekle bir sorun ortaya koydu. Bir müşteri bir sudan 12 tane alır; bazı marketler 12'li ya da 24'lü alımda indirim yapar. Kasiyer 12 şişeyi tek tek okutmaz; klavyede 12'ye basıp bir kez okutur. Böyle senaryoların da modellenmesi gerekir. Başka bir müşteri aynı sudan 1 ya da 2 tane alabilir. Toplam fiyatı belirlemek için bir üründen kaç tane alındığının tutulması gerekir.

**İlk deneme: adeti Ürün'e koymak.** Bir satışta 12 yazılır, sonraki satışta 2 yazılır ve 2, 12'nin üzerine yazılır; eski bilgi kaybolur.

**İkinci deneme: Ürün'e bir "adetler" dizisi koymak.** Bu hiç doğru değildir. Nesneye yönelimin iyi kavranmadığını gösteren bir kod kokusudur (code smell).

**Üçüncü deneme: Satış'a ürünler dizisinin yanına bir adetler dizisi koymak.** İki farklı dizinin aynı indisli elemanları birbiriyle ilişkili olur. Bu da bir kod kokusudur.

Adet bilgisi ürüne konunca da satışa konunca da "sırıtır". Bu, arada başka bir şey olduğunu gösterir: araya bir **ilişki nesnesi** konmalıdır. Yapılan satışlarda hangi üründen kaç adet alındığı bilgisini saklayan bir ara sınıfa ihtiyaç vardır.

Bu sınıfa "işlem" gibi bir ad verilebilirdi, ama burada konu alanı bilgisi devreye girer. Mağaza, market ya da muhasebe gibi alanlarda "şu üründen şu kadar" bilgisine **kalem** denir: satış kalemi, ürün kalemi, bütçe kalemi (seyahat bütçesi, yatırım bütçesi, personel bütçesi gibi alt bütçeler). Kalem, bir listedeki elemanlar anlamında eskiden gelen bir kullanımdır ama bu tür problem alanlarında hâlâ kullanılır. Öyküdeki "satış kalemi maddesi" ifadesi de buna karşılık gelir.

Öyküye göre satış kalemi maddesinde ürün tanımı, fiyatı ve toplam bedel yer alır. Ancak ürünün tanımı ve fiyatı ürünün kendisindedir; bunlar satış kalemine alınmaz. Satış kaleminde yalnız o işlemde o üründen kaç adet alındığı bilgisi yer alır.

İlişkiler şöyle kuruldu:

- **Satış → SatışKalemi (1 - 1..\*):** Bir satış işleminde en az bir ürün satılır. Bir üründen tek bir tane alınsa bile adedi 1 olan bir satış kalemi nesnesi oluşturulur.
- **SatışKalemi → Ürün (1 - 1):** Her satış kalemi yalnız satılan bir malla ilgilidir.

Bire çok ilişkilerde dizi, liste ya da map kullanılabilir. Hoca, özellikle şube ile ürün arasındaki ilişkide map kullanmanın daha iyi olacağını söyledi: kasa barkodu sorduğunda listede ardışıl arama yapılır, map'te ise anahtar-değer (barkod → ürün) ilişkisiyle ürün doğrudan bulunur. Bunun bir tasarım konusu olduğunu da ekledi.

### 6.1 Son alan modeli ve ders notuyla karşılaştırma

Derste çizilen son şema (ekrandan, 01:35:00 ve 01:40:00):

| Sınıf | Üye alanlar |
|---|---|
| Ürün | barkod, tanim: String; fiyat, KDV: float |
| Şube | ad, adres, vergiNo: String |
| Kasa | (oklarla gösterilenler dışında yazılmadı) |
| Satış | tarih: Date |
| SatışKalemi | adet: int |
| Ödeme | miktar: double |
| Kasiyer | (yazılmadı) |

| İlişki | Çokluk |
|---|---|
| Şube ◇→ Kasa (bütün-parça) | 1 - 1..\* |
| Şube ◇→ Ürün (bütün-parça) | 1 - \* |
| Kasa → Satış | 1 - \* |
| Kasa → Kasiyer | 1 - 0..1 |
| Satış → Kasiyer | 1 - 1 |
| Satış → Ödeme | 1 - 1 |
| Satış → SatışKalemi | 1 - 1..\* |
| SatışKalemi → Ürün | 1 - 1 |

Hoca ders notundaki çözümle karşılaştırınca bazı eksikleri tamamladı. Ödeme'nin miktarı aslında hesaplanabilen bir bilgidir, ama ne kadar ödeme alındığı saklanması gereken en önemli bilgidir; ödemenin tarihi ve onay kodu gibi ek bilgiler de olabilir. Gereksinim belgesinde bunlar uzun uzun yazmasa da müşteri bunları "beklenen gereksinim" (expected requirement) olarak görür. Satışın tarihi fişte basıldığı için gereklidir (`Date`). Ürüne bir tanım (örneğin bir kalemin marka ve model adı) alanı, şubeye ad, adres ve vergi numarası alanları eklendi.

Ders notundaki örnek alan modeli (ekrandan, 01:35:00) şöyledir: SatışKalemi (miktar: int) "içerir»" ilişkisiyle Ürün'e (tanim: String; fiyat, kdv: double; barkod: String) 1 - 1 bağlıdır; Satış (tarih: Date) ile SatışKalemi arasında dolu elmaslı bütün-parça ilişkisi vardır (1 - 1..\*); Satış "içerir V" ilişkisiyle Ödeme'ye (miktar: double) 1 - 1 bağlıdır; Şube (ad, adres: String) ile Ürün arasında "stoklanır" ilişkisi (1 - \*) vardır; Şube ile Kasa arasında dolu elmaslı bütün-parça ilişkisi vardır; Kasa "« kaydeder" ilişkisiyle Satış'a bağlıdır. Ders notundaki çözümde Kasiyer yoktur. İlişki adlarının yazılması tamamen isteğe bağlıdır.

Hoca araçla ilgili bir ipucu da verdi: ilişki adının okuma yönünü göstermek için büyüktür/küçüktür işaretleri, aşağı için V harfi, yukarı için şapka işareti kullanılabilir. Bu, özellikle çift yönlü ilişkilerde adın hangi yöne okunacağını belirtmek için yararlıdır.

**Soru:** Ders notundaki şemada elmasın içi dolu, derste çizilen şemada boş. Bu yalnız çizim programıyla mı ilgili, yoksa aralarında anlam farkı var mı? **Cevap:** Çok küçük bir anlam farkı vardır ve farklı kaynaklar bunu farklı biçimde vurgular. Bir yorum, parça kısmına bakar: parça, bütün olmadan tek başına var olabiliyorsa içi boş (beyaz), var olamıyorsa içi dolu (siyah) elmas kullanılır. Hoca bu aşamada bunun çok önemli olmadığını söyledi. Elmas konursa elmasın tarafında da varsayılan bir ok ucu ve `1` çokluğu olduğu bilinmelidir; o yönde bir ilişki istenmiyorsa elmas yerine düz bir bire çok ilişki konması tavsiye edildi.

> **Ek bilgi (derste anlatılmadı):** UML'de içi boş elmas birleştirme (aggregation), içi dolu elmas bileşim (composition) ilişkisidir. Bileşimde parçanın yaşam süresi büyük olasılıkla bütüne bağlıdır: bütün yok edilince parçalar da yok edilir ve bir parça aynı anda yalnız bir bütüne ait olur.

## 7. Çözümleme Aşamasını Tamamlamak

Kullanım senaryosu metinleri yazıldı, kullanım şemaları ve bir sınıf şeması çizildi. Bunlara ek olarak çözümleme aşamasında şunlar da yapılabilir:

- **CRC kartları:** Sorumluluklar daha çok "nasıl?" sorusuna ve tasarıma yönelik görünse de analizle de ilgilidir. Analiz sırasında akla gelen tasarım düşünceleri unutulmasın diye CRC kartlarına not edilebilir.
- **ER şeması:** Veritabanı işlemleri de olacağı için bir ER şeması çizilebilir. Son hâli tasarım aşamasında yer alır, ama ER şemasında da varlıklar arasındaki ilişki seçenekleri bulunur.
- **Prototip ve taslak ekranlar:** Rapor ya da veri giriş ekranlarının nasıl olacağına ilişkin taslak ekranlar çizilebilir; bunlar bir kelime işlemcide hazırlanabilir ya da bir görsel geliştirme ortamında (örneğin Visual Basic .NET'te) sürükle-bırak ile prototipe yakın biçimde yapılabilir.

Bu yöntemlerle gereksinimler belgesine (Software Requirements Specification, SRS) içerik yazılabilir.

## 8. Nesneye Yönelik Tasarım Sürecine Giriş

Tasarım sırasında analizde çizilen şemalar zenginleştirilir, ayrıca yeni belgelendirmeler yapılır. Yalnız sınıf şeması işin "nasıl"ını yeterince açık anlatmaz. Kullanım senaryosu metinleri ise işin nasılını çok ayrıntılı anlatır, ama bazen birbiriyle ilişkili senaryoların kesişen kısımlarını, olayları ve etkinlikleri ayrıca anlatmak, anlamak ve tasarlamak gerekir. Bu şemaları yalnız belgelendirme olarak görmemek gerekir: bir senaryonun iç akışını şemalarla anlatmak, okumaktan çok görsel algıyla daha iyi anlayan kişilere de yardımcı olur.

**Artifakt (artifact):** Kod dışında üretilen her şeydir. Teknik ya da son kullanıcıya yönelik her türlü belge ve yazılımın sahaya sürülmesiyle (deployment) ilgili yapılandırma dosyaları gibi ürünler artifakttır.

Slayttaki "Nesneye Yönelik Tasarım Süreci – Giriş" sayfası (ekrandan, 02:00:00):

- "Nasıl?" sorusuna yanıt aranır.
- Nesne modeli: analizden tasarıma. Doğrudan problem alanı ile ilgili nesnelerden oluşan model, yardımcı nesnelerle zenginleştirilir.
- Ana işlem grupları:
  - Nesne tasarımı: Problem alanı ile ilgili nesneler.
  - Sistem tasarımı: Alt yapıyı ve gereçleri oluşturan nesneler.
- Sistem katmanında bulunabilecek bileşenler: yazılım mimarisi (istemci-sunucu, eşler arası, olay tabanlı vb.), kullanıcı arayüzü, veri yönetimi, ağ programlama.
- Sistem katmanını çoğunlukla kendimiz sıfırdan oluşturmayız, hazır altyapı programlarını (framework) kullanırız.

Alan modeli metotlarla ve ilişkilerin ayrıntılarıyla geliştirilir; gerekirse araya ek nesneler konur. Sistem katmanında önce yazılım mimarisine karar verilir: merkezi bir sunucuya bağlı istemcilerden oluşan istemci-sunucu mimarisi mi, blok zincirine katılan makineler ya da dosya paylaşım ağları gibi eşler arası (peer-to-peer) bir mimari mi, yoksa noktadan noktaya iletişim yerine olayların bir olay iletim hattına yayınlanıp sunucular ve istemciler tarafından dinlendiği olay tabanlı bir mimari mi? Kullanıcı arayüzünün nasıl gerçekleneceği de sistem katmanının konusudur. Bu konuların her biri başlı başına ayrı dersler ve kendini geliştirme alanlarıdır; bu derste daha çok nesne tasarımı, yani problem alanı nesnelerinin tasarımı üzerinde durulacaktır.

## 9. Tasarım Ölçütleri

Alan modelinde alternatif yoktur: varlıklar, alanlar ve ilişkiler problem alanında neyse odur ve birebir aktarılır. Ama "nasıl?" kısmına gelindiğinde, müşterinin isteklerini karşılayan ve problem alanındaki varlıkları ve ilişkilerini aynı tutan birden fazla tasarım alternatifi olabilir. Bunlardan hangisinin seçileceği çok önemli bir konudur. Tasarım ölçütlerinin bir kısmı yazılım kalitesi konusunda iç kalite ölçütleri olarak da incelenecektir.

Slayttaki tasarım ölçütleri (ekrandan, 02:05:00):

- **Ayrılabilirlik:** Anlamlı parçalara ayrılabilme.
  - Parça: sınıf ya da sınıf grubu.
  - Üstünde çalıştığımız problem hangi düzeyde alt problemlere bölünebiliyorsa, tasarımımız da aynı düzeyde ayrıştırılabilmelidir.
- **Birleştirilebilirlik:** Bir parçanın başka tasarımlarda da kullanılabilecek şekilde diğer parçalarla birleştirilebilmesi. Bu, yazılımın yeniden kullanımına yol açar ve masrafları düşürür.
- **Anlaşılabilirlik:** Bir parçanın diğer parçalar hakkında bilgiye gerek duyulmadan anlaşılabilmesi.
- **Süreklilik:** Yapılacak küçük değişikliklerin etkilerinin en az sayıda parçaya yayılması (tercihen tek sınıfa).
- **Koruma:** Olası hataların düzeltilmesine yönelik büyük değişikliklerin etkilerinin geniş bir alana yayılmasının önlenmesi.

Ayrılabilirlikte daha fazla ayrıştırmanın gerekip gerekmediği düşünülmelidir; bazen sistem tasarımına bakıldığında daha fazla ayrıştırmanın yararı keşfedilebilir, o zaman ayrıştırılır.

Anlaşılabilirlik için bir nesne bir sorumluluğu çoğu zaman başka nesnelerle iş birliği yaparak yerine getirir. O sorumluluğu anlamak için en fazla CRC kartındaki iş birliği yapılan nesneleri incelemek yetiyorsa parça iyi anlaşılabilir demektir. Hoca bir soru sordu: otuz satırlık bir metodu mu, yoksa üç tane on satırlık metodu mu anlamak daha kolaydır? Kısa olanı anlamak daha kolaydır. Ciddi bir hatada belki üç metodun hepsine bakmak gerekir, ama problemler genelde daha yereldir ve olası neden daha küçük bir aralığa daraltılabilir. Kod yazarken okunabilirlik standartlarına uymak (girintileme, camel casing, yorum yazma) da kodun okunabilirliğini, dolayısıyla anlaşılabilirliğini iyileştirir.

Süreklilik ve koruma aynı madalyonun iki yüzü gibidir. Bu ölçütlerin hepsi biraz soyut ve öznel (subjektif) kalır; somut rakamlarla ifade edilemez. Daha nesnel bir değerlendirme için iki temel ilke vardır: **bağlaşımın düşük** (low coupling) ve **uyumun yüksek** (high cohesion) olması. Bu ilkeler birbirine ve uygulama alanına bağımlıdır; başka ilkeler de türetilebilir, ama bu ikisi en temel ölçütlerdir.

## 10. Bağlaşım (Coupling)

### 10.1 Tanım

Bağlaşım, bir parçanın diğer parçalara bağımlılık oranıdır. Parça sınıf, alt sistem ya da paket düzeyinde ele alınabilir; burada sınıflar arasındaki bağımlılık konuşuldu.

En kısa tanımla: bir UML sınıf şemasında iki sınıf arasında birinden diğerine doğru bir ok varsa, türü ne olursa olsun, okun başlangıcındaki sınıf okun bitişindeki sınıfa bağımlıdır. Daha ayrıntılı söylenirse, bir sınıf diğerinin hizmetlerinden yararlanıyorsa, iç yapısından ya da çalışma ilkelerinden haberdar olması gerekiyorsa ya da aralarında özelleşme-genelleşme (kalıtım) ilişkisi varsa bu bir bağımlılıktır.

> **Hocanın vurgusu:** Burada önemli olan bağımlılığın ya da bağlaşımın niceliği değil, niteliğidir.

### 10.2 Bağlaşımın sayılması

Hoca bir sınıf şemasıyla gösterdi (ekrandan, 02:15:00). A sınıfı:

- B'ye bire bir bağlıdır (A'da `b : B` alanı),
- C'ye bire çok bağlıdır (A'da `c[] : C` dizisi),
- X'ten kalıtımla türetilmiştir,
- D ile bütün-parça (dolu elmas) ilişkisi içindedir.

A ile B arasındaki mi, A ile C arasındaki mi bağlaşım daha kuvvetlidir? İkisi aynı sayılır. Kodda A'da B türünden tek bir alan, C türünden bir dizi olsa da A'yı bir projede kullanmak isteyen B'nin de C'nin de kodunu almak zorundadır. Kalıtım da aynı şekilde 1 sayılır: A'nın koduna ihtiyaç varsa X'in kodu da alınmalıdır. Kalıtım nesne düzeyinde değil sınıf düzeyinde etkileri olan daha ağır sıklet bir ilişkidir, ama bağlaşım olarak yine 1 sayılır. Elmasın içinin dolu ya da boş olması da fark etmez.

Buna göre A'dan dört ayrı sınıfa ok gittiği için:

$$\text{bağ}(A) = 4$$

Hoca bir ayrıntıya da dikkat çekti: bütün-parça okunun elmas ucunda aslında D'den A'ya doğru da bir yön vardır. Yalnız A'nın bağlaşımı sayıldığında sonuç 4'tür, ama sistemin toplam bağlaşımı düşünülürse D'den A'ya giden ok da sayılır ve toplam 5 olur.

### 10.3 Düşük bağlaşımın yararı

Düşük bağlaşım, bir sınıfta yapılan değişikliğin diğer sınıfları daha az etkilemesini sağlar ve yeniden kullanılabilirliği artırır. Bağımlılıklar az olduğunda hata ya da istenmeyen yan etkinin yayılma olasılığı düşer. Örnekte A'da yapılacak bir değişiklik B, C ve X'i etkilemez; ama B, C, X ya da D'de yapılacak bir değişikliğin A'yı etkileme olasılığı yüksektir.

### 10.4 İki tasarımın karşılaştırılması

Aynı problemi çözen, aynı A, B, C sınıflarını kullanan iki tasarım çizildi (ekrandan, 02:25:00 ve 02:30:00):

- **Tasarım I:** A → B ve A → C.
- **Tasarım II:** A → B ve B → C.

Hoca hangisinin daha iyi olduğunu sınıfa sordu ve el kaldırarak oylattı (Tasarım I daha çok oy aldı). Sonra bağlaşımları hesapladı:

| Ölçü | Tasarım I | Tasarım II |
|---|---|---|
| bağ(A) | 2 | 1 |
| bağ(B) | 0 | 1 |
| bağ(C) | 0 | 0 |
| topBağ (toplam) | 2 | 2 |
| maxBağ (en büyük) | 2 | 1 |

Toplam bağlaşım ikisinde de 2 çıktığı için bir karar verilemedi. Bu kez başka bir açıdan bakıldı: Tasarım I'de A'yı kullanmak için B ve C gerekir, ama B ve C tek başına kullanılabilir. Tasarım II'de A için yine B ve C gerekir, B için de C gerekir; C tek başına kullanılabilir. Bu yüzden en büyük (maksimum) bağlaşım ölçüsü tanımlandı.

Neden en küçük değil de en büyük bağlaşıma bakılır? Hoca bunu oyun kuramıyla açıkladı. Makul ve mantıklı bir karar vermek gerektiğinde, hayalcilik ya da kumarbazlık yerine her seçeneğin kazancı ve kaybı bir tabloya yazılır ve kayıpları en aza indirecek şekilde davranılır. (Hoca bu bağlamda matematikçi John Nash'in hayatını anlatan "A Beautiful Mind" filmini de önerdi.) Her şey yolundayken en küçük bağlaşım zaten sorun yaratmaz; riski ölçen en büyük bağlaşımdır ve istenmeyen bir şeydir.

En büyük bağlaşım Tasarım II'de daha küçük olduğu için (1 < 2) **Tasarım II tercih edilir**.

### 10.5 Dolaylı bağlaşım

Şu ana kadar yalnız doğrudan bağlaşımlar sayıldı. Ama bağlaşım geçişkendir: Tasarım II'de A, B'ye; B de C'ye bağlıysa A aslında C'ye de dolaylı olarak bağlıdır. Hoca bunu şemada `<<dolaylı>>` stereotipli kesikli bir okla gösterdi (bu bir UML kullanım ilişkisi değil, yalnız dolaylı bağlaşımı göstermek içindir) (ekrandan, 02:30:00).

Dolaylı ilişki doğrudan ilişki kadar kuvvetli kabul edilirse 1 sayılır, ama genelde **yarım** sayılır. Bu durumda Tasarım II'nin değerleri:

$$\text{bağ}(A) = 1 + 0{,}5 = 1{,}5, \quad \text{bağ}(B) = 1, \quad \text{bağ}(C) = 0$$

$$\text{topBağ} = 1{,}5 + 1 + 0 = 2{,}5, \quad \text{maxBağ} = 1{,}5$$

Tasarım I'de dolaylı bağlaşım yoktur; toplam 2'de kalır. Toplam bağlaşıma bakılırsa (2 < 2,5) **Tasarım I tercih edilir**. Ekrandaki notlar: "topBağ dolaylı hesaplanınca daha küçük olan (I) tasarımını tercih ediyorum" ve "maxBağ daha küçük olan (II) tasarımını tercih ediyorum".

> **Ders sonrası not:** Ekrandaki Tasarım II notunda dolaylı hesaptan sonra da "maxBağ() = 1" yazıyor; hoca sözlü olarak en büyük bağlaşımın 1,5'e çıktığını söyledi. Doğrusu 1,5'tir; yine de Tasarım I'in en büyük bağlaşımı (2) daha yüksek olduğu için bu ölçüye göre Tasarım II daha iyi kalır.

Sonuçta iki ölçüt farklı tasarımları gösterdi; mesele dolaylı bağlaşımın hesaba katılıp katılmamasına dayandı. İki tasarım başa baş kaldı ve hangisinin seçildiği çok dert değildir. Hoca bu tür kararların kolay olmadığını göstermek için bunu tartıştığını söyledi.

Asıl cevap ise başka bir yerdedir: A, B ve C problem alanındaki varlıklarsa, gerçek dünyada nasıl ilişkiliyse tasarımda da öyle ilişkilendirilmelidir. Gerçekte Tasarım I'deki gibi ilişkiliyse I, Tasarım II'deki gibi ilişkiliyse II seçilir. Hoca biraz "yanlış yönlendirme" yaptığını söyledi. Ancak özellikle sistem tasarımında, ilişkiler problem alanından gelmiyor ve tasarımcının elindeyse, bu ölçütlerle hangisinin daha iyi olduğu düşünülür.

## 11. Uyum (Cohesion)

### 11.1 Tanım

Uyum, bir parçanın (burada sınıfın) sorumluluklarının birbiriyle ilişkili olma derecesidir. Sorumlulukların ana kategorilerine bakıldığında (CRC kartları bu iş için çok uygundur) alakasız alanlarda sorumluluklar varsa uyum düşük, aksi hâlde yüksektir. Uyumun yüksek olması istenir.

Hoca gerçek dünyadan bir benzetme yaptı. Bir yazılım firmasında yazılım mühendisi olarak çalışıyorsunuz. Firma küçükse ya da DevOps anlayışıyla çalışıyorsa testi de, kurulumu (deployment) da yaparsınız; uçtan uca bütün işler birbiriyle ilişkilidir. Ama resepsiyondaki çalışan izinliyken size "bugün kod yazma, resepsiyona bak" denirse, hem kod yazıp hem gelenlerle ilgilenmek zorunda kalırsınız; bu iki iş birbiriyle tamamen uyumsuzdur. Bir sınıfın sorumlulukları da birbiriyle yakından ilişkili olmalıdır; alakasız işler yapan bir sınıfın uyumu düşüktür.

### 11.2 Uyumun ölçülmesi

Bu tanım bağlaşıma göre daha soyut kalır. Uyumu sayısal olarak ölçen ölçütler tanımlıdır ve genelde aynı temel fikre dayanırlar; çeşitli varyasyonları vardır. Hoca şekil olarak bir çizim programında üye alanları daire, metotları kare (eşkenar dörtgen) olarak çizdi ve hangi metodun hangi üye alana eriştiğini çizgilerle gösterdi (ekrandan, 02:40:00).

Yazılım ölçütlerinin 0 ile 1 (ya da %0 ile %100) arasında normalize bir sonuç vermesi yorumlanmalarını kolaylaştırır. Bu yüzden uyum şöyle tanımlandı:

$$\text{uyum} = \frac{\text{mevcut metot–alan eşleşmesi sayısı}}{\text{olası en çok eşleşme sayısı}}$$

Örnekte 4 üye alan ve 5 metot vardır. Her metot her alana erişseydi (tam bağlı olsaydı) 4 × 5 = 20 eşleşme olurdu. Şekilde 7 eşleşme vardır:

$$\text{uyum} = \frac{7}{20} = 0{,}35 = \%35$$

Dolaylı erişimler de hesaba katılabilir: bir metot başka bir metodu çağırıyorsa, çağrılan metodun eriştiği alanla da dolaylı olarak ilişkilidir; bu 1 ya da 0,5 sayılabilir. Verilen karara göre hesaplama yöntemi değişir; derste bu ayrıntıya girilmedi.

> **Ders sonrası not:** Hoca hesabı yaparken bir an "bağlaşımımız 7/20" dedi, hemen "pardon, uyum" diye düzeltti. Burada hesaplanan değer uyumdur.

### 11.3 Refactoring ile uyumun artırılması

%35 pek iyi bir uyum değildir. Şekle bakıldığında alanların ve metotların aslında iki ayrı gruba ayrıldığı görülür: ilk iki alana yalnız ilk iki metot, son iki alana yalnız son üç metot erişir. Hoca sınıfı ikiye böldü; bu bir **refactoring** eylemidir.

- **Birinci sınıf:** 2 alan, 2 metot. Olası eşleşme 2 × 2 = 4, mevcut 3.

$$\text{uyum}_1 = \frac{3}{4} = 0{,}75 = \%75$$

- **İkinci sınıf:** 2 alan, 3 metot. Olası eşleşme 2 × 3 = 6, mevcut 4.

$$\text{uyum}_2 = \frac{4}{6} = \frac{2}{3} \approx \%67$$

(Hoca bu değeri %66 olarak söyledi; $2/3 \approx 0{,}667$'dir.) %35 uyumlu bir sınıftan %75 ve yaklaşık %67 uyumlu iki sınıf elde edildi; uyumda büyük bir ilerleme sağlandı. Bu, uyum ölçütünün tanımı ve refactoring ile uyumun nasıl yükseltilebileceğinin örneğidir. Bu durum ilk tasarımda fark edilirse hemen düzeltilir; fark edilmediyse, örneğin çevik bir süreçte, bir refactoring koşusu planlanıp uyum iyileştirilir.

## 12. Veritabanı Sorumluluğu Kimde Olmalı?

Hoca bağlaşım bölümündeki Tasarım II'yi (A → B → C) temel alarak yeni bir soru sordu. Artık işin içine bir veritabanı katmanı girer ve A, B, C nesnelerinin veritabanına kaydedilmesi gerekir. İki tasarım çizildi (ekrandan, 02:45:00):

- **Tasarım I:** A, B ve C'nin her biri `<<Database>>` ile kendisi konuşur (A, B ve C'den veritabanına kesikli oklar). Veritabanına kaydetme, güncelleme ve yükleme sorumlulukları bu sınıfların kendisine verilir.
- **Tasarım II:** A, B ve C'ye sahip olan, onları oluşturan bir D sınıfı vardır (D → A, D → B, D → C). Veritabanıyla yalnız D konuşur (D'den veritabanına kesikli ok).

Sınıf oylamasından sonra hoca tek bir doğru cevap olduğunu söyledi: **Tasarım II**.

İlk itiraz bağlaşımdır: Tasarım I'de 5 ok (A → B, B → C ve üç veritabanı oku), Tasarım II'de 6 ok (A → B, B → C, D'den A, B, C'ye ve veritabanına) vardır. Kesikli oklar tam anlamıyla bir sınıfa bağlaşım değildir, çünkü veritabanı bir sınıf değildir; ama ok olarak sayılsa bile Tasarım II'nin bağlaşımı daha yüksektir. Yine de cevap Tasarım II'dir, çünkü:

- **Değişikliğin yayılması:** Diyelim ki başta ilişkisel bir veritabanı (örneğin MySQL) kullanıldı, sonra ilişkisel olmayan (NoSQL) bir veritabanına geçmeye karar verildi. Tasarım I'de A, B ve C sınıflarının hepsinde değişiklik yapmak, bütün okları yeniden çizmek, yani üç yerde kod değiştirmek gerekir. Tasarım II'de yalnız D'nin kodunu değiştirmek yeter.
- **Uyum:** Tasarım I'de A, B ve C'ye hem problem alanıyla ilgili görevler hem de sistem katmanıyla ilgili kendini saklama görevleri verilmiştir; bunlar birbiriyle uyumsuz iki görevdir. Tasarım II'de A, B ve C iş mantığı katmanında durur, D ise sistem tasarımında durur. D'nin işi yalnız veritabanı işlemleri, A, B ve C'nin işi yalnız problem alanı işlemleridir. Bu, daha iyi bir **katmanlı mimari** sağlar.
- **Kod tekrarı:** Tasarım I'de veritabanı işlemlerinin kodu A, B ve C'de büyük olasılıkla tekrar eder (duplicate code).

Kod tekrarını önlemek için veritabanı işlemleri ortak bir üst sınıfa konup A, B ve C bundan kalıtımla türetilebilir mi? Hoca bunu da şemada gösterdi (ekrandan, 02:50:00). Ancak Java ya da .NET gibi çoklu kalıtımı desteklemeyen dillerde, bu sınıfların kendi iç mantıkları gereği başka bir üst sınıftan türemesi gerekirse bu çözüm tıkanır. Ayrıca kalıtım daha ağır sıklet bir ilişki olduğu için zaten tercih edilmez. Bu yüzden her durumda Tasarım II tercih edilir.

> **Hocanın vurgusu:** Bağlaşım önemli bir kavram olmakla birlikte aldatıcı olabilir. Olması gereken bir bağlaşım düzeyi vardır, ama bu düzeyin ne olduğu baştan bilinemez. Gerekenden az bağlaşım da bir problem olabilir: birbiriyle ilişkili olması gereken sınıflar arasındaki ilişki keşfedilememiş olabilir. Bağlaşımı bir gösterge olarak kullanın, kesinlikle bir amaç olarak kullanmayın. Aynı şey bütün ölçütler için geçerlidir.

> **Ek bilgi (derste anlatılmadı):** Veritabanı erişimini problem alanı sınıflarından ayırıp tek bir sınıfa toplama fikri, büyük olasılıkla ileride görülecek tasarım kalıplarında "Data Access Object (DAO)" ya da "Repository" adıyla geçer. Bu yaklaşımda iş mantığı sınıfları kalıcılık (persistence) ayrıntılarını bilmez.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:10): Satış kullanım öyküsünün (birincil aktör kasiyer; ön koşul kasiyerin kimliğinin doğrulanması; ana akışta yeni satış başlatma, barkod girme, toplam hesaplama, ödeme; alternatif senaryolarda geçersiz barkod ve ürün iptali; ödemede provizyon) kullanım şemasını çizin.

> **Çözüm (derste verildi, ekrandan, 00:25:00):** Kasiyer, Satış'a düz çizgiyle bağlanır. Satış `<<include>>` Kimlik Doğrulama, Yeni Satış Başlat ve Ödeme. Geçersiz Barkod `<<extend>>` Satış, Ürün İptal `<<extend>>` Satış, Provizyon `<<extend>>` Ödeme. Barkod girme ve toplam hesaplama basit adımlar olduğu için ayrı senaryo yapılmaz. Bütün include/extend okları kesikli çizilir.

**Soru 2** (ekrandan, 00:25:00): Örnek gereksinim belgesinden (metin ve senaryolardan) sınıfları oluşturun.

> **Çözüm (derste verildi, ekrandan, 00:55:00 ve 01:40:00):** Adaylar: Kasa, Alış-veriş, Rapor, Fiş, Müşteri, Satış, KDV, Şube, Kasiyer, Ödeme, Ürün, Barkod. Alınanlar: Kasa, Satış, Şube, Kasiyer, Ödeme, Ürün; sonra ilişki nesnesi olarak SatışKalemi eklenir. Elenenler: Alış-veriş (satışla eş anlamlı), Rapor ve Fiş (üretilebilir bilgi), Müşteri (sadakat kartı gereksinimi yok), KDV ve Barkod (Ürün'ün üye alanları). İlişkiler Bölüm 6.1'deki tablodadır.

**Soru 3** (derste sözlü, 01:37:41): Ders notundaki şemada bütün-parça ilişkisinin elması içi dolu, derste çizilende içi boş. Bu yalnız çizim programıyla mı ilgili, yoksa anlam farkı var mı?

> **Cevap (derste verildi):** Küçük bir anlam farkı vardır ve farklı kaynaklar farklı vurgular. Bir yoruma göre parça bütün olmadan tek başına var olabiliyorsa içi boş, var olamıyorsa içi dolu elmas kullanılır. Elmas konursa elmas tarafında da bir yön ve `1` çokluğu olduğu bilinmelidir; o yönde ilişki istenmiyorsa elmas yerine düz bir bire çok ilişki konur.

**Soru 4** (derste sözlü, 02:06:08): Otuz satırlık bir metodu mu, üç tane on satırlık metodu mu anlamak daha kolaydır?

> **Cevap (derste verildi):** Kısa metotları anlamak daha kolaydır. Problemler genelde yereldir; olası neden daha küçük bir kod aralığına daraltılabilir.

**Soru 5** (ekrandan, 02:15:00): A sınıfı B'ye bire bir, C'ye bire çok ilişkiyle bağlı, X'ten kalıtımla türetilmiş ve D ile bütün-parça ilişkisi içinde. A'nın bağlaşımı nedir?

> **Çözüm (derste verildi):** Her ilişki türü, niceliğinden bağımsız olarak 1 sayılır: $\text{bağ}(A) = 4$. Elmas ucundaki D → A yönü de sayılırsa sistemin toplam bağlaşımı 5 olur.

**Soru 6** (derste sözlü, 02:16:00; şema ekrandan, 02:30:00): Aynı problemi çözen iki tasarım var: Tasarım I'de A → B ve A → C, Tasarım II'de A → B ve B → C. Hangisi daha iyidir?

> **Çözüm (derste verildi):** Doğrudan bağlaşımlarla topBağ ikisinde de 2'dir. maxBağ Tasarım I'de 2, Tasarım II'de 1 olduğu için en büyük bağlaşıma göre II seçilir. Dolaylı A → C ilişkisi yarım sayılırsa Tasarım II'de topBağ = 2,5 olur ve toplam bağlaşıma göre I seçilir. İki ölçüt farklı sonuç verdiği için tasarımlar başa baş kalır; asıl ölçüt A, B, C'nin problem alanında gerçekte nasıl ilişkili olduğudur.

**Soru 7** (ekrandan, 02:40:00): 4 üye alanı ve 5 metodu olan bir sınıfta metotlar alanlara toplam 7 kez erişiyor. Sınıfın uyumu nedir? Sınıf, 2 alan + 2 metot (3 erişim) ve 2 alan + 3 metot (4 erişim) olarak ikiye bölünürse uyum nasıl değişir?

> **Çözüm (derste verildi):** $7/20 = \%35$. Bölünce $3/4 = \%75$ ve $4/6 \approx \%67$. Uyum belirgin biçimde artar.

**Soru 8** (derste sözlü, 02:44:30; şema ekrandan, 02:45:00): A, B ve C nesneleri veritabanına kaydedilecek. Tasarım I'de her sınıf veritabanıyla kendisi konuşuyor; Tasarım II'de A, B ve C'ye sahip bir D sınıfı veritabanıyla tek başına konuşuyor. Hangisini seçersiniz?

> **Çözüm (derste verildi):** Tasarım II. Ok sayısı (bağlaşım) daha fazla olsa da veritabanı değiştiğinde yalnız D değişir, A, B ve C yalnız problem alanı görevlerini taşıdığı için uyumları yüksek kalır, veritabanı kodu tekrar etmez ve katmanlı bir mimari elde edilir.

## Dersin Toparlaması

Ders, çözümleme aşamasının son adımlarıyla başladı. Kullanım şemalarında senaryolar elipslerle, aktörler çöp adam ya da `<<actor>>` kutusuyla gösterilir; senaryolar arasındaki include (içerme, ön koşul) ve extend (alternatif senaryo) ilişkileri kesikli oklarla, İngilizce okunuşa uygun yönde çizilir. Ardından NextGenPOS örneğinde gereksinim belgesindeki ve kullanım öyküsündeki isimler aday sınıf olarak toplandı, saklanan bilgi, gereksinim duyulan hizmetler ve gerekli varlıklar kurallarıyla elendi ve bir alan modeli çizildi. Satış ile ürün arasındaki adet bilgisi için SatışKalemi adlı bir ilişki nesnesi gerektiği gösterildi.

İkinci bölümde nesneye yönelik tasarım sürecine geçildi. Tasarım "nasıl?" sorusuna yanıt arar ve nesne tasarımı ile sistem tasarımına ayrılır. Birden fazla tasarım alternatifi arasında seçim yapmak için ayrılabilirlik, birleştirilebilirlik, anlaşılabilirlik, süreklilik ve koruma ölçütleri tanıtıldı; daha nesnel ölçüler olarak düşük bağlaşım ve yüksek uyum ilkeleri sayısal örneklerle işlendi. Bu ölçütlerin birer gösterge olduğu, amaç olmadığı, asıl belirleyicinin problem alanındaki gerçek ilişkiler ve katmanlı mimari gibi tasarım ilkeleri olduğu vurgulandı. Hoca bir sonraki derste tasarım kalıplarına geçileceğini ve NextGenPOS tasarımının genişletileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
