# Ders 23 Genişletilmiş Notu: Uygulama Sınavı: Serileştirme ile Otel Rezervasyonu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Niteliği
- 2. Sorunun Senaryosu: Odalar ve Müşteriler
- 3. Management Sınıfı ve Metotları
- 4. Beklenen Çıktı ve Hesap
- 5. Soru-Cevap
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Niteliği

Bu kayıt kısa bir uygulama sınavı oturumudur; yeni bir konu anlatılmaz. Soru sisteme yüklenir, açılana kadar geçen sürede soru ekranda paylaşılarak açıklanır. Sorunun "çok uğraştırmayan", tamamen dosyaya yazma ve okuma üzerine kurulu olduğu söylenir: nesneler **serileştirme** (serialization) ile dosyaya kaydedilecek, **ters serileştirme** (deserialization) ile dosyadan geri okunacaktır. Yani soru, önceki derslerde işlenen dosya işlemleri ve serileştirme konularının bir uygulamasıdır.

Ekranda iki şey görünür: soru metninin bulunduğu açıklama PDF'i ve sorunun hazır verilen test sınıfı (`Test.java`). Açıklama PDF'inde nesne parametrelerinin anlamı yazılmadığı için bunlar ayrıca sözlü olarak açıklanır.

## 2. Sorunun Senaryosu: Odalar ve Müşteriler

Senaryo bir oteldir. İki tür nesne vardır.

**Oda (`Room`).** Her oda iki parametreyle oluşturulur: ilki oda numarası, ikincisi odanın gecelik fiyatı. Test sınıfında dört oda vardır (ekrandan, 00:10:00):

```java
Room r1 = new Room(101,300);
Room r2 = new Room(102,500);
Room r3 = new Room(201,1000);
Room r4 = new Room(202,2000);
```

**Müşteri (`Customer`).** Her müşteri dört parametreyle oluşturulur: kimlik numarası gibi düşünülebilecek, müşteriye özel bir numara; müşterinin adı; odada kaç gün kalacağı; hangi odayı tuttuğu (bir `Room` nesnesi). Müşteri numarasının soruda pek bir işlevi olmayacağı da belirtilir.

```java
Customer c1 = new Customer(123, "Joe Deen", 5, r1);
Customer c2 = new Customer(234,"Zoey Cripp", 3, r2);
Customer c3 = new Customer(345,"Frank Zone", 7, r3);
Customer c4 = new Customer(456, "Alan Stanley", 10, r4);
```

Örneğin `c1`, 101 numaralı ve gecesi 300 olan `r1` odasında 5 gün kalacaktır. Sonra müşteriler bir `LinkedList<Customer>` içine konur. Burada bilerek bir ayrıntı bırakılmıştır: dört müşteri oluşturulur ama listeye yalnız ilk üçü eklenir; dördüncü müşteri (`c4`) listeye eklenmez.

```java
LinkedList <Customer> list = new LinkedList<>();
list.add(c1);
list.add(c2);
list.add(c3);
```

## 3. Management Sınıfı ve Metotları

Bütün işlemler bir yönetim sınıfı üzerinden yürütülür. Test sınıfında bu sınıf otel adıyla oluşturulur ve metotları sırayla çağrılır (ekrandan, 00:05:00):

```java
Management mng = new Management("Big Five Hotel");
mng.saveBookings(list);

mng.customerInfo(c4);

System.out.println("**************************");
mng.customerInfo(c3);

System.out.println("**************************");
mng.changeBooking(c3, 10);
mng.customerInfo(c3);
System.out.println("**************************");
```

### 3.1 saveBookings

İlk adımda oluşturulan liste dosyaya kaydedilir. Kaydetmenin serileştirme işlemiyle yapılması istenir; bilgiler daha sonra bu dosyadan çekilecektir.

### 3.2 customerInfo

Bu metot dosyayı okur, içeriği ters serileştirir ve verilen müşterinin bilgilerini ekrana yazdırır. Soru metnindeki ifade şöyledir: bilgiler aşağıdaki çıktıda görülen bilgileri içerecek şekilde ekrana basılmalıdır ve bu işlem yapılırken kaydedilen dosyadan okuma yapılması gerekmektedir (ekrandan, 00:05:00). Yani bilgi bellekteki `c3` nesnesinden doğrudan alınmamalı, dosyadan okunmalıdır.

Müşteri dosyada varsa ekrana dört bilgi basılır: adı, kaldığı oda numarası, kaç gün kalacağı ve toplam ücret (total cost). Müşteri dosyada yoksa böyle bir müşterinin bulunamadığı yazılır. `c4` listeye eklenmediği için `customerInfo(c4)` çağrısında bu mesaj beklenir.

