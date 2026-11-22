# Ders 10 Çalışma Özeti

## Genel Konular

- Çift yönlü sahiplik ilişkisi (two-way association)
  - Önceki derste ilişki tek yönlüydü: kişi (`Person`) arabasını biliyordu, araba (`Car`) sahibini bilmiyordu. Bir araba kaydından sahibini sorgulamak gerekiyorsa ters yöndeki ilişki de kurulmalıdır.
  - UML şemasında `Person` ile `Car` arasında iki uçlu ok vardır; her iki uçta da `0..1` yazar (ekrandan, 00:05:00). `Person` sınıfı değişmez. `Car` sınıfına `owner : Person` üye alanı, `getOwner()`/`setOwner(Person)` metotları ve ikinci bir kurucu `Car(plateNo : String, Person)` eklenir.
  - `introduceSelf()` metotları artık ekrana yazmaz, bilgiyi içeren `String` nesnesini döndürür. Çağıran taraf bu metni ekrana, bir iletişim kutusuna, dosyaya ya da veri tabanına istediği gibi yazar.
  - `introduceSelf()` içinde ilişki `null` kontrolüyle denetlenir: araba bir kişiye bağlıysa sahibin adı da metne eklenir.
- Çift yönlü ilişkinin tutarlılığı
  - En basit kodlamada iki yön ayrı ayrı kurulmalıdır: `oktay.setCar(rover);` ve `rover.setOwner(oktay);`. Biri unutulursa derleme hatası çıkmaz ama sonuç tutarsız olur. Örneğin kişi "06 plakalı aracım var" der, araç sahibinden habersizdir. Bu bir mantık hatasıdır (bug).
  - Bir yönden kurulan ilişkinin öbür yönü kendiliğinden kurması için setter metotları birbirini çağıracak şekilde yazılır.
- Karşılıklı setter çağrısında sonsuz özyineleme
  - `Person.setCar` içinde koşulsuz `car.setOwner(this)` ve `Car.setOwner` içinde koşulsuz `owner.setCar(this)` yazılırsa iki metot birbirini durmadan çağırır ve program `StackOverflowError` ile çöker. Konsolda `Car.setOwner(Car.java:13)` ve `Person.setCar(Person.java:14)` satırları art arda tekrarlanır (ekrandan, 00:15:00).
  - Çözüm: karşı tarafa yalnız durum farklıysa haber verilir. Kişi tarafında `if( car.getOwner() != this ) car.setOwner(this);`, araba tarafında `if( owner.getCar() != this ) owner.setCar(this);` yazılır (ekrandan, 00:30:00).
- Daha karmaşık durumlar: kurucu, satış ve çapraz atama
  - Kurucuda sahip verilirse doğrudan atama yerine `this.setOwner(owner);` çağrılır. Böylece kurucu da ilişkinin iki yönünü kurar (ekrandan, 00:50:00).
  - Satış: Oktay'ın arabası Aziz'e verildiğinde (`aziz.setCar(rover)`) Oktay hâlâ "06 plakalı aracım var" der. Çözmek için önceki sahip (`prevOwner`) ve önceki araba (`prevCar`) incelenir. Önceki değer `null` olabilir, `this` olabilir ya da başka bir nesne olabilir; her durum ayrı ele alınır.
  - Kişinin mevcut arabası varsa yeni arabaya geçmeden önce eski arabanın sahibi boşaltılmalıdır. Bunu `setOwner(null)` ile yapmak yine sonsuz döngü doğurdu. Hoca bunun yerine ayrı metotlar yazdı: `Car.removeOwner(Person)` ve `Person.removeCar(Car)`. Bu metotlar ilişkiyi yalnız parametre olarak gelen nesne gerçekten mevcut sahip ya da mevcut araba ise boşaltır.
