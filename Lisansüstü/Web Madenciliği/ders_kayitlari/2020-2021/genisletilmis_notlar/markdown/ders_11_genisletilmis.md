# Ders 11 Genişletilmiş Notu: Sosyal Ağ Analizi: Gösterimler, Merkezilik ve Prestij Ölçüleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlantı Analizinin Arama Motorundaki Yeri
- 2. Sosyal Ağ Analiziyle Neler Çıkarılır?
- 3. Yönlü ve Yönsüz Çizgeler
- 4. Bağlantı Nitelikleri
- 5. Veri Gösterimleri
- 6. Derece, Derece Dizisi ve Derece Dağılımı
- 7. Bileşenler
- 8. Merkezilik Ölçülerine Giriş
- 9. Derece Neden Tek Başına Yetmez?
- 10. Degree Centrality Hesabı
- 11. Ağın Merkezileşme Değeri
- 12. Degree Centrality'nin Yakalayamadıkları
- 13. Betweenness Centrality Hesabı
- 14. Closeness Centrality Hesabı
- 15. Arama Motorlarında Bağlantı Analizinin Tarihçesi
- 16. Topluluk Keşfi ve Kümeleme
- 17. Prestij Ölçüleri
- 18. Bir Proje Önerisi Üzerine Görüşme

## 1. Bağlantı Analizinin Arama Motorundaki Yeri

Bu dersin konusu, ders kitabının 7. bölümünü oluşturan sosyal ağ analizi (social network analysis) ve bağlantı analizidir (link analysis). Hoca konuya, kitabın 6. bölümünde web içerik madenciliği (web content mining) ve bilgi erişimi (information retrieval) işlenirken söylenenleri hatırlatarak girdi.

Bir arama kelimesine karşılık gelen web sayfaları ters dizin (inverted index) üzerinden bulunur. Ters dizin aslında bir tablodur. Birinci sütununda anahtar kelimeler veya anahtar kelime grupları yer alır. İkinci sütununda bu kelimeleri içeren web sayfalarının sıralanmış listesi bulunur. Bu sıralama TF-IDF gibi skorlarla yapılır. TF-IDF, bir kelimenin bir belgedeki ve belge kümesindeki önemini ifade eden bir ölçüdür.

Arama motorları ise yalnızca bu içerik tabanlı benzerlik ölçülerine göre sıralama yapmaz. Ters dizinden alınan liste, bir de bu sayfaların web'in bağlantı yapısı içindeki önemini gösteren popülerlik (popularity) ölçülerine göre yeniden sıralanır. Sayfaların büyük web çizgesindeki popülerliğini hesaplamayı sağlayan bu konu, bağlantı analizi, web yapı madenciliği (web structure mining) ve sosyal ağ analizi başlıkları altında incelenir.

Yapılan iş şudur: Elimizdeki karmaşık ağ (complex network) ya da sosyal ağ analiz edilir ve içindeki aktörlerin önemi bulunur. Bizim odaklandığımız durumda web sayfaları aktördür. Bir sayfanın içeriğinde başka bir sayfayı işaret eden köprü bağlantısı (hyperlink) varsa, bu bağlantı iki sayfa arasındaki ilişkiyi ifade eder. Çok sayıda sayfa birbirini bu şekilde işaret ettiği için bir araya geldiklerinde karmaşık bir ağ oluşur.

Bölüm boyunca şu sorular yanıtlanacaktır:

- Böyle bir ağ nasıl gösterilir, nasıl tanımlanır?
- Ağ üzerinde hangi ölçüler hesaplanır?
- Bir düğümün önem değeri nasıl hesaplanır?
- Sıralama (ranking) işlemi farklı algoritmalara göre nasıl gerçekleşir?

## 2. Sosyal Ağ Analiziyle Neler Çıkarılır?

Hoca bir sosyal ağ verisinin görselleştirilmiş hâlini ve aynı veriden çıkarılmış bir analiz sonucunu gösterdi. Veride düğümler, yani aktörler ve aralarındaki ilişkiler vardır. Amaç, bu verinin içinde gizli kalmış bilgileri çıkarmaktır. Analizde şu sorular sorulur:

- Ağda ne tür gruplar var, bu grupların görüşleri ne?
- Bu gruplar birbirleriyle nasıl etkileşiyor?
- Birbiriyle sık görüşen alt gruplar var mı?
- Yalıtılmış (isolated) gruplar, yani başkalarıyla hiç konuşmayıp yalnız kendi içinde konuşan gruplar var mı?

Bu soruların cevabı bir görselleştirme biçiminde raporlanabilir. Hoca bu noktada çeşitli analiz sonuçlarını örnek olarak gösterdi.

### 2.1 Gazete Haberleri

Hepimiz LinkedIn, Twitter, Instagram ve Facebook gibi ağların üyesiyiz. Ancak sosyal ağ analizi bu ortamlardan çok önce de yapılıyordu. Hocanın örneğinde farklı gazetelerin haberlerinde şehir ve kişi adları gibi herkesçe üzerinde hemfikir olunan özgün adlar geçer. Bir haberde bir şehir adı ile bir ekonomi terimi aynı paragrafta yakalanırsa, ikisi arasında bir ilişki kurulur. Aynı terim başka bir gazetede başka bir kişi tarafından kullanılırsa bu kez terim ile o kişi arasında ilişki kurulur. Bu özgün adlar üzerinden çıkarılan ağlarla, özellikle finans alanındaki olayları yorumlayan analizler yapılmıştır.

Bilgisayar mühendislerinin ve veri analistlerinin bugün bu konuyu yaygın biçimde çalışmasının ana nedeni ise şudur: Analiz sonucunda ortaya çıkan sıralamaların ve aktörlerin popülerlik değerlerinin günümüzdeki internet kullanımında çok yaygın bir etkisi vardır.

### 2.2 İnternet ile Web Farkı

Gösterilen bir görselleştirme internetin yapısını ifade ediyordu. Hoca burada daha önce yaptıkları ayrımı hatırlattı. İnternet, fiziksel veya sanal düğümlerin birbirleri arasındaki iletişim ağıdır. Altyapıdaki, dünya genelindeki geniş alan ağından (Wide Area Network) söz ederiz. Web ise bu ortamdaki sunucuların üzerinde duran yazılım katmanıdır. Sunuculardaki belgeler ve bu belgelerin içindeki köprü bağlantılarıyla birbirine verdikleri bağlantılardan oluşur. Demek ki web'in karmaşık ağı ile internetin karmaşık ağı birbirinden farklıdır.

### 2.3 Siyasi Bloglar

Amerikan seçimleri öncesinde kişisel bloğu olan insanların siyasi görüşlerini yazdığı sayfalar üzerinde bir analiz yapılmış, sayfalar Cumhuriyetçi ya da Demokrat olmalarına göre görselleştirilmiştir. İlginç sonuç şudur: Aynı görüşteki sayfalar hep birbirini işaret etmiştir. Bir sayfa kendi görüşünü anlatırken karşı görüşü savunanların sayfalarına bağlantı vermemektedir. Dolayısıyla Demokrat sayfalarda dolaşan biri Cumhuriyetçilerin görüşlerini hiç veya çok düşük olasılıkla görür. Diğer taraf için de aynısı geçerlidir.

### 2.4 Bir Şirketin E-posta Verisi

Bir şirketin e-posta veritabanı üzerinde yapılan analizde e-posta atan kişiler aktördür. Bir kişi diğerine e-posta attığında bu tek yönlü bir hareket olduğu için bir kenar (edge) olarak gösterilir. Sonuçta çalışanların ağırlıkla kendi departmanı içinde yazıştığı görülür. Bazı düğümler ise diğer bütün küçük gruplarla yoğun etkileşim içindedir. Buradan bu düğümlerin insan kaynakları çalışanları ya da orta ve üst düzey yöneticiler olduğu çıkarılabilir.

