# Ders 19 Genişletilmiş Notu: Graflar: Temel Kavramlar, Gösterimler, BFS, DFS ve Minimum Spanning Tree

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Graf Nedir?
- 2. Grafların Kullanım Alanları
- 3. Graf Terminolojisi
- 4. Graf Tipleri
- 5. Çevrimsiz Graf ve Ağaç
- 6. Graf Gösterimleri
- 7. Önce Genişlemesine Arama (BFS)
- 8. Önce Derinlemesine Arama (DFS)
- 9. Minimum Spanning Tree
- 10. Generic MST Algoritması
- 11. Kruskal Algoritması
- 12. Prim Algoritması
- 13. Ders Sonundaki Sorular
- Örnek Sorular

## 1. Graf Nedir?

Hoca yeni konuyu "başlı başına bir dünya" diye tanıttı: graflar hem matematiği hem bilgisayar bilimlerini hem mühendisliği içerir ve gündelik hayatta sık kullandığımız pek çok pratik çözümün arkasında durur. İngilizcesi *graph* olan kavramın öz Türkçesi *çizge*dir, ama derste "graf" kelimesi kullanıldı.

Tanım çok kısadır: **birbirine bağlı elemanlar kümesine graf denir.** Hoca, tanım ne kadar basitse arkasından gelen işin o kadar ağır olduğunu ekledi. Daha önceki haftalarda görülen ağaçlar da aslında grafın özel bir hâlidir; hangi koşullarda bir grafın ağaç olduğu ileride ayrıca incelendi.

Bir graf iki kümeyle ifade edilir: $G=(V,E)$.

- Bağlanan elemanlara **düğüm** denir. İngilizcesi *vertex* olduğu için $V$ harfiyle gösterilir.
- Elemanları birbirine bağlayan bağlara **kenar** denir. İngilizcesi *edge* olduğu için $E$ harfiyle gösterilir.
- Kümeyi iki dikey çizgi arasına almak ($|V|$, $|E|$) matematikteki gibi eleman sayısını gösterir.

Karmaşıklık analizinde şimdiye kadar hep eleman sayısı $n$ kullanılıyordu. Grafta ise iki tür eleman vardır: düğümler ve kenarlar, ve algoritmalar ikisi üzerinde de işlem yapar. Bu yüzden Big O gösteriminde $V$ ve $E$ kullanılır. Örneğin $O(VE)$, algoritmanın karmaşıklığının düğüm sayısı ile kenar sayısının çarpımı kadar olduğunu söyler.

## 2. Grafların Kullanım Alanları

Hoca grafı gündelik örneklerle somutlaştırdı:

- **Raylı sistem haritası:** Duraklar düğüm, raylar duraklar arasındaki kenarlardır. Farklı renkli hatlar (metro, tramvay, banliyö hattı) bazı duraklarda kesişir; kesişim durağı tek bir düğümdür. Bir duraktan başka bir durağa hangi aktarmalarla gidileceği bir graf modellemesiyle çözülebilir.
- **Sınır komşulukları:** Kitaplarda genellikle ABD eyaletleri örneği verilir; hangi eyaletin hangileriyle sınır komşusu olduğu bir graf oluşturur. Hiçbir eyaletle kara sınırı olmayan eyaletler grafta bağlantısız düğüm olarak kalır. Aynı graf iller için de çizilebilir; "bir ilden başka bir ile hangi illerden geçerek gidilir, alternatifler var mı, hangisi kısa ya da hızlı" gibi sorular bu grafla çözülür.
- **Biyoinformatik:** Protein-protein etkileşim ağlarında her protein bir düğüm, iki protein arasındaki etkileşim bir kenardır. Uçlarda ağaç benzeri tekil etkileşimler, ortada yoğun çoklu etkileşimler görülür. Bu tür analizler genetik ve ilaç çalışmalarında kullanılır.
- **Bilim alanları ağı:** Her konu başlığı bir düğümdür; bir makalede iki konu birlikte geçiyorsa aralarına kenar çizilir. Çok bağlantılı düğümler daha önemli ya da daha çok birlikte çalışılan alanlardır.
- **Sosyal ağlar:** Her kullanıcı bir düğümdür; arkadaşlık ya da takip bir kenardır. Bu bağlantılar dünya haritası üzerine çizildiğinde yoğun bölgeler parlak görünür. Kimin çok takipçisi olduğu, arkadaşın arkadaşı üzerinden kimlere erişilebileceği, bir kişinin ağdaki önemi gibi sorular graf analizleriyle cevaplanır.

Teknik uygulamalar da aynı modeli kullanır:

- **Haritalar ve en kısa yol:** İki kampüs arasında en az kilometreli yolu bulmak bir *shortest path* problemidir: kaynak ve hedef düğüm arasındaki yollar içinde en düşük maliyetlisini bulmak.
- **Akış:** Ağlarda önemli olan bant genişliğiyse ya da trafikte en hızlı yol aranıyorsa problem bir *max flow* problemine dönüştürülebilir.
- **Web ve arama motorları:** Sayfalar düğüm, bağlantılar (link) kenardır.
- **Baskı devre (PCB):** Bileşenlerin uçları düğüm, aralarındaki yollar kenardır; devrenin iki boyutlu düzlemde kesişmeden çizilip çizilemeyeceği ya da ek katman gerekip gerekmediği graf modellemesiyle incelenir.
- **Zaman planlaması:** PERT diyagramlarında her iş bir düğüm, işler arasındaki bağımlılıklar kenardır; işlerin en kısa ne kadar sürede biteceği analiz edilir.
- **Ticaret ve eşleştirme:** Alıcı-satıcı-ürün ağları, öğrencileri stajlarla ya da kulüplerle eşleştirme problemleri.
- **Bilgisayar ağları:** Paket yönlendirme (routing) ve çizelgeleme problemleri.
- **Yazılım:** Derleyicide modüller arası statik ya da dinamik çağrılar; her kaynak bir düğüm, her çağrı bir kenar.
- **Sosyal ağ analizi:** Anomali tespiti, kanaat önderi (influencer) bulma, bot ağı tespiti.

## 3. Graf Terminolojisi

Slayttaki şekil terimleri tek resimde gösteriyordu (ekrandan, 00:30:00):

- **Yol (path):** Kenarlarla bağlanmış olan düğümler silsilesi. Bir kaynak ile hedef arasında gidilebilen her güzergâh bir yoldur. Yolun uzunluğu geçilen kenar sayısıdır.
- **Çevrim (cycle):** İlk ve son düğümü aynı olan yol, yani kapalı bir yol. Şekildeki çevrimden 5 kenar geçildiği için uzunluğu 5'tir.
- **Bağlı (connected):** İki düğüm arasında bir yol varsa bu iki düğüm birbirine bağlıdır.

Hoca aynı şekilde bir düğümden diğerine 4 uzunlukta, 3 uzunlukta ve 7 uzunlukta farklı yollar çizdi. Normal bir grafta iki düğüm arasında birden fazla yol olabilir; bunlardan biri en kısa, biri en hızlı olabilir. Ağaçta ise verilen iki düğüm arasında tek bir yol vardır.

