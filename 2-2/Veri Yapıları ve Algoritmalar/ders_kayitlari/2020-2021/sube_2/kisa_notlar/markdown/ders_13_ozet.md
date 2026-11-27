# Ders 13 Çalışma Özeti

## Genel Konular

- Quiz 2 sorularının çözümü (dersin ilk bölümü, beyaz tahta üzerinde)
  - İkili arama ağacında preorder (kök önde, VLR) gezinti: kök 25, solunda 19 (çocukları 5 ve 22), 5'in sağ çocuğu 8, 22'nin sol çocuğu 20; sağda 37, onun sağ çocuğu 44, 44'ün çocukları 41 ve 50. Gezinti sırası: 25, 19, 5, 8, 22, 20, 37, 44, 41, 50 (ekrandan, 00:10:00).
  - Josephus (Romalı) problemi: 21 kişilik sınıfta 1'den başlayarak her 3. kişi elenir; son kalan iki kişi 2 ve 16 numaralılardır. Dairesel bağlı listeyle kolayca gerçeklenir.
  - Push, pop ve reverse işlemleri olan özel bir yığıtla (stack) kuyruk (queue) gerçeklemek: enqueue = push; dequeue = reverse, pop, reverse (ekrandan, 00:15:00).
  - "Casus string" çözme: `abcde2fgh1ijk0lmn3oprs1` dizisinde harfler push edilir, bir rakam $k$ görülünce $k$ kez pop yapılır (ekrandan, 00:20:00). Kalan 11 karakter `abcfgijkopr` olur; toplam 18 push ve 18 pop yapılır. Uygun veri yapısı yığıttır, toplam süre $O(n)$.
  - Doğru-yanlış soruları: derleyiciler ağaç yapısı kullanabilir (D); derleyiciler yığıt kullanabilir, fonksiyon çağrı yığıtı (D); dosya sistemleri ikili ağaç kullanır (Y, çok çocuklu ağaç kullanır); çift bağlı listede bir elemanı silmek için o elemanın adresi yeterlidir (D); $n$ elemanlı sıralı diziye en kötü durumda gelen yeni bir elemanı insertion sort da bubble sort da $O(n)$'de yerleştirir (Y, bubble sort $O(n^2)$). Cevap anahtarı: D, D, Y, D, Y.
  - `for (k = 1; k < n; k = k * 2) sum++;` döngüsünde toplama sayısı $\log n$ mertebesindedir; çünkü $k$ ikiyle çarpılarak büyür.
  - En iyi algoritmayla en kötü durum arama karmaşıklıkları: sırasız dizi $O(n)$, sıralı dizi $O(\log n)$ (ikili arama), sıralı bağlı liste $O(n)$, sıralı çift yönlü bağlı liste $O(n)$. Soru sıralama istemiyordu, her durum için karmaşıklık istiyordu.
  - Labirentte çıkış arayan fare problemi için en uygun veri yapısı yığıttır: yapılan hamleler (sol, sağ, yukarı, aşağı) yığıta konur, çıkmaza girilince son hamle ilk geri alınır (bir "undo" problemi).
  - `mystery` fonksiyonu bağlı listeyi özyinelemeli olarak sondan başa yazdırır: 2, 4, 6, 8 listesi için çıktı `8 6 4 2` olur (ekrandan, 00:40:00).
  - $n$ elemanlı dizi üzerindeki dairesel kuyrukta yeni eleman `(rear + 1) % n` gözüne eklenir; mod işlemi başa dönmeyi sağlar.
- İkili arama ağacı tekrarı (önceki haftanın konusu)
  - Tanım: her düğüm için sol alt ağaçtaki değerler küçük, sağ alt ağaçtaki değerler büyüktür.
  - Arama: kökten başlanır, aranan değer küçükse sola, büyükse sağa gidilir. Slayt örneğinde 25 aranırken 44 → 17 → 32 → 28 → boş (bulunamadı), 76 aranırken 44 → 88 → 65 → 82 → 76 (bulundu) yolu izlenir (ekrandan, 00:45:00).
  - Ekleme: arama gibi ilerlenir, ilk boş (NULL) yere yeni düğüm yaratılır. 25 eklenince 28'in sol çocuğu, 75 eklenince 76'nın sol çocuğu olur.
  - Silmenin üç durumu: yaprak düğüm doğrudan silinir; tek çocuklu düğümün çocuğu dedeye (silinen düğümün ebeveynine) bağlanır ve düğüm `free` edilir; iki çocuklu düğümde sol alt ağacın en büyüğü ya da sağ alt ağacın en küçüğü düğüme kopyalanır, sonra o düğüm silinir (ekrandan, 00:55:00).
  - Ağacın yüksekliği: $n$ elemanlı ağaç en kötü durumda $n$ yüksekliğe ulaşır (bağlı listeye döner); rastgele ekleme ve silmelerde ortalama yükseklik $O(\log_2 n)$'dir. Arama, ekleme, silme $O(h)$; en kötü durum $O(n)$. Önlem: AVL, Splay, B-Tree (2-3, 2-3-4), red-black tree gibi dengeleme politikaları (ekrandan, 01:00:00).
