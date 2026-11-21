# Ders 11 Genişletilmiş Notu: Bilgi Saflaştırma, Born-Again Modeller ve Çekişmeli Üretici Ağlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Hatırlatması: SWA ve Bağımsız Eğitimler Arasındaki Vadiler
- 2. Öğretmen-Öğrenci Modeller ve Bilgi Saflaştırma
- 3. Born Again Trees (1996)
- 4. Model Compression (2006)
- 5. Distilling the Knowledge in a Neural Network (2015)
- 6. DistilBERT (2019)
- 7. Born-Again Neural Networks (2018)
- 8. Çekişmeli Üretici Modeller (GAN)
- 9. Ara Konu: Manifold Nedir?
- 10. GAN Üzerine Soru-Cevaplar
- 11. Proje Konuları
- 12. Üçüncü Ödev Sunumlarından Akademik Noktalar
- Örnek Sorular

## 1. Önceki Dersin Hatırlatması: SWA ve Bağımsız Eğitimler Arasındaki Vadiler

Ders, bir önceki haftada başlanan "yapay sinir ağlarında kollektif öğrenme" slaytının tamamlanmasıyla başladı. Önce geçen haftanın konuları hatırlatıldı. Snapshot ensemble'lar görülmüş, bağımsız eğitimlerle erişilen lokal minimumların aslında birbirine bağlı olduğuna dair deneysel bulgular incelenmişti.

Kararları değil ağırlıkları birleştirmek fikri de konuşulmuştu. Bunun örneği SWA (Stochastic Weight Averaging) yöntemidir. Hoca bunu şöyle açıkladı: slayttaki $W_1, W_2, W_3$ gibi noktalar, iyi bölge ile kötü bölge arasındaki sınırlarda bulunur. Bu noktaların ortalaması ise etrafı daha geniş, yani sınırda olmayan, daha güvenli bir bölgeye düşer. Bu tür noktaları üretmek için döngüsel öğrenme oranı (cyclic learning rate) yaklaşımları kullanılıyordu.

Ardından hocanın kendi denemesi hatırlatıldı (ekrandan, 00:10:00). Slaytın başlığı "Biraz da bizden: Bağımsız eğitimler" idi:

- Digits veri kümesi kullanılmış.
- Mavi eğri eğitim (train), kırmızı eğri test başarısıdır.
- İki bağımsız eğitilmiş ağın farklı epoch'lar sonunda elde ettiği ağırlıklar arasındaki değerler incelenmiş.
- "O" işaretleri eğitim son noktaları, "X" işaretleri test son noktalarıdır.
- Sonuç (slaytta kırmızı): vadi ileriye doğru derinleşiyor.

Deney şöyle kurulmuştu: iki bağımsız eğitimin 4., 7. ve 15. epoch'larda eriştiği noktaların arasına bir çizgi çekilir. Bu çizginin üzerindeki her nokta aslında yeni bir parametre vektörüdür, yani yeni bir ağdır. Bu noktaların başarıları çizildiğinde, iki uç arasındaki vadinin epoch ilerledikçe derinleştiği görülür. 15. epoch'ta iki ağın başarısı yaklaşık %85-90'dır.

**Soru:** Vadinin en derin noktası tek bir dik çukur yerine biraz daha yatay, geniş bir taban şeklinde olabilir mi? Kendi ödevimde bir model böyle bir şekil verdi. **Cevap:** Olabilir, bu anormal bir durum değildir. Önemli olan bu grafikleri çizdirmek ve yorumlamaktır.

Hoca, aynı modelin farklı epoch'ları arasındaki çizgiyi de hatırlattı. İki nokta arasındaki bölüm (grafikte kırmızı) iki noktayı birleştiren aralığı, iki yandaki sarı bölümler ise aynı doğrultuda çizginin devamlarını gösterir. Bu kez söz konusu olan iki farklı bağımsız başlangıç değil, aynı ağın farklı epoch'larda eriştiği noktalardır. Ardışık epoch'lar arasındaki çizgi ileriye doğru uzatıldığında başarının bir süre daha arttığı görülmüştü; ama 15. epoch, yani son epoch'tan sonra bu artış görülmüyordu.

Hocanın bu deneyden çıkardığı sonuç: iki epoch'ta erişilmiş noktalar arasındaki çizgiyi ilerleterek başarıyı artırmak hâlâ mümkün görünüyor. Bunun güzel tarafı, bu çizgi üzerinde ilerlerken gradyan hesabı yapmaya gerek olmamasıdır.

## 2. Öğretmen-Öğrenci Modeller ve Bilgi Saflaştırma

Bu dersin asıl konusu öğretmen-öğrenci modellerdir. Konu "knowledge distillation" ya da "model distillation" adlarıyla da geçer; Türkçesi bilgiyi ya da modeli saflaştırmaktır (ekrandan, 00:15:00).

Temel problem şudur: elinizde büyük bir model vardır. Bu modelle aynı ya da kabul edilebilir ölçüde düşük performansa sahip, ama ondan daha küçük bir model elde etmek istersiniz. Bunun nedenleri açıktır: küçük model çalışma zamanında (test aşamasında, ürün olarak çalıştırılırken) daha hızlıdır ve daha az bellek tutar. Dolayısıyla kaynakları daha verimli kullanır.

Slaytta üç yaklaşım sayıldı:

- Öğretmen büyük bir model, öğrenci onu taklit eden küçük bir modeldir.
- Çok öğretmen, bir öğrenci: çok sayıda modeli tek bir modelle taklit etmek. Burada da toplam model büyüklüğü düşünüldüğünde bir küçültme vardır.
- Eş kapasiteli öğretmen ve öğrenci: ikisi aynı büyüklüktedir. Model küçülmez. Amaç, performans, doğruluk ve genelleştirme kabiliyeti bakımından öğretmenden daha iyi bir öğrenci üretmektir.

İlk iki yaklaşımın amacı öğretmen ya da öğretmenlerden daha iyi bir model bulmak değildir. En azından onlar kadar iyi, ya da birazcık daha kötü ama çok daha küçük modeller üretmektir. Sonuncunun amacı ise öğretmenden daha başarılı öğrenciler yetiştirmektir.

## 3. Born Again Trees (1996)

İlk örnek, birçok karar ağacını taklit eden tek bir ağaç üretme problemidir (ekrandan, 00:20:00). "Birçok karar ağacı" denince akla ensemble gelir; yani soru şudur: ensemble kadar başarılı tek bir ağaç üretebilir miyiz? Born Again Trees bu soruya yanıt arar ve günümüzdeki bazı yaklaşımların temelidir.

Slayttaki adımlar:

- Önce karar ağaçları orijinal veriyle eğitilip ensemble oluşturulur.
- Yapay veri üretimi yapılır (smearing yöntemi). Ama en başta değil.
- Bir T düğümü bölünmeden önce veriler üretilir ve o ana kadar üretilmiş ağaca verilir. T düğümüne düşen üretilmiş verilerle bölünme hesaplanır. Üretim, T düğümüne önceden tanımlı NS adet yeni örnek düşene kadar devam eder. Aşağı seviyelere inildikçe az sayıda örnekle karar verme problemine de çözüm budur.
- Üretilenlerin etiketleri ensemble ile hesaplanır.
- Üretilen ağaç budanır.
- Yeni ağaç daha büyük ve daha başarılıdır.

### 3.1 "En başta değil" ne demek?

Hoca bunu açıklamak için dönemin başında anlatılan karar ağaçlarını hatırlattı ve sınıfa bir soru sordu: kök düğümde hangi özelliğin ve hangi eşik değerinin seçileceğine karar verirken örneklerin hangilerine bakarız? Burada sorulan, hesabın nasıl yapıldığı (information gain vb.) değil, hangi örneklerin kullanıldığıdır. Cevap: kökün kararı verilirken bütün örnekler kullanılır.

Bir seviye aşağı inildiğinde veri kümesi kökteki karara göre ikiye bölünmüştür; bir tarafta büyükler, bir tarafta küçükler vardır. Ortalama olarak bir alt seviyedeki düğümün kararı verinin yarısıyla verilir. Yapraklara yaklaştıkça örneklerin çok az bir kısmına bakılarak karar verilir. Bin örnekle başlanmışsa, en alt seviyelerde belki beş altı örneğe bakılarak hangi özellik ve hangi eşik değerinin seçileceğine karar verilir.