Böyle bir analizi kim ister? Hocanın örneği şudur: Yeni bir işletmeye genel müdür olarak atandınız. Oradaki ilişki ağını görmek için bilgi işlem biriminden geçmişe dönük e-postalar üzerinde böyle bir rapor isteyebilirsiniz. Rapordan insanların birbirinden kopuk çalıştığı ya da herkesle iletişimde olan belli aktörlerin diğer insanlara etkisinin yüksek olduğu gibi çıkarımlar yapılabilir.

### 2.5 Facebook Arkadaş Ağı

Facebook verisi üzerindeki analizde farklı arkadaş grupları farklı renklerle gösterilmiştir. Bazı düğümler diğerlerinden büyüktür, bu aktörlerin önem değeri daha yüksektir. Bazı alt ağlar ise başka kimseyle etkileşmez, yalnız kendi içinde etkileşir.

### 2.6 Yemek Tarifi Ağı

Bu örnekte yemek tarifi sayfaları analiz edilmiş, düğümler tariflerdeki malzemelerden (ingredient) oluşturulmuştur. Mantık, gazetelerdeki özgün adlar arasında ilişki kurmaya benzer: Aynı tarifte geçen malzemeler arasında ilişki kurulur. Çok tarifte geçen malzemeler görselde daha büyük yazılır.

Türk mutfağı tariflerini içeren çok sayıda belge üzerinde böyle bir analiz yapılırsa, yemeklerde ağırlıklı olarak hangi ürünlerin kullanıldığı görülür. Tereyağı, zeytinyağı, tuz ve yumurta gibi ürünlerin önemli olduğu çıkarılabilir. Buradan yeni tarifler bile çıkarılabilir. Hocanın uygulama örneği de şudur: Devlet planlama teşkilatı altında çalışan biri, Türkiye'de desteklenmesi gereken ürün altyapılarını ve fabrikaları belirlemek için bu tür bir analizden yararlanabilir. Çünkü analiz, yemek yeme alışkanlıklarımıza dayalı olarak talep ettiğimiz ürünleri öne çıkarır.

### 2.7 Çok Disiplinli Bir Konu, Farklı Terimler

Sosyal ağ çok disiplinli bir konudur. Sosyologlar, fizikçiler, matematikçiler ve bilgisayar bilimciler bu konuyu çalışır. Her disiplin aynı şeyler için farklı terim kullanabilir. Bilgisayar biliminde düğüm (node) ve bağlantı (link) denirken matematikte köşe (vertex) ve kenar (edge) denir. Bu yüzden yayınlarda aynı şeyin farklı adlarla geçtiğini görebilirsiniz.

## 3. Yönlü ve Yönsüz Çizgeler

Bir sosyal ağ yönlü çizge (directed graph) ya da yönsüz çizge (undirected graph) olabilir. Hoca bunu bir soruyla açtı.

**Soru:** LinkedIn yönlü müdür, yönsüz müdür?

**Cevap:** Bir öğrenci, etkileşim karşılıklı olduğu için yönsüz olduğunu söyledi. Hoca da bu cevabı doğruladı. LinkedIn'de kimin ilk olarak bağlantı daveti gönderdiği görülmez, bu yüzden yönsüzdür.

Hoca ardından diğer ortamları tek tek ele aldı:

- **Twitter:** Kimin kimi takip ettiği görülür, çıkarılan çizge yönlüdür.
- **Facebook:** Takip özelliği düşünülmezse kimin ilk olarak arkadaşlık isteği gönderdiği görülmez. Ancak Facebook'ta takip özelliği de vardır.
- **Instagram:** Kimin kimi takip ettiği görülür, çizge yönlüdür.
- **Web:** Web de bir sosyal ağdır. Köprü bağlantılarının yönü görülür, çizge yönlüdür.

Kural şudur: Çizgedeki ilişkilerin yönü görülemiyorsa çizge yönsüz, görülebiliyorsa yönlüdür.

## 4. Bağlantı Nitelikleri

Bağlantıların farklı nitelikleri (attribute) olabilir.

**Ağırlık (weight).** İki web sayfası düşünelim. Birinci sayfa aynı içerik içinde ikinci sayfaya çok sayıda bağlantı vermişse, bu ilişkinin ağırlığını yüksek tutmak gerekir. Bir başka örnek, kişiler arasındaki telefon konuşmalarının kayıtlarıdır (CDR verisi). Bir kişi diğerini çok defa aramışsa ilişkinin ağırlığı yüksek tutulur.

**Sıra (ranking).** Facebook arkadaşları gruplamaya izin verir: Hangileri okul arkadaşı, hangileri en yakın arkadaş, hangileri çocukluk arkadaşı. Bağlantılar "en iyi arkadaşım", "ikinci iyi arkadaşım" gibi bir sıraya oturtulabilir.

**Tür (type).** Aynı Facebook örneğinde bağlantılar kategorilere konabilir. Bu kategoriler içinde renklendirme de yapılabilir.

**Başka özellikler.** Bir bağlantının çok sayıda düğüm arasında bir yerde durduğu da bir özelliktir. Yani bir düğümden diğerine giderken kullanılan bu ilişki, çok sayıda farklı düğüm tarafından da kullanılabilir ve onları birleştiren önemli bir ilişki olabilir. Sosyal ağ analizinde ilişkiler incelenip gösterilirken bu niteliklerin hepsi kullanılabilir.

Hoca iki görselleştirme örneği verdi.

**Yurtta yemek masası tercihleri.** Bir yurtta insanların yemek masasında birlikte oturmak istediği arkadaşlar yönlü bir ağ olarak gösterilmiştir. Herkes iki kişi seçmiştir. Birinci tercih "1", ikinci tercih "2" ilişkisiyle gösterilir, yani ilişkinin türü belirlenmiştir. Ağa bakınca herkesin birlikte yemeğe gitmek istediği bazı kişiler görülür. Kimi hep birinci tercih olarak, kimi hem birinci hem ikinci tercih olarak istenmiştir. Böylece bir grup içindeki popüler kişiler belirlenir.

**Güven ağı.** Bu örnekte ilişkilere olumlu veya olumsuz ağırlık verilmiştir. Birçok sosyal ağda beğenme düğmesi vardır ama beğenmeme düğmesi genelde yoktur. Son zamanlarda bunun yerine duyguları ifade eden emojiler kullanılabilmektedir. Böyle bir veri varsa olumlu ilişkiler bir renkle, olumsuz ilişkiler başka bir renkle gösterilebilir. Gösterilen ağda kırmızı bağlantılar birbirine güvenmemeyi, yeşil bağlantılar güvenmeyi ifade eder. Bir gruptan sorumlu yönetici olduğunuzda, grubun geçmiş verilerini böyle analiz ederek grupta güven ortamı mı, güvensizlik ortamı mı olduğunu çıkarabilirsiniz.

## 5. Veri Gösterimleri

Özetle aktörlerimiz, aralarındaki ilişkiler ve bu ilişkilerin ağırlık, tür ve sıra gibi nitelikleri vardır. Bunları içerecek bir veri gösterimi gerekir. Yaygın üç gösterim vardır: komşuluk matrisi (adjacency matrix), kenar listesi (edge list) ve komşuluk listesi (adjacency list).

### 5.1 Komşuluk Matrisi

Matrisi $A$ ile gösterelim. Satırlardaki düğümler bağlantıyı veren, sütunlardaki düğümler bağlantıyı alan düğümlerdir.

$$A_{ij}=\begin{cases}1 & i\text{'den } j\text{'ye bağlantı varsa}\\ 0 & \text{yoksa}\end{cases}$$

