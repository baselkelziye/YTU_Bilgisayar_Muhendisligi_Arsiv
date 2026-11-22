# Ders 3 Genişletilmiş Notu: Aksiyomatik Olasılık, Koşullu Olasılık, Bayes Teoremi ve Kesikli Rastgele Değişkenler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki derslerin tekrarı ve dersin planı
- 2. Olasılığın aksiyomatik tanımı
- 3. Temel olasılık kuralları ve içerme-dışarma
- 4. Olasılık eşitsizlikleri
- 5. Bağımsız olaylar
- 6. Koşullu olasılık
- 7. Kesişimin olasılığı ve iki para örneği
- 8. Toplam olasılık yasası
- 9. Bayes kuralı ve Bayes teoremi
- 10. Rastgele değişken
- 11. Kesikli rastgele değişken ve dağılımı
- 12. Olasılık kütle fonksiyonu (PMF)
- 13. Birikimli dağılım fonksiyonu (CDF)
- Örnek Sorular

## 1. Önceki derslerin tekrarı ve dersin planı

Ders iPad üzerinde, "BLM2011 Lecture Notes (2020 Fall)" başlıklı bir not defterine el yazısıyla yürütüldü. Anlatım büyük ölçüde İngilizce, yer yer Türkçe açıklamalarla yapıldı.

Hoca, önceki derste doğrudan koşullu olasılığa geçtiğini, oysa önce olasılığın aksiyomatik kurallarının anlatılması gerektiğini söyledi. Bu yüzden konu sırası düzeltildi: bu derste önce aksiyomatik olasılık işlenip ardından koşullu olasılığa dönüldü.

Önceki derslerde görülenler kısaca hatırlatıldı: örnek uzay, olaylar ve olasılık; olaylar üzerinde birleşim, kesişim ve fark işlemleri; deney sayısı sonsuza giderken göreli frekansla olasılık bulma; eşit olasılıklı sonuçlar; yerine koymalı ve yerine koymasız kombinasyonlar.

## 2. Olasılığın aksiyomatik tanımı

### 2.1 Tanım

Olasılık, örnek uzay $\Omega$ üzerinde tanımlanan bir fonksiyondur. Bu fonksiyon her olaya, yani $\Omega$'nın kuvvet kümesi $\mathcal{P}(\Omega)$'nın her elemanı $A$'ya, bir sayı atar. Bu sayıya $A$ olayının olasılığı denir ve $\Pr(A)$ diye yazılır. Atamanın aşağıdaki koşulları (aksiyomları) sağlaması gerekir (ekrandan, 00:10:00):

- $\Pr(A) \ge 0$, her $A \in \mathcal{P}(\Omega)$ için.
- $\Pr(\Omega) = 1$.
- $A \cap B = \emptyset$ ise $\Pr(A \cup B) = \Pr(A) + \Pr(B)$, burada $A, B \in \mathcal{P}(\Omega)$.

Hoca "fulfilled" kelimesinin "sağlanmak" (provided / supported) anlamına geldiğini de belirtti.

### 2.2 Fonksiyon olarak olasılık

Hoca fonksiyon kavramını hatırlattı: bir $A$ kümesinin elemanlarını bir $B$ kümesinin elemanlarına eşleyen bağıntı fonksiyondur. $A$ kümesine tanım kümesi (domain), eşlenen değerlerin kümesine değer kümesi (range) denir. Gösterimler:

- $\mathbb{R} = (-\infty, +\infty)$: tüm reel sayılar.
- $\mathbb{R}_+$: pozitif reel sayılar.
- Hoca $[0,1]$ aralığını $\mathbb{R}_+^1 \equiv [0,1]$ diye gösterdi (ekrandan, 00:15:00).

Bu gösterimle olasılık bir fonksiyondur: $\Pr: \mathcal{P}(\Omega) \to \mathbb{R}_+^1$. Bu fonksiyona **olasılık ölçüsü** (probability measure) denir (ekrandan, 00:15:00).

### 2.3 Olasılık uzayı

Örnek uzay ile olasılık ölçüsünden oluşan $(\Omega, \Pr)$ ikilisine **olasılık uzayı** (probability space) denir. Hoca bu kavramın, ileride kuantum hesaplama üzerinde çalışmak, kuantum algoritmaları tasarlamak ya da kuantum mekaniğine dayalı programlar yazmak isteyenler için gerekli olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Ölçü kuramına dayanan standart tanımda olasılık uzayı genellikle üçlü olarak, $(\Omega, \mathcal{F}, \Pr)$ biçiminde yazılır; $\mathcal{F}$ olay kümeleri ailesidir (σ-cebir). Sonlu örnek uzaylarda $\mathcal{F}$ olarak kuvvet kümesi alınabildiği için derste ikili gösterim kullanıldı. Ayrıca üçüncü aksiyom ders kitaplarında çoğu zaman sayılabilir sonsuz sayıda ayrık olay için yazılır.

## 3. Temel olasılık kuralları ve içerme-dışarma

### 3.1 İmkânsız olay ve temel olaylar

Aksiyomlardan şu kurallar çıkar (ekrandan, 00:20:00):

