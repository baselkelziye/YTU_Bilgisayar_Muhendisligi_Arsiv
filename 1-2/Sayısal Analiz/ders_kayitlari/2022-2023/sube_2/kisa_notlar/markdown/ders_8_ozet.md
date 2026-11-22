# Ders 8 Çalışma Özeti

## Genel Konular

- Sonlu farklar (finite differences) konusuna giriş
  - Çıkış noktası örüntü bulma problemleridir: $1, 2, 4, 7, 11, 16, 22$ dizisinde ardışık terimlerin farkları $1, 2, 3, 4, 5, 6$ olduğu için sonraki terim $29$ bulunur.
  - Ardışık terimlerin farkını almak, sayısal türevdeki fark işlemine benzer. $1, 4, 9, 16$ ($x^2$) dizisinin birinci farkları $3, 5, 7$, ikinci farkları sabit $2$'dir; bu, $x^2$'nin ikinci türevinin $2$ olmasına karşılık gelir.
  - Gerçek hayatta fonksiyonun kuralı verilmez, yalnız $(x, f(x))$ veri ikilileri verilir. Sonlu farklar, bu verilerden fonksiyonu tahmin etmeye yarayan enterpolasyon ve regresyon yöntemlerinin temelidir.
- Fark aralığı ve operatörler
  - Birbirini takip eden iki ayrık nokta arasındaki farka fark aralığı denir ve $h$ ile gösterilir: $h = x_{k+1} - x_k$ (ekrandan, 00:10:00).
  - İleri fark $\Delta$: ilerideki noktadan bulunulan nokta çıkarılır. Geri fark $\nabla$: bulunulan noktadan gerideki nokta çıkarılır. Merkezi fark $\delta$: bulunulan noktanın $h/2$ ilerisi ile $h/2$ gerisi arasındaki farktır. Ortalama operatörü $\mu$ da merkezi farkla ilişkilidir.
  - Kaydırma (shifting) operatörü $E$: $E f(x) = f(x+h) = f(x) + \Delta f(x)$, $E^2 f(x) = f(x+2h)$, $E^n f(x) = f(x+nh)$.
  <!-- BELİRSİZ: Operatör tanımlarının ve μ operatörünün slaytı karelerde yok; μ'nün tam tanımı altyazıdan yalnız "merkezi farkın ikiye bölümü" diye anlaşılıyor. -->
- Yüksek dereceden farklar
  - 1. derece ileri fark: $\Delta f_i = f_{i+1} - f_i$, $i = 0, 1, \dots, n$ (ekrandan, 00:15:00).
  - 2. derece ileri fark: $\Delta^2 f_i = \Delta f_{i+1} - \Delta f_i = f_{i+2} - 2f_{i+1} + f_i$ (ekrandan, 00:15:00).
  - 3. derece ileri farkta katsayılar $1, -3, 3, -1$ olur. Katsayılar binom katsayılarıdır (Pascal üçgeni) ve işaretler artı-eksi sırasıyla değişir.
  - Geri farklarda aynı mantık $f_i - f_{i-1}$ ile kurulur.
  - Merkezi farkta yarım indisler kullanılır: $\delta f_i = f_{i+1/2} - f_{i-1/2}$, $\delta^2 f_i = f_{i+1} - 2f_i + f_{i-1}$, $\delta^3 f_i = f_{i+3/2} - 3f_{i+1/2} + 3f_{i-1/2} - f_{i-3/2}$ (ekrandan, 00:20:00).
  - Genel formül: $\Delta^k f_k = \sum_{i=0}^{k} (-1)^i \binom{k}{i} f_{k-i}$. $k=5$ için $\Delta^5 f_5 = f_5 - 5f_4 + 10f_3 - 10f_2 + 5f_1 - f_0$ (ekrandan, 00:25:00).
