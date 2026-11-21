# Ders 2 Genişletilmiş Notu: XOR Problemi, Hebb ve Perseptron Öğrenme Kuralları, Adaline ve Madaline

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. XOR Problemi ve Doğrusallık
- 2. Ağırlıkların Analitik Olarak Bulunması: AND ve XOR
- 3. Çok Katmanlı Ağlar ve Ağ Topolojileri
- 4. Hebb Öğrenme Kuralı
- 5. Durma Koşulu
- 6. Perseptron Öğrenme Kuralı
- 7. Epok Kavramı
- 8. Perseptron ile AND: Binary Giriş, Bipolar Çıkış
- 9. Bipolar Giriş ile Daha Hızlı Yakınsama
- 10. Karakter Tanıma Problemi
- 11. Hebb ve Perseptron Karşılaştırması
- 12. Adaline ve Delta Kuralı
- 13. Delta Kuralının Türevden Elde Edilmesi
- 14. Madaline ve XOR
- Örnek Sorular

## 1. XOR Problemi ve Doğrusallık

Hoca derse bir önceki derste sorduğu soruyla başladı: McCulloch-Pitts nöronları ve tek katmanlı perseptronla neler çözülebilir? Bu modeller mantık kapılarını gerçekleyebildiği için, ortaya atıldıkları dönemde elektroniğin başlangıç aşaması düşünülünce çok değerliydi. Bazı kapı fonksiyonlarını yapay sinir ağlarıyla gerçeklemek bugün de bazı elektronik uygulamaları hızlandırabiliyor. Fakat perseptronun önce popüler olup sonra gözden düşmesine yol açan olay, diğer bütün kapılar gerçeklenebilirken XOR kapısının gerçeklenememesi oldu.

XOR'u diğerlerinden ayıran şey doğrusal olmayan (non-linear) bir problem olmasıdır. Hoca doğrusallığı iki açıdan tanımladı:

- **Geometrik açıdan:** Çıktıları farklı olan örnekleri bir doğru ya da düzlemle, yani doğrusal bir fonksiyonla birbirinden ayırabiliyorsak problem doğrusaldır.
- **Cebirsel açıdan:** Doğrusal bir denklem seti kurup bilinmeyen parametreleri çözebiliyorsak problem doğrusaldır. Elimizdeki denklemler doğrusal bir set kurup bilinmeyenleri bulmaya yetmiyorsa problem doğrusal değildir.

Hoca burada bir yanılgıya dikkat çekti: Doğru gibi görünen her şey doğrusal, geri kalanı doğrusal değildir diyemeyiz. Bir parabol bize eğri görünür, ama parabol denklemiyle ifade edilebilen bir problem için bir denklem seti kurulup doğrusal yöntemlerle çözülebilir. Bu anlamda o problem doğrusaldır.

Slaytta bu bölümün sorusu şöyle kondu: Ne kadar süreyle çözüm aramaya devam edeceğiz? Deneme yanılmayla çözüm aramak yerine uygun parametreleri hesaplamamız gerekir. Her eğitim örneği, girişler ve ağ parametreleri açısından çıktı için doğrusal bir eşitsizlik üretir ve bu eşitsizlikler ağırlıkları ve eşikleri hesaplamak için kullanılabilir (ekrandan, 00:05:00).

> **Hocanın vurgusu:** Tek katmanlı perseptronla çözülebilecek problemler yalnız doğrusal problemlerdir; doğrusal olmayan hiçbir problemi çözemez. Bu kısıt, yapay sinir ağlarının bir dönem duraklamaya girmesinin sebeplerinden biridir.

## 2. Ağırlıkların Analitik Olarak Bulunması: AND ve XOR

### 2.1 AND kapısı

İki girişli AND kapısında iki giriş ve bir çıkış vardır, dolayısıyla dört farklı örnek oluşturulabilir. Nöronun nasıl çalıştığı bellidir: girişleri bağlantı ağırlıklarıyla çarpıp toplar, sonra bir eşik uygulayarak çıkış üretir. Bu bir denklemdir; dört örneğin değerleri yerine konunca dört eşitsizlik elde edilir. Slayttaki kurulum (ekrandan, 00:15:00):

$$\text{out} = \text{sgn}(w_1 in_1 + w_2 in_2 - \theta)$$

| $in_1$ | $in_2$ | out | Eşitsizlik | Sadeleşmiş hali |
|---|---|---|---|---|
| 0 | 0 | 0 | $w_1 \cdot 0 + w_2 \cdot 0 - \theta < 0$ | $\theta > 0$ |
| 0 | 1 | 0 | $w_1 \cdot 0 + w_2 \cdot 1 - \theta < 0$ | $w_2 < \theta$ |
| 1 | 0 | 0 | $w_1 \cdot 1 + w_2 \cdot 0 - \theta < 0$ | $w_1 < \theta$ |
| 1 | 1 | 1 | $w_1 \cdot 1 + w_2 \cdot 1 - \theta \ge 0$ | $w_1 + w_2 \ge \theta$ |

Yapay sinir ağında asıl amaç, örnekleri bildiğimiz hâlde bilmediğimiz bağlantı ağırlıklarını doğru ayarlamaktır. Ağırlıkları, örneklerin mümkün olduğunca çoğu için doğru çıktıyı üretecek şekilde bulduğumuzda ağın öğrendiğini varsayarız. Burada bilinmeyenler $w_1$ ve $w_2$'dir. İki bilinmeyen için dört denklem vardır; problem doğrusal ise iki denklem bile yeterli olmalıdır.

Hoca önceki dersteki gibi $\theta = 2$ seçti. Birinci koşul sağlanır. $w_2 < 2$ için $w_2 = 1$, $w_1 < 2$ için $w_1 = 1$ seçilebilir. Son koşul: $1 + 1 \ge 2$ sağlanır. Demek ki bu eşitsizlik setinin çözümü vardır; hatta birden fazla çözüm vardır. Örneğin $\theta = 3$ seçip ağırlıklardan birini 2 yapmak da sistemi çözer. Bu nedenle AND, perseptronun çözebileceği bir problemdir.

**Soru:** Eşitsizlikleri yazarken neden bazıları $<$, bazıları $\ge$? **Cevap:** Bu problemde çok önemli değil. Ayırma çizgisi belirlenirken eşitsizliklerin hepsi eşitliğe çevrilecek. $\ge$ kullanmak, ağırlığın eşiğe eşit olma durumunu da dışlamamak içindir. Burada önemli olan $\theta$'nın sıfırdan büyük olmasıdır; $\theta = 0$ seçilirse zaten son eşitsizlik sağlanamaz.

### 2.2 XOR kapısı

Aynı işlem XOR için yapılınca (ekrandan, 00:20:00):

| $in_1$ | $in_2$ | out | Eşitsizlik | Sadeleşmiş hali |
|---|---|---|---|---|
| 0 | 0 | 0 | $w_1 \cdot 0 + w_2 \cdot 0 - \theta < 0$ | $\theta > 0$ |
| 0 | 1 | 1 | $w_1 \cdot 0 + w_2 \cdot 1 - \theta \ge 0$ | $w_2 \ge \theta$ (2) |
| 1 | 0 | 1 | $w_1 \cdot 1 + w_2 \cdot 0 - \theta \ge 0$ | $w_1 \ge \theta$ (3) |
| 1 | 1 | 0 | $w_1 \cdot 1 + w_2 \cdot 1 - \theta < 0$ | $w_1 + w_2 < \theta$ (4) |

