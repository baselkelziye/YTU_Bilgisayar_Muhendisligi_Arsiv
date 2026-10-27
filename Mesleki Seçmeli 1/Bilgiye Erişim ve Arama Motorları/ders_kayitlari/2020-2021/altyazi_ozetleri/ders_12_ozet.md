# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin tarihi 31 Aralık 2020 Perşembe, yılın son günü. Ders Zoom üzerinden yapıldı. Kayıt yaklaşık 2 saat sürüyor.
  - Bu ders büyük ölçüde Türkçe anlatıldı.
- Bağlantı analizinin kısa özeti: merkezilik, prestij, ortak atıf (co-citation), bibliyografik eşleşme (bibliographic coupling), PageRank.
- HITS algoritması (Hypertext Induced Topic Search):
  - Kök küme (root set) ve taban küme (base set).
  - Otorite (authority) ve merkez (hub) skorları.
  - Matris gösterimi ve kuvvet yinelemesi (power iteration).
  - Ortak atıf ve bibliyografik eşleşme matrisleriyle ilişkisi.
  - Avantajları ve dezavantajları.
- Web kullanım madenciliği (web usage mining), kitabın 12. bölümü:
  - Veri kaynakları ve tıklama akışı (clickstream) verisi.
  - Veri hazırlama (data preparation) adımları.
  - Kullanıcı tanımlama (user identification), oturum tanımlama (sessionization), sayfa görüntüleme tanımlama (pageview identification), yol tamamlama (path completion), bölüm tanımlama (episode identification).
  - Olaylar (events) ile tıklama akışının eşleştirilmesi.
  - Kullanıcı işlem veritabanı (user transaction database) üzerinde örüntü keşfi ve modelleme.
- Dönem projesi sunumlarının nasıl yapılacağı.

## Hocanın Özellikle Vurguladığı Kısımlar

- PageRank ve HITS 1998'de ortaya çıktı. PageRank Stanford'dan, HITS Cornell'den çıktı. Hoca PageRank'i Google'ın, HITS'i Yahoo'nun kullanmaya başladığını söyledi. PageRank, Google'ın ortaya çıkmasını sağlayan nedenlerden biriydi.
- İki algoritmanın da ilk adımı aynıdır: sorgu, TF-IDF'e göre ters dizin (inverted index) tablosunda aranır ve eşleşen belgeler bulunur.
- PageRank sorgudan bağımsızdır. Örnek: "web data mining" araması.
  - En otoriter sayfa, bu başlıkta bir kitabın sayfasıdır.
  - Ama bu sayfanın PageRank'i düşükse, kelimeleri içeren ve daha popüler sayfalar onu ilk 10 sonucun dışına itebilir.
  - Hocanın ikinci örneği: İkinci Dünya Savaşı ile ilgili, çok kişi tarafından düzenlenen Wikipedia sayfası.
- HITS sorguya bağımlıdır. Sorguya göre küçük bir graf kurar ve onun üzerinde hesaplar.
- İyi otorite, çok sayıda iyi merkezden bağlantı alır. İyi merkez, çok sayıda iyi otoriteye bağlantı verir. İki skor birbirini besler.
- Her sayfanın iki skoru vardır: otorite skoru ve merkez skoru.
- Hocaya göre HITS'in en önemli dezavantajı, hesabın sorgu anında yapılmasıdır.
- **Sınav uyarısı:** Bağlantı analizi bölümündeki her şeyden sorumlusunuz. Bunlar sosyal ağ analizi, merkezilik ve prestij metrikleri, ortak atıf, bibliyografik eşleşme, PageRank ve HITS'tir. Bölüme iyi çalışarak final sınavına gelin.
- **Sınav uyarısı (web kullanım madenciliği):** Oturum oluşturma, kullanıcı tanımlama, oturum tanımlama, eksik URL tamamlama (path completion) ve sezgisel yöntemler (heuristics) önemli konulardır. Sınavda karşınıza çıkabilir.
- **Proje sunumu duyuruları:**
  - Sunumlar gelecek hafta, dönemin son haftasında yapılacak.
  - Hoca her grup için ayrı bir zaman aralığı belirleyip Zoom'da ayrı toplantı yapabilir. Bu, dersin duyurular bölümünde ve e-postayla duyurulacak.
  - Kameralar açık olacak, ekran paylaşılacak. Proje 5–10 dakikada anlatılacak, kodlar gösterilecek, sorular cevaplanacak.
  - Her projenin bir kullanıcı arayüzü olmalı. Yapılan çalışmayı yapılandırılabilir biçimde gösteren arayüz ne kadar iyiyse o kadar iyi.
  - Sınıflandırıcı kullanan projelerde veri seti seçilebilmeli, sınıflandırıcı seçilebilmeli ve başarısı gösterilebilmeli.
  - Yalnız accuracy ve F1 skoru yazdırmak yeterli değil. Arayüzden tek bir örnek seçilip modelin onu etiketlemesi de gösterilmeli. Örneğin açılır menüden 5 veriden biri seçilir ve model "satın alır / almaz" tahminini yazar.
  - Eksikleri olsa bile proje mutlaka sunulmalı. "Projesiz geçebilir miyim?" diye şansınızı denemeyin.
  - Güncellenmiş öneri (proposal) belgesi de projeyle birlikte verilmeli.
  - Kodlar e-posta eki olarak gönderilmemeli. Google Drive ya da Dropbox'a yüklenip indirilebilir bağlantı gönderilmeli. Gönderilecek e-posta adresi duyuruda bildirilecek.
  - Projede kurulum ve çalıştırma adımlarını anlatan bir readme dosyası olmalı. Hoca ya da asistan projeyi size danışmadan çalıştırabilmeli.
  - Projeyi bulutta (cloud) çalıştıranlar ek puan alacak. Yine de readme'ye yerel kurulum adımları yazılmalı.

