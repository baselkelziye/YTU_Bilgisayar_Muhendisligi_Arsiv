# Ders 11 Genişletilmiş Notu: Genişlik Öncelikli Arama, Dal ve Sınır Yöntemi, Dönüştür ve Fethet

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Açgözlü teknik, optimal çözüm ve dinamik programlama üzerine düzeltmeler
- 2. Genişlik öncelikli arama (BFS)
- 3. DFS ile BFS karşılaştırması
- 4. Optimizasyon problemleri ve dal ve sınır yöntemi
- 5. Atama problemi
- 6. 0-1 sırt çantası problemi
- 7. Optimizasyon tekniklerinin önemi
- 8. Dönüştür ve fethet
- 9. Alt sınır kavramına giriş
- Örnek Sorular

## 1. Açgözlü teknik, optimal çözüm ve dinamik programlama üzerine düzeltmeler

Ders, önceki quiz ve ödevlerde sık görülen iki kavram yanılgısının düzeltilmesiyle başladı.

### 1.1 "0-1 sırt çantasında açgözlü teknik kullanmak gereksizdir" ifadesi

Bu ifade ancak optimal çözüm isteniyorsa doğrudur. Açgözlü (greedy) teknik çoğu durumda optimal çözümü (optimal solution) vermez; bu yüzden optimal çözüm aranıyorsa açgözlü teknik yeterli değildir. Ama soru optimal çözümü istemiyorsa, 0-1 sırt çantası (knapsack) problemi de açgözlü teknikle çözülebilir. Hoca bunu en kısa yol problemiyle örnekledi: en kısa yol algoritmalarında bir yol ya seçilir ya seçilmez; "yolun 500 km'sini seçelim, 300 km'sini seçmeyelim" gibi bir durum yoktur. Yani bu da bir 0-1 problemidir ve açgözlü teknikle (ör. Dijkstra) çözülür.

> **Ders sonrası not:** Hoca Dijkstra algoritmasının da optimal çözümü belki vermeyebileceğini söyledi. Doğrusu: Dijkstra, kenar ağırlıkları negatif olmayan çizgelerde en kısa yolları her zaman optimal olarak bulur. Açgözlü olduğu hâlde optimal sonuç verdiği kanıtlanmış bir algoritmadır; negatif ağırlıklı kenarlarda ise doğru sonuç vermeyebilir.

Açgözlü çözüm bazen optimal çözüme eşit olabilir. Para bozma probleminde paralar 1, 2, 5 ve 10 lira gibiyse ve 50 lira bozulacaksa açgözlü çözüm ile optimal çözüm aynı sonucu verir. Paralar 2, 3, 5, 7 lira gibi birbirinin tam katı olmayan değerlerse açgözlü çözüm yaklaşık bir sonuç verir. Orada da her para ya seçilir ya seçilmez; optimal çözüm dinamik programlamayla bulunabilir.

> **Hocanın vurgusu:** Optimal çözüm çoğu durumda açgözlü teknikle bulunmaz; ancak çok özel durumlarda bulunur. Bazı internet sayfalarında yazılan ifadelerde bu küçük nüans atlanmaktadır.

### 1.2 Rekürans bağıntısı ve dinamik programlama

Ödevde istenen dinamik programlama çözümüydü. Rekürans bağıntısı (recurrence relation) kurmak gereklidir, ama bağıntıyı doğrudan özyinelemeli (rekürsif) bir fonksiyonla kodlamak dinamik programlama değildir. Dinamik programlamanın ilk düşüncesi şudur: problem alt problemlerden oluşur ve bunların bazıları birbiriyle örtüşür. Sonra rekürans bağıntısı ortaya konur. Özyinelemede tekrar eden alt problemler yüzünden sonuçları saklama (memoization) fikri ortaya çıkar ve dinamik programlama budur. Yalnız özyinelemeli bir çözüm, hangisine uygunsa, böl ve fethet (divide and conquer) ya da azalt ve fethet (decrease and conquer) türünde bir algoritmadır.

> **Hocanın vurgusu:** Rekürans bağıntısı tasarlamadan dinamik programlama yapılamaz; ama rekürsif fonksiyon yazmak da dinamik programlama demek değildir.

## 2. Genişlik öncelikli arama (BFS)

Önceki derste derinlik öncelikli arama (DFS) ve geri izleme (backtracking) görülmüştü. Bu dersin asıl konusu dal ve sınır (branch and bound) yöntemidir. Dal ve sınır, genişlik öncelikli arama (breadth-first search, BFS) üzerinden çalıştığı için önce BFS anlatıldı.

### 2.1 Temel fikir

BFS de bir arama algoritmasıdır. Elimizde bir çizge (graf) vardır; bir noktadan başka bir noktaya gitmek ya da bir yeri aramak isteriz. Hoca derste "BFS hangi veri yapısını kullanır?" diye sordu.

**Soru:** BFS hangi veri yapısını kullanır? **Cevap:** Kuyruk (queue). DFS ise yığın (stack) kullanıyordu.

DFS, bulunduğu noktadan ilk gittiği yönde derinlemesine ilerler; hocanın deyişiyle "burnunun dikine gider". BFS'de durum böyle değildir: bulunulan noktadan önce çevreye bakılır, sonra çevre biraz genişletilir, sonra biraz daha. Arama, suya atılan taşın oluşturduğu halkalar gibi büyüyerek devam eder. Aranan şey yakındaysa bazı yerlere gereksiz yere bakılmış olabilir. Bu normaldir, çünkü hem DFS hem BFS kör arama (blind search) algoritmalarıdır: arama uzayı hakkında hiçbir bilgi yoktur.

Hoca bunu bir benzetmeyle açıkladı: fakültede bir odayı hiçbir levha ya da yardım olmadan arıyorsunuz. Körlemesine girip "sola gideyim" diyorsunuz, önce birinci katı, sonra ikinci katı dolaşıyorsunuz. Yapay zekâ derslerinde ilk konu da genellikle bu kör arama teknikleridir.

