# Ders 7 Çalışma Özeti

## Genel Konular

- Trapez (yamuk) yönteminin kısa tekrarı
  - $[a,b]$ aralığı $h$ genişlikli parçalara bölünür, fonksiyonun bu noktalardaki değerleri bir diziye yazılır.
  - İlk ve son değer bir kez, aradaki değerler iki kez alınır, toplam $h/2$ ile çarpılır: $\int_a^b f(x)\,dx \approx \frac{h}{2}\left[y_0 + y_n + 2\sum_{i=1}^{n-1} y_i\right]$.
- Simpson 1/3 kuralı
  - İki nokta arasına doğru çizmek yerine üç noktadan geçen ikinci dereceden bir eğri (parabol) $f(x)=ax^2+bx+c$ uydurulur. Amaç hatayı azaltmaktır.
  - Sınırlar $-h$ ve $h$ alınınca integral $S = \frac{2}{3}ah^3 + 2ch = \frac{h}{3}(2ah^2+6c)$ olur (ekrandan, 00:15:00).
  - $y_0=f(-h)$, $y_1=f(0)=c$, $y_2=f(h)$ yazılır. $y_0+y_2 = 2ah^2+2c$ olduğundan $2ah^2 = y_0-2y_1+y_2$ bulunur. Yerine konunca tek parabol formülü $S=\frac{h}{3}(y_0+4y_1+y_2)$ çıkar.
  - Bileşik (çok parçalı) biçim: $S_1=\frac{h}{3}(y_0+4y_1+y_2)$, $S_2=\frac{h}{3}(y_2+4y_3+y_4)$, ..., $S_n=\frac{h}{3}(y_{2n-2}+4y_{2n-1}+y_{2n})$ toplanır (ekrandan, 00:20:00).
  - Sonuç formülü: $S=\frac{h}{3}\left[f(x_0)+f(x_n)+4\sum_{k=1,3,5}^{n-1} f(x_0+kh)+2\sum_{i=2,4,6}^{n-2} f(x_0+ih)\right]$, $h=(x_n-x_0)/n$ (ekrandan, 00:30:00).
  - Kural: baş ve son değer bir kat, tek indisliler dört kat, aradaki çift indisliler iki kat alınır, toplam $h/3$ ile çarpılır.
- Simpson 1/3 örnekleri
  - $y=x^3$ eğrisi, $x=-1$, $x=2$ ve $Ox$ ekseniyle sınırlı bölgenin alanı: alan $[-1,0]$ ve $[0,2]$ diye ikiye ayrılır, negatif kısım eksiyle çarpılır, toplam $4{,}25$ (ekrandan, 00:35:00).
  - $\int_{-2}^{-1}(x^2-1)(x+2)\,dx$, $n=4$: trapez $0{,}3906$, Simpson $0{,}4166$, gerçek değer $0{,}4167$ (ekrandan, 00:40:00).
- Simpson 3/8 kuralı
  - Aralıkta üçüncü dereceden polinom $ax^3+bx^2+cx+d$ uydurulur. Dört bilinmeyen için dört nokta, yani üç eşit parça gerekir.
  - Formül: $\int_a^b f(x)\,dx \approx \frac{b-a}{8}\left[f(a)+3f(x_1)+3f(x_2)+f(b)\right]$, $x_1=a+\frac{b-a}{3}$, $x_2=a+2\frac{b-a}{3}$ (ekrandan, 00:45:00).
  - $n=2$ için aralık ortadan ikiye bölünür ve formül her yarıya ayrı uygulanır.
  - Örnek $\int_0^6 \frac{1}{1+x^4}dx$: $n=1$ için $0{,}8917$, $n=2$ için $1{,}0082+0{,}0110 \approx 1{,}0192$ (ekrandan, 00:50:00).
