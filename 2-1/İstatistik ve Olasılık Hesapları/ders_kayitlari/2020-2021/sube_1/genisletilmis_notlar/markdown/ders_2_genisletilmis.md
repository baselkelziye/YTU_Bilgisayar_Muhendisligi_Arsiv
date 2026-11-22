# Ders 2 Genişletilmiş Notu: Olasılık Modelleri, Olasılık Aksiyomları, Sayma Teknikleri ve Koşullu Olasılığa Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Topluca Kapsayıcı Kümeler, Karşılıklı Ayrık Kümeler ve Bölüntü
- 2. Kümeler Cebiri
- 3. Deneyden Olasılık Modeline
- 4. Küme Kuramı ve Olasılık Kuramı Terimleri
- 5. Mutlak ve Göreli Frekans
- 6. Olasılık Aksiyomları
- 7. Olasılık Yasasının Özellikleri ve İspatları
- 8. Kesikli Modeller ve Eşit Olasılıklı Çıktılar
- 9. Sayma Teknikleri: Çarpma Kuralı, Permütasyon ve Kombinasyon
- 10. Koşullu Olasılığa Giriş
- Örnek Sorular

## 1. Topluca Kapsayıcı Kümeler, Karşılıklı Ayrık Kümeler ve Bölüntü

Ders, bir önceki derste görülen küme işlemlerinin (birleşim, kesişim) ve "disjoint / exhaustive" kavramlarının kısa bir tekrarıyla başladı. Hoca dersi İngilizce anlattı ve önemli yerlerde Türkçe açıklamalar yaptı; öğrencilere dersi izlerken eşzamanlı not almalarını ve kayıtla birlikte tekrar etmelerini tavsiye etti. Dersin, sonraki birçok dersin temelini oluşturduğunu ve kolay olmadığını belirtti.

### 1.1 Topluca kapsayıcı kümeler

$A_1, A_2, \dots, A_n$ kümelerinden oluşan bir aile, **ancak ve ancak** (if and only if, kısaca "iff") birleşimleri örnek uzaya eşitse **topluca kapsayıcı** (collectively exhaustive) olarak adlandırılır (ekrandan, 00:10:00):

$$\bigcup_{i=1}^{n} A_i = A_1 \cup A_2 \cup \dots \cup A_n = \Omega$$

Hoca "iff" kısaltmasını görünce bunun "ancak ve ancak" anlamına geldiğini hatırlatmayı ihmal etmedi.

### 1.2 Karşılıklı ayrık kümeler

Ortak elemanı olmayan kümelerden oluşan aileye **karşılıklı ayrık** (mutually exclusive) denir. Hoca tanımı, ailenin herhangi bir alt topluluğunun kesişiminin boş olması biçiminde yazdı: $1 \le k \le n$ için herhangi $i_1, \dots, i_k$ indisleriyle $A_{i_1} \cap A_{i_2} \cap \dots \cap A_{i_k} = \emptyset$ (ekrandan, 00:15:00).

> **Ders sonrası not:** Tanım genellikle ikili kesişimlerle verilir: her $i \neq j$ için $A_i \cap A_j = \emptyset$. İkili kesişimler boşsa daha fazla kümenin kesişimi de kendiliğinden boştur. Hocanın yazdığı biçimde $k$ en az 2 alınmalıdır; aksi halde $k = 1$ için kümenin kendisinin boş olması gerekirdi.

### 1.3 Bölüntü

Örnek uzay $\Omega$'nın bir **bölüntüsü** (partition), hem topluca kapsayıcı hem de karşılıklı ayrık olan $A_1, \dots, A_n$ kümeleridir (ekrandan, 00:15:00). Yani parçalar örnek uzayı tümüyle doldurur ve birbirleriyle hiç örtüşmez.

### 1.4 Venn şeması ile örnek

Hoca bir örnek uzay içinde birbiriyle kesişen iki olay, $A$ ve $B$ çizdi (ekrandan, 00:15:00 ve 00:20:00).

- $A \cup B \neq \Omega$ olduğundan $A$ ve $B$ tek başlarına topluca kapsayıcı değildir.
- Örnek uzayda $A$ ve $B$ dışında kalan bölge $C$ olarak adlandırıldı. $C$, $A$ ve $B$ cinsinden $C = \overline{A \cup B}$ diye yazılır.
- $A \cup B \cup C = \Omega$ olduğundan $A$, $B$ ve $C$ birlikte topluca kapsayıcıdır.
- $A \cap B \cap C = \emptyset$, $A \cap C = \emptyset$, $B \cap C = \emptyset$, ama $A \cap B \neq \emptyset$. Bu yüzden $A$, $B$, $C$ karşılıklı ayrık **değildir**.
- $D = A \cup B$ tanımlanırsa $C \cup D = \Omega$ (topluca kapsayıcı) ve $C \cap D = \emptyset$ (karşılıklı ayrık) olur. Dolayısıyla $C$ ve $D$ birlikte bir bölüntüdür.

Bu örnek sırasında hoca önce yanlışlıkla $A \cap B$'nin boş olduğunu yazdı; bir öğrencinin uyarısı üzerine düzeltti. Ayrıca bir yerde "exhaustive" yerine "exclusive" yazmıştı, onu da öğrencilerin uyarısıyla düzeltti.