Kuyruk bir dizi gibi düşünülebilir; bir önü (front) ve bir arkası (rear) vardır, dairesel de olabilir. Ekleme kuyruğun arkasından, çıkarma önünden yapılır (ekrandan, 00:30:00).

### 2.2 Algoritma

Hocanın ilk yazdığı sayaçlı biçim şöyledir (ekrandan, 00:30:00):

- Çizgedeki bütün köşeler (vertex) başta ziyaret edilmemiş (unvisited, 0) olarak işaretlenir. Hoca önce "kenar" dedi, sonra "köşe" diye düzeltti.
- `bfs(v)` çağrıldığında sayaç artırılır: $c \leftarrow c + 1$. Böylece köşeye kaçıncı sırada ulaşıldığı tutulur; `visited` dizisinde köşenin yerine bu sayı yazılır.
- Köşe kuyruğa atılır (kuyruk bu köşeyle başlatılır).
- Kuyruk boş olmadığı sürece öndeki köşenin her komşusu $w$ için: $w$ ziyaret edilmemişse sayaç artırılır, $w$ sayaç değeriyle işaretlenir ve kuyruğa eklenir.
- Bütün komşular işlendikten sonra öndeki köşe kuyruktan çıkarılır.

Sonra daha kısa bir sözde kod yazdı (ekrandan, 00:40:00; satırların devamı altyazıdan):

```text
BFS(G, s)
    Queue.enqueue(s)
    mark s as visited
    while (Queue is not empty)
        v = Queue.dequeue()
        for all neighbors w of v in Graph G
            if w is not visited
                Queue.enqueue(w)
                mark w as visited
```

**Soru:** Başlangıçtaki iki satır yer değiştirse, yani önce işaretleyip sonra kuyruğa eklesek olur mu? **Cevap:** Olur. DFS'de özyinelemeli bir algoritma vardı; BFS'de özyineleme yoktur, hiçbir zaman geri gidilmez, kuyruk nereyi gösterirse oraya gidilir. Bu yüzden iki satırın sırası sonucu değiştirmez.

### 2.3 Örnek

Çizgenin kenarları şunlardır (ekrandan, 00:35:00):

```text
A - B,  A - C,  A - E
B - D
C - D,  C - G
E - F
```

Adımlar:

- A kuyruğa atılır ve ziyaret edildi olarak işaretlenir. A'nın komşuları B, C, E'dir. Hangisinin önce alınacağı komşuluk listesindeki sıraya bağlıdır; burada B, C, E sırası kullanıldı.
- B ziyaret edilip kuyruğa atılır, sonra C, sonra E. A'nın başka komşusu yoktur; A kuyruktan çıkar (1. sırada).
- Kuyruğun önünde B vardır. B'nin ziyaret edilmemiş komşusu D'dir; D ziyaret edilip kuyruğa atılır. A zaten ziyaret edilmiştir. B çıkar (2. sırada).
- Kuyruğun önünde C vardır. C'nin komşusu D ziyaret edilmiştir; G ziyaret edilip kuyruğa atılır. C çıkar (3. sırada).
- Kuyruğun önünde E vardır. Bir öğrencinin hatırlatmasıyla E'nin komşusu F'nin de ziyaret edilmediği görüldü; F kuyruğa atılır. E çıkar (4. sırada).
- D, G, F'nin ziyaret edilmemiş komşusu yoktur; sırasıyla 5., 6., 7. olarak kuyruktan çıkarlar.

Ziyaret sırası: A, B, C, E, D, G, F (python ile doğrulandı). Önce A çevresine, sonra bir halka dışına bakıldığı, yani arama alanının giderek genişlediği görülür. A'dan sonra B yerine C ile başlansaydı C'nin komşuları D ve G daha önce gelirdi; E ile başlansaydı F önce gelir, D ve G sonraya kalırdı. Sıra, veri yapısının nasıl tasarlandığına bağlıdır.

### 2.4 Bağlı olmayan çizge

Çizgede başka hiçbir köşeye bağlı olmayan bir H köşesi olsaydı, kuyruk boşaldığında H hâlâ ziyaret edilmemiş olurdu. H kuyruğa atılır, komşusu olmadığı için 8. sırada çıkar. Kuyruk boşken ziyaret edilmemiş bir köşe kalmışsa çizgede yeni bir bağlı bileşen vardır; yani çizge iki alt çizgeden oluşur. BFS ile böyle bir yorum yapılabilir.

## 3. DFS ile BFS karşılaştırması

Hoca BFS'yi önceki derste DFS için yaptığı analizin yanına yazarak karşılaştırdı (altyazıdan):

| Özellik | DFS | BFS |
|---|---|---|
| Veri yapısı | Yığın (stack) | Kuyruk (queue) |
| Köşe sıralaması sayısı | 2 sıralama | 1 sıralama |
| Komşuluk matrisiyle verimlilik | $\Theta(\lvert V\rvert^2)$ | $\Theta(\lvert V\rvert^2)$ |
| Komşuluk listesiyle verimlilik | $\Theta(\lvert V\rvert+\lvert E\rvert)$ | $\Theta(\lvert V\rvert+\lvert E\rvert)$ |
| Kenar türleri | Ağaç ve geri kenarları (tree, back) | Ağaç ve çapraz kenarlar (tree, cross) |

Hoca "iki sıralama"yı DFS'de bir noktaya tekrar geri gelinmesiyle açıkladı: bir A düğümünden başlanıp bir yere gidilir, olmadığı görülünce A'ya geri dönülür. BFS'de kuyruktan çıkan bir köşe bir daha kuyruğa girmez ve ziyaret edildi olarak işaretlenir; bu yüzden tek sıralama vardır. Komşuluk matrisi kullanılırsa 5 köşe için 5×5'lik bir matris gerekir. Kenar türlerini hoca ayrıntılı açıklamadı, araştırılmasını istedi.

