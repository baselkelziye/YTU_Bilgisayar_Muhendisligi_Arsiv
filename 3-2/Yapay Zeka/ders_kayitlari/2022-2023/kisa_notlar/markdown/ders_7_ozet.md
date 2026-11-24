# Ders 7 Çalışma Özeti

## Genel Konular

- Oyunların sınıflandırılması
  - Oyunlar iki boyutta incelenir: deterministik / şans içeren ve tam bilgili (perfect information) / eksik bilgili (imperfect information).
  - Şans içeren oyunlarda zar atma, kart çekme gibi oyuncuların kesin olarak belirleyemediği bileşenler vardır.
  - Tam bilgili oyunda (satranç) oyuncular bütün tahtayı görür; eksik bilgili oyunda (okey, poker) rakibin elindeki taşlar ya da kartlar görünmez.
  - Oyunlarla ilgili bu konu, derste beş haftadır işlenen ayrık uzayda arama konusunu tamamlar. Hocaya göre makine öğrenmesi de aramanın sürekli (continuous) uzaydaki hâli olarak düşünülebilir.
- Oyun ağacı (game tree)
  - İki oyunculu oyunda kök, başlangıç tahtasıdır. Bizim hamle yaptığımız seviyeler MAX, rakibin hamle yaptığı seviyeler MIN diye işaretlenir.
  - Tic-tac-toe örneğinde boş tahtada 9 hamle, her birinin altında 8, onların altında 7 hamle vardır; ağaç hızla büyür.
  - Terminal düğümler oyun sonlarıdır. Her terminal düğümün bizim açımızdan iyiliğini gösteren değere fayda (utility) denir: kazanç +1, kayıp −1, beraberlik 0 (ekrandan, 00:10:00).
  - Terminal düğümler ağacın aynı seviyesinde olmak zorunda değildir; oyun her zaman aynı adımda bitmez.
- Minimax algoritması
  - Shannon ve Turing'in 1950'de ortaya koyduğu algoritmadır (ekrandan, 01:20:00).
  - MIN seviyesindeki düğümün değeri çocuklarının minimumu, MAX seviyesindekinin değeri çocuklarının maksimumu, terminal düğümün değeri fayda değeridir.
  - Rastgele olmayan oyunlar için idealdir; yaklaşım, en yüksek minimax değerini sağlayan hamleyi yapmaktır (ekrandan, 00:15:00).
  - Varsayım: rakip de oyunu kazanmak ister, rastgele oynamaz. Rakip rastgele oynasaydı çocukların ortalamasına bakmak daha uygun olurdu.
  - Değerler derinlemesine arama (DFS) ile hesaplanır. Özellikleri: ağaç sonluysa bütün; zaman $O(b^m)$; bellek $O(bm)$; kendisi için hep en iyisini yapan rakibe karşı optimal.
- Satrançta sınırlar
  - Ortalama oyun uzunluğu 40 hamle, her adımda ortalama 32 farklı hamle: $32^{40} = 2^{200} \approx 10^{60}$ durum (ekrandan, 00:25:00).
  - Saniyede 3 milyar durum işlense bile tüm durumların değerlendirilmesi yaklaşık $10^{43}$ yıl sürer; evrenin yaşı yaklaşık $10^{10}$ yıldır.
  - Minimax teoride mükemmel bir strateji verir ama satranç gibi oyunlarda pratikte kullanılamaz.
