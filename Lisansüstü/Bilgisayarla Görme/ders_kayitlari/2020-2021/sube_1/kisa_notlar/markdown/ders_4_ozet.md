# Ders 4 Çalışma Özeti

## Genel Konular

- Ödev değerlendirmesi üzerinden Gauss çekirdeği ve ayrılabilir filtreleme
  - İki boyutlu Gauss çekirdeği `np.mgrid` (ya da `meshgrid`) ile kurulan koordinat ızgarası üzerinde doğrudan hesaplanabilir. Hoca, çekirdeği iç içe iki döngüyle kurmak yerine NumPy'ın vektörel imkânlarının kullanılmasını istedi.
  - Büyük bir çekirdeğin kenarlarındaki sıfıra çok yakın değerler atılarak daha küçük (ör. $7\times7$) bir filtre elde edilebilir.
  - Önce yatay, sonra dikey bir boyutlu Gauss uygulamak, iki boyutlu Gauss uygulamakla aynı sonucu verir (ayrılabilirlik).
  - Yalnız ortası 1 olan bir imgeye (delta imgesi) filtre uygulanırsa sonuç filtrenin kendisidir.
  - İki Gauss art arda uygulandığında varyanslar toplanır: tek bir Gauss'un varyansı ikisinin varyanslarının toplamıdır.
- Kenar bulma (edge detection) tekrarı
  - Kenar, imgede büyük renk/parlaklık değişiminin olduğu yerdir. Türev değişimin miktarı olduğu için kenar bulma bir türev operatörünün imgeye uygulanmasıdır. İmgede birim değişim bir pikseldir.
  - Sobel kenar bulucusu (ekrandan, 00:40:00): bir boyutlu türev $[1\;\;-1]$ ile yumuşatıcı $[1\;2\;1]^T$'nin birleşimi olarak gösterildi. $[1\;2\;1]$ çok basitleşmiş bir Gauss gibi düşünülebilir.
  - $x$ ve $y$ yönündeki türevler $d_x$, $d_y$ bir türev vektörünün bileşenleridir. Büyüklük $\sqrt{d_x^2+d_y^2}$, yön ise vektörün $x$ ekseniyle yaptığı açıdır.
- Canny kenar bulucusu (ekrandan, 00:45:00)
  - 1) İmgeyi Gauss'un $x$, $y$ türevleriyle filtrele. 2) Gradyanın büyüklüğünü ve yönünü bul. 3) Maksimum olmayanları bastır (non-maximum suppression): birkaç piksel genişliğindeki kenar sırtlarını tek piksele indir. 4) Eşikleme ve bağlama (histerezis): iki eşik tanımla, kenar eğrilerini başlatmak için yüksek, sürdürmek için alçak eşiği kullan.
  - MATLAB'da `edge(image, 'canny')` ile hazır kullanılır.
- İlgi noktaları (interest points) ve eşleme
  - Amaç farklı açılardan ya da farklı imgelerde görünen aynı şeyleri eşleyebilmek: iki görünüm arasındaki dönüşümü bulmak, panorama birleştirme, birden çok fotoğraftan üç boyutlu model çıkarma.
  - İlgi noktasına özellik noktası (feature point), anahtar nokta (keypoint) ya da yalnız özellik de denir. İmge biraz döndürülse, küçültülse, perspektif olarak bozulsa da kolayca yeniden bulunabilen noktalardır.
  - Anahtar nokta eşleme (ekrandan, 01:10:00): 1) ayırt edici anahtar noktaları bul, 2) her noktanın çevresinde bir bölge tanımla, 3) normalize edilmiş bölgeden yerel bir tanımlayıcı (descriptor) hesapla. Sonra tanımlayıcılar karşılaştırılarak eşleme yapılır.
  - İyi özelliklerin nitelikleri: tekrarlanabilirlik (repeatability), ayırt edicilik (saliency), az sayıda olma (compactness/efficiency), küçük bir alanı temsil etme (locality, örtüşmeye/occlusion dayanıklılık).
  - Bulucular (detector): Harris, Hessian, Harris-Laplace, Hessian-Laplace, Harris-Affine, Hessian-Affine, MSER. Her bulucu farklı bölge tipi bulur (Harris köşe, Hessian blob).
