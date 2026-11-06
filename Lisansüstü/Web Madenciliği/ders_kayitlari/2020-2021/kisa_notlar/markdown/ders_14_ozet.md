# Ders 14 Çalışma Özeti

## Genel Konular

- Bağlantı analizinin tekrarı: centrality, prestige, co-citation, bibliographic coupling, PageRank.
- PageRank'in sorgudan bağımsız (query independent) olması ve sonucu.
- HITS (Hypertext Induced Topic Search) algoritması: otorite (authority) ve merkez (hub) puanları.
- Kök küme (root set) ve taban küme (base set).
- HITS'in matris biçimi ve co-citation, bibliographic coupling matrisleriyle bağı.
- HITS'in güçlü ve zayıf yanları.
- Ders kitabının 12. bölümü: web kullanım madenciliği (web usage mining).
- Tıklama akışı verisi (clickstream data) ve veri kaynakları.
- Veri hazırlama: temizleme, sayfa görüntüleme (page view) belirleme, oturum belirleme (sessionization), kullanıcı belirleme, yol tamamlama (path completion), bölüm (episode) belirleme, veri bütünleştirme.
- Kullanıcı işlem veritabanı (user transaction database).
- Kullanım madenciliğinde makine öğrenmesi yöntemleri ve uygulama alanları.
- 9 Ocak proje demosu duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlantı analizi bölümündeki tüm ölçüler çok önemli. Sınavda büyük olasılıkla çıkacak. Verilen örnek bir çizge üzerinde PageRank, HITS, co-citation, bibliographic coupling ve sosyal ağ ölçülerinin hesaplanması iyi bilinmeli.
- PageRank sorgudan bağımsızdır. Bu yüzden çok popüler ama sorguya en uygun olmayan sayfalar ilk 10 sonuca girebilir.
- HITS sorguya bağlıdır (query dependent). Puanlar sorgu anında, sorgunun sonuçlarından kurulan küçük çizge üzerinde hesaplanır.
- Web kullanım madenciliğinde sunucu günlük (log) kaydı şekli önemli. Hoca bu şekle iyi bakılmasını istedi.
- Oturum belirleme ve kullanıcı belirleme iyi öğrenilmeli. Sınavda çıkabilir. Farklı tekniklerin kullanım madenciliğinde hangi amaçla kullanıldığı da bilinmeli.

## Kısa Tekrar Notları

- Authority: çok sayfadan bağlantı alan sayfa.
- Hub: çok sayfaya bağlantı veren sayfa.
- Karşılıklı pekiştirme (mutual reinforcement): iyi hub sayfaları iyi authority sayfalarına bağlantı verir. İyi authority sayfaları iyi hub sayfalarından bağlantı alır.
- $a(i)=\sum_{(j,i)\in E} h(j)$, $h(i)=\sum_{(i,j)\in E} a(j)$.
- Matris biçimi: $a = L^T h$, $h = L a$.
- Yerine koyunca: $a = L^T L\, a$, $h = L L^T h$. Power iteration ile çözülür.
- $L^T L$ co-citation matrisidir. $L L^T$ bibliographic coupling matrisidir.
- Root set $W$: sorguya uyan sayfalar. Base set $S$: $W$ + $W$'nin bağlantı verdiği sayfalar + $W$'ye bağlantı veren sayfalar.
- Web mining'in üç kategorisi: içerik madenciliği (content mining), yapı madenciliği (structure mining), kullanım madenciliği (usage mining).
- Zaman tabanlı oturum belirleme: oturum en fazla 30 dakika, bir sayfada en fazla 10 dakika.
- Gezinme tabanlı oturum belirleme: yönlendiren (referrer) alanı boş olan istek yeni oturum başlatır.
- Çerez (cookie) yoksa kullanıcı kimliği: IP adresi + agent bilgisi.

## Detaylı Açıklamalar

### Tekrar

