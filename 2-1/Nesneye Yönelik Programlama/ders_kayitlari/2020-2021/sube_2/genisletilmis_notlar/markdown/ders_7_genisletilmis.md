# Ders 7 Genişletilmiş Notu: Lab 1: Müşteri, Sipariş ve Ürün Sınıflarıyla UML Uygulaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun niteliği
- 2. Lab sorusunun sistemi ve UML diyagramı
- 3. Sorunun kuralları
- 4. Hazır verilen test sınıfı
- 5. Asistanın açıklamaları ve soru-cevaplar
- 6. Örnek çözüm (derste verilmedi)
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun niteliği

Bu kayıt konu anlatımı içeren bir ders değil, bir laboratuvar uygulamasıdır. Asistan lab sorusunu öğrencilerle paylaşır, UML sınıf diyagramını ve sorunun maddelerini kısaca açıklar, birkaç soruyu cevaplar ve ardından oturumdan çıkar. Kaydın büyük kısmında (yaklaşık 00:11:46 ile 00:19:37 arası) konuşma yoktur.

Asistanın ilk söylediği şey, sorunun bir önceki uygulamaya çok benzediğidir. O uygulamada bir kitaplık, raflar ve kitaplardan oluşan üç sınıflı bir sistem kodlanmıştı. Bu labda da birbiriyle ilişkili üç sınıf vardır; aralarındaki ilişkiler aynıdır ve metotlar yine aynı mantıkta ekleme ve çıkarma işlemleridir. Önceki uygulamayı iyi çalışan biri için sorunun rahat çözüleceğini belirtir.

## 2. Lab sorusunun sistemi ve UML diyagramı

Sistem, bir marketin çevrim içi alışveriş sitesi gibi düşünülür. Müşteriler sipariş verir ve her siparişte ürünler vardır. Yani bir müşterinin altında siparişler, o siparişlerin içinde de ürünler bulunur.

Soru belgesindeki UML sınıf diyagramı şöyledir (ekrandan, 00:15:00):

```text
Musteri  <>(dolu)------  Siparis  <>(boş)------  Urun

+-------------------------------------------+
| Musteri                                   |
+-------------------------------------------+
| - ad: String                              |
| - soyad: String                           |
| - siparisler: Siparis []                  |
+-------------------------------------------+
| + Musteri(String ad, String soyad)        |
| + siparisVer(int siparisNo, Urun urun)    |
| + siparisBilgisi(int siparisNo)           |
| + tumSiparisler()                         |
| + kacSiparis(String urunAdi)              |
| + tumSiparislerdenUrunCikar(Urun urun)    |
| + urunCikar(int siparisNo, Urun urun)     |
| + getSiparisTutari(int siparisNo): double |
+-------------------------------------------+

+----------------------------+
| Siparis                    |
+----------------------------+
| - urunler: Urun []         |
+----------------------------+
| + Siparis()                |
| + getUrunler(): Urun []    |
| + urunEkle(Urun urun)      |
| + urunleriGoster()         |
| + urunCikar(Urun urun)     |
| + getToplamTutar(): double |
+----------------------------+

+-------------------------------------------+
| Urun                                      |
+-------------------------------------------+
| - ID                                      |
| - ad                                      |
| - fiyat                                   |
| - zamSayisi <static>                      |
+-------------------------------------------+
| + Urun(int ID, String ad, double fiyat)   |
| + getAd(): String                         |
| + getID(): int                            |
| + getFiyat(): double                      |
| + setAd(String ad)                        |
| + zamYap(double zamOrani)                 |
| + getZamSayisi(): int                     |
| + toString(): String                      |
+-------------------------------------------+
```

`Musteri` ile `Siparis` arasındaki çizginin `Musteri` ucunda içi dolu elmas, `Siparis` ile `Urun` arasındaki çizginin `Siparis` ucunda içi boş elmas vardır. Önceki uygulamada anlatılan gösterime göre içi dolu elmas güçlü ilişkidir (composition): siparişler müşteriye sıkıca bağlıdır. İçi boş elmas zayıf ilişkidir (aggregation): ürünler ayrı oluşturulur ve siparişten bağımsız yaşar. Niteliklerin başındaki `-` private, metotların başındaki `+` public anlamına gelir.

## 3. Sorunun kuralları

Soru belgesinde diyagramın altında şu maddeler yer alır (ekrandan, 00:15:00):

