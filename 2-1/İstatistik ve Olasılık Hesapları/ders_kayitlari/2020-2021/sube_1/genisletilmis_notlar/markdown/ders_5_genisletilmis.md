# Ders 5 Genişletilmiş Notu: Bağımsızlık ve İlişkisizlik, Kovaryans, Korelasyon, Entropi ve Markov Eşitsizliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersin tekrarı
- 2. Bağımsızlık ve ilişkisizlik
- 3. Örnek: Z = aX + bY + c rastgele değişkeninin ortalaması ve varyansı
- 4. Bağımsızlıktan E[XY] = E[X]E[Y] sonucunun ispatı
- 5. Kovaryans
- 6. Korelasyon katsayısı
- 7. Varyans, belirsizlik ve entropi
- 8. Markov eşitsizliği
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki dersin tekrarı

Hoca derse geçen haftanın sonuçlarını hatırlatarak başladı. Ortalaması sıfır olan bir sinyalin gücü, o sinyalin varyansına eşittir. $X$ ve $Y$ birbirinden bağımsız iki rastgele değişkense, çarpımlarının beklenen değeri ayrı ayrı beklenen değerlerin çarpımı olarak yazılabilir:

$$E[XY] = E[X]\,E[Y].$$

Bu eşitlik daha önceki derslerde ispatlanmıştı. Onun bir sonucu olarak bağımsız rastgele değişkenlerin toplamının varyansı, tek tek varyanslarının toplamına eşittir:

$$\mathrm{Var}(X + Y) = \mathrm{Var}(X) + \mathrm{Var}(Y).$$

Hoca bu eşitliğin yalnız $X$ ve $Y$ bağımsız olduğunda (daha doğrusu ilişkisiz olduğunda) doğru olduğunu belirtti.

## 2. Bağımsızlık ve ilişkisizlik

### 2.1 Bağımsızlık ilişkisizliği gerektirir

Hoca ekrana şunu yazdı (ekrandan, 00:20:00): $X$, $Y$ ve $Z$ üç bağımsız rastgele değişken olsun. Bağımsız oldukları için ilişkisizdirler (uncorrelated):

$$\text{bağımsız} \Rightarrow \text{ilişkisiz}.$$

Bu genel bir sonuçtur. Rastgele değişkenlerin bağımsız olduğu söyleniyorsa, ilişkisiz oldukları da söylenmiş olur.

### 2.2 İlişkisizlik bağımsızlığı gerektirmez

Ardından tersini yazdı (ekrandan, 00:25:00): $X$, $Y$ ve $Z$ üç ilişkisiz rastgele değişken olsun. Buradan bağımsız oldukları sonucu çıkar mı? Çıkmaz. Hoca okun üstünü çarpı ile çizdi ve yanına bir uyarı işareti çizdi:

$$\text{ilişkisiz} \not\Rightarrow \text{bağımsız}.$$

> **Hocanın vurgusu:** Rastgele değişkenler ilişkisizse bağımsız oldukları söylenemez. Bu çok önemli bir noktadır, bu hatayı yapmayın.

> **Ek bilgi (derste anlatılmadı):** Klasik karşı örnekte $X$ sıfır çevresinde simetrik dağılır ve $Y = X^2$ alınır. $Y$ tamamen $X$ tarafından belirlendiği için bağımsız değildir, ama simetri yüzünden $E[XY] = E[X^3] = 0 = E[X]E[Y]$ olur, yani kovaryans sıfırdır. Kovaryans yalnız doğrusal ilişkiyi ölçer; doğrusal olmayan bağımlılığı göremez.

### 2.3 Korelasyon sezgisi

Bir öğrenci geçen hafta korelasyonun görülmediğini hatırlattı. Hoca bunun yalnızca bir giriş olduğunu, ayrıntının ileride geleceğini söyledi ve korelasyonun anlamını sordu.

