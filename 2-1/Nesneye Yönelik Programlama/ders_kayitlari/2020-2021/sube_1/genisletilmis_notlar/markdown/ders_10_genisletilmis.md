# Ders 10 Genişletilmiş Notu: Kompozisyon Örneği (Gallery), Kalıtım, Çok Biçimlilik ve super

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ders Öncesi Soru: İki Yönlü İlişkide Sahip Değişimi
- 2. Nesneler Arası İlişkilerin Tekrarı
- 3. Composition Örneği: Gallery Sınıfının UML Diyagramı
- 4. Gallery Sınıfının Kodu
- 5. MainProgram04 ve main Metodu
- 6. Kalıtım (Inheritance)
- 7. Kalıtımın Kuralları ve Kalıtım Ağacı
- 8. Doğru Kalıtım Modellemesi
- 9. Çok Biçimlilik (Polymorphism) ve super
- 10. Person, Employee, Manager Örneği
- 11. Company Sınıfının Ardışık Diyagramı
- 12. Overloading ve Overriding, Private Metotlar
- 13. Protected ve super Üzerine Soru-Cevap
- 14. Gereksinim Metninden UML: Hasta ve Doktor
- 15. java.lang.Object ve Date Sınıfı
- Örnek Sorular

## 1. Ders Öncesi Soru: İki Yönlü İlişkide Sahip Değişimi

Ders başlamadan önce bir öğrenci önceki derste yazılan iki yönlü ilişki kodu hakkında soru sordu. O kodda `Car` sınıfının `setOwner` metodu hem arabanın sahibini hem kişinin arabasını aynı anda değiştiriyordu.

**Soru:** Arabanın sahibi ileride başka biri yapılırsa arabadan eski sahibe artık ulaşılamıyor, ama eski sahip nesnesinde araba hâlâ duruyor. Sanki iki kişi aynı arabaya sahipmiş gibi oluyor. Buna karşı ne yapılabilirdi?

**Cevap:** Doğru; bu örnekte eski sahiple araba arasındaki ilişki koparılmadı. Önemli olan, arabaya "sahibin kim" diye sorulduğunda doğru kişiyi göstermesidir. Önlem olarak, arabanın kendisi tarafından teyit edilmeyen sahiplik iddiaları kabul edilmez: biri "bu arabanın sahibiyim" diyorsa, bundan sonra yazılacak sınıflarda arabanın da bunu doğrulayıp doğrulamadığı mutlaka kontrol edilir.

## 2. Nesneler Arası İlişkilerin Tekrarı

Hoca önceki derste başlanan nesne ilişkilerini kısaca tekrarladı. Nesneye yönelik kod yazarken nesneler arasında farklı türde ilişkiler kurulur.

- **Association (ilişkilendirme):** sahiplik ilişkisidir. Birinci nesne ikinci türden sıfır ya da daha çok nesneye sahip olabilir. Derste verilen örnek: bir müşterinin (customer) sıfır ya da daha çok siparişi (order) olabilir.
- **Aggregation (toplama):** yine sahiplik ilişkisidir ama association'dan biraz daha güçlüdür; birinci nesnenin ikinci türden en az bir (ya da en az iki) nesnesi olmalıdır. Örnek: bir otobüs güzergâhının (bus route) en az iki durağı (bus stop) olmalıdır, daha çok da olabilir. UML'de ilişkinin bir ucunda elmas işareti bulunur.
- **Composition (bileşim):** aggregation'dan da güçlüdür. Slayttaki tanıma göre aggregation'a benzer ama daha güçlü bir bütün-parça ilişkisidir; gücü, parçanın aynı anda yalnız bir bütüne ait olabilmesinden gelir. UML'de bütünün ucunda içi dolu elmas çizilir. Örnek: `Team` ile `Player` arasında, takım tarafında `1`, oyuncu tarafında `*` çokluğu olan bir composition vardır; bir takımın birden çok oyuncusu olabilir, bir oyuncu yalnız bir takıma aittir (ekrandan, 00:15:00).
- **Dependency (bağımlılık):** ikinci nesne birinci sınıfın üye alanlarında görünmez; yalnız birinci sınıfın metotlarında, yani metot gövdesinde ya da metot parametrelerinde kullanılır. Bu durumda birinci nesne ikinci nesneye bağımlıdır denir.

Association, aggregation ve composition'ın ortak noktası, ikinci nesnenin birinci sınıfın üye alanları (data member fields) bölümünde tanımlanmış olmasıdır. Bir sınıfın alanlarında başka bir sınıf türünden değişken görülüyorsa bu üç ilişkiden biri vardır.

Önceki derste tek yönlü association (kişi ve araba), ardından iki yönlü association (arabanın da sahibi olarak bir kişiyi tutması) işlenmişti. İki yönlü ilişkide kod satırlarının nasıl azaltılabileceği de konuşulmuştu: birinci nesnenin setter metodunda ikinci nesne atanırken ikinci nesnenin referansı kullanılarak birinci nesne de ikinci nesneye atanabilir; böylece iki taraf tek metotta güncellenir.

### 2.1 UML Çokluğunun Koda Yansıması

Hoca, iki yönlü association okunurken her ok yönünün ayrı düşünülmesi gerektiğini anlattı. Okun bir yönü alındığında okun çıktığı sınıf birinci nesne, gösterdiği sınıf ikinci nesnedir. Birinci sınıfın üye alanlarında ikinci sınıf türünden bir değişken mutlaka bulunmalıdır.

Kaç değişken olacağını karşı uçtaki çokluk belirler:

- Karşı uçta `1` yazıyorsa tek bir değişken tanımlanır.
- Karşı uçta `*` ya da `1..10` gibi bir aralık yazıyorsa bir dizi tanımlanır. Dersin ilerleyen bölümlerinde vektör, liste gibi başka veri yapıları da öğrenilecektir; o zaman bunlar da kullanılabilir.

Aynı iş okun öbür yönü için de yapılır. `Person` ile `Car` arasındaki iki yönlü 1-1 ilişkide `Person` sınıfında bir `Car` alanı, `Car` sınıfında da bir `Person` alanı bulunur (ekrandan, 00:25:00).

## 3. Composition Örneği: Gallery Sınıfının UML Diyagramı

Önceki derste kalınan yer composition örneğiydi. Bu örnekte birden çok arabanın satıldığı bir araba galerisi (gallery, autoshop) modellenir. Slayttaki açıklama şöyledir (ekrandan, 00:10:00):

- Satılacak birden çok arabayla ilişkili bir `Gallery` sınıfı oluşturulur. `Car` sınıfı da yeniden kullanılır.
- Yalnız plakayı parametre alan bir kurucu eklemek istenebilir. Slayt yazarı bunu yapmamayı seçmiştir: galeriye geçici bir tür sahip olarak bir `Person` nesnesi atanabilir.
- Galeri ile arabalar arasındaki ilişki composition ile gösterilmiştir. Bu ilişki `1..*` association ile de gösterilebilir; fark etmez.
- Örnek diziler ve for döngüsü kullanımını da gösterir.

Composition burada şu anlama gelir: bir galeride sıfır ya da daha çok araba bulunabilir, ama bir araba yalnız bir galeriye ait olabilir; aynı araba iki farklı galeride görünemez.

<!-- BELİRSİZ: 00:22:30 - 00:22:55 arasındaki altyazı Whisper tekrarıdır ("bir galeriye sahip"); bu aralıkta anlatılan ayrıntı çıkarılamadı. -->

### 3.1 Diyagramdaki Sınıflar

UML sınıf diyagramı `nyp04` paketindedir ve dört sınıf içerir (ekrandan, 00:25:00):

| Sınıf | Üye alanlar | Üye metotlar |
|---|---|---|
| `Person` | `- name : String`, `- car : Car` | `+ Person( name : String )`, `+ getName( ) : String`, `+ getCar( ) : Car`, `+ setCar( Car )`, `+ introduceSelf( ) : String` |
| `Car` | `- plate : String`, `- owner : Person` | `+ Car( plateNo : String, Person )`, `+ getOwner( ) : Person`, `+ setOwner( Person )`, `+ getPlate( ) : String`, `+ setPlate( ) : String`, `+ introduceSelf( ) : String` |
| `Gallery` | `- galleryName : String`, `- cars : Car[]`, `- carCount : int`, `- galleryOwner : Person` | `+ Gallery( name : String, owner : Person )`, `+ getGalleryName( ) : String`, `+ setGalleryName( galleryName : String )`, `+ addCar( car : Car ) : boolean`, `+ searchCar( aCar : Car ) : boolean`, `+ searchCar( plate : String ) : Car`, `+ removeCar( plate : String ) : Car`, `+ sellCar( plate : String, newOwner : Person ) : boolean`, `+ introduceSelf( ) : String` |
| `MainProgram04` | (yok) | `+ main( String[] )` |

İlişkiler:

- `Person` ile `Car`: iki yönlü association, iki uçta da `1`.
- `Gallery` ile `Person`: `Gallery`'den `Person`'a association, iki uçta da `1`. Galerinin tek sahibi olduğu için `Gallery` sınıfında tek bir `galleryOwner` değişkeni vardır.
- `Gallery` ile `Car`: composition; `Gallery` ucunda `1`, `Car` ucunda `*`. Karşı uçta `*` olduğu için `Gallery` sınıfında `Car[] cars` dizisi vardır.
- `MainProgram04` ile `Gallery` ve `Car`: kesikli okla dependency. `Car` ve `Gallery` sınıfları yalnız `main` metodunda kullanıldığı için `main` metodunu içeren sınıf bu iki sınıfa bağımlıdır.

