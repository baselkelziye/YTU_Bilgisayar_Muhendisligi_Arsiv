# Ders 9 Çalışma Özeti

## Genel Konular

- Öneri sistemlerinin motivasyonu
  - Web'de ürün sayısı neredeyse sınırsızdır: kitaplar, filmler, müzikler, videolar, haberler. Kullanıcı arama yapabilir ama arama arayüzleri sınırlıdır ve sonuçlar arasında yine çok gezinmek gerekir. Öneri sistemleri, kullanıcının ilgileneceği ürünleri ona doğrudan önerir (ekrandan, 00:20:00).
  - Fiziksel mağazada, sinema salonunda ya da TV kanalında yer ve zaman kısıtı vardır (kıtlık). Web'de ise bolluk vardır.
- Uzun kuyruk (long tail) olgusu (ekrandan, 00:25:00)
  - X ekseninde ürünler popülerliğe göre sıralanır (soldan sağa azalan popülerlik), Y ekseninde haftalık satın alma ya da izlenme sayısı vardır.
  - Sol taraftaki popüler ürünler hem mağazada hem çevrim içi bulunur ("Retail and Online"). Sağdaki az popüler ürünler yalnız çevrim içi bulunur ("Items available only online").
  - Kuyruğun altındaki toplam alan, popüler ürünlerin alanından büyüktür. Bu yüzden az popüler ürünleri doğru kişiye önermek önemlidir.
  - Örnek: dağcılık konulu iki kitaptan önce yayımlanan pek ilgi görmemiş, sonra yayımlanan çok satan olmuştur. Amazon'un öneri motoru eski kitabı yeni kitabı alanlara önerince eski kitap da çok satanlara girmiş, hatta yenisinden fazla satmıştır.
  - Öneri sistemleri yalnız ürün değil, sosyal ağlarda (Facebook, LinkedIn, Twitter) kişi de önerir.
- Öneri türleri
  - Editoryal ya da elle hazırlanmış öneriler: sitenin sahibi ya da editörü belirler (örnek: kafedeki "günün içeceği" panosu). Kullanıcı davranışına bakmaz.
  - Basit toplamlar (simple aggregates): en çok izlenen ilk 10, en çok satanlar, son eklenenler. Kullanıcıların toplu davranışına bakar, bireysel davranışa bakmaz.
  - Bireysel kullanıcıya göre öneri: kullanıcının kendi etkileşimlerinden (örneğin sürekli aksiyon filmi izlemesi) yola çıkar. Dersin konusu budur.
- Biçimsel model (ekrandan, 00:35:00)
  - $C$: müşteriler kümesi, $S$: ürünler kümesi.
  - Fayda fonksiyonu (utility function) $u: C \times S \to R$. $R$ puanlar kümesidir ve tam sıralı bir kümedir (örnek: 0-5 yıldız, $[0,1]$ arası gerçel sayı; derste 0/1 ikili puan da sayıldı).
  - Her müşteri-ürün ikilisi için bir puan bulunur, puanlar büyükten küçüğe sıralanır ve en yüksek puanlı ürün önerilir.
- Fayda matrisi (utility matrix)
  - Satırlar kullanıcılar, sütunlar ürünlerdir. Çoğu kullanıcı geri bildirim vermediği için matris seyrektir: değerlerin çoğu boştur.
  - Öneri algoritmalarının hepsinin hedefi, dolu hücrelerden yararlanarak boş hücrelerin değerini tahmin etmektir. Boş hücrenin tahmini yüksek çıkarsa o ürün o kullanıcıya önerilir.
- Üç temel problem (ekrandan, 00:40:00)
  - (1) Bilinen puanları toplamak: fayda matrisindeki veri nasıl toplanır?
  - (2) Bilinmeyen puanları bilinenlerden tahmin etmek: asıl ilgi yüksek tahminlerdedir; kullanıcının neyi sevmediğiyle değil, neyi sevdiğiyle ilgilenilir.
  - (3) Tahmin yöntemlerini değerlendirmek: öneri yönteminin başarısı nasıl ölçülür?
