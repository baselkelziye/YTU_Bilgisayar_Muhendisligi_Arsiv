# Ders 3 Genişletilmiş Notu: Delta Kuralından Regresyon ve Optimizasyonun Temellerine

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersin tekrarı: Hebb, Perceptron ve Adaline
- 2. Delta kuralının türetilmesi
- 3. Perceptron ile Adaline farkı ve Madaline
- 4. Yapay sinir ağlarının kısa tarihi
- 5. Eğri uydurma (regresyon)
- 6. En küçük kareler yöntemi
- 7. Doğrusallık, afinlik ve doğrusal denklem sistemleri
- 8. Çoklu regresyon ve doğrusal olmayan regresyon
- 9. Optimizasyonun temel kavramları
- 10. Taylor açılımı, gradyan ve Hessian
- 11. İteratif düşüm yöntemleri ve yakınsama
- 12. Gradyan düşümü ve Newton yöntemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Tekrarı: Hebb, Perceptron ve Adaline

Ders, önceki haftada işlenen tek katmanlı ağların hızlı bir tekrarıyla başlar. İlk olarak Hebb'in önerdiği tek nöron modeli ve Hebb öğrenme kuralı hatırlatılır. Hebb kuralı, nöronun girdisi ile çıktısını çarparak ağırlığın yeni değerini belirler. Hocanın vurguladığı iki zayıflık vardır: kural tek iterasyonla çalışır ve bu tek iterasyon öğrenme için yetersiz kalır; kural iteratif çalıştırılırsa da ağırlıklar kontrolsüz biçimde büyür.

Perceptron öğrenme kuralı ise hedef değeri ($t$) kullanır. Girdi ile hedef değer çarpılır ve buna bir öğrenme katsayısı eklenir. Öğrenme katsayısının görevi, öğrenmeyi biraz yavaşlatmak ve ağırlıklarda kontrolsüz büyük değişimleri önlemektir. Perceptron iteratif çalışır. Slayttaki tanım şöyledir (ekrandan, 00:05:00):

- Öğrenme kuralı "error driven"dır: Perceptron hatalardan öğrenir, her hata sonucunda ağırlıklar yeniden hesaplanır.
- Eğitim ikilisi $s:t$ olarak adlandırılır.
- Bir eğitim girdisi için hata oluştuysa ağırlıklar $w_i(new) = w_i(old) + \eta t x_i$ formülüne göre değiştirilir. Burada $t$ hedef değerdir ($+1$ veya $-1$), $\eta$ öğrenme oranıdır.
- Hata oluşmazsa ağırlıklar değiştirilmez; öğrenme yalnız hata oluştuğunda gerçekleşir.
- Durma koşulu: eğitim, hiçbir hata oluşmayana veya önceden belirlenen epoch (tekrar) sayısına ulaşılana kadar devam eder.

Her iki kuralın da zayıflıkları vardır; önceki derste XOR problemini çözemedikleri gösterilmişti.

Ardından Adaline tekrar edilir. Slayttaki bilgiye göre Adaline (Adaptive Linear Network) 1960'ta Widrow ve Hoff tarafından geliştirilmiştir. Girdi sinyalleri ve hedef değerler için bipolar aktivasyonlar ($-1$ ve $1$) kullanır, ağırlık bağlantıları ayarlanabilirdir ve ağırlık güncellemesi "delta kuralı" ile yapılır (ekrandan, 00:10:00):

$$w_{ij}(new) = w_{ij}(old) + \eta\,(targ_j - out_j)\,x_i$$

Hoca, Adaline'ın mimari olarak Perceptron'dan çok farklı olmadığını, asıl önemli katkısının delta kuralı olduğunu söyler. Delta kuralı, hedeflenen değer ile hesaplanan değer arasındaki farka bakarak güncelleme yapar. Böylece hedeften ne kadar uzaksak ve ilgili ağırlık bu hatada ne kadar rol oynuyorsa, ağırlık o kadar güncellenir.

## 2. Delta Kuralının Türetilmesi

Delta kuralı, önce bir karesel hata fonksiyonu yazılarak elde edilir. Hedef değerden nöron girişinin farkı alınır, karesi alınır ve çıkışlar üzerinden toplanır (ekrandan, 00:15:00):

$$E = \sum_{j=1}^{m} (t_j - y\_in_j)^2, \qquad y\_in = \sum_{i=1}^{n} x_i w_i$$

Hocanın üzerinde durduğu nokta, bu hatanın $w_1$'e göre kısmi türevinin sözel anlamıdır. Türev değişim demektir; $\partial E/\partial w_1$, hatanın değişiminde $w_1$'in katkısının ne kadar olduğunu söyler. Yani "hatada $w_1$'in rolü ne kadar?" sorusunun cevabıdır. Delta kuralı bu mantıktan çıktığı için her ağırlığa kendine özel güncelleme yapma imkânı verir.

Türev adım adım şöyle alınır:

- Klasik türevdeki gibi üs öne iner ve parantezin üssü bir azalır: $2$ çarpanı oluşur, kare birinci kuvvete iner.
- Parantezin içinin türevi $w_1$'e göre alınır. $y\_in = x_1 w_1 + x_2 w_2 + \dots$ açık yazılırsa, $w_2$, $w_3$ içeren terimler $w_1$'e göre sabittir ve türevleri sıfırdır. Geriye yalnız $x_1$ kalır. Hedef $t$ da sabittir; önündeki eksi işareti türeve geçer.
- Sonuç (ekrandan, 00:15:00):

$$\frac{\partial E}{\partial w_1} = -2(t - y\_in)\frac{\partial y\_in}{\partial w_1} = -2(t - y\_in)x_1$$

- Öndeki $2$ sabit bir çarpandır; öğrenme katsayısının içine katılabilir. Böylece ağırlık değişimi:

$$\Delta w_1 = \mu (t - y\_in) x_1$$

Bu terim delta kuralında ağırlığa uygulanan değişimdir. Hoca bunu "bir hata fonksiyonum var, onu küçültecek şekilde, hangi ağırlığın hataya ne kadar etki ettiğini dikkate alarak değişim yapıyorum" diye özetler.

> **Ek bilgi (derste anlatılmadı):** Güncellemenin $+\mu(t - y\_in)x_1$ olması, türevin ($-2(t-y\_in)x_1$) ters işaretlisi yönünde gidildiği anlamına gelir. Dersin sonunda anlatılan "gradyanın tersi yönünde gidilirse hata azalır" fikrinin tek nöronlu özel hâlidir.

Hoca burada sonraki dersler için önemli bir uyarı yapar: Adaline'da aktivasyon fonksiyonu doğrusal olduğu için nörona ne giriyorsa o çıkar ve türev bu kadar basittir. Farklı (doğrusal olmayan) bir aktivasyon fonksiyonu kullanılsaydı, türev alma işlemi daha karmaşık olur ve formül değişirdi. Herhangi bir aktivasyon fonksiyonu için türevlerin yeniden alınmasıyla elde edilen kurala genişletilmiş (genelleştirilmiş) delta kuralı denir. Çok katmanlı ağlarda kullanılacak geri yayılım (backpropagation) kuralında durum budur.

## 3. Perceptron ile Adaline Farkı ve Madaline

### 3.1 Perceptron ile Adaline farkı

Hoca farkları yeniden sıralar:

- Adaline tek çıkışlıdır; Perceptron'da böyle bir kısıt konmamıştı.
- Perceptron'da aktivasyon fonksiyonu bir eşik (threshold) fonksiyonudur. Adaline'da ağırlık güncellemesinde kullanılan aktivasyon doğrusal bir fonksiyondur; hata bu noktadan hesaplanır. Eşik daha sonra ya da bir bias aracılığıyla uygulanabilir.
- Mimari olarak birbirlerine benzerler; öğrenme kuralı farklıdır ve kritik olan da budur.

Delta kuralının kullanılması doğrusal olmayan problemleri çözmeyi sağlamaz. XOR gibi problemler Perceptron ve Adaline ile hâlâ çözülemez.

### 3.2 Madaline

Tek katmanlı (yalnız girdi ve çıktıdan oluşan) mimarilerin yetmediği fark edilince Madaline önerilmiştir. Slayttaki tanım (ekrandan, 00:20:00): Madaline (Many ADAptive LInear NEurons), çok katmanlı bir ağda düzenlenmiş birçok Adaline'dan oluşur; iki gizli Adaline ve bir çıktı Adaline ünitesi bulunur. Şekilde:

- $X_1$ ve $X_2$ girdileri $w_{11}$, $w_{12}$, $w_{21}$, $w_{22}$ ağırlıklarıyla $Z_1$ ve $Z_2$ birimlerine bağlanır; $Z_1$ ve $Z_2$'nin biasları $b_1$ ve $b_2$'dir.
- $Z_1$ ve $Z_2$, $v_1$ ve $v_2$ ağırlıklarıyla ve $b_3$ biasıyla $Y$ çıkış birimine bağlanır.
- Z birimleri gizli katmanda yer alır.

$X_1, X_2$ girdileri, $Z_1, Z_2$ ara çıktıları ve $Y$ çıktısı olduğu için ek bir ara katman eklenmiş ve ağ çok katmanlı hâle gelmiştir. Adaline delta kuralını getirmişti; Madaline ise çok katmanlı yapıyı önerir.

Öğrenme şöyle yapılır: $Z_1$ ve $Z_2$ klasik Adaline öğrenmesiyle (delta kuralıyla) eğitilir. Orijinal algoritmada (hocanın "MR1" dediği sürüm) $Y$'ye giden $v_1$, $v_2$ ağırlıkları ve $Y$'nin biası sabit $0.5$ alınır, bunlarda ayarlama yapılmaz. Algoritmanın "MR2" dediği bir sürümünde ise $v_1$ ve $v_2$ de ayarlanır.

> **Ek bilgi (derste anlatılmadı):** Literatürde bu iki sürüm büyük olasılıkla MRI ve MRII (Madaline Rule I ve II) adlarıyla geçer; altyazıdaki "MR1/MR2" bunlara karşılık gelir.

Önceki derste Madaline'ın XOR problemini çözebildiği görülmüştü: iki doğrusal bölge (iki doğru) oluşturarak XOR'un pozitif ve negatif cevaplarını ayırır.

## 4. Yapay Sinir Ağlarının Kısa Tarihi

Hoca, Madaline ile birlikte 80'lerde çok katmanlı ağların ortaya çıktığını ve delta kuralıyla ilerlemenin sürdüğünü anlatır. Bir iki katman eklemek dönemin işlemcileri için sorun değildir; ancak daha fazla katman eklemek veya daha karmaşık problemleri çözmek istendiğinde hesaplama gücü yetmez ve 90'larda bir duraklama dönemi yaşanır. Bu duraklama iki gelişmeye kadar sürer: GPU'ların piyasaya çıkması ve genişletilmiş delta kuralı ile geri yayılımın türevle ilgili zayıflığı olan gradyanın kaybolması probleminin çözülmesi. Bu iki konu halledilince katman sayısı artırılabilmiş ve derin ağlara geçilmiştir.

Hoca, öğrenme kuralının temelinde büyük bir değişiklik olmadığını; değişenin kullanılan aktivasyon fonksiyonu ve gradyanın kaybolması probleminin çözümü olduğunu söyler. Geri yayılım ileri beslemeli derin ağlarda hâlâ popüler algoritmadır. Sonra "bütün nöronların birbirine bağlı olması gerekiyor mu?" sorusu ortaya çıkar ve konvolüsyonel ağlar (CNN) gelir: özellikle görüntü için filtrelerin kullanılması ve bütün nöronların birbirine bağlı olmadığı farklı mimariler.

## 5. Eğri Uydurma (Regresyon)

Hoca, doğrusal regresyondan başlayıp doğrusal olmayan regresyona ve oradan geri yayılım algoritmasına nasıl bağlanıldığını göstermek istediğini söyler. Slayttaki maddeler (ekrandan, 00:25:00):

- Ölçüm-gözlem yolu ile elde edilen veriler genellikle gürültü içerebilir.
- Tüm kontrol parametreleri (bağımsız değişkenler) sabit tutulsa bile elde edilen sonuç (bağımlı değişken) farklı çıkabilir.
- Ham verilere en yakın eğri denklemini bulma işlemi eğri uydurma (regresyon) olarak adlandırılır.
- Eğri uydurmanın amacı, bir grup veriyi en iyi şekilde tanımlamak için bir fonksiyondaki parametreleri seçmek ve ara değerleri hesaplamak (interpolasyon) veya bilinmeyen değerleri tahmin edebilmektir (ekstrapolasyon).

Hoca, verilerin eksik de olabileceğini, yani ara noktalarda ölçüm alınmamış olabileceğini ekler. Eğri uydurulunca bilinmeyen değerler hesaplanabilir ve tahmin yürütme imkânı doğar.

İnterpolasyon, verinin kapsadığı aralığın içinde kalan ama bilinmeyen bir değeri hesaplamaktır. Ekstrapolasyon ise aralığın dışında tahmin yapmaktır: örneğin 1 ile 10 arasındaki değerler için ölçüm yapılmışken 15'in karşılığını bulmak. Hocanın örneği: 1990'a kadar nüfus ölçümleri varken 2000 yılının nüfusunu tahmin etmek ekstrapolasyondur. 1990'a kadarki veriler içinde eksik bir yılı ya da bir yılın ortasındaki bir zamanı hesaplamak ise interpolasyondur.

## 6. En Küçük Kareler Yöntemi

### 6.1 Temel fikir

Regresyon için en yaygın yöntem en küçük kareler yöntemidir. Amaç, tüm verilere göre en az sapmayı veren eğriyi bulmaktır. Uydurulan eğri çok sayıda veri için küçük de olsa bir hata içerecektir; bu küçük hatalar toplandığında toplamı en küçük olan eğri seçilir.

Elimizde $x_1, x_2, \dots, x_n$ noktaları ve bunlara karşılık ölçülmüş $y_1, \dots, y_n$ değerleri olsun. Uydurulacak eğrinin fonksiyonu $f$ ise, her veri için gerçek değer ile tahmin arasındaki uzaklık ($d_i$) hesaplanır. Bu farkların kareleri toplanınca toplam karesel hata elde edilir. Slayttaki ifade (ekrandan, 00:30:00):

$$\Pi = d_1^2 + d_2^2 + \dots + d_n^2 = \sum_{i=1}^{n} d_i^2 = \text{minimum}$$

$\Pi$'nin içinde $x$'ler, $y$'ler ve $f$'nin bilinmeyen parametreleri vardır; dolayısıyla $\Pi$ de bu parametrelerin bir fonksiyonudur. Bir fonksiyonun minimum olduğu nokta türevinin sıfır olduğu noktadır. Bu yüzden $\Pi$'nin bilinmeyen parametrelere göre kısmi türevleri sıfıra eşitlenir.

Regresyonda en yaygın kullanılan eğri tipi polinomlardır (ekrandan, 00:30:00):

- Doğru: $y = a + bx$ (en az iki veri olmalı, $n \ge 2$)
- Parabol: $y = a + bx + cx^2$ ($n \ge 3$)
- $m$. derece polinom: $y = a_0 + a_1x + a_2x^2 + \dots + a_mx^m$ ($n \ge m+1$)

Doğru için iki, parabol için üç bilinmeyen parametre vardır. Hedef, parametrelerin öyle bir kombinasyonunu seçmektir ki $\Pi$ alabileceği en küçük değeri alsın; tercihen sıfır, olamıyorsa en küçük değer.

### 6.2 Kontrol parametreleri ve bağımlı/bağımsız değişken

Hoca burada terimleri tanımlar. $x$ bağımsız değişken, ona bağlı olarak hesaplanan $y$ bağımlı değişkendir. Bağımsız değişken birden fazlaysa (örneğin $x$ ve $y$ bağımsız, $z$ bağımlı) bu çoklu regresyondur; bağımsız değişken sayısı ikiyle sınırlı değildir. $a$, $b$, $c$ gibi katsayılar kontrol parametreleridir: değiştikçe denklemin temsil ettiği eğrinin şekli ve konumu değişir.

Hocanın benzetmesi: Bir Gauss fonksiyonunun genliği ve orta noktasıyla oynadıkça Gauss sivrileşir, yayvanlaşır, sağa sola kayar. Sinir ağlarındaki bias parametresi de böyledir: doğrunun şeklini değiştirmez ama aşağı yukarı, sağa sola kaymasını ayarlar.

### 6.3 Doğru uydurma