Bu, yüksek boyutlu uzaylarda bir problemdir. Çünkü yukarıdan aşağı inildikçe verinin boyutu azalmaz. Yukarıda bin boyutlu örnekler varsa aşağıda da bin boyutlu örnekler vardır. Bin boyutlu bir uzayda 3-5 örneğe bakarak karar vermek, varyansı çok çok yüksek bir iştir. Slayttaki "yapay veri üretiliyor ama en başta değil" ifadesinin anlamı budur: her düğümün kararı verilirken orijinal örneklerin yanına o düğüme düşen yapay örnekler eklenir.

### 3.2 Etiketler ve sonuç

Yapay veri üretmek oldukça basittir; rastgele üretilebilir (tamamen rastgele üretmek çok makul olmasa da çeşitli yöntemleri vardır). Asıl soru, üretilen örneğe hangi etiketin verileceğidir. Born Again Trees'te bu etiketler önceden eğitilmiş ensemble ile belirlenir. Yani ensemble'ın burada tek kullanım amacı üretilen verileri etiketlemektir.

Sonuçta tek bir ağaç elde edilir. Bu ağaç, orijinal veriyle eğitilmiş ağaçtan daha büyük ve daha başarılıdır. "Daha başarılı" ifadesi ensemble'ın ağaçlarıyla teker teker karşılaştırıldığında geçerlidir; ensemble'ın kendisinden daha başarılı olduğu anlamına gelmez. Amaç ensemble kadar başarılı tek bir ağaç yapmaya çalışmaktır.

## 4. Model Compression (2006)

Yaklaşık on yıl sonraki bu çalışmada karar ağaçları yerine yapay sinir ağları vardır (ekrandan, 00:25:00). Birçok modelden oluşan bir ensemble bulunur; amaç bu ensemble'ı iyi taklit eden tek bir küçük model oluşturmaktır.

Yöntem: eldeki eğitim kümesinden çok daha büyük bir yapay eğitim kümesi üretilir. Burada Born Again Trees'teki düğüm düğüm üretim mekanizmasına gerek yoktur; yapay veri en baştan üretilebilir. Çünkü o mekanizmanın nedeni ağacın alt seviyelerinde kararların çok az örnekle verilmesiydi. Yapay sinir ağlarında böyle bir dert yoktur; aşağı inildikçe daha az örnekle karar verilmez.

Yapay veri üretmek için çeşitli yöntemler denenmiş (RAND, NBE, MUNGE). Bunlar elinizdeki dağılıma bakarak yeni veriler üretir; amaç rastgele veri üretmek değildir. Yapay örneklerin sınıfları ensemble ile belirlenir, yeni örnekler ve etiketlerle küçük model eğitilir. Sonuçta küçük model, orijinal eğitim verisiyle eğitilmesine göre daha iyi sonuç verir. Bu, karar ağaçlarındaki yaklaşıma oldukça benzer; yalnız yapay veri üretim kısmı farklıdır.

### 4.1 Sonuç grafikleri

Slayttaki sol grafik (ekrandan, 00:25:00) "Figure 2: Average perf. over the eight problems" başlığını taşır. Dikey eksen RMSE, yatay eksen eğitim kümesi büyüklüğüdür (4k, 10k, 25k, 50k, 100k, 200k, 400k). RAND, NBE ve MUNGE için saklı katmandaki nöron sayısı 128'dir. Grafikte ensemble selection, best single model ve best neural net için yatay referans çizgileri de vardır.

