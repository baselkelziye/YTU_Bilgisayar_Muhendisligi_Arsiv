# Ders 5 Genişletilmiş Notu: Değer İndirgeme (ChiMerge) ve Naive Bayes Sınıflandırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Değer İndirgeme ve Öz Nitelik Ayrıklaştırma
- 2. ChiMerge Tekniği
- 3. Olumsallık Tablosu ve Ki-Kare Testi
- 4. ChiMerge Örneği
- 5. Sınıflandırmaya Giriş ve Bayes Teoremi
- 6. Naive Bayes Sınıflandırıcı
- 7. Kategorik Öz Nitelikli Örnek: Kredi Kartı Promosyonları
- 8. Sayısal Öz Nitelik ve Laplace Düzeltmesi: Araç Sigortası Örneği
- Örnek Sorular

## 1. Değer İndirgeme ve Öz Nitelik Ayrıklaştırma

Ders, önceki haftada başlanan veri indirgeme (data reduction) konusunun devamıdır. İlk bölümde veri indirgemenin üçüncü boyutu olan değer indirgeme (values reduction) bitirilir, kalan sürede sınıflandırma yöntemlerine geçilir.

Ekrandaki "Values Reduction" slaytı konuyu şöyle tanımlar (ekrandan, 00:15:00):

- Bir öz niteliğin ayrık değer sayısının azaltılması, veri indirgeme aşamasındaki ikinci teknik grubuna dayanır; bunlara öz nitelik ayrıklaştırma (feature discretization) teknikleri denir.
- Bu tekniklerin görevi, sürekli öz niteliklerin değerlerini az sayıda aralığa ayırmak ve her aralığı ayrık bir sembole eşlemektir.
- Yararları: veri tanımı sadeleşir, veri ve nihai veri madenciliği sonuçları kolay anlaşılır; ayrıca ayrık değerlerle daha fazla veri madenciliği yöntemi uygulanabilir.
- "Eski usul" ayrıklaştırma, öz nitelik hakkındaki ön bilgiye dayanılarak elle yapılır. Örneğin 0 ile 150 arasında sürekli bir değer olarak verilen yaş, sağduyu ya da uzlaşıyla çocuk, ergen, yetişkin, orta yaş ve yaşlı gibi kategorilere ayrılabilir. Kesim noktaları (cut-off points) öznel olarak belirlenir.

Hoca, önceki derste görülen veri düzleştirmenin (data smoothing) benzer bir işlem olduğunu hatırlatır. Düzleştirmede sayısal ve sürekli öz nitelik sıralanır, değerler kutulara (bin) ayrılır ve her kutu bir temsilci değerle gösterilir. Kutuyu bir sayıyla temsil etmek istenirse ortalama, medyan ya da kutu sınırları kullanılabilir. Bu derste ise kutular çoğunlukla kategorik değerlerle temsil edilecektir. Elle ayrıklaştırmada bir alan uzmanına, kesim noktalarına ve oluşan aralıkları kategorik bir öz nitelik gibi etiketlemeye ihtiyaç vardır.

<!-- BELİRSİZ: 00:16:46-00:18:40 arasında altyazı uzun tekrar halüsinasyonlarına dönüşüyor; bu aralıkta düzleştirme adımlarının anlatımı yalnız bağlamdan kuruldu. -->

## 2. ChiMerge Tekniği

Bu haftanın amacı, sayısal ve sürekli bir öz niteliği ayrıklaştırmak için ChiMerge tekniğini öğrenmektir. Ekrandaki tanım şöyledir (ekrandan, 00:20:00):

- ChiMerge, bir öz nitelik için birden çok aralığın kalitesini $\chi^2$ (ki-kare) istatistiğiyle çözümleyen otomatik bir ayrıklaştırma algoritmasıdır.
- Algoritma, örneklerin çıktı sınıflandırmasına göre iki komşu (adjacent) aralıktaki veri dağılımlarının benzerliğini belirler.
- $\chi^2$ testinin sonucu çıktı sınıfının öz niteliğin aralıklarından bağımsız olduğunu gösteriyorsa aralıklar birleştirilmelidir. Aksi hâlde aralıklar arasındaki fark istatistiksel olarak anlamlıdır ve birleştirme yapılmaz.

Algoritmanın adımları hocanın anlatımına göre şöyledir:

1. Verilen öz nitelik artan sırada sıralanır.
2. Öz niteliğin her değeri ayrı bir aralıkta olacak biçimde başlangıç aralıkları tanımlanır.
3. Bütün komşu aralık çiftleri için $\chi^2$ testi uygulanır.
4. En küçük $\chi^2$ değerini veren çift, bu değer eşiğin altındaysa birleştirilir. Bir iterasyonda yalnız bir birleştirme yapılır.
5. Birleştirilecek çift kalmayana kadar 3. ve 4. adımlar tekrarlanır.

<!-- BELİRSİZ: 00:19:48-00:21:38 arasında adımların slaytı altyazıda bozuk ve bu aralığa ait kare yok; adımlar hocanın sonraki anlatımından (00:52:36, 00:54:24, 00:58:02 ve 01:26:27) kuruldu. -->

