# Ders 5 Çalışma Özeti

## Genel Konular

- Optimizasyon ödevi üzerine kısa tartışma
  - Çok boyutlu konveks fonksiyonun en basit örneği her değişkenin karesinin toplamıdır: $y = x^2$, iki boyutta $x_1^2 + x_2^2$ (yarım küre ya da kase gibi), üç boyutta $x_1^2 + x_2^2 + x_3^2$. Önce iki boyutta çalışan bir kod yazıp sonra çok değişkenliye genişletmek önerildi.
  - Parametreye göre doğrusal bir model yazılırsa onun karesel kayıp fonksiyonu konveks olur.
  - $\alpha f(x_1) + \beta f(x_2)$ biçimindeki koşullar konveksliği değil doğrusallığı tanımlar.
  - Ödevdeki görselleştirmenin amacı: 10 boyutlu uzayda her iterasyonda bir nokta elde edilir; bu noktaların dizisi PCA ya da t-SNE ile 2 boyuta indirilerek optimizasyon algoritmasının izlediği yörünge görülür. Amaç, 2 boyutta gözlenen davranışın 10 boyutta da sürüp sürmediğini görmektir.
- Karar ağaçlarının varsayımı ve formal tanımı
  - Varsayım: veri uzayı $M$ adet kesişmeyen bölgeye ($R_m$) ayrılır ve her bölgede tek bir çıkış ($c_m$) üretilir.
  - Her algoritma bir varsayımdır. Doğrusal regresyon regresyonda verinin bir düzlem üzerinde olduğunu, sınıflandırmada sınıfların bir (hiper)düzlemle ayrılabildiğini varsayar. Verinin gerçeği ile algoritmanın varsayımı uyumluysa algoritma iyi çalışır.
  - Ağacın bir $x$ örneği için çıkışı: $\hat{y} = T(x) = \sum_{m=1}^{M} c_m I_{R_m}(x)$; $I_A(x) = 1$ eğer $x \in A$, değilse $0$ (ekrandan, 00:20:00). Bölgeler kesişmediği için toplamda yalnız $x$'in düştüğü bölgenin $c_m$ değeri kalır.
- Ağacı bulmak bir optimizasyon problemidir
  - Veri: $D = \{(x_i, y_i)\}_{i=1}^{N}$, $\hat{y}_i = T(x_i)$, kayıp $L(y_i,\hat{y}_i) = (y_i - \hat{y}_i)^2$, ağacın kaybı $L(T) = \sum_{i=1}^{N} (y_i - T(x_i))^2$.
  - Optimizasyon tanımı: $\{\hat{c}_m, \hat{R}_m\}_1^M = \underset{\{c_m, R_m\}_1^M}{\operatorname{argmin}} \sum_{i=1}^{N} \left[y_i - \sum_{m=1}^{M} c_m I_{R_m}(x_i)\right]^2$ (ekrandan, 00:30:00).
  - Bilinenler $x$ ve $y$'dir; aranan $M$ tane bölge ve $M$ tane çıkıştır. $c_m$ ile $R_m$ birlikte aranması gereken birleşik (koşullu) bir optimizasyon problemidir, çok zordur.
  - Kolaylaştırma 1: bölgeler hiperküp (eksenlere paralel hiperdikdörtgen) olsun. Hâlâ çok zor.
  - Kolaylaştırma 2: iteratif algoritma. Başta tek bir $R$ (bütün uzay) olur; ikiye bölünür, çıkan bölgeler yine ikiye bölünür (yeterince iyi bölgeler elde edilene kadar).
  - Bu yaklaşım optimum ağacı (aynı başarıda en az bölgeli ağacı) garanti etmez; yerel aramaya benzer. Yine de karar ağaçları başarılı sonuçlar verir.
- Ağacı oluşturmak (regresyon)
  - Tek bir bölgenin çıkışı, içindeki $K$ örneğin çıkışlarının ortalamasıdır (tek $R$ varsa $K = N$).
  - Bölgenin kaybı: $L(R) = \frac{1}{K}\sum_{x \in R} (y_i - \mathrm{mean}(\{y_i\}_1^K))^2$ (ekrandan, 00:40:00).
  - $j$. özelliğin $s_j$ değerine göre $R$ ikiye ($R_L$, $R_R$) bölünür. Bölmenin iyiliği: $Imp(j, s_j) = L(R) - L(R_L) - L(R_R)$. Bütün olası $(j, s_j)$ ikilileri denenir, en büyük $Imp$ seçilir. $L(R)$ hepsinde aynı olduğundan $L(R_L) + L(R_R)$ toplamı en küçük olanı seçmek de aynı sonucu verir.
  - Aday eşikler: sayısal özellikte değerler sıralanıp ardışık değerlerin orta noktaları denenebilir ya da min-max arasında eşit aralıklı eşikler alınabilir. Kategorik özellikte bütün değerler denenir.
  - Seçilen bölme karar düğümü olur; çıkan iki bölgeye aynı işlem tekrar uygulanır.
