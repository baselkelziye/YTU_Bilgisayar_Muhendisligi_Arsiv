# Ders 6 Çalışma Özeti

## Genel Konular

- Constructor tasarımı ve adaş (overloaded) constructor'lar
  - `Car` sınıfına `plate` alanının yanına ikinci bir `private` alan olarak şasi numarası (`chassisNR`) eklendi. Bir nesneyi tek başına tanımlayan, mutlaka anlamlı değeri olması gereken alanların hepsi aynı constructor'da parametre olarak alınmalıdır (ekrandan, 00:10:00).
  - Her alan için ayrı tek parametreli constructor yazmak iki nedenle yanlıştır: hangi constructor çağrılırsa çağrılsın öteki alan boş (`null`) kalır; ikinci constructor çağrıldığında da ilk nesne kaybolur, yepyeni bir nesne oluşur.
  - İki constructor da tek `String` parametre alırsa kod derlenmez ("duplicate" hatası), çünkü imzaları aynıdır. Parametre türleri farklıysa (biri `String`, öteki `int`) kod derlenir ama mantık hatası (bug) sürer.
  - Aynı adlı, farklı parametre listeli metotlara adaş metot (overloaded method), bu işe aşırı yükleme (overloading) denir. Bu yalnız constructor'lara değil, her metoda uygulanabilir.
  - İki alan `final` yapılırsa tek parametreli constructor'lar derleme hatası verir: öteki `final` alan ilklendirilmemiş kalır.
- UML gösteriminde constructor parametreleri
  - `+ Car(String, String)` yazmak hangi parametrenin hangi alanı ilklendirdiğini göstermez. `+ Car(plateNr : String, chassisNR : String)` biçiminde parametre adlarını da yazmak daha doğrudur.
- `main` metodunun başka bir sınıfta olması
  - `Car` sınıfında `main` yoksa sınıf tek başına çalıştırılamaz. Aynı paketteki `MainProgram` sınıfının `main` metodunda `Car` nesneleri oluşturulup `public` metotlarıyla kullanılabilir.
- İlkel türler (primitives) ve sarmalayıcılar (wrappers)
  - İlkel tür tek bir bilgi taşır, sınıf değildir. Sarmalayıcı, ilgili ilkel türden tek bir üye alan ve o türle ilgili yararlı metotlar içeren sınıftır. Sarmalayıcılar `java.lang` paketindedir.
  - Tam sayılar: `int` (4 bayt, Integer), `long` (8 bayt, Long, sabitin sonuna `L` yazılır), `short` (2 bayt, Short), `byte` (1 bayt, Byte) (ekrandan, 00:35:00).
  - Ondalıklı sayılar: `double` (daha geniş aralık, daha yüksek duyarlık, daha çok bellek, daha yavaş) ve `float` (tersi). `char` tek karakteri UTF-16 ile tutar (Character). `boolean` doğru/yanlış değeridir (Boolean).
  - İlkellerin kullanılamadığı yerlerde (serileştirme, map yapılarında anahtar) sarmalayıcılar kullanılır.
- İlkellerle işlemler
  - Aritmetik: `+ - * / %`, operatör önceliği, `++`/`--`, `++i` ile `i++` farkı (`y * ++z` ile `y * z++`), `+= -= *= /= %=` kısaltmaları; `java.lang.Math`'in statik metotları (ekrandan, 00:45:00).
  - Bit işlemleri: `& | ~ ^` (and, or, not, xor), `<< >>` kaydırma. Örnek: n'nin sağdan 4. biti `(n&8)/8` ya da `(n&(1<<3))>>3` ile bulunur.
- `Integer` sınıfının metotları
  - `compareTo(Integer)` (statik değil), `intValue()`, statik `parseInt(String)`, `toString()`, statik `toString(int)`, statik `valueOf(String)` (ekrandan, 01:10:00).
  - `parseInt` sayı olmayan bir metin alırsa `NumberFormatException` fırlatır ("A34" örneği).
  - Deprecated (kullanımdan kaldırılması önerilen) üyeler: `new Integer(1)` constructor'ı Java 9'dan beri deprecated'dır, kullanılmamalıdır.
