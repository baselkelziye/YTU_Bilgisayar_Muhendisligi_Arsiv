# Ders 19 Çalışma Özeti

## Genel Konular

- Graf (çizge) veri yapısının tanımı
  - Graf, birbirine bağlı elemanlar kümesidir. $G=(V,E)$ biçiminde gösterilir: $V$ düğümler (vertex), $E$ kenarlar (edge) kümesidir. $|V|$ ve $|E|$ düğüm ve kenar sayısıdır.
  - Ağaç, grafın özel bir hâlidir.
  - Graf algoritmalarının karmaşıklığı tek bir $n$ yerine $V$ ve $E$ cinsinden yazılır (örneğin $O(V+E)$, $O(E \log V)$).
- Grafların kullanım alanları
  - Raylı sistem haritası (duraklar düğüm, raylar kenar), eyalet ya da il sınır komşulukları, protein-protein etkileşim ağları, bilim alanları arasındaki ortak geçiş ağları, sosyal ağlardaki arkadaşlık ve takip bağlantıları.
  - Haritalarda en kısa yol (shortest path), ağlarda en yüksek akış (max flow), web bağlantıları ve arama motorları, baskı devre (PCB) yerleşimi, iş zamanlaması (PERT), alıcı-satıcı-ürün ağları, eşleştirme problemleri, paket yönlendirme (routing), derleyicide modül çağrıları, sosyal ağlarda kanaat önderi, anomali ve bot ağı tespiti.
- Graf terminolojisi
  - Yol (path): kenarlarla bağlanmış düğümler silsilesi. Uzunluğu geçilen kenar sayısıdır. İki düğüm arasında farklı uzunlukta birden fazla yol olabilir.
  - Çevrim (cycle): ilk ve son düğümü aynı olan yol.
  - Bağlı (connected): iki düğüm arasında yol varsa bu iki düğüm birbirine bağlıdır. Aralarında bağlantı olmayan parçalar ayrı bağlı bileşenlerdir (connected component). İki bileşen bir kenarla birleşince bileşen sayısı bir azalır.
- Graf tipleri
  - Yönsüz graf: bağlantı iki yönlüdür (arkadaşlık gibi).
  - Yönlü graf (digraph): kenarın bir kaynağı ve hedefi vardır (takip etme gibi).
  - Her ikisinde de kenar ağırlığı tanımlanabilir: ağırlıksız/ağırlıklı, yönlü/yönsüz olmak üzere dört tip.
  - Slaytta kendine dönen kenar (self-loop) ve paralel kenarlar da gösterildi.
- Çevrimsiz graf ve ağaç
  - Çevrimsiz (acyclic) graf kapalı döngü içermez. Her çevrimsiz graf ağaç değildir.
  - Slayttaki beş koşul: $V-1$ kenar var ve döngü yok; $V-1$ kenar var ve bileşenler bağlı; herhangi bir kenarı kaldırmak ağacı keser; çevrimsizdir ve bir kenar eklemek çevrim oluşturur; her düğüm çiftini tek bir basit yol bağlar.
- Graf gösterimleri
  - Komşuluk listesi (adjacency list): düğümler bir dizide, her düğümün komşuları bağlı listede tutulur. Seyrek (sparse) graflar için uygundur.
  - Komşuluk matrisi (adjacency matrix): $V^2$ yer kaplar; $A_{ij}=1$ eğer $(i,j)\in E$, değilse 0. Yönsüz grafta $A^T=A$ olduğu için yarısını tutmak yeter; elemanlar 1 bit ile tutulabilir.
  - Yönlü grafta $A^T \neq A$, matrisin tamamı tutulmalıdır.
  - Ağırlıklı grafta matriste 1 yerine ağırlık değerleri, listede her düğüm yapısında ek bir ağırlık alanı yer alır.
  - Bağlantı var mı sorusu: listede $O(\text{degree}(v))$, matriste $O(1)$.
- Önce genişlemesine arama (BFS)
  - Kaynak $s$'den ulaşılabilen tüm düğümleri keşfeder; $k+1$ uzaklığa geçmeden önce $k$ uzaklıktaki tüm düğümleri bulur. FIFO kuyruk kullanır.
  - Uzaklıklar başta $\infty$, $d[s]=0$; kuyruktan çekilen $u$'nun $d[v]=\infty$ olan her komşusuna $d[v]=d[u]+1$ yazılır ve $v$ kuyruğa eklenir.
  - Karmaşıklık: $O(V+E)$ (artı ilklendirme $O(V)$); komşuluk listesiyle lineer zamanda çalışır.
