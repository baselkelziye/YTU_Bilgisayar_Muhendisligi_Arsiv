# Ders 7 Genişletilmiş Notu: Hough Dönüşümü, RANSAC ve İki Boyutlu Geometrik Dönüşümler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hough Dönüşümüne Giriş: Oylama ile Uydurma
- 2. Çizgi Bulma: (m, b) Parametrizasyonu ve Sorunu
- 3. Kutupsal Parametrizasyon: (ρ, θ)
- 4. Gürültü, Izgara Boyutu ve Sahte Zirveler
- 5. Gerçek İmgede Hough: Canny Kenarları Üzerinde Deney
- 6. Yönelimli Gradyanlarla Hızlandırılmış Hough
- 7. Çember Bulma
- 8. Hough Dönüşümünün Değerlendirmesi
- 9. RANSAC
- 10. Hizalama ve Global Parametrik Bükme
- 11. Temel İki Boyutlu Dönüşümler
- 12. Homojen Koordinatlar ve Öteleme
- 13. Afin Dönüşümler
- 14. Projektif Dönüşümler ve Serbestlik Derecesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Hough Dönüşümüne Giriş: Oylama ile Uydurma

Önceki derste en küçük kareler yöntemiyle uydurma ve ardından gürbüz en küçük kareler (robust least squares) görülmüştü. Bu derste sıradaki yöntem Hough dönüşümüdür (Hough transform). Hough dönüşümü de uydurma (fitting) ve hizalama (alignment) yöntemleri arasında sayılır.

Hough dönüşümünün özü bir oylama sistemidir. Oylamayla aranan nesnenin ya da nesnelerin imgede nerede olduğu çıkarılır. Oylamayı çok ayrıntılı yapmak hem zaman alır hem de "nereye nasıl oy verilecek" sorusunu zorlaştırır. Bu yüzden parametre uzayı bir ızgaraya (grid) bölünür, yani hücre hücre ayrılır, ve her hücre bir parametre değerini temsil eder. Hoca bunu "demokratik bir yöntem" diye niteledi.

Oyları kim verir? Uygulamada elde hangi veri varsa o verir. Örneğin elimizde Harris ile bulunmuş noktalar ve onların SIFT öznitelikleri olsun. En basit hâlde noktaların konumları kullanılır: elimizdeki her nokta, model parametreleri için oy verir. Hangi parametrelerin olduğu modele bağlıdır; çizgi arıyorsak çizginin parametreleri, çember arıyorsak çemberin parametreleri.

Slayttaki genel adımlar şöyledir (ekrandan, 00:20:00):

1. Parametre değerlerinden bir ızgara oluştur (create a grid of parameter values).
2. Her nokta bir parametre kümesine oy verir ve ızgarada bu değerleri artırır (each point votes for a set of parameters, incrementing those values in grid).
3. Izgarada maksimumu ya da yerel maksimumları bul (find maximum or local maxima in grid).

Hough dönüşümü ilk olarak çizgiler için önerilmiştir. Zamanla daire, elips gibi başka parametrik şekillere de uygulanmıştır. Harris noktaları ve SIFT öznitelikleriyle nesneleri birbiri üzerine eşleştirmekte kullanılan biçimine genelleştirilmiş Hough dönüşümü (generalized Hough transform) denir. Hoca genelleştirilmiş Hough dönüşümünde nesne parametrelerinin tam olarak ne olduğunu o anda hatırlayamadığını, slaytlarda rastlanırsa bakılacağını söyledi.

## 2. Çizgi Bulma: (m, b) Parametrizasyonu ve Sorunu

Orijinal Hough dönüşümü hocanın aktardığına göre 1959'da Hough tarafından önerilmiştir. Problem şudur: elimizde bir nokta kümesi (set of points) var; bu noktaları en iyi açıklayan çizgiyi bul.

Çizgiyi en doğal biçimde $y = mx + b$ ile yazabilir ve $m$ ile $b$'yi arayabiliriz. Bir çizgi üzerinde birkaç nokta olduğunu düşünelim. Bu noktalar $(m,b)$ ızgarasında oy verir. Çok sayıda nokta varsa belirli hücrelerdeki oy miktarı artar ve "burada bir çizgi var ya da olabilir" deriz.

> **Ders sonrası not:** Hoca her noktanın "m'sini ve b'sini hesaplayacağız" dedi. Tek bir noktanın tek bir $(m,b)$ değeri yoktur; bir $(x_i,y_i)$ noktası $b = -x_i m + y_i$ bağıntısını sağlayan bütün $(m,b)$ çiftlerine, yani parametre uzayında bir doğruya oy verir. Aynı çizgi üzerindeki noktaların bu doğruları ortak bir $(m,b)$ noktasında kesişir.

Hoca slayttaki oylama şeklinde çizgi tam düz değil de biraz eğikse oyların yan yana hücrelere dağılabileceğini yorumladı. Buradan önemli bir parametre çıkar: ızgara (grid) büyüklüğü. Çok küçük hücreler kullanılırsa tek bir çizgi birden fazla çizgiye dönüşebilir.

Asıl sorun ise $(m,b)$ parametre uzayının sınırsız olmasıdır. $m$ ve $b$ eksi sonsuzdan artı sonsuza kadar değer alabilir. Bu uzayı ızgaraya bölmek istesek elimizde yeterince hücre olmaz.

## 3. Kutupsal Parametrizasyon: (ρ, θ)

Hough'un çözümü kutupsal gösterime (polar representation) geçmektir. Çizginin imgeye göre bir $\theta$ açısı vardır. İmgenin sol üst köşesi merkez kabul edilirse merkezden çizgiye bir $\rho$ uzaklığı da vardır. Böylece bir çizgi $\rho$ ve $\theta$ cinsinden ifade edilebilir (ekrandan, 00:35:00):

$$x\cos\theta + y\sin\theta = \rho$$

Burada $x$ ve $y$ noktanın koordinatlarıdır. Hoca formülü akılda tutmak için "x kosinüsle çarpılır" ipucunu verdi.

Bu gösterimin üstünlüğü parametrelerin sınırlı olmasıdır. İmgenin boyutu $a \times b$ ise $\rho$ en fazla imgenin köşegeni kadar, yani $\sqrt{a^2+b^2}$ olur. $\theta$ da 0 ile 360 derece arasındadır. İkisi de sınırlı (bounded) olduğu için ızgara kurulabilir.

Hocanın verdiği ızgara örneği (ara adım eklendi):

- $\rho$ ekseni $[0, \sqrt{a^2+b^2}]$ aralığında 10 parçaya bölünür.
- $\theta$ ekseni 10'ar derecelik adımlarla $360/10 = 36$ parçaya bölünür.
- Toplam hücre sayısı $10 \times 36 = 360$ olur. Oylar bu 360 hücreye verilir.

### 3.1 Bir nokta nasıl oy verir?

