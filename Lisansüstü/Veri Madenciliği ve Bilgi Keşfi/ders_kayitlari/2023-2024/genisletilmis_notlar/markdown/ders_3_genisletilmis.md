# Ders 3 Genişletilmiş Notu: Veri İndirgeme: Öz Nitelik Seçimi, Entropi Tabanlı Sıralama ve ChiMerge

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri İndirgeme Nedir?
- 2. Veri İndirgemenin Kazançları ve Bedeli
- 3. Öz Nitelik Seçimi ve Öz Nitelik Birleştirme
- 4. Haftanın Kavram Ağacı
- 5. Ortalama ve Varyansa Dayalı Öz Nitelik Seçimi
- 6. Uzaklık ve Benzerlik Ölçüleri
- 7. Entropi Ölçüsüyle Öz Nitelik Sıralama
- 8. Değer İndirgeme ve Öz Nitelik Ayrıklaştırma
- 9. ChiMerge Tekniği
- Örnek Sorular
- Dersin Toparlaması

## 1. Veri İndirgeme Nedir?

Bu dersin konusu veri indirgeme (data reduction). Hoca önce slaytlar üzerinden konuyu anlattı, ardından tablette açtığı bir beyaz tahta üzerinde kavram ağacı ve örnek çizimler yaptı.

Elimizde bir ham veri (raw data) olduğunu düşünelim. Bu verideki öz nitelik (feature) sayısı yüzlerce olabilir; özellikle doğal dil işleme çalışmalarında 250, 500, hatta binlerce öz nitelikle karşılaşılır. Bu kadar çok öz nitelik veriyi işleme açısından büyük bir yük getirir. Bu durumda yapılacak en doğru şey, amaca uygun öz nitelikleri seçip onlarla ilerlemektir. Veri indirgeme burada devreye girer.

### 1.1 Büyük Veri Setlerinin Üç Boyutu

Veri tabanındaki veri, işe başlamadan önce düz bir dosyaya (flat file), Excel tablosuna benzer bir forma yerleştirilir. Bu tabloda satırlara örnekler (samples, cases), sütunlara bu örneklerle ilişkili öz nitelikler yerleştirilir. Bir hücre, bir öz niteliğin belirli bir örnekteki değeridir (ekrandan, 00:15:00).

Slayttaki ifadeyle ön işlenmiş veri setlerinin üç ana boyutu sütunlar (öz nitelikler), satırlar (örnekler) ve öz niteliklerin değerleridir. Bu yüzden veri indirgemede üç temel işlem vardır:

- **Öz nitelik indirgeme (feature reduction):** Sütun silmek. Ekranda görülen altı sütunu üçe düşürmek gibi.
- **Örnek indirgeme (sample/case reduction):** Satır silmek. Amaca hizmet etmeyen gereksiz örnekler veri setinden çıkarılabilir.
- **Değer indirgeme (value reduction):** Bir sütundaki değerlerin sayısını ve çeşitliliğini azaltmak, yani öz niteliği yumuşatmak.

Hoca, örnek indirgemeye kendi uygulamalarında şimdiye kadar hiç ihtiyaç duymadığını söyledi. Özellikle derin öğrenmeyle çalışırken ne kadar çok örnek olursa model o kadar iyi eğitilir. Bu yüzden satır azaltma çok başvurulan bir yol değildir ve bu derste bu başlığın altında bir yöntem gösterilmedi.

### 1.2 Dönüşümle Öz Nitelik Azaltma: Vücut Kitle İndeksi

Hoca, bir önceki derste "ham verinin dönüştürülmesi" başlığında anlattığı bir fikri hatırlattı: Bazı öz nitelikleri birleştirerek yeni bir öz nitelik üretebiliriz. Vücut kitle indeksi (body mass index) kilonun boyun (metre cinsinden) karesine oranıdır ve iyi bir göstergedir. Veri setinde boy ve kilo diye iki ayrı öz nitelik yerine bunlardan türetilmiş tek bir öz nitelik kullanmak hem veriyi azaltmaya hem de veri kalitesini artırmaya güzel bir örnektir. Daha kaliteli bir girdi, model başarısını da artırır. Ancak her indirgeme işleminden sonra veri kalitesinde böyle bir artış görülmeyebilir; bazen küçük düşmeler de olur.

## 2. Veri İndirgemenin Kazançları ve Bedeli

Veri indirgeme yapıldığında üç başlıkta kazanç sağlanabilir:

- **Hesaplama süresi (computing time):** 500 öz nitelik yerine 100 öz nitelikle çalışmak modele daha basit bir girdi vermek demektir. Modelin öğrenmesi ve çalışması hızlanır, zamandan tasarruf edilir.
- **Tahmin ve tanımlama başarısı (predictive/descriptive accuracy):** Model başarısı artabilir. Bu her zaman olmaz, ama vücut kitle indeksi örneğinde olduğu gibi daha iyi bir gösterge elde edildiğinde başarı artar.
- **Veri madenciliği modelinin gösterimi (representation):** Daha az girdiyle kurulan modelin ifade ediliş şekli daha basit ve anlaşılır olur.