- En soldaki nokta "sadece orijinal" veridir: 4K'lık eğitim kümesi. Burada hata yaklaşık 0.28 civarındadır.
- En sağdaki nokta "4K orijinal + 396K yapay" veridir, yani toplam 400K örnek.
- MUNGE ile yapay veri arttıkça hata düzenli biçimde düşer (yaklaşık 0.265'e iner). Örneğin 4K orijinalin üstüne 6K yapay veri eklenince 10K'lık bir küme olur ve başarı biraz artar; yapay veri arttıkça artmaya devam eder.
- RAND ile, yani rastgele üretimle, hiçbir kazanç sağlanmaz; hata hatta biraz artar.
- MUNGE'un iyi çalışması, orijinal veri kümesine oldukça yakın örnekler üretebilmesindendir. Ne kadar benzer örnekler üretilirse o kadar iyi olur.

> **Ders sonrası not:** Hoca bir yerde "4K artı 496K, yani 400 bin" dedi; slayttaki değer 396K'dır ve $4\text{K} + 396\text{K} = 400\text{K}$ eder.

Sağdaki grafik (AVERAGE) saklı katmandaki nöron sayısı 1'den 256'ya arttıkça MUNGE ile eğitilen ağın hatasının düştüğünü gösterir (slayttaki not: MUNGE 400K, diğerleri 4K eğitim kümesiyle). Saklı katman ne kadar karmaşık hale gelirse o kadar başarılı sonuç üretilir.

Ensemble'ın buradaki rolü yine aynıdır: 396K'lık yapay veriyi etiketlemek. Sonuç tek bir modele göre daha başarılıdır, ama ensemble'ın kendisinden daha başarılı değildir.

## 5. Distilling the Knowledge in a Neural Network (2015)

Bu çalışmanın amacı da bir modeli taklit eden, ondan daha küçük bir model bulmaktır (ekrandan, 00:30:00). Slayttaki tanımlar:

- Logit'ler ($z_i$): softmax katmanının girişleri.
- $q_i$: softmax'ın çıkışları, yani $i$. sınıfa ait olma olasılıkları.
- $T$: sıcaklık. Yüksek değer, yumuşak dağılım verir.

$$q_i = \frac{\exp(z_i/T)}{\sum_j \exp(z_j/T)}$$

Sınıflandırma yapan bir yapay sinir ağının sonunda bir softmax katmanı bulunur ve sınıfa ait olma olasılıklarını verir. $z$'ler normalize değildir, toplamları 1 değildir; $q$'ların toplamı ise 1'dir.

> **Ders sonrası not:** Hoca $q$'ları "$z$'lerin toplamına bölünmesi" diye özetledi. Slayttaki formüle göre doğrusu, $\exp(z_i/T)$ değerinin bütün $\exp(z_j/T)$ değerlerinin toplamına bölünmesidir.

> **Ek bilgi (derste anlatılmadı):** $T=1$ olağan softmax'tır. $T$ büyüdükçe $z_i/T$ değerleri birbirine yaklaşır ve olasılıklar düzleşir; $T \to \infty$ iken bütün sınıflar eşit olasılığa yaklaşır. Böylece en olası sınıf dışındaki sınıflar arasındaki göreli benzerlik bilgisi (örneğin bir "2"nin "3"e "7"den daha çok benzemesi) soft target'larda görünür hale gelir.

### 5.1 Motivasyon

Elinizde 100 katmanlı bir model, bir de 10 katmanlı küçük bir model olsun. Orijinal veriyle 100 katmanlı modeli eğitirseniz bir başarı elde edersiniz. Aynı veriyle 10 katmanlıyı eğitirseniz daha düşük bir başarı elde edersiniz. Yalnız orijinal veriyi kullanarak 10 katmanlıyı daha iyi yapamazsınız. Soru şudur: 100 katmanlı yapıyı da kullanarak, orijinal verinin yanına ek olarak, 10 katmanlı modeli 100 katmanlı kadar değilse de ona yakın başarıya getirebilir miyiz?

### 5.2 Hard target ve soft target

Önce büyük model orijinal eğitim kümesiyle eğitilir; bunda olağandışı bir şey yoktur. Orijinal eğitim kümesinin çıkışları **hard target**'tır: bir örnek sınıflardan yalnız birine aittir. Bir harf için "hem A hem B" denmez; orijinal eğitim kümesinde ya A ya B denir. Buna one-hot encoding denir: on sınıf varsa, bir örneğin çıkışında ait olduğu sınıfın indisinde 1, diğerlerinde 0 bulunur.

Yeni küçük modelin eğitiminde ise **soft target**'lar kullanılır. Slayttaki tanımlar:

- Transfer kümesi: (orijinal eğitim örnekleri, çıkışlar).
- Çıkışlar: büyük modelin yüksek $T$'li $q_i$'leri (soft targets).
- Küçük model yüksek $T$ ile transfer kümesi üzerinde eğitilir; test sürecinde $T=1$ alınır.

Yani girdiler, özellikler aynıdır; çıkışlar farklıdır. Bir resmin orijinal etiketi A sınıfıysa hard target "%100 A, diğer sınıflar 0" der. Soft target ise "en yüksek olasılıkla A, ondan sonra B, sonra C, D..." şeklinde bütün sınıflara olasılık dağıtan daha düzgün (smooth) bir etikettir. Küçük model girdiler değişmeden bu soft target'larla eğitildiğinde büyük modele yakın başarı gösterebilmiştir.

Hoca burada önemli bir noktaya dikkat çekti: büyük modelin kendisi sürecin içinde yoktur. Büyük modelin ağırlıklarını alıp küçük modelin içine koymak gibi bir işlem yoktur. Büyük modelin tek işi soft target'ları üretmektir. Soft target'lar başka bir yolla üretilebilseydi büyük modeli eğitmeye gerek kalmazdı; ama bunu elle yapmak mümkün değildir. Aslında yapılan, büyük modelin davranışını taklit etmektir. Küçük model orijinal etiketlerle değil, büyük modelin soft çıkışlarıyla eğitilir.

Slaytta küçük modelin eğitimine bir alternatif de verilmiştir:

$$w_1 \cdot \text{cross\_entropi}(\text{küçük model soft}, \text{büyük model soft}) + w_2 \cdot \text{cross\_entropi}(\text{küçük model soft}, \text{hard targets})$$

Slayttaki sonuç: 10 model, aynı büyüklükteki tek bir modele (benzer performanslı) indirgenebilmiş.

## 6. DistilBERT (2019)

2018'de BERT çıktıktan sonra, bu büyük modelin distill edilip edilemeyeceği, örneğin cep telefonuna konup hızlı çalıştırılıp çalıştırılamayacağı araştırıldı (ekrandan, 00:35:00). Slayttaki bilgiler:

- BERT'in katman (layer) sayısını azaltmışlar.
- Parametre sayısı %40 düşmüş, hız %60 artmış, başarı orijinalin %97'si olmuş.

Bellek açısından önemli, hız açısından da yaklaşık yarı yarıya bir kazanç vardır.

BERT'in kendisi temel olarak masked language modeling kaybıyla eğitilir. Hoca bunu kısaca anlattı: bir cümlenin içinden rastgele bir kelime kapatılır ve modelden o kelimeyi tahmin etmesi istenir. BERT'in en temel eğitimi budur; yanında bir sonraki cümleyi tahmin etmek, cümlelerin ardışık olup olmadığını tahmin etmek gibi görevler de verilebilir.

DistilBERT'te üçlü bir hata fonksiyonu kullanılmıştır:

- $L_{ce}$: distillation loss
- $L_{cos}$: cosine embedding loss
- $L_{mlm}$: masked language modeling loss

Küçük modelin ağırlıkları sıfırdan başlatılabilir. DistilBERT'te ise öğrencinin ağırlıklarının ilk değerleri öğretmenden alınmıştır: BERT'in eğitilmiş ağırlıkları, bazı kısımları silinerek öğrenciye konmuştur.

Slayttaki ablasyon tablosu (GLUE makro skorundaki değişim):

| Ablasyon | GLUE makro skor değişimi |
|---|---|
| $\emptyset$ - $L_{cos}$ - $L_{mlm}$ ($L_{ce}$ yok) | −2.96 |
| $L_{ce}$ - $\emptyset$ - $L_{mlm}$ ($L_{cos}$ yok) | −1.46 |
| $L_{ce}$ - $L_{cos}$ - $\emptyset$ ($L_{mlm}$ yok) | −0.31 |
| Üçlü kayıp + rastgele ağırlık başlatma | −3.69 |

Slayttaki yorum: $L_{mlm}$ en etkisiz bileşendir. Tabloya göre en büyük kayıp, öğrencinin ağırlıklarını öğretmenden almak yerine rastgele başlatmaktan gelir.

Hoca saflaştırmanın hâlâ çok aktif bir konu olduğunu vurguladı. BERT büyük bir modeldir, ama artık çok daha büyük ve daha başarılı modeller vardır. Bunları eğitmek zaten zordur; eğitilse bile kullanmak, özellikle küçük cihazlarda, güçtür. Bu yüzden bulutun işi yapması beklenir, bu da ağ bağımlılığı getirir. Bu modelleri benzer performansla sıkıştırıp küçük cihazlara taşımak için son birkaç yıldır yoğun çalışma vardır.

## 7. Born-Again Neural Networks (2018)

Born Again Trees'in sinir ağı karşılığı olan bu çalışma, "eş kapasiteli öğretmen ve öğrenci" yaklaşımına karşılık gelir (ekrandan, 00:40:00). Amaç modeli küçültmek değil, öğretmenden daha başarılı bir yapı kurmaktır.

Slayttaki maddeler:

- Öğretmen ile eş kapasiteye sahip öğrenciler.
- Öğrencilerin ardışık eğitimi.
- Öğretmenden daha başarılı öğrenciler.
- Öğrencilerden daha başarılı öğrenci topluluğu.

Şemadaki adımlar şöyledir:

- Step 0: $X$ veri kümesinin girdileri, $Y$ çıkışlarıdır. Öğretmen $T$, orijinal veri kümesi ve orijinal etiketlerle standart biçimde eğitilir ve bir $f(x)$ fonksiyonu üretir. Bu fonksiyon $X$'i $Y$'ye eşlemeye çalışır. Bu fonksiyonun soft etiketleri, yani $q_i$'ler alınır.
- Step 1: Öğrenci $S_1$ eğitilir. Girdi olarak yine orijinal veri kümesi, etiket olarak ise hem $Y$ hem de $T$'nin $f(x)$'i, yani soft etiketleri kullanılır.
- Step K: $S_1$'den $S_2$, $S_2$'den $S_3$ üretilir ve bu böyle $S_k$'ye kadar sürer.
- Ensemble: $S_1, \dots, S_k$ modellerinin birleşimiyle bir ensemble kurulur.

Yazarlar bazı veri kümelerinde öğretmenden daha başarılı öğrenciler ve öğrencilerin her birinden daha başarılı bir ensemble elde edildiğini görmüşlerdir. Hocaya göre ensemble'ın tekil öğrencilerden başarılı olması şaşırtıcı değildir.

Bu yaklaşım ardışık yapısı bakımından AdaBoost'a benzer. Ama AdaBoost'ta girdiler değiştirilir: önceki öğrenicilerin yanlış yaptığı örnekler ağırlıklandırılarak daha fazla seçilir. Burada ise her öğrenci aynı girdiyle eğitilir; yalnız orijinal etiketlerin yanında öncekinin soft etiketleri kullanılarak kayıplar hesaplanır ve optimize edilir.

## 8. Çekişmeli Üretici Modeller (GAN)

Son konu çekişmeli üretici modellerdir (ekrandan, 00:45:00). İşin içine iki model girdiği için bunu da bir ensemble olarak adlandırmak mantıklıdır.

Slayttaki maddeler:

- Üretici sistemler: girişlere benzeyen yeni örnekler üretmek (yüz, ayakkabı, manzara vb.).
- Bir modelin (A) ürettiği bir örneğin iyi/kötü olduğunu nasıl anlarız? (İnsan yargısı kullanmak pahalı/uzun.)
- Başka bir model (B) kullanalım: işi gerçeklerle üretilmişleri ayırmak (GAN).
- B ayıramamaya başladığında A yeterince iyi örnekler üretiyordur.
- Ama ya A kopya çekip direkt orijinal örnekleri üretirse? Bunu engellemek için A'nın girişi sadece rastgele gürültü.

Slayttaki şema: Random Input Vector → Generator Model → Generated Example; Generated Example ve Real Example → Discriminator Model → Binary Classification (Real/Fake). Sınıflandırma sonucundan hem üreticiye hem ayırıcıya "update model" okları döner.

### 8.1 Üretimdeki temel sorun

Üretici sistem, ona verilen örneklere benzeyen örnekler üretir. Bir kalem resmi verirseniz size bir sürü kalem resmi üretir. Üretilen örneklerin birbirinin aynısı olmasını istemeyiz; elimizde olmayan yeni örnekler üretebilmelidir. Ama aynı zamanda bizim örneklerimize benzemelidirler: kedileri verdiğimizde ürettiği şeye baktığımızda biz de ona kedi demeliyiz. İşin özü bu son cümlededir: bir modelin ürettiği örneğin iyi mi kötü mü olduğunu nasıl anlarız?

Sınıflandırmayı düşünün: model bir tahmin üretir ve elimizde gerçekte olması gereken değer vardır. İkisi aynıysa "doğru yaptın", farklıysa "yanlış yaptın" denir; araya insanın girmesine gerek yoktur. Üretimde ise sistem bir resim üretir ve bu resmin iyi mi kötü mü olduğunu sisteme söylememiz gerekir, ki ona göre optimizasyon yapılabilsin. Makinenin başına bir insan oturtup her iterasyonda üretilen resimleri "iyi" ya da "kötü" diye işaretletmek ölçeklenebilir değildir.

### 8.2 Ayırıcı model

Buradaki asıl hile başka bir model kullanmaktır. Bu modelin işi gerçek resimlerle üretilmiş resimleri ayırt etmektir. Üretici (generator) bir örnek üretir ve bunu ayırıcıya (discriminator) verir. Ayırıcının elinde gerçek örnekler de vardır. Gerçeğe "gerçek", üretilmişe "üretilmiş" diyebilecek midir? Bu iki sınıflı bir sınıflandırma problemidir.

Ayırıcının etiketleri otomatik olarak bilinir: üretilen örnekleri makine üretmiştir, gerçek örnekler zaten eldedir. Böylece veri kümesi de etiketleri de otomatik oluşur; insan müdahalesine gerek kalmaz.

Üretici başlarda iyi örnekler üretemezken ayırıcı çok başarılı olacaktır. Zaman ilerledikçe ayırıcı ayrımı yapamaz hale gelirse, yani gerçeklerle üretilmişleri birbirinden ayırt edemezse, modelin artık iyi örnekler ürettiği söylenir. Bunun ölçütü içerideki ayırıcının yanlışlık yapıp yapmamasıdır. Sohbetten gelen bir yoruma karşılık hoca, bu yolla gerçekte var olmayan insanların yüzlerinin üretilebildiğini doğruladı.

### 8.3 Kopya çekmeyi engellemek

Üreticiye gerçek örnekleri versek ve o da bunları hiç değiştirmeden "ben ürettim" diye geri verse ne olur? Gerçeklerle üretilmişler aynı olur ve ayırıcı onları ayırt edemez; sistem başarılı görünür ama hiçbir şey öğrenilmemiştir. Bunu engellemek için üreticinin girdisi yalnızca rastgele bir vektördür. Bu rastgele vektörün karşılığında bir resim, metin ya da müzik üretir. Bir yüz verip onu başka bir yüze çevirmez; çünkü o zaman çıktı verilen girdiye çok bağımlı olurdu.

Hocaya göre bunun yaptığı şey, rastgele bir noktayı üretilmesi istenen verilerin bulunduğu dağılımın üzerine eşlemektir. Bu veriler bir manifoldun üstünde bulunur; herhangi bir rastgele vektör manifoldun üzerine izdüşürülebiliyorsa bu iyi bir şeydir.

## 9. Ara Konu: Manifold Nedir?

Hoca "manifold" kavramını duyan olup olmadığını sordu. Bir öğrenci kavramı matematikten, topolojik bir kavram olarak duyduğunu söyledi. Hoca kavramı bir kâğıt yardımıyla kamerada gösterdi.

Üç boyutlu uzayda noktalar olsun ve bu noktaların hepsi bir kâğıdın üzerinde bulunsun. Kâğıdın üzerindeki noktalar üç boyutlu uzaydadır. Kâğıt düz olduğunda bu çok özel bir durum değildir. Şimdi noktalar kâğıt üzerindeki yerlerinde dururken kâğıt bükülsün. Örnekler hâlâ üç boyutlu uzaydadır; ama artık kâğıdın oluşturduğu bükülmüş yüzey üzerindedirler. Düz kâğıt da bir manifolddu; bükülmüş kâğıt gerçek verilerde karşılaşılan türden bir manifolddur.

Verileriniz üç boyutlu uzayda olsa da uzayın her bölgesinde eşit yoğunlukta değildir. Belli bölgelerinde aralarında ilişkiler vardır ve bu ilişkiler her yerde aynı değildir. Düz bir kâğıtta noktaların birbirleriyle ilişkisi her yerde aynıdır. Kâğıt büküldüğünde ise kâğıdın birbirinden uzak iki köşesi üç boyutlu uzayda birbirine çok yakın görünebilir. Oysa manifoldun üzerinden bakıldığında aralarındaki uzaklık, kâğıdın içinden dolaşarak gidilen uzun bir yoldur. Yani üç boyutlu uzaydaki uzaklık ile manifold üzerindeki uzaklık aynı değildir.

İnsan yüzleri için şöyle düşünülebilir: 50x50'lik yüz resimleri 2500 boyutlu bir uzaydadır. Bu uzayın içinde yüz resimleri tekdüze (uniform) dağılmış değildir; bir manifoldun içindedirler ve bu manifoldun boyutunun mümkün olduğunca küçük olması istenir. Bu, yerel uzaklıkların global uzaklıktan farklı olduğu bir uzay gibi düşünülebilir. Dolayısıyla GAN'larda yapılan iş bir uzayı tekdüze bir uzaya dönüştürmek değil, onu bir manifoldun üzerine izdüşürmektir. Yüz resimlerine karşılık gelen noktaların dağılımı Gauss değildir; bir kürenin ya da elipsoidin içinde bulunmazlar. O dağılım, manifoldun yapısını ortaya koyar.

## 10. GAN Üzerine Soru-Cevaplar

**Soru:** Ayırıcı yalnızca "gerçek" ya da "sahte" diye bir çıktı veriyor. 2500 parametreli bir yüz örneğinde, yüzün hangi kısmının gerçek olup olmadığı bilgisini vermiyor. Üretilen örnek belki küçük bir parametre farkıyla mükemmele ulaşacakken bütün örnek çöpe atılmış oluyor. Bu, genetik algoritmalardaki gibi çok sayıda iterasyonla, duvara çarpa çarpa doğru yolu bulmaya benzemiyor mu? **Cevap:** Evet, doğru. Burada kaba bir geri bildirim vardır ve tam bu sorun yüzünden GAN eğitimi oldukça dertli bir iştir. Rastgeleliğe çok fazla güvenen bir yaklaşımdır. Bir sürü yeni GAN mimarisi çıkıyor ama hocanın bildiği kadarıyla hiçbiri çok kararlı (stabil) bir eğitim sürecine sahip değil (hoca GAN konusunda uzman olmadığını belirtti). Daha önce GAN eğitmiş bir öğrenci de eğitimin çok zor olduğunu, uzun sürmesinin yanında asıl zorluğun parametre ayarı olduğunu ve kararlı bir eğitim olmadığını söyledi.

**Soru:** Ayırıcının da güncellendiğini görüyorum; bunun amacı tam olarak ne? **Cevap:** Ayırıcı başlangıçta bir kere oluşturulup bırakılmaz. O da öğrenmeye, daha iyi ayırmaya devam eder. Başlangıçta ayırıcının eğitim kümesi yoktur, sıfırdan başlar ve başta çok iyi çalışmayabilir. Zaman içinde kendini iyileştirir.

**Soru:** (Erken bir aşamada sorun çıkıp çıkmayacağı soruldu.) <!-- BELİRSİZ: sorunun tam metni altyazıdan net çıkmıyor (00:56:12-00:56:15) --> **Cevap:** Olabilir. Büyük olasılıkla bunu önlemek için ek mekanizmalar konuluyordur; örneğin başlangıçta küçük bir modelle eğitip oradan başlatılıyor olabilir. Ama ayırıcının eğitimi sürecin içinde devam eder.

Slaytın sonunda üretici modellerin başarısıyla ilgili bir slayt ("Başarı?") ve araştırma soruları vardı; hoca bunların üzerinde durmadı. <!-- BELİRSİZ: "Başarı?" slaytı ekranda açılmadı, yalnız küçük önizlemede göründü (ekrandan, 00:45:00); önizlemeden okunduğu kadarıyla yalnız üretilmiş örneklerden oluşan bir eğitim kümesiyle eğitilen modelin test başarısının, orijinal eğitim kümesiyle eğitilene yakın olmasını bir başarı ölçütü olarak öneriyor. -->

## 11. Proje Konuları

Aradan sonra dönem projesinin konuları anlatıldı (ekrandan, 01:15:00, 01:25:00 ve 01:35:00). Burada yalnız konuların akademik içeriği verilmiştir. Hoca, uygulamaya geçildiğinde açık olmayan noktalar çıkacağını ve kesin kararlar vermeden önce kendisine danışılmasını istedi.

### 11.1 Soft etiketli ağaçlar

Ekrandaki tanım: eğitilmiş bir ağacın ya da bir ensemble'ın çıktıları ile soft etiketler üretilir. Sonra bu etiketlerle ağaç ya da ensemble eğitilir. Bu süreç iteratif biçimde devam edebilir. Hedef, ensemble kadar başarılı tek bir ağaç ya da ensemble'dan daha başarılı bir ensemble üretmektir. 36 UCI veri kümesi ve 2 metin kümesi üzerinde çalışılacaktır.

Burada karar ağacı algoritmasının değiştirilmesi gerekir: çıkışlar soft etiket olduğunda information gain gibi bölme ölçütlerinin de buna göre değiştirilmesi gerekir. Karmaşık bir kodu değiştirmek zor olabileceğinden basit, anlaşılır bir karar ağacı kodunu alıp değiştirmek önerildi. Süreç, öğretmen-öğrenci modellerdeki gibi tekrarlanabilir: hard etiketlerle soft etiket üretilir, sonra soft etiketlerle yeniden soft etiketler üretilir.

**Soru:** Örneğin 10 ağaçtan oluşan bir ensemble'ın kararlarını doğrudan soft etiket olarak kullanabilir miyiz, yoksa ağaç algoritmasını değiştirmek şart mı? **Cevap:** Ensemble'ın çıkışı aslında soft bir haldedir; her örnek için kaç ağacın hangi sınıfı söylediği kullanılabilir (demokrasiyle birleştirmede yalnız en çok oyu alan kazanır). Dolayısıyla soft etiketleri üretmek için ağacın yapısını değiştirmeye gerek yoktur. Değiştirilmesi gereken kısım, soft etiketlerle eğitilebilen bir ağaç oluşturmaktır. Girdiler değişmez, orijinal verilerdir; değişen çıkışlardır.

**Soru:** Metin kümesi derken ne kastediliyor? **Cevap:** Girdisi metin olan veri kümeleri: metin sınıflandırma (text classification), duygu analizi (sentiment analysis) gibi.

### 11.2 Improved Space

Derste anlatılmış olan Improved Space'in Python'da gerçeklenmesi ve scikit-learn'deki algoritmalarla (RF, XGBoost vb.) 36 UCI veri kümesi ve 2 metin kümesi üzerinde karşılaştırılması istenir. Improved Space bir meta algoritma, yani başka algoritmaların üstünde çalışan bir algoritma olduğu için imp_xgboost ve imp_rf gibi sürümlerin de üretilmesi projenin parçasıdır. Hocanın MATLAB kodu vardır; Python mimarisine tam uymayabilir, ama temel mantık anlaşıldıktan sonra mevcut ensemble algoritmalarını değiştirerek gerçeklemenin çok zor olmayacağı söylendi.

### 11.3 Yapay örnek üretimi

SMOTE, SMOTE-IPF (SMOTE'un bir değişikliği) ve benzeri yöntemler kullanılacaktır. Yapay örnek sayısının ve yapay örnek üretim türünün etkileri YSA'lar üzerinde incelenecektir. Belki belli bir sayıya kadar üretmek iyileştirir, bir noktadan sonra kötüleştirir. Born Again Trees ve Model Compression'da görüldüğü gibi, yapay veri üretmenin farklı yaklaşımları çok farklı sonuçlar doğurabilir. Burada model sıkıştırma yoktur: orijinal veriyle eğitilen YSA ile, yapay verilerle büyütülmüş eğitim kümesiyle eğitilen YSA karşılaştırılır.

### 11.4 Online ağaçlar ile ensemble

Karar ağaçları anlatılırken online ağaçlardan söz edilmişti: başlangıçta eğitim verisinin tamamı elde yoktur, veriler yavaş yavaş gelir. Klasik karar ağacında kökün kararı bütün veri kümesiyle verilir; online ağaçlarda ise örneklere tek tek erişilir ve ağaç giderek değişir. Örneklerin veriliş sırası ağacı değiştirir.

Hazır bir online ağaç algoritması bulunursa kullanılabilir. Bulunamazsa normal bir karar ağacı algoritması değiştirilir. Hocanın önerdiği değişiklik: yeni gelen örnek ağaca verilir ve ağaç bir sınıf söyler. Söylenen sınıf örneğin sınıfıyla aynıysa ağaçta değişiklik gerekmez. Farklıysa ağaç değiştirilmelidir; en kolayı, örneğin düştüğü yaprağı bir karar düğümüne dönüştürüp o ana kadarki örnekleri bir tarafa, yeni örneği öbür tarafa ayırmaktır. Bütün örnekler bütün özellikleriyle, ama farklı sıralarla verildiğinde farklı ağaçlar oluşması beklenir. Bunlardan ensemble kurulup klasik ensemble'larla karşılaştırılır (36 UCI ve 2 metin kümesi).

### 11.5 YSA çözümlerini birleştirmek

Ekrandaki tanım: farklı ilk değerlerle üretilen YSA çözümleri arasında test başarısını düşürmeden yol bulmak, bu yollar üzerindeki noktaları kullanarak ensemble oluşturmak, sadece son noktalardan oluşturulan ensemble ile karşılaştırmak; farklı mimariler ve farklı problemler için (en az 5 model).

Örneğin farklı ilk değerlerden başlanıp eğitilmiş üç YSA olsun. Literatüre göre bu üç nokta arasında test başarısını düşürmeden yollar bulunabilir. Soru, yollar üzerindeki noktalardan kurulan ensemble'ın yalnız üç uç noktadan kurulandan daha başarılı olup olmadığıdır. "En az 5 model" beş farklı son değeri ifade eder. Veri kümesi olarak CIFAR-10 ya da CIFAR-100 kullanmak işi kolaylaştırabilir.

### 11.6 MCMC ile YSA hata-parametre yüzeyleri

Ekrandaki tanım: YSA yüzeylerinin MCMC ile keşfi; benzer performansa sahip parametre kümelerinin şekillerinin bulunması, farklı mimariler ve farklı problemler için (en az 5 model). Fikir verici örnek olarak hocanın sayfasındaki bir dağılım keşfi örneği gösterildi.

Bir YSA başlangıçtan alınıp sonuna kadar eğitilir ve başarılı hale getirilir. Sonra bu noktadan başlanarak MCMC ile etrafta gezilir. MCMC bir dağılımın içinde gezinir: benzer performanslı noktalar bir dağılım oluşturur ve amaç bu dağılımı MCMC ile ortaya çıkarmaktır. Asıl amaç bu noktaların şeklini görmektir; noktalar on binlerce boyutlu uzayda olduğu için PCA, t-SNE gibi algoritmalarla küçük boyuta indirmek gerekir. MCMC ile illa Gauss bir dağılımı keşfetmek gerekmez; herhangi bir dağılım keşfedilebilir. Benzer performanslı noktaların dağılımının Gauss olmayacağı zaten bellidir. Her nokta bir YSA'dır. Bu proje, YSA çözümlerini birleştirmek projesiyle bağlantılıdır.

**Soru:** Son noktadan başlayıp yakında rastgele bir nokta seçeceğiz, onun başarısını ölçeceğiz, başarı düşmüyorsa oraya gidip aynı işleme devam edeceğiz, değil mi? Modeli hiç eğitmeden rastgele bir noktadan başlasak olur mu? **Cevap:** Olmaz, büyük olasılıkla başarılı bölgeye erişilemez; ama denenebilir. Bu, genetik algoritmayla eğitmeye benzer.

**Soru:** Amaç eğitilmiş modelin etrafını görmek mi, yoksa uzayı genel olarak çıkarmak mı? **Cevap:** İkisi de. İlk adım, en başarılı modellerden birini bulup o noktadan başlayarak bir dağılım üretmektir. Sonra, farklı ilk değerlerden başlanarak erişilen farklı son noktalardan hareketle bunların bir yerlerde birleşip birleşmediği görülebilir.

### 11.7 YSA distill

Ekrandaki tanım: distill'de kullanılan farklı yöntemlerin karşılaştırılması, farklı mimariler ve farklı problemler için (en az 5 model). Saflaştırmada birçok yöntem kullanılır; bunların araştırılması ve birbirlerine göre iyi ve kötü yanlarının görülmesi istenir. Mimari, konvolüsyon içermeyen standart (dense) bir YSA olabilir; ardından konvolüsyonel yapılarda bu işlemin nasıl yapıldığı ve ne kadar işe yaradığı araştırılabilir.

### 11.8 Karar/regresyon ağaçlarının hata-parametre yüzeyleri

YSA'ların hata-parametre yüzeyleri görülmüştü. Bu projede karar ya da regresyon ağaçlarının hata-parametre yüzeylerinin nasıl oluştuğu incelenir. Bu kolay değildir: düğüm sayısı arttıkça uzay büyür. 10 düğümlü bir ağaç ile 100 düğümlü bir ağaç aynı hata-parametre uzayında gösterilemez; fonksiyonel uzaylarda ifade edilebilirler ama hata-parametre yüzeyleri uzayında edilemezler.

Bu yüzden ekrandaki tanımda yapı sabittir: özellik/eşik değerleri $[0:0.1:1]$ aralığında, sınıf sayısı/farklı çıkış sayısı 2. Tüm olası özellik-eşik-etiket/çıkış bileşimleri için test başarısının nasıl değiştiği incelenir. Ardından t-SNE ile 2 boyutta görselleştirilir. En az 5 yapay veri kümesi üzerinde çalışılır; gerçek veri kümesi gerekmez. Bu uzay sürekli değil ayrık olduğu için büyük olasılıkla dışbükey yüzeyler görülmeyecektir; hocaya göre ayrık bir uzayın görselleştirilmesi oldukça ilginç olacaktır.

### 11.9 Ensemble yörüngeleri

Bir YSA'nın $W_0$'dan $W_N$'ye kadar geçtiği noktalar birleştirildiğinde bir yörünge elde edilir. Aynı şekilde ensemble'lar için de bir yörünge tanımlanır. Bunun için uzayın boyutları tanımlanmalıdır: bir boyut kappa, diğeri ortalama tekil öğrenici hatasıdır. İki analiz yapılır:

- 1. Tam (full) ağaçlarla ensemble büyüklüğü arttıkça nasıl bir yörünge oluşuyor? Ensemble büyüklüğü 1 iken bir nokta, 3 iken başka bir nokta, 5 iken başka bir nokta elde edilir; bu noktaların kappa-tekil hata uzayında nasıl gezindiği incelenir.
- 2. Sabit ensemble büyüklüğünde (örneğin 10 ağaç), tekil öğrenicilere verilen minimum derinlik ya da düğüm sayısı arttıkça nasıl bir yörünge oluşuyor?

36 UCI ve 2 metin veri kümesi üzerinde çalışılacaktır.

## 12. Üçüncü Ödev Sunumlarından Akademik Noktalar

Dersin son bölümünde üçüncü ödevin sunumları yapıldı. Ödev, YSA hata-parametre yüzeyleriyle ilgiliydi ve üç kısımdan oluşuyordu: (a) bir eğitimin başlangıç ve bitiş ağırlıklarını birleştiren çizgi üzerindeki başarılar, çizginin iki yana uzatılmasıyla birlikte; (b) ağırlık yörüngelerinin t-SNE ile iki boyutta çizilmesi; (c) aynı mimaride farklı başlangıçlardan eğitilmiş modellerin son noktalarını birleştiren çizgiler. Sunumlar adsız olarak ve yalnız akademik noktalarıyla özetlenmiştir.

### 12.1 Birinci sunum: Digits, MNIST, CIFAR-10

Öğrenci Digits, MNIST ve CIFAR-10 kullandı ve her veri kümesi için beş farklı başlangıç noktası (Glorot ilklendirici) kullandı (ekrandan, 01:45:00). Ekranda CIFAR-10 için kullanılan ağın katmanları görünüyordu: `imageInputLayer([32 32 3])`, `convolution2dLayer(5,32,'WeightsInitializer','glorot')`, `reluLayer`, `maxPooling2dLayer(2,'Stride',2)`, `convolution2dLayer(3,64,'padding','same')`, `reluLayer`, `fullyConnectedLayer(10,'WeightsInitializer','glorot')`, `reluLayer`, `dropoutLayer(0.5)`, `fullyConnectedLayer(10)`, `softmaxLayer`, `classificationLayer`.

- (a) kısmında Digits'te %90'ın üzerine çıkıldı. MNIST ve CIFAR'da başlangıç noktasının sonuca çok etkili olduğu, büyük dalgalanmalar olduğu gözlendi.
- (b) kısmında t-SNE yörüngelerinden birinin (sarı) çok büyük sıçramalar yaptığı ve yakınsamadığı görüldü. Öğrenci bunu başlangıç noktasının öğrenme oranını etkilemesine bağladı.

> **Hocanın vurgusu:** Başlangıç noktası öğrenme oranını değiştirmez, atılan adımın büyüklüğünü değiştirir. Öğrenme oranı en başta sabit verilir; bulunulan yerde gradyan büyükse büyük adımlar atılır.

Hoca sıçrayan yörüngenin başarısını sordu; öğrenci düşük olduğunu söyledi. Hoca da bir yerden bir yere sıçramanın yakınsayamamak anlamına geldiğini ve başarısının düşük olmasını beklediğini belirtti.

CIFAR-10'un t-SNE grafiğinde öğrenci yörüngelerin ortadaki bir minimuma doğru yaklaştığını düşündü. Hoca tersinin de olabileceğini söyledi: ilk ağırlıklar sıfır çevresinde rastgele dağılmış küçük değerler olduğu için başlangıçların birbirine yakın olması çok daha olasıdır. Bu durumda yörüngeler ortadan başlayıp birbirinden uzaklaşıyor olabilir. Başlangıç ve bitiş grafikte işaretlenmediği için bunu söylemek mümkün değildir.

(c) kısmında CIFAR-10'da birleştirilen son noktaların test başarıları çok düşüktü (yaklaşık %25-35). Hoca, modeller henüz öğrenmediği için aralarında ilişki kurmanın güç olduğunu söyledi. Epoch'lar ilerledikçe aradaki vadi derinleşir, çünkü iki model birden iyileşir; burada modeller o noktaya varamamıştır. Bunun büyük olasılıkla epoch sayısıyla değil mimariyle ilgili olduğunu, CIFAR-10 için daha büyük mimarilerle denemek gerektiğini belirtti. 10 sınıflı problemde rastgele tahminle tutturma olasılığının zaten %10 olduğunu da hatırlattı.

Öğrenci, t-SNE'nin büyük katmanlarda çok fazla bellek gerektirdiğini, bu yüzden bazı mimarilerde yalnız ikinci katmanı çizebildiğini; MATLAB'da `ExecutionEnvironment` seçeneğini `auto` yaparak eğitimi GPU ya da bütün işlemci çekirdekleriyle hızlandırdığını aktardı.

### 12.2 İkinci sunum: Soybean, Splice, Waveform

Tek gizli katmanlı (64 nöron) bir model kullanıldı (ekrandan, 02:05:00). (a) kısmında $V_0$ ile son nokta arası 10 parçaya bölündü ve eğitim hataları çizildi.

> **Hocanın vurgusu:** "Bu çok önemli bir şey söylüyor, herkese söylüyorum": $V_0$'dan başlayıp son noktaya giderken gerçekte izlenen yol üzerinde dalgalanmalar vardır, başarı bazen kötüleşir. Ama $V_0$ ile $V_{10}$'u birleştiren düz çizgi üzerinde böyle bir şey görülmez.

Hoca ardından $V_0$ ile $V_{10}$ arasında bir lokal minimumun aşılıp aşılmadığını sordu (bkz. Örnek Sorular). Waveform grafiklerinde bazı modellerin başlangıç ve bitiş hatalarının neredeyse aynı (örneğin ikisinin de yaklaşık %10) olduğu görüldü. Hoca bunun ağın aslında eğitilmediği anlamına geldiğini, öğrencinin bir suçu olmadığını, veri kümesinin kendisinin zor olabileceğini söyledi. Başka bir öğrenci de Waveform'da aynı sonucu aldığını belirtti; bir öğrenci de ilk epoch'ta %90 civarına çıkılıp sonra öyle devam edildiğini gözlemledi. Yine de bazı eğrilerde (örneğin hatası yaklaşık %16'dan %11'e düşen ve arada daha da aşağı inen bir eğride) arada bir lokal minimum bulunduğu söylenebildi.

Bu grupta (c) kısmı yanlış anlaşılmıştı: bir modelin başlangıcı ile başka bir modelin son noktası birleştirilmişti. Hoca istenenin iki modelin son noktalarını birleştirmek olduğunu belirtti. Grup, farklı başlangıçlı noktalar alındığında lokal minimum ya da maksimum görülme olasılığının daha fazla, aynı modelin noktalarında daha az olduğunu gözlemledi.

### 12.3 Üçüncü sunum: MNIST, Fashion MNIST, CIFAR-10 ve ilklendiriciler

Öğrenci beş başlangıç noktasını farklı Keras ilklendiricileriyle oluşturdu (ekrandan, 02:15:00). Ekrandaki raporda ilklendiriciler şöyle tanımlanıyordu:

- `initializers.RandomNormal()`: normal dağılımlı rastgele tensörler oluşturur.
- `initializers.he_uniform()`: $[-\text{limit}, \text{limit}]$ aralığında tekdüze; $\text{limit} = \sqrt{6/\text{fan\_in}}$, fan_in ağırlık tensörüne gelen girdi sayısı.
- `initializers.he_normal()`: 0 merkezli, $\text{stddev} = \sqrt{2/\text{fan\_in}}$ olan normal dağılım.
- `initializers.glorot_uniform()`: $[-\text{limit}, \text{limit}]$ aralığında tekdüze; $\text{limit} = \sqrt{6/(\text{fan\_in}+\text{fan\_out})}$, fan_out çıktı sayısı.

CIFAR-10 için 22 katmanlı bir mimariyle 200 epoch sonunda testte yaklaşık %85 doğruluğa ulaşıldı.

Hoca grafiklerde başlangıç başarısının çok yüksek olduğunu fark etti:

> **Hocanın vurgusu:** $V_0$ rastgele bir başlangıçtır, yani hiç eğitilmemiş bir ağdır. 10 sınıflı bir problemde başarısı yaklaşık %10, yani 0.1 civarında olmalıdır. Rastgele bir başlangıç %90 küsur başarıya erişemez; bu grafik aslında 1. epoch sonundan ($V_1$) başlıyordur.

**Soru:** İlklendirme tam rastgele değil de bir ölçüde yönlendirilmiş (guided) rastgele olduğu için ilk ağırlıkların başarısı yüksek olabilir mi? **Cevap:** Etkisi olur ama bu kadar olmaz; rastgele bir başlangıç büyük olasılıkla %90 küsur başarıya erişemez.

Hoca, $V_1$ ile son nokta arasında bile başarının %100'den %80'e kadar düzgün (smooth) biçimde düştüğüne, %10'a inmediğine dikkat çekti. Öğrenci, Fashion MNIST'te mimariden bağımsız olarak testte yaklaşık %95'in üzerine çıkılamadığını ve eğitim ile test arasında hafif bir aşırı öğrenme gördüğünü aktardı.

### 12.4 Dördüncü sunum: Fashion MNIST, iki sınıflı bir veri kümesi ve Letter

Fashion MNIST için 32, 16 ve 8 nöronlu, ReLU aktivasyonlu üç gizli katman ve 15 epoch kullanıldı (ekrandan, 02:25:00). Başlangıç ağırlıkları ile 15. epoch sonundaki ağırlıkları birleştiren doğru 10 eşit aralıkla çizildi ve son modelden sonra 5 adım daha uzatıldı.

> **Ders sonrası not:** Sunumda Fashion MNIST için "6.000 eğitim örneği ve 10.000 sınıf" dendi; ekrandaki rapora göre doğrusu 60.000 eğitim, 10.000 validasyon örneği ve 10 sınıftır.

İki sınıflı veri kümesinde başlangıç başarılarının %50 civarında olduğu görüldü. Hoca, iki sınıflı ve büyük olasılıkla dengeli bir veri kümesinde rastgele tahminle tutturma olasılığı zaten %50 olduğu için bunun normal olduğunu, yüksek bir yerden başlanmadığını belirtti. Yörüngelerde bütün katmanların ağırlıkları uç uca eklenerek tek bir büyük vektör oluşturulmuş ve t-SNE ile görselleştirilmişti; yörüngeler benzer bir yerden başlayıp birbirinden uzaklaşıyordu. Son noktalar birleştirildiğinde bazı çiftlerin arasındaki yolda başka bir minimum bulunduğu gözlendi. Öğrencinin yorumu: bu grafikler uzayın ne kadar engebeli olduğuna, nerelerin yüksek nerelerin alçak olduğuna dair fikir verir.

### 12.5 Beşinci sunum: Soybean, Vehicle, Waveform

Kullanılan veri kümeleri ekrandaki tabloda şöyle özetlenmişti (ekrandan, 02:30:00):

| Veri Kümesi | Örnek Sayısı | Özellik Sayısı | Sınıf Sayısı | Epoch |
|---|---|---|---|---|
| soybean | 675 | 84 | 18 | 200 |
| vehicle | 846 | 19 | 4 | 300 |
| waveform | 5000 | 41 | 3 | 300 |

Öğrenci, başlangıç ($W_0$) ve bitiş ($W_T$) noktalarını birleştiren doğru üzerindeki noktaları bir ağırlıklandırma olarak yorumladı: $[0,1]$ aralığında iki noktanın dışbükey (konveks) birleşimi alınır; bir yandaki uzantıda $W_0$ birden büyük, $W_T$ negatif katsayıyla, öbür yandaki uzantıda tersi biçimde ağırlıklandırılır.

> **Ek bilgi (derste anlatılmadı):** Bu doğru $W(\alpha) = (1-\alpha)\,W_0 + \alpha\,W_T$ biçiminde yazılabilir. $0 \le \alpha \le 1$ iken nokta iki uç arasındadır; $\alpha > 1$ iken $W_T$'nin katsayısı birden büyük, $W_0$'ınki negatiftir; $\alpha < 0$ iken bunun tersi olur.

Soybean'de yörüngelerin daha doğrusal, Vehicle ve Waveform'da daha eğrisel olduğu görüldü. Doğrusal yörüngelerde başlangıç ile bitişi birleştiren doğru üzerindeki noktalar yaklaşık olarak epoch noktalarının üzerine düşer; bu durumda doğru üzerinde hatanın sürekli azalması, eğrisel yörüngelerde ise tepeler ve zikzaklar görülmesi beklenir. A kısmının grafikleri bu beklentiyle uyumlu çıktı.

t-SNE'de son noktaları çok yakın görünen iki model arasında sığ bir vadi beklenirken, tersine diğer çiftlerden daha derin bir vadi gözlendi. Hoca bunu iki boyuta indirgemenin yanıltıcılığıyla açıkladı: iki boyutta birbirine çok yakın görünen noktalar gerçekte yakın olmayabilir. Bir nesneye bir açıdan bakıldığında iki nokta yakın, başka bir açıdan uzak görünür; bu yalnızca üç boyuttan ikiye inerken bile böyledir, binlerce boyutta çok daha büyük farklar oluşabilir.

Öğrenci ayrıca aynı model için 50., 100. ve 200. epoch'lar alındığında aradaki vadinin giderek derinleştiğini (beklentiyle uyumlu), Vehicle'da bir çiftin doğru boyunca uzatılmasıyla testte daha iyi bir nokta bulunabildiğini gözlemledi. Waveform'da bir çiftte ise epoch arttıkça vadinin derinleşmesi yerine tersi görüldü.

### 12.6 Altıncı sunum: MNIST, Fashion MNIST, CIFAR-10 (grup çalışması)

Grup, MNIST'te başarı %99'a kadar çıktığı için kayıp her yerde düşük görünüyor ve farklar seçilemiyordu; bu yüzden MNIST'i Digits'e benzer biçimde 4000 eğitim ve 1000 test örneğine indirerek problemi zorlaştırdı. Ağırlıklar Keras'ın varsayılan ilklendiricisiyle oluşturuldu ve her çalıştırmada farklı rastgele başlangıç elde edildi.

Yaklaşık 54 bin ağırlık içeren modelin bütün ağırlıkları t-SNE'ye verildiğinde (20 epoch, yani 20 nokta) karışık sonuçlar çıktı. Grup, çok yüksek boyutlu bir yapıyı çok az noktayla temsil etmeye çalışmanın buna yol açtığını düşündü; PCA'nın da anlamlı bir şey göstermediğini belirtti. Hoca da iki boyuta indirgemenin başlı başına büyük bir problem olduğunu söyledi: elimizde PCA ve t-SNE olduğu için bunları kullanıyoruz, ama ne kadar etkili oldukları tartışmalıdır; çok yüksek boyutlu bir uzaydaki şekli iki boyutta görmeye çalışıyoruz (ekrandan, 02:50:00, CIFAR-10 için üç başlangıcın birlikte t-SNE'ye verildiği yörünge grafiği).

(c) kısmında CIFAR-10'da iki farklı son nokta arasındaki düz çizgi üzerinde de hatanın sıfıra yakın çıktığı görüldü. Grup bunu, birinci ödevdeki Griewank gibi test fonksiyonlarına benzer biçimde iki optimum arasında büyük bir mesafe olmamasına bağladı. Hoca bunun beklenenden farklı olduğunu (diğer sunumlarda vadiler görülmüştü), yorumlamanın güç olduğunu söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:17:54): Bir karar ağacında kök düğümde hangi özellik ve hangi eşik değerinin seçileceğine karar verirken örneklerin hangilerine bakılır? Bir alt seviyede ve yapraklara yakın düğümlerde durum nedir?

> **Çözüm (derste verildi):** Kökün kararı bütün örnekler kullanılarak verilir. Bir alt seviyede veri kökteki karara göre bölündüğü için ortalama yarısı kullanılır. Yapraklara yaklaştıkça çok az sayıda örnekle (örneğin 1000 örnekten 5-6'sıyla) karar verilir. Verinin boyutu ise azalmadığı için yüksek boyutlu uzaylarda bu kararların varyansı çok yüksektir. Born Again Trees'in yapay veriyi her düğümde üretmesinin nedeni budur.

**Soru 2** (derste sözlü, 00:46:44): Bir GAN'da üretici, gerçek örnekleri alıp hiç değiştirmeden "ben ürettim" diye verirse ne olur? Bu nasıl engellenir?

> **Çözüm (derste verildi):** Gerçek ve "üretilmiş" örnekler aynı olur ve ayırıcı onları ayırt edemez; sistem başarılı görünür ama hiçbir şey öğrenilmemiştir. Bunu engellemek için üreticinin girdisi yalnızca rastgele bir vektördür (gürültü); üretici bir örneği değiştirerek değil, rastgele vektörü verinin manifolduna eşleyerek üretim yapar.

**Soru 3** (derste sözlü, 02:03:28): Bir ağın gerçek eğitim yolunda ($V_0 \to V_{10}$) başarı dalgalanıyor ve bazen kötüleşiyor; ama $V_0$ ile $V_{10}$'u birleştiren düz çizgi üzerinde böyle bir dalgalanma görülmüyor. Bu bize ne söyler? $V_0$ ile $V_{10}$ arasında bir lokal minimum aşılıyor mu? <!-- BELİRSİZ: hocanın beklediği cevap derste açıkça söylenmedi; sunum yapan öğrencinin cevabı başka grafiklere kaydı -->

> **Çözüm (derste verilmedi):** Düz çizgi üzerinde başarı düzgün biçimde değişiyorsa, iki uç arasında doğrusal yol boyunca bir engel, yani aşılması gereken bir lokal minimum ya da tepe yoktur. Gerçek eğitim yolundaki dalgalanmalar büyük olasılıkla optimizasyonun (adım büyüklüğü ve stokastik gradyan gibi) kendisinden kaynaklanır, yüzeydeki engellerden değil. Bu, önceki derste görülen "lokal minimumlar birbirine bağlıdır" bulgusuyla da uyumludur.

**Soru 4** (derste sözlü, 02:17:35): 10 sınıflı bir problemde, hiç eğitilmemiş rastgele başlatılmış bir ağın ($V_0$) başarısı yaklaşık ne olmalıdır? İki sınıflı dengeli bir problemde ne olmalıdır?

> **Çözüm (derste verildi):** Rastgele tahminle tutturma olasılığı kadar: 10 sınıfta yaklaşık %10 (0.1), iki sınıflı dengeli problemde yaklaşık %50. Grafikte başlangıç başarısı %90'ın üzerindeyse, eğri aslında 1. epoch sonundan ($V_1$) başlıyordur.

**Soru 5** (derste sözlü, 01:46:43): Bir t-SNE yörüngesinde bir model çok büyük sıçramalar yapıyor. Bu, başlangıç noktasının öğrenme oranını değiştirdiğini mi gösterir?

> **Çözüm (derste verildi):** Hayır. Öğrenme oranı en başta sabit verilir. Başlangıç noktası, oradaki gradyanın büyüklüğü yoluyla atılan adımın büyüklüğünü değiştirir. Sürekli sıçrayan bir yörünge yakınsayamamak demektir ve bu modelin başarısının düşük olması beklenir.

**Soru 6** (derste sözlü, 01:53:36): CIFAR-10'da farklı başlangıçlardan eğitilmiş modellerin son noktaları birleştirildiğinde çizgi üzerinde anlamlı bir vadi yapısı görülmüyor ve uçların test başarıları %25-35 civarında. Neden?

> **Çözüm (derste verildi):** Modeller henüz öğrenmemiştir; bu yüzden aralarında ilişki kurmak güçtür. Vadinin derinleşmesi iki modelin birlikte iyileşmesiyle görülür. Sorun büyük olasılıkla epoch sayısıyla değil mimariyle ilgilidir; daha büyük mimarilerle denemek gerekir.

## Dersin Toparlaması

Bu derste yapay sinir ağlarında kollektif öğrenme konusu tamamlandı. Önce önceki haftanın bulguları, yani bağımsız eğitimler arasındaki vadilerin epoch ilerledikçe derinleşmesi ve ağırlık uzayında çizgi boyunca gradyansız ilerleme fikri hatırlatıldı. Ardından öğretmen-öğrenci modeller ele alındı: Born Again Trees ve Model Compression'da ensemble'lar, yapay olarak üretilmiş verilerin etiketleyicisi olarak kullanılıp tek bir modele aktarıldı. Hinton ve arkadaşlarının 2015 çalışmasında aynı fikir sıcaklıklı softmax ile üretilen soft target'larla genelleştirildi. DistilBERT bunun büyük dil modellerine uygulamasını, Born-Again Neural Networks ise eş kapasiteli öğrencilerle öğretmeni geçme ve öğrencilerden ensemble kurma fikrini gösterdi. Son olarak iki modelin çekişmesine dayanan GAN'lar ve verinin yüksek boyutlu uzayda bir manifold üzerinde durması fikri anlatıldı.

Dersin ikinci yarısındaki proje konuları bu dönemde görülen fikirlerin (soft etiketler, yapay veri, online ağaçlar, YSA çözümleri arasındaki yollar, hata-parametre yüzeyleri, ensemble yörüngeleri) uygulamalı uzantılarıdır. Üçüncü ödev sunumları ise hata-parametre yüzeylerini incelerken dikkat edilecek noktaları ortaya koydu: eğitilmemiş ağın başarısı şans düzeyindedir, başlangıç noktası öğrenme oranını değil adım büyüklüğünü etkiler, ve t-SNE/PCA ile iki boyuta indirgemede görülen yakınlıklar yanıltıcı olabilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
