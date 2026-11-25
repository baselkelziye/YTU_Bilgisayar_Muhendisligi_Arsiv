# Ders 16 Genişletilmiş Notu: Arayüzler, Koleksiyonlar, İstisnalar ve Jenerikler (Uygulama)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Kapsamı
- 2. Arayüzler (Interface)
- 3. ArrayList ve Iterator
- 4. ArrayList İşlemleri: addAll, remove, removeAll, retainAll
- 5. LinkedList, List ve ListIterator
- 6. Koleksiyonu Doğrudan Yazdırmak
- 7. HashMap
- 8. İstisnalar: try, catch, finally
- 9. throw ile İstisna Fırlatmak
- 10. Jenerikler
- Örnek Sorular

## 1. Oturumun Kapsamı

Bu oturum bir uygulama dersidir. O haftanın uygulamasında arayüzler, koleksiyonlar (`ArrayList`, `LinkedList`, `HashMap`), istisnalar ve jenerikler kullanılacağı için bu konular hazır örnek kodlar üzerinden gösterildi. Kuramsal kısma girilmedi; kuramsal anlatımın teori dersinde yapılacağı söylendi. Örnekler Eclipse'te `uyg3` projesindeydi; proje `Interface`, `collections`, `exceptions` ve `generics` paketlerinden oluşuyordu (ekrandan, 00:10:00). Her örnek çalıştırıldı ve konsol çıktısı kodla birlikte yorumlandı.

## 2. Arayüzler (Interface)

### 2.1 Arayüz ve kalıtım

Kalıtımda alt sınıf, üst sınıfta yazılmış bir metodu kendisinde yazılmamış olsa da sanki varmış gibi kullanır. Kalıtımın amacı da budur: bir kodu bir kez yazıp başka yerlerde yeniden yazmamak. Arayüz uygulamak (`implements`) buna benzer bir ilişki kurar, ama önemli bir farkı vardır: bir arayüzü uygulayan sınıf, arayüzdeki gövdesiz metotları override etmek zorundadır. Override edilmezse Eclipse hata gösterir.

Bir sınıf yalnız bir sınıftan kalıtım alabilir, ama birden fazla arayüzü uygulayabilir.

### 2.2 Arayüzün tanımı

Arayüz `interface` anahtar kelimesiyle, sınıf tanımına benzer biçimde tanımlanır. Arayüz adının başına `I` harfi konması (`IClass`) bir alışkanlıktır. Zorunlu değildir, ama koda bakan herkes adın bir arayüze ait olduğunu hemen anlar.

Arayüzün sıradan metotları yalnız prototip olarak yazılır, gövdeleri yazılmaz. `default` anahtar kelimesiyle tanımlanan metotların ise gövdesi arayüzde yazılır. Bu şu anlama gelir: "Arayüzü uygulayan sınıfı bu metodu override etmeye zorlamıyorum; override etmezse buradaki kod çalışır, isterse override edebilir." Arayüz böylece bir şablon gibi davranır: onu uygulayan sınıfta hangi metotların bulunması gerektiğini belirler.

Arayüzde `static` metot da tanımlanabilir; onun da gövdesi yazılır ve arayüz adıyla çağrılır.

Bir arayüz başka bir arayüzü `extends` ile genişletebilir. Bu durumda üst arayüzün metotları alt arayüzde de varmış gibi kabul edilir. Bu yüzden yalnız alt arayüzü uygulayan bir sınıf, üst arayüzün soyut metotlarını da override etmek zorunda kalır.

### 2.3 Örnek kod

Ekrandaki `InterfaceEx.java` dosyasının arayüz ve sınıf kısmı şudur (ekrandan, 00:10:00 ve 00:15:00):

```java
interface IClass{
    public void method1();
    default void method2(){
        System.out.println("IClass sınıfında method2 çalıştı.");
    }
}
/*-----------------------------------------------------------*/
interface IClass2 extends IClass{
    public void method3();
    static void method4(){
        System.out.println("IClass2 sınıfında method4 çalıştı.");
    }
}
/*-----------------------------------------------------------*/
class Parent{
    public void method5(){
        System.out.println("Parent sınıfında method5 çalıştı.");
    }
}
/*-----------------------------------------------------------*/
class Child extends Parent implements IClass2{

    @Override
    public void method3() {
        System.out.println("Child sınıfında method3 çalıştı.");
    }

    @Override
    public void method1() {
        System.out.println("Child sınıfında method1 çalıştı.");
    }
}
```

`main` metodu karelerde görünmüyor. Anlatıma göre `main` içinde bir `Child` nesnesi oluşturuluyor; bu nesneyle `method1`, `method2`, `method3`, `method5` çağrılıyor, `method4` ise arayüz adıyla çağrılıyor. <!-- BELİRSİZ: main metodunun tam kodu karede görünmüyor; çağrı sırası konsol çıktısından ve anlatımdan kuruldu. --> Ekrandaki konsol çıktısı şudur (ekrandan, 00:10:00):

