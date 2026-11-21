# Ders 7 Genişletilmiş Notu: Rekabetçi Yapay Sinir Ağları: MaxNet, Mexican Hat, Hamming Ağı ve Kohonen SOM

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Rekabetçi ağlara giriş
- 2. Kümeleme ağının yapısı ve exemplar vektör
- 3. Kohonen öğrenme kuralı
- 4. Yakınlık ölçütleri: Öklid mesafesi ve açı
- 5. MaxNet
- 6. Exemplar vektör nereden gelir? (soru-cevap)
- 7. Mexican Hat
- 8. Hamming ağı
- 9. Kohonen Self-Organizing Map (SOM)
- 10. SOM uygulamaları: karakter kümeleme ve gezgin satıcı problemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Rekabetçi Ağlara Giriş

Hoca bu derste klasik yapay sinir ağları kısmını kapatmayı amaçladığını söyler. RBF ve tekrarlayan ağlar (RNN, LSTM) derin öğrenme konularına geçildiğinde ele alınacaktır. Bu dersin konusu rekabetçi (competitive) yapay sinir ağlarıdır. Slayttaki konu listesi şöyledir (ekrandan, 00:05:00):

- Giriş
- Sabit ağırlıklı rekabetçi YSA'lar: MaxNet, Mexican Hat, Hamming Net
- Kohonen Self Organizing Maps (SOM)
- LVQ
- Ters yayılım ağları

Rekabetçi ağlar şimdiye kadar görülen ağlardan farklıdır: mutlaka bir kazanan olması beklenir. Çıkışta "%90 bu sınıf, %10 şu sınıf" gibi kararsız bir sonuç istenmez, kesin bir seçim yapılmak istenir. Bu yüzden bu yapılar daha çok kümelemeye (clustering) uygundur. Bir girdi birden fazla kategoriye ait görünüyorsa ve onu tek bir kategoriye sınıflamak gerekiyorsa, bunu zorlayacak bir rekabet mekanizması gerekir. Bu mimariler bu ihtiyaçtan doğmuştur.

Rekabetin en uç örneği **Winner Take All (WTA)** yapısıdır: ağ mutlaka tek bir nöronun ya da tek bir kümenin kazanmasına zorlanır. MaxNet bu türün tipik örneğidir. **Mexican Hat** yapısında ise daha genel bir rekabet vardır. Belli bir epok sayısından sonra kazanan belirginleşir, ama diğerlerinin olasılıklarının düşmesi yeterli bulunur; diğerleri doğrudan kaybeden ilan edilmez.

Öğrenme açısından iki tür vardır: eğitim çiftlerini kullanan supervised yapılar ve verilerin ortak özelliklerine, vektörlerin yakınlığına bakarak kümeleyen unsupervised yapılar. Slayttaki tanım şöyledir (ekrandan, 00:10:00):

- YSA'ların öğrenme şekli, geliştirilme sebebiyle ilgilidir.
- LVQ ve ters yayılım YSA'lar haritalama (mapping) için, yani girdi ile çıktı arasındaki ilişkiyi kurmak için geliştirildiğinden öğrenme şekilleri supervised'dır.
- SOM ise girdi verisinin gruplanması (kümelenmesi) için geliştirildiğinden öğrenme şekli unsupervised'dır.

## 2. Kümeleme Ağının Yapısı ve Exemplar Vektör

Bir kümeleme ağında girdi vektörünün bileşen sayısı kadar giriş birimi vardır. Girdi vektörü $D$ bileşenli ise $D$ giriş nöronu olur. Çıkış birimlerinin sayısı, oluşturulmak istenen küme sayısına bağlıdır: $M$ sınıf oluşturulmak isteniyorsa $M$ çıkış nöronu olur. Buradaki öğrenme, daha önce görülen hata tabanlı öğrenme algoritmalarına benzemez; benzerliklere bakarak bir rekabet oluşturur. Hesaplamanın ve öğrenmenin yapıldığı çıkış katmanına bu yüzden özel olarak **rekabetçi katman (competitive layer)** denir.

Kümeleme ağında bir çıktının ağırlık vektörü, o çıktının temsil ettiği küme ile girdi desenleri arasındaki ilişkiyi kuran örnek bir vektördür. Hocanın "özellikle bilmeniz gereken terim" dediği kavram budur:

> **Hocanın vurgusu:** Representative, exemplar ya da codebook vektör denildiğinde, bir kümeyi temsil ettiği varsayılan ağırlık vektörü ya da o kümeye ait bir vektör kastedilir.

Örneğin üç küme varsa, bunları temsil eden üç exemplar vektör gerekir. Genellikle bu vektör, kümedeki örneklerin (ya da ağırlıklarının) ortalamasıdır. Hoca tanımı biraz "yuvarlak" yaptığını, çünkü algoritmalarda farklı biçimlerde kullanıldığını söyler; sonuçta kümenin temsilcisi, o kümeye düşen bütün örnekleri yansıtmalıdır.

Sınıflama şöyle yapılır: elimizdeki (test edilecek) vektör bütün kümelerin exemplar vektörleriyle kıyaslanır ve hangisine yakınsa o kümeye dahil edilir. Ardından kazanan birim için, kullanılan öğrenme algoritmasına göre ağırlık güncellemesi yapılır. Sonunda kümeler oluşmuş olur.

## 3. Kohonen Öğrenme Kuralı

Bu bölümdeki ağlar genel olarak Kohonen öğrenme algoritmasını kullanır. Slayttaki tanım şöyledir (ekrandan, 00:15:00):

- Bu algoritmada ağırlık vektörü giriş vektörüne en yakın birimin öğrenmesine izin verilir; yani en yakın birimin ağırlığı güncellenir. Yakınlık Öklid mesafesiyle ölçülür.
- Öğrenme için ağırlık güncelleme fonksiyonu:

$$w_{.j}(new) = w_{.j}(old) + \alpha\left[x - w_{.j}(old)\right] = \alpha x + (1-\alpha)\, w_{.j}(old)$$

- Burada $x$ girdi vektörü, $w_{.j}$ $j$ birimi için ağırlık vektörü, $\alpha$ öğrenme oranıdır (learning rate).
- Not: Bu yapılarda $\alpha$ işlem boyunca azalır.

Kohonen kuralının söylediği bilinenlerden çok farklı değildir. Ağırlık vektörü ile giriş vektörü Öklid mesafesiyle kıyaslanır, yani bileşenlerin karesel farklarına bakılır. Hangi kümenin exemplar vektörüne yakınsa yalnız onun ağırlığı güncellenir; diğerleri güncellenmez, çünkü örnek yalnız bir kümeye ait olacaktır.

Güncellemenin sezgisi şudur: ağırlık vektörü kümedeki elemanların bir ortalaması gibidir. Kümeye yeni bir eleman katıldığında, bu eleman diğerlerinden az da olsa farklı olacağından kümeyi temsil eden vektöre onun katkısı da yansıtılmalıdır. Yeni örnek kümenin temsilini değiştirir, bu yüzden kümeyi temsil eden ağırlık vektörü de değişir.

