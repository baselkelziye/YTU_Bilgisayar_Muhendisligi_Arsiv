# Ders 7 Çalışma Özeti

## Genel Konular

- K-NN algoritmasının öğrenme ve test karmaşıklığı
  - K-NN (K-Nearest Neighbor) bir sınıflandırma (supervised) algoritmasıdır; K-Means ise kümeleme (unsupervised) algoritmasıdır. İkisi sık karıştırılır.
  - K-NN'in öğrenme (model oluşturma) adımı yoktur. Örneklerden ayrı bir parametre ya da eğri çıkarılmaz; bu tür algoritmalara örnek tabanlı öğrenme (instance-based learning) denir.
  - Asıl maliyet test (gerçek kullanım) tarafındadır: her yeni örnek için kayıtlı örneklere uzaklık hesaplanır. Kullanılan uzaklık metriği de önemlidir: Öklid, Manhattan, Jaccard, Mahalanobis. Öklid çok kullanılır ama her problemde en iyisi değildir; bazen eksenler boyunca hareketin maliyeti (Manhattan) daha anlamlıdır.
- Mobil ve giyilebilir cihazlarda makine öğrenmesi
  - Test karmaşıklığı düşük modeller telefon, saat ve IoT cihazlarında çalıştırılmak için tercih edilir.
  - Öğrenmesi maliyetli modeller sunucuda eğitilir, elde edilen parametreler cihaza aktarılır (deploy). Sinir ağında ağırlıkları bulmak uzun sürer ama karar vermek yalnızca çarpma ve toplamadır.
  - Kayan noktalı işlem tam sayı işlemine göre maliyetlidir. Mümkünse sayılar ölçeklenerek (ör. virgülden sonraki iki basamak için çarpılarak) tam sayılarla çalışılır.
  - Telefonda öğrenme yapılacaksa bu iş cihaz şarjdayken yaptırılabilir; işletim sistemlerinin güncellemeyi şarjda, büyük indirmeleri Wi-Fi'de yapması aynı mantıktır.
  - Yeni eğilim veriyi olduğu yerde (telefon, saat, IoT cihazı) işleyip yalnızca çıkarılan bilgiyi merkeze göndermektir; veriyi saklamak ve taşımak da maliyettir.
- Veri ön işleme: entegrasyon ve temizleme
  - Veri entegrasyonu farklı kaynaklardan gelen verinin birleştirilmesidir (extraction, aggregation). Slayttaki örnekler: dolar ve euro gibi farklı ölçekler, aylık ve yıllık maaş gibi türetilmiş öznitelikler (ekrandan, 00:20:00). Entegrasyon genellikle ilk yapılır, çünkü eksik, fazla ve yanlış bilgiler ancak birleştirmeden sonra ortaya çıkar.
  - Temizlemede tip uyuşmazlıkları (tarih olarak görünen ama aslında float olan kolon) ve tutarsız veriler düzeltilir. Slayttaki örnek: Age="42" ile Birth Date="03/07/1997" birbiriyle tutarsızdır (ekrandan, 00:25:00). Birbiriyle ilişkili iki öznitelikten birini almak yeterli olabilir.
