# Ders 5 Genişletilmiş Notu: Karar Ağaçları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Optimizasyon ödevi üzerine akademik tartışma
- 2. Karar ağaçlarına giriş ve algoritmaların varsayımları
- 3. Formal tanım
- 4. Ağacı bulmak: optimizasyon problemi
- 5. Ağacı oluşturmak: regresyon için bölme
- 6. Sınıflandırma için çıkış ve durma ölçütleri
- 7. Durma eşiğinin üretilen fonksiyona etkisi
- 8. Tek değişkenli ve çok değişkenli karar ağaçları
- 9. Karar ağaçlarının özellikleri
- 10. Karar ağaçlarının kısıtları
- 11. Algoritma, optimallik ve alternatifler
- 12. Çevrimiçi / artımlı algoritmalar
- 13. Ödev sunumlarından çıkan akademik noktalar
- Örnek Sorular

## 1. Optimizasyon ödevi üzerine akademik tartışma

Ders, bir önceki haftalarda verilen optimizasyon ödevinde öğrencilerin takıldığı yerlerin konuşulmasıyla başladı. Ödevde 10 boyutlu konveks ve konveks olmayan kayıp fonksiyonları seçilecek, bunlar üzerinde gradyan inişi, Adam ve koordinat inişi karşılaştırılacaktı. Birçok öğrencinin en çok zorlandığı adım uygun fonksiyonu bulmaktı.

Hoca şu yolu önerdi: önce iki boyutlu fonksiyonlarda çalışan bir kod yazmak, sonra onu çok değişkenliye genişletmek. İki boyuttaki konveks ve konveks olmayan fonksiyonlar derste zaten görülmüştü. En temel konveks fonksiyon $y = x^2$'dir. İki değişkenlisi $x_1^2 + x_2^2$, kabaca bir kürenin yarısı (kase) gibi bir yüzeydir. Üç değişkende $x_1^2 + x_2^2 + x_3^2$ olur. Yani her değişkenin karesinin toplamı çok basit bir konveks fonksiyondur ve istenen boyuta kadar genişletilebilir.

Bir öğrenci, yüze yakın test fonksiyonunu çok boyutlu sürümleri, konveks olup olmadıkları ve zorluk sıralarıyla listeleyen bir siteden yararlandığını anlattı (Rosenbrock, Rastrigin gibi). Hoca bu fonksiyonların zor olduğunu onayladı.

**Soru:** Bir fonksiyonun konveks olup olmadığını $\alpha f(x_1) + \beta f(x_2)$ gibi bir koşulla mı sınıyorduk? **Cevap:** Hayır, o tür koşullar doğrusallıkla ilgilidir, konvekslikle değil. Ancak parametreye göre doğrusal bir model yazılırsa onun (karesel) kayıp fonksiyonu konveks olur; bunda anormal bir durum yoktur.

> **Ek bilgi (derste anlatılmadı):** Konveksliğin tanımı $f(\lambda x_1 + (1-\lambda)x_2) \le \lambda f(x_1) + (1-\lambda) f(x_2)$, $\lambda \in [0,1]$ eşitsizliğidir. Doğrusallık ise $f(\alpha x_1 + \beta x_2) = \alpha f(x_1) + \beta f(x_2)$ eşitliğidir. İki kez türevlenebilen bir fonksiyonda Hessian'ın her yerde pozitif yarı tanımlı olması konveksliğe denktir.

Ödevdeki PCA/t-SNE kısmı da netleştirildi. Optimizasyon bir noktadan başlar ve her epokta bir sonraki noktaya ilerler. $X$ epok sonra elde $X$ tane nokta olur ve her biri 10 boyutludur. Bu 10 boyutlu noktalar dizisine PCA ya da t-SNE uygulanıp 2 boyuta indirilince algoritmanın izlediği yörünge görülür. Amaç, iki boyutta gözlenen hareketlerin (algoritmaların optimuma nasıl yaklaştığının) 10 boyuta geçince de benzer olup olmadığını araştırmaktır.

## 2. Karar ağaçlarına giriş ve algoritmaların varsayımları

Bu haftanın konusu karar ağaçlarıdır. Sınıfta karar ağacını hiç duymamış kimse yoktu, ama birkaç kişi hiç kullanmamıştı. Hoca, karar ağacını elle hesaplamış olmanın, bilgisayarda bir fonksiyon çağırmaktan daha iyi kavrama sağlayacağını belirtti. Karar ağaçlarının bu derste kullanılma nedeni ileride (kollektif öğrenmede) anlatılacak.

Karar ağaçları güzel algoritmalardır. Algoritmaya bir veri kümesi verilir, sonucunda bir ağaç üretilir. Bu ağaca gözle bakarak karar sürecinin nasıl oluştuğu açıkça görülebilir; bu da sürecin arka planda nasıl işlediğine dair bilgi verir. Çıktılarının bu kadar anlaşılır olması, karar ağaçlarını en popüler makine öğrenmesi algoritmalarından biri yapar.

Karar ağaçlarının varsayımı şudur: veri uzayı $M$ adet kesişmeyen bölgeye ayrılır ve bu bölgelerin her biri içinde tek bir çıkış üretilir.

Hoca burada genel bir ilkenin altını çizdi. Algoritmaların varsayımları algoritmayı belirleyen, onun optimizasyon ve parametre bulma sürecini belirleyen fikirlerdir. Doğrusal regresyon, regresyon probleminde verinin bir düzlem üzerinde yer aldığını varsayar. Sınıflandırmada kullanılırsa sınıfların bir düzlem ya da hiperdüzlemle ayrılabildiğini varsayar.

> **Hocanın vurgusu:** Her algoritma aslında bir varsayımdır; bir algoritma seçerken bir varsayım seçersiniz. Gerçek veriye hiçbir zaman erişemezsiniz, yalnız ondan alınmış bir örneğe erişirsiniz. Verinin gerçeği ile seçilen algoritmanın varsayımı uyumluysa algoritma o veri kümesinde iyi çalışır.

## 3. Formal tanım

Bölgelere $R_m$, bölgelerin çıkışlarına $c_m$ denir. Ağaç bu ikisinden oluşur: "Ağaç = $M$ adet kesişmeyen bölge ($R_m$) ve bölgelerin çıkışları ($c_m$)" (ekrandan, 00:20:00).

