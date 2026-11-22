# Ders 17 Genişletilmiş Notu: Uygulama 3: Arayüzler, Koleksiyonlar, Generics ve İstisnalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun konusu
- 2. Soyut sınıftan arayüze
- 3. Arayüz örneği: IClass, IClass2, Parent, Child
- 4. Bir dosyada birden çok sınıf ve paket erişimi
- 5. Koleksiyonlar ve liste yapıları
- 6. ArrayList metotları: öğrenci listesi
- 7. LinkedList, Iterator ve ListIterator
- 8. get, indisli add ve toString
- 9. Map ve HashMap
- 10. Generics
- 11. İstisnalar ve try-catch
- 12. Birden çok catch ve printStackTrace
- 13. NullPointerException ve finally
- 14. throw, throws, checked ve unchecked istisnalar
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun konusu

Bu oturum, dersin uygulama oturumlarından biridir. Bütün örnekler Eclipse'te, önceden hazırlanmış Java dosyaları üzerinden çalıştırılarak anlatılır. Proje dört bölümden oluşur: varsayılan pakette arayüz örnekleri, `collections` paketinde `Ornek1`–`Ornek6` ile `Student` sınıfı, `generics` paketinde iki örnek, `exceptions` paketinde ise `Example` ve `Ornek1`–`Ornek4` (ekrandan, 00:10:00). Konular sırasıyla arayüzler (interface), koleksiyonlar (collections), soysal tipler (generics) ve istisnalardır (exceptions).

## 2. Soyut sınıftan arayüze

Anlatım, önceki konu olan soyut sınıfların hatırlatılmasıyla başlar. Bir sınıf `abstract` anahtar kelimesiyle tanımlanınca soyut olur. Bir sınıfın soyut olmasının nedeni, içinde gövdesi olmayan bir metot barındırmasıdır; bu metoda soyut metot denir. Soyut metodun dönüş tipi herhangi bir tip olabilir, ama süslü parantezler açılıp içi doldurulmaz. Soyut bir sınıfta soyut metotların yanında gövdesi dolu normal metotlar da bulunabilir.

Soyut sınıfın kalıtımdaki amacı şudur: Üst sınıfta bir metodun gövdesini yazmanın anlamı yoktur, çünkü her alt sınıf onu farklı biçimde kullanacaktır. Metot üst sınıfta soyut bırakılır, alt sınıf da kendi kullanımına uygun biçimde gerçekler (implement eder).

Kalıtımın bir sınırı vardır: Bir sınıf yalnız bir sınıfı `extends` edebilir. Birden fazla sınıfın metotlarını tek bir sınıfta toplamak (çoklu kalıtım) istendiğinde arayüzler devreye girer.

> **Ders sonrası not:** Anlatımda bu sınır soyut sınıflar için söylendi. Doğrusu, Java'da bu kural bütün sınıflar için geçerlidir: Somut ya da soyut fark etmez, bir sınıf yalnız bir üst sınıftan `extends` edebilir.

### 2.1 Arayüz tanımı

Arayüz, sınıf tanımına benzer biçimde `interface` anahtar kelimesiyle tanımlanır. İçine gövdesiz metotlar yazılır. Bu metotlar için `abstract` kelimesini yazmak gerekmez, çünkü bir arayüzün içindeki metotların hepsi zaten soyuttur. Ekranda boş bir `public interface InterfaceExx { }` dosyası açılarak bu gösterilir (ekrandan, 00:05:00).

Arayüzde bir metodun gövdesi yazılmaya çalışılırsa Eclipse hata verir ve iki tür öneri sunar. Birinci öneri metot gövdesini silmektir. İkinci öneri metodu `default` ya da `static` yapmaktır. Metot `default` yapılınca hata kalkar; `static` yapılınca da derleyici kabul eder.

> **Hocanın vurgusu:** Arayüzde gövdesi dolu metot yazmanın yalnız iki yolu vardır: metodu `default` ya da `static` yapmak. Yine de arayüzün ortaya çıkış amacı, çok sayıda gövdesiz metot tanımlayıp gövdelerini alt sınıflara bırakmaktır. Bu yüzden arayüzde gövde yazmaya çok başvurulmaz.

Anlatımda `default` ve `static` önce "erişim belirteci" diye anıldı, sonra "şu tipler demek daha doğru" diye düzeltildi.

## 3. Arayüz örneği: IClass, IClass2, Parent, Child

Örnek dosyada iki arayüz bulunur: `IClass` ve `IClass2`. Arayüz adlarının başına `I` harfi koymak, arayüz olduklarını belli etmek için yaygın bir alışkanlıktır.

- `IClass`: gövdesiz `method1()` ve `default` olarak gövdesi yazılmış `method2()`.
- `IClass2`: gövdesiz `method3()` ve `static` olarak gövdesi yazılmış `method4()`.
- `Parent`: somut bir sınıf, `method5()` metodu var.
- `Child`: `Parent` sınıfını `extends`, `IClass` ve `IClass2` arayüzlerini `implements` eder.

Somut (concrete) sınıf, soyut da olmayan, arayüz de olmayan normal sınıftır. Somut bir sınıftan kalıtım `extends` ile alınır. Üst sınıftan bir şey almak zorunlu değildir, ama alınacaksa somut bir sınıftan `extends` edilir. Arayüzler ise `implements` ile alınır ve virgülle ayrılarak istenen sayıda arayüz yazılabilir. Çoklu kalıtım ihtiyacı bu yolla karşılanır.

`Child`, `Parent`'tan aldığı `method5()` metodunu override etmek zorunda değildir: İsterse override eder, istemezse üst sınıftaki hâliyle çalıştırır. Arayüzlerdeki gövdesiz metotların gövdesini yazmak ise zorunludur.

> **Hocanın vurgusu:** Arayüz metotları için "override" yerine "implement" demek daha doğrudur. Override, dolu bir gövdenin üzerine yazılıyormuş gibi anlaşılır. Arayüz metodunun ise gövdesi yoktur; gerçekleyen sınıf gövdeyi ilk kez yazar.

`IClass` içindeki `default` `method2()` ile `IClass2` içindeki `static` `method4()` zaten gövdelidir, bu yüzden `Child` sınıfında yazılmaları gerekmez.

Ekrandaki `main` metodu şöyledir (ekrandan, 00:10:00):