### 3.2 Gallery'nin Alanları ve Metotları

`Gallery` sınıfında galerideki araba sayısını tutan `carCount`, galerinin adı `galleryName`, sahibi `galleryOwner` ve arabaları tutan `cars` dizisi vardır.

Kurucu iki parametre alır: biri galerinin adını, öbürü sahibini atar. Yani bir galeri oluşturulduğunda mutlaka bir adı ve bir sahibi olmalıdır. Arabaları da başlatan üç parametreli bir kurucu yazılmamıştır, çünkü galeri ilk açıldığında henüz arabası olmayabilir; ama ad ve sahip önemlidir.

Diğer metotlar:

- `addCar`: galeriye araba ekler, başarılıysa `true`, değilse `false` döndürür.
- `removeCar`: arabayı galeriden çıkarır ve çıkarılan `Car` nesnesinin referansını döndürür.
- İki `searchCar` metodu: biri aranan arabanın nesne referansını alır, galeride varsa `true`, yoksa `false` döndürür; öbürü plaka numarasını alır, araba varsa o arabanın referansını döndürür.
- `sellCar`: satılacak arabanın plakasını ve yeni sahibin referansını alır; işlem başarılıysa `true`, değilse `false` döndürür.
- `introduceSelf`: `Car` ve `Person` sınıflarındaki gibi nesneyi tanıtan bir metin üretir.

> **Ders sonrası not:** Hoca 00:29:18 civarında `addCar` için ağzından "arabayı çıkarır" (removing) dedi; bağlamdan ve koddan açıkça anlaşıldığı gibi `addCar` arabayı ekler.

> **Hocanın vurgusu:** Bu UML diyagramındaki ilişkilere ve ilişkilerdeki sayılara dikkat edilmelidir; hepsi doğru olmalıdır.

## 4. Gallery Sınıfının Kodu

Hoca kodu anlatırken her adımda UML diyagramına dönüp oradan koda geçti ve bunun izlenmesi gereken yol olduğunu söyledi.

> **Hocanın vurgusu:** Ara sınavda ve final sınavında buna benzer bir UML diyagramı verilecek ve belli bir sınıfın (örneğin `Gallery`) kodunu yazmanız istenecek. UML diyagramını inceleyip ondan Java kodunu yazabilmelisiniz.

### 4.1 Alanlar, Kurucu, Getter/Setter ve introduceSelf

UML'de alanların önünde `-` olduğu için dört alanın hepsi `private` tanımlanır. Kodun ilk bölümü şöyledir (ekrandan, 00:35:00):

```java
package nyp04;
public class Gallery {
        private String galleryName;
        private Car[] cars;
        private int carCount;
        private Person galleryOwner;

        public Gallery( String galleryName, Person galleryOwner ) {
            this.galleryName = galleryName; this.galleryOwner = galleryOwner;
            carCount = 0;
            cars = new Car[30];   // Note: No constructor is run here, this is
                                  // just a memory allocation for the array
        }
        public String getGalleryName() { return galleryName; }
        public void setGalleryName(String galleryName) {
           this.galleryName = galleryName;
        }
        public String introduceSelf( ) {
           String intro = "This is a car gallery named "+ galleryName;
           intro += ",  owned by " + galleryOwner.getName();
           intro += ". There are currently " + carCount + " cars to sell.";
           return intro;
        }
```

Kurucunun amacı bütün üye alanlara ilk değer vermektir. Kurucu galerinin adını parametre olarak alır ve üye alana atar. Yerel parametrenin adı üye alanın adıyla aynı olduğu için ikisini ayırmak gerekir; bu yüzden `this` anahtar sözcüğü kullanılır: `this.galleryName`, bu nesnenin üye alanı demektir. Sahip (`Person` türünde) de aynı biçimde `this.galleryOwner`'a atanır.

Galeri ilk oluşturulduğunda içinde araba yoktur; bu yüzden `carCount` 0 yapılır. Ardından 30 hücrelik bir dizi oluşturulup referansı `cars` değişkenine atanır. UML diyagramında galerinin kaç araba alabileceği yazmaz; sınavda bu bilgi soru metninde verilir.

`introduceSelf` metodu galerinin adını, sahibinin adını ve satılık araba sayısını bir metinde birleştirir.

### 4.2 Dizi Oluşturmak Nesne Oluşturmak Değildir

Hoca burada bir soru sordu: `Car` türünden dizi oluşturulduğunda `Car` nesneleri de oluşturulmuş olur mu? Cevap hayırdır. Yalnız bu nesneleri taşıyacak dizi oluşturulmuştur. Slayttaki not da bunu söyler: burada hiçbir kurucu çalışmaz, yalnız dizi için bellek ayrılır (ekrandan, 00:35:00).

Hoca bu noktanın önemli olduğunu söyleyip tahtada gösterdi. `new Car[30]` ile 30 hücreli bir dizi oluşturulduğunda bu dizinin fiziksel bellekte bir adres alanı olur. Dizinin bulunduğu yerin referansı `Car[]` türündeki `cars` değişkenine atanır. Ama dizinin içinde şu anda hiçbir nesne yoktur; bütün hücrelerin değeri `null`'dır, yani hiçbir nesneyi göstermezler.

### 4.3 addCar Metodu

UML'ye bakılarak metodun imzası yazılır: public bir metottur, `boolean` döndürür, adı `addCar`'dır ve `Car` türünde bir parametre alır. Ardından gövdeye geçilir (ekrandan, 00:45:00):

```java
public boolean addCar( Car aCar ) {
   if(!searchCar(aCar) && carCount < cars.length){
      cars[ carCount ] = aCar;
      carCount++;
      return true;
   }
   return false;
}//end addCar
//code of class Gallery will continue in
```

> **Ders sonrası not:** Hoca imzayı tanımlarken "metodun gövdesi ve argümanları birlikte imza (signature) olarak adlandırılır" dedi. Java'da imza, metodun adı ile parametre listesidir; gövde ve dönüş türü imzaya girmez. Hocanın bu derste sonradan verdiği overloading tanımı ("aynı ad, farklı parametreler, yani farklı imza") da bununla uyumludur.

Araba eklenebilir mi diye iki koşul denetlenir:

1. Araba zaten dizide olmamalıdır.
2. Dizide boş yer bulunmalıdır.

İkinci koşul için `cars.length` kullanılır. Bir dizinin `length` değeri o dizinin alabileceği en çok eleman sayısını verir; burada 30'dur. `carCount` ise galerideki araba sayısını tutan alandır; araba eklendikçe artırılır, çıkarıldıkça azaltılır. Böylece her zaman galerideki mevcut araba sayısını verir. `carCount < cars.length` denetimi eklenecek araba için yer olup olmadığını sınar.

Slayttaki kutuda şu açıklama vardır: dizinin boyutu bu yolla öğrenilebilir, ama dizinin eleman sayısı öğrenilemez. Bu yüzden `maxCar` gibi bir değişkene gerek yoktur, ama `carCount` gibi bir değişkene gerek vardır. Not olarak `public final static int maxCar = 30;` ve `private int carCount;` satırları verilmiştir (ekrandan, 00:45:00).

Birinci koşul için hoca UML diyagramına dönüp `searchCar` metotlarına baktı. Bu metotlar tam da arabanın galeride olup olmadığını denetler. `Car` nesnesi alıp `boolean` döndüren ilk `searchCar` burada işe yarar. Hoca bu metodun gövdesini henüz göstermemişti, ama giriş ve dönüş türüne bakarak ne yapacağının bilindiğini, bu yüzden kullanılabileceğini vurguladı.

Koşulun değerlendirilmesi:

- Araba galerideyse `searchCar` `true` döndürür. Başındaki `!` (değil) onu `false` yapar. `&&` işlecinde koşullardan biri `false` ise bütün koşul `false` olur, `if` gövdesi çalışmaz ve JVM `return false;` satırına geçer. Bu, arabanın zaten galeride olduğu anlamına gelir.
- Araba galeride değilse `searchCar` `false` döndürür, `!` ile `true` olur. Yer de varsa bütün koşul `true` olur ve `if` gövdesi çalışır.

Gövdede araba `carCount` indisli hücreye yazılır. Hoca bunu tahtada gösterdi: dizinin indisleri 0'dan başlar ve 30 hücreli dizide 29'a kadar gider. Başlangıçta `carCount` 0 olduğu için ilk boş hücre olan 0 indisli hücreyi gösterir. Yeni bir `Car` nesnesinin bellekteki adresi (referansı) bu hücreye yazılır; artık 0 indisli hücre bu nesneyi gösterir. Ardından `carCount` 0'dan 1'e artırılır ve `true` döndürülür. `return` çalışınca yürütme, `addCar`'ın çağrıldığı yere döner.

Slaytta sonraki adımlar için şu öneriler de vardır: eklenecek arabanın dizide zaten bulunup bulunmadığını başka bir metotla (`searchCar`) denetlemek akıllıcadır; bir araba nasıl satılır, `sellCar` metodu yazılmalıdır. Ayrıca "Alıştırma/Ödev: Para konularını da hesaba katmak gerekseydi ne olurdu?" sorusu sorulmuştur (ekrandan, 00:45:00).

