# Ders 13 Çalışma Özeti

## Genel Konular

- Özellik seçiminin (feature selection) önemi: sınıf içi benzerliği artırıp sınıflar arası benzerliği azaltmak.
- Kategorik (categorical) ve sayısal (numerical) özellikler.
- Kategorik özellikleri sayıya çevirme: tamsayı kodlama (integer encoding) ve tek-sıcak kodlama (one-hot encoding).
- Özellik azaltmada iki yaklaşım: özellik seçimi (feature selection) ve özellik çıkarımı (feature extraction).
- Özellik seçiminde üç yaklaşım: filtre (filter), sarmalayıcı (wrapper), gömülü (embedded).
- Filtre yöntemleri: Pearson korelasyon katsayısı, ki-kare testi (chi-square test), bilgi kazancı (information gain).
- İstatistik tekrarı: ortalama (beklenen değer), varyans, kovaryans, korelasyon.
- Sarmalayıcı yöntemler: ardışık ileri seçim (Sequential Forward Selection, SFS), ardışık geri eleme (Sequential Backward Elimination, SBE), plus-L minus-R seçimi, çift yönlü arama (bidirectional search).
- Özellik çıkarımı: temel bileşen analizi (Principal Component Analysis, PCA), özdeğer (eigenvalue) ve özvektör (eigenvector), özyüzler (eigenfaces) ile yüz tanıma.
- Otokodlayıcı (autoencoder) ve derin öğrenmede özelliklerin otomatik seçilmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bütün makine öğrenmesi modellerinde ana hedef aynı: sınıf içi benzerlik çok, sınıflar arası benzerlik az olmalı.
- Özellikleri "hissiyatla" (elle) seçmek uzun yıllar yapıldı ama doğru değil. Matematiksel olarak doğrulanmalı.
- Her iki sınıfta da ortak geçen, ayırt ediciliği olmayan özellikler kullanılmamalı. Ör. yüz tanımada göz rengi.
- Kategorik özellikler arasında mesafe ölçülemez. "İstanbul ile Ankara arasındaki mesafe 3'tür" denemez.
- Tamsayı kodlamada mesafe hesabı tehlikeli: "kırmızının yeşile mesafesi 1" gibi anlamsız sonuçlar çıkar.
- One-hot kodlamanın sakıncası: özellik sayısı çok artar, matris çoğunlukla sıfır olur. Hocanın kredi kartı sahtekarlığı projesinde 40 özellik, one-hot ile yaklaşık 4000 özelliğe çıkmış.
- Kovaryans ve korelasyon doktora yeterlik sınavında istatistik kısmından en çok sorulan konulardan biri.
- Özellik azaltmanın amacı performansı artırmak. Bazen 20 özellikle başlayıp 3 özellikle çok iyi sonuç alınır.
- Sarmalayıcı yöntemler çok zahmetli, pek kullanılmaz.
- Lisansüstü öğrenci olarak yöntemleri gerçek adlarıyla bilin, araçlardaki (tool) adlarıyla konuşmayın. Ör. WEKA'da SVM'nin adı SMO'dur.
- Seçilecek özvektör sayısı deneysel belirlenir. Genelde özdeğerlerin ilk %60-70'i.
- Derin öğrenme "inek ver, hamburger al" gibi: özellik seçimini model kendisi yapar. Bu yüzden pek çok klasik yöntemden daha başarılı.

## Kısa Tekrar Notları