```java
public class InterfaceEx {

    public static void main(String[] args) {
        Child ch = new Child();
        ch.method1();
        ch.method2(); //default erisimli method
        ch.method3();
        IClass2.method4(); //static erisimli method
        ch.method5();
    }
}
```

<!-- BELİRSİZ: IClass, IClass2, Parent ve Child sınıflarının kodu karelerde görünmüyor (dosyanın alt kısmında). Aşağıdaki iskelet altyazıdaki anlatımdan ajan tarafından kuruldu; yazdırılan mesajlar derstekilerle aynı olmayabilir. -->

Anlatıma uygun bir iskelet şöyledir (derste bu biçimde gösterilmedi; ajan tarafından yazıldı ve `java InterfaceEx.java` ile çalıştırıldı):

```java
interface IClass {
    void method1();
    default void method2() { System.out.println("IClass arayuzunde method2"); }
}

interface IClass2 {
    void method3();
    static void method4() { System.out.println("IClass2 arayuzunde method4"); }
}

class Parent {
    void method5() { System.out.println("Parent sinifinda method5"); }
}

class Child extends Parent implements IClass, IClass2 {
    public void method1() { System.out.println("Child sinifinda method1"); }
    public void method3() { System.out.println("Child sinifinda method3"); }
}
```

Program çalışınca beş satır yazılır:

- `ch.method1()`: `IClass`'tan gelen ve gövdesi `Child`'da yazılan metot; çıktı Child sınıfından gelir.
- `ch.method2()`: `default` metot; gövdesi arayüzde olduğu için doğrudan `IClass`'tan çalışır.
- `ch.method3()`: `IClass2`'den gelen ve `Child`'da gerçeklenen metot.
- `IClass2.method4()`: `static` metot. Statik metotlar sınıfa (burada arayüze) aittir, nesneyle ilgisi yoktur; bu yüzden arayüz adı, nokta ve metot adıyla çağrılır.
- `ch.method5()`: `Parent`'tan `extends` ile gelen ve override edilmeyen metot; Parent'taki gövde çalışır.

### 3.1 Arayüzler arası kalıtım

Arayüzler de birbirinden metot alabilir. İki arayüz aynı türden olduğu için aralarındaki kalıtımda `implements` değil `extends` kullanılır. Somut bir sınıf arayüz alırken `implements`, bir arayüz başka bir arayüzü alırken `extends` yazılır.

## 4. Bir dosyada birden çok sınıf ve paket erişimi

Arayüz örneği sırasında dosya düzeniyle ilgili bir ara bilgi verilir. Bir `.java` dosyası açıldığında içine birden fazla sınıf tanımlanabilir. Tek koşul, yalnız bir sınıfın `public` olmasıdır: O sınıf dosyaya adını veren sınıftır, başka `public` sınıfa izin verilmez. Diğer sınıfların başına `public`, `private` ya da `protected` yazılmaz.

Başına erişim belirteci yazılmayan sınıfa "default erişim" (paket erişimi) denir. Böyle bir sınıfa aynı dosyanın içinden ve aynı paketteki diğer sınıflardan erişilebilir. Örnek projede varsayılan paket (adı olmayan paket), `collections` ve `exceptions` gibi ayrı paketler vardır.

## 5. Koleksiyonlar ve liste yapıları

Koleksiyonlar, bir grup veriyi nerede ve nasıl tutacağımız sorusuna cevap olarak geliştirilmiş yapılardır. Şimdiye kadar uygulamalarda veriler hep dizilerde tutuldu. Dizide baştan "şu kadar yer ayır" denir ve dizi doldurulsa da doldurulmasa da o kadar yer bellekte ayrılmış olur. Listelerde ise baştan boyut vermek gerekmez: Elemanlar geldikçe `add` ile sona ya da indis belirtilerek istenen yere eklenir.

Anlatımda bağlı listede elemanların birbirini işaretçilerle (pointer) gösterdiği, bu yüzden yalnız kullanılan kadar yer tuttuğu söylendi.

> **Ders sonrası not:** Bu açıklama `LinkedList` için doğrudur. `ArrayList` ise işaretçilerle bağlı değildir; anlatımın ilerleyen kısmında da söylendiği gibi dizi tabanlıdır. İç dizi dolunca daha büyük bir diziye kopyalanarak büyür. Kullanıcı açısından boyut baştan verilmez, ama iç dizi kullanılmayan yer de ayırabilir.

### 5.1 Hiyerarşi

Hiyerarşide en üstte `Iterable` vardır. `Collection` onu, `List` de `Collection`'ı `extends` eder. `ArrayList`, `Vector` ve `LinkedList` `List`'in altındadır. Bunlar Java'da hazır tanımlanmış yapılardır, metotları da hazırdır. Uygulamada en sık `ArrayList` ve `LinkedList` kullanılacaktır, özellikle `ArrayList`.

> **Ek bilgi (derste anlatılmadı):** `Iterable`, `Collection` ve `List` sınıf değil arayüzdür. `ArrayList` ile `LinkedList`, `List` arayüzünü gerçekleyen somut sınıflardır. Bu yapılar `java.util` paketindedir; Eclipse bir `LinkedList` ya da `Iterator` yazıldığında import eklemeyi önerir.

### 5.2 ArrayList tanımı ve for-each

Liste tanımlanırken önce yapının adı (`ArrayList`) yazılır, sonra köşeli parantez içinde listenin hangi tipte veri tutacağı belirtilir. Bu tip `String`, `Integer` ya da kendi tanımladığımız bir sınıf (örneğin `Kitap`) olabilir.

> **Hocanın vurgusu:** Listenin hangi tipte veri tutacağının belirtilmesi önemlidir ve gereklidir.

Eleman eklemek diziye göre çok daha kolaydır. Dizide önce kaç elemanlı olduğu belirtilir, sonra bir for döngüsüyle tek tek doldurulur. Listede ise liste adı, nokta, `add` ve eklenecek değer yazmak yeter.

Ekrandaki ilk örnek dört şarkı adını bir listeye ekler ve iki yöntemle yazdırır (ekrandan, 00:20:00 ve 00:25:00):

