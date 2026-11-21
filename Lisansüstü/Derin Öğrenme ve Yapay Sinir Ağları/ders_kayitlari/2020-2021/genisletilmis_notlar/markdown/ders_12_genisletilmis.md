# Ders 12 Genişletilmiş Notu: Konvolüsyon Tekrarı, ReLU Türevleri, Aşırı Öğrenme ve Düzenlileştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Konvolüsyon İşleminin Tekrarı
- 2. Normal Sinir Ağları ile CNN Karşılaştırması
- 3. CIFAR-10 için Örnek CNN Mimarisi ve Boyutlar
- 4. ReLU, Ölü Nöronlar, Leaky ReLU ve Maxout
- 5. Underfitting ve Overfitting
- 6. Overfitting'in Nedenleri ve Çapraz Doğrulama
- 7. Overfitting'e Karşı Yöntemler: Düzenlileştirme, Max Norm ve Dropout
- 8. Ev Fiyatı Örneği ile Düzenlileştirme
- 9. Düzenlileştirilmiş Maliyet Fonksiyonu ve $\lambda$ Seçimi
- 10. L1 ve L2 Düzenlileştirme ve Gradyan İniş Güncellemesi
- 11. Lojistik Regresyonda Underfitting ve Overfitting, Bias ve Varyans
- 12. Pratik Öneriler: Özellik Azaltma, Aykırı Değerler ve Eğitimi Durdurma
- Örnek Sorular

## 1. Konvolüsyon İşleminin Tekrarı

Bir önceki derste korelasyon ve konvolüsyon ile bunların birbiriyle ilişkisi konuşulmuştu. Hoca bu derse o konuyu kısaca tamamlayarak başladı, çünkü konvolüsyonda sık hata yapıldığını ve bunu tekrar tekrar vurgulamak istediğini söyledi.

Konvolüsyon, korelasyonla aynı işlemdir; tek farkı maskenin (filtrenin) hem yatay hem dikey yönde döndürülmesidir. Yani konvolüsyon, filtreyi alıp doğrudan noktasal çarpım yapmak değildir. Slayttaki örnekte (ekrandan, 00:05:00):

$$
\begin{bmatrix}1&2&3\\4&5&6\\7&8&9\end{bmatrix}
\xrightarrow{\;H\;}
\begin{bmatrix}7&8&9\\4&5&6\\1&2&3\end{bmatrix}
\xrightarrow{\;V\;}
\begin{bmatrix}9&8&7\\6&5&4\\3&2&1\end{bmatrix}
$$

Sonuçta maske merkezine göre $180^\circ$ dönmüş olur. Konvolüsyon formülü slaytta şöyle verildi (ekrandan, 00:05:00):

$$
g(i,j)=\sum_{k=-n/2}^{n/2}\sum_{l=-n/2}^{n/2} h(k,l)\,f(i-k,\,j-l)=\sum_{k=-n/2}^{n/2}\sum_{l=-n/2}^{n/2} h(i-k,\,j-l)\,f(k,l)
$$

Simetrik maskelerde, yani $h(i,j)=h(-i,-j)$ olduğunda, konvolüsyon korelasyona eşittir. Gösterim olarak $h * f = f * h$ yazılır.

> **Hocanın vurgusu:** Örneklerde çoğunlukla filtrenin zaten döndürülmüş hali verildiği için insanlar bu döndürme adımının farkında olmuyor. Belli bir işi yapan bir filtre seçtiyseniz, konvolüsyon için onu mutlaka döndürerek uygularsınız.

### 1.1 Filtreyi Çarpanlarına Ayırarak Yükü Azaltmak

Hoca, algoritmanın karmaşıklığını ve derin öğrenmedeki hesap yükünü azaltmak için konuşulan bir yöntemi hatırlattı: Filtre çarpanlarına ayrılabiliyorsa, örneğin $3\times3$'lük bir filtre $3\times1$'lik iki vektörün çarpımı olarak yazılabiliyorsa, iki boyutlu tek bir filtre yerine iki tek boyutlu filtre art arda uygulanır. Böylece işlem sayısı $n$ mertebesine düşürülebilmişti.

<!-- BELİRSİZ: Altyazıda bu karmaşıklık cümlesinin başı kopuk ("...ene düşürebilmiştik"); karmaşıklığın tam ifadesi önceki derste kalmış olabilir. -->

> **Ek bilgi (derste anlatılmadı):** $n\times n$'lik ayrılabilir bir filtre, bir sütun vektörü ile bir satır vektörünün dış çarpımı olarak yazılabilir. Bu durumda piksel başına $n^2$ çarpma yerine önce satır, sonra sütun yönünde toplam $2n$ çarpma yapılır; derste söylenen "$n$'e düşürme" büyük olasılıkla bunu kastediyor.

### 1.2 Farklı Filtreler, Farklı Katmanlar

Görüntü üzerinde çalışılıyorsa, ihtiyaca göre (örneğin kenar belirleme gerekiyorsa) farklı filtrelerle farklı konvolüsyon katmanları oluşturulabilir.

## 2. Normal Sinir Ağları ile CNN Karşılaştırması

Ardından bir konvolüsyonel ağda görüntü boyutunun ve ağ boyunca yapılan işlemler sırasında boyutların nasıl değiştiğine yeniden bakıldı. Örnek veri seti CIFAR-10'dur. Slayttaki noktalar şunlardır (ekrandan, 00:15:00):

