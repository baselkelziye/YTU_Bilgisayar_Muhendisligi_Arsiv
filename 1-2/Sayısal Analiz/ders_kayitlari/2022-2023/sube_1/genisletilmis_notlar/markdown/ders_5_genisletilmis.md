# Ders 5 Genişletilmiş Notu: Cholesky (LU) Yöntemi, Jacobi ve Gauss-Seidel İterasyonu, Doğrusal Olmayan Denklem Takımları ve Sayısal Türev

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Algoritmik Düşünce Üzerine
- 2. Cholesky (Yoğunlaştırılmış Yok Etme) Yöntemi
- 3. Dolaylı Yöntemler ve Jacobi İterasyonu
- 4. Gauss-Seidel İterasyonu
- 5. Doğrusal Olmayan Denklem Takımları
- 6. Sayısal Türev
- 7. Taylor Serisiyle Türev Formülleri
- 8. Algoritmaları Kodlarken: Sorular ve Uç Durumlar

## 1. Algoritmik Düşünce Üzerine

Hoca konuya geçmeden önce algoritma yazma becerisi üzerine konuştu. Bu dersin programlama çalışmalarının amacı algoritma kurma yeteneğini ileri taşımaktır. Yazmış olduğunuz bir algoritmayı bir süre sonra daha iyi yazabileceğinize inanıyorsanız yeniden kodlamanızı önerdi. Hocaya göre algoritmayı oturtup hızlı kodlayamayan biri bölümün dört yılı boyunca zorlanır. Ne kadar çok deneme ve pratik yaparsanız o kadar hızlı ilerlersiniz.

Hoca, öğrenciyken algoritma kurmakta kendisinin de çok zorlandığını anlattı. Yılmadan yazılmış programların üzerinde analizler yapmış, mantık böyle oturmuş. Bir süre sonra "birdenbire bir ışık yanıyor, olay çözülüyor." Bu yüzden "yapamıyorum" deyip işi kenara koymamak gerekir. Programlamayı o an gördüğünüz dillerle yaparsanız hem algoritmanız gelişir hem dili daha iyi öğrenirsiniz.

> **Hocanın vurgusu:** Sevdiğiniz konuyu iyi belirleyip o konuda kendinizi geliştirin. Her konuda yüzde yüz bilgi sahibi olamayız, bu imkânsızdır. Her konuyu bilelim, ama birkaç konuda da gerçekten iyi olalım.

## 2. Cholesky (Yoğunlaştırılmış Yok Etme) Yöntemi

Geçen hafta doğrusal denklem sistemlerinin çözümüne başlanmıştı. Bütün yöntemlerde bir katsayılar matrisi vardır ve bu matris üzerinde işlemler yapılarak sonuca gidilir. Dolaysız yöntemlerin sonuncusu yoğunlaştırılmış yok etme yöntemidir. Hoca buna Cholesky yöntemi dedi ve lineer cebir dersinde de görülmüş olabileceğini söyledi. Mantık analitik çözümde de sayısal çözümde de aynıdır. Yalnız son kısımda istenirse sayısal yöntemlerden yararlanılabilir.

### 2.1 Yöntemin Fikri

Denklem takımı matris biçiminde yazılır. $A$ katsayılar matrisi, $X$ bilinmeyenler, $C$ ise eşitliğin sağ tarafındaki değerlerdir:

$$
A X = C
$$

Amaç, $A$ matrisini $L$ adı verilen bir alt üçgen matris ile $U$ adı verilen bir üst üçgen matrise ayırmaktır. $A$ yerine bu çarpım yazılır:

$$
A = L U \quad \Rightarrow \quad L U X = C
$$

$U X$ çarpımına $Y$ denirse çözüm iki adıma ayrılır:

1. $L Y = C$ çözülür. $L$ ve $C$ bilindiği için $Y$ bulunur.
2. $U X = Y$ çözülür. $U$ ve $Y$ bilindiği için $X$, yani asıl bilinmeyenler bulunur.

Bu iki denklem takımı, geçen hafta görülen dolaysız yöntemlerden herhangi biriyle çözülebilir.

