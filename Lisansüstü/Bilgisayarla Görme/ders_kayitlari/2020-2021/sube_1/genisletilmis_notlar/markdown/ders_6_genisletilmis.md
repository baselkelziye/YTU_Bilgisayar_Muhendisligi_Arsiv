# Ders 6 Genişletilmiş Notu: Detektör Seçimi, Öznitelik Eşleme ve En Küçük Kareler ile Model Uydurma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İlgi Noktası Bulucularının Karşılaştırılması
- 2. Hangi Bulucu Seçilmeli?
- 3. Öznitelik Eşlemeye Giriş ve Harris Tekrarı
- 4. Öznitelikleri Eşleme ve Lowe Oran Testi
- 5. Model Uydurma ve Hizalama
- 6. En Küçük Kareler ile Doğru Uydurma
- 7. Dikey En Küçük Karelerin Sorunları ve Toplam En Küçük Kareler
- 8. En Küçük Karelerin Artı ve Eksileri
- 9. Gürbüz En Küçük Kareler
- Örnek Sorular

## 1. İlgi Noktası Bulucularının Karşılaştırılması

Ders, önceki haftada başlanan ilgi bölgesi (interest region) bulucuları sunumunun son slaytlarıyla açıldı. Bu slaytlarda bulucuların farklı koşullarda ne kadar başarılı olduğunu gösteren karşılaştırma grafikleri vardı.

İlk grafikte tekrar edilebilirlik (repeatability), bakış açısına göre çizilmişti. Bakış açısı 0 dereceden 50 dereceye doğru arttıkça tekrar edilebilirlik düşer. Hoca burada bakış açısının ne olduğunu ayrıca açıkladı: bu, imgenin kendi imge düzlemi üzerinde döndürülmesi değildir. Bakan kişinin (kameranın) yüzeye ne kadar dik ya da ne kadar yandan baktığıdır. İki imge arasındaki bakış açısı farkı büyüdükçe hem konum hem tanımlayıcı eşlemesi yavaş yavaş kötüleşir; yani tanımlayıcının başarısı, tekrar edilebilirliği düşer. Aynı grafikte en yakın tanımlayıcının doğru eşleşme yüzdesi de verilmişti.

İkinci grafikte tekrar edilebilirlik, veri tabanındaki anahtar nokta (key point) sayısına göre çizilmişti. Yatay eksen büyük olasılıkla logaritmik ölçekteydi (bin ile on bin arası). Başarı genel olarak sabit kalıyor, nokta sayısı çok arttığında biraz düşüyordu. Hocanın açıklamasıyla bunun nedeni, çok sayıda nokta olunca eşlenecek aday sayısının da artmasıdır.

## 2. Hangi Bulucu Seçilmeli?

### 2.1 Slayttaki öneriler

"Choosing a detector" slaytında şu öneriler vardı (ekrandan, 00:10:00):

- Ne için istiyorsunuz?
  - x-y düzleminde kesin konum (precise localization): Harris.
  - Ölçekte iyi konum (good localization in scale): Difference of Gaussian (DoG).
  - Esnek bölge şekli (flexible region shape): MSER.
- En iyi seçim çoğu zaman uygulamaya bağlıdır.
  - Harris-/Hessian-Laplace/DoG birçok doğal kategori için iyi çalışır.
  - MSER binalar ve basılı nesneler için iyi çalışır.
- Neden seçmek gereksin? Birden fazla bulucuyla daha çok nokta elde edilebilir.
- Kapsamlı değerlendirme ve karşılaştırmalar vardır: Mikolajczyk ve arkadaşları, IJCV'05, PAMI'05. Burada gösterilen bütün bulucular ve tanımlayıcılar iyi çalışır.

Hoca bu tavsiyelerin yıllar içinde değişmiş olabileceğini, ama genel bir fikir verdiğini söyledi. Tek bir bulucu kullanmak zorunlu değildir. Ancak birden fazla bulucu kullanılacaksa onları yazmak ya da hazır uygulamaları kendi uygulamanıza uyarlamak gerekir. Seçim için bu konudaki değerlendirme ve karşılaştırma çalışmalarının okunmasını önerdi.

### 2.2 Bulucuların sınıflandırılması

Ardından 2008 tarihli bir karşılaştırmalı yayındaki tablo gösterildi. <!-- BELİRSİZ: Yayının yazarları altyazıda "Mikolaj Zik ... Tüyle" diye geçiyor; büyük olasılıkla Tuytelaars ve Mikolajczyk'in yerel değişmez öznitelik bulucuları taraması. Tablo karede görülmedi. --> Bu tabloda bulucular şu açılardan sınıflandırılmıştı:

- Ne tür yapı buldukları: köşe, blob ya da bölge.
- Değişmezlikleri: hemen hepsi dönmeye (rotasyona) değişmez; bir kısmı ölçeğe, bir kısmı afin dönüşüme değişmezdir. Afin değişmezlik, eliptik bölgelerin de birbirleriyle eşlenebilmesi demektir.
- Dört nitelik için yıldızla puanlama: tekrar edilebilirlik, konum doğruluğu (location accuracy), gürbüzlük (robustness) ve verimlilik (efficiency).

