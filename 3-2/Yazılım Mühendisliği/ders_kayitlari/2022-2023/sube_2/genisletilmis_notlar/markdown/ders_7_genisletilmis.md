# Ders 7 Genişletilmiş Notu: Etkinlik Şemaları, Durum Şemaları ve NextGenPOS Tasarım Modeli

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Etkinlik Şemaları (Activity Diagrams)
- 2. Havayolu Check-in Örneği
- 3. Eşgüdüm, Sinyal Alma ve Kulvarlar
- 4. Durum Şemaları (State Diagrams)
- 5. Uçak Yaşam Döngüsü Örneği
- 6. Durum Geçişlerinde Komutlar
- 7. NextGenPOS Tasarım Modeli
- 8. Satış İşleminin Etkinlik Şeması
- 9. Karar Elmasının Üçüncü Köşesi
- 10. Kasanın Durum Şeması
- Örnek Sorular
- Dersin Toparlaması

## 1. Etkinlik Şemaları (Activity Diagrams)

Bu derste iki yeni UML şema türü işlendi: etkinlik şemaları ve durum şemaları. Etkinlik şemaları olayların akış sırasını gösterir ve konunun uzmanlarının, yani yazılımcı olmayan alan uzmanlarının da anlayabileceği bir şema türüdür.

Hocaya göre bu şema türünün iki önemli avantajı vardır:

- **İş kurallarını iyi gösterir.** Bu yüzden alan uzmanlarına hitap eder.
- **Çok iş parçacıklı (multi-threading) çalışmayı gösterebilir.** Diğer UML şemalarında paralel akış ya gösterilemez ya da gösterilse de önemli değildir. Etkinlik şeması ise paralel yürüyen etkinlikleri açıkça gösterir.

### 1.1 Çizim öğeleri

"Etkinlik Şemaları – Activity Diagrams / Çizim Kuralları ve Örnek Çizim" slaytında (ekrandan, 00:45:00) şu öğeler vardır:

| Öğe | Şekil | Anlamı |
|---|---|---|
| Denetim akışı | Düz ok | Hangi olaydan sonra hangi olaya gidileceği |
| Etkinlik başlangıcı | Dolu daire | Akışın başladığı yer |
| Sinyal alma / Olay (event) kabul etme | Bir ucu içe girintili beşgen | Dışarıdan gelen bir olayı bekleme |
| Eylem | Köşeleri yuvarlatılmış dikdörtgen | Yapılan iş |
| Karar verme (if) | Elmas | Koşula göre dallanma |
| Eşgüdüm | Kalın çubuk | Paralel akışların başlangıcı ve bitişi |
| Etkinlik sonu | Halka içinde dolu daire | Akışın bittiği yer |
| Sinyal gönderme | Bir ucu sivri beşgen | Dışarıya olay gönderme |

Denetim akışı oku, birinci sınıfta görülen akış şemalarındaki oklarla aynı mantıkta ve aynı işlevdedir. Her etkinliğin bir başlangıcı ve bir bitişi olur. Ancak çizimi kolaylaştırmak için birden fazla etkinlik sonu konabilir: Akışı şemanın en sonuna kadar taşımak yerine bulunduğu yerde bir çıkış yapıp etkinlik sonu çizmek kabul edilir. Hoca slaytta etkinlik sonunun yanına "× n" yazarak bunun birden çok kez kullanılabileceğini gösterdi.

Sinyal alma ile sinyal gönderme bir çift oluşturur. Sinyal göndermeyi ters çevirip sinyal almanın yanına koyunca iki şekil birbirini tamamlayarak bir dikdörtgen oluşturur; şekiller bu yüzden böyle tasarlanmıştır. Bir şemada ikisinin birlikte bulunması kuralı yoktur. Bir şemada olay kabul etme varsa başka bir şemada buna olay gönderen bir etkinlik olabilir, ama olmak zorunda değildir.

Eylem kutularının köşeleri yuvarlatılmaya çalışılır. Kâğıda çizerken yuvarlatılamıyorsa dert değildir; Violet UML gibi bir araç kullanılıyorsa araç zaten bu şekli çizer. Başka bir araç kullanılıyorsa ve yuvarlak köşeli dikdörtgen yoksa normal dikdörtgen kullanılabilir.

## 2. Havayolu Check-in Örneği

Bu bölümdeki örneklerin hepsi bir havayolu bilgi sistemiyle ilgili senaryolardır. Slayttaki şema (ekrandan, 00:45:00) şöyledir:

```text
[Sinyal alma] Yolcu check-in bankosuna gelir.
      |
[Eylem] Yolcu check-in yapar.
      |
<Karar>
  |-- [else] ------------------> (Etkinlik sonu)
  |-- [check-in başarılı]
      |
====== Eşgüdüm çubuğu (ayırma) ======
   |                        |
[Yolcu uçağa biner]   [Bagajlar uçağa yüklenir]
   |                        |
====== Eşgüdüm çubuğu (birleştirme) ======
      |
[Eylem] Uçak piste yönelir
      |
(Etkinlik sonu)
```

Şema bir olay kabul etmeyle başlar: yolcu check-in bankosuna gelir. Başlangıç noktasıyla başlamak zorunlu değildir; istenirse önce dolu daire konup oradan bu şekle geçilebilirdi. Ama sinyal alma ile de başlanabilir.

Ardından denetim akışı ikinci öğeye, "Yolcu check-in yapar" eylemine gider. Sonra karar verme gelir. Etkileşim (sıralama) şemalarında olduğu gibi `if` koşulu köşeli parantez içinde yazılır.

> **Hocanın vurgusu:** `if` koşulu elmasın içine yazılmaz. Okları izleyerek koşul anlaşılır. Küçük elmasın içine yazı sığmaz; sığdırmak için şekli çok büyütmek gerekir. Etkinlik şemalarında kural bu şekilde konmuştur.

