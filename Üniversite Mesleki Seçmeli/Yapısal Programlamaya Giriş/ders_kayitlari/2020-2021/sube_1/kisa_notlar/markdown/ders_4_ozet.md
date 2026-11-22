# Ders 4 Çalışma Özeti

## Genel Konular

- Hatırlatma: iyi bir algoritmanın özellikleri
  - Önceki dersten: iyi algoritma daha hızlıdır, daha az bellek ister, daha esnek, daha anlaşılır ve daha modülerdir.
- Yaklaşık formüller ve işlem sayısı
  - Gauss formülü $1+2+\dots+n = \frac{n(n+1)}{2}$ tam (eşit) bir formüldür ve $n$ adımlık toplamayı sabit sayıda işleme indirir (ekrandan, 00:15:00).
  - $n! = 1\cdot 2\cdots n$ bir tanımdır, formül değildir. Stirling formülü yaklaşık bir değer verir: $n! \approx \sqrt{2\pi n}\left(\frac{n}{e}\right)^n$ (ekrandan, 00:15:00).
  - Karekökün olduğu kısım sabit sayıda işlemdir. Asıl maliyet $x^n$ kısmıdır: $x$'i kendisiyle $n$ kez çarparsak yine $n$ işlem eder, kazanç olmaz.
  - $x^n$ ileride görülecek özyinelemeli (recursive) bir yöntemle $\log_2 n$ adımda hesaplanabilir. O zaman Stirling formülü büyük kazanç sağlar (1000 adım yerine yaklaşık 10, 1 milyon yerine yaklaşık 20 adım).
- Akış diyagramı ile $x^n$ hesabı
  - START, kullanıcıdan $x$ ve $n$ okunur, $i$ 1'den $n$'e birer birer döner, sonuç yazdırılır, STOP.
  - İlk denemede döngüde `x = x * x` yazıldı. Bu her adımda karesini alır, yanlıştır. Ayrı bir değişken gerekir: `K = 1` ile başlanır, döngüde `K = K * x` yapılır, sonunda `K` yazdırılır. `K = 0` ile başlamak sonucu hep sıfır yapar.
- $\pi$'yi seri ile hesaplayan algoritma
  - $\pi \approx 4 - \frac{4}{3} + \frac{4}{5} - \frac{4}{7} + \frac{4}{9} - \dots$ (ekrandan, 00:25:00). Terim sayısı $N$ arttıkça $\pi$'ye daha çok yaklaşılır.
  - Analiz: 4 en sonda çarpılır. $i$. terimin paydası $2i-1$'dir. $i$ tekse terim eklenir, çiftse çıkarılır (ekrandan, 00:30:00).
  - Birinci çözüm: `P = 0`, döngüde `i mod 2 == 1` ise `P = P + 1/(2*i-1)`, değilse `P = P - 1/(2*i-1)`, sonunda `4*P` yazdırılır.
  - If'siz çözüm: `e = 1` ile başlanır, döngüde `P = P + e * 1/(2*i-1)` ve ardından `e = e * (-1)` yapılır. İşaret her adımda değişir.
  - $(-1)^i$'yi her adımda ayrı bir döngüyle hesaplamak karmaşıklığı $n^2$'ye çıkarır. İki ayrı for (artılar ve eksiler ayrı) da $n$ mertebesinde kalır ama daha az şıktır.
- $e^x$'i seri ile hesaplayan algoritma ve iyileştirme
  - $e^x = 1 + \frac{x}{1} + \frac{x^2}{2!} + \frac{x^3}{3!} + \dots$ (ekrandan, 00:40:00).
  - İlk çözüm: `E = 1`, $i$ 1'den $n-1$'e döner; her adımda iç döngüyle `y = y * x` ($x^i$) ve ayrı bir iç döngüyle `A = A * j` ($i!$) hesaplanır, sonra `E = E + y/A`. İç içe döngüler yüzünden karmaşıklık $n^2$'dir.
  - Döngü üst sınırı $n-1$'dir, çünkü ilk terim 1 zaten `E = 1` ile eklenmiştir.
  - İyileştirme: $x^n = x\cdot x^{n-1}$ ve $n! = n\cdot (n-1)!$. `A = 1`, `y = 1` döngüden önce bir kez verilir; döngüde yalnız `y = y * x`, `A = A * i`, `E = E + y/A` yapılır (ekrandan, 01:00:00). Karmaşıklık $n^2$'den $n$'e iner.