Bir düğümün kendisine referansı varsa $A_{ii}=1$ olur, buna öz döngü (self loop) denir. Yoksa $A_{ii}=0$ olur. Yönsüz çizgede $i$ de $j$'ye, $j$ de $i$'ye bağlıdır. Oklar çıkarılabilir ve $A_{ij}=A_{ji}$ olur.

Hoca 5 düğümlü bir oyuncak örnek üzerinden matrisi okudu. Matris $5\times 5$ boyutundadır.

- **1. düğüm:** Bağlantı almış ama kimseye bağlantı vermemiştir. Satırının bütün elemanları $0$'dır.
- **5. düğüm:** 1. ve 2. düğümlere bağlantı vermiştir. Bu iki hücre $1$, satırın geri kalanı $0$'dır.

> **Ders sonrası not:** Hoca 5. düğümün satırını okurken "A11 ve A12 değerleri 1" dedi; doğrusu $A_{51}=A_{52}=1$ olmalıdır, çünkü okunan satır 5. satırdır.

### 5.2 Kenar Listesi

Aynı ağ kenar listesiyle de gösterilebilir. Çizgedeki bütün yönlü bağlantılar, kaynak (source) ve hedef (destination) olacak biçimde tek tek yazılır. Hocanın okuduğu satırlar şunlardır:

```text
2 3
2 4
3 2
3 4
...
```

### 5.3 Komşuluk Listesi

Üçüncü gösterimde düğüm sayısı kadar satır vardır. Her düğümün yanına iki nokta konur ve verdiği bağlantılar sıralanır. 1. düğümün verdiği bağlantı yoktur, bu yüzden yanı boş kalır. 2. düğümün verdiği bağlantılar 3 ve 4'tür. Aynı şekilde 1. düğümden $n$. düğüme kadar her düğümün komşuları yazılır.

```text
1:
2: 3, 4
3: 2, 4      (ara adım eklendi, kenar listesinden)
4: ...
5: 1, 2      (ara adım eklendi, 5.1'den)
```

<!-- BELİRSİZ: Slayttaki 5 düğümlü örneğin 4. düğüm satırı altyazıda okunmuyor. Kenar listesinin devamı da yalnız sözlü olarak "bütün linkler" diye geçiyor. -->

Demek ki aynı ağ için üç farklı gösterim vardır ve hepsinin farklı kullanımları vardır.

## 6. Derece, Derece Dizisi ve Derece Dağılımı

Ağ matris olarak gösterildikten sonra üzerinde tanımlayıcı ölçüler hesaplanabilir. Bunlardan biri derecedir (degree). Bir görselleştirmede bazı düğümlerin daha büyük çizilmesi, bu düğümlerin çok sayıda farklı düğümle etkileşimde olduğunu gösterir, yani sahip oldukları bağlantı sayısı yüksektir.

Derece kendi içinde ayrılır:

- **Giriş derecesi (in-degree):** Bir düğüme gelen bağlantıların sayısı.
- **Çıkış derecesi (out-degree):** Bir düğümden dışarı çıkan bağlantıların sayısı.
- **Derece (degree):** Gelen ve giden bağlantıların toplamı.

Derece aslında merkeziliği ifade eder. Bir düğümün ne kadar çok farklı düğümle ilişkide olduğunu gösterdiği için buna derece merkeziliği (degree centrality) denir.

### 6.1 Komşuluk Matrisinden Derece Hesabı

Satırlar bağlantı verenleri, sütunlar alanları gösterdiği için hesap kolaydır. $i$. satırdaki elemanların toplamı $i$ düğümünün çıkış derecesini, bir sütundaki elemanların toplamı o düğümün giriş derecesini verir.

$$d_O(i)=\sum_{j}A_{ij},\qquad d_I(i)=\sum_{j}A_{ji}$$

5 düğümlü örnekte 3. düğümün giriş derecesi $1$ (2. düğümden gelir), çıkış derecesi $2$'dir (2. ve 4. düğümlere gider).

### 6.2 Derece Dizisi ve Derece Dağılımı

Hoca verilen bir ağı "tanıtmak" için derecelerin kullanılabileceğini söyledi. Bunun bir yolu derece dizisidir (degree sequence). Örnekte 8 düğümlü bir ağ vardır. Düğümler sırayla yazılır, her birinin giriş derecesi verilir: 1. düğüm 2, 2. düğüm 2, 3. düğüm 2, 4. düğüm 1 ve son düğüm 0. Aynı liste çıkış derecesi için de yazılabilir. Çizge yönsüzse her düğümün toplam derecesi yazılır.

Bu diziden derece dağılımı (degree distribution) tablosu elde edilir:

| Giriş derecesi | Düğüm sayısı |
|---|---|
| 2 | 3 |
| 1 | 4 |
| 0 | 1 |

Toplam $3+4+1=8$ düğüm eder. Bu tablo dizinin tamamının $2,2,2,1,1,1,1,0$ olduğunu gösterir (ara adım eklendi). Tablo çubuk grafik olarak da çizilebilir ve ağ buna bakılarak yorumlanır. Örneğin giriş derecesi $0$ olan düğümlerin sayısı çok büyük olsaydı, "bu ağda hiç bağlantı almamış yalıtılmış düğüm sayısı çok fazla" diyebilirdik.

Oyuncak örnekte bunu gözle de görürsünüz. Ama içinde 10 milyon düğüm olan, veritabanında duran ve görselleştirmesi kolay olmayan bir ağda böyle bir görsel analiz çok zordur. O zaman derece dizisi yazılır, derece dağılımı tablosu çıkarılır ve düğümlerin bağlantılılığı (connectivity) hakkında yorum yapılır. Tablonun asıl anlamı büyük ağlarda ortaya çıkar.

## 7. Bileşenler

Bir sosyal ağda her şey bağlantılı olmak zorunda değildir. Küçük adacıklar da, büyük bağlı bir yapı da, bu yapı içinde farklı gruplar da olabilir. Bu bileşenleri (component) tespit etmek isteriz. Hoca 8 düğümlü (A–H) oyuncak bir ağ üzerinden anlattı.

**Güçlü bağlı bileşen (strongly connected component).** Bileşen içinde herhangi bir düğüm seçildiğinde o düğümden diğer herhangi bir düğüme gidilebilir. Yani herkes herkese gidebilir. Örnekte:

- $\{B, C, D, E\}$: Hangi düğümden başlanırsa başlansın diğerlerine ulaşılır.
- $\{G, H\}$: Biri diğerine ulaşabilir.
- Tek düğümlü bileşenler: $\{F\}$ ve hocanın ayrıca gösterdiği tek düğüm. Bu düğüm yalnız kendisine ulaşabilir. Kalan düğüm A olduğu için bu bileşen $\{A\}$'dır (ara adım eklendi).

**Zayıf bağlı bileşen (weakly connected component).** Hoca bunu şöyle tanımladı: Her düğümden her düğüme ulaşmak zorunlu değildir, her düğüm bir şekilde bazı bağlantıları izleyerek ulaşılabilir olmalıdır. Örnekte:

- $\{A, B, C, D, E\}$
- $\{F, G, H\}$: F'den başlanırsa G ve H'ye ulaşılır.

> **Ders sonrası not:** Hocanın zayıf bağlılık tanımı biraz gevşek kaldı. Standart tanım büyük olasılıkla ders kitabında da şöyledir: Kenarların yönü göz ardı edildiğinde bileşendeki her düğüm çifti arasında bir yol vardır. Tanımda "her düğüme yönlü olarak ulaşılabilmesi" aranmaz.

Bileşenleri çıkarırken hangi tanımın kullanılacağı (güçlü ya da zayıf) seçilir, alt gruplar buna göre belirlenir.

