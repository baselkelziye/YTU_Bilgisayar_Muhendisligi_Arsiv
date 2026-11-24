# Ders 2 Genişletilmiş Notu: Dönem Projesi Sunumları: Test Planı ve Test Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Projenin Çerçevesi
- 2. Masaüstü Uçuş Takip Simülasyonu: JUnit ve SikuliX
- 3. Web Tabanlı Kart Oyunu: Kara Kutu, Jest, Cypress ve Lighthouse
- 4. Kitapçı Web API'si: xUnit ile Parametreli Negatif Test
- 5. Anomali Tespit Servisi: Birim, Entegrasyon ve Sistem Testi
- 6. Hastane Yönetim Sistemi: Test Türleri ve Kara Kutu Test Tablosu
- 7. Borsa Takip Sistemi: Kullanım Senaryoları ve Postman ile Entegrasyon Testi

## 1. Projenin Çerçevesi

Bu ders tamamen dönem projesi sunumlarına ayrıldı. Her grup daha önce geliştirilmiş bir yazılımı seçti ve ona baştan sona bir test süreci uyguladı. Süreç üç belgeyle kayda geçirildi:

- **Yazılım gereksinim spesifikasyonu (SRS):** Yazılımın ne yapması gerektiğini fonksiyonel ve fonksiyonel olmayan gereksinimler olarak tanımlar. Testlerin neye göre yapılacağının temelidir.
- **Test planı:** Hangi öğelerin, hangi test türleriyle, hangi araçla, kim tarafından ve hangi koşullarda test edileceğini belirler.
- **Test sonuç raporu:** Çalıştırılan testlerin sonuçlarını, bulunan hataları ve hataların ciddiyetini toplar.

Projede en az iki test türü istendi: birim testi ile sistem testi ya da birim testi ile kullanıcı testi. Bir öğrencinin sorusu üzerine hoca, kodun teslim edilmesinin gerekmediğini söyledi. Kod geliştirmek görev değildir. Görev, var olan kodun nasıl test edildiğini göstermektir. Birim testi yazılırken kod zaten kullanılır.

> **Hocanın vurgusu:** Rapor zaten teslim ediliyor. Sunumda testlerin hangi araçla ve nasıl çalıştırıldığı canlı gösterilmeli ki bu aracı kullanmamış arkadaşlar da görsün. Benzer durumları tekrarlamaya gerek yok, her test türü için bir örnek yeterli.

## 2. Masaüstü Uçuş Takip Simülasyonu: JUnit ve SikuliX

### 2.1 Test edilen uygulama ve gereksinimler

İlk grup Java Swing ile yazılmış bir hava yolu simülasyonunu test etti. Uygulamada şehirler ekleniyor, şehirler arasında güzergahlar oluşturuluyor ve bir sistem saatine göre uçuşların kalkışı, havada olması ve inişi izleniyor. Saat durdurulabiliyor ve değiştirilebiliyor. Grup gereksinim listesini çıkardı ve her gereksinimin karşılanıp karşılanmadığını onay kutusuyla işaretledi. Kullanıcı testinde yalnız bir gereksinimin tam karşılanmadığı görüldü: sistem saatinin sıfırlanması ya da serbestçe değiştirilmesi.

### 2.2 Test planı ve birim testleri

Beyaz kutu tarafında JUnit ile birim testleri yazıldı. Test planında her metodun nasıl test edileceği tanımlandı. Örneğin arayüzdeki uçuş listesini güncelleyen metot için iki test durumu kuruldu: sisteme iki uçuş ve on beş uçuş eklenerek liste denetlendi. Geçme ölçütü, uçuş listesinin eksiksiz ve hatasız olmasıydı. Planda toplam 7 birim testi tanımlandı.

Test sonuç raporundaki ilk hata, 0 dakikalık bir güzergahın eklenebilmesiydi. Böyle bir güzergah oluşturulamamalıdır. Hata, güzergah ekleme düğmesinin çalıştırdığı fonksiyonun süre alanında gerekli kontrolü yapmamasından kaynaklanıyordu. Raporda verilen test kodu şöyledir (ekrandan, 00:05:00; paket adı sadeleştirildi):

```java
@Test
void testRouteCannotTake0Minutes() {
    deleteFile("capitals.dat");
    App appUnderTest = new App();

    appUnderTest.getCapitalTextField().setText("C0");
    appUnderTest.getBtnAddCapital().doClick();
    appUnderTest.getCapitalTextField().setText("C1");
    appUnderTest.getBtnAddCapital().doClick();

    appUnderTest.getComboBoxFrom().setSelectedIndex(0);
    appUnderTest.getComboBoxTo().setSelectedIndex(1);
    appUnderTest.getTextFieldTime().setText("0");

    appUnderTest.getBtnAddRoute().doClick();

    JList<Route> addedRoutes = appUnderTest.getListRoute();
    assert(addedRoutes.getModel().getSize() == 0);
}
```

Program 0 süreli güzergahı listeye eklediği için test başarısız olur. Sunan öğrenci bu hatanın ciddiyetini küçük olarak değerlendirdi. Gerçekleşme sıklığı düşüktür, ama programda mantıksal bir hata olduğunu gösterir.

İkinci hata zamanlayıcıyla ilgilidir. Raporda "Zamanlayıcı Başlatma Durdurma Senaryo Sınıfı Hata 1" başlığıyla şu bilgiler yazıldı: senaryo numarası 1, test edilen işlem "zamanlayıcıdan belli aralıklarla zaman bilgisi almak", sonuç başarısız, ciddiyet orta (ekrandan, 00:05:00). Zamanlayıcı başlatılınca şimdiki zamandan ileri sayıyor ve uçuşları buna göre ilerletiyor. Hiç şehir yokken zamanlayıcı durdurulursa uçuş listesini güncelleyen fonksiyon seçili şehir nesnesini almaya çalışıyor ve `NullPointerException` oluşuyor.