> **Ek bilgi (derste anlatılmadı):** DFS'deki iki sıralama, köşelerin yığına girdiği (ilk ziyaret edildiği) sıra ile yığından çıktığı (çıkmaz sokak olduğu) sıradır. BFS'de köşeler kuyruğa girdikleri sırayla çıktıkları için bu iki sıra aynıdır. Yönsüz çizgede DFS ormanında ağaç dışı kenarlar bir köşeyi atasına bağlayan geri kenarlarıdır; BFS ormanında ise ağaç dışı kenarlar atası olmayan köşeleri bağlayan çapraz kenarlardır.

## 4. Optimizasyon problemleri ve dal ve sınır yöntemi

### 4.1 Optimizasyon

Dal ve sınır (branch and bound) bir problem çözme yöntemidir ve özellikle optimizasyon problemlerinde kullanılır (ekrandan, 00:45:00). Optimizasyonda ya bir şey maksimize ya da minimize edilir: maliyetler minimize, kârlar maksimize edilir. Bunun için bazen bir amaç fonksiyonu (objective function) olur. Hoca örnek olarak $x^3 + 3xy^2 + y^2$ gibi bir fonksiyon verdi: bir sistemin çalışma modeli olabilir ve belli bir aralıkta (ör. 0-100) bu fonksiyonu en büyük yapan $x$ ve $y$ değerleri aranır. Bu hem sürekli matematiğin (kalkülüs) hem ayrık matematiğin çalışma alanıdır.

Ayrık problemlere örnekler: beş farklı iş ve beş farklı işçi vardır, maliyetler farklıdır; hangi işçiye hangi iş atanmalı (atama problemi)? Sırt çantası probleminde de bir maksimizasyon yapılır. Bu konular endüstri mühendisliğinde çok kullanılır.

Optimizasyon belirli kısıtlar altında (under certain constraints) yapılır (ekrandan, 00:50:00). Örneğin işçilere iş atanırken bazı işler için yaş sınırı gibi koşullar olabilir; elde birçok veri vardır ve bunlar dikkate alınarak problem çözülür.

### 4.2 Çözüm türleri

Hocanın tahtaya yazdığı sınıflandırma (ekrandan, 00:50:00):

```text
Optimizasyon: minimization / maximization (under certain constraint)
├── improbable / unlikely solution      ✗
└── feasible solutions
    ├── Optimal solution                ***
    └── Approximate solution            *
```

- **Uygulanamaz çözüm (improbable / unlikely solution):** Kâğıt üzerinde bir algoritma tasarlanmıştır ama böyle bir çözüm gerçekte mümkün değildir. Hoca örnek olarak yıllar önce gündeme gelmiş, iç bölgedeki bir şehre deniz getirme projesini verdi. Bu tür çözümler kullanılmaz.
- **Uygulanabilir çözümler (feasible solutions):** Problemi çözen farklı çözümlerdir; örneğin bir atamada kime hangi işin verileceği gerekçeleriyle önerilir.
- **Optimal çözüm:** Uygulanabilir çözümlerin alt kümesidir; olabilecek en iyi çözümdür (üç yıldız).
- **Yaklaşık çözüm (approximate solution):** Tam değil ama kabul edilebilir çözümdür (bir yıldız). Bazı problemlerde hiç çözüm bulamamaktansa yaklaşık bir çözüm bulmak iyidir. Sayısal analizde doğrusal olmayan bir denklemin (ör. $x^3+3x^2+5x^7$ gibi terimlere $e^x \log x$ eklenmiş bir denklem) kökleri analitik yöntemlerle tam (exact) bulunamaz; yaklaşık çözüm veren yöntemler kullanılır.

Dinamik programlamayla bazı problemlerin tam çözümü üretilebilir, bazılarınınki üretilemez. Açgözlü çözüm genellikle tam ya da optimal çözümü vermez, yaklaşık sonuç verir. Dal ve sınırla bazı maksimizasyon ve özellikle minimizasyon problemleri çözülür. Derste iki örnek yapıldı: atama problemi ve sırt çantası problemi.

### 4.3 Hangi sınır?

Sınır (bound) ya üst sınır (upper bound) ya alt sınırdır (lower bound) (ekrandan, 01:25:00).

**Soru:** Minimizasyon için hangi sınıra bakılır? **Cevap:** Bir öğrenci "alt sınır" dedi. Hoca önce üst sınır olması gerektiğini söyledi, sonra öğrencinin doğru söylediğini kabul edip düzeltti: minimizasyonda alt sınıra bakılır.

Molaya dönüşte hoca bunu bir kez daha netleştirdi:

- **Minimizasyon:** Alt sınır kullanılır ve $\text{sonuç} \geq \text{alt sınır}$ olur. Maliyet bu sınırın altına inemez; amaç sınıra olabildiğince yakın, uygulanabilir bir çözüm bulmaktır.
- **Maksimizasyon:** Üst sınır kullanılır ve $\text{sonuç} \leq \text{üst sınır}$ olur.

> **Hocanın vurgusu:** Minimizasyonda alt sınıra bakılır ama bulunan sonuç alt sınıra eşit ya da ondan büyüktür; maksimizasyonda üst sınıra bakılır ve sonuç ondan küçük ya da ona eşittir.

Dal ve sınırda da bir durum uzayı ağacı (state space tree) çizilir ve bu ağaç BFS yöntemiyle kurulur. Bir noktadan başlanır, ilerlenir ve en iyi maliyet ağacın hangi derinliğinde bulunursa orada durulur.

## 5. Atama problemi

### 5.1 Problem

Ders kitabındaki örnek kullanıldı. 4 kişi (P1-P4) ve 4 iş (J1-J4) vardır. Matristeki değer, kişinin o işi kaç birim maliyetle yaptığıdır (ekrandan, 00:55:00):

$$
C = \begin{bmatrix} 9 & 2 & 7 & 8 \\ 6 & 4 & 3 & 7 \\ 5 & 8 & 1 & 8 \\ 7 & 6 & 9 & 4 \end{bmatrix}
\quad \begin{matrix} P_1 \\ P_2 \\ P_3 \\ P_4 \end{matrix}
$$

