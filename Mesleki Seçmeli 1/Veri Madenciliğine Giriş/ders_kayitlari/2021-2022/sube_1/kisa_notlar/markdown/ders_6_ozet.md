# Ders 6 Çalışma Özeti

## Genel Konular

- Ayrıklaştırma (discretization) yöntemlerinin devamı
  - Sürekli (continuous) değerleri ayrık değerlere dönüştürmenin yolları ele alındı: binning, kümeleme ile ayrıklaştırma ve sınıflandırma (karar ağacı) ile ayrıklaştırma.
  - Eşit genişlikli (equal-width) binning: değer aralığı eşit genişlikte parçalara bölünür, her parçaya bir etiket (1, 2, 3 gibi) verilir. Bu işlem aslında bir if-else zinciri gibidir.
  - Eşit frekanslı (equal-frequency) binning: değerler sıralanır, her bine eşit sayıda eleman düşecek şekilde bölünür. Derste 12 elemanlı bir örnekte ilk dört eleman birinci bine, sonraki dört ikinci bine, son dört üçüncü bine konduğu anlatıldı.
  - Binning sınıf etiketi (label) kullanmaz; yalnız değerlere bakar. Bu nedenle denetimsiz (unsupervised) bir yöntemdir ve aslında basit bir kümeleme tekniği sayılabilir.
  - Kümeleme ile ayrıklaştırma: sıralı değerler arasındaki en büyük boşluk (gap) bulunur ve veri oradan ikiye ayrılır; ardından sıradaki en büyük boşluktan tekrar ayrılır. Kaç küme oluşacağı kullanıcıya bağlıdır. Bu yöntem de etiket kullanmadığı için denetimsizdir.
  - Sınıflandırma ile ayrıklaştırma: karar ağacı gibi sınıflandırma teknikleri ayrıklaştırmada kullanılabilir (ekrandan, 00:05:00). Bu yaklaşım sınıf etiketi bilgisini kullandığı için denetimlidir (supervised). Yukarıdan aşağı bölme (top-down splitting) yapılır; bölme noktaları, oluşan her parçada mümkün olduğunca aynı sınıftan örnek kalacak şekilde seçilir. Bunun için en sık kullanılan ölçü entropidir.
- Kavram hiyerarşisi (concept hierarchy)
  - Piramit ya da ağaç gibi düşünülür: her üst seviye alt seviyedekileri kapsar.
  - Veri tabanında hazır bulunabilir, istatistiksel analizden (örneğin entropi ile) çıkarılabilir ya da elle oluşturulabilir.
  - Fiyat örneği: 0-1000 dolar arası fiyatlar önce büyük aralıklara (0-200, 200-400 gibi), sonra daha küçük aralıklara bölünür. Aralıkların eşit olması gerekmez. Üst seviye seçilince az sayıda ayrık değer, alt seviye seçilince daha çok ayrık değer elde edilir.
  - Nominal öznitelik örnekleri: zaman için yıl, çeyrek, ay, gün (ve paralel olarak hafta); konum için ülke, eyalet, şehir.
- Veri azaltma (data reduction)
  - Tanım: veri kümesinin hacimce çok daha küçük, ama aynı (ya da neredeyse aynı) analiz sonuçlarını veren bir temsilini elde etmektir (ekrandan, 00:10:00).
  - Neden gerekli: veri ambarları terabaytlarca veri tutabilir; karmaşık analiz tüm veri üzerinde çok uzun sürebilir ya da bellek yetmeyebilir.
  - Stratejiler (ekrandan, 00:10:00):
    - Boyut azaltma (dimensionality reduction): wavelet dönüşümleri, temel bileşenler analizi (PCA), öznitelik alt kümesi seçimi, öznitelik oluşturma.
    - Sayıca azaltma (numerosity reduction): veri küpü toplaması (data cube aggregation), örnekleme (sampling), kümeleme.
- Boyut ve boyutun laneti
  - Her öznitelik (sütun) bir boyuttur; iki öznitelikli veri iki boyutlu uzayda noktalar olarak gösterilir, bin öznitelikli veri bin boyutlu bir uzay demektir.
  - Boyut arttıkça veri uzayda daha dağınık hale gelir; algoritmaların maliyeti artar. Boyutu azaltmak hem hesaplama maliyetini düşürür hem de verinin daha toplu durmasını sağlar.