Slayttaki önemli uyarı şudur (ekrandan, 00:20:00): Boyut indirgemeyle aynı anda daha kısa süre, daha yüksek başarı ve daha basit gösterim elde etmek ideal olurdu; ama çoğu zaman birinde kazanırken diğerinde kaybederiz ve dengeyi eldeki uygulamaya göre kurarız. Örneğin tahmin başarısı az da olsa düşebilir; fakat modeli daha kısa sürede eğitip test etmek sizin için önemliyse, başarıdaki küçük düşüşü kabul edebilirsiniz. Hangisinin sizin için daha önemli olduğuna bakıp kazancı ve kaybı tartarak karar verirsiniz.

## 3. Öz Nitelik Seçimi ve Öz Nitelik Birleştirme

Öz nitelik indirgeme iki temel yöntemle yapılır.

**Öz nitelik seçimi (feature selection):** Var olan öz niteliklerden değerli olanlar seçilir. Veri setinde 10 öz nitelik olduğunu düşünelim. Bunları inceleyip "bunlardan 4'ü sonuca götürmede daha etkili, diğer 6'sı o kadar etkili değil" diyebiliriz. Ya da öz nitelikleri sıralar, belirlediğimiz bir eşiğin (threshold) üstünde kalanları önemli sayar, altında kalanları atarız. Burada yeni öz nitelik üretilmez; yalnızca mevcut öz nitelikler içinden değerli olanlar öne çıkarılır.

**Öz nitelik birleştirme (feature composition):** Öz nitelikler bir dönüşümden (transformation) geçirilerek yeni öz nitelikler üretilir. Boy ve kilodan vücut kitle indeksinin üretilmesi buna örnektir: Artık veri setinde boy ve kilo yoktur, bunlardan türetilmiş yeni bir öz nitelik vardır. Bu yaklaşım bazen yöntemde çok büyük başarı getirir. Bu gruptaki temel yöntem temel bileşen analizidir (principal component analysis, PCA); bu yöntemde öz nitelikler tümüyle değişir.

## 4. Haftanın Kavram Ağacı

Hoca, haftanın konularının nasıl gruplandığını görmek için tablette bir kavram ağacı çizdi ve öğrencilerden bunu kaydetmelerini istedi (ekrandan, 00:30:00). Ağaç metin olarak şöyledir:

```text
Data Reduction
├── Feature Reduction
│   ├── Feature Selection
│   │   ├── 1) Supervised   : Based on mean and variance
│   │   └── 2) Unsupervised : Entropy measure for ranking features
│   └── Feature Composition
│       └── 1) Unsupervised : PCA (Principal Component Analysis)
├── Sample Reduction        : (yöntem gösterilmedi)
└── Value Reduction
    └── Feature Discretization : ChiMerge Technique
```

Çözüm yöntemlerinde ayrım şuna göre yapılır: Veri sınıf etiketliyse yöntem gözetimli (supervised), değilse gözetimsizdir (unsupervised). Ortalama ve varyansa dayalı seçim sınıf etiketi gerektirir; entropi tabanlı sıralama gerektirmez. Değer indirgemede daha önce konuşulan veri yumuşatma (data smoothing) yöntemleri de işe karışır, ama bu derste önemli başlık olarak öz nitelik ayrıklaştırma ve ChiMerge tekniği ele alındı.

## 5. Ortalama ve Varyansa Dayalı Öz Nitelik Seçimi

### 5.1 Yöntemin Fikri

Bu gözetimli yöntemde her öz nitelik, sınıfları birbirinden ayırt etmede ne kadar etkin olduğuna göre değerlendirilir. Verinin normal (Gauss) dağılıma benzediği varsayılır. Bu her veri seti için uygun olmayabilir, ama doğadaki olayların büyük bölümünün normal dağılım gösterdiği varsayımıyla ilerlenir.

Veri setinde A ve B sınıflarına ait örnekler olduğunu düşünelim. Her öz nitelik için:

- A sınıfına ait örneklerin ortalaması ve varyansı,
- B sınıfına ait örneklerin ortalaması ve varyansı

hesaplanır. Sonra ortalamalar arasındaki farkın mutlak değeri, varyanslardan elde edilen bir standart hataya bölünür (ekrandan, 00:55:00):

$$SE(X_A-X_B)=\sqrt{\frac{var(X_A)}{n_1}+\frac{var(X_B)}{n_2}}$$

$$\text{test}=\frac{|\,mean(X_A)-mean(X_B)\,|}{SE(X_A-X_B)}$$

Burada $n_1$ ve $n_2$ iki sınıftaki örnek sayılarıdır. Test sonucu belirlenen bir eşikle karşılaştırılır. Sonuç ne kadar büyükse öz nitelik A sınıfını B sınıfından ayırt etmede o kadar etkindir.

### 5.2 Formülü Dağılımlarla Yorumlamak