Check-in başarılıysa akış devam eder; aksi durumda (`[else]`) senaryo orada sonlanır. `else` kolunu en alttaki bitişe kadar taşımak da mümkündü, ama gerek yoktur; oradan bir çıkış yapıp bitirmek kabul edilir.

Check-in başarılıysa eşgüdüm çubuğu başlar: akış iki kola ayrılır, yolcu uçağa binerken bagajlar da uçağa yüklenir. Alttaki eşgüdüm çubuğunda bu paralel akışlar birleşip tek akışla devam eder. Paralel kollarda iki ya da daha çok eylem bulunabilir. Erken biten eylem, geç biteni bekler; alttaki çubuk bu yüzden bir bekleme yeri olarak düşünülmelidir. Belki bagajlar yolcudan önce yüklenmeye başlar; bir kolda X süre, diğerinde Y süre geçebilir, X Y'den büyük ya da küçük olabilir. Şema bu konuda bir şey söylemez, ama birleştirme noktasında erken bitenin geç biteni beklemesi mutlaka söz konusudur. Ardından uçak piste yönelir ve senaryo biter.

## 3. Eşgüdüm, Sinyal Alma ve Kulvarlar

### 3.1 Çizim bilgileri

"Çizim Bilgileri" slaytı (ekrandan, 00:50:00) şunları söyler:

- Etkinlik şemaları başlangıç işareti veya sinyal alma işareti ile başlar.
- Sinyal alma beklemelidir:
  - Akış, bir sinyal alana kadar bekler.
  - Zamanlı olaylar (timer) da bununla gösterilebilir.
- Eşgüdüm beklemelidir:
  - Eşgüdüm çizgisine varan akış, çizgiyi geçmeden önce diğer akışların hepsini bekler.
  - Fork: tek ok çubuğa girer, birden fazla ok çıkar. Join: birden fazla ok girer, tek ok çıkar.

Unix programlama ya da çok iş parçacıklı programlama yapanlar bu kavramları tanır: bir akışın birden fazla alt akışa ayrılmasına fork, bunların yeniden bir araya gelmesine join denir. Zamanlı olaylar da sinyal alma şekliyle gösterilebilir.

### 3.2 Özne kullanımı ve kulvarlar

Bu şemada her eylemi hangi öznenin, yani hangi aktörün yaptığı belli olmalıdır. Check-in örneğinde "Bagajlar uçağa yüklenir" ifadesi edilgendir; bagajları yükleyen yer hizmetleridir. "Yer hizmetleri bagajları uçağa yükler" biçiminde yazılsaydı daha iyi olurdu.

> **Hocanın vurgusu:** Eylemlerde özne kullanmaya dikkat edin.

Bunun bir yolu kulvarlardır (swim lane). Kulvar, yüzme havuzunda aynı anda paralel yarışan yüzücülerin hatları gibi, şemayı aktörlere göre dikey şeritlere böler. Hoca, Violet UML aracının kulvarları desteklemediğini söyledi. Kulvarlı çizim isteniyorsa kulvarlar önce zihinde kurulur, etkinlikler Violet UML'de buna göre hizalanır; sonra kulvarlar bir resim düzenleyiciyle dikdörtgen olarak çizilip üstlerine aktör adları yazılır.

Bir eylemden diğerine giden bir veri varsa, akış okunun üstüne bu veri yine köşeli parantez içinde yazılır. Slayttaki kulvar örneği <!-- BELİRSİZ: Bu slaytın karesi yok; akış altyazıdan kuruldu. --> şöyledir: sağ kulvarda müşteri hizmetleri, sol kulvarda yer hizmetleri vardır. Müşteri hizmetleri yer hizmetlerinden yolcu listesini ister. Yer hizmetleri yolcu listesini oluşturur ve gönderir. Müşteri hizmetleri listeyi kabul eder; bu iki etkinlik arasındaki okun üstünde yolcu listesinin gönderildiği yazar. Ardından müşteri hizmetleri kesinleşmiş yolcu listesini veritabanına kaydeder ve etkinlik sona erer.

Listenin nasıl gittiği önemli değildir: bir veritabanı üzerinden, bir e-postaya eklenmiş bir dosyayla ya da FTP ile karşıya yüklenerek gönderilmiş olabilir. Hepsi aynı bilgi sistemini kullanıyorsa birinin "gönderdim" diye tıklaması bile bu şekilde gösterilebilir. Önemli olan iki eylem arasında bu verinin aktarılmasıdır. Bu yazım `if` koşuluyla karışmaz, çünkü okun başlangıç ucunda elmas yoktur.

### 3.3 Hangi senaryo için çizilir?

Genelde bir kullanım senaryosu için bir etkinlik şeması çizilir. Ancak birbiriyle ilişkili, örneğin `include` ve `extend` ilişkileri olan birkaç kullanım senaryosu tek bir etkinlik şemasında da gösterilebilir.

## 4. Durum Şemaları (State Diagrams)

Durum şeması, bir varlığın içinde bulunabileceği durumları ve bu durumların birinden diğerine geçiş yapma kurallarını anlatmaya yarar (ekrandan, 00:55:00). Bilgi sisteminde çok önemli bir varlık varsa, bu varlığın sistemde var olduğu süre içinde geçirdiği yaşam döngüsünü, yani bir halden diğerine nasıl, ne zaman ve hangi koşullarda geçtiğini göstermek yararlıdır. Varlık o kadar önemliyse yaşam evrelerini göstermek de önemlidir ve bu şema çizilir.

Şemanın temel öğeleri şunlardır:

- **Başlangıç ve bitiş:** Etkinlik şemasındakiyle aynıdır.
- **Durum:** Köşeleri yuvarlatılmış dikdörtgen.
- **Durum geçişi:** Ok. Okun üstüne geçişe sebep olan olay yazılır.

Geçiş etiketinin başına mutlaka stereotip karakterleri içinde `M` harfi yazılır: `«M»`. M, "mutate" demektir: nesnenin bir durumdan diğerine geçmesi bir evrimleşme (mutasyon) gibi düşünülmüştür. Olay adından sonra etiket `/` işaretiyle bitirilir. Bu biçimin neden gerektiği komutlar eklendiğinde (bölüm 6) daha iyi anlaşılır.

