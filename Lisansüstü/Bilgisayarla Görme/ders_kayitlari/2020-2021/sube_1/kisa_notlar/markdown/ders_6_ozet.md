# Ders 6 Çalışma Özeti

## Genel Konular

- İlgi noktası bulucularının karşılaştırılması ve seçimi
  - Tekrar edilebilirlik (repeatability), bakış açısı 0 dereceden 50 dereceye doğru arttıkça düşer. Buradaki bakış açısı imgenin kendi düzleminde döndürülmesi değil, yüzeye ne kadar yandan bakıldığıdır.
  - Veri tabanındaki anahtar nokta sayısı arttıkça başarı genelde sabit kalır, çok fazla noktada eşlenecek aday arttığı için biraz düşer.
  - Slayttaki öneriler (ekrandan, 00:10:00): x-y'de kesin konum için Harris, ölçekte iyi konum için Difference of Gaussian (DoG), esnek bölge şekli için MSER.
  - En iyi seçim uygulamaya bağlıdır. Harris-/Hessian-Laplace/DoG birçok doğal kategoride, MSER binalar ve basılı nesnelerde iyi çalışır. Birden fazla bulucu birlikte kullanılarak daha çok nokta elde edilebilir.
  - Mikolajczyk ve arkadaşlarının (IJCV'05, PAMI'05) kapsamlı karşılaştırmaları vardır (ekrandan, 00:10:00). Bulucular köşe, blob ya da bölge bulmalarına, dönme/ölçek/afin değişmezliklerine, tekrar edilebilirlik, konum doğruluğu, gürbüzlük ve verimliliklerine göre sınıflandırılmıştır.
  - Afin değişmez bulucular (Harris-Affine, Hessian-Affine) yavaştır. DoG/SURF tabanlı yöntemler hızlıdır.
  - Nesne örneği tanıma ya da imge birleştirme (stitching) için SIFT ya da benzeri önerilir.
- Harris köşe bulucusunun tekrarı
  - x ve y türevlerinden oluşan ikinci moment (structure) matrisi kullanılır. Köşelik ölçütü bu matrisin determinantı ve izinden kurulur. En büyük yanıtlara non-max suppression uygulanır.
  - Parlaklık değişimine kısmen değişmezdir. Öteleme ve dönmede köşe konumları kovaryanttır (imgeyle birlikte hareket eder). Ölçekte kovaryant değildir: küçük pencere ölçek büyüyünce aynı yapıyı göremez.
- Öznitelik eşleme (feature matching)
  - Genel akış: ayırt edici noktaları bul, her noktanın çevresinde bir bölge tanımla, bölgeyi çıkar ve normalize et, yerel tanımlayıcı hesapla, tanımlayıcıları eşle.
  - Basit ölçüt: en yakın komşu ve uzaklık bir eşiğin altındaysa eşle. Uzaklık fiziksel değil, tanımlayıcılar arasındaki Öklid uzaklığıdır.
  - Sorunlar: eşik nasıl seçilecek, ayırt edici olmayan bir öznitelik birçok yakın eşleşmeye sahip olabilir ama yalnız biri doğrudur.
  - David Lowe'un çözümü: en yakın komşu uzaklığının ikinci en yakın komşu uzaklığına oranı kullanılır.
- Model uydurma (fitting) ve hizalama (alignment)
  - Uydurma: veriye en iyi uyan modelin parametrelerini bulmak. Hizalama: eşleşen noktaları en iyi hizalayan dönüşümün parametrelerini bulmak (ekrandan, 00:25:00).
  - Tasarımda iki şey gerekir: uygulamanın amacını yansıtan, aykırı değerlere ve gürültüye gürbüz bir uygunluk (goodness of fit) ölçüsü ve yerel optimumlardan kaçan, hızlı bir optimizasyon yöntemi.
  - Yöntem aileleri: global optimizasyon için en küçük kareler; onun üstüne kurulan gürbüz en küçük kareler ve Iterative Closest Point (ICP); hipotez üret ve test et yaklaşımı için genelleştirilmiş Hough dönüşümü ve RANSAC.