**Soru:** Korelasyon ne demek? **Cevap (bir öğrenci):** $X$ ile $Y$ ilişkiliyse $X$ artarken $Y$ de artar gibi bir şey. Hoca bunu doğruladı ve genişletti: $X$ artarken $Y$ de artıyorsa değişkenler ilişkilidir. $X$ artarken $Y$ azalıyorsa ya da $X$ azalırken $Y$ artıyorsa da ilişkilidirler, ama bu kez korelasyon negatiftir.

Korelasyonun Türkçesi "ilişki"dir. Hocanın günlük hayattan örneği: dolar düşerken altın yükseliyorsa ya da ikisi birlikte düşüp yükseliyorsa bu olaylar ilişkilidir. Doğadaki pek çok olay ilişkilidir, bazıları ilişkisizdir. Bağımsızlık ise korelasyondan farklı bir kavramdır: bağımsızlık ilişkisizliği gerektirir, ama tersi geçerli değildir.

## 3. Örnek: Z = aX + bY + c rastgele değişkeninin ortalaması ve varyansı

### 3.1 Soru

$X$ ve $Y$ iki bağımsız rastgele değişken olsun. $a$, $b$, $c$ reel sabitler olmak üzere

$$Z = aX + bY + c$$

rastgele değişkeninin ortalamasını ve varyansını bulun. Yani soru $E[Z]$ ve $\mathrm{Var}(Z)$ değerlerini istiyor.

### 3.2 Ortalama

Beklenen değer doğrusal bir işlemdir ve $Z$ de doğrusal bir ifadedir. Bu yüzden beklenen değer toplamın terimlerine dağıtılabilir (ekrandan, 00:30:00):

$$
\begin{aligned}
E[Z] &= E[aX + bY + c] \\
&= E[aX + bY] + E[c] \\
&= E[aX + bY] + c \\
&= E[aX] + E[bY] + c \\
&= aE[X] + bE[Y] + c.
\end{aligned}
$$

Sabit bir sayının beklenen değeri kendisidir; bu yüzden $E[c] = c$. $a$ ve $b$ de sabit olduğundan beklenen değer işleminin dışına çıkarlar.

### 3.3 Varyans

Hoca önce varyansın sezgisini Türkçe hatırlattı: bir sinyal ya da rastgele değişken çok farklı değerler alıyorsa varyansı büyüktür; hep yakın değerler alıyorsa varyansı küçüktür. Tanım ise ikinci moment eksi birinci momentin karesidir:

$$\mathrm{Var}(Z) = E[Z^2] - \big(E[Z]\big)^2.$$

Birinci moment zaten bulundu; onun karesi $(aE[X] + bE[Y] + c)^2$ olur. Bu ifadeye (1\*) dendi. Geriye ikinci moment kalıyor (ekrandan, 00:35:00):

$$
\begin{aligned}
E[Z^2] &= E\big[(aX + bY + c)^2\big] \\
&= E\big[(aX + bY)^2 + 2c(aX + bY) + c^2\big] \\
&= E\big[(aX + bY)^2\big] + 2caE[X] + 2cbE[Y] + c^2.
\end{aligned}
$$

Bu ifade (2\*) oldu. İçindeki $E[(aX + bY)^2]$ terimi ayrıca açıldı:

$$
\begin{aligned}
E\big[(aX + bY)^2\big] &= E\big[a^2X^2 + 2abXY + b^2Y^2\big] \\
&= a^2E[X^2] + b^2E[Y^2] + 2abE[XY] \\
&= a^2E[X^2] + b^2E[Y^2] + 2ab\,E[X]\,E[Y].
\end{aligned}
$$

Son adımda $X$ ile $Y$ ilişkisiz olduğu için (bağımsız oldukları için) $E[XY] = E[X]E[Y]$ yazıldı. Bu da (3\*) oldu.

(1\*), (2\*) ve (3\*) birlikte kullanılınca (ekrandan, 00:40:00):

$$\mathrm{Var}(Z) = a^2\,\mathrm{Var}(X) + b^2\,\mathrm{Var}(Y),$$

yani

$$\mathrm{Var}(aX + bY + c) = a^2\,\mathrm{Var}(X) + b^2\,\mathrm{Var}(Y).$$

