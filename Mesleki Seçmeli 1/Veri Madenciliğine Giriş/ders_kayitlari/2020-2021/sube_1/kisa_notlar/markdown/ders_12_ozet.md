# Ders 12 Çalışma Özeti

## Genel Konular

- Öneri sistemlerine (recommender systems) giriş
  - Öneri sistemleri kullanıcının geçmiş etkileşimlerine bakarak ona film, müzik, kitap, haber ya da arkadaş gibi ürünler önerir. Derste Google News, Spotify, Amazon, Netflix ve MovieLens örnek olarak verildi; sosyal ağlarda (Facebook, LinkedIn, Twitter) arkadaş önerisi de aynı mantıkla çalışır.
  - Konu, Stanford Üniversitesi'nin "Mining of Massive Datasets" (Leskovec, Rajaraman, Ullman) slaytları üzerinden anlatıldı (ekrandan, 00:35:00). Slayt dizisinin başlıkları: genel bakış, içerik tabanlı sistemler, işbirlikçi filtreleme (collaborative filtering), öneri sistemlerinin değerlendirilmesi.
- Uzun kuyruk (long tail) olgusu
  - Grafikte yatay eksen popülerliğe göre sıralanmış ürünleri, dikey eksen haftalık satış sayısını gösterir (ekrandan, 00:40:00). Dikey bir çizginin solundaki popüler ürünler hem mağazada hem çevrim içi, sağındaki az satan ürünler yalnız çevrim içi satılır.
  - Fiziksel mağazanın raf alanı sınırlı olduğu için yalnız çok satan ürünleri sergiler. Çevrim içi ortamda bir ürünü listelemenin maliyeti neredeyse sıfırdır.
  - Hocanın anlatımına göre çizginin sağında kalan uzun kuyruğun altındaki toplam satış alanı, solundaki alana eşittir; yani fiziksel mağaza ciddi bir satış potansiyelini kaçırır.
  - "Daha fazla seçenek daha iyi filtre gerektirir": "Into Thin Air" kitabı, yıllarca satmayan "Touching the Void" kitabını öneri sistemleri sayesinde çok satanlar listesine taşıdı (ekrandan, 00:45:00).
- Öneri türleri
  - Elle hazırlanan listeler (favoriler, temel ürünler), basit toplu listeler (en çok satanlar, en yeniler) ve kişiye özgü (tailored to individual users) öneriler. Dersin konusu kişiye özgü önerilerdir.
- Biçimsel model ve fayda (utility) matrisi
  - $C$ müşteriler kümesi, $S$ ürünler kümesi, $u: C \times S \rightarrow R$ fayda fonksiyonu; $R$ puanlar kümesidir ve tam sıralı bir kümedir (ör. 0-5 yıldız ya da $[0,1]$ aralığında gerçel sayı) (ekrandan, 00:50:00).
  - Fayda matrisinde satırlar kullanıcılar, sütunlar ürünlerdir. Hoca bu matrise "rate matrisi" de der. 0-5 yıldızlık puanlar genellikle $[0,1]$ aralığına normalize edilir.
- Temel problemler
  - Puanların toplanması: açık (explicit) yöntemde kullanıcıya puan sorulur, ama az kişi puan verir. Örtük (implicit) yöntemde puan kullanıcının eylemlerinden (tıklama, sayfada kalma süresi, sepete ekleme, satın alma) çıkarılır (ekrandan, 00:55:00).
  - Fayda matrisi seyrektir (sparse): çoğu kullanıcı çoğu ürünü puanlamamıştır.
  - Soğuk başlangıç (cold start): yeni ürünün puanı, yeni kullanıcının geçmişi yoktur (ekrandan, 01:00:00).
  - Üç yaklaşım: içerik tabanlı, işbirlikçi, gizli faktör (latent factor) tabanlı. Derste ilk ikisi anlatıldı.
- İçerik tabanlı öneri (content-based)
  - Ana fikir: $x$ müşterisine, $x$'in daha önce yüksek puan verdiği ürünlere benzeyen ürünleri önermek (ekrandan, 01:15:00). Diğer kullanıcıların puanları hiç kullanılmaz.
  - Ürün profili (item profile) bir öz nitelik kümesidir: film için oyuncular, yönetmen, senarist, tür; görüntü ve video için meta veri ve etiketler; metin için TF-IDF ile seçilen önemli kelimeler (ekrandan, 01:20:00).
  - Kullanıcı profili, kullanıcının puanladığı ürünlerin profillerinden çıkarılır: basit ortalama ya da kullanıcının ortalama puanına göre normalize edilmiş ağırlıklar.
  - Tahmin: kullanıcı profili $\mathbf{x}$ ile ürün profili $\mathbf{i}$ arasındaki kosinüs benzerliği $u(\mathbf{x},\mathbf{i}) = \cos\theta = \dfrac{\mathbf{x}\cdot\mathbf{i}}{\lVert\mathbf{x}\rVert\,\lVert\mathbf{i}\rVert}$ (ekrandan, 01:35:00).
