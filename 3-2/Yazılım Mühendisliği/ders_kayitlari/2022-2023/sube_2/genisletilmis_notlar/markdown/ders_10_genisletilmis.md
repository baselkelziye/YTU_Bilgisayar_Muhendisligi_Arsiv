# Ders 10 Genişletilmiş Notu: Tasarım Sınıf Şeması ve Sıralama Şemaları (NextGenPOS)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Analizden Tasarıma Geçiş
- 2. Başlangıç Noktası: Analiz Yapıtları
- 3. Kasa Sınıfının Üye Alanları ve Veri Yapısı Seçimi
- 4. Giriş ve Satış Başlatma Metotları
- 5. Barkod Girişi ve Şubedeki Ürün Tablosu
- 6. Ana Senaryonun Sıralama Şeması
- 7. Satış Kalemini Kim Oluşturmalı?
- 8. Adet Bilgisi ve Geçersiz Barkod
- 9. Toplam Hesaplama, Ödeme ve Fiş
- 10. Ders Notundaki Tasarım Modeliyle Karşılaştırma
- 11. Alternatif Senaryo: Ürün Silme
- Örnek Sorular
- Dersin Toparlaması

## 1. Analizden Tasarıma Geçiş

Tasarım aşamasında işler sıfırdan yapılmaz. Analiz aşamasında oluşturulan yapıtların (artifact) üzerine gidilir ve onlarla tutarlı kalınır. Önceki derslerde NextGenPOS perakende satış örneği için alan modeli (analiz sınıf şeması), kullanım şeması, kullanım senaryosu metni, etkinlik şeması ve durum şeması hazırlanmıştı. Bu derste analiz sınıf şeması metotlarla ayrıntılandırılarak tasarım sınıf şemasına dönüştürüldü.

Hoca bu işi öğrencilerle etkileşimli yapmak istediğini söyledi. Amaç bir kavram kanıtı (proof of concept) kodu yazmak değil, mantıklı ve son haline yakın bir sınıf şeması elde etmekti. Bu süreçte bazı şeylerin "şöyle yapılacak" diye net karar verilmesi gereken yerlerde sıralama şemaları (sequence diagram) çizildi. Etkinlik şeması ve durum şeması da kodu destekleyecek tasarım için ipucu verir: etkinlik şemasındaki her eylem bir ya da birden fazla metotla hayata geçirilir.

Çizimler Violet UML Editor ile yapıldı. Analiz sınıf şemasındaki her şey seçilip yeni bir sınıf şemasına kopyalandı ve tasarım dosyası olarak ayrı kaydedildi (ekrandan, 00:15:00).

## 2. Başlangıç Noktası: Analiz Yapıtları

### 2.1 Kullanım şeması

Ekranda açılan kullanım şemasında birinci aktör Kasiyer, Satış senaryosuna düz çizgiyle bağlıdır (ekrandan, 00:10:00). İlişkiler şunlardır:

- Satış `<<include>>` Yeni Satış Başlat
- Satış `<<include>>` Kimlik Doğrulama
- Satış `<<include>>` Ödeme
- Geçersiz Barkod `<<extend>>` Satış
- Ürün İptal `<<extend>>` Satış
- Provizyon `<<extend>>` Ödeme

### 2.2 Analiz sınıf şeması

Tasarıma başlarken analiz sınıf şeması şöyleydi (ekrandan, 00:15:00):

| Sınıf | Üye alanlar |
|---|---|
| Ürün | `barkod, tanim : String`, `fiyat, KDV : float` |
| Şube | `ad, adres, vergiNo : String` |
| SatışKalemi | `adet : int` |
| Satış | `tarih : Date` |
| Ödeme | `miktar : double` |
| Kasa | (tasarımda dolduruldu) |
| Kasiyer | (üye alan yok) |

İlişkiler: Şube ile Kasa arasında toplama (aggregation, içi boş baklava Şube tarafında) vardır; bir şubede bir ya da daha çok kasa bulunur (`1` - `1..*`). Şube'den Ürün'e `1` - `*`, SatışKalemi'nden Ürün'e `1` - `1`, Satış'tan SatışKalemi'ne `1` - `1..*`, Satış'tan Ödeme'ye `1` - `1`, Kasa'dan Satış'a `1` - `*`, Kasa'dan Kasiyer'e `1` - `0..1`, Satış'tan Kasiyer'e `1` - `1` ilişkisi çizilmiştir.

### 2.3 Etkinlik şeması

Ana senaryonun etkinlik şeması şu akışı gösterir (ekrandan, 00:45:00):

```text
(başlangıç)
 -> Kasiyerin kimliği doğrulanır.
 -> Müşteri kasaya gelir
 -> Kasiyer yeni satış başlatır
 -> Kasiyer ürün barkodu girer
 -> <karar> [barkod geçerli] -> Sistem satış md. oluşturur
 -> <karar> [daha ürün varsa] -> "Kasiyer ürün barkodu girer" adımına dön
            [else] -> Kasiyer toplamı bildirir ve ödeme ister
 -> Ödeme tahsili
 -> Sistem fiş verir
 -> Müşteri ayrılır
(bitiş)
```

