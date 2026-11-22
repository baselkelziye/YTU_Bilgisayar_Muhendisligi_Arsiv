# Ders 5 Çalışma Özeti

## Genel Konular

- Uygulama dersinin amacı ve örnek problem
  - Bu kayıt bir uygulama (lab hazırlık) oturumudur. Java'nın temel kavramları sıfırdan, tek bir örnek üzerinden kodlanarak gösterilir.
  - Örnek sistem bir kitaplıktır: kitaplığın istenen sayıda rafı vardır, her rafa kitap eklenir, raftan kitap silinir, kitap aranır ve raflar listelenir.
  - Kodlama Eclipse'te yapılır: önce Java projesi, sonra sınıflar oluşturulur. Paket adı verilmediği için sınıflar varsayılan pakete (default package) düşer.
- UML sınıf diyagramı (ekrandan, 00:20:00)
  - Her sınıf kutusu üç bölümdür: en üstte sınıf adı, ortada nitelikler (attribute, field, instance variable), altta metotlar.
  - Nitelikler `ad: tip` biçiminde yazılır. Başındaki `-` private, `+` public anlamına gelir.
  - Diyagramdaki sınıflar: `Test` (`main`), `Kitaplik` (`-raf: Raf[]`), `Raf` (`-kitaplar: Kitap[]`), `Kitap` (`-ad`, `-yazar`, `-ISBN: String`, `-kitapSayisi: <static> int`).
- Sınıflar arası ilişkiler
  - Güçlü ilişki (composition, içi dolu elmas): parça bütüne sıkıca bağlıdır. Bütün ortadan kalkınca parçalara erişilemez. Slayttaki örnek: kişi ve beyni. Bu örnekte `Kitaplik` ile `Raf` arasında kurulur.
  - Zayıf ilişki (aggregation, içi boş elmas): yine bütün-parça ilişkisidir ama parçalar ayrı oluşturulur ve bütün kalkınca yaşamaya devam eder. Slayttaki örnek: araba ve yolcular. Bu örnekte `Raf` ile `Kitap` arasında kurulur.
  - Bağımlılık (dependency, kesikli ok): sahiplik yoktur. `Test` sınıfı `Kitaplik` ve `Kitap` nesnelerini yalnız kullanır.
- Kapsülleme, getter ve setter
  - Nitelikler private yapılır. Dışarıdan erişim yalnız public metotlarla olur. Böylece sınıf, verisinin ne kadarını göstereceğine kendisi karar verir.
  - Eclipse'te Source > Generate Getters and Setters ile erişim metotları otomatik üretilir.
- Yapılandırıcı (constructor), `this`, `final` ve `static`
  - Constructor, sınıfla aynı adı taşıyan ve nesne `new` ile oluşturulurken çalışan metottur. Nesneye başlangıç değerlerini vermek için kullanılır.
  - Parametre adı nitelik adıyla aynıysa nitelik `this.ad` diye belirtilir.
  - `final` nitelik bir kez değer alır, sonra değiştirilemez. Bu yüzden `ISBN` için setter üretilmez.
  - `static` nitelik nesneye değil sınıfa aittir, bütün nesneler aynı değeri paylaşır. Sınıf adıyla erişilir: `Kitap.getKitapSayisi()`.
- `toString` metodu
  - Bir nesne doğrudan yazdırılınca `Kitap@7852e922` gibi bir değer çıkar (ekrandan, 00:50:00).
  - `toString` override edilince aynı `println` nesnenin içeriğini yazar: `Kitap [ad=Kitap1, yazar=Yazar1, ISBN=1234]` (ekrandan, 00:55:00).
- Diziler içinde nesneler
  - `Kitaplik` bir `Raf[]` dizisi, her `Raf` 10 elemanlı bir `Kitap[]` dizisi tutar.
  - Nesne dizisi oluşturmak (`new Raf[n]`) ile dizinin elemanlarına nesne atamak (`raf[i] = new Raf()`) ayrı adımlardır.
- Kitap ekleme, silme, arama ve listeleme
  - Ekleme: dizi gezilir, ilk `null` gözeye kitap konur ve `break` ile çıkılır.
  - Silme: verilen kitabın bulunduğu göz `null` yapılır, `break` ile çıkılır.
  - Arama: iç içe iki döngüyle raflar ve kitaplar gezilir, adlar `compareTo` ile karşılaştırılır.
  - Listeleme: klasik `for` ve geliştirilmiş `for` (enhanced for) ile dizi elemanları yazdırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Nitelikler genelde private, metotlar genelde public yapılır
  - Nesneye yönelik programlamada veri metotlarla sarılır (encapsulation). Dışarıdaki kod veriye ancak sınıfın izin verdiği metotlarla ulaşır.
- Composition ile aggregation farkı kodda görünür
  - Raflar kitaplığın constructor'ı içinde oluşturulur. Kitaplık kalkarsa raflara erişilemez.
  - Kitaplar `main` içinde ayrı ayrı oluşturulur, rafa sonradan eklenir. Kitaplık ve raf kalksa da kitaplar yaşamaya devam eder.
- Diziyi oluşturmak elemanları oluşturmak demek değildir
  - Derste `raf = new Raf[n];` satırı unutulunca program 9. satırda hata verdi. Dizi tanımı ve her elemana `new Raf()` ataması ayrı ayrı yapılmalıdır.