- İşbirlikçi filtreleme (collaborative filtering)
  - $x$ kullanıcısına puanları en çok benzeyen $N$ kullanıcı bulunur; onların beğenip $x$'in görmediği ürünlerin puanı tahmin edilip yüksek olanlar önerilir.
  - Benzerlik ölçüleri: Jaccard, kosinüs, merkezlenmiş kosinüs (Pearson korelasyonu).
  - Puan tahmini: basit ortalama ya da benzerlikle ağırlıklı ortalama.
  - Kullanıcı-kullanıcı ve ürün-ürün (item-item) işbirlikçi filtreleme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Uzun kuyruk grafiği
  - Hoca bu grafiği çok çarpıcı bulduğunu, özellikle üzerinde durmak istediğini söyledi. Az satan ürünlerin her biri az satılır ama kuyruk çok uzun olduğu için toplamları çok büyük bir miktara ulaşır.
- İçerik tabanlı yöntemde yalnız kullanıcının kendi puanları kullanılır
  - Hoca bunu birkaç kez tekrarladı: diğer kullanıcıların bilgisi bu yöntemde kesinlikle kullanılmaz.
- Ortalama çıkararak normalizasyon
  - Ortalama çıkarılınca 0 nötr, negatif değerler beğenmeme, pozitif değerler beğenme anlamına gelir. Bu sayede beğenilmeyen ürünler hesaba doğru yönde girer.
- Merkezlenmiş kosinüs = Pearson korelasyonu
  - Hoca "bunu unutmayın" diyerek literatürdeki adının Pearson korelasyonu olduğunu vurguladı.
- Ağırlıklı ortalama ile tahmin
  - İkinci tahmin yöntemi (benzerlikle ağırlıklandırma) daha anlamlı ve daha doğrudur; tercih edilen yöntem budur.
- Ürün-ürün benzerliği genellikle tercih edilir
  - Gerçek sistemlerde kullanıcı sayısı ürün sayısından çok daha fazladır. Benzerliği sayının az olduğu tarafta hesaplamak daha ölçeklenebilirdir.
- TF-IDF bu dersin konusu değil
  - Hoca TF-IDF hesabını anlatmayacağını ve bununla ilgili soru sormayacağını belirtti; yalnız metin öz niteliklerinin nasıl çıkarıldığına örnek olarak değindi.

## Kısa Tekrar Notları

- Fayda (utility) matrisi: satır = kullanıcı, sütun = ürün, hücre = puan. Seyrektir.
- Soğuk başlangıç: yeni ürün (cold item) ve yeni kullanıcı (cold user) için puan/geçmiş yoktur.
- Açık puan: kullanıcıya sorulur, ölçeklenmez. Örtük puan: tıklama, süre, sepete ekleme, satın almadan çıkarılır.
- İçerik tabanlı: ürün profili + kullanıcı profili + kosinüs benzerliği.
- İkili matriste kullanıcı profili: 5 filmin 2'sinde A, 3'ünde B varsa ağırlıklar $2/5 = 0.4$ ve $3/5 = 0.6$.
- Yıldızlı puanda: ortalama (3) çıkarılır; A: $0, +2 \Rightarrow 1$; B: $-2, -1, +1 \Rightarrow -2/3$.
- Kosinüs: $\theta = 0^\circ \Rightarrow 1$ (en benzer), $90^\circ \Rightarrow 0$, $180^\circ \Rightarrow -1$ (tam zıt).
- İçerik tabanlının artıları: başka kullanıcı verisi gerekmez, özgün zevke öneri, yeni ve popüler olmayan ürün önerilebilir, açıklanabilir. Eksileri: uygun öz nitelik bulmak zor, aşırı uzmanlaşma (profil dışı öneri yok), yeni kullanıcı için soğuk başlangıç.
- Jaccard: $|r_A \cap r_B| / |r_A \cup r_B|$; puanları yok sayar.
- Kosinüs (boşlar 0): eksik puanları negatif gibi ele alır.
- Merkezlenmiş kosinüs (Pearson): satır ortalaması çıkarılır, boşlar "ortalama" sayılır.
- Örnekte: Jaccard $1/5 < 2/4$ (yanlış sezgi); kosinüs $0.38 > 0.32$ (az fark); merkezlenmiş kosinüs $0.09 > -0.56$ (belirgin fark).
- Tahmin: $\hat r_{xi} = \frac{1}{k}\sum_{y\in N} r_{yi}$ ya da $\hat r_{xi} = \dfrac{\sum_{y\in N} s_{xy} r_{yi}}{\sum_{y\in N} s_{xy}}$.
- Ürün-ürün CF örneğinde 1. filme en benzer iki film 6 (0.59) ve 3 (0.41); 5. kullanıcının 1. filme tahmini puanı yaklaşık 2.6.

