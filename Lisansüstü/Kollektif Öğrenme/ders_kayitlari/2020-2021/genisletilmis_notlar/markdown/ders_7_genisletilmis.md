# Ders 7 Genişletilmiş Notu: Rotasyon Ormanları, İyileştirilmiş Uzay Ormanları ve ECOC

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin planı ve rastgeleliğin bedeli
- 2. Rotasyon Ormanlarının fikri
- 3. Veriyi döndürmek ve PCA
- 4. Farklı dönüşüm matrisleri nasıl bulunur?
- 5. Rotation Forest algoritması
- 6. Seyrek, blok köşegen rotasyon matrisi
- 7. Karar ağaçları döndürmeye neden duyarlı?
- 8. Deneysel karşılaştırma
- 9. Kappa-hata diyagramları
- 10. İyileştirilmiş Uzay Ormanları
- 11. Hata düzelten çıkış kodu tabanlı topluluklar (ECOC)
- 12. İkinci ödev sunumlarından çıkan akademik noktalar
- Örnek Sorular

## 1. Dersin planı ve rastgeleliğin bedeli

Bir önceki derste aşırı rastgele ormanlara (Extremely Randomized Trees) kadar gelinmişti. Bu derste önce Rotasyon Ormanları (Rotation Forest) ve İyileştirilmiş Uzay Ormanları (Improved Space Forest), ardından hata düzelten çıkış kodu tabanlı topluluklar anlatıldı. Dersin ikinci yarısında ikinci ödevin sunumları yapıldı.

Hoca konuya rastgele özellik kullanımının iki yüzünü hatırlatarak girdi. Rastgele altuzaylarla başlayıp rastgele ormanlarla süren ve aşırı rastgele ormanlarla en uç noktasına varan çizgide, her düğümde bütün özelliklere bakmak yerine daha az sayıda özelliğe bakılır. Bu, her modelin üretilme hızını epey artırır. Dezavantajı da şudur: veride işe çok yarayacak anlamlı özellikler olabilir, ama rastgele seçilenlerin arasında bulunmazlarsa o düğümün bölmesi iyi yapılamaz. Bu da ağacın büyümesine yol açar. Ağaç derinleştikçe genelleme yeteneği azalır ve tekil öğrenicinin başarısı düşer.

Öte yandan aynı rastgelelik kararların birbirinden farklı olmasını sağlar. Ne kadar rastgele işlem yapılırsa ağaçlar o kadar farklılaşır ve o kadar farklı sonuçlar üretirler. Hoca bunu "bir tarafından kazanırken bir tarafından kaybediyoruz" diye özetledi.

## 2. Rotasyon Ormanlarının fikri

Rotation Forest, J. J. Rodriguez ve L. I. Kuncheva tarafından 2006'da önerilmiş bir algoritmadır (ekrandan, 00:15:00, slayt listesi). Çıkış noktası şu gözlemdir: orijinal eğitim kümesine yakın eğitim kümeleriyle eğitilen temel öğrenicilerin tekil başarısı yüksektir, ancak kararları birbirinden pek farklı olmaz.

Hoca bunu Bagging üzerinden açıkladı. Bir tekil öğrenici orijinal veri kümesine ne kadar yakın bir kümeyle eğitilirse başarısı o kadar yüksek olur, çünkü çok benzer bir dağılımdan üretilmiştir. Makine öğrenmesinin temel varsayımı zaten test verisinin eğitim verisiyle aşağı yukarı aynı dağılımdan geldiğidir.

Rotation Forest'ın önerisi şudur: bütün örnekler ve bütün özellikler aynı kalsın. Özellikler rastgele seçilmesin, örnekler üzerinde de bootstrap ya da bagging yapılmasın. Yeni bir eğitim kümesi üretilecek, ama örnekler de özellikler de aynı olacak. Farklılık veriyi döndürerek sağlanır; algoritmanın adı da buradan gelir. Orijinal veri belli bir miktar döndürülüp bir temel öğreniciye verilir, sonra orijinal veri başka bir şekilde döndürülüp başka bir öğreniciye verilir. Temel öğrenicinin ağaç olması şart değildir.

## 3. Veriyi döndürmek ve PCA

Veri $N$ örnek ve $d$ özellikten oluşan $N \times d$ boyutlu bir $X$ matrisidir. Döndürülmüş veri $X'$, $X$'in $d \times d$ boyutlu bir matrisle çarpılmasıyla bulunur (ekrandan, 00:15:00):

$$X' = X \cdot (d \times d) \;\Rightarrow\; (N \times d)(d \times d) = N \times d$$

Yani aranan şey, özellik sayısı çarpı özellik sayısı boyutunda bir matristir. $X$ bu matrisle çarpıldığında boyutu değişmez, ama içeriği değişir. Bir veriyi bir matrisle çarpmak onu bir şekilde döndürmek anlamına gelir; ölçekleri de değişebilir, ama temelde bir döndürmedir.

Veriyi döndürmek için en çok kullanılan yaklaşımlardan biri PCA'dır (Principal Component Analysis, temel bileşenler analizi). PCA da $d \times d$ boyutlu bir matris bulur; $X$ bu matrisle çarpılınca veri yeni bir uzaya taşınır. PCA'nın temel kullanım amacı ise özellik sayısını azaltmaktır. Matrisin bütün sütunları yerine ilk $k$ tanesi (örneğin 3-5 tanesi) alınırsa veri $k$ boyutlu uzaya iz düşürülür ve $N \times k$ boyutlu olur. Bu belli bir bilgi kaybına yol açar, ama çok daha az özellikle iş görmeyi sağlar.

Rotation Forest için PCA kullanılabilir, ama bir sorun vardır: PCA deterministik bir algoritmadır. İçinde rastgele bir süreç olmadığından aynı $X$ verildiğinde her seferinde aynı dönüşüm matrisini bulur. Hoca bunu Random Forest'la karşılaştırdı: Random Forest'a aynı veri her verildiğinde farklı ağaçlar üretilir, çünkü hem özellik seçiminde hem örnek seçiminde rastgelelik vardır. PCA'da öyle değildir.

## 4. Farklı dönüşüm matrisleri nasıl bulunur?

Farklı dönüşüm matrisleri elde etmek için slaytta üç olasılık sayıldı (ekrandan, 00:15:00):

- örneklerden bir kısmı,
- sınıflardan bir kısmı,
- özelliklerden bir kısmı.

Burada önemli bir ayrıntı vardır: örneklerin bir kısmının kullanılması yalnız dönüşüm matrisinin hesaplanması içindir. Döndürülen $X$'te herhangi bir örnek azaltması yapılmaz. Sınıfların bir kısmını kullanmak da aslında örneklerin bir kısmını kullanmaktır: örneğin 10 sınıf varsa içinden 5 sınıf seçilip yalnız onların örnekleriyle dönüşüm hesaplanır.

Böylece ilk ağaç için bir $T_1$ matrisi bulunur, veri bununla çarpılır ve elde edilen $X'$ bir karar ağacına verilir. Sonra orijinal veri için başka bir $T_2$ matrisi bulunur; çarpım başka bir veri verir ve o da başka bir ağaca gider. Her ağaca verilen veri $N \times d$ boyutludur: bütün örnekleri ve bütün özellikleri içerir, ama özellikler orijinal uzayda değil, döndürülmüş hâldedir.