Hoca tabloda hızın ayrıca verilmediğini, ama afin bulucuların çok yavaş çalıştığını belirtti; örneğin Harris-Affine ve Hessian-Affine yavaştır, DoG ve SURF ise oldukça hızlıdır. Afin değişmezliği sağlamak için ek işlem yapıldığından yavaşlık doğaldır. Örneğin Harris'ten Harris-Laplace'a, Harris-Laplace'tan Harris-Affine'e geçildikçe yöntem adım adım iyileştirilir.

### 2.3 Uygulamaya göre seçim

Nesne örneği tanıma (object instance recognition) ya da farklı imgeleri bir araya getirip birleştirme (stitching) yapılacaksa SIFT ya da benzeri bir yöntem kullanılabilir. Noktalar seçilirken tekrar edilebilir ve ayırt edici noktalar veren bir sistem kullanılmalı, sonra bu noktaların etrafında bir tanımlayıcı çalıştırılmalıdır. SIFT bu konuda oldukça başarılıdır.

## 3. Öznitelik Eşlemeye Giriş ve Harris Tekrarı

Dersin yeni konusu "Feature Matching and Robust Fitting" (öznitelik eşleme ve gürbüz uydurma) idi. Okuma kaynağı olarak Szeliski'nin 4.1. bölümü verildi.

### 3.1 Anahtar nokta eşlemenin genel akışı

Anahtar noktaların eşlenmesi şu adımlarla yapılır:

- Ayırt edici noktalar bulunur.
- Her noktanın etrafında bir bölge tanımlanır.
- Bölgenin içeriği çıkarılır ve normalize edilir.
- Bu bölgeden yerel bir tanımlayıcı (local descriptor) hesaplanır.
- Yerel tanımlayıcılar birbiriyle eşlenir.

### 3.2 Neden bu kadar karmaşık?

Slaytta şu soru soruluyordu: işleri neden bu kadar karmaşıklaştırıyoruz, neden yalnız x ve y yönlerinde gradyan değişimi büyük olan bölgelere bakmıyoruz? Bu soru üzerinden Harris bulucusu hatırlatıldı. Harris, x yönündeki ve y yönündeki türevleri içeren ikinci moment matrisini (second moment matrix, structure matrix) kullanır. Bu matrisin determinantı ve izinden (trace) bir köşelik ölçütü tanımlanır. Bu ölçütte en büyük değerleri veren noktalara non-max suppression uygulanarak köşeler bulunur.

Slaytta düz bölge, tek bir kenar ve köşe için structure matrisinin nasıl göründüğü örneklenmişti. <!-- BELİRSİZ: Bu üç durumdaki matris örnekleri karede yok, altyazıdan değerler okunamıyor. -->

### 3.3 Harris'in değişmezlik özellikleri

- Parlaklık değişimine (afin parlaklık değişimi) kısmen değişmezdir.
- Öteleme ve dönmede köşelerin konumu kovaryanttır: imge ötelenince ya da dönünce köşe konumları da birlikte ötelenir, döner.
- Ölçek değişiminde kovaryant değildir. Harris küçük bir kare komşulukta bakar. Ölçek büyüdüğünde bu küçük komşuluk aynı yapıyı göremez; büyütülmüş bir köşe küçük pencerede kenar gibi görünür.

Bu konular önceki haftalarda da işlendiği için slayt içinde tekrar ediliyordu. Daha önce anahtar nokta bulmaya ve o bölgeden çıkarılan tanımlayıcılara bakılmıştı; Szeliski 4.1.3'te ilgili bölümler vardır.

## 4. Öznitelikleri Eşleme ve Lowe Oran Testi

### 4.1 Basit eşleme ölçütü

Bir öznitelik diğerine ne zaman eşlenir? İlk akla gelen, en yakın komşuyu (k-en yakın komşu gibi) seçmek ve aradaki uzaklık belirli bir eşiğin altındaysa eşleşme saymaktır. Buradaki uzaklık fiziksel uzaklık değil, tanımlayıcı vektörleri arasındaki Öklid uzaklığı gibi bir uzaklıktır.

Bu yaklaşımın iki sorunu vardır:

- Eşik değeri nasıl belirlenecek?
- Ayırt edici olmayan öznitelikler birçok yakın eşleşmeye sahip olabilir; bunlardan yalnız biri doğrudur.

Önceki haftalardan bir örnek hatırlatıldı: bir bölgenin üç aday bölgeye uzaklıkları 0.34, 0.30 ve 0.40; başka bir durumda iki farklı noktaya benzerlik uzaklıkları 0.61 ve 1.22 idi. <!-- BELİRSİZ: Bu uzaklık değerleri yalnız altyazıdan; karede görülmedi. --> Uzaklıklar birbirine bu kadar yakınsa hangisinin eşleneceğine karar vermek zordur.

### 4.2 Lowe'un oran testi

