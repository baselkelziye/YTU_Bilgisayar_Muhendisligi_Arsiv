# Ders 20 Genişletilmiş Notu: Renkli BFS/DFS, Açgözlü Algoritmalar, Özyineleme ve Merge Sort

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Graf Problemlerinin Gerçek Hayattaki Yeri ve Önceki Dersin Hatırlatması
- 2. Renkli BFS
- 3. Renkli DFS
- 4. Açgözlü (Greedy) Algoritmalar
- 5. Özyinelemeli Algoritmalar
- 6. Özyinelemeli Algoritmalarda Big-O
- 7. Algoritmik Çözüm Yaklaşımları
- 8. Böl ve Yönet (Divide and Conquer)
- 9. Top-Down Merge Sort
- 10. Merge İşlemi
- 11. Merge Sort Örnekleri

## 1. Graf Problemlerinin Gerçek Hayattaki Yeri ve Önceki Dersin Hatırlatması

Hoca derse, graflarla ilgili problemlerin gerçek dünya problemleri olduğunu söyleyerek başladı. Arama motorları kelimeleri ve kelimeler arasındaki ilişkileri, kenarları ağırlıklandırılmış çok büyük bir graf olarak tutar. Sorgulara verilen öneriler de bu benzerlikler sıralanarak üretilir. Hoca bu örnekle yığıt, kuyruk ve heap gibi soyut görünen veri yapılarının günlük kullanılan uygulamaların içindeki algoritmalarda çalıştığını vurguladı.

Önceki derste graflara giriş yapılmış ve bütün düğümleri en düşük maliyetle bir ağaç biçiminde bağlama problemi, yani en küçük yayılan ağaç (minimum spanning tree) ele alınmıştı. Bunun için iki farklı yaklaşım görülmüştü:

- Kruskal yöntemi: küçük ağaçlardan bir orman kurup bunları birleştire birleştire tek ağaca ulaşmak.
- Prim yöntemi: tek bir ağaçla başlayıp her adımda en hafif kenarı ekleyerek büyümek.

Hoca, başka algoritmalar da olduğunu ama bu ikisinin farklı çözüm yaklaşımlarını göstermek için seçildiğini söyledi. Ayrıca grafta gezinme (arama) için BFS ve DFS de görülmüştü: BFS bir kuyruk kullanıyor, DFS ise özyinelemeli çağrılarla gidebildiği yere kadar gidip bir erişim ağacı oluşturuyordu. Bu derste ikisi de geliştirilerek tekrar ele alındı. Amaç, DFS'te gezilemeyen düğümlerin de keşfedilmesini sağlamaktı.

## 2. Renkli BFS

### 2.1 Düz BFS'in hatırlatması

Önce genişlemesine aramanın (breadth first search) sözde kodu hatırlatıldı (ekrandan, 00:15:00):

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

Başlangıç düğümünün uzaklığı 0, diğerlerininki sonsuzdur. Kuyruk boş olmadığı sürece baştaki eleman çekilir ve henüz gezilmemiş komşularının uzaklığı kendi uzaklığının bir fazlası yapılır. Böylece başlangıçtan bir adımda gidilenler birinci komşular, onların komşuları iki adımda gidilenler olur. Önce birinci derece komşuların, sonra ikinci derece komşuların işlenmesi istendiği için FIFO (ilk giren ilk çıkar) kuyruk kullanılır.

### 2.2 Renk kodlaması

Bazı uygulamalarda gezinti sırasında düğümlerin durumunu takip etmek gerekir: Bu düğüm şimdiye kadar gezildi mi? Hoca bunu anlaşılması kolay olsun diye renklerle kodladı ve algoritmayı "renkli BFS" diye adlandırdı. Üç durum vardır:

- Beyaz: düğüme hiç dokunulmamış, uzaklığı hâlâ sonsuz.
- Gri: düğüm bir komşuluk ilişkisi yüzünden keşfedilmiş ve kuyruğa girmiş.
- Siyah: düğümün bütün komşuları işlenmiş, onunla işimiz tamamen bitmiş.

Bu durumlar 0, 1, 2 gibi sayılarla da tutulabilirdi; hoca analizde takibi kolaylaştırmak için renkleri tercih etti. Bu tanımdan şu çıkarımlar yapılır: Siyahın komşuları siyah ya da gri olabilir; grinin komşuları gri ya da beyaz olabilir.

### 2.3 Renkli BFS sözde kodu

Renkli BFS'te her düğüm için bir de parent (`p`) tutulur: Bu düğüme hangi düğümden gelindi? (ekrandan, 00:25:00)

```text
BFS (G,s)
for each vertex u ∈ G.V – {s}
    u.color = WHITE
    u.d = ∞
    u.p = NIL
s.color = GRAY
s.d = 0
s.p = NIL
Q = { } ;
ENQUEUE(Q,s)
while Q != { }
    u = DEQUEUE(Q)
    for each v ∈ G.Adj[u]
        if v.color == WHITE
            v.color = GRAY
            v.d = u.d + 1
            v.p = u
            ENQUEUE(Q,v)
    u.color = BLACK
```

Başlangıç düğümü beyaz değil, doğrudan gri yapılır; çünkü ona artık dokunulmuştur. Parent'ı NIL'dir, çünkü erişim ağacının kökü olacaktır. Kuyruktan çekilen `u`'nun yalnız beyaz komşularına bakılır; beyaz olmayan komşular atlanır. Beyaz bir komşu bulunduğunda hemen griye boyanır ("seni gördüm, seninle temas kurdum"), uzaklığı `u.d + 1`, parent'ı `u` yapılır ve kuyruğa eklenir. `u`'nun bütün beyaz komşuları bitince `u` siyaha boyanır. Hoca, "yalnız beyazları gez, grilere zaten bakmıştın" kontrolünün BFS'i biraz daha iyileştirdiğini söyledi.

### 2.4 Renkli BFS örneği

Örnek graf yönsüzdür ve 8 düğümü vardır (ekrandan, 00:20:00). Üst sırada `r, s, t, u`, alt sırada `v, w, x, y` bulunur. Kenarlar:

```text
r–s, r–v, s–w, w–t, w–x, t–x, t–u, x–u, x–y, u–y
```

Gezinti `s`'den başlar. Adımlar ve her adımdan sonra kuyruğun durumu (parantez içinde uzaklıklar):

| Adım | Çekilen düğüm | Griye boyananlar (uzaklık, parent) | Siyaha boyanan | Kuyruk |
|---|---|---|---|---|
| a | – | `s` (0, NIL) | – | `s` |
| b | `s` | `w` (1, s), `r` (1, s) | `s` | `w r` |
| c | `w` | `t` (2, w), `x` (2, w) | `w` | `r t x` |
| d | `r` | `v` (2, r) | `r` | `t x v` |
| e | `t` | `u` (3, t) | `t` | `x v u` |
| f | `x` | `y` (3, x) | `x` | `v u y` |
| g | `v` | – | `v` | `u y` |
| h | `u` | – | `u` | `y` |
| i | `y` | – | `y` | boş |