- **Özellik seçimi:** $D$ özellikten $M < D$ tanesi seçilir. Dönüşüm yok (ör. boy, kilo, yaş seçildi).
- **Özellik çıkarımı:** $D$ özellikten, eskileriyle doğrudan ilgisi olmayan $M < D$ yeni özellik üretilir.
- **Filtre:** özellikler istatistikle değerlendirilir, gereksizler elenir, kalan alt küme öğrenme algoritmasına verilir.
- **Sarmalayıcı:** özellikler önemine bakılmadan eklenip çıkarılır, her seferinde model başarısı ölçülür.
- **Gömülü:** özellik seçimi yöntemin kendi içinde olur (karar ağacı, rastgele orman / random forest).
- **Ortalama:** $\mu = \dfrac{1}{N}\sum_{i=1}^{N} x_i$.
- **Varyans:** $\sigma^2 = \dfrac{1}{N-1}\sum_{i=1}^{N} (x_i - \mu)^2$. Tüm veri üzerinde $N$'e, örneklem üzerinde $N-1$'e bölünür.
- **Kovaryans:** $\operatorname{cov}(X,Y) = \dfrac{1}{N-1}\sum_{i=1}^{N} (x_i - \mu_x)(y_i - \mu_y)$.
- **Pearson korelasyonu:** $r = \dfrac{\operatorname{cov}(X,Y)}{\sigma_X \sigma_Y}$, $-1 \le r \le 1$. Doğrusal ilişkiyi ölçer.
- **Ki-kare:** $\chi^2 = \sum \dfrac{(O - E)^2}{E}$. $O$ gözlenen frekans, $E$ beklenen frekans.
- **Özdeğer tanımı:** $A x = \lambda x$. Çözüm: $\det(A - \lambda I) = 0$.
- **PCA adımları:** vektöre çevir, ortalamayı çıkar, kovaryans matrisini kur, özdeğer/özvektör bul, büyük özdeğerlilerin özvektörlerini seç, veriyi bu özvektörlere izdüşür.

## Detaylı Açıklamalar

### Veri Kümesi Hazırlığı ve Özellikler

- Model kurarken önce veri toplanır. Örnekler, önemli olduğu düşünülen özellikleriyle birlikte toplanır.
- Ör. ilk yüz tanıma çalışmaları: iki göz arası mesafe, burun büyüklüğü, yüzdeki üçgenlerin mesafeleri.
- Ör. banka: müşterinin bütün işlemleri (transaction) özellik olarak alınabilir. Ama "hissiyatla" seçilen özellikler gerçekten doğru mu, kontrol edilmeli.
- Tek boyutlu iki sınıf örneği: bir özellikte A ve B sınıfları net ayrılıyorsa o özellik tercih edilir.

### Kategorik ve Sayısal Özellikler

**Kategorik özellik:**

