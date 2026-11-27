# Ders 12 Çalışma Özeti

## Genel Konular

- Dönem projesi sunumları ve hocanın geri bildirimleri
  - Bu derste öğrenci grupları dönem boyunca geliştirdikleri bilgi sistemi projelerini sundu. Sunumlar genelde ekip yapısı, toplantılar, fizibilite, Gantt diyagramı, sistem analizi, sistem tasarımı, veri tabanı ve çalışan uygulamanın gösterimi bölümlerinden oluşuyordu.
  - Hoca sunumların arasına girerek her gruba kısa düzeltmeler yaptı ve bunların bütün gruplar için geçerli olduğunu söyledi. Dersin akademik değeri bu düzeltmelerde ve ekranda gösterilen diyagram örneklerindedir.
  - Sunulan sistemler: market fiyat karşılaştırma sistemi, hayvanat bahçesi bilgi sistemi, otel bilgi sistemi, yemek sipariş sistemi, dijital oyun abonelik sistemi, konfeksiyon deposu yönetim sistemi, online tren bileti sistemi ve kütüphane otomasyon sistemi.
- Fizibilite çalışmasından beklenenler
  - Fizibilite hızlı ve özet geçilmemeli; alternatifler karşılaştırılmalı ("neden Java, neden bu veri tabanı" gibi bir karşılaştırma matrisi). Amaç "bunu nasıl ve en iyi nasıl yaparız" sorusunu cevaplamaktır.
  - Ekonomik fizibilitede gelir belirsiz olsa bile sistemin sağlayacağı maliyet faydası ve verim artışı analiz edilmelidir.
  - Sunumlarda görülen fizibilite türleri: teknik (dil, veri tabanı, donanım, sunucu), ekonomik (personel maliyeti, sunucu kirası, gelir modeli), sosyal, yasal (kişisel verilerin korunması, lisanslar, gizlilik sözleşmesi), zaman (Gantt) ve yönetim fizibilitesi.
- Gereksinim toplama ve analiz modeli
  - Son kullanıcıya hitap eden bir sistemde gereksinimler anket gibi bir veri toplama yöntemiyle ortaya konmalı; use case'lerin nasıl bulunduğu gösterilmelidir.
  - Use case diyagramı tek başına yetmez; her kullanım durumunun metni (senaryosu) da verilmelidir.
  - Fizibilite çalışması ile sistem analizi ayrı konulardır; birleştirilmemelidir.
- Yapısal ve nesneye yönelik çözümleme
  - Ödevde iki yaklaşımdan biri istenmişti; birini seçmek yeterlidir. İkisini birden yapmak gereksiz iş yüküdür.
  - Nesneye yönelik bir projede veri akış diyagramı çizip sonra sınıf diyagramına geçmeye çalışan bir grup bunun zorluğunu yaşadığını anlattı.
- Diyagram hataları ve düzeltmeleri
  - Kavramsal sınıf diyagramında davranış (metot) yer almaz; analizde yalnız kavramlar ve aralarındaki ilişkiler çıkarılır. Metotları ve sorumlulukları olan diyagram, tasarımın sonunda oluşan yazılım sınıf diyagramıdır.
  - Veri akış diyagramında oklar eylem değil veri taşır. "Bilet al", "maaş güncelle", "hayvan ekle" gibi fiil içeren adlar yanlıştır; doğrusu "para", "bilet", "hayvan bilgisi" gibi veri adlarıdır (ekrandan, 00:20:00).
  - Veri tabanı yönetim aracının ürettiği tablo görünümü (database dump) ER diyagramı değildir. ER diyagramında ilişkiler eşkenar dörtgenle (baklava) gösterilir; özellikle N-N ilişkiler tablo görünümünde izlenemez (ekrandan, 00:25:00).