- Heap (ikili heap) veri yapısı
  - Neredeyse tam ikili ağaç (complete binary tree) şeklindedir: son düzey hariç tüm düzeyler doludur, son düzey soldan dolar (ekrandan, 01:15:00).
  - Java ve Lisp gibi dillerdeki garbage-collected bellek alanı olan "heap" ile bu veri yapısının hiçbir ilgisi yoktur.
  - Heap özelliği: her düğümün değeri çocuklarından büyük (max-heap, $A[\text{parent}(i)] \ge A[i]$) ya da küçüktür (min-heap, $A[\text{parent}(i)] \le A[i]$). Sonuç olarak en büyük (max-heap) ya da en küçük (min-heap) eleman köktedir ve $O(1)$'de okunur.
  - İkili arama ağacından farkı: sol çocuğun küçük, sağ çocuğun büyük olması gibi bir garanti yoktur; tek garanti ebeveynin çocuklardan büyük (ya da küçük) olmasıdır.
  - Heap olmama nedenleri: tam ikili ağaç yapısının bozulması (örneğin bir düğümün sol çocuğu yokken sağ çocuğu olması) ya da bir çocuğun ebeveyninden büyük olması (ekrandan, 01:25:00).
  - Dizi ile gösterim: kök $A[1]$'dedir (0. göz kullanılmaz), $0 \le A.\text{heap\_size} \le A.\text{length}$. $i$ gözündeki düğüm için ebeveyn $A[\lfloor i/2 \rfloor]$, sol çocuk $A[2i]$, sağ çocuk $A[2i+1]$. Ebeveyn düğümler dizinin ilk $n/2$ elemanındadır, kalanlar yapraktır. Heap yüksekliği $\lg n$'dir (ekrandan, 01:30:00).
- Heap oluşturma ve temel işlemler
  - Bottom-up oluşturma (BUILD-MAX-HEAP): son ebeveyn olan $n/2$'den 1'e kadar her düğüm için MAX-HEAPIFY çağrılır (ekrandan, 01:40:00).
  - MAX-HEAPIFY: düğüm, sol ve sağ çocuğu arasından en büyüğü (largest) bulunur; largest düğümün kendisi değilse yer değiştirilir ve aşağıda kalan alt ağaçta MAX-HEAPIFY yeniden çağrılır. Maliyet $O(\log n)$.
  - Örnek 1: 2, 9, 7, 6, 5, 8 → max-heap 9, 6, 8, 2, 5, 7 (ekrandan, 01:45:00). Örnek 2: 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 → 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 (ekrandan, 01:50:00).
  - En büyük elemanı almak: heap boş olmamalı; kök `max`'a kopyalanır, son eleman köke yazılır, heap boyutu bir azaltılır ve kökte MAX-HEAPIFY çağrılır; `max` döndürülür. Maliyet $O(\lg n)$ (ekrandan, 01:55:00).
  - Bir düğümün değerini artırmak (HEAP-INCREASE-KEY): yeni değer mevcut değerden büyük-eşit olmalıdır; düğüm, ebeveyninden büyük olduğu sürece ebeveyniyle yer değiştirerek yukarı çıkar. Maliyet $O(\lg n)$ (ekrandan, 02:10:00).
  - Yeni eleman eklemek (MAX-HEAP-INSERT): heap boyutu bir artırılır, son göze $-\infty$ yazılır, sonra HEAP-INCREASE-KEY ile bu göz yeni değere yükseltilir. Maliyet $O(\lg n)$.
  - Top-down oluşturma (BUILD-MAX-HEAP-2): elemanlar 2'den $n$'e kadar sırayla MAX-HEAP-INSERT ile eklenir. 1, 2, 3 dizisi için bottom-up 3, 2, 1; top-down 3, 1, 2 verir. İkisi de geçerli heap'tir ama aynı olmak zorunda değildir (ekrandan, 02:25:00).