> **Ders sonrası not:** Hoca bu yönteme Cholesky dedi. Derste anlatılan biçim ($U$'nun köşegeni 1, $L$ genel alt üçgen) literatürde büyük olasılıkla Crout ayrıştırması adıyla geçer. Literatürdeki Cholesky ayrıştırması büyük olasılıkla simetrik ve pozitif tanımlı matrisler için $A = L L^T$ biçimindedir. Bu derste kullanılan ad ve yol hocanın anlattığı biçimdir.

### 2.2 L ve U Elemanlarının Bulunması

Hoca $3 \times 3$ bir matris üzerinden gitti. Alt üçgen matriste köşegenin üstü, üst üçgen matriste köşegenin altı sıfırdır. Üst üçgen matrisin köşegeni birlerden oluşur:

$$
\begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{bmatrix}
=
\begin{bmatrix} L_{11} & 0 & 0 \\ L_{21} & L_{22} & 0 \\ L_{31} & L_{32} & L_{33} \end{bmatrix}
\begin{bmatrix} 1 & U_{12} & U_{13} \\ 0 & 1 & U_{23} \\ 0 & 0 & 1 \end{bmatrix}
$$

Bilinmeyen $L$ ve $U$ elemanlarını bulmak için iki matris normal matris çarpımıyla çarpılır ve sonuç $A$'ya eşitlenir. Birinci satır birinci kolonla çarpılınca $L_{11} \cdot 1 + 0 \cdot 0 + 0 \cdot 0$ kalır ve bu $a_{11}$'e eşittir. Birinci satır ikinci kolonla çarpılınca $L_{11} U_{12}$ kalır. Bütün çarpımlar yazılınca şu eşitlikler çıkar:

$$
\begin{aligned}
L_{11} &= a_{11} & L_{11} U_{12} &= a_{12} & L_{11} U_{13} &= a_{13} \\
L_{21} &= a_{21} & L_{21} U_{12} + L_{22} &= a_{22} & L_{21} U_{13} + L_{22} U_{23} &= a_{23} \\
L_{31} &= a_{31} & L_{31} U_{12} + L_{32} &= a_{32} & L_{31} U_{13} + L_{32} U_{23} + L_{33} &= a_{33}
\end{aligned}
$$

En son terimde bu kadar çok çarpan olmasının sebebi, üçüncü satırın üçüncü kolonla çarpılmasıdır: $L_{31} U_{13}$, $L_{32} U_{23}$ ve $L_{33} \cdot 1$.

$A$ matrisi bilindiği için eşitlikler sırayla çözülür. $L_{11}$ doğrudan $a_{11}$'dir. Bulunan $L_{11}$ yerine konunca $L_{11} U_{12} = a_{12}$ eşitliğinden $U_{12}$, $L_{11} U_{13} = a_{13}$ eşitliğinden $U_{13}$ çıkar. Sonra $L_{21} = a_{21}$ alınır. $L_{21}$ ve $U_{12}$ bilindiği için $L_{22}$ bulunur. Böylece her eleman, $a$ değerleri ve önceki adımlarda bulunanlarla hesaplanır.

Hoca formüllerin çok fazla indis içerdiği için karışık göründüğünü, ama özünün basit olduğunu söyledi.

> **Hocanın vurgusu:** Bu formülleri ezberlemenize hiç gerek yok. Bir alt üçgen matris, bir de köşegeni 1 olan üst üçgen matris yazın, bildiğiniz gibi çarpıp $A$'ya eşitleyin. Hepsi kendiliğinden çıkar.

### 2.3 Örnek

Hoca şu denklem takımını çözdü:

$$
\begin{aligned}
3.6x + 2.4y - 1.8z &= 6.3 \\
4.2x - 5.8y + 2.1z &= 7.5 \\
0.8x + 3.5y + 6.5z &= 3.7
\end{aligned}
$$

<!-- BELİRSİZ: Denklem takımının tamamı altyazıda okunmuyor, yalnız 3.6, 2.4, 1.8 ve 0.8 sözlü geçiyor. Katsayılar ve slayttaki yuvarlanmış ara sonuçlar kısa nottan alındı. -->

Hoca işaretlere dikkat edilmesini istedi. $A$ ve $C$ matrisleri denklemlerden yazılır.

**Birinci satır.** Birinci satır birinci kolonla çarpılır: $L_{11} = 3.6$. Birinci satır ikinci kolonla çarpılır: $L_{11} U_{12} = 2.4$, buradan $U_{12} = 2.4 / 3.6 = 0.67$. Üçüncü kolon için $L_{11} U_{13} = -1.8$, buradan $U_{13} = -0.5$.

**İkinci satır (ara adımlar eklendi).** $L_{21} = 4.2$ alınır. Sonra:

$$
L_{22} = -5.8 - 4.2 \cdot 0.67 = -8.6
$$

$$
U_{23} = \frac{2.1 - 4.2 \cdot (-0.5)}{-8.6} = \frac{4.2}{-8.6} = -0.49
$$

**Üçüncü satır (ara adımlar eklendi).** Hoca $L_{31} = 0.8$ olduğunu söyledi. Sonra ikinci kolonla çarpım ve üçüncü kolonla çarpımdan $L_{32}$ ve $L_{33}$ bulunur:

$$
L_{32} = 3.5 - 0.8 \cdot 0.67 = 2.96
$$

$$
L_{33} = 6.5 - 0.8 \cdot (-0.5) - 2.96 \cdot (-0.49) = 8.35 \approx 8.4
$$

> **Ders sonrası not:** Altyazıya göre hoca üçüncü satırda ikinci kolonla çarpımdan "$U_{12}$'yi bulacaksın" dedi. $U_{12}$ birinci satırda bulunmuştu, bu çarpımdan bulunan $L_{32}$'dir. Slaytta büyük olasılıkla $U_{23}$ işaretsiz 0.49 yazıyordu, doğrusu $-0.488$'dir. Python ile tam değerler $L_{32} = 2.967$ ve $L_{33} = 8.349$ çıkar. Slayttaki 8.4 büyük olasılıkla yuvarlanmış değerdir.

Böylece iki matris de elde edilir:

$$
L = \begin{bmatrix} 3.6 & 0 & 0 \\ 4.2 & -8.6 & 0 \\ 0.8 & 2.96 & 8.4 \end{bmatrix}
\qquad
U = \begin{bmatrix} 1 & 0.67 & -0.5 \\ 0 & 1 & -0.49 \\ 0 & 0 & 1 \end{bmatrix}
$$

**$L Y = C$ adımı (ara adımlar eklendi).** Burada $C$, ilk denklemlerin sağ tarafıdır. Hoca bu sistemin istenen dolaysız yöntemle çözülebileceğini söyledi. $L$ alt üçgen olduğu için yukarıdan aşağı gidilir:

$$
\begin{aligned}
y_1 &= \frac{6.3}{3.6} = 1.75 \\
y_2 &= \frac{7.5 - 4.2 \cdot 1.75}{-8.6} = -0.02 \\
y_3 &= \frac{3.7 - 0.8 \cdot 1.75 - 2.96 \cdot (-0.02)}{8.4} = 0.28
\end{aligned}
$$

**$U X = Y$ adımı (ara adımlar eklendi).** $U$ üst üçgen olduğu için aşağıdan yukarı gidilir:

$$
\begin{aligned}
x_3 &= 0.28 \\
x_2 &= -0.02 + 0.49 \cdot 0.28 = 0.12 \\
x_1 &= 1.75 - 0.67 \cdot 0.12 + 0.5 \cdot 0.28 = 1.81
\end{aligned}
$$

Sonuç $x = 1.81$, $y = 0.12$, $z = 0.28$ olur.

> **Ders sonrası not:** Python ile yuvarlamasız hesapta $y_2 = -0.0174$, $y_3 = 0.2817$, sonuç ise $x = 1.8108$, $y = 0.1201$, $z = 0.2817$ çıkar. $L U$ çarpımı $A$'yı verir ve sonuç doğrudan çözümle aynıdır. Aynı denklem takımı büyük olasılıkla bir önceki dersin Gauss eliminasyonu örneğidir.

### 2.4 Bu Yöntem Neden Geliştirilmiş?

Hoca, yöntemin biraz el oyalayan bir yöntem olduğunu kabul etti ve neden geliştirildiğini anlattı. Bazen matrisin tamamıyla çalışmak zaman alır. $3 \times 3$ bir matriste dokuz elemanın dokuzu da doludur. Matrisi iki parçaya ayırınca iki parçada da bazı elemanlar sıfır olur. Yine işlem yapılır, ama daha az çarpma ve toplama yapılır. Hoca bunu işlemi "birazcık hızlandırmak" olarak açıkladı.

> **Ek bilgi (derste anlatılmadı):** LU ayrıştırmasının toplam işlem sayısı büyük olasılıkla Gauss eliminasyonuyla aynı mertebededir. Asıl kazanç büyük olasılıkla aynı $A$ matrisi için farklı $C$ değerleri çözülürken görülür. $L$ ve $U$ bir kez bulunur, her yeni $C$ için yalnız iki üçgen sistem çözülür.

## 3. Dolaylı Yöntemler ve Jacobi İterasyonu

Buraya kadarki yöntemler dolaysız yöntemlerdi, yani iterasyona bağlı çalışmıyorlardı. Dolaylı yöntemler ise iterasyona bağlıdır. Her adımda bir önceki adımda bulunan bilinmeyen değerleri kullanılır. Bu işlem, kabul edilebilecek son değerlere ulaşılıncaya kadar sürer.

İlk dolaylı yöntem Jacobi iterasyonudur. Adını bulan kişiden alır. Yine $n$ bilinmeyen ve $n$ denklem vardır, yani katsayılar matrisi kare matristir.

### 3.1 En Önemli Adım: Köşegeni Maksimum Yapmak

Hoca bu adımı "algoritmayı algoritma yapan" adım olarak tanıttı.

> **Hocanın vurgusu:** $A$ matrisinde köşegendeki katsayıların mutlak değerce çarpımı maksimum olmalıdır. Denklemlerin yerini öyle değiştirin ki köşegene gelen katsayıların mutlak değerce çarpımı en büyük sayıyı versin. Bu olmadan düzgün bir sonuca erişemezsiniz.

Köşegen elemanları negatif olabilir, bu yüzden çarpım mutlak değerce alınır. Örneğin birinci denklem dördüncü denklemle değiştirildiğinde daha büyük bir çarpım çıkıyorsa o sıralama alınır. Gerekirse elementer satır işlemleri de yapılabilir.

Hoca bunun için pratik bir yol verdi:

1. Birinci kolona bakılır ve mutlak değerce en büyük katsayı bulunur. Diyelim ki bu $a_{31}$'dir.
2. O katsayı köşegene gelecek şekilde denklem taşınır. Bu örnekte üçüncü denklem birinci satıra, birinci denklem üçüncü satıra gider.
3. Aynı işlem ikinci kolon ve sonraki kolonlar için yapılır.

Hoca bu yolun her zaman çalıştığını söylemedi. Bazen son kolona gelince "keşke buradan başlasaydım, daha yüksek olurdu" denebilir. Katsayılardan birinin sıfır olması, yani arada bir değişkenin bulunmaması da durumu değiştirebilir. Bu yüzden sonuç kontrol edilmelidir. Program yazılırken bütün kontrolleri yapan ve matrisi maksimum köşegene getiren bir fonksiyon yazılabilir. Elle çözerken küçük örneklerde bu işlem gözle yapılır.

> **Ders sonrası not:** Altyazıya göre hoca "çözersin ama çözümün yanlış olur" dedi. Python ile aşağıdaki örnekte denklemlerin sırası değiştirilmeden deneyince iterasyon yanlış bir değere gitmez, büyük olasılıkla ıraksar: 10 iterasyonda $x$ yaklaşık 476540 olur. Yani sorun yanlış bir sonuca varmak değil, hiç yakınsamamaktır. Ayrıca hoca köşegen elemanlarını sayarken bir yerde $a_{12}$ dedi, doğrusu $a_{22}$'dir.

> **Ek bilgi (derste anlatılmadı):** Jacobi ve Gauss-Seidel için bilinen yakınsama koşulu büyük olasılıkla köşegen baskınlıktır: her satırda $|a_{ii}| > \sum_{j \ne i} |a_{ij}|$. Bu koşul yeterlidir, gerekli değildir. Aşağıdaki örnekte düzenlenmiş satırlarda $3 = 1 + 2$, $4 = 1 + 3$ ve $4 > 1 + 1$ olur, yani koşul tam sağlanmaz ama yakınsama olur. Köşegen büyüyünce çekilen değişkende diğer değişkenlerin etkisi küçülür, hatalar büyük olasılıkla bu yüzden her adımda azalır.

### 3.2 Yöntemin Adımları

1. Denklemlerin yeri değiştirilerek köşegen maksimum yapılır.
2. Birinci sıradaki denklemden $x_1$, ikinci sıradaki denklemden $x_2$, $n$. sıradaki denklemden $x_n$ çekilir. Diğer terimler negatif olarak sağ tarafa geçer ve eşitlik köşegen katsayısına bölünür:

$$
x_1 = \frac{c_1 - a_{12} x_2 - a_{13} x_3 - \cdots - a_{1n} x_n}{a_{11}},
\qquad
x_2 = \frac{c_2 - a_{21} x_1 - a_{23} x_3 - \cdots - a_{2n} x_n}{a_{22}}
$$

3. İşleme başlamak için ilk değerler verilir. Örneğin hepsine 0 denebilir.
4. Her yeni değer hesaplanırken **bir önceki iterasyonun** değerleri kullanılır.
5. Durma şartı sağlanınca işlem biter.

Dördüncü madde Jacobi'nin belirleyici özelliğidir. Hoca slaytta bunun koyu yazıldığını gösterdi. Yeni $x_2$ bulunurken o iterasyonda yeni bulunan $x_1$ kullanılmaz. Hangi iterasyondaysanız onun bir üstündeki iterasyonun $x$ değerleri yerine konur.

Durma şartı bütün değişkenler için aynıdır. Ardışık iki değer arasındaki mutlak fark hatadan küçük eşit olmalıdır:

$$
\left| x_i^{(k+1)} - x_i^{(k)} \right| \le \varepsilon, \qquad i = 1, 2, \ldots, n
$$

Yalnız bir değişkenin bu şartı sağlaması yetmez. Hepsi aynı iterasyonda sağlamalıdır.

### 3.3 Örnek

Üç bilinmeyenli şu sistem Jacobi yöntemiyle çözülecektir. Hata $\varepsilon = 0.001$'dir.

$$
\begin{aligned}
-x + 4y - 3z &= -8 \\
3x + y - 2z &= 9 \\
x - y + 4z &= 1
\end{aligned}
$$

**Köşegeni düzenleme.** Mevcut köşegen katsayıları $-1$, $1$ ve $4$'tür. Çarpımın mutlak değeri 4'tür. Hoca öğrencilere kağıt kalemle birkaç dakika denemelerini söyledi. Sohbete yazan öğrenciler 48 sonucunu buldu.

Hocanın kuralı uygulanınca birinci kolonda en büyük katsayı 3, ikinci kolonda 4, üçüncü kolonda 4'tür. Üçüncü kolondaki 4 zaten yerindedir. Birinci ve ikinci denklemler yer değiştirince köşegen 3, 4, 4 olur ve çarpım $3 \cdot 4 \cdot 4 = 48$'dir. Python ile altı sıralamanın hepsi denenince çarpımlar 4, 2, 48, 9, 8 ve 3 çıkar, yani 48 en büyüktür.

Hoca denklem taşınırken işaretlerin önemli olmadığını da hatırlattı. Karşılaştırmada mutlak değere bakılır.

> **Hocanın vurgusu:** Yalnız 3 ile 4'ün yerini değiştirmiyorum. Denklemi komple alıp taşıyorum. Dalgınlıkla yalnız $3x$'i yukarı, $-x$'i aşağı yazarsanız işin rengi çok değişir.

Düzenlenmiş sistem şöyledir:

$$
\begin{aligned}
3x + y - 2z &= 9 \\
-x + 4y - 3z &= -8 \\
x - y + 4z &= 1
\end{aligned}
$$

**Değişkenleri çekme.** Her denklemden sırasıyla bir değişken çekilir:

$$
x = \frac{9 - y + 2z}{3}, \qquad
y = \frac{-8 + x + 3z}{4}, \qquad
z = \frac{1 - x + y}{4}
$$

**Başlangıç.** Slaytta başlangıç değeri 0 yazıyordu, ama hoca derste bunu düzeltti. Örneğin tablosu $x = y = z = 1$ ile başlar. Hoca bu satıra sıfırıncı ya da birinci iterasyon denmesinin önemli olmadığını söyledi. Burada önceki adım olmadığı için $\Delta x$, $\Delta y$, $\Delta z$ sıfır yazılır.

**İkinci iterasyon.** Yeni değerlerin hepsi başlangıç satırından hesaplanır:

$$
\begin{aligned}
x &= \frac{9 - 1 + 2 \cdot 1}{3} = 3.333, & |\Delta x| &= 2.333 \\
y &= \frac{-8 + 1 + 3 \cdot 1}{4} = -1, & |\Delta y| &= 2 \\
z &= \frac{1 - 1 + 1}{4} = 0.25, & |\Delta z| &= 0.75
\end{aligned}
$$

> **Hocanın vurgusu:** Yeni $y$'yi bulurken $x$ yerine kesinlikle bu adımdaki $x$'i koymuyorsunuz. Hangi iterasyondaysanız bir üst iterasyonda $x$ neyse onu koyuyorsunuz.

Farklar hatadan çok büyük olduğu için iterasyon artar.

**Üçüncü iterasyon (ara adımlar eklendi).** İkinci satırın değerleri kullanılır:

$$
\begin{aligned}
x &= \frac{9 - (-1) + 2 \cdot 0.25}{3} = 3.5, & |\Delta x| &= 0.167 \\
y &= \frac{-8 + 3.333 + 3 \cdot 0.25}{4} = -0.979, & |\Delta y| &= 0.021 \\
z &= \frac{1 - 3.333 + (-1)}{4} = -0.833, & |\Delta z| &= 1.083
\end{aligned}
$$

Aynı işlem sonraki satırlarda sürer. Hoca ara satırları okumadı. Aşağıdaki tablo Python ile yeniden hesaplanmıştır ve üç basamağa yuvarlanmıştır:

| İter. | $x$ | $y$ | $z$ | $\lvert\Delta x\rvert$ | $\lvert\Delta y\rvert$ | $\lvert\Delta z\rvert$ |
|---|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| 2 | 3.333 | -1.000 | 0.250 | 2.333 | 2.000 | 0.750 |
| 3 | 3.500 | -0.979 | -0.833 | 0.167 | 0.021 | 1.083 |
| 4 | 2.771 | -1.750 | -0.870 | 0.729 | 0.771 | 0.036 |
| 5 | 3.003 | -1.960 | -0.880 | 0.233 | 0.210 | 0.010 |
| 6 | 3.066 | -1.909 | -0.991 | 0.063 | 0.050 | 0.111 |
| 7 | 2.976 | -1.976 | -0.994 | 0.090 | 0.067 | 0.003 |
| 8 | 2.996 | -2.001 | -0.988 | 0.020 | 0.025 | 0.006 |
| 9 | 3.008 | -1.992 | -0.999 | 0.012 | 0.009 | 0.011 |
| 10 | 2.998 | -1.997 | -1.000 | 0.011 | 0.005 | 0.001 |
| 11 | 2.999 | -2.001 | -0.999 | 0.001 | 0.003 | 0.001 |
| 12 | 3.001 | -1.999 | -1.000 | 0.002 | 0.001 | 0.001 |
| 13 | 3.000 | -2.000 | -1.000 | 0.001 | 0.000 | 0.000 |

Hoca 11. iterasyona geldiğinde şunu gösterdi: Yeni $x$'in farkı hatadan küçüktür, ama "işim bitti" diye çıkılamaz, çünkü üç değişkenin de küçük olması gerekir. Yeni $z$'nin farkı da küçüktür, ama $y$'nin farkı değildir. Bu yüzden iterasyon sürer. 12. iterasyonda hoca "bazen büyüyor, bazen küçülüyor" dedi: $\Delta x$ arttı, $\Delta y$ küçüldü, $\Delta z$ aynı kaldı. Bir adım daha yapılınca 13. iterasyonda üçü de sınırın içine girer. İşlem biter:

$$
x = 3, \qquad y = -2, \qquad z = -1
$$

**Sağlama.** Hoca sonucu $z$ denkleminde yerine koydu: $z = \frac{1 - 3 + (-2)}{4} = \frac{-4}{4} = -1$. Sağlama ister değişken çekilmiş denklemlerde, ister ilk denklemlerde yapılabilir.

> **Ders sonrası not:** Hoca başta hatayı "binde bir" dedi, tablodaki 11. satıra gelmeden önce ise altyazıya göre "0.01" dedi. Doğrusu 0.001'dir. $\varepsilon = 0.01$ olsaydı Python hesabına göre 11. satırda bütün farklar sınırın içinde olurdu, oysa hoca $y$ için "küçük değil" diyerek devam etti. Ayrıca slayttaki 6. satırda büyük olasılıkla $x = 3.006$ yazıyordu, doğrusu 3.066'dır. 13. satırda $|\Delta x|$ yuvarlanmamış halde 0.0012'dir. Kesin karşılaştırmada $\le 0.001$ şartı 14. satırda sağlanır, 13. satırdaki durma büyük olasılıkla üç basamağa yuvarlanmış değerlere dayanır. Sonuç değişmez.

Hoca bu örnekten sonra dolaylı yöntemlerin dolaysız yöntemlere göre çok daha kolay olduğunu ve sonuca çok daha hızlı gidildiğini söyledi. Unutulmaması gereken tek şey köşegenin maksimuma getirilmesidir.

## 4. Gauss-Seidel İterasyonu

Gauss-Seidel yöntemi, Jacobi'ye çok benzeyen ikinci dolaylı yöntemdir. Maksimum köşegen sağlanır, her denklemden sırasıyla değişkenler çekilir, durma şartı da aynıdır. Hoca arada "çok küçük bir fark" olduğunu söyledi. Ama bu fark sayesinde Gauss-Seidel, Jacobi'den daha hızlı çalışır.

Fark şudur: Jacobi, bir önceki iterasyonda değişkenler hangi değerleri almışsa onları kullanır. Gauss-Seidel ise değişkenlerin **en son aldığı** değerleri kullanır. Başka hiçbir fark yoktur.

> **Hocanın vurgusu:** Gauss-Seidel'de değişkenin en son değeri neyse o kullanılır. Bunu unutmayın.

### 4.1 Aynı Örnek

Hoca aynı denklem takımını ve aynı başlangıcı ($x = y = z = 1$) kullandı. Yeni $x$ bulunurken $y$ ve $z$'nin elde bulunan son değerleri konur. Bu ilk adımda iki yöntem aynıdır. Yeni $y$ bulunurken ise bu iterasyonda yeni bulunan $x$ kullanılır, $z$ için de henüz yenisi olmadığı için bir önceki değer alınır. Yeni $z$ bulunurken bu iterasyonda bulunan $x$ ve $y$ kullanılır.

**İkinci iterasyon.**

$$
\begin{aligned}
x &= \frac{9 - 1 + 2 \cdot 1}{3} = 3.333, & |\Delta x| &= 2.333 \\
y &= \frac{-8 + 3.333 + 3 \cdot 1}{4} = -0.417, & |\Delta y| &= 1.417 \\
z &= \frac{1 - 3.333 + (-0.417)}{4} = -0.688, & |\Delta z| &= 1.688
\end{aligned}
$$

**Üçüncü iterasyon (ara adımlar eklendi).**

$$
\begin{aligned}
x &= \frac{9 - (-0.417) + 2 \cdot (-0.688)}{3} = 2.681, & |\Delta x| &= 0.653 \\
y &= \frac{-8 + 2.681 + 3 \cdot (-0.688)}{4} = -1.845, & |\Delta y| &= 1.429 \\
z &= \frac{1 - 2.681 + (-1.845)}{4} = -0.882, & |\Delta z| &= 0.194
\end{aligned}
$$

Sonraki satırları hoca okumadı. Tablo Python ile yeniden hesaplanmıştır ve üç basamağa yuvarlanmıştır:

| İter. | $x$ | $y$ | $z$ | $\lvert\Delta x\rvert$ | $\lvert\Delta y\rvert$ | $\lvert\Delta z\rvert$ |
|---|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| 2 | 3.333 | -0.417 | -0.688 | 2.333 | 1.417 | 1.688 |
| 3 | 2.681 | -1.845 | -0.882 | 0.653 | 1.429 | 0.194 |
| 4 | 3.027 | -1.904 | -0.983 | 0.347 | 0.059 | 0.101 |
| 5 | 2.979 | -1.992 | -0.993 | 0.048 | 0.088 | 0.010 |
| 6 | 3.002 | -1.994 | -0.999 | 0.023 | 0.002 | 0.006 |
| 7 | 2.999 | -2.000 | -1.000 | 0.003 | 0.005 | 0.000 |
| 8 | 3.000 | -2.000 | -1.000 | 0.001 | 0.000 | 0.000 |
| 9 | 3.000 | -2.000 | -1.000 | 0.000 | 0.000 | 0.000 |

Sonuç yine $x = 3$, $y = -2$, $z = -1$'dir. Hoca 7. satırda durulmadığını, çünkü şartı yalnız bir değişkenin sağladığını gösterdi. Üçünün de sağlaması gerekir. Sonra slayttaki tabloda 9. satıra hiç gerek olmadığını, işlemin 8. adımda bittiğini söyledi.

Jacobi 13 adımda biterken Gauss-Seidel 8-9 adımda biter. Dört beş adımlık fark küçük görünebilir, ama denklem ve değişken sayısı arttığında bunun önemli olduğu görülür.

> **Ders sonrası not:** Hoca "9. adıma gerek yok" dedi. Bu, üç basamağa yuvarlanmış tablo için doğrudur. Python hesabına göre 8. satırda $|\Delta x| = 0.0015$'tir, yani kesin karşılaştırmada $\le 0.001$ şartı 9. satırda sağlanır. Slaytta büyük olasılıkla 3. satırda $|\Delta x| = 0.348$, 5. satırda $z = -0.983$ yazıyordu. Doğruları sırasıyla 0.653 ve $-0.993$'tür.

### 4.2 İki Yöntemin Özeti

Hoca soru sormadan önce iki yöntemi şöyle özetledi. Bu özette Jacobi'ye "Gauss-Jacobi" de dedi.

- **Ortak adımlar:** Denklemlerde satır değişiklikleriyle maksimum köşegen oluşturulur, her eşitlikten sırayla bilinmeyenler çekilir.
- **Jacobi:** Her yeni değer elde edilirken bir önceki iterasyondaki değerler kullanılır.
- **Gauss-Seidel:** Her yeni değer elde edilirken en son bulunan değişken değerleri kullanılır.
- **Durma:** Bütün değişkenler için ardışık iki değer arasındaki mutlak fark hatadan küçük eşit olmalıdır.

## 5. Doğrusal Olmayan Denklem Takımları

Bu kısımda elimizde yine denklem takımı vardır, ama denklemler doğrusal değildir. Örneğin $x$ ve $y$ değişkenli bir $f$ fonksiyonu ile yine $x$ ve $y$ değişkenli bir $g$ fonksiyonu verilir:

$$
f(x, y) = 0, \qquad g(x, y) = 0
$$

Çözüme, tek değişkenli sistemlerde olduğu gibi Taylor serisi açılarak gidilir. Hoca, ilk haftada Taylor serisinin neden görüldüğünün sorulduğunu hatırlattı. Seri, Newton-Raphson yönteminde karşımıza çıkmıştı, burada ve ileride türevde de çıkacaktır.

### 5.1 Tek Değişkenli Taylor Serisini Hatırlama

Bir eksende $x_0$, $x_1$, $x_2$ noktalarını düşünün. Ardışık iki $x$ arasındaki artım $h$'dir. $x_0$'a $h$ eklenince $x_1$, iki $h$ eklenince $x_2$ elde edilir. $x$ noktasındaki değer, $x_0$ noktasındaki değere belirli türev değerleri eklenerek bulunur. Ne kadar fazla terim eklenirse gerçeğe o kadar yakın bir değer elde edilir:

$$
f(x) = f(x_0) + f'(x_0) \frac{h}{1!} + f''(x_0) \frac{h^2}{2!} + \cdots, \qquad h = x - x_0
$$

### 5.2 İki Değişkenli Taylor Serisi

Burada fonksiyonda iki değişken vardır, bu yüzden seri iki değişkenli yazılır. $x = x_0 + \Delta x$, $y = y_0 + \Delta y$ alınır. $h$ yerine $\Delta x$ ve $\Delta y$ gelir. Türevler kısmi türevdir:

$$
f(x_0 + \Delta x, y_0 + \Delta y) = f(x_0, y_0) + \frac{\partial f}{\partial x} \Delta x + \frac{\partial f}{\partial y} \Delta y + \frac{\partial^2 f}{\partial x^2} \frac{\Delta x^2}{2!} + \frac{\partial^2 f}{\partial y^2} \frac{\Delta y^2}{2!} + \cdots
$$

Aynısı $g$ için de yazılır. Türevler $(x_0, y_0)$ noktasında alınır.

> **Ek bilgi (derste anlatılmadı):** İki değişkenli serinin ikinci mertebe kısmında büyük olasılıkla bir de karışık türev terimi $\frac{\partial^2 f}{\partial x \partial y} \Delta x \Delta y$ bulunur. Bu terim derste söylenmedi. Bir sonraki adımda ikinci mertebeden terimlerin hepsi atıldığı için yöntem değişmez.

Hoca kesme hatasını hatırlattı. Yalnız ilk terim alınırsa olması gereken değerden çok uzak bir değer elde edilir. Birinci türevler katılınca değer biraz yaklaşır, ikinci türevler katılınca biraz daha yaklaşır. Ama her yeni terimin getirdiği değişim ilk terimlerinki kadar büyük değildir, gittikçe küçülür.

### 5.3 Matris Biçimi ve Algoritma

Yöntem, ikinci mertebe türevden başlayarak sağdaki tüm terimleri atar ve ifadeyi sıfıra eşitler:

$$
\begin{aligned}
f(x_0, y_0) + \frac{\partial f}{\partial x} \Delta x + \frac{\partial f}{\partial y} \Delta y &= 0 \\
g(x_0, y_0) + \frac{\partial g}{\partial x} \Delta x + \frac{\partial g}{\partial y} \Delta y &= 0
\end{aligned}
$$

Başlangıç değerleri konunca $f(x_0, y_0)$ ve $g(x_0, y_0)$ birer sayıdır. Bunlar eşitliğin diğer tarafına negatif olarak geçirilir. Kalan kısım matris formunda yazılır:

$$
\begin{bmatrix} \frac{\partial f}{\partial x} & \frac{\partial f}{\partial y} \\ \frac{\partial g}{\partial x} & \frac{\partial g}{\partial y} \end{bmatrix}
\begin{bmatrix} \Delta x \\ \Delta y \end{bmatrix}
=
- \begin{bmatrix} f(x_0, y_0) \\ g(x_0, y_0) \end{bmatrix}
$$

Algoritma şöyledir:

1. Verilen $x_k$, $y_k$ değerleri matrise ve sağ tarafa konur.
2. Doğrusal sistem istenen yöntemle çözülür, $\Delta x$ ve $\Delta y$ bulunur.
3. Yeni değerler hesaplanır: $x_{k+1} = x_k + \Delta x$, $y_{k+1} = y_k + \Delta y$.
4. $|x_{k+1} - x_k| = |\Delta x| \le \varepsilon$ ve $|y_{k+1} - y_k| = |\Delta y| \le \varepsilon$ ise durulur. Son bulunan $x$ ve $y$ çözümdür.
5. Şart sağlanmıyorsa yeni $x$ ve $y$ ile birinci adıma dönülür. Her turda $\Delta x$ ve $\Delta y$ değişir.

### 5.4 Üç ve Daha Fazla Değişken

Üç değişkende $f$, $g$, $v$ fonksiyonları ile $x$, $y$, $z$ değişkenleri vardır. Her fonksiyon Taylor serisine açılır, birinci türeve kadar alınır. Kalan terimler atılır, fonksiyon değerleri negatif olarak sağ tarafa geçer:

$$
\begin{bmatrix}
\frac{\partial f}{\partial x} & \frac{\partial f}{\partial y} & \frac{\partial f}{\partial z} \\
\frac{\partial g}{\partial x} & \frac{\partial g}{\partial y} & \frac{\partial g}{\partial z} \\
\frac{\partial v}{\partial x} & \frac{\partial v}{\partial y} & \frac{\partial v}{\partial z}
\end{bmatrix}
\begin{bmatrix} \Delta x \\ \Delta y \\ \Delta z \end{bmatrix}
=
- \begin{bmatrix} f \\ g \\ v \end{bmatrix}
$$

Hoca dördüncü bir $q$ fonksiyonu ve dördüncü bir $k$ değişkeni eklenirse neler değişeceğini anlattı:

- Matrise bir kolon gelir: $f$, $g$, $v$'nin $k$'ya göre türevleri.
- Matrise bir satır gelir: $q$'nun $x$, $y$, $z$ ve $k$'ya göre türevleri.
- Bilinmeyenler vektörüne $\Delta k$, sağ tarafa da $-q$ eklenir.

Başka hiçbir şey değişmez. Kaç değişken ve denklem gelirse gelsin yöntem aynıdır.

### 5.5 Örnek

Çözülecek sistem:

$$
f(x, y) = x^2 + y - 3 = 0, \qquad g(x, y) = x + y^2 - 5 = 0
$$

Başlangıç değerleri $x_0 = 0.7$, $y_0 = 1.7$, hata $\varepsilon = 0.08$'dir. Yani yerine konduğunda iki denklemi de 0 yapan $x$ ve $y$ aranır.

**Türevler.** $f$'in $x$'e göre türevi $2x$, $y$'ye göre türevi 1'dir. $g$'nin $x$'e göre türevi 1, $y$'ye göre türevi $2y$'dir:

$$
\begin{bmatrix} 2x & 1 \\ 1 & 2y \end{bmatrix}
\begin{bmatrix} \Delta x \\ \Delta y \end{bmatrix}
=
- \begin{bmatrix} x^2 + y - 3 \\ x + y^2 - 5 \end{bmatrix}
$$

**Birinci iterasyon.** $x = 0.7$, $y = 1.7$ konur. Sağ tarafta $0.7^2 + 1.7 - 3 = -0.81$ ve $0.7 + 1.7^2 - 5 = -1.41$ bulunur:

$$
\begin{bmatrix} 1.4 & 1 \\ 1 & 3.4 \end{bmatrix}
\begin{bmatrix} \Delta x \\ \Delta y \end{bmatrix}
=
- \begin{bmatrix} -0.81 \\ -1.41 \end{bmatrix}
$$

Sistem istenen yöntemle çözülür. Hoca slayttan $\Delta x = 0.31$, $\Delta y = 0.38$ okudu. Yeni değerler $x = 0.7 + 0.31 = 1.01$ ve $y = 1.7 + 0.38 = 2.08$ olur. Farklar 0.08'den büyük olduğu için bir iterasyon daha yapılır.

> **Ders sonrası not:** Hoca slayttan $\Delta x = 0.31$, $\Delta y = 0.38$ okudu. Bu sistemin doğru çözümü Python ile $\Delta x = 0.357$, $\Delta y = 0.310$'dur. Slayttaki değerler büyük olasılıkla hatalıdır, çünkü ikinci denklemi sağlamaz: $0.31 + 3.4 \cdot 0.38 = 1.60$, olması gereken 1.41. Doğru yol ile $x_1 = 1.057$, $y_1 = 2.010$ çıkar. Sonraki adımda $\Delta x = -0.056$, $\Delta y = -0.010$ olur ve yine durulur: $x = 1.002$, $y = 2.000$.

**İkinci iterasyon.** $x = 1.01$, $y = 2.08$ konur (ara adım eklendi):

$$
\begin{bmatrix} 2.02 & 1 \\ 1 & 4.16 \end{bmatrix}
\begin{bmatrix} \Delta x \\ \Delta y \end{bmatrix}
=
- \begin{bmatrix} 0.1001 \\ 0.3364 \end{bmatrix}
$$

Çözüm $\Delta x = -0.01$, $\Delta y = -0.08$'dir. Mutlak değerce ikisi de $0.08$'den küçük eşittir, öyleyse durulur. Son değerler bulunur:

$$
x = 1.01 - 0.01 = 1, \qquad y = 2.08 - 0.08 = 2
$$

<!-- BELİRSİZ: İkinci iterasyonun Δ değerleri altyazıda sözlü geçmiyor ("sonuçlar bunlar çıktı"). -0.01 ve -0.08 kısa nottan alındı, Python ile -0.0108 ve -0.0783 çıkıyor. -->

Gerçek çözüm $(1, 2)$'dir: $1 + 2 - 3 = 0$ ve $1 + 4 - 5 = 0$.

Hoca, hata 0.001 verilseydi bu farkların henüz şartı sağlamadığını söyledi. O zaman $x$ yerine 1, $y$ yerine 2 yazılır, yeni $\Delta x$, $\Delta y$ bulunur ve duruma göre ya durulur ya devam edilir. Üç değişkenli bir sistemde de değişen tek şey matrisin $3 \times 3$ olmasıdır.

## 6. Sayısal Türev

Hoca türev konusuna Newton-Raphson'u hatırlatarak girdi. O formülün paydasında bir türev ifadesi vardı. Bazen bu türevi almakta zorlanırız, bu yüzden türevden kurtulmak için sekant yöntemini kullanmıştık. Şimdiye kadar türevleri analitik yolla almıştık. Şimdi türev sayısal olarak alınacaktır.

### 6.1 Fonksiyonu ve Türevi Programa Girmek

Program yazılırken türev gerekiyorsa, türevin alınmış hali dışarıdan da girilebilir. Fonksiyon girmenin yolu, hocanın daha önce de söylediği gibi şöyledir. Örneğin $2x + 5$ için:

1. Kullanıcıya fonksiyonun derecesi sorulur: 1.
2. Birinci derecenin katsayısı sorulur: 2.
3. Derece azaltılır, sıfırıncı derecenin katsayısı sorulur: 5.

Derece azaltılarak bütün katsayılar alınır.

### 6.2 Türev Nedir, Mühendislikte Nerede Geçer?

Türev, bir noktadaki fonksiyonun değişimidir. Bağımlı bir değişkenin bağımsız bir değişkene göre değişme miktarıdır. $f(x)$ fonksiyonunun $x$'e göre türevinde $x$ bağımsız değişken, fonksiyon ise bağımlı değişkendir. Diğer bir tarifle, bir fonksiyonun bağlı olduğu değişkenlere göre değişim hızının ölçüsüdür.

Mühendislikte birçok yasa ve genelleştirme, fiziksel dünyadaki değişimlerin tahminine dayanır. Hoca şu örnekleri verdi:

- **Hız:** Bir cismin hızı, konumunun zamana göre değişimidir. $x$ konum ise $x$'in $t$'ye göre türevi hızı verir.
- **Isı geçişi:** Isı geçişleri sıcaklık farkındaki değişime bağlı olarak ifade edilir. Meteorolojide günlük sıcaklıklar arasındaki değişime bakılır.
- **Bobin:** Bobinin uçları arasındaki gerilim, üzerinden geçen akımın zamana göre değişimi üzerinden yazılır.
- **Kondansatör:** Kondansatörden geçen akım, uçlarındaki gerilimin zamana göre değişimi üzerinden yazılır.

> **Ders sonrası not:** Slayttaki hız örneği hoca tarafından Newton'un ikinci yasası başlığı altında anıldı. Hızın konumun türevi olması büyük olasılıkla tanımdır, Newton'un ikinci yasası ise kuvvet ile ivmeyi bağlar. Bobin ve kondansatör için ilişkiler de büyük olasılıkla $v = L \frac{di}{dt}$ ve $i = C \frac{dv}{dt}$ biçiminde, yani $L$ ve $C$ çarpanlarıyla orantılıdır.

Analitik olarak türev ya da integral almanın mümkün olmadığı yerlerde sayısal türev ve sayısal integral kullanılır.

### 6.3 Geometrik Anlam

Geometrik olarak türev, bir fonksiyona ait eğrinin $x$ noktasındaki teğetinin eğimidir. Bu, teğetin yatayla yaptığı açıyla ifade edilir. Newton-Raphson'da da bunu kullanmıştık: Teğetin eğimi $\tan \alpha$'ya eşitti. $\tan \alpha$ ise karşının komşuya oranıdır.

$$
f'(x) = \lim_{\Delta x \to 0} \frac{\Delta f(x)}{\Delta x}
$$

Burada komşu kenar iki $x$ değeri arasındaki fark, yani $\Delta x$'tir. Karşı kenar da o noktalardaki fonksiyon değerleri arasındaki farktır. Hoca bunu şöyle özetledi: Her şeyi bırakın, bir fonksiyonun türevini sayısal olarak almak demek, fonksiyonun $x_1$ noktasındaki değerinden $x_0$ noktasındaki değerini çıkarıp iki $x$ arasındaki $\Delta x$ farkına oranlamaktır.

### 6.4 Geri, İleri ve Merkezi Fark

$f(x)$ fonksiyonunun $x_i$ noktasındaki türevi üç farklı yolla bulunabilir.

**Geri fark.** $x_i$'nin $h$ kadar gerisindeki nokta alınır. Bu nokta $x_i$'nin solunda kaldığı için $x_{i-1}$ denir. Sembolü ters delta ($\nabla$) işaretidir.

$$
\nabla f(x_i) = \frac{f(x_i) - f(x_{i-1})}{x_i - x_{i-1}} = \frac{f(x_i) - f(x_i - h)}{h}
$$

> **Ders sonrası not:** Hoca bir an geri farkı "türevini bulacağım noktanın $h$ kadar ilerisindeki değer" diye tarif etti. Doğrusu $h$ kadar gerisindeki değerdir, hoca hemen ardından doğrusunu anlattı.

**İleri fark.** $x_i$'nin $h$ kadar ilerisindeki nokta alınır, bu da $x_{i+1}$'dir. Sembolü normal deltadır ($\Delta$).

$$
\Delta f(x_i) = \frac{f(x_{i+1}) - f(x_i)}{x_{i+1} - x_i} = \frac{f(x_i + h) - f(x_i)}{h}
$$

**Merkezi fark.** Ne ileri ne geri alınır. $x_i$ noktasındaki türev için hem gerideki hem ilerideki nokta kullanılır. İki nokta arasındaki mesafe $2h$'dir.

$$
f'(x_i) \approx \frac{f(x_{i+1}) - f(x_{i-1})}{x_{i+1} - x_{i-1}} = \frac{f(x_i + h) - f(x_i - h)}{2h}
$$

<!-- BELİRSİZ: Hoca merkezi farkın sembolüne "row işareti" dedi. Slayttaki sembol altyazıdan okunamıyor. -->

Hoca, formülleri unutan biri için yol gösterdi: Fonksiyonu çizin, $x$ noktasından teğet geçirin, geri için $x - h$, ileri için $x + h$, merkezi için ikisini birden işaretleyin. $\tan \alpha$ hesabındaki karşı bölü komşu oranı formülü verir. Formül ezberlemek zor gelirse bu çizim yeterlidir.

> **Ders sonrası not:** Altyazıya göre hoca bu tekrarda merkezi farkı "$f(x + h)$'dan $f(x + h)$'ı çıkarıp" diye söyledi. Doğrusu $f(x + h) - f(x - h)$'dir, bu büyük olasılıkla bir söyleniş ya da altyazı hatasıdır.

### 6.5 Neden Üç Yol? x Küp Grafiği

Hoca $f(x) = x^3$ için analitik türev ile üç farkı karşılaştıran iki grafik gösterdi. Grafikte 0, 2, 4 gibi noktalardaki türevler vardı. Siyah noktalar analitik türevdi.

- **$h = 0.1$ iken:** Merkezi fark siyah noktaların hemen üstündedir. İleri ve geri fark biraz yukarıda ve aşağıdadır.
- **$h$ büyük alınınca:** Geri ve ileri fark siyahtan oldukça uzaklaşır. Merkezi fark yine siyahla örtüşür.

Demek ki sayısal türevde merkezi fark analitik türeve çok yakın bir değer verir. $h$ ne kadar küçük olursa sonuç o kadar iyidir. Hoca $h = 0.01$ alınsaydı sapmaları gözle görmenin zorlaşacağını, ufak sapmaların ancak logaritmik eksende görülebileceğini söyledi.

<!-- BELİRSİZ: Grafik slaytta. Büyük h değeri altyazıda söylenmiyor, kısa nota göre h = 2. -->

> **Ders sonrası not:** Python ile $x^3$ için $h = 2$ alınırsa, $x = 4$ noktasında analitik türev 48, ileri fark 76, geri fark 28, merkezi fark 52 çıkar. Merkezi fark diğerlerinden çok daha yakındır, ama tam örtüşmez: $x^3$ için hatası büyük olasılıkla her noktada $h^2$, yani burada 4'tür.

> **Ek bilgi (derste anlatılmadı):** Basit ileri ve geri farkın hatası büyük olasılıkla $h$ ile orantılıdır, yani $O(h)$'dir. Merkezi farkın hatası ise $h^2$ ile orantılıdır, yani $O(h^2)$'dir. Bu yüzden $h$ yarıya inince merkezi farkın hatası yaklaşık dörtte birine iner. Merkezi farkın daha iyi sonuç vermesinin nedeni büyük olasılıkla budur.

### 6.6 Örnek: $e^x$

$f(x) = e^x$ fonksiyonunun $x = 1$ noktasındaki türevi $h = 0.1$ ile üç yöntemle hesaplanacaktır. Analitik sonuç $e^1 = 2.7183$'tür, yani yaklaşık 2.72.

**İleri fark (ara değerler eklendi).** $x + h = 1.1$:

$$
\frac{e^{1.1} - e^{1}}{0.1} = \frac{3.0042 - 2.7183}{0.1} = 2.86
$$

**Geri fark (ara değerler eklendi).** $x - h = 0.9$:

$$
\frac{e^{1} - e^{0.9}}{0.1} = \frac{2.7183 - 2.4596}{0.1} = 2.59
$$

Analitik türev 2.72 iken ileri fark 2.86, geri fark 2.59 çıktı. Yakındırlar ama tam değildir.

**Merkezi fark (ara değerler eklendi).** Payda $2h = 0.2$'dir:

$$
\frac{e^{1.1} - e^{0.9}}{0.2} = \frac{3.0042 - 2.4596}{0.2} = 2.72
$$

Merkezi fark ile analitik sonuç iki basamakta aynı çıkar. Bu yüzden sayısal türev alırken merkezi farkla almak çok daha iyidir.

> **Ders sonrası not:** Hoca bu hesapta bir yerde "$h$ 0.2 idi" dedi, doğrusu $h = 0.1$, $2h = 0.2$'dir, bu büyük olasılıkla bir sürçmedir. Python ile değerler ileri 2.8588, geri 2.5868, merkezi 2.7228, analitik 2.7183'tür.

**Alıştırma.** Hoca $f(x) = x^2$ için analitik türevi 2 olan noktada ve verilen $h$ ile üç farkı hesaplamanızı istedi. Merkezi fark 2 çıkmalı, ileri fark 2'den biraz büyük, geri fark 2'den biraz küçük olmalıdır. Hoca bu farkların yukarıdaki örnekteki gibi analitik türevin iki yanına düştüğünü hatırlattı.

> **Ders sonrası not:** Alıştırmanın $h$ değeri altyazıda yok. Kontrol için büyük olasılıkla $x = 1$, $h = 0.1$ alınırsa Python ile ileri fark 2.1, geri fark 1.9, merkezi fark 2'dir.

## 7. Taylor Serisiyle Türev Formülleri

Taylor serisi burada da karşımıza çıkar. Hocanın dediği gibi birinci, ikinci, hatta beşinci dereceden türevin formülü Taylor serisinden çıkarılabilir. Seri şöyleydi:

$$
f(x_{i+1}) = f(x_i) + f'(x_i) \frac{\Delta x}{1!} + f''(x_i) \frac{\Delta x^2}{2!} + f'''(x_i) \frac{\Delta x^3}{3!} + \cdots
$$

Buradaki $\Delta x$ yerine $h$ de yazılabilir.

### 7.1 Birinci Türev

Birinci türev için fonksiyonun $x + h$ ve $x + 2h$ civarındaki değerleri ikinci kuvvete kadar açılır:

$$
\begin{aligned}
f(x + h) &= f(x) + h f'(x) + \frac{h^2}{2!} f''(x) \\
f(x + 2h) &= f(x) + 2h f'(x) + \frac{(2h)^2}{2!} f''(x)
\end{aligned}
$$

Amaç ikinci türevi yok etmektir. İkinci açılımda $f''$ çarpanı $\frac{4h^2}{2} = 2h^2$, birincisinde $\frac{h^2}{2}$'dir. Birinci denklem $-4$ ile çarpılırsa iki terim birbirini götürür:

$$
-4 f(x + h) = -4 f(x) - 4h f'(x) - 2h^2 f''(x)
$$

İkinci açılımla toplanır:

$$
-4 f(x + h) + f(x + 2h) = -3 f(x) - 2h f'(x)
$$

$f'$ yalnız bırakılıp her iki taraf $2h$'ye bölünür. $f(x)$ yerine $f_i$, $f(x + h)$ yerine $f_{i+1}$, $f(x + 2h)$ yerine $f_{i+2}$ yazılır:

$$
f'_i = \frac{1}{2h} \left[ -3 f_i + 4 f_{i+1} - f_{i+2} \right]
$$

Yapılacak tek şey fonksiyonda $x$, $x + h$, $x + 2h$ değerlerini hesaplayıp bu işlemi yapmaktır.

> **Ders sonrası not:** Hoca slayt üzerinde bu toplamı yaparken terimleri önce ters tarafa geçirdi ve işaretleri düzelterek ilerledi. Slayttaki sonuç büyük olasılıkla bu formüldür ve doğrudur. Python ile formül $x^0$, $x^1$, $x^2$ için tam sonuç verir.

### 7.2 İkinci Türev

Aynı iki açılım alınır, ama bu kez birinci türevler yok edilir. Birinci denklem $-2$ ile çarpılır:

$$
-2 f(x + h) = -2 f(x) - 2h f'(x) - h^2 f''(x)
$$

$f(x + 2h)$ açılımı ile toplanınca $f'$ terimleri gider, $f''$ için $2h^2 - h^2 = h^2$ kalır:

$$
f(x + 2h) - 2 f(x + h) = - f(x) + h^2 f''(x)
$$

$h^2$ diğer tarafa bölü olarak geçer:

$$
f''_i = \frac{1}{h^2} \left[ f_i - 2 f_{i+1} + f_{i+2} \right]
$$

### 7.3 Üçüncü Türev, Geri ve Merkezi Fark

Üçüncü türev için seri üçüncü kuvvete kadar açılır ve öyle çarpanlar seçilir ki birinci ve ikinci türevler gider. Hoca, kitaplarda ve internette bu formülleri görebileceğinizi, yapılan şeyin de bu olduğunu söyledi. Genel kural şudur:

- Birinci türev için ikinci türevler yok edilir.
- İkinci türev için birinci türevler yok edilir.
- Üçüncü türev için birinci ve ikinci türevler yok edilir.

Burada anlatılan ileri farklı biçimdir. Geri farkta $x - h$ ve $x - 2h$ konur. Merkezi farkta $x - h$ ve $x + h$ konur. İşlemler aynıdır. Hoca bunların türetilmesini istemediğini, amacın yalnız türevin Taylor serisinden de bulunabildiğini görmek olduğunu söyledi.

### 7.4 Alıştırma: Üçüncü Kuvvete Kadar Açmak

Hoca şu alıştırmayı verdi: Taylor serisini üçüncü kuvvete kadar açarak ileri fark yönteminin türev yaklaşımlarının aşağıdaki gibi olduğunu gösterin. Birinci, ikinci ya da üçüncü türevi yalnız bırakacak çarpanlar seçilir.

$$
\begin{aligned}
f'_i &= \frac{1}{6h} \left[ -11 f_i + 18 f_{i+1} - 9 f_{i+2} + 2 f_{i+3} \right] \\
f''_i &= \frac{1}{h^2} \left[ 2 f_i - 5 f_{i+1} + 4 f_{i+2} - f_{i+3} \right] \\
f'''_i &= \frac{1}{h^3} \left[ -f_i + 3 f_{i+1} - 3 f_{i+2} + f_{i+3} \right]
\end{aligned}
$$

<!-- BELİRSİZ: Bu üç formül slaytta, altyazıda okunmuyor. Formüller kısa nottan alındı. -->

Hoca, çözümlerin kitaplarda ve internette bulunduğunu, ama önce kendiniz denemeniz gerektiğini söyledi. Bu sonuçları bulamazsanız önce işlem hatası yapıp yapmadığınıza bakın. İşlem hatası olmadığından eminseniz çözüme bakın.

> **Ders sonrası not:** Slaytta büyük olasılıkla bu formüllere "3 noktalı", $f'_i$'nin iki açılımlı biçimine "iki noktalı" deniyordu. Formüller fiilen sırasıyla dört ve üç nokta kullanır. Ad büyük olasılıkla açılan nokta sayısını ($x + h$, $x + 2h$, $x + 3h$) gösteriyor. Üç formül de Python ile tam kesirli hesapla kontrol edildi ve doğru çıktı.

### 7.5 Alıştırma: İleri Fark ve Taylor

Hoca son olarak şu soruyu verdi: $f(x) = 2x^2 + 1$, $x = 2$. Yaklaşık türevi önce basit ileri farkla, sonra Taylor serisinden çıkan iki noktalı (ikinci dereceye kadar alınan) formülle bulun. Analitik türev 8'dir. Merkezi farkla 8, ileri farkla 8 virgül bir şey, geri farkla 7 virgül 8 ya da 9 gibi bir değer çıkmalıdır.

<!-- BELİRSİZ: Fonksiyon altyazıda bozuk ("x, g, artı bir") ve h değeri söylenmiyor. Fonksiyon ve h = 0.1 kısa nottan alındı. -->

Hoca hesabın anlamlı basamak sayısıyla değiştiğini de hatırlattı. İki kişi aynı soruyu biri üç, diğeri beş anlamlı basamakla çözerse farklı sonuçlar bulur. Ondalık nokta sayısı da aynı şekilde önemlidir. Ne kadar hassas işlem yapılırsa analitik çözüme o kadar yakın sonuç elde edilir.

> **Ders sonrası not:** Kontrol için, önce kendiniz çözün. Büyük olasılıkla $h = 0.1$ ile Python hesabı şöyledir: $f(1.9) = 8.22$, $f(2) = 9$, $f(2.1) = 9.82$, $f(2.2) = 10.68$. İleri fark 8.2, geri fark 7.8, merkezi fark 8'dir. Taylor formülü $\frac{-3 \cdot 9 + 4 \cdot 9.82 - 10.68}{0.2} = 8$ verir.

## 8. Algoritmaları Kodlarken: Sorular ve Uç Durumlar

Dersin sonunda kod yazımıyla ilgili sorular geldi.

**Soru:** Kod yazarken fonksiyon kullanmak serbest mi? Şimdilik daha çok döngülerle yazıyoruz. **Cevap:** Yazabilirsiniz. İlk yöntemlerde, örneğin denklem takımlarında, fonksiyona zaten ihtiyacınız olmaz. Fonksiyonu öğrendikçe sonraki yöntemlerde kullanırsınız.

**Soru:** Programlama derslerinde `switch-case` ve `break` gibi komutlara izin verilmiyor. Bu ders için de öyle mi? **Cevap:** Bir bilgisayar mühendisi `break`, `goto` kullanmaz. Çok istisnai, olmazsa olmaz bir durum olmadıkça bunları kullanmadan yazın. Hoca, bu kodları daha önce yazanların ve kendilerinin `break`, `exit`, `goto` kullanmadığını söyledi.

Hoca, kodu tek bir değerle deneyip kenara koymamayı önemle tekrarladı. Birkaç değerle ve uç noktalarla denemek gerekir. Örnek olarak kökü 2 olan bir fonksiyon ve kök bulma yöntemi verdi:

- $a$ ve $b$ hep 0 ile 5 arasında verilince program sorunsuz çalışabilir.
- $[2.5, 3]$ aralığı verilirse program "verilen aralıkta kök yoktur" demelidir. Kök bulma yöntemlerinde bu kontrol vardı, yazmayı unutmayın.
- $[1.98, 2.1]$ gibi dar bir aralık verilirse programın bir yerde takılıp takılmadığına ya da 2'yi bulup bulmadığına bakılmalıdır.

Hoca bunu bir arabayla anlattı: Altınızda çok güzel bir araba var, kontağı çeviriyorsunuz, ama bir gıdım benzin kalmış. Biraz ilerliyorsunuz ve araba duruyor. Yola çıkmadan önce benzin var mı diye bakmalısınız. Uç nokta kontrolü de böyle bir şeydir.

> **Hocanın vurgusu:** Uç nokta problemleri çok önemlidir. Tek bir değerle çalıştı deyip kodu kenara koymayın.

## Dersin Toparlaması

Bu derste doğrusal denklem takımlarının dolaysız yöntemleri Cholesky ile bitti: $A = L U$ yazılır, önce $L Y = C$, sonra $U X = Y$ çözülür. Ardından iki dolaylı yöntem görüldü. İkisinde de en önemli adım köşegeni maksimum yapmaktır. Jacobi bir önceki iterasyonun, Gauss-Seidel en son bulunan değerleri kullanır ve aynı örnekte daha az adımda biter. Durma için bütün değişkenlerin farkı hatadan küçük eşit olmalıdır. Doğrusal olmayan denklem takımlarında iki değişkenli Taylor serisi birinci türevde kesilir, her adımda türev matrisiyle bir doğrusal sistem çözülür ve bulunan $\Delta$ değerleri eklenir.

İkinci yarıda sayısal türev geldi. Türev teğetin eğimidir. Geri, ileri ve merkezi fark bu eğimin üç yaklaşık hesabıdır. Merkezi fark analitik türeve en yakın sonucu verir. Taylor serisinden de istenmeyen türevler yok edilerek formüller çıkarılabilir. Hocanın söylediğine göre gelecek hafta integral (trapez, Simpson, iki katlı integral) görülecek, ardından sonlu farklara geçilecektir. Regresyon ve enterpolasyon daha sonraya kalabilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