David Lowe şu çözümü önermiştir: en yakın komşuya olan uzaklık, ikinci en yakın komşuya olan uzaklığa bölünür ve bu oran kullanılır.

$$
\text{oran} = \frac{d(\text{1. en yakın})}{d(\text{2. en yakın})}
$$

> **Ek bilgi (derste anlatılmadı):** Oran 1'e yakınsa en iyi aday ikinciden pek farklı değildir, eşleşme belirsizdir ve atılır. Oran küçükse en iyi aday belirgin biçimde öne çıkar ve eşleşme güvenilirdir. Lowe'un SIFT çalışmasında büyük olasılıkla 0.8 civarında bir eşik önerilmiştir.

## 5. Model Uydurma ve Hizalama

Eşlemeyi daha iyi hale getirmek için uydurma (fitting) sorusuna geçildi. Elinizde veri ve bir model var, ama modelin parametreleri bilinmiyor. Bu parametreler veriye nasıl uygun biçimde uydurulur?

Slayttaki tanımlar (ekrandan, 00:25:00):

- **Fitting (uydurma):** veriye en iyi uyan modelin parametrelerini bulmak.
- **Alignment (hizalama):** eşleşen noktaları en iyi hizalayan dönüşümün parametrelerini bulmak.

Hizalamayı hoca şöyle örnekledi: iki imgede bir noktanın diğerine eşlendiğini söylüyorsanız, bunun için bir dönüşüm düşünmeniz gerekir; şurası dönüşüme uğrayıp buraya gelmiştir. O dönüşümün parametrelerini bulmak hizalamadır.

### 5.1 Tasarım soruları

Hoca bunun bir algoritma ya da sistem tasarımı olduğunu belirtti. İki şey tasarlanmalıdır:

- İyi bir uygunluk (goodness of fit) ölçüsü.
  - Benzerlik, uygulamanın amacını yansıtmalıdır.
  - Aykırı değerlere (outlier, istatistikte ortalamadan çok uzak olan değerler) ve gürültüye karşı gürbüzlük bu ölçüye kodlanmalıdır.
- Bir optimizasyon yöntemi.
  - Yerel optimumlardan uzak durmalıdır; bu optimizasyonda genel bir sorundur.
  - Hızlı olmalı, parametrelerin uygun değerlerini çabuk bulmalıdır.

### 5.2 Yöntem aileleri

- Global optimizasyon ya da parametre arama: en küçük kareler uydurması (least squares fit).
- Gürbüz en küçük kareler (robust least squares) ve Iterative Closest Point (ICP): en küçük kareler üzerine kurulmuş daha ileri yöntemler.
- Hipotez üret ve test et: genelleştirilmiş Hough dönüşümü ve RANSAC.

## 6. En Küçük Kareler ile Doğru Uydurma

Örnek olarak bir doğru uydurma problemi ele alındı. Bu bölümde hoca slaytı tablet üzerinde açıp üzerine çizerek anlattı.

### 6.1 Problem

Slayttaki tanım (ekrandan, 00:35:00):

- Veri: $(x_1,y_1),\dots,(x_n,y_n)$
- Doğru denklemi: $y_i = m x_i + b$
- $(m,b)$ öyle bulunsun ki şu hata en küçük olsun:

$$
E=\sum_{i=1}^{n}(y_i - m x_i - b)^2
$$

Modelimiz bir doğrudur; parametreleri $m$ ve $b$'dir. Fikir şudur: $x$ bağımsız değişkendir. Her $x_i$ için modelin vereceği değer $m x_i + b$'dir. Gerçek değer $y_i$ ile modelin değeri arasındaki fark, o noktanın hatasıdır. Hoca bunu çizimde $y_i-(m x_i+b)$ diye parantezle gösterdi (ekrandan, 00:35:00). Toplam hata, bütün noktalar üzerinden bu hataların karelerinin toplamıdır.

### 6.2 Neden kare alınıyor?

Hoca iki neden verdi:

- Farklar bazen negatif bazen pozitif çıkar. Toplandığında birbirlerini götürmemeleri için hepsi pozitife çevrilmelidir. Bunun için mutlak değer ya da kare kullanılabilir.
- Karenin türevi kolaydır: $x^2$'nin türevi $2x$'tir (hoca bunu slaytın kenarına yazdı, ekrandan 00:35:00). Mutlak değerin türevi ise daha zahmetlidir.

Sinir ağlarıyla çalışanların bildiği gibi başka hata fonksiyonları da tanımlanabilir.

### 6.3 Matris biçimine geçiş

Toplamı matris çarpımlarıyla yazmak için önce tek bir terime bakıldı. $[x_i\;\;1]$ satır vektörü ile $[m\;\;b]^T$ sütun vektörü çarpılırsa $m x_i + b$ çıkar. Ondan $y_i$ çıkarılır. Farkın sırası önemli değildir, çünkü karesi alınacaktır; $y_i - (m x_i+b)$ ya da $(m x_i+b) - y_i$ aynı sonucu verir.

