# Ders 21 Çalışma Özeti

## Genel Konular

- En uzun ortak alt dizi (Longest Common Subsequence, LCS) tekrarı
  - Alt dizi (subsequence): bir kelimeden harfler, sıraları korunarak seçilir; seçilen her harf bir öncekinden ileride olmalıdır. Harflerin bitişik olması ya da ilk harfle başlaması gerekmez.
  - Ortak alt dizi iki kelimede birlikte bulunan alt dizidir; LCS bunların en uzunudur. Kelime işlemciler, doğal dil işleme ve biyoinformatikte (DNA dizilimlerinin benzerliği) kullanılır.
  - Özyinelemeli bağıntı (ekrandan, 00:15:00):
    - $LCS[i,j] = 0$, eğer $i = 0$ ya da $j = 0$.
    - $LCS[i,j] = LCS[i-1,j-1] + 1$, eğer $i,j > 0$ ve $x_i = y_j$.
    - $LCS[i,j] = \max(LCS[i,j-1],\ LCS[i-1,j])$, eğer $i,j > 0$ ve $x_i \neq y_j$. İlk terimde $y_j$, ikincisinde $x_i$ LCS'nin parçası sayılmaz.
  - Örnek: $X = \langle BACDB \rangle$, $Y = \langle BDCB \rangle$; tablonun son hücresi 3'tür, iki LCS vardır: BCB ve BDB (ekrandan, 00:20:00).
- Başlangıç değerleri problemin amacına göre seçilir
  - LCS'de karşı kelime boşsa ortak karakter yoktur, ilk satır ve sütun 0'dır.
  - Edit distance'ta bir harfin karşısı boşsa uzaklık 1'dir, ilk satır ve sütun 0, 1, 2, 3, ... diye artar.
- LCS'nin geri izlenmesi (traceback)
  - Çözüm sondan başa doğru, tablonun sağ alt hücresinden başlanarak bulunur.
  - Çapraz (diagonal) gelinen hücrede $x_i = y_j$'dir, harf alınır. Yukarıdan ya da soldan gelinen hücrede harf alınmaz.
  - Harfleri yeniden karşılaştırmamak için tablo doldurulurken ikinci bir $b$ matrisine etiket yazılır: ADDXY (harf alınır), SKIPX ($x_i$ alınmaz, yukarı gidilir), SKIPY ($y_j$ alınmaz, sola gidilir).
- Backtracking (geri izleme) mantığına giriş
  - Labirentteki fare örneği: bir yol seçilir, çıkmaz yola (dead end) gelinince en başa değil, son karar noktasına geri dönülüp diğer seçenek denenir.
  - Dinamik programlama bütün alt problemleri çözer; backtracking ise çözüme ulaşılamayacağı görülen noktadan hiyerarşik olarak geri döner.
- Çizge (graf) gösterimleri
  - Komşuluk matrisi (adjacency matrix): $|V| \times |V|$ yer; "v ile w arasında kenar var mı" sorusu tek adımda cevaplanır.
  - Komşuluk listesi (adjacency list): her düğüm için bağlı liste; $|V| + |E|$ yer; kenar sorgusu en kötü durumda düğümün derecesi kadar adım sürer.
  - Seyrek (sparse) çizgede liste, yoğun (dense) çizgede matris uygundur.
- Derinlik öncelikli arama (Depth First Search, DFS)
  - Bir yoldan durmadan sonuna kadar gidilir, gidilecek yer kalmayınca bir adım geri dönülür; ziyaret edilen düğümler işaretlenir.
  - Yığıt (stack) kullanır; özyinelemeli yazılırsa yığıtı çağrı yığıtı sağlar.
  - Uygulamaları: topolojik sıralama, s'den t'ye yol bulma, çevrim (cycle) bulma, bağlı bileşen (connected component) sayma.
- Genişlik öncelikli arama (Breadth First Search, BFS)
  - Önce birinci kademedeki komşular, sonra ikinci kademedekiler ziyaret edilir; kuyruk (queue) kullanır.
  - Ağırlıksız çizgede en kısa yol için uygundur.
