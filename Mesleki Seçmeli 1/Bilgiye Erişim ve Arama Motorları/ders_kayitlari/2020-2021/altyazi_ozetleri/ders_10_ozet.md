# Ders 10 Çalışma Özeti

## Genel Konular

- Dersin tarihi 17 Aralık 2020 Perşembe. Ders Zoom üzerinden yapıldı. Kayıt yaklaşık 00:24'te başlıyor ve 2 saat 10 dakika sürüyor.
  - Ders büyük ölçüde İngilizce anlatıldı. Hoca ders başında, aralarda ve sonda Türkçe açıklamalar yaptı.
  - Konu, kitabın 7. bölümü: Sosyal Ağ Analizi ve Bağlantı Analizi (Social Network Analysis and Link Analysis). Slaytlar dönemin başında ders sayfasına konmuştu.
- Sosyal ağ analizinin web madenciliğindeki (web mining) yeri ve görselleştirme örnekleri.
  - Karmaşık ağ (complex network), ayrık alt ağlar, dev bileşen, yalıtılmış (island) düğümler.
  - Örnekler: gazete terimleri ağı, internet haritası, ABD siyasi blogları, şirket e-posta ağı, Facebook arkadaşlık ağı, yemek tarifi siteleri.
- İnternet ile Dünya Çapında Ağ (World Wide Web) farkı.
- Temel terimler: düğüm (node) ve bağlantı (link), yönlü (directed) ve yönsüz (undirected) graf, bağlantı nitelikleri (link attributes).
- Ağ verisinin üç temsil biçimi:
  - Komşuluk matrisi (adjacency matrix).
  - Kenar listesi (edge list).
  - Komşuluk listesi (adjacency list).
- Ağın bağlantı yapısını özetleyen metrikler:
  - Derece (degree), giriş derecesi (in-degree), çıkış derecesi (out-degree), derece dizisi (degree sequence) ve derece dağılımı (degree distribution).
  - Bağlı bileşenler (connected components): güçlü bağlı (strongly connected), zayıf bağlı (weakly connected) ve dev bileşen (giant component).
- Bağlantı analizine dayalı sıralamanın tarihçesi: HITS (Cornell) ve PageRank (Stanford).
- Merkezilik metrikleri (centrality metrics):
  - Derece merkeziliği (degree centrality) ve tüm ağın derece merkezileşmesi (degree centralization).
  - Arasındalık merkeziliği (betweenness centrality).
  - Yakınlık merkeziliği (closeness centrality).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sosyal ağ analizinin raporları genellikle görselleştirmeyle sunulur. Düğümün büyüklüğü, seçilen metriğe göre önemini gösterir.
- Aynı kavram farklı bilim dallarında farklı adlar alır:

| Alan | Düğüm | Bağlantı |
|---|---|---|
| Matematik | vertex (köşe) | edge (kenar) |
| Bilgisayar bilimi | node (düğüm) | link (bağlantı) |
| Fizik | site | bond |
| Sosyoloji | actor (aktör) | tie (bağ) |

- **Yönlü mü yönsüz mü sorusu:**
  - LinkedIn yönsüzdür. Bağlantı isteğini kimin başlattığı bilinmez.
  - Twitter yönlüdür. Takip eden ve takip edilen bellidir.
  - Facebook'ta arkadaşlık yönsüz, takip (follow) yönlüdür. Bu yüzden ikisi birden sayılabilir.
- Bağlantı nitelikleri:
  - Ağırlık (weight): iletişim sıklığı. Telefon kaydı (CDR) verisinde arama sayısı, e-posta verisinde e-posta sayısı ağırlık olarak kullanılabilir.
  - Tür (type): yakın arkadaş, iş arkadaşı, okul arkadaşı gibi kategoriler.
  - Sıra (ranking): aynı türdeki bağlantılar arasında birinci, ikinci tercih.
  - Örnekler: yurtta yemek masası arkadaşı tercihleri (1. ve 2. tercih), güven/güvensizlik (trust/distrust) ağı.
- Komşuluk matrisinde satır bağlantıyı vereni, sütun bağlantıyı alanı gösterir.
  - Bir satırın toplamı o düğümün çıkış derecesini verir.
  - Bir sütunun toplamı o düğümün giriş derecesini verir.
- Yönlü grafta derece merkeziliği hesaplanırken genellikle çıkış derecesi kullanılır.
- Derece merkeziliği tek başına yeterli değildir. Orkut örneği:
  - Orkut küçük alt grafta çok bağlantılıdır.
  - Ama bütün ağın kenarındadır, çok sayıda çiftin arasında durmaz ve ağın geri kalanına yakın değildir.
  - Bu yüzden arasındalık ve yakınlık da hesaplanmalıdır.
