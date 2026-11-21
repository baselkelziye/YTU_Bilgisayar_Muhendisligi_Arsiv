# Ders 10 Genişletilmiş Notu: Geri Yayılımın Türetilmesi ve Çok Katmanlı Algılayıcı Uygulama Notları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı
- 2. Mantık kapıları ve doğrusal ayrılabilirlik
- 3. Tek nöron: preaktivasyon, aktivasyon ve karar doğrusu
- 4. Çok katmanlı algılayıcının yapısı
- 5. Hata, ileri geçiş ve geri geçiş
- 6. Epoch, batch ve doğrulama kümesi
- 7. Zincir kuralı ile çıkış ağırlığının türetilmesi
- 8. Gizli katman ağırlıklarına genelleme
- 9. Öğrenme oranı
- 10. Uygulama notları: ağırlık başlatma ve giriş ölçekleme
- 11. MNIST üzerinde çok katmanlı algılayıcı
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı

Bu ders, bir önceki derste hocanın slaytlarla anlattığı geri yayılım (backpropagation) algoritmasının uygulamalı bir tekrarıdır. Dersi bir araştırma görevlisi verir. Amaç, tek bir nörondan başlayıp yapıyı adım adım çok katmanlı algılayıcıya (multilayer perceptron, MLP) kadar büyütmek ve her adımda optimizasyonun nasıl yapıldığını göstermektir. Formüllerin nereden geldiği tek tek çıkarılır.

## 2. Mantık Kapıları ve Doğrusal Ayrılabilirlik

Anlatım, sık kullanılan bir örnekle başlar: mantık kapılarının davranışını modellemek. Slaytta AND, OR ve XOR fonksiyonları iki girişli bir düzlemde çizilmiştir (ekrandan, 00:20:00). Yatay eksen birinci girişi, dikey eksen ikinci girişi gösterir. Dört nokta $(0,0)$, $(1,0)$, $(0,1)$ ve $(1,1)$ girişlerine karşılık gelir. İçi boş (beyaz) daireler çıkışın 1, dolu (siyah) daireler çıkışın 0 olduğunu gösterir.

- AND: yalnız $(1,1)$ beyazdır, diğer üç nokta siyahtır.
- OR: yalnız $(0,0)$ siyahtır, diğer üç nokta beyazdır.
- XOR: $(0,0)$ ve $(1,1)$ siyah, $(1,0)$ ve $(0,1)$ beyazdır.

Çıkışa göre etiketlenen noktalar iki küme oluşturur. AND ve OR için bu iki küme elinizi kaldırmadan çekilen tek bir düz çizgiyle ayrılabilir. XOR için bu yapılamaz. İlk iki problem doğrusal olarak ayrılabilir (linearly separable), üçüncüsü ayrılamaz.

**Soru:** İlk iki fonksiyonun üçüncüsünden farkı nedir? **Cevap:** XOR doğrusal olarak ayrılamaz.

Bu farkın ağ tasarımına etkisi şudur: doğrusal ayrılabilen bir problem tek bir nöronla çözülebilir. XOR tek nöronla çözülemez, tek katman yetmez.

## 3. Tek Nöron: Preaktivasyon, Aktivasyon ve Karar Doğrusu

### 3.1 Tek nöron bir doğrusal sınıflayıcıdır

Tek bir nöron aslında bir doğrusal sınıflayıcıdır. İki sınıflı veri tek bir doğruyla ayrılabiliyorsa, tek nöron bu ayrımı yapabilir. Doğrunun matematiksel bir denklemi vardır ve nöronun parametreleri bu denkleme karşılık gelir.

Slayttaki nöronun iki girişi $X_1$ ve $X_2$, bir de bias girişi $b$ vardır. Bunların ağırlıkları $w_1$, $w_2$ ve $w_3$'tür (ekrandan, 00:25:00). $X_1$ ve $X_2$ elimizdeki özelliklerdir (feature), örneğin bir noktanın düzlemdeki $x$ ve $y$ konumları. Bias için iki parametre ($w_3$ ve $b$) görülmesi önemli değildir: biri hep 1'dir, diğeri optimize edilir. Kaynaklarda bazen $b$, bazen $w_3$ yazılır. Bias küçük ama çok önemli bir parametredir: bu örnekte çizilecek doğrunun orijinden geçmek zorunda kalmamasını sağlar.

### 3.2 Ağırlık başlatma ve preaktivasyon

Eğitimin başında ağırlıklara bir başlangıç değeri verilir: hepsi sıfır, hepsi bir ya da rastgele. Bu seçim başarımı etkiler ve "ağırlık başlatma" (weight initialization) adıyla ayrı bir süreçtir (bkz. Bölüm 10).

Nöronun ilk işi çarpmadır: $x_1$ ile $w_1$, $x_2$ ile $w_2$, 1 ile $w_3$ çarpılır ve toplanır (multiply-accumulate). Bu çarpımlar toplamı genelde $S$ ile gösterilir ve **preaktivasyon** adını alır, çünkü henüz yalnız toplama yapılmıştır:

$$S = x_1 w_1 + x_2 w_2 + \dots + b \cdot 1$$

(ekrandan, 01:10:00)

**Soru:** Girişlerin ağırlıklarla çarpılıp toplanmasıyla elde edilen değere ne denir? **Cevap:** Preaktivasyon, $S$.

### 3.3 Aktivasyon fonksiyonu ve değer aralığı

$S$ daha sonra bir aktivasyon fonksiyonundan geçer. Kaynaklarda $f$, $\varphi$ ya da $\theta$ ile gösterilir. Nöronun çıktısı $y = f(S)$ olur. Aktivasyon fonksiyonu ikili düşünülürse nöronun iletimde olup olmadığını, genel olarak da hangi aralıkta değer döndürdüğünü belirler.

En bilinenleri hiperbolik tanjant, sigmoid, signum ve ReLU'dur. 0-1 çıkışı istenirse birim basamak kullanılabilir; nöron o zaman mekanik bir anahtar gibi çalışır. Aktivasyon fonksiyonları hakkında söylenecek en önemli şey değer aralıklarıdır:

- ReLU pozitif değerlerde doğrusal artar.
- Sigmoid 0 ile 1 arasında değer alır.
- Tanh negatif tarafta $-1$'e yakınsar, değerleri $-1$ ile $1$ arasındadır.

Bu aralık önemlidir, çünkü tek nöron aynı zamanda çıkış nöronudur ve beklenen değerlerle elde edilen değerler karşılaştırılacaktır. Mantık kapısı örneğinde beklenen değerler 1 ve 0 diye kodlanmıştı. Seçilen aktivasyona göre nöronun çıkışında sayısal değerler elde edilir ve optimizasyon, beklenenle elde edilen arasındaki farka (genelde bir hata fonksiyonuna) dayanır.

### 3.4 Karar doğrusunun denklemi

