# Ders 10 Genişletilmiş Notu: Yapay Sinir Ağlarıyla Kolektif Öğrenme, Snapshot Ensemble ve Ağırlık Ortalaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. YSA'ların iç dinamikleri
- 2. Temel öğreniciler olarak YSA'lar
- 3. Veri artırımı (data augmentation)
- 4. Tank sınıflandırma örneği ve açıklanabilirlik
- 5. 2012: ImageNet yarışması ve ensemble
- 6. Kararlar mı, parametreler mi?
- 7. Snapshot Ensembles
- 8. Parametre uzayında iki nokta arasındaki doğru
- 9. Bağımsız eğitimlerle erişilen lokal minimumlar bağlıdır
- 10. Kararları değil, ağırlıkları birleştirmek (SWA)
- 11. Hocanın denemeleri: Digits veri kümesi
- 12. Validasyon kümesinin rolü
- Örnek Sorular

## 1. YSA'ların iç dinamikleri

Ders, yapay sinir ağları (YSA) ile kolektif öğrenme konusuna giriş olarak planlandı. Hoca konuyu "YSA_kolektif" adlı yeni bir slayt dosyasıyla anlattı. Amaç, o haftanın ödevi için gereken kısma kadar ilerlemekti.

### 1.1 Gerçek ve yapay nöronlar

Hoca önce gerçek bir sinir dokusunun görüntüsünü gösterdi. Kalın, beyaz görünen kısımlar hücre çekirdekleridir; onlardan çıkan ve onlara giren kollar vardır. Bir sinir hücresinin yaptığı iş, çevresinden sinyalleri toplayıp başka hücrelere iletmektir. Her nöronun birden fazla girişi ve bir çıkışı vardır; bir nöron birden fazla hücreden bilgi alır ve birden fazla hücreye bilgi iletir.

### 1.2 Eğitim bir yörüngedir

YSA bağlamında eğitim kümesi üzerinde eğitim yapmak, yapay nöronlar arasındaki ağırlıkları güncellemek demektir. Rastgele bir $w_0$ ağırlığından başlanır. $w_0$'dan $w_1$ üretilir, sonra $w_2$, ve süreç $w_T$'ye kadar ilerler (ekrandan, 00:10:00). Güncelleme önceki derslerde görülen gradient descent, Adam vb. bir optimizasyon yöntemiyle yapılır. Hangi yöne ve ne kadar gidileceğini eğitim kümesindeki tahminlerle gerçek değerler arasındaki fark belirler; ağırlıklar bu farkı en aza indirecek biçimde güncellenir.

Bu güncellemeyi geri yayılım (backpropagation) algoritması yapar. Önce ağ ileri yönde çalıştırılır ve bir loss hesaplanır. Sonra loss'u azaltacak biçimde son katman güncellenir, ardından bir önceki katman, sonra onun öncesi; bu en baştaki katmana kadar sürer. Nöronlar katmanlar hâlinde dizilir ve hata çıkış katmanından geriye doğru yayılır; adı da buradan gelir.

### 1.3 Tek bir YSA bile kolektif öğrenmedir

Slaytta üç madde vardı (ekrandan, 00:10:00): sanal nöronların her biri bir temel öğrenicidir; nöronlar geriye yayılan, yani diğerlerinden gelen sinyallerle öğrenir; tek bir YSA bile kolektif öğrenme içerir. Kolektif öğrenme, bir öğrenme sürecine birden fazla modelin katılması diye tanımlanmıştı. Her nöron bir model olarak düşünülürse yüzlerce, binlerce nöron birlikte öğrenir; tek başına öğrenen bir nöron yoktur.

Bunun ötesinde farklı YSA'ların kararlarını birleştirerek de kolektif öğrenme yapılabilir; yani YSA'lar temel öğrenici olarak kullanılabilir. Geçmiş haftalarda temel öğrenici olarak karar ağaçları kullanılmış ve kararları birleştirilmişti.

## 2. Temel öğreniciler olarak YSA'lar

Karar ağaçları deterministik algoritmalardır: aynı eğitim kümesiyle her seferinde aynı sonucu verirler, içlerinde rastgelelik yoktur. Bu yüzden farklı kararlar üretmeleri için önceki derslerde birçok yaklaşım görülmüştü; hepsi sürece bir rastgelelik katıyordu.

Slayttaki ana fikir şudur: YSA'ların farklı karar üretmeleri için çok uğraşmaya gerek yoktur (ekrandan, 00:15:00). Slayttaki alt maddeler:

- Karar ağaçları gibi deterministik değiller.
- Farklı başlangıç değerleri.
- Farklı örnek / mini-batch sıralamaları.
- Farklı hiperparametreler.

**Başlangıç değerleri.** $w_0$'ın seçimi bile rastgeledir; hata-parametre uzayının neresinden başlanacağı rastgele belirlenir. Bu yüzden süreç önceden tam tahmin edilemez: başka bir $w_0$'dan başlayan eğitim, aynı eğitim kümesiyle bile başka bir $w_T$'ye varabilir. Aynı eğitim kümesiyle bile farklılık oluşabildiği için farklı kararlar üretmek amacıyla ek bir mekanizmaya gerek yoktur.

**Örnek sıraları.** Optimizasyon kısmından stokastik gradient descent (SGD) hatırlatıldı. Büyük veri kümelerinde her güncellemede bütün örnekleri kullanmak (batch gradient descent) çok zaman ve bellek ister. Bunun yerine her güncellemede tekil örnekler ya da rastgele örnek grupları (mini-batch) kullanılır. SGD özellikle başlangıç adımlarında hızlıdır; küçük zigzaglar çizse de iyi çalışır. Örnekler farklı sıralarla verildiğinde süreç değişir. Aynı yerden başlayıp farklı örnek sıralarıyla eğitilen ağlar da farklı sonuçlar verebilir.

**Hiperparametreler ve mimari.** Öğrenme katsayısı ve diğer hiperparametreler, katman sayısı (3 yerine 4 katman) ya da katmanlardaki nöron sayısı değişince süreç tamamen değişir. YSA'lar hem hiperparametre bakımından zengindir hem de kendi içlerinde rastgelelik taşıdıkları için her zaman farklı kararlar üretebilir.

## 3. Veri artırımı (data augmentation)

Slayttaki tanım: eldeki verilerle güvenilir dönüşümler yaparak farklı veriler elde etmek (ekrandan, 00:30:00). Resimler için döndürmek, renklerle oynamak, resim parçalarıyla eğitim; metinler için eş anlamlı kelime/ifade dönüşümleri ve back translation sayıldı.

### 3.1 Neden yapılır, maliyeti nedir?

Hoca, döndürmenin ne fayda sağladığını ve bunun nasıl maliyetsiz yapılabileceğini sordu. Buradaki maliyet hesaplama maliyeti değil, etiketleme maliyetidir. Örnek olarak yıldız resimlerinden yıldızın türünü tahmin eden bir model düşünüldü: A, B, C sınıflarından birçok yıldız resmi vardır. Orijinal resimler döndürülerek yeni resimler elde edilir. Döndürmek yıldızın sınıfını değiştirmez; döndürülmüş resmin etiketi orijinalininkiyle aynıdır, bu yüzden yeni etiketleme için insana gerek yoktur.

