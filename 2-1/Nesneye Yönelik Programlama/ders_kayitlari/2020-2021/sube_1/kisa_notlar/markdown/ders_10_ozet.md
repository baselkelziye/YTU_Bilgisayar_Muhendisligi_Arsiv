# Ders 10 Çalışma Özeti

## Genel Konular

- Nesneler arası ilişkilerin tekrarı
  - Association (ilişkilendirme): birinci nesne ikinci türden sıfır ya da daha çok nesneye sahip olabilir. Örnek: bir müşterinin sıfır ya da daha çok siparişi olabilir.
  - Aggregation (toplama): yine sahiplik ilişkisidir ama daha güçlüdür; birinci nesnenin ikinci türden en az belirli sayıda nesnesi olmalıdır. Örnek: bir otobüs güzergâhının en az iki durağı vardır.
  - Composition (bileşim): aggregation'a benzer ama daha güçlü bir bütün-parça ilişkisidir; parça aynı anda yalnız bir bütüne ait olabilir. UML'de içi dolu elmasla gösterilir. Örnek: `Team` 1 — * `Player`; bir oyuncu yalnız bir takıma aittir (ekrandan, 00:15:00).
  - Association, aggregation ve composition'da ikinci nesne birinci sınıfın üye alanlarında (data member fields) görünür. Dependency (bağımlılık) ilişkisinde ise ikinci sınıf yalnız birinci sınıfın metotlarında (gövde ya da parametre) kullanılır.
  - UML'deki çokluk koda şöyle yansır: karşı uçta `1` yazıyorsa tek bir değişken, `*` ya da `1..10` gibi bir aralık yazıyorsa dizi (ileride liste gibi başka veri yapıları) tanımlanır.
- Composition örneği: `Gallery` (araba galerisi) sınıfı (ekrandan, 00:25:00)
  - Sınıflar: önceki derslerden `Person` ve `Car` (aralarında iki yönlü 1-1 association), yeni `Gallery` sınıfı ve `main` metodunu içeren `MainProgram04`.
  - `Gallery` alanları: `- galleryName : String`, `- cars : Car[]`, `- carCount : int`, `- galleryOwner : Person`.
  - `Gallery` metotları: `+ Gallery( name : String, owner : Person )`, `+ getGalleryName( ) : String`, `+ setGalleryName( galleryName : String )`, `+ addCar( car : Car ) : boolean`, `+ searchCar( aCar : Car ) : boolean`, `+ searchCar( plate : String ) : Car`, `+ removeCar( plate : String ) : Car`, `+ sellCar( plate : String, newOwner : Person ) : boolean`, `+ introduceSelf( ) : String`.
  - `Gallery` ile `Person` arasında 1-1 association, `Gallery` ile `Car` arasında composition (bir galeride sıfır ya da daha çok araba; bir araba yalnız bir galeride) vardır. `MainProgram04` ile `Gallery` ve `Car` arasında dependency vardır, çünkü bu sınıflar yalnız `main` metodunda kullanılır.
  - Kurucu iki parametre alır (ad ve sahip): galeri açıldığında arabası olmayabilir, ama adı ve sahibi olmalıdır.
- `Gallery` kodu (ekrandan, 00:35:00 - 01:10:00)
  - Kurucu: `this.galleryName = galleryName; this.galleryOwner = galleryOwner; carCount = 0; cars = new Car[30];`. Yerel parametreyle aynı adı taşıyan üye alana `this` ile erişilir.
  - `new Car[30]` yalnız diziye bellek ayırır, hiçbir `Car` kurucusu çalışmaz; dizinin 30 hücresinin hepsi `null`'dır (ekrandan, 00:35:00).
  - `addCar`: `if(!searchCar(aCar) && carCount < cars.length)` ise `cars[carCount] = aCar; carCount++; return true;`, değilse `return false;`. `cars.length` dizinin kapasitesini verir, eleman sayısını vermez; bu yüzden `carCount` alanı gerekir (ekrandan, 00:45:00).
  - `searchCar(Car aCar)`: for-each döngüsüyle (`for( Car car : cars )`) referans karşılaştırır (`car == aCar`) (ekrandan, 00:50:00).
  - `searchCar(String plate)`: klasik for döngüsüyle `0`'dan `carCount`'a kadar gezer, `cars[i].getPlate().compareTo(plate) == 0` ise o arabayı, bulamazsa `null` döndürür (ekrandan, 00:50:00).
  - `removeCar(String plate)`: arabayı bulunca referansını `theCar` değişkenine alır, sonraki hücreleri birer sola kaydırır, `cars[carCount-1] = null; carCount--;` yapar ve `theCar`'ı döndürür (ekrandan, 01:05:00).
  - `sellCar(String plate, Person newOwner)`: `removeCar`'ı çağırır; dönen araba `null` değilse `setOwner(newOwner)` ile yeni sahibi atar ve `true` döndürür (ekrandan, 01:05:00).
