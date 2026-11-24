# Ders 12 Genişletilmiş Notu: Öğrenmeli Vektör Kuantalama, Kümeleme ve Regresyon Algoritmaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Nerede Kalmıştık: k-NN'in Güçlü ve Zayıf Yanları
- 2. Öğrenmeli Vektör Kuantalama (LVQ)
- 3. LVQ'da İlk Değerler, Ölü Vektörler ve Yerel Çözümler
- 4. LVQ'nun Karar Sınırları
- 5. Eğitim Kümesindeki Başarı Neyi İfade Etmez?
- 6. Çapraz Geçerleme ve Sınıflandırıcıların Karşılaştırılması
- 7. Model Karmaşıklığı ve Hata
- 8. Kümeleme Algoritmalarına Giriş
- 9. Hiyerarşik Kümeleme
- 10. K-means
- 11. Self-Organizing Map (SOM)
- 12. DBSCAN
- 13. Kümelemede Açık Sorular
- 14. Regresyon Algoritmaları
- Örnek Sorular

## 1. Nerede Kalmıştık: k-NN'in Güçlü ve Zayıf Yanları

Ders, makine öğrenmesi bölümünün sınıflandırma kısmından devam eder. Önceki derslerde özelliklerle yapılabilecekler (özellik seçimi/çıkarımı, temel bileşen analizi) ve birkaç sınıflandırma algoritması (karar ağaçları, yapay sinir ağları, en yakın k komşu) görülmüştür. Derse geçerken ekranda önceki konunun slaytı, Temel Bileşen Analizi açıktır (ekrandan, 00:05:00).

Hoca en yakın komşu (k-NN) algoritmasının özelliklerini hatırlatır. İyi tarafı, karar ağaçları ve yapay sinir ağları gibi çok esnek olmasıdır: her türlü eğitim kümesine uyum sağlayabilir. Kötü tarafı ise bir eğitim aşamasının olmamasıdır. Hocanın bakışıyla bir modelin işi aslında eğitim kümesini **sıkıştırmaktır**: sınıflandırma ya da regresyon kararını verebilecek şekilde eğitim kümesini bir modelin içine sığdırırsınız. k-NN bunu yapmaz; herhangi bir test örneğinin yerini belirlemek için eğitim kümesinin kendisi gerekir.

Az örnekli veri kümelerinde bu büyük bir sorun değildir, ama çok örnekli veri kümelerinde her test örneği için en yakın örneği bulmak pahalıdır: $n$ örnek ve $d$ boyut için kabaca $n \times d$'lik bir karşılaştırma yapılır. Bu işi hızlandırmak için KD ağaçları gibi veri yapıları vardır. Başka bir yol ise şu soruyu sormaktır: Eğitim örneklerinin hepsine gerçekten ihtiyacımız var mı? Bir kısmını seçsek ya da onları temsil eden yeni noktalar üretsek olmaz mı?

Slaytta bu fikir gösterilir (ekrandan, 00:10:00). Başlık "1NN'deki Tüm Noktaları kullanmasak?" şeklindedir; maddeler "Tüm noktalar yerine yeni/seçilmiş noktalar" ve "Bu noktalar nasıl belirlenebilir?" sorusudur. Grafikte iki sınıfın (yeşil çarpılar ve mavi yuvarlaklar) onlarca noktası ve bunların yerine kullanılan altı kırmızı temsilci nokta vardır: her sınıftan üçer tane. Bu temsilciler orijinal örneklerin aynısı değildir; mevcut örneklerden seçilmemişlerdir, ama genelde örneklere yakın yerlere düşerler.

## 2. Öğrenmeli Vektör Kuantalama (LVQ)

### 2.1 Fikir

Temsilci noktaları bulan algoritma Öğrenmeli Vektör Kuantalama'dır (Learning Vector Quantization, LVQ). Temsilciler bulunduktan sonra test süreci 1-NN gibidir: yeni bir test örneği geldiğinde bu kez yalnız temsilci noktalara bakılır ve en yakın temsilcinin sınıfı verilir. Örnek sayısı çok düştüğü için algoritma ciddi zaman kazandırır.

LVQ bir ödüllendirme ve cezalandırma sürecine dayanır. Bu açıdan K-means ve SOM algoritmalarına benzer. Hoca, LVQ'yu öneren kişinin SOM'u da öneren Kohonen olduğunu söyler; hangisinin önce geldiğinden emin olmadığını, büyük olasılıkla SOM'un önce geldiğini ekler.

### 2.2 Algoritma

Slayttaki tanımlar şöyledir (ekrandan, 00:15:00):

- $[\eta]$: öğrenme oranı
- $[n]$: en fazla eğitim sayısı (kaç epok dönüleceği gibi düşünülebilir)
- $[c]$: betimleyici vektör sayısı
- $[\mu_1, \dots, \mu_c]$: betimleyici vektörler (centroids)
- $[x]$: eğitim verisinden bir örnek
- $[S(x)]$: $x$ vektörünün ait olduğu ya da betimlediği sınıf

Adımlar:

```text
1.  eta, n, mu_1..mu_c için ilk değer atamalarını gerçekleştir
2.  Aşağıdaki işlemleri n defa tekrar et
2.1   x eğitim verisini al
2.2   x'e en yakın betimleyici vektörü bul:
        k <- argmin_j ||x - mu_j||,  j = 1..c
2.3   mu_k'nın güncellenmesi:
        Eğer x doğru sınıfsa (S(x) = S(mu_k) sınıfları aynı ise)
            mu_k <- mu_k + eta (x - mu_k)    ödüllendir, x'e yaklaştır
        değilse
            mu_k <- mu_k - eta (x - mu_k)    cezalandır, x'ten uzaklaştır
```

Öğrenme oranını ve en fazla eğitim sayısını kullanıcı seçer. Betimleyici vektörlerin ilk değerleri için de bir ilklendirme yapılır; hoca bunu yapay sinir ağlarında ilk ağırlıkların belirlenmesine benzetir.

$\arg\min$ ifadesini hoca şöyle okur: içerideki ifadeyi en küçük yapan $j$ indisini bul. Bulunan $k$ indisli $\mu_k$, o anki örneğe en yakın betimleyici vektördür.

### 2.3 Ödül ve ceza

Güncellemenin mantığı basittir. $x$'in sınıfı ile kazanan vektörün sınıfı aynıysa vektör "aferin, iyi yaptın" diye ödüllendirilir ve $x$'e yaklaştırılır. Sınıflar farklıysa vektör yanlış bir şey yapmıştır; $x$ bir daha geldiğinde aynı vektörün seçilmemesi için vektör $x$'ten uzaklaştırılır. Hoca slayttaki örnek çizimde, gri sınıftan bir örneğe en yakın çıkan siyah sınıflı bir vektörün itildiğini gösterir.

**Soru:** Uzaklaştırma miktarı öğrenme katsayısına mı bağlıdır? **Cevap:** Evet, ne kadar yaklaştırılıp uzaklaştırılacağını öğrenme oranı belirler. Yön ise sabittir: hareket, betimleyici vektörle $x$ örneğini birleştiren doğru üzerinde olur.