- Değerler arasında ölçüm yapılamaz. Ör. şekil (yuvarlak, elips, kare), şehir (İstanbul, Ankara, İzmir).
- Bazı yöntemler kategorik özelliği doğrudan kullanır:
  - Karar ağacı: istatistik ve sayımla çalışır (ör. İstanbul'da oturan kişi sayısı).
  - Naive Bayes: frekansa dayalı. Doküman sınıflandırmada kelime sıklıkları kullanılmıştı.

**Sayısal özellik:**

- Matematiksel işlem ve karşılaştırma yapılabilir. Ör. yaş, kilo (45 kg ile 57 kg), ev yüzölçümü, harcama miktarı.

**Kategorik özelliği sayıya çevirme:**

- **Tamsayı kodlama:** red = 1, green = 2, blue = 3.
  - Artık matematik isteyen algoritmalarda kullanılabilir.
  - Sakıncası: mesafe ölçümü anlamsız olur. "Mavi kırmızıya 2 benziyor" gibi bir şey yok.
- **One-hot kodlama:** her değer ayrı bir özellik olur.

| Örnek | red | green | blue |
| :---: | :---: | :---: | :---: |
| kırmızı elma | 1 | 0 | 0 |
| yeşil ıspanak | 0 | 1 | 0 |

- Hamming mesafesi kullanılabilir (aynıysa 0, farklıysa 1). Normal mesafe hesapları da yapılabilir.
- Sakıncası: çok fazla özellik ve çoğu sıfır olan bir matris. Ülke, şehir, semt gibi özellikler one-hot ile binlerce özelliğe çıkar.
- Çok az özellikle çalışmak da iyi değil. Ör. sahtekarlık tespitinde yalnız harcama miktarı ve saat yetmez. Ama türetilmiş özelliklerin binlere çıkması hem hızı hem başarıyı düşürür.

### Özellik Seçimi ve Çıkarımı

- İyi özellik iki şartı sağlar:
  - Sınıflar arası farkı artırır, sınıf içi benzerliği artırır.
  - O sınıf için gerçekten ayırt edicidir. Bir sınıfta çok geçse bile ayırt edici değilse işe yaramaz.
- Ham özelliklerden anlamlı, karakteristik özellikler çıkarılır. İki yol: seçim ve çıkarım.

### Filtre Yöntemleri

```
tüm özellikler --> alt küme seçimi (istatistik) --> öğrenme algoritması --> performans
```

**İstatistik tekrarı:**

- Ortalama (beklenen değer, expected value) bir bilgi verir ama dağılım hakkında bilgi vermez. Ortalaması aynı (ör. 3) olan iki grup çok farklı dağılabilir.
- Varyans, örneklerin ortalamadan ne kadar uzaklaştığını gösterir. Standart sapmanın karesidir.
- Kovaryans, iki özelliğin birlikte değişimini gösterir. Ör. ilkokul çağındaki çocuklarda boy uzadıkça kilo da artar.

**Pearson korelasyon katsayısı:**

- İki değişken arasındaki doğrusal ilişkiyi gösterir. $-1$ ile $+1$ arasında.
  - $r > 0$: pozitif korelasyon. Ör. boy artarken kilo artar.
  - $r < 0$: negatif korelasyon. Ör. çok sigara içtikçe ömür kısalır.
  - $r \approx 0$: ilişki yok. Ör. yağmurlu günler ile televizyonda belli bir filmin oynaması.
- Kullanım:
  - İki özellik arasında korelasyon yüksekse ikisini birden kullanmaya gerek yok, biri yeter.
  - Bir özelliğin sınıf etiketiyle korelasyonu yüksekse o özellik o sınıf için kullanılabilir.

**Ki-kare testi:**

- Kategorik özellikler için kullanılır. Bir özelliğin sınıf için uygun olup olmadığına karar verir.
- Beklenen frekans: $E = \dfrac{\text{satır toplamı} \times \text{sütun toplamı}}{\text{toplam örnek}}$.

**Örnek: tenis oynama veri kümesi, Outlook özelliği (14 gün).**

| Outlook | Yes | No | Toplam |
| :---: | :---: | :---: | :---: |
| Sunny | 2 | 3 | 5 |
| Overcast | 4 | 0 | 4 |
| Rain | 3 | 2 | 5 |
| Toplam | 9 | 5 | 14 |

1. Beklenen frekanslar:
   - Sunny-Yes: $5 \cdot 9 / 14 = 3{,}21$. Sunny-No: $5 \cdot 5 / 14 = 1{,}79$.
   - Overcast-Yes: $4 \cdot 9 / 14 = 2{,}57$. Overcast-No: $1{,}43$.
   - Rain-Yes: $3{,}21$. Rain-No: $1{,}79$.
2. Her hücre için $(O-E)^2/E$ hesaplanıp toplanır:
   $\chi^2 = \dfrac{(2-3{,}21)^2}{3{,}21} + \dfrac{(3-1{,}79)^2}{1{,}79} + \dfrac{(4-2{,}57)^2}{2{,}57} + \dfrac{(0-1{,}43)^2}{1{,}43} + \dfrac{(3-3{,}21)^2}{3{,}21} + \dfrac{(2-1{,}79)^2}{1{,}79}$
3. Aynı hesap Wind özelliği için de yapılır.
4. Ki-kare değeri büyük olan özellik sınıfla daha ilişkilidir, seçilmeye daha uygundur.

**Ki-kare ile adım adım eleme:**

- Önce tüm özelliklerle başarı ölçülür.
- Ki-kare değeri en düşük özellik çıkarılıp tekrar ölçülür. Başarı artıyorsa o özellik çıkarılır.
- En düşük iki özellik çıkarılıp denenir, böyle devam edilir.

**Bilgi kazancı:** karar ağacındaki bilgi kazancı da bir filtre yöntemidir. Bilgi kazancı küçük özellikler elenebilir.

**Öğrenci sorusu: bütün özellikler iyiyse neden seçim yapıyoruz?**

- Gerçek dünyada bütün özelliklerin harika olması pek olmaz. Mutlaka bir ikisi gereksizdir.
- Boyut arttıkça özellikler arasındaki ilişkiler gözden kaçar.
- Amaç performansı artırmak. Etkisi az görünen özellikler çıkarılıp başarı tekrar ölçülür. Başarı ör. %70'ten %80'e sıçrıyorsa o özellikler kullanılmaz.

**Uygulamada:** genelde tek bir filtre yöntemine bağlı kalınmaz. Pearson, bilgi kazancı ve ki-kare ile ayrı ayrı modeller kurulup başarıları karşılaştırılır, hibrit karar verilir.

### Sarmalayıcı Yöntemler

- Özelliklerin önemine bakılmaz. Özellik eklenir ya da çıkarılır, her seferinde model başarısı ölçülür.

**Ardışık ileri seçim (SFS):**

1. Boş kümeyle başla.
2. Her özelliği tek başına dene, model başarısını ölç. En iyisini seç.
3. Seçilmiş özelliklerin yanına kalan özellikleri tek tek ekleyip dene. En çok başarı getireni ekle.
4. Başarı artmayana kadar 3. adımı tekrarla.

**Ardışık geri eleme (SBE):**

1. Tüm özelliklerle başla, başarıyı ölç.
2. Her özelliği tek tek çıkarıp başarıyı ölç. Çıkınca en az zarar veren (en kötü) özelliği at.
3. Başarı değişmeyene kadar tekrarla.

**Sakıncaları:**

- Özellik sayısı çoksa çok zaman alır.
- İlk seçilen (ya da ilk atılan) özellik sonraki seçimleri belirler. Başka bir başlangıçla daha iyi bir kombinasyon bulunabilirdi.

**Plus-L minus-R seçimi:**

- $L > R$ ise ileri seçimle başlanır: $L$ kez özellik eklenir, $R$ kez çıkarılır, tekrar edilir.
- $L < R$ ise geri elemeyle başlanır.
- Eklenen özelliklerin bir arada gerçekten iyi olup olmadığı böylece kontrol edilir.

**Çift yönlü arama:** SFS ve SBE paralel çalıştırılır. Biri en iyi özelliği eklerken diğeri kötü özelliği çıkarır.

### Gömülü Yöntemler

- Özellik seçimi öğrenme yönteminin içinde yapılır.
- Karar ağacı: en iyi özellik köke konur, aşağı inilir. Tüm örnekler sınıflanınca ağaç kesilir. Bazı özellikler hiç kullanılmamış olabilir; bu bir özellik seçimidir.
- Rastgele orman da gömülü bir yöntemdir.

### Temel Bileşen Analizi (PCA)

- Amaç: korelasyonlu özellikleri, korelasyonsuz (uncorrelated) ve daha az sayıda yeni özelliğe dönüştürmek.
- Hâlâ özellikle sinyal işlemede çok kullanılır.
- Özdeğer ve özvektöre dayanır. "Eigen" Almanca bir sözcük. Hoca "karakteristik" anlamında kullanıldığını söyledi.

**Özdeğer ve özvektör:**

- $A$ matris, $\lambda$ skaler, $x$ vektör olmak üzere $A x = \lambda x$ ise $\lambda$ özdeğer, $x$ özvektördür.
- Çözüm: $(A - \lambda I)\,x = 0$, buradan $\det(A - \lambda I) = 0$. $I$ birim matris.
- $2 \times 2$ için: $(a_{11} - \lambda)(a_{22} - \lambda) - a_{12}a_{21} = 0$.

**Örnek: $A = \begin{pmatrix} 1 & 2 \\ 2 & 1 \end{pmatrix}$**

1. $\det(A - \lambda I) = (1-\lambda)^2 - 4 = 0$.
2. $(1-\lambda)^2 = 4$, buradan $\lambda_1 = -1$, $\lambda_2 = 3$.
3. $\lambda = 3$ için $(A - 3I)x = 0$: $-2x_1 + 2x_2 = 0$, özvektör $v = (1, 1)$.
4. $\lambda = -1$ için $(A + I)x = 0$: $2x_1 + 2x_2 = 0$, özvektör $v = (1, -1)$.

**PCA'nın sezgisi:**

- Verinin en çok değiştiği yönü bulmak. Bu yön birinci temel bileşendir.
- İkinci bileşen ondan sonraki en çok değişim yönüdür. Böyle devam eder.
- En büyük özdeğere karşılık gelen özvektör en değerli (en ayırt edici) bileşendir.

**Özyüzler (eigenfaces):**

- 1990'lara kadar yüz tanıma, göz-burun-ağız yerlerinden üçgenler ve mesafeler çıkarmaya dayanıyordu.
- İnsanlar birbirini böyle tanımıyor. Yüzün bütününe bakıyor.
- Matthew Turk ve Alex Pentland yüzün tamamını kullanmayı önerdi. Hoca bu makalenin 20. yüzyılın yön değiştiren makaleleri arasında seçildiğini söyledi.
- Sorun: yanak, alın gibi herkeste ortak pikseller ayırt ediciliği öldürür.
- Çözüm: yüzlerin birbirine göre değişimine (kovaryans) bakmak, kovaryans matrisinin özvektörlerini özellik olarak kullanmak.

**Eğitim adımları:**

1. $N \times N$ boyutlu $M$ yüz görüntüsünü $N^2 \times 1$ vektörlere çevir.
2. Ortalama yüzü hesapla: $\Psi = \dfrac{1}{M}\sum_{i=1}^{M} \Gamma_i$.
3. Her görüntüden ortalamayı çıkar: $\Phi_i = \Gamma_i - \Psi$ (mean-centered).
4. Bu vektörleri yan yana koyup $A = [\Phi_1 \ \Phi_2 \ \cdots \ \Phi_M]$ matrisini kur.
5. Kovaryans matrisi: $C = A A^T$.
6. $C$'nin özdeğer ve özvektörlerini bul. Sıfırdan farklı özdeğerleri büyükten küçüğe sırala.
7. En büyük özdeğerlere karşılık gelen özvektörleri seç (ör. ilk %60-70).
8. Her görüntüyü seçilen özvektörlerle özuzaya (eigenspace) geçir: $\Omega_i = V^T \Phi_i$.

**Test adımları:**

1. Bilinmeyen görüntü $Y$'yi vektöre çevir.
2. Ortalama yüzü çıkar.
3. Seçilen özvektörlerle özuzaya geçir.
4. Elde edilen özellikleri herhangi bir öğrenme modeline ver (k-NN, SVM vb.).

**Derste gösterilen sayısal örnek:**

- 4 sınıf ($X_1, X_2, X_3, X_4$), her biri $3 \times 3$ gri seviye görüntü (0 siyah, 255 beyaz). $Y$ bilinmeyen örnek.
- Her görüntü $9 \times 1$ vektöre çevrildi. Ortalama çıkarıldı (ör. $225 - 171{,}5 = 53{,}5$).
- $A$ matrisi $9 \times 4$, kovaryans matrisi $9 \times 9$ oldu.
- Sıfırdan farklı 3 özdeğer çıktı. Bunlara karşılık gelen özvektörlerle $9 \times 3$ matris kuruldu.
- Her görüntü $3 \times 9$ ile $9 \times 1$ çarpılarak $3 \times 1$ boyuta indi. 9 özellik 3 özelliğe indi.
- $Y$ aynı adımlardan geçirildi, Öklid mesafesiyle en yakın örnek $X_2$ çıktı. Görüntüye bakınca da $X_2$'ye benziyor.

**Kaç özvektör seçilmeli?**

- Bir öğrenci sordu: her vektör için iki özdeğer var, büyüğünü mü seçiyoruz?
- Cevap: kovaryans matrisinin kaç kökü varsa o kadar özdeğer çıkar. Her özdeğerin bir özvektörü vardır.
- Özdeğer küçüldükçe özvektörün değeri de düşer. Bütün pozitif özdeğerleri seçmek doğru değil.
- Derste gösterilen özyüzlerde ilk özvektörler insan yüzüne benziyor. Dördüncüde sakallı kişilerin etkisi görünüyor. Sonrakiler giderek bozuluyor; karakteristik olmayan bilgiyi taşıyor.
- Bu yüzden ör. 5, sonra 10 özvektörle başarı ölçülüp karar verilir.

**PCA'nın kullanım alanları:**

- Yüz tanımayla başladı, sonra ses sinyallerinde kullanıldı.
- Banka verisi gibi düz verilerde de çok kullanılıyor.
- Ek avantaj: veri dönüştürüldüğü için orijinal bilgi kaybolur. Paylaşılan kamuya açık banka verilerinde kişiyi geri bulmayı (reverse engineering) zorlaştırır.

### Otokodlayıcı ve Derin Öğrenme

- Hocaya göre PCA'dan daha başarılı bir özellik dönüştürme yöntemi otokodlayıcıdır.
- Klasik makine öğrenmesinde akış:

```
örnekler --> ön işleme --> özellik seçimi / çıkarımı --> model seçimi (k-NN, karar ağacı...)
```

- Klasik akışta başarı, özellikleri nasıl seçtiğinize göre değişir (elle, filtre, sarmalayıcı, çıkarım).
- Derin öğrenme "o işi bana bırak" der. Evrişimli sinir ağında (Convolutional Neural Network, CNN) filtreler en uygun özellikleri sistemin içinde seçer.
- Otokodlayıcı eğitmensiz bir yöntemdir. Özellik çıkarma aşamasında kesilirse çok iyi özellikler verir.
- Derin öğrenmeyle çıkarılan özellikler kesilip klasik yöntemlerle (ör. SVM) de kullanılabiliyor.

### Ders sonrası notlar

- **Ki-kare sayıları:** hoca Outlook için 3,129, Wind için 3,62 değerini verdi ve "Wind seçilmeli" dedi. Standart tenis veri kümesiyle hesaplanınca Outlook için $\chi^2 \approx 3{,}55$ çıkıyor. Wind (Weak: 6 Yes/2 No, Strong: 3 Yes/3 No) için $\chi^2 \approx 0{,}93$. Yani bu veride Outlook sınıfla daha ilişkili. Ayrıca serbestlik dereceleri farklı (Outlook 2, Wind 1). Bu yüzden ham ki-kare değerleri yerine p-değerleri karşılaştırılmalı. Altyazıdaki "1000 seçilmeli" ifadesi "Wind seçilmeli" olarak anlaşıldı.
- **Pearson ve kategorik veri:** hoca bir yerde "kategorik özelliklerimiz varsa Pearson kullanılıyor" dedi. Doğrusu tersi: Pearson sayısal özellikler arasındaki doğrusal ilişkiyi ölçer. Kategorik özellikler için ki-kare kullanılır.
- **Negatif özdeğer sorusu:** bir öğrenci neden yalnız pozitif özdeğerlerin seçildiğini sordu. Hoca negatif özdeğerleri hiç denemediğini söyledi. Kovaryans matrisi pozitif yarı tanımlıdır (positive semi-definite). Özdeğerleri hiçbir zaman negatif olmaz, yalnız sıfır ya da pozitif çıkar.
- **Sıfırdan farklı özdeğer sayısı:** örnekte 4 görüntüden 3 sıfırdan farklı özdeğer çıkması tesadüf değil. Ortalama çıkarılınca $M$ örnekten kurulan kovaryans matrisinin rankı en fazla $M - 1$ olur.
- **Kovaryans katsayısı:** $C = A A^T$ ifadesinde $1/(M-1)$ çarpanı atlandı. Bu çarpan özvektörleri değiştirmez, yalnız özdeğerleri ölçekler.
- **Özdeğer örneğindeki özvektörler:** altyazıda iki özvektör de "1, 1" gibi okunuyor. Doğrusu $\lambda = 3$ için $(1, 1)$, $\lambda = -1$ için $(1, -1)$.
- **t-SNE:** bir öğrenci PCA'dan iyi yöntem olarak t-SNE'yi önerdi, açılımını hatırlayamadı. Açılımı t-distributed Stochastic Neighbor Embedding (van der Maaten ve Hinton, 2008). Doğrusal olmayan bir yöntemdir, daha çok 2-3 boyutta görselleştirme için kullanılır.
- **WEKA'daki SMO:** Sequential Minimal Optimization. SVM'yi eğitmek için kullanılan bir algoritmadır.
- **Özyüz makalesi:** Turk ve Pentland, "Eigenfaces for Recognition", 1991.
- **Embedded yöntemler:** hoca karar ağacı ve rastgele ormanı örnek verdi. L1 düzenlileştirmeli (Lasso) doğrusal modeller de yaygın bir gömülü yöntemdir.
- **Altyazı yanlış okumaları:** "Aygın" = eigen, "key square" = chi-square, "Füçür" = feature, "Nayibayez" = Naive Bayes, "papyrus'in korelasyon" = Pearson korelasyonu.
- **Duyurular:**
  - Hoca sınav sonuçlarını yoğunluk nedeniyle henüz ilan edemediğini söyledi. Sistemde notların yanlış göründüğünü, düzeltilmesini beklediğini belirtti.
  - O gün bir ödev vereceğini ve duyuracağını söyledi.
  - Bir sonraki hafta işbirlikçi filtreleme (collaborative filtering) ve derin öğrenmeye kısa bir giriş yapılacak.
- **Tatil:** bu derste geçmiyor.

Gemini Notebook gibi bir araca altyazı dosyasını yükleyerek bu ders hakkında daha ayrıntılı soru-cevap yapabilirsiniz.