- Çift yönlü ilişkinin maliyeti
  - Çift yönlü ilişki daha esnek ve güçlüdür ama tutarlılığını sağlamak ek çaba ister.
  - Müşteri istemediği sürece "ileride lazım olur" diye ilişkiyi baştan çift yönlü kodlamak doğru değildir.
- Parça-bütün ilişkileri: aggregation ve composition
  - Aggregation zayıf parça-bütün ilişkisidir. Bütün tarafında içi boş elmas çizilir. Çizilmese bile elmas ucunda `1`, öbür uçta `*` ve ok olduğu anlaşılır (ekrandan, 01:20:00).
  - Aggregation, association'dan yalnız kavramsal olarak daha güçlüdür: parçayı bütüne eklemenin daha sıkı kuralları vardır. Örneğin bir otobüs hattı en az iki duraktan oluşur (`Bus Route 1 —— 2..* Stop`).
  - Composition daha güçlü parça-bütün ilişkisidir; içi dolu elmasla gösterilir. Gücü şuradan gelir: bir parça aynı anda yalnız bir bütüne ait olabilir (`Team 1 —— * Player`) (ekrandan, 01:30:00). Bir durak birden fazla hatta bulunabilir, ama bir oyuncu aynı anda tek bir takımdadır.
  - Kaynak kodda elmasın türü bir şey değiştirmez. Asıl önemli olan, bütüne parça ekleyen metodun problem alanının kurallarını uygulamasıdır.
- Dizilerle bire-çok ilişki: `Gallery` örneği
  - `Gallery` sınıfının üyeleri `galleryName`, `cars : Car[]`, `carCount : int` ve `galleryOwner : Person` alanlarıdır. Galeri ile araba arasında düz `1 — *` sahiplik ilişkisi vardır; galeri arabalardan oluşmadığı için parça-bütün ilişkisi seçilmedi (ekrandan, 01:35:00).
  - `cars = new Car[30];` satırı hiçbir `Car` kurucusunu çalıştırmaz, yalnız dizi için bellek ayırır (ekrandan, 02:05:00).
  - `cars.length` dizinin kapasitesini verir, eleman sayısını vermez. Bu yüzden `maxCar` gibi bir alana gerek yoktur ama `carCount` gerekir. `carCount` hem "galeride kaç araba var" sorusunu yanıtlar hem de diziye ekleme indisi olarak kullanılır (ekrandan, 02:10:00).
  - `addCar` iki şeyi denetler: araba zaten dizide olmamalı ve dizide yer kalmış olmalı.
  - `searchCar` metodu aşırı yüklenmiştir (overload): `searchCar(Car)` nesnenin kendisini arar ve `boolean` döndürür. `searchCar(String plate)` plakaya göre arar, bulursa `Car` nesnesini, bulamazsa `null` döndürür (ekrandan, 02:20:00).
  - `removeCar(String plate)` bulduğu elemanın sağındaki elemanları birer sola kaydırır, son gözü `null` yapar, `carCount`'u azaltır ve silinen arabayı döndürür. `sellCar` önce `removeCar` çağırır, araba bulunduysa yeni sahibini atar (ekrandan, 02:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- İki yönlü ilişkide iki yönü de kurmak unutulmamalıdır
  - Unutulursa derleyici uyarmaz, ama nesneler birbiriyle çelişen bilgi verir. Bu tutarsızlık bir hatadır.
- `null` kontrolü her zaman yapılmalıdır
  - "Her arabanın sahibi olsun, tek parametreli kurucuyu silelim" fikri `null` kontrolünü gereksiz kılmaz. Biri yine de iki parametreli kurucuya elle `null` verebilir.
- Karşılıklı çağrıyı kesmek
  - Hoca bunu el sıkışma benzetmesiyle anlattı. İki kişi birbirine durmadan "merhaba, benim adım ..." derse tanışma hiç bitmez. Bir noktada "seni tanıdım" deyip kesmek gerekir. Kodda bu, "zaten ilişkiliysek tekrar çağırma" koşuludur.
