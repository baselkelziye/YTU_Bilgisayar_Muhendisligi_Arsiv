# Ders 10 Çalışma Özeti

## Genel Konular

- Tam bağlı katmandan evrişimli katmana geçiş
  - Standart (tam bağlı, fully connected) bir sinir ağında imgenin her pikseli gizli katmandaki her üniteye bağlanır. 200×200'lük gri seviye bir imge 40.000 piksel verir; 40.000 gizli üniteyle bu yaklaşık 2 milyar parametre demektir (ekrandan, 00:10:00).
  - Slaytta tam bağlı yapının sorunları: uzamsal ilişki yereldir (spatial correlation is local), kaynak israfıdır ve zaten yeterli eğitim örneği yoktur.
  - Yerel bağlı katman (locally connected layer): her çıkış ünitesi girdinin yalnız küçük bir bölgesine bağlanır. 200×200 imge, 40.000 gizli ünite ve 10×10 filtreyle 4 milyon parametre olur. Girdi imgeleri hizalı (registered) olduğunda, örneğin yüz tanımada iyi çalışır (ekrandan, 00:15:00).
  - Evrişimli katman (convolutional layer): yerel bağlantı korunur, ayrıca aynı ağırlıklar (filtre çekirdeği) imgenin her yerinde paylaşılır. Bu işlem bildiğimiz evrişimdir; öğrenilen şey çekirdeğin katsayılarıdır.
- Evrişimli katmanın işleyişi
  - Örnek çekirdek $\begin{bmatrix}-1&0&1\\-1&0&1\\-1&0&1\end{bmatrix}$ her satırda yatay türev alır, yani yatay yönde büyük parlaklık değişimi olan kenarları ortaya çıkarır (ekrandan, 00:20:00).
  - Bir katmanda birçok filtre öğrenilir: biri yatay, biri dikey kenarları, bir başkası başka bir özelliği yakalayabilir.
  - Formül (ekrandan, 00:25:00): $h_j^{n}=\max\left(0,\sum_{k=1}^{K} h_k^{n-1} * w_{kj}^{n}\right)$. Burada $h_k^{n-1}$ girdi özellik haritası (input feature map), $w_{kj}^n$ çekirdek, $h_j^n$ çıktı özellik haritasıdır; $\max(0,\cdot)$ ReLU doğrusalsızlığıdır.
  - Çıktı özellik haritası sayısını filtre sayısı belirler. Birden fazla girdi haritası üzerinde aynı anda çalışan "üç boyutlu" filtre, her konumda bütün haritalardaki çarpımları toplayıp tek değer üretir.
  - Slayttaki ana fikirler (ekrandan, 00:30:00): standart ağ girdi boyutuyla karesel büyür ve durağanlıktan (stationarity) yararlanmaz; çözüm her gizli üniteyi küçük bir yamaya bağlamak ve ağırlıkları uzayda paylaşmaktır (LeCun ve ark., 1998).
- Havuzlama katmanı (pooling layer)
  - Filtre cevaplarını küçük bir pencerede istatistiksel olarak özetler; özelliğin tam konumundaki küçük kaymalara karşı gürbüzlük (x-y ötelemesine değişmezlik) sağlar.
  - Max, ortalama (average), L2 ve özellikler üzerinde L2 havuzlama formülleri slaytta verildi (ekrandan, 00:50:00).
  - Havuzlama özellik haritalarının boyutunu küçültür.
  - Alıcı alan (receptive field): K×K filtre (adım 1) ve P×P havuzlamada havuzlama katmanındaki her ünite, önceki evrişim katmanının girdisinde $(P+K-1)\times(P+K-1)$'lik bir yamaya bağlıdır (ekrandan, 00:55:00).
- Adım (stride), dolgu (padding) ve genişletme (dilation)
  - Stride: filtrenin bir konumdan sonrakine kaç piksel atladığı.
  - Padding: kenarlara sıfır eklenerek evrişim sonrası küçülmenin önlenmesi; 5×5 filtre dolgusuz uygulanırsa imge her boyutta 4 piksel küçülür.
  - Dilation (atrous): filtre hücreleri arasına boşluk bırakılması; 3×3 filtre 5×5'lik bir alana yayılmış gibi çalışır.
- Yerel kontrast normalizasyonu (LCN)
  - $h^{i+1}(x,y)=\dfrac{h^{i}(x,y)-m^{i}(N(x,y))}{\sigma^{i}(N(x,y))}$: komşuluğun ortalaması çıkarılır, standart sapmasına bölünür (ekrandan, 01:00:00).
- Tipik aşama ve mimari
  - Bir aşama (stage): evrişim, (ReLU ile birlikte) LCN, havuzlama (ekrandan, 01:10:00).
  - Bütün sistem: birkaç aşama, ardından tam bağlı katmanlar ve sınıf etiketleri (ekrandan, 01:15:00).
  - SIFT/DoG ölçek uzayıyla benzerlik; fark, filtrelerin elle tasarlanması yerine veriden öğrenilmesidir.
