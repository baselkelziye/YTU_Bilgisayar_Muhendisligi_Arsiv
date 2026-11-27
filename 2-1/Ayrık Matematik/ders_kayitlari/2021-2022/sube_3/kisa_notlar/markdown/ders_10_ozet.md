# Ders 10 Çalışma Özeti

## Genel Konular

- Ağaçlarda gezinme (tree traversal)
  - Ağaçtaki düğümler rastgele değil, belirli bir kurala göre okunur. Ağacın ikili (binary) olması gerekmez.
  - Pre-order (önden sıralı): önce kök $r$, sonra alt ağaçlar soldan sağa: $r\,T_1\,T_2\dots T_n$.
  - In-order (içten sıralı): önce en soldaki alt ağaç $T_1$, sonra kök, sonra kalan alt ağaçlar: $T_1\,r\,T_2\dots T_n$.
  - Post-order (sondan sıralı): önce alt ağaçlar soldan sağa, en son kök: $T_1\,T_2\dots T_n\,r$.
  - Reverse post-order (ters önden sıralı): kitaplarda geçtiği için gösterildi, pek kullanılmaz.
  - Her alt ağaca aynı kural yinelemeli olarak uygulanır.
  - Yalnızca bir okunuş (örneğin yalnız post-order) ağacı çizmeye yetmez; düğüm seviyeleri, yükseklik ya da ebeveyn-çocuk bilgisi gibi ek bilgi gerekir.
- Huffman kodlama
  - Sembollere (karakter, kelime, piksel rengi) kullanım sıklığına göre değişken uzunlukta ikili kod atanır. JPEG, gzip ve faks gibi uygulamalarda kullanılır.
  - Huffman ağacı her zaman ikili ağaçtır. Yapraklar sembollerdir; sol dal 0, sağ dal 1 ile etiketlenir.
  - Sık kullanılan sembol az bitle, seyrek kullanılan sembol çok bitle kodlanır. Böylece 8 bitlik ASCII kodlamaya göre sıkıştırma sağlanır.
  - Kodlar kökten yaprağa (yukarıdan aşağıya) okunur. Hiçbir kod başka bir kodun başlangıcı (öneki) olmaz; bu sayede sıkıştırılan metin geri açılabilir.
- Kapsayan ağaç (spanning tree)
  - Bir grafın bütün düğümlerini içeren ve kapalı döngü içermeyen alt ağaçtır. Bir grafın birçok farklı kapsayan ağacı olabilir.
  - Ağırlıksız graflarda DFS ve BFS ile bulunur.
- DFS (Depth First Search, derin öncelikli arama)
  - Başlangıç düğümünden gidilebilecek en uzak düğüme kadar gidilir, sonra geri dönülür. Yığın (stack) kullanılır.
- BFS (Breadth First Search, geniş öncelikli arama)
  - Düğümler seviye seviye ziyaret edilir: bir seviyedeki bütün düğümler bitmeden alt seviyeye geçilmez. Kuyruk (queue) kullanılır.
- Minimum kapsayan ağaç (minimal spanning tree)
  - Ağırlıklı grafta, bütün düğümleri bağlayan ve kenar ağırlıkları toplamı en küçük olan kapsayan ağaçtır.
  - Prim algoritması: komşuluk (maliyet) matrisi üzerinde, ağaca eklenmiş düğümlerden çıkan en küçük kenar seçilerek ilerlenir.
  - Kruskal algoritması: kenarlar küçükten büyüğe sıralanır, kapalı döngü oluşturmayan en küçük kenar seçilir; $n$ düğüm için $n-1$ kenar seçilince durulur.
- Ağaçlarda izomorfizm (benzerlik)
  - Köksüz ağaçlarda düğüm sayısı, kenar sayısı ve karşılıklı düğüm dereceleri aynı olmalıdır.
  - Köklü ağaçlarda ayrıca kökler eşleşmelidir ("kökünden tutup üzüm salkımı gibi sallamak").
  - İkili ağaçlarda ayrıca çocukların sol/sağ konumları aynı olmalıdır.
- Karar ağaçları (decision trees)
  - Her iç düğüm bir soru, her dal bir cevap, her yaprak bir karardır.
  - Beş para problemi: biri sahte olan beş paradan sahtesini ve ağır/hafif olduğunu bulmak için terazi tartıları.
  - Tenis veri seti: 14 gün, 4 özellik (outlook, temperature, humidity, wind). Özellik sırası entropi ve bilgi kazancı (information gain) ile seçilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Gezinme türlerinde her alt ağaca aynı kuralın uygulanması
  - Pre-order'da kök önce, post-order'da kök en son gelir; in-order'da en soldaki alt ağaç bittikten sonra kök okunur.