Bir $T$ ağacının bir $x$ örneği için çıkışı (ekrandan, 00:20:00):

$$\hat{y} = T(x) = \sum_{m=1}^{M} c_m I_{R_m}(x), \qquad I_A(x) = \begin{cases} 1 & \text{eğer } x \in A \\ 0 & \text{değilse} \end{cases}$$

Burada $x$ veri kümesinden bir örnektir; kaç boyutlu olduğu önemli değildir. $I_A(x)$ göstergeç (indicator) fonksiyonudur. Bölgeler kesişmediği için herhangi bir $x$ örneği $M$ bölgeden yalnız birinin içinde olabilir. Bu nedenle $I_{R_m}(x)$ yalnız bir $m$ için 1, diğerleri için 0'dır. Toplamdaki bütün diğer terimler sıfırla çarpılır ve $T(x)$, $x$'in ait olduğu bölgenin $c_m$ değerine eşit olur.

## 4. Ağacı bulmak: optimizasyon problemi

### 4.1 Kayıp fonksiyonu

Veri kümesi $D = \{(x_i, y_i)\}_{i=1}^{N}$ olsun: $x$'ler girdiler, $y$'ler çıktılar, $N$ elemanlı bir eğitim kümesi. $i$. örneğin tahmini $\hat{y}_i = T(x_i)$'dir. Ağacın iyiliğini ölçmek için bir kayıp fonksiyonu gerekir. Karesel hata seçilsin: $L(y_i, \hat{y}_i) = (y_i - \hat{y}_i)^2$. O zaman $T$ ağacının kaybı bütün örneklerdeki hataların karelerinin toplamıdır:

$$L(T) = \sum_{i=1}^{N} (y_i - T(x_i))^2 = \sum_{i=1}^{N} \left(y_i - \sum_{m=1}^{M} c_m I_{R_m}(x_i)\right)^2$$

Bu, herhangi bir $T$ ağacı için hesaplanabilen bir kayıp değeridir.

### 4.2 Optimizasyon tanımı

Amaç bu kaybı küçük yapan bir $T$ bulmaktır. $T$, $M$ bölge ve onların çıkışlarından oluştuğu için optimizasyon problemi şöyledir (ekrandan, 00:30:00):

$$\{\hat{c}_m, \hat{R}_m\}_1^M = \underset{\{c_m, R_m\}_1^M}{\operatorname{argmin}} \sum_{i=1}^{N} \left[y_i - \sum_{m=1}^{M} c_m I_{R_m}(x_i)\right]^2$$

**Soru (hocanın sorusu):** Burada argmin neyi ifade eder? Min yazmıyor, argmin yazıyor. **Cevap:** Elimizde $x$'ler ve $y$'ler, yani veri kümesi vardır. Bilinmeyenler $c_m$ ve $R_m$'lerdir. Argmin, gerçek çıkışlarla ağacın tahminleri arasındaki farkların karelerinin toplamını en küçük yapan $c_m, R_m$ değerlerini verir. Önceki haftalarda $\min_x$ ile tek bir $x$ aranıyordu; burada $M$ tane bölge ve $M$ tane çıkış birlikte aranır.

Slaytta bu tanımın altında şu adımlar yer alıyordu (ekrandan, 00:30:00): olası tüm $c_m, R_m$ ikilileri içinde $L$ değeri en küçük olanı bulalım. Birleşik bir optimizasyon problemi, çok zor. Kolaylaştıralım: $R$'ler hiperküp şeklinde olsun. Hâlâ çok zor. İteratif bir algoritma: başta tek bir $R$ olsun, ikiye bölelim, çıkan bölgeleri yine bölelim (yeterince iyi bölgeler elde edene kadar).

### 4.3 Neden zor ve nasıl kolaylaştırılır

Bu birleşik (koşullu) bir optimizasyon problemidir: yalnız $R_m$'leri ya da yalnız $c_m$'leri optimize ederek çözülemez, ikisi birlikte düşünülmelidir. Üstelik tanımda bölgelerin yalnız kesişmediği söylendi; bölge sayısı da bölgelerin biçimi de belirtilmedi. Bölgeler üçgen, prizma, dairesel, eğik olabilirdi.

Bir optimizasyon probleminde arama uzayı çok büyükse bazı değişkenler ortadan kaldırılarak uzay daraltılır. Karar ağaçlarında ilk kısıt bölgelerin biçimidir: bölgeler hiperküp olsun. Hoca burada "küp" sözcüğünün tam doğru olmadığını, kenar uzunlukları farklı olabileceği için aslında (hiper)dikdörtgensel bölgelerden söz edildiğini belirtti; boyut 2, 3 ya da 5 olabilir. Böylece dairesel ve eğik bölgeler aramadan çıkar.

Bu yine de zordur, çünkü her bölgeyi ayrı ayrı tanımlamak birçok düzlem gerektirir. Hoca bir hiperbölgeyi tanımlamak için "herhalde en az $D+1$ düzlem" gerektiğini söyledi.

> **Ders sonrası not:** Hoca bir hiperbölge için "herhalde $D+1$ düzlem" dedi. $D+1$, $D$ boyutta sınırlı bir bölgeyi (simpleks) kapatmak için gereken en az düzlem sayısıdır. Eksenlere paralel bir hiperdikdörtgen için ise büyük olasılıkla her eksende bir alt ve bir üst sınır, yani $2D$ düzlem gerekir.

Bu yüzden çok daha basit bir çözüm önerilmiştir: başta tek bir $R$ olsun, o da bütün uzay. Sonra bu iteratif olarak bölünür: bütün uzay bir yerden ikiye ayrılır, çıkan iki bölgenin her biri yine ikiye bölünür ve bu böyle sürer. Her adımda bölge sayısı kabaca iki katına çıkar.

Bu çözüm optimum değildir. Optimum karar ağacı, o veri kümesinde aynı (yüksek) başarıya sahip ve en az sayıda bölge içeren ağaçtır. İteratif algoritma bu ağacı bulamayabilir. Bu durum yerel aramaya benzer: global optimuma ulaşmak çok zaman alacağı için yeterince iyi bir yerel minimuma razı olunur. Optimal ağaç üretilmese de karar ağaçları oldukça başarılı sonuçlar verir.

