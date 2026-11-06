# Ders 3 Çalışma Özeti

## Genel Konular

- Karar ağaçlarında aşırı öğrenme (overfitting) ve çözümleri (geçen dersin devamı):
  - Azaltılmış hata budaması (reduced error pruning), örnekle.
  - Erken durdurma (early stopping).
  - Kural sonrası budama (rule post-pruning).
- Karar ağaçlarının özeti: avantajlar ve dezavantajlar.
- Ayırt edici (discriminative) ve üretici (generative) sınıflandırıcılar.
- Olasılık hatırlatması: örnek uzayı, bağımlı / bağımsız olaylar, birleşik olasılık (joint probability), koşullu olasılık (conditional probability).
- Bayes teoremi ve en büyük sonsal olasılık (maximum a posteriori, MAP) kestirimi.
- Örnekler: kiraz-erik yaprağı, COVID testi, Monty Hall problemi.
- Naive Bayes sınıflandırıcısı (Naive Bayes classifier): bağımsızlık varsayımı, eğitim ve test.
- PlayTennis verisiyle Naive Bayes örneği.
- Naive Bayes ile belge sınıflandırma (spam filtresi), Laplace düzeltmesi (Laplace estimator).

## Hocanın Özellikle Vurguladığı Kısımlar

- **Overfitting'in belirtisi:** Eğitim başarısı yüksek (ör. %90), test başarısı belirgin düşük (ör. %60-70).
- **Budama doğrulama (validation) verisiyle yapılır, eğitim verisiyle değil.** Eğitim bittikten sonra eğitim verisine hiç dönülmez.
- **Doğrulamanın amacı:** Eğitimle elde edilen modelin ince ayarını yapmak (budama, parametre seçimi). Model hangisi olursa olsun (karar ağacı, k-NN...) aynı mantık geçerlidir.
- **Test verisi** modelin eğitiminde ve düzeltilmesinde hiç kullanılmamış bağımsız veridir. Modelin son başarısı onunla verilir.
- **Budamada çoğunluk kuralı:** Budanan düğüm, o noktadaki örneklerin çoğunluk sınıfıyla etiketlenen bir yaprak olur.
- Hoca azaltılmış hata budamasını tercih ediyor: İşlem açısından daha kolay. Erken durdurma çok bilgi tutmayı gerektirdiği için pratik değil.
- Ders içinde en başarılı ve en çok kullanılan modeller seçilerek anlatılıyor.
- **COVID örneğinin dersi:** Test pozitif çıksa bile hastalığın toplumdaki oranı çok düşükse, kişinin hasta olmama olasılığı daha yüksek çıkabilir. Hatanın büyük kısmı sayıca çok olan sağlıklı kişilerden gelir.
- **Naive Bayes** basit ama belge sınıflandırmada (spam, duygu analizi, haber kategorisi, yazar cinsiyeti) çok başarılı. Hocanın BKM için yaptığı kredi kartı sahtekarlığı çalışmasında da (yaklaşık 30 bankanın verisi) klasik yöntemler arasında Naive Bayes yüksek başarı vermiş.
- Naive Bayes'in bağımsızlık varsayımı her zaman doğru değildir (ör. "Donald" ve "Trump" kelimelerini ayrı ayrı değerlendirmek ile birlikte değerlendirmek farklı etki yapar).
- Belge sınıflandırmada önce durak kelimeler (stop words) elenmeli.
- Sınıflardaki örnek sayıları mümkün olduğunca eşit tutulmalı.

## Kısa Tekrar Notları

