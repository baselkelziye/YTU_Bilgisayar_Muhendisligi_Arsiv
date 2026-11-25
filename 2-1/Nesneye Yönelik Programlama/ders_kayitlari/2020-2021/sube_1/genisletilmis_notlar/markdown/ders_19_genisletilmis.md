# Ders 19 Genişletilmiş Notu: İç Sınıflar, Tip Dönüştürme, Dosya İşlemleri ve İş Parçacıkları (Uygulama)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Kapsamı
- 2. İç Sınıflar (Inner Class)
- 3. İlkel Veri Tiplerinde Tip Dönüştürme
- 4. Nesnelerde Tip Dönüştürme
- 5. Metin Dosyasına Yazma ve Okuma
- 6. Nesneyi Dosyaya Yazma ve Okuma (Serileştirme)
- 7. İş Parçacıkları (Thread)
- 8. İş Parçacığı Havuzu
- Örnek Sorular

## 1. Oturumun Kapsamı

Bu oturum bir uygulama dersidir. O hafta dört konu ele alındı: dosyaya yazma ve dosyadan okuma (file stream), iç sınıflar, çok iş parçacıklı (multi-thread) yapılar ve tip dönüştürme (type casting). Örnekler Eclipse'teki `uyg-4` projesindeydi; proje `filestream`, `innerclass`, `multithread` ve `typecasting` paketlerinden oluşuyordu (ekrandan, 00:10:00 ve 00:25:00). İç sınıf örnekleri bir Java öğretici sitesinden alındı; diğer konular hazır kodlar çalıştırılıp çıktıları yorumlanarak anlatıldı.

Teori dersinde bu konulara henüz gelinmediği için özellikle iş parçacıklarının yüzeysel anlatılacağı, ileri ayrıntılarına girilmeyeceği söylendi. İç sınıf ve tip dönüştürmenin zaten kuramsal bir tarafının az olduğu, büyük kısmının kod olduğu belirtildi.

## 2. İç Sınıflar (Inner Class)

### 2.1 Tanım ve iki ayrı sınıfla karşılaştırma

Bir sınıfın içinde başka bir sınıf yazıldığında içerideki sınıfa iç sınıf denir. Derste önce iç sınıfın neyi kolaylaştırdığını göstermek için iki ayrı sınıf yazılmış bir örnek açıldı. Adı `InnerClass` olsa da bu sınıf `OuterClass`'ın içinde değil, onun yanında ayrı bir sınıf olarak tanımlanmıştı; `OuterClass` ise yapıcısında ondan bir nesne oluşturup alan olarak tutuyordu (ekrandan, 00:10:00):

```java
package innerclass;

public class Main{

    public class InnerClass{
        int y;
        public InnerClass() {
            y = 5;
        }
    }

    public class OuterClass {
        int x;
        InnerClass y;
        public OuterClass() {
            y = new InnerClass();
            x = 10;
        }

    }

    public static void main(String[]args) {

    }
}
```

Bu yapı ile iç sınıf yazımı çalışma bakımından aynı işi görür. Fark, iç sınıfla aynı ilişkinin birkaç satırda kurulmasıdır: iki ayrı sınıf ve alan tanımı yerine sınıf doğrudan diğerinin içine yazılır. Bu okunurluğu artırır ve kodu kısaltır.

### 2.2 İç sınıftan nesne oluşturma

Sitedeki örnekte (kod karede görünmüyor; aşağıdaki biçim anlatımdan ve sitedeki standart örnekten kuruldu) önce dış sınıftan bir nesne oluşturulur, sonra iç sınıfın nesnesi bu nesne üzerinden `new` ile oluşturulur ve `OuterClass.InnerClass` türündeki bir değişkende tutulur:

```java
class OuterClass {
  int x = 10;

  class InnerClass {
    int y = 5;
  }
}

public class Main {
  public static void main(String[] args) {
    OuterClass myOuter = new OuterClass();
    OuterClass.InnerClass myInner = myOuter.new InnerClass();
    System.out.println(myInner.y + myOuter.x);
  }
}
```

<!-- BELİRSİZ: İç sınıf örneğinin kodu karelerde görünmüyor; değerler (x = 10, y = 5, toplam 15) anlatımdan alındı, kod biçimi anlatıma göre kuruldu. -->

`myInner.y + myOuter.x` toplamı `5 + 10 = 15` olarak yazdırılır. Bu örnek `java` ile çalıştırılarak denendi ve `15` çıktısı alındı.

İç içe yazılmış olmanın, iç sınıf nesnesi üzerinden dış sınıfın alanına erişim sağladığı düşünülmemelidir: `myInner.x` yazılamaz; nasıl ki iki ayrı sınıfın nesneleriyle de böyle bir erişim yapılamıyorsa.

> **Ders sonrası not:** Derste iç sınıfın içinden dış sınıfın `x` değişkenine erişilemeyeceği de söylendi (00:12:39). Bu `static` olmayan iç sınıf için doğru değildir: iç sınıfın kodu dış sınıfın alanlarına (private olanlar dahil) doğrudan erişir. Aşağıda 2.4'te gösterilen `myInnerMethod()` örneği de dış sınıfın `x`'ini döndürür. Erişilemeyen şey, iç sınıf nesnesi üzerinden `myInner.x` biçimindeki erişimdir.

### 2.3 Erişim belirteci ve static iç sınıf