Şekilde birbirinden ayrı duran parçalar ayrı **bağlı bileşenlerdir** (connected component). Şekilde üç bileşen vardı. İki bileşen arasına bir kenar eklenirse ikisi tek bir bileşen olur ve bileşen sayısı 3'ten 2'ye düşer; bir kenar daha eklenirse 1'e iner ve tek bir graf elde edilir.

## 4. Graf Tipleri

Slayt dört tip sayıyordu: yönsüz graf, yönlü graf (digraph), kenar ağırlıklı yönsüz graf ve kenar ağırlıklı yönlü graf (ekrandan, 00:35:00). Slaytta ayrıca kendine dönen kenar (self-loop) ve iki düğüm arasında paralel kenarlar da gösteriliyordu.

### 4.1 Yönsüz Graf

Düğümler arasında yalnız bağlantı olması yeterlidir. Slayttaki örnekte 0 düğümü 1, 2, 5 ve 6'ya bağlıdır; 6 da 0'a bağlıdır. Bağlantının yönü yoktur. Hoca bunu arkadaşlıkla anlattı: Ali, Ayşe ile arkadaşsa Ayşe de Ali ile arkadaştır.

### 4.2 Yönlü Graf

Kenarın bir kaynağı ve bir hedefi varsa graf yönlüdür (*directed graph*, *digraph*). Hocanın örneği bir sosyal medya platformundaki takip ilişkisiydi: Ali, Ayşe'yi takip ediyorsa Ali'den Ayşe'ye bir ok çizilir. Ayşe de Ali'yi takip ederse ters yönde ayrı bir ok gerekir. Ayşe, Mehmet'i ve Fatma'yı takip ediyorsa Ayşe'den onlara oklar çizilir.

### 4.3 Kenar Ağırlıkları

Kenarlara ağırlık verilebilir. Hoca yönsüz örnekte kenarlara kilometre değerleri yazdı. 0'dan 5'e doğrudan giden kenarın ağırlığı 12 idi; başka bir güzergâhla ara toplamlar 5, 6, 8 olacak biçimde toplam 8 birimle gidilebiliyordu. Yani doğrudan kenar, kenar sayısı az olsa da yaklaşık %50 daha maliyetliydi.

<!-- BELİRSİZ: Hocanın elle çizdiği ağırlıkların hangi kenarlara yazıldığı karelerden okunamadı; yalnız doğrudan yolun 12, diğer güzergâhın toplam 8 olduğu altyazıdan kesindir. -->

Ağırlık uygulamaya göre kilometre, bant genişliği, saniyede aktarılan veri miktarı ya da beğeni sayısı olabilir. Yönlü grafta da ağırlık tanımlanabilir: "Ali, Ayşe'yi 5 kez beğendi; Ayşe, Ali'yi 1 kez beğendi" gibi.

Sonuçta tipin seçimi problemin doğasına bağlıdır, ama hepsi birbirine bağlı elemanlar kümesidir.

## 5. Çevrimsiz Graf ve Ağaç

**Çevrimsiz (acyclic) graf** kapalı döngü içermeyen graftır (ekrandan, 00:40:00). Slayttaki yönlü örnekte kenarlar A→B, B→C, B→E, B→D, C→E, D→E, G→D ve E→F idi. B'den çıkıp B'ye geri dönülemez; E'den F'ye gidilir ama geri dönülemez. Bu yüzden graf çevrimsizdir.

Ama bu, grafın ağaç olması için yeterli değildir. Slayttaki koşullar şunlardır:

- $V-1$ kenar var, döngü yok.
- $V-1$ kenar var, bileşenler bağlı.
- Herhangi bir kenarı kaldırmak ağacı keser (iki bileşene ayırır).
- Çevrimsizdir; bir kenar eklemek çevrim oluşturur.
- Slaytta "G'nin her kenar çiftini basit bir yol bağlar" yazıyordu; hoca bunu "iki tane vertex'i yalnız tek bir basit yol bağlar, iki nokta arasında birden fazla yol çizemezsiniz" diye açıkladı.

> **Ders sonrası not:** Slayttaki son maddede "kenar çifti" yazıyor; doğrusu "düğüm çifti"dir, hocanın sözlü açıklaması da bu yöndedir. Ayrıca hoca beş koşulun "aynı anda" doğru olması gerektiğini söyledi; standart kaynaklarda (büyük olasılıkla slaytın alındığı ders kitabında da) bu koşullar birbirine denktir, yani bağlı yönsüz bir graf için herhangi biri doğruysa diğerleri de doğrudur.

Örnek yönlü grafta 7 düğüm (A, B, C, D, E, F, G) ve 8 kenar vardır. $V-1=6$ kenar koşulu sağlanmadığı için bu graf ağaç değildir.

Slayttaki ikinci şekil ise bir ağaçtı: 19 düğüm, $V-1=18$ kenar, hiç çevrim yok, tek bir bağlı bileşen. Herhangi iki düğüm arasına kenar eklenince çevrim oluşur ve herhangi iki düğüm arasında yalnız bir yol vardır.

> **Hocanın vurgusu:** Her çevrimsiz graf ağaç değildir. Ağaç, çevrimsiz grafların özel bir hâlidir; bu ayrıma dikkat etmek gerekir.

## 6. Graf Gösterimleri

Grafları algoritmalarda kullanmak için iki temel yol vardır ve ikisi de daha önce görülen yapılara dayanır: bağlı listeler ve matrisler (ekrandan, 00:45:00).

### 6.1 Komşuluk Listesi ve Komşuluk Matrisi (Yönsüz Graf)

- **Komşuluk listesi (adjacency list):** Seyrek (sparse) graflar için uygundur. Kenarlar az ise, yani matris düşünülse çoğu hücresi sıfır olacaksa liste gösterimi daha doğrudur.
- **Komşuluk matrisi (adjacency matrix):** $V$ düğüm için $V^2$ yer kaplar; 5 düğümlü bir graf 25 hücre ister. $A_{ij}=1$ eğer $(i,j)\in E$, değilse 0'dır.

Slayttaki yönsüz grafın kenarları 1-2, 1-5, 2-3, 2-4, 2-5, 3-4 ve 4-5'tir. Komşuluk matrisi:

| | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| 1 | 0 | 1 | 0 | 0 | 1 |
| 2 | 1 | 0 | 1 | 1 | 1 |
| 3 | 0 | 1 | 0 | 1 | 0 |
| 4 | 0 | 1 | 1 | 0 | 1 |
| 5 | 1 | 1 | 0 | 1 | 0 |

Hoca satırları tek tek doldurdu: 1, 2'ye ve 5'e bağlıdır; 2 ise 1, 3, 4 ve 5'e bağlıdır, kendisine bağlı değildir. Kendine bağlı düğümler de olabilir.

Yer tasarrufu için iki fikir verildi. Birincisi, her hücre normal bir tamsayı yerine **1 bit** ile tutulabilir. İkincisi, yönsüz grafta matris simetriktir, yani $A^T=A$; köşegenin bir tarafını tutmak yeterlidir.

