# Ders 16 Çalışma Özeti

## Genel Konular

- Uygulama oturumu: arayüzler, koleksiyonlar, istisnalar ve jenerikler
  - Oturum bir uygulama (lab hazırlık) dersidir. Konular Eclipse'teki `uyg3` projesinin `Interface`, `collections`, `exceptions` ve `generics` paketlerindeki hazır örnek kodlar çalıştırılarak anlatıldı (ekrandan, 00:10:00).
  - Kuramsal anlatım yapılmadı; örnekler çalıştırılıp çıktıları yorumlandı.
- Arayüz (interface) tanımı ve kullanımı
  - Arayüz `interface` anahtar kelimesiyle tanımlanır. Adının başına `I` konması (`IClass`) bir alışkanlıktır, zorunlu değildir; okunurluğu artırır.
  - Arayüzdeki sıradan metot yalnız prototip olarak yazılır (gövdesiz): `public void method1();`. Arayüzü uygulayan (`implements`) sınıf bu metodu override etmek zorundadır, yoksa derleme hatası alınır.
  - `default` ile tanımlanan metodun gövdesi arayüzde yazılır; uygulayan sınıf onu override etmek zorunda değildir, isterse eder.
  - `static` metodun da gövdesi arayüzde yazılır ve arayüz adıyla çağrılır: `IClass2.method4()`.
  - Bir arayüz başka bir arayüzü `extends` ile genişletir (`interface IClass2 extends IClass`). `IClass2`'yi uygulayan sınıf `IClass`'ın soyut metotlarını da override etmek zorundadır.
  - Bir sınıf yalnız bir sınıftan kalıtım alabilir, ama birden fazla arayüzü uygulayabilir. Örnek: `class Child extends Parent implements IClass2` (ekrandan, 00:10:00).
  - Bir öğrencinin sorusu üzerine derste denendi: bir arayüz birden fazla arayüzü `extends` edebilir; bu durumda uygulayan sınıf hepsinin soyut metotlarını override etmelidir.
- `ArrayList` ve `Iterator`
  - `ArrayList<String> listem = new ArrayList<String>();` biçiminde, tutulacak tür `< >` içinde yazılır. Tür `Integer`, `Double` ya da kullanıcı sınıfı (`Student`) olabilir (ekrandan, 00:20:00).
  - `add` ile sona eleman eklenir. `iterator()` listenin yineleyicisini döndürür; `while(itr.hasNext())` ve `itr.next()` ile dolaşılır. Aynı dolaşma `for (String obj : listem)` ile de yapılır.
  - Dizilere göre fark: boyut sabit değildir, eleman eklendikçe büyür.