- Heap sort
  - Önce BUILD-MAX-HEAP ile heap kurulur. Sonra her adımda kök (en büyük eleman) heap'in son elemanıyla yer değiştirir, heap boyutu bir azaltılır ve kökte MAX-HEAPIFY çağrılır. Bu işlem heap'te tek eleman kalana kadar sürer.
  - Örnek 1: 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 heap'inden 1, 2, 3, 4, 7, 8, 9, 10, 14, 16 elde edilir (ekrandan, 02:30:00).
  - Örnek 2: 2, 9, 7, 6, 5, 8 → heap 9, 6, 8, 2, 5, 7 → sıralı 2, 5, 6, 7, 8, 9 (ekrandan, 02:45:00).
  - Karmaşıklık: $n$ eleman için her biri $O(\log n)$ olan işlem yapıldığından toplam $O(n \log n)$, en kötü durumda da öyledir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Heap veri yapısı ile programlama dillerindeki heap bellek alanı tamamen farklı kavramlardır; aynı adı taşımaları tesadüftür.
  - Hoca slayttaki "değildir" kelimesinin altını kırmızıyla çizdi. Java'daki "not enough heap space" hatasıyla ilgisi yoktur.
- Heap'in tek garantisi ebeveynin çocuklardan büyük (ya da küçük) olması ve tam ikili ağaç yapısıdır.
  - Sol-sağ çocuk arasında bir sıra garantisi yoktur; bu yüzden aynı diziden farklı yöntemlerle farklı (ama geçerli) heap'ler oluşabilir.
- MAX-HEAPIFY'da yer değiştirme yapıldıysa aşağıya doğru kontrol sürmelidir.
  - Yalnız bir düğümü çocuklarıyla karşılaştırıp bırakmak yetmez; aşağı inen değer torunlarından da küçük olabilir.
- Heap'te değer artırma ve eklemede yalnız ebeveynlerle karşılaştırmak yeterlidir.
  - Yukarı çıkan değer, eski ebeveynden büyük olduğu için onun çocuklarından da büyüktür; kardeşlere bakmaya gerek yoktur.
- Heap'i dizide 1. gözden başlatmak, ebeveyn ve çocuk aritmetiğini ($i/2$, $2i$, $2i+1$) basitleştirir.
- Soru metnini dikkatli okumak gerekir.
  - Dosya sistemleri sorusunda "ikili" kelimesi hızlı okurken gözden kaçabilir. Karmaşıklık sorusu da sıralama istemiyordu, her senaryonun karmaşıklığını istiyordu.

## Kısa Tekrar Notları

- Reverse destekli yığıtla kuyruk: enqueue = push; dequeue = reverse + pop + reverse.
- Casus string çözme ve labirent problemi yığıtla doğal biçimde çözülür (son yapılan ilk geri alınır).
- Çift bağlı listede tek bir düğüm işaretçisiyle silme yapılabilir; dört bağın güncelleme sırasına dikkat edilir.
- Dairesel kuyrukta sonraki göz: `(rear + 1) % n`.
- İkili arama ağacında silme: yaprak → doğrudan sil; tek çocuk → çocuğu dedeye bağla; iki çocuk → sol alt ağacın en büyüğü ya da sağ alt ağacın en küçüğüyle değiştir.
- Max-heap: $A[\text{parent}(i)] \ge A[i]$, kök en büyük; min-heap: tersi.
- Dizi gösterimi: ebeveyn $\lfloor i/2 \rfloor$, sol $2i$, sağ $2i+1$; ebeveynler ilk $n/2$ gözde.
- BUILD-MAX-HEAP: `for i = n/2 downto 1: MAX-HEAPIFY(A, i, n)`.
- Heap'ten en büyüğü alma, değer artırma ve ekleme $O(\lg n)$.
- Heap sort $O(n \log n)$ (en kötü durumda da).

## Detaylı Açıklamalar

- Özel yığıtla kuyruk gerçeklemek
  - Yığıt LIFO, kuyruk FIFO çalışır. Kuyruğa eklenen eleman en son çıkacağı için yığıtın üstüne push etmek enqueue için yeterlidir. Kuyruktan çıkması gereken eleman ise yığıtın dibindedir. $n$ kez pop yapmak yerine yığıt reverse edilir, en üste gelen eleman pop edilir, yığıt yeniden reverse edilerek eski düzene getirilir. Örneğin 1, 2, 3, 4 (dipten üste) yığıtında reverse ile 4, 3, 2, 1 olur, pop ile 1 alınır, ikinci reverse ile 2, 3, 4 kalır.
- Casus string ve dizi ile karşılaştırma
  - Yığıtla her karakter bir kez işlenir, push ve pop $O(1)$ olduğundan toplam $O(n)$'dir. Aynı iş dizide yapılsaydı her rakam için geriye doğru silme yapan iç döngüler gerekirdi. Hoca bunun dikkatli yazılmazsa $n^2$ mertebesine çıkabileceğini söyledi.
