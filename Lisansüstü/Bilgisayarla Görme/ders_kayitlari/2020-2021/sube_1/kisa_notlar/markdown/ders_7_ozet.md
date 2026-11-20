# Ders 7 Çalışma Özeti

## Genel Konular

- Hough dönüşümü: oylamayla model uydurma
  - Hough dönüşümü uydurma (fitting) ve hizalama yöntemleri arasında sayılır. Temeli bir oylama sistemidir: elimizdeki her veri (örneğin Harris ile bulunmuş nokta konumları) model parametreleri için oy verir.
  - Parametre uzayı sonlu bir ızgaraya (grid) bölünür, oylar hücrelerde birikir. Bu ızgaraya birikeç (accumulator) denir.
  - Slayttaki üç adım (ekrandan, 00:20:00): 1) parametre değerlerinden bir ızgara kur, 2) her nokta bir parametre kümesine oy verir ve ızgaradaki o değerleri artırır, 3) ızgarada maksimumu ya da yerel maksimumları bul.
  - Orijinal Hough dönüşümü çizgi bulmak için önerilmiştir (hocaya göre 1959). Zamanla daire, elips gibi başka parametrik şekillere, SIFT gibi özniteliklerle de nesne eşleştirmeye (genelleştirilmiş Hough dönüşümü) genişletilmiştir.
- Çizgi parametrizasyonu: $(m,b)$ yerine $(\rho,\theta)$
  - $y = mx + b$ biçiminde $m$ ve $b$ eksi sonsuzdan artı sonsuza değer alabilir; parametre uzayı sınırsızdır, bu yüzden ızgaraya bölmek mümkün olmaz.
  - Çözüm kutupsal gösterimdir (ekrandan, 00:35:00): $x\cos\theta + y\sin\theta = \rho$.
  - $\rho$ en fazla imgenin köşegeni kadar olur ($\sqrt{a^2+b^2}$, $a\times b$ imge boyutu), $\theta$ 0 ile 360 derece arasındadır. İkisi de sınırlıdır.
  - Hocanın örneği: $\rho$ ekseni 10 parçaya, $\theta$ 10'ar derecelik 36 parçaya bölünürse 360 hücrelik bir ızgara elde edilir.
  - Bir noktanın $x$ ve $y$'si bilinir ama denklemde iki bilinmeyen ($\rho,\theta$) vardır. Bu yüzden $\theta$ adım adım (0, 10, 20, ..., 360) değiştirilir, her $\theta$ için $\rho$ hesaplanıp oy verilir. Bir noktanın oyları Hough uzayında sinüs biçimli bir eğri oluşturur; aynı çizgi üzerindeki noktaların eğrileri bir hücrede kesişir.
- Pratik sorunlar
  - Gürültülü veride bir çizginin oyları komşu hücrelere dağılır. Izgara (bin) boyutu doğru seçilmeli, birikeç üzerinde yumuşatma (smoothing) yapılmalı; komşu hücrelere de oy atmak bir seçenektir.
  - Düzgün dağılmış gürültü sahte zirveler (spurious peaks) üretir (ekrandan, 00:40:00). Hocanın önerisi: nokta sayısıyla ilişkili bir en az oy eşiği koymak.
  - Canny kenarları üzerinde Hough deneyi: bir bina fotoğrafında bazı çizgiler iyi bulunur, renk geçişi zayıf olan ya da gürültüyle eğrilmiş kısımlar kaçırılır. Gerçek fotoğraflarda başarı sınırlıdır; uzun ve düz çizgiler bol oy aldığı için daha kolay bulunur.
- Yönelimli gradyanlarla hızlandırılmış Hough
  - Kenar bulma (Sobel, Canny) ve Harris sırasında gradyan bilgisi zaten hesaplanır. Gradyan yönü $\theta$'yı verir.
  - $\theta$ bilinince $\rho = x\cos\theta + y\sin\theta$ doğrudan hesaplanır ve her nokta tek bir hücreye oy verir. Bu, değiştirilmiş (modified) bir Hough dönüşümüdür. Literatürde olasılıksal Hough gibi başka değişik biçimler de vardır.
- Çember bulma
  - Çember denklemi $(x-x_0)^2+(y-y_0)^2=r^2$; üç bilinmeyen vardır, birikeç üç boyutlu olur.
  - Kenar yönelimi biliniyorsa her nokta, her $r$ için yalnız iki yere oy verir: noktadan birim gradyan yönünde ve ters yönünde $r$ kadar gidilen noktalar (merkez hangi tarafta bilinmediği için).
