# Ders 9 Çalışma Özeti

## Genel Konular

- Kümelemeye giriş (denetimsiz öğrenme)
  - Kümeleme (clustering) denetimsiz öğrenmedir (unsupervised learning): veri gerekir ama sınıf etiketi gerekmez (ekrandan, 00:20:00).
  - Verideki örüntüleri bulmak için kullanılır: e-postaları ya da arama sonuçlarını gruplamak, müşteri alışveriş örüntülerini çıkarmak, görüntülerdeki bölgeleri ayırmak. Ne aradığımızı bilmediğimiz durumlarda yararlıdır (ekrandan, 00:20:00).
  - Derste anılan kümeleme yöntemleri: bölümlemeli (partitional) kümeleme ve K-Means, QT kümeleme, kendini düzenleyen özellik haritaları (SOM) ve beklenti maksimizasyonu (EM) kümelemesi. Bu haftanın konusu K-Means ve EM'dir.
  <!-- BELİRSİZ: 00:19:00-00:19:30 arasında yöntem listesi kısmen İngilizce ve bozuk; slayt listesi okunamadı. -->
- Uzaklık ölçüleri (sayısal öz nitelikler)
  - $p$ öz nitelikli veri setinde $x$ ve $y$ örnekleri arasındaki Öklid uzaklığı: $d(x,y) = \sqrt{\sum_{i=1}^{p} (x_i - y_i)^2}$.
  - Manhattan (şehir bloğu, $L_1$ norm) uzaklığı: farkların karesi yerine mutlak değeri alınır, $d(x,y) = \sum_{i=1}^{p} |x_i - y_i|$. Tahtada iki boyutta $A(x_1,y_1)$ ve $B(x_2,y_2)$ için $d_{L_1}(A,B) = |x_1 - x_2| + |y_1 - y_2|$ gösterildi (ekrandan, 00:25:00).
  - Öklid uzaklığı $L_2$ norm uzaklığıdır.
  - Minkowski uzaklığı: farkların $q$. kuvvetlerinin toplamının $q$. dereceden kökü, $d(x,y) = \left(\sum_{i=1}^{p} |x_i - y_i|^q\right)^{1/q}$. $q = 1$ Manhattan, $q = 2$ Öklid uzaklığını verir.
  - Mesafe ölçüsünün özellikleri: $d(i,j) \ge 0$, $d(i,i) = 0$, $d(i,j) = d(j,i)$, $d(i,j) \le d(i,k) + d(k,j)$ (üçgen eşitsizliği) (ekrandan, 00:30:00).
- İkili (binary) öz nitelikler için benzerlik ölçüleri
  - İki örneğin ikili öz nitelikleri olumsallık (contingency) tablosuyla karşılaştırılır: $a$ 0-0 eşleşme, $d$ 1-1 eşleşme, $b$ ve $c$ ise 0-1 ve 1-0 eşleşme sayılarıdır.
  - Basit eşleşme katsayısı (simple matching coefficient): $\text{Sim}_{SMC}(i,j) = \dfrac{a + d}{a + b + c + d}$.
  - Jaccard katsayısı: $\text{Sim}_{Jaccard}(i,j) = \dfrac{d}{b + c + d}$; 0-0 eşleşmeler ($a$) kullanılmaz.
  - Kategorik öz nitelikler için Hamming uzaklığı kullanılır.
- K-Means kümeleme
  - $N$ nesneli, sınıf etiketi olmayan veri $K$ ayrık (disjoint) alt kümeye ($S_j$) bölünür; $K < N$ ve pozitif tam sayıdır.
  - Amaç kareler toplamı ölçütünü (maliyet fonksiyonu) en küçük yapmaktır: $J = \sum_{j=1}^{K} \sum_{n \in S_j} |x_n - \mu_j|^2$; $\mu_j$, $S_j$ kümesinin geometrik merkezidir (ekrandan, 00:45:00).
  - Adımlar: $K$ verilir; başlangıç küme merkezleri seçilir; her örneğin merkezlere uzaklığı hesaplanır ve örnek en yakın kümeye atanır; her kümenin yeni merkezi üyelerin ortalamasıyla bulunur; yakınsamaya kadar tekrarlanır.
  - Durma kuralı: kümeler arasında yer değiştiren örnek kalmaması ya da maliyet fonksiyonu için bir alt sınır.