- Normal sinir ağları tam görüntülere iyi ölçeklenmez. CIFAR-10'da görüntüler yalnızca $32\times32\times3$ boyutundadır (32 genişlik, 32 yükseklik, 3 renk kanalı: RGB).
- Bu yüzden normal bir sinir ağının ilk gizli katmanındaki tam bağlantılı tek bir nöronun $32\cdot32\cdot3=3072$ ağırlığı olur.
- Bu miktar hâlâ yönetilebilir görünür, ama bu tam bağlantılı yapı büyük görüntülere ölçeklenmez.
- Örneğin $200\times200\times3$ boyutunda daha makul bir görüntü, $200\cdot200\cdot3=120\,000$ ağırlıklı nöronlara yol açar. Üstelik bu nöronlardan birkaç tane isteneceği için parametre sayısı hızla artar.
- Bu tam bağlantı israftır ve çok sayıdaki parametre hızla aşırı öğrenmeye (overfitting) götürür.

Hoca, konvolüsyonel ağda filtrenin giriş nöronlarının yalnız belli bir kısmına uygulandığını, dolayısıyla her şeyin her şeye bağlı olmadığını hatırlattı. Böylece filtrenin boyutuyla da ilişkili olarak boyut daha en baştan bir kez azaltılmış olur.

Slayttaki şekilde solda üç katmanlı normal bir çok katmanlı algılayıcı (MLP), sağda kabaca bir konvolüsyonel ağ çizimi vardı. MLP'de her kademede hesaplanacak ağırlık sayısı kullanılan nöron sayısıyla ilişkili olarak artar. Konvolüsyonel ağda ise girişteki $32\times32$'lik görüntüye üç renk kanalı bir derinlik boyutu ekler; ama işlem bölüm bölüm uygulandığı için hesap azalır. Bunun ardından, ReLU uygulandıktan sonra bir havuzlama (pooling) katmanı gelir ve boyut orada bir kez daha düşürülür. Sonuç olarak klasik bir MLP'yi gizli katmanlar ekleyerek derinleştirmek yerine konvolüsyonel ağ kullanmak, boyutun ve hesabın ciddi biçimde azalmasını sağlar.

### 2.1 CNN'in Katman Tipleri

Konvolüsyonel ağın temel katmanları şunlardır:

- **Konvolüsyon katmanı:** İhtiyaç olduğu kadar ve ihtiyaç olan filtreleri içerecek şekilde kurulur. Konvolüsyondaki işlem filtrelere karşılık geldiği için özellikle görüntü üzerinde daha iyi sonuç alınır.
- **Havuzlama (pooling) katmanı:** Boyutu düşürür.
- **Tam bağlantılı (fully connected) katman:** Normal MLP'de de görülen katmandır.
- **ReLU katmanı:** Aktivasyon fonksiyonunun yerine geçer. Hoca, ReLU kullanılmasının gradyan kaybolması (vanishing gradient) probleminin önüne geçtiğini hatırlattı.

MLP'den farklı olanlar konvolüsyon katmanı, havuzlama katmanı ve ReLU katmanıdır.

## 3. CIFAR-10 için Örnek CNN Mimarisi ve Boyutlar

CIFAR-10 küçük ($32\times32$) görüntülerden oluştuğu için CNN'i denemek için uygun bir veri setidir. Hoca, bundan "muhteşem bir şeyler beklemek değil ama CNN'i bir denemek için" kullanılabileceğini söyledi. Veri setinde 10 sınıf vardır ve birer konvolüsyon ve birer havuzlama katmanıyla bile sınıflandırma sonucu alınabilir. Slayttaki örnek mimari (ekrandan, 00:20:00):

```text
CIFAR-10 dataset: https://www.cs.toronto.edu/~kriz/cifar.html
A simple ConvNet for CIFAR-10 classification could have the architecture
[INPUT - CONV - RELU - POOL - FC]
```

Bu dizilişte boyutlar şöyle değişir:

- **INPUT:** $32\times32\times3$. Derinlik 3, RGB'den gelir.
- **CONV:** Hoca, 12 filtre uygulanırsa boyutun ne olacağını sordu. Her filtre bir çıktı kanalı ürettiği için derinlik 12 olur; uzamsal boyut korunursa çıktı $32\times32\times12$ olur (ara adım eklendi: altyazıda bu sayı açıkça söylenmedi, sonraki havuzlama adımından çıkarıldı).
- **RELU:** $\max(0,x)$ eleman eleman uygulanır. ReLU katmanında boyut azaltma yoktur; çıktı yine $32\times32\times12$'dir.
- **POOL:** Boyutu yarıya indirmek için $32\times32$, $16\times16$'ya düşürülür: çıktı $16\times16\times12$. Havuzlamanın nasıl yapıldığı filtre boyutuna bağlıdır; mevcut pencerede en yüksek değer seçilip kalanlar atılır (maksimum havuzlama).
- **FC:** Tam bağlantılı katmanın çıktısı beklenen sınıf sayısı kadar nörona bağlanır. CIFAR-10'da 10 sınıf olduğu için 10 nöron gerekir ve çıktı boyutu $1\times1\times10$ olur.

Böylece $32\times32\times3$ olarak giren veri, çıkışta 10 sınıfa, yani 10 değere düşmüş olur.

<!-- BELİRSİZ: Havuzlamada hoca "en yüksek bir, en yüksek iki değer çekerek ... üçe üçlük bir şeyden bire inebiliyoruz" dedi; cümle bozuk, pencere boyutu net değil. -->

## 4. ReLU, Ölü Nöronlar, Leaky ReLU ve Maxout

ReLU'da $\max(0,x)$ fonksiyonu uygulanır; buradaki $x$ nörona gelen toplam değerdir. Bu değer pozitifse olduğu gibi alınır, değilse sıfıra çekilir; yani negatif değer oluşması önlenir. ReLU, her elemana ayrı uygulanan bir aktivasyon fonksiyonu gibi düşünülebilir.

> **Ders sonrası not:** Hoca "ReLU fonksiyonu aslında lineer fonksiyondu" dedi. ReLU pozitif bölgede doğrusaldır, ama bütününde parçalı doğrusaldır; ağa doğrusal olmama özelliğini kazandıran da büyük olasılıkla sıfırdaki bu kırılmadır.