- Önce derinlemesine arama (DFS)
  - Minotor ve labirent hikâyesindeki ip yumağı benzetmesiyle anlatıldı (Trémaux keşfi).
  - Düğümü işaretle, işaretsiz tüm komşularını özyinelemeli ziyaret et. `marked[]` dizisi kullanılır.
  - DFS ile tek kaynaktan nerelere gidilebileceği ve iki düğüm arasında yol olup olmadığı çözülür. `edgeTo[]` dizisi tutularak yol, yığıtla tersten çıkarılır.
- Minimum yayılımlı ağaç (minimum spanning tree, MST)
  - Muhtar örneği: köydeki tüm evleri en az toplam yol maliyetiyle birbirine bağlamak.
  - Yönsüz $G=(V,E)$, her kenar için $w(u,v)$; tüm düğümleri bağlayan ve $w(T)=\sum_{(u,v)\in T} w(u,v)$ değeri en küçük olan $T \subseteq E$ ağacı.
  - Aynı toplam ağırlıkta birden fazla MST olabilir.
  - Genel (generic) MST: boş kümeden başla, her adımda güvenli (safe) bir kenar ekle, $V-1$ kenar olunca dur. Bu açgözlü (greedy) bir yöntemdir.
  - Kesim (cut): $S$ ve $V-S$; kesimler arasında bağlantıyı hafifleten kenar güvenlidir.
- Kruskal algoritması
  - Her düğüm ayrı bir bileşen (ayrık küme) olarak başlar; kenarlar ağırlığa göre artan sırada taranır; iki farklı bileşeni bağlayan kenar eklenir, çevrim oluşturan atlanır.
  - Karmaşıklık: $O(E \log V)$.
- Prim algoritması
  - Keyfi bir $r$ kökünden başlar ve her zaman tek bir ağaç tutar. Her adımda $(V_A, V-V_A)$ kesimindeki en hafif kenarı öncelikli kuyruk (EXTRACT-MIN) ile bulup ağaca ekler.
  - İkili yığınla $O(E \log V)$; Fibonacci yığınıyla $O(V \log V + E)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağaç, grafın özel bir hâlidir ama her çevrimsiz graf ağaç değildir.
  - Örnekteki yönlü çevrimsiz grafta 7 düğüm ve 8 kenar olduğu için $V-1$ koşulu bozulur, bu yüzden ağaç değildir.
- Yönsüz grafta komşuluk matrisi simetriktir, yönlü grafta değildir.
  - Yönlü grafta matrisin yarısını tutma iyileştirmesi yapılamaz; $V^2$ yer gerekir.
- Matris ile liste arasındaki temel fark yer-zaman takasıdır.
  - Matris yer karmaşıklığını artırır ama bağlantı sorgusunu $O(1)$ yapar. Liste yerden kazandırır ama sorgu düğüm derecesi kadar sürer.
- BFS ve DFS'i hoca "bilmeniz için" hızlıca anlattığını, asıl önemli konunun MST oluşturmak olduğunu söyledi.
- MST'de en kritik nokta çevrim oluşturmamaktır.
  - Çevrim oluşturan kenar "güvenli değil"dir; gereksiz asfalt dökmek demektir.
- Kruskal kenar kenar ilerler ve ara adımlarda birden fazla bileşen (orman) olabilir; Prim her an tek bir ağaca sahiptir.
- MST, iki düğüm arasındaki en kısa yolu vermez.
  - MST toplam maliyeti en küçük yapar; tek bir düğüm çifti arasındaki yol MST'de daha uzun olabilir.
- Grafa yeni bir düğüm eklenirse MST baştan oluşturulmalıdır.

## Kısa Tekrar Notları

- $G=(V,E)$; karmaşıklık $V$ ve $E$ cinsinden yazılır.
- Yol, çevrim, bağlı, bağlı bileşen kavramları.
- Dört graf tipi: yönsüz, yönlü, ağırlıklı yönsüz, ağırlıklı yönlü.
- Ağaç: $V-1$ kenar, bağlı, çevrimsiz; bir kenar eklemek çevrim yaratır, bir kenar silmek ağacı ikiye böler; her düğüm çifti arasında tek yol.
- Komşuluk listesi seyrek graf için; komşuluk matrisi $V^2$ yer, $O(1)$ sorgu.
- Yönsüz grafta $A^T=A$, yönlü grafta $A^T \neq A$.
- BFS: kuyruk, katman katman ilerler, $O(V+E)$, ağırlıksız grafta kaynaktan en kısa yol uzunluklarını verir.
- DFS: özyineleme, `marked[]`, `edgeTo[]`; yol bulma için yığıt.
- MST: $V-1$ kenar, çevrimsiz, toplam ağırlık en küçük; açgözlü yöntem.
- Kruskal: kenarları sırala, ayrık kümelerle çevrim denetle, $O(E \log V)$.
- Prim: kökten başla, öncelikli kuyruktan EXTRACT-MIN, $O(E \log V)$ (Fibonacci yığınıyla $O(V \log V + E)$).
- Örnek grafta Kruskal ve Prim'in bulduğu MST'lerin toplam ağırlığı 37'dir.