### 4.4 İki searchCar Metodu ve İki Tür for Döngüsü

`searchCar` metotlarının kodu şöyledir (ekrandan, 00:50:00):

```java
public boolean searchCar( Car aCar ) {
    for( Car car : cars )
        if( car == aCar )
            return true;
    return false;
}
public Car searchCar( String plate ) {
    for( int i = 0; i < carCount; i++ )
        if( cars[i].getPlate().compareTo(plate) == 0 )
            return cars[i];
    return null;
}
```

Slaytta "`searchCar` metodunu da aşırı yükleyebilirsiniz (overload)" notu vardır: aynı adlı iki metot farklı parametre alır.

Hoca burada Java'daki iki tür for döngüsünü karşılaştırdı:

- **Klasik for döngüsü** üç bölümlüdür: başlangıç (döngü değişkenine ilk değer verilir), durma koşulu (her turun başında denetlenir; doğruysa gövde çalışır, değilse döngüden çıkılır) ve her turda döngü değişkenine uygulanan işlem (artırma, azaltma ya da başka bir işlem).
- **For-each döngüsü** bir veri yapısı üzerinde çalışır; burada veri yapısı dizidir. İleride bağlı liste (linked list), `ArrayList`, `HashMap` gibi veri yapıları da burada kullanılabilecektir. `for( Car car : cars )` her turda `cars` dizisinden bir nesneyi alıp yerel `car` değişkenine atar ve gövdeyi çalıştırır, sonra sıradaki nesneye geçer; eleman kalmayınca döngüden çıkılır.

İlk `searchCar`'da her turda dizideki nesnenin referansı aranan nesnenin referansıyla `==` ile karşılaştırılır. Eşitse `true` döndürülür; dizi bitip eşleşme bulunmazsa döngüden çıkılır ve `false` döndürülür.

İkinci `searchCar` arabayı plakayla arar. Bunun için dizideki her arabanın plakasına bakmak gerekir; hoca burada klasik for döngüsünü tercih etti. Döngü değişkeni 0'dan başlar ve mevcut araba sayısı olan `carCount`'a kadar artar. Her turda `cars[i]` nesnesinin `getPlate()` metodu çağrılır; dönen `String` üzerinde `compareTo` metodu çağrılarak metoda verilen plakayla karşılaştırılır. İki metin eşitse `compareTo` 0 döndürür ve o arabanın referansı döndürülür. Döngü eşleşme bulamadan biterse `null` döndürülür; bu, o plakada araba olmadığı anlamına gelir.

İki metodun farkı: ilki arabanın olup olmadığını `true`/`false` ile bildirir; ikincisi galerideki arabanın referansını, yoksa `null` değerini döndürür.

> **Ders sonrası not:** Bir öğrenci üstteki for-each döngüsünün bütün diziyi mi gezdiğini yoksa ilk `null` hücrede mi durduğunu sordu; hoca ilk `null` hücreye kadar döndüğünü, döngünün kaç nesne olduğunu kendi içinde izlediğini söyledi. Doğrusu: for-each dizinin bütün hücrelerini (burada 30 hücrenin hepsini) gezer; `null` hücrelerde `car == aCar` karşılaştırması yalnız `false` verir, hata oluşmaz. Bu ajan tarafından `java` ile denendi. Aynı denemede `searchCar(null)` çağrısının, boş hücreler `null` olduğu için `true` döndürdüğü de görüldü.

### 4.5 == ile compareTo Farkı

**Soru:** Metinleri karşılaştırmak için `compareTo` yerine yukarıdaki gibi `==` kullanılabilir mi?

**Cevap:** İki `String` nesnesi için de yapılabilir, denenebilir. Ama `String` sınıfının getirdiği `compareTo` metodu ek bir avantaj sağlar: metinleri sözlük sırasına (lexicographical order) göre karşılaştırır, yani hangisinin önce, hangisinin sonra geldiğini de söyler.

Hoca ardından sohbetten gelen bir yorumu okudu: `==` içeriğe değil, aynı adresi gösterip göstermediklerine bakar. Hoca bunu onayladı. `String` de, `new` ile oluşturulan bir `Car` da birer nesnedir ve referanslarıyla izlenir. `new` bellekte yaşayan bir nesne oluşturur; onu izlemek için kullanılan referans o nesnenin adres alanını gösterir. İki `String` nesnesi `==` ile karşılaştırılınca içeriklerine bakılmaz, adres alanlarının aynı olup olmadığına bakılır. `compareTo` ile ise metnin içeriğine girilir; içerikler aynı mı, biri öbüründen büyük mü küçük mü karşılaştırılabilir.

> **Ders sonrası not:** Hoca örnek olarak "biri A ile, biri T ile başlıyorsa, A öndeyse artı, T öndeyse eksi döndürür" dedi. İşaretler ters söylenmiştir: `"A...".compareTo("T...")` negatif, `"T...".compareTo("A...")` pozitif bir değer döndürür. `compareTo`, çağrıldığı metin sözlük sırasında önce geliyorsa negatif, sonra geliyorsa pozitif, eşitse 0 döndürür.

### 4.6 removeCar Metodu

UML'ye göre `removeCar` `String` (plaka) alır ve `Car` döndürür. Kod şöyledir (ekrandan, 01:05:00):

```java
public Car removeCar( String plate ) {
    for( int i = 0; i < carCount; i++ ) {
        if( cars[i].getPlate().compareTo(plate) == 0 ) {
            Car theCar = cars[i];
            for( int j = i; j < carCount; j++ )
                cars[j] = cars[j+1];
            cars[carCount-1] = null; carCount--;
            return theCar;
        }
    }
    return null;
}
```

Bütün diziyi değil, yalnız araba içeren hücreleri gezmek istendiği için döngü 0'dan `carCount`'a kadar gider. Döngüde her arabanın plakası metoda verilen plakayla `compareTo` ile karşılaştırılır; 0 dönerse o plakadaki araba dizidedir. Bu durumda:

1. O hücredeki arabanın referansı geçici `theCar` değişkenine alınır.
2. Bulunan indisten başlayıp `carCount`'a kadar giden ikinci bir for döngüsünde her hücreye bir sonraki hücredeki referans kopyalanır. Böylece referanslar birer sola kayar ve dizide boşluk kalmaz.
3. Döngüden sonra son dolu hücre `null` yapılır ve `carCount` bir azaltılır.
4. `theCar` döndürülür.

> **Ders sonrası not:** Hoca 01:06:59 civarında `carCount`'un artırıldığını söyledi; slayttaki kodda ve hocanın tahtadaki anlatımında `carCount--` vardır, yani azaltılır.

Hoca bunu tahtada iki arabalı bir dizi üzerinde anlattı. `carCount` iki anlamda kullanılır: indis olarak dizideki ilk `null` hücreyi gösterir, sayı olarak da dizideki araba sayısını verir. İki araba varken `carCount` 2'dir ve 2 indisli hücrede `null` vardır. Aranan araba 0 indisli hücrede bulunsun ve adresi örneğin `0x0A` olsun. Bu adres `theCar` değişkenine atanır; artık `theCar` bu nesneyi gösterir, ama dizideki referans henüz silinmemiştir. Kaydırma döngüsünde 1 indisli hücredeki referans 0 indisli hücreye yazılır, yani 0 indisli hücre artık ikinci arabayı gösterir. Döngüden sonra `carCount` 1'e düşer, `carCount` indisli (artık 1 olan) son hücreye `null` yazılır ve `theCar` döndürülür.

<!-- BELİRSİZ: Tahtadaki çizim karelerde görünmüyor; adres değeri ("DS, X0A" diye yazılmış) altyazıdan alındı ve 0x0A olarak yorumlandı. -->

**Soru:** Kaydırma döngüsünün sonunda `carCount`'tan bir önceki hücreye zaten `null` yazılmıyor mu? `j + 1` son turda `carCount`'u göstermiyor mu?

**Cevap:** Hoca önce döngüyü adım adım izledi: `carCount` 2 iken `j = 0` turunda 1. hücre 0. hücreye, `j = 1` turunda 2. hücre 1. hücreye kopyalanır; `j = 2` olunca koşul (`2 < 2`) sağlanmaz ve döngüden çıkılır. Sohbetten gelen bir yorum da 2. hücredeki değerin 1. hücreye kopyalandığını, yani 1. hücrenin son turda `null` aldığını hatırlattı. Hoca öğrencinin haklı olduğunu kabul etti: bu örnekte 2 indisli hücredeki `null` 1. hücreye zaten kopyalanmıştır. Yine de döngüden sonra `carCount` indisli hücreye `null` yazmak güvenli taraftır (to be on the safe side). Sonraki aramalarda ve eklemelerde ilk boş hücre `carCount` indisinin gösterdiği yer olmalıdır; yeni nesne oraya eklenir ve `carCount` bir ileri alınır.

> **Ders sonrası not:** Dizi tamamen doluyken (`carCount == 30`) kaydırma döngüsünün son turu `j = 29` olur ve `cars[30]` okunmaya çalışılır; bu `ArrayIndexOutOfBoundsException` fırlatır. Döngü sınırı `j < carCount - 1` yapılırsa sorun ortadan kalkar ve son hücreye `null` yazmak gerçekten gerekli hâle gelir. Bu durum derste konuşulmadı; ajan tarafından `java` ile denendi.

