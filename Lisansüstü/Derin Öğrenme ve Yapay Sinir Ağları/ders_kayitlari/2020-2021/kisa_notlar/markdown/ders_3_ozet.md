# Ders 3 Çalışma Özeti

## Genel Konular

- Perceptron, Adaline ve delta kuralının tekrarı
  - Hebb kuralı tek iterasyonda çalışır; girdiyle çıktının çarpımıyla ağırlığı günceller. İteratif çalıştırılırsa ağırlık kontrolsüz büyür, tek iterasyon ise öğrenme için yetmez.
  - Perceptron öğrenme kuralı hatadan öğrenir: hata oluştuysa $w_i(new) = w_i(old) + \eta t x_i$ ile güncellenir ($t$ hedef değer, $+1$ veya $-1$; $\eta$ öğrenme oranı). Hata yoksa ağırlık değişmez (ekrandan, 00:05:00).
  - Durma koşulu: hiç hata oluşmayana veya önceden belirlenen epoch sayısına ulaşılana kadar eğitim sürer (ekrandan, 00:05:00).
  - Adaline (Adaptive Linear Network), Widrow ve Hoff (1960); bipolar girdi ve hedefler kullanır, ağırlıklar delta kuralıyla güncellenir: $w_{ij}(new) = w_{ij}(old) + \eta(targ_j - out_j)x_i$ (ekrandan, 00:10:00).
  - Perceptron ve Adaline XOR gibi doğrusal ayrılamayan problemleri çözemez.
- Delta kuralının türetilmesi
  - Karesel hata: $E = \sum_{j=1}^{m}(t_j - y\_in_j)^2$, $y\_in = \sum_{i=1}^{n} x_i w_i$ (ekrandan, 00:15:00).
  - Kısmi türev: $\frac{\partial E}{\partial w_1} = -2(t - y\_in)x_1$; 2 çarpanı öğrenme katsayısına katılarak $\Delta w_1 = \mu (t - y\_in) x_1$ elde edilir (ekrandan, 00:15:00).
  - $\partial E / \partial w_1$, $w_1$'in hataya ne kadar katkı yaptığını söyler; her ağırlık kendi katkısı kadar güncellenir.
  - Adaline'da aktivasyon doğrusal olduğu için türev basittir. Başka bir aktivasyon kullanılırsa türev değişir; buna genelleştirilmiş delta kuralı denir ve geri yayılım (backpropagation) bunu kullanır.
- Madaline (Many ADAptive LInear NEurons)
  - İki gizli Adaline ($Z_1$, $Z_2$) ve bir çıkış Adaline'ından ($Y$) oluşan çok katmanlı ağ (ekrandan, 00:20:00).
  - MRI algoritmasında yalnız gizli Adaline'lar delta kuralıyla eğitilir; $v_1$, $v_2$ ve çıkış biası sabit $0.5$ alınır. MRII sürümünde bu ağırlıklar da ayarlanır.
  - İki doğru oluşturarak XOR problemini çözebilir.
- Yapay sinir ağlarının kısa tarihi
  - 80'lerde çok katmanlı ağlar; hesaplama gücü yetmeyince 90'larda duraklama.
  - GPU'ların gelmesi ve gradyanın kaybolması probleminin çözülmesiyle derin ağlara geçiş. CNN'de nöronların hepsinin birbirine bağlı olmadığı mimariler kullanılır.
- Eğri uydurma (regresyon)
  - Ölçüm verileri gürültülü ve eksik olabilir. Ham verilere en yakın eğri denklemini bulmaya eğri uydurma (regresyon) denir (ekrandan, 00:25:00).
  - Amaç: fonksiyonun parametrelerini seçmek, ara değerleri hesaplamak (interpolasyon) ve aralık dışını tahmin etmek (ekstrapolasyon). Örnek: 1990'a kadarki nüfus verisinden 2000 yılını tahmin etmek ekstrapolasyondur.