## Detaylı Açıklamalar

- Öneri sistemleri neden gerekli?
  - Fiziksel mağazacılıkta raf kapasitesi sergilenebilecek ürün sayısını kısıtlar; mağaza sahibi kira gibi giderleri karşılamak için yalnız popüler ürünleri sergiler. Çevrim içi satışta bir ürünü listelemek yalnız veri tabanına bir satır eklemek demektir. Bu durumda çok sayıda az satan ürün de satılabilir, ama kullanıcının bu kadar büyük bir seçenek kümesinde ilgisini çekecek ürünü bulabilmesi için iyi bir filtreye, yani öneri sistemine ihtiyaç vardır. "Touching the Void" örneği öneri sistemlerinin unutulmuş ürünleri yeniden keşfettirebildiğini gösterir.
- Puan toplama ve fayda matrisi
  - Puanlar 0-5 ya da 1-5 yıldız olabilir; bazı sistemler yarım yıldıza izin verir. Uygulamada puanlar $[0,1]$ aralığına normalize edilerek kullanılır. Hocanın gösterdiği film örneğinde bir kullanıcı Avatar'a 5 yıldız (normalize 1), Matrix'e 1 yıldız (normalize 0.2) vermiştir; başka bir kullanıcı tam tersini yapmıştır. Bu iki kullanıcı birbirine en zıt kullanıcılardır. <!-- BELİRSİZ: Bu örnek matrisin karesi yok; film adlarından biri altyazıda "Pretz" diye geçiyor, tam adı ve diğer hücre değerleri okunamadı. -->
  - Örtük puanlamada site üzerindeki her iz kayıtlarda tutulur: ürüne tıklamak, ürünü yeni ekranda açmak, ekranın açık kaldığı süre, sepete eklemek ve satın almak ayrı ayrı ağırlıklandırılmış puanlara dönüştürülür. Sepete eklenen her ürün satın alınmaz, bu yüzden sepete ekleme ile satın almanın puanı farklıdır.
- İçerik tabanlı öneri
  - Eylem planı: kullanıcının beğendiği ürünlerden (ör. kırmızı daire, kırmızı üçgen) ürün profilleri çıkarılır, bunlardan kullanıcı profili oluşturulur ("kırmızıyı, daireyi ve üçgeni seviyor"), sonra bu profille eşleşen ürünler önerilir.
  - Ürün profili vektörü ikili (Boolean) ya da gerçel değerli olabilir: kullanıcının ürünle teması var/yok ya da verdiği puan.
  - Metin öz nitelikleri: belgedeki önemli kelimeler profil olarak alınır; önemli kelimeleri seçmek için metin madenciliğindeki TF-IDF (terim frekansı × ters belge frekansı) sezgisi kullanılır. Terim frekansı, terimin belgedeki geçiş sayısının o belgede en sık geçen terimin sayısına oranıdır.
  - Örnek 1, ikili fayda matrisi (ekrandan, 01:25:00): filmlerin tek öz niteliği oyuncudur. Kullanıcı 5 film izlemiş, 2'sinde A, 3'ünde B oynamıştır. Kullanıcı profili ürün profillerinin ortalamasıdır: A'nın ağırlığı $2/5 = 0.4$, B'nin ağırlığı $3/5 = 0.6$.
  - Örnek 2, yıldızlı puanlar (ekrandan, 01:30:00): A'nın filmlerine 3 ve 5, B'nin filmlerine 1, 2 ve 4 verilmiştir. Kullanıcının ortalama puanı $15/5 = 3$ çıkarılır. A'nın normalize puanları $0, +2$, ağırlığı $(0+2)/2 = 1$. B'nin normalize puanları $-2, -1, +1$, ağırlığı $-2/3 \approx -0.67$. Kullanıcı A'nın filmlerini sever, B'ninkileri pek sevmez. İkili örnekte B'nin ağırlığı daha yüksek çıkarken puanlar kullanılınca durum tersine döner.
  - Kosinüs benzerliği: iki vektör aynı yöndeyse açı küçüktür ve kosinüs 1'e yakındır; açı $90^\circ$ ise kosinüs 0 (benzerlik yok), $180^\circ$ ise $-1$ (tam zıt) olur. Kullanıcıya, profiliyle kosinüsü 1'e en yakın ürünler önerilir.
  - Artılar (ekrandan, 01:40:00): başka kullanıcıların verisine gerek yoktur; özgün zevkleri olan kullanıcılara öneri yapılabilir; yeni ve popüler olmayan ürünler önerilebilir (ilk puanlayan problemi yoktur); öneri, ürünün hangi öz nitelikleri yüzünden önerildiğiyle açıklanabilir.
  - Eksiler: uygun öz nitelikleri bulmak zordur; aşırı uzmanlaşma vardır, kullanıcının profili dışındaki ürünler hiç önerilmez ve kullanıcı yeni şeyler deneyimleyemez; yeni kullanıcılar için soğuk başlangıç problemi vardır.