### 4.7 sellCar Metodu

Araba satılınca galeriden çıkarılmalıdır; satış bir kişiye yapıldığı için metot iki parametre alır: plaka ve yeni sahip (ekrandan, 01:05:00):

```java
public boolean sellCar( String plate, Person newOwner ) {
    Car soldCar = removeCar(plate);
    if( soldCar != null ) {
        soldCar.setOwner(newOwner);
        return true;
    }
    return false;
}
} //end class Gallery
```

`sellCar` arabayı çıkarmak için `removeCar` metodunu çağırır. `removeCar` çıkarılan arabanın referansını döndürür. Dönen değer `null` değilse araba bulunmuş ve çıkarılmıştır; bu durumda arabanın `setOwner` metoduyla yeni sahip atanır ve `true` döndürülür. `null` ise `removeCar` arabayı galeride bulamamıştır ve metot `false` döndürür.

> **Hocanın vurgusu:** Sınavda en çok zaman kaybı burada olur. Bir metodu yazarken başka bir metodu kullanmanız gerekecek. UML diyagramını okuyun: araba satılınca galeriden çıkarılmalıdır; bunu yapan bir metot var mı diye bakın. `removeCar` varsa `sellCar` içinde onu çağırın. `removeCar`'ın gövdesi sizden istenmemiş ya da gösterilmemiş olsa bile, sanki zaten yazılmış gibi kullanın; aynı kodu `sellCar` içinde sıfırdan yeniden yazmayın.

## 5. MainProgram04 ve main Metodu

Programı çalıştırmak için `main` metodu olan bir sınıf gerekir; UML'deki `MainProgram04` budur. Kodu şöyledir (ekrandan, 01:35:00). Slayttaki örnek kişi adı burada genel bir adla değiştirilmiştir:

```java
package nyp04;
public class MainProgram04 {
    public static void main(String[] args) {
        Gallery cars4U = new Gallery("Cars 4 U",
                 new Person("<sahip adı>"));
        Car bmw = new Car("34 RA 440", null);
        Car audi = new Car("06 AC 432",null);
        if( cars4U.addCar(bmw) ) {
            System.out.println("Adding operation succeded");
        }
        else { System.out.println("Adding operation failed"); }
        cars4U.addCar(audi);
        System.out.println(cars4U.introduceSelf());
        System.out.println(bmw.introduceSelf());
        if( cars4U.searchCar(bmw) == true ) {
            System.out.println("Search is successful");
        }
        else     System.out.println("Search has failed");
        if( cars4U.removeCar(audi.getPlate()) == audi )
            System.out.println("Remove operation succeeded");
        else     System.out.println("Remove operation failed");
        if( cars4U.searchCar(audi) == false )
            System.out.println("Last operation has correctly failed");
        else     System.out.println("Last operation has incorrectly succeeded");
    }
}
```

Adım adım:

1. Bir `Gallery` nesnesi oluşturulup `cars4U` değişkenine atanır. Kurucuya iki argüman verilir: bir `String` ve bir `Person` nesnesi. `Person` nesnesi argümanın içinde, yerinde `new` ile oluşturulmuştur. İstenirse bir satır önce oluşturulup geçici bir `Person` değişkenine atanabilir ve o değişken verilebilirdi. Hoca bu nesneyi bir daha kullanmayacağı için doğrudan argümanda oluşturmayı tercih etti.
2. İki `Car` nesnesi oluşturulur. Arabaların başlangıçta sahibi olmadığı için sahip parametresine `null` verilir.
3. `addCar(bmw)` çağrılır. Bu metot `Car` alıp `boolean` döndürdüğü için doğrudan `if` koşulunda kullanılabilir; başarılıysa ilk mesaj, değilse `else` dalındaki mesaj yazılır.
4. İkinci araba da eklenir; galerinin ve `bmw` arabasının `introduceSelf` metotları çağrılır.
5. `searchCar(bmw)` çağrılır. `bmw` daha önce eklendiği için `true` döner ve "Search is successful" yazılmalıdır.
6. `removeCar` çağrısına `audi` nesnesinin plakası `audi.getPlate()` ile verilir. `removeCar` çıkardığı arabanın referansını döndürür; bu referans `audi` referansına eşitse (aynı nesneyi gösteriyorsa) koşul doğrudur ve "Remove operation succeeded" yazılır.
7. Son olarak `audi` galeride yeniden aranır.

### 5.1 Son if Deyiminin Değerlendirilmesi

Hoca son `if` deyimini incelerken önce mesajlarda bir hata olabileceğini, iki deyimin yer değiştirmesi gerektiğini düşündü, sonra durumu Türkçe şöyle açıkladı: `audi` başarıyla çıkarıldıysa `searchCar(audi)` onu bulamaz ve `false` döndürür. `false == false` doğru olduğu için koşul `true` olur ve üstteki mesaj yazılır; yani çıkarma işlemi gerçekleşmiştir. `searchCar` arabayı bulursa `true == false` yanlış olur ve alttaki mesaj yazılır.

**Soru:** `searchCar` arabayı bulunca arabayı mı döndürüyor, `true` mu?

**Cevap:** İki `searchCar` vardı: biri `boolean`, öbürü `Car` döndürüyordu. Burada kullanılan, `Car` nesnesi alan ve bulursa `true`, bulamazsa `false` döndüren sürümdür. Araba çıkarıldıktan sonra aranınca `false` dönmelidir; `false == false` olduğu için koşul `true` olur.

**Soru:** O zaman `== false` kısmı kaldırılıp yalnız `searchCar` sonucu kullanılsa yetmez mi?

**Cevap:** Hoca bunun daha iyi olacağını kabul etti. Mesajların da "Last operation has correctly worked / has incorrectly worked" ya da "Last operation succeeded / has not succeeded" gibi daha açık biçimde yazılabileceğini söyledi.

> **Ders sonrası not:** Hoca deyimlerin yer değiştirmesi gerekebileceğini söyledi, ama slayttaki kod tutarlıdır: araba başarıyla çıkarıldıysa son arama "doğru biçimde başarısız olur" ve "Last operation has correctly failed" yazılır. Ajan, eksik `Person` ve `Car` sınıflarını UML'ye göre basitçe tamamlayarak programı `java` ile çalıştırdı; çıktılar sırasıyla "Adding operation succeded", galerinin tanıtım metni (2 araba), `bmw`'nin tanıtım metni, "Search is successful", "Remove operation succeeded" ve "Last operation has correctly failed" oldu. Öğrencinin önerdiği sadeleştirme `if( !cars4U.searchCar(audi) )` biçiminde yazılabilir.

## 6. Kalıtım (Inheritance)

Hoca ardından yeni bir nesne ilişkisine geçti: kalıtım. Kalıtım, bir nesnenin özelliklerinin başka bir nesneye geçmesi istendiğinde kullanılır. Bu ilişkide bir ebeveyn (parent) ve bir çocuk (child) vardır.

Slayttaki tanım şöyledir (ekrandan, 01:50:00):

- Gerçek dünyada çocuk genetik özelliklerini anne ve babasından alır.
- Nesneye yönelik programlamada kalıtım, var olan bir sınıftan gerçek dünyaya benzer biçimde yeni sınıflar oluşturmanın yoludur. Kalıtım aslında sınıf düzeyinde bir ilişkidir.
- Gösterim: `B` sınıfından `A` sınıfına, `A` ucunda içi boş üçgen bulunan bir ok çizilir. Okun yönüne dikkat edilmelidir: ok çocuktan ebeveyne gider.

| A (ebeveyn) | B (çocuk) |
|---|---|
| Parent class | Child class |
| Super class | Sub class |
| Base class | Derived class |

`B`, `A`'dan türetilmiştir; `A` sınıfının nesneleri `B` sınıfının nesnelerinin ebeveynidir.

### 6.1 Genelleme ve Özelleştirme

Kalıtım, sınıflar arasında genelleme-özelleştirme (generalization-specialization) ilişkisi olduğunda kullanılır. Bazı sınıflar daha kapsayıcı (genel), bazıları daha özeldir. Özel sınıflarda, genel sınıfta bulunmaması gereken, yalnız o özel türe ait metotlar bulunur.

Slayttaki örnekler (ekrandan, 01:45:00):

- `Car` ebeveyn; `StationWagon`, `Racing` ve `Jeep` çocuk.
- `Printer` ebeveyn; `DotMatrix`, `Laser` ve `InkJet` çocuk.

Slayta göre kalıtım genelleme-özelleştirme ilişkisi olarak da adlandırılır: çocuk ebeveynin özelleşmiş ve daha yetenekli hâlidir; ebeveyn de çocuklarının daha az yetenekli, genelleştirilmiş hâlidir.

Hoca kalıtımın avantajını yazıcı örneğiyle anlattı. `Printer` sınıfında dört metot olsun; alt sınıfların her birinde de yalnız kendisine özel birer ek metot bulunsun. Kalıtım kullanılmasaydı ortak dört metot her alt sınıfa ayrı ayrı yazılacaktı. Kalıtımla bu dört metot genel sınıfa bir kez yazılır, alt sınıflar onları miras alır ve her alt sınıfa yalnız kendi özel metodu yazılır. Böylece daha az kod yazılır.

### 6.2 IS-A İlişkisi ve Yerine Konabilirlik

