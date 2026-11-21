# Ders 11 Çalışma Özeti

## Genel Konular

- Konvolüsyonel sinir ağlarının (CNN) katmanlarının tekrarı
  - Konvolüsyon katmanı: istenen sayıda filtre, girdinin (genelde görüntünün) filtre boyutu kadar bir bölgesine uygulanır; aynı filtre görüntünün farklı bölgelerine tekrar tekrar uygulanır. Filtrelerin uygulanması konvolüsyon işlemiyle yapıldığı için katmanın adı buradan gelir.
  - Slayta göre aynı filtredeki nöronlar aynı ağırlık ve bias değerlerini paylaşır; böylece filtre aynı deseni görüntünün farklı bölgelerinde arar ve bütün görüntü taranır (ekrandan, 00:15:00). Birden fazla filtre aynı bölgelere paralel bakar; slayttaki örnekte 4 filtreli katman $8 \times 6 \times 4$ boyutlu bir yapıdır (ekrandan, 00:10:00).
  - Bölgeler arasında, mümkünse, kesişim (örtüşme) olması istenir: bir girdi düğümü hem birinci hem ikinci konvolüsyon işlemine bağlı olabilir.
  - ReLU katmanı: sinir ağlarındaki aktivasyon fonksiyonunun yerini alır; geri yayılım sırasında gradyanın kaybolması problemini aşmaya yardımcı olur ve CNN'de varsayılan fonksiyondur.
  - Pooling katmanı: boyut küçültme yapar. Birkaç nöronun özeti, en baskın özellik tek nöronla ifade edilir; böylece ileri ve geri yayılımdaki toplama, çarpma ve ağırlık güncelleme işlemleri azalır.
  - Tam bağlı (fully connected) katman: çıktıların etiketlenmesi (sınıflama) içindir; sınıf sayısı kadar nörondan oluşur ve pooling çıktısındaki bütün değerlere bağlıdır.
  - İstenen sayıda konvolüsyon, ReLU ve pooling katmanı kullanılabilir. Kesin olan, konvolüsyondan sonra ReLU ve pooling gelmesi ve en sonda tam bağlı katman bulunmasıdır.
- CNN'in temel dezavantajı
  - Gözetimli öğrenme gerektirir; bu da çok sayıda etiketli veri bulma problemini getirir. Uygulamada en çok zorlayan nokta budur.
- Korelasyon
  - İki fonksiyonun ya da ayrık durumda iki matrisin noktasal çarpımıdır: aynı indisli hücreler çarpılır, sonuçlar toplanır ve tek bir sayı elde edilir. Klasik matris çarpımı değildir.
  - Görüntüde maskenin merkezi her pikseli dolaşır: $g(i,j) = \sum_{k=-n/2}^{n/2} \sum_{l=-n/2}^{n/2} h(k,l)\, f(i+k, j+l)$; toplam bir ölçekleme sabiti $C$ ile çarpılıp çıktı pikseline yazılır (ekrandan, 01:15:00).
- Konvolüsyon
  - Korelasyonla aynıdır, yalnız maske (kernel) hem yatay hem dikey olarak döndürülür (flip). Gösterimi yıldızdır ($*$), korelasyon ise nokta ile gösterilir.
  - $g(x,y) = w(x,y) * f(x,y) = \sum_{s=-K/2}^{K/2} \sum_{t=-K/2}^{K/2} w(s,t)\, f(x-s, y-t)$ (ekrandan, 00:25:00).
  - Maske simetrikse ($w(x,y) = w(-x,-y)$) konvolüsyon korelasyona eşittir.
  - Sürekli tek boyutlu tanım: $f(x) * g(x) = \int_{-\infty}^{\infty} f(a)\, g(x-a)\, da$; yani ötelenmiş $g$ ile $f$'nin çarpımının altında kalan alan.
  - Yer değiştirme (komütatiflik): $f * g = g * f$; hangisinin filtre, hangisinin veri olduğu sonucu değiştirmez.
