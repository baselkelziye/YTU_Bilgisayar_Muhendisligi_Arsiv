# Ders 4 Çalışma Özeti

## Genel Konular

- Veri indirgeme haritasının hatırlatılması
  - Veri indirgeme üç başlıkta toplanır: öznitelik indirgeme (feature reduction), örnek indirgeme (sample reduction) ve değer indirgeme (value reduction).
  - Öznitelik indirgeme iki yolla yapılır: öznitelik seçme (feature selection) ve öznitelik birleştirme (feature composition).
  - Öznitelik seçme önceki derste işlendi. Bu derste öznitelik birleştirme tarafında eğitmensiz (unsupervised) bir yöntem olan Temel Bileşen Analizi (Principal Component Analysis, PCA) anlatıldı.
  - Anlatım, internetten bulunan "A tutorial on Principal Components Analysis" (Lindsay I. Smith, 2002) belgesi üzerinden yürüdü (ekrandan, 00:10:00).
- İstatistik hatırlatması: ortalama, standart sapma, varyans
  - Ortalama: $\bar{X} = \frac{\sum_{i=1}^{n} X_i}{n}$ (ekrandan, 00:15:00).
  - Ortalama tek başına veriyi tarif etmeye yetmez: $[0, 8, 12, 20]$ ve $[8, 9, 11, 12]$ dizilerinin ikisinin de ortalaması 10'dur ama yayılımları çok farklıdır.
  - Standart sapma: $s = \sqrt{\frac{\sum_{i=1}^{n}(X_i - \bar{X})^2}{n-1}}$ (ekrandan, 00:15:00). Birinci dizi için $s \approx 8{,}33$, ikinci dizi için $s \approx 1{,}83$.
  - Yorum: değerler kabaca $\bar{X} \pm s$ aralığında dağılır. İkinci dizi için bu aralık yaklaşık $8{,}2$ ile $11{,}8$ arasıdır; dizinin gerçekten 8 ile 12 arasında değiştiği görülür.
  - Varyans, standart sapmanın karesidir (karekök alınmadan bırakılan değer).
- Kovaryans
  - Varyans tek bir değişkene (tek boyuta) bakar. Kovaryans iki değişkenin birlikte nasıl değiştiğini ölçer: $\mathrm{cov}(X,Y) = \frac{\sum_{i=1}^{n}(X_i - \bar{X})(Y_i - \bar{Y})}{n-1}$ (ekrandan, 00:20:00).
  - Varyans, kovaryansın bir değişkenin kendisiyle hesaplanmış hâlidir: $\mathrm{var}(X) = \mathrm{cov}(X,X)$.
  - Veri madenciliği açısından her değişken bir özniteliktir; kovaryans iki öznitelik arasındaki ilişkiyi gösterir.
  - Örnek: 12 öğrencinin bir derse çalıştığı saat (H) ve aldığı puan (M). Ortalama çalışma süresi yaklaşık 13,92 saat, ortalama puan yaklaşık 62'dir (ekrandan, 00:25:00).
  - Her öğrenci için iki farkın çarpımı alınır. Ortalamadan az çalışıp ortalamanın altında puan alan öğrencide iki fark da negatiftir, çarpım pozitif çıkar. Daha çok çalışıp ortalamanın altında puan alan istisnalar (ör. 15 saat, 56 puan) negatif çarpım verir ama genel yapıyı değiştirmez.
  - Kovaryansın pozitif çıkması iki değişkenin aynı yönde değiştiğini (biri artarken öbürü de artar) gösterir.
- Kovaryans matrisi
  - Değişken sayısı arttığında ikili kovaryanslar bir matriste toplanır. $n$ değişken için $n \times n$ boyutludur.
  - Üç değişken $(x, y, z)$ için ana köşegende $\mathrm{cov}(x,x)$, $\mathrm{cov}(y,y)$, $\mathrm{cov}(z,z)$ yani varyanslar bulunur; köşegen dışında ikili kovaryanslar vardır.
  - $\mathrm{cov}(a,b) = \mathrm{cov}(b,a)$ olduğu için kovaryans matrisi simetriktir.