Ara adım eklendi: $(E[Z])^2 = a^2E[X]^2 + b^2E[Y]^2 + c^2 + 2abE[X]E[Y] + 2acE[X] + 2bcE[Y]$ açılımı $E[Z^2]$'den çıkarılınca $2abE[X]E[Y]$, $2acE[X]$, $2bcE[Y]$ ve $c^2$ terimleri birbirini götürür. Geriye $a^2(E[X^2] - E[X]^2) + b^2(E[Y^2] - E[Y]^2)$ kalır. Sonuç python ile benzetim yapılarak doğrulandı.

### 3.4 Yorum

Sabit $c$ varyansı değiştirmez; bu beklenen bir sonuçtur, çünkü sabit eklemek bütün değerleri aynı miktarda kaydırır ve ortalamadan sapmayı etkilemez. Varyans yalnız ölçek katsayılarına bağlıdır: toplam varyans, $a$'nın karesi çarpı $X$'in varyansı artı $b$'nin karesi çarpı $Y$'nin varyansıdır.

> **Hocanın vurgusu:** Bu çıkarımda kilit nokta şudur: $X$ ve $Y$ ilişkisizse çarpımlarının ortalaması, ayrı ayrı ortalamalarının çarpımına eşittir.

**Soru (hocanın sınıfa sorusu):** Bu eşitliği nereden biliyoruz, nerede göstermiştik? Cevap gelmeyince hoca önceki haftaların notlarına döndü ve ispatı yeniden yaptı.

## 4. Bağımsızlıktan E[XY] = E[X]E[Y] sonucunun ispatı

İki kesikli rastgele değişken alalım. $X$ rastgele değişkeni $x_1, x_2, \dots, x_n$ değerlerini, $Y$ rastgele değişkeni $y_1, y_2, \dots, y_m$ değerlerini alabilir. Her değerin bir olasılığı vardır:

$$\Pr(X = x_i) = p_i,\qquad \sum_{i=1}^{n} p_i = 1,$$

$$\Pr(Y = y_j) = q_j,\qquad \sum_{j=1}^{m} q_j = 1.$$

Ayrıca ortak olasılıklar vardır: $\Pr(X = x_i \cap Y = y_j)$.

$X$ ile $Y$ bağımsızsa ortak olasılık çarpanlarına ayrılır (ekrandan, 00:50:00):

$$\Pr(X = x_i \cap Y = y_j) = \Pr(X = x_i)\,\Pr(Y = y_j) = p_i\,q_j.$$

Çarpımın beklenen değeri bütün $(x_i, y_j)$ ikilileri üzerinden alınır:

$$
\begin{aligned}
E[XY] &= \sum_{(x_i, y_j)} x_i y_j \Pr(X = x_i \cap Y = y_j) \\
&= \sum_{i=1}^{n}\sum_{j=1}^{m} x_i y_j \Pr(X = x_i \cap Y = y_j).
\end{aligned}
$$

Bağımsız değillerse bu ifade daha fazla sadeleşmez. Bağımsızlarsa (ara adım eklendi):

$$E[XY] = \sum_{i=1}^{n}\sum_{j=1}^{m} x_i p_i\, y_j q_j = \left(\sum_{i=1}^{n} x_i p_i\right)\left(\sum_{j=1}^{m} y_j q_j\right) = E[X]\,E[Y].$$

Birinci parantez $X$'in, ikinci parantez $Y$'nin beklenen değeridir. $X$ ve $Y$ bağımsız değilse genel olarak

$$E[XY] \ne E[X]\,E[Y]$$

olur. Bu iki taraf arasındaki fark kovaryans diye adlandırılır.

## 5. Kovaryans

### 5.1 İlk tanım ve özel durumlar

Hoca kovaryansı önce $E[XY]$ ile $E[X]E[Y]$ arasındaki fark olarak verdi ve hemen iki özel duruma baktı:

$$\mathrm{Cov}(X, X) = E[X \cdot X] - E[X]\,E[X] = E[X^2] - (E[X])^2 = \mathrm{Var}(X),$$

benzer şekilde $\mathrm{Cov}(Y, Y) = \mathrm{Var}(Y)$. Bir de $Y$ ile $-Y$ arasındaki kovaryansa baktı (ekrandan, 00:55:00):