## 5. Ağacı oluşturmak: regresyon için bölme

### 5.1 Bölgenin çıkışı ve kaybı

Önce çıkışların sayı olduğu bir regresyon problemi ele alınır. Slayt şöyleydi (ekrandan, 00:40:00):

- Tek bir $R$, çıkışı ($c$) içindeki $K$ adet örneğin çıkışlarının ortalaması (tek $R$ varsa $K = N$).
- $L(R) = \frac{1}{K} \sum_{x \in R} \left(y_i - \mathrm{mean}(\{y_i\}_1^K)\right)^2$
- Bir özelliğin ($j$) bir değerine ($s_j$) göre $R$'yi 2'ye ($R_L$, $R_R$) bölelim. Bu bölmenin iyiliği: $Imp(j, s_j) = L(R) - L(R_L) - L(R_R)$
- Tüm olası $j, s_j$ ikilileri için $Imp$'leri hesapla, en iyisini (büyüğünü) seç.

Başta bütün veriler tek bir bölgededir. Bölgenin çıkışı içindeki örneklerin çıkışlarının ortalamasıdır. Bölme bittiğinde de her bölgenin çıkışı aynı kuralla belirlenir: o bölgedeki eğitim örneklerinin çıkışlarının ortalaması, o bölgeye düşen yeni bir test örneğinin tahminidir.

Bölgenin kaybındaki $y_i - \mathrm{mean}$ terimi her örneğin kendi bölge ortalamasından ne kadar saptığını gösterir. Bu farkların kareleri toplanıp $K$'ya bölününce bir ortalama karesel hata (mean square error) elde edilir.

### 5.2 Bölmenin iyiliği

Bölme belli bir özelliğin belli bir değerine göre yapılır. Örneğin veri üç boyutluysa her boyut (özellik) için olası bütün bölmeler denenir. Hoca bunu slaytın üzerinde bir çizgi çizerek gösterdi: uzay bir çizgiyle ikiye bölününce bir tarafta $R_L$, diğer tarafta $R_R$ oluşur. Örnek bir bölme sorusu: "veri kümesindeki üçüncü özellik 3,5'ten büyük mü?"

Bölmenin iyiliği (improvement) $Imp(j, s_j) = L(R) - L(R_L) - L(R_R)$'dir. Kayıpların küçük olması istenir; çocuk bölgelerin kayıpları ne kadar küçükse bu fark o kadar büyük olur. Bu yüzden bütün $(j, s_j)$ ikilileri için $Imp$ hesaplanır ve en büyüğü seçilir. $L(R)$ bütün adaylar için aynı olduğundan, $L(R_L) + L(R_R)$ toplamı en küçük olanı seçmek de aynı sonucu verir.

> **Ders sonrası not:** Slayttaki $L(R)$ tanımında $\frac{1}{K}$ çarpanı vardır. Bu ortalamalı biçimde çocuk bölgelerin kayıpları doğrudan çıkarılırsa örnek sayıları hesaba katılmamış olur. Yaygın uygulamalarda (ör. CART) büyük olasılıkla ya $\frac{1}{K}$'sız karesel hata toplamı kullanılır ya da çocuk kayıpları örnek sayılarıyla ağırlıklandırılır: $L(R) - \frac{K_L}{K}L(R_L) - \frac{K_R}{K}L(R_R)$.

Seçilen en faydalı bölme ağaca karar düğümü olarak yerleştirilir. Bu, uzayı iki parçaya bölmek demektir. Sonra çıkan iki bölgenin her biri aynı mantıkla yine ikiye bölünür: yine $L(R)$ hesaplanır, yine olası bütün bölmelerin iyiliği bulunur, yine en iyisi seçilir.

### 5.3 Aday eşikler nasıl seçilir

**Soru:** $Imp(j, s_j)$'deki $s_j$ neye göre belirleniyor? **Cevap:** Tek bir özellik ele alındığında veri kümesinde o özellik için birçok değer vardır. Bölmenin yapılabileceği yerleri bulmanın birkaç yolu vardır. Biri, en küçük ve en büyük değer arasına eşit aralıklı, örneğin 10 eşik koymaktır. Diğeri, sayısal özelliğin değerlerini sıralayıp her ardışık iki değerin tam orta noktasını aday eşik olarak denemektir. Kategorik özelliklerde ise özelliğin alabildiği bütün değerler için bu işlem yapılır.

## 6. Sınıflandırma için çıkış ve durma ölçütleri

Slayt şu soruları soruyordu (ekrandan, 00:45:00): Sınıflandırma problemleri için $c$? Bölmeye ne zamana kadar devam edeceğiz? Maksimum derinlik; bölgenin saflığı / düzgünlüğü; minimum yaprak büyüklüğü.

### 6.1 Regresyon ve sınıflandırmada bölge çıkışı

Hoca önce tek boyutlu bir regresyon örneği çizdi: tek bir $x$ girdisi ve ona karşılık çıkışlar, dört örnek. Tek bölge bütün örnekleri kapsar ve çıkışı örneklerin çıkışlarının ortalamasıdır; yani ağacın fonksiyonu bu ortalama düzeyinde yatay bir doğrudur.

Sonra örnekler iki renge boyandı (iki sınıflı bir sınıflandırma problemi). **Soru:** Bütün örnekler aynı bölgedeyse çıkış olarak hangi sınıf verilmeli? **Cevap:** En çok olanı. Bölgenin çıkışı, o bölgeye düşen örneklerin sınıfları arasında frekansı en yüksek olan sınıftır.

### 6.2 Durma ölçütleri

Bölmeye ne zamana kadar devam edileceğine birkaç yolla karar verilir:

- Maksimum derinlik: örneğin en fazla 20 derinliğe kadar inilsin denebilir.
- Bölgenin saflığı (sınıflandırma) ya da düzgünlüğü (regresyon).
- Minimum yaprak büyüklüğü (slaytta yer aldı, derste ayrıca açıklanmadı).

Bunlar hiperparametredir.

**Soru (hocanın sorusu):** Parametre ile hiperparametrenin farkı neydi? **Cevap (bir öğrenci):** Hiperparametre, sistemin kendi kendine belirleyemediği, bizim önceden tanımlamamız gereken parametredir. Hoca cevabı doğruladı.