- Veri dönüşümü (data transformation)
  - Amaç veriyi veri madenciliği algoritmalarına en uygun hale getirmektir. Slayttaki tipik işlemler: aggregation (aylık satışların yıllık satışa çevrilmesi), data generalization (sokak → şehir, sayısal yaş → {young, adult, half-age, old}), normalizasyon ([-1,1] ya da [0,1]), doğrusal, karesel ve polinom dönüşümler (ekrandan, 00:35:00).
  - Ayrıklaştırma (discretization): yüksek çözünürlüklü sürekli veri karar vermeyi zorlaştırıyorsa aralıklara bölünür. Derste verilen örnekler: yaş grupları, şirket verisinin çeyreklere bölünmesi, sıcaklığın "soğuk, serin, ılık, sıcak" diye gruplanması, ders notlarının harf notuna çevrilmesi.
  - Kategorik verinin sayıya çevrilmesi: label encoding her kategoriye bir sayı verir (pazartesi 1, cuma 5); bu sayılar arasındaki uzaklık anlamlı değilse yanıltır. One-hot encoding her kategori için ayrı bir kolon açar; haftanın günü özniteliği 7 kolona çıkar, ilgili gün 1, diğerleri 0 olur.
  - Boyut indirgeme: PCA ve LDA veriyi başka bir uzaya taşır; hem öznitelik sayısını azaltır hem de mevcut uzayda ayrılamayan sınıfları ayırmaya yardım eder. PCA sınıf bilgisi kullanmaz (unsupervised veride de çalışır); LDA sınıflar arası uzaklığı büyütüp sınıf içi uzaklığı küçültmeye çalışır, genelde daha iyi sonuç verir. PCA'de özdeğer ve özvektörler hesaplanır, scree grafiğiyle kaç bileşen alınacağına karar verilir.
  - Min-max normalizasyon [-1,1] ya da [0,1] aralığına ölçekler.
- Eksik veri (missing values)
  - Kullanıcının elle girdiği veriler en kirli ve eksik verilerdir (büyük/küçük harf, İ/ı farkı, yazım hataları). Sensör verisinde hatalı değer daha seyrektir.
  - Seçenekler: eksik olduğunu standart bir işaretle belirtmek (ör. -1 ya da N/A; boşluk, null gibi farklı sembollerin karışık kullanılmaması gerekir); eksik özniteliği olan örneği atmak (veri bolsa ve eksik oranı düşükse, ör. %5-10); tüm örneklerin ortalaması; aynı sınıftaki örneklerin ortalaması; medyan; en olası değerle doldurma (Bayes ya da karar ağacı ile çıkarım, ekrandan, 01:05:00).
  - Her örnekte farklı bir öznitelik eksikse örnek atma yaklaşımı neredeyse bütün veriyi siler; öznitelik sayısı çok olduğunda bu sık görülür.
  - Benzerliğe dayalı doldurma: eksik öznitelik dışındaki özniteliklere göre en benzer k örnek bulunur (K-NN), onların değerinin ortalaması, medyanı vb. kullanılır. Sınıf bilgisi yoksa K-Means ile örnekler kalan özniteliklere göre kümelenir, eksik örneğin düştüğü kümedeki değerlere bakılır.
  - Slaytta KEEL aracındaki yöntemlerden bazıları listelenmişti: Ignore-MV, EventCovering-MV, KNN-MV, MostCommon-MV, AllPossible-MV, KMeans-MV, ConceptMostCommon-MV; "15 methods" (ekrandan, 01:05:00).
- Gürültü temizleme (noise cleaning)
  - Slayttaki örnek türleri: güvenli (safe), sınırda (borderline) ve gürültülü (noisy) örnekler (ekrandan, 01:10:00). Sınıfların iç içe geçtiği yerdeki borderline örnekler risklidir.
  - Aykırı değer (outlier) tespitinde iki ölçüt birlikte kullanılır: merkezden belli bir yarıçapın dışında olmak ve çevresinde yeterince örnek bulunmamak. Uzakta tek bir örnek atılmaya adaydır, uzakta 50 örneklik bir grup ise atılmamalıdır.
  - Bazı problemlerde uzak örnek gerçek bir gözlemdir; atmak yerine benzer sentetik veri üretmek (fraud tespiti, yeni ve az görülen hastalıklar) dengesiz veri setini dengeleyebilir. Ağ saldırıları gibi değer aralığı çok geniş problemlerde sentetik veri gerçek verinin yerini tutmaz.
  - Slayttaki şekil sınıflar arası etkileşimi gösteriyordu: small disjuncts ve overlapping (ekrandan, 01:20:00). İç içe geçmiş, doğrusal olmayan problemlerde sinir ağları başarılıdır ama öğrenme maliyeti yüksektir.