- K-Means'in zayıf yönleri
  - Başlangıç merkezlerinin yeri nihai kümeleri değiştirebilir.
  - Ortak merkezli (co-centric) kümeleri ayıramaz; bu tür veri için DBSCAN daha elverişlidir.
- Uygun $K$ değerinin seçimi (dirsek yöntemi)
  - Farklı $K$ değerleriyle çözüm yapılır, her biri için $J$ hesaplanır ve $K$'ya karşı çizilir; düşüşün belirgin biçimde yavaşladığı dirsek noktası uygun $K$ kabul edilir.
- Beklenti maksimizasyonu (EM) kümeleme
  - K-Means'te her nokta tek bir kümeye aittir (sert atama, hard assignment). EM'de her nokta her kümeye belli bir olasılıkla aittir (yumuşak atama, soft assignment); $P(x \mid C)$ değeri $[0,1]$ aralığında herhangi bir değer alabilir (ekrandan, 02:10:00).
  - Bayes teoremi ile $P(C_i \mid x_j)$ sonsal olasılığı, $P(x_j \mid C_i)$ olabilirliği ve $P(C_i)$ önsel olasılığı üzerinden hesaplanır.
  - Her kümenin normal (Gauss) dağılım gösterdiği ve verinin $k$ normal dağılımın karışımından (mixture of Gaussians) üretildiği varsayılır.
  - Üç adım: başlatma (initialization), beklenti (expectation), maksimizasyon (maximization).
  - $d$ boyutlu veride ortalama bir vektör, varyans yerine $d \times d$ kovaryans matrisi olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Başlangıç merkezlerinin seçimi K-Means'in en büyük dezavantajıdır
  - Aynı veri, farklı başlangıç merkezleriyle farklı biçimde iki kümeye bölünebilir. Başlangıç merkezlerinin veri setindeki örneklerden seçilmesi zorunlu değildir; her eksendeki değişim aralığına bakılarak düzlemde rastgele bir nokta da seçilebilir. Uygun noktaların seçilmesi yakınsamayı hızlandırır.
- Ortak merkezli veri
  - İç içe bir merkez grubu ve onu çevreleyen halka biçimli bir grup, insan gözüyle kolayca iki kümeye ayrılır; ama iki grubun merkezi aynı olduğu için K-Means bu kümeleri ayıramaz (ekrandan, 01:45:00).
- EM kümeleme çok önemli bir konudur
  - Hoca konuyu dikkatle dinlemeyi ve paylaşılan dokümanın tek boyutlu bölümünü indislere dikkat ederek okumayı önerdi.
  - EM'de her nokta yeni merkezin hesabına kendi üyelik ağırlığıyla katılır; K-Means'te yalnız kümenin üyeleri ve tam ağırlıkla katılır.
- Olabilirlik ile sonsal olasılık karıştırılmamalı
  - $P(x_j \mid C_i)$ olabilirliktir ve normal dağılım denkleminden hesaplanır; $P(C_i \mid x_j)$ sonsal olasılıktır ve Bayes teoremiyle bulunur.
- Varyans neden yeniden hesaplanır
  - Normal dağılımın iki parametresi ortalama ve varyanstır; her iterasyonda olabilirliği yeniden hesaplayabilmek için ikisi de güncellenir.

## Kısa Tekrar Notları

