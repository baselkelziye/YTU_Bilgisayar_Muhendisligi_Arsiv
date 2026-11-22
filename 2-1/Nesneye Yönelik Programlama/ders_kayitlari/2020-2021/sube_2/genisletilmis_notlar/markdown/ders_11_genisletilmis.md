# Ders 11 Genişletilmiş Notu: Uygulama 2: Kalıtım, Override ve Soyut Sınıflar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun konusu
- 2. Sahip olma ilişkisinden kalıtıma
- 3. Örnek sistem: Ders, ZorunluDers, SecmeliDers
- 4. Erişim belirteçleri ve protected
- 5. Üst sınıfı kodlamak: Ders
- 6. extends ve super ile alt sınıf constructor'ı
- 7. Override
- 8. Alanlarda super ile ayrım
- 9. Kitaplık uygulaması 2: soyut sınıf
- 10. Override ve overload farkı
- 11. Test sınıfı üzerinden uygulamanın akışı
- 12. Kitap satışı: kitapSat ve odemeYap
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun konusu

Bu kayıt dersin ikinci uygulama oturumudur ve konusu kalıtımdır (inheritance). Oturumu yürüten kişi, kalıtımın teorik derste henüz tam işlenmediğini fark ettiği için önce konuyu temelden anlatmayı seçer: küçük bir ders/not hesabı örneğiyle sınıfların nasıl türetildiğini canlı olarak kodlar. Ardından asıl uygulama olan kitaplık sisteminin ikinci sürümünü, yani kalıtım ve soyut sınıf eklenmiş hâlini hazır kod üzerinden inceler. Çalışma ortamı Eclipse, diyagramlar UML sınıf diyagramıdır.

## 2. Sahip olma ilişkisinden kalıtıma

Önceki uygulamadaki kitaplık sisteminde sınıflar arasında sahip olma ilişkileri vardı. Bir `Raf` nesnesi bir `Kitap` dizisi tutar; yani bir rafın içinde birçok kitap bulunur. Bu ilişkiler bütün-parça (composition, aggregation) biçiminde olabileceği gibi, bir sınıfın başka bir sınıfın tek bir nesnesini yalnızca kullanmak için tutması biçiminde de olabilir. Composition ve aggregation durumlarında genelde bir dizi ya da liste gibi çok veri tutan bir yapı bulunur. Bu ilişkinin özü "bu sınıf şuna sahiptir" (has-a) demektir.

Kalıtım ise farklı bir bağlantıdır: "bu sınıf aslında şu sınıftır" (is-a). Alt sınıf (subclass, çocuk sınıf) üst sınıfın (superclass) bir türüdür. Örneğin zorunlu ders de seçmeli ders de birer derstir.

Neden böyle bir yapıya ihtiyaç duyulur? Sınıflar arasında benzerlikler olabilir; birçok sınıf aynı metodu farklı biçimlerde kullanıyor olabilir. Ortak değişkenleri her sınıfta tek tek yazmak yerine bir üst sınıf yapılır, ortak nitelikler (attribute) orada tanımlanır. Alt sınıflar üst sınıfın üye alanlarına ve metotlarına erişim hakkına sahip olduğu için onları yeniden yazmadan kullanır.

UML'de kalıtım, alt sınıftan üst sınıfa çizilen ve ucu içi boş üçgen olan bir okla gösterilir.

## 3. Örnek sistem: Ders, ZorunluDers, SecmeliDers

Ekranda gösterilen diyagram şudur (ekrandan, 00:10:00):

```text
Ders
  # dersAdi: String
  # vize1: int
  # finalNotu: int
  + Ders(String, int, int)
  + hesaplaNot(): double

ZorunluDers  (Ders'ten türer)
  - vize2: int
  + ZorunluDers(int)
  + hesaplaNot(): double

SecmeliDers  (Ders'ten türer)
  - vize2: int
  - proje: int
  + SecmeliDers(int, int)
  + hesaplaNot(): double

TestDers  (Ders'e kesikli okla bağlı)
  + main(): void
```

Sistem bir not hesaplama örneğidir. `Ders` sınıfındaki `hesaplaNot` metodu, sınıfın kendi alanlarını kullanabildiğine göre, vize ve final notundan bir not hesaplar. Alt sınıflarda aynı ad, aynı parametre ve aynı dönüş tipiyle yine `hesaplaNot` bulunur; bu, metodun alt sınıfta override edildiğini gösterir (bölüm 7).

Diyagramda alt sınıf constructor'ları yalnız eklenen parametreleri gösterir: `ZorunluDers(int)` yalnız `vize2`'yi, `SecmeliDers(int, int)` yalnız `vize2` ve `proje`yi gösterir. Bu, constructor'ın tek parametreli olduğu anlamına gelmez; constructor üst sınıfın `String, int, int` parametrelerini de alır ve kendi ihtiyacı olanları ekler.