- $\Pr(\emptyset) = 0$. İmkânsız olayın gerçekleşme olasılığı yoktur.
- $A = \{\omega_1, \omega_2, \dots, \omega_k\}$ ve $\omega_i$'ler sonuçlar (outcomes) ise
  $$\Pr(A) = \sum_{i=1}^{k} \Pr(\{\omega_i\}).$$
  Burada $\{\omega_i\}$, $i$'inci temel olaydır (elementary event). Temel olayların ikişer ayrık olduğu varsayılır: $i \ne j$ için $\{\omega_i\} \cap \{\omega_j\} = \emptyset$.

### 3.2 Tümleyen ve ayrık olayların birleşimi

$\bar{A}$, $A$ olayının gerçekleşmemesidir ve $\Pr(\bar{A}) = 1 - \Pr(A)$.

$A_1, A_2, \dots, A_n \in \mathcal{P}(\Omega)$ olayları için her $i \ne j$ çiftinde $A_i \cap A_j = \emptyset$ ise (ikişer ayrık, mutually exclusive) üçüncü aksiyom tekrar tekrar uygulanarak
$$\Pr\left(\bigcup_{k=1}^{n} A_k\right) = \Pr(A_1) + \Pr(A_2) + \dots + \Pr(A_n) = \sum_{k=1}^{n} \Pr(A_k)$$
elde edilir (ekrandan, 00:25:00).

### 3.3 İki olayın birleşimi

Ayrık olmayan herhangi iki olay için (ekrandan, 00:25:00):
$$\Pr(A \cup B) = \Pr(A) + \Pr(B) - \Pr(A \cap B), \qquad A, B \in \mathcal{P}(\Omega).$$

### 3.4 Üç ve dört olaya genelleme

Hoca bu formülün $n$ olayın birleşimine genelleştirilebileceğini söyledi. $n = 3$ için:
$$\Pr(A \cup B \cup C) = \Pr(A) + \Pr(B) + \Pr(C) - \Pr(A \cap B) - \Pr(A \cap C) - \Pr(B \cap C) + \Pr(A \cap B \cap C).$$

**Soru:** Bir öğrenci, son terimin birleşim olarak yazıldığını, kesişim olması gerekip gerekmediğini sordu. **Cevap:** Hoca haklı olduğunu söyleyip son terimi $\Pr(A \cap B \cap C)$ olarak düzeltti.

$n = 4$ için hoca formülü ezbere yazdı:
$$\begin{aligned}
\Pr(A \cup B \cup C \cup D) ={}& \Pr(A) + \Pr(B) + \Pr(C) + \Pr(D) \\
&- \Pr(A \cap B) - \Pr(A \cap C) - \Pr(A \cap D) - \Pr(B \cap C) - \Pr(B \cap D) - \Pr(C \cap D) \\
&+ \Pr(A \cap B \cap C) + \Pr(A \cap B \cap D) + \Pr(A \cap C \cap D) + \Pr(B \cap C \cap D) \\
&- \Pr(A \cap B \cap C \cap D).
\end{aligned}$$

> **Ders sonrası not:** Altyazıda üçlü kesişimler sayılırken yalnız $A \cap B \cap C$, $A \cap B \cap D$ ve $B \cap C \cap D$ okunuyor (sözlü bir atlama ya da altyazı eksikliği olabilir); dört olaydan seçilebilecek dört üçlü kesişim vardır, eksik terim $\Pr(A \cap C \cap D)$'dir. Yukarıdaki formül tam hâlidir.

Genel düşünce şudur: önce tekli olasılıklar toplanır, ikili kesişimler çıkarılır, üçlü kesişimler eklenir, dörtlü kesişim çıkarılır; işaret her seviyede değişir.

> **Hocanın vurgusu:** $n = 5$ için $\Pr(A \cup B \cup C \cup D \cup E)$ ifadesini yazmak çok iyi bir sınav sorusudur.

## 4. Olasılık eşitsizlikleri

Hoca bazı eşitsizlikleri tekrar etti (ekrandan, 00:30:00 ve 00:35:00):

- **Monotonluk:** $A \subset B$ ise $\Pr(A) \le \Pr(B)$.
- Herhangi $A_1, \dots, A_n$ için
  $$\Pr\left(\bigcup_{i=1}^{n} A_i\right) \le \sum_{i=1}^{n} \Pr(A_i).$$
  Her $i \ne j$ için $A_i \cap A_j = \emptyset$ ise eşitlik geçerlidir.
- Herhangi $A_1, \dots, A_n \in \mathcal{P}(\Omega)$ için, $n \in \mathbb{N}$:
  $$\Pr\left(\bigcap_{i=1}^{n} A_i\right) \ge 1 - \sum_{i=1}^{n} \Pr(\bar{A}_i).$$

> **Ek bilgi (derste anlatılmadı):** İkinci eşitsizlik literatürde Boole eşitsizliği (union bound), üçüncüsü Bonferroni eşitsizliği adıyla bilinir. Üçüncüsü, tümleyenlere Boole eşitsizliği ve De Morgan kuralı uygulanarak elde edilir.

## 5. Bağımsız olaylar