- Döngüden `break` ile çıkmak gerekir
  - Ekleme döngüsünde `break` olmazsa aynı kitap rafın bütün boş gözlerine yazılır.
- `null` kontrolü
  - Aramada boş gözlerde `getAd()` çağrılmasın diye önce `iter != null` kontrol edilir (ekrandan, 01:30:00).
- Değişiklikleri kaydetmek
  - Eclipse'te dosya kaydedilmezse diğer sınıf yeni metodu görmez ve hata çıkar.

## Kısa Tekrar Notları

- UML: `-` private, `+` public; kutu = ad / nitelikler / metotlar.
- Dolu elmas = composition (güçlü), boş elmas = aggregation (zayıf), kesikli ok = dependency.
- Nesne oluşturma: `Kitap kitap1 = new Kitap("Kitap1", "Yazar1", "1234");`
- `this.ad = ad;` nitelik ile parametreyi ayırır.
- `final` nitelik: bir kez atanır, setter'ı olmaz.
- `static` nitelik: sınıfa aittir, nesne oluşturmadan sınıf adıyla erişilir; nesne sayacı olarak kullanılabilir.
- `toString` override edilmezse nesne `SınıfAdı@...` biçiminde yazılır.
- Nesne dizisi: önce `new Raf[n]`, sonra döngüyle `raf[i] = new Raf()`.
- Boş nesne dizisi gözleri `null` değerindedir.
- `compareTo` sonucu 0 ise iki String eşittir.
- Geliştirilmiş for: `for (Kitap iter : kitaplar)`.
- Eclipse kısayolları: `main` + Ctrl+Space, `sysout` + Ctrl+Space.

## Detaylı Açıklamalar

- Kitap sınıfı (ekrandan, 00:40:00 ve 00:45:00)
  - Nitelikler `private String ad`, `private String yazar`, `private final String ISBN`, `private static int kitapSayisi` olarak yazılır.
  - Constructor üç String parametre alır ve `this.ad = ad; this.yazar = yazar; ISBN = isbn;` atamalarını yapar. `ISBN` ile `isbn` büyük-küçük harf farkıyla ayrıldığı için orada `this` gerekmez. Her nesne oluştuğunda `kitapSayisi` bir artırılır. Derste dört kitap oluşturulunca `Kitap.getKitapSayisi()` 4 yazdırdı (ekrandan, 01:35:00).
  - Eclipse'in ürettiği metotlar: `getAd`, `setAd`, `getYazar`, `setYazar`, `getISBN` (yalnız get, çünkü final) ve `static int getKitapSayisi()`.
  - Dersin sonunda `kitap3.setAd("Suç ve Ceza")` ile adın değiştirilebildiği gösterildi.
- Raf sınıfı (ekrandan, 01:00:00)
  - `private Kitap[] kitaplar;` niteliği constructor'da `new Kitap[10]` ile oluşturulur, yani her rafta 10 kitaplık yer açılır.
  - `kitapEkle(Kitap ktp)`, `kitapSil(Kitap ktp)`, `rafGoster()` ve `getKitaplar()` metotları vardır.
- Kitaplık sınıfı (ekrandan, 01:05:00, 01:20:00 ve 01:30:00)
  - Constructor raf sayısını alır, `Raf[]` dizisini oluşturur ve her göze yeni bir `Raf` koyar.
  - `kitapEkle(Kitap ktp, int rafNo)`, `rafGoster(int rafNo)` ve `kitapSil(int rafNo, Kitap ktp)` işi ilgili rafın aynı adlı metoduna devreder: `raf[rafNo].kitapEkle(ktp);`. Bu iki aşamalı yapı ilişkileri görmek için seçildi; `getKitaplar()` ile tek aşamada da yazılabilirdi.
  - `kitapAra(String str)` dönüş tipi `Kitap` olan bir metottur. Bulursa "aranan kitap %d. rafta bulunuyor." yazar ve kitabı döndürür, bulamazsa "aranan kitap bulunamadı" yazar ve `null` döndürür.
  - `tumRaflariGoster()` her raf için "i. Raftaki Kitaplar:" başlığını yazar ve aynı sınıftaki `rafGoster(i)` metodunu çağırır.
- Çalıştırma sonucu
  - Üç kitap 0. rafa eklenip raf gösterilince üç kitap ve yedi `null` yazıldı. `kitap1` silinince ilk göz `null` oldu. `Kitap2` önce 0. rafta bulundu, silindikten sonra bulunamadı.
  - Ajan, ekrandaki dört sınıfı tek dosyada birleştirip çalıştırdı; çıktılar ekrandakilerle aynıdır. Sistemde `javac` olmadığı için kod `java Test.java` (tek dosya kaynak çalıştırıcı) ile derlenip çalıştırıldı.
- Ders sonrası notlar
  - UML'de `toString(): void` yazıyor; doğrusu `toString(): String`. Asistan da bir yerde elle yazımı "public void string" diye söyledi, ama ekrandaki üretilen metot String döndürüyor.
  - Asistan Java'nın constructor'ı zaten kendisi oluşturduğunu söyledi. Bu yalnız sınıfta hiç constructor yazılmadıysa geçerlidir; `Kitap(String, String, String)` yazıldıktan sonra `new Kitap()` derlenmez.
  - Asistan statik değişken için "hiçbir şekilde değişmeyecek" dedi. Kastedilen, değerin bütün nesneler için ortak olmasıdır; değerin kendisi değişebilir (sayaç örneğinde olduğu gibi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