Bütün veri alt alta dizilince toplam tek bir matris çarpımına dönüşür (ekrandan, 00:40:00):

$$
E=\sum_{i=1}^{n}\left(\begin{bmatrix}x_i & 1\end{bmatrix}\begin{bmatrix}m\\ b\end{bmatrix}-y_i\right)^2
=\left\lVert\begin{bmatrix}x_1 & 1\\ \vdots & \vdots\\ x_n & 1\end{bmatrix}\begin{bmatrix}m\\ b\end{bmatrix}-\begin{bmatrix}y_1\\ \vdots\\ y_n\end{bmatrix}\right\rVert^2
=\lVert\mathbf{A}\mathbf{p}-\mathbf{y}\rVert^2
$$

Çarpım sonucunda elemanları $m x_1 + b - y_1$, $m x_2 + b - y_2$, ... olan bir vektör oluşur. Dıştaki çift çizgi vektör normudur. Hoca normu öğrencilere sordu: $(a,b)$ gibi bir vektörün normu $\sqrt{a^2+b^2}$'dir; başka bileşenler varsa onların kareleri de eklenir (hoca bunu tahtaya $\lVert\langle a,b\rangle\rVert=\sqrt{a^2+b^2}$ diye yazdı, ekrandan 00:45:00). Normun üzerine kare konunca karekök gider ve geriye bileşen karelerinin toplamı kalır. Böylece dıştaki toplama işlemi norm işlemiyle yapılmış olur.

Adlandırmalar: $\mathbf{A}$ veri matrisi, $\mathbf{p}=[m\;\;b]^T$ bulunacak parametre vektörü, $\mathbf{y}$ gerçek $y$ değerlerinden oluşan vektördür.

Matris ve vektörlere geçmenin iki avantajı vardır: uzun uzun yazmak yerine kısa yazılır ve Matlab ya da Python kütüphaneleri gibi matrislerle çok hızlı çalışan araçlar doğrudan kullanılabilir.

**Soru:** Büyük harf ve küçük harf ayrımı matris ve vektör anlamına mı geliyor? **Cevap:** Bu kaynağa göre değişir. Bu slaytta kalın yazılanlar matris ya da vektör, kalın olmayanlar skalerdir. Bazı kaynaklar vektörün üstüne ok koyar. Burada matrisler büyük, vektörler küçük kalın harfle yazılmış; bu yaygın bir gösterimdir ama yazardan yazara değişebilir.

### 6.4 Açılım

Parametre optimizasyonunda parametreye göre türev alınıp sıfıra eşitlenir. Bunun için önce norm karesi açılır (ekrandan, 00:45:00):

$$
E=\mathbf{y}^T\mathbf{y}-2(\mathbf{A}\mathbf{p})^T\mathbf{y}+(\mathbf{A}\mathbf{p})^T(\mathbf{A}\mathbf{p})
$$

Hoca bu açılımın nereden geldiğini sordu; bir öğrenci $(a-b)^2$ binom açılımına benzediğini söyledi. Gerçekten de $\mathbf{y}^T\mathbf{y}$ birincinin karesine, $(\mathbf{A}\mathbf{p})^T(\mathbf{A}\mathbf{p})$ ikincinin karesine, ortadaki terim de "2 çarpı birinci çarpı ikinci"ye karşılık gelir.

Hoca bu tür eşitliklerin bileşenler cinsinden yeniden yazılarak kolayca doğrulanabileceğini gösterdi:

- $\mathbf{y}^T\mathbf{y}=y_1^2+y_2^2+\dots+y_n^2$.
- $\mathbf{A}\mathbf{p}$, elemanları $m x_1+b,\ m x_2+b,\dots$ olan vektördür. $(\mathbf{A}\mathbf{p})^T\mathbf{y}$ çarpımı $y_1(m x_1+b)+y_2(m x_2+b)+\dots$ terimlerini verir.
- $(\mathbf{A}\mathbf{p})^T(\mathbf{A}\mathbf{p})=(m x_1+b)^2+(m x_2+b)^2+\dots$

Bunlar toparlanınca her $i$ için $(y_i-m x_i-b)^2$ açılımı elde edilir. Hoca bu denetimi evde yapmayı önerdi.

> **Ders sonrası not:** Açılım rastgele bir veri ve rastgele bir $\mathbf{p}$ ile python'da denendi; $\sum(y_i-m x_i-b)^2$ ile $\mathbf{y}^T\mathbf{y}-2(\mathbf{A}\mathbf{p})^T\mathbf{y}+(\mathbf{A}\mathbf{p})^T(\mathbf{A}\mathbf{p})$ aynı değeri verdi.

### 6.5 Türev ve normal denklem

$\mathbf{p}$ vektörüne göre türev alınır (ekrandan, 00:50:00):

$$
\frac{dE}{d\mathbf{p}}=2\mathbf{A}^T\mathbf{A}\mathbf{p}-2\mathbf{A}^T\mathbf{y}=0
$$