```text
Child sınıfında method1 çalıştı.
IClass sınıfında method2 çalıştı.
Child sınıfında method3 çalıştı.
IClass2 sınıfında method4 çalıştı.
Parent sınıfında method5 çalıştı.
```

Kod, bu `main` ile birlikte ajan tarafından `java` ile çalıştırıldı ve aynı çıktıyı verdi.

### 2.4 Çıktının adım adım okunması

- `method1`: `Child` yalnız `IClass2`'yi uyguluyor. Ama `IClass2`, `IClass`'ı genişlettiği için `Child` `IClass`'ı da uygulamış sayılır. Bu yüzden `IClass`'taki soyut `method1`'i override etmek zorundadır. Override edilen sürüm çalışır: "Child sınıfında method1 çalıştı."
- `method2`: `default` olduğu için `Child` onu override etmedi ve etmek zorunda da değildi. Arayüzdeki gövde çalışır: "IClass sınıfında method2 çalıştı."
- `method3`: `IClass2`'nin soyut metodudur, `Child` onu override etti.
- `method4`: `IClass2`'nin `static` metodudur. Gövdesi arayüzdedir ve `IClass2.method4()` biçiminde arayüz adıyla çağrılır.
- `method5`: `Child`, `Parent`'tan kalıtım aldı. `Child` içinde `method5` yazılmasa da kalıtımla gelir ve `Parent`'taki gövde çalışır.

### 2.5 Bir arayüz birden fazla arayüzü genişletebilir mi?

**Soru:** Bir arayüz diğerini `implements` değil `extends` ediyor. Birden fazla arayüzü `extends` edebilir mi?
**Cevap:** Derste denendi. Yeni bir `IClass3` arayüzü yazıldı ve `IClass2` hem `IClass`'ı hem `IClass3`'ü genişletecek biçimde değiştirildi. Derleme başarılı oldu; yani bir arayüz birden fazla arayüzü `extends` edebilir. Bu değişiklikten sonra `Child` sınıfı hata verdi, çünkü artık `IClass3`'teki soyut metodu da override etmek zorundaydı. <!-- BELİRSİZ: IClass3'ün ve eklenen metodun tam kodu karede görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Java'da sınıflar arasında çoklu kalıtım yoktur, ama arayüzler arasında vardır: `interface C extends A, B { }` geçerli bir tanımdır. Bir sınıf da `class X implements A, B` biçiminde birden fazla arayüzü uygulayabilir.

## 3. ArrayList ve Iterator

### 3.1 Tanım ve ekleme

`ArrayList` dizilere benzer, ama dizi değildir. Hangi türde nesne tutacağı `< >` işaretleri arasında yazılır. Bu tür `String`, `Integer`, `Double` ya da örnekteki `Student` gibi bir kullanıcı sınıfı olabilir.

> **Ders sonrası not:** Derste `String`'in ilkel bir veri tipi olduğu söylendi. Doğrusu: `String` bir sınıftır. Koleksiyonların tür parametresi her zaman bir nesne türüdür; `int`, `double` gibi ilkel türler yazılamaz, onların yerine `Integer`, `Double` gibi sarmalayıcı sınıflar kullanılır.

Ekrandaki `collections/Ornek1.java` (ekrandan, 00:20:00):

```java
package collections;

import java.util.ArrayList;
// (diğer import satırları Eclipse'te katlanmış; Iterator için java.util.Iterator gerekir)

public class Ornek1 {

    public static void main(String[] args) {
        ArrayList<String> listem = new ArrayList<String>();
        listem.add("Haydar Haydar");
        listem.add("Dalgalandım Da Duruldum");
        listem.add("Benzemez Kimse Sana");
        listem.add("Gamzedeyim Devam Bulmam");

        Iterator<String> itr = listem.iterator();
        System.out.println("Iterator while için yazdırma !!!");
        while(itr.hasNext()) {
            System.out.println(itr.next());
        }

        System.out.println("\nIterator foreach için yazdırma !!!");
        for (String obj : listem) {
            System.out.println(obj);
        }
    }
}
```

`add` metodu değerleri sırayla listenin sonuna ekler.

### 3.2 Iterator

`listem.iterator()` listenin yineleyicisini (iterator) döndürür ve bu `itr` değişkeninde tutulur. `while(itr.hasNext())` döngüsü listede sırada eleman olduğu sürece döner; her turda `itr.next()` bir sonraki elemanı verir ve yineleyiciyi ilerletir. Böylece dört eleman sırayla yazdırılır.