- `MainProgram04` (ekrandan, 01:35:00)
  - Galeri oluşturulurken sahip olan `Person` nesnesi doğrudan argüman içinde `new` ile oluşturulur, çünkü başka yerde kullanılmayacaktır.
  - İki araba (`"34 RA 440"` ve `"06 AC 432"`, sahipsiz: `null`) eklenir, aranır, biri plaka ile silinir ve silindikten sonra tekrar aranır.
- Kalıtım (inheritance)
  - Bir sınıftan yeni sınıf türetme yoludur; sınıf düzeyinde bir ilişkidir. UML'de içi boş üçgen ok çocuktan ebeveyne doğru çizilir. Ebeveyn: parent, super, base class; çocuk: child, sub, derived class (ekrandan, 01:50:00).
  - Genelleme-özelleştirme (generalization-specialization) ilişkisidir: çocuk ebeveynin özelleşmiş ve daha yetenekli hâlidir. Örnekler: `Car` → `StationWagon`, `Racing`, `Jeep`; `Printer` → `DotMatrix`, `Laser`, `InkJet` (ekrandan, 01:45:00).
  - Ebeveynin bütün alanları ve metotları çocuğa geçer, ama çocuk miras aldığı private üyelere doğrudan erişemez; ebeveynin public metotlarını kullanır. Protected üyelere çocuklar erişebilir, başka sınıflar erişemez.
  - Kurallar: alt sınıf üst sınıftan gelen bir üyeyi reddedemez; miras alınan metodun gövdesi değiştirilebilir (overriding); `final` metotlar override edilemez; alt sınıfa yeni üyeler eklenebilir; bir alt sınıf başka sınıfların ebeveyni olabilir ve kalıtım ağacı oluşur (ekrandan, 01:55:00).
  - Ağaç çok derin yapılmamalıdır (fragile super class sorunu): en üstteki sınıfta yapılan bir değişiklik bütün alt sınıfları etkiler.
  - Yerine konabilirlik (substitutability): ebeveynin beklendiği her yerde çocuk kullanılabilir. Bu yüzden kalıtıma IS-A ilişkisi denir.
  - Kalıtım çalışma sırasında değiştirilemez; açık bir genelleme-özelleştirme ilişkisi yoksa association, composition ya da aggregation kullanılır (ekrandan, 02:00:00).
- Çok biçimlilik (polymorphism) ve `super`
  - `Person` türünden bir dizide `Person`, `Student`, `Employee` ve `Retired` nesneleri bulunabilir. Hepsinin `introduceSelf` metodu çağrıldığında her nesnenin kendi sınıfındaki sürüm çalışır. Bu mekanizmaya polymorphism denir (ekrandan, 02:05:00).
  - Override edilmiş metodun üst sınıftaki sürümüne `super` ile erişilir. `this` geçerli nesneyi, `super` ebeveyn kısmını gösterir.
  - `super(...)` çocuk kurucusunda ebeveynin kurucusunu çağırır; `super.metot()` ebeveynin metodunu çağırır. `super.super` yazılamaz.