### 2.4 Vektörlere sınıf atanması

Algoritmada açıkça görünmese de başlangıçta her betimleyici vektörün hangi sınıfı temsil edeceği söylenmelidir. Önce vektörlere başlangıç değerleri verilir, sonra bunlara sınıflar atanır. Bu atama rastgele yapılabilir, ama eğitim kümesi elde olduğu için sınıf dağılımı bilinir ve vektörleri bu dağılıma uygun oranda dağıtmak makuldür.

Sınıflar dengesizse başka bir şey de yapılabilir. Örneğin bir sınıftan 100, öbüründen 10 örnek varsa her sınıfa 5 vektör verilebilir. Böylece eğitim kümesindeki sınıflar eşit oranlıymış gibi olur. Bunun her zaman işe yarayıp yaramayacağı ayrı bir konudur, ama sınıf dağılımını değiştirmek için LVQ bu şekilde kullanılabilir.

Özetle LVQ rastgele vektörlerle başlar ve zamanla bu vektörleri eğitim kümesinin temsilcilerine dönüştürür. Hoca algoritmanın basit ve kodlamasının keyifli olduğunu söyler.

## 3. LVQ'da İlk Değerler, Ölü Vektörler ve Yerel Çözümler

### 3.1 Ölü betimleyici vektör

Rastgele ilk atamanın bir sakıncası vardır (aynı durum K-means için de geçerlidir). Bazı betimleyici vektörler (centroid) verinin hiç bulunmadığı yerlere düşebilir. Bir vektörün güncellenebilmesi için bir örneğe diğer bütün vektörlerden daha yakın olması, yani seçilmesi gerekir. Herkesten uzak bir vektör hiçbir örnek için seçilmez, ne yaklaşır ne uzaklaşır, olduğu yerde kalır. Böyle bir vektör "ölü" bir betimleyici vektördür ve hiçbir işe yaramaz.

Bu sorunu çözmek için genelde vektörlerin ilk değerleri mevcut eğitim örneklerinden seçilir. Böylece hiç hareket etmeme olasılığı azalır. Bir vektör aynı sınıftan bir örnekle başlatılırsa o örnek için en yakın vektör kendisi olur ve fark sıfır olduğundan o örnek için güncelleme olmaz; ama başka örnekler için güncelleme gelir ve vektör sonraki adımlarda o noktadan ayrılır.

### 3.2 Tahtada bir örnek

Hoca slayta iki sınıflı küçük bir veri kümesi çizer (ekrandan, 00:25:00): bir yanda kırmızı noktalar, bir yanda yeşil noktalar ve iki yıldız. Yıldızlardan biri kırmızı sınıfı, biri yeşil sınıfı temsil eder ve başlangıçta rastgele yerlere konmuştur.

Örnekler teker teker gelir. Gelen örneğe en yakın yıldız başka sınıftansa, yıldız örnekle kendisini birleştiren doğru boyunca itilir. Hoca birkaç örnek için bunu adım adım gösterir: yıldız her seferinde gelen örnekten uzağa itilir ve giderek veri kümesinin öbür tarafına doğru gider. Belli bir noktadan sonra o yıldız kendi sınıfının noktalarına en yakın vektör olmaya başlar; bu kez noktalar onu kendine çeker ve yıldız kabaca kendi sınıfının ortalamasına yerleşir. Sınıf başına iki vektör konursa her biri sınıfın bir bölümüne oturur.

### 3.3 Yerel çözüme takılma

Bu her zaman mükemmel bir sonuca ulaşacak mı? Hayır. Algoritmanın küresel bir çözüm garantisi yoktur ve sonuç veri kümesine bağlıdır. Hoca şu durumu çizer: iki yeşil vektör ve bir kırmızı vektör aynı taraftan başlamıştır. Bir yeşil vektörün öbür taraftaki yeşil noktalara ulaşması için bir bölgeyi aşması gerekir. Ancak bu bölgede hem kendi tarafındaki noktalar onu kendine çeker hem de öbür sınıfın noktaları onu iter. Bu iki gücü aşıp geçmek hiç kolay değildir; böyle bir başlangıçta vektör büyük olasılıkla takılıp kalır.

## 4. LVQ'nun Karar Sınırları

Slayttaki soru şudur: "LVQ ne zaman lineer (doğrusal) karar sınırı üretir?" (derste sözlü, 00:27:50).

Hoca önce iki merkezli durumu ele alır. İki betimleyici vektör varsa ve yeni test örnekleri bunlara yakınlığa göre sınıflandırılıyorsa nasıl bir sınır çıkar? Bir öğrencinin cevabı: ortalarından, onları birleştiren doğruya 90 derece dik bir çizgi. Hoca doğrular: sınır iki merkezi birleştiren doğrunun tam ortasından geçen dik doğrudur. Bir yanındaki noktalar yeşil, öbür yanındakiler kırmızı sınıfa atanır, çünkü sınıflandırma "hangi merkeze daha yakınsa onun sınıfı" kuralıyla yapılır. Dolayısıyla **iki merkez varsa karar sınırı kesinlikle doğrusaldır**; merkezlerin yeri değişse de sınır yine bir doğru olur.

Sonra üç merkezli bir durum sorulur (ekrandan, 00:35:00): iki kırmızı yıldız (biri yukarıda, biri aşağıda) ve sağda bir yeşil yıldız. Bir öğrenci her kırmızı-yeşil çifti için ayrı bir dik doğru oluşacağını söyler. Hoca bunu Voronoi bölgeleriyle açıklar: her merkezin kendisine daha yakın noktalardan oluşan bir bölgesi vardır. Yeşil merkeze en yakın noktalar yeşil sınıfa, iki kırmızı merkezden birine daha yakın olanlar kırmızı sınıfa atanır. Ekranda bu sınır, iki doğru parçasından oluşan kırık bir çizgidir; yani sınır parçalı doğrusaldır.

Aynı durum 1-NN için de geçerlidir. Hoca 1-NN ile LVQ'nun test süreçlerinin aynı olduğunu vurgular; fark birinin eğitim kümesinin tamamını, öbürünün yalnız temsilcileri kullanmasıdır.

### 4.1 LVQ'nun esnekliği

Doğrusal bir sınırla iyi ayrılabilen bir veri kümesinde LVQ da yapay sinir ağı da çalışır. İç içe geçmiş bir veri kümesinde ise doğrusal sınıflandırma mümkün değildir, daha esnek algoritmalar gerekir. LVQ, 1-NN kadar esnek değildir: eğitim örneklerinin hepsini almadığı için eğitim kümesindeki başarısı %100 değildir. Betimleyici vektör sayısı örnek sayısına yaklaştıkça uzay daha iyi temsil edilir ve eğitim başarısı %100'e yaklaşır (gereksiz temsiller de girebilir). Ama asıl ilgilendiğimiz şey eğitim kümesindeki değil, test kümesindeki performanstır.

