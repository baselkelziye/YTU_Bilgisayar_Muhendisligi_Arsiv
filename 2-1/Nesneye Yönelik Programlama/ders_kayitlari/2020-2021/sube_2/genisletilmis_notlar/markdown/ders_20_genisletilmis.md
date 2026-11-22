# Ders 20 Genişletilmiş Notu: Uygulama 4: Tip Dönüşümleri, Dosya İşlemleri ve Serileştirme, İç Sınıflar ve Thread'lere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun kapsamı
- 2. İlkel tiplerde tip dönüşümü
- 3. Nesnelerde tip dönüşümü: upcasting ve downcasting
- 4. Dosya işlemleri: oluşturma, yazma, okuma, silme
- 5. Nesne serileştirme ve geri okuma
- 6. İç sınıflar (inner class)
- 7. Thread'lere giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun kapsamı

Bu kayıt dönemin son uygulama oturumudur. Dört konu hazır Java örnekleriyle Eclipse üzerinde gösterilir: önce tip dönüşümleri (type casting), sonra dosya işlemleri ve nesnelerin dosyaya yazılıp okunması, ardından henüz teori derslerinde işlenmemiş iki konuya giriş düzeyinde bakılır: iç sınıflar (inner class) ve çok iş parçacıklı programlama (multithreading). Örnek dosyalar `typecasting`, `files`, `inner_class` ve `multithreading` paketlerindedir.

Notlardaki kodlar ekrandaki kodlardır. Karelerde görünmeyen birkaç satır anlatımdan kurulmuş ve bu durum yanlarında belirtilmiştir. Bütün örnekler bu not hazırlanırken Java 25'in tek dosya çalıştırıcısıyla (`java Dosya.java`) denenmiş ve ekrandaki çıktıların aynısı elde edilmiştir.

## 2. İlkel tiplerde tip dönüşümü

### 2.1 Genişletme ve daraltma

Casting, bir değerin bir tipten başka bir tipe dönüştürülmesidir. İlkel (primitive) tipler, C dilinden de bilinen `int`, `double`, `char` gibi tiplerdir. `PrimitiveCasting` sınıfının başında şu yorum vardır (ekrandan, 00:10:00):

```java
// byte -> short -> char -> int -> long -> float -> double
```

Bu sırada sağa doğru gitmek **genişletme** (widening), sola doğru gitmek **daraltma** (narrowing) olarak adlandırılır. Genişletmenin sezgisi şöyle anlatılır: bir tamsayının ondalık kısmı yoktur, `double` ise hem tam kısmı hem ondalık kısmı tutabilen daha geniş bir tiptir. Bu yüzden `int` → `double` dönüşümünde bilgi kaybolmaz. Tersinde, `double` → `int` dönüşümünde ondalık kısım alınmaz, yani veri kaybı olur.

> **Ders sonrası not:** Ekrandaki zincirde `short -> char` adımı bir genişletme değildir. `short` işaretli, `char` işaretsiz 16 bitlik bir tiptir ve bu ikisi arasındaki dönüşüm elle yapılmalıdır. Zincir büyük olasılıkla `byte -> short -> int -> long -> float -> double` ve `char -> int -> long -> float -> double` biçiminde iki kol olarak düşünülmelidir.

### 2.2 Genişletme örnekleri

Ekrandaki kod (ekrandan, 00:10:00):

```java
public static void main(String[] args) {

    // byte -> short -> char -> int -> long -> float -> double

    //wadening casting - automatic   (ekrandaki yazım; doğrusu widening)
    int x = 5;
    double y = x;
    System.out.println(x);
    System.out.println(y);

    char c = 'A';
    int c_i = c;
    System.out.println(c_i); //ascii tablosundan dönüşüm yapıyor.

    //narrowing casting - manual
    double a = 7.8;
    ...
```

`x` değeri `5` olarak, `double` olan `y` ise `5.0` olarak yazılır; virgülden sonraki kısım eklenmiştir ve bu bir genişletmedir. `char` tek bir karakter tutar; büyük harf, küçük harf ya da rakam olabilir ve her karakterin ASCII tablosunda bir sayı karşılığı vardır. `char` tablodaki sırada `int`'in solunda, yani daha dar bir tip olduğundan `char` → `int` de genişletmedir. `'A'` karakterinin karşılığı `65` olarak yazılır.

### 2.3 Daraltma örneği

`double a = 7.8;` değeri tamsayıya çevrilmek istendiğinde derleyici otomatik dönüşüm yapmaz; dönüşüm parantez içinde hedef tip yazılarak elle yapılır. Sonuç ekrana `7` olarak yazılır: ondalık kısım yuvarlanmadan atılmıştır (çıktı ekrandan, 00:10:00). Bu satırın kodu karede tam görünmez; anlatıma göre şu biçimdedir (ara adım eklendi):

```java
double a = 7.8;
int b = (int) a;   // değişken adı karede görünmüyor
System.out.println(b);  // 7
```

Daraltma daha risklidir ve dikkat ister; genişletme ise rahatça yapılabilir.