### 2.3 JUnit'in projeye eklenmesi

Hoca, testlerin nasıl başlatıldığını göstermelerini istedi. JUnit 5 (Jupiter), Gradle yapı dosyasına bağımlılık olarak eklendi. Gradle yapı sistemini otomatik ayarladı. Test dosyasında şunlar kullanıldı (ekrandan, 00:10:00):

- `org.junit.jupiter.api.Test`: bir metodu test olarak işaretler.
- `org.junit.jupiter.api.Order`: birden fazla testin çalışma sırasını belirler.
- `import static org.junit.jupiter.api.Assertions.assertEquals;`: doğrulama metotları statik olarak içe aktarılınca doğrudan `assertEquals(...)` diye yazılabilir.

### 2.4 Sistem testi

Sistem testinde, programın birçok parçası birlikte çalıştığında beklenen sonucun alınıp alınmadığı denendi. Test iki şehir ekliyor, şehir listesinde iki eleman olduğunu ve adlarının eklenen adlarla aynı olduğunu denetliyor. Sonra iki şehir arasına güzergah ekliyor ve güzergahın başlangıç şehrini, varış şehrini ve süresini doğruluyor. Ardından ilk şehri silip şehir listesinde bir eleman kaldığını ve ona bağlı güzergahın da silindiğini (güzergah listesinin boyutu 0) kontrol ediyor (ekrandan, 00:15:00). Arayüzdeki düğmeler ve metin alanları sınıflardaki getter metotlarıyla alındı. Tıklama `doClick()`, yazma `setText()` ile yapıldı.

**Soru (hoca):** Sistem testi olarak neyi seçtiniz, performansı mı yoksa güvenliği mi? **Cevap:** Programın birçok parçası birlikte çalıştığında düzgün ve beklenen sonucu verip vermediği denendi.

### 2.5 SikuliX ile görüntüye dayalı arayüz otomasyonu

Swing arayüzünü test etmenin doğrudan kolay bir yolu olmadığı için grup önce SikuliX aracını denedi. SikuliX, verilen bir resme göre ekrandaki nesneyi bulur, fareyi oraya götürür, tıklar ve yazı yazar. Bu testte kullanıcı fareye hiç dokunmaz, araç arayüzü kendisi kullanır. Kodda ekran bölgesi (`Region`) tanımlanıyor, bir resim (örneğin şehir adı metin alanının resmi) `find` ile aranıyor ve bulunan bölgenin altındaki alana tıklanıp yazı yazılıyor (ekrandan, 00:10:00).

**Soru (hoca):** Buna fonksiyonel test de diyebilir miyiz? **Cevap:** Evet. Hoca bunu şöyle açıkladı: gereksinimlerdeki bir fonksiyonu yerine getirmek için gereken komutlar hızlıca çalıştırılıyor ve ön yüzde ne yapıldığı görünüyor. Fonksiyonun dışarıdan görüldüğü haliyle tamamlanıp tamamlanmadığı sınanıyor. Bu yüzden fonksiyon testi denebilir.

### 2.6 Dayanıklılık denemesi ve kaynak sızıntısı

Grup, programın kaydettiği ve sonra tekrar okuduğu veri dosyasının bazı baytlarını bozmayı da denedi. Amaç programın ne kadar dayanıklı (robust) olduğunu görmekti. Programda istisna yakalanıp yalnız yığın izi yazdırıldığı için program dosyayı yok sayarak çalışmaya devam etti. Bu davranış aslında doğru sayılabilir. Ancak dosya nesnesi kapatılmıyordu. Bu hata, iki test art arda çalıştırılınca ortaya çıktı: ikinci test, dosyanın başka bir süreç tarafından kullanıldığını söyleyerek dosyayı açamadı. Hoca bunun da bir hata olduğunu, ama otomatik bir testte hata olarak göstermenin zor olduğunu söyledi.

Grup ayrıca kullanıcı testi yaptı. Bu test, SRS'teki gereksinimlerin "bu yapıldı, bu yapılmadı" biçiminde metne dökülmüş haliydi. Hoca, laboratuvardaki gibi bir tablo biçiminin de aynı işi göreceğini söyledi.

## 3. Web Tabanlı Kart Oyunu: Kara Kutu, Jest, Cypress ve Lighthouse

### 3.1 Uygulama ve SRS

İkinci grup React ile yazılmış, tarayıcıda çalışan bir Spider Solitaire oyununu test etti. Oyunda A'dan K'ya kartlar alt alta diziliyor, tamamlanan seriler üstte toplanıyor ve bütün seriler bitince oyun sona eriyor.

SRS'in genel tanım bölümünde kullanıcı ihtiyaçları yazıldı: kartların ve animasyonların anlaşılır ve görünür olması, oyunun durumunun kolayca izlenebilmesi, her işletim sisteminde, cihazda ve tarayıcıda çalışması, mobil cihazlar için düşük donanım ihtiyacı ve düşük güç tüketimi, sürükle-bırak gibi özelliklerle kullanılabilir bir arayüz. Bağımlılık olarak JavaScript destekleyen bir tarayıcı gerekiyor.

Fonksiyonel gereksinimler sayfa bazında sınıflandırıldı: bitiş sayfası, kurallar sayfası ve oyun sayfası. Bileşen sayıları ve uzunlukları, zamanlayıcı, duyarlı (responsive) tasarım, arka plan ve resimler, rastgele kart üretici, oyun mantığı ve uygulamada kullanılan bağlı liste için de ayrı gereksinimler yazıldı. Fonksiyonel olmayan gereksinimler şunlardı: uyumluluk, taşınabilirlik, güvenlik, hız, performans, kapasite, yerelleştirme (farklı diller), ölçeklenebilirlik, kullanılabilirlik, erişilebilirlik, sürdürülebilirlik ve bakım yapılabilirlik.

