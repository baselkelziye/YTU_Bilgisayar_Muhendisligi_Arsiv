# Ders 10 Çalışma Özeti

## Genel Konular

- Enterpolasyon ile regresyonun farkı
  - Enterpolasyonda üretilen doğru ya da eğri bütün veri noktalarından geçer. Bu yüzden veri noktalarında hata $\varepsilon_i = y_i - \hat{y}_i$ sıfırdır ve hataların toplamı da sıfırdır.
  - Veri sayısı çok olduğunda (örneğin binlerce ölçüm) her noktadan geçen bir fonksiyon üretmek güçleşir. Bu durumda noktaları belli bir hata payıyla temsil eden bir doğru ya da eğri aranır; buna regresyon denir.
  - Regresyonda $\sum |\varepsilon_i|$ kesinlikle sıfırdan farklıdır. Amaç bu hatayı sıfırlamak değil, en küçük yapmaktır.
  - Hangisinin daha iyi olduğunun kesin bir ölçüsü yoktur. Ses ya da görüntü kalitesini artırmak gibi veri üretme işlerinde parçalı (spline) enterpolasyon kullanılır; çok sayıda ölçümde regresyon daha iyi sonuç verebilir.
- Hata ölçüleri
  - Pozitif ve negatif hatalar birbirini götürmesin diye ya mutlak değer (sum of absolute error) ya da kare (sum of squared error, mean squared error) alınır.
  - Mutlak değer fonksiyonunun türevi sorunludur. Kareli hatanın türevi kolay alındığı için karesel hata tercih edilir.
- En küçük kareler yaklaşımı (ekrandan, 00:25:00)
  - Toplam karesel hata $S = \sum_{i=1}^{n} d_i^2 = \sum_{i=1}^{n} (y_i - A - Bx_i)^2$ yazılır (ekrandan, 00:30:00).
  - $S$, $A$ ve $B$'nin fonksiyonudur. $\partial S/\partial A = 0$ ve $\partial S/\partial B = 0$ alınarak $S$ en küçük yapılır.
- Doğrusal regresyon $y = A + Bx$ (ekrandan, 00:35:00)
  - Normal denklemler: $nA + B\sum x_i = \sum y_i$ ve $A\sum x_i + B\sum x_i^2 = \sum x_i y_i$.
  - Matris biçimi: $\begin{bmatrix} n & \sum x_i \\ \sum x_i & \sum x_i^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum y_i \\ \sum x_i y_i \end{bmatrix}$. Determinantla (Cramer) ya da başka bir yöntemle çözülür.
  - Örnek (ekrandan, 00:40:00): 10 nokta, $\sum x = 60$, $\sum y = 193$, $\sum x^2 = 492$, $\sum xy = 1550$; $A = 1956/1320 \approx 1.48$, $B = 3920/1320 \approx 2.97$, yani $y \approx 1.48 + 2.97x$.
- Sabit terimsiz doğru $y = ax$
  - Tek parametre olduğu için tek kısmi türev alınır: $a = \dfrac{\sum x_i y_i}{\sum x_i^2}$.
  - Derste $\sum x_i y_i = 101.75$, $\sum x_i^2 = 135$ için $a \approx 0.7537$ bulundu.
- Polinom regresyonu $F(x) = A + Bx + Cx^2$ (ekrandan, 00:45:00)
  - Üç kısmi türev alınır. $n$, $\sum x$, $\sum x^2$, $\sum x^3$, $\sum x^4$ katsayılı $3 \times 3$ simetrik bir sistem çıkar; sağ taraf $\sum y$, $\sum xy$, $\sum x^2 y$'dir.
  - Örnek (ekrandan, 00:50:00): $x = 2, 3, 5, 6, 8$, $y = 1, 6, 22, 33, 61$ için $y = x^2 - 3$; $\hat{f}(4) = 13$.