- `Person` - `Employee` - `Manager` örneği ve `Company` sınıfı (ekrandan, 02:10:00 - 02:20:00)
  - `Employee extends Person` (`- salary : int`), `Manager extends Employee` (`- bonus : int`). `Manager.getSalary()` ebeveyninkini `super.getSalary()` ile çağırıp bonusu ekler.
  - `Company.main`: `Employee[] staff = new Employee[3];` dizisine bir `Manager` ve iki `Employee` konur; for-each döngüsünde her birinin `getName()` ve `getSalary()` metodu çağrılır. `Manager` nesnesi için `Manager`'ın `getSalary` sürümü çalışır.
  - Bu `main` metodunun UML ardışık diyagramı da çizildi; dizi hücresine atama "add" mesajıyla, döngüde tekrarlanan çağrılar `*` ile gösterildi.
- Overloading ve overriding farkı (ekrandan, 02:35:00)
  - Overriding: miras alınan metodun gövdesini çocuk sınıfta aynı imzayla yeniden yazmak; kalıtımla ilgilidir. Örnek: `Manager.getSalary()`.
  - Overloading: aynı sınıfta aynı adlı ama parametreleri farklı birden çok metot; kalıtımla ilgili değildir. Örnek: `Manager`'a üç parametreli `Manager(String name, int salary, int bonus)` kurucusunu eklemek.
- Doğru modelleme örneği: hasta ve doktor (ekrandan, 02:50:00)
  - Gereksinim metninden sınıflar çıkarılır: hasta, doktor, tedavi.
  - Yanlış model: `Doctor extends Patient`; her doktor hasta değildir ve hastaya ait `treatments` dizisi doktora da miras kalır.
  - Doğru model: ortak bilgileri (`name`, `TCID`, `cellNr`, `birth : Date`) tutan bir `Person` üst sınıfı; `Doctor` (`diplomaNr`) ve `Patient` (`treatments : Treatment[]`) bu sınıftan türer; `Patient` 1 — * `Treatment`.
- `java.lang.Object`
  - Java'da her sınıf örtük olarak `java.lang.Object` sınıfından türer. Onun metotları, örneğin `toString`, kendi sınıflarımızda override edilebilir; `introduceSelf` içinde yazılanlar `toString` içine de yazılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- UML diyagramından kod yazmak
  - Sınavlarda bir UML sınıf diyagramı verilip belli bir sınıfın Java kodu istenecektir. Alanların erişim belirleyicileri (`-` private, `+` public), türleri ve ilişkilerdeki çokluklar doğru okunmalıdır.
- Var olan metodu kullanmak
  - Bir metodu yazarken UML'de zaten bulunan başka bir metodun işini görmesi gerekiyorsa o metot, gövdesi gösterilmemiş olsa bile çağrılmalıdır. Örnek: `addCar` içinde `searchCar`, `sellCar` içinde `removeCar` kullanılır. Bir metodun ne yaptığı giriş ve dönüş türünden anlaşılır. Hoca sınavda en çok zaman kaybının, var olan metodu sıfırdan yeniden yazmaktan çıktığını söyledi.
- Dizi oluşturmak nesne oluşturmak değildir
  - `new Car[30]` yalnız 30 tane `null` referans tutan bir dizi ayırır; `Car` nesneleri ayrıca `new Car(...)` ile oluşturulur.
- Kalıtım yalnız IS-A ilişkisi varken kullanılır
  - Kırmızı, sarı, mor gibi renkler bir GUI düğmesinin özelliğidir, düğmenin kendisi değildir; renkleri düğmenin alt sınıfı yapmak yanlış modellemedir. "Doktor bir hastadır" önermesi de doğru olmadığı için `Doctor extends Patient` yanlıştır.
- Sınava hazırlanma yolu
  - Bir gereksinim metninden UML sınıf diyagramını çıkarmak, diyagramdan her sınıfın kodunu ve `main` sınıfını yazmak, sonra `main` metodunun ardışık diyagramını çizmek. Ardışık diyagram sorusu da sınavda beklenmelidir.
- Erişim belirleyici seçimi
  - Üye alanlar genelde private, metotlar public tanımlanır. Kalıtım kullanılacağı kesinse alanlar protected olabilir. Yalnız sınıfın içinde kullanılan yardımcı (utility) metotlar private, alt sınıfların da kullanması gerekiyorsa protected tanımlanır. Alanlar hiçbir zaman gerekçesiz public yapılmaz.