## Detaylı Açıklamalar

- **Graf ve gösterim.** Graf, düğümler ve onları bağlayan kenarlardan oluşur. Slayttaki 5 düğümlü yönsüz örnekte 1'in komşuları 2 ve 5, 2'nin komşuları 1, 5, 3, 4, 3'ün komşuları 2 ve 4, 4'ün komşuları 2, 5, 3, 5'in komşuları 4, 1, 2'dir (ekrandan, 00:45:00). Komşuluk listesinde komşuların sırası önemli değildir. Matris gösteriminde 1. satır `0 1 0 0 1`, 2. satır `1 0 1 1 1` olur ve matris köşegene göre simetriktir. Slayttaki 6 düğümlü yönlü örnekte listeler 1: 2, 4; 2: 5; 3: 6, 5; 4: 2; 5: 4; 6: 6 biçimindedir; 6 kendine bağlıdır (ekrandan, 00:50:00). Burada $A[1][2]=1$ ama $A[2][1]=0$ olduğu için matris simetrik değildir.
- **Ağırlıklı gösterim.** Ağırlıklı grafta matris hücresine ağırlık yazılır. Komşuluk listesinde her düğüm `struct`'ına bir `weight` alanı eklenir; örneğin 1'den 2'ye ağırlık 5, 1'den 4'e ağırlık 3.
- **BFS.** Slayttaki sözde kod (ekrandan, 01:10:00):

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

  - Örnek yönlü grafta (kenarlar: s→a, s→c, a→e, c→e, c→g, e→b, e→h, b→a, g→f, g→h, g→i, h→g, f→c, i→h) kaynak $s$'den bulunan uzaklıklar: $a=1$, $c=1$, $e=2$, $g=2$, $b=3$, $h=3$, $f=3$, $i=3$ (ekrandan, 01:15:00). Kuyruktan çıkış sırası s, a, c, e, g, b, h, f, i'dir.
  - Ebeveynler (parent) da tutulursa rota bulunur; örneğin $s$'den $h$'ye BFS ağacındaki yol s → a → e → h'dir.
  - Her düğüm en fazla bir kez kuyruğa girer ($O(V)$), her kenar en fazla bir kez denetlenir ($O(E)$); toplam $O(V+E)$ (ekrandan, 01:20:00).
- **DFS.** Sözde kod (ekrandan, 01:30:00):

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

  - Komşuluk listesi 0: 2, 1, 5; 1: 0, 2; 2: 0, 1, 3, 4; 3: 5, 4, 2; 4: 3, 2; 5: 3, 0 olan grafta 0'dan başlayan DFS'in ziyaret sırası 0, 2, 1, 3, 5, 4'tür (ekrandan, 01:35:00).
  - `edgeTo[]`: 1←2, 2←0, 3←2, 4←3, 5←3. Bu bir ağaçtır: 0'ın çocuğu 2; 2'nin çocukları 1 ve 3; 3'ün çocukları 4 ve 5 (ekrandan, 01:40:00).
  - `pathTo(5)`: 5'ten başlayıp `edgeTo` ile geri gidilir (5, 3, 2), sonra kaynak 0 yığıta itilir; yığıttan çekince yol 0-2-3-5 olur.
- **Kruskal örneği.** Kenarlar sıralanır: h-g:1, c-i:2, f-g:2, a-b:4, c-f:4, i-g:6, c-d:7, h-i:7, a-h:8, b-c:8, d-e:9, e-f:10, b-h:11, d-f:14 (ekrandan, 02:25:00). Seçilenler: h-g, c-i, f-g, a-b, c-f, c-d, a-h, d-e. Atlananlar (çevrim oluşturur): i-g, h-i, b-c, e-f, b-h, d-f. 9 düğüm için 8 kenar seçilir, toplam ağırlık 37'dir.
- **Prim örneği.** $a$ kökünden başlanır. Ağaca sırayla eklenen kenarlar: a-b (4), b-c (8), c-i (2), c-f (4), f-g (2), g-h (1), c-d (7), d-e (9) (ekrandan, 02:40:00). Toplam $4+8+2+4+2+1+7+9=37$. Kruskal'da a-h (8), Prim'de b-c (8) seçildiği için iki ağaç farklıdır ama toplam ağırlık aynıdır.
- **Karmaşıklık.** Prim ikili yığınla: ilklendirme $O(V \log V)$, kökün anahtarını azaltma $O(\log V)$, $|V|$ kez EXTRACT-MIN $O(V \log V)$, en fazla $|E|$ kez DECREASE-KEY $O(E \log V)$; toplam $O(E \log V)$ (ekrandan, 02:50:00). Fibonacci yığınıyla DECREASE-KEY $O(1)$ olduğundan $O(V \log V + E)$ olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