Hoca formülü ezberlemek yerine üzerinde düşünmeyi istedi ve tahtaya iki öz nitelik için dağılım grafikleri çizdi (ekrandan, 00:45:00). X öz niteliğinde A ve B sınıflarının ortalamaları (0,46 ve 0,43) birbirine çok yakındır, dağılımlar iç içe geçmiştir. Y öz niteliğinde ortalamalar (0,6 ve 0,83) daha uzaktır, dağılımlar daha ayrıktır. Bu yüzden Y, sınıfları ayırmada daha başarılıdır.

Yalnız ortalamalar arasındaki uzaklık yetmez, varyansa da bakılmalıdır. Standart sapması ($\sigma$) küçük bir dağılım ortalamaya yakın, derli topludur; standart sapması büyük bir dağılım geniş bir alana yayılır. Hoca sınıfa hangi durumda iki dağılımı ayırt etmenin daha kolay olduğunu sordu; doğru cevap standart sapmanın küçük olduğu durumdu.

Formüle bu gözle bakınca:

- Kesrin üstündeki ortalamalar farkı büyük olmalıdır.
- Kesrin altındaki terim küçük olmalıdır. Bu terim, her grubun varyansını o gruptaki örnek sayısına bölüp toplayan ve karekökünü alan, bir tür standart sapmadır.
- Pay büyük, payda küçük olunca test değeri büyür.

> **Hocanın vurgusu:** Test formülünü ezberleyip geçmeyin; ortalamalar arasındaki farkın büyük, standart sapmaların küçük olmasını istediğimiz için formül bu şekildedir.

### 5.3 Sayısal Örnek

Slayttaki veri seti iki girdi öz niteliği (X, Y) ve örnekleri A ve B sınıflarına ayıran ek bir C öz niteliğinden oluşur. Eşik değeri 0,5 alınır (ekrandan, 00:35:00):

| X | Y | C |
|---|---|---|
| 0.3 | 0.7 | A |
| 0.2 | 0.9 | B |
| 0.6 | 0.6 | A |
| 0.5 | 0.5 | A |
| 0.7 | 0.7 | B |
| 0.4 | 0.9 | B |

Veri setinde 6 örnek ve sınıf hariç 2 öz nitelik vardır. Amaç, iki öz nitelikten hangisinin A ve B sınıflarını ayırt etmede daha etkin olduğunu bulmak ve belki veri setini tek öz niteliğe düşürmektir.

**Adım 1: Ortalamalar.**

- X için A sınıfı değerleri 0,3, 0,6, 0,5: $mean(X_A)=0.4667$.
- X için B sınıfı değerleri 0,2, 0,7, 0,4: $mean(X_B)=0.4333$.
- Y için A sınıfı değerleri 0,7, 0,6, 0,5: $mean(Y_A)=0.6$.
- Y için B sınıfı değerleri 0,9, 0,7, 0,9: $mean(Y_B)=0.8333$.

**Adım 2: Standart hatalar ve test değerleri (ekrandan, 00:55:00).**

$$SE(X_A-X_B)=\sqrt{0.0233/3+0.6333/3}=0.4678$$

$$SE(Y_A-Y_B)=\sqrt{0.01/3+0.0133/3}=0.0875$$

$$|0.4667-0.4333|/0.4678=0.0735<0.5$$

$$|0.6-0.8333|/0.0875=2.6667>0.5$$

**Adım 3: Karar.** X'in ortalamaları birbirine yakın olduğu için test değeri eşiğin altındadır; X indirgeme adayıdır. Y'nin test değeri eşiğin belirgin biçimde üstündedir; Y iki sınıfı ayırt etme potansiyeli taşıdığı için indirgeme adayı değildir. Veri setinde Y tutulur, X çıkarılabilir.

> **Ders sonrası not:** Slaytta $var(X_B)=0.6333$ yazıyor. 0,2, 0,7 ve 0,4 değerlerinin örneklem varyansı ($n-1$ ile) 0,0633'tür (python ile doğrulandı); slayttaki değer büyük olasılıkla basamak kaymasıdır. Doğru değerle $SE(X_A-X_B)=\sqrt{0.0233/3+0.0633/3}\approx 0.170$ ve test değeri $\approx 0.196$ çıkar. Bu da 0,5'in altında olduğundan karar değişmez. Y için yuvarlamasız değerler $SE\approx 0.0882$ ve test $\approx 2.646$'dır.

### 5.4 Çok Sayıda Öz Nitelik ve Eşik Seçimi

Örnekte yalnızca iki öz nitelik vardı; gerçek çalışmalarda on ya da daha fazla öz nitelik olabilir. Her biri için test yapılır ve sonuçlar büyükten küçüğe sıralanır. Örneğin değerler 5, 4, 3,5, 2,5 diye giderken birden 0,05'e düşerse, burada büyük bir boşluk (gap) vardır ve bu noktadan kesmek idealdir: Üstte kalanlar tutulur, altta kalanlar çıkarılır. Bazen iki ayrı boşluk görülür; o zaman ikisi de denenir ve tahmin başarısına etkisine bakılarak karar verilir.

