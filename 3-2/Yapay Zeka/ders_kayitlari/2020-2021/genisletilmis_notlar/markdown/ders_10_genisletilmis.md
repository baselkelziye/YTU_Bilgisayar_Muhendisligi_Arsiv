# Ders 10 Genişletilmiş Notu: Özellik Belirleme ve Sınıflandırma Metotlarına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: Eğitim ve Test Kümesi Neden Ayrılır
- 2. Özellik Belirleme: Neden Gerekir
- 3. Balık Hali Örneği: Uzunluk ve Parlaklık
- 4. Özellik Seçiminin Yolları
- 5. Filter Yöntemi 1: Bilgi Kazancı
- 6. Filter Yöntemi 2: Sinyalin Gürültüye Oranı
- 7. Filter Yöntemlerinin Göremediği Durum
- 8. Wrapper: Özellik Alt Kümesi Seçiciler
- 9. Yeni Özelliklerin Çıkarımı: PCA ve LDA
- 10. Ne Zaman Hangi Yöntem
- 11. Sınıflandırma Metotları ve Varsayımları
- 12. Doğrusal Regresyon
- 13. Karar Ağaçları
- 14. Yapay Sinir Ağları
- 15. Hiperparametre Kavramı
- 16. En Yakın K Komşu
- Örnek Sorular

## 1. Tekrar: Eğitim ve Test Kümesi Neden Ayrılır

Ders, makine öğrenmesi bölümünün ikinci slayt setine geçmeden önce kısa bir tekrarla başladı. Önceki derste bir veri kümesi oluşturulmuş, bu küme eğitim ve test olmak üzere iki parçaya ayrılmıştı. Hoca bunun nedenini sordu.

**Soru:** Veri kümesini neden eğitim ve test kümesine ayırıyoruz? **Cevap:** Bir öğrenci, tüm veri eğitime verilirse modelin veriyi ezberleyip ezberlemediğinin (overfitting) ve geçerli bir model kurulup kurulmadığının kontrol edilemeyeceğini söyledi. Hoca, asıl istenenin modelin daha önce görmediği örnekler üzerinde iyi çalışması olduğunu ekledi.

Hoca bunu bir OCR programı örneğiyle açıkladı. Programı satan firma reklamda "%95 başarı" der. Programı satın alan kullanıcı onu firmanın verisinde değil, kendi verisinde çalıştıracaktır; firmanın kendi içinde topladığı verideki başarı kullanıcıyı hiç ilgilendirmez. Firma ise kullanıcının verisini önceden göremez ve bilemez. Test kümesi diye ayrılan parça, sistemin gerçek uygulamada karşılaşacağı bu yeni örnekleri temsil eder. Model eğitim sırasında bu örnekleri görmez; bunlar üzerindeki performans modelin asıl performansıdır.

Performansın ölçülebilmesi şöyle olur: test kümesindeki örneklerin gerçek sınıfları (ya da çıkışları) aslında bilinir. Bilinmiyormuş gibi davranılır, model bu örnekler için tahmin üretir ve tahminlerle gerçek değerler arasındaki uyum modelin başarısını verir.

## 2. Özellik Belirleme: Neden Gerekir

Bu dersin konusu slayttaki akışın şu kısmıdır: özellik belirleme, sınıflandırma yöntemleri, kümeleme algoritmaları, regresyon algoritmaları, çok boyutlu verilerle çalışmak ve dikkat edilmesi gereken bir kavram olarak veri sızıntısı. Derste özellik belirleme tamamlandı ve sınıflandırma yöntemlerinden k en yakın komşuya kadar gelindi.

### 2.1 Doktor örneği

Bir doktorun önüne hastanın dosyası konduğunu düşünelim (ekrandan, 00:20:00). Görev, kimlerin hasta olduğunu bulmaktır. Dosyada hastaya dair pek çok bilgi vardır: ad soyad, doğum yeri, cinsiyet, kan tahlili sonuçları, röntgen sonuçları vb. Bu bilgilerin hepsi hastalıkla ilgili değildir; bir şekilde dosyaya girmişlerdir. Hastanın adının Ayşe ya da Fatma olması hastalığı belirlemede anlamlı değildir, cinsiyetin ise bir önemi olabilir. Yani elde bulunan her özellik çıkışı tahmin etmek için gerekli değildir; gereksiz veriler de işin içinde olabilir.

### 2.2 Küçük tablo örneği

Slayttaki tabloda 3 özellik, bir sınıf sütunu ve 4 örnek vardır (ekrandan, 00:20:00):

| 1. Öz | 2. Öz | 3. Öz | Sınıf |
|---|---|---|---|
| 1 | 3 | 13 | A |
| 2 | 3 | 13 | B |
| 1 | 4 | 13 | A |
| 2 | 3 | 13 | B |

Hoca hangi özelliğin sınıfı belirlemek için daha anlamlı olduğunu sordu.

- **1. özellik:** 1 olanlar A, 2 olanlar B sınıfındadır. Sınıfı çok açık biçimde söyler.
- **2. özellik:** Kesin bir şey söylemez, ama bir şeyler söyler. 4 olanlar A'dır. 3 olan üç örneğin ikisi B, biri A'dır; dolayısıyla 2. özellik 3 ise B olma olasılığı daha yüksektir. Ayırt edici ama 1. özellik kadar iyi değildir.
- **3. özellik:** Bir öğrenci "13 olanlar yüzde elli A, yüzde elli B" dedi. Hoca bunun hiçbir şey söylemediğini vurguladı: bütün örneklerde aynı olan bir özelliğin veri kümesinde bulunmasının tahmin açısından hiçbir anlamı yoktur.

Sonuç olarak her özellik sınıfı ya da çıkışı belirlemede eşit kabiliyete sahip değildir. Var olan özelliklerden bir kısmını seçmek ya da yenilerini türetmek bu yüzden gerekir.

### 2.3 "Hangi boyut?" grafiği

Slayttaki iki boyutlu grafikte yatay eksen $x_1$, dikey eksen $x_2$'dir; sınıflar çarpı ve yuvarlakla gösterilmiştir (ekrandan, 00:25:00). Boyut, özellik demektir. Soru: sınıfları ayırmak için hangi özellik daha iyidir? Cevap $x_1$'dir.

Hoca bunu her sınıfın histogramını çizerek gösterdi. $x_1$'e göre çizildiğinde çarpıların histogramı solda yükselip belli bir noktadan sonra sıfıra iner, yuvarlakların histogramı ise o noktadan sonra yükselir; dağılımlar oldukça ayrıktır. $x_2$'ye göre çizildiğinde iki dağılım birbirinin içine girer. Bu yüzden yalnızca $x_2$'ye bakarak "şundan büyükse şu sınıf, küçükse bu sınıf" demek mümkün değildir. $x_1$'e bakarak ise "yaklaşık 0.05'ten büyükse yuvarlak, küçükse çarpı" gibi bir kural söylenebilir.

## 3. Balık Hali Örneği: Uzunluk ve Parlaklık

Bir balık halinde yakalanan iki tür balık birbirine karışmıştır: somon (salmon) ve levrek (sea bass). Balıklar kayan bir bant üzerinde ilerler; yukarıdaki kamera görüntü üzerinde ön işleme yapar ve iki özellik verir: balığın boyu ve parlaklığı. Soru, bu iki özellikle türlerin ayırt edilip edilemeyeceğidir.

### 3.1 Uzunluk

Slaytta iki sınıfın uzunluk histogramları vardır (ekrandan, 00:30:00). Slayttaki not "Salmonlar genelde Sea Bass'lardan daha kısalar" der. Ama somonlarda da epey uzun olanlar vardır; iki sınıf birbirinden açıkça ayrılmaz.

Uzunluğu belli bir eşikten büyük olanlara levrek, küçük olanlara somon denecek bir kural kurulmak istenir. Eşik farklı yerlere konarak denemeler yapılır. Bir denemenin iyiliği, yanlış sınıflanan balık sayısıyla ölçülür: eşiğin solunda kalan levrekler (somon denmiştir) ve sağında kalan somonlar (levrek denmiştir) hatadır. Yani eşiğin solunda levrek histogramının altında kalan alan ile sağında somon histogramının altında kalan alanın toplamı hatayı verir. Bütün denemeler içinde en düşük hatayı veren eşik slaytta yeşil çizgiyle gösterilmiştir (yaklaşık 11 uzunluğu).