## 5. Rotation Forest algoritması

Algoritmanın girdileri şunlardır (ekrandan, 00:20:00):

- $\mathcal{L} = \{(\mathbf{x}_i, y_i)\}_{i=1}^{N} = [X \; Y]$: eğitim kümesi. $X$, $N \times p$ boyutlu girdi matrisi, $Y$ sınıf etiketlerinden oluşan $N$ boyutlu sütun vektörüdür. Burada özellik sayısı $p$ ile gösterilmiştir.
- $K$: özellik alt kümelerinin sayısı (ya da $M$: her alt kümedeki özellik sayısı).
- $\mathcal{W}$: temel öğrenme algoritması.
- $T$: iterasyon (öğrenici) sayısı.
- $\mathbf{x}$: sınıflandırılacak test örneği.

Eğitim aşamasında her $t = 1, 2, \dots, T$ için $C_t$ sınıflandırıcısının rotasyon matrisi $R_t^a$ beş adımda hesaplanır:

1. Özellik kümesi $F$ rastgele $K$ alt kümeye ($F_{t,k}$) bölünür.
2. Her $k = 1, \dots, K$ için:
   - (a) $X$'in $F_{t,k}$'deki özelliklere karşılık gelen sütunları seçilerek $X_{t,k}$ alt matrisi oluşturulur.
   - (b) $X_{t,k}$'den bir bootstrap örneklemi $X'_{t,k}$ çekilir (slayta göre örneklem boyutu genellikle $X_{t,k}$'den küçüktür).
   - (c) $X'_{t,k}$'ye PCA uygulanır; $i.$ sütunu $i.$ temel bileşenin katsayılarından oluşan $D_{t,k}$ matrisi elde edilir.
3. Döngü biter.
4. $D_{t,k}$ matrisleri blok köşegen bir $R_t$ matrisine yerleştirilir.
5. $R_t$'nin satırları orijinal özellik sırasına karşılık gelecek şekilde yeniden düzenlenerek $R_t^a$ bulunur.

Ardından $[X R_t^a \; Y]$, $\mathcal{W}$'ye girdi olarak verilir ve $C_t$ sınıflandırıcısı eğitilir. $X$ $N \times p$ boyutlu olduğuna göre $X R_t^a$ de $N \times p$ boyutludur.

### 5.1 Test aşaması

Test aşamasında gelen bir örnek, Bagging ya da Random Forest'taki gibi doğrudan tekil öğrenicilere verilemez.

**Soru (hoca):** Diğer yöntemlerde test örneğini doğrudan veriyorduk; burada neden veremeyiz? **Cevap (bir öğrenci):** Aynı uzayda değiller. Hoca bunu onayladı: her sınıflandırıcı $X R_t^a$ ile, yani kendi uzayında eğitilmiştir. Test örneği önce o sınıflandırıcının rotasyon matrisiyle çarpılır; böylece $t.$ sınıflandırıcının uzayına taşınır ve ancak ondan sonra $C_t$'ye verilir.

Topluluk kararı (ekrandan, 00:20:00):

$$C^*(\mathbf{x}) = \arg\max_{y \in \Phi} \sum_{t=1}^{T} I\big(C_t(\mathbf{x} R_t^a) = y\big)$$

Burada $I(\cdot)$ gösterge fonksiyonudur: içi doğruysa 1, değilse 0 verir. $\Phi$ bütün sınıf etiketlerinin kümesidir. En çok oyu alan sınıf kazanır; herhangi bir ağırlıklandırma yoktur. Örneğin üç sınıflandırıcıdan ikisi "B", biri "A" derse örnek B sınıfına atanır.

**Soru:** $X$'i döndürüyoruz da $Y$'yi neden döndürmüyoruz? $X$'e karşılık gelen bir $Y$ yok muydu? **Cevap:** $Y$'ler sınıf bilgisidir. Etiketi bir renk gibi düşünmek gerekir: bir noktanın koordinatı değişince rengi, yani etiketi değişmez. Bu yüzden $Y$ üzerinde hiçbir dönüşüm yapılmaz, aynen kalır.

### 5.2 Modelde saklanması gerekenler

Random Forest'ta ya da Bagging'de bir test örneğini sınıflandırmak için yalnız temel öğreniciler (ör. ağaçlar) yeterlidir; Boosting'de de büyük ölçüde öyledir. Rotation Forest'ta ise ağaçların yanında her ağacın rotasyon matrisinin de saklanması gerekir. Hocanın sorusuna bir öğrenci "matris" diye cevap verdi; hoca bütün bu matrislerin model içinde tutulması gerektiğini vurguladı.

## 6. Seyrek, blok köşegen rotasyon matrisi

Hoca sonra matrisin nasıl üretildiğine döndü. Yöntem, veriyi çok fazla bozmamayı amaçlar.

**Soru (hoca):** Bir veriyi en az bozan matris hangisidir? **Cevap (bir öğrenci):** Birim matris. Köşegeninde yalnız 1'ler, geri kalanında 0'lar olan birim matrisle çarpılan veri kendisini verir; hiçbir değişiklik olmaz.

Rotation Forest'ta veri birim matrise benzeyen matrislerle çarpılır. Benzerlikten kasıt şudur: sıfırdan farklı değerler köşegenin yakınında, bloklar hâlinde yer alır; köşegenden uzak yerler sıfırdır.

Hoca bunu ekrana $9 \times 9$'luk bir tablo çizerek gösterdi (ekrandan, 00:30:00; sonuç slayt 44'ün küçük resminde görünüyor). Dokuz özellik varsa dönüşüm matrisi $9 \times 9$ boyutludur. Birim matriste yalnız köşegen 1'dir. Burada ise köşegen boyunca üç tane $3 \times 3$'lük blok için değer üretilir, geri kalan bütün elemanlar sıfır bırakılır. Bloklar algoritmadaki $K$ alt kümeye karşılık gelir: dokuz özellik üç alt kümeye bölünür.

Adımlar şöyledir:

- Dokuz özellik rastgele üç alt kümeye bölünür; örneğin {1, 6, 7}, {2, 3, 5} ve {4, 8, 9}.
- Birinci alt kümenin üç özelliğiyle bootstrap yapılır (N örnek içinden N örnek seçilir) ve PCA uygulanır. Üç özellik olduğu için PCA $3 \times 3$'lük bir matris verir.
- Aynı işlem ikinci ve üçüncü alt küme için yapılır; her biri başka bir $3 \times 3$ matris verir.
- Bu üç blok köşegene yerleştirilir. Böylece bütün özellikler kullanılmış olur, ama bloklar dışındaki elemanlar sıfırdır.

Bu tür seyrek bir matrisle çarpmak veriyi bir miktar döndürür, ama büyük bir değişime uğratmaz. Matrisin tamamı dolu olsaydı veri epey dönecek ve epey bozulacaktı. Seyrek dönüşüm bunu önler.