- Sosyal ağ analizinde iki temel ölçü grubu: centrality (degree, closeness, betweenness) ve prestige (degree, proximity, rank).
- Co-citation ve bibliographic coupling: içeriğe bakmadan yalnız verilen ve alınan atıflara bakarak iki belge arasında ilişki kurar. Normalde iki belge arasındaki benzerlik bilgi erişimi (information retrieval) bölümünde görülen TF-IDF ölçüleriyle bulunur.
- PageRank: çok sayıda ve popüler düğümden bağlantı alan düğüm popülerdir. Matris gösterimi, spider trap ve dead end çözümleri ve yakınsama geçen hafta işlendi.

### PageRank'in sorgudan bağımsızlığı

- Google'da sorgu girilir. Sorgu ters dizindeki (inverted index) anahtar kelimelerle karşılaştırılır.
- Eşleşen girişlerdeki sayfalar birleştirilip bir sonuç listesi oluşturulur.
- Liste önceden hesaplanmış PageRank tablosuna göre yeniden sıralanır.
- PageRank puanları sorgudan bağımsız, önceden hesaplanır.
- Sorun: "web data mining" aranırken beklenen sonuç bu adlı kitabın sayfasıdır. Ama bu kelimeleri içeren ve PageRank'i çok yüksek başka sayfalar varsa kitap sayfası ilk 10'a giremeyebilir.

### HITS

- 1998'de Cornell Üniversitesi'nden çıktı. PageRank ise Stanford'dan çıktı.
- PageRank'ten farkı: sorguya bağlıdır.
- Her sayfanın iki puanı var: authority ve hub.
- Algoritmanın adımları:
  - Sorgu ters dizinde aranır. Eşleşen sayfalar birleştirilir. Bu kümeye root set ($W$) denir. Slayttaki örnekte root set 200 sayfa.
  - Komşuluk matrisine bakılarak $W$'deki sayfaların bağlantı verdiği sayfalar ve $W$'ye bağlantı veren sayfalar bulunur.
  - Hepsi birleşince base set ($S$) oluşur.
  - $S$'deki bağlantılarla küçük bir çizge kurulur. Komşuluk matrisi $L$: bağlantı varsa 1, yoksa 0.
  - Authority ve hub denklemleri yazılır.

```
a(i) = i'ye bağlantı veren hub sayfalarının hub puanları toplamı
h(i) = i'nin bağlantı verdiği sayfaların authority puanları toplamı
```

- Matris biçimi: $a = L^T h$ ve $h = L a$.
- Birbirinin yerine koyma: $a = L^T L\, a$ ve $h = L L^T h$.
- $L^T$ ve $L$ $N \times N$ matristir. Çarpımları da $N \times N$ matristir.
- PageRank'teki gibi power iteration uygulanır:
  - Başlangıçta tüm authority (ve hub) puanları 1 alınır.
  - $a^{(k+1)} = L^T L\, a^{(k)}$, $h^{(k+1)} = L L^T h^{(k)}$.
  - Belli yinelemeden sonra iki vektör sabit değerlere yakınsar.
- Base set küçüktür (ör. 200 sayfalık root set için belki 500 sayfa). Matris büyük değildir, hesap hızlıdır.
- Sonuçlar authority ve hub puanlarına göre sıralanır.

### HITS ile co-citation ve bibliographic coupling bağı

- Co-citation: $C_{ij}=\sum_{k} L_{ki}L_{kj}$. Matris biçiminde $C = L^T L$.
- Bibliographic coupling: $B_{ij}=\sum_{k} L_{ik}L_{jk}$. Matris biçiminde $B = L L^T$.
- Authority denklemindeki matris co-citation matrisi, hub denklemindeki matris bibliographic coupling matrisidir.

### HITS'in zayıf ve güçlü yanları

