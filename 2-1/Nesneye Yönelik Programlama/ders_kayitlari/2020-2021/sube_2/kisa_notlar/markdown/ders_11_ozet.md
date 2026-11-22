# Ders 11 Çalışma Özeti

## Genel Konular

- Uygulama oturumunun konusu
  - Bu kayıt bir uygulama oturumudur. Konu kalıtımdır (inheritance). Önce küçük bir ders/not örneğiyle kalıtımın temelleri kodlanır, sonra kitaplık uygulamasının kalıtım ve soyut sınıf eklenmiş ikinci sürümü incelenir.
- Sahip olma (has-a) ile kalıtım (is-a) ilişkisi
  - Önceki uygulamadaki composition ve aggregation ilişkileri sahip olma ilişkisidir: bir `Raf` nesnesi `Kitap` dizisi tutar, "raf kitaplara sahiptir".
  - Kalıtım ise "budur" ilişkisidir: alt sınıf (subclass, çocuk sınıf) aynı zamanda üst sınıfın (superclass) bir türüdür.
  - UML'de kalıtım, alt sınıftan üst sınıfa çizilen içi boş üçgen uçlu okla gösterilir.
- Örnek UML: `Ders`, `ZorunluDers`, `SecmeliDers` (ekrandan, 00:10:00)
  - `Ders`: `# dersAdi: String`, `# vize1: int`, `# finalNotu: int`; `+ Ders(String, int, int)`, `+ hesaplaNot(): double`.
  - `ZorunluDers`: `- vize2: int`; `+ ZorunluDers(int)`, `+ hesaplaNot(): double`.
  - `SecmeliDers`: `- vize2: int`, `- proje: int`; `+ SecmeliDers(int, int)`, `+ hesaplaNot(): double`.
  - `TestDers` sınıfı `main` içerir ve `Ders`'e kesikli okla (bağımlılık) bağlıdır.
  - Diyagramdaki `ZorunluDers(int)` gösterimi yalnız eklenen parametreyi gösterir; gerçek constructor üst sınıfın parametrelerini de alır.
- Erişim belirteçleri ve `protected`
  - `+` public: her sınıftan erişilir. `-` private: yalnız kendi sınıfından erişilir.
  - `#` protected: kendi sınıfı, alt sınıflar ve aynı paketteki sınıflar erişir; başka paketten erişilmez. Public ile private arasında bir düzeydir.
  - Paketler, benzer işleri yapan sınıfları bir arada tutmak için Eclipse'te projenin `src` klasörüne New > Package ile oluşturulur.
- `extends` ve `super` ile constructor
  - Alt sınıf `public class SecmeliDers extends Ders` biçiminde tanımlanır.
  - Üst sınıfta parametreli bir constructor varsa alt sınıf da constructor tanımlamak zorundadır; Eclipse bu hatayı çözüm önerisiyle gösterir.
  - Alt sınıfın constructor'ı ilk satırda `super(dersAdi, vize1, finalNot)` ile üst sınıfın constructor'ını çağırır, kendi alanlarını `this` ile atar (ekrandan, 00:35:00).
  - Ortak alanlar alt sınıfta yeniden tanımlanmaz; üst sınıftan gelir.
  - `super(...)` çağrısı üst sınıfın var olan bir constructor'ına uymalıdır. Üst sınıfta üç parametreli constructor varken iki parametreyle çağrılamaz; böyle bir constructor üst sınıfa eklenmelidir.
  - Eclipse: Source > Generate Constructor using Fields.
- Override (metodu ezmek)
  - Alt sınıfta üst sınıftaki metodun aynı ad, parametre ve dönüş tipiyle yeniden yazılmasıdır. Alt sınıf metodu kendi ihtiyacına göre doldurur.
  - Eclipse: Source > Override/Implement Methods. Üretilen gövdede `super.hesaplaNot()` çağrısı bulunur; bu, üst sınıfın sürümünü çalıştırır.
  - Alt sınıf metodu override etmezse üst sınıfın metodu çalışır.
  - Java'daki bütün sınıflar `Object` sınıfından türer; `toString` bu yüzden override edilebilir.
