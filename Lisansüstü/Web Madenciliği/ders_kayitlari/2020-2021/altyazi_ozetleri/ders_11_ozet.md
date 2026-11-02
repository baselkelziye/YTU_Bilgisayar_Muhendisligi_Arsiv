# Ders 11 Çalışma Özeti

## Genel Konular

- Ders kitabının 7. bölümü: sosyal ağ analizi (social network analysis) ve bağlantı analizi (link analysis).
- Bağlantı analizinin arama motorundaki yeri: TF-IDF sıralamasının üstüne popülerlik sıralaması.
- Sosyal ağ analizi örnekleri ve neler çıkarılabileceği.
- Yönlü (directed) ve yönsüz (undirected) çizgeler.
- Bağlantı nitelikleri (attribute): ağırlık, sıra (rank), tür (type), olumlu/olumsuz işaret.
- Veri gösterimleri: komşuluk matrisi (adjacency matrix), kenar listesi (edge list), komşuluk listesi (adjacency list).
- Derece (degree), derece dizisi (degree sequence) ve derece dağılımı (degree distribution).
- Bileşenler: güçlü bağlı (strongly connected), zayıf bağlı (weakly connected), dev bileşen (giant component).
- Merkezilik (centrality) ölçüleri: degree, betweenness, closeness. Ağın merkezileşme (centralization) değeri.
- Bağlantı analizinin tarihçesi: HITS ve PageRank.
- Topluluk keşfi (community discovery) ve kümeleme (clustering) farkı.
- Prestij (prestige) ölçüleri: degree prestige, proximity prestige, rank prestige.
- Rank prestige ile PageRank bağı: özdeğer sistemi (eigensystem) ve kuvvet yinelemesi (power iteration).

## Hocanın Özellikle Vurguladığı Kısımlar

- Arama motoru yalnız içerik benzerliğiyle (TF-IDF) sıralama yapmaz. Ters dizinden gelen liste bağlantı analizinden çıkan popülerlik değerleriyle yeniden sıralanır.
- Yalnız içerik benzerliğine dayalı sıralama kolay kandırılır (spam). Sayfalar içeriklerine çok sayıda anahtar kelime koyar. Bu yüzden 1996 sonrası bağlantı tabanlı yöntemlere geçildi.
- Degree centrality tek başına yeterli değildir. Bağlantı sayısı çok olan bir düğüm ağın bütününde kenarda kalabilir. Betweenness ve closeness da hesaplanmalı.
- Centrality daha çok dışa giden bağlantılarla (outlink), prestige ise gelen bağlantılarla (inlink) ilgilenir. Prestige: başkaları tarafından ne kadar tercih edildiğin, yani popülerlik.
- Betweenness örneğinde iki düğüm arasında birden fazla en kısa yol varsa katkı yol sayısına bölünür. Hoca bu örneğin önemli olduğunu ve iyi takip edilmesi gerektiğini söyler.
- PageRank'in temeli rank prestige ölçüsüdür. Gelecek hafta power iteration yöntemi ve PageRank anlatılacak.
- Büyük ağlarda (ör. 10 milyon düğüm) görselleştirme zordur. Derece dağılımı tablosu ağ hakkında hızlı fikir verir.

## Kısa Tekrar Notları