Saflığa göre durmada şu denebilir: her bölgede tek bir sınıftan örnek kalana kadar bölmeye devam et. Hoca burada "tek bir örnek kalana kadar değil, tek bir sınıftan örnek kalana kadar" ayrımını vurguladı. Bu %100 saflık demektir. Eşik başka bir hiperparametre olarak %90 da seçilebilir: bölgedeki örneklerin %90'ı bir sınıftansa bölme durur.

Regresyonda ise bölgedeki örneklerin çıkışlarının standart sapması belli bir eşikten büyük olduğu sürece bölmeye devam edilir. Standart sapma aslında bölgenin kayıp tanımından gelir: çıkışların ortalamadan farklarının kareleri.

**Soru (hocanın sorusu):** Regresyonda bir bölgedeki örneklerin çıkışlarının standart sapmasının sıfır olması ne anlama gelir? Bir öğrencinin "%100 saflık mı?" cevabına hoca, saflığın sınıflandırma için olduğunu, burada çıkışların sayı olduğunu hatırlattı. **Cevap:** Bölgedeki bütün noktaların çıkışları aynıdır. Bölgede tek bir örnek varsa ya da örneklerin çıkışları birbirine eşitse standart sapma sıfır olur.

## 7. Durma eşiğinin üretilen fonksiyona etkisi

### 7.1 İki düzeyli veri

Hoca tek girdili ($x$) ve tek çıkışlı ($y$) bir regresyon verisi çizdi (ekrandan, 00:55:00). Altı nokta vardı: soldaki üçü düşük bir düzeyde, sağdaki üçü daha yüksek bir düzeyde. Durma ölçütü "çıkışların standart sapması sıfır olana kadar böl" olsun.

Başta hepsi tek bölgededir; çıkış bütün çıkışların ortalaması olan yatay bir doğrudur. Standart sapma sıfır olmadığı için bölge bölünmelidir. Altı nokta arasında beş olası bölme yeri vardır. En iyisi iki grubun arasından bölmektir: bölme sonrası soldaki bölgenin çıkışları da sağdaki bölgenin çıkışları da (yaklaşık) bir düz çizgiye oturur. Düz çizgi standart sapmanın sıfır olduğu anlamına gelir; o andan sonra bölmeye gerek kalmaz. Yani tek bir bölme yeterlidir.

### 7.2 Farklı yükseklikte noktalar

Sonra noktalar farklı yüksekliklere kaydırıldı. **Soru (hocanın sorusu):** Durma ölçütü standart sapmanın sıfır olması ise karar ağacı nasıl bir fonksiyon üretir? Bir öğrenci "her nokta için bir karar sınırı mı?" diye sordu. Hoca, karar sınırının sınıflandırma terimi olduğunu, burada bir regresyon fonksiyonu çizildiğini düzeltti.

**Cevap:** Ağaç bir basamak fonksiyonu üretir (ekrandan, 01:00:00). Düz bir çizgi ilk noktanın üstünden geçer, iki noktanın tam orta noktasına kadar ilerler, orada zıplar, bir sonraki noktanın düzeyinde düz devam eder, sonraki iki noktanın ortasında yine zıplar ve böyle sürer. Yani verilen değerden küçük girdiler için bir değer, büyük girdiler için başka bir değer söylenir.

**Soru:** Bu, her girdiyi ayrı bir sınıf olarak kabul ettiği anlamına mı gelir? **Cevap:** Hayır, sınıf yoktur, bu bir regresyon problemidir. Ayrıca aynı düzeyde (aynı çizgi üzerinde) duran noktalar için ayrı basamak üretilmez; standart sapmanın sıfır olması için bölgedeki çıkışların eşit olması yeterlidir.

## 8. Tek değişkenli ve çok değişkenli karar ağaçları

**Soru:** Karar ağacı kullandığımız için bu fonksiyonun eğri biçiminde olma imkânı yok, değil mi? **Cevap:** Klasik karar ağaçları için doğru, eğri üretemezler. Klasik ağaçlardaki karar düğümleri tek değişken içerir; örneğin "üçüncü özellik ($x_3$) 2,45'ten büyük mü?". Bu yüzden bölgeler hep özelliklere (eksenlere) dik sınırlarla ayrılır.

Çok değişkenli karar ağacı (multivariate decision tree) kullanılırsa düğümlerde "$w_1 x_1 + w_2 x_2 > 3{,}48$ mi?" gibi sorular yer alır. Bu durumda eğik bölmeler oluşturulabilir, ama bölgeler artık hiperküp olmaz; hiperküp varsayımı kaldırılmış, başka biçimde bölgelere geçilmiş olur.

## 9. Karar ağaçlarının özellikleri

### 9.1 Özellik seçimi ve özellik türleri

Karar ağaçları çıkışla ilgisiz özelliklerle başa çıkabilir. Bir ağacın düğümlerine bakıldığında bazı özellikler sık sık yer alırken bazıları hiç yer almayabilir; yani o özelliğe göre hiç düğüm oluşturulmamış olabilir. Bu, karar ağacı algoritmasının kendiliğinden özellik seçimi yaptığı anlamına gelir. Ayrıca özellik seçimi yapıp sonra ağaca vermek gerekmez. Her özellik için bir önem skoru da hesaplanabilir.

Sayısal ve kategorik özelliklerle çalışırlar. Sayısal özellikte $x_j \le$ eşik (ya da $<$) biçiminde, kategorik özellikte $x_j =$ değer biçiminde karşılaştırma yapılır; örneğin "renk kırmızı mı?".

### 9.2 Normalizasyon gerekmez

Her özellik kendi içinde ele alındığı için ölçek farklılıklarından etkilenmezler, normalizasyon gerekmez. Ancak çok değişkenli karar ağacı üretilecekse ($w_1 x_1 + w_2 x_2 + \dots$ gibi özellikler birlikte işe katılıyorsa) normalizasyon gerekir. Klasik (univariate) ağaçlar için ölçek farkı sorun oluşturmaz.

### 9.3 Hesap karmaşıklığı

