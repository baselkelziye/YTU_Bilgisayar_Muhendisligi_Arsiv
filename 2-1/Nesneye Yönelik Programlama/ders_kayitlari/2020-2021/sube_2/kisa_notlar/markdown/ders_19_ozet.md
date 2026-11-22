# Ders 19 Çalışma Özeti

## Genel Konular

- Tip dönüşümü (typecasting)
  - Alt sınıftan üst sınıfa (ya da sınıftan gerçeklediği arayüze) dönüşüm otomatik ve güvenlidir; veri kaybı olmaz.
  - Ters yöndeki dönüşüm (üst sınıf/arayüz işaretçisinden alt sınıf türüne) risklidir, elle yazılır. Önce `instanceof` ile tür kontrolü yapılır, sonra `((Tür) isaretci)` biçiminde dönüştürülür.
  - Örnek: `MarketShelf` sınıfı `LinkedList<Item>` tutar. `Item` boş bir arayüzdür. `Food` ve `Electronics` bu arayüzü gerçekler. Yalnız `Food` nesnelerinin son kullanma tarihi vardır.
  - `printExpiredItems()` her öğe için `item instanceof Food` kontrolü yapar, sonra `((Food)item).isExpired()` çağırır. Bayrak değişkeni hiç süresi geçmiş öğe yoksa "All items are fresh!" yazdırmak için kullanılır.
- `Calendar` ve `Date` sınıfları (`java.util`)
  - `Calendar.getInstance()` bir factory (fabrika) metottur: nesne constructor ile değil, bir statik metotla üretilir.
  - `add(Calendar.DAY_OF_MONTH, 1)` tarihe bir gün ekler; ay sonu taşmasını kendisi düzeltir (31 Mayıs + 1 gün = 1 Haziran).
  - `set(Calendar.YEAR, ...)`, `set(Calendar.MONTH, ...)`, `set(Calendar.DATE, ...)` ile alanlar ayarlanır. Aylar 0'dan, günler 1'den sayılır (Ocak = 0).
  - `getTime()` takvimin gösterdiği anı `Date` olarak verir. `new Date()` şu anki zamanı verir. İki tarih `before` ve `after` ile karşılaştırılır.
- Typecasting eleştirisi
  - Typecasting "gerekli bir kötülüktür" (necessary evil). Sık yapılıyorsa tasarımda eksiklik vardır.
  - Generics gelmeden önce koleksiyonlar `Object` tuttuğu için sık sık dönüşüm gerekiyordu. Bugün zorunlu kaldığımız yer deserialization'dır.
  - Daha iyi tasarım: `getExpireDate()` ve `isExpired()` arayüze konur; `Electronics` bunları anlamlı sabit değerlerle (örneğin `return false`) gerçekler. Ortak alanlar varsa arayüz yerine soyut üst sınıf kullanılabilir.
- Dosyalarla çalışma: ilgili istisnalar
  - `IOException` (genel G/Ç istisnası, checked), alt sınıfları `EOFException` ve `FileNotFoundException`.
  - `SecurityException` ise `RuntimeException` alt sınıfıdır (unchecked); yetki olmadığında oluşur.
  - Özel istisnayı ayrı bildirmek istiyorsak alt sınıf (`EOFException`) önce, üst sınıf (`IOException`) sonra yakalanır.
- Dosya işlemlerinin iki grubu
  - Dosya yönetimi: dosya/klasör oluşturma, adlandırma, silme (`java.io.File`).
  - G/Ç işlemleri: akışlar (stream) üzerinden okuma/yazma. Akış dosya, bellek, komut satırı ya da ağ bağlantısı olabilir; hepsi aynı biçimde kodlanır.