Doğrusal ayrılabilen yuvarlak ve yıldız (slaytta sarı daireler ve kırmızı yıldızlar) sınıfları $-100$ ile $100$ arasında iki özellik üzerinde çizilmiştir; aralarında mavi bir ayırıcı doğru vardır (ekrandan, 00:30:00). Tek nöronun doğrusal sınıflayıcı olmasının nedeni, ağırlıklar cinsinden bir doğru denklemi yazılabilmesidir. Genel doğru $ax + by + c = 0$ biçimindedir. Doğru orijinden geçseydi sabit terim olmazdı; $c$ doğruyu kaydırır ve bu rolü bias üstlenir.

Slayttaki türetme şöyledir (ekrandan, 00:30:00):

$$0 = w_1 \cdot feature_1 + w_2 \cdot feature_2 + w_3 \cdot b$$

$$0 = w_1 x + w_2 y + w_3 b$$

$b = 1$ alınarak eksenleri kesen noktalar bulunur: $x = 0$ için $y = \dfrac{-w_1 x - w_3}{w_2} = -\dfrac{w_3}{w_2}$, $y = 0$ için $x = \dfrac{-w_2 y - w_3}{w_1} = -\dfrac{w_3}{w_1}$. Bu iki noktadan eğim:

$$slope = \frac{y_2 - y_1}{x_2 - x_1} = \frac{0 + w_3/w_2}{-w_3/w_1 - 0} = -\frac{w_3/w_2}{w_3/w_1}$$

Sabit terim $x = 0$ konularak bulunur: $c = -w_3/w_2$. Sonuç:

$$feature_2 = -\frac{w_3/w_2}{w_3/w_1} \cdot feature_1 - \frac{w_3}{w_2}$$

Eğim sadeleştirilirse $-w_1/w_2$ olur (ara adım eklendi; python ile sayısal olarak doğrulandı).

Bu türetmenin verilme nedeni şudur: optimizasyonla $w_1$, $w_2$ ve $w_3$ bulunurken aslında bu doğruya uyan bir şeye erişilmeye çalışılır. Örneğin doğrusal ayrılabilen iki sınıflı rastgele veri üretilip ağ birkaç epoch eğitilebilir; eğitimden çıkan doğru ideal ayırıcı doğruyla karşılaştırılabilir.

## 4. Çok Katmanlı Algılayıcının Yapısı

### 4.1 Katmanlar ve tam bağlantı

Pratikte çok daha derin yapılar kullanılır. Girişteki $X_1, X_2, \dots$ giriş katmanını (input layer) oluşturur: okunan verinin ya da çıkarılan özelliğin kendisidir. Birinci katmandan itibaren çıkış katmanına kadar olan katmanlar gizli katmanlardır (hidden layer). Her katmanda bir ya da daha fazla nöron bulunur.

Bu derste tam bağlı (fully connected) ağlar ele alınır: herhangi bir nöron, önündeki katmanın bütün nöronlarıyla ilişkilidir. İlişki, ağırlıkla çarpılan değerin ilgili nöronun aktivasyonuna gitmesi demektir. Bazı bağlantılar yoksa ağ budanmış (pruned) olur; bunun için budama algoritmaları vardır.

Bu yapı biyolojik sinir hücresine benzetilerek kurulmuştur. Çevreden algılanan (perceive) veriler girişlerdir; "perceptron" adı da buradan gelir. Girişler 0,5, 0,2, 0,1 gibi ağırlıklarla çarpılır; ağırlıklar kimyasal nörotransmitterlere benzer. Çarpımların toplamı hücre çekirdeğinde aktivasyon fonksiyonundan geçer ve nöronun çıktısını oluşturur. Ağın en sonundaki çıkış ile olması gereken değer arasındaki hataya bakılır. Hata yoksa sorun yoktur; hata varsa bitilen yerden başlanan yere geri dönülerek optimizasyon yapılır.

### 4.2 Matris biçiminde hesap

Slaytta katmanlar arası hesap matrislerle gösterilir (ekrandan, 00:40:00):

- $i$: eğitim örneği sayısı.
- $j$: örnek boyutu (giriş katmanındaki nöron sayısı).
- $k$: ilk gizli katmanın boyutu; $n$: gizli katman sayısı (nohl, number of hidden layers).
- $p$: $(n-1)$. gizli katmanın boyutu.
- $m$: son gizli katmanın boyutu.
- $t$: çıkış katmanının boyutu.

Giriş matrisi $X_{i \times j}$, ilk ağırlık matrisi $W_{(1)}$ $j \times k$, $n$. ağırlık matrisi $W_{(n)}$ $p \times m$, çıkış ağırlık matrisi $W_{(n+1)}$ $m \times t$ boyutludur. Boyutların çarpıma uygun olmasına dikkat edilmelidir.

Son yıllarda derin öğrenmeye ilginin artmasının bir nedeni, eskiden paralel hesaplama ortamlarında matris çarpımının bu kadar verimli olmamasıdır. GPU'larla birlikte $X$ ve $W$ matrislerinin hızlı çarpımı mümkün oldu. İleri geçiş (forward pass), soldan sağa ağırlıklarla çarpıp aktivasyondan geçirerek girişten çıkışa bir yolculuktur; arka planda bir matris çarpımı ve bütün nöronlarda paralel aktivasyon vardır.

Genelde her katman için bir aktivasyon fonksiyonu seçilir; bazı uygulamalarda katmana göre aktivasyon değişebilir. Çıkış katmanında da değerler aktivasyondan geçer. Örneğin ikili hale getirilmiş ağlarda çıkışın da yalnız 0-1 üretmesi anlamlı olmadığı için çıkışa sigmoid gibi bir fonksiyon konabilir.

### 4.3 Gizli katman ve nöron sayısı

Gizli katman sayısı ve her katmandaki nöron sayısı problemin doğrusal olmama derecesine bağlıdır; XOR ile AND'in farklılaşması gibi. Giriş boyutu $j$ özellik sayısına, yani veriye bağlıdır. $k$, $m$ gibi derinlik ve genişlik değerleri ise ağ mühendisliği işidir ve büyük ölçüde deneme yanılmayla belirlenir. Doğrusallıktan uzaklaşan bölgeleri ayırmak için katman sayısı artar, ama büyük problemlerde bunun matematiğini kurmak kolay değildir; 3 katman, 4 katman, 200-100-100 gibi yapılar sezgisel olarak denenir.

Örnek olarak 1990'ların sonunda çıkan el yazısı rakam veri kümesi, iki gizli katmanlı bir ağla %95'in üzerinde test doğruluğuyla sınıflanabilir.

## 5. Hata, İleri Geçiş ve Geri Geçiş

### 5.1 Semboller

Slayttaki semboller şunlardır (ekrandan, 01:10:00):