Sütunlar sırasıyla J1, J2, J3, J4'tür. Kısıtlar: her iş bir kişiye atanır, boşta iş kalmaz, bir kişi iki iş almaz. Amaç toplam maliyeti en aza indirmektir.

### 5.2 Sezgisel çözüm

Hoca önce öğrencilere "doğrudan düşünseniz kime hangi işi verirsiniz?" diye sordu. Bir öğrencinin önerisi şöyle oldu (ekrandan, 00:55:00): P1'e J2 (en küçük değer, 2), P3'e J3 (1), P4'e J4 (4), P2'ye kalan J1 (6). Toplam $2+6+1+4=13$. Hoca bu düşünüş tarzının aslında açgözlü tekniğe yakın olduğunu söyledi: önce en ucuz atamalar seçilip kalanlar kıyaslanıyor (P4 için J1'in 7'si ile J4'ün 4'ü gibi).

### 5.3 Alt sınır

Kısıtlar kaldırılırsa, yani "bir iş iki kişiye verilemez" kuralı yok sayılırsa, her kişi kendi satırının en küçüğünü alır: P1'den 2, P2'den 3, P3'ten 1, P4'ten 4. Toplam $2+3+1+4=10$ olur. Bu atama uygulanabilir değildir (J1'i kimse almadı, J3'ü iki kişi aldı), ama hiçbir çözümün maliyeti 10'un altına inemez. Bu yüzden 10, kökün alt sınırıdır.

**Soru:** Kısıtların hepsini kaldırırsak bir kişiye birden çok iş verilebilir mi? **Cevap:** Hayır; her kişi yine bir iş alır, yalnız "bir işi iki kişi alamaz" kısıtı kaldırılır.

### 5.4 Durum uzayı ağacı

Genel kural (ara adım eklendi): bir düğümün alt sınırı, o ana kadar yapılmış atamaların maliyeti ile henüz atanmamış her kişinin, henüz alınmamış işler arasındaki en küçük maliyetinin toplamıdır.

Kök: hiçbir atama yok, $lb = 2+3+1+4 = 10$ (ekrandan, 01:00:00).