<!-- BELİRSİZ: Hocanın histogramdan okuduğu tek tek balık sayıları (ör. "uzunluğu 3 olan 4 levrek, 17 somon", eşik 5 için "9 yanlış") altyazıda tutarsız; karede histogram ölçeğiyle doğrulanamadığı için nota alınmadı. -->

**Soru:** Eşik denemelerinin iyiliğini nasıl karşılaştırırız? **Cevap:** Bir öğrenci "yanlış tahmin ettiklerine bakarak" dedi. Hoca, her eşik için kaç balığın yanlış sınıflandığının sayılabileceğini ve böylece her özelliğin sınıflandırma açısından ne kadar iyi olduğunun görülebileceğini ekledi.

### 3.2 Parlaklık

Parlaklıkta levrekler daha parlaktır. Yine histogramlar çizilir, bütün eşikler denenir ve en iyi eşik ($x^*$) bulunur. İki özelliğin en iyi eşiklerindeki hatalar (slaytta kırmızı bölge) karşılaştırıldığında parlaklığın çok daha az hata yaptığı görülür. Sınıfta da cevap parlaklık oldu.

Özellik sayısı çok olursa bunları tek tek gözle incelemek mümkün değildir; özellik seçimini makinenin yapması gerekir.

## 4. Özellik Seçiminin Yolları

Slayttaki sınıflandırma şöyledir (ekrandan, 00:35:00):

- Var olan özelliklerden bazılarını seçmek
  - Özellikleri tek tek değerlendirmek (filter)
  - Özellik alt kümeleri oluşturup sınıflandırıcılar kullanarak performanslarını ölçmek ve bu alt kümeleri en iyilemek için değiştirmek (wrapper)
- Var olan özelliklerin doğrusal birleşimlerinden yeni özelliklerin çıkarımı (PCA, LDA)

Birinci yolda elde 50 özellik varsa bunların bir kısmı seçilir. İkinci yolda özellikler seçilmez; var olan özelliklerin doğrusal birleşimlerinden yeni özellikler türetilir, yani veri başka bir uzaya taşınır. 45 boyutlu bir uzay yine 45 boyutlu başka bir uzaya dönüştürülebilir ya da daha az boyut alınabilir.

Filter yaklaşımında her özellik tek başına değerlendirilir: balık örneğinde uzunluğa ve parlaklığa ayrı ayrı bakıldığı gibi. 50 özellik varsa her birinin sınıfı ya da çıkışı tek başına tahmin etme kabiliyeti ölçülür, özellikler bu kabiliyete göre sıralanır ve anlamlı görülen kısmı (belli bir eşiğin üstündekiler ya da belli sayıda en iyi özellik) seçilir. Filter "elimizde yalnızca bu özellik olsaydı ne olurdu?" sorusunun cevabını arar: özellik değiştikçe sınıf ya da sonuç ne kadar değişiyorsa özelliğin sonuca etkisi o kadar büyük kabul edilir. Wrapper yaklaşımında ise özellikler tek tek değil, alt kümeler halinde bir sınıflandırıcının içinde değerlendirilir.

## 5. Filter Yöntemi 1: Bilgi Kazancı

### 5.1 Piknik örneği

Slayttaki örnekte hava, nem, rüzgar ve su sıcaklığı gibi dört özelliğe göre pikniğe gidilip gidilmediği 4 olay için verilmiştir. Sınıf evet ya da hayırdır, yani iki sınıflı bir problemdir. Soru: her özelliğin tek başına pikniğe gitme kararı üzerindeki etkisi nedir?

Gözle bakınca rüzgarın kararı etkilemeyeceği görülür, çünkü bütün örneklerde rüzgar aynıdır (güçlü). Gözle bakmak yerine bilgi kazancı (information gain) yöntemi kullanılır.

<!-- BELİRSİZ: Piknik tablosunun tamamı (nem ve su sıcaklığı değerleri) karelerde okunamadı; yalnızca hava ve rüzgara dair bilgiler altyazıdan ve 00:45:00 karesinden alındı. -->

### 5.2 Formül

$S$ eğitim seti içindeki $A$ özelliğinin kazancı (ekrandan, 00:40:00):

$$Gain(S, A) = Entropy(S) - \sum_{v \in Values(A)} \frac{|S_v|}{|S|} Entropy(S_v)$$

Burada $Values(A)$, $A$ özelliğinin aldığı farklı değerlerdir; $S_v$, $A$'nın $v$ değerini aldığı örneklerdir. Kazanç ne kadar yüksekse özellik o kadar iyidir.

### 5.3 Entropi

Entropi düzensizliğin ölçüsüdür; bir şey ne kadar düzensizse entropisi o kadar yüksektir. Termodinamiğin ikinci yasasında da geçer: boş bir kaba bir noktadan gaz verilirse moleküller bir noktada toplanmaz, her yere yayılır; sistemler entropilerini artırma eğilimindedir.

$N$ kavramının $c$ farklı değeri varsa $N$'in entropisi, aldığı her değerin olasılığı $p_i$ kullanılarak şöyle hesaplanır:

$$Entropy(N) = \sum_{i=1}^{c} -p_i \log_2 p_i$$

Hoca iki uç durumu tahtada hesapladı:

- 6 örneğin 3'ü A, 3'ü B olsun. $p_A = p_B = 0.5$ ve $\log_2 0.5 = -1$. $Entropy = -(0.5 \cdot (-1) + 0.5 \cdot (-1)) = 1$. Örneklerin yarısı A, yarısı B olduğu için hiçbir yapı yoktur, tahmin yapılamaz; düzensizlik en yüksektir. İki sınıflı bir kavramın entropisi en fazla 1 olabilir.
- Örneklerin hepsi A olsun. $p_A = 1$, $\log_2 1 = 0$; $p_B = 0$ olduğu için ikinci terim de 0'dır. $Entropy = 0$.

Slayttaki grafikte $H(X)$, $\Pr(X = 1)$ olasılığına göre çizilmiştir: 0 ve 1'de sıfır, 0.5'te 1 değerini alan bir tepe biçimindedir (ekrandan, 00:40:00).

### 5.4 Pikniğin entropisi ve havanın kazancı

İlk önce eğitim setinin tamamının, yani sınıfın entropisi hesaplanır. Evet cevabının olasılığı 3/4, hayır cevabının 1/4'tür:

$$Entropy(Piknik) = -\frac{3}{4}\log_2\frac{3}{4} - \frac{1}{4}\log_2\frac{1}{4} = 0.811$$

$Entropy(S)$ terimi bütün özellikler için aynı olduğundan her özellik için yeniden hesaplanmaz; karşılaştırmada hepsinden aynı değer çıkarılır.

Havanın iki değeri vardır: güneşli ve yağmurlu. Slayttaki hesap (ekrandan, 00:45:00):

$$Gain(Piknik, Hava) = 0.811 - \frac{3}{4}\left(-\frac{3}{3}\log_2\frac{3}{3} - 0\right) - \frac{1}{4}\left(0 - \frac{1}{1}\log_2\frac{1}{1}\right) = 0.811$$

Rakamların anlamları slaytta şöyle açıklanmıştır:

- 0.811: pikniğe gitme olayının entropisi
- 3/4: havanın güneşli olma oranı
- 3/3: hava güneşliyken pikniğe gidilme oranı; 0: hava güneşliyken gidilmeme oranı
- 1/4: havanın yağmurlu olma oranı
- 0: hava yağmurluyken gidilme oranı; 1/1: hava yağmurluyken gidilmeme oranı

$\log_2 1 = 0$ olduğu için iki alt kümenin entropisi de 0'dır; 0.811'den 0 çıkarılır ve kazanç 0.811 kalır. Aynı hesap nem, rüzgar ve su sıcaklığı için de yapılır. Rüzgarın kazancı 0 çıkar, çünkü tek değeri olan rüzgarda alt kümenin entropisi sınıfın entropisine eşittir ve 0.811'den 0.811 çıkarılır.

Kazancın anlamı şudur: $A$ özelliği kullanıldığında $S$ sınıfının entropisi ne kadar azaltılabiliyor? Entropiyi ne kadar çok azaltıyorsa özellik o kadar iyidir; işlemler en yüksek kazanca göre yapılır. Bu, sıkça kullanılan standart bir yaklaşımdır.