Aynı grafın komşuluk listesi: önce düğümler için bir dizi tanımlanır (statik dizi, dinamik dizi ya da bağlı liste olabilir). Her dizi gözü bir düğümdür ve komşuları bir bağlı listede tutulur:

```text
1 -> 2 -> 5 -> NULL
2 -> 1 -> 5 -> 3 -> 4 -> NULL
3 -> 2 -> 4 -> NULL
4 -> 2 -> 5 -> 3 -> NULL
5 -> 4 -> 1 -> 2 -> NULL
```

Komşuların sırası önemli değildir; örneğin 4'ün listesi 5, 2, 3 diye de yazılabilirdi.

### 6.2 Yönlü Grafın Gösterimi

> **Hocanın vurgusu:** Yönlü grafta $A^T \neq A$. Ali, Ayşe'yi takip ediyor diye Ayşe'nin Ali'yi takip etmesi gerekmez.

Slayttaki 6 düğümlü yönlü grafın kenarları 1→2, 1→4, 2→5, 3→5, 3→6, 4→2, 5→4 ve 6→6'dır (ekrandan, 00:50:00). Matris:

| | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| 1 | 0 | 1 | 0 | 1 | 0 | 0 |
| 2 | 0 | 0 | 0 | 0 | 1 | 0 |
| 3 | 0 | 0 | 0 | 0 | 1 | 1 |
| 4 | 0 | 1 | 0 | 0 | 0 | 0 |
| 5 | 0 | 0 | 0 | 1 | 0 | 0 |
| 6 | 0 | 0 | 0 | 0 | 0 | 1 |

$A[1][2]=1$ ama $A[2][1]=0$; matris simetrik değildir. Bu yüzden yarısını tutma iyileştirmesi yapılamaz ve $V^2$ yerin tamamı kullanılır.

Komşuluk listesi:

```text
1 -> 2 -> 4 -> NULL
2 -> 5 -> NULL
3 -> 6 -> 5 -> NULL
4 -> 2 -> NULL
5 -> 4 -> NULL
6 -> 6 -> NULL
```

6'nın komşusu kendisidir (kendine dönen kenar).

### 6.3 Ağırlıklı Graflar

Ağırlıklı graflarda matriste 1 yerine ağırlık değerleri yer alır. Hoca sosyal medya örneğine döndü: Ali, Ayşe'yi 5 kez beğendiyse ilgili hücreye 5, Mehmet'i 3 kez beğendiyse 3 yazılır.

Komşuluk listesinde ağırlık, liste düğümünün yapısına (struct) eklenen bir alanla tutulur. Örneğin 1'in listesindeki 2 düğümünde `weight = 5`, 4 düğümünde `weight = 3` olur. Yani her liste düğümüne komşu numarasının yanında bir tamsayı ağırlık alanı eklenir.

### 6.4 Bağlantı Sorgusu: Yer ve Zaman Takası

"4, 5'i takip ediyor mu?" gibi bir sorgu iki gösterimde farklı maliyetlidir:

- **Matris:** Doğrudan $A[4][5]$ hücresine bakılır. Değer 0 ise bağlantı yoktur. Maliyet $O(1)$'dir.
- **Liste:** Önce 4. göze gidilir, sonra 4'ün bütün komşuları NULL'a kadar gezilir. En kötü durumda düğümün derecesi kadar bakılır: $O(\text{degree}(v))$. Örneğin yönsüz grafta 2'nin listesinde 4 aranırken 1, 5, 3 geçilip ancak sonra 4 bulunur.

Matris yer karmaşıklığını artırır ama bağlantı ve kenar ağırlığı sorgusunu $O(1)$ yapar. Liste yer karmaşıklığını çok azaltır, ama sorgu zamanını derece mertebesinde tutar. İki gösterim arasındaki temel fark budur.

## 7. Önce Genişlemesine Arama (BFS)

Hoca BFS ve DFS'i normalde anlatmayı düşünmediğini, ama bilinmesi için hızlıca geçmek istediğini söyledi.

### 7.1 Fikir

*Breadth First Search* (önce genişlemesine arama) en basit arama yöntemlerinden biridir ve pek çok algoritmanın temelidir. Prim'in MST algoritması ve Dijkstra'nın en kısa yol algoritması BFS'e çok benzer bir mantık kullanır (ekrandan, 01:00:00).

- Girdi: yönlü ya da yönsüz bir $G(V,E)$ (komşuluk listesi ya da matrisiyle verilir) ve bir kaynak düğüm $s\in V$.
- $s$'den ulaşılabilen tüm düğümleri "keşfetmeye" çalışır.
- Sonuçta $s$ kökünden erişilebilen tüm yolları içeren bir *breadth-first tree* oluşur; bu ağaç $s$'den erişilebilen düğümlere giden en kısa yolları içerir.
- $k+1$ uzaklığa geçmeden önce $k$ uzaklıktaki tüm düğümler bulunur: önce kendi komşularım, sonra onların komşuları, sonra onların komşuları.

Hoca bunu suya atılan taşın yaptığı dalgaya benzetti: $s$'den bir dalga gönderilir; önce 1 uzaklıktakilere, sonra 2 uzaklıktakilere çarpar. Sorun, dalganın önünde kimin olduğunu takip etmektir. Bunun çözümü düz bir **FIFO kuyruktur**. Bir düğüm kuyruktayken dalga ona çarpmış ama onu henüz terk etmemiştir; o sıradakiler bitince bir sonraki katmana geçilir.

### 7.2 Algoritma

Slayttaki sözde kod (ekrandan, 01:10:00):

```text
BFS(V, E, s)
for each u ∈ V − {s}
    do d[u] ← ∞
d[s] ← 0
Q ← ∅
ENQUEUE(Q, s)
while Q != ∅
    do u ← DEQUEUE(Q)
       for each v ∈ Adj[u]
           do if d[v] = ∞
                then d[v] ← d[u] + 1
                     ENQUEUE(Q, v)
```

İlklendirmede bütün uzaklıklar sonsuz yapılır (uygulamada en büyük tamsayı); bu, "henüz hiçbir yere erişemiyorum" demektir. Kaynağın kendine uzaklığı 0'dır.

### 7.3 Adım Adım Örnek

Örnek yönlü grafın kenarları (ekrandan, 01:15:00): s→a, s→c, a→e, c→e, c→g, e→b, e→h, b→a, f→c, g→f, g→h, g→i, h→g, i→h. Düğümler s, a, b, c, e, f, g, h, i'dir (d yoktur).