## 3. Olumsallık Tablosu ve Ki-Kare Testi

İki sınıflı ($k = 2$) bir problemde iki aralığın birleştirilmesi incelenirken $2 \times 2$ bir olumsallık (contingency) tablosu kullanılır (ekrandan, 00:25:00). $A_{11}$ birinci aralıkta birinci sınıfa ait örnek sayısı, $A_{12}$ birinci aralıkta ikinci sınıfa ait örnek sayısı, $A_{21}$ ikinci aralıkta birinci sınıfa ait örnek sayısı, $A_{22}$ ise ikinci aralıkta ikinci sınıfa ait örnek sayısıdır.

| | Sınıf 1 | Sınıf 2 | $\Sigma$ |
|---|---|---|---|
| Aralık 1 | $A_{11}$ | $A_{12}$ | $R_1$ |
| Aralık 2 | $A_{21}$ | $A_{22}$ | $R_2$ |
| $\Sigma$ | $C_1$ | $C_2$ | $N$ |

- $R_i$: $i$. aralıktaki toplam örnek sayısı (satır toplamı).
- $C_j$: $j$. sınıftaki toplam örnek sayısı (sütun toplamı).
- $N$: iki aralıktaki toplam örnek sayısı.

Beklenen frekans (expected frequency) ve test istatistiği şöyledir:

$$E_{ij} = \frac{R_i \cdot C_j}{N}, \qquad \chi^2 = \sum_{i=1}^{2}\sum_{j=1}^{k} \frac{(A_{ij} - E_{ij})^2}{E_{ij}}$$

Buradaki $i$ indisi aralık sayısını (2), $j$ indisi sınıf sayısını ($k$) dolaşır.

> **Ders sonrası not:** Slayttaki formülde pay $(A_{ij} - E_{ij})$ olarak, kare işareti olmadan yazılmış (ekrandan, 00:45:00). Hoca derste bunu fark edip kare eklenmesi gerektiğini söyledi; doğru formül yukarıdaki gibidir. Slayttaki sayısal hesaplar da kareli formülle yapılmıştır.

## 4. ChiMerge Örneği

### 4.1 Veri ve sezgisel ayrıklaştırma

Ekrandaki örnekte sıralanmış sürekli bir $F$ öz niteliği ve buna karşılık gelen $K$ sınıfları vardır; 12 örnek bulunur (ekrandan, 00:30:00):

| Örnek | F | Sınıf (K) |
|---|---|---|
| 1 | 1 | 1 |
| 2 | 3 | 2 |
| 3 | 7 | 1 |
| 4 | 8 | 1 |
| 5 | 9 | 1 |
| 6 | 11 | 2 |
| 7 | 23 | 2 |
| 8 | 37 | 1 |
| 9 | 39 | 2 |
| 10 | 45 | 1 |
| 11 | 46 | 1 |
| 12 | 59 | 1 |

Hoca algoritmaya geçmeden önce bu öz niteliği elle nasıl ayrıklaştırabileceğimizi sorar. 1 ile 9 arasındaki beş örneğin dördü sınıf 1'dendir; tek bir sınıf 2 örneği göz ardı edilirse bu bölge bir aralık olabilir. Bir öğrenci sonraki aralığın 10'dan 40'a kadar olabileceğini söyler: bu bölgedeki dört örneğin çoğu sınıf 2'dendir. Sonraki aralık da 40'tan 60'a kadar olabilir. ChiMerge bu sezgiyi otomatik ve istatistiksel olarak yapar.

### 4.2 Başlangıç aralıkları

Hoca tahtada her ardışık değer çiftinin orta noktasını aralık sınırı olarak işaretler; ilk sınır 0'dır (ekrandan, 00:40:00). Örneğin 1 ile 3'ün orta noktası 2, 3 ile 7'nin orta noktası 5'tir. Bulunan sınırlar:

$$0,\ 2,\ 5,\ 7.5,\ 8.5,\ 10,\ 17,\ 30,\ 38,\ 42,\ 45.5,\ 52.5,\ 60$$

Böylece her değer kendi başlangıç aralığındadır. Bundan sonra bütün komşu aralıklara $\chi^2$ testi uygulanır; derste örnek olarak bir çift seçilip ayrıntılı çözülür.

### 4.3 Birinci hesap: [7.5, 8.5] ve [8.5, 10]

[7.5, 8.5] aralığında yalnız 8 değeri (sınıf 1), [8.5, 10] aralığında yalnız 9 değeri (sınıf 1) vardır. Sınıf etiketlerine bakınca bu iki aralığın birleştirilebileceği zaten görülür; test bunu doğrular. Tablo (ekrandan, 00:45:00):

| | K=1 | K=2 | $\Sigma$ |
|---|---|---|---|
| [7.5, 8.5] | $A_{11}=1$ | $A_{12}=0$ | $R_1=1$ |
| [8.5, 10] | $A_{21}=1$ | $A_{22}=0$ | $R_2=1$ |
| $\Sigma$ | $C_1=2$ | $C_2=0$ | $N=2$ |

