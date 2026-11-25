# Ders 2 Çalışma Özeti

## Genel Konular

- Algoritmanın tanımı ve üç özelliği
  - Algoritma, belirli (certain, not ambiguous), sıralı (sequential) ve sonlu (limited/finite) komutlardan oluşan bir komut kümesidir (ekrandan, 00:10:00).
  - Belirli: yalnız tanımlı komut kümesindeki komutlar kullanılır. Tanımlı olmayan bir komutla program yazılamaz.
  - Sıralı: komutlar mantıksal sırayla dizilir (logically ordered instructions). İki sayıyı toplarken `Input x`, `Input y`, `z = x + y`, `Write z` doğrudur. `y` okunmadan `z = x + y` yazmak yanlıştır (ekrandan, 00:15:00).
  - Sonlu: hem komut sayısı hem çalışma süresi sonlu olmalıdır. Sonu gelmeyen kod ya da bitmeyen çalışma algoritma değildir.
  - Sembolik örnek: komut kümesi A, B, C, D, E iken `A A B C A D E` bir algoritmadır; içinde tanımsız `Z` geçen dizi algoritma değildir; `A B C D E A B C ...` diye sonsuza giden dizi algoritma değildir (ekrandan, 00:15:00).
- Problem çözme yaklaşımı ile algoritma farkı
  - "n sayı gir, en küçüğünü bul, karesini al" bir yaklaşımdır ama algoritma değildir; çünkü "en küçüğü bul" adımı yeterince ayrıntılı değildir. Bu adım ayrıca bir algoritmayla (ya da kendi yazdığımız bir fonksiyonla) açılmalıdır.
- Gündelik algoritma örnekleri
  - Kek tarifi: miktarı belirsiz adımlar ("şeker ekle") sonluluğu bozar. "30 dakika pişir" sayısı belli bir tekrardır (for), "kürdan ıslak çıkmayana kadar bekle" sayısı belirsiz bir tekrardır (while).
  - Yol tarifi: "yemekhaneyi görene kadar yürü", "yol bitene kadar git" while döngüsüne, "100 metre git" for döngüsüne karşılık gelir.
  - Çizgi ve daire çizen bir programla ev çizme: komutlar (draw line, draw circle, draw arc) ve koordinatlar tam verilmezse çizim yapılamaz. Programda olmayan bir işlem ("ters çevir", "yansıt") kullanılamaz.
- Temel algoritmik işlemler (ekrandan, 00:30:00)
  - Sıralı (sequential) işlemler: atama (`a = 8;`, `a = x + 3;`, sembolik gösterim `:=`), matematiksel işlemler (+, −, ×, /) ve karşılaştırmalar (<, >, ==, !=). Yalnız sıralı işlemlerden oluşan programın bütün satırları çalışır.
  - Koşullu (conditional) işlemler: temeli `if`. Akış diyagramında koşul kutusunun T ve F kolları vardır, iki kol da aşağı gider ve sonra birleşir. Kodun bir kısmı çalışır, bir kısmı çalışmaz.
  - Tekrarlı (repetitive) işlemler: tekrar sayısı belliyse `for`, belirsizse `while` ya da `do-while` (bazı dillerde `repeat-until`).
  - Bu üç işlem dışında algoritmik bir yapı yoktur. Diziler algoritmayla değil veri yapılarıyla ilgilidir.
- while ve do-while farkı
  - while'da koşul önce sınanır; koşul baştan yanlışsa döngü gövdesi hiç çalışmaz.
  - do-while'da gövde en az bir kez çalışır, sonra koşul sınanır. Örnek: sisteme giriş (login). Kullanıcı adı ve şifre en az bir kez girilir; şifre yanlış olduğu ve deneme sayısı sınırı aşılmadığı sürece tekrar istenir.