## 5. Uçak Yaşam Döngüsü Örneği

Hoca bu örnekleri Craig Larman'ın kitabından aldığını; kitabın şemayı aşama aşama karmaşıklaştırarak anlatmasını beğendiğini söyledi. Örnek, bir uçağın havayolu bilgi sistemindeki yaşam döngüsüdür.

### 5.1 Basit hali

<!-- BELİRSİZ: "Örnek Çizim (1)" slaytının karesi yok; bu basit hal altyazıdan ve "Örnek Çizim (2)" slaytından kuruldu. -->

İlk olay uçağın alım emrinin verilmesidir: `«M» Uçağın alım emri verildi /`. Alım emri verildiğinde uçak henüz gelmemiştir, yalnız sipariş edilmiştir; uçak "Sipariş aşamasında" durumundadır. Uçak teslim edilene kadar bu durumda kalır. Teslim edilince (`«M» Uçak teslim edildi /`) hemen kullanıma alınmaz, önce bakıma alınır ("Bakımda"). İlk kontrolleri yapılıp bakım tamamlanınca (`«M» Bakım tamamlandı /`) "Kullanıma hazır" durumuna geçer. Kullanıma hazırken bir arıza baş gösterirse (`«M» Arıza bulundu /`) tekrar Bakımda durumuna döner. Uçağın emekli edilmesine karar verilince (`«M» Uçak emekli edildi /`) senaryo sona erer. Bu ilk halde uçuşla ilgili ayrıntılar yoktur.

### 5.2 Durumu değiştirmeyen olaylar

Bir olay gerçekleştiğinde varlık aynı durumda kalmaya devam ediyorsa, aynı durumdan çıkıp aynı durumda biten bir ok çizilir ve okun üstüne olay yazılır. Alternatif gösterim, olayı durum kutusunun içine yazmaktır.

Hoca uçuşta olmayı ayrı bir durum olarak düşünmediklerini, uçuş yapmayı bir olay olarak ele aldıklarını belirtti.

### 5.3 Ayrıntılı hal

"Örnek Çizim (2)" slaytındaki şema (ekrandan, 01:00:00) şöyledir:

| Kaynak durum | Geçiş etiketi | Hedef durum |
|---|---|---|
| Başlangıç | `«M» Uçağın alım emri verildi /` | Sipariş aşamasında |
| Sipariş aşamasında | `«M» Uçak teslim edildi /` | Bakımda |
| Bakımda | `«M» Bakım tamamlandı /` | Kullanıma hazır |
| Kullanıma hazır | `«M» Arıza bulundu /` | Bakımda |
| Kullanıma hazır | `«M» Uçuş ata / «M» Uçuş yap /` | Kullanıma hazır (kendine dönen ok) |
| Kullanıma hazır | `«M» Bakım isteği geldi /` | Bakım sırası beklemede |
| Bakım sırası beklemede | `«M» Uçuş yap [atanmış uçuş varsa] /` (kutunun içinde) | Bakım sırası beklemede |
| Bakım sırası beklemede | `«M» Uçuş yap [atanmış uçuş kalmamışsa] /` | Bakımda |
| Bakımda | `«M» Uçak emekli edildi /` | Bitiş |

Slayttaki yorum şöyledir: "Kullanıma hazır bir uçak için bakım isteği gelmişse, uçak önce bakım sırasına alınır. Bu sırada önceden planlanmış uçuşları varsa onları yapar. Planlanan uçuşlar bitince uçak bakıma alınır."

Kullanıma hazırken uçağa uçuş atanabilir ve atanmış uçuşlar yapılabilir; bu olaylardan sonra uçak hâlâ kullanıma hazırdır. Kendine dönen okun etiketinde iki olay birbirinden ayrılarak yazılmıştır. Aynı geçişe sebep olan ikinci bir olay varsa, ilk olayın `/` işaretinden sonra ikinci `«M»` olayı yazılabilir; böylece iki olay birbirinden ayrılır.

Bakım isteğinin nasıl geldiği ayrı bir kullanım senaryosunun konusu olabilir: periyodik bakım olabilir, uçağın ekibinden biri ya da uçağın indiği havaalanındaki yer ekibinden biri talep etmiş olabilir. Önemli olan, bakım isteği gelince uçağın doğrudan Bakımda durumuna dönmemesidir. Öyle olsaydı ok doğrudan Bakımda durumuna giderdi. Uçak önce "Bakım sırası beklemede" durumuna düşer. Bu sırada uçuş yap olayı gelirse ve atanmış uçuş varsa uçuşu yapar ve aynı durumda kalır. Uçuş yaptıktan sonra başka atanmış uçuş kalmamışsa Bakımda durumuna geçer. Uçak bu döngü içinde, emekli edilene kadar hayatını sürdürür.

"Planlanan uçuşlar bitince uçak bakıma alınsın" isteği makul ve mantıklıdır, ama şemaya eklemeye çalışınca zorlanılabilir. Bu şemada koşullu geçişlerle bu iş çözülmüştür.

### 5.4 Durum şemasının zorluğu

Bu şemada aynı olay farklı koşullarda ve farklı durumlarda farklı geçişlere sebep olabilir. "Uçuş yap" olayının üç versiyonu vardır:

- Kullanıma hazır durumunda koşulsuz normal versiyonu,
- Bakım sırası beklemede durumunda `[atanmış uçuş varsa]` ile yapılan ikinci versiyonu,
- `[atanmış uçuş kalmamışsa]` ile Bakımda durumuna geçiren üçüncü versiyonu.

Durum şemasında adı üstünde durumları izlemek kolaydır, ama olayları izlemek zordur. Bu şemaya bakarak "uçuş nasıl ve hangi şartlarda yapılır?" gibi bir soruyu yanıtlamak için bütün şemayı incelemek gerekir. Durum ve geçiş oku sayısı arttıkça bu daha da zorlaşır. Bu durum tutarlılık denetimini de zorlaştırır, ama başka yapacak bir şey yoktur.