- Alt sınıf nesnesi üst sınıf tipinde tutulabilir
  - `Ders zd1 = new ZorunluDers(...)` geçerlidir, çünkü alt sınıf nesnesi aynı zamanda bir `Ders` nesnesidir.
- `super` ile aynı adlı alanları ayırmak
  - Alt sınıfta üst sınıftakiyle aynı adlı bir alan tanımlanırsa yalın ad alt sınıfın alanını gösterir. Üst sınıfın alanı `super.vize1` ile kullanılır.
- Soyut sınıf ve soyut metot
  - `public abstract class Kart` soyut sınıftır. `public abstract boolean odemeYap(double fiyat);` gövdesiz (süslü parantezsiz) soyut metottur (ekrandan, 00:55:00).
  - Soyut metodu olan sınıftan türeyen somut (concrete) alt sınıflar bu metodu override etmek zorundadır.
  - Soyut sınıftan `new Kart(...)` ile nesne üretilemez, ama `Kart kart1 = new OgrenciKarti(...)` yazılabilir.
  - Soyut sınıfın da constructor'ı olur; alt sınıflar onu `super` ile çağırır.
- Overload (aşırı yükleme)
  - Aynı sınıfta aynı adlı birden çok metot tanımlamaktır; kalıtımla ilgisi yoktur.
  - Parametre listeleri (tipleri, sayısı ya da sırası) farklı olmalıdır. Örnek: `kitapSil(int, int)` ve `kitapSil(int, Kitap)`.
- Kitaplık uygulaması 2 (ekrandan, 00:40:00)
  - Önceki `Kitaplik`, `Raf`, `Kitap` yapısı ve ilişkileri aynen kalır; `Kitap`'a `fiyat: double` alanı eklenir (her kitap 10 lira).
  - Yeni sınıflar: soyut `Kart` (`id`, `Sahip`, `Bakiye`, soyut `odemeYap`), ondan türeyen `YetiskinKarti` ve `OgrenciKarti` (`bonus: double`), `KitaplikYonetim` (bir `Kitaplik` tutar, `kitapSat(kitap, kart)`).
  - `kitapSat`: `kitapAra` ile kitabın raf numarası alınır; -1 ise "kitap yok", değilse kartın `odemeYap` metodu çağrılır; ödeme başarılıysa kitap raftan silinir, değilse "bakiye yetersiz" yazılır.
  - `YetiskinKarti.odemeYap`: bakiye fiyattan büyük ya da eşitse fiyat bakiyeden düşülür ve `true` döner, değilse `false` (ekrandan, 01:00:00).
  - `OgrenciKarti.odemeYap`: bakiye yeterliyse fiyat düşülür ve fiyatın %20'si bonus olarak eklenir; bakiye yetmez ama bonus fiyattan büyük ya da eşitse fiyat bonustan düşülür; ikisi de yetmezse `false` döner.
- `static` üyeler
  - Statik metot ve değişkenler nesne üretmeden sınıf adıyla çağrılır. Nesne üzerinden çağırmak, o üyenin nesneye özgü olduğu izlenimini verdiği için uygun görülmez.

## Hocanın Özellikle Vurguladığı Kısımlar

- Override ile overload karıştırılmamalıdır
  - Override: alt sınıfta metodun içini yeniden doldurmak. Overload: aynı adlı ama farklı parametreli metotlar.
- Overload'da parametre tipleri birebir aynı olamaz
  - İki metot da `(int, int)` alırsa derleyici hangisini çağıracağını bilemez. `(int, String)` ile `(String, int)` ise geçerlidir.
- Kalıtımda en çok kullanılan şey override'dır.
- Soyut metot kullanmanın amacı, alt sınıfların o metodu doldurmasını zorunlu kılmaktır
  - Sıradan bir üst sınıf metodu alt sınıfı override etmeye zorlamaz; soyut metot zorlar.
- `null` kontrolü
  - Dizideki bir eleman `null` iken onun bir metodu çağrılırsa `NullPointerException` alınır. `kitapAra` içinde `kitap.getAd()` çağrılmadan önce elemanın `null` olmadığı kontrol edilmelidir.