## Kısa Tekrar Notları

- HITS adımları:
  - Sorguyla eşleşen sayfalar kök kümeyi ($W$) oluşturur.
  - Kök kümedeki sayfaların bağlantı verdiği sayfalar ve kök kümeye bağlantı veren sayfalar eklenir. Sonuç taban kümedir.
  - Taban kümeden bir graf ve komşuluk matrisi $L$ kurulur. $i\to j$ bağlantısı varsa $L_{ij}=1$, yoksa 0.
- Otorite ve merkez skorları:

$$a(i)=\sum_{j\to i}h(j),\qquad h(i)=\sum_{i\to j}a(j)$$

- Matris gösterimi:

$$a=L^{T}h,\qquad h=L\,a$$

$$a=L^{T}L\,a,\qquad h=L\,L^{T}h$$

  - $L^{T}L$ ortak atıf matrisidir. $L\,L^{T}$ bibliyografik eşleşme matrisidir.
  - İki denklem de kuvvet yinelemesiyle çözülür.
- HITS avantajı: sorguya bağımlı sıralama.
- HITS dezavantajları:
  - Merkez skoru manipülasyona açıktır.
  - Konu kayması (topic drift) olabilir.
  - Hesap sorgu anında yapıldığı için PageRank'ten daha az verimlidir.
- Web madenciliğinin üç kolu:
  - İçerik madenciliği (web content mining): sorgu ile sayfa içeriğini eşleştirme.
  - Yapı madenciliği (web structure mining): bağlantı analiziyle popülerlik.
  - Kullanım madenciliği (web usage mining): kullanıcıların sitedeki davranış örüntüleri.
- Web kullanım madenciliği veri hazırlama sırası:
  - Veri birleştirme (data fusion).
  - Veri temizleme (data cleaning).
  - Kullanıcı tanımlama.
  - Oturum tanımlama.
  - Sayfa görüntüleme tanımlama.
  - Yol tamamlama.
  - Bölüm tanımlama.
  - Veri bütünleştirme (data integration) ve dönüştürme (data transformation).
- Zamana dayalı oturum sezgileri: toplam oturum süresi en fazla 30 dakika. Bir sayfada kalma süresi en fazla 10 dakika.

## Detaylı Açıklamalar

### HITS'te taban küme nasıl kurulur?

- Kök kümedeki sayfaların içeriği bilinir. Bu yüzden onların verdiği bağlantılar sayfanın köprü bağlantılarından (hyperlink) bulunur.
- Kök kümeye bağlantı veren sayfalar da bulunabilir. Tarama (crawling) sırasında bütün sayfaların içeriği ve bağlantı yapısı veritabanına kaydedilmiştir. Sayfaları yeniden taramaya gerek yoktur.
- HITS bütün web grafı için değil, yalnız bu taban küme için hesaplanır.
- Hoca bir sorgunun taban kümesini yaklaşık 1000–2000 bağlantı olarak düşünmeyi önerdi.