Aynı işi for-each döngüsü de yapar ve normalde öyle yazılır. Yineleyicinin gösterilmesinin nedeni şudur: `ArrayList` gibi kendi koleksiyonunuzu yazarsanız onun yineleyicisini de yazmanız gerekir.

## 4. ArrayList İşlemleri: addAll, remove, removeAll, retainAll

### 4.1 Student sınıfı ve liste

`Student` sınıfında üç alan, bunları atayan bir yapıcı ve get metotları vardır. `Ornek2`'de üç `Student` nesnesi oluşturulup bir `ArrayList<Student>` listesine eklenir. Bu, daha önce nesne dizileriyle yapılan işin listeyle yapılmasıdır. Listenin dizilerden üstünlüğü esnekliktir: 10 elemanlı bir dizi 11. eleman için yeniden tanımlanmak zorundadır, listeye ise istenildiği kadar eleman eklenir.

Ekrandaki `collections/Ornek2.java` (ekrandan, 00:25:00 ve 00:35:00; örnek verilerde tanınmış kişilerin adları kullanılmıştır):

```java
Student s1 = new Student(17011001,"Mehmet Akif Ersoy", 20);
Student s2 = new Student(17011010,"Abdülhak Hamit Tarhan", 22);
Student s3 = new Student(17011100,"Mithat Cemal Kuntay", 19);

ArrayList<Student> stu_list = new ArrayList<Student>();
stu_list.add(s1);
stu_list.add(s2);
stu_list.add(s3);

System.out.println("İlk listenin öğrencilerin isimleri...");
ListeGoster(stu_list);

ArrayList<Student> stu_list2 = new ArrayList<Student>();
stu_list2.add(new Student(16011001, "Hamza Yerlikaya", 21));
stu_list2.add(new Student(16011010, "Naim Süleymanoğlu", 18));

stu_list.addAll(stu_list2);

System.out.println("\nİki listenin tüm öğrencilerin isimleri ...");
ListeGoster(stu_list);

stu_list.remove(3);
System.out.println("\n3 nolu öğrenci silindikten sonra liste ...");
ListeGoster(stu_list);

// ...
stu_list.removeAll(stu_list2);
System.out.println("\n2. listeyi silindikten sonra liste ...");
ListeGoster(stu_list);

stu_list.addAll(stu_list2);
stu_list.retainAll(stu_list2); //2. listeyi koruyor
System.out.println("\n2. listeyi retaion yaptıktan sonra liste ...");
ListeGoster(stu_list);
```

<!-- BELİRSİZ: Kodun 33-37. satırları karelerde tam görünmüyor; anlatıma göre burada ikinci liste yazdırılıyor. Student sınıfının ve ListeGoster metodunun tam kodu da karelerde yok. -->

`ListeGoster` metodu listenin yineleyicisini alır ve `while` döngüsüyle elemanları yazdırır. Konsoldaki ilk çıktı satırları `Mehmet Akif Ersoy, 17011001, 20` biçimindedir (ekrandan, 00:25:00).

### 4.2 Adım adım

- İlk liste: üç öğrenci yazdırılır.
- İkinci listeye `new` ile doğrudan iki öğrenci eklenir. İlk listedeki gibi `s1`, `s2` değişkenleri kullanılmaz.
- `stu_list.addAll(stu_list2)`: ikinci listenin bütün elemanları birinci listenin sonuna eklenir. Birinci listede artık beş öğrenci vardır.
- `stu_list.remove(3)`: 3 numaralı indisteki eleman silinir. İndis 0'dan başladığı için (0, 1, 2, 3) silinen dördüncü elemandır, yani ikinci listeden gelen ilk öğrenci. İkinci liste bu işlemden etkilenmez; iki elemanıyla aynen durur.
- `stu_list.removeAll(stu_list2)`: ikinci listede bulunan bütün elemanlar birinci listeden çıkarılır. Birinci listede ikinci listeden yalnız bir öğrenci kalmıştı, o da çıkarılır; liste ilk üç öğrenciye döner. `remove(3)` yapılmamış olsaydı da sonuç aynı olurdu.
- `stu_list.addAll(stu_list2)` ve ardından `stu_list.retainAll(stu_list2)`: önce ikinci liste yeniden eklenir, sonra yalnız ikinci listede de bulunan elemanlar tutulur. `retainAll`, `removeAll`'ın tersi gibidir: verilen listedekiler dışındaki her şeyi siler. Sonuçta listede yalnız ikinci listenin iki öğrencisi kalır.

Bu adımlar, `Student` için basit bir sınıf yazılarak ajan tarafından `java` ile çalıştırıldı; her adımın sonucu yukarıdaki anlatımla aynı çıktı.

## 5. LinkedList, List ve ListIterator

### 5.1 Karakter listesi