## Kısa Tekrar Notları

- Association: 0 ya da daha çok; aggregation: en az belirli sayıda; composition: parça yalnız bir bütüne ait (içi dolu elmas).
- İlişkinin karşı ucunda `1` varsa tek değişken, `*` varsa dizi tanımlanır.
- Dependency: ikinci sınıf yalnız metotlarda kullanılır; `main` sınıfı kullandığı sınıflara bağımlıdır.
- `new Car[30]`: kurucu çalışmaz, 30 tane `null`.
- `cars.length` kapasiteyi, `carCount` dolu hücre sayısını (ve ilk boş hücrenin indisini) verir.
- for-each: `for( Car car : cars )`; klasik for: başlangıç; durma koşulu; artırma.
- `==` nesnelerde referans (adres) karşılaştırır; `String.compareTo` içerik karşılaştırır, eşitse 0 döndürür.
- `removeCar`: bul, referansı sakla, sola kaydır, son dolu hücreyi `null` yap, `carCount--`, saklanan referansı döndür.
- Kalıtım: `class B extends A`; UML'de boş üçgen ok çocuktan ebeveyne.
- Private üyeler miras kalır ama çocuk doğrudan erişemez; protected üyelere çocuk erişir.
- `final` metot override edilemez; alt sınıf üst sınıfın üyesini reddedemez.
- Kalıtım ağacı derin olmamalı (fragile super class).
- Çocuk, ebeveynin beklendiği her yerde kullanılabilir (IS-A).
- Polymorphism: aynı türden referanslar üzerinden çağrılan aynı metot, nesnenin gerçek sınıfına göre farklı çalışır.
- `super(...)`: ebeveyn kurucusu; `super.metot()`: ebeveyn metodu; `super.super` yok.
- Overriding: çocukta aynı imza; overloading: aynı sınıfta aynı ad, farklı parametreler.
- Her sınıf örtük olarak `java.lang.Object`'ten türer; `toString` override edilebilir.

## Detaylı Açıklamalar

- `Gallery` sınıfının yapısı ve kurucusu
  - Galeri, satılacak birden çok arabayı tutan bir sınıftır. Arabalar `Car[] cars` dizisinde, dolu hücre sayısı `carCount` alanında tutulur. Kurucu galeri adını ve sahibini parametre olarak alır, `carCount`'u 0 yapar ve 30 hücrelik diziyi ayırır (ekrandan, 00:35:00):

    ```java
    public Gallery( String galleryName, Person galleryOwner ) {
        this.galleryName = galleryName; this.galleryOwner = galleryOwner;
        carCount = 0;
        cars = new Car[30];   // kurucu çalışmaz, yalnız dizi için bellek ayrılır
    }
    ```

  - Hoca bunu tahtada da gösterdi: dizi oluşturulunca fiziksel bellekte bir adres alanı ayrılır ve bu adres `cars` değişkenine atanır. Hücrelerin hepsi `null`'dır, yani hiçbir nesneyi göstermez.
  - Dizinin boyutu UML diyagramında yazmaz; sınavda soru metninde verilir.
- `addCar` ve iki koşul
  - Araba eklenmeden önce iki koşul denetlenir: araba zaten galeride olmamalı ve dizide boş yer bulunmalıdır (ekrandan, 00:45:00):

    ```java
    public boolean addCar( Car aCar ) {
       if(!searchCar(aCar) && carCount < cars.length){
          cars[ carCount ] = aCar;
          carCount++;
          return true;
       }
       return false;
    }//end addCar
    ```

  - `searchCar` araba varsa `true` döndürür; başındaki `!` onu `false` yapar ve `&&` yüzünden bütün koşul `false` olur, metot `false` döndürür. Araba yoksa iki koşul da doğruysa araba `carCount` indisli hücreye (ilk boş hücre) yazılır ve `carCount` bir artırılır.
  - Slayttaki nota göre dizinin boyutu `cars.length` ile öğrenilebilir, ama eleman sayısı öğrenilemez; bu yüzden `maxCar` gibi bir değişken gerekmez, `carCount` gibi bir değişken gerekir. İstenirse `public final static int maxCar = 30;` sabiti tanımlanabilir (ekrandan, 00:45:00).
