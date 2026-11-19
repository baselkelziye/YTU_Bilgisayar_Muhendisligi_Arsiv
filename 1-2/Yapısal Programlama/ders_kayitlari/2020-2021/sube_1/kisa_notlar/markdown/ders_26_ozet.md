# Ders 26 Çalışma Özeti

<!-- Bu oturum konu anlatımı değildir. Ders müfredatı önceki hafta tamamlandığı için oturum dönem projesiyle ilgili soru-cevaba ayrıldı (ekrandan, 00:05:00). Aşağıda yalnız soru-cevaplardaki C programlama ve yazılım tasarımı içeriği yer alır. -->

## Genel Konular

- Oturumun bağlamı: dosya tabanlı kayıt sistemi projesi
  - Proje; öğrenci, ders ve öğretim üyesi bilgilerini metin dosyalarında tutan, menülü bir C programıdır. Proje metninde statik ve global değişken kullanımının yasak olduğu, her türlü bellek tahsisinin dinamik bellek yönetimi fonksiyonlarıyla yapılacağı, her dosyadaki nesne için uygun `struct` tanımlanacağı, dosyaların metin biçiminde olacağı ve benzer çalışan fonksiyonlarda tekrardan kaçınmak için fonksiyon işaretçisi kullanılacağı yazar (ekrandan, 00:10:00).
  - İstenen işlemler: her dosya için ekleme, silme, güncelleme; ID'si verilen öğretim üyesinin verdiği dersleri, ders kodu verilen derse kayıtlı öğrencileri ve numarası verilen öğrencinin aldığı dersleri listeleme; bir dersin sınıf listesini `DERSKODU_SINIFLISTESI.txt` dosyasına yazma (ekrandan, 00:10:00 ve 00:30:00).
- Girdi doğrulama ve parametre dosyası
  - Kullanıcının girdiği en çok ders sayısı ve kredi gibi değerler programın her çalışmasında farklı olabilir. Bu bir tutarsızlık değildir; aynı programın kopyaları farklı programlar (lisans, yüksek lisans, sürekli eğitim) için farklı ayarlarla çalışabilir.
  - İstenirse bu değerler ayrı bir parametre dosyasına kaydedilir; kullanıcı değiştirmedikçe program her açılışta bu parametrelerle devam eder.
  - Mantıklı kontroller: negatif kredi girilemez, sıfır ders sayısı girilemez. Ama tek derslik bir program bile olabileceği için alt sınır çok katı konmamalıdır.
- `fopen` sonrası `NULL` kontrolü
  - Dosya hangi kiple açılırsa açılsın dönüş değerinin `NULL` olup olmadığı kontrol edilmelidir. <!-- BELİRSİZ: soru "dosyayı ... ile açtığımızda kontrol gerekmez değil mi" biçiminde; kip altyazıda bozuk ("ağır tığla", "Atent ve okumak"), büyük olasılıkla a+ (ekleme ve okuma) kipi kastediliyor. -->
  - Dosyanın oluşturulamaması için nedenler: dosyayı açma yetkisi olmaması, başka bir sistemde çalışılması, dosya adında Türkçe ya da garip karakter kullanılması. Hoca bunu "Murphy kuralları her an devreye girebilir" diye özetledi.
- Sekmeyle ayrılmış metin dosyası ve Excel
  - Programın çıktısı ekrana yazdırılır; Excel dosyası üretmek beklenmez. Doğrudan Excel biçiminde yazmak o biçimin ayrıntısını bilmeyi gerektirir.
  - Pratik yol: kayıtlar metin dosyasına yazılır, alanların arasına `\t` (sekme) konur. Böyle bir dosya Excel'de "sınırlandırılmış" seçeneği ve sekme ayırıcısıyla birkaç adımda tablo olarak açılır. Hoca bunu Not Defteri ve Excel'de canlı gösterdi.
  - Açarken karakter kodlaması sorulur (UTF-8, Windows Türkçe, ISO); Türkçe karakterlerin doğru görünmesi kodlamaya bağlıdır. Tersi de yapılabilir: Excel tablosu metin olarak kaydedildiğinde alanlar noktalı virgülle ayrılır.
- Dinamik bellek: ne zaman `malloc`
  - `malloc` her değişken için değil, yalnız dinamik bellek ayırmak gerektiğinde kullanılır.
  - Projede ders, öğrenci ve öğrenci-ders ilişkisi sayıları önceden bilinmediği (n tane) için bunları `malloc` ile yönetmek en doğrusudur. Programdan çıkarken ayrılan her şey sırasıyla `free` edilir.