> **Ders sonrası not:** Diyagramda alan adı `finalNotu`, kodda ise `finalNot` olarak yazılmıştır (ekrandan, 00:20:00). İkisi aynı alanı gösterir.

## 4. Erişim belirteçleri ve protected

Önceki derslerden iki belirteç biliniyordu. `+` public demektir: o üyeye yalnız alt sınıftan değil, bütün sınıflardan erişilir. `-` private demektir: üyeye yalnız kendi sınıfının içinden erişilir.

Kalıtımla birlikte sıkça kullanılan üçüncü bir belirteç gelir: `#` ile gösterilen protected. Protected bir üye kendi sınıfında, alt sınıflarında ve sınıfın bulunduğu paketteki diğer sınıflarda kullanılabilir; farklı bir paketten erişilemez. Public ile private arasında bir düzeydir.

Paket, Eclipse'te bir proje oluşturduktan sonra `src` klasörüne sağ tıklayıp New > Package ile oluşturulur. Paketlerin amacı konuyla ilgili, benzer işleri yürüten sınıfları bir arada tutmaktır. Bu uygulamada iki paket vardır: ders örneği için `inheritanceEx`, kitaplık uygulaması için `uyg2` (ekrandan, 00:50:00).

## 5. Üst sınıfı kodlamak: Ders

`Ders` sınıfında üç alan protected olarak tanımlanır. Constructor, Eclipse'in Source > Generate Constructor using Fields seçeneğiyle üretilir; bu pencere hangi alanların kullanılacağını sorar, hepsi seçilir. Constructor'ın görevi, nesne ilk oluşturulduğunda verilen değerleri nesnenin alanlarına atamaktır.

`hesaplaNot` metodu `double` döndüren public bir metottur. Dönüş tipi `double` olduğu için Eclipse önce `return` eksik diye uyarır. Hesap klasik bir formüldür: vizenin %40'ı ile finalin %60'ı toplanır. Metot ayrıca hangi sınıfta çalıştığını görmek için bir ileti yazdırır. Eclipse'te `syso` yazıp Ctrl+Space'e basınca `System.out.println` otomatik gelir.

Ekrandaki kod (ekrandan, 00:20:00):

```java
protected String dersAdi;
protected int vize1;
protected int finalNot;

public Ders(String dersAdi, int vize1, int finalNot) {
    this.dersAdi = dersAdi;
    this.vize1 = vize1;
    this.finalNot = finalNot;
}

public double hesaplaNot(){
    System.out.println("Ders sınıfında hesaplaNot çalıştı.");
    return vize1*0.4 + finalNot*0.6 ;
}
```

## 6. extends ve super ile alt sınıf constructor'ı

### 6.1 extends

Bir sınıfın başka bir sınıfın alt sınıfı olduğu `extends` anahtar sözcüğüyle belirtilir: `public class SecmeliDers extends Ders`. Bu satır, `SecmeliDers` sınıfının `Ders` sınıfından türetildiğini ve onun metotlarını kullanacağını söyler.

`extends` yazılınca Eclipse hemen bir hata gösterir: üst sınıfta parametreli bir constructor olduğu için alt sınıfın da constructor tanımlaması gerekir. Anlatımda vurgulandığı gibi, Eclipse'in uyarılarına dikkatle bakıldığında hem nedeni hem de altında çözüm önerisi görünür. Önerilen çözüm, üst sınıfın constructor'ına uyan bir constructor'ı otomatik oluşturmaktır.

> **Ek bilgi (derste anlatılmadı):** Bu zorunluluğun nedeni, alt sınıf constructor'ının ilk iş olarak üst sınıfın bir constructor'ını çağırmasıdır. Açık bir `super(...)` yazılmazsa derleyici parametresiz `super()` ekler; üst sınıfta parametresiz constructor yoksa derleme hatası oluşur.

### 6.2 super ile constructor çağırmak

Üretilen constructor `super(...)` ile başlar. `super`, üst sınıfı temsil eder; parantez içine değişken adları yazılınca üst sınıfın constructor'ı bu değerlerle çalışır. Böylece ders adı, vize ve final alanları alt sınıfta yeniden tanımlanmaz ve yeniden atanmaz; üst sınıftan gelir.

Alt sınıf kendine özgü bir alan eklemek isterse onu kendisi tanımlar. `ZorunluDers` sınıfına üst sınıfta olmayan `vize2` eklenir ve constructor'a bir parametre olarak katılır; bu alan `this.vize2 = vize2` ile atanır. Seçmeli derse ise hem `vize2` hem `proje` eklenir. Ekrandaki seçmeli ders constructor'ı (ekrandan, 00:35:00):

```java
public class SecmeliDers extends Ders {
    private int vize2;
    private int proje;

    public SecmeliDers(String dersAdi, int vize1, int vize2, int finalNot, int proje) {
        super(dersAdi, vize1, finalNot);
        this.vize2=vize2;
        this.proje=proje;
    }
}
```