- Kümeleme denetimsizdir; sınıf etiketi yoktur.
- Öklid = $L_2$, Manhattan = $L_1$; Minkowski $q = 1$'de Manhattan, $q = 2$'de Öklid olur.
- SMC $= (a + d)/(a + b + c + d)$; Jaccard $= d/(b + c + d)$.
- Örnek: $i = 10011011$, $j = 11000110$ için $a = 1$, $b = 2$, $c = 3$, $d = 2$; SMC $= 3/8$, Jaccard $= 2/7$.
- K-Means: $K$ verilir, başlangıç merkezleri seçilir, en yakın merkeze atanır, merkezler ortalamayla güncellenir, değişiklik kalmayana kadar tekrar edilir.
- Eşit uzaklıkta örnek herhangi bir kümeye atanabilir; iterasyon yanlış atamayı düzeltir.
- K-Means sert atama, EM yumuşak atama yapar.
- EM, M adımında ağırlıklı ortalama, ağırlıklı varyans ve küme olasılığını yeniden hesaplar.
- Uygun $K$ için dirsek yöntemi; $K$ bilinmeden kümeleme için hiyerarşik kümeleme gibi yöntemler vardır.

## Detaylı Açıklamalar

- Uzaklık ve benzerlik ölçüleri
  - Kümeleme, örnekleri benzerliklerine göre gruplar; bu yüzden önce uzaklık ya da benzerlik ölçüsü seçilir. Sayısal öz niteliklerde en sık Öklid ve Manhattan uzaklıkları kullanılır. Manhattan uzaklığı, iki nokta arasında binaların arasından yürüyormuş gibi yalnız eksenlere paralel hareketle gidilen yolu ölçer: önce bir eksendeki farkın mutlak değeri, sonra diğer eksendeki farkın mutlak değeri alınıp toplanır. Öklid uzaklığı iki nokta arasındaki düz çizgidir. Hoca, Minkowski uzaklığının hesap karmaşıklığı yüksek olduğu için hesaplarda çoğunlukla Öklid ya da şehir bloğu uzaklığının tercih edildiğini söyledi.
  - İkili öz nitelikte (evet/hayır, 0/1) uzaklık yerine eşleşme sayılarına dayanan benzerlik ölçüleri kullanılır. Ekrandaki örnekte $i = 10011011$ ve $j = 11000110$ sekiz boyutlu ikili örneklerdir (ekrandan, 00:35:00). Tahtada eşleşmeler sayıldı: bir 0-0 eşleşmesi ($a = 1$), iki 0-1 eşleşmesi ($b = 2$), üç 1-0 eşleşmesi ($c = 3$) ve iki 1-1 eşleşmesi ($d = 2$). Buradan $\text{Sim}_{SMC} = (1 + 2)/8 = 3/8$ ve $\text{Sim}_{Jaccard} = 2/(2 + 3 + 2) = 2/7$ bulundu (ekrandan, 00:40:00).
  - Ders sonrası not: Slaytta Jaccard benzerliği $2/8$ yazıyor (ekrandan, 00:35:00). Tanıma göre payda $b + c + d = 7$ olduğundan doğrusu hocanın tahtada bulduğu $2/7 \approx 0.286$ değeridir.