İç sınıf `private` tanımlanırsa dışarıdaki bir sınıftan ona erişmeye çalışan satır hata verir, çünkü sınıf görünmez. `public`, `protected` ya da hiç erişim belirteci yazılmaması kabul edilir.

`static` iç sınıfta durum, dış sınıftaki `static` bir alana benzer. Dış sınıfta `static int x` olsaydı ona `OuterClass.x` diye erişilirdi; aynı biçimde `static` iç sınıfa da `OuterClass.InnerClass` diye erişilir. Bu kez dış sınıftan nesne oluşturmaya gerek yoktur. Yine de iç sınıfın kendisi bir nesne olduğu için bellekte yer ayrılması gerekir, bu yüzden `new` kullanılır:

```java
OuterClass.InnerClass myInner = new OuterClass.InnerClass();
System.out.println(myInner.y);
```

<!-- BELİRSİZ: static iç sınıf örneğinin kodu karede görünmüyor; satırlar anlatıma göre yazıldı. -->

`static` iç sınıfın kullanılmasının amacı, dış sınıftan nesne oluşturmadan iç sınıfa ulaşabilmektir.

### 2.4 İç sınıfın metodunu çağırma

İç sınıftaki bir metoda erişmek için önce dış sınıftan bir nesne (`myOuter`) oluşturulur, sonra `myOuter.new InnerClass()` ile iç sınıf nesnesi oluşturulup `myInner` ile tutulur. Bundan sonra iç sınıf nesnesi sıradan bir nesne gibi kullanılır: `myInner.myInnerMethod()` çağrılır. Bu metot dış sınıfın `x` değerini döndürür ve sonuç yazdırılır.

```java
class OuterClass {
  int x = 10;

  class InnerClass {
    public int myInnerMethod() {
      return x;
    }
  }
}
```

<!-- BELİRSİZ: Bu kod da karede görünmüyor; metodun x'i döndürdüğü anlatımdan alındı. -->

### 2.5 İç sınıf ne zaman kullanılır

Bir öğrencinin sorusu üzerine iç sınıfın kullanım ölçütü açıklandı (bkz. Örnek Sorular). Bir sınıfı yalnız tek bir sınıf kullanıyorsa, o sınıfla ilişkiliyse, onu dışarıda ayrı yazmak yerine içeride iç sınıf olarak tanımlamak daha şıktır. Ama başka bir sınıf (örneğin bir `X` sınıfı) da ondan nesne oluşturacaksa sınıf içeride tutulmaz, dışarıda yazılır. Yani iç sınıf daha çok bir yazım tekniğidir; çalışma bakımından iki ayrı sınıfla arasında fark yoktur.

## 3. İlkel Veri Tiplerinde Tip Dönüştürme

İki tür tip dönüştürme vardır: ilkel veri tiplerinin dönüştürülmesi ve ilkel olmayan veri tiplerinin (sınıfların, nesnelerin) dönüştürülmesi. Derste `int`, `double`, `char` ilkel tiplere örnek verildi; `String` de bu başlık altında ele alındı.

### 3.1 Otomatik dönüştürme

Ekrandaki `TypeCasting.java` dosyasının ilk kısmı şudur (ekrandan, 00:25:00):

```java
// ilkel veri tiplerini dönüştürme
    //otomatik casting
int x =1911;
double y = x;
System.out.println(x);
System.out.println(y);
String yildiz = "Yıldız Teknik Üniversitesi (YTÜ) "+x+" yılında kuruldu.";
System.out.println(yildiz);

char c = '3';
int c_i = c;
System.out.println(c_i); //ascii tablosundan dönüşüm yapıyor.
```

Konsol çıktısı (ekrandan, 00:25:00):

```text
1911
1911.0
Yıldız Teknik Üniversitesi (YTÜ) 1911 yılında kuruldu.
51
```

Bu satırların her birinde parantez içinde tür yazılmadan dönüşüm olur:

- `int` bir değer `double` bir değişkene atandığında otomatik olarak `1911.0` olur.
- `x` bir tam sayı olduğu halde iki metin arasında `+` ile kullanıldığında otomatik olarak metne çevrilir ve metin birleştirme yapılır.
- `char` ile `int` arasında dönüşümde ASCII tablosu kullanılır: `'3'` karakterinin ASCII karşılığı `51`'dir.

### 3.2 Büyük türden küçük türe otomatik dönüşüm yok

Derste ek olarak `double z = 5.4;` tanımlanıp bir `int` değişkene `x = z;` diye atanmaya çalışıldı ve Eclipse hata verdi. Küçük tür büyük türe otomatik dönüşür (eksik kısım doldurulur), ama büyük tür küçük türe otomatik dönüşmez. Bu satır `java` ile denendiğinde de "possible lossy conversion from double to int" derleme hatası alındı.

### 3.3 Zorla dönüştürme

Bir `double` değeri `int`'e çevirmek gerektiğinde dönüştürme zorla yapılır: parantez içinde hedef tür yazılır (ekrandan, 00:30:00 ve 00:35:00):

```java
// zorla dönüştürme
double x_d = 5.4;
int y_i = 8;
        y_i =(int)x_d;
System.out.println(y_i);

char y_c = (char)y_i;
System.out.println(y_c); //ascii tablosundan dönüşüm yapıyor.
```

