# Ders 10 Çalışma Özeti

## Genel Konular

- En Uzun Ortak Alt Dizi (Longest Common Subsequence, LCS)
  - İki dizginin (string) soldan sağa sırası korunarak seçilen, ikisinde de bulunan en uzun ortak alt dizisi aranır. Karakterlerin bitişik olması gerekmez. DNA dizilerinde ortak yapıyı ve bu yapıyı bozan (ör. mutasyon) yerleri bulmak gibi uygulamaları vardır.
  - Örnek (ekrandan, 00:15:00): $X = \text{ATCTGAT}$, $Y = \text{TGCATA}$ için $LCS(X, Y) = \text{TCTA}$ (uzunluk 4). TCT, TC, A gibi daha kısa ortak alt diziler de vardır.
  - Problem alt problemlere bölünebildiği için dinamik programlamayla çözülür: dizgilerin tamamı yerine önekleri (A, AT, ATC, ...) düşünülür, sonuçlar bir tabloda saklanır.
- LCS bağıntısı (ekrandan, 00:15:00)
  - Durum 1, $x_i = y_j$: bu karakter ortak alt diziye eklenir, $LCS[i, j] = LCS[i-1, j-1] + 1$ (çapraz hücre + 1).
  - Durum 2, $x_i \ne y_j$: ya $x_i$ ya da $y_j$ ortak alt dizinin parçası değildir. Üstteki $LCS[i-1, j]$ ile soldaki $LCS[i, j-1]$ hücrelerinden büyüğü alınır.
  - Başlangıç: $i = 0$ ya da $j = 0$ ise (boş dizgi) değer 0'dır.
  - $$LCS[i,j] = \begin{cases} 0 & i = 0 \text{ ya da } j = 0 \\ LCS[i-1,j-1] + 1 & i,j > 0 \text{ ve } x_i = y_j \\ \max(LCS[i-1,j],\ LCS[i,j-1]) & i,j > 0 \text{ ve } x_i \ne y_j \end{cases}$$
- LCS sayısal örneği (ekrandan, 00:30:00)
  - $X = \langle B, A, C, D, B \rangle$ (satırlar), $Y = \langle B, D, C, B \rangle$ (sütunlar). Tabloya boş dizgi için fazladan bir satır ve bir sütun eklenir.
  - Dolu tablo ve sonuç uzunluğu 3; en uzun ortak alt diziler BDB ve BCB (CB, DB gibi daha kısaları da var).
- Geriye izleme ile alt dizinin bulunması (ekrandan, 00:35:00)
  - Son hücreden başlanır. Değer üst ve soldaki değerlerden farklıysa çapraz gelinmiştir ve karakter alt diziye eklenir. Aynıysa üst ya da sola gidilir; iki yolun seçimi farklı alt dizileri (BCB ya da BDB) verir.
  - Yön tablosu etiketleri: `ADDXY` ($x_i = y_j$, $B[i,j]$), `SKIPX` ($B[i-1,j]$), `SKIPY` ($B[i,j-1]$).
- LCS karmaşıklığı
  - Kaba kuvvet çözümü üstel karmaşıklıktadır. Tabloyu doldurmak $\Theta(mn)$ zaman, tablo $\Theta(mn)$ yer ister; iki dizgi yaklaşık eşit uzunluktaysa ikisi de $\Theta(n^2)$'dir.
- Açgözlü yöntem (Greedy method) (ekrandan, 00:40:00)
  - Optimizasyon problemlerinde kullanılır. Dinamik programlama optimal çözümü verirken açgözlü yöntem her adımda o an en kârlı görüneni seçer ve uygun (feasible) bir çözüm verir; bu çözüm optimal olmayabilir.
  - Para bozma (change-making) problemi: en büyük birimden başlanarak en az sayıda para seçilir.
  - Sırt çantası (knapsack) için açgözlü yaklaşım: her eşyanın kârlılığı $v_i / w_i$ hesaplanır, büyükten küçüğe sıralanır ve kapasite $C$ dolana kadar en kârlıdan başlayarak eşya alınır.
  - Minimum yayılan ağaç (Prim, Kruskal), Dijkstra en kısa yol algoritması ve Huffman kodlaması da açgözlü yöntemin uygulamalarıdır.