- Hoca formülleri ezberlemenizi değil, hesabın mantığını anlamanızı istedi.
- Merkezilik metrikleri bütün bağlantılara eşit ağırlık verir ve yönlü grafta çıkış bağlantılarına odaklanır.
  - Prestij metrikleri (prestige metrics) ise giriş bağlantılarına odaklanır. Bunlar bir sonraki derste işlenecekti: derece prestiji (degree prestige), yakınlık prestiji (proximity prestige) ve sıra prestiji (rank prestige).
  - Sonraki derste ayrıca ortak atıf (co-citation), bibliyografik eşleşme (bibliographic coupling) ve PageRank işlenecekti.
- Bağlantı analizi bölümü final sınavı için önemli bir bölümdür.
- **Proje duyurusu:** Ders sonunda bir öğrencinin sorusu üzerine hoca dönem projesi beklentilerini açıkladı.
  - Crawler (web tarayıcı) projelerinde bütün ürünler yerine belli bir ürün grubuna odaklanılabilir. Örnek: televizyonların bütün modelleri ya da iPhone'un bütün modelleri.
  - Veri en az iki ya da üç farklı siteden toplanmalı. Tek siteden toplanan veri yeterli değil.
  - Toplanan ürünler tek bir hibrit sayfada gösterilmeli. Fiyata, stok durumuna, adede göre filtrelenip sıralanabilmeli.
  - Tek bir modeli değil, o ürün grubunun bütün modellerini kapsamalı.
- Ders kaydı Online YıldızEdu'ya yükleniyor. Konularda takılanlar kaydı yeniden dinleyebilir.

## Kısa Tekrar Notları

- Örnek graf ve komşuluk matrisi (kenarlar: 2→3, 2→4, 3→2, 3→4, 4→5, 5→1, 5→2):

$$A=\begin{pmatrix}0&0&0&0&0\\0&0&1&1&0\\0&1&0&1&0\\0&0&0&0&1\\1&1&0&0&0\end{pmatrix}$$

  - Satır toplamları (çıkış dereceleri): 0, 2, 2, 1, 2.
  - Sütun toplamları (giriş dereceleri): 1, 2, 1, 2, 1.
  - Düğüm 3'ün çıkış derecesi 2 (düğüm 2 ve 4'e), giriş derecesi 1'dir (düğüm 2'den).
- Kenar listesi bu örnekte 7 satırdır: (2,3), (2,4), (3,2), (3,4), (4,5), (5,1), (5,2). Liste ilk elemana göre küçükten büyüğe yazılır.
- Komşuluk listesi: `1:`, `2: 3, 4`, `3: 2, 4`, `4: 5`, `5: 1, 2`.
- Kendine bağlantı (self loop) varsa $a_{ii}=1$, yoksa $a_{ii}=0$ yazılır. Yönsüz grafta $a_{ij}=a_{ji}$ olur.
- Derece: düğümün toplam bağlantı sayısı. Yönlü grafta derece = giriş derecesi + çıkış derecesi.
- Derece dağılımı: her derece değerinden kaç düğüm olduğunu gösterir.
- Güçlü bağlı bileşen: bileşendeki her düğüme, diğer her düğümden yön kurallarına uyarak ulaşılabilir.
- Zayıf bağlı bileşen: yönler göz ardı edildiğinde her düğüme ulaşılabilir.
- Dev bileşen: düğümlerin büyük kısmını içeren bileşen.
- Derece merkeziliği (normalize):

$$C_D(i)=\frac{d(i)}{n-1}$$

  - 6 düğümlü yıldızda merkez $5/5=1$, uçlar $1/5=0{,}2$ alır.
- Arasındalık merkeziliği:

$$C_B(i)=\sum_{j<k}\frac{p_{jk}(i)}{p_{jk}}$$

  - $p_{jk}$: $j$ ile $k$ arasındaki en kısa yolların sayısı. $p_{jk}(i)$: bunlardan $i$'den geçenlerin sayısı.
  - Normalize etmek için $\frac{(n-1)(n-2)}{2}$'ye bölünür. Bu, $i$ dışındaki düğüm çiftlerinin sayısıdır.
- Yakınlık merkeziliği:

$$C_C(i)=\frac{n-1}{\sum_{j=1}^{n} d(i,j)}$$

  - $d(i,j)$: $i$'den $j$'ye en kısa yol uzunluğu. Ortalama uzaklığın tersidir. Ağın ortasındaki düğümler en yüksek değeri alır.

## Detaylı Açıklamalar

### Sosyal ağ analizi neden önemli?

