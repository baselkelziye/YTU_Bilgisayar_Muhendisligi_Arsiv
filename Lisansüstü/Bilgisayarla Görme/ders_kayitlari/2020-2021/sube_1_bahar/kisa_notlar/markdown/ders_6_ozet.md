# Ders 6 Çalışma Özeti

## Genel Konular

- Laplacian of Gaussian (LoG) çıktısında sıfır geçişi (zero crossing)
  - İkinci türev, bir kenarın (ani basamak ya da rampa geçişinin) olduğu bölgede negatiften pozitife ya da pozitiften negatife geçer. Bu işaret değişimine sıfır geçişi denir.
  - Görüntü LoG filtresiyle konvolüsyona sokulur, çıktıya sıfır geçişi işlemi uygulanır; işaret değiştiren pikseller kenar olarak işaretlenir ve ikili (binary) kenar görüntüsü elde edilir.
  - Farklı $\sigma$ değerleri için hesaplanan LoG katsayıları tamsayı çıkmaz. Katsayılar toplamı 1 (ya da çok küçük kalıyorsa 100) olacak biçimde normalize edilip yuvarlanabilir. Katsayıların çizdirilen şekli derste görülen şekle benziyorsa değerlerin birebir aynı olması gerekmez.
- Hough dönüşümü (Hough Transform)
  - Hough dönüşümü kenar bulmadan (edge detection) sonra, ikili kenar görüntüsü üzerinde uygulanır. Amaç kenar noktalarının bir doğru, çember, parabol ya da elips oluşturup oluşturmadığını bulmak ve bu şeklin parametrelerini çıkarmaktır (ekrandan, 00:25:00).
  - Konu başlıkları: Hough dönüşümünün üstünlükleri, doğru bulma, çember bulma ve integro-diferansiyel operatör. Daha genel biçimi Genelleştirilmiş Hough Dönüşümü (Generalized Hough Transform) adını alır.
  - Üstünlükleri: kenardaki boşluklara (kopukluklara) dayanıklıdır, gürültüden görece az etkilenir, görüntüdeki örtülmeden (occlusion) etkilenmez (ekrandan, 00:30:00).
  - Sakıncası: her kenar noktası için yüzlerce olası doğru ya da çember denendiği için işlem yükü yüksektir, yöntem yavaştır.
- Hesse normal formu ile doğru gösterimi
  - $y = mx + c$ gösterimi dikey doğrular için çalışmaz. Bunun yerine Hesse normal formu kullanılır: $x\cos\theta + y\sin\theta = r$ (ekrandan, 00:45:00).
  - $r$ (ya da $\rho$, $p$) doğruya orijinden çizilen dikmenin uzunluğu, $\theta$ bu dikmenin yatay eksenle yaptığı açıdır. Doğru üzerindeki her nokta için $r$ ve $\theta$ aynıdır.
  - Türetme: doğru x eksenini $A$, y eksenini $B$ noktasında kessin. $OLA$ üçgeninde $\cos\alpha = p/OA$, $OLB$ üçgeninde $\sin\alpha = p/OB$ olur. Eksen kesişimli doğru denklemi $\frac{x}{OA} + \frac{y}{OB} = 1$ içine yazılınca $x\cos\alpha + y\sin\alpha = p$ elde edilir (ekrandan, 00:40:00).
- Akümülatör matrisi ve oylama
  - Hough uzayı $(\theta, \rho)$ düzlemidir. Her kenar noktasından her yönde doğrular geçirilir; her doğrunun $(\theta, \rho)$ değeri akümülatör matrisinde ilgili göze bir oy olarak eklenir.
  - Aynı doğru üzerindeki noktaların Hough uzayındaki eğrileri tek bir noktada kesişir. En çok oyu toplayan göz aranan doğrunun parametrelerini verir (ekrandan, 00:50:00).
  - Parametreler sınırlıdır: $\theta$ 0° ile 180° arasındadır; $\rho$ en fazla görüntünün köşegen uzunluğu kadar olabilir.
  - Algoritma: Hough uzayını nicemle (θ aralığını istenen hassasiyette böl, ρ için köşegeni üst sınır al), akümülatörü oluştur, oyları topla, en büyük değerli gözü seç.
