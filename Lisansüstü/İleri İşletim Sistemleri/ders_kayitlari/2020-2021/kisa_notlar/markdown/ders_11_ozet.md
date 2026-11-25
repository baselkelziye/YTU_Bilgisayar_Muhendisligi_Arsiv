# Ders 11 Çalışma Özeti

## Genel Konular

- Ders bir makale tartışması biçiminde işlendi
  - Üç makale tartışıldı: "IO-Lite: A Unified I/O Buffering and Caching System", LOCUS dağıtık işletim sistemi makalesi ve "The ITC Distributed File System: Principles and Design" (AFS olarak da bilinir).
  - Hoca makaleler üzerine sorular sordu, öğrenciler cevapladı; hoca cevapları düzeltip makaleden ilgili cümleleri sesli okudu.
  - Kayıt Zoom konuşmacı görünümündeydi, ekranda slayt ya da makale paylaşımı görünmedi. Bu yüzden içerik altyazıdan alındı; hocanın makaleden okuduğu cümleler İngilizce korunmuştur.
- IO-Lite: birleşik G/Ç tamponlama ve önbellekleme
  - Temel fikir değiştirilemez (immutable) tamponlardır: tampona veri bir kez yüklendikten sonra içeriği bir daha değiştirilmez, tampon salt okunur (read-only) olur.
  - Değiştirilemez tamponlar, işletim sistemi alt sistemleri ve uygulamalar arasında senkronizasyon, koruma, tutarlılık ve hata yalıtımı (fault isolation) sorunlarını ortadan kaldırır.
  - Unix türevi sistemlerdeki tamponlama mekanizmalarının üç temel sorunu: gereksiz veri kopyalama (redundant data copying), çoklu tamponlama (multiple buffering) ve alt sistemler arası optimizasyon eksikliği (lack of cross-subsystem optimization).
  - Erişim denetimi ve koruma süreç (process) çözünürlüğündedir (granularity of processes).
  - Ağ tarafında sürücülerin güncellenmesi gerekir: gelen paketin hangi uygulamaya ait olduğu paket başlığından, paket filtresiyle erken belirlenir (early demultiplexing).
  - Değiştirilemezliğin bedeli: bir veriyi değiştirmek isteyen program yeni değeri yeni ayrılmış bir tampona yazmak zorundadır. Makale üç durumu inceler.
- LOCUS dağıtık işletim sistemi
  - Ağdaki birden çok makinenin kullanıcıya tek bir işletim sistemi gibi görünmesini sağlar (yüksek şeffaflık).
  - En çok üzerinde durulan konu çoğaltmadır (replication): esnek, mümkünse kullanıcı müdahalesi olmadan otomatik, temelde dosya düzeyinde.
  - Çoğaltmada öne çıkan ilke işlemsel bütünlüktür (transactional integrity); makale iç içe işlemleri (nested transactions) de destekler.
  - Bedeli: LOCUS Unix'ten yaklaşık üçte bir daha büyük ve daha karmaşıktır.
- ITC dağıtık dosya sistemi (AFS)
  - Carnegie Mellon Üniversitesi için, çok sayıda kullanıcı ve iş istasyonu düşünülerek tasarlandı.
  - Dağıtık sistemleri üç sınıfa ayırır: dağıtık işletim sistemleri, dağıtık dosya sistemleri, gevşek bağlı ağlar (loosely coupled networks, örnek ARPANET).
  - Dosya sistemi hedefleri arasında konum şeffaflığı, kullanıcı hareketliliği, erişilebilirlik, bütünlük ve heterojenlik sayıldı.
  - Vice (sunucu tarafı, güvenilirlik sınırı) ve Virtue (iş istasyonu tarafı) yapısı; küme sunucuları (cluster server) birleşerek Vice'ı oluşturur.
  - Tasarım ilkeleri, yerel tutulacak dosya türleri, mimariye göre ayrılmış ikili dosyalar, koruyuculuk (custodianship) ve güvenlik ihlali sınıflandırması tartışıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- IO-Lite'ın "hafif" olmasının anahtarı tampon yapısıdır
  - Hoca bunu "çok anahtar bir şey" olarak sordu; cevap değiştirilemez tamponlardır. Veri tek bir tampondan, kopyalanmadan, onu kullanacak yere verilir.