- Karmaşık ağda bağlantılar merkezi bir otorite olmadan, özerk olarak oluşur. Web de böyle bir ağdır. Her sayfa sahibi kime bağlantı vereceğine kendisi karar verir.
- Analiz sonucunun görselleştirilmesi ağ hakkında bilgi verir.
  - **ABD siyasi blogları:** Aynı görüşteki bloglar birbirine bağlantı veriyor, karşı görüşe nadiren bağlantı var. Bir görüşü takip eden okur karşı görüşü pek görmüyor.
  - **Şirket e-posta ağı:** Sık yazışan küçük kümeler ve birçok kümeye bağlanan merkezi düğümler var. Yönetici bundan şirket içi iletişimin düzeyini anlayıp önlem alabilir.
  - **Facebook ağı:** Sıkı bağlı alt ağlar ve dev alt ağa gevşek bağlı alt ağlar ayırt edilebiliyor.
  - **Yemek tarifi siteleri:** Bir ülkenin tarif sitelerini tarayıp (crawl) anahtar kelimeleri sıklığa göre büyüterek, o mutfakta önemli malzemeler (tuz, yumurta, tereyağı, soğan) görülebilir.
- Web madenciliğinde HTML belgelerinin oluşturduğu ağ incelenir. Amaç web sayfalarının sıralamasının nasıl yapıldığını anlamaktır.
- İnternet alttaki iletişim ağıdır (sunucular ve aralarındaki fiziksel bağlantılar). Web, bunun üzerinde duran, HTML belgeleri ve köprü bağlantılarından (hyperlink) oluşan "yumuşak" bir ağdır.

### Derece dizisi ve dağılımı

- Hoca iki ayrık parçadan oluşan 8 düğümlü bir örnekte giriş derecelerini yazdı:
  - 3 düğüm 2 giriş bağlantısı alıyor, 4 düğüm 1 giriş bağlantısı alıyor, 1 düğüm hiç almıyor.
- Aynı şey çıkış derecesi için de yapıldı: 4 düğümün çıkış derecesi 2, 3 düğümün 1, bir düğümün 0.
- Derece dizisi ve dağılımı, ağı görselleştirmeden bağlantı yapısını anlamayı sağlar.

### Bağlı bileşen örneği

- 8 düğümlü örnekte iki ayrık alt ağ var.
- B, E, D, C birbirine her yönden ulaşabildiği için güçlü bağlı bileşendir. J ve H de güçlü bağlı bileşendir.
- A ve F tek elemanlı güçlü bağlı bileşenlerdir.
- Yönler göz ardı edildiğinde her iki alt ağ da zayıf bağlı bileşendir.

### Bağlantı analizine dayalı sıralama neden çıktı?

- 6. bölümde (bilgi erişimi, information retrieval) sorgu ile belge arasındaki benzerlik TF-IDF ile hesaplanıyor ve sonuçlar buna göre sıralanıyordu.
- Bu yöntemin iki zayıflığı vardı:
  - **Spam sayfalar:** Sayfa sahipleri sayfayı temsil etmeyen anahtar kelimeler ekleyerek birçok sorguda üst sıralara çıkabiliyordu.
  - **Popülerlik:** Benzerliği eşit sayfalardan hangisinin daha popüler olduğu bilinmiyordu.
- Çözüm: Bir sayfa çok sayıda bağlantı alıyorsa prestiji (prestige) ya da otoritesi (authority) yüksektir. Arama sonuçları bu değere göre sıralanabilir.
- Sosyal ağ analizi sıralama dışında topluluk keşfi (community discovery), e-posta analizi ve sosyal ağ profillerinin incelenmesi için de kullanılır.

### Derece merkezileşmesi (bütün ağ için)

- Hoca bütün ağın ne kadar tek bir düğüm etrafında toplandığını ölçen değeri gösterdi:

$$C_D=\frac{\sum_{i}\left[d_{\max}-d(i)\right]}{(n-1)(n-2)}$$

  - $d_{\max}$: ağdaki en büyük derece. Değer 0 ile 1 arasındadır.
- Yıldız ağda değer 1'dir. Bütün düğümler tek merkezin etrafındadır.
- Birden fazla önemli düğüm varsa değer küçülür, 0'a yaklaşır.

### Arasındalık örnekleri

- **Neden gerekli?** İki küme arasında köprü olan düğümün derecesi 2 olabilir. Ama iki taraftaki düğümlerin birbirine ulaşmak için kullandığı bütün yollar ondan geçer.
  - Hoca örnekte köprü düğümün 9, onun yanındaki düğümlerin 8 çiftin arasında olduğunu gösterdi.
