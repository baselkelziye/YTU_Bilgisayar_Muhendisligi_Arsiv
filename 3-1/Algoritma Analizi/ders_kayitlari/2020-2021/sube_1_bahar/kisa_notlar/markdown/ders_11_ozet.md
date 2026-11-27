# Ders 11 Çalışma Özeti

## Genel Konular

- Açgözlü teknik ve optimal çözüm üzerine düzeltme
  - Açgözlü (greedy) teknik çoğu durumda optimal çözümü vermez, yaklaşık bir çözüm verir. Optimal çözüm istenmiyorsa 0-1 sırt çantası gibi "ya seç ya seçme" türündeki problemlerde de kullanılabilir.
  - Para bozma örneği: 1, 2, 5, 10 liralık paralarla 50 lira bozulurken açgözlü çözüm optimal çözümle aynı sonucu verir. Paralar birbirinin tam katı değilse (ör. 2, 3, 5, 7) açgözlü çözüm yaklaşık sonuç verir; optimal çözüm dinamik programlamayla bulunur.
  - Dinamik programlama çözümü bir rekürans bağıntısıyla başlar, ama yalnız özyinelemeli (rekürsif) bir fonksiyon yazmak dinamik programlama değildir. Tekrar eden alt problemlerin sonuçları saklanmalıdır (memoization); yoksa tasarım böl ve fethet ya da azalt ve fethet olur.
- Genişlik öncelikli arama (Breadth-First Search, BFS)
  - Kuyruk (queue) veri yapısını kullanan bir kör arama (blind search) algoritmasıdır; DFS ise yığın (stack) kullanır. Kuyrukta ekleme arkadan (rear), çıkarma önden (front) yapılır.
  - DFS bir yönde derinlemesine ilerler. BFS önce bulunduğu düğümün bütün komşularına bakar, sonra arama alanını suya atılan taşın halkaları gibi genişletir.
  - Algoritma: bütün köşeler ziyaret edilmemiş (0) olarak işaretlenir; başlangıç köşesi sayaçla işaretlenip kuyruğa atılır; kuyruk boşalana kadar öndeki köşenin ziyaret edilmemiş komşuları sayaç artırılarak işaretlenir ve kuyruğa eklenir, sonra öndeki köşe kuyruktan çıkarılır (ekrandan, 00:30:00).
  - BFS özyinelemeli değildir; hiçbir zaman geri dönülmez, kuyruk nereyi gösterirse oraya gidilir.
  - Kuyruk boşaldığında ziyaret edilmemiş köşe kalmışsa çizgede başka bir bağlı bileşen vardır; BFS o köşeden yeniden başlatılır.
- DFS ile BFS karşılaştırması
  - Veri yapısı: DFS yığın, BFS kuyruk.
  - Köşe sıralaması sayısı: DFS iki sıralama, BFS tek sıralama verir.
  - Komşuluk matrisiyle verimlilik $\Theta(|V|^2)$, komşuluk listesiyle $\Theta(|V|+|E|)$; ikisinde de aynıdır.
  - Kenar türleri: DFS'de ağaç ve geri (tree, back) kenarları, BFS'de ağaç ve çapraz (tree, cross) kenarları.
- Optimizasyon problemleri ve dal ve sınır (branch and bound) yöntemi
  - Optimizasyonda belirli kısıtlar altında (under certain constraints) bir amaç fonksiyonu ya minimize ya maksimize edilir (ekrandan, 00:50:00).
  - Çözüm türleri: uygulanamaz (improbable/unlikely) çözüm ve uygulanabilir (feasible) çözümler; uygulanabilir çözümlerin içinde optimal (en iyi) çözüm ve yaklaşık (approximate) çözüm vardır.
  - Dal ve sınır, BFS mantığıyla bir durum uzayı ağacı (state space tree) kurar. Her düğümde bir sınır hesaplanır, en umut verici düğümden devam edilir, umutsuz dallar budanır.
  - Minimizasyonda alt sınır (lower bound) kullanılır ve sonuç $\geq$ alt sınırdır. Maksimizasyonda üst sınır (upper bound) kullanılır ve sonuç $\leq$ üst sınırdır.
- Atama problemi (assignment problem)
  - 4 kişi ve 4 iş için maliyet matrisi verilir; her kişiye bir iş, her işe bir kişi atanacak ve toplam maliyet en aza indirilecek (ekrandan, 00:55:00).
  - Alt sınır: atanmış maliyetler ile atanmamış her kişinin, alınmamış işler arasındaki en küçük maliyeti toplanır.
  - Sonuç: P1→J2, P2→J1, P3→J3, P4→J4, toplam maliyet 13 (ekrandan, 01:15:00).