### Otorite ve merkez

- **Otorite:** Çok bağlantı alan sayfa. Belirli bir konuda otoriterdir.
- **Merkez (hub):** Çok bağlantı veren sayfa. Bir düzenleyici görevi görür. Örnekler: Yahoo dizini (directory), Open Directory. Bunlar çok sayıda bağlantıyı bir sınıflandırma (taxonomy) içinde sunar.

### HITS'in dezavantajları

- **Manipülasyon:** Bir sayfanın verdiği bağlantıları sayfanın yazarı belirler.
  - Yazar iyi otoritelere bağlantı vererek sayfasının merkez skorunu yükseltebilir.
  - Ardından otoriter olmayan sayfalara da bağlantı verirse, onların otorite skorunu yapay olarak artırır.
- **Konu kayması:** Kök kümeden bir adım ileri ve geri gidilince eklenen sayfalar sorgunun konusundan tamamen farklı olabilir. Analiz başka bir konu grubu üzerinde yapılmış olur.
- **Verimlilik:** Ters dizinde arama hızlıdır, çünkü ters dizin bir karma tablo (hash table) gibidir. Ama matris üzerinde kuvvet yinelemesi zaman alır. PageRank skorları önceden hesaplandığı için PageRank'te yalnız yeniden sıralama yapılır.

### Web kullanım madenciliğinin amacı

- Web sunucuları kullanıcıların tıklama akışını kayıt (log) dosyalarında tutar.
  - Uygulama sunucusunun (IIS, Tomcat, GlassFish) kendi kayıt dosyası olabilir.
  - Sunucuda çalışan uygulamanın kendi kayıt dosyası olabilir.
- Amaç: çok sayıda kullanıcının kolektif davranış örüntülerini bulmak ve buna göre işlem yapmak.
  - Kampanya oluşturma.
  - Birlikte satılan ürünleri bulma.
  - Kullanıcıların sırayla yaptığı işlemleri bulma.
  - Kullanıcının bir şey almadan çıkıp çıkmayacağını tahmin etme.
- Veri kaynakları:
  - Web sunucusu kayıt dosyaları (en büyük veri bunlardır).
  - Uygulama verisi.
  - Sitenin bağlantı yapısı.
  - Müşteri ilişkileri yönetimi (CRM) gibi eski (legacy) operasyonel veritabanları.
- Bu kaynakların hepsi her zaman bulunmayabilir. Bulunanlar tek bir işlem veritabanında bütünleştirilmelidir.

### Bir kayıt satırından ne öğrenilir?

- Her satır bir HTTP isteğidir (request).
- İsteğin tarihi ve saati.
- İsteğin geldiği sunucu ve istenen sayfa. Örnek: `/classes/cs589/papers.html`.
- Yönlendiren sayfa (referrer): kullanıcının hangi sayfadaki bağlantıya tıklayarak geldiği.
- Kullanıcının işletim sistemi, sürümü, tarayıcısı ve tarayıcı sürümü (user agent).
- IP adresi. Statik ya da dinamik olabilir.
- Tarayıcı çerezlere (cookie) izin veriyorsa çerezdeki kullanıcı kimliği (user ID). Kullanıcı tekrar geldiğinde tanınır.
- Oturum kimliği (session ID). Kullanıcının kısa bir zaman dilimindeki hareketleri bununla izlenir.

### Kullanıcı işlem veritabanı

- Birliktelik kuralı madenciliği (association rule mining) ve sıralı örüntü madenciliği (sequential pattern mining) konularındaki işlem veritabanına benzer.
- Her satır bir kullanıcıdır. Bir sütunda kullanıcı kimliği, diğerinde kullanıcının sırayla yaptığı etkinlikler oturum bazında tutulur.

### Veri temizleme

- Analiz hedefiyle ilgisi olmayan kayıtlar çıkarılır.
- Arama motoru tarayıcılarının (Googlebot, MSNbot gibi) bıraktığı istekler çıkarılır.
- Hatalı istekler çıkarılır.

### Kullanıcı tanımlama