Bir noktanın $x$ ve $y$'si bilinir, ama denklemde $\rho$ ve $\theta$ olmak üzere iki bilinmeyen vardır. İki bilinmeyenli tek bir denklem çözülemez. Bu yüzden $\theta$ 0'dan 360'a kadar örneğin 10'ar 10'ar artırılır; her $\theta$ için yeni bir $\rho$ hesaplanır ve o $(\rho,\theta)$ hücresine oy verilir. Böylece bir nokta için mecburen 30-40 farklı hücreye oy verilir.

Örneğin $\theta = 0$ için bir $\rho$ değeri bulunur ve o hücreye oy atılır; $\theta = 10$ için başka bir $\rho$, $\theta = 20$ için başka bir $\rho$ bulunur ve her birine oy atılır. Aynı çizgi üzerindeki ikinci nokta $(x_2,y_2)$ da aynı şekilde oy verdiğinde, iki noktanın ortak çizgisine karşılık gelen hücrede oy sayısı 1'den 2'ye çıkar; üçüncü noktayla 3 olur. Oy sayısı arttıkça "burada sanırım bir nesne var" denir.

Slayttaki çizimde bir noktanın verdiği oyların Hough uzayında bir eğri oluşturduğu görülür (ekrandan, 00:35:00). Sonraki noktalar da benzer eğriler çizer ve eğrilerin yoğunlaştığı yer çizginin parametrelerinin doğrudan görüldüğü yerdir. Hoca, şekilde $\theta$'nın mı yoksa $\rho$'nun mu değiştirildiğinin belli olmadığını, ama denklem $\rho$'yu hesaplamaya uygun olduğu için $\theta$'yı değiştirmenin daha mantıklı olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Sabit bir $(x,y)$ için $\rho(\theta) = x\cos\theta + y\sin\theta$ ifadesi $\sqrt{x^2+y^2}\cos(\theta-\varphi)$ biçiminde yazılabilir; bu yüzden her noktanın Hough uzayındaki izi sinüs biçimli bir eğridir. Pratikte $\theta$ çoğunlukla $[0,180)$ aralığında alınıp $\rho$'nun negatif olmasına izin verilir; $[0,360)$ ile $\rho \ge 0$ seçimi de aynı çizgi kümesini temsil eder.

## 4. Gürültü, Izgara Boyutu ve Sahte Zirveler

İmgelerle çalışırken veri genellikle gürültülüdür (noisy data). İmge piksellere bölündüğü için noktalar bir piksel kayabilir; aydınlanma değişir; noktalar zaten Harris gibi kendi hataları olan bulucularla çıkarılır. Sonuç olarak bir çizginin oyları tek hücrede toplanmaz, birbirine yakın hücrelere dağılır.

Bunun için iki yaklaşım konuşuldu:

- Bir noktanın yalnız kendi hücresine değil çevresindeki hücrelere de oy atması. Yer belirsiz olduğu için tam oraya değil çevresine de oy atılabilir; hocanın aktardığına göre genelleştirilmiş Hough dönüşümünde böyle yaklaşımlar vardır.
- Izgara boyutunun düzgün seçilmesi ve slaytın da önerdiği gibi birikeç üzerinde bir yumuşatma (smoothing) operatörünün uygulanması. Böylece doğru maksimum bulunabilir.

İkinci sorun sahte zirvelerdir (spurious peaks). Hoca "spurious" kelimesinin anlamını aratıp "sahte" karşılığına karar verdi. Slayttaki deneyde imge düzlemine düzgün dağılmış gürültü noktaları konmuştur; oy uzayında birçok eğri rastgele yerlerde kesişir (ekrandan, 00:40:00). Belirgin bir çizgi yoksa geriye kalan noktalar çizgi gibi görünebilir: iki nokta basit bir çizgi oluşturur, üç nokta bir başka çizgi oluşturur. Böylece birçok küçük alternatif zirve ortaya çıkar.

Hocanın aklına ilk gelen çözümler: bir eşik (threshold) koymak, yani bir zirvenin kabul edilmesi için en az bir oy sayısı istemek; bu en az oy sayısını da nokta sayısıyla ilişkilendirmek (bu kadar nokta varsa en az bu kadar oy olmalı gibi).

## 5. Gerçek İmgede Hough: Canny Kenarları Üzerinde Deney

Slayttaki deney şu akışla yapılmıştır: imge Canny kenar bulucusuna verilir, Canny'nin bulduğu kenar noktaları üzerinden Hough dönüşümü alınır, oy uzayında zirveler bulunur ve son işlem (post-process) yapılır. Hoca Canny'nin çok başarılı ve popüler bir kenar bulma algoritması olduğunu, ancak dersin slaytlarında bu konunun atlandığını belirtti.

Bina fotoğrafının Canny çıktısında çok sayıda kenar, "dünya kadar çizgi" vardır (ekrandan, 00:45:00). Hough dönüşümünün bulduğu çizgilerin bir kısmı iyidir. Ama örneğin üst kısımdaki bazı çizgiler bulunamamıştır; hocanın yorumuna göre oradaki renk geçişleri güçlü olmadığı için kenar bulmada da kenar olarak çıkmamışlardır. Bazı yerlerde ise çizgi gürültü yüzünden dümdüz değil hafif eğri bir hâl almıştır; düz çizgi arandığı için orası da bulunamamıştır.

Başka bir örnekte imgede boydan boya uzanan bir kafes vardır. Kafes çok sayıda gerçek doğru verir ve her doğru boydan boya uzandığı için bol oy alır; bu doğrular bulunmuştur. Bina fotoğrafında ise küçük küçük çok sayıda doğru vardır ve oy uzayında öne çıkan zirve azdır.

Sonuç: Hough dönüşümünün gerçek fotoğraflarda başarısı sınırlıdır ve kullanılan imgenin doğası önem kazanır.

## 6. Yönelimli Gradyanlarla Hızlandırılmış Hough

Hough dönüşümünde Canny gibi bir kenar bulucu kullanılıyorsa, kenar bulma sırasında genellikle Sobel benzeri bir türev operatörü kullanılır ve bu bize gradyanı verir. Harris'te de gradyan bilgisi vardır. Bu bilgi çöpe atılmayıp saklanırsa Hough dönüşümünde kullanılabilir.

> **Hocanın vurgusu:** Bu tür ayrıntıları yakalamak öğrenciler için zor olur ama sınavda sorulabilir; slaytlar ciddi düşünülerek ve ayrıntılı çalışılmalıdır.

Gradyanın $x$ yönündeki ve $y$ yönündeki bileşenleri (türevler) gradyanın yönünü verir. Bu yönelim bir açı olarak düşünülürse slayttaki ters tanjant (arktanjant) ifadesiyle $\theta$ hesaplanır. <!-- BELİRSİZ: slayttaki θ formülünün tam biçimi (hoca "negatif arktanjant" dedi) karelerde görülemedi. -->