Kullanım senaryosu metninde ön koşul olarak kimlik doğrulaması yazılmıştı. Son koşullar (ödemenin tahsil edilmesi, satışın kaydedilmesi) zaten ana ve alternatif senaryo metinlerinde geçtiği için tasarımda ana öyküden (ana senaryodan) gidildi.

## 3. Kasa Sınıfının Üye Alanları ve Veri Yapısı Seçimi

Kullanım senaryosunun birinci aktörü kasiyerdir, ama bütün işlerin yapıldığı odak nokta kasadır: kasiyer kasaya giriş yaptıktan sonra kasanın tuşlarına basarak çeşitli işler yaptırır. Bu yüzden tasarıma Kasa sınıfından başlandı.

Önce üye alanlar koda en yakın biçimde, adları ve türleriyle yazıldı. Nesneye yönelik programlamada get/set metotlarının adları üye alan adlarından türetildiği için bu adların net olması yararlıdır. Kasa sınıfının üye alanları:

- `kasiyer : Kasiyer` (küçük harfle üye alan adı, büyük harfle sınıf adı)
- `sube : Sube` (kasanın hangi şubede olduğu)
- `satislar : LinkedList<Satis>` (ekrandan, 00:20:00)

### 3.1 Satışlar neden bağlı listede?

Yapılan satışlar bir dizi, bir bağlı liste ya da başka bir veri yapısıyla tutulabilir. Hoca bağlı listeyi seçti:

- Belirli bir satışı sorgulamayı gerektiren bir kullanım senaryosu yoktur. En fazla gün sonu raporu alınır ve bu raporda bütün satışlar sırayla gezilir. Yani sıralı erişim yeterlidir, rastgele erişime (random access) ihtiyaç yoktur.
- Sürekli yeni satış eklenecektir. Dizide yer bitince diziyi genişletmek gerekir; bu bir dolu angarya iştir.

Bu yüzden satış nesnelerini tutan genel (generic) bir `LinkedList` en rahat çözümdür. Genel bağlı listenin ikinci sınıftaki nesneye yönelik programlama dersinde görüldüğü hatırlatıldı.

## 4. Giriş ve Satış Başlatma Metotları

### 4.1 `login`

Kasiyerin giriş yapması için bir metot gerekir. Metot kullanıcı adı ve parola alır, işlem başarılıysa `true`, değilse `false` döndürür (ekrandan, 00:20:00):

```text
+ login( uName, passwd : String ) : boolean
```

Gerçekte parola açık metin olarak gönderilmez, özeti (hash) gönderilir. Ama dersin konusu veri güvenliği ya da sistem tasarımı olmadığı için bu aşamada bu kadarı yeterli görüldü.

### 4.2 `satisBaslat`

Etkinlik şemasında müşterinin kasaya gelmesi fiziksel bir olaydır, kasada yapılacak bir iş değildir. Kasiyerin yeni satış başlatması ise kasanın işidir. Bu yüzden `satisBaslat( )` metodu eklendi.

- **Parametre gerekir mi?** Hayır. Metot yeni satış nesnesini kendi içinde oluşturur.
- **Satışın kimliği gerekir mi?** Sonraki gereksinimlere bakıldığında satışa özel bir kimlik numarası gerekmez.
- **Tarih kimde oluşturulmalı?** Satışta tarih saklanacaktır. Java'da bir `Date` nesnesi oluşturulduğunda, yapıcısının çağrıldığı anın gün ve saatini gösterir. Bu yüzden tarih kasada oluşturulup satışa verilebilir, ama bu işi satışın kendi içinde yapması daha uygundur. Satış için varsayılan (default) yapıcı yeterlidir.
- **Başarı bilgisi döndürmeli mi?** Bu karar satışın arka planda nasıl yürüdüğüne bağlıdır. Klavyeden gelen olayları bekleyen bir süreç sürekli mi çalışıyor, yoksa `satisBaslat` yeni bir iş parçacığı (thread) başlatıp bütün işi o mu yönetiyor? Farklı yaklaşımlar olabileceği için metot şimdilik parametresiz ve dönüş türü boş bırakıldı. Bu sistem düzeyi ayrıntı istenirse ayrı bir etkinlik ya da sıralama şemasıyla çizilebilir.

## 5. Barkod Girişi ve Şubedeki Ürün Tablosu

Etkinlik şemasında sonraki adım kasiyerin ürün barkodu girmesidir. Girilen barkod bir veri girişidir, bu yüzden metoda parametre olarak aktarılır: `barkodGir( barkod : String )`.