- Wavelet dönüşümü ve PCA
  - Fourier dönüşümü sinyali baskın frekanslar cinsinden ifade eder; wavelet buna zaman (konum) bilgisini de ekler. Her satır bir sinyal gibi düşünülür; önemli bileşenler tutulup diğerleri atılır. Örneğin bin sütun yedi yüz ya da sekiz yüz sütuna indirilebilir.
  - PCA lineer cebire dayanır; özdeğer ve özvektörler kullanılarak sütunlar arasındaki ilişkiye bakılır, fazlalık bilgi çıkarılır ve en önemli bileşenler tutulur.
  - Her ikisi de bilgi kaybıyla çalışır: veri birebir aynı değil, benzer şekilde daha az boyutla ifade edilir. Kütüphaneleri hazırdır ve sık kullanılır.
- Öznitelik alt kümesi seçimi (attribute subset selection)
  - Gereksiz (redundant) öznitelik: başka özniteliklerdeki bilginin çoğunu tekrarlar. Slayttaki örnek: ürün fiyatı ile ödenen satış vergisi (ekrandan, 00:15:00). Derste ayrıca fiyat, vergi ve toplam tutar sütunlarının birlikte bulunması örneği verildi.
  - İlgisiz (irrelevant) öznitelik: veri madenciliği görevi için neredeyse hiç yararlı bilgi taşımaz. Slayttaki örnek: öğrenci notunu tahmin etmek için öğrenci kimlik numarası (ekrandan, 00:15:00).
  - Amaç: tüm özniteliklerle elde edilen sınıf olasılık dağılımına mümkün olduğunca yakın dağılımı veren en küçük öznitelik kümesini bulmak. Bu, bulunan örüntüleri de anlamayı kolaylaştırır.
  - $n$ öznitelik için $2^n$ alt küme vardır; kaba kuvvetle (brute force) tümünü denemek büyük veride mümkün değildir. Bu nedenle sezgisel (heuristic) yöntemler kullanılır: adım adım (stepwise) en iyi özniteliği ekleme, skoru iyileştirmeyen öznitelikleri bir daha denememe gibi.
- Sayıca azaltma
  - Veri küpü toplaması: çeyreklik satışlar yıllık toplamlara indirgenir (ekrandan, 00:20:00). Excel'deki pivot tablolara benzer. Veri küpleri satışları mağaza, ürün ve yıl gibi birden fazla boyutta özet olarak tutar; önceden hesaplandığı için aranan özet veriye hızlı erişim sağlar ama gün düzeyindeki ayrıntı kaybolur.
  - Örnekleme: veri çok büyükse (milyonlarca satır) modelin tamamıyla eğitilmesi mümkün olmayabilir; veriden örnek alınır. İlk ya da son kayıtları almak yerine nasıl seçileceği önemlidir: rastgele seçim, yerine koyarak (with replacement) ya da yerine koymadan seçim, benzerlerini çıkararak seçim gibi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Binning denetimsizdir
  - Hoca, binning'in etiket kullanmadığını, yalnız değerlere bakarak ayırdığını ve bu yüzden basit bir kümeleme tekniği sayılabileceğini özellikle sordu ve vurguladı.
- Karar ağacıyla ayrıklaştırmanın ayrıntısı sonraya kaldı
  - Aralıkların entropi ile otomatik öğrenilmesi, karar ağaçlarında düğümlerin nasıl belirlendiği görülünce daha iyi anlaşılacak.
- Çok fazla veri her zaman iyi değildir
  - Algoritmaların çoğu optimizasyonla çalışır ve kesin doğru sonuç yerine örneğin yerel minimum verir; çok büyük veride bellek yetmeyebilir. Bu yüzden veri azaltma gerekir.
- Alt küme seçiminde kaba kuvvet çalışmaz
  - Kombinasyon sayısı üstel büyür ($2^n$); hoca bu yöntemlerin pratikte pek iyi çalışmadığını, ama yine de genellikle sezgisel yöntemlerle kullanıldığını söyledi.