- Puan toplama (ekrandan, 00:45:00)
  - Açık (explicit): kullanıcıdan puan istenir (örneğin film bitince beş yıldızlı anket). Kesin bilgi verir ama ölçeklenmez; kullanıcıların küçük bir kısmı puan bırakır.
  - Örtük (implicit): puan kullanıcı eylemlerinden çıkarılır (örneğin satın alma yüksek puan demektir). Ölçeklenir ama düşük puanlar bu yolla anlaşılamaz.
- Bilinmeyen puanları tahmin etmenin zorlukları
  - Seyreklik: çoğu kullanıcı çoğu ürünü puanlamamıştır.
  - Soğuk başlangıç (cold start): geçmişi olmayan yeni kullanıcıya ne önerilecek; hiç puanı olmayan yeni ürün kime önerilecek?
- Üç yaklaşım: içerik tabanlı sistemler, işbirlikçi filtreleme (collaborative filtering) ve gizil faktör (latent factor) tabanlı sistemler. Üçüncüsü dersin kapsamı dışında bırakıldı.
- İçerik tabanlı öneri (content-based)
  - Fikir: kullanıcıya, daha önce yüksek puan verdiği ürünlere benzeyen ürünler önerilir.
  - İşleyiş (ekrandan, 00:50:00): kullanıcı bazı ürünleri beğenir (kırmızı daire, kırmızı üçgen) → bu ürünlerin **ürün profilleri** (item profile) çıkarılır → profillerden **kullanıcı profili** kurulur ("kırmızı, daire, üçgen") → kullanıcı profili katalogdaki ürün profilleriyle eşleştirilir → uyan ürünler önerilir.
  - Ürün profili bir özellik vektörüdür: film için oyuncular, yönetmen, tür; görüntü ve video için metaveri ve etiketler; kişi için arkadaş kümesi; metin için kelimeler. Değerler Boolean (0/1) ya da gerçel olabilir.
- Metin özellikleri ve TF-IDF (ekrandan, 00:55:00 ve 01:00:00)
  - Profil, belgedeki "önemli" kelimelerin kümesidir. "and", "or", "the" gibi yaygın kelimeler belgeyi temsil etmez.
  - $f_{ij}$: $i$ teriminin $j$ belgesindeki frekansı. $TF_{ij} = \dfrac{f_{ij}}{\max_k f_{kj}}$. Normalleştirme uzun belgelerin etkisini azaltır.
  - $n_i$: $i$ terimini içeren belge sayısı, $N$: toplam belge sayısı. $IDF_i = \log \dfrac{N}{n_i}$.
  - TF-IDF puanı: $w_{ij} = TF_{ij} \times IDF_i$. Belge profili, TF-IDF puanı en yüksek kelimeler ve puanlarıdır.
  - Belgede sık geçen ve koleksiyonda az belgede geçen kelimenin TF-IDF puanı yüksektir.
- Kullanıcı profili kurma
  - Kullanıcının puanladığı ürün profillerinin ortalaması, ağırlıklı ortalaması ya da kullanıcının ortalama puanıyla normalleştirilmiş ağırlıklı ortalaması alınabilir.
  - Örnek 1, Boolean fayda matrisi (ekrandan, 01:15:00): tek özellik oyuncudur. Kullanıcı 5 film izlemiş; 2'sinde A, 3'ünde B oynuyor. Kullanıcı profili, ürün profillerinin ortalamasıdır: A ağırlığı $2/5 = 0.4$, B ağırlığı $3/5 = 0.6$.
  - Örnek 2, yıldız puanları (ekrandan, 01:20:00): A'nın filmlerine 3 ve 5, B'nin filmlerine 1, 2 ve 4 verilmiş. Ortalama $15/5 = 3$ çıkarılır. A: $0, +2$, ağırlık $(0+2)/2 = 1$. B: $-2, -1, +1$, ağırlık $-2/3$.