> **Ders sonrası not:** Hoca bir yerde "A'yı kullanarak ne kadar azaltırsam o kadar kötü" dedi (00:47:55); bağlamdan bunun bir dil sürçmesi olduğu anlaşılıyor. Doğrusu: entropiyi ne kadar çok azaltırsa o kadar iyi.

> **Ek bilgi (derste anlatılmadı):** Bilgi kazancı, ID3 ve C4.5 gibi karar ağacı algoritmalarında düğüme konacak özelliği seçmek için de kullanılır. Çok sayıda farklı değeri olan özellikleri (örneğin bir kimlik numarası) kayırma eğilimi olduğu için C4.5'te kazanç oranı (gain ratio) adlı düzeltilmiş bir ölçü kullanılır.

## 6. Filter Yöntemi 2: Sinyalin Gürültüye Oranı

Bilgi kazancı kategorik özellikler içindir. Sayısal özellikler için kullanılabilecek yöntemlerden biri sinyalin gürültüye oranıdır (signal-to-noise ratio). Önceki derste sınıflar arası ayrılıkların fazla, sınıf içi ayrılıkların az olmasının iyi olduğu konuşulmuştu; bu yöntem o bilgiyi bir ölçüye dönüştürür (ekrandan, 00:50:00):

$$S_i = \frac{m_1 - m_2}{d_1 + d_2}$$

- $m_1$: sınıf 1'deki $i.$ özelliklerin ortalaması; $m_2$: sınıf 2'deki $i.$ özelliklerin ortalaması. Pay "sinyal"dir.
- $d_1$: sınıf 1'deki $i.$ özelliklerin standart sapması; $d_2$: sınıf 2'deki $i.$ özelliklerin standart sapması. Payda "gürültü"dür.

**Soru:** $m_1$ ile $m_2$'nin birbirinden uzak olması iyi mi kötü mü? **Cevap:** İyidir; ne kadar uzaklarsa o kadar iyi.

**Soru:** $d_1 + d_2$'nin nasıl olmasını isteriz? **Cevap:** Bir öğrenci "az olmasını" dedi. Hoca onayladı: $d_1$'in küçük olması, o sınıftaki örneklerin bu özellikte birbirine çok benzediği, küçük bir bölgede toplandığı anlamına gelir.

Yani pay büyük, payda küçük olmalıdır. Paydaki $m_1 - m_2$ farkının mutlak değerini almak mantıklıdır. $S$ değeri en yüksek olan özellikler seçilerek sınıflandırmada kullanılır: belli bir değerden yüksek olanlar ya da en yüksek $S$'e sahip $k$ tane gibi pek çok varyasyon yapılabilir.

Bu iki filter yalnızca örnektir: biri kategorik, biri sayısal değişkenler için. Ki-kare gibi daha pek çok filter vardır; hoca bu tür yöntemlerin çok sayıda bulunduğu bir araca ileride bakılabileceğini söyledi. <!-- BELİRSİZ: Altyazıda "VK" diye geçen aracın adı (00:50:49) büyük olasılıkla Weka'dır; doğrulanamadı. -->

## 7. Filter Yöntemlerinin Göremediği Durum

Hoca, wrapper'lara neden ihtiyaç olduğunu göstermek için bir veri kümesi çizdi (ekrandan, 00:55:00). İki boyutlu düzlem dört kareye bölünmüştür; sol üst ve sağ alt bir sınıf (pembe), sağ üst ve sol alt diğer sınıftır (yeşil). Satranç tahtası gibi bir yapıdır.

**Soru:** $x_1$ mi daha iyidir, $x_2$ mi? **Cevap:** Öğrenciler "eşitler" ve "ikisi de kötü" dedi. Hoca onayladı: sinyalin gürültüye oranı gibi bir filter kullanılsa ikisinin de işe yaramadığı görülür. Histogramları çizilirse her iki eksende de iki sınıfın dağılımı birebir üst üste biner. Bu özellikler tek başlarına sınıfı tahmin edemiyor gibi görünür.

Oysa problem zor değildir. "$x_1$ şu değerden küçük ve $x_2$ şu değerden büyükse sınıf şudur" gibi birkaç kuralla veri kümesi kusursuz sınıflanabilir. Bu kadar basit bir yapıyı filter'lar göremez, çünkü tek tek özelliklere bakarlar. Özellikleri birleştirerek kullanınca iyi bir sınıflandırma yapılabilir. Bu yüzden özellikleri birlikte kullanan bir yapıya, yani wrapper'lara ihtiyaç vardır.

## 8. Wrapper: Özellik Alt Kümesi Seçiciler

### 8.1 Kaba kuvvet yaklaşımı

Bir sınıflandırıcı seçilir (örneğin bir karar ağacı) ve ona özellik alt kümeleri verilir. $n$ özellik varsa $2^n$ olası alt küme vardır. Her alt kümeyle sınıflandırıcı eğitilir ve en yüksek başarıyı veren seçilir. Bu dümdüz bir yaklaşımdır ama bedeli $2^n$ eğitimdir (slaytta: "N özellik için olası $2^N$ özellik alt kümesi = $2^N$ eğitim"). Özellik sayısı 3 ise 8 eğitim korkunç değildir; ama 100 özellik için $2^{100}$ eğitim yapılamaz.

### 8.2 Alt küme uzayı ve arama

Slayttaki şekil (Kohavi & John, 1997) dört özellik için 16 alt kümeyi gösterir (ekrandan, 01:25:00). 0,0,0,0 hiçbir özelliğin seçilmediği durumdur; 0,1,0,0 yalnızca ikinci özelliğin; 1,0,0,1 birinci ve dördüncü özelliğin seçildiği durumdur. Oklar bir özellik ekleyerek gidilebilecek komşuları gösterir: 0,0,0,0'dan dört ok çıkar (yalnız birinci, yalnız ikinci, ...); 1,0,0,0'dan üç ok çıkar (1 ve 2, 1 ve 3, 1 ve 4).

Yöntem şöyle ilerler: bulunulan alt kümeyle sınıflandırıcı eğitilir ve başarısı ölçülür, sonra o düğümden çıkan oklardaki alt kümelerle eğitilir. Slayttaki başarılar şunlardır:

| Alt küme | Başarı (%) |
|---|---|
| 0,0,0,0 | 60 |
| 1,0,0,0 | 65 |
| 0,1,0,0 | 69 |
| 0,0,1,0 | 70 |
| 0,0,0,1 | 60 |
| 1,1,0,0 | 90 |
| 1,0,1,0 | 80 |
| 0,1,1,0 | 70 |
| 0,0,1,1 | 75 |
| 1,1,1,0 | 79 |
| 1,0,1,1 | 65 |

Adım adım:

1. 0,0,0,0: %60.
2. Komşular: 65, 69, 70, 60. Bulunulan yerden daha iyi üç seçenek var; en yükseği 0,0,1,0 (%70). Oraya geçilir.
3. 0,0,1,0'ın komşuları: 1,0,1,0 (%80), 0,1,1,0 (%70), 0,0,1,1 (%75). En yükseği %80; geçilir.
4. 1,0,1,0'ın komşuları: 1,1,1,0 (%79), 1,0,1,1 (%65). Hiçbiri 80'den iyi değil; algoritma durur ve "birinci ve üçüncü özelliği seç" sonucunu döndürür.

### 8.3 Hiç özellik yokken tahmin: Zero Rule

Hoca, 0,0,0,0 durumundaki %60'ın nereden geldiğini sordu.

**Soru:** Hiçbir özelliğe bakamıyorsak gelen bir örnek için nasıl tahminde bulunuruz? **Cevap:** Bir öğrenci "tamamına aynı sınıfı veririz" dedi; hangi sınıfı vereceğimiz sorulunca "en çok hangi sınıftan varsa" dedi. Hoca onayladı: örneklerin özellikleri bilinmese de sınıfları bilinir; en fazla örneği olan sınıf bütün örneklere söylenir. Bir sınıftan %60, diğerinden %40 varsa başarı muhtemelen %60 olur.

> **Hocanın vurgusu:** Bu algoritmanın adını unutmayın: Zero Rule. Hiçbir şey yokken de bir performans elde edilebilir; "atmak ama mantıklı atmak".