**Soru:** $A$, $B$ ve $C$ topluca "exclusive" mi yoksa "exhaustive" mi? **Cevap:** $A$, $B$, $C$ birlikte topluca kapsayıcıdır (exhaustive), çünkü birleşimleri örnek uzaydır. Yalnız $A$ ve $B$ alınırsa kapsayıcı değildir.

## 2. Kümeler Cebiri

Hoca kümeler üzerindeki temel cebir kurallarını sıraladı (ekrandan, 00:25:00).

- **Birleşme (associative):** Bütün işlemler aynıysa parantezlerin yeri değiştirilebilir.
  - $A \cup (B \cup C) = (A \cup B) \cup C$
  - $A \cap (B \cap C) = (A \cap B) \cap C$
- **Dağılma (distributive):** Bir işlem diğerinin üzerine dağıtılabilir.
  - $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
  - $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$
- **De Morgan kuralları:** Tümleyen alınırken birleşim kesişime, kesişim birleşime dönüşür.
  - $\overline{A \cup B} = \bar A \cap \bar B$
  - $\overline{A \cap B} = \bar A \cup \bar B$

Hoca De Morgan kurallarının özellikle pratikte çok işe yaradığını söyledi: Doğrudan çözülmesi zor görünen bir problem, birleşimi kesişime (ya da tersine) çevirerek çok daha basit hale gelebilir.

## 3. Deneyden Olasılık Modeline

Bu bölümün amacı, fiziksel dünyadaki bir durumdan bir olasılık modeline nasıl geçileceğidir.

- **Deney (experiment):** İzlenen bir prosedürdür. Deneyi yaparız ve sonucu gözlemleriz.
- **Gözlem ve çıktı (outcome):** Deneyin sonunda gördüğümüz şeylere çıktı denir. Örneğin hilesiz bir para atıldığında iki olası gözlem vardır: yazı (head) ya da tura (tail). Bunlar deneyin çıktılarıdır.
- **Olasılık modeli:** Durumu, yani deneyin çıktılarını incelemek için kurulan basitleştirilmiş matematiksel modeldir.

### 3.1 Olasılık modelinin bileşenleri

Hoca bir olasılık modelinin üç bileşenini tanımladı (ekrandan, 00:35:00):

1. **Çıktı (outcome):** Deneyin olası gözlemlerinden biridir. Zar atıldığında 1, 2, 3, 4, 5 ve 6 olmak üzere altı olası çıktı vardır; her biri bir çıktıdır.
2. **Örnek uzay (sample space, $\Omega$):** Bütün olası çıktıların kümesidir.
3. **Olay (event, $A$):** Çıktılardan oluşan bir kümedir, yani örnek uzayın bir alt kümesidir: $A \subset \Omega$. Hoca, olayın bütün çıktılar olmak zorunda olmadığını, bütün çıktıların kümesinin örnek uzay olduğunu vurguladı.

## 4. Küme Kuramı ve Olasılık Kuramı Terimleri

Hoca terminolojinin çok önemli olduğunu söyleyerek küme kuramı ile olasılık kuramındaki karşılıkları bir tabloyla verdi (ekrandan, 00:35:00 ve 00:40:00).

| Küme kuramı | Olasılık kuramı | Sembol |
|---|---|---|
| Evrensel küme | Örnek uzay | $\Omega$ ya da $S$ |
| Kümenin elemanı | Çıktı | $e_1, e_2, \dots$ ya da $o_1, o_2, \dots$ |
| Alt küme | Olay | $A$, $E$ gibi büyük harfler |
| Ayrık kümeler | Karşılıklı ayrık olaylar | $E_1 \cap E_2 = \emptyset$ |
| Boş küme | İmkânsız olay | $\emptyset$ |
| Evrensel küme | Kesin olay | $\Omega$ |

**Soru (hocadan):** İmkânsız olayın tümleyeni nedir? **Cevap:** Kesin olay, yani örnek uzay: $\bar\emptyset = \Omega$ (ekrandan, 00:40:00).

## 5. Mutlak ve Göreli Frekans

### 5.1 Mutlak frekans

Belirli bir deneyle ilişkili bir $A$ olayı ele alınır. Deney $N$ kez tekrarlanır ve $A$ olayının kaç kez gerçekleştiği $\alpha$ ile gösterilir (ekrandan, 00:40:00). $\alpha$'ya $A$ olayının **mutlak frekansı** (absolute frequency) denir.

**Soru (hocadan):** $\alpha$ hangi değerleri alabilir? **Cevap:** Her tekrarda $A$ gerçekleşirse $\alpha = N$, hiç gerçekleşmezse $\alpha = 0$ olur. $\alpha$ bir tam sayıdır: $\alpha \in \{0, 1, 2, \dots, N-1, N\}$. En büyük değeri tekrar sayısına bağlıdır.

**Soru (hocadan):** $A$ olayı $\alpha$ kez gerçekleştiyse tümleyeni $\bar A$ kaç kez gerçekleşir? **Cevap:** $N - \alpha$ kez.