- Eşleştirme: kosinüs benzerliği
  - Kullanıcı profili $x$ ile ürün profili $i$ arasında $\cos(x, i) = \dfrac{x \cdot i}{\lVert x \rVert \, \lVert i \rVert}$. Kullanıcı profiline en yakın ürünler sıralanıp önerilir.
- İçerik tabanlı yaklaşımın artı ve eksileri (eksiler ekrandan, 01:25:00)
  - Artılar: başka kullanıcıların verisine gerek yoktur; kendine özgü zevki olan kullanıcıya da öneri yapabilir; hiç puanlanmamış yeni ürünü önerebilir; önerinin nedeni açıklanabilir.
  - Eksiler: uygun özellikleri bulmak zordur (görüntü, film, müzik); aşırı uzmanlaşma (overspecialization): kullanıcının profili dışında öneri yapmaz, insanların birden çok ilgi alanı olabilir, başka kullanıcıların kalite yargılarından yararlanamaz; yeni kullanıcı için soğuk başlangıç: profil nasıl kurulacak?
- İşbirlikçi filtreleme (collaborative filtering)
  - Kullanıcı $x$'e, $x$'in beğenilerine benzer beğeniler göstermiş başka kullanıcıların beğendiği ürünler önerilir: "Seninle aynı filmleri izleyen kullanıcılar şunu da izledi."
  - Örnek fayda matrisi (ekrandan, 01:30:00): HP1, HP2, HP3, TW, SW1, SW2, SW3 filmleri; A: HP1=4, TW=5, SW1=1; B: HP1=5, HP2=5, HP3=4; C: TW=2, SW1=4, SW2=5; D: HP2=3, SW3=3. Sezgi: $\text{sim}(A,B) > \text{sim}(A,C)$ olmalı.
  - Seçenek 1, Jaccard (ekrandan, 01:35:00): $\text{sim}(A,B) = |r_A \cap r_B| / |r_A \cup r_B| = 1/5$, $\text{sim}(A,C) = 2/4$. Sezgiye ters çıkar; çünkü puan değerlerini yok sayar.
  - Seçenek 2, kosinüs (boşluklar 0): $\text{sim}(A,B) \approx 0.38$, $\text{sim}(A,C) \approx 0.32$. Sıra doğru ama fark küçük. Sorun: 0, en düşük puan gibi davranır, yani izlenmeyen filme olumsuz puan verilmiş sayılır.
  - Seçenek 3, merkezlenmiş kosinüs (ekrandan, 01:40:00): her satırdan satır ortalaması çıkarılır. A'nın ortalaması $10/3$; A: $2/3, 5/3, -7/3$; B: $1/3, 1/3, -2/3$; C: $-5/3, 1/3, 4/3$; D: $0, 0$. Boşluklar 0 kalır ve artık "ortalama puan" anlamına gelir. $\text{sim}(A,B) \approx 0.09$, $\text{sim}(A,C) \approx -0.56$. Bu yöntem Pearson korelasyonu olarak da bilinir; sert ve cömert puanlayıcıları ortalamaya çeker.
- Puan tahmini (ekrandan, 01:45:00)
  - $N$: $x$'e en benzer olan ve $i$ ürününü puanlamış $k$ kullanıcı.
  - Seçenek 1: $r_{xi} = \dfrac{1}{k} \sum_{y \in N} r_{yi}$.
  - Seçenek 2: $r_{xi} = \dfrac{\sum_{y \in N} s_{xy} r_{yi}}{\sum_{y \in N} s_{xy}}$, burada $s_{xy} = \text{sim}(x,y)$. Daha benzer kullanıcının puanına daha çok ağırlık verilir.
