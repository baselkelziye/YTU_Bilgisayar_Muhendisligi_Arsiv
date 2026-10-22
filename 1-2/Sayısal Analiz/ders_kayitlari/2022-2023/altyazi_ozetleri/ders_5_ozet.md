# Ders 5 Çalışma Özeti

## Genel Konular

- Proje duyuruları
  - Projede istenenleri anlatan belge (kodlanacak algoritmalar, teslim tarihi, projenin not yüzdesi, kontrol zamanı) ve Ahmet Hoca'nın hazırladığı rapor şablonu e-postayla gönderildi.
  - Online Yıldız (online.yildiz.edu.tr) üzerinde "Proje" sayfası açıldı. Proje ilgili forma yüklenecek. Rapor kapak sayfasına imzanızı koyun.
  - Dersi not yükseltmek için tekrar alanlar da sunum yapmak zorundadır, sunum yapmayan projeden not alamaz. Geçen yılın kodunu vermek yerine, algoritmik düşüncenizin geliştiğine inanıyorsanız yeniden kodlamanız önerilir.
  - Yaklaşık 10 algoritma var. Sınıf 100 kişilik olduğu için hoca herkesin bütün algoritmalarına bakamaz. Her öğrenciden 1-2 algoritma seçip çalıştırmasını isteyecek. Gösterilen algoritma çalışırsa hepsi doğru kabul edilir. Çalışmazsa diğerleri de çalışmıyor kabul edilir.
  - Raporda 2 satır, 10 sütunluk bir tablo var. Yaptığınız algoritmaya 1, yapamadığınıza 0 yazın. Çalıştığından emin olmadığınız algoritmaya "yaptım" demeyin.
  - Bu yıl bütün yöntemler tek bir programda toplanacak: bir menü açılır, seçilen yönteme göre (ör. `switch-case` ile) dallanılır. 10 ayrı program verilmez.
  - O an hangi programlama dilini görüyorsanız onu kullanabilirsiniz. Fonksiyon kullanmak serbesttir.
  - "Bir bilgisayar mühendisi `break`, `goto` kullanmaz." Çok istisnai durumlar dışında `break`, `exit`, `goto` kullanmayın.
  - Kodu tek bir değerle deneyip bırakmayın. Uç durumları test edin. Örneğin kökü 2 olan bir fonksiyon için $[2.5, 3]$ aralığı verilirse program "bu aralıkta kök yok" demelidir. $[1.98, 2.1]$ gibi dar bir aralıkta takılıp takılmadığına bakın.
  - Diğer grup birkaç hafta önde. İsterseniz o grubun ders videolarındaki örnekleri de dinleyebilirsiniz.
  - Hoca kendi öğrenciliğinden bahseder: birinci dönem algoritma kuramadığı için çok zorlanmış, bırakmayı düşünmüş, yazılmış programları analiz ederek ilerlemiş. Pes etmeyin, en sevdiğiniz konuları belirleyip onlarda iyi olun, bilgiyi birbirinizden saklamayın.
- Cholesky (yoğunlaştırılmış yok etme) yöntemi
  - Dolaysız yöntemlerin sonuncusudur. Mantık lineer cebirdekiyle aynıdır.
  - $A$ katsayılar matrisi bir alt üçgen matris $L$ ile köşegeni 1 olan bir üst üçgen matris $U$'nun çarpımına ayrılır: $A = LU$.
  - $AX = C$ yerine $LUX = C$ yazılır. $UX = Y$ denirse:
    - Önce $LY = C$ çözülür ve $Y$ bulunur (ileri yerine koyma).
    - Sonra $UX = Y$ çözülür ve $X$ bulunur (geri yerine koyma).
  - $L$ ve $U$'nun elemanları $LU$ çarpımı $A$'ya eşitlenerek bulunur. Satır satır çarpılır, önceki adımda bulunan değerler yerine konur:
    - $L_{11} = a_{11}$, $L_{11} U_{12} = a_{12}$, $L_{11} U_{13} = a_{13}$.
    - $L_{21} = a_{21}$, $L_{21} U_{12} + L_{22} = a_{22}$, $L_{21} U_{13} + L_{22} U_{23} = a_{23}$.
    - $L_{31} = a_{31}$, $L_{31} U_{12} + L_{32} = a_{32}$, $L_{31} U_{13} + L_{32} U_{23} + L_{33} = a_{33}$.
  - Formülleri ezberlemeye gerek yok. Alt üçgen $L$'yi ve köşegeni 1 olan üst üçgen $U$'yu yazıp çarpın, $A$'ya eşitleyin.
  - Neden geliştirildi? Matrisi iki üçgen parçaya ayırınca bazı elemanlar sıfır olur. Daha az çarpma ve toplama yapılır, işlem hızlanır.
  - Örnek (geçen haftaki Gauss örneği): $3.6x + 2.4y - 1.8z = 6.3$, $4.2x - 5.8y + 2.1z = 7.5$, $0.8x + 3.5y + 6.5z = 3.7$.
    - $L_{11} = 3.6$, $U_{12} = 0.67$, $U_{13} = -0.5$.
    - $L_{21} = 4.2$, $L_{22} = -5.8 - 4.2 \cdot 0.67 = -8.6$, $U_{23} = -0.49$.
    - $L_{31} = 0.8$, $L_{32} = 2.96$, $L_{33} = 8.4$.
    - $LY = C$: $y_1 = 1.75$, $y_2 = -0.02$, $y_3 = 0.28$.
    - $UX = Y$: $x_3 = 0.28$, $x_2 = 0.12$, $x_1 = 1.81$. Sonuç Gauss eliminasyonuyla aynıdır.