- İki `searchCar` metodu (overloading)
  - Biri `Car` nesnesi alıp `boolean`, öbürü plaka alıp `Car` (ya da `null`) döndürür. Aynı adlı, farklı parametreli metotlar olduğu için bu bir overloading örneğidir (ekrandan, 00:50:00):

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

  - For-each döngüsü her turda diziden bir elemanı sırayla yerel `car` değişkenine atar ve gövdeyi çalıştırır; eleman kalmayınca çıkar. Klasik for döngüsünün üç bölümü vardır: başlangıç, durma koşulu ve döngü değişkeninin güncellenmesi.
  - Ders sonrası not: hoca bir soruya, for-each döngüsünün ilk `null` hücrede durduğunu söyledi. Doğrusu: for-each dizinin bütün hücrelerini (30 hücrenin hepsini) gezer; `null` hücrelerde `car == aCar` yalnız `false` verir. Bu ajan tarafından `java` ile denendi.
- `removeCar` ve `sellCar`
  - `removeCar` arabayı plakasıyla bulur, referansını saklar, sonraki hücreleri birer sola kaydırarak boşluğu kapatır, son dolu hücreyi `null` yapıp `carCount`'u azaltır (ekrandan, 01:05:00):

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
    public boolean sellCar( String plate, Person newOwner ) {
        Car soldCar = removeCar(plate);
        if( soldCar != null ) {
            soldCar.setOwner(newOwner);
            return true;
        }
        return false;
    }
    ```

  - Bir öğrenci kaydırma döngüsünün son turunda `cars[carCount-1]`'e zaten bir sonraki hücredeki `null`'ın kopyalandığını fark etti. Hoca haklı olduğunu kabul etti, ama döngüden sonra `carCount-1` hücresine `null` yazmanın güvenli taraf olduğunu söyledi: bir sonraki ekleme `carCount` indisine yapılacağından o hücre boş olmalıdır.
  - Ders sonrası not: dizi doluyken (`carCount == 30`) bu kod `j = 29` turunda `cars[30]`'a erişir ve `ArrayIndexOutOfBoundsException` fırlatır. Döngü sınırı `j < carCount - 1` yapılırsa sorun kalkar. Bu derste söylenmedi; ajan tarafından `java` ile denendi.
- Kalıtım ve `super`
  - `Employee` kurucusu önce `super( name );` ile `Person` kurucusunu çağırıp ebeveyndeki `name` alanını başlatır, sonra kendi `salary` alanını atar (ekrandan, 02:10:00). `Manager.getSalary()` ise `super.getSalary()` ile ebeveynin maaş hesabını çağırıp üstüne bonusu ekler.
  - `Company` örneğinin çıktısı (ajan tarafından `java` ile çalıştırıldı): `Manager 10500`, `Employee1 7500`, `Employee2 7000`. İlk satırdaki 10500, `Manager`'ın override ettiği `getSalary` sürümünün çalıştığını (8000 + 2500) gösterir.
  - Hoca, `super` gereksinimini şöyle açıkladı: alt sınıfta `getName` override edilip başına bir ön ek eklenmiş olsun; aynı sınıfta hem yeni sürüm hem üst sınıftaki sürüm gerekebilir. Üst sınıftaki sürüm `super` ile çağrılır. Kurucuda ebeveynin alanlarını başlatmak da `super(...)` ile yapılır.
  - Ders sonrası not: slayt (ve hoca) üst sınıfın private metotlarının alt sınıfta override edilebileceğini söyledi. Java'da private metotlar override edilmez; alt sınıfta aynı adla yazılan metot bağımsız yeni bir metottur ve üst sınıfın kendi içindeki çağrılar yine üst sınıftaki private sürümü çalıştırır. Bu ajan tarafından `java` ile denendi. Slaytın asıl uyarısı doğrudur: alt sınıf üst sınıfın private metoduna `super` ile bile erişemez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