$\theta$ bilindiğinde
$$\rho = x\cos\theta + y\sin\theta$$
ifadesinde $x$ ve $y$ de bilindiği için $\rho$ doğrudan hesaplanır. Artık bir nokta için 20-40 farklı $\theta$'ya oy vermek gerekmez; tek bir hücreye tek oy atılır.

> **Hocanın vurgusu:** $x\cos\theta + y\sin\theta = \rho$ formülünü sınav için bilmeniz gerekebilir.

Bu, değiştirilmiş (modified) bir Hough dönüşümüdür. Literatürde çok sayıda değiştirilmiş Hough dönüşümü vardır. Örneğin çok fazla nokta olduğunda ne yapılacağı düşünülmüş, olasılıksal (probabilistic) yöntemler geliştirilmiştir; hocanın aktardığına göre bunlarda oyların biriktiği birikeç benzeri bir yapı tutulur ve belirli koşulda bir nokta doğrudan seçilir.

Slayt Hough ile çizgi bulmayı şöyle özetler (ekrandan, 01:05:00):

- $m,b$ parametrizasyonu
- $r,\theta$ parametrizasyonu; yönelimli gradyanların kullanılması
- Pratik konular: bin boyutu, yumuşatma, birden fazla çizgi bulma, çizgi parçalarını bulma

**Soru:** Hough dönüşümünde çizginin başlangıç ve bitiş noktası elde edilmiyor; kısa bir çizgi parçası için uçlar nasıl bulunur?
**Cevap:** Hangi noktanın hangi çizgiye oy verdiği bilinir. Bu bilgi saklanırsa o çizgiye oy veren noktaların en küçüğü ile en büyüğü arasında çizgi parçası çizilebilir.

Hocanın aktardığına göre bu konu Szeliski'nin kitabında 6.1 bölümünde okunabilir.

## 7. Çember Bulma

Hoca öğrencilere, yarıçapı bilinen ya da bilinmeyen bir çemberin Hough ile nasıl bulunabileceğini sordu ve birlikte düşünüldü.

Çember denklemi, merkez orijinde ise $x^2 + y^2 = r^2$'dir. Merkez aranacağı için bir öğrencinin önerisiyle doğru biçim yazıldı:
$$(x - x_0)^2 + (y - y_0)^2 = r^2$$

Burada üç bilinmeyen vardır: $x_0$, $y_0$ ve $r$. Dolayısıyla birikeç iki boyutlu değil, üç boyutlu olmalıdır.

Bir öğrenci noktaların $x$ ve $y$ ortalamasının merkezi vereceğini önerdi. Hoca imgede birden fazla çember olabileceğini, üç çember çizerek gösterdi; bütün noktaların ortalamasını almak bu yüzden işe yaramaz, oylama gerekir.

Merkezin imgenin herhangi bir yerinde olabilmesi $x_0$ ve $y_0$'ın sınırlandırılması gerektiği tartışmasını açtı. Hoca merkezi de kutupsal koordinatlarla ($\rho,\theta$) parametrize etmeyi, sonra yarıçapı ayrı bir parametre olarak almayı düşündü. Bu durumda $\theta$ bilinmiyorsa, örneğin 36 farklı $\theta$ değeri ve her biri için ızgaraya bölünmüş $\rho$ ve $r$ değerleri için çok sayıda oy vermek gerekir; birikeç üç boyutlu olur ve parametre sayısı arttıkça birikecin boyut sayısı da artar. <!-- BELİRSİZ: hocanın kutupsal çember parametrizasyonu tartışması derste kesin bir sonuca bağlanmadı; oy sayısıyla ilgili "360 oy" hesabı altyazıda net değil. -->

Slayttaki yaklaşım ise şudur: her $(x, y, r)$ için karşılık gelen çemberi çiz ve onun desteğini (support), yani bu çembere denk gelen kenar noktalarını hesapla. Kenar yönelimi biliniyorsa işler kolaylaşır. Bir noktada çember varsa, kenar o noktada çembere teğettir ve gradyan yönü çemberin merkezini gösterir. Merkezin hangi tarafta olduğu bilinmediği için noktadan gradyan yönünde ve ters yönünde birer oy atılır. Gradyan birim uzunluğa indirgenmiştir (birim gradyan); bulunulan noktadan bu yönde $r$ kadar gidilirse merkeze ulaşılır. Hough parametre uzayı $(x, y, r)$ ile üç boyutludur.

> **Ek bilgi (derste anlatılmadı):** Birim gradyan $\hat{\mathbf{g}} = \nabla I / \lVert \nabla I \rVert$ ile gösterilirse, kenar noktası $\mathbf{p}$ için aday merkezler $\mathbf{p} \pm r\,\hat{\mathbf{g}}$'dir. Yarıçap bilinmiyorsa her $r$ değeri için bu iki noktaya oy verilir.

## 8. Hough Dönüşümünün Değerlendirmesi

Slayttaki değerlendirme (ekrandan, 01:25:00):

**İyi yanları**

- Aykırı değerlere (outlier) gürbüzdür: her nokta ayrı oy verir. Bir çizgi aranırken uzakta duran tek bir nokta kendi oyunu atar, ama çizgi üzerindeki noktalar birlikte oy verdiği için tek noktanın oyu toplamda anlam taşımaz.
- Oldukça (fairly) verimlidir: bütün parametre kümelerini denemekten çok daha hızlıdır. Hoca, birikecin boyutuna göre yavaş da kalabildiğini; 10-15 parametreli bir modelde 10-15 boyutlu bir uzayda maksimum arama ve maksimum olmayanı bastırma (non-max suppression) yapmak gerektiğini ekledi.
- Birden fazla iyi uyum verir: imgede iki farklı çizgi varsa ikisi de bulunabilir. Bina imgesinde birçok farklı çizgi bulunmuştu.

**Kötü yanları**

- Gürültüye bir miktar duyarlıdır.
- Bin boyutu gürültü toleransı, kesinlik ve hız/bellek arasında bir ödünleşimdir. Hücreler büyüdükçe daha az bellek kullanılır ve gürültüye tolerans artar ama kesinlik kaybolur. Doğru noktayı (sweet spot) bulmak zor olabilir.
- Birkaç parametreden fazlası için uygun değildir: ızgara boyutu parametre sayısıyla üstel büyür.

Hocanın üstel büyüme örneği (ara adım eklendi): her parametre 10 hücreye bölünürse

- 2 parametre: $10^2 = 100$ hücre,
- 3 parametre: $10^3 = 1000$ hücre,
- 4 parametre: $10^4 = 10\,000$ hücre.

Hücre sayısı arttıkça bellek sorunu çıkar. Ayrıca bu kocaman oy nesnesinin işlenmesi gerekir: üzerinden filtre geçirmek, maksimum olmayanı bastırmak gibi. Bu yüzden Hough az parametreli modeller için uygundur.

**Yaygın uygulamalar**