$\theta > 0$ iken 2. ve 3. koşulu sağlamak için iki ağırlığın da en az $\theta$ olması gerekir. O zaman toplamları en az $2\theta$ olur ve $\theta$'dan küçük olamaz. Slayttaki ifadeyle 2. ve 3. eşitsizlikler 4. ile uyuşmaz, bu nedenle hiçbir çözüm yoktur. Daha karmaşık ağlara ihtiyaç vardır: birçok basit ağı bir araya getiren ya da farklı aktivasyon, eşik veya aktarma fonksiyonları kullanan çözümler.

Hoca "perseptronla çözülemez" demesinin sebebini de açıkladı: Bu eşitsizlikler perseptronun denkleminden kuruldu. Başka bir yapı kullanılsaydı belki çözülebilecekti. Yalnız perseptronla sınırlarsak, bu matematiksel ispattan sonra XOR'un perseptronla çözülemeyeceği kesin olarak söylenebilir.

## 3. Çok Katmanlı Ağlar ve Ağ Topolojileri

Tek katmanla çözülemeyen bir problem için en doğal fikir, iki katman kullanmaktır. Matematiksel açıdan bakınca, aynı denklemi bir kez daha aynı denkleme koymak denklemi karmaşıklaştırır ve daha karmaşık, doğrusal olmayan ilişkileri ifade edebilir hâle getirir. Böylece çok katmanlı yapay sinir ağı mimarisi ortaya çıkar.

Slaytta üç topoloji gösterildi (ekrandan, 00:25:00):

- **Tek katmanlı ileri beslemeli (single layer feed-forward):** Tek katmanlı perseptron.
- **Çok katmanlı ileri beslemeli (multi-layer feed-forward):** Çok katmanlı perseptron; girişle çıkış arasında en az bir ek katman vardır.
- **Geri beslemeli ağ (recurrent network):** Basit recurrent ağ; gizli nöronun çıkışı kendisine geri bağlanır.

> **Hocanın vurgusu:** Katman sayısında farklı notasyonlar görülebilir. Girişi bir katman sayıyorsanız çıkışı saymamalısınız. Perseptronda bir giriş, bir çıkış vardır ama ona tek katmanlı denir. Giriş, bir ara katman ve çıkıştan oluşan ağ 3 değil 2 katmanlıdır; 3 katmanlı ağ için araya bir katman daha eklemek gerekir.

**İleri beslemeli** (feed-forward) sözü mimari olarak girişlerin ara katmanlara ve çıkışa tek yönde gittiğini anlatır. Hesaplama açısından da hesaplar hep ileri doğru yapılır: giriş alınır, işlenir, sonraki katmana aktarılır.

Diğer ana mimari **recurrent** (geri beslemeli) ağlardır. Bu ağların bir tür hafıza özelliği vardır. Birinci örnek ağa verilip hesap ileri doğru yapıldığında ara katmandaki bir nöronda kalan değer saklanır. İkinci örnek işlenirken bu değer de hesaba eklenir. Hoca "ekleme" sözünün her zaman toplama anlamına gelmediğini, saklanan değerle farklı işlemler yapıldığını ve bunların ileride görüleceğini belirtti. Yani ağ ikinci örneğe "senden önceki örnekte elimdeki bilgi buydu" der. Derin öğrenmede kullanılan LSTM (long short-term memory) kavramı da buradan gelir.

Recurrent ağı gerektiren problemler, sonucun geçmişe bağlı olduğu problemlerdir:

- **Zamana bağlı değişen veriler (zaman serileri):** Nüfusun 10 yılda bir %10 arttığını biliyorsak, 10 yıl sonraki nüfusu bulmak için başlangıç noktasını, yani en azından bir adım öncesini bilmemiz gerekir. "Nüfus her on yılda %10 artıyor" diyebilmek için de geçmişteki birçok on yılı bilmek gerekir. Neyin ne kadar hatırlanacağı, tahmin edilmek istenen şeye göre değişir.
- **Art arda gelen görüntüler:** Video kareleri gibi sıralı veriler.
- **Geçmişe bağlı olay tahmini:** Örneğin bir araba kazası gibi olabilecek bir olayı öncesinde ne olduğuna bakarak tahmin etmek.

LSTM gibi gelişmiş yapılar hatırlanacak bilginin miktarını da ayarlar: önümüzde gelecek yüz ya da bin örneğin hepsine geçmiş bilgiyi yansıtmak gerekir mi, ne kadar süre hatırlamak gerekir? Bu, kapıya benzer bir mekanizmayla ayarlanır ve ileride ayrıntılı işlenecektir.

## 4. Hebb Öğrenme Kuralı

Öğrenme kuralı, algoritmada ağırlıkların nasıl ayarlanacağını söyleyen kuraldır. Perseptrona kadar belirli bir öğrenme kuralı yoktu. İlk öğrenme kuralı 1949'da bir nöropsikolog olan Donald Hebb'den gelir. Hebb, biyolojik nöronlarda gözlemlediği bir şeyin yapay sinir ağlarına uygulanabileceğini düşündü (ekrandan, 00:30:00).

Slayttaki ifadesiyle kural: Bir sinapsın iki tarafındaki iki nöron aynı anda (eşzamanlı) aktive oluyorsa o sinapsın gücü seçici olarak artırılır. Tersine, bağlı iki nörondan biri tetiklendiğinde diğeri tetiklenmiyorsa aralarındaki bağın ağırlığı zayıflatılır; böylece tesadüfi çakışmalar bağlantı gücü biriktirmez.

> **Ders sonrası not:** Slaytta tamamlayıcı kural "activated synchronously ... weakened" diye yazılmış. Hocanın sözlü anlatımına göre de büyük olasılıkla doğrusu "asynchronously" (eşzamansız aktive olan nöronlar arasındaki bağ zayıflatılır) olmalıdır.

Kural temelde mantıklıdır ve öğrenme kuralı olmaya uygundur. Fakat öğrenme, her örnekle ağırlıkları yeniden ayarlamayı gerektiren bir süreçtir. Her tetiklenmede ağırlık bir daha artırılırsa, birkaç tetiklenmeden sonra ağırlık o kadar büyüyebilir ki o bağı zayıflatma şansı kalmaz. Kazayla iki örnek art arda bağlantıyı güçlendirecek şekilde gelmişse, diğer örnekler tersini söylese bile ağırlığı geri düşürmek zorlaşır ve öğrenme oluşmaz. Ağırlıklar sınırsız artabilir.

Hoca bunu bir benzetmeyle anlattı: Kırmızıyı gördüğümde aklıma elma geliyorsa giriş kırmızı, çıkış elmadır. İki kez kırmızı görüp elmayı hatırladıysam aralarındaki bağlantıyı güçlendiririm. Ama bu bağlantı sınırsız güçlenirse elmayla hiç ilgisi olmayan bir sahnede de her kırmızıda elmayı hatırlamaya başlarım. Aynı şekilde sınırsız zayıflatmak da yanlıştır: Kırmızı bana iki kez elmayı hatırlatmadı diye bir daha hiç hatırlatmayacak değildir. Uygun örnekte uygun tahmin için bağlantı ağırlıkları daha kontrollü ayarlanabilmelidir.