- Tek boyutlu sürekli konvolüsyon örneği (ekrandan, 00:35:00)
  - $f$: $[0,1]$ aralığında 1, $g$: $[0,1]$ aralığında $1/2$ olan iki kare (basamak) fonksiyon.
  - Sonuç parçalıdır: $0 \le x \le 1$ için $x/2$, $1 \le x \le 2$ için $1 - x/2$, diğer her yerde 0. Çizildiğinde üçgen elde edilir.
  - Sonucun genişliği iki fonksiyonun genişliklerinin toplamıdır (burada $1+1=2$). İntegralin alt sınırı iki fonksiyonun sol uçlarının büyüğü, üst sınırı sağ uçlarının küçüğüdür.
  - Kare fonksiyonla yarım testere fonksiyonunun konvolüsyonu daha düşük genlikli bir testere biçimi verir.
  - Impuls fonksiyonu konvolüsyonda etkisiz eleman gibidir: fonksiyonun şekli değişmez, yalnız impulsun bulunduğu yere ötelenir. Üç impulsluk bir dizi ile konvolüsyon, kare fonksiyonun üç ötelenmiş kopyasını verir (ekrandan, 00:40:00).
- Frekans domeni ve konvolüsyon teoremi
  - Uzamsal/zaman domenindeki konvolüsyon frekans domeninde çarpmaya eşdeğerdir; tersine, uzamsal domendeki çarpma frekans domeninde konvolüsyona karşılık gelir.
  - Adımlar: iki fonksiyonu frekans domenine çevir ($F(u)$, $G(u)$), çarp, çarpımın ters dönüşümünü al.
- Ayrık konvolüsyon
  - İntegralin yerini toplam alır, integral değişkeni indis olur, kaydırmalar ayrık adımlarla yapılır: $f(x) * g(x) = \sum_{m=-\infty}^{\infty} f(m)\, g(x-m)$ (ekrandan, 00:45:00).
  - $f$'den $A$, $g$'den $B$ örnek alınmışsa sonuç $A + B - 1$ örnek uzunluğundadır.
  - Ayrık durumda konvolüsyon teoremi yalnız (sıfırla) uzatılmış diziler için geçerlidir: $f_e(x) * g_e(x) \leftrightarrow F_e(u)\, G_e(u)$, genelde $M \ge A + B - 1$ seçilir (ekrandan, 00:50:00). Boyut doğru seçilmezse periyodik sonuçlar üst üste biner ve hatalı sonuç çıkar.
- Sıfırla doldurma (zero padding)
  - Veriyi istenen boyuta getirmek için kenarlara genellikle sıfır eklenir. Diğer seçenek kenarları katlayıp aynalamaktır. Padding konvolüsyonun özelliklerini değiştirmez.
- İki boyutlu konvolüsyon
  - $f(x,y) * g(x,y) = \int\!\!\int f(a,b)\, g(x-a, y-b)\, da\, db$; teoremi: $f * g \leftrightarrow F(u,v) G(u,v)$ ve $f g \leftrightarrow F(u,v) * G(u,v)$ (ekrandan, 00:55:00).
  - Ayrık durumda $A \times B$ boyutlu görüntü ile $C \times D$ boyutlu filtrenin konvolüsyonu $(A + C - 1) \times (B + D - 1)$ boyutlu sonuç verir.
- Doğrusallık
  - Korelasyon ve konvolüsyon doğrusal işlemlerdir: toplamsallık ($f(x_1 + x_2) = f(x_1) + f(x_2)$) ve homojenlik (sabit çarpanın dışarı alınması). Birlikte süperpozisyon ilkesi denir.
- Kosinüs benzerliği
  - $x \cdot y = \sum_i x_i y_i = \lVert x \rVert\, \lVert y \rVert \cos\theta$; buradan $\cos\theta = \dfrac{x \cdot y}{\lVert x \rVert \lVert y \rVert}$. Açı küçüldükçe iki vektör birbirine benzer.
  - Bir maske görüntüyle korelasyona sokulduğunda maskenin birebir bulunduğu yerin merkezi parlak çıkar; parlaklık yoksa görüntü maskeyle ilişkisizdir.