- Başlangıç: $d[s]=0$, diğerleri $\infty$; $Q=\{s\}$.
- $s$ çekilir. Komşuları a ve c sonsuzdur: $d[a]=d[c]=0+1=1$; $Q=\{a,c\}$.
- $a$ çekilir. Tek komşusu e: $d[e]=1+1=2$; $Q=\{c,e\}$.
- $c$ çekilir. Komşu e'nin uzaklığı artık 2'dir, sonsuz değil; e daha önce ziyaret edildiği için atlanır ve kuyruğa yeniden eklenmez. Komşu g: $d[g]=2$; $Q=\{e,g\}$.
- $e$ çekilir. Komşular b ve h: $d[b]=d[h]=3$; $Q=\{g,b,h\}$.
- $g$ çekilir. Komşu f: $d[f]=3$. Komşu h zaten ziyaret edilmiştir, atlanır. Komşu i: $d[i]=3$; $Q=\{b,h,f,i\}$.
- Bundan sonra hiçbir komşu sonsuz değildir: b'nin komşusu a, h'nin komşusu g, f'nin komşusu c, i'nin komşusu h zaten ziyaret edilmiştir. Kuyruk boşalınca algoritma durur.

Sonuç uzaklık tablosu:

| | a | b | c | e | f | g | h | i | s |
|---|---|---|---|---|---|---|---|---|---|
| d | 1 | 3 | 1 | 2 | 3 | 2 | 3 | 3 | 0 |

Neden ziyaret edilmiş düğüm atlanır? Hocanın açıklamasıyla: bir düğüme daha önce gelinmişse, ona sonradan ulaşan yol büyük olasılıkla daha uzundur; bu örnekte şans eseri yine $1+1=2$ ile gelinirdi, ama $2+1=3$ ile de gelinebilirdi ve uzaklık yanlış artardı.

Uzaklıkların yanında her düğümün ebeveyni (parent) de tutulursa rota da çıkarılabilir. Hoca $s$'den $h$'ye gitmek için birkaç yol saydı ve BFS'te izlenen yolun s → a → e → h olduğunu hatırlattı; çünkü h, e üzerinden keşfedilmişti.

### 7.4 Karmaşıklık

Slayttaki analiz (ekrandan, 01:20:00):

- Enqueue ve dequeue $O(1)$'dir.
- Her düğüm en fazla bir kez kuyruğa girer (yalnız uzaklığı sonsuzken): toplam $O(V)$.
- Her düğüm en fazla bir kez kuyruktan çıkar ve o zaman kenarları denetlenir: toplam $O(E)$.
- Toplam $O(V+E)$, ilklendirme için de $+O(V)$.

BFS komşuluk listesi gösterimiyle lineer zamanda çalışır.

## 8. Önce Derinlemesine Arama (DFS)

### 8.1 Labirent ve İp Yumağı

Hoca DFS'in kökenini Trémaux keşfiyle (labirent keşfi) ilişkilendirdi ve Girit'teki Minotor ile labirent hikâyesini anlattı. Hikâyenin algoritmik özü şudur: Labirentten çıkmanın en kolay yolu girişe bir ip bağlayıp ilerlerken ipi açmaktır. Bir dönemeçte ip görülürse oranın daha önce gezildiği anlaşılır ve oraya gidilmez. Çıkmaz yola girilince ip geri sarılarak bir önceki dönemece dönülür ve henüz denenmemiş yol denenir.

Hoca bunu 6 düğümlü basit bir labirent üzerinde gösterdi: her dönemeçte önce en soldaki yol seçildi, ipin görüldüğü yere girilmedi, çıkmazda geri dönüldü ve sonunda çıkış bulundu. DFS tam olarak bu ip mantığıdır, ama daha az uğraşla yapılır.

### 8.2 Algoritma

Slayttaki ilke ve sözde kod (ekrandan, 01:30:00):

- Düğümleri özyinelemeli (rekürsif) olarak ziyaret et.
- Bir düğümü al, işaretle.
- Tüm işaretsiz komşularını özyinelemeli olarak ziyaret et.

```text
DepthFirstSearch(G, s)
    count = 0;
    for each vertex u ∈ G.V
        marked[u] = FALSE
    dfs(G, s)

dfs(G, v)
    marked[v] = TRUE
    count++
    for each w ∈ G.adj[v]
        if (!marked[w])
            dfs(G, w)
```

`marked[]` dizisi düğüm sayısı kadardır ve labirentteki ipin görevini görür: "Buradan daha önce geçtim mi?" DFS çalışırken komşuluk listesi gösterimi kolaylık sağlar.

### 8.3 Adım Adım Örnek

Yönsüz grafın komşuluk listesi (ekrandan, 01:35:00):

```text
0: 2 1 5
1: 0 2
2: 0 1 3 4
3: 5 4 2
4: 3 2
5: 3 0
```

DFS 0'dan başlar:

- `dfs(0)`: 0 işaretlenir. İlk komşu 2 işaretsiz, `dfs(2)` çağrılır.
- `dfs(2)`: 2 işaretlenir. İlk komşu 0 işaretli, geçilir. Sıradaki komşu 1 işaretsiz, `dfs(1)`.
- `dfs(1)`: 1 işaretlenir. Komşuları 0 ve 2 işaretli; 1 biter, 2'ye dönülür.
- 2'nin sıradaki komşusu 3 işaretsiz, `dfs(3)`.
- `dfs(3)`: 3 işaretlenir. İlk komşu 5 işaretsiz, `dfs(5)`.
- `dfs(5)`: 5 işaretlenir. Komşuları 3 ve 0 işaretli; 5 biter, 3'e dönülür.
- 3'ün sıradaki komşusu 4 işaretsiz, `dfs(4)`.
- `dfs(4)`: 4 işaretlenir. Komşuları 3 ve 2 işaretli; 4 biter.
- 3'ün son komşusu 2 işaretli; 3 biter. 2'nin son komşusu 4 işaretli; 2 biter.
- 0'ın kalan komşuları 1 ve 5 işaretli; 0 biter. Gezinti tamamlanır.

Ziyaret sırası 0, 2, 1, 3, 5, 4'tür. Slayttaki özyinelemeli çağrı ağacı da aynı sırayı gösteriyordu: `dfs(0)` → `dfs(2)` → (`check 0`) → `dfs(1)` → `dfs(3)` → `dfs(5)` → `dfs(4)` ve geri dönüşler.

Hem BFS'te hem DFS'te, özellikle yönlü graflarda, başlangıç noktasına bağlı olarak erişilemeyen düğümler kalabilir.

### 8.4 DFS ile Neler Çözülür?

Slayttaki sorular (ekrandan, 01:40:00):

- Tek kaynaktan nerelere gidebiliriz?
- Verilen iki düğüm birbirine bağlı mıdır? Bu, iki düğüm arasında yol var mıdır sorusuyla aynıdır.

Bunun için `marked[]` dizisine ek olarak `edgeTo[]` dizisi tutulur: her düğüme hangi düğümden gelindiği.

```text
DepthFirstPaths(G, s)
    for each vertex u € G.V
        marked[u] = FALSE
        edgeTo[u] = 0;
    dfs(G, s)

dfs(G, v)
    marked[v] = TRUE
    for each w € G.adj[v]
        if (! marked[w])
            edgeTo[w] = v
            dfs(G, w)

pathTo(v)
    // path is a stack
    if (! marked[v]) return NULL
    for (x = v; x != s; x = edgeTo[x])
        path.push(x)
    path.push(s)
    return path
```