- Sonlu fark tabloları
  - Her sütun bir önceki sütunun ardışık farklarından oluşur. $n+1$ nokta varsa en fazla $n$. dereceden fark alınabilir.
  - Örnek: $F(x) = x^3 - 3x$, $h = 1$, $[-3, 2]$ aralığı. $f$: $-18, -2, 2, 0, -2, 2$; $\Delta f$: $16, 4, -2, -2, 4$; $\Delta^2 f$: $-12, -6, 0, 6$; $\Delta^3 f$: $6, 6, 6$; $\Delta^4 f$: $0, 0$ (ekrandan, 00:30:00).
  - $n$. dereceden bir polinomun $n$. farkı sabittir, $(n+1)$. farkı sıfırdır. $P_n(x) = a_0 x^n + \dots + a_n$ için $\Delta^3 P_3(x) = 6 a_0 h^3$; $h = 1$, $a_0 = 1$ için $6$ bulunur ve tablodaki değerle aynıdır (ekrandan, 00:30:00).
- Sonlu farklarda hatanın yayılması
  - Tablodaki bir değer, geriye doğru izlendiğinde (backtracking) önceki sütunlardaki birden fazla değere bağlıdır.
  - $f_3$ değeri $\varepsilon$ kadar hatalı hesaplanırsa hata, sonraki sütunlara binom katsayılarıyla yayılır: 1. farkta $\varepsilon, -\varepsilon$; 2. farkta $\varepsilon, -2\varepsilon, \varepsilon$; 3. farkta $\varepsilon, -3\varepsilon, 3\varepsilon, -\varepsilon$.
- Enterpolasyona giriş
  - Enterpolasyon, tablo halinde verilen bir değişkenin tabloda olmayan bir ara değerini bulmaktır. Üretilen fonksiyon verilen bütün noktalardan geçmelidir.
  - Verilen aralığın dışında tahmin yapmaya ekstrapolasyon denir.
  - Enterpolasyon fonksiyonu doğru, polinom, logaritmik, üstel, trigonometrik ya da parçalı (spline, "şerit") olabilir. Çok sayıda nokta varsa bütün noktalardan geçen fonksiyon üretmek güçtür; bu durumda regresyona başvurulur.
  - Polinomlar tercih edilir: basit, türevi ve integrali kolay alınır, modellemesi kolaydır. Periyodik verilerde sinüs ve kosinüs toplamı (katsayılar $a_k$, $b_k$) tercih edilir.
  - Sürekli bir $f(x)$ için $[a,b]$ aralığında, gerçek değerle tahmin arasındaki farkın mutlak değeri küçük bir $\varepsilon$'dan az kalacak bir polinom kullanılabilir.