### 4.1 Hebb algoritması

Slayttaki adımlar (ekrandan, 00:35:00):

1. Adım 0: Bütün ağırlıkları başlat. Basitlik için ağırlıklar ve bias sıfır yapılır.
2. Adım 1: Her eğitim vektörü için 2-4. adımları uygula.
3. Adım 2: Giriş birimlerinin aktivasyonlarını ayarla: $x_i = s_i$.
4. Adım 3: Çıkış biriminin aktivasyonunu ayarla: $y = t$.
5. Adım 4: Ağırlıkları ve bias'ı güncelle:

$$w_i(\text{yeni}) = w_i(\text{eski}) + y\,x_i, \qquad b(\text{yeni}) = b(\text{eski}) + y$$

Başlangıç adımı bütün klasik öğrenme algoritmalarında ortaktır. Ağırlıklar için uygun bir değer aranır ve bunun bir başlangıç değeri olmalıdır. Problemin çözümü bilinmediği için (bilinseydi yapay sinir ağına gerek kalmazdı) en mantıklısı ağırlıkları sıfırlamak ya da rastgele başlatmaktır.

Güncelleme, sözlü kuralın matematiksel karşılığıdır. $y$ ve $x$ ikisi de pozitifse çarpım pozitiftir ve ağırlık artar. Biri pozitif, diğeri negatifse çarpım negatiftir ve ağırlık azalır. İkisi de negatifse, yani ikisi birlikte aktive olmuyorsa, çarpım yine pozitiftir ve bağlantı güçlenir.

Hebb kuralının bir özelliği daha vardır: Tek iterasyon çalışır. Elde dört örnek varsa dört örneğe de kural bir kez uygulanır ve algoritma biter. Sonraki göreceğimiz kuralların çoğu iteratiftir; aynı örnekler tekrar tekrar gösterilir.

## 5. Durma Koşulu

İteratif öğrenme algoritmalarında örnekler bir durma koşulu sağlanana kadar tekrar gösterilir. Bu nedenle öğrenme algoritmalarının ikinci gerekli unsuru bir durma koşuludur. Örnekler:

- **Hedef doğruluk oranı:** 10 örneğin 9'u doğru tahmin ediliyorsa algoritma durdurulabilir; o zaman durma koşulu %90 başarıdır.
- **İterasyon (ya da epok) sayısı:** Algoritmanın çok uzun çalışması istenmiyorsa belirli bir sayıdan sonra durdurulur.

Hebb algoritmasında durma koşulu yoktur, çünkü varsayılan olarak tek iterasyon çalışıp zaten durur.

## 6. Perseptron Öğrenme Kuralı

Hoca önce perseptronun yeteneğini özetledi. Problem doğrusal ayrılabilir ise perseptron öğrenme kuralı mutlaka bir çözüm bulur. Sınır şudur: Sonlu sayıda iterasyonda çözer, ama bu sayı çok büyük olabilir; binlerce iterasyon gerekebilir. Çözeceği garanti matematiksel olarak kanıtlanmıştır. AND örneğinde olduğu gibi iki bilinmeyen ve en az iki denklemle matematiksel olarak çözülebilen bir sistem varsa perseptron onu çözebilecek kapasitededir.

Başka bir sorun, problemin iyi tanımlanmamış olmasıdır: Problem doğrusal gibi tanımlanmış ama dikkate alınması gereken başka parametreler atlanmıştır. Bu durumda istenen başarı elde edilmeyebilir, ama bu kullanıcının hatasıdır. Perseptron, verildiği hâliyle doğrusal olan problemi her durumda çözer.

### 6.1 Mimari

Perseptron, ikili sınıflandırma (binary) problemleri için kullanılan öğretmenli bir öğrenme algoritmasıdır. Slaytta mimari üç adımda gösterildi: girişleri ağırlıklandır (weigh), topla (sum up), aktive et (activate) (ekrandan, 00:40:00). Girişler bağlantı ağırlıklarıyla çarpılıp toplanır, buna bias eklenir ve aktivasyon fonksiyonu uygulanarak çıkış elde edilir. Öğrenme algoritması $w_1$, $w_2$ gibi ağırlıkların nasıl değiştirileceğini söyler.

- Giriş sayısında kısıt yoktur. Çıkış sayısında da kısıt yoktur; şekillerde tek çıkış gösterilmesi tesadüftür.
- **Bias** her zaman kullanılmalıdır, ağa esneklik sağlar. Bias, değeri 1 olan ek bir girişmiş gibi düşünülür ve $b$ bağlantı ağırlığıyla toplama katılır.
- Perseptronun ilk tanımında aktivasyon fonksiyonu eşik (threshold) fonksiyonudur. Sonraki kullanımlarda başka fonksiyonlar da kullanılabilir. Ancak perseptron öğrenme kuralının orijinali eşik fonksiyonu varsayılarak tasarlanmıştır.

Perseptron kuralı Hebb'den farklı olarak iteratiftir. Ağırlıkları yeterince çok kez artırıp azaltma şansı olduğu için daha güçlü bir öğrenme kuralıdır.

### 6.2 Aktivasyon ve güncelleme

Net girdi ve çıkış (ekrandan, 00:45:00):

$$y\_in = b + \sum_i x_i w_i$$

$$y = \begin{cases} 1 & y\_in > \theta \\ 0 & -\theta \le y\_in \le \theta \\ -1 & y\_in < -\theta \end{cases}$$

> **Ders sonrası not:** Slaytta net girdi $b + \sum_i x_i + w_i$ diye yazılmıştı; hoca da derste "şurası artı olmuş, çarpı olacak" diyerek düzeltti. Doğrusu $b + \sum_i x_i w_i$'dir.

Bias toplamın dışında yazılmıştır, çünkü bias nöronunun değeri 1'dir ve onu $b$ olarak almak yeterlidir; içeri katılabilirdi ama ayrı görünmesi daha anlaşılırdır.

Algoritmanın adımları:

1. Ağırlıkları ve bias'ı başlat (genellikle sıfır). Öğrenme katsayısını ($\eta$ ya da $\alpha$, $0 < \eta \le 1$) seç.
2. Her eğitim örneği için net girdiyi ve çıkışı hesapla.
3. Çıkış hedefle aynı değilse ($y \ne t$) ağırlıkları güncelle; aynıysa hiçbir şey yapma:

$$w_i(\text{yeni}) = w_i(\text{eski}) + \eta\, t\, x_i, \qquad b(\text{yeni}) = b(\text{eski}) + \eta\, t$$

4. Her epok sonunda durma koşulunu kontrol et.

Burada $t$ hedef (target) değeridir: elimizdeki örneklerin çıkışta ne olması gerektiğini söylediği değer. Örneğin AND kapısına 0-0 verince 0 bekleriz; hesaplanan değer 0 değilse fark oluşmuştur ve ağırlık güncellenir. Hebb'e çok benzer, farkı öğrenme katsayısı ve hesaplanan $y$ yerine olması gereken $t$ değerinin kullanılmasıdır.