- Ensemble Filter (EF)
  - Brodley ve Friedl'in yöntemi: farklı öğrenme algoritmalarıyla (C4.5, 1-NN, LDA) eğitim verisinin alt kümelerinde sınıflandırıcılar kurulur. Her algoritma için k-katlı çapraz doğrulamayla her eğitim örneği "correct" ya da "mislabeled" diye etiketlenir; sonra oylama yapılır (ekrandan, 01:35:00).
  - Consensus voting: örnek bütün sınıflandırıcılar tarafından yanlış sınıflanırsa atılır. Majority voting: sınıflandırıcıların yarısından fazlası yanlış sınıflarsa atılır.
  - Dezavantajı maliyettir. Önce basit bir elemeyle aykırı değer adayları (borderline ya da uzak örnekler) seçilip yalnız onlar EF'ye verilerek hibrit bir yapı kurulabilir.
- K-katlı çapraz doğrulama (k-fold cross validation)
  - Veri k parçaya bölünür; her turda bir parça test, k-1 parça eğitim için kullanılır ve bu bütün parçalar için tekrarlanır. Küçük veri setleri için önerilmiştir.
  - Dezavantajları: uzun sürer; veri karıştırılmadan bölünürse bir sınıfın bütün örnekleri tek bir parçada toplanabilir.
  - Hocaya göre çapraz doğrulama başarıyı yapay olarak yükseltir (hocanın deneyimine göre %5-%10). Büyük veride rastgele karıştırılıp ayrılmış eğitim, doğrulama ve test kümesi (ör. 60/20/20, 80/10/10) gerçek başarıyı daha iyi gösterir.
- Veri indirgeme (data reduction)
  - Slayttaki biçimler: öznitelik seçimi (feature selection), örnek seçimi (instance selection), ayrıklaştırma (discretization) (ekrandan, 02:05:00).
  - Öznitelik seçimi gerekçeleri: daha çok öznitelik daha çok başarı demek değildir; az öznitelik karmaşıklığı ve çalışma süresini azaltır, genelleştirmeyi artırır; bazı özniteliklerin değerini elde etmek zor ve pahalıdır (ekrandan, 02:10:00). Az öznitelikle sonuçlar daha kolay açıklanır; sinir ağı gibi modellerde hangi özniteliğin kararı etkilediği anlaşılamaz, karar ağacında anlaşılır. Doktorlar karar destek sistemlerinde bu açıklanabilirliği ister.
  - İleri yönlü seçim (forward selection) özellik ekleyerek, geri yönlü seçim (backward selection) bütün özelliklerden başlayıp çıkararak başarı değişimini izler. Gereksiz öznitelikleri atar ama en iyi kombinasyonu garanti etmez.
  - Öznitelik seçimi bir arama problemidir; n öznitelikten bütün alt kümeleri denemek $2^n$ (boş küme hariç $2^n - 1$) deneme ister (ekrandan, 02:15:00).
  - Bir sınıflandırıcıda en iyi olan öznitelik kümesi başka bir sınıflandırıcıda en iyi olmayabilir.
  - Filter ve wrapper: filter yöntemleri sınıflandırıcı kullanmadan bilginin dağılımına bakar (korelasyon, karşılıklı bilgi, entropi), öznitelikleri sıralar (Weka'daki ranker'lar); wrapper yöntemleri sınıflandırıcının başarısıyla alt küme seçer (ekrandan, 02:20:00).
  - Wrapper avantajları: daha doğru, doğrulama teknikleri sayesinde aşırı uyuma karşı direnç. Filter avantajları: hızlı, sınıflandırıcıdan bağımsız olduğu için her problemde kullanılabilir (ekrandan, 02:25:00). Filter'ın dezavantajı az katkısı olan çok sayıda değişkeni elde tutması, wrapper'ın dezavantajı maliyet ve sınıflandırıcıya özel olmasıdır.
  - Korelasyon: birbiriyle ilişkili iki öznitelikten biri atılabilir; sınıfla ilişkili öznitelik ayırt edicidir. Korelasyon yalnız doğrusal bağımlılığı ölçer; karşılıklı bilgi (mutual information) daha güçlüdür.