`TestDers` içinde `new ZorunluDers(...)` yazılırken, `ZorunluDers` sınıfında `dersAdi`, `vize1`, `finalNot` tanımlanmamış olsa da Java bu alanların üst sınıfta bulunduğunu bilir ve onları nesneye dahil eder. Kalıtım bu sayede aynı şeyleri tekrar tekrar yazmayı önler.

> **Ders sonrası not:** Oturumda seçmeli ders constructor'ı tamamlandıktan sonra "abstract class kavramını bu şekilde oluşturmuş olduk" denildi (00:27:38). Burada yapılan iş soyut sınıf değil, alt sınıf constructor'ını `super` ile tanımlamaktır; soyut sınıf bölüm 9'da ele alınır.

**Soru:** Bir öğrenci hata satırının, `Ders` sınıfındaki değişiklik kaydedilmediği için mi çıktığını sordu. **Cevap:** Evet; dosya kaydedilmediği için Eclipse diğer sınıfta hata gösteriyordu, kaydedince hata kalktı.

### 6.3 super çağrısı üst sınıfın constructor'ına uymalı

Üst sınıfın constructor'ı ders adı, vize ve final olmak üzere üç parametre aldığı için `super` ile çağrılırken üçü de verilmelidir. "Final notunu almayayım" diyerek `super`'e yalnız iki değer verilirse hata alınır. Eclipse bu durumda üst sınıfa yalnız `String` ve `int` alan iki parametreli bir constructor eklemeyi ya da çağrıyı değiştirmeyi önerir. Yani alt sınıfta hangi biçimde çağrı yapılacaksa üst sınıfta o biçimde bir constructor yazılmış olmalıdır.

### 6.4 Test sınıfında nesne oluşturmak

Test sınıfı (ekrandan, 00:30:00):

```java
Ders ders1=new Ders("İş Sağlığı", 75, 95);
System.out.println(ders1.hesaplaNot());

ZorunluDers zd1=new ZorunluDers("BBG", 80,90, 100);
//Ders zd1 = new ZorunluDers(""üstteki gibi);
System.out.println(zd1.hesaplaNot());

SecmeliDers sd1=new SecmeliDers("Mobil Prog.",50, 60, 70, 80);
System.out.println(sd1.hesaplaNot());
```

<!-- BELİRSİZ: SecmeliDers satırının başı karede açılır pencerenin altında kalıyor; "Mobil Prog." ders adı görünen "bil Prog." parçasından tahmin edildi. -->

Yorum satırındaki biçim önemlidir: `Ders zd1 = new ZorunluDers(...)` da yazılabilir. Zorunlu ders nesneleri aynı zamanda `Ders` nesnesidir, çünkü alt sınıfın nesnesi üst sınıfın da bir nesnesidir. Alt sınıfın nesnesi hem üst sınıfın üyelerini hem kendi üyelerini kullandığı için daha geniş kapsamlıdır.

## 7. Override

### 7.1 Tanım

Override, üst sınıftaki bir metodu alt sınıfta aynı ad, aynı parametreler ve aynı dönüş tipiyle yeniden yazmak, içini alt sınıfın ihtiyacına göre doldurmaktır ("metodu ezmek"). Üst sınıftaki metot o sınıfa göre çalışır; alt sınıf aynı metodu kendi hesabına göre yazabilir.

Eclipse'te Source > Override/Implement Methods seçilince override edilebilecek metotların listesi çıkar. Bu listede `toString` gibi metotlar da bulunur: Java'daki bütün sınıflar temelde `Object` sınıfından türediği için `toString` her sınıfta override edilebilir. Önceki uygulamada nesnenin içeriğini yazdırmak için `toString` bu yolla doldurulmuştu.

### 7.2 super.hesaplaNot()

Eclipse'in ürettiğindeki gövdede `return super.hesaplaNot();` bulunur. `super.` ile bir metodun adı yazılınca üst sınıftaki metot çağrılır; bu durumda yine yalnız vize ve final ağırlıklandırılır. Alt sınıfta kendi hesabı yapılmak istendiği için bu satır silinir ve gövde yeniden doldurulur. `super.metotAdi()` biçimi, alt sınıfın içindeyken üst sınıfın metodunu çağırmanın yoludur.

Zorunlu derste notun hesabında vize 1 ve vize 2 %30'ar, final %40 ağırlık alır; metot ayrıca "Zorunlu Ders notlari" iletisini yazar (ekrandan, 00:35:00). Bu metodun kodu karelerde görünmüyor; aşağıdaki sürüm anlatımdan ve ekrandaki çıktıdan kuruldu:

```java
@Override
public double hesaplaNot() {
    System.out.println("Zorunlu Ders notlari");
    return vize1*0.3 + vize2*0.3 + finalNot*0.4;
}
```

### 7.3 Override edilmeyen metot üst sınıftan çalışır