- Eğitim
  - Her işlem türevlenebilir olduğu için geri yayılım (backpropagation) ve (stokastik) gradyan inişi aynen kullanılır; mini batch'lerle ileri yayılım, geri yayılım ve parametre güncellemesi yapılır.
- ImageNet ve sınıflandırma mimarisi
  - ImageNet: hiyerarşik büyük imge veri tabanı (Deng ve ark., CVPR 2009); örnek hiyerarşi mammal → placental → carnivore → canine → dog → working dog → husky (ekrandan, 01:20:00).
  - Krizhevsky ve ark. (NIPS 2012) mimarisi: toplam 60M parametre, 832M flop; evrişim katmanlarında az, tam bağlı katmanlarda çok parametre (ekrandan, 01:25:00).
  - Optimizasyon ayarları: momentumlu SGD, öğrenme oranı 0.01, momentum 0.9; genelleme için ağırlık paylaşımı, girdi bozulmaları, dropout 0.5, weight decay 0.0005 (ekrandan, 01:35:00).
  - Değerlendirmede sınıflandırıcı her imge için en olası 5 sınıfı döndürür; doğru sınıf bunların içindeyse doğru sayılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Parametre sayısı ve ağırlık paylaşımı
  - Tam bağlı katman milyarlarca, yerel bağlı katman milyonlarca, evrişimli katman (100 adet 10×10 filtre) yalnız 10.000 parametre ister. Hız isteniyorsa tam bağlı katmanlardan mümkün olduğunca kaçınılmalıdır.
- Evrişimli ağın ilk katmanları özellik çıkarıcıdır
  - Harris (Gauss ağırlıklı türevler), DoG ve SIFT gibi elle tasarlanmış özellik çıkarıcıların yaptığını CNN eğitim verisine göre kendi filtrelerini tasarlayarak yapar.
- Havuzlamanın getirdiği değişmezlik
  - Göz bulucu örneği: göz birkaç piksel kaysa da havuzlama penceresi içinde kaldıkça max havuzlama yine "burada göz var" bilgisini verir. Dönmeye değişmezlik vermez; bunun için eğitim imgeleri döndürülerek çoğaltılabilir.
- Katman (layer) ve aşama (stage) terimleri yazara göre değişir
  - Kimi yazar evrişim + aktivasyon + havuzlamayı tek katman ya da aşama sayar, kimi her birini ayrı katman sayar.

## Kısa Tekrar Notları

- Tam bağlı: 200×200 imge, 40K ünite → ~2B parametre.
- Yerel bağlı: 10×10 yerel bağlantı → 4M parametre.
- Evrişimli: yerel bağlantı + ağırlık paylaşımı; parametreler yalnız filtre katsayıları.
- $h_j^{n}=\max\left(0,\sum_{k} h_k^{n-1} * w_{kj}^{n}\right)$.
- Havuzlama: max, ortalama, L2, özellikler üzerinde L2; ötelemeye gürbüzlük ve boyut küçültme.
- Alıcı alan: $(P+K-1)\times(P+K-1)$.
- Stride = atlama adımı, padding = sıfırla kenar doldurma, dilation = filtre hücreleri arası boşluk.
- LCN: komşuluk ortalamasını çıkar, standart sapmaya böl.
- Aşama: Conv → (ReLU) → LCN → Pooling; sonunda tam bağlı katmanlar.
- Eğitim: backprop + mini batch SGD.
- AlexNet: 60M parametre, 832M flop; lr 0.01, momentum 0.9, dropout 0.5, weight decay 0.0005.

## Detaylı Açıklamalar