**Dev bileşen (giant component).** Alt bileşenlerden biri içerdiği eleman ve bağlantı sayısı bakımından diğerlerinden çok büyükse ona dev bileşen denir.

Hoca buraya kadarki kısmı şöyle topladı: Sosyal ağlar matris, kenar listesi ve komşuluk listesi olarak gösterilebilir. Ağlar derece değerleriyle tanımlanabilir, derece dağılımı grafikleri çıkarılabilir. Ağ içindeki bileşenler güçlü, zayıf ve dev bileşenler olarak belirtilebilir.

<!-- BELİRSİZ: A–H örneğinin kenarları slaytta; altyazıda yalnız bileşen sonuçları sözlü olarak geçiyor. -->

## 8. Merkezilik Ölçülerine Giriş

Derecenin yanı sıra başka merkezilik (centrality) ölçüleri de vardır. Üç ölçüyü kısaca şöyle ayırabiliriz:

- **Degree centrality:** Bir düğüm kaç farklı düğümle ilişkide?
- **Betweenness centrality:** Bir düğüm kaç farklı düğüm ikilisinin arasında?
- **Closeness centrality:** Bir düğüm ağdaki diğer düğümlere ne kadar yakın? O düğümden başlayarak diğerlerine kısa sürede ulaşılabiliyor mu?

**Soru:** Betweenness şöyle mi işliyor: 1, 2, 3 düğümleri olsun, birden ikiye, ikiden üçe mi bir kenar oluşacak? Aracı düğüm mü oluyor?

**Cevap:** Hoca örneği 5 düğüme genişletti. 1 yalnız 2 ile, 2 yalnız 3 ile, 3 yalnız 4 ile, 4 yalnız 5 ile konuşabilsin. Bir, iki, üç için en önemli kişi 2, sondaki üç düğüm için 4'tür. Birden beşe kadar bakınca en önemli kişi 3 olur. Çünkü 1 hem 4 hem de 5 ile konuşmak için 3'ten geçmek zorundadır, bu iki ikili eder. 2 de 4 ve 5 ile konuşmak için 3'ten geçer, bu da iki ikili eder. Böylece 3, dört farklı ikilinin konuşma yolu üzerindedir: 1–4, 1–5, 2–4, 2–5. Bir düğüm ne kadar çok ikilinin konuşma yolu üzerindeyse önem değeri o kadar artar. Gerçek hayatta da birbiriyle konuşmayan iki grubu birleştiren kişiler vardır. Grup üyeleri arasında doğrudan iletişim yoktur ama bilgi sürekli bu kişi üzerinden bir gruptan diğerine taşınır. O kişinin betweenness değeri çok yüksektir.

## 9. Derece Neden Tek Başına Yetmez?

> **Hocanın vurgusu:** Degree, betweenness ve closeness olmak üzere bu üç ölçü bizim için önemli. Bu yüzden derinlemesine bakacağız.

### 9.1 Ölçüye Göre Görselleştirme

Sosyal ağ raporlarındaki görselleştirme seçilen ölçüye göre yapılır. Hocanın gösterdiği bir ağda düğüm büyüklükleri degree centrality değerine göre çizilmiştir. Kimball ve Gerard adlı düğümler, bağlantı sayıları yüksek olduğu için daha büyük görünür. Başka bir görselleştirmede düğüm büyüklüğünün yanında ilişkiler de ağırlıklarına göre gösterilmiştir. Leonard ile Teddy arasındaki ilişki daha kuvvetlidir. Bu ağırlık aralarında geçen konuşma veya e-posta sayısı olabilir.

### 9.2 Orkut Örneği

Bir ağın yakın görünümünde Orkut adlı bir düğüm vardır. Bağlantı sayısı yanındaki kırmızı düğümden çok daha fazladır. Bu yüzden degree centrality'ye göre Orkut daha önemli denebilir. Hoca sonra ağın tamamını gösterdi. Orkut aslında toplam ağ içinde çok ufak bir alanda duran bir düğümdür, ağın merkezinde değildir. Bağlantı sayısı fazladır ama ağın geneline bakıldığında önemli bir yerde durmaz. Demek ki bağlantı sayısı tek başına yeterli değildir. Betweenness ve closeness ölçülerine de ihtiyaç vardır.

### 9.3 X ve Y Düğümleri

Bir aktörün ağdaki önemi belirtilirken üç ölçüye birden bakılır. Degree centrality hesaplanırken giriş veya çıkış derecesi kullanılabilir. Merkezilik için genelde kullanılan çıkış derecesidir. Hoca aynı çizgedeki X ve Y düğümlerini üç ölçüye göre karşılaştırdı.

- **Degree:** X'in dışarı verdiği 5 bağlantı var, Y'nin 0. X daha önemlidir.
- **Betweenness:** Bir düğüm X üzerinden iki düğümle, başka bir düğüm de X üzerinden aynı iki düğümle konuşur. Böylece $2+2=4$ ikili eder. Y için ise bir düğüm, Y üzerinden gitmeyi tercih ederse üç düğümle konuşabilir, bu 3 ikili eder. Fakat bu üç ikili konuşurken Y'yi atlayıp başka yoldan da gidebilir. X ise dört ikilinin yolu üzerinde kesin olarak durur. X daha önemlidir.
- **Closeness:** X'ten bütün düğümlere bir veya iki adımda ulaşılır. Bu uzaklıklar toplandığında Y'den başlayarak ortalama ulaşma uzaklığından daha kısadır. X daha önemlidir.

> **Ders sonrası not:** Bu örnekte iki nokta tutarsız kalıyor. Birincisi, Y'nin çıkış derecesi $0$ ise yönlü bir çizgede Y'den hiçbir yol devam edemez, yani Y hiçbir ikilinin yolu üzerinde olamaz. Hoca betweenness sayımında büyük olasılıkla bağlantıları yönsüz gibi ele almıştır. İkincisi, Y'nin alternatif yolla atlanabildiği ikililer 13. bölümdeki formüle göre tam $1$ katkı yapmaz. Dolayısıyla Y için söylenen $3$ değeri "en fazla üç ikili" gibi okunmalıdır.

<!-- BELİRSİZ: X–Y çizgesinin tam yapısı slaytta. Altyazıda X'in 5 bağlantısı ile "dört ikili" sayımı birlikte geçiyor ama kenarlar okunmuyor; uzaklık değerleri de sözlü ve eksik. Bu yüzden closeness sayısal olarak hesaplanamadı. -->

### 9.4 Petrol Ticareti Örneği

Hoca derecenin yönüne göre çizimin neyi değiştirdiğini bir ağla gösterdi. Bu ağ, ülkelerin petrol alım satımına dayanır. Bağlantı kalınlığı ilişkinin ağırlığını, yani miktarı gösterir.

Giriş derecesine göre çizildiğinde ABD ve Japonya öne çıkar. ABD Venezuela, Meksika, Kanada, Irak ve Suudi Arabistan'dan, Japonya ise Suudi Arabistan ve Birleşik Arap Emirlikleri'nden petrol alır. "Hangi ülkelerin giriş derecesi yüksek?" sorusu grafiğe bakılarak hızla yanıtlanır. Yani bu raporlar, veriden yapılması gereken çıkarımları görsel olarak kolaylaştırır.

Çıkış derecesine göre çizildiğinde Suudi Arabistan'ın düğümü en büyük görünür, çünkü dış dünyaya verdiği petrol miktarı çok yüksektir. Venezuela ve Birleşik Arap Emirlikleri de petrol verir ama düğümleri daha küçüktür. Hoca şu soruyu sordu: Çıkış derecesi düşük olup önemli miktarda petrol gönderen ülke hangisidir? Cevap Venezuela ve Birleşik Arap Emirlikleri'dir. Çıkış bağlantıları Suudi Arabistan'a göre azdır ama dış dünyaya önemli miktarda petrol sağlarlar.