- $n$. Fibonacci sayısı
  - $f(1) = 1$, $f(2) = 1$, $f(n) = f(n-1) + f(n-2)$. Dizi: 1, 1, 2, 3, 5, 8, 13, 21, ... (ekrandan, 01:25:00).
  - Dizili çözüm: `F(1) = 1`, `F(2) = 1`, $i$ 3'ten $N$'e `F(i) = F(i-1) + F(i-2)`, sonunda `F(N)`. Sorun: 1 milyonuncu sayı için 1 milyon elemanlık dizi gerekir.
  - Üç değişkenli çözüm: `T = 0, E = 1, K = 1`; döngüde `T = K + E`, `E = K`, `K = T`; sonunda `T` yazdırılır (ekrandan, 01:35:00). Bellek sabittir, süre yine $n$ mertebesindedir.
  - İki değişkenli çözüm: `S = 1, F = 1`; döngüde `S = S + F`, `F = S - F`. $i$. Fibonacci sayısı her zaman `S`'dedir (ekrandan, 01:35:00).
  - Üç değişkenli çözüm $N = 1$ ya da $N = 2$ için döngüye girmez ve 0 verir. Beklenmeyen girişler için ek kontrol gerekebilir.
- Basamak küpleri toplamı kendine eşit sayılar (Armstrong sayıları)
  - Üç basamaklı sayı için $a^3 + b^3 + c^3 = 100a + 10b + c$ (ekrandan, 01:40:00). Döngü 100'den 999'a gider.
  - Yüzler: $\lfloor i/100 \rfloor$, onlar: $\lfloor (i - 100\cdot y)/10 \rfloor$, birler: $i \bmod 10$. Küplerin toplamı $i$'ye eşitse $i$ yazdırılır.
  - Aşağı yuvarlama $\lfloor\ \rfloor$, yukarı yuvarlama $\lceil\ \rceil$ ile gösterilir. Algoritma programlama dilinden bağımsız yazılır.
- Hangi döngü?
  - Bir dizide bir sayının ilk ya da ikinci geçtiği yer için while; son geçtiği yer için for ya da tersten taranan while; bütün geçtiği yerler için for kullanılır.
- Önermeler, karşıt örnek ve bilgisayarla arama
  - "Her pozitif doğal $n$ için $n^2 + n + 41$ asaldır" önermesi $n = 1, 2, 3$ için tutar (43, 47, 53) ama yanlıştır: $n(n+1) + 41$ yazılırsa $n = 40$ için $40\cdot 41 + 41 = 41^2$ çıkar (ekrandan, 01:50:00).
  - "$a^4 + b^4 + c^4 = d^4$ denkleminin pozitif doğal sayılarda çözümü yoktur" önermesi yanlıştır. Karşıt örnek: $a = 95800$, $b = 217519$, $c = 414560$, $d = 422481$ (ekrandan, 02:00:00). Bu ancak 1988'de bilgisayarla bulunabilmiştir.
  - Arama algoritması: $a$, $b$, $c$, $d$ için 1'den $n$'e dört iç içe döngü ve $a^4 + b^4 + c^4 == d^4$ kontrolü (ekrandan, 01:55:00). Bulunduğu anda çıkılacağı için while daha uygundur. Dördüncü döngü yerine dördüncü dereceden kök alıp tam sayı olup olmadığına bakılabilir.
  - "2 haricindeki her çift sayı iki asal sayının toplamıdır": 8 = 5 + 3, 18 = 13 + 5 = 11 + 7, 46 = 41 + 5 (ekrandan, 02:05:00). Bugün doğru mu yanlış mı olduğu bilinmiyor.
  - Bu önermeyi araştıran algoritma taslağı: asal sayılar dizisi `AS[1..N]` elde var sayılır; çift $x$ değerleri dolaşılır; $i$ ve $j$ için iç içe döngülerle `x == AS[i] + AS[j]` kontrol edilir (ekrandan, 02:25:00). Hiçbir çift tutmazsa karşıt örnek bulunmuş olur; bu kontrol derste tamamlanmadı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tam formül ile yaklaşık formül farkı
  - Eşittir ile yaklaşık işareti ayrı şeylerdir. Stirling yaklaşık bir formüldür ama işlem sayısını azaltabilir.
- Bir formülün kazancı işlem sayısıyla ölçülür
  - Formül yine $n$'e bağlı işlem gerektiriyorsa doğrudan hesaba göre kazanç sağlamaz. $n$'den $\log_2 n$'e ya da $n^2$'den $n$'e inmek büyük başarıdır.
- Zaman ile bellek ayrı kazançlardır
  - Fibonacci'de dizisiz çözüm daha hızlı değildir, ama bellek ihtiyacını $n$'den sabite indirir.
- Değişkenlere ilk değer verin
  - İlk değer verilmeyen değişken bellekte ne varsa onu taşır. Pratikte her değişkene ilk değeri kendiniz atayın.
- Kullanıcı girişleri
  - Kullanıcı $n$ için 1, 2 ya da negatif bir değer girebilir. Düşünülmeyen girişler için ek kontrol eklemek gerekir.