**Öğrenme katsayısı** öğrenmenin yavaş ya da hızlı olmasını ayarlar. 1 seçilirse öğrenme kuralı olduğu gibi uygulanır. Daha küçük seçilirse ağırlıklardaki değişiklikler o oranda küçülür.

**Durma koşulu:** Bir tur boyunca hiçbir örnek için ağırlık değişmemişse, yani AND'in dört örneğinin hepsinde hedef tutturulmuşsa, ağırlıklar olması gereken yere gelmiştir ve algoritma durur. Dört örneğin ikisinde hedef tutturulmuşsa bu yetmez, bir tur daha gerekir. Ağırlık ayarlaması yalnız hata oluştuğunda yapıldığı için perseptron kuralına hata tabanlı öğrenen bir algoritma denir. Durma koşulu hiç hata kalmaması ya da belirli bir epok sayısı olabilir.

## 7. Epok Kavramı

Hoca durma koşulunda bilerek "iterasyon" değil "epok" dediğini belirtti. Bir epok, bütün örneklerin bir kez gösterilmesidir. Elde dört örnek varsa algoritmayı bu dört örnekle bir kez çalıştırmak bir epoktur.

İterasyon sayısı örnek sayısıyla değişir. Örnek sayısı da probleme göre değiştiği için iterasyonla konuşmak sağlıklı değildir. Bugün 10 veri varken kod "10 iterasyon" diye yazılırsa, yarın 100 örnekle çalıştırıldığında algoritma bütün örnekleri gösteremeden erken durur. Epok sayısı aslında her örneğin kaç kez gösterileceğini söyler. Epok 1 seçilirse dört örneğin her biri bir kez gösterilip algoritma sonlanır.

## 8. Perseptron ile AND: Binary Giriş, Bipolar Çıkış

Örnekte girişler binary (0 ve 1), çıkışlar bipolar seçilmiştir: sonuç olumluysa 1, olumsuzsa $-1$, sonuç bilinmiyorsa 0. AND kapısında sonucun bilinmemesi gibi bir durum yoktur. Parametreler: öğrenme katsayısı $\eta = 1$, eşik $\theta = 0.2$, başlangıç ağırlıkları ve bias 0. Ağırlık değişimi $\Delta W = \eta\, t\,(x_1, x_2, 1)$'dir (ekrandan, 00:50:00).

### 8.1 Birinci örnek

Giriş $(x_1, x_2, 1) = (1, 1, 1)$, hedef $t = 1$.

- Net girdi: $y\_in = 0 + 1 \cdot 0 + 1 \cdot 0 = 0$.
- Çıkış: $0 \le 0.2$ olduğundan eşik geçilemez, $y = 0$.
- $y = 0 \ne t = 1$, hata var.
- Değişim: $\Delta W = 1 \cdot 1 \cdot (1, 1, 1) = (1, 1, 1)$.
- Yeni ağırlıklar: $(0, 0, 0) + (1, 1, 1) = (1, 1, 1)$.

### 8.2 İkinci örnek

Giriş $(1, 0, 1)$, hedef $t = -1$ (ekrandan, 00:55:00).

- Net girdi: $1 \cdot 1 + 0 \cdot 1 + 1 \cdot 1 = 2$.
- Çıkış: $2 > 0.2$, $y = 1$.
- $y = 1 \ne t = -1$, hata var.
- Değişim: $\Delta W = 1 \cdot (-1) \cdot (1, 0, 1) = (-1, 0, -1)$.
- Yeni ağırlıklar: $(1, 1, 1) + (-1, 0, -1) = (0, 1, 0)$.

### 8.3 Ayırma çizgileri

Her ağırlık değişiminden sonra eşitsizliklerdeki $<$ ve $>$ yerine eşitlik konarak ayırma çizgileri çizilebilir. Bu kez $x_1$ ve $x_2$ yerine değer yazılmaz, çünkü istenen şey mevcut ağırlıklarla oluşan doğruların bütün $(x_1, x_2)$ örneklerini doğru ayırmasıdır. Eşik fonksiyonu iki sınır ($+\theta$ ve $-\theta$) içerdiği için iki doğru oluşur; aralarındaki bant bir tür doğrusal bölgedir.

Grafikte AND'in sonuçları işaretlenir: (0,0), (0,1), (1,0) için eksi, yalnız (1,1) için artı. Ağırlıklar $(1, 1, 1)$ iken doğrular eksilerle artıyı ayıramaz. İkinci örnekten sonra ağırlıklar $(0, 1, 0)$ olunca ayırma çizgileri $x_2 = 0.2$ ve $x_2 = -0.2$ olur; eksiler ve artılar hâlâ ayrılmamıştır (ekrandan, 01:10:00). Üçüncü ve dördüncü örneklerle ağırlıklar değişmeye devam eder.

Eğitim yaklaşık 10 epok sürer: 10. epokta dört örneğin hepsinde hesaplanan değer hedefle aynıdır (1 için 1, $-1$ için $-1$) ve hiçbir ağırlık değişmez. Durma koşulu bu noktada sağlanır. 10. epok sonunda karar sınırlarının altında negatif, üstünde pozitif sonuçlar kalır.

> **Ders sonrası not:** Python ile tekrarlanan eğitimde örnek sırası (1,1), (1,0), (0,1), (0,0) iken eğitim 10. epokta durur ve son ağırlıklar $(w_1, w_2, b) = (2, 3, -4)$ olur. Hoca ayırma doğrularını "$x_2 = -\tfrac{2}{3}x_1 + \tfrac{7}{5}$ ve $x_2 = -\tfrac{2}{3}x_1 + \tfrac{19}{5}$" diye okudu. $2x_1 + 3x_2 - 4 = 0.2$ ve $2x_1 + 3x_2 - 4 = -0.2$ eşitliklerinden doğrusu $x_2 = -\tfrac{2}{3}x_1 + \tfrac{7}{5}$ ve $x_2 = -\tfrac{2}{3}x_1 + \tfrac{19}{15}$'tir.

## 9. Bipolar Giriş ile Daha Hızlı Yakınsama

Hoca aynı AND problemini bipolar giriş ve bipolar çıkışla, $\theta = 0$, öğrenme katsayısı 1 ve sıfır başlangıç ağırlıklarıyla denemeyi önerdi (bkz. Örnek Sorular). Bu kez birinci epokun son adımında ağırlık değişimi olmaz ve 2. epokta dört örneğin hiçbirinde ağırlık değişmez (ekrandan, 01:15:00):

| Giriş $(x_1, x_2, 1)$ | Net | Çıkış | Hedef | Değişim | Ağırlıklar |
|---|---|---|---|---|---|
| $(1, 1, 1)$ | 1 | 1 | 1 | $(0, 0, 0)$ | $(1, 1, -1)$ |
| $(1, -1, 1)$ | $-1$ | $-1$ | $-1$ | $(0, 0, 0)$ | $(1, 1, -1)$ |
| $(-1, 1, 1)$ | $-1$ | $-1$ | $-1$ | $(0, 0, 0)$ | $(1, 1, -1)$ |
| $(-1, -1, 1)$ | $-3$ | $-1$ | $-1$ | $(0, 0, 0)$ | $(1, 1, -1)$ |

