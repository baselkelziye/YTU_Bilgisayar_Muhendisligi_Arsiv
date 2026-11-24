# Ders 4 Çalışma Özeti

## Genel Konular

- Kör arama tekrarı ve iki yönlü arama
  - Arama, başlangıç durumundan hedef duruma götüren bir operatörler dizisini bulma süreci olarak ele alınır. Durumlar, operatörler (durumlar arası geçişler) ve kısıtlar (bazı durumlarda uygulanamayan operatörler, yasaklı durumlar) tanımlanır.
  - Stratejiler tamlık (completeness), zaman karmaşıklığı, hafıza karmaşıklığı ve optimumluk ölçütleriyle karşılaştırılır. Kullanılan kavramlar: $b$ en büyük dallanma sayısı, $d$ en az maliyetli çözümün derinliği, $m$ arama uzayının en büyük derinliği (ekrandan, 00:05:00).
  - İki yönlü arama (bidirectional search): Arama hem başlangıçtan hem hedeften aynı anda yürütülür, iki taraf ortada buluşur. Her biri yarım yol ($d/2$) gider ve enlemesine arama yapılır.
    - $b=10$, $d=6$ için her yön 3 derinliğe iner; oluşturulan düğüm sayısı 2.222'dir. Tek yönlü enlemesine aramada bu sayı 1.111.111'dir (ekrandan, 00:10:00).
    - Zaman ve hafıza $O(b^{d/2})$; tamdır; tüm maliyetler eşitse optimaldir.
    - Şartı: Operatörlerin her iki yönde de tanımlı olması (hedeften geriye doğru da geçiş yapılabilmesi). Bazı problemlerde geçişler tek yönlüdür ve bu yöntem kullanılamaz.
- Kör arama algoritmalarının ortak yapısı
  - Enlemesine ve derinlemesine arama hemen hemen aynı algoritmadır: Yeni durumlar listenin sonuna eklenirse enlemesine, başına eklenirse derinlemesine arama olur (hep baştan çekildiği varsayılır).
  - Düşük maliyetli arama (uniform cost) listeden sabit bir uçtan değil, kökten o duruma gelişin maliyeti en az olan durumu çeker. Bu ona optimallik kazandırır; ancak sıralama işini verimli yapmak gerekir.
- Tekrarlayan durumlar
  - Örnek: A→D, D→E, E→A,F yolları; A'dan başlayan, hedefi F olan derinlemesine arama A, D, E, A, D, E, ... diye sonsuza gider, F hiç çekilmez (ekrandan, 00:15:00).
  - Çözüm: Yeni durumları eklemeden önce, durum o ana kadar izlenen yolda varsa ekleme. ADE yolunda E'den A ve F'ye gidilebilir; A yolda olduğu için eklenmez, F eklenir.
- my_search.m uygulaması: Algoritmaların bir harita üzerinde karşılaştırılması
  - Rastgele üretilmiş şehirler ve yollar üzerinde 12 numaralı şehirden 1 numaralı şehre yol aranır (ekrandan, 00:20:00).
  - Bulunan yolların maliyetleri: DFS 314, BFS 128, UCS 110, ilk en iyi arama 110, A* 110. Kuyruktan çekilen eleman (adım) sayıları: DFS 24, BFS 37, UCS 79, ilk en iyi arama 5, A* 6.
  - Kuyruk boyutu grafiği: UCS'nin kuyruğu 250'nin üzerine çıkar, BFS'ninki 100 civarına, DFS'ninki ise yavaş ve düzgün artar.
  - DFS'nin yolu (12, 11, 9, 15, 18, 17, 13, 10, 7, 14, 8, 5, 1) hedefe yaklaşıp uzaklaşır; kör algoritmalar hedefe yakınlık bilgisi kullanmaz.
- Sezgisel (heuristic, bilgili) arama
  - Kör algoritmalar yalnızca kökten o ana kadar gelinen maliyete bakar, hedefe ne kadar yol kaldığına bakamaz. Kalan yolu kesin bilmek çözümü bilmek demektir.
  - Sezgisel arama, hedefe kalan uzaklığın bir tahminini kullanır. Amaç daha iyi bir yol bulmak değil, çözümü daha kısa sürede bulmaktır.