Örnekteki `edgeTo[]` değerleri: 1←2, 2←0, 3←2, 4←3, 5←3. Bunlar bir ağaç oluşturur: kök 0, 0'ın çocuğu 2, 2'nin çocukları 1 ve 3, 3'ün çocukları 4 ve 5. Bu ağaçla "0'dan 4'e gidebilir miyim?" sorusu 0 → 2 → 3 → 4 diye, "0'dan 5'e?" sorusu 0 → 2 → 3 → 5 diye cevaplanır.

`pathTo(5)` hesabı tersten yapılır:

| x | path (yığıt) |
|---|---|
| 5 | 5 |
| 3 | 3 5 |
| 2 | 2 3 5 |
| 0 | 0 2 3 5 |

5'e 3'ten, 3'e 2'den, 2'ye 0'dan gelinmiştir. Yığıttan çekilince yol 0-2-3-5 olarak yazdırılır.

## 9. Minimum Spanning Tree

### 9.1 Muhtar Örneği

Hoca dersin asıl konusu olarak *minimum spanning tree*'yi (minimum yayılımlı ağaç, asgari örten ağaç, asgari tarama ağacı) tanıttı (ekrandan, 01:45:00):

- Bir köyün muhtarısınız.
- Sorumluluğunuz gereği köydeki tüm evleri birbirine bağlamanız gerekir.
  - Bir yol parçası $w$ ile iki ev $(u,v)$ bağlanabilir.
  - Bu yol parçasının yapım ya da tamir masrafı $w(u,v)$'dir (örneğin dökülecek asfalt miktarı).
- Hedef: herkesi birbirine bağlı tutacak (bir evden diğer tüm evlere ulaşılabilecek) ve bunu minimum masrafla yapacak yol ağını oluşturmak.

Hoca 4 evli bir örnek çizdi; her ev diğerlerine bağlanabiliyordu ve yol maliyetleri 8, 18, 2, 50, 1 ve 5 birimdi. Muhtar 50, 18 ve 8'lik yolları yapmadan yalnız 1, 2 ve 5 birimlik yolları yaparak toplam 8 birimle dört evi birbirine bağladı. Her ev bu üç yol üzerinden diğer üç eve ulaşabilir. Ortaya çıkan yapı bir ağaçtır; kök hangi ev seçilirse seçilsin fark etmez.

<!-- BELİRSİZ: Elle çizilen 4 evli örnekte hangi maliyetin hangi ev çiftine ait olduğu karede tam okunamadı; seçilen yolların 1, 2 ve 5 birim olduğu ve toplamın 8 olduğu altyazıdan kesindir. -->

### 9.2 Formal Tanım

Slayttaki tanım (ekrandan, 01:50:00):

- Köyü yönsüz bir graf olarak modelleyin: $G=(V,E)$.
- Her $(u,v)\in E$ kenarı için bir ağırlık $w(u,v)$ atayın.
- Öyle bir $T \subseteq E$ bulun ki:
  - $T$ tüm düğümleri birbirine bağlasın (tarasın, örtsün),
  - $w(T)=\sum_{(u,v)\in T} w(u,v)$ değeri asgaride kalsın.
- Tüm örten ağaçlar içinde ağırlıkları toplamı en az olan ağaca *minimum spanning tree* denir.

Aynı grafta aynı toplam ağırlığa sahip birden fazla MST bulunabilir. Slayttaki grafta iki tane 3 ağırlıklı kenar vardı (c-e ve e-f); e düğümüne f'den değil c'den bağlanılsaydı yine bir MST elde edilirdi. Ağaç farklı olur ama toplam maliyet aynı kalır.

### 9.3 Ağaç Koşulları ve Güvenli Kenar

MST bir ağaç olduğu için $V-1$ kenarı olmalı ve çevrim oluşturmamalıdır. Hoca burayı özellikle vurguladı: çevrim oluştuğu anda gereksiz bir asfalt dökülmüş, gereksiz bir bağlantı yapılmış olur.

Yöntem şöyledir: boş bir kenar kümesiyle başlanır ve her adımda bir kenar seçilip kümeye eklenir. Küçük değerli bir kenar seçilir, ama bu kenar çevrim oluşturuyor ya da $V-1$ koşulunu bozuyorsa **güvenli değildir**. Yalnız güvenli (*safe*) kenarlar seçilir. $V-1$ güvenli kenar seçildiğinde $V$ düğümü bağlayan, çevrim içermeyen ve toplam ağırlığı en küçük olan ağaç elde edilir.

Her adımda o anki en uygun, en düşük maliyetli seçimi yapan ve ilerisini ya da toplamı düşünmeyen yöntemlere **açgözlü (greedy)** yöntemler denir. Burada her adımda güvenli kenarlar içinden en hafifi seçilir; güvenli olmak ön şarttır.

## 10. Generic MST Algoritması

Slayttaki sözde kod (ekrandan, 02:05:00):

```text
GENERIC-MST(G, w)
1  A = ∅;
2  while A does not form a spanning tree
3      find an edge (u,v) that is safe for A
4      A = A U {(u,v)}
5  return A
```

Güvenli kenar nasıl bulunur? Slayttaki açıklama:

- (c,f) kenarı en düşük maliyetli olandır. A için güvenli mi?
- O ana kadar oluşan ağaçta $c\in S$ olsun ama f düğümü olmasın ($f\in V-S$).
- Herhangi bir MST'de f de en az bir kenarla ağaca bağlanmalıdır. Neden en ucuz olanı seçmeyelim ki? (Greedy seçim stratejisi)

Slayttaki grafın kenarları: a-b 10, a-c 12, b-c 9, b-d 8, c-e 3, c-f 1, e-f 3, d-e 7, d-g 8, d-h 5, f-h 6, g-h 9, g-i 2, h-i 11. Hoca seçimi şöyle anlattı: önce 1 (c-f), sonra 2 (g-i), sonra 3'lerden biri (hangisi olduğu fark etmez), ama ikinci 3 seçilemez çünkü c-e-f kapalı çevrim oluşur; ardından 5 (d-h) ve böyle devam edilir.

### 10.1 Kesim ve Hafifleten Kenar

Slayttaki açıklama (ekrandan, 02:10:00):

- $S$ ve $V-S$ ayrık kısımlarına kesim (*cut*) diyelim.
- $(S, V-S)$ kesimleri arasında $(u,v)\in E$ kenarları olabilir.
- Bu kesimler arasında bağlantıyı hafifleten bir kenar bizim için güvenlidir.
- Örnekte $(u,v)$ kenarının değeri $(x,y)$ kenarının değerinden küçük olsun. $(x,y)$'yi kaldırıp $(u,v)$'yi ekleriz; spanning tree yapısını bozmamış oluruz.

Hoca şekle kesim kenarları için 7, 8, 9 ve 5 değerlerini yazdı. İki bileşen $x$-$y$ kenarıyla (7) bağlıysa, onun yerine $u$-$v$ kenarı (5) kullanılarak toplam maliyet 2 birim azaltılır ve ağaç yapısı bozulmaz.