- Minimum yayılan ağaç (Minimum Spanning Tree) (ekrandan, 00:50:00)
  - Yayılan ağaç grafın bütün düğümlerine erişen ve döngü içermeyen bir alt ağaçtır. Amaç, kenar kümesinden ($a_1, \dots, a_6$) toplam maliyeti en küçük olan kenarları seçmektir.
  - Kruskal: kenarlar ağırlığa göre sıralanır, döngü oluşturmayan en küçük kenar seçilir; ara adımlarda orman oluşabilir, sonunda tek ağaç elde edilir.
  - Prim: bir düğümden başlanır, ağaçtan çıkan kenarlardan en küçüğü seçilir, sürekli döngü kontrolü yapılır.
- Graf tekrarı
  - Graf, düğümler (vertex) ve kenarlar (edge) kümesidir. Yönlü (directed, digraph) ya da yönsüz, ağırlıklı ya da ağırlıksız olabilir.
  - Tam graf (complete graph): her düğüm başka bir düğümden geçmeden diğer bütün düğümlere doğrudan bağlıdır.
  - Ağaç döngüsüz bağlı graftır; birbirinden bağımsız birden çok ağaçtan oluşan graf ormandır (forest). Her ağaç bir bağlı bileşendir (connected component).
- Grafın saklanması (ekrandan, 01:00:00)
  - Komşuluk matrisi (adjacency matrix): yoğun (dense) graflar için uygundur, yer $\Theta(|V|^2)$. Bağlantı 0/1 ya da ağırlık olarak yazılır.
  - Komşuluk listesi (adjacency list): seyrek (sparse) graflar için uygundur, yer $\Theta(|V| + |E|)$.
  - Örnek: 6 düğümlü seyrek grafta matris 36 hücre tutar; 5 kenar olduğundan 31 hücre boşa gider.
- Graf üzerinde gezinme: BFS ve DFS (ekrandan, 01:20:00)
  - Genişlik öncelikli arama (BFS) önce çevredekilere bakar, kuyruk (queue, FIFO; enqueue/dequeue) kullanır.
  - Derinlik öncelikli arama (DFS) gidebildiği kadar derine gider, sonra geri döner; yığıt (stack, LIFO; push/pop) kullanır.
  - Ziyaret bilgisi bir `visited` dizisinde (0 = ziyaret edilmedi) tutulur.
- DFS sözde kodları (ekrandan, 01:20:00 ve 01:35:00)
  - Sayaçlı DFS: bütün düğümler 0 ile işaretlenir; işaretsiz her düğüm için `dfs(v)` çağrılır; `dfs(v)` sayacı artırır, düğümü sayaçla işaretler ve işaretsiz her komşu için kendini çağırır.
  - Özyinelemeli DFS: özyinelemeli çağrıların kendi yığıtı olduğu için ayrıca yığıt gerekmez.
  - Yığıtlı (iteratif) DFS: başlangıç düğümü yığıta atılır; yığıt boşalana kadar düğüm çekilir, ziyaret edilmemiş komşular yığıta atılıp işaretlenir.
  - Karmaşıklık: komşuluk matrisiyle $\Theta(|V|^2)$, komşuluk listesiyle $\Theta(|V| + |E|)$.
- DFS örneği (ekrandan, 01:25:00)
  - Yönlü grafta A'dan G'ye yol aranır. A → B → E → D çıkmaz, geri dönülür; E → F çıkmaz, F, E, B yığıttan çıkar; A → C → G ile hedefe ulaşılır.
