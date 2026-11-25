# Ders 5 Çalışma Özeti

## Genel Konular

- UML sınıf diyagramının okunması (Kitaplık uygulaması)
  - Ekranda Violet UML Editor ile çizilmiş dört sınıflık bir diyagram vardır: `Test`, `Kitaplik`, `Raf`, `Kitap` (ekrandan, 00:05:00).
  - Her sınıf kutusu üç bölmedir: sınıfın adı, nitelikleri (attributes), metotları (fonksiyonları).
  - `+` public, `-` private demektir. Nitelikte `ad : tür`, metotta `ad(parametre türleri) : dönüş türü` biçimi kullanılır. Örneğin `+main(String[ ]): void` tek parametre alan (bir `String` dizisi), değer döndürmeyen, public bir metottur.
  - `kitapSayisi: <static> int` gibi bir işaret niteliğin static olduğunu gösterir. Nitelik sabit (final) olsaydı bu da yanına yazılabilirdi.
  - Sınıfla aynı adı taşıyan ve dönüş türü olmayan metot yapıcı fonksiyondur (constructor): `+ Kitap(String,String,String)`, `+ Kitaplik(int)`, `+ Raf()`.
  - Dönüş türü yalnız `int` ya da `void` olmak zorunda değildir; bir sınıf türü ya da dizi de olabilir: `kitapAra(String):Kitap`, `getKitaplar(): Kitap[ ]`.
- Diyagramdaki bağlantı türleri
  - İçi dolu elmas (Kitaplik — Raf): composition, güçlü bağlantı. Kitaplık silinirse rafları da gider.
  - İçi boş elmas (Raf — Kitap): aggregation, zayıf bağlantı. Raf silinse de kitaplar nesne olarak var olmaya devam eder.
  - Kesikli oklar (Test → Kitaplik, Test → Kitap): bağımlılık. `Test` sınıfı bu sınıfları yalnız kullanır, onlara sahip değildir.
- Nesne yönelimli programlamanın dört temel kavramı
  - Sınıf (class), nesne (object), nitelik ve fonksiyon (metot).
  - Sınıf bir şablondur: "kitabın adı, yazarı, ISBN'i olur; adı getirilebilir, değiştirilebilir" der, ama ortada henüz kitap yoktur.
  - Nesne bu şablondan oluşturulan somut örnektir; tek şablondan bir, on ya da bin kitap üretilebilir.
  - Nitelikler nesnenin özelliklerini, metotlar nesnenin neler yapabileceğini ifade eder.
- Diyagramın Java kodu (Eclipse, `uyg1.pkg2` paketi)
  - Program `public static void main(String[] args)` içinden başlar.
  - `Kitap.isbnNedir()` static olduğu için nesne oluşturmadan sınıf adıyla çağrılır. Koddaki yorum: static olmayan `getAd()` bu şekilde çağrılamaz (ekrandan, 00:20:00).
  - `new Kitap("Dönüşüm","Kafka","1234")` ile yapıcı çağrılır, parametreler niteliklere atanır ve static `kitapSayısı` bir artırılır.
  - `setAd` içinde `this.Ad = Ad;` yazılır: yalın `Ad` en yakın kapsamdaki parametreyi, `this.Ad` nesnenin niteliğini gösterir.
  - `toString()` override edilerek nesnenin ekrana nasıl yazılacağı belirlenir.
  - `Kitaplık(5)` beş raflı bir kitaplık kurar; her raf on kitaplık bir `Kitap[]` dizisi tutar. Kitap ekleme, arama, nesneyle silme ve sıra numarasıyla silme metotları adım adım izlendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Static ile public farklı kavramlardır
  - `public`/`private` erişimi belirler: public bir üyeye başka sınıftan nokta ile erişilir, private üyeye yalnız kendi sınıfının içinden erişilir. `kitap1.` yazınca private `Ad` listede çıkmaz.
  - `static` üyenin nesneye değil sınıfa ait olduğunu belirtir; nesne oluşturmadan `Kitap.getKitapSayısı()` gibi sınıf adıyla çağrılabilir.
  - Static bir metot içinde kullanılan nitelik de static olmalıdır. `kitapSayısı`'ndan `static` kaldırılınca Eclipse hata verdi ve "change ... to static" önerdi (00:50:06).