- Verilen soruda her bir müşteri için siparişler, her bir sipariş için ürünler bulunmaktadır.
- Her bir müşteri için 3 sipariş olmalı ve her sipariş için 5 ürün tutulmalıdır.
- `siparisBilgisi` metodu, verilen sipariş numarasına ait ürünlerin bilgilerini yazdırmalıdır.
- `tumSiparisler` metodu ile müşteriye ait tüm siparişlerin içerdiği ürün bilgileri sırasıyla yazdırılmalıdır.
- `kacSiparis` metodu ile String olarak verilen ürün adının kaç siparişte, toplam kaç kere sipariş edildiği bilgisi yazdırılmalıdır. Bu ürün tüm siparişlerde verilmemiştir ve bir siparişte birden fazla kez verilmiş olabilir, dikkat ediniz.
- `urunCikar` metodu verilen sipariş numarasından ilgili ürünü çıkarırken, `tumSiparislerdenUrunCikar` metodu ise verilen tüm siparişlerden bu ürünü çıkarmalıdır.
- `getSiparisTutari` metodu ile verilen sipariş numarasındaki ürünlerin fiyatları toplanmalı ve double değer olarak döndürülmelidir.
- `zamSayisi` değeri, sadece bir ürün için değil, tüm ürünler için toplamda kaç kez zam yapıldığının bilgisini tutmaktadır.
- `toString` metodu `Urun` sınıfı için override edilmeli ve ürün bilgilerini içeren String değer döndürmelidir.

### 3.1 Sabit boyutlu diziler

Asistan bu labın önceki uygulamadan farkını özellikle belirtir. Kitaplık örneğinde rafta kaç kitap olacağı ya da kaç raf olacağı bir sayı verilerek constructor'da üretiliyordu. Burada ise boyutlar en baştan sabittir: her müşteri için 3 sipariş, her siparişte 5 ürün. Bu yüzden constructor'ın bu sayılar için parametre almasına gerek yoktur; dizilerin içeride nasıl tanımlanacağı önceki uygulamadan bilinmektedir.

## 4. Hazır verilen test sınıfı

Öğrenciler üç sınıfı (`Musteri`, `Siparis`, `Urun`) yazar; `main` metodunu içeren test sınıfı hazır verilir. Ekranda görünen kısmı şöyledir (ekrandan, 00:10:00):

```java
public class Test {

    public static void main(String[] args) {

        Urun urun1 = new Urun(91,"ekmek",1.25);
        Urun urun2 = new Urun(92,"su",4.5);
        Urun urun3 = new Urun(93,"makarna",2.15);
        Urun urun4 = new Urun(94,"çikolata",1);
        Urun urun5 = new Urun(95,"meşrubat",2.75);

        Musteri musteri = new Musteri("Ali","Yılmaz");

        musteri.siparisVer(0,urun2);
        musteri.siparisVer(0,urun4);
        musteri.siparisBilgisi(0);
        System.out.println("----------------------");
        musteri.siparisVer(1,urun2);
        musteri.siparisVer(1,urun2);
        musteri.siparisVer(1, urun1);
        musteri.siparisVer(2,urun3);
        musteri.siparisVer(2, urun5);
        musteri.tumSiparisler();
        System.out.println("----------------------");
        musteri.kacSiparis("su");
        System.out.println("----------------------");
        urun3.zamYap(0.05);
        urun5.zamYap(0.1);
        System.out.printf("Toplam %d defa zam yapıldı.\n", Urun.getZamSayisi());
        System.out.println("----------------------");
        musteri.urunCikar(0,urun4);
        musteri.tumSiparisler();
        // ... (devamı karede görünmüyor)
    }
}
```

<!-- BELİRSİZ: Test sınıfının bu satırlardan sonraki kısmı karede görünmüyor; büyük olasılıkla tumSiparislerdenUrunCikar ve getSiparisTutari çağrıları da vardır. -->

Asistan, istenen çıktıların soru PDF'inin ikinci ve üçüncü sayfalarında verildiğini söyler. Yazılan metotların doğruluğu, test sınıfı çalıştırılıp çıktının bu sayfalarla karşılaştırılmasıyla kontrol edilir. <!-- BELİRSİZ: Beklenen çıktı sayfaları karelerde yalnız küçük önizleme olarak görünüyor, okunmuyor. -->

## 5. Asistanın açıklamaları ve soru-cevaplar