### 8.4 Bu hangi algoritma?

**Soru:** Bu anlatılan algoritma daha önce görülen hangi algoritmadır? **Cevap:** Bir öğrenci "tepe tırmanma" dedi. Hoca onayladı: bir noktadayız, gidebileceğimiz yerler arasından bizi en yükseğe çıkaran yer bulunduğumuz yerden daha iyiyse oraya gidiyoruz, değilse kalıyoruz.

**Soru:** Bulunan alt kümenin en iyi alt küme olduğundan emin olabilir miyiz? **Cevap:** Hayır. Slayttaki 1,1,0,0 alt kümesinin başarısı %90'dır, ama algoritma bu düğümü hiç görmez; çünkü 0,0,1,0'a geçtikten sonra geri dönüş yoktur. Yerel arama algoritmalarının hepsinin temel problemi budur: global çözümü bulmayı garanti etmezler. Hoca bu noktada, tepe tırmanmanın yerel tepeye takılmasını gösteren bir eğri çizdi (ekrandan, 01:30:00).

**Soru:** En iyi çözümü bulmuyorsa neden kullanırız? **Cevap:** Bir öğrenci "bütün olasılıkları denemek yerine daha hızlı çözüm bulduğu için" dedi. Hoca onayladı.

### 8.5 Karmaşıklık

**Soru:** $2^n$ yerine bu algoritma kaç eğitim yapar? **Cevap:** Bir öğrenci önce "en fazla $n$" dedi; hoca ilk adımda bile $n$ eğitim yapıldığını hatırlattı. İlk adımda $n$, sonraki adımda $n-1$, sonra $n-2$ eğitim yapılır. En sona kadar gidilse bile toplam $1$'den $n$'e kadar sayıların toplamıdır:

$$n + (n-1) + \dots + 1 = \frac{n(n+1)}{2}$$

Bu $n^2$ mertebesindedir. $2^n$ ise bununla karşılaştırılamayacak kadar büyüktür. Örneğin $n = 4$ için en fazla $4 + 3 + 2 + 1 = 10$ eğitim yapılır, bütün alt kümeler ise 16'dır (ara adım eklendi). Tepe tırmanmanın kullanım amacı da buydu: bütün uzayı taramanın çok maliyetli olduğu durumlarda yeterince iyi bir çözüm bulmak.

### 8.6 Ters yön: geriye doğru eleme

Bütün oklar ters çevrilerek de arama yapılabilir: önce bütün özelliklerin seçili olduğu 1,1,1,1'den başlanır, birer birer özellik çıkarılarak ilerlenir. Karmaşıklık aynıdır (yine önce $n$, sonra $n-1$ eğitim...). Biri ekleye ekleye, diğeri çıkara çıkara gider.

**Soru:** Aynı veri kümesi için 0,0,0,0'dan başlayarak bulunan çözümle 1,1,1,1'den başlayarak bulunan çözüm aynı olur mu? **Cevap:** Bir öğrenci "olmayabilir" dedi. Hoca onayladı: tepe tırmanmada başlangıç noktası varılacak yeri çok etkiler. Aynı sonucu da verebilir, ama özellikle $n$ büyükse farklı sonuç verme ihtimali oldukça yüksektir.

> **Ek bilgi (derste anlatılmadı):** Boş kümeden başlayıp ekleyerek ilerleyen aramaya literatürde ileri doğru seçim (sequential forward selection), tüm özelliklerden başlayıp çıkararak ilerleyene geriye doğru eleme (sequential backward elimination) denir.

## 9. Yeni Özelliklerin Çıkarımı: PCA ve LDA

### 9.1 Doğrusal dönüşüm

Var olan özelliklerin doğrusal birleşimlerinden yeni bir özellik uzayı oluşturulur ve veriler bu uzayda ifade edilir. Yaygın kullanılan iki metot PCA ve LDA'dır. İkisinin yaptığı ortak iş şudur (ekrandan, 02:35:00):

$$P_1 = W_1 X_1 + W_2 X_2, \quad P_2 = W_3 X_1 + W_4 X_2, \quad \dots, \quad P_N = W_k X_1 + W_m X_2$$

Yani $x_1, x_2$ boyutları $p_1, p_2$ boyutlarına dönüştürülür; $p_1$'in içinde hem $x_1$ hem $x_2$ vardır, $p_2$'nin içinde de. Bulunması gereken, $W_1, W_2, W_3, W_4$ katsayılarıdır. Her yeni özellik, bütün eski özelliklerin belli oranlarda doğrusal birleşimidir. Bu iki boyutla sınırlı değildir; $X_1, X_2, \dots, X_N$ için de aynısı yazılır.

Yeni özelliklerin hepsinin kullanılması gerekmez; özellik sayısını azaltmak için yalnızca bir kısmı (örneğin yalnızca $P_1$) alınabilir. Hangi yeni özelliğin "daha iyi" olduğu, algoritmanın neye odaklandığına bağlıdır; PCA ve LDA farklı şeylere odaklanır.

### 9.2 Temel bileşen analizi (PCA)

Bu metotta örneklerin en fazla değişim gösterdiği boyutlar bulunur (ekrandan, 01:40:00). Slayttaki şekilde veriler $x_1, x_2$ düzleminde eğik bir bulut halindedir ve algoritma $c_1$ ve $c_2$ eksenlerini bulur. Veriler $c_1$ eksenine izdüşürüldüğünde dağılım geniş, $c_2$'ye izdüşürüldüğünde dardır. $c_1$ eksenindeki değişim daha büyüktür; dolayısıyla veriler iki boyuttan bir boyuta $c_1$ ekseni üzerine izdüşürülerek indirgenebilir.

Algoritma önce izdüşüm sonrası standart sapmanın en büyük olduğu $c_1$'i bulur; sonra bu bileşeni dışarıda bırakıp geri kalanlar içinde yine en büyüğünü arar ve $c_2$'yi bulur. Kritik bir özellik: $c_1$ ve $c_2$ birbirine diktir (ortogonaldir), yani birbiri türünden ifade edilemez. $c_1$ belli bir yöndeyken $c_2$ ona çok yakın bir yönde olamaz, çünkü o zaman ikisi çok ilişkili olur. Bu eksenleri bulmanın çeşitli yolları vardır; derste bunlara girilmedi.

Bu dönüşüm aslında bir döndürmedir: $x_1, x_2$ eksenleri döndürülünce $c_1, c_2$ elde edilir (ölçekleme gibi işlemler de olabilir).

### 9.3 Doğrusal ayırtaç analizi (LDA)

PCA'da yalnızca noktalar vardır; sınıf bilgisi hiç kullanılmaz. Bu yaklaşıma denetimsiz (unsupervised) denir; kullandığı veri türü açısından kümelemeye benzer, ama amaç kümeleme yapmak değildir.

Slayttaki örnekte kırmızı ve mavi noktalar iki sınıftır ve veri iki boyuttan bire indirgenmek istenir (ekrandan, 01:45:00). PCA, izdüşüm sonrası standart sapmanın en büyük olduğu ekseni seçer; bu eksen iki bulutun uzandığı yöndedir. İki boyutta birbirinden çok iyi ayrılan iki sınıf, bu eksene izdüşürülünce korkunç derecede iç içe girer.

LDA bunu çözmek için önerilmiştir. Slayttaki ifadeyle: LDA varyanslara ek olarak sınıf bilgisini de kullanarak boyut indirgeme yapar; sadece varyansa değil, sınıflandırabilmeye de bakar. Slayttaki turkuaz eksen LDA'nın seçtiği eksendir; kırmızılar bu eksenin bir bölgesine, maviler başka bir bölgesine düşer ve iki sınıf iyi ayrılır.

- PCA'nın odağı: verileri açmak, birbirinden uzaklaştırmak, olayın daha rahat görülmesini sağlamak.
- LDA'nın odağı: verileri iyi sınıflandırabilmek.
- LDA'nın gerektirdiği bilgi daha fazladır: PCA sınıf bilgisi olmadan yapılabilir, LDA sınıf bilgisi olmadan yapılamaz. LDA'nın pratikte birkaç kısıtı daha vardır.

İzdüşümün doğrusal olması da zorunlu değildir; kuadratik gibi doğrusal olmayan dönüşümler kullanan yaklaşımlar da vardır, ama derste bunlara girilmedi.

