# Hafta 2

## Ders 1

### Veri önişleme
veriler kategorik ya da numerik olabilir. numerik veriler order ve distance özelliklerine sahiptir.

raw data'nın dönüşümü

**normalization**
veriyi normalize etmemiz gerekebilir, özellikle explode olmasın diye. 3 tarz normalizasyon yöntemi var.
Decimal scaling: -1, 1 arasında değişir. v'(i) = v(i) / 10^k. Aslında tamamen mutlak olarak en büyük sayıdan bir büyük onluk üssü buluyouz. -843, +455 varsa mesela -0.843, 0.455 oluyor işte

min-max normalization: 0,1 arasına scale edicez. v'(i) = (v(i) - min(v(i)))  / (max(v(i)) - min(v(i))) | -1,1 arasında yapmak istersek bir önceki formülü 2 ile çarpıp 1 eksiltirsek buluruz.

standar deviation normalization: v'(i)= (v(i) - mean) / stderr

## Ders 2 

**Data smoothing**: basitçe rounding diyebiliriz. Ancak daha karmaşık durumlarda binning, regression, clustering, combined computer and human inspection olarak farklı 4 method vardır.

binning: veriyi sırala, ve sonra eşit binlere böl, frekans ya da eşit aralıklar bin'ler olabilir. (burayı tam anlamadım daha fazla açık yazarsın) smooth by bin means, medians, boundaries
frekans'a göre bölersem her sepette 4 eleman olur mesela. ama eşit aralığa göre bölersem sepet'te daha fazla ya da daha az ürün olabilir. Mean yaparsam her sepetin içindeki değeri değerlerin ortalaması yaparım. 
4,8,9,15,21,21,24,25,26,28,29,34 sayıları ile bu örnekleri yap

regression: veriyi regresyın eğrisinde standardize ederek yumuşatabiliriz
clustering: outlier'ları tespit edip kaldırabiliriz
computer and human inspection: 
bu 3'üne çok değinmedik

**Differences and ratios**
missing datayı doldurcaz
- eksik verileri tek bir global değişken ile doldurabilriz
- ortalamayı doldurabiliriz,
- ilgili sınıfın ortalaması ile doldurabiliriz.


### Time Dependent Data

window mantığı ile tabular data'ya dönüştürebiliyoruz.

### Outlier Analysis
3 yöntem var:
- Box-Plot analysis (Univariate - tek değişkenli)
- Distance-based analysis (multi-variate)
- outlier analysis by mean and variance (univariate)



# Hafta 3

## Ders 1
1. ve 2. maddeleri önceki ders işlemiştik.
3. başlık: Outlier Analysis with mean and variance.
Threshold = Mean +- 2 * Stderr
Bu iki thresholdun dışındaysa eliyoruz
Aslında bu box plot'un aynısı değil mi? Değilmiş, box plot medyanı kullanırken bu ortalamayı kullanıyor. Veri eğer ki normal dağılımdan kayarsa o zaman medyana bakarak değerlendirme yapmak outlier tespitini yanlış yönlendirebilir. Yanımdaki çocuğun verdiği örnek: 1, 1, 1, 1, 2, 3, 4 olursam mesela medyan 1'ken ortalama 2'ye yakın vs oluyor. Daha fazla veri verince uç değerler medyana takılırken ortalamaya takılmayabilir.

### Data Reduction
- Feature* {Feature Selection, Feature Composition} (En önemlisi) 
- Case
- Value

Feature Selection:
- Supervised
Feature selection by using mean and variance
- Unsupervied
Entropy based feature ranking

Feature Composition:
- PCA Principle Component Analysis

Value Reduction:
- Chi merge technique 
- Data Discretization

Neden Dimension azaltıyoruz?
Compute time'dan tasarruf
Predictive - descriptive acc (bunu anlamadım tam)
reprenstation of data

üçünü de aynı anda yapabiliyor olsak harika olur
#### Feature Selection
##### by mean and variance

Test = |mean(A) - mean(B)| // SE(A-B) > Threshold

SE(A-B) = (Var(A)/n1 + Var(B)/n2) ^ (1/2)