Bir alt sınıf metodu override etmezse, o metot alt sınıf nesnesi üzerinden çağrıldığında üst sınıftaki sürüm çalışır. Java, üst sınıfta böyle bir metot olduğu için ona erişebilir. Bu durum test çıktısında açıkça görünür. İlk çalıştırmada seçmeli ders henüz `hesaplaNot`'u override etmemiştir (ekrandan, 00:35:00):

```text
Ders sınıfında hesaplaNot çalıştı.
87.0
Zorunlu Ders notlari
91.0
Ders sınıfında hesaplaNot çalıştı.
62.0
```

Adım adım:

- `Ders("İş Sağlığı", 75, 95)`: $75 \cdot 0.4 + 95 \cdot 0.6 = 30 + 57 = 87.0$.
- `ZorunluDers("BBG", 80, 90, 100)`, yani vize1 = 80, vize2 = 90, final = 100: $80 \cdot 0.3 + 90 \cdot 0.3 + 100 \cdot 0.4 = 24 + 27 + 40 = 91.0$.
- `SecmeliDers("Mobil Prog.", 50, 60, 70, 80)`, yani vize1 = 50, vize2 = 60, final = 70, proje = 80. Override olmadığı için üst sınıfın formülü çalışır ve yalnız vize1 ile final kullanılır: $50 \cdot 0.4 + 70 \cdot 0.6 = 20 + 42 = 62.0$. Vize 2 ve proje hesaba girmez.

Ajan bu örneği (üç sınıf ve test, tek dosyada) Java 25'in tek dosya çalıştırıcısıyla (`java TestDers.java`) derleyip çalıştırdı; çıktı ekrandakiyle aynıdır. Zorunlu dersin parametre sırası (vize1, vize2, final) bu sonuçla doğrulanır.

Ardından seçmeli ders için de Source > Override/Implement Methods ile `hesaplaNot` override edilir ve gövdesi seçmeli derse özgü formülle doldurulur. Yeniden çalıştırınca çıktıda seçmeli ders sınıfının kendi iletisi görünür. Bu sürümde örnek olarak `super` ile üst sınıf metodunun nasıl çağrılacağını gösteren iki satır da yazılmış, sonra yorum satırı yapılmıştır.

<!-- BELİRSİZ: SecmeliDers.hesaplaNot formülü (proje ağırlığı vb.) ve ikinci çalıştırmanın çıktısı karelerde görünmüyor; altyazıda da formül okunmuyor. -->

> **Hocanın vurgusu:** Kalıtımda en çok kullanılacak şey override olacaktır.

## 8. Alanlarda super ile ayrım

`vize1` protected olduğu için alt sınıftan doğrudan erişilebilir. Normalde başka bir sınıftan `nesne.alan` biçiminde private bir alana erişilemez, ama protected alana alt sınıftan ulaşılabilir. Fare `vize1` üzerine getirildiğinde Eclipse bunun `Ders` sınıfının alanı olduğunu gösterir.

Fark görülsün diye alt sınıfta da `vize1` adında bir alan tanımlandığını düşünelim. Bu durumda alt sınıfın içinde yalın `vize1` yazılınca içinde bulunulan sınıfın alanı kullanılır; kendi sınıfının değişkeni önceliklidir. Üst sınıfın `vize1`'i kullanılmak isteniyorsa `super.vize1` yazılır. Bu ayrım yapılmazsa hesap alt sınıfın alanıyla yapılır ve anlamsız bir not çıkabilir. Aynı adlı iki alan varsa `super` ile hangisinin kastedildiği belirtilir.

## 9. Kitaplık uygulaması 2: soyut sınıf

### 9.1 Diyagram

Asıl uygulama, önceki kitaplık sisteminin üzerine kalıtım eklenmiş hâlidir. `Kitaplik`, `Raf`, `Kitap` kısmı ve aralarındaki ilişkiler aynıdır; yalnız birkaç metodun parametresi değişmiştir. Diyagram (ekrandan, 00:40:00 ve 00:45:00):