### 3.2 Kullanım durumuna dayalı kara kutu testi

Kara kutu testinde kullanım durumu (use case) temelli test tasarımı kullanıldı. Kullanıcının sistemden beklediği durumlar tek tek denendi:

- **Kart seçimi:** Bir karta tıklanınca etrafında kırmızı bir çerçeve oluşuyor, yani kart seçilebiliyor.
- **Kart hamlesi:** Kart doğru yere konunca yerine yerleşiyor.
- **İpucu:** Hint düğmesine basılınca geçerli bir hamle öneriliyor. Örnekte 5 ve 6 numaralı kartlar vurgulanıyor ve bu geçerli bir hamle (ekrandan, 00:25:00).
- **Kart dağıtma:** Dağıtma destesindeki karta basılınca her sıraya birer kart dağıtılıyor. Boş bir sütun varken dağıtma yapılmıyor, boş sütun yokken yapılıyor.
- **Seri tamamlama:** Bir seri bitince yukarı alınıyor ve bir bildirim gösteriliyor.
- **Hatalı yerleştirme:** Kart yanlış yere konunca hata vermesi bekleniyor.
- **Oyunu tamamlama:** Yukarıdaki bütün boş yuvalar dolunca oyun bitiyor ve sonuç gösteriliyor.
- **Kaybetme:** Hiç hamle kalmamışsa ve bütün kartlar dağıtılmışsa oyun kaybedilmiş oluyor. Bunun için özel bir ekran yok.
- **Geri alma:** Bir hamle geri alınabiliyor, ama yalnız bir adım. İki kez geri alınamıyor.

### 3.3 Test planı ve birim testleri (Jest)

Birim testinde en küçük parçalar bağımsız olarak, basit senaryolarla test edildi. Araç olarak Jest seçildi. Örneğin kartlar üretildikten sonra karıştırma testi yapıldı: küçük bir örnek dizi oluşturulup karıştırıldı ve tutarlılığı denetlendi. Test verisi kısmında kartlar değer ve deste numarasıyla tanımlandı. Bağlı listenin "sonraki eleman yok" durumu da ayrıca denendi. Raporda dağıtılacak kalan kartları denetleyen bir birim testi de gösterildi (ekrandan, 00:35:00; kodun yalnız başı görünüyor):

```javascript
describe("Card Generator Remaining Cards Test", () => {
    it("should remCards length is 50", () => {
        const array = generateCards()
        const remArray = getRemainingCards(array)
        // ... (devamı karede görünmüyor)
```

<!-- BELİRSİZ: Testin devamı ve beklenen uzunluğun neye göre 50 olduğu karede görünmüyor. -->

Test senaryoları oyunun akışına göre gruplandı. Başlangıç senaryosunda kartlar dağıtıldıktan sonra dağıtım ve üstteki kart testleri yapıldı. Devamlılık senaryosunda karta tıklanınca seçili olduğunu gösteren kırmızı çerçeve ve hamlelerin sisteme yansıyıp yansımadığı (seri tamamlanma denetimi) test edildi.

Jest toplam 3 test dosyasında 23 test çalıştırdı ve hepsi geçti. Kapsam raporunda tüm dosyalar için değerler şöyleydi (ekrandan, 00:30:00):

| Ölçü | Değer |
|---|---|
| Deyim (Stmts) | %71,63 |
| Dal (Branch) | %50,63 |
| Fonksiyon (Funcs) | %81,25 |
| Satır (Lines) | %70,88 |

Jest, test edilmeyen satırları "Uncovered Line" sütununda satır satır gösteriyor. Bu satırlar arayüz testiyle ayrıca sınandı.

> **Hocanın vurgusu:** Derslerde sürekli kapsamdan (coverage) söz ediyoruz. Hazır bir araç kullanıldığında araç, testin kapsamını yüzde olarak sayabiliyor.

### 3.4 Arayüz testi (Cypress)