Öğrenme katsayısı konusunda hoca bir fark vurgular: şimdiye kadarki ağlarda öğrenme katsayısı pek değiştirilmedi, ama rekabetçi ağlarda genellikle işlem boyunca azaltılır. Çoğu zaman her epokta yarıya indirilerek değişken biçimde ayarlanır.

## 4. Yakınlık Ölçütleri: Öklid Mesafesi ve Açı

En yakın ağırlık vektörünü belirlemenin iki yolu vardır. Birincisi karesel Öklid yakınlığıdır. İkincisi, bazı algoritma ve uygulamalarda kullanılan, girdi vektörü ile ağırlık vektörünün noktasal çarpımıdır. Hoca burada korelasyon ve konvolüsyonun da noktasal çarpımdan hesaplandığını hatırlatır. Noktasal çarpım iki vektör arasındaki açının kosinüsüyle ilgili bilgi verir: noktasal çarpımın büyük olması, vektörler arasındaki açının küçük ve korelasyonun yüksek olduğu anlamına gelir.

Slayttaki formüller şöyledir (ekrandan, 00:20:00):

$$\|x - x_i\| = \sqrt{(x - x_i)^t (x - x_i)}$$

$$\cos\psi = \frac{x^t x_i}{\|x\|\,\|x_i\|}$$

Öklid mesafesi, iki vektörün farkının normu olarak da düşünülebilir. Vektörün karesini alırken çarpımın boyutları uygun olsun diye transpozu ile kendisi çarpılır, sonra karekök alınır. Slayttaki şekilde iki küme ve bunları temsil eden $x_1$ ve $x_2$ exemplar vektörleri vardır. Yeni bir $x$ örneği için $x$ ile $x_1$ ve $x$ ile $x_2$ arasındaki mesafe ayrı ayrı hesaplanır, hangisi daha yakınsa örnek o kümeye atılır.

Açı yaklaşımında $x$'in $x_1$ ile ve $x_2$ ile oluşturduğu açıların kosinüsleri hesaplanır. İki vektörün noktasal çarpımı, normlarının çarpımı ile aralarındaki açının kosinüsünün çarpımına eşittir: $x^t x_i = \|x\|\|x_i\|\cos\psi$. Formül bu ifadeden $\cos\psi$ çekilerek elde edilir. Bu, kosinüs benzerliği olarak da bilinen bir yakınlık ölçütüdür. İstenirse ark kosinüs alınarak açının kendisi bulunur. Slayttaki şekilde $\psi_1 < \psi_T < \psi_2$ ilişkisi gösterilir.

## 5. MaxNet

### 5.1 Sabit ağırlıklı ağlar ve MaxNet'in görevi

Sabit ağırlıklı rekabetçi ağlarda nöronların bağlantı ağırlıkları hiç değişmez. Yalnız kümeyi temsil eden vektörle ilgilenilir. MaxNet en büyük girişi olan düğümü seçmek için alt ağ olarak kullanılan bir yapıdır. Hocaya göre kendi başına çok anlamlı değildir: nöronları yarıştırıp birini kazanan ilan etmeye yarar.

Normal kullanım yeri şöyledir: önce probleme yönelik başka bir ağ (bir perceptron, çok katmanlı bir ağ ya da bir kümeleme algoritması) çalıştırılmıştır ve sonuç, örneğin birden fazla kümeye ait olabileceğini söylemektedir. Kümelerden birinin seçilmesi gerekiyorsa o ağın sonuna MaxNet eklenir ve yapı bir karar vermeye zorlanır.

Mimari tam bağlıdır (fully connected). Her nöronun kendine bir bağlantısı vardır ve bu bağlantının ağırlığı $1$'dir. Nöronlar arasındaki bütün bağlantılar ise aynı sabit ağırlıktadır: $-\epsilon$. Böylece ağırlık matrisi köşegeni $1$, diğer elemanları eşit olan simetrik bir matristir.

### 5.2 Algoritma

Slayttaki akış ve formüller şöyledir (ekrandan, 00:25:00):

```text
start
  aktivasyonları ve ağırlıkları initialize et
  durma koşulu = false olduğu sürece:
      her birimin aktivasyonunu güncelle
      aktivasyonları sonraki iterasyon için sakla
      kontrol
end
```

- Başlangıç: $0 < \epsilon < \dfrac{1}{m}$; $a_j(0)$, $A_j$ düğümünün girdisidir.
- Ağırlıklar: $w_{ij} = 1$ ($i = j$ ise), $w_{ij} = -\epsilon$ ($i \neq j$ ise).
- Güncelleme: $a_j(new) = f\left[a_j(old) - \epsilon \sum_{k \neq j} a_k(old)\right]$, $j = 1, \ldots, m$; sonra $a_j(old) = a_j(new)$.
- Aktivasyon: $f(x) = x$ ($x \geq 0$ ise), $f(x) = 0$ (diğer durumda).
- Slayttaki not: "Sadece 1 birim sıfırdan farklı bir değer alabilir!"

Başlangıç aktivasyonları büyük olasılıkla MaxNet'ten önce kullanılan ağdan gelir. Durma koşulu, bir nöron pozitif kalıp diğer bütün aktivasyonlar sıfır olana kadar devam etmektir. İstenirse bir maksimum epok sayısı konabilir, ama yapı zaten birinin kazanmasını sağladığı için buna pek gerek yoktur. Her iterasyonda nöronun girdisi hesaplanır: nöronun o andaki değeri ile diğer nöronlardan gelen $-\epsilon$ ağırlıklı değerler toplanır ve aktivasyon fonksiyonu uygulanır. Aktivasyon fonksiyonu sıfırdan büyük değerleri olduğu gibi bırakır, diğerlerini sıfıra çeker.

### 5.3 Sayısal örnek

Hoca örneği şöyle yorumlar: dört küme vardır ve önceki bir ağ, verilen girdinin bu kümelere ait olma olasılıklarını üretmiştir. Buradaki nöronların her biri bir girdi değil, bir kümeyi temsil eder. Önceki ağın kararı "örnek %20 $A_1$'e, %40 $A_2$'ye, %40 $A_3$'e, %80 $A_4$'e ait" gibidir. Bu yeterince net değilse MaxNet çalıştırılır. Örnek basit olduğu için gözle %80'i seçmek mümkündür, ama MaxNet bu işlemi otomatikleştirir.

Slayttaki örnek şöyledir (ekrandan, 00:30:00):

- 4 nörondan oluşan bir MaxNet, $\epsilon = .2$, girdi sinyalleri $a_1(0) = .2$, $a_2(0) = .4$, $a_3(0) = .4$, $a_4(0) = .8$.
- Aktivasyon değişimi örnek olarak $a_1(1)$ için:

$$a_1(1) = f\{a_1(0) - \epsilon[a_2(0) + a_3(0) + a_4(0)]\} = f(0.2 - 0.2 \cdot (0.4 + 0.4 + 0.8)) = f(-0.12) = 0$$

$A_1$'in değeri $0.2$ iken $0$'a düşer; yani $A_1$ daha ilk iterasyonda kaybetmiştir ve bu kümenin artık hiç şansı kalmamıştır.

Beş iterasyon boyunca aktivasyonlar slaytta şöyle verilir (ekrandan, 00:35:00):

| İterasyon | $a_1$ | $a_2$ | $a_3$ | $a_4$ |
|---|---|---|---|---|
| 1 | .0 | .08 | .32 | .56 |
| 2 | .0 | .0 | .192 | .48 |
| 3 | .0 | .0 | .096 | .442 |
| 4 | .0 | .0 | .008 | .422 |
| 5 | .0 | .0 | .0 | .421 |

İkinci turda $A_2$ sıfıra düşer. Üçüncü ve dördüncü turda yeni kaybeden yoktur ama $A_3$ ve $A_4$'ün değerleri azalır. Beşinci iterasyonda $A_3$ de sıfıra iner. Üç nöron sıfır, bir nöron pozitif kalmıştır: kazanan küme $A_4$'tür ve girdi bu kümeye atanır.

> **Ders sonrası not:** Slayttaki iterasyon tablosu $a_3(0) = .6$ başlangıcına aittir; python ile kontrol edildiğinde $(.2, .4, .6, .8)$ girdisi tablodaki değerleri birebir verir (örneğin $a_2(1) = 0.4 - 0.2(0.2 + 0.6 + 0.8) = 0.08$). Slaytta yazılı $a_3(0) = .4$ ile hesaplanırsa birinci iterasyon $(0, .12, .12, .60)$, ikinci iterasyon $(0, 0, 0, .552)$ olur ve $A_4$ ikinci iterasyonda tek başına kalır. $a_1(1)$ için gösterilen $-0.12$ de $.4$ ile yapılmıştır; $.6$ ile $-0.16$ çıkar. Her iki durumda kazanan $A_4$'tür.

## 6. Exemplar Vektör Nereden Gelir? (Soru-Cevap)

Aradan sonra hoca, aranın öncesinde sohbetten gelen bir soruya döner.

**Soru:** Mesafeleri hesapladık, ama kümeyi temsil eden vektöre olan mesafeyi hesapladık; bu vektör nereden geliyor? Kümeleme yapmadan önce sınıfların çok iyi tanımlı olması gerekmez mi?

**Cevap:** Evet. Bir küme tanımlanırken o kümede olması istenen belli özellikler ya da kümeyi temsil eden bazı örnekler olur. Unsupervised öğrenme yapılsa bile "araba dediğim şey nasıl bir şeydir" sorusunun örneği gösterilmelidir; az miktarda etiketlenmiş veri unsupervised öğrenmede de kullanılır. Hoca araba ve gemi kümeleri örneğini verir. Araba kümesine ait az sayıda etiketli örnek, motor kapasitesi, büyüklük, teker sayısı gibi parametrelerle sayısallaştırılırsa her örnek bir vektör olur. Bu vektörlerin bileşen bileşen ortalaması alınırsa küme için bir ortalama vektör elde edilir. Bu, exemplar vektör olarak kullanılabilir. Örneklerin her biri tek başına da exemplar olabilir, ama kümeyi daha genel temsil etmek için en iyisi ortalamayı almaktır. Hiçbir temsil vektörü yoksa bu yöntemler kullanılamaz; hiç değilse problemi temsil eden 3-5 veri etiketlenmelidir. Bir tane de olabilir, iki tane daha iyidir. Derste exemplar vektörler hazırmış gibi davranılır, ama gerçekte önce kümeyi tanımlamak ve onu temsil eden exemplar'ı gerçek örneklerden oluşturmak gerekir.

## 7. Mexican Hat

### 7.1 Mimari

Mexican Hat, MaxNet'ten daha genel bir yapıdır. Bütün nöronları sıfırlayıp tek kazanan bırakmaz; belli bir nöron ve çevresindeki birkaç nöron öne çıkar. Nöronların bazı komşuları **işbirlikçi**, bazıları **rekabetçi** komşu sayılır. Her nöronun kendi işbirlikçi ve rekabetçi komşuları vardır; bir nöron için işbirlikçi olan, başka bir nöron için rekabetçi olabilir. İşbirlikçi komşulara pozitif, rekabetçi komşulara negatif ağırlıkla bağlanılır. Daha uzaktaki nöronlarla hiç bağlantı yoktur.

MaxNet gibi Mexican Hat de çoğunlukla başka bir ağın devamında kullanılır. Dışarıdan aldığı aktivasyon, daha önce uygulanmış bir yapının kesin olmayan sonucudur. Mexican Hat bu sonucu netleştirmek için kullanılır.

Slayttaki mimaride (ekrandan, 00:40:00) $X_i$ nöronunun kendine bağlantısı $w_0$, iki yanındaki $X_{i \pm 1}$ ve $X_{i \pm 2}$ nöronlarına bağlantıları $w_1$ ve $w_2$ (pozitif bağlantı), $X_{i \pm 3}$ nöronlarına bağlantısı $w_3$ (negatif bağlantı) ile gösterilir. $X_{i \pm 4}$ ve ötesi bağlantısızdır. Aşağıdan gelen $s_i$, external aktivasyondur. Yani bu şekilde iki komşuya kadar işbirlikçi, üçüncü komşu rekabetçi kabul edilmiştir. Hangi uzaklıktaki komşuların işbirlikçi, hangilerinin rekabetçi olacağına tasarımcı karar verir; komşuluk alanının boyutu ayarlanabilir bir parametredir.

Bir nöronun değeri değiştiğinde ona bağlı bütün nöronlar da (pozitif ya da negatif yönde) değişir. Belli sayıda iterasyondan sonra nöronların aktivasyon değerleri çizildiğinde Meksika şapkasına benzer bir şekil çıkar: tepedekiler kazanan nöronlar, yanlarda yükselen pozitif bölge ve aşağıda değeri küçülmüş kaybeden nöronlar. Bu şekil hemen değil, belli bir epoktan sonra oluşur ve yapının adı buradan gelir. Slaytın sağ altındaki $w_{ij}$ - $(i-j)$ grafiği de ortada pozitif, iki yanda negatif ağırlıkları gösterir.

### 7.2 Tanımlar ve algoritma

Slayttaki tanımlar şöyledir (ekrandan, 01:05:00):

- $R_2$: $X$ biriminin bağlı olduğu birim sayısı.
- $R_1$: $X$ biriminin pozitif bağlı olduğu birim sayısı; $R_1 < R_2$.
- $w_k$: $X$ birimi bağlantılarının ağırlıkları; $0 \leq k \leq R_1$ için $w_k$ pozitif.
- $x$: aktivasyon vektörü; $x\_old$: bir önceki adımın aktivasyon vektörü.
- $t\_max$: toplam iterasyon sayısı; $s$: external sinyal.