Slaytın sonucu: Sistem ilk epoktan sonra tamamen eğitildi. Bipolar gösterim epok sayısını azaltır. Mümkünse bipolar giriş ve bipolar çıkış kullanılmalıdır. Binary girişte 10 epok süren aynı problem, yalnız girişler bipolar yapılınca bir epokta öğrenildi.

Hoca bunun matematiksel sebebini şöyle açıkladı: Öğrenme kuralı $t$ ile $x$'in çarpımına dayanır. Sıfır çarpmada "yutan" bir sayıdır; $x_i = 0$ olduğunda $t$'nin değeri hiç dikkate alınmamış olur. Binary gösterimde girişlerde daha çok sıfır bulunduğu için öğrenme yavaşlar. $-1$ ve $+1$ gibi birbirinden ayrılabilen değerler kullanılınca her adımda öğrenme olur ve algoritma hızlanır.

> **Hocanın vurgusu:** Özellikle bu tür ikili sınıflandırıcı algoritmalarda, mümkün olan her durumda bipolar giriş ve çıkış kullanırsanız algoritmanızı hızlandırırsınız.

## 10. Karakter Tanıma Problemi

Hoca perseptronun daha gerçekçi bir uygulaması olarak karakter tanıma problemini anlattı. Üç farklı fontla yazılmış 7 harf (A, B, C, D, E, J, K) vardır; toplam 21 örnek. Fontlar arasında küçük farklar vardır. Örneğin bir A harfinde bir fontta üstte 3 piksel doluyken, başka bir fontta bunlara ek olarak solda bir piksel daha doludur.

İstenen şey, verilen girişin hangi harf olduğunu fonttan bağımsız olarak söylemektir. Yani sınıflar fontlar değil, harflerdir. Bu durumda (ekrandan, 01:20:00):

- **Çıkışlar:** 7 harf olduğuna göre 7 çıkış birimi ($Y_1, \dots, Y_7$) vardır; her biri bir harfi temsil eder. Çıkış birimi sayısı = 7 = sınıf sayısı.
- **Girişler:** Görsel bir karakter sayısal olarak ifade edilmelidir. Karakter bir matrise oturtulur ve her pikselin dolu/boş durumu sayıyla gösterilir. Yatayda 7, dikeyde 9 piksel olduğundan her harf $7 \times 9$ matristir ve giriş birimi sayısı $7 \times 9 = 63$'tür.
- Her giriş birimi her çıkış birimine $w_{i,j}$ ağırlığıyla bağlanır ($i = 1, \dots, 63$; $j = 1, \dots, 7$). Bu, 7 çıkışlı tek katmanlı ileri beslemeli bir ağdır.

**Soru:** Bu problemde bipolar giriş kullanabilir miyiz? **Cevap:** Kesinlikle; dolu piksel 1, boş piksel $-1$ olur. Hatta hem binary hem bipolar girişle denenip sonuçlar karşılaştırılmalıdır.

Hoca bu problemde bazı harflerin birbirine daha sık karışacağını, yani ağın A yerine B gibi yanlış cevaplar vereceğini belirtti. Epok sayısı artırılınca başarı değişiyor mu ve hâlâ karışan harfler neden karışıyor, bunlar ileride konuşulacak konularla bağlantılı sorulardır. Hoca ayrıca 7 çıkış yerine daha az çıkışla kodlama yapılabileceğini de söyledi (bkz. Örnek Sorular).

## 11. Hebb ve Perseptron Karşılaştırması

Hebb kuralının çözemediği bazı problemler vardır; bunun esas sebebi tek iterasyon çalışmasıdır. Biraz daha ilerletilebilseydi çözebilirdi. Hocanın gösterdiği örnekte Hebb kuralı problemi çözemezken perseptron 26 epokta çözmüştür. Örnek üç girişli olduğu için sınıfları ayıran şey bir doğru değil bir düzlemdir. Doğrusal ayırıcı çok boyutlu bir düzlem (hiperdüzlem) de olabilir; yeter ki düzlemsel bir yapıyla ayrılabilsin. Problem doğrusal olduğu için perseptron onu her durumda çözebilir. <!-- BELİRSİZ: üç girişli örneğin veri tablosu slaytta gösterildi, ancak o ana ait kare yok; değerler doğrulanamadı. -->

## 12. Adaline ve Delta Kuralı

Hoca bu bölümü önemli diye niteledi, çünkü burada başlayan delta kuralı ve genişletilmiş delta kuralı hâlâ kullanılan kurallardır.

### 12.1 Tanım

Adaline (Adaptive Linear Neuron; slaytta Adaptive Linear Network) 1960'ta Bernard Widrow ve Ted Hoff tarafından geliştirilmiştir. Tek çıkış birimi ve birden fazla girişi olan, bias'lı bir yapay sinir ağıdır; mimarisi perseptronla aşağı yukarı aynıdır. Slayttaki özellikleri (ekrandan, 01:30:00):

- Giriş sinyalleri ve hedef değerleri için bipolar aktivasyonlar ($-1$ ve $1$) kullanır.
- Ağırlık bağlantıları ayarlanabilir.
- Ağırlık güncellemesi için delta kuralıyla eğitilir:

$$w_{ij}(\text{yeni}) = w_{ij}(\text{eski}) + \alpha\,(t_j - y_j)\,x_i$$

Esas fark öğrenme kuralındadır. Şimdiye kadar hedefin tutturulup tutturulmadığına bakılıyordu. Delta kuralı daha gelişmiş bir şey yapar: Hedeften ne kadar uzakta olunduğuna bakar ve ağırlıkları buna göre ayarlar. Aktivasyon ile hedef arasındaki ortalama karesel hatayı hesaplayıp en aza indirmeye çalışır. Hebb hesaplanan değeri, perseptron hedef değeri girişle çarpıyordu. Delta kuralı ise ikisinin farkını girişle çarpar.

> **Ders sonrası not:** Hoca slaytlarda öğrenme katsayısının yer yer $\mu$ (mü), yer yer $\alpha$ ya da $\eta$ ile gösterildiğini, hepsinin aynı öğrenme katsayısı olduğunu belirtti.

### 12.2 Algoritma ve öğrenme katsayısı

Adımlar perseptronunkine benzer: başlangıç ağırlıkları ve 0 ile 1 arasında bir öğrenme katsayısı seçilir; durma koşulu sağlanana kadar her örnek için nörona gelen net girdi ve çıkış hesaplanır, ağırlıklar delta kuralıyla güncellenir ve her adımda durma koşulu kontrol edilir.

Öğrenme katsayısının etkisi burada da görülür: Katsayı çok büyükse yakınsama olmayabilir. Aranan ağırlık değeri küsuratlı bir ara değerse, büyük adımlarla o değer hiç denenmeden atlanabilir. Yavaş öğrenme yakınsamayı kolaylaştırır. Adaline için önerilen pratik aralık giriş sayısını esas alır:

$$0.1 \le n\,\alpha \le 1$$