## 5. Eğitim Kümesindeki Başarı Neyi İfade Etmez?

Hoca bunu bir hikaye ile anlatır (ekrandan, 00:40:00 ve 00:45:00). 1024 kişi seçilir ve e-posta adresleri alınır. Sayının önemi vardır: $1024 = 2^{10}$.

Slayttaki akış şöyledir:

```text
1. gün: 1024 kişi
    512'sine: yarın X hisse senedi yükselecek
    512'sine: yarın X hisse senedi düşecek
2. gün: 512 kişi
    256'sına: yarın X hisse senedi yükselecek
    256'sına: yarın X hisse senedi düşecek
3. gün: 256 kişi
    128'ine: yarın X hisse senedi yükselecek
    128'ine: yarın X hisse senedi düşecek
...
10. gün: 1 kişi
```

Her gün tahmini tutan yarı ile devam edilir; tutmayan yarı bırakılır. Örneğin ilk gün hisse düşerse "yükselecek" denen 512 kişi gider, "düşecek" denen 512 kişi kalır. Onuncu günde elde bir kişi kalır.

**Soru:** Bu bir kişinin özelliği nedir? **Cevap:** Ona on gün boyunca önceden söylenen her şey gerçekleşmiştir. Bu yüzden size güvenecektir.

**Soru:** Peki güvenmeli mi? Yarın için tahminin tutma olasılığı nedir? **Cevap:** %50. Dışarıdan bakan için güvenmek için hiçbir sebep yoktur; içeriden bakan ise on gün boyunca dediği çıkan birini görür. Daha fazla kişiyle başlanırsa daha uzun süreli "başarı" serileri elde edilebilir. Hoca bunun bir üçkağıtçılık tekniği olduğunu, sayılarla oynamayı bilenlerin böyle şeyler yapabileceğini söyler.

Makine öğrenmesi açısından ders şudur: bu tahminleyicinin o tek kişi üzerindeki "eğitim kümesi" başarısı %100'dür, ama 11. gün için para verecek biri açısından bu hiçbir şey ifade etmez, çünkü tahminler tamamen rastgeledir ve yalnız tesadüfen tutmuştur. Eğitim kümesindeki başarıya bakarak test kümesindeki başarı hakkında bir şey söylenmemelidir. Eğitim ve test başarılarının uyumlu olması iyi ve beklenen bir şeydir, ama tek başına eğitim başarısı bir kanıt değildir.

> **Hocanın vurgusu:** Bütün makine öğrenmesi algoritmalarının, hatta bütün modelleme yaklaşımlarının temel varsayımı, geleceğin geçmişten çok farklı olmayacağıdır. Model eğitim kümesinden kurulur ve test kümesinde çalıştırılır; test örnekleri eğitim örneklerinden çok farklıysa modelin bir şey yapma şansı yoktur.

Bu yüzden hiç görülmemiş bir örüntünün gelecekte oluşmasını tahmin etmek mümkün değildir. Geçmişte görülen anomalilere benzeyen anomaliler gelecekte yakalanabilir, ama hiç görülmemiş, farklı nedenlerden doğan bir olayı önceden görmek pek mümkün değildir.

## 6. Çapraz Geçerleme ve Sınıflandırıcıların Karşılaştırılması

### 6.1 Çapraz geçerleme

Aradan sonra hoca daha önce değinilen çapraz geçerlemeyi hatırlatır (ekrandan, 01:00:00). Slayt başlığı "Hata nasıl ölçülür? Çapraz Geçerleme"dir:

- Tüm veri kümesini eşit boyutlu $N$ gruba böl.
- Bir grubu test için, geri kalanların hepsini eğitim için kullan.
- $N$ defa tekrar et.

Slayttaki çizimde beş grup vardır ve her turda farklı bir grup (kırmızı) test grubudur. Beş katlı çapraz geçerlemede her turda verinin %20'si test, %80'i eğitim olur ve beş sınıflandırma sonucu elde edilir. Bunların ortalaması alınabilir; ya da her örnek tam bir kez test edildiği için doğrudan bütün veri kümesi üzerindeki başarıya bakılabilir. Bu tahmin, tek bir eğitim-test ayrımına göre daha güvenilirdir.

### 6.2 Neden bu kadar çok algoritma var?

Slayt "Sınıflandırma Metotları - Sonuç" başlığını ve "Neden bu kadar çok algoritma var?", "Ne zaman hangisini seçeceğiz?" sorularını taşır. Altında altı veri kümesi ve beş algoritmanın 5 katlı çapraz geçerleme başarıları (%) vardır (ekrandan, 01:20:00):

| dataset | amlall | ann | bi75ds3 | derma | gkanser | Hava |
|---|---|---|---|---|---|---|
| Özellik sayısı | 7129 | 21 | 470 | 34 | 30 | 34 |
| Sınıf sayısı | 2 | 3 | 9 | 6 | 2 | 2 |
| Örnek sayısı | 72 | 3772 | 315 | 286 | 456 | 281 |
| NB | **97,14** | 95,55 | 68,49 | 77,97 | 94,29 | 89,31 |
| SVM | 92,86 | 93,74 | 62,11 | **79,37** | **96,26** | 86,48 |
| 1NN | 94,29 | 93,4 | 63,19 | 76,26 | **96,26** | 89,72 |
| C45 | 83,39 | **99,58** | 65,01 | 75,2 | 93,62 | 91,82 |
| RF | 95,71 | 99,5 | **72** | 76,96 | 95,38 | **95,02** |

Kalın değerler o sütundaki en başarılı algoritmayı gösterir. Örneğin amlall'da Naive Bayes, ann'de C4.5 karar ağacı, bi75ds3'te Random Forest, derma'da SVM en iyisidir.

**Soru:** Bu tablo bize ne söylüyor? **Cevap (bir öğrenci):** Her algoritma veri kümesine, özellik, sınıf ve örnek sayısına göre farklı başarı gösteriyor; bu yüzden çok sayıda algoritma var. **Hoca:** Bütün veri kümelerinde diğerlerinin hepsinden iyi olan bir algoritma yoktur; bu yüzden bu kadar çok algoritma hâlâ yaşamaktadır. Her veri kümesinde diğerlerini geçen bir algoritma olsaydı "bunu kullanalım, diğerlerini hiç düşünmeyelim" denirdi.

Bunun böyle olması doğaldır. Bir algoritmanın bir veri kümesinde başarılı olması için verinin geldiği dağılımla algoritmanın varsaydığı modelin uyumlu olması gerekir. Verilerin gelebileceği dağılımlar sonsuz çeşitlidir; sonsuz farklı şeye uyum sağlayan tek bir model bulunamaz. Hangi algoritmanın seçileceği bir deneme-yanılma sürecidir. Bu yüzden makine öğrenmesi algoritmaları genelde kütüphaneler halinde sunulur: farklı algoritmalar aynı veri üzerinde denenir ve sonuçlar karşılaştırılır.