Kullanım senaryosu metnine göre barkod geçerliyse sistem bir satış kalemi (satış maddesi) oluşturur; kalemde ürünün tanımı, fiyatı ve toplam bedel yer alır. Demek ki barkod girildiğinde o barkodla ilişkili ürünün bir şekilde bulunabilmesi gerekir.

Hoca bu noktanın şimdiye kadarki metinlerde yer almadığını vurguladı. Analiz metinleri müşteri odaklıydı; müşterinin gereksinimlerine ve işin nasıl yapılmasını istediğine odaklanıyordu. Gerçeklemeye gelince nesneler arası ilişkiler, özellikle "tekil tanımlayıcı ile ona karşılık gelen asıl nesne" ilişkileri düşünülür ve bu ayrıntılar ortaya çıkar. Bu yüzden barkod giriş metodu barkodu alıp ilgili ürünü döndürecek biçimde tanımlandı: `barkodGir( barkod : String ) : Urun`.

### 5.1 Ürünler nerede ve nasıl tutulur?

Analizde şubede satılan ürünlerden zaten söz edilmişti; şubede satılabilecek bütün ürünlerin listesi Şube sınıfında yer alır. Şube'den Ürün'e bir-çok ilişkisinin veri yapısı seçilirken barkoddan ürüne erişim gerektiği görüldü. Barkod tekil bir tanımlayıcıdır. Bütün kalemleri tek tek arayan sıralı bir arama yerine doğrudan (rastgele) erişim gerekir.

Java'daki bu tür yapılardan `HashMap` ve `Hashtable` hatırlatıldı. `HashMap` çok iş parçacıklı kullanıma uygun (thread-safe) değildir. Gerçek sistemde çok iş parçacığı olup olmayacağına göre karar vermek gerekir, ama derste sistem katmanı düşünülmediği için `HashMap` seçildi. Yapı anahtar-değer (key-value) çiftlerinden oluşur: anahtar `String` türünden barkod, değer `Urun` nesnesidir. Şube sınıfının son hali (ekrandan, 00:30:00):

```text
Şube
- ad, adres, vergiNo : String
- urunler : Hashmap<String,Urun>
+ urunBul( barkod:String ) : Urun
```

Kasa ilişkili olduğu şube nesnesine "elimde şöyle bir barkod var, bu ürün neymiş, bana döndür" diye sorar. Bunun için Şube'de `urunBul` adlı bir hizmet metodu gerekir.

## 6. Ana Senaryonun Sıralama Şeması

Konuşulan ayrıntıların unutulmaması için sınıf şemasıyla birlikte bir sıralama şeması da çizildi. Hoca, aksi halde kararları sağa sola notlar olarak düşmek gerekeceğini ve şemanın notlardan görünmez hale geleceğini söyledi.

### 6.1 İlk çizim

İlk çizimde kasiyerin `:Kasa` nesnesine `urunGir(barkod:String)` çağrısı yaptığı, kasanın `sube:Sube` nesnesine `urunBul( barkod )` dediği ve şubenin `urun` döndürdüğü gösterildi (ekrandan, 00:35:00). İkinci çağrıda `barkod : String` türünü yeniden yazmak gerekmez; gelen barkod değerinin aynen iletildiği bellidir. Dönen ürün nesnesinin fiyatı gibi bilgiler sonra sorulacağı için `urun:Urun` nesnesi de şemaya şimdiden konuldu; kullanılmazsa sonra silinebilir.

### 6.2 Aktif satış üye alanı

Satışlar bağlı listede tutulacaktı. Hoca bu listede yalnız tamamlanmış satışların durmasını, o anda süren satış için ayrı bir nesne olmasını istedi. Her şey `satisBaslat` metodunun içinde gerçekleşseydi o metot içinde bir yerel değişken tanımlamak yeterli olabilirdi. Ama süren satış üye alan olarak tutulursa başka metotlardan da erişilebilir; bu daha esnek bir çözümdür. Kasa'ya `aktifSatis : Satis` üye alanı eklendi (ekrandan, 01:00:00). Adında sınıf adı geçtiği için sıralama şemasında `aktifSatis` diye yazmak yeterlidir, ayrıca `:Satis` yazmaya gerek yoktur.

### 6.3 Sıranın düzeltilmesi

Hoca önce ürün girişine odaklandığı için satış başlatmayı yanlışlıkla ürün girişinin içine koyduğunu fark etti ve düzeltti: etkinlik şemasına göre önce kasiyer yeni satış başlatır, sonra ürün barkodu girer. Hoca, UML aracında unutulan bir şeyin ilgili yerden yeni çizgi çekilerek sonradan eklenebilmesini bir avantaj olarak gösterdi.

Düzeltilmiş baş kısım şöyledir (ekrandan, 00:40:00):