- Dolaylı (iteratif) yöntemler
  - Her adımda bir önceki adımda bulunan bilinmeyen değerleri kullanılır. Kabul edilebilir değerlere ulaşılınca durulur.
  - Hocaya göre dolaylı yöntemler dolaysız yöntemlerden çok daha kolaydır ve sonuca hızlı gider.
- Jacobi iterasyonu
  - $n$ bilinmeyen, $n$ denklem (kare matris).
  - 1. adım (en önemli adım): denklemlerin yerleri, köşegendeki katsayıların mutlak değerce çarpımı en büyük olacak şekilde değiştirilir. Bu yapılmadan da çözülür ama çözüm yanlış çıkar.
    - Pratik yol: her sütundaki mutlak değerce en büyük katsayıyı köşegene getirin. Bu her zaman en iyi sonucu vermeyebilir, kontrol etmek gerekir. Programda bunu yapan bir fonksiyon yazılabilir.
    - Denklemin tamamı (bütün satır) yer değiştirir. Yalnızca bir terimin yeri değiştirilmez.
    - Katsayıların işareti bu karşılaştırmada önemli değildir.
  - 2. adım: 1. denklemden $x_1$, 2. denklemden $x_2$, $n$. denklemden $x_n$ çekilir. Diğer terimler sağ tarafa geçer ve köşegen katsayısına bölünür.
  - 3. adım: başlangıç değerleri (ör. hepsi 0 veya 1) konur. Her yeni değer hesaplanırken **bir önceki iterasyonun** değerleri kullanılır. Aynı iterasyonda yeni bulunan değer kullanılmaz.
  - Durma: bütün değişkenler için $|x_i^{(k+1)} - x_i^{(k)}| \le \varepsilon$. Yalnızca bir değişkenin şartı sağlaması yetmez, hepsi sağlamalıdır.
  - Örnek: $-x + 4y - 3z = -8$, $3x + y - 2z = 9$, $x - y + 4z = 1$, $\varepsilon = 0.001$.
    - Mevcut köşegen çarpımı $|-1 \cdot 1 \cdot 4| = 4$. 1. ve 2. denklemler yer değiştirince köşegen 3, 4, 4 olur, çarpım 48.
    - $x = \frac{9 - y + 2z}{3}$, $y = \frac{-8 + x + 3z}{4}$, $z = \frac{1 - x + y}{4}$.
    - Başlangıç: slaytta "0" yazıyor ama hoca derste düzeltti, başlangıç değerleri $x = y = z = 1$.
    - 2. iterasyon: $x = 3.333$, $y = -1$, $z = 0.25$. 3. iterasyon: $x = 3.5$, $y = -0.979$, $z = -0.833$.
    - 13. iterasyonda bütün farklar hata sınırına iner. Sonuç $x = 3$, $y = -2$, $z = -1$.
    - Kontrol: $z = \frac{1 - 3 + (-2)}{4} = -1$.