- Çizgi uydurma (çember, elips vb. de)
- Nesne örneği tanıma (object instance recognition): parametreler afin dönüşümdür
- Nesne kategorisi tanıma (object category recognition): parametreler konum ve ölçektir

Hoca "instance" için Türkçe "örnek" karşılığını aratıp seçti ve örnek ile kategori arasındaki ayrımı sınıfla tartıştı.

**Soru:** Kategori, farklı büyüklükteki dairelerin hangi gruba girdiğini; örnek ise kare, daire, üçgen gibi şekillerin tespiti olabilir mi?
**Cevap:** Hoca tersini düşündüğünü söyledi: kategori çizgi, elips, çember gibi şekil türleri olabilir; örnek ise resimde bulunan farklı boyutlardaki tek tek daireler gibi olabilir. Hoca slayttaki ayrımı tam anlamadığını da belirtti.

> **Ek bilgi (derste anlatılmadı):** Nesne örneği tanımada belirli bir nesnenin (örneğin belirli bir kitap kapağının) imgedeki görünümü aranır; bakış açısı değişimi afin dönüşümle modellendiği için parametreler afin dönüşüm parametreleridir. Kategori tanımada ise bir sınıfın (örneğin "araba") herhangi bir üyesi aranır; üyeler arasında biçim farkı büyük olduğu için çoğunlukla yalnız konum ve ölçek oylanır.

## 9. RANSAC

RANSAC (RANdom SAmple Consensus), 1981'de Fischler ve Bolles tarafından önerilmiştir (ekrandan, 01:30:00). Slayttaki tanıma göre, gözlenen verinin rastgele örneklenmesiyle bir modelin parametrelerini kestiren bir öğrenme tekniğidir. Hoca bu algoritmayı çok iyi bilmediğini, ileriki yıllarda ayrıntılı anlatılması için öğrenci konu listesine eklenebileceğini söyledi.

### 9.1 Algoritma

Slayttaki algoritma (ekrandan, 01:35:00):

1. **Örnekle (Sample):** Modeli uydurmak için gereken sayıda noktayı rastgele seç (çizgi için 2).
2. **Çöz (Solve):** Bu örneklerle model parametrelerini çöz.
3. **Puanla (Score):** Modelin önceden belirlenmiş bir eşiği içinde kalan iç noktaların (inlier) oranıyla puanla.

En iyi model yüksek güvenle bulunana kadar 1-3'ü tekrarla.

Hoca bunun çok fazla nokta olduğunda yapılacak bir şey olduğunu söyledi: elde 3-5 değil, belki on binlerce nokta vardır; örneğin üç boyutlu tarayıcıların oluşturduğu nokta bulutları.

Çizgi uydurma örneği:

- Rastgele iki nokta seçilir ve bunlardan bir çizgi uydurulur (bu, örneğin en küçük karelerle yapılabilir).
- Çizgiye $\delta$ uzaklığından yakın kaç nokta kaldığı sayılır. Slayttaki ilk denemede $N_I = 6$ iç nokta vardır.
- Başka iki nokta rastgele seçilir ve yeni çizgi uydurulur. Bu kez $\delta$ eşiği içinde 14 nokta kalır ($N_I = 14$).
- 14 iç noktalı model daha iyidir.

### 9.2 Parametrelerin seçimi

Slayttaki parametreler (ekrandan, 01:40:00):

- **Örneklenen nokta sayısı $s$:** Modeli uydurmak için gereken en az sayı. Çizgi iki noktayla belirlenir. Hocanın düşüncesine göre çember için üç nokta gerekir; üç noktayla çemberin parametreleri belirlenebilir.
- **Uzaklık eşiği $\delta$:** İyi bir noktanın yüzde 95 olasılıkla eşik içine düşeceği biçimde seçilir. Slaytta sıfır ortalamalı Gauss gürültüsü varsayımı geçer.
- **Örnek (deneme) sayısı $N$:** En az bir rastgele örneğin $p$ olasılıkla aykırı değerlerden arınmış olacağı biçimde seçilir (örneğin $p = 0.99$). $p$'yi kullanıcı kendisi belirler.

Slayttaki formül:
$$N = \frac{\log(1-p)}{\log\left(1-(1-e)^s\right)}$$

Burada $e$ aykırı değer oranıdır. Hoca slayta Szeliski'nin aynı formülü veren paragrafını da ekledi (ekrandan, 01:40:00): $p$ herhangi bir eşleşmenin geçerli olma olasılığı, $P$ $S$ denemeden sonraki toplam başarı olasılığı olsun. Bir denemede $k$ rastgele örneğin hepsinin iç nokta olma olasılığı $p^k$'dir. Bu yüzden bütün denemelerin başarısız olma olasılığı
$$1 - P = (1 - p^k)^S$$
ve gereken en az deneme sayısı
$$S = \frac{\log(1-P)}{\log(1-p^k)}$$
olur. İki gösterimde harfler farklıdır: slayttaki $1-e$, Szeliski'deki $p$'ye; slayttaki $p$, Szeliski'deki $P$'ye karşılık gelir.

Slayttaki tablo $p = 0.99$ için gereken $N$ değerlerini verir. Karede tablonun üst kısmı (başlık ve $s=2,3$ satırları) Szeliski metniyle örtülüdür; görünen satırlar aşağıdadır (ekrandan, 01:40:00). Sütunlar aykırı değer oranıdır; başlık ve ilk iki satır python ile formülden hesaplandı ve görünen satırların hepsi bu hesapla birebir tutuyor.

| $s$ | %5 | %10 | %20 | %25 | %30 | %40 | %50 |
|---|---|---|---|---|---|---|---|
| 2 (hesaplandı) | 2 | 3 | 5 | 6 | 7 | 11 | 17 |
| 3 (hesaplandı) | 3 | 4 | 7 | 9 | 11 | 19 | 35 |
| 4 | 3 | 5 | 9 | 13 | 17 | 34 | 72 |
| 5 | 4 | 6 | 12 | 17 | 26 | 57 | 146 |
| 6 | 4 | 7 | 16 | 24 | 37 | 97 | 293 |
| 7 | 4 | 8 | 20 | 33 | 54 | 163 | 588 |
| 8 | 5 | 9 | 26 | 44 | 78 | 272 | 1177 |

Hoca $s=2$ (çizgi) ve $p=0.99$ satırına bakarak yorum yapmaya çalıştı, ama ayrıntıların bir öğrenci tarafından anlatılmasının daha iyi olacağını, şimdilik genel fikrin bu olduğunu söyledi.

Formülün türetilişi (ara adım eklendi): bir denemede $s$ noktanın hepsinin iç nokta olma olasılığı $(1-e)^s$'dir. Bir denemenin başarısız olma (en az bir aykırı değer içerme) olasılığı $1-(1-e)^s$'dir. $N$ denemenin hepsinin başarısız olma olasılığı $\left(1-(1-e)^s\right)^N$ olur ve bu $1-p$'ye eşitlenir. İki tarafın logaritması alınınca yukarıdaki $N$ formülü çıkar; sonuç bir üst tam sayıya yuvarlanır.