### 5.1 Tanım

$E_1, E_2, \dots, E_n$ olaylarından herhangi birinin gerçekleşmesi diğerlerinin olasılıklarını etkilemiyorsa bu olaylara **bağımsız** (independent) denir (ekrandan, 00:35:00). Yani birinci olayın gerçekleşmesi ikincinin gerçekleşmesine bağlı değildir; olaylar arasında bir bağımlılık yoktur.

$A_1, A_2, \dots, A_n$ bağımsızsa hepsinin birlikte gerçekleşme olasılığı tek tek olasılıkların çarpımıdır:
$$\Pr(A_1 \cap A_2 \cap \dots \cap A_n) = \Pr(A_1)\Pr(A_2)\cdots\Pr(A_n).$$

### 5.2 Para ve zar örneği

Bir para atılıyor ve bir zar atılıyor. Paranın H (head) gelmesi ile zarın 6 gelmesi birbirini etkilemez (ekrandan, 00:40:00):
$$\Pr(\text{para H gelir ve zar 6 gelir}) = \Pr(\text{para H}) \cdot \Pr(\text{zar 6}) = \frac{1}{2} \times \frac{1}{6} = \frac{1}{12}.$$

**Soru:** Olaylar bağımlı olsaydı oranı koşullu olasılıkla mı hesaplayacaktık? **Cevap:** Evet, bağımlı olsalardı işin içine koşullu olasılık girerdi. Hoca Türkçe bir örnek verdi: bir zar atıldığında tek sayı gelmesi ($\{1, 3, 5\}$) ile asal sayı gelmesi ($\{2, 3, 5\}$) arasında bağımlılık vardır, çünkü 3 ve 5 iki kümede de bulunur; asal sayı geldiğinde çoğu zaman tek sayı da gelmiş olur.

Sayısal kontrol (ara adım eklendi): $\Pr(\text{tek}) = \Pr(\text{asal}) = 3/6 = 1/2$, $\Pr(\text{tek} \cap \text{asal}) = \Pr(\{3, 5\}) = 2/6 = 1/3$. Çarpım $1/4$ olurdu; $1/3 \ne 1/4$ olduğu için olaylar gerçekten bağımlıdır.

### 5.3 Tümleyenlerle bağımsızlık

$A$ ve $B$ bağımsızsa $A$ ile $\bar{B}$ ve $\bar{A}$ ile $B$ de bağımsızdır. Hoca bunun çok kullanışlı bir sonuç olduğunu söyledi.

<!-- BELİRSİZ: 00:41:05 civarında altyazı yalnız "A and complement of B, A complement and B" kısımlarını veriyor; $\bar{A}$ ile $\bar{B}$ çiftinin de yazılıp yazılmadığı okunamadı. -->

## 6. Koşullu olasılık

### 6.1 Tanım

$B$ olayının gerçekleştiği bilindiğinde $A$ olayının gerçekleşme olasılığına, $A$'nın $B$ verildiğinde koşullu olasılığı denir (ekrandan, 00:45:00):
$$\Pr(A \mid B) = \frac{\Pr(A \cap B)}{\Pr(B)}, \qquad \Pr(B) \ne 0.$$

Bu yüzden $B$ imkânsız bir olay olamaz.

> **Ders sonrası not:** Hoca $\Pr(B) = 0$ olduğunda oranın sonsuza gideceğini söyledi. Doğrusu: $\Pr(B) = 0$ ise $A \cap B \subset B$ olduğundan $\Pr(A \cap B) = 0$ olur ve oran $0/0$ biçiminde tanımsızdır. Koşul bu yüzden konur.

### 6.2 Özellikler

Koşullu olasılığın özellikleri (ekrandan, 00:50:00):

- $0 \le \Pr(A \mid B) \le 1$.
- $\Pr(\Omega \mid B) = 1$, çünkü $B \subset \Omega$. $B$ gerçekleştiyse örnek uzay da gerçekleşmiştir.
- $A_1$ ve $A_2$ bağdaşmaz (incompatible, mutually exclusive) ise
  $$\Pr(A_1 \cup A_2 \mid B) = \Pr(A_1 \mid B) + \Pr(A_2 \mid B).$$
- $A$ ve $B$ bağımsızsa
  $$\Pr(A \mid B) = \Pr(A), \qquad \Pr(B \mid A) = \Pr(B).$$
  $B$ olayının gerçekleşmesi $A$'nın gerçekleşmesine bağlı değildir (ve tersi).

**Soru (hoca sordu):** "Incompatible" ne demektir? **Cevap:** Bir öğrenci "birbirine uygun olmayan" dedi; hoca bunun diğer adının "mutually exclusive" (ayrık) olduğunu belirtti.

## 7. Kesişimin olasılığı ve iki para örneği

### 7.1 Çarpma kuralı

$\Pr(A_1 \cap A_2 \cap \dots \cap A_n) \ne 0$ ise, yani olayların ortak bir kısmı varsa:
$$\Pr(A_1 \cap A_2 \cap \dots \cap A_n) = \Pr(A_1)\,\Pr(A_2 \mid A_1)\,\Pr(A_3 \mid A_1 \cap A_2)\cdots\Pr(A_n \mid A_1 \cap A_2 \cap \dots \cap A_{n-1}).$$