`5.4` `int`'e çevrilince ondalık kısım silinir ve `5` elde edilir; yani veri kaybı olur. Satırın ilk halinde dönüşüm tanımlamayla birlikte yazılmıştı (`int y_i = (int)x_d;`, ekrandan 00:25:00). Bir öğrencinin sorusu üzerine değişken önce `8` ile tanımlanıp sonra atama yapıldı; sonuç yine `5` oldu (bkz. Örnek Sorular). Bellekte `y_i`'nin adresinde önce `8` vardır; yazdırmadan önce bu adrese `5` yazıldığı için `8`'in bir etkisi kalmaz.

Sonra `5` değeri `(char)` ile karaktere çevrildi ve ASCII tablosunda 5 koduna karşılık gelen karakter yazdırıldı. Konsolda bu karakter bir simge olarak göründü (ekrandan, 00:25:00).

### 3.4 Metinden sayıya dönüştürme

Metin tutan bir değişken `(double)` ya da `(int)` ile dönüştürülemez. Derste `//double yas_d = (double) yas;` satırı yorum olarak bırakılmıştı; sonra `int yas_d = (int) yas;` yazılarak hatası gösterildi (ekrandan, 00:40:00). Metinden sayı elde etmek için her ilkel türün sarmalayıcı sınıfının (baş harfi büyük yazılan sınıf: `Integer`, `Double`, `Float`) hazır metotları kullanılır: `Integer.parseInt`, `Double.parseDouble`, `Float.parseFloat`. Bu metotlar parametre olarak bir `String` alır ve onun sayısal değerini döndürür. Eclipse'in öneri penceresinde de `parseInt(String s) : int` görünüyordu (ekrandan, 00:30:00).

```java
String yas = "50.4";
//double yas_d = (double) yas;
double yas_d = Double.parseDouble(yas);
System.out.println(yas_d);
int yas_i = (int) yas_d;
System.out.println(yas_i);
```

Çıktı `50.4` ve `50`'dir (ekrandan, 00:35:00). `double`'dan `int`'e geçerken yine veri kaybı oldu.

### 3.5 Veri kaybı her zaman kötü değil

Bu veri kaybının bazen işe yaradığı söylendi. Bir sayının tam kısmını bulmak için 10 ile çarpıp mod almak gibi işlemler yapmak yerine doğrudan `(int)` dönüşümü kullanılabilir. Özellikle sayının basamak sayısı değişken olduğunda (`50.4`, `500.4`, `3.4` gibi) mod ile tam kısmı bulmak zahmetlidir; `(int)` ile tam kısım (`50`) kolayca elde edilir.

## 4. Nesnelerde Tip Dönüştürme

### 4.1 Kalem ve TukenmezKalem

İlkel olmayan tiplerde dönüştürmenin kalıtım konusunda da görüldüğü hatırlatıldı. Örnek için iki basit sınıf yazılmıştı: `Kalem` ve ondan kalıtım alan `TukenmezKalem` (`TukenmezKalem extends Kalem`). Sınıfların tek işi, `toString` override edilerek kendi adlarını yazdırmaktır ("Kalem sınıfı", "Tükenmez kalem sınıfı"). `println` ile nesne yazdırıldığında arka planda `toString` çağrılır.

<!-- BELİRSİZ: Kalem ve TukenmezKalem sınıflarının kodu karelerde görünmüyor; yapıları anlatımdan ve konsol çıktısından kuruldu. -->

Ekrandaki kodun ikinci kısmı şudur (ekrandan, 00:35:00):

```java
//ilkel olmayan veri tiplerini dönüştürme
TukenmezKalem tk = new TukenmezKalem();
System.out.println(tk);

Kalem k = new Kalem();
System.out.println(k);

k=(Kalem)tk;
System.out.println(k);
if(k instanceof TukenmezKalem) System.out.println("Evet");
if(k instanceof Kalem) System.out.println("Evet");
```

Konsol çıktısı (ekrandan, 00:35:00):

```text
Tükenmez kalem sınıfı
Kalem sınıfı
Tükenmez kalem sınıfı
Evet
Evet
```

`Kalem` türündeki `k` değişkeni bir `TukenmezKalem` nesnesini tutabilir. Bunun koşulu kalıtımdır: `extends` ile tükenmez kalemin kalemden kalıtım aldığı, yani "tükenmez kalem bir kalemdir" denmiştir. `k` yazdırıldığında yine "Tükenmez kalem sınıfı" çıkar, çünkü değişken `Kalem` türünde olsa da tuttuğu nesne bir tükenmez kalemdir. `k` hem `TukenmezKalem`'in hem `Kalem`'in örneğidir; bu yüzden iki `instanceof` sınaması da "Evet" yazar. Kalıtım olmasaydı bu dönüşüm yapılamazdı.

Bu örnek tip dönüştürmeyle birlikte `java` ile çalıştırılarak denendi; çıktı ekrandakiyle aynıdır.

### 4.2 Cast yazmak gerekli mi

`k = (Kalem) tk;` satırındaki `(Kalem)` yazılmasa da dönüşüm otomatik olur. Derste satır `k = tk;` yapılıp çalıştırıldı ve aynı sonuç alındı (ekrandan, 00:40:00). Parantez, dönüşümün görülmesi için bilerek yazılmıştı.

### 4.3 Kardeş sınıflar ve ters yön