İndirgeme kararı tek başına alınmaz. Verinin tamamıyla elde edilen tahmin başarısı ile indirgenmiş veriyle elde edilen başarı karşılaştırılır. Fark çok büyükse öz nitelik seçimi yapılmayıp verinin tamamı kullanılabilir. 10 öz niteliği 3'e mi 5'e mi indirmek gerektiği de ikisi denenerek bulunur; 3 ile başarıda belirgin bir düşme yoksa 3 ile ilerlenir. Hoca, uygulamada onlarca farklı çözümün denenip karar verildiğini vurguladı.

**Soru:** Eşik değerini neye göre belirliyoruz?
**Cevap:** Bu problemde eşik verilmiş. Gerçekte her öz nitelik için test yapılır, sonuçlar sıralanır ve değerlerin birden düştüğü boşluktan kesilir. Birden fazla boşluk varsa hepsi denenir, tahmin başarısına etkisine göre seçilir.

**Soru:** A, B ve C diye üç sınıf olsaydı nasıl yapardık?
**Cevap:** Testi ikili yapmak gerekir: A ile B, A ile C, B ile C. Dağılımlar eksen üzerine yan yana dizildiğinde sıralamaları zaten görünüyorsa oradan da sonuca varılabilir.

## 6. Uzaklık ve Benzerlik Ölçüleri

Öz nitelik birleştirme başlığındaki PCA, özdeğer ve özvektör hesabı ile kovaryansın hatırlatılmasını gerektirdiği ve kendi başına uzun bir konu olduğu için bir sonraki derse bırakıldı. Ders, sınıf etiketi olmadan öz nitelik seçimi yapan entropi tabanlı yöntemle devam etti. Bu yöntem için önce uzaklık ve benzerlik kavramları gerekir.

### 6.1 Uzaklıktan Benzerliğe

Önceki derste uzaklık tabanlı aykırı değer analizinde Öklid uzaklığı kullanılmıştı. İki örnek arasındaki uzaklık ne kadar küçükse (sıfıra ne kadar yakınsa) bu iki örnek o kadar benzerdir. Yani uzaklık $D$ ile benzerlik $S$ ters orantılı gibidir: $D$ küçüldükçe $S$ büyür. Slaytta da algoritmanın, iki $n$ boyutlu örnek arasındaki uzaklıkla ters orantılı bir benzerlik ölçüsüne dayandığı yazıyordu (ekrandan, 01:25:00).

Sayısal bir veri setinde örnekler arası uzaklık hesaplanabilir. Uzaklıktan benzerliğe geçmek için dönüşüm formülleri vardır. $i$ örneğinin $j$ örneğine benzerliği:

$$S_{ij}=e^{-\alpha D_{ij}}$$

Buradaki $\alpha$ bir formülle hesaplanabilir ya da sabit bir sayı alınabilir. <!-- BELİRSİZ: alfa için slaytta verilen formül altyazıda okunmuyor ve o anın karesi yok. -->

> **Ek bilgi (derste anlatılmadı):** Bu yöntemin yaygın kaynaklarında $\alpha$ büyük olasılıkla $\alpha=-\ln(0.5)/\bar{D}$ olarak verilir; burada $\bar{D}$ veri setindeki örnekler arası ortalama uzaklıktır. Bu seçimle ortalama uzaklıktaki iki örneğin benzerliği 0,5 olur.

### 6.2 Normalize Öklid Uzaklığı

Hoca formülü anlatmak için önce veri setinin yapısını tarif etti. Veri seti $X$, $m$ satır (örnek) ve $n$ sütundan (öz nitelik) oluşan bir matristir. $x_{11}, x_{12}, \dots, x_{1n}$ birinci örneğin öz nitelikleri, $x_{m1}, \dots, x_{mn}$ ise son örneğin öz nitelikleridir. Satır yönünde örnekler, sütun yönünde öz nitelikler okunur.

İki örnek arasındaki Öklid uzaklığı, karşılıklı öz nitelikler arasındaki farkların kareleri toplamının kareköküdür. Normalize Öklid uzaklığında kare almadan önce her fark, o öz niteliğin sütundaki en büyük ve en küçük değeri arasındaki farka bölünür (ekrandan, 01:40:00):

$$D_{ij}=\left[\sum_{k=1}^{n}\left(\frac{x_{ik}-x_{jk}}{max_k-min_k}\right)^2\right]^{1/2}$$

Burada $n$ boyut (öz nitelik) sayısıdır; $max_k$ ve $min_k$, $k$. boyutun normalizasyonu için kullanılan en büyük ve en küçük değerlerdir. Yani her sütun için dikey doğrultuda bir maksimum ve minimum hesaplanır.

> **Hocanın vurgusu:** Formüllerle barışmanızda fayda var. Formül okumayı bilmek ve formülün ne anlattığını anlamak çok kıymetlidir.

### 6.3 Kategorik Öz Niteliklerde Benzerlik

Sayısal öz niteliklerde uzaklık, kategorik öz niteliklerde doğrudan benzerlik hesaplanır. En basit yol, iki örneğin karşılıklı öz nitelikleri arasında birebir eşleşenlerin sayısını toplam öz nitelik sayısına bölmektir. Hoca bu ölçüyü Hamming uzaklığı adıyla andı; adı uzaklık olsa da eşleşen değer sayısı üzerinden hesaplanır.

