# Ders 11 Genişletilmiş Notu: k En Yakın Komşu, LVQ, Kümeleme ve Regresyon Algoritmaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten Bağlantı ve Parametre/Hiperparametre Ayrımı
- 2. En Yakın k Komşu (k-NN)
- 3. Öğrenmeli Vektör Kuantalama (LVQ)
- 4. k-NN ve LVQ'nun Karar Sınırları
- 5. Eğitim Başarısı Neyi Gösterir: Borsa Tahmini Hikayesi
- 6. Çapraz Geçerleme
- 7. Sınıflandırma Yöntemlerinin Karşılaştırılması
- 8. Model Karmaşıklığı, Aşırı Eğitme ve Genelleştirme
- 9. Kümeleme Algoritmalarına Giriş
- 10. Hiyerarşik Kümeleme
- 11. K-means
- 12. Kendi Kendini Düzenleyen Haritalar (SOM)
- 13. DBSCAN: Yoğunluk Tabanlı Kümeleme
- 14. Regresyon Algoritmaları: Basit Doğrusal Regresyon
- 15. k-NN ile Regresyon
- 16. Regresyon Ağaçları
- 17. Çok Boyutlu Verilerle Çalışmak
- 18. Veri Sızıntısı (Data Leakage)
- 19. Weka ile Uygulama
- Örnek Sorular

## 1. Önceki Dersten Bağlantı ve Parametre/Hiperparametre Ayrımı

Ders, makine öğrenmesi bölümünün devamıdır. Önceki derste sınıflandırma yöntemlerinden doğrusal regresyon, karar ağaçları ve yapay sinir ağları görülmüştü. Yapay sinir ağlarının TensorFlow Playground (playground.tensorflow.org) uygulamasıyla oldukça karmaşık karar sınırları üretebildiği gösterilmişti (ekrandan, 00:10:00). Bu ders en yakın k komşu algoritmasıyla başlar, sonra kümeleme ve regresyon algoritmalarına geçer, en sonda Weka aracıyla uygulama yapılır.

### 1.1 Hiperparametre

k-NN'deki $k$ bir hiperparametredir. Hiperparametre, algoritmanın çalışmak için ihtiyaç duyduğu ama kendisinin bulamadığı değerdir. Kullanıcının algoritmaya söylemesi gerekir; algoritmanın girdisidir. Yapay sinir ağında kaç katman olacağı, her katmanda kaç nöron olacağı ve aktivasyon fonksiyonlarının ne olacağı da hiperparametredir.

### 1.2 Parametre

Klasik anlamda parametre, algoritmanın eğitim sürecinde veriden kendisinin öğrendiği değerlerdir. Rastgele bir yerden başlatılır ve giderek iyileştirilir. Örnekler:

- Doğrusal sınıflandırıcıdaki $w_0, w_1, w_2$ katsayıları (iki boyutta bu üçü yeterlidir).
- Karar ağacında hangi özelliğin hangi değerinden bölüneceği, yani ağacın yapısı.
- Yapay sinir ağının ağırlıkları (weight).

Hoca doğrusal modelin nasıl iyileştirildiğini tahtada canlandırdı. Çizginin üstünde kalanlara mavi, altında kalanlara gri diyen bir model düşünelim. Eğitim örnekleri birer birer gelir. Gelen gri bir örnek çizginin üstündeyse model ona mavi der; yanlış sınıflandırma olduğu için $w_0, w_1, w_2$ güncellenir, çizgi bu örneği de doğru sınıflandıracak yöne kaydırılır. Sonra gelen mavi bir örnek gri tarafta kalıyorsa çizgi yine kaydırılır. Bu adım adım sürer; daha iyi bir şey yapılamayacak noktaya gelince algoritma durur. Bundan sonra test örneklerinin sınıfını bulmak için yalnız bu model (çizgi) yeterlidir.

Parametreler, modelin eğitim kümesindeki tahminleriyle örneklerin gerçek sınıfları arasındaki uyuma göre güncellenir.

## 2. En Yakın k Komşu (k-NN)

### 2.1 Fikir

En yakın k komşu algoritması bir atasözünün uygulamasıdır: "Bana arkadaşını söyle, sana kim olduğunu söyleyeyim." Bu algoritmada eğitim süreci yoktur. Elimizde bir eğitim kümesi vardır; bir test örneği geldiğinde eğitim örnekleri içinden ona en yakın $k$ tanesi seçilir, bunların sınıflarına bakılır.

- $k=1$ ise en yakın tek komşunun sınıfı (örneğin A) test örneğine verilir.
- $k=3$ ise en yakın üç komşu B, B ve A sınıfındansa çoğunluk B olduğu için test örneğine B denir.

### 2.2 $k$ değerinin etkisi

$k$ küçüldükçe algoritma yerel değişimlerden ve gürültüden daha çok etkilenir. $k$ büyüdükçe karar daha geniş bir çevreye bakılarak verilir.

**Soru (hoca):** $N$ eğitim kümesindeki örnek sayısı olmak üzere $k=N$ seçilirse ne olur?