> **Ek bilgi (derste anlatılmadı):** Bu gözlem literatürde "No Free Lunch" (bedava öğle yemeği yok) teoremi olarak bilinir: bütün olası problemler üzerinden ortalama alındığında hiçbir öğrenme algoritması diğerlerinden üstün değildir.

## 7. Model Karmaşıklığı ve Hata

Slayttaki metin şöyledir (ekrandan, 01:05:00): "Modelin karmaşıklığı arttığında eğitim kümesindeki hata sürekli düşerken, test kümesindeki hata bir noktadan sonra yükselir. Her veri kümesi için optimum nokta (optimum karmaşıklık) farklıdır." Grafikte yatay eksen model karmaşıklığı, dikey eksen hatadır; mavi eğri eğitim hatası (training error), yeşil eğri test hatasıdır. Yanda aynı iki sınıflı veriye uydurulmuş üç sınır vardır: bir doğru, yumuşak bir eğri ve her noktayı dolanan çok kıvrımlı bir eğri. Altta "İki karşıt özellik: Aşırı eğitme - ezberleme (overfitting), Genelleştirebilme" yazar.

Model ne kadar çok parametre içerirse eğitim kümesindeki hata o kadar düşer. Her türlü veri kümesine uyum sağlayabilen tamamen esnek bir modelde eğitim hatası sıfıra iner. Test hatası ise bir yere kadar düşer, sonra artmaya başlar. Bu yapı doğrusal regresyonun parametrik halleri, k-NN ve karar ağaçları gibi algoritmaların hepsinde geçerlidir.

Hoca bu grafiğin yapay sinir ağları için tam doğru olmadığını, bunun 90'lardan beri bilindiğini söyler. Yapay sinir ağlarında test hatası bazen düşer, yükselir, sonra yeniden düşmeye başlar (double descent gibi yapılar). Bunun nedenine dair çeşitli fikirler vardır ama hiçbiri tam tatmin edici değildir. Az veriyle yapay sinir ağları da grafiğe uyar; hem model karmaşıklığı hem veri miktarı birlikte arttığında uymaz. Eğitim hatasının karmaşıklıkla düştüğü kısım (mavi eğri) ise yapay sinir ağları dahil bütün algoritmalar için geçerlidir.

## 8. Kümeleme Algoritmalarına Giriş

### 8.1 Kümeleme nedir?