- Dosya sistemi ile ağ arasındaki fark
  - Dosya sisteminde nereden okunacağı ya da nereye yazılacağı çağrı sırasında bellidir.
  - Ağda gelen paketin hangi uygulamaya ait olduğu ancak paket incelenerek (TCP/IP'de port numarası) çözülebilir. Bu yüzden normal sürücüler donanım tamponu, çekirdekte inceleme tamponu ve uygulama tamponu olmak üzere birden çok kopya oluşturur.
  - IO-Lite için sürücü, erişim denetimini yapacak ve ara tampona kopyalamayı kaldıracak biçimde güncellenmeli; mümkünse veri ağ arayüzünün donanım tamponundan doğrudan ilgili uygulamaya aktarılmalıdır.
- "Nothing is free" (LOCUS sonucu)
  - Kaynaklar yerelken performans kaybını önlemenin bedeli ek kod ve uygulamada büyük özendir. Hoca "üçte bir büyük" ifadesini "Unix 1 ise LOCUS yaklaşık 1,33" diye açıkladı ve bir öğrencinin "üç katı" yorumunu düzeltti.
- İç içe işlemler ve çoğaltma
  - Dosyanın birden çok kopyası otomatik olarak tutarlı tutulurken üstte iç içe geçmiş işlemler olabilir; işlem sınırlarında (transaction boundary) çoğaltmayı yapıp tutarlılığı korumak asıl problemdir.
- Konum şeffaflığı
  - Kullanıcı yalnız dosyanın adını verir, dosyanın hangi makinede olduğunu kullanıcı değil dosya sistemi çözer. Bugünkü URL'ler konum bilgisi içerdiği için bu anlamda konum şeffaflığı sağlamaz.
- Vice güvenilirlik sınırıdır
  - İş istasyonu üzerindeki bütün denetim kullanıcıdadır, bu yüzden iş istasyonuna güvenilmez; ortak güven ilişkisi Vice denen ortak omurga üzerinden kurulur.

## Kısa Tekrar Notları

- IO-Lite: immutable buffer = içerik bir kez yazılır, sonra salt okunur.
- Immutable buffer şunları çözer: senkronizasyon, koruma, tutarlılık, hata yalıtımı.
- Unix tamponlamasının üç sorunu: gereksiz kopyalama, çoklu tamponlama, alt sistemler arası optimizasyon eksikliği.
- IO-Lite erişim denetimi: süreç çözünürlüğünde.
- Early demultiplexing: paket başlığından, paket filtresiyle hedefin erken belirlenmesi.
- Değişiklik durumları: verinin tamamı değişir; bir alt kümesi değişir; değişiklikler veriye dağılmıştır.
- Değiştirilemezliğin dezavantajı: değişiklik için yeni tampon ve kopyalama maliyeti.
- LOCUS: ağ şeffaf dağıtık işletim sistemi; otomatik, dosya düzeyinde çoğaltma; işlemsel bütünlük, iç içe işlemler.
- LOCUS ≈ Unix'in 1,33 katı büyüklükte; donanım tek tipe yaklaştırıldı (PDP-11'ler devre dışı bırakıldı).
- ITC/AFS: üç sınıf (dağıtık İS, dağıtık dosya sistemi, gevşek bağlı ağ); hedefler arasında konum şeffaflığı, kullanıcı hareketliliği, erişilebilirlik, bütünlük, heterojenlik.
- Vice = Vast Integrated Computing Environment, sunucu tarafı ve güvenilirlik sınırı; Virtue = iş istasyonu tarafı.
- Yerelde kalabilecek dosyalar: açılış için gereken sistem dosyaları, geçici dosyalar, özel dosyalar, sık kullanılan ama az güncellenen programlar.
- Custodian: bir dosyanın saklanmasından, çoğaltılmasından ve erişim koordinasyonundan sorumlu sunucu.
- Güvenlik ihlali sınıfları: yetkisiz bilgi açığa çıkması, yetkisiz bilgi değiştirilmesi, kaynak kullanımının engellenmesi (bugünkü hizmet reddinin karşılığı).

## Detaylı Açıklamalar