- Sınırlı derinlikte arama ve değerlendirme fonksiyonu
  - Sınırları aşmanın iki yolu: sınırlı derinlikte arama ile değerlendirme fonksiyonu (cutoff test, evaluation function) ve alfa-beta budaması.
  - Değerlendirme fonksiyonu, oyun bitmeden bir tahtanın bizim açımızdan iyi mi kötü mü olduğunu tahmin eden sezgisel fonksiyondur.
  - Satranç için basit örnek: piyon 1, at ve fil 3, kale 5, vezir 9 puan. Ekrandaki tahtada siyahların puanı 18, beyazlarınki 10; siyah için +8, beyaz için −8.
  - Genel biçim ağırlıklı doğrusal toplamdır: $Eval(s) = w_1 f_1(s) + w_2 f_2(s) + \dots + w_n f_n(s)$ (ekrandan, 00:30:00). Ağırlıklı toplam, bileşenlerin birbirinden bağımsız olduğunu varsayar.
  - Asıl iş $f$'leri ve $w$'leri belirlemektir: etrafı boş piyonlar, şahın korunması, hareket kabiliyeti, tahtanın ortasının kontrolü gibi.
- Tic-tac-toe için değerlendirme fonksiyonu
  - $E(n)$ = X'in hâlâ kazanabileceği çizgi sayısı − O'nun hâlâ kazanabileceği çizgi sayısı.
  - Boş tahtadan 2 derinlikli aramada köşe hamlesi −1, kenar hamlesi −2, orta hamlesi +1 değer alır; en iyi ilk hamle ortaya X koymaktır (ekrandan, 00:35:00).
  - Rakip hamle yaptıktan sonra aynı 2 derinlikli arama yeni tahtadan tekrarlanır (ekrandan, 00:40:00).
- Ufuk etkisi (horizon effect)
  - Arama derinliği değişince seçilen hamle değişebilir. C2'deki beyaz kalenin a2'deki piyonu alması 1 derinlikte alınır, 2'de alınmaz, 3'te alınır, 4'te alınmaz (ekrandan, 00:55:00).
  - Çözüm, donanımın izin verdiği kadar derine gitmektir. 100 saniye ve saniyede $10^4$ düğümle $10^6$ düğüm açılabilir; $b = 35$ için $b^m \approx 10^6$ olduğundan $m = 4$ olur. 4 kat ileriye bakış amatör seviyededir.
- Alfa-beta budaması
  - α bir durumun alabileceği minimum değer, β alabileceği maksimum değerdir (ekrandan, 01:00:00).
  - Bir dalın $[\alpha, \beta]$ aralığı ile üstündeki düğümün aralığının kesişimi boş olunca o dalın kalan çocukları değerlendirilmez.
  - Budama seçilen hamleyi değiştirmez. En iyi durumda karmaşıklığı $b^{m/2}$'ye düşürür; aynı sürede 4 yerine 8 derinliğe inilebilir.
  - Kotok ve McCarthy, 1966.
- Deterministik oyunlarda bilgisayarlar
  - Dama: Chinook 1994'ten beri; satranç: 1997'den beri; Go: 2016'da bilgisayar üstün geldi.
  - Go'da tahta 19×19, dallanma yaklaşık 250, oyun derinliği yaklaşık 150'dir; arama uzayı satrançtan çok büyüktür.
- Bilgisayarla satranç tarihi
  - 1957 Newell ve Simon'ın "10 yıl içinde" tahmini; 1958 IBM 704 üzerinde ilk satranç programı; 1967 MacHack; 1983 master unvanı alan ilk program; 1989'da proje IBM'e geçti; 1997'de Deep Blue Kasparov'u 3,5–2,5 yendi (2 galibiyet, 1 yenilgi, 3 beraberlik) (ekrandan, 01:25:00).
  - Yöntemlerin tarihi: Minimax 1950, alfa-beta 1966, dönüşüm tabloları 1967, iteratif derinleşme 1975; sonrasında özel donanım (1978), paralel arama (1983), paralel değerlendirme (1985); Deep Blue (1997) hepsini birleştirdi (ekrandan, 01:20:00).