Karar ağaçları hızlı üretilir. $n$ özellik ve $N$ örnek olsun. Her adımda örnek sayısı ortalama olarak ikiye bölündüğü için ortalama derinlik $\log N$'dir. Her seviyede $N$ örnek $n$ özellik için işlenir: her özellik için her örneğe bir kez bakılır. Bu yüzden bir karar ağacı üretmenin karmaşıklığı $O(n \cdot N \log N)$'dir; diğer popüler algoritmalara göre yüksek değildir.

### 9.4 Eksik özellikler

Slayt şöyleydi (ekrandan, 01:05:00): eksik özelliklerle başa çıkarlar; kategorik özellikler için "eksik" isimli bir kategori olabilir. Suret (surrogate) özellikler kullanılabilir: bir özellik eksik ise onun yerine hangi özelliklere sırayla bakılacağı belirlenebilir. Az sayıda hiperparametreye sahip. Deterministik (aynı verilerle hep aynı sonuç elde edilir). Yorumlanabilir model.

Hoca surrogate düğümleri bir örnekle açıkladı. Bir düğüm "27. özellik 3,2'den büyük mü?" diye soruyor olsun. Test anında o düğüme gelen örnekte 27. özellik yoksa ağaçta şöyle bir mekanizma olabilir: bu özellik eksikse şu özelliğin şu eşiğine bak. Yani her düğümün içine onun yerine geçebilecek yedek düğümler konabilir; bunlar oldukça iyi çalışır.

**Soru:** Veri madenciliğinde verideki NaN değerleri, örneği silerek ya da o özelliğin ortalamasını yazarak ele alıyorduk. Surrogate yaklaşımı NaN değerler için de kullanılabilir mi? **Cevap:** Evet, özellik NaN olduğunda da kullanılabilir; "eksikse" yerine "NaN ise" bu mekanizmayı çağır denebilir. Ancak bazı durumlarda eksikliğin kendisi bir anlam taşır: o veriye erişilemiyor olması sınıfı belirleyen bir bilgi olabilir. Bu durumda surrogate gibi bir yöntem doğru olmayabilir; eksik değeri ayrı bir kategori ya da ayrı bir değer olarak almak makul olabilir. Bu, veri kümesinden veri kümesine değişir.

### 9.5 Diğer özellikler

Az sayıda hiperparametreleri vardır. Deterministiktir: aynı verilerle hep aynı sonuç elde edilir, işin içinde rastgelelik yoktur. Yorumlanabilir bir modeldir.

## 10. Karar ağaçlarının kısıtları

### 10.1 Sürekli olmayan çıkışlar (merdiven etkisi)

Hoca iki boyutlu, iki sınıflı ve sınıfları eğik bir doğruyla ayrılan bir veri çizdi (ekrandan, 01:25:00). Karar ağacının karar sınırları eksenlere dik olmak zorunda olduğu için eğik bir sınır üretemez. Onun yerine bir merdiven gibi, basamaklı bir sınır oluşur: şuradan, buradan, şuradan bölünür. Basamakların küçülmesi, yani sınırın doğrusala yakın görünmesi için çok fazla örnek gerekir.

### 10.2 Derinlerde az örnek

Derinlere inildikçe düğümleri belirlemekte kullanılan örnek sayısı azalır, çünkü örnekler her adımda bölünür. En alt seviyelerdeki bölgelerin çıkışları giderek az sayıda örnekle belirlenir. Az örnek, özellikle çok sayıda özellik varsa güvenilir bir dayanak olmayabilir. Bu yüzden çok derin ağaçlar istenmez. Hoca, yakında kollektif öğrenmeye giriş yapılacağını ve tek ağaç yerine birçok ağaç kullanarak bu tür sorunların önüne geçilebileceğini söyledi.

### 10.3 Etkileşimsiz (toplamsal) ilişkiler

Özellikler çıkışı birbirleriyle etkileşime girmeden etkiliyorsa, yani gerçek fonksiyon $f(x) = \sum_j a_j x_j$ gibi doğrusal bir fonksiyonsa ($a_j$ katsayılar, $x_j$ girdiler) karar ağacı iyi bir yaklaşım değildir. Çünkü bölgeler etkileşimi ifade eder: her bölge yalnız kendi karar düğümüne değil, kökten kendisine kadar olan bütün kararlara birden bağlıdır. Örneğin bir bölge "$x_1 < 2$ ve $x_3 < 4$" gibi bir koşulla tanımlanır.

### 10.4 Yüksek boyut, varyans, aç gözlülük, korelasyon

Slayt şöyleydi (ekrandan, 01:30:00):

- Çıkış çok fazla özelliğe bağlı ise iyi değil. Çünkü çok derin bir ağaç oluşur. Derinlerde örnek sayısı azdır.
- Eğitim kümesindeki küçük değişimler ağaçta büyük değişimlere sebep olabilir. Aynı dağılımdan gelmiş farklı eğitim kümeleri için çok farklı ağaçlar üretilebilir. Bu farklılığa varyans denir.
- Aç gözlü algoritma sebebiyle yukarıda yapılan bir yanlış hiç düzeltilmez.
- Özellikler arası korelasyon yüksek ise farklı görüntülere sahip ağaçların fonksiyonel uzaydaki görünümleri (tahminleri) benzer olabilir.

Çok sayıda özellik örneği olarak hoca bir resmin piksellerinin özellik olarak kullanılmasını verdi: ağacın derin bölgelerinde çok az örnek ama binlerce boyut olur, güvenilir sonuç çıkmayabilir.

> **Hocanın vurgusu:** Veri kümesindeki küçücük bir değişiklik ağacın yapısını çok değiştirebilir. Tek bir karar ağacı kullanılıyorsa bu kötüdür; ama kollektif öğrenmede olduğu gibi birden fazla ağaç kullanılıyorsa bu iyi bir özellik hâline gelir. Bu daha sonra görülecek.

**Soru (hocanın sorusu):** Aç gözlü (greedy) algoritma ne demektir? **Cevap:** Bir karar verip bir daha arkasına bakmayan algoritmadır. Karar ağacı algoritmasında aşağıda bir yerde "yukarıda yanlış yapmışım" deyip yukarıyı güncelleyen bir mekanizma yoktur; bu yüzden yukarıda yapılan bir yanlış hiçbir şekilde düzelmez.