```java
package collections;

import java.util.ArrayList;
import java.util.Iterator;

public class Ornek1 {

    public static void main(String[] args) {
        ArrayList<String> listem = new ArrayList<String>();
        listem.add("Haydar Haydar");
        listem.add("Dalgalandım Da Duruldum");
        listem.add("Benzemez Kimse Sana");
        listem.add("Gamzedeyim Devam Bulmam");

        System.out.println("1.Yöntem : foreach ile yazdırma ...");
        for (String obj : listem) {
            System.out.println(obj);
        }

        Iterator<String> itr = listem.iterator();

        System.out.println("\n2.Yöntem : Iterator ile yazdırma ...");
        while(itr.hasNext()) {
            System.out.println(itr.next());
        }
    }
}
```

For-each döngüsünde önce gezilecek verinin tipi (`String`), sonra her adımda o anki elemanı tutacak değişkenin adı (`obj`), iki nokta ve listenin adı yazılır. Her adımda `obj` sıradaki tek bir String değeri tutar. Liste `Kitap` nesneleri tutsaydı `obj.getAd()`, `obj.getFiyat()` gibi metotlarla nesnenin bilgileri alınırdı.

### 5.3 Iterator

İkinci yöntem `Iterator` sınıfıdır. Iterator, liste üzerinde sırayla ilerleyen bir imleç gibi düşünülebilir. Tanımında önce `Iterator`, köşeli parantez içinde gezilecek tip, sonra iterator'ın adı yazılır ve listenin `iterator()` metodu çağrılır: `Iterator<String> itr = listem.iterator();`.

Gezme işi bir `while` döngüsüyle yapılır:

- Iterator ilk oluşturulduğunda listenin başında durur ve hiçbir elemanı göstermez.
- `hasNext()` boolean döndürür: İmlecin ilerisinde eleman varsa `true`, yoksa `false`. `true` ise döngüye girilir.
- `next()` sıradaki elemanın içeriğini döndürür ve imleci ilerletir.
- Birinci eleman alındıktan sonra imlecin birinci ile ikinci elemanın arasında durduğu düşünülür. İkinci eleman alınınca ikinci ile üçüncünün arasındadır.
- Son eleman alınınca imleç sona varır, `hasNext()` `false` döner ve döngüden çıkılır.

Her iki yöntemin çıktısı da aynı dört satırdır (ekrandan, 00:25:00). Hocaya göre pratikte for-each daha kullanışlıdır.

## 6. ArrayList metotları: öğrenci listesi

İkinci örnekte (`Ornek2`) `collections` paketindeki `Student` sınıfı kullanılır. Bu sınıfın numara, ad ve yaş alanları, bunları alan bir constructor'ı ve getter metotları vardır (ekrandan, 00:50:00):

```java
public int getNo() {
    return no;
}

public String getName() {
    return name;
}

public int getAge() {
    return age;
}

@Override
public String toString() {
    return "Student [no=" + no + ", name=" + name + ", age=" + age + "]";
}
```

### 6.1 add ve listeyi gösteren metot

Ekranda önce üç öğrenci nesnesi `s1`, `s2`, `s3` oluşturulur, sonra `ArrayList<Student> stu_list` listesine `add` ile eklenir (ekrandan, 00:30:00). Aşağıdaki kodda öğrenci adları ve numaraları genel değerlerle değiştirilmiştir:

```java
Student s1 = new Student(101, "Ogrenci A", 20);
Student s2 = new Student(102, "Ogrenci B", 22);
Student s3 = new Student(103, "Ogrenci C", 19);

ArrayList<Student> stu_list = new ArrayList<Student>();
stu_list.add(s1);
stu_list.add(s2);
stu_list.add(s3);

System.out.println("İlk listenin Öğrencilerin isimleri...");
ListeGoster(stu_list);
```