Kalemden kalıtım alan bir `KursunKalem` sınıfı olsaydı, tükenmez kalem kurşun kaleme dönüştürülemezdi. İkisi de bir kalemdir, ama tükenmez kalem bir kurşun kalem değildir; aralarında kalıtım ilişkisi yoktur. Dönüşüm ancak üst sınıfa (superclass) doğru yapılabilir.

Ters yönde, `TukenmezKalem` türündeki bir değişkene `Kalem` nesnesi atanması da derste denendi ve hata verdi.

<!-- BELİRSİZ: Ters yön denemesinde yazılan satır karede görünmüyor; tam olarak hangi atamanın denendiği altyazıdan anlaşılmıyor. -->

> **Ek bilgi (derste anlatılmadı):** Alt sınıfa doğru dönüşüm (downcasting) açık cast ile yazılabilir: `tk = (TukenmezKalem) k;` derlenir. Bu, `k` gerçekten bir `TukenmezKalem` nesnesi tutuyorsa çalışır; düz bir `Kalem` nesnesi tutuyorsa çalışma anında `ClassCastException` fırlatılır. Cast yazılmadan yapılan `tk = k;` ataması ise derleme hatasıdır.

## 5. Metin Dosyasına Yazma ve Okuma

### 5.1 Urun sınıfı

Dosya örneklerinde `Urun` sınıfı kullanıldı. Sınıf `isim` ve `fiyat` adında iki alan, bir yapıcı, `toString` ve get/set metotları içeren basit bir sınıftır. `SerializableUrun` da aynı yapıdadır; tek farkı `java.io.Serializable` arayüzünü uygulamasıdır (bkz. 6.1).

<!-- BELİRSİZ: Urun ve SerializableUrun sınıflarının kodu karelerde görünmüyor; yapıları anlatımdan ve konsoldaki toString çıktısından alındı. -->

### 5.2 Dosyaya yazma: WriteFile

Ekrandaki `WriteFile.java` (ekrandan, 00:45:00):

```java
package filestream;

import java.io.FileWriter;

public class WriteFile {
    public static void main(String[] args) {
        ArrayList<Urun> urunler = new ArrayList<>();
        Urun Urun1 = new Urun("Urun1",10.0);
        Urun Urun2 = new Urun("Urun2",15.0);
        urunler.add(Urun1);
        urunler.add(Urun2);

        try {
          FileWriter myWriter = new FileWriter("urunler.txt");
          for (Urun u: urunler)
            myWriter.write(u.getIsim() + ", " + u.getFiyat() + "\n");
          myWriter.close();
          System.out.println("Dosyaya başarıyla yazıldı.");
        } catch (IOException e) {
          System.out.println("Hata oluştu.");
        }

    }
}
```

<!-- BELİRSİZ: import satırları karede katlanmış; yalnız ilki (java.io.FileWriter) görünüyor. Kodun çalışması için java.io.IOException ve java.util.ArrayList de içe aktarılmalıdır. -->

İşleyiş şöyledir: iki `Urun` nesnesi oluşturulup bir `ArrayList`'e eklenir. `FileWriter` sınıfından bir nesne oluşturmak aslında bir dosya oluşturmaktır; parametreye dosyanın adresi ve adı yazılır. Adres belirtilmediği için dosya projenin bulunduğu dizinde oluşur. Sonra liste dolaşılır; her ürünün önce adı, sonra fiyatı, aralarında virgülle dosyaya yazılır ve `\n` ile alt satıra geçilir. Böylece `urunler.txt` dosyasına iki satır yazılır:

```text
Urun1, 10.0
Urun2, 15.0
```

Son olarak `myWriter.close()` ile dosya kapatılır.

> **Hocanın vurgusu:** Dosyayı kapatın. Java'da kapatılmasa çok bir şey olmayabilir, ama C++ gibi dillerde kapatmamak sorun çıkarır; her durumda kapatılmalıdır.

Kod `try-catch` içindedir. Dosya oluşturulurken bir hata alınırsa `try` bloğundaki sonraki satırlar çalışmaz, `catch` bloğu çalışır ve "Hata oluştu." yazılır. Derste kod çalıştırıldı, "başarıyla yazıldı" mesajı alındı ve proje dizininde oluşan dosya açılıp iki satır gösterildi.

### 5.3 Dosyadan okuma: ReadFile

Ekrandaki `ReadFile.java` (ekrandan, 00:50:00):

```java
package filestream;

import java.io.File;

public class ReadFile {
    public static void main(String[] args) {
        ArrayList<Urun> urunler = new ArrayList<>();
        try {
          File myObj = new File("urunler.txt");
          Scanner myReader = new Scanner(myObj);
          while (myReader.hasNextLine()) {
            String data = myReader.nextLine();
            String tokens[] = data.split(", ");
            System.out.println(tokens[0] + "\t" +tokens[1]);
//            String urun_name = tokens[0];
//            double urun_fiyat = Double.parseDouble(tokens[1]);
//            Urun urun = new Urun(urun_name, urun_fiyat);
            urunler.add(new Urun(tokens[0],Double.parseDouble(tokens[1])));
          }
          myReader.close();
        } catch (FileNotFoundException e) {
          System.out.println("Dosya bulunamadı.");
        }
            System.out.println(urunler);
    }

}
```