> **Ders sonrası not:** Hoca bootstrap için "N örnekten N örnek seçilir" dedi. Gösterilen algoritma metnine göre ise örneklem boyutu genellikle $X_{t,k}$'den küçük seçilir (ekrandan, 00:20:00). Uygulamada büyük olasılıkla daha küçük bir oran kullanılır.

## 7. Karar ağaçları döndürmeye neden duyarlı?

Hoca, küçük bir döndürmenin neden yeterli olduğunu bir karşılaştırmayla açıkladı.

**Soru (hoca):** Bütün veriyi orijin etrafında 45 derece döndürürsek 1-NN algoritmasının sonuçları değişir mi? **Cevap (bir öğrenci):** Değişmez. Döndürme noktalar arasındaki uzaklıkları korur.

Bir karar ağacında ise veri 45 derece döndürülürse ağaç çok değişir, çünkü karar ağacı eksenlere dik karar sınırları üretir. Karar ağaçları döndürmeye karşı aşırı hassastır. Bu yüzden büyük değişiklikler yapmaya gerek yoktur; küçük değişiklikler bile ağaçlar arasında farklılık oluşturur. Seyrek dönüşüm matrisinin amacı da veriyi fazla bozmadan bu farklılığı elde etmektir.

> **Ek bilgi (derste anlatılmadı):** PCA'nın bulduğu temel bileşen matrisi ortogonaldir; ortogonal bloklardan oluşan blok köşegen bir matris de ortogonaldir. Ortogonal dönüşüm iki nokta arasındaki Öklid uzaklığını korur. Bu yüzden 1-NN gibi uzaklığa dayalı yöntemler böyle bir döndürmeden etkilenmez, eksene dik bölmeler yapan ağaçlar ise etkilenir.

## 8. Deneysel karşılaştırma

Slaytta Rotation Forest'ın diğer topluluk yöntemleriyle karşılaştırması gösterildi (ekrandan, 00:35:00). Temel öğrenici J48'dir (C4.5'in Weka'daki karşılığı olan bir karar ağacı algoritması). Tabloda 34 veri kümesinde Rotation Forest (J48), tek J48, Bagging (J48), Boosting (J48) ve Random Forest'ın doğrulukları ortalama ± standart sapma olarak verilmiştir. Bazı satırlar:

| Veri kümesi | Rotation (J48) | J48 | Bagging | Boosting | Random Forest |
|---|---|---|---|---|---|
| balance-scale | 90.26 ± 2.62 | 79.43 ± 4.01 | 81.39 ± 3.70 | 76.82 ± 4.14 | 80.28 ± 3.80 |
| letter | 95.54 ± 0.47 | 88.02 ± 0.75 | 92.85 ± 0.65 | 95.44 ± 0.50 | 94.52 ± 0.49 |
| vowel-n | 95.77 ± 1.94 | 79.22 ± 4.59 | 89.52 ± 3.27 | 91.93 ± 2.72 | 92.37 ± 2.73 |
| primary-tumor | 44.37 ± 6.56 | 42.42 ± 7.57 | 42.79 ± 6.92 | 41.64 ± 6.94 | 41.56 ± 6.50 |

Tablonun en alt satırı win/tie/loss sayılarıdır: J48 (0/13/21), Bagging (0/24/10), Boosting (1/25/8), Random Forest (0/24/10). Dipnota göre dolu yuvarlak "Rotation Forest anlamlı olarak daha iyi", boş yuvarlak "anlamlı olarak daha kötü" demektir (anlamlılık düzeyi 0.05). Yani sayılar karşı algoritmanın Rotation Forest'a göre durumudur: örneğin J48 hiçbir veri kümesinde kazanamamış, 13'ünde berabere kalmış, 21'inde kaybetmiştir. Her satırın toplamı veri kümesi sayısı olan 34'tür (python ile kontrol edildi).

Hoca, win/tie/loss sayılarının ikinci ödevde yapılan analizle aynı şey olduğunu hatırlattı: bir t-testi (ya da kullanılan başka bir test) ile kaç veri kümesinde kazanıldığı, kaybedildiği ya da berabere kalındığı sayılır. Bu tabloya göre Rotation Forest diğerlerinden daha başarılıdır.

## 9. Kappa-hata diyagramları

### 9.1 Kararların benzerliğini ölçmek

Ödevde istenenlerden biri, tekil öğrenicilerin kararlarının birbirine benzerliğini incelemek ve bunun topluluk doğruluğuyla ilişkisine bakmaktı. Hatayı bulmak kolaydır, ama kararların benzerliğini ölçmek ilk bakışta garip gelir. Bunun için birçok yöntem vardır; hoca iki yaklaşımdan söz etti:

- Her temel öğrenici ikilisi alınır, iki öğrenicinin örnekler üzerindeki kararlarının yüzde kaçının aynı olduğu bulunur ve bütün ikililerin ortalaması alınır. Kappa bu tür bir ikili ölçüdür.
- Her tekil öğrenicinin kararının, topluluğun (çoğunluk oylamasıyla bulunan) kararına ne kadar benzediği ölçülür.

### 9.2 Diyagramın okunması

Kappa-hata diyagramında her nokta bir ağaç ikilisidir. Bir eksen ikilinin kappa değeri, yani kararlarının uyumudur; diğer eksen iki ağacın hatalarının ortalamasıdır. Vowel verisi için gösterilen diyagramda (ekrandan, 00:40:00) yatay eksen $\kappa$ (0 ile 0.8 arası), dikey eksen ortalama hata $E_{i,j}$ (0.5 ile 0.9 arası) idi. 100 temel öğrenicili topluluklarda bütün olası ağaç ikilileri çizilmiştir.

**Soru (hoca):** 100 temel öğrenicinin içinden kaç tane ikili seçilebilir? Derste bir öğrenci 5500 dedi, hoca da bunu kabul edip "5500 tane nokta var" diye devam etti.

> **Ders sonrası not:** Hoca 5500 sayısını kabul etti; doğrusu $\binom{100}{2} = \frac{100 \cdot 99}{2} = 4950$'dir (python ile kontrol edildi). Sunumlarda bir öğrenci de 5500'ün yanlış olduğunu söyleyip $100 \cdot 101 / 2 = 5050$ verdi. Bu değer her öğrenicinin kendisiyle eşleşmesini de sayar; farklı ağaç ikilisi sayısı 4950'dir.

Örnek bir kırmızı nokta için hoca "kappa değeri 0.1, hata 0.68 civarında" diye okudu: o iki ağacın kararları birbirinden oldukça farklı, ortalama hataları ise 0.68 civarındadır. Kırmızı noktalar Rotation Forest'a, bir bölgedeki siyah noktalar Random Forest'a, arka taraftaki gri noktalar AdaBoost'a, sağdaki siyah bulut Bagging'e aittir. Diyagramdaki sayılar topluluk doğruluklarıdır: Rotation Forest 95.77, Random Forest 92.37, AdaBoost 91.93, Bagging 89.52.

### 9.3 İdeal nokta ve yorum

Topluluklarda istenen iki şey vardır: tekil ağaçların hatası en az olsun ve kararları birbirinden en farklı olsun, yani benzerlikleri sıfıra yaklaşsın. Bu yüzden ideal nokta sol alt köşedir: buluttaki noktalar oraya yaklaştıkça ağaç ikilileri hem düşük hatalı hem de birbirinden farklı demektir.

