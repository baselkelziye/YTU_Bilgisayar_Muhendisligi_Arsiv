# Ders 9 Çalışma Özeti

## Genel Konular

- Girişte hatırlatma: ikili ağaç ve gezinme biçimleri
  - $(x * y) + B$ ifadesi bir ikili ağaçla gösterildi: kökte $+$, sol alt ağaçta $*$ ve onun çocukları $x$, $y$, sağda $B$ (ekrandan, 00:20:00).
  - Operatörün yerine göre üç gösterim vardır: infix (operatör içeride, günlük kullanım), prefix (operatör önde), postfix (operatör sonda). Ağaçtaki karşılıkları inorder, preorder ve postorder gezinmedir.
  - Bu ifade için postfix $x\,y\,*\,B\,+$, prefix $+\,*\,x\,y\,B$ olur. Derleyiciler işlem önceliğini kolay işlemek için infix ifadeleri postfix ya da prefix biçime çevirir.
- Inorder gezinmenin iki yazımı ve analizi
  - İteratif (yığıtlı) yazım: gidilebildiği kadar sola gidilir, geçilen düğümler bir yığıtta (stack) saklanır. Hoca bunu kaba kuvvet (brute force) yaklaşımı olarak niteledi.
  - Özyinelemeli yazım: sol alt ağaç, kök, sağ alt ağaç. Problem küçük alt ağaçlara bölündüğü için böl ve fethet (divide and conquer) yaklaşımıdır.
  - İkisinde de her düğüm bir kez ziyaret edilir: $T(n) = O(n)$ (ekrandan, 00:35:00).
- Fibonacci sayıları üç paradigmayla
  - Kaba kuvvet (döngüyle iki değişken): $T(n)=O(n)$, $S(n)=O(1)$.
  - Böl ve fethet (özyinelemeli $F_n = F_{n-1} + F_{n-2}$): $T(n) = T(n-1) + T(n-2) + 1$, üstel zaman, kabaca $O(2^n)$.
  - Dinamik programlama (dizide saklayarak): $T(n)=O(n)$, $S(n)=O(n)$.
- Dinamik programlamanın tanımı ve adımları
  - Örtüşen alt problemleri (overlapping subproblems) olan problemleri çözmek için bir tekniktir. Böl ve fethet ya da azalt ve fethetteki yineleme bağıntısına bir saklama (tabulation / memoization) eklenir.
  - Adımlar (ekrandan, 01:25:00): alt problemleri tanımla; yineleme bağıntısını kur; başlangıç koşullarını belirle ve çöz; ara çözümleri kullanıp kaydederek son çözümü bul.
- Madeni para dizisi (coin-row) problemi
  - Yan yana iki para seçilmeden toplam değer en büyük yapılır.
  - $P(n) = \max\{P(n-2) + c_n,\ P(n-1)\}$, $P(0)=0$, $P(1)=c_1$.
  - Örnek 5, 1, 2, 10, 6, 2 için en büyük değer 17, seçilen paralar 1., 4. ve 6. paralar (ekrandan, 02:05:00).
- 0-1 sırt çantası (knapsack) problemi
  - Her eşyadan bir tane vardır; ya alınır ya alınmaz. Ağırlık sınırı aşılmadan toplam değer en büyük yapılır.
  - Kaba kuvvet $2^n$ alt küme dener. Dinamik programlamada eşya × kapasite tablosu doldurulur.
  - $P(i,w) = P(i-1,w)$, eğer $w_i > w$; değilse $P(i,w)=\max\{P(i-1, w-w_i) + v_i,\ P(i-1,w)\}$ (ekrandan, 02:35:00).
  - İki örnek çözüldü: $W=5$ için 37 (eşya 1, 2, 4) ve $W=9$ için 13 (eşya 2, 3, 4).