### 5.1 Metotların okunuşu

Asistan metot adlarının açıklayıcı olduğunu belirtir. Örneğin `siparisVer` metoduna bir sipariş numarası ve bir ürün verilir; bu ürün o sipariş numarasındaki siparişe kaydedilir. Sistem bu şekilde, metot metot gerçeklenir.

### 5.2 Test sınıfının adı

**Soru:** Hazır verilen test dosyasının adı değiştirilebilir mi, örneğin `Main` yapılabilir mi?

**Cevap:** Evet. Sınıfın adı önemli değildir; içeriği aynen kopyalanabilir. Önemli olan `main` metodu çalıştırıldığında istenen çıktıların üretilmesidir.

### 5.3 zamSayisi neyi tutar

**Soru:** Zam sayısı tam olarak neyi tutacak?

**Cevap:** Kaç kez zam yapıldığının bilgisini tutar. Bunun için bir metot (`zamYap`) vardır; o metot her çalıştığında bu değer artırılır. Sorunun maddesine göre bu sayaç tek bir ürüne değil bütün ürünlere aittir, bu yüzden UML'de `<static>` olarak işaretlenmiştir.

### 5.4 Ürün niteliklerinin tipleri

**Soru:** `Urun` sınıfının niteliklerinin tipleri diyagramda verilmemiş; hangi tipte olacaklar?

**Cevap:** Test sınıfına bakılarak çıkarılabilir. Ürünler `new Urun(91, "ekmek", 1.25)` biçiminde oluşturulmuştur: `ID` `int`, ürün adı `String`, fiyat `double` olur. Bu tipler diyagramdaki `Urun(int ID, String ad, double fiyat)` constructor imzasıyla da uyumludur.

### 5.5 zamYap bir değer döndürecek mi

**Soru:** `zamYap` metodu bir şey döndürecek mi, yoksa yalnız zam sayısını mı artıracak?

**Cevap:** Burada kurulması istenen bağlantı, test metodunda çağrılan `getZamSayisi` ile ilgilidir. Asıl amaç kaç kere zam yapıldığını görmektir; `zamYap` çalıştıkça bu sayaç üzerinde bir işlem olur. Diyagramda `zamYap(double zamOrani)` için dönüş tipi yazılmamıştır.

> **Ek bilgi (derste anlatılmadı):** Metodun adı ve `zamOrani` parametresi, büyük olasılıkla ürünün fiyatının bu oranda artırılmasını da ifade eder (örneğin `0.05` için yüzde 5). Asistan yalnız sayacın artırılmasından söz etmiştir; aşağıdaki örnek çözümde fiyat da `fiyat * (1 + zamOrani)` ile güncellenmiştir.

### 5.6 En zor metot: kacSiparis

> **Hocanın vurgusu:** En çok zorlanılabilecek metot `kacSiparis`'tir; en sona bırakılıp üzerinde uzun uzun düşünülebilir. Ürün bütün siparişlerde olmayabilir; kaç siparişte geçtiği ve toplam kaç kere sipariş edildiği ayrı ayrı bulunmalıdır. Diğer metotların rahatça yapılacağı düşünülmektedir.

Test sınıfındaki siparişlerle "su" ürünü 0 numaralı siparişte bir kez, 1 numaralı siparişte iki kez geçer, 2 numaralı siparişte hiç geçmez. Dolayısıyla `kacSiparis("su")` için doğru sonuç 2 sipariş ve toplam 3 kezdir.

## 6. Örnek çözüm (derste verilmedi)

Derste çözüm verilmemiştir. Aşağıdaki kod ajan tarafından yazılmış, ekrandaki test girdileriyle tek dosyada `java Test.java` komutuyla (Java tek dosya çalıştırıcısı) çalıştırılmıştır. Test sınıfının görünen kısmından sonra eklenen iki çağrı (`tumSiparislerdenUrunCikar` ve `getSiparisTutari`) ajanın denemesidir. Çıktı biçimi soru belgesindeki beklenen çıktılarla birebir aynı olmayabilir, çünkü o sayfalar okunamamıştır.

Çözümdeki tasarım kararları:

- `Musteri` constructor'ı `new Siparis[3]` dizisini oluşturur ve her elemana `new Siparis()` atar (composition).
- `Siparis` constructor'ı `new Urun[5]` dizisini oluşturur. `urunEkle` ilk boş (`null`) göze ürünü koyar.
- `urunCikar`, verilen ürün nesnesinin siparişteki bütün geçişlerini `null` yapar (ajanın seçimi; soru metni tek geçiş mi bütün geçişler mi açık söylemiyor).
- Test sınıfı `Urun.getZamSayisi()` diye sınıf adıyla çağırdığı için `getZamSayisi` static yazılmıştır; diyagramda yalnız nitelik `<static>` işaretlidir.

```java
class Urun {
    private int ID;
    private String ad;
    private double fiyat;
    private static int zamSayisi = 0;

    public Urun(int ID, String ad, double fiyat) {
        this.ID = ID;
        this.ad = ad;
        this.fiyat = fiyat;
    }
    public String getAd() { return ad; }
    public int getID() { return ID; }
    public double getFiyat() { return fiyat; }
    public void setAd(String ad) { this.ad = ad; }
    public void zamYap(double zamOrani) {
        fiyat = fiyat * (1 + zamOrani);
        zamSayisi++;
    }
    public static int getZamSayisi() { return zamSayisi; }
    @Override
    public String toString() {
        return "Urun [ID=" + ID + ", ad=" + ad + ", fiyat=" + fiyat + "]";
    }
}

class Siparis {
    private Urun[] urunler;

    public Siparis() { urunler = new Urun[5]; }
    public Urun[] getUrunler() { return urunler; }
    public void urunEkle(Urun urun) {
        for (int i = 0; i < urunler.length; i++) {
            if (urunler[i] == null) { urunler[i] = urun; return; }
        }
        System.out.println("Sipariş dolu, ürün eklenemedi.");
    }
    public void urunleriGoster() {
        for (Urun u : urunler) {
            if (u != null) System.out.println(u);
        }
    }
    public void urunCikar(Urun urun) {
        for (int i = 0; i < urunler.length; i++) {
            if (urunler[i] == urun) urunler[i] = null;
        }
    }
    public double getToplamTutar() {
        double toplam = 0;
        for (Urun u : urunler) {
            if (u != null) toplam += u.getFiyat();
        }
        return toplam;
    }
}

class Musteri {
    private String ad;
    private String soyad;
    private Siparis[] siparisler;

    public Musteri(String ad, String soyad) {
        this.ad = ad;
        this.soyad = soyad;
        siparisler = new Siparis[3];
        for (int i = 0; i < siparisler.length; i++) {
            siparisler[i] = new Siparis();
        }
    }
    public void siparisVer(int siparisNo, Urun urun) {
        siparisler[siparisNo].urunEkle(urun);
    }
    public void siparisBilgisi(int siparisNo) {
        System.out.println(siparisNo + " numaralı sipariş:");
        siparisler[siparisNo].urunleriGoster();
    }
    public void tumSiparisler() {
        for (int i = 0; i < siparisler.length; i++) siparisBilgisi(i);
    }
    public void kacSiparis(String urunAdi) {
        int siparisSayisi = 0, toplam = 0;
        for (Siparis s : siparisler) {
            int bu = 0;
            for (Urun u : s.getUrunler()) {
                if (u != null && u.getAd().equals(urunAdi)) bu++;
            }
            if (bu > 0) siparisSayisi++;
            toplam += bu;
        }
        System.out.println(urunAdi + " " + siparisSayisi + " siparişte, toplam "
                + toplam + " kez sipariş edildi.");
    }
    public void tumSiparislerdenUrunCikar(Urun urun) {
        for (Siparis s : siparisler) s.urunCikar(urun);
    }
    public void urunCikar(int siparisNo, Urun urun) {
        siparisler[siparisNo].urunCikar(urun);
    }
    public double getSiparisTutari(int siparisNo) {
        return siparisler[siparisNo].getToplamTutar();
    }
}
```

Test sınıfının görünen kısmı ve ajanın eklediği iki satırla (`musteri.tumSiparislerdenUrunCikar(urun2); musteri.tumSiparisler();` ve sipariş 2 tutarının yazdırılması) alınan çıktı:

```text
0 numaralı sipariş:
Urun [ID=92, ad=su, fiyat=4.5]
Urun [ID=94, ad=çikolata, fiyat=1.0]
----------------------
0 numaralı sipariş:
Urun [ID=92, ad=su, fiyat=4.5]
Urun [ID=94, ad=çikolata, fiyat=1.0]
1 numaralı sipariş:
Urun [ID=92, ad=su, fiyat=4.5]
Urun [ID=92, ad=su, fiyat=4.5]
Urun [ID=91, ad=ekmek, fiyat=1.25]
2 numaralı sipariş:
Urun [ID=93, ad=makarna, fiyat=2.15]
Urun [ID=95, ad=meşrubat, fiyat=2.75]
----------------------
su 2 siparişte, toplam 3 kez sipariş edildi.
----------------------
Toplam 2 defa zam yapıldı.
----------------------
0 numaralı sipariş:
Urun [ID=92, ad=su, fiyat=4.5]
1 numaralı sipariş:
Urun [ID=92, ad=su, fiyat=4.5]
Urun [ID=92, ad=su, fiyat=4.5]
Urun [ID=91, ad=ekmek, fiyat=1.25]
2 numaralı sipariş:
Urun [ID=93, ad=makarna, fiyat=2.2575]
Urun [ID=95, ad=meşrubat, fiyat=3.0250000000000004]
----------------------
0 numaralı sipariş:
1 numaralı sipariş:
Urun [ID=91, ad=ekmek, fiyat=1.25]
2 numaralı sipariş:
Urun [ID=93, ad=makarna, fiyat=2.2575]
Urun [ID=95, ad=meşrubat, fiyat=3.0250000000000004]
Sipariş 2 tutarı: 5.2825
```

Çıktıdaki noktalar:

- `kacSiparis("su")` sonucu 2 sipariş ve toplam 3 kezdir; 5.6'daki el hesabıyla aynıdır.
- İki `zamYap` çağrısından sonra static sayaç 2 olur.
- Zamlı fiyatlar: makarna $2.15 \times 1.05 = 2.2575$, meşrubat $2.75 \times 1.10 = 3.025$. Çıktıdaki `3.0250000000000004`, `double` tipinin kayan nokta gösterimindeki yuvarlama hatasıdır.
- `urunCikar(0, urun4)` sonrası 0 numaralı siparişte yalnız su kalır. Su bütün siparişlerden çıkarılınca 0 numaralı sipariş boşalır, 1 numaralı siparişte yalnız ekmek kalır.
- 2 numaralı siparişin tutarı $2.2575 + 3.025 = 5.2825$ olur.

## Örnek Sorular

### Soru 1 (ekrandan, 00:15:00)

Verilen UML diyagramına göre `Musteri`, `Siparis` ve `Urun` sınıflarını Java'da yazınız. Her müşteri için 3 sipariş, her sipariş için 5 ürün tutulmalıdır. `siparisBilgisi`, `tumSiparisler`, `kacSiparis`, `urunCikar`, `tumSiparislerdenUrunCikar`, `getSiparisTutari` metotlarını ve `Urun` için static `zamSayisi` sayacını ve override edilmiş `toString` metodunu Bölüm 3'teki kurallara göre gerçekleyiniz; hazır verilen test sınıfı istenen çıktıları üretmelidir.

> **Çözüm (derste verilmedi):** Bölüm 6'daki kod ve çıktı. Kod ekrandaki test girdileriyle `java Test.java` ile çalıştırılmıştır.

### Soru 2 (derste sözlü, 00:21:12)

Test sınıfındaki siparişlerden sonra `kacSiparis("su")` ne yazdırmalıdır?

> **Çözüm (derste verilmedi):** "su" 0 numaralı siparişte bir kez, 1 numaralı siparişte iki kez geçer, 2 numaralı siparişte yoktur. Sonuç: 2 siparişte, toplam 3 kez. Bölüm 6'daki çözüm de bu değeri üretir.

## Dersin Toparlaması

Bu oturum, önceki uygulamada kitaplık örneğiyle gösterilen sınıf, nesne dizisi, composition/aggregation ilişkileri, kapsülleme, static nitelik ve `toString` override kavramlarının bir lab sorusunda uygulanmasıdır. Müşteri-sipariş-ürün sistemi kitaplık-raf-kitap yapısının karşılığıdır; fark, dizi boyutlarının sabit olması ve `kacSiparis` gibi iki ayrı sayaç gerektiren bir sayma metodunun bulunmasıdır. Asistanın verdiği ipuçları, eksik tiplerin test sınıfından çıkarılması, static zam sayacının bütün ürünler için ortak olması ve `kacSiparis`'in en sona bırakılmasıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