- Aktör: düğüm (node). Web'de aktör = web sayfası, ilişki = köprü bağlantı (hyperlink).
- Farklı disiplinler farklı terim kullanır. Bilgisayar biliminde "node" ve "link", matematikte "vertex" ve "edge".
- Yönlü çizge: ilişkinin yönü görülür. Ör. Twitter, Instagram takip ilişkisi, web bağlantıları.
- Yönsüz çizge: yön görülmez. Ör. LinkedIn bağlantısı.
- Komşuluk matrisi: $A_{ij}=1$ ise $i$'den $j$'ye bağlantı var, yoksa $0$. $A_{ii}=1$ ise öz döngü (self loop). Yönsüz çizgede $A_{ij}=A_{ji}$.
- Out-degree: satır toplamı. In-degree: sütun toplamı.
- Strongly connected: bileşendeki her düğümden her düğüme gidilebilir.
- Weakly connected: her düğümden her düğüme gitmek zorunlu değil. Her düğüm bir şekilde ulaşılabilir.
- Giant component: eleman ve bağlantı sayısı diğerlerinden çok büyük bileşen.
- Normalize degree centrality: $C_D(i)=\dfrac{d(i)}{n-1}$.
- Closeness: $C_C(i)=\left(\dfrac{\sum_{j} d(i,j)}{n-1}\right)^{-1}$.
- Degree prestige: $P_D(i)=\dfrac{d_I(i)}{n-1}$.
- Rank prestige: $P_R(i)=A_{1i}P_R(1)+A_{2i}P_R(2)+\dots+A_{ni}P_R(n)$. Matris biçimi $P=A^T P$.

## Detaylı Açıklamalar

### Bağlantı analizi neden gerekir

- Ters dizin (inverted index) bir tablodur. Birinci sütunda anahtar kelimeler, ikinci sütunda bu kelimeleri içeren sayfaların sıralı listesi vardır.
- Sıralama TF-IDF gibi puanlarla yapılır. TF-IDF: bir kelimenin bir belgede ve belge kümesinde ne kadar önemli olduğunu gösterir.
- Arama motoru bu listeyi, sayfaların web'in bağlantı yapısındaki önemine göre yeniden sıralar.
- Bu konu web yapı madenciliği (web structure mining) ve sosyal ağ analizidir. Amaç: karmaşık bir ağdaki aktörlerin önemini bulmak.

### Sosyal ağ analizi ile neler çıkarılır

- Hangi gruplar var, görüşleri ne, birbirleriyle nasıl etkileşiyor.
- Sık görüşen alt gruplar var mı.
- Yalıtılmış (isolated) gruplar var mı: yalnız kendi içinde konuşan gruplar.
- Hocanın gösterdiği analiz örnekleri:
  - Gazete haberlerinde aynı paragrafta geçen şehir, kişi ve ekonomi terimleri arasında ilişki kurarak finans olaylarını yorumlamak. Sosyal medyadan çok önce yapılıyordu.
  - İnternetin (fiziksel iletişim ağı) görselleştirmesi. Hoca hatırlatır: internet altyapıdaki geniş alan ağıdır (WAN). Web ise sunuculardaki belgeler ve aralarındaki bağlantılardan oluşan yazılım katmanıdır. İkisi farklı karmaşık ağlardır.
  - ABD seçimleri öncesi siyasi bloglar: aynı görüşteki bloglar hep birbirine bağlantı veriyor. Bir tarafın sayfalarında dolaşan kişi diğer tarafın görüşüne çok az ulaşıyor.
  - Bir şirketin e-posta verisi: e-posta atan kişi aktör, gönderim tek yönlü kenar. Çalışanlar ağırlıkla kendi departmanı içinde yazışıyor. Tüm gruplarla yoğun etkileşen düğümler insan kaynakları çalışanı veya üst düzey yönetici olabilir. Yeni atanan bir genel müdür kurumdaki ilişki ağını görmek için bunu isteyebilir.
  - Facebook arkadaş ağı: farklı arkadaş grupları farklı renkte. Büyük düğümler önemli aktörler. Kimseyle etkileşmeyen alt ağlar da görülüyor.
  - Yemek tarifi ağı: düğümler malzemeler. Aynı tarifte geçen malzemeler arasında ilişki kurulur. Çok tarifte geçen malzeme büyük yazılır. Türk mutfağı tariflerinden tereyağı, zeytinyağı, tuz, yumurta gibi temel ürünler çıkarılabilir. Devlet planlama gibi bir kurum desteklenecek ürün altyapısını buna göre belirleyebilir.
- Sosyal ağ çok disiplinli bir konudur: sosyologlar, fizikçiler, matematikçiler ve bilgisayar bilimciler çalışır.

### Yönlü ve yönsüz çizgeler

