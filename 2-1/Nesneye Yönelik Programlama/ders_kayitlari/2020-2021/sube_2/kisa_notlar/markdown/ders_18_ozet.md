# Ders 18 Çalışma Özeti

## Genel Konular

- Veri yapısı kavramı ve doğru veri yapısını seçmenin önemi
  - Veri yapısı, aynı türden ve birbiriyle ilişkili verilerin bellekte nasıl bir arada tutulacağını belirleyen düzendir. Verinin nasıl düzenlendiği, onu kullanan programın ne kadar verimli çalışacağını doğrudan etkiler.
  - Bu dersin amacı veri yapılarının iç yapısını anlatmak ya da jenerik sınıf yazmayı öğretmek değildir. Amaç, `java.util` paketindeki hazır jenerik veri yapılarını kullanmayı öğretmektir.
- Bağlı liste (linked list) ile dizinin karşılaştırılması
  - Bağlı liste, birbirini işaret eden düğümlerden oluşan doğrusal bir nesne koleksiyonudur. İlk düğüme head, son düğüme tail denir. Son düğümün "sonraki" işaretçisi `null`dır.
  - Son düğüm yeniden ilk düğümü gösteriyorsa liste döngüseldir (circular). Her düğüm bir öncekini de gösteriyorsa liste çift bağlıdır (doubly-linked).
  - Listenin dizilere üstünlükleri (ekrandan, 00:15:00): listeyi büyütmek neredeyse bedavadır; herhangi bir konuma ekleme ve silme daha hızlıdır; slayta göre bazı sıralama algoritmaları bağlı listede daha hızlı çalışır.
  - Dizinin tek üstünlüğü: i. elemana doğrudan (random access) erişim. Listede elemana ulaşmak için baştan sırayla gitmek gerekir.
  - Diziyi büyütmek için daha büyük yeni bir dizi açılır, elemanlar kopyalanır ve eski referans yeni diziye bağlanır.
- Jenerik programlama
  - Farklı türden nesneler için tekrar kullanılabilir kod yazma yoludur. Java'ya JSE 5.0 ile geldi (ekrandan, 00:20:00).
  - Jenerik öncesi `ArrayList myList = new ArrayList();` tanımında düğümler `Object` türündedir. Bu yüzden kendi sınıfımızın metotlarını çağırmak için tür dönüşümü (typecasting) zorunluydu.
  - Jenerik tanım: `ArrayList<Person> liste = new ArrayList<Person>();`. Açılı parantez içine listenin tutacağı nesne türü yazılır.
- `ArrayList` sınıfı ve temel metotları (ekrandan, 00:25:00)
  - Arka planda dizi kullanır ve thread-unsafe'tir.
  - `add(T)` sona ekler, `get(int i)` i. elemanı döndürür, `size()` eleman sayısını döndürür. Bütün liste for-each ile gezilir.
  - `ensureCapacity(int)` arka plandaki diziyi gerekirse genişletir. `trimToSize()` boş gözleri atarak kapasiteyi eleman sayısına indirir. `set(int i, T)` i. konumdaki elemanı değiştirir. `remove(int i)` i. elemanı siler. Geçersiz konumda `IndexOutOfBoundsException` (unchecked) fırlatılır.
- Java koleksiyon hiyerarşisi (ekrandan, 00:35:00)
  - `java.lang.Iterable<E>` for-each döngüsünü mümkün kılar. `java.util` içinde `AbstractCollection<E>`, `Collection<E>` arayüzünü gerçekler.
  - `Collection<E>` metotları: `add(e)`, `clear()`, `contains(o)`, `isEmpty()`, `iterator()`, `remove(o)`, `size()`.
  - `List<E>` arayüzü `get(index)` ve `indexOf(o)` ekler; eleman yoksa `indexOf` -1 döndürür.
  - `AbstractList<E>`: `indexOf`, `get`, `set`, `remove`. `set` ve `remove(index)` konumdan çıkan eski elemanı döndürür.
  - `Vector<E>` (thread-safe) ek olarak `elementAt`, `firstElement`, `lastElement` sunar. `LinkedList<E>`, `AbstractSequentialList<E>` altındadır ve `addFirst`, `addLast`, `getFirst`, `getLast` sunar.