- Eclipse uyarılarını okumak
  - Uyarı hem nedenini hem çözüm önerisini gösterir.

## Kısa Tekrar Notları

- has-a: sahip olma (composition, aggregation). is-a: kalıtım.
- UML kalıtım oku: içi boş üçgen uç, alt sınıftan üst sınıfa.
- `#` protected: sınıf + alt sınıflar + aynı paket.
- `class A extends B`; alt sınıf constructor'ı `super(...)` ile başlar.
- Override: aynı imza, alt sınıfta yeni gövde. `super.metot()` üst sınıfın sürümünü çağırır.
- Override edilmeyen metot üst sınıftan çalışır.
- `UstSinif ref = new AltSinif(...)` geçerlidir.
- `abstract class`: nesnesi üretilemez; `abstract` metot gövdesizdir ve somut alt sınıfta override edilmek zorundadır.
- Overload: aynı ad, farklı parametre listesi; kalıtımdan bağımsız.
- Statik üye: `SinifAdi.uye`.
- Nesneye metot çağırmadan önce `null` kontrolü.

## Detaylı Açıklamalar

- Ders/not örneği (ekrandan, 00:20:00, 00:30:00, 00:35:00)
  - `Ders` sınıfında üç alan `protected` tanımlanır. `hesaplaNot()` önce "Ders sınıfında hesaplaNot çalıştı." yazar, sonra `vize1*0.4 + finalNot*0.6` döndürür.
  - `ZorunluDers` ek olarak `vize2` alır; constructor'ı `super(dersAdi, vize1, finalNot)` çağırıp `this.vize2 = vize2` atar. Override edilen `hesaplaNot()` "Zorunlu Ders notlari" yazar ve vize1 %30, vize2 %30, final %40 ağırlıkla hesap yapar.
  - `SecmeliDers` constructor'ı `SecmeliDers(String dersAdi, int vize1, int vize2, int finalNot, int proje)` biçimindedir (ekrandan, 00:35:00).
  - Test: `new Ders("İş Sağlığı", 75, 95)` için $75 \cdot 0.4 + 95 \cdot 0.6 = 87.0$; `new ZorunluDers("BBG", 80, 90, 100)` için $80 \cdot 0.3 + 90 \cdot 0.3 + 100 \cdot 0.4 = 91.0$; henüz override etmeyen `SecmeliDers` (50, 60, 70, 80) için üst sınıf metodu çalışır: $50 \cdot 0.4 + 70 \cdot 0.6 = 62.0$ (ekrandan, 00:35:00). Bu üç sonuç ajanın Java ile kurduğu sürümde de aynı çıktı.
  - Daha sonra `SecmeliDers` için de `hesaplaNot` override edilir ve çıktıda seçmeli dersin kendi iletisi görünür. <!-- BELİRSİZ: SecmeliDers.hesaplaNot formülü ve çıktısı karelerde görünmüyor. -->
- Kitaplık uygulaması 2
  - `Kitaplik(5)` beş elemanlı bir `Raf` dizisi oluşturur ve döngüyle her göze `new Raf()` atar; her `Raf()` 10 elemanlı bir `Kitap` dizisi kurar. Rafların constructor'ı public olduğu için test sınıfında doğrudan `new Raf()` da yazılabilirdi, ama tasarım gereği raflara kitaplık üzerinden erişilir.
  - Test çıktısında kartlar `Kart [id=0, Sahip=Ali, Bakiye=50.0]OgrenciKartı [bonus=0.0]` ve `Kart [id=1, Sahip=Ayşe, Bakiye=50.0]` biçiminde yazılır (ekrandan, 00:55:00). `YetiskinKarti` `toString` yazmadığı için `Kart`'ınki çalışır; `OgrenciKarti` ise `super.toString()` sonucuna bonus bilgisini ekler.
  - Ödeme metotlarının `boolean` dönmesi, `kitapSat` içinde satışın yapılıp yapılmayacağına karar vermeyi sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