Kalıtım bir IS-A ("bir ... dır") ilişkisidir: `DotMatrix` sınıfının bir nesnesi aynı zamanda bir `Printer` nesnesidir. Slayta göre yerine konabilirlik (substitutability) ilkesi şudur: ebeveynin beklendiği her yerde çocuk kullanılabilir; bu yüzden kalıtıma IS-A ilişkisi de denir (ekrandan, 01:45:00).

Bu yüzden `DotMatrix` türünden oluşturulan bir nesne hem `DotMatrix` hem `Printer` türünden bir değişkenle izlenebilir. Aynı biçimde bir `Jeep` nesnesi hem `Jeep` hem `Car` türünden bir referansla tutulabilir. `Car` türünden bir değişken tanımlandığında ona yalnız `Car` nesnesi değil, `Car`'ın bir çocuğunun nesnesi de atanabilir.

### 6.3 Kalıtım Nasıl Çalışır

Slayta göre (ekrandan, 01:50:00):

- Ebeveynin bütün üye alanları ve metotları çocuğa aktarılır. Çocuk nesnesi yalnız metotları değil, üye alanları da miras alır.
- Ancak çocuk, miras aldığı private üyelere doğrudan erişemez. Ebeveynde private bir alan varsa çocuk o alanı miras alır, ama ona erişmek için ebeveynin public metotlarından birini kullanmalıdır.
- Protected üyeler (alan ya da metot) çocuklar tarafından erişilebilir, ama başka sınıflar tarafından erişilemez.

Hoca bunu Türkçe şöyle özetledi: başka sınıfların nesneleri için protected ile private aynı şeydir; ikisini de göremezler. Çocuk sınıf ise ebeveynin protected üyelerini görebilir, private üyelerini göremez.

## 7. Kalıtımın Kuralları ve Kalıtım Ağacı

Slayttaki kurallar şöyledir (ekrandan, 01:55:00):

- Alt sınıf üst sınıftan gelen bir üyeyi reddedemez; çocuk ebeveynden gelen her şeyi miras alır.
- Miras alınan metotların gövdesi değiştirilebilir. Buna **overriding** (geçersiz kılma) denir. Örneğin `Printer` sınıfında bir `print` metodu varsa `Laser` sınıfında da bir `print` metodu yazılabilir; `Laser` nesnesinin `print` metodu çağrıldığında `Laser`'daki sürüm çalışır.
- Dikkat: `final` metotlar override edilemez. Daha önce `final` anahtar sözcüğünün yalnız alanlarda değil metotlarda da kullanılabileceği söylenmişti; metot `final` ise çocuk sınıfta yeniden yazılamaz.
- Alt sınıflara yeni üyeler eklenebilir. Örneğin `Student`, `Person`'dan türer. `Person`'da genel bir kimlik olan vatandaşlık numarası bulunur; öğrencinin ayrıca öğrenci numarası vardır. Her kişinin öğrenci numarası olmayabileceği için bu alan ve onun `getStudentID`, `setStudentID` gibi metotları `Person`'a değil `Student`'a konur.
- Bir alt sınıf başka sınıfların ebeveyni olabilir. Bu biçimde oluşan ağaç yapısına kalıtım hiyerarşisi ya da kalıtım ağacı (inheritance tree) denir.

Slayttaki ağaç örneği:

```text
Person
├── Student
├── Employee
│   ├── Director
│   └── PartTime
└── Retired
```

Slayta göre ağaç çok derin yapılmamalıdır (ekrandan, 01:55:00):

- Derin ağaç kırılgan üst sınıf (fragile super class) sorununa yol açar.
- En üstteki sınıf değiştirildiğinde bu değişiklik bütün alt sınıfları etkiler.
- Bu, kökü çürük bir ağaca benzer; rüzgârla kolayca devrilebilir.

Hoca örnekteki ağacın üç düzeyli olduğunu, ama on düzeyli bir ağacın programcı için yönetilmesinin zorlaşacağını söyledi; ebeveynlerden biri değişince birçok çocuk sınıf etkilenir.

## 8. Doğru Kalıtım Modellemesi

Kalıtım kullanılırken her zaman sınıflar arasında IS-A ilişkisi olup olmadığı sorulmalıdır.

Hoca yanlış bir kalıtım ağacı örneği gösterdi: `GUIButton` (grafik kullanıcı arayüzü düğmesi) ebeveyn, kırmızı, sarı ve mor renkler çocuk olarak modellenmiştir. "Kırmızı bir GUI düğmesidir" önermesi doğru değildir. Renkler GUI düğmesinin özellikleridir, düğmenin kendisi değildir; burada IS-A ilişkisi yoktur ve bu modelleme yanlıştır.

Doğru modellemede ebeveyn `GUIButton`, çocuk ise sıradan bir GUI düğmesidir (regular GUI button); bu da bir GUI düğmesi olduğu için kalıtım uygundur. Renk ise bir özellik (alan) olarak tutulur ve herhangi bir renk kullanılabilir.

<!-- BELİRSİZ: GUI düğmesi slaytı karelerde görünmüyor; sınıf adları ve doğru modelin yapısı yalnız altyazıdan alındı. -->

Slayttaki kalıtım değerlendirmesi şöyledir (ekrandan, 02:00:00):

- Kalıtım, çalışma sırasında değiştirilemeyen sınıf düzeyinde bir ilişkidir. Bu yüzden program modellenirken doğru kurulmasına dikkat edilmelidir.
- Deneyimli nesneye yönelik modelleyiciler kalıtımı yalnız açık bir genelleme-özelleştirme ilişkisi varsa seçer. Yoksa association, composition ya da aggregation kullanılır.
- Alternatif olarak arayüz gerçekleştirme (interface implementation) de kullanılabilir (ileride işlenecek).
- Kalıtımın doğru kullanımı, nesne yönelimini tamamen öğrendikten sonra yazılım profesyoneli olmak isteyenlerin çalışması gereken her tasarım kalıbının (design pattern) önemli bir parçasıdır.

## 9. Çok Biçimlilik (Polymorphism) ve super

Kalıtım, nesneye yönelik programlamada çok biçimlilik (polymorphism) adı verilen güzel bir avantaj sağlar.

Slayttaki örnekte (ekrandan, 02:05:00) `Person` ebeveyndir ve `+ introduceSelf( ) : String` metodu vardır. `Student`, `Employee` ve `Retired` bu sınıftan türer ve her biri `introduceSelf` metodunu override eder.

`Person` türünden bir dizi oluşturulsun. Bu diziye `Person` sınıfından oluşturulmuş nesneler konabilir. Ebeveynin beklendiği yerde çocuk kullanılabildiği için `Student`, `Employee` ve `Retired` nesneleri de konabilir. Böylece aynı dizide dört farklı türden nesne bulunur.

Dizi üzerinde döngü kurulup her nesnenin `introduceSelf` metodu çağrılsın. `Person` nesnesi için `Person`'daki sürüm, `Student` nesnesi için `Student`'ın override ettiği sürüm, `Employee` için `Employee`'nin, `Retired` için `Retired`'ın sürümü çalışır. Hepsi aynı dizide aynı türden (`Person`) görünse de çalışma sırasında farklı davranırlar. Slayta göre çalışma zamanında `introduceSelf` metodunun doğru sürümü yürütülür ve bu mekanizmaya **polymorphism** denir.

Hoca bunu Türkçe "çeşitlilik, çeşitli davranış" diye özetledi: aynı türdeki nesnelerin aynı metot için farklı davranışları kalıtımla gerçekleştirilebilir; yani kalıtımla çok biçimlilik elde edilir.

### 9.1 super ile Ebeveyn Sürümüne Erişim

Slayttaki soru şudur: override edilmiş bir metodun üst sınıfta yazıldığı biçimdeki önceki sürümüne erişmek gerekirse ne yapılır? Cevap: o metoda `super` işaretçisiyle erişilir (ekrandan, 02:05:00).

`Student` sınıfında `introduceSelf` doğrudan çağrılırsa `Student`'taki sürüm çalışır. Ebeveynin `introduceSelf` metodu çalıştırılmak istenirse `super` anahtar sözcüğü kullanılır. Daha önce `this`, geçerli sınıfın nesnesini göstermek için kullanılmıştı; `super` ise ebeveyn sınıfın nesnesini (nesnenin ebeveyn kısmını) gösterir.

## 10. Person, Employee, Manager Örneği

### 10.1 UML Diyagramı

Slayttaki UML sınıf şeması bir kalıtım ağacından (`Person` – `Employee` – `Manager`) ve bunları kullanan bir sınıftan (`Company`) oluşur (ekrandan, 02:15:00):

| Sınıf | Üye alanlar | Üye metotlar | Ebeveyn |
|---|---|---|---|
| `Person` | `- name : String` | `+ Person( String )`, `+ getName( ) : String` | — |
| `Employee` | `- salary : int` | `+ Employee( name: String, salary: int )`, `+ getSalary( ) : int`, `+ setSalary( int )` | `Person` |
| `Manager` | `- bonus : int` | `+ Manager( name: String, salary: int )`, `+ setBonus( int )`, `+ getSalary( ) : int` | `Employee` |
| `Company` | (yok) | `+ main( String[] )` | — |

`Company` sınıfından `Employee` ve `Manager` sınıflarına kesikli oklar (dependency) çizilmiştir, çünkü `main` metodunda bu iki sınıf kullanılır.

