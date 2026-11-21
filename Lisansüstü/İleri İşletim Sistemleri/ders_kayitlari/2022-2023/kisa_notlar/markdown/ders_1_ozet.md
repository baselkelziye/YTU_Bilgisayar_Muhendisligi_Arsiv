# Ders 1 Çalışma Özeti

## Genel Konular

- İşletim sisteminin bilgisayar sistemindeki yeri
  - İşletim sistemi altta donanım, üstte uygulamalar olan katmanlı yapının tam ortasında durur.
  - Üstteki uygulamalar sistem uygulamaları (ör. veri tabanı, web uygulama sunucusu) ya da son kullanıcıya hitap eden uygulamalar olabilir.
  - Donanım ile uygulamalar arasındaki etkileşimi, koordinasyonu, kaynak yönetimini ve verimli çalışmayı işletim sistemi sağlar.
  - Bu rol sunucu, dizüstü/masaüstü bilgisayar, cep telefonu ve gömülü sistemler için aynı şekilde geçerlidir.
- İşletim sisteminin bilgisayar mühendisliğinin temel konularıyla ilişkisi
  - Veri yapıları: çalışan programlara karşılık gelen proseslerin listesi verimli bir veri yapısıyla tutulmalı, liste içinde hızlı hareket edilebilmelidir.
  - Bellek yönetimi: belleğin hangi kısmının hangi prosese ait olduğu da bir veri yapısıyla tutulur.
  - Programlama dilleri: bir program parçasından diğerine geçerken eski programın durumunun kenara kaydedilmesi, yenisinin bilgilerinin yüklenmesi ve yığın (stack) alanının ilklendirilmesi, programlama dilinin çalışma modelini bilmeyi gerektirir.
  - Algoritmalar ve en alt seviyede assembly programlama ile donanım bilgisi de bu konulara dokunur.
- İşletim sistemi bir aracı ve kaynak yöneticisidir
  - İşletim sistemi de bir programdır; işlemci ve bellek ihtiyacı vardır.
  - Kaynakların büyük kısmını diğer programların proseslerine bırakmalıdır. İşlemci gücünün ya da belleğin tamamını kendisi kullanırsa program çalıştırmaya yer kalmaz.
  - Varlığını çok hissettirmemelidir. Örneğin bir disk okuma/yazma işleminin bittiğini bildiren donanım kesmesi (interrupt) geldiğinde, bu işlemi bekleyen program en kısa sürede haberdar edilip kaldığı yerden devam ettirilmelidir.
  - Kendisi de işlemcide çalışan bir kod parçası olmasına rağmen bu işleri en az gecikmeyle yapmalıdır.
- Ders kapsamındaki konu alanları
  - İşlemci yönetimi, bellek yönetimi, çevre birimi yönetimi.
  - Birden fazla işlemcinin birlikte çalışması.
  - Proses yönetimi; prosesin çalışırken durdurulup yeniden çalıştırılması ve çalışma sıralarının verimli belirlenmesi (zamanlama).
  - Prosesin bir sistemden başka bir sisteme göç ettirilmesi (process migration).
  - Prosesler arası haberleşme ve senkronizasyon.
  - Sanallaştırma: tam sanallaştırma (virtualization), para-sanallaştırma (paravirtualization), diğer teknikler ve container yapıları.
  - Koruma (protection) ve güvenlik (security).
- Dersin yöntemi: temel makaleler üzerinden ilerlemek
  - Temel kavramlar hoca tarafından motamot anlatılmaz; konuların defakto standartlarını oturtan, alanın uzmanı kişilerin yazdığı makaleler incelenir.
  - Hoca bu amaçla 40 küsur makale seçmiştir. Bu makaleler konuların ortaya çıkışını, araştırmaları, sonuçları, tartışmaları ve tasarım kararlarını içerir.
  - Makaleler okunup değerlendirilir ve derste soru-cevap biçiminde tartışılır; hoca moderatör olur.
