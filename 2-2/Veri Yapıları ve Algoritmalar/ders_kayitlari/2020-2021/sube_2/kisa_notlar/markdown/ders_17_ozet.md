# Ders 17 Çalışma Özeti

## Genel Konular

- Vize sorularının çözümü (dersin ilk bölümü, beyaz tahta üzerinde)
  - Bağlı liste ile dizi karşılaştırması: ekleme ve silmede bağlı liste avantajlıdır (dizide elemanları kaydırmak $O(n)$ sürer). Güncelleme ve aramada dizi daha iyidir (doğrudan indis erişimi; sıralı dizide ikili arama). Min/max bulmada bağlı listenin bir avantajı yoktur. Cevap: 1,2.
  - Sıralı diziden ikili arama ağacı (5, 8, 9, 12, 24, 48, 64): en kötü durumda sırayla eklenen elemanlar zincir (bağlı liste gibi) bir ağaç oluşturur; 6 seviye, kökte 5. En iyi durumda her alt dizinin ortadaki elemanı köke alınır; kökte 12, 2 seviyeli mükemmel (perfect) ikili ağaç. Cevap: 2,6,12,5 (ekrandan, 00:15:00).
  - En uygun veri yapısı: fonksiyon çağrıları için yığıt (function call stack), klavyeden basılan tuşlar için kuyruk (FIFO), dengesiz ikili ağacı saklamak için bağlı liste (dizide boş gözler yer israfıdır), satrançta sonraki hamle için ağaç (ekrandan, 00:20:00).
  - Kuyruktaki 1 2 3 4 elemanları önce yığıta push edilip sonra pop edilerek kuyruğa geri eklenirse kuyruk ters çevrilir: 4 3 2 1. Sorudaki ilk döngüde `enqueueQueue(queue)` yazım hatasıdır, `dequeue` olmalıydı (ekrandan, 00:25:00).
  - İkili arama ağacında 5 aranırken bakılamayacak sıra: 2, 7, 3, 8, 4, 5 (c şıkkı). 7'nin solundaki alt ağaçta 8 bulunamaz (ekrandan, 00:30:00).
  - Min-heap'ten en küçük 3 elemanı silmek: her extract-min $O(\log n)$; $3\log n$ yine $O(\log n)$ (ekrandan, 00:35:00).
  - Parantez dengesi kontrolünde yığıtta aynı anda en fazla açılış parantezi sayısı kadar eleman durabilir: 4 açılış parantezi için cevap 4.
  - İç içe döngü karmaşıklığı: dış döngü $n/2$'den $n$'e ($\approx n/2$ kez), iç döngü `j*=2` ile ($\approx \log n$ kez); toplam $O(n\log n)$ (ekrandan, 00:40:00).
  - Üçlü (ternary) min-heap'ten extract-min: son eleman 15 köke gelir, üç çocuğun en küçüğü (4) ile yer değiştirir. Sonuç dizi: 4 13 15 91 49 29 98 32 30 (ekrandan, 00:45:00).
  - Ara adımlardan sıralama algoritmasını tanıma: I insertion sort, II heap sort (dizi max-heap durumunda), III selection sort (ekrandan, 00:50:00).
  - Seyrek (sparse) matriste tamamen sıfır olan sütunları bulma: sütun sayısı kadar bir işaret dizisi; bağlı liste bir kez gezilir, dolu hücrelerin sütunları elenir. Örnek çıktı 0,3,4 (ekrandan, 00:55:00).
  - Yazıcı kuyruğu: sıradaki işi basan fonksiyon (dequeue + sayfa sayısı kadar döngü) ve kuyruğun ortasından iş silme. Silme, yalnız enqueue/dequeue ile ikinci bir (yedek) kuyruk kullanılarak ya da dairesel kuyrukla yapılır (ekrandan, 01:05:00).