Listeyi yazdırmak için statik bir `ListeGoster` metodu tanımlanmıştır (Eclipse'te statik metot çağrısı eğik yazıyla gösterilir). Metot parametre olarak `ArrayList<Student>` alır ve bir iterator ile gezer. Metodun kodu karelerde tam görünmüyor; yapısı altyazıdaki anlatıma ve çıktı biçimine (ad, numara, yaş) göre şöyledir:

```java
static void ListeGoster(ArrayList<Student> stu) {
    Iterator<Student> itr = stu.iterator();
    while (itr.hasNext()) {
        Student std = itr.next();
        System.out.println(std.getName() + ", " + std.getNo() + ", " + std.getAge());
    }
}
```

<!-- BELİRSİZ: ListeGoster metodunun gövdesi karede görünmüyor; çıktı biçimi kareden (ad, numara, yaş), yapı altyazıdan alındı. -->

`itr.next()` bir `Student` nesnesi döndürdüğü için ayrı bir `std` değişkeni tanımlamak zorunlu değildir; doğrudan `itr.next().getName()` de yazılabilir. Ama her `next()` çağrısı imleci ilerlettiği için bir elemanın birden çok alanı okunacaksa nesneyi bir değişkene atamak gerekir. Anlatımda bu biçim adımları göstermek için seçildi. Aynı iş for-each ile `for (Student std : stu)` diye de yapılabilir.

### 6.2 addAll

İkinci liste `stu_list2` tanımlanır. Bu sefer önce nesne oluşturup sonra eklemek yerine nesne doğrudan `add` içinde oluşturulur: `stu_list2.add(new Student(...));`. Böylece ikinci listeye üç öğrenci eklenir.

`add` tek bir nesne ekler; `addAll` ise başka bir koleksiyonun bütün elemanlarını ekler. `stu_list.addAll(stu_list2);` sonrasında birinci listede altı öğrenci olur. `ListeGoster` önce ilk listenin üç öğrencisini, sonra ikinci listenin üç öğrencisini yazar (ekrandan, 00:35:00).

### 6.3 remove ve removeAll

`remove(indis)` verilen indisteki elemanı siler. İndis dizilerdeki gibi 0'dan başlar; `remove(3)` 0, 1, 2, 3 sayılarak dördüncü sıradaki elemanı, yani ikinci listeden gelen ilk öğrenciyi siler. Liste 5 elemana düşer.

`removeAll(liste)`, `addAll`'ın tersidir: Verilen listenin elemanlarını listeden çıkarır. `stu_list.removeAll(stu_list2)` çağrısında ikinci listenin geriye kalan iki elemanı silinir ve liste yalnız ilk üç öğrenciden oluşur.

### 6.4 retainAll

İkinci liste yeniden `addAll` ile eklenir ve liste tekrar altı elemanlı olur. `retainAll(liste)` "şu listeyi tut" anlamına gelir: Verilen listedeki elemanları tutar, geri kalanları siler. `stu_list.retainAll(stu_list2)` sonrasında yalnız ikinci listenin üç öğrencisi kalır (ekrandan, 00:40:00).

Ajan, örneği genel adlarla `java Ornek2.java` üzerinde çalıştırdı. Sıra şöyledir: 3 eleman, `addAll` ile 6, `remove(3)` ile 5, `removeAll` ile ilk üç öğrenci, `addAll` ve `retainAll` ile ikinci listenin üç öğrencisi.

## 7. LinkedList, Iterator ve ListIterator

### 7.1 LinkedList tanımı

`LinkedList` de `List` arayüzünü gerçekler. Tanımı ve metotları `ArrayList` ile aynıdır. Ekrandaki örnekte (`Ornek3`) karakter tutan bir liste oluşturulur, üç karakter eklenir ve iterator ile yazdırılır (ekrandan, 00:40:00 ve 00:45:00; karakterler genel değerlerle değiştirildi):

```java
LinkedList<Character> harf = new LinkedList<Character>();
harf.add('A');
harf.add('B');
harf.add('C');

Iterator<Character> itr = harf.iterator();
while (itr.hasNext()) {
    System.out.println(itr.next());
}
```

Çıktıda üç karakter alt alta yazılır. `LinkedList` ya da `Iterator` yazıldığında Eclipse bunların `java.util` paketinden import edilmesini ister.

### 7.2 Liste değişkenini List tipiyle tanımlamak

Dördüncü örnekte (`Ornek4`) değişken yalnız `List` tipiyle tanımlanır: `List<Book> kitaplar = new LinkedList<Book>();`. `ArrayList` ve `LinkedList`, `List`'i gerçeklediği için değişken üst tipin adıyla tanımlanıp alt sınıfın nesnesi oluşturulabilir.

Aynı dosyanın üst kısmında bir `Book` sınıfı tanımlanmıştır. Sınıfın id, ad, yazar ve yayınevi alanları ve bu dört bilgiyi alan bir constructor'ı vardır. İki kitap nesnesi oluşturulup `kitaplar.add(b1)`, `kitaplar.add(b2)` ile eklenir.

<!-- BELİRSİZ: Book sınıfının ve kitap nesnelerinin tanım satırları karelerde görünmüyor; alan adlarından name, author ve publisher karelerde geçiyor. -->

For-each ile kitapların adı ve yazarı yazdırılır (ekrandan, 00:45:00):

```java
System.out.println("Kitap listesi for each ile...");
for (Book kitap : kitaplar) {
    System.out.println(kitap.name + ", " + kitap.author);
}
```

Burada getter kullanılmadan `kitap.name` diye doğrudan erişilir. Bunun nedeni, `Book` sınıfının alanlarının `private` tanımlanmaması ve sınıfın aynı dosyada (aynı pakette) olmasıdır.

### 7.3 ListIterator

`ListIterator`, `Iterator`'a benzer ama ek metotları vardır. Oluşturmak için listenin `listIterator()` metodu çağrılır (ekrandan, 00:45:00):

```java
System.out.println("\nKitap listesi ListIterator ile...");
ListIterator<Book> itr = kitaplar.listIterator();

while(itr.hasNext()) {
    System.out.println(itr.next().name);
}

while(itr.hasPrevious()) {
    System.out.println(itr.previous().name);
}
```

Birinci döngü `hasNext()`/`next()` ile iki kitabı baştan sona gezer ve adlarını yazar. `next()` bir `Book` nesnesi döndürdüğü için arkasına `.name` eklenir. Liste String tutsaydı yalnız `next()` yeterdi. Birinci döngü bittiğinde imleç son elemanın arkasındadır.

`hasPrevious()` imlecin gerisinde eleman olup olmadığını söyler. İmleç sonda olduğu için `true` döner ve ikinci döngüye girilir. `previous()` bir öndeki elemanı döndürür ve imleci geri alır. Böylece kitap adları ters sırada yazılır: önce son kitap, sonra ilk kitap.

> **Hocanın vurgusu:** `hasPrevious()` döngüsü en başa, iterator listenin başındayken yazılsaydı `false` dönerdi ve hiçbir şey yazılmazdı. Geriye gezebilmek için önce `next()` ile ileri gidilmiş olmalıdır.

## 8. get, indisli add ve toString

Beşinci örnekte (`Ornek5`) iki liste tanımlanır. Değişkenler `List` tipindedir; biri `LinkedList` (kitaplar), diğeri `ArrayList` (öğrenciler) olarak oluşturulur. Kitaplar ve öğrenciler `add` ile eklenir.

Ekleme `add` ile, silme `remove` ile yapılır; eleman almak için ise `get(indis)` kullanılır. Öğrenci listesinde `get(0)` en baştaki öğrenciyi, kitap listesinde `get(0)` ilk kitabı döndürür.

Bu nesnelerin `System.out.println` ile okunaklı yazılabilmesi `toString()` metodunun override edilmiş olmasına bağlıdır. Eclipse'te Source menüsünden "Generate toString()" seçilerek bu metot otomatik oluşturulur. Ekrandaki çıktı (ekrandan, 00:50:00; öğrenci adları ve numaraları gizlendi):

```text
Student [no=..., name=..., age=20]
Book [id=1, name=Bir Türk Ailesinin Öyküsü, author=İrfan Orga, publisher=Everest Yayınları]
Student [no=..., name=..., age=22]
```

`toString()` yazılmasaydı ekranda nesnenin bellekteki yerini gösteren, sayılardan oluşan bir kod görünürdü.

`add` metodunun ikinci bir biçimi indis alır: `add(indis, nesne)`. Normal `add` hep sona ekler; bu biçim ise belirtilen yere ekler ve oradaki elemanları bir sağa kaydırır. Öğrenci listesinde `add(0, s2)` çağrıldıktan sonra `get(0)` artık `s2` nesnesini döndürür. Çıktının üçüncü satırı bunu gösterir.

### 8.1 ArrayList ve LinkedList farkı

`ArrayList`, belirli bir indisteki elemana erişmede daha hızlı olabilir. `LinkedList` ise eleman eklemede daha hızlı olabilir. Ders projelerinin ölçeğinde bu performans farkı önemsizdir, ikisi de istenildiği gibi kullanılabilir.

## 9. Map ve HashMap

Şimdiye kadarki listeler tek tipte değer tutuyordu: öğrenci, kitap, String ya da Integer. Map yapıları ise değerleri anahtar–değer (key–value) çifti olarak tutar.

Map yapılarını koleksiyon diye anmak tam doğru değildir. Bunlar ayrı bir `Map` hiyerarşisinde bulunur, çünkü listelerden farklı olarak her kayıt bir anahtar ile bir değerden oluşur. Bu derste `HashMap` kullanılır.

`HashMap` tanımında iki tip yazılır: Birincisi anahtarın, ikincisi değerin tipidir. Örnekte anahtar `Integer`, değer `String`'dir. Anahtarın Integer olması gerekmez; anahtar String ya da başka bir tip de olabilir.

> **Hocanın vurgusu:** Bir map'te anahtar tekildir, aynı anahtardan ikinci bir tane olamaz. Değerler ise farklı kayıtlarda aynı olabilir.

### 9.1 put, get ve size

Eleman eklemek için `add` yerine `put(anahtar, değer)` kullanılır. Anahtar ile değer birlikte kaydedilir. Ekrandaki örnek (`Ornek6`) şöyledir (ekrandan, 00:55:00; değerler genel adlarla değiştirildi):

```java
HashMap<Integer, String> map = new HashMap<>();
map.put(5, "Ali");
map.put(1, "Veli");
map.put(17, "Can");

//map.put(5, "Ece");  sizce bu satır ne yapar? hata mı verir?

System.out.println(map);

System.out.println(map.get(5));

System.out.println(map.size());
```

Yorum satırındaki soru öğrencilere sorulur: Aynı anahtara (5) ikinci bir `put` yapılırsa ne olur? Cevap: Hata vermez; 5 anahtarının değeri yeni değerle değiştirilir.

`System.out.println(map)` bütün çiftleri `{1=Veli, 17=Can, 5=Ali}` biçiminde yazar. Map'lerde `get` indis değil anahtar alır: `map.get(5)` anahtarı 5 olan kaydın değerini (`Ali`) döndürür. `size()` kayıt sayısını, yani 3'ü döndürür.

### 9.2 entrySet ile gezme

Map'i satır satır gezip her kaydın anahtarını ve değerini almak için iki metot vardır: anahtar için `getKey()`, değer için `getValue()`. Bunlar `Entry` nesneleri üzerinden çağrılır. `Entry` nesnelerine de map'in `entrySet()` metoduyla ulaşılır (ekrandan, 01:00:00):

```java
for (Entry<Integer, String> m : map.entrySet()) {
    System.out.println(m.getValue() + ", " + m.getKey());
}
```

Burada önce değer, sonra anahtar yazdırıldığı için çıktı `Veli, 1`, `Can, 17`, `Ali, 5` olur.

Çıktının sırası ekleme sırasıyla aynı değildir. `HashMap`'in sıralı tutma zorunluluğu yoktur. `LinkedHashMap` kullanılsaydı kayıtlar ekleme sırasıyla gelirdi.

> **Ek bilgi (derste anlatılmadı):** Anlatımda sıranın "rastgele" olduğu söylendi. Aslında `HashMap`'in sırası anahtarların hash değerlerine göre belirlenir; aynı anahtarlarla aynı sıra elde edilir, ama bu sıraya güvenilmemelidir. Anahtara göre sıralı bir map için `TreeMap` kullanılır.

### 9.3 replace, remove ve clear

Ekrandaki devam kodu şöyledir (ekrandan, 01:00:00; değerler genel adlarla değiştirildi):

```java
map.replace(17, "Can", "Deniz");   //map.put(17, "Deniz");
System.out.println(map);

map.remove(5);
System.out.println(map);

map.clear();
System.out.println(map.get(17));
```

- `replace(anahtar, eski, yeni)`: Verilen anahtarın değeri gerçekten "eski" ise "yeni" ile değiştirilir. Aynı iş `put(17, "Deniz")` ile de yapılabilir.
- `remove(anahtar)`: İndis değil anahtar alır; `remove(5)` 5 anahtarlı kaydı siler.
- `clear()`: Map'i tamamen boşaltır. Sonrasında hangi anahtar verilirse verilsin `get` `null` döndürür.

Ekrandaki çıktı satırları sırasıyla şunlardır: `{1=..., 17=..., 5=...}`, 5 anahtarının değeri, `3`, entrySet döngüsünün üç satırı, `replace` sonrası map, `remove` sonrası iki kayıtlı map ve `null`.

> **Ders sonrası not:** Anlatımda `clear()` için "map'i null hâline getirecek" dendi. Doğrusu, `clear()` map nesnesini `null` yapmaz, içini boşaltır: `map` hâlâ geçerli ve boş bir nesnedir (`System.out.println(map)` `{}` yazar). `null` dönen, var olmayan bir anahtar için çağrılan `get` metodudur.

Bir öğrencinin sorusu üzerine `replace` metodunun eski değer eşleşmediğinde ne yaptığı denendi (bkz. Örnek Sorular).

### 9.4 Map arayüzü tipiyle tanımlama

Listelerdeki gibi değişken üst tipin adıyla da tanımlanabilir: `Map<Integer, String> map = new HashMap<>();`. `HashMap`'in gerçeklediği üst yapı `Map` arayüzüdür. Bu durumda `java.util.Map` import edilmelidir; Eclipse import eksikse uyarır.

## 10. Generics

Generics ile bir bakıma kendi koleksiyonumuz kurulur. `ArrayList` ya da `HashMap`'te verilen tipe göre bir yapı oluşturuluyor ve onun metotları çalışıyordu. Generics ile sınıf ya da metot, tipini baştan değil, kullanıldığı anda alacak biçimde yazılır.

Motivasyon şudur: Integer dizisi gezmek ile Double dizisi gezmek farklıdır. For-each döngüsünde tip yazılması gerektiği için her tipe ayrı bir döngü, ya da "Integer ise şöyle, Double ise böyle" diye `if-else` kurmak gerekir. Bu gereksiz kod tekrarıdır. Bunun yerine bir tip parametresi tanımlanır ve kod gelen veri tipine göre şekil alır.

### 10.1 Generic sınıf

Ekrandaki ilk generic örnek şöyledir (ekrandan, 01:05:00):

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
        System.out.println(obj1 + "\t" + obj2);
    }
}