$$\mathrm{Cov}(Y, -Y) = -\mathrm{Var}(Y).$$

Buradan görülen şudur: varyans negatif olamaz, ama kovaryans negatif de pozitif de olabilir.

> **Ders sonrası not:** Hoca "varyans her zaman pozitiftir" dedi. Doğrusu varyans negatif olmayan bir sayıdır: sabit bir rastgele değişkenin varyansı sıfırdır.

### 5.2 Kovaryansın anlamı

Aradan sonra hoca kovaryansı Türkçe açıkladı. Varyans, ortalamadan sapma miktarıdır. Kovaryans ise iki rastgele değişkenin birbiriyle olan ilişkisinin derecesidir: birbirlerine göre nasıl saptıklarının ölçüsüdür. İki değişkenin aldığı değerler birbirinden tamamen alakasızsa (birisi büyük değer alırken diğeri bazen büyük bazen küçük değer alıyorsa) kovaryans sıfır olur.

### 5.3 Biçimsel tanım

Ekrandaki tanım (ekrandan, 01:10:00):

$$\mathrm{Cov}(X, Y) = E\Big[\big(X - E[X]\big)\big(Y - E[Y]\big)\Big].$$

Parantezler açılır:

$$\mathrm{Cov}(X, Y) = E\Big[XY - X\,E[Y] - E[X]\,Y + E[X]\,E[Y]\Big].$$

Bir rastgele değişkenin ortalaması sabittir, değişmez. Bu yüzden $E[X]$ ve $E[Y]$ sabit gibi davranır ve beklenen değerin dışına çıkar (ara adım eklendi):

$$\mathrm{Cov}(X, Y) = E[XY] - E[X]E[Y] - E[X]E[Y] + E[X]E[Y] = E[XY] - E[X]\,E[Y].$$

Kovaryans, rastgele değişkenlerin birbirine bağımlılığının gücünü (strength of the dependence) ölçer.

### 5.4 Bağımsızlık ve sıfır kovaryans

$X$ ve $Y$ bağımsızsa $E[XY] = E[X]E[Y]$ olduğundan

$$\mathrm{Cov}(X, Y) = E[X]E[Y] - E[X]E[Y] = 0.$$

Yani bağımsızlık sıfır kovaryans demektir; sıfır kovaryansın diğer adı ilişkisizliktir (ekrandan, 01:15:00):

$$\text{bağımsızlık} \Rightarrow \text{sıfır kovaryans (ilişkisizlik)}.$$

Ancak tersi doğru değildir (ekrandan, 01:20:00):

$$\text{sıfır kovaryans (ilişkisizlik)} \not\Rightarrow \text{bağımsızlık}.$$

## 6. Korelasyon katsayısı

### 6.1 Kovaryansın sınırı

Hoca $X = Y$ olursa kovaryansın $\mathrm{Var}(X)$'e (ya da $\mathrm{Var}(Y)$'ye) eşit olduğunu hatırlattı ve buradan kovaryansın varyansların büyüğünü aşamayacağını yazdı (ekrandan, 01:40:00):

$$\mathrm{Cov}(X, Y) \le \max\big(\mathrm{Var}(X), \mathrm{Var}(Y)\big).$$

Kovaryans negatif de olabileceği için bunu iki yönlü yazdı:

$$-\max\big(\mathrm{Var}(X), \mathrm{Var}(Y)\big) \le \mathrm{Cov}(X, Y) \le \max\big(\mathrm{Var}(X), \mathrm{Var}(Y)\big).$$

Sonra eşitsizliğin her parçasını pozitif bir sabit olan $\sqrt{\mathrm{Var}(X)\,\mathrm{Var}(Y)}$'ye böldü. Pozitif sabite bölmek eşitsizliğin yönünü değiştirmez.

**Soru (hocanın sınıfa sorusu):** Sağ taraftaki oranın en büyük değeri nedir? **Cevap (bir öğrenci):** 1. Hoca bu cevabı kabul etti ve şu sonuca vardı (ekrandan, 01:45:00):