- Lineer cebir hatırlatması: özdeğer ve özvektör
  - $\begin{pmatrix}2 & 3\\ 2 & 1\end{pmatrix}\begin{pmatrix}3\\ 2\end{pmatrix} = \begin{pmatrix}12\\ 8\end{pmatrix} = 4\begin{pmatrix}3\\ 2\end{pmatrix}$ (ekrandan, 00:35:00). Sonuç, aynı vektörün bir katsayıyla çarpımı olarak yazılabildiği için $(3,2)$ bir özvektör, 4 de onun özdeğeridir.
  - Genel tanım: $A\mathbf{u} = \lambda\mathbf{u}$. Buradan $(A - \lambda I)\mathbf{u} = 0$ ve karakteristik denklem $\det(A - \lambda I) = 0$ elde edilir.
  - Önce $\lambda$ değerleri bulunur, sonra her $\lambda$ için ona ait özvektör hesaplanır.
  - Örnek (hocanın el yazısı notları, ekrandan, 00:55:00 ve 01:00:00): $A = \begin{pmatrix}2 & 1\\ 1 & 2\end{pmatrix}$ için $(2-\lambda)^2 - 1 = 0$, yani $\lambda^2 - 4\lambda + 3 = 0$; kökler $\lambda = 1$ ve $\lambda = 3$. $\lambda = 3$ için $x = y$, özvektör $(1, 1)$; $\lambda = 1$ için $x = -y$, özvektör $(1, -1)$.
  - PCA'da önemli olan özvektörün uzunluğu değil yönelimidir; $x = y$ doğrusu bir yeni eksen olur.
- Temel Bileşen Analizinin adımları
  - Adım 1: Veri seti al. Örnekte 10 örnekli, iki öznitelikli $(x, y)$ bir veri seti kullanıldı (ekrandan, 01:05:00).
  - Adım 2: Her boyutun ortalamasını hesapla ve tüm örneklerden çıkar (subtract the mean). Elde edilen veri "DataAdjust" olarak adlandırılır. Geometrik anlamı, veri bulutunun orta noktasının koordinat düzleminin orijinine taşınmasıdır.
  - Adım 3: Ortalaması çıkarılmış veri için kovaryans matrisini hesapla. İki öznitelik olduğu için matris $2 \times 2$'dir; köşegen dışı değer yaklaşık 0,6154'tür.
  - Adım 4: Kovaryans matrisinin özdeğer ve özvektörlerini hesapla. Özdeğerler yaklaşık $\lambda_1 = 0{,}049$ ve $\lambda_2 = 1{,}284$; özvektör bileşenleri yaklaşık 0,677 ve 0,735 büyüklüğündedir.
  - Özvektörler verinin yönelimini gösteren yeni eksenlerdir (ekrandan, 01:10:00 ve 01:20:00). Büyük özdeğerli $\mathbf{u}_2$, veri bulutunun uzandığı köşegen doğrultusundadır; küçük özdeğerli $\mathbf{u}_1$ ona diktir.
  - Adım 5: Bileşen seçme ve öznitelik vektörü oluşturma (choosing components and forming a feature vector). Örnekler yeni $\mathbf{u}_1$-$\mathbf{u}_2$ düzlemine izdüşürülür (projeksiyon).
- Boyut azaltma ve bileşen sayısının seçimi
  - Örneklerin $\mathbf{u}_2$ üzerindeki izdüşümleri geniş bir aralıkta, $\mathbf{u}_1$ üzerindekiler dar bir aralıkta değişir. Değişimin az olduğu eksen atılarak iki boyuttan bir boyuta inilir.
  - $d$ öznitelikli veride $d \times d$ kovaryans matrisi, $d$ özdeğer ve $d$ özvektör çıkar. Özdeğerler büyükten küçüğe sıralanır: $L_1 > L_2 > \dots > L_{10}$ (ekrandan, 01:30:00).
  - Sırayla $\frac{L_1}{L_1 + \dots + L_{10}}$, sonra $\frac{L_1 + L_2}{L_1 + \dots + L_{10}}$ hesaplanır ve oranın %95 eşiğini geçip geçmediğine bakılır. Eşik sağlanana kadar bileşen eklenir. Eşik %90 gibi farklı seçilebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- İstatistiksel parametreleri yorumlamak
  - Ortalama, standart sapma, varyans ve kovaryans yalnız formül olarak görülmemeli; her birinin veri hakkında ne söylediği düşünülmelidir. Bir veriyi tarif etmek için ortalama yetmez, standart sapma da gerekir.
- Kovaryansın işareti
  - Kovaryansın ne zaman pozitif, ne zaman negatif çıktığı ve bunun ne anlama geldiği önemlidir; pozitif kovaryans aynı yönde değişimi gösterir.
- Kovaryans matrisinin yapısı
  - Ana köşegende varyanslar vardır ve matris simetriktir.
- Büyük özdeğer önemlidir
  - Özdeğerlerden biri çok küçük (0,049), öbürü çok büyük (1,28) çıkar; bu fark hangi eksenin tutulacağının göstergesidir.
- Neden yüksek varyanslı eksen?
  - Geniş aralıkta değişen eksende örnekler birbirinden ayırt edilebilir. Dar aralıkta değişen eksende örnekler üst üste biner ve ayırt etmek zorlaşır. Bu yüzden varyansı yüksek eksen daha değerli bir öznitelik olur.

## Kısa Tekrar Notları