- Nesne kimliği mi, tekil tanımlayıcı mı?
  - Kişi-araba atamalarında karşılaştırma nesne kimliğiyle (`!=`, `==`) yapıldı: aynı bellek adresindeki aynı nesne mi?
  - Galeriye ekleme gibi durumlarda tekil tanımlayıcı (plaka) üzerinden kontrol daha kapsayıcıdır. Plaka sahtekârlığında iki farklı nesne aynı plakayı taşıyabilir. Hoca, aksi belirtilmedikçe tekil tanımlayıcı üzerinden kontrolün daha doğru olduğunu söyledi.
- Aynı işi iki kez kodlamamak
  - Hoca slayttaki `removeCar` metodunun aramayı yeniden yaptığını, bunun yerine `searchCar` kullanılmasının daha doğru olacağını söyledi.
- Geri dönüş türü seçimi
  - `removeCar` `boolean` yerine `Car` döndürür. Silinen nesne çağırana verilir, böylece çağıran onu başka işlerde kullanabilir.
  - Parametreleri aynı olup yalnız geri dönüş türü farklı olan iki aynı adlı metot derleme hatası verir. Bu yüzden iki sürümü birlikte yazmak mümkün değildir.
- Dizinin `length` üyesi
  - `length` sonunda parantez olmayan bir üye alan erişimidir; Java'da diziler de nesnedir. Bu, "üye alanlara getter ile erişilir" ilkesinin dilin kendi içindeki bir istisnasıdır. Programcı kendi sınıflarında bu ilkeye uymalıdır.

## Kısa Tekrar Notları

- Çift yönlü ilişki: iki sınıfta da karşı sınıf türünden bir üye alan bulunur (`Person.car`, `Car.owner`).
- Setter'lar birbirini koşulsuz çağırırsa sonsuz özyineleme olur ve `StackOverflowError` çıkar.
- Koşul: `if( car.getOwner() != this )` ve `if( owner.getCar() != this )`.
- Kurucu içinde `this.setOwner(owner)` çağrılırsa kurucu da ilişkiyi iki yönlü kurar.
- Satışta eski sahibin bağlantısı koparılmalıdır; bunun için `removeOwner`/`removeCar` yardımcı metotları yazıldı.
- Aggregation: içi boş elmas, zayıf parça-bütün, ekleme kuralları var.
- Composition: içi dolu elmas, parça aynı anda tek bir bütüne ait.
- Elmas çizilmese de elmas ucu `1`, diğer uç `*` ve ok demektir.
- `new Car[30]` yalnız bellek ayırır, kurucu çalıştırmaz.
- `dizi.length` kapasiteyi verir, eleman sayısı ayrıca tutulur (`carCount`).
- `addCar`: tekrar ekleme yok ve kapasite kontrolü. Başarıda `true`, başarısızlıkta `false` döner.
- `for( Car car : cars )` for-each döngüsüdür; döngü değişkeni her adımda sıradaki elemanı gösterir.
- Diziden silmede elemanlar sola kaydırılır, son göz `null` yapılır, sayaç bir azaltılır.
- Plaka karşılaştırmasında `compareTo(...) == 0` yerine `equals` ya da büyük/küçük harfe duyarsız `equalsIgnoreCase` kullanılabilir.

## Detaylı Açıklamalar