$$-1 \le \frac{\mathrm{Cov}(X, Y)}{\sqrt{\mathrm{Var}(X)\,\mathrm{Var}(Y)}} \le 1.$$

> **Ders sonrası not:** Hocanın kullandığı yol bu sonucu vermez. $\max(\mathrm{Var}(X), \mathrm{Var}(Y))/\sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)}$ oranı her zaman 1 ya da daha büyüktür; varyanslar eşitse tam 1 olur, farklıysa 1'den büyüktür (python ile kontrol edildi). Bu nedenle bu adımdan $|\rho| \le 1$ çıkmaz. Sonuç doğrudur, ama doğru gerekçesi Cauchy-Schwarz eşitsizliğidir: $|\mathrm{Cov}(X,Y)| \le \sqrt{\mathrm{Var}(X)\,\mathrm{Var}(Y)}$.

> **Ek bilgi (derste anlatılmadı):** Cauchy-Schwarz eşitsizliği beklenen değer için $\big(E[UV]\big)^2 \le E[U^2]\,E[V^2]$ biçimindedir. $U = X - E[X]$ ve $V = Y - E[Y]$ alınınca doğrudan $\mathrm{Cov}(X,Y)^2 \le \mathrm{Var}(X)\,\mathrm{Var}(Y)$ elde edilir. Eşitlik yalnız $Y$, $X$'in doğrusal bir fonksiyonu olduğunda sağlanır; bu durumda $\rho = \pm 1$ olur.

### 6.2 Tanım

Bu orana $X$ ile $Y$ arasındaki korelasyon (korelasyon katsayısı) denir:

$$\rho_{X,Y} = \frac{\mathrm{Cov}(X, Y)}{\sqrt{\mathrm{Var}(X)\,\mathrm{Var}(Y)}},\qquad -1 \le \rho_{X,Y} \le 1.$$

### 6.3 Yorum

Ekrandaki açıklama (ekrandan, 01:50:00): korelasyon katsayısı $-1$ ile $+1$ arasında bir sayıdır.

- Pozitif değerler, bir rastgele değişkenin "yüksek" değerlerinin diğer rastgele değişkenin yüksek değerleriyle birlikte görülme eğilimi olduğunu gösterir.
- Negatif değerler, bir rastgele değişkenin yüksek değerlerinin diğerinin düşük değerleriyle birlikte görülme eğilimi olduğunu gösterir.
- Korelasyon $+1$'e ya da $-1$'e yaklaştıkça, yani sıfırdan uzaklaştıkça bu eğilimin gücü artar.

## 7. Varyans, belirsizlik ve entropi

### 7.1 Gözlem grafiği

Hoca iki rastgele değişkenin on denemedeki gözlemlerini aynı eksende çizdi (ekrandan, 01:55:00): yatay eksen deneme numarası (1'den 10'a), dikey eksen gözlem değeri. Kırmızı noktalar $X$'in, mavi noktalar $Y$'nin gözlemleridir. Hoca bunların bir olasılık yoğunluk ya da dağılım fonksiyonu olmadığını, deneyin çıktıları olduğunu vurguladı; istenirse histogramlarına bakılabilir.

**Soru (hocanın sınıfa sorusu):** Hangisinin varyansı daha büyük? **Cevap (bir öğrenci):** $X$'in değerleri birbirinden daha uzak dağılmış, aralarındaki mesafe daha büyük; yani $X$'in sapması daha yüksek. Hoca "sapma" kelimesinin doğru olduğunu söyledi ve ortalamaları grafiğe ekledi:

$$E[X] = \sum_{x_k} x_k \Pr(X = x_k),\qquad E[Y] = \sum_{y_k} y_k \Pr(Y = y_k).$$

Grafikte olasılıklar görünmez, yalnız değerler görünür. Kırmızı noktalar ortalamadan daha çok uzaklaştığı için kırmızının varyansı daha yüksektir. Belirsizlik de kırmızıda daha fazladır, mavide daha azdır.

### 7.2 Entropi nedir?