> **Hocanın vurgusu:** Bu şemayı doğru yerde kullanmalıyız. Durum şeması varlığın durumlarına odaklıdır. Olaylarla ilgili akışlar daha çok etkinlik şemalarıyla, koda yakın versiyonlar için de sıralama (sequence) şemalarıyla belgelendirilir. Önemli bir varlığın geçirdiği aşamalar anlatılacaksa en uygun şema durum şemasıdır.

## 6. Durum Geçişlerinde Komutlar

`«M»` gösteriminin neden gerektiği burada ortaya çıkar. Bir olay gerçekleştikten sonra sistemde yürütülecek komutlar da durum şemasında gösterilebilir. Varlık önemli olduğuna göre bilgileri büyük olasılıkla bir veritabanında saklanacaktır; hangi olay gerçekleşince veritabanında hangi komutların yürütüleceği bu şemada gösterilebilir.

Komutlar `/` işaretinden sonra serbest biçimde, sözde kod olarak yazılır. Önerilen bir örnek gösterim vardır; istenirse doğrudan SQL de yazılabilir, ama hocaya göre önerilen gösterim daha sade ve derli topludur.

<!-- BELİRSİZ: Komutlu uçak şemasının slaytının karesi yok (yaklaşık 01:07-01:09). Aşağıdaki komutlar altyazıdan aktarıldı; slayttaki tam yazım doğrulanamadı. -->

Uçak örneğinde:

- **Uçağın alım emri verildi:** `create` komutu, uçak kaydının veritabanında oluşturulduğunu gösterir. Ardından `set kayıtNo := input` benzeri bir komutla uçak tablosundaki kayıt numarası alanına kullanıcının girdiği değer atanır.
- **Uçak teslim edildi:** Teslim tarihi kullanıcıdan alınır ve kaydın teslim tarihi alanına yazılır. Ayrıca "update" demeye gerek yoktur.
- **Uçak emekli edildi:** Uçağın kaydı silinir (`delete`). Hoca, silmek yerine kaydın pasife çekilebileceğini de söyledi: başka bir şirkete verildiyse ya da uzun süreli depolamaya alındıysa durum açıklamasına bu yazılabilir. Örnekte daha basit olsun diye silme seçilmiştir.

Bir durum geçişini başka bir olay daha sağlayabiliyorsa, o olay da yine `«M»` ile yazılır; yürütülecek komutlar varsa `/` işaretinden sonra yazılır ve en sonda etiket noktalı virgülle bitirilir. Sondaki ayırıcı unutulursa komutların yorumlanması karışabilir. <!-- BELİRSİZ: İkinci olayın hangi ayırıcıyla eklendiği ("//" ya da ";") altyazıdan net çıkmıyor. -->

> **Hocanın vurgusu:** Bu biçime uymanıza dikkat edilecek. Bütün olaylarda `«M»` yazılmış mı, olayın adı yazılmış mı ve `/` yazılmış mı diye bakılacak. Komut kısmını göstermek şart değildir, isteğe bağlıdır.

Hoca bir ekleme daha yaptı: Durum şemasında başlangıçtan ilk duruma geçişte bir olay olması gerekmeyebilir. Varlık varsayılan olarak belli bir durumda hayatına başlıyorsa, başlangıçtan ilk duruma giden okta `«M»` bulunmayabilir. Diğer bütün geçişlerde ise mutlaka bir olay olmalıdır. Dışarıdan ya da içeriden bir etki olmadıkça bir varlık kendi kendine durum değiştirmez; durumu değiştiren her etki bir olaydır ve geçişin üstüne `«M»` ile yazılır.

## 7. NextGenPOS Tasarım Modeli

Daha önceki derslerde çözümleme aşamasında kullanılan NextGenPOS perakende satış örneği, bu derste tasarım modeline taşınmaya başlandı. Slayt (ekrandan, 01:10:00) şunu söyler:

- Kullanım senaryosu metni ve alan modelinden yola çıkarak tasarım modelini oluşturalım.
  - Bu amaçla bir etkinlik, bir durum ve bir sınıf şeması çizelim.
  - Belki bu sırada keşfedeceğimiz yeni ayrıntılar olacaktır.
  - Tasarım modelindeki sınıf şemasının farkı, artık yönsüz ilişki bırakılmaması ve sınıfların metotlarının da eklenmesidir.

Hoca, etkinlik şemasının görece kolay çizildiğini, durum şemasının ise bir ders saati alabileceğini; sınıf şemasının sonraya kalabileceğini söyledi. Derste etkinlik ve durum şemaları çizildi, metotlarla zenginleştirilmiş sınıf şeması sonraki derse kaldı.

## 8. Satış İşleminin Etkinlik Şeması

### 8.1 Kullanım senaryosu metni

Şema, ders notundaki "Kullanım Öyküsü: Satış İşlemi" metninden çizildi (ekrandan, 01:35:00 ve 01:45:00):

- **Birincil aktör:** Kasiyer.
- **Ön koşul:** Kasiyerin kimliği doğrulanır.
- **Son koşullar:** Ödeme tahsil edilir. Satış kaydedilir. Fiş yazılır.
- **Ana öykü:**
  1. Müşteri kasaya alacağı ürünlerle gelir.
  2. Kasiyer yeni bir satış işlemi başlatır.
  3. Kasiyer ürünün barkodunu girer.
  4. Sistem bir satış kalemi maddesi oluşturur. Bu maddede ürün tanımı, fiyatı ve toplam bedel (aynı maldan birden fazla alınmış olabilir) yer alır.
  5. Kasiyer 3. ve 4. adımları müşterinin alacağı tüm ürünler için tekrarlar.
  6. Sistem toplam bedeli KDV ile birlikte hesaplar.
  7. Kasiyer müşteriye toplamı bildirir ve ödeme ister.
  8. Müşteri ödemeyi yapar ve sistem ödemeyi tahsil eder.
  9. Sistem tamamlanan işlemin kaydını tutmayı tamamlar ve harici envanter ile mali sistemlere gerekli bilgileri gönderir.
  10. Sistem fiş verir.
  11. Müşteri ürünlerle birlikte ayrılır.
