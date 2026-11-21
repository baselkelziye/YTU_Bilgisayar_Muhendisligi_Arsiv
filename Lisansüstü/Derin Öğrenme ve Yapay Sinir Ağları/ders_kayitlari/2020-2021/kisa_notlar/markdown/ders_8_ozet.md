# Ders 8 Çalışma Özeti

## Genel Konular

- Çok katmanlı yapay sinir ağları ve geri yayılım (backpropagation)
  - Çok katmanlı ağlar tek katmanlı ağlardan daha geniş problemleri çözebilir, ama ayarlanacak ağırlık sayısı arttığı için öğrenme daha karmaşıktır.
  - Geri yayılım, gradyan düşümüne dayanan ve ağın çıktısındaki toplam hatayı en aza indirmeye çalışan bir eğitim yöntemidir. Slayta göre 1969'da Bryson ve Ho tarafından çok katmanlı ağlar için "hatalardan öğrenme" yöntemi olarak geliştirilmiştir ve "genelleştirilmiş delta kuralı" diye de anılır (ekrandan, 00:10:00).
  - Amaç, doğru yanıt ile ağın yanıt verme yeteneği arasında denge kurmak, yani eğitim kalıplarına benzeyen ama onlarla özdeş olmayan girdilere de makul yanıt verebilen bir ağ elde etmektir.
- Algoritmanın üç aşaması
  - İleri besleme (feedforward): girdiler ağırlıklarla çarpılıp toplanır, bias eklenir, aktivasyon fonksiyonu uygulanır; bu işlem katman katman çıktıya kadar sürer.
  - Hatanın hesaplanıp geriye yayılması: çıktıdaki karesel hata hesaplanır, türevi geriye doğru yayılır.
  - Ağırlıkların güncellenmesi: her ağırlık, hataya olan katkısı (hatanın o ağırlığa göre türevi) oranında, gradyanın tersi yönünde değiştirilir.
  - Eğitim bittikten sonra test sırasında yalnız ileri besleme yapılır; ağırlıklar artık değişmez.
- Mimari (ekrandan, 00:15:00)
  - Girdi katmanı $X_1 \dots X_n$, gizli katman $Z_1 \dots Z_p$, çıktı katmanı $Y_1 \dots Y_m$.
  - Girdi-gizli ağırlıkları $v_{ij}$, gizli-çıktı ağırlıkları $w_{jk}$; her iki katmana da değeri 1 olan bir bias birimi bağlanır ($v_{0j}$, $w_{0k}$).
  - Hoca genellikle bir, en çok iki gizli katman kullanıldığını; gizli katman ve nöron sayısını çok artırmanın başarıyı fazla değiştirmediğini, hesabı ağırlaştırdığını söyledi. Gizli nöron sayısı için gözleme dayalı bir kural olarak "girdi sayısının logaritması kadar" önerdi.
- Aktivasyon fonksiyonu seçimi
  - Fonksiyon sürekli, türevlenebilir ve monoton azalmayan olmalıdır.
  - Ayrıca çıktı aralığı, problemde beklenen çıktı değerlerinin aralığıyla uyumlu olmalıdır.
  - Yaygın seçenekler: binary sigmoid (0 ile 1 arası) ve bipolar sigmoid (-1 ile 1 arası).
  - Türevler: binary sigmoid için $f'(x) = f(x)\,(1 - f(x))$, bipolar sigmoid için $f'(x) = \tfrac{1}{2}(1 + f(x))(1 - f(x))$.
- Hebb, perceptron ve delta kuralından geri yayılıma geçiş
  - Hebb kuralı girdi ile çıktıyı çarpıyordu; perceptron kuralı hedef değer ve öğrenme katsayısı ekledi; delta kuralı hedef ile hesaplanan değerin farkını kullandı.
  - Delta kuralının türetilmesi (ekrandan, 00:25:00): $y_{in} = \sum_{i=1}^{n} x_i w_i$, $E = \sum_{j=1}^{m} (t_j - y_{in,j})^2$, $\dfrac{\partial E}{\partial w_1} = -2(t - y_{in})\,x_1$, $\Delta w_1 = \mu (t - y_{in})\,x_1$. Sabit $-2$ çarpanı öğrenme katsayısının içine alınır.
