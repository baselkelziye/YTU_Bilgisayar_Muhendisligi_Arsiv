# Ders 9 Çalışma Özeti

## Genel Konular

- İmge dönüşümlerinin özeti ve öteleme (translation) örneği
  - Öteleme dönüşümü $[I \mid t]$ biçiminde yazılır: birim matrisin yanına öteleme vektörü eklenir. Döndürme, benzerlik, afin ve projektif dönüşümler de aynı tabloda özetlenir; projektif dönüşüm $3\times 3$ bir $H$ matrisiyle ve 8 serbestlik derecesiyle verilir, düz çizgileri korur (ekrandan, 00:15:00).
  - Eşleşmiş nokta kümeleri $\{A\}$ ve $\{B\}$ verildiğinde aradaki ötelemeyi bulmak: her eşleşme $x_i^B = x_i^A + t_x$, $y_i^B = y_i^A + t_y$ denklemlerini verir (ekrandan, 00:10:00).
- En küçük kareler çözümü ve sözde ters (pseudo-inverse)
  - $n$ eşleşme $2n$ denklem verir; bunlar $Ax=b$ biçiminde yazılır. $A$ kare olmadığı için tersi alınamaz.
  - Her iki taraf soldan $A^T$ ile çarpılır, $A^TA$ kare olduğundan tersi alınır: $x = (A^TA)^{-1}A^Tb$. Özdeğer ayrışımıyla da çözülebilir.
- Hough dönüşümü ve RANSAC ile öteleme bulma
  - Hough: $(t_x, t_y)$ için bir parametre ızgarası kurulur, her eşleşen çift tutarlı değere oy verir, en çok oy alan parametre seçilir, sonra iç noktalarla (inlier) en küçük kareler çözülür (ekrandan, 00:25:00).
  - RANSAC: ötelemeyi bulmak için en az bir nokta yeter. Bir noktadan $(t_x, t_y)$ bulunur, bir eşik içinde bu ötelemeye uyan noktalar sayılır, bu tekrarlanır.
  - Eşleşmiş çift yoksa Hough ve RANSAC uygulanamaz; tıbbi görüntülerde beyin taramalarını ya da robotikte nokta bulutlarını eşleme bu duruma örnektir (ekrandan, 00:20:00).
- Gözetimli öğrenme (supervised learning)
  - Eğitim verisi $\{(x^i, y^i),\ i = 1 \ldots P\}$: $x^i$ $i$. girdi, $y^i$ $i$. hedef etiket, $P$ eğitim örneği sayısı. Amaç, görülmemiş girdilerin etiketini tahmin etmek (ekrandan, 00:35:00).
  - Etiket eğitimde veriliyorsa gözetimli, verilmiyorsa gözetimsiz öğrenme denir.
  - Örnekler: sınıflama (resimdeki köpek), gürültü giderme (regresyon), OCR (yapılandırılmış tahmin) (ekrandan, 00:40:00).
- Yapay sinir ağları ve ileri yayılım
  - Örnek ağ: $h^1 = \max(0, W^1x)$, $h^2 = \max(0, W^2h^1)$, $o = W^3h^2$. İki gizli katmanlı ağ ya da girdi ve çıktı sayılırsa dört katmanlı ağ (ekrandan, 01:05:00).
  - Boyutlar: $x \in \mathbb{R}^D$, $W^1 \in \mathbb{R}^{N_1 \times D}$, $b^1 \in \mathbb{R}^{N_1}$, $h^1 \in \mathbb{R}^{N_1}$; $h^1 = \max(0, W^1x + b^1)$ (ekrandan, 01:25:00).
  - Bias, doğru denklemi $y = mx + b$'deki $b$ gibi fonksiyonu kaydırır.
  - Her çıktı biriminin bütün girdileri kullanması tam bağlı (fully connected) katman demektir.