- İlk en iyi arama (best first search)
  - Algoritma diğerleriyle aynıdır; yalnızca kuyruktaki durumlara değerlendirme fonksiyonuna göre puan verilir ve en düşük puanlı durum çekilir.
  - Değerlendirme fonksiyonu $f(n) = h(n)$: mevcut durumun hedefe tahmini uzaklığı. Örnek: $h_{SLD}(n)$, hedefe kuş uçuşu mesafe (Shortest Line Distance) (ekrandan, 00:50:00).
  - Algoritma her adımda hedefe en yakın **gözüken** duruma ilerler.
  - Romanya haritası örneği (Arad'dan Bükreş'e): Arad (366) → Sibiu (253) → Fagaras (176) → Bükreş (0). Bulunan yol Arad–Sibiu–Fagaras–Bükreş'tir ve optimal değildir (ekrandan, 00:55:00).
  - Analiz: Tam değil (looplara takılabilir); zaman $O(b^m)$, ama iyi sezgisel kurallar büyük iyileşme sağlar; hafıza $O(b^m)$, tüm durumlar hafızadadır; optimal değil.
- A* algoritması
  - Fikir: Kökten itibaren toplam maliyeti yüksek durumlara gidişi engellemek.
  - $f(n) = g(n) + h(n)$. $g(n)$ kökten mevcut duruma gelişin kesin bilinen maliyeti, $h(n)$ mevcut durumdan hedefe tahmini maliyettir. $f(n)$ kökten $n$ üzerinden hedefe gidişin tahmini maliyetidir.
  - Romanya örneğinde kuyrukta Fagaras üzerinden giden Bükreş ($f=450$) varken A* onu seçmez; Pitesti'yi açar ve Rimnicu Vilcea–Pitesti üzerinden giden Bükreş'i ($f=418$) seçer.
  - Analiz: Tamdır; $g$ loop oluştukça arttığı için looplara takılmaz, ek kontrol gerekmez. Zaman ve hafıza açısından ilk en iyi aramaya benzer. $h$ iyimserse optimaldir.
- Labirent örneği (Manhattan uzaklığı)
  - S'den G'ye gidilir, taralı hücrelerden geçilemez; operatörler sağ, sol, yukarı, aşağı (ekrandan, 01:05:00).
  - $h$: Engel yokmuş gibi satır farkı + sütun farkı (Manhattan uzaklığı).
  - İlk en iyi arama yalnız $h$'ye baktığı için G'ye yakın görünen uzun bir koridora girer ve çok uzun bir yol bulur. A* ise $g$ arttıkça o koridoru bırakıp kısa yoldan gider.
- 8 taş problemi için sezgisel kurallar
  - $h_1(n)$: yerinde olmayan taş sayısı; $h_2(n)$: taşların hedefteki yerlerine uzaklıkları toplamı (Manhattan uzaklığı) (ekrandan, 01:15:00).
  - Örnek başlangıç durumunda $h_1(S)=8$, $h_2(S)=3+1+2+2+2+3+3+2=18$.
  - İkisi de iyimserdir; $h_2(n) \ge h_1(n)$.
- Baskınlık (dominance)
  - Geçerli (iyimser) iki sezgisel kural için tüm durumlarda $h_2(n) \ge h_1(n)$ ise $h_2$, $h_1$'e baskındır ve arama için daha uygundur (ekrandan, 01:25:00).
  - 8 taş, $d=12$: IDS 3.644.035 düğüm, A*($h_1$) 227, A*($h_2$) 73. $d=24$: IDS pratikte çok büyük, A*($h_1$) 39.135, A*($h_2$) 1.641.
- A*'ın optimalliğinin ispatı
  - A* optimaldir, eğer $h$ gerçek maliyeti daha düşük tahmin ediyorsa ve tüm maliyetler pozitifse (ekrandan, 01:50:00).
  - Kuyrukta optimal yola götüren bir $n$ ve suboptimal bir hedef $G_2$ varken $f(n) < f(G_2)$ gösterilirse $n$ önce seçilir (ekrandan, 01:55:00).
- Uygulama: Çok robotlu keşif
  - Bilinmeyen bir ortamın haritası robotlarla çıkarılır. Keşfedilmiş ve keşfedilmemiş bölgelerin sınırındaki noktalar hedef seçilir, hedefin iyiliği oraya gidiş süresiyle hesaplanır, yol A* ile bulunur (ekrandan, 02:00:00).
  - Bu sistemde A* yüzlerce kez çözülür; sezgisel arama olmadan böyle uygulamalar pratikte çalışmaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- Optimalliğin anlamı
  - Optimal bir algoritma (örneğin düşük maliyetli arama) bir yol bulduğunda ondan daha kısa yol olmadığından emin olunur. Aynı maliyette başka bir optimal yol olabilir, ama daha ucuzu olamaz.
  - Enlemesine arama en az adımlı çözümü bulur, en az maliyetli çözümü değil; maliyetler eşit değilse bulduğu yolun en kısa olduğu söylenemez. Bir örnekte optimumu bulması algoritmanın optimal olduğunu göstermez, yalnız şanslı olduğunu gösterir.