## 10. Degree Centrality Hesabı

Yönsüz çizgede gelen ve giden bağlantı ayrımı yoktur, doğrudan bağlantı sayısına bakılır. Normalize etmek için değer, kendisi dışındaki düğüm sayısına, yani $n-1$'e bölünür.

$$C_D(i)=\frac{d(i)}{n-1}$$

Hoca üç oyuncak ağ üzerinde hesapladı.

**Yıldız çizgesi (6 düğüm).** Ortadaki düğümün 5 bağlantısı, uçtaki beş düğümün birer bağlantısı vardır. $n-1=5$'tir.

- Merkez: $5/5=1$
- Uçlar: $1/5=0{,}2$

**Zincir (5 düğüm).** Ortadaki ve onun iki yanındaki düğümlerin ikişer bağlantısı, en uçtakilerin birer bağlantısı vardır. $n-1=4$'tür.

- Ortadaki üç düğüm: $2/4=0{,}5$
- İki uç: $1/4=0{,}25$

**7 düğümlü ağ.** Bir yanda 3, öbür yanda 3 düğüm ve ortada bir düğüm vardır. $n-1=6$'dır.

- 2 bağlantılı düğüm: $2/6$
- 3 bağlantılı düğümler: $3/6=0{,}5$

Altyazıdaki sayımlardan (13.3 ve 14.3. bölümler) bu ağın yapısı şöyle çıkarılabilir: İki üçgen, tek bir orta düğüm üzerinden birbirine bağlıdır (ara adım eklendi).

```text
S1 --- S2         T2 --- T3
  \    /            \    /
   \  /              \  /
    S3 ---- M ------- T1
```

<!-- BELİRSİZ: 7 düğümlü ağın çizimi slaytta. Yukarıdaki yapı ve düğüm adları, hocanın söylediği derece, betweenness ve closeness sayılarıyla tutarlı olan yeniden kurulumdur. -->

## 11. Ağın Merkezileşme Değeri

Bir düğüm için hesaplanan degree centrality, bütün ağ için de hesaplanabilir. Buna merkezileşme (centralization) denir. Ağdaki en yüksek dereceli düğümün değerinden her düğümün değeri çıkarılır, farklar toplanır ve $(n-1)(n-2)$ ile bölünerek normalize edilir.

$$C_D=\frac{\sum_{i}\left[d(i^*)-d(i)\right]}{(n-1)(n-2)}$$

Burada $i^*$ en yüksek dereceli düğümdür.

**Yıldız çizgesi (6 düğüm).** En yüksek derece $5$, uçlarınki $1$'dir.

1. Her uç için fark: $5-1=4$.
2. Beş uç için farkların toplamı: $4\times 5=20$. Merkezin kendi farkı $0$'dır.
3. Payda: $n-1=5$, $n-2=4$, $5\times 4=20$.
4. Sonuç: $20/20=1$.

> **Ders sonrası not:** Hoca hesapta "maksimumla minimum arasındaki farkların toplamı" dedi; doğrusu, formülde olduğu gibi en büyük değer ile her düğümün değeri arasındaki farkların toplamıdır. Yıldız çizgesinde bütün uçlar en küçük değere sahip olduğu için iki ifade aynı sonucu verir. Ayrıca hoca paydayı bir yerde "toplamdaki eş sayısı" diye adlandırdı, bu ifade altyazıda anlaşılmıyor; işlem $(n-1)(n-2)$ iledir.

> **Ek bilgi (derste anlatılmadı):** Payda keyfî değildir. Yönsüz basit bir çizgede farklar toplamının alabileceği en büyük değer yıldız çizgesinde oluşur. $n-1$ uç düğümün her biri için fark $(n-1)-1=n-2$'dir, toplam $(n-1)(n-2)$ eder. Bu yüzden ölçü yıldız çizgesinde tam $1$ olur ve değerler $0$ ile $1$ arasında kalır.

Sonuç yorumlanırken şunlara bakılır:

- Tek düğüm etrafında toplanmış merkezî bir çizgede değer $1$'e yakındır.
- Yatay eksende dağılmış bir çizgede, yani zincirde değer $0$'a yakındır.
- İki kümenin orta düğüm üzerinden bağlandığı 7 düğümlü ağda da tek düğüm etrafında toplanma yoktur. Orta düğümün yalnız iki bağlantısı vardır, değer $0$ yönündedir.

Hoca iki ağı yan yana gösterip hangisinin merkezileşmesinin yüksek olduğunu sordu. Solda çok sayıda düğümle konuşan büyük bir düğüm vardır ve ağ ağırlıkla onun etrafında toplanmıştır, değer yüksektir. Sağda birbirine eşit önemde çok sayıda düğüm vardır, ağ bunların etrafına dağılmıştır, değer düşüktür.

> **Hocanın vurgusu:** Aklınızda kalsın diye tekrar: Bir ağda tek büyük merkezî düğüm varsa ve her şey onun etrafında dönüyorsa merkezileşme değeri yüksek olur. Birbirine eşit önemde çok sayıda düğüm varsa bu değer düşüktür.

Bu değerin yararı şudur: Bir çizge için merkezileşme hesaplanarak, çizge görselleştirilmeden önce onun hakkında bir şeyler söylenebilir.

## 12. Degree Centrality'nin Yakalayamadıkları

Degree centrality iki şeyi yakalayamaz: Düğümün kaç düğümün iletişim yolu üzerinde olduğunu (betweenness) ve o düğümden diğerlerine ne kadar kolay gidilebildiğini (closeness).

Hoca bunu iki oyuncak ağla gösterdi. 7 düğümlü ağdaki orta düğüm, $3\times 3=9$ farklı ikilinin konuşma yolu üzerindedir. Ama degree centrality'ye göre bu düğüm hemen yanındaki düğümlerden daha düşük öneme sahiptir ($2/6$ ile $3/6$). Zincirdeki ortadaki düğümden ise diğer düğümlere kolayca ulaşılır. Ama degree centrality yakınlığı ölçmediği için onun önemini yanındakilerle eşit tutar ($2/4$). Oysa bu değerin daha yüksek olması gerekir. Daha önceki Orkut örneğinde de degree yüksek, betweenness ve closeness düşüktür.

## 13. Betweenness Centrality Hesabı

Bir $i$ düğümü için kaç ikilinin yolu üzerinde olduğu sayılır ve bu değer, ikili arasındaki toplam yol sayısıyla dengelenir. $j$ ile $k$ arasındaki yol sayısı $p_{jk}$, bunlardan $i$ üzerinden geçenlerin sayısı $p_{jk}(i)$ ise:

$$C_B(i)=\sum_{j<k}\frac{p_{jk}(i)}{p_{jk}}$$

> **Ders sonrası not:** Hoca anlatımda yalnız "yol" ve "path sayısı" dedi. Tanımda sayılan yollar büyük olasılıkla ders kitabındaki gibi en kısa yollardır (shortest path). Aşağıdaki örneklerin hepsi bu okumayla da tutarlıdır.

Hoca aşağıdaki örneklerin hepsini önce normalize etmeden hesapladı.

> **Ek bilgi (derste anlatılmadı):** Derste normalleştirilmiş betweenness hesaplanmadı. Yönsüz çizgede yaygın normalleştirme, değeri olası en büyük ikili sayısına, yani $(n-1)(n-2)/2$'ye bölmektir. Böylece farklı boyuttaki ağlardaki değerler karşılaştırılabilir hâle gelir.

### 13.1 Yıldız Çizgesi

