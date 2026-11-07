# Ders 23 Çalışma Özeti

## Genel Konular

- Kayıt yaklaşık 7 dakikalıktır. Bu kayıt bir ders değil, laboratuvar sınavı (NYP LAB-4) oturumudur. Konu anlatılmadı.
- NYP LAB-4 sorusu
  - Öğrencilere hazır bir `Test.java` sınıfı verildi. Kodun bu test sınıfına uygun yazılması bekleniyor.
  - `Customer` nesnelerini tutan liste dosya sistemine kaydedilecek. Serileştirme (serialization) ve geri okuma (deserialization) kullanılacak.
  - `Management` sınıfında üç metot istendi:
    - `saveBookings(...)`: listeyi parametre olarak alır ve dosyaya yazar.
    - `customerInfo(...)`: verilen `Customer` nesnesinin bilgilerini örnek çıktıdaki gibi ekrana basar. Bu bilgi kaydedilen dosyadan okunmalıdır.
    - `changeBooking(...)`: `Customer` nesnesini ve gün sayısını belirten bir `int` alır. Müşterinin kalacağı gün sayısını değiştirir. Müşteri bulunamazsa uygun mesaj verilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu kayıtta konu vurgusu yoktur.

## Kısa Tekrar Notları

- Serileştirme: nesneyi bayt dizisine çevirip dosyaya yazmak. Geri okuma: dosyadaki baytlardan nesneyi yeniden oluşturmak.
- Serileştirilecek sınıf `java.io.Serializable` arayüzünü uygulamalıdır.
- Yazma: `ObjectOutputStream` ile `writeObject(...)`. Okuma: `ObjectInputStream` ile `readObject()` ve tip dönüşümü.
- Akışlar `try-with-resources` ile açılırsa otomatik kapanır.
- `readObject()` checked istisnalar fırlatabilir: `IOException`, `ClassNotFoundException`.

## Detaylı Açıklamalar

### Serileştirme ile liste kaydetme ve okuma

Sınavdaki işin temel kısmı aşağıdaki gibidir. Bu kod derste yazılmadı; konuyu hatırlatmak için eklendi ve Java 25 ile çalıştırılarak denendi (çıktı: `Ali 3`).

```java
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Ser {
    static class Customer implements Serializable {
        private static final long serialVersionUID = 1L;
        String name;
        int days;
        Customer(String name, int days) { this.name = name; this.days = days; }
    }

    static void saveBookings(List<Customer> list) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("bookings.dat"))) {
            out.writeObject(list);
        }
    }

    @SuppressWarnings("unchecked")
    static List<Customer> loadBookings() throws IOException, ClassNotFoundException {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("bookings.dat"))) {
            return (List<Customer>) in.readObject();
        }
    }

    public static void main(String[] args) throws Exception {
        List<Customer> list = new ArrayList<>();
        list.add(new Customer("Ali", 3));
        saveBookings(list);
        System.out.println(loadBookings().get(0).name + " " + loadBookings().get(0).days);
    }
}
```

- `ArrayList` zaten `Serializable`'dır. İçindeki `Customer` nesneleri de `Serializable` olmalıdır, yoksa `NotSerializableException` oluşur.
- `changeBooking` gibi değişiklik yapan bir metot, değişiklikten sonra listeyi dosyaya yeniden yazmalıdır. Yoksa dosyadaki veri eski kalır.

### Ders sonrası notlar

- Kayıt kısa bir sınav oturumudur. Sınav sorusunun ayrıntıları altyazıdan ve ekrandaki PDF'ten ("NYP LAB-4 2021") alındı.
- Altyazının 00:05:36'daki "Thank you." satırı büyük olasılıkla Whisper'ın sessiz bölümde ürettiği bir halüsinasyondur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