- Binlerce çalışan örnek ispat değildir
  - Bir önermenin yanlış olduğunu göstermek için tek bir karşıt örnek yeter; doğru olduğunu göstermek için ispat gerekir. Algoritmayı yazmak önermeyi ispatlamak demek değildir; algoritma belli bir sınıra kadar araştırma yapar.
- Algoritma geliştirmek iteratif bir süreçtir
  - Önce basit ve kötü ama çalışan bir çözüm yazılır, sonra memnun olunmayan yerleri iyileştirilir. Yanlış yapmak bu sürecin doğal parçasıdır.
- Önce kendiniz düşünün
  - Hoca, düşünme süresinde internete bakmak yerine kendi kafanızı kullanmanızı istedi.

## Kısa Tekrar Notları

- $1+\dots+n = n(n+1)/2$ tam formül; $n! \approx \sqrt{2\pi n}(n/e)^n$ yaklaşık formül (Stirling).
- $x^n$ düz çarpmayla $n$ adım, ileride görülecek yöntemle $\log_2 n$ adım.
- $x^n$ için `K = 1`, döngüde `K = K * x`; `x = x * x` yanlış.
- $\pi$ serisi: payda $2i-1$, işaret için `i mod 2` ya da her adımda `e = e * (-1)`.
- $e^x$: iç içe döngülerle $n^2$; `y = y * x`, `A = A * i` ile tek döngüde $n$.
- Fibonacci: dizi ($n$ bellek), üç değişken (`T = K + E`, `E = K`, `K = T`), iki değişken (`S = S + F`, `F = S - F`).
- Basamaklar: $\lfloor i/100 \rfloor$, $\lfloor (i-100y)/10 \rfloor$, $i \bmod 10$.
- İlk/ikinci geçiş: while; tüm geçişler: for.
- $n^2+n+41$: $n = 40$'ta $41^2$, önerme yanlış.
- $a^4+b^4+c^4=d^4$ çözümü var (95800, 217519, 414560, 422481).
- Goldbach önermesi bugün açık bir problemdir.

## Detaylı Açıklamalar

- **Formülün asıl kazancı.** Gauss formülü, $n$ sayıyı tek tek toplamak yerine sabit sayıda işlemle sonucu verdiği için değerlidir: $n$ bin de olsa on bin de olsa işlem sayısı değişmez. Stirling formülünde $\sqrt{2\pi n}$ kısmı sabit sayıda işlemdir (çarp, çarp, karekök al) ve $n/e$ tek bir bölmedir. Ama bunun $n$. kuvvetini almak, $x$'i kendisiyle $n$ kez çarparak yapılırsa yine $n$ işlem eder. $n!$'i doğrudan hesaplamak da $n$ çarpma olduğuna göre bu durumda formül bir şey kazandırmaz. Kazanç, $x^n$'i $\log_2 n$ adımda bulan yöntemle gelir; bu yöntem özyinelemeli algoritmalar konusunda görülecek.

  > **Ders sonrası not:** Python ile kontrol: Stirling formülü $n = 10$ için gerçek değerin yaklaşık %99,2'sini, $n = 100$ için yaklaşık %99,9'unu veriyor. $\log_2 1000 \approx 9{,}97$, $\log_2 10^6 \approx 19{,}93$; hocanın "10 adım" ve "20 adım" sözleri bununla uyumlu.

- **Akış diyagramı gösterimi.** Tahtada kullanılan gösterimde START ve STOP oval içine yazılır. Kullanıcıdan okuma eğik üst kenarlı bir kutuyla, ekrana yazma alt kenarı dalgalı belge biçimli bir kutuyla çizilir. For döngüsü iki katlı bir kutudur: üst katta başlangıç değeri ve adım (`i ← 1 || 1`), alt katta bitiş değeri (`N`) yazılır. Döngü gövdesinin sonu numaralı bir bağlantı dairesiyle (1, 2, ...) döngü kutusuna geri bağlanır. Karar kutusu altıgen biçimindedir ve çıkışları T (true) ve F (false) olarak işaretlenir (ekrandan, 00:30:00, 00:50:00). Karşılaştırmada atamayla karışmasın diye `==` yazılır.

- **$\pi$ algoritmasının iki hali.** Birinci halde döngünün içinde `i mod 2 == 1` sorulur; tekse $1/(2i-1)$ eklenir, çiftse çıkarılır, iki dal aynı bağlantı noktasında birleşir ve döngü sonunda `4*P` yazdırılır. İkinci halde işaret bir değişkende tutulur: `e = 1` ile başlar ve her adımda `-1` ile çarpılarak $+1, -1, +1, \dots$ diye gider. Böylece if kullanmadan aynı sonuç elde edilir.

  > **Ders sonrası not:** İki sürüm python ile karşılaştırıldı ve aynı sonucu verdi: $N = 10$ için $3{,}0418$, $N = 1000$ için $3{,}14059$. Seri yavaş yakınsadığı için çok terim gerekiyor.