Arayüz testi için Cypress seçildi. Cypress, Selenium benzeri bir uçtan uca (end-to-end) test çatısıdır. Grubun açıklamasına göre başarısız testlerde kullanıcıya iyi geri bildirim veriyor. Ayrıca sayfanın yüklenmesini beklemek gibi durumları otomatik ayarlıyor. Elle yazılan testlerde bunlar için ayrı komutlar gerekir. Proje duyarlı bir tasarıma sahip olduğu için testler farklı ekran boyutlarında da çalıştırıldı. Toplam 32 test vardı. Raporda testler şu gruplara ayrılmıştı (ekrandan, 00:30:00): Finish Page Test, Rules Page Test, Component Length Test (kart tutucu ve kart sayıları), Game Page Test (tıklama, düğmeler, yeniden başlatma, ipucunda iki kartın vurgulanması) ve Timer Test (zamanlayıcının 00:00:00'dan başlaması, 5 saniye sonra 00:00:05 göstermesi).

### 3.5 Performans testi (Lighthouse)

Performans testi için Lighthouse kullanıldı. Lighthouse, Google'ın ön yüz projeleri için geliştirdiği bir performans test aracıdır. Tarayıcının öğe inceleme (inspect) penceresinden ya da eklenti olarak açılır. Kullandığı metriklerden ikisi şunlardır:

- **First Contentful Paint (FCP):** Site açıldığında ilk anlamlı görüntünün gelmesi için geçen süre.
- **Largest Contentful Paint (LCP):** Sitedeki en büyük öğenin (örneğin en büyük resmin) yüklenme süresi.

Masaüstü ve mobil için ortalamanın üstünde sonuç alındı, mobil performans daha düşüktü. Araç puanın neden o değerde olduğunu ve hangi adımlarla artırılabileceğini de söylüyor. Grubun önerisi, JPEG resimler yerine WebP gibi daha küçük boyutlu bir biçim kullanmaktı. Canlı gösterimde sonuç rapordakinden farklı çıktı. Bunun nedeni, Lighthouse sonucunun o andaki ağa, tarayıcıya ve tarayıcı eklentilerine bağlı olmasıdır.

## 4. Kitapçı Web API'si: xUnit ile Parametreli Negatif Test

### 4.1 Uygulama ve test planı

Üçüncü grup, ASP.NET Core ile yazılmış bir kitapçı Web API'sini test etti. Sistemde yazar, kitap ve kitap türü varlıkları vardır. Testler kitap modülüne odaklandı, yazar ve tür modülleri test edilmedi. Test stratejisi, her gereksinim için birim testi ve ayrıca bir kullanıcı testiydi.

Test planında şu ölçütler tanımlandı:

- **Tamamlanma ölçütü:** Bütün test faaliyetleri yapılmış, sonuçlar başarılı ya da başarısız olarak kaydedilmiş, hatalar çözülmüş ve raporlanmış olmalı.
- **Başlatma ölçütü:** Beklenen sonuçlar belirlenmiş olmalı ve önceki testlerin hataları çözülmüş olmalı.
- **Durdurma ölçütü:** Beklenmeyen bir sonuç alınırsa hatayı düzeltmek için test durdurulur.
- **Yeniden başlatma ölçütü:** Durdurulan test, hata düzeltilince yeniden başlatılır.

Hata seviyeleri üç dereceydi:

- **Birinci derece:** Sistemin genel çalışmasını etkileyen hatalar.
- **İkinci derece:** Genel çalışmayı engellemeyen ama bazı işlevlerin çalışmasını engelleyen hatalar.
- **Üçüncü derece:** İşlevi engellemeyen, görsel hatalar.

Test sorumlulukları dört role ayrıldı: proje yöneticisi, konfigürasyon yönetimi sorumlusu, test yöneticisi ve test ortamı sorumlusu. Test ortamı Visual Studio, test çatısı xUnit.net'tir. Toplam 13 test durumu tanımlandı ve hepsi başarılı çalıştı.

### 4.2 Doğrulama kuralları ve Theory/Fact

Kitap oluşturulurken dört doğrulama yapılır:

- Kitap türü kimliği 0'dan büyük olmalı. Türler bir enum ile tanımlanmıştır (1 kişisel gelişim, 2 bilim kurgu, 3 aksiyon vb.).
- Sayfa sayısı 0'dan büyük olmalı.
- Yayın tarihi bugünden (sistem tarihinden) önce olmalı.
- Başlık en az 4 karakter olmalı.

xUnit'te iki test özniteliği vardır. `[Fact]` tek bir durumu sınayan testtir. `[Theory]` ise aynı testi `[InlineData]` ile verilen farklı verilerle tekrar tekrar çalıştırır. Grup, birden fazla olumsuz durumu tek testte denemek için `[Theory]` kullandı (ekrandan, 00:50:00):

```csharp
public class CreateBookCommandValidatorTests : IClassFixture<CommonTestFixture>
{
    //We used [Theory] to test multiple data at the same time
    [Theory]
    [InlineData("Lord of The Rings", 0, 0)]
    [InlineData("Lord of The Rings", 0, 1)]
    [InlineData("Lord of The Rings", 100, 0)]
    [InlineData("", 0, 0)]
    [InlineData("", 100, 1)]
    [InlineData("Lor", 100, 1)]
    [InlineData("Lord", 100, 0)]
    [InlineData("Lord", 0, 1)]
    [InlineData(" ", 100, 1)]
    public void WhenInvalidInputsAreGiven_Validator_ShouldBeReturnErrors(string title, int pageCount, int genreId)
    {
        //Arrange
        CreateBookCommand command = new CreateBookCommand(null, null);
        command.Model = new CreateBookModel()
        {
            Title = "",
            PageCount = 0,
            PublishDate = DateTime.Now.Date,
            GenreId = 0
        };

        //Act
        CreateBookCommandValidator validator = new CreateBookCommandValidator();
        // ... (devamı karede görünmüyor)
```

Bu bir negatif testtir. Her veri satırı en az bir kuralı ihlal eder. Örneğin ilk satırda başlık geçerlidir, ama sayfa sayısı ve tür 0'dır. Doğrulayıcının hata döndürmesi beklendiği için hata gelince test başarılı sayılır. Satırların hangi kuralı ihlal ettiği python ile denetlendi:

| Satır (başlık, sayfa, tür) | İhlal edilen kural |
|---|---|
| "Lord of The Rings", 0, 0 | sayfa, tür |
| "Lord of The Rings", 0, 1 | sayfa |
| "Lord of The Rings", 100, 0 | tür |
| "", 0, 0 | başlık, sayfa, tür |
| "", 100, 1 | başlık |
| "Lor", 100, 1 | başlık (3 karakter) |
| "Lord", 100, 0 | tür |
| "Lord", 0, 1 | sayfa |
| " ", 100, 1 | başlık (boşluk) |

> **Ders sonrası not:** Sunumda "olası 8 durum" denildi, ama karede 9 adet `[InlineData]` satırı görünüyor. Ayrıca karede modelin alanları parametrelerden değil sabit değerlerden (`Title = ""`, `PageCount = 0`, `GenreId = 0`, `PublishDate = DateTime.Now.Date`) dolduruluyor. Bu haliyle her satırda aynı geçersiz model denenir ve parametrelerin etkisi olmaz. Büyük olasılıkla doğru kullanım `Title = title`, `PageCount = pageCount`, `GenreId = genreId` biçimindedir.

Başarısız bir test de gösterildi. Var olan bir kitabın tekrar eklenmesini sınayan testte, veritabanında bulunmayan bir ad verilince test geçiyor. Veritabanında zaten bulunan bir kitap adı verilince test hata veriyor ve geçemiyor.

### 4.3 Kullanıcı testi (Swagger)

API olduğu için kullanıcı testi Swagger arayüzünden yapıldı. Kitapları listeleyen GET isteği kitapları doğru döndürdü. Geçerli verilerle yeni kitap ekleyen POST isteği kitabı ekledi. İki istek de HTTP 200 kodu döndü.

**Soru (hoca):** Özetle hangi testleri gerçekleştirdiniz? **Cevap:** Birim testleri ve kullanıcı testi. Hoca bunun proje tanımına uygun olduğunu söyledi: birim testi ile sistem testi ya da birim testi ile kullanıcı testi.

## 5. Anomali Tespit Servisi: Birim, Entegrasyon ve Sistem Testi

### 5.1 Modülün işlevleri

Dördüncü grup, PyOD kütüphanesini kullanan bir anomali tespit servisini test etti. Modül, kendisine verilen verinin içinde anomali olup olmadığını tespit edip kullanıcıya gösteriyor. İşlevleri şunlardır:

- **Algoritma seçme:** Kullanıcı anomali tespiti için bir algoritma seçer.
- **Algoritma ayarları:** Seçilen algoritmanın parametreleri verilir.
- **`fit`:** Seçilen algoritma kullanıcının verisiyle eğitilir ve yeni bir model oluşur.
- **`predict`:** Daha önce eğitilmiş bir modelle yeni veri tahmin edilir. Sonuç 0 ve 1'lerden oluşur: anomali var ya da yok.
- **`decision_function`:** Tahminin hangi oranda anomali olduğunu bir puan olarak verir (örneğin 0,70).
- **Veri üretme:** Testler için hazır veri üretir.
- **Kaydetme ve yükleme:** Eğitilen modelin ağırlıkları dosyaya kaydedilir, sonra yeniden eğitmeden yüklenip kullanılır.
- **Toplu tahmin (batch):** İsteğe bağlı olarak veri tek seferde değil, parçalara bölünerek tahmin edilir.

Bu işlevler birim testleriyle sınandı. Arayüzden servise gelen istekler (kaydetme, veri yükleme, eğitim) ise entegrasyon testleriyle sınandı.

### 5.2 SRS

SRS, her özellik için açıklama ve öncelik, uyarı-yanıt (stimulus/response) dizisi ve fonksiyonel gereksinimler biçiminde yazıldı. Model eğitimi özelliği için örnek (ekrandan, 01:00:00):

- **Uyarı-yanıt:** Kullanıcı servise bir eğitim isteği (`fit_request`) gönderir. İki yanıt olabilir: Success (model başarıyla eğitildi, sonuçlar döndü) ve Fail (model eğitilemedi, sonuç dönmedi).
- **REQ-1 `user_id`:** Modülü kullanan her kullanıcı için tekil kimlik.
- **REQ-2 `algorithm_config`:** Anomali tespit algoritmasının ayarları.
- **REQ-3 `model_name`:** Anomaliyi tespit eden modelin ağırlık adı.
- **REQ-4 `data_id`:** Eğitimde kullanılan verinin tekil kimliği.

İletişim arayüzü olarak HTTP/HTTPS ve TCP gerekli, SSL ise isteğe bağlı olarak tanımlandı. Fonksiyonel olmayan gereksinimlerde bellek ihtiyacı (GPU varsa eğitim daha hızlı), hata ve bilgi kayıtlarını tutan bir logger modülü ve kullanıcının yalnız kendi verisine erişebilmesi (güvenlik) yazıldı.

### 5.3 Test planı ve efor tahmini

Test planında birim, entegrasyon ve sistem testleri yer aldı. Planda riskler ve risk azaltma (mitigation) yolları, kimin hangi testi nasıl yapacağı ve kaynak planı (web sunucusu, ağ bağlantısı, bilgisayar) yazıldı. Grup, kurala uygun bir test süreci için normalde beş farklı kişi gerektiğini, herkesin birbirini denetleyebilmesi gerektiğini belirtti. Test ortamı için IP adresi ve boş bir port verilmesi ve gerekli Python sürümüyle kütüphanelerin kurulu olması gerekiyordu. Efor tahmini şöyleydi (ekrandan, 01:05:00):

| Görev | Üyeler | Tahmini efor |
|---|---|---|
| Yazılım gereksinimlerini belirleme | Geliştirici | 30 adam-saat |
| SRS belgesini hazırlama | Testçi, geliştirici | 20 adam-saat |
| Test planını oluşturma | Testçi, geliştirici | 20 adam-saat |
| Testleri çalıştırma | Testçi | 10 adam-saat |
| Test raporunu oluşturma | Testçi | 4 adam-saat |
| **Toplam** | | **84 adam-saat** |

Toplam python ile denetlendi: $30 + 20 + 20 + 10 + 4 = 84$.

### 5.4 Testlerin çalıştırılması

Önce üç entegrasyon testi çalıştı. Bu testler servise kendi kendine istek atıp yanıtı denetliyor. Test sınıfının başında `setUp` servisi hazırlıyor, sonunda `tearDown` servise kapatma (Shutdown) isteği gönderip uygulamadan çıkıyor (ekrandan, 01:10:00). Ardından birim testleri çalıştı. Geçen testler yeşil nokta, başarısız testler kırmızı "fail" ile gösterildi.

Üç test, hata davranışını göstermek için bilerek başarısız yapıldı:

- **Model yükleme:** Test, var olmayan bir model dosyası adı aradı. Dosya bulunamadığı için hata fırlatıldı.
- **Karar fonksiyonu:** Verinin biçimi değiştirildi. scikit-learn 2 boyutlu dizi beklerken 1 boyutlu dizi aldı ve `ValueError: Expected 2D array, got 1D array instead` hatası verdi (ekrandan, 01:10:00).
- **Algoritma ayarı:** Algoritma adı bilerek yanlış yazıldı. Böyle bir algoritma bulunamadığı için hata fırlatıldı.

Kapsam yalnız birim testleri için hesaplandı. Grubun açıklamasına göre entegrasyon testleri kapsam hesabına dahil edilemedi. İlgili dosyalarda %84, %76 ve %30 değerleri görüldü.

Sistem testi arayüz üzerinden elle yapıldı. İki eksik bulundu: algoritma seçilebiliyor ama parametreleri arayüzden girilemiyor, varsayılan parametreler kullanılıyor. Ayrıca `predict` çıktısı arayüzde görünmüyor, sonuç yalnız uygulamanın çalıştığı terminalde görülebiliyor. Servis Postman ya da `curl` komutlarıyla da kullanılabiliyor. Raporda birim ve entegrasyon testi sonuçları kaç testin geçtiği, kaçının başarısız olduğu ve kaçının çalıştırılmadığı biçiminde verildi.

## 6. Hastane Yönetim Sistemi: Test Türleri ve Kara Kutu Test Tablosu

### 6.1 Uygulama ve gereksinimler

Beşinci grup, C# Windows Forms ve MySQL ile yazılmış bir hastane yönetim sistemini test etti. Kullanıcı tipleri veznedar, doktor, kayıt görevlisi, randevu görevlisi ve yöneticidir. Veznedar hastanın kaydını sorgular ve tedavi ücretini sigorta durumuna göre indirimle hesaplar. Doktor randevuyu görür, tedavi bilgisini ekler, rapor ya da reçeteyi PDF olarak üretir. Kayıt görevlisi yeni hasta kaydı açar. Randevu görevlisi poliklinik ve tarihe göre boş doktorları listeler, doktor yoksa alternatif tarihler önerilir. Yönetici doktor ekler, siler ve günceller.

Fonksiyonel olmayan gereksinimler arasında birlikte çalışabilirlik, kullanım kolaylığı, platformlar arası taşınabilirlik ve güvenlik vardı. Güvenlik gereksinimleri şunlardı: her kullanıcı tipi yalnız kendi ekranına girebilmeli, yetkisiz girişler engellenmeli ve hekimler yalnız sorumlu oldukları hastaların verisine ulaşabilmeli.

### 6.2 Test planındaki test türleri

Test ortamı Windows idi. Planda şu test türleri tanımlandı (ekrandan, 01:20:00):

- **Fonksiyonel test:** Sistemin işlevsel yönünü sınar. Verilen girdilere göre beklenen çıktıların alınıp alınmadığına bakar. Örneğin hekimin muayene sonrası panelinde kayıt oluşturup rapor üretmesi ve her düğmenin arkadaki SQL sorgusunu doğru çalıştırması.
- **Arayüz testi:** Arayüzle etkileşimin doğru çalışıp çalışmadığını sınar. Süreç, kullanıcı adı ve şifreyle girişle başlar, veritabanı bağlantısının kurulmasıyla devam eder.
- **Performans testi:** Yüksek riskli bileşenlerin belirli bir iş yükü altında nasıl çalıştığını belirler.
- **Uyumluluk testi:** Yazılımın hazırlandığı platform dışındaki ortamlarla uyumunu, yani taşınabilirliğini sınar. Bu projede Windows ortamında hazırlanan uygulama yine Windows'ta test edildi.
- **Kullanılabilirlik testi:** Belirlenen hedef kitleye belirlenen görevler yaptırılır ve kullanıcıdan verimlilik, etkinlik ve memnuniyet değerlendirmesi alınır. Örneğin aktörlerin fare ve klavyeyle yaptığı işlemlerdeki hatalara bakılır.
- **Güvenlik testi:** Uygulamada güvenlik zafiyeti olup olmadığını, dışarıdan müdahale imkânı olup olmadığını sınar.

Riskler bölümünde yetki kuralları yazıldı: her doktor yalnız kendi hastasının bilgilerine ulaşır, veznedar sınırlı yetkiye sahiptir ve hasta alanlarına erişemez, yönetici bütün panelleri görebilir.

### 6.3 Birim testleri

Birim testlerinde doktor ekleme, silme ve güncelleme denendi. Ad ve soyadın metin ya da sayı olması gibi farklı girdi birleşimleri ele alındı. Sonuçlar bir tabloda toplandı: doktor işlemleri çalışıyor, hasta işlemleri geliştirilmediği için çalışmıyor, PDF oluşturma çalışıyor. Testler C# birim testi projesiyle yazıldı. Bir test metodunun yapısı şöyle anlatıldı:

- Metot test metodu olarak işaretlenir ve `public void` olarak tanımlanır, yani bir değer döndürmez.
- Test edilecek fonksiyon (örneğin doktor ekleme) çağrılır ve dönüş değeri bir değişkende tutulur.
- Bu değer beklenen değerle (örneğin `true`) karşılaştırılır. İkisi eşitse test geçer.

### 6.4 Kara kutu testleri ve hata ciddiyeti

Kara kutu testleri ve sistem testinin güvenlik kısmı elle yapıldı. Aynı kullanıcı adıyla ya da aynı bilgilerle kayıt yapılıp yapılamadığı denendi. Form büyütülüp küçültülünce düğmelerin yerinin bozulup bozulmadığına bakıldı. Rapor için rastgele metinler kullanıldı. Sonuçlar şu tabloda toplandı. Tablonun satırları test durumu kimliği, hata ciddiyeti (Critical, High, Medium, Low), hata açıklaması, hatayı yeniden üretme adımı, test verisi, beklenen sonuç ve gerçekleşen sonuçtur (ekrandan, 01:25:00):

| No | Açıklama | Ciddiyet | Test verisi | Beklenen | Gerçekleşen | Durum |
|---|---|---|---|---|---|---|
| 4 | Elle doktor ekleme | - | Örnek bir doktor adı | Doktorun eklenmesi | Başarıyla eklendi | PASSED |
| 5 | Elle doktor ekleme | - | Başka bir örnek ad | Doktorun eklenmesi | Başarıyla eklendi | PASSED |
| 6 | Elle rapor oluşturma | Medium | Rapor için rastgele metin | Raporun ve içindeki yazıların PDF olarak düzenli kaydedilmesi | PDF kaydediliyor ama isim seçilemiyor | NOT PASSED |
| 7 | Elle doktor silme | Medium | Doktor kimlikleri | Doktorların kimliğe göre silinmesi | Silme başarılı ama kalan doktorların kimlikleri güncellenmiyor | NOT PASSED |
| 8 | Ekran düzeninin bozulup bozulmadığı | Medium | Ekran sağdan büyütüldü | Düğme düzenini koruyarak büyümesi | Düzen korundu ama gerekli büyüme olmadı | NOT PASSED |
| 9 | Reçete işlemleri çalışmıyor | Critical | Reçete ekleme, silme, güncelleme | Reçetelerin eklenip silinebilmesi | Reçete işlemleri tamamlanmamış, yapılamıyor | NOT PASSED |

Tablonun notunda doktor modülünün çalıştığı, diğer modüllerin istenen şekilde çalışmadığı ve grafiklerin statik olduğu, dinamik hale getirilmesi gerektiği yazıyordu. Reçete hatası Critical olarak işaretlendi, çünkü uygulamanın ana hizmeti doktor ile hasta arasındaki reçete ve rapor işlemleriydi. Ekran boyutu ve doktor ekleme/silmedeki girdi denetimi sorunları ise Medium olarak işaretlendi.

### 6.5 Güvenlik testi

Güvenlik testinde üç şey denendi:

- **Veritabanına yetkisiz işlem:** Arayüz üzerinden veritabanında izinsiz bir işlem yapılıp yapılamadığı.
- **Bellek taşması (buffer overflow):** Masaüstü uygulaması olduğu için girdilerin boyutu artırılarak bellek taşması zafiyeti arandı.
- **Yarış durumu (race condition):** İki pencere aynı anda açılıp aynı işlemler birlikte yapıldı ve sistemin bunları doğru sıralayıp sıralamadığına bakıldı.

Bu denemelerde sorun görülmedi. Yetkilendirme ve kimlik doğrulama testleri için kullanım durumu diyagramından yararlanıldı. Örneğin yöneticinin yönetici olarak girebildiği, veznedarın ise doktor ya da poliklinik ekleyemediği denetlendi. Uygulamayı anlamak için sınıf diyagramı ve veritabanı şeması da rapora eklendi. Ad, soyad ve kimlik numarası gibi girdilerin ne kadar doğrulandığı da denendi.

## 7. Borsa Takip Sistemi: Kullanım Senaryoları ve Postman ile Entegrasyon Testi

### 7.1 Gereksinimler ve kullanım senaryoları

Altıncı grup veritabanı, arka uç ve ön yüzden oluşan bir borsa takip sistemini test etti. Fonksiyonel gereksinimler şunlardı: kullanıcı kaydı ve yönetimi, kullanıcı rolleri (admin bütün yetkilere sahip), giriş yapınca borsa kalemlerinin fiyat ve grafiklerinin incelenmesi, hisse alım-satımı, yöneticinin hisse ekleme, düzenleme ve silmesi, yöneticinin kullanıcı ekleme, silme ve rol değiştirmesi.

Kullanım senaryoları ön koşul, aktör, ana akış ve alternatif akış biçiminde yazıldı. Örnekler:

- **Üye olma:** Kullanıcı e-posta ve şifre girer, bilgiler veritabanına kaydedilir. Alternatif akış: e-posta biçimi yanlışsa sistem hatalı e-posta biçimi uyarısı verir.
- **Üye girişi:** Bilgiler veritabanındakiyle eşleşmezse akış giriş adımından tekrarlanır.
- **Yeni hisse ekleme:** Aktör yöneticidir, ön koşul yöneticinin giriş yapmış olmasıdır. Yönetici hisse adını ve kodunu girip kaydeder. Alternatif akış: aynı kodlu bir hisse varsa sistem uyarı verir, yönetici yeni bir kod girer ve akış ilgili adımdan devam eder.

> **Hocanın vurgusu:** Kullanım senaryolarını tek tek anlatmaya gerek yok. Esas anlatılacak olan testlerdir. Test planında hangi testlerin yapıldığını özetleyin ve planladıklarınızdan en az ikisinin çalıştırılmasını gösterin.

Test planında risk yönetimi her risk için risk tanımı, etkisi, önlem stratejisi ve risk sorumlusu biçiminde yazıldı. Örneğin "gereksinimlerin belirlenmesinde gecikme" riskinin etkisi test faaliyetlerinin geç başlamasıdır. Önlem stratejisi düzenli toplantılar ve sorunların hızlı çözülmesidir (ekrandan, 01:40:00).

### 7.2 Kullanıcı testi

Kullanıcı testlerinde uygulama doğrudan kullanılarak beklenen davranış denetlendi. Örneğin ana sayfada her varlığın fiyatı ve değişim oranı listeleniyor, birine tıklanınca fiyat-zaman grafiği açılıyor. Yönetici girişinde kullanıcı ve hisse listeleri görülüyor ve yeni kayıt eklenebiliyor. Yeni bir kullanıcı oluşturulup onunla giriş yapıldı, hisse alınıp satıldı ve portföyün güncellendiği görüldü.

> **Hocanın vurgusu:** Kullanıcı testinde değerler önceden çalıştırılıp bir tabloda gösterilebilirdi: tahmin edilen değer ve gerçekleşen değer. Önceki grupların bazıları böyle yaptı.

### 7.3 Entegrasyon testi (Postman)

Birim testlerinde yetkilendirme katmanı aşılamadı, çünkü admin ve kullanıcı kimlik doğrulaması gerekiyordu. Grup bu eksiği entegrasyon testinde, uçları tek tek deneyerek kapattı. Entegrasyon testleri Postman ile yapıldı:

- Kimlik doğrulama ucuna kayıt (sign up) isteği gönderilerek yeni kullanıcı oluşturuldu.
- Kullanıcı adı ve şifreyle POST isteği gönderilerek giriş yapıldı. Başarılı girişte kullanıcı bilgileri ve bir erişim belirteci (access token) döndü.
- Yetki gerektiren her istekte bu belirteç isteğin başlığına (header) eklendi. Ön yüz de belirteci aynı şekilde gönderiyor. Belirteç yoksa istek hata veriyor.
- Hisse alma, satma, kullanıcının bütün hisseleri ve portföyü görüntülemesi, yöneticinin kullanıcıları ve hisseleri listelemesi, hisse eklemesi ve silmesi denendi.
- **Hatalı durum:** Yönetici, başka bir kullanıcının portföyünde bulunan bir hisseyi silmeye çalışınca veritabanındaki yabancı anahtar (foreign key) kısıtı yüzünden HTTP 500 (internal server error) alındı. Silmeden önce hissenin bağlı olduğu portföylerden kaldırılması gerekir.
- Hissenin tarihsel grafik verisi ucu son bir yılın günlük verisini döndürüyor: her gün için en düşük fiyat, en yüksek fiyat, açılış ve kapanış fiyatı ve hacim. Ön yüz bu veriyi grafik çizmek için kullanıyor.

**Soru (hoca):** Bu testi gerçekleştirirken hangi programdan destek aldınız? **Cevap:** Uçlar Postman ile test edildi. Uygulama IntelliJ'de yerelde çalıştırıldı ve Spring ile yazılmıştı.

## Örnek Sorular

Bu derste ekranda soru gösterilmedi. Aşağıdakiler sunumlar sırasında hocanın sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:07:22): Sistem testi olarak neyi seçtiniz: performansı mı, güvenliği mi?