### 9.3 RANSAC'ın değerlendirmesi

Slayttaki sonuçlar ve hocanın yorumları:

- **İyi:** Aykırı değerlere gürbüzdür, onlardan çok etkilenmez. Hough dönüşümüne göre daha fazla model parametresiyle uygulanabilir, çünkü birikeç biriktirme ve birikeç üzerinde arama yoktur; doğrudan hipotez oluşturulur ve daha iyisi olup olmadığına bakılır. Slayttaki optimizasyonla ilgili madde derste atlandı.
- **Kötü:** Hesaplama zamanı aykırı değer oranına ve parametre sayısına bağlı olarak hızla büyüyebilir. Birden fazla uyum bulmak için iyi değildir: bir imgede birden fazla çizgi aranacaksa iyi bir seçim değildir.
- **Yaygın kullanım:** Homografi hesaplama, yani imge birleştirme (image stitching): imgeler üst üste getirilir, birden fazla nesne aranmaz. Temel matrisin (fundamental matrix) kestirimi: iki ilişkili görünümü birbiriyle ilişkilendirip aralarında bir dönüşüm matrisi kurmak.

## 10. Hizalama ve Global Parametrik Bükme

Hizalama (alignment), bir nokta kümesini diğerine eşleyen modelin parametrelerini bulmaktır (find parameters of model that maps one set of points to another). Türkçesiyle "doğru hizaya getirme". Genellikle doğru eşleşmelerin çoğunu açıklayan global bir dönüşüm aranır.

Zorluklar:

- Gürültü (slaytta tipik olarak 1-3 piksel),
- Aykırı değerler, yani ortalamadan çok sapmış değerler (slaytta çoğu zaman yüzde 50),
- Çoktan bire eşleşmeler ya da birden fazla nesne: hizalanacak birden fazla nesne varsa hangisi hizalanacak?

### 10.1 Parametrik (global) bükme

Bir imgeye dönüşüm uygulamaya bükme (warping) denir. Bir imge bir $T$ dönüşümünden geçirildiğinde yeni bir imge elde edilir; bu sırada imgedeki noktaların, örneğin slayttaki kırmızı noktanın yeri de değişir (ekrandan, 01:45:00). $T$ bir fonksiyon gibi düşünülür: $p = (x,y)$ noktası verilince yeni yer $p' = (x',y')$ elde edilir. Slaytın deyişiyle dönüşüm bir koordinat değiştirme makinesidir:
$$p' = T(p)$$

$T$'nin global olması iki şey demektir:

- Her $p$ noktası için aynıdır.
- Yalnızca birkaç sayıyla (parametreyle) tarif edilebilir.

Dönüşüm doğrusal ise $T$ bir matrisle çarpım olarak düşünülebilir:
$$p' = \mathbf{T}p, \qquad \begin{bmatrix}x'\\y'\end{bmatrix} = \mathbf{T}\begin{bmatrix}x\\y\end{bmatrix}$$

## 11. Temel İki Boyutlu Dönüşümler

### 11.1 Yaygın dönüşümler

Slaytta bir ev fotoğrafı üzerinde yaygın dönüşümler gösterilir (ekrandan, 02:05:00):

- **Öteleme (translation):** İmgedeki nesnelerin imgede yer değiştirmesi. Piksel renkleri aynı kalır, yalnız aşağı ya da sağa sola taşınır. Hoca örnekte ötelemenin çok az olduğunu, birkaç piksel olabileceğini belirtti.
- **Dönme (rotation):** Nesnenin döndürülmesi.
- **En-boy (aspect):** Bir tür ölçekleme. Bir eksendeki ölçek diğerine göre küçültülünce yaklaşık kare olan imgenin en-boy oranı değişir.
- **Afin (affine)**
- **Perspektif (perspective):** Afinden daha karmaşık bir dönüşüm.

Hoca afin dönüşümde paralelliğin korunduğunu, yani dönüşümden önce paralel olan çizgilerin sonra da paralel kaldığını; perspektif dönüşümün ise çizgilerin paralelliğini de bozabildiğini söyledi. Dönüşüm karmaşıklaştıkça matristeki sayıların miktarı da artar, çünkü her yeni değişimi tarif eden yeni sayılar gerekir.

> **Ders sonrası not:** Hoca öteleme, ölçekleme ve dönmenin üçünü birden içeren (RST) dönüşümlere afin dönüşüm dediğini söyledi. Öteleme, dönme ve tekdüze ölçeklemenin birleşimine aslında benzerlik (similarity) dönüşümü denir; afin dönüşüm bunlara ek olarak kayma ve tekdüze olmayan ölçeklemeyi de içerir. Hoca dersin ilerleyen kısmında afin dönüşümün ölçekleme, dönme, öteleme ve kaymayı içerdiğini söyledi.

### 11.2 Ölçekleme

Bir koordinatı ölçeklemek, her bileşenini bir skalerle çarpmak demektir. Tekdüze (uniform) ölçeklemede bu skaler bütün bileşenler için aynıdır (ekrandan, 02:05:00).

Hocanın örneği: $x = 2$, $y = 1$ olan nokta 2 ile ölçeklenirse

- yeni $x = 2 \cdot 2 = 4$,
- yeni $y = 2 \cdot 1 = 2$,

nokta $(4, 2)$ olur, yani koordinatlar iki katına çıkar.

Tekdüze olmayan (non-uniform) ölçeklemede her bileşen farklı skalerle çarpılır; örneğin $x$ 2 ile, $y$ 0.5 ile. Bu, en-boy oranını değiştiren dönüşümdür. Hoca tek bir nokta üzerinde dönüşümün görsel olarak pek bir şey ifade etmediğini, birkaç nokta üzerinde düşünüldüğünde anlam kazandığını belirtti.

Denklem sistemi şöyledir: $x' = a x$, $y' = b y$. Bunu matrisle yazmak istiyoruz. Matrisle çalışmanın üstünlükleri:

- Bilgisayar grafiğinde de geçerli olduğu gibi GPU, TPU gibi hızlandırıcılar matris çarpımını hızlandırmak için geliştirilmiştir; matrislerle çalışmak çok hızlı işlem sağlar.
- Matris biçiminde yazıldığında matematiksel ifadeler bir süre sonra daha basit ve anlaşılır olur, matrisler üzerinde çeşitli algoritmik işlemler yapılabilir.

Matrisi kurmak için yalnızca "hangi matris bana bu denklemi verir" diye düşünmek yeterlidir. $x'$ elde edilirken $x$, $a$ ile çarpılır; denklemde $y$ olmadığı için $y$ ile çarpılacak yere 0 konur. $y'$ için de $x$'in yerine 0 konur:
$$\begin{bmatrix}x'\\y'\end{bmatrix} = \begin{bmatrix}s_x & 0\\ 0 & s_y\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}$$