Dosyadaki her satır bir ürün olarak `ArrayList`'te tutulacaktır. `File` nesnesi (`myObj`) yalnız dosyayı temsil eder; okumayı `Scanner` yapar. `myObj` `Scanner`'a parametre olarak verilir. `hasNextLine()` sonraki satır var mı diye bakar; varsa `nextLine()` o satırı getirir. Satır `split(", ")` ile parçalara ayrılır: `tokens[0]` ürün adı, `tokens[1]` fiyattır. Bunlar arada sekme (`\t`) ile ekrana yazdırılır. Fiyat dosyadan metin olarak (`"10.0"`) gelir; `Double.parseDouble` ile sayıya çevrilip yeni bir `Urun` nesnesi oluşturulur ve listeye eklenir. Yorum satırlarındaki üç satır aynı işi adım adım yapan uzun yazımdır. Dosya sonuna kadar okunduktan sonra `Scanner` kapatılır ve liste yazdırılır.

Konsol çıktısı (ekrandan, 00:50:00):

```text
Urun1   10.0
Urun2   15.0
[Urun{isim=Urun1, fiyat=10.0}, Urun{isim=Urun2, fiyat=15.0}]
```

Dosya bulunamazsa `FileNotFoundException` fırlatılır ve "Dosya bulunamadı." yazılır. Başka hatalar da olabilir; onlar için ek bir `catch (IOException e)` ya da en genel `catch (Exception e)` bloğu yazılabilir ve dosya bulunamaması dışındaki her hata oraya düşer.

Yazma ve okuma örnekleri birlikte, `Urun` sınıfı anlatıma göre kurularak `java` ile çalıştırıldı; dosya içeriği ve çıktı ekrandakiyle aynıdır.

## 6. Nesneyi Dosyaya Yazma ve Okuma (Serileştirme)

### 6.1 Serializable arayüzü

Bayt bayt yazma ve okumaya serileştirme (serializable) denir. Önceki örnekte ürünün adı ve fiyatı `getIsim()` ve `getFiyat()` ile tek tek alınıp yazılmıştı. Burada ise nesnenin kendisi doğrudan yazılır, çünkü yazma bayt düzeyinde yapılır; alanın tamsayı ya da metin olması fark etmez.

Bunun için sınıfın `java.io.Serializable` arayüzünü uygulaması (`implements`) gerekir. Sınıflar `extends` ile genişletilir, arayüzler `implements` ile uygulanır. Bir arayüz uygulandığında normalde onun soyut metotları override edilmek zorundadır, ama `Serializable`'ın içi tamamen boştur; override edilecek bir metot yoktur.

Sınıfa ayrıca bir satır eklendiği, eklenmeyince Eclipse'in uyarı (sarı işaret) verdiği söylendi; bu satırın neden gerektiği derste açıklanmadı.

<!-- BELİRSİZ: Eklenen satır karede görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu uyarı büyük olasılıkla `serialVersionUID` alanının eksik olduğunu bildirir (`private static final long serialVersionUID = 1L;`). Bu alan, dosyaya yazılan nesne ile okunurken kullanılan sınıfın aynı sürüm olduğunu denetlemek için kullanılır. İçi boş, yalnız işaret amaçlı bu tür arayüzlere işaretçi arayüz (marker interface) denir.

### 6.2 Nesneyi yazma: WriteObject

`WriteObject` örneğinde bir `Urun` ve bir `SerializableUrun` nesnesi oluşturuldu. Kod yine `try-catch` içindedir; hata çıkarsa program çökmez, hatanın ne olduğu yazılır. Burada `try-catch` yazılmazsa Eclipse zaten hata verir, yani yazdırmaya zorlar.

Adımlar şöyledir:

- `FileOutputStream` nesnesi oluşturulur ve `Urun.ser` adında bir dosya açılır.
- `ObjectOutputStream` nesnesi oluşturulur; dosya akışı (`FileOutputStream` nesnesi) ona parametre olarak verilir.
- `writeObject(nesne)` çağrılarak nesne dosyaya yazılır.
- Önce `ObjectOutputStream`, sonra `FileOutputStream` kapatılır ve "İşlem başarılı" yazdırılır.

<!-- BELİRSİZ: WriteObject.java'nın kodu karelerde görünmüyor; adımlar anlatımdan alındı. -->

Önce `Serializable`'ı uygulamayan ürün yazdırılmaya çalışıldı ve "işlem başarısız" mesajı alındı. Sınıf `Serializable`'ı uygulayınca işlem başarılı oldu. `writeObject`'e `urun2.getIsim()` gibi alanlar değil, doğrudan nesne (`urun2`) verildi.

Çalıştırma sonunda proje dizininde `Urun.ser` dosyası oluştu. Metin düzenleyicide açıldığında içeriği düzgün okunamadı; yine de sınıf adı, `fiyat` ve `isim` alan adları ve veri türü seçilebiliyordu.

### 6.3 Nesneyi okuma: ReadObject

Ekrandaki `ReadObject.java` (ekrandan, 00:55:00):

```java
package filestream;

import java.io.FileInputStream;

public class ReadObject {
    public static void main(String[] args) {
        try {
            FileInputStream fileIn = new FileInputStream("Urun.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);
            Object a = in.readObject();
            System.out.println(a);
            in.close();
            fileIn.close();
        } catch (IOException | ClassNotFoundException i) {
        }
    }
}
```