| Yöntem | Avantaj | Dezavantaj |
|---|---|---|
| Çerez (cookie) | Tekrar gelen kullanıcı izlenebilir | Kullanıcılar çerezleri çoğu zaman engeller |
| Oturum açma (login) | Hangi cihaz ve tarayıcıdan gelirse gelsin izlenir | Herkes oturum açarak gezinmez |
| Yazılım ajanı (software agent), ör. mobil uygulama | Kullanıcı rahatça izlenir | Kullanıcılar uygulama indirmek istemeyebilir |
| Gömülü oturum kimliği (embedded session ID) | Tarayıcının engellemesi kolay değil | Yalnız tek oturum izlenir, farklı zamanlardaki ziyaretler ilişkilendirilemez |
| IP + kullanıcı ajanı (user agent) | Ek bilgi gerektirmez | %100 doğru değil, dinamik IP'de bozulur |

- E-ticaret sitelerinin çoğu satın almaya kadar oturum açmayı zorunlu tutmaz. Bazıları üye olmadan satın almaya da izin verir.
- IP + ajan yönteminde IP, işletim sistemi ve sürümü, tarayıcı ve sürümü birleştirilip tek bir kimlik yapılır.
  - Kafe gibi ortak ağlarda IP sürekli değişir. Kullanıcı tanınamaz.
  - Evden statik IP ve tek bilgisayarla bağlanan kullanıcı tanınabilir.
- Hocanın örneği: Kayıtlarda çerez, oturum ve giriş bilgisi yok. Bu yüzden IP + ajan kullanıldı. IE 5 / Windows 2000 ile gelen bir IP birinci kullanıcı, IE 6 / Windows XP ile gelen başka bir IP ikinci kullanıcı oldu.

### Oturum tanımlama

- İsteklerde gömülü oturum kimliği varsa gerçek oturumlar doğrudan bulunur. En iyi durum budur.
- Yoksa sezgisel yöntemler kullanılır.
- **Zamana dayalı sezgiler:**
  - Araştırmalara göre bir oturum ortalama 30 dakika sürer. Bu değer siteye göre ayarlanabilir. E-ticarette daha kısa, metin ağırlıklı sitelerde daha uzun olabilir.
  - İlk istekten başlayarak 30 dakika içindeki bütün istekler bir oturumdur.
  - Bir sayfada 10 dakikadan uzun kalınırsa oturum orada bitirilir. Sonraki istek yeni oturumu başlatır.
  - Örnek: İlk istek 0:01'de geldi. 0:31'e kadar olanlar 1. oturum. Sonraki istek 1:15'te geldi ve 2. oturumu başlattı.
- **Gezinmeye dayalı sezgi:**
  - Hoca şöyle anlattı: İlk istekte yönlendiren (referrer) alanı boşsa kullanıcı adresi kendisi yazmıştır. Burası oturumun başlangıcıdır. Bir sonraki yönlendirensiz isteğe kadarki istekler aynı oturumdadır.

### Sayfa görüntüleme tanımlama

- Kullanıcı tek bir sayfa ister. Ama tarayıcı sayfadaki her nesne (resim, müzik, diğer çoklu ortam dosyaları) için ayrı HTTP isteği gönderir.
- Kayıt dosyasında tek sayfa için örneğin 10 satır oluşabilir. Bunların tek bir sayfa görüntülemesine (pageview) ait olduğu belirlenmelidir.

### Yol tamamlama

- Sitelerin önünde çoğu zaman vekil (proxy) önbellek bulunur. Daha önce istenen sayfaya dönüldüğünde istek sunucuya gitmez, önbellekten karşılanır.
- Hocanın örneği: Kullanıcı A → B → D → E sayfalarına gidiyor. Sonra E'den D'ye, D'den B'ye dönüyor ve B'den C'ye gidiyor.
  - D ve B'ye dönüşler önbellekten karşılandığı için sunucu kaydında yok. Kayıtta E'den sonra doğrudan C görünüyor.
  - Sitenin bağlantı yapısına bakılarak eksik istekler (E→D, D→B) eklenir.

### Bölüm (episode) tanımlama

- Oturum içindeki etkinliklerin hangi amaçla yapıldığı bulunur.
  - Örnek amaçlar: satın alma, ürün iade etme, yardım arama, ürün arama, favorilere ekleme.
- İki yol vardır:
  - **Kural tabanlı:** "Kullanıcı şu sayfalara bu sırayla girdiyse ürünü favorilere ekliyordur."
  - **Sınıflandırma:** Sıralı sayfa görüntülemelerinden "satın alma" ya da "almadan terk etme" gibi bir etiket tahmin eden model.
