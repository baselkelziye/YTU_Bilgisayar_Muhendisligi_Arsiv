# Ders 3 Çalışma Özeti

## Genel Konular

- Ders, öğrencilerin önceden okuduğu iki makalenin soru-cevap biçiminde tartışılmasıyla işlendi.
  - Birinci makale işletim sisteminde süper sayfa (superpage) desteği üzerineydi.
  - İkinci makale C. A. R. Hoare'un 1978 tarihli "Communicating Sequential Processes" (CSP) makalesiydi.
- Sayfalı bellek, sayfa tablosu ve TLB
  - Bellek iki biçimde yönetilebilir: segmentli bellek (8086'daki veri, kod segmentleri ve offset ile adresleme) ve sayfalı bellek.
  - Sayfalı bellekte bellek sabit boyutlu sayfalara bölünür. Linux 4 KB taban sayfa kullanır.
  - CPU mantıksal adresi sayfa numarası ve offset olarak üretir. Sayfa tablosu sayfa numarasını fiziksel çerçeve (frame) numarasına çevirir.
  - Her erişimde tabloya bakmak pahalıdır. Bu yüzden TLB (Translation Lookaside Buffer) adlı özel donanım kullanılır. TLB bütün girdilerine aynı anda bakarak çerçeve numarasını hemen verir.
  - TLB'de kayıt yoksa TLB miss olur ve sayfa tablosuna gidilir. Sayfa tablosunda da yoksa sayfa hatası olur; sayfa diskten getirilir ve tablo güncellenir.
- Süper sayfa fikri
  - Amaç TLB kapsamını (TLB coverage) artırıp TLB miss sayısını azaltmaktır.
  - Taban sayfa boyutunu doğrudan büyütmek iyi bir çözüm değildir; sayfanın küçük bir kısmı kullanılırsa geri kalanı boşa gider.
  - Süper sayfa, birden fazla taban sayfanın tek bir bütün olarak, tek bir TLB girdisiyle erişilmesidir. Örnek: 4 KB'lık 10 taban sayfa 40 KB'lık bir süper sayfa olur.
  - Kısıtlar: donanım süper sayfayı desteklemeli ve süper sayfa hem sanal hem fiziksel adres uzayında bitişik (contiguous) olmalı.
- Bitişiklik gereksiniminin yeniden doğurduğu sorun
  - Sayfa ve çerçeve yapısı, fiziksel bellekte bitişik yer bulma zorunluluğunu ve dış parçalanmayı (fragmentation) ortadan kaldırmak için getirilmişti.
  - Süper sayfa, offset sıralı ilerlediği için fiziksel olarak da ardışık çerçeve ister. Kontrolsüz büyütülürse bu eski sorun geri gelir.
  - Toplam boş bellek yeterli olsa bile tek parça boş alan bulunamayabilir. Çözüm boş alanları bir araya toplamaktır: bellekte compaction, diskte defragmentation, yönetilen dillerin yığınında garbage collection.
  - Bu işlem bellekten belleğe kopyalama gerektirir. Kopyalanan alanı kullanan süreçler durdurulmalıdır; bu da öngörülemeyen duraksamalara yol açar.
- Süper sayfa tahsis yaklaşımları
  - Yer değiştirmeye dayalı (relocation-based): süper sayfa büyütülmek istendiğinde arkada boş çerçeve yoksa başka bir yerde yeterli bitişik alan bulunur ve sayfalar oraya kopyalanır. Bellek bol ve bitişik alanlar çoksa iyi çalışır; süreç sayısı artıp bellek kısıtlandıkça sürekli kopyalama ve sonunda sistem çapında compaction gerekir.
  - Rezervasyona dayalı (reservation-based): bir sürecin sayfaları için fiziksel bellekte önceden, istenen ya da öngörülen süper sayfa boyutunda bitişik bir alan ayrılır. Boyutu süreç değil, işletim sistemi tahminle belirler.
- Promotion, incremental promotion, demotion ve eviction
  - Promotion: fiziksel olarak zaten ardışık yerleşmiş taban sayfaları tespit edip tek bir süper sayfa girdisinde birleştirmek.
  - Incremental promotion: rezerve alan içinde dolu çerçeve sayısı eşiği geçtikçe süper sayfayı adım adım büyütmek. Sınır rezervasyon boyutudur, çünkü bitişiklik yalnız rezervasyonun içinde garanti edilir.
  - Demotion: süreç süper sayfanın bütün parçalarını aktif kullanmıyorsa süper sayfayı küçültmek. Temel sorun donanımın süper sayfa için tek bir dirty bit tutmasıdır; hangi taban sayfanın değiştiği bilinmez.
  - Eviction: sayfanın diske yazılması. Süper sayfada bütün süper sayfa yazılır; içindeki temiz taban sayfalar da yazılıp geri okunur, disk G/Ç gecikmesi artar.
- Kirli süper sayfaların dışarı yazılması ve kriptografik özet
  - Temiz bir sayfa diskten okunurken her taban sayfa için kriptografik özet (hash) hesaplanıp saklanır.
  - Kısmen kirli taban sayfalar süper sayfaya yükseltilirse ya da temiz bir süper sayfa kirlenirse bütün taban sayfalar kirli sayılır.
  - Dışarı yazılırken her taban sayfanın özeti yeniden hesaplanır ve saklanan değerle karşılaştırılır; yalnız değişenler diske yazılır.
  - Çakışma olasılığı $2^{-80}$ düzeyindedir ve donanım hatası olasılığından çok küçüktür.
  - Sürekli özet hesabı maliyetlidir. Derste söylenene göre kötü durumda yaklaşık %60 performans düşüşü görülmüş ve yöntemin kullanılmamasına karar verilmiş.
- CSP makalesi (Hoare, 1978)
  - İlk cümle: giriş ve çıkış (input/output) programlamanın temel ilkel işlemleridir; girdi almayan ve sonucunu paylaşmayan program işe yaramaz.
  - Eşzamanlı çalışan sıralı süreçlerin bileşimi (parallel composition) programlamanın temel yapı taşlarından biridir; nasıl birleştirildikleri doğrudan performansı etkiler.
  - Makale öncesindeki yapılar: altyordam, prosedür (Algol 60), korutin, sınıf (Simula 67), Concurrent Pascal, semaforlar, koşullu kritik bölgeler, monitörler.
  - Makale önerisini bounded buffer, dining philosophers, monitör gibi temel problemlerin çözümleriyle sınar.
- CSP'nin yedi temel önerisi
  - 1: Dijkstra'nın korumalı komutları (guarded commands) sıralı kontrol yapısı ve belirsizliği (non-determinism) denetlemenin tek aracı olarak alınır.
  - 2: Dijkstra'nın `parbegin`'ine dayanan paralel komut; bütün süreçler aynı anda başlar, komut ancak hepsi bitince biter; süreçler global değişken güncelleyerek haberleşemez.
  - 3: Eşzamanlı süreçler arası haberleşme için basit giriş ve çıkış komutları.
  - 4: Haberleşme, bir süreç diğerini çıkış hedefi, diğeri de birinciyi giriş kaynağı olarak adlandırdığında olur; değer kopyalanır, otomatik tampon yoktur, karşı taraf hazır olana kadar komut bekletilir ve bu bekleme süreç için görünmezdir.
  - 5: Giriş komutları korumalarda yer alabilir; birden fazla koruma hazırsa yalnız biri, keyfi seçilir.
  - 6: Giriş korumalı tekrarlı komut, kaynak süreçlerin hepsi bitince sona erer.
  - 7: Basit örüntü eşleme ile beklenen yapıya uymayan girdiler reddedilir.
  - Program metni eşzamanlı süreç sayısına sabit bir üst sınır koyar; özyineleme ve süreç değerli değişken yoktur. Dil, tek ana belleği olan sıradan bir makinede ya da G/Ç kanallarıyla bağlı sabit bir işlemci ağında gerçeklenebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Makale yalnız giriş, özet ya da sonuç bölümünden değil, baştan sona okunmalıdır.
  - Hoca, yayımlanmış bir çalışmanın "olabilir"ler üzerinden değil, makalede yazanlar üzerinden konuşulması gerektiğini vurguladı.
  - Okurken not almak, önemli yerleri işaretlemek ve kenara yorum yazmak önerildi.
- Süper sayfanın temel çelişkisi
  - TLB erişimini azaltmak için sayfaları birleştirmek, sayfa ve çerçeve yapısının çözdüğü bitişiklik ve parçalanma sorununu yeniden doğurur. Bu yüzden süper sayfa kontrollü, durum izlenerek oluşturulmalıdır.
- Hoca bellekte compaction, diskte defragmentation ve yığında garbage collection işlemlerini aynı fikre bağladı; ortak maliyetleri kopyalama ve süreçlerin durdurulmasıdır.
  - Ders sonrası not: Hoca bunlar için "hiçbir farkı yok" dedi. Garbage collection'ın asıl işi erişilemeyen nesneleri geri kazanmaktır; büyük olasılıkla hocanın kastettiği, sıkıştırma (compacting) yapan çöp toplayıcılardır.
- Rezervasyon boyutunun önceden bilinmesi gerekir. Bilimsel bir çözüm, süreci önce çalıştırıp gözlemlemek yerine, daha önce hiç çalışmamış bir sürecin ihtiyacını tahmin edebilmelidir (a priori tahmin).
- Kriptografik özetin bit sayısı, donanımda bit hatası olasılığından çok daha düşük bir çakışma olasılığı verecek kadar büyük olmalıdır.
- CSP'de `parbegin` gelişigüzel süreçleri değil, ortak bir amaç için birbiriyle etkileşen (kooperatif) süreçleri başlatır.
  - Kabuktaki `cat dosya | more` örneği: iki süreç aynı anda başlar, biri üretir, diğeri tüketir. `>` ile yönlendirmede ise biri bittikten sonra diğeri çalışır.
- Tampon olmadan bekletme ile senkronizasyon: hazır olmayan tarafı beklemek, sınırı bilinmeyen bir tampon kurmadan iki sürecin hızını eşitler. Bu, üretici-tüketici problemindeki dolu tampon durumuna benzer.
- Bugünkü semafor, kritik bölge, üretici-tüketici, port, isimli boru gibi kavramların arkasında 1978'de tanımlanmış bu fikirler vardır.

## Kısa Tekrar Notları

- Sayfa tablosu: sayfa numarası -> çerçeve numarası. TLB bu çeviriyi donanımda hızlandırır.
- Süper sayfa = birden fazla taban sayfa, tek TLB girdisi; hem sanal hem fiziksel bitişiklik ve donanım desteği gerekir.
- Bitişiklik yoksa çözüm compaction'dır; bedeli kopyalama ve süreçlerin durması.
- Relocation-based: gerektiğinde başka yere kopyala. Reservation-based: önceden bitişik alan ayır.
- Promotion: doğal olarak ardışık çerçeveleri tek girdide birleştir. Incremental promotion: eşik aşıldıkça rezervasyon sınırına kadar büyüt.
- Demotion ve eviction sorunu: süper sayfa başına tek dirty bit; temiz taban sayfalar da yazılır.
- Taban sayfa başına kriptografik özet ile yalnız değişen sayfalar yazılabilir; ama hesap maliyeti yüksek.
- CSP: giriş/çıkış temel ilkeldir; korumalı komut, paralel komut, adlandırılmış süreçler arası tamponsuz, bekletmeli haberleşme, giriş korumaları, örüntü eşleme.
- `cat | more` iki süreci aynı anda başlatır; bu `parbegin`'in günlük örneğidir.

## Detaylı Açıklamalar

Süper sayfa tartışması sayfalı belleğin temel mekanizmasıyla başladı. CPU bir adrese erişmek istediğinde sayfa numarası ve offset üretir. Sayfa numarası sayfa tablosu üzerinden fiziksel çerçeve numarasına çevrilir, offset bu çerçevenin içinde konumu verir. Tabloya her erişimde bellekten bakmak pahalı olduğu için TLB kullanılır. TLB'nin kapsadığı bellek miktarı sınırlıdır; uygulamanın çalışma kümesi bu kapsamı aşarsa TLB miss artar. Akla gelen ilk çözüm sayfa boyutunu büyütmektir, ama bu sayfanın kullanılmayan kısmını boşa harcar. Makalenin önerdiği süper sayfa ise taban sayfaları gerektiğinde bir bütün hâline getirir.

Hocanın tartışmayı yönlendirdiği asıl soru şuydu: sayfa ve çerçeve yapısı, bir süreç için fiziksel bellekte tek parça yer bulma zorunluluğunu kaldırmak için getirilmişti. Sanal adres uzayında ardışık olan sayfaların çerçeveleri fiziksel bellekte dağınık olabilir. Oysa 4 KB'lık 10 taban sayfadan 40 KB'lık bir süper sayfa yapıldığında offset 0'dan 40 KB'a kadar sıralı ilerlediği için fiziksel çerçevelerin de ardışık olması gerekir. Böylece başta kaçılan sorun geri gelir: toplamda yeterli boş bellek olsa da tek parça alan bulunamayabilir. Bu durumda boş alanları birleştirmek için compaction yapılır. Bellekten belleğe kopyalama sırasında ilgili süreçler çalışamaz; bu yüzden sistem öngörülemeyen anlarda duraklar.

Relocation-based yaklaşımda, örneğin üç çerçevelik bir süper sayfayı dörde çıkarmak isteyen sürecin üçüncü çerçevesinin arkası doluysa, dört çerçevelik başka bir boş alan bulunur ve sayfalar oraya kopyalanır. Bu ilk aşamada yalnız o süreci etkiler; ama bellek doldukça yer bulunamaz ve bütün süreçleri durduran bir compaction gerekir. Reservation-based yaklaşımda ise işletim sistemi, sürecin gelecekteki ihtiyacını tahmin ederek önceden bitişik bir alan ayırır. Sayfalar bu alana yerleştikçe ve dolu çerçeve sayısı bir eşiği geçtikçe süper sayfa adım adım büyütülür (incremental promotion). Bu büyüme rezervasyon boyutunda durur, çünkü bitişiklik yalnız rezervasyonun içinde garantidir.

Demotion ve eviction tarafındaki sorun donanımdan kaynaklanır: donanım dirty biti çerçeve başına tutar, süper sayfa oluşturulunca ise tüm süper sayfa için tek bir bilgi kalır. Süper sayfa diske yazılacağında içindeki bütün taban sayfalar yazılır, oysa hepsinin değişmiş olması çok düşük bir olasılıktır. Makalenin "kirli süper sayfaları dışarı yazma" bölümünde önerilen çözüm, sayfa diskten okunurken her taban sayfanın kriptografik özetini saklamak ve dışarı yazarken özetleri yeniden hesaplayıp karşılaştırmaktır. Özet aynıysa sayfa değişmemiştir ve yazılmaz. Çakışma olasılığı $2^{-80}$ düzeyinde olduğu için donanım hatasından daha güvenilir kabul edilir. Ancak sürekli özet hesabı ciddi bir maliyet getirir; derste aktarıldığına göre kötü durumda yaklaşık %60 performans kaybı gözlenmiş ve yöntem kullanılmamış.

> **Ders sonrası not:** Hoca, 160 bitlik özet ile $2^{80}$ arasındaki ilişkiyi "yarısının iki katı" diye karışık ifade etti. Doğrusu: $n$ bitlik bir özette doğum günü sınırına göre çakışma güçlüğü yaklaşık $2^{n/2}$'dir; 160 bit için bu $2^{80}$ eder. Makalede kullanılan özet büyük olasılıkla 160 bitlik SHA-1'dir.

CSP tartışmasında hoca önce makalenin ilk cümlesine dikkat çekti: giriş ve çıkış programlamanın temel ilkel işlemleridir ve eşzamanlı sıralı süreçlerin paralel bileşimi temel bir yapıdır. Makale, o güne kadar önerilmiş prosedür, korutin, sınıf (Simula 67), Concurrent Pascal, semafor ve koşullu kritik bölge gibi yapıların üzerinde uzlaşma olmadığını belirtir ve yedi öneri getirir. Korumalı komutlar, belirsizliği denetlemenin tek aracıdır; burada amaç çalışma sırası ya da zamanlaması ne olursa olsun sonucun aynı kalmasıdır. Paralel komut bütün süreçleri aynı anda başlatır ve ancak hepsi bitince biter. Süreçler ortak değişkenle değil, birbirini adlandıran giriş ve çıkış komutlarıyla haberleşir. Otomatik tampon olmadığından gönderen ya da alan, karşı taraf hazır olana kadar bekletilir; bu bekletme süreç için görünmezdir, yani işletim sistemi düzeyinde sağlanır. Giriş komutları korumalarda kullanılabilir; birden fazla hazır seçenek varsa biri keyfi seçilir. Hoca bunu bugünkü wait ve signal (signal all) ilkelleriyle ilişkilendirdi. Son öneri olan örüntü eşleme, beklenen yapıya uymayan girdinin kabul edilmemesini sağlar; hoca bunu ağ paketlerinin protokole göre IP, TCP ya da UDP katmanına yönlendirilmesindeki filtrelemeye benzetti. Dil, ortak belleği olan sıradan bir makinede de, G/Ç kanallarıyla bağlı işlemci ağında da gerçeklenebilecek biçimde tasarlanmıştır ve süreç sayısı program metniyle sabittir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