**Birinci seviye (P1'e iş atanır)** (ekrandan, 01:05:00):

- **P1←J1:** P1'den 9. J1 artık alınamaz; P2'nin en küçüğü 3, P3'ün 1, P4'ün 4. $lb = 9+3+1+4 = 17$. Yani P1'e J1 verilirse toplam maliyet 17'nin altında olamaz.
- **P1←J2:** P1'den 2, kalanlardan 3, 1, 4. $lb = 2+3+1+4 = 10$.
- **P1←J3:** P1'den 7. J3 alındığı için P2'nin 3'ü ve P3'ün 1'i seçilemez; P2'den 4, P3'ten 5, P4'ten 4. $lb = 7+4+5+4 = 20$.
- **P1←J4:** P1'den 8. P2'den 3, P3'ten 1; J4 alındığı için P4'ün en küçüğü 6. $lb = 8+3+1+6 = 18$.

> **Ders sonrası not:** P1←J2 düğümü için altyazıda "11" sözü geçiyor; ekrandaki hesap $2+3+1+4=10$'dur ve doğrusu 10'dur.

En küçük sınır P1←J2'dedir (10). Bu düğüm genişletilir; diğerleri şimdilik bekler. Alt dallarda bu bekleyen düğümlerin sınırlarından daha kötüye gidilirse onlara dönülür, daha iyi bir sonuç bulunursa onlar elenir.

**İkinci seviye (P1←J2 altında P2'ye iş atanır)** (ekrandan, 01:10:00):

- **P2←J1:** $2 + 6$; J3 boş olduğu için P3'ten 1, P4'ten 4. $lb = 2+6+1+4 = 13$.
- **P2←J3:** $2 + 3$; J3 alındığı için P3'ten en küçük 5, P4'ten 4. $lb = 2+3+5+4 = 14$.
- **P2←J4:** $2 + 7$; P3'ten 1; J2 ve J4 alındığı için P4'ten 7. $lb = 2+7+1+7 = 17$.

Bu seviyede 13 bulunmuştur. 17 ya da 18 sınırlı düğümlerden yürümek, maliyeti en az 17-18 olan çözümler aramak demektir; 13 sınırlı düğümden yürümek daha makuldür.

**Üçüncü seviye (P1←J2, P2←J1 altında):** Geriye iki kişi (P3, P4) ve iki iş (J3, J4) kalır; iki durum vardır (ekrandan, 01:15:00).

- **P3←J3, P4←J4:** $2+6+1+4 = 13$.
- **P3←J4, P4←J3:** Bir öğrencinin düzeltmesiyle P3 için J4'ün maliyeti 8, P4 için J3'ün maliyeti 9 alındı: $2+6+8+9 = 25$.

13 maliyetli yaprak, ulaşılabilecek en düşük alt sınıra oturmuştur. Bekleyen diğer düğümlerin sınırları 14, 17, 17, 18, 20 ve 25 olduğu için hepsi budanır. Optimal atama:

| Kişi | İş | Maliyet |
|---|---|---|
| P1 | J2 | 2 |
| P2 | J1 | 6 |
| P3 | J3 | 1 |
| P4 | J4 | 4 |
| | Toplam | 13 |

Sonuç, python ile 24 permütasyonun hepsi denenerek doğrulandı. Bu, öğrencinin baştaki önerisiyle aynıdır.

**Soru:** O zaman açgözlü mü davranmış oldum? **Cevap:** İkisi de. Öğrenci açgözlü gibi düşündü ama ötesine geçti; düşünsel olarak bir anlamda dinamik programlama ya da dal ve sınır gibi bir şey yaptı. Hoca bunu yığın veri yapısına benzetti: yığın diye bir veri yapısını bilmeyen insanlar da "son giren ilk çıkar" mantığıyla birçok problemi zihninde çözer. Burada da 4×4'lük problem kafada optimum çözülebildi; sorun 8×8 gibi büyük problemlerde ortaya çıkar.

## 6. 0-1 sırt çantası problemi

### 6.1 Problem ve açgözlü çözüm

Kapasite $W = 10$'dur. Nesneler değer/ağırlık oranına göre azalan sırada dizilmiştir (ekrandan, 01:30:00):

| Nesne | Ağırlık ($w$) | Değer ($v$) | $p = v/w$ |
|---|---|---|---|
| 1 | 4 | 40 | 10 |
| 2 | 7 | 42 | 6 |
| 3 | 5 | 25 | 5 |
| 4 | 3 | 12 | 4 |

Hoca önce bir öğrenciden en yüksek değeri bulmasını istedi. Açgözlü çözüm (ödevdeki algoritma): nesneler orana göre sıralanır, kapasite dolana kadar en yüksek orandan en düşüğe sığanlar alınır. Kapasitenin tamamen dolması gerekmez.

- 1. nesne alınır (ağırlık 4, kalan yer 6).
- 2. nesne (ağırlık 7) sığmaz.
- 3. nesne alınır (ağırlık 5, kalan yer 1).
- 4. nesne (ağırlık 3) sığmaz.

Toplam değer $40 + 25 = 65$. Başka bileşimler denendi: 2. ve 3. nesne birlikte $7+5=12$ ağırlıkla sığmaz; 2. ve 4. nesne $7+3=10$ ağırlıkla sığar ama değeri $42+12=54$'tür. Hoca kaba kuvvetle $2^4 = 16$ alt kümenin hepsi denenirse 65'in garanti edileceğini, dinamik programlamanın da büyük olasılıkla 65 vereceğini söyledi (python ile 16 alt küme denendi: en iyi değer 65, nesneler 1 ve 3).

### 6.2 Üst sınır formülü

Bu bir maksimizasyon problemi olduğu için üst sınır kullanılır. Formül (ekrandan, 01:30:00):

$$ub = v + (W - w)\cdot\frac{v_{i+1}}{w_{i+1}}$$

Burada $v$ ve $w$ o ana kadar seçilen nesnelerin toplam değeri ve ağırlığı, $i$ son karar verilen nesnedir. Formül şunu söyler: çantadaki boş yerin tamamını, sıradaki nesnenin birim değeriyle (en yüksek kalan oranla) dolduruyormuş gibi say. Bu üst sınır da açgözlü düşünceden türer.

### 6.3 Durum uzayı ağacı

Her seviyede bir nesne için "alındı" (+) ve "alınmadı" (−) dalları açılır (ekrandan, 01:35:00 ve 01:40:00):

```text
kök: w=0, v=0, ub = 0 + 10*10 = 100
├── 1+ : w=4, v=40, ub = 40 + 6*6 = 76
│   ├── 2+ : w = 4+7 = 11 > 10, uygulanamaz (budandı)
│   └── 2- : w=4, v=40, ub = 40 + 6*5 = 70
│       ├── 3+ : w=9, v=65, ub = 65 + 1*4 = 69
│       │   ├── 4+ : w = 9+3 = 12 > 10, uygulanamaz (budandı)
│       │   └── 4- : w=9, v=65, ub = 65   <- çözüm
│       └── 3- : w=4, v=40, ub = 40 + 6*4 = 64
└── 1- : w=0, v=0, ub = 10*6 = 60
```

Adımların açıklaması:

- **Kök:** Hiçbir şey alınmamıştır. 10 birimlik yerin tamamı birim değeri 10 olan 1. nesneyle doldurulmuş gibi düşünülür: $ub = 0 + 10\cdot 10 = 100$. Hoca bunu "10 birimlik çantaya birim kârı 10 olan nesneden 10 tane alabilseydim" diye açıkladı; kâr 100'ü geçemez, aranan değer 100'den küçük ve ona olabildiğince yakın bir değerdir.
- **1+:** Ağırlık 4, değer 40, kalan yer 6. Bu yer 2. nesnenin birim değeri 6 ile doldurulur: $40 + 36 = 76$.
- **1−:** Ağırlık 0, değer 0. Sıradaki 2. nesnenin birim değeriyle 10 birim: $10 \cdot 6 = 60$. 76 daha iyi olduğu için 1+ dalından devam edilir.
- **2+:** Kalan yer 6, 2. nesnenin ağırlığı 7; sığmaz, dal budanır.
- **2−:** Ağırlık 4, değer 40; 6 birimlik yer 3. nesnenin birim değeri 5 ile doldurulur: $40 + 30 = 70$. Sınır 76'dan 70'e düştü ama 60'tan hâlâ iyidir.
- **3+:** Ağırlık $4+5=9$, değer $40+25=65$; 1 birimlik yer 4. nesnenin birim değeri 4 ile doldurulur: $65 + 4 = 69$.
- **3−:** Ağırlık 4, değer 40; 6 birim yer 4. nesneyle: $40 + 24 = 64$. 69 bulunduğu için bu dala bakılmaz.
- **4+:** Ağırlık $9+3=12 > 10$; uygulanamaz.
- **4−:** Ağırlık 9, değer 65. 4. nesneden sonra nesne kalmadığı için $ub = 65$. Çözüme ulaşılmıştır.

> **Ders sonrası not:** Hoca 3+ düğümünde "lower bound'ım 70'den 69'a geldi" dedi; burada kastedilen üst sınırdır.

Ağaçta geriye doğru gidildiğinde "+" olan dallar 1. ve 3. nesnelerdir; en iyi değer 65'tir. Hoca sınır formülünü günlük hayattaki "yükte hafif, pahada ağır" sözünün dal ve sınıra uygulanması olarak özetledi.

> **Ek bilgi (derste anlatılmadı):** Dal ve sınırda bir yaprakta bulunan uygulanabilir çözümün değeri, bekleyen her düğümün üst sınırından büyük ya da ona eşitse o düğümler budanabilir. Burada 65, bekleyen düğümlerin sınırları olan 64 ve 60'tan büyük olduğu için başka dal açılmasına gerek kalmaz.

## 7. Optimizasyon tekniklerinin önemi

Hoca atama problemleri için Macar algoritmasından (Hungarian algorithm) söz etti; endüstri mühendislerinin çok kullandığı, zor olmayan bir algoritmadır ve araştırılabilir. Kısa yollar için Dijkstra gibi algoritmalar da optimizasyonda kullanılır; bunlar veri yapıları ve ayrık matematik derslerinde de görülür.

Hocanın tavsiyesi: yenilik üreten yerlerde kişinin hangi programlama dilini bildiğinden çok, bir şeyler geliştirip düşünebilme ve soyut modelleme yapabilme yeteneğine bakılır. Bu yüzden bu derste görülen konulara, özellikle dinamik programlamaya ve özyinelemeli tasarıma çalışılmalıdır. Ders kitabı bu açıdan çok iyi bir kaynaktır.

## 8. Dönüştür ve fethet

Dönüştür ve fethet (transform and conquer) bir metodolojidir: bir problemin çözümü, daha önceden bilinen çözümler türünden ortaya çıkarılır. Elde bir çözüm yöntemi vardır; problem başka bir şeye dönüştürülerek bu yöntemle çözülür (ekrandan, 01:45:00). Hoca bunu "transfer and conquer" diye de adlandırdı: eğitim bilimlerindeki bilgi transferi gibi, mevcut bir bilgiyi alıp başka bir yerde kullanabilmektir.

> **Hocanın vurgusu:** Bilginin transfer edilememesi kadar kötü bir şey yoktur; bu, boşuna öğrenilmiş demektir. QuickSort'u öğrenip hiçbir yerde kullanamıyorsanız bir sorun vardır.

### 8.1 Denklem sistemi örneği

Sınavlardaki kâr-zarar problemleri gibi bir metin okunur ve 7 bilinmeyenli 7 denklem kurulur. Bunu elle çözmek zahmetlidir. Ama Gauss eliminasyonu bilinen bir yöntemdir; iş, senaryodan modeli ve denklemleri çıkarmaya gelir, gerisi Gauss eliminasyonuyla çözülür. Bu bir dönüşümdür.

### 8.2 `find_min` ile en büyük elemanı bulma

Elimizde bir diziyi alıp en küçük elemanını döndüren hazır bir fonksiyon olsun (ekrandan, 01:45:00):

```text
int find_min(dizi)
```

**Soru:** Fonksiyonun içini değiştirmeden dizinin en büyük elemanı nasıl bulunur? **Cevap (bir öğrenci):** Elemanların eksileri alınır.

Ekrandaki örnek:

```text
dizi     :  6   1   2   8   3     -> find_min = 1
negatifi : -6  -1  -2  -8  -3     -> find_min = -8
en büyük : -(-8) = 8
```

Dizinin negatifi alınır, `find_min`'e verilir, dönen en küçük değerin tekrar negatifi alınır: $\max(A) = -\min(-A)$.

### 8.3 Ön sıralama ve indeksleme

Bir dizide sürekli eleman aranıyorsa (belki milyonlarca eleman vardır), $n$ elemanlı dizide $n$ kez doğrusal arama yapmak en kötü durumda $n^2$ karmaşıklığa gider. Bunun yerine dizi önce $n \log n$ bir sıralama algoritmasıyla sıralanır, sonra her arama ikili arama (ya da başka bir arama) ile daha kısa sürede yapılır. Hash de bir seçenektir.

Bankalar gibi büyük verilerle çalışan kurumlar sistemlerini zaman zaman bakıma alır; bu sırada veritabanı yeniden indekslenir. İndeksleme bir anlamda basit bir sıralamadır ve veriye erişimi kolaylaştırır. Ekleme ve çıkarmalarla verinin dağılımı değiştikçe işlemler yavaşlar; belli aralıklarla indeksleme yeniden yapılarak veri uygun hâle getirilir.

> **Ek bilgi (derste anlatılmadı):** $m$ arama için ön sıralamalı yaklaşımın maliyeti yaklaşık $n\log n + m\log n$, doğrudan doğrusal aramanınki $m \cdot n$'dir. Arama sayısı $m$ büyüdükçe ön sıralama daha avantajlı olur.

## 9. Alt sınır kavramına giriş

Hoca dersin sonunda alt sınır (lower bound) konusuna kısaca giriş yaptı; kitapta bu konu ayrı bir bölümdür. Tahtaya "Lower Bound: Ω (Best case)" yazdı (ekrandan, 01:50:00).

**Soru:** Alt sınır için hangi asimptotik gösterim kullanılır? **Cevap:** $\Omega$. Hoca bunun "olsa olsa bu kadar iyi olur" dediğimiz en iyi durumu söylediğini belirtti.

Bazı problemlerde bir çözüm tekniği seçilmeden önce (dinamik programlama mı, açgözlü mü, hash mi?) bir alt sınır analizi yapılır; geliştirilecek algoritmada en iyi durumun en fazla ne olabileceği belirlenir ve tasarım buna göre yapılır.

**Soru:** Sıralı olmayan bir dizide eleman aramanın alt sınırı nedir? **Cevap (bir öğrenci):** 1; aranan eleman ilk eleman olabilir. Hoca bu cevabı kabul etti.

**Soru:** Sıralı bir dizide arama yapmanın alt sınırı nedir? **Cevap (bir öğrenci):** $\log n$, ikili arama ile.

Hoca ikili aramadan daha iyi algoritmalar da olduğunu söyledi. Sayısal analizde kök bulmada ikiye bölme (bisection) yöntemi ikili aramaya karşılık gelir. Regula falsi yöntemi ise 1/2 ile çarpmak yerine daha iyi bir katsayı kullanır; buna karşılık gelen arama $\log \log n$'e kadar inebilir, 1024 elemanda aranan neredeyse iki üç adımda bulunabilir. Bu yöntemin kısıtları vardır ve ayrıntısına girilmedi.

> **Ders sonrası not:** Hoca $\Omega$'yı en iyi durumla eşledi ve sırasız dizide arama için alt sınırı 1 olarak kabul etti. Doğrusu: $\Omega$ yalnız asimptotik bir alt sınır gösterimidir; en kötü, ortalama ya da en iyi durumun herhangi biri için kullanılabilir. Ders kitabındaki anlamıyla bir problemin alt sınırı, o problemi çözen her algoritmanın en kötü durumda yapması gereken en az iştir. Bu anlamda sırasız dizide arama için alt sınır $\Omega(n)$ (her elemana bakılmadan elemanın yokluğu bilinemez), sıralı dizide karşılaştırmaya dayalı arama için $\Omega(\log n)$'dir. $\log \log n$ değeri, regula falsi fikrine dayanan interpolasyon aramasının düzgün dağılımlı verideki ortalama durumudur; en kötü durumu $n$'dir.

## Örnek Sorular

Aşağıdaki ilk dört soru, ders günü yapılan sınavın soru kâğıdından, hoca soruları açıklarken ekrandan ve sözlü anlatımdan alınmıştır. Sınav bu dersin konularını değil önceki konuları kapsıyordu; çözümler derste verilmedi.

**Soru 1** (ekrandan, 00:05:00 ve 00:10:00):

a) Aşağıdaki kavramları kısa, öz ve doğru bir şekilde ve tek bir örnek vererek açıklayınız. (Yanlış veya belirsizlik içeren açıklamalar değerlendirilmez.)

- 1) Kaba kuvvet (Brute Force)
- 2) En kötü durum analizi (Worst Case Analysis)
- 3) Büyük Omega ($\Omega$)
- 4) Azalt Fethet (Decrease by conquer)