- Sınıflandırma için çıkış ve durma ölçütleri
  - Sınıflandırmada bölgenin çıkışı, o bölgedeki örneklerden en sık görülen sınıftır.
  - Durma ölçütleri (ekrandan, 00:45:00): maksimum derinlik, bölgenin saflığı/düzgünlüğü, minimum yaprak büyüklüğü. Bunlar hiperparametredir.
  - Saflık (sınıflandırma): bölgedeki bütün örnekler aynı sınıftan olana kadar (%100 saflık) ya da örneğin %90 saflığa kadar bölünür.
  - Düzgünlük (regresyon): bölgedeki çıkışların standart sapması bir eşiğin üstünde olduğu sürece bölünür. Standart sapma sıfırsa bölgedeki bütün çıkışlar aynıdır (ya da bölgede tek örnek vardır).
  - Eşik sıfır alınırsa regresyon ağacı her farklı çıkış değeri için ayrı bir basamak üreten, atlamaları ardışık noktaların ortasında olan bir basamak fonksiyonu üretir (ekrandan, 01:00:00).
- Tek değişkenli ve çok değişkenli karar ağaçları
  - Klasik (univariate) ağaçta düğüm tek özellik sorar ("$x_3 > 2.45$ mi?"); bölgeler eksenlere dik sınırlarla ayrılır, eğri sınır üretilemez.
  - Çok değişkenli (multivariate) ağaçta düğüm "$w_1x_1 + w_2x_2 > 3.48$ mi?" gibi sorar; eğik sınırlar oluşur, bölgeler artık hiperküp değildir.
- Karar ağaçlarının özellikleri
  - Çıkışla ilgisiz özelliklerle başa çıkarlar; ağaçta hiç kullanılmayan özellikler olabilir, yani otomatik özellik seçimi yaparlar. Her özellik için önem skoru hesaplanabilir.
  - Sayısal ($x_j \le$ eşik) ve kategorik ($x_j =$ değer) özelliklerle çalışırlar.
  - Ölçek farklılığından etkilenmedikleri için normalizasyon gerekmez (çok değişkenli ağaçlarda gerekir).
  - Hızlı üretilirler: $n$ özellik, $N$ örnek için ortalama derinlik $\log N$, her seviyede $N$ örnek $n$ özellik için işlenir; karmaşıklık $O(n N \log N)$.
  - Eksik özelliklerle başa çıkarlar: kategorik özellik için "eksik" adlı bir kategori olabilir; surrogate (vekil) özelliklerle bir özellik eksikse sırayla hangi özelliklere bakılacağı belirlenir (ekrandan, 01:05:00).
  - Az sayıda hiperparametre, deterministik (aynı veriyle hep aynı sonuç), yorumlanabilir model.
- Karar ağaçlarının kısıtları
  - Sürekli olmayan çıkışlar (merdiven etkisi): eğik bir sınır ancak çok sayıda örnekle küçük basamaklara yaklaşabilir.
  - Derinlere inildikçe düğümleri belirleyen örnek sayısı azalır.
  - Özellikler çıkışı etkileşimsiz etkiliyorsa ($f(x) = \sum_j a_j x_j$) iyi değildir; çünkü her bölge kökten kendisine kadar bütün kararlara bağlıdır, yani bölgeler etkileşimi ifade eder.
  - Çıkış çok fazla özelliğe bağlıysa çok derin ağaç oluşur, derinlerde örnek azdır (ör. resim pikselleri).
  - Eğitim kümesindeki küçük değişimler ağaçta büyük değişimlere yol açabilir; bu farklılığa varyans denir (ekrandan, 01:30:00).
  - Aç gözlü algoritma nedeniyle yukarıda yapılan bir yanlış hiç düzeltilmez.
  - Özellikler arası korelasyon yüksekse farklı görünüşlü ağaçların tahminleri benzer olabilir.