- Şans içeren oyunlar ve expectiminimax
  - Oyun ağacına MAX ve MIN düğümlerine ek olarak şans düğümleri eklenir. Tavlada 21 farklı zar sonucu vardır (6 çift, 15 farklı): 1-1 olasılığı 1/36, 1-2 olasılığı 1/18.
  - Şans düğümünün değeri, çocuklarının değerlerinin olasılıklarıyla çarpılıp toplanmasıdır: $\sum_s P(s)\cdot \text{değer}(s)$.
  - Karmaşıklık $O(b^m n^m)$ olur ($n$: farklı şans sonucu sayısı). Tavlada pratikte en fazla 3 seviye gidilebilir; TD-Gammon 2 derinlikli arama ve çok iyi bir değerlendirme fonksiyonuyla dünya şampiyonu seviyesine ulaştı.
- Tahmin ve öğrenme
  - Bilgisayar kullanıcının hamle kayıtlarından bir sonraki hamleyi tahmin edebilir (örnek: Virtua Fighter 4).
  - Olası hamlelerde aramayı derinleştirip olasılığı düşük hamlelerde sığ tutarak rakibe karşı oynamayı öğrenebilir.
- Değerlendirme fonksiyonunu öğrenmek
  - Deep Blue'da $f$'leri uzmanlar belirledi, $w$ ağırlıkları öğrenildi: büyük ustaların oyunlarından oluşan bir veri tabanındaki hamleler, $f(p)$'si en büyük olacak şekilde ağırlıklar ayarlandı.
- Kendi kendine oynamak ve Monte Carlo Ağaç Araması (MCTS)
  - Uzman bilgisi kullanılmaz; makineye yalnız oyunun kuralları verilir (AlphaGo, AlphaZero).
  - MCTS'de hamle değerlendirilirken oyun sonuna kadar rastgele hamlelerle binlerce kez oynanır; kazanma oranı hamlenin iyiliğini gösterir.
  - Adımlar: seçim (selection), genişletme (expansion), simülasyon, geri yayılım (back propagation). Her düğüm kaç oyun oynandığını ve kaçının kazanıldığını tutar (ekrandan, 02:00:00).
  - Değerlendirme fonksiyonu gerekmediği için simülasyon hızlıdır ve kolayca paralelleştirilir.
- Tartışma: makineler satrançta ne başarıyor?
  - Bir görüşe göre Deep Blue tasarımcıların fikirlerini büyük hesap gücüyle uygulayan özel bir hesap makinesidir.
  - Drew McDermott: Deep Blue'nun satranç anlamadığını söylemek, bir uçağın kanat çırpmadığı için uçmadığını söylemeye benzer (ekrandan, 02:05:00).
  - Deep Thought örneği: beyaz piyonların kurduğu barajı bozan bir hamleyle kaleyi alıp oyunu kaybediyor. Çözüm yeni bir $f$ eklemek, ama "nereye kadar?" (ekrandan, 02:10:00).
  - İnsanlar yepyeni durumlara (örneğin 16×16 tahtalı bir satranca) makinelerden çok daha hızlı uyum sağlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Minimax'ın optimalliği varsayıma bağlıdır
  - Optimal olması için rakibin de kazanmak için oynaması gerekir. Rastgele oynayan rakibe karşı minimax ideal değildir.
- Oyun ağacının tamamı neredeyse hiçbir zaman elde değildir
  - Oyun ağacı elde olan oyunlar (tic-tac-toe gibi) sıkıcıdır, çünkü stratejisi bellidir. İnsanların oynamayı sevdiği oyunlar ağacın elde olmadığı oyunlardır.
- Değerlendirme fonksiyonu, önceki konulardaki sezgisel fonksiyonun karşılığıdır
  - Genetik algoritmadaki fitness fonksiyonu ya da kuş uçuşu mesafe gibi tahmini bir değerdir. Bu tahmin sayesinde ağacın tamamı olmadan oyun oynanabilir.
- Derinlik kararı etkiler, alfa-beta etkilemez
  - Derinliği değiştirmek seçilen hamleyi değiştirebilir (ufuk etkisi). Aynı derinlikte alfa-beta kullanmak ya da kullanmamak seçilen hamleyi değiştirmez; yalnız işi hızlandırır.