- **Azaltılmış hata budaması:** Ağacı tam kur. Yapraklardan yukarı doğru buda. Doğrulama başarısı artıyorsa budamayı koru, düşüyorsa geri al.
- **Erken durdurma:** Ağacı büyütürken her adımda doğrulama başarısını kaydet. Ağaç bitince başarının düşmeye başladığı noktadaki ağaca dön.
- **Kural sonrası budama:** Ağacı kurallara çevir. Her kuralı bağımsız olarak doğrulama verisiyle değerlendir. Başarıyı düşüren kuralları / koşulları at.
- **Ayırt edici (discriminative) sınıflandırıcı:** Özelliklerden doğrudan sınıfa gider, $P(y \mid x)$ ya da karar sınırı öğrenir. Örnek: k-NN, yapay sinir ağları, doğrusal regresyon, karar ağaçları.
- **Üretici (generative) sınıflandırıcı:** Sınıftan geriye gider; her sınıf için $P(x \mid y)$ ve $P(y)$ kullanarak örneğin hangi sınıfa daha çok benzediğini bulur. Örnek: Bayes, Naive Bayes, Saklı Markov Modeli (Hidden Markov Model).
- **Koşullu olasılık:** $P(A \mid B) = \dfrac{P(A \cap B)}{P(B)}$, $P(B) > 0$.
- **Bağımsızlık:** $A$ ve $B$ bağımsızsa $P(A \mid B) = P(A)$.
- **Bayes teoremi:** $P(A \mid B) = \dfrac{P(B \mid A)\,P(A)}{P(B)}$.
- **MAP kestirimi:** $\hat{y} = \arg\max_{y} P(x \mid y)\,P(y)$. Payda $P(x)$ tüm sınıflarda aynı olduğu için atılır.
- **Naive Bayes:** $\hat{y} = \arg\max_{y_j} P(y_j)\prod_{i} P(a_i \mid y_j)$.
- **Laplace düzeltmesi:** $P(w_k \mid y_j) = \dfrac{n_{kj} + 1}{n_j + |V|}$.

## Detaylı Açıklamalar

### Karar Ağaçlarında Overfitting (Tekrar)

- Öğrenme, öğrenilmesi istenen bilginin karakteristiklerini anlamaktır. Karakteristikler anlaşılırsa bilinmeyen örnek doğru tahmin edilir.
- Gereğinden fazla öğrenmek ezberlemeye gider. Fazla detay öğrenilince karakteristik kaybolur; A sınıfının örneği B sınıfı sanılabilir.
- **Örnek:** Kız ve erkek öğrencileri boy ve kiloya göre ayıran bir sistem.
  - Kız öğrencilerde boy genelde 1,55-1,75 m, kilo 45-100 kg arasında.
  - 1,85 m 80 kg ya da 1,90 m 120 kg bir kız öğrenci erkeklerin bilgilerine daha yakın.
  - Model bunu da doğru bilsin diye zorlanırsa karakteristikten uzaklaşır.
- **Nedenler:**
  - Gürültülü (noisy) veri. Hoca burada "gürültü"nün sinyal işlemedeki parazit değil, sınıfın diğer örneklerine benzemeyen veri olduğunu vurguluyor.
  - Küçük eğitim kümesi. Az örnekle karakteristikleri yakalamak zorlaşır.
- **Grafik (düğüm sayısı - doğruluk):** Eğitim doğruluğu düğüm sayısı arttıkça sürekli artar. Test doğruluğu bir noktaya kadar artar, sonra sabit kalır, sonra düşer. Düşmenin başladığı yer overfitting'in başladığı yerdir.
- Karar ağacı, bütün yapraklarda yalnız tek sınıf kalana kadar büyüdüğü için overfitting'e yatkındır.

### Veri Bölme (Basit Hali)

- Örnek: 100 örnek.
  - %70 eğitim + doğrulama, %30 test.
  - %70'lik kısmın %60'ı eğitim, %40'ı doğrulama.
- Çapraz doğrulama (cross-validation) gibi başka yöntemler ileride anlatılacak.

### Azaltılmış Hata Budaması (Reduced Error Pruning): Örnek

- Başlangıç: PlayTennis ağacı eğitim verisiyle kurulmuş. Doğrulama başarısı **%75**.

```
Outlook
├─ Sunny    -> Humidity
│              ├─ High   -> No
│              └─ Normal -> Yes
├─ Overcast -> Yes
└─ Rain     -> Wind
               ├─ Weak   -> Yes
               └─ Strong -> No
```

- **Overfitting'e yol açan örnek:** (Sunny, Hot, Normal, Strong) → No. Ağaçta Sunny + Normal → Yes. Bu örnek eklenirse Normal dalı saf olmaz ve ağaç aşağı doğru uzar.

**Adım 1: Sunny dalını buda**