- Örnek: ders ve öğrenci (Course, Student, USIS)
  - `Course` sınıfı, öğrencileri `ArrayList<Student>` içinde tutar. `capacity` üyesi yalnız iş mantığı içindir, veri yapısının kapasitesiyle ilgisi yoktur.
  - `getStudentCount()` için `students.size()`, ekleme için `students.add()`, arama için for-each kullanılır.
  - Dizili sürümle karşılaştırma: dizide ayrı bir `studentCount` sayacı, kapasite artışında yeni dizi açıp kopyalama ve for-each kullanılırsa `null` denetimi gerekir.
- Map yapıları
  - Bir elemana tekil tanımlayıcısıyla (key) hızlıca erişmeyi sağlar. Eleman value, tekil tanımlayıcı key diye anılır.
  - `Map<K,V>` metotları (ekrandan, 01:20:00): `get(key)`, `put(key, value)`, `remove(key)`, `values()`, `isEmpty()`, `size()`, `containsKey(k)`, `containsValue(v)`.
  - `HashMap<K,V>` thread-unsafe, `Hashtable<K,V>` thread-safe'tir. `Hashtable` adındaki küçük "t" harfine dikkat edilmelidir.
  - Örnek `HashMap<String, Student>` ile yeniden yazıldı: ekleme `put(aStudent.getNumber(), aStudent)`, arama `students.get(number)`, listeleme `students.values()` üzerinde for-each.
  - Key ve value ilkel tür olamaz; `int` yerine `Integer` sarmalayıcısı yazılır. Otomatik sarmalama (autoboxing) sayesinde sınıfın geri kalanında `int` kullanılabilir.
- Liste ve map yapılarının özeti (ekrandan, 02:05:00)
  - `LinkedList`: ekleme ve silme daha hızlı, rastgele erişim daha yavaş, çift bağlı.
  - `ArrayList`: ekleme ve silme daha yavaş, rastgele erişim daha hızlı.
  - `Vector`: `ArrayList`'e benzer ama senkronize (thread-safe). Çok iş parçacıklı kullanım için uygundur, tek iş parçacığında daha yavaştır.
  - `HashMap`: anahtara göre hızlı arama. `Hashtable`: `HashMap` gibi ama senkronize.
- Aykırı durum işleme (exception handling)
  - Hata kaynakları: sanal makinedeki hatalar, kullanıcının yanlış girdisi, programcının hatalı kodu, programcının denetleyemediği dış etkenler (ağ, dosya erişim hakkı).
  - Hiyerarşi (ekrandan, 02:15:00): `Throwable` → `Error` (unchecked) ve `Exception`. `Exception` altında `IOException` (checked, `java.io`) ve `RuntimeException` (unchecked).
  - Unchecked exception'ı yakalamak zorunlu değildir. Checked exception ya `try-catch` ile işlenir ya da metot imzasına `throws` ile eklenip çağırana bırakılır. Sonunda bir yerde mutlaka ele alınır.
  - `try` bloğu, ilişkili metotları bir arada içine alır. Her exception türü için ayrı `catch` yazılabilir. `finally` bloğu exception olsa da olmasa da çalışır ve kaynakları serbest bırakmak için kullanılır.
  - `catch` içinde en azından anlamlı bir mesaj yazdırılmalı ve `e.printStackTrace()` çağrılmalıdır.
- Kendi exception sınıfını yazmak
  - Checked olacaksa `IOException`'dan, unchecked olacaksa `RuntimeException`'dan kalıtımla türetilir (ekrandan, 02:35:00).
  - Açıklama metni alan bir kurucu yazılır ve metin `super(errorMessage)` ile üst sınıfa iletilir.
  - Exception `throw new ExceptionAdi("açıklama");` ile fırlatılır. Fırlatan metodun imzasına `throws` eklenir; işlemeyi çağıran yapar.
  - Örnek: `ImpossibleInfo` exception'ı ve `Person.setAge` metodu. Yaş 0'dan küçük ya da 150'den büyükse exception fırlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kendi exception sınıfında açıklama metni alan kurucuyu yazmak
  - Hoca bu kurucunun sınavlarda ve projelerde yazılmasını istedi; yazılmazsa da kod derlenir. Son kullanıcı yığın izinden (stack trace) bir şey anlamaz; programın neden durduğuna anlamlı bir yanıt verilmelidir.
- Kendi exception'ını `Exception`'dan değil, `IOException` ya da `RuntimeException`'dan türetmek
  - Böylece exception'ın checked mı unchecked mı olduğu açıkça belli olur.