Hocanın diyagram okuması şöyleydi:

- Hata açısından: Bagging ağaçlarının hatası yaklaşık 0.6 civarında, yani tekil olarak en başarılı ağaçlar onlardır. Random Forest ağaçlarının hatası 0.7'ler civarında; en başarısız tekil ağaçlar onlardır. Rotation Forest ve AdaBoost bu ikisinin arasındadır.
- Kappa açısından: en düşük benzerlik Random Forest ağaçlarındadır; ardından Rotation Forest, AdaBoost gelir; kararları birbirine en çok benzeyenler Bagging ağaçlarıdır.

<!-- BELİRSİZ: Hoca Rotation Forest ile Bagging ağaçlarının hata düzeyini karşılaştırırken "Rotation Forest'ın hatası birazcık daha yüksek belki" dedi; diyagramda kırmızı bulut 0.5-0.75 aralığına yayılmış görünüyor, kesin sıralama kareden net okunamıyor. -->

Bu durumda Rotation Forest iki uç arasında bir denge yakalamış görünür: hem birbirinden farklı kararlar üretebiliyor hem de çok kötü olmayan ağaçlar üretiyor. Hoca bunun teorik bir açıklaması olmadığını, bir teorem değil deneysel bir gözlem ve fikir olduğunu belirtti.

> **Hocanın vurgusu:** Kappa-hata diyagramları topluluk dinamiklerini oldukça güzel gösterir. Farklı topluluk algoritmalarının kappa-hata diyagramlarını incelemek, topluluk dinamiklerini anlamak açısından çok faydalıdır.

> **Ek bilgi (derste anlatılmadı):** Kappa istatistiği iki sınıflandırıcının uyumunu, şans eseri beklenen uyumu düzelterek ölçer: $\kappa = (p_o - p_e)/(1 - p_e)$. Burada $p_o$ gözlenen uyum oranı, $p_e$ iki sınıflandırıcının sınıf dağılımlarından beklenen rastlantısal uyumdur. $\kappa = 1$ tam uyum, $\kappa = 0$ rastlantı düzeyinde uyum demektir.

## 10. İyileştirilmiş Uzay Ormanları

### 10.1 Genel fikir

İyileştirilmiş Uzay Ormanları (Improved Space Forest; Amasyalı, 2018, IEEE Transactions on Cybernetics) diğer algoritmalardan farklı olarak bir meta algoritmadır: başka topluluk algoritmalarıyla birlikte çalışabilir (ekrandan, 00:45:00). Bagging, AdaBoost ya da Random Forest ile kullanılabilir.

Bu yöntemde örnek ya da özellik sayısı azaltılmaz; tersine özellik sayısı artırılır. Slayttaki adımlar şunlardır (ekrandan, 00:45:00):

- Her öğrenici için orijinal özelliklerden yeni özellikler üretilir.
- Uzay $d$ boyuttan $d$ (orijinal) $+ z \cdot d$ (üretilmiş) boyuta çıkar. $z$ bir katsayıdır; örneğin $z = 1$ ise $d$ boyuttan $2d$ boyuta çıkılır, $d$ tane yeni özellik üretilmiş olur.
- Yeni özellik üretimi: eğitimden bir örneklem (bootstrap, N içinden N) seçilir; rastgele $f$'li özellik grupları (ikililer, üçlüler vb.) üretilir; her $f$ adet özellik için $k.$ dereceden doğrusal regresyonla çıkışı tahmin eden bir model oluşturulur; bu modelin tahminleri ($gf$) yeni bir özellik olarak eklenir.
- Her öğrenici $d + z \cdot d$ boyutlu uzayda eğitilir, sonuçlar oylamayla birleştirilir.

Her özellik grubundan bir yeni özellik çıkar. İşlem ne kadar tekrarlanırsa o kadar çok yeni özellik olur. Gruplar rastgele seçildiği için her yeni özellik farklıdır ve her öğrenici için farklı bir iyileştirilmiş uzay oluşur.

### 10.2 Özellik üretimi örneği

Hoca doğrusal regresyonu hatırlattı: $Y = XA$ modelinde $A$'yı bulmak için $X$ kendi transpozuyla çarpılıp tersi alınıyordu. Özellik üretimi slaytında iki durum gösterildi (ekrandan, 00:50:00; slayt 48 küçük resimde okunuyor, metin küçük):

$f = 2$, $k = 1$ için rastgele iki özellik $x_i$ ve $x_j$ seçilir ve tasarım matrisi kurulur:

$$SX = [\,1 \;\; x_i \;\; x_j\,]$$

$$w = (SX^T SX)^{-1} SX^T Y, \qquad gf = SX \cdot w$$

Burada $x_i, x_j$ özelliklerin $i.$ ve $j.$ sütunları, $Y$ çıkışlar, $gf$ tahmini çıkışlardır. Yani algoritma rastgele iki özellik alıp onlarla çıkışı doğrusal regresyonla tahmin etmeye çalışır ve bu tahmin ediciyi yeni bir özellik olarak tanımlar.

$f = 3$, $k = 2$ için rastgele üç özellik alınır ve ikinci dereceden (second order) doğrusal regresyon kullanılır. Bu durumda $SX$ daha uzun, daha çok sütunlu bir matristir:

$$SX = [\,1 \;\; x_i \;\; x_j \;\; x_k \;\; x_i x_j \;\; x_i x_k \;\; x_j x_k \;\; x_i^2 \;\; x_j^2 \;\; x_k^2\,]$$

<!-- BELİRSİZ: f=3, k=2 tasarım matrisinin terimleri slaytın küçük resminden okundu; sıralama tam doğrulanamadı. -->

İşlem yine aynıdır: $w$ en küçük kareler çözümüyle bulunur, $gf = SX \cdot w$ yeni özellik olur.

### 10.3 Yeni özelliklerin anlamı

Burada önemli olan "iyileştirilmiş" sözcüğüdür: amaç orijinal uzaydan daha iyi bir uzay bulmaktır. Hem orijinal hem yeni özellikler karar ağaçlarına verilir. Standart bir Bagging'deki tek bir ağaç düşünülürse bazı özellikler düğümlerde yer alır, bazıları almaz. Ağaç yalnız orijinal özelliklerden oluşuyorsa, üretilen özellikler pek bir anlam taşımıyor demektir. Yeni özellikler ağaçta yer alıyorsa üretimin başarılı olduğu düşünülebilir.

Her $gf$ birden çok özelliği (ikili, üçlü vb.) içerir; tek değişkenli (univariate) değildir. Bu yüzden bu özelliklerle yapılan bölmeler orijinal uzayı eksene dik çizgilerle bölmez. Standart yaklaşımın yapamadığı eğik, çok değişkenli (multivariate) sınırlar da işin içine girer.

### 10.4 Görsel örnek