Hoca vektöre göre türev almanın vektör kalkülüsü konusu olduğunu, kendisinin bunu çok kullanmadığını söyleyip terimlerin nasıl dönüştüğünü sezgisel olarak açıkladı:

- $\mathbf{y}^T\mathbf{y}$ terimi $\mathbf{p}$ içermez, türevde sıfır olur (hoca bunun üstüne 0 yazdı, ekrandan 00:50:00).
- $-2(\mathbf{A}\mathbf{p})^T\mathbf{y}$ teriminde $\mathbf{p}$ birinci derecededir; türevde $\mathbf{p}$ gider, $-2\mathbf{A}^T\mathbf{y}$ kalır.
- $(\mathbf{A}\mathbf{p})^T(\mathbf{A}\mathbf{p})$ teriminde $\mathbf{p}$ "kare" gibidir; türevde bir $\mathbf{p}$ kalır ve kareden gelen 2 öne geçer: $2\mathbf{A}^T\mathbf{A}\mathbf{p}$.

Sonra terimlerden biri eşitliğin öbür tarafına atılır ve $\mathbf{p}$ yalnız bırakılmak için her iki taraf soldan $(\mathbf{A}^T\mathbf{A})^{-1}$ ile çarpılır (ekrandan, 00:55:00):

$$
\mathbf{A}^T\mathbf{A}\mathbf{p}=\mathbf{A}^T\mathbf{y}\;\Rightarrow\;\mathbf{p}=(\mathbf{A}^T\mathbf{A})^{-1}\mathbf{A}^T\mathbf{y}
$$

Sonuç çok basittir: $\mathbf{A}$'nın transpozu kendisiyle çarpılır, tersi alınır, yeniden $\mathbf{A}^T$ ile ve $\mathbf{y}$ ile çarpılır; tahmini parametreler doğrudan çıkar.

### 6.6 Hazır araçlar ve tekillik

Slaytta hazır araçlar da verilmişti (ekrandan, 00:35:00):

```text
Matlab: p = A \ y;
Python: see example for numpy.linalg.lstsq
```

Hoca NumPy'daki bu fonksiyonun en küçük kareler çözümünü doğrudan yaptığını, tanımına bakılabileceğini söyledi. Matlab'daki işleç de büyük olasılıkla bunu yapar; belki matrisin yapısına göre yinelemeli yöntemler de kullanıyor olabilir.

> **Hocanın vurgusu:** Ters matris alma bu tür işlerde sorun olabilir. Elinizdeki verinin durumuna göre $\mathbf{A}^T\mathbf{A}$ tekil (singular) ya da tuhaf matrisler çıkabilir.

> **Ders sonrası not:** Kapalı çözüm $(\mathbf{A}^T\mathbf{A})^{-1}\mathbf{A}^T\mathbf{y}$ ile `numpy.linalg.lstsq(A, y)` rastgele üretilmiş bir veri üzerinde python'da karşılaştırıldı; iki yöntem aynı $(m,b)$ değerlerini verdi.

```python
import numpy as np
# x, y: veri vektörleri
A = np.c_[x, np.ones_like(x)]          # satırlar [x_i, 1]
p = np.linalg.inv(A.T @ A) @ A.T @ y   # normal denklem
p2 = np.linalg.lstsq(A, y, rcond=None)[0]
```

Bu kod derste yazılmadı; slayttaki formül ve `numpy.linalg.lstsq` göndermesine göre ajan tarafından yazılıp denendi.

### 6.7 Doğrusal regresyonla ilişkisi

Bir öğrencinin yorumu üzerine hoca bunun doğrusal regresyondaki yöntemin aynısı olduğunu onayladı. Burada tek bir $x$ var, ama $x_1, x_2, x_3$ gibi çok boyutlu girdiler için de aynı formülasyon geçerlidir. Daha karmaşık bir model uydurulduğunda parametreler yalnız $m$ ve $b$ olmaz, daha fazla parametre olur; ama genel mantık aynıdır.

## 7. Dikey En Küçük Karelerin Sorunları ve Toplam En Küçük Kareler

### 7.1 Dikey en küçük kareler neden sorunlu?

Yukarıdaki yöntemde hata, noktanın doğruya $y$ yönündeki (dikey) uzaklığıyla ölçülür. Slayta göre bunun iki sorunu vardır:

- Dönmeye değişmez değildir.
- Dikey doğrularda başarısız olur. Noktalar dikey bir doğru boyunca diziliyorsa $y=mx+b$ modeli bu doğruyu ifade edemez.

### 7.2 Dik uzaklık

Toplam en küçük karelerde (total least squares) noktanın doğruya gerçek dik uzaklığı kullanılır. Doğru bu kez $ax+by+c=0$ biçiminde yazılır; parametre sayısı ikiden üçe çıkar ve amaç $a,b,c$'yi bulmaktır.

Slayttaki bilgi (ekrandan, 02:35:00):