### 4.1 Ölü Nöron Problemi

ReLU'nun bazı avantajları ve dezavantajları vardır. Bu şekilde uygulandığında bir grup nöronun ürettiği değer sıfıra çekilir ve bu nöronların tekrar pozitif olma şansı da azalır. Böyle bir durumda eğitim sırasında o nöronun (ünitenin) "öldüğü" söylenir. Ölme şu yüzden olur: Değer sıfıra çekildiğinde sonraki çarpma işlemlerinde sıfır gelen değeri yutar ve bir daha pozitife geçme şansı kalmaz. Sonuçta o nöronun temsil ettiği özellik bazı örnekler için önemli olsa bile bu önemi göremeyiz; bazı özellikleri kullanma şansını kaybederiz.

### 4.2 Leaky ReLU

Bu soruna karşı yaygın kullanılan bir yöntem Leaky ReLU'dur. Burada değer doğrudan sıfıra çekilmez, küçük bir negatif değere izin verilir ki nöron ölmesin. Slayttaki tanım (ekrandan, 00:25:00): Leaky ReLU, "ölen ReLU" problemini düzeltme girişimlerinden biridir. Fonksiyon $x<0$ iken sıfır olmak yerine küçük bir negatif eğime (0,01 civarı) sahiptir:

$$
f(x)=\mathbb{1}(x<0)(\alpha x)+\mathbb{1}(x\ge 0)(x)
$$

Burada $\alpha$ küçük bir sabittir. Slaytta ayrıca negatif bölgedeki eğimin her nöron için bir parametre yapılabileceği (PReLU) ve sonuçların her görevde tutarlı olmadığı yazıyordu.

> **Ders sonrası not:** Hoca 0,01'i "sıfırın biraz altında veya biraz üstünde bir değer" olarak anlattı. Slayta göre 0,01 sabit bir çıkış değeri değil, negatif bölgedeki eğimdir: $x<0$ için $f(x)=0{,}01\,x$.

### 4.3 Maxout

Hoca bunun dışında başka yöntemler de olduğunu, örneğin Maxout'u söyledi. Slayttaki tanım (ekrandan, 00:25:00): Maxout nöronu

$$
\max(w_1^Tx+b_1,\; w_2^Tx+b_2)
$$

fonksiyonunu hesaplar. ReLU ve Leaky ReLU bu biçimin özel durumlarıdır (örneğin ReLU için $w_1=0,\ b_1=0$). Maxout, ReLU'nun avantajlarını (doğrusal çalışma bölgesi, doygunluk olmaması) taşır ve ölü nöron sorununu yaşamaz; ama her nöron için parametre sayısını iki katına çıkarır. Slaytın son notu da şuydu: ReLU kullanın, öğrenme hızına dikkat edin ve gerekirse ağdaki "ölü" ünitelerin oranını izleyin; sorun olursa Leaky ReLU ya da Maxout deneyin.

## 5. Underfitting ve Overfitting

Hoca, düzenlileştirmeye geçmeden önce aralarda adı geçen underfitting ve overfitting kavramlarını vurgulamak istediğini söyledi.

Elimizde bir grup örnek, yani bir veri vardır ve buna en uygun fonksiyonu oluşturmaya, o fonksiyonu genellemeye çalışırız. Eldeki verilere göre iyi bir fonksiyon kurabilirsek, aynı kavram içinde yeni veriler geldiğinde onlar hakkında da tahmin yürütebileceğimizi düşünürüz.

- **Underfitting (yetersiz öğrenme):** Model çok genel üretilmişse güvenilirliği azalır.
- **Overfitting (aşırı öğrenme):** Eldeki örneklerin hepsine birebir çok iyi uyan bir fonksiyon kurulursa, en ufak farklı yeni bir örnek bu "mükemmel" fonksiyona uymayacağı için tahmin yeteneği kaybedilir.

Eğitimde %100 başarıya, bütün örnekler için sıfır hataya ulaşılabilir, ama bu her zaman iyi bir şey değildir. Bu, eğitimde görülmeyen örnekler için sonuç üretilemeyeceğini, genelleme yeteneğinin kaybedildiğini gösterebilir.

### 5.1 Aslan Örneği

Hoca bir aslanı ya da büyük bir kediyi özelliklerine bakarak modellemeye çalıştığımızı düşünmemizi istedi. Seçilen özellikler vücut ölçüsü, ağırlık, dişlerin kuvveti, yelenin olup olmadığı gibi şeyler olsun.

- **Underfitting:** Kükremeyi de bir özellik sayarsak, kükreyebilen ve yelesi olan her hayvan aslan olarak sınıflanıyorsa bu underfitting'dir.
- **Overfitting:** Bir aslandan beklenen boyutlar çok net tanımlanmışsa, bu boyutların biraz üstünde ya da altında olan, biraz daha ağır ya da hafif aslanlar doğru tanınamaz.

Slayttaki örnek (ekrandan, 00:30:00): Eğitim setinde tam olarak 305 pound ağırlığında, 3,5 feet boyunda ve 2,9 inç pençeli bir aslan olabilir. Kötü eğitilmiş bir model "305 pound, 3,5 feet boyunda, 2,9 inç pençeli her kedi aslandır" kuralını geliştirebilir. Bu kural eğitim örneğini elbette doğru tahmin eder, ama yeni örnekleri sınıflandırırken işe yaramaz.

## 6. Overfitting'in Nedenleri ve Çapraz Doğrulama

### 6.1 Nedenler

- **Çok fazla giriş özelliği:** Bir şeyi tanımlarken çok fazla ayrıntıya girmemek gerekir.
- **Çok karmaşık mimari:** Çok sayıda gizli katman ve bu katmanlarda çok sayıda nöron.