Olaylar bağımsızsa her koşullu olasılık koşulsuz olasılığa eşit olduğundan formül $\Pr(A_1)\Pr(A_2)\cdots\Pr(A_n)$ olur.

**Soru:** Bazı kaynaklarda koşullu olasılık yazılırken araya noktalı virgül ya da virgül konuyor; bu gösterimleri de görecek miyiz? **Cevap:** Gösterim kitaptan kitaba değişebilir; derste kullanılan gösterim burada izlenen gösterimdir ve öğrenciler bunu kullanacaktır.

### 7.2 İki para örneği

Hoca basit ve iyi bir örnek verdi (ekrandan, 01:20:00). Elimizde iki para var: biri hileli, biri hilesiz. Hangisinin hangisi olduğunu bilmiyoruz.

- Para 1 (hileli): $\Pr(H) = 3/4$, $\Pr(T) = 1/4$.
- Para 2 (hilesiz): $\Pr(H) = 1/2$, $\Pr(T) = 1/2$.

Bir para seçip atıyoruz. $C_i$, $i$'inci paranın seçilmesi olayıdır ($i = 1, 2$). Soru: Sonuç H geldiyse seçilen paranın para 1 olma olasılığı nedir, yani $\Pr(C_1 \mid H)$?

**Çözüm.** Paralar dıştan aynı olduğu için her birinin seçilme olasılığı $1/2$'dir. Ağaç diyagramı:

```text
            3/4 -> H   Pr(C1 ∩ H) = 1/2 · 3/4 = 3/8
   1/2  C1 
            1/4 -> T   Pr(C1 ∩ T) = 1/2 · 1/4 = 1/8
 o
            1/2 -> H   Pr(C2 ∩ H) = 1/2 · 1/2 = 1/4
   1/2  C2
            1/2 -> T   Pr(C2 ∩ T) = 1/2 · 1/2 = 1/4
```

Koşullu olasılığın tanımıyla:
$$\Pr(C_1 \mid H) = \frac{\Pr(C_1 \cap H)}{\Pr(H)}.$$

H iki yoldan gelebilir:
$$\Pr(H) = \Pr(C_1 \cap H) + \Pr(C_2 \cap H) = \frac{3}{8} + \frac{1}{4} = \frac{5}{8}.$$

Sonuç (ekrandan, 01:25:00):
$$\Pr(C_1 \mid H) = \frac{3/8}{5/8} = \frac{3}{5}.$$

> **Ders sonrası not:** Hoca toplamı önce $4/8 = 1/2$ diye söyledi, öğrencilerin uyarısıyla $5/8$ olarak düzeltti. Bölmeyi sözlü yaparken bir an "3/8 bölü 1/8" dedi; ekrandaki ve doğru işlem $\frac{3/8}{5/8} = \frac{3}{5}$'tir.

Hoca bu örnekte para seçme ve parayı atma deneylerinin birbirinden bağımsız varsayıldığını belirtti. $\Pr(H)$'nin iki yolun toplamı olarak bulunması, bir sonraki konu olan toplam olasılık yasasının bir uygulamasıdır.

## 8. Toplam olasılık yasası

> **Hocanın vurgusu:** Toplam olasılık yasası çok önemlidir.

### 8.1 Parçalanış

$B_1, B_2, \dots, B_k \in \mathcal{P}(\Omega)$ olayları şu koşulları sağlıyorsa örnek uzayın bir **parçalanışını** (partition) oluşturur:

- Her $i \ne j$ için $B_i \cap B_j = \emptyset$ (ikişer ayrık, mutually exclusive).
- $\bigcup_{i=1}^{k} B_i = \Omega$ (birlikte örnek uzayı kapsar, collectively exhaustive).
- Her $i = 1, \dots, k$ için $\Pr(B_i) > 0$.

**Soru (hoca sordu):** Üçüncü koşul ne anlama gelir? **Cevap:** Öğrenciler parçaların boş olamayacağını, yani imkânsız olay olamayacaklarını söyledi; hoca bunu onayladı.

### 8.2 Yasa

$B_1, \dots, B_k$ örnek uzayın bir parçalanışıysa her $A \in \mathcal{P}(\Omega)$ için (ekrandan, 01:30:00):
$$\Pr(A) = \sum_{i=1}^{k} \Pr(B_i)\,\Pr(A \mid B_i).$$

Hoca bunu bir şekille açıkladı: örnek uzay $B_1, \dots, B_6$ diye altı parçaya bölünmüş, $A$ olayı (kırmızı bölge) bu parçaların birkaçıyla kesişiyor. $B_6$ gerçekleştiğinde $A$'nın da bir kısmı gerçekleşmiş olabilir; bu, kesişim bölgesine düşen kısımdır ve $\Pr(B_6)\Pr(A \mid B_6)$ ile ölçülür. Bütün parçalar için bu katkılar toplanınca:
$$\Pr(A) = \Pr(B_1)\Pr(A \mid B_1) + \Pr(B_2)\Pr(A \mid B_2) + \dots + \Pr(B_6)\Pr(A \mid B_6).$$