- Kandırılmaya (spam) daha açık:
  - PageRank yalnız gelen bağlantılara bakar.
  - HITS root set'ten base set'e geçerken root set'teki sayfaların verdiği bağlantıları da alır.
  - Bu sayfalarda gereğinden çok veya spam amaçlı bağlantı varsa base set'e sorguyla ilgisiz sayfalar girer.
- Sorgu anında hesap yapar. Matris küçük olsa bile arama performansını düşürür.
- Konu kayması (topic drift): ilgisiz sayfalara verilen bağlantılar yüzünden sonuçlar sorgu konusundan uzaklaşabilir.
- Avantajı sorguya bağlı olmasıdır. PageRank daha popüler sayfalar yüzünden sorguya en otoriter yanıtı veren sayfayı (ör. Wikipedia) ilk 10'a alamayabilir. HITS bunu yapmaz.

### Web kullanım madenciliği: amaç ve veri

- Kitabın 12. bölümü.
- Web mining üç kategori:
  - İçerik madenciliği: 6. bölüm ve web taraması bölümü.
  - Yapı madenciliği: sosyal ağ analizi bölümü.
  - Kullanım madenciliği: bu bölüm.
- Üzerinde çalışılan veri: tıklama akışı (clickstream). Web'de gezerken arayüzdeki nesnelere tıklarız, olaylar (event) oluşur, bunlar günlük dosyalarına yazılır. Buna davranış verisi de denebilir.
- Günlük dosyaları:
  - Uygulama sunucusunun (IIS, Apache Tomcat, GlassFish) kendi günlükleri. Sunucu üzerinde çalışan uygulamalara gelen her olayı kaydeder.
  - Web uygulamasının kendi günlükleri.
- Amaç: insanların (veya yazılım ajanlarının) gezinme davranışlarını anlamak, davranış örüntülerini bulmak, kullanıcının sayfada ne yapmaya çalıştığını veya sonraki adımını tahmin etmek.
- Veri kaynakları:
  - Web sunucusu günlükleri.
  - Uygulama günlükleri.
  - Site içeriği ve yapısı (ana sayfa, menü bağlantıları).
  - Müşteri ilişkileri yönetimi (CRM) veritabanları: formlar, kredi kartı bilgileri vb.
- Sorunlar:
  - Veri her zaman tam değil. Ör. vekil önbellek (proxy cache) kullanılıyorsa: kullanıcı A, B, C sayfalarına gider, sonra B'ye döner. B önbellekten verilir, istek sunucuya ulaşmaz, günlüğe yazılmaz.
  - Veri farklı yerlerde. Hepsi tek bir kullanıcı işlem veritabanında bütünleştirilmeli.
  - Tıklama verisinin modellenmesi gerekir.

### Sunucu günlüğü örneği

- Slayttaki günlükte bir kullanıcı bir üniversite sitesinde (altyazıda "mayacsdepol.edu"; ders kitabındaki DePaul Üniversitesi örneği) bir dersin `papers.html` sayfasını istiyor.
- Her kayıtta: tarih, saat, istemci IP adresi, sunucu, HTTP sürümü (1.1), istenen sayfa, yönlendiren sayfa (referrer), tarayıcı, işletim sistemi ve sürümü.
- Kullanıcının adımları:
  - `papers.html` sayfasına girer.
  - Oradan bir PDF ister.
  - Google'da arama yapar, sonuçlardan bir PDF bağlantısına tıklar.
  - Başka bir dersin duyuru (announcement) sayfasına tıklar. Tarayıcı bu sayfayı göstermek için arka planda iki nesne daha ister. Kullanıcı bunları ayrıca istemedi.
- Hedef: bu davranışı gözle değil, makine öğrenmesiyle anlamak ve kullanıcının niyetini bulmak.

### Web kullanım madenciliği süreci

```
Sunucu/uygulama günlükleri + site içeriği
  -> Veri ön işleme (temizleme, page view, oturum, bütünleştirme, dönüştürme)
  -> Kullanıcı işlem veritabanı
  -> Makine öğrenmesi (kural, örüntü, küme, model)
  -> Örüntü analizi (pattern analysis)
  -> Kullanıcı davranışının tanımlanması
```

