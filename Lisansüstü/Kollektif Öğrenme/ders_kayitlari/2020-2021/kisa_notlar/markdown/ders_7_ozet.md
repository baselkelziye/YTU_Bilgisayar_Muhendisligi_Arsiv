# Ders 7 Çalışma Özeti

## Genel Konular

- Rastgeleliğin iki yüzü (Extreme Random Forest'a kısa dönüş)
  - Her düğümde bütün özellikler yerine az sayıda rastgele özelliğe bakmak modeli hızlandırır ve kararları birbirinden farklılaştırır.
  - Bedeli: işe yarayan özellikler rastgele seçilenlerin arasında yoksa bölme kötü olur, ağaç derinleşir, genelleme ve tekil öğrenici başarısı düşer. Çeşitlilik kazanılırken doğruluk kaybedilir.
- Rotasyon Ormanları (Rotation Forest, Rodriguez ve Kuncheva, 2006)
  - Fikir: orijinal eğitim kümesine yakın kümelerle eğitilen temel öğrenicilerin tekil başarısı yüksek, ama kararları birbirine benzer olur. Bu yüzden bütün örnekler ve bütün özellikler korunur, veri döndürülerek farklılık üretilir.
  - Döndürme: $N \times d$ boyutlu $X$ verisi $d \times d$ boyutlu bir matrisle çarpılır: $X' = X_{N\times d} \cdot R_{d\times d}$, sonuç yine $N \times d$ olur (ekrandan, 00:15:00).
  - PCA veriyi döndüren bir yöntemdir, ama deterministiktir: aynı veriye her seferinde aynı dönüşümü verir. Farklı dönüşüm matrisleri elde etmek için PCA örneklerin, sınıfların ya da özelliklerin bir kısmıyla hesaplanır (ekrandan, 00:15:00).
  - Algoritma (ekrandan, 00:20:00): her $t = 1, \dots, T$ için özellik kümesi $F$ rastgele $K$ alt kümeye bölünür; her alt küme için $X$'in ilgili sütunlarından bir bootstrap örneklemi çekilir ve PCA uygulanır; elde edilen $D_{t,k}$ matrisleri blok köşegen $R_t$ matrisine dizilir, satırlar orijinal özellik sırasına göre yeniden düzenlenerek $R_t^a$ bulunur; $C_t$ sınıflandırıcısı $[X R_t^a \; Y]$ ile eğitilir.
  - Test: örnek her sınıflandırıcıya kendi rotasyon matrisiyle çarpılarak verilir. $C^*(\mathbf{x}) = \arg\max_{y \in \Phi} \sum_{t=1}^{T} I(C_t(\mathbf{x}R_t^a) = y)$, yani ağırlıksız çoğunluk oylaması.
  - Modelde ağaçların yanında her ağacın rotasyon matrisi de saklanmalıdır.
- Seyrek (blok köşegen) rotasyon matrisi
  - Veriyi en az bozan matris birim matristir. Rotation Forest birim matrise benzeyen, sıfır olmayan değerleri köşegen yakınındaki bloklarda olan seyrek bir matris kullanır.
  - 9 özellik ve 3 alt küme örneği: özellikler örneğin {1, 6, 7}, {2, 3, 5}, {4, 8, 9} diye bölünür, her üçlü için $3 \times 3$ PCA matrisi bulunur; matrisin geri kalanı sıfırdır (ekrandan, 00:30:00).
  - Karar ağaçları döndürmeye çok duyarlıdır (eksenlere dik sınırlar çizerler); 1-NN ise orijin etrafındaki döndürmeden etkilenmez. Bu yüzden küçük dönüşümler bile ağaçlarda yeterli farklılık yaratır.
- Deneysel karşılaştırma ve kappa-hata diyagramları
  - J48 tabanlı karşılaştırmada Rotation Forest'ın win/tie/loss sayıları: J48'e karşı (0/13/21), Bagging'e karşı (0/24/10), Boosting'e karşı (1/25/8), Random Forest'a karşı (0/24/10) (ekrandan, 00:35:00). Bu sayılar karşı algoritmanın Rotation Forest'a göre durumudur.
  - Kappa-hata diyagramında her nokta bir ağaç ikilisidir: yatay eksen ikilinin kararlarının uyumu (kappa), dikey eksen iki ağacın ortalama hatası. İdeal bölge sol alt köşedir (düşük hata, düşük benzerlik).
  - Vowel verisinde (ekrandan, 00:40:00) Random Forest ağaçları en farklı ama en hatalı, Bagging ağaçları en doğru ama en benzer; Rotation Forest arada bir denge kurar. Topluluk doğrulukları: Rotation Forest 95.77, Random Forest 92.37, AdaBoost 91.93, Bagging 89.52.
- İyileştirilmiş Uzay Ormanları (Improved Space Forest, Amasyalı, 2018)
  - Diğer topluluk algoritmalarıyla birlikte çalışabilen bir meta algoritmadır (ekrandan, 00:45:00).
  - Özellik sayısı azaltılmaz, artırılır: uzay $d$ boyuttan $d + z \cdot d$ boyuta çıkar.
  - Yeni özellik üretimi: bootstrap örneklemi seçilir, rastgele $f$'li özellik grupları üretilir, her grup için $k$. dereceden doğrusal regresyonla çıkışı tahmin eden bir model kurulur ve tahmin ($gf$) yeni özellik olarak eklenir. Her öğrenici kendi iyileştirilmiş uzayında eğitilir, sonuçlar oylamayla birleştirilir.
  - Yeni özellikler birden çok orijinal özelliği içerdiği için eğik (çok değişkenli) sınırlar çizilebilir. Ağaç gerektiğinde orijinal özellikle eksene dik, gerektiğinde üretilmiş özellikle eğik bölme yapar; yeni özellikler seçildiğinde ağaçlar küçülür (ekrandan, 00:50:00).
- Hata düzelten çıkış kodu tabanlı topluluklar (ECOC, Dietterich ve Bakiri, 1995)
  - $K$ sınıflı problem $L$ tane iki sınıflı probleme bölünür; bölünme bir kod matrisi $W$ ile tanımlanır. Böylece yalnız iki sınıf ayırabilen bir sınıflandırıcı (örneğin SVM) çok sınıflı problemde kullanılabilir.
  - Satırlar sınıfları, sütunlar ikili problemleri gösterir. Her sütunun tanımladığı eğitim kümesini bir öğrenici öğrenir; $+1$ ile gösterilen sınıfların örnekleri $+1$, $-1$ ile gösterilenlerin örnekleri $-1$ etiketini alır (ekrandan, 01:10:00).
  - Üç kod matrisi yöntemi: bir sınıf diğer tüm sınıflara karşı ($L = K$), sınıf ikilileri ($L = K(K-1)/2$; $K=4$ için 6), tüm olası alt problemler, "full code" ($L = 2^{K-1} - 1$; $K=4$ için 7).
  - Test: öğrenicilerin çıkışlarından oluşan vektör, $W$'nin hangi satırına en çok benziyorsa örnek o sınıfa atanır. $W$'deki 0'lar (ikililer yönteminde problemin dışında kalan sınıflar) etkisiz eleman sayılır. Eşit benzerlikte sınıflardan biri rastgele seçilir.
- İkinci ödev sunumlarından akademik noktalar
  - Sınıflandırıcıları karşılaştırmak için 5x2 katlı çapraz doğrulama ile eşleştirilmiş t-testi kullanıldı; kazanma/beraberlik/kaybetme sayıları veri kümeleri üzerinden sayılır.
  - Win/loss matrisinde satırdaki algoritmanın sütundaki algoritmayı kaç kez yendiği ve kaç kez yenildiği yazılır. Ortalamaya göre matriste bir ikilinin kazanma ve kaybetme sayılarının toplamı veri kümesi sayısını verir; t-testine göre matriste anlamsız farklar beraberlik sayıldığı için toplam daha küçüktür.
  - Temel öğrenici kararlarının benzerliği ikililer arasında (ör. kosinüs benzerliği ya da kappa) ölçülüp ortalaması alınarak ya da her öğrenicinin topluluk kararına benzerliğiyle ölçülebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Rastgelelik çeşitliliği artırır ama tekil başarıyı düşürür
  - Topluluk yöntemlerinde bir taraftan kazanılırken öbür taraftan kaybedilir; iyi bir yöntem iki uç arasında dengeyi yakalar.
- Rotation Forest'ta test örneği doğrudan verilemez
  - Her ağaç farklı bir uzayda eğitilmiştir. Örnek önce o ağacın rotasyon matrisiyle çarpılıp aynı uzaya taşınır. Bu yüzden ağaçlarla birlikte rotasyon matrisleri de saklanmalıdır.
  - Etiketler ($Y$) döndürülmez: etiket bir renk gibidir, noktanın koordinatı değişince etiketi değişmez.
- Karar ağaçlarının döndürmeye duyarlılığı
  - Veri 45 derece döndürülünce 1-NN'in sonucu değişmez, karar ağacının sonucu çok değişir. Bu yüzden veriyi çok bozmayan seyrek bir dönüşüm yeterlidir.
- Kappa-hata diyagramlarının değeri
  - Rotation Forest'ın dengeli konumu teorik bir sonuç değil, deneysel bir gözlemdir. Ama kappa-hata diyagramları topluluk dinamiklerini anlamak için çok faydalıdır.
- Sonuçların akla yatkınlık kontrolü
  - Ortalama %30 başarılı tekil öğreniciler birleşerek %80'lik bir topluluk oluşturamaz; tamamen farklı algoritmaların bütün veri kümelerinde virgülüne kadar aynı başarıyı vermesi de mümkün değildir. Böyle sonuçlar kodda hata olduğunu gösterir.
  - Tek veri kümesi üzerinden genelleme yapılamaz; birden çok veri kümesi bu yüzden kullanılır. Derinliğe bağlı değişimler tablo yerine grafikle daha açık anlatılır.

## Kısa Tekrar Notları

- Rotation Forest: bütün örnek ve özellikler korunur; özellik alt kümelerinde bootstrap + PCA ile seyrek, blok köşegen rotasyon matrisi kurulur; her ağaç kendi döndürülmüş verisiyle eğitilir.
- $X'_{N\times d} = X_{N\times d} R_{d\times d}$; PCA deterministik olduğu için çeşitlilik alt kümelerden gelir.
- Test: $\mathbf{x}R_t^a$ ile her ağacın uzayına taşınır, ağırlıksız oylama yapılır.
- Kappa-hata diyagramı: sol alt köşe ideal; RF farklı ama hatalı, Bagging doğru ama benzer, Rotation Forest arada.
- 100 temel öğreniciden $\binom{100}{2} = 4950$ ikili çıkar (derste 5500 denip geçildi).
- Improved Space Forest: meta algoritma; özellik $f$'lilerinden doğrusal regresyonla yeni özellikler, uzay $d \to d + z d$; eğik sınırlar.
- ECOC: one-vs-all $L=K$, ikililer $L=K(K-1)/2$, full code $L=2^{K-1}-1$; çıkış vektörü en yakın $W$ satırına atanır, 0'lar etkisiz.
- 5x2cv t-testinde 5 serbestlik dereceli %95 iki yönlü kritik değer yaklaşık 2.571'dir.
- Uzman karışımı (Mixture of Experts) ve stacking sonraki derse kaldı.

## Detaylı Açıklamalar

- Rotation Forest'ın mantığı. Bagging ve rastgele özellik seçimi farklılığı veriyi küçülterek sağlar. Bu tekil başarıyı düşürür, çünkü test verisinin eğitim verisiyle aynı dağılımdan geldiği varsayılır ve eğitim kümesi orijinale ne kadar yakınsa tekil öğrenici o kadar başarılı olur. Rotation Forest örnekleri ve özellikleri azaltmaz; veriyi bir matrisle çarparak başka bir uzaya taşır. Her ağaç için farklı bir $R_t$ matrisi bulunduğundan her ağaç aynı bilgiyi farklı bir koordinat sisteminde görür. Ağaçlar eksene dik sınırlar çizdiği için koordinat sistemindeki küçük bir değişiklik bile farklı bir ağaç üretir.
- Rotasyon matrisinin kurulması. Özellikler rastgele $K$ alt kümeye bölünür (ya da her alt kümede $M$ özellik olacak şekilde). Her alt küme için yalnız o sütunlardan oluşan alt matristen bir bootstrap örneklemi çekilir ve PCA uygulanır. PCA'nın verdiği katsayı matrisleri blok köşegen bir matrise yerleştirilir; satırlar orijinal özellik sırasına göre düzenlenir. Bütün özellikler kullanılır, ama bloklar dışındaki bütün elemanlar sıfırdır. Böylece veri bir miktar döndürülür ama tamamen dolu bir matristeki gibi bozulmaz. Slayttaki algoritmaya göre bootstrap örneklem boyutu genellikle $X_{t,k}$'den küçük seçilir (ekrandan, 00:20:00).
- Kappa-hata diyagramı nasıl okunur. 100 ağaçlı bir toplulukta her ağaç ikilisi için iki değer hesaplanır: kararların uyumunu gösteren kappa ve iki ağacın hatalarının ortalaması. Bir topluluk algoritmasının bulutu sol alta ne kadar yakınsa, ağaçları hem doğru hem birbirinden farklıdır. Vowel verisinde Bagging bulutu sağda (yüksek kappa) ama hatası düşük, Random Forest bulutu solda ama hatası en yüksek; Rotation Forest'ın kırmızı bulutu ikisinin arasındadır ve topluluk doğruluğu en yüksektir.
- İyileştirilmiş uzayda özellik üretimi. $f=2$, $k=1$ için rastgele seçilen iki özellikle tasarım matrisi $SX = [1 \; x_i \; x_j]$ kurulur, $w = (SX^T SX)^{-1} SX^T Y$ ile ağırlıklar bulunur ve $gf = SX \cdot w$ tahmini yeni özellik olur. $f=3$, $k=2$ için ikinci dereceden regresyon kullanılır: $SX$ üç özelliğin kendilerini, ikili çarpımlarını ve karelerini içerir (ekrandan, 00:50:00, slayt küçük görünüyor). Yeni özellik çıkışı tahmin etmeye çalıştığı için sınıflandırmaya yararlı bir yönü temsil eder. Ağaç yeni özellikleri seçmiyorsa üretilen özellikler anlamsız, seçiyorsa yararlı demektir.
- ECOC'ta kod çözme. Dört sınıflı one-vs-all örneğinde test örneği için öğrenicilerin çıkışı $(-1, -1, -1, +1)$ ise bu vektör dördüncü satırla aynıdır, örnek 4. sınıfa atanır. $(+1, -1, +1, -1)$ gibi hiçbir satıra tam uymayan bir çıkışta en benzer satır seçilir; birden çok satır eşit benzerlikteyse biri rastgele seçilir. Kod matrisi büyüdükçe (full code) hatalı bir öğrenicinin kararını diğerleri telafi edebilir; ama sınıf sayısı artınca full code'daki problem sayısı çok büyür.
- Ödevlerden çıkan pratik dersler. Kullanılan Python kütüphanesinin AdaBoost'unda `n_estimators` (öğrenici sayısı) bir üst sınırdır; algoritma daha erken durabilir. Sunumlarda maksimum derinlik sonsuza çıkınca eğitim süresinin birden düşmesi, topluluğun tek öğreniciye düşmesiyle açıklandı; hoca bunu kütüphanede tuhaf bir durum olarak not etti. MATLAB'ın yeni `fitctree` sürümünde doğrudan maksimum derinlik parametresi bulunamadığı için öğrenciler derinliği bölme sayısını (MaxNumSplits) sınırlayarak dolaylı olarak ayarladı; hoca budamanın da bir seçenek olabileceğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