- Doğrusal olmayan fonksiyonların doğrusallaştırılması (ekrandan, 00:55:00)
  - Önce veri çizdirilip neye benzediğine bakılır: üstel, logaritmik, çift fonksiyon, periyodik vb. Üstel dağılımı polinomla temsil etmek hatayı artırır.
  - $y = a\,b^x$: $\ln y = \ln a + x \ln b$, yani $Y = A + Bx$; $a = e^A$, $b = e^B$.
  - $y = a\,x^b$: $\ln y = \ln a + b \ln x$; $a = e^A$, $b = B$. Toplamlarda $x$ yerine $\ln x$ kullanılır.
  - $y = a\,e^{bx}$: $\ln y = \ln a + bx$; $a = e^A$, $b = B$.
- Trigonometrik (periyodik) regresyon (ekrandan, 01:25:00)
  - $F(x) = a_0 + a_1\cos x + b_1\sin x + a_2\cos 2x + b_2\sin 2x + \dots$ biçimi Fourier analizinin temelidir.
  - Her katsayıya göre kısmi türev alınıp sıfıra eşitlenir. Toplam sembolleri dağıtılınca matris biçimi çıkar.
- Çoklu regresyon (ekrandan, 01:30:00)
  - Birden fazla bağımsız değişken vardır: $Q = a_0 D^{a_1} S^{a_2}$.
  - Logaritma alınınca $\log Q = \log a_0 + a_1 \log D + a_2 \log S$, yani $Y = a_0' + a_1 x_1 + a_2 x_2$ olur. Bu bir düzlem uydurmaktır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Enterpolasyon tahmindir, kesin değer bulmaz; regresyon da noktalardan geçmek zorunda değildir.
  - Regresyonun amacı "en az hatayla bu noktaları temsil etmek"tir. Bazı noktalardan geçebilir ama genel olarak geçmez.
- İşin anahtar kelimesi kısmi türevdir.
  - Hangi fonksiyon uydurulacaksa onun bilinmeyen parametrelerine göre kısmi türev alınıp sıfıra eşitlenir. Çıkan doğrusal denklem sistemi, dönemin başında görülen yöntemlerle çözülür.
- Karesel hata tercih edilir çünkü türevi rahat alınır.
  - Türev alabilmek için fonksiyonun sürekli olması gerekir; mutlak değer fonksiyonu türev açısından sıkıntılıdır.
- Doğrusallaştırmada hangi değişkenin logaritmasının alınacağına dikkat edilmelidir.
  - Matrise doğrudan $\sum x$, $\sum y$ yazılmaz. $y = ab^x$ için $\sum \ln y$ ve $\sum x \ln y$; $y = ax^b$ için $\sum \ln x$, $\sum (\ln x)^2$, $\sum \ln y$, $\sum \ln x \ln y$ kullanılır.
- $i$ yalnız indistir, değişken değildir.
  - Modele $i$ değil, o satırdaki $x_i$ değeri konur.
- Trigonometrik regresyonda matrisin çoğu elemanı sıfıra gider.
  - $\sum \cos x_i$ ve $\sum \sin x_i$ gibi toplamlar sıfıra yaklaştığı için sistem kolay çözülür.

## Kısa Tekrar Notları

- Enterpolasyon: bütün noktalardan geçer, noktalarda hata 0. Regresyon: noktalardan geçmek zorunda değil, hata en küçük yapılır.
- En küçük kareler: $S = \sum (y_i - \hat{y}_i)^2$, her parametreye göre $\partial S = 0$.
- $y = A + Bx$: $\begin{bmatrix} n & \sum x \\ \sum x & \sum x^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum y \\ \sum xy \end{bmatrix}$.
- $y = ax$: $a = \sum xy / \sum x^2$.
- $y = A + Bx + Cx^2$: katsayı matrisinde $\sum x^0 \dots \sum x^4$, sağ tarafta $\sum y$, $\sum xy$, $\sum x^2 y$.
- $y = ab^x$: $\ln y = A + Bx$, $a = e^A$, $b = e^B$.
- $y = ax^b$: $\ln y = A + B\ln x$, $a = e^A$, $b = B$.
- $y = ae^{bx}$: $\ln y = A + Bx$, $a = e^A$, $b = B$.
- Trigonometrik: $F(x) = a_0 + \sum (a_k \cos kx + b_k \sin kx)$.
- Çoklu: $Q = a_0 D^{a_1} S^{a_2}$, $\log$ alınarak iki değişkenli doğrusal regresyon.