- Doğrusal enterpolasyon
  - İki noktası bilinen doğrunun denklemini bulmaktır: $\dfrac{f(x_2) - f(x_1)}{x_2 - x_1} = \dfrac{f(x_3) - f(x_1)}{x_3 - x_1}$ (ekrandan, 00:45:00).
  - $F(x) = Ax + B$ seçilir; $F(a) = f(a)$ ve $F(b) = f(b)$ koşullarından $A$ eğim olarak, $B$ de noktalardan biri yerine konarak bulunur (ekrandan, 00:55:00).
  - Örnek: tablodan $f(2)$, $x=1$ ve $x=3$ kullanılarak $0{,}4912955$ bulunur; $x=-2$ ve $x=6$ kullanılınca sonuç $-0{,}594356$ olur (ekrandan, 00:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sonlu fark tablolarının ilk satırlarındaki (başlangıç) değerler
  - İlerleyen derslerde verilerden polinom üretirken bu başlangıç değerleri kullanılacaktır.
- Farkların bir yerden sonra sıfırlanması
  - Polinomun derecesi kadar fark alınca sabite, bir fazlasında sıfıra ulaşılır. Uygulamada en çok üçüncü dereceden polinom kullanıldığı için en fazla dört fark yeterli olur.
- Hatanın yayılması
  - Tablonun başındaki küçük bir hata, binom katsayılarıyla büyüyerek sonucu ciddi biçimde etkileyebilir.
- Enterpolasyon bir tahmindir, kesin belirleme değildir
  - Doğrusal enterpolasyonda hangi iki noktanın seçildiği hatayı etkiler. Aranan noktaya en yakın noktaları seçmek (yakınlaştırma, "zoom" yapmak gibi) genelde daha doğru sonuç verir, ama kesin bir şey söylenemez.
- Train, test ve ground truth
  - Verilen noktaların bir kısmıyla model (doğru) üretilir, kalan noktalarla test edilir. Gerçek değerlere literatürde "ground truth" denir; görüntü işlemede tahmin ile ground truth arasındaki fark sıfıra yakınsa tahmin doğrudur.

## Kısa Tekrar Notları

- $h = x_{k+1} - x_k$ fark aralığıdır.
- $\Delta f_i = f_{i+1} - f_i$, $\nabla f_i = f_i - f_{i-1}$, $\delta f_i = f_{i+1/2} - f_{i-1/2}$.
- $E f(x) = f(x+h)$, $E^n f(x) = f(x+nh)$.
- $\Delta^2 f_i = f_{i+2} - 2f_{i+1} + f_i$; katsayılar Pascal üçgeninden gelir, işaretler değişir.
- $\Delta^k f_k = \sum_{i=0}^{k} (-1)^i \binom{k}{i} f_{k-i}$.
- $n$. derece polinomun $n$. farkı sabit, $(n+1)$. farkı sıfırdır; kübik için $\Delta^3 P_3 = 6a_0h^3$.
- Bir değerdeki $\varepsilon$ hatası, $k$. fark sütununda $\binom{k}{i}$ katsayılarıyla ve değişen işaretlerle yayılır.
- Enterpolasyon: aralığın içinde ara değer; ekstrapolasyon: aralığın dışında tahmin.
- Doğrusal enterpolasyon $F(x) = Ax + B$ doğrusudur; aranan noktaya yakın iki nokta seçmek genelde daha iyidir.
- Çok sayıda noktada parça parça (spline) enterpolasyon ya da regresyon kullanılır.

## Detaylı Açıklamalar

- **Sonlu farkların mantığı:** Bir dizinin ardışık terimlerini birbirinden çıkarmak, sürekli fonksiyonlarda türev almanın ayrık karşılığıdır. $x^2$ değerlerinin ($1, 4, 9, 16$) birinci farkları $3, 5, 7$, ikinci farkları $2, 2$ olur. Bu, $x^2$'nin birinci türevinin $2x$, ikinci türevinin $2$ olmasıyla örtüşür. Bir veri kümesinde farklar bir yerde sabitlenip sonra sıfırlanıyorsa, veri büyük ölçüde bir polinomdan gelmektedir ve polinomun derecesi sabitlenen fark derecesidir. Bu gözlem, verilen tablodan polinom tahmin etmenin temelidir.
- **İleri fark formüllerinin açılması:** $\Delta^2 f_i = \Delta(\Delta f_i) = \Delta(f_{i+1} - f_i) = \Delta f_{i+1} - \Delta f_i$ yazılır. $\Delta f_{i+1} = f_{i+2} - f_{i+1}$ ve $\Delta f_i = f_{i+1} - f_i$ yerine konunca $\Delta^2 f_i = f_{i+2} - 2f_{i+1} + f_i$ çıkar (ekrandan, 00:15:00). Daha yüksek dereceler aynı biçimde açılır ve katsayılar $(x+y)^n$ açılımındaki binom katsayılarına eşittir. Genel formülde $(-1)^i$ terimi işaretin artı-eksi değişmesini, $\binom{k}{i}$ katsayıyı verir. $\binom{k}{i} = \binom{k}{k-i}$ eşitliği hesabı kolaylaştırır; örneğin $\binom{10}{8}$ yerine $\binom{10}{2}$ hesaplanır, çünkü 10 elemandan 8'ini seçmek, seçilmeyecek 2'sini seçmekle aynı sayıda durum verir.
- **$k=5$ örneği:** $\Delta^5 f_5 = \sum_{i=0}^{5} (-1)^i \binom{5}{i} f_{5-i}$ formülünde $i = 0, \dots, 5$ için terimler $f_5$, $-5f_4$, $10f_3$, $-10f_2$, $5f_1$, $-f_0$ olur (ekrandan, 00:25:00). Formüldeki $f_5$ indisi, slaytta açılımın $f_0$'dan $f_5$'e kadar değerleri kullandığını gösterir. Bu formül, farkları sütun sütun hesaplamadan doğrudan sonuca ulaşmayı sağlar.
- **Merkezi farklar:** İndisler normalde tam sayıdır, ama merkezi farkta $i+1/2$ gibi yarım noktalar varmış gibi düşünülür. Birinci merkezi fark $f_{i+1/2} - f_{i-1/2}$'dir. İkinci merkezi fark tam sayılı noktalara döner: $f_{i+1} - 2f_i + f_{i-1}$. Üçüncü merkezi fark ise $f_{i+3/2} - 3f_{i+1/2} + 3f_{i-1/2} - f_{i-3/2}$ olur (ekrandan, 00:20:00). Hoca, merkezi farkın pratikte pek kullanılmadığını belirtti.
- **Sonlu fark tablosu örneği:** $F(x) = x^3 - 3x$, $h = 1$, $x = -3, -2, -1, 0, 1, 2$ için $f$ değerleri $-18, -2, 2, 0, -2, 2$'dir. Birinci farklar $-2-(-18) = 16$, $2-(-2) = 4$, $0-2 = -2$, $-2-0 = -2$, $2-(-2) = 4$; ikinci farklar $-12, -6, 0, 6$; üçüncü farklar $6, 6, 6$; dördüncü farklar $0, 0$ olur (ekrandan, 00:30:00). Üçüncü farkın sabit $6$ çıkması, $x^3$'ün türevlerinin $3x^2 \to 6x \to 6$ olmasıyla açıklanır ve $6a_0h^3 = 6 \cdot 1 \cdot 1^3 = 6$ formülüyle doğrulanır. Değerler python ile kontrol edildi.
- **Hatanın yayılması:** Tablodaki $-6$ değeri $-2$ ve $4$'ten, onlar da önceki sütundaki üç değerden hesaplanır. Böylece bir değer, geriye doğru gittikçe giderek daha fazla değere bağlanır. Tersinden bakıldığında, $f_3$'te yapılan bir $\varepsilon$ hatası birinci farklarda iki değeri ($+\varepsilon$, $-\varepsilon$), ikinci farklarda üç değeri ($\varepsilon, -2\varepsilon, \varepsilon$), üçüncü farklarda dört değeri ($\varepsilon, -3\varepsilon, 3\varepsilon, -\varepsilon$) etkiler.
- **Enterpolasyonun yeri:** Elimizde fonksiyon değil, $(x, y)$ noktaları vardır. Örneğin $x = 8$ için $y = 18$, $x = 9$ için $y = 29$ verilmişken $x = 8{,}25$'in değeri istenebilir (ekrandan, 00:40:00). Enterpolasyonda bütün noktalardan geçen bir eğri üretilir ve ara değer bu eğriden okunur. Nokta sayısı çok fazlaysa (ekrandaki "Interpolasyon Örnekleri" grafiğindeki gibi dağınık veri) bütün noktalardan geçen bir fonksiyon üretmek güçleşir, hatta fonksiyon tanımına aykırı bir eğri çıkabilir; bu durumda regresyon kullanılır. İkinci yaklaşım veriyi bölgelere ayırıp her bölgeye ayrı bir fonksiyon uydurmaktır (spline).
- **Doğrusal enterpolasyon örneği:** Tabloda $x = -2, -1, 0, 1, 3, 4, 6$ için $f(x)$ değerleri $-0{,}909297$, $-0{,}841471$, $0$, $0{,}841471$, $0{,}141120$, $-0{,}756802$, $-0{,}279415$'tir (ekrandan, 00:50:00). (a) $x=1$ ve $x=3$ ile $\frac{0{,}141120 - 0{,}841471}{2} = \frac{f(2) - 0{,}841471}{1}$ yazılır ve $f(2) = 0{,}4912955$ bulunur. (b) $x=-2$ ve $x=6$ ile $\frac{f(6) - f(-2)}{6-(-2)} = \frac{f(2) - f(6)}{2-6}$ kurulur; derste sonuç hesaplanmadı, hesaplanınca $f(2) \approx -0{,}594356$ çıkar. Hoca, aranan noktaya daha yakın olan (a) seçeneğinin büyük olasılıkla daha doğru olduğunu, ama bunun kesin olmadığını vurguladı.
- **Ders sonrası not:** Tablodaki değerler $\sin x$ değerleriyle birebir aynıdır; veri büyük olasılıkla $\sin x$ fonksiyonundan alınmıştır. Bu durumda gerçek değer $\sin 2 \approx 0{,}909297$'dir ve (a) seçeneği gerçeğe daha yakındır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
