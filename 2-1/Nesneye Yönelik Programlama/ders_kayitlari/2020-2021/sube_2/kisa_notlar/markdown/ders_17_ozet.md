# Ders 17 Çalışma Özeti

## Genel Konular

- Soyut sınıftan arayüze geçiş
  - Soyut (abstract) sınıf `abstract` anahtar kelimesiyle tanımlanır; içinde gövdesi olmayan soyut metotlar ve gövdesi dolu normal metotlar birlikte bulunabilir. Soyut metodun gövdesi alt sınıfta, o sınıfın kullanımına uygun biçimde yazılır.
  - Java'da bir sınıf yalnız bir sınıfı `extends` edebilir. Birden fazla kaynaktan metot almak (çoklu kalıtım) gerektiğinde arayüz (interface) kullanılır.
- Arayüz tanımı ve kuralları
  - `interface` anahtar kelimesiyle tanımlanır. İçindeki metotlar `abstract` yazılmadan soyuttur; yalnız ad, dönüş tipi ve parametreler yazılır.
  - Arayüzde gövdesi dolu bir metot yazmanın iki yolu vardır: metodu `default` ya da `static` yapmak. Aksi hâlde Eclipse "gövdeyi sil" ya da "default/static yap" önerir.
  - Adlandırma alışkanlığı: arayüz adının başına `I` harfi konur (`IClass`, `IClass2`).
  - Somut (concrete) sınıf, yani soyut ya da arayüz olmayan sınıf, arayüzü `implements` ile alır; birden fazla arayüz virgülle ayrılarak yazılır. Aynı sınıf bir de `extends` ile somut bir üst sınıftan kalıtım alabilir.
  - Üst sınıftan gelen metodu override etmek zorunlu değildir; arayüzden gelen soyut metotların gövdesi ise gerçekleyen sınıfta mutlaka yazılır (implement). `default` ve `static` metotların yazılması gerekmez.
  - `static` arayüz metodu nesne üzerinden değil, arayüz adıyla çağrılır: `IClass2.method4();` (ekrandan, 00:10:00).
  - İki arayüz arasında kalıtım `extends` ile kurulur.
- Dosya ve paket düzeyinde erişim
  - Bir `.java` dosyasında yalnız bir `public` sınıf olabilir ve dosyaya adını o verir; aynı dosyaya erişim belirteci yazılmamış başka sınıflar da eklenebilir.
  - Belirteç yazılmayan (default/paket erişimi) sınıf ve üyelere aynı paketteki sınıflardan erişilir.
- Koleksiyonlar (Collections) ve liste yapıları
  - Dizi baştan sabit boyutla oluşturulur. Listelere ise eleman geldikçe `add` ile ekleme yapılır; baştan boyut verilmez, sona ya da belirli bir indise eklenebilir.
  - Hiyerarşi: `Iterable` → `Collection` → `List` → `ArrayList`, `Vector`, `LinkedList`. Bunlar Java'da hazır gelen arayüz ve sınıflardır (`java.util`).
  - Tanım: `ArrayList<String> listem = new ArrayList<String>();`. Köşeli parantez içinde listenin tutacağı tip (String, Integer ya da kendi sınıfımız) belirtilir.
  - Gezme yöntemleri: for-each (`for (String obj : listem)`) ve `Iterator` (`hasNext()` ile sırada eleman olup olmadığına bakılır, `next()` ile eleman alınır).