- **Alternatif öyküler** (ekrandan, 01:50:00):
  - 3a. Geçersiz barkod: 1. Sistem uyarı mesajı verir ve kayıt girişini reddeder.
  - 3-7a. Müşteri bir kalem malı alışverişten çıkartmak ister: 1. Kasiyer satıştan çıkarmak üzere ürünün barkodunu okutur. 2. Sistem güncel toplamı bildirir.

### 8.2 Ana öykünün çizilmesi

Hoca şemaya ön koşuldan başladı: başlangıç noktasından "Kasiyerin kimliği doğrulanır" eylemine geçildi. Alternatif olarak ön koşul yazılmadan doğrudan "Müşteri kasaya gelir" eylemiyle ya da bu cümleyi bir sinyal alma şekline yazarak da başlanabilirdi.

Kulvar kullanılmadı. Müşteri, kasiyer ve sistem (kasa) için üç kulvar yapılabilirdi, ama Violet UML kulvarları doğrudan çizemediği için tek kulvar kullanıldı. Eylem kutularındaki yazılar iki satıra bölündü; tek satıra yazılsa da kutu genişliği değişmiyordu, ve ekranda dikey alan yatay alandan daha azdı.

Sıradaki eylemler: "Müşteri kasaya gelir", "Kasiyer yeni satış başlatır", "Kasiyer ürün barkodu girer", "Sistem satış md. oluşturur". Hoca derste "satış maddesi" ifadesini "satış md." diye kısalttığını, ders notunda kısaltma kullanmadığını belirtti. Barkod girme adımı ilk çizimde unutulmuştu; araç kullanıldığı için araya eklemek kolay oldu.

5. adım bir döngüdür. Metinde "eğer" geçmese de bu, kod yazarken kurulan bir döngüdür: müşterinin alacağı ürün olduğu sürece tekrar eden bir `while` döngüsü. Döngü koşulunu belirtmek için karar elması kullanılır. "Sistem satış md. oluşturur" eyleminden sonra konan elmastan iki ok çıkar: `[daha ürün varsa]` barkod girme eylemine geri döner, `[else]` "Kasiyer toplamı bildirir ve ödeme ister" eylemine gider. Hoca "bildirir ve ödeme ister" diye "ve" ile bağlanan iki cümlenin iki ayrı etkinlik olarak da yazılabileceğini, bunun çok önemli olmadığını söyledi.

> **Hocanın vurgusu:** `else` etiketini yazmayı unutmayın; bu kritik.

Ardından "Ödeme tahsili", "Sistem fiş verir" ve "Müşteri ayrılır" eylemleri ve etkinlik sonu geldi. 9. adım şemaya alınmadı. Müşterinin ayrılmasının yazılmasa da olacağını, ama yazıldığını söyledi. Şemayı A4 kâğıdına sığdırmak yerine kompakt tutmak için ikinci sütun aşağıdan yukarıya doğru çizildi.

### 8.3 Geçersiz barkod alternatifi

Alternatif öyküler unutulduğu için iş zorlaştı. Hocanın önerisi şudur:

> **Hocanın vurgusu:** Özellikle kâğıt kalemle çiziyorsanız alternatif öyküleri de baştan okuyun ve şemayı ona göre oluşturun. Ana öykünün ilgili adımlarını çizerken alternatiflerin yaratacağı varyasyonları görüp öğeleri ona göre konumlandırırsanız daha kolay olur.

Geçersiz barkod olasılığı nedeniyle, kasiyer barkodu girdikten sonra hemen satış maddesi oluşmaz; araya barkodun geçerli olup olmadığının denetimi girer. Barkod girme eyleminden sonra bir karar elması konur: `[barkod geçerli]` ise sistem satış maddesi oluşturur. Barkod geçersizse (`[else]`) akış barkod girmeye geri döner. Bu durumda kayıt girilmez: Müşteri belki ürünü istemez ya da ürünün tanımlanması için birine telefon edilir; tanımlanamıyorsa ister istemez vazgeçilir.

`else` oku Violet UML'de istenen yerden çizilemediği için şema "POS_ACT" adıyla kaydedildi, resim olarak dışa aktarıldı ve ok bir resim düzenleyicide (paint.net) çizildi. Hoca düz çizgi çizmek için Shift tuşunun basılı tutulduğunu gösterdi.

### 8.4 Ürün iptali alternatifi: alan gösterimi

3-7a alternatifi daha zordur. Müşterinin bir kalemi alışverişten çıkartmak istemesi, 3. adım (barkod girme) ile 7. adım (toplamı bildirip ödeme isteme) arasındaki bütün etkinliklerde olabilir. Her eylemden sonra "müşteri ürün çıkarmak istiyor mu?" diye karar elması koymak çok angarya bir iş olur ve mantıklı değildir.

Bunun yerine **alan gösterimi** kullanılır: Şemanın ilgili kısmı bir dikdörtgen içine alınır ve dikdörtgenin sol üst köşesine bir açıklama kutusu eklenir. Derste bu kutuya "Bkz. Ürün İptal Alt. Sen." yazıldı (ekrandan, 02:00:00). Bu, dikdörtgenin içindeki her eylem sırasında ürün iptali alternatif senaryosunun devreye girebileceğini söyler.

Son hali (ekrandan, 02:00:00 ve 02:05:00):