`Ornek3`'te karakter tutan bir `LinkedList` oluşturulur, karakterler eklenir ve yine yineleyiciyle dolaşılır. <!-- BELİRSİZ: Ornek3'ün kodu karelerde görünmüyor; konsolda yalnız alt alta yazılmış birkaç harf görünüyor (ekrandan, 00:30:00). -->

### 5.2 Kitap listesi

`Ornek4`'te `Book` sınıfından nesneler tutan bir `LinkedList` vardır. `Book` sınıfında yapıcı, alanlara atama yapar (`this.name`, `this.author`, `this.publisher`, `this.quantity`). Ekrandaki kod (ekrandan, 00:30:00):

```java
public static void main(String[] args) {
    List<Book> kitaplar = new LinkedList<Book>();
    Book b1 = new Book(1, "Pera Palas'ta Gece Yarısı", "Charles King", "Kitap Yayınevi", 10000);
    Book b2 = new Book(2, "Bir Türk Ailesinin Öyküsü", "İrfan Orga", "Everest Yayınları", 1000);

    kitaplar.add(b1);
    kitaplar.add(b2);

    System.out.println("Kitap listesi for each ile...");
    for (Book kitap : kitaplar) {
        System.out.println(kitap.name + ", " + kitap.author);
    }

    System.out.println("\nKitap listesi ListIterator previous ile...");
    ListIterator<Book> itr = kitaplar.listIterator();

    while(itr.hasNext()) { //eğer bu while döngüsü olmasaydı ne olacaktı göster
        System.out.println(itr.next().name);
    }

    while(itr.hasPrevious()) {
        System.out.println(itr.previous().name);
    }
}
```

`LinkedList` nesnesi `List` türünden bir değişkenle tutulur. Bu, daha önceki uygulamada farklı kart sınıflarından üretilen nesnelerin ortak bir kart türüyle tutulmasına benzer.

> **Ders sonrası not:** Derste `LinkedList`'in `List`'ten kalıtım aldığı söylendi. Doğrusu: `List` bir arayüzdür (`java.util.List`); `LinkedList` ve `ArrayList` bu arayüzü uygular. Bu yüzden ikisinin nesnesi de `List` türünden bir değişkenle tutulabilir.

### 5.3 ListIterator ile ileri ve geri dolaşma

`listIterator()` ile alınan `ListIterator`, `hasNext/next` yanında `hasPrevious/previous` metotlarını da sunar. Bağlı listede her düğüm bir sonrakini ve bir öncekini gösterir; bu yüzden iki yönde de ilerlenebilir.

İlk `while` döngüsü kitapları baştan sona yazdırır. Bu döngü bittiğinde yineleyici listenin sonundadır. İkinci `while` döngüsü `hasPrevious/previous` ile geriye doğru yazdırır. Konsol çıktısının bu kısmı şudur (ekrandan, 00:35:00):

```text
Kitap listesi ListIterator previous ile...
Pera Palas'ta Gece Yarısı
Bir Türk Ailesinin Öyküsü
Bir Türk Ailesinin Öyküsü
Pera Palas'ta Gece Yarısı
```

Son eleman iki kez yazılır: ileri dolaşmada bir kez, geri dolaşmanın ilk adımında bir kez.

> **Ders sonrası not:** Derste ileri döngünün sonunda yineleyicinin `null` gösterdiği ve `previous`'un önce ikinci kitaba döndüğü anlatıldı. Doğrusu: `ListIterator`'ın imleci her zaman iki elemanın arasındadır. `next()` imlecin sağındaki elemanı döndürüp imleci sağa, `previous()` solundaki elemanı döndürüp imleci sola kaydırır. İleri döngü bitince imleç son elemanın sağındadır; ilk `previous()` bu yüzden son elemanı (ikinci kitabı) yeniden döndürür. Ekrandaki çıktı da budur.

### 5.4 ArrayList ile LinkedList farkı

**Soru:** `LinkedList` ile `ArrayList` arasındaki fark nedir? İkisinde de `add` ile ekleme yapılıyor. `ArrayList`'te geri dönme yok mu?
**Cevap:** Derste `ArrayList`'in `iterator()` metoduyla alınan yineleyicide `next` olduğu, `previous` olmadığı gösterildi. Bağlı listede bir düğümden sonrakine ve öncekine gidilebildiği, bunun veri yapıları dersinden de bilinebileceği söylendi; ayrıntının teori dersinde anlatılacağı belirtildi.

> **Ders sonrası not:** Derste `ArrayList`'te geriye dönülemeyeceği ve araya ekleme yapılamayacağı söylendi (anlatıcı sonra "ArrayList'te de yapılabilir" diyerek kısmen düzeltti). Doğrusu: `previous` olmaması koleksiyondan değil, `iterator()`'ın döndürdüğü `Iterator` türünden kaynaklanır. `ArrayList` de `listIterator()` ile `hasPrevious/previous` sunar (ajan tarafından denendi) ve `add(indis, eleman)` ile araya ekleme yapılabilir. Asıl fark iç yapıdadır: `ArrayList` arkada bir dizi tutar, `LinkedList` çift bağlı listedir.