## Detaylı Açıklamalar

- **Neden regresyon?** Enterpolasyon yöntemlerinin (doğrusal, kuadratik, Gregory-Newton, Lagrange) hepsi noktaların üzerinden geçer ve özgün veriyi bozmaz. Ancak polinom için derecenin bir fazlası kadar nokta yeterlidir; nokta sayısı çok arttığında her noktadan geçen bir fonksiyon pratik değildir. Regresyonda noktalar bir doğru ya da eğriyle temsil edilir ve her noktadaki sapma $\varepsilon_i$ kabul edilir. Bu yaklaşım özellikle zamana göre değişen ve çok sayıda ölçüm içeren deney verilerinde kullanılır.

- **Normal denklemlerin türetilmesi.** $\hat{y}_i = A + Bx_i$ için $S = \sum (y_i - A - Bx_i)^2$. $A$'ya göre türevde 2 başa gelir, içerinin türevi $-1$'dir: $\partial S/\partial A = \sum 2(A + Bx_i - y_i) = 0$. $B$'ye göre türevde içerinin türevi $-x_i$'dir: $\partial S/\partial B = \sum 2(A + Bx_i - y_i)x_i = 0$. 2'ler sadeleşir, toplamlar dağıtılır ve $\sum_{i=1}^{n} A = nA$, $\sum B x_i = B\sum x_i$ kullanılarak iki bilinmeyenli iki doğrusal denklem elde edilir (ekrandan, 00:35:00). Tablodaki $x_i$, $y_i$ değerlerinden bütün toplamlar hazır olduğu için geriye yalnız $A$ ve $B$'yi bulmak kalır.

- **Doğrusal regresyon örnekleri.** İlk örnekte altı nokta için $\sum x = 30$, $\sum x^2 = 220$, $\sum y = 66.1$, $\sum xy = 470.2$ söylenir; çözüm $A \approx 1.038$, $B \approx 1.996$, yani yaklaşık $y = 2x + 1$ doğrusudur. <!-- BELİRSİZ: Bu örneğin tablosu kare aralığına düşmedi; toplamlar altyazıdan alındı ve python ile tutarlı bulundu. --> İkinci örnekte (ekrandan, 00:40:00) on nokta vardır: $\Delta = 10 \cdot 492 - 60^2 = 1320$, $\Delta A = 193 \cdot 492 - 60 \cdot 1550 = 1956$, $\Delta B = 10 \cdot 1550 - 60 \cdot 193 = 3920$. $A \approx 1.48$, $B \approx 2.97$; hoca bunu yaklaşık $y = 3x + 1.5$ diye okur.

- **Sabit terimsiz doğru.** $y = ax$ istenirse $S = \sum (y_i - a x_i)^2$, $\partial S/\partial a = \sum 2(a x_i - y_i)x_i = 0$, buradan $a\sum x_i^2 = \sum x_i y_i$. Hoca bu oranın $y$'deki değişimin $x$'teki değişime oranı gibi olduğunu, istatistikteki kovaryans fikrine benzediğini anekdot olarak söyler. Derste $x = 3, 4, 5, \dots$ için $y = 2.25, 3, 3.75, \dots$ ile başlayan bir tabloda $a = 101.75 / 135 \approx 0.7537$ bulunur. <!-- BELİRSİZ: Tablonun tamamı ekranda görünmedi. -->