```text
<<abstract>> Kart
  - id: int
  - Sahip: String
  - Bakiye: double
  + getId(): int
  + getSahip(): String
  + getBakiye(): double
  + setBakiye(double)
  + toString(): String
  + odemeYap(double): <<abstract>> boolean

YetiskinKartı  (Kart'tan türer)
  + YetiskinKartı(int, String, double)
  + odemeYap(double): boolean

OgrenciKartı  (Kart'tan türer)
  - bonus: double
  + OgrenciKartı(int, String, double)
  + odemeYap(double): boolean

KitaplıkYonetim  (Kart'a kesikli ok, Kitaplik'e ok)
  - Kitaplık: kitaplık
  + kitapSat(kitap, kart): boolean
  + KitaplıkYonetim(Kitaplık)

Kitaplik  (Raf ile içi dolu elmas: composition)
  - raf: Raf[]
  + Kitaplik(int)
  + kitapEkle(Kitap, int): void
  + kitapSil(int, int): void
  + kitapSil(int, Kitap): void
  + kitapAra(String): int
  + gosterRaf(int): void
  + tumRaflariGoster(): void
  + kitapSat(kitap, kart): boolean

Raf  (Kitap ile içi boş elmas: aggregation)
  - kitaplar: Kitap[]
  + Raf()
  + KitapEkle(Kitap): void
  + kitapSil(int)
  + kitapSil(Kitap)
  + RafGoster(): void
  + getKitaplar(): Kitap[]

Kitap
  - ad: String
  - yazar: String
  - ISBN: String
  - fiyat: double
  - kitapSayisi: <static> int
  + Kitap(String, String, String)
  + getAd(), getYazar(), getISBN(): String
  + getKitapSayisi(): int
  + getFiyat(): double
  + setAd(String), setYazar(String): void
  + toString(): void
```

> **Ders sonrası not:** Diyagramda `Kitap` için `toString(): void` yazıyor; `toString` her zaman `String` döndürür. `Kart` için doğru biçimde `toString(): String` yazılmıştır.

Sistemin mantığı şudur: kitaplık bir kütüphane gibi düşünülür; `Kart` sınıfından türeyen yetişkin kartı ve öğrenci kartıyla kitap satın alınır. `KitaplikYonetim` sınıfı bu satış işini yürütür.

### 9.2 Soyut sınıf ve soyut metot

Kalıtımda karşılaşılan bir sınıf çeşidi soyut sınıftır (abstract class). Eclipse'te soyut sınıfın simgesinde bir "A" işareti görünür. Sıradan sınıf `public class` diye tanımlanırken soyut sınıf `public abstract class` diye tanımlanır.

Soyut sınıfın asıl özelliği soyut metotlarıdır. Soyut metodun süslü parantezleri, yani gövdesi yoktur; yalnız imzası yazılır ve noktalı virgülle bırakılır (ekrandan, 00:55:00):

```java
public abstract boolean odemeYap(double fiyat);

@Override
public String toString() {
    return "Kart [id=" + id + ", Sahip=" + Sahip + ", Bakiye=" + Bakiye + "]";
}
```

Bunun anlamı şudur: metot bu sınıfa yazılmıştır ama bu sınıf için doldurulmayacaktır; kalıtımla türetilen sınıflarda içinin mutlaka doldurulması gerekir. Soyut metodu olan bir sınıftan alt sınıf türetildiğinde Java bu metotların override edilmesini zorunlu kılar. Önceki `Ders` örneğinde böyle bir zorunluluk yoktu: `hesaplaNot` yalnız üst sınıfta yazılıp alt sınıflarda olduğu gibi kullanılabiliyordu. Burada ise üst sınıftaki metodun gövdesi olmadığı için alt sınıflar onu override etmek zorundadır.

> **Hocanın vurgusu:** Soyut kullanmanın önemi buradan gelir. Alt sınıflarda içinin mutlaka doldurulması gereken metotlar soyut yapılır; böylece bunun yapılacağından emin olunur.

Bu uygulamada soyut metot `odemeYap`'tır. Soyut olmayan sınıflara somut (concrete) sınıf denir. Somut alt sınıflar soyut sınıftan sıradan sınıflarda olduğu gibi `extends` ile türetilir; hiçbir farkı yoktur. Soyut sınıfın da constructor'ı vardır: `Kart`'ın üç parametreli constructor'ı alt sınıflarda `super` ile çağrılır, alt sınıf da kendine özgü ne varsa onu ekler. Öğrenci kartı id, sahip adı ve bakiyeye ek olarak `bonus` alanı taşır; yetişkin kartının ek alanı yoktur.

Yetişkin kartı (ekrandan, 01:00:00):

```java
public class YetiskinKartı extends Kart{

    public YetiskinKartı(int id, String Sahip, double Bakiye) {
        super(id, Sahip, Bakiye);
    }

    @Override
    public boolean odemeYap(double fiyat){
        if (getBakiye() >= fiyat){
            setBakiye(getBakiye() - fiyat);
            return true;
        }
        else{
            return false;
        }
    }
}
```

### 9.3 Soyut sınıftan nesne üretilemez

Test sınıfında öğrenci kartı iki biçimde tanımlanabilir: `OgrenciKarti kart1 = new OgrenciKarti(...)` ya da üst sınıf adını kullanarak `Kart kart1 = new OgrenciKarti(...)`. İkisi arasında fark yoktur. Ancak soyut sınıftan doğrudan nesne üretilemez; `new Kart(...)` yazılamaz. Nesne her zaman somut bir alt sınıftan üretilir.

## 10. Override ve overload farkı

Oturumda sık karıştırılan iki kavram ayrıca vurgulanır.

> **Hocanın vurgusu:** Override ile overload karıştırılmamalıdır; bu konu dersin kapsamındadır.