```text
Kasiyer -> :Kasa         : satisBaslat( )
:Kasa   -> aktifSatis    : new( )
aktifSatis -> aktifSatis : tarih = new( )
aktifSatis --> :Kasa     (dönüş)
:Kasa   --> Kasiyer      (dönüş)
```

Tarih nesnesi ayrı bir yaşam çizgisi olarak gösterilmedi, çünkü sonra ayrıca sorgulanmayacak (bir tarihten önce mi sonra mı gibi bir soru yok). Ama ilklendirildiğini göstermek yararlıdır. Hoca bunu "söz uçar, yazı kalır" diye özetledi: sözle söylenen ayrıntı şemada yerini bulmalıdır.

## 7. Satış Kalemini Kim Oluşturmalı?

Barkod geçerliyse satış kalemi oluşturulur. Senaryodaki "sistem" aslında kasadır. Kasa satıştan bir satış kalemi oluşturmasını isteyebilir. İki yaklaşım vardır:

- Kasa satış kalemini kendisi oluşturup satışa verir.
- Kasa gerekli bilgiyi satışa verir, satış kalemi satış oluşturur.

Hoca en doğru kararın şu ilke olduğunu söyledi: **bir iş, o işle ilgili veri neredeyse orada yapılır.** Ama bir iş için gereken bütün veri nadiren tek yerde bulunur. Burada ilgili ürünün ne olduğunu kasa şubeden öğrenmiştir, ama satış kalemlerini saklayacak olan satış nesnesidir. Bu yüzden kasa, satışa yeni kalemde kullanılacak ürünü verir; satış kalemini satış nesnesi oluşturur ve ürünle ilişkilendirir.

> **Hocanın vurgusu:** En mantıklı olan ve nesneye yönelimin asıl yapmamızı istediği şey budur: işi, o işin verisine sahip olan nesneye yaptırmak.

Satış sınıfına `kalemOlustur( urun : Urun )` metodu eklendi. Sıralama şemasında kasa, bulduğu ürünle aktifSatis'in `kalemOlustur( urun )` metodunu çağırır (ekrandan, 00:40:00). Satış kalemlerinin de bir listede tutulması gerektiği için Satış'a `kalemler : LinkedList<SatisKalemi>` eklendi. Hoca sınıf adlarında Türkçe karakter kullanmadığını, şemada kalan adları da değiştirmeyeceğini belirtti.

## 8. Adet Bilgisi ve Geçersiz Barkod

### 8.1 Adet

Bir üründen birden fazla adet alınması da düşünüldü. Bir adet ve n adet ayrı ayrı kodlanmalı mı? Hoca buna gerek olmadığını söyledi. Aynı ürün iki kez okutulursa her seferinde bir adet geçer. Kasiyer adedi girip ürünü bir kez de okutabilir; hangisinin kolayına geldiği fark etmez. Genel durum n adettir, bir adet onun özel durumudur. Bu yüzden barkod giriş metoduna adet bilgisi de parametre olarak eklendi:

```text
+ barkodGir( barkod : String, adet : int ) : Urun
```

Adet bilgisi kalem oluşturulurken de satışa iletilir: `kalemOlustur( urun : Urun, adet : int )`. Satış kalemi hangi üründen kaç adet olduğunu bilmek zorunda olduğu için yapıcısı bu iki bilgiyi alır: `SatisKalemi( urun : Urun, adet : int )`. Kalem oluşturulur oluşturulmaz kalemler listesine eklenir.

### 8.2 Geçersiz barkod

Geçersiz barkod alternatif senaryosu da hatırlandı. Şube ilgili ürünü bulamazsa `null` döndürür; kasa bu durumda null kontrolü yapar, uyarı verir ve akış sona erer. Etkinlik şemasında senaryo sonuna ok çizilebilir, ama sıralama şemasında akışın bitişini göstermek sıkıntılıdır. Bu yüzden şemaya bir not düşüldü (ekrandan, 00:50:00):

```text
[urun==null] uyariVer( ) return;
```

### 8.3 Ana senaryo şemasının son hali

Ana senaryo şeması `AnaSenaryo.seq.violet` adıyla kaydedildi (ekrandan, 00:55:00). Yaşam çizgileri: (kasiyer), `:Kasa`, `aktifSatis`, `sube:Sube`, `:SatisKalemi`, `urun:Urun`. Mesajlar:

```text
Kasiyer -> :Kasa           : satisBaslat( )
  :Kasa -> aktifSatis      : new( )
    aktifSatis -> aktifSatis : tarih = new( )
  aktifSatis --> :Kasa
:Kasa --> Kasiyer
Kasiyer -> :Kasa           : urunGir(barkod:String, adet:int)
  [not: [urun==null] uyariVer( ) return;]
  :Kasa -> sube:Sube       : urunBul( barkod )
  sube:Sube --> :Kasa      : urun
  :Kasa -> aktifSatis      : kalemOlustur(urun,adet)
    aktifSatis -> :SatisKalemi : new(urun,adet)
    :SatisKalemi --> aktifSatis
  aktifSatis --> :Kasa
:Kasa --> Kasiyer
```