- Topolojik sıralama (ekrandan, 01:40:00 ve 01:45:00)
  - Ön koşullu dersler örneği: C1 → C3, C2 → C3, C3 → C4, C3 → C5, C4 → C5. Grafta döngü olmamalıdır (yönlü döngüsüz graf).
  - DFS yöntemi: girişi olmayan bir düğümden başlanır; düğümlerin yığıttan çıkış sırası (popping-off order) C5, C4, C3, C1, C2'dir. Bu sıranın tersi C2, C1, C3, C4, C5 topolojik sıralamadır.
  - Azalt ve fethet (kaynak çıkarma, source removal) yöntemi: girişi olmayan bir düğüm seçilir ve kenarlarıyla birlikte graftan çıkarılır; kalan grafta işlem tekrarlanır. Yığıt gerekmez. Derste bir örnekte elde edilen sıra a, e, b, f, c, d, g, h oldu (ekrandan, 01:50:00).
- Geri izleme (Backtracking) (ekrandan, 01:55:00)
  - Çözüme doğru ilerlenirken çıkmaza (dead end) girilirse bir önceki adıma dönülüp başka bir seçenek denenir. Önceki adımları hatırlamak için yığıt ya da DFS kullanılır.
  - Arama uzayı durum uzayı ağacı (state space tree) ile gösterilir.
  - Örnek: {1, 2, 3} rakamlarıyla yazılabilecek sayılar ağaçta 6 yaprak verir (123, 132, 213, 231, 312, 321).
- Graf işlemlerinin karmaşıklığı (ekrandan, 02:10:00)
  - Yer: komşuluk matrisi $\Theta(|V|^2)$, komşuluk listesi $\Theta(|V| + |E|)$.
  - İki düğüm arasında kenar var mı sorusu: matriste $\Theta(1)$, listede $O(\text{degree}(v))$.
- Alt küme toplamı (Subset Sum) (ekrandan, 02:20:00)
  - Kaba kuvvet $2^n$ alt kümeyi dener. Kitap örneği: $A = \{1, 2, 5, 6, 8\}$, $d = 9$ için $2^5 = 32$ alt küme denenir; çözümler $\{1, 2, 6\}$ ve $\{1, 8\}$.
  - Geri izleme: sayılar sıralanır, her sayı için "al" ve "alma" dalları DFS ile gezilir, toplam hedefi aşınca geri dönülür. $S = \{3, 5, 6, 7\}$, $d = 15$ için $3 + 5 + 7 = 15$ bulunur.
- N-Vezir problemi (ekrandan, 02:35:00)
  - $n \times n$ tahtaya $n$ vezir, birbirini tehdit etmeyecek biçimde yerleştirilir. $1 \times 1$ kendiliğinden çözümdür, $2 \times 2$ ve $3 \times 3$ için çözüm yoktur, $4 \times 4$ ve üstünde çözüm vardır.
  - 8 vezir için deneme sayıları: kaba kuvvet $\binom{64}{8} = 4\,426\,165\,368$ (yaklaşık 4,5 milyar); her satıra bir vezir $8^8 = 16\,777\,216$; her satır ve sütuna bir vezir $8! = 40\,320$; geri izleme 2057.
  - $4 \times 4$ için geri izleme sonucu bulunan çözüm: satır 1 sütun 2, satır 2 sütun 4, satır 3 sütun 1, satır 4 sütun 3.
- Hamilton devresi (Hamiltonian Circuit) problemi (ekrandan, 02:40:00)
  - Her düğümden tam bir kez geçip başlangıca dönen devre aranır. Geri izleme ile durum uzayı ağacı kurulur; derste bulunan devre $a \to b \to f \to e \to c \to d \to a$.

## Hocanın Özellikle Vurguladığı Kısımlar

