# Ders 5 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı
  - Ortalaması sıfır olan bir sinyalin gücü, o sinyalin varyansına eşittir.
  - $X$ ve $Y$ bağımsızsa $E[XY] = E[X]\,E[Y]$ yazılabilir ve $\mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$ olur.
- Bağımsızlık ve ilişkisizlik (uncorrelation)
  - $X$, $Y$ ve $Z$ bağımsız rastgele değişkenlerse ilişkisizdirler: bağımsızlık $\Rightarrow$ ilişkisizlik (ekrandan, 00:20:00).
  - Tersi doğru değildir: $X$, $Y$, $Z$ ilişkisiz diye bağımsız oldukları söylenemez (ekrandan, 00:25:00).
  - Korelasyon (Türkçesiyle ilişki): bir değişken artarken diğeri de artıyorsa pozitif, biri artarken diğeri azalıyorsa negatif korelasyon vardır. Hocanın örneği: doların düşmesi ile altının yükselmesi gibi birlikte hareket eden olaylar.
- Örnek: $Z = aX + bY + c$ ($X$, $Y$ bağımsız; $a$, $b$, $c$ reel sabitler) için ortalama ve varyans (ekrandan, 00:30:00, 00:35:00, 00:40:00)
  - Beklenen değer doğrusal bir işlemdir; sabitin beklenen değeri kendisidir: $E[Z] = aE[X] + bE[Y] + c$.
  - Varyans, ikinci moment eksi birinci momentin karesidir: $\mathrm{Var}(Z) = E[Z^2] - (E[Z])^2$.
  - $E[Z^2]$ açılırken $E[XY] = E[X]E[Y]$ kullanılır; sonuç: $\mathrm{Var}(aX + bY + c) = a^2\mathrm{Var}(X) + b^2\mathrm{Var}(Y)$.
  - Sabit $c$ varyansı değiştirmez; varyans yalnız ölçek katsayılarının karesine bağlıdır.
- Bağımsızlıktan $E[XY] = E[X]E[Y]$ sonucunun ispatı (kesikli durum, ekrandan, 00:50:00)
  - $X \in \{x_1, \dots, x_n\}$, $\Pr(X = x_i) = p_i$; $Y \in \{y_1, \dots, y_m\}$, $\Pr(Y = y_j) = q_j$; $\sum p_i = \sum q_j = 1$.
  - $E[XY] = \sum_{i=1}^{n}\sum_{j=1}^{m} x_i y_j \Pr(X = x_i \cap Y = y_j)$.
  - Bağımsızlıkta $\Pr(X = x_i \cap Y = y_j) = \Pr(X = x_i)\Pr(Y = y_j)$ olduğundan çift toplam $\left(\sum_i x_i p_i\right)\left(\sum_j y_j q_j\right) = E[X]E[Y]$ biçiminde ayrılır.
  - Bağımsız değillerse genel olarak $E[XY] \ne E[X]E[Y]$; aradaki fark kovaryanstır.
- Kovaryans
  - Tanım (ekrandan, 01:10:00): $\mathrm{Cov}(X,Y) = E\big[(X - E[X])(Y - E[Y])\big] = E[XY] - E[X]E[Y]$.
  - İki rastgele değişkenin birbirine göre nasıl saptığını, yani bağımlılığın gücünü ölçer.
  - $\mathrm{Cov}(X,X) = \mathrm{Var}(X)$, $\mathrm{Cov}(Y,-Y) = -\mathrm{Var}(Y)$ (ekrandan, 00:55:00).
  - Varyans negatif olamaz, kovaryans negatif olabilir.
  - Bağımsızlık $\Rightarrow$ sıfır kovaryans (ilişkisizlik); sıfır kovaryans $\not\Rightarrow$ bağımsızlık (ekrandan, 01:15:00 ve 01:20:00).
- Korelasyon katsayısı
  - $\rho_{X,Y} = \dfrac{\mathrm{Cov}(X,Y)}{\sqrt{\mathrm{Var}(X)\,\mathrm{Var}(Y)}}$ ve $-1 \le \rho_{X,Y} \le 1$ (ekrandan, 01:45:00).
  - Pozitif değerler: bir değişkenin yüksek değerleri diğerinin yüksek değerleriyle birlikte görülme eğilimindedir. Negatif değerler: birinin yüksek değerleri diğerinin düşük değerleriyle birlikte görülür (ekrandan, 01:50:00).
  - Katsayı $+1$ ya da $-1$'e yaklaştıkça (sıfırdan uzaklaştıkça) bu eğilimin gücü artar.