- `java.io.File` sınıfı
  - Aynı sınıf hem dosyayı hem klasörü temsil eder; `isFile()` ile ayırt edilir.
  - `File` nesnesi oluşturmak diskte dosya oluşturmak demek değildir; `exists()` ile kontrol, `createNewFile()`/`mkdir()`/`mkdirs()` ile gerçek oluşturma yapılır.
  - Constructor'lar: `File(String fileName)`, `File(String path, String name)`, `File(File path, String name)`. Tam yol taşınabilirliği bozar; göreli yol IDE'ye göre farklı klasörü gösterebilir.
  - Yol ayırıcı: Windows `\` (Java string'inde `\\`), Unix `/`. Taşınabilirlik için `File.separator` ve `File.separatorChar`.
  - Diğer metotlar: `getParentFile()`, `getCanonicalPath()` (`IOException` fırlatabilir), `canRead()`, `canWrite()`, `renameTo()`, `delete()`.
- Akışlar (stream)
  - İkili (binary) G/Ç hızlı ve verimlidir ama insan okuyamaz; metin G/Ç tersidir.
  - Sıralı ve rastgele erişim: disk dosyaları rastgele erişilebilir, ağ akışları erişilemez.
  - Java farklı yetenekteki akışları birbirine zincirler (chaining).
- Serileştirme (serialization) ve deserileştirme
  - Serileştirme: bellekteki nesneyi diske yazmak için bayt dizisine çevirmek. Deserileştirme: tersi.
  - Sınıf ve ilkel olmayan tüm üye alanları `java.io.Serializable` arayüzünü gerçeklemelidir. Bu arayüzün metodu yoktur (işaretleyici/marker arayüz).
  - Serileştirilmeyecek alan `transient` ile işaretlenir; geri okunduğunda değeri `null` (ya da varsayılan değer) olur.
  - `private static final long serialVersionUID = 1L;` sınıfın sürüm numarasıdır. Yazılmazsa uyarı çıkar; `@SuppressWarnings("serial")` ile gizlenebilir.
  - Yazma: `ObjectOutputStream(new FileOutputStream(dosyaAdi))` zinciri, `writeObject`. Okuma: `ObjectInputStream(new FileInputStream(dosyaAdi))` zinciri, `readObject` ve typecasting.
  - Deserileştirmede `IOException`'a ek olarak `ClassNotFoundException` da yakalanmalıdır.
- Kayıt sayısı sorunu
  - Kayıtlar sabit uzunlukta olmadığından dosya boyutundan kayıt sayısı çıkarılamaz. Dizi örneğinde kayıt sayısı önce (`Integer` olarak) yazılır, okurken önce o okunur.
  - `available()` hatalı çalışabilir, `readObject()` dosya sonunda `null` döndürmez, istisnayı döngü sonu için kullanmak istisna mantığına aykırıdır.
  - En iyi çözüm: tüm nesneleri tek bir veri yapısına (ör. `LinkedList<Contact>`) koyup onu tek seferde yazıp okumak.
- İç sınıflar (inner classes)
  - Bir sınıfın içinde sınıf tanımlanabilir. İç sınıf dış sınıfın private üyeleri dahil tüm üyelerine erişir.
  - `private` iç sınıf aynı paketteki diğer sınıflardan da gizlenir. GUI ve çok iş parçacıklı programlamada anonim iç sınıflar sık kullanılır.
  - İç sınıf nesnesi bir dış sınıf nesnesine bağlıdır: `kisi.new Employee(10000)`.
  - `public` iç sınıfı başka sınıfta kullanmak için `import paket.Person.Employee;` gerekir (aynı pakette bile).
  - Dış sınıfın bir metodu (`enlist`) üzerinden private iç sınıfa erişim; iç sınıftan bağlı dış nesneye `Person.this` ile ulaşılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Typecasting'i mümkün olduğunca az kullanın
  - Sık typecasting tasarımın daha iyi yapılabileceğini gösterir. Hoca typecasting'li tasarım yerine, `Electronics` sınıfında küçük bir pürüz (boş gövdeli set metodu ya da sabit `false` dönen metot) bulunan typecasting'siz tasarımı tercih ettiğini söyledi.
- Dönüşüm sözdizimi
  - `((Food)item).isExpired()`: tür adı parantez içinde, sonra tür ve işaretçi birlikte yeniden paranteze alınır; ancak ondan sonra nokta ile alt türün metotlarına erişilir.
  - Geriye uyumluluk (backwards compatibility) istiyorsanız dönüşümü uzun biçimde açıkça yazın.
- `Calendar`'da aylar 0'dan başlar
  - 13 Ocak 2010 için `YEAR 2010`, `MONTH 0`, `DATE 13` verilmelidir.
- `File` nesnesi gerçek dosya değildir
  - Hem dosya hem klasörü temsil eder; nesne oluşturmak diskte bir şey oluşturmaz.
- Serileştirme ön koşulu
  - Serileştirilen nesne ve ilişkili tüm sınıflar (A→B ilişkisinde hem A hem B) `Serializable` olmalıdır; veri yapısı kullanılsa bile bu kural geçerlidir.
- İstisna mekanizması akış kontrolü için değildir
  - Dosya sonunu istisna ile yakalayıp döngüyü bitirmek tercih edilmez.
- İç sınıfı public mi private mi yapacağınız önemli bir karardır
  - Public iç sınıfın normal sınıftan pek farkı yoktur; private iç sınıf erişimi tamamen dış sınıf üzerinden kontrol etmeyi sağlar.
- Uyarıları topluca kapatmayın
  - `@SuppressWarnings("all")` gösterildi ama uyarılar gözden kaçan bir şeyin işareti olabileceği için kullanılmaması istendi.

## Kısa Tekrar Notları

- Yukarı dönüşüm otomatik ve güvenli; aşağı dönüşüm `instanceof` kontrolü + `((Tür)ref)` ile elle.
- `instanceof` küçük harfle yazılır; solunda işaretçi, sağında sınıf/arayüz/enum adı vardır.
- `Calendar.getInstance()` factory metottur. `add`, `set`, `getTime` kullanılır. Ay 0'dan başlar.
- `Date`: `new Date()` şu an; `before`/`after` karşılaştırma. `Date`'in tarih aritmetiği metotları deprecated'dır.
- Typecasting bugün yalnız deserialization'da zorunludur.
- `IOException` ⊃ `EOFException`, `FileNotFoundException`; `SecurityException` unchecked.
- `File`: `exists`, `isFile`, `getParentFile`, `getCanonicalPath`, `canRead`, `canWrite`, `createNewFile`, `mkdir`, `mkdirs`, `renameTo`, `delete`.
- Windows yolunda string içinde `\\`; taşınabilirlik için `File.separator`.
- Binary hızlı/verimli, okunamaz; metin tersi.
- Serileştirme: `Serializable` (marker), `serialVersionUID`, `transient`, `ObjectOutputStream` + `FileOutputStream`, `writeObject`.
- Deserileştirme: `ObjectInputStream` + `FileInputStream`, `readObject` + cast, `IOException` ve `ClassNotFoundException`.
- Kayıt sayısını önce yaz ya da tek bir koleksiyonu serileştir (daha iyi).
- İlkel değer `writeObject`'e verilince otomatik olarak sarmalayıcıya (`Integer`) çevrilir (autoboxing).
- Aynı işlemi yapan catch blokları `catch (IOException | ClassNotFoundException e)` ile birleştirilebilir.
- Metin dosyası: okuma `FileReader` + `BufferedReader`, yazma `FileWriter`.
- İç sınıf: dış sınıfın private üyelerine erişir; nesnesi `dis.new Ic(...)` ile; dış nesneye `DisSinif.this` ile ulaşılır.

## Detaylı Açıklamalar

- Typecasting örneği (MarketShelf)
  - Markette satılan ürünler `Item` arayüzüyle temsil edilir. Bu tasarımda `Item` arayüzünde son kullanma tarihiyle ilgili hiçbir metot yoktur (UML notu: "some methods excluding expiration operations"). `Food` sınıfı `expireDate : Date` alanına, constructor'a, `getExpireDate()` ve `isExpired()` metotlarına sahiptir. `Electronics` ise bozulmaz. Bu yüzden rafta dolaşırken her öğenin gerçekte `Food` olup olmadığı `instanceof` ile sorulur ve olumluysa `Food` türüne çevrilip `isExpired()` çağrılır (ekrandan, 00:20:00).
  - `isExpired()` içinde `Date today = new Date();` ile şu an alınır; `expireDate.before(today)` doğruysa ürünün süresi geçmiştir (ekrandan, 00:30:00).
  - `main` içinde `Calendar` ile bir gün sonrası (`future`) ve 13 Ocak 2010 (`past`) hazırlanır; biri geçmiş, biri gelecek tarihli iki `Food` ve bir `Electronics` rafa eklenir (ekrandan, 00:25:00). Programın çıktısında süresi geçmiş öğe olarak yalnız 2010 tarihli gıda listelenir; tüm öğe listesinde iki gıda ve "An electronic item" görünür (ekrandan, 00:35:00).
  - Hoca Eclipse'te `instanceof` kontrolünden sonra, cast yazmadan `item.` dediğinde `isExpired` önerisinin çıktığını gösterdi ve bunun Eclipse'in mi yoksa yeni JDK'nın mı özelliği olduğundan emin olmadığını söyledi.
  - Ders sonrası not: Java'da `instanceof` kontrolünden sonra da `item.isExpired()` doğrudan derlenmez ("cannot find symbol"; Java 25 ile denendi). Görülen öneri büyük olasılıkla Eclipse'in cast'i kendisi ekleyen kod tamamlama özelliğidir. Java 16'dan beri `if (item instanceof Food f) f.isExpired();` biçiminde desen eşleme (pattern matching) ile değişken tanımlanabilir.
- Factory metot tartışması
  - `Date` Java 1.0'dan beri vardır ve tarih aritmetiği yapabiliyordu, ama bu metotlar sorunlu olduğu için deprecated edildi. Yerine `Calendar` getirildi: takvim istenen ana ayarlanır, sonra ondan `Date` alınır. `Calendar` pek çok takvim sistemini (Miladi, Hicri, Pers vb.) destekler. Hoca, arka planda farklı takvimler için farklı sınıflar yazılmış olabileceğini, factory metodun programcıyı bu karmaşadan soyutladığını (kara kutu yaklaşımı) söyledi.
- Typecasting'siz tasarım
  - `getExpireDate()` ve `isExpired()` `Item` arayüzüne konur (ekrandan, 00:40:00). `Electronics` `isExpired()` için tek satırlık `return false` yazar. `getExpireDate()` için bir yıl sonrası ya da `null` döndürülebilir; `null` döndürülürse `NullPointerException`'a dikkat edilmeli, `Electronics`'in `toString()`'i tarihi kullanmayacak biçimde yazılmalıdır. Bir `setExpireDate` metodu gerekirse `Electronics`'te boş gövdeli olur; bu tek kusurdur. Barkod, fiyat gibi ortak alanlar varsa arayüz yerine soyut üst sınıf daha iyi olur.
- Dosya yönetimi
  - `File` sınıfı yol ve dosya adını birlikte alır. Tam yol (ör. Windows'ta sürücü harfiyle başlayan yol) kullanıldığında string içinde her ters eğik çizgi `\\` yazılmalıdır. Windows ortamında `/` yazmak da çalışır. Göreli yolda (`new File("not.txt")`) dosya o anki çalışma klasöründe aranır; Eclipse'te bu proje klasörüdür. `..` bir üst klasörü gösterir (ör. `new File("../tmp/not.txt")`).
  - `File(String path, String name)` ya da `File(File path, String name)` ile bir kök klasörün altında dosya tanımlanabilir.
  - `mkdir()` eksik üst klasörleri oluşturmaz; `mkdirs()` oluşturur. Boolean dönen metotlar işlem başarılıysa `true` döndürür.
  - Ders sonrası not: Hoca var olmayan bir dosya için `isFile()`'ın `true` döneceğini söyledi; doğrusu, dosya diskte yoksa `isFile()` da `false` döner (Java 25 ile denendi: `false false`, dosya oluşturulunca `true true`).
- Serileştirme ve sürümleme
  - `serialVersionUID` sınıfın sürümünü belirtir. Uygulamanın yeni sürümünde sınıfa ikinci telefon/e-posta gibi alanlar eklenirse, eski sürümle yazılmış dosyayı okuyan yeni sürüm sorun yaşar. Yeni kod, okunan nesnenin seri numarasına bakıp eskiyse kullanıcıyı uyararak işlemi yapmamalıdır. Eclipse'in hızlı düzeltmesi varsayılan `1L`, otomatik üretilmiş bir `long` değer ya da `@SuppressWarnings("serial")` önerir.
  - Annotation'lar `@` ile başlar; programın çalışmasına etkisi yoktur, derleyici ve araçlara verilen bildirimlerdir.
- İletişim listesi örneği
  - `Contact` sınıfı `name`, `phone`, `eMail` alanlarını tutar, `Serializable`'ı gerçekler ve `serialVersionUID = 1L` tanımlar (ekrandan, 01:25:00).
  - `CreateContacts`, Scanner ile kaç kişi girileceğini sorar, diziyi doldurur, sonra `ObjectOutputStream` ile önce `contactCount`'u, sonra her `Contact`'ı yazar (ekrandan, 01:35:00). `ShowContacts` önce `Integer`'ı, sonra o kadar `Contact`'ı okuyup yazdırır (ekrandan, 02:10:00).
  - Oluşan `contacts.dat` ikili bir dosyadır; Not Defteri'nde açıldığında `java.lang.Integer`, `nyp12a.Contact`, alan adları ve string değerleri seçilebilir ama dosya tam okunamaz (ekrandan, 02:15:00).
  - Kayıt sayısı `int` tanımlanınca da `writeObject` onu otomatik `Integer`'a çevirerek yazdı; hoca bunu dosyaları karşılaştırarak gösterdi.
  - Son sürümde kişiler bir `LinkedList<Contact>` içinde tutulur; tek `writeObject` ile yazılır, tek `readObject` ile okunup `LinkedList<Contact>`'a çevrilir.
  - Hoca `input.close()`'un `finally` bloğuna konmasının daha doğru olduğunu belirtti.
- İç sınıf örnekleri
  - `nyp13a`: `Person` içinde `private class Employee`; `Employee.toString()` dış sınıfın private `name` alanını kullanır. `main` yalnız `Person` içinde olabilir; başka bir sınıfa taşınınca "not visible" derleme hatası alınır (ekrandan, 02:30:00 ve 02:35:00).
  - `nyp13b`: iç sınıf `public` yapılır; `main` başka sınıfa taşınabilir ama `import nyp13b.Person.Employee;` gerekir.
  - `nyp13c`: iç sınıf yine `private`; `Person` içinde `private Employee employee` alanı ve `enlist(int salary)` metodu vardır. `toString()` çalışmayan kişi için yalnız adı, çalışan için adı ve maaşı yazar (ekrandan, 02:50:00).
  - `nyp13d`: iç sınıftan bağlı olduğu dış nesneye `Person.this` ile erişilir; kişi nesnesinin ve `Person.this`'in hash kodları aynı çıkar (ekrandan, 02:55:00).
  - Ders sonrası not: Hoca iç sınıfta static metot tanımlanamayacağını söyledi (slayt: "You cannot define a static method in an inner class"). Bu kural Java 15'e kadar geçerliydi; Java 16'dan beri iç sınıflar static üye tanımlayabilir (Java 25 ile denendi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