Hoca iki sınıflı bir problem üzerinden gösterdi (ekrandan, 00:50:00). Artılar ve yuvarlaklar mavi bir gerçek sınıra göre etiketlenmiştir. Tek değişkenli ağaç (yeşil) bu sınırı merdiven gibi, art arda yatay ve dikey basamaklarla yaklaşık olarak çizer. İyileştirilmiş uzay ağacı (mor) ise gerektiği yerde düz (eksene dik) çizgiler, gerektiği yerde eğik çizgiler kullanır: bir bölgede orijinal uzaydan bir özellik seçer, başka bir bölgede üretilmiş özelliklerden birini seçer, yine başka bir bölgede orijinal bir özelliğe döner. Yani gerektiğinde karmaşıklaşıp gerektiğinde orijinal uzayda kalabilen bir yaklaşımdır. Slaytta "Yeni özellikler seçildiğinde ağaçlar küçülür" notu yer alıyordu.

Slayttaki kappa-hata diyagramları (hill-valley, letter, lymph, balance-scale, vehicle, splice verileri; $f = 2$, $k = 1$) iyileştirilmiş uzay sürümlerini BG, RF ve RotF'un orijinal sürümleriyle karşılaştırıyordu (ekrandan, 00:50:00). Hoca, farklı veri kümelerinde ve farklı topluluk algoritmalarıyla yöntemin oldukça iyi çalıştığının gözlendiğini, ayrıca birkaç teorik özelliği de olduğunu söyledi.

## 11. Hata düzelten çıkış kodu tabanlı topluluklar (ECOC)

### 11.1 Amaç

Aradan sonra hata düzelten çıkış kodu tabanlı topluluklara (Error-Correcting Output Codes, ECOC; Dietterich ve Bakiri, 1995) geçildi (ekrandan, 01:10:00). Amaç, $K$ sınıflı bir problemi daha basit alt problemlere, yani iki sınıflı $L$ tane probleme bölmektir. Bölme bir kod matrisi $W$ ile tanımlanır; $W$'yi oluşturmanın üç yöntemi vardır.

Bunun neden yapıldığını hoca şöyle açıkladı: elimizde yalnız iki sınıfı ayırabilen, örneğin doğrusal yapılı bir sınıflandırıcı olsun. ECOC sayesinde bu iki sınıflı sınıflandırıcı, istenen sayıda sınıfı ayırt eden bir model kurmakta kullanılabilir. En yaygın kullanıldığı yer SVM'lerdir: SVM'ler temelde iki sınıfı ayırır, ama ECOC yöntemlerinden biriyle 10 sınıflı bir problemde de kullanılabilir.

Kod matrisinde satırlar sınıfları, sütunlar ikili problemleri (eğitim kümelerini) gösterir. Her sütunun ifade ettiği eğitim setini bir öğrenici öğrenir. Yeni eğitim setinde sütunda $+1$ ile gösterilen sınıfa ait örneklerin çıkışı $+1$, $-1$ ile gösterilen sınıflara ait örneklerin çıkışı $-1$ yapılır (ekrandan, 01:10:00).

### 11.2 Yöntem 1: Bir sınıf diğer tüm sınıflara karşı

Bu yöntemde (one-versus-all) $L = K$'dır. Dört sınıf için kod matrisi (ekrandan, 01:10:00):

$$W = \begin{bmatrix} +1 & -1 & -1 & -1 \\ -1 & +1 & -1 & -1 \\ -1 & -1 & +1 & -1 \\ -1 & -1 & -1 & +1 \end{bmatrix}$$

Birinci problemde birinci sınıfın örnekleri $+1$, ikinci, üçüncü ve dördüncü sınıfın örnekleri $-1$ etiketini alır; yeni "birinci sınıfta" yalnız eski 1. sınıfın, yeni "ikinci sınıfta" 2., 3. ve 4. sınıfların örnekleri vardır. İkinci problemde yalnız 2. sınıfa $+1$, diğerlerine $-1$ verilir ve böyle devam eder. Bu dört yeni eğitim setiyle dört ikili temel öğrenici eğitilir.

Test aşamasında yeni örnek dört öğreniciye de verilir; her biri $+1$ ya da $-1$ döndürür. Bu dört değer bir satır olarak düşünülür ve $W$'nin hangi satırına en çok benziyorsa örnek o sınıfa atanır. Örneğin çıkış $(-1, -1, -1, +1)$ ise örnek 4. sınıftandır.

**Soru:** Çıkış $(+1, -1, +1, -1)$ gibi bir şey olursa ne olacak? **Cevap:** Elimizdeki satırlardan en çok hangisine benziyorsa ona atanır. İki satıra aynı anda eşit derecede benziyorsa bunlardan biri rastgele seçilip çıkış olarak verilir.

### 11.3 Yöntem 2: Sınıf ikilileri

İkinci yöntemde bütün olası sınıf ikilileri birer problem hâline getirilir (pairwise). Problem sayısı:

$$L = \frac{K(K-1)}{2}$$

Dört sınıf için $4 \cdot 3 / 2 = 6$ yeni problem elde edilir. Birinci problem yalnız 1. ve 2. sınıfı, ikincisi 1. ve 3. sınıfı, üçüncüsü 1. ve 4. sınıfı ayırır; bütün olası ikililer böyle sıralanır. Eğitim kümesi kurulurken yalnız o ikilinin örnekleri kullanılır: örneğin 1. sınıfı 4. sınıftan ayıran kümede 2. ve 3. sınıfın örneklerine ihtiyaç yoktur. Sınıflardan biri $+1$, diğeri $-1$ ile etiketlenir. Matriste probleme katılmayan sınıflar 0 ile gösterilir. Hocanın sıraladığı ilk üç sütuna göre matris şöyle kurulabilir (ara adım eklendi: son üç sütunun sırası ve hangi sınıfın $+1$ aldığı derste söylenmedi):

$$W = \begin{bmatrix} +1 & +1 & +1 & 0 & 0 & 0 \\ -1 & 0 & 0 & +1 & +1 & 0 \\ 0 & -1 & 0 & -1 & 0 & +1 \\ 0 & 0 & -1 & 0 & -1 & -1 \end{bmatrix}$$

Altı temel öğrenici eğitilir. Test örneği altı sonuç üretir; bu sonuçların oluşturduğu satır $W$'nin hangi satırına en çok benziyorsa örnek o sınıftandır.

### 11.4 Yöntem 3: Tüm olası alt problemler (full code)

Üçüncü yaklaşımda bütün olası alt problemler kullanılır. Problem sayısı:

$$L = 2^{K-1} - 1$$

Dört sınıf için $2^3 - 1 = 8 - 1 = 7$ yeni problem çıkar. Bu problemler arasında 1. sınıfı diğerlerinden, 2. sınıfı diğerlerinden ayıranlar, 1. ve 2. sınıfı 3. ve 4. sınıftan ayıran ya da 2. ve 3. sınıfı 1. ve 4. sınıftan ayıran gibi bütün olası bölmeler vardır. Sınıf sayısı çok olduğunda bu matris çok büyür. İşlem yine aynıdır: bütün öğreniciler sonuçlarını söyler, sonuç satırı $W$'nin hangi satırına benziyorsa örnek o sınıfa atanır.

Test süreciyle ilgili slaytta da belirtildiği gibi, $W$'deki 0'lar etkisiz eleman olarak algılanır; benzerlik hesabına katılmaz. Hoca, ECOC yaklaşımının özellikle SVM'ler için literatürde çok sık kullanıldığını tekrarladı.