Beklenen frekanslar hocanın öğrencilere sorarak birlikte hesapladığı gibi:

- $E_{11} = R_1 C_1 / N = 1 \cdot 2 / 2 = 1$
- $E_{12} = R_1 C_2 / N = 1 \cdot 0 / 2 = 0$
- $E_{21} = R_2 C_1 / N = 1 \cdot 2 / 2 = 1$
- $E_{22} = R_2 C_2 / N = 1 \cdot 0 / 2 = 0$

$E_{12}$ ve $E_{22}$ sıfır çıktığı için $\chi^2$ formülünde sıfıra bölme oluşur. Hoca aradan sonra bu noktaya özellikle dikkat çeker: çözümde sıfır çıkan beklenen frekanslar yerine sıfıra yakın küçük bir sayı, burada $0.1$, kullanılır ($0.01$ de alınabilir). Böylece terim sonsuza gitmez. Slayttaki hesap (ekrandan, 00:45:00):

$$\chi^2 = \frac{(1-1)^2}{1} + \frac{(0-0.1)^2}{0.1} + \frac{(1-1)^2}{1} + \frac{(0-0.1)^2}{0.1} = 0 + 0.1 + 0 + 0.1 = 0.2$$

Serbestlik derecesi $d = 1$ için eşik $2.706$'dır. $0.2 < 2.706$ olduğundan sınıf frekansları arasında anlamlı bir fark yoktur; aralıklar birleştirilir ve yeni aralık [7.5, 10] olur.

> **Hocanın vurgusu:** Bu sıfıra bölme durumunu kimsenin sormadığını, sınıfta olsaydı en az üç kişinin soracağını söyledi. $E_{ij} = 0$ durumunu ve $0.1$ ile çözümünü bilmek gerekir.

### 4.4 Eşik nasıl seçilir?

Bir öğrenci eşiğin neye göre seçildiğini sorar.

**Soru:** Eşiği neye göre seçiyoruz?
**Cevap:** Eşik, ki-kare dağılım tablosundan serbestlik derecesine göre seçilir; burada $d = 1$ için $2.706$ alınmıştır. Ancak eşik esnektir: işlemler bittiğinde elde çok fazla aralık kalmışsa eşik büyütülebilir; böylece daha fazla birleştirme yapılır ve daha geniş aralıklar elde edilir.

Hoca amacın işlemleri arka arkaya uygulayarak daha geniş aralıklar elde etmek olduğunu, ama bu aralıkların sınıf etiketleriyle de uyumlu olması gerektiğini vurgular. Birleştirilen aralıktaki örnekler olabildiğince aynı sınıftan olursa daha iyi bir aralık seçilmiş olur. Bu önemlidir, çünkü elde edilen aralıklar daha sonra sınıflandırmada kullanılacaktır.

### 4.5 İterasyon kuralı

Slayta göre (00:58:02 anlatımı) birleştirme işlemi bir iterasyonda yalnız en küçük $\chi^2$ değerine sahip iki komşu aralığa uygulanır; birleştirme için bu değerin eşikten küçük olması gerekir. Süreç, en küçük $\chi^2$ değerine sahip sonraki komşu aralıklarla devam eder.

**Soru:** Aralıkları birleştirmek için baştan itibaren hep ardışık olanları mı kontrol ediyoruz?
**Cevap:** Evet, test yalnız birbirine komşu aralıklar için yapılır. Her iterasyonda bütün komşu aralık çiftleri için test hesaplanır, en küçük değeri veren çift için tek bir birleştirme yapılır. Genişletilen aralığın üstündeki ve altındaki komşularla olan test sonuçları artık değiştiği için bir sonraki iterasyonda değerler yeniden hesaplanır ve birleştirme kararı yeniden verilir.

### 4.6 İkinci hesap: [0, 7.5] ve [7.5, 10]

İşlemler bir süre uygulandıktan sonra [0, 7.5] ve [7.5, 10] aralıkları oluşmuştur. [0, 7.5] aralığında üç örnek vardır (1, 3, 7): ikisi sınıf 1, biri sınıf 2. [7.5, 10] aralığında iki örnek vardır (8, 9), ikisi de sınıf 1.

| | K=1 | K=2 | $\Sigma$ |
|---|---|---|---|
| [0, 7.5] | 2 | 1 | 3 |
| [7.5, 10] | 2 | 0 | 2 |
| $\Sigma$ | 4 | 1 | 5 |

Beklenen frekanslar (ara adım eklendi): $E_{11} = 3 \cdot 4/5 = 2.4$, $E_{12} = 3 \cdot 1/5 = 0.6$, $E_{21} = 2 \cdot 4/5 = 1.6$, $E_{22} = 2 \cdot 1/5 = 0.4$.

$$\chi^2 = \frac{(2-2.4)^2}{2.4} + \frac{(1-0.6)^2}{0.6} + \frac{(2-1.6)^2}{1.6} + \frac{(0-0.4)^2}{0.4} \approx 0.067 + 0.267 + 0.1 + 0.4 \approx 0.83$$