### 2.4 String'den sayıya: parse

Metin hâlindeki sayıların dönüşümü casting ile değil, sarmalayıcı sınıfların parse metotlarıyla yapılır. İçinde `80` yazan bir String hem `double`'a hem `int`'e çevrilebilir:

```java
String s = "80";                       // değişken adları karede görünmüyor
double d = Double.parseDouble(s);      // 80.0
int i = Integer.parseInt(s);           // 80
```

`parseDouble`, `Double` sınıfının; `parseInt`, `Integer` sınıfının metodudur. Ekrandaki çıktılar `80.0` ve `80`'dir (ekrandan, 00:10:00). Metnin düzgün bir sayı olması gerekir. Ondalıklı bir metin tamsayıya `parseInt` ile çevrilemez, ama `double`'a çevrilebilir.

> **Ders sonrası not:** Ondalıklı bir metin `Integer.parseInt` metoduna verilirse `NumberFormatException` fırlatılır; `Integer.parseInt("80.5")` ile denendi.

## 3. Nesnelerde tip dönüşümü: upcasting ve downcasting

### 3.1 Temel kural

Nesneler arasındaki dönüşümde nesnenin tipi değil, onu gösteren **referansın** tipi değişir. Atama yapılan değişken, diğer nesnenin referansını alır. Bu dönüşüm yalnız aralarında **kalıtım** ilişkisi olan sınıflar arasında yapılabilir; birbirinden bağımsız iki sınıf birbirine dönüştürülemez.

### 3.2 Bir dosyada birden çok sınıf

`ObjectCasting.java` dosyasında `ObjectCasting` sınıfının yanında `Animal` ve `Cow` sınıfları da yazılmıştır. Şimdiye kadar her dosyada bir sınıf vardı; bu sınıf diğer sınıflardan erişilebilsin diye `public` yapılır ve adı dosyanın adıyla aynıdır. Aynı dosyaya başka sınıflar da yazılabilir, ama bir dosyada yalnız **bir** `public` sınıf olabilir. Diğer sınıfların önüne erişim belirteci yazılmaz; buna **default** (paket) erişim denir. Default erişimli sınıflara aynı paketteki diğer sınıflardan erişilebilir. Örneğin `typecasting` paketindeki `PrimitiveCasting` sınıfı da `Animal` ve `Cow` sınıflarını kullanabilir.

### 3.3 Örnek sınıflar