### 3.3 changeBooking

Soru metnine göre `changeBooking` metodu bir `Customer` nesnesi ve gün sayısını belirten bir `int` değer alır ve müşterinin kalacağı gün sayısında değişiklik yapar (ekrandan, 00:05:00). Örnekte `c3` müşterisinin kalacağı gün sayısı 10 yapılır.

Bu değişiklik dosyaya da yansıtılmalıdır. Değişiklik yapıldıktan sonra `customerInfo` tekrar çağrıldığında, bilgiler yine dosyadan okunacağı için müşterinin değişmiş bilgileri gelmelidir.

> **Hocanın vurgusu:** `changeBooking` içinde dosyaya yeniden yazma işlemi yapılabilir; basit düşünülmeli, dosya komple yeniden yazılabilir. Yeni bir dosya oluşturulmaz, aynı dosyadaki veriler değiştirilir.

## 4. Beklenen Çıktı ve Hesap

Toplam ücret, müşterinin kalacağı gün sayısı ile tuttuğu odanın gecelik ücretinin çarpımıdır. Hesap `c3` için iki kez yapılır:

- Değişiklikten önce: `c3`, gecesi 1000 olan 201 numaralı odada 7 gün kalır. Toplam ücret $7 \times 1000 = 7000$.
- `changeBooking(c3, 10)` sonrası: gün sayısı 10 olur. Toplam ücret $10 \times 1000 = 10000$.

Hoca da bunu "yedi binden on bine çıktı" diye özetler. Açıklama PDF'inin ekranda görünen kısmında çıktının son satırları `Total Cost: 10000.0` ve bir yıldız satırıdır (ekrandan, 00:15:00). Değerin `10000.0` biçiminde basılması, ücretin `double` tutulduğunu gösterir.

<!-- BELİRSİZ: Beklenen çıktının tamamı (ad, oda ve gün satırlarının etiketleri ile "bulunamadı" mesajının metni) karelerde görünmüyor. -->

## 5. Soru-Cevap

**Soru:** Nesnelerin parametreleri ne anlama geliyor? (Soru oturum sırasında tekrar soruldu.)
**Cevap:** `Room` için ilki oda numarası, ikincisi gecelik ücret. `Customer` için ilki kişiye özel, kimlik numarası gibi bir numara; ikincisi adı; üçüncüsü kaç gün kalacağı; dördüncüsü `r1`, `r2`, `r3` odalarından hangisinde kalacağı.

**Soru:** `changeBooking` değişikliği nasıl yazmalı?
**Cevap:** Dosyaya tekrar yazma işlemi yapılabilir; dosya komple yeniden yazılabilir. Yeni dosya açılmaz, aynı dosyadaki veri değiştirilir.

## Örnek Sorular

### Soru 1: Otel rezervasyonlarının serileştirilmesi

Kaynak: (ekrandan, 00:05:00 ve 00:10:00; derste sözlü, 00:02:04 - 00:07:26)

Yukarıdaki `Test` sınıfı verilmiştir. `Room(odaNo, geceÜcreti)`, `Customer(numara, ad, günSayısı, oda)` ve `Management(otelAdı)` sınıflarını yazın:

- `saveBookings(LinkedList<Customer>)` listeyi serileştirerek dosyaya kaydetsin.
- `customerInfo(Customer)` kaydedilen dosyadan okuma yaparak müşterinin adını, oda numarasını, gün sayısını ve toplam ücretini yazsın; müşteri yoksa bulunamadığını bildirsin.
- `changeBooking(Customer, int)` müşterinin gün sayısını değiştirsin ve değişikliği aynı dosyaya yazsın.

> **Çözüm (derste verilmedi):** Aşağıdaki çözüm ajan tarafından yazıldı ve `java Test.java` ile çalıştırıldı. Dosya adı (`bookings.ser`) ve çıktı etiketleri ajanın seçimidir; soru PDF'indeki etiketler karelerde görünmüyor. Dosyadan okunan nesneler bellekteki `c3` ile aynı nesne değildir; bu yüzden müşteri `==` ile değil, numarasıyla aranır.