- Hough dönüşümünün değerlendirmesi (ekrandan, 01:25:00)
  - İyi: aykırı değerlere gürbüz (her nokta ayrı oy verir), oldukça verimli, birden fazla iyi uyum (örneğin birden fazla çizgi) bulabilir.
  - Kötü: gürültüye biraz duyarlı; bin boyutu gürültü toleransı, kesinlik ve hız/bellek arasında ödünleşimdir; birkaç parametreden fazlası için uygun değildir, ızgara boyutu parametre sayısıyla üstel büyür.
  - Kullanım: çizgi, çember, elips uydurma; nesne örneği tanıma (parametreler afin dönüşüm); nesne kategorisi tanıma (parametreler konum ve ölçek).
- RANSAC (RANdom SAmple Consensus, Fischler ve Bolles, 1981)
  - Algoritma (ekrandan, 01:35:00): 1) modeli uydurmak için gereken sayıda noktayı rastgele seç (çizgi için 2), 2) bu örneklerle model parametrelerini çöz, 3) modelin önceden belirlenmiş eşiği ($\delta$) içinde kalan iç noktaların (inlier) oranıyla puanla. En iyi model yüksek güvenle bulunana kadar 1-3'ü tekrarla.
  - Slayttaki örnekte bir aday çizgi $N_I=6$, daha iyi bir aday $N_I=14$ iç nokta toplar.
  - Parametre seçimi (ekrandan, 01:40:00): örnek sayısı $s$ (çizgi 2, çember 3), uzaklık eşiği $\delta$ (iyi bir noktanın yüzde 95 olasılıkla eşik içine düşeceği biçimde), deneme sayısı $N=\log(1-p)/\log(1-(1-e)^s)$ ($p$ genelde 0.99, $e$ aykırı değer oranı).
  - İyi: aykırı değerlere gürbüz, Hough'tan daha çok parametreli modellere uygulanabilir (birikeç yok). Kötü: hesap zamanı aykırı değer oranı ve parametre sayısıyla hızla büyür, birden fazla uyum bulmakta iyi değildir. Kullanım: homografi (imge birleştirme), temel matris (fundamental matrix) kestirimi.
- Hizalama (alignment) ve global parametrik bükme (warping)
  - Hizalama: bir nokta kümesini diğerine eşleyen modelin parametrelerini bulmak; doğru eşleşmelerin çoğunu açıklayan global dönüşüm aranır. Zorluklar: gürültü, aykırı değerler, çoktan bire eşleşmeler, birden fazla nesne.
  - Dönüşüm $T$ bir koordinat değiştirme makinesidir: $p' = T(p)$ (ekrandan, 01:45:00). Global olması, her nokta için aynı olması ve birkaç sayıyla tarif edilebilmesi demektir. Doğrusal dönüşümlerde $T$ bir matristir: $p' = \mathbf{T}p$.
- Temel iki boyutlu dönüşümler (ekrandan, 02:20:00)
  - Ölçekleme: $\begin{bmatrix}x'\\y'\end{bmatrix}=\begin{bmatrix}s_x&0\\0&s_y\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}$. Tekdüze ölçeklemede iki katsayı eşittir; tekdüze olmayan ölçekleme en-boy oranını değiştirir. Hocanın örneği: $(2,1)$ noktası 2 ile ölçeklenince $(4,2)$ olur.
  - Dönme: $x'=x\cos\theta-y\sin\theta$, $y'=x\sin\theta+y\cos\theta$ (ekrandan, 02:10:00); matris $\mathbf{R}=\begin{bmatrix}\cos\theta&-\sin\theta\\\sin\theta&\cos\theta\end{bmatrix}$. $\sin$ ve $\cos$ $\theta$'nın doğrusal olmayan fonksiyonları olsa da $x'$, $y'$ $x$ ve $y$'nin doğrusal birleşimidir. Ters dönüşüm $-\theta$ ile elde edilir ve $\mathbf{R}^{-1}=\mathbf{R}^T$'dir.
  - Kayma (shear): $\begin{bmatrix}1&\alpha_x\\\alpha_y&1\end{bmatrix}$.
  - Öteleme: $x'=x+t_x$, $y'=y+t_y$. 2x2 matrisle yazılamaz; üçüncü bir bileşen (1) eklenir: $\begin{bmatrix}x'\\y'\end{bmatrix}=\begin{bmatrix}1&0&t_x\\0&1&t_y\end{bmatrix}\begin{bmatrix}x\\y\\1\end{bmatrix}$ (ekrandan, 02:25:00). Buna homojen koordinatlar denir.