## 10. Ne Zaman Hangi Yöntem

Slayttaki sorular: "Niye bu kadar çok metot var? Ne zaman hangisini kullanacağız?"

> **Hocanın vurgusu:** Her durumda, her veri kümesinde diğerlerinin hepsinden daha iyi olan bir algoritma yoktur. Bu; özellik seçimi, sınıflandırma, kümeleme ve regresyonun hepsinde geçerlidir. Öyle bir algoritma olsaydı yalnızca o anlatılır, diğerleri yalnızca tarihsel önemi olan şeyler olurdu; bu teorik olarak da mümkün değildir.

Seçim için bazı kriterler vardır:

- **Hesaplama maliyeti:** Filter'lar her özellik için bir değerlendirme yapar; $n$ özellik için maliyet $n$'dir. Wrapper'lar (tepe tırmanmayla) $n^2$ mertebesindedir. Filter'lar çok daha hızlıdır; 10 bin özellik için $n^2$ değerlendirme çok uzun sürebilir.
- **Doğruluk:** Wrapper'lar özellik etkileşimlerini görebildiği için daha doğru sonuç verebilir. Maliyet ile doğruluk arasında bir ödünleşim (trade-off) vardır; verilecek karar uygulamadan uygulamaya değişir.
- **Veri türü:** Sayısal veride sinyalin gürültüye oranı, kategorik veride bilgi kazancı doğrudan mantıklıdır. Yine de bilgi kazancını sayısal özelliklerde kullanmak için de çeşitli dönüşüm yöntemleri bulunmuştur; bu konular çok uzun süredir çalışıldığı için hemen her şeyi uygulamanın bir yolu geliştirilmiştir.

> **Ek bilgi (derste anlatılmadı):** "Her problemde en iyi olan tek bir algoritma yoktur" fikri, makine öğrenmesinde büyük olasılıkla en çok Wolpert'in "bedava öğle yemeği yoktur" (No Free Lunch) teoremleri olarak bilinir.

## 11. Sınıflandırma Metotları ve Varsayımları

Özellik seçimi yapmak sınıflandırma için şart değildir; elde bulunan bütün özellikler doğrudan sınıflandırma metotlarına verilebilir.

Slayttaki görev tanımı: önceden etiketlenmiş örnekleri kullanarak yeni örneklerin sınıflarını bulmak (ekrandan, 01:50:00). Slayttaki örnekte mavi ve gri sınıftan örnekler vardır; soru, beyaz noktanın mavi mi gri mi olduğudur. Test kümesinde tek bir örnek, eğitim kümesinde çok sayıda örnek var gibi düşünülebilir. Metotlar: regresyon, karar ağaçları, LVQ, yapay sinir ağları ve diğerleri. Hepsi verileri alır ve sınıfları birbirinden ayıran karar sınırlarını bulmaya çalışır.

Makine öğrenmesi bir model bulmaya çalışır, ama modelin yapısı her algoritmada farklıdır. Her yöntemin kendi varsayımı vardır:

- **Doğrusal regresyon:** Sınıfları ayıran karar sınırı düz bir çizgi, bir düzlem ya da bir hiperdüzlemdir.
- **Karar ağaçları:** Sınıfları ayıran çizgiler özelliklere diktir.
- **LVQ:** Merkezler önemlidir; yerel yakınlık sınıfı belirler, global bir şey kullanmak gereksizdir.
- **Yapay sinir ağları:** Çok daha karmaşık mimariler kurar, dönüşümler yapar.

> **Hocanın vurgusu:** Bir yöntem seçmek, karar sınırlarının yapısı hakkında bir varsayımda bulunmak demektir. Bu varsayım verinin kendi gerçeğiyle uyuşuyorsa algoritma o veri kümesinde iyi çalışır; uyuşmuyorsa iyi çalışmaz.

## 12. Doğrusal Regresyon

### 12.1 Model

Slayttaki model (ekrandan, 01:55:00):

$$w_0 + w_1 x + w_2 y \geq 0$$

Doğrunun bir tarafı mavi, diğer tarafı gri denir. Regresyon en az hata yapan $w_i$'leri bulmaya çalışır. Basit bir modeldir: tek bir çizgiyle ifade edilir, eğitimi de testi de çok hızlıdır. Ama yeterince esnek değildir. Slayttaki veri kümesinde sınıfları tek bir doğruyla ayırmak mümkün görünmez; iki boyutta bu görülebilir. Algoritma yine de "burada çalışmam" demez; doğrusal olarak en iyi ayrılabilecek çizgiyi bulur.

### 12.2 İteratif eğitim

Doğrusal regresyonun doğrudan analitik, tek adımlı çözümleri de vardır; ama büyük miktarda veride bu çözümler bellek problemi yaratır. Onun yerine iteratif çözümler kullanılır: başlangıçta $w_0, w_1, w_2$ rastgele seçilir, yani rastgele bir doğru çizilir. Bu doğrunun neleri doğru, neleri yanlış sınıflandırdığına bakılır ve doğru buna göre güncellenir; adım adım kaydırılır. Artık daha da iyileştirilemeyen bir yere gelince süreç durur.

Bu süreç, derin öğrenme ve yapay sinir ağlarının eğitiminde kullanılan mekanizmanın aynısıdır; orada yalnızca daha fazla parametre vardır ve yapı bu kadar basit değildir. Hata en küçüklenmeye çalışıldığı için bir tepe tırmanma (ya da çukur inme) sürecidir: rastgele bir yerden başlanır ve eğitim kümesi üzerinde optimize edilerek eğitim kümesi için en iyi yere inilir.

### 12.3 Eğitimdeki en iyi, testteki en iyi mi?

Eğitim kümesi için en iyi olan nokta test kümesi için de en iyi olmayabilir. Hoca tek boyutlu bir parametre üzerinde iki hata eğrisi çizdi: siyah eğri eğitim hatası, kırmızı eğri test hatası. Eğitim eğrisinin minimumu, test eğrisinin minimumuyla aynı yerde olmayabilir; ama test kümesi elde olmadığı için yapılabilecek bir şey yoktur, yalnızca eğitim eğrisine göre en iyi yer aranır. Veri kümesi gerçek problemi iyi temsil ediyorsa (yeterince büyük ve iyi toplanmışsa) bu iki eğri birbirine benzemeye, minimumları birbirine yaklaşmaya başlar.

### 12.4 Yorumlanabilirlik

Doğrusal regresyonda ağırlıklara bakarak modelin nasıl karar verdiği anlaşılabilir. Örneğin $x$ ve $y$ aynı aralıkta değer alırken $w_1 = 9$, $w_2 = 0.2$ bulunmuşsa, $w_1$'e karşılık gelen özelliğin sistemin kararına çok daha büyük etkisi vardır.

## 13. Karar Ağaçları

### 13.1 Karar sınırları

Karar ağaçlarının varsayımı doğrusal regresyondan farklıdır. Doğrusal regresyonda sınır üç boyutta bir düzlem, dört ya da on bin boyutta bir hiperdüzlemdir. Karar ağaçlarında ise karar sınırları her bir özelliğe dik olarak oluşturulur; iki boyutta dikdörtgen bölgeler, üç boyutta dikdörtgenler prizması, çok boyutta hiper dikdörtgenler prizmaları oluşur. Bu bir böl ve yönet stratejisidir.

Aynı mavi-gri veri kümesi için karar ağacı birkaç dik sınır üretebilir. Ortaya çıkan ağaç şuna benzer: "$x$ 5'ten büyükse doğrudan mavi sınıfı; değilse $y$ 3'ten küçükse ..." Karar ağaçlarının ürettiği kurallar oldukça anlaşılırdır; ağaç incelenerek algoritmanın nasıl karar verdiği kolayca okunur ve yorumlanır.

### 13.2 Oluşturma algoritması

1. Tüm veri kümesiyle başla.
2. Bir özelliğin bir değerine göre veri kümesini iki alt kümeye böl. Bölmede kullanılan özelliği ve değeri karar düğümüne yerleştir.
3. Her alt küme için aynı prosedürü, her alt kümede yalnızca tek bir sınıfa ait örnekler kalıncaya kadar uygula.