- Ekrandan diyagram örnekleri
  - ER diyagramı (Chen gösterimi): konfeksiyon deposu sisteminde User, Branch, Store, Storeproduct, Product, Approval varlıkları ve zayıf varlık Salerecords; ilişkiler "has" baklavasıyla ve 1-N kardinaliteyle (ekrandan, 01:10:00).
  - Tren bileti sisteminde Sefer ve Guzergahlar varlıkları ile çift çizgili "Seferler" ilişkisi (ekrandan, 01:25:00).
  - UML sınıf diyagramı: kütüphane sisteminde Account, Librarian, Member, Book, BookItem, BookBorrowing sınıfları; kalıtım (Extends) ve 1 - 0..5 çokluklu ilişkiler (ekrandan, 01:40:00).
  - Ardışıl (sequence) diyagramı: bir ürün sınıfının yapıcısı, get ve set metot çağrıları (ekrandan, 00:50:00).
  - İkinci düzey veri akış diyagramı: otel sisteminde "oda rezervasyonu" işleminin alt işlemleri (ekrandan, 00:40:00).
  - Gantt diyagramları: görev, süre, başlangıç, bitiş, öncül, kaynak ve maliyet sütunları (ekrandan, 00:45:00 ve 01:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Fizibilitede karşılaştırma
  - Hoca birçok grupta karşılaştırmalı bir fizibilite görmediğini söyledi. Fizibilitede seçeneklerin karşılaştırıldığı bir matris beklenir.
- Veri akışları eylem değildir
  - Hoca bu hatayı "gözden kaçırmayın, bir daha dikkat edin" diye vurguladı. Ok üzerinde çek, ekle, yap, yaz, et gibi fiiller yazılmaz.
- Veri tabanı görünümü ER diyagramı değildir
  - Hoca, çalışma hayatında da ER denince sık sık bu tablo görünümünün verildiğini, ama bunun ER diyagramı olmadığını özellikle belirtti.
- Kavramsal sınıf diyagramında metot olmaz
  - Analizde davranışlar henüz bilinmez; davranış ve sorumluluklar tasarımda ortaya çıkar.
- Gereksinimlerin kaynağı gösterilmeli
  - Müşteriyle sohbet şeklinde görüşülse bile hangi verilere ulaşıldığı ve gereksinimlerin, use case'lerin nasıl oluştuğu rapora konmalıdır.
- Sunum dinleyicilere yapılır
  - Sunum yalnız hocaya değil bütün sınıfa anlatılır.

## Kısa Tekrar Notları

- Fizibilite: alternatifleri karşılaştır, seçimi gerekçelendir; ekonomik fizibilitede maliyet-fayda ve verim artışını analiz et.
- Fizibilite ≠ sistem analizi.
- Gereksinim toplama (anket, görüşme) ve use case metinleri analiz modelinin parçasıdır.
- Yapısal ya da nesneye yönelik çözümlemeden birini seç.
- Kavramsal sınıf diyagramı: kavramlar + ilişkiler, metot yok.
- VAD okları veri taşır, eylem değil.
- ER diyagramı: varlık (dikdörtgen), nitelik (elips), ilişki (eşkenar dörtgen), kardinalite. Tablo görünümü ER değildir.
- Zayıf varlık çift çerçeveli dikdörtgenle, birincil anahtar altı çizili nitelikle gösterilir.
- UML sınıf diyagramında kalıtım içi boş üçgen okla, çokluk (1, 0..5) ilişki uçlarında gösterilir.

## Detaylı Açıklamalar

- Bu ders, dönem projelerinin sunulduğu iki haftadan biridir. Hocanın geri bildirimleri, dönem boyunca anlatılan analiz ve tasarım kurallarının pratikte nasıl yanlış uygulanabildiğini gösterir. En sık görülen hata fizibilitenin özet geçilmesidir: hangi dilin, veri tabanının ya da donanımın neden seçildiği alternatiflerle karşılaştırılmadan yalnız sonuç yazılmıştır. Ekonomik fizibilitede gelir tahmin edilemese bile sistemin kullanıcıya ya da işletmeye sağlayacağı maliyet faydası ve verim artışı değerlendirilmelidir.
- Analiz aşamasında gereksinimlerin nereden geldiği gösterilmelidir. Son kullanıcıya hitap eden bir fiyat karşılaştırma uygulamasında kullanıcıların neyi önemsediği (fiyat, kalite, yüksek puan gibi) bir anketle toplanabilir. Use case diyagramı yalnız aktörleri ve kullanım durumlarının adlarını gösterir; her kullanım durumunun senaryo metni (aktörler, ön koşul, temel akış, alternatif akışlar) ayrıca yazılmalıdır. Kütüphane sistemi sunumunda bir kullanım senaryosu bu biçimde verildi: üye giriş yapar, kitap müsaitse ödünç alır; alternatif akışta üyelik bilgisi yanlışsa, kitap bulunamazsa ya da üye alabileceği en fazla kitap sayısına ulaştıysa sistem hata mesajı verir.
- Kavramsal sınıf diyagramı analizin ürünüdür ve yalnız kavramları ve ilişkilerini içerir. Davranışlar (metotlar) tasarımda, nesnelerin nasıl iş birliği yapacağı belirlendikten sonra ortaya çıkar. Bu yüzden metotlarla dolu bir diyagram kavramsal değil, yazılım (tasarım) sınıf diyagramıdır.
- Veri akış diyagramında bir ok, bir yerden başka bir yere akan veriyi gösterir. Hayvanat bahçesi sisteminin taslak diyagramında oklar "Bilet Al", "Bakiye Ekle", "Maaş Güncelle", "Hayvan Ekle/Güncelle", "Kullanıcı Bilgisi Çek" diye adlandırılmıştı (ekrandan, 00:20:00). Hoca bunların eylem olduğunu, doğrusunun müşteriden sisteme "para", sistemden müşteriye "bilet", çalışandan sisteme "hayvan bilgisi" gibi veri adları olduğunu açıkladı.
- ER diyagramı ile veri tabanı tablo görünümü farklıdır. Bir grup, veri tabanı yönetim aracında tabloları, alanları ve anahtar simgelerini gösteren görünümü (EmployeeShift, VisitedCage, Cage, Customer, Animal, CustomerTimeLog, Employee tabloları) ER diyagramı olarak sundu (ekrandan, 00:25:00). Hoca bunun bir "database dump" görünümü olduğunu, ilişkilerin ve niteliklerin bu görünümde düzgün izlenemediğini, N-N ilişkiler için oluşturulan ilişki tablosunun burada sıradan bir tablo gibi göründüğünü, oysa ER'de ilişkinin baklava biçiminde görülmesi gerektiğini söyledi. Doğru gösterime örnek, konfeksiyon deposu sisteminin Chen gösterimli ER diyagramıdır (ekrandan, 01:10:00).
- Bir grup hem yapısal (VAD, veri sözlüğü, yapı diyagramı) hem nesneye yönelik (use case, sınıf, ardışıl diyagram) çözümlemeyi birlikte yapmıştı. Hoca ödevde ikisinden birinin istendiğini, birinin yeterli olduğunu belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