- Varyans, belirsizlik ve entropi (ekrandan, 01:55:00 ve 02:05:00)
  - On denemenin gözlemleri üzerinde iki değişken çizildi: ortalamasından çok uzaklaşan kırmızı $X$'in varyansı ve belirsizliği yüksek, ortalama çevresinde kalan mavi $Y$'ninki düşüktür.
  - Entropi = bilgi (information) miktarı. Hocanın ayrımı: information "bilmediğin bilgi", knowledge "bildiğin bilgi".
  - Belirsizliği yüksek olan değişken daha fazla bilgi taşır. Makine öğrenmesi ve yapay zekâ algoritmaları bilinmeyen bilgiyi bilinen bilgiye dönüştürür.
- Markov eşitsizliği (ekrandan, 02:25:00 ve 02:30:00)
  - Negatif olmayan bir $X$ (deneyi hep pozitif ya da sıfır sonuç veren) ve pozitif sabit $c$ için $\Pr(X \ge c) \le \dfrac{E[X]}{c}$.
  - Sol taraf $[0,1]$ aralığındadır; $E[X]/c \ll 1$ iken eşitsizliğin hatası küçüktür. Not: eşitsizlik $c \gg E[X]$ iken yararlıdır.
  - Markov eşitsizliği ile Markov zincirleri farklı kavramlardır. İspat sonraki derse bırakıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- İlişkisizlik bağımsızlık demek değildir
  - Hoca bunu "çok önemli" diye iki kez yazdı ve çarpı işaretiyle vurguladı. Bağımsız değişkenler ilişkisizdir, ama ilişkisiz değişkenlerin bağımsız olduğu söylenemez.
- Sabitler varyansı etkilemez
  - $\mathrm{Var}(aX + bY + c)$ ifadesinde $c$ kaybolur; yalnız $a^2$ ve $b^2$ kalır.
- $E[XY] = E[X]E[Y]$ eşitliğinin nereden geldiği
  - Hoca bunun ortak olasılığın çarpanlara ayrılmasından geldiğini tekrar ispatladı; bu eşitlik kovaryansın sıfır olmasının ta kendisidir.
- Entropinin mühendislikteki anlamı
  - Hoca, entropinin mühendislikte "düzensizlik" değil "bilgi miktarı" olarak anlaşılması gerektiğini vurguladı; düzensizlik tanımı fizikteki atom ve molekül dizilimi bakışından gelir.
- Markov eşitsizliği ne zaman işe yarar?
  - Bir eşitsizliği bilmek yetmez, hangi koşulda az hata verdiğini bilmek gerekir: $c$, $E[X]$'ten çok büyükken.
- Olasılık ve istatistik, makine öğrenmesi ve veri biliminin temelidir; kütüphane kullanmayı ezberlemek yerine yöntemin arkasındaki olasılık teorisini bilmek gerekir.

## Kısa Tekrar Notları

- Bağımsız $\Rightarrow$ ilişkisiz; ilişkisiz $\not\Rightarrow$ bağımsız.
- $E[aX + bY + c] = aE[X] + bE[Y] + c$.
- $X$, $Y$ bağımsız (ilişkisiz yeter) ise $\mathrm{Var}(aX + bY + c) = a^2\mathrm{Var}(X) + b^2\mathrm{Var}(Y)$.
- $\mathrm{Var}(X) = E[X^2] - (E[X])^2$.
- $\mathrm{Cov}(X,Y) = E[(X - E[X])(Y - E[Y])] = E[XY] - E[X]E[Y]$.
- $\mathrm{Cov}(X,X) = \mathrm{Var}(X)$; $\mathrm{Cov}(Y,-Y) = -\mathrm{Var}(Y)$; kovaryans negatif olabilir.
- $\rho_{X,Y} = \mathrm{Cov}(X,Y)/\sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)} \in [-1, 1]$; işaret yönü, mutlak değer gücü gösterir.
- Yüksek varyans = yüksek belirsizlik = daha fazla bilgi (entropi).
- Markov: $X \ge 0$, $c > 0$ için $\Pr(X \ge c) \le E[X]/c$; $c \gg E[X]$ iken yararlı.

## Detaylı Açıklamalar