- En küçük kareler ile doğru uydurma (ekrandan, 00:35:00)
  - Veri $(x_1,y_1),\dots,(x_n,y_n)$, model $y_i = m x_i + b$, bulunacak $(m,b)$.
  - Hata: $E=\sum_{i=1}^{n}(y_i - m x_i - b)^2$.
  - Matris biçimi: $E=\lVert \mathbf{A}\mathbf{p}-\mathbf{y}\rVert^2$; $\mathbf{A}$'nın satırları $[x_i\;\;1]$, $\mathbf{p}=[m\;\;b]^T$.
  - Açılım: $E=\mathbf{y}^T\mathbf{y}-2(\mathbf{A}\mathbf{p})^T\mathbf{y}+(\mathbf{A}\mathbf{p})^T(\mathbf{A}\mathbf{p})$.
  - Türev: $\frac{dE}{d\mathbf{p}}=2\mathbf{A}^T\mathbf{A}\mathbf{p}-2\mathbf{A}^T\mathbf{y}=0$.
  - Normal denklem ve çözüm: $\mathbf{A}^T\mathbf{A}\mathbf{p}=\mathbf{A}^T\mathbf{y}\Rightarrow \mathbf{p}=(\mathbf{A}^T\mathbf{A})^{-1}\mathbf{A}^T\mathbf{y}$.
  - Hazır araçlar: Matlab'da `p = A \ y;`, Python'da `numpy.linalg.lstsq` (ekrandan, 00:35:00).
  - Doğrusal regresyonla aynı yöntemdir, çok boyutlu $x$ için de geçerlidir.
- Dikey en küçük karelerin sorunları ve toplam en küçük kareler (total least squares)
  - Dikey uzaklıkla kurulan en küçük kareler dönmeye değişmez değildir ve dikey doğrularda başarısız olur.
  - Toplam en küçük karelerde doğru $ax+by+c=0$ biçiminde yazılır. $a^2+b^2=1$ ise $(x_i,y_i)$ noktasının doğruya dik uzaklığı $|ax_i+by_i+c|$'dir; birim normal $N=(a,b)$ (ekrandan, 02:35:00).
  - Hata $E=\sum(ax_i+by_i+c)^2$. $c$'ye göre türev sıfırlanınca $c=-a\bar{x}-b\bar{y}$ çıkar. Yerine yazınca $E=\mathbf{p}^T\mathbf{A}^T\mathbf{A}\mathbf{p}$ olur; $\mathbf{A}$'nın satırları $[x_i-\bar{x}\;\;y_i-\bar{y}]$, $\mathbf{p}=[a\;\;b]^T$ (ekrandan, 02:40:00).
  - $\mathbf{p}^T\mathbf{p}=1$ kısıtıyla $\mathbf{p}^T\mathbf{A}^T\mathbf{A}\mathbf{p}$ en küçüklenir. Çözüm, $\mathbf{A}^T\mathbf{A}$'nın en küçük özdeğerine karşılık gelen özvektördür (Rayleigh bölümü).
- En küçük karelerin artı ve eksileri
  - Artı: amaç fonksiyonu açıktır, optimizasyon kolaydır, analitik (kapalı) çözümü vardır.
  - Eksi: optimize edilmek istenen şey bu olmayabilir, aykırı değerlere duyarlıdır, birden fazla iyi uydurma seçeneği vermez.
  - Tek bir aykırı nokta bile uydurulan doğruyu büyük ölçüde bozar, çünkü kare hata aykırı değerleri çok ağır cezalandırır (ekrandan, 02:45:00).