- Veri temizleme (data cleaning): robotların ve tarayıcıların (crawler) istekleri çıkarılır. Yalnız gerçek kullanıcı kayıtları kalır. İlgisiz ve hatalı kayıtlar da silinir. Hatalı kayıtlar günlük kütüphanesinden veya aynı sunucudaki başka uygulamaların günlüğe yazmasından olabilir.
- Page view belirleme: bir sayfayı göstermek için yapılan istekler zinciri tek bir page view'dur. Ör. duyuru sayfası ve arka plandaki iki nesne isteği.
- Oturum belirleme: kullanıcı sabah, öğlen, akşam gelebilir. Her ziyaret (giriş-çıkış veya tarayıcıyı açma-kapama arası) bir oturumdur.
- Bölüm belirleme (episode identification): oturum içinde önceden tanımlı iş süreçlerinden hangisinin yapıldığını bulmak.
  - Kredi kartıyla satın alma: ürünü görüntüle, özelliklere bak, sepete ekle, ilerle, kart bilgisini gir, öde.
  - İstek listesine ekleme: ürünü görüntüle, favorilere ekle düğmesine bas, istek listesine git.
  - Yardım alma süreci.
- Yol tamamlama: önbellek yüzünden günlükte eksik kalan istekler tamamlanır.
- Veri bütünleştirme ve dönüştürme: CRM, site içeriği ve günlük verisi birleştirilir. Gerekirse sütunlar birleştirilerek genelleştirilir. Sonuç kullanıcı işlem veritabanıdır.

### Kullanıcı işlem veritabanı

- İki sütunlu bir tablo düşünülebilir.
- Birinci sütun: kullanıcı veya oturum (ör. user 1, session 001).
- İkinci sütun: o oturumdaki sıralı eylemler (ör. ana sayfa, altındaki sayfa, onun altındaki sayfa).

### Oturum ve kullanıcı belirleme

- Çerez: tarayıcı ziyaret edilen sayfa için yerel bir klasöre benzersiz çerez kimliği (cookie ID) içeren bir dosya bırakır. Kullanıcı çerezi engellemediyse her istekte çerez kimliği gider. Geri gelen kullanıcı tanınır.
- Oturum kimliği:
  - İstekte gömülü oturum kimliği (embedded session ID) varsa gerçek oturum tüm ayrıntılarıyla yakalanır.
  - Çoğu zaman çerez kimliği olsa da oturum kimliği yoktur. O zaman oturumlar sezgisel (heuristic) yöntemlerle bulunur.
- Çerez de yoksa: IP adresi + agent bilgisi birleştirilip kullanıcı kimliği yapılır.
  - Agent: işletim sistemi ve sürümü, varsa güvenlik paketi, tarayıcı ve sürümü.
  - Sorun: kablosuz ağlarda dinamik IP alınır. Aynı kullanıcı farklı kullanıcı gibi görünür. Statik IP'de bu ikili benzersiz olabilir.

### Oturum belirleme sezgileri

- Zaman tabanlı (time-oriented heuristic):
  - Deneysel çalışmalara göre bir oturum 30 dakikayı geçmez. Değer yapılandırılabilir: bankacılıkta 15 dakika, başka bir alanda 45 dakika olabilir. Genelde 30 dakika.
  - İlk isteğin zamanından itibaren 30 dakika içindeki tüm etkinlikler bir oturumdur. 30 dakikadan sonraki ilk istek yeni oturumu başlatır.
  - Ek kural: bir sayfada 10 dakikadan fazla kalınırsa oturum 30 dakikayı beklemeden biter, yeni oturum başlar.