- LCS'de eşit olmayan durumda üst ve sol hücreden büyüğü alınır
  - Bu, o ana kadar bulunmuş en uzun ortak alt dizinin korunmasını sağlar. Eşitlikte ise mutlaka çapraz hücreye 1 eklenir.
- Dinamik programlama ile açgözlü yöntemin farkı
  - Açgözlü yöntem ilk bakışta en kârlı seçimi yapar ve geleceği düşünmez; bu yüzden uygun (feasible) çözüm verir ama optimal çözümü kaçırabilir. Dinamik programlama ise bütün alt problemleri tabloya kaydederek optimal sonuca ulaşır.
- Yoğun graf için matris, seyrek graf için liste
  - Seyrek grafı matriste saklamak gereksiz yer kaplar.
- DFS yığıt ister
  - Geri dönülecek yeri hatırlamak gerekir. Özyinelemeli yazımda bu yığıt çağrı yığıtıdır; bu yüzden özyinelemeli çözüm daha kolaydır.
- Topolojik sıralamada döngü olmamalıdır
  - Döngü varsa topolojik sıralamanın çözümü yoktur.
- Geri izlemenin temeli DFS'tir
  - Çıkmaza girince bir önceki adıma dönülür. Bir sonraki konu olan dal ve sınır (branch and bound) yönteminde ise BFS kullanılacak.

## Kısa Tekrar Notları

- LCS: $x_i = y_j$ ise çapraz + 1; değilse $\max(\text{üst}, \text{sol})$; ilk satır ve sütun 0.
- BACDB ile BDCB'nin LCS uzunluğu 3: BCB ya da BDB.
- LCS zaman ve yer karmaşıklığı $\Theta(mn)$.
- Açgözlü yöntem: feasible çözüm; sırt çantasında $v_i/w_i$ oranına göre azalan sırada al.
- Kruskal: en küçük kenar, döngü yok. Prim: bir düğümden başla, çıkan en küçük kenar.
- Komşuluk matrisi $\Theta(|V|^2)$ yer, liste $\Theta(|V|+|E|)$ yer.
- Kenar sorgusu: matriste $\Theta(1)$, listede $O(\text{degree}(v))$.
- BFS: kuyruk (FIFO). DFS: yığıt (LIFO).
- DFS karmaşıklığı: matrisle $\Theta(|V|^2)$, listeyle $\Theta(|V|+|E|)$.
- Topolojik sıralama: DFS'te yığıttan çıkış sırasının tersi; ya da kaynak çıkarma (azalt ve fethet).
- Geri izleme: DFS + çıkmazda geri dönüş; durum uzayı ağacı.
- 8 vezir: $\binom{64}{8} \approx 4{,}4$ milyar, $8^8 \approx 16{,}8$ milyon, $8! = 40\,320$, geri izleme 2057.

## Detaylı Açıklamalar

- **LCS'nin dinamik programlamayla çözümü.** Kaba kuvvetle iki dizgide ortak karakterleri soldan sağa eşleştirmeye çalışmak, başta yapılan bir eşleştirme yüzünden daha uzun bir ortak alt diziyi kaçırabilir. Dinamik programlama bunun yerine dizgilerin bütün öneklerini birbiriyle karşılaştırır ve her önek çifti için en uzun ortak alt dizinin uzunluğunu bir tabloya yazar. $X = \text{BACDB}$, $Y = \text{BDCB}$ için tablo şöyledir (ekrandan, 00:30:00):

  | | $\varnothing$ | B | D | C | B |
  |---|---|---|---|---|---|
  | $\varnothing$ | 0 | 0 | 0 | 0 | 0 |
  | B | 0 | 1 | 1 | 1 | 1 |
  | A | 0 | 1 | 1 | 1 | 1 |
  | C | 0 | 1 | 1 | 2 | 2 |
  | D | 0 | 1 | 2 | 2 | 2 |
  | B | 0 | 1 | 2 | 2 | 3 |

  Sağ alt köşedeki 3, en uzun ortak alt dizinin uzunluğudur. Geriye izlemede 3'ün üstü ve solu 2 olduğu için B çapraz gelinerek eklenmiştir. Sonraki 2'de üst ve sol eşit olduğundan iki yol vardır: bir yol C'yi, diğeri D'yi alır. Böylece BCB ve BDB bulunur.

