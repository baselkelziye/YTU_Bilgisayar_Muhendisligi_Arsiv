# Ders 3 Çalışma Özeti

## Genel Konular

- Kapalı yöntemlerden açık yöntemlere geçiş
  - Kapalı yöntemlerde (ikiye bölme, regula falsi) kök bir $[a,b]$ aralığında aranır; kökün varlığı önce doğrulanır, ama gerçek köke ulaşmak uzun sürebilir.
  - Açık yöntemlerde tek bir noktadan ($x_i$) başlanır ve $x_{i+1}$'e geçilir. İyileşme varsa çözüme yaklaşılıyor (yakınsama, convergence), kötüleşme varsa uzaklaşılıyor (ıraksama, divergence) demektir.
  - Derste üç açık yöntem işlendi: Newton-Raphson, sekant (kiriş) ve tekrarlama (sabit nokta, fixed point iteration) yöntemi (ekrandan, 00:30:00).
- Newton-Raphson yöntemi
  - Doğrusal olmayan ve analitik çözümü olmayan tek bilinmeyenli denklemlerin gerçek köklerini bulmada kullanılır. Açık aralık metodudur; $[a,b]$ verilse de hesaplanan değerler aralığın dışına çıkabilir (ekrandan, 00:10:00).
  - Bazen ıraksar, ama yakınsadığında kökü en hızlı bulan yöntemdir. Köke türevle (teğetle) yaklaşır. Başlangıç değeri verilmezse küçük olan aralık değerinden başlamak önerilir (ekrandan, 00:10:00).
  - Formül: $x_{i+1} = x_i - \dfrac{f(x_i)}{f'(x_i)}$.
  - Türetme 1: $(x_0, f(x_0))$ noktasından eğimi $f'(x_0)$ olan teğet çizilir: $y - f(x_0) = f'(x_0)(x - x_0)$. Teğetin $x$ eksenini kestiği yerde $y = 0$ konur, $x_1$ çekilir.
  - Türetme 2: Taylor serisinde $f(x_0 + h) \approx f(x_0) + f'(x_0)h$ alınır (ilk iki terim), $f(x_0+h)=0$ yazılarak aynı formül bulunur.
  - Tek zorluğu türevdir: üstel, trigonometrik, logaritmik ve iç içe fonksiyonların sembolik türevini almak zorlaşabilir.
- Sekant (kiriş) yöntemi
  - Türev yerine, birbirine yakın iki noktadan geçen doğru (kiriş) kullanılır. Böylece türev almanın maliyetinden kaçılır.
  - İki noktası bilinen doğru denkleminde $y = 0$ konarak yeni nokta bulunur: $x_{k+1} = x_k - \dfrac{f(x_k)\,(x_{k-1} - x_k)}{f(x_{k-1}) - f(x_k)}$ (ekrandan, 00:35:00).
  - Sonraki adımda en eski nokta bırakılır, son iki nokta ile yeni kiriş çizilir.
  - Başlangıç noktaları yerine $x_k$ ve bir $h$ adımı da verilebilir; $h$ küçültülerek (ör. $h/2$) ilerlenir.
- Tekrarlama (sabit nokta) yöntemi
  - $f(x) = 0$ denklemi $x = g(x)$ biçimine getirilir; $f(x) = x - g(x)$ olduğu için denklem değişmez (ekrandan, 00:40:00).
  - Kök, $y = g(x)$ ile $y = x$ doğrusunun kesiştiği noktadır. İterasyon: $x_{k} = g(x_{k-1})$.
  - Aynı $f(x)$'ten birden çok $g(x)$ türetilebilir; bazıları yakınsar, bazıları ıraksar.
  - Uygunluk testi: kökün $[a,b]$ aralığında olması ($f(a)f(b) < 0$), $f$ ve $g$'nin aralıkta türevlenebilir olması, $|g'(a)| < 1$ ve $|g'(b)| < 1$ olması. Hoca bunun her zaman işe yaramadığını, istisnaları olduğunu söyledi.
  - Durma koşulları: $N$ iterasyon yapmak; gerçek kök $p$ biliniyorsa $|p - x_{i+1}| < \text{TOL}$; bilinmiyorsa $|x_{i+1} - x_i| < \text{TOL}$ (ekrandan, 00:55:00).
- Fonksiyonların bilgisayarda gösterimi (proje hazırlığı)
  - Polinom $a_0x^n + a_1x^{n-1} + \dots + a_n$: dereceler tam sayı olduğu için dizi indisi derece, dizi elemanı katsayı olarak tutulabilir (`double array[20]`).
  - Dezavantaj: eksik terimler için gereksiz yer ayrılır ($6x^{20} - x^{19}$ için 21 eleman).
  - Alternatif 1: iki sütunlu `double` matris (katsayı, kuvvet). Kuvvet tam sayı olduğu hâlde `double` olarak saklanır.
  - Alternatif 2: katsayılar için `double` dizi, kuvvetler için `int` dizi.
  - Trigonometrik terim $A\cos(x)$ ya da $A\cos(P(x))$, üstel terim $a^{x}$, logaritmik terim katsayı, taban ve argüman değişkenleriyle tutulabilir.
  - Daha esnek yapı için C'de `struct` (`typedef struct`) ile katsayı ve üs alanları olan bir terim türü tanımlanabilir.
- Doğrusal denklem takımlarına giriş ve matris işlemleri
  - Matrisler C'de bellekte satır satır, ardışık adreslerde tutulur; `double` elemanlar arasında 8 byte fark vardır (ekrandan, 01:45:00).
  - Matris türleri: alt ve üst üçgen, birim, köşegen, band, simetrik ($A = A^T$), ortogonal.
  - Matris eşitliği, kofaktör, adjoint ve ters matris ($A^{-1} = \operatorname{adj}(A)/\det A$) tanımlandı (ekrandan, 01:50:00).
  - Toplama/çıkarma aynı boyutta eleman eleman yapılır; matrislerde bölme yoktur, yalnız sayıya bölünebilir (ekrandan, 01:55:00).
  - Elementer satır işlemleri: satırı sabitle çarpma, iki satırın yerini değiştirme, bir satırın katını başka satıra ekleme (ekrandan, 02:00:00).
  - Ters matris $[A \mid I]$ genişletilmiş matrisinde $A$ birim matrise çevrilerek bulunur (Gauss-Jordan) (ekrandan, 02:05:00; 02:10:00).
  - Kare olmayan matris için yaklaşık (pseudo) ters: $A^TA$ ya da $AA^T$ kare matrisi üzerinden.

## Hocanın Özellikle Vurguladığı Kısımlar

- Iraksamanın fark edilmesi
  - Ardışık kökler arasındaki fark her adımda azalmalıdır. Fark büyüyorsa kökten uzaklaşılıyordur; algoritma hemen durdurulmalı, başlangıç noktası ya da $g(x)$ değiştirilmelidir.
  - Newton-Raphson'da ıraksama genelde yanlış başlangıç noktasından kaynaklanır; fonksiyonun artan/azalan olmasıyla ilgili değildir.
- Gerçek kök bilinmiyorsa ne zaman durulur?
  - $|x_{i+1} - x_i|$ belirli bir $\varepsilon$ değerinin altına inince durulur. Gerçek köke göre durma pratikte gerçekçi değildir, çünkü kök zaten aranmaktadır.
- Newton-Raphson'un pratikteki yeri
  - Birçok programlama dilinin karekök (`sqrt`) gibi kütüphane fonksiyonlarının içinde bu yöntem bulunur. $\sqrt{7}$ gibi bir değer $x^2 - 7 = 0$ denkleminin kökü olarak bulunabilir.
- Türev sorunu
  - Bilgisayarda türev sembolik olarak gösterilmelidir; zor fonksiyonlarda bu yüzden sekant yöntemi ya da ileride görülecek sayısal türev kullanılır.
- Ters matris şartları
  - Yalnız kare matrisin tersi alınabilir ve determinant sıfırdan farklı olmalıdır. Bir satırı tamamen sıfır olan matrisin determinantı sıfırdır, tersi yoktur.
  - Gauss-Jordan'da $(1,1)$ elemanı sıfır olmamalıdır; sıfırsa önce satırların yeri değiştirilir (ekrandan, 02:05:00).
- Matris işlemlerinin maliyeti
  - Eşitlik kontrolü iki, çarpım üç iç içe döngü ister; çarpım $O(n^3)$ karmaşıklıktadır. Ters alma da pahalıdır; bu yüzden algoritmik iyileştirmeler ve yaklaşık çözümler önemlidir.
- `scanf` ile matris hücresi okunurken adres operatörü `&` mutlaka yazılmalıdır; karakter dizisinin adı zaten adres olduğu için orada gerekmez.

## Kısa Tekrar Notları

- Açık yöntemler: Newton-Raphson, sekant, tekrarlama. Hızlıdırlar ama ıraksayabilirler.
- Newton-Raphson: $x_{i+1} = x_i - f(x_i)/f'(x_i)$; teğet doğrusu ya da Taylor serisinin ilk iki terimiyle türetilir.
- Sekant: $x_{k+1} = x_k - f(x_k)(x_{k-1}-x_k)/(f(x_{k-1})-f(x_k))$; türev gerekmez.
- Tekrarlama: $x = g(x)$, $x_k = g(x_{k-1})$; uygunluk için $|g'(a)|<1$, $|g'(b)|<1$.
- Durma: $N$ iterasyon, $|p - x_{i+1}| < \text{TOL}$ ya da $|x_{i+1} - x_i| < \text{TOL}$.
- Kutu problemi: $V(x) = (6-2x)^2x$, $V'$'nin kökü Newton-Raphson ile $x = 1$, $V_{\max} = 16$ birim küp.
- $x^2 - 2x - 3 = 0$, $x_0 = 4$: $g(x)=\sqrt{2x+3}$ ile 3'e, $g(x) = 3/(x-2)$ ile $-1$'e yakınsar; $g(x) = (x^2-3)/2$ ıraksar.
- Polinom: dizi (indis = derece), iki sütunlu matris ya da ayrı katsayı/kuvvet dizileri; esnek yapı için `struct`.
- Matris C belleğinde satır satır, ardışık durur.
- $A^{-1} = \operatorname{adj}(A)/\det A$; Gauss-Jordan ile $[A \mid I] \to [I \mid A^{-1}]$.
- $\begin{bmatrix}1&2\\3&4\end{bmatrix}^{-1} = \begin{bmatrix}-2&1\\ 3/2&-1/2\end{bmatrix}$.

## Detaylı Açıklamalar

- Newton-Raphson ve kutu problemi
  - Kenarı $a = 6$ olan bir karenin dört köşesinden $x$ boyunda kareler kesilip üstü açık kutu yapılıyor. Hacim $V = (6-2x)^2x = 4x^3 - 24x^2 + 36x$. Slaytta ifade 4'e bölünerek $V = x^3 - 6x^2 + 9x$, $V' = 3x^2 - 12x + 9$, sadeleşmiş hâli $x^2 - 4x + 3$ olarak alındı (ekrandan, 00:25:00).
  - Maksimum için $V'$'nin kökü aranır: $f(x) = x^2 - 4x + 3$, $f'(x) = 2x - 4$. $x_0 = 0$, hata $0{,}001$ (ekrandan, 00:20:00).
  - İterasyonlar: $0 \to 0{,}75 \to 0{,}975 \to 0{,}9996 \to \approx 1$ (ekrandan, 00:25:00). Gerçek kökler 1 ve 3'tür; $x=3$ hacmi sıfır yaptığı için çözüm $x = 1$, $V = 4^2\cdot 1 = 16$ birim küptür.
  - Ders sonrası not: Slayttaki son satırda $f(0{,}9996)$ değeri $9{,}903\cdot10^{-4}$ ve sonuç $1{,}000095$ yazıyor. Python ile kontrolde $f(0{,}9996) \approx 8{,}0\cdot10^{-4}$, sonraki değer $\approx 1{,}0000006$ çıkıyor (tam zincirle $x_3 = 0{,}999695$, $x_4 \approx 0{,}99999995$). Kök 1 olduğu için sonuç değişmiyor.
- Sekant örneği
  - Örnekte $x_{-1} = 10$, $x_0 = 5$ ile sinüs içeren bir fonksiyon kullanıldı. Hesap makinesinde sinüs hesaplanırken açının radyan/derece dönüşümüne dikkat edilmesi gerektiği söylendi. <!-- BELİRSİZ: fonksiyonun kendisi incelenen karelerde görünmüyor -->
  - Ekrandaki ara değerler: $x_1 = 4{,}931924$, $x_2 = 3{,}813366$, $x_3 = 3{,}234929$, $x_4 = 2{,}754669$, $x_5 = 2{,}578048$, $x_6 = 2{,}544745$, $x_7 = 2{,}543023$, $x_8 = x_9 = 2{,}543009$; kök $\approx 2{,}543009$ (ekrandan, 00:35:00).
- Tekrarlama yöntemi örnekleri
  - $\sin x + x - 1 = 0$, $[0,1]$: $g(x) = 1 - \sin x$. $f(0) = -1$, $f(1) = 0{,}84$, kök var; $f$ ve $g$ türevlenebilir (ekrandan, 00:50:00). $g'(x) = -\cos x$: $|g'(0)| = 1$ (şart sağlanmaz), $|g'(1)| \approx 0{,}54$. Bu yüzden $x_0 = 1$ seçildi.
  - $x^2 - 9x - 10 = 0$ için üç aday: $g(x) = \sqrt{9x+10}$, $g(x) = (x^2-10)/9$, $g(x) = 10/(x-9)$ (ekrandan, 00:45:00). İlki $x_0 = 0$'dan $\sqrt{10}$, $\sqrt{9\sqrt{10}+10}$, … diye 10'a, diğer ikisi $-1$'e yakınsar.
  - Ders sonrası not: Hoca köklerin $-10$ ve $+1$ olduğunu söyledi; $x^2-9x-10 = (x-10)(x+1)$ olduğu için doğrusu $10$ ve $-1$'dir.
  - $x^2 - 2x - 3 = 0$, $x_0 = 4$, hata $0{,}005$: $g(x) = \sqrt{2x+3}$ ile $4 \to 3{,}316 \to 3{,}104 \to 3{,}034 \to 3{,}011 \to 3{,}004 \to 3{,}001$, son fark $0{,}003 <$ hata, kök $3{,}001$ (ekrandan, 01:20:00). $g(x) = 3/(x-2)$ ile fark önce artar ($2{,}5$; $7{,}5$; $5{,}625$), sonra azalır ve $-1$'e yakınsar. $g(x) = (x^2-3)/2$ ile $4 \to 6{,}5 \to 19{,}625 \to \dots$ ıraksar.
- Matrislerin bellekte yerleşimi
  - Derste `double polinom[MAX][3]` (MAX = 5) matrisinin her elemanının adresi `%p` ile yazdırıldı; 15 adresin 8'er byte artarak ardışık geldiği görüldü (ekrandan, 01:45:00). Kod ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı, aynı davranış (15 ardışık adres, 8 byte aralık) görüldü.
- Gauss-Jordan ile ters matris
  - $2\times2$ örnek: $\left[\begin{smallmatrix}1&2\\3&4\end{smallmatrix} \middle| \begin{smallmatrix}1&0\\0&1\end{smallmatrix}\right]$; $-3S_1 + S_2 \to S_2$, $-\tfrac12 S_2 \to S_2$, $-2S_2 + S_1 \to S_1$ işlemleriyle sonuç $\left[\begin{smallmatrix}-2&1\\3/2&-1/2\end{smallmatrix}\right]$ (ekrandan, 02:05:00).
  - $3\times3$ örnek: $A = \left[\begin{smallmatrix}5&2&-4\\1&4&2\\2&3&6\end{smallmatrix}\right]$. Birinci satır $a_{11} = 5$'e bölünür: $[1;\ 0{,}4;\ -0{,}8 \mid 0{,}2;\ 0;\ 0]$ (ekrandan, 02:10:00). Sonra alttaki elemanlar sıfırlanır, ikinci satır $3{,}6$'ya bölünür, devam edilir.
  - Ders sonrası not: Hoca ortogonal matrisi "kendisi ve tersi birbirine eşit olan matris" diye tanımladı; doğrusu, transpozu tersine eşit olan ($A^T = A^{-1}$) matristir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