- `String` sınıfının metotları
  - `length()`, `compareTo`, `compareToIgnoreCase`, `equals`, `equalsIgnoreCase`, `contains`, `toUpperCase`, `toLowerCase`.
  - `compareTo` sözlük sıralamasıyla karşılaştırır ve karakter kodları farkını döndürür. "A string!" ile "This is another one." karşılaştırması −19 verir (ekrandan, 01:25:00).
  - Türkçe karakterler Unicode koduna göre sıralanır; "çocuk" ile "dede" karşılaştırması 131 verir.
  - `toUpperCase`/`toLowerCase` nesnenin durumunu değiştirmez, yalnız dönüştürülmüş yeni bir metin döndürür.
  - `contains`'in büyük/küçük harf duyarsız sürümü yoktur; iki metin de büyük harfe çevrilip `contains` çağrılarak yazılabilir.
- `Math` ve `Random`
  - `Math.random()` [0.0, 1.0) aralığında `double` döndürür. `abs`, `max`, `min` her sayısal ilkel tür için adaş sürümlere sahiptir. `round`, `ceil`, `floor`, `sqrt` vardır.
  - `java.util.Random` sınıfının statik olmayan metotları: `nextBoolean`, `nextDouble`, `nextFloat`, `nextInt()`, `nextInt(bound)` (bound hariç), `nextLong` (ekrandan, 01:55:00).
- Komut satırından girdi ve çıktı
  - `System.out`, `System` sınıfının `public static` üyesidir. `print`, `println`, `printf` metotları vardır.
  - JDK 5.0'dan beri `java.util.Scanner` ile girdi alınır: `Scanner in = new Scanner(System.in);`, `nextLine`, `nextInt`, `nextFloat` vb. (ekrandan, 02:20:00).
  - `+` operatörü aşırı yüklüdür: işlenenlerden biri `String` ise birleştirme yapar. `(age + 1)` parantezsiz yazılırsa 45 ve 1 yan yana yazılır (451).
  - `nextInt` gibi bir metottan sonra `nextLine` çağrılırsa satır boş gelir; araya fazladan bir `in.nextLine()` konur.
  - Scanner nesnesi işi bitince `close()` ile kapatılmalıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Anlamlı değeri olması gereken bütün alanlar tek bir constructor'da ilklendirilmelidir.
  - Alanları ayrı constructor'lara bölmek ya derleme hatasına ya da gizli bir mantık hatasına yol açar. Derleme hatası bug'dan iyidir, çünkü hemen görülür.
- Birden çok constructor yalnız mantıklı senaryolar varsa tanımlanır.
  - Bir öğrenci sorusu üzerine: şasi numarası fabrikada verilir ve değişmez (`final`), plaka sonradan atanabilir. O zaman hem `Car(plate, chassisNR)` hem `Car(chassisNR)` mantıklıdır; plaka için setter da gerekir.
- UML şemasında constructor parametrelerinin adlarını da yazın.
- `parseInt` sayı olmayan metinde exception fırlatır; metnin içinden sayıyı ayıklamaz.
- `toUpperCase` ve `toLowerCase` nesneyi değiştirmez; sonucu kullanmak için atama yapmak gerekir (`strB = strB.toUpperCase();`).
- `Scanner` nesnesini kapatmayı unutmayın.
- İlkelden sonra metin okurken fazladan bir `nextLine()` gerekir.
- Deprecated üyeler sonraki JDK sürümlerinde bulunmayabilir, kullanılmamalıdır.

## Kısa Tekrar Notları

- Adaş metotlar: aynı ad, farklı parametre listesi. Aynı imza iki kez tanımlanamaz.
- Tek parametreli iki constructor'la "önce birini, sonra ötekini" çağırmak iki ayrı nesne üretir; ilk nesne kaybolur.
- `final` alan constructor'da mutlaka bir kez atanmalıdır.
- İlkel sınıf değildir; sarmalayıcısı genellikle adının büyük harfle başlayan hâlidir (`int` → `Integer`, `char` → `Character` istisnadır).
- `long` sabitine `L` eklenir: `long natID = 12345678900L;`.
- Sağdan 4. bit: `(n & 8) / 8` ya da `(n & (1 << 3)) >> 3`.
- `compareTo`: küçükse negatif, eşitse 0, büyükse pozitif.
- `equals`/`equalsIgnoreCase` eşitlik için `compareTo == 0`'dan daha uygundur.
- `Math.random()` → [0.0, 1.0); `Random.nextInt(10)` → 0..9.
- `"..." + (age + 1)` parantezle toplama, parantezsiz birleştirme.
- Eclipse'te Ctrl'e basılı tutup bir metodun üstüne tıklamak, metodun tanımına götürür.