Yapı özyinelemelidir (recursive). Her özyinelemeli fonksiyonun bir durma koşulu olmalıdır; aksi halde sonsuza kadar gider. Buradaki durma koşulu şudur: bir bölge bölünmeden önce içindeki örneklere bakılır; hepsi aynı sınıftansa bölünmez, farklı sınıflardan örnekler varsa bölünür.

Hangi bölmenin seçileceğinde entropi kullanılır. Bir bölme veriyi A ve B diye iki parçaya ayırır; iki parçanın entropileri toplanır ($E_A + E_B$). En mükemmel durumda bir taraf tamamen O, diğer taraf tamamen X olur; iki entropi de 0'dır. Dolayısıyla $E_A + E_B$'nin küçük olması istenir. Bütün olası bölmeler denenir ve en düşük entropi toplamını veren özellik ve eşik karar düğümüne yerleştirilir.

> **Ek bilgi (derste anlatılmadı):** Yaygın uygulamalarda (ID3, C4.5) iki parçanın entropisi doğrudan toplanmaz, parçaların örnek sayısına göre ağırlıklandırılır: $\frac{|A|}{|S|}E_A + \frac{|B|}{|S|}E_B$. Bu, bilgi kazancı formülündeki ikinci terimin aynısıdır. Ağırlıksız toplam, çok küçük ama saf bir parçayı ayıran bölmeleri gereğinden fazla kayırabilir.

### 13.3 Izgara örneği

Slayttaki veri kümesi $x_1 \in \{1,2,3,4\}$ ve $x_2 \in \{1,2,3,4,5\}$ değerlerinden oluşan 20 noktalık bir ızgaradır; O'lar bir sınıf, X'ler diğer sınıftır (ekrandan, 02:05:00):

```text
x2=5 |  o  x  x  x
x2=4 |  o  x  x  x
x2=3 |  o  o  o  x
x2=2 |  o  o  o  x
x2=1 |  x  x  o  o
     +------------
        1  2  3  4   (x1)
```

**Tüm veri.** Bölgede birden fazla sınıftan örnek olduğu için bölünmesi gerekir. Olası bölmeler komşu değerlerin ortalarıdır: $x_1 < 1.5$, $x_1 < 2.5$, $x_1 < 3.5$, $x_2 < 1.5$, $x_2 < 2.5$, $x_2 < 3.5$, $x_2 < 4.5$; toplam 7 bölme vardır, başka olasılık yoktur. Örneğin $x_1 < 1.5$ bölmesi solda 5 nokta (4 O, 1 X), sağda 15 nokta (6 O, 9 X) bırakır; her iki parçanın entropisi hesaplanıp toplanır. Aynı işlem diğer altı bölme için tekrarlanır ve 7 değerin en küçüğü seçilir. Hoca değerleri hesaplamadan "diyelim ki en küçüğü bu çıktı" diyerek slaytta yıldızla işaretli $x_2 < 1.5$ ile devam etti (ekrandan, 02:10:00).

**Alt parça ($x_2 = 1$ satırı: X, X, O, O).** Hepsi aynı sınıftan olmadığı için bölünmeye devam edilir. Bu parçada $x_2$'ye göre bölme yapılamaz; yalnızca $x_1 < 1.5$, $x_1 < 2.5$, $x_1 < 3.5$ adaydır. $x_1 < 2.5$ iki parçayı da saf yapar (sol X, X; sağ O, O), entropi toplamı 0 olur ve seçilir (slaytta yıldızlı). Bu iki bölge bir daha bölünmez; algoritma onlar için kendini çağırmaz.

**Üst parça ($x_2 \geq 2$).** Hâlâ karışık olduğu için bölünür. Adaylar $x_1 < 1.5$, $x_1 < 2.5$, $x_1 < 3.5$, $x_2 < 2.5$, $x_2 < 3.5$, $x_2 < 4.5$'tir; $x_2 < 1.5$ bu bölgede artık yoktur. Slaytta $x_1 < 1.5$ yıldızlıdır (ekrandan, 02:15:00). Sol sütunun hepsi O olduğu için o bölge biter; sağdaki bölge yine bölünmeye devam eder. Süreç, oluşan bütün bölgeler tek sınıftan örnek içerene kadar sürer. Sonunda elde bir karar ağacı olur; düğümlerinde "$x_1$ (ya da $x_2$) şundan küçük mü?" soruları yer alır.

**Soru:** Üstteki bölgeyi nerelerden bölebiliriz? **Cevap:** Bir öğrenci "$x_2$'ye göre, 2.5'un altındakilere göre" dedi. Hoca "böleyim demiyorum, bölebilirim diyorum" diye uyardı: algoritmanın hangi bölmeyi seçeceği değil, denemesi gereken bütün olası bölmeler soruluyor. Algoritma her olası durumu dener.

> **Ders sonrası not:** Slayttaki ızgara değerleriyle python ile yapılan hesap (ağırlıksız $E_A + E_B$):
>
> | Bölme (tüm veri) | Sol (O/X) | Sağ (O/X) | $E_A + E_B$ |
> |---|---|---|---|
> | $x_1 < 1.5$ | 4/1 | 6/9 | 1.693 |
> | $x_1 < 2.5$ | 6/4 | 4/6 | 1.942 |
> | $x_1 < 3.5$ | 9/6 | 1/4 | 1.693 |
> | $x_2 < 1.5$ | 2/2 | 8/8 | 2.000 |
> | $x_2 < 2.5$ | 5/3 | 5/7 | 1.934 |
> | $x_2 < 3.5$ | 8/4 | 2/6 | 1.730 |
> | $x_2 < 4.5$ | 9/7 | 1/3 | 1.800 |
>
> Yani slaytta yıldızlanan $x_2 < 1.5$, iki parçada da sınıflar yarı yarıya olduğu için aslında en kötü bölmedir; yıldız yalnızca anlatım için konmuş bir varsayımdır. En küçük değeri $x_1 < 1.5$ ve $x_1 < 3.5$ (eşit, 1.693) verir. Üst parçada ise $x_1 < 1.5$ gerçekten en küçük değeri verir (0.918; $x_1 < 3.5$ ile eşit). Hoca ayrıca $x_1 < 1.5$'in sol parçasında "5 O, 1 X" saydı; ızgarada sol sütunda 4 O, 1 X vardır.

### 13.4 Gerçek bir karar ağacı ve test

Hoca internetten basit bir ağaç örneği gösterdi (ekrandan, 02:20:00). İki sınıflı bir tıbbi problemdir: benign ve malignant. Kök düğüm "Uniformity of Cell Size ≤ 3?" sorusunu sorar. ≤ 3 ise "Bare Nuclei ≤ 3?", > 3 ise "Marginal Adhesion ≤ 1?" düğümüne gidilir. Alt düğümlerde Normal Nucleoli, Uniformity of Cell Shape, Clump Thickness, Bland Chromatin, Mitoses gibi özellikler ve eşikleri vardır; yapraklar benign ya da malignant kararlarıdır. Örneğin Marginal Adhesion > 1 ise doğrudan malignant denir.

Ağaç oluşturulduktan sonra bir test örneğinin sınıfı şöyle bulunur: örneğin özellikleri bilinir. Örnek kökten bırakılır; ağaç "şu özellik 3'ten büyük mü küçük mü?" diye sorar, cevaba göre bir dala gidilir. Örneğin Uniformity of Cell Size 3'ten küçükse sol dala, orada Bare Nuclei 3'ten küçükse yine sola, Normal Nucleoli 2'den küçükse benign yaprağına düşülür. Örnek yukarıdan bırakılır ve karar düğümlerinden birine düşer. Her iç düğüm tek bir özelliğe ve bir eşik değerine göre bölme yapar.

## 14. Yapay Sinir Ağları

### 14.1 Katmanlar birer dönüşümdür

Yapay sinir ağları çok daha karmaşık karar sınırları üretebilir. Hoca bunu PCA ve LDA'daki doğrusal dönüşüm fikriyle ilişkilendirdi (ekrandan, 02:35:00).

100 örnek ve 10 özellikli bir giriş matrisi $X$ ($100 \times 10$) düşünelim. Bu $10 \times 10$'luk bir $W$ matrisiyle çarpılırsa yeni uzay yine $100 \times 10$ olur. $W$ $10 \times 50$ olsaydı 10 boyutlu uzay 50 boyutlu bir uzaya çıkarılmış, $10 \times 5$ olsaydı 5 boyuta indirilmiş olurdu.