Override, metodun içini alt sınıfta yeniden doldurmaktır (bölüm 7). Overload ise metotların aşırı yüklenmesidir ve kalıtımla ilgisi yoktur; her sınıfta yapılabilir. Kitaplık sınıfındaki iki `kitapSil` metodu buna örnektir: aynı sınıftadırlar ve adları aynıdır. Bu bir hata değildir. Dönüş tipleri de aynı olabilir. Farklı olması gereken parametrelerdir: bir metot `int` tipinde, diğeri `Kitap` tipinde bir parametre alır. Metot çağrılırken hangi tipte değer gönderilirse Java ona uyan metodu otomatik seçer.

Parametre sayısı da farklı olabilir (`int, Kitap` gibi). Sıra da ayırt edicidir: `(int, String)` ve `(String, int)` iki ayrı geçerli metottur. Ama iki metodun da `(int, int)` alması durumunda derleyici hangisini çalıştıracağını bilemez. Kısacası overload'da metot adları aynıdır, parametre tip listeleri birbirinin aynısı olmamalıdır.

> **Ek bilgi (derste anlatılmadı):** Yalnız dönüş tipi farklı, parametre listesi aynı olan iki metot overload sayılmaz ve derleme hatası verir. Derleyici çağrıyı yalnız metot adı ve parametre tiplerine bakarak eşleştirir.

## 11. Test sınıfı üzerinden uygulamanın akışı

### 11.1 Statik üyeler

Test sınıfının başında `Kitap` sınıfındaki statik bir metot çağrılır; çıktısı "isbn kitapları ayırt etmek için eşsiz bir numaradır" iletisidir (ekrandan, 00:50:00). Eclipse'te bir metodun üzerine gelip Open Declaration seçilince metodun bulunduğu sınıf ve tanımı açılır.

Statik metot ve değişkenler, nesne üretmeden sınıfın adı, nokta ve üye adıyla çağrılabilir. Normalde bir metodu çağırmak için önce o sınıftan nesne üretmek gerekir. Statik üye bir nesneyle de çağrılabilir, ama bu uygun görülmez; çünkü üyenin o nesneye özgü olduğu izlenimini verir. Karedeki yorum satırlarında nesne üzerinden yapılan eski çağrı (`kitap1.isbnNedir()`) ve `Kitap.getkitapSayiyi()` görünür.

<!-- BELİRSİZ: Etkin çağrı satırı karede görünmüyor; altyazıda sınıf adıyla yapıldığı söyleniyor, büyük olasılıkla Kitap.isbnNedir(). -->

### 11.2 Kitaplık ve rafların oluşturulması

Kitaplar üç parametreyle (ad, yazar, ISBN) oluşturulur (ekrandan, 00:50:00):

```java
Kitap kitap4 = new Kitap("Kitap4","Yazar4","1237");
Kitap kitap5 = new Kitap("Kitap5","Yazar5","1238");
Kitap kitap6 = new Kitap("Kitap6","Yazar6","1239");

Kitaplık kitaplık = new Kitaplık(5);

kitaplık.kitapEkle(kitap3, 0);
kitaplık.kitapEkle(kitap1, 0);
```

`Kitaplık(5)` beş raflı bir kitaplık ister; constructor'a verilen sayı raf sayısıdır. Constructor önce `new` ile beş elemanlı `Raf` dizisini oluşturur. Bu aşamada her göz `null`'dur. Sonra bir `for` döngüsüyle sıfırıncı gözden başlayarak her göze `new Raf()` atanır. Her `Raf()` çalıştığında 10 elemanlı bir `Kitap` dizisi oluşturur.

Yorum satırı yapılmış bir kısımda `Raf raf1 = new Raf();` ile test sınıfında doğrudan raf oluşturulup `raf1.kitapEkle(kitap1)` gibi çağrılar yapıldığı görülür. Bunun açıklaması (ekrandaki yorum): raf nesnesi bu şekilde de oluşturulabilirdi, ancak tasarım gereği raflar kitaplığın içinde oluşturulur ve rafa kitaplığın metotlarıyla erişilir (bölüm "Örnek Sorular", soru 3).

Tüm rafları gösterince üç kitabın ilk rafa, diğerlerinin sonraki raflara eklendiği, 3. ve 4. rafların boş olduğu görülür. Bir rafta kitap olmayan gözler `null` diye yazdırılır.

### 11.3 KitaplikYonetim ve kartlar

`KitaplikYonetim` nesnesi oluşturulurken constructor'a bir `Kitaplik` nesnesi verilir. Bu sınıf bir dizi değil, tek bir kitaplık tutar; yani bir kitaplık yönetimi bir kitaplığın bilgisini taşır.

Kartlar yazdırılınca `toString` çalışır (ekrandan, 00:55:00):