- Hoca öğrencilere sorar: LinkedIn yönlü mü?
- Cevap: yönsüz. Bağlantı karşılıklıdır, kimin davet ettiği görülmez.
- Twitter ve Instagram'da kimin kimi takip ettiği görülür: yönlü.
- Facebook arkadaşlığı takip özelliği düşünülmezse yönsüz. Takip özelliği de vardır.
- Web: bağlantının yönü görülür, yönlü çizgedir.

### Bağlantı nitelikleri

- Ağırlık (weight): ör. bir sayfa diğerine çok sayıda bağlantı veriyorsa ilişki ağırdır. Arama kaydı (CDR) verisinde bir kişi diğerini çok aramışsa ağırlık yüksektir.
- Sıra (ranking): ör. "en iyi arkadaşım", "ikinci iyi arkadaşım".
- Tür (type): ör. Facebook'ta okul arkadaşı, çocukluk arkadaşı. Bağlantılar renklendirilebilir.
- Bir bağlantının birçok düğümü birleştiren önemli bir ilişki olduğu da bir nitelik olabilir.
- Örnek: yurtta yemek masası tercihleri. Herkes 1. ve 2. tercihini verir. Bağlantı türü tercih sırasını gösterir. Herkesin seçtiği popüler kişiler çıkar.
- Olumlu ve olumsuz ağırlık: ör. güven ağı. Kırmızı bağlantılar güvensizliği, yeşiller güveni gösterir. Yönetici bir grupta güven ortamı olup olmadığını böyle görebilir. Beğenme yanında duygu emojileri de bu tür veri üretir.

### Veri gösterimleri

- Komşuluk matrisi:
  - Satırlar bağlantıyı veren, sütunlar alan düğümler.
  - Hocanın 5 düğümlü örneğinde 1. düğüm kimseye bağlantı vermez, satırı sıfırdır. 5. düğüm 1 ve 2'ye bağlantı verir.
- Kenar listesi: her yönlü bağlantı (kaynak, hedef) çifti olarak yazılır. Ör. `2 3`, `2 4`, `3 2`, `3 4`.
- Komşuluk listesi: her düğüm için bir satır, yanında bağlantı verdiği düğümler. Ör. `1:` (boş), `2: 3, 4`.

### Derece, derece dizisi ve derece dağılımı

- Degree: bir düğümün bağlantı sayısı.
  - In-degree: gelen bağlantı sayısı.
  - Out-degree: giden bağlantı sayısı.
  - Degree: ikisinin toplamı.
- Komşuluk matrisinde bir satırın toplamı out-degree, bir sütunun toplamı in-degree verir. Hocanın örneğinde 3. düğümün in-degree değeri 1, out-degree değeri 2.
- Derece dizisi: düğümler sırayla yazılıp her birinin derecesi verilir. Hocanın 8 düğümlü örneğinde in-degree dizisi 2, 2, 2, 1, ..., 0 biçimindedir.
- Derece dağılımı: kaç düğümün hangi dereceye sahip olduğu. Örnekte in-degree değeri 2 olan 3, 1 olan 4, 0 olan 1 düğüm var. Çubuk grafikle gösterilir.
- In-degree değeri 0 olan düğüm çoksa ağda bağlantı almamış yalıtılmış düğüm çoktur.

### Bileşenler

- Hocanın 8 düğümlü (A–H) örneği:
  - Strongly connected bileşenler: {B, C, D, E}, tek düğümlü bileşenler (ör. {A}, {F}), {G, H}.
  - Weakly connected bileşenler: {A, B, C, D, E} ve {F, G, H}.
- Bileşen tanımı (güçlü veya zayıf) seçilir, alt gruplar buna göre bulunur.

### Merkezilik ölçüleri