- Harris köşe bulucusu
  - Fikir (ekrandan, 01:20:00): nokta küçük bir pencereden bakınca kolayca tanınabilmeli, pencere herhangi bir yöne kaydırılınca parlaklık çok değişmeli. Düz bölgede hiçbir yönde, kenarda yalnız bir yönde, köşede her yönde büyük değişim olur.
  - Pencere görünüşündeki değişim (ekrandan, 01:25:00): $E(u,v)=\sum_{x,y} w(x,y)\,[I(x+u,y+v)-I(x,y)]^2$. $w$ pencere fonksiyonudur (Gauss ya da kutu filtresi).
  - Bunu her piksel ve her kayma için doğrudan hesaplamak pahalıdır ($600\times600$ imge, $11\times11$ pencere, $11\times11$ kayma için yaklaşık 5 milyar işlem). Bu yüzden ikinci dereceden Taylor açılımı kullanılır.
  - Taylor açılımı (ekrandan, 01:35:00): $E(u,v)\approx E(0,0)+[u\;v]\begin{bmatrix}E_u\\E_v\end{bmatrix}+\tfrac12[u\;v]\begin{bmatrix}E_{uu}&E_{uv}\\E_{uv}&E_{vv}\end{bmatrix}\begin{bmatrix}u\\v\end{bmatrix}$. $E(0,0)$ her zaman 0, birinci türev de $(0,0)$'da 0'dır (ekrandan, 01:40:00).
  - Sonuç (ekrandan, 01:45:00): $E(u,v)\approx[u\;v]\,M\begin{bmatrix}u\\v\end{bmatrix}$, $M=\sum_{x,y} w(x,y)\begin{bmatrix}I_x^2&I_xI_y\\I_xI_y&I_y^2\end{bmatrix}=\sum \nabla I(\nabla I)^T$ (ekrandan, 02:05:00). $M$'ye ikinci moment matrisi (second moment matrix) denir.
- İkinci moment matrisinin yorumu
  - $[u\;v]\,M\,[u\;v]^T=\text{sabit}$ bir elips denklemidir (ekrandan, 02:10:00). Her sabit için yüzeyin yatay bir kesiti, yani bir elips elde edilir.
  - Özdeğer ayrışımı: simetrik bir matris $U\Lambda U^T$ biçiminde yazılır. Özvektörler elipsin eksen yönlerini, özdeğerler büyüklüğünü verir; bir özvektör yönündeki yarı eksen $1/\sqrt{\lambda}$'dır.
  - Sınıflama: bir özdeğer diğerinden çok büyükse kenar; ikisi de küçük ve benzerse düz bölge; ikisi de büyük ve benzerse köşe.
- Köşe cevap fonksiyonu (corner response function) (ekrandan, 02:30:00)
  - $R=\det(M)-\alpha\,\mathrm{trace}(M)^2=\lambda_1\lambda_2-\alpha(\lambda_1+\lambda_2)^2$, $\alpha$ 0,04 ile 0,06 arasında bir sabit.
  - Kenarda $R<0$, düz bölgede $|R|$ küçük, köşede $R>0$ ve büyük.
  - Özdeğer hesaplamak pahalı olduğu için determinant ($ad-bc$) ve iz ($a+d$) kullanılır.
- Harris algoritması (ekrandan, 02:35:00)
  - 1) Her pencere için $M$'yi hesapla, köşelik puanını bul. 2) Köşe cevabı eşikten büyük olan noktaları al. 3) Yerel maksimumları al, yani non-maximum suppression uygula.
  - Kaynak: C. Harris ve M. Stephens, "A Combined Corner and Edge Detector", Proceedings of the 4th Alvey Vision Conference, s. 147-151, 1988.

## Hocanın Özellikle Vurguladığı Kısımlar