- Çift yönlü ilişkinin kodlanması
  - `Car` sınıfının iki kurucusu vardır: yalnız plaka alan kurucu ve plaka ile sahip alan kurucu. Bir araba oluşturulduğu anda bir kişiye verilmek zorunda değildir, bu yüzden `Person` tarafında çokluk `0..1`'dir. Hoca dersin sonunda `Person` tarafının da `0..1` olması gerektiğini, `nyp04` şemasındaki `1`-`1` gösterimini düzelteceğini söyledi.
  - `Car.introduceSelf()` kodu (ekrandan, 00:30:00):

    ```java
    public String introduceSelf( ) {
        String intro;
        intro = "[CAR] My license plate is " + getPlate();
        if( owner != null )
            intro += " and my owner is " + owner.getName();
        return intro;
    }
    ```

  - Test programında `oktay` ve `aziz` kişileri ile `rover` ("06 OS 1934") ve `honda` ("47 AS 1946") arabaları oluşturulur. Doğru kurulduğunda çıktı şöyledir (ekrandan, 00:10:00):

    ```text
    [PERSON] My name is Oktay Sinanoğlu and the plate of my car is 06 OS 1934
    [CAR] My license plate is 06 OS 1934 and my owner is Oktay Sinanoğlu
    [PERSON] My name is Aziz Sancar and the plate of my car is 47 AS 1946
    [CAR] My license plate is 47 AS 1946 and my owner is Aziz Sancar
    ```

- Sonsuz döngünün izlenmesi
  - `oktay.setCar(rover)` çağrısında önce `this.car = rover` atanır, sonra `rover.setOwner(oktay)` çağrılır. Orada `this.owner = oktay` atanır ve tekrar `oktay.setCar(rover)` çağrılır. Döngü hiç bitmez.
  - Her metot çağrısı yığına (stack) yeni bir çerçeve ekler, çağrı bitince çerçeve atılır. Çağrılar hiç bitmediği için yığın taşar.
  - Koşul eklendikten sonraki akış: `oktay.setCar(rover)` içinde `rover.getOwner()` `null` döner. `null != oktay` olduğu için `rover.setOwner(oktay)` çağrılır. Orada `oktay.getCar()` artık `rover` döndürür ve `rover != rover` yanlış olur. Böylece çağrı zinciri kesilir.
  - Koşullu sürümde `main` içinde iki yönden biri yorum satırı yapılsa bile ilişki iki yönlü kurulur. İki yön de açıkça çağrılsa da sorun çıkmaz.
- Satış senaryosu için genişletilmiş `setCar` (ekrandan, 00:45:00; sonraki eklemeler altyazıdan)
  - Önce `Person prevOwner = car.getOwner();` alınır. `prevOwner == null || prevOwner != this` ise araba sahiplenilir. `prevOwner != null && prevOwner != this` ise eski sahibin arabası `null` yapılır.
  - Gelen parametre `null` olabilir (`setCar(null)`). O durumda `car.getOwner()` çağrısı `NullPointerException` verir. Bu yüzden bütün işlemler `if( car != null )` bloğuna alındı.
  - `Car.setOwner` buna simetrik yazıldı (`prevCar`, `owner.getCar()`).
- Test bakış açısı
  - Hoca öğrencilerden kodu çökertecek test senaryoları önermelerini istedi. Yazılımı sınarken programa hata yaptırmaya çalışan girdiler düşünmek gerekir.
- Para işlerinin tasarıma katılması (tasarım tartışması)
  - Arabanın alış ve satış fiyatı, galerinin bütçesi olmalıdır. `addCar` yalnız bütçe yetiyorsa eklemeli ve alış fiyatını bütçeden düşmelidir. Satışta bütçe satış fiyatı kadar artmalıdır.
  - Kişiye de bütçe eklenebilir. Ayrıca ortak bir `BankAccount` ya da `Wallet` sınıfı tasarlanıp hem kişiye hem galeriye verilebilir.
- Kapasite sınırı
  - Galeri sınırı yasal bir kuralsa ve bütün galeriler için geçerliyse `public final static` bir sabit kullanılır.
  - Sınır o galerinin fiziksel alanından geliyorsa normal bir `private` üye alan kullanılır. Bu durumda dizi büyütülmez, `addCar` `false` döndürür.
  - Dizi büyütülmek istenirse daha geniş yeni bir dizi oluşturulur, eski elemanlar ona kopyalanır ve üye alana yeni dizi atanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