Hoca bunu şöyle açıkladı: Girişte verilen şeylerin özellikleri temsil ettiğini, gizli katmanlarda da bu özelliklerin alt özelliklerinin çıkarıldığını düşünün. Zaten çok sayıda özellikle başlanmış, sonra gizli katmanlarda bunlar daha da özelleştirilmiştir. Böylece eğitim sırasında oluşan çıktılar çok fazla ayrıntıya dayanır ve bu özelliklerin hepsini taşımayan şeyleri tanımak zorlaşır. Overfitting olduğunda, aslında ihtiyaç olmayan bazı özellikler de ağırlıklandırılıp probleme katılmış olur.

### 6.2 Çapraz Doğrulama

Çözüm olarak eğitim sırasında çapraz doğrulama (cross-validation) uygulanabilir. Eldeki verinin büyük kısmı eğitime ayrılır ve eğitim yapılır; bir kısmıyla da doğrulama yapılır. Eğitim başarısı ile çapraz doğrulama başarısı arasında fark varsa overfitting olmuş olabilir; bu durumda mimariyi ve kullanılan özellik setlerini gözden geçirmek mantıklıdır. Çapraz doğrulamadan önce verinin iyi karıştırıldığından emin olmak gerekir.

Hoca belirli bir başarı yüzdesi vermediğini, bunun tamamen probleme bağlı olduğunu söyledi; önemli olan sonuçların uyumlu olmasıdır. Örneğin eğitimde %90, çapraz doğrulama setinde %60 başarı elde edildiyse bir şeyler ters gitmiştir: ya overfitting ya underfitting vardır ya da veri dağılımı iyi değildir. Doğrulama grubundaki verilere benzeyen hiçbir şey eğitimde kullanılmamış olabilir; hocaya göre underfitting de genellikle bu yüzden olur. Bu nedenle verinin iyi hazırlanması ve eldeki örneklerin hemen hepsini temsil eden örneklerin eğitim setinde yer alması önemlidir.

Düzgün dağıtılmış verinin bir kısmıyla çapraz doğrulama yapılır ve başarı elde edilirse test verileri kullanılır. Test başarısı da bunlarla uyumluysa model doğru şekilde oluşmuş sayılır.

## 7. Overfitting'e Karşı Yöntemler: Düzenlileştirme, Max Norm ve Dropout

Peki baştan hangi ayrıntının anlamlı olduğu nasıl bilinebilir? Büyük verilerle uğraşılıyor ve problemin çözümü hakkında zaten bir fikir olmadığı için derin ağ kullanmaya karar verilmişse, özellikleri bilerek azaltma şansı yoktur. O zaman kullanılacak yöntem düzenlileştirmedir (regularization).

### 7.1 Düzenlileştirme

İlk başta örnek, düşünülebilen bütün özellikleriyle, bütün ayrıntısıyla ağa verilir. Ama öne çıkan özellikler daha ağırlıklı kullanılırken diğerlerinin fazla etki etmemesi için parametrelerin önüne bir katsayı eklenir, önemleri azaltılır ve böylece daha genellenebilir bir denklem kurulur. Başka bir deyişle bazı özelliklere ya da girdilere bir ceza (penalty) terimi tanımlanır; yüksek ceza verilen özelliğin etkisi azalır.

Slayttaki ifade (ekrandan, 00:35:00): Özellikle sinir ağları için yaygın bir yöntem düzenlileştirmedir. L1 ve L2 gibi birkaç türü vardır, ama hepsi aynı genel ilkeyi izler: *model, fazla büyük ağırlık ve bias'lara sahip olduğu için cezalandırılır.* Slayttaki şekilde ağırlık ve bias'lar büyüdükçe cezanın düşükten yükseğe arttığı gösteriliyordu.

### 7.2 Max Norm Kısıtı

Başka bir yöntem max norm kısıtı koymaktır. Ağırlıkların ve bias'ların alabileceği değerler sınırlanır. Genellikle önemli olan üst sınırdır: Belli bir özellik çok fazla öne çıkarsa diğer özellikler ihmal edilir ve öne çıkan bu özellik her örnekte mutlaka aranır; bu da yine overfitting'dir. Bunu engellemek için, ReLU'daki gibi, ağırlıklar belli bir değerin üstüne çıktıysa daha fazla yükselmelerine izin verilmez.

### 7.3 Dropout

Çok kullanılan farklı bir yaklaşım da dropout'tur. Eğitim sırasında nöronların bir kısmı seçilip düşürülür; bu genellikle rastgele yapılır. Bazı nöronlar kapatılır, işleme sokulmaz. Hoca buna "silmek" denmemesi gerektiğini, nöronların yalnızca işleme alınmadığını vurguladı.

Slayttaki şekilde birinci gizli katmanda bir nöron, sonraki katmanda başka bir nöron kapatılmıştı. Hoca, şekildeki değerlere dikkat edildiğinde değeri yükselen nöronların kapatıldığını, bunun da bir tür sınırlama olduğunu söyledi: Değeri fazla yükselmiş bir nöronun ikinci turda daha da yükselmesi istenmediği için kapatılır. Böylece bu nöronların temsil ettiği özelliklerin eğitim sırasında çok fazla öne çıkması engellenir.

> **Ders sonrası not:** Hoca bir aşamada en yüksek değerli nöronların dropout'a tabi tutulduğunu söyledi. Standart dropout'ta nöronlar büyük olasılıkla (yaygın tanıma göre) değerlerine bakılmaksızın, her eğitim adımında belli bir olasılıkla rastgele kapatılır; değere göre seçim yapılmaz.

Hocaya göre max norm ve dropout geniş çapta uygulanan ve overfitting'i engelleyen yöntemlerdir, ama çok sistematik değildir ve çok temel bir fikre dayanırlar. Düzenlileştirme ise matematiksel olarak daha anlamlandırılabilir bir yöntemdir.