- $x$: giriş (görüntü pikseli ya da özellik); $x_u$ giriş katmanındaki $u$. nöronun çıktısıdır.
- $w$: ağırlık; $w_{r_{u\_p}}$, $r$. katmandaki $u$. nöron ile $(r+1)$. katmandaki $p$. nöron arasındaki ağırlıktır.
- $b$: bias.
- $S$: preaktivasyon; $S_{r_u}$, $r$. katmanın $u$. nöronu içindir.
- $f$: aktivasyon fonksiyonu.
- $y$: gizli ya da çıkış katmanındaki bir nöronun gerçek çıktısı; $y = f(S)$.
- $E_{total} = E_1 + \dots + E_t$; $t$ çıkış nöronu sayısıdır.

Giriş, görüntü sınıflamada doğrudan piksel değerleri olabilir ya da örneğin bir CNN'den gelen özellikler olabilir.

### 5.2 Hata fonksiyonu

Çıkıştaki değerler probleme göre anlam taşır. Mantık problemi için beklenen değerler 0-1'dir. Çok sınıflı bir problemde beklenen değerlerin nasıl kodlandığına bağlıdır: 1, 2, 3, 4, 5 gibi mi, yoksa one-hot kodlama ile mi? Beklenen ile elde edilen arasında bir hata vardır ve bu hata optimize edilmelidir.

Çıkıştaki her nöron için bir hata ($E_1$'den $E_t$'ye) bulunur. Hata bir kayıp (loss) fonksiyonuyla hesaplanır: ortalama kare hata (MSE), hinge loss gibi. Anlatımda çıkış nöronunun hatası beklenen değer ile gerçek değerin farkının karesinin yarısı olarak alınır ve $E_{total}$ bütün çıkışların toplamıdır.
<!-- BELİRSİZ: hata fonksiyonunun slayttaki tam yazımı karelerde görünmüyor; altyazıya göre "farkın karesi, 1 bölü 2" biçimindedir. -->

> **Ders sonrası not:** Derste $\tfrac{1}{2}$ katsayısı için "ortalama alınıyor" denmiştir. Bu katsayı büyük olasılıkla türevde inen 2'yi sadeleştirmek için konur, ortalama anlamına gelmez.

Beklenen eksi gerçek ya da gerçek eksi beklenen yazılabilir; bu seçim delta kuralında güncelleme değerinin ağırlığa eklenip çıkarılacağını belirler.

### 5.3 Üç temel adım

- **İleri geçiş (feed forward, forward pass):** girişten başlayıp çarparak, toplayarak, aktivasyondan geçirerek çıkışa kadar gitmek ve hataları belirlemek.
- **Geri geçiş (backward pass):** bulunan hatalardan, aynı ağ üzerinde çıkıştan girişe doğru geri gitmek. Geri yayılım adını veren adım budur.
- **Güncelleme:** geri giderken ağırlıkları güncellemek.

Başta bir kez ileri gidilir, hataya bakılır, hatayı azaltmak için geri gidilir ve bu sırada ağırlıklar güncellenir. Amaç $E$ ile $W$ arasında bir optimizasyondur.

**Soru:** Hatanın en aza indirilmesi için hangi matematiksel işlem kullanılır? **Cevap:** Türev alınır; kısmi türevler üzerinden hata sıfıra yaklaştırılmaya çalışılır.

Amaç, $E$'nin $W$'ye göre değişimini bulmaktır. Bu bir optimizasyon problemidir ve gradyan düşümü ile delta kuralı geri yayılımda kullanılır. İleri geçişin kodunu yazmak çok zor değildir: kullanıcıdan gizli katman sayısı ve boyutları alınır, giriş boyutuna göre ağ kurulur ve soldan sağa gidilir. Zor kısım geri yayılımdır.

## 6. Epoch, Batch ve Doğrulama Kümesi

### 6.1 Örnek senaryo

Elde 100 eğitim görüntüsü (101-110 arası test için) olduğu düşünülür. Görüntüler gri tonlu ve $M \times N$ boyutludur; kuş, köpek, kedi gibi hayvan resimleridir. Bu bir CNN problemi değil, MLP ile görüntü sınıflamadır: hiçbir özellik çıkarılmadan pikseller doğrudan giriş katmanına verilir.

Optimizasyon sırasında veriler tek tek mi alınacak, gruplar halinde mi? Tek tek alınırsa birinci resim için ileri geçiş yapılır, aynı resmin hatasıyla geri gidilip ağırlıklar güncellenir, sonra ikinci resme geçilir. 100 resim için 100 adım yapılır.

**Soru:** Bütün resimler böyle bir kez geçince ne tamamlanmış olur? **Cevap:** Bir epoch. Epoch için eğitim kümesinin tamamı bir kez ağdan geçmelidir.

### 6.2 Batch

Batch'te örnekler gruplara ayrılır. 100 resim dörde bölünürse 25'erli gruplar olur.

**Soru:** Gruplara ayırmak dışında başka ne yapılır? **Cevap:** Hata toplu olarak düzeltilir.

Batch boyutu kadar görüntü için yalnız ileri geçiş yapılır. Bu sırada elde edilen toplam hataların ortalaması alınabilir ve optimizasyon o grubun hatası üzerinden bir kez yapılır. Yani her grup sonunda bir geri geçiş ve bir güncelleme olur. Slayttaki algoritma bu akışı gösterir (ekrandan, 00:45:00):

```text
Algorithm 1: Neural Network Training
for epoch <- 1 ... last_epoch
    for batch <- 1 ... (input_samples_count / batch_size)
        for elements_in_batch <- 1 ... batch_size
            for layer <- 1 ... hidden_layer_number+1
                do forward_path()
            end
        end
        for layer <- hidden_layer_number+1 ... 1
            do backward_path()
        end
        do update_weights()
    end
    do cross_validation_test()
end
```

Aynı slayttaki açıklama: bunların hepsi, batch boyutu $m$ ve eğitim kümesi boyutu $n$ olan aynı gradyan düşümü yaklaşımının örnekleridir. Stokastik gradyan düşümünde $m = 1$, batch gradyan düşümünde $m = n$, mini-batch'te $m = b$ ve $b < n$'dir; $b$ genelde $n$'ye göre küçüktür (ekrandan, 00:45:00).

Batch'in performans açısından avantajı açıktır: geri yayılımda çarpma işlemleri en çok zamanı alır ve her örnekte geri geçiş yapmak yerine grup başına bir kez yapılır. Anlatıcı, kendi kodunu analiz ettiğinde zamanın büyük kısmının geri yayılımdaki çarpmalarda geçtiğini görmüştür. Batch olmadan tek çekirdekte MNIST problemini çözmek pratikte mümkün değildir. Batch hem genelleme hem başarım açısından avantaj sağlar.