- Öncelikli kuyruk (priority queue)
  - Her elemanın bir anahtar (öncelik) değeri vardır; elemanlar önceliğe göre işlenir. Temelde bir heap ile gerçekleştirilir.
  - Max-priority-queue (max-heap ile): `insert(s,x)`, `max(s)`, `extract_max(s)`, `increase_key(s,x,k)` ($k \ge x$) (ekrandan, 01:50:00).
  - Min-priority-queue: aynı işlemlerin min versiyonları (`extract_min`, `min`).
  - Uygulamalar: işletim sisteminde süreç zamanlayıcı (process scheduler), olay güdümlü simülatör (event-driven simulator), bankadaki sıra numarası sistemi.
- Öncelikli kuyruk işlemlerinin algoritmaları ve C kodu
  - `max`: `A[1]` döndürülür, $O(1)$.
  - `extract_max`: heap boş olmamalı; `max = A[1]`, `A[1] = A[n]`, heap boyutu bir azaltılır, `MAX_HEAPIFY(A, 1, n-1)`; $O(\log n)$ (ekrandan, 02:00:00).
  - `increase_key`: yeni değer eskisinden küçük olamaz; değer yazılır ve ebeveynle karşılaştırılarak yukarı taşınır (ekrandan, 02:05:00).
  - `insert`: heap boyutu bir artırılır, son göze $-\infty$ yazılır, `increase_key` ile anahtar yerleştirilir; $O(\log n)$ (ekrandan, 02:20:00).
  - Yardımcı fonksiyonlar: `get_left_child` ($2i$), `get_right_child` ($2i+1$), `get_parent` ($i/2$); sınır dışında $-1$ döner (ekrandan, 02:10:00).
  - `build_max_heap`: `heap_size/2`'den 1'e kadar geriye doğru her düğüm için `max_heapify` (ekrandan, 02:15:00).