- Gezinme tabanlı (navigation-oriented heuristic):
  - Yönlendiren alanı boşsa kullanıcı adresi kendisi yazmıştır. Bağlantıya tıklayarak gelmemiştir.
  - Bu istek yeni oturumu başlatır. Yönlendireni boş olan bir sonraki isteğe kadar her şey aynı oturumdur.
- Örnek: aynı kullanıcının kayıtları 0:01'den başlar. Zaman tabanlı yöntemde ilk 30 dakika bir oturum, 1:15'ten başlayan 30 dakika ikinci oturum.
- Bir öğrenci sorar: süreyi kim tutuyor? Hoca: her HTTP isteğinde zaman bilgisi var. Günlükten zaman, IP, istenen sayfa (GET) ve yönlendiren alınıp tabloya çevrilir.

### Kullanıcı belirleme yöntemleri

| Yöntem | Zayıf yanı |
|---|---|
| Çerez | Kullanıcı çerezleri kapatabilir |
| Kayıt ve giriş (login) | Çoğu kullanıcı hesap olsa da giriş yapmadan gezer, ödeme anında giriş yapar |
| Kullanıcı ortamında yazılım ajanı (ör. telefonda e-posta, bilgisayarda MAC adresi alınır) | Kullanıcılar her uygulama için yazılım yüklemek istemeyebilir |
| Gömülü oturum kimliği | Yalnız aynı oturumu izler, geri gelen kullanıcıyı tanımaz |
| IP adresi + agent | Dinamik IP'de benzersiz kimlik zor |

- Oyuncak örnek (IP + agent):
  - IP aynı, agent "Internet Explorer 5, Windows 2000" olan kayıtlar birleşince user 1 çıkar.
  - "Internet Explorer 6, Windows XP Security Package 1" (büyük olasılıkla Service Pack 1) olan kayıtlar birleşince user 2 çıkar. Altyazıda bu kayıtların IP'si ayrıca söylenmez.
  - Benzer biçimde user 3 bulunur.

### Yol tamamlama örneği

- Kullanıcının gerçek yolu: A, B, D, E, D, B, C.
- Günlükte görülen: A (yönlendiren yok, adres yazılmış), B, D, E, C.
- E'den D'ye ve D'den B'ye dönüşler önbellekten karşılandığı için günlükte yok.
- Eksik kayıtlar yol tamamlama ile doldurulur.

### Olaylar (events)

- E-ticarette tıklama verilerinden olaylar oluşur.
- Örnekler:
  - Ürün görüntüleme (product view): ürünün resmi, metni veya bağlantısı görüntülenir.
  - Ayrıntı için ürüne tıklama (click-through).
  - Alışveriş sepetinde değişiklik: ekleme, çıkarma, adet değiştirme.
  - Satın alma, fiyat teklifi verme.
- Önce sayfadaki olay türleri belirlenmeli, kategorize edilmeli ve tanımlanmalı. Bir olay tek tıklamadan veya tıklama zincirinden oluşabilir. Olaylar tanımlanırsa olay örüntüleri bulunabilir.
- Slayttaki otel örneği: kullanıcı konuma göre arama yapar, sonuçları konum ve fiyata göre sıralar, bir oteli görüntüler. HTTP istekleri anlaşılır bir biçime çevrilmiştir. Kullanım madenciliğinde yapılmaya çalışılan budur.

### E-ticaret veri analizi akışı

- İçerik analizi modülü site içeriğini, sunucu ve uygulama günlüklerini girdi alır.
- Çıktılar oturum belirleme ve veri temizleme modülüne verilir.
- Veri bütünleştirme modülü CRM verisini, uygulama sunucusu verisini ve site yapısını birleştirir. Bir veri reyonu (data mart) kurulur.
- Data mart üzerinde makine öğrenmesiyle örüntü analizi veya OLAP analizi yapılır.

### Makine öğrenmesi yöntemleri ve uygulamalar