> **Ek bilgi (derste anlatılmadı):** Derste batch'in öğrenmeyi etkilemediği söylenir. Batch boyutu büyük olasılıkla eğitim dinamiğini etkiler: küçük batch'ler daha gürültülü gradyan verir, büyük batch'ler daha düzgün ama daha seyrek güncelleme yapar. Bu yüzden batch boyutu da ayarlanan bir hiperparametredir.

### 6.3 Doğrulama kümesi

K-katlı çapraz doğrulama (k-fold cross validation) gibi yöntemler de vardır. Her batch ya da her epoch sonunda, güncellenen ağırlıklarla başarım ölçülebilir. Bunun için eğitim kümesinin içinden bir alt küme ayrılır ama eğitime verilmez; buna doğrulama (validation) kümesi, ölçülen başarıma doğrulama doğruluğu denir. Eğitim sürerken test kümesiyle işiniz yoktur, çünkü test için eğitimin bitmesi gerekir. Doğrulama doğruluğu ise eğitim sırasında bilgi verir.

Amaç özetle şudur: $E_{total}$'ın ağırlığa göre kısmi türevi kullanılarak, sık çizilen üç boyutlu hata yüzeyi üzerinde minimuma, mümkünse küresel minimuma doğru yürümek ve hatanın en küçük olduğu noktadaki ağırlıkları bulmak.

## 7. Zincir Kuralı ile Çıkış Ağırlığının Türetilmesi

### 7.1 Zincir kuralına neden gerek var

Hata yüzeyinde yerel ve küresel minimumlar vardır; hedef hatanın en küçük olduğu ağırlık değerini bulmaktır. Bunun için $\partial E_{total} / \partial w$ gerekir. Ancak $E$ doğrudan $W$ cinsinden yazılamaz.

**Soru:** $E$'yi $W$ cinsinden nasıl yazarız? **Cevap:** Zincir kuralı (chain rule) ile.

Doğrudan yazılamayan ifade, yazılabilen ifadelerin çarpımı olarak kurulur: toplam hatanın çıktıya göre türevi, çıktının (aktivasyonun) preaktivasyona göre türevi ve preaktivasyonun ağırlığa göre türevi. Üç değer çarpılır; geri yayılımda en çok zaman alan kısım budur. $S$ ağırlıklar cinsinden yazılabilir; $y$ $S$ cinsinden yazılabilir; $E$ $y$ cinsinden yazılabilir. Paydalar ve paylar birbirini götürecek biçimde dizilir.

### 7.2 Güncellenecek ağırlık

İki gizli katmanlı bir örnekte çıkıştan geriye üç aralık vardır (çıkış-ikinci gizli, ikinci gizli-birinci gizli, birinci gizli-giriş). Son aralıktaki ağırlık $w_{(nohl+1)_{1\_1}}$ ile gösterilir: son gizli katmanın birinci nöronu ile çıkışın birinci nöronu arasındaki ağırlık (ekrandan, 01:15:00). Hedef:

$$\frac{\partial E_{total}}{\partial w_{(nohl+1)_{1\_1}}} = \frac{\partial E_{total}}{\partial y_{(nohl+1)_1}} \cdot \frac{\partial y_{(nohl+1)_1}}{\partial S_{(nohl+1)_1}} \cdot \frac{\partial S_{(nohl+1)_1}}{\partial w_{(nohl+1)_{1\_1}}}$$

(ekrandan, 01:20:00)

### 7.3 Birinci çarpan: hatanın çıktıya göre türevi

$E_{total} = E_1 + E_2 + \dots + E_t$ toplamında yalnız $E_1$, $y_{(nohl+1)_1}$'e bağlıdır; diğer terimler bu değişkeni içermediği için türevleri sıfırdır. $E_1$'in türevi "üssü başa indir, bir azalt, içinin türevini yaz" kuralıyla alınır.

### 7.4 İkinci çarpan: aktivasyonun türevi

Bu örnekte aktivasyon olarak hiperbolik tanjant kullanılır (ekrandan, 01:20:00):

$$y_{(nohl+1)_1} = \tanh\left(S_{(nohl+1)_1}\right) \qquad (4.9)$$

$$\frac{\partial y_{(nohl+1)_1}}{\partial S_{(nohl+1)_1}} = 1 - \tanh^2\left(S_{(nohl+1)_1}\right) \qquad (4.10)$$

Türevin doğruluğu python ile sayısal türevle kontrol edildi. Hangi aktivasyon kullanılıyorsa onun türevi bilinmelidir; ağ sıfırdan yazılırken geri yayılımda türev her zaman gerekir. Bu çarpan kolaydır, çünkü fonksiyon bellidir ve içine aldığı parametre zaten $S$'dir.

> **Hocanın vurgusu:** Hangi aktivasyon fonksiyonunu kullanıyorsanız onun türevini mutlaka belirtmeniz gerekir; geri yayılımda hep türeve ihtiyaç olur.

### 7.5 Üçüncü çarpan: preaktivasyonun ağırlığa göre türevi

Bu çarpan kullanılan hata fonksiyonuna (MSE, hinge, ortalama mutlak hata) ya da aktivasyona bağlı değildir. $S$'nin formülü bellidir:

$$S_{(nohl+1)_1} = y_{(nohl)_1} w_{(nohl+1)_{1\_1}} + y_{(nohl)_2} w_{(nohl+1)_{2\_1}} + \dots + b \cdot 1$$

(ara adım eklendi; slayttaki 4.1 biçiminin bu katmana uygulanmasıdır.) Bu ağırlığa bağlı tek terim ilk çarpım olduğu için diğerlerinin türevi sıfırdır ve sonuç $y_{(nohl)_1}$, yani ağırlığın bağladığı önceki nöronun çıktısıdır. Bu özellik ağın her yerinde aynıdır.

### 7.6 Delta kuralına geçiş

Gradyan düşümünden delta kuralına geçilerek ağırlık güncellenir (ekrandan, 01:25:00):

$$\hat{w}_{(nohl+1)_{1\_1}} = w_{(nohl+1)_{1\_1}} - \eta \cdot \frac{\partial E_{total}}{\partial w_{(nohl+1)_{1\_1}}} \qquad (4.14)$$

Güncellenecek ağırlık şapkalı yazılmalıdır. $\eta$ öğrenme oranıdır (learning rate; python kütüphanelerinde "lr" kısaltması görülür). Hata fonksiyonunda alınan işarete göre terim çıkarılır ya da eklenir.

Bütün kaynaklarda görülen $\delta$ terimi, zincir kuralının ilk iki çarpanını sembolize eder. Slayttaki tanım: "$\delta$, hataların ağırlıklı toplamını işlemek için tanımlanmıştır" (ekrandan, 01:25:00):

$$\delta_{(nohl+1)_1} = \frac{\partial E_{total}}{\partial y_{(nohl+1)_1}} \cdot \frac{\partial y_{(nohl+1)_1}}{\partial S_{(nohl+1)_1}} = \frac{\partial E_{total}}{\partial S_{(nohl+1)_1}} \qquad (4.15)$$