- İyi (verimli) algoritma ölçütleri (ekrandan, 00:55:00 ve 01:00:00)
  - Doğruluk ve hassasiyet (accuracy & precision): sonuçların ne kadar doğru ve hassas olduğu.
  - Kaynakların verimli ve ekonomik kullanımı (efficient & economical resource utilization): CPU (zaman, time) ve bellek (space).
  - Okunabilirlik (readability): aynı doğruluk ve kaynak kullanımındaki algoritmalardan en anlaşılır olanı en iyisidir.
  - Ödünleşim (trade-off): bir ölçütte kazanırken başka bir ölçütte kaybetmek. Merge sort daha hızlıdır ama ek bellek ister; bubble sort az bellek kullanır ama yavaştır.
- Algoritma geliştirme nasıl öğrenilir
  - Algoritma geliştirmenin genel bir algoritması yoktur; tecrübeyle, bilinen çözüm yöntemlerini görerek öğrenilir. Kombinatorikteki birkaç formülün etrafında çok sayıda farklı problem olması gibi.
  - Yapay zekâ (makine öğrenmesi) örneği: sohbet robotları da veriden öğrenen algoritmalarla çalışır.
- Örnek: 1'den N'ye kadar toplam (ekrandan, 01:30:00 ve 01:35:00)
  - Döngülü çözüm: `x = x + i`, i = 1..N. N = 5 için x değerleri 0, 1, 3, 6, 10, 15. İşlem sayısı $T_1(N) \approx N$.
  - Gauss formülüyle çözüm: $x = \frac{N(N+1)}{2}$. N ne olursa olsun 3 işlem: $T_2(N) = 3$, yani sabit.
  - $N \to \infty$ iken sabit karmaşıklıklı algoritma tercih edilir.
- Örnek: M > N için −N ile M arasındaki sayıların toplamı (ekrandan, 01:45:00)
  - −N ile +N arasındakiler birbirini götürür; geriye N+1'den M'ye kadar olanlar kalır (M−N terim).
  - Döngü yerine $X_1 = \frac{M(M+1)}{2}$, $X_2 = \frac{N(N+1)}{2}$, $T = X_1 - X_2$: sabit sayıda (7) işlem.
  - Genel Gauss formülü: ardışık sayılarda toplam $= ((M-N)+1)\cdot\frac{M+N}{2}$.
- Karmaşıklık örnekleri ve çözülmemiş problemler
  - Bubble sort $N^2$, merge sort ve quick sort $N\log N$; quick sort ters sıralı girdide $N^2$'ye düşer (ekrandan, 01:45:00).
  - Gezgin satıcı problemi (TSP): N şehir için yaklaşık $N!$ tur incelenir; 4 şehirde $4! = 24$ (ekrandan, 01:55:00). Kesin çözüm büyük N'de pratik değildir, yaklaşık çözümler (genetik algoritma vb.) kullanılır.
  - PageRank, FFT ($N^2$'den $N\log N$'ye), N-body simülasyonu algoritma iyileştirmesinin örnekleridir.
- Algoritma analizi (Sedgewick-Wayne, Algorithms 4. baskı, Bölüm 1.4 slaytları)
  - Bilimsel yöntem: gözlem, hipotez, tahmin, doğrulama; deneyler tekrar edilebilir, hipotezler yanlışlanabilir olmalı.
  - 3-SUM problemi: N farklı tamsayıdan toplamı 0 olan kaç üçlü var? `30 -40 -20 -10 40 0 10 5` için cevap 4 (ekrandan, 02:10:00).
  - Kaba kuvvet çözüm üç iç içe döngüdür (j = i+1'den, k = j+1'den başlar), yaklaşık $N^3$ işlem.
  - Deneysel analiz: N iki katına çıkınca süre yaklaşık 8 katına çıkar. Log-log grafikte eğim yaklaşık 3'tür ($b = 2.999$) (ekrandan, 02:25:00). Ölçülen süre makineye bağlı olduğu için matematiksel model tercih edilir.
  - Matematiksel model (Knuth): her işlemin maliyeti × sıklığı toplanır. Sadeleştirmek için yalnız temel işlem (iç döngüdeki karşılaştırma ya da dizi erişimi) sayılır ve tilde ($\sim$) gösterimiyle yalnız en büyük terim tutulur.
  - 2-SUM: $0 + 1 + \dots + (N-1) = \frac{N(N-1)}{2} = \binom{N}{2} \sim \frac{1}{2}N^2$ karşılaştırma (ekrandan, 02:35:00).
  - 3-SUM: $\binom{N}{3} = \frac{N(N-1)(N-2)}{3!} \sim \frac{1}{6}N^3$ üçlü, $\sim \frac{1}{2}N^3$ dizi erişimi (ekrandan, 02:40:00).
  - Büyüme sınıfları: sabit, logaritmik, doğrusal, doğrusal-logaritmik ($N\log N$), karesel, kübik, üstel ($2^N$).
  - İyileştirme: diziyi sıralayıp ($N\log N$) her ikili için ikili arama ($\log N$) yapan 3-SUM $N^2\log N$'dir. 8000 elemanda kaba kuvvet 51,1 s, sıralamalı çözüm 0,96 s (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yaklaşım ile algoritma aynı şey değildir
  - "En küçüğü bul" gibi ayrıntısı verilmemiş adımlar içeren çözüm bir yaklaşımdır; algoritma olması için her adım tanımlı komutlara inmelidir.