- Bilimsel makale nasıl okunur
  - Abstract: makalenin neyle ilgili olduğunu, neyin incelendiğini ve hedefini kısaca özetler.
  - Introduction: konuya genel giriş, problemin tanımı ve öneminin ortaya konması.
  - Related Work: öncül çalışmalar. Bu dersteki makalelerin çoğu konunun ilk çalışmaları olduğundan bu bölüm az olur ya da hiç olmaz.
  - Teorik inceleme, ona dayanan deneyler, elde edilen sonuçlar ve hangi yaklaşımın hangi durumda daha iyi olduğuna dair yorumlar.
  - Future work: tek çalışmada bütün sorular cevaplanamaz; açık kalan problemler belirtilir.
  - Değerlendirmede sorulacak sorular: makalenin amacı ne, kapsamı ne (nelere dokunmuş), ne elde etmiş, amacı ne ölçüde çözmüş, çözülmesi gereken başka şey kalmış mı?
  - Okuma sırası: başlangıçta yukarıdan aşağı (top-down); konuya hakim olunca önce referanslardan başlayarak aşağıdan yukarı (bottom-up) okunabilir.
- Uygulama projesi fikirleri (derste örnek olarak verilenler)
  - Linux üzerinde, iki sanal makine (VM) arasında bir prosesin A'da durdurulup B'ye göç ettirilmesi ve B'de çalıştırılması.
  - Kesme (interrupt) mekanizmaları, kesme önceliklerinin çözülmesi ve kesme gecikmesinin (latency) en aza indirilmesi.
  - Unix ve Windows dosya sistemlerinin performansı: okuma/yazma, büyük/küçük dosya, sıralı/rastgele erişim.

## Hocanın Özellikle Vurguladığı Kısımlar

- İşletim sistemi bilgisayar mühendisliğinin merkezinde durur
  - Hem donanım ile uygulamalar arasında köprü olduğu hem de veri yapıları, algoritmalar ve programlama dilleri gibi temel konuların doğrudan uygulandığı yer olduğu için önemlidir.
- İşletim sistemi kendini hissettirmeyen bir aracı olmalıdır
  - Kaynakları kendisi tüketmemeli, olaylara (ör. kesmeler) en az gecikmeyle tepki vermelidir.
- Lisansüstü ders, lisans dersinden farklıdır
  - Lisansta bilgi daha çok aktarılır ve öğrenci yönlendirilir. Burada amaç bilimsel yayın okuma, araştırma ve yorumlama yeteneğini geliştirmektir.
  - Dersin şekillenmesini öğrencinin makaleleri okuyup anlaması ve yorumlaması sağlar.
- Linux bu tür çalışmalar için tercih edilir
  - Çekirdek kaynak koduna kadar her şeye erişilebildiği için deneysel işletim sistemi çalışmaları Linux'ta daha kolaydır.
- İstek karakteristiği performansı belirler
  - Dosya sistemine gelen istek modeli bir veri tabanında, bir web sunucusunda ve sıradan bir kullanıcıda farklıdır; dosya sistemi performansı bu farklara göre değişir.

## Kısa Tekrar Notları

- İşletim sistemi: donanım ile uygulamalar arasında aracı ve kaynak yöneticisi.
- Kaynakların çoğunu uygulamalara bırakmalı; kendi yükü düşük olmalı.
- Kesme geldiğinde bekleyen proses en az gecikmeyle uyandırılmalı.
- Proses listesi ve bellek sahipliği tabloları veri yapısı tasarımı ister.
- Bağlam değişiminde durum kaydedilir, yeni prosesin bilgileri yüklenir, stack ilklendirilir.
- Konu alanları: işlemci, bellek, çevre birimi, çok işlemcili sistemler, proses yönetimi ve zamanlama, proses göçü, IPC, senkronizasyon, sanallaştırma (tam, para, container), koruma, güvenlik.
- Makale yapısı: abstract, introduction, related work, teori ve deney, sonuçlar ve yorum, future work.
- Makale değerlendirme soruları: amaç, kapsam, sonuç, amaca ne kadar ulaşıldığı, açık kalan sorunlar.
- Okuma stratejisi: top-down ya da referanslardan başlayan bottom-up.

## Detaylı Açıklamalar