- NumPy ile döngüsüz programlama
  - Filtre ve matris işlemleri iç içe döngüyle değil, `mgrid`, vektörel çarpım gibi NumPy imkânlarıyla yapılmalı. Bu tarz programlamaya alışmak hedefleniyor.
- Taylor serisi
  - Bir noktadaki değeri ve türevleri bilinen fonksiyonun hemen yakınındaki değeri tahmin edilir. Pratikte genelde birinci ya da ikinci türeve kadar gidilir. Optimizasyonda da çok kullanılır.
- İkinci moment matrisi önemli bir matristir
  - Farklı yöntemlerde karşınıza çıkar. Her piksel için bir elips, yani bir bölge tanımlar.
- Özdeğer ve özvektör
  - Görüntü işlemede ve PCA'da sıkça karşımıza çıkar. Nasıl hesaplandığından çok ne anlama geldiği ve nasıl kullanıldığı önemlidir.
- Non-maximum suppression
  - Komşuluğunda en büyük olan piksel ("kendi komşuluğunda kral olan") tutulur, diğerleri atılır. Komşuluk $3\times3$, $5\times5$ gibi uygulamaya göre seçilir.

## Kısa Tekrar Notları

- Kenar = büyük parlaklık değişimi; kenar bulma = türev operatörü uygulamak.
- Sobel: türev ($[1\;-1]$) + yumuşatma ($[1\;2\;1]$). Büyüklük $\sqrt{d_x^2+d_y^2}$, yön $\theta$.
- Canny: Gauss türevi, büyüklük/yön, NMS ile inceltme, histerezis (yüksek eşik başlatır, alçak eşik sürdürür).
- İyi özellik: tekrarlanabilir, ayırt edici, az sayıda, yerel.
- Eşleme: anahtar nokta bul, bölge tanımla, tanımlayıcı çıkar, karşılaştır.
- Harris: $E(u,v)\approx[u\;v]M[u\;v]^T$, $M=\sum w\begin{bmatrix}I_x^2&I_xI_y\\I_xI_y&I_y^2\end{bmatrix}$.
- Özdeğerler: ikisi büyük = köşe, biri büyük = kenar, ikisi küçük = düz.
- $R=\det M-\alpha(\mathrm{trace}\,M)^2$, $\alpha\approx0{,}04$-$0{,}06$.
- Harris adımları: $M$ hesapla, $R$ eşikle, NMS uygula.
- Harris köşeleri ışık, dönme ve küçük bakış açısı değişimlerinde büyük ölçüde yeniden bulunabilir.

## Detaylı Açıklamalar

- Kenar bulmanın temeli türevdir. İmgede $x$ yönündeki en küçük adım bir piksel olduğundan, bir piksel ilerleyince parlaklığın ne kadar değiştiğini veren her işlem bir kenar bulucudur. Sobel bulucusu bu türevi küçük bir yumuşatmayla birleştirir: $[1\;-1]$ türevi alır, $[1\;2\;1]$ ise gürültüyü azaltan kaba bir Gauss gibi çalışır. $x$ ve $y$ yönündeki iki sonuç bir vektörün bileşenleri olarak düşünülür; vektörün büyüklüğü o pikseldeki kenarın gücünü, açısı kenarın yönünü verir.
  > **Ders sonrası not:** Hoca Sobel'i tahtada $[1\;2\;1]^T$ ile $[1\;-1]$'in birleşimi olarak, yani $3\times2$ bir matris olarak yazdı (ekrandan, 00:40:00). Literatürdeki standart Sobel çekirdeği büyük olasılıkla merkez farkı kullanan $3\times3$ biçimdir: $\begin{bmatrix}1&0&-1\\2&0&-2\\1&0&-1\end{bmatrix}=[1\;2\;1]^T[1\;0\;-1]$. Hoca derste ikinci moment matrisini anlatırken $x$ türevi için $[+1\;0\;-1]$'i de kullandı.