- **Polinom regresyonu.** $F(x) = A + Bx + Cx^2$ için üç kısmi türev alınır (ekrandan, 00:45:00). Katsayı matrisinde bir örüntü vardır: köşede $n$, köşegenlere paralel olarak $\sum x$, $\sum x^2$, $\sum x^3$, sağ altta $\sum x^4$. Örnekte (ekrandan, 00:50:00) $\Delta = 8316$, $\Delta A = -24948$ (karede $-24918$ yazılmış; doğrusu python ile $-24948$ bulundu, $A = -3$ ancak bu değerle çıkar), $\Delta B = 0$, $\Delta C = 8316$; $A = -3$, $B = 0$, $C = 1$, yani $y = x^2 - 3$. Bu fonksiyon tablodaki beş noktadan sıfır hatayla geçer. $x = 4$ için tahmin $\hat{f}(4) = 16 - 3 = 13$'tür.

- **Üstel model $y = ab^x$** (ekrandan, 01:05:00). $x = 0, 2, 3, 4, 5$ ve $y = 5.2, 56.628, 186.872, 616.679, 2035.040$. $\ln y$ sütunu toplamı $24.958$, $\sum x = 14$, $\sum x^2 = 54$, $\sum x\ln y = 87.550$. $\Delta = 5 \cdot 54 - 14^2 = 74$, $A = 122.032/74 \approx 1.649$, $B = 88.338/74 \approx 1.1938$. $a = e^A \approx 5.202$, $b = e^B \approx 3.299$; sonuç $y \approx 5.202 \cdot 3.3^x$.

- **Güç modeli $y = ax^b$** (ekrandan, 01:15:00). $x = 1, 3, 5$, $y = 3, 15.588, 33.541$. $\sum \ln x = 2.708$, $\sum \ln y = 7.359$, $\sum (\ln x)^2 = 3.797$, $\sum \ln x \ln y = 8.671$. Sistem çözülünce $A \approx 1.099$, $B \approx 1.50$; $a = e^{1.099} \approx 3$, $b \approx 1.5$, yani $y \approx 3x^{1.5}$ (son değerler python ile hesaplandı). Üs tam sayı olmadığı için bu bir polinom değildir.

- **Trigonometrik regresyon.** $F(x_i) = a_0 + a_1\cos x_i + b_1\sin x_i$ için $\partial M/\partial a_0$, $\partial M/\partial a_1$, $\partial M/\partial b_1$ türevleri alınır; içerisi aynı kalır, yalnız sırasıyla $1$, $\cos x_i$, $\sin x_i$ çarpanı gelir (ekrandan, 01:25:00). Bir terim grubu daha eklenirse beş bilinmeyenli beş denklem çıkar. Derste dereceyle verilen verilerle $a_0 + a_1\sin x$ ve $a_0 + a_1\cos x$ biçiminde iki örnek kısaca gösterildi. <!-- BELİRSİZ: Bu iki örneğin tablosu karelerde yok; cos örneğinin sonucu altyazıda yaklaşık "1.6 eksi 2 cos x" diye geçiyor. -->

- **Çoklu regresyon** (ekrandan, 01:35:00). Bir kanaldaki akış miktarı $Q$, boru çapı $D$ ve eğim $S$ ile verilir. $\log Q = \log a_0 + a_1\log D + a_2\log S$ ile üç bilinmeyenli sistem kurulur: $\begin{bmatrix} 9 & 2.334 & -18.903 \\ 2.334 & 0.954 & -4.903 \\ -18.903 & -4.903 & 44.079 \end{bmatrix}\begin{bmatrix} a_0' \\ a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 11.691 \\ 3.945 \\ -22.207 \end{bmatrix}$. Çözüm $\log a_0 = 1.7475$, $a_1 = 2.62$, $a_2 = 0.54$; $a_0 = 10^{1.7475} \approx 55.9$, yani $Q = 55.9\,D^{2.62} S^{0.54}$.
  - Ders sonrası not: Karedeki matriste ikinci köşegen elemanı $0.924$ yazılmış, tablo toplamı ise $0.954$'tür. Doğrusu $0.954$'tür; slayttaki sonuç da bu değerle çıkar (python ile doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