Hoca, bir senaryonun ana akışını ve bütün alternatiflerini tek bir sıralama şemasına sıkıştırmaya çalışmanın anlamı olmadığını söyledi. Ürün silme bu yüzden ayrı bir şemaya bırakıldı.

> **Ders sonrası not:** Sınıf şemasında Kasa'nın metodu `barkodGir( barkod : String, adet : int ) : Urun` adını taşırken sıralama şemasında aynı çağrı `urunGir(barkod:String, adet:int)` diye yazılmış (ekrandan, 00:55:00 ve 01:05:00). Hocanın derste vurguladığı ad tutarlılığı kuralına göre ikisinden biri seçilip iki şemada da aynı ad kullanılmalıdır.

## 9. Toplam Hesaplama, Ödeme ve Fiş

### 9.1 Toplam hesaplama

Ürünler bitince kasiyer toplamı bildirir. Kasa'ya parametresiz bir `toplamHesapla( ) : double` metodu eklendi. Ürünler zaten barkod giriş metoduyla satışa aktarılmış, satış da kalemlerini oluşturmuştur. Toplamı asıl hesaplayacak olan satıştır, çünkü kalemler satışla ilişkilidir. Ama kasanın satışa "artık senden toplamı istiyorum" diye bir çağrı yapması gerekir. Bu yüzden aynı adlı metot hem Kasa'da hem Satış'ta bulunur, ama gövdeleri çok farklıdır: Kasa'daki metot yalnız aktif satışın `toplamHesapla` metodunu çağırır ve onun döndürdüğü değeri aynen döndürür.

Satış, her satış kalemine bedelini sorar. Kalemde adet bilgisi ve hangi ürünle ilişkili olduğu bilgisi vardır; kalem adet × ürün fiyatı döndürür. Bir satış kaleminin kendi bedeline terminolojide ara toplam denir; bu yüzden SatışKalemi'ne `araToplamHesapla( ) : double` eklendi (ekrandan, 01:00:00).

Sıralama şemasında akış şöyle çizildi:

```text
Kasiyer -> :Kasa              : toplamHesapla( )
  :Kasa -> aktifSatis         : toplamHesapla( )
    * aktifSatis -> :SatisKalemi : araToplamHesapla( )   (her kalem için, döngü)
        :SatisKalemi -> urun:Urun  : getFiyat( )
        urun:Urun --> :SatisKalemi : fiyat
      :SatisKalemi --> aktifSatis  : adet * fiyat
  aktifSatis --> :Kasa        : kümülatif toplam
:Kasa --> Kasiyer             : (aynı değer)
```

Döngü, nesneye yönelik programlama dersinde görüldüğü gibi çağrının önüne `*` konarak gösterilir. Kodda `toplam = toplam + adet * fiyat` gibi bir birikimli toplama yapılır, ama sıralama şemasında yalnız metot çağrıları gösterildiği için bu ifade yazılmaz; dönüş okuna "kümülatif toplam" yazmak yeterlidir.

> **Hocanın vurgusu:** Sıralama şemasına her metot çağrısını eklemeden önce sınıf şemasına dönüp metodun adının tam olarak ne olduğuna bakılmalı. İki şema arasında tutarsızlık olmamalı; ödevler ve projeler buna göre kontrol edilir. Sınıf şemasından kopyalayıp yapıştırmak da bu işi kolaylaştırır.

Hoca, uzayan ana senaryo şemasının istenirse satış başlatma, ürün girme ve toplam hesaplama olarak üç ayrı sıralama şemasına bölünebileceğini de söyledi.

### 9.2 Ödeme ve fiş

Ödeme tahsili ve fiş basma metotlarının ayrıntısı çizilmedi, yalnız sınıf şemasına eklendi (ekrandan, 01:05:00):

- `odemeTahsil( ) : boolean`: Ödeme başarılı ya da başarısız olabilir (örneğin provizyon alınamayabilir).
- `fisBas( ) : String`: Fiş doğrudan yazıcıya basılıyorsa bir şey döndürmesine gerek yoktur. Fişin içeriği oluşturulup döndürülüyorsa içerik metni döndürür.

### 9.3 Yapıcılar ve get metotları

Sınıfların boş kalmaması için yapıcılar ve get metotları da eklendi. Ürün oluşturulurken barkod, tanım, fiyat ve KDV verilmelidir; varsayılan yapıcı işe yaramaz (ekrandan, 01:15:00):

```text
Ürün
- barkod, tanim : String
- fiyat, KDV : float
+ Urun( barkod : String, tanim : String, fiyat : float, KDV : float )
+ getBarkod( ) : String
+ getTanim( ) : String
+ getFiyat( ) : float
+ getKDV( ) : float

Ödeme
- miktar : double
+ Odeme( miktar : double )
+ getMiktar( ) : double
```