- `ArrayList` işlemleri (`Ornek2`, `Student` listesi)
  - `addAll(liste2)`: ikinci listenin bütün elemanlarını birincinin sonuna ekler.
  - `remove(3)`: 3 numaralı indisteki (0'dan sayılınca dördüncü) elemanı siler; ikinci liste etkilenmez.
  - `removeAll(liste2)`: ikinci listede bulunan elemanları birinci listeden çıkarır.
  - `retainAll(liste2)`: yalnız ikinci listede de bulunan elemanları tutar, gerisini siler (`removeAll`'ın tersi gibi) (ekrandan, 00:35:00).
- `LinkedList`, `List` ve `ListIterator`
  - `List<Book> kitaplar = new LinkedList<Book>();`: `LinkedList` nesnesi `List` türünden bir değişkenle tutulabilir (ekrandan, 00:30:00).
  - `listIterator()` ile alınan `ListIterator` `hasNext/next` yanında `hasPrevious/previous` ile geriye doğru da dolaşabilir. Ekrandaki çıktıda kitaplar önce ileri, sonra geri sırayla yazıldı (ekrandan, 00:35:00).
  - Koleksiyon doğrudan `println` ile yazdırılırsa elemanların `toString`'i override edilmediği için `[collections.Book@34c45dca, ...]` gibi çıktı alınır (ekrandan, 00:40:00). Anlamlı çıktı için `toString` override edilmelidir.
- `HashMap`
  - `HashMap<Integer, String>` anahtar-değer çiftleri tutar; ekleme `put(anahtar, değer)` ile yapılır (ekrandan, 00:40:00).
  - `entrySet()` ile `Map.Entry<Integer, String>` öğeleri for-each ile dolaşılır.
  - `replace(anahtar, eskiDeğer, yeniDeğer)` değeri değiştirir; `remove(anahtar)` çifti siler. Ekranda son iki çıktı `{1=..., 36=..., 25=...}` ve `{1=..., 36=...}` biçimindedir (ekrandan, 00:45:00).
- İstisnalar: `try`, `catch`, `finally`, `throw`
  - Hata çıkabilecek kod `try` bloğuna yazılır; hata oluşursa türüne uyan `catch` bloğu çalışır. `Exception` en genel türdür; özel bir `catch` yoksa hata ona düşer.
  - Amaç programın çökmemesi ve hataya karşı başka bir yol izlenmesidir.
  - Bir `try` bloğunda ilk hata oluşunca akış `catch`'e geçer; `try`'daki sonraki satırlar çalışmaz ve yalnız bir `catch` bloğu çalışır.
  - `finally` bloğu hata olsa da olmasa da çalışır (ekrandan, 00:50:00).
  - `throw` ile programcı kendisi istisna fırlatır (örnek: yaş 18'den küçükse `ArithmeticException` fırlatmak).
  - `try-catch` olmadan fırlatılan bir istisna programı durdurur.
- Jenerikler (generics)
  - Jenerik metot: `public static <E> void printArray(E[] inputArray)` aynı metodu `Integer`, `Double` ve `Character` dizileri için ayrı ayrı yazmadan kullanmayı sağlar (ekrandan, 01:00:00).
  - Jenerik sınıf: `class Test<T, U>` iki farklı tür parametresi alır; nesne oluşturulurken türler belirtilir: `new Test<String, Integer>("NYP", 20182)`, `new Test<Character, Character>('A', 'B')` (ekrandan, 01:05:00).
  - `E`, `T`, `U` adlarının özel bir anlamı yoktur; alışkanlık olarak kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Arayüzde `default` ile soyut metot arasındaki fark
  - Soyut metot uygulayan sınıfı override etmeye zorlar; `default` metot zorlamaz ama override edilmesine de engel değildir.
- Tek sınıftan kalıtım, çok arayüz
  - `extends` ile yalnız bir sınıftan kalıtım alınır; `implements` ile birden fazla arayüz uygulanabilir.
- Koleksiyonlar ve istisnalar çok kullanılacak
  - İstisnalar ve koleksiyonların ileride çok kullanılacağı özellikle söylendi.
- `try-catch` neden kullanılır
  - `try-catch` olmazsa hata programı durdurur; yakalanırsa program istenmeyen değerlerle de olsa çalışmaya devam eder ve hata durumunda farklı bir yol izlenebilir.

## Kısa Tekrar Notları

- Arayüz metodu varsayılan olarak gövdesizdir; `default` ve `static` metotların gövdesi vardır.
- `implements` eden sınıf soyut metotları override etmek zorundadır.
- Arayüz arayüzü `extends` eder; birden fazla arayüzü de `extends` edebilir.
- `ArrayList`: `add`, `addAll`, `remove(indis)`, `removeAll`, `retainAll`, `iterator()`.
- `Iterator`: `hasNext`, `next`. `ListIterator`: ayrıca `hasPrevious`, `previous`.
- `HashMap`: `put`, `entrySet`, `replace`, `remove`.
- Koleksiyonu yazdırmak için elemanların sınıfında `toString` override edilmelidir.
- `catch` sırası: özel istisnalar önce, `Exception` en sonda.
- `finally` her durumda çalışır.
- `throw new ArithmeticException("...")` ile istisna fırlatılır.
- Jenerik metot `<E>`, jenerik sınıf `<T, U>`; tür kullanım anında belirlenir.

## Detaylı Açıklamalar

- Arayüz örneği (`InterfaceEx.java`, ekrandan 00:10:00 ve 00:15:00)
  - `IClass` içinde soyut `method1()` ve `default method2()` vardır. `IClass2 extends IClass` içinde soyut `method3()` ve `static method4()` vardır. `Parent` sınıfında sıradan `method5()` vardır. `Child extends Parent implements IClass2` yalnız `method1` ve `method3`'ü override eder.
  - `main` içinde bir `Child` nesnesiyle metotlar çağrılınca çıktı şudur (ekrandan, 00:10:00; ajan tarafından `java` ile çalıştırıldı):

    ```text
    Child sınıfında method1 çalıştı.
    IClass sınıfında method2 çalıştı.
    Child sınıfında method3 çalıştı.
    IClass2 sınıfında method4 çalıştı.
    Parent sınıfında method5 çalıştı.
    ```

  - `method2` override edilmediği için arayüzdeki `default` gövde çalışır; `method5` `Parent`'tan kalıtımla gelir.
- İstisna örneği (`exceptions/Ornek1`, ekrandan 00:45:00)
  - `int a = 1; int b[] = new int[5];` sonra `try` içinde `a = a / 0;` ve `b[10] = a;` vardır. `catch` sırası: `ArrayIndexOutOfBoundsException` (`b[b.length-1] = a;`), `ArithmeticException` (`a = 0;`), `Exception` (`e.printStackTrace();`). Bloktan sonra `a = a * 5;` ve iki `println`.
  - Bölme satırı açıkken: sıfıra bölme `ArithmeticException` verir, `a = 0` olur, `b[10]` satırı hiç çalışmaz; sonuç `a = 0`, `b[4] = 0`.
  - Bölme satırı yorum yapılınca: `b[10]` dizi sınırını aşar, `b[4] = a = 1` olur; sonra `a = 5`. Sonuç `a = 5`, `b[4] = 1` (ajan tarafından çalıştırıldı).
  - `ArithmeticException` bloğu kaldırılınca sıfıra bölme hatası `Exception` bloğuna düşer, yığın izi yazılır, program yine devam eder.
- `finally` örneği (`exceptions/Ornek2`, ekrandan 00:50:00)
  - `Integer data;` `try` içinde `data = null` iken `data.intValue()` `NullPointerException` verir, `catch` yığın izini yazar, `finally` "Her zaman çalışır" yazar ve `data = 5` yapar; son satır `5` yazar.
  - `data = 3` iken önce `3`, sonra `finally` çıktısı, sonra `5` yazılır.
- Jenerik sınıf (`generics/Ornek2`, ekrandan 01:05:00)
  - `Test<T, U>` iki alan (`T obj1; U obj2;`), bunları atayan yapıcı ve ikisini alt alta yazan `print()` içerir. `obj1.print()` `NYP` ve `20182`; `obj2.print()` `A` ve `B` yazar (ajan tarafından çalıştırıldı).
- Ders sonrası düzeltmeler
  - Derste `String`'in ilkel tür olduğu söylendi; doğrusu `String` bir sınıftır. Koleksiyonlara ilkel türler (`int`, `double`) değil, sarmalayıcı ya da nesne türleri (`Integer`, `Double`, `String`) verilir.
  - Derste `ArrayList`'te geriye dönülemeyeceği ve araya ekleme yapılamayacağı söylendi. Doğrusu: geriye dolaşma yeteneği koleksiyona değil yineleyiciye bağlıdır; `ArrayList` de `listIterator()` ile `hasPrevious/previous` sunar ve `add(indis, eleman)` ile araya ekleme yapılabilir. Fark iç yapıdadır: `ArrayList` dizi tabanlı, `LinkedList` çift bağlı listedir.
  - `ArrayList` ve `LinkedList` `List`'ten "kalıtım almaz"; `List` bir arayüzdür ve bu sınıflar onu uygular (`implements`).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