Ölçekleme matrisinde değerler köşegendedir, diğer yerler sıfırdır (ekrandan, 02:20:00).

Hoca ölçeklemenin tersini düşünmeyi ödev olarak bıraktı ve tersin $1/a$ ile yapılacağını söyledi.

### 11.3 İki boyutlu dönme

$(x,y)$ noktasını $\theta$ açısı kadar döndürüp $(x',y')$ noktasına götüren dönme şu denklemlerle verilir (ekrandan, 02:10:00):
$$x' = x\cos\theta - y\sin\theta$$
$$y' = x\sin\theta + y\cos\theta$$

Hoca bu denklemlerin elde edilmesinin zor olmadığını, kutupsal koordinatlara geçmek gerektiğini anlattı. Noktanın yatay eksenle yaptığı açıya $\alpha$, orijine uzaklığına $r$ denirse $x' = r\cos(\theta+\alpha)$ ve $y' = r\sin(\theta+\alpha)$ olur. Toplam açı özdeşlikleri kullanılıp $r$ ve $\alpha$ yok edilerek denklemler bulunur. Hoca bunun evde yapılabilecek keyifli bir egzersiz olduğunu söyledi (çözüm Örnek Sorular bölümündedir).

Bu denklemler matris çarpımı olarak yazılır. Katsayılar, $x$ ilk sütunla, $y$ ikinci sütunla çarpılacak biçimde yerleştirilir (ekrandan, 02:15:00):
$$\begin{bmatrix}x'\\y'\end{bmatrix} = \underbrace{\begin{bmatrix}\cos\theta & -\sin\theta\\ \sin\theta & \cos\theta\end{bmatrix}}_{\mathbf{R}}\begin{bmatrix}x\\y\end{bmatrix}$$

Köşegende $\cos\theta$, ters köşegende $\sin\theta$ vardır; üstteki $-\sin\theta$'dır.

Slayttaki not: $\sin\theta$ ve $\cos\theta$, $\theta$'nın doğrusal olmayan fonksiyonları olsa da $x'$ ve $y'$, $x$ ile $y$'nin doğrusal birleşimidir. Dolayısıyla dönme doğrusal bir dönüşümdür.

**Ters dönüşüm:** $(x',y')$'den $(x,y)$'ye götüren dönüşüm, aynı denklemde $\theta$ yerine $-\theta$ konarak elde edilir. Yerine konup denendiğinde ters dönüşümün $\mathbf{R}$'nin devriği (transpozu) olduğu görülür: üstteki eleman $\sin\theta$, alttaki $-\sin\theta$ olur.
$$\mathbf{R}^{-1} = \mathbf{R}^T$$

Dönme matrislerinin bu özelliği sayesinde ters dönüşüm devrik alınarak bulunur (python ile $\theta = 30^\circ$ için doğrulandı).

### 11.4 Kayma (shear)

Slayttaki temel iki boyutlu dönüşümler listesinde kayma şöyledir (ekrandan, 02:20:00):
$$\begin{bmatrix}x'\\y'\end{bmatrix} = \begin{bmatrix}1 & \alpha_x\\ \alpha_y & 1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}$$

Hoca kaymayı iki nokta üzerinden gösterdi: dikey bir doğru üzerindeki iki nokta kayma uygulanınca çapraz bir doğruya eşlenir, doğru üzerindeki noktalar da bu çapraz doğru üzerinde yer alır. Kare biçimli bir nesneye $x$ yönünde kayma uygulanırsa üst kenarı yana kayar ve nesne eğik bir paralelkenara dönüşür. $y$ yönünde kayma da düşünülebilir; hoca bunu "tepesinden ve alttan tutup çekmek" diye benzetti.

## 12. Homojen Koordinatlar ve Öteleme

Öteleme nesnenin yerini değiştirir: nesne olduğu gibi başka bir yere taşınır. $x$ yönündeki öteleme $t_x$, $y$ yönündeki $t_y$'dir. Elde edilmek istenen:
$$x' = x + t_x, \qquad y' = y + t_y$$

Hoca diğer dönüşümlerden farkı sordu: 2x2'lik bir matris bu iş için yetmez. Neden? Burada orijinal $x$'i bir sayıyla toplamak istiyoruz. Bu işi yapacak bir matris arandığında $x'$ satırı şöyle düşünülür (ekrandan, 02:25:00):
$$x' = 1\cdot x + 0\cdot y + t_x \cdot 1$$

$x$'in katsayısı için bir bileşen, $y$'nin katsayısı için bir bileşen, $t_x$ için de bir bileşen gerekir; matrisin üç sütunu olmalıdır. Üçüncü bileşenle çarpılacak şey ne $x$ ne $y$'dir; o 1'dir. $(x,y)$ vektörünün altına 1 eklenir ve $t_x$ bu 1 ile çarpılınca sabit terim elde edilir. Aynı mantık $y$ için de yürütülür:
$$\begin{bmatrix}x'\\y'\end{bmatrix} = \begin{bmatrix}1 & 0 & t_x\\ 0 & 1 & t_y\end{bmatrix}\begin{bmatrix}x\\y\\1\end{bmatrix}$$

İki boyutta çalışırken bu matriste en az üç sütun, üç boyutta en az dört sütun gerekir. Hoca üç boyutlu grafik programlamada da aynı durumun ortaya çıktığını belirtti.

Buna homojen koordinatlar (homogeneous coordinates) denir: normalde $x$ ve $y$ vardır, ama bir bileşen daha eklenir ve bu 1'dir. Son bileşen 1 değil de örneğin 10 olursa bütün bileşenler 10'a bölünerek son bileşen tekrar 1 yapılır; böylece 1'in eklenmediği durumdaki $x$ ve $y$ elde edilir.

## 13. Afin Dönüşümler

Ölçekleme, dönme, öteleme ve kaymanın dördünü birden içeren bir matris elde edilebilir; buna afin dönüşüm denir. Öteleme de içerildiği için homojen koordinatlara geçmek burada da gereklidir.

Slayttaki tanıma göre afin dönüşümler, doğrusal dönüşümler ile ötelemenin birleşimidir. Özellikleri:

- Çizgiler çizgilere eşlenir.
- Paralel çizgiler paralel kalır.
- Oranlar korunur. Hocanın yorumu: bir parçanın diğerine oranı yeni resimde de aynı kalır.
- Birleşme altında kapalıdır (closed under composition).