**Soru (hocanın sınıfa sorusu):** Entropi nedir? Öğrencilerden "bilginin değeri", "belirsizlik", "dağınıklık" gibi cevaplar geldi. Hoca bu tanımların hiçbirini tam kabul etmedi.

Hocanın tanımı (ekrandan, 02:05:00):

$$\text{Entropi} = \text{bilgi miktarı (the amount of information)}.$$

Burada "bilgi değeri" değil, "bilgi miktarı" söz konusudur. Fizikçiler entropiyi düzensizlik olarak tanımlar, çünkü atom ve moleküllerin uzaydaki dizilimine bakarlar: atomlar dağınık yayılmışsa entropi yüksek, hepsi tek noktada toplanmışsa entropi sıfırdır. Mühendislikte ise entropi bilgi miktarıdır.

> **Hocanın vurgusu:** Mühendis olarak entropinin anlamı "amount of information"dır. Entropiyi size yalnızca düzensizlik olarak anlatan kaynaklara dikkat edin.

### 7.3 Information ve knowledge

Hoca Türkçede tek bir "bilgi" kelimesi olduğunu, İngilizcede ise iki ayrı kavram bulunduğunu belirtti. Öğrencilerden "information verinin düzenlenmiş, anlam kazanmış hâlidir", "knowledge bilgilerin birbirine bağlanmış hâlidir" gibi cevaplar geldi.

**Soru:** Entropi = the amount of knowledge diyebilir miyiz? **Cevap:** Hayır. Hocanın tanımları (ekrandan, 02:05:00):