- En küçük kareler yöntemi
  - $\Pi = d_1^2 + d_2^2 + \dots + d_n^2 = \sum_{i=1}^{n} d_i^2 = \text{minimum}$ (ekrandan, 00:30:00).
  - Doğru $y = a + bx$ ($n \ge 2$), parabol $y = a + bx + cx^2$ ($n \ge 3$), $m$. derece polinom $y = a_0 + a_1x + \dots + a_mx^m$ ($n \ge m+1$) (ekrandan, 00:30:00).
  - Doğru için $\partial\Pi/\partial b = 0$ ve $\partial\Pi/\partial m = 0$ yazılır; iki bilinmeyen için iki doğrusal denklem çıkar (ekrandan, 00:35:00).
  - Çözüm (ekrandan, 00:40:00): $m = \frac{n\sum xy - (\sum x)(\sum y)}{n\sum x^2 - (\sum x)^2}$, $b = \frac{(\sum y)(\sum x^2) - (\sum x)(\sum xy)}{n\sum x^2 - (\sum x)^2}$.
  - Beş noktalık örnek veride uydurulan doğru $y = 2x + 5$ çıkmıştır.
  - Parabol için üç kısmi türev sıfıra eşitlenir, üç doğrusal denklem çözülür (ekrandan, 00:50:00).
- Doğrusallaştırma kestirmesi
  - Verinin logaritması veya karekökü alınarak doğru uydurulabilir hale getirilebilir; doğru uydurulduktan sonra ters işlemle eğri denklemi elde edilir (ekrandan, 00:45:00).
- Çoklu regresyon
  - Birden fazla bağımsız değişken varsa (ör. $z = a + bx + cy$) çoklu regresyondur. Aynı şekilde hata yazılır, $a$, $b$, $c$'ye göre türevler sıfırlanır.
- Doğrusallık kavramı
  - Doğrusal fonksiyon iki koşulu sağlar: toplanabilirlik $f(x+y) = f(x) + f(y)$ ve homojenlik $f(\alpha x) = \alpha f(x)$ (ekrandan, 01:15:00).
  - $f = 2x$ doğrusaldır; $f = 2x + 3$ afindir (öteleme vardır). Afin, toplanabilirlik ve homojenliği sağlamaz.
  - Parabol ve polinom uydurma da doğrusal regresyondur: katsayılar doğrusal denklem sistemiyle bulunur. Doğrusallık şekle değil sistemin çözülebilirliğine bakılarak söylenir.
- Doğrusal olmayan regresyon ve optimizasyon
  - Bilinmeyenler cebirsel olarak çözülemiyorsa optimizasyon (arama) algoritmaları kullanılır.
  - Optimizasyon: $f: A \to R$ için $f(x_0) \le f(x)$ (minimizasyon) veya $f(x_0) \ge f(x)$ (maksimizasyon) sağlayan $x_0$'ı sistematik olarak aramak. $f$ hedef/maliyet fonksiyonu, $A$ makul (feasible) değerler kümesi, yani arama uzayıdır (ekrandan, 01:20:00).
  - Norm özellikleri: $\|x\| \ge 0$, $\|x\| = 0 \iff x = 0$; $\|\alpha x\| = |\alpha|\,\|x\|$; $\|x+y\| \le \|x\| + \|y\|$ (ekrandan, 01:25:00).
  - Doğrusal olmayan en küçük kareler: veriler $(t_i, y_i)$, model $M(x,t)$, $y_i = M(x,t_i) + \epsilon_i$; residü $f_i(x) = y_i - M(x,t_i)$; maliyet $F(x) = \frac{1}{2}\sum_{i=1}^{m} (f_i(x))^2$ (ekrandan, 01:30:00 ve 01:35:00).
- Taylor açılımı, gradyan ve Hessian
  - $F(x+h) = F(x) + h^T g + \frac{1}{2} h^T H h + O(\|h\|^3)$; $g$ gradyan, $H$ Hessian (ekrandan, 01:35:00).
  - İleri/geri fark türev formülleri Taylor açılımından birkaç terim atılarak elde edilir; daha çok terim, daha hassas türev demektir.
  - $F'(x^*) = 0$ ise $x^*$ yerel minimum olabilir; $F'(x_s) = 0$ olan nokta durağan noktadır. Yerel minimum durağan noktadır, tersi her zaman doğru değildir (ekrandan, 01:45:00).
  - Hessian kesin pozitif ise yerel minimum, kesin negatif ise yerel maksimum, belirsiz ise (öz değerler + ve −) eyer noktası (ekrandan, 02:20:00).
- İteratif düşüm yöntemleri
  - $f(x_{k+1}) < f(x_k)$ koşulu ile hep azalma yönünde ilerlenir (ekrandan, 02:25:00).
  - Hata $e_k = x^* - x_k$; $\|e_{k+1}\| < \|e_k\|$ olmalı (ekrandan, 02:25:00).
  - Yakınsama türleri: doğrusal, süperdoğrusal, karesel (kuadratik).
  - Genel yapı: $x_0$ ile başla; düşüm yönünü belirle, adımı belirle, güncelle; durma kriteri sağlanana kadar tekrarla (ekrandan, 02:30:00).
  - Gradyanın tersi yön fonksiyonu azaltır; bu, Taylor açılımının ilk iki teriminden çıkar.