Hoca "birleşme altında kapalı" ifadesinin, birden fazla afin dönüşüm art arda uygulandığında elde edilen dönüşümün yine afin olması anlamına geldiğini tahmin etti ve Wikipedia'daki "Affine transformation" maddesine bakarak doğruladı (ekrandan, 02:30:00). Maddeye göre $X$ bir afin uzayın nokta kümesiyse $X$ üzerindeki her afin dönüşüm, $X$ üzerinde bir doğrusal dönüşüm ile bir ötelemenin birleşimi olarak gösterilebilir. Dönme, ölçekleme ve kayma doğrusaldır, öteleme doğrusal değildir; afin dönüşüm bunların birleşiminden oluşur. Maddedeki örnekler: öteleme, ölçekleme, homoteti, benzerlik, yansıma, dönme, kayma eşlemesi ve bunların her türlü birleşimi. Hoca homoteti, benzerlik ve yansımanın görülen dönüşümlerin özel biçimleri olabileceğini, üzerinde durmaya gerek görmediğini söyledi. Maddede ayrıca "ötelemeler afin dönüşümdür ve afin dönüşümlerin birleşimi bir afin dönüşümdür" cümlesi geçer.

Birleşme şöyle düşünülür: $(x,y)$'ye önce bir afin $T_2$ dönüşümü, sonra bir afin $T_1$ dönüşümü uygulanırsa elde edilen dönüşüm de afindir. Dönüşüm illa matrisle gösterilmek zorunda değildir, fonksiyon olarak da gösterilebilir.

## 14. Projektif Dönüşümler ve Serbestlik Derecesi

### 14.1 Tanım

Projektif dönüşümlerde afin dönüşümdeki kısım ($a, b, c, d, e, f$) aynen vardır; ek olarak alt satır $(g, h, i)$ eklenir ve vektörler $(x, y, w)$ olur (ekrandan, 02:35:00):
$$\begin{bmatrix}x'\\y'\\w'\end{bmatrix} = \begin{bmatrix}a & b & c\\ d & e & f\\ g & h & i\end{bmatrix}\begin{bmatrix}x\\y\\w\end{bmatrix}$$

Giriş vektöründe $w = 1$ alınsa bile sonuçtaki $w'$ 1 olmayabilir. Onu 1'e denk düşürmek için bütün değerler $w'$'ye bölünür; böylece elde edilen sonuç homojen olmayan koordinatlara çevrilir.

Slayttaki tanım ve özellikler:

- Projektif dönüşümler, afin dönüşümler ile projektif bükmelerin (projective warps) birleşimidir.
- Çizgiler çizgilere eşlenir.
- Paralel çizgiler paralel kalmayabilir.
- Oranlar korunmaz.
- Birleşme altında kapalıdır: art arda iki projektif dönüşüm yine projektif dönüşümdür.
- Taban değişimini (change of basis) modeller.
- Projektif matris bir ölçeğe kadar tanımlıdır (8 serbestlik derecesi, DOF).

### 14.2 Taban değişimi

Hoca taban değişimini bir çizimle anlattı (ekrandan, 02:40:00). Bir noktanın konumundan söz etmek için bir koordinat sistemi merkezi ve bu merkezde taban vektörleri düşünmek gerekir; günlük hayatta bunu $x$, $y$, $z$ eksenleri olarak oturtmuşuzdur. Ama koordinat sistemi başka bir yere de konabilir. Örneğin merkezi $Q$ olan bir koordinat sistemi ve onun $u$, $v$, $k$ taban vektörleri olsun.

Bu taban vektörlerinin birbirine dik ya da eşit uzunlukta olması gerekmez, ama doğrusal bağımsız olmaları gerekir. Doğrusal bağımsızlık, $u$ ve $v$'yi çeşitli sayılarla çarpıp toplayarak $k$'nin elde edilememesi demektir.

Noktanın konumu bu yeni sisteme göre de tarif edilebilir: $Q$'dan $u$ yönünde $t_u$ kadar, sonra $v$ yönünde $t_v$ kadar, sonra $k$ yönünde $t_k$ kadar gidilirse noktaya ulaşılır. Bu koordinat sisteminde noktanın yeri $(t_u, t_v, t_k)$'dir.

Bilgisayar grafiğinde bu çok kullanılır: model dünyasından oyun dünyasına geçilir (oyun dünyasının merkezi farklıdır), oradan kamera tabanına geçilir (kameranın merkezi ve tabanı farklıdır ve kamera sürekli hareket ettirilebilir), kameradan da ekran koordinatlarına geçilir. Projektif dönüşümler bu taban değişimlerini modelleyebilir. Hoca bu bilginin bu derste çok gerekli olmayabileceğini söyledi.

### 14.3 Serbestlik derecesi

Slayttaki "projektif matris bir ölçeğe kadar tanımlıdır (8 DOF)" ifadesi üzerine hoca, serbestlik derecesinin (degrees of freedom) matriste bağımsız olarak değişebilen değerlerin sayısı olduğunu söyledi. 3x3 matriste 9 değer olmasına rağmen 8 serbestlik derecesi olmasının nedenini internette aradı (homografiyle çok ilgili olduğunu gördü) ve bunun bir elemanın 1 olarak sabitlenebilmesiyle ilgili olduğunu, bu yüzden 9 değil 8 olduğunu düşündüğünü söyledi; tam tatmin edici bir açıklama bulunamadı.

Bakılan bir başka kaynakta (Carnegie Mellon ders slaytları) serbestlik dereceleri tartışılmıştır (ekrandan, 02:45:00): öteleme matrisinde yalnız $t_1$ ve $t_2$ değiştiği için serbestlik derecesi 2'dir. Hoca dönme ve öteleme birlikte olduğunda önce 6 dedi, sonra dönme için tek parametre $\theta$ olduğunu görerek 3 dedi ve doğru söyleyip söylemediğini sordu. Kaynak bir sonraki dönüşüme benzerlik (similarity) dönüşümü diyor ve projektif dönüşümün serbestlik derecesini 8 olarak veriyor, ama nedenini açıklamıyor.

> **Ders sonrası not:** İki boyutta dönme ve öteleme birlikte (katı cisim, Öklid dönüşümü) 3 serbestlik derecesine sahiptir: $\theta$, $t_x$, $t_y$. 6 sayısı afin dönüşüme aittir ($a,\dots,f$). Benzerlik dönüşümüne bir ölçek eklenir ve 4 olur. Projektif matrisin 9 elemanı vardır, ama matris sıfırdan farklı bir sayıyla çarpılınca aynı dönüşümü verdiği için (homojen koordinatlarda sonuç $w'$'ye bölünür) bir serbestlik düşer ve 8 kalır.

Hoca sonunda Szeliski'de de bulunan, dönüşümleri satır satır özetleyen bir referans tablosu gösterdi ve "öteleme için nasıl çözülür" (solving for translation) kısmının önemli olduğunu ama bir sonraki derse kaldığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Szeliski'nin iki boyutlu dönüşüm tablosunda büyük olasılıkla şu hiyerarşi yer alır: öteleme (2 DOF, yönelim korunur), katı/Öklid (3 DOF, uzunluklar korunur), benzerlik (4 DOF, açılar korunur), afin (6 DOF, paralellik korunur), projektif (8 DOF, düz çizgiler korunur).

## Örnek Sorular