b) A1 ve A2 algoritmalarının hangisinin daha verimli olduğuna karar vermek için yapılması gerekenler nelerdir, maddeler hâlinde kısaca açıklayınız.

> **Çözüm (derste verilmedi):**
> - Kaba kuvvet: problemi tanımına doğrudan dayanarak, bütün olasılıkları deneyerek çözen yaklaşım. Örnek: $n$ elemanlı dizide en küçük elemanı her elemana bakarak bulmak ya da seçmeli sıralama.
> - En kötü durum analizi: $n$ boyutlu girdiler arasında algoritmanın en fazla temel işlem yaptığı girdi için çalışma süresinin belirlenmesi. Örnek: doğrusal aramada aranan elemanın dizide olmaması, $C_{worst}(n) = n$.
> - Büyük Omega: $t(n) \geq c\,g(n)$ koşulunu her $n \geq n_0$ için sağlayan pozitif $c$ ve $n_0$ varsa $t(n) \in \Omega(g(n))$; büyüme hızı için asimptotik alt sınırdır. Örnek: $n^3 \in \Omega(n^2)$.
> - Azalt ve fethet: problemin bir örneğinin çözümü ile daha küçük bir örneğinin çözümü arasındaki ilişkiden yararlanma; boyut sabit miktar, sabit oran ya da değişken miktarda azaltılır. Örnek: eklemeli sıralama (bir azalt), ikili arama (yarıya azalt).
> - b şıkkı için: girdi boyutunu belirle; temel işlemi belirle; temel işlemin kaç kez çalıştığını girdi boyutuna göre ifade et (gerekirse en kötü, en iyi, ortalama durumları ayrı ayrı); toplam ya da rekürans bağıntısı kurup çöz; elde edilen büyüme hızlarını asimptotik gösterimle ($O$, $\Theta$, $\Omega$ ya da limit yöntemiyle) karşılaştır; gerekirse bellek karmaşıklığını da karşılaştır.