> **Ek bilgi (derste anlatılmadı):** "Hata düzelten" adı kodlama kuramından gelir. Kod matrisinin satırları arasındaki en küçük Hamming uzaklığı $d$ ise, en yakın satıra atama kuralı $\lfloor (d-1)/2 \rfloor$ tane öğrenicinin hatalı karar vermesini tolere eder. One-versus-all matrisinde satırlar arası uzaklık 2 olduğu için tek bir hata bile düzeltilemez; full code gibi daha uzun kodlarda satırlar arası uzaklık arttığından birkaç hatalı öğrenici telafi edilebilir.

### 11.5 Sonraki derse kalanlar

Planda sırada Yerel Modellerin Birleşimi (Mixture of Experts, uzman karışımı) ve İki Aşamalı Öğrenme (Stacking) vardı. Hoca, sesindeki sorun nedeniyle bu iki konuyu sonraki derse bıraktı; çok uzun konular olmadıklarını, sonraki haftada karmaşık bir konu bulunmadığını söyledi. Stacking slaytında yöntem "öğrenicilerin çıktılarının yeni bir veri kümesi olarak görüldüğü yöntem (Wolpert, 1992)" diye tanımlanıyor ve $d_1, \dots, d_L$ öğrenicilerinin çıkışlarını birleştiren bir $f()$ fonksiyonu çiziliyordu (ekrandan, 01:15:00); konu bu derste anlatılmadı.

## 12. İkinci ödev sunumlarından çıkan akademik noktalar

Ödevde Zero Rule başarısı 0.7'nin altında kalan (sınıf dağılımı dengeli) 12 veri kümesi seçilecek; tek karar ağacı, Bagging, AdaBoost ve Random Forest 100 temel öğrenici ve 1, 2, 3, 5, 10 ve sonsuz maksimum derinlik değerleriyle karşılaştırılacaktı. İstenen analizler: 5x2 çapraz doğrulama ve t-testi ile win/tie/loss sayıları, maksimum derinliğe göre topluluk başarısı, ortalama tekil öğrenici başarısı, tekil öğrenici kararlarının benzerliği ve eğitim süresi. Sunumlarda öne çıkan akademik noktalar aşağıdadır.

### 12.1 5x2 katlı çapraz doğrulama ile t-testi

Bir öğrenci kullandığı testi raporunda şöyle tanımladı (ekrandan, 02:40:00): 5x2 katlı çapraz doğrulama, 2 katlı çapraz doğrulamanın her sınıflandırıcı için beş kez tekrarlanmasıdır. t istatistiği:

$$t = \frac{p_1^{(1)}}{\sqrt{\frac{1}{5}\sum_{i=1}^{5} s_i^2}}$$

Burada $p_i^{(j)}$, $i.$ iterasyonun $j.$ katındaki iki sınıflandırıcı arasındaki skor farkıdır; $p_1^{(1)}$ birinci iterasyonun birinci katındaki farktır. $i.$ iterasyondaki farkın varyansı:

$$s_i^2 = \big(p_i^{(1)} - \bar{p}_i\big)^2 + \big(p_i^{(2)} - \bar{p}_i\big)^2, \qquad \bar{p}_i = \frac{p_i^{(1)} + p_i^{(2)}}{2}$$

Sıfır hipotezi $H_0$ sınıflandırıcılar arasında istatistiksel olarak fark olmadığını, $H_1$ anlamlı fark olduğunu söyler. $t$ değeri 5 serbestlik dereceli dağılımın %95 güven aralığı dışında kalırsa $H_0$ reddedilir. Başka bir öğrenci, Python'daki hazır 5x2cv eşleştirilmiş t-testi fonksiyonunu kullandığını anlattı: fonksiyon $t$ ve $p$ değerlerini döndürür; $p < 0.05$ ise ve $t$ pozitif kritik değerden büyükse birinci model, negatif kritik değerden küçükse ikinci model kazanır; aksi hâlde beraberlik sayılır.

> **Ders sonrası not:** Bir sunumda kritik değer 2.571, diğerinde 2.575 olarak söylendi. 5 serbestlik dereceli t dağılımında iki yönlü %95 kritik değer $t_{0.025,5} \approx 2.5706$'dır; 2.571 doğrudur. 2.575 büyük olasılıkla standart normal dağılımın %99 değeriyle (yaklaşık 2.576) karıştırılmıştır (python ile kontrol edildi).

> **Ek bilgi (derste anlatılmadı):** 5x2cv t-testi Dietterich'in 1998 tarihli çalışmasında önerilmiştir. Payda yalnız birinci iterasyonun birinci katındaki fark kullanılır; paydadaki varyans tahmini ise beş iterasyonun hepsinden gelir. Bu tasarım, aynı veriyi tekrar tekrar kullanmaktan doğan birinci tür hata şişmesini azaltmak içindir.

### 12.2 Win/loss matrisinin okunması

Bir öğrenci, t-testine göre ve ortalamaya göre iki ayrı win/loss matrisi gösterip bunların nasıl okunacağını sordu (ekrandan, 03:00:00). Sıra Bagging, Boosting, Random Forest idi ve 15 veri kümesi kullanılmıştı. Ağaç derinliği 10 için:

| | Bagging | Boosting | Random Forest |
|---|---|---|---|
| t-testine göre, Bagging | 0/0 | 0/7 | 2/8 |
| t-testine göre, Boosting | 7/0 | 0/0 | 3/6 |
| t-testine göre, Random Forest | 8/2 | 6/3 | 0/0 |
| ortalamaya göre, Bagging | 0/0 | 2/13 | 4/11 |
| ortalamaya göre, Boosting | 13/2 | 0/0 | 7/8 |
| ortalamaya göre, Random Forest | 11/4 | 8/7 | 0/0 |

Hocanın açıklaması şöyleydi:

- Ortalamaya göre matris, 5x2 çapraz doğrulamanın 10 sonucunun ortalamasına bakarak hangi algoritmanın hangisinden yüksek olduğunu sayar. Bu yüzden bir ikilinin kazanma ve kaybetme sayılarının toplamı veri kümesi sayısına (15) eşittir.
- t-testine göre matriste yalnız istatistiksel olarak anlamlı farklar sayılır, bu yüzden toplam 15'ten az olabilir.
- Köşegen, algoritmanın kendisiyle karşılaştırılmasıdır (0/0).
- Satırdaki algoritma sütundaki algoritmayı ilk sayı kadar yenmiş, ikinci sayı kadar ona yenilmiştir. Bagging Boosting'e karşı 0 kez kazanmış, 7 kez yenilmiştir. Bagging Random Forest'a karşı 2 kez kazanmış, 8 kez kaybetmiştir. Toplam 15 veri kümesi olduğuna göre kalan 5 veri kümesinde berabere kalmışlardır.
- Matris simetriktir: (satır, sütun) hücresindeki $a/b$, (sütun, satır) hücresinde $b/a$ olarak görünür.
- t-testi ve ortalama matrislerinin karşılaştırılması bilgi verir. Hoca, ekrandaki bir tabloda 2/8'in ortalamaya göre karşılığının 3/12 olduğunu söyledi ve bunu "aslında 3 kez yenmiş, ama bunların yalnız 2'si istatistiksel olarak anlamlı; 12 kez yenilmiş, yalnız 8'i anlamlı" diye yorumladı.
- Özet satırındaki eksi değerler kaybetme sayısının kazanma sayısından fazla olduğunu gösterir: net değer, kazanma sayısından kaybetme sayısı çıkarılarak bulunur.