- Örnek seçimi (instance selection)
  - Verinin "parmak izini" (özet, hash, fingerprint) taşıyacak örnekleri seçmektir. Aynı bölgedeki çok sayıda benzer örnek katkı sağlamaz; yüz tanımada bir kişiden 50 neredeyse aynı fotoğraf koymak gereksizdir.
  - Slaytta aynı şeklin 8000, 2000 ve 500 noktayla gösterimi vardı (ekrandan, 02:30:00).
  - K-NN'de örnek sayısını azaltmak test maliyetini doğrudan düşürür. Karar ağacı yeni örnekle yeniden kurulur; sinir ağında yalnız ağırlıklar güncellenir.
  - Sık örneklenen sensör verisinde (ivmeölçer, jiroskop, GPS, dakikalık trafik hız verisi) ardışık benzer kayıtları seyreltmek de alan bilgisine dayalı basit bir örnek azaltmadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- K-NN ile K-Means karıştırılmamalıdır
  - Hoca bu karışıklığın her yıl tekrarlandığını söyledi. K-NN sınıflandırma, K-Means kümelemedir.
- K-NN'in öğrenme adımı yoktur
  - Hocanın her yıl sorduğu soru; tek ve net cevap "öğrenme adımı yoktur". Asıl sorun test karmaşıklığının yüksek olmasıdır.
- Mobil cihazda düşük test karmaşıklığı
  - Ağır öğrenme sunucuda yapılır, cihaza parametreler gönderilir. Kayan nokta yerine tam sayı tercih edilir.
- Ortalama yerine medyan
  - Ortalama uç değerlerden etkilenir; medyan dağılımın orta noktasını verir. Hoca bunu kritik bir bilgi olarak vurguladı.
- Aşırı uyum (overfitting) ve yetersiz uyum (underfitting)
  - Karmaşık model veriyi ezberler; mümkün olduğunca genelleştirilebilir, basit modeller kurulmalıdır. Çok basit model de (ör. tek doğru) örneklerin önemli kısmını yanlış sınıflar.
- K-katlı çapraz doğrulama tehlikelidir
  - Hoca tezlerde, veri gerçekten küçük değilse çapraz doğrulama kullanılmamasını önerdi; başarıyı olduğundan yüksek gösterir. Büyük veride rastgele karıştırılmış ayrık test kümesi kullanılmalıdır.
- Öznitelik alt kümesi sayısı $2^n$
  - Hoca bunu doktora yeterlilik düzeyinde basit bir soru olarak niteledi.

## Kısa Tekrar Notları

- K-NN: örnek tabanlı öğrenme, eğitim adımı yok, test maliyeti yüksek.
- Uzaklık metrikleri: Öklid, Manhattan, Jaccard, Mahalanobis.
- Ön işleme sırası genelde: entegrasyon → temizleme → dönüşüm → indirgeme.
- Label encoding sayılar arasında yapay bir uzaklık kurar; one-hot encoding her kategoriye ayrı kolon açar.
- PCA sınıf bilgisi kullanmaz; LDA sınıf bilgisini kullanır.
- Eksik veri: işaretle, sil, genel ortalama, sınıf ortalaması, medyan, en olası değer, K-NN, K-Means.
- Aykırı değer: hem uzak hem çevresi seyrek olmalı.
- Ensemble Filter: C4.5, 1-NN, LDA; k-fold ile correct/mislabeled; consensus ya da majority oylaması.
- Çapraz doğrulama küçük veri içindir; büyük veride ayrık eğitim/doğrulama/test.
- Öznitelik seçimi: forward, backward; filter (hızlı, genel) ve wrapper (doğru, pahalı).
- Bütün alt kümeler: $2^n$ (boş küme hariç $2^n-1$).
- Örnek seçimi K-NN'in test maliyetini düşürür.

## Detaylı Açıklamalar