> **Cevap (derste verildi):** Grup, programın birçok parçası birlikte çalıştığında düzgün ve beklenen sonucu verip vermediğini sınadı. Test, şehir ve güzergah ekleyip silerek parçaların birlikte doğru çalıştığını `assertEquals` ile denetledi.

**Soru 2** (derste sözlü, 00:12:55): Arayüzü görüntü tanıyarak otomatik kullanan bir test (SikuliX) fonksiyonel test sayılabilir mi?

> **Cevap (derste verildi):** Evet. Bu test, gereksinimlerdeki bir fonksiyonu yerine getirmek için gereken komutları hızlıca çalıştırır ve fonksiyonun dışarıdan görüldüğü haliyle tamamlanıp tamamlanmadığını sınar.

**Soru 3** (derste sözlü, 00:31:54): Kapsamın yüzde kaç olduğunu Jest mi gösteriyor?

> **Cevap (derste verildi):** Evet. Jest kapsamı deyim, dal, fonksiyon ve satır için yüzde olarak verir. Bu projede satır kapsamı %70,88'dir. Test edilmeyen satırları da listeler.

**Soru 4** (derste sözlü, 00:51:53): Özetle hangi testleri gerçekleştirdiniz?

> **Cevap (derste verildi):** Birim testleri (xUnit) ve Swagger üzerinden kullanıcı testi. Proje tanımına göre birim testi ile sistem testi ya da birim testi ile kullanıcı testi seçilebilir.