Bir olayın olasılığı, aynı örnek uzayda tanımlanmış bir parçalanışa göre koşullu olasılıklarla yazılabilir. Yasanın adı buradan gelir.

### 8.3 İki parçalı özel durum

$B$ ve $\bar{B}$ bir parçalanış oluşturur, çünkü kesişimleri boş ve birleşimleri örnek uzaydır. Bu durumda (ekrandan, 01:35:00):
$$\Pr(A) = \Pr(A \mid B)\Pr(B) + \Pr(A \mid \bar{B})\Pr(\bar{B}).$$

## 9. Bayes kuralı ve Bayes teoremi

### 9.1 Bayes kuralı

Herhangi iki olay $A$ ve $B$ için koşullu olasılığın tanımından iki eşitlik yazılır:

1. $\Pr(A \mid B) = \dfrac{\Pr(A \cap B)}{\Pr(B)} \Rightarrow \Pr(A \mid B)\Pr(B) = \Pr(A \cap B)$.
2. $\Pr(B \mid A) = \dfrac{\Pr(B \cap A)}{\Pr(A)} \Rightarrow \Pr(B \mid A)\Pr(A) = \Pr(B \cap A)$.
3. $\Pr(A \cap B) = \Pr(B \cap A)$.

Bu üç eşitlikten **Bayes kuralı** çıkar:
$$\Pr(A \mid B)\Pr(B) = \Pr(B \mid A)\Pr(A), \qquad \Pr(A) \ne 0, \ \Pr(B) \ne 0.$$

### 9.2 Bayes teoremi: sezgi

Hoca Bayes kuralı ile Bayes teoreminin farklı olduğunu söyledi. Önce düşünceyi bir örnekle anlattı: iki fabrika elektronik çip üretiyor ve çiplerden bazıları bozuk çıkıyor. Bozuk bir çip gözlendiğinde, bu çipin birinci ya da ikinci fabrikada üretilmiş olma olasılığı soruluyor. Bir gözlem "çipler fabrikalarda üretilir" (neden), diğeri "bozuk çip gözlendi" (sonuç) bilgisidir; sonuçtan nedene geri gidilir. İki durumlu böyle bir problemde Bayes kuralı, genel durumda Bayes teoremi kullanılır.

### 9.3 Bayes teoremi: ifade ve ispat

$B_1, B_2, \dots, B_k$ örnek uzay $\Omega$'nın bir parçalanışı olsun ve $A$ olayının gerçekleşmesinin nedenleri olsun. Her $j \in \{1, 2, \dots, k\}$ için (ekrandan, 01:45:00):
$$\Pr(B_j \mid A) = \frac{\Pr(B_j)\,\Pr(A \mid B_j)}{\sum_{i=1}^{k} \Pr(B_i)\,\Pr(A \mid B_i)}.$$

**İspat.** Koşullu olasılığın tanımıyla
$$\Pr(B_j \mid A) = \frac{\Pr(B_j \cap A)}{\Pr(A)}.$$
Pay, çarpma kuralıyla $\Pr(B_j)\Pr(A \mid B_j)$ olarak yazılır. Payda, toplam olasılık yasasıyla $\sum_{i=1}^{k} \Pr(B_i)\Pr(A \mid B_i)$ olur. İkisi yerine konunca teorem elde edilir.

Sonuç olarak Bayes teoremi, Bayes kuralı ile toplam olasılık yasasının birleşimidir.

### 9.4 Önsel ve sonsal olasılıklar

- $\Pr(B_i)$, $i = 1, \dots, k$: **önsel olasılıklar** (prior probabilities). Önceden bilinirler (ekrandan, 01:50:00).
- $\Pr(B_i \mid A)$: **sonsal olasılıklar** (posterior probabilities).
- $A$ olayı: **kanıt** (evidence).

Kanıt $A$ elde edilmeden önce elimizde önsel olasılıklar $\Pr(B_1), \Pr(B_2), \dots$ vardır. Ayrıca her hipotez doğruyken kanıtın olasılığı, yani $\Pr(A \mid B_i)$ biliniyorsa, kanıt verildiğinde hipotezlerin olasılıkları $\Pr(B_i \mid A)$ Bayes teoremiyle bulunur.

### 9.5 Bağımsızlık ve ayrıklık sorusu

**Soru:** Her bağımsız olay çifti için aynı zamanda ayrık (mutually exclusive) diyebilir miyiz? **Cevap:** Hoca bağımsızlıkta birlikte gerçekleşme olasılığının olasılıkların çarpımına eşit olması gerektiğini, ayrıklıkta ise olayların kesişiminin boş küme olduğunu açıkladı. Sorunun devamında öğrencinin "bu durumda aynı zamanda ayrık oluyor değil mi" sorusuna "evet" dedi.

> **Ders sonrası not:** Bu "evet" cevabı genel olarak doğru değildir. $\Pr(A) > 0$ ve $\Pr(B) > 0$ iken $A$ ve $B$ ayrıksa $\Pr(A \cap B) = 0 \ne \Pr(A)\Pr(B)$ olur, yani olaylar bağımlıdır. Olasılıkları sıfırdan büyük iki olay hem bağımsız hem ayrık olamaz; ancak olaylardan birinin olasılığı 0 ise ikisi birden sağlanabilir.

