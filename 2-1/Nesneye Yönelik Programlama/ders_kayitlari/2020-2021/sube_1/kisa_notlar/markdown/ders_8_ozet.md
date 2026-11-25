# Ders 8 Çalışma Özeti

## Genel Konular

- Java'da metot çağrısı: değerle çağırma ve referansın değeriyle çağırma
  - Java "call by value" kullanır. İlkel (primitive) türde bir argüman verildiğinde metoda değerin kopyası geçer; metot içindeki değişiklik çağıranı etkilemez.
  - İlkel olmayan (nesne, dizi) argümanlarda metoda referansın değeri (nesnenin bellekteki adresinin kopyası) geçer. Bu yüzden bu yönteme "call by value of references" da denir. C'deki işaretçiyle çağırmadan farklıdır.
  - Örnekler Eclipse'te `nyp01e` paketindeki `MethodParametersTest1`, `MethodParametersTest2` ve `MethodParametersTest3` sınıflarıyla adım adım izlendi (ekrandan, 00:20:00, 00:45:00, 00:55:00).
- `MethodParametersTest1`: metot içinde değiştirme denemeleri
  - `ilkelDuzenle(int x) { x++; }`: `count = 3` gönderilir, metot içinde `x` 4 olur, `count` 3 kalır.
  - `sarmalayiciDuzenle(Integer x) { x++; }`: `Integer wrap = 5;` satırı otomatik kutulamadır (boxing), Java bunu `new Integer(5)` gibi anlar. Metottaki `x++` kutuyu açar, 6 değerli yeni bir `Integer` nesnesi oluşturur ve `x`'i ona yöneltir; `wrap` hâlâ 5 değerli nesneyi gösterir, çıktı 5'tir.
  - `ilkelDegistir(int x, int y)` ve `sarmalayiciDegistir(Integer x, Integer y)`: yer değiştirme yalnız metodun yerel değişkenlerinde olur; `count1, count2` ve `wrap1, wrap2` değerleri 1 ve 2 olarak kalır.
  - `sarmalayiciDegistirAlt`: aynı yer değiştirme, kutulama bu kez `new Integer(...)` ile açıkça yazılarak yapılır. Sonuç yine değişmez.
  - `swapForReal()`: parametre almaz, sınıfın `private Integer wrapI, wrapJ;` alanlarını değiştirir. Bu alanlar nesnenin verisi olduğu için her üye metot onlara erişebilir; yer değiştirme kalıcıdır (3 ve 5 değerleri yer değiştirir).
- `MethodParametersTest2`: aynı metot içinde yer değiştirme
  - Yerel `int x = 1, y = 2` ve `temp` ile takas: önce `1, 2`, sonra `2, 1`.
  - `Integer sarma1 = 3; Integer sarma2 = 5;` ve `Integer gecici` ile referansların takası: önce `3, 5`, sonra `5, 3`. Nesnelerin değerleri değil, değişkenlerin gösterdiği adresler yer değiştirir.
- `MethodParametersTest3`: dizinin metoda geçirilmesi
  - Bir `.java` dosyasında birden fazla sınıf olabilir, ama yalnız biri `public` olabilir ve dosya adı bu public sınıfın adıdır.
  - Dizi değişkeni de nesne değişkeni gibi bir referanstır. `LowHighSwap.doIt(dizi)` dizinin referansını `z`'ye kopyalar; `z` ile yapılan değişiklik aynı diziyi değiştirir.
  - `doIt` dizinin son ve ilk elemanını takas eder; `{1, 2, 3, 4, 5}` dizisi `5 2 3 4 1` olur (ekrandan, 00:55:00; ajan tarafından çalıştırıldı).
  - Dosyanın sonundaki yorum: static kullanımının "call-by-value-of-references" konusuyla ilgisi yoktur.
- Kontrol akışını değiştiren yapılar (slayt 63)
  - Karar: `if (koşul) {...} else if (koşul) {...} ... else {...}` ve `switch / case`. Her iki yapıda da bloklardan yalnız biri çalışır.
  - Koşullarda karşılaştırma işleçleri `< > <= >= == !=`, mantıksal işlemlerde çift işleç `&& ||` kullanılır.
  - Döngüler: `for(başlangıç; koşul; artırma)`, `while(koşul)`, `do {...} while(koşul);`. `do-while` gövdeyi koşula bakmadan önce bir kez çalıştırır, yani en az bir kez çalışır.
