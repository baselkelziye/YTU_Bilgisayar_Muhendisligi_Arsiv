# Ders 12 Çalışma Özeti

## Genel Konular

- Konvolüsyon işleminin tekrarı
  - Konvolüsyon, korelasyonla aynı işlemdir; tek farkı maskenin (filtrenin) hem yatayda hem dikeyde döndürülerek uygulanmasıdır (ekrandan, 00:05:00).
  - Formül: $g(i,j)=\sum_{k=-n/2}^{n/2}\sum_{l=-n/2}^{n/2} h(k,l)\,f(i-k,j-l)=\sum_{k}\sum_{l} h(i-k,j-l)\,f(k,l)$ (ekrandan, 00:05:00).
  - Simetrik maskelerde ($h(i,j)=h(-i,-j)$) konvolüsyon korelasyonla aynı sonucu verir; gösterim $h * f = f * h$.
  - Çarpanlarına ayrılabilen bir filtre (örneğin $3\times3$ filtre, $3\times1$ ve $1\times3$ iki vektörün çarpımı olarak) iki ayrı tek boyutlu filtre ile uygulanarak işlem yükü azaltılabilir.
  - İhtiyaca göre (örneğin kenar belirleme) farklı filtrelerle farklı konvolüsyon katmanları kurulabilir.
- Normal sinir ağı ile CNN karşılaştırması
  - CIFAR-10 görüntüleri $32\times32\times3$ boyutludur; tam bağlantılı ilk gizli katmandaki tek bir nöron $32\cdot32\cdot3=3072$ ağırlığa sahip olur (ekrandan, 00:15:00).
  - $200\times200\times3$ bir görüntüde bu sayı $120\,000$ ağırlığa çıkar; tam bağlantı israftır ve aşırı öğrenmeye yol açar.
  - CNN'de filtre girdinin yalnız bir bölümüne uygulanır, her şey her şeye bağlı değildir; ardından gelen havuzlama da boyutu düşürür.
- Örnek CNN mimarisi (CIFAR-10)
  - Mimari: `[INPUT - CONV - RELU - POOL - FC]` (ekrandan, 00:20:00).
  - Boyutlar: giriş $32\times32\times3$; 12 filtreli konvolüsyon katmanı; ReLU boyutu değiştirmez; havuzlama $16\times16\times12$'ye indirir; tam bağlantılı katman 10 sınıf için $1\times1\times10$ çıktı verir.
- ReLU ve türevleri
  - ReLU: $f(x)=\max(0,x)$; $x$ nörona gelen toplam değerdir, eleman eleman uygulanır, boyut azaltmaz. Gradyan kaybolması problemini önler.
  - Ölü nöron (dying ReLU): sıfıra çekilen nöronun tekrar pozitif olma şansı azalır, bazı özellikler kullanılamaz hale gelir.
  - Leaky ReLU: $x<0$ için sıfır yerine küçük bir eğim (0,01 civarı) kullanır: $f(x)=\mathbb{1}(x<0)(\alpha x)+\mathbb{1}(x\ge0)(x)$ (ekrandan, 00:25:00).
  - Maxout: $\max(w_1^Tx+b_1,\,w_2^Tx+b_2)$; ReLU ve Leaky ReLU bunun özel durumlarıdır, ama nöron başına parametre sayısı iki katına çıkar (ekrandan, 00:25:00).
- Underfitting ve overfitting
  - Underfitting: model çok genel kurulmuştur; örneğin yeleli ve kükreyen her hayvanın aslan sayılması.
  - Overfitting: model eğitim örneklerine birebir uyar; örneğin "305 pound, 3,5 feet boyunda, 2,9 inç pençeli kedi aslandır" kuralı eğitim örneğini doğru tahmin eder ama yeni örneklerde işe yaramaz (ekrandan, 00:30:00).
  - Nedenleri: çok fazla giriş özelliği, çok karmaşık mimari (çok sayıda gizli katman ve nöron).