$0.83$ eşiğin altında kaldığı için seçilen aralıklar tek aralıkta birleştirilir ve [0, 10] oluşur.

<!-- BELİRSİZ: Bu hesabın slaytı karelerde yok; tablo değerleri altyazıdan (01:00:14-01:01:17) ve veri tablosundan kuruldu, sonuç 0.83 hocanın söylediği değerle ve python hesabıyla uyumlu. -->

### 4.7 Üçüncü hesap: [0, 10] ve [10, 42]

Ayrıklaştırma sürdürülünce üç aralık kalır: [0, 10], [10, 42] ve [42, 60]. Bu komşu aralıklara yeniden ChiMerge uygulanıp birleştirme yapılıp yapılamayacağı kontrol edilir. [0, 10] ve [10, 42] için tablo (ekrandan, 01:05:00):

| | K=1 | K=2 | $\Sigma$ |
|---|---|---|---|
| [0, 10] | $A_{11}=4$ | $A_{12}=1$ | $R_1=5$ |
| [10, 42] | $A_{21}=1$ | $A_{22}=3$ | $R_2=4$ |
| $\Sigma$ | $C_1=5$ | $C_2=4$ | $N=9$ |

Slaytta $N$ değeri boş bırakılmıştı; bir öğrenci sohbetten $N = 9$ cevabını verdi. Bir öğrencinin "2.78 nasıl bulundu?" sorusu üzerine hoca beklenen frekansı açar:

- $E_{11} = R_1 C_1 / N = 5 \cdot 5 / 9 \approx 2.78$
- $E_{12} = R_1 C_2 / N = 5 \cdot 4 / 9 \approx 2.22$
- $E_{21} = R_2 C_1 / N = 4 \cdot 5 / 9 \approx 2.22$
- $E_{22} = R_2 C_2 / N = 4 \cdot 4 / 9 \approx 1.78$

$$\chi^2 = \frac{(4-2.78)^2}{2.78} + \frac{(1-2.22)^2}{2.22} + \frac{(1-2.22)^2}{2.22} + \frac{(3-1.78)^2}{1.78} \approx 2.72$$

$2.72 > 2.706$ olduğundan iki aralık arasında anlamlı fark vardır ve birleştirme önerilmez (ekrandan, 01:05:00).

> **Ek bilgi (derste anlatılmadı):** İki aralık ve $k$ sınıf için ki-kare testinin serbestlik derecesi $(2-1)(k-1) = k-1$'dir; iki sınıfta bu $1$ eder. $d = 1$ için $2.706$ değeri, büyük olasılıkla $0.10$ anlamlılık düzeyine karşılık gelen kritik değerdir.

## 5. Sınıflandırmaya Giriş ve Bayes Teoremi

Değer indirgeme bittikten sonra sınıflandırma (classification) bölümüne geçilir. Derste üç sınıflandırma yöntemi işlenecektir: ilki basit Bayes ya da naive Bayes sınıflandırma, sonra karar ağaçları (decision trees) ve k-en yakın komşu (k-nearest neighbor) sınıflandırma.

Bayes sınıflandırma Bayes teoremini kullanır. Ekrandaki tanımlar (ekrandan, 01:30:00):

- $X$, sınıf etiketi bilinmeyen bir veri örneğidir. Sınıfı bilinmediği için ona test örneği (test sample) denir.
- $H$, "$X$ veri örneği belirli bir $C$ sınıfına aittir" biçiminde bir hipotezdir.
- Amaç $P(H \mid X)$'i, yani gözlenen $X$ verildiğinde $H$ hipotezinin doğru olma olasılığını bulmaktır.
- $P(H \mid X)$ sonsal (posterior) olasılıktır; $X$ verildikten sonra hipoteze duyulan güveni gösterir.

Her sınıf için hipotez olasılıkları hesaplanır, karşılaştırılır ve en büyük olasılığı veren sınıf etiket olarak seçilir. Bayes teoremi bu koşullu olasılığı şöyle yazar:

$$P(H \mid X) = \frac{P(X \mid H)\, P(H)}{P(X)}$$

## 6. Naive Bayes Sınıflandırıcı

Veri madenciliği diliyle: $S$ eğitim kümesinde $s_1, s_2, \dots, s_m$ olmak üzere $m$ örnek vardır. Her örnek, öz niteliklerden oluşan $n$ boyutlu bir vektördür. $C_1, C_2, \dots, C_k$ olmak üzere $k$ farklı sınıf vardır. Sınıfı bilinmeyen ek bir $X$ örneği (test örneği) verildiğinde her $C_i$ için $P(C_i \mid X)$ hesaplanır; en büyük olasılığı veren sınıf test örneğinin etiketi olur.

Ekrandaki slayta göre (ekrandan, 01:35:00):

$$P(C_i \mid X) = \frac{P(X \mid C_i)\, P(C_i)}{P(X)}$$