- Sık öğe kümeleri (frequent itemsets): ör. bir e-ticaret sitesinde belli bir destek (support) değerinin üstünde birlikte satılan ürünler.
- Birliktelik kuralları (association rules): gözetimsiz bir yöntem. Ör. "A'yı alan şu olasılıkla B'yi de alır". Her kuralın destek ve güven (confidence) değeri var.
- Sıralı örüntü madenciliği (sequential pattern mining): sıralı eylem dizileri. Ör. "A oyununu oynayan %50–60 olasılıkla B oyununu da oynar". Popüler eylem dizilerinin bir kısmını yapan kullanıcının sonraki adımı tahmin edilebilir.
- Kümeleme (clustering): müşterileri davranışa göre bölümleme (segmentation), sayfa veya ürün kategorize etme.
- Sınıflandırma (classification): eğitilen modelle bir ürünün veya kişinin hangi gruba ait olduğunu, sonraki adımını tahmin etme.
- Korelasyon analizi, müşteri kaybı (churn) analizi.
- Çıktılar: kural kümeleri (destek ve güven değerli), sıralı eylem dizileri, küme modelleri, sınıflandırma modelleri.
- Örüntü analizi: önemsiz kurallar süzülür, kümelerin neyi temsil ettiği tanımlanır.
- Slayttaki uygulama eşleşmeleri:
  - Kart dolandırıcılığı tespiti (card fraud detection): sınıflandırma.
  - Ziyaretçileri nitelendirme (characterization of visitors): sınıflandırma.
  - Ortak davranışlı veya ortak ilgili ziyaretçi gruplarını bulma: kümeleme.
  - İlişkili olayları veya uygulama nesnelerini bulma: birliktelik kuralları.
  - Sonraki olayı tahmin (prediction of next event): sıralı örüntü madenciliği.

### Proje demosu duyurusu

- 9 Ocak 2021 Cumartesi saat 9.00'da hocanın göndereceği Zoom bağlantısında proje demoları yapılacak. Hoca ayrıca e-postayla da hatırlatacak. E-posta gelmese de katılım gerekli.
- Demo kişi başı en fazla 10 dakika. Öğrenci sayısı az olduğu için biraz uzayabilir.
- Sunu (slayt) hazırlamaya gerek yok. Kod ayrıntılı gösterilecek, hoca kodları açtıracak. Neyin nasıl yapıldığı ve uygulamanın çalışması anlatılacak.
- Kodlar hocayla paylaşılacak.
- README dosyası olmalı. Hoca uygulamayı kendi bilgisayarında öğrenciden bağımsız kurup çalıştırabilmeli. Gereken adımlar yazılmalı.

### Ders sonrası notlar

- Hoca HITS için "spam'e uğrama açısından daha açık" der. Bu HITS'in zayıf yanıdır, avantajı değil. Hoca bunu "diğer önemli avantaj" diye sürdürür ama anlattığı şey (sorgu anında hesap, performans kaybı, konu kayması) de dezavantajdır. HITS'in asıl avantajı sorguya bağlı olmasıdır.
- Hoca authority ve hub tanımında "e-hub sayfaları link verir" der. Altyazı bozuk. Doğrusu: iyi hub'lar iyi authority'lere bağlantı verir, iyi authority'ler iyi hub'lardan bağlantı alır.
- Hoca power iteration'da normalizasyondan söz etmez. Ders kitabında her yinelemede $a$ ve $h$ vektörleri normalize edilir. Yoksa değerler büyümeye devam eder.
- Altyazıda "Security Package 1" geçer. Doğrusu büyük olasılıkla Windows XP Service Pack 1.
- Altyazıda uygulama sunucusu "ISS" diye geçer. Doğrusu büyük olasılıkla Microsoft IIS.
- Ders girişinde hoca link analizine "geçtiğimiz hafta başlamıştık" der. Önceki kayıtlarda konu iki derse yayılmıştır: sosyal ağ ölçüleri 15 Aralık'ta, co-citation ve PageRank 29 Aralık'ta işlendi.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