## 11. Algoritma, optimallik ve alternatifler

Aç gözlü yaklaşımda bir karar verilir ve bir daha geri dönülmez. **Soru (hocanın sorusu):** Bu, optimal karar ağacını oluşturur mu? **Cevap:** Hayır. Ama optimal karar ağacını bulmak NP türünden bir problemdir (yukarıda konuşulan birleşik optimizasyon problemi); onun çözümü yerine aç gözlü yaklaşım tercih edilir.

**Soru (hocanın sorusu):** Bir karar ağacı her türlü eğitim kümesine tam uyum sağlar mı? **Cevap:** Evet. Eğitim kümesi (örneğin bir sınıflandırma problemi) ne kadar karmaşık olursa olsun, eğitim kümesinde %100 sonuç veren bir karar ağacı üretilebilir. Bu yüzden karar ağaçları oldukça esnek, evrensel algoritmalardır. Tek istisna, aynı noktada hem A hem B sınıfından örnek bulunmasıdır; ama bu karar ağacının sorunu değildir, bu durumda hiçbir algoritma eğitim kümesinde %100 başarıya ulaşamaz.

Alternatifler:

- Birden fazla özelliğe bağlı düğümler, yani çok değişkenli karar ağaçları.
- İkiden fazla dal: şimdiye kadar hep ikiye bölündü, ikili ağaçlar (binary tree) oluşturuldu; üçlü ve daha fazla dallı ağaçlar da kullanılabilir.
- İleriye bakarak arama: şimdiye kadar yalnız "buradan bölersem ne olur" sorusuna odaklanıldı. Daha ileri seviyede "buradan, sonra da şuradan bölersem ne olur" diye daha büyük bir uzayda aranarak belki daha doğru kararlar verilebilir.

## 12. Çevrimiçi / artımlı algoritmalar

Slayt şöyleydi (ekrandan, 01:35:00):

- Eğitim kümesine yeni örneklerin katılması durumunda baştan eğitime ihtiyaç duymayan algoritmalar.
- Çok büyük veri kümesine sahip ve/veya dağılım değişimi olan problemler için uygun.
- Herhangi bir anda tahmin üretebilirler (eğitimin bitmesine gerek yok).
- YSA'lar, LVQ, SOM, çevrimiçi K-means vb.
- Karar ağaçları böyle değil, ama çevrimiçi versiyonları var.

Çok büyük veri kümesi için uygunluk şöyle açıklandı: karar ağacı algoritması bir düğümde (örneğin kökte) bölme yaparken bütün örneklerin bütün özelliklerine bakar, çünkü her olası bölmenin iyiliğini hesaplaması gerekir. Çok büyük veri kümelerinde bu bellek yetmeyecek büyüklüklere ulaşabilir. Çevrimiçi algoritmalar ise örnekleri tek tek ya da küçük mini-batch'ler hâlinde alır ve her seferinde kendini (parametrelerini) günceller.

Dağılım değişimi için örnek duygu (sentiment) analizidir. Bir veri kümesi toplanıp bir model kurulduğunu ve çalıştırıldığını düşünelim. Bu modelin performansı zamanla büyük olasılıkla kötüleşir, çünkü dil yaşayan bir şeydir: yeni jargonlar, yeni kavramlar, bunlarla ilgili yepyeni tweet'ler ve birleşimler ortaya çıkar. Modelin yeni örneklerle güncellenmesi gerekir. Sıfırdan eğitim yapmak yerine yeni örnekler geldikçe algoritmaya verilebilirse çok daha esnek bir yapı elde edilir.

Yapay sinir ağları, LVQ, Self Organizing Map ve çevrimiçi K-means bu tür algoritmalardır. Klasik karar ağaçları böyle değildir, ama çevrimiçi sürümleri vardır. Hoca bunların ayrıntısını öğrencilere bıraktı: Hoeffding ağaçlarında ağaç başlangıçta bir kez üretilip bitmez; bir ağaç oluşturulur, sonra yeni örnekler geldikçe güncellenir, eğitim en baştan yapılmaz. Bu özellik karar ağaçlarını büyük veri kümeleri ve dağılım değişimi olan problemler için uygun hâle getirir.

> **Ek bilgi (derste anlatılmadı):** Hoeffding ağacı (VFDT, Very Fast Decision Tree), bir düğümde en iyi bölme ile ikinci en iyi bölme arasındaki farkın yeterince büyük olduğuna Hoeffding sınırı ile karar verir. Böylece bölme kararı bütün veri görülmeden, yeterli sayıda örnek geldiğinde verilir ve her örnek bir kez işlenir.

Bir öğrencinin LightGBM sorusuna hoca, ileride geleceklerini, kabaca bunun tek bir ağaç değil bir topluluk (ensemble), yani kollektif öğrenme yöntemi olduğunu söyledi.

## 13. Ödev sunumlarından çıkan akademik noktalar

Dersin ikinci yarısında birkaç öğrenci birinci ödevini sundu. Ödevde 10 boyutlu konveks ve konveks olmayan fonksiyonlar seçilip gradyan inişi, Adam ve koordinat inişi farklı başlangıç noktaları ve hiperparametrelerle karşılaştırılıyordu. Burada yalnız akademik bulgular ve hocanın açıklamaları aktarılmıştır.

### 13.1 Fonksiyon seçimi

- Bir öğrenci konveks fonksiyonları iki boyutlu kuadratik fonksiyonları toplayarak, değişkenleri birbirine bağlamak için $x_6 x_7$, $x_7 x_8$ gibi çapraz terimler ekleyerek kurdu. Konveks olmayan fonksiyonu, iki yerel ve bir global minimumu olan dördüncü dereceden bir polinomu konveks fonksiyonlarla toplayarak elde etti (ekrandan, 01:40:00).
- Bir öğrenci her değişkenin karesini ve her değişkenden bir sabit çıkarılmış karesini konveks fonksiyon olarak aldı; bazı eksenlerin işaretini eksiye çevirerek konveks olmayan fonksiyonlar kurdu.
- Bazı öğrenciler test fonksiyonu sitelerinden küre (sphere), döndürülmüş hiperelipsoid, Rastrigin, Bohachevsky ve Ackley fonksiyonlarını aldı. Rastrigin çok sayıda yerel minimumu olan, global minimumu 0'da ($x = 0$) olan bir fonksiyondur. Bohachevsky'nin çok boyutlu genellemesi ekranda şöyleydi (ekrandan, 01:55:00):