- $P(X)$ bütün sınıflar için sabittir; bu yüzden yalnız $P(X \mid C_i) \cdot P(C_i)$ çarpımının en büyüklenmesi gerekir.
- Sınıfların önsel (prior) olasılıkları $P(C_i) = (\text{$C_i$ sınıfındaki eğitim örneği sayısı}) / m$ ile hesaplanır.

Bu olasılıklar eğitim verisinden bulunur. $P(X \mid C_i)$ koşullu olasılığı, öz nitelikler koşullu bağımsız (conditionally independent) kabul edilirse her öz niteliğin olasılıklarının çarpımı olarak yazılabilir:

$$P(X \mid C_i) = \prod_{t=1}^{n} P(x_t \mid C_i)$$

<!-- BELİRSİZ: 01:34:04-01:36:35 arasında altyazı tekrar halüsinasyonu içeriyor; koşullu bağımsızlık slaytının ayrıntısı okunamadı, formül hocanın 01:35:22 ve tahtadaki çarpım yazımından (ekrandan, 01:50:00) kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** "Naive" (saf) sözcüğü, gerçekte çoğu zaman doğru olmayan bu koşullu bağımsızlık varsayımından gelir. Varsayım sayesinde çok boyutlu bir ortak olasılık yerine her öz nitelik için ayrı ayrı sayım yapmak yeterli olur; bu da yöntemi az veriyle bile hızlı ve uygulanabilir kılar.

## 7. Kategorik Öz Nitelikli Örnek: Kredi Kartı Promosyonları

### 7.1 Veri ve test örneği

Eğitim verisinde kredi kartı kullanıcılarına yapılan promosyonlar vardır. Dört öz nitelik bulunur: dergi promosyonu (magazine promotion), saat promosyonu (watch promotion), hayat sigortası promosyonu (life insurance promotion) ve kredi kartı sigortası (credit card insurance). 10 örnek vardır ve sınıf etiketi kart kullanıcısının cinsiyetidir.

<!-- BELİRSİZ: Eğitim veri tablosu hiçbir karede görünmüyor (01:36-01:46 arası kare yok); tablo satırları nota alınamadı, sayımlar altyazıdan ve tahtadaki sonuçlardan kuruldu. -->

Hoca tahtada öz nitelikleri kısaltır: $F_1$ dergi promosyonu, $F_2$ saat promosyonu, $F_3$ hayat sigortası promosyonu, $F_4$ kredi kartı sigortası. Test örneği:

$$X = (F_1 = \text{evet},\ F_2 = \text{evet},\ F_3 = \text{hayır},\ F_4 = \text{hayır})$$

### 7.2 Bayes teoremini yazmak

İki sınıf için sonsal olasılıklar tahtada şöyle yazılır (ekrandan, 01:45:00):

$$P(\text{erkek} \mid X) = \frac{P(X \mid \text{erkek})\, P(\text{erkek})}{P(X)}, \qquad P(\text{kadın} \mid X) = \frac{P(X \mid \text{kadın})\, P(\text{kadın})}{P(X)}$$

Önsel olasılıklar eğitim verisinden sayılır: 10 kullanıcının 6'sı erkek, 4'ü kadındır. $P(\text{erkek}) = 6/10$, $P(\text{kadın}) = 4/10$ (ekrandan, 02:00:00).

### 7.3 Erkek sınıfı için $P(X \mid \text{erkek})$

Koşullu bağımsızlık varsayımıyla (ekrandan, 01:50:00):

$$P(X \mid \text{erkek}) = \prod_{i=1}^{4} P(x_i \mid \text{erkek}) = P(F_1=\text{evet} \mid \text{e}) \cdot P(F_2=\text{evet} \mid \text{e}) \cdot P(F_3=\text{hayır} \mid \text{e}) \cdot P(F_4=\text{hayır} \mid \text{e})$$

Altı erkek kart kullanıcısı arasında sayım yapılır:

- Dergi promosyonuna evet diyenler: 4, yani $4/6$.
- Saat promosyonuna evet diyenler: 2, yani $2/6$.
- Hayat sigortası promosyonuna hayır diyenler: 4, yani $4/6$.
- Kredi kartı sigortasına hayır diyenler: 4, yani $4/6$.

$$P(X \mid \text{erkek}) = \frac{4}{6}\cdot\frac{2}{6}\cdot\frac{4}{6}\cdot\frac{4}{6} = \frac{128}{1296} = \frac{8}{81}$$

### 7.4 Kadın sınıfı için $P(X \mid \text{kadın})$

Aynı işlem dört kadın kart kullanıcısı için yapılır. Hoca burada test örneğinin değerlerini hatırlatır: ilk iki öz nitelik "evet", son ikisi "hayır" olduğu için olasılıklar bu değerlere göre sayılır.

- Dergi promosyonuna evet diyenler: 3, yani $3/4$.
- Saat promosyonuna evet diyenler: 2, yani $2/4$.
- Hayat sigortası promosyonuna hayır diyenler: 1, yani $1/4$.
- Kredi kartı sigortasına hayır diyenler: 3, yani $3/4$ (ara adım eklendi; bu sayı altyazıda duyulmuyor, tahtadaki $9/128$ sonucundan çıkarıldı).