- Gauss-Seidel iterasyonu
  - Jacobi ile aynıdır: köşegen en büyük yapılır, her denklemden bir değişken çekilir. Tek fark: her yeni değer hesaplanırken değişkenlerin **en son bulunan** değerleri kullanılır.
  - Örneğin $y$ hesaplanırken bu iterasyonda yeni bulunan $x$ kullanılır. $z$ hesaplanırken yeni bulunan $x$ ve $y$ kullanılır.
  - Aynı örnekte Jacobi 13 iterasyonda, Gauss-Seidel 8-9 iterasyonda bitti. Değişken sayısı arttıkça bu fark çok önemli olur.
  - 2. iterasyon: $x = 3.333$, $y = \frac{-8 + 3.333 + 3 \cdot 1}{4} = -0.417$, $z = \frac{1 - 3.333 - 0.417}{4} = -0.688$.
- Doğrusal olmayan denklem takımları (Newton-Raphson ile)
  - İki değişkenli iki denklem: $f(x, y) = 0$, $g(x, y) = 0$.
  - İki değişkenli Taylor serisi:
    - $f(x_0 + \Delta x, y_0 + \Delta y) = f(x_0, y_0) + \frac{\partial f}{\partial x}\Delta x + \frac{\partial f}{\partial y}\Delta y + \frac{\partial^2 f}{\partial x^2}\frac{\Delta x^2}{2!} + \ldots$
    - $g$ için de aynısı yazılır.
  - İkinci mertebe türevler ve sonrası atılır, ifade sıfıra eşitlenir. Matris biçimi:
    - $\begin{bmatrix} \frac{\partial f}{\partial x} & \frac{\partial f}{\partial y} \\ \frac{\partial g}{\partial x} & \frac{\partial g}{\partial y} \end{bmatrix} \begin{bmatrix} \Delta x \\ \Delta y \end{bmatrix} = -\begin{bmatrix} f(x_0, y_0) \\ g(x_0, y_0) \end{bmatrix}$
  - Bu doğrusal sistem herhangi bir yöntemle (Cramer, Gauss…) çözülür. $x_{k+1} = x_k + \Delta x$, $y_{k+1} = y_k + \Delta y$.
  - Durma: $|\Delta x| \le \varepsilon$ ve $|\Delta y| \le \varepsilon$.
  - Üç değişken ($f, g, v$ ve $x, y, z$) için matris 3×3 olur. Her yeni değişken ve denklem için matrise bir satır ve bir sütun eklenir. Yöntem aynıdır.
  - Örnek: $x^2 + y - 3 = 0$, $x + y^2 - 5 = 0$, $x_0 = 0.7$, $y_0 = 1.7$, $\varepsilon = 0.08$.
    - $\begin{bmatrix} 2x & 1 \\ 1 & 2y \end{bmatrix} \begin{bmatrix} \Delta x \\ \Delta y \end{bmatrix} = -\begin{bmatrix} x^2 + y - 3 \\ x + y^2 - 5 \end{bmatrix}$.
    - 1. iterasyon: $\begin{bmatrix} 1.4 & 1 \\ 1 & 3.4 \end{bmatrix} \begin{bmatrix} \Delta x \\ \Delta y \end{bmatrix} = -\begin{bmatrix} -0.81 \\ -1.41 \end{bmatrix}$. Slaytta $\Delta x = 0.31$, $\Delta y = 0.38$, $x = 1.01$, $y = 2.08$ yazıyor (doğru değerler için "Ders sonrası notlar"a bakın).
    - 2. iterasyon: $\Delta x = -0.01$, $\Delta y = -0.08$. İkisi de $\le 0.08$. Sonuç $x = 1$, $y = 2$.
    - Hata 0.001 verilseydi iterasyona devam edilirdi.