Üçüncü çarpan zaten $y_{(nohl)_1}$ olduğundan güncelleme şöyle yazılır:

$$\hat{w}_{(nohl+1)_{1\_1}} = w_{(nohl+1)_{1\_1}} - \eta \cdot \delta_{(nohl+1)_1} \cdot y_{(nohl)_1} \qquad (4.16)$$

Burada yeni bir şey yapılmamıştır: zincir kuralındaki iki çarpım bir katsayıyla ifade edilmiş, üçüncü çarpım ona eklenmiştir. $\delta$'nın asıl amacı, bu formülü ağın herhangi bir yerindeki ağırlığa genelleştirebilmektir. İnternetteki kaynaklar genelde yalnız bu son ağırlık örneğini gösterir, oysa bu formül tek başına yalnız en sağdaki çıkış ağırlıkları için geçerlidir.

## 8. Gizli Katman Ağırlıklarına Genelleme

### 8.1 Hatanın gizli nöron çıktısına göre türevi

Şimdi çıkışa bağlı olmayan, araya düşen bir ağırlık güncellenir: $w_{(nohl)_{1\_1}}$. Zincir kuralı bu ağırlık için yeniden yazılır; ikinci ve üçüncü çarpanlar ($\partial y / \partial S$ ve $\partial S / \partial w$) aynı kalır, değişen birinci çarpandır: $\partial E_{total} / \partial y_{(nohl)_1}$.

Gizli nöronun çıktısı bütün çıkış nöronlarını etkiler. Bu yüzden (ekrandan, 01:30:00):

$$\frac{\partial E_{total}}{\partial y_{(nohl)_1}} = \frac{\partial E_1}{\partial y_{(nohl)_1}} + \frac{\partial E_2}{\partial y_{(nohl)_1}} + \dots + \frac{\partial E_t}{\partial y_{(nohl)_1}}$$

Her terim yine zincir kuralıyla, sağdaki (çıkışa yakın) preaktivasyon üzerinden açılır:

$$\frac{\partial E_1}{\partial y_{(nohl)_1}} = \frac{\partial E_1}{\partial S_{(nohl+1)_1}} \cdot \frac{\partial S_{(nohl+1)_1}}{\partial y_{(nohl)_1}}, \qquad \frac{\partial E_1}{\partial S_{(nohl+1)_1}} = \frac{\partial E_1}{\partial y_{(nohl+1)_1}} \cdot \frac{\partial y_{(nohl+1)_1}}{\partial S_{(nohl+1)_1}}$$

Birleştirilince:

$$\frac{\partial E_{total}}{\partial y_{(nohl)_1}} = \sum_{u=1}^{t} \frac{\partial E_u}{\partial y_{(nohl+1)_u}} \cdot \frac{\partial y_{(nohl+1)_u}}{\partial S_{(nohl+1)_u}} \cdot \frac{\partial S_{(nohl+1)_u}}{\partial y_{(nohl)_1}}$$

(ekrandan, 01:30:00; slaytta açık toplam olarak yazılmıştır, toplam sembolüyle gösterim ara adım olarak eklendi.) Slayttaki ilk satırda son terim $E_z$ diye yazılmıştır; anlatıcı bunun $E_t$ olması gerektiğini belirtir.

Bu yapının önemi şudur: bir gizli nöronun türevi hesaplanırken çıkışa yakın preaktivasyonlar da işe girer. Böylece sağdan gelen $\delta$ değerleri geriye yayılır (propagate). $E_{total}$ yerine her terimde $E_u$ yazmak aynı sonucu verir, çünkü her $y_{(nohl+1)_u}$ yalnız kendi $E_u$ teriminde geçer; ama $E_{total}$ yazımı daha geneldir.

### 8.2 Delta ve ağırlık cinsinden yazım

İlk iki çarpan tanım gereği $\delta_{(nohl+1)_u}$'dır. Üçüncü çarpan $\partial S / \partial y$ ise, tıpkı $\partial S / \partial w$'nin girişi vermesi gibi, bu kez ağırlığı verir: $w_{(nohl+1)_{1\_u}}$. Sonuç (ekrandan, 01:35:00):

$$\left( \sum_{\alpha=1}^{t} \delta_{(nohl+1)_\alpha} \, w_{(nohl+1)_{1\_\alpha}} \right) \cdot \frac{\partial y_{(nohl)_1}}{\partial S_{(nohl)_1}} \cdot \frac{\partial S_{(nohl)_1}}{\partial w_{(nohl)_{1\_1}}} = \frac{\partial E_{total}}{\partial w_{(nohl)_{1\_1}}}$$

Geriye yayılma bu toplamda olur: sonraki katmandan gelen $\delta$'lar ağırlıklarla çarpılıp toplanır, sonra zincir kuralının ikinci ve üçüncü çarpanlarıyla çarpılır.

### 8.3 Genel güncelleme kuralı

Delta kuralı bu ağırlık için şöyle yazılır (ekrandan, 01:35:00):

$$\hat{w}_{(nohl)_{1\_1}} = w_{(nohl)_{1\_1}} - \eta \left[ \left( \sum_{\alpha=1}^{t} \delta_{(nohl+1)_\alpha} \, w_{(nohl+1)_{1\_\alpha}} \right) \cdot \frac{\partial y_{(nohl)_1}}{\partial S_{(nohl)_1}} \cdot \frac{\partial S_{(nohl)_1}}{\partial w_{(nohl)_{1\_1}}} \right]$$

Çarpanların açık hali yazılınca herhangi bir katmandaki ($\varsigma$) herhangi bir $i$-$j$ ağırlığı için genel kural elde edilir (ekrandan, 01:35:00):