- Degree centrality: bir düğüm kaç farklı düğümle ilişkide. Merkezi düğüm herkesle iletişimdedir.
- Betweenness centrality: bir düğüm kaç düğüm çiftinin iletişim yolu üzerinde. Gerçek hayatta birbiriyle konuşmayan iki grubu birleştiren kişi buna örnektir.
- Closeness centrality: bir düğüm ağdaki diğer düğümlere ortalama ne kadar yakın.
- Bir öğrencinin sorusu üzerine hoca örnek verir: 1–2–3–4–5 zincirinde 1'den 5'e kadar en önemli düğüm 3'tür. 3, dört çiftin (1–4, 1–5, 2–4, 2–5) yolu üzerindedir.
- Orkut örneği: yakın görünümde Orkut düğümünün çok bağlantısı var. Ağın tamamı gösterilince Orkut'un küçük bir köşede kaldığı görülür. Bu yüzden degree tek başına yeterli değil.
- X ve Y örneği:
  - Degree (out-degree): X'in 5 bağlantısı var, Y'nin 0. X daha önemli.
  - Betweenness: X 4 çiftin yolu üzerinde ve bu yollar X'ten geçmek zorunda. Y 3 çiftin yolu üzerinde ama bu çiftler Y'yi atlayabilir. X daha önemli.
  - Closeness: X'ten diğer düğümlere uzaklık toplamı daha küçük. X daha önemli.
- Centrality için genelde out-degree kullanılır.
- Petrol ticareti örneği:
  - In-degree'ye göre çizim: en çok petrol alan ülkeler ABD ve Japonya. Bağlantı kalınlığı miktarı gösterir.
  - Out-degree'ye göre çizim: Suudi Arabistan en büyük düğüm. Venezuela ve Birleşik Arap Emirlikleri'nin bağlantı sayısı düşük ama önemli miktarda petrol veriyorlar.

### Degree centrality hesaplama

- Yönsüz çizgede bağlantı sayısına bakılır.
- Normalize etmek için $n-1$'e bölünür.
- Yıldız çizgesi (6 düğüm): merkez $5/5=1$, uçlar $1/5=0{,}2$.
- Zincir (5 düğüm): ortadaki üç düğüm $2/4=0{,}5$, uçlar $1/4=0{,}25$.
- 7 düğümlü örnek: 2 bağlantılı düğüm $2/6$, 3 bağlantılı düğüm $3/6=0{,}5$.

### Merkezileşme (centralization)

- Tüm ağın merkeziliğini ölçer.
- En büyük degree değerinden her düğümün değeri çıkarılır, farklar toplanır, $(n-1)(n-2)$ ile bölünür.

$$C_D=\frac{\sum_{i}\left[d(i^*)-d(i)\right]}{(n-1)(n-2)}$$

- Yıldız çizgesi: farklar $5 \times 4 = 20$, payda $5 \times 4 = 20$, sonuç $1$.
- Değer 1'e yakınsa ağ tek bir merkez düğüm etrafında toplanmıştır.
- Değer 0'a yakınsa ağ dağınıktır, birbirine eşit önemde çok düğüm vardır.
- Bu değer çizgeyi görselleştirmeden ağ hakkında bilgi verir.

### Degree centrality'nin yakalayamadıkları

- Zincir örneğinde ortadaki düğüm 9 çiftin yolu üzerinde ama degree'si yanındakilerden düşük.
- Başka bir örnekte ortadaki düğümden herkese kolay ulaşılıyor ama degree yanındakilerle eşit.
- Bu durumları betweenness ve closeness yakalar.

### Betweenness centrality hesaplama

- $j$ ile $k$ arasındaki en kısa yol sayısı $p_{jk}$, bunlardan $i$'den geçenlerin sayısı $p_{jk}(i)$ ise:

$$C_B(i)=\sum_{j<k}\frac{p_{jk}(i)}{p_{jk}}$$

- Normalize edilmemiş örnekler:
  - Yıldız çizgesi (5 uç): merkez $4+3+2+1=10$, uçlar $0$.
  - Zincir A–B–C–D–E: C için A'dan 2, B'den 2, toplam $4$. B için $3$. A ve E için $0$.
  - Ortadaki düğümün iki yanında üçer düğüm olan örnek: $3+3+3=9$.
  - Bir başka düğüm için $4+4=8$.