- Sayısal türev
  - Türev, bağımlı değişkenin bağımsız değişkene göre değişim miktarıdır. Mühendislikte birçok yasa değişime dayanır: hız konumun zamana göre türevi, ısı geçişi sıcaklık farkındaki değişim, bobin gerilimi akımın zamana göre değişimi, kondansatör akımı gerilimin zamana göre değişimi.
  - Analitik türev alınamayan yerlerde sayısal türev kullanılır. Projede türevi dışarıdan da girebilirsiniz. Polinom girişi: derece ve katsayılar sırayla istenir (ör. $2x + 5$ için derece 1, katsayılar 2 ve 5).
  - Geometrik olarak türev, fonksiyonun $x$ noktasındaki teğetinin eğimidir: $\tan \alpha$ = karşı / komşu. $f'(x) = \lim_{\Delta x \to 0} \frac{\Delta f}{\Delta x}$.
  - Üç sayısal türev:
    - Geri fark: $f'(x_i) \approx \frac{f(x_i) - f(x_i - h)}{h}$.
    - İleri fark: $f'(x_i) \approx \frac{f(x_i + h) - f(x_i)}{h}$.
    - Merkezi fark: $f'(x_i) \approx \frac{f(x_i + h) - f(x_i - h)}{2h}$.
  - $f(x) = x^3$ grafiği: $h = 0.1$'de üçü de analitik türeve yakındır. $h = 2$'de ileri ve geri fark analitik türevden belirgin şekilde uzaklaşır, merkezi fark yine üst üste oturur. Merkezi fark analitik türeve en yakın sonucu verir. $h$ ne kadar küçükse sonuç o kadar iyidir.
  - Örnek: $f(x) = e^x$, $x = 1$, $h = 0.1$. Analitik $e^1 = 2.718$.
    - İleri fark: $\frac{e^{1.1} - e^{1}}{0.1} = 2.86$.
    - Geri fark: $\frac{e^{1} - e^{0.9}}{0.1} = 2.59$.
    - Merkezi fark: $\frac{e^{1.1} - e^{0.9}}{0.2} = 2.72$.
  - Alıştırma: $f(x) = x^2$, analitik türev 2. Merkezi fark 2, ileri fark 2'den biraz büyük, geri fark biraz küçük çıkmalıdır.
- Taylor serisiyle türev formülleri
  - $f(x_i + h)$ ve $f(x_i + 2h)$ Taylor serisine açılır (ikinci kuvvete kadar). Uygun katsayılarla çarpılıp toplanarak istenmeyen türev yok edilir.
  - Birinci türev (ileri fark): ilk açılım $-4$ ile çarpılıp ikincisiyle toplanır, $f''$ terimleri gider.
    - $f'_i = \frac{1}{2h}\left[-3f_i + 4f_{i+1} - f_{i+2}\right]$
  - İkinci türev (ileri fark): ilk açılım $-2$ ile çarpılıp ikincisiyle toplanır, $f'$ terimleri gider.
    - $f''_i = \frac{1}{h^2}\left[f_i - 2f_{i+1} + f_{i+2}\right]$
  - Üçüncü türev için seri üçüncü kuvvete kadar açılır, birinci ve ikinci türevler yok edilir.
  - Geri fark için $x - h$, $x - 2h$; merkezi fark için $x - h$, $x + h$ konur. Bunların türetilmesi sınavda sorulmayacak, sadece Taylor serisinden de türev bulunabildiğini görün.