$$\hat{w}_{(\varsigma)_{i\_j}} = w_{(\varsigma)_{i\_j}} - \eta \left[ \left( \sum_{\alpha=1}^{\varrho} \delta_{(\varsigma+1)_\alpha} \, w_{(\varsigma+1)_{j\_\alpha}} \right) \cdot f'\!\left(S_{(\varsigma)_j}\right) \cdot y_{(\varsigma-1)_i} \right]$$

Burada $f'$ aktivasyonun türevi, $y_{(\varsigma-1)_i}$ önceki katmanın çıktısıdır; $\varsigma$ ya da $\varsigma+1$ yazımı önceki ve sonraki katman arasındaki ilişkiyi göstermek içindir. Bu formül ağın herhangi bir noktasındaki ağırlığı güncellemek için kullanılabilir.

> **Hocanın vurgusu:** Çıkıştaki ağırlığın formülü ile içerideki ağırlığın formülü farklıdır. Çıkışta henüz geriye yayılan bir şey yoktur, içeride ise sonraki katmanlardan gelen $\delta$'lar vardır.

## 9. Öğrenme Oranı

Minimum hata için bulunan türev $\eta$ ile çarpılır. Öğrenme oranının seçimi önemlidir; sabit almak, çok büyük almak ya da çok küçük almak sorun çıkarır.

**Soru:** Öğrenme oranı çok büyük seçilirse ne olur? **Cevap:** Büyük atlamalar yapıldığı için minimum noktası kaçırılabilir; küresel minimum atlanabilir.

Sabit bir değer alınırsa, değerin büyüklüğüne göre eğitim çok uzun sürebilir. En iyisi uyarlamalı (adaptive) öğrenme oranıdır: hata azalıyorsa ve azalma yavaşlamaya başladıysa, yani minimuma yaklaşılıyorsa adımlar küçültülmelidir. Adam gibi optimizasyon yöntemleri bu yaklaşımın örnekleridir ve python çerçevelerinde hazır bulunur. "Learning rate optimization" diye aranırsa çok kullanılan üç yöntem bulunur.

Öğrenme oranı elle de denenebilir: 1'den ya da 0,1'den başlayıp onar onar küçültmek gibi; ya da üstel değiştiren bir kod parçası yazılabilir. Slaytta sabit öğrenme oranlarının doğruluğa etkisini gösteren bir grafik, ayrıca çok küçük, uygun ve çok büyük adımları karşılaştıran bir şekil vardır: küçük adım çok uzun sürer, büyük adım minimumu kaçırır, uygun ve değişken boyutlu adımlar hem hız hem doğruluk açısından doğru çözümü verir.

Öğrenme oranına nasıl karar verileceği sorusunun cevabı kayıptır (loss). Gradyan düşümü kayba bağlı olduğundan, öğrenme oranı değişirken kaybın nasıl değiştiği izlenir. Slayttaki grafik kaybı öğrenme oranına karşı gösterir (ekrandan, 01:40:00):

- Yaklaşık $10^{-4}$ civarında öğrenme oranı çok düşüktür, kayıp iyileşmez.
- Yaklaşık $4 \times 10^{-4}$ ile $1{,}5 \times 10^{-3}$ arası en uygun öğrenme oranı aralığı olarak işaretlenmiştir; kayıp hızla düşer.
- $10^{-2}$'nin üzerinde (yaklaşık $2 \times 10^{-2}$'den sonra) öğrenme oranı çok yüksektir ve kayıp ıraksamaya başlar.

<!-- BELİRSİZ: aralık sınırları grafikteki kesikli çizgilerden yaklaşık okunmuştur. -->

> **Hocanın vurgusu:** Ağı kendiniz kodlarsanız öğrenme oranı için izlemeniz gereken büyüklük, öğrenme oranının değişimine bağlı kayıptır.

## 10. Uygulama Notları: Ağırlık Başlatma ve Giriş Ölçekleme

### 10.1 Xavier başlatma

İleri geçişe başlarken ağırlıkların bir başlangıç değeri olmalıdır. Hepsini sıfır ya da bir almak bazen, çok uzun epoch'lar koşulsa bile problemi çözmez. Ya Gauss dağılımından örnek çekilir ya da katman boyutlarına bağlı bir aralık belirlenip bu aralıktan rastgele örneklenir. Kanada'dan (büyük olasılıkla Montreal) iki araştırmacının yaklaşımı Xavier başlatma diye bilinir ve bazı çerçevelerde bu adla çağrılabilir. Slayttaki aralık (ekrandan, 01:45:00):

$$w^{initial}_{(\varsigma)_{i\_j}} = \left[ -4\sqrt{\frac{6}{size(\varsigma) + size(\varsigma+1)}}\ ,\ 4\sqrt{\frac{6}{size(\varsigma) + size(\varsigma+1)}} \right]$$

Bu aralıktan seçilen ağırlıklar, yüz binlerce epoch'a gerek kalmadan doğru sonuca ulaşmayı kolaylaştırır. Problemin türüne göre başlangıç ağırlıkları önemlidir: anlatıcının iki doğrusal ayrılabilen kümeyle yaptığı bir denemede, değerler büyük seçilince ağırlıkları sıfırla başlatmak çok sayıda epoch'ta bile doğru sonuç vermemiştir. Python çerçevelerindeki Xavier, Adam gibi parametre adlarının ne anlama geldiğini bilmek gerekir.

**Soru:** Daha önce sıfırdan yazılan bir algılayıcı uygulamasında ağırlıklar nasıl başlatılmıştı? **Cevap:** Bir öğrenci, kitaptaki örneği temel aldıkları için sıfırla başlattığını söyler.

> **Ek bilgi (derste anlatılmadı):** Glorot ve Bengio'nun önerdiği aralık büyük olasılıkla $\pm\sqrt{6/(n_{in}+n_{out})}$'tir ve tanh için kullanılır. Slayttaki 4 katsayısı genelde sigmoid aktivasyonu için önerilen biçimdir.

### 10.2 Doyum ve giriş ölçekleme

Görüntüden hiç özellik çıkarmadan değerler doğrudan verildiğinde, ağırlıklar sıfırsa sorun yoktur ama rastgele başlatıldığında sorun çıkar. Örneğin girişler 25, 38, 42 gibi artılı eksili büyük değerlerse ve ağırlıklar 0-1 arasında olsa bile, 10.000 nöronlu bir katmandan gelen çarpımların toplamı çok büyük olur.

**Soru:** Bu durumda tanh ya da sigmoid kullanılırsa (ReLU değil) nasıl bir sorun çıkar? **Cevap:** Bir öğrenci hesaplama taşmasını önerir; anlatıcı doğru yönde olduğunu söyler ve doyumu açıklar.

Sigmoid en fazla 1, en az 0 verir. Toplam belli bir değerden sonra hep büyük olduğu için çıkış hep 1 (negatif tarafta hep 0) olur; nöron sürekli doyuma (saturation) girer. Ağırlık başlatma genelde $[-1, 1]$ aralığına düşen küsuratlı değerler verdiği için bu sorunu azaltır.

Giriş de aynı mantıkla ölçeklenmelidir. Giriş bir görüntünün pikselleriyse pikselleri doğrudan vermek doyuma götürebilir. Bu yüzden min-max normalizasyonu ile değerler 0-1 aralığına eşlenir. 8 bitlik gri görüntüde bütün pikseller 255'e bölünür; minimum zaten 0 olduğundan bu, en büyük değere bölmektir. Minimum 0 değilse slayttaki formül kullanılır (ekrandan, 01:45:00). Slaytta $X$ matrisinin elemanlarının negatif olmayan rasyonel sayılar olduğu ($x_{\vartheta\_\Upsilon} \in \mathbb{Q}_0^{+}$) belirtilir.