- Sezgisel aramanın kazancı yolda değil süredir
  - Kör algoritmalar da optimum yolu bulabilir. Sezgisel algoritmaların amacı aynı çözüme daha az adımda ulaşmaktır.
- İyimser sezgi
  - $h$ iyimser: tüm durumlarda gerçek maliyetten daha düşük (ya da eşit) tahmin eder. Kuş uçuşu mesafe iyimserdir, çünkü gerçek yol kuş uçuşundan kısa olamaz.
  - A*'ın optimal olmasının şartı iyimser bir $h$ kullanmaktır.
- Baskın sezgi daha iyi çözüm değil daha hızlı çözüm demektir
  - $h_1$ ve $h_2$ ile A* aynı maliyetli çözümü bulur; fark çözüme kadar çekilen durum sayısındadır.
- A* kuyruk tablosu gösterimi
  - A*'ın adım adım çalışması, her satırda kuyruktaki yolların, son durumlarının ve $h+g$ değerlerinin yazıldığı, seçilenin koyu işaretlendiği tablo biçiminde gösterilir. Hoca bu gösterimi istediği biçim olarak belirtti; $h$ ve $g$ sırası tutarlı olduğu sürece önemsizdir.
- A*'ın looplardan kendiliğinden kurtulması
  - Loop oluştukça $g$ büyür ve o yol seçilmez; derinlemesine aramadaki gibi ek kontrol gerekmez.

## Kısa Tekrar Notları

- BFS: yeni durumlar listenin sonuna; DFS: başına; UCS: kökten maliyeti en az olan çekilir.
- İki yönlü arama: $O(b^{d/2})$; operatörlerin iki yönde de tanımlı olması gerekir.
- Tekrarlayan durumlar: Yolda zaten bulunan durumu tekrar ekleme.
- İlk en iyi arama: $f(n)=h(n)$; hızlı, ama tam değil ve optimal değil.
- A*: $f(n)=g(n)+h(n)$; tam, looplara takılmaz, $h$ iyimserse optimal.
- İyimser $h$: gerçek maliyetten küçük ya da eşit tahmin.
- 8 taş: $h_1$ yerinde olmayan taş sayısı, $h_2$ Manhattan uzaklıkları toplamı; $h_2 \ge h_1$, $h_2$ baskın.
- Baskın sezgi aramayı hızlandırır, çözümün maliyetini değiştirmez.
- Sezgi üretilemeyen problemlerde yapılabilecek tek şey kör arama kullanmaktır.

## Detaylı Açıklamalar