- **İlişkisizlik ve bağımsızlık.** Ders, önceki haftadan kalan $E[XY] = E[X]E[Y]$ eşitliğiyle başladı. Hoca önce üç bağımsız değişkenin ilişkisiz olduğunu, sonra üç ilişkisiz değişkenin bağımsız olduğu iddiasının yanlış olduğunu yazdı. Korelasyonu sezgisel olarak "iki değişkenin birlikte artıp azalması ya da biri artarken diğerinin azalması" diye tanımladı ve doğadaki pek çok olayın ilişkili olduğunu söyledi.

- **$Z = aX + bY + c$ örneği.** İlk adımda beklenen değerin doğrusallığı kullanıldı: $E[Z] = E[aX + bY] + E[c] = aE[X] + bE[Y] + c$. Varyans için $E[Z^2]$ hesaplandı:
  - $E[Z^2] = E[(aX + bY)^2] + 2caE[X] + 2cbE[Y] + c^2$ (ekrandan, 00:35:00).
  - $E[(aX + bY)^2] = a^2E[X^2] + b^2E[Y^2] + 2abE[XY] = a^2E[X^2] + b^2E[Y^2] + 2abE[X]E[Y]$.
  - $(E[Z])^2 = (aE[X] + bE[Y] + c)^2$ açılıp çıkarılınca çapraz terimler ve $c$'li terimler birbirini götürür; geriye $a^2(E[X^2] - E[X]^2) + b^2(E[Y^2] - E[Y]^2)$ kalır.

- **Kovaryans ve korelasyon katsayısı.** Kovaryans, $E[XY]$ ile $E[X]E[Y]$ arasındaki farktır. Değişkenler bağımsızsa bu fark sıfırdır. Hoca $X = Y$ için kovaryansın varyansa eşit olduğunu söyleyip kovaryansı varyanslarla sınırladı ve oranın en büyük değerinin 1 olduğu sonucuna vardı. Böylece korelasyon katsayısı $-1$ ile $1$ arasında kalan, boyutsuz bir sayı olarak tanımlandı.
  - Ders sonrası not: Hoca sınırı $|\mathrm{Cov}(X,Y)| \le \max(\mathrm{Var}(X), \mathrm{Var}(Y))$ üzerinden kurdu ve her tarafı $\sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)}$'ye bölünce çıkan oranın en büyük değerinin 1 olduğunu söyledi. Ancak $\max(\mathrm{Var}(X),\mathrm{Var}(Y))/\sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)}$ oranı her zaman 1 ya da daha büyüktür (varyanslar eşitse tam 1'dir). Bu yüzden bu yol $|\rho| \le 1$ sonucunu vermez. Sonucun doğru gerekçesi Cauchy-Schwarz eşitsizliğidir: $|\mathrm{Cov}(X,Y)| \le \sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)}$.
  - Ders sonrası not: Hoca "varyans her zaman pozitiftir" dedi; doğrusu varyans negatif olmayan bir sayıdır, sabit bir değişkenin varyansı sıfırdır.

- **Varyans ve entropi.** Grafikte kırmızı ($X$) noktalar ortalamadan çok uzaklaşır, mavi ($Y$) noktalar ortalamaya yakındır. Mavinin değeri neredeyse bilinir (ortalama civarında), bu yüzden daha az bilgi taşır; kırmızının değeri belirsizdir, daha çok bilgi taşır. Hoca entropiyi "bilmediğin bilginin miktarı" diye tanımladı.

- **Markov eşitsizliği.** $\Pr(X \ge c) \le E[X]/c$. Sağ taraf 1'den büyükse eşitsizlik hiçbir şey söylemez, çünkü sol taraf zaten en çok 1'dir. Sağ taraf çok küçükse sol taraf da küçük olmak zorundadır ve iki taraf arasındaki fark azdır.
  - Ders sonrası not: Hoca $E[X]/c \ll 1$ iken $\Pr(X \ge c) \approx E[X]/c$ yazdı (ekrandan, 02:30:00). Doğru olan, iki tarafın arasındaki mutlak farkın küçük olmasıdır (ikisi de sıfıra yakındır). Oran olarak yakın olmaları gerekmez: gerçek olasılık sınırdan çok daha küçük olabilir.
  - Ders sonrası not: Hoca Markov zinciri ile Markov eşitsizliğinin genelde farklı kişilerin adını taşıdığını söyledi; büyük olasılıkla ikisi de aynı matematikçinin, Andrey Markov'un adını taşır. Kavram olarak birbirinden farklıdırlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