Yapay sinir ağlarında bir giriş uzayı ve ardından gizli katmanlar (hidden layer) vardır. Her gizli katman bu işlemi yapar: giriş uzayı dönüşüme uğrar ve yeni bir uzay olur. Buna bir de doğrusal olmayan bir $f$ fonksiyonu eklenir. Slayttaki boyutlar:

$$X(100 \times 10) \cdot W_1(10 \times 5) = H_1(100 \times 5) \quad \text{(1. gizli katman)}$$

$$H_1(100 \times 5) \cdot W_2(5 \times 40) = H_2(100 \times 40) \quad \text{(2. gizli katman)}$$

$W_1$ tek bir katsayı değil, bir matristir. Her katman bir önceki katmanın çıkışlarını giriş olarak alır; en sonda sınıflandırıcı bir yapı vardır. Bütün eğitim süreci, $W_1$, $W_2$ gibi matrislerin bulunmasıdır.

### 14.2 TensorFlow Playground gösterimi

Hoca tarayıcıda TensorFlow Playground'u açtı. Önce iki sınıflı (mavi ve sarı) basit bir veri kümesinde, girişler, 4 nöronlu tek gizli katman ve çıkıştan oluşan bir ağ çalıştırdı. Buradaki 4, iki boyutlu girişin dört boyutlu bir uzaya çıkarıldığı anlamına gelir; aradaki çizgiler ağırlıklardır. Başlangıçta ağırlıklar rastgeledir ve hiçbir eğitim yoktur. Eğitim başlatılınca ağırlıklar değişti ve iki sınıf yumuşak bir sınırla ayrıldı.

Sonra daha zor bir veri kümesi olan sarmal (spiral) veri seçildi. 2 gizli katmanlı (4 ve 2 nöron), tanh aktivasyonlu, öğrenme oranı 0.03 olan ağda yaklaşık 2943. epokta test kaybı 0.342, eğitim kaybı 0.285 idi (ekrandan, 02:40:00); eğitim kaybı biraz düşse de test kümesinde iyileşme olmuyordu. Hoca mimariyi değiştirdi: gizli katman ve nöron sayısını artırdı, aktivasyonu ReLU yaptı, L1 düzenlileştirme (regularization) ekledi ve girişlere $x_1, x_2$'nin yanında $x_1^2$, $x_2^2$, $x_1 x_2$ gibi türetilmiş özellikleri ekledi. 5 gizli katmanlı (4, 5, 5, 4, 2 nöron) bu ağda yaklaşık 4357. epokta test kaybı 0.089, eğitim kaybı 0.000 oldu (ekrandan, 02:45:00). Sonuç oldukça iyiydi; ama bazı bölgelerin mavi kalması iyi değildir, çünkü test örnekleri oralardan da gelebilir.

Hoca epok gibi kavramlara girmedi; yapay sinir ağlarının başlı başına bir ders konusu olduğunu, burada yalnızca temel mantığın anlatıldığını söyledi.

## 15. Hiperparametre Kavramı

Hiperparametre, algoritmanın çalışması için ihtiyaç duyduğu ama kendisinin belirleyemediği parametrelerdir. Algoritmanın çalışması için bunlara bir değer atanması gerekir, ama algoritma bunları kendisi bulamaz.

- **Yapay sinir ağlarında:** kaç gizli katman olacağı, her katmanda kaç nöron olacağı, aktivasyon fonksiyonu, öğrenme oranı (learning rate).
- **Genetik algoritmalarda:** mutasyon oranı, kaç noktadan bölme (çaprazlama) yapılacağı, popülasyon büyüklüğü.
- **k-NN'de:** $k$.

Hiperparametre ne kadar çok olursa algoritma o kadar esnek olur, ama deneme yanılma süreci de o kadar uzar. Playground'daki eğitim kısa sürdü; ama büyük verilerle eğitilen büyük mimarilerde bir eğitim bir hafta sürebilir. Her denemenin bu kadar uzun sürmesi, hiperparametreleri o veri kümesi için optimize etmeyi çok zorlaştırır. Klasik yapay sinir ağlarına göre derin mimarilerde hiperparametreler çok daha fazladır; mimarinin kendisinin de tasarlanması gerekir. Örneğin bir resim için metin üretmede (caption generation) resmi ve metni nasıl temsil edeceğimiz, bunları nasıl birleştireceğimiz, çıkışta hangi kaybı (loss) kullanacağımız gibi pek çok seçim vardır.

## 16. En Yakın K Komşu

### 16.1 Algoritma

En yakın $k$ komşu algoritması, "Bana arkadaşını söyle, sana kim olduğunu söyleyeyim" atasözünün algoritmaya dönüşmüş halidir (ekrandan, 02:50:00). $k$ bir hiperparametredir.

Diğer yöntemlerden farkı, bir eğitim (modelleme) süreci olmamasıdır. Doğrusal regresyonda $w$'ler, karar ağacında ağacın kendisi, yapay sinir ağında ağırlıklar bulunur; burada eğitim süresi sıfırdır.

Bir test örneğinin sınıfı şöyle bulunur: ona en yakın $k$ eğitim örneği bulunur ve bunların çoğunluğunun sınıfı söylenir. Slayttaki şekilde mavi kafalı figür test örneği, siyah ve beyaz kafalılar eğitim örnekleridir (beyazlar A, siyahlar B).

- $k = 1$: Test örneğine en yakın eğitim örneği beyaz (A) olduğu için sınıf A olur.
- $k = 3$: En yakın üç eğitim örneği dairenin içindekilerdir: B, B, A. B daha çok olduğu için sınıf B olur.

Yani aynı örnek için en yakın 1 komşu A, en yakın 3 komşu B der.

### 16.2 Test için ne gerekir?

**Soru:** Bir test örneğinin sınıfını bulmak için elimizde ne olmalıdır? **Cevap:** Hoca önce diğer yöntemleri hatırlattı: doğrusal regresyonda yapı zaten doğrusal olduğu için $w$'leri bilmek yeter; karar ağacında ağacın kendisi yeter; yapay sinir ağında mimari ve ağırlıklar yeter. k-NN için bir öğrenci "eğitim verisinin tamamını elimizde tutmamız gerekir" dedi. Hoca onayladı: modelleme yapılmadığı için eğitim kümesinin tamamı saklanmalıdır.

Algoritmanın kodlaması çok kolaydır. Ama eğitim kümesi çok büyükse (binlerce örnek) her test örneği için en yakınları bulmak çok uğraştırır; test süresi korkunç hale gelebilir ve çok büyük miktarda veri saklamak gerekir. Bu, algoritmanın kötü tarafıdır.

Bir sonraki derste LVQ ile devam edileceği söylendi.

## Örnek Sorular

**1. (ekrandan, 00:20:00)** Aşağıdaki tabloda hangi özellik sınıfı belirlemek için en anlamlıdır? Hangisi hiç bilgi taşımaz?

| 1. Öz | 2. Öz | 3. Öz | Sınıf |
|---|---|---|---|
| 1 | 3 | 13 | A |
| 2 | 3 | 13 | B |
| 1 | 4 | 13 | A |
| 2 | 3 | 13 | B |

> **Çözüm (derste verildi):** 1. özellik sınıfı tam belirler (1 → A, 2 → B). 2. özellik kısmen bilgi verir (4 → A; 3 olanların ikisi B, biri A). 3. özellik bütün örneklerde 13 olduğu için hiçbir bilgi taşımaz.

**2. (derste sözlü, 00:40:12)** 6 örneğin 3'ü A, 3'ü B ise entropi nedir? Hepsi A ise entropi nedir?

> **Çözüm (derste verildi):** $-(0.5\log_2 0.5 + 0.5\log_2 0.5) = 1$; hepsi A ise $-(1 \cdot \log_2 1) = 0$. İki sınıflı bir kavramın entropisi en fazla 1'dir.

**3. (ekrandan, 00:45:00)** Pikniğe gidilen 4 olayın 3'ünde cevap evet, 1'inde hayırdır. Hava güneşliyken (3 olay) hepsinde gidilmiş, yağmurluyken (1 olay) gidilmemiştir. $Gain(Piknik, Hava)$ nedir? Bütün olaylarda rüzgar "güçlü" ise $Gain(Piknik, \text{Rüzgar})$ nedir?