- IO-Lite ve değiştirilemez tamponlar
  - IO-Lite'ta tampona veri bir kez yüklendikten sonra içeriği değiştirilmez. Tampon salt okunur olduğu için alt sistemler ve uygulamalar aynı tamponu kilitlemeye ya da birbirinden korumaya gerek duymadan paylaşabilir. Bir öğrencinin cevabına göre makale bunu "synchronization, protection, consistency, and fault isolation" sorunlarının çözümü olarak sunar.
  - Çoklu tamponlama, aynı verinin birden çok yerde ayrı ayrı tamponda tutulmasıdır. Derste verilen örnekte bir web sunucusu, her kullanıcı için ayrı tampon oluşturmak yerine ortak veriyi tek bir tamponda tutar.
  - Erişim denetimi süreç düzeyinde yapılır. Makalenin 2.3 numaralı "Access Control and Allocation" bölümünde "IO-Lite ensures access control and protection at the granularity of processes" yazar. Granularity burada çözünürlük, yani işin hassasiyeti demektir.
  - Makale "IO-Lite and the File System" ve "IO-Lite and the Network" diye iki ayrı başlık açar. Dosya sisteminde okunacak ya da yazılacak yer çağrı sırasında bellidir. Ağda ise paketin sahibi paket gelince çözülmelidir. Bu yüzden sürücüler, gelen paketlerin başlıklarından paket filtresi kullanarak hedefi belirlemelidir; makale bu işleme erken çoklama çözme (early demultiplexing) der. Hoca bunun donanım düzeyinde yapılarak işin hızlandırıldığını belirtti.
  - Değiştirilemezliğin etkisi makalenin 2.8 numaralı "Impact of Immutable I/O Buffers" bölümündedir. Bir program bir veri nesnesini değiştirmek isterse yeni değeri yeni ayrılmış bir tampona yazar. Üç durum vardır:
    - Verinin her sözcüğü değişir. Hoca örnek olarak tamponun şifrelenmesini ya da üzerinden sağlama toplamı (checksum) hesaplanmasını verdi. Bu durumda zaten yeni tampon gerekir.
    - Verinin yalnız bir alt kümesi değişir. Değişmeyen kısım aynı tutulur, değişen kısımlar bağlı liste (chaining) mantığıyla birleştirilir.
    - Değişiklikler verinin pek çok farklı yerine dağılmıştır. Hoca bunun günlük hayatta karşılaşılan bir durum olduğunu söyledi.
  - Makalede ayrıca HTTP örneği, istek miktarı ve geniş alan ağı (wide area) etkisi üzerinden ayrıntılı bir performans analizi olduğu belirtildi; derste ayrıntısına girilmedi.
- LOCUS
  - LOCUS ağ üzerindeki birden çok makinenin tek bir işletim sistemi gibi birlikte çalışmasını sağlar. Sistem geniş bir ağa yayıldığı için kopyalar hem erişilebilirlik (biri bozulunca diğerinin hizmet vermesi) hem de performans (en yakın kopyanın sunulması) açısından önemlidir.
  - Çoğaltma esnek ve mümkünse hiç kullanıcı müdahalesi olmadan otomatik olmalıdır. Çoğaltma birimi temelde dosyadır, bunun için çekirdek tarafı da işin içindedir.
  - Çoğaltmada ön planda tutulan şey işlemsel bütünlüktür: işlemin bir kısmının gerçekleşip bir kısmının gerçekleşmemesi kabul edilmez. Makale iç içe işlemleri de destekler. Bir öğrenci commit edilmeyen değişikliğin kopyalara da yansımadığını belirtti.
  - Makalenin sonuç bölümünden: "Nothing is free. In order to avoid performance degradation when resources are local, the cost has been converted into additional code and substantial care in implementation architecture." ve "LOCUS is approximately a third bigger than Unix and certainly more complex." Dinamik yeniden yapılandırmada kilit tablolarını yeniden kurmak ve ayrı ortamlarda çalışan süreçleri senkronize etmek doğası gereği zor problemlerdir.
  - Farklı donanımlar (heterojenlik) büyük bir sorundu; dizin adlandırması bile sorun çıkarıyordu. Sistem devreye alınmadan önce PDP-11'ler devre dışı bırakıldı ve donanım daha tek tip bir yapıya getirildi.
  - Hocanın okuduğuna göre çalışma 1979'da başlayıp 1983 başında bitti ve yaklaşık 50 adam-yıl emek harcandı. Hoca adam-yılı "bir kişi 50 yıl ya da 50 kişi bir yıl" diye açıkladı.
  - Makalenin son cümlesi, dosya etkinliği işletim sistemi işinin baskın kısmı olduğu için dağıtık dosya sistemi tabanı üzerine kurulan LOCUS mimarisinin çekici olduğunu söyler. Hoca bugün ise dosya sistemlerinin çoğunlukla merkezi bir noktaya taşındığını hatırlattı.