- Alfa-beta'nın kazancı
  - Satranç için aynı donanımla 4 kat yerine 8 kat ileriye bakmak, amatör seviyesinden usta seviyesine çıkmak demektir.
- Uyum kabiliyeti
  - Makineler belirli bir oyunda insanları yense de yeni ve bilinmeyen bir duruma uyum sağlama konusunda insanlar şimdilik çok daha iyidir.

## Kısa Tekrar Notları

- MAX: bizim hamlemiz, çocukların maksimumu. MIN: rakibin hamlesi, çocukların minimumu. Terminal: fayda değeri.
- Ekrandaki minimax örneğinde MIN düğümleri 3, 2, 2; kökün değeri 3; seçilen hamle $a_1$.
- Minimax: zaman $O(b^m)$, bellek $O(bm)$, rakip optimal oynarsa optimal.
- Satranç: $32^{40} \approx 10^{60}$ durum, saniyede 3 milyar durumla yaklaşık $10^{43}$ yıl.
- $Eval(s) = \sum_i w_i f_i(s)$; asıl iş $f$ ve $w$ seçimi.
- Tic-tac-toe: $E(n)$ = X'in açık çizgileri − O'nun açık çizgileri; ilk hamle için en iyisi orta (değer 1).
- Ufuk etkisi: derinlik değişince karar değişebilir; mümkün olduğunca derine git.
- α: alt sınır, β: üst sınır. Aralıkların kesişimi boşsa dal budanır.
- Alfa-beta en iyi durumda $b^{m/2}$; kararı değiştirmez.
- Expectiminimax: şans düğümü = olasılıkla ağırlıklı toplam; karmaşıklık $O(b^m n^m)$.
- Ekrandaki expectiminimax örneğinde şans düğümleri 2,1 ve 1,3; seçilen sol hamle.
- MCTS: seçim → genişletme → simülasyon (rastgele oyun) → geri yayılım; kolay paralelleşir.
- Deep Blue: uzman tanımlı $f$'ler, öğrenilmiş $w$'ler; AlphaZero: yalnız kurallar, kendi kendine oynama.

## Detaylı Açıklamalar

- **Minimax örneği (ekrandan, 00:15:00).** MAX kökünde üç hamle vardır: $a_1, a_2, a_3$. Bunların altında MIN düğümleri B, C, D ve her birinin üç çocuğu vardır. Yaprak değerleri B için 3, 12, 8; C için 2, 4, 6; D için 14, 5, 2'dir. MIN düğümlerinin değerleri $\min(3,12,8)=3$, $\min(2,4,6)=2$, $\min(14,5,2)=2$ olur. Kökün değeri $\max(3,2,2)=3$'tür ve seçilen hamle $a_1$'dir. $a_3$'ün altında 14 puanlık bir yaprak olsa da rakip, bizim açımızdan en kötü olan $d_3$'ü seçer ve biz 2 alırız. $a_1$ ise en kötü durumda bile 3 puanı garanti eder.

- **Değerlendirme fonksiyonu ile tic-tac-toe (ekrandan, 00:35:00).** Fonksiyon, X'in hâlâ kazanabileceği çizgi sayısından O'nunkini çıkarır. Örneğin X'in 6, O'nun 5 açık çizgisi varsa değer 1'dir. 4'e 6 ise tahta bizim için kötüdür, 5'e 4 ise iyidir. Boş tahtada simetri nedeniyle yalnız üç tür ilk hamle vardır: köşe (4 durumu temsil eder), kenar (4 durumu temsil eder) ve orta. 2 derinlikli aramada köşenin çocuk değerleri 1, 0, 1, 0, −1 olduğundan MIN değeri −1'dir. Kenarın çocukları −1, 0, −1, 0, −2 olduğundan değeri −2'dir. Ortanın çocukları 1 ve 2 olduğundan değeri 1'dir. MAX, 1'i seçer, yani ortaya X koyar. Rakip hamle yaptıktan sonra aynı işlem yeni tahta için tekrarlanır. İkinci hamle örneğinde aday hamlelerin değerleri 1, 0, 1, 0 çıkar; değeri 1 olan iki hamleden biri seçilir (ekrandan, 00:40:00).