- Yöntemlerin karşılaştırılması
  - Gradyan düşümü yalnız birinci türev ister; güvenilir ama yavaştır.
  - Newton ikinci türev ister; konveks fonksiyonda çok hızlıdır, konveks olmayan fonksiyonda sorun çıkarabilir.
  - Quasi-Newton ve Levenberg-Marquardt ikinci türevi yaklaşık hesaplar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Delta kuralının anlamı
  - $\partial E/\partial w_1$ "hatada $w_1$'in rolü ne kadar?" sorusunun cevabıdır. Delta kuralı bu yüzden matematiksel bir dayanağa sahiptir ve sonraki ağlarda da kullanılır.
- Doğrusallık kavramının netleştirilmesi
  - Doğrusal fonksiyon, doğrusal denklem sistemi ve afin ayrı kavramlardır. Parabol uydurmak bile doğrusal regresyondur; doğrusal olan sistemdir, şekil değil.
- Tek ve çok değişkenli fonksiyon kavramları
  - Makale okurken bu temel matematik kavramları yorum için önemlidir.
- Gradyan düşümünün yönü
  - Türevin (gradyanın) tersi yönünde gidilirse fonksiyonun değeri azalır; bunun dayanağı Taylor serisidir.
- Global yerine iyi bir yerel minimum
  - Engebeli hata yüzeyinde global minimumu bulmak çok uzun sürebilir; pratikte iyi bir yerel minimum yeterlidir.

## Kısa Tekrar Notları

- Perceptron: hata varsa $w_i \leftarrow w_i + \eta t x_i$.
- Adaline/delta kuralı: $\Delta w = \eta (t - y\_in) x$; karesel hatanın türevinden gelir.
- Madaline: gizli katmanlı Adaline ağı; XOR'u çözer.
- Regresyon: verilere en yakın eğriyi bulma; interpolasyon ve ekstrapolasyon.
- En küçük kareler: $\sum d_i^2$ minimum; kısmi türevler sıfır.
- $k$ parametre için en az $k$ veri gerekir (doğru 2, parabol 3, $m$. derece polinom $m+1$).
- Doğrusal fonksiyon: toplanabilirlik + homojenlik. $2x+3$ afindir, doğrusal değildir.
- Doğrusal olmayan regresyon: cebirsel çözüm yok, optimizasyon gerekir.
- $F(x+h) \approx F(x) + h^T g + \frac{1}{2}h^T H h$.
- $g = 0$: yerel minimum veya durağan nokta; Hessian kesin pozitif: yerel minimum.
- Düşüm algoritması: yön, adım, güncelle, durma kriteri.
- Gradyan düşümü: $-\nabla f$ yönü; yalnız birinci türev.
- Newton: ikinci türev, hızlı ama pahalı ve her fonksiyona uygun değil.

## Detaylı Açıklamalar