- if'in iki kolu da aşağı gider
  - Akış diyagramında koşul kutusunun bir kolu yukarı, bir kolu aşağı gitmez. Ayrıca "if döngüsü" diye bir şey yoktur; if bir döngü değildir.
- `x = x + i` bir denklem değildir
  - Önce sağ taraftaki toplama yapılır, sonra sonuç sol taraftaki değişkene atanır. Atama operatörü en son çalışır. "x'ler birbirini götürür" diye düşünülmez.
- Okunabilirlik ve parametrik kod
  - Algoritma edebi eser değildir; en sade ve anlaşılır biçimde yazılmalıdır. Ekip çalışmasında kodu başkası da okuyacaktır.
  - Sabit 3 kez yapılacak bir işlem 3 satırla yazılabilir; ileride n kez yapılması gerekebilecekse döngüyle (parametrik) yazmak daha iyidir.
- Algoritma geliştirmede matematiğin yeri
  - Gauss formülü örneğinde olduğu gibi matematik bilgisi, döngülü $N$ işlemlik çözümü sabit işleme indirebilir.
- Süre ölçmek yerine işlem saymak
  - Saniye cinsinden süre donanıma, işletim sistemine ve yazılıma bağlıdır. Doğru yaklaşım koddan işlem sayısını ($N^3$ gibi) bulup süreyi ondan tahmin etmektir.
- Okuma önerileri
  - Sedgewick-Wayne "Algorithms" kitabı ve Knuth'un "The Art of Computer Programming" serisi meslek hayatı boyunca okunacak kaynaklar olarak önerildi.

## Kısa Tekrar Notları

- Algoritma = belirli + sıralı + sonlu komutlar kümesi.
- Üç temel işlem: sıralı (atama, aritmetik, karşılaştırma), koşullu (if), tekrarlı (for / while / do-while).
- for: tekrar sayısı belli. while: belirsiz, gövde hiç çalışmayabilir. do-while: gövde en az bir kez çalışır.
- İyi algoritma: doğruluk/hassasiyet, verimli kaynak kullanımı (zaman ve bellek), okunabilirlik; ölçütler arasında ödünleşim vardır.
- $1+2+\dots+N$: döngüyle $\approx N$ işlem, Gauss formülüyle sabit (3) işlem.
- TSP: N şehir için $N!$ olası tur.
- 3-SUM kaba kuvvet $\sim N^3$, sıralama + ikili arama ile $N^2\log N$.
- 2-SUM karşılaştırma sayısı $\binom{N}{2} \sim \frac{1}{2}N^2$.
- Tilde gösterimi: yalnız en yüksek dereceli terim tutulur.
- Büyüme sınıfları: $1, \log N, N, N\log N, N^2, N^3, 2^N$.

## Detaylı Açıklamalar