- İki katlı integralin sayısal çözümü
  - $z=f(x,y)$ iki değişkenli fonksiyonun integrali, düzlemin altında kalan hacmi verir.
  - İç integral her $x_i$ için ayrı bir tek katlı integral olarak çözülür ($g(x_i)$), sonra dış integral bu $g$ değerleri üzerinden yine tek katlı yöntemle hesaplanır. İç içe iki döngü gibi düşünülür.
  - Örnek: $I=\int_2^3\int_x^{2x^3}(x^2+y)\,dy\,dx$, her iki adımda Simpson 1/3 ile $n=4$ (ekrandan, 01:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Simpson ve trapez yöntemlerinde integral hesabı yapılmaz
  - Sonuç yalnız toplama, çıkarma, çarpma ve bölmeyle, döngülerle bulunur. Analitik integral yalnız gerçek sonuçla karşılaştırıp mutlak hata bulmak için alınır.
- Simpson'da katsayı düzeni
  - Baş ve son bir kat, tekler dört kat, aradaki çiftler iki kat. Bu düzen, ardışık parabollerin uç noktalarının ortak olmasından gelir: bir parabolün üst sınırı sonrakinin alt sınırıdır.
- Simpson'da parça sayısı
  - Çubuklar ikişer ikişer alındığı için aralık sayısının çift olması gerekir (ekrandan, 00:30:00).
- Negatif alan
  - $Ox$ ekseninin altında kalan kısımda integral negatif çıkar. Alan istendiğinde bu kısım ayrı hesaplanıp eksiyle çarpılır.
- $h$ değeri soruda verilmez
  - Sınırlardan ve parça sayısından üretilir: $h=(b-a)/n$.
- Hata kavramları
  - Bir integral sorusunda mutlak ya da göreceli (relatif) hata da sorulabilir. Hata kavramları ve anlamlı basamak sayısı gibi temel konular göz ardı edilmemelidir.

## Kısa Tekrar Notları

- Trapez: $\frac{h}{2}[y_0+y_n+2(\text{aradakiler})]$.
- Simpson 1/3 tek parabol: $\frac{h}{3}(y_0+4y_1+y_2)$.
- Simpson 1/3 bileşik: $\frac{h}{3}[y_0+y_n+4(\text{tekler})+2(\text{aradaki çiftler})]$, aralık sayısı çift.
- Simpson 3/8: $\frac{b-a}{8}[f(a)+3f(x_1)+3f(x_2)+f(b)]$, $h=(b-a)/3$.
- Simpson 1/3 üçüncü dereceden polinomlarda bile tam sonuç verir: $x^3$ örneğinde $[0,2]$ için tam $4$ bulundu.
- Parça sayısı arttıkça sonuç gerçeğe yaklaşır ($3/8$ örneğinde $n=1$'den $n=2$'ye geçince).
- İki katlı integral: önce her $x_i$ için iç integral ($g_i$), sonra $g_i$ değerleri üzerinden dış integral.

## Detaylı Açıklamalar

- Simpson 1/3 kuralının mantığı
  - Trapez yöntemi iki nokta arasını doğru parçasıyla birleştirir. Simpson 1/3 ise üç noktadan geçen bir parabol kullanır. Parabolün integrali kolaydır: $\int(ax^2+bx+c)dx = a\frac{x^3}{3}+b\frac{x^2}{2}+cx$.
  - Sınırlar $-h$ ve $h$ seçilince $b$'li terimler birbirini götürür ve $S=\frac{2}{3}ah^3+2ch$ kalır. Katsayılar bilinmediği için fonksiyonun üç noktadaki değeri kullanılır: $x=-h$, $0$, $h$ yerine konunca $a$ ve $c$ bulunur. $x=0$ doğrudan sabit terimi ($c=y_1$) verir.
  - Böylece $S=\frac{h}{3}(y_0-2y_1+y_2+6y_1)=\frac{h}{3}(y_0+4y_1+y_2)$ elde edilir. "1/3" adı bu formüldeki $h/3$'ten gelir.
- Bileşik Simpson'ın toplanması
  - $[a,b]$ çok sayıda parçaya bölünür ve her iki parçaya bir parabol uydurulur. Örneğin üç parabol için: $S=\frac{h}{3}[(y_0+y_6)+4(y_1+y_3+y_5)+2(y_2+y_4)]$ (ekrandan, 00:25:00).
  - Parabol sayısı arttıkça yalnız son terim değişir. Örneğin dördüncü parabol eklenince $y_6$ artık uç değil, iki kat alınan ara çift olur.
- $y=x^3$ örneği
  - $[-1,0]$ aralığı için $h=0{,}25$: $x$ dizisi $-1, -0{,}75, -0{,}5, -0{,}25, 0$. Simpson sonucu $-0{,}25$, alan $0{,}25$.
  - $[0,2]$ aralığı için $h=0{,}5$: $x$ dizisi $0, 0{,}5, 1, 1{,}5, 2$. Simpson sonucu tam $4$.
  - Toplam alan $4{,}25$ birim karedir. Analitik kontrol: $\frac{x^4}{4}$ ile $[0,2]$ için $4$, $[-1,0]$ için $-\frac14$.
  - Ders sonrası not: Hoca $[-1,0]$ için yaklaşık $0{,}24$ bulunduğunu söyledi. Python ile kontrol edildiğinde Simpson 1/3 bu aralıkta tam $-0{,}25$ verir. Simpson 1/3 üçüncü dereceden polinomlar için hatasızdır.
- $(x^2-1)(x+2)$ örneği
  - $n=4$, $h=0{,}25$. Tablo: $f(-2)=0$, $f(-1{,}75)=0{,}5156$, $f(-1{,}5)=0{,}625$, $f(-1{,}25)=0{,}4218$, $f(-1)=0$ (ekrandan, 00:40:00).
  - Trapez: $\frac{0{,}25}{2}[0+0+2(0{,}5156+0{,}625+0{,}4218)] \approx 0{,}3906$; mutlak hata yaklaşık $0{,}026$ (python ile hesaplandı).
  - Simpson: $\frac{0{,}25}{3}[0+0+2\cdot 0{,}625+4(0{,}5156+0{,}4218)] \approx 0{,}4166$. Gerçek değer $\frac{5}{12}\approx 0{,}4167$.
  - Ders sonrası not: Slaytta $f(x_1)$ değeri formülün içinde $0{,}0156$ diye yazılmış. Tablodaki doğru değer $0{,}5156$'dır. $0{,}4166$ sonucu da ancak $0{,}5156$ ile çıkar.
- Simpson 3/8
  - Üçüncü dereceden polinomun dört katsayısı için dört nokta gerekir. Bu yüzden $[a,b]$ üç eşit parçaya bölünür: $a$, $a+h$, $a+2h$, $b$.
  - Ders sonrası not: Hoca $h$ için ekrana $(b-a)/4$ yazdı ve "dört parçaya böleceğiz" dedi. Dört nokta üç parça demektir; doğrusu $h=(b-a)/3$. Slayttaki $x_1=a+\frac{b-a}{3}$, $x_2=a+2\frac{b-a}{3}$ ifadeleri de bunu gösterir.
  - $\int_0^6\frac{dx}{1+x^4}$ için $n=1$: $h=2$, $\frac{6}{8}\left[1+\frac{3}{17}+\frac{3}{257}+\frac{1}{1297}\right]\approx 0{,}8917$.
  - $n=2$: $[0,3]$ ve $[3,6]$ ayrı ayrı, $h=1$. İlk yarı $\frac{3}{8}\left[1+\frac{3}{2}+\frac{3}{17}+\frac{1}{82}\right]\approx 1{,}0082$, ikinci yarı $\frac{3}{8}\left[\frac{1}{82}+\frac{3}{257}+\frac{3}{626}+\frac{1}{1297}\right]\approx 0{,}0110$, toplam $\approx 1{,}0192$ (ekrandan, 00:50:00).
  - Ders sonrası not: Çok ince bölmeli sayısal hesapla (python) integralin değeri yaklaşık $1{,}1092$ bulundu. $n=2$ sonucu $n=1$'e göre bu değere belirgin biçimde daha yakındır.
- İki katlı integral örneği
  - Dış integral için $n=4$, $h=(3-2)/4=0{,}25$, $x$ değerleri $2; 2{,}25; 2{,}5; 2{,}75; 3$.
  - $x_0=2$ için iç integral $\int_2^{16}(4+y)\,dy$, $h=(16-2)/4=3{,}5$, $y$: $2; 5{,}5; 9; 12{,}5; 16$, $f$: $6; 9{,}5; 13; 16{,}5; 20$. $g_0=\frac{3{,}5}{3}[(6+20)+2\cdot13+4(9{,}5+16{,}5)]=182$ (ekrandan, 01:10:00).
  - Diğer $x$ değerleri için üst sınır $2x^3$ büyüdükçe iç $h$ de büyür: $x_1=2{,}25$ için $h\approx5{,}13$, $x_2=2{,}5$ için $h\approx7{,}19$, $x_4=3$ için $y\in[3,54]$.
  - Python ile Simpson 1/3 kontrolü: $g_1\approx 360{,}90$, $g_2\approx 664{,}84$, $g_3\approx 1155{,}0$, $g_4=1912{,}5$. Dış Simpson: $I\approx 790{,}65$. Analitik değer $\approx 790{,}54$.
  <!-- BELİRSİZ: Bu ara sonuçların slayt karesi yok. Altyazıda g1 için "360.417", sonuç için "790.450" ve analitik değer için "790.55" duyuluyor; python değerleri yukarıdadır. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