> **Çözüm (derste verildi):** $Entropy(Piknik) = -\frac{3}{4}\log_2\frac{3}{4} - \frac{1}{4}\log_2\frac{1}{4} = 0.811$. Havanın iki alt kümesi de saf olduğu için entropileri 0'dır: $Gain = 0.811 - \frac{3}{4} \cdot 0 - \frac{1}{4} \cdot 0 = 0.811$. Rüzgarın tek değeri olduğu için $Gain = 0.811 - 1 \cdot 0.811 = 0$.

**4. (ekrandan, 00:55:00)** Satranç tahtası biçiminde dağılmış iki sınıflı bir veride (sol üst ve sağ alt bir sınıf, sağ üst ve sol alt diğer sınıf) $x_1$ mi daha iyi özelliktir, $x_2$ mi? Filter yöntemleri bu veride ne sonuç verir?

> **Çözüm (derste verildi):** İkisi eşittir ve tek başlarına ikisi de işe yaramaz; her iki eksende sınıfların histogramları üst üste biner. Filter'lar iki özelliği de değersiz bulur. Oysa iki özellik birlikte kullanılınca basit kurallarla kusursuz sınıflandırma yapılır; bu durumu wrapper yöntemleri yakalayabilir.

**5. (ekrandan, 01:25:00)** Slayttaki alt küme uzayında (dört özellik) başarılar şöyledir: 0,0,0,0 → 60; 1,0,0,0 → 65; 0,1,0,0 → 69; 0,0,1,0 → 70; 0,0,0,1 → 60; 1,1,0,0 → 90; 1,0,1,0 → 80; 0,1,1,0 → 70; 0,0,1,1 → 75; 1,1,1,0 → 79; 1,0,1,1 → 65. Boş kümeden başlayan tepe tırmanma hangi alt kümeyi bulur? Bulunan çözüm en iyi midir?

> **Çözüm (derste verildi):** 0,0,0,0 (60) → 0,0,1,0 (70) → 1,0,1,0 (80). Komşular 79 ve 65 olduğu için durur; birinci ve üçüncü özellik seçilir. En iyi değildir: 1,1,0,0'ın başarısı 90'dır ama bu düğüme hiç bakılmaz.

**6. (derste sözlü, 01:25:05)** Hiçbir özelliğe bakamıyorsak, sınıfların %60'ı bir sınıftan, %40'ı diğerinden olan bir veride nasıl tahmin yaparız ve başarımız ne olur?

> **Çözüm (derste verildi):** Zero Rule: bütün örneklere en kalabalık sınıf söylenir; başarı yaklaşık %60 olur.

**7. (derste sözlü, 01:30:40)** $n$ özellikte bütün alt kümeleri denemek $2^n$ eğitim gerektirir. Tepe tırmanma tabanlı wrapper en fazla kaç eğitim yapar?

> **Çözüm (derste verildi):** $n + (n-1) + \dots + 1 = \frac{n(n+1)}{2}$, yani $n^2$ mertebesi. $2^n$ bundan çok çok büyüktür.

**8. (derste sözlü, 01:33:18)** 0,0,0,0'dan başlayıp özellik ekleyerek ilerleyen arama ile 1,1,1,1'den başlayıp özellik çıkararak ilerleyen arama aynı alt kümeyi bulur mu?

> **Çözüm (derste verildi):** Bulmayabilir. Tepe tırmanmada başlangıç noktası sonucu çok etkiler; özellikle özellik sayısı büyükse farklı sonuç verme olasılığı yüksektir. Karmaşıklıkları aynıdır.

**9. (ekrandan, 02:05:00)** Aşağıdaki ızgara verisinde karar ağacının kökü için denenecek bütün bölmeleri yazın ve her biri için iki parçanın entropileri toplamını ($E_A + E_B$) hesaplayın. Hangisi seçilir?

```text
x2=5 |  o  x  x  x
x2=4 |  o  x  x  x
x2=3 |  o  o  o  x
x2=2 |  o  o  o  x
x2=1 |  x  x  o  o
     +------------
        1  2  3  4   (x1)
```

> **Çözüm (derste verilmedi):** Bölmeler: $x_1 < 1.5, 2.5, 3.5$ ve $x_2 < 1.5, 2.5, 3.5, 4.5$ (7 bölme). Python ile hesaplanan $E_A + E_B$ değerleri sırasıyla 1.693, 1.942, 1.693, 2.000, 1.934, 1.730, 1.800'dür. En küçük değeri $x_1 < 1.5$ ve $x_1 < 3.5$ (1.693) verir; eşitlik varsa ilk bulunan ($x_1 < 1.5$) seçilebilir. Derste anlatım kolaylığı için $x_2 < 1.5$ seçilmiş varsayılmıştı; bu bölme gerçekte en büyük değeri verir. Örneğin $x_1 < 1.5$ için sol parça 4 O, 1 X: $E_A = -\frac{4}{5}\log_2\frac{4}{5} - \frac{1}{5}\log_2\frac{1}{5} = 0.722$; sağ parça 6 O, 9 X: $E_B = -\frac{6}{15}\log_2\frac{6}{15} - \frac{9}{15}\log_2\frac{9}{15} = 0.971$; toplam 1.693.

**10. (ekrandan, 02:10:00)** Aynı veride $x_2 < 1.5$ ile bölündükten sonra alttaki parça (X, X, O, O) için hangi bölmeler denenebilir ve hangisi seçilir?

> **Çözüm (derste verildi):** Bu parçada $x_2$'ye göre bölme yapılamaz; adaylar $x_1 < 1.5$, $x_1 < 2.5$, $x_1 < 3.5$'tir. $x_1 < 2.5$ iki parçayı da saf yapar (entropi toplamı 0) ve seçilir.

**11. (ekrandan, 02:50:00)** Slayttaki şekilde test örneğine en yakın eğitim örneği A sınıfındadır; en yakın üç örnek ise B, B ve A'dır. 1-NN ve 3-NN hangi sınıfı söyler?

> **Çözüm (derste verildi):** 1-NN A, 3-NN çoğunluk oyuyla B der.

**12. (derste sözlü, 02:48:41)** k-NN ile bir test örneğinin sınıfını bulmak için elde ne bulunmalıdır? Bunun dezavantajı nedir?

> **Çözüm (derste verildi):** Eğitim kümesinin tamamı saklanmalıdır, çünkü modelleme yapılmaz. Eğitim kümesi büyükse test süresi çok uzar ve çok büyük miktarda veri saklamak gerekir.

## Dersin Toparlaması

Bu derste önce, elimizdeki her özelliğin çıkışı belirlemede eşit derecede yararlı olmadığı görüldü ve özellik belirlemenin iki yolu ele alındı. Var olan özelliklerden seçim yapan filter yöntemleri (kategorik veri için bilgi kazancı, sayısal veri için sinyalin gürültüye oranı) her özelliği tek başına değerlendirir ve hızlıdır; ama satranç tahtası örneğindeki gibi özelliklerin ancak birlikte anlam kazandığı durumları göremez. Wrapper yöntemleri alt kümeleri bir sınıflandırıcıyla dener; $2^n$ alt kümenin hepsi yerine tepe tırmanmayla $n^2$ mertebesinde eğitimle iyi ama global en iyisi garanti olmayan bir alt küme bulur. Özellik seçmek yerine yeni özellik türeten PCA en çok varyansı, LDA ise sınıfların en iyi ayrılmasını hedefleyen doğrusal dönüşümler bulur.

Ardından sınıflandırma metotlarına geçildi. Her metodun karar sınırının yapısı hakkında bir varsayımı olduğu, bu varsayım veriyle uyuştuğunda metodun iyi çalıştığı vurgulandı ve her durumda en iyi olan bir algoritma bulunmadığı hatırlatıldı. Doğrusal regresyon (düz sınır, iteratif eğitim), karar ağaçları (özelliklere dik sınırlar, entropiyle bölme), yapay sinir ağları (her katmanda bir dönüşüm) ve eğitimsiz ama testi pahalı olan en yakın $k$ komşu anlatıldı; hiperparametre kavramı tanıtıldı. Sonraki derste LVQ ile devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