public class Ornek1 {

    public static void main(String[] args) {
        Test <String, Integer> t1 = new Test<String, Integer>("NYP", 2020);
        t1.print();
        // ikinci nesne Character tipleriyle oluşturuluyor
    }
}
```

Sınıf adından sonra köşeli parantez içine yazılan harfler (`T`, `U`) sınıfın kaç tip parametresiyle çalışacağını gösterir. `T obj1;` satırı normal bir alan tanımı gibidir; tek fark, tipin `String` ya da `Integer` diye baştan yazılmamasıdır. Nesneye String gönderilirse String, Integer gönderilirse Integer olur. Constructor'da dışarıdan gelen değerler `this` ile sınıfın alanlarına atanır.

`main` içinde nesneyi oluşturan kişi tiplere o an karar verir. `Test<String, Integer>` denince constructor'a bir String ve bir Integer verilmelidir. `t1.print()` iki değeri aralarında bir sekme boşluğuyla yazar: `NYP	2020`.

İkinci nesne iki `Character` tipiyle oluşturulur ve tek karakterler verilir. Çıktı `3	B` olur (ekrandan, 01:10:00).

<!-- BELİRSİZ: İkinci nesnenin tanım satırı karede görünmüyor; Character tipi altyazıdan, '3' ve 'B' değerleri karedeki çıktıdan alındı. -->

### 10.2 Generic metot

İkinci örnekte (`Ornek2`) üç dizi tek bir metotla yazdırılır (ekrandan, 01:10:00):

```java
public static <E> void printArray(E[] inputArray) {
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
```

<!-- BELİRSİZ: Metot imzası satırı karenin üstünde kalıyor; `public static <E> void printArray(E[] inputArray)` biçimi altyazıdaki anlatımdan ve gövdeden kuruldu. -->

`printArray` statik bir metottur ve nesne oluşturmadan çağrılır. Parametresi `E` tipinde bir dizidir; Integer mı Double mı gönderileceği belirtilmez. For-each döngüsünde `element` her adımda dizinin bir elemanını tutar. `print` kullanıldığı için elemanlar yan yana, aralarında boşlukla yazılır; döngü bitince `println()` ile satır sonu verilir. Çıktı (ekrandan, 01:15:00):

```text
Array integerArray contains:
1 2 3 4 5

Array doubleArray contains:
1.1 2.2 3.3 4.4

Array characterArray contains:
H E L L O
```

Dönüş tipinden önceki `<E>` ifadesi önemlidir. Bu yazılmazsa derleyici parametredeki `E`'yi tanımaz ve "böyle bir tip yok" diye hata verir. `<E>`, `E`'nin Integer ya da String gibi bir tip olarak kullanılacağını bildirir.

Örnekler ajan tarafından `java Ornek1.java` ile çalıştırıldı; çıktılar karedekiyle aynıdır.

## 11. İstisnalar ve try-catch

### 11.1 Sözdizimi hatası, istisna ve Error

Kodda noktalı virgül unutmak gibi yanlışlar sözdizimi (syntax) hatasıdır ve derleyici bunları hemen gösterir. Tanımlanmamış bir nesne üzerinden metot çağırmak gibi hatalar da derleyici tarafından o anda bildirilir. Bazı sorunlar ise derleme ya da çalışma anında ortaya çıkar. Bunlara istisna (exception) denir.

"Exception" Türkçeye "hata" diye çevrilmez, "istisna" denir. Hatalar (Error) sistemin ölümcül sorunlarıdır: kaynak yetersizliği, çeşitli çakışmalar gibi, kod üzerinden çözülemeyecek durumlar. İstisnalar ise programcının yönetebileceği durumlardır.

Hiyerarşide `Error` ve `Exception` aynı üst sınıftan gelir. Altyazıda bu sınıfın adı bozuk yazılmıştır; doğrusu `Throwable`'dır. `Exception` sınıfının alt sınıfları vardır: `ArithmeticException`, `NullPointerException` gibi.

### 11.2 Sıfıra bölme

`int a = 5/0;` satırı derleyiciden hata almaz; Eclipse yalnız `a` değişkeninin kullanılmadığını söyleyen sarı bir uyarı gösterir. Program çalıştırılınca `ArithmeticException: / by zero` istisnası fırlatılır; istisnanın tipi ve satırı da konsola yazılır. Bu satırdan sonra yüzlerce satır kod olsa bile hiçbiri çalışmaz, program orada kesilir.

İstenen davranış genelde şudur: Hata oluşursa ilgili uyarı yapılsın, ilgili işlem yapılsın, ama kodun geri kalanı çalışmaya devam etsin. Bunun için `try-catch` yapısı kullanılır.

### 11.3 try-catch yapısı

Hata çıkarabilecek kod bloğu `try` bloğunun içine alınır. `try`'ın hemen ardından gelen `catch` bloğu hata yakalamakla görevlidir. `try` içindeki kod okunurken bir istisna oluşursa uygun `catch` bloğu çalıştırılır. `catch` parantezine yakalanacak istisnanın sınıfı ve bir değişken adı yazılır: `catch (Exception e)`. `Exception` en genel istisna sınıfıdır ve bütün istisnaları kapsar.

Ekrandaki örnek (ekrandan, 01:20:00):

```java
package exceptions;

public class Example {

    public static void main(String[] args) {

        try {
            int a = 5/0;
        } catch (Exception e) {
            System.out.println("hata yakalandı.");
        }

        System.out.println("kodun devamı.");
    }
}
```

<!-- BELİRSİZ: Karede try'dan sonra yarım kalmış bir "}catch" satırı ve ayrı bir catch(Exception e) bloğu görünüyor (düzenleme anı); yukarıdaki kod, karedeki çıktıyı veren derlenebilir hâlidir. -->

Çıktı `hata yakalandı.` ve `kodun devamı.` satırlarıdır. `try` içinde sıfıra bölme görülür, bu bir `Exception` olduğu için `catch` bloğu çalışır. İstisna yönetildiği için program kesilmez ve sonraki satırı da yazdırır.

### 11.4 Daha özel bir catch

`catch (Exception e)` bloğunun önüne `catch (ArithmeticException e)` gibi daha özel bir blok eklenirse istisna önce ona uyar. Sıfıra bölme bir `NullPointerException` değil `ArithmeticException` olduğu için özel blok çalışır; en genel olan `Exception` bloğuna gelinmez. Ardından kodun devamı çalışır.

> **Ek bilgi (derste anlatılmadı):** Catch blokları yukarıdan aşağı denenir ve ilk uyan çalışır. Bu yüzden özel istisnalar genel olanlardan önce yazılmalıdır. `catch (Exception e)` bloğu `catch (ArithmeticException e)` bloğundan önce yazılırsa ikinci blok hiç erişilemez olur ve kod derlenmez.

## 12. Birden çok catch ve printStackTrace

`exceptions` paketindeki `Ornek1` iki değişken tanımlar: `int a = 1;` ve 5 elemanlı `int[] b`. Ekrandaki kodun görünen kısmı şöyledir (ekrandan, 01:25:00):

```java
        b[10] = a;
    } catch (ArrayIndexOutOfBoundsException aiobe) {
        //aiobe.printStackTrace();
        System.out.println("dizi sınırı aşıldı");
        b[b.length-1] = 3;

    } catch (ArithmeticException ae) {
        //ae.printStackTrace();
        System.out.println("sıfıra bölmeye çalışıldı");
        a = 2;

    } catch (Exception e) {
        e.printStackTrace();
    }

    a = a * 5;
    System.out.println("a'nin son degeri: " + a);
    System.out.println("b dizisi son elemanın değeri: " + b[b.length-1]);