<!-- BELİRSİZ: Hocanın sözlü örneğindeki 3/12 karşılığı, 03:00:00 karesindeki derinlik 10 tablosunda 4/11 olarak görünüyor; hoca büyük olasılıkla ekranda başka bir derinliğin tablosunu okuyordu. -->

### 12.3 Ödevlerden çıkan diğer gözlemler

- **Tekil ve topluluk başarısı:** Bütün sunumlarda topluluk başarısı, temel öğrenicilerin ortalama başarısından yüksek çıktı. Random Forest'ın tekil ağaçları en düşük başarılı ağaçlar oldu, çünkü her düğümde yalnız $\log_2$(özellik sayısı) kadar özelliğe bakılıyor ve önemli özellikler seçilmeyebiliyor. Bagging'in tekil ağaçları en başarılı, AdaBoost'unkiler arada oldu. Bu, kappa-hata diyagramındaki tabloyla uyumludur.
- **Tutarlılık kontrolü:** Bir sunumda ortalama tekil ağaç başarısı %30'larda, topluluk başarısı %70-80'lerde görünüyordu. Hoca, %30'luk öğrenicilerin birleşerek %80'lik bir sonuç oluşturamayacağını, bu satırda bir hata olduğunu söyledi. Başka bir sunumda dört farklı algoritma bütün veri kümelerinde virgülüne kadar aynı başarıyı veriyordu; hoca, tamamen farklı yapıdaki algoritmaların aynı sonuçları üretemeyeceğini ve kodda hata olduğunu vurguladı.
- **Tek veri kümesiyle genelleme:** Derinliğe bağlı analizleri tek bir veri kümesi üzerinde yapan bir öğrenciye hoca, bir veri kümesinden genelleme yapılamayacağını, 12 veri kümesinin bu yüzden verildiğini hatırlattı. Veri kümesinin adının raporda yazılması gerektiğini de ekledi.
- **Grafik ve tablo:** Derinlik arttıkça başarının zikzak çizdiği gibi gözlemler tablo yerine her veri kümesi için çizilen bir grafikle çok daha açık anlatılır.
- **AdaBoost'ta öğrenici sayısı:** Birkaç öğrenci, maksimum derinlik sonsuz olunca AdaBoost'un eğitim süresinin birden düştüğünü gördü. Bir öğrenci, öğrenici sayısını 100 verdiği hâlde derinlik artınca topluluğun tek öğreniciye düştüğünü buldu. Başka bir öğrenci derinlik 1'de de öğrenici sayısının 100'ün altında kaldığını gözledi. Hoca, öğrenici sayısının bir üst sınır olduğunu, algoritmanın daha önce bitebileceğini ve bunun anormal olmadığını söyledi; ama sonsuz derinlikte tek öğreniciye düşmeyi kütüphanede tuhaf bir durum olarak not etti.
- **Zikzaklı AdaBoost eğrileri:** Bir öğrenci AdaBoost başarısının derinliğe göre zikzak çizmesini derste anlatılan oylama sorununa (çift sayıda oy olduğunda beraberlik) bağladı. Hoca bunun sebebi olup olmadığından emin olmadığını söyledi.
- **Kararların benzerliğini ölçmek:** Öğrenciler kosinüs benzerliği (öğrenici sayısı × öğrenici sayısı boyutlu matrisin üst ya da alt üçgeninin ortalaması) ya da öğrenici kararları arasındaki uzaklığı kullandı. Bir sunumda uzaklık değerleri benzerlik gibi okunmuştu; hoca uzaklık büyüdükçe kararların daha farklı olduğunu hatırlattı. Bu düzeltmeyle Random Forest ağaçlarının kararları Bagging'inkilerden daha farklı çıktı. Hoca bunun beklenen sonuç olduğunu, çünkü Random Forest ağaçlarının hem daha büyük hem daha rastgele üretildiğini söyledi. Ayrıca iki sınıflandırıcının t-testindeki $p$ değerinin, tekil öğrenicilerin kararlarının benzerliği değil, iki sınıflandırıcının başarılarının farkı hakkında bilgi verdiğini belirtti.
- **Derinlik ve benzerlik:** Bir öğrenci beklentisinin tersine, derinlik arttıkça temel öğrenici kararlarının benzerliğinin arttığını gözledi (Bagging ve AdaBoost için 0.97-1.0, Random Forest için 0.80'den 0.92'ye) (ekrandan, 02:45:00). Başka bir öğrenci de belli bir derinlikten sonra başarının doygunluğa ulaştığını, derinleşen ağaçların kararlarının birbirine benzemeye başladığını ve bunun topluluğa daha az katkı anlamına geldiğini yorumladı.
- **MATLAB'da maksimum derinlik:** MATLAB'ın yeni `fitctree` sürümünde doğrudan bir maksimum derinlik parametresi bulunamadı. Öğrenciler derinliği bölme sayısını (MaxNumSplits) sınırlayarak ve oluşan derinlikleri yazdırıp kontrol ederek dolaylı olarak ayarladı. Hoca bu yolun düğüm sayısını sınırladığını, derinliği doğrudan sınırlamadığını söyledi ve budamanın (pruning) da bir seçenek olabileceğini ekledi.
- **Kolay ve zor veri kümeleri:** Mushroom verisinin Zero Rule değeri düşük olmasına rağmen çok kolay sınıflandığı gözlendi; bir öğrenci bunu özelliklerinin ikili (0/1) olmasına bağladı. Seçilen kümelerden biri çok zordu (en iyi başarı yaklaşık %28); hoca bunun normal olduğunu söyledi. Sağlık veri kümelerinin Zero Rule değerlerinin genelde 0.7'nin çok üstünde olduğu da not edildi. Bir veri kümesinde (splice) Random Forest yaklaşık %91, diğerleri %52 civarında kaldı; her veri kümesinde en iyi tek algoritma olmadığı tekrar görüldü.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $X$ verisi $N \times d$ boyutludur. Rotation Forest'ta $X' = X \cdot R$ döndürmesinin sonucunun boyutu nedir? $R$ hangi boyutta olmalıdır?

> **Çözüm:** $R$, $d \times d$ boyutlu olmalıdır. $(N \times d)(d \times d) = N \times d$; yani döndürülmüş veri de bütün örnekleri ve bütün özellikleri içerir, yalnız özellikler yeni bir uzaydadır.

**Soru 2** (derste sözlü, 00:27:00): Bir veriyi en az bozan dönüşüm matrisi hangisidir? Rotation Forest bu fikri nasıl kullanır?

> **Çözüm:** Birim matristir; birim matrisle çarpılan veri kendisini verir. Rotation Forest birim matrise benzeyen, sıfır olmayan değerleri köşegen yakınındaki bloklarda bulunan seyrek, blok köşegen bir matris kullanır. Böylece veri biraz döndürülür ama fazla bozulmaz.