### 3.2 Dönüşümün sınırı veri kümesine bağlıdır

Yıldız resmi 0 ile 180 derece arasında istenen açıyla döndürülebilir. Rakam ya da harf resimlerinde ise döndürme sağlıklı olmayabilir. 8 rakamı ile sonsuz işaretinin ayırt edilmesi gerektiğini düşünün: 8'leri döndürüp sonsuz işaretine benzeyen resimler üretir ve bunları 8 diye etiketlerseniz modele yanlış bilgi vermiş olursunuz. Veri artırımı ek etiketleme gerektirmeden veri üretir, ama sınırlarını veri kümesine göre belirlemek gerekir.

Diğer dönüşümler: renklerle oynamak, resmin siyah-beyaz hâlini kullanmak, resmin tamamı yerine içinden kırpılmış (crop) yaklaşık %80'lik parçalar kullanmak. Kırpılmış parçalar şu durumda işe yarar: nesnelerin genelde ortada durduğu bir veri kümesinde arka plandan (background) bağımsız bir model istenebilir, çünkü test verisinde arka plan farklı olabilir. Küçük parçalarla eğitmek arka plana karşı bir yanlılık (bias) oluşmasını engeller.

### 3.3 Metinler için dönüşüm

Eş anlamlı kelime ve ifadeler değiştirilebilir: "Hava bugün çok güzel" cümlesinden, "çok güzel" ile "harika"nın eş anlamlı olduğu biliniyorsa, "Hava bugün harika" üretilir.

Geri çeviri (back translation): A dilindeki bir cümle otomatik çeviriyle B diline, sonra B dilinden yeniden A diline çevrilir. Sonuçta $A$'dan $\bar{A}$ elde edilir. Çeviri sistemi kusursuz çalışırsa $\bar{A}$ ile $A$ aynı olur ve işe yaramaz. Aynı anlamı farklı biçimde ifade eden bir $\bar{A}$ çıkarsa yeni bir eğitim örneği elde edilmiş olur. Anlam çok bozulursa bu da kötüdür.

### 3.4 Veri artırımı ve ensemble

Her model farklı verilerle eğitilebilir: renkleriyle oynanmış bir küme, döndürülmüş bir küme vb. farklı mimarilerle eğitilip kararları birleştirilebilir. Ya da aynı model her epoch'ta farklı verilerle eğitilebilir: birinci epoch'ta orijinal veriler, ikincide biraz döndürülmüş, üçüncüde renkleriyle oynanmış, dördüncüde kırpılmış veriler.

## 4. Tank sınıflandırma örneği ve açıklanabilirlik

### 4.1 Hikâye

Hoca arka plan konusunu bir hikâyeyle açtı. Soğuk Savaş döneminde (hoca ülkeyi tam hatırlamadığını söyledi) otonom bir tankın görüntüden çevresindeki tankların dost mu düşman mı olduğunu ayırması istenir. Dost ve düşman tank resimleri toplanıp işaretlenir, eğitim ve test kümesine ayrılır ve bir YSA eğitilir. Test kümesinde %100'e yakın, örneğin %99 başarı elde edilir. Sistem tankın bilgisayarına yüklenip gerçek (ama yine kurgusal) bir ortamda denendiğinde başarı %50 civarına düşer: dostlara düşman, düşmanlara dost der.

Hoca sorunun ne olabileceğini sordu. Öğrencilerden titreşim, tankların yeşil olup çimenden ayırt edilememesi, düşman resimlerinin karanlık olması gibi tahminler geldi. Cevap: dost tankların resimleri çekilirken hava güneşliymiş, düşman tankların resimleri çekilirken bulutluymuş. Eğitim ve test kümesi aynı resimlerden rastgele ayrıldığı için ikisinde de bu yanlılık vardı. Sistemin öğrendiği şey yalnızca havada güneş olup olmadığıydı.

### 4.2 Neden YSA?

Hoca, hikâyede neden özellikle YSA dediğini sordu: bir karar ağacı olsaydı bu hata daha çabuk fark edilirdi. Bir öğrenci YSA kararlarının insan için açıklanmasının zor olduğunu, ağaçların ise kurallarla karar verdiğini söyledi. Hoca bunu örnekle açtı: bir karar ağacında "resmin üst tarafındaki piksellerin aydınlık (luminance) değeri şu değerden büyükse dost" gibi düğümler görülürdü. Bu piksellerin tankla değil resmin üst kısmıyla ilgili olduğu fark edilirdi. YSA'da ise girişler ağırlıklarla çarpılır, doğrusal olmayan bir fonksiyondan geçirilir, birinci katmanın çıkışları yine ağırlıklandırılarak ikinci katmana verilir; neye göre karar verildiğini anlamak daha güçtür. İmkânsız değildir, ama yanlış bir şey öğrenildiğini fark etmek ağaçta daha kolaydır.

> **Hocanın vurgusu:** Makine öğrenmesi algoritmalarının çoğu için şu söylenebilir: makinelere ne yapmaları gerektiğini söyleyebilirsiniz, ama nasıl yapmaları gerektiğini söyleyemezsiniz.

Modellerin verdikleri kararları bize açıklaması açıklanabilir yapay zekâ (explainable AI) konusudur. Model alakasız şeylere göre karar veriyorsa düzeltilmesi gerekir. Arka planı öğrenmek, yani asıl amacı değil bir yan yolu öğrenmek gerçek bir sorun olabilir.

**Soru:** CNN kullansalardı ara katmanlardaki filtreler görülebildiği için bunu fark ederlerdi, değil mi? Örneğin yüz tanıyan bir CNN'in göze, burna, çeneye odaklandığı görülebiliyor. **Cevap:** Resmin üzerinde gezdirilen CNN çekirdekleri (kernel) yorumlanmaya daha açıktır; yoğun (dense) bir ağa göre CNN'in ne yaptığını anlamak biraz daha kolay olabilir. Yine de bu yanlılığın doğrudan görülüp görülmeyeceği belli değildir, uğraşmak gerekir. Açıklanabilir yapay zekânın giderek artan bir eğilim olmasının sebebi budur: YSA'ların neye göre karar verdiğini açıklayan araçlar geliştiriliyor. Anlaşılabilirlik mimariden mimariye değişir, ama karar ağaçları kadar net olmayabilir.

## 5. 2012: ImageNet yarışması ve ensemble

2012 yılı derin öğrenme için önemli bir yıldır. Slayttaki başlık: derin öğrenmenin sıçrayışı (veri artırımı ve birçok modelin kararlarının birleştirilmesini içeriyor) (ekrandan, 00:35:00). Kaynak, ILSVRC-2012 sonuçlarını veren NIPS makalesidir.

### 5.1 Top-1 ve Top-5

**Soru:** Top-1 ve Top-5 ne demek? **Cevap (bir öğrenci):** Top-1'de en iyi tahmin, Top-5'te en iyi 5 tahmin alınır. Hoca açtı: ImageNet yarışmasında yaklaşık 1000 sınıf vardır. Model, örneğin "bu büyük olasılıkla 942. sınıftır" der. En olası tahmini doğruysa bu Top-1 doğruluğuna yazılır.