##### by entropy
normalize öklid mesafesi falan garip gudubet şeyler var. Çok anlamadım açıkaçsı, numerik veriler için sample'lar arasındaki distance hesapladık ama sample'lar arası distance feature selection için ne anlam ifade ediyor onu anlamadım. 

#### Feature Composition
Sonraki hafta PCA anlatılacak


# Hafta 4

### Value Reduction

#### Feature Discretizatio: ChiMerge Technique
3 adım var
- veriyi artan sırada sırala
- initial interval'lar belirle, her value bir interval'a ait olsun
- Chi Square tekniğini uygulayarak interval'ların birleşip birleşmeyeceğine karar vereceğiz, slaytta formülü var.
verisetinde en minimal aralıklara bakacağız, sonra iki aralık arasında zaten çok fazla fark varsa ve sınırın değişmesi gerekiyorsa onu chi square'den anlıyoruz

Slayttaki örnekte 0 - 7,5 ve 7,5 - 10 aralığı belirlenen thresholdun aşağısında kaldığı için 

şunu anlamadım, biz bunu yapınca ne elde ettik. bir feature'ın ne kadar ayırıcı olduğunu mu buluyoruz. aralık bulmanın faydası ne ki. 

### PCA Principal component analysis

sample kullandığımzda standar sapmada aşağıdaki kısma n değil n-1 yazmamız gerekir.


## HAfta 5

### Classiifiication by decision tree


## Hafta 6
Naive Bayes Classification
Conditional prob: P (Y | X) = P (X, Y) / P (X) and vice versa
Bayes = P (Y | X) = P(X | Y) .  P (Y) / P(X)

P(S | M) = 1/2
P(M) = 1/50,000
P(S) = 1/20
P(M | S) = P(S | M) . P(M) / P(S)

Bir tablo varsa, diyelim ki 5 sütun var. Biri kontrol grubu. P (kontrol grubu state | X ) olarak kontrol ediyoruz. yes no ise mesela yes'e ayrı oran no'ya ayrı oran çıkıyor.

Kontrol yes olsun. X'in her sütunu için kontrol'un yes odluğu oranları hesaplıyoruz. Yani X1 değerinin yüzde kaçında kontrol yes idi bunun olasılığını hesaplayacağız.
P (Yes | X) = P(X | Yes) . P (Yes) / P (X)
P(X | Yes) Bunu hesaplamak asıl olay zaten. Bunun için de test ifadesindeki her sütun için o sütunun test ifadesindeki değerin kontrol'le koşullu olasılığına bakıyoruz.
Yani Toplam yes'ler arasında kaçı X'tir diye bakacağız.

Sürekli veriler için bu olasılık hesabı biraz sıkıntı. Çünkü bir x değerine yakın olmanın bir anlamı olmalı, Yani 120k maaşa sahip olmakla 119k maaşa sahip olmak benzer anlamlara gelmeli. Bunun için veriyi kategorilere bölebilriz. Discritization deniyor buna. Dğer yöntem de aşağıdaki. Normal dağılımda nerede olduğuna göre olasılığını buluyoruz. gibi bir şey.

probability density estimation: Sürekli verileri değerlendirmek için kullanıyoruz. Verinin normal dağılıma uyduğunu kabul ediyoruz. ortalama ve standart sapma vs hesaplıyoruz. kontrol gurubunun No ve Yes oluşuna göre ayrı ayrı mean vs variance hesaplıyoruz. Sonra onun bi formulü ve e üzeri bilmemneli karmaşık bi formül. onun yerine koyuyoruz öyle ihtimalini buluyoruz.


Sınavda direkt işlemli şeyler soruyormuş. o yüzden hesap makinesinde önceden hesaplayın gelin dedi. E üzeri işlemleri yapmaya bakın falan dedi.

precision ve recall öğerndik ayrıca
precision: benim bu yestir dediklerimden kaç tanesi gerçekten pozitif.
Recall: Gerçek yes'lerin kaç tanesini bilebildim.

# Hafta 9

Classification: alternative techniques
KNN 