## 10. Rastgele değişken

Arada verilen molanın ardından yeni konuya, kesikli rastgele değişkenler ve dağılımlara geçildi.

### 10.1 Tanım

Bir deneyin her sonucuna sayısal bir değer atanarak elde edilen niceliğe **rastgele değişken** denir. Rastgele değişken, sonuçların bir fonksiyonudur.

> **Hocanın vurgusu:** Rastgele değişken, her sonuca sayısal bir değer atamaktır. Hoca bu tanımın altını çizdi ve Türkçe olarak şunu ekledi: makine öğrenmesi ve yapay zekanın temelinde çok değişkenli veri analizi vardır; bunun için kümeler kuramı, olasılık kuramı ve istatistik kuramı çok iyi bilinmelidir. Rastgele değişkenin ne olduğunu açıklayamayan biri bu alanda uzman sayılmaz.

### 10.2 Para atma örneği

Para atma deneyinde gözlemler H ve T'dir. $X$ rastgele değişkeni bu sonuçlara değer atar: $X(H) = 0$, $X(T) = 1$. Beş kez para atıldığında, örneğin T, H, H, T, T sonuçları gelirse rastgele değişken $1, 0, 0, 1, 1$ değerlerini alır.

**Soru:** Derste "dağılım" (distribution) dediğimiz şey bir fonksiyon anlamında mı kullanılıyor? **Cevap:** Evet, dağılım bir fonksiyondur; birikimli dağılım fonksiyonu ileride görülecektir. Hoca buradan şu gözlemi çıkardı: rastgele değişken, şansa bağlı olarak dağılımı belirleyen bir niceliktir.

## 11. Kesikli rastgele değişken ve dağılımı

### 11.1 Tanım

Sayılabilir bir olası değerler kümesine sahip rastgele değişkene, yani sayılabilir değerler alan rastgele değişkene **kesikli rastgele değişken** (discrete random variable) denir (ekrandan, 02:25:00).

### 11.2 Zar örneği

Bir zar atıldığında sonuçlar bir, iki, ..., altı noktalı yüzlerdir. Her sonuca bir sayı atanır: bir nokta $\to 1$, iki nokta $\to 2$, ..., altı nokta $\to 6$ (ekrandan, 02:25:00). Böylece $X$ rastgele değişkeni $1, 2, 3, 4, 5, 6$ değerlerini alabilir.

Rastgele değişkenin örnek uzayı $\{1, 2, 3, 4, 5, 6\}$'dır ve boyutu 6'dır. Elemanlar $1, 2, \dots, 6$ diye sayılabildiği için örnek uzay sayılabilirdir ve $X$ kesiklidir.

> **Ders sonrası not:** Hoca örnek uzayın boyutu sonsuz olursa elemanların sayılamayacağını ve kümenin sayılamaz olacağını söyledi. Doğrusu: "sayılabilir" sonlu ya da sayılabilir sonsuz demektir. Örneğin $\{0, 1, 2, \dots\}$ sonsuzdur ama sayılabilirdir; böyle değerler alan bir rastgele değişken de kesiklidir. Sayılamaz kümelere örnek bir reel aralıktır.

### 11.3 Tanım kümesi ve değer kümesi

Şekilde soldaki sonuçlar tanım kümesini, sağdaki sayılar değer kümesini, oklar da atamayı gösterir. Buradan iki gözlem çıkar:

- Değer atama işleminin tanım kümesi örnek uzay $\Omega$'dır, yani bütün olası sonuçların kümesidir.
- Değer atama işleminin değer kümesi, rastgele değişkenin alabileceği değerlere bağlı olarak $\mathbb{R}$'nin bir alt kümesidir (ekrandan, 02:35:00).

### 11.4 Kesikli dağılım

$X$ rastgele değişkeniyle ilgili bütün olasılıkların topluluğuna **$X$'in dağılımı** (distribution) denir. Dağılım çoğu zaman tablo biçiminde verilir (ekrandan, 02:35:00):

| $X$ | $x_1$ | $x_2$ | $x_3$ | $\dots$ | $x_n$ |
|---|---|---|---|---|---|
| $\Pr(X = x_k)$ | $p_1$ | $p_2$ | $p_3$ | $\dots$ | $p_n$ |

Burada olası değerlere atanan olasılıklar şu koşulları sağlar:

- $0 \le p_i \le 1$, her $i = 1, 2, \dots, n$ için.
- $p_1 + p_2 + \dots + p_n = 1$, yani $\sum_i p_i = 1$.

$p_k = \Pr(X = x_k)$, $X$ rastgele değişkeninin $x_k$ değerini alma olasılığıdır.

### 11.5 Dağılım örnekleri

**Zar atma dağılımı:**

| $X$ | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| $\Pr(X = x_k)$ | 1/6 | 1/6 | 1/6 | 1/6 | 1/6 | 1/6 |