Slayttaki veri seti üç kategorik öz nitelikten oluşur (ekrandan, 01:45:00). F3'teki 1, 2, 3 değerleri sayı değil, kategorik değerlerin kodlarıdır (dummy variable):

| Örnek | F1 | F2 | F3 |
|---|---|---|---|
| R1 | A | X | 1 |
| R2 | B | Y | 2 |
| R3 | C | Y | 2 |
| R4 | B | X | 1 |
| R5 | C | Z | 3 |

**$S_{1,4}$ hesabı:** F1'de R1 A, R4 B değerini almış: eşleşme yok. F2'de ikisi de X: eşleşme var. F3'te ikisi de 1: eşleşme var. Eşleşen öz nitelik sayısı 2, toplam 3: $S_{1,4}=2/3$.

**$S_{3,5}$ hesabı (derste birlikte yapıldı):** Yalnız F1'de (C) eşleşme var: $S_{3,5}=1/3$.

Beş örnek için 5x5'lik benzerlik matrisi şöyledir (ekrandan, 01:45:00; python ile doğrulandı):

| | R1 | R2 | R3 | R4 | R5 |
|---|---|---|---|---|---|
| R1 | 1 | 0/3 | 0/3 | 2/3 | 0/3 |
| R2 | | 1 | 2/3 | 1/3 | 0/3 |
| R3 | | | 1 | 0/3 | 1/3 |
| R4 | | | | 1 | 0/3 |
| R5 | | | | | 1 |

Matris simetriktir ve bir örneğin kendisine benzerliği her zaman 1 olduğu için köşegen 1'lerden oluşur; bu yüzden yalnız üst üçgen yazılır.

## 7. Entropi Ölçüsüyle Öz Nitelik Sıralama

### 7.1 Yöntemin Varsayımı

Slayta göre (ekrandan, 01:25:00) entropi ölçüsüne dayalı gözetimsiz öz nitelik seçimi ya da sıralaması görece basit bir tekniktir, ama öz nitelik sayısı arttıkça karmaşıklığı belirgin biçimde artar. Temel varsayım, tüm örneklerin çıktı sınıfı olmadan, öz nitelik değerlerinden oluşan vektörler olarak verilmesidir. Yaklaşım, ilgisiz (irrelevant) ya da gereksiz (redundant) bir öz niteliğin kümeden çıkarılmasının veri setinin temel özelliklerini değiştirmeyebileceği gözlemine dayanır. Amaç, olabildiğince çok öz nitelik çıkarırken örnekler arasındaki ayırt edilebilirlik düzeyini hiç öz nitelik çıkarılmamış gibi korumaktır.

Bilgi kuramından bilindiği üzere entropi küresel bir ölçüdür; düzenli yapılarda düşük, düzensiz yapılarda yüksektir. Teknik, bir öz nitelik çıkarılmadan önceki ve sonraki entropiyi karşılaştırır. İki ölçü yakınsa, indirgenmiş öz nitelik kümesi orijinal kümeye yeterince iyi yaklaşır (ekrandan, 01:50:00). Hoca, entropiyi karar ağaçlarında daha geniş anlatacağını söyledi.

### 7.2 Entropi Formülü

$N$ örnekli bir veri seti için entropi ölçüsü (ekrandan, 01:50:00):

$$E=-\sum_{i=1}^{N-1}\sum_{j=i+1}^{N}\Big(S_{ij}\log S_{ij}+(1-S_{ij})\log(1-S_{ij})\Big)$$

Hoca formülü birlikte okudu:

- $S_{ij}$, benzerlik matrisinin $i$. satır $j$. sütundaki elemanıdır, yani $x_i$ ile $x_j$ arasındaki benzerliktir.
- Buradaki $N$ öz nitelik sayısı değil, örnek sayısıdır (benzerlik matrisinin boyutu). Normalize Öklid formülündeki $n$ ile karıştırılmamalıdır.
- $i$ birinci satırdan başlar ve $N-1$. satıra kadar gider; son satır alınmaz.
- $j$, $i+1$'den başlar ve son sütuna kadar gider. Köşegen (örneğin kendisine benzerliği, hep 1) atlanır; yani yalnız üst üçgen kullanılır.
- $S_{ij}$ benzerliği, $1-S_{ij}$ ise benzemezliği (dissimilarity) gösterir.

### 7.3 Sıralama Algoritması

Slayttaki beş adım (ekrandan, 01:55:00):

```text
1. Tüm öz nitelik kümesi F ile başla.
2. Her f ∈ F için f'yi F'den çıkar, F_f alt kümesini elde et.
   E_F ile her E_{F-f} arasındaki farkı bul.
   Örnekte: (E_F − E_{F−F1}), (E_F − E_{F−F2}), (E_F − E_{F−F3}).
3. E_F ile E_{F−fk} arasındaki farkı en küçük yapan fk'yı seç.
4. F = F − {fk} yap. Örnekte (E_F − E_{F−F1}) en küçükse
   indirgenmiş küme {F2, F3} olur, F1 sıralı listenin en altına gider.
5. F'de tek öz nitelik kalana kadar 2-4. adımları tekrarla.
```