```text
(Başlangıç)
  -> Kasiyerin kimliği doğrulanır.
  -> Müşteri kasaya gelir
  -> Kasiyer yeni satış başlatır
  +-- Alan: "Bkz. Ürün İptal Alt. Sen." -------------------------+
  |  -> Kasiyer ürün barkodu girer   <-------------------------+  |
  |  -> <Karar>                                                |  |
  |       [else] ---> Kasiyer ürün barkodu girer'e döner       |  |
  |       [barkod geçerli]                                     |  |
  |  -> Sistem satış md. oluşturur                             |  |
  |  -> <Karar>                                                |  |
  |       [daha ürün varsa] -----------------------------------+  |
  |       [else]                                                  |
  |  -> Kasiyer toplamı bildirir ve ödeme ister                   |
  +---------------------------------------------------------------+
  -> Ödeme tahsili
  -> Sistem fiş verir
  -> Müşteri ayrılır
  -> (Etkinlik sonu)
```

Alan gösterimi her tür şemada kullanılabilir: sıralama şemalarında da, etkinlik şemalarında da. Sınıf şemalarında da sınıflar düzgün konumlandırılabiliyorsa kullanılabilir. Alanın tam bir dikdörtgen olması da gerekmez: Dahil edilmek istenmeyen bir kısım varsa, birbirini 90 derecelik açılarla izleyen çizgilerle o kısım dışarıda bırakılarak çokgen bir alan çizilebilir. Böylece alternatif senaryo şemaya en derli toplu ve en az karmaşıklıkla eklenmiş olur.

### 8.5 Ders notundaki çözümle karşılaştırma

Hoca derste çizilen şemayı ders notundaki şemayla karşılaştırdı <!-- BELİRSİZ: Ders notundaki etkinlik şemasının karesi yok; karşılaştırma altyazıdan aktarıldı. -->:

- Derste ön koşul da konduğu için şema biraz uzadı; bunun zararı yoktur.
- Ders notundaki şemada özneler (aktörler) yazılmamıştı. Hoca bunun eksik olduğunu, metinde özneler görünse de şemayı anlamak için senaryo metnine dönmek zorunda kalınmaması gerektiğini söyledi.
- Ders notunda karar elmasına giren oka soru yazılmıştı: "Barkod geçerli mi?" sorusundan `[evet]` ve `[hayır]` kolları çıkıyordu. Derste ise `[barkod geçerli]` ve `[else]` kullanıldı. İki gösterim de kullanılabilir.
- Ders notunda "makbuz ver" denmişti; hoca "fiş"in daha doğru olabileceğini söyledi.
- Ürün iptali ders notunda da alan gösterimiyle yapılmıştı.

## 9. Karar Elmasının Üçüncü Köşesi

Şimdiye kadar çizilen şemalarda karar elmasının bir köşesi hep boş kaldı: bir köşeden giriş, iki köşeden çıkış vardı. Üçlü bir seçenek söz konusuysa bu boş köşe de kullanılabilir.

Hoca bunu uydurma bir kasko örneğiyle gösterdi. Bir trafik kazasında hangi tarafın kusurlu olduğu sorulur. Banka hesap sahibine "müdi" dendiği gibi, kasko sahibine de müdi densin. Elmasa giren soru "Müdi kusurlu mu?" olsun:

- `[hayır]` ise tam karşılama yapılır.
- `[evet]` ise sigorta süreci ilerlemez ve sonlanır. Araya bir açıklama eylemi konsa daha iyi olurdu.
- `[oransal kusur]` ise kısmi karşılama yapılır.

Tam karşılama ve kısmi karşılamadan sonra başka işler yapılabilir ve akışlar bir yerde birleşebilir. Hoca bu ayrıntıları tamamen uydurduğunu, amacının yalnızca üç çıkışlı elmasın kullanımını göstermek olduğunu söyledi.

Bunun alternatifi `if - else if - else` zinciridir: Bir elmasın `else` kolu ikinci bir elmasa girer, o da kendi içinde iki kola ayrılır. İç içe `if` gibi ilerletilebilir. Bir durum hem üç çıkışlı elmasa hem de ikili zincire uygunsa hangisinin seçildiği fark etmez.

## 10. Kasanın Durum Şeması

### 10.1 Hangi varlığın durumu?

İlk soru, hangi varlığın durum şemasının çizileceğidir. Satış senaryosunda girişleri kasiyer koordine eder, ama esas işleri yürüten kasadır. Bu yüzden kasanın durum şeması çizildi. Hoca sınavda böyle bir soru gelirse hangi varlığın durum şemasının çizileceğinin soruda belirtileceğini, ama durumların neler olduğunu keşfetmenin çok ciddi bir aşama olduğunu söyledi.

> **Hocanın vurgusu:** Durumları yanlış teşhis ederseniz durum kötü. Olay ile durumu karıştırmayın.

Uçak örneğinde uçuş yapmak bir olaydır, durum değildir. "Uçuşta olma" da bir durum ya da mod olarak düşünülebilir. Ama kullanım senaryosu metninde bakımda olma, uçuş yapma ve bakım sırası bekleme birlikte geçerken uçuşta olmayı durum yaparsanız, o zaman hangi olayların geçişe yol açacağını düşünmek gerekir. Bu karar kullanım senaryosu metni üzerinden verilir.

### 10.2 Durumların belirlenmesi

Hoca durumları senaryo metnini okuyarak tek tek çıkardı (ekrandan, 02:15:00):