- Aktivasyon fonksiyonları ve doğrusal olmama
  - ReLU: $f(x) = \max(0, x)$; türevi $x<0$ için 0, $x>0$ için 1 (ekrandan, 01:20:00).
  - Sigmoid çıktıyı $(0,1)$ aralığına, tanh $(-1,1)$ aralığına taşır; ReLU'nun negatif tarafta küçük eğimli ve köşesi yumuşatılmış türevleri vardır.
  - Doğrusal fonksiyonların bileşkesi doğrusaldır; XOR gibi doğrusal ayrılamayan veriyi ayırmak için doğrusal olmayan aktivasyon gerekir.
- Derinliğin yorumu
  - Alt katmanlar düşük düzey (gradyan, kenar), orta katmanlar orta düzey (eğri, parça), üst katmanlar yüksek düzey parçaları (araba, bisiklet) temsil eder; dağıtık temsil, öznitelik paylaşımı ve bileşimsellik (ekrandan, 01:40:00).
  - Gizli birim bir sınıflayıcı ya da öznitelik bulucu olarak düşünülebilir; derin öğrenme öznitelik tasarımını da kendisi öğrenir (SIFT gibi elle tasarlanmış özniteliklerin yerine).
  - Katman ve birim sayısı çapraz doğrulama ya da hiperparametre araması ile seçilir (ekrandan, 01:45:00).
- Eğitim, doğrulama ve test kümeleri
  - Test kümesi eğitimde asla kullanılmaz. Doğrulama kümesi model seçimi ya da eğitimin ne zaman durdurulacağına karar vermek için kullanılır.
- Kayıp fonksiyonu
  - Etiket tek sıcak (one-hot) vektördür: $y = [0\,0 \ldots 0\,1\,0 \ldots 0]$, $k$. sınıf 1.
  - Softmax: $p(c_k = 1 \mid x) = \dfrac{e^{o_k}}{\sum_{j=1}^{C} e^{o_j}}$ (ekrandan, 02:10:00).
  - Negatif log-olabilirlik: $L(x, y; \theta) = -\sum_j y_j \log p(c_j \mid x)$; az sayıda sınıflı sınıflamada iyi çalışır.
- Eğitim ve gradyan inişi
  - $\theta = [W^1, b^1, W^2, b^2, \ldots]$; $\theta^* = \arg\min_\theta \sum_{n=1}^{P} L(x^n, y^n; \theta)$ (ekrandan, 02:30:00).
  - Gradyan inişi: $\theta_j^{(i+1)} = \theta_j^{(i)} - \alpha \dfrac{\partial f}{\partial \theta_j}\Big|_{\theta^{(i)}}$.
  - Toplu (batch), stokastik ve mini-toplu gradyan inişi, güncellemede kullanılan örnek sayısıyla ayrılır.
- Geri yayılım (backpropagation)
  - $\dfrac{\partial L}{\partial o} = p(c \mid x) - y$ (ekrandan, 02:45:00).
  - Zincir kuralı: $\dfrac{\partial L}{\partial W^3} = \dfrac{\partial L}{\partial o}\dfrac{\partial o}{\partial W^3}$, $\dfrac{\partial L}{\partial h^2} = \dfrac{\partial L}{\partial o}\dfrac{\partial o}{\partial h^2}$; $\dfrac{\partial L}{\partial W^2} = \dfrac{\partial L}{\partial h^2}\dfrac{\partial h^2}{\partial W^2}$, $\dfrac{\partial L}{\partial h^1} = \dfrac{\partial L}{\partial h^2}\dfrac{\partial h^2}{\partial h^1}$ (ekrandan, 02:50:00 ve 02:55:00).
  - Vektörün vektöre göre türevi Jacobian matrisidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- $Ax=b$ biçimine getirip sözde tersle çözmek
  - Hoca bunu sınavlarda standart olarak sorduğu konulardan biri olarak andı: birkaç denklem verilir, $Ax=b$ biçimine getirilip çözülmesi istenir.
- Canny kenar bulucusu
  - Derste anlatılmadı, ama hoca bilinmesi gerektiğini ve öğrencilerin kendilerinin araştırmasını söyledi.