- **Geriye izleme sözde kodu (ekrandan, 00:35:00).** Tabloyu doldururken her hücreye hangi durumdan gelindiği de yazılır (`ADDXY`, `SKIPX`, `SKIPY`). Sonra alt dizi sondan başa doğru kurulur:

  ```text
  FindLCS(X[1..m], Y[1..n], B[0..m, 0..n]) {
      i = m; j = n;
      while (i != 0 && j != 0) {
          switch (B[i, j]) {
              case ADDXY: add X[i] to LCS (önüne); i--; j--; break;
              case SKIPX: i--; break;
              case SKIPY: j--; break;
          }
      }
  }
  ```

  Döngü en fazla $m + n$ kez döner; asıl maliyet tabloyu doldurmaktır.

- **Açgözlü yöntemin sınırı.** Para bozmada birimler birbirinin tam katıysa (ör. 20 TL'yi 10, 5 ve 1'lerle bozmak) en büyük birimden başlamak iyi sonuç verir. Birimler böyle değilse açgözlü seçim yalnız uygun bir çözüm verir. Sırt çantasında da en yüksek değerli ya da en kârlı eşyayı önce almak, bazı durumlarda onu almayıp başkalarını almaktan daha düşük toplam değer verebilir; dinamik programlama bu durumu önceki derste göstermişti.

  > Ek bilgi (derste anlatılmadı): Para bozmada açgözlü yöntemin optimal olmadığı bilinen bir örnek $\{1, 3, 4\}$ birimleriyle 6'yı bozmaktır: açgözlü $4 + 1 + 1$ (3 para) verir, optimal $3 + 3$'tür (2 para).

- **DFS ve yığıt.** Hoca DFS'i, tabelası olmayan bir fakülte binasında bölüm sekreterliğini arayan birine benzetti: kişi bir koridora girer, sonuna kadar bütün kapılara bakar, bulamazsa son ayrıldığı yere döner ve başka koridoru dener. Geri dönülecek yerler yığıtta tutulur. Yönlü örnek grafta (A → B, A → C, A → D, B → E, B → F, C → E, C → G, E → D, E → F, G → F) A'dan G'ye arama: A, B, E, D ziyaret edilir; D'den çıkış yok, geri dönülür; E'den F'ye gidilir, oradan da çıkış yok; F, E, B yığıttan çıkar; A'dan C'ye, C'den G'ye gidilerek hedef bulunur.

- **Topolojik sıralama için iki yol.** DFS ile: C1'den başlanır, C1 → C3 → C4 → C5 yığıta girer; C5, C4, C3, C1 sırasıyla çıkar; sonra C2 yığıta girer ve çıkar. Çıkış sırasının tersi (C2, C1, C3, C4, C5) bir topolojik sıralamadır. C2'den başlanınca da sıra C1, C2, C3, C4, C5 olur; topoloji bozulmaz. Kaynak çıkarma yönteminde ise her adımda girişi olmayan bir düğüm seçilip graftan çıkarılır. Bu, $T(n) = 1 + T(n-1)$ biçimindeki azalt ve fethet yaklaşımıdır.

- **Geri izlemenin kazancı.** N-vezir probleminde her satıra bir vezir konacağı bilindiği için deneme sayısı milyarlardan milyonlara, her sütuna da bir vezir konacağı bilinince $n!$'e iner. Geri izleme, çıkmaza giren dalları erken keserek 8 vezir için ilk çözümü 2057 denemede bulur. Bu sayı ilk çözümün bulunduğu deneme sayısıdır, toplam çözüm sayısı değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