- Ayrılabilir (separable) filtreler ve işlem karmaşıklığı
  - $3\times3$ maskenin bir noktada uygulanması 9 çarpma ve 9 toplama gerektirir ($n^2$ karmaşıklık).
  - Filtre iki tek boyutlu vektörün çarpımına ayrılabiliyorsa önce satırlar, sonra sütun boyunca tek boyutlu konvolüsyon yapılır; karmaşıklık $2n$, yani $O(n)$ olur.
- Filtre seçimi ve CNN'in "sırrı"
  - Yüz tanıma gibi bir problemde kenar belirleme, ten rengi, keskinleştirme filtreleri düşünülebilir; ama derin ağda filtrelerin bilinçli seçilmesi şart değildir, yeterli sayıda farklı filtre olması yeter.
- Klasik sinir ağı ile CNN karşılaştırması ve CIFAR-10 örnek mimarisi
  - CIFAR-10'da görüntüler $32\times32\times3$'tür; tek bir tam bağlı nöronun $32\cdot32\cdot3 = 3072$ ağırlığı olur. $200\times200\times3$ görüntüde bu sayı $120\,000$'e çıkar.
  - Basit mimari: [INPUT - CONV - RELU - POOL - FC] (ekrandan, 01:45:00).
  - Boyutlar: 12 filtreyle konvolüsyon sonrası $32\times32\times12$; ReLU boyutu değiştirmez; pooling ile $16\times16\times12$; FC ile $1\times1\times10$ (10 sınıf skoru) (ekrandan, 01:50:00).
- ReLU'nun sorunları ve çözümleri
  - ReLU $\max(0, x)$'tir: pozitif değer aynen geçer, negatif değer sıfıra çekilir.
  - "Ölen ReLU": büyük gradyan güncellemelerinden sonra bazı nöronlar sürekli sıfırda kalır, bir daha aktive olamaz; hoca, istatistiksel olarak nöronların yaklaşık %40'ının ölebildiğinin gözlemlendiğini söyledi.
  - Leaky ReLU: $x<0$ için sıfır yerine küçük bir negatif eğim (slayta göre 0.01 kadar): $f(x) = \mathbb{1}(x<0)(\alpha x) + \mathbb{1}(x \ge 0)(x)$ (ekrandan, 01:55:00).
  - Maxout: $\max(w_1^T x + b_1,\; w_2^T x + b_2)$; ReLU ve Leaky ReLU bunun özel durumlarıdır. Slayta göre ölen ReLU sorunu yoktur ama nöron başına parametre sayısı iki katına çıkar.
  - Öğrenme katsayısına dikkat etmek ve ölü nöronların oranını izlemek önerilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Konvolüsyonda maskeyi döndürmeyi atlamamak
  - Örneklerde maske ya önceden döndürülmüş verilir ya da bu adım atlanıp doğrudan noktasal çarpım yapılır. Doğru konvolüsyon için maske önce yatayda, sonra dikeyde döndürülmeli, ardından noktasal çarpım yapılmalıdır.
- Etiketli veri gereksinimi
  - CNN ile çözülecek bir problemde elde çok sayıda etiketli veri olduğundan emin olunmalıdır; aksi halde CNN ile çözülebilecek problem başarılı çözülemez.
- Karmaşıklıkta asıl ölçüt çarpma sayısıdır
  - Toplamanın maliyeti çarpmanın yanında önemsizdir; filtrenin çarpanlarına ayrılabilmesi büyük görüntü ve çok sayıda filtrede ciddi hız kazancı sağlar.
- Ağın neye karar verdiği
  - Filtreleri biz seçsek de hangi özelliğin önemli olduğuna aslında ağ karar verir; insan algısında önemsiz görünen ama veride ayırt edici olan bir özelliği filtreler yakalayabilir.
- Eğitimde mükemmellik istenmez
  - Hata yeterince küçülmüyorsa filtreler yetersiz ya da uygun değildir; filtre eklemek/değiştirmek düşünülebilir. Ama eğitimin kusursuz olması ezberleme belirtisi olabilir.