Başlangıç boş bir küme olduğu için yapı bir orman gibi düşünülebilir: başta her bileşen tek bir düğümdür; bileşenler güvenli kenarlarla birleştirilerek $V-1$ kenar eklenince tek bir ağaç elde edilir. Kenarlar üzerinden bu biçimde ilerlemek Kruskal'ın yöntemine çok yakındır.

## 11. Kruskal Algoritması

### 11.1 Fikir

Kruskal da açgözlü bir yöntemdir:

- Her düğüm başta tek başına bir bileşendir.
- Tekrarlı olarak iki bileşeni birbirine bağlayan hafif bir kenar bulunur.
- Bunun için kenarlar ağırlıklarına göre artan sırada taranır: önce en hafif kenar.
- Bir kenarın farklı bileşenlerdeki düğümleri bağlayıp bağlamadığını anlamak için düğümler **ayrık kümeler** (disjoint set) veri yapısında tutulur. Kenarın iki ucu aynı kümedeyse kenar çevrim oluşturur.

Hocanın anlattığı sözde kodun adımları: ağaç kümesi A boş küme olarak başlar; her düğüm için bir küme oluşturulur ($V$ işlem, $O(V)$); kenarlar ağırlığa göre küçükten büyüğe sıralanır ($O(E \log E)$; hoca, şimdiye kadarki en iyi sıralamanın heap sort ile elde edilen $n \log n$ olduğunu hatırlattı); sonra sıralı kenarlar üzerinde dönülür, iki ucun kümesi bulunur (find set) ve farklıysa kenar ağaca eklenip kümeler birleştirilir (union).

<!-- BELİRSİZ: Kruskal sözde kodunun slayttaki birebir metni karelerde yakalanmadı; adımlar hocanın anlatımından yazıldı. -->

### 11.2 Adım Adım Örnek

Örnek grafın kenarları (ekrandan, 02:15:00): a-b 4, a-h 8, b-c 8, b-h 11, c-d 7, c-f 4, c-i 2, d-e 9, d-f 14, e-f 10, f-g 2, g-h 1, g-i 6, h-i 7. Düğümler a, b, c, d, e, f, g, h, i'dir; 9 düğüm olduğu için MST'de 8 kenar olacaktır.

Hoca kenarları slaytta sıraladı; eşit ağırlıklarda alfabede önce geleni öne yazdı (ekrandan, 02:25:00):

```text
h-g:1, c-i:2, f-g:2, a-b:4, c-f:4, i-g:6, c-d:7,
h-i:7, a-h:8, b-c:8, d-e:9, e-f:10, b-h:11, d-f:14
```

| Adım | Kenar | Ağırlık | Karar | Bileşenler (ekledikten sonra) |
|---|---|---|---|---|
| 1 | h-g | 1 | Al | {h,g} |
| 2 | c-i | 2 | Al | {h,g}, {c,i} |
| 3 | f-g | 2 | Al | {h,g,f}, {c,i} |
| 4 | a-b | 4 | Al | {h,g,f}, {c,i}, {a,b} |
| 5 | c-f | 4 | Al | {h,g,f,c,i}, {a,b} |
| 6 | i-g | 6 | Atla (çevrim) | |
| 7 | c-d | 7 | Al | {h,g,f,c,i,d}, {a,b} |
| 8 | h-i | 7 | Atla (çevrim) | |
| 9 | a-h | 8 | Al | {a,b,h,g,f,c,i,d} |
| 10 | b-c | 8 | Atla (çevrim) | |
| 11 | d-e | 9 | Al | tümü |
| 12 | e-f | 10 | Atla (çevrim) | |
| 13 | b-h | 11 | Atla (çevrim) | |
| 14 | d-f | 14 | Atla (çevrim) | |

Dördüncü adımdan sonra üç ayrı ağaç vardır; hoca bunu "üç ağaçlık bir orman" diye adlandırdı. c-f kenarı iki bileşeni birleştirerek 5 düğümü en küçük bağlantılarla bağladı.

d-e eklendiğinde 8 kenar seçilmiş olur ve ağaç aslında tamamlanmıştır. Ama Kruskal sıralı listedeki bütün kenarları taradığı için kalan e-f, b-h ve d-f de denetlenir; hepsi çevrim oluşturduğundan atlanır. Seçilen kenarların toplam ağırlığı $1+2+2+4+4+7+8+9=37$'dir.

Hoca alternatif ağacı da gösterdi: 9. adımda a-h yerine b-c (8) seçilseydi o da çevrim oluşturmazdı ve başka bir MST elde edilirdi; o durumda a-h alınamazdı. Sıralamada a-h önce geldiği için a-h seçildi. Ayrıca 2 ağırlıklı c-i ile f-g'den hangisinin önce alınacağı da sonucu değiştirmez.

### 11.3 Karmaşıklık

Hoca ayrıntıya girmeden şunları söyledi: ilklendirmede $V$ kez make set yapılır ($O(V)$); kenarlar $O(E \log E)$ ile sıralanır; ikinci döngüde $E$ kenar üzerinde find set ve union işlemleri yapılır. Toplamda Kruskal'ın karmaşıklığı $O(E \log V)$'dir. Kenarlar sıralı verilirse karmaşıklık neredeyse lineer bir mertebeye iner.

> **Ders sonrası not:** Hoca sıralı kenarlar için ulaşılan mertebeyi altyazıda "E AV" gibi geçen bir ifadeyle söyledi. Ders kitabındaki karşılığı büyük olasılıkla $O(E\,\alpha(V))$'dir; $\alpha$, pratikte çok küçük kalan ters Ackermann fonksiyonudur.

Düğüm çok, kenar az ise $O(E \log V)$ iyidir. Ama sosyal ağlardaki gibi kenar sayısı çok fazlaysa bu mertebe zorlayıcı olabilir.

## 12. Prim Algoritması

### 12.1 Fikir

Kruskal kenar kenar ilerler ve ara adımlarda birbirinden bağımsız birden fazla bileşen olabilir. Prim olaya ters yönden yaklaşır (ekrandan, 02:30:00):

- Tek bir ağaç oluşturur; A her zaman bir ağaçtır.
- Keyfi bir $r$ kökü ile başlar.
- Her adımda $(V_A, V-V_A)$ kesimleri arasında bir hafif kenar bularak ağaca ekler.
- Hafif kenar öncelikli kuyruk ile bulunur:
  - Kuyruktaki elemanlar $V-V_A$ kümesindeki düğümlerdir.
  - Elemanların anahtarları ağırlık değerleridir.
  - EXTRACT_MIN ile $(V_A, V-V_A)$ arasındaki hafif kenar geçişi bulunur.
  - Bir düğüm $V_A$'daki düğümlerle komşu değilse ağırlığı sonsuzdur.
- A'nın kenarları $r$ köküne sahip bir ağaç oluşturur:
  - $r$ başlangıcı verilir ama esasen herhangi bir düğüm olabilir.
  - Her düğüm ağaçtaki ebeveynini ($p[v]$) bilir.
  - Algoritma ilerledikçe $V_A$ büyür; $V$ boş küme olduğunda (tüm düğümlere erişildiğinde) sonlanır.