- Başlık dosyası ekleme: `#include <...>` ve `#include "..."`
  - Başka bir dosyadaki tanımları kullanmak için `#include` yeterlidir. Köşeli parantez (`< >`) yalnız sistem kütüphane dosyaları içindir. Tırnak (`" "`) herhangi bir konumdaki dosya içindir; bu konum genelde `.c` dosyasıyla aynı dizindir.
  - Bulunamazsa dosyayı proje dizinine kopyalamak denenir. Davranış IDE'den IDE'ye değişebilir.
  - Canlı deneme (Dev-C++): `Untitled1.c` içindeki yapı tanımları kesilip aynı dizindeki yeni `bilgi.h` dosyasına yapıştırıldı, koda `#include "bilgi.h"` eklendi ve proje sorunsuz derlendi (ekrandan, 00:20:00). Bu ekleme olmasaydı `PERSONALSTAT` türü tanınmayacak, derleme hatası alınacaktı.
  - Kaynak dosyalar paylaşılırken eklenen bütün dosyalar birlikte verilmeli, tercihen aynı dizinde tutulmalıdır. Başka dizindeki bir kod kitaplığına IDE proje ayarlarıyla bağlantı kurulduysa kod başka bilgisayarda derlenmeyebilir.
- Kayıt silme ve güncelleme: geçici dosya
  - Dosyadaki bir kaydı silmek ya da güncellemek için geçici dosya kullanmak iyi bir çözümdür: kayıtlar geçici dosyaya (değiştirilerek ya da atlanarak) yazılır, sonra asıl dosyanın yerine geçer.
  - C dosya konum göstergesini değiştirip istenen yere gelerek veri yazmaya izin verir, ama hocaya göre bu yolun taşınabilirliği daha düşüktür; kod bir sistemde çalışıp başka bir sistemde çalışmayabilir.
  - Dosyalar küçük olacağı için geçici dosyanın süre maliyeti önemsizdir. Hocanın genel önerisi: kolay ve taşınabilir yol geçici dosyadır.
- Taşınabilirlik
  - Kod Linux dağıtımlarında, Windows'ta ya da Mac'te yazılıyor olabilir, ama hangi sistemde çalıştırılacağı belli değildir. Bu yüzden taşınabilir kod yazılmalıdır.
- Dosyanın başına dönmek: `fseek`
  - Soru: `while (!feof(...))` ile dosya sonuna gelindikten sonra başa dönmek için dosyayı kapatıp açmak mı gerekir? Cevap: gerekmez, `fseek(fp, 0, SEEK_SET)` dosyanın başından 0. bayt konumuna götürür.
  - Hoca önce bunun yalnız ikili kipte geçerli olabileceğinden şüphelendi ve ders notlarına baktı. Sonuç: `fseek` metin kipinde de kullanılır. İkili kipte ofset bayt sayısıdır; metin kipinde ofset ya 0 ya da `ftell`'in döndürdüğü bir değer olmalıdır.
- Kimlik (ID) tasarımı ve log
  - Ders kodu dersin kimliği olarak kullanılıyorsa ve ders kodu güncellenirse, bu kodun geçtiği her dosyada (ilişki dosyaları dahil) güncelleme yapılmalıdır. Aynı anda birden çok müfredatın yürüdüğü senaryo ek menü, dosya ve ilişki gerektirir; projede bu açıya girilmemesi önerildi.
  - Log, bir şeyin geçmişteki ayrıntılı ayak izidir. Ders kodu değişirse logdaki eski kayıtlar eski haliyle bırakılır, "şu dersin kodu şuna değişti" diye yeni bir satır eklenir, sonraki kayıtlar yeni kodla yazılır.
  - Öğrencinin aldığı ders sayısını her seferinde ilişki/kayıt dosyasından saymak yerine bu amaçla ayrı bir dosya tutmak bir alternatiftir.
  - Derslere otomatik artan bir ID verip ders kodunu yalnız bir bilgi alanı olarak tutmak da kabul edilir; böyle tasarım kararları raporda mutlaka belirtilmelidir.
- Mevcut yapıları değiştirmek
  - Özellik eklemek için yapılar genişletilebilir, ama bu silme değil ekleme biçiminde olmalıdır; temel isterlerin üstüne konan ekler olarak düşünülmelidir.