- Huffman dizisinin genişletilmesinde iki önemli kural
  - $n$ sembol varsa genişletilmiş dizi $2n-1$ elemanlı olur.
  - Toplamlar mutlak değerle alınır; toplamlardan oluşan değerlerin önüne eksi konur. Eksi işaretli değerle işaretli toplama yapılırsa yanlış ağaç çıkar.
  - Bir toplam, iki değer bir kez toplandıktan sonra tekrar kullanılmaz; sıradaki ikili alınır.
  - Eşit değerde toplam soluna mı sağına mı yerleştirilecekse, o kural baştan sona tutarlı uygulanmalıdır.
- Huffman kodlarının yukarıdan aşağıya okunması
  - Aşağıdan yukarıya okunursa bir kod başka bir kodun başlangıcı olur ve sıkıştırılmış veri geri açılamaz.
- Kruskal'da durma koşulu
  - Bütün düğümlere dokunulmuş olması yetmez; graf parçalı kalabilir. $n$ düğüm için $n-1$ kenar seçilmiş olmalıdır.
- İzomorfizm olmadığını göstermek daha kolaydır
  - İzomorfizm için bütün şartlar sağlanmalıdır; izomorf olmadığını göstermek için tek bir şartın bozulması yeter.
- Karar ağacında amaç en az soruyla karara ulaşmaktır
  - Özellikleri rastgele yerleştirmek yerine bilgi kazancı en yüksek özellik köke konur.

## Kısa Tekrar Notları

- Pre-order: $r\,T_1\dots T_n$; in-order: $T_1\,r\,T_2\dots T_n$; post-order: $T_1\dots T_n\,r$.
- Huffman: sıklıkları küçükten büyüğe sırala; soldan ikişer topla; toplamı eksi işaretiyle sırayı bozmadan yerleştir; $2n-1$ elemana genişlet.
- Ağacı kur: en sondaki eleman kök; bir eksi değerin iki bileşeninden önce okunan sola, sonra okunan sağa; eksi değer ara düğüm, artı değer yapraktır.
- Sol dal 0, sağ dal 1; kod kökten yaprağa okunur. Kodlar önek koşulunu sağlar.
- Örnek: $a{:}25, e{:}14, k{:}8, l{:}7, m{:}4, z{:}2$ için kodlar $1, 01, 001, 0000, 00010, 00011$; 480 bit yerine 135 bit.
- DFS: yığın; en derine git, sonra geri dön. BFS: kuyruk; seviye seviye ilerle.
- Prim: matriste ziyaret edilen düğümlerin satırlarındaki, ziyaret edilmemiş düğümlere giden en küçük değeri seç.
- Kruskal: kenarları sırala, döngü oluşturmayan en küçüğü seç, $n-1$ kenarda dur.
- $n$ düğümlü farklı (izomorf olmayan) ikili ağaç sayısı: $\binom{2n}{n}/(n+1)$; $n=3$ için 5.
- Entropi: $E(S) = -p_{+}\log_2 p_{+} - p_{-}\log_2 p_{-}$. Hepsi aynı sınıfta ise 0, eşit dağılmışsa 1.
- Bilgi kazancı: $\mathrm{Gain}(S,A) = E(S) - \sum_{v} \frac{|S_v|}{|S|} E(S_v)$; en büyük kazanç veren özellik köke konur.

## Detaylı Açıklamalar

- Ağaçlarda gezinme. Örnek ağaçta kök $a$'nın çocukları $b, c, d$; $b$'nin çocukları $e, f$; $e$'nin çocukları $j, k$; $k$'nın çocukları $n, o, p$; $d$'nin çocukları $g, h, i$; $g$'nin çocukları $l, m$'dir (ekrandan, 00:10:00). Bu ağacın okunuşları:
  - Pre-order: $a, b, e, j, k, n, o, p, f, c, d, g, l, m, h, i$.
  - In-order: $j, e, n, k, o, p, b, f, a, c, l, g, m, d, h, i$.
  - Post-order: $j, n, o, p, k, e, f, b, c, l, m, g, h, i, d, a$.
  - Derste pre-order okunurken $b$'nin sağ çocuğu $f$ önce atlandı, bir öğrencinin uyarısıyla düzeltildi. Sonuçlar python ile kontrol edildi.