- PCA, öznitelik birleştirme yoluyla boyut azaltan eğitmensiz bir yöntemdir.
- Standart sapma ve kovaryans formüllerinde payda $n-1$'dir.
- $\mathrm{var}(X) = \mathrm{cov}(X,X)$; kovaryans matrisi simetrik, köşegeni varyanslardır.
- $A\mathbf{u} = \lambda\mathbf{u}$ ve $\det(A - \lambda I) = 0$.
- $\begin{pmatrix}2 & 1\\ 1 & 2\end{pmatrix}$: özdeğerler 1 ve 3, özvektörler $(1,-1)$ ve $(1,1)$.
- PCA adımları: veri al, ortalamayı çıkar, kovaryans matrisini hesapla, özdeğer/özvektör hesapla, bileşen seç ve izdüşür.
- Özvektörler yeni koordinat eksenleridir; özdeğer büyüdükçe o eksendeki varyans büyür.
- Bileşen sayısı: sıralı özdeğerlerin birikimli oranı eşiği (ör. %95) geçene kadar bileşen eklenir.

## Detaylı Açıklamalar

- Ortalama, standart sapma ve varyans
  - $[0, 8, 12, 20]$ ve $[8, 9, 11, 12]$ dizilerinin toplamları 40'tır ve 4'e bölününce ikisinin de ortalaması 10 çıkar. Buna karşın birinci dizi 0-20 aralığında, ikinci dizi 8-12 aralığında değişir. Bu farkı standart sapma yakalar: her elemandan ortalama çıkarılır, farkların kareleri toplanır, $n-1$'e bölünür (varyans) ve karekök alınır. Birinci dizi için yaklaşık 8,33, ikinci dizi için yaklaşık 1,83 bulunur. Ortalama $\pm$ standart sapma aralığı, sayıların ortalamadan ne kadar uzaklaştığını özetler.
  - > **Ders sonrası not:** Hoca birinci dizi için $10 - 8{,}32$ sonucunu yaklaşık 1,7 diye söyledi; doğrusu $1{,}68$'dir.
- Kovaryans örneği
  - Çalışma saati ve puan veri setinde her satır bir örnek (öğrenci), iki sütun iki özniteliktir. Tablo (ekrandan, 00:25:00):

    | H | M | $H_i - \bar{H}$ | $M_i - \bar{M}$ | Çarpım |
    |---|---|---|---|---|
    | 9 | 39 | -4,92 | -23,42 | 115,23 |
    | 15 | 56 | 1,08 | -6,42 | -6,93 |
    | 25 | 93 | 11,08 | 30,58 | 338,83 |
    | 14 | 61 | 0,08 | -1,42 | -0,11 |
    | 10 | 50 | -3,92 | -12,42 | 48,69 |
    | 18 | 75 | 4,08 | 12,58 | 51,33 |
    | 0 | 32 | -13,92 | -30,42 | 423,45 |
    | 16 | 85 | 2,08 | 22,58 | 46,97 |
    | 5 | 42 | -8,92 | -20,42 | 182,15 |
    | 19 | 70 | 5,08 | 7,58 | 38,51 |
    | 16 | 66 | 2,08 | 3,58 | 7,45 |
    | 20 | 80 | 6,08 | 17,58 | 106,89 |

  - Çarpımlar toplanıp $n - 1 = 11$'e bölünür. Ekrandaki belgede toplam 1149,89, kovaryans yaklaşık 104,53 olarak verildi; sonuç pozitiftir, çalışma süresi ile puan aynı yönde değişir.
  - > **Ders sonrası not:** Tablodaki çarpımların gerçek toplamı 1352,46'dır (python ile kontrol edildi). Belgedeki 1149,89 toplamı hatalıdır; kovaryans yaklaşık $1352{,}46 / 11 \approx 122{,}95$ olmalıdır. İşaret ve yorum değişmez.