- Canny, Sobel'in verdiği büyüklük ve yön bilgisini daha akıllıca kullanır. Türevler alındıktan sonra kenarlar birkaç piksel genişliğinde çıkar; non-maximum suppression her küçük komşulukta yalnız en büyük büyüklüğü tutarak kenarı tek piksel genişliğe indirir. Hocanın örneğinde bir satırdaki $5, 60, 8$ üçlüsünden yalnız 60, alttaki $5, 10, 3$ üçlüsünden yalnız 10 kalır. Son adımda histerezis eşiklemesi yapılır: tek bir eşikle kenarı kesmek yerine, yüksek eşiği geçen yerden bir kenar eğrisi başlatılır ve eğri alçak eşiğin üstünde kaldığı sürece sürdürülür. Böylece kenarın zayıfladığı yerlerde kopmalar azalır (ekrandan, 00:50:00).
- İlgi noktaları farklı imgeler arasında karşılık kurmanın temel aracıdır. Bir stop levhasının iki farklı fotoğrafındaki "TO" harfleri birbirine çok benzer (ekrandan, 01:05:00); bu tür benzer küçük bölgeleri bulup eşleyerek iki imge arasındaki dönüşüm, panorama ya da üç boyutlu yapı çıkarılabilir. İki imgede binlerce nokta çıkabileceği için rastgele noktalar yerine iyi noktalar seçmek gerekir. Kalitesiz, bir imgede olup diğerinde olmayan noktalar yanlış karşılık hipotezleri üretir.
- Harris bulucusunun matematiği bir pencerenin $(u,v)$ kadar kaydırılmasıyla görünüşündeki değişimi ölçen $E(u,v)$ ile başlar. Bu fonksiyon küçük kaymalar için ikinci dereceden Taylor açılımıyla yaklaşık hesaplanır. $(0,0)$ noktasında kayma olmadığı için fark sıfırdır; bu nedenle $E(0,0)=0$ ve birinci türevler de sıfırdır, çünkü türev ifadesinde $I(x+u,y+v)-I(x,y)$ farkı çarpan olarak bulunur. İkinci türevlerde ise sıfıra gitmeyen $I_x^2$, $I_xI_y$, $I_y^2$ terimleri kalır ve $\tfrac12$ çarpanı türevdeki 2 ile sadeleşir. Böylece $E(u,v)\approx[u\;v]M[u\;v]^T$ elde edilir.
- $M$'nin bileşenleri bütün imge için hızlıca hesaplanabilir: imge $[+1\;0\;-1]$ ile konvolüsyona sokularak $I_x$, bunun transpozuyla $I_y$ bulunur; bunlar eleman eleman çarpılarak $I_x^2$, $I_y^2$, $I_xI_y$ "imgeleri" elde edilir ve üzerlerinde bir Gauss gezdirilir. Hoca, slayttaki örnekte $I_y$ imgesinde yatay yapıların, $I_xI_y$ imgesinde ise çaprazların öne çıktığını gösterdi.
- $[u\;v]M[u\;v]^T=\text{sabit}$ bir elipstir. Düz bölgelerde elipsler küçük, bazı yerlerde daireye yakın, bazı yerlerde uzamış çıkar. Özvektörler elipsin eksen yönlerini, özdeğerler büyüklüğünü verir ve bu eksenler ileride bir bölgeyi standart yöne çevirmek için kullanılabilir. Harris, özdeğerlere göre pikselleri kenar, düz bölge ve köşe olarak sınıflar; ancak her pikselde özdeğer hesaplamak pahalı olduğundan $\det(M)=\lambda_1\lambda_2$ ve $\mathrm{trace}(M)=\lambda_1+\lambda_2$ üzerinden kurulan $R$ fonksiyonu kullanılır.
- Harris'in orijinal makalesindeki örnekte (ekrandan, 02:40:00) iki imge arasında ışıklandırma farkı, dönme ve bakış açısı farkı vardır. Buna rağmen birçok köşe iki imgede de bulunur, bazıları ise bakış açısı yüzünden kaybolur. Dönüşümden sonra köşelerin yeri değişmiyorsa değişmezlik (invariance), dönüşümle birlikte karşılık gelen yerlerde yine bulunuyorsa eşdeğişkenlik (covariance) söz konusudur; Harris köşeleri bu bakımdan oldukça iyidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