$$f_{\text{Bohachevsky}}(x) = \sum_{i=1}^{n-1} \left[x_i^2 + 2x_{i+1}^2 - 0{,}3\cos(3\pi x_i) - 0{,}4\cos(4\pi x_{i+1}) + 0{,}7\right]$$

Bu fonksiyon $x = 0$'da 0 değerini alır (python ile doğrulandı); konvekse benzer, ama yüzeyinde "portakal kabuğu" gibi yerel minimumlar vardır.

- Bir öğrenci konveksliği 10x10'luk Hessian matrisinin özdeğerlerine bakarak sınadı: bütün özdeğerler pozitifse (pozitif tanımlı) konveks dedi. $f_4 = x_1x_2 + x_3x_4 + x_5x_6 + x_7x_8 + x_9x_{10}$ fonksiyonu için Hessian'ın özdeğerleri $1$ ve $-1$'dir, bu yüzden konveks değildir (ekrandan, 02:25:00). Bu özdeğerler python ile doğrulandı: beş tane $-1$, beş tane $+1$.

### 13.2 Gözlenen davranışlar

- Konveks fonksiyonlarda başlangıç noktası ne olursa olsun aynı minimuma varıldı; başlangıç noktası yalnız iterasyon sayısını etkiledi.
- Konveks olmayan fonksiyonlarda farklı başlangıçlar farklı yerel minimumlara götürdü; bazı eksenlerde değer sonsuza ıraksadı. Büyük adım (öğrenme oranı) ıraksamaya yol açtı, küçük adım yakınsamayı yavaşlattı. Bir sunumda Rastrigin'de gradyan inişi öğrenme oranı 0,02 iken zikzak çizip minimuma ulaşamadı, 0,002 ile ulaştı (ekrandan, 02:20:00).
- Koordinat inişi bir seferde tek boyutu güncellediği için yörüngeler merdiven basamağı gibi, tırtıklı göründü. Bir iterasyonda 10 türev hesapladığı için süre bakımından gradyan inişinden yavaş çalıştı; adil karşılaştırma için iterasyon sayısını 10'a bölmek önerildi.
- Adam'da $\beta$ değerleri küçültülünce önceki gradyanlar daha az kullanıldığı için grafik daha dalgalı ve yavaş oldu; $\beta$ büyüdükçe daha düzgün oldu.
- Bazı denemelerde Adam konveks fonksiyonlarda gradyan inişinden daha fazla iterasyonla minimuma ulaştı.

### 13.3 Hocanın açıklamaları

**Soru:** PCA ile t-SNE yörüngeleri neden farklı çıkıyor? **Cevap:** İkisi de boyut azaltma yöntemidir, ama farklı algoritmalar ve farklı varsayımlarla çalışırlar. Birinin yaptığı izdüşümün diğerininkiyle birebir aynı olması gerekmez. Gösterilen örnekte şekiller benzerdi; aralarında bir miktar dönme ve öteleme farkı vardı.

**Soru:** Adam'da konveks bir fonksiyonda kayıp neden üstel olarak azalmak yerine dalgalanıyor? **Cevap:** Adam önceki gradyanları da işin içine katar, bir sürüklenme (drift) etkisi oluşur. Huni biçimli konveks bir yüzeyde kenardan ileriye doğru itilen bir top düşünün: genel olarak aşağı iner, ama önceki hızı nedeniyle aralarda yukarı çıkar. Bu momentum etkisidir.

**Soru:** Bir fonksiyonun konveks olup olmadığından emin değilsem ne yapabilirim? **Cevap:** Optimizasyon sonuçlarına bakarak da kontrol edilebilir. Nereden başlanırsa başlansın aynı yere varılıyorsa fonksiyon büyük olasılıkla konvekstir; farklı başlangıçlardan farklı yerlere varılabiliyorsa konveks değildir.

Bir sunumda yörünge yerine kaybın 10 bileşeni ya da ardışık ağırlık farkları 2 boyuta indirilmişti. Hoca, istenenin her adımdaki 10 boyutlu noktanın kendisinin saklanıp yörünge olarak çizilmesi olduğunu açıkladı; kayıp tek bir sayıdır ve derste iki boyutta çizilen, optimuma düzgünce yaklaşan yörüngelerin 10 boyuttaki karşılığı görülmek istenmektedir.

**Soru:** Momentumu olduğu için Adam'ın konveks fonksiyonlarda daha hızlı gelmesi beklenmez mi? **Cevap:** Beklenti, Adam'ın her adımda daha çok işlem yapıp daha az adımda varmasıdır; bazı deneylerde tersinin çıkması şaşırtıcıdır. Ama Adam özellikle yapay sinir ağları ve derin öğrenme mimarilerinin eğitiminde yaygın kullanılsa da gradyan inişi gözden düşmüş değildir.

> **Hocanın vurgusu:** Adam'ın her durumda gradyan inişini yendiğini söylemek mümkün değil; empirik deneyler bunu gösteriyor ve sunulan bazı deneyler de buna uygun.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $\{\hat{c}_m, \hat{R}_m\}_1^M = \operatorname{argmin}_{\{c_m, R_m\}_1^M} \sum_{i=1}^{N} [y_i - \sum_{m=1}^{M} c_m I_{R_m}(x_i)]^2$ ifadesinde argmin neyi ifade eder, hangi değişkenler bilinir, hangileri aranır?

> **Çözüm:** $x_i$ ve $y_i$ (veri kümesi) bilinir. Aranan $M$ bölge ($R_m$) ve $M$ çıkıştır ($c_m$). Argmin, karesel hata toplamını en küçük yapan bu değerleri döndürür (min ise yalnız en küçük hata değerini verirdi). $c_m$ ve $R_m$ birlikte aranması gereken birleşik bir problem olduğu için çok zordur.

**Soru 2** (ekrandan, 00:45:00): Sınıflandırma problemlerinde bir bölgenin çıkışı $c$ nasıl belirlenir?