$$P(X \mid \text{kadın}) = \frac{3}{4}\cdot\frac{2}{4}\cdot\frac{1}{4}\cdot\frac{3}{4} = \frac{18}{256} = \frac{9}{128}$$

### 7.5 Karşılaştırma

Paylar hesaplanır (ara adım eklendi):

- Erkek: $\dfrac{8}{81}\cdot\dfrac{6}{10} \approx 0.0593$
- Kadın: $\dfrac{9}{128}\cdot\dfrac{4}{10} \approx 0.0281$

Erkek sınıfının değeri daha büyük olduğu için test örneği $X$ büyük olasılıkla erkek bir kart kullanıcısıdır.

> **Ders sonrası not:** Altyazıda erkek sınıfı için değer "0.0591" gibi duyuluyor; $\frac{8}{81}\cdot\frac{6}{10} = 0.05926$ olduğundan doğrusu yaklaşık $0.0593$'tür. Sonuç (erkek) değişmez.

### 7.6 $P(X)$ neden hesaplanmadı?

Hoca, payda olan $P(X)$'in aslında hesaplanabileceğini, ama işlemi sadeleştirmek için hesaplanmadığını belirtir; $P(X)$, test örneğinin bu davranışının (öz nitelik değerleri birleşiminin) olasılığıdır.

**Soru:** Erkek ve kadın olma olasılıklarının toplamı neden 1 değil?
**Cevap:** $P(X)$'e bölmediğimiz için. İşlemin $P(X)$'e bölme kısmı yapılmaz, çünkü amaç yalnız karşılaştırmadır; $P(X)$ iki sınıf için de aynıdır.

> **Ek bilgi (derste anlatılmadı):** Gerçek sonsal olasılıklar istenirse $P(X)$, iki payın toplamı alınarak bulunabilir: $P(X) = 0.0593 + 0.0281 \approx 0.0874$. Bu durumda $P(\text{erkek} \mid X) \approx 0.68$ ve $P(\text{kadın} \mid X) \approx 0.32$ olur ve toplam 1 eder.

Hoca örnekteki bütün öz niteliklerin kategorik olduğunu ve olasılıkların sayılarak bulunduğunu hatırlatır; öz nitelik sayısal olsaydı ne yapılacağı sorusunu sonraki örneğe bırakır.

## 8. Sayısal Öz Nitelik ve Laplace Düzeltmesi: Araç Sigortası Örneği

Hoca bu örneğin slaytlarda bulunmadığını, yalnız tahtada çözüleceğini belirtir ve not alınmasını ister.

### 8.1 Veri

Araç sigortası (car insurance) veri setinde iki öz nitelik vardır: yaş (sayısal) ve araç tipi (kategorik). Sınıf etiketi düşük risk (L) ya da yüksek risktir (H). Altı eğitim örneği tahtada şöyledir (ekrandan, 02:25:00):

| Yaş | Araç tipi | Risk |
|---|---|---|
| 25 | spor (sports) | L |
| 20 | klasik (vintage) | H |
| 25 | spor (sports) | L |
| 45 | SUV | H |
| 20 | spor (sports) | H |
| 25 | SUV | H |

Test örneği: $X = (\text{yaş} = 23,\ \text{araç} = \text{kamyon (truck)})$. Soru: test örneği yüksek risk mi, düşük risk mi?

### 8.2 Bayes teoremini yazmak

$$P(H \mid X) = \frac{P(H)\, P(X \mid H)}{P(X)}, \qquad P(L \mid X) = \frac{P(L)\, P(X \mid L)}{P(X)}$$

Altı örneğin 4'ü yüksek, 2'si düşük risktir. Bir öğrencinin sohbetten verdiği cevapla: $P(H) = 4/6$, $P(L) = 2/6$.

### 8.3 Sayısal öz nitelik: Gauss dağılımı

Sayısal öz niteliklerde olasılık sayarak bulunamaz. Her sınıf için öz niteliğin sınıf ortalaması ve standart sapması hesaplanır ve sınıf normal (Gauss) dağılımla temsil edilir (ekrandan, 02:35:00):

- Yüksek risk sınıfında yaşlar 20, 45, 20, 25'tir: $m_H = 27.5$, $s_H = 10.31$.
- Düşük risk sınıfında yaşlar 25, 25'tir: $m_L = 25$, $s_L = 0$.

> **Ders sonrası not:** $s_H = 10.31$, $n$'ye bölünen (popülasyon) standart sapmadır: $\sqrt{(7.5^2 + 17.5^2 + 7.5^2 + 2.5^2)/4} = \sqrt{106.25} \approx 10.31$. $n-1$'e bölünürse $11.90$ çıkar; derste $10.31$ kullanıldı.

Hoca düşük risk sınıfının standart sapmasının sıfır çıkmasının iyi bir örnek olmadığını, gerçek dünya problemlerinde standart sapmanın sıfır çıkmasının beklenmediğini belirtir.