Burada $n$ giriş sayısıdır. Örneğin beş giriş varsa $5\alpha$, 0.1 ile 1 arasında kalmalıdır.

### 12.3 AND örneği: binary giriş, bipolar hedef

Adaline hatayı en aza indirgeyecek ağırlıkları bulmak için tasarlanmıştır. Hata karesel hata olarak hesaplanır (ekrandan, 01:35:00):

$$E = \sum_{p=1}^{4} \big(x_1(p) w_1 + x_2(p) w_2 + w_0 - t(p)\big)^2$$

Burada $x_1(p) w_1 + x_2(p) w_2 + w_0$, $p$ deseni için net girdi; $t(p)$ ise $p$ deseninin hedefidir. Parantezin ilk üç terimi, seçilen $w_1$, $w_2$ ağırlıklarına göre nöronun hesapladığı değerdir. Hedefle fark çıkarma işlemiyle de alınabilir; karesel hata kullanılınca daha iyi yakınsama sağlanır. Bu hatayı en aza indiren ağırlıklar:

$$w_1 = 1, \quad w_2 = 1, \quad w_0 = -\tfrac{3}{2}$$

ve ayırma doğrusu $x_1 + x_2 - \tfrac{3}{2} = 0$'dır.

Bu ağırlıklarla dört eğitim örneği için toplam karesel hata 1'dir. Kontrol (ara adım eklendi): (0,0) için net $-1.5$, hedef $-1$, fark $-0.5$; (0,1) ve (1,0) için net $-0.5$, hedef $-1$, fark $0.5$; (1,1) için net $0.5$, hedef $1$, fark $-0.5$. Her farkın karesi $0.25$, toplam $1$ (python ile doğrulandı). Hoca perseptronla bulunan ağırlıklarla bu hatanın $10/9$, yani 1'in biraz üstünde olduğunu söyledi. <!-- BELİRSİZ: 10/9 değerinin hangi perseptron ağırlıklarından hesaplandığı ekranda görülemedi; doğrulanamadı. -->

Adaline kuralıyla doğru denklemleri biraz değişir ve daha iyi yöne değişir. AND'de örnekler birbirinden yeterince uzak olduğu için fark önemsizdir. Ama veriler birbirine çok yakınsa ve çok hassas ayırma gerekiyorsa perseptron zorlanır ya da daha uzun sürede yakınsar; delta kuralı daha hızlı yakınsar ve daha hassas ayırma yapar.

### 12.4 Adaline ve perseptronun karşılaştırılması

Ortak yönler:

- İkisi de ikili sınıflandırıcıdır (binary classifier).
- İkisi de doğrusal problemleri çözer, dolayısıyla doğrusal karar sınırlarına sahiptir.
- İkisi de iteratiftir ve eşik aktivasyon fonksiyonu kullanır.

Fark: Perseptron desenlerin ortak etmenlerini belirlerken sınıf etiketlerini (doğru/yanlış gibi) kullanır. Adaline ise sürekli tahmin değerlerini kullanır.

## 13. Delta Kuralının Türevden Elde Edilmesi

Delta kuralının bir sonraki versiyonu genişletilmiş delta kuralıdır ve geri yayılım (backpropagation) algoritmasında kullanılacaktır. Mantığı, net girdi ile hedef arasındaki farkı en aza indirmektir. Fark doğrudan çıkarmayla alınabilir; ama düşürülmeye çalışılan şey hatanın miktarı olduğu için karesi de kullanılabilir. Amaç bütün eğitim örnekleri üzerindeki hatayı en aza indirmek olduğundan, bütün örneklerin karesel hataları toplanıp bu toplam küçültülürse hep en iyiye doğru gidilir.

Perseptronda bir örnek gösterilip hedef tutturulamazsa ağırlık hemen değiştiriliyordu. Toplu yaklaşımda ise her örnek için farklar hesaplanır, değişim miktarları bir araya getirilip bir $E$ değeri hesaplanır. $m$ örnek için (ekrandan, 01:45:00):

$$\Delta w_{IJ} = \alpha\,(t_J - y\_in_J)\,x_I$$

$$E = \sum_{j=1}^{m} (t_j - y\_in_j)^2, \qquad y\_in_J = \sum_{i=1}^{n} x_i w_{iJ}$$

Türev bir değişimdir. Bir ağırlığın hata üzerindeki etkisini görmek için $E$'nin o ağırlığa göre türevi alınır:

$$\frac{\partial E}{\partial w_{IJ}} = \frac{\partial}{\partial w_{IJ}} \sum_{j=1}^{m} (t_j - y\_in_j)^2 = \frac{\partial}{\partial w_{IJ}} (t_J - y\_in_J)^2$$

$$\frac{\partial E}{\partial w_{IJ}} = -2\,(t_J - y\_in_J)\,\frac{\partial y\_in_J}{\partial w_{IJ}} = -2\,(t_J - y\_in_J)\,x_I$$

Hatayı azaltmak için ağırlık türevin tersi yönünde değiştirilir ve şu elde edilir:

$$\Delta w_{IJ} = \alpha\,(t_J - y\_in_J)\,x_I$$

Böylece delta kuralı yalnız "hedeften ne kadar uzağım" sezgisinden değil, bu türev ifadesinden de çıkar. Kural, her ağırlığı hataya katkısı oranında değiştirir; bütün ağırlıklara toptan aynı muamele yapılmaz. Türevdeki 2 çarpanı önemli değildir, çünkü zaten öğrenme katsayısı diye bir oran parametresi vardır ve sabit onun içine katılabilir.

> **Ek bilgi (derste anlatılmadı):** Ağırlığı hata fonksiyonunun türevinin tersi yönünde küçük adımlarla değiştirme yöntemine gradyan inişi (gradient descent) denir. Delta kuralı, karesel hatanın doğrusal bir nöron için gradyan inişiyle küçültülmesidir; bu yüzden en küçük ortalama kareler (LMS, least mean squares) kuralı ya da Widrow-Hoff kuralı diye de anılır.

Hoca üç kuralın iki slaytını hep göz önünde tutmayı istedi:

| Kural | Ağırlık değişimi | Not |
|---|---|---|
| Hebb | $\Delta w_i = y\,x_i$ (hesaplanan çıkış $\times$ giriş) | Tek iterasyon, başarısı sınırlı |
| Perseptron | $\Delta w_i = \eta\,t\,x_i$ (hedef $\times$ giriş $\times$ katsayı) | Hata olduğunda güncelleme |
| Delta | $\Delta w_i = \alpha\,(t - y\_in)\,x_i$ | Hedefle çıktı farkı oranında güncelleme |

Perseptron Hebb'den bir derece, delta kuralı da perseptrondan daha iyidir; çünkü hem hesaplananı hem hedefleneni, yani hedefe ne kadar uzak olunduğunu dikkate alır.

## 14. Madaline ve XOR

### 14.1 Mimari

