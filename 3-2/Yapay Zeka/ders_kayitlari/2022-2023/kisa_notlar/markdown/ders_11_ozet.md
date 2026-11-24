# Ders 11 Çalışma Özeti

## Genel Konular

- Genel veri kümesi yapısı ve problem türü
  - Gözetimli (supervised) öğrenmede bütün veri kümeleri aynı tablo biçimine çevrilir: satırlarda $N$ örnek, sütunlarda $d$ özellik ve en sağda çıkış vardır (ekrandan, 00:10:00). Her örnek $d$ boyutlu uzayda bir noktadır.
  - Çıkış kategorik ise problem sınıflandırma, sayısal ise regresyondur.
  - Kategorik değişkenin belirleyici özelliği, değerleri arasında büyüklük-küçüklük ilişkisinin olmamasıdır (kan grubu, tutulan takım, yaşanan şehir gibi).
  - Karar etiketlerin görünüşüne göre verilmez. Eğitim durumu (ilkokul, ortaokul, lise, üniversite) isim gibi görünür ama sıralıdır; regresyon olarak ele almak daha doğrudur. Rakam tanımadaki 0-9 etiketleri ise sayı gibi görünür ama bir şeklin adıdır; sınıflandırmadır.
  - Regresyon olarak ele almak, modele hataların büyüklüğünü söyler: ilkokul mezununa ortaokul demek, üniversite demekten daha küçük bir hatadır. Sınıflandırmada iki hata eşit sayılır.
- Özellik belirleme: neden gerekli?
  - Erişilebilen her bilgi problemi çözmede faydalı değildir; gereksiz özellikler fazlalık ve gürültü yaratır.
  - Üç özellikli, A/B sınıflı tablo örneği (ekrandan, 00:15:00): 1. özellik sınıfı tek başına %100 belirler, 2. özellik %75 başarı verir, 3. özellik hiçbir bilgi taşımaz (her zaman B demek %50).
  - Levrek-somon ayırma örneği: banttan geçen balıkların kamera görüntüsünden uzunluk ve parlaklık özellikleri çıkarılır. Her özellik için sınıf histogramları çizilir ve "özellik eşikten büyükse bir sınıf, değilse öteki" kuralıyla en az hatalı eşik aranır. İki özellikte de sıfır hatalı eşik yoktur; minimum hatalar karşılaştırılarak hangi özelliğin daha iyi olduğu görülür.
- İki temel yaklaşım (ekrandan, 00:20:00)
  - Var olan özelliklerden bazılarını seçmek: özellikleri tek tek değerlendirmek (filter) ya da özellik alt kümeleri oluşturup sınıflandırıcı performanslarını ölçerek bu alt kümeleri iyileştirmek (wrapper).
  - Var olan özelliklerin lineer birleşimlerinden yeni özellikler çıkarmak. Doğrusal olmayan birleşimler de mümkündür, ama derste lineer olanlar ele alındı.
- Filter yöntemleri
  - "Elimizde yalnız bu özellik olsaydı ne olurdu?" sorusunu cevaplar; özellik değiştiğinde sınıfın ne kadar değiştiğine bakar.
  - Kategorik özellikler için bilgi kazancı (information gain), sayısal özellikler için sinyalin gürültüye oranı (signal-to-noise ratio).
- Entropi
  - Düzensizliğin ölçüsüdür; bir kümenin elemanları üzerinden tanımlanır: $E(S) = \sum_{i=1}^{c} -p_i \log_2 p_i$. Burada $c$ kümedeki farklı değer sayısı, $p_i$ her değerin oranıdır (ekrandan, 00:25:00).
  - $\{A,A,B,B\}$: $c=2$, $E = -(\tfrac12\log_2\tfrac12 + \tfrac12\log_2\tfrac12) = 1$. $\{A,B,A,B\}$ da aynı kümedir, entropisi 1'dir. $\{C,A,D,B\}$: $c=4$, her oran $1/4$, $E=2$.
  - Entropi 0 ile 1 arasına sınırlı değildir, farklı değer sayısı arttıkça büyür (üst sınırı $\log_2 c$); yalnız $c=2$ iken 0 ile 1 arasında değişir. İki değerin oranı eşitse en yüksek (1), tek değer varsa 0'dır (hepsi beyaz toplardan oluşan kutu).