- Eğitim ayrıntıları (ekrandan, 00:30:00)
  - Ağırlık ve biaslar genelde $-0.5$ ile $0.5$ (veya $-1$ ile $1$) arasında rastgele başlatılır.
  - Durma: belirli bir epok sayısı ya da hata seviyesi. Ağ çok eğitilirse ezberler ve genelleme yeteneğini kaybeder; az eğitilirse eğitim desenine bile doğru yanıt veremeyebilir.
  - Eğitim deseni sayısı: $P$ desen sayısı, $W$ ağırlık sayısı, $e$ istenen doğruluk olmak üzere $P = W/e$ ilişkisi (slayta göre 1989'da Baum ve Haussler).
- Sayısal geri yayılım örneği (ekrandan, 00:40:00-01:00:00)
  - 2 girdi, 2 gizli, 2 çıktı nöronlu ağ; bir eğitim örneği üzerinde ileri besleme, toplam hata ve $w_5$ ağırlığının zincir kuralıyla güncellenmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Geri yayılım derin öğrenmede her zaman kullanılacak
  - Sonraki konularda (derin ağlar) da hep geri yayılım kullanılacağı için bu konu dersin en önemli parçalarından biri olarak sunuldu.
- Her ağırlık hataya katkısı kadar değişir
  - $\partial E / \partial w$ ifadesi "hatanın o ağırlığa göre değişimi", yani o ağırlığın hatadaki payıdır. Eski yöntemlerdeki gibi bütün ağırlıklar aynı biçimde değiştirilmez.
  - Güncellemedeki eksi işareti çıkarma işlemi olarak değil, yön olarak (gradyanın tersi) düşünülmelidir. Böyle düşünülürse formül ezberlemeye gerek kalmaz.
- Ezberleme (aşırı eğitim)
  - Hata eğrisi çizilip izlenmelidir. Hata düşüşü çok yavaşladığında ya da düzlüğe girdiğinde eğitimi sürdürmek ağı ezberlemeye götürür.
  - Geri yayılım ağları genelde 5-10 epokla değil binlerce epokla eğitilir; bu yüzden hatanın gidişatı önemlidir.
- Aktivasyon fonksiyonuna dikkat
  - Ağ başarısızsa aktivasyon fonksiyonunun seçimi hatalı olabilir.
  - Delta kuralındaki $f(x)(1-f(x))$ terimi lojistik fonksiyona özgüdür. Başka bir aktivasyon fonksiyonu kullanılırsa güncelleme denklemindeki bu terim o fonksiyonun türeviyle değişir.
- Zincir kuralını elle uygulamak gerekir
  - Örnekleri yalnız izleyerek değil, elle yazarak çözmek gerekir. Bilgisayarda ise işlemler ortak katsayılarla (düğüm deltası) matris biçiminde, sistematik olarak yapılır.
- Örnek sayısı ve bağlantı sayısı
  - Bağlantı (ağırlık) sayısı arttıkça düşük hata için daha çok örnek gerekir. Derin ağların çok veriye ihtiyaç duymasının nedeni budur. $P = W/e$ kesin sayı vermez, ilişkiyi gösteren yaklaşık bir formüldür.

## Kısa Tekrar Notları

- Geri yayılım = ileri besleme + hatanın geriye yayılması + ağırlık güncelleme.
- Toplam hata, çıkış nöronlarının karesel hatalarının toplamıdır.
- Güncelleme: $w^{+} = w - \eta \, \dfrac{\partial E_{total}}{\partial w}$.
- Çıkış katmanı ağırlığı için zincir kuralı: $\dfrac{\partial E_{total}}{\partial w_5} = \dfrac{\partial E_{total}}{\partial out_{o1}} \cdot \dfrac{\partial out_{o1}}{\partial net_{o1}} \cdot \dfrac{\partial net_{o1}}{\partial w_5}$.
- Düğüm deltası: $\delta_{o1} = -(target_{o1} - out_{o1})\,out_{o1}(1 - out_{o1})$, $\dfrac{\partial E_{total}}{\partial w_5} = \delta_{o1}\,out_{h1}$.
- Sigmoid türevi: $f' = f(1-f)$ (binary), $f' = \tfrac12 (1+f)(1-f)$ (bipolar).
- Aktivasyon fonksiyonu: sürekli, türevlenebilir, monoton azalmayan ve çıktı aralığına uygun olmalı.
- Başlangıç ağırlıkları: $[-0.5, 0.5]$ ya da $[-1, 1]$ arasında rastgele.
- Çok uzun eğitim ezberlemeye yol açar; hata eğrisi izlenmeli.
- Genelde 1-2 gizli katman yeterlidir.
- $P = W/e$: ağırlık sayısı arttıkça gereken örnek sayısı artar.

## Detaylı Açıklamalar

- **Neden geri yayılım?** Çok katmanlı ağda ağırlık kombinasyonu çok fazla parametre içerdiği için Hebb ya da perceptron kuralı gibi basit kurallar yetmez. Ağın çıktısındaki hata, ağırlıkların bir fonksiyonu olarak düşünülür ve bu fonksiyonun minimumu gradyan düşümüyle aranır. Her ağırlık bu fonksiyonda bir boyuttur; $n$ ağırlık varsa minimum $n$ boyutlu bir uzayda aranır. Hoca bu nedenle önceki derste ikinci dereceden bir fonksiyon üzerinde gösterilen gradyan düşümünün burada çok boyutlu ve doğrusal olmayan bir probleme uygulandığını vurguladı.

- **Algoritmanın akışı (ekrandan, 00:20:00).** Slayttaki akış şemasına göre ağırlıklar küçük değerlerle başlatılır; durma koşulu sağlanmadığı sürece bütün eğitim ikilileri için şu adımlar yapılır:
  - FeedForward: $z\_in_j = v_{0j} + \sum_{i=1}^{n} x_i v_{ij}$, $z_j = f(z\_in_j)$; $y\_in_k = w_{0k} + \sum_{j=1}^{p} z_j w_{jk}$, $y_k = f(y\_in_k)$.
  - BackProp (çıktı birimi): $\delta_k = (t_k - y_k)\, f'(y\_in_k)$, $\Delta w_{jk} = \alpha \delta_k z_j$, $\Delta w_{0k} = \alpha \delta_k$.
  - BackProp (gizli birim): $\delta\_in_j = \sum_{k=1}^{m} \delta_k w_{jk}$, $\delta_j = \delta\_in_j\, f'(z\_in_j)$, $\Delta v_{ij} = \alpha \delta_j x_i$, $\Delta v_{0j} = \alpha \delta_j$.
  - Update: $w_{jk}(new) = w_{jk}(old) + \Delta w_{jk}$, $v_{ij}(new) = v_{ij}(old) + \Delta v_{ij}$.

- **Delta kuralının kökeni.** Nöronun girdisi $y_{in} = \sum x_i w_i$ biçimindedir. Karesel hata $E = (t - y_{in})^2$ alınıp $w_1$'e göre türev alındığında iç türevde yalnız $x_1 w_1$ terimi kalır, onun türevi $x_1$'dir; dış türevden gelen 2 ve $-y_{in}$ teriminin önündeki eksiyle $\partial E / \partial w_1 = -2(t - y_{in})x_1$ bulunur (ekrandan, 00:25:00). Sabit çarpan öğrenme katsayısına katılır ve gradyanın tersi yönünde gidilince $\Delta w_1 = \mu (t - y_{in}) x_1$ elde edilir. Aktivasyon fonksiyonu araya girdiğinde türevde fonksiyonun türevi de çarpan olarak yer alır.

- **Sayısal örnek (ekrandan, 00:45:00).** Girdiler $i_1 = 0.05$, $i_2 = 0.10$; hedefler $0.01$ ve $0.99$; ağırlıklar $w_1 = 0.15$, $w_2 = 0.20$, $w_3 = 0.25$, $w_4 = 0.30$, $w_5 = 0.40$, $w_6 = 0.45$, $w_7 = 0.50$, $w_8 = 0.55$; biaslar $b_1 = 0.35$, $b_2 = 0.60$. Aktivasyon lojistik fonksiyondur.
  - $net_{h1} = 0.15 \cdot 0.05 + 0.20 \cdot 0.10 + 0.35 = 0.3775$, $out_{h1} = 0.593269992$; $out_{h2} = 0.596884378$.
  - $net_{o1} = 0.40 \cdot 0.593269992 + 0.45 \cdot 0.596884378 + 0.60 = 1.105905967$, $out_{o1} \approx 0.7514$; $out_{o2} \approx 0.7729$.
  - Hatalar: $E_{o1} \approx 0.2748$, $E_{o2} \approx 0.0236$, $E_{total} \approx 0.2984$.
  - $\dfrac{\partial E_{total}}{\partial w_5} = 0.74136507 \cdot 0.186815602 \cdot 0.593269992 = 0.082167041$ (ekrandan, 01:00:00).
  - $\eta = 0.5$ ile $w_5^{+} = 0.4 - 0.5 \cdot 0.082167041 = 0.35891648$ (ekrandan, 00:55:00). Aynı yolla $w_6^{+} = 0.408666186$.
  - Ara değerler (ekranda görünmeyenler dahil) python ile hesaplanıp doğrulandı.
  - Ders sonrası not: Hoca toplam hatayı "0,29", yeni $w_5$'i "0,35" diye yuvarlayarak söyledi; python ile hesaplanan toplam hata $0.298371109$, ekrandaki yeni $w_5$ ise $0.35891648$'dir. Ayrıca hata değerleri, karesel hatanın $\tfrac12$ katsayısıyla ($E = \tfrac12 (t - out)^2$) hesaplanmıştır; hoca yalnız "farkın karesi" dedi, ama $0.2748$ sonucu ancak bu $\tfrac12$ çarpanıyla çıkar.

- **Gizli katman ağırlıkları.** $w_1 \dots w_4$ için de aynı zincir kuralı uygulanır; bir tur sonunda bütün ağırlıklar güncellenir, yeni örnek gösterilir ve işlem hata belirli bir seviyeye inene ya da belirli epok sayısına ulaşılana kadar sürer. Bu adımların sayısal çözümü sonraki derse bırakıldı.

- **Ders sonrası not:** Slaytta "Broyson & Ho" yazıyor; doğru yazım "Bryson & Ho"dur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