- Doğru: $ax+by+c=0$, birim normal $N=(a,b)$.
- $a^2+b^2=1$ ise $(x_i,y_i)$ noktasının doğruya uzaklığı $|ax_i+by_i+c|$'dir.
- Kanıt için slaytta MathWorld'ün "Point-Line Distance 2-Dimensional" sayfasına bağlantı verilmişti.

### 7.3 Hata fonksiyonu ve $c$'nin bulunması

Slayttaki türetme (ekrandan, 02:40:00): dik uzaklıkların karelerinin toplamını en küçük yapan $(a,b,c)$ aranır.

$$
E=\sum_{i=1}^{n}(ax_i+by_i+c)^2
$$

Önce yalnız $c$'ye göre türev alınıp sıfıra eşitlenir:

$$
\frac{\partial E}{\partial c}=\sum_{i=1}^{n}2(ax_i+by_i+c)=0
\;\Rightarrow\;
c=-\frac{a}{n}\sum_{i=1}^{n}x_i-\frac{b}{n}\sum_{i=1}^{n}y_i=-a\bar{x}-b\bar{y}
$$

Hoca bunu birlikte çözdü: $x$'ler toplanıp $n$'e bölününce $x$'lerin ortalaması $\bar{x}$ çıkar; böylece $c$, eksi $a$ çarpı $x$ ortalaması eksi $b$ çarpı $y$ ortalaması olur. Yani $c$ tek başına kolayca çözülebilmektedir. Bu $c$ hata ifadesine yerine yazılır ve $a$, $b$'ye dağıtılırsa:

$$
E=\sum_{i=1}^{n}\big(a(x_i-\bar{x})+b(y_i-\bar{y})\big)^2
=\left\lVert\begin{bmatrix}x_1-\bar{x} & y_1-\bar{y}\\ \vdots & \vdots\\ x_n-\bar{x} & y_n-\bar{y}\end{bmatrix}\begin{bmatrix}a\\ b\end{bmatrix}\right\rVert^2
=\mathbf{p}^T\mathbf{A}^T\mathbf{A}\mathbf{p}
$$

Burada $\mathbf{A}$ merkezlenmiş veri matrisi, $\mathbf{p}=[a\;\;b]^T$ aranan parametrelerdir.

### 7.4 Kısıtlı en küçükleme ve özvektör çözümü

$a^2+b^2=1$ koşulu $\mathbf{p}^T\mathbf{p}=1$ demektir. Problem şöyle yazılır (ekrandan, 02:40:00):

$$
\text{minimize } \mathbf{p}^T\mathbf{A}^T\mathbf{A}\mathbf{p}\quad \text{s.t. } \mathbf{p}^T\mathbf{p}=1
\;\Rightarrow\;
\text{minimize } \frac{\mathbf{p}^T\mathbf{A}^T\mathbf{A}\mathbf{p}}{\mathbf{p}^T\mathbf{p}}
$$

Çözüm, $\mathbf{A}^T\mathbf{A}$'nın en küçük özdeğerine karşılık gelen özvektördür. Ayrıntılar için slaytta Rayleigh bölümü (Rayleigh quotient) bağlantısı verilmişti. Hoca bunun için doğrusal cebir bilmek gerektiğini belirtti.

Hoca $\mathbf{x}^T\mathbf{x}=1$ koşulunun ne anlama geldiğini sordu: bileşenlerin karelerinin toplamının 1 olması, vektörün birim çember (genel boyutta hiperküre yüzeyi) üzerinde olması demektir. Bu kısıt olmasaydı $\mathbf{p}=\mathbf{0}$ önemsiz (trivial) çözümü hatayı sıfır yapardı; kısıt, sıfırdan farklı bir çözüm bulunmasını sağlar.

> **Ders sonrası not:** Yöntem python'da rastgele üretilmiş bir doğru verisiyle denendi: merkezlenmiş verinin $\mathbf{A}^T\mathbf{A}$ matrisinin en küçük özdeğerine ait özvektörden bulunan $(a,b)$ ve $c=-a\bar{x}-b\bar{y}$, veriyi üreten doğruya çok yakın bir doğru verdi.

### 7.5 İki optimizasyon problemi

Hoca dersin bu kısmında en küçük karelerin iki farklı biçimde kullanıldığını özetledi:

- $\lVert\mathbf{A}\mathbf{x}-\mathbf{b}\rVert^2$'yi en küçükle. Çözüm normal denklemden ya da Matlab'daki `A \ b` gibi hazır araçlarla bulunur; bu, en küçük kareler çözümüdür.
- $\mathbf{x}^T\mathbf{A}^T\mathbf{A}\mathbf{x}$'i $\mathbf{x}^T\mathbf{x}=1$ kısıtıyla en küçükle. Bu, $\mathbf{A}\mathbf{x}=\mathbf{0}$ için önemsiz olmayan çözüm aramaktır ve özvektörlerle çözülür.

## 8. En Küçük Karelerin Artı ve Eksileri

En küçük kareler bir global optimizasyon yöntemidir.

Artıları:

- Açıkça tanımlanmış bir amaç fonksiyonu vardır.
- Optimizasyon kolaydır; sonuç matris çarpımlarıyla bulunur, bir bakıma analitik çözümü vardır.