- Alternatif yol örneği (önemli):
  - C ve D, B üzerinden de E üzerinden de konuşabilir.
  - B için: A'dan gelen 3 çift ve C–D çiftinden $1/2$. Toplam $3{,}5$.
  - E için: yalnız C–D çiftinden $1/2=0{,}5$.
- Betweenness'e göre çizilen ağda çok çiftin arasında kalan düğümler büyük görünür.
- Sınıf sorusu 1: betweenness yüksek ama degree düşük düğüm hangisi?
  - Cevap G. G'nin bir yanında 6, diğer yanında 5 düğüm var: $6 \times 5=30$ çift. Degree 2.
  - H için $7 \times 4=28$ çift, degree 2. G daha yüksek.
- Sınıf sorusu 2: betweenness düşük ama degree yüksek düğümler?
  - Cevap A, B, C, D, E, F. Birbirleriyle doğrudan konuşabilirler, kimsenin yolunda değiller. Degree değerleri 5 gibi yüksek.

### Closeness centrality hesaplama

- Örnek: genel müdürün danışmanı. Az kişiyle bağlantısı var (degree düşük), çalışanların arasında değil (betweenness düşük). Ama genel müdürü doğrudan etkileyebilir. Closeness bunu yakalar.
- Formül: uzaklıklar toplamı $n-1$'e bölünür, tersi alınır.
- Zincir A–B–C–D–E'de A için uzaklıklar $1+2+3+4=10$. $(10/4)^{-1}=0{,}4$.
- Zincirde C en ortada. Önce C, sonra B ve D, sonra A ve E gelir.
- Yıldız çizgesinde merkez: uzaklıklar toplamı $5$, $(5/5)^{-1}=1$.
- 7 düğümlü bir örnekte uzaklıklar toplamı $10$, $(10/6)^{-1}=0{,}6$.
- Sınıf sorusu: degree görece yüksek ama closeness düşük düğüm? Cevap O. 3 bağlantısı var, diğerlerinin 1 veya 2. Ama uçta durduğu için diğerlerine ulaşması zor. I'nın ise hem degree hem closeness değeri yüksek.

### Bağlantı analizinin tarihçesi

- İlk arama motorları TF-IDF ve kosinüs benzerliği (cosine similarity) kullanıyordu.
- Sayfalar üst sıralara çıkmak için içeriklerine anahtar kelime doldurdu. Yöntem kolay kandırılır hâle geldi.
- 1997: bağlantıların üzerindeki kelimelere dayalı bir arama motoru patenti alındı.
- 1997–1998: Cornell'den bir grup ve Stanford'dan bir grup iki algoritma yayımladı.
  - HITS: sonra Yahoo'nun bağlantı tabanlı algoritması oldu.
  - PageRank: sonra Google'ın bağlantı tabanlı algoritması oldu.
- Sonuçta sayfalar hem TF-IDF hem bağlantı analizi sonucuna göre sıralanıp kullanıcıya gösterilir.
- Popülerlik değerleri yalnız arama için değil, web'deki alt toplulukları bulmak, e-posta analizi ve serbest metindeki kelimeler arası ilişki ağını çıkarmak için de kullanılır.

### Topluluk keşfi ve kümeleme

- Bir öğrenci sorar: sosyal ağdaki topluluklar (communities), gözetimsiz öğrenmedeki (unsupervised learning) kümelere benzer mi?
- Hoca: aynı şey değil ama benzetme kurulabilir.
  - Kümeleme: veri kümesindeki birbirine benzer noktaları gruplar.
  - Topluluk keşfi: önce bir ölçü seçilir (ör. in-degree). Sonra bağlantı yapısına göre alt topluluklar bulunur (güçlü veya zayıf bağlı bileşenler gibi).
- Hocanın araştırma grubunun örneği: bir telekom firması için müşteri kaybı (churn) analizi.
  - Birbiriyle yoğun konuşan alt topluluklar bulunur.
  - Bir kişi başka operatöre geçerse topluluktaki diğerleri de etkilenir varsayımı yapılır.
  - Henüz ayrılmayanlara indirim ve teklif sunulur, ayrılma davranışı önlenmeye çalışılır.