```

`try` bloğunda önce `a = a/0;` (a sıfıra bölünüp a'ya atanır), sonra `b[10] = a;` satırı vardır.

<!-- BELİRSİZ: Dosyanın başı (a ve b tanımları, try ve a = a/0 satırı) karede görünmüyor; altyazıdan alındı. -->

### 12.1 Birinci çalıştırma: sıfıra bölme

1. `a = a/0;` satırında istisna fırlatılır. `b[10] = a;` satırına hiç geçilmez.
2. İstisna sırayla catch bloklarıyla karşılaştırılır. Sıfıra bölme bir dizi indisi hatası değildir, bu yüzden `ArrayIndexOutOfBoundsException` bloğu çalışmaz.
3. `ArithmeticException` bloğu uyar: `sıfıra bölmeye çalışıldı` yazılır ve `a = 2` yapılır. En genel `Exception` bloğuna gelinmez.
4. Catch bloklarından sonra kod devam eder: `a = a * 5` ile `a` 10 olur.
5. `b.length - 1 = 5 - 1 = 4`, yani son elemanın indisi 4'tür. `b` üzerinde hiçbir işlem yapılmadığı ve int dizisinin elemanları başlangıçta 0 olduğu için son eleman 0'dır.

Çıktı: `sıfıra bölmeye çalışıldı`, `a'nin son degeri: 10`, `b dizisi son elemanın değeri: 0`. Ajan aynı kodu `java` ile çalıştırdı ve bu sonucu aldı.