- Adlarda boşluk
  - Adlarda boşluk yerine alt çizgi kullanmak önerilmedi; iki adı olan biri mutlaka olacağı için boşluk sorunu çözülmelidir.
  - Sabit uzunluklu bir yapı alanında (örneğin ad 20 karakter yerine, ikinin kuvveti olarak 32 karakter) boşluk sorun çıkarmaz.
  - Metin kipinde boşluk görene kadar değil, satır satır okunursa boşluk ayrı bir alan sayılmaz.
  - Arka planda boşlukları alt çizgiyle kaydedip ekranda yeniden boşluğa çevirmek de kabul edilir, ama hocaya göre gerekmez.
- Gereksinimlerin netleştirilmesi
  - Yazılım geliştirmede iletişim çok önemlidir. İsterler belirlenirken müşterinin konu uzmanıyla konuşmak, gereksinimleri netleştirmek ve süreç adımlarıyla ayrıntılandırmak gerekir. Hoca bunu binanın temelini sağlam atmaya benzetti; konunun sistem analizi ve yazılım mühendisliği derslerinde işleneceğini söyledi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Taşınabilirlik
  - Kodun hangi işletim sisteminde çalıştırılacağı belli olmadığı için taşınabilir çözümler (geçici dosya, aynı dizinde başlık dosyaları) seçilmelidir.
- Her `fopen` sonrasında `NULL` kontrolü yapılmalıdır
  - Küçük bir olasılık bile olsa dosya açılamayabilir; kontrolün zararı yoktur.
- `malloc` yalnız gerektiğinde
  - Sayısı önceden bilinmeyen kayıtlar için `malloc`, çıkışta sırasıyla `free`.
- Tasarım kararlarını belgeleme
  - Farklı bir ID yöntemi gibi her ek kararın raporda açıklanması gerekir; okuyanın kodu çözmeye çalışmasına bırakılmamalıdır.
- Log geçmişin ayak izidir
  - Eski log kayıtları değiştirilmez, değişiklik yeni satır olarak eklenir.
- Ekleme, silme değil
  - Mevcut yapılara yapılan değişiklikler var olanı kaldırmadan, üstüne katma biçiminde olmalıdır.

## Kısa Tekrar Notları

- Dosya açıldıktan sonra her zaman `if (fp == NULL)` kontrolü.
- `#include <...>`: sistem kütüphaneleri; `#include "..."`: kendi dosyaların (genelde aynı dizin).
- Yapı tanımlarını bir `.h` dosyasına taşıyıp tırnakla eklemek çalışır; `.c` ve `.h` birlikte ve aynı dizinde tutulmalı.
- Kayıt silme/güncelleme için geçici dosya: kolay ve taşınabilir.
- `fseek(fp, 0, SEEK_SET)` dosyanın başına döner; kapatıp açmak gerekmez.
- Metin kipinde `fseek` ofseti 0 ya da `ftell`'den dönen değer olmalı; ikili kipte bayt sayısı.
- Sekmeyle (`\t`) ayrılmış metin dosyası Excel'de kolayca tablo olarak açılır; kodlamaya dikkat.
- `malloc` yalnız dinamik bellek gerektiğinde; çıkışta her şey `free`.
- Ad alanlarında boşluk: sabit uzunluklu alan ya da satır satır okuma.
- Anahtar (ders kodu) değişirse ilişkili bütün dosyalarda güncelle; ya da otomatik artan ID kullan ve raporda belirt.

## Detaylı Açıklamalar

- **Oturumun niteliği.** Ders müfredatı önceki hafta bittiği için bu oturum, öğrencilerin dönem projesine dair sorularına ayrıldı (ekrandan, 00:05:00). Sorular sohbet penceresinden ve sesli geldi; cevaplar C'de dosya işlemleri, başlık dosyaları, dinamik bellek ve yazılım tasarımı üzerinde yoğunlaştı.

- **Girdi doğrulama.** En çok ders sayısı ve kredi gibi değerlerin kullanıcıdan alınması tutarsızlık yaratmaz, çünkü bu değerler müfredatla değişebilir ve programın farklı kopyaları farklı programlar için çalıştırılabilir. Değerler bir parametre dosyasında saklanabilir. Kontrol olarak negatif kredi ve sıfır ders sayısı reddedilebilir; ama tek derslik bir sürekli eğitim programı bile olabileceğinden alt sınır makul tutulmalıdır.