Hoca derste $R_2$'yi genel olarak dikkate alınan komşu alanı (şekildeki dış elips), $R_1$'i pozitif komşuların alanı olarak anlatır. $R_2$ dışındaki nöronlar dikkate alınmaz. Algoritmayı çalıştırmak için $R_1$, $R_2$ ve bağlantı ağırlıkları başlangıçta belirlenmelidir.

Aktivasyon vektörü, her kümenin başlangıçtaki değeridir. Hoca bunu exemplar fikrine bağlar: beş etiketli örneğin ortalamasıyla bir temsil vektörü kurulabiliyorsa, her yeni örnek gösterildiğinde bir örnek daha eklenmiş gibi olur ve kümeyi temsil eden vektör değişebilir.

MaxNet'te maksimum iterasyon sayısı önemli değildi, çünkü bir kazanan çıkması gerekiyordu. Mexican Hat'te ise bazı nöronların değeri yükselir, bazılarınınki düşer ve eğitim istenen bir noktada kesilebilir. Bu yüzden $t\_max$ kullanılır.

Slayttaki akış ve formüller (ekrandan, 01:10:00):

```text
start
  t_max, R1, R2 parametrelerini set et
  external sinyali ata x = s; aktivasyonları x_old'a set et (x_old_i = x_i);
  iterasyon sayacını set et t = 1
  t < t_max olduğu sürece:
      net inputu hesapla
      aktivasyon fonksiyonunu hesapla
      geçerli aktivasyonları x_old'a set et; t++
end
```

- Ağırlıklar: $w_{ij} = C_1 > 0$ ($k = 0, \ldots, R_1$ için), $w_{ij} = C_2 < 0$ ($k = R_1 + 1, \ldots, R_2$ için). $x\_old$ başlangıçta $0$.
- Net input:

$$x_i = C_1 \sum_{k=-R_1}^{R_1} x\_old_{i+k} + C_2 \sum_{k=-R_2}^{-R_1-1} x\_old_{i+k} + C_2 \sum_{k=R_1+1}^{R_2} x\_old_{i+k}$$

- Aktivasyon fonksiyonu:

$$f(x) = \begin{cases} 0 & x < 0 \\ x & 0 \leq x \leq x\_max \\ x\_max & x > x\_max \end{cases} \qquad x_i = \min(x\_max, \max(0, x_i)), \quad i = 1, \ldots, n$$

Formül uzun görünür, çünkü pozitif ve negatif komşuların toplamları ayrı yazılmıştır. Özünde yine "ağırlık çarpı girdi" toplamıdır: işbirlikçilere $C_1$, rekabetçilere $C_2$ ağırlığı verilir. Kendine bağlantısı da olduğu için nöronun kendi değeri de toplamın içindedir. Aktivasyon fonksiyonu üç parçalıdır: sıfırdan küçük değerler sıfıra, belirlenen maksimumdan büyük değerler maksimuma çekilir, aradaki değerler olduğu gibi kullanılır.

**Soru:** (sohbetten) Mexican Hat'in şekli görüntü işlemedeki Gauss filtresine benziyor mu?

**Cevap:** Evet, şekil bir Gauss eğrisine benzer; yapılan işlemler anlamında Gauss benzeri bir çıktı oluşturduğu söylenebilir. Hoca örnek bittikten sonra bu soruya döner: buradaki aktivasyon fonksiyonu sağı ve solu sıfırladığı için şekil daha keskindir. Alt sınır sıfır yerine küçük bir değer olsaydı ya da daha genel bırakılsaydı, yanlarda olasılığı düşük uzantılar ve şapkanın negatif kenarları da oluşurdu.

### 7.3 Sayısal örnek

Örnekte 7 nöronlu bir ağ vardır. Aktivasyon fonksiyonunda maksimum değer $2$ alınmıştır. $R_1 = 1$, $R_2 = 2$ seçilmiştir: her nöronun sağındaki ve solundaki birinci komşular pozitif, ikinci komşular negatif komşudur; ötesi işleme alınmaz. Hoca, mimari şeklinin üç komşuya kadar çizildiğini, bu örneği doğrudan yansıtmadığını uyarır. Pozitif bağlantı ağırlığı $0.6$, negatif bağlantı ağırlığı $-0.4$'tür (hoca sözlü olarak "0.4" der, slayttaki denklemlerde eksi işaretlidir). Nöronların başlangıç değerleri simetrik olarak $0,\ 0.5,\ 0.8,\ 1,\ 0.8,\ 0.5,\ 0$'dır.

En soldaki nöronun solunda komşusu yoktur; bu yüzden ona diğer nöronlardan daha az besleme gelir. İkinci nöronun solunda bir pozitif komşusu vardır ama negatif komşusu yoktur. Üçüncü nöronun iki yanında da bütün bağlantılar bulunur. Slayttaki denklemler şöyledir (ekrandan, 01:15:00):

$$\begin{aligned}
x_1 &= 0.6\, x\_old_1 + 0.6\, x\_old_2 - 0.4\, x\_old_3 \\
x_2 &= 0.6\, x\_old_1 + 0.6\, x\_old_2 + 0.6\, x\_old_3 - 0.4\, x\_old_4 \\
x_3 &= -0.4\, x\_old_1 + 0.6\, x\_old_2 + 0.6\, x\_old_3 + 0.6\, x\_old_4 - 0.4\, x\_old_5 \\
x_4 &= -0.4\, x\_old_2 + 0.6\, x\_old_3 + 0.6\, x\_old_4 + 0.6\, x\_old_5 - 0.4\, x\_old_6 \\
x_5 &= -0.4\, x\_old_3 + 0.6\, x\_old_4 + 0.6\, x\_old_5 + 0.6\, x\_old_6 - 0.4\, x\_old_7 \\
x_6 &= -0.4\, x\_old_4 + 0.6\, x\_old_5 + 0.6\, x\_old_6 + 0.6\, x\_old_7 \\
x_7 &= -0.4\, x\_old_5 + 0.6\, x\_old_6 + 0.6\, x\_old_7
\end{aligned}$$

Başlangıç değerleriyle bir tur hesaplanır, sonra aynı işlem tekrarlanır. Derste gösterilen grafikte $t = 0$, $t = 1$ ve $t = 2$ anlarındaki aktivasyonlar çizilmiştir; ortadaki nöron kazanana yaklaşmaya başlamış, diğerleri zayıflamaktadır. Daha çok iterasyon çalıştırılırsa sivrilik artar. <!-- BELİRSİZ: Ara iterasyon değerlerinin gösterildiği slayt incelenen karelerde yok; aşağıdaki değerler ders sonrası hesaplandı. -->