- Öğe-öğe (item-item) işbirlikçi filtreleme (ekrandan, 01:50:00)
  - $i$ ürününe benzeyen ürünler bulunur, $i$'nin puanı benzer ürünlere verilen puanlardan tahmin edilir. Aynı benzerlik ölçüleri ve tahmin fonksiyonları kullanılır; matrisin satır ve sütunları yer değiştirmiş gibidir.
  - $r_{xi} = \dfrac{\sum_{j \in N(i;x)} s_{ij} \, r_{xj}}{\sum_{j \in N(i;x)} s_{ij}}$; $s_{ij}$: $i$ ile $j$ ürünlerinin benzerliği, $r_{xj}$: $x$'in $j$'ye puanı, $N(i;x)$: $x$'in puanladığı ve $i$'ye benzer ürünler.
  - Örnek (ekrandan, 01:55:00): 6 film × 12 kullanıcı, $|N| = 2$. Film 1'in satır ortalaması 3.6. Film 1 ile diğer filmlerin merkezlenmiş kosinüs benzerlikleri: 1.00, −0.18, 0.41, −0.10, −0.31, 0.59. Kullanıcı 5'in puanladığı en benzer iki film 3 (0.41) ve 6'dır (0.59). Kullanıcı 5 bu filmlere 2 ve 3 vermiştir. $r_{15} = (0.41 \cdot 2 + 0.59 \cdot 3)/(0.41 + 0.59) \approx 2.6$.
  - Pratikte öğe-öğe yöntemi kullanıcı-kullanıcı yönteminden daha iyi sonuç verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Öneri algoritmalarının ortak hedefi
  - Bütün yöntemlerin amacı fayda matrisindeki boş hücreleri dolu hücrelerden tahmin etmektir. Tahminler büyükten küçüğe sıralanır ve en yüksekleri önerilir.
- Açık ve örtük geri bildirimin dengesi
  - Açık geri bildirim kesin ama ölçeklenmez. Örtük geri bildirim ölçeklenir ama düşük puanı yakalayamaz.
- TF ve IDF'nin anlamı
  - TF, kelimenin o belge için önemini; IDF, kelimenin belge koleksiyonundaki ayırt ediciliğini ölçer. Her belgede geçen kelimenin IDF'si küçüktür.
- Jaccard'ın neden yetmediği
  - Jaccard yalnız ortak puanlanan ürünlere bakar, puan değerlerine bakmaz. Örnekte zıt zevkli A ve C'yi, benzer zevkli A ve B'den daha benzer buldu.
- Boş hücreye 0 yazmanın tuzağı ve merkezleme
  - Düz kosinüste 0 en düşük puan gibi davranır. Ortalama çıkarılınca 0 "ortalama puan" anlamına gelir ve A-C zıtlığı negatif benzerlikle açıkça görünür.
- Neden öğe-öğe tercih edilir
  - İnsanlar ürünlerden çok daha karmaşıktır: heavy metal seven biri klasik müziği de sevebilir. Ürünler arası benzerlik daha iyi tanımlanır. Bu yüzden öğe-öğe işbirlikçi filtrelemenin pratikte daha başarılı olduğu gösterilmiştir ve tercih edilmesi önerilir.

## Kısa Tekrar Notları

- Uzun kuyruk: az popüler ürünlerin toplam payı büyüktür; öneri motorları bu ürünleri görünür kılar.
- Öneri türleri: editoryal, basit toplamlar, bireysel kullanıcıya göre.
- Model: $u: C \times S \to R$, $R$ tam sıralı puan kümesi.
- Fayda matrisi seyrektir; hedef boş hücreleri tahmin etmektir.
- Üç problem: puan toplama, bilinmeyeni tahmin, değerlendirme.
- Açık geri bildirim ölçeklenmez; örtük geri bildirim düşük puanı göstermez.
- Zorluklar: seyreklik ve soğuk başlangıç.
- İçerik tabanlı: ürün profili → kullanıcı profili → kosinüs ile eşleştirme.
- $TF_{ij} = f_{ij} / \max_k f_{kj}$, $IDF_i = \log(N/n_i)$, $w_{ij} = TF_{ij} \cdot IDF_i$.
- Boolean örnek: A ağırlığı 0.4, B ağırlığı 0.6. Yıldız örneği: A ağırlığı 1, B ağırlığı $-2/3$.
- İçerik tabanlının eksileri: özellik bulmak zor, aşırı uzmanlaşma, yeni kullanıcıda soğuk başlangıç.
- Jaccard: 1/5 ve 2/4 (yanlış sıra). Kosinüs: 0.38 ve 0.32. Merkezlenmiş kosinüs: 0.09 ve −0.56.
- Tahmin: basit ortalama ya da benzerlikle ağırlıklı ortalama.
- Öğe-öğe örneği: $r_{15} = (0.41 \cdot 2 + 0.59 \cdot 3)/1.00 \approx 2.6$.
- Pratikte öğe-öğe, kullanıcı-kullanıcıdan iyidir.

