# Ders 11 Çalışma Özeti

## Genel Konular

- Parametre ve hiperparametre
  - Hiperparametre, algoritmanın çalışmak için ihtiyaç duyduğu ama kendisinin bulamadığı, kullanıcının vermesi gereken değerdir (k-NN'deki $k$, yapay sinir ağındaki katman ve nöron sayısı, aktivasyon fonksiyonu).
  - Parametre, algoritmanın eğitim sürecinde veriden öğrendiği değerdir (doğrusal modeldeki $w_0, w_1, w_2$, karar ağacının bölme noktaları, yapay sinir ağının ağırlıkları). Rastgele bir yerden başlatılır, eğitim örneklerindeki tahmin ile gerçek sınıf arasındaki uyuma göre adım adım iyileştirilir.
- En yakın k komşu (k-NN)
  - "Bana arkadaşını söyle, sana kim olduğunu söyleyeyim." Eğitim süreci yoktur. Test örneğine en yakın $k$ eğitim örneği bulunur, aralarında en çok hangi sınıf varsa test örneği o sınıfa atanır.
  - $k$ küçüldükçe yöntem yerel değişimlerden ve gürültüden daha çok etkilenir. $k=N$ (eğitim örneği sayısı) seçilirse her örneğe en çok örneği olan sınıf söylenir; bu, daha önce görülen "Zero Rule" (çoğunluk sınıfını tahmin etme) yaklaşımına dönüşür.
  - Dezavantaj: Test için eğitim kümesinin tamamı gerekir. Her test örneği bütün eğitim örnekleriyle karşılaştırılır; test süresi uzun, bellek ihtiyacı büyüktür. Yapay sinir ağı, karar ağacı ve doğrusal regresyonda ise test için yalnız model yeterlidir.
  - 1-NN'in eğitim kümesindeki başarısı %100'dür (her örneğin en yakın komşusu kendisidir; aynı noktada farklı sınıftan örnek yoksa).
  - 1-NN, en karmaşık karar sınırlarını üretebilen algoritmadır; $k$ arttıkça karar sınırı yumuşar.
- Öğrenmeli Vektör Kuantalama (LVQ, Kohonen)
  - Amaç: 1-NN'de bütün eğitim noktaları yerine az sayıda "betimleyici vektör" (prototip, centroid) kullanmak. Bu vektörlerin hem koordinatı hem sınıfı vardır; sayısı ($c$) hiperparametredir.
  - Algoritma (ekrandan, 00:25:00): öğrenme oranı $\eta$, en fazla eğitim sayısı $n$, betimleyici vektörler $\mu_1,\dots,\mu_c$ rastgele başlatılır. $n$ kez: bir eğitim örneği $x$ alınır; en yakın vektör $k \leftarrow \arg\min_j \lVert x-\mu_j \rVert$ bulunur; sınıflar aynıysa $\mu_k \leftarrow \mu_k + \eta(x-\mu_k)$ (ödül, yaklaştır), farklıysa $\mu_k \leftarrow \mu_k - \eta(x-\mu_k)$ (ceza, uzaklaştır).
  - $\eta=1$ ise vektör doğrudan $x$'in üstüne gider, $\eta=0.5$ ise ikisinin tam ortasına gelir; küçük $\eta$ daha az yaklaştırır.
  - Eğitimden sonra yalnız bu vektörlerle k-NN çalıştırılır; test çok hızlanır.
  - Tepe tırmanma (yerel arama) yapısındadır; yerel bir noktaya takılabilir, birkaç kez çalıştırmak gerekir.
- Karar sınırları
  - İki sınıf ve iki prototip varsa karar sınırı, iki noktayı birleştiren doğruya ortasından dik olan doğrudur (doğrusal sınır). Prototip sayısı arttıkça sınır karmaşıklaşır.
- Eğitim başarısı neyi gösterir: borsa tahmini hikayesi
  - 1024 kişiye "yarın dolar çıkacak/düşecek" tahmini yarı yarıya gönderilir, her gün doğru tahmin alanlar yine ikiye bölünür. Yaklaşık 10 gün sonra bir kişi, 10 günün hepsini doğru tahmin eden birini görmüş olur ($2^{10}=1024$). Bu, piyasa bilgisi gerektirmez; eğitim verisindeki başarının tek başına güvenilir olmadığını gösterir.
- Çapraz geçerleme
  - Veri kümesi $N$ eşit gruba bölünür; her seferinde bir grup test, kalanı eğitim olur. $N$ test sonucunun ortalaması performanstır. Her örnek en az bir kez testte yer alır; tek bir eğitim/test ayrımından daha güvenilirdir.
- Sınıflandırma yöntemlerinin karşılaştırılması
  - Aynı (somon/levrek) veri kümesinde farklı yöntemler farklı karar sınırları üretir (ekrandan, 01:00:00).
  - 6 veri kümesi ve 5 sınıflandırıcıyla yapılan tabloda her veri kümesinde farklı bir algoritma en iyidir. Her veride en iyi olan tek algoritma yoktur; denemek gerekir. <!-- BELİRSİZ: tablo değerleri karede görünmüyor; altyazıda yalnız 97, 99, 72, 79 gibi en iyi değerler okunuyor. -->
- Model karmaşıklığı, aşırı eğitme ve genelleştirme
  - Model karmaşıklığı, modelin öğrendiği parametre sayısıdır. Karmaşıklık arttıkça eğitim hatası sürekli düşer (1-NN ya da saf yapraklara kadar büyüyen karar ağacında sıfıra iner).
  - Test hatası bir noktaya kadar düşer, sonra gürültü öğrenildiği için artar. Amaç bu optimum noktayı bulmaktır.
  - Aşırı eğitme (ezberleme): eğitimde çok iyi, testte kötü performans. Genelleştirme: test kümesinde iyi performans.
  - İstisna: yapay sinir ağlarında katman ve nöron arttıkça test hatası her zaman bu eğriyi izlemiyor; hocaya göre henüz matematiksel açıklaması yapılmamış bir konu.
- Kümeleme algoritmaları
  - Eğiticisiz öğrenmedir; örneklerin sınıf bilgisi yoktur. Veriyi en iyi temsil eden vektörler bulunur, veri bu vektörlerle kodlanır; bu yüzden birçok sıkıştırma yönteminin temelindedir.
  - Örnek (ekrandan, 01:05:00): 12-15-13-87-4-5-9-67-1-2 verisi 3 değerle 12-12-12-77-3-3-3-77-3-3 olarak temsil edilir. Kümeler: {12, 15, 13}, {87, 67}, {4, 5, 1, 2, 9}.
  - Renk kümeleme: 256 gri tonlu resim adım adım 2 renge indirilir. Gri seviyede centroid tek boyutlu, RGB'de üç boyutludur. Renk sayısı azalınca piksel başına bit sayısı azalır.
  - Resim kümeleme (ekrandan, 01:15:00): 10×10'luk bloklar 100 boyutlu vektörlerdir; 200×200 resimdeki 400 blok 20 centroid ile temsil edilir.
  - Kullanım: iki tarafta aynı kod tablosu ($m_i$ vektörleri) varsa $x$ yerine yalnız en yakın $m_i$'nin indisi $i$ gönderilir; alıcı $\hat{x}=m_i$ kabul eder. Kayıplı sıkıştırma ve haberleşmedir; kayıp $x$ ile $m_i$ arasındaki farktır.
- Hiyerarşik kümeleme
  - Eklemeli (çok kümeden tek kümeye): birbirine en çok benzeyen iki kümeyi birleştir, tekrar et. Bölmeli (tek kümeden çok kümeye): küme içinde birbirine en az benzeyen iki elemanı bul, kümeyi bu iki elemana yakınlığa göre böl, alt kümelerde tekrar et.
  - İki kümenin benzerliği: en benzer elemanların benzerliği (single link), en benzemeyen elemanların benzerliği (complete link), bütün eleman çiftlerinin ortalaması (group average).
  - Sonuç dendrogramla gösterilir; istenen küme sayısına ulaşılan yerde kesilir. Bölmelide istenen küme sayısında ya da bir benzerlik eşiğinde durulur.
- K-means
  - Yalnız sayısal veriyle çalışır. 1) Rastgele $k$ küme merkezi ata. 2) Her örneği en yakın merkezin kümesine ata. 3) Merkezleri kendi kümelerinin ortasına taşı. 4) Küme değiştiren örnek kalmayıncaya kadar (ya da en fazla tur sayısına kadar) 2 ve 3'ü tekrarla.
  - Adım adım gösterimde (ekrandan, 01:25:00) renkler sınıf değil, örneğin hangi merkeze ait olduğunu gösterir.
  - Yerel arama algoritmasıdır; ilk değerler farklıysa sonuç farklı olabilir. Hata fonksiyonu, her örneğin kendi küme merkezine uzaklığı üzerinden hesaplanır.
  - Toplu (batch) k-means bütün örneklerle güncelleme yapar; tekli (online) k-means'te her örnek gelince yalnız en yakın merkez örneğe doğru yaklaştırılır (LVQ'daki ödül gibi, ceza yok). Online sürüm büyük veride bellek sorununu önler; derin öğrenmede de bu yaklaşım kullanılır.