- `ArrayList` metotları (öğrenci listesi örneği)
  - `add(nesne)`: sona ekler. `add(indis, nesne)`: belirtilen indise ekler.
  - `addAll(liste)`: başka bir koleksiyonun bütün elemanlarını ekler.
  - `remove(indis)`: o indisteki elemanı siler (indis 0'dan başlar). `removeAll(liste)`: verilen listenin elemanlarını çıkarır.
  - `retainAll(liste)`: yalnız verilen listedeki elemanları tutar, diğerlerini siler.
  - `get(indis)`: o indisteki elemanı döndürür.
  - Nesnenin ekrana anlamlı yazılması için sınıfta `toString()` override edilir (Eclipse: Source → Generate toString()).
- `LinkedList` ve `ListIterator`
  - `LinkedList<Character> harf = new LinkedList<Character>();` biçiminde tanımlanır, metotları `ArrayList` ile aynıdır.
  - Değişken üst arayüz tipiyle de tanımlanabilir: `List<Book> kitaplar = new LinkedList<Book>();`.
  - `ListIterator` (`kitaplar.listIterator()`), `hasNext()`/`next()` yanında `hasPrevious()`/`previous()` metotlarıyla geriye doğru da gezer.
- `Map` ve `HashMap`
  - Map yapıları `Collection` hiyerarşisinde değildir; veriyi anahtar–değer (key–value) çifti olarak tutar. Anahtar tekrar edemez, değerler tekrar edebilir.
  - `HashMap<Integer, String> map = new HashMap<>();`. Ekleme `put(anahtar, değer)` ile yapılır.
  - `get(anahtar)`, `size()`, `replace(anahtar, eski, yeni)`, `remove(anahtar)`, `clear()` metotları ve `entrySet()` ile `Entry` üzerinden `getKey()`/`getValue()` kullanımı.
  - `HashMap` ekleme sırasını korumaz; `LinkedHashMap` ekleme sırasını korur.
- Generics (soysal tipler)
  - Sınıf, tipini çalışma anında, nesne oluşturulurken alacak biçimde yazılır: `class Test<T, U>`.
  - Generic metot: `public static <E> void printArray(E[] inputArray)` tek bir for döngüsüyle Integer, Double ve Character dizilerini yazdırır.
- İstisnalar (exceptions)
  - Sözdizimi hataları derleyici tarafından hemen gösterilir. İstisnalar programın akışında ortaya çıkan, programcının yönetebileceği durumlardır; `Error` ise kaynak yetersizliği gibi çözülemeyecek ciddi sorunlardır. İkisi de `Throwable` sınıfından gelir.
  - `try` bloğuna hata çıkarabilecek kod, `catch` bloğuna yakalanınca yapılacak iş yazılır. İstisna yönetilirse program kalan satırları çalıştırmaya devam eder.
  - Özel istisna sınıfları: `ArithmeticException` (sıfıra bölme), `ArrayIndexOutOfBoundsException` (dizi sınırı), `NullPointerException` (null üzerinden metot çağırma). En genel olanı `Exception`'dır.
  - `printStackTrace()`: istisnanın tipini, nedenini ve satırını yazar.
  - `finally` bloğu istisna olsa da olmasa da her zaman çalışır.
  - `throw` bir satırda istisna fırlatır; `throws` metot imzasına eklenir ve metodun istisna fırlatabileceğini bildirir.
  - Checked istisnalar (örneğin `SQLException`, `IOException`) derleme anında denetlenir; ya `try-catch` içine alınmaları ya da `throws` ile bildirilmeleri gerekir. Unchecked istisnalar (`ArithmeticException`, `NullPointerException`) çalışma anında ortaya çıkar ve programcının sorumluluğundadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Arayüzde gövde yazmanın yalnız iki yolu vardır
  - Metot `default` ya da `static` yapılmadıkça arayüzde gövde yazılamaz. Ama arayüzün asıl amacı, gövdeyi gerçekleyen sınıflara bırakmaktır; bu yola çok başvurulmaz.
- "Override" yerine "implement" demek daha doğrudur
  - Arayüzdeki metotların zaten bir gövdesi yoktur; gerçekleyen sınıf var olanı ezmez, gövdeyi ilk kez yazar.
- Liste tanımında tipi belirtmek gerekir
  - `ArrayList<Student>` gibi, listenin hangi tipte veri tutacağı köşeli parantez içinde mutlaka yazılır.
- Iterator'ın konumu
  - İmleç başta hiçbir elemanı göstermez. Her `next()` çağrısından sonra iki elemanın arasında durduğu düşünülür. Sona varınca `hasNext()` false döner.
  - `hasPrevious()` iterator baştayken false döner; önce `next()` ile sona gidilirse geriye doğru gezilebilir.
- `put` aynı anahtara yeniden yapılırsa
  - Hata vermez; o anahtarın değeri yeni değerle değiştirilir.
- `replace(anahtar, eski, yeni)` bir kontrol içerir
  - Verilen eski değer gerçek değerle eşleşmezse değişiklik yapılmaz.
- Checked istisnalarda derleyici zorlar
  - Veritabanı bağlantısı ya da dosya açma gibi işlemlerde Eclipse ya `throws` eklemeyi ya da `try-catch` kullanmayı önerir.

## Kısa Tekrar Notları

- Bir sınıf tek sınıfı `extends` eder, birden çok arayüzü `implements` eder.
- Arayüz metotları gizli olarak soyuttur; gövde için `default` ya da `static` gerekir.
- `static` arayüz metodu arayüz adıyla çağrılır.
- Arayüzden arayüze kalıtım: `extends`.
- Liste: `add`, `add(i, x)`, `addAll`, `remove(i)`, `removeAll`, `retainAll`, `get(i)`.
- Gezme: for-each ya da `Iterator` (`hasNext`, `next`); `ListIterator` ile `hasPrevious`, `previous`.
- `ArrayList` indisle erişimde, `LinkedList` eleman eklemede daha hızlı olabilir.
- `HashMap`: `put`, `get`, `size`, `entrySet`, `getKey`, `getValue`, `replace`, `remove`, `clear`. Anahtar tekildir.
- Generic sınıf `class Test<T, U>`, generic metot `<E> void printArray(E[] a)`.
- `try` → `catch` (özelden genele) → `finally` (her zaman çalışır).
- `throw` satırda fırlatır, `throws` metot imzasında bildirir.
- Checked: derleme anında (SQL, IO). Unchecked: çalışma anında (aritmetik, null pointer).

## Detaylı Açıklamalar

- **Arayüz örneği.** `IClass` arayüzünde gövdesiz `method1()` ve `default` olarak gövdesi yazılmış `method2()` vardır. `IClass2` arayüzünde gövdesiz `method3()` ve `static` olarak gövdesi yazılmış `method4()` vardır. `Parent` somut bir sınıftır ve `method5()` metodunu içerir. `Child extends Parent implements IClass, IClass2` sınıfı yalnız `method1()` ile `method3()` metotlarının gövdesini yazar. `main` içinde (ekrandan, 00:10:00) `ch.method1()` Child'daki gövdeyi, `ch.method2()` arayüzdeki default gövdeyi, `ch.method3()` Child'daki gövdeyi, `IClass2.method4()` arayüzdeki static gövdeyi, `ch.method5()` ise override edilmediği için Parent'taki gövdeyi çalıştırır.
  <!-- BELİRSİZ: IClass, IClass2, Parent ve Child sınıflarının tam kodu karelerde görünmüyor; yapı altyazıdaki anlatımdan kuruldu. -->
- **ArrayList ve iki gezme yöntemi** (ekrandan, 00:25:00). Dört şarkı adı `listem.add(...)` ile eklenir. Birinci yöntemde `for (String obj : listem) System.out.println(obj);` kullanılır. İkinci yöntemde `Iterator<String> itr = listem.iterator();` oluşturulur ve `while (itr.hasNext()) System.out.println(itr.next());` ile aynı çıktı elde edilir. Hocaya göre for-each daha pratiktir.
- **Öğrenci listesi** (ekrandan, 00:30:00 ve 00:35:00). `Student` sınıfının numara, ad ve yaş alanları, getter metotları ve `toString()` metodu vardır. Üç öğrenci `stu_list` listesine, üç öğrenci de `stu_list2` listesine eklenir. `stu_list.addAll(stu_list2)` ile birinci liste 6 elemanlı olur. `remove(3)` dördüncü sıradaki elemanı (ikinci listenin ilk öğrencisini) siler ve eleman sayısı 5'e düşer. `removeAll(stu_list2)` ikinci listeden kalan iki öğrenciyi çıkarır. Yeniden `addAll` yapılıp `retainAll(stu_list2)` çağrılınca yalnız ikinci listenin üç öğrencisi kalır (ekrandan, 00:40:00). Listeyi yazdıran statik `ListeGoster(ArrayList<Student> stu)` metodu `Iterator<Student>` ile gezer ve her öğrencinin adını, numarasını ve yaşını yazar.
- **LinkedList ve ListIterator** (ekrandan, 00:40:00 ve 00:45:00). `LinkedList<Character>` listesine üç karakter eklenir ve `Iterator<Character>` ile alt alta yazdırılır. Kitap örneğinde `List<Book> kitaplar = new LinkedList<Book>();` tanımlanır. Aynı dosyadaki `Book` sınıfının alanları `private` olmadığı için `kitap.name` ve `kitap.author` ile doğrudan erişilir. `ListIterator<Book> itr = kitaplar.listIterator();` ile önce `hasNext()`/`next()` döngüsüyle sona kadar ilerlenir, sonra `hasPrevious()`/`previous()` döngüsüyle kitap adları ters sırada yazdırılır.
- **`get` ve indisli `add`.** `ogrenciler.get(0)` ilk öğrenciyi, `kitaplar.get(0)` ilk kitabı döndürür. Çıktı `Student [no=..., name=..., age=...]` biçimindedir, çünkü `toString()` override edilmiştir (ekrandan, 00:50:00). `toString()` yazılmasaydı nesnenin bellek adresini gösteren bir kod yazılırdı. `add(0, s2)` sonrasında `get(0)` artık `s2` nesnesini döndürür.
- **HashMap örneği** (ekrandan, 00:55:00 ve 01:00:00). `map.put(5, ...)`, `map.put(1, ...)` ve `map.put(17, ...)` ile üç çift eklenir. `System.out.println(map)` çıktısı `{1=..., 17=..., 5=...}` biçimindedir, yani ekleme sırasını korumaz. `map.get(5)` 5 anahtarının değerini, `map.size()` ise 3 döndürür. `for (Entry<Integer, String> m : map.entrySet())` döngüsünde `m.getValue() + ", " + m.getKey()` yazdırılır. `map.replace(17, eski, yeni)` 17 anahtarının değerini değiştirir. `map.remove(5)` 5 anahtarlı çifti siler. `map.clear()` sonrasında `map.get(17)` `null` döndürür.
- **Generic sınıf** (ekrandan, 01:05:00 ve 01:10:00). `class Test<T, U>` içinde `T obj1; U obj2;` alanları, bunları atayan bir constructor ve `obj1 + "\t" + obj2` yazdıran `print()` metodu vardır. `new Test<String, Integer>("NYP", 2020)` çağrısı `NYP	2020`, `Character` tipli nesne ise `3	B` yazdırır.
- **Generic metot** (ekrandan, 01:10:00 ve 01:15:00). `printArray` metoduna `Integer[] {1,2,3,4,5}`, `Double[] {1.1,2.2,3.3,4.4}` ve `Character[] {'H','E','L','L','O'}` dizileri gönderilir. Çıktı `1 2 3 4 5`, `1.1 2.2 3.3 4.4` ve `H E L L O` olur. Dönüş tipinden önceki `<E>` yazılmazsa derleyici `E` tipini tanımaz.
- **try-catch temeli** (ekrandan, 01:20:00). `try { int a = 5/0; } catch (Exception e) { System.out.println("hata yakalandı."); }` bloğundan sonra `System.out.println("kodun devamı.");` satırı da çalışır. Karede ilk denemede `try`'dan sonra yarım kalmış bir `catch` satırı ve ayrı bir `catch` bloğu görünür; çıktı `hata yakalandı.` ve `kodun devamı.` satırlarıdır.
- **Birden çok catch** (ekrandan, 01:25:00). `int a = 1; int[] b = new int[5];` tanımlanır. `try` içinde `a = a/0;` ve `b[10] = a;` satırları, ardından `ArrayIndexOutOfBoundsException`, `ArithmeticException` ve `Exception` için üç catch bloğu yazılır. Sıfıra bölme olunca ikinci satıra geçilmez; aritmetik catch'i çalışır (`a = 2`). Sonra `a = a*5` ile `a` 10 olur, `b` dizisinin son elemanı 0 kalır. Sıfıra bölme satırı yorum yapılınca dizi sınırı catch'i çalışır (`b[b.length-1] = 3`). Bu durumda çıktı `dizi sınırı aşıldı`, `a'nin son degeri: 5` ve `b dizisi son elemanın değeri: 3` olur.
- **NullPointerException ve finally.** `Integer data = null;` üzerinden `data.intValue()` çağrılınca `NullPointerException` fırlatılır. Catch içinde `System.out.println(e)` istisnanın sınıf adını yazar. `finally` bloğu her durumda çalışır ve `data` değişkenini 5 yapar. `data` 0 olsaydı istisna oluşmaz, yine de finally çalışırdı.
  <!-- BELİRSİZ: Bu örneğin kodu karelerde görünmüyor; altyazıdan aktarıldı. -->
- **throw ve throws** (ekrandan, 01:30:00). `int age = 23; if (age < 18) throw new ArithmeticException("Not valid"); else { ... "Welcome to vote" ... "Rest of the code" ... }` ve ardından `"devam.."` yazdırılır. `age` 18'den küçükse özel mesajlı istisna fırlatılır ve kodun devamı çalışmaz. Çalışmaya devam etmek için `try-catch` gerekir. `DriverManager` ile veritabanı bağlantısı kuran bir satırda Eclipse "Unhandled exception type SQLException" uyarısı verir. Bu, derleme anında denetlenen (checked) bir istisnadır ve ya `throws SQLException` ya da `try-catch` ile çözülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