**Soru 2** (derste sözlü, 00:06:22): Bubble sort algoritmasını kullanarak C dilinde, içinde boşluk olmayan ve büyük harfler içeren bir metnin karakterlerini A'dan Z'ye sıralayacak C fonksiyonunu aşağıdaki şartlara göre yazınız. a) Algoritma en iyi durumda $O(n)$ karmaşıklıkla çalışabilmelidir; buna göre kodunuzda gerekli düzenlemeyi yapınız ve bu düzenlemenin gerekçesini açıklayınız. b) Algoritmanın en kötü durum analizini matematiksel analiz yöntemiyle, temel operasyonu belirleyerek yazınız.

> **Çözüm (derste verilmedi):** Bir geçişte hiç yer değiştirme olmazsa dizi sıralıdır; bayrakla döngüden çıkılır. Sıralı girdide yalnız bir geçiş yapılır ve en iyi durum $n-1$ karşılaştırma, yani $O(n)$ olur. Aşağıdaki fonksiyon gcc -Wall ile derlenip "ALGORITMA" girdisiyle denendi, "AAGILMORT" çıktısını verdi.
>
> ```c
> void bubble(char *s) {
>     int n = strlen(s), i, j, sw;
>     char t;
>     for (i = 0; i < n - 1; i++) {
>         sw = 0;
>         for (j = 0; j < n - 1 - i; j++)
>             if (s[j] > s[j + 1]) {
>                 t = s[j]; s[j] = s[j + 1]; s[j + 1] = t;
>                 sw = 1;
>             }
>         if (!sw) break;
>     }
> }
> ```
>
> En kötü durum (ters sıralı metin): temel işlem `s[j] > s[j+1]` karşılaştırmasıdır. $C_{worst}(n) = \sum_{i=0}^{n-2}\sum_{j=0}^{n-2-i} 1 = \sum_{i=0}^{n-2}(n-1-i) = \frac{n(n-1)}{2} \in \Theta(n^2)$.

**Soru 3** (derste sözlü, 00:07:08): Decrease by half (yarıya azalt) yöntemini kullanarak C dilinde $\log_2 n$ değerini hesaplayan programın fonksiyonunu verilen fonksiyon prototipiyle yazınız. a) Gerekli özyinelemeli bağıntıyı (recurrence relation) yazınız. b) Algoritmanın zaman ve bellek karmaşıklığını özyinelemeli bağıntıyı kullanarak geriye doğru yerine koyma (backward substitution) ve Master teoremi ile ayrı ayrı hesaplayınız. c) Algoritmanızın doğruluğunu göstermek için belirleyeceğiniz iki farklı $n$ değeriyle algoritmanın özyinelemeli çalışmasını adım adım gösteriniz.