- Ders, K-NN'in eğitim karmaşıklığı sorusuyla başladı. Öğrencilerden k parametresi, uzaklık metriği, $n^2$, küme sayısı ve $k \cdot n$ gibi cevaplar geldi. Hoca, K-NN'in eğitim aşamasında model kurmadığını, yalnızca örnekleri sakladığını ve test anında uzaklık hesapladığını açıkladı. Mobil teknolojiler açısından asıl önemli olan test karmaşıklığıdır, çünkü model cihazda çalışır.
- Entegrasyon aşamasında birimlerin ve ölçeklerin eşitlenmesi gerekir. Slayttaki tabloda bir kaynak aylık maaş (5000, 2400, 3000), diğer kaynak yıllık maaş (50,000, 100,000, 40,000) veriyordu (ekrandan, 00:20:00). İki tablo aynı birime çevrilmeden birlikte kullanılamaz.
- Dönüşümde amaç bazen standart bir biçime getirmek, bazen de gereksiz yüksek çözünürlüğü azaltmaktır. Aynı gruptaki örneklerin benzer davrandığı düşünülüyorsa gruplama yapılır. One-hot encoding'de bir öznitelik, içindeki farklı değer sayısı kadar özniteliğe çıkar.
- PCA ile örneğin 20 öznitelik 10 ya da 5 boyuta indirilebilir; yeni boyutların yönleri uzayda değişmiştir. İki boyutta bu, iki özniteliğin 45 derecelik bir doğru üzerine izdüşürülmesi gibi düşünülebilir.
- Eksik veride en basit iyi yöntem sınıf ortalaması ya da medyandır. Daha iyisi benzer örnekleri bulmaktır: kategorik özniteliklerde aynı değerler için uzaklık 0, farklı değerler için 1 alınır ve toplam uzaklık 0'a yakın olan örnek en benzeri sayılır. <!-- BELİRSİZ: Altyazıda bu cümle bozuk ("S ise 1'dir uzaklık. Farklıysa aynısı 0'dır"); bağlamdan aynı=0, farklı=1 olarak yazıldı. --> Sınıflandırma algoritmasıyla eksik değer tahmin etmek mümkündür ama maliyetlidir ve başarı garantisi yoktur.
- Gürültü temizleme bölümünde ekrandaki ayrım eğrisi polinom bir eğri olarak yorumlandı. Hoca yüksek dereceli eğrilerin hesap yükü ve özellikle aşırı uyum yüzünden istenmediğini, XOR'da bile doğrusal modelin yetmediğini, bu yüzden dengenin iyi kurulması gerektiğini anlattı. Bu tür bir ayrım SVM'de çekirdek seçimiyle elde edilir; SVM iki sınıf arasındaki farkı açıp destek vektörlerinin ortasından geçen bir çizgiyle ayırır.
- İç içe geçmiş sınıflara derste verilen örnekler: zatürre ile COVID'in akciğer görüntülerinde benzer desen göstermesi ve kullanıcının alışveriş alışkanlığını taklit eden kart dolandırıcılığı.
- Ensemble learning birden fazla sınıflandırıcının kararını çoğunluk ya da ağırlıklı oylamayla birleştirir; kararın doğruluğunu ve kararlılığını artırır. Ensemble Filter bu fikri gürültülü örnekleri bulmak için kullanır.
- Çapraz doğrulamada küçük veri avantajı: 10 örnekle 9 eğitim, 1 test yapılırsa tek örnekle test edilmiş olur; döndürerek yapılırsa bütün örnekler test edilmiş olur. Hoca bir araç türü tanıma çalışmasında karıştırılmadan bölünen veride bazı türlerin hiç öğrenilmediğini gözlemlediklerini anlattı.
- Öznitelik seçiminde hoca filter yöntemlerini verinin kendi karakteristiğini (sınıflandırıcıdan bağımsız ayırt ediciliğini) anlamak için, wrapper yöntemlerini belirli bir sınıflandırma probleminde en iyi başarıyı bulmak için önerdi.
- Örnek seçiminde sıradan seyreltme (ör. dakikalık hız verisi yerine 5 dakikalık kararlar) alan bilgisine dayanır, sofistike bir algoritma değildir; yine de gereksiz tekrarı azaltır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