Hoca, ağacı büyüterek ilerlendiği için kenarları Kruskal'daki gibi baştan sıralamanın mümkün olmadığını, kalanlar içinde her seferinde en hafifini bulmak gerektiğini söyledi. Bunun için iki hafta önce görülen öncelikli kuyruğa (priority queue) ve onun yığın (heap) yapısına dönülür: EXTRACT-MIN en hafif geçişi verir, kalanlar içinde bir sonraki aday yığının tepesine gelir.

Hocanın anlattığı sözde kodun adımları: kuyruk ilklendirilir; her düğümün anahtarı sonsuz, ebeveyni ($\pi$) NULL yapılır ve kuyruğa eklenir; seçilen $r$ kökünün anahtarı 0 yapılır, böylece ilk o çekilir; kuyruk boşalana kadar EXTRACT-MIN yapılır ve çekilen düğümün komşularının anahtarları kenar ağırlıklarıyla güncellenir.

<!-- BELİRSİZ: Prim sözde kodunun slayttaki birebir metni karelerde yakalanmadı; adımlar hocanın anlatımından yazıldı. -->

### 12.2 Adım Adım Örnek

Kruskal'daki grafın aynısı kullanıldı ve $a$ kökünden başlandı (ekrandan, 02:40:00). Hoca yığını slayta çizmek zor olduğu için kuyruğu sıralı bir liste gibi yazdı; gerçekte yığın olduğunu hatırlattı.