### 5.2 Göreli frekans

Yeni bir sayı tanımlanır:

$$f_A(N) = \frac{\alpha}{N}$$

Buna $A$ olayının **göreli frekansı** (relative frequency) ya da **normalize frekansı** denir. Anlamı, deneyin $N$ tekrarında $A$ olayının gerçekleştiği tekrarların oranıdır (ekrandan, 00:50:00).

### 5.3 Göreli frekansın özellikleri

- $0 \le f_A(N) \le 1$. $\alpha$ en çok $N$ olabildiği için en büyük değer $N/N = 1$, en küçük değer $0$'dır. Bu her pozitif doğal sayı $N$ için geçerlidir.
- $f_\Omega(N) = 1$, çünkü örnek uzay her tekrarda gerçekleşir.
- $A \cap B = \emptyset$ (ayrık olaylar) ise $f_{A \cup B}(N) = f_A(N) + f_B(N)$. Her tekrarın sonucu ya $A$'da ya $B$'dedir, ikisinde birden olamaz; bu yüzden birleşimin frekansı tek tek frekansların toplamıdır.
- Sonuç olarak $A \cup \bar A = \Omega$ ve $A \cap \bar A = \emptyset$ olduğundan
  $$1 = f_\Omega(N) = f_{A \cup \bar A}(N) = f_A(N) + f_{\bar A}(N) \;\Rightarrow\; f_{\bar A}(N) = 1 - f_A(N)$$
  (ekrandan, 00:55:00).

### 5.4 Zar örneği

Hoca hilesiz bir zarın 60 kez atılmasını MATLAB'de `randi(6,1,60)` komutuyla simüle etti ve çıkan 60 sayılık diziyi ekranda gösterdi (ekrandan, 01:00:00). <!-- BELİRSİZ: 60 çıktılık dizi karede okunamayacak kadar küçük; aşağıdaki sayımlar hocanın sözlü sayımından alındı. -->

- **a)** $A = \{1\}$. Dizideki 1'ler sayılır: $\alpha_A = 11$. Buradan $f_A(60) = \dfrac{\#A}{N} = \dfrac{11}{60} \approx 0{,}183 \approx \dfrac{1}{6}$.
- **b)** $B = \{1, 3, 5\}$ (tek sayılar). 1'lerin sayısı 11, 3'lerin sayısı 9, 5'lerin sayısı 13 bulundu: $f_B(60) = \dfrac{11 + 9 + 13}{60} = \dfrac{33}{60} = 0{,}55 \approx \dfrac{1}{2}$.
- **c)** $C = \{2, 3, 5\}$ (asal sayılar). Hoca sayımı öğrencilere bırakıp sonucun yaklaşık $31/60 \approx 0{,}517 \approx 1/2$ olduğunu söyledi.

Hoca bu sonuçları şöyle yorumladı: Zarı altı kez atarsanız bir kez 1 görmeyi beklersiniz. Ama gerçekte altı atışta hepsi 6 da gelebilir; zarı çok fazla, sınırda sonsuz kez atarsanız 1 gelme oranının $1/6$ olduğunu görürsünüz.

> **Ders sonrası not:** Hoca İngilizce anlatımda "altı kez atarsanız en az bir kez 1 görürsünüz" dedi, hemen ardından Türkçe olarak bunun garantili olmadığını belirtti. Doğrusu Türkçe açıklamadır: altı atışta en az bir 1 görme olasılığı $1 - (5/6)^6 \approx 0{,}665$'tir. Beklenen 1 sayısı ise $6 \cdot \tfrac{1}{6} = 1$'dir.

### 5.5 Frekanstan olasılığa

Tekrar sayısı $N$ çok büyük olduğunda bir olayın olasılığı göreli frekansıyla tahmin edilebilir. Bu cümle limit ile şöyle yazılır:

$$\Pr(A) = \lim_{N \to \infty} f_A(N)$$

Hoca bu formül için ekrana "THANKS TO AL-KINDI" yazdı ve formülü El-Kindî'nin önerdiğini söyledi (ekrandan, 01:05:00).

> **Ders sonrası not:** Olasılığın göreli frekansın limiti olarak tanımlanması büyük olasılıkla genellikle 19. yüzyılda John Venn'e ve 20. yüzyılda Richard von Mises'e atfedilir. El-Kindî ise 9. yüzyılda harf sıklıklarını kullanarak şifre çözmesiyle (frekans analizi) bilinir; hocanın atfı bu bağlamda büyük olasılıkla frekans fikrinin erken kullanımına işaret eder.

## 6. Olasılık Aksiyomları

Hoca önce aksiyomun ne olduğunu sordu. Bir öğrenci "doğruluğu kanıtlanmayan, doğru kabul edilen tanımlar" diye cevap verdi. Hoca bunu, aksiyomların matematiksel olarak ispatlanmadığı, gözlemle her zaman doğru olduğu görülen kabuller olduğu diye tamamladı.

Bir $A$ olayı için olasılık yasası, aşağıdaki aksiyomları sağlayan bir $\Pr(A)$ sayısı atar (ekrandan, 01:25:00):