Yazarken çıkış (output), okurken giriş (input) akışları kullanılır. `FileInputStream` ile `Urun.ser` açılır, `ObjectInputStream`'e verilir ve `readObject()` çağrılır. Dönen değer `Object` türünde bir değişkende tutulur ve yazdırılır; `println` nesnenin `toString`'ini kullandığı için `Urun{isim=Urun2, fiyat=10.0}` çıktısı alındı (ekrandan, 00:55:00). Sonra iki akış kapatılır.

Ardından bir deneme yapıldı: dosyaya ikinci bir nesne de yazıldı ve okuma tarafında `readObject()` ikinci kez çağrılıp sonucu yazdırıldı. Bu kez ikinci nesne de geldi; çıktı `Urun{isim=Urun2, fiyat=10.0}` ve `Urun{isim=urun3, fiyat=10.4}` oldu (ekrandan, 01:00:00). Yani her `readObject()` çağrısı dosyadaki sıradaki nesneyi döndürür. Bu deneme `java` ile tekrarlandı ve aynı iki satır elde edildi.

> **Ek bilgi (derste anlatılmadı):** `readObject()` her zaman `Object` döndürür. Nesnenin kendi metotlarını (`getIsim()` gibi) kullanmak için `Urun u = (Urun) in.readObject();` biçiminde tip dönüştürme gerekir; bu, 4. bölümdeki nesne dönüştürmenin bir uygulamasıdır.

## 7. İş Parçacıkları (Thread)

### 7.1 İş parçacığı nedir

Normal bir program akışında satırlar sırayla çalışır: önce bir satır, sonra sonraki satır. Bir metot çağrılırsa o metot bitmeden sonraki satıra geçilmez. İş parçacıklarında ise bir satır çalışırken başka bir satır da aynı anda çalışır. Bunu göstermek için iki ayrı sınıfta birer döngü yazıldı; iki iş parçacığı bu iki döngüyü aynı anda çalıştırır, biri bitip öteki başlamaz.

İş parçacığı oluşturmanın derste anılan iki yolu vardır: `new Thread(...)` ile tek tek oluşturmak ve bir iş parçacığı havuzu kullanmak (bkz. 8. bölüm).

### 7.2 Runnable ve start

`Thread` sınıfının yapıcısı parametre olarak bir `Runnable` alır. Bu yüzden `Increaser` sınıfı `Runnable`'ı uygular. `Runnable` uygulandığında `run()` metodu override edilmek zorundadır. `t1.start()` çağrılınca `run()` ayrı bir iş parçacığında çalışır. Ekrandaki `ThreadOlusturma.java`'nın görünen kısmı (ekrandan, 01:00:00 ve 01:05:00):

```java
        Thread t1 = new Thread(new Increaser("nesne1"));
        Thread t2 = new Thread(new Onay());
        t1.start();
        t2.start();

    }
}

class Increaser implements Runnable {
    public static int sayi=5;
    private String name;

    public Increaser(String name){
        this.name = name;
    }
     public void add(){
       sayi++;
        try{for(int i =0; i<5;i++) {
            System.out.println(name+" çalıştı, sayı değeri artık= "+sayi);
            Thread.sleep(1000);
        }
        }catch(Exception e) {

        }

    }
    @Override
    public void run() {
        add();
    }
}

class Onay implements Runnable {

    public void onaylama(){
        try{
            for(int i =0;i<5;i++) { System.out.println("Onaylandı");
```

<!-- BELİRSİZ: Onay sınıfının geri kalanı ve main metodunun başı karelerde görünmüyor. Anlatıma göre onaylama() 5 kez "Onaylandı" yazar, Thread.sleep(1000) ile bekler ve run() onaylama()'yı çağırır. -->

`"nesne1"` adı `Increaser`'ın yapıcısından gelir; zorunlu bir şey değildir. `Increaser.run()` `add()`'i çağırır. `add()` `static` `sayi` değişkenini 5'ten 6'ya artırır ve döngüde 5 kez "nesne1 çalıştı, sayı değeri artık= 6" yazar. `Onay.run()` ise `onaylama()`'yı çağırır ve 5 kez "Onaylandı" yazar.

### 7.3 Çıktının yorumu

İş parçacığı olmasaydı `t1.start()` yerine metot doğrudan çağrılmış gibi önce 5 kez "nesne1 çalıştı..." satırı, sonra 5 kez "Onaylandı" yazılırdı. İş parçacıklarıyla ise satırlar karışık gelir. İlk çalıştırmada önce bir "nesne1" satırı, sonra beş "Onaylandı", sonra dört "nesne1" satırı geldi (ekrandan, 00:10:00). Bir sonraki çalıştırmada iki "Onaylandı", iki "nesne1", sonra üçerli gruplar geldi. Sıranın her çalıştırmada değişmesi normaldir: iki iş aynı zaman aralığında yürür. Örneğin program toplam 5 saniye sürüyorsa, bu 5 saniye içinde hem `Increaser` hem `Onay` çalışır.

Bunu daha açık göstermek için döngülere `Thread.sleep(1000)` eklendi. Her yazdırmadan sonra o iş parçacığı yaklaşık bir saniye durur. Bu kez çıktı "Onaylandı" ve "nesne1 çalıştı..." satırları birer birer, dönüşümlü geldi (ekrandan, 01:05:00): bir iş parçacığı yazdırma satırına geldikten birkaç milisaniye sonra öteki de kendi yazdırma satırına geliyor. Önce birinin bütünüyle bitip sonra ötekinin başlaması söz konusu değildir.