## 8. Ev Fiyatı Örneği ile Düzenlileştirme

Bir ev fiyatı tahmini için ağ kurduğumuzu varsayalım. Bu aslında bir doğrusal regresyon problemidir ve veri iki boyutludur: evin büyüklüğü ve fiyatı. Veriyi bir eğri temsil eder ve bu eğri istenen dereceden bir polinomla temsil edilebilir; kötü bir uydurma olsa da bir doğruyla bile temsil edilebilir. Slayttaki üç durum (ekrandan, 00:40:00):

- **Doğrusal fonksiyon:** $\theta_0+\theta_1x$
- **İkinci derece:** $\theta_0+\theta_1x+\theta_2x^2$
- **Yüksek dereceli polinom:** $\theta_0+\theta_1x+\theta_2x^2+\theta_3x^3+\theta_4x^4$

Birinci durumun kötü olduğu açıktır: doğru, örneklerin çoğunun üzerinden bile geçmez. Bu underfitting örneğidir ve neredeyse hiçbir şeyi tutturamaz. İkincisi fena değildir; verilerin çoğunun yakınından ya da üzerinden geçer, bazıları biraz dışında kalır. Üçüncüsü bütün verilerin tam üzerinden geçen "mükemmel" bir denklemdir; bu veri setiyle eğitim yapılırsa sonuç %100 doğrudur. Ama sonra test edilecek veriler bu eğrinin dışında kaldığında tahmin yapma şansı kalmaz. Bu kadar mükemmel uyum da istenmez; bu overfitting örneğidir. İstenen, ortadaki gibi bir miktar hatası olan ama hatası çok büyük olmayan bir modeldir.

### 8.1 Neden Ceza Terimi?

Bu örnekte veri iki boyutlu ve tek değişken olduğu için ikinci derece eğrinin uygun olduğunu görmek kolaydır. Ama çok boyutlu veride kaçıncı dereceden bir şeyin uyması gerektiğine karar vermek zordur. Bunun yerine dördüncü derece ya da olabildiğince karmaşık bir modele, akla gelen her özelliği kullanmaya izin verilir. Sonra derecesini artıran özellikler bir cezaya tabi tutulur: Bu katsayılar yok edilmez, etkileri vardır; ama önlerindeki katsayıları küçültmek için bir ceza terimi kurulur. Slayttaki maliyet (ekrandan, 00:45:00):

$$
\min_\theta\; \frac{1}{2m}\sum_{i=1}^{m}\left(h_\theta(x^{(i)})-y^{(i)}\right)^2 + 1000\,\theta_3^2 + 1000\,\theta_4^2
$$

İlk terim, modelle hesaplanan değer ile olması gereken değer arasındaki farkın karesidir ve bu küçük tutulmaya çalışılır. Mavi ile eklenen terimler $\theta_3$ ve $\theta_4$'ü cezalandırır. Katsayılar (1000) çok büyük olduğu için minimizasyon $\theta_3$ ve $\theta_4$'ü sıfıra yakın değerlere götürür. Bunun anlamı şudur: Yeni gelen örnekte $\theta_3$ ve $\theta_4$'ün temsil ettiği özelliklere dair bir şey varsa hiç dikkate alınmaması değil, mümkünse az etki etmesi istenir. Böylece mavi ile çizilen ayrıntılı model, istenen ikinci derece denkleme döner ya da en azından ona yaklaşır.

## 9. Düzenlileştirilmiş Maliyet Fonksiyonu ve $\lambda$ Seçimi

### 9.1 Yüz Özellikli Ev Örneği

Bu kez ev için yalnız büyüklük değil, onun yanında 100 tane daha özellik, dolayısıyla 100 parametre olsun. Artık bu özelliklerin hangisinin önemli olduğu, hangisinin cezalandırılacak terim, hangisinin asıl ağırlıklı terim olacağı bilinmez. Bu durumda maliyet fonksiyonu yine karesel hata gibi yazılır ve bütün terimler için bir $\lambda$ katsayısıyla ekleme yapılır; 100 özellik varsa 100 terim eklenir. Slayttaki genel biçim (ekrandan, 00:50:00):

$$
J(\theta)=\frac{1}{2m}\left[\sum_{i=1}^{m}\left(h_\theta(x^{(i)})-y^{(i)}\right)^2+\lambda\sum_{j=1}^{n}\theta_j^2\right]
$$

$\lambda$ her parametreyi kontrol eder; her parametre kare olarak yazılır. Böylece bir özelliğin değeri yüksekse bile kontrol edilemez derecede yükselmesi engellenir, ama özellik denklemde var olmaya devam eder. Artık bütün özellikler vardır, ama ana fonksiyona katkıları değerleri kadar olur.

### 9.2 $\lambda$ Çok Büyük Seçilirse

Slayttaki soru (ekrandan, 00:50:00): $\lambda$ problemimiz için aşırı büyük bir değere, örneğin $\lambda=10^{10}$'a ayarlanırsa ne olur? Slayta elle yazılan cevapta $\theta_1\approx0,\ \theta_2\approx0,\ \theta_3\approx0,\ \theta_4\approx0$ olur ve $h_\theta(x)=\theta_0$ kalır; yani model $\theta_0+\theta_1x+\theta_2x^2+\theta_3x^3+\theta_4x^4$'ten yalnızca $\theta_0$'a iner ve yatay bir doğru çıkar ("underfit"). Slaytın alt yazısı: *Düzenlileştirmenin iyi çalışması için düzenlileştirme parametresini seçerken dikkatli olmak gerekir.*