- K-Means sayısal örneği ($K = 2$)
  - Veri: 1 (1.0, 1.0), 2 (1.5, 2.0), 3 (3.0, 4.0), 4 (5.0, 7.0), 5 (3.5, 5.0), 6 (4.5, 5.0), 7 (3.5, 4.5) (ekrandan, 00:55:00). Başlangıç merkezleri 1. ve 4. örneklerdir.
  - Birinci iterasyonda Öklid uzaklıkları hesaplanır; örneğin 1. örneğin 2. merkeze uzaklığı $\sqrt{(1-5)^2 + (1-7)^2} = \sqrt{52} \approx 7.21$'dir. 3. örnek iki merkeze de 3.61 uzaklıktadır; birinci kümeye atanır. Kümeler {1, 2, 3} ve {4, 5, 6, 7}, yeni merkezler $m_1 = (1.83, 2.33)$ ve $m_2 = (4.12, 5.38)$ olur (ekrandan, 01:20:00).
  - İkinci iterasyonda 3. örnek ikinci merkeze daha yakındır (2.04'e karşı 1.78). Kümeler {1, 2} ve {3, 4, 5, 6, 7}, merkezler $m_1 = (1.25, 1.5)$ ve $m_2 = (3.9, 5.1)$ olur (ekrandan, 01:25:00). Bir sonraki iterasyonda atama değişmez.
  - Aynı veri $K = 3$ ve başlangıç merkezleri 1, 2, 3 ile çözüldüğünde kümeler {1}, {2}, {3, 4, 5, 6, 7} olur; üçüncü merkez $(3.9, 5.1)$'dir ve ikinci adımda atama değişmez (ekrandan, 01:30:00).
- İlaç örneği
  - Dört ilaç (A, B, C, D) ağırlık indeksi ve pH değeriyle verilir: A (1, 1), B (2, 1), C (4, 3), D (5, 4). Başlangıç merkezleri $c_1 = (1,1)$ ve $c_2 = (2,1)$'dir. Uzaklık matrisinin satırları merkezleri, sütunları nesneleri gösterir: $D^0$'ın satırları $[0,\ 1,\ 3.61,\ 5]$ ve $[1,\ 0,\ 2.83,\ 4.24]$'tür (ekrandan, 01:35:00).
  - İlk atamada A birinci, B, C, D ikinci kümededir; ikinci merkez $(3.67, 2.67)$ olur. Sonraki iterasyonda B birinci kümeye geçer ve her kümede iki ilaç kalır.
- EM kümeleme
  - Bayes teoremi: $P(C_i \mid x_j) = \dfrac{P(x_j \mid C_i) P(C_i)}{\sum_{a=1}^{k} P(x_j \mid C_a) P(C_a)}$. Paydaki terim normalizasyon terimidir.
  - Başlatma: her $C_i$ için $\mu_i$ ve $\sigma_i^2$ rastgele atanır, $P(C_i) = 1/k$ alınır (ekrandan, 02:15:00).
  - Beklenti adımı: olabilirlik normal dağılımdan hesaplanır, $P(x_j \mid C_i) = \dfrac{1}{\sqrt{2\pi}\,\sigma_i} e^{-\frac{(x_j - \mu_i)^2}{2\sigma_i^2}}$; sonra Bayes teoremiyle $P(C_i \mid x_j)$ bulunur (ekrandan, 02:20:00).
  - Maksimizasyon adımı: $w_i(x_j) = P(C_i \mid x_j)$ ağırlığıyla $\mu_i' = \dfrac{\sum_{j=1}^{n} w_i(x_j)\, x_j}{\sum_{j=1}^{n} w_i(x_j)}$, $\sigma_i'^2 = \dfrac{\sum_{j=1}^{n} w_i(x_j)(x_j - \mu_i)^2}{\sum_{j=1}^{n} w_i(x_j)}$ ve $P'(C_i) = \dfrac{\sum_{j=1}^{n} w_i(x_j)}{\sum_{a=1}^{k}\sum_{j=1}^{n} w_a(x_j)}$ hesaplanır (ekrandan, 02:35:00). E ve M adımları ortalamalar çok az değişene kadar tekrarlanır.
  - K-Means, EM'in özel bir durumudur: olabilirlik, $x_j$ en yakın merkezin kümesindeyse 1, değilse 0 alınır; bu sert atamadır (ekrandan, 02:45:00).
- Uygulama alanları
  - Kümeleme görüntü işlemede renk kümelemesi için kullanılabilir: 24 bitlik (yaklaşık 16 milyon renkli) bir görüntüde renk sayısı, yalnız görüntüde bulunan renkler kümelenerek örneğin 16 renge indirilebilir. Hoca bu iş için K-Means'in yanında bulanık c-ortalamalar (fuzzy c-means) ve SOM yöntemlerinin de kullanılabildiğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