$y = mx + b$ için hata $\Pi = \sum [y_i - (mx_i + b)]^2$ olarak yazılır. İki kontrol parametresi $m$ ve $b$'dir. Hocanın sözel yorumu: $\partial\Pi/\partial b$, "$\Pi$ hata fonksiyonunda $b$'nin rolü ne kadar, $\Pi$ $b$'ye göre nasıl değişiyor?" sorusunun cevabıdır. $b$ öyle ayarlanır ki $\Pi$'nin $b$'ye göre değişimi sıfır olsun; bu, $\Pi$'nin minimuma ulaşması demektir. Aynısı $m$ için de istenir. Slayttaki denklemler (ekrandan, 00:35:00):

$$\frac{\partial\Pi}{\partial b} = 2\sum_{i=1}^{n}[y_i - (mx_i + b)] = 0$$

$$\frac{\partial\Pi}{\partial m} = 2\sum_{i=1}^{n}x_i[y_i - (mx_i + b)] = 0$$

Slaytta not olarak "Bir fonksiyonun minimum değerinde her bir bağımsız değişkene göre kısmi türevi 0 olmalı" yazar.

> **Ders sonrası not:** Slayttaki türevlerin başında $2$ yazıyor; zincir kuralıyla doğrusu $-2$'dir. Sağ taraf sıfır olduğu için bu işaret farkı sonucu değiştirmez.

İki bilinmeyen ve iki doğrusal denklem olduğu için sistem çözülebilir. Denklemler açılınca (ekrandan, 00:40:00):

$$\sum_{i=1}^{n} y_i = m\sum_{i=1}^{n} x_i + b\sum_{i=1}^{n} 1$$

$$\sum_{i=1}^{n} x_i y_i = m\sum_{i=1}^{n} x_i^2 + b\sum_{i=1}^{n} x_i$$

Buradan $m$ ve $b$ katsayıları:

$$m = \frac{n\sum xy - (\sum x)(\sum y)}{n\sum x^2 - (\sum x)^2}, \qquad b = \frac{(\sum y)(\sum x^2) - (\sum x)(\sum xy)}{n\sum x^2 - (\sum x)^2}$$

$m$ eğim, $b$ doğrunun düşey ekseni kestiği noktadır. Hoca bu formülleri öğrencilerin daha önceki derslerden (lineer cebir) hatırladığını söyler.

### 6.4 Sayısal örnek

Elimizde beş veri vardır: $x = 1$ iken $y = 7$, $x = 2$ iken $y = 9$ vb. Formüller uygulanınca en uygun doğru $y = 2x + 5$ bulunmuştur. Hoca veriyi yapay oluşturduğu için verilerin bu doğruyu tam sağladığını, gerçek veride bir miktar hata olabileceğini söyler. Hata olsa bile, yöntemin dayanağı türevin sıfırlanması olduğu için bulunan $m$ ve $b$'nin hatayı minimum yapan katsayılar olduğuna güvenilir. İlk iki nokta kontrol edildiğinde $2\cdot1 + 5 = 7$ ve $2\cdot2 + 5 = 9$'dur.

<!-- BELİRSİZ: beş noktalık örnek tablonun tamamı (kalan üç nokta ve ara toplamlar) karelerde görünmüyor; yalnız ilk iki nokta ve sonuç altyazıdan alındı. -->

### 6.5 Doğrusallaştırma kestirmesi

Slayttaki maddeler (ekrandan, 00:45:00): Bu teori verilerin doğrusal formda olduğunu varsayar. Bir eğriye ait veriler için de bu yöntemle ancak bir doğru denklemi elde edilebilir. Ancak verilerin logaritmasını veya karekökünü almak gibi basit yöntemlerle verileri doğru uydurulabilecek hâle getirmek mümkün olabilir. Örnek olarak $y = x^2 + 5$ fonksiyonu ve onun 0-35 aralığındaki grafiği verilmiştir.

Hocanın anlatımı: Veri $y = (mx + b)^2$ gibi bir parabol gösteriyorsa, $\sqrt{y} = mx + b$ bir doğrudur. $x$'e karşı $\sqrt{y}$ çizilirse doğru görülür; $\sqrt{y}$'ye doğru uydurulur, $m$ ve $b$ bulunur, sonra karesi alınarak $y$ için parabol denklemi elde edilir. Bu yol işlem sayısını azaltır ve programlama açısından da etkilidir; uydurulan eğrinin çok hassas olması gerekmiyorsa kullanılabilir.

> **Ders sonrası not:** Slayttaki $y = x^2 + 5$ fonksiyonunun karekökü ($\sqrt{x^2+5}$) tam bir doğru değildir; yalnız büyük $x$ değerlerinde yaklaşık $x$'e benzer. 0-34 aralığında $\sqrt{y}$'ye doğru uydurulduğunda en büyük sapma yaklaşık 1.42'dir (python ile kontrol edildi). Karekök dönüşümü tam olarak $(mx+b)^2$ biçimli veride doğru verir; $x^2+5$ için bu yol yaklaşık bir sonuç verir.

### 6.6 Parabol ve polinom uydurma

Parabol uydurmak için parabolün derecesinin bir fazlası kadar veri gerekir: ikinci derece parabolün üç katsayısı olduğu için en az üç örnek ve üç denklem gerekir. Yine karesel hata yazılır ve her kontrol parametresine göre kısmi türevler sıfıra eşitlenir (ekrandan, 00:50:00):

$$\frac{\partial\Pi}{\partial a} = 2\sum_{i=1}^{n}[y_i - (a + bx_i + cx_i^2)] = 0$$

$$\frac{\partial\Pi}{\partial b} = 2\sum_{i=1}^{n}x_i[y_i - (a + bx_i + cx_i^2)] = 0$$

$$\frac{\partial\Pi}{\partial c} = 2\sum_{i=1}^{n}x_i^2[y_i - (a + bx_i + cx_i^2)] = 0$$

Üç denklemin üçü de doğrusaldır; doğrusal denklem sistemi çözülerek parabol uydurulur. Yani problem doğrusaldır. $m$. dereceden polinom için de aynısı geçerlidir: her katsayıya göre kısmi türev yazılır ve katsayı sayısı kadar doğrusal denklem elde edilir. Hoca aradan sonra bunu "$m$ değişken varsa $m+1$ türev denklemi" diye toparlar (katsayılar $a_0$'dan $a_m$'ye kadar $m+1$ tanedir).

## 7. Doğrusallık, Afinlik ve Doğrusal Denklem Sistemleri

### 7.1 Parabol uydurmak neden doğrusal regresyondur?

Hoca, bir fonksiyonun şekil olarak doğru görünmesi ile sistemin doğrusal olmasının farklı şeyler olduğunu vurgular. Eğri uydurma konusu "lineer cebir" dersinde işlenir; şekil parabol ya da daha karmaşık bir eğri olabilir, ama sistem doğrusaldır. Problemin doğrusal denklem setleriyle çözülüp çözülemediği, sistemin doğrusal olup olmadığını söyler.

> **Hocanın vurgusu:** Doğrusallık konusunu kafanızda netleştirin; birçok konuda karşınıza çıkacak.

### 7.2 Afin ve doğrusal

Hoca öğrencilere "afin ne demek, lineer ne demek?" diye sorar ve görüntü işlemedeki afin dönüşümü hatırlatır. Bir öğrenci sohbete afinin "ötelenmiş" anlamına geldiğini yazar; hoca bunu doğru bulur. $f = 2x$ doğrusal bir denklemdir: ilişkide yalnız çarpan etkisi vardır. $f = 2x + 3$ ise afindir: çarpmanın yanı sıra bir öteleme de vardır. $2x + 3$ şekil olarak bir doğrudur ama ilişki doğrusal değildir; $+3$ ötelemesi doğrusal ilişkiyi bozar.

Bu yüzden doğrusallığa bakarken neye bakıldığı netleştirilmelidir: şekle mi, ilişkiye mi, yoksa problemin doğrusal denklemlerle çözülebilirliğine mi? Bilinmeyen sayısı kadar birinci derece denklem kurulabiliyor ve bunlar toplanıp çıkarılarak bilinmeyenler bulunabiliyorsa sistem doğrusaldır. Matematiksel tanım toplanabilirlik ve çarpımsallık kurallarının sağlanmasıdır.