- Veri küplerinin amacı hızdır
  - İki boyutlu tablolar yerine çok boyutlu özet tutmak, aranan özet bilgiye hızlı ulaşmayı sağlar; bu konu veri tabanı ve OLAP alanında bugün de kullanılır.

## Kısa Tekrar Notları

- Ayrıklaştırma: sürekli değer, ayrık etiket.
- Eşit genişlik: aralık eşit bölünür. Eşit frekans: her bine eşit sayıda eleman.
- Binning ve boşluğa (gap) göre kümeleme denetimsizdir; karar ağacıyla ayrıklaştırma denetimlidir ve entropi kullanır.
- Kavram hiyerarşisi: üst seviye alt seviyeyi kapsar (yıl, çeyrek, ay, gün; ülke, eyalet, şehir).
- Veri azaltma: daha küçük veri, aynı ya da neredeyse aynı analiz sonucu.
- Boyut azaltma: wavelet, PCA, öznitelik alt kümesi seçimi.
- Sayıca azaltma: veri küpü toplaması, örnekleme, kümeleme.
- Gereksiz öznitelik: fiyat ve satış vergisi. İlgisiz öznitelik: not tahmininde öğrenci numarası.
- $n$ öznitelikte $2^n$ alt küme; sezgisel (stepwise) arama kullanılır.
- Örneklemede seçim biçimi önemlidir: rastgele, yerine koyarak ya da koymadan.

## Detaylı Açıklamalar

- **Eşit genişlikli binning örneği.** Derste fiyat (price) özniteliğinin 5'ten 215'e uzandığı bir veri üç bine bölündü. Bin genişliği 70 olarak alındı ve değerler birinci, ikinci, üçüncü bine yerleştirilip 1, 2, 3 etiketleri verildi. <!-- BELİRSİZ: Slayttaki 12 değerlik fiyat listesi ve bin sınırları karede yok; altyazıda sınırlar "0-70, 70-140, 140-210" diye geçiyor. -->
  - Ders sonrası not: Eşit genişlik genellikle $(\max - \min)/k$ ile hesaplanır; burada $(215-5)/3 = 70$ eder. Bu durumda sınırlar büyük olasılıkla 5-75, 75-145, 145-215 olur; altyazıda söylenen 0-70, 70-140, 140-210 sınırları bu formülle uyuşmuyor.
- **Eşit frekanslı binning.** Aynı veri sıralanır; 12 eleman olduğundan her bine dört eleman düşer.
- **Boşluğa göre kümeleme.** Sıralı değerler arasındaki en büyük fark bulunur (derste 89 ile 204 arası) ve veri buradan iki kümeye ayrılır. Sonra kalan boşluklar arasında en büyüğü (derste 15 ile 35 arası, fark 20) bulunup bir kez daha ayrılır; böylece üç küme elde edilir. <!-- BELİRSİZ: Değer listesi karede yok; boşluk değerleri altyazıdan alındı. -->
- **Karar ağacıyla ayrıklaştırma.** Sürekli bir değer için "şu aralıktaysa A sınıfı, şu aralıktaysa B sınıfı" gibi aralıklar, sınıf etiketleri ve entropi kullanılarak otomatik öğrenilir. Bölme noktaları her parçada aynı sınıftan mümkün olduğunca çok örnek kalacak şekilde seçilir.
- **Veri küpü toplaması örneği (ekrandan, 00:20:00).** 2002 yılının çeyreklik satışları Q1 = \$224,000, Q2 = \$408,000, Q3 = \$350,000, Q4 = \$586,000'dir. Toplandığında yıllık satış \$1,568,000 olur. Slayttaki yıllık tabloda 2003 için \$2,356,000, 2004 için \$3,594,000 yazar. Sonuç veri kümesi hacimce küçülür ama yıllık analiz için gereken bilgi kaybolmaz.
- **Neden üç boyutlu küp?** Veri tabanı tabloları iki boyutludur. Satışların mağaza, ürün ve yıl boyutlarında önceden toplanıp küp olarak tutulması gerçek zamanlı değildir; veri sonradan işlenir. Kazanç hızdır: özet sorulara hızlıca cevap verilir. Kayıp ise ayrıntıdır: örneğin belirli bir günde kaç bilgisayar satıldığı küpten bulunamaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