**Hileli para atma dağılımı.** Hoca önce $\Pr(H) = 1/2$ dedi, sonra hileli olması için $\Pr(H) = 1/4$, $\Pr(T) = 3/4$ seçti. H'ye 0, T'ye 1 atandı (ekrandan, 02:40:00):

| $X$ | 0 | 1 |
|---|---|---|
| $\Pr(X = x_k)$ | 1/4 | 3/4 |

## 12. Olasılık kütle fonksiyonu (PMF)

### 12.1 Tanım ve gösterim

Bazen tablo yerine grafik kullanmak daha yararlıdır; olası değer sayısı çok büyükse tablo kullanışsız olur. Bu durumda olasılık kütle fonksiyonu (probability mass function, PMF) kullanılır. Bazı kitaplar buna olasılık frekans fonksiyonu (probability frequency function, PFF) da der.

$X$ rastgele değişkeninin PMF'i şöyle tanımlanır:
$$p(x) = \Pr(X = x).$$

Burada sol taraftaki $X$ rastgele değişken, $x$ ise bir sabittir.

**Soru (hoca sordu):** Kancasız yazılmış küçük $x$ bir rastgele değişken midir? **Cevap:** Öğrenciler değil dedi; hoca, kancası olmadığı için rastgele değişken olmadığını onayladı.