- Düzenleme uzaklığı (edit distance)
  - Bir dizgiyi diğerine çevirmek için gereken en az ekleme, silme ve değiştirme sayısıdır (her birinin maliyeti 1 kabul edildi).
  - $ED[i,j] = ED[i-1,j-1]$, eğer $x_i = y_j$; değilse üç komşunun en küçüğü artı 1 (ekrandan, 03:30:00).
  - Örnek: "abcfg" ile "adceg" arasındaki uzaklık 2 (ekrandan, 03:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Dinamik programlamanın ilk ve en zor adımı yineleme bağıntısını kurmaktır
  - Yineleme bağıntısı yoksa ne böl ve fethet, ne azalt ve fethet, ne de dinamik programlama yapılabilir.
  - Hoca, tabloyu ezbere doldurmak yerine bağıntının nasıl kurulduğunun öğrenilmesi gerektiğini söyledi.
- Bağıntı sondan düşünülerek kurulur, tablo baştan doldurulur
  - "Son parayı (son eşyayı) alırsam / almazsam" diye iki durum düşünülür.
  - Tablo ise başlangıç koşullarından başlayarak ileri doğru doldurulur, çünkü her hücre önceki kayıtları kullanır.
- $T(n) = T(n-1) + T(n-2) + 1$ Master teoremiyle çözülmez
  - Alt problemler eşit boyda değildir. Bu tür bağıntılar karakteristik denklemle ya da geri yerine koymayla çözülür.
  - Pratik kural: $n$'e yakın boyutlu iki dallanma varsa karmaşıklık yaklaşık $2^n$, üç dallanma varsa $3^n$ mertebesindedir.
- Özyinelemeli Fibonacci'nin asıl kusuru gereksiz tekrar
  - $F(5)$ ağacında $F(1)$ ve $F(0)$ defalarca hesaplanır. Dinamik programlama bu tekrarı kayıt tutarak ortadan kaldırır.
- Seçilen elemanlar tablodan geriye izlenerek (backtracking) bulunur
  - Bir hücre üst satırdaki (ya da önceki) değerden farklıysa o eleman alınmıştır; aynıysa alınmamıştır.
- Aç gözlü seçim kaba kuvvet değildir
  - En değerli eşyayı doğrudan almak aç gözlü (greedy) bir yaklaşımdır. Kaba kuvvet bütün olasılıkları dener.

## Kısa Tekrar Notları

- Postfix: sol, sağ, operatör. Prefix: operatör, sol, sağ. Infix: sol, operatör, sağ.
- Inorder gezinme: iteratif (yığıtlı) ve özyinelemeli yazımların ikisi de $O(n)$ zamandır.
- Fibonacci: kaba kuvvet $O(n)$ zaman, $O(1)$ yer; özyinelemeli üstel zaman; dinamik programlama $O(n)$ zaman, $O(n)$ yer.
- Dinamik programlama = yineleme bağıntısı + örtüşen alt problemlerin uygun veri yapısında saklanması.
- Coin-row: $P(n) = \max\{P(n-2)+c_n, P(n-1)\}$, $P(0)=0$; $T(n)=\Theta(n)$, $S(n)=\Theta(n)$.
- 0-1 knapsack: $P(i,w)$ tablosu, kaba kuvvet $2^n$ yerine $O(nW)$.
- Edit distance: eşitse çapraz değeri kopyala; farklıysa üst, sol ve çapraz komşunun en küçüğüne 1 ekle; $O(mn)$ zaman ve yer.

## Detaylı Açıklamalar

- Ağaç gezinmesinden paradigmalara
  - Hoca, $(x*y)+B$ ağacı üzerinden postfix ve prefix dönüşümlerini elle yaptı. Ağaçtaki inorder gezinme, parantezli infix ifadeyi geri verir.
  - Inorder gezinmenin yığıt kullanan (özyinelemesiz) bir kodu internetten gösterildi. Yığıtsız anlatımda ise her alt ağaç yeni bir ağaç gibi düşünülür; bu da özyinelemeli koda karşılık gelir. Özyinelemeli kod çok daha kısa ve açıktır.
  - Ekranda gösterilen bir ağaç için inorder sırası bir öğrenci tarafından 4, 2, 5, 1, 3 olarak verildi. <!-- BELİRSİZ: bu ağacın yapısı karelerde görünmüyor; internet sayfasındaki örnek olduğu anlaşılıyor. -->
  - Hoca, iki yazımın da $O(n)$ zaman aldığını, iteratif yazımın ayrıca bir yığıt tuttuğunu söyledi. Burada böl ve fethet daha anlaşılır bir algoritma vermişti.
- Fibonacci: böl ve fethetin çuvalladığı yer
  - Kaba kuvvet çözüm iki değişkenle ilerler: $s_1=0$, $s_2=1$; her adımda $temp = s_1 + s_2$, sonra $s_1 \leftarrow s_2$, $s_2 \leftarrow temp$. Döngü $n-2$ kez döner, $O(n)$.
  - Özyinelemeli kod (ekrandan, 00:40:00) $n=0$ için 0, $n=1$ için 1 döndürür, diğer durumlarda $fib(n-1)+fib(n-2)$ hesaplar. $F(3)$ izlenirken her çağrının artıdan önce bütünüyle tamamlandığı vurgulandı.
  - Zaman bağıntısı $T(n) = 1 + T(n-1) + T(n-2)$'dir. Hoca karakteristik denklemi $r^2 - r - 1 = 0$ olarak yazdı ve sonucun $O(2^n)$ mertebesinde, daha kesin olarak altın orana ($\approx 1{,}6$) dayalı bir üstel olduğunu söyledi.
  - $n=1000$ için kaba kuvvet 1000 adımda biterken özyinelemeli çözüm $2^{1000}$ mertebesinde adım ister.
  - Dinamik programlama çözümü (ekrandan, 01:05:00): `A[0]=0; A[1]=1; for (i=2; i<n; i++) A[i] = A[i-1] + A[i-2];` Her değer bir kez hesaplanır ve dizide saklanır.
- Dinamik programlamanın kökeni
  - Hoca, buradaki "programlama" sözcüğünün planlama anlamına geldiğini, tekniğin endüstri mühendisliğinde de çok kullanıldığını ve optimizasyon ile kombinatorik problemlerde işe yaradığını söyledi.
  - Örnek olarak $x^n$ hesabı da verildi: $x^n = x^{n/2} \cdot x^{n/2}$, başlangıç koşulu $x^0 = 1$ (ekrandan, 01:20:00).
- Madeni para dizisi problemi
  - Paralar: 5, 1, 2, 10, 6, 2 (sıraları değiştirilemez). Kaba kuvvette yan yana olmayan bütün seçimler listelenip en büyüğü bulunur; bu yaklaşık $2^n$ mertebesindedir.
  - Durum 1, son para alınır: $c_n$ kazanılır ve $(n-1)$. para alınamaz, kalan problem $P(n-2)$ olur. Durum 2, son para alınmaz: problem $n-1$ para için yeniden çözülür, $P(n-1)$.
  - Tablo (ekrandan, 02:05:00):

    | indeks | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
    |---|---|---|---|---|---|---|---|
    | $c$ | – | 5 | 1 | 2 | 10 | 6 | 2 |
    | $P$ | 0 | 5 | 5 | 7 | 15 | 15 | 17 |

  - Geriye izleme: $P(6)=17 \neq P(5)=15$ olduğu için 6. para alınmış, $P(4)$'e gidilir. $P(4)=15 \neq P(3)=7$, 4. para alınmış, $P(2)$'ye gidilir. $P(2)=P(1)$ olduğundan 2. para alınmamış; $P(1)=5$, 1. para alınmış. Seçim: 1, 4, 6 (toplam 17).
- 0-1 sırt çantası problemi
  - Kaba kuvvet: $n$ eşya için $2^n$ alt küme (doğruluk tablosu gibi) denenir, kapasiteyi aşanlar elenir.
  - Birinci örnek ($W=5$; ağırlıklar 2, 1, 3, 2; değerler 12, 10, 20, 15) (ekrandan, 02:30:00):

    | eşya \ $w$ | 0 | 1 | 2 | 3 | 4 | 5 |
    |---|---|---|---|---|---|---|
    | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
    | 1 | 0 | 0 | 12 | 12 | 12 | 12 |
    | 2 | 0 | 10 | 12 | 22 | 22 | 22 |
    | 3 | 0 | 10 | 12 | 22 | 30 | 32 |
    | 4 | 0 | 10 | 15 | 25 | 30 | 37 |

  - Sonuç 37; eşya 1, 2 ve 4 alınır. Tablo doldurma $O(nW)$ zaman ve aynı boyutta yer ister.
- Düzenleme uzaklığı
  - Üç işlem: değiştirme (sunny ile sumny), silme (sunny ile sun-y), ekleme. "maths" ile "arts" arasındaki uzaklık 3'tür (ekrandan, 03:05:00).
  - Biyoenformatikte gen dizilerini hizalamada ön işlem olarak kullanılır.
  - Tabloda ilk satır ve ilk sütun $0, 1, 2, \dots$ diye dolar (boş dizgiden ekleme ya da silmeyle geçiş). Diğer hücreler bağıntıyla doldurulur; uzunlukları $m$ ve $n$ olan iki dizgi için $O(mn)$ zaman ve yer gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