`b` adımından sonra hoca şuna dikkat çekti: Bir düğümün bütün komşuları gezilmiş, iki düğüm keşfedilmiş, beş düğüm hâlâ beyazdır. `e` adımında dört düğümle iş tamamen bitmiş, üç düğüm keşfedilmiş, `y` ise hâlâ beyazdır. `f` adımından sonra beyaz düğüm kalmaz; bu andan itibaren döngüdeki `if` hiç çalışmayacağı için algoritma biraz hızlanır. Parent bilgisiyle yol da izlenebilir: `v`'nin parent'ı `r`, `r`'nin parent'ı `s` olduğu için `s → r → v` yolu bulunur. Önceki derste DFS'te yapılan "path to" türü sorgular, BFS'te de yalnız bir parent tutarak yapılabilir.

Bu örnekte graf yönsüz ve bağlı olduğu için bütün düğümler gezildi. Hoca, özellikle yönlü graflarda bazı düğümlerin gezilemeyebileceğini, beyaz kontrolüyle bunun önüne geçilebileceğini söyledi.

## 3. Renkli DFS

### 3.1 Düz DFS'in hatırlatması

Derinlemesine aramada (depth first search) düğümler özyinelemeli olarak ziyaret edilir: Başlangıç düğümünden ilk komşusuna, onun ilk komşusuna gidilir; gidilemeyen yerde geri dönülüp ikinci komşuya geçilir. Önceki derste her düğüm işaretlenip `count` sayacı bir artırılıyor, sonra işaretsiz bütün komşular için DFS yeniden çağrılıyordu. Hoca, `count`'un o zaman hiç kullanılmadığını, bu derste düğümlerin hangi sırayla ve kaç adımda gezildiğini izlemek için zaman bilgisinin kullanılacağını söyledi.

### 3.2 Renkli DFS sözde kodu

(ekrandan, 00:30:00)

```text
DFS(V, E)
for each u ∈ V
    do color[u] ← WHITE
time ← 0
for each u ∈ V
    do if color[u] = WHITE
         then DFS-VISIT(u)

DFS-VISIT(u)
color[u] ← GRAY      // discover u
time ← time+1
d[u] ← time
for each v ∈ Adj[u]  // explore (u, v)
    do if color[v] = WHITE
         then DFS-VISIT(v)
color[u] ← BLACK
time ← time+1
f [u] ← time         // finish u
```

`time` değişkeni evrensel bir sayaç, bir saat tiki gibidir; her keşifte ve her bitişte bir artırılır. Böylece her düğüm için iki bilgi tutulur:

- `d[u]`: düğümün keşfedildiği (griye boyandığı) tik.
- `f[u]`: düğümle işin bittiği, özyinelemeden çıkılıp siyaha boyandığı tik.

Düz DFS'ten farkı dış döngüdür. Normal DFS tek bir başlangıç düğümünden gezinti başlatır ve erişilemeyen düğümler kalabilir. Renkli DFS'te beyaz kalan her düğüm için yeniden `DFS-VISIT` çağrılır; yani gerekirse birden fazla kez özyinelemeli gezinti başlatılır ve grafın tamamı keşfedilir. `DFS-VISIT` içinde de BFS'teki gibi yalnız beyaz komşulara gidilir.

### 3.3 Yönlü graf örneği

Erişilemeyen düğümler olsun diye örnek özellikle yönlü bir graf üzerindedir (ekrandan, 00:35:00). Düğümler üstte `u, v, w`, altta `x, y, z`'dir. Kenarlar:

```text
u→v, u→x, x→v, v→y, y→x, w→y, w→z, z→z
```

Gezinti `u`'dan başlar. Hoca çağrı yığıtını (call stack) yanına yazarak izledi:

| Tik | Olay | Çağrı yığıtı |
|---|---|---|
| 1 | `u` keşfedildi (gri) | u |
| 2 | `v` keşfedildi (u'nun ilk komşusu) | u v |
| 3 | `y` keşfedildi (v'nin tek komşusu) | u v y |
| 4 | `x` keşfedildi (y'nin tek komşusu) | u v y x |
| 5 | `x` bitti (beyaz komşusu yok, siyah) | u v y |
| 6 | `y` bitti | u v |
| 7 | `v` bitti | u |
| 8 | `u` bitti (x artık siyah) | – |
| 9 | dış döngü: `w` beyaz, `w` keşfedildi | w |
| 10 | `z` keşfedildi (y siyah olduğu için atlandı) | w z |
| 11 | `z` bitti (tek komşusu kendisi, zaten gri) | w |
| 12 | `w` bitti | – |

Sonuç: `u 1/8, v 2/7, y 3/6, x 4/5, w 9/12, z 10/11`. Eski DFS 8. tikte dururdu; `w` ve `z` hiç keşfedilmezdi. Renkli DFS'te dış döngü bir sonraki beyaz düğüm olan `w`'dan devam eder.

Hoca keşif ve bitiş zamanlarının yorumunu şöyle yaptı: Aradaki fark ne kadar açıksa düğümden o kadar fazla özyinelemeli dallanma yapılmıştır. `x` için 4/5 gibi fark bir ise o düğümden yeni bir çağrı başlamamış, hiçbir yere gidilemeden geri dönülmüştür. `y` için 3/6 gibi bir fark, aşağı doğru dallanılıp geri gelindiğini gösterir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki şekillerde bazı kenarların yanında B, F ve C harfleri görünüyor. Bunlar DFS kenar sınıflandırmasıdır: B (back) bir düğümden atasına giden geri kenar, F (forward) ağaçta olmayan ve torununa giden ileri kenar, C (cross) iki ayrı dal arasındaki çapraz kenardır. Örnekte `x→v` ve `z→z` geri, `u→x` ileri, `w→y` çapraz kenardır.

### 3.4 Yönsüz labirent örneği

Önceki dersteki labirent örneği (0'dan girip 4'ten çıkmaya çalışılan) bu kez renkli DFS ile işletildi (ekrandan, 00:45:00). Komşuluk listesi:

```text
0: 2 1 5
1: 0 2
2: 0 1 3 4
3: 5 4 2
4: 3 2
5: 3 0
```

Gezinti `dfs(0)` ile başlar:

1. `0` gri, `d=1`. İlk komşusu `2`'ye gidilir.
2. `2` gri, `d=2`, parent'ı 0. `2`'nin ilk komşusu `0` beyaz değil, atlanır. İkinci komşu `1` beyazdır.
3. `1` gri, `d=3`, parent'ı 2. Komşuları `0` ve `2` gri olduğu için iş biter: `1` siyah, `f=4`.
4. `2`'ye dönülür, sıradaki komşu `3`: gri, `d=5`, parent'ı 2.
5. `3`'ün ilk komşusu `5`: gri, `d=6`, parent'ı 3. Komşuları `3` ve `0` renkli olduğu için `5` siyah, `f=7`.
6. `3`'ün sıradaki komşusu `4`: gri, `d=8`, parent'ı 3. Komşuları `3` ve `2` renkli olduğu için `4` siyah, `f=9`.
7. `3`'ün son komşusu `2` zaten gri; `3` siyah, `f=10`.
8. `2`'nin kalan komşusu `4` zaten siyah; `2` siyah, `f=11`.
9. `0`'a dönülür, kalan komşuları `1` ve `5` siyah; `0` siyah, `f=12`.

Slayttaki sonuç tablosu:

| Düğüm | d | f | Pre |
|---|---|---|---|
| 0 | 1 | 12 | – |
| 1 | 3 | 4 | 2 |
| 2 | 2 | 11 | 0 |
| 3 | 5 | 10 | 2 |
| 4 | 8 | 9 | 3 |
| 5 | 6 | 7 | 3 |

Gezinti toplam 12 tikte tamamlandı. 3/4, 6/7, 8/9 gibi farkı bir olan düğümlerin bütün komşularının zaten gezilmiş olduğu doğrudan görülür. 5/10 gibi geniş aralıklar daha fazla dallanmayı, 1/12 ise en fazla dallanmayı gösterir.

Hoca BFS ve DFS'in renk kodlu hâllerinin ileride çok işe yarayacağını, örneğin en kısa yol problemlerinde yolu takip etmek için bu gezintilerin kullanılacağını söyledi.

## 4. Açgözlü (Greedy) Algoritmalar

### 4.1 Tanım

Hoca bu konuyu derinlemesine anlatmayacağını, dersin asıl konusu olan böl ve yönete geçmeden önce başka bir algoritmik yaklaşımı tanıtmak istediğini söyledi. Bazı problemler belirli bir sırayla, parça parça yapılan bir dizi işlemle çözülür. Bu tür adım adım çözülen problemlerde her adımda yapılan seçim şu üç özelliği taşıyorsa yaklaşım açgözlüdür (greedy):

- Yapılabilir (feasible) olmalıdır.
- Yerel olarak en iyi (local optimal) olmalıdır: O anda içinde bulunulan durumda en iyi hareket neyse o yapılır.
- Geri alınamaz olmalıdır: Bir seçim yapıldıktan üç adım sonra geri dönüp değiştirilemez.

Greedy yöntem her problem için en iyi çözümü getirmez, ama genellikle hızlı ve yakın sonuç ürettiği için tercih edilir.

### 4.2 Örnekler

Slayttaki örnekler (ekrandan, 00:55:00):

- Optimal çözüm verdiği problemler: bozuk para üstü vermek, minimum spanning tree, tek kaynaklı en kısa yollar (single-source shortest paths: bir başlangıç düğümünden seçilen düğümlere en kısa nasıl gidilir), basit çizelgeleme problemleri, Huffman kodlaması.
- Yaklaşık çözüm için kullanıldığı problemler: gezgin satıcı problemi, sırt çantası problemi, diğer kombinatoryal optimizasyon problemleri.

Gezgin satıcı probleminde bir graf (orijinalinde şehirler) vardır ve çantalı bir satıcı bütün düğümleri gezmek zorundadır; minimum yayılan ağaçtan farkı, bir düğümün üzerinden tekrar geçilebilmesidir. Amaç satıcıyı en az yoracak gezinti rotasını bulmaktır. Sırt çantası probleminde hacmi belli bir çanta ve her birinin boyutu (ağırlık ya da hacim) ve fiyatı olan kutular vardır; çantaya en yüksek toplam fiyatı sığdırmak istenir. Her adımda yapılabileceklerin en iyisi seçilerek optimale yakın bir çözüm bulunabilir.

### 4.3 Bozuk para üstü verme

Bozuk paralar 1 TL, 50 kuruş, 25 kuruş, 10 kuruş, 5 kuruş ve 1 kuruş olsun. 52 kuruşluk alışverişte 1 lira verilirse 48 kuruş para üstü verilmelidir. Hoca, kasiyerlerin ve minibüsçülerin para üstünü nasıl hızla verdiğini örnek gösterdi: Her adımda farkı en çok kapatan en büyük para verilir (ekrandan, 01:00:00).

| Adım | Verilen | Kalan |
|---|---|---|
| 1 | 25 Kr | 23 Kr |
| 2 | 10 Kr | 13 Kr |
| 3 | 10 Kr | 3 Kr |
| 4 | 1 Kr | 2 Kr |
| 5 | 1 Kr | 1 Kr |
| 6 | 1 Kr | 0 Kr |

1 TL ve 50 kuruş 48'den büyük olduğu için verilemez. 23 kuruşta 25 verilemez, 10 verilir. 3 kuruşta 5 de verilemez, üç tane 1 kuruş verilir. Strateji: "Her adımda kalan miktarı en az yapacak olan bozuk parayı ver." 48 tane 1 kuruş da verilebilirdi ama bu çok daha fazla para ve uğraş gerektirir; greedy yöntem en az sayıda parayı verir.

> **Ek bilgi (derste anlatılmadı):** Greedy para üstü yöntemi Türk lirası gibi "kanonik" para sistemlerinde en az sayıda parayı verir. Her para sisteminde böyle değildir: Örneğin 1, 3 ve 4 birimlik paralarla 6 birim için greedy 4+1+1 (üç para) verir, oysa 3+3 (iki para) daha iyidir.

### 4.4 Huffman kodlaması

Huffman kodlaması öncelikli kuyruk konusunda min priority queue örneği olarak veri sıkıştırma için görülmüştü. Frekanslar kuyruğa dizilir, her adımda en küçük frekanslı iki düğüm birleştirilip ara düğüm yapılır ve yeniden kuyruğa eklenir. Böylece az kullanılan karakterler ağacın en altında kalır ve en uzun kodları alır. Slayttaki örnekte beş karakter vardır: A, B, C, D ve boşluk. En sık kullanılan A'nın frekansı 0.35'tir. Hocanın anlatımına göre A, C ve D iki bitle (A=11, C=00, D=01), daha az kullanılan B ve boşluk üç bitle (100 ve 101) kodlanmıştır.
<!-- BELİRSİZ: Huffman slaytı karelerde yok. Frekanslar altyazıdan C ve D için 0.2, B ve boşluk için 0.1 ve 0.15 olarak anlaşılıyor; 100 ve 101 kodlarının B'ye mi boşluğa mı ait olduğu altyazıdan kesin değil. Python ile kurulan Huffman ağacı B=100, boşluk=101 veriyor. -->

## 5. Özyinelemeli Algoritmalar

### 5.1 Neden tekrar ediyoruz?

Arada verilen moladan sonra hoca özyinelemeli (recursive) algoritmalara döndü. Böl ve yönet yaklaşımında problem alt parçalara bölünürken neredeyse her zaman özyinelemeli çağrılar kullanılır. Bu yüzden konu başka derslerde görülmüş olsa da 15-20 dakika üzerinde durmak faydalıdır.

### 5.2 Tanım ve koşullar

Özyinelemeli algoritma, problemi çözmek için aynı çözüm yöntemini, yani kendini tekrar tekrar çağırarak çözüme ulaşan algoritmik tasarımdır. İki koşul gerekir:

- Problem aynı cinsten ama daha küçük bir örnekle ifade edilebilmelidir. Bu yapılamıyorsa özyinelemeli çözüm kurulamaz.
- Özyinelemeyi kesen bir karar mekanizması (durma noktası) olmalıdır. Aksi hâlde fonksiyon kendini sonsuza kadar çağırır. Durma noktasında elde edilen sonuçla çağrı ağacında geri dönülür; her dönüşte daha küçük problemin çözümü daha büyük probleme katkı sağlar.

### 5.3 Faktöriyel

$n!$, 1'den $n$'e kadar olan sayıların çarpımıdır: $n! = n\cdot(n-1)\cdot(n-2)\cdots 3\cdot 2\cdot 1$. Örneğin $5! = 5\cdot4\cdot3\cdot2\cdot1 = 120$. Bu bir döngüyle hesaplanabilir (ekrandan, 01:25:00):

```text
f = 1
for i: 1 to 5
    f *= i
```

Ama $5! = 5 \cdot 4!$ olduğu görülür. $4!$ hesaplanmışsa bütün çarpımları yeniden yapmaya gerek kalmaz. Aynı biçimde $4! = 4\cdot 3!$, $3! = 3\cdot 2!$, $2! = 2\cdot 1!$ ve $1! = 1$'dir. $1!$ bilindiğinde geriye doğru $2! = 2$, $3! = 6$, $4! = 24$, $5! = 120$ elde edilir; her adımda tek bir çarpma yapılır.

Tanım uzayına dikkat etmek gerekir. $0! = 0\cdot(-1)!$ yazılmaya çalışılırsa $(-1)!$ tanımlı olmadığı için sorun çıkar. Bu yüzden özyinelemeli tanım bir durma noktasıyla verilir:

$$n! = \begin{cases} n\cdot(n-1)! & n>1 \\ 1 & \text{aksi hâlde} \end{cases}$$

Slayttaki kod (ekrandan, 01:35:00):

```c
int fact(int n)
{
   if (n <= 1)
      return n;
   return n * fact(n - 1);
}
```

Slaytın altında `fact(0)` için 0, `fact(1)` için 1, `fact(2)` için `2*1`, `fact(10)` için `10*9*8*7*6*5*4*3*2*1` yazıyordu. Hoca derste `return n;` satırını `return 1;` olarak değiştirdi; böylece hem durma noktası temizlenmiş olur hem de negatif sayılarla sorun çıkmaz (ekrandan, 01:25:00).

> **Ders sonrası not:** Hoca "0 faktöriyel de 1 olarak tanımlıydı galiba" dedi. Doğrudur: $0! = 1$ tanım gereğidir. Bu yüzden `return 1;` biçimi `fact(0)` için de doğru sonucu verir; slayttaki `return n;` biçimi ise `fact(0)` için yanlış olarak 0 döndürür.

Çağrı yığıtı şöyle oluşur:

```text
fact(5) = 5 * fact(4)
          fact(4) = 4 * fact(3)
                    fact(3) = 3 * fact(2)
                              fact(2) = 2 * fact(1)
                                        fact(1) = 1   (n <= 1, özyineleme kesildi)
```

`fact(1)` 1 döndürünce `fact(2)` $2\cdot1=2$, `fact(3)` 6, `fact(4)` 24 ve `fact(5)` 120 döndürür. Durma noktasından sonrası, her çağrının sonucunu kendisini çağırana geri vermesinden ibarettir.

### 5.4 Fibonacci sayıları

Bir fonksiyon kendini birden fazla kez, hatta farklı parametrelerle çağırabilir. Bunun güzel örneği Fibonacci dizisidir: 1, 1 ile başlar ve her sayı kendinden önceki iki sayının toplamıdır: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... (ekrandan, 01:30:00). Yani $fib(n) = fib(n-1) + fib(n-2)$. Tanımın kendisi özyinelemelidir.

$fib(1) = fib(0) + fib(-1)$ tanımlı olmadığı için yine bir durma koşulu gerekir:

$$fib(n) = \begin{cases} fib(n-1)+fib(n-2) & n\ge 2 \\ 1 & \text{aksi hâlde} \end{cases}$$

```c
int fib (int n)
{
   if (n <= 1)
      return 1;
   return fib(n-1) + fib(n-2);
}
```

Hoca `F5` için çağrı ağacını yazdı: `F5 = F4 + F3`, `F4 = F3 + F2`, `F3 = F2 + F1`, `F2 = F1 + F0` ... Aynı alt çağrılar (örneğin `F2` ve `F3`) defalarca tekrar yapılır. Hoca çağrıları sayarak 17 buldu ve "yanlış saymadım değil mi, siz kontrol edin" dedi.

> **Ders sonrası not:** Bu tanımla ($n\le 1$ için doğrudan 1) `fib(5)` çağrısı toplam 15 fonksiyon çağrısı yapar: $C(n) = 1 + C(n-1) + C(n-2)$, $C(0)=C(1)=1$ bağıntısından $C(2)=3$, $C(3)=5$, $C(4)=9$, $C(5)=15$ bulunur (Python ile kontrol edildi). Hocanın saydığı 17 büyük olasılıkla tahtadaki çizimde bazı çağrıların iki kez sayılmasından kaynaklanıyor.

Kendini iki kez çağırmak zorunda olunca karmaşıklık doğrusaldan üstele çıkar.

## 6. Özyinelemeli Algoritmalarda Big-O

### 6.1 Faktöriyelin karmaşıklığı

Faktöriyel her seferinde kendini $n-1$ ile bir kez çağırır ve 1'e gelince durur. Toplam $n$ çarpım, yani $n$ çağrı yapılır. Bu yüzden karmaşıklığı $O(n)$'dir.

### 6.2 Fibonacci'nin karmaşıklığı

$n$ 0 ya da 1 iken tek bir işlem yapılır; $T(0)$ ve $T(1)$ sabit maliyettir. $n>1$ için iki çağrı ve bir toplama yapılır:

$$T(n) = T(n-1) + T(n-2) + c$$

Bu bağıntıyı en basit biçimde çözmek için üstten sınırlama yapılır. $T(n-1) \ge T(n-2)$ olduğu bilinir; en kötü durum olarak $T(n-2) \approx T(n-1)$ alınır. Ardından yerine koyma yöntemiyle açılır (ekrandan, 01:40:00):

$$\begin{aligned}
T(n) &= T(n-1) + T(n-2) + c \\
&= 2T(n-1) + c \quad \text{// } T(n-1)\sim T(n-2) \text{ yaklaşımı ile} \\
&= 2\,(2T(n-2) + c) + c \\
&= 4T(n-2) + 3c \\
&= 8T(n-3) + 7c \\
&= 2^k\, T(n-k) + (2^k-1)\,c
\end{aligned}$$

Her adımda katsayı ikinin bir üst kuvveti, $c$'nin katsayısı ise ikinin o kuvvetinden bir eksiğidir. $n-k=0$, yani $k=n$ alınırsa:

$$T(n) = 2^n\,T(0) + (2^n-1)\,c = 2^n(1+c) - c$$

$T(0)$ sabit maliyet 1 alınmıştır. Sabitler atılınca $T(n) \sim 2^n$ olur ve algoritmanın büyüme oranı $O(2^n)$'dir. Fonksiyon yalnız kendini iki kez çağırıp bir toplama yaptığı hâlde $O(n)$ yerine $O(2^n)$ maliyete çıkılır. Arada başka işlemler yapılsaydı karmaşıklık daha da yükselirdi.

Hoca, kendini üç kez çağıran bir fonksiyonda karmaşıklığın daha da hızlı büyüyeceğini söyledi.

> **Ders sonrası not:** Hoca üç çağrı için "2 üzeri n kare falan olacak" dedi. Aynı üstten sınırlama ($T(n)=T(n-1)+T(n-2)+T(n-3)+c \le 3T(n-1)+c$) ile sınır $O(3^n)$ olur, $2^{n^2}$ değil.

Fibonacci için 5, 10 hatta 100 sayı makul sürede hesaplanabilir; 100 bile çok kötüdür. 1000 ya da 10.000'e çıkıldığında $2^n$ mertebesinde beklemek gerekir ve yöntem mantıklı olmaktan çıkar.

### 6.3 Tekrarlanan alt ağaçlar

`fib(6)` için çağrı ağacı çizildiğinde aynı alt ağaçların tekrar tekrar hesaplandığı görülür (ekrandan, 01:45:00). `fib(6)`, `fib(4)` ve `fib(5)`'i çağırır; `fib(5)` de yine `fib(4)` ve `fib(3)`'ü çağırır. Yani `fib(4)` alt ağacının tamamı iki kez, `fib(3)` alt ağacı üç kez hesaplanır. Hoca şöyle dedi: "Aynı bloğu aslında 3 kere boşu boşuna tekrar tekrar çağırmışım." Bu yüzden düz özyinelemeli çözüm Fibonacci için iyi bir yöntem değildir. Faktöriyelde ise problem her adımda bir küçültülür ve hiçbir alt problem tekrar edilmez.

> **Ek bilgi (derste anlatılmadı):** Tekrarlanan alt problemler, hesaplanan değerler bir tabloda saklanarak (memoization) ya da döngüyle aşağıdan yukarı hesaplanarak önlenebilir. Bu durumda Fibonacci $O(n)$ zamanda hesaplanır. Bu yaklaşıma dinamik programlama denir.

## 7. Algoritmik Çözüm Yaklaşımları

Böl ve yönete geçmeden önce şimdiye kadar görülen yaklaşımlar özetlendi (ekrandan, 01:50:00):

- Kaba kuvvet (brute force): Başlangıçtan dümdüz ilerleyerek, hiçbir özel şeye bakmadan her adımda sabit bir işlem yapıp çözüme gitmek.
  - Üs alma: $a^n = a\cdot a\cdots a$ ($n$ kere çarpma).
  - Selection sort: Her adımda kalan dizinin en küçüğünü bulup kalanın başına koymak, sonra diziyi bir küçültmek; tek eleman kalana kadar.
  - Bubble sort: Komşu büyük ve küçük elemanları yer değiştirerek büyüklerin kabarcık gibi sona taşınmasını sağlamak.
  - Hoca şifre kırmada bütün harf kombinasyonlarını tek tek denemeyi de örnek verdi.
- Açgözlü (greedy): Her adımda o an için en iyi olan çözümü (local optimum) uygulamak.
  - Para üstü: Her adımda verilebilecek en büyük parayı ver; kalan en aza iner, toplamda en az sayıda para verilir.
  - Huffman kodlaması: Her adımda en küçük frekanslı iki karakteri birleştirip ara düğüm oluştur ve kuyruğa geri ekle. Kuyrukta dinamik değişen bir mekanizma olduğu için kaba kuvvet değil, greedy sayılır.
- Azalt ve yönet (decrease and conquer): Problem uzayını adım adım küçülterek çözüme ilerlemek. Bazı kaynaklar bunu ayrı bir yaklaşım olarak verir.
  - Üs alma: $a^n = a^{n-1}\cdot a$. Bir önceki değer biliniyorsa tek bir çarpma yeter.
  - Insertion sort: Kart dizer gibi, elemanı gidebileceği yere kadar kaydırarak araya yerleştirmek; arama uzayı giderek daralır.
  - Josephus problemi (dairesel bağlı liste): Her iterasyonda bir kişi elenir, problem bir küçülür.

## 8. Böl ve Yönet (Divide and Conquer)

### 8.1 Tanım

İngilizcesi "divide and conquer"dır; Türkçeye tam karşılığı "böl ve fethet" olsa da "böl ve yönet" kullanılır. Hoca yöntemi, büyük ve yönetmesi zor bir bütünü küçük parçalara bölüp her parçayı ayrı yöneterek toplam hakimiyeti sürdürme politikasına benzetti. Elde örneğin sıralanacak bir dizi varsa, dizi daha küçük dizilere bölünür, küçük diziler daha kolay sıralanır, sonra hepsi tek bir dizi hâlinde birleştirilir.

Yöntemin adımları (ekrandan, 01:55:00):

- Problem (genellikle eşit boyutlu) aynı tipte küçük problemlere ayrıştırılır. Hoca alt problemlerin eşit boyutlu olmak zorunda olmadığını, bunu ileride göreceklerini söyledi.
- Alt problemler çözülür:
  - Genellikle özyinelemeli olarak daha küçük problemler hâline getirilir.
  - Bölünemeyecek kadar küçük problem bir yöntemle çözülür.
- Gerektiğinde alt problemlerin çözümleri bir araya getirilerek orijinal probleme ait nihai çözüm oluşturulur. Bu "yönet" (conquer) aşamasıdır.

### 8.2 Her zaman daha verimli değildir, ama paralelleşebilir

Böl ve yönet her zaman kaba kuvvetten daha verimli olmak zorunda değildir. Ama kolayca paralel hesaplama ile gerçekleştirilebilir. Hoca 40.000 elemanlı bir dizi örneği verdi: Dört çekirdekli bir işlemcinin tek çekirdeğinde heap sort ile sıralama $n\log n$ maliyetindedir. Dizi dört parçaya bölünüp her çekirdeğe 10.000 eleman verilirse her çekirdek $10.000\cdot\log 10.000$ kadar iş yapar. Üzerine yalnız birleştirme (conquer) aşaması eklenir.

> **Ders sonrası not:** Hoca tek çekirdekli maliyeti "40.000 çarpı 40.000 şeklinde", paralel maliyeti "$n\log n$ bölü 4 artı C" diye söyledi. Doğrusu: tek çekirdekte yaklaşık $40.000\cdot\log 40.000$; dört çekirdekte paralel kısım $\frac{n}{4}\log\frac{n}{4}$, birleştirme ise sabit değil $n$ ile orantılı (bu yöntemle büyük olasılıkla $O(n)$) bir ek yüktür.

Paralelleştirme yapılabiliyorsa ve küçük uzaylar toplam zamanı azaltıyorsa böl ve yönetten kazanç elde edilir. Tek işlemcide paralelleştirmeden yapılıyorsa her zaman daha verimli olmayabilir. Gücü, küçük parçaları farklı işlemcilerde ya da çekirdeklerde aynı anda çözebilmekten gelir.

Diyagram olarak: $n$ boyutlu problem iki işlemci varsa iki tane $n/2$ boyutlu probleme "karpuz gibi ortadan" bölünür. Her yarı ayrı işlemcide aynı anda sıralanırsa sıralama süresi yarıya iner. Sonra birleştirme yapılır; bu adım bir ek yüktür (overhead) ve unutulmamalıdır. 8 çekirdek varsa 8 parçaya bölünerek $n/8$ mertebesindeki sürelere inilebilir.

## 9. Top-Down Merge Sort

### 9.1 Fikir

Merge sort da bir sıralama algoritmasıdır. $A[0..n-1]$ dizisi böl ve yönet ile şöyle sıralanır (ekrandan, 02:00:00):

- Diziyi ikiye böl, her parçayı kendi içinde sırala; bunun için parçaları özyinelemeli olarak ikiye bölmeye devam et (Algorithm MergeSort).
- Tek elemanlık parçalar zaten sıralıdır.
- Sonra her sıralı alt parçayı sıralı olarak birleştir; parçalar birleştikçe onları da sıralı olarak birleştir (Algorithm Merge).

Hoca bunu `3 5 2 1 8 4 6 9` dizisiyle gösterdi:

```text
3 5 2 1 8 4 6 9
3 5 2 1 | 8 4 6 9
3 5 | 2 1 | 8 4 | 6 9
3 | 5 | 2 | 1 | 8 | 4 | 6 | 9        (tek elemanlı parçalar: zaten sıralı)
3 5 | 1 2 | 4 8 | 6 9                (ikililer birleşti)
1 2 3 5 | 4 6 8 9                    (dörtlüler birleşti)
1 2 3 4 5 6 8 9                      (sonuç)
```

Bölme tarafında yapılacak hiçbir iş yoktur; yalnız özyinelemeli olarak bölmeye devam edilir. Asıl dert birleştirme (conquer) aşamasıdır: Sıralı alt parçaları sırayı bozmadan birleştirmek gerekir. Örneğin `2` ve `1` birleşirken `1 2` sırası garanti edilmeli, `8` ve `4` birleşirken `4 8` elde edilmelidir. Dörtlüler birleşirken iki taraftan sırayla `1, 2, 3` (soldan), `4` (sağdan), `5` (soldan), sonra kalanlar `6, 8, 9` alınır. Yani iki ayrı işlem gerekir: bir eleman kalana kadar bölmek ve sırayı gözeterek birleştirmek.

Merge sort'un iki çeşidi vardır: top-down ve bottom-up. Bu derste top-down merge sort işlendi; bottom-up sonraki derse kaldı.

### 9.2 Akış diyagramı

Her çağrıda farklı bir parça işlendiği için fonksiyon başlangıç (`lo`) ve son (`hi`) indislerini parametre olarak alır. İlk çağrı 8 elemanlı dizi için `lo=0`, `hi=7` ile yapılır. Akış diyagramı (ekrandan, 02:10:00):

```text
MergeSort(A, lo, hi)
  lo < hi ?
    Hayır -> Stop
    Evet  -> mid <- lo + (hi - lo)/2
             MergeSort(A, lo, mid)
             MergeSort(A, mid+1, hi)
             Merge(A, lo, mid, hi)
             Stop
```

Durma kontrolü `lo < hi`'dir. İndisler birbirine eşit olduğunda (tek eleman kaldığında) ya da ters geçtiğinde artık bölünemez ve birleştirilecek bir şey yoktur. Bölme noktası `mid = lo + (hi - lo)/2`'dir; hoca bunu `(lo + hi)/2` ile aynı anlamda, daha açık olsun diye böyle yazdığını söyledi.

Hoca 0-7 indisli dizi üzerinde bölmeleri renklerle gösterdi (ekrandan, 02:20:00): ilk bölme turuncu (0-3 | 4-7), ikinci seviye kırmızı (0-1 | 2-3 ve 4-5 | 6-7), en alt seviye mavi. Çağrı sırası şöyledir: Önce sol yarı için `MergeSort(A, lo, mid)` çağrılır; onun içinde yine sol yarıya inilir; tek göze düşülünce daha fazla bölünemez ve bir üst çağrıya dönülür. Bu kez `MergeSort(A, mid+1, hi)` sağ yarıyı işler. İki çağrı da bitince `Merge` çalışır. Yani her seferinde "sol tarafı merge sort'a gönder, sağ tarafı merge sort'a gönder, sonra birleştir" yapılır.

Paralel bir mimaride iki `MergeSort` çağrısı aynı anda çalıştırılıp ardından birleştirme yapılabilir.

**Soru:** En üstteki birleştirmede iki taraf ayrı ayrı sıralı, ama elemanların iç içe geçmesi gerekiyor. Bunun maliyeti nedir?
**Cevap:** Hoca birleştirme işlemini göstereceğini söyledi; $n$ eleman ikiye bölündüğü için toplamda $n\log n$ mertebesinde bir maliyet olacağını, ayrıntılı analizi ilerleyen derste yapacaklarını belirtti.

## 10. Merge İşlemi

### 10.1 Yardımcı dizi ve akış

Bölmek kolaydır: "Bıçağı al, ortadan ikiye böl." Asıl iş birleştirmedir. Merge sort'un bir ihtiyacı vardır: Sıralanacak dizi kadar harici (auxiliary) bir alan. Küçük-büyük karşılaştırmasıyla birleştirme yaparken elemanların izini sürebilmek ve bir yere yazabilmek için dizi önce olduğu gibi `Aux` dizisine kopyalanır.

Merge akış diyagramı (ekrandan, 02:25:00):

```text
Merge(A, lo, mid, hi)
  i <- lo
  j <- mid + 1
  for k <- lo to hi:
      Aux[k] <- A[k]
  for k <- lo to hi:
      if i > mid:              A[k] <- Aux[j];  j <- j + 1
      else if j > hi:          A[k] <- Aux[i];  i <- i + 1
      else if Aux[j] < Aux[i]: A[k] <- A[j];    j <- j + 1
      else:                    A[k] <- Aux[i];  i <- i + 1
  Stop
```

Dört durum vardır:

- `i > mid`: Sol parça bitmiştir; sağ parçadan eleman alınır.
- `j > hi`: Sağ parça bitmiştir; sol parçadan eleman alınır.
- `Aux[j] < Aux[i]`: Sağdaki eleman küçüktür; o yazılır ve `j` artırılır.
- Aksi hâlde soldaki eleman yazılır ve `i` artırılır. Eşitlikte de soldan alınır.

Her adımda hangi koldan eleman alındıysa o kolun indisi bir artırılır.

> **Ders sonrası not:** Akış diyagramındaki üçüncü dalda `A[k] <- A[j]` yazılı; bu dalda `Aux[j]` yazmak daha açıktır. Sonuç değişmez, çünkü bu dalda her zaman $k < j$ olduğundan `A[j]` henüz üzerine yazılmamıştır ve `Aux[j]` ile aynıdır (Python ile üç örnekte kontrol edildi).

### 10.2 Merge izleme örneği

İki yarısı kendi içinde sıralanmış `E E G M R | A C E R T` dizisi birleştirilir (ekrandan, 02:30:00). Dizi önce `aux`'a kopyalanır. Başta `i=0`, `j=5`'tir.

| k | i | j | Karşılaştırma | Yazılan | Çıktı |
|---|---|---|---|---|---|
| 0 | 0 | 5 | A < E | A (sağ) | A |
| 1 | 0 | 6 | C < E | C (sağ) | A C |
| 2 | 0 | 7 | E = E | E (sol) | A C E |
| 3 | 1 | 7 | E = E | E (sol) | A C E E |
| 4 | 2 | 7 | E < G | E (sağ) | A C E E E |
| 5 | 2 | 8 | G < R | G (sol) | A C E E E G |
| 6 | 3 | 8 | M < R | M (sol) | A C E E E G M |
| 7 | 4 | 8 | R = R | R (sol) | A C E E E G M R |
| 8 | 5 | 8 | sol bitti (i > mid) | R (sağ) | A C E E E G M R R |
| 9 | 5 | 9 | sol bitti | T (sağ) | A C E E E G M R R T |

Eşitlik durumunda soldaki parçadan alınır. `k=7`'den sonra `i` mid'i geçer; artık sol tarafa bakılmaz, sağdaki kalanlar (`R`, `T`) olduğu gibi kopyalanır. Tersi de olabilirdi: Sağ taraf önce biterse soldaki kalanlar kopyalanırdı. Sonuç `A C E E E G M R R T`'dir.

### 10.3 Sözde kod hâli

Hoca, merge sort'un ve merge'ün sözde kod hâllerini de slaytta verdiğini söyledi. MergeSort'ta $n>1$ ise $A$'nın bir yarısı $B$'ye, diğer yarısı $C$'ye kopyalanır, $B$ ve $C$ için MergeSort çağrılır ve `Merge(B, C, A)` ile birleştirilir. Merge'te `i < p` ve `j < q` olduğu sürece $B$ ve $C$'nin baştaki elemanları karşılaştırılır; küçük olan çıktıya yazılır ve o tarafın indisi ile çıktının indisi `k` artırılır. Döngü bitince hangi taraf tükendiyse diğer tarafın kalanı olduğu gibi kopyalanır. Hoca, merge'ün tek bir uygulaması olmadığını, varyasyonlar yaratılabileceğini; yapılan işin karşılaştırmak, küçük olanı çıktıya yazmak ve bir taraf tükenince diğerini kopyalamak olduğunu vurguladı.
<!-- BELİRSİZ: Merge sort ve merge sözde kodlarının bulunduğu slayt karelerde yok; yukarıdaki anlatım altyazıdan kuruldu, kodun satırları birebir aktarılamadı. -->

## 11. Merge Sort Örnekleri

### 11.1 Örnek 1: Sayı dizisi

Dizi: `8 3 2 9 7 1 5 4` (ekrandan, 02:35:00). Önce `lo`, `mid` ve `hi` bulunur ve dizi ikiye bölünür: `8 3 2 9 | 7 1 5 4`. Bölmeler sırayla dokuz adımda yapılır ve sonunda tek elemanlı parçalar elde edilir. Ardından birleştirme şu sırayla yürür:

1. `8` ile `3`: Sağdaki küçük, `3` yazılır; sağda eleman kalmadığı için soldaki `8` kopyalanır → `3 8`.
2. `2` ile `9`: Soldaki küçük, `2` yazılır; sağdaki `9` kopyalanır → `2 9`.
3. `3 8` ile `2 9`: `2` (sağ), `3` (sol), `8` (sol); sol bitti, `9` kopyalanır → `2 3 8 9`.
4. `7` ile `1` → `1 7`.
5. `5` ile `4` → `4 5`.
6. `1 7` ile `4 5`: `1` (sol), `4` (sağ), `5` (sağ); sağ bitti, `7` kopyalanır → `1 4 5 7`.
7. `2 3 8 9` ile `1 4 5 7`: `1` (sağ), `2` (sol, 2 ile 4), `3` (sol, 3 ile 4), `4` (sağ, 8 ile 4), `5` (sağ, 5 ile 8), `7` (sağ, 7 ile 8); sağ bitti, `8` ve `9` kopyalanır → `1 2 3 4 5 7 8 9`.

```text
            8 3 2 9 7 1 5 4
        8 3 2 9         7 1 5 4
      8 3     2 9     7 1     5 4
     8   3   2   9   7   1   5   4
      3 8     2 9     1 7     4 5
        2 3 8 9         1 4 5 7
            1 2 3 4 5 7 8 9
```

Bölme aşamasında hiçbir iş yapılmaz; yalnız `mid` hesaplanıp `mid`'den aşağısı ilk `MergeSort`'a, `mid+1`'den `hi`'ye kadar olanlar ikinci `MergeSort`'a gönderilir. `lo` ile `hi` aynı göze düşene, yani tek eleman kalana kadar bu sürer. Asıl iş birleştirmededir: Ek bir diziye kopyalanır, küçük olan çıktıya yazılır, indisler artırılır, bir taraf bitince kalanlar olduğu gibi kopyalanır.

### 11.2 Örnek 2: MERGESORTEXAMPLE

16 karakterlik dizi: `M E R G E S O R T E X A M P L E` (indis 0-15) (ekrandan, 02:45:00). Önce sol sekizli (0-7), onun içinde sol dörtlü, onun içinde sol ikili işlenir; yani "sol, sol, sol, sonra sağ, sonra birleştir" sırası izlenir.

| Adım | Birleştirilen aralık | Sonuç |
|---|---|---|
| 1 | M \| E | E M |
| 2 | R \| G | G R |
| 3 | E M \| G R | E G M R |
| 4 | E \| S | E S |
| 5 | O \| R | O R |
| 6 | E S \| O R | E O R S |
| 7 | E G M R \| E O R S | E E G M O R R S |
| 8 | T \| E | E T |
| 9 | X \| A | A X |
| 10 | E T \| A X | A E T X |
| 11 | M \| P | M P |
| 12 | L \| E | E L |
| 13 | M P \| E L | E L M P |
| 14 | A E T X \| E L M P | A E E L M P T X |
| 15 | E E G M O R R S \| A E E L M P T X | A E E E E G L M M O P R R S T X |

Birkaç birleştirmenin ayrıntısı:

- 3. adım: E ile G → E; M ile G → G; M ile R → M; sol bitti, R kopyalanır.
- 6. adım: E ile O → E; S ile O → O; S ile R → R; sağ bitti, S kopyalanır.
- 7. adım: E ile E → E (sol); G ile E → E; G ile O → G; M ile O → M; R ile O → O; R ile R → R; sol bitti, R ve S kopyalanır. Sol sekizli ilk 7 birleştirmede tamamlanır.
- 14. adım: A ile E → A; E ile E → E; T ile E → E; T ile L → L; T ile M → M; T ile P → P; sağ bitti, T ve X kopyalanır.
- 15. adım: Önce A, sonra dört tane E, ardından G, L, M, M, O, P, R, R, S yazılır; sol bittiği için kalan T ve X kopyalanır.

Sonuç: `A E E E E G L M M O P R R S T X`. Bütün sonuçlar Python ile aynı akış diyagramı kullanılarak kontrol edildi.

## Örnek Sorular

1. (ekrandan, 00:20:00) Kenarları `r–s, r–v, s–w, w–t, w–x, t–x, t–u, x–u, x–y, u–y` olan yönsüz grafta `s`'den başlayan renkli BFS'te her düğümün uzaklığı ve parent'ı nedir?

> **Çözüm (derste verildi):** Uzaklıklar `s=0, w=1, r=1, t=2, x=2, v=2, u=3, y=3`; parent'lar `w←s, r←s, t←w, x←w, v←r, u←t, y←x`. Kuyruktan çekilme sırası `s, w, r, t, x, v, u, y`.

2. (ekrandan, 00:35:00) Kenarları `u→v, u→x, x→v, v→y, y→x, w→y, w→z, z→z` olan yönlü grafta `u`'dan başlayan renkli DFS'te keşif ve bitiş zamanları nedir?

> **Çözüm (derste verildi):** `u 1/8, v 2/7, y 3/6, x 4/5`; dış döngü `w`'dan yeniden başlar: `w 9/12, z 10/11`.

3. (ekrandan, 00:45:00) Komşuluk listesi `0: 2 1 5`, `1: 0 2`, `2: 0 1 3 4`, `3: 5 4 2`, `4: 3 2`, `5: 3 0` olan yönsüz grafta `dfs(0)` için d, f ve önceki düğüm (Pre) değerleri nedir?

> **Çözüm (derste verildi):** `0: 1/12, –`; `1: 3/4, 2`; `2: 2/11, 0`; `3: 5/10, 2`; `4: 8/9, 3`; `5: 6/7, 3`.

4. (ekrandan, 01:00:00) Bozuk paralar 1 TL, 50, 25, 10, 5 ve 1 kuruş iken 48 kuruş para üstü greedy yöntemle nasıl verilir?

> **Çözüm (derste verildi):** 25 (23 kaldı), 10 (13 kaldı), 10 (3 kaldı), 1, 1, 1. Toplam 6 para.

5. (derste sözlü, 01:31:01) Yukarıdaki `fib` fonksiyonu `fib(5)` için toplam kaç kez çağrılır?

> **Çözüm (derste verilmedi):** Hoca 17 saydı ve kontrol edilmesini istedi. $C(n)=1+C(n-1)+C(n-2)$, $C(0)=C(1)=1$ ile $C(5)=15$ çağrı yapılır (Python ile kontrol edildi).

6. (ekrandan, 02:30:00) Kendi içinde sıralı `E E G M R` ve `A C E R T` yarıları merge ile birleştirildiğinde her adımda hangi eleman yazılır?

> **Çözüm (derste verildi):** A, C, E (sol), E (sol), E (sağ), G, M, R (sol), R, T. Sonuç `A C E E E G M R R T`.

7. (ekrandan, 02:35:00) `8 3 2 9 7 1 5 4` dizisini top-down merge sort ile sıralayın.

> **Çözüm (derste verildi):** `3 8`, `2 9` → `2 3 8 9`; `1 7`, `4 5` → `1 4 5 7`; sonuç `1 2 3 4 5 7 8 9`.

8. (ekrandan, 02:45:00) `MERGESORTEXAMPLE` dizisini top-down merge sort ile sıralayın.

> **Çözüm (derste verildi):** Sol yarı `E E G M O R R S`, sağ yarı `A E E L M P T X`; sonuç `A E E E E G L M M O P R R S T X`.

## Dersin Toparlaması

Bu derste önce graf gezintileri renk kodlamasıyla geliştirildi. Renkli BFS'te düğümler beyaz, gri ve siyah ile işaretlenip uzaklık ve parent tutuldu; böylece hem yalnız gezilmemiş düğümlere bakılarak gereksiz kontroller azaldı hem de başlangıçtan her düğüme giden yol izlenebilir hâle geldi. Renkli DFS'te ek olarak keşif ve bitiş zamanları tutuldu ve dış döngü sayesinde erişilemeyen düğümler de gezildi. Ardından açgözlü yaklaşım para üstü ve Huffman örnekleriyle tanıtıldı, özyinelemenin koşulları faktöriyel ve Fibonacci ile hatırlatıldı ve kendini iki kez çağıran bir fonksiyonun maliyetinin $O(2^n)$'e çıktığı yerine koyma yöntemiyle gösterildi.

Dersin ikinci yarısında kaba kuvvet, greedy ve azalt-yönet yaklaşımları karşılaştırılarak böl ve yönet tanımlandı. Bu yöntemin gücünün paralelleştirmeden geldiği vurgulandı ve top-down merge sort akış diyagramı, merge işlemi ve üç örnekle adım adım izlendi. Sonraki derste merge sort'un karmaşıklık analizi, bottom-up merge sort ve dizinin eşit parçalara değil eleman değerlerine göre bölündüğü bir böl ve yönet örneğiyle konunun tamamlanacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