- Sonraki konu: backtracking ile n-vezir (n-queen) problemi; 4 vezirin 4×4 tahtaya birbirini görmeyecek biçimde yerleştirilmesi soru olarak bırakıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Başlangıç değerleri ezberlenmez
  - Bir öğrenci başka kaynaklarda ilk satırın 0, 1, 2, 3, 4 diye başlatıldığını sordu. Hoca bunun edit distance olduğunu, başlangıç değerinin problemin amacına bağlı olduğunu, bazı problemlerde hiç başlangıç değeri olmayabileceğini söyledi.
- Doğru çözüm sondan başa bulunur
  - LCS'nin uzunluğu sağ alt hücrededir; hangi harflerden oluştuğu geriye gidilerek bulunur. 0-1 sırt çantasında da aynı yapılmıştı.
- Etiket matrisi ile geri izleme
  - Geriye giderken harfleri yeniden karşılaştırmak tabloyu bir kez daha doldurmak gibidir. Tablo doldurulurken $b$ matrisine yazılan etiketlere bakmak yeterlidir.
- Bu algoritma tek bir LCS verir
  - Yukarı ve sol değerler eşit olduğunda if koşuluna göre biri seçilir. Bütün LCS'ler istenirse eşitlik için üçüncü bir etiket kullanılmalı ve algoritma genişletilmelidir.
- Backtracking'de geri dönüş hiyerarşiktir
  - Çıkmazdan en başa değil, son karar noktasına dönülür; belki o noktadaki diğer seçenek çözüme götürür.
- BFS özyinelemeye uygun değildir
  - BFS'nin mantığı kademe kademe ilerlemektir ve bunu kuyruk sağlar; DFS ise doğası gereği yığıt ya da özyineleme kullanır.

## Kısa Tekrar Notları

- LCS: $x_i = y_j$ ise çapraz + 1; değilse yukarı ile solun büyüğü; ilk satır ve sütun 0.
- $X = BACDB$, $Y = BDCB$ için LCS uzunluğu 3; BCB ve BDB.
- Geri izleme sağ alt hücreden başlar; çaprazda harf eklenir, yukarı ya da sola gidişte eklenmez.
- Etiketler: ADDXY → harfi LCS'nin başına ekle, $i$ ve $j$ azalır; SKIPX → $i$ azalır (yukarı); SKIPY → $j$ azalır (sola).
- LCS'nin zaman karmaşıklığı tablo boyutu kadardır: $O(mn)$.
- Komşuluk matrisi: $O(|V|^2)$ yer, $O(1)$ kenar sorgusu. Komşuluk listesi: $O(|V|+|E|)$ yer, kenar sorgusu derece kadar.
- Seyrek → liste, yoğun → matris.
- DFS = yığıt (ya da özyineleme); BFS = kuyruk.
- Ziyaret edilen düğüm işaretlenmezse arama aynı düğümlerde döner durur.
- DFS uygulamaları: topolojik sıralama, yol bulma, çevrim bulma, bağlı bileşen sayma.
- BFS: ağırlıksız çizgede en kısa yol; peer-to-peer ağlarda komşu bulma, arama motoru tarayıcıları (crawler).

## Detaylı Açıklamalar

- LCS bağıntısının mantığı
  - $x_i$ ile $y_j$ eşitse bir ortak karakter daha bulunmuştur; bir önceki durumun, yani $x_{i-1}$ ve $y_{j-1}$'e kadar olan sonucun üzerine 1 eklenir. Eşit değillerse ortak alt dizide ya $x_i$ ya $y_j$ (belki ikisi de) yoktur. Hangisinin olmadığı bilinmediği ve en uzunu arandığı için $LCS[i-1,j]$ ve $LCS[i,j-1]$'in büyüğü alınır.
  - Tablonun her hücresi, iki kelimenin o ana kadarki önekleri arasındaki LCS uzunluğudur. Örnekte BAC ile BDC karşılaştırıldığında değer 2'dir (BC); BACD ile BDCB'de hâlâ 2'dir (BD ya da BC); BACDB ile BDCB'de 3'tür (BCB ya da BDB).
  - Örneğin tamamlanmış tablosu (ekrandan, 00:20:00; python ile doğrulandı):

    | | 0 | B | D | C | B |
    |---|---|---|---|---|---|
    | 0 | 0 | 0 | 0 | 0 | 0 |
    | B | 0 | 1 | 1 | 1 | 1 |
    | A | 0 | 1 | 1 | 1 | 1 |
    | C | 0 | 1 | 1 | 2 | 2 |
    | D | 0 | 1 | 2 | 2 | 2 |
    | B | 0 | 1 | 2 | 2 | 3 |