Hoca burada "extends" sözcüğünü tanıttı: kalıtım ilişkisinde "türetilir" yerine "genişletir" (extends) denir; `Employee extends Person`. Bu sözcük ders boyunca kullanılacaktır.

`Employee` bir ek alan (`salary`) tanımlar, ama `name` alanını da miras alır. Bir `Employee` nesnesi oluşturulduğunda içinde hem `name` hem `salary` bulunur. `Employee`'de üç metot vardır: iki parametreli kurucu ve `salary` için getter ile setter.

`Manager` ise `Employee`'yi genişletir ve ek olarak `bonus` alanını tanımlar. Üç metodu vardır: iki parametreli kurucu, `bonus` için setter ve `getSalary`. `getSalary` `Employee`'de de bulunduğu için `Manager`'daki sürüm ebeveyninkini override eder. Diyagramda `Manager`'da `getName` ve `setSalary` görünmez; `getName` `Person`'dan, `setSalary` `Employee`'den miras alınır. Aynı biçimde `name` ve `salary` alanları da diyagramda görünmese de `Manager` nesnesinde bulunur.

> **Hocanın vurgusu:** Çocuk sınıfta görmeseniz bile miras alınan alanların ve metotların orada olduğunu bilmelisiniz.

### 10.2 Person ve Employee Kodu

Kod şöyledir (ekrandan, 02:10:00):

```java
package nyp05;
public class Person {
        private String name;
        public Person( String name ) { this.name = name; }
        public String getName( ) { return name; }
}
```

```java
package nyp05;
public class Employee extends Person {
        private int salary;
        public Employee( String name, int salary ) {
                super( name );          // super'in önemli rolüne dikkat
                this.salary = salary;
        }
        public int getSalary( ) { return salary; }
        public void setSalary( int salary ) { this.salary = salary; }
}
```

`Person` şimdiye kadar öğrenilen sınıf yazımıyla aynıdır: tek bir private alan, bu alanı başlatan bir kurucu ve `String` döndüren `getName`.

`Employee` sınıfının tanımında `extends` anahtar sözcüğü kullanılır. Kurucu iki parametre alır: `name` ve `salary`. Kurucunun ilk satırındaki `super( name );` ebeveynin (`Person`) kurucusunu çağırır ve `name` değerini ebeveynin üye alanına atar. Çocuk sınıf ebeveynin bütün alanlarını miras aldığı için ebeveynin alanlarının da başlatılması gerekir; bu, ebeveyn kurucusu çağrılarak yapılır. Ardından geçerli nesnenin kendi alanı olan `salary` atanır.

### 10.3 Manager Kodu

`Manager` sınıfı `Employee`'yi genişletir. Altyazıya göre `bonus` adlı private bir `int` alanı vardır. İki parametreli (`String` ve `int`) kurucu önce `super` ile ebeveynin iki parametreli kurucusunu çağırır (`name` ve `salary` verilir), sonra `bonus` alanına 0 atar. Bunun yanında `bonus` için bir setter ve `getSalary` metodu vardır.

`getSalary`'nin gövdesinde yönetici, çalışanla aynı maaş hesabına sahip olduğu için önce ebeveynin `getSalary` metodu çağrılır. `Manager`'da da bir `getSalary` bulunduğundan ebeveynin sürümü `super.getSalary()` biçiminde çağrılır. Ardından yöneticiye özel `bonus` eklenir.

Altyazıdaki anlatıma göre kod şu biçimdedir:

```java
public class Manager extends Employee {
        private int bonus;
        public Manager( String name, int salary ) {
                super( name, salary );
                bonus = 0;
        }
        public void setBonus( int bonus ) { this.bonus = bonus; }
        public int getSalary( ) { return super.getSalary( ) + bonus; }
}
```

<!-- BELİRSİZ: Manager kodunun slaytı karelerde görünmüyor; kod altyazıdaki anlatımdan kuruldu, slayttaki yazımı farklı olabilir. -->

Böylece `super`'in iki kullanımı görülmüş olur: ebeveynin kurucusunu çağırmak (`super(...)`) ve ebeveynin bir metodunu çağırmak (`super.getSalary()`).

`super` yalnız bir kez kullanılabilir; `super.super` yazılamaz. Bir sınıfın nesneleri yalnız kendi ebeveynine `super` ile erişebilir, ebeveynin ebeveynine doğrudan erişemez. Ebeveynin ebeveynine ulaşmak gerekiyorsa önce ebeveyn sınıfta, kendi ebeveyninin metoduna erişen bir metot bulunmalıdır; çocuk sınıf bu metodu kullanarak dolaylı yoldan ulaşır.

### 10.4 Company Sınıfı

Örneği çalıştıran `Company` sınıfı şöyledir (ekrandan, 02:20:00):

```java
package nyp05;
public class Company {
    public static void main(String[] args) {
       Employee[] staff = new Employee[3];
       Manager boss = new Manager("Manager", 8000 );
       boss.setBonus( 2500 );
       staff[0] = boss;
       staff[1] = new Employee("Employee1", 7500 );
       staff[2] = new Employee("Employee2", 7000 );
       for( Employee author : staff )
           System.out.println( author.getName() + " " +
              author.getSalary( ) );
    }
}
```

Slaytın altında "for döngüsünün sözdizimini fark ettiniz mi?" sorusu vardır; burada for-each döngüsü kullanılmıştır.

`main` metodunda üç elemanlı `Employee` türünden bir dizi oluşturulur. Önce bir `Manager` nesnesi oluşturulur, `setBonus` ile bonusu atanır ve dizinin ilk hücresine konur. Dizi `Employee` dizisidir; ilk hücrede bir `Employee` nesnesi beklenir. Ebeveynin beklendiği yerde çocuk kullanılabildiği için `Manager` nesnesi de bu hücreye atanabilir. Ardından iki `Employee` nesnesi oluşturulup diğer hücrelere konur.

For-each döngüsünde dizideki her nesne `Employee` türündeki yerel `author` değişkenine atanır. `getName` çağrısı her çalışanın adını, yönetici için de yöneticinin adını yazar. `getSalary` çağrıldığında `Manager` nesnesi için `Manager`'daki sürüm, `Employee` nesneleri için `Employee`'deki sürüm çalışır. Bu, çok biçimliliktir.

Programın çıktısı şöyledir (derste yazdırılmadı; ajan tarafından `java` ile çalıştırıldı, `Manager` sınıfı yukarıdaki biçimiyle):

```text
Manager 10500
Employee1 7500
Employee2 7000
```

İlk satırdaki $8000 + 2500 = 10500$ değeri, `staff[0]` `Employee` türünden bir referans olsa da `Manager`'ın `getSalary` sürümünün çalıştığını gösterir.

## 11. Company Sınıfının Ardışık Diyagramı

Hoca ikinci aradan sonra `main` metodunun UML ardışık (sequence) diyagramını anlattı.

- Diyagramda `main` metodunu içeren sınıf `Company`'dir. Dersin başında söylendiği gibi `java` komutuna bir sınıf adı verildiğinde Java sanal makinesi o sınıftaki `main` metodunu çalıştırır; bu yüzden `main`'i çağıran Java sanal makinesidir.
- `main` önce `Employee` dizisini oluşturur.
- Ardından ilk nesne olan `Manager` nesnesi oluşturulur ve onun `setBonus` metodu çağrılır.
- Oluşturulan nesne dizinin ilk hücresine atanır. Diziye atama diyagramda "add" mesajıyla gösterilir; hoca sınavda da böyle gösterilebileceğini söyledi.
- Sonra bir `Employee` nesnesi oluşturulup dizinin ikinci hücresine, bir başka `Employee` nesnesi oluşturulup üçüncü hücresine eklenir.
- Son olarak dizi üzerinde for-each döngüsüyle `getName` ve `getSalary` çağrılır. Bu mesajların önünde `*` işareti vardır; bu, mesajın bir kereden çok (döngüde) gönderildiğini gösterir.

<!-- BELİRSİZ: Ardışık diyagram slaytı karelerde görünmüyor; diyagramdaki nesne adları ve mesaj etiketleri yalnız altyazıdan alındı. -->

> **Hocanın vurgusu:** Bunu çalışmalısınız; sınavda bu türden bir soru (bir `main` metodunun ardışık diyagramı) beklemelisiniz.

## 12. Overloading ve Overriding, Private Metotlar

Slayttaki açıklama şöyledir (ekrandan, 02:35:00):

- Overriding ile overloading karıştırılmamalıdır.
- **Override:** miras alınan metodun gövdesini değiştirmek. Overriding kalıtımla yakından ilgilidir.
- **Overload:** aynı adlı ama farklı parametreli birden çok metoda sahip olmak. Overloading kalıtımla ilgili değildir.
- Overriding örneği: `Manager` sınıfındaki `getSalary` metodu.
- Overloading örneği: `Manager` sınıfının kurucusu, şu kurucu eklenerek aşırı yüklenir:

```java
public Manager( String name, int salary, int bonus ) {
       super( name, salary );
       this.bonus = bonus;
}
```

- Artık `Manager` sınıfının iki kurucusu vardır.
- Not: üst sınıfın private metotları alt sınıflarda override edilebilir. Ancak alt sınıf metodun özgün sürümüne hiçbir yolla, örneğin `super` anahtar sözcüğüyle bile erişemez.