Gauss yoğunluk fonksiyonu (ekrandan, 02:40:00):

$$g(x) = \frac{1}{\sqrt{2\pi}\, s}\, e^{-\frac{(x-m)^2}{2s^2}}$$

Tahtadaki çizimde yüksek risk sınıfının dağılımı 27.5'te tepe yapan bir çan eğrisidir; 23 değerinin bu eğri üzerindeki yüksekliği aranan olasılıktır.

Yüksek risk sınıfı için:

$$P(\text{yaş}=23 \mid H) = \frac{1}{\sqrt{2\pi}\cdot 10.31}\, e^{-\frac{(23-27.5)^2}{2\cdot 10.31^2}} \approx 0.0387 \cdot e^{-0.0953} \approx 0.035$$

Düşük risk sınıfında standart sapma sıfır olduğu için Gauss dağılımı 25'te bir dürtüye (impulse) dönüşür; 23 yaşının bu sınıftaki olasılığı $0$'dır.

### 8.4 Kategorik öz nitelik: Laplace düzeltmesi

Test örneğinin araç tipi "kamyon"dur, ama eğitim verisinde hiç kamyon yoktur. Öz nitelik var, ama bu değer yeni bir değerdir. Bu durumda olasılık sıfır çıkıp bütün çarpımı sıfırlamasın diye basit bir düzeltme yapılır: Laplace düzeltmesi (Laplace adjustment). Her sayıma 1 eklenir (ekrandan, 02:50:00).

| Araç tipi | Yüksek | Düşük |
|---|---|---|
| spor | $1+1=2$ | $2+1=3$ |
| klasik | $1+1=2$ | $0+1=1$ |
| SUV | $2+1=3$ | $0+1=1$ |
| kamyon | $0+1=1$ | $0+1=1$ |
| Toplam | 8 | 6 |

Düzeltilmiş sayımlarla olasılıklar:

- $P(\text{kamyon} \mid H) = 1/8$
- $P(\text{spor} \mid H) = 2/8$
- $P(\text{kamyon} \mid L) = 1/6$
- $P(\text{SUV} \mid L) = 1/6$

Hesapta yalnız $P(\text{kamyon} \mid H)$ ve $P(\text{kamyon} \mid L)$ kullanılır; diğerleri alıştırma olarak sorulmuştur.

### 8.5 Sonuç

$$P(X \mid H) = P(\text{yaş}=23 \mid H)\cdot P(\text{kamyon} \mid H) = 0.035 \cdot \frac{1}{8} \approx 0.0044$$

$$P(H)\, P(X \mid H) = \frac{4}{6} \cdot 0.0044 \approx 0.003$$

$$P(X \mid L) = 0 \cdot \frac{1}{6} = 0 \quad\Rightarrow\quad P(L)\, P(X \mid L) = 0$$

Yüksek risk sınıfının değeri daha büyük olduğu için test örneği (23, kamyon) yüksek risk sınıfındadır (ekrandan, 02:55:00).

Hoca ilk aşamada $P(X \mid H)$ sonucunu son sonuç gibi okumuştu; bir öğrenci $4/6$ ile çarpılması gerektiğini hatırlattı ve hoca sonucu $0.003$ olarak düzeltti. Python ile kontrol: $0.035185 \cdot \frac{1}{8} \cdot \frac{4}{6} \approx 0.00293$.

> **Hocanın vurgusu:** Bu hesaplamalarda hassasiyet yüksek tutulmalıdır. Normal dağılımdan bulunan olasılık değeri oldukça küçük çıkar; virgülden sonra dört ya da beş basamak (on binde bir hassasiyet) kullanılmalı, ara işlemlerde fazla yuvarlama yapılmamalı, yalnız nihai sonuç biraz yuvarlanmalıdır.

### 8.6 Standart sapma iki sınıfta da sıfır olsaydı?

**Soru:** Standart sapma öbür sınıfta da sıfır olsaydı iki olasılık da sıfır olurdu; o zaman ne yapardık?
**Cevap:** Bu, gerçekte görülmeyecek bir durumdur. Örnek küçük tutulduğu için, yani düşük risk sınıfı yalnız iki örnekten oluştuğu için standart sapma sıfır çıktı; bu, sınıftaki örnek sayısının azlığından kaynaklanır. Gerçek hayatta böyle bir durumla karşılaşılması beklenmez; bunu düzeltmek için bir çözüm önerilmemiştir. İki sınıfta da sıfır olduğu bir durumla hiç karşılaşılmaz; öyle bir şey varsa o öz nitelik atılmalıdır, çünkü hiçbir ayırt ediciliği yok demektir.