- Hough ile çember bulma
  - Çember denklemi $(x-a)^2 + (y-b)^2 = r^2$; üç parametre ($a$, $b$, $r$) olduğu için akümülatör üç boyutludur.
  - Canny kenar bulucuyla elde edilen ikili görüntüdeki bütün çemberlerin merkezi ve yarıçapı bu yolla bulunabilir.
  - Python'da `skimage.transform.hough_circle` hazır fonksiyonu vardır (ekrandan, 01:05:00).
- Daugman'ın integro-diferansiyel operatörü (DIO)
  - Göz görüntüsünde irisi ve göz bebeğini çevreleyen çemberleri (ve göz kapaklarının yaylarını) bulmak için kullanılır; Hough dönüşümünün bir başka biçimi olarak görülebilir (ekrandan, 01:30:00).
  - Formül: $\max_{(r, x_0, y_0)} \left| G_\sigma(r) * \frac{\partial}{\partial r} \oint_{r, x_0, y_0} \frac{I(x,y)}{2\pi r}\, ds \right|$.
  - $I(x,y)$ göz görüntüsü, $r$ yarıçap, $G_\sigma(r)$ Gauss yumuşatma fonksiyonu, $s$ çemberin çevresidir.
- İki boyutlu dönüşümler ve eşleştirme (2D Transformations for Matching)
  - Ölçekleme, döndürme, öteleme ve bükme (warping) dönüşümleri, bir model ile görüntü ya da iki görüntü arasında karşılık gelen noktaları (correspondence) eşleştirmek için kullanılır.
  - Homojen koordinatlar: $P = [x, y]^t$ noktası $[sx, sy, s]^t$ biçiminde yazılır; ölçek çarpanı $s$ genelde 1 alınır (ekrandan, 02:10:00).
  - Döndürme matrisi: $R_\theta = \begin{bmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{bmatrix}$ (ekrandan, 02:20:00).
  - Öteleme matrisi: $D_{x_0,y_0} = \begin{bmatrix} 1 & 0 & x_0 \\ 0 & 1 & y_0 \\ 0 & 0 & 1 \end{bmatrix}$.
  - Bir nokta etrafında döndürme: önce merkezi orijine taşı, döndür, geri taşı: $D_{5,8}\,R_{\pi/2}\,D_{-5,-8}$ (ekrandan, 02:25:00).
  - Görüntü düzleminden dünya düzlemine dönüşüm: ${}^{w}P_j = D_{x_0,y_0}\,S_s\,R_\theta\,{}^{i}P_j$; dört bilinmeyen ($x_0, y_0, s, \theta$) iki kontrol noktasıyla bulunur (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Hough dönüşümü kenar bulmadan sonra gelir
  - Girdi, kenar bulma algoritmasından çıkmış ikili bir görüntüdür. Hough ancak bu kenar noktaları üzerinde çalışır.
- Hesse normal formunun neden gerektiği
  - $y = mx + c$ dikey doğruda çöker; $(\theta, \rho)$ gösterimi hem her doğruyu gösterebilir hem de sınırlı bir parametre uzayı verir.
- Akümülatörde en çok oyu alan göz
  - Aynı doğru üzerindeki noktaların hepsi aynı $(\theta, \rho)$ gözüne oy verir; sonuç bu gözdeki tepe değerdir.
- Klasik algoritmaların önemi
  - Derin öğrenme bölümüne geçmeden önce klasik algoritmalar (Hough, köşe bulma, HOG gibi öznitelik çıkarma) ileride işe yarayacak düşünme biçimini kazandırır.
- DIO'daki türevin anlamı
  - Aynı merkezde $r$, $r+1$, $r+2$ yarıçaplı çemberler üzerindeki toplamların farkı alınır. Bu farkın en büyük olduğu yerde iris ile göz akı arasındaki sınır vardır.
- Aranan uzayı küçültmek
  - Merkezi görüntünün tamamında değil, görüntü 3×3 parçaya bölündüğünde ortadaki bölgede aramak ve yarıçapı belli bir aralıkta tutmak algoritmayı çok hızlandırır.
- Hazır kodu kullanırken her satırı anlamak
  - İnternetteki hazır çözümlerden esinlenilebilir ama kodun her satırının ne yaptığı, hangi matrisin kaç boyutlu olduğu bilinmelidir.
- Bir nokta etrafında döndürmede sıra
  - Önce merkez orijine taşınır, sonra döndürülür, sonra geri taşınır. Dönüş yönü saatin tersidir.

## Kısa Tekrar Notları

- LoG çıktısında işaret değişimi = sıfır geçişi = kenar.
- Hough: kenar görüntüsü → parametre uzayında oylama → en çok oy alan göz → şeklin parametreleri.
- Doğru: $x\cos\theta + y\sin\theta = \rho$; $\theta \in [0°, 180°)$, $\rho \le$ köşegen.
- Çember: $(x-a)^2 + (y-b)^2 = r^2$; üç boyutlu akümülatör.
- Üstünlükler: boşluk, gürültü ve örtülmeye dayanıklı. Sakınca: yavaş.
- Wikipedia örneği: üç noktanın tablolarında 60° satırındaki uzaklıklar yaklaşık 80 ile birbirine en yakındır; doğru $\theta = 60°$, $\rho \approx 80$ gözünde bulunur.
- DIO: çember üzerindeki parlaklık ortalaması → $r$'ye göre türev → Gauss ile yumuşatma → $(r, x_0, y_0)$ üzerinde en büyük değer.
- Göz bebeği yarıçapı iris yarıçapının 0.1 ile 0.8 katı aralığında kabul edilir; iris yarıçapı için 50-120 piksel aralığı önerildi.
- Homojen koordinat: $[x, y, 1]^t$. Ölçekleme doğrusal bir dönüşümdür: $P(1,2)$ iki katına ölçeklenince $(2,4)$ olur.
- $(5,8)$ etrafında $\pi/2$ döndürme matrisi: $\begin{bmatrix} 0 & -1 & 13 \\ 1 & 0 & 3 \\ 0 & 0 & 1 \end{bmatrix}$; $(5,8) \to (5,8)$, $(6,8) \to (5,9)$, $(5,9) \to (4,8)$.
- İki düzlem arasındaki açı: $\theta = \theta_w - \theta_i$, her biri $\arctan(\Delta y / \Delta x)$ ile bulunur.

## Detaylı Açıklamalar

- **Sıfır geçişi ve LoG.** İlk ve ikinci türev konuşulurken görüldüğü gibi, bir kenar geçişinde ikinci türev bir tarafta negatif, öbür tarafta pozitif değer alır. LoG filtresi bir Gauss yumuşatmasıyla ikinci türevi birleştirir. Görüntü LoG ile konvolüsyona sokulduktan sonra çıktının işaret değiştirdiği yerler kenardır. Sıfır geçişini bulan hazır fonksiyonlarla bu noktalar ikili bir kenar görüntüsüne çevrilir. LoG maskesi farklı $\sigma$ değerleri için formülden üretildiğinde katsayılar ondalıklı çıkar; bunlar toplamları 1 ya da 100 olacak biçimde ölçeklenip yuvarlanabilir.

- **Hough dönüşümünün fikri.** Kenar bulma bize kenar noktalarını verir ama bu noktaların bir doğru ya da çember oluşturduğunu söylemez. Hough dönüşümü her kenar noktası için "bu noktadan geçebilecek bütün şekilleri" parametre uzayında oylar. Gerçek bir doğru üzerindeki noktalar aynı parametreye oy verdiği için o göz öne çıkar. Bu yüzden kenarda kopukluk olsa bile (noktaların bir kısmı eksik), birkaç gürültü noktası bulunsa bile ya da doğrunun bir kısmı başka bir nesne tarafından örtülse bile doğru bulunur: az sayıdaki eksik ya da fazla nokta tepe değeri değiştirmez.

- **Hesse normal formu.** Doğruya orijinden indirilen dikmenin boyu $p$, dikmenin x ekseniyle yaptığı açı $\alpha$ olsun. Doğru x eksenini $A$, y eksenini $B$ noktasında kessin; dikmenin ayağı $L$ olsun. $OLA$ dik üçgeninde $\cos\alpha = p/OA$, yani $OA = p/\cos\alpha$. $OLB$ üçgeninde $B$ köşesindeki açı $90° - \alpha$ olduğundan $O$'daki açı yine $\alpha$'dır ve $\sin\alpha = p/OB$, yani $OB = p/\sin\alpha$. Eksenleri $OA$ ve $OB$'de kesen doğrunun denklemi $\frac{x}{OA} + \frac{y}{OB} = 1$'dir. Yerine koyunca $\frac{x\cos\alpha}{p} + \frac{y\sin\alpha}{p} = 1$, yani $x\cos\alpha + y\sin\alpha = p$ çıkar. Slaytta bu $x\cos\theta + y\sin\theta = r$ diye yazılır.

- **Akümülatör ve Wikipedia örneği.** Slayttaki örnekte üç siyah nokta vardır ve her noktadan 0°, 30°, 60°, 90°, 120°, 150° açılarıyla doğrular geçirilir. Her doğru için $\rho = x\cos\theta + y\sin\theta$ hesaplanır (ekrandan, 00:55:00). Birinci noktanın tablosu 40, 69.6, 81.2, 70, 40.6, 0.4; ikincininki 57.1, 79.5, 80.5, 60, 23.4, −19.5; üçüncününki 74.6, 89.6, 80.6, 50, 6.0, −39.6'dır. 60° satırında üç değer de 80 dolayındadır. Grafikte üç eğri $\theta = 60°$, $\rho \approx 80$ noktasında kesişir ve bu nokta üç noktadan geçen pembe doğruyu verir (ekrandan, 01:00:00).

  > **Ders sonrası not:** Birinci noktanın tablosundan $x = 40$ ($\theta = 0°$) ve $y = 70$ ($\theta = 90°$) okunur. Bu değerlerle python ile hesaplanan 60° uzaklığı $40 \cdot 0.5 + 70 \cdot 0.866 \approx 80.6$'dır; slayttaki 81.2 büyük olasılıkla kaynak çizimdeki bir yuvarlama ya da yazım hatasıdır. Diğer bütün değerler hesapla uyuşmaktadır.

- **Çember için Hough.** Çemberde merkez $(a, b)$ ve yarıçap $r$ bilinmediği için akümülatör üç boyutludur. Her kenar noktası için, olası her $(a, b)$ merkezi ve aralıktaki her $r$ için oy verilir. Slayttaki kodda 100×100'lük boş bir ikili görüntüye merkezi (satır 25, sütun 35) ve yarıçapı 23 olan bir çember çizilir, `try_radii = np.arange(5, 50)` ile yarıçap aralığı verilir, `hough_circle` ile akümülatör hesaplanır ve `np.argmax` ile en büyük gözün indisleri bulunur (ekrandan, 01:05:00). Beklenen sonuç satır 25, sütun 35, yarıçap 23'tür.

- **Daugman'ın integro-diferansiyel operatörü.** Formülün en içindeki çevre integrali, $(x_0, y_0)$ merkezli $r$ yarıçaplı çember üzerindeki piksellerin parlaklıklarını toplar ve $2\pi r$ çevre uzunluğuna böler; yani çember üzerindeki ortalama parlaklığı verir. Sonra yarıçap birer birer artırılarak ardışık çemberlerin toplamları arasındaki fark alınır; $\partial/\partial r$ türevinin anlamı budur. İrisin içi koyu, göz akı açık olduğundan iris sınırında bu fark birden büyür. Farklar bir boyutlu bir Gauss maskesiyle yumuşatılır; böylece tek tük sıçramalar bastırılır. Sonuçta farkın en büyük olduğu $(r, x_0, y_0)$ üçlüsü irisi çevreleyen çemberi verir. Aynı işlem göz bebeği için de tekrarlanır; göz bebeği merkezi iris merkezinden birkaç piksel kayık olabilir.

- **Uygulamada dikkat edilecekler.** Bir uygulama örneği olarak UBIRIS.v1 iris veritabanı gösterildi: 241 göz için toplam 1877 gri seviyeli görüntü, iki ayrı oturumda toplanmış (ekrandan, 01:45:00). Merkez görüntünün yalnız orta bölgesinde aranır, iris yarıçapı 50-120 piksel aralığında, göz bebeği yarıçapı iris yarıçapının 0.1-0.8 katı aralığında aranır (ekrandan, 01:50:00). Göz bebeğinde flaştan gelen beyaz bir parlama varsa göz bebeği sınırı zor bulunur; bu bölge bir ön işlemle karartılmalıdır.

- **Homojen koordinatlar ve temel dönüşümler.** Eşleştirmede iki düzlem arasında ölçek farkı (ölçekleme), açı farkı (döndürme) ve konum farkı (öteleme) olabilir. Homojen koordinatlarda nokta $[x, y, 1]^t$ biçiminde yazılır; bu sayede öteleme de bir matris çarpımı olur. Döndürme matrisi birim vektörlerin döndürülmesinden çıkar: $(1,0)$ noktası $\theta$ kadar döndürülünce $(\cos\theta, \sin\theta)$'ya, $(0,1)$ noktası $(-\sin\theta, \cos\theta)$'ya gider. Bu iki vektör matrisin sütunlarıdır, böylece $x' = x\cos\theta - y\sin\theta$, $y' = x\sin\theta + y\cos\theta$ elde edilir.

- **Bir nokta etrafında döndürme örneği.** $(5,8)$ noktası etrafında $\pi/2$ döndürme matrisi $D_{5,8} R_{\pi/2} D_{-5,-8}$ çarpımıdır (ekrandan, 02:35:00). Çarpım $\begin{bmatrix} 0 & -1 & 13 \\ 1 & 0 & 3 \\ 0 & 0 & 1 \end{bmatrix}$ verir (ekrandan, 02:40:00; python ile doğrulandı). $A(5,8)$ merkez olduğu için yerinde kalır, $B(6,8)$ $(5,9)$'a, $C(5,9)$ $(4,8)$'e gider.

- **Görüntü düzleminden dünya düzlemine.** Bir kamera düz bir çalışma alanına dik bakıyorsa görüntüdeki nokta ${}^{w}P = D_{x_0,y_0} S_s R_\theta\, {}^{i}P$ ile dünya koordinatına çevrilir. Dört bilinmeyen için iki kontrol noktası yeterlidir. Örnekte ${}^{i}P_1 = [100, 60]$, ${}^{w}P_1 = [200, 100]$, ${}^{i}P_2 = [380, 120]$, ${}^{w}P_2 = [300, 200]$'dür. $\theta_i = \arctan(60/280) = 12.09°$, $\theta_w = \arctan(100/100) = 45°$, $\theta = \theta_w - \theta_i = 32.91°$ (ekrandan, 02:50:00; python ile doğrulandı). $\theta$ bulununca kalan üç denklemden $s$, $x_0$, $y_0$ çözülür. Bu yöntem, kamera görüntüsündeki bir konumu gerçek ölçekli oda düzlemindeki konuma çevirmek gibi kamera kalibrasyonu işlerinde kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