Hoca ayrımı şöyle özetledi: overloading, bir sınıfta aynı adlı ama imzası farklı birden çok metodun bulunmasıdır ve aynı sınıf içinde olur. Overriding ise ebeveynin bir metodunun çocuk sınıfta aynı imzayla yeniden yazılmasıdır. Bu derste `Manager`'daki `getSalary`, `Employee`'dekini override etmiştir; `Manager`'a ad, maaş ve bonusu alan üç parametreli ikinci bir kurucu eklemek ise overloading olur.

Hoca ardından private metotlara değindi. Şimdiye kadar alanlar genelde private, metotlar genelde public yazıldı. Ama bazen bir metodun başka nesnelerce görülmemesi istenir; o zaman metot private tanımlanır. Hocaya göre üst sınıfta private bir metot varsa çocuk sınıfta aynı adlı bir metot yazılabilir, ama çocuk sınıfın nesneleri ebeveynin private metoduna hiçbir yolla, `super` ile bile erişemez. Private alan ya da metot yalnız ebeveyn sınıfın içinde kullanılabilir.

> **Ders sonrası not:** Slayt ve hoca private metotların override edilebileceğini söyledi. Java'da private metotlar override edilmez: alt sınıfta aynı adla yazılan metot, üst sınıftakinden bağımsız yeni bir metottur. Üst sınıfın kendi içinden bu metoda yapılan çağrılar alt sınıftaki sürüme değil, yine üst sınıftaki private sürüme gider; yani çok biçimlilik oluşmaz. Ajan bunu `java` ile denedi: üst sınıfın public bir metodu kendi private `f()` metodunu çağırdığında, alt sınıfta `f()` yazılmış olsa da üst sınıftaki `f()` çalıştı. Slaytın erişimle ilgili kısmı ise doğrudur.

## 13. Protected ve super Üzerine Soru-Cevap

**Soru:** `super` kullanmak yerine değişkenler ya da metotlar protected tanımlansa olmaz mı? Neden `super` kullanmak zorundayız?

**Cevap:** Hoca önce protected'ın ne yaptığını açıkladı. Program yazılırken her zaman kalıtım kullanılmaz; önce iki sınıf arasında association, sonra eklenen üçüncü bir sınıfla composition gibi ilişkiler kurulur. Erişim belirlenirken genel kural, üye alanları private, metotları public tanımlamaktır. Kalıtım ilişkisi kurulacağından kesin olarak eminse alanlar protected tanımlanabilir; o zaman alanlara yalnız ebeveyn sınıf değil, çocuk sınıf ve onun nesneleri de doğrudan erişebilir.

Metotlar da protected tanımlanabilir, ama bu durumda başka sınıfların nesneleri bu metotlara ulaşamaz, onları göremez bile. Oysa nesnelerin birbirleriyle konuşarak iş yapması istendiği için metotlar genelde public tanımlanır; böylece başka sınıfların nesneleri ebeveyn ya da çocuk sınıfın metotlarını görüp çağırabilir.

Bazı metotların ise başka sınıflarca çağrılmaması gerektiğinden emin olunur. Bunlar yardımcı (utility) metotlardır: sınıfın kendi gerçekleştiriminde kullanılır, ama dış dünyaya açılmaz. Hoca araba benzetmesini hatırlattı: gaza basmak, vites değiştirmek, frene basmak, kapıyı açmak aracın dış dünyaya açtığı özelliklerdir. Aracın içinde ise su seviyesini ya da yakıt seviyesini denetleyen işlevler vardır. Bunlar private metotlar olarak tanımlanabilir ve public metotlar işlerini yaparken bu private metotları çağırabilir. Bu yardımcı metotların alt sınıflarda da kullanılması isteniyorsa protected tanımlanır; yine başka sınıfların nesnelerince görülmez.

Özetle, kalıtım kullanılacağı kesinse alanlar protected da private da tanımlanabilir; ikisi de alanların başka sınıfların nesnelerince değiştirilmesini önler. Protected tanımlandığında alt sınıflar üstteki alanlara kendi alanlarıymış gibi doğrudan erişip onları değiştirebilir; ilişkileri kuran ve çocuk sınıfları yazan da aynı programcı olduğu için bunda sorun yoktur. Alanlar ise gerçekten özel bir durum yoksa hiçbir zaman public tanımlanmaz.

`super` gereksinimi için hoca şu örneği verdi. Genellemede bütün alt sınıfların kullanacağı alanlar genel sınıfta toplanır; örnekteki `name` alanı hem `Employee`'de hem `Manager`'da gerektiği için ebeveyne taşınır. Bu alan için `getName` ve `setName` metotları olsun. Alt sınıfta `getName` metodu, adın başına "Employee" ön ekini koyacak biçimde yeniden yazılmış olsun. Aynı kodda bir yerde ön eksiz, yani üstteki `getName` sürümüne de ihtiyaç doğabilir. Hem alttaki hem üstteki sürümün gerektiği bu durumda üstteki sürüm `super` ile çağrılır. Ayrıca kurucuda `name` alanını başlatmak için üstteki kurucu da `super` ile çağrılır.

## 14. Gereksinim Metninden UML: Hasta ve Doktor

Hoca sınavda verilebilecek türden bir metinle iki modellemeyi karşılaştırdı. Slayttaki gereksinim metni şöyledir (ekrandan, 02:50:00):

> We should keep track of the patients' names, TC ID numbers, birth dates and cell numbers. This information should be stored for doctors, too. In addition, it is required by law to keep the diploma numbers of doctors. We should keep records of treatments applied to a patient, too.

Metin cümle cümle okunarak sınıflar çıkarılır:

1. "Hastaların adları, TC kimlik numaraları, doğum tarihleri ve cep telefonu numaraları tutulmalı" cümlesinden bir hasta (`Patient`) sınıfı çıkar.
2. "Bu bilgiler doktorlar için de tutulmalı" cümlesinden bir doktor (`Doctor`) sınıfı çıkar.
3. "Yasa gereği doktorların diploma numaraları da tutulmalı" cümlesi, `Doctor` sınıfında diploma numarası alanı olması gerektiğini söyler.
4. "Hastalara uygulanan tedavilerin kayıtları da tutulmalı" cümlesinden bir tedavi (`Treatment`) sınıfı çıkar.

**Yanlış modelleme:**

- `Patient`: `- name, TCID, cellNr : String`, `- birth : Date`, `- treatments : Treatment[]`.
- `Patient` 1 — * `Treatment` association.
- `Doctor` (`- diplomaNr : String`) `Patient`'ten türetilmiş; slaytta "kalıtımın yanlış kullanımı" notu vardır.

Hasta ile tedavi arasındaki ilişki doğrudur: bir hastanın sıfır ya da daha çok tedavisi olabilir. Ama `Doctor extends Patient`, "doktor bir hastadır" demektir ve bu doğru değildir. Her doktor hasta değildir; bazı doktorlar hastalanıp hastanede hasta olabilir, ama bütün doktorlar hasta değildir. Slayttaki açıklamaya göre tedaviler hastalara aittir, doktorlara değil; yanlış modelde kalıtım yüzünden `treatments` dizisi doktorlara da geçer.

**Doğru modelleme:**

Metin yeniden okununca hastalarla doktorların ortak bilgileri olduğu görülür: ad, kimlik numarası, cep telefonu numarası ve doğum tarihi. Ortak bilgi görüldüğünde kalıtım akla gelmelidir. Bu ortak bilgiler yeni bir sınıfta toplanır:

| Sınıf | Üye alanlar | Ebeveyn |
|---|---|---|
| `Person` | `- name, TCID, cellNr : String`, `- birth : Date` | — |
| `Doctor` | `- diplomaNr : String` | `Person` |
| `Patient` | `- treatments : Treatment[]` | `Person` |
| `Treatment` | (gösterilmemiş) | — |

`Patient` ile `Treatment` arasında `Patient` ucunda `1`, `Treatment` ucunda `*` olan bir association vardır. Artık her doktor bir kişidir, her hasta bir kişidir; bu doğru modellemedir.

> **Hocanın vurgusu:** Sınavda böyle bir metin verip ondan UML diyagramı çizmenizi isteyebilirim. Ara sınava ve finale hazırlanmanın yolu şudur: bir metinden başlayıp UML sınıf diyagramını çıkarın, diyagramdan her sınıfın ve `main` sınıfının kodunu yazın, sonra yazdığınız `main` metodunun ardışık diyagramını çizin. Bunların hepsini yaparsanız sınava iyi hazırlanmış olursunuz.

## 15. java.lang.Object ve Date Sınıfı

Java'da her sınıf, `java.lang.Object` adlı bir üst sınıftan türer. Bu örtük (implicit) bir üst sınıftır; yani Java'da `java.lang.Object` bütün sınıfların atasıdır. Bu yüzden `java.lang.Object` sınıfına ait her metot, yazılan sınıflarda override edilebilir.

Genellikle `toString` metodu override edilir ve içine istenen yazılır. Örneğin şimdiye kadar `introduceSelf` metotlarında yazılanlar `toString` içine yazılabilir; bu, `Object`'in `toString` metodunu geçersiz kılar.

Hoca derse burada son verdi ve kalıtımın bir başka gerçekleştirme yolu olan soyut sınıfların (abstract classes) sonraki derste işleneceğini söyledi. Şimdiye kadar kalıtım sıradan sınıflarla gerçekleştirildi.