Satış kalemi için adedin get metodu bu aşamada gerekmedi, çünkü ara toplamı kalem kendi bilgisiyle hesaplar. Ürün iptali tasarlanınca gerekebileceği söylendi (aşağıda gerçekten gerekti).

## 10. Ders Notundaki Tasarım Modeliyle Karşılaştırma

Derste birlikte yapılan tasarım, ders notundaki "NextGenPOS Tasarım Modeli" ile karşılaştırıldı (ekrandan, 01:10:00). Ders notundaki model şöyledir (karede okunabildiği kadarıyla):

```text
SatisKalemi
- miktar : int
- urun : Urun (final)
+ SatisKalemi( urun : Urun, miktar : int )
+ SatisKalemi( urun : Urun )
+ getUrun( ) : Urun
+ getMiktar( ) : int
+ miktarArttir( int )
+ miktarAzalt( int )
+ getBedel( ) : double

Urun
- tanim, barkod : String
- fiyat : double
+ Urun( tanim : String, barkod : String, fiyat : double )
+ getTanim( ) : String
+ getBarkod( ) : String
+ getFiyat( ) : double

Satis
- tarih : Date
- kalemler : Vector<SatisKalemi>
+ Satis( )
+ urunEkle( urun : Urun, adet : int )
- kalemAra( barkod : String ) : SatisKalemi
+ urunEksilt( Urun ) : boolean
+ getKalemler( ) : String
+ getDate( ) : Date
+ toplamBul( ) : double

Sube
- ad, adres : String
+ urunBul( barkod : String ) : Urun

Katalog
- urunler : Hashtable
+ urunBul( barkod : ... )

Odeme
- miktar : double
+ Odeme( double )
+ getOdeme( ) : double

Kasa
- sube : Sube
- satislar : Vector<Satis>
- sonSatis : Satis
- bostaBeklemede : boolean
+ Kasa( Sube )
+ satisBaslat( ) : boolean
+ urunGir( barkod : String, adet : int ) : boolean
+ urunSil( barkod : String ) : boolean
+ makbuzVer( ) : String
```

<!-- BELİRSİZ: Ders notundaki Katalog sınıfının sağ kenarı ve yanındaki açıklama notu ("Katalog sınıfının eklenmesi ... Ürün stok yönetimi sorumluluğu Şube sınıfında kalması uyumu ...") karede kesik; tam metni okunamadı (ekrandan, 01:10:00). Ders notundaki Ürün'de KDV alanı görünmüyor. -->

Karşılaştırmada öne çıkan farklar:

- **Katalog sınıfı:** Ders notunda şubedeki ürünler ayrı bir Katalog sınıfına bölünmüştür (bir sınıfı ikiye ayırma, "extract class"). Farklı şubelerde farklı kataloglar olacaksa ders notundaki çözüm daha mantıklıdır. Ama büyük bir saklama maliyeti yoksa, herhangi bir şubede satılabilecek bütün ürünlerin bilgisinin bütün şubelerde bulunması da düşünülebilir; bu çok kritik bir fark değildir.
- **Ürün:** Derste get metotları aynı biçimde eklendi; derste ayrıca KDV üye alanı vardır.
- **Kalemin bedeli:** Ders notunda `getBedel()`, derste `araToplamHesapla()` adı verildi. Adlar farklı ama yaptıkları iş aynıdır.
- **Kalem ekleme:** Ders notunda `urunEkle`, derste `kalemOlustur`; mantık aynıdır.
- **Liste türü:** Ders notunda `Vector` kullanılmıştır. Çok iş parçacıklı kullanım olursa `Vector`, olmazsa `LinkedList` seçilebileceği hatırlatıldı.
- **Varsayılan yapıcı:** Ders notunda kalem listesinin ilklendirilmesi önemli olduğu için Satış'a varsayılan yapıcı gösterilmiştir.
- **Miktar artırma ve azaltma:** Ders notundaki SatışKalemi'nde `miktarArttir` ve `miktarAzalt` vardır. Hoca miktar artırmayı gereksiz (overkill) buldu, azaltmayı ise gerekli gördü.
- **Kalem arama:** Ders notunda `kalemAra( barkod )` özel (private) bir metottur, çünkü asıl metot `urunEksilt`'tir ve `kalemAra` onun içinden çağrılır.
- **Tarih get metodu:** Fiş basılırken tarih gerekeceği için Satış'a `getTarih( ) : Date` eklendi.

### 10.1 Miktar artırma neden gereksiz?

Hoca şu örneği verdi: biri kasada iki şişe su almış, sonra yanındakiler de susayıp iki şişe daha getirmiş. İlk iki suyun satış kalemini bulup adedini iki artırmak ile ayrıca iki adetlik yeni bir kalem oluşturmak arasında ödenecek toplam açısından hiçbir fark yoktur. Fişte "2 × 2 su" ya da "4 × 1 su" görünmesi bir şey değiştirmez. Bu yüzden miktar artırma gereksizdir.