- information = bilmediğin "bilgi" (that you don't know),
- knowledge = bildiğin "bilgi" (that you know).

Dolayısıyla entropi, bilmediğiniz bilginin miktarıdır.

### 7.4 Grafiğe dönüş

Kırmızı değişken daha fazla bilgi taşır: değerlerini önceden kestiremezsiniz, çok sayıda deneme yaptıkça yeni bilgi öğrenirsiniz. Mavinin değerini ise neredeyse bilirsiniz, ortalamanın çevresindedir; bu yüzden mavi daha az bilgi taşır.

Hoca bunu makine öğrenmesine bağladı: makine öğrenmesi ve yapay zekâ algoritmaları, bilinmeyen bilgiyi (information) bilinen bilgiye (knowledge) dönüştürür.

> **Ek bilgi (derste anlatılmadı):** Kesikli bir $X$ için Shannon entropisi $H(X) = -\sum_k \Pr(X = x_k)\log_2 \Pr(X = x_k)$ bit olarak tanımlanır. Bütün olasılık tek bir değerdeyse $H = 0$ olur (sonuç önceden bilinir). Olasılık değerlere eşit yayıldıkça $H$ büyür. Bu, hocanın "belirsizlik arttıkça bilgi miktarı artar" yorumunun biçimsel karşılığıdır.

## 8. Markov eşitsizliği

### 8.1 Markov zinciri ile karıştırmayın

Hoca olasılık teorisindeki faydalı eşitsizliklere geçti ve Chebyshev ile Markov eşitsizliklerini anacağını söyledi; derste Markov eşitsizliği işlendi. Bir öğrenci Markov zincirlerini hatırlattı. Hoca Markov zincirlerinin Markov eşitsizliğiyle ilgili olmadığını söyledi. Markov zincirleri ve gizli Markov modelleri (Hidden Markov Models) sistem modellemede, örneğin sesin ya da ağdaki haberleşme sistemlerinin karşılaştığı durumların modellenmesinde kullanılır.

> **Ders sonrası not:** Hoca, Markov zincirlerini ve Markov eşitsizliğini ortaya koyan kişilerin genelde aynı kişi olmadığını söyledi. Büyük olasılıkla ikisi de aynı matematikçinin, Andrey Markov'un adını taşır. Yine de iki kavram birbirinden farklıdır.

### 8.2 Teorem

**Soru (hocanın sınıfa sorusu):** Negatif olmayan (non-negative) ne demek? **Cevap (bir öğrenci):** Her zaman pozitif ya da sıfır.

Ekrandaki teorem (ekrandan, 02:25:00): negatif olmayan bir $X$ rastgele değişkeni (deneyi her zaman pozitif ya da sıfır sonuç veren bir rastgele değişken) ve pozitif bir $c$ sabiti için

$$\Pr(X \ge c) \le \frac{E[X]}{c}.$$

Yani bir rastgele değişkenin $c$'den büyük ya da ona eşit olma olasılığı, ortalamasının $c$'ye oranını aşamaz.

### 8.3 Ne zaman işe yarar?

**Soru (hocanın sınıfa sorusu):** Bu eşitsizliği kullanmak ne zaman faydalıdır; sol taraf ile sağ taraf arasındaki fark ne zaman en küçük olur? Öğrenciler önce "beklenen değeri biliyorsam olasılığın ondan küçük olduğunu bilirim" gibi cevaplar verdi. Hoca, öğrendiklerini kullanarak sol tarafın değerine bakmalarını istedi.

Sol taraf bir olasılıktır, değeri $0$ ile $1$ arasındadır; 1'den büyük olamaz. Sağ taraf ise 1'den büyük olabilir; o durumda eşitsizlik hiçbir bilgi vermez. Buradan çıkan sonuç (ekrandan, 02:30:00):

- $\dfrac{E[X]}{c} \ll 1$ ise Markov eşitsizliği çok az hata verir, bu yüzden daha kullanışlı olur.
- Hocanın kutu içine aldığı ifade: $\dfrac{E[X]}{c} \ll 1 \Rightarrow \Pr(X \ge c) \approx \dfrac{E[X]}{c}$.
- Not (Remark): Markov eşitsizliği $c \gg E[X]$ iken yararlıdır.

**Soru:** Yani çok küçük değerler için olasılığa eşit gibi bir yorum mu yapıyoruz? **Cevap:** Evet, hoca bu yorumu doğruladı.

> **Ders sonrası not:** Hoca $E[X]/c \ll 1$ iken $\Pr(X \ge c) \approx E[X]/c$ yazdı. Doğru olan şudur: iki taraf arasındaki mutlak fark en fazla $E[X]/c$ kadardır, bu da küçüktür; yani iki taraf da sıfıra yakındır. Ama oran olarak yakın olmaları gerekmez: gerçek olasılık, sınırdan kat kat küçük olabilir. Eşitsizlik bir üst sınırdır, yaklaşık değer formülü değildir.

Hoca bir uygulama fikri verdi: bir kullanıcının maaşının $c$'den büyük olma olasılığı, maaşların ortalamasının $c$'ye oranıyla sınırlanabilir; bu sınır $c$ ortalamadan çok büyükken anlamlıdır. Eşitsizliğin ispatını sonraya bıraktı.

> **Hocanın vurgusu:** Bir eşitsizliği ezberlemek yetmez; hangi koşulda az hata verdiğini, nerede ve nasıl kullanılacağını bilmek gerekir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $X$ ve $Y$ iki bağımsız rastgele değişken olsun. $a$, $b$, $c$ reel sabitler olmak üzere $Z = aX + bY + c$ rastgele değişkeninin ortalamasını ve varyansını bulun.

> **Çözüm:** Beklenen değerin doğrusallığından $E[Z] = aE[X] + bE[Y] + c$. $E[Z^2] = a^2E[X^2] + b^2E[Y^2] + 2abE[X]E[Y] + 2caE[X] + 2cbE[Y] + c^2$ (bağımsızlıktan $E[XY] = E[X]E[Y]$). $\mathrm{Var}(Z) = E[Z^2] - (E[Z])^2 = a^2\mathrm{Var}(X) + b^2\mathrm{Var}(Y)$ (ekrandan, 00:40:00). Sabit $c$ varyansı etkilemez.

**Soru 2** (derste sözlü, 00:41:56): $X$ ve $Y$ bağımsızken $E[XY] = E[X]E[Y]$ eşitliği nereden gelir?

> **Çözüm:** Bağımsızlıkta ortak olasılık $\Pr(X = x_i \cap Y = y_j) = p_i q_j$ biçiminde çarpanlara ayrılır. Bu yüzden $E[XY] = \sum_i\sum_j x_i y_j p_i q_j = \left(\sum_i x_i p_i\right)\left(\sum_j y_j q_j\right) = E[X]E[Y]$ (ekrandan, 00:50:00).

**Soru 3** (derste sözlü, 00:53:15): $\mathrm{Cov}(Y, -Y)$ neye eşittir?

> **Çözüm:** $\mathrm{Cov}(Y, -Y) = E[-Y^2] - E[Y]\,E[-Y] = -\big(E[Y^2] - (E[Y])^2\big) = -\mathrm{Var}(Y)$ (ekrandan, 00:55:00). Buradan kovaryansın negatif olabileceği görülür.

**Soru 4** (ekrandan, 01:45:00): $\dfrac{\mathrm{Cov}(X,Y)}{\sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)}}$ oranının alabileceği en büyük değer nedir?

