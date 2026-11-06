# Ders 8 Çalışma Özeti

## Genel Konular

- Sınav karışıklığı ve vize, ödev duyuruları.
- Perceptron hatırlatması: $f(\mathbf{x}) = \text{sign}(\mathbf{w}^T\mathbf{x} + b)$.
- Perceptronun sorunları ve karar sınırının yerinin önemi.
- Destek vektör makineleri (Support Vector Machines, SVM): margin, destek vektörleri (support vectors).
- Margin genişliği $\frac{2}{\lVert \mathbf{w} \rVert}$ ve optimizasyon problemi.
- Lagrange çarpanları (Lagrange multipliers) ve dual problem.
- Yumuşak marjin (soft margin), gevşek değişkenler (slack variables) ve $C$ parametresi.
- Doğrusal ayrılamayan veriler için kernel fonksiyonları.
- Çok sınıflı (multi-class) SVM: one-against-one ve one-against-all.

## Hocanın Özellikle Vurguladığı Kısımlar

- İki sınıf arasına sonsuz sayıda karar sınırı çizilebilir. Hepsi eğitim örneklerini %100 doğru ayırabilir. Önemli olan test örneklerindeki başarıdır.
- Karar sınırının yeri, bilinmeyen bir örneğin hangi sınıfa atanacağını değiştirir. En iyi sınır, iki sınıfın birbirine en yakın örneklerine eşit uzaklıkta olandır. "İki sınıfın tam ortası" demek tam doğru değildir.
- Sınırı belirleyen örnekler "ön cephede savaşan" örneklerdir. Arkadaki örnekler sınır nereye konursa konsun doğru sınıflanır; sınıflandırmaya etkileri yoktur. Ön cephedeki örnekler destek vektörleridir.
- Matematiği ezberlemeniz gerekmiyor; neyin nereden çıktığını bilin.
- Margini maksimize etmek, $\lVert \mathbf{w} \rVert$'yi minimize etmek demektir.
- Sınıflandırmada yalnız destek vektörleri kullanılır ($\alpha_i > 0$ olanlar). k-NN'de işe yaramayan örneklerin elenmesine benzer.
- Özellik sayısı 3'ü geçince verinin doğrusal ayrılıp ayrılmadığını çizerek göremezsiniz. Farklı $C$ değerlerini ve farklı kernel'ları (lineer, polinom, RBF/Gaussian) doğrulama (validation) ile deneyip en iyi modeli seçin. Lineer kernel da iyi sonuç verebilir.
- Hangi yöntemin başarılı olacağı her zaman probleme ve veriye bağlıdır.
- One-against-all, gerçek uygulamalarda çoğunlukla one-against-one'dan daha başarılıdır. Hoca başta tersini beklediğini söyledi.
- Sınavda cevaplar en fazla üç cümle olmalı. Uzun cevapta yarısı doğru yarısı yanlış olunca puan vermek zorlaşıyor.

## Kısa Tekrar Notları

