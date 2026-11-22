# Ders 6 Çalışma Özeti

## Genel Konular

- Sayısal integralin amacı
  - Sayısal türevde bir fonksiyonun türevinin belirli bir $x_i$ noktasındaki değeri yaklaşık hesaplanıyordu. Sayısal integralde ise belirli integralin $\int_a^b f(x)\,dx = C$ sayısal sonucu yaklaşık hesaplanır (ekrandan, 00:15:00).
  - Değişken dönüştürme, kısmi integrasyon (integration by parts), basit kesirlere ayırma gibi analitik yöntemlerle belirsiz integrali bulunamayan ya da bulunması çok güç fonksiyonlarda sınırlar yerine konamaz; bu durumda sayısal (iteratif) yöntemlerle yaklaşık sonuç bulunur. Buna sayısal integral (numerical integration) denir.
  - Belirli integral, geometrik olarak $a$ ile $b$ arasında fonksiyonun altında kalan alandır.
- Temel strateji: fonksiyonu polinoma benzetmek
  - Polinomların integrali kolaydır: $\int A x^n\,dx = \dfrac{A\,x^{n+1}}{n+1} + c$ (ekrandan, 00:20:00).
  - Sabit fonksiyonun altındaki alan bir dikdörtgendir (örneğin 2 ile 8 arasında değeri 4 olan sabit fonksiyon). Doğrusal, kuadratik, kübik fonksiyonların altındaki alan da analitik olarak kolay bulunur.
  - Karmaşık fonksiyon, integrali kolay alınan polinomlara benzetilir. Bu polinom ailesine Newton-Cotes formülleri denir.
  - Fonksiyonun $f(a)$, $f(b)$ gibi değerleri, programlama dillerinin matematik kütüphaneleriyle (ör. C'de `math.h`) kolayca hesaplanabilir.
- Yamukla yaklaşık alan ve parçalara bölme
  - $(a, f(a))$ ve $(b, f(b))$ noktalarından bir doğru geçirilirse alan bir yamuğa benzer: $A \approx \dfrac{(b-a)\,\big(f(a)+f(b)\big)}{2}$. Doğru ile eğri arasında hata kalır.
  - Aralığın ortası $c$ alınıp iki yamuk kullanılırsa ($A_1 + A_2$) hata azalır. Parça sayısı $n$ arttıkça sonuç gerçek değere yaklaşır; $n \to \infty$ limitinde gerçek integral elde edilir.
- Sayısal integral çeşitleri (ekrandan, 00:25:00)
  - Doğru uydurma, $f_n(x) = a_0 + a_1 x$: Yamuk kuralı (Trapezoidal Rule). İki nokta gerekir.
  - Parabol uydurma, $f_n(x) = a_0 + a_1 x + a_2 x^2$: Simpson'ın 1/3 kuralı. Üç nokta gerekir.
  - Kübik polinom uydurma, $f_n(x) = a_0 + a_1 x + a_2 x^2 + a_3 x^3$: Simpson'ın 3/8 kuralı. Dört nokta gerekir.
  - Parabol için üç noktanın $x$ değerleri ($\alpha$, $\beta$, $\theta$) ve görüntüleri yerine konunca $a_2$, $a_1$, $a_0$ için üç bilinmeyenli doğrusal bir denklem sistemi çıkar.
- Trapez (yamuk) yöntemi
  - $[a,b]$ aralığı $n$ eşit parçaya bölünür; parça genişliği $h = \dfrac{b-a}{n}$ (ekrandan, 00:30:00).
  - Noktalar $x_0 = a,\ x_1 = a+h,\ \dots,\ x_n = a+nh = b$; görüntüler $y_i = f(x_i)$.
  - Parça alanları $S_1 = \dfrac{A+B}{2}h$, $S_2 = \dfrac{B+C}{2}h$, $S_3 = \dfrac{C+D}{2}h$; toplam $\dfrac{h}{2}\big(A + D + 2(B + C)\big)$ (ekrandan, 00:35:00).
  - Genel formül: $I \approx \dfrac{h}{2}\Big(y_0 + 2\sum_{i=1}^{n-1} y_i + y_n\Big) = h\Big(\dfrac{y_0+y_n}{2} + \sum_{i=1}^{n-1} y_i\Big)$.
- Örnek: $\int_0^1 \frac{1}{1+x^2}\,dx$, $n=4$ (ekrandan, 00:40:00)
  - $h = 0{,}25$; $y = 1;\ 0{,}9412;\ 0{,}8;\ 0{,}64;\ 0{,}5$.
  - $I \approx 0{,}125 \cdot 1{,}5 + 0{,}25\,(0{,}9412 + 0{,}8 + 0{,}64) \approx 0{,}7828$.
  - Gerçek değer $\arctan 1 - \arctan 0 = \pi/4 \approx 0{,}7854$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sayısal integralin temel mantığı
  - Karmaşık fonksiyonu parçalara bölüp her parçada integrali kolay bir polinomla (doğru, parabol, kübik) değiştirmek ve parça alanlarını toplamak. Parabol de kullanılsa yapılan iş yine dikdörtgen ya da yamuk alanına benzer bir hesaptır.
- Programın girdileri yalnız $a$, $b$ ve $n$'dir
  - Fonksiyon ne olursa olsun yöntem aynıdır. Önce $h$ hesaplanıp saklanır, sonra $x$ noktaları ve $y = f(x)$ değerleri bir dizide tutulur.
  - Fonksiyon değerini hesaplayan bir yardımcı C fonksiyonu yazılır; diziyi dolduran `for` döngüsü içinde toplam da aynı anda hesaplanabilir.
- Ara değerlerin iki kez sayılması
  - İlk ve son değer dışındaki her $y_i$ iki komşu yamukta yer aldığı için iki katı alınır. Dışarıdaki $h/2$ ile bu 2 sadeleşince, ara değerler doğrudan toplanıp $h$ ile çarpılır; ilk ve son değerin yalnız yarısı alınır. Bu, gereksiz çarpma ve bölmeden kurtarır.
- Parça sayısı arttıkça hata azalır
  - Örnekte $n=4$ ile sonuç gerçek değere oldukça yakındır; $n$ büyütüldükçe hata daha da azalır.

## Kısa Tekrar Notları

- Sayısal integral, belirli integralin sayısal değerini yaklaşık bulur; geometrik anlamı eğrinin altındaki alandır.
- Newton-Cotes: fonksiyon polinomla değiştirilir. Doğru → yamuk kuralı, parabol → Simpson 1/3, kübik → Simpson 3/8.
- Doğru için 2, parabol için 3, kübik için 4 nokta gerekir.
- $h = (b-a)/n$, $x_i = a + ih$, $y_i = f(x_i)$.
- Yamuk kuralı: $I \approx \frac{h}{2}\big(y_0 + 2(y_1 + \dots + y_{n-1}) + y_n\big)$.
- $\int_0^1 \frac{dx}{1+x^2}$, $n=4$: yaklaşık $0{,}7828$; gerçek değer $\pi/4 \approx 0{,}7854$.

## Detaylı Açıklamalar

- Sayısal integral neden gerekir?
  - Belirsiz integral yine bir fonksiyon verir; belirli integral ise $a$ ve $b$ sınırları yerine konunca bir sayı verir. Bazı fonksiyonların belirsiz integrali bilinen kurallarla bulunamaz ya da çok zordur. Bu durumda sınırları koyacak bir ifade olmadığından sonuca analitik yoldan ulaşılamaz. Sayısal yöntemler, fonksiyonun yalnız belirli noktalardaki değerlerini kullanarak alanı yaklaşık hesaplar. Bu değerler, karmaşık fonksiyonlarda bile bilgisayarda kolayca hesaplanabilir.
- Yamuk yaklaşımı
  - $a$ ve $b$ noktalarındaki $f(a)$ ve $f(b)$ değerleri bulunur ve bu iki noktadan bir doğru geçirilir. Doğrunun altındaki şekil bir yamuktur: yüksekliği $b-a$, tabanları $f(a)$ ve $f(b)$'dir. Alan $(b-a)\big(f(a)+f(b)\big)/2$ olur. Bu, aslında fonksiyonu birinci dereceden bir polinomla değiştirmektir. Doğru ile eğri arasındaki fark hatadır.
  - Hatayı azaltmak için aralık bölünür. Orta nokta $c = (a+b)/2$ alınırsa iki yamuk oluşur; $A_1 + A_2$ tek yamuktan daha doğrudur. Dört parçaya bölünürse sonuç daha da iyileşir. Bu düşünce, liseden bilinen Riemann toplamına benzer.
  - Hata, doğru yerine ikinci ya da üçüncü dereceden eğri geçirilerek de azaltılabilir. Parabolün katsayıları üç noktadan kurulan üç bilinmeyenli doğrusal sistemin çözümüyle bulunur. Kübik için dört nokta gerekir; dört nokta üç aralık, üç nokta iki aralık oluşturur. Birden çok aralıkta ardışık parabol parçaları kullanmaya çok noktalı integral denir.
- Trapez yönteminin algoritması
  - Kullanıcıdan $a$, $b$ ve $n$ alınır; $h = (b-a)/n$ hesaplanır.
  - $x$ dizisi $a, a+h, a+2h, \dots, a+nh = b$ biçiminde, $y$ dizisi bu noktalardaki fonksiyon değerleriyle doldurulur. İsterseniz iki dizi, isterseniz iki sütunlu bir matris kullanılabilir. Aslında $x$ dizisine gerek yoktur; $y$ dizisi yeterlidir.
  - Komşu yamuklar ortak kenarı paylaştığı için ilk ve son değer bir kez, aradakiler iki kez sayılır. Toplam $h/2$ ile çarpılır.
  - Burada aralık genişlikleri sabittir. Değişken uzunluklu (uyarlamalı, adaptive) trapez yöntemleri de vardır.
- Örnek: $\int_0^1 \frac{1}{1+x^2}\,dx$, $n=4$
  - $x_0 = 0$, $x_n = 1$, $h = (1-0)/4 = 0{,}25$ (ekrandan, 00:40:00). Noktalar $0;\ 0{,}25;\ 0{,}5;\ 0{,}75;\ 1$.
  - Değerler: $f(0)=1$, $f(0{,}25)\approx 0{,}9412$, $f(0{,}5)=0{,}8$, $f(0{,}75)=0{,}64$, $f(1)=0{,}5$.
  - İlk ve son değerin toplamı $1{,}5$; $h/2 = 0{,}125$ ile çarpılınca $0{,}1875$. Ara değerlerin toplamı $2{,}3812$; $h = 0{,}25$ ile çarpılınca $\approx 0{,}5953$. Sonuç $I \approx 0{,}7828$ (python ile doğrulandı).
  - Analitik sonuç $\int_0^1 \frac{dx}{1+x^2} = \arctan x\,\big|_0^1 = \pi/4 \approx 0{,}7854$ (bir öğrenci derste belirtti). Hata yaklaşık $0{,}0026$'dır.
  - Ders sonrası not: Hoca $h/2$ değerini söylerken "0.5 bölü 2" dedi; $h = 0{,}25$ olduğundan doğrusu $0{,}25/2 = 0{,}125$'tir (sonuç olarak söylenen $0{,}125$ doğrudur).
  - Ders sonrası not: Tahtadaki ilk yamuk formülü $(b-a)\cdot f(a)\cdot f(b)/2$ gibi yazılmış görünüyor (ekrandan, 00:20:00); hocanın sözlü anlatımına uygun doğru biçim $(b-a)\big(f(a)+f(b)\big)/2$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