- ITC dağıtık dosya sistemi (AFS)
  - Makale 1985 tarihlidir. Carnegie Mellon Üniversitesi'nde çok sayıda kullanıcı ve bilgisayar olduğu için esnek ve kullanıcı hareketliliğini destekleyen bir sistem hedeflenmiştir.
  - Gevşek bağlı ağ örneği olarak ARPANET verilir. Orada kullanıcı FTP gibi araçlarla dosyanın yerel kopyasını kendisi oluşturur, kopyalar birbirinden bağımsızdır ve şeffaflık yoktur. Çok kullanıcılı bir ortamda bu sorumluluğu kullanıcıya bırakmak kaosa yol açar.
  - Konum şeffaflığı: paylaşılan dosyalar tek bir ad alanında bulunur, dosya adından dosyanın hangi bilgisayarda olduğu anlaşılmaz ve dosyanın yerini kullanıcı değil sistem bulur. Hoca DNS sorusuna, kaynağı bir makineye sabitlemek yerine en yakın kopyaya yönlendirme örneğiyle (coğrafi konuma göre en yakın sunucuya yönlendirme) cevap verdi.
  - Heterojenlik: farklı yapılandırmalı ve farklı işlemcili istasyonların aynı sisteme katılabilmesi.
  - Şekil 2.1'de ortada Vice yazan bir bulut vardır ve "Vice is the boundary of trustworthiness" denir. İş istasyonları kümeler oluşturur, her kümenin bir küme sunucusu vardır; küme sunucuları köprülerle bağlı omurga Ethernet üzerinden birleşerek Vice'ı oluşturur. Başlangıçta 5000 kişisel iş istasyonundan söz edilir. Trafiğin şifrelenmesi ve iş istasyonlarının yerel disk yerine uzak disk kullanması da tartışılır.
  - Bir öğrenci yapıyı eşler arası (peer-to-peer) olarak görmeyi önerdi; hoca bunun çok kısıtlayıcı olacağını, yapının çoktan çoğa (M'ye N) ilişki gibi düşünülmesi gerektiğini söyledi.
  - Tasarım ilkeleri (bir öğrencinin aktardığı biçimiyle): işi mümkünse iş istasyonunda yap, mümkünse yerelleştir, sınıfa özgü dosya özelliklerinden yararlan (ör. salt okunur dosyalar kopyalanabilir), mümkünse önbelleğe al, sık ve sistem çapında değişiklikten kaçın.
  - Yerelde kalabilecek dosyalar: iş istasyonunun açılması için gereken sistem dosyaları, derleme sırasında oluşan geçici dosyalar, paylaşılmak istenmeyen özel dosyalar (bunlar kullanıcı hareketliliğini kısıtlar), sık kullanılan ama az güncellenen programlar (derleyici, editör). Şekil 3.1 bunu bir Venn diyagramıyla gösterir. Şekil 3.2'de Vice bir bağlama noktasıdır (mount point); Sun ve VAX mimarileri için ikili dosyalar ayrı dizinlerdedir.
  - Koruyuculuk (custodianship): bir dosyanın nerede saklandığından, nasıl çoğaltıldığından ve erişimin nasıl koordine edildiğinden sorumlu sunucu onun koruyucusudur. Koruyucusu olmadığı bir dosya için istek alan sunucu uygun koruyucunun kimliğini döndürür. Bir alt dizin altındaki dosyaların koruyucusu aynıysa bilgi yalnız alt dizin için tutulur.
  - Güvenlik: makale Voydock ve Kent'e dayanarak ağdaki güvenlik ihlallerini yetkisiz bilgi açığa çıkması, yetkisiz bilgi değiştirilmesi ve kaynak kullanımının engellenmesi (denial of resource usage) olarak sınıflandırır. Hoca sonuncusunun bugünkü hizmet reddi (denial of service) kavramına karşılık geldiğini vurguladı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