- **İki yönlü arama.** Bir aramayı başlangıçtan ve hedeften aynı anda başlatıp ortada buluşturmak, üstel terimdeki derinliği yarıya indirir. $b=10$, $d=6$ için tek yönlü enlemesine arama $1+10+\dots+10^6 = 1.111.111$ düğüm üretirken iki yönlü arama her yönde 3 derinliğe inerek $2 \times 1.111 = 2.222$ düğüm üretir. Bunun için hedeften geriye doğru da operatör uygulanabilmesi gerekir. Hafıza hâlâ üsteldir ($b^{d/2}$), derinlemesine aramadaki gibi doğrusal değildir.
- **Tekrarlayan durumlar.** A→D, D→E, E→A,F grafında A'dan derinlemesine arama yapılırsa liste A, D(AD), E(ADE), A(ADEA) F(ADEF), D(ADEAD) F(ADEF), ... diye ilerler. Hep baştaki çekildiği için F hiç çekilmez ve arama sonsuza gider. Yeni durum eklenirken o durum izlenen yolda zaten varsa eklenmezse A eklenmez, F eklenir ve çözüm bulunur. Derinlemesine arama looplara takılabilir; enlemesine ve düşük maliyetli arama takılmaz.
- **Sezgisel aramanın mantığı.** Bir durumun hedefe tam uzaklığını bilmek çözümü bilmek demektir. Ama yaklaşık bir tahmin bile aramayı hedefe doğru yönlendirir. my_search.m deneyinde kör algoritmalar 24-79 adım sürerken ilk en iyi arama 5, A* 6 adımda çözüme ulaşmıştır. Az adım sürdüğü için kuyruk da küçük kalır; ama uzun süren problemlerde sezgisel algoritmaların hafızası da büyür.
- **İlk en iyi arama, Romanya örneği.** Arad'dan Bükreş'e kuş uçuşu mesafeler $h$ olarak kullanılır. Arad açılınca Sibiu (253), Timisoara (329), Zerind (374) eklenir; Sibiu seçilir. Sibiu'dan Arad (366), Fagaras (176), Oradea (380), Rimnicu Vilcea (193) eklenir; kuyrukta 6 eleman vardır, Fagaras seçilir. Fagaras'tan Sibiu (253) ve Bükreş (0) eklenir; Bükreş'in $h$ değeri 0 olduğu için seçilir ve arama biter. Bulunan yol Arad–Sibiu–Fagaras–Bükreş'tir; daha kısa bir yol (Rimnicu Vilcea–Pitesti üzerinden) olduğu için optimal değildir.
- **A*, Romanya örneği.** Arad için $366 = 0 + 366$ yazılır. Sibiu açıldıktan sonra kuyruktaki altı durumdan $f$'si en küçük olan Rimnicu Vilcea seçilir, sonra Fagaras açılır. Bu anda kuyrukta Fagaras üzerinden Bükreş vardır ($f=450$), ama Pitesti'nin $f$'si daha küçük olduğu için Pitesti açılır. Sonunda kuyruktaki 11 durum içinden $f$'si en küçük olan, Rimnicu Vilcea–Pitesti üzerinden giden Bükreş seçilir. İlk en iyi arama ise hedef kuyruğa girer girmez onu seçerdi. <!-- BELİRSİZ: Ara f değerlerinin (393, 413, 415, 417, 418) yalnız bir kısmı altyazıda geçiyor; slayt karesi yok. Değerler kitaptaki standart Romanya haritasıyla python ile hesaplandı. -->
- **Labirent örneği.** Manhattan uzaklığı, ortamda engel yokmuş gibi satır ve sütun farklarının toplamıdır. İlk en iyi arama G'ye sayısal olarak yakın görünen hücreleri izleyerek G'nin yanındaki çıkmaz koridora girer ve dolaşarak uzun bir yol bulur. A* aynı yöne bir süre ilerler, ama $g$ büyüdükçe toplam maliyet diğer seçeneği geçer ve kısa yoldan devam eder. A*'ın yol değiştirmesi bir kez olmak zorunda değildir; labirente göre birkaç kez taraf değiştirebilir.
- **8 taş sezgileri.** Başlangıç durumu 7 2 4 / 5 _ 6 / 8 3 1, hedef _ 1 2 / 3 4 5 / 6 7 8 iken hiçbir taş yerinde olmadığı için $h_1=8$; taşların 1'den 8'e Manhattan uzaklıkları $3+1+2+2+2+3+3+2 = 18$ olduğu için $h_2=18$ (python ile doğrulandı). $h_2$ iyimserdir, çünkü taşları sanki aradaki taşlar yokmuş gibi hareket ettirir; gerçekte örneğin 7'yi yerine üç hamlede getirmek mümkün değildir. $h_1$ her taşın tek hamlede yerine gidebileceğini varsaydığı için daha da iyimserdir. Her taşın uzaklığı en az 1 olduğu için $h_2 \ge h_1$'dir.
- **A*'ın optimalliği.** $G$ optimal hedef, $G_2$ suboptimal hedef, $n$ kuyruktaki optimal yol üzerindeki bir durum olsun. $h(G_2)=0$ olduğundan $f(G_2)=g(G_2)$, $h(G)=0$ olduğundan $f(G)=g(G)$. $G_2$ optimal olmadığından $g(G_2) > g(G)$, dolayısıyla $f(G_2) > f(G)$. $h$ iyimserse $h(n) \le h^*(n)$; iki tarafa $g(n)$ eklenince $f(n) \le g(n)+h^*(n) = f(G)$. Buradan $f(n) \le f(G) < f(G_2)$, yani A* $n$'yi $G_2$'den önce seçer ve suboptimal bir çözümü asla çekmez (ekrandan, 01:55:00).
- **Çok robotlu keşif.** Tek robotla: hedefleri belirle (keşfedilmiş ile keşfedilmemiş bölgenin sınırı), hedeflerin iyiliğini hesapla, hedef seç, yolu A* ile bul, robotu götür, yeniden hedef seç. Çok robotla: hedefleri belirle, her robot için hedeflerin iyiliğini hesapla, robot-hedef eşlemesi yap, yolları bul, robotları götür. Hedef sayısı azaldıkça birden fazla robot aynı hedefe yönelebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