- Bilgi kazancı
  - $Gain(S,A) = E(S) - \sum_{v \in Values(A)} \frac{|S_v|}{|S|} E(S_v)$.
  - Tek bir değişken için hesaplanamaz; bir özelliğin bir çıkışı tahmin etmeye katkısını ölçer. Tek değişkenin entropisi vardır, kazancı yoktur.
  - Piknik örneği (ekrandan, 00:30:00): 4 olayda pikniğe 3 kez gidilmiş, $E(S) = 0.811$. Hava tek başına sonucu tam açıklar: $Gain = 0.811$. Rüzgar hiç değişmediği için $Gain = 0$. Nem ve su sıcaklığı bir şey söyler ama hava kadar değil.
  - Özellikler kazanca göre sıralanır; en büyükleri ya da belli bir eşiğin üstündekiler seçilir.
- Sinyalin gürültüye oranı (ekrandan, 00:35:00)
  - $S_i = \dfrac{|m_1 - m_2|}{d_1 + d_2}$. $m_1, m_2$: sınıf 1 ve sınıf 2'deki $i.$ özelliğin ortalaması; $d_1, d_2$: standart sapmaları.
  - Sınıflar arası uzaklık (pay) büyük, sınıf içi dağınıklık (payda) küçük olmalıdır. $S$ değeri en yüksek özellikler seçilir.
  - El yazısı ile kitap yazısı tanıma bağlantısı: el yazısında sınıf içi benzerlik azdır, bu yüzden daha zordur; sınıflar arası benzerlik (büyük O ile sıfır) de problemi zorlaştırır.
- Filter yöntemlerinin sınırı
  - Dört gruplu veri örneği: yeşiller solda, kırmızılar sağdayken öz1 iyi, öz2 işe yaramaz görünür (ekrandan, 00:40:00). Gruplar çapraz köşelere (XOR benzeri) yerleştirilince iki özelliğin de iki sınıftaki ortalamaları eşittir, yani SNR'ye göre ikisi de işe yaramaz. Oysa ikisi birlikte "öz1 < 3 ve öz2 < 2 ise yeşil" türü kurallarla veriyi tam sınıflandırır.
  - Filter, tek başına işe yaramayıp birlikte işe yarayan özellikleri bulamaz. Bu yüzden wrapper yaklaşımı gerekir.
- Wrapper (özellik alt kümesi seçiciler)
  - $N$ özellik için $2^N$ alt küme, yani $2^N$ eğitim vardır (ekrandan, 01:05:00). 4 özellik için 16 alt küme, boş küme dahil.
  - $N$ küçükse hepsi denenebilir; $N = 100$ için $2^{100}$ alt küme denemek mümkün değildir.
  - Wrapper boş kümeden başlayıp her adımda performansı en çok artıran özelliği ekler; iyileşme kalmayınca durur. Bu tepe tırmanma (hill climbing) algoritmasıdır.
  - Kohavi ve John (1997) grafiği örneği: boş küme 60; tek özellikler 65, 69, 70, 60 → 3. özellik (70); sonra {1,3} = 80; {1,2,3} = 79 ve {1,3,4} = 65 daha kötü → {1,3} ile durur. Hiç denenmeyen {1,2} = 90 daha iyidir.
  - Karmaşıklık en kötü durumda $N + (N-1) + \dots + 1$, yani $O(N^2)$; $2^N$'den $N^2$'ye iner. Dezavantajı en iyi sonucu garanti etmemesidir.
  - Tüm özelliklerden başlayıp her adımda bir özellik silerek de gidilebilir. İki yön aynı alt kümeye varmayabilir; bu, lokal aramanın doğasıdır.