- Humidity düğümü kaldırılır. Sunny dalı bir yaprak olur.
- Yaprağın sınıfı çoğunluğa göre belirlenir. Hocanın örneğinde Sunny dalında çoğunluk "oynamadı" (ör. 3 oynamadı, 1 oynadı). Yaprak: **No (Don't Play)**.
- Doğrulama başarısı: **%80**. Arttı; budama korunur.

**Adım 2: Overcast dalı**

- Zaten tek yaprak (Yes). Budanacak alt ağaç yok.

**Adım 3: Rain dalını buda**

- Wind düğümü kaldırılır. Çoğunluk "oynadı" (hocanın örneğinde Weak iken 6 gün oynamış, Strong iken 2 gün oynamamış). Yaprak: **Yes**.
- Doğrulama başarısı orijinal ağaca göre ölçülür: **%70**. Önceki %75'ten düşük. Bu budama yapılmaz.
- İki dal farklı kuralları temsil ettiği için birbirini etkilemez. Sol dal budanmış haldeyken sağ dalı budamayı denemek de fayda vermez.

**Sonuç**

- Yeni model: Sunny dalı budanmış ağaç, doğrulama başarısı %80.
- Son olarak hiç kullanılmamış test verisiyle başarı ölçülür ve modelin doğruluğu olarak raporlanır.
- Özet: **Eğitim verisiyle eğit, doğrulama verisiyle buda, test verisiyle bağımsız ölç.**

- Bir öğrencinin sorusu: Budama kararı eğitim verisine mi, doğrulama verisine mi bakılarak verilir? Cevap: Doğrulama verisine. Eğitim bittikten sonra eğitim örnekleriyle işimiz yok; onlarla ölçmek durumu karıştırır.
- Slayttaki grafikte de budamaya devam ettikçe başarı artıyor, bir noktadan sonra (yaklaşık 20 düğüm) değişmiyor. Daha fazla budanırsa başarı yine düşebilir. Budama orada kesilmeli.

### Erken Durdurma (Early Stopping)

- Ağaç büyütülürken her yeni düğümle birlikte başarı ölçülür ve kaydedilir.
- Ağaç sonuna kadar kurulur. Sonra doğrulama başarısının düşmeye başladığı noktadaki ağaca geri dönülür.
- Slayttaki grafik: siyah eğitim, kırmızı test, yeşil doğrulama verisi. Eğitim başarısı sürekli yükselirken doğrulama ve test başarısı belli noktadan sonra düşüyor.
- Fark:
  - Azaltılmış hata budamasında ağaç kurulup geriye doğru budanır.
  - Erken durdurmada ağaç kurulurken başarı hesaplanır, sonra en uygun noktada kesilir.
- Hocaya göre çok bilgi tutmak gerektiği için pek pratik değil.

### Kural Sonrası Budama (Rule Post-Pruning)

1. Veri eğitim, doğrulama, test olarak üçe ayrılır.
2. Ağaç kurulur ve kurallara çevrilir. Ör. "Outlook = Sunny ve Humidity = High ise Don't Play".
3. Her kural (ve kuralın koşulları) bağımsız olarak doğrulama verisiyle değerlendirilir.
   - Ör. "Humidity = High ise Don't Play" koşulu doğrulama başarısını %75'e çıkarıyorsa korunur.
   - Başarıyı düşüren kurallar elenir.
4. Kurallar başarıya göre büyükten küçüğe sıralanır. Belli bir başarı seviyesinin altındakiler atılabilir.

- Hoca: Çok kullanılan bir yöntem ama ben işlem kolaylığı nedeniyle azaltılmış hata budamasını tercih ediyorum.

### Karar Ağaçlarının Özeti

**Avantajlar**

- Doğrusal ayrılamayan sınıflar için karar sınırlarını, matematiksel bağıntı kurmadan, kontrollerle (eğer-ise) etkili biçimde oluşturur. Başarısının önemli bir nedeni budur.
- Kategorik özelliklerle doğrudan çalışır. Kategorik özellikleri sayısala çevirme ve sorunları ilerideki haftalarda anlatılacak.
- Sürekli özellikleri eşik değerleriyle (ör. sıcaklık > 20 ise oyna) kullanabilir.
- Kurallara çevrilebilir.
- Budama ile gürültüden (parazitten) kurtulabilir.
- Hızlı: Ağacın bir dalına girilince diğer dallar hiç değerlendirilmeden elenir. Büyük ağaçlarda önemli avantaj.

**Dezavantajlar**

- Çok büyük ağaçları kurala çevirmek ve anlamak zor.
- Artımlı (incremental) değil: Yeni örnekler gelince ağaç yeniden kurulmalı.
- Özellik sayısı sabit ve baştan bilinmeli (ör. 8 özellik varsa 8 özellikle çalışır). Hoca bunun çok önemli bir dezavantaj olmadığını düşünüyor.

### Ayırt Edici ve Üretici Sınıflandırıcılar

- Örnek: İki sınıf var, filler ve ayılar. Boyu, ağırlığı, rengi bilinen bir hayvan gördünüz. Fil mi, ayı mı?

**Ayırt edici (discriminative) sınıflandırıcılar**

- Bilinmeyen örneğin özelliklerinden doğrudan sınıfa gider: "Bu fildir."
- Örnekler: k-en yakın komşu, yapay sinir ağları, doğrusal regresyon, karar ağaçları.
- Bilinen yöntemlerin çoğu böyle çalışır.

**Üretici (generative) sınıflandırıcılar**

- Sınıftan yola çıkıp geriye gider:
  - "Hayvan filse, bu boy, ağırlık ve rengin görülme olasılığı nedir?"
  - "Hayvan ayıysa, bu özelliklerin görülme olasılığı nedir?"
- Örnek hangi sınıfa daha çok benziyorsa o sınıfa atanır.
- Verilen $y$ için $x$ özelliklerinin olasılığı, yani $P(x \mid y)$ kullanılır.
- Örnekler: Bayes, Naive Bayes, Saklı Markov Modeli.

### Olasılık Hatırlatması

- **Örnek uzayı (sample space) $S$:** Problemde alınabilecek bütün değerler. Zar için $S = \{1,2,3,4,5,6\}$. (Hoca bir an "özellik uzayı" deyip "örnek uzayı" diye düzeltiyor.)
- **Rastgele değişken $A$:** Örnek uzayından herhangi bir değer.
- $P(A)$: Mümkün bütün olaylar içinde $A$'nın olma olasılığı. Zarın 4 gelme olasılığı $1/6$.
- Her zaman $0 \le P(A) \le 1$. Örnek uzayındaki olasılıkların toplamı 1'dir.
- **Bağımlı olaylar:** Öğrencinin lisansüstü giriş sınavını kazanması ve yüksek mühendis olması.
- **Bağımsız olaylar:** Hoca yazı-tura örneğini veriyor (bkz. Ders sonrası notlar).
- **Birleşik olasılık (joint probability):** İki olayın birlikte doğru olma olasılığı, $P(A \cap B)$. Ör. aynı anda baş ağrısı ve burun akıntısı olması (grip belirtileri). Kesişim boş küme de olabilir.

$$P(A \cap B) = P(A \mid B)\,P(B)$$

- **Koşullu olasılık (conditional probability):** $B$ gerçekleşmişken $A$'nın olma olasılığı.

$$P(A \mid B) = \frac{P(A \cap B)}{P(B)}, \quad P(B) > 0$$

- $P(B)$'ye bölmek normalizasyon içindir.
- Örnek:
  - Bir kişide baş ağrısı olma olasılığı $P(H) = 1/10$.
  - Nezle olma olasılığı $P(F) = 1/40$.
  - Nezleyken baş ağrısı olma olasılığı $P(H \mid F) = 1/2$. Bu bir koşullu olasılıktır.
- $A$ ve $B$ bağımsızsa: $P(A \mid B) = P(A)$.

### Bayes Teoremi

**Sezgi: Kiraz ve erik yaprağı**

- Bahçede 200 kiraz ağacı, 120 erik ağacı var. Yerde bir yaprak buldunuz ama iki ağacın yaprağını da tanımıyorsunuz. Hangi ağaca ait?
- Yalnız ağaç sayılarına göre:

$$P(kiraz) = \frac{200}{320}, \qquad P(erik) = \frac{120}{320}$$

- $P(kiraz) > P(erik)$ olduğu için "kiraz" demek şansı artırır.
- Ama yaprağın gözlemlenen özellikleri de var (ör. kırmızı, ince). Hem ağaç sayılarından gelen önceki (prior) bilgi hem gözlemlenen özellikler kullanılırsa daha doğru sınıflandırma yapılır. Bayes teoremi buna dayanır.

**Teorem**

$$P(A \mid B) = \frac{P(B \mid A)\,P(A)}{P(B)}$$

- Sınıflandırma diliyle: $A$ sınıf, $B$ gözlemlenen veri (özellikler).

$$P(sınıf \mid veri) = \frac{P(veri \mid sınıf)\,P(sınıf)}{P(veri)}$$

- $P(sınıf)$: önceki (prior) olasılık. Ör. $P(kiraz)$, $P(erik)$. Önceden bilinir.
- $P(veri \mid sınıf)$: olabilirlik (likelihood). Ör. kiraz ağacının yaprağının kırmızı ve ince olma olasılığı. Önceden toplanmış bilgiden bilinir.
- $P(sınıf \mid veri)$: sonsal (posterior) olasılık. Bulunmak istenen.
- Her sınıf için sonsal olasılık hesaplanır. En büyük olan sınıf seçilir.

**En büyük sonsal olasılık (MAP) kestirimi**

- $P(veri)$ bütün sınıflar için aynı paydadır; hangi sınıfın büyük çıkacağını değiştirmez. Atılabilir.
- $y_1, y_2, \dots, y_n$ sınıflar, $x$ gözlemlenen özellikler olmak üzere:

$$\hat{y}_{MAP} = \arg\max_{y_j} P(y_j \mid x) = \arg\max_{y_j} P(x \mid y_j)\,P(y_j)$$

### Örnek 1: COVID Testi

- **Verilenler:**
  - Toplumda COVID olma olasılığı: $P(C) = 0.008$ (binde 8). Dolayısıyla $P(\neg C) = 0.992$.
  - COVID olanların testinin pozitif çıkma olasılığı: $P(+ \mid C) = 0.98$. Dolayısıyla $P(- \mid C) = 0.02$.
  - COVID olmayanların testinin negatif çıkma olasılığı: $P(- \mid \neg C) = 0.97$. Dolayısıyla $P(+ \mid \neg C) = 0.03$.
- **Soru:** Bir kişinin testi pozitif çıktı. COVID mi, değil mi?
- **Çözüm (MAP):** Payda $P(+)$ iki tarafta ortak; atılır.

$$P(+ \mid C)\,P(C) = 0.98 \times 0.008 = 0.0078$$

$$P(+ \mid \neg C)\,P(\neg C) = 0.03 \times 0.992 = 0.0298$$

- $0.0298 > 0.0078$. **Sonuç: Test pozitif olmasına rağmen "COVID değil" denir.**
- Normalize edilirse: $P(C \mid +) = \dfrac{0.0078}{0.0078 + 0.0298} \approx 0.21$. Pozitif çıkan birinin gerçekten hasta olma olasılığı yaklaşık %21.
- **Neden böyle?** (Bir öğrencinin sorusu üzerine.) Toplumda COVID olmayanlar çok fazla (1000 kişiden 992). Bunların %3'üne yanlışlıkla pozitif deniyor. Bu yanlış pozitifler sayıca gerçek pozitiflerden fazla oluyor.
- Hoca, pratikte testin tek başına yetmediğini, şüpheli durumlarda akciğer görüntülemesi (hoca "MR" diyor; bkz. notlar) ya da art arda testlerle doğrulama yapıldığını söylüyor. %98 değeri, hasta olduğu bilinen kişilerde testin pozitif çıkma oranıdır.

### Örnek 2: Monty Hall Problemi

- Üç kapı var: Birinin arkasında araba, ikisinin arkasında keçi.
- Yarışmacı A kapısını seçiyor. Sunucu (Monty), arabanın olmadığı bir kapıyı açıyor. Yarışmacıya "A'da mı kalırsın, diğer kapıya mı geçersin?" diye soruyor.
- Hoca önce "Monty C'yi açıyor" diye soruyu soruyor, sonra karıştırmamak için çözümü "Monty B'yi açıyor" durumu üzerinden yapıyor.
- **Önceki olasılıklar:** $P(A) = P(B) = P(C) = \dfrac{1}{3}$ (araba her kapının arkasında eşit olasılıkla).
- **Olabilirlikler** (yarışmacı A'yı seçmiş, Monty B'yi açıyor):
  - Araba A'daysa: Monty B ya da C'yi açabilir. $P(B\text{ açılır} \mid A) = \dfrac{1}{2}$.
  - Araba B'deyse: Monty B'yi açamaz. $P(B\text{ açılır} \mid B) = 0$.
  - Araba C'deyse: Monty A'yı (seçilmiş) ve C'yi (araba) açamaz; tek seçenek B. $P(B\text{ açılır} \mid C) = 1$.
- **MAP karşılaştırması:**

$$P(B\text{ açılır} \mid A)\,P(A) = \frac{1}{2}\cdot\frac{1}{3} = \frac{1}{6}$$

$$P(B\text{ açılır} \mid C)\,P(C) = 1 \cdot \frac{1}{3} = \frac{1}{3}$$

- $\dfrac{1}{3} > \dfrac{1}{6}$. **Sonuç: Kapı değiştirilmeli (C'ye geçilmeli).**
- Normalize edilirse: $P(A \mid B\text{ açıldı}) = \dfrac{1}{3}$, $P(C \mid B\text{ açıldı}) = \dfrac{2}{3}$.
- Sınıflar: "araba A'da", "araba B'de", "araba C'de". Dışarıdan gelen veri: "B kapısı açıldı".

### Naive Bayes Sınıflandırıcısı

**Bağımsızlık varsayımı**

- Özellik sayısı çok olunca özelliklerin birbirine göre koşullu olasılıklarını bulmak zordur. Ör. soğuk algınlığında ateş varken burun akması, kas ağrısı varken burun akması olasılıkları.
- Naive Bayes, sınıf verildiğinde özelliklerin **birbirinden bağımsız** olduğunu varsayar.
- $C$ sınıfında $x_1, \dots, x_5$ özellikleri için (ör. sınıf kiraz ağacıyken yaprağın kırmızı, ince... olması):

$$P(x_1, x_2, \dots, x_5 \mid C) = P(x_1 \mid C)\,P(x_2 \mid C) \cdots P(x_5 \mid C)$$

- "Naive" (saf, basit) adı bu basitleştirici varsayımdan gelir.
- Bu varsayım her zaman doğru değildir ama yöntem pratikte çok başarılıdır.

**Sınıflandırma kuralı**

- $v_j$: $j$. sınıf, $a_1, \dots, a_n$: özellikler (attributes).

$$v_{NB} = \arg\max_{v_j} P(v_j)\prod_{i=1}^{n} P(a_i \mid v_j)$$

**Kullanım alanları**

- Spam filtresi (spam / spam değil). Naive Bayes'in parlamasına neden olan uygulama.
- Yazının yazarının kadın mı erkek mi olduğunu tahmin etme.
- Film yorumunun olumlu mu olumsuz mu olduğu (duygu analizi).
- Alaycı yorum tespiti, ürün yorumunda hakaret olup olmadığı.
- Haber belgesinin konusu (ekonomi, sanat, politika, spor).
- Hoca, belge sınıflandırmada Naive Bayes'in klasik karar ağacı, k-NN, SVM ve klasik (derin olmayan) yapay sinir ağlarından çoğu zaman daha başarılı olduğunu söylüyor.

**Eğitim**

1. Her sınıfın önceki olasılığı $P(v_j)$ hesaplanır.
   - Sınıflarda eşit örnek varsa (2 sınıf) her biri $1/2$.
   - Ör. hasta örneği 1, sağlam örneği 4 ise $P(hasta) = 1/5$, $P(sağlam) = 4/5$.
2. Her sınıf için her özelliğin her değerinin olasılığı $P(a_i \mid v_j)$ hesaplanır.

**Test**

- Bilinmeyen örneğin özellik değerleri için her sınıfta olasılıklar çarpılır, sınıfın önceki olasılığıyla çarpılır. En büyük olan sınıf seçilir.

### Örnek 3: Naive Bayes ile PlayTennis

- Veri: Geçen dersteki 14 günlük PlayTennis tablosu (9 Yes, 5 No).
- **Sınıf olasılıkları:** $P(Yes) = 9/14$, $P(No) = 5/14$.
- **Koşullu olasılık tabloları** (eğitim):

| Özellik = Değer | $P(\cdot \mid Yes)$ | $P(\cdot \mid No)$ |
| :--- | :---: | :---: |
| Outlook = Sunny | 2/9 | 3/5 |
| Outlook = Overcast | 4/9 | 0/5 |
| Outlook = Rain | 3/9 | 2/5 |
| Temperature = Hot | 2/9 | 2/5 |
| Temperature = Mild | 4/9 | 2/5 |
| Temperature = Cool | 3/9 | 1/5 |
| Humidity = High | 3/9 | 4/5 |
| Humidity = Normal | 6/9 | 1/5 |
| Wind = Weak | 6/9 | 2/5 |
| Wind = Strong | 3/9 | 3/5 |

- Not: Hoca altyazıda Sunny ve Temperature satırlarını sözlü olarak veriyor; tablonun kalanı slayttaki standart değerlerdir.
- **Test örneği:** $x$ = (Outlook = Sunny, Temperature = Cool, Humidity = High, Wind = Strong).

$$P(Yes)\,P(Sunny \mid Yes)\,P(Cool \mid Yes)\,P(High \mid Yes)\,P(Strong \mid Yes) = \frac{9}{14}\cdot\frac{2}{9}\cdot\frac{3}{9}\cdot\frac{3}{9}\cdot\frac{3}{9} \approx 0.0053$$

$$P(No)\,P(Sunny \mid No)\,P(Cool \mid No)\,P(High \mid No)\,P(Strong \mid No) = \frac{5}{14}\cdot\frac{3}{5}\cdot\frac{1}{5}\cdot\frac{4}{5}\cdot\frac{3}{5} \approx 0.0206$$

- $0.0206 > 0.0053$. **Sonuç: PlayTennis = No (tenis oynamaz).**

### Naive Bayes ile Belge Sınıflandırma

**Eğitim adımları**

1. Her sınıf için örnek belgeler toplanır. Ör. 100 spam, 100 spam olmayan e-posta.
2. Bir sınıfın bütün belgeleri uç uca eklenerek o sınıfın metni oluşturulur.
3. Özellikler kelimelerdir.
4. Durak kelimeler (stop words: "a", "in", "the" gibi; Türkçede "de", "da", "ki" gibi) elenir. Bunlar her iki sınıfta da benzer sıklıkta geçtiği için sınıflandırma başarısını düşürür.
5. Kalan kelimelerden, bütün sınıflarda geçen kelimeleri içeren bir **sözlük (vocabulary) $V$** oluşturulur.
   - Gerekirse kelime olmayan simgeler (ünlem, soru işareti, sayılar) de sözlüğe alınabilir.
6. Sınıf olasılıkları $P(v_j)$ hesaplanır.
7. Sözlükteki her kelime için her sınıfta bulunma olasılığı hesaplanır:

$$P(w_k \mid v_j) = \frac{n_{kj}}{n_j}$$

- $n_{kj}$: $w_k$ kelimesinin $j$. sınıfta geçme sayısı.
- $n_j$: $j$. sınıftaki toplam kelime sayısı.

**Sıfır olasılık sorunu ve Laplace düzeltmesi**

- Bir kelime bir sınıfta hiç geçmiyorsa (ör. "fantastic" pozitif sınıfta hiç yok) $P(w_k \mid v_j) = 0$ olur. Çarpım sıfırlanır; o sınıfın olasılığı başka hiçbir kelimeye bakılmadan 0 çıkar.
- Çözüm: Laplace düzeltmesi (Laplace estimator, add-one smoothing):

$$P(w_k \mid v_j) = \frac{n_{kj} + 1}{n_j + |V|}$$

- $|V|$: sözlükteki farklı kelime sayısı.

**Test adımları**

1. Bilinmeyen belgedeki kelimelerden sözlükte olanlar seçilir. Sözlükte olmayan kelimeler atlanır.
2. Her sınıf için $P(v_j)\prod_k P(w_k \mid v_j)$ hesaplanır.
3. En büyük değeri veren sınıf seçilir.

- Hoca, İngilizcede kök bulmanın kolay olduğunu ("raining" → "rain", "cats" → "cat") ama Türkçede eklerin (geliyorum, geldin, gelir misin) bunu zorlaştırdığını, bunun Türkçe için ayrı bir ön işleme problemi olduğunu söylüyor.

### Örnek 4: Basit Belge Sınıflandırma

- Hoca iki sınıfın kelimelerini tablette yazıyor; tam liste altyazıda net değil.
- Bilinenler:
  - Sözlük $|V| = 6$ kelime (ör. cat, crab, crawl, rain, dog...).
  - A sınıfında sözlükte geçen toplam kelime sayısı $n_A = 4$. "cat" 1 kez geçiyor, "dog" hiç geçmiyor.
  - B sınıfında $n_B = 3$. "cat" 1 kez, "dog" 1 kez geçiyor.
  - $P(A) = P(B) = 1/2$ (yaklaşık eşit kelime sayısı).
- Bilinmeyen belgedeki kelimelerden yalnız "cat" ve "dog" sözlükte var.

$$P(A)\,P(cat \mid A)\,P(dog \mid A) = \frac{1}{2}\cdot\frac{1+1}{4+6}\cdot\frac{0+1}{4+6} = \frac{1}{2}\cdot 0.2 \cdot 0.1 = 0.01$$

$$P(B)\,P(cat \mid B)\,P(dog \mid B) = \frac{1}{2}\cdot\frac{1+1}{3+6}\cdot\frac{1+1}{3+6} = \frac{1}{2}\cdot\frac{2}{9}\cdot\frac{2}{9} \approx 0.0247$$

- $0.0247 > 0.01$. **Sonuç: Belge B sınıfına aittir.**

### Ders İçindeki Bağlantı Sorunu

- Hoca ilk aradan sonra tahtaya yazabilmek için başka bir cihaza geçerken Zoom oturumunu herkes için kapatıp yeniden açtı.
- Öğrencilerin bir kısmı eski oturumda kaldı. Olasılık hatırlatması ve Bayes teoreminin girişi bu sırada yapıldı; bir kısım öğrenci bu bölümü kaçırdı.
- Hoca COVID örneğini baştan yeniden çözdü.
- Bir öğrenci, ileride böyle bir durumda hocanın çıkmadan önce bir öğrenciyi host yapmasını, dönünce hostluğu geri almasını önerdi; aksi halde ilk oturumun kaydı görünmüyor.

### Ders sonrası notlar

- Hoca ayırt edici sınıflandırıcıları sayarken bir an "bunlar hep generatif klasifierler" diyor, sonra "ayırt edici" diye düzeltiyor. Doğrusu: k-NN, yapay sinir ağları, doğrusal regresyon ve karar ağaçları **ayırt edici** modellerdir.
- Hoca bağımsız olay örneği olarak "paranın yazı gelmesi ve tura gelmesi"ni veriyor. Tek atışta yazı ve tura gelmesi **ayrık (mutually exclusive)** olaylardır, bağımsız değildir: Biri gerçekleşirse diğeri kesinlikle gerçekleşmez. Bağımsız olaylara doğru örnek: iki ayrı atışın sonuçları (ilk atışın yazı gelmesi ile ikinci atışın yazı gelmesi).
- Baş ağrısı ($H$) ve nezle ($F$) örneğinde Bayes teoremi uygulanırsa: $P(F \mid H) = \dfrac{P(H \mid F)\,P(F)}{P(H)} = \dfrac{(1/2)(1/40)}{1/10} = \dfrac{1}{8}$. Baş ağrısı olan birinin nezle olma olasılığı 1/8'dir. (Hoca bu hesabı derste yapmıyor; örneğin tamamlanmış hali.)
- Laplace düzeltmesi için hoca "bazı çalışmalarda paya ve paydaya 1 eklenir" diyor. Olasılıkların toplamının 1 olması için paya 1, paydaya sözlük boyutu $|V|$ eklenmelidir. Hoca da pratikte paydaya $|V|$ eklendiğini söylüyor.
- Hoca bir yerde kelime olasılığının paydası için "sınıftaki farklı kelime sayısı" diyor. Doğrusu: payda $n_j$, sınıftaki **toplam** kelime (geçiş) sayısıdır; Laplace düzeltmesinde buna $|V|$ eklenir.
- Hoca Naive Bayes'in belge sınıflandırmada "%100'lere yakın" başarı verebildiğini söylüyor. Bu, veri kümesine ve göreve bağlıdır; Naive Bayes güçlü bir temel (baseline) yöntemdir ama her belge sınıflandırma görevinde %100'e yakın başarı vermez.
- COVID tanısında akciğer bulguları genellikle bilgisayarlı tomografi (BT) ile görülür; hocanın "MR" dediği yer BT olmalıdır. Hocanın "test sonuçları %40 oranla doğru" sözü dersin verdiği %98 duyarlılıkla çelişir; dönemin PCR testlerinin yanlış negatif oranına dair genel bir yorum olarak anlaşılmalı.
- Altyazıdaki "Nayibayez / Mayıs sınıflandırıcısı" Naive Bayes'tir.
- Altyazıdaki "Hidden Markov model" Saklı Markov Modeli'dir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
