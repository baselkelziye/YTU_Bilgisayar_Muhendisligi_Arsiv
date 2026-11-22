# Ders 20 Çalışma Özeti

## Genel Konular

- Uygulama oturumunun kapsamı
  - Son uygulama oturumunda dört konu Eclipse üzerinde hazır örneklerle gösterildi: tip dönüşümleri (type casting), dosya işlemleri ve nesne serileştirme, iç sınıflar (inner class) ve thread'lere giriş.
- İlkel tiplerde tip dönüşümü (primitive casting)
  - Ekrandaki sıralama yorumu: `byte -> short -> char -> int -> long -> float -> double` (ekrandan, 00:10:00). Sağa doğru gidiş genişletmedir (widening), sola doğru gidiş daraltmadır (narrowing).
  - Genişletme otomatik yapılır: `int x = 5; double y = x;` ile `y` ekrana `5.0` yazılır (ekrandan, 00:10:00).
  - `char c = 'A'; int c_i = c;` ASCII karşılığını verir: `65` (ekrandan, 00:10:00).
  - Daraltma elle yapılır ve veri kaybı olur: `double a = 7.8;` değeri `(int)` ile dönüştürülünce ondalık kısım atılır, sonuç `7` olur.
  - String'den sayıya dönüşüm "parse" ile yapılır: `Double.parseDouble("80")` → `80.0`, `Integer.parseInt("80")` → `80` (çıktılar ekrandan, 00:10:00). Ondalıklı bir metin `parseInt` ile tamsayıya çevrilemez.
- Nesnelerde tip dönüşümü (object casting)
  - Dönüşümde nesnenin kendisi değil, onu gösteren referansın tipi değişir. Yalnız aralarında kalıtım ilişkisi olan sınıflar arasında yapılabilir.
  - Örnek sınıflar: `Animal` ve `Animal`'dan türeyen `Cow`; ikisinde de `toString()` ve `myMethod()` var (ekrandan, 00:15:00).
  - Upcasting (çocuktan ebeveyne): `anim = (Animal) daisy;`. Parantezli tip yazmak şart değildir. Sonrasında `anim` yazdırılınca "This is a Cow", `anim.myMethod()` ile "running Cow's method." çıkar (ekrandan, 00:20:00).
  - Downcasting (ebeveynden çocuğa): `Animal` tipinde ama `new Cow()` ile üretilmiş bir referans `(Cow)` ile `Cow` referansına atanır; burada parantezli tip zorunludur.
- Bir dosyada birden çok sınıf
  - Bir `.java` dosyasında yalnız bir `public` sınıf olabilir ve dosya adını o verir. Aynı dosyaya erişim belirteci yazılmamış (default, paket erişimli) başka sınıflar da konabilir; bunlara aynı paketteki sınıflardan erişilir.
- Dosya işlemleri (`java.io`)
  - Dosya işlemleri denetlenen (checked) `IOException` fırlattığı için ya `try-catch` içine alınır ya da metoda `throws` eklenir.
  - Oluşturma: `File myObj = new File("dosyam.txt");` ve `myObj.createNewFile()`; dosya yoksa `true` döner ve dosya oluşur, varsa `false` döner ("File already exists.") (ekrandan, 00:25:00). Yol verilmezse dosya proje klasörüne yazılır; tam yol ya da `new File(yol, ad)` biçimi de kullanılabilir.
  - Yazma: `FileWriter myWriter = new FileWriter("dosyam.txt"); myWriter.write(...); myWriter.close();` (ekrandan, 00:30:00).
  - Okuma: `Scanner` nesnesi `File` üzerinden kurulur; `while (myReader.hasNextLine())` döngüsünde `nextLine()` ile satır satır okunur, sonra `close()`. Dosya bulunamazsa istisna fırlar.
  - Silme: `myObj.delete()` başarılıysa `true` döner; ekranda "Deleted the file: dosyam.txt" çıktısı görülür (ekrandan, 00:35:00).