> **Ders sonrası not:** Slayttaki denklemlerle python'da hesaplanan değerler (eş zamanlı güncelleme, $[0, 2]$ aralığına kırpma): $t = 1$: $(0,\ 0.38,\ 1.06,\ 1.16,\ 1.06,\ 0.38,\ 0)$; $t = 2$: $(0,\ 0.4,\ 1.136,\ 1.664,\ 1.136,\ 0.4,\ 0)$. Örneğin $x_3(1) = -0.4(0) + 0.6(0.5) + 0.6(0.8) + 0.6(1) - 0.4(0.8) = 1.06$. Ortadaki nöron belirgin biçimde yükselmektedir.

## 8. Hamming Ağı

### 8.1 Tanım

Sabit ağırlıklı ağlara son örnek Hamming ağıdır. Slayttaki tanım şöyledir (ekrandan, 01:20:00):

- Bir Hamming ağı, birkaç exemplar vektörden hangisinin $n$ bileşenli (n-tuple) bir girdi vektörüne daha fazla benzediğini belirlemek için kullanılan bir maksimum benzerlik sınıflandırıcısıdır.
- Exemplar vektörler ağın ağırlık matrisini belirler.
- Giriş vektörü ve depolanan exemplar vektörler arasındaki benzerlik ölçüsü $= n - H(x_1, x_2)$.
- İki vektör arasındaki Hamming mesafesi, vektörlerin farklı olduğu bileşenlerin sayısıdır. İki bipolar vektör arasındaki Hamming mesafesi $d = n - a$'dır; $d$ mesafe, $n$ eleman sayısı, $a$ aynı olan (agreement) bit sayısıdır.
- Hamming ağı en büyük inputu bulmak için MaxNet'i kullanır.

Hoca Hamming mesafesinin daha çok bilindiğini, burada ise mesafe yerine benzerliğin kullanıldığını vurgular: $n$'den farklı olanların sayısı çıkarılınca geriye aynı olanların sayısı kalır. Hamming ağı benzerlikleri hesaplar, ama diğer kümenin de bir olasılığı kalır; bu ayrımı yapmak için sonuna MaxNet konur.

Mimaride alt katmanda girdi düğümleri, üstte $Y_1$ ve $Y_2$ çıktıları (iki küme), en üstte de MaxNet vardır. $m$ çıktı sayısıdır, yani exemplar vektör (küme) sayısıdır; bu örnekte $m = 2$.

> **Hocanın vurgusu:** Exemplar vektörler bipolar kullanılır. $1/0$ gösterimiyle Hamming mesafesi doğru hesaplanmaz.

### 8.2 Algoritma

Slayttaki akış ve formüller (ekrandan, 01:25:00):

```text
start
  m adet exemplar vektör kaydetmek için ağırlıkları ve biası set et
  her vektör için:
      net inputu hesapla
      MaxNet için aktivasyon fonksiyonunu hesapla
      MaxNet en uygun exemplar'ı bulmak için iterate eder
end
```

$$w_{ij} = 0.5\, e_i(j), \qquad b_j = 0.5\, n$$

$$y\_in_j = b_j + \sum_i x_i w_{ij}, \qquad y_j(0) = y\_in_j, \quad j = 1, \ldots, m$$

Ağırlıklar exemplar vektörlerin yarısıdır, bias da girdinin bileşen sayısının yarısıdır. Net input her zamanki gibi "bileşen çarpı ağırlık artı bias" ile hesaplanır. Aktivasyon fonksiyonu yoktur (ya da doğrusaldır): çıkan değer, o sınıfın exemplar vektörüne benzerlik ölçüsü olarak MaxNet'e başlangıç değeri verilir. Bu işlem bütün çıktılar için yapılır, sonra MaxNet birini seçer. Gruplanacak bütün vektörler bitene kadar devam edilir.

### 8.3 Sayısal örnek

Girdi dört bileşenlidir ($n = 4$), iki exemplar vektör vardır ($m = 2$). İki exemplar'ın yarıları bir ağırlık matrisinin iki sütununa yazılır: $Y_1$ ile ilgili ağırlıklar sol, $Y_2$ ile ilgili ağırlıklar sağ sütundadır. Bias $4/2 = 2$'dir. Slayttaki örnek (ekrandan, 01:30:00):

- Exemplar'lar: $e(1) = [1, -1, -1, -1]$, $e(2) = [-1, -1, -1, 1]$.
- Girdi $(1, 1, -1, -1)$ için:

$$y\_in_1 = b_1 + \sum_i x_i w_{i1} = 2 + 1 = 3, \qquad y\_in_2 = b_2 + \sum_i x_i w_{i2} = 2 - 1 = 1$$

Ara adım (ara adım eklendi): $\sum_i x_i w_{i1} = 0.5[(1)(1) + (1)(-1) + (-1)(-1) + (-1)(-1)] = 0.5 \cdot 2 = 1$ ve $\sum_i x_i w_{i2} = 0.5[(1)(-1) + (1)(-1) + (-1)(-1) + (-1)(1)] = 0.5 \cdot (-2) = -1$.

Slaytta belirtildiği gibi bu sonuç aslında vektörler arasındaki Hamming benzerliğidir: girdi $e(1)$ ile 1., 3. ve 4. bitlerde aynıdır (3 benzerlik), $e(2)$ ile yalnız 3. bitte aynıdır (1 benzerlik). $y_1(0) > y_2(0)$ olduğu için MaxNet $e(1)$'i seçer.

Hoca burada MaxNet'in neden gerektiğini sorar: iki değer birbirine yakın ya da eşit çıkabilirdi; ikisi de $3$ olsaydı seçim nasıl yapılacaktı? Belli bir kümenin seçilmesi gerekiyorsa bu ikilemden çıkış yolu MaxNet gibi keskin bir rekabetçi ağ kullanmaktır.

Diğer girdiler için derste söylenen değerler şöyledir: ikinci girdi için $y_1 = 4$, $y_2 = 2$ ve MaxNet $Y_1$'i seçer; üçüncü girdi için $y_1 = 2$, $y_2 = 4$ ve kazanan $Y_2$'dir; son girdi için $y_1 = 1$, $y_2 = 3$ ve kazanan $Y_2$'dir. <!-- BELİRSİZ: İkinci, üçüncü ve dördüncü girdi vektörleri incelenen karelerde görünmüyor; değerler altyazıdan alındı. -->

## 9. Kohonen Self-Organizing Map (SOM)

### 9.1 Tanım ve beyinle ilişkisi

Slayttaki tanım şöyledir (ekrandan, 01:35:00):

- Teuvo Kohonen tarafından 1989'da geliştirilmiştir.
- SOM YSA'lar topoloji koruma haritaları olarak da adlandırılır ve küme birimleri arasında topolojik bir yapı bulur.
- Bu özellik beyinde görülür, ancak diğer YSA'larda bulunmaz.
- Tek veya iki boyutlu dizi halinde düzenlenmiş $m$ kümeleme birimi vardır; giriş sinyalleri $n$ bileşenlidir (n-tuple).