## Detaylı Açıklamalar

- **Constructor'ları doğru tasarlamak.** Geçen haftaki `Car` sınıfına `chassisNR` alanı eklendi. Doğru kod tek constructor'dır: `public Car(String plateNr, String chassisNR) { plate = plateNr; this.chassisNR = chassisNR; }`. Slaytın sağındaki yanlış sürümde iki tek parametreli constructor vardır (`Car(String plateNr)` ve `Car(String chassisNR)`) ve kod "constructor Car(String) is already defined" hatasıyla derlenmez (ekrandan, 00:10:00). Derste şasi numarası geçici olarak `int` yapıldı. Bu durumda kod derlendi ama `Car aCar = new Car("34 RA 440"); aCar = new Car(3434); aCar.introduceSelf();` çıktısı `My plate is null and my chassis nr is 3434` oldu (ekrandan, 00:25:00). Yani ikinci constructor ilk nesneyi güncellemedi, yeni bir nesne yarattı. Sonra şasi numarası `final` yapıldı ve tek parametreli constructor'lar "might not have been initialized" hatası verdi. Doğrusu Eclipse'te Source → Generate Constructor using Fields ile iki parametreli constructor'ı üretmektir. Çıktı: `My plate is 34 RA 440 and my chassis nr is ASX3434` (ekrandan, 00:30:00).
- **Birden çok constructor ne zaman mantıklı?** Bir öğrenci, birden çok constructor'ın ne işe yaradığını sordu. Hoca bayi senaryosunu verdi: araç fabrikadan şasi numarasıyla çıkar; bazen plakası da hazırdır, bazen sonradan takılır. Bu durumda `Car(String plate, String chassisNR)` ve `Car(String chassisNR)` birlikte tanımlanır. `chassisNR` `final` kalır, `plate` için `setPlate` eklenir.
- **İlkel türler ve sarmalayıcılar.** Tablo (ekrandan, 00:35:00): `int` −2.147.483.648 ile +2.147.483.647; `long` yaklaşık ±9,22 × 10^18; `short` −32.768 ile +32.767; `byte` −128 ile +127. `double` yaklaşık ±10^308'e, `float` yaklaşık ±3,4 × 10^38'e kadar gider. Bu derste duyarlık önemli olmadığı için ikisinden biri seçilebilir; hoca `double` kullanıyor. `char` UTF-16 kodlamasıyla Çince, Japonca ve matematik simgelerini de destekler. <!-- BELİRSİZ: double/float/char/boolean tablosunun bulunduğu slayt 38 karelerde okunmuyor; değerler altyazıdan alındı ve Java ile doğrulandı. -->
  > **Ders sonrası not:** Hoca, sayısal ilkellerin başına `unsigned` yazılarak işaretsiz yapılabileceğini söyledi ve slayta da bu cümleyi ekledi. Doğrusu: Java'da `unsigned` anahtar sözcüğü yoktur; `byte`, `short`, `int`, `long` her zaman işaretlidir. (Java 8'den beri `Integer.toUnsignedString`, `Integer.divideUnsigned` gibi metotlarla işaretsiz yorum yapılabilir; işaretsiz olan tek ilkel 16 bitlik `char`'dır.)