Miktar azaltma ise gereklidir: üç su alınmış, biri sızdırıyorsa müşteri "birini bırakıyorum" diyebilmeli; ya da üçünün birden iptalini isteyebilmelidir.

## 11. Alternatif Senaryo: Ürün Silme

### 11.1 Metot imzaları

Bütün işleri başlatan yer yine kasadır. Kasa'ya hangi ürünün (barkod) kaç adet silineceğini alan bir `urunSil` metodu eklendi. Bir boolean döndürmesine pek gerek görülmedi. Mantık barkod girişindekiyle aynıdır: n adet silmek ile bir adet silmek arasındaki tek fark n'nin 1 olmasıdır.

Çağrı aktif satışa iletilir. Satış'a eklenecek metoda barkod mu ürün mü verilmeli? Hoca barkodu seçti:

- Kalem oluştururken ürün nesnesi verilmelidir, çünkü kayıt ilk kez oluşturulacaktır ve ürün nesnesine ihtiyaç vardır.
- Ürün silinirken ise o ürün zaten bir kalemde vardır. Ürün nesnelerinin eşitliği yerine barkodların (tekil tanımlayıcıların) eşitliğine bakmanın sakıncası yoktur. Alakasız bir barkod okunursa kalemler arasında bulunamaz ve işlem başarısız olur.
- Barkodla girilen ürünün hangi nesne olduğunu yeniden şubeye sormaktansa barkod metnini doğrudan satışa iletmek daha hızlıdır ve daha az veri iletişimi (ağ trafiği) doğurur.

Satış'a `urunSil( barkod : String, adet : int ) : boolean` eklendi (ekrandan, 01:15:00).

### 11.2 Kalemden silme mi, adet azaltma mı?

Satış, hangi kalemden silme yapacağını bulmalıdır. Kalemden üç adet alınmışsa ve biri silinecekse adet ikiye düşer. Kalemden bir tane alınmışsa ve bir tane silinecekse bütün kalem listeden çıkarılmalıdır. Listede "0 adet" görünen bir kalem olmamalıdır: bedeli sıfır olsa da satılmamış bir ürünün fişte sıfır adetle görünmesi saçmadır.

Bu kararlar için SatışKalemi'ne şu metotlar eklendi (ekrandan, 01:15:00):

```text
SatışKalemi
- adet : int
- urun : Urun
+ SatisKalemi( urun : Urun, adet : int )
+ araToplamHesapla( ) : double
+ getUrunBarkod( ) : String
+ getAdet( ) ...
+ setAdet( ... )
```

<!-- BELİRSİZ: getAdet ve setAdet metotlarının tam imzaları karede görünmüyor; altyazıda yalnız adları geçiyor (01:15:11-01:15:29). -->

### 11.3 Alternatif senaryonun sıralama şeması

Ürün silme için ayrı bir sıralama şeması (`AltSenaryo.seq.violet`) çizildi. Gereken nesneler ana senaryo şemasından seçilip kopyalandı. Silinecek kalemin bir referansta tutulması gerektiği için ona bir ad verildi. Önce `silinecek`, sonra daha anlamlı olsun diye `silinebilecek` dendi, çünkü kalem silinmeyebilir, yalnız adedi azaltılabilir.

Ad seçiminde bir incelik de vardır: hem silinecek miktara hem kalemdeki mevcut miktara "adet" denirse anlam karışır. Bu yüzden `silinecekAdet` ve `mevcutAdet` adları kullanıldı; hoca adların biraz uzun olmasının sorun olmadığını söyledi.

Şemanın son hali (ekrandan, 01:25:00):

```text
Kasiyer -> :Kasa         : urunSil( barkod : String, adet : int )
  :Kasa -> aktifSatis    : urunSil( barkod, silinecekAdet )
    aktifSatis -> aktifSatis : <<silinebilecek olanı bul>>
    aktifSatis -> silinebilecek:SatisKalemi : getAdet( )
    silinebilecek:SatisKalemi --> aktifSatis : mevcutAdet
    aktifSatis -> aktifSatis : [silinecekAdet == mevcutAdet] <<silinebilecek olanı sil>>
    aktifSatis -> silinebilecek:SatisKalemi : [else] setAdet( mevcutAdet - silinecekAdet )
    silinebilecek:SatisKalemi --> aktifSatis
  aktifSatis --> :Kasa
:Kasa --> Kasiyer
```