- 0-1 sırt çantası (knapsack) problemi
  - Nesneler değer/ağırlık oranına göre azalan sırada dizilir. Üst sınır $ub = v + (W - w)\cdot(v_{i+1}/w_{i+1})$ formülüyle hesaplanır (ekrandan, 01:30:00).
  - Kapasite 10 olan örnekte en iyi çözüm 1. ve 3. nesneler, toplam değer 65'tir (ekrandan, 01:40:00).
- Dönüştür ve fethet (transform and conquer)
  - Problem, çözümü bilinen başka bir probleme dönüştürülür: metinden kurulan 7 bilinmeyenli denklem sistemi Gauss eliminasyonuyla çözülür.
  - En küçüğü bulan `find_min` fonksiyonuyla en büyük eleman bulunur: dizinin negatifi alınır, `find_min` çağrılır, sonucun negatifi alınır (ekrandan, 01:45:00).
  - Çok sayıda arama yapılacaksa dizi önce sıralanır (ön sıralama, presorting), sonra ikili arama kullanılır. Veritabanı indekslemesi de bu fikre dayanır.
- Alt sınır (lower bound) kavramına giriş
  - Hoca alt sınırı $\Omega$ gösterimi ve "en iyi durum" ile ilişkilendirdi (ekrandan, 01:50:00). Sıralı dizide arama için ikili aramayla $\log n$ verildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Açgözlü teknik optimal çözümü garanti etmez
  - Optimal çözüm ancak özel durumlarda açgözlü teknikle elde edilir. İnternetteki bazı kaynaklardaki "0-1 sırt çantasında açgözlü teknik kullanılamaz" ifadesi, optimal çözüm istendiği varsayılarak doğrudur. Optimal çözüm istenmiyorsa açgözlü teknik kullanılabilir.
- Dinamik programlama rekürans bağıntısıyla başlar
  - Önce problemin örtüşen alt problemlerden oluştuğu görülür, sonra rekürans bağıntısı kurulur. Yalnız rekürsif fonksiyon yazmak dinamik programlama değildir.
- Hangi sınıra bakılacağı
  - Minimizasyonda alt sınıra bakılır; bulunan sonuç bu sınırın altına inemez. Maksimizasyonda üst sınıra bakılır; sonuç bu sınırı geçemez. Hoca bunu önce ters söyledi, sonra düzeltti.
- Bilginin transferi
  - Öğrenilen bir algoritmayı başka bir problemde kullanamamak, onun boşuna öğrenildiği anlamına gelir. Dönüştür ve fethet bu transferin algoritmik karşılığıdır.

## Kısa Tekrar Notları

- BFS kuyruk, DFS yığın kullanır. BFS özyinelemeli değildir ve tek köşe sıralaması verir.
- Örnek çizgede A'dan başlayan BFS sırası: A, B, C, E, D, G, F.
- Kuyruk boşalınca ziyaret edilmemiş köşe varsa çizge bağlı değildir.
- Komşuluk matrisi $\Theta(|V|^2)$, komşuluk listesi $\Theta(|V|+|E|)$.
- Dal ve sınır: durum uzayı ağacı + her düğümde sınır + en iyi düğümden devam + budama.
- Atama örneğinde kök alt sınırı $2+3+1+4=10$, optimal maliyet 13.
- Sırt çantası örneğinde kök üst sınırı 100, optimal değer 65 (1. ve 3. nesne).
- Dönüştür ve fethet: en büyük = $-\text{find\_min}(-A)$; tekrarlı aramada önce sırala.

## Detaylı Açıklamalar

- **BFS sözde kodu.** Hocanın yazdığı genel biçim (ekrandan, 00:30:00 ve 00:40:00):

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

  Başlangıçta `enqueue` ile işaretleme yer değiştirebilir; BFS özyinelemeli olmadığı için sıra sorun çıkarmaz. Sayaçlı sürümde her yeni köşe `count = count + 1` ile ziyaret sırasına göre numaralanır.

- **BFS örneği.** Çizgenin kenarları A-B, A-C, A-E, B-D, C-D, C-G, E-F'dir (ekrandan, 00:35:00). A kuyruğa atılır; komşuları B, C, E ziyaret edilip kuyruğa eklenir, A çıkarılır. B'nin ziyaret edilmemiş komşusu D eklenir. C'nin komşusu D zaten ziyaret edildiği için yalnız G eklenir. E'nin komşusu F eklenir. Sonra D, G, F sırayla kuyruktan çıkar. Ziyaret sırası A, B, C, E, D, G, F'dir. Komşuluk listesindeki sıra değişirse (ör. A'dan sonra önce C) ziyaret sırası da değişir. Çizgeye bağlantısız bir H köşesi eklenirse, kuyruk boşaldığında H hâlâ ziyaret edilmemiştir; H kuyruğa atılıp işlenir ve çizgede iki bağlı bileşen olduğu anlaşılır.