- Afin ve projektif dönüşümler
  - Afin dönüşüm: doğrusal dönüşümler (ölçekleme, dönme, kayma) ile ötelemenin birleşimi. Çizgiler çizgiye gider, paralel çizgiler paralel kalır, oranlar korunur, birleşme (composition) altında kapalıdır.
  - Projektif dönüşüm (ekrandan, 02:35:00): afin dönüşüm ile projektif bükmelerin birleşimi; 3x3 matrisin alt satırı $(g,h,i)$ da serbesttir. Sonuçtaki $w'$ 1 olmayabilir, bütün bileşenler $w'$'ye bölünerek homojen olmayan koordinatlara dönülür.
  - Projektif özellikler: çizgiler çizgiye gider, paralel çizgiler paralel kalmayabilir, oranlar korunmaz, birleşme altında kapalıdır, taban değişimini (change of basis) modeller, matris bir ölçeğe kadar tanımlıdır (8 serbestlik derecesi).
  - Taban değişimi: bir noktanın konumu farklı bir merkez ve doğrusal bağımsız taban vektörleriyle de tarif edilebilir; bilgisayar grafiğinde model, dünya, kamera ve ekran koordinatları arasındaki geçişler buna örnektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- $x\cos\theta + y\sin\theta = \rho$ çizgi denklemi
  - Hoca bu formülün bilinmesi gerekebileceğini söyledi. Hough'un $(m,b)$ yerine bu kutupsal gösterimi kullanmasının nedeni parametre uzayının sınırlı olmasıdır.
- Gradyan bilgisinin kullanılması
  - Hoca, kenar bulma ve Harris'te zaten var olan gradyan yönünün Hough'u hızlandırmak için kullanılabileceği gibi "yakalanması zor ayrıntıların" da sorulabileceğini, slaytların ayrıntılı çalışılması gerektiğini vurguladı.
- Izgara (bin) boyutu
  - Çok küçük hücreler tek bir çizgiyi birden fazla çizgiye bölebilir, çok büyük hücreler kesinliği kaybettirir. Bu, Hough'un en önemli ayarıdır.
- Hough ve RANSAC'ın karşılaştırması
  - Hough birden fazla nesne bulabilir ama parametre sayısı arttıkça birikeç üstel büyür. RANSAC daha çok parametreli modellere uygundur ama tek bir uyum için iyidir.
- Ötelemenin homojen koordinat gerektirmesi
  - İki boyutta öteleme için matriste en az üç sütun, üç boyutta en az dört sütun gerekir.

## Kısa Tekrar Notları

- Hough: parametre ızgarası kur, her nokta oy versin, maksimumu bul.
- Çizgi için $(\rho,\theta)$: $x\cos\theta + y\sin\theta = \rho$; $\rho \le$ imge köşegeni, $\theta\in[0,360)$.
- $\theta$ bilinmiyorsa her nokta birçok hücreye oy verir (sinüs eğrisi); gradyandan $\theta$ biliniyorsa tek oy yeter.
- Sorunlar: gürültüde oy dağılması, sahte zirveler, bin boyutu seçimi; çözümler: yumuşatma, eşik.
- Çember: $(x_0,y_0,r)$, üç boyutlu birikeç; gradyanla her $r$ için iki oy.
- Çizgi parçasının uçları: hangi noktaların o çizgiye oy verdiği saklanırsa en küçük ve en büyük nokta arasında parça çizilir.
- RANSAC: rastgele en az örnek seç, modeli çöz, iç noktaları say, tekrarla. $N=\log(1-p)/\log(1-(1-e)^s)$.
- RANSAC kullanımı: homografi, temel matris; birden fazla model için zayıf.
- Global dönüşüm: her noktaya aynı, birkaç parametreyle tarif edilir.
- Ölçek, dönme, kayma 2x2 matrisle; öteleme homojen koordinatla.
- $\mathbf{R}^{-1}=\mathbf{R}^T$; ölçeklemenin tersi $1/s$ katsayılıdır.
- Afin: paralellik ve oranlar korunur. Projektif: yalnız çizgiler çizgi kalır, 8 serbestlik derecesi.

## Detaylı Açıklamalar

