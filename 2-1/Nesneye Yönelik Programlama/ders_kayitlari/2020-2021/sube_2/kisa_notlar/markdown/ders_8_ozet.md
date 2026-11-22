# Ders 8 Çalışma Özeti

## Genel Konular

- Java'da metot parametre aktarımı
  - C'den bilinen iki mekanizma hatırlatıldı: değerle çağırma (call by value) ve işaretçiyle, yani referansla çağırma (call by reference). Değerle çağırmada metodun içindeki değişiklik metot bitince kaybolur, referansla çağırmada kalıcı olur.
  - Java ikisinin birleşimidir: "call by value of references". İlkel türler (`int` vb.) her zaman değerle aktarılır. Nesnelerde referansın kendisi değil, değeri (kopyası) aktarılır.
  - Sonuç: çağrılan metot, nesnenin durumunu (üye alanlarını, setter'larla) kalıcı olarak değiştirebilir. Ama parametreyi `new` ile yeniden ilklendirmek ya da başka bir nesneyi göstermesini sağlamak çağıran tarafa yansımaz.
- `MethodParametersTest1` örneği (ekrandan, 00:10:00 ve 00:15:00)
  - `ilkelDuzenle(int x)` ve `sarmalayiciDuzenle(Integer x)` parametreyi bir artırır, `ilkelDegistir` ve `sarmalayiciDegistir` iki parametreyi takas etmeye (swap) çalışır, `sarmalayiciDegistirAlt` takası `new Integer(...)` ile dener, `swapForReal()` parametre almadan nesnenin kendi `wrapI` ve `wrapJ` üye alanlarını takas eder.
  - Ekrandaki çıktı (ekrandan, 00:30:00): `3/3`, `5/5`, üç kez `1, 2 / 1, 2`, son olarak `Before : 3, 5` ve `After: 5, 3`. Yalnız nesnenin kendi üye alanları üzerinde yaptığı takas kalıcıdır.
  - Sarmalayıcı (wrapper) sınıflar nesne olsa da `x++` gibi basit işlemlerde ilkel gibi davranır, değişiklik kalıcı olmaz.
  - `new Integer(x)` kurucusu "deprecated" (eskimiş) olarak işaretlidir. IDE bunu üstü çizili gösterir. Eskimiş metotlar ileriki JDK sürümlerinde kaldırılabilir, kullanılmamaları önerilir.
- Yerel değişkenin kapsamı (scope)
  - `MethodParametersTest2`'de değişiklikler metodun kendi yerel değişkenleri üzerinde yapılır ve metot içinde gerçekten geçerlidir (çıktı `1, 2` → `2, 1`, `3, 5` → `5, 3`; ekrandan, 00:25:00).
  - Bir metotta tanımlı yerel değişken başka bir metotta görülmez. Aynı adla yeniden tanımlanırsa ayrı bir değişken olur.
- `static` metot ve üye alan erişimi
  - Örnek `static` metotlara çevrilince, `static` metot içinden normal üye alana erişim derleme hatası verdi.
  - Nedeni: `static` metot nesneden bağımsız, sınıf üzerinden çağrılır. Ortada bir nesne olmadığı için hangi nesnenin üye alanına erişileceği belli değildir ve `this` de anlamsızdır.
  - `static` metot içinden ya yalnız `static` üyelere doğrudan erişilir ya da o sınıftan bir nesne oluşturulup onun üyelerine erişilir.
- Dizilerin aktarımı (`MethodParametersTest3`, ekrandan 00:35:00)
  - `LowHighSwap.doIt(int[] z)` dizinin ilk ve son elemanını takas eder. `{1, 2, 3, 4, 5}` dizisi metot dönünce `5 2 3 4 1` olur (ekrandan, 00:40:00).
  - Java'da diziler nesne gibi davranır, bu yüzden elemanlarda yapılan değişiklik kalıcıdır.
  - Bir `.java` dosyasında public olmayan başka sınıflar da tanımlanabilir, ama her sınıfı kendi dosyasında tanımlamak en doğrusudur.
- Araba nesneleriyle aktarım (`MethodParametersTest4` ve `5`, ekrandan 00:40:00 ve 00:50:00)
  - `modifyPlate(Car aCar)` içinde `aCar.setPlate("34 İS 34")` kalıcıdır. `swapPlate` iki arabanın plakasını getter ve setter ile takas eder ve bu da kalıcıdır.
  - `swapCars(Car carA, Car carB)` referansları takas etmeye çalışır (`tmp = carA; carA = carB; carB = tmp;`). Metot bitince hiçbir şey değişmez.
  - Kurucuyla yeniden oluşturarak takas (`carA = new Car(carB.getPlate())` vb.) da işe yaramaz, çünkü bu da parametrenin gösterdiği yeri değiştirmektir.
  - `System.out.println(car1)` nesneyi `nyp01a.Car@4926097b` biçiminde yazar (ekrandan, 00:50:00). Farklı nesneler farklı değer verir. `main` içinde `car1 = car2;` yazılınca iki referans aynı nesneyi gösterir ve aynı değer basılır.
- Yapısal programlama tekrarı (ekrandan, 01:10:00)
  - `if / else if / else`, karşılaştırma işleçleri (`<`, `>`, `<=`, `>=`, `==`, `!=`), mantıksal işlemlerde çift işleç (`&&`, `||`), `for`, `while`, `do-while`, `switch-case` Java'da C ile aynı söz dizimindedir.
  - Yapısal programlama temeli eksik olanlar için çok sayıda çözümlü problem içeren bir algoritma ve programlamaya giriş kitabı önerildi (Fahri Vatansever, "Algoritma Geliştirme ve Programlamaya Giriş").
- Nesneler arası ilişkiler (giriş)
  - Bir nesnenin başka bir nesnenin metodunu çağırabilmesi için aralarında ilişki olmalıdır.
  - Association (sahiplik), dependency (bağımlılık, geçici kullanma), aggregation ve composition (parça-bütün; gevşek ya da sıkı) nesne düzeyinde düşünülen ilişkilerdir. Inheritance (kalıtım) ise sınıf düzeyinde bir ilişkidir.
- Association (sahiplik) (ekrandan, 01:15:00)
  - Özü sahipliktir: mesajı gönderen nesne, alıcıyı üye alan olarak taşır. Örnek: müşteri (`Customer`) ve siparişleri (`Order`).
  - UML'de düz çizgi ve ucu açık okla gösterilir. Ok yönü hem metot çağırabilme yönünü hem de kimin kimden haberdar olduğunu gösterir: `Customer` siparişlerini bilir, `Order` kendisini veren müşteriyi bilmez.
  - Oksuz çizgi, yönün henüz kararlaştırılmadığı anlamına gelir. Şemalarda yön mutlaka gösterilmelidir.
  - Nicelik (multiplicity) çizginin uçlarında yazılır: `*` sıfır ya da daha fazla, `1..*` en az bir, `1` tam olarak bir, `0..1` sıfır ya da bir, `1..11` bir ile on bir arası.
- Gizli bilgi (hidden information) (ekrandan, 01:20:00)
  - İlişki çizgi ve okla gösterildiyse sınıfın içindeki ayrıntı yazılmayabilir. `Customer 1 → * Order` şeması, `Customer` içinde `- orders[] : Order` dizisi gösterilmiş şemayla aynıdır.
  - Ok ucunda `*` varsa okun çıktığı sınıfta, baktığı türden bir dizi bulunmak zorundadır. Ok ucunda `2` varsa o türden iki üye alan bulunur.
- Dependency (bağımlılık) (ekrandan, 01:20:00)
  - Kesikli çizgi ve ucu açık okla gösterilir. A'da B türünden üye alan yoktur, ama A'nın bir metodu B türünden parametre alır (`+ aMethod(b : B)`) ya da metot gövdesinde geçici bir B nesnesi oluşturur.
  - Örnek: `main` metodu içinde `Car` nesneleri oluşturan sınıf ile `Car` arasındaki ilişki.
  - Hem association hem dependency kod bağımlılığı doğurur: A'yı kullanan yere B de eklenmelidir (import).
- Tek yönlü association örneği: `Person` ve `Car` (ekrandan, 01:25:00)
  - Her kişinin en fazla bir arabası olabilir: `Person 1 —owns→ 0..1 Car`. `Person`'da `name` ve `car` üye alanları, `Person(String name)` kurucusu, `getName`, `getCar`, `setCar`, `introduceSelf(): String` metotları vardır.
  - `Car`'da tek üye alan `plate` (plaka), kurucu `Car(String)` ve `getPlate()` vardır. Kurucunun aldığı `String` plakadır.
  - `MainProgram01` ile `Person` ve `Car` arasında dependency vardır.
- `introduceSelf` artık ekrana yazmak yerine bir `String` döndürür
  - Böylece iş mantığı ile sunum (girdi/çıktı) katmanı ayrılır. Dönen metin ekrana, dosyaya, ağa ya da bir pencereye istenildiği gibi gönderilebilir.
- `null` kontrolü (ekrandan, 01:50:00)
  - Arabası olmayan kişinin `introduceSelf` metodu `car.getPlate()` çağırınca `NullPointerException` oluşur ve program akışı durur.
  - Çözüm: `if( car != null )` ile plaka bilgisi yalnız araba varsa eklenir.
  - Bir setter yazılmış olması onun çağrılacağını garanti etmez. Garanti yalnız kurucular için verilebilir.
  - Nesnenin ilklendirilip ilklendirilmediği dört biçimde sınanabilir: `obj != null` true ya da `obj == null` false ise ilklendirilmiştir; `obj == null` true ya da `obj != null` false ise ilklendirilmemiştir.
- Sıralama şeması (sequence diagram) (ekrandan, 01:45:00, 01:50:00, 02:15:00, 02:30:00)
  - Yalnız metot çağrıları (kurucular dahil) çizilir. Yerel değişken tanımı ya da atama çizilmez.
  - `introduceSelf` şeması: `:Person` nesnesine `introduceSelf()` gelir, kendi `getName()` metodunu çağırır (kendine ok), sonra `car : Car` nesnesine `[car != null] getPlate()` gönderir, `plate` döner, en sonunda `info` döndürülür.
  - Koşula bağlı çağrının önüne koşul köşeli parantez içinde yazılır. Kısaltma yerine koşulun tam hali yazılmalıdır.
  - `MainProgram01` şeması: `main(String[])` içinde `new("Oktay Sinanoğlu")` ile `oktay : Person`, `new("34 OS 1934")` ile `rover : Car` oluşturulur, `setCar(rover)` ve `introduceSelf()` çağrılır (içinde `getName()` ve `[rover != null] getPlate()`), sonra `aziz : Person` oluşturulup `introduceSelf()` çağrılır; arabası olmadığı için yalnız `getName()` çağrılır.
  - Zaman aşağı doğru akar. İlk çağrı, çağıran metodun etkinlik çubuğunun başlangıcıyla aynı hizada değil, biraz aşağıda çizilmelidir.
- Sahip olunan nesneye iş yaptırma: `changeCarPlate` (ekrandan, 02:35:00 ve 02:40:00)
  - `Car`'a `setPlate` eklendi. `Person.changeCarPlate(String newPlate)` arabası varsa `car.setPlate(newPlate)` çağırır, yoksa ekrana hata mesajı yazar.
  - Plaka kişi üzerinden değiştirilince arabanın kendisi de yeni plakayı döndürür, çünkü ikisi aynı nesnedir: çıktı `... plate 06 ANK 06` ve `06 ANK 06`.
  - Arabası olmayan kişide `NullPointerException` olmaz, yalnız mesaj basılır ve akış sürer.

## Hocanın Özellikle Vurguladığı Kısımlar

- Java'da parametre aktarımı "call by value of references"tır
  - Nesnenin durumu başka metotta değiştirilebilir, ama referans başka bir nesneye yönlendirilemez. `swap` örnekleri bu yüzden başarısız olur.
- `static` metot içinde `this` ve normal üye alanlar kullanılamaz
  - Çünkü metot bir nesne üzerinden değil, sınıf üzerinden çağrılır.
- İlişkinin yönü mutlaka gösterilmeli
  - Sınavda verilen ya da istenen sınıf şemalarında oklar çizilmelidir. Oksuz çizgi belirsizliktir.
- Gizli bilgiyi okuyabilmek gerekir
  - Sınavlarda verilen tasarımda dizi ya da üye alan açıkça yazılmamış olabilir. Ok ucunda `*` varsa o türden bir dizi, `2` varsa iki üye alan kodlanmalıdır.
- `null` kontrolü mutlaka yapılmalı
  - `0..1` gibi isteğe bağlı ilişkilerde üye alan `null` olabilir. Metodunu çağırmadan önce kontrol edilmelidir.
- Sıralama şeması dersin parçasıdır
  - Bir metodun şemasının çizilmesi ya da verilen şemaya göre kodlanması istenebilir. Elle çizerken çağrılar arasında dikey boşluk bırakılmalıdır.

## Kısa Tekrar Notları

- İlkel → her zaman değerle aktarılır. Nesne → referansın değeri aktarılır.
- Metot içinde nesnenin durumunu değiştirmek kalıcıdır. Parametreye yeni nesne atamak kalıcı değildir.
- Sarmalayıcı (`Integer`) `x++` ile değişmez, ilkel gibi davranır.
- Diziler nesne gibi davranır, eleman değişiklikleri kalıcıdır.
- `static` metotta `this` yok. Normal üyeye erişmek için nesne oluşturulur.
- Association: düz çizgi + açık ok, üye alanla sahiplik. Dependency: kesikli çizgi + açık ok, parametre ya da geçici yerel nesne.
- Aggregation/composition: parça-bütün, bütün tarafında içi boş ya da dolu elmas.
- Kalıtım sınıf düzeyinde, diğerleri nesne düzeyinde düşünülür.
- Nicelik: `*`, `1..*`, `1`, `0..1`, `1..11`. `*` → dizi.
- `introduceSelf` bir `String` döndürür, böylece iş mantığı ve sunum ayrılır.
- Sıralama şemasında koşullu çağrı: `[car != null] getPlate()`.

## Detaylı Açıklamalar

Dersin ilk yarısı Java'nın parametre aktarma biçimine ayrıldı. Hoca, C'de değerle ve işaretçiyle aktarımı hatırlattıktan sonra Java'nın "call by value of references" kuralını şöyle özetledi: ilkel bir değişken metoda verilince metodun içinde ne yapılırsa yapılsın çağıran taraftaki değer değişmez. Nesne verilince çoğu zaman referansla aktarım gibi davranır: setter ya da durum değiştiren başka bir metot çağrılırsa değişiklik kalıcıdır. Fark, metodun içindeki parametre değişkeninin başka bir nesneyi göstermesi sağlandığında ortaya çıkar. Ne `carA = carB` gibi bir atama ne de `carA = new Car(...)` gibi yeniden ilklendirme çağıran taraftaki referansı etkiler, çünkü metoda referansın kendisi değil kopyası gelmiştir.

Bunu göstermek için `MethodParametersTest1` sınıfı çalıştırıldı (ekrandan, 00:15:00):

```java
@SuppressWarnings("all")
public class MethodParametersTest1 {
    private Integer wrapI, wrapJ;
    public void ilkelDuzenle( int x ) { x++; }
    public void sarmalayiciDuzenle( Integer x ) { x++; }
    public void ilkelDegistir( int x, int y ) {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }
    public void sarmalayiciDegistir( Integer x, Integer y ) {
        Integer temp; temp = x; x = y; y = temp;
    }
    public void sarmalayiciDegistirAlt(Integer x, Integer y) {
        Integer temp;
        temp = new Integer(x);
        x = new Integer(y);
        y = new Integer(temp);
    }
    public void swapForReal( ) {
        Integer temp = wrapI;
        wrapI = wrapJ;
        wrapJ = temp;
    }
    public static void main(String[] args) {
        MethodParametersTest1 test = new MethodParametersTest1();
        test.tryMe();
    }
}
```

`tryMe` metodu her çağrıdan önce ve sonra değerleri yazdırır. Çıktıda yalnız son satır çifti değişir (`Before : 3, 5`, `After: 5, 3`), çünkü `swapForReal` parametre üzerinde değil, nesnenin kendi üye alanları üzerinde çalışır. Bir nesne kendi üyeleri üzerinde her türlü değişikliği yapabilir. <!-- BELİRSİZ: tryMe metodunun gövdesinin yalnız ilk kısmı karelerde görünüyor (ekrandan, 00:25:00); takas çağrılarının yer aldığı son kısım çıktı ve anlatımdan anlaşılıyor. -->

Dizilerde durum farklı görünür: `LowHighSwap.doIt` dizinin ilk ve son elemanını takas eder ve `main` dönüşte `5 2 3 4 1` yazar. Bu çelişki değildir; dizi bir nesnedir ve metot dizinin durumunu (elemanlarını) değiştirmiştir, dizi referansını başka bir yere yönlendirmemiştir.

İkinci yarıda nesneler arası ilişkilere geçildi. Association bir nesnenin diğerini üye alan olarak taşımasıdır ve UML'de düz çizgiyle, ucu açık okla çizilir. Dependency'de üye alan yoktur; bağımlı sınıfın bir metodu öbür türden parametre alır ya da metot içinde geçici olarak öbür türden nesne oluşturur. Bu ilişki kesikli çizgiyle gösterilir. `Person 1 → 0..1 Car` örneğinde `0..1`, kurucunun araba almamasından ve kişinin arabasız olabilmesinden gelir. Bu tasarımın doğal sonucu `car` üye alanının `null` kalabilmesidir. Bu yüzden `introduceSelf` içinde `if( car != null )` kontrolü zorunlu oldu:

```java
public String introduceSelf( ) {
    String info = "My name is " + getName();
    if( car != null )
        info += " and I have a car with plate "
                + car.getPlate();
    return info;
}
```

(ekrandan, 02:35:00)

Aynı metodun sıralama şemasında `getName()` her zaman, `getPlate()` ise yalnız `[car != null]` koşulu sağlanınca çağrılır. Koşul, çağrı okunun üstüne köşeli parantez içinde yazılır. Dersin sonunda kişinin sahip olduğu arabaya iş yaptırmak için `changeCarPlate` eklendi. Bu metot arabanın kendi `setPlate` metodunu çağırdığından değişiklik hem kişi üzerinden hem doğrudan araba üzerinden aynı görünür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