- `main` metoduna `throws` ekleyip geçmemek
  - Exception işlenmezse kullanıcı karşısında bozuk bir hata ekranı görür, örneğin bir web servisinde. Exception mutlaka bir yerde ele alınmalıdır.
- Tek `try` bloğu, birden çok `catch`
  - Hoca, her metot için ayrı `try` açmanın performansı düşüreceğini söyledi. İlişkili metotlar tek `try` içine alınır.
- `Hashtable` adındaki küçük "t"
  - Camel casing kuralına uymayan bu adlandırma sık hata yaptırır.
- Thread-safe ve thread-unsafe yapı seçimi
  - Thread-safe yapılar senkronizasyon nedeniyle daha yavaştır. Çok iş parçacıklı kod yazılmıyorsa thread-unsafe yapılar seçilmelidir.
- Map yapısında anahtar değeri nesnenin kendisinden almak
  - Ekleme sırasında anahtar `aStudent.getNumber()` gibi nesnenin getter metoduyla alınmalıdır.
- Kağıt üzerindeki sınav için `Collection` arayüzündeki 7 metot ile `List` arayüzündeki `get` ve `indexOf` metotlarını bilmek yeterlidir.

## Kısa Tekrar Notları

- Jenerik tanım: `ArrayList<Tür> ad = new ArrayList<Tür>();`. Jenerik desteği JSE 5.0 ile geldi.
- Liste: `add`, `get`, `size`, `set`, `remove`; gezme için for-each. `ArrayList`'e özel metotlar: `ensureCapacity`, `trimToSize`.
- Dizinin `length` değeri kapasiteyi verir, eleman sayısını vermez. Listede `size()` eleman sayısını verir.
- `LinkedList`: ekleme ve silme hızlı, erişim yavaş. `ArrayList`: tersi. `Vector`: thread-safe `ArrayList` benzeri.
- Map: `put(key, value)`, `get(key)`, `remove(key)`; gezmek için `values()`. Map doğrudan for-each'e konmaz.
- `HashMap` thread-unsafe, `Hashtable` thread-safe.
- Key ilkel olamaz: `HashMap<Integer, Student>`. Otomatik sarmalama `int` ↔ `Integer` dönüşümünü kendisi yapar.
- `Throwable` → `Error` / `Exception` → `IOException` (checked) / `RuntimeException` (unchecked).
- Checked exception: `try-catch` ya da `throws` zorunlu. Unchecked exception için zorunlu değil.
- `catch` içinde mesaj ve `e.printStackTrace()`; kaynak bırakmak için `finally`.
- Kendi exception'ın: `extends IOException` ya da `extends RuntimeException`, `String` parametreli kurucu, `super(mesaj)`.
- Fırlatma: `throw new ImpossibleInfo("Impossible age " + age);`, metot imzasında `throws ImpossibleInfo`.

## Detaylı Açıklamalar

- **Dizi ile liste farkı.** Dizi sabit kapasiteyle açılır. Kaç eleman dolu olduğu programcının ayrı bir sayaçla tutması gereken bir bilgidir. Diziyi büyütmek yeni dizi açıp kopyalamayı gerektirir. Bağlı listede yeni eleman için yalnız bir düğüm ayrılır ve en çok iki işaretçi değiştirilir. Bu yüzden ekleme ve silme kolaydır. Bedeli, aradaki bir elemana ulaşmak için baştan ilerlemektir. Bir elemana anahtarla doğrudan ulaşmak gerekiyorsa map yapısı kullanılır.
- **Jenerik yapı.** Jenerik öncesi koleksiyonlar `Object` tutuyordu. Kendi sınıfımızın metodunu çağırmak için her elemanı dönüştürmek gerekiyordu. Ayrıca her veri türü için listeyi yeniden yazmak gerekirdi. Jenerik sınıfta tür parametre olarak verilir: `ArrayList<Person>`. Gezme sırasında eleman doğrudan `Person` olarak gelir.
- **`ArrayList` ve kapasite.** `ArrayList` arka planda dizi kullanır. Dizi dolunca kendisi genişletir. Çok sayıda eleman eklenecekse önce `ensureCapacity(mevcut + yeni)` çağrılabilir; böylece genişletme tek seferde yapılır. Uzun süre eleman eklenmeyecekse `trimToSize()` ile boş gözler bırakılabilir. Bu metotlar dizi tabanlı olmayan listelerde gerekmez.
- **Koleksiyon hiyerarşisini bilmenin yararı.** `ArrayList`, `AbstractList`'in, o da `AbstractCollection`'ın alt sınıfıdır. `AbstractCollection` da `Collection` arayüzünü gerçekler. Bu yüzden `Collection` ve `List` arayüzlerindeki bütün metotlar `ArrayList`, `Vector` ve `LinkedList`'te vardır. `set(index, e)` ve `remove(index)` eski elemanı döndürür. Döndürülen eleman başka bir değişkene atanmazsa çöp toplayıcı onu toplar.
- **Course örneği (ekrandan, 01:00:00 ve 01:05:00).**