> **Ders sonrası not:** Slaytta formül $\bar{x}_{\vartheta\_\Upsilon} = \dfrac{x_{\vartheta\_\Upsilon} + \min(X)}{\max(X) - \min(X)}$ biçiminde yazılmıştır (ekrandan, 01:45:00). Doğrusu $\bar{x}_{\vartheta\_\Upsilon} = \dfrac{x_{\vartheta\_\Upsilon} - \min(X)}{\max(X) - \min(X)}$'tir. Örneğin $X = \{50, 100, 150\}$ için doğru formül $0;\ 0{,}5;\ 1$ verir, slayttaki biçim ise $1;\ 1{,}5;\ 2$ verir ve değerler $[0,1]$ dışına çıkar (python ile kontrol edildi).

Üçüncü uygulama notu batch'tir: batch kullanılmazsa eğitim çok uzun sürer ve genelleme desteklenmez. Slayt bu üç notu (I. ağırlık başlatma, II. giriş ölçekleme, III. eğitim algoritması) bir arada gösterir (ekrandan, 01:45:00).

## 11. MNIST Üzerinde Çok Katmanlı Algılayıcı

### 11.1 Veri kümesi

Derse yeni başlayanların bu örneğin kodunu yazması ya da hazır kodu anlaması önerilir. En bilinen örnek MNIST'tir: 1990'ların sonunda Yann LeCun'un çalıştığı el yazısı rakam veri kümesi. Farklı kişilerin 0'dan 9'a yazdığı rakamlardan oluşur ve 10 etiketi vardır. Her görüntü $28 \times 28 = 784$ adet 8 bitlik gri pikseldir (ekrandan, 01:50:00). Slaytta bir "3" görüntüsünün pikselleri satır satır açılarak 784 elemanlı giriş vektörü ($x$) haline getirilir. Veri kümesinde 60.000 eğitim ve 10.000 test örneği vardır; python'da tek satırla indirilebilir.

CNN ve daha ileri ağlarda önde özellikleri çıkaran evrişim katmanları vardır ve resmin kendisi verilir. Burada öyle bir şey yapılmaz; amaç geri yayılımı anlamak olduğu için uygulama MLP üzerine kurulur.

### 11.2 Ağın boyutları

Kodu yazarken önce kaç gizli katman ve her katmanda kaç nöron olacağı belirlenir. Ağırlıklar başlatılırken o katmanın önündeki ve arkasındaki katman boyutları dikkate alınır.

**Soru:** Çıkış katmanında kaç nöron vardır? **Cevap:** Bu bir sınıflama problemidir ve 10 sınıf vardır; çıkışta 10 nöron bulunur. Birinci nöron 0'ı, ikincisi 1'i, sonuncusu 9'u temsil eder.

Çıkışta sayısal değerler elde edilir ve hangi nöron baskınsa (örneğin değeri en büyükse) bir kontrol mekanizmasıyla o nöronun rakamı seçilir. Bir de regresyon problemi vardır; orada bir fonksiyona benzetme yapılır ve sınıflamadan biraz daha zordur.

**Soru:** Giriş katmanının boyutu nedir? **Cevap:** $28 \times 28$, yani görüntünün piksel sayısı.

Girişe verilen gri piksel değerleri, doyum olmaması için min-max ile ölçeklenir; çıkışta sigmoid kullanılıyorsa aralık 0-1'dir. Literatürde iki gizli katmanlı (1024-1024) bir ağ yaklaşık %97 sonuç verir.

### 11.3 Hedef matrisi ve one-hot kodlama

**Soru:** Çıkıştaki değerler neyle karşılaştırılacak, rakamların sayısal değerleriyle mi? **Cevap:** Bir öğrencinin önerdiği gibi bir hedef matrisi oluşturulur. İçeriği, çıkış aktivasyonunun aralığına göre doldurulur.

Çıkışta sigmoid kullanılırsa en büyük değer 1, en küçük değer 0'dır. Bu sınır değerleriyle one-hot kodlama yapılır. Eğitimde verilen görüntü "3" ise, 0, 1, 2, 3 sırasındaki dördüncü nöronun en büyük değeri, diğerlerinin en küçük değeri vermesi beklenir. Slayttaki one-hot etiket şöyledir (ekrandan, 01:55:00):

$$[0,\ 0,\ 0,\ 1,\ 0,\ 0,\ 0,\ 0,\ 0,\ 0]$$

Gerçek çıktılar bu vektörle matematiksel olarak karşılaştırılabilir. Slaytta bir ileri geçişten sonra çıkış nöronlarının değerleri örnek olarak verilmiştir (ekrandan, 02:00:00):

$$[0{,}1;\ 0{,}1;\ 0{,}3;\ 0{,}9;\ 0{,}4;\ 0{,}2;\ 0{,}1;\ 0{,}1;\ 0{,}6;\ 0{,}3]$$

Her çıkış için MSE çalıştırılır ve $t = 10$ hata ($E_1$'den $E_{10}$'a) bulunur. Ardından geri yayılım başlar: genelleştirilmiş formülle, $\delta$'ların taşıdığı bilgi de kullanılarak sağdan sola girişe kadar bütün ağırlıklar bu görüntü için güncellenir. Bu, her görüntüde güncelleme yapılan stokastik gradyan düşümüdür. Batch kullanılıyorsa hatalar saklanır, sonraki görüntüye geçilir, örneğin batch boyutu 5 ise beş görüntünün ortalama hatası üzerinden geri yayılım ve güncelleme yapılır. Bütün veri kümesi tarandığında bir epoch biter.

Örneğin veri kümesi 50 örnekse ve batch boyutu 5 ise, bir epoch'ta $50 / 5 = 10$ güncelleme yapılır. Eğitim genelde epoch sayısıyla anlatılır: 200 epoch sonunda veri kümesi mini-batch'lerle 200 kez taranmış ve ağırlıklar son haline gelmiş olur; sonra eğitimde hiç görülmemiş test kümesiyle test yapılır.

Slaytta bu örneğin çalıştırılabilir bir sürümüne bağlantı verilmiştir (CNTK MNIST çok katmanlı algılayıcı öğreticisi). Keras'ta iki gizli katmanlı ağ iki satırda kurulabilir, ama arkada geri yayılımın nasıl çalıştığına dair bir bilgi görünmez. Derin öğrenmenin bir sıkıntısı da budur: herkes üst seviyeden baktığı için bazı ayrıntılar kaçabilir. Bu yüzden bu derste anlatılan bilgiler anlamak açısından önemlidir.

### 11.4 Diğer küçük veri kümeleri