`Thread.sleep`'e süre milisaniye cinsinden verilir: 1000 yazılırsa 1 saniye, 2000 yazılırsa 2 saniye bekler.

Kod, karedeki satırlar ve anlatıma göre tamamlanan `Onay` sınıfıyla `java` ile çalıştırıldı; çıktıda "Onaylandı" ve "nesne1 çalıştı, sayı değeri artık= 6" satırları dönüşümlü geldi.

### 7.4 Faydası

İki iş aynı anda yapılabilir. Normalde $2t$ sürecek bir iş, iki iş parçacığına bölündüğünde $t$ sürede bitebilir.

## 8. İş Parçacığı Havuzu

### 8.1 Havuzun oluşturulması

Önceki örnekte iki iş parçacığı tek tek oluşturulmuştu. Havuzda ise kaç iş parçacığı olacağı baştan verilir: `Executors` sınıfının `newFixedThreadPool` metoduna parametre olarak iş parçacığı sayısı (örnekte 5) verilir ve bir `ExecutorService` elde edilir. Sonra bir `for` döngüsüyle 20 tane `MyThread` (bir `Runnable`) oluşturulup her biri `execute` ile havuza verilir.

Ekrandaki `Ornek2.java`'nın görünen kısmı (ekrandan, 01:10:00):

```java
            ex.execute(thread);

        }
        ex.shutdown();
        ex.awaitTermination(1, TimeUnit.DAYS);
        System.out.println("işlem bitti");

    }
}

class MyThread implements Runnable {

    private String name;

    public MyThread(String name) {
        this.name = name;

    }

    @Override
    public void run() {

        System.out.println(name+" çalıştı");
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}
```

Dosyanın karede görünmeyen başı, anlatıma göre şu biçimdedir (ara adım eklendi):

```java
ExecutorService ex = Executors.newFixedThreadPool(5);
for (int i = 1; i <= 20; i++) {
    Runnable thread = new MyThread("thread" + i);
    ex.execute(thread);
}
```

<!-- BELİRSİZ: Havuzun oluşturulduğu ve döngünün kurulduğu satırlar karede görünmüyor; döngü sınırları ve değişken adları anlatıma ve çıktıdaki "thread1"-"thread5" adlarına göre yazıldı. -->

### 8.2 Çıktı

Program çalıştırıldığında önce beş satır geldi; örneğin bir çalıştırmada sıra `thread2, thread5, thread4, thread1, thread3`, bir sonrakinde `thread2, thread5, thread3, thread1, thread4` oldu (ekrandan, 01:10:00). Sıra farklı olabilir, önemli değildir. Her iş parçacığı adını yazdırıp `Thread.sleep(5000)` ile 5 saniye bekler. Program devam ettirilseydi ardından 6, 7, 8, 9, 10 numaralı işler çalışacaktı.

Havuzun faydası olarak şu örnek verildi: bir fonksiyonda 5 iş yapılacaksa ve her iş parçacığına (örneğin `if` ile iş parçacığının numarasına bakarak) bir iş verilirse, her iş parçacığı kendi işini yapar; $5x$ sürede bitecek iş $x$ sürede biter.

> **Ders sonrası not:** Derste havuzun önce 5 iş parçacığıyla dolmasını beklediği, havuz dolunca çalışmaya başladığı söylendi (01:07:07 ve 01:11:03). Doğrusu: `newFixedThreadPool(5)` 5 işçi iş parçacığı tutar. `execute` ile verilen her iş, boş bir işçi varsa hemen çalışmaya başlar; havuzun dolması beklenmez. Boş işçi yoksa iş kuyrukta bekler. Çıktıda beşli grupların görülmesinin nedeni, her işin `Thread.sleep(5000)` ile işçisini 5 saniye meşgul etmesidir; bir işçi boşalınca kuyruktaki sıradaki iş başlar. Derste "20 tane thread oluşturuyorum" denen şey de büyük olasılıkla 20 iş (Runnable nesnesi) ve bunları çalıştıran 5 iş parçacığıdır. Bu davranış 1 saniyelik beklemeyle `java` üzerinde denendi: ilk beş iş hemen, sonraki beş iş bir saniye sonra başladı.

### 8.3 shutdown ve awaitTermination

Bir öğrencinin sorusu üzerine son iki satır açıklandı. `ex.shutdown()` ile havuza artık iş eklenmeyeceği bildirilir: "ben bittim, bana artık iş ekleyemezsin". `ex.awaitTermination(1, TimeUnit.DAYS)` ise çalışmakta olan işlerin hepsinin bitmesini bekler; en fazla bekleme süresi burada bir gündür. Bunun ardından "işlem bitti" yazdırılır.

> **Ek bilgi (derste anlatılmadı):** `shutdown()` çalışan ve kuyrukta bekleyen işleri iptal etmez; yalnız yeni iş kabulünü kapatır, var olan işler tamamlanır. Hepsini hemen durdurmaya çalışan metot `shutdownNow()`'dur. `awaitTermination` `InterruptedException` fırlatabildiği için `main` bu istisnayı bildirmeli ya da yakalamalıdır.

## Örnek Sorular

**1.** (derste sözlü, 00:20:23) İç sınıf ne tür durumlarda kullanılır?