## Detaylı Açıklamalar

- **Neden öneri sistemi?** Fiziksel mağazanın rafı, sinemanın seans sayısı, TV kanalının 24 saati sınırlıdır; bu yüzden yalnız çok satacak ürünler sunulur. Web'de bu kısıt yoktur ve ürün sayısı neredeyse sınırsızdır. Uzun kuyruk grafiğinde dikey çizginin sağında kalan, yalnız çevrim içi bulunan ürünlerin toplam satış alanı soldaki popüler ürünlerinkinden büyüktür. Bu ürünler kendiliğinden bulunamaz; kullanıcıya önerilmeleri gerekir. Dağcılık kitapları örneği, öneri motorunun az bilinen bir ürünü çok satanlara taşıyabileceğini gösterir.

- **Biçimsel model ve fayda matrisi.** Fayda fonksiyonu her müşteri-ürün ikilisine bir puan atar. Gerçekte bu puanların çoğu bilinmez, çünkü insanlar izlediği ya da aldığı ürünü çoğunlukla puanlamaz. Bu yüzden fayda matrisi seyrektir. Örneğin bir kullanıcının henüz izlemediği iki film için boş hücreler tahmin edilirse, hangisine daha yüksek puan vereceği bulunur ve o film önerilir. Bunun için üç problem çözülmelidir: bilinen puanlar nasıl toplanacak, bilinmeyenler nasıl tahmin edilecek, yöntemin başarısı nasıl ölçülecek.

- **İçerik tabanlı öneri.** Her ürün bir özellik vektörüyle (ürün profili) temsil edilir. Metin belgelerinde özellikler kelimelerdir; belgeyi temsil edecek kelimeler TF-IDF ile seçilir. TF, kelimenin belgede kaç kez geçtiğini o belgedeki en sık terimin frekansına böler; IDF, kelimeyi içeren belge sayısı arttıkça küçülür. Belgede sık, koleksiyonda seyrek geçen kelime yüksek puan alır ve profile girer. Kullanıcı profili, kullanıcının puanladığı ürün profillerinin (ağırlıklı) ortalamasıdır. Yıldız puanlarında önce kullanıcının ortalaması çıkarılır; böylece hep yüksek veren "kolay puanlayıcı" ile hep düşük veren kullanıcı aynı ölçeğe gelir ve ortalamanın üstündeki puanlar beğeni, altındakiler beğenmeme olarak okunur. Örnek 2'de A oyuncusunun ağırlığı pozitif (1), B'ninki negatif ($-2/3$) çıkar: kullanıcı A'nın filmlerini daha çok sevmiştir. Son adımda kullanıcı profili ile katalogdaki ürün profilleri kosinüs benzerliğiyle karşılaştırılır ve en yakın ürünler önerilir.