> **Çözüm:** Derste cevap 1 olarak verildi; oran $-1$ ile $1$ arasındadır. Doğru gerekçe Cauchy-Schwarz eşitsizliğidir: $|\mathrm{Cov}(X,Y)| \le \sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)}$. En büyük değer olan 1, $Y$ ile $X$ arasında pozitif eğimli doğrusal bir ilişki olduğunda (örneğin $Y = X$ iken) elde edilir.

**Soru 5** (ekrandan, 01:55:00): On denemedeki gözlemleri çizilen kırmızı $X$ ve mavi $Y$ değişkenlerinden hangisinin varyansı, belirsizliği ve taşıdığı bilgi miktarı daha büyüktür?

> **Çözüm:** Kırmızı noktalar ortalamadan çok uzaklaşıyor, mavi noktalar ortalamanın çevresinde kalıyor. Bu yüzden kırmızının ($X$) varyansı, belirsizliği ve taşıdığı bilgi miktarı (entropisi) daha büyüktür; mavinin ($Y$) değeri neredeyse önceden bilinir.

**Soru 6** (derste sözlü, 02:23:41): Markov eşitsizliği $\Pr(X \ge c) \le E[X]/c$ ne zaman faydalıdır; iki taraf arasındaki fark ne zaman küçük olur?

> **Çözüm:** Sol taraf $[0,1]$ aralığındadır. $E[X]/c \ge 1$ ise eşitsizlik bilgi vermez. $E[X]/c \ll 1$, yani $c \gg E[X]$ iken sağ taraf küçüktür ve iki taraf arasındaki mutlak fark da küçük olur (ekrandan, 02:30:00). Bu durumda eşitsizlik, $X$'in büyük değerler alma olasılığının küçük olduğunu garanti eder.

## Dersin Toparlaması

Bu derste rastgele değişkenler arasındaki ilişki üzerinde duruldu. Bağımsızlığın ilişkisizliği gerektirdiği, ama ilişkisizliğin bağımsızlık anlamına gelmediği vurgulandı. $Z = aX + bY + c$ örneğinde beklenen değerin doğrusallığı ve $E[XY] = E[X]E[Y]$ eşitliği kullanılarak $\mathrm{Var}(aX + bY + c) = a^2\mathrm{Var}(X) + b^2\mathrm{Var}(Y)$ bulundu; sabitin varyansı etkilemediği görüldü. Ardından $E[XY]$ ile $E[X]E[Y]$ arasındaki fark olarak kovaryans tanımlandı. Kovaryansın varyanslarla ölçeklenmiş hâli olan korelasyon katsayısının $-1$ ile $1$ arasında olduğu ve işaretinin ilişkinin yönünü, büyüklüğünün gücünü gösterdiği anlatıldı.

Dersin ikinci yarısında varyans, belirsizlik ve bilgi miktarı arasındaki bağ bir gözlem grafiği üzerinden kuruldu; entropi "bilmediğimiz bilginin miktarı" olarak tanımlandı. Son olarak olasılık teorisindeki faydalı eşitsizliklerden Markov eşitsizliği verildi ve $c \gg E[X]$ iken yararlı olduğu gösterildi. Eşitsizliğin ispatı sonraya bırakıldı; derste adı geçen Chebyshev eşitsizliğine bu derste geçilmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