Hoca, yalnız $\theta_0$'ın öne çıktığı bu durumun pek anlamlı bir örnek olmadığını, diğer özellikler sıfır olsaydı ya da hiç olmasaydı tek bir doğru elde edileceğini söyledi. Düzenlileştirmede ise diğer bütün özellikler de küçük küçük eklenir ve model doğrudan paraboliğe ya da daha üst dereceli bir eğriye doğru evrilebilir.

### 9.3 $\lambda$ Veriye Göre Seçilir

Burada $10^{10}$ denmiştir, ama $\lambda$'nın ne olması gerektiği veriye bağlıdır: $\theta_1, \theta_2$ gibi özelliklerin değeri en az ve en çok kaç oluyor? $\lambda$ buna uygun seçilmezse diğer özellikler farkında olmadan yok edilebilir. $\theta$'lar çok küçük değerler alıyorsa bir anda sıfıra çekilebilir ve yine underfitting oluşur.

> **Hocanın vurgusu:** Maliyet fonksiyonundan çıkacak değeri ve seçtiğiniz özelliklerin ($\theta$'ların) hangi aralıkta değer aldığını dikkate alıp $\lambda$'yı öyle seçmeniz ya da ayarlamanız gerekir. Bunu deneyerek de yapabilirsiniz; ya da $\theta$'ların aralıklarını belirleyip hangi $\lambda$ ile çarpınca sıfıra çekildiğini, hangisiyle çok büyüdüğünü görüp arada uygun bir yerde seçebilirsiniz.

## 10. L1 ve L2 Düzenlileştirme ve Gradyan İniş Güncellemesi

### 10.1 L1 ve L2

Düzenlileştirmede iki yöntem vardır. L1 düzenlileştirmede ceza teriminde $\theta$ parametresi olduğu gibi alınır; L2 düzenlileştirmede karesi alınır. Yani $\lambda$'nın yanına gelen terimin parametrenin kendisi mi yoksa karesi mi olduğu iki yöntemi ayırır.

> **Ek bilgi (derste anlatılmadı):** L1 cezası büyük olasılıkla, yaygın kullanımda olduğu gibi, $\lambda\sum_j|\theta_j|$ biçiminde, mutlak değerle yazılır ve bazı parametreleri tam sıfıra indirerek seyrek (özellik seçen) modeller üretme eğilimindedir. L2 cezası ($\lambda\sum_j\theta_j^2$) parametreleri sıfıra tam indirmeden küçültür; sinir ağlarında "weight decay" adıyla da bilinir.

### 10.2 Gradyan İniş Güncellemesi

Maliyet bu şekilde tanımlandıktan sonra gradyan iniş ya da geri yayılım uygulanır. Her parametreye göre türev alınır ve $\alpha$ öğrenme katsayısıyla çarpılır. Slayttaki noktalar (ekrandan, 00:55:00):

- $\theta_0$ güncellemesi ayrıca gösterilir, çünkü düzenlileştirmede $\theta_0$ cezalandırılmaz ve biraz farklı ele alınır.
- Diğer kurallar şöyle düzenlileştirilir: terime $\frac{\lambda}{m}\theta_j$ eklenir.
- Bu, gradyan iniş için düzenlileştirmeyi verir; aşağıdaki ifade düzenlileştirilmiş $J(\theta)$'nın kısmi türevidir.

$$
\theta_j := \theta_j-\alpha\left[\frac{1}{m}\sum_{i=1}^{m}\left(h_\theta(x^{(i)})-y^{(i)}\right)x_j^{(i)}+\frac{\lambda}{m}\theta_j\right],\qquad j=1,2,3,\dots,n
$$

Slayttaki $j$ aralığında 0 elle üzeri çizilerek çıkarılmıştı; köşeli parantezin içi $\frac{\partial}{\partial\theta_j}J(\theta)$'dır.

Hoca, türev alındığında $\lambda$'nın payda kaldığını ve parametre sayısına bölündüğünü söyledi. Güncelleme yeniden düzenlenirse (ara adım eklendi):

$$
\theta_j := \theta_j\left(1-\alpha\frac{\lambda}{m}\right)-\alpha\frac{1}{m}\sum_{i=1}^{m}\left(h_\theta(x^{(i)})-y^{(i)}\right)x_j^{(i)}
$$

Burada öne çıkan terim $1-\alpha\lambda/m$'dir. Öğrenme katsayısı $\alpha$ 0 ile 1 arasında küçük bir sayıdır. Bu terim ne kadar büyükse, birden çıkarıldığı için $\theta_j$'nin çarpanı o kadar küçülür. Bu çarpan, $\theta_j$'nin temsil ettiği parametrenin denklemdeki önemini belirler; $\theta_j$'nin değeri zaten küçükse terim neredeyse yok olur. Hoca, her güncellemede bu kural kullanılırsa $\lambda$ katsayısının bizi koruyacağını, belli bir özelliğin öne çıkmasını ve denklemin çok karmaşıklaşmasını engelleyeceğini söyledi.

Hoca bu bölüm için sayısal bir örneğinin slaytlarda olmadığını, bunu daha sonra bir örnek üzerinden göstereceğini belirtti. Bu yüzden notta sayısal örnek yoktur.

## 11. Lojistik Regresyonda Underfitting ve Overfitting, Bias ve Varyans

Aynı durum lojistik regresyonda, yani sınıflandırma probleminde de görülür. Slayttaki noktalar (ekrandan, 01:00:00):

- Aynı şey lojistik regresyonda da olabilir.
- Sigmoid fonksiyonlu doğrusal sınır underfit'tir.
- Yüksek dereceli bir polinom ise overfitting verir (yüksek varyans hipotezi).

Slayttaki üç karar sınırı:

- **Underfitting (yüksek bias):** $h_\theta(x)=g(\theta_0+\theta_1x_1+\theta_2x_2)$, $g$ sigmoid fonksiyonu.
- **Uygun:** $g(\theta_0+\theta_1x_1+\theta_2x_2+\theta_3x_1^2+\theta_4x_2^2+\theta_5x_1x_2)$.
- **Overfitting (yüksek varyans):** $g(\theta_0+\theta_1x_1+\theta_2x_1^2+\theta_3x_1^2x_2+\theta_4x_1^2x_2^2+\theta_5x_1^2x_2^3+\theta_6x_1^3x_2+\dots)$.

Dersin sonunda gösterilen lojistik regresyon slaytında da aynı doğrusal sınır ve sigmoid fonksiyonu $\frac{1}{1+e^{-x}}$ grafiği vardı (ekrandan, 01:10:00).

Hoca şöyle açıkladı: İki kümeyi ayırmaya çalışırken hiçbir örnek yanlış kümeye düşmesin denirse, kurulması gereken denklem son derece karmaşık ve yüksek dereceli olur. Çok basit bir denklemle ya da doğruyla ayırmaya çalışılırsa bu kez çok fazla örnek yanlış tarafa düşer. Aradaki dengeyi bulmak gerekir.

### 11.1 Soru-Cevap: Yüksek Varyans

**Soru:** Overfitting'deki "high variance" kavramı, doğrusal olmayan denklemdeki değişkenlerin sayısı mı oluyor? **Cevap:** Hoca önce "evet" dedi, sonra varyansı şöyle açıkladı: Bir eğri ya da fonksiyon uydurulduğunda verilerin bu fonksiyona tek tek uzaklıklarından varyans hesaplanır. Ev örneğinde her verinin uydurulan doğruya uzaklığı hesaplanıp kareleri toplanırsa doğru için büyük bir değer çıkar. İkinci derece eğride bazı örnekler eğriye tam oturur, bazıları biraz uzaktadır; karelerin toplamı soldaki kadar büyük olmaz. Dördüncü derece eğride bu değer sıfırdır. Hoca, istenenin bu değerin ne sıfır ne de çok büyük olması, arada bir değer olması olduğunu söyledi. İki ya da üç boyutlu veride çizerek ya da hesaplayarak bu öngörülebilir; bu işi otomatikleştirmek için düzenlileştirme formülü kullanılır. Amaç, görülmeyen örneklerde de sapmanın belli bir seviyede kalması ve önemsiz özelliklerin denklemde hiç yer almaması ya da küçük değerlerle yer almasıdır.

> **Ders sonrası not:** Hoca, uydurulan doğruya olan uzaklıkların kareleri toplamının büyük olmasını "yüksek varyans" olarak adlandırıp underfitting'e bağladı. Slaytta ve yaygın terminolojide ise durum terstir: Eğitim verisinde büyük hata bırakan basit model **yüksek bias** (underfitting), eğitim verisine aşırı uyan ve eğitim verisi değiştiğinde çok değişen karmaşık model **yüksek varyans** (overfitting) olarak adlandırılır. Hocanın kareler toplamı dediği şey eğitim hatasıdır; düşük eğitim hatası yüksek varyansla birlikte görülebilir. Ayrıca yüksek varyans, değişken sayısının kendisi değil, model karmaşıklığının bir sonucudur.

## 12. Pratik Öneriler: Özellik Azaltma, Aykırı Değerler ve Eğitimi Durdurma

### 12.1 Özellik Azaltma

Slayttaki örnekte (ekrandan, 01:05:00) ev için şu özellikler sıralanıyordu: $x_1$ = evin büyüklüğü, $x_2$ = yatak odası sayısı, $x_3$ = kat sayısı, $x_4$ = evin yaşı, $x_5$ = mahalledeki ortalama gelir, $x_6$ = mutfak büyüklüğü, ..., $x_{100}$. Yanındaki grafikte ise beş noktanın hepsinden geçen dalgalı bir eğri (overfitting) vardı.

Hoca, ön bilgiyle bu özelliklerden bazılarının önemsiz olduğu biliniyorsa özelliklerin elle azaltılabileceğini söyledi; örnek olarak komşuların gelir düzeyini verdi, ama bunun da semtle ilgili bilgi verip vermeyeceğinden emin olmadığını ekledi. Hiçbir fikir yoksa ve elde 100 özellik varsa bu iş düzenlileştirmeye bırakılabilir. Özellik azaltma hem ilk başta yapılabilecek hem de düzenlileştirmeye bırakılabilecek bir şeydir.

### 12.2 Aykırı Değerleri Ayıklamak

Overfitting'e neden olmamak için verinin baştan iyi analiz edilmesi de önemlidir. Hoca, lojistik regresyon şeklindeki örnekte verilerin ikinci derece bir eğriyle güzelce ayrılabilecek gibi göründüğünü, ama iki kırmızı örneğin neden öbür tarafa düştüğünün sorulması gerektiğini söyledi. Bunlar hatalı veri ya da uç (ekstrem) örnekler olabilir. Modeli yanıltacak bu uç örnekleri önce ayıklayıp eğitim verisinden atmak faydalı olabilir. Böylece model baştan çok karmaşık hale gelmez; karmaşıklaşırsa sağdaki overfitting durumu oluşur, o zaman da düzenlileştirme kullanılarak ortadaki modele doğru evrilmesi sağlanır. Ama veriyi baştan temizlemek gerekir; bu tür örnekler büyük olasılıkla yanlış ölçüm ya da ekstrem örneklerdir.

### 12.3 Eğitimi Ne Zaman Durdurmalı?

Eğitimde belli sayıda epoch çalıştırılır ve aynı örnekler tekrar tekrar gösterilir. Ama burada bir sınır koymak gerekir.

> **Hocanın vurgusu:** Sıfır hata hedeflemek çok sağlıklı değildir. Sıfır hata hedeflerseniz örnekleri ezberletmeye gidersiniz. Hata artık çok az azalıyorsa durmanız gerektiğini bilin; daha fazlası örneklerin ezberlenmesi demektir ve ağ gösterdiğiniz örnekler dışında bir şey tanımaz.

> **Ek bilgi (derste anlatılmadı):** Hocanın anlattığı yaklaşım büyük olasılıkla "erken durdurma" (early stopping) olarak bilinen yöntemdir. Pratikte genellikle doğrulama setindeki hata izlenir; doğrulama hatası azalmayı bırakıp artmaya başladığında eğitim durdurulur ve en iyi doğrulama hatasını veren ağırlıklar saklanır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00; derste sözlü, 00:15:20)