- Görüntü dışı verilerde CNN
  - Görüntü işlemede başarılı filtreler doğrudan kullanıldığı için görüntü dışı (ör. $1\times50$'lik) girdilerde başarı düşebilir. Başarılı olsa bile sonuç çok sıkı test edilmelidir. Veriler çizdirildiğinde görsel olarak ayırt edici biçimler (ör. Gauss eğrisi ile doğru) görülebiliyorsa CNN yine işe yarayabilir.

## Kısa Tekrar Notları

- CNN katmanları: CONV (paylaşılan ağırlıklı filtreler), ReLU, POOL (boyut küçültme), FC (sınıflama).
- Korelasyon: aynı indisli elemanları çarp, topla. Konvolüsyon: maskeyi yatay+dikey döndür, sonra korelasyon.
- Simetrik maskede konvolüsyon = korelasyon. $f * g = g * f$.
- Sürekli: $\int f(a) g(x-a)\,da$; ayrık: $\sum_m f(m) g(x-m)$.
- İki kare fonksiyonun konvolüsyonu üçgen; genişlik = genişliklerin toplamı.
- Impuls: konvolüsyonun etkisiz elemanı; impuls dizisi = ötelenmiş kopyalar.
- Konvolüsyon teoremi: uzamsalda konvolüsyon = frekansta çarpma (ve tersi).
- Ayrık uzunluk: $A + B - 1$; 2B: $(A+C-1)\times(B+D-1)$; teorem için $M \ge A+B-1$.
- Zero padding: kenarlara sıfır; alternatif: aynalama.
- Doğrusallık: toplamsallık + homojenlik (süperpozisyon).
- Kosinüs benzerliği: $\cos\theta = x\cdot y / (\lVert x\rVert \lVert y\rVert)$.
- Ayrılabilir filtre: $n^2$ yerine $2n$ çarpma.
- CIFAR-10: $32\times32\times3 \to$ CONV(12) $32\times32\times12 \to$ ReLU aynı $\to$ POOL $16\times16\times12 \to$ FC $1\times1\times10$.
- Ölen ReLU; çözümler: Leaky ReLU (eğim ~0.01), Maxout, öğrenme katsayısını ayarlamak.

## Detaylı Açıklamalar

- **Konvolüsyon katmanı ve ağırlık paylaşımı.** Konvolüsyon katmanı, çok katmanlı perceptron gibi bütün girdilere bağlı değildir. Her filtre, filtre boyutu kadar bir bölgeye bağlıdır ve aynı filtre görüntünün başka bölgelerine aynen yansıtılır. Slayttaki şekilde dört farklı filtre (dört konvolüsyon işlemi) vardır ve bu yapı görüntü boyunca tekrarlanır; aynı filtredeki nöronlar aynı ağırlık ve biası paylaştığı için filtre aynı deseni görüntünün her yerinde arar (ekrandan, 00:15:00). Ardından gelen ReLU katmanında, her konvolüsyon katmanının boyutu kadar ReLU işlemi vardır; sonra pooling gelir. Birden fazla filtre kullanılması, görüntüde aranan özellikler kadar çeşitte konvolüsyon katmanı demektir.

- **Pooling ve tam bağlı katman.** Hocaya göre bu kadar konvolüsyondan sonra neyin önemli olduğu ortaya çıkmıştır; örneğin dört nöronun en ağır basan özelliği tek nöronla ifade edilebilir. Bu, geri yayılımdaki toplama, çarpma, gradyan hesabı ve ağırlık güncellemelerini azaltır. Slayta göre konvolüsyon, ReLU ve pooling birlikte karmaşık desenleri bulabilir ama ağ bu desenlerin ne anlama geldiğini bilmez; bu yüzden sona sınıflama yeteneği veren bir tam bağlı katman eklenir (ekrandan, 00:20:00).

- **Korelasyon ve konvolüsyonun ilişkisi.** Konvolüsyon formülünde $w$ simetrikse, $w(s,t) = w(-s,-t)$ olduğundan $f(x-s, y-t)$ terimi değişken dönüşümüyle $f(x+s, y+t)$'ye döner ve sonuç birebir korelasyonla aynı olur. Sürekli fonksiyonlarda konvolüsyonu hesaplamak zordur; bu yüzden zaman domeninden S domenine ya da frekans domenine geçilir. Fourier dönüşümü de konvolüsyon ve noktasal çarpıma dayanır.

- **İki kare fonksiyonun konvolüsyonu.** $f(a)$: $[0,1]$'de 1; $g(a)$: $[0,1]$'de $1/2$. Önce $g(x-a)$ oluşturulur ($g$ ters çevrilip $x$ kadar ötelenir) ve $f(a)$ ile çarpılarak integral alınır (ekrandan, 00:35:00):
  - $x < 0$: örtüşme yok, sonuç 0.
  - $0 \le x \le 1$: $\int_0^x 1 \cdot \tfrac12\, da = \tfrac{x}{2}$.
  - $1 \le x \le 2$: $\int_{x-1}^{1} 1 \cdot \tfrac12\, da = 1 - \tfrac{x}{2}$.
  - $x > 2$: fonksiyonlar ayrılır, sonuç 0.
  - Sonuç $x=1$'de $1/2$ tepe değerine ulaşan bir üçgendir. Değerler python ile sayısal konvolüsyonla kontrol edildi ($x = 0.5$ için $0.25$, $x = 1.5$ için $0.25$). Animasyonda iki eşit kare fonksiyonun konvolüsyonu da üçgen olarak gösterildi (ekrandan, 00:30:00); bu, iki fonksiyonun tepe noktasını belirginleştirmenin görsel bir örneğidir.

- **Impuls dizisiyle konvolüsyon (sınıfa sorulan soru).** Hoca, $[0,t]$'de 1 olan kare fonksiyonun $-T$, $0$, $T$ noktalarındaki üç impulsla konvolüsyonunun neye benzeyeceğini sordu (ekrandan, 00:40:00). Doğru cevap: kare fonksiyonun $-T$, $0$ ve $T$'ye ötelenmiş üç kopyası. Bir öğrencinin "soldaki ($-T$) sönümlenmez mi?" sorusuna hoca, konvolüsyonda kaydırma yapıldığı için soldaki impulsun da kare fonksiyonun ötelenmiş bir kopyasını üreteceğini söyledi.

- **Ayrık konvolüsyon ve boyut.** Sürekli fonksiyondan belirli sayıda örnek alınır ve çarpım bu örnekler üzerinden yapılır. $f$'den $A$, $g$'den $B$ örnek alınmışsa sonuç $A + B - 1$ uzunluğundadır (python ile 5 ve 3 uzunluklu iki dizinin konvolüsyonunun 7 eleman verdiği kontrol edildi). Konvolüsyon teoremini ayrık durumda kullanabilmek için diziler sıfırla uzatılır ve uzunluk $M \ge A + B - 1$ seçilir; seçilmezse periyodik olarak oluşan sonuçlar üst üste biner (ekrandan, 00:50:00).
  <!-- BELİRSİZ: 00:46:19'da hoca şekilde "1, 2, ..., 8 noktam var, 5 artı 3, 8 olacak" diyor; bu ana ait kare yok. Ayrık örnek sayısı formülü A+B-1 olduğundan (5+3-1=7) burada sürekli genişliklerden mi yoksa nokta sayısından mı söz edildiği anlaşılamadı. -->

- **Korelasyon örneği: $3\times3$ ortalama filtresi.** Maske, $\tfrac19$ ölçekli birlerden oluşan $3\times3$ filtredir; görüntü kenarları sıfırla doldurulmuş, ortasında 90'lardan oluşan bir bölge (içinde bir 0 pikseli) ve ayrı bir 90 pikseli olan $10\times10$ matristir (ekrandan, 01:20:00). Filtre gezdirildikçe sıfır bölgede sonuç 0, bir tane 90 içeren konumda $\tfrac19 \cdot 90 = 10$, iki tane 90'da 20, üç tane 90'da 30 çıkar. Slayttaki $8\times8$ çıktının tamamı python ile yeniden hesaplandı ve aynı çıktı (ilk satır: 0, 10, 20, 30, 30, 30, 20, 10) elde edildi.

- **2B konvolüsyon ve ayrılabilir filtre örneği (ekrandan, 01:30:00).** Filtre $\begin{bmatrix}1&2&1\\2&4&2\\1&2&1\end{bmatrix}$, görüntü $\begin{bmatrix}2&3&3\\3&5&5\\4&4&6\end{bmatrix}$. Yalnız merkez konumda: $2+6+3 = 11$, $6+20+10 = 36$, $4+8+6 = 18$, toplam 65 (filtre simetrik olduğu için döndürmek sonucu değiştirmez). Filtre $\begin{bmatrix}1\\2\\1\end{bmatrix} \times \begin{bmatrix}1&2&1\end{bmatrix}$ olarak ayrılır. Önce satırlar boyunca $[1\ 2\ 1]$ ile konvolüsyon: 11, 18, 18. Sonra sütun boyunca $[1\ 2\ 1]^T$ ile: $11 + 36 + 18 = 65$. İki yol da aynı sonucu verir (python ile kontrol edildi). Hoca doğrudan yolda 9 çarpma ve 9 toplama, ayrılmış yolda önce 6, sonra 3 çarpma saydı ve karmaşıklığın $n^2$'den $2n$'ye, yani $O(n)$'e düştüğünü söyledi.
  - Ders sonrası not: Tek bir merkez konumda satır adımındaki üç değeri (11, 18, 18) hesaplamak da 9 çarpma ister, yani kazanç tek konumda görünmez. Kazanç, filtre bütün görüntüde gezdirilip ara sonuçlar komşu piksellerce paylaşıldığında piksel başına $n^2$ yerine $2n$ çarpma olarak ortaya çıkar.

- **Ders sonrası notlar.**
  - Hoca ReLU'yu "girdiyi aynen yansıtan ama belli bir maksimum noktayla sınırlanan" fonksiyon diye tanıttı. Standart ReLU $\max(0,x)$'tir ve üstten sınırlı değildir (slayt da böyle verir, ekrandan, 01:50:00); üst sınırlı olanlar büyük olasılıkla ReLU6 gibi türevlerdir.
  - Bir öğrencinin "eğitim sırasında filtrelerin değeri değişir mi?" sorusuna hoca, filtrenin eğitim ortasında değiştirilemeyeceğini, başarı yetersizse filtre sayısı ve türünü değiştirip eğitimi yeniden başlatmak gerektiğini söyledi. Standart CNN'de filtre katsayıları (paylaşılan ağırlıklar) geri yayılımla öğrenilir; hocanın cevabı büyük olasılıkla filtre sayısı ve türü gibi mimari seçimler için geçerlidir.
  - Hoca matris çarpımı için "birinin satır sayısı diğerinin sütun sayısına eşit olmalı" dedi; $AB$ çarpımı için doğrusu $A$'nın sütun sayısının $B$'nin satır sayısına eşit olmasıdır.

- **Keskinleştirme maskesi (ekrandan, 01:35:00).** Slayttaki fikir yerel bölgelerdeki yoğunluk farklarını hesaplamaktır: maske $\tfrac19 \begin{bmatrix}-1&-1&-1\\-1&8&-1\\-1&-1&-1\end{bmatrix}$. Düz 10'luk bölgede $\tfrac19(-10\cdot8 + 80) = 0$ (gri düzeyde değişim yok); 10-80 geçişinin üstünde $\tfrac19(-10-80-80-10+640-80-10-80-80) = 210/9 > 0$ (değişim var). Python ile 210 toplamı doğrulandı. Hoca bu tür bir keskinleştirmenin bir yüz fotoğrafına uygulanmış halini gösterdi.

- **CIFAR-10 ve klasik ağ ile karşılaştırma.** Klasik ağlarda genelde 2-3 gizli katman kullanılır; yol uzadıkça geriye dönerken çarpma sayısı artar ve gradyan kaybolur. Bütün nöronların birbirine bağlı olması gereksiz işlem yükü getirir; CNN bu yüzden işlemsel olarak da daha hafiftir. CIFAR-10 küçük görüntüleri sayesinde yöntem denemek için hızlı eğitilebilen bir veri setidir. Slayttaki basit mimari [INPUT - CONV - RELU - POOL - FC] her katmanı birer kez kullanır ve yine başarılı sonuç verebilir (ekrandan, 01:45:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