### Prestij ölçüleri

- Prestige: popülerlik, başkalarınca ne kadar tercih edildiğin. Gelen bağlantılarla ilgilenir.
- Degree prestige: gelen bağlantı sayısı bölü $n-1$. Degree centrality'ye benzer.
- Proximity prestige: closeness'a benzer. Yalnız $i$'ye bağlantıları izleyerek ulaşabilen düğümler hesaba katılır.

$$P_P(i)=\frac{|I_i|/(n-1)}{\sum_{j \in I_i} d(j,i)\,/\,|I_i|}$$

- Pay: $i$'ye ulaşabilen düğümlerin tüm düğümlere oranı.
- Payda: bu düğümlerin $i$'ye ortalama uzaklığı.
- Rank prestige:
  - Degree ve proximity prestige her bağlantıyı 1 puan sayar.
  - Gerçek hayatta öyle değil. Genel müdürden alınan referans bir iş arkadaşından alınandan değerlidir.
  - Bu yüzden bağlantı veren düğümün önemi bağlantıyla aktarılır.
  - $A_{ji}=1$ ise $j$, $i$'ye bağlantı vermiştir. $j$'nin rank prestige değeri $i$'ninkine eklenir.
  - Matris biçimi $P=A^T P$. Bu bir özdeğer sistemi denklemidir. Doğrusal cebirdeki power iteration yöntemiyle çözülür.

### Gelecek hafta ve proje görüşmesi

- Gelecek hafta: power iteration, PageRank, co-citation ve bibliographic coupling.
- Co-citation ve bibliographic coupling iki düğüm arasındaki benzerliği ölçer. Benzer makaleleri bulan araçlar (altyazıda "Authenticate" ve "Urkund" diye geçer; intihal denetim araçları) yalnız içeriğe değil, makalelerin birbirine verdiği atıflara da bakar.
- Ders sonunda bir öğrenci proje önerisini gösterdi:
  - Konu: ürün yorumlarının olumlu ve olumsuz sınıflandırılması. Hoca daha önce görüş madenciliği (opinion mining) önermişti: yorumlardan özellikleri (feature) çıkarıp hangisinin olumlu, hangisinin olumsuz olduğunu bir arayüzde göstermek.
  - Hoca ders kitabındaki yön odaklı görüş madenciliği (aspect-oriented opinion mining) bölümünü hatırlattı.
  - Öğrencinin planı: sözcük türü etiketleme (POS tagging) ile isimleri ayırmak, isimlerin önündeki ve arkasındaki sıfat ve zarflarla Apriori algoritmasıyla özellik çıkarmak, olumlu/olumsuz kelime sözlüğüyle (yaklaşık 6800 kelime) her özelliğin olumlu ve olumsuz sayısını tutup grafiğe dökmek.
  - Hoca bu şekilde devam etmesini ve dosyayı tekrar e-postayla göndermesini istedi.

### Ders sonrası notlar

- Hoca slaytlarını Google Drive'a yüklediğini, ders günü ve bir gün önce Google hizmetlerinde erişim sorunu olduğunu söyler. Ekran paylaşımı ders içinde birkaç kez kesilmiştir.
- Altyazıda veri kümesini ve sözlüğü hazırlayan kişi "Linkli" ve "LinkedIn" diye geçer. Büyük olasılıkla ders kitabının yazarı Bing Liu kastedilir (Hu ve Liu'nun yaklaşık 6800 kelimelik görüş sözlüğü).
- Hoca rank prestige formülünü anlatırken "PageRank değeri" ile "rank prestige değeri"ni karıştırır, sonra düzeltir. Formüldeki değer rank prestige değeridir.
- Hoca "daha önceki dört derste" der. Bu derste anlatılanları özetlediği için büyük olasılıkla "bu dersin önceki bölümlerinde" demek ister.
- Proximity prestige formülü altyazıda dağınık anlatılır. Yukarıdaki formül ders kitabındaki tanımdır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