- Hiper düzlem: $\mathbf{w}^T\mathbf{x} + b = 0$. $b$ bias'tır; hiper düzlemi orijinden kaydırır (perceptrondaki $w_0$ / eşik).
- $\mathbf{w}$ hiper düzleme diktir.
- Margin sınırları: $\mathbf{w}^T\mathbf{x} + b = +1$ ve $\mathbf{w}^T\mathbf{x} + b = -1$.
- Kısıt: $y_i(\mathbf{w}^T\mathbf{x}_i + b) \ge 1$, $y_i \in \{+1, -1\}$.
- Margin: $M = \dfrac{2}{\lVert \mathbf{w} \rVert}$. Maksimize etmek için $\dfrac{1}{2}\lVert \mathbf{w} \rVert^2$ minimize edilir.
- Çözüm: $\mathbf{w} = \sum_{i} \alpha_i y_i \mathbf{x}_i$. $\alpha_i > 0$ olan örnekler destek vektörleridir; $\alpha_i = 0$ olanlar değildir.
- Karar fonksiyonu: $f(\mathbf{z}) = \text{sign}\left(\sum_{i \in SV} \alpha_i y_i \, \mathbf{x}_i^T\mathbf{z} + b\right)$.
- Soft margin: $\min \frac{1}{2}\lVert \mathbf{w} \rVert^2 + C\sum_i \xi_i$, $\;y_i(\mathbf{w}^T\mathbf{x}_i + b) \ge 1 - \xi_i$, $\;\xi_i \ge 0$, $\;0 \le \alpha_i \le C$.
- Kernel ile karar fonksiyonu: $f(\mathbf{z}) = \text{sign}\left(\sum_{i \in SV} \alpha_i y_i \, K(\mathbf{x}_i, \mathbf{z}) + b\right)$.
- Çok kullanılan kernel'lar: polinom, Gaussian, radyal tabanlı (RBF).
- Çok sınıf: one-against-one (her sınıf çifti için bir SVM), one-against-all (her sınıf için "bu sınıf / geri kalan hepsi" SVM'i).

## Detaylı Açıklamalar

### 1. Perceptron Hatırlatması ve Sorunları

- Giriş $\mathbf{x} = (x_1, \dots, x_n)$, çıkış $f(\mathbf{x}) = \text{sign}(\mathbf{w}^T\mathbf{x} + b)$. Burada $\mathbf{w}^T\mathbf{x} = w_1x_1 + w_2x_2 + \dots + w_nx_n$ (dot product).
- $b$ (bias) hiper düzlemin orijine göre konumunu ayarlar. Perceptronda bunu $x_0 = 1$ girişine bağlı $w_0$ ağırlığı ya da eşik olarak görmüştük.
- Hiper düzlemin bir tarafı $\mathbf{w}^T\mathbf{x} + b > 0$, diğer tarafı $< 0$ bölgesidir. Sign fonksiyonu ile çıkış $+1$ veya $-1$ olur.
- Hoca bu yapıyı uzun uzun hatırlattı; SVM'de benzer yapı kullanılıyor.
- Tek katmanlı perceptronun sorunları:
  - Yavaş öğrenir.
  - Özellik sayısı artınca aşırı öğrenme (overfitting) sorunu vardır.
  - Doğrusal ayrılamayan problemleri çözemez.
  - Asıl büyük sorun: karar sınırını rastgele bir yere koyar.

### 2. Karar Sınırının Yeri

- İki özellikli ($x_1, x_2$) iki sınıf düşünelim. Aralarına sonsuz sayıda karar sınırı çizilebilir (bir öğrenci "sonsuz" diye cevap verdi).
- Örnek: Aynı bilinmeyen örnek, bir karar sınırına göre B sınıfına, başka bir karar sınırına göre A sınıfına düşer.
- Sonuç: Karar sınırının yeri test başarısını belirler.
- Bir öğrenci sınırın iki sınıfın ortasında olması gerektiğini söyledi. Hoca daha doğru ifadeyi verdi: sınır, iki sınıfın birbirine en yakın örneklerine eşit mesafede olmalı. Böylece "eşit şartlarda savaş" sağlanır.
- Sınır bir sınıfa yakın olursa eğitimde başarı yüksek olabilir ama testte düşer.

### 3. Destek Vektör Makineleri

- SVM, Vapnik ve arkadaşlarının (hoca "Ruslar tarafından" dedi) 1992'de ortaya attığı bir yaklaşımdır. 2000'lerde popüler oldu.
- Slayttaki tarihçe: el yazısı karakter tanımada yaklaşık %1,1 test hatası verdi. Bu, özel tasarlanmış LeNet yapay sinir ağının hatasıyla aynı seviyedeydi.
- Derin öğrenme yaygınlaşana kadar en başarılı ve en çok kullanılan yöntemlerden biriydi.
- En önemli özelliği: doğrusal ayrılabilen sınıflarda başarılıdır; kernel kullanımıyla doğrusal ayrılamayan sınıflarda da başarılıdır.
- "Destek vektörü" adı: her örnek bir vektördür (2 özellik de olabilir, 20 özellik de). Sınırı koruyan ve karar sınırının nereye çizileceğini belirleyen örnekler destek vektörleridir.

**Margin**

- Sınıra en yakın örneklerden geçen iki paralel düzlem arasındaki bölgeye margin denir.
- Karar sınırı margin'in tam ortasına çizilir. Margin $M$ ise her iki tarafa uzaklık $M/2$'dir: $d_+ = d_-$, $\;M = d_+ + d_-$.
- Amaç: margin'i maksimum yapan hiper düzlemi bulmak.

**Matematik**

- Bir $\mathbf{x}$ noktasının hiper düzleme uzaklığı:

$$d = \frac{\lvert \mathbf{w}^T\mathbf{x} + b \rvert}{\lVert \mathbf{w} \rVert}, \qquad \lVert \mathbf{w} \rVert = \sqrt{w_1^2 + w_2^2 + \dots + w_n^2}$$

- Destek vektörleri tam margin sınırındadır. Bu noktalarda $\mathbf{w}^T\mathbf{x} + b = \pm 1$ olur. Bu yüzden her destek vektörünün hiper düzleme uzaklığı $\frac{1}{\lVert \mathbf{w} \rVert}$'dir.
- Margin:

$$M = \frac{2}{\lVert \mathbf{w} \rVert}$$

- $\lVert \mathbf{w} \rVert$ paydada olduğu için margin'i maksimize etmek $\lVert \mathbf{w} \rVert$'yi minimize etmek demektir. Eşdeğer olarak $\frac{1}{2}\lVert \mathbf{w} \rVert^2$ minimize edilir.
- Kısıtlar:
  - $y_i = +1$ için $\mathbf{w}^T\mathbf{x}_i + b \ge 1$
  - $y_i = -1$ için $\mathbf{w}^T\mathbf{x}_i + b \le -1$
  - Tek ifadeyle: $y_i(\mathbf{w}^T\mathbf{x}_i + b) \ge 1$, yani $y_i(\mathbf{w}^T\mathbf{x}_i + b) - 1 \ge 0$.
- $\mathbf{w}^T\mathbf{x}$ yazılmasının sebebi ikisinin de vektör olmasıdır; iç çarpım $w_1x_1 + w_2x_2 + \dots$ demektir.

**Öğrenci sorusu: Karar sınırı sıfırken neden $\pm 1$ yazıyoruz?**

- Karar sınırı $\mathbf{w}^T\mathbf{x} + b = 0$'dır.
- Perceptronda örneklerin sınıra uzaklığıyla ilgilenmiyorduk; sınırın sıfır olması yetiyordu.
- SVM'de sınırı iki sınıfın sınır örneklerine eşit uzaklığa koymak istiyoruz. Bunun için margin'i hesaplamak gerekir.
- Margin üzerindeki örnekler $\mathbf{w}^T\mathbf{x} + b = +1$ ve $\mathbf{w}^T\mathbf{x} + b = -1$ düzlemlerindedir. $y_i$ de $+1$ veya $-1$ olduğu için kısıt $y_i(\mathbf{w}^T\mathbf{x}_i + b) \ge 1$ şeklinde yazılır.

**Lagrange çarpanları ve dual problem**

- İki şart birlikte sağlanmalıdır: $\frac{1}{2}\lVert \mathbf{w} \rVert^2$ minimum olmalı ve $y_i(\mathbf{w}^T\mathbf{x}_i + b) \ge 1$ kısıtı sağlanmalı.
- Bu, Lagrange çarpanları ($\alpha_i \ge 0$) ile çözülür:

$$L(\mathbf{w}, b, \boldsymbol{\alpha}) = \frac{1}{2}\lVert \mathbf{w} \rVert^2 - \sum_{i=1}^{N} \alpha_i \left[ y_i(\mathbf{w}^T\mathbf{x}_i + b) - 1 \right]$$

- Hoca çözüme girmedi, yalnız sonucu verdi:
  - $\sum_{i=1}^{N} \alpha_i y_i = 0$
  - $\mathbf{w} = \sum_{i=1}^{N} \alpha_i y_i \mathbf{x}_i$
  - $\alpha_i > 0$ ise $\mathbf{x}_i$ destek vektörüdür (margin üzerindedir).
  - $\alpha_i = 0$ ise $\mathbf{x}_i$ destek vektörü değildir (arkadaki örnek).
- Bilinmeyen bir $\mathbf{z}$ örneği (query sample) için:

$$f(\mathbf{z}) = \sum_{i \in SV} \alpha_i y_i \, \mathbf{x}_i^T\mathbf{z} + b$$

- $f(\mathbf{z}) > 0$ ise A sınıfı, $< 0$ ise B sınıfı. Örnek: spam olan ve olmayan mailler (ikili sınıflandırma, binary classification).
- $\alpha_i = 0$ olan örnekler toplama katkı vermez. Bu yüzden sınıflandırmada yalnız destek vektörleri kullanılır.
- Hoca bu yaklaşımı çok beğendiğini söyledi: yapay sinir ağlarının (MLP dahil) sınıflandırma başarısının düşük olma sorununu margin'i maksimize ederek çözmüşler.

### 4. Soft Margin ve Gevşek Değişkenler

- Bir öğrenci aykırı değerlerin (outlier) etkisini sordu.
- Uzakta, arkada kalan bir aykırı değerin etkisi yoktur. Ama sınırın yakınında, ters tarafa kaymış birkaç örnek sorun olur.
- Bu örneklere göre sınır çizilirse margin gereksiz yere daralır ve sınıflandırma başarısı düşer. Çözüm, margin hesabını yumuşatmaktır: soft margin.
- Gevşek değişken (slack variable) $\xi_i \ge 0$ eklenir. Kısıtlar şöyle olur:
  - $y_i = +1$ için $\mathbf{w}^T\mathbf{x}_i + b \ge 1 - \xi_i$
  - $y_i = -1$ için $\mathbf{w}^T\mathbf{x}_i + b \le -1 + \xi_i$
- Hocanın tahtadaki örnekte örnek türleri:
  - **1:** margin üzerindeki destek vektörleri (margin support vectors), $\xi_i = 0$, $0 < \alpha_i < C$.
  - **2:** margin içine girmiş ama doğru tarafta kalan örnekler (non-margin support vectors), $0 < \xi_i < 1$.
  - **3:** yanlış tarafa geçmiş örnekler (hatalar), $\xi_i > 1$.
- Optimizasyon problemi:

$$\min_{\mathbf{w}, b, \boldsymbol{\xi}} \; \frac{1}{2}\lVert \mathbf{w} \rVert^2 + C\sum_{i=1}^{N} \xi_i$$

- $C$ düzenleme sabitidir (regularization constant, trade-off parametresi). Önceki yaklaşımdan tek fark $C$ ve $\xi_i$'lerin eklenmesidir.
- Lagrange çarpanlarına bir üst sınır gelir: $0 \le \alpha_i \le C$.
- $C$ büyüdükçe yanlış sınıflandırmaya verilen ceza artar; eğitimde yanlış sınıflanan örnek sayısı azalır. $C$ küçüldükçe margin genişler ve sınır daha esnek olur.

### 5. Kernel Fonksiyonları

- Doğrusal ayrılamayan veride sınıfları bir doğruyla ayırmaya çalışmak kötü sonuç verir.
- SVM'in en faydalı özelliklerinden biri: bir dönüşüm (mapping) ile örnekleri başka bir uzaya taşıyıp orada doğrusal ayrılabilir hale getirmek.
- Bu dönüşüm kernel fonksiyonlarıyla yapılır. Karar fonksiyonundaki iç çarpım $\mathbf{x}_i^T\mathbf{z}$ yerine $K(\mathbf{x}_i, \mathbf{z})$ yazılır.
- Örnek (2. derece polinom kernel): $\mathbf{x} = (x_1, x_2)$ eğitim örneği, $\mathbf{y} = (y_1, y_2)$ bilinmeyen örnek ise

$$K(\mathbf{x}, \mathbf{y}) = (1 + x_1y_1 + x_2y_2)^2 = (1 + \mathbf{x}^T\mathbf{y})^2$$

- Çok kullanılan kernel'lar:
  - Polinom (derece $d$): $K(\mathbf{x}, \mathbf{y}) = (\mathbf{x}^T\mathbf{y} + 1)^d$
  - Gaussian / radyal tabanlı (RBF): $K(\mathbf{x}_i, \mathbf{x}_j) = \exp\left(-\dfrac{\lVert \mathbf{x}_i - \mathbf{x}_j \rVert^2}{2\sigma^2}\right)$
- Kernel'lı karar fonksiyonu:

$$f(\mathbf{z}) = \sum_{i \in SV} \alpha_i y_i \, K(\mathbf{x}_i, \mathbf{z}) + b$$

- Kendiniz yazmayacaksınız, hazır kütüphane kullanacaksınız. Ama kütüphaneye "Gaussian kernel kullan" dediğinizde yaptığı şey budur: her destek vektörü ile test örneğine kernel uygular, sonuçları toplar, işaretine göre sınıfı belirler.
- Pratik öneri: farklı $C$ değerleri ve farklı kernel'larla (lineer, polinom, RBF, Gaussian) modeli doğrulama verisiyle deneyin; en iyi sonuç vereni seçin.

### 6. Çok Sınıflı SVM

- SVM temelde ikili sınıflandırıcıdır. Tüm sınıfları tek seferde ayıran yöntemler azdır, karmaşık ve yavaştır.
- Çok kullanılan iki yaklaşım vardır.

**One-against-one (bire karşı bir)**

- Eğitim: her sınıf çifti için bir SVM hazırlanır. 4 sınıf (A, B, C, D) için A-B, A-C, A-D, B-C, B-D, C-D.
- Eğitim test aşamasında asla yapılmaz; çok yavaş olur. SVM'ler bir kez hazırlanır ve saklanır.
- Test (hocanın örneği):
  1. Bilinmeyen $\mathbf{x}$ önce A-B SVM'ine verilir. Sonuç $> 0$ çıkar: A. B elenir.
  2. C-D SVM'ine verilir. Sonuç $> 0$ çıkar: C. D elenir.
  3. Kalan A ve C için A-C SVM'ine verilir. Sonuç negatif çıkar: C.
  4. Karar: $\mathbf{x}$ C sınıfına aittir.

**One-against-all (bire karşı hepsi)**

- Eğitim: her sınıf için bir SVM hazırlanır. Bir tarafta o sınıf, karşı tarafta diğer tüm sınıflar karışık bulunur: A / BCD, B / ACD, C / ABD, D / ABC.
- Kullanım örnekleri: yüz tespiti (yüz / yüz olmayan), yaya tespiti (insan / araç, ev, elektrik direği...), hakaret içeren mesaj tespiti (hakaret / diğer tüm mesajlar).
- Test: bilinmeyen örnek dört SVM'e de verilir. Örneği pozitif sınıflayan SVM'in sınıfı seçilir. Örnek: ilk üçü negatif, D/ABC pozitif ise örnek D sınıfına aittir.
- Kütüphanelerde eğitim örneğini verirken çıkışını ($+1$ / $-1$) siz belirlersiniz.

**Öğrenci sorusu: Karşı sınıftaki dağılım eşit olmalı mı?**

- Zorunlu değil. Ama çok dengesiz olursa başarı düşebilir: örneğin 2 elektrik direği, 98 araç koyarsanız elektrik direğinin etkisi az olur.
- Tavsiye: karşı sınıf olabildiğince çeşitli ve dengeli dağılmış olsun.
- Karşı sınıf iyi çeşitlendirilirse, eğitimde hiç görülmemiş türden bir örnek geldiğinde bile sistem genellikle hata yapmaz.

**Hangisi daha başarılı?**

- Öğrenciler farklı tahminler yaptı. Bir öğrenci one-against-one'da sınıf sayısı arttıkça işlemin karmaşıklaştığını belirtti.
- Hoca: genellikle one-against-all daha başarılıdır. Hoca başta one-against-one'ın daha "saf" sınıflarla çalıştığı için daha iyi olacağını düşünmüştü. One-against-all, SVM dışındaki sınıflandırıcılarda da en çok kullanılan veri bölme yaklaşımıdır.

### Ders sonrası notlar

- **Sınav karışıklığı:** Vize bir hafta sonraya (1 Aralık 2020) ertelenmişti ama hoca bunu unutup sınavı bu sabah sisteme yükledi. Öğrenciler uyarınca ders 10:30'da başladı. Haber WhatsApp grubundan verildi; grupta olmayan bazı öğrenciler bilgiyi alamadı, bazıları sınavı çözüp yükledi.
- **Duyurular:**
  - Vize haftaya, 1 Aralık 2020 Salı saat 10:00'da yapılacak.
  - Bu sabah yüklenen sınav soruları hazırlık için kullanılacak. Vizede benzer, elle çözülecek sorular gelecek.
  - Cevaplar en fazla üç cümle olmalı.
  - Ödev bu hafta Cuma (27 Kasım 2020) verilecek, süresi yaklaşık bir hafta. Hoca ödevlerin ikinci vize gibi değerlendirilmesinin bu sistemde daha uygun olacağını söyledi.
  - Duyurular normalde GSİS üzerinden yapılıyor (e-posta gidiyor).
  - Bu dönem slayt paylaşılmıyor. Yalnız yapay sinir ağları slaytları (örnekler içerdiği için) Online Yıldız'da "Ders Dokümanları > Genel" altına konuldu.
- **Hocanın gerekçesi:** Uzaktan eğitimde "nasılsa kaydediliyor" diye dersi takip etmeyen öğrenciler var. Hoca geri beslemeye ihtiyaç duyduğunu, slayt paylaşılırsa kimsenin dersi dinlemeyeceğini düşündüğü için bu dönem slayt paylaşmama kararı aldığını söyledi.
- **Düzeltmeler:**
  - Hoca $\alpha_i$ için bir yerde "alfa i'nin 0 olduğu yerlerde x'ler support vektörleri veriyor" dedi. Doğrusu: $\alpha_i > 0$ olan örnekler destek vektörüdür; $\alpha_i = 0$ olanlar değildir. Hoca hemen ardından doğru söyledi.
  - Soft margin örnek türlerinde hoca "margin'deyse $\alpha_i = 0$, margin içindeyse $\alpha_i < 1$, hataysa $\alpha_i > 1$" gibi ifadeler kullandı. Standart gösterimde bu ayrım $\xi_i$ ile yapılır: $\xi_i = 0$ (margin üzerinde/dışında), $0 < \xi_i < 1$ (margin içinde, doğru tarafta), $\xi_i > 1$ (yanlış sınıflanmış). $\alpha_i$ için ise $0 \le \alpha_i \le C$ geçerlidir; margin içindeki ve hatalı örneklerde $\alpha_i = C$ olur.
  - Hoca "C ne kadar büyürse o kadar daha esnek" dedi. Standart yorum: büyük $C$ hatalara daha çok ceza verir, margin daralır, eğitim hatası azalır (daha az esnek, aşırı öğrenme riski artar). Küçük $C$ daha geniş ve esnek bir margin verir.
  - One-against-one / one-against-all karşılaştırmasında hoca bir cümlede "gerçek uygulamalarda çoğunlukla one-against-one'ın daha iyi sonuç verdiğini gördüm" dedi. Bağlamdan ve hemen önceki cümleden kastı one-against-all'dur.
  - Bu ders anlatımında one-against-one'ı tam turnuva (eleme) gibi anlattı. Kütüphanelerde one-against-one genelde tüm $\frac{k(k-1)}{2}$ SVM'i çalıştırıp oylama (voting) ile karar verir.
- **Ders düzeni:** Hocanın bilgisayarının şarjı ve internet bağlantısı birkaç kez kesildi. 00:32-00:46 arası bağlantı koptu; bir öğrenci 10 dakika ara verildiğini duyurdu. 01:13-01:20 ve 01:48-01:49 arasında da kopma var. Hoca bir süre yazamadan, slayttan anlattı.
- **Kayıt:** Hoca kayıtlara karşı değil. Online eğitim sistemindeki yazılım hakkındaki eleştirilerini "kayıtlara geçecek ama" diyerek dile getirdi.

> **Not:** Bu özeti ve dersin altyazı dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