- Nesneler arası ilişkiler
  - İlişki türleri: association (ilişkilendirme), dependency (bağımlılık), association'ın daha güçlü biçimleri olan aggregation ve composition, ayrıca inheritance (kalıtım).
  - İki nesne arasında ilişki varsa biri diğerine mesaj gönderebilir; mesaj göndermek, diğer nesnenin bir metodunu çağırmaktır.
- Association: sahiplik (ownership)
  - Mesaj gönderen nesne, mesajı alan nesneyi bir üye alanı (member field) olarak tutar. Örnek: `Customer 1 —gives→ * Order` (ekrandan, 01:20:00).
  - Gösterim: oksuz düz çizgi (iki yönlü ya da yön henüz düşünülmemiş), tek yönlü ok (A, B'ye sahiptir; A'nın örnekleri B'nin örneklerine mesaj gönderebilir), çift yönlü ok (iki yönlü bağlantı) (ekrandan, 01:25:00).
  - Çokluk (cardinality): `*` sıfır ya da daha çok, `1..*` bir ya da daha çok, `1` yalnız bir, `1..11` birden on bire kadar.
- Gizli bilgi (hidden information)
  - Bir ilişki çizgi ve okla gösterilmişse sınıfın içindeki ayrıntılar yazılmayabilir. `Customer 1 → * Order` diyagramı, `Customer` içinde `- orders[] : Order` alanı yazılmış diyagramla aynıdır (ekrandan, 01:30:00).
  - Slayt 78'deki üç grupta üstteki diyagram alttakini ima eder: `A 1 → 2 B` ise A'da `- b1, b2 : B`; kesikli `A → B` ise A'da `+ metot(b : B)`; A tarafında boş elmas ve B tarafında `*` ise A'da `- b[] : B` (ekrandan, 01:55:00).
- Dependency: bağımlılık
  - B sınıfı A'nın üye alanlarında değil, yalnız bir metodunun parametresinde ya da gövdesinde geçiyorsa A, B'ye bağımlıdır. Sahiplik yoktur, geçici kullanım vardır.
  - Kesikli okla gösterilir: `A (+ aMethod(b : B)) - - -> B`; A'nın örnekleri `aMethod` gövdesinde B'nin örneklerine mesaj gönderebilir (ekrandan, 01:30:00).
- Tek yönlü association örneği (`nyp02` paketi: `Person`, `Car`, `MainProgram01`)
  - Diyagram: `Person` (`- name : String`, `- car : Car`) `1 owns → 0..1` `Car` (`- plate : String`); `MainProgram01` iki sınıfa kesikli okla bağımlıdır (ekrandan, 01:35:00).
  - `0..1` olmasının nedeni: `Person` tek bir `Car` alanı tutar (dizi değil) ve `Person(String name)` yapıcısı araba istemez; kişi arabasız oluşturulabilir.
  - `introduceSelf()` arabanın plakasını yazmadan önce `if( car != null )` ile arabanın var olup olmadığını denetler (ekrandan, 01:40:00).
  - `MainProgram02` aynı modeli `Scanner` ile klavyeden ad, araba olup olmadığı (`e/h`) ve plaka alarak çalıştırır (ekrandan, 02:05:00).
- İki yönlü association örneği (`nyp03`, `nyp03b`, `nyp03c` paketleri)
  - `Car` sınıfına `- owner : Person` alanı, bu alanın getter/setter'ı ve `Car(String plate, Person owner)` ikinci yapıcısı eklenir; `introduceSelf()` sahibin adını yazmadan önce `if( owner != null )` denetimi yapar (ekrandan, 02:20:00).
  - İlk sürümde ilişkiyi kurmak için iki satır gerekir: `oktay.setCar(rover);` ve `rover.setOwner(oktay);` (ekrandan, 02:25:00).
  - İyileştirme (`nyp03b`): `setCar` içinde `if( car.getOwner() != this ) car.setOwner(this);`, `setOwner` içinde `if( owner.getCar() != this ) owner.setCar(this);` yazılır. Böylece tek bir set çağrısı iki yönü de kurar (ekrandan, 02:30:00).
  - Son adım (`nyp03c`): iki parametreli `Car` yapıcısına `setOwner` konunca `new Car("06 OS 1934", oktay)` tek satırda iki yönlü ilişkiyi kurar (ekrandan, 02:40:00).
- Aggregation ve composition
  - Aggregation bütün-parça (whole-part) ilişkisidir ve association'dan biraz daha güçlüdür. Hocanın örneği: otobüs hattı ve durak. Bir hat en az iki durak (başlangıç ve varış) içermelidir; bir durak birden çok hatta bulunabilir.
  - Composition daha güçlü bir bütün-parça ilişkisidir: parça aynı anda yalnız bir bütüne ait olabilir. Gösterimi dolu elmastır; örnek `Team 1 ◆→ * Player` (ekrandan, 02:45:00).
  - Aggregation ve composition'da çokluk genelde `*` olduğundan birinci sınıf bir veri yapısı (şimdilik dizi; ileride liste, yığın, kuyruk) tutar.
  - Derste sonraki örnek olarak birden çok satılık araba tutan bir `Gallery` sınıfının composition ile modellenmesi slaytı açıldı, örnek işlenmedi (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Association'da diğer nesnenin metodu çağrılmadan önce `null` denetimi
  - Sahip olunan nesne henüz oluşturulmamışsa metodunu çağırmak çalışma sırasında `NullPointerException` verir. Kod derleme hatası vermez, hata çalışırken çıkar.
  - Hoca sınavda bu denetimin yapılmamasını puan kaybı sayacağını açıkça söyledi; tek ve iki yönlü örneklerin ikisinde de üzerinde durdu.
- Sınavda istenen sıralama diyagramı (sequence diagram) nasıl çizilir
  - Metot kodu satır satır okunur; her nesne ayrı bir sütun olur; `new` ile yapıcı çağrısı, metot çağrıları ve dönüşler okunan sırayla çizilir. Metot gövdesi bitince diyagram da biter.
  - `if` gibi bir koşul varsa diyagramda koşul da gösterilir (örneğin `car != null`).
  - `main` metodunu JVM (`java.exe`) çağırır; çalışma bitince kontrol JVM'e döner.
- Sınıf yazarken bütün üye alanlar için getter ve setter
  - Hoca sınavda tüm üye alanlar için getter/setter yazılmasını isteyeceğini söyledi.
- Önce tek yönlü ilişkiyle başlayın
  - İki yönlü ilişkide hem karşı nesnenin set metodunu çağırmak hem de yapıcıda ilişkiyi kurmak gibi unutulabilecek ayrıntılar vardır. İş tek yönlü ilişkiyle görülebiliyorsa tek yönlü tercih edilmeli, gerçekten gerekirse iki yönlüye geçilmelidir.
- Diyagramda çizgi türünden kodu okumak
  - Düz çizgi/ok: B, A'nın üye alanlarında geçer. Kesikli ok: B yalnız A'nın metot parametresinde ya da gövdesinde geçer. `*` çokluk: A'da B nesnelerini tutan bir veri yapısı vardır. Bu ayrıntılar diyagramda gösterilmese de öğrencinin bunları anlaması beklenir.

## Kısa Tekrar Notları

- Java her zaman değerle çağırır: ilkel türde değerin kopyası, nesnede referansın kopyası geçer.
- Metot içinde parametreye yeni nesne atamak (`x = y`, `x++` ile yeni `Integer`) çağıranın değişkenini değiştirmez.
- Referansın gösterdiği nesnenin içi (dizi elemanı, nesne alanı) değiştirilirse değişiklik çağırana da yansır.
- `Integer` değişmezdir (immutable); `x++` yeni bir nesne oluşturur.
- `Integer wrap = 5;` otomatik kutulamadır (boxing).
- Üye alanları değiştiren metot (`swapForReal`) parametre almadan kalıcı değişiklik yapar.
- Bir dosyada tek `public` sınıf olur, dosya adı onun adıdır.
- Static olmayan bir metodu static `main` içinden çağırmak için önce nesne oluşturulur; static metot sınıf adıyla çağrılır (`LowHighSwap.doIt(dizi)`).
- `do-while` en az bir kez çalışır; `if-else` ve `switch`'te tek blok çalışır.
- Association = sahiplik, düz çizgi/ok; dependency = parametre ya da geçici kullanım, kesikli ok.
- Çokluk: `*` 0 ya da çok, `1..*` 1 ya da çok, `1` tek, `0..1` sıfır ya da bir, `1..11` aralık.
- Association'da karşı nesnenin metodunu çağırmadan önce `if (nesne != null)`.
- İki yönlü ilişkide set metotları birbirini `!= this` denetimiyle çağırır; yapıcıya set konursa ilişki tek satırda kurulur.
- Aggregation: bütün-parça (otobüs hattı-durak). Composition: parça tek bütüne ait (takım-oyuncu), dolu elmas.

## Detaylı Açıklamalar

- Değerle çağırma ve referansın değeriyle çağırma
  - Java'da bir metoda ilkel türde (`int` gibi) bir değişken verildiğinde JVM, metodun parametresi için bellekte ayrı bir yer açar ve değeri oraya kopyalar. `ilkelDuzenle(count)` çağrısında `x` için yeni bir yer açılır, `x = 3` olur, `x++` ile 4 olur; metot bitince `count` yine 3'tür.
  - İlkel olmayan bir argümanda ise nesnenin kendisi değil, nesnenin adresinin (referansının) kopyası geçer. Hoca bunu tahtada adresi "xyz" olan bir nesneyle anlattı: çağıran değişken de parametre de aynı "xyz" adresini tutar, ikisi de aynı nesneyi gösterir.
  - `sarmalayiciDuzenle(wrap)` içinde `x++` yazıldığında Java `Integer` nesnesini ilkel `int`'e çevirir (5), artırır (6) ve sonucu yeni bir `Integer` nesnesine koyup `x`'i ona yöneltir. `wrap` eski nesneyi göstermeye devam ettiği için çıktı 5'tir.
  - `sarmalayiciDegistir` ve `sarmalayiciDegistirAlt` metotları da yalnız yerel `x`, `y`, `temp` değişkenlerinin gösterdiği adresleri değiştirir; çağıranın `wrap1` ve `wrap2` değişkenleri yine 1 ve 2 değerli nesneleri gösterir.
  - `swapForReal()` ise sınıfın üye alanlarını değiştirir. Hoca bir öğrencinin "parametre geçmeden bu değişkenlere nasıl erişiyoruz?" sorusuna, bu değişkenlerin nesnenin verisi olduğunu ve nesnenin bütün üye metotlarının bu veriye erişebildiğini söyleyerek cevap verdi.
- Aynı metot içinde takas
  - `MethodParametersTest2.tryMe()` içinde takas yerel değişkenlerle yapıldığı için sonuç görünür: `int`'lerde `1, 2` → `2, 1`; `Integer`'larda `3, 5` → `5, 3`. Hoca `sarma1` ve `sarma2`'nin gösterdiği adresleri (xyz ve abc) tahtada yer değiştirerek takasın nesneleri değil adresleri değiştirdiğini gösterdi.
- Dizi örneği
  - `int[] dizi = {1, 2, 3, 4, 5};` satırı bellekte beş elemanlık bir dizi oluşturur ve `dizi` değişkeni bu dizinin adresini tutar. `doIt(int[] z)` çağrısında `z` aynı adresi alır.
  - `int temp = z[z.length - 1];` son elemanı (5) alır, `z[z.length - 1] = z[0];` son hücreye 1 yazar, `z[0] = temp;` ilk hücreye 5 yazar. `main` içindeki döngü `5 2 3 4 1` yazar.
- Tek yönlü association kodu
  - `Person` sınıfı slayttaki kodla şöyledir (ekrandan, 01:40:00):

```java
package nyp02;
public class Person {
   private String name;
   private Car car;

   public Person( String name ) {
         this.name = name;
   }
   public String getName( ) { return name; }
   public Car getCar( ) { return car; }
   public void setCar( Car car ) { this.car = car; }

   public String introduceSelf( ) {
         String intro;
         intro = "Hello, my name is " + getName();
         if( car != null )
             intro += "and I have a car with license plate "
             + car.getPlate()+ ".";
         return intro;
   }
}
```

  - `MainProgram01` iki kişi oluşturur. Birincisine `setCar` ile bir araba verilir, ikincisine verilmez. Birincinin `introduceSelf()` çıktısı plakayı da içerir; ikincide `car` `null` olduğu için `if` bloğu çalışmaz ve yalnız ad yazılır.
  - `null` denetimi: nesne oluşturulmuşsa `nesne == null` yanlış, `nesne != null` doğrudur; oluşturulmamışsa tersi. Metodu çağırabilmek için `nesne != null` koşulunun doğru olması istenir.
- İki yönlü association kodu
  - Yeni `Car` sınıfı (ekrandan, 02:20:00):

```java
package nyp03;
public class Car {
   private String plate;
   private Person owner;

   public Car( String plate ) { this.plate = plate; }
   public Car( String plate, Person owner ) {
        this.plate = plate;
        this.owner = owner;
   }
   public void setOwner( Person owner ) { this.owner = owner; }
   public Person getOwner() { return owner; }
   public String getPlate( ) { return plate; }
   public void setPlate( String plate ) { this.plate = plate; }
   public String introduceSelf( ) {
        String intro;
        intro = "[CAR] My license plate is " + getPlate();
        if( owner != null )
             intro += " and my owner is " + owner.getName();
        return intro;
   }
}
```

  - İki yapıcının nedeni: fabrikadan çıkan bir arabanın sahibi henüz belli olmayabilir (tek parametreli yapıcı) ya da önceden satılmış olabilir (iki parametreli yapıcı).
  - `nyp03b`'deki set metotları (ekrandan, 02:30:00):

```java
public void setCar( Car car ) {          // Person sınıfında
     this.car = car;
     if( car.getOwner() != this )
          car.setOwner(this);
}

public void setOwner( Person owner ) {   // Car sınıfında
     this.owner = owner;
     if( owner.getCar() != this )
          owner.setCar(this);
}
```

  - `!= this` denetimi, arabanın sahibi zaten bu kişiyse yeniden yazmayı önler. Hoca bir öğrencinin "bu `if` şart mı?" sorusuna, denetim olmadan da sonucun aynı çıkacağını, denetimin yalnız gereksiz üzerine yazmayı engellediğini söyledi.
  - Bu iki metot ve iki parametreli yapıcıdaki `setOwner` çağrısıyla `MainProgram03` yalnız `new Person(...)` ve `new Car("06 OS 1934", oktay)` satırlarıyla iki yönlü ilişkiyi kurar (ekrandan, 02:40:00). Ajan bu kodu `java` ile çalıştırdı: iki `introduceSelf()` çıktısı da karşı nesnenin bilgisini içerdi.
- Ders sonrası notlar
  - Hoca 00:49:41'de "aynı sınıfın metodunu kullanmak için bile nesne oluşturmak gerekir" dedi. Bu, soruda geçen static `main` içinden çağırma için doğrudur. Static olmayan bir metodun içinden aynı sınıfın başka bir static olmayan metodu nesne oluşturmadan doğrudan (ya da `this.` ile) çağrılabilir; `tryMe()` içindeki `this.ilkelDuzenle(count)` çağrıları da böyledir.
  - Slayt 63'teki şablonda `else (condition) {...}` yazıyor. Java'da son `else` koşul almaz; doğrusu `else {...}`'dir.
  - Slayttaki `introduceSelf()` kodunda `"Hello, my name is " + getName()` ile `"and I have a car ..."` arasında boşluk yoktur; çıktı `...Oktay Sinanoğluand I have a car...` biçiminde bitişik çıkar (ajan çalıştırarak gördü). Okunaklı çıktı için ikinci metin `" and I have a car ..."` diye başlamalıdır.
  - `nyp03b`'deki `setCar` metoduna `null` verilirse `car.getOwner()` `NullPointerException` verir; derste bu durum konuşulmadı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