- $a$ çekilir. Komşuları kuyruğa: b-4, h-8. Kuyruk: b4, h8.
- EXTRACT-MIN → b (4). a-b eklenir. b'nin komşuları: c-8, h-11. Kuyruk: c8, h8, h11.
- EXTRACT-MIN → c (8, b'den). b-c eklenir. c'nin komşuları: i-2, f-4, d-7. Kuyruk: i2, f4, d7, h8, h11.
- EXTRACT-MIN → i (2, c'den). c-i eklenir. Ağaçtaki 4 düğümün toplam maliyeti $4+8+2=14$'tür. i'nin komşuları: g-6, h-7. Kuyruk: f4, g6, d7, h7, h8, h11.
- EXTRACT-MIN → f (4, c'den). c-f eklenir. f'nin komşuları: g-2, e-10, d-14.
- EXTRACT-MIN → g (2, f'den). f-g eklenir. g'nin komşuları: i-6 (i zaten ağaçta, güvenli değil, atılır), h-1.
- EXTRACT-MIN → h (1, g'den). g-h eklenir. h'nin komşuları a, b, i zaten ağaçtadır. Kuyrukta kalan h-8, h-11, h-7, g-6 gibi kayıtlar artık işe yaramaz ve atılabilir.
- Kalan: d7, e10, d14. EXTRACT-MIN → d (7, c'den). c-d eklenir. d'nin komşuları: e-9; f-14 (f zaten ağaçta, eklenmez).
- E için önce 10 vardı, şimdi 9 geldi. EXTRACT-MIN → e (9, d'den). d-e eklenir. Kalan kayıtlar zaten ağaçtaki düğümlere aittir; kuyruk boşalır.

Hoca, ağaca daha önce eklenmiş düğümlerin kuyruğa yeniden eklenmesine gerek olmadığını, eklenmişse de çekildiğinde kontrol edilip atılabileceğini söyledi.

Sonuç ağaç, $a$ kökünden:

```text
a
└── b (4)
    └── c (8)
        ├── i (2)
        ├── f (4)
        │   └── g (2)
        │       └── h (1)
        └── d (7)
            └── e (9)
```

Toplam ağırlık: $4+8+2+4+7+9+2+1=37$. Prim ve Kruskal aynı toplam ağırlığı buldu; ama Kruskal a-h'yi, Prim b-c'yi seçtiği için ağaçlar farklıdır.

### 12.3 MST En Kısa Yol Değildir

Hoca son bir uyarı yaptı. MST'de i ile g arasındaki yol i → c → f → g'dir ve maliyeti $2+4+2=8$'dir. Oysa i ile g doğrudan 6 birimlik bir kenarla bağlanabilir. Yani tek bir düğüm çifti için MST'deki yol en kısa yol olmayabilir. MST'nin amacı iki düğüm arasındaki en kısa yolu bulmak değil, bütün düğümleri en az sayıda yolla ($V-1$ kenar) ve toplam en küçük maliyetle bağlamaktır.

> **Hocanın vurgusu:** Tekil iki düğüm arasında daha kısa yol (shortest path) bulunabilir; MST'nin derdi bütün düğümleri toplam minimum maliyetle bir ağaçla bağlamaktır.

### 12.4 Karmaşıklık

Slayttaki analiz, öncelikli kuyruk ikili yığınla (binary heap) yapılmışsa (ekrandan, 02:50:00):

- Init Q ve ilk for döngüsü: $O(V \lg V)$.
- R anahtar değerinin azaltılması: $O(\lg V)$.
- While döngüsü:
  - $|V|$ Extract_min çağrısı → $O(V \lg V)$.
  - $\le |E|$ Decrease_key çağrısı → $O(E \lg V)$.
- Toplam: $O(E \lg V)$.
- Eğer Fibonacci yığını kullanılarak Decrease_key $O(1)$'de yapılırsa: $O(V \lg V + E)$.

Hoca Fibonacci yığınının ayrıntısına girmedi. Vurguladığı nokta şuydu: kenar bağlantıları çok olabileceği için karmaşıklık ifadelerinde $E$ çarpanından mümkün olduğunca kaçınılmaya çalışılır.

## 13. Ders Sonundaki Sorular

**Soru:** Big O gösteriminde $+E$ nasıl geliyor?

**Cevap:** Hoca, ifadede $+E$ terimi bulunduğunu ama mertebenin $V \log V$'de kaldığını bilmenin şimdilik yeterli olduğunu söyledi; bu terime takılmamak gerektiğini ekledi.

**Soru:** Bir algoritmanın bazı kısımlarında bir döngünün karmaşıklığı daha yüksek, bazılarında daha düşükse ve parametreler farklıysa ($V$ ve $E$), düşük terim yine silinir mi?

**Cevap:** Hoca, dersin bir algoritma analizi dersi olmadığı için notasyonun ayrıntısına girmek istemediğini söyledi. Şu anda önemli olan en ağır mertebedir; $+E$ terimi vardır ama mertebenin $V \log V$ olduğunu bilmek yeterlidir.

> **Ek bilgi (derste anlatılmadı):** $V$ ve $E$ bağımsız parametreler olduğu için $O(V \log V + E)$ ifadesindeki $+E$ genel olarak atılamaz; yoğun graflarda $E$ en fazla $V^2$ mertebesine çıkar ve $V \log V$'den büyük olabilir. Bu yüzden ders kitapları bu terimi korur.

**Soru:** Prim algoritmasında grafa yeni bir düğüm eklenirse ağacı baştan oluşturmak gerekir mi?

**Cevap:** Evet. Hoca örnek verdi: grafa e ve a'ya bağlı yeni bir z düğümü eklensin ve a-z kenarının ağırlığı 2 olsun. a'nın komşuları kuyruğa eklenirken b-4 ve h-8'in yanına z-2 de gelir ve en başta z seçilir. Böylece bambaşka bir MST çıkabilir. Kruskal'da da aynı durum geçerlidir: yeni kenarlar sıralı listede farklı yerlere girer. Graf değişince MST de değişebileceği için baştan oluşturulmalıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Kenarları A→B, B→C, B→E, B→D, C→E, D→E, G→D, E→F olan yönlü graf çevrimsiz midir? Bir ağaç mıdır?

> **Çözüm:** Hiçbir düğümden çıkıp aynı düğüme dönülemediği için graf çevrimsizdir. Ancak 7 düğüm (A-G) ve 8 kenar vardır; ağaç için $V-1=6$ kenar gerekir. Koşul bozulduğu için graf ağaç değildir.

**Soru 2** (derste sözlü, 00:52:02): Slayttaki 6 düğümlü yönlü grafta 4, 5'i takip ediyor mu? Komşuluk matrisi ve komşuluk listesiyle bu sorgu nasıl yapılır?

> **Çözüm:** Matriste $A[4][5]=0$ olduğu için bağlantı yoktur; sorgu $O(1)$'dir. Listede 4'ün komşuları NULL'a kadar gezilir (yalnız 2 vardır) ve 5 bulunamaz; sorgu $O(\text{degree}(4))$'tür.

**Soru 3** (ekrandan, 01:15:00): Kenarları s→a, s→c, a→e, c→e, c→g, e→b, e→h, b→a, f→c, g→f, g→h, g→i, h→g, i→h olan yönlü grafta $s$ kaynağından BFS uygulayınız. Her düğümün uzaklığını bulunuz.

> **Çözüm:** Kuyruktan çıkış sırası s, a, c, e, g, b, h, f, i'dir. Uzaklıklar: $d[s]=0$, $d[a]=d[c]=1$, $d[e]=d[g]=2$, $d[b]=d[h]=d[f]=d[i]=3$. (Python ile doğrulandı.)

**Soru 4** (ekrandan, 01:35:00): Komşuluk listesi 0: 2 1 5; 1: 0 2; 2: 0 1 3 4; 3: 5 4 2; 4: 3 2; 5: 3 0 olan grafta 0'dan DFS uygulayınız. Ziyaret sırasını ve `edgeTo[]` dizisini bulunuz.

> **Çözüm:** Ziyaret sırası 0, 2, 1, 3, 5, 4'tür. `edgeTo`: 1←2, 2←0, 3←2, 4←3, 5←3. (Python ile doğrulandı.)

**Soru 5** (ekrandan, 01:40:00): Aynı DFS sonucunda `pathTo(5)` hangi yolu verir?

> **Çözüm:** $x=5$ → yığıt 5; $x=3$ → 3 5; $x=2$ → 2 3 5; sonra kaynak itilir → 0 2 3 5. Yol 0-2-3-5'tir.

**Soru 6** (ekrandan, 02:05:00): Kenarları a-b 10, a-c 12, b-c 9, b-d 8, c-e 3, c-f 1, e-f 3, d-e 7, d-g 8, d-h 5, f-h 6, g-h 9, g-i 2, h-i 11 olan graf için bir minimum spanning tree bulunuz. Hangi kenar ilk seçilir, hangi kenar çevrim oluşturduğu için seçilemez?

> **Çözüm (derste verilmedi):** Hoca yalnız ilk adımları anlattı: önce c-f (1), sonra g-i (2), sonra 3'lerden biri; ikinci 3 c-e-f çevrimi oluşturacağı için seçilemez; sonra d-h (5). Kruskal ile tamamlanınca seçilen kenarlar c-f 1, g-i 2, c-e 3 (ya da e-f 3), d-h 5, f-h 6, b-d 8, d-g 8, a-b 10'dur ve toplam ağırlık 43'tür. Bu sonuç slaytta kalın çizilen ağaçla (e'nin bağlandığı 3'lük kenar dışında) uyumludur. (Python ile doğrulandı.)

**Soru 7** (ekrandan, 02:15:00): Kenarları a-b 4, a-h 8, b-c 8, b-h 11, c-d 7, c-f 4, c-i 2, d-e 9, d-f 14, e-f 10, f-g 2, g-h 1, g-i 6, h-i 7 olan grafta Kruskal algoritmasıyla MST bulunuz.

> **Çözüm:** Seçilen kenarlar sırasıyla h-g 1, c-i 2, f-g 2, a-b 4, c-f 4, c-d 7, a-h 8, d-e 9'dur. i-g, h-i, b-c, e-f, b-h ve d-f çevrim oluşturduğu için atlanır. Toplam ağırlık 37'dir. (Python ile doğrulandı.)

**Soru 8** (ekrandan, 02:40:00): Aynı grafta $a$ kökünden başlayarak Prim algoritmasıyla MST bulunuz.

> **Çözüm:** Ağaca eklenen kenarlar sırasıyla a-b 4, b-c 8, c-i 2, c-f 4, f-g 2, g-h 1, c-d 7, d-e 9'dur. Toplam ağırlık $4+8+2+4+7+9+2+1=37$'dir. (Python ile doğrulandı.)

**Soru 9** (derste sözlü, 02:54:02): Grafa yeni bir düğüm eklenirse MST yeniden mi oluşturulmalıdır?

> **Çözüm:** Evet. Hocanın örneğinde a ile 2 ağırlıklı bir kenarla bağlanan yeni z düğümü, Prim'de a'dan sonra hemen seçilir ve farklı bir MST ortaya çıkabilir. Kruskal'da da yeni kenarlar sıralamayı değiştirir. Graf değişince MST baştan hesaplanmalıdır.

## Dersin Toparlaması

Bu derste graf veri yapısı tanıtıldı: $G=(V,E)$ tanımı, gündelik ve teknik kullanım alanları, yol, çevrim, bağlılık ve bağlı bileşen kavramları, yönlü/yönsüz ve ağırlıklı/ağırlıksız graf tipleri, çevrimsiz graflar ve ağacın bunların özel bir hâli olduğu. Grafların komşuluk listesi ve komşuluk matrisiyle nasıl gösterileceği, iki gösterimin yer ve zaman açısından nasıl karşılaştırılacağı örneklerle gösterildi.

Ek bilgi olarak iki temel gezinti yöntemi işlendi: kuyruk kullanarak katman katman ilerleyen BFS ve labirentteki ip yumağı mantığıyla özyinelemeli ilerleyen DFS. Dersin asıl konusu minimum spanning tree oldu: önce açgözlü generic MST fikri ve güvenli kenar kavramı, sonra kenarları sıralayıp ayrık kümelerle bileşenleri birleştiren Kruskal algoritması ve tek bir kökten başlayıp öncelikli kuyrukla ağacı büyüten Prim algoritması aynı grafta adım adım uygulandı. İki algoritma da toplam ağırlığı 37 olan, ama farklı birer MST buldu. Hoca derste Dijkstra'nın en kısa yol algoritmasının bu dönem işlenmeyeceğini, ama BFS mantığına çok benzediğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