- Özdeğer ve özvektör
  - $\begin{pmatrix}2 & 3\\ 2 & 1\end{pmatrix}$ matrisi $(1,3)$ ile çarpılınca $(11,5)$ çıkar ve bu, $(1,3)$'ün bir katı değildir. $(3,2)$ ile çarpılınca $(12,8) = 4 \cdot (3,2)$ çıkar. Özvektörün bir katı da özvektördür: $(6,4)$ için sonuç $(24,16) = 4 \cdot (6,4)$ olur (ekrandan, 00:35:00).
  - $A\mathbf{u} = \lambda\mathbf{u}$ eşitliğinde sağ taraf sola alınır: $A\mathbf{u} - \lambda I\mathbf{u} = 0$, ortak $\mathbf{u}$ paranteze alınır: $(A - \lambda I)\mathbf{u} = 0$. Sıfırdan farklı çözüm için $\det(A - \lambda I) = 0$ olmalıdır. $\lambda I$ çıkarmak, $A$'nın yalnız ana köşegenindeki elemanlardan $\lambda$ çıkarmaktır.
  - $A = \begin{pmatrix}2 & 1\\ 1 & 2\end{pmatrix}$ için $\det\begin{pmatrix}2-\lambda & 1\\ 1 & 2-\lambda\end{pmatrix} = (2-\lambda)^2 - 1 = 0$. Açılınca $\lambda^2 - 4\lambda + 3 = 0$, kökler 1 ve 3'tür. $\lambda = 3$ için $2x + y = 3x$ ve $x + 2y = 3y$ denklemlerinin ikisi de $x = y$ verir; $x = 1$ seçilirse özvektör $(1,1)$ olur. $\lambda = 1$ için benzer işlem $x = -y$ verir; özvektör $(1,-1)$, koordinat düzleminde ikinci/dördüncü bölgeden geçen doğrudur.
  - > **Ders sonrası not:** Hoca karakteristik denklemi sözlü olarak "$\lambda^2 - 4\lambda + 4 = 0$" diye söyledi; doğrusu $\lambda^2 - 4\lambda + 3 = 0$'dır (el yazısı notta da $4 - 4\lambda + \lambda^2 - 1$ görülür). Hocanın verdiği kökler (1 ve 3) doğrudur.
- PCA örneği
  - Veri (ekrandan, 01:05:00; ilk satır sözlü, 01:03:39):

    | x | y | x - ortalama | y - ortalama |
    |---|---|---|---|
    | 2,5 | 2,4 | 0,69 | 0,49 |
    | 0,5 | 0,7 | -1,31 | -1,21 |
    | 2,2 | 2,9 | 0,39 | 0,99 |
    | 1,9 | 2,2 | 0,09 | 0,29 |
    | 3,1 | 3,0 | 1,29 | 1,09 |
    | 2,3 | 2,7 | 0,49 | 0,79 |
    | 2,0 | 1,6 | 0,19 | -0,31 |
    | 1,0 | 1,1 | -0,81 | -0,81 |
    | 1,5 | 1,6 | -0,31 | -0,31 |
    | 1,1 | 0,9 | -0,71 | -1,01 |

  - Ortalamalar $\bar{x} = 1{,}81$, $\bar{y} = 1{,}91$'dir (python ile kontrol edildi). Ortalaması çıkarılan veri orijin çevresinde dağılır.
  - Kovaryans matrisi python ile yaklaşık $\begin{pmatrix}0{,}6166 & 0{,}6154\\ 0{,}6154 & 0{,}7166\end{pmatrix}$ bulunur; derste söylenen köşegen dışı değer (0,6154) ile uyumludur. Özdeğerler 0,0491 ve 1,2840'tır.
  - Derste özvektör matrisinin birinci sütunu $\mathbf{u}_1 \approx (-0{,}735;\ 0{,}677)$ ($\lambda_1 = 0{,}049$), ikinci sütunu $\mathbf{u}_2 \approx (-0{,}677;\ -0{,}735)$ ($\lambda_2 = 1{,}28$) olarak okundu. Hoca $\mathbf{u}_2$'yi $(0{,}67;\ 0{,}735)$ noktasından ve orijinden geçen doğru olarak çizdi; bu, aynı yöndeki doğrudur. $\mathbf{u}_1$ ise ona dik olan öbür köşegendir. <!-- BELİRSİZ: Kovaryans matrisi ve özvektör matrisinin ekran görüntüsü karelerde yok; değerler altyazıdan ve python kontrolünden alındı. -->
  - Grafikte (ekrandan, 01:10:00) veri bulutu $\mathbf{u}_2$ doğrultusunda uzanır. İzdüşümler $\mathbf{u}_2$ üzerinde geniş, $\mathbf{u}_1$ üzerinde dar aralıkta kalır; bu yüzden $\mathbf{u}_1$ atılabilir.
  - > **Ders sonrası not:** Bu örnekte büyük özdeğerin toplamdaki payı $1{,}284 / (1{,}284 + 0{,}049) \approx \%96{,}3$'tür (python ile hesaplandı). Derste verilen %95 kuralına göre tek bileşen yeterlidir.
- Bileşen sayısının seçimi (10 öznitelik örneği)
  - Bir öğrencinin sorusu üzerine hoca çok boyutlu durumu anlattı: 10 öznitelikli veri $10 \times 10$ kovaryans matrisi, 10 özdeğer ve 10 özvektör verir. Özdeğerler sıralanır, önce $L_1$'in toplam içindeki payına bakılır; %95 sağlanmazsa $L_2$ eklenir, sonra $L_3$ ve böyle devam edilir. Kaç bileşen eklendiyse veri o kadar boyuta indirgenmiş olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