Madaline (Many Adaptive Linear Neurons), çok katmanlı bir ağda düzenlenmiş birçok Adaline'dan oluşur: iki gizli Adaline ve bir çıkış Adaline birimi (ekrandan, 01:55:00). $X_1$ ve $X_2$ girişleri $w_{11}$, $w_{21}$ ağırlıklarıyla ve $b_1$ bias'ıyla $Z_1$'e; $w_{12}$, $w_{22}$ ve $b_2$ ile $Z_2$'ye bağlanır. $X_1, X_2 \to Z_1$ tek başına bir Adaline'dır, $X_1, X_2 \to Z_2$ de öyle. $Z_1$ ve $Z_2$'nin çıktıları $v_1$, $v_2$ ve $b_3$ ile $Y$'ye bağlanınca girişi $Z_1, Z_2$ olan üçüncü bir Adaline oluşur. $Z$ birimleri gizli katmandadır; bunlara gizli Adaline'lar denir. Literatürde perseptrondan sonra Adaline ve Madaline ağları gelir.

### 14.2 MR1 algoritması

Madaline öğrenme algoritmasının birkaç varyasyonu vardır. Klasik MR1 algoritmasında:

- Çıkış biriminin ağırlıkları sabittir: $v_1 = v_2 = \tfrac{1}{2}$ ve bias $b_3 = 0.5$. Bunlar ayarlanmaz.
- Yalnız gizli Adaline'ların dört ağırlığı ($w_{11}$, $w_{12}$, $w_{21}$, $w_{22}$) ve bias'ları, normal Adaline algoritması gibi ayarlanır.
- Birimlerin aktivasyon fonksiyonu bipolardır: girdi sıfırdan büyükse (ya da eşitse) 1, küçükse $-1$.

MR2 algoritmasında ise tüm ağırlıkların ayarlanması için bir yöntem önerilmiştir.

Sabit $0.5$ ağırlıklı çıkış birimi bir tür OR fonksiyonu gibi iş görür: $Z_1$ ve $Z_2$'den en az biri 1 ise $y\_in \ge 0.5 > 0$ olur ve çıkış 1'dir; ikisi de $-1$ ise $y\_in = -0.5$ ve çıkış $-1$'dir (ara adım eklendi).

### 14.3 XOR örneği

Bipolar XOR'un doğruluk tablosu: $(1, 1) \to -1$, $(1, -1) \to 1$, $(-1, 1) \to 1$, $(-1, -1) \to -1$. Başlangıç ağırlıkları küçük rastgele değerlerdir, $\alpha = 0.5$ (ekrandan, 02:10:00):

| $Z_1$'e giden | $w_{11} = 0.05$ | $w_{21} = 0.2$ | $b_1 = 0.3$ |
|---|---|---|---|
| $Z_2$'ye giden | $w_{12} = 0.1$ | $w_{22} = 0.2$ | $b_2 = 0.15$ |
| $Y$'ye giden (sabit) | $v_1 = 0.5$ | $v_2 = 0.5$ | $b_3 = 0.5$ |

İlk eğitim çifti $s : t = (1, 1) : -1$.

1. Değerler atanır: $x_1 = 1$, $x_2 = 1$.
2. Her Adaline birimi için net girdi:
   - $z\_in_1 = b_1 + x_1 w_{11} + x_2 w_{21} = 0.3 + 0.05 + 0.2 = 0.55$
   - $z\_in_2 = b_2 + x_1 w_{12} + x_2 w_{22} = 0.15 + 0.1 + 0.2 = 0.45$
3. Aktivasyon: ikisi de sıfırdan büyük, $z_1 = 1$, $z_2 = 1$.
4. Ağın çıkışı: $y\_in = b_3 + z_1 v_1 + z_2 v_2 = 0.5 + 0.5 + 0.5 = 1.5$, $y = 1$.
5. Hata: hedef $-1$, çıkış $1$; fark var, ağırlıklar ve bias'lar güncellenecek.

> **Ders sonrası not:** Slaytta 1. adımda "$x_2 = 2$" yazıyor; hesaplarda $x_2 = 1$ kullanıldığı için doğrusu $x_2 = 1$'dir. Ayrıca slayttaki "$t - y = -1 - 1 = 2$" ifadesinde fark $-2$'dir; hoca derste farkın büyüklüğünü "iki" diye söyledi.

Güncelleme $Z_1$ ve $Z_2$ için Adaline kuralıyla, birimin net girdisi kullanılarak yapılır (ara adım eklendi):

- $Z_1$: $\alpha(t - z\_in_1) = 0.5 \cdot (-1 - 0.55) = -0.775$. Yeni değerler: $b_1 = 0.3 - 0.775 = -0.475$, $w_{11} = 0.05 - 0.775 = -0.725$, $w_{21} = 0.2 - 0.775 = -0.575$.
- $Z_2$: $\alpha(t - z\_in_2) = 0.5 \cdot (-1 - 0.45) = -0.725$. Yeni değerler: $b_2 = 0.15 - 0.725 = -0.575$, $w_{12} = 0.1 - 0.725 = -0.625$, $w_{22} = 0.2 - 0.725 = -0.525$.

Hoca derste $Z_1$ için $-0.475$, $-0.725$ ve $-0.575$ değerlerini okudu; bunlar yukarıdaki yeni bias ve ağırlık değerleriyle aynıdır (python ile doğrulandı). Sonra diğer örneklerle devam edilir ve derste aktarıldığına göre XOR dört epok sonunda öğrenilir. Eğitim, çıktılar bütün örneklerin hedeflerini sağladığında sonlanır.

### 14.4 Geometrik yorum

Artık iki Adaline olduğu için bir sınır doğrusu $Z_1$'den, bir sınır doğrusu $Z_2$'den gelir. Hoca $Z_1$ için oluşan sınır doğrusunu "0.48 $x_1$ artı 0.65" diye okudu. <!-- BELİRSİZ: Z1 ve Z2 sınır doğrularının denklemleri slaytta vardı ama o ana ait kare yok; katsayılar doğrulanamadı. --> Hoca ara şekillerde artı ve eksi işaretlerinde hata olduğunu, son şeklin doğru olduğunu belirtti.

Son şekilde (ekrandan, 02:20:00) XOR'un artıları sol üstte $(-1, 1)$ ve sağ altta $(1, -1)$, eksileri sağ üstte $(1, 1)$ ve sol altta $(-1, -1)$'dir. İki çapraz bant çizgisi, eksileri ortadaki bölgede bırakıp iki artıyı dış bölgelere ayırır. Madaline'ın çıktısında iki doğrusal bölge oluşur ve artılarla eksiler ayrılabilir.

**Soru:** İki Adaline (iki $Z$ birimi) kullandığımız için mi iki doğru oluştu? **Cevap:** Aynen öyle. Bu, çok katmanlı perseptrona yaklaşmaktır; sanki iki ayrı katman kullanılmış gibi iki doğru oluşunca ayırma şansı doğar. Tek doğru nereye yerleştirilirse yerleştirilsin, artılardan biri sol üstte, diğeri sağ altta olduğu için ayırma mümkün değildir.

Madaline'ın yaptığı şey iki ağı bir arada kullanmaktır. Bunları arka arkaya eklemeyi düşündüğümüzde çok katmanlı perseptron fikrine varırız.

> **Hocanın vurgusu:** Adaline ve Madaline artık çok kullanılmıyor, ama asıl fikir Adaline ile gelen hata hesaplama yöntemidir: hedefle hesaplanan değerin farkına bakmak ve karesel hata kullanmak. Delta kuralı çok katmanlı perseptronlarda ve bugün derin öğrenmede geri yayılım algoritmasıyla birlikte kullanılmaktadır.