Eksileri:

- Optimize edilmek istenen şey bu olmayabilir.
- Aykırı değerlere duyarlıdır. Ortalamadan çok farklı değerler sonucu çok değiştirebilir.
- Birden fazla iyi uydurma seçeneği vermez, yalnız bir tane verir. Oysa 5-10 farklı uydurma (hipotez) verse ve bunlar test edilip seçilse belki daha iyi olurdu.

### 8.1 Aykırı değerin etkisi

"Least squares: Robustness to noise" slaytında bir grafik vardı (ekrandan, 02:45:00). Kırmızı noktalar yaklaşık $x=-1$ ile $x=1$ arasında, eğimli bir doğru boyunca diziliydi. Sağda, yaklaşık $(6,-0.5)$ civarında tek bir aykırı nokta vardı. Bu noktayla birlikte uydurulan mavi doğru, kırmızı noktaların doğrultusundan belirgin biçimde sapıp yatıklaşmıştı. Slayttaki sonuç: "Problem: squared error heavily penalizes outliers", yani kare hata aykırı değerleri çok ağır cezalandırır. Uzak bir noktanın hatası karesi alındığı için çok büyür ve çözümü kendine doğru çeker.

## 9. Gürbüz En Küçük Kareler

Aykırı değerlerden bu kadar etkilenmeyen yönteme gürbüz en küçük kareler (robust least squares) denir. Genel yaklaşım, kare yerine gürbüz bir fonksiyon kullanmaktır:

$$
\min_{\theta}\ \sum_i \rho\big(u_i(x_i,\theta);\sigma\big)
$$

- $\rho$: gürbüz fonksiyon.
- $\sigma$: ölçek parametresi.
- $u_i(x_i,\theta)$: $i$. noktanın, model parametreleri $\theta$'ya göre artığı (residual).

<!-- BELİRSİZ: Bu formül altyazıdaki okumadan kuruldu; slaytın karesi yok, ρ'nun açık biçimi derste söylenmedi. -->

> **Ek bilgi (derste anlatılmadı):** Lazebnik'in slaytlarında büyük olasılıkla $\rho(u;\sigma)=\dfrac{u^2}{\sigma^2+u^2}$ kullanılır. Bu fonksiyon küçük artıklarda kareye benzer davranır, büyük artıklarda ise 1'e doyar. Böylece çok uzaktaki bir noktanın hataya katkısı sınırlı kalır.

Hoca bu formülü ayrıntılı bilmediğini, burada temel bir giriş yapıldığını ve konunun ayrıca araştırılabileceğini söyledi. Slayttaki örnekte kırmızı bir aykırı nokta olmasına rağmen gürbüz uydurmada onun etkisi en aza indirilmişti.

### 9.1 Ölçek seçimi

Ölçek parametresi $\sigma$ düzgün seçilmezse yöntem doğru sonuç vermez. Ölçek çok küçük ya da çok büyük seçildiğinde sorun çıkar; bu yüzden gürbüz uydurmada bir ölçek bulma derdi vardır.

### 9.2 Çözüm yöntemi

Slayta göre gürbüz uydurma doğrusal olmayan bir optimizasyon problemidir ve yinelemeli olarak çözülmelidir:

- En küçük kareler çözümünden başlanır.
- Newton ya da en dik iniş (steepest descent) gibi yinelemeli optimizasyon algoritmalarıyla devam edilir.
- Ölçek, artıkların medyanına (median residual) göre uyarlamalı olarak seçilebilir.

> **Ek bilgi (derste anlatılmadı):** Uyarlamalı ölçek seçiminde büyük olasılıkla her yinelemede $\sigma$, artıkların mutlak değerlerinin medyanıyla orantılı alınır (ör. $\sigma \approx 1.5\cdot\mathrm{medyan}|u_i|$). Medyan aykırı değerlerden az etkilendiği için ölçek tahmini de gürbüz olur.

Konu burada bırakıldı; gürbüz uydurmaya sonraki derste devam edileceği söylendi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:40:12). $(a,b)$ gibi bir vektörün normu nasıl hesaplanır? Bu, en küçük kareler hatasını $\lVert\mathbf{A}\mathbf{p}-\mathbf{y}\rVert^2$ biçiminde yazmayı neden mümkün kılar?

> **Çözüm:** $\lVert(a,b)\rVert=\sqrt{a^2+b^2}$; daha fazla bileşen varsa onların kareleri de eklenir. Normun karesi alınınca karekök gider ve bileşen karelerinin toplamı kalır. $\mathbf{A}\mathbf{p}-\mathbf{y}$ vektörünün bileşenleri $m x_i+b-y_i$ olduğundan, norm karesi tam olarak $\sum_i (y_i-m x_i-b)^2$'ye eşittir.

**Soru 2** (derste sözlü, 00:34:33). En küçük kareler hatasında farkların neden karesi alınıyor? Mutlak değer neden tercih edilmiyor?