MNIST dışında Fashion-MNIST (kıyafet görüntüleri, MNIST'ten daha zor) ve CIFAR (renkli, küçük boyutlu; hayvan, araç gibi nesneler) gibi veri kümeleri de vardır. Küçük boyutlu veri kümeleri, özellikle sinir ağı donanımı üzerinde çalışanlar için uygundur; büyük ağlar ve büyük veri kümeleri için donanım tasarımı çok zordur. Son olarak, bazı ağ yapılarını katmanlarıyla renklendirerek gösteren bir harita ve giriş bölümleri okunmaya değer birkaç yayın önerilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:20): AND, OR ve XOR fonksiyonlarından ilk ikisini üçüncüsünden ayıran özellik nedir? Bunun ağ tasarımına etkisi nedir?

> **Çözüm:** AND ve OR doğrusal olarak ayrılabilir, XOR ayrılamaz. Tek nöron doğrusal bir sınıflayıcı olduğu için XOR tek nöronla (tek katmanla) çözülemez; gizli katman gerekir.

**Soru 2** (derste sözlü, 00:26:36): Bir nöronun girişlerinin ağırlıklarla çarpılıp toplanmasıyla elde edilen değere ne denir?

> **Çözüm:** Preaktivasyon, $S = \sum x_i w_i + b$. Henüz aktivasyondan geçmemiştir; nöronun çıktısı $y = f(S)$'dir.

**Soru 3** (derste sözlü, 00:45:17): Girişten çıkışa, hatalar belirlenene kadar geçen adımlara ve çıkıştan girişe doğru geri dönülen adıma ne ad verilir? Hatayı en aza indirmek için hangi işlem kullanılır?

> **Çözüm:** İleri geçiş (feed forward) ve geri geçiş (backward pass). Hatanın ağırlıklara göre kısmi türevleri alınır ve gradyan düşümü ile ağırlıklar güncellenir.

**Soru 4** (derste sözlü, 00:52:21): 100 eğitim görüntüsü tek tek ağa verilip her birinden sonra ağırlıklar güncellenirse, bütün görüntüler bittiğinde ne tamamlanmış olur? 25'erli gruplar kullanılırsa ne değişir?

> **Çözüm:** Bir epoch tamamlanır (100 güncelleme). 25'erli 4 grup kullanılırsa her grubun ortalama hatasıyla bir geri geçiş ve güncelleme yapılır; bir epoch'ta 4 güncelleme olur.

**Soru 5** (derste sözlü, 01:10:41): $E$ ağırlıklar cinsinden doğrudan yazılamıyorsa $\partial E / \partial w$ nasıl bulunur?

> **Çözüm:** Zincir kuralı ile: $\dfrac{\partial E}{\partial w} = \dfrac{\partial E}{\partial y} \cdot \dfrac{\partial y}{\partial S} \cdot \dfrac{\partial S}{\partial w}$. tanh için $\partial y / \partial S = 1 - \tanh^2(S)$, $\partial S / \partial w$ ise ağırlığın bağladığı önceki nöronun çıktısıdır.

**Soru 6** (derste sözlü, 01:37:24): Öğrenme oranı çok büyük seçilirse ne olur?

> **Çözüm:** Büyük adımlar yüzünden minimum atlanabilir; kayıp salınır ve ıraksayabilir. Çok küçük oran ise eğitimi çok uzatır. Uyarlamalı öğrenme oranı tercih edilir.

**Soru 7** (derste sözlü, 01:46:20): Girişler büyük değerliyse ve ağırlıklar rastgele başlatılmışsa, sigmoid ya da tanh kullanan bir ağda nasıl bir sorun çıkar?

> **Çözüm:** Preaktivasyon çok büyür ve aktivasyon doyuma girer: sigmoid hep 1 ya da hep 0 verir. Çözüm, ağırlıkları Xavier gibi katman boyutuna bağlı bir aralıktan başlatmak ve girişleri min-max ile $[0,1]$ aralığına ölçeklemektir.

**Soru 8** (derste sözlü, 01:51:37 ve 01:53:41): MNIST'i MLP ile sınıflarken giriş ve çıkış katmanlarının boyutu ne olur?

> **Çözüm:** Giriş $28 \times 28 = 784$ nöron, çıkış 10 nöron (her rakam için bir nöron).

**Soru 9** (ekrandan, 02:00:00): MNIST'te "3" etiketli bir görüntü için one-hot hedef $[0, 0, 0, 1, 0, 0, 0, 0, 0, 0]$, çıkış nöronlarının değerleri $[0{,}1;\ 0{,}1;\ 0{,}3;\ 0{,}9;\ 0{,}4;\ 0{,}2;\ 0{,}1;\ 0{,}1;\ 0{,}6;\ 0{,}3]$'tür. Her nöron için $E_u = \tfrac{1}{2}(t_u - y_u)^2$ alınırsa hatalar ve $E_{total}$ nedir? Ağ hangi rakamı tahmin eder?

> **Çözüm (derste verilmedi):** $E_u$ değerleri sırasıyla $0{,}005;\ 0{,}005;\ 0{,}045;\ 0{,}005;\ 0{,}08;\ 0{,}02;\ 0{,}005;\ 0{,}005;\ 0{,}18;\ 0{,}045$'tir. Örneğin dördüncü nöron için $\tfrac{1}{2}(1 - 0{,}9)^2 = 0{,}005$, dokuzuncu nöron için $\tfrac{1}{2}(0 - 0{,}6)^2 = 0{,}18$. Toplam $E_{total} = 0{,}395$. En büyük çıktı dördüncü nöronda (0,9) olduğu için ağ "3" tahmin eder. En büyük hata katkısı 0,6 veren dokuzuncu nörondan ("8") gelir. (Python ile hesaplandı.)

**Soru 10** (derste sözlü, 01:59:21): Veri kümesi 50 örnekten oluşuyor ve batch boyutu 5 ise bir epoch'ta kaç ağırlık güncellemesi yapılır?

> **Çözüm:** $50 / 5 = 10$ güncelleme.

## Dersin Toparlaması

Bu derste geri yayılım, tek nörondan başlanarak yeniden kuruldu. Önce doğrusal ayrılabilirlik ve tek nöronun bir doğru denklemine karşılık gelmesi gösterildi. Ardından çok katmanlı tam bağlı ağın matris yapısı, ileri geçiş, geri geçiş ve güncelleme adımları, epoch ve batch kavramları ele alındı. Ana bölümde zincir kuralıyla önce çıkış ağırlığının türevi çıkarıldı, $\delta$ terimi tanımlandı ve bu tanım sayesinde sonraki katmandan gelen $\delta$'ların ağırlıklı toplamıyla her katmandaki ağırlık için geçerli genel güncelleme kuralına ulaşıldı.

Son bölümde uygulamada önemli olan noktalar toplandı: öğrenme oranının kayba bakılarak seçilmesi ve uyarlamalı yapılması, Xavier başlatma, girişlerin min-max ile ölçeklenerek doyumun önlenmesi ve batch kullanımı. MNIST örneğinde 784 girişli, 10 çıkışlı bir MLP'nin one-hot hedeflerle nasıl eğitileceği anlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