> **Hocanın vurgusu:** Rastgele değişkenler "kancalı" büyük harflerle gösterilir; bu çok önemlidir. (Hocanın el yazısında rastgele değişken $X$'in üst kısmında kanca biçiminde bir işaret vardır; bu notta rastgele değişken düz $X$ ile yazılmıştır.)

Hoca PMF için $p(x)$ ve $p_X(x)$ gösterimlerinin ikisinin de kabul edildiğini, ama $\Pr(X = x)$ yazımının tercih edildiğini söyledi:
$$p(x) = p_X(x) = \Pr(X = x).$$

### 12.2 PMF çizimi

Gerçek eksen üzerinde $x_1, x_2, \dots, x_n$ noktaları işaretlenir ve her noktada yüksekliği $\Pr(X = x_k)$ olan dikey bir çubuk çizilir. Bu çizim $X$'in PMF'idir. Tablo ile çizim aynı bilgiyi verir.

> **Hocanın vurgusu:** $X$'in olası değer sayısı çok fazlaysa PMF çizimlerinin kullanılması şiddetle önerilir (ekrandan, 02:50:00).

**Örnek: hilesiz zar.** PMF çiziminde $x = 1, 2, \dots, 6$ noktalarında yüksekliği $1/6$ olan altı eşit çubuk vardır; başka noktalarda olasılık sıfırdır (ekrandan, 02:50:00).

## 13. Birikimli dağılım fonksiyonu (CDF)

### 13.1 Tanım

$X$ rastgele değişkeninin birikimli dağılım fonksiyonu (cumulative distribution function, CDF) büyük $F$ harfiyle gösterilir ve şöyle tanımlanır (ekrandan, 02:55:00):
$$F_X(x) = \Pr(X \le x).$$

Burada $X$ rastgele değişken, $x$ sabittir. Kesikli bir rastgele değişken için:
$$F_X(x) = \sum_{\text{tüm } x_k \le x} \Pr(X = x_k),$$
burada $x_k$, $X$'in $k$'inci olası değeridir.

### 13.2 Zar atmanın CDF'i

$X \in \{1, 2, 3, 4, 5, 6\}$ ve her değerin olasılığı $1/6$'dır. Birkaç noktada CDF değeri (ekrandan, 03:05:00 ve 03:10:00):

- $F_X(1) = \Pr(X \le 1) = 1/6$.
- $F_X(0.5) = \Pr(X \le 0.5) = 0$, çünkü zarın değerleri arasında $0.5$'ten küçük ya da ona eşit bir değer yoktur.
- $F_X(1.5) = \Pr(X \le 1.5) = \Pr(X = 1) = 1/6$.
- $F_X(3.5) = \Pr(X \le 3.5) = \Pr(X = 1) + \Pr(X = 2) + \Pr(X = 3) = \frac16 + \frac16 + \frac16 = \frac36 = \frac12$.
- $F_X(8) = \Pr(X \le 8) = \Pr(X = 1) + \dots + \Pr(X = 6) = 6 \cdot \frac16 = 1$.

> **Ders sonrası not:** Hoca $F_X(0.5)$'i hesaplarken bir an "0.5 bölü 6" dedi; hemen ardından ve ekranda doğru sonuç $0$ olarak verildi.

Bu değerlerle grafik çizildi: $x < 1$ için $F_X(x) = 0$; $x = 1$'de $1/6$'ya sıçrar ve $x = 2$'ye kadar sabit kalır; $x = 2$'de $2/6$'ya, $x = 3$'te $3/6$'ya, $x = 4$'te $4/6$'ya, $x = 5$'te $5/6$'ya, $x = 6$'da $1$'e sıçrar ve sonra hep $1$ kalır. Her basamağın sol ucu dolu noktayla (değer o noktada alınır), sağ ucu boş noktayla gösterilir.

$$F_X(x) = \begin{cases} 0, & x < 1 \\ k/6, & k \le x < k+1, \quad k = 1, \dots, 5 \\ 1, & x \ge 6 \end{cases}$$

**Soru:** CDF grafiğindeki dikey çizgiler düz yerine kesikli çizilmeli mi? **Cevap:** İstenirse kesikli çizilebilir, istenmezse çizilmeyebilir. Dikey kısım zaten bir sıçramayı ifade eder. Önemli olan grafiğin, örneğin $x = 3$'te değerin $1/6$ değil $3/6$ olduğunu doğru göstermesidir.

Hoca CDF'in temel özelliklerine bir sonraki derste devam edileceğini söyledi.

## Örnek Sorular

### Soru 1: Beş olayın birleşimi (ekrandan, 00:30:00)

$\Pr(A \cup B \cup C \cup D \cup E) = ?$ Hoca bunun çok iyi bir sınav sorusu olduğunu söyledi.

> **Çözüm (derste verilmedi):** İçerme-dışarma ilkesine göre
> $$\Pr\Big(\bigcup_{i=1}^{5} A_i\Big) = \sum_{i} \Pr(A_i) - \sum_{i<j} \Pr(A_i \cap A_j) + \sum_{i<j<k} \Pr(A_i \cap A_j \cap A_k) - \sum_{i<j<k<l} \Pr(A_i \cap A_j \cap A_k \cap A_l) + \Pr(A_1 \cap \dots \cap A_5),$$
> burada $A_1 = A, \dots, A_5 = E$. Terim sayıları sırasıyla $\binom51 = 5$, $\binom52 = 10$, $\binom53 = 10$, $\binom54 = 5$ ve $\binom55 = 1$'dir, toplam 31 terim. Formül python ile rastgele beş küme üzerinde sayısal olarak denetlendi; iki taraf aynı sonucu verdi.

### Soru 2: Para ve zar (ekrandan, 00:40:00)

Bir para ve bir zar atılıyor. Paranın H, zarın 6 gelme olasılığı nedir?

Çözüm (derste verildi): olaylar bağımsızdır, $\Pr = \frac12 \cdot \frac16 = \frac{1}{12}$.

### Soru 3: Tek sayı ve asal sayı (derste sözlü, 00:39:40)

Bir zar atıldığında "tek sayı gelmesi" ile "asal sayı gelmesi" bağımsız mıdır?

Çözüm: Hoca bağımlı olduklarını, çünkü 3 ve 5'in iki kümede de bulunduğunu söyledi. Sayısal kontrol (ara adım eklendi): $\Pr(\text{tek} \cap \text{asal}) = 1/3$, $\Pr(\text{tek})\Pr(\text{asal}) = 1/4$; eşit olmadıkları için olaylar bağımlıdır.

### Soru 4: Hangi para seçildi? (ekrandan, 01:20:00)

Biri $\Pr(H) = 3/4$ olan hileli, diğeri hilesiz iki para var. Rastgele bir para seçilip atılıyor ve H geliyor. $\Pr(C_1 \mid H)$ nedir?

Çözüm (derste verildi, ekrandan, 01:25:00): $\Pr(C_1 \cap H) = 3/8$, $\Pr(H) = 3/8 + 1/4 = 5/8$, $\Pr(C_1 \mid H) = 3/5$.

### Soru 5: Parçalanışın üçüncü koşulu (derste sözlü, 01:26:14)

Parçalanış tanımındaki "$\Pr(B_i) > 0$ her $i$ için" koşulu ne anlama gelir?

Çözüm (derste verildi): Parçaların hiçbiri imkânsız olay (boş) olamaz.

### Soru 6: Zarın CDF değerleri (ekrandan, 03:05:00)

Hilesiz zar için $F_X(1)$, $F_X(0.5)$, $F_X(1.5)$, $F_X(3.5)$ ve $F_X(8)$ değerleri nedir?

Çözüm (derste verildi): $1/6$, $0$, $1/6$, $1/2$ ve $1$. Değerler python ile doğrulandı.

## Dersin Toparlaması

Bu derste olasılık, örnek uzayın kuvvet kümesinden $[0,1]$ aralığına giden ve üç aksiyomu sağlayan bir fonksiyon (olasılık ölçüsü) olarak kuruldu. Aksiyomlardan imkânsız olay, tümleyen, ayrık olayların birleşimi ve içerme-dışarma kuralları ile temel eşitsizlikler türetildi. Ardından bağımsızlık, koşullu olasılık ve çarpma kuralı ele alındı; iki para örneğinde koşullu olasılık ağaç diyagramıyla hesaplandı. Toplam olasılık yasası parçalanış kavramıyla verildi ve Bayes kuralıyla birleştirilerek Bayes teoremi elde edildi; önsel olasılık, sonsal olasılık ve kanıt kavramları tanıtıldı.

Dersin son bölümünde rastgele değişken, sonuçlara sayısal değer atayan bir fonksiyon olarak tanımlandı. Kesikli rastgele değişken, dağılım tablosu, olasılık kütle fonksiyonu ve birikimli dağılım fonksiyonu zar ve para örnekleriyle işlendi. Hoca bir sonraki derste CDF'in özellikleriyle devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