Ortadaki düğümün çevresinde beş uç vardır. İkililer tekrar sayılmayacak şekilde, uçlar birer birer ele alınır:

1. Birinci uç, merkez üzerinden diğer 4 uçla konuşur: $4$.
2. Birinci uç sayıldı. İkinci uç kalan 3 uçla konuşur: $3$.
3. Üçüncü uç kalan 2 uçla konuşur: $2$.
4. Dördüncü uç kalan 1 uçla konuşur: $1$.

Merkezin değeri: $4+3+2+1=10$. Uçlar hiçbir ikilinin yolu üzerinde değildir, değerleri $0$'dır.

### 13.2 Zincir A–B–C–D–E

```text
A --- B --- C --- D --- E
```

- **C:** A, C üzerinden D ve E ile konuşur, bu $2$ ikili eder. B de D ve E ile konuşur, bu da $2$ eder. Toplam: $4$.
- **B:** A, B üzerinden C, D ve E ile konuşur. Toplam: $3$.
- **A ve E:** Hiçbir ikilinin yolunda değildir, $0$.

### 13.3 7 Düğümlü Ağ

**Orta düğüm.** Bir yandaki üçlüden her düğüm, orta düğüm üzerinden öbür yandaki üç düğümle konuşur. Üç düğümden $3$'er ikili gelir: $3+3+3=9$.

**Orta düğümün yanındaki düğüm.** Bu düğümün arkasındaki iki düğümün her biri, onun üzerinden öbür taraftaki dört düğümle konuşur: $4+4=8$.

### 13.4 Alternatif Yol Örneği

> **Hocanın vurgusu:** Bu örnek önemli, iyi takip edin.

Ağın yapısı şöyledir. C ve D birbirine bağlı değildir, ama hem B hem de E üzerinden konuşabilir.

```text
        C
       / \
A --- B   E
       \ /
        D
```

**A:** Hiçbir ikilinin yolu üzerinde değildir: $0$.

**B:** Slaytta değer $3{,}5$'tir. Buçuğun nereden geldiğine dikkat edelim.

1. A, B üzerinden C, D ve E ile konuşur. Bu üç ikilinin her biri için B zorunlu geçittir: $3$.
2. C ve D, B üzerinden konuşabilir. Ama ikisinin E üzerinden de konuşma seçeneği vardır.
3. Formüle dönelim: Pay, ikilinin B üzerinden konuşabildiği yol sayısıdır ($1$). Payda, ikilinin toplam yol sayısıdır ($2$). C–D ikilisinin katkısı: $1/2=0{,}5$.
4. Toplam: $3+0{,}5=3{,}5$.

**E:** E yalnız C–D ikilisinin arasındadır. C ile D arasında iki yol vardır, E bunlardan birinin üzerindedir: $1/2=0{,}5$.

### 13.5 Betweenness Değerine Göre Çizim ve Sınıf Soruları

Betweenness değerine göre çizilen bir ağda çok sayıda düğüm arasında kalan düğümler daha büyük görünür. Hoca böyle bir ağ gösterip iki soru sordu.

**Soru:** Betweenness değeri yüksek ama degree değeri düşük düğüm hangisidir?

**Cevap:** Bir öğrenci G dedi, hoca doğruladı. G'nin bir yanında 6, öbür yanında 5 düğüm vardır. Bu nedenle G, $6\times 5=30$ ikilinin konuşma yolu üzerindedir ve degree değeri $2$'dir. H'nin bir yanında 7, öbür yanında 4 düğüm vardır: $7\times 4=28$ ikili, degree yine $2$. G hem en yüksek betweenness hem de düşük degree değerine sahiptir.

**Soru:** Betweenness değeri düşük ama degree değeri yüksek düğümler hangileridir?

**Cevap:** A, B, C, D, E ve F. Bunlar birbirleriyle doğrudan konuşabildiği için birbirlerinin yolunda durmazlar. Degree değerleri ise yüksektir: F'nin 5, A'nın 5, E'nin 5 bağlantısı vardır.

> **Ders sonrası not:** G'nin degree değeri $2$ ise G'nin sol taraftaki altı düğümden yalnız birine bağlantısı vardır. O düğüm, kendi tarafındaki diğer düğümlerin G'ye giden yolu üzerinde durur. Bu yüzden büyük olasılıkla hocanın saydığı A–F düğümlerinin hepsinin değeri düşük olamaz, bağlantı noktası olan düğüm bu genellemenin dışında kalmalıdır.

<!-- BELİRSİZ: G ve H'nin bulunduğu ağın çizimi slaytta; altyazıda kenarlar okunmuyor, bağlantı noktası olan düğüm belirlenemiyor. -->

## 14. Closeness Centrality Hesabı

### 14.1 Sezgi: Genel Müdürün Danışmanı

Closeness, bir düğümün ağdaki diğer düğümlere ortalama ne kadar yakın olduğunu ifade eder. Hoca bir oyuncak ağda mor renkli bir düğüm gösterdi. Bu düğümün bir tek bağlantısı vardır, dolayısıyla degree değeri düşüktür. Betweenness değeri de düşüktür. Ama closeness açısından önem değeri çok yüksektir.

Bunu bir genel müdürün danışmanı gibi düşünebiliriz. Danışman, genel müdürle istediği zaman konuşabilir, onu etkileyebilir ve yönlendirebilir. Bu çok önemli bir roldür. Ama şirkette çalışanlarla çok etkileşim hâlinde değildir, bu yüzden betweenness değeri düşüktür. Dışarıdan geldiği için çalışanlarla tanışıklığı da azdır, degree değeri de düşüktür. Yine de önem derecesi büyük olmalıdır. Closeness bunu yakalar.

### 14.2 Formül

Bir düğümün diğer bütün düğümlere uzaklıkları toplanır ve bu toplamın tersi alınır. Normalize etmek için $n-1$ ile çarpılır. Nihai biçim:

$$C_C(i)=\left(\frac{\sum_{j=1}^{n} d(i,j)}{n-1}\right)^{-1}$$

### 14.3 Örnekler

**Zincir A–B–C–D–E, A düğümü.** A'nın B'ye, C'ye, D'ye ve E'ye uzaklıkları sırasıyla $1, 2, 3, 4$'tür.

1. Toplam: $1+2+3+4=10$.
2. Kendisi dışında 4 düğüm vardır: $10/4=2{,}5$.
3. Tersi: $(10/4)^{-1}=0{,}4$.

Hoca, hesap yapmadan da çizgeye bakarak sıralama yapılabileceğini söyledi: C en ortadadır, ondan sonra B ve D, sonra A ve E gelir. Bu sıralama hesapla da doğrulanır (ara adım eklendi):

- C: Uzaklıklar toplamı $2+1+1+2=6$, değer $(6/4)^{-1}\approx 0{,}67$.
- B ve D: Uzaklıklar toplamı $1+1+2+3=7$, değer $(7/4)^{-1}\approx 0{,}57$.
- A ve E: Değer $0{,}4$.

**Yıldız çizgesi (6 düğüm), merkez.** Merkezin beş uca uzaklığı birer adımdır. Toplam $5$, $n-1=5$, değer $(5/5)^{-1}=1$. Çizgeye bakınca da merkezden diğer düğümlere kolayca gidildiği görülür.

Hoca uçlar için "aynı şekilde hesaplanır" dedi. Bir ucun merkeze uzaklığı $1$, diğer dört uca uzaklığı $2$'dir. Toplam $1+4\times 2=9$, değer $(9/5)^{-1}\approx 0{,}56$ (ara adım eklendi).

**7 düğümlü ağ, orta düğüm.** Bir taraftaki düğümlere uzaklıklar $1, 2, 2$'dir, bu $5$ eder. Öbür taraftan da $5$ gelir.