**Soru 1** (derste sözlü, 01:06:05): Yarıçapı bilinmeyen bir çember Hough dönüşümüyle nasıl bulunur? Kenar gradyanları biliniyorsa ne değişir?

> **Cevap (derste tartışıldı):** Çember $(x-x_0)^2+(y-y_0)^2=r^2$ ile üç parametrelidir, birikeç $(x_0, y_0, r)$ üzerinde üç boyutludur. Noktaların ortalamasını almak birden fazla çember olabileceği için işe yaramaz. Kenar yönelimi biliniyorsa her kenar noktası, her $r$ değeri için birim gradyan yönünde ve ters yönünde $r$ uzaklıktaki iki aday merkeze oy verir.

**Soru 2** (derste sözlü, 01:17:37): Hough dönüşümü bir çizginin yalnız $(\rho,\theta)$ parametrelerini verir. Kısa bir çizgi parçasının başlangıç ve bitiş noktaları nasıl bulunur?

> **Cevap (derste verildi):** Hangi noktanın hangi çizgiye oy verdiği saklanır. O çizgiye oy veren noktaların en küçüğü ile en büyüğü arasında parça çizilir.

**Soru 3** (derste sözlü, 00:40:31): Düzgün dağılmış gürültü Hough uzayında sahte zirveler üretir. Bunun için ne yapılabilir?

> **Cevap (derste verildi, hocanın önerisi):** Bir zirvenin kabulü için en az oy eşiği konur ve bu eşik nokta sayısıyla ilişkilendirilir. Ayrıca bin boyutu uygun seçilir ve birikeç yumuşatılır.

**Soru 4** (ekrandan, 01:40:00): Slayttaki tabloya göre $p=0.99$ iken bir çizgi ($s=2$) için aykırı değer oranı yüzde 50 olduğunda en az kaç RANSAC denemesi gerekir? Aynı oranda $s=4$ için kaç deneme gerekir?

> **Çözüm (derste verilmedi):** $N=\log(1-p)/\log(1-(1-e)^s)$.
> $s=2$: $(1-0.5)^2=0.25$, $N=\log(0.01)/\log(0.75)=-4.605/-0.2877\approx 16.01$, yukarı yuvarlanınca $N=17$.
> $s=4$: $(0.5)^4=0.0625$, $N=\log(0.01)/\log(0.9375)=-4.605/-0.06454\approx 71.4$, yukarı yuvarlanınca $N=72$ (karedeki tabloyla aynı). Değerler python ile hesaplandı.

**Soru 5** (derste sözlü, 02:05:31): $(2,1)$ noktası 2 ile tekdüze ölçeklenirse yeni nokta nedir? $x$ 2 ile, $y$ 0.5 ile ölçeklenirse ne olur?

> **Cevap:** Tekdüze ölçeklemede $(4,2)$ (derste verildi). Tekdüze olmayan ölçeklemede $\begin{bmatrix}2&0\\0&0.5\end{bmatrix}\begin{bmatrix}2\\1\end{bmatrix}=\begin{bmatrix}4\\0.5\end{bmatrix}$ (derste verilmedi, python ile doğrulandı).

**Soru 6** (derste sözlü, 02:13:08): Dönme denklemlerini $x'=x\cos\theta-y\sin\theta$, $y'=x\sin\theta+y\cos\theta$ kutupsal koordinatlarla ispatlayın.

> **Çözüm (derste verilmedi):** $x = r\cos\alpha$, $y = r\sin\alpha$ olsun. $\theta$ kadar dönen noktada $x' = r\cos(\theta+\alpha) = r\cos\theta\cos\alpha - r\sin\theta\sin\alpha = x\cos\theta - y\sin\theta$. Benzer biçimde $y' = r\sin(\theta+\alpha) = r\sin\theta\cos\alpha + r\cos\theta\sin\alpha = x\sin\theta + y\cos\theta$.

**Soru 7** (derste sözlü, 02:17:05): Ölçeklemenin ve dönmenin ters dönüşümleri nedir?

> **Cevap:** Dönmenin tersi $-\theta$ ile dönmedir ve $\mathbf{R}^{-1}=\mathbf{R}^T$ (derste verildi). Ölçeklemenin tersi $\begin{bmatrix}1/s_x&0\\0&1/s_y\end{bmatrix}$'dir (hoca $1/a$ olduğunu söyleyip düşünmeyi ödev olarak bıraktı).

**Soru 8** (derste sözlü, 02:21:06): Öteleme neden 2x2'lik bir matrisle yazılamaz?

> **Cevap (derste verildi):** $x'=x+t_x$ bir sabit terim içerir; 2x2 matris yalnız $x$ ve $y$'nin doğrusal birleşimini üretir. Vektöre 1 eklenir (homojen koordinatlar) ve matrise $t_x$, $t_y$'yi içeren üçüncü bir sütun konur.

**Soru 9** (ekrandan, 02:45:00): Projektif dönüşümün serbestlik derecesi kaçtır ve neden?

> **Çözüm (derste tam verilmedi):** 8'dir. 3x3 matriste 9 eleman vardır, ama $\mathbf{H}$ ile $\lambda\mathbf{H}$ ($\lambda\neq 0$) aynı dönüşümü verir, çünkü sonuç $w'$'ye bölünür. Bu ölçek belirsizliği bir serbestlik derecesini götürür: $9-1=8$.

## Dersin Toparlaması

Bu derste uydurma ve hizalama yöntemlerinin iki önemli üyesi görüldü. Hough dönüşümü, her veri noktasının parametre ızgarasındaki hücrelere oy verdiği bir yöntemdir. Çizgiler için sınırsız $(m,b)$ uzayı yerine sınırlı $(\rho,\theta)$ uzayı ve $x\cos\theta + y\sin\theta = \rho$ denklemi kullanılır. Gradyan yönü biliniyorsa her nokta tek oy verir. Çemberlerde birikeç üç boyutlu olur. Hough aykırı değerlere gürbüzdür ve birden fazla nesne bulabilir; ama bin boyutu seçimi zordur ve parametre sayısı arttıkça ızgara üstel büyür. RANSAC ise az sayıda noktadan rastgele hipotezler kurup iç nokta sayısıyla puanlar. Daha çok parametreli modellere uygulanabilir ve homografi ile temel matris kestiriminde kullanılır, ama birden fazla uyum bulmakta zayıftır.

Dersin ikinci yarısında hizalamanın temelini oluşturan global parametrik dönüşümler ele alındı. Ölçekleme, dönme ve kayma 2x2 matrislerle, öteleme ise homojen koordinatlarla yazıldı. Afin dönüşümler paralelliği ve oranları korur; projektif dönüşümler yalnız çizgileri korur ve bir ölçeğe kadar tanımlı oldukları için 8 serbestlik derecesine sahiptir. Eşleşen noktalardan bu dönüşümlerin (önce öteleme) nasıl çözüleceği bir sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