- **Alfa-beta budama örneği (ekrandan, 01:05:00 ve 01:15:00).** Aynı minimax ağacı DFS ile soldan sağa gezilir. Başta her düğümün aralığı $[-\infty, +\infty]$'dur.
  - İlk yaprak 3 gelince B düğümü $[-\infty, 3]$ olur. 12 bir şey değiştirmez. 8 gelince B'nin bütün çocukları bilinir ve B = 3 olur. Kök artık $[3, +\infty]$'dur.
  - C'nin ilk yaprağı 2 gelince C $[-\infty, 2]$ olur. Kökün aralığı $[3, +\infty]$ ile kesişimi boştur; C'den 3'ü aşan bir değer gelemez. C'nin kalan iki yaprağı değerlendirilmez (X ile işaretli).
  - D'nin ilk yaprağı 14 gelince D $[-\infty, 14]$ olur. D son çocuk olduğu için kök $[3, 14]$ olarak güncellenir. 5 gelince D $[-\infty, 5]$, kök $[3, 5]$ olur. Kesişim hâlâ boş olmadığından devam edilir. Son yaprak 2 gelince D = 2 olur. Kök $\max(3, 2, 2) = 3$'tür ve seçilen hamle yine $a_1$'dir.

- **Expectiminimax örneği (ekrandan, 01:45:00).** Bir yüzü 0,9, diğer yüzü 0,1 olasılıkla gelen iki yüzlü bir zar (ağırlıklı bir para) düşünülür. MAX'ın iki hamlesi, her birinin altında bir şans düğümü, onun altında iki MIN düğümü vardır. Yapraklar soldan sağa 2, 4 | 5, 3 | 1, 1 | 6, 4'tür. MIN değerleri 2, 3, 1, 4 olur. Şans düğümleri $0{,}9\cdot 2 + 0{,}1\cdot 3 = 2{,}1$ ve $0{,}9\cdot 1 + 0{,}1\cdot 4 = 1{,}3$'tür. MAX, 2,1 değerli sol hamleyi seçer.

- **Monte Carlo Ağaç Araması.** Sınırlı bir derinlikte mükemmel hamleyi aramak yerine, değerlendirilecek hamleden sonra oyun her iki taraf için de tamamen rastgele hamlelerle sonuna kadar oynanır. Bu binlerce kez tekrarlanır. Örneğin 1000 oyunun 700'ü kazanılmışsa hamlede bir iyilik vardır; 550'ye 450 belirgin bir şey söylemez; 300'e 700 ise hamlenin kötü olduğunu gösterir. Sonuç ağaçta yukarıya doğru yayılır ve üst düğümlerin iyiliğini etkiler. Ne değerlendirme fonksiyonu ne de iyi oynama çabası olduğu için simülasyonlar çok hızlıdır. Birbirini beklemedikleri için binlerce CPU ya da GPU'ya kolayca dağıtılabilirler.

- **Deep Blue ile kendi kendine oynama arasındaki fark.** Deep Blue'nun değerlendirme fonksiyonundaki özellikleri insan uzmanlar belirlemiştir; ağırlıkları ise büyük ustaların geçmiş oyunlarından oluşan bir veri tabanında, ustaların yaptığı hamle en yüksek değeri alacak biçimde optimize edilmiştir. AlphaGo ve AlphaZero gibi kendi kendine oynayan sistemlere ise yalnız oyunun kuralları ve kazanma/kaybetme koşulları verilir; nasıl oynanacağına dair insan bilgisi yoktur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