- Hocanın örneğinde kayıtta çok sayıda GET ile arama isteği vardı. Bölüm tanımlamadan sonra davranış şöyle okundu: önce konuma göre arama, sonra konum ve fiyata göre arama, sonra bir ürünü seçme.

### Olaylar (events)

- Tıklama akışı verisi her tıklamadır: bağlantı, düğme, onay kutusu.
- Olay birden fazla tıklamanın birleşimi olabilir.
  - Ürün görüntüleme (product view), ürün tıklama (product click-through), sepet değişikliği (shopping cart change), satın alma, ürüne teklif verme.
- Olaylar uygulamanın kendi kayıt dosyasına olay kimliği (event ID) ile yazılabilir. Sayfayı hazırlayan sizsiniz.
- IIS ya da Tomcat gibi sunucuların kayıt dosyası sayfa içinde tanımlanan olayları izleyemez.

### Örüntü keşfi ve kullanım alanları

- Veri hazırlandıktan sonra uygulanan teknikler:
  - Birliktelik kuralları: birlikte satılan ürünler. "Birinci ürünü alan şu olasılıkla ikinciyi de alır."
  - Sıralı örüntüler: önce bu ürünü, sonra şu ürünü almak. Ya da önce görüntüleme, sonra satın alma.
  - Kümeleme (clustering): kullanıcıları davranışa göre bölümlere ayırma (segmentation), isteklerden ısı haritaları (heat map), sayfa ve ürün kategorileri.
  - Sınıflandırma: terk etme ya da satın alma tahmini, sahtecilik (fraud) tespiti.
  - Korelasyon analizi: ilişkili ürünleri bulma.
- Bulunan model ve örüntüler filtrelenir, birleştirilir ve pazarlama ya da ilgili iş biriminin önüne konur.
- Hocanın gösterdiği e-ticaret mimarisinde sunucu kayıtları CRM verisiyle bütünleştiriliyor. Ardından veri ambarı (data mart) ve OLAP analizleri ile veri madenciliği kütüphaneleri kullanılıyor.

### Ders sonrası notlar

- **HITS ve Yahoo:** Hoca HITS'in Yahoo tarafından kullanıldığını söyledi. HITS'i Jon Kleinberg 1998'de yayımladı. Ticari kullanımda en çok bilinen örnek Teoma arama motorudur (sonra Ask.com). Yahoo'nun HITS kullandığına dair yaygın bir kaynak yok.
- **Kök küme, taban küme:** Hoca bir yerde ilk bulunan URL'lere "base set" dedi. Doğrusu: sorguyla eşleşen ilk küme kök kümedir (root set). Bir adım ileri ve geri genişletilmiş küme taban kümedir (base set).
- **Merkez denklemi:** Hoca bir yerde $h$ için "komşuluk matrisinin transpozesi çarpı hub vektörü" dedi. Doğrusu $h=L\,L^{T}h$'dir.
- **Normalleştirme:** HITS'te her yinelemeden sonra $a$ ve $h$ vektörleri normalize edilir. Yoksa değerler sürekli büyür. Derste bu adımdan söz edilmedi.
- **"HREF alanı":** Hoca, isteğin hangi sayfadan geldiğini gösteren alanı bir yerde "HREF" diye andı. Doğrusu HTTP isteğindeki `Referer` başlığıdır.
- **Gezinmeye dayalı sezgi:** Kitaptaki referrer tabanlı sezgi (h-ref) şöyle tanımlanır: Bir isteğin yönlendireni o anki oturumda daha önce görüntülenmiş bir sayfaysa, istek o oturuma eklenir. Değilse yeni oturum başlar. Hocanın anlattığı "yönlendiren boşsa yeni oturum" kuralı bunun özel bir durumudur. Ayrıca kitapta yönlendiren boş bırakılan isteklerin de oturuma eklenebileceği belirtilir.
- **Zaman sezgisinde "en az 3 sayfa":** Hoca 30 dakika ve sayfa başına 10 dakika sınırından "en az 3 sayfa" sonucunu çıkarmaya çalıştı, sonra düzeltti. İki sınır birbirinden bağımsızdır. Sayfa sayısı için bir alt sınır yoktur.
- **Kaynak:** Bölüm numaraları Bing Liu'nun *Web Data Mining* kitabıyla uyumludur. 12. bölüm (Web Usage Mining) Bamshad Mobasher tarafından yazılmıştır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