- **İçerik tabanlının artı ve eksileri.** Yalnız kullanıcının kendi geçmişi yeterlidir; sıra dışı zevkli kullanıcıya da öneri yapılabilir; yeni gelen ve hiç puanlanmamış bir film, profili çıkarılarak hemen önerilebilir; öneri açıklanabilir (hep aksiyon izleyene aksiyon filmi önermek beklenmedik değildir). Öte yandan görüntü ya da müzik gibi ürünlerde iyi özellik vektörü kurmak zordur. Yöntem kullanıcının geçmişine aşırı odaklanır: hep aksiyon izleyen birine hiç klasik film önermez, oysa insanların birden çok ilgi alanı vardır. Geçmişi olmayan yeni kullanıcı için profil kurulamaz.

- **İşbirlikçi filtreleme ve benzerlik ölçüsü seçimi.** Kullanıcıya, ona benzeyen kullanıcıların beğendikleri önerilir. Bunun için iki puan vektörü arasında, sezgiyi yakalayan bir benzerlik ölçüsü gerekir. Örnekte A ile B'nin ortak tek filmi HP1'dir ve ikisi de sevmiştir; A ile C'nin iki ortak filmi vardır ama zevkleri zıttır. Jaccard 1/5 ve 2/4 vererek yanlış sıralar. Boşluklara 0 yazılan düz kosinüs 0.38 ve 0.32 ile doğru sıralar ama farkı çok küçüktür, çünkü 0 en düşük puan gibi işler. Satır ortalaması çıkarılınca (merkezlenmiş kosinüs, Pearson korelasyonu) boşluklar ortalama puana karşılık gelir; benzerlikler 0.09 ve −0.56 olur ve A-C zıtlığı açıkça görünür.

- **Puan tahmini.** $x$'e en benzer ve $i$'yi puanlamış $k$ kullanıcı seçilir. Basit ortalama, uzak ve yakın komşuya eşit ağırlık verir. Ağırlıklı ortalamada her komşunun puanı benzerliğiyle çarpılır ve benzerlikler toplamına bölünür; böylece $x$'e daha yakın kullanıcının puanı daha çok etkiler.

- **Öğe-öğe işbirlikçi filtreleme.** Aynı formüller satırları ürün, sütunları kullanıcı olan matrise uygulanır. Örnekte film 1'in kullanıcı 5 için puanı tahmin edilir. Film 1'in puanları (1, 3, 5, 5, 4) ortalaması 3.6'dır; merkezlenince −2.6, −0.6, 1.4, 1.4, 0.4 olur. Bütün filmler böyle merkezlenip film 1 ile kosinüs benzerlikleri hesaplanır. Kullanıcı 5'in puanladığı filmlerden en benzer iki tanesi film 3 (0.41) ve film 6'dır (0.59). Bu filmlere kullanıcı 5'in puanları 2 ve 3 olduğundan tahmin $(0.41 \cdot 2 + 0.59 \cdot 3)/(0.41+0.59) = 2.59 \approx 2.6$ olur. Bütün boş hücreler böyle doldurulunca kullanıcıya en yüksek tahminli film önerilir. İnsanların zevki geniş bir yelpazeye yayıldığından, ürünler arası benzerlik daha güvenilirdir ve öğe-öğe yöntemi pratikte daha iyi sonuç verir.

- **Ders sonrası notlar.**
  - Hoca TF'nin paydasını "o kelimenin koleksiyondaki herhangi bir belgede geçtiği en büyük sayı" diye anlattı. Ekrandaki formülde payda $\max_k f_{kj}$'dir, yani aynı $j$ belgesinde en sık geçen terimin frekansıdır (ekrandan, 01:00:00).
  - Hoca öğe-öğe örneğinde 0.41 ve 0.59 değerlerine "uzaklık" dedi. Bunlar benzerlik değerleridir; büyük olan daha yakın demektir.
  - Hoca merkezlenmiş matriste A satırını "+1, +1, −1" diye özetledi. Ekrandaki değerler $2/3, 5/3, -7/3$'tür (ekrandan, 01:40:00); işaretler aynıdır.
  - Merkezlenmiş kosinüste iki benzerlik arasındaki fark yaklaşık $0.09 - (-0.56) = 0.65$'tir; düz kosinüsteki 0.06'lık farktan çok büyüktür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