### 12.2 İkinci çalıştırma: dizi sınırı

Sıfıra bölme satırı yorum satırı yapılır ve kod yeniden çalıştırılır.

1. `try` içinde ilk satır artık `b[10] = a;` olur. `b` 5 elemanlıdır, 10 numaralı indis yoktur.
2. `ArrayIndexOutOfBoundsException` fırlatılır: dizinin sınırları dışına çıkılmaya çalışılmıştır.
3. İlk catch bloğu uyar: `dizi sınırı aşıldı` yazılır ve son eleman 3 yapılır (`b[b.length-1] = 3`).
4. `a` başta 1'dir; `a = a * 5` ile 5 olur.

Ekrandaki çıktı (ekrandan, 01:25:00):

```text
dizi sınırı aşıldı
a'nin son degeri: 5
b dizisi son elemanın değeri: 3
```

### 12.3 printStackTrace

Koddaki `aiobe.printStackTrace();` satırı yorumdan çıkarılınca, yakalanan istisna hakkında bilgi yazdırılır. Burada `ArrayIndexOutOfBoundsException` sınıfın adı, `aiobe` ise o sınıftan bir nesne gibi düşünülebilir. Bu nesne üzerinden çağrılan `printStackTrace()` hatanın tipini, nedenini (hangi indisten, burada 10. indisten kaynaklandığını) ve kaçıncı satırda oluştuğunu (örnekte 11. satır) yazar. Bilgi yazdırıldıktan sonra kodun geri kalanı yine çalışır.

## 13. NullPointerException ve finally

`Ornek2`'de `Integer` tipinde bir `data` değişkeni vardır. `try` içinde `data`'ya `null` atanır ve ardından `data`'nın değeri bir metotla alınmaya çalışılır. Bu, uygulamalarda en sık karşılaşılan istisnalardan birini verir: `null` bir değer üzerinden metot çağrılırsa `NullPointerException` fırlatılır. Uygulama ve lab sorularında `if (x != null)` kontrolünün yazılmasının nedeni budur.

<!-- BELİRSİZ: Bu örneğin kodu karelerde görünmüyor; aşağıdaki iskelet altyazıdan kuruldu. -->

```java
Integer data;
try {
    data = null;
    System.out.println(data.intValue());
} catch (NullPointerException e) {
    System.out.println(e);
} finally {
    data = 5;
    System.out.println("Her zaman çalışır");
}
System.out.println(data);
```

`catch` içinde `System.out.println(e)` istisnanın bağlı olduğu sınıfın adını yazar, yani "NullPointerException sınıfından bir istisna geldi" bilgisini verir.

`try-catch` yapısına bir de `finally` bloğu eklenebilir (altyazıda "final" diye geçer). `finally` bloğu her zaman çalışır: `try` içinde ne olursa olsun, istisna yakalansa da yakalanmasa da. Örnekte `finally` bloğu `data`'yı 5 yapar ve "her zaman çalışır" mesajını yazar. Son satır da 5 yazar.

`data` `null` yerine `0` yapılırsa durum değişir. Artık `data` boş değildir, değeri 0'dır; `intValue()` çağrılabilir ve 0 yazılır. Hiçbir catch çalışmaz, ama `finally` yine çalışır: `data` 5 olur, mesaj yazılır, son satır 5 yazar.

> **Ders sonrası not:** Derste kullanılan Java 8'de `System.out.println(e)` yalnız `java.lang.NullPointerException` yazar. Java 14 ve sonrasında, yardımcı NullPointerException mesajları nedeniyle aynı satır, hangi değişkenin `null` olduğunu anlatan bir açıklama da ekler (ajanın Java 25 denemesinde görüldü).

## 14. throw, throws, checked ve unchecked istisnalar

### 14.1 throw ile istisna fırlatmak