- Bu ilk ders, dersin konusunu ve yaklaşımını tanıtan bir giriş dersidir. Hoca işletim sistemini katmanlı bir yapının ortası olarak tanımladı: altta donanım, üstte ise veri tabanı ya da web uygulama sunucusu gibi sistem uygulamaları ve son kullanıcı uygulamaları vardır. Bu iki taraf arasındaki etkileşimi, koordinasyonu ve kaynak yönetimini sağlayan parça işletim sistemidir. Bu durum sunucudan cep telefonuna, gömülü sistemlere kadar her bilgisayar sistemi için geçerlidir.
- İşletim sistemi bilgisayar mühendisliğinin temel konularının birleştiği yerdir. Çalışan programlara karşılık gelen prosesler bir listede tutulur ve bu listenin verimli yönetilmesi bir veri yapısı problemidir. Belleğin hangi bölümünün hangi prosese ait olduğu yine bir veri yapısında saklanır. Bir programdan diğerine geçerken (bağlam değişimi) eski programın durumu kenara kaydedilir, yeni programın bilgileri yüklenir ve stack alanı ilklendirilir; bunun için programlama dilinin çalışma modeline hakim olmak gerekir.
- İşletim sistemi bir kaynak yöneticisi olarak düşünülmelidir. Kendisi de işlemci ve bellek kullanan bir program olduğu için, kaynakların büyük kısmını diğer proseslere bırakacak şekilde tasarlanmalıdır. Ayrıca varlığını hissettirmemelidir: örneğin disk biriminden okuma ya da yazmanın bittiğini bildiren bir donanım kesmesi geldiğinde, bu işlemi bekleyen program en kısa sürede haberdar edilip kaldığı yerden devam ettirilmelidir. İşletim sistemi kodu da işlemcide çalıştığından bu işi en az gecikmeyle yapması gerekir.
- İşletim sistemleri üzerine uzun yıllar boyunca işlemci, bellek, çevre birimi ve program yönetimi; programların eş zamanlı çalışması, etkileşmesi ve haberleşmesi konularında derin akademik çalışmalar ve bunların pratik uygulamaları yapılmıştır. Bugünkü modern işletim sistemlerinin temelleri bu çalışmalarla atılmıştır. Ders, bu süreci baştan bugüne, konuların defakto standartlarını oturtan uzmanların yazdığı makaleler üzerinden inceler. Kapsamdaki konular: işlemci, bellek ve çevre birimi yönetimi, çok işlemcili çalışma, proses yönetimi ve zamanlama, proses göçü (migration), prosesler arası haberleşme, senkronizasyon, sanallaştırma (tam sanallaştırma, para-sanallaştırma, container), koruma ve güvenlik.
- Bir bilimsel makale belirli bir düzenle okunur. Abstract makalenin konusunu ve hedefini özetler. Introduction konuya genel giriş yapar, problemi tanımlar ve önemini ortaya koyar. Related Work öncül çalışmaları verir; bu dersteki makaleler çoğunlukla konunun ilk çalışmaları olduğu için bu bölüm kısa olabilir ya da olmayabilir. Ardından teorik inceleme, ona dayalı deneyler, sonuçlar ve hangi yaklaşımın hangi durumda daha uygun olduğuna dair yorumlar gelir. Son olarak future work bölümünde açık kalan problemler belirtilir. Bir makaleyi değerlendirirken şu sorulara cevap aranır: amacı ne, kapsamı ne, ne elde etmiş, amacı ne ölçüde çözmüş, geriye çözülmesi gereken ne kalmış? Okuma başta yukarıdan aşağı yapılabilir; konuya hakim olununca önce referanslara bakıp sonra makaleye dönen aşağıdan yukarı bir okuma da tercih edilebilir.
- Hoca okunan konuların uygulamada pekişmesi için örnek çalışma fikirleri verdi. Birincisi, aynı mimarideki iki Linux sanal makinesi arasında bir prosesin A makinesinde durdurulup B makinesine taşınması ve orada çalıştırılmasıdır. İkincisi, kesme mekanizmaları, kesme önceliklerinin çözülmesi ve kesme gecikmesinin azaltılmasıyla ilgili makalelerdeki tekniklerin uygulanmasıdır. Üçüncüsü, Unix ve Windows dosya sistemlerinin büyük/küçük dosya ve sıralı/rastgele erişim gibi durumlarda okuma-yazma performansının karşılaştırılmasıdır. Hoca dosya sistemine gelen istek karakteristiğinin bir veri tabanında, bir web sunucusunda ve sıradan bir kullanıcıda farklı olduğunu, bu yüzden performansın kullanım profiline bağlı olduğunu vurguladı. Bu tür çalışmalarda Linux, çekirdek kaynak koduna erişim sağladığı için avantajlıdır; C/C++, kabuk betikleri, Perl, Python, Java ya da Go gibi diller kullanılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