```java
import java.io.*;
import java.util.LinkedList;

public class Test {
    public static void main(String[] args) {
        Room r1 = new Room(101,300);
        Room r2 = new Room(102,500);
        Room r3 = new Room(201,1000);
        Room r4 = new Room(202,2000);

        Customer c1 = new Customer(123, "Joe Deen", 5, r1);
        Customer c2 = new Customer(234,"Zoey Cripp", 3, r2);
        Customer c3 = new Customer(345,"Frank Zone", 7, r3);
        Customer c4 = new Customer(456, "Alan Stanley", 10, r4);

        LinkedList <Customer> list = new LinkedList<>();
        list.add(c1);
        list.add(c2);
        list.add(c3);

        Management mng = new Management("Big Five Hotel");
        mng.saveBookings(list);

        mng.customerInfo(c4);

        System.out.println("**************************");
        mng.customerInfo(c3);

        System.out.println("**************************");
        mng.changeBooking(c3, 10);
        mng.customerInfo(c3);
        System.out.println("**************************");
    }
}

class Room implements Serializable {
    private static final long serialVersionUID = 1L;
    private int roomNo;
    private double price;   // gecelik ücret
    public Room(int roomNo, double price) { this.roomNo = roomNo; this.price = price; }
    public int getRoomNo() { return roomNo; }
    public double getPrice() { return price; }
}

class Customer implements Serializable {
    private static final long serialVersionUID = 1L;
    private int id;
    private String name;
    private int days;
    private Room room;
    public Customer(int id, String name, int days, Room room) {
        this.id = id; this.name = name; this.days = days; this.room = room;
    }
    public int getId() { return id; }
    public String getName() { return name; }
    public int getDays() { return days; }
    public void setDays(int days) { this.days = days; }
    public Room getRoom() { return room; }
    public double totalCost() { return days * room.getPrice(); }
}

class Management {
    private String hotelName;
    private final String fileName = "bookings.ser";
    public Management(String hotelName) { this.hotelName = hotelName; }

    public void saveBookings(LinkedList<Customer> list) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName))) {
            out.writeObject(list);
        } catch (IOException e) {
            System.out.println("Dosyaya yazilamadi: " + e.getMessage());
        }
    }

    @SuppressWarnings("unchecked")
    private LinkedList<Customer> loadBookings() {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName))) {
            return (LinkedList<Customer>) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Dosyadan okunamadi: " + e.getMessage());
            return new LinkedList<>();
        }
    }

    private Customer find(LinkedList<Customer> list, Customer c) {
        for (Customer x : list)
            if (x.getId() == c.getId()) return x;   // nesne kimligi degil, id karsilastirilir
        return null;
    }

    public void customerInfo(Customer c) {
        Customer x = find(loadBookings(), c);
        if (x == null) {
            System.out.println("Customer not found!");
            return;
        }
        System.out.println("Name: " + x.getName());
        System.out.println("Room No: " + x.getRoom().getRoomNo());
        System.out.println("Days: " + x.getDays());
        System.out.println("Total Cost: " + x.totalCost());
    }

    public void changeBooking(Customer c, int newDays) {
        LinkedList<Customer> list = loadBookings();
        Customer x = find(list, c);
        if (x == null) {
            System.out.println("Customer not found!");
            return;
        }
        x.setDays(newDays);
        saveBookings(list);   // ayni dosya bastan yeniden yazilir
    }
}
```

Çalıştırma çıktısı:

```text
Customer not found!
**************************
Name: Frank Zone
Room No: 201
Days: 7
Total Cost: 7000.0
**************************
Name: Frank Zone
Room No: 201
Days: 10
Total Cost: 10000.0
**************************
```

> **Ek bilgi (derste anlatılmadı):** `ObjectInputStream.readObject()` dosyadaki baytlardan yeni nesneler kurar. Bu yüzden ters serileştirilen `Customer`, programdaki `c3` değişkeniyle aynı referans değildir ve `list.contains(c3)` ya da `==` onu bulamaz (`equals` override edilmediyse). Aramayı bir anahtar alanla yapmak ya da `equals`/`hashCode` metotlarını bu alana göre override etmek gerekir. Ayrıca serileştirilen nesnenin içindeki `Room` gibi alanların sınıfları da `Serializable` olmalıdır; aksi halde `NotSerializableException` alınır.

## Dersin Toparlaması

Bu oturumda serileştirme ve dosya işlemleri bir otel rezervasyonu senaryosunda bir araya getirildi. Odalar ve müşteriler nesne olarak oluşturuluyor, müşteri listesi serileştirilerek dosyaya yazılıyor, sonra her sorguda bilgi aynı dosyadan ters serileştirilerek okunuyor. Gün sayısı değiştiğinde dosya baştan yeniden yazılıyor ve sonraki okuma güncel bilgiyi veriyor. Toplam ücret gün sayısı ile gecelik ücretin çarpımı olarak hesaplanıyor; örnekte 7000'den 10000'e çıkıyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