- **Atama problemi.** Maliyet matrisi (satırlar kişiler, sütunlar işler) (ekrandan, 00:55:00):

  | | J1 | J2 | J3 | J4 |
  |---|---|---|---|---|
  | P1 | 9 | 2 | 7 | 8 |
  | P2 | 6 | 4 | 3 | 7 |
  | P3 | 5 | 8 | 1 | 8 |
  | P4 | 7 | 6 | 9 | 4 |

  Kısıtsız düşünüldüğünde her satırın en küçüğü alınır: $2+3+1+4=10$. Bu, olabilecek en düşük maliyettir (kökün alt sınırı); J3 iki kişiye verildiği için gerçekte uygulanamaz. Birinci seviyede P1'e her iş denenir (ekrandan, 01:15:00):

  | Düğüm | Alt sınır hesabı | lb |
  |---|---|---|
  | P1←J1 | $9+3+1+4$ | 17 |
  | P1←J2 | $2+3+1+4$ | 10 |
  | P1←J3 | $7+4+5+4$ | 20 |
  | P1←J4 | $8+3+1+6$ | 18 |

  En küçük sınırlı P1←J2 genişletilir:

  | Düğüm | Alt sınır hesabı | lb |
  |---|---|---|
  | P2←J1 | $2+6+1+4$ | 13 |
  | P2←J3 | $2+3+5+4$ | 14 |
  | P2←J4 | $2+7+1+7$ | 17 |

  P2←J1 genişletildiğinde iki yaprak kalır: P3←J3, P4←J4 için $2+6+1+4=13$; P3←J4, P4←J3 için $2+6+8+9=25$. 13 maliyetli çözüm diğer bütün düğümlerin sınırından küçük ya da eşit olduğu için onlar budanır. Optimal atama P1→J2, P2→J1, P3→J3, P4→J4, toplam 13'tür (python ile tüm permütasyonlar denenerek doğrulandı).

- **Sırt çantası problemi.** Kapasite $W=10$ (ekrandan, 01:30:00):

  | Nesne | Ağırlık | Değer | Değer/ağırlık |
  |---|---|---|---|
  | 1 | 4 | 40 | 10 |
  | 2 | 7 | 42 | 6 |
  | 3 | 5 | 25 | 5 |
  | 4 | 3 | 12 | 4 |

  Açgözlü çözüm orana göre 1. nesneyi alır (6 birim yer kalır), 2. nesne sığmaz, 3. nesneyi alır (1 birim kalır), 4. nesne sığmaz: değer 65. Dal ve sınır ağacı (ekrandan, 01:40:00):

  ```text
  kök: w=0, v=0, ub = 0 + 10*10 = 100
  ├── 1 alındı: w=4, v=40, ub = 40 + 6*6 = 76
  │   ├── 2 alındı: w=11 > 10, uygulanamaz
  │   └── 2 alınmadı: w=4, v=40, ub = 40 + 6*5 = 70
  │       ├── 3 alındı: w=9, v=65, ub = 65 + 1*4 = 69
  │       │   ├── 4 alındı: w=9+3=12 > 10, uygulanamaz
  │       │   └── 4 alınmadı: w=9, v=65, ub = 65  (çözüm)
  │       └── 3 alınmadı: w=4, v=40, ub = 40 + 6*4 = 64
  └── 1 alınmadı: w=0, v=0, ub = 10*6 = 60
  ```

  Değeri 65 olan yaprak, kalan bütün düğümlerin üst sınırından (64, 60) büyük ya da eşit olduğu için en iyi çözümdür: 1. ve 3. nesneler, değer 65. Sınır formülü açgözlü düşünceden gelir ("yükte hafif, pahada ağır").

- **Dönüştür ve fethet örneği.** Dizi 6, 1, 2, 8, 3 için negatifler −6, −1, −2, −8, −3'tür; `find_min` −8'i döndürür, negatifi 8 en büyük elemandır (ekrandan, 01:45:00). Fonksiyonun içi değiştirilmez.

- **Ders sonrası not:** Hoca Dijkstra algoritmasının da optimal çözümü vermeyebileceğini söyledi. Doğrusu: Dijkstra, kenar ağırlıkları negatif olmayan çizgelerde en kısa yolları her zaman optimal bulur; açgözlü olduğu hâlde optimal sonuç veren bir algoritmadır.
- **Ders sonrası not:** Hoca $\Omega$'yı en iyi durumla eşledi. Doğrusu: $\Omega$ yalnız asimptotik bir alt sınır gösterimidir ve en kötü, ortalama ya da en iyi durumun herhangi biri için kullanılabilir. Bir problemin alt sınırı ise genellikle o problemi çözen her algoritmanın en kötü durumda yapması gereken en az iş olarak tanımlanır; buna göre sırasız dizide arama problemi için alt sınır $\Omega(n)$, sıralı dizide karşılaştırmaya dayalı arama için $\Omega(\log n)$ olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