1. Toplam: $5+5=10$.
2. $n-1=6$.
3. Değer: $(10/6)^{-1}=0{,}6$.

### 14.4 Sınıf Sorusu

**Soru:** Bu çizgede degree değeri yüksek ama closeness değeri düşük bir düğüm söyleyin.

**Cevap:** Hoca, öğrencinin soruyu ters anlaması üzerine soruyu netleştirdi: closeness düşük, degree ise görece yüksek olacak. Cevap O düğümüdür. O'nun 3 bağlantısı vardır, diğerlerinin ise 1 veya 2 bağlantısı vardır. Yani degree değeri görece yüksektir. Ama uçta durduğu için diğer düğümlere ulaşması bir tık daha zordur, closeness değeri düşüktür. I düğümü ise bu soruya cevap olamaz. Degree değeri çok yüksektir ve diğer düğümlere kolayca ulaşılabilecek bir yerde durduğu için closeness değeri de yüksektir.

## 15. Arama Motorlarında Bağlantı Analizinin Tarihçesi

Son aradan sonra hoca, sosyal ağ analizinin web'de ve özellikle arama motorlarında nasıl kullanıldığına döndü.

İlk arama motorları TF-IDF ve kosinüs benzerliği (cosine similarity) gibi anahtar kelime ile belge arasındaki benzerliğe dayanan yöntemler kullanıyordu. Bir kelimeyle en iyi eşleşen belgeler benzerlik değerine göre yukarıdan aşağıya sıralanıp kullanıcıya gösteriliyordu. Ancak sayfalar sonuçlarda üst sıralara çıkmak için kendi içeriklerine farklı anahtar kelimeler koymaya başladı. Bu da yöntemi kolayca kandırılabilir (spam) hâle getirdi. 1996 dolaylarında içerik benzerliğine dayalı arama motorlarının başarılı olmadığı ortaya çıkınca bağlantı tabanlı yöntemlerle popülerlik sıralamasının nasıl yapılabileceği üzerine çalışılmaya başlandı.

1997 ve 1998 yılları bu açıdan önemlidir:

- **1997:** Köprü bağlantılarının üzerindeki anahtar kelimelere dayanan bir arama motoruyla ilgili bir patent alındı.
- **1997–1998:** Biri Cornell'den, biri Stanford'dan iki grup, web sayfalarının birbirine verdiği bağlantılara dayanarak sayfaların popülerliğini belirleyen iki algoritma çıkardı. Yayınlardan biri 1998 Ocak, diğeri 1998 Nisan ayında çıktı.
- **HITS:** Hocaya göre daha sonra Yahoo'nun bağlantı tabanlı algoritması oldu.
- **PageRank:** Daha sonra Google'ın bağlantı tabanlı algoritması oldu.

> **Ders sonrası not:** Hoca HITS'in Yahoo'nun algoritması olduğunu söyledi. Bu bilgi altyazıdan doğrulanamıyor. HITS'in ticari kullanımıyla büyük olasılıkla daha çok Teoma (sonraki adıyla Ask) arama motoru anılır; bu cümle ihtiyatla okunmalıdır. Hocanın sözünü ettiği 1997 patenti de büyük olasılıkla 1997'de başvurusu yapılmış, sonradan verilmiş bir patenttir.

İki algoritma da düğümlerin popülerlik değerlerini bularak sıralamaya olanak verir. Kullanımı şöyledir: Bir anahtar kelime ters dizinde aranır. O kelimeyi içeren sayfaların TF-IDF değerine göre sıralanmış listesi alınır. Liste, bağlantı analizinden çıkan popülerlik değerlerine göre yeniden sıralanır. Yani sayfalar hem TF-IDF hem bağlantı analizi sonucuna göre sıralanıp kullanıcıya gösterilir.

Popülerlik değerleri yalnız aramada kullanılmaz:

- Web üzerindeki alt toplulukları (sub-community) tespit etmek.
- Dersin önceki bölümünde görüldüğü gibi e-postaları analiz etmek.
- Serbest metin belgelerdeki özgün kelimeler arasında ilişki kurarak bir ilişki ağı çıkarmak.

Hoca, sosyal ağ analizinin önceki slaytlarda işlenen aktör, ilişki, komşuluk matrisi, kenar listesi, komşuluk listesi ve üç merkezilik ölçüsü kısımlarını tekrarlamadan geçti.

> **Ders sonrası not:** Hoca burada "daha önceki dört derste" konuştuklarını söyledi. Aynı konular bu dersin önceki bölümlerinde işlendiği için büyük olasılıkla "dersin önceki bölümlerinde" demek istemiştir. Altyazıda hemen öncesinde de "bir önceki dersin bölümleri" ifadesi geçer.

## 16. Topluluk Keşfi ve Kümeleme

**Soru:** Sosyal ağ analizinde topluluk (community) dediğimiz şeylerin, gözetimsiz öğrenmedeki (unsupervised learning) küme (cluster) kavramına benzer özellikleri var mı?

**Cevap:** Aynı şeyler değildir ama benzetme kurulabilir. Kümelemede (clustering) gözetimsiz bir yöntemle veri kümesindeki birbirine benzer noktalar gruplanır. Sosyal ağdaki topluluk keşfinde (community discovery) ise önce belli ölçüler belirlenir. Örneğin giriş derecesi ölçüsüne dayalı alt topluluk keşfi yapılacağı söylenir. Ardından insanların birbirine verdiği ve aldığı bağlantılara dayanarak güçlü veya zayıf bağlı alt gruplar bulunur. Biri veri kümesinde birbirine benzer noktaları gruplar, diğeri ağda belli bir ölçüye dayalı olarak birbirine bağlantı vermiş düğümleri ayırır.

Topluluk keşfinin nerede kullanıldığına örnek olarak hoca, araştırma grubunun bir telekom firması için yaptığı müşteri kaybı (churn) analizi çalışmasını anlattı:

1. Alt topluluk keşfi algoritmalarıyla alt topluluklar bulunur. Bir alt topluluktaki insanlar birbiriyle çok yoğun konuşan insanlardır.
2. Bunlardan biri o şirketi bırakıp başka bir operatöre geçerse, grubun diğer üyelerinin de bundan etkileneceği varsayılır. Çünkü bu kişiler birbiriyle çok yakın konuşan bir arkadaş grubudur.
3. Henüz ayrılmamış kişilere indirim ve memnuniyet sağlayacak teklifler gibi aksiyonlarla gidilir.
4. Böylece terk etme davranışı sistemde kalma davranışına dönüştürülmeye çalışılır.

## 17. Prestij Ölçüleri

Şimdiye kadar düğümlerin önemine merkezilik açısından bakıldı. Şimdi önemi belirten ikinci kategoriye, prestije (prestige) geçiyoruz.

Prestij popülerlik gibi düşünülebilir: Başkaları tarafından ne kadar tercih ediliyorsunuz? Merkezilik ise tercih edilmeye değil, ağ üzerinde closeness, betweenness veya degree açısından ne kadar ortada olduğunuza bakar. Bu nedenle prestij daha çok gelen bağlantılarla (inlink), merkezilik daha çok giden bağlantılarla (outlink) ilgilenir.

Üç prestij ölçüsü vardır.

### 17.1 Degree Prestige

Degree centrality'ye benzer. Bir düğüme gelen bağlantıların sayısı, kendisi dışındaki düğüm sayısına bölünür.

$$P_D(i)=\frac{d_I(i)}{n-1}$$

### 17.2 Proximity Prestige

Closeness centrality'ye benzer. Degree prestige yalnız düğüme doğrudan bağlantı verenlerin katkısını sayarken, proximity prestige doğrudan bağlantı vermemiş ama başka düğümler üzerinden bu düğüme ulaşabilen düğümleri de hesaba katar.