- Static metoda nesne üzerinden erişmek mümkündür ama uyarı verir
  - `kitap1.isbnNedir()` çalışır, Eclipse uyarı işareti koyar; yalnız gösterim amacıyla yazıldı.
- `System.out.println` nesneyi yazarken gizlice `toString()` çağırır
  - Override edilmemişse çıktı `paket.SınıfAdı@adres` biçimindedir: `uyg1.pkg2.Kitaplık@34c45dca` (ekrandan, 00:30:00). `@` sonrası nesnenin adresini gösterir.
  - `Kitap` sınıfında override edilmiş `toString()` ise `Kitap{Ad=Dönüşüm 2. Baskı, Yazar=Kafka, ISBN=1234}` yazar.
- Composition ile aggregation'ın koddaki karşılığı
  - `Kitaplık` yapıcısı rafları `new Raf()` ile kendi içinde oluşturur; bu yüzden kitaplık giderse raflar da gider (composition).
  - `Raf` yapıcısı yalnız boş bir `Kitap[10]` dizisi oluşturur. Kitaplar `main` içinde ayrıca oluşturulup rafa konur; raf silinse de kitaplar durur (aggregation).
- Raftan "silmek" kitabı yok etmek değildir
  - `kitaplar[i] = null` kitabı yalnız raftan kaldırır; kitap nesnesi başka referanslarla yaşamaya devam eder.

## Kısa Tekrar Notları

- UML sınıf kutusu: ad / nitelikler / metotlar. `+` public, `-` private.
- Dolu elmas composition (güçlü), boş elmas aggregation (zayıf), kesikli ok bağımlılık.
- Sınıf şablondur, nesne o şablondan `new` ile oluşturulan örnektir.
- Yapıcı: sınıfla aynı adlı, dönüş türü olmayan metot.
- `this.x` nesnenin niteliği, yalın `x` en yakın kapsamdaki değişkendir.
- Static üye sınıfa aittir, sınıf adıyla çağrılır; static metot yalnız static niteliklere doğrudan erişebilir.
- Static `int` nitelik varsayılan olarak 0, `String` nitelik `null` ile başlar.
- `println(nesne)` otomatik olarak `toString()` çağırır; override edilmezse `SınıfAdı@adres` yazılır.
- Nesne dizisi oluşturmak (`new Raf[n]`) nesneleri oluşturmaz; her eleman `null`'dır, elemanlara ayrıca `new Raf()` atanmalıdır.
- Uygulama sonunda `Kitap.getKitapSayısı()` 6 döndürdü: raftan kaldırılan kitaplar sayacı azaltmaz.

## Detaylı Açıklamalar