"Silinebilecek olanı bul" adımında aktif satış, kalemler listesinde bir yineleyici (iterator) alıp elemanları tek tek dolaşır ve barkodu eşleşen kalemi bulur. Bu ayrı bir metot çağrısı olmasa da önemli bir iş mantığı olduğu için nesnenin kendine çağrısı biçiminde, stereotip (`<<...>>`) ile gösterildi. Silme işini de satış kalemi kendisi yapmaz; kalemi listeden satış siler, bu yüzden bu adım da satışın kendine çağrısıdır. Koşullar köşeli parantezle yazıldı; uzatmamak için ikinci koşul kısaca `[else]` diye, bir öncekinin değilse kolu olarak gösterildi.

Hoca, sıralama şemasını çizerken sınıf şemasında eksik bir şey fark etseydi geri dönüp sınıf şemasına ekleyeceğini söyledi; bu örnekte ekstra bir şey çıkmadı. Ders notundaki sınıf şemasında da alternatif senaryolar için ayrıca bir şey yoktur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:50): Kasanın yaptığı satışlar dizi, bağlı liste ya da başka hangi veri yapısıyla tutulmalıdır?

> **Cevap (derste verildi):** Bağlı liste (`LinkedList<Satis>`). Belirli bir satışı sorgulama gereksinimi yoktur; gün sonu raporunda bütün satışlar sırayla gezilir, yani rastgele erişim değil sıralı erişim gerekir. Ayrıca sürekli yeni satış eklenir; dizide yer bitince genişletmek gerekir.

**Soru 2** (derste sözlü, 00:18:38): `satisBaslat` metodu parametre almalı mı? Satışın tarihi nerede oluşturulmalı?

> **Cevap (derste verildi):** Parametre gerekmez; metot yeni satış nesnesini kendi içinde oluşturur. Java'da `Date` nesnesi oluşturulduğu anın tarih ve saatini taşıdığı için tarih, satışın kendi (varsayılan) yapıcısında oluşturulabilir; bu, tarihi kasada oluşturup vermekten daha uygundur.

**Soru 3** (derste sözlü, 00:24:08): Kasa, girilen barkodun hangi ürüne karşılık geldiğini nereden ve nasıl bulmalıdır?

> **Cevap (derste verildi):** Şubede satılan ürünler Şube sınıfında tutulur. Barkod tekil bir anahtar olduğu ve doğrudan erişim gerektiği için `urunler : Hashmap<String,Urun>` kullanılır. Kasa, şubenin `urunBul( barkod:String ) : Urun` hizmet metodunu çağırır.

**Soru 4** (derste sözlü, 00:37:20): Satış kalemini kasa mı oluşturup satışa vermeli, yoksa satış mı oluşturmalı?

> **Cevap (derste verildi):** Satış oluşturmalıdır. Bir iş, o işin verisi neredeyse orada yapılır; kalemleri saklayan satıştır. Kasa ürünü şubeden öğrenir ve `kalemOlustur( urun, adet )` ile satışa verir; kalemi satış oluşturup ürünle ilişkilendirir.

**Soru 5** (derste sözlü, 01:12:06): Ürün silme için satışa barkod mu, ürün nesnesi mi verilmelidir?

> **Cevap (derste verildi):** Barkod. Silinecek ürün zaten bir kalemdedir; barkodların eşitliğine bakmak yeterlidir. Ürünü yeniden şubeye sormaya gerek kalmaz, daha az veri iletilir. Kalem oluştururken ise ürün nesnesi gerekir, çünkü kayıt ilk kez oluşturulur.

**Soru 6** (derste sözlü, 01:13:49): Silinecek adet kalemdeki mevcut adede eşitse ne yapılmalı, küçükse ne yapılmalı?

> **Cevap (derste verildi):** Eşitse kalem listeden tamamen silinir (fişte 0 adetli kalem kalmamalı). Değilse `setAdet( mevcutAdet - silinecekAdet )` ile adet azaltılır.

## Dersin Toparlaması

Bu derste NextGenPOS örneğinin analiz sınıf şeması, kullanım senaryosu metni ve etkinlik şeması rehber alınarak tasarım sınıf şemasına dönüştürüldü. Kasa, işlerin başladığı sınıf olarak ele alındı; üye alanlar türleriyle yazıldı ve veri yapıları kullanım biçimine göre seçildi (sıralı erişim ve sık ekleme için bağlı liste, anahtarla doğrudan erişim için eşleme tablosu). Metotlar etkinlik şemasındaki eylemlerden çıkarıldı. Her önemli karar bir sıralama şemasıyla kayda geçirildi: satış başlatma, ürün girme (geçersiz barkod notu dahil), toplam hesaplama ve ürün silme. Tasarım boyunca "işi, verisi olan nesneye yaptır" ilkesi uygulandı ve sınıf şeması ile sıralama şemalarındaki adların tutarlı olması gerektiği vurgulandı. Son olarak birlikte yapılan tasarım ders notundaki modelle karşılaştırıldı; farkların çoğunun adlandırma ve sorumluluk bölüşümü tercihi olduğu görüldü.

Bir sonraki derste ders notlarının yazılım sınama teknikleri bölümüne geçileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