- **`NULL` kontrolü ve Murphy kuralları.** Bir dosya kendi bilgisayarında her zaman açılıyor gibi görünse de yetki eksikliği, başka bir sistemde çalışma ya da dosya adında Türkçe karakter gibi nedenlerle açılamayabilir. Bu yüzden her `fopen` çağrısından sonra dönüş değeri `NULL` ile karşılaştırılmalıdır.

- **Sekmeyle ayrılmış metin ve Excel.** Hoca Not Defteri'nde alanları sekmeyle ayrılmış birkaç satır yazdı, kaydetti ve Excel'de "Metin dosyası, sınırlandırılmış, ayırıcı: sekme" adımlarıyla açtı. Kodlama seçiminde UTF-8 ile Türkçe Windows/ISO kodlamalarını denedi; Türkçe karakterlerin görünümü seçilen kodlamaya göre değişti. Ayrıca Excel'de bir sütunun sayı yerine metin olarak alınması gibi seçenekler bulunduğunu gösterdi. <!-- BELİRSİZ: Not Defteri'ne yazılan örnek satırların değerleri altyazıda bozuk ("Kırk dört", "Şahıs 9"); bu anın karesi yok. -->

- **Başlık dosyası denemesi.** Hoca, önceki dersten kalan rastgele erişim örneğinin (kişi kaydı yazan program) Dev-C++ projesini açtı. Kodda `stdio.h`, `stdlib.h` ve `"bilgi.h"` eklenmiş, `main` içinde `PERSONALSTAT ps2[4]` dizisi tanımlanmış, `records.dat` dosyası `"wb"` kipinde açılmış ve döngüyle dört kişinin adı, kimlik numarası ve doğum tarihi okunup `fwrite` ile yazılmaktadır (ekrandan, 00:20:00 ve 00:25:00). Yapı tanımları (bit alanlı `DATE` ve `PERSONALSTAT`) `Untitled1.c`'den kesilip aynı dizindeki `bilgi.h` dosyasına konmuş ve derleyici "compiled successfully" mesajını vermiştir (ekrandan, 00:20:00). Yapı tanımları slayttaki biçimiyle şöyledir (ekrandan, 00:40:00):

```c
typedef struct {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
} DATE;
typedef struct {
    char ps_name[19], ps_tcno[11];
    DATE ps_birth_date;
} PERSONALSTAT;
```

- **Geçici dosya ile güncelleme.** Sorulan alternatif, dosya konum göstergesini oynatıp kaydı yerinde değiştirmekti. Hoca bunun mümkün olduğunu ama taşınabilirliğinin daha düşük olduğunu söyledi; okunan kayıtları gerekirse değiştirerek geçici bir dosyaya yazıp sonra asıl dosyanın yerine koymayı önerdi.

- **`fseek` ile başa dönme.** `fseek(fp, 0, SEEK_SET)` çağrısı konum göstergesini dosyanın başından 0. bayta taşır. Slayttaki örnekte `stat = fseek(fp, 10, SEEK_SET);` göstergeyi akıştaki 10. karaktere taşır; akışlar diziler gibi 0'dan başladığı için bu aslında 11. karakterdir. `fseek` istek geçerliyse 0, değilse sıfırdan farklı bir değer döndürür; örneğin salt okunur açılmış bir dosyada `fseek(fp, 1, SEEK_END)` dosya sonunun ötesine gitmeye çalıştığı için geçersizdir. `SEEK_END` ile ofset 0 ya da negatif, `SEEK_SET` ile 0 ya da pozitif olmalıdır (ekrandan, 00:45:00). Metin kipinde ofset ya 0 ya da `ftell`'in döndürdüğü değer olmalıdır.

- **ID ve log tasarımı.** Ders kodu birincil anahtar olarak kullanılırsa kod değişikliği bütün ilişki dosyalarına yansıtılmalıdır. Log dosyası ise geçmişi değiştirilmeden tutar; değişiklik yeni bir satırla kaydedilir. Ders kodunu bir bilgi alanı yapıp otomatik artan bir ID kullanmak da kabul edilir; böyle kararlar raporda açıklanır.

- **Gereksinim mühendisliği.** Proje isterleri belirsiz göründüğünde soru sormak, gerçek yazılım süreçlerindeki analiz ekibi ile müşteri arasındaki iletişimin küçük bir örneğidir. Gereksinimlerin net belirlenmesi binanın temelini sağlam atmaya benzer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