- Yeni özellik çıkarımı (ekrandan, 01:15:00)
  - $y_j = w_{j1}x_1 + w_{j2}x_2 + \dots + w_{jd}x_d + w_{j0}$; yeni özellikler yalnız $w$ katsayılarıyla birbirinden ayrılır. İstenen sayıda (5, 100, 1000) üretilebilir.
  - PCA (temel bileşen analizi): yeni özelliklerin varyansının (standart sapmasının) yüksek olmasını ve birbirine ortogonal olmasını ister. Orijinal boyut kadar boyut üretir; ilk $k$ tanesi seçilerek boyut indirgenir. Sınıf bilgisi kullanmaz (gözetimsiz); bu yüzden sınıfları ayırmada kötü sonuç verebilir.
  - LDA (doğrusal ayırtaç analizi): sınıfların ayrılabilirliğini en büyük yapacak boyutu bulur. Gözetimlidir; sınıf bilgisi yoksa kullanılamaz.
  - Lineer birleşim doğrusal olmayan bir $f$ fonksiyonundan geçirilirse doğrusal olmayan özellikler elde edilir; bu yapı temelde bir yapay sinir ağıdır (ekrandan, 01:20:00).
- Hangi yöntem? Bedava öğle yemeği yok (No Free Lunch) teoremi
  - Denemeden hangi yöntemin daha iyi olacağı bilinemez. Her veri kümesinde diğerlerinden daha iyi çalışan bir yöntem yoktur; bu, sınıflandırma, regresyon ve kümeleme için de geçerlidir.
- Sınıflandırma yöntemleri
  - Doğrusal sınıflandırıcı: $w_0 + w_1x_1 + w_2x_2 + \dots + w_dx_d \ge 0$; en az hata yapan $w_i$'ler aranır (ekrandan, 01:25:00). Basittir ve yorumlanabilir: katsayıların işareti ve büyüklüğü her özelliğin çıkışa etkisini gösterir. Yeterince esnek değildir; ikiden fazla sınıflı problemler birden çok iki sınıflı probleme indirgenerek birden çok doğrusal sınıflandırıcıyla çözülebilir.
  - Karar ağaçları: veriyi böl ve yönet stratejisiyle her adımda iki parçaya ayırır. Tek değişkenli (univariate) ağaçta her bölmede tek özellik ve tek eşik kullanılır. Kuralları kolay anlaşılır.
  - Yapay sinir ağları: katmanlar ve aralarındaki ağırlıklardan oluşur; her nöron bir lineer perceptron ile üstünde doğrusal olmayan bir fonksiyondur. Eğitim, sürekli uzayda gradyanın yön gösterdiği bir lokal aramadır (ör. stokastik gradyan iniş).
  - En yakın K komşu: "Bana arkadaşını söyle, sana kim olduğunu söyleyeyim." Eğitim süreci yoktur; test örneğine en yakın $K$ eğitim örneğinin çoğunluk sınıfı verilir (ekrandan, 01:50:00).