- **$e^x$ algoritmasının iyileştirilmesi.** İlk çözümde her terim için $x^i$ ve $i!$ sıfırdan hesaplanır. $i$. terim için yaklaşık $2i$ işlem gerekir, $n$ terim için toplam $n^2$ mertebesinde iş çıkar. Derste önce iki iç döngü tek iç döngüde birleştirildi; bu işi biraz basitleştirdi ama iç içe yapı kaldığı için karmaşıklık değişmedi. Asıl iyileştirme, bir önceki adımda bulunan $x^{i-1}$ ve $(i-1)!$ değerlerini saklamaktır: yeni terimin payı bir kez $x$ ile, paydası bir kez $i$ ile çarpılır. `A` ve `y` döngüden önce 1 yapılır ve döngü içinde yeniden sıfırlanmaz. Böylece tek döngü kalır ve karmaşıklık $n$ olur.

  > **Ders sonrası not:** İki sürüm python ile karşılaştırıldı, aynı sonucu verdi: $x = 2$, $n = 4$ için $1 + 2 + 2 + 4/3 \approx 6{,}333$; $n = 20$ için $7{,}389056$, bu da $e^2$ ile çakışıyor.

- **Fibonacci'de bellek.** Dizili çözüm basittir ama $n$. sayı için $n$ elemanlık yer ister. Üç değişkenli çözümde `T` o anki sayıyı ($f(n)$), `K` bir öncekini ($f(n-1)$), `E` iki öncekini ($f(n-2)$) tutar. Yeni sayı hesaplandıktan sonra `E = K` ve `K = T` ile değişkenler bir sonraki adıma hazırlanır. İki değişkenli çözümde `S = S + F` yeni sayıyı verir, `F = S - F` ise eski `S`'yi geri elde eder. Derste yapılan iz sürme tablosu (ekrandan, 01:35:00):

  | $i$ | $S$ | $F$ |
  |---|---|---|
  | başlangıç | 1 | 1 |
  | 3 | 2 | 1 |
  | 4 | 3 | 2 |
  | 5 | 5 | 3 |
  | 6 | 8 | 5 |

  > **Ders sonrası not:** Üç sürüm python ile çalıştırıldı. $n \ge 3$ için üçü de 2, 3, 5, 8, 13, ... dizisini veriyor. Üç değişkenli sürüm $n = 1, 2$ için 0 veriyor; derste bir öğrencinin fark ettiği durum bu.

- **Armstrong sayıları.** Her $i$ için basamaklar ayrılır. 845 örneğinde $845/100 = 8{,}45$ aşağı yuvarlanınca yüzler basamağı 8 çıkar; $(845 - 800)/10 = 4{,}5$ aşağı yuvarlanınca onlar basamağı 4 çıkar; $845 \bmod 10 = 5$ birler basamağıdır. Küplerin toplamı $i$'ye eşitse $i$ yazdırılır. Hoca 1000'in kendisi bu özellikte olmadığı ve iki basamaklı böyle sayı bulunmadığı için döngüyü 100'den 999'a kadar kurdu; bunun ancak bu bilgi bilindiğinde yapılabilecek bir sadeleştirme olduğunu da söyledi.

  > **Ders sonrası not:** Python ile 100-999 arasında bu özellikte 153, 370, 371 ve 407 sayıları bulundu; iki basamaklı böyle sayı yok.

- **Önermeler ve bilgisayar.** $n^2+n+41$ önermesini kaba kuvvetle (brute force) sınamak için $n$ bir döngüde artırılır, değer hesaplanır ve asallığı kontrol edilir; asal olmayan ilk değerde çıkılacağı için while daha uygundur. $a^4+b^4+c^4=d^4$ için dört iç içe döngü gerekir, çünkü $d$ diğer üçünden doğrudan elde edilemez (ya da dördüncü dereceden kök alınmalıdır). Sayılar 400 bin civarında olduğundan arama çok fazla işlem ister; bu yüzden karşıt örnek ancak hızlı bilgisayarlarla bulunabilmiştir. Goldbach önermesi ise bugün 1988 öncesindeki o önermenin durumundadır: ne karşıt örnek bulunmuştur ne de ispat.

  > **Ders sonrası not:** Python ile kontrol: $n = 40$ için $1681 = 41^2$, $n = 41$ için $1763 = 41\cdot 43$; ikisi de asal değil. $95800^4 + 217519^4 + 414560^4 = 422481^4$ eşitliği tam sayı aritmetiğiyle doğrulandı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