- **Bit işlemleriyle 4. bit.** Hoca Excel'de 2^7 … 2^0 basamaklarını yazdı ve n = 10110101 gibi bir sayı aldı (ekrandan, 00:50:00). Sağdan 4. bit 2^3 = 8'e karşılık gelir. `n & 8` bu bit 1 ise 8, 0 ise 0 verir; 8'e bölünce bitin kendisi (1 ya da 0) bulunur. İkinci yolda maske `1 << 3` ile üretilir (00000001 → 00001000), `n` ile AND'lenir ve sonuç `>> 3` ile sağa kaydırılır. Bu örnekte iki yol da 0 verir (Java ile doğrulandı).
- **`Integer` metotları.** `Integer sarma1 = 1, sarma2 = 7;` ve `sarma1.compareTo(sarma2)` → −1 (ekrandan, 01:10:00). Derste sıra değişince +1, eşit değerlerle 0 görüldü. `Integer.parseInt("34")` 34 verir, `Integer.parseInt("A34")` ise `NumberFormatException: For input string: "A34"` fırlatır.
- **`String.compareTo` ve harf büyüklüğü.** "A string!".compareTo("This is another one.") → −19 (ekrandan, 01:25:00). Sonuç ilk farklı karakterlerin kod farkıdır: 'A' (65) − 'T' (84) = −19. Hoca bunu İngiliz alfabesinde A ile T arasındaki 19 harfle açıkladı; büyük harfler kendi aralarında sıralı olduğu için bu örnekte ikisi aynı sonucu verir. "çocuk".compareTo("dede") → 131 ('ç' = 231, 'd' = 100); Türkçe sözlük sırasında beklenen negatif sonuç çıkmaz.
  > **Ders sonrası not:** Derste bir deneme sonrası "küçük harfler daha küçüktür" denildi ve slayta "lowercase letters are smaller" yazıldı. Doğrusu tersidir: Unicode/ASCII'de büyük harfler önce gelir ('A' = 65, 'a' = 97). Örneğin "A string!".compareTo("a string!") = −32 olur, yani büyük harfle başlayan metin daha küçüktür (Java ile doğrulandı). <!-- BELİRSİZ: Derste denenen kodun tam hâli karelerde görünmüyor. -->
- **`contains` ve `toUpperCase`.** `StringOps02` örneğinin çıktısı sırasıyla `false`, `true`, `tan`, `true`, `TAN`, `false` olur (ekrandan, 01:40:00). `strB.toUpperCase();` tek başına `strB`'yi değiştirmez; `strB = strB.toUpperCase();` ataması yapılınca "TAN" küçük harfli "İstanbul" içinde bulunmaz. Büyük/küçük harf duyarsız `contains` için derste yazılan statik metot: `return str1.toUpperCase().contains(str2.toUpperCase());` (ekrandan, 01:45:00). "İstanbul" ile "TAN" için `true` verir.
- **`Math` ve `Random`.** `Math.random()` [0.0, 1.0) aralığında değer üretir. N ile çarpılarak [0, N) aralığına genişletilir. JRE, `Math.random()` için kendiliğinden bir `Random` nesnesi oluşturur ve JVM boyunca onu kullanır (ekrandan, 01:55:00). Farklı çekirdekler gerekiyorsa birden çok `Random` nesnesi oluşturulur. Örnekte `Math.abs(r.nextInt())` ile çakıl taşı sayısı, `r.nextInt(10)` ile 0-9 arasında boyanmış parmak sayısı üretildi.
  > **Ders sonrası not:** Slaytta `nextInt()` için (−2^32, 2^32) ve `nextLong()` için [0, 2^48) yazıyor. Doğrusu: `nextInt()` bütün `int` aralığını, yani [−2^31, 2^31 − 1] aralığını kapsar. `nextLong()` negatif değerler de döndürebilir; 48 bitlik çekirdek yüzünden bütün `long` değerlerini üretemez.
- **Scanner ile girdi.** `ConsoleIOv1` örneğinde ad `nextLine()` ile, yaş `nextInt()` ile okunur. Çıktı `Hello, <ad>. Next year, you'll be 46.` olur (ekrandan, 02:25:00). Hoca soruyu `print` ile soruyor ki cevap aynı satıra yazılsın. Okuma sırası değişip önce yaş okunduğunda ad boş gelir.
  > **Ders sonrası not:** Hoca bunu düzeltilmemiş bir Scanner bug'ı olarak anlattı. Aslında bu belgelenmiş bir davranıştır: `nextInt()` sayıyı okur ama satır sonu karakterini tamponda bırakır, ardından gelen `nextLine()` de o boş satırı okur. Çözüm yine derste gösterildiği gibi araya fazladan bir `nextLine()` koymaktır.
- **Kullanıcıdan plaka alan `Car`.** Slayt 52'deki sınıf `main` içinde `new Car(input.nextLine())` ile plakayı doğrudan constructor'a verir ve sonunda `input.close()` çağırır (ekrandan, 02:30:00). Girdi `34 RA 440` için çıktı `My plate: 34 RA 440` olur (ekrandan, 02:35:00). İki parametreli sürümde plaka ve şasi numarası önce iki ayrı `String` değişkene okunur, sonra constructor'a verilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