- Doğrusal olmayan aktivasyonun gerekliliği
  - Doğrusal katmanların bileşkesi yine doğrusal olduğundan ağ tek katmanlı bir modele indirgenir; XOR örneği bunun için verildi.
- Eğitim ve test verisinin ayrılması
  - Modeli eğitildiği veriyle test etmek "son derece hatalı"dır; model gerçek hayatta görmediği verilerle karşılaşacaktır.
- Negatif log-olabilirliğin davranışı
  - Doğru sınıfın olasılığı 1'e yakınsa kayıp küçüktür, 0'a yakınsa kayıp çok büyür.
- Türev her şeyin temelidir
  - Hemen bütün optimizasyon yöntemleri (SGD, Adam vb.) türev ister; türev geri yayılımla elde edilir.
- Kaynak önerisi
  - Sinir ağlarıyla ciddi çalışacaklar için Goodfellow ve Bengio'nun "Deep Learning" kitabı ile Stanford CS231n ders notları önerildi.

## Kısa Tekrar Notları

- Öteleme: $[I \mid t]$; her eşleşme 2 denklem verir, bilinmeyenler $t_x, t_y$.
- Fazla denklem varsa en küçük kareler: $x = (A^TA)^{-1}A^Tb$.
- Hough: parametre ızgarası, oy, yumuşatma, en büyük olmayanı bastırma, en çok oy.
- RANSAC: en az örnekle model, eşik içindeki iç noktaları say, tekrarla.
- Eşleşmiş çift yoksa Hough ve RANSAC uygulanamaz.
- Gözetimli öğrenme: etiketli $(x^i, y^i)$ ile görülmemiş girdinin etiketini tahmin.
- Sınıflama ayrık etiket, regresyon sayı tahmini.
- Katman: $h = a(Wx + b)$; $a$ doğrusal olmayan aktivasyon.
- ReLU $=\max(0,x)$, türevi 0 ya da 1.
- Doğrusal katmanlar üst üste konunca yine doğrusal: aktivasyon şart.
- Derin ağ: hiyerarşik öznitelikler (düşük, orta, yüksek düzey).
- Veri: eğitim, doğrulama, test; doğrulama model seçimi ve erken durdurma için.
- Softmax çıktıları olasılığa çevirir, toplamı 1'dir.
- NLL kaybı: $-\sum_j y_j \log p_j$.
- Öğrenme: toplam kaybı $\theta$'ya göre en aza indirmek.
- SGD: her örnekten sonra; toplu: bütün veriden sonra; mini-toplu: arada (genelde 32, 64 gibi 2'nin kuvvetleri).
- $\partial L/\partial o = p - y$; zincir kuralıyla geriye doğru türevler.
- Geri yayılımın maliyeti ileri hesaplamanın yaklaşık iki katı.

## Detaylı Açıklamalar

- **Ötelemenin en küçük karelerle bulunması.** İki imgede SIFT gibi tanımlayıcılarla eşleştirilmiş $A_i$ ve $B_i$ noktaları olsun. Yalnız öteleme varsa her eşleşme $x_i^B - x_i^A = t_x$ ve $y_i^B - y_i^A = t_y$ denklemlerini verir. İki bilinmeyen için iki denklem (yani tek eşleşme) yeterlidir, ama elde çok sayıda eşleşme vardır. Bütün denklemler alt alta yazılınca katsayı matrisi her nokta için $\begin{bmatrix}1&0\\0&1\end{bmatrix}$ bloklarından oluşan $2n\times 2$ bir $A$, sağ taraf da farkların vektörü $b$ olur (ekrandan, 00:10:00). $A$ kare olmadığından $A^{-1}$ yoktur; soldan $A^T$ ile çarpınca $A^TAx = A^Tb$ elde edilir, $A^TA$ kare ve terslenebilir olduğundan $x = (A^TA)^{-1}A^Tb$ bulunur. Bu ifadeye sözde ters denir.
- **Hough ve RANSAC.** Eşleşmelerin bir kısmı yanlış (aykırı) olabilir, birden çok nesne ya da çoktan bire eşleşmeler olabilir. Hough çözümünde $(t_x, t_y)$ düzlemi imge boyutlarıyla sınırlı bir ızgaraya bölünür; her eşleşmenin verdiği öteleme bir oy olarak biriktirilir, ardından yumuşatma ve en büyük olmayanı bastırma ile en çok oy alan hücre bulunur. Hoca buna genelleştirilmiş Hough dönüşümü dedi. RANSAC'ta tek bir eşleşmeden öteleme hesaplanır, eşik içinde bu ötelemeye uyan eşleşme sayısı kaydedilir, işlem başka eşleşmelerle tekrarlanır. Aynı mantık ölçekleme, döndürme ve projektif dönüşümlere de uygulanır.
- **Sinir ağının yapısı.** Ağ, basit fonksiyonların arka arkaya uygulanmasıdır. İlk katmanda girdi vektörü ağırlık matrisiyle çarpılır, bias eklenir ve sonuç aktivasyondan geçirilir. Katman boyutu $W$ ve $b$'nin boyutuyla ayarlanır; örneğin 800 girdi 600, 400, 100 gibi adım adım küçültülebilir. Çıkış katmanının boyutu problemin gerektirdiği değer sayısına göre seçilir. Bias istenirse $x$'in sonuna 1 eklenip $b$, $W$'nin son sütunu yapılarak tek bir çarpıma katılabilir.
- **Neden doğrusal olmayan aktivasyon?** XOR örneğinde $(0,0)$ ve $(1,1)$ noktaları 0, $(1,0)$ ve $(0,1)$ noktaları 1 sınıfındadır (ekrandan, 01:10:00). Hiçbir tek doğru bu iki sınıfı ayıramaz. Matris çarpımları doğrusal olduğundan ve doğrusal fonksiyonların bileşkesi doğrusal kaldığından, aktivasyon olmadan ağ ne kadar derin olursa olsun tek doğrusal bir model olur. ReLU parça parça doğrusaldır: yerelde doğrusal, genelde doğrusal olmayan bir eşleme verir ve birçok küçük doğrusal ayırıcının birlikte kullanılmasını sağlar.
- **Kayıp ve softmax.** Ağın çıktısı (ör. 0,3; 0,5 gibi değerler) softmax ile olasılığa çevrilir. Negatif log-olabilirlikte $y_j$ yalnız doğru sınıf için 1 olduğundan toplamda yalnız doğru sınıfın terimi kalır. Doğru sınıf olasılığı 0,9 ise kayıp $-\ln 0{,}9 \approx 0{,}105$, 0,1 ise $-\ln 0{,}1 \approx 2{,}303$ olur (değerler python ile hesaplandı).
- **Gradyan inişi ve türleri.** Gradyan, fonksiyonun en hızlı arttığı yönü gösterir; negatif gradyan yönünde adım atılarak kayıp azaltılır. Bütün eğitim verisi ile yapılan güncelleme toplu, her örnekten sonra yapılan stokastik, küçük gruplarla yapılan mini-toplu gradyan inişidir. Verinin üzerinden bir kez geçmeye epoch denir. Derin öğrenmede adım büyüklüğü genelde sabit ya da iterasyonla azalan bir değer olarak seçilir; momentum (ör. 0,9) gibi birçok varyant vardır.
- **Geri yayılım.** Önce $\partial L/\partial o = p(c\mid x) - y$ bulunur. Sonra zincir kuralıyla $\partial L/\partial W^3$ ve $\partial L/\partial h^2$; bunlar kullanılarak $\partial L/\partial W^2$ ve $\partial L/\partial h^1$; en son $\partial L/\partial W^1$ hesaplanır. Önceki adımda bulunan türev bir sonraki adımda yeniden kullanılır. Böylece bütün $W$ ve $b$ elemanları için türev elde edilir ve gradyan inişiyle güncellenir. ReLU dışındaki aktivasyonlarla da çalışır; yalnız türev ifadeleri değişir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