- **Doğrusal örnek (A–B–C–D–E):**
  - C: (A,D), (A,E), (B,D), (B,E) çiftlerinin arasında. Arasındalık 4.
  - B: (A,C), (A,D), (A,E) çiftlerinin arasında. Arasındalık 3.
  - A: uçta, hiçbir çiftin arasında değil. Arasındalık 0.
- **Paylaşılan kredi örneği:** Kenarlar A–B, B–C, B–D, C–E, D–E.
  - B'nin değeri 3,5. A'dan C, D, E'ye giden yollar B'den geçer (3). C ile D arasında iki en kısa yol var (C–B–D ve C–E–D), B bunlardan birinde olduğu için 0,5 alır.
  - E'nin değeri 0,5. Yalnız (C,D) çiftinin iki yolundan birindedir.
  - C ve D'nin değeri 1. (A,E) ve (B,E) çiftlerinde krediyi paylaşırlar: $\frac{1}{2}+\frac{1}{2}=1$.
  - Python ile bütün çiftler üzerinden hesaplandı: A=0, B=3,5, C=1, D=1, E=0,5.
- **Düşük derece, yüksek arasındalık sorusu:** G ve H'nin ikisinin de derecesi 2.
  - G'nin bir yanında 6, öbür yanında 5 düğüm var: $6\times5=30$ çift.
  - H'nin bir yanında 7, öbür yanında 4 düğüm var: $7\times4=28$ çift.
  - Cevap G'dir.

### Yakınlık örnekleri

- Hoca mor düğüm örneğini gösterdi. Bu düğümün derecesi 1'dir ve hiçbir çiftin arasında değildir. Ama ağın en önemli düğümüne doğrudan bağlıdır. Bu önemi yalnız yakınlık merkeziliği yakalar.
- Hesap: düğümden diğer bütün düğümlere en kısa uzaklıklar toplanır, $n-1$'e bölünür ve tersi alınır.
- **Yüksek derece, düşük yakınlık sorusu:** Merkezden uzak düğümlere bakılır.
  - O ve F'nin derecesi 3'tür. İkisi de en merkezi düğüm I'ya 2 adımda ulaşır.
  - F'nin I'ya iki ayrı yolu, O'nun tek yolu vardır. E ise I'ya doğrudan bağlıdır.
  - Hoca cevabı O olarak verdi.

### Petrol ticareti örneği

- Düğümler ülkeler, kenar kalınlığı ticaret miktarıdır.
- Giriş derecesine göre çizimde ABD ve Japonya büyük çıkar. Bunlar birçok ülkeden petrol alır.
- Çıkış derecesine göre çizimde Suudi Arabistan büyük çıkar. Birçok ülkeye petrol satar.
- Az ülkeye satıp büyük miktar ihraç eden ülke sorusu: Venezuela (yalnız ABD'ye, büyük miktarda).

### Ders sonrası notlar

- **Sosyolojideki bağlantı adı:** Hoca bağlantının farklı alanlardaki adlarını slayttan okumadı. Tabloda yaygın karşılıklar verildi: matematikte edge, fizikte bond, sosyolojide tie.
- **Kenar sayısı:** Hoca örnek grafta bağlantıları sayarken "yedi bir yönde, sekiz öbür yönde" dedi. Grafta toplam 7 yönlü bağlantı var. 2 ile 3 arasındaki bağlantı iki yönlü olduğu için iki ayrı kenar sayılır.
- **Derece merkezileşmesinin paydası:** Hoca normalize değerleri ($1$, $0{,}2$, …) birbirinden çıkarıp $(n-1)(n-2)$'ye bölmeyi anlattı. Bu formül ham derecelerle (5, 1, …) kullanılır. Normalize değerlerle çalışılıyorsa payda $n-2$ olmalıdır. Yıldız ağda iki yol da 1 verir: $\frac{5\cdot4}{5\cdot4}=1$ ve $\frac{5\cdot0{,}8}{4}=1$.
- **Köprü örneğindeki sayı:** Hoca bir örnekte "altı farklı çiftin ortasında" deyip ardından "dokuz" dedi. Altyazının bu kısmı tutarsız. Doğru sayı çizimdeki düğüm sayılarına bağlıdır. Hesap kuralı: bir taraftaki düğüm sayısı × öbür taraftaki düğüm sayısı.
- **HITS'in kullanımı:** Hoca HITS'in daha sonra Yahoo tarafından kullanıldığını söyledi. HITS'i Jon Kleinberg (Cornell) 1998'de yayımladı. Ticari kullanımı en çok bilinen arama motoru Teoma'dır (sonra Ask.com). Yahoo'nun HITS kullandığına dair yaygın bir kaynak yok.
- **Altyazı hatası:** Kayıtta "odd degree" ve "alt degree" geçen yerler "out degree" (çıkış derecesi) olmalıdır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