- **Aksiyom 1 (negatif olmama, non-negativity):** $\Pr(A) \ge 0$. Olasılık negatif olamaz.
- **Aksiyom 2 (normalleştirme, normalization):** $\Pr(\Omega) = 1$.
- **Aksiyom 3 (toplanabilirlik, additivity):** $A_1, A_2, \dots, A_n$ karşılıklı ayrık olaylarsa
  $$\Pr(A_1 \cup A_2 \cup \dots \cup A_n) = \Pr\left(\bigcup_{i=1}^{n} A_i\right) = \Pr(A_1) + \Pr(A_2) + \dots + \Pr(A_n) = \sum_{i=1}^{n} \Pr(A_i)$$

Aksiyom 3 sırasında hoca karşılıklı ayrık olayları tekrar sordu; bir öğrenci aralarında hiç kesişim olmadığını söyledi, hoca da bu kümelerin herhangi bir bileşiminin kesişiminin boş olduğunu ekledi.

Göreli frekansın 5.3'teki özellikleriyle bu aksiyomların birebir örtüştüğüne dikkat edin: $f_A(N) \ge 0$, $f_\Omega(N) = 1$ ve ayrık olaylarda toplanabilirlik.

## 7. Olasılık Yasasının Özellikleri ve İspatları

Bütün özellikler üç aksiyomdan türetilir. Hoca ispatları adım adım yaptı.

### 7.1 Özellik 1: Olasılık 0 ile 1 arasındadır

$0 \le \Pr(A) \le 1$.

**İspat:** $A \cup \bar A = \Omega$ ve $A \cap \bar A = \emptyset$. Aksiyom 3'ten $\Pr(A \cup \bar A) = \Pr(A) + \Pr(\bar A)$; Aksiyom 2'den $\Pr(\Omega) = 1$. İkisi birleştirilince
$$\Pr(A) + \Pr(\bar A) = 1.$$
Aksiyom 1'den her iki terim de negatif değildir. Negatif olmayan iki sayının toplamı 1 ise her biri en çok 1 olabilir. Sonuç olarak $0 \le \Pr(A) \le 1$ (ekrandan, 01:30:00).

### 7.2 Özellik 2: Tümleyenin olasılığı

$\Pr(\bar A) = 1 - \Pr(A)$. Hoca bunun ispatını basit olduğu için öğrencilere evde yapmalarını bıraktı (çözüm Örnek Sorular bölümünde).

### 7.3 Özellik 3: İmkânsız olayın olasılığı sıfırdır

$\Pr(\emptyset) = 0$.

**İspat:** İmkânsız olayın tümleyeni örnek uzaydır: $\bar\emptyset = \Omega$. Buradan $\emptyset \cup \bar\emptyset = \emptyset \cup \Omega = \Omega$ ve $\emptyset \cap \Omega = \emptyset$ (ekrandan, 01:30:00). Aksiyom 3 ile
$$\Pr(\emptyset \cup \bar\emptyset) = \Pr(\emptyset) + \Pr(\bar\emptyset) \;\Rightarrow\; \Pr(\Omega) = \Pr(\emptyset) + \Pr(\Omega) \;\Rightarrow\; 1 = \Pr(\emptyset) + 1,$$
dolayısıyla $\Pr(\emptyset) = 0$.

### 7.4 Özellik 4: Birleşimin olasılığı

$$\Pr(A \cup B) = \Pr(A) + \Pr(B) - \Pr(A \cap B)$$

**İspat:** Venn şemasında $A$ kümesi iki ayrık parçaya bölünür: $A \setminus B$ ($A$ fark $B$) ve $A \cap B$.

- $A = (A \setminus B) \cup (A \cap B)$ ve bu iki parça ayrıktır. Aksiyom 3'ten:
  $$\Pr(A) = \Pr(A \setminus B) + \Pr(A \cap B) \quad (1)$$
- Benzer biçimde $A \cup B = (A \setminus B) \cup B$ ve $A \setminus B$ ile $B$ ayrıktır:
  $$\Pr(A \cup B) = \Pr(A \setminus B) + \Pr(B) \quad (2)$$
- (1)'den (2) çıkarılır: $\Pr(A) - \Pr(A \cup B) = \Pr(A \cap B) - \Pr(B)$. $\Pr(A \setminus B)$ terimleri birbirini götürür.
- Terimler yer değiştirilince $\Pr(A) + \Pr(B) - \Pr(A \cap B) = \Pr(A \cup B)$ elde edilir (ekrandan, 01:40:00). Hoca ispatın sonuna bir kare koyarak ispatın tamamlandığını (QED) gösterdi.

### 7.5 Özellik 5: Bölüntü özelliği

Herhangi bir $A$ olayı ve bir $B_1, B_2, \dots, B_n$ bölüntüsü için (ekrandan, 01:40:00):

$$\Pr(A) = \sum_{i=1}^{n} \Pr(A \cap B_i)$$