- **Hough dönüşümünün mantığı.** Hough dönüşümü "demokratik" bir yöntemdir: aranan nesnenin parametrelerini doğrudan çözmek yerine her veri noktası, kendisiyle uyumlu bütün parametre değerlerine oy verir. Parametre uzayı hücrelere bölündüğü için oylar sayılabilir. Çok sayıda noktanın ortak oy verdiği hücre, imgede o parametrelere sahip bir nesnenin (örneğin bir çizginin) bulunduğunu gösterir. $y=mx+b$ gösteriminde $m$ ve $b$ sınırsız olduğu için ızgara kurulamaz. Kutupsal gösterimde ise çizgi, imgenin sol üst köşesi merkez alınarak çizgiye olan dik uzaklık $\rho$ ve bu dikmenin açısı $\theta$ ile tarif edilir: $x\cos\theta + y\sin\theta = \rho$. İmge boyutu $a\times b$ ise $\rho$ en fazla $\sqrt{a^2+b^2}$ olur. Tek bir noktadan ($x,y$ bilinen) iki bilinmeyen çözülemez; bu yüzden $\theta$ adım adım taranır ve her $\theta$ için $\rho$ hesaplanıp oy verilir. Bir noktanın oyları Hough uzayında bir eğri çizer (ekrandan, 00:35:00); aynı çizgi üzerindeki noktaların eğrileri bir hücrede yoğunlaşır ve çizginin parametreleri bu yoğunlaşmanın yerinden okunur.
- **Gürültü ve sahte zirveler.** Piksel ayrıklığı, aydınlanma ve köşe bulucunun kendi hataları yüzünden noktalar tam bir çizgi üzerinde durmaz; oylar komşu hücrelere dağılır. Bu yüzden bin boyutu dikkatle seçilir ve birikeç yumuşatılır. Belirgin bir çizgi yokken rastgele noktalar küçük çizgiler oluşturur gibi görünür ve sahte zirveler çıkar (ekrandan, 00:40:00). Hoca, nokta sayısına bağlı bir en az oy eşiğini olası bir çözüm olarak önerdi. Canny kenarları üzerinde yapılan deneyde bina fotoğrafındaki bazı çizgiler iyi bulunmuş, zayıf renk geçişli üst kısım ve gürültüyle eğrilmiş kısımlar kaçırılmıştır (ekrandan, 00:45:00); düzenli, boydan boya uzanan kafes gibi yapılarda ise sonuç daha iyidir.
- **Gradyanla hızlandırma ve çember.** Gradyanın $x$ ve $y$ bileşenlerinden gradyan yönelimi bir açı olarak hesaplanır. Bu açı $\theta$ olarak kullanılırsa her noktanın $\rho$'su tek işlemle bulunur ve 30-40 oy yerine tek oy verilir. Çemberde üç parametre ($x_0,y_0,r$) vardır. Merkez imgenin herhangi bir yerinde olabildiği için birden fazla çember olduğunda noktaların ortalamasını almak işe yaramaz; oylama gerekir. Kenar yönelimi biliniyorsa merkez, noktadan birim gradyan yönünde $r$ kadar uzaktadır; merkezin hangi tarafta olduğu bilinmediği için iki yöne de oy verilir. Birikeç üç boyutludur ve parametre sayısı arttıkça boyutu büyür.
- **RANSAC.** Çok sayıda nokta olduğunda (örneğin üç boyutlu tarayıcıların nokta bulutları) bütün noktaları kullanmak yerine model için gereken en az sayıda nokta rastgele seçilir, bu noktalardan model çözülür ve modelden $\delta$ uzaklığından yakın noktalar sayılır. En çok iç nokta toplayan model seçilir. Kaç deneme gerektiği, en az bir denemenin aykırı değersiz olma olasılığının $p$ olmasından türetilir: bir denemede $s$ noktanın hepsinin iç nokta olma olasılığı $(1-e)^s$, $N$ denemenin hepsinin başarısız olma olasılığı $(1-(1-e)^s)^N = 1-p$'dir; buradan $N=\log(1-p)/\log(1-(1-e)^s)$ çıkar (ekrandan, 01:40:00). Slayttaki tablo $p=0.99$ içindir; örneğin $s=4$ ve yüzde 50 aykırı değerde 72, $s=8$ ve yüzde 50'de 1177 deneme gerekir (python ile doğrulandı).
- **Dönüşümler ve homojen koordinatlar.** Dönüşümleri matris çarpımı olarak yazmak hem GPU/TPU gibi hızlandırıcılarda hızlı hesap sağlar hem de matematiksel ifadeleri sadeleştirir. Matris, istenen denklemlerdeki katsayılar yerine konarak kurulur; denklemde bulunmayan değişkenin katsayısı 0 olur. Öteleme bir sabit eklediği için $x$ ve $y$'nin katsayıları yetmez; vektöre 1 eklenir ve $t_x$ bu 1 ile çarpılır: $x' = x + 0y + t_x\cdot 1$ (ekrandan, 02:25:00). Projektif dönüşümde son bileşen 1'den farklı çıkabilir; o zaman bütün bileşenler ona bölünür. Afin dönüşümler paralelliği ve oranları korur; projektif dönüşümler korumaz ama çizgileri yine çizgiye götürür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