- Algoritmanın üç özelliği birlikte sağlanmalıdır. Belirlilik, yalnız tanımlı komutların kullanılmasıdır: C'de `scanf`, akış diyagramında giriş sembolü gibi. Sıralılık, komutların mantıklı bir sırada olmasıdır; bir değişken okunmadan kullanılırsa algoritma bozulur. Sonluluk, hem yazılan komutların hem çalışma süresinin sonlu olmasıdır. Ders, bu üç özelliği A–E harflerinden oluşan soyut bir komut kümesiyle örnekledi: harflerin istenen sırada ve tekrar sayısında kullanılması algoritmayı bozmaz, ama tanımsız bir harf (Z) ya da sonsuza giden bir dizi algoritmayı geçersiz kılar.
- Gündelik örnekler tekrarlı işlemlerin iki türünü ayırmak için kullanıldı. "30 dakika pişir" ya da "100 metre yürü" başı ve sonu belli tekrarlardır ve `for` ile kodlanır. "Kürdan ıslak çıkmayana kadar bekle" ya da "yol bitene kadar yürü" ise tekrar sayısı önceden bilinmeyen durumlardır ve `while` ile kodlanır. Ev çizme örneği, bir programın yalnız sahip olduğu komutlarla (çizgi, daire, yay çizme) çalışabileceğini ve her komutun koordinat gibi ayrıntılarla tam verilmesi gerektiğini gösterdi.
- do-while yapısında önce döngü gövdesi çalışır, sonra koşul sınanır. Sisteme giriş örneğinde koşul "şifre yanlış ve deneme sayısı sınırın altında" biçimindedir. Yalnız "şifre yanlış olduğu sürece" demek tehlikelidir, çünkü sınırsız deneme şifre kırmaya izin verir.
- İyi algoritmanın ölçütleri birbirinin aleyhine çalışabilir. Gömülü sistem örneğinde 4 MB bellekte 4 MB veriyi merge sort ile sıralamak mümkün olmaz, çünkü merge sort ek bir 4 MB ister; bu durumda daha yavaş ama az bellekli bir sıralama seçilir. Telefon ya da bilgisayar alırken bütçeye göre en uygun ürünün seçilmesi gibi, algoritma da koşullara göre en iyi ödünleşimi sağlayan seçilir.
- Gauss toplamı karmaşıklık fikrine giriş oldu. Döngülü çözümde N = 5 için i = 1, 2, 3, 4, 5 adımlarında x sırasıyla 1, 3, 6, 10, 15 olur; toplama işlemi N kez yapılır, $T_1(N) \approx N$. Formüllü çözümde bir çarpma, bir toplama ve bir bölme vardır; $T_2(N) = 3$ ve N'den bağımsızdır. Formülün kanıtı: $1 + 2 + \dots + N$ ile $N + (N-1) + \dots + 1$ alt alta toplanınca her sütun $N+1$ verir, N sütun vardır, iki kez yazıldığı için 2'ye bölünür. Aynı mantıkla N'den M'ye kadar toplam $((M-N)+1)\cdot\frac{M+N}{2}$ olur.
- Algoritma analizinde süre ölçümü (deneysel analiz) bir başlangıçtır: 3-SUM için N iki katına çıktığında süre yaklaşık 8 katına çıkıyorsa algoritma kübiktir. Log-log grafikte doğru eğimi bu üssü verir ($T(N) = aN^b$, $b \approx 3$). Ama süre makineye bağlıdır. Bu yüzden Knuth'un önerdiği matematiksel modelde her işlemin sıklığı sayılır. İşi kolaylaştırmak için yalnız temel işlem (iç döngüdeki karşılaştırma) sayılır ve tilde gösterimiyle küçük terimler atılır. 2-SUM'da karşılaştırma sayısı $\sum_{i=0}^{N-1}(N-1-i) = \frac{N(N-1)}{2} \sim \frac{1}{2}N^2$'dir.
- Algoritma iyileştirme örneği olarak 3-SUM'un sıralama ve ikili aramayla çözümü gösterildi: dizi önce $N\log N$ sürede sıralanır, her $(i, j)$ ikilisi için $-(a[i]+a[j])$ değeri ikili aramayla ($\log N$) aranır; toplam $N^2\log N$. Slayttaki ölçümde 8000 elemanda kaba kuvvet çözüm 51,1 saniye, sıralamalı çözüm 0,96 saniye sürüyor.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