SOM, komşular arasındaki ilişkileri kurmak, örnekler ya da sınıflar arasında topolojik bir harita oluşturmak için uygundur. Dayandığı mantık beyinde görülen bir yapıdır: her nöron belli davranışları temsil ediyorsa aralarında topolojik ilişkiler vardır. Yapay zekayı insan davranışına benzetmek isteniyorsa, hem unsupervised olan hem de beyindeki ilişkilerin benzerini kuran yapılar önemlidir. Hocaya göre SOM her uygulama için uygun değildir, ama başarılı uygulamaları vardır; zor bir problem olan gezgin satıcı problemini unsupervised biçimde çözebilmesi bunlardan biridir.

### 9.2 Komşuluk ve mimari

SOM'da belli geometrik biçimlerde komşuluk tanımlanır. Beyindeki etkilenmeler de belli yakınlıktaki komşuları etkiler; yakın görünen bazı nöronlar etkilenmezken biraz daha uzaktakiler etkilenebilir. Aynı hizadaki komşular, kare komşuluğundakiler ya da altıgen (hexagonal) gridteki komşular birbirinden etkileniyor olabilir. Slaytta hexagonal grid üzerinde kazanan nöron $\#$ ile, etrafında $R = 0$, $R = 1$ ve $R = 2$ komşulukları iç içe altıgenlerle gösterilir (ekrandan, 01:40:00).

Mimari olarak ağ bilinen tam bağlı giriş-çıkış yapısıdır; fark komşuların seçimindedir. Hangi birimlerin kazananla birlikte eğitileceği, ne çapta komşuların dikkate alınacağı, hangi eğitim fonksiyonunun kullanılacağı ve bütün birimlerin aynı miktarda eğitilip eğitilmeyeceği gibi kararlar verilmelidir. Unsupervised olduğu için bu parametrelerle oynayarak SOM'un başarısı çok değiştirilebilir; bu yüzden hoca SOM'u deneysel olarak iyileştirilebilen bir algoritma olarak tanımlar.

Her kümenin exemplar'ı olarak ağırlık vektörü kullanılır. Ağırlık vektörü girdi desenine en yakın olan kümeleme birimi kazanan seçilir. Kazanan birimin ve geometrik komşuluğu içindeki birimlerin ağırlıkları güncellenir, diğerleri güncellenmez.

İki temel eğitim aşaması vardır: komşuların geometrik olarak nasıl sayılacağını belirleyen bir başlangıç formasyonu ve en sondaki yakınsama durumu. Formasyonu algoritma içinde değiştiren uygulamalar da vardır. Eğitimin ne zaman sonlanacağına da karar verilmelidir: veriler SOM'a uygun olmayabileceği için bir maksimum epok sayısı konabilir; ya da harita artık çok az değişiyorsa (önceki ve yeni ağırlıklar arasındaki fark küçükse) öğrenme olmadığı kabul edilip durulabilir.

### 9.3 Algoritma

Slayttaki akış ve formüller (ekrandan, 01:45:00):

```text
start
  ağırlıkları set et; topolojik komşulukları set et;
  learning rate parametrelerini set et
  durma koşulu = false olduğu sürece:
      bütün input vektörleri için:
          net inputu hesapla
          D(J) min olan index J'yi bul
          J'nin ve komşularının ağırlıklarını güncelle
      learning rate'i güncelle; topolojik komşuluğun yarıçapını küçült
end
```

$$D(J) = \sum_i (w_{ij} - x_i)^2$$

$$w_{ij}(new) = w_{ij}(old) + \alpha\left[x_i - w_{ij}(old)\right]$$

> **Ders sonrası not:** Hoca bir yerde "D değeri en büyük olan küme" dedi; doğrusu slayttaki gibi $D(J)$'si en küçük olan kümedir, çünkü $D(J)$ bir mesafedir. Hoca örnekte de en küçük $D$'yi kazanan aldı.

Learning rate ve komşuluk yarıçapı her iterasyonda değiştirilebilir. Genellikle küçülterek gitmek mantıklıdır: geniş bir alanda komşulukları güncelleyerek başlayıp daha dar alanlara inmek öğrenme için daha faydalıdır. Learning rate epok sayısıyla ya da iterasyon sayısıyla ilişkilendirilerek, ya da doğrudan her iterasyonda yarıya bölünerek veya belli bir oranda küçültülerek azaltılabilir.

Haritanın oluşması iki aşamada gerçekleşir. Önce doğru bir düzen oluşmalıdır: her seferinde kazanan ve dolayısıyla komşuları değiştiği için final haritadaki yerler öğrenme sırasında sürekli değişir. Kazananların oluşturduğu kaba geometri belli olduktan sonra yakınsama için birkaç epok daha gerekir. Bu yüzden çoğu uygulamada çözüm ancak birçok epoktan sonra oluşur.

### 9.4 Sayısal örnek

Hoca örnekten önce, kümeyi doğrudan temsil eden bir örnek elde olmayabileceğini hatırlatır. Kümelere ait az miktarda etiketli veri varsa ağırlık matrisi onların ortalamasından kurulabilir; bu çok daha anlamlıdır. Hiçbir bilgi yoksa rastgele bir başlangıçtan da başlanabilir.

Slayttaki örnek (ekrandan, 01:50:00):

- Kümelenecek 4 vektör: $s(1) = (1, 1, 0, 0)$, $s(2) = (0, 0, 0, 1)$, $s(3) = (1, 0, 0, 0)$, $s(4) = (0, 0, 1, 1)$.
- Maksimum küme sayısı $m = 2$; 4 input, 2 output düğümü.
- Learning rate $= 0.6$ ve $\alpha(t+1) = 0.5\,\alpha(t)$.
- $R = 0$ (komşuluk yok; hoca, yarıçap biraz büyük seçilip her iterasyonda azaltılabileceğini de belirtir).
- Başlangıç ağırlıkları:

$$W = \begin{bmatrix} .2 & .8 \\ .6 & .4 \\ .5 & .7 \\ .9 & .3 \end{bmatrix}$$

Her sütun bir kümenin ağırlıklarıdır. İlk vektör $s(1)$ için her küme sütunuyla karesel farklar toplanır (ara adımlar eklendi, değerler python ile kontrol edildi):

$$D(1) = (0.2 - 1)^2 + (0.6 - 1)^2 + (0.5 - 0)^2 + (0.9 - 0)^2 = 0.64 + 0.16 + 0.25 + 0.81 = 1.86$$

$$D(2) = (0.8 - 1)^2 + (0.4 - 1)^2 + (0.7 - 0)^2 + (0.3 - 0)^2 = 0.04 + 0.36 + 0.49 + 0.09 = 0.98$$

Bunlar mesafe olduğu için küçük olan daha yakındır: $D(2)$ daha küçüktür, 2. küme kazanır. Yalnız ikinci sütun güncellenir; birinci küme kaybettiği için ilk sütuna dokunulmaz:

$$w_{i2}(new) = w_{i2}(old) + 0.6\,[x_i - w_{i2}(old)] \Rightarrow (0.8, 0.4, 0.7, 0.3) \to (0.92, 0.76, 0.28, 0.12)$$

Örneği 2. kümeye katmak, onu kümenin ortalamasına da katmak demektir. Sonraki vektörde $D(1)$ daha küçük çıkar ve $s(2)$ birinci kümeye katılır, birinci sütun güncellenir. Üçüncü vektör ikinci kümeye, dördüncü vektör birinci kümeye düşer. Böylece her iki kümenin ağırlıkları ikişer kez güncellenmiş ve bir epok tamamlanmıştır.

Bir epok sonunda learning rate yarıya düşürülür. Slayttaki devam (ekrandan, 01:55:00):

- Yeni learning rate: $\alpha(t+1) = 0.5\,\alpha(t) = 0.5(0.6) = 0.3$.
- Ağırlık güncelleme fonksiyonunun yeni hali: $w_{ij}(new) = w_{ij}(old) + 0.3[x_i - w_{ij}(old)] = 0.7\, w_{ij}(old) + 0.3\, x_i$.
- 2. epoch sonunda ağırlıklar:

$$W = \begin{bmatrix} .016 & .980 \\ .047 & .360 \\ .630 & .055 \\ .999 & .024 \end{bmatrix}$$

- 100. epoch sonunda ağırlıklar:

$$W = \begin{bmatrix} .0 & 1.0 \\ .0 & 0.5 \\ .5 & 0.0 \\ 1.0 & 0.0 \end{bmatrix}$$

Hoca bunu şöyle yorumlar: başlangıç matrisi belki az sayıdaki örneğin ortalaması, belki rastgele seçilmişti. Dört örnek yüz epok boyunca gösterilince örneklerin birbirine benzerliği de hesaba katılmış olur ve ağırlık matrisi her kümeye ait vektörlerin ortalaması gibi olur. Bileşen bileşen ortalama alınır; örneğin $1$ ile $0$'ın ortalaması $0.5$'tir.

> **Ders sonrası not:** Hoca ve slayt ilk sütunun 1. ve 2. vektörlerin, ikinci sütunun 3. ve 4. vektörlerin ortalaması olduğunu söyledi. Doğrusu: ilk sütun $(0, 0, 0.5, 1)$, $s(2) = (0,0,0,1)$ ile $s(4) = (0,0,1,1)$'in ortalamasıdır; ikinci sütun $(1, 0.5, 0, 0)$, $s(1) = (1,1,0,0)$ ile $s(3) = (1,0,0,0)$'ın ortalamasıdır. Derste de ilk epokta $s(2)$ ve $s(4)$ 1. kümeye, $s(1)$ ve $s(3)$ 2. kümeye düşmüştü.

> **Ders sonrası not:** Python ile, $\alpha$ her epokta yarıya indirilerek hesaplandığında 2. epoch sonunda sütunlar $(0.016, 0.047, 0.633, 0.992)$ ve $(0.984, 0.359, 0.055, 0.024)$ çıkar; slayttaki değerlerden üçüncü basamakta biraz farklıdır. Bu kuralla 100. epoch sonunda ağırlıklar $(0.008, 0.025, 0.582, 0.996)$ ve $(0.992, 0.414, 0.029, 0.012)$ civarında kalır, çünkü $\alpha$ çok hızlı küçülür. Slayttaki tam ortalamalara ulaşmak için $\alpha$'nın daha yavaş azaltılması gerekir; örneğin $0.6$'dan $0.01$'e geometrik olarak inen bir $\alpha$ ile 100 epokta $(0, 0, 0.508, 1)$ ve $(1, 0.492, 0, 0)$ elde edilir.

## 10. SOM Uygulamaları: Karakter Kümeleme ve Gezgin Satıcı Problemi

### 10.1 Karakter kümeleme

Hoca, öğrencilerin perceptron ile yaptığı karakter tanıma çalışmasındaki karakterlerin SOM ile de kümelenebileceğini söyler. Üç farklı fontla yazılmış karakterler vardır. Topolojik bir yapı kurulmazsa Winner Take All biçiminde öğrenme yapılır. Örnekler belli epoklarda tekrar tekrar gösterilir ve sonunda hangi karakterlerin hangi gruba girdiğine bakılır. Örnekte 25 kümeleme birimi ve 21 desen vardır.

Slayttaki doğrusal yapı sonucu şöyledir (ekrandan, 02:00:00): doğrusal bir yapı ($R = 1$ iken) mevcut küme birimlerine desenlerin daha iyi bir dağılımını sağlar. Kazanan düğüm $J$ ve onun topolojik komşuları $J + 1$ ve $J - 1$ olarak düşünülür ve her iterasyonda yalnız bu birimlerin öğrenmesine izin verilirse şu sonuç ortaya çıkar:

| Birim | Desenler | Birim | Desenler |
|---|---|---|---|
| 6 | K2 | 20 | C1, C2, C3 |
| 10 | J1, J2, J3 | 22 | D2 |
| 14 | E1, E3 | 23 | B2, E2 |
| 16 | K1, K3 | 25 | A1, A2, A3 |
| 18 | B1, B3, D1, D3 | | |

Hoca A'ların, C'lerin ve E'lerin büyük ölçüde ayrıldığını, B ile D'nin biraz karıştığını, ikinci fonttaki K'nın farklı bir birime düştüğünü belirtir. Farklı çap ve topolojilerde (örneğin "diamond" yapısıyla) sonuçlar değişir. <!-- BELİRSİZ: Winner Take All ve diamond yapısı sonuç tabloları incelenen karelerde yok. -->

> **Ders sonrası not:** Hoca "5 karakterimiz vardı, 5 sınıf" dedi; slayttaki tabloda A, B, C, D, E, J, K olmak üzere 7 harfin üçer fontu (21 desen) görünmektedir.

### 10.2 Gezgin satıcı problemi

SOM gezgin satıcı problemi için de denenmiştir. Gezgin satıcı probleminde bir topolojik harita oluşturulmaya çalışıldığı için SOM ile çözülüp çözülemeyeceğine uzun süre bakılmıştır. Şehir sayısı azken çözüm daha kolaydır; şehir sayısı yüzlere çıktığında daha çok epok ve farklı geometrilerle daha zor çözülmüştür.

Hoca önce doğrusal yapıda birer komşulukla yapılmış bir örneğin 100 epok sonraki çözümünü, sonra aynı örnek için $R = 0$ ile elde edilen çözümü gösterir. Slayttaki $R = 0$ sonucu (ekrandan, 02:05:00): 100 epoch, Alpha $= 0.2000$, Radius $= 0$; A'dan J'ye kadar şehirleri dolaşan bir tur $W_1$-$W_2$ düzleminde çizilmiştir. Hocaya göre iki şehre tam isabet olmamıştır, ama çözüm neredeyse bütün şehirleri gezecek şekilde oluşur.