- **Delta kuralının türetilmesi.** Adaline'da nöron girişi $y\_in = \sum x_i w_i$ ve aktivasyon doğrusaldır. Hata $E = \sum_j (t_j - y\_in_j)^2$ olarak yazılır. $w_1$'e göre kısmi türevde üs öne iner, içinin türevinde yalnız $x_1$ kalır (diğer terimler $w_1$'e göre sabittir). Sonuç $-2(t - y\_in)x_1$'dir. Sabit 2 öğrenme katsayısının içine katılır ve ağırlık değişimi $\Delta w_1 = \mu(t - y\_in)x_1$ olur (ekrandan, 00:15:00). Doğrusal olmayan bir aktivasyon kullanılınca türev zincir kuralıyla değişir; bu genelleştirilmiş delta kuralıdır ve çok katmanlı ağlardaki geri yayılımın temelidir.

- **Perceptron ve Adaline farkı.** Mimari benzerdir. Perceptron'da aktivasyon eşik fonksiyonudur; Adaline'da ağırlık güncellemesi doğrusal aktivasyonun çıkışı üzerinden yapılır, eşik sonra veya bias ile uygulanabilir. Asıl fark öğrenme kuralıdır. Delta kuralı da doğrusal olmayan problemleri çözmeyi sağlamaz.

- **Madaline.** $X_1$, $X_2$ girdileri $w_{11}, w_{12}, w_{21}, w_{22}$ ağırlıklarıyla ve $b_1$, $b_2$ biaslarıyla $Z_1$, $Z_2$ gizli birimlerine; bunlar $v_1$, $v_2$ ve $b_3$ ile $Y$ çıkışına bağlanır (ekrandan, 00:20:00). Ara katman eklendiği için çok katmanlı bir ağdır ve iki karar doğrusu oluşturarak XOR'u ayırabilir.

- **En küçük kareler ile doğru uydurma.** $y = mx + b$ için $\Pi = \sum [y_i - (mx_i + b)]^2$. $\partial\Pi/\partial b = 0$ ve $\partial\Pi/\partial m = 0$ açılınca normal denklemler çıkar (ekrandan, 00:40:00):
  - $\sum y_i = m\sum x_i + b\sum 1$
  - $\sum x_i y_i = m\sum x_i^2 + b\sum x_i$
  - Buradan $m$ (eğim) ve $b$ (düşey ekseni kestiği nokta) formülleri elde edilir. Beş noktalık örnekte ($x=1$ için $y=7$, $x=2$ için $y=9$, ...) sonuç $y = 2x + 5$'tir; veri yapay olduğu için doğru noktalardan tam geçer. <!-- BELİRSİZ: beş noktalık örnek tablonun tamamı karelerde görünmüyor; yalnız ilk iki nokta altyazıdan alındı. -->

- **Karekök kestirmesi.** $y = (mx+b)^2$ biçimindeki veride $\sqrt{y} = mx + b$ bir doğrudur; $\sqrt{y}$'ye doğru uydurulup sonuç karesi alınarak parabol elde edilir. Slayttaki örnek fonksiyon $y = x^2 + 5$'tir (ekrandan, 00:45:00). Hassasiyet çok önemli değilse işlem yükünü azaltan pratik bir yoldur.
  - Ders sonrası not: $\sqrt{x^2+5}$ tam doğru değildir; yalnız büyük $x$ için yaklaşık $x$'e benzer (0-34 aralığında doğru uydurmada en büyük sapma yaklaşık 1.42, python ile kontrol edildi). Karekök dönüşümü tam olarak $(mx+b)^2$ biçimli veride doğru verir.

- **Doğrusal olmayan regresyon.** Model $y_i = M(x, t_i) + \epsilon_i$ biçimindedir; $\epsilon_i$ düşey eksendeki ölçüm hataları (beyaz gürültü) (ekrandan, 01:30:00). Residü $f_i(x) = y_i - M(x,t_i)$, maliyet $F(x) = \frac{1}{2}\sum f_i(x)^2$'dir. $F(x^*) \le F(x)$, $\|x - x^*\| < \delta$ koşulunu sağlayan $x^*$ aranır (ekrandan, 01:35:00). Cebirsel çözüm olmadığından türev bilgisi Taylor açılımı üzerinden kullanılır.

- **Gradyan ve Hessian örnekleri.**
  - $f = 2x + 3y^2 - \sin z$ için $\nabla f = (2,\ 6y,\ -\cos z)^T$ (derste sözlü, 02:17:39; python ile kontrol edildi).
  - $f = x^2 + xy + y^2$ için $\partial f/\partial x = 2x + y$, Hessian $\begin{bmatrix} 2 & 1 \\ 1 & 2 \end{bmatrix}$ (derste sözlü, 02:21:24; python ile kontrol edildi, öz değerler 1 ve 3, yani kesin pozitif).
  - Ders sonrası not: Hoca Hessian'ı "tersi kendisine eşit kare matris" diye tanımladı; doğrusu slayttaki gibi simetrik matristir ($H^T = H$). Hoca kesin pozitifliği determinantın pozitif olması diye açıkladı; doğrusu bütün öz değerlerin pozitif olmasıdır (determinant pozitifliği tek başına yetmez).

- **Gradyan düşümü ve Newton karşılaştırması.** Slayttaki $f(x) = 2x_1^2 + x_1x_2 + x_2^2$ eş yükselti eğrilerinde gradyan düşümü $x^0 = (0.5, 1)$'den başlayıp $x^1$, $x^2$, $x^3$ ile zikzak çizerek merkezdeki minimuma yaklaşır; Newton ise tek adımda minimuma gider (ekrandan, 02:45:00). Python kontrolü: tam doğru aramalı gradyan düşümünde $x^1 \approx (-0.22, 0.40)$, $x^2 \approx (0.04, 0.08)$; Newton adımı doğrudan $(0, 0)$ verir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