**Soru:** Önceki UML diyagramındaki `Date` bir sınıf mı, yoksa bir veri tutma biçimi mi? `Person` doğum tarihini `birth : Date` olarak tutuyor.

**Cevap:** `Date` bir sınıftır. Daha önce öğrenilen `Random`, `Math` ve `String` sınıfları gibi kullanılan sınıflardan biridir ve `java.util` paketindedir. `birth` alanı `Date` sınıfı türünden bir değişkendir. `Date` sınıfı ilerideki örneklerde daha çok kullanılacaktır; tarih gün, yıl ya da zaman olarak alınabilir. `Date` sınıfının metotlarının da öğrenilmesi gerekir.

> **Ek bilgi (derste anlatılmadı):** `toString` metodu, bir nesne `System.out.println(nesne)` ile yazdırıldığında ya da `"metin" + nesne` biçiminde bir metne eklendiğinde otomatik olarak çağrılır. Override edilmezse `Object`'teki sürüm sınıf adını ve bir karma (hash) değerini yazdırır. Override ederken `public String toString()` imzası birebir korunmalıdır; `@Override` işareti eklemek imza hatalarını derleme anında yakalar.

## Örnek Sorular

**1. (derste sözlü, 00:36:26)** `Gallery` kurucusunda `cars = new Car[30];` çalıştırıldığında `Car` nesneleri de oluşturulmuş olur mu?

> **Cevap (derste verildi):** Hayır. Yalnız 30 tane `Car` referansı tutacak dizi için bellek ayrılır ve hiçbir `Car` kurucusu çalışmaz. Dizinin bütün hücreleri `null`'dır; `Car` nesneleri ayrıca `new Car(...)` ile oluşturulup diziye eklenir.

**2. (derste sözlü, 00:58:07)** `searchCar(Car aCar)` metodundaki for-each döngüsü bütün diziyi mi gezer, yoksa ilk `null` hücrede mi durur?

> **Cevap (derste verildi, düzeltilerek):** Hoca ilk `null` hücrede durduğunu söyledi. Doğrusu: for-each dizinin bütün hücrelerini gezer (burada 30 hücre); `null` hücrelerde `car == aCar` yalnız `false` verir. Bu ajan tarafından `java` ile denendi.

**3. (derste sözlü, 00:58:53)** `String`'leri karşılaştırmak için `compareTo` yerine `==` kullanılabilir mi?

> **Cevap (derste verildi):** `==` iki referansın aynı nesneyi (aynı adresi) gösterip göstermediğine bakar, içeriğe bakmaz. `compareTo` ise içeriği sözlük sırasına göre karşılaştırır: eşitse 0, çağrıldığı metin önce geliyorsa negatif, sonra geliyorsa pozitif bir değer döndürür. Plaka gibi içerik karşılaştırmalarında `compareTo` (ya da `equals`) kullanılmalıdır.

**4. (derste sözlü, 01:11:23)** `removeCar` metodunda kaydırma döngüsünün son turu `carCount - 1` hücresine zaten `null` kopyalamıyor mu? Döngüden sonra ayrıca `cars[carCount-1] = null;` yazmak neden gerekli?

> **Cevap (derste verildi):** Dizi dolu değilken son turda `cars[carCount]` hücresindeki `null` gerçekten `carCount - 1` hücresine kopyalanır; öğrenci bu konuda haklıdır. Hoca yine de döngüden sonra o hücreye `null` yazmanın güvenli taraf olduğunu, çünkü bir sonraki eklemenin `carCount` indisine yapılacağını ve o hücrenin boş olması gerektiğini söyledi.
>
> **Ders sonrası not:** Dizi doluyken (`carCount == 30`) son turda `cars[30]` okunur ve `ArrayIndexOutOfBoundsException` oluşur (ajan `java` ile denedi). Döngü `for( int j = i; j < carCount - 1; j++ )` yazılırsa hata kalkar; o zaman döngüden sonraki `cars[carCount-1] = null;` satırı da gerçekten gerekli olur.

**5. (derste sözlü, 01:41:26)** `MainProgram04`'teki `if( cars4U.searchCar(audi) == false )` koşulunda `== false` kaldırılsa yeterli olmaz mı?

> **Cevap (derste verildi):** Hoca bunun daha iyi olacağını kabul etti ve mesajların da daha açık yazılabileceğini söyledi. Koşul `if( !cars4U.searchCar(audi) )` biçiminde sadeleştirilebilir; araba başarıyla çıkarıldıysa arama `false` döndürür ve koşul doğru olur.

**6. (ekrandan, 00:45:00)** Alıştırma/Ödev: Galeri örneğinde para konularını da hesaba katmak gerekseydi ne olurdu?

> **Çözüm (derste verilmedi):** Bu açık uçlu bir tasarım sorusudur ve derste çözülmedi. Bir yaklaşım: `Car` sınıfına fiyat alanı (`price`) ile getter/setter, `Person` ve `Gallery` sınıflarına bakiye alanı eklenir; `sellCar` metodu önce yeni sahibin bakiyesinin fiyata yetip yetmediğini denetler, yetiyorsa `removeCar` ile arabayı çıkarır, fiyatı alıcının bakiyesinden düşüp galerinin bakiyesine ekler ve yeni sahibi atar; yetmiyorsa arabayı galeride bırakıp `false` döndürür.

**7. (ekrandan, 02:20:00)** `Company` sınıfının `main` metodu çalıştırıldığında ne yazdırır? (Slayttaki soru: for döngüsünün sözdizimini fark ettiniz mi?)

> **Çözüm (derste verilmedi):** Döngü bir for-each döngüsüdür: `staff` dizisindeki her eleman sırayla `Employee` türündeki `author` değişkenine atanır. Çıktı (ajan tarafından `java` ile çalıştırıldı):
>
> ```text
> Manager 10500
> Employee1 7500
> Employee2 7000
> ```
>
> `staff[0]` `Employee` türünden bir referans olsa da nesne bir `Manager` olduğu için `Manager.getSalary()` çalışır: $8000 + 2500 = 10500$.

**8. (derste sözlü, 02:39:19)** `super` kullanmak yerine alanlar ya da metotlar protected tanımlansa olmaz mı?

> **Cevap (derste verildi):** Protected, alanlara alt sınıfların doğrudan erişmesini sağlar ve kalıtım kullanılacağı kesinse alanlar için seçilebilir. Ama metotlar protected yapılırsa başka sınıfların nesneleri onları çağıramaz; nesnelerin birbiriyle konuşması için metotlar genelde public olmalıdır. Protected yalnız alt sınıfların da kullanacağı yardımcı metotlar için uygundur. `super` ise başka bir ihtiyacı karşılar: alt sınıfta override edilmiş bir metodun üst sınıftaki sürümünü çağırmak ve kurucuda üst sınıfın kurucusunu çağırmak.

**9. (ekrandan, 02:50:00)** Verilen gereksinim metni için `Doctor extends Patient` modeli neden yanlıştır, doğru model nedir?

> **Cevap (derste verildi):** Kalıtım IS-A ilişkisidir; "her doktor bir hastadır" doğru değildir. Ayrıca bu modelde hastaya ait `treatments` dizisi kalıtım yüzünden doktorlara da geçer. Doğru modelde ortak bilgiler (`name`, `TCID`, `cellNr`, `birth`) bir `Person` sınıfında toplanır; `Doctor` (`diplomaNr`) ve `Patient` (`treatments : Treatment[]`) `Person`'dan türer; `Patient` ile `Treatment` arasında 1 — * association bulunur.

**10. (derste sözlü, 02:54:11)** Hasta-doktor diyagramındaki `Date` bir sınıf mıdır?

> **Cevap (derste verildi):** Evet. `Date`, `java.util` paketindeki bir sınıftır; `birth` alanı bu sınıf türünden bir değişkendir.

## Dersin Toparlaması

Ders, önceki derste başlanan nesne ilişkilerinin tekrarıyla açıldı ve composition ilişkisinin kodlanmasını gösteren araba galerisi örneğiyle sürdü. UML diyagramındaki çoklukların koda nasıl yansıdığı (karşı uçta `1` için tek değişken, `*` için dizi), dizi oluşturmanın nesne oluşturmak olmadığı, `carCount` alanının hem araba sayısını hem ilk boş hücreyi gösterdiği ve `addCar`, iki `searchCar`, `removeCar` ve `sellCar` metotlarının nasıl yazıldığı ayrıntılı işlendi. Var olan bir metodun gövdesi görülmese bile giriş ve dönüş türüne bakılarak başka metotların içinde kullanılması gerektiği sınav açısından vurgulandı.

Dersin ikinci yarısında kalıtım anlatıldı: genelleme-özelleştirme ve IS-A ilişkisi, yerine konabilirlik, private ve protected üyelerin mirası, overriding, `final` metotlar, kalıtım ağacı ve derin ağaçların sakıncası, yanlış ve doğru modelleme örnekleri. Kalıtımın sağladığı çok biçimlilik `Person`, `Employee` ve `Manager` örneğiyle gösterildi; `super` anahtar sözcüğünün ebeveyn kurucusunu ve ebeveyn metodunu çağırmak için kullanımı, overloading ile overriding farkı ve hasta-doktor örneğinde gereksinim metninden UML çıkarma işlendi. Ders, her sınıfın `java.lang.Object`'ten türediği bilgisiyle kapandı; sonraki derste kalıtımın başka bir gerçekleştirme yolu olan soyut sınıflara geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