Hoca yalnız Top-1 kullanmanın adil olmadığını söyledi. Bir model birinci tahmini yanlış, ikincisini doğru bilebilir: örneğin %65 olasılıkla A, %30 olasılıkla B (doğru sınıf) der, kalan olasılıklar diğer sınıflara %1-2 dağılır. Top-1'e göre bu model hiçbir şey bilmeyen, bütün sınıflara eşit olasılık veren bir modelle aynı görünür; oysa ondan daha başarılıdır. Top-5'te sistemin en iyi 5 tahmini alınır; herhangi biri doğruysa örnek doğru sayılır. Top-5 kümesi Top-1'i de içerdiği için Top-5 doğruluğu her zaman Top-1 doğruluğundan yüksek ya da ona eşittir.

### 5.2 Tablo

Tablo hata oranlarını verir (küçük olan iyidir; 100'den çıkarılırsa başarı bulunur) (ekrandan, 00:35:00):

| Model | Top-1 (val) | Top-5 (val) | Top-5 (test) |
|---|---|---|---|
| SIFT + FVs | — | — | 26.2% |
| 1 CNN | 40.7% | 18.2% | — |
| 5 CNNs | 38.1% | 16.4% | 16.4% |
| 1 CNN* | 39.0% | 16.6% | — |
| 7 CNNs* | 36.7% | 15.4% | 15.3% |

Yıldızlı modeller bütün ImageNet 2011 Fall sürümü üzerinde önceden eğitilmiştir (tablo açıklamasından). İlk satır o yıl ikinci olan sistemdir; slaytta "Bu da bir ensemble" notu vardır. Alttaki dört satır CNN sonuçlarıdır.

Önceki yıllarda ilk üç sistem arasında %1-2'lik farklar bile nadirken 2012'de fark büyüktür: Top-5 test hatasında $26.2 - 15.3 = 10.9$ puan, yani yaklaşık %10'luk bir fark. 1 CNN'den 5 CNN'e geçince Top-5 doğrulama hatası $18.2 - 16.4 = 1.8$ puan azalır. "5 CNNs" ve "7 CNNs" satırları beş ve yedi CNN'in kararlarının birleştirilmesiyle elde edilmiştir.

**Soru:** Tablodaki modellerin hepsi mi ensemble? 1 CNN de ensemble mi? **Cevap:** Hayır; bir CNN tek bir modeldir. 5 CNN'in kararlarının birleştirilmesine ensemble denir.

> **Hocanın vurgusu:** Bu slayt kolektif öğrenmenin önemini vurgulamak için: yarışmaları kazananlar ensemble içerir; tek bir YSA yerine birçoğunu kullanmak daha iyi bir yaklaşımdır.

### 5.3 Ensemble'ın dezavantajları

Hoca, konu YSA ve büyük veri olduğunda ensemble'ın dezavantajını sordu. Öğrencilerin cevabı zaman ve hesaplama maliyetiydi. 10 YSA eğitmek 10 kat hesaplama demektir. YSA'lar birbirine bağımlı değildir; aynı veri kümesi (ya da artırılmış hâli) farklı makinelerdeki ağlara verilebilir, makine varsa süre sorun olmaz. Ama harcanan elektrik her hâlükârda 10 katına çıkar. Bir öğrencinin "çok sınıf için çok veri gerekir" önerisine hoca, bütün sistemlerin aynı verilerle eğitildiğini söyledi.

Ek bir dezavantaj saklama ve bellektir. Büyük verilerle eğitilmiş iyi modeller milyonlarca, milyarlarca parametreye sahiptir; birden fazlasını bellekte tutmak ciddi bir iştir. Hem bellek gereksinimi artar hem de hız açısından kayıp olur.

## 6. Kararlar mı, parametreler mi?

### 6.1 Aynı eğitim sürecinin noktaları

Slayt başlığı "Kararlar / Parametreler" idi (ekrandan, 00:45:00). İlk madde: aynı eğitim sürecinin farklı noktalarındaki parametrelerin / kararların birleştirilmesi mantıklı. İkinci madde: farklı eğitim süreçlerinin kararlarının birleştirilmesi mantıklı.

Hoca slayta $w_0\ w_1\ w_2 \dots w_k \dots w_h \dots w_g \dots w_T$ dizisini yazdı. Başlangıçtaki ağın da bir kararı vardır; zaten bir tahmin olmalı ki iyileştirilsin. Ama $w_0$'daki kararlar güvenilir değildir; rastgeleye yakındır (zero rule gibi düşünülebilir). İlerledikçe $w_k$'da belli bir başarıya, daha sonra daha iyi başarılara ulaşılır.

İki seçenek vardır:

- $w_k, w_h, w_g, w_T$ noktalarındaki ağların kararlarını demokrasi usulüyle birleştirmek.
- Bu noktaların parametrelerinin ortalamasını alıp yeni bir nokta, örneğin $w_z$, üretmek ve o tek ağı kullanmak.

### 6.2 Farklı eğitim süreçlerinin noktaları

Hoca slayta şunu da ekledi (ekrandan, 00:50:00): $W_0 \dots w_{a1}$, $W_0 \dots w_{a2}$, $W_0 \dots w_{a3}$. Her biri farklı bir $w_0$'dan başlayan farklı bir eğitim sürecidir. Bunların kararlarını birleştirmenin mantıklı olduğu zaten biliniyordu: ensemble'ın mantığı, herhangi birini seçmek yerine üçünün kararlarının ortalamasını almaktır. Birbirinden farklı şeyler söyleyebiliyorlarsa bir kişi yerine birçok kişinin aklına güvenmek daha iyidir.

**Soru:** $w_{a1}, w_{a2}, w_{a3}$'ün parametre ortalamasını alıp onu bir model olarak kullanmak mantıklı mı? **Cevap (bir öğrenci):** Hayır; her biri farklı bir lokal minimuma iner, karar verme biçimleri farklıdır. Hoca onayladı: farklı başlangıçlar genelde farklı lokal minimumlara götürür. İki lokal minimumun ortası minimum olmayabilir; büyük olasılıkla ikisinden de daha yüksek hatalı bir yerdir. Slayttaki son soru da buydu: lokal minimumlar arası da minimum olur mu?

### 6.3 R bölgesindeki kaos

Aynı eğitim sürecinin noktalarında ise parametre ortalaması mantıklıdır; sebebi slayttaki "R bölgesindeki kaos" maddesidir. SGD'de bir R bölgesi tanımlanmıştı. SGD'de her güncelleme örneklerin yalnız bir kısmıyla yapılır; bazı örnekler bir yöne, bazıları başka bir yöne gitmeyi ister. Hepsinin ortalaması aynı yeri gösterse de bölgenin içinde bir kaos vardır.

Sürecin sonuna yakın $w_k, w_h, w_g, w_T$ noktaları bu bölgenin içinde bir orta noktanın etrafında salınır. Herhangi bir noktanın orta noktaya uzaklığı ile son 10 noktanın ortalamasının orta noktaya uzaklığı karşılaştırılırsa, 10 noktanın ortalaması orta noktaya daha yakın olur. Bu yüzden son noktayı kullanmak yerine son kısımdaki ardışık noktaların ortalamasını almak daha mantıklıdır. Başlardaki noktaları ortalamaya katmak ise anlamlı değildir.

> **Ek bilgi (derste anlatılmadı):** Bu sezgi basit bir benzetimle görülebilir. Merkez çevresinde iki boyutlu standart normal gürültüyle salınan noktalarda tek bir noktanın merkeze ortalama uzaklığı yaklaşık 1.25, 10 bağımsız noktanın ortalamasınınki ise yaklaşık 0.40 çıkar (ajan tarafından python ile benzetildi). Gerçek SGD noktaları birbirinden bağımsız olmadığı için kazanç büyük olasılıkla daha azdır.

> **Hocanın vurgusu:** Farklı eğitim süreçlerinin kararlarını birleştirmek mantıklıdır. Aynı eğitim sürecinin parametrelerini birleştirmek de mantıklıdır, ama yalnız noktalar sürecin sonlarındaysa.

## 7. Snapshot Ensembles

### 7.1 Fikir

Snapshot Ensembles, bir ağın eğitim sürecindeki farklı durumlarının kararlarını birleştirir (kaynak: arXiv 1704.00109, ekrandan, 01:05:00). Tek bir eğitim sürecinden $x$ tane model çıkarılır ve her biri ayrı bir lokal minimumdadır. Bu ilk bakışta önceki bölümle çelişir: aynı süreçteki noktalar aynı minimuma doğru gidiyordu. Farkı yaratan, öğrenme katsayısının döngüsel olarak güncellenmesidir.

### 7.2 Öğrenme katsayısı planları

**Soru:** Öğrenme katsayısı nedir? **Cevap:** Adım büyüklüğü (step size). SGD'nin kaos içinde sonsuza kadar kalmayıp bir yere çökmesi için adım büyüklüğü küçültülür. Başta büyüktür, sürecin sonlarına doğru adım adım küçültülür; küçük adımlarla bir yere yakınsanır.

Standart planda öğrenme katsayısı bütün süreç boyunca azalır: büyük bir değerden başlar, sonda çok küçük bir değere iner ve süreç biter. Slayttaki şekilde (Figure 1, sol: Single Model, Standard LR Schedule) model yüzeyde gezinip sonunda tek bir minimuma iner.

Döngüsel planda (Figure 1, sağ: Snapshot Ensemble, Cyclic LR Schedule) önce bir model baştan sona eğitilir; öğrenme katsayısı başta yüksek, sonda düşüktür. Sonra sıfırdan başlanmaz, kalınan yerden devam edilir ($w_T$'den $w_{T+1}$ üretilir), ama bu geçişte öğrenme katsayısı en baştaki değere yükseltilir. Amaç her biri farklı bir lokal minimumda bulunan ağırlıklara ulaşmaktır.

Neden katsayı büyütülür? Bir minimumdan ($w_k$) başka bir minimuma atlamak için büyük adımlar gerekir. Adım büyüklüğü türev ile öğrenme katsayısının çarpımına bağlıdır. $w_k$ bir lokal minimum olduğu için türev sıfıra yakındır; türeve bağlı bir şey yapılamaz. O hâlde büyütülebilecek tek şey öğrenme katsayısıdır. Katsayı artırılınca ağ o minimumdan çıkar, başka yerlerde dolaşıp ikinci bir minimuma, sonra üçüncüsüne iner.

Slayttaki eğri (CIFAR10, L=100, k=24, B=300 epochs; Figure 2: 100 katmanlı DenseNet, $M = 6$ cosine annealing döngüsü) eğitim loss'unu gösterir: standart planda (mavi) loss birkaç basamakta düşer; döngüsel planda (kırmızı, cosine annealing with restart lr 0.1) loss her döngüde düşüp yeniden yükselir ve her döngünün sonu Model 1 ... Model 6 olarak işaretlidir (ekrandan, 01:05:00).

> **Ek bilgi (derste anlatılmadı):** Snapshot Ensembles makalesinde döngüsel katsayı büyük olasılıkla kosinüs biçimindedir: $\alpha(t) = \frac{\alpha_0}{2}\left(\cos\left(\frac{\pi \cdot \mathrm{mod}(t-1, \lceil T/M \rceil)}{\lceil T/M \rceil}\right) + 1\right)$. Burada $T$ toplam iterasyon, $M$ döngü sayısı, $\alpha_0$ başlangıç katsayısıdır; her döngünün sonunda katsayı sıfıra yaklaşır ve o anki model kaydedilir.

### 7.3 Neden kararlar birleştirilir?

**Soru:** Bu birbirinden farklı modelleri parametre uzayında, yani parametrelerinin ortalamasını alarak birleştirmek mantıklı mı? **Cevap (bir öğrenci):** Az önceki gibi farklı lokal minimumlarda oldukları için olmaz. Hoca şekil üzerinde gösterdi: 2. ve 3. minimumun ortası, ikisinden de daha yüksek bir yerdedir; orta nokta işe yarayan bir nokta değildir. Bu yüzden snapshot'lar karar uzayında birleştirilir.

### 7.4 Sonuçlar

Slayt üç bölümden oluşuyordu (ekrandan, 01:00:00).

**Kararların benzerliği.** Figure 6: CIFAR100 üzerinde DenseNet-100 ile alınan 6 snapshot'ın softmax çıkışları arasındaki ikili korelasyon. Döngüsel planda ("Cosine with restart", $\alpha_0 = 0.2$, her 50 epoch'ta yeniden başlatma) değerler yaklaşık 0.88-0.93 arasındadır. Standart planda ("Standard lr scheduling", iki katsayı düşüşü, her 50 epoch'ta snapshot) ilk snapshot'larla korelasyon yaklaşık 0.76-0.85, son üç snapshot (4, 5, 6) arasında ise 0.99'dur. Hoca bunu şöyle yorumladı: standart planda son modeller birbirinin aynısıdır; aynı şeyi söyleyen üç modelden ensemble kurmanın anlamı yoktur. Döngüsel planda farklılık oluşur.

**Normal ensemble ile karşılaştırma.** Grafik (CIFAR100, DenseNet-40) model sayısına göre ensemble test hatasını verir. Mavi kesikli çizgi tek modeldir, yaklaşık %26 hata. Kırmızı çizgi snapshot ensemble'dır (model başına 50 epoch); model sayısı arttıkça hata düşer. Siyah çizgi tamamen eğitilmiş modellerin true ensemble'ıdır (model başına 300 epoch); hatası en düşüktür, grafikte 6 modelde yaklaşık %19'a iner.

**Soru:** True ensemble nedir? **Cevap:** Ağların yapıları aynıdır. Snapshot ensemble'da tek bir $w_0$ vardır; $w_1, w_2, \dots, w_6$ tek bir eğitim süreci boyunca erişilen noktalardır. True ensemble'da ise her model farklı bir $w_0$'dan başlar ve sonlarına varılan ağların kararları birleştirilir. True ensemble kesinlikle daha iyidir: birçok bağımsız süreç çok daha çeşitli (diverse) sonuçlar verir.

**Soru:** True ensemble daha iyiyse neden snapshot ensemble yapıyoruz? **Cevap:** Süre. Tek modelin eğitim süresi ile snapshot ensemble'ın eğitim süresi aynıdır: tek model 300 epoch'ta, snapshot ensemble da toplam 300 epoch'ta, her 50 epoch'ta bir model üreterek eğitilir. True ensemble'da her model için 300 epoch harcanır. Öğrenme katsayısı değiştiği için izlenen yol tek modelinkiyle aynı değildir, ama süre aynıdır.

## 8. Parametre uzayında iki nokta arasındaki doğru

### 8.1 Snapshot'lar arası değerlerin başarıları

Aynı slaytın alt kısmında Figure 5 vardı: son model (altıncı snapshot) ile bütün ara snapshot'lar arasında parametre uzayında doğrusal ara değerleme; $\lambda = 0$ ara snapshot'ı, $\lambda = 1$ son modeli gösterir (ekrandan, 01:00:00). Sol taraf CIFAR10 (cosine annealing), sağ taraf CIFAR100 ve standart lr planıdır.

Bunu anlamak için hoca şunu açıkladı: bir ağın örneğin 1000 parametresi varsa ağ, 1000 boyutlu uzayda bir noktadır. Altıncı modelin vardığı nokta bir nokta, beşinci modelin vardığı nokta başka bir noktadır. İki nokta arasına bir doğru çizilip bu doğru üzerindeki test hatası izlenebilir.

Hoca iki boyutlu bir çizimle gösterdi (ekrandan, 01:10:00): $w_0$'dan başlanır, dolaşılıp $w_1$'e varılır (birinci model), sonra $w_2, w_3, \dots, w_6$'ya gelinir. $w_5$ ile $w_6$ arasına bir doğru çizilebilir. Bu doğrunun üzerindeki her nokta da bir YSA'dır, tahmin üretebilir ve test başarısı ölçülebilir.

Grafikte kırmızı eğri 5. snapshot'ı, sarı 4.'yü, turkuaz 3.'yü, mavi 2.'yi, mor 1.'yi son modele bağlar. Altıncı modelin test hatası yaklaşık %5'tir; 5., 4. ve 3. snapshot'lar ona yakındır, 2. yaklaşık %6, 1. yaklaşık %7 hata verir. Asıl önemli olan doğru boyuncaki değişimdir: $w_6$ ile $w_1$ arasında test hatası yükselip yeniden iner; arada bir dağ vardır. Son snapshot'lar arasında fark küçüktür. Ne kadar önceki bir snapshot ile karşılaştırılırsa fark o kadar büyür.

Standart öğrenme katsayısıyla (NoCycle) aynı grafikte 1., 2. ve 3. snapshot'larla arada çok yüksek dağlar vardır; 4. ve 5. ile büyük fark yoktur.

### 8.2 Doğru üzerindeki loss nasıl hesaplanır?

**Soru:** Bunun nasıl yapıldığını merak ediyorum. **Cevap:** Hoca slayta $L = F(b_1, b_2, X, Y)$ yazdı (ekrandan, 01:15:00). $X$ girişler, $Y$ çıkışlar, $b_1, b_2$ modelin iki parametresidir (iki boyutlu bir model). Gerçek bir YSA'da parametre sayısı kadar $b$ vardır. $w_6$'nın iki boyutu verilince $X, Y$ için bir $L$ değeri bulunur; $w_5$ için de aynısı yapılır. $w_5$ ile $w_6$'yı birleştiren doğrunun üzerindeki herhangi bir nokta da verilince yine bir loss bulunur. Bu loss'ların değişimi grafikte görülür: bazı bölgelerde düzgün (smooth) gider, bazılarında yukarı doğru artar.

Hoca, ödevin bu konuyla ilgili olduğunu söyledi.

## 9. Bağımsız eğitimlerle erişilen lokal minimumlar bağlıdır

### 9.1 Gözlem

Bu doğruları inceleyen çalışmalardan şaşırtıcı bir sonuç çıktı: bağımsız eğitimlerle erişilen lokal minimumlar bağlıdır (kaynak: arXiv 1803.00885, "Essentially No Barriers in Neural Network Energy Landscape", ekrandan, 01:35:00). Bağımsız eğitim, farklı $w_0$'lardan başlayıp farklı yerlere varmaktır (true ensemble gibi); aynı süreçteki farklı snapshot'lar için de aynı şey geçerlidir.

Şekilde (Figure 1) $\theta_1$ ve $\theta_2$ iki ayrı minimumdur; burada $\theta_1$'den sonra $\theta_2$'ye gidilmiş değildir, ikisi farklı $w_0$'lardan varılmış noktalardır. Aralarındaki doğrusal ara değerlemede (linear interpolation) loss önce yükselir, biraz azalır, tekrar yükselir; doğru üzerindeki loss yaklaşık 4'e çıkar. Ama araştırmacılar bu iki noktayı birleştiren bir yol (our path) bulmuştur ve bu yol üzerinde loss neredeyse sabit kalır (sağdaki turuncu çizgi). Şekil DenseNet-40-12 ile CIFAR10 üzerinde, yaklaşık bir milyon boyutlu eğitim loss fonksiyonunun bir kesitidir. Yani iki minimum, birinden diğerine geçilemeyecek bir dağla çevrili değildir.

> **Ders sonrası not:** Hoca yol için "test hatası azalmıyor" dedi; şekle göre kastedilen, yol boyunca hatanın artmaması, yani yolun neredeyse düz olmasıdır.

### 9.2 Bir öğrencinin itirazı: tek boyutta böyle bir yol yok

**Soru:** Tek boyutlu bir loss fonksiyonu düşünelim. Bir başlangıç soldaki çukura, diğeri sağdaki çukura düşsün. Arada loss değişmeden bir doğru çizemeyiz. **Cevap:** Hoca önce tek boyutta iki nokta arasında zaten yalnız bir doğru olduğunu, başka bir yol seçme şansı olmadığını söyledi. Sonra şunu açıkladı: iddia iki ya da üç boyutlu uzaylar için değildir. Düşük boyutlu, konveks olmayan bir fonksiyonda iki lokal minimum arasında loss artırmadan bir yol her zaman bulunamaz; çok derin bir çukurdan çıkmak için loss'u artırmak gerekir. İddia, derin öğrenme mimarilerindeki binlerce, milyonlarca boyutlu uzayların bir özelliği olarak ileri sürülür.

**Soru:** Bu bir varsayım mı, yani kesin değil mi? **Cevap:** Bu, önceki hafta görülen teorem-ispat türünden bir sonuç değildir. Gösterilen şekil DenseNet-40-12 mimarisi ile CIFAR10 kullanılarak oluşan parametre uzayında çizilmiştir; aynı şey farklı birçok mimari için de yapılmıştır. Yani empirik olarak gösterilmiş bir sonuçtur, ispatlanmış bir teorem değildir.

Hoca bunu derin ağların neden iyi çalıştığı sorusuna bağladı. Normalde parametre sayısı gereksiz yere artırılınca model karmaşıklaşır ve aşırı öğrenme (overfit) olur. Derin öğrenme mimarileri ise yeni katmanlar ve nöronlar eklendikçe hâlâ overfit olmaz; bu hâlâ tam çözülmüş bir durum değildir. Bu çalışmalar, sebebin bu tür yolların bulunması ve bu sayede uzayların kolay öğrenilebilmesi olduğunu öne sürer.

### 9.3 Yol nasıl bulunur?

$w_1$ ve $w_2$'nin eğitim ve test kümeleri üzerindeki performansı doğru boyunca çizilir. Önce aradaki yol tek bir kırılma noktasıyla (üçgen gibi) kurulur; loss'un en yüksek olduğu yerden yeni bir nokta (pivot) eklenip yol bölünür. Bu işlem tekrarlandıkça yol, hatanın değişmediği bir yola yaklaşır. Figure 4 (ResNet-20, CIFAR10) dört aşamayı gösterir (ekrandan, 01:45:00): ilk döngüden sonra genelde bir iki köşe kesilir ve yüksek loss değerlerine yeni pivotlar eklenir; yüksek öğrenme katsayısıyla (0.1) dört döngüden sonra en yüksek loss beş kat azalır; düşük katsayıyla (0.01) ilk tur enerjiyi iki kat daha azaltır; 14 döngüden sonra pivotlar arasında önemli bir tümsek kalmaz ve yöntem yakınsar.

Sonraki araştırmalarda bu bağlantının daha kolay kurulabildiği görüldü: Bezier eğrileri, polinom eğriler ya da tek kırılmalı düz çizgilerle de yapılabiliyor. Ayrıca aynı eğitim içinde öğrenme katsayısıyla oynanarak üretilen noktaların da birbirine bu şekilde bağlı olduğu gösterildi. Hoca bunun iki boyutta düşünülmemesi gerektiğini vurguladı: iki boyuttan üç boyuta geçince bile bulunabilecek yolların sayısı çok artar; ekranın içine doğru bir boyut daha düşünülürse o yönden dolaşan yollar da olabilir.

Slaytta ayrıca "Ağırlıklarda ölçeklendirme hatayı değiştirmez" notu vardı (ekrandan, 01:35:00).

> **Ek bilgi (derste anlatılmadı):** Bezier eğrisi ve çok parçalı doğrularla minimumları birleştiren yaklaşım büyük olasılıkla Garipov ve arkadaşlarının "Loss Surfaces, Mode Connectivity, and Fast Ensembling of DNNs" (2018) çalışmasıdır. Aynı çalışma, bu yollar boyunca dolaşarak hızlı ensemble (Fast Geometric Ensembling) kurmayı da önerir.

## 10. Kararları değil, ağırlıkları birleştirmek (SWA)

### 10.1 Fikir

Slayt başlığı "Kararları değil, ağırlıkları birleştirelim" idi (kaynak: arXiv 1803.05407, ekrandan, 01:50:00):

- Ağın eğitiminin sonundaki epoch'lardaki ağırlıkların ortalamasını alalım.
- Son epoch'larda sabit yüksek LR ya da döngüsel LR kullanılıyor.
- Her modeli ayrı ayrı tutmaya gerek yok; ek bir model yeterli.

Slayttaki temel fikir: X'ler aynı eğitim sürecinde oluşan ve birleştirilen ağırlıklardır; R bölgesindeki kaos. Tek bir eğitim vardır ve bu eğitimle erişilen farklı $w$'ların kararları değil, kendileri ortalanır; yani birleştirme parametre uzayında yapılır. Bu ortalamaya SWA (Stochastic Weight Averaging) denmiştir. Slayttaki şekilde test hatası yüzeyinde $W_1, W_2, W_3$ noktaları kenarlarda, $W_{SWA}$ ise ortadaki düşük hatalı bölgededir; altındaki grafikler döngüsel öğrenme katsayısını ve buna bağlı salınan test hatasını gösterir.

### 10.2 Geniş çözüm

Çalışmada SGD ile bulunan nokta ile SWA noktasının çevresi incelenmiştir: noktadan geçen rastgele doğrultular (ray) çizilir ve bu doğrultular üzerindeki hatalara bakılır (iki boyutta değil, binlerce boyutta). SWA'nın çevresinde hata çok daha az artar, SGD'nin çevresinde daha çok artar. SGD tarzı bir algoritma bölgenin kenarına yakın bir çözüme varır: çevresinin bazı yerleri başarılı, bazı yerleri başarısızdır. SWA'nın çevresi ise her yönde başarılıdır; "geniş çözüm" ile kastedilen budur.

SGD ve SWA noktalarını birleştiren doğru da incelenmiştir. İkisinin arasında kötü bir durum yoktur; SWA'dan öteye doğru gidince hata çok artmaz, ama SGD tarafında biraz ilerleyince hata hemen yükselir. Bu, R bölgesindeki kaosun bir sonucudur: R bölgesinin kenarındaki bir noktadan biraz hareket edince bölgenin dışına çıkılır ve hatalar yükselir. Bölgenin ortasına yakın bir sonuç, aynı eğitim sürecindeki noktaların (bağımsız eğitimlerin değil) ortalaması alınarak bulunabilir.

> **Ders sonrası not:** Hoca bu kısımda iki yerde "hatamız düşer" ve "hata düşmeye başlıyor" dedi; bağlama göre kastettiği, başarının düşmesi, yani hatanın artmasıdır.

Bir ayrıntı daha: eğitim kümesinde SGD'nin başarısı SWA'dan biraz daha iyidir, ama test kümesinde durum tersine döner; çünkü SWA'nın vardığı nokta daha geniş ve toleransı yüksek bir noktadır. Bu karşılaştırma ResNet ve VGG16 için yapılmıştır.

### 10.3 Yorum

Bağımsız ağ eğitiminin süresinden kaçınmak için tek eğitimden birçok model kaydedilir, ama bunlar bağımsız modeller (true ensemble) kadar başarılı değildir. Bağımsızların minimumları bağlıdır, doğru; ama kritik olan çeşitliliktir. Aynı eğitim sürecinden üretilen modeller bir noktaya kadar farklılaşır; true ensemble'daki modeller ise birbirinden çok daha fazla farklılaşır ve bu yüzden daha başarılıdır.

## 11. Hocanın denemeleri: Digits veri kümesi

### 11.1 Bağımsız eğitimler

Slayt başlığı "Biraz da bizden: Bağımsız eğitimler" idi (ekrandan, 01:55:00). Digits veri kümesinde mavi eğri eğitim, kırmızı eğri test başarısıdır. İki bağımsız eğitilmiş ağın farklı epoch'lar sonunda elde edilen ağırlıkları arasındaki değerler çizilmiştir; "O" işaretleri eğitim, "X" işaretleri test için iki son noktayı gösterir.

Bir ağ $A_1, A_2, \dots, A_{15}$, diğeri $B_1, B_2, \dots, B_{15}$ olarak 15 epoch ilerlemiştir. 4. epoch grafiği $A_4$ ile $B_4$'ü birleştiren doğruyu, iki yana da uzatarak gösterir. İki nokta arasında bir düşüş vardır ve çevrede de uzaklaştıkça başarı düşer. 7. epoch'ta başarılar yaklaşık 0.66'dan 0.7'li değerlere çıkmıştır ve aradaki vadi derinleşmiştir. 15. epoch'ta başarılar %80-90'a varmıştır; iki başarılı model arasında çok derin bir vadi oluşur. Slayttaki sonuç: vadi ileriye doğru derinleşiyor.

### 11.2 Aynı eğitim içinde

İkinci slayt "Biraz da bizden: Aynı eğitim içinde" idi; tek eğitimin noktaları $a_1, a_2, \dots, a_{15}$ (ekrandan, 02:05:00). Sütunlar 1 epoch fark (1-2, 6-7, 11-12), 3 epoch fark, 5 epoch fark ve en sona (15) kadar olan karşılaştırmaları gösterir (örneğin 1-4, 1-6, 1-15).

Hoca öğrencilere 6. ile 7. epoch'u birleştiren doğrunun (iki yana uzatılmış) grafiğinde ne gördüklerini sordu (ekrandan, 02:00:00). 6. ve 7. epoch'taki başarılar yaklaşık 0.75-0.8'dir. $a_6$'dan $a_7$'ye giden doğru $a_7$'den öteye devam ettirildikçe başarı artmaya devam eder ve yaklaşık 0.9'a çıkar. Yani ağırlıkların nasıl güncelleneceği, türev hesaplamadan bulunmuş olur: 6. ve 7. epoch arasındaki fark tekrar tekrar eklenerek ilerlenebilir ve başarı bir yere kadar artar.

Bir öğrenci bunun epoch sayısını ve hesaplama maliyetini azaltacağını, rastgele sapmaları da önleyeceğini söyledi; hoca bunun önemli olduğunu onayladı.

6 ile 10'u birleştiren doğruda biraz artış olur, sonra çok keskin bir düşüş gelir. 5 ile 15'i birleştiren doğruda 15'ten sonra başarı hemen düşer. En başarılı noktadan sonra bu yöntemle ileri gitmek mümkün görünmüyor. 11-12 ya da 11-14 gibi aralarında 1-3 epoch olan noktalarda ise yine iyi sonuç alınabiliyor; ilk epoch'larda değil, biraz ilerledikten sonra.

Slayttaki notlar (ekrandan, 02:05:00):

- $x$-$y$ arası farkı, başarı arttığı sürece $y$'ye ekleyerek devam et (gradyan hesaplamadan); artış durunca standart eğitime devam.
- Uzak noktalarda işe yaramıyor.
- En başarılı nokta için işe yaramıyor.
- Ölçeklendirme hatayı bozmuyor.

Hoca bunu iyi bir araştırma alanı olarak sundu: türev almayı bırakıp bu yönde hata düştüğü sürece ilerlemek, düşüş durunca tekrar türeve dönmek mümkün görünüyor. Süreci hızlandırabilir, ama en başarılı noktadan daha iyi bir yere götürüp götürmediği bilinmiyor.

Hoca ayrıca kendi grafiklerinde doğruyu iki noktanın ötesine de uzatmasının işe yaradığını söyledi; uzatmasaydı 6-7 doğrultusundaki bu ilginç artışı yakalayamayacaktı. Bu grafiklerde noktalar iki boyuta indirgenmiş değildir; orijinal yüksek boyutlu uzaydadır. Yatay eksen yalnızca doğru üzerindeki konumu verir: örneğin iki nokta arası 20 parçaya bölünmüş, iki yana birer birimlik (40'ar parça) uzatılmıştır; eksendeki 120 gibi değerlerin ayrıca bir anlamı yoktur.

## 12. Validasyon kümesinin rolü

Ödev konuşmasından sonra bir öğrenci validasyon kümesinin eğitime katkısını sordu.

**Soru:** Validasyon kümesinin sonuçları eğittiğimiz modele bir şekilde yansıyor mu? **Cevap:** Hayır. Test kümesi çok büyükse üzerinde performans ölçmek uzun sürer. Validasyon kümesi genelde eğitimde görülmeyen küçük bir veri kümesidir ve eğitim sürecinde performans onun üzerinde izlenir. Örneğin erken durdurma (early stopping) için kullanılır: validasyon performansı bir noktaya kadar artıp sonra artmayı bırakır ya da düşerse daha fazla ilerlemenin overfit'e götüreceği anlaşılır. Ağın ağırlıklarının güncellenmesine doğrudan bir katkısı yoktur; eğitimin nasıl gittiğini izlemek için bir tür iç denetimdir. Yalnız eğitim başarısına bakmak yeterli değildir.

**Soru:** J48 gibi bir ağaç algoritmasında validasyon kümesiyle sürecin kalitesi artırılabilir mi? **Cevap:** Ağaç derinleştikçe ilerleyen bir süreçtir. Ağaç genişlik öncelikli (breadth first) üretilirse süreç boyunca validasyon performansı izlenip ne kadar derinliğin yeterli olduğu görülebilir. Derinlik öncelikli (depth first) üretimde ağacın tamamı bitmeden o anki ağaç pek işe yaramaz, bu yüzden anlamlı olmaz. Validasyon kümesi ayrıca budama için de kullanılır: ağacın bazı dallarını ya da ensemble'ın bazı üyelerini budarken nereyi budayacağınıza onunla karar verirsiniz. Hiperparametre optimizasyonu da başka bir kullanım alanıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:23:20). Dost/düşman tanklarını ayıran bir YSA test kümesinde yaklaşık %99 başarı veriyor, ama gerçek ortamda %50 civarına düşüyor. Eğitim ve test resimleri aynı ortamda, aynı tanktan çekilmiş. Sorun ne olabilir?

> **Cevap (derste verildi):** Dost tankların resimleri güneşli, düşman tankların resimleri bulutlu havada çekilmiş. Eğitim ve test kümeleri bu resimlerden rastgele ayrıldığı için ikisinde de aynı yanlılık vardı. Ağ tankı değil, havanın güneşli olup olmadığını öğrenmişti.

**Soru 2** (derste sözlü, 00:25:01). Hikâyede neden özellikle YSA denildi? Karar ağacı kullanılsaydı ne değişirdi?

> **Cevap (derste verildi):** Karar ağacında "resmin üst kısmındaki piksellerin aydınlığı şu değerden büyükse dost" gibi düğümler görülür ve modelin tankla ilgisiz piksellere baktığı daha çabuk fark edilirdi. YSA'nın neye göre karar verdiğini anlamak daha güçtür.

**Soru 3** (derste sözlü, 00:33:06; tablo ekrandan, 00:35:00). Top-1 ve Top-5 hata ne demektir? Tabloya göre 2012'de CNN ensemble'ı ile ikinci sistem arasındaki Top-5 test hatası farkı nedir?

> **Cevap:** Top-1'de yalnız en olası tahmin, Top-5'te ilk 5 tahmin dikkate alınır; doğru sınıf bunların içinde değilse hata sayılır. Top-5 test hatası ikinci sistemde %26.2, 7 CNN ensemble'ında %15.3'tür; fark $26.2 - 15.3 = 10.9$ puandır.

**Soru 4** (derste sözlü, 00:38:15). Konu YSA ve büyük veri olduğunda ensemble'ın dezavantajı nedir?

> **Cevap (derste verildi):** Hesaplama maliyeti: $L$ ağ eğitmek yaklaşık $L$ kat hesaplama ve enerji demektir (paralel makinelerle süre azaltılabilir). Ayrıca milyonlarca parametreli ağları saklamak bellek gereksinimini artırır.

**Soru 5** (ekrandan, 00:50:00). Farklı $w_0$'lardan başlayan üç eğitim $w_{a1}, w_{a2}, w_{a3}$'e varıyor. Bu üç ağın parametrelerinin ortalamasını alıp tek bir model olarak kullanmak mantıklı mı? Aynı eğitim sürecinin son noktaları için cevap değişir mi?

> **Cevap (derste verildi):** Farklı başlangıçlar genelde farklı lokal minimumlara götürür ve iki minimumun ortası büyük olasılıkla daha yüksek hatalı bir yerdir; bu yüzden parametre ortalaması mantıklı değildir, kararlar birleştirilmelidir. Aynı sürecin sonundaki noktalar ise R bölgesinde aynı merkezin etrafında salındığı için parametre ortalaması mantıklıdır.

**Soru 6** (derste sözlü, 00:56:46). Snapshot ensemble'da döngüsel öğrenme katsayısıyla elde edilen modellerin parametre ortalamasını almak mantıklı mı?

> **Cevap (derste verildi):** Hayır. Her snapshot farklı bir lokal minimumdadır; örneğin 2. ve 3. minimumun ortası ikisinden de daha yüksek bir yerdedir. Bu yüzden snapshot'lar karar uzayında birleştirilir.

**Soru 7** (derste sözlü, 01:02:41). True ensemble daha başarılıysa neden snapshot ensemble kullanılır?

> **Cevap (derste verildi):** Süre. Snapshot ensemble, tek bir modelin eğitim süresinde (örnekte toplam 300 epoch, her 50 epoch'ta bir model) birden fazla model verir. True ensemble'da her model için ayrıca 300 epoch harcanır.

**Soru 8** (ekrandan, 02:00:00). Aynı eğitimin 6. ve 7. epoch ağırlıklarını birleştiren doğru iki yana uzatılıp başarı çiziliyor. Ne görülüyor ve bu ne işe yarar?

> **Cevap (derste verildi):** $a_7$'den öteye aynı doğrultuda devam edildikçe başarı bir süre artmaya devam eder. Yani 6. ile 7. epoch arasındaki fark tekrar tekrar eklenerek, türev hesaplamadan ilerlenebilir. Uzak epoch'lar arasında ve en başarılı noktadan sonra bu işe yaramaz.

**Soru 9** (derste sözlü, 02:22:01). Bir modelin test başarısı %70 ise başarılı mıdır, %90 olması mı gerekir?

> **Cevap (derste verildi):** Duruma göre değişir. Sınıflar eşit dağılmışsa ve 5 ya da 10 sınıf varsa %70 kötü bir başarı değildir. Ölçüt, rastgele tahminden en azından birkaç kat daha iyi olmaktır.

> **Çözüm (derste verilmedi):** Eşit dağılmış 5 sınıfta rastgele tahminin başarısı $1/5 = \%20$, 10 sınıfta $1/10 = \%10$'dur; %70 bunların sırasıyla 3.5 ve 7 katıdır.

**Soru 10** (ekrandan, 02:10:00). Ödev 3: YSA eğitim süreçlerini incelemek. 3 veri kümesi - YSA mimarisi seçin; mimarilerde başarılı test sonuçları elde edebilecek seçimler yapın. Her veri kümesi-mimari için 5 farklı başlangıç değeri ile eğitim yapın; eğitimlerin her epoch'undaki modelleri kaydedin (toplam 15 eğitim).

- A) Her eğitim için modelin başı ($w_0$) ile sonunu ($w_T$) birleştiren çizgi üzerindeki (eş aralıklı en az 10 adet) noktaların eğitim ve test hatalarının grafiklerini çizin, yorumlayın (3 grafik, her birinde 5 model).
- B) Farklı başlangıçlarla yapılan eğitimlerin her biri için geçilen ara noktaları ($w_0, w_1, \dots, w_T$) t-SNE ile 2 boyutlu yörünge hâline getirin. Aynı veri kümesi için üretilen yörüngeleri tek bir grafikte gösterin, yorumlayın (3 grafik, her birinde 5 yörünge).
- C) Farklı başlangıçlardan erişilen farklı sonları birleştiren çizgi üzerindeki (eş aralıklı en az 10 adet) noktaların eğitim ve test grafiklerini çizin, yorumlayın. Her veri kümesi için 5'in 2'li kombinasyonu kadar son ikilisi vardır; her veri kümesi için 3 ikiliyi gösterin (3 grafik, her birinde 3 ikili).
- Bonus: ek analizler, ilginç / beklenmedik sonuçlar.

> **Çözüm (derste verilmedi):** Derste uygulama yapılmadı; hocanın açıklamaları şunlardır. A ve C'de noktalar orijinal parametre uzayındadır, iki boyuta indirgeme yapılmaz; doğru $(1-\lambda) w_A + \lambda w_B$ biçimindeki ara ağların hatalarıyla çizilir. B'de her epoch'un ağırlık vektörü t-SNE (ya da PCA) ile iki boyuta indirgenir ve ardışık noktalar çizgiyle birleştirilerek yörünge gösterilir; farklı başlangıçların farklı yerlerde mi yoksa birbirine yakın yerlerde mi bittiği yorumlanır. C'deki ikili sayısı $\binom{5}{2} = 10$'dur (python ile doğrulandı). Hoca eğitimin bir iki saati geçmemesini ve modellerin testte de başarılı olmasını istedi; CIFAR'ın örnek sayısı azaltılmış hâli ya da MNIST gibi kümeler önerildi. Ekteki MATLAB kodundaki "4D" ifadesi yalnızca Digits veri kümesinin boyut biçimidir.

## Dersin Toparlaması

Bu derste YSA'lar kolektif öğrenme açısından incelendi. Tek bir YSA bile birlikte öğrenen nöronlardan oluşan bir kolektif sistemdir; ayrıca YSA'lar deterministik olmadıkları için başlangıç değeri, örnek sırası, hiperparametre ve veri artırımıyla kolayca çeşitlendirilebilir ve ensemble'ın temel öğrenicisi olarak kullanılabilir. 2012 ImageNet sonuçları, derin öğrenmenin sıçrayışında birden fazla CNN'in kararlarını birleştirmenin payını gösterdi. Dersin merkezinde eğitimi parametre uzayında bir yörünge olarak görmek vardı: farklı süreçlerin sonları farklı minimumlardadır ve kararları birleştirilir; aynı sürecin sonundaki noktalar ise aynı minimumun etrafında salındığı için ağırlıkları ortalanabilir (SWA). Snapshot ensemble, döngüsel öğrenme katsayısıyla tek eğitim süresinde farklı minimumlarda birkaç model üretir, ama çeşitlilikte true ensemble'a yetişemez.

İki nokta arasındaki doğru üzerinde hatayı incelemek, bu fikirlerin ortak aracıydı. Bu araçla minimumlar arasındaki dağlar, bağımsız minimumları birleştiren düşük loss'lu yollar ve hocanın Digits denemelerindeki derinleşen vadiler ile türevsiz ilerleme fikri görüldü. Hoca bir sonraki derste YSA'larla kolektif öğrenme konusuna aynı slaytlar üzerinden devam edileceğini söyledi; verilen ödev de bu doğru ve yörünge analizlerini kendi eğitilmiş ağlar üzerinde tekrarlamayı istiyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