**Cevap:** Bir öğrenci "hep aynı tahmini yapar" dedi; hangi tahmin olduğu sorulunca "en çok hangi sınıftan veri varsa onu" dedi. Hoca bunu onayladı: Bu, daha önce görülen ve yalnız sınıf bilgisine bakarak (özelliklere bakmadan) çoğunluk sınıfını söyleyen "Zero Rule" yaklaşımıdır. $k=N$ olduğunda k-NN mantıklı tahmin etmeye (Zero Rule'a) dönüşür.

### 2.3 k-NN'in dezavantajı

Yöntemi anlatmak da kodlamak da çok basittir. Sorun test aşamasındadır.

**Soru (hoca):** Bir test örneğini sınıflandırmak için neye ihtiyacımız var?

**Cevap:** O örneğe en yakın $k$ komşuyu bulmak gerekir; bunun için de eğitim kümesinin tamamı gerekir. Test örneği eğitim kümesinin birinci, ikinci, üçüncü ... bütün örnekleriyle karşılaştırılır, en yakınlar bulunur.

Bu, daha önce görülen bütün algoritmalardan ayrılan bir özelliktir:

- Yapay sinir ağında eğitim bittikten sonra test için örneğin özellikleri ve modelin kendisi (mimari, ağırlıklar) gerekir; eğitim kümesine bir daha ihtiyaç yoktur. Eğitim kümesinin bir modeli çıkarılmış ve ağın içine gömülmüştür.
- Karar ağacında yalnız modele (hangi düğümde hangi özelliğe göre bölündüğüne) ihtiyaç vardır.
- Doğrusal regresyonda yalnız çizginin katsayıları yeterlidir.

k-NN'de ise bir model çıkarılmadığı için büyük miktarda veri tutulmalı ve her test için bütün eğitim kümesi taranmalıdır; test süresi uzundur.

### 2.4 1-NN'deki bütün noktaları kullanmasak?

Bu sorunu aşmak için şu öneri yapılmıştır: Eğitim kümesinin tamamını tutmak yerine bazı noktalar belirleyip yalnız onlarla çalışmak. Slayttaki şekilde (ekrandan, 00:35:00) iki sınıflı (yeşil çarpılar ve mavi yuvarlaklar) dört kümeli bir veri ve bunlar arasında kırmızıyla işaretlenmiş 6 nokta vardır. Bu kırmızı noktalar eğitim örneklerinden seçilmiş değil, sonradan "belirlenmiş" noktalardır.

**Soru (hoca):** Her grupta 20'şer örnek varsa toplam 120 örnek yerine yalnız bu 6 kırmızı noktayı tutsak 1-NN yine iş görür mü?

**Cevap:** Bir öğrenci iş görebileceğini söyledi; hoca onayladı. Soru, bu kırmızı noktaların nasıl bulunacağıdır. Bunun için geliştirilmiş algoritma Öğrenmeli Vektör Kuantalamadır.

## 3. Öğrenmeli Vektör Kuantalama (LVQ)

### 3.1 Genel yapı

İngilizcesi Learning Vector Quantization (LVQ) olan algoritmanın Türkçe adı biraz zorlamadır. Kuantalama, seviyeler oluşturmak anlamına gelir; burada bu seviyeler öğrenilerek bulunur. Algoritma Kohonen'e aittir; Kohonen ileride görülecek SOM (Self-Organizing Map) kümeleme algoritmasını da bulmuştur.

Doğrusal regresyonda çizgi rastgele bir yerden başlatılıp iteratif olarak iyileştiriliyordu. LVQ'da da kırmızı noktalar (prototipler, centroidler) rastgele başlatılır ve adım adım iyileştirilir. Şekildeki kırmızıların hepsi aynı değildir: kimi yuvarlak, kimi çarpıdır; yani prototiplerin de sınıfı vardır. Her prototipin bir örnek gibi koordinatı ve bir sınıfı vardır.

Başlatma şöyle yapılabilir:

- Sınıflar eğitim verisindeki sınıf dağılımına uygun atanır; koordinatlar eğitim kümesinden rastgele seçilen örneklerden alınabilir.
- Ya da koordinatlar uzayın aralığında düzgün (uniform) dağılımla tamamen rastgele atanabilir.

Prototipler farklı yerlerde başlar, sonra iteratif olarak iyileştirilir. Prototip sayısını kullanıcı söyler (şekilde 6); bu da bir hiperparametredir.

### 3.2 Algoritma (ekrandan, 00:25:00)

Slayttaki tanımlar:

- $[\eta]$: öğrenme oranı
- $[n]$: en fazla eğitim sayısı
- $[c]$: betimleyici vektör sayısı
- $[\mu_1,\dots,\mu_c]$: betimleyici vektörler (centroidler)
- $[x]$: eğitim verisinden bir örnek
- $[S(x)]$: $x$ vektörünün ait olduğu ya da betimlediği sınıf

```text
1.  η, n, μ1,...,μc için ilk değer atamalarını gerçekleştir
2.  Aşağıdaki işlemleri n defa tekrar et
2.1   x eğitim datasını al
2.2   x'e en yakın betimleyici vektörü bul
        (μk): k <- argmin_j ||x - μj||,  j = 1..c
2.3   μk'nın güncellenmesi:
        Eğer x doğru sınıfsa (s(x) = s(μk), sınıfları aynı ise)
            μk <- μk + η(x - μk)    ödüllendir, x'e yaklaştır
        değilse
            μk <- μk - η(x - μk)    cezalandır, x'den uzaklaştır
```

$n$, en fazla tur (epok) sayısı ya da toplam güncelleme sayısı gibi düşünülebilir.

### 3.3 argmin ne demek?

**Soru (hoca):** argmin ne demek?

**Cevap:** Bir öğrenci "minimum elemanın bulunduğu indeksi döndürür" dedi. Hoca "neyin minimumu?" diye sordu ve açıkladı: $\arg\min_j$ ifadesinde $j$, 1'den $c$'ye kadar değer alır. İçerideki fonksiyonu en küçük yapan $j$ değeri bulunur. Fonksiyon $\lVert x-\mu_j \rVert$, yani $x$ ile $j$. prototip arasındaki uzaklıktır. Dolayısıyla bulunan $k$, $x$'e en yakın betimleyici vektörün indisidir.

### 3.4 Ödül ve ceza

Hoca tahtada şunu çizdi: Prototiplerin hepsi başlangıçta küçük bir karenin içinde olsun; eğitim örnekleri (yeşiller ve maviler) etrafa dağılmış olsun. Bir yeşil örnek seçilir; ona en yakın prototip bulunur. Algoritma ödül-ceza mekanizmasıyla çalışır:

- Örneğin sınıfı ile kazanan prototipin sınıfı aynıysa (ikisi de yeşil) ödül olarak prototip örneğe doğru, ikisini birleştiren doğru üzerinde yaklaştırılır.
- Sınıflar farklıysa (kazanan mavi, örnek yeşil) bu prototipin bir dahaki sefere kazanması istenmez; prototip aynı doğru üzerinde örnekten uzağa itilir. Böylece bir sonraki adımda belki doğru sınıftan başka bir prototip kazanır ve o örneğe yaklaştırılır.

Ne kadar yaklaştırılacağını öğrenme oranı belirler: $\mu_k \leftarrow \mu_k + \eta(x-\mu_k)$. $x$ ile $\mu_k$ arasındaki fark alınır, $\eta$ ile çarpılır ve $\mu_k$'ya eklenir.

**Soru (hoca):** $\eta=1$ olsa ne olur?

**Cevap:** Bir öğrenci "doğrudan $x$'in konumuna gider" dedi; doğrudur. $\eta=0.5$ için bir öğrenci "tam ortada kalır" dedi; prototip ikisinin tam ortasına gelir. $\eta=0.1$ daha az, $\eta=0.9$ çok daha fazla yaklaştırır.

Sayısal olarak (ara adım eklendi): $\mu_k=(0,0)$, $x=(2,2)$ için $\eta=1$ → $(2,2)$; $\eta=0.5$ → $(1,1)$; $\eta=0.1$ → $(0.2,0.2)$; $\eta=0.9$ → $(1.8,1.8)$.

Slayttaki ikinci şekilde (hocanın anlatımına göre) iki siyah ve iki gri prototip vardır. Bir $x$ geldiğinde en yakın prototip aynı sınıftansa $x$'e yaklaştırılır; başka bir durumda $x$ gri, kazanan farklı sınıftansa uzaklaştırılır ki bir sonraki adımda kazanamasın.

### 3.5 Prototipler neden grupların ortasına yerleşir?

Rastgele başlatılan prototipler ödül-ceza mekanizmasıyla gerçek gruplara doğru itilir ve bir yerden sonra oturur. Bir grubun ortasındaki prototipi düşünelim: Etrafındaki bütün örnekler için kazanan odur ve her biri onu kendine doğru çeker. Bu çekişler sonucunda prototip dinamik olarak grubun kabaca ortasına yerleşir. Ortalamayı ayrıca hesaplayıp prototipi oraya taşımak gerekmez; kendiliğinden konumlanır.

### 3.6 LVQ ne işe yarar?

k-NN'de binlerce örnek olabilir. LVQ bunları kullanıcının istediği sayıda prototipe indirger. Sonra yalnız bu prototiplerle k-NN çalıştırılır. Bütün eğitim kümesine gerek kalmaz, işlem çok daha hızlıdır.

> **Hocanın vurgusu:** LVQ da bir tepe tırmanma (yerel arama) sürecidir. Yapay sinir ağları, doğrusal regresyonun iteratif sürümü gibi bütün iteratif algoritmalar mevcut konumu durmadan güncellemeye çalışır ve yerel bir noktaya takılabilir. Bu yüzden algoritmayı bir kez çalıştırmak iyi değildir; birden fazla kez çalıştırıp olası varyasyonları görmek gerekir.

## 4. k-NN ve LVQ'nun Karar Sınırları

**Soru (hoca):** LVQ (ya da 1-NN) ne zaman doğrusal bir karar sınırı üretir, yani bölgeyi tek bir çizgiyle ikiye ayırır?

**Cevap:** Bir öğrenci "örnekler iki farklı yerde kümelendiyse" dedi. Hoca çizerek açıkladı: İki sınıf ve iki prototip (1-NN'de iki örnek) varsa sınır doğrusaldır. Bu sınır, iki noktayı birleştiren doğruya ortasından dik olan doğrudur. Bir taraftaki her yere bir sınıf, diğer tarafa öbür sınıf denir.

Üç prototip olursa sınır tek bir doğru olmaz. Hoca önce bir doğru çizdi, sonra bazı bölgelerin hâlâ yeşile daha yakın olduğunu fark ederek düzeltti: Her iki prototip çifti için orta dikme çizilir; üçüne de eşit uzaklıkta bir nokta vardır. Bir bölgeye yeşil, diğer iki bölgeye mavi denir. 1-NN'de üç örnek olması ile LVQ'da üç prototip olması aynı sonucu verir.

Nokta sayısı arttıkça karar sınırları daha karmaşık hale gelir. 1-NN en karmaşık karar sınırlarını üretebilen algoritmadır; yapay sinir ağlarından bile daha karmaşık sınırlar üretebilir. $k$ arttırıldıkça daha yumuşak (smooth) karar sınırları elde edilir.

> **Ek bilgi (derste anlatılmadı):** 1-NN'in karar sınırı, eğitim noktalarının Voronoi diyagramının farklı sınıftan komşu hücreleri ayıran kenarlarından oluşur. İki nokta için Voronoi kenarı tam olarak orta dikmedir; derste çizilen üç nokta durumu da bu yapının küçük bir örneğidir.

## 5. Eğitim Başarısı Neyi Gösterir: Borsa Tahmini Hikayesi

Slaytın başlığı "Eğitim kümesi üzerindeki performans neyi ifade eder?"tir; maddeleri "Borsa oynayan maymunlar" ve "1000 kişiye hisse senedi tahminleri göndermek"tir; kaynak olarak "Hatasız Düşünme Sanatı" kitabı gösterilmiştir (ekrandan, 00:40:00).

Hoca bunu bir "üç kağıtçılık" hikayesiyle anlattı. Erişebildiğiniz (örneğin e-posta ile) 1024 kişi seçilir:

1. 1024 kişi 512'şerlik iki gruba ayrılır. Birinci gruba "yarın dolar çıkacak", ikinci gruba "yarın dolar düşecek" denir.
2. Ertesi gün dolar düşmüşse yalnız "düşecek" denen 512 kişi tutulur ve 256'şar kişilik iki gruba bölünür; birine "çıkacak", ötekine "düşecek" denir.
3. Bu her gün tekrarlanır. $1024 = 2^{10}$ olduğu için yaklaşık 10 gün sonra bir kişi kalır.

Son kalan kişi, 10 gün boyunca doların ne yapacağını bir gün önceden hep doğru tahmin eden birini görmüştür. Bu kişi, ertesi günün tahminini öğrenmek için epey para vermeye razı olabilir. Oysa bunun için dolardan ya da piyasadan anlamaya gerek yoktur. Hikaye, geçmişteki başarının (eğitim verisindeki başarının) tek başına güvenilir bir ölçü olmadığını gösterir.

## 6. Çapraz Geçerleme

Bir algoritmanın bir veri kümesi üzerindeki performansını ölçmek için veri kümesi eşit boyutlu $N$ gruba bölünür. Bir grup test için ayrılır, geri kalanların hepsi eğitim için kullanılır. Bu her grup için tekrarlanır; sonuçta $N$ test sonucu elde edilir, bunların ortalaması sistemin performansıdır.

Amaç, her örneğin test kümesinde en az bir kez bulunmasıdır. Bazı örnekler çok kolay, bazıları çok zor olabilir. Tek bir eğitim ve tek bir test kümesi kullanmak yerine çapraz geçerleme yapmak daha güvenilir sonuç verir. Bu, eğitim süreci çok uzun sürmüyorsa uygulanabilir; eğitim çok uzunsa $N$ kez eğitmek zordur.

## 7. Sınıflandırma Yöntemlerinin Karşılaştırılması

### 7.1 Farklı yöntemlerin karar sınırları

Slaytta (ekrandan, 01:00:00) daha önce görülen somon/levrek (salmon/sea bass) veri kümesi vardır: özellikler parlaklık (lightness) ve genişlik (width), iki sınıf. Aynı veri farklı modellere verildiğinde her biri farklı bir karar sınırı üretir. Kaynak: Duda, Hart ve Stork, *Pattern Classification* (2. baskı).

- Düz çizgi şeklindeki sınır doğrusal regresyonla üretilmiştir.
- Çok kıvrımlı, bütün eğitim örneklerini doğru sınıflandıran sınır 1-NN türü bir yöntemle üretilmiş olabilir.

**Soru (hoca):** 1-NN'in eğitim kümesi üzerindeki performansı yüzde kaçtır?

**Cevap:** %100'dür. Eğitim örneklerinden biri test edilmek istendiğinde ona en yakın eğitim örneği kendisidir; dolayısıyla kendi sınıfını söyler. İstisna, tam aynı noktada farklı sınıflardan birden fazla örnek bulunmasıdır. 1-NN eğitim kümesini tam olarak ezberler.

Üçüncü sınır biraz daha yumuşaktır. Veri kümesinde gürültüler vardır; 1-NN gürültülere karşı dayanıklı değildir ve genel eğilimi yansıtamaz. Bu veri için daha düzgün bir sınır daha makul görünür.

### 7.2 Neden bu kadar çok algoritma var?

Slaytta 6 veri kümesi ve 5 sınıflandırıcı algoritmanın yer aldığı bir tablo vardır. Her veri kümesinin sınıf sayısı, örnek sayısı ve özellik sayısı yazılıdır; her algoritmanın her veri kümesindeki başarısı verilmiştir. Kalın yazılanlar o veri kümesindeki en iyi sonuçlardır (hoca 97, 99, 72, 79 gibi değerler okudu; bir veri kümesinde iki algoritma aynı en yüksek değeri almıştır). <!-- BELİRSİZ: tablo okunacak bir karede yok (01:00:00 karesinde önceki slayt, 00:55:00 karesi boş); veri kümesi adları, algoritmalar ve diğer değerler not edilemedi. -->

Tablodan çıkan sonuç: Farklı algoritmalar farklı veri kümelerinde daha iyidir. Her veri kümesinde en iyi olan tek bir süper algoritma olsaydı doğrudan onu kullanırdık; öyle bir algoritma yoktur. Bu yüzden veri kümesini çeşitli algoritmalarla denemek, deneme yanılma yoluyla ilerlemek gerekir. Hocaya göre bu çok hoş bir yol değildir ama yapılacak başka şey de yoktur.

## 8. Model Karmaşıklığı, Aşırı Eğitme ve Genelleştirme

Modelin karmaşıklığı, temel olarak modelin öğrendiği parametre sayısıdır. Hata, eğitim ve test kümelerinde farklı davranır:

- Eğitim hatası (slayttaki mavi eğri): Model karmaşıklaştıkça eğitim kümesindeki hata sürekli düşer. En yüksek karmaşıklıkta, örneğin 1-NN'de, eğitim hatası sıfıra iner. Karar ağacı her bölgede tek sınıftan örnek kalana kadar büyütülürse yine eğitim hatası sıfır olur. Ağaç büyümesi parametre sayısının artması demektir.
- Test hatası: Belli bir yere kadar düşer, o noktadan sonra artmaya başlar; çünkü model artık gürültüleri öğrenmeye başlar.

Kritik olan bu optimum noktadır ve her veri kümesinde farklıdır. Yapılması gereken, algoritmanın ne kadar karmaşık olacağını buna göre ayarlamaktır.

- Aşırı eğitme (overfitting) ve ezberleme aynı şeydir: eğitim kümesinde çok iyi, test kümesinde kötü performans.
- Genelleştirme (genelleştirebilme kabiliyeti): test kümesi üzerindeki performansın iyi olmasıdır.

Bunun bir istisnası vardır: Yapay sinir ağlarında katman ya da katmanlardaki nöron sayısı arttıkça test performansı her zaman bu eğrideki gibi davranmayabiliyor. Hoca bunu "istisna, daha doğrusu bir gizem" olarak niteledi; şu ana kadar matematiksel açıklaması yapılmamış, üzerinde epey çalışma süren bir konu.

> **Ek bilgi (derste anlatılmadı):** Literatürde bu olgu büyük olasılıkla "double descent" (çift iniş) adıyla incelenir: Çok büyük modellerde test hatası, eğitim verisini tam ezberleme noktasını geçtikten sonra yeniden düşebilir.

## 9. Kümeleme Algoritmalarına Giriş

### 9.1 Tanım

Sınıflandırma algoritmalarından sonra kümeleme algoritmalarına geçildi. Kümeleme algoritmaları eğiticisiz öğrenme algoritmalarıdır: Örneklerin sınıf bilgisi yoktur, yalnız özellikler vardır. Temelde veriyi en iyi temsil edecek vektörleri bulmaya çalışırlar. LVQ'daki centroidlere benzerler, ama bu centroidlerin (ve örneklerin) sınıfı yoktur.

Veriyi temsil eden vektörler bulunduktan sonra bütün veri bu yeni vektörlerle kodlanabilir. Bu yöntemler farklı bilgi sayısını azaltmak için kullanılır; bu yüzden birçok sıkıştırma algoritmasının temelinde kümeleme algoritmaları vardır.

### 9.2 Bir boyutlu örnek (ekrandan, 01:05:00)

Bir boyutlu (tek özellikli) 10 örnek içeren veri: 12-15-13-87-4-5-9-67-1-2.

Bu 10 farklı veriyi 3 farklı veriyle temsil etmek istersek: 12-12-12-77-3-3-3-77-3-3 şeklinde ifade edebiliriz. Yani 12, 15, 13'e 12; 87 ve 67'ye 77; 4, 5, 9, 1, 2'ye 3 denmiştir.

Kümeleme algoritmasına hiperparametre olarak küme sayısı $k$ verilir. Algoritma kümelerin orta noktalarını ve her örneğin hangi kümeye düştüğünü bulur. Gerçek değerlerle temsil edilen değerler arasındaki farkları en küçük yapmaya çalışır. Bu örnekte 3 küme oluşur:

- 12-15-13 örnekleri 1. kümede,
- 87-67 örnekleri 2. kümede,
- 4-5-1-2-9 örnekleri 3. kümededir.

Doğrulama (ara adım eklendi): $\{87, 67\}$ kümesinin ortalaması $77$, $\{1,2,4,5,9\}$ kümesinin ortalaması $21/5=4.2$, $\{12,13,15\}$ kümesinin ortalaması $40/3\approx 13.3$'tür. Slayttaki 12 ve 3 temsil değerleri tam ortalama değil, yuvarlanmış örnek değerlerdir.

### 9.3 Renk kümeleme

Slaytta 256 farklı gri tonu olan bir resim adım adım 128, 64, 32, ... renge ve en sonunda 2 renge (siyah-beyaz) indirilmiştir. Her biri ayrı bir kümeleme problemidir: 256'dan 128'e indirmek, 256'dan 2'ye indirmek başka problemlerdir.

- Gri seviyeli resimde her piksel 0-255 arası tek bir değerdir; centroidler tek boyutludur. 256 farklı değer 2 farklı değere indirgenir.
- Resim RGB renkli olsaydı her piksel üç sayıyla ifade edilir, centroidler üç boyutlu olurdu. Mekanizma aynıdır: $M$ farklı renk $K$ farklı renge indirgenir.

Resimdeki farklı renk sayısı azalınca bir pikseli ifade etmek için gereken bit sayısı azalır; resim sıkışır, boyutu küçülür.

### 9.4 Resim kümeleme (ekrandan, 01:15:00)

Bu kez küçük parçalar (patch), yani 10×10'luk bloklar kümelenir. Resim 200×200 piksel olsun; yatayda ve dikeyde 20'şer blok, toplam 400 tane 10×10'luk blok vardır ve muhtemelen hepsi birbirinden farklıdır. Bu 400 blok 20 bloğa indirgenir. Her blokta 100 piksel olduğu için (resim gri seviyeli) centroidler 100 boyutlu vektörlerdir. Amaç 400 farklı bloğu en iyi temsil eden 20 centroidi bulmaktır. Slayttaki sağdaki resim bu şekilde kodlanmış haliyle bloklu görünür.

### 9.5 Kodlama ve haberleşmede kullanımı

İki tarafta da aynı kod tablosu ($m_i$ vektörleri) bulunsun. Bir $x$ gönderilecekse $x$'in kendisi yerine ona en yakın $m_i$ bulunur ve karşıya yalnız $i$ indisi gönderilir. Alıcı bu indisin $m_i$'ye karşılık geldiğini bulur ve $\hat{x}=m_i$ kabul eder. $x$ ne kadar büyük boyutlu olursa olsun tek bir indis göndermek yeterlidir; büyük bir şey küçük bir kodla kodlanmış olur.

Bu yöntemde kayıp vardır: kayıp, $x$ ile $m_i$ arasındaki fark kadardır. Yani kayıplı bir sıkıştırma ve kayıplı bir haberleşme yöntemidir.

## 10. Hiyerarşik Kümeleme

### 10.1 İki tür (ekrandan, 01:20:00)

- Tek kümeden çok kümeye (bölmeli)
- Çok kümeden tek kümeye (eklemeli)

Slaytta a, b, c, d, e, f harfleriyle bir örnek (bc ve de birleşip def, bcdef ve en sonunda abcdef oluşur) ve algoritmaların başarılarına göre kümelendiği bir dendrogram vardır (kaynak: Wikipedia, Hierarchical clustering).

### 10.2 Eklemeli hiyerarşik kümeleme

Algoritma çok basittir: Birbirine en çok benzeyen iki kümeyi birleştir, tekrar et.

Başlangıçta dokuz farklı değer (dokuz tek elemanlı küme) olsun. Her adımda iki küme birleştirilir. Hocanın anlattığı slayt örneğinde önce birbirine en çok benzeyen D3 ve D7 birleştirilir (noktasal benzerlik örneğin Öklid uzaklığıyla ölçülebilir). Birinci adım sonunda kümelerin çoğunda birer eleman, bir kümede iki eleman vardır. Sonraki adımlarda başka çiftler (hocanın okuduğuna göre 1 ile 5, 6 ile 8) birleşir; daha sonra bir küme ile tek bir örnek birleşir. <!-- BELİRSİZ: slayttaki birleşme sırası (D3-D7 sonrası çiftler) karede görülmedi; altyazıda "üç ve beş, bir ve beş" diye karışık okunuyor. -->

### 10.3 İki kümenin benzerliği

İki noktanın benzerliğini ölçmek kolaydır. Ama bir kümenin bir noktaya ya da iki kümenin birbirine benzerliği nasıl ölçülür? Üç yaklaşım vardır:

- **Single link:** iki kümenin en benzer elemanlarının benzerliği.
- **Complete link:** iki kümenin en benzemeyen elemanlarının benzerliği.
- **Group average:** bir kümedeki her elemanın diğer kümedeki her elemana uzaklığının ortalaması.

Bunlardan biri seçilerek kullanılır. Durumdan duruma birbirlerine üstünlükleri vardır; kesin "şu kullanılır" denebilecek bir durum yoktur.

### 10.4 Dendrogram ve istenen küme sayısı

Dendrogramda önce birbirine en çok benzeyen iki eleman (burada iki algoritma) birleşir, sonra başka bir çift, sonra bunlar birleşir; her adımda birleştire birleştire en sonunda herkes tek kümede toplanır. Hoca burada dendrogramdaki algoritma adlarının çok kritik olmadığını, şeklin önemli olduğunu belirtti.

İstenen $K$ küme sayısına ulaşmak için süreci en sona kadar götürmek gerekmez; süreç bütün küme sayılarından geçer. Dendrogram bir yerden kesilir: Bir yerden kesilirse 3 küme, bir alttan kesilirse 4 küme, onun altından 5 küme oluşur. İşlem aşağıdan yukarıya gittiği için istenen sayıda küme oluştuğu adımda durulabilir.

### 10.5 Bölmeli hiyerarşik kümeleme

Eklemelinin tersidir:

1. Tek kümeyle başla.
2. Küme içinde birbirine en az benzeyen iki elemanı bul.
3. Kümeyi bu iki elemana yakınlığa göre böl.
4. Oluşan her alt küme için bu işlemi tekrar et.

Ne zaman durulur? İstenen küme sayısına ulaşınca ya da önceden belirlenmiş bir toplam benzerlik eşiğine göre (örneğin küme içindeki elemanların birbirine belli bir değerden fazla benzemesi istenirse).

## 11. K-means

### 11.1 Batch (toplu) k-means

K-means, hiyerarşik kümelemeden daha çok kullanılan, hocanın deyişiyle oldukça şık bir algoritmadır. Önce toplu (batch), sonra online hali anlatıldı; online hali LVQ'ya çok benzer.

Slayttaki adımlar (hocanın okuduğu haliyle; slayt 68):

1. Yalnız sayısal veriyle çalışır. Rastgele $k$ adet küme merkezi ata (LVQ'daki gibi).
2. Her örneği en yakınındaki merkezin kümesine ata.
3. Merkezleri kendi kümelerinin merkezine ata.
4. 2. ve 3. adımları küme değiştiren örnek kalmayıncaya kadar (ya da en fazla tur sayısı gibi başka bir kritere göre) tekrar et.

### 11.2 Adım adım gösterim (ekrandan, 01:25:00)

Slaytta "Adım Adım K-means" başlığıyla 6 iterasyon gösterilir (kaynak: cs.wmich.edu ClusteringAnalysis.pdf). Buradaki renkler verilerin sınıfı değildir; sınıf bilgisi zaten yoktur. Renkler yalnız örneklerin hangi küme merkezine ait olduğunu gösterir.

- İterasyon 1: Üç merkez (+ işaretleri) rastgele atanmıştır; ikisi üstteki büyük yığının içinde, biri yakınındadır. Her nokta en yakın merkezin kümesine atanır; bir nokta hangisine en yakınsa ona aittir.
- Sonra her merkez kendi kümesindeki örneklerin orta noktasına taşınır.
- Aynı işlem tekrar edilir. İterasyon 6'da merkezler üç doğal grubun ortasına oturmuştur: üstteki kırmızı yığın, sol alttaki yeşil grup ve sağ alttaki mavi grup.

Hoca ardından başka bir başlangıçla elde edilen sonucu (slayt 70, "İlk değerlerin önemi") gösterdi: Merkezler başka yerlerden başlatıldığında sonuç farklı olur; örneğin alttaki iki ayrı grup tek bir merkezle temsil edilebilir.

### 11.3 İlk değerlerin önemi ve hata fonksiyonu

**Soru (hoca):** İlk değerlerin önemi hangi tür algoritmalarda kritikti?

**Cevap:** Yerel arama algoritmalarında. K-means de bir yerel arama algoritmasıdır.

> **Hocanın vurgusu:** Makine öğrenmesinde kullanılan algoritmaların çok büyük bir kısmı yerel arama algoritmalarıdır. Bütün olasılıkları denemek mümkün olmadığından yeterince iyi çözümlerle yetinmek gerekir. Bu yüzden ilk değerler farklı olduğunda algoritmanın çıkışı da farklı olabilir.

K-means'in hata fonksiyonu, her örneğin kendi küme merkezine olan mesafesi üzerinden hesaplanır. Slayt 71'in küçük resminde (ekrandan, 01:30:00, küçük resimden okunuyor) $k$ adet küme $C_1,\dots,C_k$, $c_i$: $i$. küme merkezi, $x$: örnekler olmak üzere:

$$\text{Cost}(C)=\sum_{i=1}^{k}\sum_{x\in C_i}(x-c_i)^2$$

ve farklı ilk değerlerle bulunan sonuçların bu hataya göre karşılaştırıldığı yazılıdır.

### 11.4 Tekli (online) ve toplu (batch) k-means

Önceki örnek toplu (batch) k-means'tir: Bütün örneklerle birlikte işlem yapılır. Eğer her örnek için merkezler güncellenirse tekli (online) k-means elde edilir:

- Merkezler yine rastgele atanır.
- Bir örnek gelir; ona en yakın merkez bulunur ve bu merkez örneğe doğru yaklaştırılır. Bu, LVQ'daki ödülün aynısıdır. Ceza kısmı yoktur, çünkü sınıf yoktur.
- Yani her örnek, küme merkezlerinden kendisine en yakın olanı kendine doğru çeker.

Örnekler teker teker işlendiği için bellek sorunu oluşmaz. Bir milyon örnekle batch işlem yapmak sorun olabilir; online olarak örnekler teker teker alınarak rahatça işlenir. Derin öğrenme mimarilerinde de bu yaklaşım kullanılır: Milyonlarca örneğin hepsiyle güncelleme yapmak bellek sorununa yol açacağından örneklerin bir kısmı alınarak işlem yapılır.

## 12. Kendi Kendini Düzenleyen Haritalar (SOM)

SOM (Self-Organizing Maps), LVQ'yu da öneren Kohonen'in kümeleme algoritmasıdır. Slayttaki maddeler (ekrandan, 01:30:00; kaynak: Kohonen, T., "The self-organizing map", *Proceedings of the IEEE* 78.9, 1990, 1464-1480):

- K-means algoritmasında merkez noktalar arasında herhangi bir ilişki yoktur. SOM'da ise merkez noktalar 1 ya da 2 boyutlu bir dizi içinde yer alırlar. Buna göre birbirlerine 1 ya da 2 boyutlu uzayda komşudurlar.
- K-means algoritmasında yalnız kazanan (en yakın) merkez güncellenirken SOM'da bütün merkezler kazanan nörona komşuluklarına göre güncellenir. Yakın komşular uzak komşulara göre daha fazla hareket eder (güncellenir).
- Merkezlerin birbirine bağlı oluşu verinin 1 ya da 2 boyutlu uzaydaki yansımasının da elde edilmesini sağlar.

Hoca bunu şöyle canlandırdı: Bir örnek seçildi, bir centroid kazandı. Bu centroidin dizideki komşuları da tanımlıdır. Hem kazanan hem komşuları örneğe doğru çekilir; komşu olmayan ya da daha uzak komşu olan bir centroid o kadar çekilmez. Dolayısıyla SOM'un tek farkı, centroidler arasında bir komşuluk ilişkisi tanımlayarak online k-means'i çalıştırmaktır. Bu, verinin topolojisinin ortaya çıkmasını sağlar; oldukça güzel bir özelliktir.

Örnek slaytta (slayt 74) siyah noktalardan oluşan bir veri ve 20 SOM merkezi vardır. Merkezler arasında komşuluklar tanımlanmıştır (sen şuna ve şuna komşusun). Algoritma çalıştırıldığında merkezler, aralarındaki bağlantılarla birlikte veriyi yeterince iyi temsil edecek şekilde yerleşir.

## 13. DBSCAN: Yoğunluk Tabanlı Kümeleme

### 13.1 Motivasyon

Renkleri olmayan (hepsi aynı renkte) bir veri düşünelim. Bunu k-means'e ya da SOM'a (hoca hiyerarşik kümelemeden çok emin olmadığını söyledi) verip "üç kümeye ayır" desek algoritma kabaca üç merkez oluşturur ve örnekleri bu merkezlere yakınlıklarına göre kümelere atar. Bu yöntemler bölgesel bir özelliği dikkate alarak çalışır; uzay üç bölgeye bölünür.

Oysa veride farklı bir yapı vardır: Bazı noktalar birbirlerine çok yakın yakın sıralanarak yoğun, uzun şekilli gruplar oluşturur (slayttaki iç içe sarmal şekiller). Bu yapıyı yakalamak için yoğunluk tabanlı algoritmalar gerekir.

### 13.2 Tanımlar (ekrandan, 01:35:00)

DBSCAN yoğunluk tabanlı bir kümeleme algoritmasıdır. Hiperparametreleri: eps ve min_p. Önce bütün noktalar çekirdek, sınır ya da gürültü olarak belirlenir:

- **Çekirdek (kırmızı):** eps komşuluğunda en az min_p adet nokta bulunan noktalar.
- **Gürültü (mavi):** eps komşuluğunda hiç nokta bulunmayan noktalar.
- **Sınır (sarı):** eps komşuluğunda min_p'den az nokta bulunan noktalar.

Slayttaki şekilde (kaynak: Wikipedia, DBSCAN) renkler sınıf değil, nokta türünü gösterir. min_p = 2'dir. A ve diğer kırmızı noktaların eps yarıçaplı çemberi içinde en az iki nokta vardır; bunlar çekirdektir. B ve C (sarı) noktalarının eps komşuluğunda yalnız bir nokta vardır; bunlar sınırdır. N noktasının eps komşuluğunda hiç nokta yoktur; gürültüdür.

Hoca bunu sarmal veri üzerinde düşündürdü: Uzun bir şeklin uç kısımlarında sınır noktalar, araları boyunca hep çekirdekler görülür (min_p 2-3 civarında seçilirse). Bu veride gürültü yoktur.

### 13.3 Kümelerin oluşturulması

Slayt 76'daki adımlar (hocanın okuduğu haliyle):

1. Noktalar etiketlendikten sonra gürültüler elenir.
2. Çekirdeklerden birbirine eps mesafede olanlar birleştirilir. Hiperparametre eps'e bağlı olarak X adet küme oluşur.
3. Sınır noktalar en yakın çekirdeğin kümesine atanır.

Sarmal örnekte bir şeklin üzerindeki bütün çekirdekler kendi aralarında birleşir, diğer şeklin üzerindekiler de kendi aralarında birleşir. Uçlardaki sınır noktalar en yakın çekirdeğin kümesine eklenir. Böylece her sarmal tek bir küme olarak bulunur. DBSCAN yoğunluk tabanlı yapılarda oldukça iş gören bir algoritmadır.

### 13.4 Kümeleme algoritmalarında ne zaman durulur?

Slaytta "Ne zaman dururuz, ölü nöron kavramı (SOM, k-means), başarı ölçütü, küme sayısı nasıl belirlenir" başlıkları vardı; hoca bunları geçti. Temelde bir tur (epok) sayısı belirlenir ve işlem bu sayı üzerinden yürütülür.

## 14. Regresyon Algoritmaları: Basit Doğrusal Regresyon

Kümelemeden sonra regresyon algoritmalarına geçildi. Burada bir sınıf değil, bir sayı tahmin edilir. Sırasıyla basit doğrusal regresyon, k-NN ile regresyon, regresyon ağaçları görülecek; yapay sinir ağları da regresyon yapabilir.

### 14.1 Analitik çözüm (ekrandan, 01:40:00)

Hoca bu konuyu eskiden "mühendislik matematiği" dersinde anlattığını söyledi. $X$'lere karşılık $Y$'ler verilir; $X$ tek boyutlu olmak zorunda değildir. $W$, iteratif olarak adım adım bulunabileceği gibi analitik olarak, iteratif olmayan birkaç adımda da bulunabilir.

- $X$: girişler ($n\times d$); $n$ örnek, $d$ boyut.
- $Y$: çıkışlar ($n\times 1$).
- Model: $Y=XW$.
- $W$: katsayılar. Amaç $W$'yi bulmaktır; $X$ ve $Y$ bilinir.

**Soru (hoca):** $X$ $n\times d$, $Y$ $n\times 1$ ise $W$'nin boyutu nedir?

**Cevap:** $n\times d$ bir matrisi bir şeyle çarpıp $n\times 1$ elde etmek için o şey $d\times 1$ olmalıdır. $W$ $d\times 1$'liktir.

Türetme:

1. Her iki taraf soldan $X^{-1}$ ile çarpılır: $X^{-1}Y=X^{-1}XW$ ve $X^{-1}X=I$ olduğundan $W=X^{-1}Y$.
2. Ama $X$ kare matris değilse tersi alınamaz.
3. Bu yüzden önce iki taraf $X^T$ ile çarpılır: $X^TY=X^TXW$. $X^TX$ her zaman kare matristir ($d\times d$).
4. İki taraf $(X^TX)^{-1}$ ile çarpılır: $(X^TX)^{-1}(X^TY)=(X^TX)^{-1}(X^TX)W$ ve $(X^TX)^{-1}(X^TX)=I$.
5. Sonuç:

$$W=(X^TX)^{-1}(X^TY)$$

Matris çarpımı ve ters alma gibi sınırlı sayıda işlemle $W$ bulunur.

> **Ders sonrası not:** Hoca 3. adımda "$X^TX$ kare matristir, kare matrisin tersi alınabilir" dedi. $X^TX$ her zaman karedir ama her kare matrisin tersi yoktur; tersin var olması için $X$'in sütunlarının doğrusal bağımsız olması (örneğin $n \ge d$ ve tekrarlanan/bağımlı özellik olmaması) gerekir. Bağımlı sütunlarda büyük olasılıkla sözde ters (pseudo-inverse) ya da düzenlileştirme kullanılır.

### 14.2 Pratikte zorluk

Pratikte bu her zaman kolay değildir. Çok büyük veri kümelerinde, örneğin 500 bine 500 bin boyutlu bir matrisin tersini almak kolay bir işlem değildir. $X^TX$'in boyutları çok büyükse ters alma zorlaşır.

Sınıflandırmada anlatılan doğrusal regresyon gibi, rastgele bir yerden başlayıp adım adım ilerleyen sürüm burada da uygulanabilir. Küçük veri kümesinde analitik çözüm çok avantajlı ve hızlıdır; veri çok büyükse bu avantaj kaybolur ve mecburen online, adım adım ilerleyen iteratif yöntemlere geçilir.

## 15. k-NN ile Regresyon

### 15.1 Veri (ekrandan, 01:45:00)

Tek boyutlu bir veri kümesi:

| $x_1$ | $Y$ |
|---|---|
| 1 | 7 |
| 2 | 6 |
| 6 | 3 |
| 4 | 9 |

Yani 1 iken 7, 2 iken 6, 6 iken 3, 4 iken 9 çıkması istenir.

### 15.2 $k=1$

k-NN'deki işlemin aynısı yapılır: Bir örnek gelir, ona en yakın eğitim örneği bulunur ve onun çıkışı verilir. Örneğin 1'e çok yakın bir nokta için en yakın eğitim örneği 1'dir, çıkış 7'dir.

- $x < 1.5$: en yakın 1 → çıkış 7
- $1.5 < x < 3$: en yakın 2 → çıkış 6
- $3 < x < 5$: en yakın 4 → çıkış 9
- $x > 5$: en yakın 6 → çıkış 3

Sınırlar komşu eğitim noktalarının orta noktalarıdır (1 ile 2 arası 1.5, 2 ile 4 arası 3, 4 ile 6 arası 5). Oluşan model bir basamak (step) fonksiyonudur. Python ile birkaç noktada doğrulandı: 1.4 → 7, 1.6 → 6, 2.9 → 6, 3.1 → 9, 4.9 → 9, 5.1 → 3.

### 15.3 $k=4$

Sınıflandırmada en yakın $k$ örnek içinde en çok bulunan sınıf söyleniyordu. Regresyonda farklı olarak en yakın $k$ örneğin çıkışlarının ortalaması verilir. $k=4$ için:

$$\frac{7+6+3+9}{4}=\frac{25}{4}=6.25$$

Hoca "6 civarında" dedi; tam değer 6.25'tir. Veri kümesinde zaten 4 örnek olduğu için $k=4$'te her nokta için aynı şey söylenir: model sabit bir doğrudur.

## 16. Regresyon Ağaçları

### 16.1 Bölme ölçütü: entropi yerine standart sapma

Karar ağacı oluşturma algoritması özyinelemeli (recursive) bir algoritmaydı ve her seferinde bir yerden bölüyordu. Olası bütün bölmeler arasından, bölmenin sağ ve solundaki bölgelerin entropi toplamı en düşük olanı (saflık değeri en yüksek olanı) seçiliyordu.

Regresyonda da olası bütün bölmeler oluşturulur; fakat çıkışlar sınıf değil, sayıdır. Bu yüzden entropi yerine başka bir ölçüt gerekir. O bölgedeki çıkışların birbirine benzer olması istenir; bunun kabaca ölçüsü standart sapmadır. Bölmeyle oluşan iki bölgenin (sol ve sağ ya da üst ve alt) standart sapmalarının toplamının en küçük olması istenir. Algoritmanın geri kalanı karar ağacıyla aynıdır.

Hoca tahtada iki grup noktayla açıkladı: İki grubun arasından bölünürse her taraftaki standart sapma küçük, toplamları düşüktür; bu iyi bir bölmedir. Grupların birinin ortasından bölünürse bir taraftaki noktaların standart sapması yüksek olur ve toplam daha büyük çıkar.

### 16.2 Ne zamana kadar bölünür?

Karar ağaçlarında bölgeler tamamen saf olana kadar bölünebileceği ya da gürültüleri öğrenmemek için belli bir saflık (örneğin %95) kabul edilip durulabileceği konuşulmuştu. Burada da iki taraftaki standart sapma toplamının sıfır olması istenirse her bölgede tek örnek (ya da aynı çıkışlı örnekler) kalana kadar bölünür. Bölmeye devam etme ölçütü sıkılaştıkça daha büyük ağaçlar elde edilir.

### 16.3 Slayt örneği (ekrandan, 02:05:00)

Slayt "Regresyon ağaçlarında kabul edilen hata değerinin etkisi" başlıklıdır (kaynak: Ethem Alpaydın, The MIT Press, 2004). Üç ağaç ve karşılık gelen basamaklı fonksiyonlar vardır:

- $\theta_r=0.5$: kök $x<3.16$. Evet dalında $x<1.36$ (evet: 1.37, hayır: −1.35). Hayır dalında yaprak 1.86. İki iç düğüm vardır.
- $\theta_r=0.2$: hayır dalı da bölünür: $x<5.96$ (evet: 2.20), değilse $x<6.91$ (evet: 0.9, hayır: 2.40).
- $\theta_r=0.05$: $x<1.36$'nın evet dalı $x<0.76$ ile (1.15 ve 1.80), $x<6.91$'in evet dalı $x<6.31$ ile (1.20 ve 0.60) bölünür.

Yaprak çıkışı, o bölgeye düşen örneklerin çıkışlarının ortalamasıdır:

- 1.37: $x<1.36$ bölgesindeki üç kırmızı noktanın ortalaması.
- −1.35: $x$ 1.36'dan büyük ve 3.16'dan küçük olan iki örneğin ortalaması.
- 1.86: sağdaki yedi örneğin çıkış ortalaması.

> **Ders sonrası not:** Hoca kök eşiğini "3.6" diye okudu; slaytta $x<3.16$ yazmaktadır (ekrandan, 02:05:00).

Kabul edilen hata 0.05'ten de sıfıra indirilirse algoritma 1-NN regresyonuna benzer bir mekanizmaya dönüşür. Karar ağaçlarını küçük değişikliklerle regresyon ağaçlarına dönüştürmek oldukça basittir.

## 17. Çok Boyutlu Verilerle Çalışmak

Veri boyutu arttıkça işler zorlaşır. Bu analizde veriler uzayda düzgün (uniform) dağılımlı varsayılır; Gaussian gibi bir dağılım yoktur.

### 17.1 Verinin sınırlara yığılması

Bir boyutta $D$ uzunluğunda bir aralık düşünelim. Ortada $D/2$ uzunluğunda siyah sınıf bölgesi, dışında kırmızı sınıf vardır. Ortadaki $D/2$'lik alandaki örnekler kendi sınıflarındaki örneklere daha yakındır; bu alan "güvenli" bölgedir. Sınıf sınırına yakın bölgelerde ise karşı sınıfın örnekleri de yakındır; orası güvensizdir.

- 1 boyut: güvenli bölge $D/2$, oran $1/2$.
- 2 boyut: güvenli bölge $D^2/4$, oran $1/4$.
- 3 boyut: güvenli bölge $D^3/8$, oran $1/8$.
- $p$ boyut: oran $1/2^p$.

Boyut sayısı arttıkça verilerin çok büyük bir kısmı sınıfları ayıran sınırlara yakın bölgelere yığılır. Bir boyutta verinin %50'si güvenli bölgedeyken $p$ boyutta yalnız $1/2^p$'si güvenli bölgede kalır. Örneğin $p=10$ için bu oran yaklaşık $0.001$'dir. Örneklerin merkeze yakın olması iyidir, sınırlara yakın olması sorundur. Bu, çok boyutlu verilerle çalışmanın birinci kötü özelliğidir.

### 17.2 Gereken örnek sayısının üstel artması (ekrandan, 02:10:00)

İkinci kötü özellik: Boyut sayısı arttıkça veriyi yeterince temsil etmek için gereken örnek sayısı üstel olarak artar.

- Tek boyutlu uzayda [0,1] aralığını temsil eden 10 nokta olsun. Rastgele bir noktanın, uzayı temsil eden noktalardan en yakın olanına ortalama uzaklığı 0.5'tir (slayttaki değer).
- İki boyutlu uzayda rastgele bir noktanın en yakın noktaya olan ortalama uzaklığının düşey ya da dikey (Manhattan) 0.5 olması için gereken temsilci nokta sayısı 100'dür.

| Boyut sayısı | Gerekli temsil eden nokta sayısı |
|---|---|
| 1 | 10 |
| 2 | 100 |
| 3 | 1000 |
| ... | ... |
| $p$ | $10^p$ |

Bir test örneği geldiğinde ona yeterince yakın bir eğitim örneği bulunsun isteniyorsa (yakın örnek varsa iyi tahmin yapılabilir), gereken eğitim örneği sayısı boyutla üstel artar. Taban, seçilen nokta sayısına bağlıdır: 10 yerine 8 nokta seçilse $8^p$ olurdu. Doğru sınıflandırma yapmak için gereken örnek sayısı artar.

Çok boyutlu uzaylarda az sayıda örnekle çalışmak aşırı derecede risklidir. Örneğin 100 boyutlu bir uzayda 10 örnek (10 satır, 100 sütun) varsa sınıflandırma ya da regresyon riskli sonuçlar doğurabilir.


## 18. Veri Sızıntısı (Data Leakage)

Hoca bu konuyu "ileride bu alanlarda çalışırsanız" diye bir uyarı olarak sundu. Slayttaki maddeler (ekrandan, 02:15:00):

- Tahmin sonuçlarının çok iyi görünmesine sebep olabilir, ama gerçekler uygulamada ortaya çıkar.
- Test kümesindeki bilgilerin eğitim sürecine karışması: verileri normalize ederken, özellik seçimi yaparken test kümesini de kullanmak.
- Test zamanı elde olmayacak özelliklerin kullanılması: $x(t)=f(x(t-1),x(t+1))$.
- Zaman serisi sınıflandırmada eğitim ve test kümelerini oluşturmada hata: rastgele seçim yapılmamalı, bir $t$ anından öncesi eğitim, sonrası test olmalı ki ardışık süreçleri değil sınıfı tanısın.
- Verilerde çıkışla korelasyonu çok yüksek olan özelliklerin olması (kişi tanırken kimlik, telefon no vb.).

Senaryo: Toplanan veri eğitim ve teste bölünür, testte çok iyi sonuçlar alınır; model uygulamaya alınır (deploy edilir) ve her şey çöker. Bunun arkasında aşağıdakiler olabilir.

### 18.1 Test bilgisinin eğitime karışması

Normalizasyon, özellik seçimi ya da özellik temsili oluşturulurken test kümesi farkında olmadan kullanılabilir. Örneğin özellik seçim algoritması bütün veri kümesi üzerinde çalıştırılırsa test kümesi de işin içine katılmış olur. Doğrusu: Özellik seçimi yalnız eğitim kümesiyle yapılır (örneğin 1., 7. ve 9. özelliklerin işe yaradığı bulunur), sonra test kümesinde yalnız bu özellikler alınarak model test edilir.

### 18.2 Test zamanında elde olmayacak özellikler

Hoca bilerek abartılı bir örnek verdi: Dolar kuru tahmini yapan bir sistem, bugünkü değeri bir önceki gün ile bir sonraki günün değerinden (ortalamasından) tahmin ediyor: $x(t)=f(x(t-1),x(t+1))$. Geçmiş verilerle böyle bir model kurmak mümkündür ve başarısı çok yüksek olur. Ama gerçek zamanda $x(t+1)$'e erişilemez; yarınki kur bilinseydi bugünkü zaten bilinirdi.

### 18.3 Zaman serisinde rastgele bölme

Zaman serisi sınıflandırmada eğitim ve test kümeleri rastgele seçilmemelidir. Bir $t$ anı belirlenir; $t$'den öncesi yalnız eğitim, sonrası test için kullanılır. Rastgele oluşturulursa insanı çok yanıltan güzel sonuçlar elde edilir. Hoca kendisinin de bir zamanlar bu hataya düştüğünü anlattı: Önceki çalışmalarda hiç görülmemiş kadar iyi sonuçlar çıkmış, sonra sebebin bu olduğu anlaşılmış.

### 18.4 Çıkışla çok yüksek korelasyonlu özellikler

Günümüzde veri bilimiyle uğraşanların bir kısmı, özellikle derin öğrenmeyle birlikte, veri kümesinin özelliklerine hiç bakmadan veriyi doğrudan algoritmaya koyup çalıştırıyor. Veri kümesinin nasıl bir veri olduğu, özelliklerin nasıl dağıldığı incelenmiyor. Örneğin kişileri tanıma probleminde veri içinde kimlik numarası ya da telefon numarası varsa bu özellik tek başına sonucu verir. Bu yüzden veri kümesini iyi tanımak ve incelemek gerekir.

## 19. Weka ile Uygulama

### 19.1 Weka ve ARFF dosyası

Weka, dersteki konuları göstermek için uygun bir araçtır. Arayüzü vardır ama asıl gücü Java API'sidir; derin öğrenmeye bağlanmış sürümleri de vardır. Derste standart sürüm (Weka Explorer) gösterildi.

Veri "Open file" ile bir ARFF dosyası olarak açılır. Örnek veri dosyaları Weka'nın kurulu olduğu klasörün altındaki `data` klasöründedir. ARFF, Weka'nın dosya uzantısıdır; düz metin (text) dosyasıdır. İçinde satırlarda örneklerin, sütunlarda özelliklerin olduğu matris ve üstte özelliklerin adlarını veren tanımlar (description) vardır; formatı çok basittir. Veri arayüz yerine API ile de yüklenebilir.

### 19.2 Iris veri kümesi (ekrandan, 02:20:00)

- Relation: iris; Instances: 150; Attributes: 5 (sepallength, sepalwidth, petallength, petalwidth, class). Class sınıfı gösterir.
- Seçili özellik sepallength için en küçük 4.3, en büyük 7.9, ortalama 5.843, standart sapma 0.828; sayısal tip. Ayrıca sınıflara göre renklendirilmiş bir histogram gösterilir.

Özellikler tek tek filtre gibi değerlendirildiğinde histogramlara bakarak hangilerinin iyi olduğu görülür: sepallength ve sepalwidth sınıfları iyi ayırmaz, petallength ve petalwidth çok daha iyidir. Örneğin petallength'te 1 ile yaklaşık 2.8 arasındaki 50 örneğin hepsi tek sınıftandır (mavi). Üç sınıfın adları ve her birinden kaçar örnek olduğu da yazılıdır.

### 19.3 Sınıflandırma ve test seçenekleri

Classify sekmesinde bir sınıflandırıcı seçilir. Test seçenekleri:

- Use training set: eğitim kümesi üzerinde test.
- Supplied test set: başka bir ARFF dosyasını test kümesi olarak kullanma.
- Cross-validation: 10 katlı çapraz geçerleme (önceki bölümde anlatılan).
- Percentage split: örneğin verinin %66'sı eğitim, kalan %34'ü test.

"More options" içinden tahminlerin de çıktıya basılması istenebilir.

### 19.4 ZeroR ve J48 sonuçları

**Soru (hoca):** Bu veri kümesinde Zero Rule'un başarısının ne kadar olmasını beklersiniz?

**Cevap:** Bir öğrenci %33 dedi. Weka çıktısında doğru sınıflandırılan örnek sayısı 50, yani %33'tür. Karışıklık matrisinde ZeroR'un hepsine A sınıfı dediği, diğer sınıflara hiçbir şey diyemediği görülür.

Sonra J48 (karar ağacı) seçildi ve eğitim kümesi olarak yalnız %20 kullanıldı (ekrandan, 02:25:00). 150 örneğin %20'si olan 30 örnekle model kurulup 120 örnek üzerinde test edildi; 115'i doğru, 5'i yanlış sınıflandırıldı. Karışıklık matrisi:

```text
  a  b  c   <-- classified as
 37  0  0 |  a = Iris-setosa
  0 42  0 |  b = Iris-versicolor
  0  5 36 |  c = Iris-virginica
```

37 Iris-setosa'nın hepsi, 42 Iris-versicolor'un hepsi doğru sınıflandırılmış; 41 Iris-virginica'nın 36'sı doğru, 5'i yanlışlıkla Iris-versicolor olarak sınıflandırılmıştır. Doğruluk $115/120\approx 0.958$'dir (çıktıdaki ağırlıklı ortalama TP Rate 0.958 ile uyumlu).

Karışıklık matrisi hangi sınıfların birbirine karıştığını gösterir. En ideal karışıklık matrisinde köşegen dışındaki her yer sıfırdır; köşegendekiler doğruları, köşegen dışındakiler hataları gösterir.

Eğitim oranı düşürüldü:

- %10 (15 örnek): başarı yine %90'lar civarında; veri kümesi çok basittir.
- Çok daha düşük bir oranda (hoca "5" dedi) model 141 örnek üzerinde test edildi; yaklaşık %70 doğru, %29 yanlış. Muhtemelen bir sınıftan hiç eğitim örneği alınmamıştır. Karışıklık matrisi daha çok karışmıştır; özellikle Iris-versicolor ile Iris-virginica birbirine girer, mavi sınıf (setosa) daha ayrıktır. <!-- BELİRSİZ: Weka'da %5 bölme 150 örnekten 8 eğitim, 142 test verir; 141 test için oranın %6 olması gerekir. Hocanın girdiği değer karede görülmedi. -->

### 19.5 Breast Cancer veri kümesi

Daha zor bir veri olarak Breast Cancer açıldı: 286 satır, 10 özellik (sınıf dahil). Özelliklerin hepsi sayısal değildir; örneğin yaş aralıklara bölünerek nominal hale getirilmiştir, tümör boyutu için 11 kategorik değer vardır. Sınıf dağılımı 201 ve 85'tir; hocaya göre muhtemelen göğüs kanserinin tekrarlayıp tekrarlamayacağını tahmin eden bir veri kümesidir (no-recurrence-events ve recurrence-events).

Eğitim oranı %50 yapılarak farklı sınıflandırıcılar denendi:

- J48: iki sınıflı olduğu için karışıklık matrisi 2×2'dir. Tekrarlayan (recurrence) durumlar iyi tahmin edilemiyor; yalnız 9 tanesi doğru tahmin edilmiş, başarı düşüktür.
- Random Forest: çok az daha iyi. <!-- BELİRSİZ: altyazıda "69, 60" diye okunuyor; Random Forest'ın tam başarı değeri karede görülmedi. -->
- SVM (Functions altında SMO): başarı %72'ye çıktı. Ekranda 104 doğru (%72.7273), 39 yanlış (%27.2727), toplam 143 test örneği görülür (ekrandan, 02:30:00). Tekrarlayan sınıfta 18 doğru tahmin vardır.
- Naive Bayes: çok hızlı bitti, %71; karar ağacına göre fena değil.
- Yapay sinir ağı: biraz daha uzun sürdü ve daha kötü sonuç verdi.

Farklı algoritmaların aynı veri kümesindeki sonuçları farklıdır; aynı algoritmanın farklı hiperparametrelerle sonuçları da farklıdır. Bir sınıflandırıcının adına tıklanınca açılan pencerede değiştirilebilen bütün ayarlar o algoritmanın hiperparametreleridir; varsayılan değerlerle gelir. Bunlarla oynayarak modeli veri kümesine en uygun hale getirmeye hiperparametre optimizasyonu denir. Random Forest'ın dört hiperparametresi olduğu gösterildi; J48'in de kendi ayarları vardır. Makine öğrenmesi işlerinde böyle geniş bir arama uzayı vardır.

Sınıflandırıcı listesinde bazı algoritmalar soluk renktedir (örneğin trees altında Id3 ve M5P). Bunlar bu veri kümesine uygulanamayan algoritmalardır. Bu veri bir sınıflandırma verisidir (son sütun sınıftır); regresyon verisi verilirse regresyon yapabilen algoritmalar açık, yapamayanlar soluk hale gelir.

### 19.6 Görselleştirme

Visualize sekmesinde Iris'in 150 örneği iki özelliğe göre çizilir, renkler sınıfları gösterir. Eksenlerdeki özellikler istenildiği gibi değiştirilebilir; üst üste binen noktaları görmek için noktalar biraz rastgele kaydırılabilir (jitter). Petal width ile petal length birlikte bakıldığında mavi sınıf oldukça ayrıktır; kırmızı ve yeşil biraz birbirine girmiştir ama yine de veri kümesi oldukça basittir.

### 19.7 Filtreler: özellik seçimi ve PCA

Preprocess sekmesindeki Filter kısmında Supervised → Attribute → AttributeSelection seçildiğinde özellik seçim algoritmaları listelenir (ekrandan, 02:35:00): InfoGainAttributeEval, CfsSubsetEval, ChiSquaredAttributeEval, GainRatioAttributeEval, PrincipalComponents, SVMAttributeEval, WrapperSubsetEval vb.

> **Ders sonrası not:** Hoca CfsSubsetEval'i "bir wrapper yöntemi" olarak tanıttı. CFS (Correlation-based Feature Selection) büyük olasılıkla özellik alt kümesini sınıflandırıcı eğitmeden özellik-sınıf ve özellik-özellik korelasyonlarıyla değerlendiren filtre türü bir yöntemdir; Weka'da wrapper yöntemi listedeki WrapperSubsetEval'dir.

Principal Components seçildi (arama yöntemi olarak Ranker kullanmak gerektiği belirtildi) ve uygulandı. 4 boyutlu veri 2 boyuta indirgendi; yeni boyutların her birinin içinde eski boyutların hepsi yer alır. PCA'dan geçen hafta bahsedilmişti. Sonucun daha iyi ya da daha kötü olması ayrı bir konudur.

> **Hocanın vurgusu:** Burada özellik seçimi bütün veri kümesi üzerinde yapıldı; bu yapılmamalıdır. Özellik seçimi eğitim kümesi üzerinde yapılmalı, sonra test kümesine uygulanmalıdır (veri sızıntısı).

### 19.8 Kümeleme ve Weka'nın yeri

Cluster sekmesinde DBSCAN, SimpleKMeans ve hiyerarşik kümeleme gibi algoritmalar vardır. Makine öğrenmesi araştırmacıları bir sürü algoritmayı içeren kütüphaneler kullanmak zorundadır; Weka bunların iyilerinden biridir. Bugün daha güncel paketler vardır ve Weka biraz eskide kalmıştır, ama temel noktaları içerdiği için eğitim amaçlı kullanımında sorun yoktur. Tek konu Java'dır: Uygulamanın kurulduğu sistemde Java kullanılıyorsa sorun yoktur; günümüzde farklı sistemleri sarmalayıcı (wrapper) yazılımlarla birlikte çalıştırmak da büyük sorun oluşturmaz.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:11:41): k-NN'de $k=N$ ($N$: eğitim kümesindeki örnek sayısı) seçilirse ne olur?

> **Cevap (derste verildi):** Her test örneği için bütün eğitim örneklerine bakılır; sonuç hep aynıdır ve en çok örneği olan sınıftır. Algoritma Zero Rule (çoğunluk sınıfını tahmin etme) yaklaşımına dönüşür.

**Soru 2** (derste sözlü, 00:13:35): k-NN'in dezavantajı nedir? Bir test örneğini sınıflandırmak için neye ihtiyaç vardır?

> **Cevap (derste verildi):** Eğitim kümesinin tamamına ihtiyaç vardır; test örneği bütün eğitim örnekleriyle karşılaştırılır. Test süresi uzun, saklanması gereken veri büyüktür. Yapay sinir ağı, karar ağacı ve doğrusal regresyonda yalnız model yeterlidir.

**Soru 3** (ekrandan, 00:25:00 ve derste sözlü, 00:29:22): LVQ güncelleme kuralı $\mu_k \leftarrow \mu_k + \eta(x-\mu_k)$'da $\eta=1$ ve $\eta=0.5$ için ne olur?

> **Cevap (derste verildi):** $\eta=1$'de prototip doğrudan $x$'in konumuna gider; $\eta=0.5$'te ikisinin tam ortasına gelir. $\eta=0.1$ daha az, $\eta=0.9$ daha çok yaklaştırır.

**Soru 4** (derste sözlü, 00:35:10): LVQ (ya da 1-NN) ne zaman doğrusal karar sınırı üretir? İki prototip için sınır nasıldır? Üç prototipte ne olur?

> **Cevap (derste verildi):** İki sınıf ve iki prototip olduğunda sınır doğrusaldır; iki noktayı birleştiren doğrunun ortasından geçen dik doğrudur. Üç prototipte sınır, prototip çiftlerinin orta dikmelerinden oluşan parçalı bir yapıdır; üçüne eşit uzaklıkta bir nokta vardır.

**Soru 5** (derste sözlü, 00:59:00): 1-NN algoritmasının eğitim kümesi üzerindeki başarısı yüzde kaçtır? Neden?

> **Cevap (derste verildi):** %100. Her eğitim örneğinin en yakın komşusu kendisidir; aynı noktada farklı sınıftan örnek bulunması dışında hep doğru sınıfı söyler. 1-NN eğitim kümesini ezberler.

**Soru 6** (ekrandan, 01:05:00): 12-15-13-87-4-5-9-67-1-2 verisini 3 değerle temsil ediniz; hangi örnekler hangi kümededir?

> **Cevap (slaytta verildi):** 12-12-12-77-3-3-3-77-3-3. 1. küme: 12, 15, 13; 2. küme: 87, 67; 3. küme: 4, 5, 1, 2, 9.

**Soru 7** (ekrandan, 01:40:00 ve derste sözlü, 01:38:54): $X$ $n\times d$, $Y$ $n\times 1$ ve $Y=XW$ ise $W$'nin boyutu nedir? $W$ analitik olarak nasıl bulunur?

> **Cevap (derste verildi):** $W$ $d\times 1$'dir. $X$ kare olmayabileceği için iki taraf $X^T$ ile çarpılır: $X^TY=X^TXW$; $X^TX$ kare olduğundan $W=(X^TX)^{-1}(X^TY)$.

**Soru 8** (ekrandan, 01:45:00): $(x_1, Y)$ = (1, 7), (2, 6), (6, 3), (4, 9) verisinde k-NN ile regresyon yapılırsa $k=1$ ve $k=4$ için model nasıl olur?

> **Cevap (derste verildi):** $k=1$: basamak fonksiyonu; $x<1.5$ için 7, $1.5<x<3$ için 6, $3<x<5$ için 9, $x>5$ için 3. $k=4$: dört örneğin çıkış ortalaması $25/4=6.25$; her yerde aynı (sabit) çıkış.

**Soru 9** (derste sözlü, 02:00:26): Regresyon ağacında sınıf olmadığı için entropi yerine ne kullanılır?

> **Cevap (derste verildi):** Bölmeyle oluşan iki bölgedeki çıkışların standart sapmalarının toplamı; bu toplamı en küçük yapan özellik-eşik ikilisi seçilir. Yapraktaki çıkış, bölgedeki örneklerin çıkış ortalamasıdır.

**Soru 10** (derste sözlü, 02:22:51): Iris veri kümesinde (3 sınıf, her birinden 50 örnek) ZeroR'un başarısı ne olur?

> **Cevap (derste verildi):** %33. Hepsine aynı sınıf (A) dendiği için yalnız o sınıfın 50 örneği doğru sınıflandırılır: $50/150\approx 0.33$.

**Soru 11** (ekrandan, 02:25:00): J48'in Iris'te %20 eğitim oranıyla ürettiği karışıklık matrisi aşağıdadır. Doğruluk nedir, hangi sınıflar karışmıştır?

```text
  a  b  c   <-- classified as
 37  0  0 |  a = Iris-setosa
  0 42  0 |  b = Iris-versicolor
  0  5 36 |  c = Iris-virginica
```

> **Cevap (derste verildi):** 120 test örneğinden 115'i doğru, doğruluk $115/120\approx 95.8\%$. Hatalar yalnız 5 virginica örneğinin versicolor olarak sınıflandırılmasıdır; setosa hiç karışmamıştır.

**Soru 12** (ekrandan, 02:10:00): Tek boyutta [0,1] aralığını temsil etmek için 10 nokta gerekiyorsa aynı yoğunluk için $p$ boyutta kaç nokta gerekir? Her boyutta ortadaki yarım aralık güvenli bölge ise $p$ boyutta güvenli bölgenin oranı nedir?

> **Cevap (derste verildi):** $10^p$ nokta (2 boyutta 100, 3 boyutta 1000). Güvenli bölgenin oranı $1/2^p$ (1 boyutta 1/2, 2 boyutta 1/4, 3 boyutta 1/8).

## Dersin Toparlaması

Bu derste sınıflandırma yöntemleri k-NN ve LVQ ile tamamlandı. k-NN'in eğitimsiz ama test zamanında pahalı olduğu, LVQ'nun ödül-ceza mekanizmasıyla az sayıda prototip bulup bu sorunu çözdüğü görüldü. Eğitim başarısının yanıltıcı olabileceği borsa hikayesiyle, güvenilir ölçüm için çapraz geçerleme ile, model karmaşıklığı arttıkça eğitim hatasının sürekli düştüğü ama test hatasının bir noktadan sonra arttığı aşırı eğitme kavramıyla anlatıldı. Tek bir algoritmanın her veride en iyi olmadığı, denemenin şart olduğu vurgulandı.

Ardından eğiticisiz öğrenmeye geçildi: kümelemenin sıkıştırma ve kodlamadaki rolü, hiyerarşik kümeleme (eklemeli/bölmeli, single/complete/group average, dendrogram), toplu ve online k-means, komşuluklu online k-means olarak SOM ve yoğunluk tabanlı DBSCAN. Regresyon tarafında doğrusal regresyonun analitik çözümü $W=(X^TX)^{-1}X^TY$, k-NN regresyonu ve standart sapmaya dayanan regresyon ağaçları görüldü. Son olarak çok boyutlu verilerin sorunları (verinin sınırlara yığılması, gereken örnek sayısının üstel artması) ve veri sızıntısı türleri anlatıldı; bütün bu kavramlar Weka üzerinde Iris ve Breast Cancer verileriyle uygulamalı gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