- Serileştirme (serialization) ve geri okuma (deserialization)
  - Nesne bayt dizisine çevrilip dosyaya yazılır; geri okumada bayt dizisinden yeniden nesne kurulur.
  - Sınıfın `java.io.Serializable` arayüzünü gerçeklemesi gerekir. `serialVersionUID` alanı yazılmazsa Eclipse uyarı verir; bu bir hata değildir, alan eklenerek ya da `@SuppressWarnings` ile kapatılabilir.
  - `Employee` sınıfı: `name`, `address`, `transient int SSN`, `number` alanları ve `toString()` (ekrandan, 00:35:00).
  - Yazma: nesneler bir `LinkedList<Employee>` içine konur; `FileOutputStream` → `ObjectOutputStream` zinciri kurulur, `out.writeObject(listem)` çağrılır, önce `out` sonra `fileOut` kapatılır (ekrandan, 00:40:00). Uzantının (`.ser`, `.dat`) bir önemi yoktur; dosya metin düzenleyicide anlamlı okunmaz.
  - Okuma: `FileInputStream` → `ObjectInputStream`; `(LinkedList<Employee>) in.readObject()` ile dönen `Object` uygun tipe dönüştürülür. `IOException` ve `ClassNotFoundException` yakalanır (ekrandan, 00:45:00 ve 00:50:00).
  - Okunan listede `SSN` değerleri `0` gelir, çünkü `transient` alanlar serileştirilmez ve geri okumada varsayılan değeri alır (ekrandan, 00:50:00).
- Varsayılan değerler
  - Atanmamış alanlarda `int` için `0`, `boolean` için `false`, nesne referansı için `null` vardır.