> **Çözüm:** Bölgeye düşen eğitim örneklerinin sınıfları arasında en sık görülen sınıf çıkış olarak verilir. Regresyonda ise çıkış, bölgedeki örneklerin çıkışlarının ortalamasıdır.

**Soru 3** (derste sözlü, 00:48:37): Parametre ile hiperparametre arasındaki fark nedir? Karar ağacının durma ölçütlerinden hangileri hiperparametredir?

> **Çözüm:** Parametreler eğitimle veriden bulunur (karar ağacında bölgeler ve çıkışlar). Hiperparametreler sistemin kendisinin belirleyemediği, önceden tanımlanan değerlerdir: maksimum derinlik, saflık eşiği (ör. %90), standart sapma eşiği, minimum yaprak büyüklüğü.

**Soru 4** (derste sözlü, 00:51:08): Regresyonda bir bölgedeki örneklerin çıkışlarının standart sapmasının sıfır olması ne anlama gelir?

> **Çözüm:** Bölgedeki bütün örneklerin çıkışları aynıdır; bölgede tek örnek olması da bu durumu sağlar. Bu, %100 saflıktan farklıdır; saflık sınıflandırma için kullanılır.

**Soru 5** (ekrandan, 01:00:00): Tek girdili bir regresyon verisinde noktalar farklı yüksekliklerde olsun. Durma ölçütü "çıkışların standart sapması sıfır olana kadar böl" ise karar ağacı nasıl bir fonksiyon üretir?

> **Çözüm:** Bir basamak fonksiyonu üretir: her farklı çıkış düzeyi için yatay bir parça, atlamalar ardışık iki noktanın tam ortasında. Aynı düzeydeki komşu noktalar için ayrı basamak üretilmez. Klasik ağaç eğri bir fonksiyon üretemez.

**Soru 6** (derste sözlü, 01:30:08): Aç gözlü (greedy) algoritma ne demektir ve karar ağaçlarında hangi soruna yol açar?

> **Çözüm:** Bir karar verip bir daha arkasına bakmayan algoritmadır. Karar ağacında aşağıdan yukarıya geri güncelleme mekanizması olmadığı için üst seviyede yapılan bir yanlış hiç düzeltilmez ve optimal ağaç garanti edilmez.

**Soru 7** (derste sözlü, 01:31:18): Bir karar ağacı her türlü eğitim kümesine tam uyum sağlar mı?

> **Çözüm:** Evet, eğitim kümesinde %100 başarı veren bir ağaç her zaman üretilebilir. Tek istisna aynı noktada farklı sınıflardan örnek bulunmasıdır; bu durumda hiçbir algoritma eğitim kümesinde %100'e ulaşamaz.

**Soru 8** (ekrandan, 02:25:00): $f_4(x) = x_1x_2 + x_3x_4 + x_5x_6 + x_7x_8 + x_9x_{10}$ fonksiyonu konveks midir?

> **Çözüm:** Hessian matrisi, her $(2k-1, 2k)$ ve $(2k, 2k-1)$ konumunda 1, diğer yerlerde 0 olan 10x10'luk bir matristir. Her $2\times2$ blok $\begin{pmatrix}0&1\\1&0\end{pmatrix}$ olup özdeğerleri $\pm 1$'dir. Toplamda beş $+1$ ve beş $-1$ özdeğer vardır (python ile doğrulandı). Hessian belirsiz (indefinite) olduğu için fonksiyon konveks değildir; eyer biçimlidir.

**Soru 9** (derste sözlü, 02:32:01): Adam ile konveks bir fonksiyon optimize edilirken kayıp eğrisi neden zaman zaman yükselip dalgalanabilir?

> **Çözüm:** Adam önceki gradyanları biriktirerek ilerler (momentum). Huni biçimli bir yüzeyde itilen bir top gibi genel olarak aşağı iner, ama önceki hızı nedeniyle ara ara yukarı çıkar. Bu sürüklenme etkisi dalgalanmaya yol açar.

**Soru 10** (derste sözlü, 02:35:11): Seçilen bir fonksiyonun konveks olup olmadığı optimizasyon sonuçlarından nasıl kontrol edilebilir?

> **Çözüm:** Farklı başlangıç noktalarından optimizasyon yapılır. Hepsi aynı noktaya varıyorsa fonksiyon büyük olasılıkla konvekstir; farklı noktalara varılıyorsa konveks değildir.

## Dersin Toparlaması

Bu derste karar ağaçlarının uzayı kesişmeyen bölgelere bölüp her bölgede tek çıkış üreten bir varsayıma dayandığı görüldü. Ağaç $T(x) = \sum_m c_m I_{R_m}(x)$ olarak yazıldı. Optimal ağacı bulmak, bölgeleri ve çıkışları birlikte arayan zor bir birleşik optimizasyon problemi olduğu için bölgeler hiperdikdörtgenlerle sınırlandı ve uzay aç gözlü biçimde, her adımda en büyük iyileşmeyi ($Imp$) sağlayan özellik-eşik çiftiyle ikiye bölündü. Regresyonda bölge çıkışı ortalama, sınıflandırmada en sık sınıftır. Durma ölçütleri (derinlik, saflık, standart sapma, yaprak büyüklüğü) ağacın ne kadar ayrıntılı bir basamak fonksiyonu üreteceğini belirler. Karar ağaçları özellik seçimi yapan, ölçekten etkilenmeyen, hızlı, eksik veriyle başa çıkabilen ve yorumlanabilir modellerdir. Buna karşılık merdiven etkisi, derinde az örnek, toplamsal ilişkilerde zayıflık ve özellikle yüksek varyans gibi kısıtları vardır.

Hoca, tek ağaç için kötü olan yüksek varyansın birden çok ağaç kullanıldığında avantaja dönüşeceğini ve sonraki derslerde kollektif öğrenmeye giriş yapılacağını belirtti. Çevrimiçi algoritmalar ve karar ağaçlarının çevrimiçi sürümü olan Hoeffding ağaçları da büyük veri ve dağılım değişimi için bir seçenek olarak tanıtıldı. Ödev sunumları ise konveks ve konveks olmayan yüzeylerde gradyan inişi, Adam ve koordinat inişinin davranış farklarını, başlangıç noktası ve öğrenme oranının etkisini somut olarak gösterdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