CIFAR-10'daki $32\times32\times3$ bir görüntü için normal bir sinir ağının ilk gizli katmanındaki tam bağlantılı tek bir nöron kaç ağırlığa sahiptir? $200\times200\times3$ bir görüntüde bu sayı kaç olur?

> **Çözüm:** $32\cdot32\cdot3=3072$ ağırlık; $200\cdot200\cdot3=120\,000$ ağırlık (python ile doğrulandı). Her nöron için bu kadar ağırlık gerektiği için tam bağlantılı yapı büyük görüntülere ölçeklenmez.

**Soru 2** (derste sözlü, 00:20:35; ekrandan, 00:20:00)

`[INPUT - CONV - RELU - POOL - FC]` mimarisinde girişte $32\times32\times3$ görüntü var. Konvolüsyon katmanında 12 filtre uygulanırsa, sonra ReLU, boyutu yarıya indiren havuzlama ve 10 sınıflı tam bağlantılı katman gelirse her katmanın çıktı boyutu ne olur?

> **Çözüm:** INPUT $32\times32\times3$ → CONV (12 filtre, uzamsal boyut korunarak) $32\times32\times12$ → RELU $32\times32\times12$ (boyut değişmez) → POOL $16\times16\times12$ → FC $1\times1\times10$. CONV çıktısı derste açıkça söylenmedi; havuzlama adımındaki $16\times16\times12$ değerinden çıkarıldı.