Hoca örnek uzayı $B_1, \dots, B_{10}$ parçalarına böldüğü bir şekil çizdi. $B_i$'ler karşılıklı ayrık ve topluca kapsayıcı olduğu için bölüntüdür. $A$ olayı $B_2, B_3, \dots, B_{10}$ ile kesişiyor ama $B_1$ ile kesişmiyor; bu yüzden $\Pr(A \cap B_1) = 0$. $A$'nın olasılığını bu kesişimler belirler:
$$\Pr(A) = \Pr(B_2 \cap A) + \Pr(B_3 \cap A) + \dots + \Pr(B_9 \cap A) + \Pr(B_{10} \cap A) = \sum_{i=2}^{n} \Pr(A \cap B_i)$$
(ekrandan, 01:45:00). $\Pr(A \cap B_1) = 0$ olduğu için toplamın $i = 1$'den ya da $i = 2$'den başlaması sonucu değiştirmez.

**İspat:** $A = (A \cap B_1) \cup (A \cap B_2) \cup \dots \cup (A \cap B_n)$ ve her $i \neq j$ için $A \cap B_i$ ile $A \cap B_j$ ayrıktır. Aksiyom 3 ile $\Pr(A) = \Pr(A \cap B_1) + \Pr(A \cap B_2) + \dots + \Pr(A \cap B_n)$.

**Soru:** Bölüntüde $B$'lerin karşılıklı ayrık olması zorunlu mu? **Cevap:** Evet. Bölüntü için iki şart birlikte sağlanmalıdır: $B$'lerin birleşimi örnek uzay olmalı (topluca kapsayıcılık) ve $B$'ler birbiriyle kesişmemeli (karşılıklı ayrıklık). Bölüntü örnek uzayı parçalamak demektir; parçalar kesişseydi bölüntü olmazdı.

### 7.6 Özellik 6: Monotonluk

$A \subseteq B$ ise $\Pr(A) \le \Pr(B)$.

**İspat:** $A \subseteq B$ ise $B = A \cup (B \setminus A)$ yazılabilir ve $A$ ile $B \setminus A$ ayrıktır. Aksiyom 3'ten $\Pr(B) = \Pr(A) + \Pr(B \setminus A)$. Aksiyom 1'den $\Pr(B \setminus A) \ge 0$. $\Pr(B)$, $\Pr(A)$'ya negatif olmayan bir sayı eklenerek elde edildiği için $\Pr(A) \le \Pr(B)$.

> **Hocanın vurgusu:** $A$, $B$'nin alt kümesiyse $A$'nın olasılığı $B$'ninkinden büyük olamaz; çünkü $A$'nın gerçekleştiği her durumda $B$ de gerçekleşir. Bu özellik ayrıca dikkate alınmalıdır.

## 8. Kesikli Modeller ve Eşit Olasılıklı Çıktılar

### 8.1 Model kurmanın iki adımı

Fiziksel dünyadaki bir durumu incelemek için matematiksel bir model kurulur. Model kurmak iki şey gerektirir:

1. **Örnek uzayı tanımlamak.** Hoca, bir olasılık sorusuyla karşılaşınca yapılacak ilk işin örnek uzayı tanımlamak olduğunu söyledi.
2. **Olasılık yasasını belirlemek.** Belirlenen olasılık yasası üç aksiyomla (negatif olmama, normalleştirme, toplanabilirlik) tutarlı olmalıdır (ekrandan, 02:05:00).

### 8.2 Örnekler

**Hilesiz para atışı:** $\Omega = \{H, T\}$, $\Pr(H) = 1/2$, $\Pr(T) = 1/2$ (ekrandan, 02:05:00).

**Üç hilesiz para atışı:** Örnek uzay
$$\Omega = \{HHH, HHT, HTH, HTT, THH, THT, TTH, TTT\}$$
sekiz çıktıdan oluşur ve her çıktının olasılığı $1/8$'dir: $\Pr(HHH) = \Pr(HHT) = \dots = \Pr(TTT) = 1/8$. Çıkarılan sonuç, her çıktının eşit olasılıklı olmasıdır.

"Tam olarak iki yazı (head) gelmesi" olayı örnek uzayın bir alt kümesidir (ekrandan, 02:10:00):
$$A = \{HTH, THH, HHT\}, \qquad \Pr(A) = \Pr(HTH) + \Pr(THH) + \Pr(HHT) = \tfrac{1}{8} + \tfrac{1}{8} + \tfrac{1}{8} = \tfrac{3}{8}.$$
Olayın çıktıları öğrencilerle birlikte örnek uzaydan seçildi.

### 8.3 Eşit olasılıklı çıktılar

Hoca "equally likely" ifadesini Türkçeye "eşit olabilirlikli" diye çevirdi. Ekrandaki tanım şöyledir (ekrandan, 02:15:00): Bir deneyle ilişkili iki olay $A$ ve $B$, iki olaydan birinin gerçekleşmesinin diğerine göre kayırıldığını varsaymak için hiçbir neden yoksa eşit olasılıklıdır (equally probable).

Hoca Türkçe açıklamada iki olayın eşit olasılıklı olduğunu ve birinin olmasının diğerini desteklemediğini söyledi; zar örneğinde tek ve çift sayıların iki ayrı, kesişmeyen olay olduğunu, tek sayılar ile asal sayıların ise kesiştikleri için birbirini etkilediğini belirtti.