$I_i$, $i$ düğümüne bağlantıları izleyerek ulaşabilen düğümlerin kümesi olsun.

$$P_P(i)=\frac{|I_i|/(n-1)}{\sum_{j \in I_i} d(j,i)\,/\,|I_i|}$$

- **Pay:** Ulaşabilen düğümlerin tüm düğümler içindeki oranı.
- **Payda:** Ulaşabilen düğümlerin $i$'ye ortalama uzaklığı. Uzaklıklar toplanıp ulaşabilen düğüm sayısına bölünür.

Hesaplanması closeness'a benzer, tek fark yalnız ulaşabilen düğümlerin dikkate alınmasıdır.

> **Ek bilgi (derste anlatılmadı):** Yönlü bir çizgede her düğüm her düğüme ulaşamayabilir. Ulaşılamayan düğümün uzaklığı tanımlı olmadığı için closeness formülü doğrudan uygulanamaz. Proximity prestige bu yüzden yalnız ulaşabilen düğümlerle hesaplanır. Paydaki oran da az sayıda ama çok yakın düğümü olan bir düğümün haksız yere yüksek değer almasını önler.

### 17.3 Rank Prestige

Degree ve proximity prestige, bağlantı veren düğümlerin her bağlantısını $1$ puan sayar. Bir düğüme üç farklı düğüm bağlantı vermişse her biri eşit sayılır. Gerçek hayatta ise böyle değildir. Hocanın örneğiyle, bir genel müdürden alınan referans, birlikte çalıştığınız bir iş arkadaşından alınan referanstan daha değerlidir. Herkesin ağdaki önemi, verdiği bağlantıyla bir sonraki düğüme yansıyabilmelidir. Rank prestige bunu sağlar.

$i$ düğümünün rank prestige değeri hesaplanırken ona bağlantı verebilecek $1$'den $n$'e kadar bütün düğümlere bakılır:

$$P_R(i)=A_{1i}P_R(1)+A_{2i}P_R(2)+\dots+A_{ni}P_R(n)$$

$A_{ji}$ katsayıları $1$ ya da $0$'dır. 1. düğüm $i$'ye bağlantı vermişse $A_{1i}=1$ olur ve 1. düğümün rank prestige değeri kadar bir değer $i$'nin değerine eklenir. Vermemişse katsayı $0$'dır. Yani bağlantı veren düğümlerin rank prestige değerlerinin toplamı bir sonraki düğüme yansıtılır.

Formülün kısaltılmış biçimi şudur. Hoca burada bir an "PageRank değeri" dedi, sonra "rank prestige değeri" diye düzeltti.

$$P=A^T P$$

Yani bağlantı verenlerin rank prestige değerleri ile komşuluk matrisinin devriğinin (transpose) çarpımı, düğümlerin rank prestige değerlerini verir. Bu denkleme özdeğer sistemi (eigensystem) denklemi denir. Doğrusal cebirdeki kuvvet yinelemesi (power iteration) yöntemiyle çözülür.

> **Ek bilgi (derste anlatılmadı):** $P=A^T P$, $P$'nin $A^T$ matrisinin özdeğeri $1$ olan bir özvektörü olması anlamına gelir. Kuvvet yinelemesi, bir başlangıç vektörünü matrisle tekrar tekrar çarparak baskın özvektöre yaklaşma yöntemidir. Ayrıntısı önümüzdeki derste işlenecektir.

Üç ölçü şöyle özetlenebilir:

| Ölçü | Benzediği merkezilik ölçüsü | Temel fikir |
|---|---|---|
| Degree prestige | Degree centrality | Doğrudan gelen bağlantı sayısı |
| Proximity prestige | Closeness centrality | Bağlantıları izleyerek ulaşabilen düğümlerin katkısı |
| Rank prestige | Hoca benzetme yapmadı | Bağlantı veren düğümün önemi aktarılır |

PageRank algoritmasının temeli rank prestige ölçüsüne dayanır.

## 18. Bir Proje Önerisi Üzerine Görüşme

Ders sonunda bir öğrenci proje önerisini ekran paylaşımıyla gösterdi.

- **Konu:** Ürün yorumlarından görüş madenciliği (opinion mining). Önceki hâli yorumların olumlu ve olumsuz sınıflandırılmasıydı.
- **Amaç:** Yorumlardan özellikleri (feature) çıkarmak, hangi özelliklerin olumlu, hangilerinin olumsuz olduğunu bir arayüzde göstermek.
- **Veri:** Altyazıda "linkli" diye geçen kişinin hazırladığı 9, 3 ve 5 ürünlük veri kümeleri.
- **Yöntem:**
  - Sözcük türü etiketleme (altyazıda "post", büyük olasılıkla POS tagging) ile isimleri ayırmak.
  - İsimlerin önündeki ve arkasındaki sıfat veya zarflara bakarak Apriori algoritmasıyla özellikleri çıkarmak. Öğrencinin örneği "kulaklık çok iyi" gibi yorumlardır.
  - Yaklaşık 6800 kelimelik olumlu ve olumsuz kelime sözlüğüyle her özelliğin önüne gelen sıfatlardan olumlu ve olumsuz sayısını tutmak, frekansa göre şeklini çizdirmek.
- **Literatür:** Öğrenci, özellik çıkarımında makine öğrenmesi kullanan bir çalışma gördüğünü ama verisi çok büyük olduğu için tercih etmediğini söyledi. Baktığı diğer çalışmalarda Apriori ve TF-IDF kullanılmıştı.

**Hocanın geri bildirimi:** Hoca, ders kitabındaki yön odaklı görüş madenciliği (aspect-oriented opinion mining) kısmını hatırlattı. Anlatılan planı uygun buldu ve bu şekilde devam edilebileceğini söyledi.

> **Ders sonrası not:** Altyazıda sözlüğü ve veri kümesini hazırlayan kişi "linkli" ve "LinkedIn" diye geçer. Büyük olasılıkla ders kitabının yazarı Bing Liu kastedilir, sözlük de büyük olasılıkla Hu ve Liu'nun görüş sözlüğüdür.

## Dersin Toparlaması

Bu derste sosyal ağların ne işe yaradığı örneklerle görüldü, ardından ağlar komşuluk matrisi, kenar listesi ve komşuluk listesi olarak gösterildi. Ağları tanımlayan derece dizisi, derece dağılımı ve bileşenler ele alındı. Bir düğümün önemi önce merkezilik açısından degree, betweenness ve closeness ile, sonra popülerlik açısından degree prestige, proximity prestige ve rank prestige ile ölçüldü. Bütün ağ için de merkezileşme değeri tanımlandı. Temel mesaj, tek bir ölçünün yetmediği ve her ölçünün ağın farklı bir yönünü yakaladığıdır.

Bir sonraki derste rank prestige denklemini çözen kuvvet yinelemesi yöntemi ve bu ölçüye dayanan PageRank algoritması işlenecektir. Ayrıca iki düğüm arasındaki benzerliği ölçen ortak atıf (co-citation) ve bibliyografik eşleşme (bibliographic coupling) konuşulacaktır. Hoca, birbirine benzer makaleleri tespit eden sistemlerin (altyazıda "Authenticate" ve "Urkund") yalnız içerik benzerliğine değil, yayınların birbirine verdiği bağlantılara da baktığını, bunun için bu ölçüleri yaygın biçimde kullandığını söyledi.

> **Ders sonrası not:** "Authenticate" büyük olasılıkla iThenticate'tir. Hocanın bu araçların atıf analizi yaptığı yönündeki sözü altyazıdan doğrulanamıyor. Bu tür intihal denetim araçları büyük olasılıkla ağırlıklı olarak metin eşleştirmeye dayanır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