SOM, farklı problemlere çözüm sunabilen ama parametre ayarı zor olan, unsupervised olduğu için de veri hazırlama derdi olmayan bir yöntemdir.

> **Ek bilgi (derste anlatılmadı):** SOM'un gezgin satıcı problemine uygulanmasında genellikle düğümler bir halka (kapalı zincir) üzerinde dizilir ve her düğümün ağırlık vektörü düzlemde bir nokta olarak yorumlanır. Eğitim ilerledikçe halka şehirlere doğru gerilir; düğümlerin halkadaki sırası turun sırasını verir. Bu yaklaşım büyük olasılıkla en iyi turu garanti etmez, ama kısa sürede iyi bir yaklaşık çözüm üretir.

## Örnek Sorular

**1. MaxNet (ekrandan, 00:30:00 ve 00:35:00).** 4 nörondan oluşan bir MaxNet'te $\epsilon = 0.2$, girdi sinyalleri $a_1(0) = .2$, $a_2(0) = .4$, $a_3(0) = .4$, $a_4(0) = .8$ olsun. $a_1(1)$'i hesaplayınız ve hangi nöronun kazanacağını bulunuz.

Çözüm (derste verildi): $a_1(1) = f(0.2 - 0.2(0.4 + 0.4 + 0.8)) = f(-0.12) = 0$. Slayttaki iterasyon tablosuna göre beşinci iterasyonda $a(5) = (0, 0, 0, .421)$ olur; kazanan $A_4$'tür. (Tablonun $a_3(0) = .6$ için hesaplandığına dair ders sonrası not 5.3'tedir.)

> **Çözüm (derste verilmedi):** Slayttaki $a_3(0) = .4$ değeriyle iterasyon sürdürülürse $a(1) = (0, .12, .12, .60)$, $a(2) = (0, 0, 0, .552)$ olur ve $A_4$ ikinci iterasyonda kazanır (python ile kontrol edildi).

**2. Mexican Hat (ekrandan, 01:15:00).** 7 nöronlu bir Mexican Hat ağında $R_1 = 1$, $R_2 = 2$, $C_1 = 0.6$, $C_2 = -0.4$, $x\_max = 2$ ve başlangıç aktivasyonları $(0, 0.5, 0.8, 1, 0.8, 0.5, 0)$ olsun. Her nöronun net input denklemini yazınız ve bir iterasyon sonrasındaki aktivasyonları bulunuz.

Çözüm: Denklemler 7.3'tedir (derste verildi).

> **Çözüm (derste verilmedi):** Bir iterasyon sonrası aktivasyonlar $(0,\ 0.38,\ 1.06,\ 1.16,\ 1.06,\ 0.38,\ 0)$, ikinci iterasyon sonrası $(0,\ 0.4,\ 1.136,\ 1.664,\ 1.136,\ 0.4,\ 0)$'dır (python ile kontrol edildi). Örneğin $x_1(1) = 0.6(0) + 0.6(0.5) - 0.4(0.8) = -0.02 \to 0$.

**3. Hamming ağı (ekrandan, 01:30:00).** $e(1) = [1, -1, -1, -1]$ ve $e(2) = [-1, -1, -1, 1]$ exemplar vektörleriyle kurulan Hamming ağında $(1, 1, -1, -1)$ girdisi hangi exemplar'a atanır?

Çözüm (derste verildi): $w_{ij} = 0.5\, e_i(j)$, $b = 2$; $y\_in_1 = 2 + 1 = 3$, $y\_in_2 = 2 - 1 = 1$. Bunlar Hamming benzerlikleridir (3 ve 1 ortak bit). $y_1(0) > y_2(0)$ olduğu için MaxNet $e(1)$'i seçer.

**4. Kohonen SOM (ekrandan, 01:50:00 ve 01:55:00).** $s(1) = (1,1,0,0)$, $s(2) = (0,0,0,1)$, $s(3) = (1,0,0,0)$, $s(4) = (0,0,1,1)$ vektörleri $m = 2$ küme, $\alpha = 0.6$, $\alpha(t+1) = 0.5\alpha(t)$, $R = 0$ ve başlangıç ağırlıkları $W = \begin{bmatrix} .2 & .8 \\ .6 & .4 \\ .5 & .7 \\ .9 & .3 \end{bmatrix}$ ile kümelensin. İlk vektör hangi kümeye girer, ağırlıklar nasıl güncellenir?

Çözüm (derste verildi): $D(1) = 1.86$, $D(2) = 0.98$; 2. küme kazanır, ikinci sütun $(0.92, 0.76, 0.28, 0.12)$ olur. İlk epokta $s(2)$ ve $s(4)$ 1. kümeye, $s(1)$ ve $s(3)$ 2. kümeye düşer. Uzun eğitim sonunda sütunlar kümelerdeki vektörlerin ortalamasına, $(0, 0, 0.5, 1)$ ve $(1, 0.5, 0, 0)$'a yaklaşır.

> **Çözüm (derste verilmedi):** İlk epoğun tamamı python ile: $s(2)$ için $D = (0.66, 2.2768)$, 1. sütun $(0.08, 0.24, 0.2, 0.96)$ olur; $s(3)$ için $D = (1.8656, 0.6768)$, 2. sütun $(0.968, 0.304, 0.112, 0.048)$ olur; $s(4)$ için $D = (0.7056, 2.7243)$, 1. sütun $(0.032, 0.096, 0.68, 0.984)$ olur.

## Dersin Toparlaması

Bu derste rekabetçi yapay sinir ağları işlendi. Ortak fikir, kararsız çıktılar yerine bir kazanan seçmek ve bunu kümelemede kullanmaktır. Her küme bir exemplar (ağırlık) vektörüyle temsil edilir; yeni bir örnek Öklid mesafesi ya da noktasal çarpım (açı) ile en yakın exemplar'a atanır ve Kohonen kuralıyla yalnız kazananın ağırlığı güncellenir. Sabit ağırlıklı ağlardan MaxNet $-\epsilon$ ile karşılıklı bastırma yaparak tek kazanan bırakır; Mexican Hat yakın komşuları güçlendirip uzak komşuları bastırarak bir grup kazanan oluşturur; Hamming ağı bipolar vektörlerde aynı bit sayısını benzerlik olarak hesaplar ve kararı MaxNet'e bırakır.

Son olarak Kohonen SOM ile topolojiyi koruyan, unsupervised bir kümeleme yöntemi görüldü: kazanan ve topolojik komşuları güncellenir, learning rate ve komşuluk yarıçapı zamanla küçültülür, uzun eğitim sonunda ağırlıklar kümelerin ortalamasına yaklaşır. Karakter kümeleme ve gezgin satıcı problemi örnekleri, SOM'un sonucunun komşuluk yapısı ve parametrelere ne kadar bağlı olduğunu gösterdi. Hoca, klasik yapay sinir ağları kısmının bu dersle kapandığını, sonraki derslerde derin öğrenme konularına geçileceğini ve RNN gibi yapıların orada işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