- Ödevler (önce kendiniz çözün, sonra kaynaklara bakın):
  - Ödev 1: Taylor serisini 3. kuvvete kadar açarak ileri fark formüllerini gösterin:
    - $f'_i = \frac{1}{6h}\left[-11f_i + 18f_{i+1} - 9f_{i+2} + 2f_{i+3}\right]$
    - $f''_i = \frac{1}{h^2}\left[2f_i - 5f_{i+1} + 4f_{i+2} - f_{i+3}\right]$
    - $f'''_i = \frac{1}{h^3}\left[-f_i + 3f_{i+1} - 3f_{i+2} + f_{i+3}\right]$
  - Ödev 2: $f(x) = 2x^2 + 1$, $x = 2$, $h = 0.1$, analitik $f'(2) = 8$. Basit ileri fark ve Taylor serisiyle iki noktalı ileri fark ile çözün. Merkezi fark 8, ileri fark 8'den biraz büyük, geri fark biraz küçük çıkmalıdır. Farklı anlamlı basamak sayılarıyla hesaplayıp sonuçları karşılaştırın.
- Ders planı: gelecek hafta integral (trapez, Simpson, iki katlı integral). 7. hafta sonlu farklar, ardından vize. Regresyon ve enterpolasyon vizeden sonraya kalabilir. Kalabalık sınıf nedeniyle projeye 2 hafta ayrılması gerekebilir. Vizelerin nasıl yapılacağı henüz belli değil.

## Hocanın Özellikle Vurguladığı Kısımlar

- Jacobi ve Gauss-Seidel'de en önemli adım köşegeni maksimum yapmaktır. Bunu unutursanız çözüm yanlış çıkar.
- Denklemlerin yerini değiştirirken satırın tamamını taşıyın, tek bir terimi değil.
- Jacobi bir önceki iterasyonun değerlerini, Gauss-Seidel en son bulunan değerleri kullanır. Bütün fark budur.
- Durma için bütün değişkenlerin farkı $\varepsilon$'dan küçük olmalıdır.
- Sayısal türevde merkezi farkı tercih edin. Analitik türeve en yakın sonucu verir.
- Cholesky formüllerini ve Taylor türev formüllerini ezberlemeyin. Matris çarpımından ve Taylor açılımından çıkarabilirsiniz.
- Projede `break`/`goto` kullanmayın, kodunuzu uç durumlarla test edin, çalıştığından emin olmadığınız algoritmaya "yaptım" demeyin.
- Projeyi son haftalara bırakmayın. İlk yöntemler kolaydır, şimdiden yazın.

## Kısa Tekrar Notları

- Cholesky (ders anlatımı): $A = LU$ ($U$'nun köşegeni 1). $LY = C$, sonra $UX = Y$.
- Jacobi: köşegen maksimum, her denklemden bir değişken, eski değerlerle güncelle.
- Gauss-Seidel: aynı, ama en son değerlerle güncelle. Genellikle daha hızlı.
- Doğrusal olmayan sistem: $J \cdot \Delta = -F$, $x_{k+1} = x_k + \Delta x$.
- Geri fark $\frac{f(x) - f(x-h)}{h}$, ileri fark $\frac{f(x+h) - f(x)}{h}$, merkezi fark $\frac{f(x+h) - f(x-h)}{2h}$.
- Taylor ileri fark: $f'_i = \frac{-3f_i + 4f_{i+1} - f_{i+2}}{2h}$, $f''_i = \frac{f_i - 2f_{i+1} + f_{i+2}}{h^2}$.

## Detaylı Açıklamalar

### Neden köşegen büyük olmalı?

- Jacobi ve Gauss-Seidel'in yakınsaması için yeterli bir şart, matrisin **köşegen baskın** olmasıdır: her satırda köşegen elemanının mutlak değeri, o satırdaki diğer elemanların mutlak değerleri toplamından büyük olmalıdır ($|a_{ii}| > \sum_{j \ne i} |a_{ij}|$).
- Örnekteki yeniden düzenlenmiş sistemde: $|3| > |1| + |-2|$ değil (eşit), $|4| > |-1| + |-3|$ değil (eşit), $|4| > |1| + |-1|$ (evet). Tam baskın değildir ama yine de yakınsar. Şart yeterlidir, gerekli değildir.
- Köşegen katsayıları büyük olunca her denklemden çekilen değişkende diğer değişkenlerin etkisi küçülür. Hatalar her adımda azalır.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Bütün örnekler ders sonrasında Python ile yeniden hesaplandı. Cholesky, $e^x$ türevleri, Jacobi ve Gauss-Seidel'in sonuçları ($x = 3$, $y = -2$, $z = -1$) doğrudur. Bazı ara değerlerde hatalar var, aşağıda belirtildi.
- **Ders anlatımı Crout ayrıştırmasıdır:** Derste anlatılan yöntem ($U$'nun köşegeni 1, $L$ genel alt üçgen) aslında **Crout LU ayrıştırması**dır. Literatürdeki Cholesky ayrıştırması yalnızca simetrik ve pozitif tanımlı matrislere uygulanır ve $A = LL^T$ biçimindedir ($U = L^T$). Örnekteki $A$ simetrik değildir, gerçek Cholesky uygulanamaz. Türkçe kaynaklarda bu yöntem bazen "Cholesky" adıyla geçer. Sınavda hocanın anlattığı yöntem beklenir.
- **Cholesky örneğinde ara değerler:** Slaytta $U_{23} = 0.49$ yazıyor, sonraki adımlarda $-0.49$ kullanılmış. Doğrusu $U_{23} = \frac{2.1 + 2.1}{-8.6} = -0.488$'dir. $L_{33} = 6.5 + 0.4 + 2.967 \cdot 0.488 = 8.349$'dur (slaytta yuvarlanmış: 8.4). Tam değerler: $y = (1.75, -0.0174, 0.2817)$, $x = (1.8108, 0.1201, 0.2817)$.
- **Jacobi tablosu:** 6. satırda $x = 3.006$ yazıyor. $|\Delta x| = 0.063$ ile tutarlı değer $x = 3.066$'dır (yazım hatası). 13. satırda $|\Delta x|$ aslında 0.0012'dir, tabloda 0.001'e yuvarlanmış. $\le 0.001$ şartı kesin olarak 14. iterasyonda sağlanır. Sonuç değişmez.
- **Gauss-Seidel tablosu:** 3. satırda $|\Delta x| = 0.348$ yazıyor. Doğrusu $|2.681 - 3.333| = 0.653$'tür. 5. satırda $z = -0.983$ yazıyor, doğrusu $-0.993$'tür ($|\Delta z| = 0.010$ ile tutarlı). Hoca "9. adıma gerek yokmuş" dedi. Ancak 8. satırda $|\Delta x|$ aslında 0.0015'tir (tabloda 0.001'e yuvarlanmış). Kesin hesapla $\le 0.001$ şartı 9. iterasyonda sağlanır. Yani 9. satır gereklidir.
- **Doğrusal olmayan sistem örneğinde ilk adım:** $1.4\Delta x + \Delta y = 0.81$ ve $\Delta x + 3.4\Delta y = 1.41$ çözülünce $\Delta x = 0.357$, $\Delta y = 0.310$ çıkar (slaytta 0.31 ve 0.38). Doğru değerlerle $x_1 = 1.057$, $y_1 = 2.010$ olur. 2. iterasyonda $\Delta x = -0.056$, $\Delta y = -0.010$. İkisi de $\le 0.08$ olduğu için durulur: $x = 1.002$, $y = 2.000$. Gerçek çözüm $(1, 2)$'dir. Slayttaki yanlış ara değerlerle de aynı köke ulaşılmıştır, çünkü Newton yöntemi bir sonraki adımda hatayı düzeltir.
- **Geri fark tanımındaki sürçme:** Derste bir an "geri fark, türevini bulacağım noktanın $h$ kadar ilerisindeki değer" denildi. Geri farkta $h$ kadar **gerideki** $x_i - h$ noktası kullanılır, hoca hemen ardından doğrusunu anlattı.
- **Formüllerin doğruluk mertebesi:** Basit ileri ve geri fark formüllerinin hatası $h$ ile orantılıdır ($O(h)$). Merkezi fark ve Taylor'dan çıkan $\frac{-3f_i + 4f_{i+1} - f_{i+2}}{2h}$ formülünün hatası $h^2$ ile orantılıdır ($O(h^2)$). Bu yüzden $h$ yarıya inince merkezi farkın hatası dörtte birine iner. Merkezi farkın daha iyi sonuç vermesinin nedeni budur.
- **"İki noktalı" ve "3 noktalı" adları:** Slaytta $\frac{-3f_i + 4f_{i+1} - f_{i+2}}{2h}$ için "iki noktalı", ödev 1'deki formüller için "3 noktalı" deniyor. Aslında ilki üç noktayı ($f_i, f_{i+1}, f_{i+2}$), ödevdekiler dört noktayı ($f_i, \ldots, f_{i+3}$) kullanır. Slayttaki ad, Taylor serisinin açıldığı noktaların sayısını ($x+h$, $x+2h$) belirtiyor olabilir.
- **Alıştırma ve ödev 2'nin cevapları (kontrol için, önce kendiniz çözün):** $f(x) = x^2$, $x = 1$, $h = 0.1$ alınırsa ileri fark 2.1, geri fark 1.9, merkezi fark 2'dir. $f(x) = 2x^2 + 1$, $x = 2$, $h = 0.1$ için ileri fark 8.2, geri fark 7.8, merkezi fark 8, Taylor ileri fark formülü $\frac{-3 \cdot 9 + 4 \cdot 9.82 - 10.68}{0.2} = 8$. İkinci derece polinomlarda merkezi fark ve $O(h^2)$ formülleri tam sonucu verir. $e^x$ için Taylor ileri fark formülü 2.7085 verir (basit ileri farktan çok daha yakın).
- **Ödev 1 kontrolü:** Ödevdeki üç formül doğrudur. $f(x) = x^3$, $x = 1$, $h = 0.1$ ile deneyince $f' \approx 3$, $f'' \approx 6$, $f''' = 6$ çıkar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