Her adımda yalnız bir öz nitelik dışarıda bırakılır ve diğerleri hesaba dahildir. Fark ne kadar küçükse o öz nitelik o kadar az etkilidir: İçeride olsa da olmasa da veri setine katkısı yok ya da çok azdır. Farkı en küçük yapan öz nitelik sıralı listenin (ranked features) en altına yazılır ve kümeden çıkarılır. Kalan küme yeni "tam küme" kabul edilir ve işlemler baştan tekrarlanır. Böylece listenin alt sıraları geriye doğru (sequential backward ranking) dolar. Öz nitelik sayısı kadar tekrar gerektiren iteratif bir yapıdır. Süreçte sınıf bilgisi hiç kullanılmadığı için bu bir gözetimsiz öz nitelik sıralama algoritmasıdır.

**Soru:** Öz nitelikleri tek tek dışarıda bırakırken, örneğin ikinciyi dışarıda bıraktığımızda birinci hesaba dahil mi?
**Cevap:** Evet. Aynı iterasyon içinde ikinci adımda önce yalnız F1 çıkarılır, F2 ve F3 ile hesap yapılır. Sonra tam kümeden yalnız F2 çıkarılır, sonra yalnız F3. Değerlendirmenin sonunda en az etkili olan (örneğin F1) listenin en altına yazılır; bir sonraki iterasyonda tam küme yalnız F2 ve F3'ten oluşur.

**Soru:** Entropi değeri en düşük olan öz nitelik listenin en altına gelip en önemsiz mi oluyor?
**Cevap:** Entropisi en düşük olan değil; o öz nitelik çıkarıldığında hesaplanan entropi ile tüm kümenin entropisi arasındaki fark en küçük olan listenin en altına gelir.

## 8. Değer İndirgeme ve Öz Nitelik Ayrıklaştırma

Değer indirgeme, tablodaki değerlerde indirgeme yapmaktır. Bir öz niteliğin aldığı onlarca farklı sayı, belirli aralıklara bölünüp her aralık tek bir değerle temsil edilebilir. Bu, daha önce yumuşatma (smoothing) konusunda yapılana benzer bir yaklaşımdır ve öz nitelik ayrıklaştırma (feature discretization) teknikleriyle yapılır.