> **Ek bilgi (derste anlatılmadı):** Uygulamada sıfır varyans sorununa karşı genellikle varyansa çok küçük bir sabit eklenir (varyans düzeltmesi). Laplace düzeltmesi de kategorik öz nitelikler için aynı amaca, yani tek bir sıfır olasılığın bütün çarpımı sıfırlamasını önlemeye hizmet eder.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:30:22): Sıralı 12 örnekli veride (bölüm 4.1'deki tablo) öz nitelik elle ayrıklaştırılmak istense, 1-9 aralığından sonraki aralık 10'dan hangi değere kadar seçilebilir?

> **Çözüm (derste verildi):** Bir öğrenci 40 dedi. 10-40 arasındaki dört örneğin (11, 23, 37, 39) çoğu sınıf 2'dendir; bu bir aralık olabilir. Sonraki aralık 40-60 olabilir.

**Soru 2** (ekrandan, 00:45:00): [7.5, 8.5] ve [8.5, 10] aralıkları için olumsallık tablosu $A_{11}=1$, $A_{12}=0$, $A_{21}=1$, $A_{22}=0$ ise $E_{11}$, $E_{12}$, $E_{21}$, $E_{22}$ nedir? $\chi^2$ kaçtır ve aralıklar birleştirilir mi?

> **Çözüm (derste verildi):** $E_{11} = 1$, $E_{12} = 0$, $E_{21} = 1$, $E_{22} = 0$. Sıfır olan beklenen frekanslar $0.1$ alınır. $\chi^2 = 0.2 < 2.706$; aralıklar birleştirilir, yeni aralık [7.5, 10].

**Soru 3** (ekrandan, 01:05:00): [0, 10] ve [10, 42] aralıkları için $A_{11}=4$, $A_{12}=1$, $A_{21}=1$, $A_{22}=3$ ise $N$ ve $\chi^2$ nedir?

> **Çözüm (derste verildi):** $N = 9$; $E = 2.78, 2.22, 2.22, 1.78$; $\chi^2 \approx 2.72 > 2.706$; birleştirme önerilmez.

**Soru 4** (derste sözlü, 01:44:44): Kredi kartı veri setinde 10 kart kullanıcısından kaçı erkektir; $P(\text{erkek})$ ve $P(\text{kadın})$ nedir?

> **Çözüm (derste verildi):** 6 erkek, 4 kadın; $P(\text{erkek}) = 6/10$, $P(\text{kadın}) = 4/10$.

**Soru 5** (derste sözlü, 01:49:51 ve 01:56:20): Test örneği (evet, evet, hayır, hayır) için erkek ve kadın sınıflarında her öz niteliğin koşullu olasılığı nedir?

> **Çözüm (derste verildi):** Erkek: $4/6$, $2/6$, $4/6$, $4/6$, çarpım $8/81$. Kadın: $3/4$, $2/4$, $1/4$, $3/4$, çarpım $9/128$. Test örneği erkek sınıfına atanır.

**Soru 6** (derste sözlü, 02:27:51): Araç sigortası verisinde $P(\text{yüksek})$ nedir?

> **Çözüm (derste verildi):** 6 örneğin 4'ü yüksek risk: $4/6$. Düşük risk için $2/6$.

**Soru 7** (ekrandan, 02:50:00): Laplace düzeltmesinden sonra $P(\text{kamyon} \mid H)$, $P(\text{spor} \mid H)$, $P(\text{kamyon} \mid L)$ ve $P(\text{SUV} \mid L)$ nedir?

> **Çözüm (derste verildi):** $1/8$, $2/8$, $1/6$, $1/6$.

**Soru 8** (ekrandan, 02:55:00): Test örneği (yaş = 23, araç = kamyon) hangi risk sınıfındadır?

> **Çözüm (derste verildi):** Yüksek risk için $\frac{4}{6}\cdot 0.035 \cdot \frac{1}{8} \approx 0.003$, düşük risk için $0$; test örneği yüksek risk sınıfındadır.

## Dersin Toparlaması

Dersin ilk bölümünde veri indirgemenin değer indirgeme boyutu tamamlandı. Sürekli bir öz niteliğin az sayıda aralığa bölünmesi için elle ayrıklaştırma ile otomatik ChiMerge tekniği karşılaştırıldı. ChiMerge'de değerler sıralanıp her değer ayrı bir aralığa konur; komşu aralıklar için olumsallık tablosu kurulur, beklenen frekanslar $E_{ij} = R_i C_j / N$ ile hesaplanır ve $\chi^2$ istatistiği eşikle karşılaştırılır. Her iterasyonda en küçük $\chi^2$ değerine sahip çift, eşiğin altındaysa birleştirilir; sıfır beklenen frekanslar küçük bir sayıyla değiştirilir.

İkinci bölümde sınıflandırmaya giriş yapıldı ve ilk yöntem olarak naive Bayes sınıflandırıcı işlendi. Bayes teoremi ve koşullu bağımsızlık varsayımıyla her sınıf için $P(X \mid C_i)\,P(C_i)$ hesaplanıp en büyüğü seçilir. Kategorik öz niteliklerde olasılıklar sayılarak, sayısal öz niteliklerde sınıf ortalaması ve standart sapmasıyla Gauss dağılımından bulunur; eğitimde görülmeyen kategorik değerler için Laplace düzeltmesi uygulanır. Sonraki derslerde karar ağaçları ve k-en yakın komşu sınıflandırma işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