- Ders, önceki derslerde görülen temel sinir ağı ve geri yayılım formüllerinin hatırlatılmasıyla başladı. Hoca, PyTorch ve TensorFlow gibi çerçevelerde her katmanın kendi türev bilgisiyle geldiğini, bu yüzden pratikte bu formülleri elle bulmak gerekmediğini söyledi. Ardından evrişimli sinir ağlarına (CNN) geçildi. CNN'ler LeCun ve arkadaşlarının derin öğrenmeden önce de üzerinde çalıştığı bir yapıdır; derin ağların eğitilebildiği anlaşılınca derinleştirilmiş ve en popüler ağlardan biri olmuştur.
- Tam bağlı katmanda 200×200'lük imgenin 40.000 pikselinin her biri her gizli üniteye bir ağırlıkla bağlanır. Slayttaki ~2 milyar parametre bu bağlantı sayısından gelir ($40.000\times40.000=1{,}6\times10^9$; çarpım ajan tarafından kontrol edildi). Bu kadar parametre hem hesaplama yükü hem de çok fazla veri ya da verinin tekrar tekrar verilmesi ihtiyacı demektir. Yerel bağlı katmanda her çıkış ünitesi yalnız ilgili bölgedeki girişlere bağlanır; 10×10 bölgeyle $40.000\times100=4$ milyon parametre olur. Evrişimli katmanda ise aynı filtre imgenin her yerinde gezdirilir, böylece parametreler bütün pikseller tarafından paylaşılır.
- Evrişimde 3×3 bir çekirdek girdi imgesi üzerinde kaydırılır ve her konumdaki sonuç çıktı imgesinde pencerenin merkezine yazılır. Slayttaki $[-1\ 0\ 1]$ satırlarından oluşan çekirdek her satırda yatay türev aldığı için yatay yönde büyük parlaklık değişimi olan noktaları, yani kenarları gösterir. Bir katmanda örneğin 10×10 boyutunda 100 filtre öğrenilirse $100\times100=10.000$ parametre olur. <!-- BELİRSİZ: Filtre sayısı altyazıda düşmüş; 100 değeri hocanın "100 çarpı 100" hesabından çıkarıldı, slayt karede görülmedi. -->
- Girdi ve çıktılara "özellik haritası" (feature map) denir. Hoca bunu Harris, DoG ve SIFT ile ilişkilendirdi: bir özellik grubundan yeni bir özellik grubu üretilir. Evrişim sonucu ReLU'dan ($\max(0,\cdot)$) geçirilerek doğrusallıktan çıkarılır. Birden fazla girdi haritası varsa filtre bunların hepsi üzerinde aynı anda gezdirilir ve her konumdaki çarpımlar toplanarak tek bir çıktı değeri elde edilir; böylece çok sayıda harita daha az sayıda haritaya eşlenebilir.
- Havuzlama, filtre cevaplarını bir pencerede özetler. Max havuzlama penceredeki en büyük değeri, ortalama havuzlama değerlerin toplamının $K$'ya bölümünü, L2 havuzlama değerlerin karelerinin toplamının karekökünü alır. Özellikler üzerinde L2 havuzlamada pencere uzayda değil, aynı pikselin farklı özellik haritalarındaki değerleri üzerindedir. Hoca, CNN'lerin sinirbilimden en çok etkilenen ağlar arasında olduğunu; beyindeki V1 alanında Gabor benzeri kenar bulucuların, daha üst katmanlarda ise değişmez cevap veren hücrelerin bulunduğunu anlattı ("çikolata" kavramına yazıda, seste ve resimde aynı tepkiyi veren hücre örneği).
- Havuzlamadan sonra özellik haritaları küçülür. Alıcı alan formülü, havuzlama katmanındaki tek bir ünitenin evrişimin girdisinde ne kadar büyük bir alana bağlı olduğunu verir: $(P+K-1)\times(P+K-1)$. Örneğin $P=2$, $K=3$ için 4×4 (örnek ajan tarafından hesaplandı).
- Derste stride, padding ve dilation kavramları sözlü olarak tartışıldı. Stride 3 olduğunda filtre bir konumdan sonra üç piksel ileri atlar. Dolgu yapılmazsa her evrişimde imge küçülür; yüzlerce katmanlı derin ağda girdi neredeyse yok olabilir, bu yüzden kenarlar sıfırlarla doldurulur. Genişletilmiş filtrede 3×3 filtre, araları sıfır olan 5×5'lik bir filtre gibi davranır.
- LCN, bir komşulukta değerlerin ortalamasını çıkarıp standart sapmasına bölerek benzer renk değişimlerinin benzer cevap vermesini sağlar. Özellik uzayındaki komşuluklarda da uygulanabilir; slayta göre değişmezliği, optimizasyonu ve seyrekliği iyileştirir.
- Bir aşama evrişim (filtre bankası), doğrultma (ReLU) ile kontrast normalizasyonu ve havuzlamadan oluşur. Hoca bu yapıyı SIFT'teki DoG ölçek uzayına benzetti: orada imge farklı sigma değerli Gauss filtreleriyle süzülür, her oktavda imge yarıya indirilirdi; CNN'de havuzlama bu küçültmeye, evrişim katmanları filtrelemeye karşılık gelir. Fark, CNN'nin filtreleri eğitim setine göre kendisinin tasarlamasıdır. Birkaç aşamadan sonra sınıf etiketleri için tam bağlı katmanlar eklenir; bu kısım yerine SVM gibi başka sınıflandırıcılar da kullanılabilir.
- Krizhevsky ve arkadaşlarının 2012 ImageNet mimarisinde evrişim katmanlarının parametreleri 35K, 307K, 884K, 1.3M, 442K; tam bağlı katmanlarınki 37M, 16M ve son doğrusal katmanınki 4M'dir (ekrandan, 01:25:00). Toplam yaklaşık 60M parametrenin yaklaşık 57M'i tam bağlı katmanlardadır (toplam ajan tarafından kontrol edildi).
  - Ders sonrası not: Hoca tam bağlı kısımda "45 milyon civarı" parametre olduğunu söyledi; slayttaki değerlerin toplamı $37+16+4=57$ milyondur. Evrişim kısmı için söylediği yaklaşık 3 milyon doğrudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