Slayttaki örnekte bir kişinin yaşı 0 ile 150 arasında olsun. Toplumda bilinen yaş grupları vardır: çocukluk (belki 12'ye kadar), ergenlik, yetişkinlik, orta yaş, yaşlılık. Bu aralıklar zamanla değişebilir de. Ayrıklaştırmada iki soru önemlidir:

- Kesim noktaları (cut-off points) nasıl belirlenecek?
- Kesimden sonra her aralığı temsil edecek değer nasıl seçilecek?

Önceki derste görülen yumuşatma tekniklerinde önce kaç aralığa bölüneceğine karar verilir. Eşit frekanslı bölmede değerler olabildiğince eşit sayıda (örneğin 3, 3, 4) sepete (bin) dağıtılır. Ardından her sepet için bir temsilci seçilir: ortalama, mod, medyan ya da sınır değerler gibi.

## 9. ChiMerge Tekniği

### 9.1 Algoritmanın Adımları

ChiMerge, ki-kare istatistiğini kullanarak ayrıklaştırma yapan bir tekniktir. Üç temel adımdan oluşur (ekrandan, 02:05:00):

1. Öz niteliğin değerlerini küçükten büyüğe sırala.
2. Başlangıç aralıklarını, öz niteliğin her değeri ayrı bir aralıkta olacak şekilde tanımla. Böylece başlangıçta örnek sayısı kadar aralık olur.
3. Komşu iki aralığın ki-kare değeri eşikten küçük olduğu sürece birleştirmeye devam et.

Slaytın devamında şöyle yazıyordu: Her birleştirmeden sonra kalan aralıklar için ki-kare testleri yeniden hesaplanır ve ki-kare değeri en küçük olan iki komşu aralık bulunur. Hesaplanan değer eşikten küçükse bu aralıklar birleştirilir. Birleştirme mümkün değilse ve aralık sayısı kullanıcının belirlediği üst sınırdan büyükse eşik değeri artırılır. Her iterasyonda yalnız bir birleştirme yapılır.

### 9.2 Ki-Kare Testi ve Olumsallık Tablosu

Ki-kare formülü:

$$\chi^2=\sum_{i=1}^{2}\sum_{j=1}^{k}\frac{(A_{ij}-E_{ij})^2}{E_{ij}},\qquad E_{ij}=\frac{R_i\,C_j}{N}$$

- $i=1,2$: birbirine komşu iki aralık.
- $j=1,\dots,k$: sınıflar; $k$ sınıf sayısıdır.
- $A_{ij}$: $i$. aralıkta $j$. sınıfa ait örnek sayısı.
- $E_{ij}$: $A_{ij}$'nin beklenen frekansı.
- $R_i$: $i$. aralıktaki toplam örnek sayısı; $C_j$: $j$. sınıfa ait toplam örnek sayısı; $N$: toplam örnek sayısı.

Hoca, slayttaki formülü denklem düzenleyicide yazarken farkın karesini unuttuğunu, bunun yazılması gerektiğini ve sonraki işlemlerde zaten karenin alındığını belirtti.

İki sınıflı ($k=2$) bir problemde iki aralığın birleştirilmesi için 2x2'lik olumsallık tablosu (contingency table) şöyledir (ekrandan, 02:20:00):

| | Sınıf 1 | Sınıf 2 | Toplam |
|---|---|---|---|
| Aralık 1 | $A_{11}$ | $A_{12}$ | $R_1$ |
| Aralık 2 | $A_{21}$ | $A_{22}$ | $R_2$ |
| Toplam | $C_1$ | $C_2$ | $N$ |

Satır toplamları aralıklardaki örnek sayılarını, sütun toplamları sınıflardaki örnek sayılarını verir. $N=C_1+C_2=R_1+R_2$'dir.

### 9.3 Sayısal Örnek

Sıralı, sürekli bir F öz niteliği ve K sınıfları verilmiştir (ekrandan, 02:25:00):

| Örnek | F | K |
|---|---|---|
| 1 | 1 | 1 |
| 2 | 3 | 2 |
| 3 | 7 | 1 |
| 4 | 8 | 1 |
| 5 | 9 | 1 |
| 6 | 11 | 2 |
| 7 | 23 | 2 |
| 8 | 37 | 1 |
| 9 | 39 | 2 |
| 10 | 45 | 1 |
| 11 | 46 | 1 |
| 12 | 59 | 1 |

(Slaytta 10. örneğin numarası yanlışlıkla "1" yazılmış.) Aralıklar bölünürken aynı sınıfa ait örneklerin olabildiğince aynı aralıkta kalması istenir. Örneğin ilk beş örneğin çoğu 1. sınıftadır; gözle bakınca 1'den 9'a kadar değerlerin aynı aralıkta kalması gerektiği düşünülebilir. Ama ayrıklaştırma gözle değil, algoritmayla yapılır.

**Adım 1: [7,5-8,5] ve [8,5-10] aralıkları.** Birinci aralıkta yalnız 8 (sınıf 1), ikincide yalnız 9 (sınıf 1) vardır. İkisi de aynı sınıfta olduğu için sezgisel olarak birleşeceği beklenir.

| | K=1 | K=2 | Toplam |
|---|---|---|---|
| [7,5-8,5] | 1 | 0 | $R_1=1$ |
| [8,5-10] | 1 | 0 | $R_2=1$ |
| Toplam | $C_1=2$ | $C_2=0$ | $N=2$ |

$\chi^2=0.2$. Serbestlik derecesi 1 için seçilen eşik 2,706'dır; $0.2<2.706$ olduğu için aralıklar birleştirilir ve [7,5-10] aralığı oluşur.

> **Ek bilgi (derste anlatılmadı):** Burada $C_2=0$ olduğu için $E_{12}=E_{22}=0$ çıkar ve formülde sıfıra bölme oluşur. Yöntemin yaygın uygulamasında bu durumda beklenen frekans yerine küçük bir sabit (büyük olasılıkla 0,1) konur. Bu varsayımla $\chi^2=0+0.1+0+0.1=0.2$ bulunur (python ile doğrulandı). 2,706 değeri, ki-kare dağılımında serbestlik derecesi 1 ve anlamlılık düzeyi 0,1 için kritik değerdir.

**Adım 2: [0-7,5] ve [7,5-10] aralıkları.** Algoritma bir süre ilerledikten sonra bu iki aralık oluşmuş olsun. İlk aralıkta 1 (sınıf 1), 3 (sınıf 2), 7 (sınıf 1); ikincide 8 ve 9 (ikisi de sınıf 1) vardır. Hoca sınıfa bu iki aralığın birleşip birleşmeyeceğini sordu; ağırlıklı olarak 1. sınıf örnekleri olduğu için birleştirilebilir cevabı verildi.

| | K=1 | K=2 | Toplam |
|---|---|---|---|
| [0-7,5] | 2 | 1 | 3 |
| [7,5-10] | 2 | 0 | 2 |
| Toplam | 4 | 1 | 5 |

Beklenen frekanslar: $E_{11}=3\cdot4/5=2.4$, $E_{12}=3\cdot1/5=0.6$, $E_{21}=2\cdot4/5=1.6$, $E_{22}=2\cdot1/5=0.4$ (ara adım eklendi).

$$\chi^2=\frac{0.4^2}{2.4}+\frac{0.4^2}{0.6}+\frac{0.4^2}{1.6}+\frac{0.4^2}{0.4}=0.067+0.267+0.1+0.4\approx 0.834$$

$0.834<2.706$ olduğu için birleştirilir ve [0-10] aralığı oluşur.

**Adım 3: [0-10] ve [10-42] aralıkları.** Algoritma ilerledikten sonra [0-10], [10-42] ve [42-60] diye üç aralık oluşmuş olsun. [0-10] ile [10-42] test edilir. İlk aralıkta 1, 3, 7, 8, 9 (dördü sınıf 1, biri sınıf 2); ikincide 11, 23, 37, 39 (biri sınıf 1, üçü sınıf 2) vardır.

| | K=1 | K=2 | Toplam |
|---|---|---|---|
| [0-10] | 4 | 1 | 5 |
| [10-42] | 1 | 3 | 4 |
| Toplam | 5 | 4 | 9 |

Beklenen frekanslar: $E_{11}=25/9\approx2.78$, $E_{12}=E_{21}=20/9\approx2.22$, $E_{22}=16/9\approx1.78$; her hücrede $|A_{ij}-E_{ij}|\approx1.22$ (ara adım eklendi).

$$\chi^2\approx 2.72>2.706$$

Değer eşikten büyük olduğu için birleştirme önerilmez (merging is not recommended). Üç ki-kare değeri python ile doğrulandı.

**Soru:** 2,706 eşik değerini biz mi belirliyoruz?
**Cevap:** Bu değer istatistikteki ki-kare dağılımı tablosundan alınır. Ama kesin bir kural yoktur: Elde çok fazla aralık kalıyorsa ve daha fazla birleştirme isteniyorsa eşik büyütülebilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): Tabloda iki girdi öz niteliği (X, Y) ve örnekleri A, B sınıflarına ayıran C öz niteliği verilmiştir. Uygulanan testin eşik değeri 0,5'tir. X ve Y'nin indirgeme adayı olup olmadığına karar verin.