- Gürbüz en küçük kareler (robust least squares)
  - Kare yerine, ölçek parametresi $\sigma$ olan bir gürbüz fonksiyon $\rho$ kullanılır: $\sum_i \rho(u_i(x_i,\theta);\sigma)$; $u_i$, $i$. noktanın model parametrelerine göre artığıdır (residual).
  - Ölçek uygun seçilirse aykırı noktanın etkisi azalır; çok küçük ya da çok büyük ölçek sorun çıkarır.
  - Doğrusal olmayan bir optimizasyondur, yinelemeli çözülür: en küçük kareler çözümünden başlanır, Newton ya da en dik iniş (steepest descent) gibi yöntemlerle devam edilir. Ölçek, artıkların medyanına göre uyarlamalı seçilebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Matematiksel kısımlar
  - Hoca Harris bulucusu ve en küçük kareler kestirimi gibi matematiksel konuların slaytlardan iyi çalışılmasını istedi.
- Matris biçimine geçmenin yararı
  - Uzun toplamlar kısa yazılır. Matlab ya da NumPy gibi matrislerle hızlı çalışan kütüphaneler doğrudan kullanılabilir.
- Neden kare alınıyor?
  - Artıklar pozitif ya da negatif olabilir; toplamda birbirini götürmemeleri için hepsi pozitife çevrilir. Mutlak değer yerine karenin seçilmesinin nedeni türevinin kolay olmasıdır ($x^2$'nin türevi $2x$).
- Matris açılımlarını doğrulama
  - Bu tür eşitlikler bileşenler cinsinden yeniden yazılarak kolayca kontrol edilebilir. Hoca açılımı evde denemeyi önerdi.
- Ters matris sorunu
  - $(\mathbf{A}^T\mathbf{A})^{-1}$ hesaplanırken veriye bağlı olarak tekil (singular) matrisler çıkabilir.
- Gürbüz yöntemlerde ölçek
  - Gürbüz en küçük karelerde $\sigma$ ölçeği düzgün seçilmezse yöntem doğru sonuç vermez.

## Kısa Tekrar Notları

- Harris: kesin x-y konumu; DoG: ölçek; MSER: esnek bölge şekli. Seçim uygulamaya bağlıdır, birden fazla bulucu birlikte kullanılabilir.
- Afin değişmez bulucular yavaş, DoG/SURF hızlıdır.
- Harris: parlaklığa kısmen değişmez, öteleme ve dönmeye kovaryant, ölçeğe kovaryant değil.
- Eşleme akışı: nokta bul, bölge tanımla, normalize et, tanımlayıcı hesapla, eşle.
- Lowe oran testi: en yakın komşu uzaklığı / ikinci en yakın komşu uzaklığı.
- Uydurma: model parametreleri; hizalama: dönüşüm parametreleri.
- En küçük kareler: $E=\lVert\mathbf{A}\mathbf{p}-\mathbf{y}\rVert^2$, $\mathbf{p}=(\mathbf{A}^T\mathbf{A})^{-1}\mathbf{A}^T\mathbf{y}$; Python'da `numpy.linalg.lstsq`.
- Dikey en küçük kareler dönmeye değişmez değil, dikey doğrularda başarısız.
- Toplam en küçük kareler: $c=-a\bar{x}-b\bar{y}$, çözüm $\mathbf{A}^T\mathbf{A}$'nın en küçük özdeğerinin özvektörü.
- En küçük kareler aykırı değerlere duyarlı; gürbüz en küçük kareler $\rho(u;\sigma)$ kullanır, yinelemeli çözülür, ölçek seçimi kritiktir.

## Detaylı Açıklamalar

- Bulucu seçimi
  - Derste önceki haftanın ilgi noktası bulucuları sunumu tamamlandı. Karşılaştırma grafiklerinde bakış açısı değiştikçe tekrar edilebilirliğin ve doğru eşleşme oranının düştüğü görüldü. Bakış açısı burada kameranın yüzeye ne kadar yandan baktığıdır. Tek bir bulucu seçmek zorunlu değildir, ancak birden fazla bulucu kullanılacaksa uygulamaların kendi sisteme uyarlanması gerekir. Hoca seçim için ciddi karşılaştırma çalışmalarının okunmasını önerdi; Mikolajczyk ve arkadaşlarının çalışmalarına ve 2008 tarihli bir karşılaştırmalı yayına değindi. <!-- BELİRSİZ: 2008 yayınının yazarı altyazıda "Tüyle" diye geçiyor; büyük olasılıkla Tuytelaars ve Mikolajczyk'in yerel değişmez öznitelik bulucuları taraması. -->
  - Harris'ten Harris-Laplace'a, oradan Harris-Affine'e geçildikçe yöntem iyileşir ama afin değişmezlik için ek işlem yapıldığından yavaşlar.
- Harris tekrarı
  - "Neden yalnız x ve y'de gradyanın büyük olduğu yerlere bakmıyoruz?" sorusuyla Harris hatırlatıldı. Düz bölge, tek kenar ve köşe için structure matrisinin farklı biçimler aldığı slaytta gösterildi. <!-- BELİRSİZ: Bu üç durumdaki matris örnekleri karede yok; altyazıdan değerler okunamıyor. -->
- Öznitelik eşleme ve oran testi
  - Önceki haftalarda görülen örnekte bir bölgenin üç aday bölgeye uzaklıkları 0.34, 0.30 ve 0.40, başka bir örnekte iki noktaya uzaklıkları 0.61 ve 1.22 idi; bu durumda hangisinin eşleneceğine karar vermek zordur. <!-- BELİRSİZ: Bu uzaklık değerleri yalnız altyazıdan; karede görülmedi. --> Lowe'un önerdiği oran, en yakın eşleşmenin ikinci en yakından belirgin biçimde daha iyi olup olmadığını ölçer.
- En küçük kareler türetmesi
  - Fikir, her $x_i$ için modelin verdiği $m x_i + b$ ile gerçek $y_i$ arasındaki farkın karelerinin toplamını en küçük yapmaktır. Toplam, satırları $[x_i\;1]$ olan $\mathbf{A}$ matrisi ile $\mathbf{p}=[m\;b]^T$ çarpımından $\mathbf{y}$ çıkarılıp vektör normunun karesi alınarak yazılır; çünkü $\lVert(a,b)\rVert=\sqrt{a^2+b^2}$ olduğundan normun karesi bileşen karelerinin toplamıdır. Açılım $(a-b)^2$ binom açılımına benzer. $\mathbf{p}$'ye göre türev alınıp sıfıra eşitlenir; $\mathbf{y}^T\mathbf{y}$ terimi $\mathbf{p}$ içermediği için düşer. Normal denklem soldan $(\mathbf{A}^T\mathbf{A})^{-1}$ ile çarpılarak $\mathbf{p}$ yalnız bırakılır.
  - Kapalı çözüm, rastgele bir veri üzerinde `numpy.linalg.lstsq` sonucuyla aynı çıktı; açılım da sayısal olarak doğrulandı (ders sonrası python ile kontrol edildi).
- Toplam en küçük kareler
  - Burada noktanın doğruya dikey (y yönündeki) uzaklığı yerine gerçek dik uzaklığı kullanılır ve parametre sayısı üçe ($a,b,c$) çıkar. Önce $c$ tek başına çözülür, sonra $a,b$ için kısıtlı bir en küçükleme kalır. $\mathbf{p}^T\mathbf{p}=1$ kısıtı, $\mathbf{p}$'nin birim çember (genelde hiperküre yüzeyi) üzerinde olması demektir. Kısıtlı problem $\frac{\mathbf{p}^T\mathbf{A}^T\mathbf{A}\mathbf{p}}{\mathbf{p}^T\mathbf{p}}$ oranının en küçüklenmesine denktir ve özvektörle çözülür.
  - Bu çözüm de ders sonrası python ile denendi: merkezlenmiş verinin $\mathbf{A}^T\mathbf{A}$ matrisinin en küçük özdeğerine ait özvektör, beklenen doğruyu verdi.
- Gürbüzlük
  - Slayttaki grafikte kırmızı noktalara uyan mavi doğru, uzakta tek bir aykırı nokta eklenince belirgin biçimde yatıklaşmıştır. Gürbüz fonksiyon büyük artıkların etkisini sınırladığı için aykırı nokta varken bile doğru bozulmaz. Hoca gürbüz en küçük kareleri ayrıntılı araştırılabilecek bir konu olarak belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