<!-- BELİRSİZ: Sınav kâğıdındaki fonksiyon prototipi karelerde görünmüyor; aşağıdaki prototip ajan tarafından seçildi. -->

> **Çözüm (derste verilmedi):** $\lfloor \log_2 n \rfloor$ için $L(1) = 0$, $L(n) = 1 + L(\lfloor n/2 \rfloor)$. Aşağıdaki fonksiyon gcc -Wall ile derlenip denendi: 1→0, 2→1, 8→3, 10→3, 17→4, 1024→10.
>
> ```c
> int log2_dbh(int n) {
>     if (n == 1) return 0;
>     return 1 + log2_dbh(n / 2);
> }
> ```
>
> Zaman için bağıntı $T(n) = T(n/2) + 1$, $T(1) = 0$. Geriye doğru yerine koyma ($n = 2^k$): $T(2^k) = T(2^{k-1}) + 1 = T(2^{k-2}) + 2 = \dots = T(2^0) + k = k = \log_2 n$, yani $\Theta(\log n)$. Master teoremi: $a = 1$, $b = 2$, $f(n) = \Theta(n^0)$, $d = 0$; $a = b^d$ olduğundan $T(n) \in \Theta(n^d \log n) = \Theta(\log n)$. Bellek: özyineleme derinliği kadar yığın çerçevesi gerekir; $S(n) = S(n/2) + 1$ ile $\Theta(\log n)$. Örnek çalışma: $n=8$: $L(8) = 1 + L(4) = 2 + L(2) = 3 + L(1) = 3$; $n=10$: $L(10) = 1 + L(5) = 2 + L(2) = 3 + L(1) = 3$.

**Soru 4** (derste sözlü, 00:07:56): $N \times M$'lik bir alanda hareket eden robot tavşan, bu alanın farklı yerlerinde bulunan havuçları toplamaktadır. Robot $(0,0)$ noktasından başlayıp $(N-1, M-1)$ noktasına doğru yalnız sağa ya da aşağıya gitmektedir. En fazla havucu toplayacak yolu ve toplanabilecek en fazla havuç miktarını bulan algoritmayı dinamik programlama kullanarak çözen programı aşağıdaki maddelere göre yazınız. a) Gerekli rekürans bağıntısını yazınız. b) Uygun veri yapısını seçerek dinamik programlamaya göre sonuç üreten fonksiyonu sözde kodla ya da C ile yazınız. c) Verilen 5×6 birimlik alan için toplanacak en fazla havuç miktarını ve robotun olası hareket rotasını, tasarladığınız algoritmaya göre adım adım gösteriniz. d) Algoritmanın zaman ve bellek karmaşıklığını yazınız.

<!-- BELİRSİZ: 5×6'lık örnek alanın havuç değerleri karelerde görünmüyor; c şıkkının sayısal sonucu verilemedi. -->

> **Çözüm (derste verilmedi):** $c_{ij}$ hücredeki havuç sayısı olsun. $F(0,0) = c_{00}$; $F(0,j) = F(0,j-1) + c_{0j}$; $F(i,0) = F(i-1,0) + c_{i0}$; diğer hücrelerde $F(i,j) = \max\{F(i-1,j),\, F(i,j-1)\} + c_{ij}$. Sonuç $F(N-1, M-1)$'dir. $N \times M$'lik bir tablo satır satır doldurulur; rota, son hücreden başlayarak her adımda $F$ değeri büyük olan üst ya da sol komşuya geri gidilerek bulunur. Zaman $\Theta(NM)$, bellek $\Theta(NM)$ (yalnız değer isteniyorsa tek satırla $\Theta(M)$).

**Soru 5** (derste sözlü, 00:52:22): Bölüm 5'teki maliyet matrisi için kim hangi işe atanmalıdır?

> **Çözüm (derste verildi):** P1→J2, P2→J1, P3→J3, P4→J4; toplam maliyet 13. Dal ve sınır ağacı Bölüm 5.4'tedir.

**Soru 6** (derste sözlü, 01:25:28): Bölüm 6'daki dört nesne ve 10 kapasiteli çanta için elde edilebilecek en yüksek değer nedir?

> **Çözüm (derste verildi):** 1. ve 3. nesneler alınır, toplam ağırlık 9, toplam değer 65. Açgözlü çözüm de bu örnekte 65 verir; dal ve sınır ağacı Bölüm 6.3'tedir.

**Soru 7** (derste sözlü, 01:42:58): Bir dizinin en küçük elemanını döndüren `find_min` fonksiyonunun içini değiştirmeden, bu fonksiyonla dizinin en büyük elemanı nasıl bulunur?

> **Çözüm (derste verildi):** Dizinin bütün elemanlarının negatifi alınır, `find_min` çağrılır, dönen değerin negatifi alınır. 6, 1, 2, 8, 3 için sonuç 8'dir.

## Dersin Toparlaması

Bu derste önce kuyruk veri yapısını kullanan, özyinelemesiz ve katman katman genişleyen genişlik öncelikli arama (BFS) görüldü ve önceki derste görülen DFS ile karşılaştırıldı. Ardından BFS mantığıyla bir durum uzayı ağacı kurup her düğümde bir sınır hesaplayan ve umut vermeyen dalları budayan dal ve sınır yöntemi anlatıldı. Minimizasyon problemi olan atama probleminde alt sınırla 13 maliyetli optimal atama, maksimizasyon problemi olan 0-1 sırt çantası probleminde açgözlü düşünceden türeyen üst sınırla 65 değerli optimal seçim bulundu.

Son kısımda bir problemi çözümü bilinen başka bir probleme dönüştüren dönüştür ve fethet yaklaşımı (Gauss eliminasyonu, $\max(A) = -\min(-A)$, ön sıralama ve indeksleme) ve alt sınır analizine kısa bir giriş yapıldı. Hoca bir sonraki dersin son konu olan problem türlerine ayrılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