- İki çocuklu düğüm silme örneği (ekrandan, 00:55:00)
  - Ağaç: 94'ün çocukları 10 ve 97; 10'un çocukları 5 ve 24; 24'ün sol çocuğu 11; 11'in sağ çocuğu 17. Hoca 5'e çocuk olarak 2 ve 8 ekledi.
  - 10 silinirken birinci seçenek sol alt ağacın en büyüğü olan 8'dir. 8, 10'un yerine yazılır ve eski 8 (yaprak) silinir. Sonuç: 94 → (8, 97); 8 → (5, 24); 5 → 2; 24 → 11 → 17.
  - İkinci seçenek sağ alt ağacın en küçüğü olan 11'dir. 11, 10'un yerine kopyalanır, sonra eski 11 tek çocuklu düğüm olarak silinir (17, 24'e bağlanır). Slayttaki not: sağ alt ağaçtaki en küçük değeri içeren düğümün en fazla bir çocuğu olabilir.
- Heap oluşturma örneği 2'nin adımları (ekrandan, 01:50:00)
  - Dizi 4, 1, 3, 2, 16, 9, 10, 14, 8, 7; $n/2 = 5$.
  - $i=5$ (16): çocuğu 7, değişiklik yok. $i=4$ (2): çocukları 14 ve 8, 14 ile yer değiştirir. $i=3$ (3): çocukları 9 ve 10, 10 ile yer değiştirir.
  - $i=2$ (1): çocukları 14 ve 16, 16 ile yer değiştirir; sonra 1 çocuğu 7 ile yer değiştirir. $i=1$ (4): 16 ile, sonra 14 ile, sonra 8 ile yer değiştirir.
  - Sonuç: 16, 14, 10, 8, 7, 9, 3, 2, 4, 1.
- En büyük elemanı alma örneği (ekrandan, 02:05:00)
  - Heap: 20, 15, 8, 10, 5, 7, 6, 2, 9, 1. 20 alınır, son eleman 1 köke yazılır, heap boyutu 9 olur.
  - MAX-HEAPIFY: 1 önce 15 ile, sonra 10 ile, sonra 9 ile yer değiştirir. Yeni heap: 15, 10, 8, 9, 5, 7, 6, 2, 1.
- Değer artırma örneği (ekrandan, 02:15:00)
  - Heap 16, 14, 10, 8, 7, 9, 3, 2, 4, 1'de 9. gözdeki 4 değeri 15 yapılır. 15 > 8 olduğu için yer değiştirir, sonra 15 > 14 olduğu için yine yer değiştirir; 16'dan küçük olduğu için durur. Sonuç: 16, 15, 10, 14, 7, 9, 3, 2, 8, 1.
- Heap sort örneği 2'nin dizi üzerinde izlenmesi (ekrandan, 02:45:00)
  - Aşama 1 (heap oluşturma): 2 9 7 6 5 8 → 2 9 8 6 5 7 → 9 2 8 6 5 7 → 9 6 8 2 5 7.
  - Aşama 2 (kök/son değiştirme, `|` sağı sıralı kısım): 7 6 8 2 5 | 9 → 8 6 7 2 5 | 9 → 5 6 7 2 | 8 9 → 7 6 5 2 | 8 9 → 2 6 5 | 7 8 9 → 6 2 5 | 7 8 9 → 5 2 | 6 7 8 9 → 2 | 5 6 7 8 9.
- Ders sonrası notlar
  - Hoca casus string sorusunda "18 tane rakam" dedi; doğrusu 18 harftir (push edilen karakterler harflerdir).
  - Hoca ikili arama ağacında aramanın $\log n$ olduğunu söylerken yüksekliğin en fazla $\log n$ olacağını belirtti. Doğrusu bu yalnız dengeli ağaçlar için geçerlidir; dengesiz ağaçta yükseklik $n$'e ulaşabilir (hoca bunu dersin devamında söyledi).
  - Hoca heap sortun "$n^2$'den $\log n$'e" düşürdüğünü söyledi; doğrusu $n^2$'den $n \log n$'edir.
  - Hoca iki heap oluşturma yönteminin de kabaca $n \log n$ olduğunu söyledi. Slaytta BUILD-MAX-HEAP için $O(N)$ yazıyor; bottom-up yöntemin sıkı sınırı $O(n)$'dir, top-down yöntem en kötü durumda $O(n \log n)$'dir.
  - Slayttaki MAX-HEAPIFY sözde kodunda koşul "if largest = i then" olarak görünüyor; doğrusu "if largest ≠ i then"dir (yer değiştirme yalnız largest düğümün kendisi değilse yapılır).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