- İç sınıflar (inner class)
  - Bir sınıfın içine başka sınıf yazılabilir. Statik olmayan iç sınıfın nesnesi dış sınıfın bir nesnesi üzerinden üretilir: `OuterClass.InnerClass myInner = myOuter.new InnerClass();`.
  - Statik iç sınıf için dış sınıf nesnesi gerekmez: `OuterClass2.InnerClass2 myInner = new OuterClass2.InnerClass2();` (ekrandan, 01:00:00).
  - İç sınıfın metodu dış sınıfın alanına doğrudan erişebilir (`return x;` dış sınıftaki `x`'i döndürür).
- Thread'lere giriş
  - Thread'ler nesnelerin işlerini sırayla değil aynı anda yürütmeyi sağlar; işler paralel ilerlediği için toplam süre kısalabilir.
  - Birinci yol: `Thread` sınıfını `extends` edip `run()` metodunu override etmek (ekrandan, 01:05:00 ve 01:10:00).
  - İkinci yol: `Runnable` arayüzünü `implements` etmek; nesne `new Thread(i1)` içine verilip `t1.start()` çağrılır (ekrandan, 01:15:00).
  - `start()` thread'i başlatır ve `run()` gövdesi ayrı akışta çalışır. `run()` doğrudan çağrılırsa sıradan bir metot çağrısı olur.
  - Ortak `static int sayi = 5` iki thread tarafından artırıldığında çıktılar her çalıştırmada değişebilir; ekranda iki satır da "sayı değeri artık= 7" yazdı (ekrandan, 01:15:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Daraltma dönüşümü riskli
  - Ondalık kısım sessizce atılır (7.8 → 7); bu yüzden daraltmada dikkatli olunmalıdır, genişletme ise güvenle yapılır.
- Downcasting'de parantezli tip zorunlu
  - Upcasting'de `(Animal)` yazılmasa da kod çalışır; downcasting'de hedef sınıf parantez içinde yazılmalıdır.
- Output yazmak, input okumak içindir
  - `OutputStream` ile dosyaya yazılır, `InputStream` ile dosyadan okunur. Bu ikisi sık karıştırılır.
- Birden çok nesneyi tek bir liste içinde yazmak
  - Nesneleri tek tek yazıp okumak yerine bir `LinkedList` içinde tek nesne olarak yazmak, okurken listeyi gezmeyi kolaylaştırır.
- `transient` alan dosyaya yazılmaz
  - Geri okunduğunda varsayılan değerini alır; Eclipse `toString` üretirken bu alanı ayrıca işaretler.
- `start()` ile `run()` farkı
  - Thread davranışı için `start()` çağrılır; `run()` çağrısı paralellik sağlamaz.
- `Runnable` gerçeklemek daha esnek
  - Bir sınıfın tek `extends` hakkı vardır; `Thread`'i genişletince başka sınıftan kalıtım alınamaz. `Runnable` gerçekleyen sınıf bu hakkı korur ve başka arayüzleri de virgülle ekleyebilir.

## Kısa Tekrar Notları

- Genişletme otomatik (`int` → `double`), daraltma elle ve kayıplı (`(int) 7.8` → `7`).
- `char` → `int` ASCII kodunu verir (`'A'` → `65`).
- `Double.parseDouble`, `Integer.parseInt` metinden sayı üretir.
- Nesne dönüşümü yalnız kalıtım hiyerarşisinde; referansın tipi değişir, nesne değişmez.
- Upcast sonrası çağrılan override edilmiş metot gerçek nesnenin (Cow) metodudur.
- `File.createNewFile()`, `FileWriter.write()`, `Scanner.hasNextLine()/nextLine()`, `File.delete()`.
- Serileştirme: `Serializable` + `ObjectOutputStream.writeObject`; geri okuma: `ObjectInputStream.readObject` + tip dönüşümü.
- `transient` alan serileştirilmez → `int` için `0` gelir.
- Statik olmayan iç sınıf: `dis.new Ic()`; statik iç sınıf: `new Dis.Ic()`.
- Thread: `extends Thread` ya da `implements Runnable`; her ikisinde `run()` override, başlatma `start()`.

## Detaylı Açıklamalar

- **İlkel dönüşümler.** Java'da daha dar bir tipten daha geniş bir tipe atama (örneğin `int` → `double`, `char` → `int`) derleyici tarafından otomatik yapılır ve bilgi kaybı olmaz. `int x = 5; double y = x;` sonrası `y` değeri `5.0` olarak yazılır. `char` bir tamsayı koduna karşılık geldiği için `'A'` bir `int` değişkene atanınca `65` elde edilir. Tersi yönde, örneğin `double a = 7.8;` değerini `int`'e çevirmek için `(int) a` yazılması gerekir; ondalık kısım yuvarlanmadan atılır ve sonuç `7` olur. Metin içindeki sayıyı kullanmak için sarmalayıcı sınıfların parse metotları kullanılır: `"80"` metni `Double.parseDouble` ile `80.0`, `Integer.parseInt` ile `80` olur. Metin ondalıklıysa `parseInt` başarısız olur.

> **Ders sonrası not:** Ekrandaki `byte -> short -> char -> int -> long -> float -> double` sıralamasında `short` ile `char` arasında otomatik genişletme yoktur (`char` işaretsiz, `short` işaretlidir; birbirine dönüşüm elle yapılır). Doğru zincirler büyük olasılıkla `byte -> short -> int -> long -> float -> double` ve `char -> int -> ...` biçiminde düşünülmelidir. Ayrıca `Integer.parseInt("80.5")` çağrısı `NumberFormatException` fırlatır (Java 25 ile denendi).

- **Nesne dönüşümleri.** `Cow`, `Animal`'dan türer ve iki sınıf da `toString()` ile `myMethod()` metotlarını tanımlar. `Cow daisy = new Cow();` ve `Animal anim = new Animal();` ayrı ayrı yazdırılınca kendi metinlerini verir. `anim = (Animal) daisy;` atamasından sonra `anim` artık bir `Cow` nesnesini gösterir; bu yüzden yazdırıldığında "This is a Cow", `myMethod()` çağrısında "running Cow's method." çıkar. Downcasting'de `Animal` tipinde tanımlanıp `new Cow()` ile üretilen bir referans `(Cow)` ile `Cow` referansına atanır ve iki referans da aynı `Cow` nesnesini gösterir.

> **Ders sonrası not:** Derste upcasting için "üst sınıf alt sınıfın metotlarını kazanır, genişler" dendi. Doğrusu: upcast edilen referansla yalnız `Animal`'da tanımlı üyeler çağrılabilir; "running Cow's method." çıkmasının nedeni dinamik bağlama, yani override edilmiş metodun gerçek nesnenin sınıfından çalışmasıdır. Gerçek nesnesi `Animal` olan bir referansı `(Cow)` ile dönüştürmek çalışma anında `ClassCastException` verir (Java 25 ile denendi).

- **Dosya işlemleri.** `File` nesnesi bir dosya yolunu temsil eder; `createNewFile()` dosya yoksa oluşturup `true`, varsa `false` döndürür. Yol verilmezse dosya proje klasörüne yazılır. `FileWriter` ile dosyaya metin yazılır ve iş bitince `close()` çağrılır. Okuma için `Scanner`, `File` nesnesi üzerinden kurulur ve `hasNextLine()` doğru olduğu sürece `nextLine()` ile satırlar alınır. `delete()` dosyayı siler ve başarı durumunu `boolean` olarak döndürür. Bu metotların çoğu denetlenen istisna fırlattığı için `try-catch` kullanılır.
- **Serileştirme.** `Employee implements java.io.Serializable` olan sınıfın nesneleri bir `LinkedList<Employee>` içine konur. `FileOutputStream("myfile.ser")` üzerine `ObjectOutputStream` kurulur ve `writeObject(listem)` ile liste tek nesne olarak yazılır. Geri okumada `FileInputStream` ve `ObjectInputStream` ile `readObject()` çağrılır; dönen değer `Object` olduğu için `(LinkedList<Employee>)` ile dönüştürülür. Liste for-each ile gezilip yazdırıldığında `SSN` alanları `0` görünür, çünkü bu alan `transient` tanımlanmıştır ve dosyaya hiç yazılmamıştır. Akışlar iç içe tek satırda (`new ObjectInputStream(new FileInputStream(...))`) da kurulabilir; dıştaki akış kapatılınca içteki de kapanır.
- **İç sınıflar.** `OuterClass` içinde `InnerClass` tanımlandığında iç sınıfın nesnesi dış sınıf nesnesine bağlıdır: önce `OuterClass myOuter = new OuterClass();`, sonra `OuterClass.InnerClass myInner = myOuter.new InnerClass();`. İç sınıf `static` yapılırsa statik metotlarda olduğu gibi dış nesneye gerek kalmaz: `new OuterClass2.InnerClass2()`. Statik olmayan iç sınıfın metodu, kendi içinde olmayan `x` alanını dış sınıftan okuyabilir.
- **Thread'ler.** Normalde metotlar satır satır, biri bitince öteki başlayacak biçimde çalışır. Nesneleri thread hâline getirmek işlerin aynı anda başlamasını sağlar. `Increaser2 extends Thread` sınıfında `run()` içinde `add()` çağrılır; `add()` ortak `static int sayi` değerini bir artırıp ekrana yazar. `i1.start(); i2.start();` ile iki thread art arda başlatılır. İki thread de artırmayı yazdırmadan önce yapabildiği için iki satırda da `7` görülebilir; başka bir çalıştırmada sıra ve değerler farklı çıkabilir. `Runnable` yolunda sınıf aynıdır, yalnız `implements Runnable` yazılır ve nesne bir `Thread` nesnesine verilerek başlatılır. Bu yol sınıfın tek kalıtım hakkını boşa harcamadığı için tercih edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