- Geri izleme algoritması (ekrandan, 00:35:00)
  - Tablo doldurulurken: $x_i = y_j$ ise $b[i,j] = $ ADDXY; değilse $cost[i-1,j] > cost[i,j-1]$ ise $b[i,j] = $ SKIPX, aksi durumda SKIPY.
  - `findLCS(x[1..m], y[1..n], b[0..m, 0..n])`: $i = m$, $j = n$'den başlanır, $i \neq 0$ ve $j \neq 0$ olduğu sürece `switch (b[i,j])` ile ADDXY'de `x[i]` LCS'nin önüne eklenir ve $i$, $j$ bir azaltılır; SKIPX'te yalnız $i$, SKIPY'de yalnız $j$ azaltılır.
  - Harfler geriden öne bulunduğu için her yeni harf dizinin başına eklenir.
  - Eşitlikte sola giden bu kural örnekte BDB'yi verir (python ile denendi); hocanın elle izlediği yol BCB'yi verdi. İkisi de doğru LCS'dir.
- Tabloyu dolduran algoritma (ekrandan, 00:40:00)
  - `cost[0..m, 0..n]` tanımlanır. $i = 0..m$ için $cost[i,0] = 0$, $b[i,0] = $ SKIPX; $j = 0..n$ için $cost[0,j] = 0$, $b[0,j] = $ SKIPY.
  - $i = 1..m$, $j = 1..n$ için: $x[i] = y[j]$ ise $cost[i,j] = cost[i-1,j-1] + 1$, $b[i,j] = $ ADDXY; değilse yukarıdaki karşılaştırmaya göre değer yukarıdan (SKIPX) ya da soldan (SKIPY) alınır. <!-- BELİRSİZ: else dalının yazıldığı an karelerde yok; altyazıya göre aktarıldı. -->
- Komşuluk matrisi ve listesi örneği (ekrandan, 01:20:00)
  - Yönsüz, ağırlıklı çizge: A–B 5, A–C 21, A–D 12, B–C 8. Matris simetriktir (AB = BA = 5 gibi). Listede A'nın satırı B(5) → C(21) → D(12) → NULL'dur.
  - 4 düğüm ve 4 kenarlı bu çizgede liste için 4 başlık ve yönsüz olduğu için 8 liste elemanı gerekir: $|V| + |E|$ mantığı.
  - Bir milyar kullanıcılı ve kullanıcı başına en çok 200 arkadaşlı bir sosyal ağ seyrek bir matris oluşturur; listeyle kazanç çok büyüktür.
- DFS örneği (ekrandan, 01:35:00)
  - Yönlü çizgede A'dan G'ye yol aranır. A → B → E → D (D'den çıkış yok, geri) → F (F'den yalnız ziyaretli B'ye gidiliyor, geri) → geri A → C → G. Ziyaret sırası: A, B, E, D, F, C, G.
  - Özyinelemeli DFS (ekrandan, 01:40:00): `DFS(G, s)`: s'yi VISITED işaretle; s'nin her komşusu w için, w ziyaret edilmediyse `DFS(G, w)`.
  - Özyinelemesiz DFS: kaynak düğüm yığıta konup işaretlenir; yığıt boşalana kadar üstteki düğüm alınır, ziyaret edilmemiş komşuları yığıta konup işaretlenir. <!-- BELİRSİZ: yığıtlı sözde kodun yazıldığı an karelerde yok; altyazıdan aktarıldı. -->
  - Bütün düğümler ziyaret edilip aranan düğüm işaretlenmemişse yol yoktur.
- BFS örneği (ekrandan, 01:50:00 ve 02:00:00)
  - Yönsüz çizge: A–B, A–C, A–E, B–D, C–D, C–G, E–F. Kuyruk: ABCE → BCED → CEDG → EDGF → DGF → GF → F → boş. Ziyaret sırası: A, B, C, E, D, G, F.
  - Sözde kod: kaynak kuyruğa konup işaretlenir; kuyruk boşalana kadar baştaki eleman çekilir, ziyaret edilmemiş her komşusu kuyruğa konup işaretlenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