- Huffman kodlama mantığı. Bir metinde boşluk karakteri 10.000, $a$ 100, $j$ 5 kez geçsin. 8 bitle kodlanırsa $80.000 + 800 + 40 = 80.840$ bit gerekir. Boşluk 2, $a$ 7, $j$ 12 bitle kodlanırsa $20.000 + 700 + 60 = 20.760$ bit yeter; yaklaşık dörtte birine iner (ekrandan, 00:30:00).
- Huffman örneği (ekrandan, 00:30:00 - 00:50:00). Semboller $a, e, k, l, m, z$; sıklıklar 25, 14, 8, 7, 4, 2.
  - Adım 1: sıralı dizi $2, 4, 7, 8, 14, 25$.
  - Adım 2: genişletilmiş dizi ($2\cdot 6-1=11$ eleman): $2, 4, -6, 7, 8, -13, 14, -21, 25, -35, -60$. İkililer $(2,4)\to 6$, $(6,7)\to 13$, $(8,13)\to 21$, $(14,21)\to 35$, $(25,35)\to 60$.
  - Adım 3: kök $-60$; çocukları sol $-35$, sağ $25$ ($a$); $-35$'in çocukları $-21$ ve $14$ ($e$); $-21$'in çocukları $-13$ ve $8$ ($k$); $-13$'ün çocukları $7$ ($l$) ve $-6$; $-6$'nın çocukları $4$ ($m$) ve $2$ ($z$).
  - Adım 4: kodlar $a\to 1$, $e\to 01$, $k\to 001$, $l\to 0000$, $m\to 00010$, $z\to 00011$.
  - Bit hesabı: 8 bitle $60\cdot 8 = 480$ bit; Huffman ile $25\cdot1 + 14\cdot2 + 8\cdot3 + 7\cdot4 + 4\cdot5 + 2\cdot5 = 135$ bit (python ile kontrol edildi).
  - Kodlar aşağıdan yukarıya okunsaydı $a\to1$, $e\to10$, $k\to100$ gibi kodlar çıkardı. "kek" kelimesi $100\,10\,100$ olur; açarken ilk $1$ bir sembol ($a$) sayılır ve kalan bitler hiçbir koda uymaz. Bu yüzden kodlar yukarıdan aşağıya okunur.
- İkinci genişletme örneği (ekrandan, 00:35:00). Sıklıklar $1, 1, 2, 5, 7, 15$. İkililer $(1,1)\to 2$, $(2,2)\to 4$, $(4,5)\to 9$, $(7,9)\to 16$, $(15,16)\to 31$. Eşit iki $2$ değerinden toplamın hangi yana yazılacağı bu ders için önemli değildir; ama seçilen kural hep aynı uygulanmalıdır.
- DFS örneği (ekrandan, 01:10:00). Graf kenarları: $A\!-\!B$, $A\!-\!H$, $A\!-\!D$, $D\!-\!F$, $B\!-\!E$, $B\!-\!C$; başlangıç $A$. Yığın adımları: Push(A), Push(D), Push(F), Pop, Pop, Push(H), Pop, Push(B), Push(E), Pop, Push(C), Pop, Pop, Pop. Çıktı: $A, D, F, H, B, E, C$.
- BFS örneği (ekrandan, 01:20:00). Graf kenarları: $A\!-\!B$, $A\!-\!C$, $B\!-\!F$, $C\!-\!E$, $C\!-\!D$, $D\!-\!H$, $H\!-\!J$; başlangıç $A$. Kuyruk: A; B-C; C-F; F-E-D; E-D; D; H; J. Çıktı: $A, B, C, F, E, D, H, J$. Hoca, suya atılan taşın oluşturduğu halkalar benzetmesiyle seviye kavramını anlattı.
- Prim örneği (ekrandan, 01:30:00 - 01:35:00). Yedi düğüm (köydeki evler, düğüm 1 su deposu); M doğrudan bağlantı olmadığını gösteren çok büyük sayıdır. Seçim sırası: $1\!-\!3$ (100), $1\!-\!4$ (300), $1\!-\!7$ (400), $3\!-\!5$ (500), $5\!-\!6$ (200), $7\!-\!2$ (900). Toplam maliyet 2400.
  - Ders sonrası not: hoca toplamı sözlü olarak 2600 diye hesapladı; kenar ağırlıklarının toplamı $100+300+400+500+200+900 = 2400$'dür (python ile kontrol edildi).
- Kruskal örneği (ekrandan, 01:45:00). 3x3 düzende 9 düğümlü bir grafta seçilen kenarlar ağırlık sırasıyla 1, 2, 2, 3, 3, 3, 4, 4; 8 kenar, toplam 22. Derste bütün düğümlere dokunulduğu hâlde bir parçanın ayrı kaldığı, bu yüzden $n-1$ kenar kuralının kontrol edilmesi gerektiği gösterildi.
- Kapalı döngü kontrolü: $BD$ ve $BE$ seçilmişse $DE$ seçilmez; geçişlilik (transitivity) gibi düşünülebilir.
- Karar ağacı ve entropi. Tenis veri setinde 9 "yes", 5 "no" vardır; $E(S) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} \approx 0{,}940$. Rüzgar için weak $[6+,2-]$ ($E\approx0{,}811$), strong $[3+,3-]$ ($E=1$) ve $\mathrm{Gain}(S,\text{wind}) \approx 0{,}048$ (ekrandan, 02:35:00). Seçilen ağaçta kök outlook'tur: overcast doğrudan "yes", sunny altında humidity (high "no", normal "yes"), rainy altında wind sorulur. Sıcaklık hiç kullanılmaz ve en çok iki soruyla karar verilir.
  - Ders sonrası not: hoca entropi ne kadar büyükse sistemin soruya o kadar iyi cevap vereceğini söyledi; doğrusu tersidir. Entropi belirsizliğin (karışıklığın) ölçüsüdür; yüksek entropi sınıfların karışık olduğunu gösterir. Bu yüzden bölme sonrasında entropiyi en çok düşüren, yani bilgi kazancı en büyük olan özellik seçilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