- Overfitting'i fark etme ve önleme
  - Çapraz doğrulama (cross-validation): verinin büyük kısmıyla eğitim, bir kısmıyla doğrulama; önce veri iyi karıştırılır. Eğitim ve doğrulama başarısı arasında büyük fark (örneğin %90'a %60) bir sorun olduğunu gösterir.
  - Ardından test verisiyle model doğrulanır.
  - Düzenlileştirme (regularization), max norm kısıtı ve dropout başlıca yöntemlerdir.
  - Aykırı (outlier) örnekleri eğitimden önce ayıklamak, gereksiz özellikleri elle azaltmak ve sıfır eğitim hatası hedeflememek (belli bir noktada durmak) de yardımcı olur.
- Düzenlileştirme (regularization)
  - Model, ağırlıkları ve bias'ları fazla büyük olduğu için cezalandırılır; L1 ve L2 türleri vardır (ekrandan, 00:35:00).
  - Ev fiyatı örneği: doğru $\theta_0+\theta_1x$ (underfit), ikinci derece $\theta_0+\theta_1x+\theta_2x^2$ (uygun), dördüncü derece polinom (overfit) (ekrandan, 00:40:00).
  - Maliyete ceza terimi eklenir: $\min_\theta \frac{1}{2m}\sum_{i=1}^{m}(h_\theta(x^{(i)})-y^{(i)})^2+1000\,\theta_3^2+1000\,\theta_4^2$ (ekrandan, 00:45:00).
  - Genel biçim: $J(\theta)=\frac{1}{2m}\left[\sum_{i=1}^{m}(h_\theta(x^{(i)})-y^{(i)})^2+\lambda\sum_{j=1}^{n}\theta_j^2\right]$ (ekrandan, 00:50:00).
  - $\lambda$ çok büyük seçilirse ($\lambda=10^{10}$) bütün $\theta_1..\theta_4\approx0$ olur, $h_\theta(x)=\theta_0$ yatay doğrusu kalır ve underfitting oluşur.
  - Gradyan iniş güncellemesi: $\theta_j := \theta_j-\alpha\left[\frac{1}{m}\sum_{i=1}^{m}(h_\theta(x^{(i)})-y^{(i)})x_j^{(i)}+\frac{\lambda}{m}\theta_j\right]$, $j=1,\dots,n$; $\theta_0$ cezalandırılmaz (ekrandan, 00:55:00).
- Lojistik regresyonda underfitting ve overfitting
  - Doğrusal karar sınırı $g(\theta_0+\theta_1x_1+\theta_2x_2)$ underfitting'dir (yüksek bias); ikinci derece terimlerle uygun sınır; çok yüksek dereceli polinom overfitting'dir (yüksek varyans) (ekrandan, 01:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Konvolüsyonda filtre mutlaka döndürülür
  - Hoca, bu konuda sık hata yapıldığını söyledi: örneklerde genelde döndürülmüş hali verildiği için döndürme adımı fark edilmiyor. Belli bir işi yapan bir filtre seçildiyse konvolüsyon için mutlaka döndürülerek uygulanır.
- Sıfır eğitim hatası iyi bir şey değildir
  - Eğitimde %100 başarı genelleme yeteneğinin kaybedildiğini gösterebilir. Hata çok az azalmaya başladıysa durmak gerekir; daha fazlası örneklerin ezberlenmesidir.
- $\lambda$ veriye göre seçilmelidir
  - $\lambda$, $\theta$'ların aldığı değer aralığına göre seçilmezse önemli özellikler farkında olmadan sıfıra çekilir ve underfitting oluşur. Deneyerek ya da değer aralıklarına bakarak uygun bir ara değer bulunur.
- Veri temizliği
  - Model kurmadan önce veri analiz edilmeli; büyük olasılıkla yanlış ölçüm olan uç örnekler eğitimden atılmalıdır.

## Kısa Tekrar Notları

- Konvolüsyon = filtre yatay ve dikey döndürülmüş korelasyon; simetrik maskede ikisi aynıdır.
- Ayrılabilir filtre: $3\times3$ yerine $3\times1$ ve $1\times3$ ile daha az işlem.
- CIFAR-10: $32\times32\times3$, tek tam bağlantılı nöronda 3072 ağırlık; $200\times200\times3$'te 120 000.
- `INPUT - CONV - RELU - POOL - FC`: $32\times32\times3 \to$ (12 filtre) $\to 16\times16\times12$ (havuzlama) $\to 1\times1\times10$.
- ReLU $\max(0,x)$; ölü nöron sorunu; Leaky ReLU negatifte küçük eğim; Maxout iki doğrusalın maksimumu.
- Underfitting = aşırı genel model (yüksek bias); overfitting = ezber (yüksek varyans).
- Overfitting nedenleri: çok özellik, çok karmaşık mimari.
- Çözümler: çapraz doğrulama ile tespit, düzenlileştirme (L1, L2), max norm kısıtı, dropout, özellik azaltma, aykırı değer temizliği, erken durma.
- $J(\theta)$'ya $\lambda\sum\theta_j^2$ eklenir; $\theta_0$ cezalandırılmaz; çok büyük $\lambda$ underfitting yapar.
- Güncelleme: $\theta_j := \theta_j\left(1-\alpha\frac{\lambda}{m}\right)-\alpha\frac{1}{m}\sum(h_\theta(x^{(i)})-y^{(i)})x_j^{(i)}$.

## Detaylı Açıklamalar

- **Konvolüsyon ve korelasyon.** Korelasyonda filtre görüntü üzerinde kaydırılıp doğrudan noktasal çarpım yapılır. Konvolüsyonda ise filtre önce yatayda ve dikeyde döndürülür. Slayttaki örnekte $\begin{bmatrix}1&2&3\\4&5&6\\7&8&9\end{bmatrix}$ maskesi önce $\begin{bmatrix}7&8&9\\4&5&6\\1&2&3\end{bmatrix}$ biçimine, sonra $\begin{bmatrix}9&8&7\\6&5&4\\3&2&1\end{bmatrix}$ biçimine getirilir (ekrandan, 00:05:00). Simetrik maskelerde bu döndürme bir şey değiştirmez. Hesap yükünü azaltmak için çarpanlarına ayrılabilen filtreler iki tek boyutlu filtre olarak art arda uygulanabilir.
- **CNN neden boyut azaltır?** Tam bağlantılı bir çok katmanlı algılayıcıda her katmanda hesaplanacak ağırlık sayısı nöron sayısıyla birlikte artar. Konvolüsyon katmanında filtre girdinin yerel bir bölgesine uygulanır, havuzlama katmanı da ReLU'dan sonra boyutu düşürür. Böylece derin bir MLP yerine CNN kullanmak hem parametre sayısını hem hesabı ciddi biçimde azaltır. CIFAR-10 küçük görüntülerden oluştuğu için CNN denemek için uygun bir veri setidir; tek konvolüsyon ve tek havuzlama katmanıyla bile 10 sınıflı sınıflandırma yapılabilir.
- **ReLU katmanı.** ReLU, aktivasyon fonksiyonunun yerine geçer ve her elemana ayrı uygulanır. Negatif değerler sıfıra çekildiği için bazı nöronlar eğitim boyunca hep sıfır üretebilir ("ölü nöron"); bu durumda o nöronun temsil ettiği özellik bazı örnekler için önemli olsa bile kullanılamaz. Leaky ReLU negatif bölgede küçük bir eğime izin vererek bu sorunu hafifletir; Maxout başka bir seçenektir.
- **Underfitting ve overfitting.** Amaç, eldeki örneklerden yeni örneklere genellenebilecek bir fonksiyon bulmaktır. Çok genel model güvenilmezdir (underfitting); örneklerin hepsine birebir uyan model ise en küçük farklılıkta yanlış tahmin yapar (overfitting). Girişte çok fazla özellik verilir ve gizli katmanlarda bunların alt özellikleri de çıkarılırsa model aşırı ayrıntıya dayanır ve bu ayrıntıları taşımayan örnekleri tanıyamaz.
- **Çapraz doğrulama.** Veri iyi karıştırıldıktan sonra büyük kısmı eğitime, bir kısmı doğrulamaya ayrılır. Eğitim ve doğrulama sonuçları uyumlu değilse ya overfitting/underfitting ya da kötü veri dağılımı vardır; eğitim seti örneklerin hemen hepsini temsil etmelidir. Uyum sağlandıktan sonra test verisi kullanılır.
- **Düzenlileştirme.** Problemin çözümü hakkında fikir olmadığı ve büyük veriyle derin ağ kullanıldığı durumlarda hangi özelliğin önemli olduğu baştan bilinemez. Bu yüzden bütün özellikler verilir, ama maliyet fonksiyonuna parametreleri cezalandıran bir terim eklenir. Ev fiyatı örneğinde dördüncü derece polinoma $1000\theta_3^2+1000\theta_4^2$ eklendiğinde $\theta_3$ ve $\theta_4$ sıfıra yaklaşır ve model ikinci derece eğriye döner. 100 özellik olduğunda hangisinin cezalandırılacağı bilinmediği için bütün $\theta_j$'ler $\lambda\sum\theta_j^2$ ile cezalandırılır. L1 düzenlileştirmede parametrenin kendisi (mutlak değeri), L2'de karesi kullanılır. Gradyan inişte türev alınınca güncelleme $\theta_j(1-\alpha\lambda/m)$ çarpanını içerir; bu çarpan her adımda parametreyi küçültür.
- **Max norm ve dropout.** Max norm kısıtında ağırlık ve bias değerleri belli bir üst sınırla kırpılır; böylece tek bir özelliğin aşırı öne çıkması engellenir. Dropout'ta eğitim sırasında bazı nöronlar işlem dışı bırakılır (silinmez). Hoca bu iki yöntemi düzenlileştirmeye göre daha az sistematik ama işe yarayan yöntemler olarak niteledi.

- **Ders sonrası not (dropout):** Hoca önce nöronların rastgele kapatıldığını, şekil üzerinden anlatırken ise en yüksek değerli nöronların kapatıldığını söyledi. Standart dropout'ta nöronlar büyük olasılıkla (yaygın tanıma göre) değerlerine bakılmadan, belli bir olasılıkla rastgele kapatılır.
- **Ders sonrası not (varyans):** Bir öğrenci sorusu üzerine hoca, uydurulan doğrudan uzaklıkların kareleri toplamının büyük olmasını "yüksek varyans" olarak adlandırıp underfitting'e bağladı. Slayttaki ve yaygın terminolojide eğitim verisinde büyük hata veren basit model **yüksek bias** (underfitting), eğitim verisine aşırı uyan ve veriye göre çok değişen karmaşık model **yüksek varyans** (overfitting) olarak adlandırılır.
- **Ders sonrası not (Leaky ReLU):** Hoca Leaky ReLU'da "sıfırın biraz altında ya da biraz üstünde bir değer, 0,01 gibi" kullanıldığını söyledi; slayta göre 0,01 sabit bir değer değil, $x<0$ bölgesindeki eğimdir: $f(x)=0{,}01\,x$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