Ekrandaki sınıflar (ekrandan, 00:15:00; `Animal`'ın `toString` metni çıktıdan alındı):

```java
class Animal {
    @Override
    public String toString() {
        return "This is an Animal";
    }
    public String myMethod() {
        return "running Animal's method.";
    }
}

class Cow extends Animal {
    @Override
    public String toString() {
        return "This is a Cow";
    }
    public String myMethod() {
        return "running Cow's method.";
    }
}
```

`toString()` metodu nesne `System.out.println` ile yazdırıldığında hangi metnin çıkacağını belirler. `Cow` daha özelleşmiş sınıf olduğu için kendi `myMethod()` sürümünü kullanır.

### 3.4 Önce olağan kullanım

`main` metodunun ilk kısmı (ekrandan, 00:20:00):

```java
Cow daisy = new Cow();
System.out.println( daisy);
System.out.println(daisy.myMethod());

Animal anim = new Animal();
System.out.println(anim);
System.out.println(anim.myMethod());
```

Çıktı ilk dört satırda "This is a Cow", "running Cow's method.", "This is an Animal", "running Animal's method." olur.

### 3.5 Upcasting: çocuktan ebeveyne

```java
//Upcasting : child to parent
anim = (Animal) daisy;  //parantezde Animal yazmam şart değil.
System.out.println(anim); // prints: This is a Cow
System.out.println(anim.myMethod()); //running Cow's method.
```

(ekrandan, 00:20:00)

Alt sınıftan üretilmiş `daisy`, üst sınıf tipindeki `anim` referansına atanır. Atamadan sonra "This is an Animal" yazan referans artık "This is a Cow" yazar, `myMethod()` çağrısı da `Cow`'daki metodu çalıştırır. Parantez içindeki `(Animal)` gösterimi yazılmasa da kod aynı biçimde çalışır.

> **Ders sonrası not:** Derste upcasting için "üst sınıf artık alt sınıfın metotlarını da çağırabilir, genişlemiş olur" dendi. Doğrusu: upcast edilmiş `Animal` referansıyla yalnız `Animal`'da tanımlı üyeler çağrılabilir; `Cow`'a özgü yeni bir metot bu referansla çağrılamaz. "running Cow's method." çıkmasının nedeni **dinamik bağlama**dır: override edilmiş metodun hangi sürümünün çalışacağı referansın tipine göre değil, gerçek nesnenin sınıfına göre belirlenir.

### 3.6 Downcasting: ebeveynden çocuğa

Downcasting'de üst sınıf tipindeki bir referans alt sınıf tipindeki bir referansa atanır ve burada parantez içindeki hedef sınıf **zorunludur**. Örnekte `Animal` tipinde bir referans `new Cow()` ile oluşturulur, sonra `(Cow)` ile bir `Cow` referansına atanır. Böylece iki referans da aynı `Cow` nesnesini gösterir. Ekranda bu bölümün iki satırı "This is a Cow" olarak görülür (ekrandan, 00:20:00). Kodun bu bölümü karelerde görünmez; anlatıma göre şöyledir:

```java
//Downcasting : parent to child
Animal an1 = new Cow();     // değişken adları anlatımdan
Cow c = (Cow) an1;
System.out.println(an1);    // This is a Cow
System.out.println(c);      // This is a Cow
```

<!-- BELİRSİZ: downcasting bölümünün tam kodu karelerde görünmüyor; değişken adları altyazıdan ("n1", "c") kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Downcasting yalnız gerçek nesne gerçekten hedef sınıftansa (ya da onun alt sınıfındansa) başarılıdır. `Cow bad = (Cow) new Animal();` derlenir ama çalışma anında `ClassCastException` verir. Bu yüzden downcast öncesinde çoğunlukla `instanceof` ile denetim yapılır.

## 4. Dosya işlemleri: oluşturma, yazma, okuma, silme

Dosya işlemleri için `java.io` paketindeki `File` sınıfı ve ileride görülecek başka sınıflar kullanılır. Dosya oluşturma, yazma ve okuma metotları denetlenen (checked) istisna kategorisindeki `IOException` türünden istisnalar fırlatabilir. Java bu durumda iki yoldan birini ister: çağrıyı `try-catch` bloğuna almak ya da metodun imzasına `throws IOException` eklemek. Dosya işlemlerinde `try-catch` sık kullanılır.

### 4.1 Dosya oluşturma

`CreateFile` sınıfı (ekrandan, 00:25:00):

```java
import java.io.File;
import java.io.IOException;  // import satırları katlanmış görünüyor

public class CreateFile {
    public static void main(String[] args) {
        try {
            File myObj = new File("dosyam.txt");
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
```

`File` nesnesi olağan biçimde oluşturulur ve yapıcı metoda dosya adı tırnak içinde verilir. Yol belirtilmezse dosya projenin bulunduğu klasöre (Eclipse çalışma alanındaki proje klasörüne) yazılır. `createNewFile()` o konumda bu adla bir dosya yoksa dosyayı oluşturur ve `true` döner; o zaman "File created: dosyam.txt" yazılır (çıktı ekrandan, 00:30:00). Dosya zaten varsa `false` döner ve `else` kolunda "File already exists." yazılır. Uzantının `.txt` olması şart değildir.

Dosya başka bir yere de yazılabilir. Yapıcıya tam yol verilirse (örneğin masaüstü klasörünün yolu ile birlikte) dosya oraya oluşturulur; ekrandaki yorumda Windows'ta yolun başına `C:` eklenmesi gerektiği not edilmiştir. Pratik bir yol da yapıcının iki parametreli sürümüdür: birinci parametre klasör yolunu tutan bir String, ikincisi dosya adıdır. Çok sayıda dosyayla çalışırken yol bir değişkende tutulup her seferinde tekrar kullanılabilir.

```java
// yol değişkeni ekranda yorum satırı olarak duruyor; gerçek yol buraya yazılır
String myDesktopPath = "...";
File myObj = new File(myDesktopPath, "dosyam.txt");
```

### 4.2 Dosyaya yazma

`WriteToFile` sınıfı (ekrandan, 00:30:00):

```java
package files;

import java.io.FileWriter;

public class WriteToFile {
    public static void main(String[] args) {

        try {
            FileWriter myWriter = new FileWriter("dosyam.txt");
            myWriter.write("Files in Java might be tricky, but it is fun enough!");
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
```

`FileWriter` nesnesi hangi dosyaya yazılacağı verilerek oluşturulur, `write` metodu verilen metni dosyaya yazar. İş bitince `close()` ile yazma işlemi kapatılır. Çalıştırınca "Successfully wrote to the file." mesajı çıkar ve dosya açıldığında yazılan cümle görülür.

### 4.3 Dosyadan okuma

Okuma için `Scanner` sınıfı kullanılır ve dosya satır satır okunur. Önce hangi dosyanın okunacağı bir `File` nesnesiyle belirtilir, sonra `Scanner` nesnesi bu `File` nesnesi üzerinden kurulur. `while` döngüsü bir sonraki satır var oldukça satırı okur, bir String değişkene atar ve konsola yazar. En sonda `Scanner` kapatılır. Dosya bulunamazsa istisna fırlatılacağı için `try-catch` gereklidir. Kod karelerde görünmez; anlatıma göre şöyledir:

```java
File myObj = new File("dosyam.txt");
Scanner myReader = new Scanner(myObj);
while (myReader.hasNextLine()) {
    String data = myReader.nextLine();
    System.out.println(data);
}
myReader.close();
// catch (FileNotFoundException e) { ... }
```

<!-- BELİRSİZ: ReadFile sınıfının kodu karelerde görünmüyor; yapı altyazıdaki anlatımdan kuruldu. -->

Çalıştırınca dosyaya yazılmış cümle konsola gelir. Yazarken `write`, okurken `Scanner` kullanılmış olur.

### 4.4 Dosya silme

Silinecek dosya yine bir `File` nesnesiyle belirtilir ve `delete()` çağrılır. `delete()` `true` ya da `false` döndürür: dosya varsa silinir ve `true` döner. Başarı durumunda konsola bilgi yazılır; ekrandaki çıktı "Deleted the file: dosyam.txt" olur (ekrandan, 00:35:00). Ardından proje klasörüne bakıldığında dosyanın kalmadığı görülür.

```java
File myObj = new File("dosyam.txt");
if (myObj.delete()) {
    System.out.println("Deleted the file: " + myObj.getName());
}
```

<!-- BELİRSİZ: DeleteFile kodunun yalnız çıktısı karede görünüyor; else kolu anlatılmadı. -->

## 5. Nesne serileştirme ve geri okuma

### 5.1 Fikir

Şimdiye kadar dosyaya String ya da tamsayı yazıldı. Nesneleri dosyaya yazmak için nesne bir bayt dizisine dönüştürülür ve dosyaya yazılır; buna **serileştirme** (serialization) denir. Dosyadaki bayt dizisinden nesneyi yeniden kurup okunabilir hâle getirmeye de **geri serileştirme** (deserialization) denir.

### 5.2 Serializable arayüzü ve Employee sınıfı

Dosyaya yazılacak nesnelerin sınıfı `java.io.Serializable` arayüzünü gerçeklemelidir. Örnekte çalışan (employee) nesneleri yazılır (ekrandan, 00:35:00):

```java
package files;

public class Employee implements java.io.Serializable {

    public String name;
    public String address;
    public transient int SSN;
    public int number;

    @Override
    public String toString() {
        return "Employee [name=" + name + ", address=" + address + ", SSN=" + SSN + ", number=" + number + "]";
    }
}
```

`name` çalışanın adı, `address` adresi, `SSN` çalışan kimlik numarası gibi bir numara, `number` ise telefon numarası gibi başka bir numaradır. Sınıfta tanımlı bir yapıcı metot yoktur.

`Serializable` gerçeklendiğinde Eclipse genellikle bir sürüm kimliği (`serialVersionUID`) alanı ister; yazılmazsa uyarı (warning) çıkar. Bu bir hata değildir ve programın çalışmasını etkilemez. Uyarı, önerilen kimlik satırı eklenerek ya da Eclipse'in diğer önerisiyle `@SuppressWarnings` yazılarak (serileştirme uyarılarını bastırmak) kapatılabilir.

> **Ek bilgi (derste anlatılmadı):** `serialVersionUID`, sınıfın sürümünü belirten `private static final long` bir alandır. Nesne yazıldıktan sonra sınıf değiştirilirse geri okumada sürüm uyuşmazlığı denetiminde kullanılır; yazılmazsa JVM sınıf yapısından otomatik bir değer hesaplar.

### 5.3 Nesneleri dosyaya yazma: SerializeDemo

`SerializeDemo` sınıfında önce iki `Employee` nesnesi oluşturulur. Yapıcı metot olmadığı için nesne boş oluşturulur ve alanlara tek tek değer atanır. Derste belirtildiği gibi alanları yapıcı metotla başlangıçta doldurmak daha pratiktir, ama bu biçim de mümkündür. Birden çok nesnenin nasıl yazılacağını göstermek için iki nesne kullanılır. Nesneler tek tek yazılırsa okumaları zorlaşır; bu yüzden hepsi bir `LinkedList<Employee>` içine konur ve liste tek bir nesne olarak yazılır. Okurken liste kolayca sırayla gezilir.

Ekrandaki kodun ikinci yarısı (ekrandan, 00:40:00; çalışan adları ve adresleri bu notta genel değerlerle değiştirildi, birinci çalışanın `SSN` değeri karede görünmüyor):

```java
Employee e = new Employee();
e.name = "Çalışan Bir";
e.address = "Şehir A";
e.SSN = ...;            // karede görünmüyor
e.number = 101;

Employee e2 = new Employee();
e2.name = "Çalışan İki";
e2.address = "Şehir B";
e2.SSN = 222333444;
e2.number = 202;

LinkedList<Employee> listem = new LinkedList<>();
listem.add(e);
listem.add(e2);

try {
    FileOutputStream fileOut = new FileOutputStream("myfile.ser");
    ObjectOutputStream out = new ObjectOutputStream(fileOut);
    out.writeObject(listem);
    out.close();
    fileOut.close();
    System.out.printf("Serialized data is saved.");
} catch (IOException i) {
    ...
}
```

Yazma iki aşamalıdır ve iki akış birbirine zincirlenir. Önce dosya adı verilerek bir `FileOutputStream` nesnesi oluşturulur. Sonra nesne yazılacağı için bir `ObjectOutputStream` oluşturulur ve yapıcısına parametre olarak `fileOut` verilir. `writeObject(listem)` çağrısıyla listenin tamamı tek bir nesne gibi yazılır; istenseydi yalnız `e` ya da `e2` de verilebilirdi. Kapatma sırası: önce `out`, sonra `fileOut`. Sorun çıkarsa `IOException` fırlatılır.

Dosya uzantısı olarak `.ser` (serialize'dan) ya da `.dat` (data'dan) kullanılabilir; uzantının bir önemi yoktur, istenen herhangi bir ad konabilir. Yine de içerik bayt dizisi olduğundan dosyayı bilgisayarda açıp okumak anlamsızdır (bilgisayar için anlamlı, insan için anlamsız bilgiler); bu yüzden `.ser` gibi bir uzantı iyi bir gösterim olur. Yol verilmediği için dosya proje klasörüne yazılır. Çalıştırınca "Serialized data is saved." mesajı çıkar (ekrandan, 00:45:00).

### 5.4 Nesneleri geri okuma: DeserializeDemo

Okuma yazmanın tersidir. Derste uyarıldığı gibi bu ikisi sık karıştırılır: **output** ile yazılır, **input** ile okunur (input'u "içeri almak, okumak" diye düşünmek yardımcı olur). Yazarken kurulan `FileOutputStream` + `ObjectOutputStream` zincirinin yerine bu kez `FileInputStream` + `ObjectInputStream` kurulur (ekrandan, 00:45:00):

```java
package files;

import java.io.*;
public class DeserializeDemo {

    public static void main(String [] args) {

        LinkedList<Employee> okunacak_liste;
        try {
            FileInputStream fileIn = new FileInputStream("myfile.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);

            //Employee e = (Employee) in.readObject();  //tek bir kayıt göndermiş olsam bu şekilde
            okunacak_liste = (LinkedList<Employee>) in.readObject();

            in.close();
            fileIn.close();
        } catch (IOException i) {
            i.printStackTrace();
            return;
        } catch (ClassNotFoundException c) {
            System.out.println("Employee class not found");
            c.printStackTrace();
            return;
        }

        for(Employee iter: okunacak_liste)
            System.out.println(iter);
    }
}
```

(ekrandan, 00:45:00 ve 00:50:00)

Liste değişkeni `try` bloğunun dışında tanımlanır, çünkü listeye `try`'ın dışında, en alttaki döngüde de erişilecektir. Tanım bloğun içinde yapılsaydı dışarıda tanımsız olur ve derleyici hata verirdi.

`readObject()` çağrısının önündeki parantezli ifade yine bir tip dönüşümüdür. Java'da bütün sınıfların en tepesinde `Object` sınıfı vardır ve bütün sınıflar kalıtımla ondan gelir; `readObject()` de bir `Object` döndürür. Bu yüzden dönen değerin `LinkedList<Employee>` olarak alınması için dönüşüm yazılır. Tek bir `Employee` yazılmış olsaydı yorum satırındaki gibi `(Employee)` dönüşümü kullanılırdı. Bu satırda Eclipse yine bir uyarı gösterir; bastırılabilir, sorun değildir.

Okuma bitince akışlar kapatılarak kaynaklar serbest bırakılır. `catch` bloklarını derleyici zaten zorunlu kılar; metotların üzerine gelince hangi istisnayı fırlattıkları görülebilir. Son olarak liste for-each döngüsüyle eleman eleman gezilir. Döngü değişkeni (`iter`), listeyi sırayla gezen bir imleç gibi düşünülebilir. `toString()` yazıldığı için her eleman anlamlı biçimde yazılır.

### 5.5 Neden SSN değerleri 0?

Çıktı şöyledir (ekrandan, 00:50:00; adlar ve adresler bu notta genel değerlerle değiştirildi):

```text
Employee [name=Çalışan Bir, address=Şehir A, SSN=0, number=101]
Employee [name=Çalışan İki, address=Şehir B, SSN=0, number=202]
```

Nesneler oluşturulurken `SSN` alanlarına değer verilmişti, ama okunan listede ikisi de `0` gelir. Nedeni `Employee` sınıfındaki `transient` anahtar kelimesidir. `transient`, serileştirme sırasında bu alanın görmezden gelinmesini, dosyaya yazılmamasını söyler. Alan sınıfta vardır, ama dosyada değeri olmadığından geri okumada varsayılan değerini alır. `int`'in varsayılan değeri `0`'dır.

Eclipse'te `toString()` metodu silinip Source menüsünden yeniden üretildiğinde, alan seçme listesinde `SSN`'nin yanında bir "T" işareti görülür. Eclipse bu alanın büyük olasılıkla `toString` içinde gerekmediğini, çünkü anlamlı bir değeri olmayacağını belirtir; alan elle seçilirse yine eklenir.

### 5.6 Akışları tek satırda kurmak

**Soru:** `FileInputStream` için ayrı bir değişken tanımlamayıp doğrudan `new ObjectInputStream(new FileInputStream("myfile.ser"))` yazılırsa iç akış nasıl kapatılacak? **Cevap:** Denendi; dış akış kapatılınca onunla ilişkili iç akış da kapanır. İç akış için ayrı bir nesne adı olmadığından onu ayrıca kapatmak gerekmez. Ayrı satırlarda yazmak okunurluğu artırdığı için örnekte eski hâline dönülür.

**Soru:** Şifreleme yapmak ya da bir fotoğrafın baytları üzerinde işlem yapmak için bayt bayt okurken de aynı yöntem mi kullanılır? **Cevap:** Evet, baytlarla çalışırken stream'ler devreye girer; input stream ve output stream sınıflarıyla ilerlenir.

> **Ek bilgi (derste anlatılmadı):** Java 7'den beri akışlar `try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("myfile.ser"))) { ... }` biçiminde try-with-resources ile açılabilir; blok bitince `close()` kendiliğinden çağrılır. Ham baytlarla çalışmak için `FileInputStream.read()` ve `FileOutputStream.write(byte[])` doğrudan kullanılır.

## 6. İç sınıflar (inner class)

Java'da bir sınıfın içine başka bir sınıf yazılabilir. Dış sınıfa (outer class) olağan biçimde erişilir; iç sınıfa (inner class) ise dış sınıf üzerinden ulaşılır.

### 6.1 Statik olmayan iç sınıf

İç sınıfın nesnesi olağan `new IcSinif()` biçimiyle üretilemez. Önce dış sınıftan bir nesne oluşturulur, sonra bu nesne üzerinden iç sınıfa gidilir. Tip adı iki parçalı yazılır: `DisSinif.IcSinif`. İç sınıfta ve dış sınıfta birer `x` değişkeni vardır; iç sınıfın `x`'i `5`, dış sınıfınki `10` olarak yazılır (`Test1` çıktısı ekrandan, 01:00:00). Kod karelerde görünmez; anlatıma göre yapı şöyledir:

```java
class OuterClass {
    int x = 10;
    class InnerClass {
        int x = 5;      // ayrıntılar karede görünmüyor
    }
}
// main içinde:
OuterClass myOuter = new OuterClass();
OuterClass.InnerClass myInner = myOuter.new InnerClass();
System.out.println(myInner.x);   // 5
System.out.println(myOuter.x);   // 10
```

<!-- BELİRSİZ: Test1 kodu karelerde görünmüyor; yapı anlatımdan ve 5, 10 çıktısından kuruldu. -->

### 6.2 Statik iç sınıf

Statik metotlar sınıf adıyla, nesne üretmeden çağrılabiliyordu. İç sınıfın `static` olması da benzer bir kolaylık sağlar: dış sınıfın nesnesine gerek kalmaz (ekrandan, 01:00:00):

```java
package inner_class;

// static inner class örneği - üst sınıf nesnesine gerek yok.
class OuterClass2 {
    int x = 10;

    static class InnerClass2 {
        int x = 5;
    }
}

public class Test2 {
    public static void main(String[] args) {
        OuterClass2.InnerClass2 myInner = new OuterClass2.InnerClass2();
        System.out.println(myInner.x);
    }
}
```

Sınıf adlarının sonuna `2` eklenmiştir, çünkü `Test1` ile aynı paketteki sınıflar birbirine erişebilir; aynı ad verilseydi aynı pakette iki aynı adlı sınıf olacağı için hata alınırdı. Kalıtımda "üst" ve "alt" sınıf denir; burada ise "dış" ve "iç" sınıf denir. Çıktı `5`'tir.

### 6.3 İç sınıftan dış sınıfa erişim

Son örnekte (`Test3`) iç sınıf yine statik değildir; önce dış sınıfın nesnesi, sonra `myOuter.new InnerClass()` ile iç sınıfın nesnesi oluşturulur. İç sınıftaki metot `return x;` der. İç sınıfta `x` adlı bir alan yoktur, ama bağlı olduğu dış sınıfta vardır; metot bu değeri dış sınıftan alır. Çıktı `10`'dur (`Test3` çıktısı ekrandan, 01:05:00).

```java
class OuterClass {
    int x = 10;
    class InnerClass {
        public int myInnerMethod() {
            return x;           // dış sınıfın x'i
        }
    }
}
// main içinde:
OuterClass myOuter = new OuterClass();
OuterClass.InnerClass myInner = myOuter.new InnerClass();
System.out.println(myInner.myInnerMethod());   // 10
```

<!-- BELİRSİZ: Test3 kodu karelerde görünmüyor; metot adı altyazıdan ("myinner method"), yapı anlatımdan kuruldu. -->

## 7. Thread'lere giriş

### 7.1 Neden thread?

Bir nesnenin metodu çağrıldığında işlemler satır satır ilerler: bir metot çalışır, bitince diğerine geçilir ve her işin bitmesi beklenir. Bilgisayarın gücü yeterliyse nesnelerin işlerini aynı anda başlatmaları istenebilir. Örneğin bir işlem 5 saniye, diğeri 10 saniye sürüyorsa sırayla çalışınca toplam 15 saniye beklenir; ikisi aynı anda başlarsa bütün işler en uzun süren iş kadar, yani yaklaşık 10 saniyede bitebilir. Thread'ler aynı anda (eş zamanlı) çalışabilen küçük iş parçalarıdır; nesneler thread hâline getirilerek bu imkân sağlanır.

Bir sınıfın nesnelerini thread yapmanın iki yolu vardır.

### 7.2 Birinci yol: Thread sınıfını genişletmek

Örnek dosyanın adı `ThreadOlusturma2`'dir, çünkü daha az tercih edilen yol olduğu için "ikinci" diye adlandırılmıştır; yine de anlatıma bununla başlanır. Hazır `Thread` sınıfı `extends` edilir ve bu sınıfın `run()` metodu override edilir. Önemli olan `run()` metodudur: nesne çalıştırıldığında bu metodun gövdesi çalışır. Bunun dışında sınıf olağan bir sınıftır; alanlar, yapıcı ve başka metotlar yazılabilir (ekrandan, 01:05:00 ve 01:10:00):

```java
package multithreading;

public class ThreadOlusturma2 {

    public static void main(String[] args)  {

        Increaser2 i1 = new Increaser2("nesne1");
        Increaser2 i2 = new Increaser2("nesne2");

        i1.start();
        i2.start();
    }
}

class Increaser2 extends Thread {
    public static int sayi=5;
    private String name;

    public Increaser2(String name){
        this.name = name;
    }

    public void add(){
        sayi++;
        System.out.println(name+" çalıştı, sayı değeri artık= "+sayi);
    }

    @Override
    public void run() {
        add();
    }
}
```

(Yapıcının ve `run()`'ın bazı karakterleri karede bir menünün arkasında kalmıştır; bu kısımlar görünen parçalardan ve anlatımdan tamamlandı.)

`run()` içinde `add()` çağrılır. `add()` statik `sayi` değişkenini bir artırır ve sonucu yazar. Statik değişkenler derste kullanılan benzetmeyle sınıfa "kazık çakılmış" bir değerdir: her nesnenin ayrı değeri olan olağan alanların aksine bütün nesneler aynı değeri paylaşır. Bir nesne değeri 5'ten 6'ya çıkarırsa diğer nesne 6'dan devam edip 7 yapar.

Nesneler yapıcının istediği adla oluşturulur (`"nesne1"`, `"nesne2"`). Sınıfta `start()` diye bir metot yazılmamıştır, ama sınıf `Thread`'den türediği için `start()` çağrılabilir ve bu çağrı `run()` metodunu çalıştırır. İki `start()` arasında bekleme yoktur; birinci thread başlar, hemen arkasından ikincisi başlar ve ikisi birlikte çalışır.

### 7.3 Çıktının yorumu

Bir çalıştırmada iki satırda da sayı değerinin 7 olduğu görülür (ekrandan, 01:15:00):

```text
nesne1 çalıştı, sayı değeri artık= 7
nesne2 çalıştı, sayı değeri artık= 7
```

Anlatılan çalıştırmada önce `nesne2` satırı yazılmıştır. Açıklama şöyledir: değer 5'ten başlar. Bir thread artırma satırını çalıştırıp değeri 6 yapar, hemen ardından diğer thread aynı satırı çalıştırıp 7 yapar. Sonra iki thread yazdırma satırına geçer; hangisi önce davranırsa onun satırı önce çıkar. İkisi de `sayi`'nin o anki değerini, yani 7'yi yazar. Program birkaç kez çalıştırıldığında farklı sonuçlar görülür: bir çalıştırmada önce `nesne1` çalışıp değerler 6'da kalmış gibi görünebilir. Thread'ler en son gördükleri değeri yazar.

> **Ek bilgi (derste anlatılmadı):** Bu durum bir **yarış durumu**dur (race condition): `sayi++` tek bir adım değildir (oku, artır, yaz), bu yüzden eş zamanlı artırmalarda sonuç çalıştırmadan çalıştırmaya değişir. Paylaşılan değişkene erişim `synchronized` blok ya da `AtomicInteger` gibi araçlarla güvenli hâle getirilir.

### 7.4 start() ile run() farkı

Nesne oluşturulup `start()` çağrıldığında override edilmiş `run()` metodunun içeriği ayrı bir akışta çalışır. `i1.run()` diye doğrudan çağrı yapılırsa bu sıradan bir metot çağrısı olur ve thread davranışı elde edilmez. `start()`'ın anlamı "bu iş başlasın, bitmesini beklemeden alt satıra geç" demektir.

### 7.5 İkinci yol: Runnable arayüzünü gerçeklemek

Daha sık tercih edilen yol `Runnable` arayüzünü `implements` etmektir. Sınıfın geri kalanı, metotları ve override edilen `run()` metodu tamamen aynıdır (ekrandan, 01:15:00):

```java
public static void main(String[] args)  {

    Increaser i1 = new Increaser("nesne1");
    Increaser i2 = new Increaser("nesne2");

    Thread t1 = new Thread(i1);
    Thread t2 = new Thread(i2);

    t1.start();
    t2.start();
}

class Increaser implements Runnable {
    public static int sayi=5;
    private String name;
    ...   // yapıcı, add() ve run() birinci yoldakiyle aynı
}
```

Bu kez nesneler oluşturulduktan sonra birer `Thread` nesnesinin içine verilir ve `start()` bu `Thread` nesneleri üzerinden çağrılır. Çıktılar yine hangi thread'in hangi satırı önce okuduğuna göre değişir.

Bu yolun avantajı şudur: `Thread` somut bir sınıftır ve `extends` ile alınır. Java'da bir sınıfın yalnız bir `extends` hakkı vardır; bu hak `Thread` için kullanılırsa sınıf başka bir sınıftan kalıtım alamaz. Bir arayüz `implements` edildiğinde ise tek `extends` hakkı yerinde durur, başka arayüzler de virgülle eklenebilir. Bu yüzden `Runnable` gerçeklemek daha mantıklıdır.

Thread havuzu oluşturma (thread'leri üçerli, beşerli gruplar hâlinde çalıştırma) ve thread önceliklerinin belirlenmesi bu oturuma alınmadı; konunun teori derslerinde işleneceği söylendi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:50:39; çıktı ekrandan, 00:50:00): Serileştirilip geri okunan `Employee` listesinde nesneler oluşturulurken `SSN` alanlarına değer verildiği hâlde çıktıda `SSN=0` görülüyor. Bunun nedeni nedir?

> **Çözüm (derste verildi):** `SSN` alanı `transient` tanımlanmıştır. `transient` alanlar serileştirmede dosyaya yazılmaz; geri okumada alan varsayılan değerini alır. `int` için bu değer `0`'dır.

**Soru 2** (derste sözlü, 00:52:00): Bir `boolean` değişken tanımlanıp ona değer atanmazsa başlangıç değeri `true` mu olur, `false` mu?

> **Çözüm (derste verildi):** `false` olur. Atanmamış bir `int` alanı `0`, bir nesne referansı ise `null` değerini alır.

> **Ders sonrası not:** Bu varsayılan değerler sınıfın alanları (ve dizi elemanları) için geçerlidir. Bir metodun içindeki yerel değişkenin varsayılan değeri yoktur; değer atanmadan okunursa derleme hatası alınır.

**Soru 3** (ekrandan, 00:20:00): Aşağıdaki kod parçası çalıştırıldığında son iki satır ne yazar?

```java
Cow daisy = new Cow();
Animal anim = new Animal();
anim = (Animal) daisy;
System.out.println(anim);
System.out.println(anim.myMethod());
```

> **Çözüm (derste verildi):** "This is a Cow" ve "running Cow's method." yazar. `anim` artık bir `Cow` nesnesini gösterir; override edilmiş `toString()` ve `myMethod()` gerçek nesnenin sınıfından çalışır.

**Soru 4** (ekrandan, 01:15:00): İki thread de ortak statik `sayi = 5` değişkenini birer kez artırıp yazdırıyor. Ekranda iki satırda da "sayı değeri artık= 7" görülmesi nasıl açıklanır, her çalıştırmada aynı çıktı alınır mı?

> **Çözüm (derste verildi):** İki thread de artırma satırını yazdırma satırından önce çalıştırmıştır (5 → 6 → 7); sonra ikisi de `sayi`'nin o anki değeri olan 7'yi yazar. Thread'lerin sırası her çalıştırmada değişebileceği için çıktı her seferinde aynı olmaz; örneğin bir satırda 6 görülebilir.

## Dersin Toparlaması

Bu uygulama oturumunda önce ilkel tiplerde otomatik genişletme ile elle yapılan, kayıplı daraltma karşılaştırıldı ve metinden sayı elde etmek için parse metotları kullanıldı. Nesnelerde dönüşümün yalnız kalıtım hiyerarşisi içinde yapılabildiği, nesnenin değil referansın tipinin değiştiği `Animal` ve `Cow` örneğiyle gösterildi. Ardından `File`, `FileWriter` ve `Scanner` ile dosya oluşturma, yazma, okuma ve silme yapıldı. Nesneler `Serializable` arayüzü ve `ObjectOutputStream` ile bir liste hâlinde dosyaya yazıldı, `ObjectInputStream` ile geri okundu ve `transient` alanların dosyaya yazılmadığı görüldü.

Son bölümde teori derslerinde henüz işlenmemiş iki konuya giriş yapıldı. İç sınıflarda statik olmayan iç sınıfın nesnesinin dış sınıf nesnesine bağlı olduğu, statik iç sınıfın ise dış nesne olmadan üretilebildiği gösterildi. Thread'ler `Thread` sınıfını genişleterek ve `Runnable` arayüzünü gerçekleyerek oluşturuldu, `start()` ile `run()` farkı ve paylaşılan statik değişkende çıktının neden çalıştırmadan çalıştırmaya değiştiği tartışıldı. Thread havuzları ve öncelikler gibi konuların teori derslerinde işleneceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