```text
----- Uyg2 -----
Kart [id=0, Sahip=Ali, Bakiye=50.0]OgrenciKartı [bonus=0.0]
Kart [id=1, Sahip=Ayşe, Bakiye=50.0]
```

Yetişkin kartında `toString` yazılmamıştır; üst sınıfta içi doldurulmuş olduğu için `Kart`'ın `toString`'i kullanılır. Öğrenci kartında ise `toString` override edilmiştir: önce `super.toString()` ile kart sınıfındaki metin alınır, sonra bu sınıfa özgü bonus bilgisi eklenir. `toString` Eclipse'te Source > Generate toString() ile de üretilebilir.

## 12. Kitap satışı: kitapSat ve odemeYap

### 12.1 kitapSat

`kitapSat(kitap, kart)` metodu, bir kitabın bir kart sahibine satılmasını yürütür; örnekte birinci kart öğrenci kartıdır. Akış şöyledir:

```text
kitapSat(kitap, kart):
  rafNo = kitaplik.kitapAra(kitabın adı)
  rafNo == -1 ise: "kitap yok" yaz
  değilse:
    kart.odemeYap(kitabın fiyatı) true ise:
      kitaplik.kitapSil(rafNo, kitap)   -> "Satış Gerçekleşti"
    false ise:
      "bakiye yetersiz" yaz
```

Ekran çıktısında öğrenci kartıyla yapılan işlemlerde "Aranan kitap 0. rafta bulunuyor." ve "Satış Gerçekleşti." satırları görünür (ekrandan, 00:55:00).

### 12.2 kitapAra ve null kontrolü

`kitapAra` metodu artık `int` döndürür: kitap bulunursa bulunduğu rafın numarasını, bulunamazsa -1 döndürür. Raflar ve her rafın kitap dizisi tek tek gezilir; gönderilen kitap adı bulunana kadar bakılır. Kitabın adı `equals` ile karşılaştırılır; eşitse o rafın numarası `return` ile döndürülür.

> **Hocanın vurgusu:** Burada `null` kontrolü yapmak çok önemlidir. Dizideki göz boşken (`null`) o nesnenin bir metodu çağrılırsa `NullPointerException` hatası alınır. Bu yüzden `getAd()` çağrılmadan önce kitabın `null` olmadığı kontrol edilmelidir.

Metodun kodu karelerde görünmüyor. Anlatıma göre yapısı aşağıdakine benzer (ajan tarafından kuruldu, derste bu biçimiyle gösterilmedi):

```java
public int kitapAra(String kitapAdi) {
    for (int i = 0; i < raf.length; i++) {
        Kitap[] kitaplar = raf[i].getKitaplar();
        for (int j = 0; j < kitaplar.length; j++) {
            if (kitaplar[j] != null && kitaplar[j].getAd().equals(kitapAdi)) {
                return i;
            }
        }
    }
    return -1;
}
```

### 12.3 odemeYap metotları

`kitapSat` içinde çağrılan `odemeYap` `Kart` sınıfında soyuttur, gövdesi yoktur; alt sınıflarda doldurulmuştur. Kitabın fiyatı `getFiyat()` ile gönderilir. Bu uygulamada `Kitap` sınıfına önceki sürümde olmayan bir fiyat alanı eklenmiştir ve her kitap 10 liradır.