**Soru 3** (derste sözlü, 00:21:43 ve 00:25:13): Rotation Forest'ta test örneği neden doğrudan tekil sınıflandırıcılara verilemez? Bu yüzden modelde ağaçların yanında ne saklanmalıdır?

> **Çözüm:** Her sınıflandırıcı $X R_t^a$ ile, yani farklı bir uzayda eğitilmiştir. Test örneği önce $\mathbf{x} R_t^a$ ile o sınıflandırıcının uzayına taşınmalıdır. Bu yüzden her ağacın rotasyon matrisi de modelde saklanmalıdır.

**Soru 4** (derste sözlü, 00:24:04): Rotation Forest'ta $X$ döndürülüyor; $Y$ neden döndürülmez?

> **Çözüm:** $Y$ sınıf etiketidir; noktanın rengi gibidir. Noktanın koordinatları değişince etiketi değişmez, bu yüzden $Y$'ye hiçbir dönüşüm uygulanmaz.

**Soru 5** (derste sözlü, 00:33:15): Bütün veri orijin etrafında 45 derece döndürülürse 1-NN'in ve bir karar ağacının sonuçları değişir mi?

> **Çözüm:** 1-NN'in sonuçları değişmez, çünkü döndürme noktalar arası uzaklıkları korur. Karar ağacının sonuçları ise çok değişir, çünkü ağaç eksenlere dik sınırlar çizer. Bu duyarlılık, Rotation Forest'ta küçük döndürmelerin bile yeterli çeşitlilik sağlamasının nedenidir.

**Soru 6** (derste sözlü, 00:37:56): 100 temel öğrenicili bir toplulukta kappa-hata diyagramı için kaç tane ağaç ikilisi vardır?

> **Çözüm:** Derste 5500 dendi. Doğrusu $\binom{100}{2} = 100 \cdot 99 / 2 = 4950$'dir (python ile kontrol edildi). Her ağacın kendisiyle eşleşmesi de sayılırsa $100 \cdot 101 / 2 = 5050$ olur, ama kendisiyle eşleşme bir ikili sayılmaz.

**Soru 7** (ekrandan, 00:40:00): Kappa-hata diyagramında ideal bölge neresidir? Vowel verisinde Bagging ve Random Forest bulutları nasıl yorumlanır?

> **Çözüm:** İdeal bölge sol alt köşedir: düşük hata ve düşük kappa, yani hem doğru hem birbirinden farklı ağaçlar. Bagging ağaçları en düşük hatalı ama kararları en benzer olanlardır (sağda). Random Forest ağaçları en farklı ama en hatalı olanlardır (solda ve yukarıda). Rotation Forest arada bir denge kurar ve topluluk doğruluğu en yüksek olandır (95.77).

**Soru 8** (ekrandan, 01:10:00; derste sözlü, 01:10:20): Dört sınıflı one-versus-all kod matrisinde öğrenicilerin çıkışı $(-1, -1, -1, +1)$ ise örnek hangi sınıfa atanır?

> **Çözüm:** Çıkış vektörü $W$'nin dördüncü satırıyla aynıdır; örnek 4. sınıfa atanır.

**Soru 9** (derste sözlü, 01:10:54): Aynı matriste çıkış $(+1, -1, +1, -1)$ olursa ne yapılır?

> **Çözüm:** Derste verilen kural: en çok benzeyen satıra atanır, eşit benzerlikte biri rastgele seçilir. Hamming uzaklıkları (farklı konum sayısı) şöyledir (ara adım eklendi, python ile kontrol edildi): 1. satır $(+1,-1,-1,-1)$ ile 1, 2. satır $(-1,+1,-1,-1)$ ile 3, 3. satır $(-1,-1,+1,-1)$ ile 1, 4. satır $(-1,-1,-1,+1)$ ile 3. 1. ve 3. sınıf eşit derecede benzediği için bu ikisinden biri rastgele seçilir.

**Soru 10** (derste sözlü, 01:11:44 ve 01:13:10): $K = 4$ sınıf için sınıf ikilileri ve tüm olası alt problemler (full code) yöntemlerinde kaç ikili problem oluşur?

> **Çözüm:** Sınıf ikilileri: $L = K(K-1)/2 = 4 \cdot 3/2 = 6$. Full code: $L = 2^{K-1} - 1 = 2^3 - 1 = 7$. One-versus-all için $L = K = 4$'tür.

**Soru 11** (ekrandan, 03:00:00): Derinlik 10 için t-testine göre win/loss matrisi (sıra Bagging, Boosting, Random Forest) şöyledir: Bagging satırı {0/0, 0/7, 2/8}, Boosting satırı {7/0, 0/0, 3/6}, Random Forest satırı {8/2, 6/3, 0/0}. 15 veri kümesi kullanıldığına göre Bagging ile Random Forest kaç veri kümesinde berabere kalmıştır? Her algoritmanın net win/loss değeri nedir?

> **Çözüm:** Bagging Random Forest'ı 2 kez yenmiş, 8 kez ona yenilmiş; $15 - 2 - 8 = 5$ veri kümesinde berabere kalmışlardır. Net değerler (kazanma − kaybetme): Bagging $(0+2) - (7+8) = -13$, Boosting $(7+3) - (0+6) = 4$, Random Forest $(8+6) - (2+3) = 9$. Bu değerler karedeki "Win/Loss Sayıları" satırıyla aynıdır (python ile kontrol edildi).

## Dersin Toparlaması

Bu derste çeşitliliği veriyi küçültmeden üreten iki yöntem görüldü. Rotation Forest bütün örnekleri ve özellikleri korur; özellik alt kümelerinde bootstrap ve PCA ile seyrek, blok köşegen bir rotasyon matrisi kurar ve her ağacı kendi döndürülmüş uzayında eğitir. Karar ağaçlarının döndürmeye duyarlılığı sayesinde küçük döndürmeler yeterli farklılığı sağlar. Kappa-hata diyagramları, Rotation Forest'ın Bagging'in doğru ama benzer ağaçlarıyla Random Forest'ın farklı ama zayıf ağaçları arasında bir denge kurduğunu deneysel olarak gösterdi. İyileştirilmiş Uzay Ormanları ise özellik sayısını artırır: rastgele özellik gruplarından doğrusal regresyonla üretilen yeni özellikler ağaçların eğik sınırlar çizmesine imkân verir ve diğer topluluk algoritmalarıyla birlikte kullanılabilir. Son olarak ECOC ile çok sınıflı bir problemin kod matrisi aracılığıyla iki sınıflı problemlere bölünmesi ve kod çözme ile sınıf kararı verilmesi anlatıldı.

Ödev sunumları, topluluk başarısının tekil öğrenicilerin ortalamasını aştığını, Random Forest'ın tekil ağaçlarının zayıf ama farklı olduğunu ve sonuçların akla yatkınlık kontrolünün önemini gösterdi. Sonraki derste kalan iki konuyla, uzman karışımı (Mixture of Experts) ve iki aşamalı öğrenme (Stacking) ile devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