> **Çözüm:** Farklar pozitif ya da negatif olabilir; karesi alınmazsa toplamda birbirlerini götürür. Mutlak değer de bu sorunu çözer, ama karenin türevi ($x^2 \to 2x$) çok daha kolaydır; mutlak değerin türevi sıfırda tanımsız ve zahmetlidir.

**Soru 3** (ekrandan, 00:45:00; derste sözlü, 00:45:27). $E=\lVert\mathbf{A}\mathbf{p}-\mathbf{y}\rVert^2$ ifadesinin $\mathbf{y}^T\mathbf{y}-2(\mathbf{A}\mathbf{p})^T\mathbf{y}+(\mathbf{A}\mathbf{p})^T(\mathbf{A}\mathbf{p})$ biçimine nasıl açıldığını açıklayın ve $\mathbf{p}$'yi bulun.

> **Çözüm:** $E=(\mathbf{A}\mathbf{p}-\mathbf{y})^T(\mathbf{A}\mathbf{p}-\mathbf{y})$; bu, $(a-b)^2=a^2-2ab+b^2$ binom açılımına benzer biçimde açılır ($(\mathbf{A}\mathbf{p})^T\mathbf{y}=\mathbf{y}^T\mathbf{A}\mathbf{p}$ skaler olduğu için iki çapraz terim birleşir). $\mathbf{p}$'ye göre türev: $2\mathbf{A}^T\mathbf{A}\mathbf{p}-2\mathbf{A}^T\mathbf{y}=0$, buradan $\mathbf{p}=(\mathbf{A}^T\mathbf{A})^{-1}\mathbf{A}^T\mathbf{y}$ (ekrandan, 00:50:00). Açılım ve çözüm python ile sayısal olarak doğrulandı.

**Soru 4** (derste sözlü, 02:42:29). $\mathbf{x}$ vektörünün bileşenlerinin karelerinin toplamının 1 olması ($\mathbf{x}^T\mathbf{x}=1$) geometrik olarak neyi verir? Toplam en küçük karelerde bu kısıt neden gerekir?

> **Çözüm:** İki boyutta birim çemberi, genel boyutta birim hiperkürenin yüzeyini verir. Kısıt olmasaydı $\mathbf{p}^T\mathbf{A}^T\mathbf{A}\mathbf{p}$ ifadesi $\mathbf{p}=\mathbf{0}$ ile sıfır yapılırdı; kısıt önemsiz çözümü dışlar ve çözüm $\mathbf{A}^T\mathbf{A}$'nın en küçük özdeğerine ait birim özvektör olur.

**Soru 5** (ekrandan, 02:40:00). Toplam en küçük karelerde $E=\sum(ax_i+by_i+c)^2$ için $c$'yi bulun.

> **Çözüm:** $\frac{\partial E}{\partial c}=\sum 2(ax_i+by_i+c)=0 \Rightarrow a\sum x_i+b\sum y_i+nc=0 \Rightarrow c=-a\bar{x}-b\bar{y}$.

**Soru 6** (ekrandan, 02:35:00; derste sözlü, 02:34:33). Dikey uzaklıkla kurulan en küçük kareler doğru uydurması neden sorunludur?

> **Çözüm:** Dönmeye değişmez değildir; veri döndürülünce farklı bir doğru elde edilebilir. Ayrıca dikey doğruları ifade edemez, çünkü $y=mx+b$ modelinde dikey doğru için $m$ sonsuz olur. Toplam en küçük kareler bu sorunu dik uzaklık ve $ax+by+c=0$ modeliyle çözer.

## Dersin Toparlaması

Ders, ilgi noktası bulucularının karşılaştırmasıyla başladı: Harris kesin konum, DoG ölçek, MSER esnek bölge şekli için önerildi; seçimin uygulamaya bağlı olduğu ve birden fazla bulucunun birlikte kullanılabileceği vurgulandı. Ardından öznitelik eşlemenin genel akışı (nokta bul, bölge tanımla, normalize et, tanımlayıcı hesapla, eşle) ve en yakın komşu eşlemesinin belirsizliğine karşı Lowe'un oran testi anlatıldı.

Dersin ağırlıklı kısmı model uydurmaydı. En küçük kareler ile doğru uydurmada hata matris biçiminde $\lVert\mathbf{A}\mathbf{p}-\mathbf{y}\rVert^2$ yazıldı, açıldı, türevi alınarak normal denklem ve $\mathbf{p}=(\mathbf{A}^T\mathbf{A})^{-1}\mathbf{A}^T\mathbf{y}$ çözümü elde edildi. Dikey en küçük karelerin dönmeye değişmez olmaması ve dikey doğrularda başarısız olması nedeniyle dik uzaklığa dayanan toplam en küçük kareler ve özvektör çözümü görüldü. Son olarak en küçük karelerin aykırı değerlere duyarlılığı ve buna karşı ölçek parametreli gürbüz fonksiyon kullanan, yinelemeli çözülen gürbüz en küçük kareler tanıtıldı. Gürbüz uydurmaya sonraki derste devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