- Parametre ve hiperparametre
  - Parametre: algoritmanın veriye ve kayıp fonksiyonuna göre kendi optimize ettiği değişkenler (doğrusal modelin $w$'leri, sinir ağının ağırlıkları).
  - Hiperparametre: bizim seçtiğimiz değerler (kayıp fonksiyonu, gizli katman sayısı, aktivasyon fonksiyonu, öğrenme algoritması, karar ağacında saflık ölçütü ve düğüm başına özellik sayısı, k-NN'de $K$).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınıflandırma mı regresyon mu?
  - Karar etiket adlarına göre değil, çıkış değerleri arasında anlamlı bir büyüklük-küçüklük ilişkisi olup olmadığına göre verilir.
- Bilgi kazancı tek bir değişken için hesaplanamaz
  - Entropi tek değişkenin özelliğidir; bilgi kazancı bir özelliğin başka bir değişkeni (çıkışı) tahmin etmeye katkısıdır.
- Mantıklı atma (çoğunluk sınıfı) referansı
  - Hiçbir özelliğe bakmadan, eğitimdeki en sık sınıfı söyleyerek bir başarı elde edilir. Sınıflar %90-%10 ise bu yolla %90 başarı alınır.
  - Bu yüzden "%90 başarı" tek başına bir şey söylemez. 1000 sınıflı dengeli bir problemde %5 başarı ise şanstan (binde bir) çok iyidir.
  - Makine öğrenmesinin temel varsayımı: gelecek geçmişe benzer, yani eğitim ve test kümelerinin dağılımı değişmez.
- Filter yöntemlerinin kör noktası
  - Tek başına işe yaramayıp birlikte işe yarayan özellikleri göremezler; bu durum wrapper'ı gerektirir.
- Wrapper bir tepe tırmanma aramasıdır
  - Arama uzayı $2^N$ iken yalnız $O(N^2)$ alt küme denenir; denenmeyenlerin oranı çok büyüktür. Mükemmel değil ama çözülebilir bir yol seçilir.
- Esneklik ve evrensel yaklaşıklayıcılar
  - Doğrusal sınıflandırıcı her eğitim kümesine %100 uyamaz. Karar ağacı, aynı noktada farklı sınıftan iki örnek olmadıkça her eğitim kümesini tam modelleyebilir.
  - Her eğitim kümesine uyabilen yöntemlere evrensel yaklaşıklayıcı (universal approximator) denir: karar ağaçları, yapay sinir ağları, 1-NN; sinyal tarafında Fourier ve Taylor açılımları.
  - Bu kavram yalnız eğitim kümesi için geçerlidir; test başarısı hakkında bir şey söylemez.
- Saflık hiperparametresi
  - %100 saflık istemek gürültülü veride ağacın gürültü noktalarının çevresine gereksiz bölmeler yapıp büyümesine yol açar. Gürültüden kaçınmak mümkün değildir.
- Hiperparametre sayısı
  - Çok hiperparametre algoritmayı esnek yapar, ama ayarlamayı çok zorlaştırır. Standart bir yapay sinir ağında 20-30 hiperparametre vardır; çoğu için varsayılan değerlerle çalışmak zorunda kalınır. Bir problem için bulunan iyi değerler başka bir problemde aynı olmaz.
  - Genetik algoritmalar için daha önce "çok parametresi var" denmişti; doğru ifade "çok hiperparametresi var" olmalıdır.
- k-NN model oluşturmaz
  - Model oluşturmak eğitim kümesini sıkıştırmaktır. Doğrusal modelde $w$'ler, karar ağacında ağaç, sinir ağında ağ yeter; k-NN'de ise her tahmin için veri kümesinin kendisi gerekir. Büyük veri kümelerinde çok bellek ister.

## Kısa Tekrar Notları

- Gözetimli veri: $N$ örnek × $d$ özellik + çıkış. Kategorik çıkış → sınıflandırma, sayısal/sıralı çıkış → regresyon.
- Özellik işlemleri: seçme (filter, wrapper) ya da yeni özellik çıkarma (PCA, LDA).
- Entropi $= -\sum p_i \log_2 p_i$; $\{A,A,B,B\} \to 1$, $\{C,A,D,B\} \to 2$, tek değerli küme $\to 0$. $c=2$ iken $[0,1]$.
- $Gain(S,A) = E(S) - \sum_v \frac{|S_v|}{|S|}E(S_v)$; piknik örneğinde hava 0.811, rüzgar 0.
- SNR $= |m_1 - m_2| / (d_1 + d_2)$: ortalamalar uzak, standart sapmalar küçük olmalı.
- Filter tek özelliğe bakar; XOR benzeri veride iki özelliği de işe yaramaz sanır.
- Wrapper = tepe tırmanma; $2^N$ yerine $O(N^2)$ deneme; ileri ve geri yönler farklı sonuç verebilir.
- PCA: varyansı en büyük, ortogonal boyutlar; gözetimsiz. LDA: ayrılabilirliği en büyük boyut; gözetimli.
- No Free Lunch: her veride en iyi tek yöntem yoktur.
- Başarı, çoğunluk sınıfı (mantıklı atma) referansıyla birlikte yorumlanır.
- Doğrusal sınıflandırıcı: basit, yorumlanabilir, esnek değil.
- Karar ağacı: tek özellik + tek eşikle ikiye böl; saf olana kadar tekrarla; saflık bir hiperparametredir.
- Karar ağacı, YSA ve 1-NN evrensel yaklaşıklayıcıdır (eğitim kümesi için).
- k-NN: eğitim yok, $K$ hiperparametre; $K=1$ eğitimde %100, $K=N$ çoğunluk sınıfı; veri kümesini saklamak gerekir.

## Detaylı Açıklamalar

- **Problem türünü belirlemek.** Ders, gözetimli öğrenmedeki genel tablo yapısını hatırlatarak başladı. Problemin sınıflandırma mı regresyon mu olduğu, çıkış değerlerinin adına bakılarak değil, aralarında anlamlı bir sıralama olup olmadığına bakılarak belirlenir. Bunun pratik sonucu hata toleransıdır. Eğitim durumunu ilkokul = 1, ortaokul = 2, üniversite = 5 gibi sayılarla regresyon olarak modellediğimizde, modele "ilkokul mezununa ortaokul demek küçük, üniversite demek büyük bir hatadır" bilgisini vermiş oluruz. Sınıflandırma olarak modellersek bu iki hata aynı sayılır. Tersine, rakam tanıma probleminde 0'a 1 demek 0'a 9 demekten daha küçük bir hata değildir; bu yüzden etiketler sayı olsa da problem sınıflandırmadır.

- **Özellik belirleme ve tek özellikle eşik kuralı.** Slayttaki tabloda (ekrandan, 00:15:00) 1. özellik 1 iken sınıf A, 2 iken B'dir: "1.öz == 1 ise A, değilse B" kuralı %100 başarılıdır. 2. özellik için "2.öz == 4 ise A, değilse B" kuralı %75, 3. özellik sabit (13) olduğundan yalnız "her zaman B" demek mümkündür, %50. Balık örneğinde de aynı mantık kullanılır: uzunluk ya da parlaklık için histogramlara bakılır, en az hata veren eşik seçilir ve iki özelliğin minimum hataları karşılaştırılır. <!-- BELİRSİZ: Balık histogramlarındaki sayılar ve uzunluk eşiği (altyazıda "17") karede okunmadı. -->

- **Bilgi kazancının hesaplanması.** Piknik tablosunda (ekrandan, 00:30:00) 4 olay vardır; hava sütunu güneşli, güneşli, yağmurlu, güneşli; sonuç evet, evet, hayır, evet. Çıkışın entropisi $E(S) = -(\tfrac34\log_2\tfrac34 + \tfrac14\log_2\tfrac14) = 0.811$. Hava güneşliyken (oran $3/4$) üç olayın üçünde de gidilmiş, entropi 0; yağmurluyken (oran $1/4$) tek olayda gidilmemiş, entropi 0. Bu yüzden $Gain(S, Hava) = 0.811 - 0 = 0.811$; kazancın çıkışın entropisine eşit olması, havanın piknik kararını birebir açıkladığını gösterir. Rüzgar dört olayda da "güçlü" olduğundan kazancı 0'dır. Python ile kontrol edildiğinde nem ve su sıcaklığının kazancı ikisi için de yaklaşık 0.123 çıkar (bu değerler derste söylenmedi; tablodan hesaplandı).

- **Wrapper'ın tepe tırmanma ile çalışması.** Hiçbir özellik kullanılmayan durumun da bir başarısı vardır (çoğunluk sınıfını söylemek); grafikte bu 60'tır (ekrandan, 01:05:00). Algoritma her adımda eklenebilecek her özelliği dener: boş kümeden 1, 2, 3, 4 eklenince 65, 69, 70, 60 elde edilir ve 70 seçilir. Sonra 3 özelliği varken 1, 2 ya da 4 eklenir: 80, 70, 75; 80 seçilir ({1,3}). Kalan 2 ve 4 eklenince 79 ve 65 olur; hiçbiri 80'den iyi olmadığı için algoritma durur. Grafikte {1,2} alt kümesinin 90 olduğu görülür, ama algoritma oraya hiç uğramaz. Derste öğrenciler önce BFS ve en iyi öncelikli aramayı önerdi; doğru cevap tepe tırmanmaydı.

- **PCA ve LDA.** Yeni özellikler eski özelliklerin ağırlıklı toplamlarıdır (ekrandan, 01:15:00). PCA, iki boyutlu bir nokta bulutunda veriyi üzerine iz düşürdüğümüzde en geniş dağılımı veren C1 yönünü ilk özellik, ona dik C2 yönünü ikinci özellik olarak bulur. Yalnız C1'i kullanmak iki boyuttan bire indirgemek demektir. Ancak PCA sınıfları bilmediğinden, iki sınıflı bir bulutta en büyük varyans yönü sınıfları üst üste düşürebilir. LDA ise sınıfların ayrılabilirliğini doğrudan hedefler.

- **Karar ağacının kurulması.** Örnekte iki boyutlu uzayda 20 örnek vardır (10 X, 10 O); $x_1 \in \{1,2,3,4\}$, $x_2 \in \{1,\dots,5\}$ (ekrandan, 01:30:00). Bölme noktaları $x_1$ için 1.5, 2.5, 3.5; $x_2$ için 1.5, 2.5, 3.5, 4.5'tir: toplam 7 aday. Her adayda iki tarafa kendi çoğunluk sınıfı verilip hata sayılır. Slayttaki değerler (ekrandan, 01:35:00): $x_1 = 1.5 \to 7$, $x_1 = 2.5 \to 8$, $x_1 = 3.5 \to 7$; $x_2$ değerleri derste "?" bırakıldı. Hoca örneği sürdürmek için ilk bölmeyi $x_1 = 1.5$ kabul etti ("şimdilik sallıyorum" diyerek). Sol taraf ($x_1 = 1$) yalnız $x_2$ ile bölünebilir ve $x_2 = 1.5$'ten hatasız bölünür. Sağ taraf saf olana kadar aynı işlemle bölünür. Sonunda karar düğümleri (özellik-eşik soruları) ve yapraklardan (sınıf kararları) oluşan bir ağaç elde edilir. Test örneği kökten bırakılır, dallarda ilerleyip bir yaprağa düşer ve o yaprağın sınıfını alır (ekrandan, 01:45:00).

- **k-NN ve esneklik.** Slayttaki çöp adam örneğinde (ekrandan, 01:50:00) mavi test örneğine en yakın tek komşu A'dır, 1-NN "A" der; en yakın üç komşuda iki B bir A vardır, 3-NN "B" der. 1-NN'de her eğitim örneğinin en yakın komşusu kendisi olduğundan eğitim başarısı %100'dür; $K$ büyüdükçe esneklik azalır. $K$ eğitim kümesinin boyutuna eşit olursa algoritma her zaman çoğunluk sınıfını, yani mantıklı atmayı döndürür. Hangi $K$'nin testte iyi olacağı veriye bağlıdır; $K$ bir hiperparametredir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