- Diyagramın içeriği (ekrandan, 00:05:00)

  ```text
  Test        : +main(String[ ]): void
  Kitaplik    : -raf: Raf[ ]
                + Kitaplik(int), + kitapEkle(Kitap,int):void,
                + kitapSilSiraNo(int,int):void, + kitapSil(int,Kitap):void,
                + kitapAra(String):Kitap, + gosterRaf(int):void,
                + tumRaflariGoster():void
  Raf         : - kitaplar: Kitap[ ]
                + Raf(), + KitapEkle(Kitap):void, + kitapSilSiraNo(int),
                + kitapSil(Kitap), + RafGoster():void, + getKitaplar(): Kitap[ ]
  Kitap       : - ad: String, - yazar: String, - ISBN: String,
                - kitapSayisi: <static> int
                + Kitap(String,String,String), + getAd(): String,
                + getYazar(): String, + getISBN(): String,
                + getKitapSayisi(): int, + setAd(String): void,
                + setYazar(String): void, + toString(): void
  Bağlantılar : Kitaplik ◆—— Raf (dolu elmas Kitaplik tarafında)
                Raf ◇—— Kitap (boş elmas Raf tarafında)
                Test - - -> Kitaplik, Test - - -> Kitap (kesikli ok)
  ```

  - Ders sonrası not: diyagramda `toString(): void` yazıyor, ama koddaki `toString()` bir `String` döndürür (Eclipse Outline'da `toString() : String`, ekrandan 00:50:00). Doğrusu `+ toString(): String`'dir.
- Kitaplık sınıfının kodu (ekrandan, 00:55:00)

  ```java
  public class Kitaplık {
      private Raf[] raf;

      public Kitaplık(int n) {
          this.raf = new Raf[n];
          for (int i = 0; i < n; i++){
              raf[i] = new Raf();
          }
      }

      public void kitapEkle(Kitap kitap, int rafNo)
      {
          raf[rafNo].kitapEkle(kitap);
      }

      public void kitapSilSıraNo(int rafNo, int n)
      {
          raf[rafNo].kitapSilSıraNo(n);
      }

      public void kitapSil(int rafNo, Kitap k)
      {
          raf[rafNo].kitapSil(k);
      }

      public void rafGoster(int n){
          raf[n].rafGoster();
      }
      // tumRaflariGoster() ve kitapAra(String) sonraki satırlarda
  }
  ```

  - `new Raf[n]` yalnız `n` elemanlı bir referans dizisi ayırır; her eleman `null`'dır. Döngü her elemana yeni bir `Raf` nesnesi atar.
- Raf sınıfında silme metotları (ekrandan, 00:45:00)

  ```java
  public void kitapSilSıraNo(int n) {
      if (n < kitaplar.length)
          kitaplar[n] = null;
  }

  public void kitapSil(Kitap k) {
      int i = 0;
      while(i < kitaplar.length && kitaplar[i] != k)
      {
          i++;
      }
      if (i < kitaplar.length)
      {
          kitaplar[i] = null;
      }
  }
  ```

  - `kitapSil` aranan kitabı bulana kadar ilerler. Bulunduğunda `kitaplar[i] != k` yanlış olur, döngü durur; `i` dizi boyundan küçük kaldığı için o göz `null` yapılır.
  - Anlatıma göre `Raf()` yapıcısı `kitaplar = new Kitap[10]` oluşturur, `kitapEkle` de ilk boş (`null`) gözü bulup kitabı oraya koyar. Bu kısımların kodu karelerde görünmüyor. <!-- BELİRSİZ: Raf yapıcısı ve kitapEkle gövdesi karede yok, anlatımdan aktarıldı -->
- Main akışı ve çıktıları
  - Kitaplar: `kitap1 ("Dönüşüm","Kafka","1234")`, `kitap2 ("Söylevler","Epiktetos","1235")`, `kitap3 ("Introduction to Algorithms","Ron Rivest","1236")`, `kitap4 ("Clean Code","Robert C. Martin","1237")`, `kitap5 ("The Pragmatic Programmer","Andy Hunt","1238")`, `kitap6 ("Designing Data-Intensive Applications","Martin Kleppmann","1239")` (ekrandan, 00:20:00).
  - Raflar: kitap1-3 rafa 0, kitap4-5 rafa 1, kitap6 rafa 2 (ekrandan, 00:40:00).
  - `rafGoster(0)` üç kitabı ve yedi `null` yazar. `kitapAra("Clean Code")` "Kitap 1. Rafta var." yazıp `kitap4`'ü döndürür. `kitapSil(1, kitap4)` sonrasında aynı arama "Kitap yok." yazar ve `null` döndürür. Sıra numarasıyla 0. raftaki 0. kitap silinince `rafGoster(0)` ilk satırda `null` gösterir. Son satırda `Kitap.getKitapSayısı()` 6 yazar (ekrandan, 00:45:00 ve 00:50:00).
  - Ajan bu akışı, karede görünen kodu ve anlatılan eksik gövdeleri birleştirip tek dosyalık bir Java programı olarak `java` ile çalıştırdı; çıktı ekrandaki konsol çıktısıyla aynı çıktı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