> **Çözüm:** Bir sınıfı yalnız tek bir sınıf kullanıyorsa ve onunla ilişkiliyse, onu ayrı yazmak yerine kullanan sınıfın içine iç sınıf olarak yazmak daha okunaklı ve kısadır. Başka bir sınıf da ondan nesne oluşturacaksa dışarıda tutulur. Çalışma bakımından iki ayrı sınıf yazmakla fark yoktur; bu bir yazım tekniğidir.

**2.** (derste sözlü, 00:27:24) Zorla dönüştürme yalnız tanımlama sırasında mı yapılır? `y_i` önce `int` olarak tanımlanıp sonra aşağıda atanabilir mi?

> **Çözüm:** Atanabilir. Derste `int y_i = 8;` yazılıp alt satırda `y_i = (int) x_d;` yapıldı; sonuç yine `5` oldu (ekrandan, 00:30:00). `y_i`'nin adresindeki `8` yazdırmadan önce `5` ile değiştirildiği için etkisi kalmaz.

**3.** (derste sözlü, 00:35:25) Kalemden kalıtım alan bir kurşun kalem sınıfı olsaydı, tükenmez kalem kurşun kaleme dönüştürülebilir miydi?

> **Çözüm:** Hayır. İkisi kardeş sınıflardır; tükenmez kalem bir kalemdir ama bir kurşun kalem değildir. Dönüşüm yalnız kalıtım ilişkisi olan türler arasında, üst sınıfa doğru yapılabilir.

**4.** (derste sözlü, 00:36:41) Tükenmez kalem türündeki bir değişken bir kalem nesnesini tutabilir mi?

> **Çözüm:** Derste denendi ve hata verdi; ters yönde atama yapılamaz. Ayrıntı için 4.3'teki ek bilgiye bakın: açık cast ile derlenir ama nesne gerçekten tükenmez kalem değilse çalışma anında `ClassCastException` alınır.

**5.** (derste sözlü, 00:37:49) `k = (Kalem) tk;` satırında parantez içine tür yazmadan dönüştürme yapılabilir miydi?

> **Çözüm:** Evet. Alt sınıftan üst sınıfa dönüşüm otomatiktir. Derste satır `k = tk;` yapılıp çalıştırıldı, aynı çıktı alındı (ekrandan, 00:40:00).

**6.** (derste sözlü, 00:38:58) `(int)` ile dönüştürme ile `Integer.parseInt` arasındaki fark nedir? İkisi de aynı işi yapıyorsa neden ikisi de var?

> **Çözüm:** Parantezli dönüştürme sayısal türler arasında (örneğin `double` → `int`) çalışır, ama `String` üzerinde çalışmaz: `int yas_d = (int) yas;` hata verir (ekrandan, 00:40:00). `Integer.parseInt` ise parametre olarak `String` alır ve metnin sayısal değerini döndürür.

**7.** (derste sözlü, 01:11:03) Havuz işleri anında çalıştırmıyor mu, havuzun dolmasını mı bekliyor?

> **Çözüm:** Derste "evet, bekliyor" diye cevaplandı. Doğru cevap 8.2'deki ders sonrası nottadır: havuzun dolması beklenmez; boş işçi varsa iş hemen başlar, yoksa kuyrukta bekler. Beşli gruplar `Thread.sleep(5000)` yüzünden görülür.

**8.** (derste sözlü, 01:11:14) `ex.shutdown()` satırından sonraki `awaitTermination` satırı ne yapıyor?

> **Çözüm:** `shutdown()` havuza yeni iş eklenmesini kapatır. `awaitTermination(1, TimeUnit.DAYS)` çalışan işlerin hepsinin bitmesini en fazla bir gün bekler; sonra "işlem bitti" yazılır.

## Dersin Toparlaması

Bu uygulama oturumunda dört konu hazır kodlarla gösterildi. İç sınıflarda iç sınıf nesnesinin dış sınıf nesnesi üzerinden `myOuter.new InnerClass()` ile, `static` iç sınıfın ise dış sınıf nesnesi olmadan `new OuterClass.InnerClass()` ile oluşturulduğu görüldü; iç sınıfın çalışma bakımından iki ayrı sınıftan farkı olmadığı, okunurluk için ve yalnız tek sınıfın kullandığı sınıflarda tercih edildiği anlatıldı. Tip dönüştürmede küçük türden büyüğe otomatik, büyükten küçüğe zorla (`(tür)`) dönüşüm, `char` ile `int` arasında ASCII karşılığı, metinden sayıya `parse` metotları ve nesnelerde kalıtıma bağlı dönüşüm ile `instanceof` gösterildi.

Dosya işlemlerinde `FileWriter` ile metin dosyasına yazma, `File` ve `Scanner` ile satır satır okuyup `split` ve `Double.parseDouble` ile nesneye çevirme; `Serializable` arayüzü, `ObjectOutputStream.writeObject` ve `ObjectInputStream.readObject` ile nesneyi doğrudan dosyaya yazıp okuma işlendi. Son olarak `Runnable` uygulayan sınıflarla iş parçacığı oluşturma, `start`, `Thread.sleep` ve eş zamanlı çalışmanın çıktıya etkisi ile `Executors.newFixedThreadPool`, `execute`, `shutdown` ve `awaitTermination` kullanılan iş parçacığı havuzu gösterildi. İş parçacıklarının önemli bir konu olduğu, bu oturumda yalnız yüzeysel anlatıldığı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