| X | Y | C |
|---|---|---|
| 0.3 | 0.7 | A |
| 0.2 | 0.9 | B |
| 0.6 | 0.6 | A |
| 0.5 | 0.5 | A |
| 0.7 | 0.7 | B |
| 0.4 | 0.9 | B |

> **Çözüm (derste verildi, ekrandan, 00:55:00):** Ortalamalar $0.4667$, $0.4333$ (X) ve $0.6$, $0.8333$ (Y). Slayttaki test değerleri X için $0.0735<0.5$, Y için $2.6667>0.5$. X indirgeme adayıdır, Y tutulur. Doğru varyansla ($var(X_B)=0.0633$) X'in test değeri yaklaşık 0,196'dır, sonuç aynıdır (bkz. 5.3).

**Soru 2** (derste sözlü, 00:35:06): Bu veri setinde kaç örnek ve sınıf hariç kaç öz nitelik vardır?

> **Cevap (derste verildi):** 6 örnek, 2 öz nitelik.

**Soru 3** (derste sözlü, 00:46:11): Bir öz nitelikte iki sınıfın dağılımlarını ayırt etmek hangi durumda daha kolaydır: standart sapma büyükken mi, küçükken mi?

> **Cevap (derste verildi):** Küçükken. Küçük standart sapmalı dağılımlar ortalamaya toplanır, iç içe geçmez; bu yüzden test formülünün paydasında küçük bir terim istenir.

**Soru 4** (ekrandan, 01:45:00): Tablodaki üç kategorik öz nitelikli veri seti için $S_{1,4}$ ve $S_{3,5}$ benzerliklerini hesaplayın.

> **Çözüm (derste verildi):** $S_{1,4}$: F2 ve F3 eşleşir, $2/3$. $S_{3,5}$: yalnız F1 eşleşir, $1/3$.

**Soru 5** (derste sözlü, 02:29:12): ChiMerge örneğinde [0-7,5] ve [7,5-10] aralıkları sınıf etiketlerine bakılarak birleştirilebilir mi?

> **Çözüm (derste verildi):** Birleştirilebilir; aralıklarda ağırlıklı olarak 1. sınıf örnekleri vardır. Ki-kare testi de $0.834<2.706$ verir.

**Soru 6** (derste sözlü, 02:31:28): [0-10] ve [10-42] aralıklarını ki-kare testine koyun; birleştirilebilir mi?

> **Çözüm (derste verildi):** Tablo [[4,1],[1,3]], $\chi^2\approx2.72>2.706$; birleştirme önerilmez.

## Dersin Toparlaması

Bu derste veri indirgemenin üç ekseni (öz nitelik, örnek, değer) ve indirgemenin hesaplama süresi, başarı ve gösterim üzerindeki kazançları ile bunlar arasındaki denge ele alındı. Öz nitelik indirgemede seçim ile birleştirme ayrıldı. Gözetimli seçim için ortalama ve varyansa dayalı test, sınıf etiketi olmadan seçim için normalize Öklid uzaklığı, kategorik benzerlik ve benzerlik matrisinden hesaplanan entropiye dayalı geriye doğru sıralama algoritması anlatıldı. Değer indirgemede öz nitelik ayrıklaştırma ve komşu aralıkları ki-kare testiyle birleştiren ChiMerge tekniği sayısal bir örnekle gösterildi.

Öz nitelik birleştirmenin temel yöntemi olan temel bileşen analizi (PCA), özdeğer-özvektör ve kovaryans hatırlatmasıyla birlikte bir sonraki derste anlatılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