Yetişkin kartında (kodu bölüm 9.2'de): bakiye fiyattan büyük ya da eşitse `setBakiye(getBakiye() - fiyat)` ile fiyat bakiyeden düşülür ve `true` döner. Metodun `boolean` dönmesinin faydası, `return` ile hem sonucu bildirip hem metottan çıkabilmektir. Bakiye yetmezse `false` döner; `kitapSat` satış yapmaz ve "bakiye yetersiz" yazar.

Öğrenci kartında aynı mantığa bonus eklenir. Anlatıma göre:

- Bakiye fiyattan büyük ya da eşitse fiyat bakiyeden düşülür ve ödenen fiyatın %20'si bonus olarak eklenir. Fiyat 10 lira olduğu için her alışverişte 2 lira bonus kazanılır. `true` döner.
- Bakiye yetmiyor ama bonus fiyata eşit ya da ondan büyükse ödeme bonusla yapılır: fiyat bonustan düşülür, `true` döner.
- İkisi de yetmezse `false` döner; `kitapSat` "bakiye yetersiz" yazar.

> **Ders sonrası not:** Anlatımda bonusla ödeme koşulu bir yerde "bonusum fiyattan azsa veya eşitse" diye söylendi (01:01:35); hemen ardından doğru biçimi, yani bonusun fiyata eşit ya da ondan büyük olması gerektiği anlatıldı. Doğru koşul `bonus >= fiyat`'tır.

Öğrenci kartının `odemeYap` kodu karelerde görünmüyor. Anlatıma göre kurulan sürüm (ajan tarafından kuruldu):

```java
@Override
public boolean odemeYap(double fiyat) {
    if (getBakiye() >= fiyat) {
        setBakiye(getBakiye() - fiyat);
        bonus += fiyat * 0.2;
        return true;
    } else if (bonus >= fiyat) {
        bonus -= fiyat;
        return true;
    }
    return false;
}
```

Ajan, `Kart`, `YetiskinKarti` ve bu `OgrenciKarti` sürümünü tek dosyada `java TestKart.java` ile çalıştırdı. 50 lira bakiyeli öğrenci kartıyla 10 liralık altı alışverişte ilk beşi bakiyeden ödenip bonus 2, 4, 6, 8, 10 liraya çıktı; altıncı alışveriş biriken 10 lira bonusla ödendi. Aynı bakiyeli yetişkin kartında altıncı alışveriş `false` döndü.

Ödeme `true` dönünce `kitapSat`, `Kitaplik` sınıfındaki `kitapSil` metodunu çağırır. Kitabın hangi rafta olduğu `kitapAra` ile zaten bilindiği için kitap o raftan silinir ve satış tamamlanır. Diğer metotlar getter ve setter'lardır.

Oturumun sonunda bu uygulamanın tekrar tekrar incelenmesi önerilir: metotlar ilk bakışta karışık gelebilir, ama hangi metodun nereden nereye gittiği izlendikçe yapı yerine oturur.

## Örnek Sorular

**1.** (derste sözlü, 00:08:15) `Raf` sınıfının nesneleri `Kitap` tipinde bir dizi tutuyor; bir raf nesnesinin içinde birçok kitap var. Bu iki sınıf arasındaki ilişkiye ne denir?

> **Cevap (derste verildi):** Sahip olma ilişkisi (has-a). Bütün-parça biçiminde composition ya da aggregation olabilir.

**2.** (derste sözlü, 00:10:43) UML'de bir üyenin başında `+`, `-` ve `#` görülünce ne anlaşılır?

> **Cevap (derste verildi):** `+` public (her sınıftan erişilir), `-` private (yalnız kendi sınıfından erişilir), `#` protected (kendi sınıfı, alt sınıfları ve aynı paketteki sınıflar erişir).

**3.** (derste sözlü, 00:49:30) Kitaplık uygulamasında raflar kitaplığın içinde oluşturuluyor. Test sınıfından doğrudan `new Raf()` ile raf oluşturup rafa erişilebilir mi?

> **Cevap (derste verildi):** Evet, çünkü `Raf` sınıfının constructor'ı public'tir; public constructor'ı olan bir sınıftan her yerden nesne üretilebilir. Ancak tasarım gereği raflar kitaplığa doğrudan bağlı olsun diye kitaplık oluşturulurken içeride oluşturulur ve rafa kitaplığın metotlarıyla erişilir.

**4.** (ekrandan, 00:35:00) `Ders("İş Sağlığı", 75, 95)`, `ZorunluDers("BBG", 80, 90, 100)` ve henüz `hesaplaNot`'u override etmemiş `SecmeliDers("Mobil Prog.", 50, 60, 70, 80)` nesneleri için `hesaplaNot()` sonuçları nedir?

> **Cevap (ekranda verildi):** 87.0, 91.0 ve 62.0. Seçmeli ders override etmediği için üst sınıfın `vize1*0.4 + finalNot*0.6` formülü çalışır: $50 \cdot 0.4 + 70 \cdot 0.6 = 62.0$. Ayrıntı bölüm 7.3'tedir.

## Dersin Toparlaması

Bu oturumda kalıtımın temel araçları bir not hesaplama örneğiyle kodlandı. Kalıtımın sahip olma ilişkisinden farklı olarak bir "budur" ilişkisi olduğu, UML'de içi boş üçgen uçlu okla gösterildiği ve `protected` belirtecinin alt sınıflara ve aynı paketteki sınıflara erişim verdiği görüldü. Alt sınıfın `extends` ile tanımlandığı, constructor'ının `super(...)` ile üst sınıfın constructor'ını çağırıp yalnız kendi alanlarını eklediği gösterildi. Override ile metodun alt sınıfta yeniden doldurulduğu, override edilmeyen metodun üst sınıftan çalıştığı ve `super` ile hem üst sınıf metodunun hem aynı adlı üst sınıf alanının kullanılabildiği test çıktılarıyla izlendi.

Kitaplık uygulamasının ikinci sürümünde soyut sınıf ve soyut metot tanıtıldı: gövdesiz `odemeYap` metodu, `Kart`'tan türeyen yetişkin ve öğrenci kartlarını bu metodu kendi kurallarıyla doldurmaya zorlar ve `Kart`'tan doğrudan nesne üretilemez. Satış akışı `kitapAra`, `odemeYap` ve `kitapSil` metotlarının birlikte çalışmasıyla izlendi. Ayrıca override ile overload arasındaki fark ve statik üyelerin sınıf adıyla çağrılması hatırlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