- Algoritma, optimallik ve alternatifler
  - Aç gözlü yaklaşım optimal ağacı oluşturmaz; optimal ağacı bulmak NP türünden zor bir problem olduğu için tercih edilir.
  - Karar ağacı her eğitim kümesine tam uyum sağlayabilir; tek istisna aynı noktada farklı sınıftan örnekler olmasıdır (bu durumda hiçbir algoritma %100'e ulaşamaz).
  - Alternatifler: birden fazla özelliğe bağlı düğümler (multivariate), ikiden fazla dal, birkaç seviye ileriye bakarak bölme seçmek.
- Çevrimiçi / artımlı algoritmalar
  - Yeni örnekler gelince baştan eğitim gerektirmeyen algoritmalardır; çok büyük veri kümeleri ve dağılım değişimi olan problemler için uygundur, herhangi bir anda tahmin üretebilirler (ekrandan, 01:35:00).
  - Örnek: duygu analizi modeli zamanla kötüleşir, çünkü dil yaşar ve yeni jargon çıkar.
  - YSA'lar, LVQ, SOM, çevrimiçi K-means çevrimiçidir. Klasik karar ağaçları değildir, ama çevrimiçi sürümleri (Hoeffding ağaçları) vardır.
- Ödev sunumlarından çıkan akademik noktalar
  - Öğrenciler 10 boyutlu konveks ve konveks olmayan fonksiyonlarda (küre, döndürülmüş hiperelipsoid, Rastrigin, Bohachevsky, Ackley vb.) gradyan inişi, Adam ve koordinat inişini karşılaştırdı.
  - Konveks fonksiyonlarda her başlangıçtan aynı noktaya varıldı; konveks olmayanlarda farklı yerel minimumlara takılma ve büyük adımda ıraksama görüldü.
  - Koordinat inişi bir seferde tek boyutu güncellediği için merdiven gibi, tırtıklı yörüngeler üretti.
  - Bir öğrenci konveksliği 10x10 Hessian matrisinin özdeğerleriyle sınadı: $f_4 = x_1x_2 + x_3x_4 + \dots + x_9x_{10}$ fonksiyonunun özdeğerleri $\pm 1$ olduğu için konveks değildir (ekrandan, 02:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Her algoritma bir varsayımdır
  - Algoritma seçmek varsayım seçmektir. Gerçek veriye değil, ondan alınmış örneğe erişilir; algoritmanın varsayımı verinin gerçeğine uyuyorsa algoritma iyi çalışır.
- Karar ağacı yorumlanabilirdir
  - Ağaca bakarak karar sürecinin nasıl oluştuğu açıkça görülür; bu, karar ağaçlarını popüler yapan özelliktir.
- Birleşik optimizasyondan aç gözlü bölmeye
  - Optimal ağaç bulunamadığı için yerel arama benzeri bir yaklaşım kullanılır; yukarıda yapılan hata düzeltilemez.
- Varyans kollektif öğrenmede avantaja dönüşür
  - Eğitim kümesindeki küçük değişimin ağacı çok değiştirmesi tek ağaç için kötüdür, ama birden fazla ağaç kullanan kollektif öğrenmede iyi bir özellik hâline gelir. Derinlerde örnek azalması gibi sorunlar da çok ağaç kullanarak aşılacak.
- Adam her zaman gradyan inişini yenmez
  - Adam derin öğrenmede yaygın kullanılır, ama deneylerde her durumda daha iyi olmadığı görülür; gradyan inişi gözden düşmüş değildir.

## Kısa Tekrar Notları

- Karar ağacı: uzay $M$ kesişmeyen bölgeye bölünür, her bölgede tek çıkış.
- $T(x) = \sum_m c_m I_{R_m}(x)$; yalnız $x$'in bölgesinin $c_m$'i kalır.
- Optimal ağaç: $c_m$ ve $R_m$ birlikte argmin; çok zor. Çözüm: hiperküp bölgeler + iteratif ikiye bölme.
- Regresyonda bölge çıkışı = ortalama; sınıflandırmada = en sık sınıf.
- Bölme iyiliği $Imp(j,s_j) = L(R) - L(R_L) - L(R_R)$; en büyüğü seçilir.
- Durma: maksimum derinlik, saflık (sınıflandırma), standart sapma eşiği (regresyon), minimum yaprak büyüklüğü.
- Univariate ağaç: eksene dik sınırlar; multivariate ağaç: eğik sınırlar, normalizasyon gerekir.
- Artılar: özellik seçimi, sayısal + kategorik, normalizasyon gerekmez, $O(nN\log N)$, eksik veri (surrogate), deterministik, yorumlanabilir.
- Eksiler: merdiven etkisi, derinde az örnek, toplamsal ilişkide kötü, yüksek varyans, aç gözlü hata düzeltilmez.
- Çevrimiçi algoritmalar baştan eğitim gerektirmez; karar ağaçlarının çevrimiçi sürümü Hoeffding ağaçlarıdır.
- Konvekslik sınaması: Hessian pozitif tanımlı mı; pratikte farklı başlangıçlardan aynı noktaya varılıyor mu.

## Detaylı Açıklamalar

- Karar ağacının matematiksel tanımı $T(x) = \sum_{m=1}^{M} c_m I_{R_m}(x)$ biçimindedir. Göstergeç fonksiyonu $I_A(x)$, $x$ bölgenin içindeyse 1, değilse 0 verir. Bölgeler kesişmediği için her $x$ yalnız bir bölgeye düşer; toplamdaki bütün terimler sıfır olur, yalnız o bölgenin çıkışı kalır. Ağacı eğitmek, karesel hatayı en küçük yapan bölgeleri ve çıkışları bulmaktır. Bu, önceki haftalardaki tek bir $x$ arayan optimizasyonlardan farklı olarak $M$ bölge ve $M$ çıkışı birlikte arayan birleşik bir problemdir. Bölgelerin sayısı ve biçimi bile tanımda yoktur: üçgen, daire, eğik bölgeler olabilirdi. Arama uzayını daraltmak için önce bölgeler eksenlere paralel hiperdikdörtgenlerle sınırlandırılır, sonra bölgeler tek tek tanımlanmak yerine bütün uzaydan başlayıp tekrar tekrar ikiye bölünerek elde edilir. Her adımda bölge sayısı kabaca iki katına çıkar.
- Bir bölmenin seçilmesi için her özellik ve her aday eşik denenir. Regresyonda bölgenin kaybı, çıkışların bölge ortalamasından sapmalarının karelerinin ortalamasıdır, yani bölgedeki çıkışların varyansıdır. Bölme sonrası çocuk bölgelerin kayıpları ne kadar küçükse $Imp$ o kadar büyük olur. Seçilen bölme ağaca karar düğümü olarak eklenir, iki yeni bölgeye aynı işlem uygulanır.
- Regresyon örneğinde (ekrandan, 00:55:00) tek boyutlu girdide altı nokta vardı: üçü düşük, üçü yüksek bir düzeyde. Tek bölgeyle çıkış bütün noktaların ortalaması olan yatay bir doğrudur. Beş olası bölmeden iki grubun arasından bölmek en iyisidir; her iki tarafta da çıkışlar aynı düzeyde olduğu için standart sapma sıfırlanır ve bölme durur. Noktalar farklı yüksekliklere kaydırılınca, durma eşiği sıfırken ağaç her farklı değer için ayrı basamak üretir; atlamalar ardışık noktaların tam ortasında olur (ekrandan, 01:00:00). Aynı çizgi üzerindeki noktalar için ayrı basamak üretilmez. Klasik ağaç bu yüzden eğri bir fonksiyon üretemez, yalnız basamaklar üretir.
- Eksik değer konusunda bir öğrenci sorusu üzerine: eksik değer içeren örneği silmek ya da özelliğin ortalamasını yazmak yaygın yaklaşımlardır. Surrogate düğümler eksik değer için de kullanılabilir. Ama bazen verinin eksik olmasının kendisi sınıfla ilgili bilgi taşır; bu durumda "eksik" değeri ayrı bir kategori olarak almak daha makul olabilir.
- Çevrimiçi algoritmalar örnekleri tek tek ya da mini-batch hâlinde alıp modeli günceller. Klasik karar ağacı her bölmede bütün örneklerin bütün özelliklerine baktığı için çok büyük veride belleğe sığmayabilir. Hoeffding ağaçlarında ağaç bir kez üretilip bitmez, yeni örnekler geldikçe güncellenir.
- Ödev sunumlarında hocanın açıklamaları: PCA ile t-SNE farklı varsayımlarla izdüşüm yaptığı için yörüngeler birebir aynı olmak zorunda değildir, aralarında dönme ve öteleme farkı olabilir. Adam'da konveks fonksiyonda kaybın dalgalanması momentum etkisidir: huni biçimli bir yüzeyde ileri itilen bir top genel olarak aşağı iner, ama önceki hızı yüzünden ara ara yukarı çıkar. Yörünge çizimi için kaybın değil, her iterasyondaki 10 boyutlu noktanın kendisinin saklanıp 2 boyuta indirilmesi gerekir.

<!-- BELİRSİZ: Slayt 3 (T'yi bulmak), slayt 8 (özellikler, ilk kısım), slayt 10 (kısıtlar, ilk kısım) ve slayt 12 (algoritma) için tam ekran kare yok; bu kısımlar altyazıdan yazıldı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
