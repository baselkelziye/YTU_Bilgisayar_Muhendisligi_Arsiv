# Ders 12 Çalışma Özeti

## Genel Konular

- k-NN'in zayıf yönü ve temsilci noktalar fikri (ekrandan, 00:10:00)
  - En yakın komşu (k-NN) her türlü eğitim kümesine uyum sağlayabilen esnek bir algoritmadır, ama bir eğitim aşaması yoktur. Bu yüzden ortaya eğitim kümesini "sıkıştıran" bir model çıkmaz; her test örneği için eğitim kümesinin tamamı gerekir.
  - Az örnekli veri kümelerinde sorun değildir, çok örnekli veri kümelerinde en yakın örneği bulmak pahalıdır ($n$ örnek ve $d$ boyut için $n \times d$ karşılaştırma). KD ağacı gibi veri yapıları aramayı hızlandırır.
  - Diğer yol: bütün eğitim örnekleri yerine az sayıda yeni (seçilmiş ya da üretilmiş) temsilci nokta kullanmak. Slayttaki örnekte iki sınıfın onlarca noktası yerine her sınıftan 3 temsilci (toplam 6) kullanılır. Temsilciler orijinal örneklerden biri olmak zorunda değildir.
- Öğrenmeli Vektör Kuantalama (Learning Vector Quantization, LVQ) (ekrandan, 00:15:00)
  - Parametreler: $\eta$ öğrenme oranı, $n$ en fazla eğitim sayısı, $c$ betimleyici vektör sayısı, $\mu_1, \dots, \mu_c$ betimleyici vektörler (centroid), $x$ eğitim örneği, $S(x)$ $x$'in sınıfı.
  - Adımlar: (1) $\eta$, $n$ ve $\mu_1, \dots, \mu_c$ için ilk değer ata. (2) $n$ kez tekrarla: (2.1) bir $x$ eğitim örneği al, (2.2) $x$'e en yakın betimleyici vektörü bul: $k \leftarrow \arg\min_j \lVert x - \mu_j \rVert$, $j = 1..c$, (2.3) $\mu_k$'yı güncelle.
  - Sınıflar aynıysa ($S(x) = S(\mu_k)$) ödüllendir, $x$'e yaklaştır: $\mu_k \leftarrow \mu_k + \eta (x - \mu_k)$. Değilse cezalandır, $x$'ten uzaklaştır: $\mu_k \leftarrow \mu_k - \eta (x - \mu_k)$.
  - Her betimleyici vektöre baştan bir sınıf atanır. Sınıf dağılımına uygun sayıda vektör atamak makuldür; dengesiz veri kümelerinde az örnekli sınıfa görece fazla vektör vererek sınıf oranları değiştirilebilir (örneğin 100'e 10 örnekte her sınıfa 5 vektör).
  - Test aşaması 1-NN'e benzer: yeni örnek en yakın betimleyici vektörün sınıfını alır. Örnek sayısı çok azaldığı için hızlıdır.
  - LVQ'yu öneren Kohonen, SOM'u da önermiştir; K-means ve SOM'a benzer bir ödül-ceza düzeni vardır.
- Ölü betimleyici vektör sorunu ve ilk değerler
  - Rastgele atanan bir vektör verinin hiç olmadığı bir yere düşerse hiçbir örneğe en yakın olamaz, hiç güncellenmez ve işe yaramaz ("ölü" vektör).
  - Çözüm: ilk değerleri mevcut eğitim örneklerinden seçmek.
  - Algoritma yerel çözüme takılabilir: aynı sınıftan noktaların çekmesi ve öbür sınıftan noktaların itmesi bir vektörün bir bölgeyi aşıp öbür tarafa geçmesini zorlaştırır.
- LVQ'nun karar sınırı (ekrandan, 00:35:00)
  - İki betimleyici vektör varsa karar sınırı, iki vektörü birleştiren doğrunun orta dikmesidir, yani doğrusaldır.
  - Daha fazla vektörde sınır, vektörlerin Voronoi bölgelerinden oluşan parçalı doğrusal bir sınırdır. 1-NN'de de durum aynıdır; ikisinin test süreçleri aynıdır, fark yalnız eğitim kümesinin tamamının mı temsilcilerinin mi kullanıldığıdır.
  - LVQ, 1-NN kadar esnek değildir; eğitim kümesinde %100 başarı garanti değildir. Vektör sayısı örnek sayısına yaklaştıkça eğitim başarısı %100'e yaklaşır.
- Eğitim kümesi performansı neyi ifade etmez? (ekrandan, 00:40:00 ve 00:45:00)
  - 1024 kişiye e-posta: yarısına "X hisse senedi yarın yükselecek", yarısına "düşecek" denir. Her gün tahmini tutan yarıyla devam edilir: 1024 → 512 → 256 → 128 → ... → 10. günde 1 kişi ($2^{10} = 1024$).
  - Bu kişiye göre on gün boyunca söylenen her şey tutmuştur, ama 11. gün için tahminin tutma olasılığı yine %50'dir. Eğitim kümesindeki %100 başarı test başarısı hakkında hiçbir şey söylemez.
  - Bütün makine öğrenmesi yöntemlerinin temel varsayımı: gelecek geçmişten çok farklı değildir. Hiç görülmemiş bir örüntüyü önceden tahmin etmek mümkün değildir.
- Çapraz geçerleme (ekrandan, 01:00:00)
  - Veri kümesi eşit boyutlu $N$ gruba bölünür; her seferinde bir grup test, geri kalanı eğitim için kullanılır; $N$ kez tekrarlanır. 5 katlıda her seferinde %20 test, %80 eğitim olur.
  - Her örnek tam bir kez test edilir. Tek bir eğitim-test ayrımından daha güvenilir bir başarı tahmini verir.
- Sınıflandırma metotlarının karşılaştırılması (ekrandan, 01:20:00)
  - Altı veri kümesinde NB, SVM, 1NN, C4.5 ve RF'nin 5 katlı çapraz geçerleme başarıları verilir. Her veri kümesinde başka bir algoritma en iyidir.
  - Bütün veri kümelerinde diğerlerinden iyi olan tek bir algoritma yoktur. Bir algoritmanın başarılı olması için varsaydığı modelin verinin geldiği dağılıma uyması gerekir; dağılımlar sonsuz çeşitlidir. Bu yüzden algoritmalar kütüphaneler halinde sunulur ve denenip karşılaştırılır.
- Model karmaşıklığı ve hata (ekrandan, 01:05:00)
  - Karmaşıklık arttıkça eğitim hatası sürekli düşer; test hatası bir noktaya kadar düşer, sonra yükselir. Her veri kümesi için optimum karmaşıklık farklıdır. İki karşıt özellik: aşırı eğitme (ezberleme, overfitting) ve genelleştirebilme.
  - Bu yapı doğrusal regresyon, k-NN, karar ağaçları gibi algoritmalarda geçerlidir. Yapay sinir ağlarında, özellikle çok veri ve yüksek karmaşıklık birlikte olduğunda, tam geçerli değildir (double descent gibi yapılar görülebilir).
- Kümeleme algoritmaları (ekrandan, 01:10:00)
  - Eğiticisizdir, sınıf bilgisi yoktur. Veriyi temsil eden merkezleri bulur, örnekleri en yakın merkeze göre kümelere ayırır. Farklı değer sayısını azalttığı için sıkıştırmanın (kuantalama) temelindedir.
  - Örnek: tek özellikli 10 örnek `12-15-13-87-4-5-9-67-1-2`, 3 değerle `12-12-12-77-3-3-3-77-3-3` diye temsil edilebilir. Kümeler: {12, 15, 13}, {87, 67}, {4, 5, 1, 2, 9}. Amaç gerçek değerlerle temsil eden değerler arasındaki farkları en aza indirmektir.
  - Uygulamalar: renk kümeleme (256 renkten adım adım 2 renge), resmi 10×10 piksellik bloklara bölüp blokları kümeleme (200×200 resimde 400 blok → 40 temsilci blok), iletişimde vektör kuantalama: gönderen yalnız en yakın küme merkezinin indisini yollar, alıcı aynı tablodan merkezi geri koyar. Küme sayısı azaldıkça indis daha az yer tutar ama görüntü bozulur.
- Hiyerarşik kümeleme (ekrandan, 01:15:00)
  - İki tür: tek kümeden çok kümeye (bölmeli) ve çok kümeden tek kümeye (eklemeli). Genelde eklemeli olan kullanılır.
  - Eklemeli: başta her örnek bir kümedir; en benzer iki küme birleştirilir ve tekrarlanır. İstenen küme sayısında durulabilir.
  - İki kümenin benzerliği: en benzer elemanlar (single link), en az benzer elemanlar (complete link) ya da ortalama (group average). Herhangi bir uzaklık ölçüsü (Öklid, Manhattan, kosinüs) kullanılabilir.
  - Bölmeli: her şey tek kümede başlar, kümenin en az benzer iki elemanı bulunur ve küme bu ikisine göre bölünür.
  - Slayttaki dendrogram, algoritmaların veri kümelerindeki başarılarına göre kümelenmesidir: doğrusal algoritmalar, ensemble algoritmaları ve k-NN türevleri ayrı gruplarda toplanır.
- K-means (ekrandan, 01:25:00)
  - Sayısal verilerle çalışır. Rastgele $K$ küme merkezi atanır; her örnek en yakın merkezin kümesine atanır; merkezler kendi kümelerinin ortalamasına taşınır; küme değiştiren örnek kalmayana ya da en fazla iterasyona ulaşılana kadar tekrarlanır.
  - Yerel minimuma takılabilir; ilk değerler önemlidir.
  - Kümelemelerin karşılaştırılması: her örneğin kendi küme merkezine uzaklığına dayanan hata (loss) fonksiyonu. Yalnız küme sayıları eşitse karşılaştırma anlamlıdır; $K$ arttıkça hata hep düşer.
  - Toplu (batch) K-means: önce bütün örnekler atanır, sonra merkezler güncellenir. Tekli (online) K-means: her örnek için en yakın merkez bir öğrenme oranıyla örneğe yaklaştırılır (LVQ'nun ödül kısmı gibi; ceza yoktur).
- Self-Organizing Map (SOM) (ekrandan, 01:35:00)
  - Online K-means'e merkezler arasında önceden tanımlı bir komşuluk (tek boyutlu halka/doğru ya da iki boyutlu ızgara) eklenmiş halidir.
  - Bir örnek geldiğinde en yakın merkezle birlikte ona bağlı komşu merkezler de örneğe yaklaştırılır.
  - İki boyutlu ızgara, yüksek boyutlu verinin iki boyutta nasıl göründüğü hakkında fikir verir; bu yüzden görselleştirmede de kullanılır.
- DBSCAN (ekrandan, 01:40:00)
  - Yoğunluk tabanlı kümelemedir. Hiperparametreleri: $eps$ ve $min\_p$.
  - Noktalar etiketlenir: çekirdek (eps komşuluğunda en az $min\_p$ nokta var), sınır (eps komşuluğunda $min\_p$'den az nokta var), gürültü (eps komşuluğunda hiç nokta yok).
  - Gürültüler atılır, birbirine eps mesafede olan çekirdekler birleştirilir, sınır noktalar en yakın çekirdeğin kümesine atanır. Küme sayısı hiperparametrelere bağlıdır; her örnek bir kümeye girmek zorunda değildir.
  - Merkez tabanlı K-means'in bulamadığı iç içe ya da uzamış biçimli kümeleri bulabilir.
- Kümelemede açık sorular (ekrandan, 01:45:00)
  - Ne zaman dururuz: küme değiştiren örnek kalmayana kadar ya da en fazla iterasyonda (iki merkez arasında gidip gelen noktalar yüzünden ikincisi genelde gerekir).
  - Ölü nöron kavramı (SOM, K-means).
  - Başarı ölçütü: hata fonksiyonu ve literatürdeki geçerlilik indeksleri. Sınıfları bilinen veride küme-sınıf uyumuna bakılabilir, ama kümeleme ile sınıflandırmanın amacı aynı değildir.
- Regresyon algoritmaları (ekrandan, 01:50:00 ve 01:55:00)
  - Basit doğrusal regresyon: $X$ girişler ($n \times d$), $Y$ çıkışlar ($n \times 1$), model $Y = XW$. $X$ kare olmadığı için tersi alınamaz; her iki taraf $X^T$ ile çarpılır ($X^TX$ her zaman karedir): $W = (X^TX)^{-1}X^TY$. Bu analitik, tek adımlı çözümdür; perceptron gibi iteratif gradyan yöntemleri de kullanılabilir.
  - k-NN ile regresyon: $k=1$'de çıktı en yakın eğitim örneğinin çıktısıdır (basamaklı fonksiyon); $k>1$'de en yakın $k$ örneğin çıktılarının ortalaması alınır.
  - Regresyon ağaçları: yapraklarda sınıf yerine sayı (bölgeye düşen örneklerin ortalaması) bulunur. Bir bölmenin iyiliği iki taraftaki çıkışların standart sapmalarının toplamıyla ölçülür. Kabul edilen hata değeri ($\theta_r$) küçüldükçe ağaç büyür; sıfırda her noktadan geçen dev bir ağaç çıkar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Eğitim kümesindeki başarı test başarısının ölçüsü değildir
  - 1024 e-posta hikayesi bunun için anlatılır: on gün tutan tahminler yalnız seçilim sonucudur, 11. gün tahmini yine yazı turadır.
- Tek bir "en iyi" sınıflandırıcı yoktur
  - Veri kümesinin geldiği dağılımla algoritmanın modeli uyuşmalıdır; bu yüzden algoritmalar denenerek seçilir.
- LVQ ve K-means'te ilk değerler önemlidir
  - Rastgele başlangıç ölü vektörlere ve yerel çözümlere yol açabilir; ilk değerleri mevcut örneklerden seçmek ölü vektör olasılığını azaltır.
- Kümelemeleri karşılaştırırken küme sayısı eşit olmalıdır
  - $K$ arttıkça hata fonksiyonu kesinlikle düşer.
- Bu algoritmaları kendiniz kodlayın
  - LVQ, online K-means ve SOM'un kodlaması kolaydır; vektörlerin nasıl hareket ettiğini ve kötü durumların nasıl oluştuğunu gözlemlemek öğreticidir.

## Kısa Tekrar Notları

- LVQ: en yakın betimleyici vektör aynı sınıftaysa $\mu_k \leftarrow \mu_k + \eta(x-\mu_k)$, değilse $\mu_k \leftarrow \mu_k - \eta(x-\mu_k)$.
- Güncelleme, $x$ ile $\mu_k$'yı birleştiren doğru üzerinde olur; miktarı $\eta$ belirler.
- İki merkezli LVQ / 1-NN: orta dikme (doğrusal sınır); çok merkezde Voronoi bölgeleri (parçalı doğrusal sınır).
- Ölü vektör: hiç kazanamayan, hiç güncellenmeyen vektör. Çözüm: ilk değerleri örneklerden seç.
- $2^{10} = 1024$: 10 gün tutan tahmin, 11. gün için yine %50.
- Çapraz geçerleme: $N$ grup, her biri bir kez test.
- Model karmaşıklığı arttıkça eğitim hatası düşer, test hatası önce düşer sonra yükselir (yapay sinir ağlarında tam geçerli değil).
- Kümeleme = kuantalama = sıkıştırma; amaç örnekle temsil eden merkez arasındaki farkı en aza indirmek.
- Hiyerarşik: single link (en yakın), complete link (en uzak), group average (ortalama).
- K-means: ata → ortalamaya taşı → tekrarla; batch ve online türleri var.
- SOM = online K-means + merkezler arası komşuluk; kazananla birlikte komşular da güncellenir.
- DBSCAN: $eps$, $min\_p$; çekirdek, sınır, gürültü; gürültü hiçbir kümeye girmez.
- Doğrusal regresyon: $W = (X^TX)^{-1}X^TY$.
- k-NN regresyonu: en yakın $k$ örneğin çıktılarının ortalaması.
- Regresyon ağacı: yaprakta ortalama; bölme ölçütü iki taraftaki standart sapmaların toplamı.

## Detaylı Açıklamalar

- LVQ'nun nasıl hareket ettiği
  - Derste tahtada iki sınıflı küçük bir örnek çizilir (ekrandan, 00:25:00): bir sınıfın noktaları bir yerde, öbür sınıfın noktaları başka bir yerde toplanmıştır ve iki betimleyici vektör (yıldız) rastgele yerlere konmuştur. Örnekler teker teker gelir. Bir örneğe en yakın vektör başka sınıftansa vektör, örnekle kendisini birleştiren doğru boyunca örnekten uzağa itilir. Bu itmeler sürdükçe vektör, kendi sınıfının noktalarının kazananı olmaya başlar; artık bu noktalar onu kendine çeker ve vektör yavaş yavaş kendi sınıfının ortalamasına yerleşir. Sınıf başına iki vektör konursa her biri sınıfın bir alt bölgesine oturur.
  - Kötü bir başlangıçta, örneğin iki vektör de aynı tarafta başlarsa, bir vektörün öbür tarafa geçmesi için hem kendi sınıfının çekmesini hem de öbür sınıfın itmesini aşması gerekir. Bu çok zordur; vektör büyük olasılıkla takılı kalır. LVQ küresel çözüm garantisi vermez.
- LVQ'nun karar sınırları
  - İki merkez varken bir test noktası hangisine yakınsa onun sınıfını alır; iki noktaya eşit uzak noktalar iki merkezi birleştiren doğruya dik ve tam ortasından geçen doğrudur. Merkez sayısı artınca her merkezin Voronoi bölgesi oluşur; aynı sınıftan bölgelerin birleşimi o sınıfın alanıdır ve sınır parçalı doğrusaldır (ekrandan, 00:35:00).
  - Doğrusal ayrılabilen bir veri kümesinde LVQ da yapay sinir ağı da çalışır; iç içe geçmiş bir veri kümesinde daha esnek algoritmalar gerekir.
- Model karmaşıklığı grafiği ve yapay sinir ağları
  - Hoca grafiğin klasik algoritmalarda geçerli olduğunu, yapay sinir ağlarında ise 90'lardan beri tam uymadığının bilindiğini söyler. Az veriyle yapay sinir ağları da grafiğe uyar; çok veri ve yüksek karmaşıklık birlikte olduğunda test hatası düşüp yükseldikten sonra yeniden düşebilir (double descent). Bunun nedeni için önerilen açıklamaların hiçbiri tam tatmin edici değildir.
- Kümelemenin sıkıştırmadaki yeri
  - Tek boyutlu örnekte 10 değer 3 değerle temsil edilir. Merkezi bulmak kümeleme algoritmasının işidir. Görüntüde aynı fikir renklere (256'dan 2 renge kadar) ya da piksel bloklarına uygulanır. Blok kümelemede geçişler yumuşak olmaz; düşük bağlantıda izlenen videolardaki kareli görüntü buna benzer.
  - İletişimde sunucu ve istemcide aynı küme merkezi tablosu (kod kitabı) bulunur. Gönderilen tek şey en yakın merkezin indisidir; merkezin büyüklüğünden bağımsızdır. Küme sayısı azsa indis küçük olur ama görüntü kabalaşır.
- Hiyerarşik kümeleme örneği
  - Slayttaki eklemeli örnekte önce birbirine çok benzeyen D3 ile D7, sonra D4 ile D5, sonra D6 ile D8 birleşir; ardından {D3, D7} kümesi ile {D4, D5} birleşir. Nokta-nokta benzerliği doğrudan hesaplanır; nokta-küme ya da küme-küme benzerliği için elemanlar arası benzerliklerin en küçüğü, en büyüğü ya da ortalaması alınır. <!-- BELİRSİZ: Bu dendrogram slaytının karesi yok; D numaraları altyazıdan alındı. -->
- K-means adım adım (ekrandan, 01:25:00)
  - Slaytta üç merkez (artı işaretleri) başta rastgele konmuştur. Her nokta en yakın merkezin rengini alır, sonra her merkez kendi renginin ortalamasına taşınır. Altı iterasyonda merkezler üç doğal kümenin ortasına yerleşir. Kötü ilk değerlerle (slayt "İlk değerlerin önemi") bir merkez iki kümenin ortasında kalabilir ve küme içi uzaklıklar çok büyük olur; hata fonksiyonu bu farkı gösterir.
- DBSCAN ile K-means farkı
  - Hoca iki veri kümesi gösterir: K-means her noktayı en yakın merkeze bağladığı için dairesel kümeler bulur; DBSCAN ise yoğunluk zincirlerini izleyerek iç içe ya da uzamış kümeleri bulur. Kullanım amaçları farklıdır.
- Doğrusal regresyonun analitik çözümü (ekrandan, 01:50:00)
  - $Y = XW$ denkleminde $W$'yi yalnız bırakmak için soldaki çarpanın birim matrise dönüşmesi gerekir. $X$ genelde kare değildir (örneğin 50 örnek, 250 özellik), bu yüzden $X^{-1}$ alınamaz. Her iki taraf $X^T$ ile çarpılınca $X^TY = X^TXW$ olur; $X^TX$ karedir, tersiyle çarpınca $W = (X^TX)^{-1}X^TY$ bulunur.
- Regresyon ağacında bölme seçimi (ekrandan, 02:00:00)
  - Slaytta $x < 3.16$, $x < 1.36$ gibi bölmeler ve yapraklarda 1.37, -1.35, 1.86 gibi sayılar vardır. Bir noktadan bölünce sol ve sağ taraftaki örneklerin ortalaması çıktı olur. Hangi bölmenin iyi olduğunu ölçmek için iki taraftaki çıkışların standart sapmaları toplanır; küçük olan daha iyidir. $\theta_r = 0.5$, $0.2$, $0.05$ için ağacın giderek büyüdüğü görülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