**Soru 5** (derste sözlü, 01:41:36): Entegrasyon testinden mi başladınız?

> **Cevap (derste verildi):** Hayır. Önce kullanıcı testleri, en son entegrasyon testi yapıldı.

**Soru 6** (derste sözlü, 01:49:09): Bu entegrasyon testini gerçekleştirirken hangi programdan destek aldınız?

> **Cevap (derste verildi):** Postman. İstekler uçlara doğrudan gönderildi. Yetki gerektiren isteklerde erişim belirteci başlığa eklendi.

## Dersin Toparlaması

Bu derste gruplar, bir test sürecinin bütün adımlarını gerçek projeler üzerinde gösterdi. Gereksinimler SRS'te tanımlandı. Test planında test türleri, ölçütler, roller, riskler ve efor yazıldı. Testler uygun araçlarla çalıştırılıp sonuç raporunda hata ciddiyetiyle birlikte toplandı. Araçlar dile ve platforma göre değişti: Java için JUnit 5 ve SikuliX, JavaScript için Jest, Cypress ve Lighthouse, .NET için xUnit ve C# birim testi projesi, Python servisinde birim ve entegrasyon testleri, REST uçları için Swagger ve Postman.

Sunumlarda ortak bazı kavramlar öne çıktı. Negatif test geçersiz girdide hata bekler. Parametreli testler (`[Theory]`) aynı testi birçok veriyle çalıştırır. Kapsam araçlarla ölçülür. Hatalar ciddiyete göre sınıflanır ve sistemin ana işlevini engelleyen hata en yüksek seviyede değerlendirilir. Kullanıcı testi beklenen ve gerçekleşen değerleri karşılaştıran bir tabloyla raporlanır. Hoca, testlerin yalnız raporda anlatılmasının yetmediğini, çalıştırılarak gösterilmesi gerektiğini vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