- **Boşta bekleme:** Ön koşul kasiyerin login olmasıdır. Login olmadan kasa hiçbir şey yapamaz, bir iş yapar duruma geçemez. Kimse login olmamışken kasa boşta bekler.
- **Yeni satış bekleme:** Kasiyer login olmuş, ama henüz satış başlamamıştır. Bu durum derste sonradan ayrıldı: boşta bekleme ile login olmuş halde bekleme iki ayrı durum olarak düşünüldü.
- **Satış kaydetme:** Yeni satış başlatılınca kasa aktif olarak çalışmaya başlar ve satışı kaydeder. Barkod okuma ayrı bir durum değildir; bir olaydır, bir etkinliktir.
- **Ödeme bekleme/tahsil:** Toplam hesaplanıp ödeme istendiğinde kasa bir tür kapanış moduna geçer. "Ödeme bekleme" ya da "Ödeme tahsil" denebilir. Hoca durum adlarında fiil kullanmamaya dikkat edilmesini, "beklemek" gibi bir fiilin durum adı olarak sorunlu olduğunu belirtti.
- **Fiş basma durumu:** Sistem fiş basarken başka hiçbir müdahale kabul etmez; barkod, ürün iptal tuşu gibi girişler işlenmez. Kâğıt bitse bile kâğıt değiştirilir ve basım kaldığı yerden devam eder. Bu başlı başına bir durumdur. Olayla karıştırılmasın diye adına "durumu" eklendi.
- **Uyarı verme:** Geçersiz barkod okunduğunda sistem bir uyarı sinyali verir; bu sırada belli bir süre yeni giriş kabul etmez. Bu durum, senaryodaki "sistem uyarı mesajı verir" adımından çıkarıldı.
- **Ürün silme:** Ürün iptal tuşuna basılınca kasa silme moduna geçer. Hocanın benzetmesiyle: normalde kalemle yazıyorsunuz; bir şey silinecekse kalemi bırakıp silgiyi alıyorsunuz ve silgi elinizde olduğu sürece silme modundasınız. Bütün satış iptal edilmediği için adı "satış silme" değil "ürün silme" oldu. Hoca bu durumun ilk okumada fark edilmediğini, şema çizilirken keşfedildiğini söyledi.

### 10.3 Geçişler

Violet UML'de `«M»` karakterleri doğrudan yazılamadığı için hoca bir hile kullandı: bir sınıf şemasında bir arayüz oluşturup `«interface»` yazısını `«M»` yapıp kopyaladı ve geçiş etiketlerine yapıştırdı.

Derste çizilen son şema (ekrandan, 02:30:00 ve 02:35:00):

| Kaynak durum | Geçiş etiketi | Hedef durum |
|---|---|---|
| Başlangıç | `«M»Güç açıldı/` | Boşta bekleme |
| Boşta bekleme | `«M»Kasiyer login/` | Yeni Satış Bekleme |
| Yeni Satış Bekleme | `«M»Kasiyer logoff/` | Boşta bekleme |
| Yeni Satış Bekleme | `«M»Müşteri geldi/` | Satış kaydetme |
| Satış kaydetme | `«M»Barkod oku [barkod geçerli]/` | Satış kaydetme (kendine) |
| Satış kaydetme | `«M»Barkod oku [barkod geçersiz]/` | Uyarı Verme |
| Uyarı Verme | `«M»Sinyal süresi bitimi/` | Satış kaydetme |
| Satış kaydetme | `«M»Ürün iptal/` | Ürün Silme |
| Ürün Silme | `«M»Barkod oku [silme]/` | Satış kaydetme |
| Satış kaydetme | `«M»Alınacak ürün kalmadı/` | Ödeme bekleme/tahsil |
| Ödeme bekleme/tahsil | `«M»Ödeme başarılı/` | Fiş basma durumu |
| Fiş basma durumu | `«M»Fiş basımı bitti/` | Yeni Satış Bekleme |
| Boşta bekleme | `«M»Kapatma komutu/` | Bitiş |

Bazı geçişlerin gerekçeleri:

- **Güç açıldı:** Senaryo doğrudan boşta bekleme durumuyla da başlayabilirdi; ama kasanın güç düğmesine basılıp açılması başlangıç olayı olarak eklendi.
- **Müşteri geldi:** Müşteri alacağı ürünlerle gelince satış başlatılır ve kasa satış kaydetme moduna geçer.
- **Barkod oku:** Barkod okutuldukça kalemler kaydedilir, durum değişmez; ama bu yalnız barkod geçerliyse olur. Koşul köşeli parantez içinde yazıldı. Geçersiz barkodda hoca önce durumun değişmediğini düşündü, sonra senaryodaki "sistem uyarı mesajı verir" adımından Uyarı verme durumunu çıkardı.
- **Alınacak ürün kalmadı:** Hoca bunu bir "varsa/yoksa" koşulu olarak değil, başlı başına bir olay olarak ele aldı.
- **Fiş basımı bitti:** Fiş basılınca senaryo bitti denebilir, ama basım biter bitmez otomatik logoff olmaz; kasa yeni satış beklemeye geçer.
- **Ürün iptal ve silme amaçlı barkod okuma:** Kasiyer ürün iptal tuşuna basınca kasa ürün silme durumuna geçer. Silinecek ürünün barkodu okutulunca satış kaydetmeye dönülür. Bu standart barkod okuma olmadığı için geçişe mutlaka `[silme]` koşulu yazılmalıdır.

Durum şemasında olayların hangi sırayla olduğunu anlatmak gerekmez; bu etkinlik şemasının işidir. Durum şemasında yalnız olaylar ve durum geçişleri gösterilir. Bu yüzden ürün iptalinde müşterinin sözlü isteği, kasiyerin düğmeye basması gibi ayrıntılar yazılmaz; ayrıntılar kullanım senaryosu metnindedir, etikette "Ürün iptal" yeter.

Senaryo metninde olmasa da şemaya bir son eklendi: yeni satış beklerken kasiyer logoff olursa boşta beklemeye dönülür; boşta beklerken kapatma komutu gelirse kasanın o günlük işi biter.

Hoca bu şemanın tek doğru çözüm olmadığını vurguladı: Yanlış olmadığı sürece farklı varyasyonlar ve mantıklı kabuller kabul edilir. Hoca kendisinin de aynı şemayı iki ayrı oturuşta aynı biçimde çizemeyeceğini, aynı şeyi biraz farklı yorumlamanın doğal olduğunu söyledi.

### 10.4 Ders notundaki durum şeması

Ders notundaki "Kasa ile ilgili durum şeması" (ekrandan, 02:40:00) daha az durumla kuruludur:

| Kaynak durum | Geçiş etiketi | Hedef durum |
|---|---|---|
| Başlangıç | `«M» Güç açıldı /` | Boşta bekleme |
| Boşta bekleme | `«M» Satış başlatıldı / [Kasiyer login olmuş ise]` | Satış kaydetme |
| Satış kaydetme | `«M» Barkod girildi /` | Satış kaydetme (kendine) |
| Satış kaydetme | `«M» Ürün iptal düğmesine basıldı /` | Satıştan tek ürün silme |
| Satıştan tek ürün silme | `«M» Barkod girildi /` | Satış kaydetme |
| Satış kaydetme | `«M» Alınacak ürün kalmadı /` | Ödeme bekleme |
| Ödeme bekleme | `«M» Ödeme alındı /` | Makbuz verme |
| Makbuz verme | (etiket yok) | Boşta bekleme |
| Boşta bekleme | `«M» Kapatma düğmesine basıldı /` | Bitiş |

Bu şemada login ayrı bir durum değildir. Boşta beklerken satış başlatılırsa, ancak kasiyer login olmuşsa satış kaydetmeye geçilir; olmamışsa boşta beklemeye devam edilir. Yani durum geçişini sağlayan olay, koşuluyla birlikte geçerlidir.

> **Ders sonrası not:** Hoca, ders notundaki `«M» Satış başlatıldı / [Kasiyer login olmuş ise]` etiketinde `/` işaretinin yanlış yerde olduğunu söyledi; doğrusu `«M» Satış başlatıldı [Kasiyer login olmuş ise] /` biçimidir. Ders notundaki kendine dönen "Barkod girildi" geçişine de `[barkod geçerli]` koşulunun eklenmesi gerekir. Makbuz verme durumundan çıkan geçiş için de slayt açıklamasında `«M»Makbuz basımı bitti/` notu vardır.

Slaytın açıklamalarında silme geçişinde yürütülecek komut için bir not da görünür: `<M> Barkod girildi / DELETE ürün FROM satışKalemi` (ekrandan, 02:40:00). Bu, bölüm 6'daki komut gösteriminin bir örneğidir.

Hocanın değerlendirmesine göre ders notundaki şema, olaya yazılan koşulla login olayını daha az durumla karşılar ve sadelik açısından belki daha iyidir. Derste çizilen şema ise daha ayrıntılı durum ve geçişlerle aynı işi betimler. İkisi de uygundur; ayrıntılı olmanın zararı yoktur ve çoğu zaman daha çok ayrıntı tercih edilir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:10:00 ve 01:45:00): NextGenPOS "Satış İşlemi" kullanım senaryosu metnini (ana öykü ve 3a, 3-7a alternatifleriyle) bir etkinlik şemasıyla gösterin.

> **Çözüm (derste verildi):** Bölüm 8.4'teki şema. Barkod girişinden sonra `[barkod geçerli]`/`[else]` kararı, satış maddesi oluşturulduktan sonra `[daha ürün varsa]`/`[else]` döngü kararı kullanılır. 3-7a ürün iptali alternatifi, barkod girişinden ödeme istenmesine kadar olan bölümü çevreleyen bir alan ve "Bkz. Ürün İptal Alt. Sen." notuyla gösterilir.

**Soru 2** (ekrandan, 02:15:00; derste sözlü, 02:11:12): Aynı satış senaryosu için kasanın geçirdiği durumlara odaklanan bir durum şeması çizin.

> **Çözüm (derste verildi):** Bölüm 10.3'teki tablo. Durumlar: Boşta bekleme, Yeni Satış Bekleme, Satış kaydetme, Uyarı Verme, Ürün Silme, Ödeme bekleme/tahsil, Fiş basma durumu. Daha az durumlu alternatif çözüm bölüm 10.4'tedir.

**Soru 3** (derste sözlü, 02:12:31): Uçak örneğinde uçağın uçuş yapması bir olay mıdır, bir durum mudur?

> **Cevap (derste verildi):** Uçak örneğinde uçuş yapmak bir olay olarak ele alınmıştır. "Uçuşta olma" bir durum olarak da düşünülebilir, ama o zaman hangi olayların bu duruma giriş ve çıkışı sağlayacağı ayrıca düşünülmelidir. Karar kullanım senaryosu metnine göre verilir.

**Soru 4** (derste sözlü, 02:06:32): Bir sorunun üç ayrı yanıtı varsa etkinlik şemasında nasıl gösterilir?

> **Cevap (derste verildi):** Karar elmasının boş kalan dördüncü köşesi de çıkış olarak kullanılır (örneğin "Müdi kusurlu mu?" sorusunda `[hayır]` tam karşılama, `[evet]` son, `[oransal kusur]` kısmi karşılama). Alternatif olarak `if - else if - else` biçiminde zincirlenmiş ikili elmaslar kullanılabilir.

## Dersin Toparlaması

Bu derste iki yeni UML şema türü öğrenildi. Etkinlik şemaları olayların akış sırasını, iş kurallarını ve paralel yürüyen etkinlikleri gösterir. Karar koşulları oklara köşeli parantezle yazılır, paralellik eşgüdüm çubuklarıyla (fork/join) gösterilir, aktörler kulvarlarla ayrılır ve birden fazla adımda geçerli bir alternatif senaryo alan gösterimiyle şemaya eklenir. Durum şemaları ise önemli bir varlığın yaşam döngüsünü gösterir: durumlar yuvarlak köşeli kutular, geçişler `«M» Olay [koşul] / komutlar` etiketli oklardır. Durumları izlemek kolay, olayları izlemek zordur; bu yüzden olay akışı için etkinlik ve sıralama şemaları, varlık yaşam döngüsü için durum şeması kullanılır.

NextGenPOS örneğinde tasarım modeline geçildi: satış işlemi için etkinlik şeması ve kasa için durum şeması çizildi, ders notundaki çözümlerle karşılaştırıldı. Tasarım modelinin üçüncü parçası olan, yönsüz ilişkilerin kaldırıldığı ve metotların eklendiği sınıf şeması bir sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