`Ornek3`'te `throw` anahtar kelimesiyle kendimiz istisna fırlatırız. Örnek bir oy kullanma kontrolüdür (ekrandan, 01:30:00):

```java
package exceptions;

public class Ornek3 {

    public static void main(String[] args) {
        int age = 23;

        if(age < 18) {
            throw new ArithmeticException("Not valid");

        }else{
            System.out.println("Welcome to vote");
            System.out.println("Rest of the code");
        }

        System.out.println("devam..");
    }
}
```

`age` 23 iken `if` bloğuna girilmez; `else` bloğu çalışır ve çıktı `Welcome to vote`, `Rest of the code`, `devam..` olur. `age` 18'den küçük yapılırsa `throw` satırı çalışır: Konsolda `ArithmeticException` ile birlikte bizim yazdığımız "Not valid" mesajı görünür ve kodun devamı hiç çalışmaz. Mesaj istenildiği gibi yazılabilir. Bu durumu yönetip devam etmek isteseydik bu kısmı da bir `try-catch` içine almamız gerekirdi. Aksi hâlde `throw` çalıştığı anda kod o noktada kesilir.

Ajan `age = 15` ile denedi: Program `Exception in thread "main" java.lang.ArithmeticException: Not valid` yazarak sonlandı ve `devam..` yazılmadı.

### 14.2 throw ile throws farkı

`throw` ve `throws` birbirine karıştırılabilir:

- `throw`: Kod içinde bir satırdır. `throw new ...` denip istisna tipi ve mesajı belirtilerek o anda bir istisna fırlatılır.
- `throws`: Metot imzasına eklenir. "Bu metodun içinde istisna fırlatılabilecek bir durum var, bunu yönetmen gerekebilir" bilgisini verir. `throws` yalnız `main` metoduna değil, kendi yazdığımız herhangi bir metoda da eklenebilir.

### 14.3 Checked ve unchecked istisnalar

Eclipse ve Java derleyicileri bazı durumlarda `throws` kullanmaya ya da `try-catch` yazmaya zorlar. Bu genellikle dosya açma–kapama ya da veritabanı bağlantısı kurma gibi işlemlerde olur. Böyle işlemlerde bir sorun çıkabilir ve derleyici, sorun oluşursa uyarı verilebilmesi için bir yönetim mekanizması ister.

Örnek olarak `DriverManager` ile bir URL'deki veritabanına bağlantı kuran bir satır yazılır. Eclipse hemen "Unhandled exception type SQLException" hatası verir. İki çözüm önerir: metoda `throws SQLException` eklemek ya da satırı `try-catch` içine almak. `try-catch` seçilince Eclipse satırı otomatik olarak sarar, çünkü burayı riskli bir nokta olarak görür: Bağlantı kurulabilir de kurulamayabilir de.

<!-- BELİRSİZ: Veritabanı bağlantı satırının tam metni karelerde görünmüyor. -->

Bu istisnalara checked (denetlenen) istisnalar denir: Kod yazılıp derlenirken derleyici bunları denetler ve uyarır. `IOException` (dosya işlemleri) ve `SQLException` (veritabanı işlemleri) bu gruptadır.

`ArithmeticException` ve `NullPointerException` gibi istisnalar ise yazıldığı anda bir uyarı üretmez ve `try-catch` içine alınmaları zorunlu değildir. Bunlar çalışma anında (runtime) ortaya çıkar ve unchecked (denetlenmeyen) istisnalar diye anılır. Bunları önlemek geliştiricinin sorumluluğundadır; örneğin `null` kontrolü yazmak gibi.

> **Ek bilgi (derste anlatılmadı):** Unchecked istisnalar `RuntimeException` sınıfından türeyenlerdir (`ArithmeticException`, `NullPointerException`, `ArrayIndexOutOfBoundsException`). `Exception`'dan türeyip `RuntimeException`'dan türemeyenler checked istisnalardır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:55:00): Bir `HashMap<Integer, String>` için `map.put(5, ...)` ile 5 anahtarına bir değer konmuştur. Ardından `map.put(5, <başka bir değer>);` satırı çalıştırılırsa ne olur? Hata verir mi?

> **Çözüm (derste verildi):** Hata vermez. Map'te anahtar tekildir. Aynı anahtarla yapılan ikinci `put`, o anahtarın eski değerini yenisiyle değiştirir ve map'teki kayıt sayısı değişmez. Ajan denemesinde `put(5, "Ali")` ve ardından `put(5, "Ece")` sonrasında map `{5=Ece}` yazdı.

**Soru 2** (derste sözlü, 01:00:49): `replace(anahtar, eskiDeğer, yeniDeğer)` metodunda verilen eski değer, anahtarın gerçek değeriyle eşleşmezse değer yine de değişir mi?

> **Çözüm (derste verildi):** Değişmez. Derste denendi ve değer değişmedi. Bu biçim bir kontrol mekanizması içerir: Değişiklik yalnız eski değer doğru verilmişse yapılır. Ajan denemesinde eşleşmeyen eski değerle yapılan `replace` çağrısı `false` döndürdü ve map aynı kaldı.

## Dersin Toparlaması

Bu uygulama oturumunda önce soyut sınıflar hatırlatıldı. Ardından çoklu kalıtım ihtiyacını karşılayan arayüzler anlatıldı: metotların gizli olarak soyut olması, gövde için `default` ya da `static` gerekmesi, `implements` ile birden çok arayüz alma ve arayüzler arasında `extends`. Sonra Java'nın hazır koleksiyonları işlendi. `ArrayList` ve `LinkedList` için ekleme, silme, birleştirme, tutma ve indisle erişim metotları; for-each, `Iterator` ve iki yönlü `ListIterator` ile gezme; `toString()`'in önemi gösterildi. Anahtar–değer tutan `HashMap` için `put`, `get`, `entrySet`, `replace`, `remove` ve `clear` örneklendi.

Generics bölümünde tipini kullanım anında alan sınıf (`Test<T, U>`) ve tek döngüyle her tipten diziyi yazdıran metot (`<E> printArray`) görüldü. Son bölümde istisnalar anlatıldı: `try-catch` ile programın kesilmeden devam etmesi, özel ve genel catch blokları, `printStackTrace`, her zaman çalışan `finally`, `throw` ile `throws` farkı ve derleme anında denetlenen (checked) istisnalarla çalışma anında ortaya çıkan (unchecked) istisnalar arasındaki ayrım.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