- İşbirlikçi filtreleme ve benzerlik ölçüleri
  - Örnek matris (ekrandan, 02:05:00): kullanıcılar A, B, C, D; filmler HP1, HP2, HP3, TW, SW1, SW2, SW3. A: HP1=4, TW=5, SW1=1. B: HP1=5, HP2=5, HP3=4. C: TW=2, SW1=4, SW2=5. D: HP2=3, SW3=3. Sezgi: A, B'ye C'den daha çok benzer, yani $\text{sim}(A,B) > \text{sim}(A,C)$ olmalıdır.
  - Jaccard (ekrandan, 02:10:00): matris ikiliye çevrilir. $\text{sim}(A,B) = 1/5$, $\text{sim}(A,C) = 2/4$. Sonuç sezgiye ters çıkar, çünkü puan değerleri yok sayılır. Elde yalnız ikili matris varsa Jaccard kullanmak zorunludur.
  - Kosinüs (ekrandan, 02:15:00): boşlar 0 alınır. $\text{sim}(A,B) = \dfrac{20}{\sqrt{16+25+1}\,\sqrt{25+25+16}} \approx 0.38$, $\text{sim}(A,C) \approx 0.32$. Sezgiye uyar ama fark küçüktür; eksik puanlar negatif gibi ele alınır.
  - Merkezlenmiş kosinüs (ekrandan, 02:20:00): her satırdan o kullanıcının ortalaması çıkarılır (A: $10/3$, B: $14/3$, C: $11/3$, D: 3). A satırı $2/3, 5/3, -7/3$ olur. Sonuçta $\text{sim}(A,B) = 0.09$, $\text{sim}(A,C) = -0.56$; fark belirginleşir, A ile C'nin zıt zevkte olduğu negatif değerden görülür. Eksik puanlar "ortalama" sayılır; zor ve kolay puan veren kullanıcıların farkı dengelenir. Bu ölçünün bilinen adı Pearson korelasyonudur.
- Puan tahmini (ekrandan, 02:25:00)
  - $N$, $x$'e en benzeyen ve $i$ ürününü puanlamış $k$ kullanıcıdır. Seçenek 1: $\hat r_{xi} = \frac{1}{k}\sum_{y\in N} r_{yi}$. Seçenek 2: $\hat r_{xi} = \dfrac{\sum_{y\in N} s_{xy}\, r_{yi}}{\sum_{y\in N} s_{xy}}$, $s_{xy} = \text{sim}(x,y)$. İkincisinde puanlar benzerlikle ağırlıklandırılır ve ağırlıklar toplamına bölünerek normalize edilir. Kullanıcılar arasında benzerlik hesaplandığı için bu yönteme kullanıcı tabanlı (user-user) işbirlikçi filtreleme denir.
  - Ürün-ürün işbirlikçi filtrelemede $i$ ürününe benzeyen ürünler $j$ bulunur ve $\hat r_{xi} = \dfrac{\sum_{j\in N(i;x)} s_{ij}\, r_{xj}}{\sum_{j\in N(i;x)} s_{ij}}$ ile tahmin yapılır.
  - Ürün-ürün örneği (ekrandan, 02:35:00): satırlar 6 film, sütunlar 12 kullanıcıdır; $|N|=2$. 5. kullanıcının 1. filme puanı aranır. Pearson benzerlikleri: $\text{sim}(1,m) = 1.00, -0.18, 0.41, -0.10, -0.31, 0.59$. En benzer iki film 6 (0.59) ve 3 (0.41); 5. kullanıcı bunlara 3 ve 2 vermiştir. Tahmin: $(0.41\cdot 2 + 0.59\cdot 3)/(0.41+0.59) \approx 2.6$.
  - Gerçek sistemlerde kullanıcı sayısı film sayısından çok fazladır; benzerliği az olan tarafta (ürünler) hesaplamak daha ucuz ve ölçeklenebilirdir. Bu yüzden çoğunlukla ürün-ürün benzerliği tercih edilir.
- Güncel eğilimler
  - Derin öğrenme tabanlı hibrit çözümler, kullanıcı yorumlarından duygu (olumlu/olumsuz/nötr) çıkararak puan üretme, güvenilir kullanıcıları (trusted user) öne çıkarma ve sahte hesaplarla puan manipülasyonunu önleme çalışmaları konuşuldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