> **Ek bilgi (derste anlatılmadı):** Dizi tabanlı `ArrayList`'te indisle erişim sabit sürede yapılır, ama ortaya ekleme ve silmede sonraki elemanlar kaydırılır. `LinkedList`'te indisle erişim için listeyi baştan dolaşmak gerekir, ama yineleyicinin bulunduğu yere ekleme ya da silme düğüm bağlantılarını değiştirerek yapılır.

## 6. Koleksiyonu Doğrudan Yazdırmak

`Ornek5`'te `Book` nesneleri tutan bir `LinkedList` ve `Student` nesneleri tutan bir `ArrayList` oluşturulur. İki liste de `List` türünden değişkenlerle tutulur ve `println` ile doğrudan yazdırılır. Derste şu soruldu: kitaplar yazdırılınca kitap adları çıkar mı? Çıkmaz. Konsol çıktısı şudur (ekrandan, 00:40:00):

```text
Linked List: [collections.Book@34c45dca, collections.Book@52cc8049]
Array List: [collections.Student@5b6f7412, collections.Student@27973e9b, collections.Student@312b1dae]
```

Her eleman için sınıfın adı ve `@` işaretinden sonra bir sayı yazılır. Bir nesnenin anlamlı biçimde yazdırılması için sınıfında `toString` metodu override edilmelidir; bu, önceki uygulamalarda yapılmıştı.

> **Ders sonrası not:** Derste `@` işaretinden sonraki değerin nesnenin adresi olduğu söylendi. Büyük olasılıkla daha doğru ifade şudur: bu değer `Object.toString()`'in yazdığı, nesnenin `hashCode()` değerinin onaltılık gösterimidir; bellek adresi olması gerekmez.

## 7. HashMap

`HashMap` iki tür birlikte tutar: biri anahtar (key), öbürü değer (value). `< >` içine yalnız iki tür yazılabilir; üçüncü bir tür kabul edilmez. Ekleme `add` ile değil `put(anahtar, değer)` ile yapılır.

Ekrandaki `collections/Ornek6.java`'nın başı şudur (ekrandan, 00:40:00; örnekteki kişi adları burada genel adlarla değiştirildi):

```java
HashMap<Integer, String> first_hm = new HashMap<Integer, String>();

first_hm.put(1, "Ali");
first_hm.put(36, "Veli");
first_hm.put(25, "Can");
```

<!-- BELİRSİZ: Ornek6'nın 14-24. satırları karede bir açılır pencereyle örtülü; aşağıdaki işlemler anlatıdan ve konsol çıktısından kuruldu. -->

Sonra `entrySet()` ile girdi (entry) kümesi alınır ve `Map.Entry<Integer, String>` türünden öğeler for-each ile dolaşılarak yazdırılır. Ardından `replace(25, eskiDeğer, yeniDeğer)` ile 25 anahtarının değeri değiştirilir; diğer çiftler etkilenmez. Son olarak `remove(25)` ile 25 anahtarlı çift tamamen silinir. Konsol çıktısı (ekrandan, 00:45:00; adlar genel adlarla değiştirildi):

```text
Ali, 1
Veli, 36
Can, 25
Tüm map: {1=Ali, 36=Veli, 25=Ece}
Tüm map: {1=Ali, 36=Veli}
```

Bu işlemler ajan tarafından `java` ile çalıştırıldı ve aynı sırayla aynı çıktı alındı.

> **Ek bilgi (derste anlatılmadı):** `HashMap`'te bir anahtar yalnız bir kez bulunur; aynı anahtarla yeniden `put` yapılırsa eski değer yenisiyle değiştirilir. `HashMap` öğelerin ekleme sırasını korumayı garanti etmez; sıranın korunması gerekiyorsa `LinkedHashMap` kullanılır.

## 8. İstisnalar: try, catch, finally

### 8.1 Neden try-catch?

Hata çıkabilecek kod `try` bloğuna yazılır. Hata çıkmazsa kod normal çalışır. Hata çıkarsa, hatanın türüne uyan `catch` bloğu çalışır; örneğin sıfıra bölmede `ArithmeticException` bloğu. Uygun özel bir blok yoksa hata `Exception` bloğuna düşer, çünkü `Exception` en genel istisna türüdür. Bloklardan sonra program kaldığı yerden devam eder.

`a = a / 0` gibi bir satır `try-catch` dışında yazılırsa program "patlar", yani durur. Amaç programın çökmemesi, istisnai durumda başka bir yol izlenmesi ve programın çalışmayı sürdürmesidir. `try-catch` bu yüzden çok sık kullanılır.

### 8.2 Birden çok catch bloğu