**Soru 3** (ekrandan, 00:05:00)

$\begin{bmatrix}1&2&3\\4&5&6\\7&8&9\end{bmatrix}$ maskesi konvolüsyonda nasıl uygulanır?

> **Çözüm:** Maske önce bir yönde ($\begin{bmatrix}7&8&9\\4&5&6\\1&2&3\end{bmatrix}$), sonra diğer yönde döndürülür ve $\begin{bmatrix}9&8&7\\6&5&4\\3&2&1\end{bmatrix}$ elde edilir; korelasyon bu döndürülmüş maskeyle yapılır (python ile doğrulandı). Bu maske simetrik olmadığı için konvolüsyon ve korelasyon farklı sonuç verir.

**Soru 4** (ekrandan, 00:50:00)

Düzenlileştirilmiş doğrusal regresyonda $J(\theta)=\frac{1}{2m}\left[\sum_{i=1}^{m}(h_\theta(x^{(i)})-y^{(i)})^2+\lambda\sum_{j=1}^{n}\theta_j^2\right]$ minimize ediliyor. $\lambda$ problem için aşırı büyük bir değere, örneğin $\lambda=10^{10}$'a ayarlanırsa ne olur?

> **Çözüm:** Ceza terimi baskın olduğu için $\theta_1,\theta_2,\theta_3,\theta_4\approx0$ olur ve $h_\theta(x)=\theta_0$ kalır. Model yatay bir doğruya iner ve veriyi yetersiz öğrenir (underfit). Bu yüzden $\lambda$ dikkatle, verinin ve parametrelerin değer aralığına göre seçilmelidir.

**Soru 5** (derste sözlü, 00:59:19)

Overfitting'deki "high variance" kavramı neyi ifade eder?

> **Çözüm:** Derste verilen cevap ve düzeltmesi için Bölüm 11.1'deki soru-cevaba ve "Ders sonrası not"a bakın. Kısaca: Yüksek varyans, karmaşık modelin eğitim verisine aşırı uyması ve eğitim verisi değiştiğinde çok değişmesidir; overfitting'in göstergesidir. Basit modelin eğitim verisinde büyük hata bırakması ise yüksek bias'tır (underfitting).

## Dersin Toparlaması

Ders, konvolüsyonun korelasyondan farkını (maskenin yatay ve dikey döndürülmesi) ve ayrılabilir filtrelerle hesap yükünün azaltılmasını hatırlatarak başladı. Ardından CIFAR-10 üzerinden tam bağlantılı ağların görüntülerde neden ölçeklenmediği, basit bir `INPUT - CONV - RELU - POOL - FC` mimarisinde boyutların $32\times32\times3$'ten $1\times1\times10$'a nasıl indiği gösterildi. ReLU'nun ölü nöron sorunu ve buna karşı Leaky ReLU ile Maxout ele alındı.

Dersin ikinci yarısı genelleme sorununa ayrıldı. Underfitting ve overfitting aslan ve ev fiyatı örnekleriyle anlatıldı; overfitting'in çok sayıda özellik ve karmaşık mimariden kaynaklandığı, çapraz doğrulamayla fark edilebileceği söylendi. Çözüm olarak düzenlileştirme (L1, L2), max norm kısıtı ve dropout tanıtıldı. Düzenlileştirilmiş maliyet fonksiyonu, $\lambda$'nın veriye göre seçilmesi ve $\theta_0$'ın cezalandırılmadığı gradyan iniş güncellemesi incelendi; aynı durum lojistik regresyonda bias ve varyans kavramlarıyla gösterildi. Son olarak gereksiz özelliklerin azaltılması, aykırı örneklerin temizlenmesi ve sıfır hata hedeflemeden eğitimin durdurulması önerildi. Hoca, düzenlileştirme güncellemesini sayısal bir örnekle daha sonra göstereceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