## Örnek Sorular

### Soru 1: XOR perseptronla çözülebilir mi?

Kaynak: (ekrandan, 00:20:00). Önceki derste verilen soru, bu derste çözüldü.

İki girişli XOR kapısı için $\text{out} = \text{sgn}(w_1 in_1 + w_2 in_2 - \theta)$ perseptron denklemiyle eşitsizlikleri kurun ve $w_1$, $w_2$, $\theta$ için çözüm olup olmadığını gösterin.

**Çözüm:** Eşitsizlikler $\theta > 0$, $w_2 \ge \theta$, $w_1 \ge \theta$, $w_1 + w_2 < \theta$ olur. 2. ve 3. koşuldan $w_1 + w_2 \ge 2\theta > \theta$ çıkar (çünkü $\theta > 0$); bu 4. koşulla çelişir. Çözüm yoktur, XOR tek katmanlı perseptronla çözülemez.

### Soru 2: Bipolar giriş ve bipolar çıkışlı AND

Kaynak: (ekrandan, 01:15:00), (derste sözlü, 01:13:20).

AND kapısını bipolar giriş ve bipolar çıkışla perseptron kuralıyla eğitin. Öğrenme katsayısı $\alpha = 1$, eşik $\theta = 0$, başlangıç ağırlıkları ve bias sıfır. Algoritma ne zaman durur, son ağırlıklar ne olur?

Derste 2. epokun tablosu gösterildi: hiçbir ağırlık değişmez ve ağırlıklar $(1, 1, -1)$'dir.

> **Çözüm (derste verilmedi):** Birinci epok (python ile doğrulandı): $(1, 1, 1)$, hedef 1: net 0, çıkış 0, değişim $(1, 1, 1)$, ağırlıklar $(1, 1, 1)$. $(1, -1, 1)$, hedef $-1$: net 1, çıkış 1, değişim $(-1, 1, -1)$, ağırlıklar $(0, 2, 0)$. $(-1, 1, 1)$, hedef $-1$: net 2, çıkış 1, değişim $(1, -1, -1)$, ağırlıklar $(1, 1, -1)$. $(-1, -1, 1)$, hedef $-1$: net $-3$, çıkış $-1$, değişim yok. İkinci epokta hiçbir örnekte değişim olmadığı için algoritma 2. epok sonunda durur; son ağırlıklar $w_1 = 1$, $w_2 = 1$, $b = -1$.

### Soru 3: Madaline ile XOR'un bir epoku

Kaynak: (ekrandan, 02:10:00), (derste sözlü, 02:12:25).

Bölüm 14.3'teki başlangıç ağırlıklarıyla ($\alpha = 0.5$, çıkış ağırlıkları sabit 0.5) Madaline MR1 algoritmasının en az bir epokunu kendiniz yürütün.

Derste yalnız ilk eğitim çifti çözüldü (Bölüm 14.3).

> **Çözüm (derste verilmedi):** Python ile, büyük olasılıkla standart MR1 kuralına göre hesaplandı: hedef 1 iken çıkış $-1$ ise net girdisi sıfıra en yakın gizli birim, hedef $-1$ iken çıkış 1 ise net girdisi pozitif olan bütün gizli birimler $w \leftarrow w + \alpha(t - z\_in)x$ ile güncellenir. Birinci epok: $(1, 1) \to -1$ sonrası $Z_1 = (b, w_1, w_2) = (-0.475, -0.725, -0.575)$, $Z_2 = (-0.575, -0.625, -0.525)$. $(1, -1) \to 1$: $z\_in = (-0.625, -0.675)$, çıkış $-1$; $Z_1$ güncellenir: $(0.3375, 0.0875, -1.3875)$. $(-1, 1) \to 1$: $z\_in = (-1.1375, -0.475)$, çıkış $-1$; $Z_2$ güncellenir: $(0.1625, -1.3625, 0.2125)$. $(-1, -1) \to -1$: $z\_in = (1.6375, 1.3125)$, çıkış 1; ikisi de güncellenir: $Z_1 = (-0.98125, 1.40625, -0.06875)$, $Z_2 = (-0.99375, -0.20625, 1.36875)$. Epok sayısı güncelleme kuralının ayrıntılarına bağlıdır; derste dört epok söylendi.

### Soru 4: Karakter tanıma (uygulama)

Kaynak: (ekrandan, 01:20:00), (derste sözlü, 01:16:28 ve 01:33:15).

Üç fontla yazılmış 7 harften (A, B, C, D, E, J, K) oluşan 21 karakteri, $7 \times 9 = 63$ girişli ve 7 çıkışlı tek katmanlı bir ağla tanıyın. Karakterler önce sayısallaştırılır (dolu piksel 1; boş piksel binary gösterimde 0, bipolar gösterimde $-1$).

- Girişler binary iken ve bipolar iken kaç epokta, ne kadar başarıya (21 karakterin kaçı tanındı) ulaşılıyor?
- Aynı ağı hem perseptron öğrenme kuralıyla hem de delta (Adaline) kuralıyla eğitip karşılaştırın.
- Epok sayısı artırılınca (örneğin 10 ya da 100 epok daha) başarı değişiyor mu?
- Hangi harfler birbirine daha çok karışıyor ve neden?
- Kodu parametrik yazın; aynı problem ileride çok katmanlı ağla da denenecek.

Bu soru derste çözülmedi. Sayısallaştırılmış karakter matrisleri derste verilmediği için burada çözülemez.

## Dersin Toparlaması

Bu derste tek katmanlı perseptronun sınırı matematiksel olarak gösterildi. AND'in eşitsizlikleri çözülebilirken XOR'un eşitsizlikleri birbiriyle çelişir; yani tek katmanlı perseptron yalnız doğrusal ayrılabilir problemleri çözer. Buradan çok katmanlı ve geri beslemeli topolojilere geçildi. Ardından üç öğrenme kuralı sırayla incelendi. Hebb kuralı ($\Delta w = yx$) tek geçişlidir ve ağırlıkları sınırsız büyütebilir. Perseptron kuralı ($\Delta w = \eta t x$) yalnız hata olduğunda güncelleme yapar, iteratiftir ve doğrusal ayrılabilir her problemi sonlu adımda çözer. Delta kuralı ($\Delta w = \alpha(t - y\_in)x$) ise hedeften uzaklık oranında güncelleme yapar ve karesel hatanın türevinden elde edilir. AND örnekleri epok kavramını ve bipolar gösterimin yakınsamayı ne kadar hızlandırdığını gösterdi. Karakter tanıma örneği de perseptronun çok çıkışlı bir uygulaması olarak sunuldu.

Son olarak Madaline'ın iki gizli Adaline ile XOR'u iki doğruyla ayırabildiği görüldü. Bu fikir, birden çok katmanı arka arkaya bağlayan çok katmanlı perseptrona götürür. Hoca bir sonraki konunun dersin en önemli konusu olan çok katmanlı ağlar ve geri yayılım algoritması olacağını, delta kuralının genişletilmiş hâlinin orada kullanılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