> **Ders sonrası not:** Eşit olasılıklılık yalnız olasılıkların eşitliği ile ilgilidir; olayların ayrık ya da bağımsız olmasıyla ilgili değildir. Örneğin zarda "tek sayı" ($\{1,3,5\}$) ve "asal sayı" ($\{2,3,5\}$) olaylarının ikisinin de olasılığı $1/2$'dir; bu yüzden kesişmelerine rağmen eşit olasılıklıdırlar. Olayların birbirini etkileyip etkilememesi bağımsızlık kavramıdır ve hocanın sonraki derse bıraktığı konudur.

Örnek uzay $\Omega = \{\omega_1, \omega_2, \dots, \omega_n\}$ eşit olasılıklı çıktılardan oluşuyorsa her çıktının olasılığı örnek uzaydaki çıktı sayısının tersidir (ekrandan, 02:20:00):
$$\Pr(\omega_i) = \frac{1}{|\Omega|} = \frac{1}{n}.$$

$k$ çıktıdan oluşan herhangi bir $E$ olayının (örneğin $E = \{\omega_1, \omega_5, \omega_7, \omega_{20}, \dots\}$, $|E| = k$) olasılığı:
$$\Pr(E) = \frac{k}{n} = \frac{\#\text{ (E'deki çıktılar)}}{\#\text{ (}\Omega\text{'daki çıktılar)}}$$
Bir olayı oluşturan çıktılara **elverişli** (favorable) çıktılar da denir; bu yüzden formül "elverişli çıktı sayısı / toplam çıktı sayısı" diye de okunur. $\#$ sembolü "sayısı" anlamındadır.

## 9. Sayma Teknikleri: Çarpma Kuralı, Permütasyon ve Kombinasyon

Eşit olasılıklı modellerde olasılık hesabı çıktıları saymaya dayandığı için hoca kombinatorik ve sayma tekniklerine geçti.

### 9.1 Çarpma kuralı

Bir deney $k$ bileşenden (alt deneyden) oluşuyorsa ve bileşenlerin olası çıktı sayıları $n_1, n_2, n_3, n_4, \dots, n_k$ ise deneyin toplam çıktı sayısı, yani örnek uzayın büyüklüğü (ekrandan, 02:25:00):
$$n_1 \times n_2 \times n_3 \times n_4 \times \dots \times n_k.$$

Bütün bileşenlerin çıktı sayısı aynıysa ($n_i = n_j = n$), toplam çıktı sayısı $n$'nin $k$ kez çarpımı, yani $n^k$ olur.

Hoca bunu üç para atışıyla bağladı: Tek para atışında örnek uzayın büyüklüğü 2'dir; üç kez atınca $2 \times 2 \times 2 = 2^3 = 8$ olur. Bir öğrencinin isteği üzerine Türkçe olarak da açıkladı: Deney $k$ alt deneyden oluşur, birincinin $n_1$, ikincinin $n_2$ tane çıktısı vardır ve hepsi birlikte yapıldığında oluşan örnek uzayın büyüklüğü bileşenlerin örnek uzay büyüklüklerinin çarpımıdır. Hepsinin çıktı sayısı eşitse $n$ sayısı $k$ kez çarpılır ve $n^k$ elde edilir.

### 9.2 Permütasyon

**Permütasyon**, $n$ nesneli bir kümeden ($n \ge k$) birbirinden ayırt edilebilir (distinguishable) $k$ nesnenin olası bir seçimidir. Permütasyonda **seçilen nesnelerin sırası önemlidir** (ekrandan, 02:35:00).

İki tür permütasyon vardır:

- **Yerine koyarak (with replacement):** Örneğin bir torbadan bir bilye çekilir, sonra torbaya geri konur ve işlem tekrarlanır. Bu durumda deney, her biri $n$ olası çıktılı $k$ özdeş bileşenden oluşur. $k$ nesneyi seçmenin olası yollarının sayısı:
  $$P_r(n,k) = n^k$$
- **Yerine koymadan (without replacement):** Birinci seçimde $n$ seçenek vardır; seçilen geri konmadığı için ikincide $n-1$, üçüncüde $n-2$ seçenek kalır ve $k$'ıncı seçimde $n-k+1$ seçenek olur. Seçim sayısı:
  $$P(n,k) = n(n-1)(n-2)\cdots(n-k+1)$$
  Pay ve payda $(n-k)(n-k-1)\cdots 2 \cdot 1$ ile genişletilince ortak terimler sadeleşir (ekrandan, 02:40:00):
  $$P(n,k) = \frac{n(n-1)\cdots(n-k+1)(n-k)\cdots 2\cdot 1}{(n-k)(n-k-1)\cdots 2\cdot 1} = \frac{n!}{(n-k)!}$$

### 9.3 Kombinasyon

**Kombinasyon**, $n$ nesneden ($n \ge k$) ayırt edilebilir $k$ nesnenin olası bir seçimidir; ancak burada **seçilen nesnelerin sırası hesaba katılmaz** (ekrandan, 02:40:00 ve 02:45:00).

- **Yerine koymadan:** $k$ nesneyi seçmenin olası yollarının sayısı
  $$C(n,k) = C_n^k = \frac{P(n,k)}{P(k,k)} = \frac{n!}{k!\,(n-k)!} = \binom{n}{k}$$
  Burada $P(k,k) = k!$, seçilen $k$ nesnenin kendi aralarındaki sıralanış sayısıdır; sıra önemsiz olduğu için permütasyon sayısı buna bölünür.
- **Yerine koyarak:** $k$ nesneyi seçmenin olası yollarının sayısı
  $$C_r(n,k) = C_{k+n-1}^{k} = \frac{(k+n-1)!}{k!\,(n-1)!} = \binom{n+k-1}{k}$$
  Hoca bu formülü yazarken önce yanlış bir ifade yazıp düzeltti; doğru biçim yukarıdakidir (ekrandan, 02:45:00).

> **Ek bilgi (derste anlatılmadı):** Yerine koyarak kombinasyon formülü "yıldızlar ve çubuklar" yöntemiyle açıklanır. $k$ seçimi $k$ yıldız, $n$ türü ayıran sınırları $n-1$ çubuk olarak düşünürsek her seçim, $k + n - 1$ konumdan $k$'sının yıldız olduğu bir diziye karşılık gelir. Bu tür dizilerin sayısı $\binom{n+k-1}{k}$'dır.

Hoca, permütasyon ve kombinasyonla ilgili bölümlerin derste önerilen kitaptan (Michael Baron) okunmasını önemle tavsiye etti.

## 10. Koşullu Olasılığa Giriş

### 10.1 Motivasyon ve örnekler

Hoca koşullu olasılığı örneklerle motive etti.

- **Kablo örneği:** İki fabrikada üretilen kablolardan biri kopuk çıkıyor. Kopuk kablonun birinci ya da ikinci fabrikada üretilmiş olma olasılığı nedir? Burada bir koşul vardır: kablonun kopuk olduğu biliniyor; bu koşul altında kablonun hangi fabrikadan geldiğinin olasılığı soruluyor. <!-- BELİRSİZ: Örneğin başlangıcı altyazıda bozuk; uzunluk (100 metre gibi) ve fabrikalarla ilgili ayrıntılar okunamadı. -->
- **Radar örneği:** Radar ekranında bir nokta görünüyor. Bu noktanın bir uçağa karşılık gelme olasılığı nedir? Nokta bir uçak olabileceği gibi bir roket ya da başka bir şey de olabilir. Koşul, ekranda bir nokta görülmüş olmasıdır.
- **Zar örneği:** Hilesiz bir zar atılıyor ve sonucun çift olduğu söyleniyor. Sonucun 1 olma olasılığı nedir? Sıfır. Sonucun 6 olma olasılığı nedir? $1/3$ (ekrandan, 02:55:00).

Normalde her çıktının olasılığı $1/6$'dır, ama koşul eklenince olasılıklar değişir: Sonucun çift olduğu bilindiği için olası çıktılar $\{2, 4, 6\}$'ya iner; 1 bu kümede olmadığından olasılığı 0, 2, 4 ve 6'nın her birinin olasılığı $1/3$ olur. Hoca koşullu olasılık formülünü bu gözlemden yola çıkarak verdi.

### 10.2 Tanım

$\Pr(B) \neq 0$ olacak şekilde iki olay $A$ ve $B$ verilsin; yani $B$ imkânsız bir olay değildir. $B$ olayı verildiğinde $A$ olayının **koşullu olasılığı** şöyle tanımlanır (ekrandan, 03:00:00):
$$\Pr(A \mid B) = \frac{\Pr(A \cap B)}{\Pr(B)}$$
"$B$ verildiğinde" ifadesi, $B$'nin gerçekleştiğinin bilindiği anlamına gelir; soru, bu bilgi altında $A$'nın gerçekleşmiş olma olasılığıdır.

> **Hocanın vurgusu:** $\Pr(A \setminus B)$ ile $\Pr(A \mid B)$ aynı şey değildir. Birincisi "$A$ fark $B$" olayının olasılığı, ikincisi "$B$ verildiğinde $A$"nın olasılığıdır; çizginin yönüne dikkat edilmelidir.

**Soru:** Koşullu olasılık yazılırken kullanılan "Pr" ne anlama geliyor? **Cevap:** "Probability" (olasılık) demektir. Yalnız büyük $P$ harfi de kullanılabilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Örnek uzayda kesişen iki olay $A$ ve $B$ veriliyor, $C = \overline{A \cup B}$ ve $D = A \cup B$. (a) $A, B, C$ topluca kapsayıcı mıdır? (b) $A, B, C$ karşılıklı ayrık mıdır? (c) $C$ ve $D$ bir bölüntü oluşturur mu?

> **Çözüm:** (a) $A \cup B \cup C = \Omega$, dolayısıyla evet. (b) $A \cap C = B \cap C = \emptyset$ ama $A \cap B \neq \emptyset$, dolayısıyla hayır. (c) $C \cup D = \Omega$ ve $C \cap D = \emptyset$, dolayısıyla evet, $\{C, D\}$ bir bölüntüdür.

**Soru 2** (derste sözlü, 00:37:43): İmkânsız olayın tümleyeni nedir?

> **Çözüm:** Kesin olay, yani örnek uzay: $\bar\emptyset = \Omega$.

**Soru 3** (derste sözlü, 00:42:02 ve 00:44:52): Deney $N$ kez tekrarlanıyor ve $A$ olayı $\alpha$ kez gerçekleşiyor. $\alpha$ hangi değerleri alabilir? $\bar A$ kaç kez gerçekleşir?

> **Çözüm:** $\alpha \in \{0, 1, \dots, N\}$. $\bar A$, $N - \alpha$ kez gerçekleşir.

**Soru 4** (ekrandan, 01:00:00): Hilesiz bir zar 60 kez atılıyor (MATLAB `randi(6,1,60)`). (a) $A = \{1\}$, (b) $B = \{1, 3, 5\}$, (c) $C = \{2, 3, 5\}$ olaylarının göreli frekanslarını bulun.

> **Çözüm:** Hocanın sayımına göre (a) $f_A(60) = 11/60 \approx 0{,}183 \approx 1/6$; (b) $f_B(60) = (11 + 9 + 13)/60 = 33/60 = 0{,}55 \approx 1/2$; (c) $f_C(60) \approx 31/60 \approx 0{,}517 \approx 1/2$. Gerçek olasılıklar sırasıyla $1/6$, $1/2$ ve $1/2$'dir.

**Soru 5** (derste sözlü, 01:28:44): $\Pr(\bar A) = 1 - \Pr(A)$ olduğunu ispatlayın.

> **Çözüm (derste verilmedi):** $A \cup \bar A = \Omega$ ve $A \cap \bar A = \emptyset$. Aksiyom 3'ten $\Pr(A \cup \bar A) = \Pr(A) + \Pr(\bar A)$, Aksiyom 2'den $\Pr(\Omega) = 1$. Dolayısıyla $\Pr(A) + \Pr(\bar A) = 1$, yani $\Pr(\bar A) = 1 - \Pr(A)$.

**Soru 6** (derste sözlü, 01:28:57): $\Pr(\emptyset) = 0$ olduğunu ispatlayın.

> **Çözüm:** $\emptyset \cup \Omega = \Omega$ ve $\emptyset \cap \Omega = \emptyset$. Aksiyom 3 ile $\Pr(\Omega) = \Pr(\emptyset) + \Pr(\Omega)$, yani $1 = \Pr(\emptyset) + 1$; buradan $\Pr(\emptyset) = 0$.

**Soru 7** (ekrandan, 02:10:00): Üç hilesiz para atılıyor. Tam olarak iki yazı (head) gelme olasılığı nedir?

> **Çözüm:** $|\Omega| = 2^3 = 8$ ve her çıktının olasılığı $1/8$. $A = \{HTH, THH, HHT\}$ olduğundan $\Pr(A) = 3 \cdot \tfrac{1}{8} = \tfrac{3}{8}$.

**Soru 8** (ekrandan, 02:55:00): Hilesiz bir zar atılıyor ve sonucun çift olduğu söyleniyor. Sonucun 1 olma olasılığı nedir? Sonucun 6 olma olasılığı nedir?

> **Çözüm:** $B = \{2, 4, 6\}$, $\Pr(B) = 1/2$. $\Pr(\{1\} \mid B) = \Pr(\emptyset)/\Pr(B) = 0$. $\Pr(\{6\} \mid B) = \Pr(\{6\})/\Pr(B) = (1/6)/(1/2) = 1/3$.

## Dersin Toparlaması

Bu derste olasılık kuramının temeli kuruldu. Önce kümeler dili tamamlandı: topluca kapsayıcılık, karşılıklı ayrıklık, bölüntü ve kümeler cebiri (birleşme, dağılma, De Morgan). Ardından deneyden olasılık modeline geçildi; çıktı, örnek uzay ve olay kavramları ile küme kuramı ve olasılık kuramı arasındaki terim eşleşmesi verildi. Göreli frekans tanımlanıp özellikleri incelendi ve olasılığın, tekrar sayısı sonsuza giderken göreli frekansın limiti olarak düşünülebileceği gösterildi. Göreli frekansın özellikleri, olasılığın üç aksiyomunu (negatif olmama, normalleştirme, toplanabilirlik) doğal olarak motive etti; bu aksiyomlardan tümleyen, imkânsız olay, birleşim, bölüntü ve monotonluk özellikleri ispatlandı.

Dersin ikinci yarısında kesikli modeller ve eşit olasılıklı çıktılar ele alındı; eşit olasılıklı bir modelde olasılığın elverişli çıktıların toplam çıktılara oranı olduğu görüldü. Bu oranı hesaplamak için çarpma kuralı, yerine koyarak ve koymadan permütasyon ile kombinasyon formülleri türetildi. Son olarak koşullu olasılık örneklerle tanıtıldı ve $\Pr(A \mid B) = \Pr(A \cap B)/\Pr(B)$ tanımı verildi. Hoca bir sonraki derste koşullu olasılığın özelliklerine, Bayes teoremine, toplam olasılık teoremine ve bağımsızlığa geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