```java
public boolean addStudent( Student aStudent ) {
    if( getStudentCount() == capacity ||
            findStudent(aStudent.getNumber()) != null )
        return false;
    students.add(aStudent);
    return true;
}
public Student findStudent( String number ) {
    for( Student aStudent : students )
        if( aStudent.getNumber().compareTo(number) == 0 )
            return aStudent;
    return null;
}
```

  - Dizili sürümde `findStudent` döngüsü `for (int i = 0; i < studentCount; i++)` biçimindedir (ekrandan, 01:10:00). For-each kullanılırsa dizinin boş gözlerinde `NullPointerException` alınır. Hoca kapasiteyi artırıp listeyi yazdırarak bunu canlı gösterdi.
- **Map sürümü (ekrandan, 01:35:00).** Yalnız birkaç satır değişir: `students = new HashMap<String,Student>();`, `students.put(aStudent.getNumber(), aStudent);`, `return students.get(number);` ve `for (Student aStudent : students.values())`. Arama tek satıra iner ve hızlanır. Ekran çıktısında `HashMap` öğrencileri ekleme sırasıyla listelemedi (ekrandan, 01:40:00).
- **Aykırı durum işleme.** Bir hata olasılığı varsa er geç gerçekleşir (Murphy kanunu). Programcı ağ trafiğini ya da kullanıcının dosya erişim hakkını denetleyemez. Ama bu durumların farkında olup ya üstesinden gelmeli ya da sorunu bildirmelidir. `IOException` yalnız dosya için değildir; ağ ve komut satırı girdi/çıktısı da girdi/çıktı işlemidir. `RuntimeException` genelde programcı hatasından doğar (`NullPointerException`, `IndexOutOfBoundsException`).
- **`ExceptionExample01` (ekrandan, 02:30:00).** Grafik nesnesi oluşturma, dosya açma, şekilleri okuma, çizme ve kapatma işlemleri tek `try` içindedir. `catch (IOException e)` bloğu dosya adını ve `e.toString()` değerini yazar, `e.printStackTrace()` ve `System.exit(1)` çağırır. `finally` bloğunda `graphics.releaseSources()` ile kaynak bırakılır.
  - Ders sonrası not: Hoca ve slayttaki yorum, `System.exit(1)` sonrasında da `finally` bloğunun çalışacağını söylüyor; doğrusu, `System.exit` çağrıldıktan sonra `finally` blokları çalıştırılmaz (ajan küçük bir denemeyle doğruladı). Kaynak `System.exit`'ten önce bırakılmalıdır.
  - Ders sonrası not: Hoca `finally` içinden `try` içinde tanımlanan değişkenlere erişilebildiğini söyledi; doğrusu, `try` içinde tanımlanan değişken `finally`'de görülmez, kaynak değişkeni `try`'dan önce tanımlanır.
- **`ImpossibleInfo` ve `TestExceptions` (ekrandan, 02:45:00 ve 02:50:00).** `ImpossibleInfo extends IOException` olduğu için checked'dir. `setAge` geçersiz yaşta exception fırlatır ve imzasında `throws ImpossibleInfo` vardır. `main` içinde yaşı soran, okuyan, atayan ve yazdıran satırlar birlikte `try` içine alınır. `finally` bloğunda `Scanner` kapatılır. 450 girildiğinde `ImpossibleInfo: Impossible age 450` ve yığın izi yazılır. Exception `RuntimeException`'dan türetildiğinde `throws` ve `try-catch` zorunluluğu kalkar; exception yakalanmazsa yığın izini sanal makine yazar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