- Kendi kendini düzenleyen haritalar (SOM, Kohonen)
  - K-means'te merkezler arasında ilişki yoktur. SOM'da merkezler 1 ya da 2 boyutlu bir dizide komşudur. Kazanan merkez ve komşuları güncellenir; yakın komşular uzak komşulardan daha çok hareket eder (ekrandan, 01:30:00).
  - SOM, komşuluk tanımlanmış online k-means'tir. Verinin 1 ya da 2 boyutlu uzaydaki yansıması (topolojisi) elde edilir.
- DBSCAN (yoğunluk tabanlı kümeleme)
  - K-means, SOM gibi yöntemler bölgesel yakınlığa göre kümeler; iç içe ya da uzun şekilli yoğun yapıları ayıramaz.
  - Hiperparametreler: eps ve min_p (ekrandan, 01:35:00). Çekirdek: eps komşuluğunda en az min_p nokta bulunan nokta. Sınır: eps komşuluğunda min_p'den az nokta bulunan nokta. Gürültü: eps komşuluğunda hiç nokta bulunmayan nokta.
  - Gürültüler atılır; birbirine eps mesafede olan çekirdekler birleştirilir (küme sayısı eps'e bağlıdır); sınır noktalar en yakın çekirdeğin kümesine atanır.
- Basit doğrusal regresyon (analitik çözüm)
  - $X$: girişler ($n \times d$), $Y$: çıkışlar ($n \times 1$), model $Y=XW$, $W$: katsayılar ($d\times 1$).
  - $X$ kare değilse tersi alınamaz. İki taraf $X^T$ ile çarpılır ($X^TX$ kare matristir) ve $W=(X^TX)^{-1}X^TY$ bulunur (ekrandan, 01:40:00).
  - Çok büyük veride $X^TX$'in tersini almak zordur; o zaman iteratif yöntemlere geçilir.
- k-NN ile regresyon
  - Örnek veri (ekrandan, 01:45:00): $(x_1, y)$ = (1, 7), (2, 6), (6, 3), (4, 9).
  - $k=1$: basamak fonksiyonu oluşur. $x<1.5$ için 7, $1.5<x<3$ için 6, $3<x<5$ için 9, $x>5$ için 3.
  - $k=4$: en yakın $k$ örneğin çıkışlarının ortalaması verilir; dört örnek olduğu için her yerde $25/4=6.25$.
- Regresyon ağaçları
  - Karar ağacı algoritması aynıdır; entropi yerine bölgelerdeki çıkışların standart sapma toplamı en küçük olan bölme seçilir. Yaprak çıkışı, o bölgedeki örneklerin çıkış ortalamasıdır.
  - Kabul edilen hata ($\theta_r$ = 0.5, 0.2, 0.05) küçüldükçe ağaç büyür (ekrandan, 02:05:00). Sıfıra indirilirse 1-NN regresyonuna benzer bir yapı oluşur.
- Çok boyutlu verilerle çalışmak
  - Her boyutta ortadaki yarım aralık "güvenli bölge" sayılırsa bu bölgenin oranı $1/2^p$ olur ($p$: boyut). Boyut arttıkça veri sınırlara yığılır.
  - [0,1] aralığını temsil eden 10 nokta için en yakın noktaya ortalama uzaklık 0.5 kalsın istenirse gereken nokta sayısı 1 boyutta 10, 2 boyutta 100, 3 boyutta 1000, $p$ boyutta $10^p$ olur (ekrandan, 02:10:00). Boyut arttıkça gereken örnek sayısı üstel artar; az örnekle çok boyutlu uzayda çalışmak risklidir.
- Veri sızıntısı (data leakage) (ekrandan, 02:15:00)
  - Test kümesinin eğitime karışması: normalizasyon ve özellik seçimi bütün veri üzerinde yapılırsa test kümesi işe karışır. Doğrusu: özellik seçimi eğitim kümesiyle yapılır, seçilen özellikler test kümesine uygulanır.
  - Test zamanında elde olmayacak özelliklerin kullanılması: $x(t)=f(x(t-1),x(t+1))$.
  - Zaman serilerinde rastgele bölme hatası: bir $t$ anından öncesi eğitim, sonrası test olmalıdır.
  - Çıkışla korelasyonu çok yüksek özellikler (kişi tanımada kimlik no, telefon no).
- Weka uygulaması
  - ARFF dosyası, özellik tanımları ve satır-sütun veri matrisi içeren düz metin dosyasıdır. Iris: 150 örnek, 5 öznitelik (4 özellik + sınıf), 3 sınıf.
  - Test seçenekleri: eğitim kümesi, ayrı test kümesi, 10 katlı çapraz geçerleme, yüzde bölme.
  - Iris'te ZeroR %33 başarı verir (hep aynı sınıf). J48 eğitime %20 (30 örnek) ile 120 test örneğinin 115'ini doğru sınıflandırır; karışıklık matrisinde hatalar versicolor ile virginica arasındadır (ekrandan, 02:25:00).
  - Breast Cancer (286 örnek, 10 öznitelik, 201/85 sınıf dağılımı) üzerinde J48, Random Forest, SVM (SMO), Naive Bayes ve yapay sinir ağı farklı sonuç verir; SVM %72.7 (143 testten 104 doğru) (ekrandan, 02:30:00).
  - Filter menüsünde özellik seçimi ve PCA, Cluster sekmesinde DBSCAN, SimpleKMeans, hiyerarşik kümeleme vardır.

## Hocanın Özellikle Vurguladığı Kısımlar

- k-NN'in asıl sorunu test zamanıdır
  - Model çıkarmadığı için test için eğitim kümesinin tamamı gerekir; LVQ bu sorunu birkaç prototiple çözer.
- Yerel arama algoritmalarında ilk değerin önemi
  - LVQ, k-means, yapay sinir ağı ve doğrusal regresyonun iteratif sürümü tepe tırmanmadır; yerel noktaya takılabilir, birkaç kez çalıştırmak gerekir. Makine öğrenmesindeki algoritmaların çok büyük kısmı yerel aramadır.
- Tek bir süper algoritma yok
  - Her veri kümesi için farklı algoritmalar ve hiperparametreler denenmelidir (hiperparametre optimizasyonu).
- Aşırı eğitme ve optimum karmaşıklık
  - Eğitim hatası düşük diye model iyi değildir; test hatasının en düşük olduğu karmaşıklık aranır.
- Veri sızıntısına dikkat
  - Özellik seçimi bütün veri üzerinde yapılmamalı; zaman serisi rastgele bölünmemeli; veri kümesinin özellikleri incelenmeden algoritmaya verilmemeli.

## Kısa Tekrar Notları

- Hiperparametre kullanıcıdan alınır, parametre veriden öğrenilir.
- k-NN: eğitim yok, test pahalı; $k=N$ ise Zero Rule; 1-NN eğitim başarısı %100.
- LVQ: aynı sınıfsa $\mu_k \leftarrow \mu_k + \eta(x-\mu_k)$, farklıysa $\mu_k \leftarrow \mu_k - \eta(x-\mu_k)$.
- İki prototip için karar sınırı, birleştiren doğrunun orta dikmesidir.
- Çapraz geçerleme: $N$ grup, her biri bir kez test, ortalama alınır.
- Karmaşıklık arttıkça eğitim hatası düşer, test hatası önce düşer sonra artar.
- Kümeleme: sınıf yok, temsil vektörleri bulunur, sıkıştırmada kullanılır.
- Hiyerarşik: eklemeli/bölmeli; single link, complete link, group average; dendrogram kesilerek küme sayısı seçilir.
- K-means: ata, merkezleri güncelle, tekrarla; batch ve online sürümler.
- SOM: komşuluklu online k-means.
- DBSCAN: eps, min_p; çekirdek, sınır, gürültü.
- Doğrusal regresyon: $W=(X^TX)^{-1}X^TY$.
- k-NN regresyonu: komşuların çıkış ortalaması; $k=1$ basamak fonksiyonu.
- Regresyon ağacı: entropi yerine standart sapma, yaprakta ortalama.
- Boyut laneti: güvenli bölge $1/2^p$, gereken örnek $10^p$.
- Veri sızıntısı: test bilgisinin eğitime karışması, gelecekteki bilgi, zaman serisinde rastgele bölme, kimlik gibi özellikler.

## Detaylı Açıklamalar

- k-NN ve LVQ ilişkisi
  - k-NN, test örneğine en yakın $k$ eğitim örneğinin oy çokluğuyla karar verir. Eğitim süreci yoktur ama her test örneği için bütün eğitim kümesiyle uzaklık hesaplanır. Slayttaki örnekte her grupta 20 civarında örnek, toplam yaklaşık 120 örnek vardır; bunların yerine 6 "belirlenmiş" nokta (eğitim örneklerinden seçilmiş değil, sonradan bulunmuş noktalar) yeterli olabilir (ekrandan, 00:35:00).
  - LVQ bu noktaları bulur. Prototipler rastgele başlatılır (sınıfları eğitim verisinin sınıf dağılımına uygun, koordinatları eğitimden rastgele seçilerek ya da uzayın aralığında düzgün dağılımla). Her eğitim örneği için kazanan (en yakın) prototip aynı sınıftaysa örneğe doğru, farklı sınıftaysa örnekten uzağa itilir. Bir grubun ortasındaki prototip, etrafındaki bütün örnekler onu kendine çektiği için kendiliğinden grubun ortasına yerleşir; ortalamayı ayrıca hesaplamak gerekmez.
- Karar sınırının şekli
  - İki prototip (ya da 1-NN'de iki örnek) varsa sınır, ikisini birleştiren doğrunun orta dikmesidir. Üç prototipte sınır parçalı doğrulardan oluşur; üçüne eşit uzaklıkta bir nokta vardır. Prototip ya da örnek sayısı arttıkça sınır karmaşıklaşır; 1-NN, yapay sinir ağlarından bile karmaşık sınır üretebilir.
- Doğrusal regresyonun türetilmesi
  - $Y=XW$'den $X^{-1}$ ile çarpma yalnız $X$ kare ise mümkündür. Bunun yerine $X^TY=X^TXW$ yazılır; $X^TX$ ($d\times d$) kare matristir, tersi alınarak $W=(X^TX)^{-1}(X^TY)$ bulunur. Küçük veride hızlı ve avantajlıdır; çok büyük matrislerde ters alma zorlaştığı için iteratif yöntemler kullanılır.
- Regresyon ağacındaki slayt örneği (ekrandan, 02:05:00)
  - $\theta_r=0.5$ için ağaç: kök $x<3.16$; evet dalında $x<1.36$ (evet: 1.37, hayır: −1.35); hayır dalında 1.86. 1.37, $x<1.36$ bölgesindeki üç örneğin çıkış ortalaması, −1.35 ise $1.36 \le x < 3.16$ bölgesindeki iki örneğin ortalamasıdır; 1.86 sağdaki yedi örneğin ortalamasıdır.
  - $\theta_r$ 0.2 ve 0.05'e indikçe yeni bölmeler ($x<5.96$, $x<6.91$, $x<0.76$, $x<6.31$) eklenir.
- Weka'da hiperparametreler
  - Bir sınıflandırıcının adına tıklanınca açılan ayarlar o algoritmanın hiperparametreleridir (örneğin Random Forest'ın dört hiperparametresi). Veri kümesine uygulanamayan algoritmalar (sınıflandırma verisinde regresyon algoritmaları) soluk renkte görünür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
