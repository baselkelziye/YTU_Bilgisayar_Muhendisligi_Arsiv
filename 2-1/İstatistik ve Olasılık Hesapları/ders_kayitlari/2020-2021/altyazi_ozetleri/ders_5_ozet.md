# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin tarihi 12 Kasım 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl ders yaklaşık 00:05:20'de başlar.
  - Dersin son bölümü (yaklaşık 02:21:50'den sonra) quiz oturumudur.
- Kesikli rastgele değişkenler (discrete random variables)
  - Rastgele değişken, deneyin çıktısını bir sayıya götüren fonksiyondur.
  - Örnek: İki adil madeni para atılıyor. $X$ = yazı (heads) sayısı.
  - Değer kümesi (range) ya da destek (support): $R_X$.
- Olasılık kütle fonksiyonu (PMF) ve birikimli dağılım fonksiyonu (CDF)
  - PMF ile CDF arasında dönüşüm.
  - PMF ve CDF grafikleri. CDF basamak (step) fonksiyonudur.
- Rastgele vektörler (random vectors)
  - Birleşik dağılım (joint distribution) ve marjinal dağılım (marginal distribution).
  - Rastgele değişkenlerin bağımsızlığı.
- Beklenen değer (expectation)
  - Fonksiyonun beklenen değeri.
  - Beklenen değerin özellikleri.
- Varyans (variance) ve standart sapma (standard deviation)
  - Bir öğrencinin isteğiyle bu bölüm Türkçe olarak tekrar anlatıldı.
- Kovaryans (covariance) ve korelasyon (correlation)
  - Varyans, kovaryans ve korelasyonun özellikleri.
- Quiz 1
  - 15:30-15:59 arasında yapıldı. Cevaplar A4 kâğıda yazılıp PDF olarak Dropbox dosya isteği (file request) bağlantısına yüklendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Rastgele değişkenin değeri mutlaka bir sayıdır. "Yağmur" ya da "yazı" olamaz.
- "Dağılımı bulun" denince PMF ya da CDF istenir. Biri bilinirse diğeri bulunur.
- PMF yalnızca $R_X$'teki noktalarda sıfırdan farklıdır. CDF ise ilk değerden sonra hiçbir yerde sıfır değildir.
  - Örnek: $P(X = 0.5) = 0$, ama $F(0.5) = 1/4$.
- $E[XY] = E[X]\,E[Y]$ ve $\mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$ yalnızca bağımsızlık koşuluyla geçerlidir. Formüldeki "eğer"i unutmayın.
- Beklenen değer, varyans ve kovaryansın alternatif formüllerini evde kendiniz ispatlayın. İnternete bakmadan önce deneyin.
- Quiz kuralları:
  - Quiz'de bu dersin konusu yok. Geçen dersin konularına kadar her şey dahil.
  - Sınav 15:30'da başlar. Dropbox bağlantısı 16:00'da otomatik kapanır. 15:59'dan sonra yükleme kabul edilmez.
  - Sınav yaklaşık 15 dakikalık. Yarım saat, PDF'e çevirme ve yükleme süresi için verildi. En az 10-15 dakika önce yüklemeye başlayın.
  - E-postayla gönderilen cevap kabul edilmez. Yalnızca Dropbox bağlantısı.
  - Telefonla PDF için CamScanner gibi bir tarayıcı uygulaması önerildi.
  - İkinci kez gönderirseniz dosyaya V1, V2 gibi sürüm yazın.
- Bir sonraki sınavda kamera açmanız istenebilir. Kameranızda sorun varsa şimdiden düzeltin.

## Kısa Tekrar Notları

- PMF: $p_X(x) = P(X = x)$.
- CDF: $F_X(x) = P(X \le x) = \sum_{y \le x} p_X(y)$.
- $P(a < X \le b) = F(b) - F(a)$.
- Özellikler: $\sum_x p_X(x) = 1$, $\lim_{x \to -\infty} F(x) = 0$, $\lim_{x \to \infty} F(x) = 1$.
- Birleşik PMF: $p_{X,Y}(x,y) = P(X = x \cap Y = y)$, $\sum_x \sum_y p_{X,Y}(x,y) = 1$.
- Marjinal: $p_X(x) = \sum_y p_{X,Y}(x,y)$, $p_Y(y) = \sum_x p_{X,Y}(x,y)$.
- Bağımsızlık: Tüm $x, y$ için $p_{X,Y}(x,y) = p_X(x)\,p_Y(y)$.
- Beklenen değer: $\mu = E[X] = \sum_x x\,p(x)$. Fonksiyon için $E[g(X)] = \sum_x g(x)\,p(x)$.
- Beklenen değerin özellikleri:
  - $E[c] = c$, $E[aX] = a\,E[X]$, $E[X+Y] = E[X] + E[Y]$.
  - Bağımsızsa $E[XY] = E[X]\,E[Y]$.
  - $E[aX + bY + c] = a\,E[X] + b\,E[Y] + c$.
- Varyans: $\sigma^2 = \mathrm{Var}(X) = E[(X-\mu)^2] = E[X^2] - \mu^2$. Standart sapma: $\sigma = \sqrt{\mathrm{Var}(X)}$.
- Kovaryans: $\mathrm{Cov}(X,Y) = E[(X-\mu_X)(Y-\mu_Y)] = E[XY] - \mu_X \mu_Y$.
- Korelasyon: $\rho = \dfrac{\mathrm{Cov}(X,Y)}{\sigma_X \sigma_Y}$, $-1 \le \rho \le 1$.
- Varyans ve kovaryans özellikleri:
  - $\mathrm{Var}(c) = 0$, $\mathrm{Var}(aX + c) = a^2\,\mathrm{Var}(X)$.
  - $\mathrm{Var}(aX + bY + c) = a^2\,\mathrm{Var}(X) + b^2\,\mathrm{Var}(Y) + 2ab\,\mathrm{Cov}(X,Y)$.
  - $\mathrm{Cov}(aX + bY, cZ + dW) = ac\,\mathrm{Cov}(X,Z) + ad\,\mathrm{Cov}(X,W) + bc\,\mathrm{Cov}(Y,Z) + bd\,\mathrm{Cov}(Y,W)$.
  - $\mathrm{Cov}(aX + b, cY + d) = ac\,\mathrm{Cov}(X,Y)$.
  - Bağımsızsa $\mathrm{Cov}(X,Y) = 0$ ve $\mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$.

## Detaylı Açıklamalar

### İki madeni para örneği

- Örnek uzay: $S = \{HH, HT, TH, TT\}$. Dört çıktı eşit olasılıklı.
- $X$ = yazı sayısı. $R_X = \{0, 1, 2\}$.
- PMF:

| $x$ | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| $P(X = x)$ | 1/4 | 2/4 | 1/4 |
| $F(x)$ | 1/4 | 3/4 | 1 |

- CDF grafiği: $x < 0$ için 0. $x = 0$'da $1/4$'e, $x = 1$'de $3/4$'e, $x = 2$'de 1'e sıçrar. Sonra 1'de kalır.
- Öğrenci sorusu: $x \to -\infty$ iken CDF neden 0? Negatif değerler olamaz mı?
  - Olabilir. Bu örnekte en küçük değer 0 olduğu için 0'ın solunda CDF 0'dır. Genel kural her rastgele değişken için geçerlidir.

### Beklenen değer örneği

- $X$, 2 değerini $0.75$, 3 değerini $0.25$ olasılıkla alıyor.
- $E[X] = 2 \cdot 0.75 + 3 \cdot 0.25 = 2.25$.
- $X$ hiçbir zaman $2.25$ değerini almaz. Yorum: Deney çok kez tekrarlanırsa sonuçların ortalaması $2.25$'e yaklaşır.

### Varyansın sezgisi

- $X_1 \in \{-2, 2\}$ ve $X_2 \in \{-2000, 2000\}$. Her değerin olasılığı $1/2$.
- İkisinin de ortalaması 0. Ama $X_2$ çok daha dalgalı.
- Hesap:
  - $\mathrm{Var}(X_1) = (-2-0)^2 \cdot \frac{1}{2} + (2-0)^2 \cdot \frac{1}{2} = 4$.
  - $\mathrm{Var}(X_2) = 2000^2 = 4\,000\,000$.
- Hocanın benzetmesi: $X_1$ istikrarlı bir yatırım (ör. BIST 30), $X_2$ spekülatif bir hisse gibidir.
- Standart sapma problemle aynı birimdedir. Bu yüzden yorumlaması daha kolaydır.

### Kovaryans ve korelasyonun yorumu

- Pozitif kovaryans: $X$ artarken $Y$ de artar.
- Negatif kovaryans: $X$ artarken $Y$ azalır.
- Sıfır kovaryans: $X$ değişirken $Y$ belirgin bir yöne gitmez.
- Kovaryansın büyüklüğünü yorumlamak zordur. Korelasyon kovaryansı standart sapmalarla normalleştirir ve $[-1, 1]$ aralığına getirir.
  - 1'e yakın: güçlü pozitif ilişki. $-1$'e yakın: güçlü negatif ilişki.

### Quiz 1 oturumu

- Sorular PDF olarak Zoom sohbetinden paylaşıldı.
- Hoca 1. sorunun C şıkkında $P(A_2 \mid B_1)$'in iki kez sorulduğunu fark etti. Yalnızca $P(A_1 \mid B_1)$ ve $P(A_2 \mid B_1)$'in yapılmasını istedi. D şıkkındaki tekrar eden kısım da yapılmayacak.
- Çözümü 6. derste anlatıldı.

### Ders sonrası notlar

- Hoca CDF tanımını bir yerde "küçük ya da büyük" diye okudu. Doğrusu: $F(x) = P(X \le x)$, yani "küçük ya da eşit".
- Hoca CDF limitini önce "$x \to -\infty$ iken ... sıfıra" derken karıştırdı. Doğrusu: $x \to -\infty$ iken $F(x) \to 0$, $x \to +\infty$ iken $F(x) \to 1$.
- Hoca CDF'den PMF'e geçişi "$X$'in $a$ ile $b$ arasında olması $F(b) - F(a)$" diye verdi. Kesin ifade: $P(a < X \le b) = F(b) - F(a)$. Sol uç dahil değildir.
- Hoca beklenen değerin "en olası değeri" gösterdiğini söyledi. Bu doğru değil. En olası değer moddur (mode). Beklenen değer ağırlıklı ortalamadır. Örnekte en olası değer 2, beklenen değer $2.25$.
- Hoca sıfır kovaryansı "bağımsız değişiyorlar" diye yorumladı. Dikkat: Bağımsızlık sıfır kovaryansı gerektirir. Ama sıfır kovaryans bağımsızlığı gerektirmez. Örnek: $X \in \{-1, 0, 1\}$ eşit olasılıklı ve $Y = X^2$ ise $\mathrm{Cov}(X,Y) = 0$, ama $Y$ tamamen $X$'e bağlıdır.
- Hoca $\rho(aX + b, cY + d) = \rho(X,Y)$ dedi. Bu yalnızca $ac > 0$ ise doğrudur. Genel hâli: $\rho(aX + b, cY + d) = \mathrm{sgn}(ac)\,\rho(X,Y)$.
- Varyans sezgisi örneğinde hoca $\mathrm{Var}(X_2)$ için önce "4000" dedi. Doğrusu $2000^2 = 4\,000\,000$.
- Yaklaşık 01:44:30-01:53:40 arasındaki Türkçe tekrar bölümünde ve quiz oturumunda altyazı yer yer bozuk ve döngülü. Bu kısımlar özetlenirken yalnızca anlaşılır cümleler kullanıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilirsiniz. Bu ders İngilizce anlatılmıştır; altyazı da İngilizcedir.