Ekrandaki `exceptions/Ornek1.java` (ekrandan, 00:45:00):

```java
package exceptions;

public class Ornek1 {

    public static void main(String[] args) {
        int a = 1;
        int b[] = new int[5];

        try {
            a = a / 0;
            b[10] = a;
        }catch (ArrayIndexOutOfBoundsException aiobe) {
            //aiobe.printStackTrace();
            b[b.length-1] = a;
        }catch (ArithmeticException ae) {
            //ae.printStackTrace();
            a = 0;
        }catch (Exception e) {
            e.printStackTrace();
        }

        a = a * 5;
        System.out.println("a'nın son değeri: " + a);
        System.out.println("b[10]'un degeri: " + b[b.length-1]);
    }
}
```

Adım adım (bölme satırı açıkken):

- `a = 1`, `b` beş elemanlı bir `int` dizisidir (indisler 0-4).
- `a = a / 0`, yani `1 / 0`, `ArithmeticException` fırlatır. Akış `ArithmeticException` bloğuna geçer ve `a = 0` olur.
- `b[10] = a` satırı hiç çalışmaz, çünkü `try` bloğunda ilk hata oluştuğu anda akış `catch`'e geçmiştir. Yalnız bir `catch` bloğu çalışır.
- Bloktan sonra `a = a * 5 = 0` olur. `b[b.length-1]`, yani `b[4]`, hiç değişmediği için 0'dır.
- Çıktı: `a'nın son değeri: 0` ve `b[10]'un degeri: 0` (ekrandan, 00:55:00).

Bölme satırı yorum satırı yapılınca (`//a = a / 0;`, ekrandan 00:55:00):