Hoca, afin işlemlerin toplanabilirlik ve çarpımsallık kuralını sağlamadığına dikkat çeker: afin, doğrusal değildir. Doğrusal, afinin ötelemenin sıfır olduğu özel durumu (alt kümesi) olarak düşünülebilir. Görüntü işlemede ve işaret işlemede dönüşümlerin doğrusal, doğrusal olmayan ya da afin diye adlandırıldığını da ekler.

### 7.3 Doğrusal fonksiyonun koşulları

Slayttaki tanım (ekrandan, 01:15:00): Doğrusal fonksiyon ve doğrusal denklem sistemi ayrı şeylerdir. Doğrusal ilişkiler, çıkış fonksiyonunun girişlerle doğrudan (sabit) orantılı olarak değiştiği ilişkilerdir. $f(x)$ doğrusal bir fonksiyon ise iki koşulu sağlamalıdır:

- Toplanabilirlik: $f(x + y) = f(x) + f(y)$
- Homojenlik: $f(\alpha x) = \alpha f(x)$

Hocanın açıklaması: Toplanabilirlik, $x+y$'ye $f$ uygulamanın $x$ ve $y$'ye ayrı ayrı uygulayıp toplamakla aynı sonucu vermesidir. Homojenlikte $\alpha$ sabit bir sayıdır; çarpanı fonksiyonun dışına almak sonucu değiştirmemelidir. Bu iki kural birlikte süperpozisyon kurallarıdır. Slayta göre doğrusal sistemler, aynı denklemin farklı çözümlerini üst üste bindirerek (süperpoze edip toplayarak) çözülebilir. Slaytın son cümlesi: en küçük kareler yöntemiyle çözülen parabol ve $m$. derece polinom denklemleri doğrusal regresyon örneğidir, çünkü en uygun katsayılar bağımlı ve bağımsız değişkenlere bağlı olarak ifade edilebilmiştir.

Hoca, doğrusal denklem sistemlerini hatayı farklı tanımlayarak başka yollarla da çözmenin mümkün olduğunu, ama en yaygın yolun en küçük kareler olduğunu söyler.

## 8. Çoklu Regresyon ve Doğrusal Olmayan Regresyon

### 8.1 Çoklu regresyon

Çoklu regresyonda iki (veya daha fazla) bağımsız değişken vardır. Örnek: $x$ ve $y$ bağımsız, $z$ bağımlı değişken olmak üzere $z = a + bx + cy$ biçiminde bir denkleme uygun $a$, $b$, $c$ bulunacaktır. Üç parametre olduğu için en az üç veri gerekir. Hata fonksiyonu aynı şekilde yazılır; fark, kullanılan fonksiyonun çok değişkenli olmasıdır. $a$, $b$, $c$'ye göre türevler alınıp sıfıra eşitlenince üç doğrusal denklem çıkar ve çözülür.

> **Hocanın vurgusu:** Tek değişkenli ve çok değişkenli fonksiyon gibi temel matematik kavramlarını kafanızda oturtun; tez aşamasında makale okurken yorum için önemli ipuçları verir.

Hoca ayrıca çoklu regresyon için Lagrange yönteminin de kullanılabildiğini belirtir.

### 8.2 Doğrusal olmayan regresyon

Doğrusal olmayan denklem sistemlerinde ve doğrusal olmayan regresyonda bilinmeyen parametreleri çözmek için cebirsel bir ifade kurulamaz; bilinmeyen sayısı kadar denklem yazıp toplayıp çıkararak çözüm bulunamaz. Geriye kalan yol optimizasyon algoritmaları, sezgisel (heuristic) algoritmalar gibi "akıllı deneme yanılma" yöntemleriyle fonksiyonun minimumunu aramaktır. Fonksiyon türevlenebilir olmayabilir ya da cebirsel bir ifadeyle yazılamıyor olabilir; minimumu ancak bir arama/optimizasyon algoritmasıyla bulunabilir.

Hoca, doğrusal regresyonun $f(x) + \epsilon$ gibi bir hata payıyla ifade edilebileceğini söyler. Doğrusal olmayan regresyonda bulunacak sonuç cebirsel bir ifade olmayacaktır; hatanın minimum olduğu yere ait parametreler bulunacak ve tahminler nokta bazında bunlara dayanarak yürütülecektir.

<!-- BELİRSİZ: 01:18:11 civarında doğrusal olmayan regresyon modeline ikinci bir bağımsız değişken eklenmesi ve "X ile Y arasında ilişki olmaması" anlatımı altyazıda bozuk; bu anın karesi okunmadı. -->

## 9. Optimizasyonun Temel Kavramları

### 9.1 Tanım

Slayttaki tanım (ekrandan, 01:20:00): Optimizasyon, reel bir fonksiyonu minimum veya maksimum yapmak için izin verilen bir kümeden reel veya tamsayı değerlerin sistematik olarak seçilmesidir. $f: A \to R$, $A$ kümesinden reel sayılara bir fonksiyon olsun. $A$ kümesinde öyle bir $x_0$ değeri aranır ki:

- $f(x_0) \le f(x)$ ($A$ kümesindeki tüm $x$'ler için): minimizasyon
- $f(x_0) \ge f(x)$ ($A$ kümesindeki tüm $x$'ler için): maksimizasyon

$f$ hedef (objective) fonksiyon veya maliyet (cost) fonksiyonu olarak adlandırılır. $A$, bu fonksiyonu minimize veya maksimize eden makul (feasible) değerleri içeren bir kümedir.

Hocanın açıklaması: Sistematik olarak bir grup $x$ değeri denenir, fonksiyonun bu değerlerdeki sonucu hesaplanır ve şimdiye kadar hesaplananlardan daha küçük sonuç veren $x_0$ minimum kabul edilir. Neyin minimize ya da maksimize edileceği problemin tanımına bağlıdır: kârlılıksa maksimize edilir, hata ise minimize edilir. $A$ kümesi sonsuz seçilmek istenmez; problemin tanımlı olduğu ya da minimumun beklendiği bir aralık seçilerek kısıtlanır.

### 9.2 Arama uzayı ve norm

Slayttaki maddeler (ekrandan, 01:25:00): $A$ genellikle $R^n$ Öklid uzayının bir alt kümesidir ve bir grup sınırlama, eşitlik veya eşitsizlik ile tanımlanır. $A$ domeni arama uzayıdır (search space); bu kümenin elemanları aday çözümler veya olası çözümler olarak adlandırılır. Şu özellikler sağlanmalıdır:

- $\|x\| \ge 0,\ \forall x \in R^n$; $\|x\| = 0$ ancak ve ancak $x = 0$ ise
- $\|\alpha x\| = |\alpha|\,\|x\|,\ \forall \alpha \in R,\ x \in R^n$
- $\|x + y\| \le \|x\| + \|y\|,\ \forall x, y \in R^n$

Hoca $R^n$ yazılmasının nedenini açıklar: değişkenler artık tek boyutlu değil, çok boyutludur. Norm kavramını da tanımlar: $x = (x_1, x_2, x_3, \dots)$ vektörel bir değişken olduğunda bileşenlerin karelerinin toplamı (ve karekökü) $x$'in normunu verir. Öklid uzayında konuşulduğu için bu Öklid normudur; Manhattan uzaklığı gibi başka mesafeler için başka normlar vardır. İkinci kural homojenlik, üçüncü kural toplanabilirlikle ilgili koşuldur (üçgen eşitsizliği).

### 9.3 Konvekslik ve yerel minimum

Hedef fonksiyon konveks değilse birkaç yerel minimum veya maksimum bulunabilir. Hocanın benzetmesi: avucunuzu yuvarlayınca oluşan tas şekli konveks fonksiyondur; ters çevrilmiş hâli konkav fonksiyondur. Net bir minimumu olan böyle bir fonksiyon yerine engebeli bir arazi gibi, çok boyutlu bir fonksiyon düşünülürse çok sayıda yerel minimum ve maksimum olabileceği öngörülebilir.

Yerel minimumun tanımı: küçük bir $\delta$ komşuluğu seçilir. Aday çözümlerden $x^*$, $\|x - x^*\| < \delta$ olan bütün komşularına göre fonksiyonda daha küçük (veya eşit) değer veriyorsa yerel minimumdur. Şekil olarak bir yokuşun dibindeki nokta gibidir: $\delta$ civarındaki diğer bütün noktalarda fonksiyonun değeri daha yüksektir. Yerel maksimum için eşitsizlikler ters çevrilir.

### 9.4 Doğrusal olmayan en küçük kareler

En basit optimizasyon yaklaşımı olarak doğrusal olmayan en küçük kareler yöntemi kullanılır. Slayttaki tanımlar (ekrandan, 01:30:00):

- $(t_1, y_1), \dots, (t_m, y_m)$: veriler
- $M(x, t)$: uygulanan model
- $x = [x_1, x_2, \dots, x_n]^T$: modelin bağlı olduğu parametreler
- $y_i = M(x, t_i) + \epsilon_i$ koşulunu sağlayan bir $x$ olduğu varsayılır.
- $\epsilon_i$: düşey eksendeki ölçüm hataları (beyaz gürültü)

Hoca, modelin ölçülen $y_i$ değerini küçük bir $\epsilon$ hatasıyla sağlaması gerektiğini; küçük ölçüm hatalarının ve beyaz gürültünün $\epsilon$'a dahil edildiğini söyler.

Devamındaki slayt (ekrandan, 01:35:00):

- Residü: $f_i(x) = y_i - M(x, t_i)$, $t_i$ bağımsız değişken
- $x = [x_1, x_2, \dots, x_n]$: modelin bağlı olduğu parametreler
- Maliyet fonksiyonu (LSE): $F(x) = \frac{1}{2}\sum_{i=1}^{m}(f_i(x))^2$
- $F(x^*) \le F(x)$, $\|x - x^*\| < \delta$ koşulunu sağlayan bir $x^*$ bağımsız değişken vektörü bulmak hedeflenir.

Doğrusal regresyondaki "uzaklık" burada residü (artık) adını alır: modelin hesapladığı değer ile ölçülen değer arasındaki farktır. Karesel hata yazılır ve onu minimum yapan değer aranır; ancak bu artık doğrusal denklem sistemiyle yapılamaz. Doğrusal olmayan problemlerde ve optimizasyonda bu hataya maliyet fonksiyonu (cost function) denir. Aranan $x^*$ iki koşulu sağlamalıdır: fonksiyonla ilgili koşul ($F(x^*) \le F(x)$) ve normla ilgili komşuluk koşulu ($\|x - x^*\| < \delta$).

## 10. Taylor Açılımı, Gradyan ve Hessian

### 10.1 Türev formülleri nereden gelir?

Bu yaklaşımda maliyet fonksiyonunun türevlenebilir olduğu varsayılır. Hoca öğrencilere, okuldan beri bilinen $\frac{f(x+h) - f(x)}{h}$ biçimindeki ileri fark ve geri fark türev formüllerinin nereden geldiğini sorar. Bu formül belli bir noktada yaklaşık türev verir ama hata içerir. Geometrik çizimde eğimi bulmak için oluşturulan dikdörtgenin atılan yarısı hata payıdır. Matematiksel karşılığı ise Taylor serisi açılımıdır: fonksiyon $x$ noktasında $h$ kadar artım verilerek Taylor serisine açılır, her terim birinci, ikinci, üçüncü türevleri içerir ve fonksiyona bağlı olarak sonsuz terim olabilir. Hepsi hesaplanamayacağı için bir kısmı atılır; atılan kısım kabul edilen hatadır. Daha çok terim kullanıp daha az terim atılırsa daha az hatayla daha iyi bir türev yaklaşımı elde edilir. Açılımdaki birinci türev ya da ikinci türev çekilip yalnız bırakılırsa farklı, daha hassas türev formülleri elde edilebilir.

### 10.2 Çok değişkenli Taylor açılımı

Slayttaki açılım (ekrandan, 01:35:00):

$$F(x + h) = F(x) + h^T g + \frac{1}{2}h^T H h + O(\|h\|^3)$$

$$\|h\| \to \text{2-norm} \to \|h\| = \sqrt{h_1^2 + h_2^2 + \dots + h_n^2}$$

Hocanın açıklamaları:

- $T$ transpozu gösterir; $x$ ve $h$ çok değişkenlidir (vektördür).
- İlk terim fonksiyonun kendisi, ikinci terim artım miktarı çarpı $g$ ile gösterilen birinci türev, üçüncü terim $\frac{1}{2}$ çarpı artım çarpı $H$ ile gösterilen ikinci türev içerir.
- $g$'ye gradyan, $H$'ye Hessian denir.
- $O(\|h\|^3)$, ihmal edilen terimleri ve onların taşıdığı hatanın $\|h\|^3$ mertebesinde olduğunu gösterir.
- $\|h\|$, $h$'nin bileşenlerinin kareleri toplamının karekökü, yani Öklid normu (2-norm) olarak hesaplanır.

Daha çok terim kullanmak maliyet fonksiyonunu daha iyi temsil eder, ama bedeli vardır: fonksiyonun daha yüksek mertebeden türevlerinin alınabilmesi gerekir.

### 10.3 Yerel minimum ve durağan nokta

Slayttaki maddeler (ekrandan, 01:45:00):

- $x^*$ yerel minimum ve $\|h\|$ yeterince küçük ise $F$ değeri daha küçük olan bir $x^* + h$ noktası bulunamaz.
- $g^* \equiv F'(x^*) = 0 \Rightarrow x^*$ local minimizer'dır (yerel minimumdur) diyebiliriz.
- $g_s \equiv F'(x_s) = 0 \Rightarrow x_s$ durağan nokta (stationary point) olarak adlandırılır.
- Yerel minimum aynı zamanda bir durağan noktadır ama tersi her zaman doğru değildir.

Hoca, türevin sıfır olduğu başka bir durumun durağan nokta olduğunu açıklar: düzlük gibi bir yer oluşmuşsa, noktanın sağında ve solunda fonksiyon artmıyor veya azalmıyorsa oradan çizilen teğet de minimumdaki gibi yataydır. Bu yüzden durağan nokta minimum sanılabilir. Doğrusal denklem seti yazılamadığı için algoritma geliştirmek üzere matematiğin bu temel bilgilerinden yararlanıldığını söyler.

### 10.4 Hessian ile karar

İkinci türevi (Hessian'ı) de dikkate almak daha fazla çıkarım sağlar. Slayttaki tanım (ekrandan, 02:20:00): Hessian matrisi, $f$ fonksiyonunun vektörel $x$ değişkenine göre ikinci kısmi türevlerinden oluşan simetrik matristir:

$$H = f''(x) = \left[\frac{\partial^2 f}{\partial x_i \partial x_j}\right] = \begin{bmatrix} \partial^2 f/\partial x_1^2 & \partial^2 f/\partial x_1\partial x_2 & \cdots & \partial^2 f/\partial x_1\partial x_n \\ \partial^2 f/\partial x_2\partial x_1 & \partial^2 f/\partial x_2^2 & \cdots & \partial^2 f/\partial x_2\partial x_n \\ \vdots & & \ddots & \vdots \\ \partial^2 f/\partial x_n\partial x_1 & \cdots & & \partial^2 f/\partial x_n^2 \end{bmatrix}$$

- $f''(x_s)$ kesin pozitif ise $x_s$ lokal minimizer'dır ($x_s = x^*$).
- $f''(x_s)$ kesin negatif ise $x_s$ lokal maximizer'dır.
- $f''(x_s)$ belirsiz (öz değerleri $+$ ve $-$) ise $x_s$ eyer noktasıdır (saddle point).

Hoca, gradyanın sıfır olduğu aday noktada Hessian hesaplanıp kesin pozitif çıkarsa bunun yerel minimum için ciddi bir kanıt olduğunu söyler. Hessian belirsiz çıkarsa ulaşılan nokta minimum değildir; algoritma orada durdurulmayabilir ve Hessian'ın kesin pozitif olduğu bir yer aranmaya devam edilebilir. Bu, algoritmayı tasarlayanın vereceği bir karardır.

> **Ders sonrası not:** Hoca Hessian'ı "tersi kendisine eşit olan bir kare matris" diye tanımladı; doğrusu slayttaki gibi simetrik matristir, yani transpozu kendisine eşittir ($H^T = H$). Hoca kesin pozitifliği "determinantın pozitif olması" diye açıkladı; doğrusu bütün öz değerlerin pozitif olmasıdır (denk olarak bütün baş alt matris determinantlarının pozitif olması). Hoca belirsiz Hessian için "duran nokta" dedi; slayttaki doğru terim eyer noktasıdır (saddle point).

### 10.5 Yöntem aileleri

Bütün optimizasyon algoritmaları bu bilgileri kullanır:

- Yalnız gradyana (birinci türeve) bakan, işlemsel olarak daha basit yöntemler.
- Hem birinci hem ikinci türevi kullanan, işlemsel olarak daha karmaşık yöntemler.
- Türevi doğrudan almayıp yaklaşık hesaplayan, hesap karmaşıklığını azaltırken çıkarımı güçlü tutmaya çalışan yöntemler.

Hepsinin dayandığı temel aynıdır: maliyet fonksiyonu Taylor serisine açılır, birinci ve ikinci türevin durumuna bakılarak minimum bulunup bulunmadığı anlaşılır. Elimizde parabol gibi formülü sabit yapılar yerine girintili çıkıntılı, büyük olasılıkla cebirsel olarak yazılamayan fonksiyonlar olduğu için, fonksiyonun bir noktadaki türev özelliklerinden ve komşularına göre aldığı değerlerden yararlanan algoritmalar gerekir.

### 10.6 Düşüm yöntemlerinin özü

Düşüm yöntemleri hem doğrusal olmayan optimizasyonun hem de geri yayılım algoritmasının temel yaklaşımıdır. Bütün doğrusal olmayan optimizasyon yöntemleri iteratiftir: aday kümeden bir başlangıç noktası seçilir, bir vektör serisi üretilir, her nokta maliyet fonksiyonunda değerlendirilir ve noktanın minimum olup olmadığına matematiksel olarak karar verilir. Minimum olduğu anlaşılsa bile "yeterince iyi mi?" diye başka durma koşulları da tanımlanabilir.

**Soru:** Birden fazla özellik (feature) varsa $x$ vektörü matris mi olur?

**Cevap:** Burada bahsedilen şey bir özellik boyutu değil, fonksiyonu minimum yapan noktanın konumudur. Bu konum bir vektörle ifade edilir; o noktanın renk gibi özellikleri ilgilendirmez. Matris kullanmak mantığı değiştirmez ama hesapları çok karmaşıklaştırır, bu yüzden genellikle vektör kullanılır. Sinir ağlarında her özellik ayrı bir girdi olarak verilir. Örneğin harf görüntüleri bir matrise oturtulmuş olsa bile her satır peş peşe yazılarak tek bir vektör hâline getirilebilir; içerdeki bilgi matris de olsa vektör olarak ifade edilebilir.

**Soru:** Her vektör bir örnek noktası (sample point) mıdır?

**Cevap:** Burada tek sütunlu (veya tek satırlı), istenildiği kadar bileşeni olan bir vektörden söz edilir; çok sütunlu bir matristen değil. Bileşenlerin her birinin ayrı bir özellik mi olduğu, yoksa hepsinin birlikte tek bir özelliği mi ifade ettiği probleme bağlıdır. Birlikte bir şey ifade ediyorlarsa ya da ayrı özellikler olup birlikte gidiyorlarsa, vektör bütünüyle bir girdi olarak verilebilir.

## 11. İteratif Düşüm Yöntemleri ve Yakınsama

### 11.1 Düşüm koşulu ve global yakınsama

Bu yöntemlere düşüm yöntemleri denir, çünkü aday çözüm uzayından sırayla noktalar denenirken minimuma bir yaklaşıp bir uzaklaşan "dalgalı" taktikler istenmez; her yeni adayın bir öncekinden daha iyi sonuç vermesi istenir. Slayttaki maddeler (ekrandan, 02:25:00):

- Bahsedilecek tüm yöntemler iteratiftir; bir seri vektör üretirler: $x_0, x_1, x_2, \dots$
- Bu serinin bir $x^*$ lokal minimizer'a doğru yakınsaması istenir: $f: R^n \to R$, $k \to \infty$ için $x_k \to x^*$.
- Hemen hemen tüm yöntemlerde düşüm (azalma) özelliğini zorlayan ölçütler vardır: $f(x_{k+1}) < f(x_k)$.
- Bu, bir maximizer'a ya da kararsız noktaya yakınsama ihtimalini azaltır.
- Kullanılan yöntemin global yakınsama özelliği olmalıdır: $x^*$'dan uzak bir $x_0$ noktasından başlansa bile kararlı bir şekilde $x^*$ komşuluğuna yaklaşan iterasyonlar üretmelidir.
- İlk iterasyon adımları dışında hata artmıyorsa global yakınsama sağlanabilir.
- $\{e_k\}$ hataları göstermek üzere $e_k \equiv x^* - x_k$ ve $k > K$ için $\|e_{k+1}\| < \|e_k\|$.
- İterasyonun son adımlarında ($x_k$, $x^*$'a yaklaşınca) daha hızlı yakınsama beklenir.

Hoca, $f(x_{k+1}) < f(x_k)$ ifadesinin algoritmalarda genellikle bir durma koşulu ya da en azından bir kontrol olarak yer aldığını söyler. $k$, iterasyon sayısı veya denenen nokta sayısıdır. Hata vektörünün normunun giderek küçülmesi istenir.

Hoca ayrıca global minimumu bulmanın, fonksiyon engebeliyse çok uzun sürebileceğini, pratikte iyi bir yerel minimumun yeterli olduğunu söyler; bu yüzden anlatımı yerel minimum aranıyormuş gibi sürdürür. Yerel minimum için iki koşul vardır: seçilen noktada fonksiyonun değerinin küçülmesi ve bu noktanın $\delta > 0$ komşuluğundaki diğer noktalardan daha küçük değer alması.

### 11.2 Yakınsama türleri

Bir yöntem seçerken ne kadar hızlı yakınsadığına da bakılır. Üç temel yakınsama türü vardır. Hocanın sözlü anlattığı tanımlar şöyledir:

- **Doğrusal yakınsama:** $\|e_{k+1}\| \le c_1 \|e_k\|$, burada $0 < c_1 < 1$ küçük bir sabittir.
- **Karesel (kuadratik) yakınsama:** $\|e_{k+1}\| \le c_2 \|e_k\|^2$, $c_2 > 0$. Hata bir öncekinin normunun karesiyle orantılı küçüldüğü için çok daha hızlı azalır.
- **Süperdoğrusal yakınsama:** ardışık iki hatanın oranı $\|e_{k+1}\|/\|e_k\|$ sıfıra gider. Doğrusaldan iyi, karesel yakınsamadan kötüdür.

<!-- BELİRSİZ: yakınsama tanımlarının slayttaki tam yazımı karelerde görünmüyor; yukarıdaki biçim hocanın sözlü anlatımından (02:25:42-02:27:01) kuruldu. -->

Hoca, yöntemlerin çoğunun ve bu derste en çok kullanılacak gradyan düşümünün süperdoğrusal yakınsama gösterdiğini söyler.

> **Ek bilgi (derste anlatılmadı):** Standart kaynaklarda en dik iniş (steepest descent) yöntemi genellikle doğrusal yakınsama, Newton yöntemi karesel yakınsama, Quasi-Newton yöntemleri süperdoğrusal yakınsama gösterir diye geçer. Hocanın gradyan düşümü için "süperdoğrusal" demesi büyük olasılıkla genel bir ifadedir.

### 11.3 Düşüm algoritmalarının genel yapısı

Başlangıçta hata fonksiyonu hakkında bilgi olmadığı için rastgele bir $x_0$ noktasıyla başlanır. Bu nokta büyük olasılıkla minimum olmayacağından bir süre iterasyona devam etmek gerekir. Her adımda iki karar verilir: bir sonraki nokta hangi yönde olsun (düşüm yönü) ve ne kadar uzakta olsun (adım miktarı). Yeni nokta seçilir, koşulları sağlayıp sağlamadığına bakılır; sağlamıyorsa yeniden aynı şekilde yeni bir nokta seçilir. Slayttaki genel yapı (ekrandan, 02:30:00):

```text
Tahmini bir nokta ile (x0) başla
Repeat
    düşüm yönü belirle
    adım belirle
    update et
Until (durma kriteri sağlanana kadar)
```

### 11.4 Durma kriterleri

Hocanın saydığı durma kriterleri:

- Hatanın yeterince küçük olması: illa yerel minimum bulmak gerekmez; hata örneğin yüzde birin altına düştüyse yeterli sayılabilir.
- Fonksiyonun değerinin minimuma çok yakın olması: son denenen nokta ile şimdiki nokta arasında fonksiyonun değeri çok az değişiyorsa ($\tau_2$ gibi küçük bir değerle ölçülür) minimuma yeterince yaklaşılmıştır. Bu, iki noktadaki fonksiyon değerlerinin farkı ve iki noktanın birbirine uzaklığının normu cinsinden de yazılabilir.
- Türevin o noktadaki normuna bakmak ve ikinci türevli bir durma koşulu tanımlamak.

Türev için bilinen geri fark formülü ya da daha iyisi kullanılabilir; programlama dillerinin türev fonksiyonları olsa da daha iyisini kendiniz yazmak isteyebilirsiniz.

<!-- BELİRSİZ: durma kriterlerinin slayttaki formülleri (02:30:39-02:33:11) karelerde görünmüyor; yalnız sözlü anlatım aktarıldı. -->

## 12. Gradyan Düşümü ve Newton Yöntemi

### 12.1 Yöntemlerin kısa karşılaştırması

En bilinen optimizasyon (aynı zamanda arama) algoritmaları ve yapay sinir ağlarında da kullanılanlar: altın oran algoritması, gradyan düşümü, Newton, Quasi-Newton ve Levenberg-Marquardt. Hoca bunları kabaca karşılaştırır:

- **Gradyan düşümü:** En yaygın kullanılacak yöntemdir. Yalnız birinci türev hesaplamak gerekir; bu yüzden hata fonksiyonunun yalnız birinci türevinin alınabilmesi yeterlidir (ikinci, üçüncü türev mevcut olmayabilir). Uygulama alanı daha geniştir ve karmaşıklığı daha düşüktür. Bir minimum varsa, yerel de olsa, ona yakınsayabilir.
- **Newton:** İkinci derece türev kullanır. Konveks fonksiyonlarda gradyan düşümüne göre çok daha hızlı yakınsar. Ama ikinci türevin hesaplanmasını gerektirdiği için karmaşıktır; daha tehlikelisi, fonksiyon konveks değilse ve belirgin bir minimum yoksa minimumu atlayıp gereksiz yere uzayabilir. Hızlıdır ama her tip fonksiyona uygun değildir.
- **Quasi-Newton:** Newton'a benzer, aynı ailedendir.
- **Levenberg-Marquardt:** İkinci türevi doğrudan hesaplamadan yaklaşık bir değer kullanır; hesap karmaşıklığı Newton'dan iyidir. Fonksiyon konveks gibiyse (belirgin bir minimumu varsa) Newton ve Quasi-Newton'a benzer hızlı yakınsama sağlar.

### 12.2 Gradyan

Slayttaki tanım (ekrandan, 02:15:00): $f: R^n \to R$ fonksiyonu için $f(x^*) \le f(x)$, $\|x^* - x\| \le \delta$ ($\delta > 0$) koşulunu sağlıyorsa $x^*$ lokal minimizer olabilir. Gerçek lokal minimum noktasını bu gerekliliği sağlayan diğer noktalardan ayırmak için çeşitli teoremler vardır. Gradyan, $f$ fonksiyonunun vektörel bir $x$ değişkenine göre ilk kısmi türevlerinden oluşan vektördür:

$$\nabla_x f(x) = f'(x) = \begin{bmatrix} \partial f/\partial x_1 \\ \vdots \\ \partial f/\partial x_n \end{bmatrix} = \text{grad}(f)$$

- $f'(x^*) = 0 \Rightarrow$ lokal minimizer olabilir
- $f'(x_s) = 0 \Rightarrow$ durağan nokta (stationary point)

Çok değişkenli fonksiyonda adi türev değil kısmi türev düşünülür. Gradyan sıfırsa nokta yerel minimum ya da durağan nokta olabilir. Kesin karar için Hessian'a bakmak gerekir, ama gradyan düşümü buna bakmaz; büyük olasılıkla yerel minimum bulunduğunu varsayar ve durmaya fonksiyon değerinin azalması koşuluna bakarak karar verir.

**Gradyan örneği** (derste sözlü, 02:17:39): $f(x, y, z) = 2x + 3y^2 - \sin z$.

- $x$'e göre kısmi türev: ikinci ve üçüncü terim gider, $2x$'in türevi $2$'dir.
- $y$'ye göre: $3y^2$'nin türevi $6y$'dir.
- $z$'ye göre: $-\sin z$'nin türevi $-\cos z$'dir.
- Sonuç: $\nabla f = (2,\ 6y,\ -\cos z)^T$. Gradyan normalde sütun vektördür; yan yana yazılınca transpozu yazılmış olur. (Python ile sayısal türevle kontrol edildi.)

**Soru:** $x$, $y$, $z$ skaler mi?

**Cevap:** Değer verildiğinde evet, her biri skaler değer alan bağımsız değişkendir; bir arada bir vektörün skaler bileşenleri gibidir. Gradyan bir vektördür ama bileşenleri skalerdir.

### 12.3 Hessian örneği

(derste sözlü, 02:21:24) $f(x, y) = x^2 + xy + y^2$. İki değişken olduğu için değişkenlerin kombinasyonlarına göre ikinci türevler alınır:

- $\partial f/\partial x = 2x + y$; tekrar $x$'e göre: $\partial^2 f/\partial x^2 = 2$.
- $\partial^2 f/\partial x\partial y = 1$ (önce $x$'e sonra $y$'ye göre).
- Benzer şekilde $\partial f/\partial y = x + 2y$, $\partial^2 f/\partial y^2 = 2$ (ara adım eklendi).
- Sonuç:

$$H = \begin{bmatrix} 2 & 1 \\ 1 & 2 \end{bmatrix}$$

Python ile kontrol edildi; öz değerler 1 ve 3'tür, ikisi de pozitif olduğu için Hessian kesin pozitiftir.

### 12.4 Gradyan düşümünün yönü: Taylor serisinden

Hoca, gradyan düşümünün ayrıntılı algoritmasını sonraki derse bırakır ama dayandığı mantığı anlatır. Bulunulan $x$ noktasından belli bir yönde komşu bir noktaya ($x + \alpha h$) gidilir ve orada fonksiyonun değerinin $f(x)$'ten küçük olması istenir. Taylor açılımında:

$$f(x + \alpha h) = f(x) + \alpha h^T f'(x) + \dots$$

$\alpha$ küçük olduğunda ilk iki terim baskındır. İkinci terim negatif işaretliyse $f(x + \alpha h) < f(x)$ olacağı kesindir. Öndeki pozitif katsayılar atılırsa bu, $h$ ile $f'(x)$'in çarpımının negatif olması demektir. Buradan türevin (gradyanın) ters yönünün bir azalma yönü olduğu sonucu çıkar.

> **Hocanın vurgusu:** Türevin tersi yönde gidersen fonksiyonun değeri azalır. Bunun dayanağı Taylor serisidir.

Gradyan bir vektördür, dolayısıyla yönlüdür. Başındaki eksi işareti yalnız skaler olarak negatiflik anlamına gelmez; negatif yönde gidileceğini söyler. $-\nabla f(x)$ bizi minimuma doğru götüren düşüm yönüdür. Düşüm yönü $h$ için $h^T f'(x) < 0$ olmalıdır. $h$ ile gradyan arasındaki açı $\theta$ ile ifade edilirse, aramanın gradyan vektörünün tersi yönde yapılması gerektiği sonucu çıkar; adım miktarı da buna bağlı olarak belirlenebilir. Algoritma: gradyanın tersi yönde, seçilen bir adım miktarı kadar ötede yeni bir nokta seç; durma kriterleri sağlanınca son noktayı yerel minimum kabul ederek dur.

<!-- BELİRSİZ: 02:38:04-02:39:43 arasındaki açı ($\theta$) ve $\mu$ ile adım/yön koşulunun slayttaki tam formülü karelerde görünmüyor; altyazı bu kısımda bozuk. -->

### 12.5 Yerel minimuma takılma

Hoca, çok boyutlu dağlık bir hata yüzeyini iki boyutlu bir şekille anlatır. Böyle bir fonksiyona doğru veya parabol uydurarak iyi bir yaklaşım elde edilemez; doğrusal olmayan regresyon gerekir. Fonksiyonun bir global minimumu vardır, ama aramaya rastgele bir yerden başlayan bir optimizasyon yöntemi büyük olasılıkla bir yerel minimumda durur. Algoritma hep aşağı gitmek istediği için bir minimuma gelince tekrar yukarı çıkmak istemez; global minimumu bulmak için onun çevresindeki tepelerden başlamış olmak gerekir. Algoritma uzatılarak daha iyi bir minimum aranabilir, ama yerel minimum yetiyorsa hareket yönü minimuma doğru seçildiği sürece gradyan düşümü gibi bir algoritmayla bir yerel minimum bulunabilir.

### 12.6 Eş yükselti örneği: gradyan düşümü ve Newton

Slayttaki şekil (ekrandan, 02:45:00), $f(x) = 2x_1^2 + x_1x_2 + x_2^2$ fonksiyonunun eş yükselti eğrilerini ve $x^0 = (0.5, 1)$ başlangıç noktasını gösterir. Gradyan düşümünde $x^0$'dan gradyanın tersi yönde ($d^0$) belli bir adım atılarak $x^1$ seçilir; minimum koşulu sağlanmadığı için yeni yön ($d^1$) ve yeni nokta ($x^2$), sonra $d^2$ ve $x^3$ seçilir. Son seçilen $x^3$ ile $x^2$ birbirine çok yakın olmaya başlar, çünkü merkezdeki minimuma yaklaşılmıştır; burada durma koşullarına bakılır. Hoca gradyan düşümünü "güvenilir, yavaş gider ama mutlaka bir yerel minimuma gider" diye niteler.

Aynı fonksiyonda Newton yöntemi kullanılsaydı $x^0$'dan sonra seçeceği nokta doğrudan minimum olurdu (şekildeki yeşil ok); gradyan düşümünün dört adımda ulaştığı yere tek adımda gider. Hoca, fonksiyon böyle düzgün olmasaydı Newton'un "şaşırabileceğini" ekler.

Python kontrolü:

- Gradyan $\nabla f = (4x_1 + x_2,\ x_1 + 2x_2)$, $x^0$'da $(3,\ 2.5)$; Hessian $\begin{bmatrix} 4 & 1 \\ 1 & 2 \end{bmatrix}$ (öz değerler yaklaşık 4.41 ve 1.59, kesin pozitif).
- Newton adımı $x^0 - H^{-1}\nabla f(x^0) = (0, 0)$, yani tam minimum.
- Tam doğru aramalı gradyan düşümü: $x^1 \approx (-0.22,\ 0.40)$, $x^2 \approx (0.04,\ 0.08)$, $x^3 \approx (-0.02,\ 0.03)$; şekildeki zikzakla uyumludur.

> **Ek bilgi (derste anlatılmadı):** Newton yöntemi ikinci dereceden (kuadratik) bir fonksiyonda tek adımda tam minimuma ulaşır, çünkü Taylor açılımının ikinci dereceden kısmı fonksiyonun kendisidir. Konveks olmayan fonksiyonlarda Hessian kesin pozitif olmayabilir ve Newton adımı azalma yönü olmayabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 02:27:11): İki iteratif yöntem belli bir adım sonunda üç basamak doğruluğa ulaşmıştır, yani hatanın normu $10^{-3}$ mertebesindedir. Yakınsama tanımlarındaki $c_1$ ve $c_2$ katsayıları $\frac{1}{2}$ alınsın. 12 basamak doğruluk ($10^{-12}$) için doğrusal yakınsayan yöntemle ve karesel yakınsayan yöntemle kaç adım daha iterasyon gerekir?

> **Çözüm (derste verilmedi):** Doğrusal yakınsamada $\|e_{k+1}\| \le \frac{1}{2}\|e_k\|$; $n$ adım sonra $\|e\| \le 10^{-3}\cdot(1/2)^n$. $10^{-3}(1/2)^n \le 10^{-12}$ için $(1/2)^n \le 10^{-9}$, $n \ge 9\log_2 10 \approx 29.9$, yani **30 adım** gerekir. Karesel yakınsamada $\|e_{k+1}\| \le \frac{1}{2}\|e_k\|^2$: $e_1 = \frac{1}{2}(10^{-3})^2 = 5\times10^{-7}$, $e_2 = \frac{1}{2}(5\times10^{-7})^2 = 1.25\times10^{-13} < 10^{-12}$, yani **2 adım** yeterlidir. (Python ile kontrol edildi; hoca cevabın slaytlarda olduğunu söyledi, slayt karelerde görünmüyor.)

**Soru 2** (derste sözlü, 00:38:39): Afin ne demektir, doğrusal ne demektir? $ax + b$ afin midir, doğrusal mıdır?

> **Cevap (derste verildi):** Afin, ötelenmiş demektir. $f = 2x$ doğrusaldır, yalnız çarpan etkisi vardır. $f = 2x + 3$ afindir: çarpmanın yanında bir öteleme de vardır. Bu yüzden toplanabilirlik ve homojenlik koşullarını sağlamaz. Doğrusal, ötelemenin sıfır olduğu özel durumdur.

**Soru 3** (derste sözlü, 01:33:32): İleri fark ve geri fark türev formülleri nereden gelir, hata payı nedir?

> **Cevap (derste verildi):** Formüller fonksiyonun $h$ artımıyla Taylor serisine açılıp yüksek mertebeli terimlerin atılmasından gelir. Atılan terimler formülün hatasıdır; geometrik çizimde eğim için kurulan dikdörtgenin atılan kısmına karşılık gelir. Daha çok terim tutulursa daha hassas türev formülleri elde edilir.

**Soru 4** (derste sözlü, 02:17:39): $f(x, y, z) = 2x + 3y^2 - \sin z$ fonksiyonunun gradyanını bulun.

> **Cevap (derste verildi):** $\nabla f = (2,\ 6y,\ -\cos z)^T$.

**Soru 5** (derste sözlü, 02:21:24): $f(x, y) = x^2 + xy + y^2$ fonksiyonunun Hessian matrisini bulun.

> **Cevap (derste verildi):** $H = \begin{bmatrix} 2 & 1 \\ 1 & 2 \end{bmatrix}$. Öz değerleri 1 ve 3 olduğu için kesin pozitiftir (bu son cümle python ile kontrol edilerek eklendi).

**Soru 6** (ekrandan, 02:45:00): $f(x) = 2x_1^2 + x_1x_2 + x_2^2$ fonksiyonunda $x^0 = (0.5, 1)$'den başlayan Newton yöntemi ilk adımda nereye gider?

> **Çözüm (derste verilmedi):** $\nabla f(x^0) = (4\cdot0.5 + 1,\ 0.5 + 2\cdot1) = (3,\ 2.5)$, $H = \begin{bmatrix} 4 & 1 \\ 1 & 2 \end{bmatrix}$. $H^{-1}\nabla f(x^0) = (0.5,\ 1)$, dolayısıyla $x^1 = x^0 - (0.5, 1) = (0, 0)$; tek adımda minimuma ulaşılır. Hoca derste sonucu sözlü olarak "Newton ikinci noktada minimumu bulur" diye verdi; ara hesap python ile kontrol edildi.

## Dersin Toparlaması

Ders, tek katmanlı ağlardan (Hebb, Perceptron, Adaline) başlayıp delta kuralının karesel hatanın türevinden nasıl çıktığını göstererek ilerledi. Delta kuralının arkasındaki fikir, hatayı her ağırlığın hataya katkısı ölçüsünde küçültmektir. Madaline ile çok katmanlı yapıya geçiş ve XOR'un çözümü hatırlatıldı. Ardından aynı fikir regresyon üzerinden genelleştirildi: en küçük kareler yönteminde hatanın parametrelere göre kısmi türevleri sıfırlanır. Doğru, parabol, polinom ve çoklu regresyon doğrusal denklem sistemleriyle çözülebildiği için doğrusal regresyondur. Doğrusallık şekle göre değil sistemin çözülebilirliğine göre tanımlanır; afin ilişkiler doğrusal değildir.

Cebirsel çözüm mümkün olmayınca doğrusal olmayan regresyon ve optimizasyon gerekir. Maliyet fonksiyonu Taylor serisine açılır; gradyan ve Hessian, bir noktanın yerel minimum, maksimum ya da eyer noktası olup olmadığını söyler. İteratif düşüm yöntemleri her adımda fonksiyonu azaltan bir yön ve adım seçer ve durma kriterleri sağlanınca durur. Gradyanın tersi yönün azalma yönü olduğu Taylor açılımından çıkar; bu, geri yayılım algoritmasının da temelidir. Sonraki derste gradyan düşümü algoritması ayrıntılı incelenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