Sınıflandırmadan sonra kümeleme algoritmalarına geçilir. Kümeleme algoritmaları eğiticisizdir; sınıf bilgisi yoktur. Veriyi temsil eden merkezleri bulmaya çalışırlar (LVQ'daki betimleyici vektörler gibi) ve sonra örnekleri en yakın küme merkezine göre kümelere ayırırlar. Farklı değer sayısını azalttıkları için sıkıştırma algoritmalarının çoğunun temelinde yer alırlar; yapılan iş bir kuantalama (quantization) işlemidir.

### 8.2 Tek boyutlu örnek

Slayttaki örnek (ekrandan, 01:10:00):

- Bir boyutlu (özellikli) 10 örnek içeren bir veri: `12-15-13-87-4-5-9-67-1-2`
- Bu 10 farklı veriyi 3 farklı veriyle temsil etmek istersek: `12-12-12-77-3-3-3-77-3-3` şeklinde ifade edebiliriz.
- Kümeleme algoritmaları bu 3 farklı verinin değerlerini bulmakta kullanılır.
- Gerçek değerlerle temsil edilen değerler arasındaki farkları en aza indirmeye çalışırlar.
- Bu örnekte 3 küme oluşmuştur: 12-15-13 örnekleri 1. kümede, 87-67 örnekleri 2. kümede, 4-5-1-2-9 örnekleri 3. kümede.

Kümelemenin kayıp (loss) fonksiyonu, bir örneğin değeriyle o örneğin dahil olduğu küme merkezinin değeri arasındaki farktır ve amaç bu farkı küçültmektir. 12, 15 ve 13 için 12; 87 ve 67 için 77; diğerleri için 3 kullanılmıştır. Başka değerler de kullanılabilirdi ama o kadar iyi olmayabilirdi.

> **Ek bilgi (derste anlatılmadı):** Kare hatayı en aza indiren temsilci, kümenin ortalamasıdır. Bu örnekte ortalamalar büyük olasılıkla şöyle olur: $\{12, 15, 13\} \to 13{,}33$, $\{87, 67\} \to 77$, $\{4, 5, 9, 1, 2\} \to 4{,}2$. Slayttaki 12 ve 3 değerleriyle kare hata toplamı 256, ortalamalarla yaklaşık 243,5'tir (python ile hesaplandı).

### 8.3 Uygulamalar

Renk kümeleme: Daha önce konuşulan renk kümelemede bir resim adım adım 256, 128, 64, 32, 16, 8, 4 ve en sonunda 2 renge indirilir.

Blok kümeleme: Pikseller yerine bloklar da kümelenebilir. Resim 10×10 piksellik bloklara ayrılır. 200×200'lük bir resimde $(200/10)^2 = 400$ blok olur. Bu 400 blok 40 temsilci bloğa indirgenir ve her blok, kendi küme merkezinin değeriyle değiştirilir. Sonuçta geçişler yumuşak olmaz; düşük bağlantıyla video izlerken görülen kareli görüntüler buna benzer.

İletişimde vektör kuantalama: En yaygın kullanım iletişimdir. Elde bir $x$ vektörü (örneğin 10×10'luk bir blok), bir kodlayıcı (encoder, sunucu tarafı) ve bir kod çözücü (decoder, istemci tarafı) vardır. Sunucuda kümeleme algoritmasıyla oluşturulmuş bir tablo (küme merkezleri) bulunur. $x$ geldiğinde ona en yakın küme merkezi bulunur ve karşıya merkezin kendisi değil yalnız indisi $i$ gönderilir. Kod çözücüde aynı tablo vardır; $i$'ye karşılık gelen $m_i$ kullanıcının ekranına konur, yani $x$ yerine $\hat{x}$ oluşur. Güzel tarafı, gönderilen şeyin $m_i$'nin büyüklüğünden bağımsız olarak yalnız bir indis olmasıdır.

**Soru:** İndisin az yer tutması için ne gerekir? **Cevap:** Küme sayısının az olması. **Soru:** Küme merkezi sayısı azalırsa görüntü bozulur mu, iyileşir mi? **Cevap:** Bozulur; çok daha kaba görüntüler elde edilir (256 kümeli ve 2 kümeli resimler arasındaki fark gibi).

## 9. Hiyerarşik Kümeleme

### 9.1 İki tür

Slaytta hiyerarşik kümelemenin iki türü verilir (ekrandan, 01:15:00):

- Tek kümeden çok kümeye (bölmeli)
- Çok kümeden tek kümeye (eklemeli)

Slayttaki ağaç çizimi a, b, c, d, e, f noktalarından başlar: önce b ile c birleşip bc, d ile e birleşip de olur; de ile f birleşip def olur; bc ile def birleşip bcdef olur; en sonunda a ile birleşerek abcdef oluşur.

### 9.2 Eklemeli hiyerarşik kümeleme

Algoritma çok basittir: başlangıçta küme sayısı örnek sayısına eşittir, yani her örnek bir küme merkezi gibi düşünülür. Birbirine en benzer iki küme birleştirilir ve bu tekrar edilir. Tekrarlandıkça kümeler büyür; bir noktada iki küme kalır, bir adım daha ilerlenirse hepsi tek bir kümeye dönüşür.

Derste gösterilen örnekte önce birbirine çok benzeyen D3 ile D7, sonra D4 ile D5, sonra D6 ile D8 birleştirilir. Bunlar hep nokta-nokta birleşmeleridir. Bir sonraki adımda {D3, D7} kümesi ile {D4, D5} kümesi birleştirilir. <!-- BELİRSİZ: Bu örnek slaytın karesi yok; D numaraları ve birleşme sırası altyazıdan alındı. -->

### 9.3 İki kümenin benzerliği

Bu noktada bir soru çıkar: iki kümenin benzerliği nasıl ölçülür? İki nokta için herhangi bir benzerlik ya da uzaklık ölçüsü (Öklid, Manhattan, kosinüs uzaklığı vb.) kullanılabilir. Ama örneğin D2'nin {D3, D7} kümesine benzerliği nasıl ölçülür? Üç temel yaklaşım vardır:

- **Single link:** İki küme, en benzer elemanları kadar benzerdir. D2-D3 ve D2-D7 uzaklıklarının en küçüğü alınır.
- **Complete link:** İki küme, en az benzer elemanları kadar benzerdir. Bu uzaklıkların en büyüğü alınır.
- **Group average:** Uzaklıkların ortalaması alınır.

İki kümede de birden fazla örnek varsa (örneğin {D4, D5} ile {D3, D7}) bütün çapraz çiftlerin (D4-D3, D4-D7, D5-D3, D5-D7) uzaklıkları hesaplanır ve en küçüğü, en büyüğü ya da ortalaması alınır.

Süreç adım adım ilerlediği için her adımdaki küme sayısı bilinir. İstenen yerde durulup "beş küme istiyorum" ya da "üç küme istiyorum" denebilir.

### 9.4 Bölmeli hiyerarşik kümeleme

Her şey tek bir kümeymiş gibi başlanır. Kümenin içinde birbirine en az benzeyen iki eleman bulunur ve küme bu iki elemana göre bölünür (her eleman hangisine yakınsa onun tarafına gider). Oluşan her küme için bu işlem tekrarlanır. Genelde aşağıdan yukarıya (eklemeli) yaklaşım daha çok kullanılır.

### 9.5 Algoritmaların kümelenmesi

Slayttaki dendrogramın başlığı "Algoritmaların başarılarına göre kümelenmesi"dir (ekrandan, 01:15:00). Hoca bunu önceki tablo üzerinden açıklar: tablodaki her algoritma, her boyutu bir veri kümesindeki başarı olan altı boyutlu bir uzayda bir nokta gibi düşünülebilir. Dendrogramda yirmiden fazla algoritmanın otuz kadar veri kümesi üzerindeki sonuçları kümelenmiştir. Aynı veri kümelerinde benzer sonuç veren algoritmalar birbirine yakın düşer. Sonuçta SVM, SMO, Partial Least Squares gibi doğrusal algoritmalar bir kümede, ensemble algoritmaları başka bir kümede, k-NN türevleri başka bir yerde toplanır. Algoritmaların model ve varsayım benzerlikleri bu kümelemeye yansır.

## 10. K-means

### 10.1 Algoritma

K-means'in adımları (derste sözlü, 01:22:33):

```text
Sayısal verilerle çalışır
1) Rastgele K adet küme merkezi ata
2) Her örneği en yakındaki merkezin kümesine ata
3) Merkezleri kendi kümelerinin merkezine ata
4) 2. ve 3. adımları küme değiştirme kalmayana
   ya da en fazla iterasyona erişilene kadar tekrar et
```

LVQ'dan farklı olarak burada merkezlerin sınıfları yoktur, çünkü kümelemede sınıf bilgisi yoktur.

### 10.2 Adım adım K-means

Slaytta altı iterasyon gösterilir (ekrandan, 01:25:00). Başta üç merkez (artı işaretleri) rastgele konmuştur ve üst bölgeye yakındır. İlk adımda her nokta en yakın merkezin rengini alır (yeşil, mavi, kırmızı). Sonra her merkez kendi renkli noktalarının ortalamasına taşınır ve atama yeniden yapılır. İterasyonlar ilerledikçe iki merkez yavaş yavaş aşağıdaki küçük kümelere iner; altıncı iterasyonda üç merkez üç doğal kümenin (üstte büyük kırmızı küme, altta sol yeşil ve sağ mavi küme) ortasındadır. Rastgele başlansa bile güzel bir sonuca ulaşılabildiği görülür.

### 10.3 İlk değerlerin önemi

Bu süreç de yerel minimumlara takılabilir. Hoca bir sonraki slaytta ("İlk değerlerin önemi") farklı ilk değerlerle başlayan bir çalışma gösterir: merkezler adım adım ilerler ama sonunda biri iki kümenin arasında kalır ve kümesindeki örneklerin hepsine uzaktır. Hoca yine de K-means'in iyi bir algoritma olduğunu rahatlıkla söyleyebileceğini ekler.

### 10.4 Kümelemeler nasıl karşılaştırılır?

**Soru:** Bir kümelemenin diğerinden daha iyi ya da kötü olduğu nasıl söylenir? Sınıflandırmadaki gibi "olması gereken şu" diye bir doğru cevap elimizde yok. **Cevap:** Kümelemenin kayıp fonksiyonuna bakılır: küme merkezinin temsil ettiği noktalara uzaklıklarının küçük olması istenir. Kötü başlangıçlı örnekte üstteki kümeler iyi görünür, ama alttaki küme merkezi kendi örneklerinin ortalamasında olsa bile hepsine epey uzaktır; hata fonksiyonu bunu gösterir.

> **Hocanın vurgusu:** İki kümeleme ancak küme sayıları aynıysa bu hataya göre karşılaştırılabilir. $K$ arttıkça kayıp fonksiyonu kesinlikle düşer; küme sayıları farklıysa karşılaştırma anlamsız olur.

> **Ek bilgi (derste anlatılmadı):** K-means'in hata fonksiyonu genelde küme içi kare uzaklıkların toplamı olarak yazılır: $\text{Cost}(C) = \sum_{i=1}^{K} \sum_{x \in C_i} \lVert x - c_i \rVert^2$. Burada $c_i$, $i$. kümenin merkezidir.

### 10.5 Toplu ve tekli K-means

Şimdiye kadar anlatılan toplu (batch) K-means'tir: önce bütün örnekler en yakın merkeze atanır, sonra merkezler güncellenir; merkez, kümesindeki bütün örneklerin ortalamasına konur.

Tekli (online) K-means'te ise her örnek için güncelleme yapılır. Bir örnek gelir, ona en yakın küme merkezi bulunur ve bu merkez belli bir öğrenme oranıyla örneğe doğru yaklaştırılır; aynen LVQ'nun ödül kısmı gibi. Cezalandırma yoktur, çünkü cezalandırılacak bir sınıf hatası yoktur. Online çalıştırılan süreç de toplu hale çok benzeyen, tatmin edici sonuçlar verir.

Hoca bu algoritmaların kodlamasının çok kolay olduğunu, öğrencilerin kendileri kodlayıp vektörlerin nasıl hareket ettiğini, kötü durumların nasıl oluştuğunu, online sürümün daha hızlı olup olmadığını birinci elden görmelerini önerir.

## 11. Self-Organizing Map (SOM)

SOM, online K-means'e yeni bir yapı eklenmesiyle oluşur. Yine bir örneğe en yakın küme merkezi bulunur ve örneğe yaklaştırılır. Fark şudur: küme merkezleri belirlendikten sonra aralarında önceden tanımlı bir bağlılık, bir komşuluk yapısı kurulur. Bu komşuluk tek boyutlu (bir halka ya da doğru üzerinde) ya da iki boyutlu (bir ızgara) olabilir. Hangi merkezin hangisiyle komşu olduğu başta indislerle atanır.

Bir örnek geldiğinde kazanan merkezle birlikte ona bağlı komşu merkezler de örneğe doğru yaklaştırılır. Yani her örnekte tek bir merkez değil, kazanan merkez ve komşuları güncellenir.

Hoca bunu bir animasyonla gösterir (ekrandan, 01:35:00): üç boyutlu, halka biçimli bir veri bulutunun üzerinde kırmızı merkezler mavi çizgilerle ızgara biçiminde birbirine bağlıdır. Başta rastgele noktalardan başlayan ızgara, zamanla açılarak verinin şeklini alır ve sonunda artık değişmez. Komşuluk tek boyutlu olursa (halka topolojisi) işler daha basit olur.

SOM'u asıl güzel yapan şey şudur: veri yüz boyutlu olsa bile ızgara iki boyutludur. Kümeleme bittikten sonra iki boyutlu ızgaraya bakarak yüz boyutlu verinin iki boyutta aşağı yukarı nasıl göründüğüne, kimin kime yakın kimin kime uzak olduğuna dair bir öngörü elde edilir. Bu yüzden SOM yalnız kümelemede değil, yüksek boyutlu uzayların görselleştirilmesinde de kullanılır.

## 12. DBSCAN

### 12.1 Merkez tabanlı ve yoğunluk tabanlı kümeleme

Kümeleme konusunun son algoritması DBSCAN'dır ve şimdiye kadarkilerden farklıdır. Hoca iki veri kümesini karşılaştırır: K-means'e "üç küme bul" denirse her noktayı en yakın merkeze bağlar ve merkez tabanlı kümeler çıkar. DBSCAN ise aynı veride bambaşka, yoğunluk zincirlerini izleyen kümeler bulur. Kullanım amaçları farklıdır: yoğunluk tabanlı kümeleme isteniyorsa DBSCAN, merkez tabanlı kümeleme isteniyorsa K-means gibi algoritmalar kullanılır.

### 12.2 Algoritma

Slayttaki maddeler (ekrandan, 01:40:00):

- Yoğunluk tabanlı kümeleme
- Hiperparametreleri: $eps$, $min\_p$
- Önce tüm noktaları çekirdek, sınır, gürültü olarak belirle
- Çekirdek (kırmızı): $eps$ komşuluğunda en az $min\_p$ adet nokta bulunan noktalar
- Gürültü (mavi): $eps$ komşuluğunda hiç nokta bulunmayan noktalar
- Sınır (sarı): $eps$ komşuluğunda $min\_p$'den az nokta bulunan noktalar

Şekilde her noktanın etrafında yarıçapı $eps$ olan bir daire vardır. Kırmızı noktaların dairelerinin içinde başka noktalar vardır, bu yüzden çekirdektirler. Hoca bu şekilde $min\_p$'nin büyük olasılıkla 2 olduğunu tahmin eder. Sarı B ve C noktalarının komşuluğunda yalnız bir nokta vardır, bu yüzden sınır noktasıdırlar. Mavi N noktasının komşuluğunda hiç nokta yoktur, bu yüzden gürültüdür. Bu etiketler alışılmış sınıflar değildir; yoğunluğu ifade ederler: çok yoğun bir bölgenin içindeki nokta, yoğun bir bölgenin sınırındaki nokta ve seyrek bir bölgedeki nokta.

Etiketlemeden sonra:

- Gürültüler elenir.
- Birbirine $eps$ mesafede olan çekirdekler birleştirilir (aralarında birçok çekirdek olabilir).
- Hiperparametrelere bağlı sayıda küme oluşur.
- Sınır noktaları en yakın çekirdeğin kümesine atanır.

Algoritma karmaşık değildir. Çok uzakta tek başına duran bir nokta hiçbir kümeye bağlanamaz, gürültü olarak dışarı atılır. Dolayısıyla DBSCAN'da bir örnek bir kümeye girmek zorunda değildir. Burada küme "merkezi" tek bir nokta değil, birçok çekirdek noktadan oluşan bir yapıdır.

## 13. Kümelemede Açık Sorular

Slayt "Kümeleme algoritmalarında" başlığıyla şu soruları sıralar (ekrandan, 01:45:00): Ne zaman dururuz? Ölü nöron kavramı (SOM, K-means). Başarı ölçütü nedir? Küme sayısı nasıl belirlenir? (Mecburiyet (verilmiştir), ?)

Ne zaman durulacağına kolay cevap verilemez. Bir yol, bir önceki iterasyonda bir kümede olup sonraki iterasyonda başka kümeye geçen örnek kalmayana kadar devam etmektir. Ama bazı noktalar iki küme merkezinin tam ortasına düşer ve bir o tarafa bir bu tarafa gidip gelir; bunun bitmesini beklemek çok uzun sürebilir. Bu yüzden genelde bir en fazla iterasyon sayısı da kullanılır.

Ölü nöron kavramı, LVQ'da anlatılan ölü vektörle aynıdır: hiç kazanamadığı için hiç güncellenmeyen merkez.

Başarı ölçütü olarak önceki bölümdeki hata fonksiyonu kullanılır. Bunun dışında literatürde kümeleme başarısını karşılaştırmak için çeşitli indeksler tanımlanmıştır. <!-- BELİRSİZ: Altyazıda "deviz bağlı indeks", "Siret", "Witt" geçiyor; büyük olasılıkla Davies-Bouldin indeksi ve Silhouette gibi geçerlilik ölçütleri kastediliyor, üçüncüsü anlaşılamadı. --> Ama sınıflandırmadaki gibi kesin bir doğru cevap yoktur.

**Soru:** Kümeleme sonuçları sınıflandırma sonuçlarıyla test edilebilir mi? **Cevap:** Evet; sınıfları bilinen bir veri kümelenir (örneğin 3 sınıf varsa 3 küme istenir) ve aynı sınıftakilerin aynı kümeye düşüp düşmediğine bakılır. Ama kümeleme ile sınıflandırmanın amaçları farklıdır. Hoca basit bir örnek verir: sınıflar merkez tabanlı bir yapıya uymuyorsa K-means sınıflarla hiç uyumlu bir sonuç vermez; sınıflar uygun biçimdeyse uyumlu bir sonuç çıkar.

## 14. Regresyon Algoritmaları

Regresyonda çıkış bir sayıdır. Derste üç regresyon yaklaşımı görülür: basit doğrusal regresyon, k-NN ile regresyon ve regresyon ağaçları.

### 14.1 Basit doğrusal regresyon

Slayttaki tanım (ekrandan, 01:50:00):

- $X$: girişler ($n \times d$)
- $Y$: çıkışlar ($n \times 1$)
- Model: $Y = XW$
- $W$: katsayılar
- Amaç $W$'yi bulmak

Hoca bunu birkaç noktaya bir doğru oturtmak olarak çizer; doğruyu $W$ temsil eder. Türetme şöyledir:

1. Her iki tarafı $X^{-1}$ ile çarpalım: $X^{-1}Y = X^{-1}XW$, buradan $W = X^{-1}Y$. Ama bir matrisin tersi alınabilmesi için kare matris olması gerekir. $X$'in satırları örnekler, sütunları özelliklerdir ve kare olmak zorunda değildir (örneğin 50 örnek, 250 özellik).
2. Bu yüzden her iki taraf önce $X^T$ ile çarpılır: $X^TY = X^TXW$. $X^TX$ her zaman kare matristir.
3. Her iki taraf $(X^TX)^{-1}$ ile çarpılır: $(X^TX)^{-1}(X^TY) = (X^TX)^{-1}(X^TX)W$ ve $(X^TX)^{-1}(X^TX) = I$.
4. Sonuç: $W = (X^TX)^{-1}(X^TY)$.

Bu, iterasyonsuz, sabit sayıda işlemle bulunan analitik çözümdür. Alternatif olarak perceptron gibi rastgele bir $W$'den başlayıp gradyanla adım adım ilerleyen iteratif bir süreç de kullanılabilir. (Formülün rastgele bir $X$ ve bilinen bir $W$ ile doğru katsayıları geri verdiği python ile denendi.)

> **Ek bilgi (derste anlatılmadı):** $X^TX$ kare olsa da her zaman tersinir değildir. Özellik sayısı örnek sayısından fazlaysa (50 örnek, 250 özellik gibi) $X^TX$ tekildir; pratikte sözde ters (pseudo-inverse) ya da ridge regresyonundaki gibi $X^TX + \lambda I$ kullanılır.

### 14.2 k-NN ile regresyon

k-NN, sınıflandırmada olduğu gibi regresyonda da kolayca kullanılır. Hoca tek boyutlu bir örnek çizer: x ekseninde kabaca 1, 2, 4 ve 6 civarında dört eğitim örneği (siyah noktalar) vardır, her birinin bir çıkış değeri vardır.

$k = 1$ için: bir test örneği geldiğinde x uzayında ona en yakın eğitim örneği bulunur ve onun çıkışı verilir. 1 ile 2'nin orta noktasına kadar ilk örneğin çıkışı, oradan 2 ile 4'ün ortasına kadar ikinci örneğin çıkışı, 4 ile 6'nın ortasından (5 civarı) sonra son örneğin çıkışı verilir. En soldaki ve en sağdaki değerler sonsuza kadar devam eder. Sonuç, örnekler arasındaki orta noktalarda aniden sıçrayan basamaklı bir fonksiyondur.

$k > 1$ için: sınıflandırmada en yakın $k$ örneğin en çok görülen sınıfı verilirken, regresyonda en yakın $k$ eğitim örneğinin çıkışlarının ortalaması verilir. Dört örnekli bu durumda $k = 4$ seçilirse her test örneği için dört örneğin hepsinin ortalaması alınır ve model sabit bir doğru olur.

> **Ders sonrası not:** Hoca çıkış değerlerini 7, 6, 9 ve 3 diye okuyup ortalamanın "5 küsur" yazıldığını söyler. Bu dört değerin ortalaması $25/4 = 6{,}25$'tir. Slaydın karesi olmadığı için değerler doğrulanamadı; büyük olasılıkla ya değerlerden biri ya da ortalama yanlış duyulmuştur. <!-- BELİRSİZ: k-NN regresyon slaytındaki çıkış değerleri ve ortalama karede okunamadı. -->

### 14.3 Regresyon ağaçları

Karar ağaçlarıyla sınıflandırma yapılmıştı; aynı yapı regresyonda da kullanılabilir. Slaytın başlığı "Regresyon ağaçlarında kabul edilen hata değerinin etkisi"dir (ekrandan, 01:55:00; kaynak olarak Ethem Alpaydın'ın kitabı belirtilmiştir). Sağdaki ilk ağaç şöyledir:

```text
x < 3.16 ?
  Evet -> x < 1.36 ?
            Evet -> 1.37
            Hayır -> -1.35
  Hayır -> 1.86
```

Sınıflandırma ağaçlarında yapraklarda "bu bölgeye düşerse sınıfı A'dır" denirdi; regresyon ağacında ise yaprakta bir sayı vardır: o bölgeye düşen eğitim örneklerinin çıkışlarının ortalaması. Artık bölünmeyecek bir düğümde çıktı olarak bu ortalama verilir.

#### Hangi bölme daha iyi?

Ağaç kurulurken, sınıflandırmadaki gibi farklı yerlerden bölmenin iyiliği karşılaştırılır. Hoca slayttaki ilk grafiğin sol parçasını (kırmızı noktaları) ele alır (ekrandan, 02:00:00). Bu noktalar birçok yerden bölünebilir. Örneğin sağdaki tek noktayı ayıran bir yerden bölünürse solda dört nokta kalır ve çıktı onların ortalamasıdır (yeşil yatay çizgi); sağda tek nokta vardır ve çıktı noktanın kendisidir. Başka bir yerden bölmek başka bir model (mavi) verir.

**Soru:** Mavi model mi yeşil model mi daha iyi, bunu nasıl ölçeriz? **Cevap:** Bir öğrenci uzaklıkların karelerini önerir. Hoca bunu ortalamadan uzaklıkların karelerine bağlar ve bu büyüklüğün adını sorar: standart sapma. Her iki taraftaki model o taraftaki örneklerin ortalamasıdır; örneklerin standart sapması onların bu ortalamadan ne kadar saptığını gösterir. Bir bölmenin hatası, sol taraftaki örneklerin çıkışlarının standart sapması ile sağ taraftakilerin standart sapmasının toplamıdır. Nereden bölmenin iyi olduğu buna göre seçilir.

#### Kabul edilen hata değerinin etkisi

Saflık kriteri burada kabul edilebilir standart sapmayla ilgilidir. Slayttaki üç grafik $\theta_r = 0{,}5$, $0{,}2$ ve $0{,}05$ için çizilmiştir. $\theta_r$ küçüldükçe fonksiyon noktalara daha çok yaklaşır ve ağaç büyür: $\theta_r = 0{,}2$ ağacında $x < 5.96$ ve $x < 6.91$ gibi yeni bölmeler ve 2.20, 0.9, 2.40 gibi yapraklar eklenir; $\theta_r = 0{,}05$ ağacında ise $x < 0.76$ ve $x < 6.31$ bölmeleriyle 1.15, 1.80, 1.20, 0.60 gibi yapraklar da gelir. Kabul edilen standart sapma sıfır yapılırsa model bütün noktaların tam üzerinden geçer ve ağaç kocaman olur. Daha toleranslı davranılırsa daha küçük ağaçlar elde edilir.

## Örnek Sorular

### Soru 1

(derste sözlü, 00:21:45; ekrandan, 00:25:00) İki sınıflı bir veri kümesinde her sınıf için birer betimleyici vektör rastgele yerlere konmuştur. LVQ örnekleri teker teker işlerken vektörler nasıl hareket eder ve sonunda nereye yerleşir?

> **Çözüm (derste verildi):** Gelen örneğe en yakın vektör başka sınıftansa, örnekle vektörü birleştiren doğru boyunca örnekten uzağa itilir; aynı sınıftansa örneğe yaklaştırılır. İtilen vektör bir noktadan sonra kendi sınıfının noktalarına en yakın vektör olur, bu noktalar onu çeker ve vektör kabaca kendi sınıfının ortalamasına yerleşir. Kötü bir başlangıçta (iki vektör aynı tarafta) çekme ve itme güçleri yüzünden bir vektör takılıp kalabilir.

### Soru 2

(derste sözlü, 00:27:50; ekrandan, 00:35:00) LVQ ne zaman doğrusal karar sınırı üretir? Üç merkezli bir durumda (iki kırmızı, bir yeşil) sınır nasıl olur?

> **Çözüm (derste verildi):** İki merkez varsa sınır, iki merkezi birleştiren doğrunun orta dikmesidir, yani doğrusaldır. Daha fazla merkezde her merkezin Voronoi bölgesi oluşur; yeşil merkezin bölgesi ile iki kırmızı merkezin bölgeleri arasındaki sınır, her kırmızı-yeşil çifti için bir dik doğru parçasından oluşan parçalı doğrusal bir sınırdır (ekrandan, 00:35:00).

### Soru 3

(ekrandan, 00:40:00 ve 00:45:00) 1024 kişiye e-posta atılıyor; her gün yarısına "X hisse senedi yarın yükselecek", yarısına "düşecek" deniyor ve tahmini tutanlarla devam ediliyor. 10. günde kalan kişinin özelliği nedir? Bu kişi 11. gün için verilecek tahmine güvenmeli midir?

> **Çözüm (derste verildi):** $1024 = 2^{10}$ olduğu için her gün yarıya inen grup 10. günde tek kişi olur. Bu kişiye on gün boyunca söylenen her tahmin tutmuştur, bu yüzden güvenecektir. Ama tahminler rastgeledir ve 11. gün için tutma olasılığı %50'dir. Eğitim kümesindeki %100 başarı test başarısı hakkında bir şey söylemez.

### Soru 4

(ekrandan, 01:20:00) Altı veri kümesinde NB, SVM, 1NN, C4.5 ve RF'nin başarılarını veren tabloyu nasıl yorumlarsınız? Neden bu kadar çok algoritma var, ne zaman hangisini seçeceğiz?

> **Çözüm (derste verildi):** Her veri kümesinde başka bir algoritma en iyidir (amlall'da NB, ann'de C4.5, bi75ds3'te RF, derma'da SVM, gkanser'de SVM ve 1NN, Hava'da RF). Bütün veri kümelerinde en iyi olan tek bir algoritma yoktur, çünkü başarı verinin dağılımıyla algoritmanın modelinin uyumuna bağlıdır. Seçim deneme-yanılma ile yapılır; bu yüzden algoritmalar kütüphaneler halinde sunulur.

### Soru 5

(derste sözlü, 01:13:43) Vektör kuantalamayla iletişimde gönderilen indisin az yer tutması için ne gerekir? Küme merkezi sayısı azalırsa görüntü bozulur mu, iyileşir mi?

> **Çözüm (derste verildi):** Küme sayısının az olması gerekir. Küme sayısı azaldıkça görüntü bozulur, daha kaba görüntüler elde edilir.

### Soru 6

(derste sözlü, 01:25:59) İki kümelemeden hangisinin daha iyi olduğunu nasıl söyleriz?

> **Çözüm (derste verildi):** Örneklerin kendi küme merkezlerine uzaklıklarına dayanan hata (kayıp) fonksiyonu hesaplanır; küçük olan daha iyidir. Bu karşılaştırma yalnız küme sayıları eşitse anlamlıdır, çünkü $K$ arttıkça hata hep düşer.

### Soru 7

(ekrandan, 02:00:00; derste sözlü, 01:58:16) Bir regresyon ağacında aynı noktaları iki farklı yerden bölen iki model (yeşil ve mavi) var. Hangisinin daha iyi olduğunu nasıl ölçeriz?

> **Çözüm (derste verildi):** Her iki tarafta model, o taraftaki örneklerin çıkışlarının ortalamasıdır. Bölmenin hatası, sol taraftaki çıkışların standart sapması ile sağ taraftaki çıkışların standart sapmasının toplamıdır. Bu toplamı küçük olan bölme daha iyidir.

## Dersin Toparlaması

Ders, k-NN'in eğitim kümesinin tamamını saklama sorununa LVQ ile bir çözüm getirerek başladı: az sayıda betimleyici vektör, aynı sınıftan örneklere yaklaştırılıp farklı sınıftan örneklerden uzaklaştırılarak eğitim kümesinin temsilcilerine dönüştürülür. İlk değerlerin ölü vektörlere ve yerel çözümlere yol açabileceği, karar sınırlarının iki merkezde doğrusal, çok merkezde parçalı doğrusal (Voronoi) olduğu görüldü. 1024 e-posta hikayesiyle eğitim başarısının test başarısının ölçüsü olmadığı, çapraz geçerleme ve sınıflandırıcı karşılaştırma tablosuyla da tek bir en iyi algoritma olmadığı ve model karmaşıklığı arttıkça test hatasının bir noktadan sonra yükseldiği vurgulandı.

Ardından eğiticisiz öğrenmeye geçildi: kümeleme bir kuantalama/sıkıştırma işlemi olarak tanıtıldı; hiyerarşik kümeleme (single, complete, group average), toplu ve tekli K-means, merkezler arası komşuluk ekleyen SOM ve yoğunluk tabanlı DBSCAN anlatıldı. Son olarak regresyon algoritmalarına girildi: doğrusal regresyonun analitik çözümü $W = (X^TX)^{-1}X^TY$, k-NN ile regresyon ve bölme hatası standart sapmayla ölçülen regresyon ağaçları. Hoca makine öğrenmesi slaytlarında birkaç slaytın kaldığını ve bunların sonraki derste konuşulacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