- `b[10] = a` satırında 10. indis yoktur (en büyük indis 4'tür). `ArrayIndexOutOfBoundsException` fırlatılır.
- Akış ilgili bloğa geçer: `b[b.length-1] = a`, yani `b[4] = 1` olur.
- Sonra `a = 1 * 5 = 5` olur.
- Çıktı: `a'nın son değeri: 5` ve `b[10]'un degeri: 1`. Ekrana yazılan değer aslında `b[10]` değil, dizinin son elemanı `b[4]`'tür.

Son olarak `ArithmeticException` bloğu kaldırılıp bölme satırı yeniden açıldığında sıfıra bölme hatası genel `Exception` bloğuna düştü: yığın izi yazıldı, `a` 1 olarak kaldı, `a = 5` ve `b[4] = 0` yazıldı. Hata yazıldı, ama program çökmeden çalışmayı sürdürdü.

İlk iki durum ajan tarafından `java` ile çalıştırıldı ve anlatılan değerler doğrulandı; üçüncü durumun değerleri derste ekranda gösterildiği biçimde aktarıldı.

> **Ek bilgi (derste anlatılmadı):** `catch` bloklarında özel istisnalar genel olanlardan önce yazılmalıdır. `catch (Exception e)` ilk sıraya konursa, ondan sonraki `ArithmeticException` gibi bloklara hiçbir zaman ulaşılamaz ve Java bunu derleme hatası olarak bildirir.

### 8.3 finally

Ekrandaki `exceptions/Ornek2.java` (ekrandan, 00:50:00):

```java
package exceptions;

public class Ornek2 {

    public static void main(String[] args) {
        Integer data;
        try {
            data = 3;
            System.out.println(data.intValue());
        } catch (NullPointerException e) {
            e.printStackTrace();
        }finally {
            System.out.println("Her zaman çalışır");
            data = 5;
        }
        System.out.println(data.intValue());
    }
}
```

İlk çalıştırmada `try` içinde `data = null` vardı (karede görünen sürümde `3`'tür). `null` bir değerin `intValue()`'su alınamaz; `NullPointerException` fırlatılır ve akış `catch` bloğuna geçer. `catch` yığın izini yazar. Ardından `finally` bloğu çalışır: "Her zaman çalışır" yazılır ve `data = 5` olur. Son satır `5` yazar. Ekrandaki çıktı (ekrandan, 00:50:00):

```text
java.lang.NullPointerException
        at uyg3/exceptions.Ornek2.main(Ornek2.java:9)
Her zaman çalışır
5
```

`data = 3` yapılınca `try` bloğu hatasız çalışır ve önce `3` yazılır. `catch` bloğuna girilmez, ama `finally` yine çalışır: "Her zaman çalışır" yazılır, `data = 5` olur ve son satır `5` yazar. `finally`'nin işi budur: `try` de çalışsa, `catch` de çalışsa sonunda mutlaka çalışır.

## 9. throw ile İstisna Fırlatmak

### 9.1 Kendi istisnamızı fırlatmak

Önceki örneklerde istisnayı Java fırlatıyordu, biz yakalıyorduk. Programcı da `throw` ile kendisi istisna fırlatabilir. `exceptions/Ornek3`'teki örnekte bir yaş değeri 18'den küçükse "not valid" iletisiyle bir `ArithmeticException` fırlatılır; değilse "Welcome to ..." diye başlayan bir ileti yazılır. Yaş 18'den küçükken çalıştırılan program istisna fırlatıp durdu; değer 18'in üstüne çıkarılınca karşılama iletisi yazıldı. <!-- BELİRSİZ: Ornek3'ün kodu karelerde görünmüyor; değişken adı, eşik ve iletiler yalnız altyazıdan alındı. -->

> **Ek bilgi (derste anlatılmadı):** Bu tür örnekler genelde `if (age < 18) throw new ArithmeticException("not valid"); else System.out.println("welcome ...");` biçimindedir. `throw` bir istisna nesnesi fırlatır; metodun imzasındaki `throws` ise metodun hangi istisnaları fırlatabileceğini bildirir.

### 9.2 Kalıtım ve fırlatılan istisna

`exceptions/Ornek4`'te bir üst sınıfta bir ileti metodu vardır. Ondan kalıtım alan sınıf bu metodu override eder (zorunlu değildi) ve metodun `ArithmeticException` fırlatabileceğini belirtir. `main` içinde alt sınıftan bir nesne oluşturulup metodu çağrılır. Hata oluşmadığında metodun iletisi yazılır, fırlatılan bir şey olmaz.

Metodun içine sıfıra bölme eklenince iki durum karşılaştırıldı:

- Çağrı `try-catch` içindeyken hata `catch (Exception e)` bloğunda yakalandı, "hata yakalandı" gibi bir ileti yazıldı ve program devam etti.
- Çağrı `try-catch` dışındayken program istisnayla durdu; sonraki satırlar çalışmadı.

<!-- BELİRSİZ: Ornek4'ün kodu karelerde görünmüyor; sınıf ve metot adları ile iletiler altyazıdan kesin çıkarılamıyor. -->

## 10. Jenerikler

### 10.1 Jenerik metot

Aynı işi farklı veri türleri için yapan bir metot, örneğin bir dizinin elemanlarını yazdıran bir metot, normalde `Integer`, `Double` ve `String` için ayrı ayrı yazılmalıdır. Jenerik metotta veri türü sonradan, kullanım anında belirlenir. Ekrandaki `generics/Ornek1.java` (ekrandan, 01:00:00):

```java
package generics;

public class Ornek1 {

    public static <E> void printArray(E[] inputArray ) {
        for(E element : inputArray)
            System.out.print(element + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] intArray = { 1, 2, 3, 4, 5 };
        Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4 };
        Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };

        System.out.println("Array integerArray contains:");
        printArray(intArray);   // pass an Integer array

        System.out.println("\nArray doubleArray contains:");
        printArray(doubleArray);   // pass a Double array

        System.out.println("\nArray characterArray contains:");
        printArray(charArray);   // pass a Character array
    }
}
```

`<E>` metodun bir tür parametresi aldığını söyler; `E[] inputArray` "türü ne olursa olsun bir dizi" demektir. `E` adının özel bir anlamı yoktur, onun yerine başka bir ad da yazılabilir; ama alışkanlık olarak `E` kullanılır. Metot önce `Integer`, sonra `Double`, sonra `Character` dizisiyle, kodunda hiçbir değişiklik yapılmadan çağrılır. Her eleman bir boşlukla yazılır ve her dizinin sonunda alt satıra geçilir. Konsol çıktısı (ekrandan, 01:05:00):

```text
1 2 3 4 5

Array doubleArray contains:
1.1 2.2 3.3 4.4

Array characterArray contains:
H E L L O
```

### 10.2 Jenerik sınıf

Jenerik sınıfta birden fazla tür parametresi olabilir. Ekrandaki `generics/Ornek2.java` (ekrandan, 01:05:00):

```java
package generics;

class Test<T, U> {
    T obj1;
    U obj2;

    Test(T obj1, U obj2) {
        this.obj1 = obj1;
        this.obj2 = obj2;
    }

    public void print() {
        System.out.println(obj1 + "\n" + obj2);
    }
}

public class Ornek2 {

    public static void main(String[] args) {
        Test <String, Integer> obj1 = new Test<String, Integer>("NYP", 20182);
        obj1.print();
        Test <Character, Character> obj2 = new Test<Character, Character>('A', 'B');
        obj2.print();
    }
}
```

`T` ve `U`'nun da özel anlamı yoktur. `obj1` alanı `T`, `obj2` alanı `U` türündedir. `main`'de `Test<String, Integer>` yazıldığında `T` yerine `String`, `U` yerine `Integer` geçer. Sınıfta `String` ve `Integer` doğrudan yazılsaydı aynı sınıf `Character, Character` ile kullanılamazdı.

`main` içindeki `obj1` değişkeni ile `Test` sınıfının `obj1` alanı farklı şeylerdir. Biri `main`'in, öbürü sınıfın küme parantezleri içindedir.

- `obj1`: `"NYP"` ve `20182` yapıcıya gönderilir. `"NYP"` sınıfın `obj1` alanına, `20182` `obj2` alanına atanır. `print()` bunları alt alta yazar: `NYP`, `20182`.
- `obj2`: bu kez iki tür de `Character`'dır. `print()` `A` ve `B` yazar.

Kod ajan tarafından `java` ile çalıştırıldı; çıktı `NYP`, `20182`, `A`, `B` satırlarıdır.

## Örnek Sorular

**1.** (derste sözlü, 00:12:00) Bir arayüz başka bir arayüzü `extends` edebiliyor. Birden fazla arayüzü `extends` edebilir mi?

> **Çözüm:** Evet. Derste `IClass2`'nin iki arayüzü genişletmesi denendi ve derleme başarılı oldu. Bu durumda `IClass2`'yi uygulayan `Child`, iki üst arayüzün bütün soyut metotlarını override etmek zorundadır; etmeyince hata verdi.

**2.** (derste sözlü, 00:34:00 ve 00:35:54) `ArrayList` ile `LinkedList` arasındaki fark nedir? İkisine de `add` ile ekleme yapılıyor.

> **Çözüm:** Derste bağlı listede ileri ve geri gidilebildiği, `ArrayList`'in `iterator()` yineleyicisinde ise `previous` olmadığı gösterildi. Doğru ve tam cevap için 5.4'teki ders sonrası nota bakın: iki sınıf da `List` arayüzünü uygular ve ikisinde de `listIterator()` ile geri dolaşılabilir; fark iç yapıdadır (dizi tabanlı ve çift bağlı liste).

**3.** (ekrandan ve sözlü, 00:37:46) `Book` nesneleri tutan bir `LinkedList` `System.out.println` ile doğrudan yazdırılırsa kitap adları çıkar mı?

> **Çözüm:** Çıkmaz. `Book` sınıfında `toString` override edilmediği için her eleman `collections.Book@34c45dca` biçiminde, sınıf adı ve bir onaltılık sayıyla yazılır (ekrandan, 00:40:00). Kitap adlarının yazılması için `Book` sınıfında `toString` override edilmelidir.

**4.** (derste sözlü, 00:56:30) `ArrayList` ve `LinkedList` `List`'ten mi türetilmiş?

> **Çözüm:** Derste "evet, `List` genel bir tanım; kalıtım almasaydı `List` türünden bir değişkenle tutamazdık" diye cevaplandı. Daha doğru ifade: `List` bir arayüzdür ve iki sınıf da bu arayüzü uygular. `List` türünden değişkenle tutulabilmelerinin nedeni budur.

**5.** (derste sözlü, 00:57:11) `HashMap` örneğinde for-each döngüsündeki `m` değişken adı neye göre seçildi?

> **Çözüm:** Hiçbir özel anlamı yoktur, yalnız bir değişken adıdır. Derste ad `deneme` olarak değiştirildi ve döngüdeki bütün kullanımlar da değiştirilince çıktı aynı kaldı.

## Dersin Toparlaması

Bu uygulama oturumunda Java'nın dört temel yapısı hazır örneklerle gösterildi. Arayüzlerde soyut metotların uygulayan sınıfta override edilmek zorunda olduğu, `default` ve `static` metotların ise gövdelerinin arayüzde yazıldığı görüldü. Bir sınıf tek sınıftan kalıtım alıp birden fazla arayüzü uygulayabilir; bir arayüz de birden fazla arayüzü genişletebilir. Koleksiyonlarda `ArrayList` ile ekleme, toplu ekleme, indisle silme, `removeAll` ve `retainAll`; `LinkedList` ve `ListIterator` ile ileri ve geri dolaşma; `HashMap` ile anahtar-değer çiftlerinin eklenmesi, değiştirilmesi ve silinmesi işlendi. Bir koleksiyonun anlamlı biçimde yazdırılması için elemanların `toString`'inin override edilmesi gerektiği de görüldü.

İstisnalarda `try` bloğunda ilk hata oluşunca uygun `catch` bloğunun çalıştığı, `Exception`'ın en genel yakalayıcı olduğu, `finally`'nin her durumda çalıştığı ve `throw` ile istisna fırlatılabildiği gösterildi; yakalanmayan bir istisnanın programı durdurduğu vurgulandı. Son olarak jenerik metot (`<E>`) ve jenerik sınıf (`<T, U>`) ile aynı kodun farklı türler için yeniden yazılmadan kullanılması anlatıldı. Koleksiyonlar ve istisnaların ileride çok kullanılacağı özellikle belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