- Huffman ağacı
  - Kayıpsız veri sıkıştırma: sık kullanılan karaktere kısa, az kullanılana uzun kod verilir (ekrandan, 02:25:00).
  - Min-priority-queue kullanılır: en düşük frekanslı iki düğüm çekilir, frekansları toplanarak bir ara düğüm oluşturulur ve kuyruğa geri eklenir. Kuyrukta tek düğüm kalana kadar sürer.
  - Örnek: a:5, b:9, c:12, d:13, e:16, f:45. Kodlar: f=0, c=100, d=101, a=1100, b=1101, e=111 (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kuyruk ile ilgili kod sorusunda fonksiyonun imzası (kuyruk parametresi alıp değer döndürmesi) işlemin dequeue olduğunu gösterir.
  - Hoca dört temel işlemin (enqueue, dequeue, push, pop) imzalarından tanınabilmesi gerektiğini söyledi.
- Kuyruğun ortasından eleman silmek yalnız kuyruk işlemleriyle yapılmalıdır.
  - Dizide arayıp kaydırmak bu soruda kabul edilen yol değildir. Beklenen çözüm yedek kuyrukla boşalt-doldur ya da dairesel kuyruk mantığıdır.
- Öncelikli kuyruk aslında bir heap'tir.
  - Heap'teki bütün işlemler (`max_heapify` etrafında döner) öncelikli kuyruğun işlemlerini birebir karşılar.
  - Gerçek uygulamada heap elemanları struct olur, struct'ın anahtar alanı heap anahtarı olarak kullanılır.
- Huffman'da neden min-priority-queue?
  - Az kullanılan karakterler önce işlenirse ağaçta aşağıda kalır ve uzun kod alır; sık kullanılanlar köke yakın kalır ve kısa kod alır.
- Algoritma sorusu çözmeye şimdiden alışmak önemlidir.
  - İş görüşmelerinde HackerRank, LeetCode gibi platformlardan algoritma soruları sorulduğunu hatırlattı.

## Kısa Tekrar Notları

- Bağlı liste: ekleme/silme kolay; dizi: güncelleme/arama hızlı.
- Sıralı diziden BST: sırayla eklenirse zincir ($n-1$ seviye), ortadan seçilerek eklenirse dengeli.
- Yığıt + kuyruk birlikte kullanılarak kuyruk ters çevrilir.
- BST'de arama yolu: her adımda aranan değer ile karşılaştırılan düğüm arasında kalan aralık daralır; yoldaki bir değer bu aralığın dışındaysa o sıra mümkün değildir.
- $k$ kez extract-min: $O(k\log n)$; $k$ sabitse $O(\log n)$.
- $d$-li heap'te heapify'da $d$ çocuk karşılaştırılır.
- Öncelikli kuyruk işlemleri: `max` $O(1)$; `extract_max`, `increase_key`, `insert` $O(\log n)$.
- `insert` = boyutu artır, $-\infty$ yaz, `increase_key`.
- `decrease_key` = değeri azalt, `max_heapify` ile aşağı taşı.
- Huffman: iki min çek, topla, ara düğüm yap, geri ekle; sola 0, sağa 1.
- Huffman kodları önek (prefix) özelliklidir; bitişik yazılsa da çözülebilir.

## Detaylı Açıklamalar

- Vize çözümünde sıralı diziden ikili arama ağacı sorusu, ağacın yüksekliğinin ekleme sırasına bağlı olduğunu gösterir. 5, 8, 9, 12, 24, 48, 64 sırayla eklendiğinde her yeni eleman bir öncekinin sağına gider ve 7 düğümlü, 6 seviyeli bir zincir oluşur (kök 0. seviye). En iyi durumda ortadaki eleman 12 köke alınır; sol alt dizinin (5, 8, 9) ortası 8, sağ alt dizinin (24, 48, 64) ortası 48 olur. 7 eleman en az 3 seviyeye (0, 1, 2) sığdığı için bundan iyisi yoktur. Hoca AVL ağacının dengeyi döndürme işlemleriyle sağladığını, ama bu soruda bunun bilinmesine gerek olmadığını belirtti.
- İkili arama ağacında arama sırası sorusunda c şıkkı (2, 7, 3, 8, 4, 5) için 2'den sonra sağa gidilir (5 > 2), 7'de sola gidilir (5 < 7). Bu noktadan sonra karşılaşılan her düğüm 2 ile 7 arasında olmalıdır. 3'ten sonra gelen 8 bu aralıkta olmadığından bu sıra bir ikili arama ağacında oluşamaz. Diğer şıklar (10, 9, 8, 7, 6, 5; 1, 10, 2, 9, 3, 5; 1, 2, 10, 4, 8, 5) geçerli ağaçlar verir. Derste bir öğrenci ağaca başka elemanlar da eklenebileceğini sordu. Hoca, soruda yalnız arama sırasında görülen elemanların sorulduğunu ve 7'nin solunda 8'in duramayacağını açıkladı.
- Döngü karmaşıklığı sorusunda dış döngü `i = n/2`'den `n`'e kadar birer artar, yani yaklaşık $n/2$ kez döner. İç döngü `j = 2`'den başlayıp `j *= 2` ile ikiyle çarpılarak `n`'e kadar gider; bu yaklaşık $\log_2 n$ adımdır. İçteki `k += n/2` sabit sayıda işlemdir. Toplam $\frac{n}{2}\log n$ olur, katsayılar atılınca $O(n\log n)$ elde edilir.
- Üçlü min-heap'te her düğümün üç çocuğu vardır ve ağaç complete'tir. Verilen heap dizisi 3, 13, 4, 91, 49, 29, 98, 32, 30, 15'tir (kök 3; çocukları 13, 4, 91; 13'ün çocukları 49, 29, 98; 4'ün çocukları 32, 30, 15). Extract-min ile 3 çıkar, son eleman 15 köke yazılır. 15, çocukları 13, 4, 91'in en küçüğü olan 4 ile yer değiştirir. Yeni konumunda çocukları 32 ve 30'dan küçük olduğu için durur. Sonuç: 4 13 15 91 49 29 98 32 30.
- Sıralama algoritmasını ara adımdan tanıma sorusunda selection sort her iterasyonda kalanların en küçüğünü sıradaki göze koyar. Bu yüzden dizinin başında genel sıralamanın ilk elemanları (been, from, good, ...) yer alır. Heap sort sütununda dizi büyükten küçüğe bir max-heap düzenindedir (kökte your, çocukları with ve will). Insertion sort sütununda ilk 12 eleman kendi içinde sıralıdır; son 4 eleman (want, been, that, good) henüz yerine yerleşmemiştir.
- Seyrek matris sorusunda her dolu hücre bağlı listede (satır, sütun, değer, next) düğümü olarak tutulur. Çözüm için sütun sayısı kadar bir dizi açılır ve hepsine 1 ("tamamen sıfır olabilir") yazılır. Liste bir kez gezilirken her düğümün sütun gözü 0 yapılır. Sonda 1 kalan gözler tamamen sıfır olan sütunlardır. Örnekte (0,1,3), (0,6,1), (1,2,2), (1,6,4), ... (5,5,5) düğümleri sonucunda 0, 3 ve 4. sütunlar kalır.
- Yazıcı kuyruğunda bir işi aradan silmek için ana kuyruktan dequeue edilen her iş, silinecek iş değilse yedek kuyruğa enqueue edilir; silinecek iş bulunduğunda hiçbir yere eklenmez. Ana kuyruk boşalınca iki yol vardır: yedek kuyruktaki işler aynı şekilde ana kuyruğa geri aktarılır ya da bundan sonra yedek kuyruk ana kuyruk olarak kullanılır (hangi kuyruğun kullanıldığını tutan bir işaret/pointer ile). Bir öğrencinin önerdiği üçüncü yol, eleman sayısı bilindiği için aynı kuyrukta dequeue edip yeniden enqueue ederek tam bir tur dönmektir (dairesel kuyruk mantığı).
- Öncelikli kuyrukta işletim sistemi örneği: her sürecin bir öncelik değeri vardır. Bir iş bittiğinde ya da kesintiye uğradığında zamanlayıcı `extract_max` ile sıradaki en yüksek öncelikli süreci alır. Zamanlayıcı her an `insert` ile yeni iş ekleyebilir ve gerektiğinde bir işin önceliğini artırabilir ya da azaltabilir. Banka örneğinde ise küçük numara önceliklidir (min-priority-queue): sıra numarası 342, 343 olan müşterilerin önüne daha küçük numara (örneğin 120, sonra 10) alan müşteriler geçer ve `extract_min` her seferinde en küçük numarayı çağırır.
- `extract_max` örneğinde (heap: 20; 15, 8; 10, 5, 7, 6; 2, 9, 1) 20 çıkarılır, son eleman 1 köke gelir. 1; 15 ve 8 ile karşılaştırılır, 15 yukarı çıkar. Sonra 10 ve 5 ile karşılaştırılır, 10 yukarı çıkar. Sonra 2 ve 9 ile karşılaştırılır, 9 yukarı çıkar ve 1 yaprağa iner. `increase_key` örneğinde (a) heap 16; 14, 10; 8, 7, 9, 3; 2, 4, 1 iken 4 değeri 15 yapılır. 15 önce 8 ile, sonra 14 ile yer değiştirir; 16'dan küçük olduğu için orada durur (ekrandan, 02:05:00).
- Huffman örneğinde min-priority-queue başta 5, 9, 12, 13, 16, 45 içerir. Adımlar: 5+9=14; 12+13=25; 14+16=30; 25+30=55; 45+55=100. Kökten sola 0, sağa 1 verilir. "fbfdc" dizgisi sabit 8 bitlik kodla $5 \times 8 = 40$ bit tutarken Huffman kodlarıyla 0 1101 0 101 100 = 12 bit tutar. Bu, %70 tasarruf demektir. Ağacın (kod tablosunun) da karşı tarafa gönderilmesi gerekir, ama büyük metinlerde bu ek yük oranı çok değiştirmez.
  - Ders sonrası not: Hoca Huffman algoritmasını özetlerken kuyrukta kalan son düğümün "en yüksek frekansa sahip karakter" olduğunu söyledi. Doğrusu, kalan son düğüm bir karakter değil, ağacın köküdür ve değeri bütün frekansların toplamıdır (örnekte 100).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
