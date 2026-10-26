# Ders 6 Çalışma Özeti

## Genel Konular

- Dersin tarihi 19 Kasım 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl ders yaklaşık 00:02:30'da başlar.
  - Hoca bu dersin notlarını paylaşmayacağını söyledi. Not almanız gerekiyor.
- Önceki dersin tekrarı
  - PMF, CDF, rastgele vektörler, marjinal dağılım, bağımsızlık, beklenen değer, varyans, kovaryans, korelasyon ve özellikleri.
- Sayısal örnek: İki modüllü programda hata sayıları
  - Birleşik dağılım tablosu, marjinal dağılımlar, bağımsızlık kontrolü, varyanslar ve korelasyon katsayısı.
  - Hoca soruyu bir öğrencinin isteğiyle Türkçe de açıkladı.
- Vize duyurusu
- Chebyshev eşitsizliği (Chebyshev's inequality)
  - Yazılımdaki hata sayısı örneği.
- Yaygın kesikli dağılımlara giriş
  - Bu bölümde görülecek dağılımlar: Bernoulli, binom, geometrik, negatif binom, Poisson.
  - Bernoulli denemesi (Bernoulli trial) ve Bernoulli dağılımı.
  - Binom dağılımı (binomial distribution). Hedefe atış örneği.
- Quiz 1 çözümü (ders sonunda, Türkçe)

## Hocanın Özellikle Vurguladığı Kısımlar

- Cevap yazma kuralı: Hoca dört aşamalı cevap istiyor. Bu dört aşamayı görmezse puan vermiyor.
  - 1) Aranan şeyi yazın. 2) Denklemi yazın. 3) Denklemde sayıları yerine koyun. 4) Sonucu yazın.
  - Quiz'de yalnızca sonucu yazanlara, denklemsiz ya da sayısız çözenlere puan verilmedi.
  - Denklemi bir şıkta yazıp diğer şıkta yazmayanlardan da puan kırıldı. Her şıkta denklemi yeniden yazın.
  - Toplam sembolü yerine terimleri açık yazmak ve Venn şeması kullanmak kabul edildi.
- Bağımsızlık tüm $x, y$ değerleri için sağlanmalı. Bağımsız olmadığını göstermek için tek bir karşı örnek yeter.
  - Cevabı düzgün yazın: "Bağımsız olduğunu varsayalım ... çelişki ... bağımsız değildir."
- Chebyshev eşitsizliği her rastgele değişken için geçerlidir. Yalnızca ortalama ve varyans bilindiğinde olasılığa sınır koyar. PMF biliniyorsa daha iyi sonuç alınır.
- Vize duyurusu:
  - Bir hafta sonra, aynı saatte. Çevrim içi test olarak online.yildiz.edu.tr'de yapılacak.
  - 10'dan fazla, büyük ihtimalle 20 civarında soru. Soru başına 3-5 dakika. Sorular henüz hazırlanmadı; bunlar tahmin.
  - Bu ders dahil, dersin başından beri işlenen her şey kapsamda. Binom dağılımı da dahil.
  - Kamera açmanız istenebilir. Hazırlıklı olun.

## Kısa Tekrar Notları

- Bağımsız değil göstermek: Bir $(x, y)$ için $p_{X,Y}(x,y) \neq p_X(x)\,p_Y(y)$ bulmak yeter.
- $E[XY] = \sum_x \sum_y x\,y\,p_{X,Y}(x,y)$. Birleşik olasılık kullanılır.
- Chebyshev: $P(|X - \mu| > \varepsilon) \le \dfrac{\sigma^2}{\varepsilon^2}$.
- Bernoulli: $X \sim \mathrm{Bernoulli}(p)$, $P(X=1) = p$, $P(X=0) = 1 - p = q$.
  - $E[X] = p$, $\mathrm{Var}(X) = pq$.
- Binom: $X \sim \mathrm{Bin}(n, p)$. $X$ = $n$ bağımsız Bernoulli denemesindeki başarı sayısı.
  - $P(X = x) = \binom{n}{x} p^x (1-p)^{n-x}$, $x = 0, 1, \dots, n$.
  - $E[X] = np$, $\mathrm{Var}(X) = npq$.
- Farklı kaynaklarda gösterim: $P(x; n, p)$, $\mathrm{binomial}(x; n, p)$, $B(x; n, p)$. Hepsi aynı şeydir.
- IID (independent and identically distributed): bağımsız ve özdeş dağılımlı.

## Detaylı Açıklamalar

### İki modüllü program örneği

- Program iki modülden oluşuyor. $X$ = 1. modüldeki hata sayısı, $Y$ = 2. modüldeki hata sayısı.
- Birleşik dağılım ($R_X = \{0, 1\}$, $R_Y = \{0, 1, 2, 3\}$):

| $x \backslash y$ | 0 | 1 | 2 | 3 | $p_X(x)$ |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0.20 | 0.20 | 0.05 | 0.05 | 0.50 |
| 1 | 0.20 | 0.10 | 0.10 | 0.10 | 0.50 |
| $p_Y(y)$ | 0.40 | 0.30 | 0.15 | 0.15 | 1 |

- a) Marjinal dağılımlar: Satır toplamları $p_X$, sütun toplamları $p_Y$'yi verir. Tablonun kenarına (margin) yazıldıkları için "marjinal" denir.
- b) Bağımsızlık:
  - $(0,0)$ için $0.5 \cdot 0.4 = 0.20$. Bu hücre uyuyor.
  - $(0,1)$ için $p_X(0)\,p_Y(1) = 0.5 \cdot 0.3 = 0.15 \neq 0.20$.
  - Çelişki. $X$ ve $Y$ bağımsız değildir.
- c) Beklenen değerler ve varyanslar:
  - $E[X] = 0 \cdot 0.5 + 1 \cdot 0.5 = 0.5$.
  - $E[Y] = 0 \cdot 0.4 + 1 \cdot 0.3 + 2 \cdot 0.15 + 3 \cdot 0.15 = 1.05$.
  - $\mathrm{Var}(X) = (0 - 0.5)^2 \cdot 0.5 + (1 - 0.5)^2 \cdot 0.5 = 0.25$.
  - $E[Y^2] = 0.30 + 4 \cdot 0.15 + 9 \cdot 0.15 = 2.25$. $\mathrm{Var}(Y) = 2.25 - 1.05^2 = 1.1475$.
- d) Korelasyon katsayısı:
  - $E[XY]$: Sıfır olmayan terimler yalnızca $x = 1$ satırında. $1 \cdot 1 \cdot 0.1 + 1 \cdot 2 \cdot 0.1 + 1 \cdot 3 \cdot 0.1 = 0.6$.
  - $\mathrm{Cov}(X,Y) = 0.6 - 0.5 \cdot 1.05 = 0.075$.
  - $\rho = \dfrac{0.075}{\sqrt{0.25}\,\sqrt{1.1475}} \approx 0.140$.
  - Yorum: Zayıf pozitif korelasyon.

### Chebyshev eşitsizliği örneği

- Yeni bir yazılımdaki hata sayısının beklenen değeri 20, standart sapması 2. 30'dan fazla hata olma olasılığına sınır bulun.
- PMF bilinmediği için olasılık doğrudan hesaplanamaz. Chebyshev kullanılır.
- $\varepsilon$ ortalamadan uzaklıktır: $\varepsilon = 30 - 20 = 10$.
- $P(|X - 20| > 10) \le \dfrac{4}{10^2} = 0.04$.
- Bu sınır iki kuyruğu birlikte kapsar: $X < 10$ ve $X > 30$.
- Sağ kuyruk tek başına bu toplamdan büyük olamaz: $P(X > 30) \le 0.04$.
- Öğrenci sorusu: Neden 30'dan ortalamayı çıkardık? Çünkü eşitsizlik ortalamadan uzaklıkla ifade edilir. 30 değeri ortalamadan 10 birim uzaktadır.

### Bernoulli dağılımı

- Bernoulli denemesi: İki çıktılı deney. Yazı-tura, bebeğin cinsiyeti, dersi geçip geçmemek.
- Bernoulli değişkeni çıktılardan birini 1'e (başarı, success), diğerini 0'a (başarısızlık, failure) götürür. Hangisine 1 dendiği önemli değildir. Model kurulurken seçilir.
- $E[X] = 0 \cdot (1-p) + 1 \cdot p = p$.
- $\mathrm{Var}(X) = E[X^2] - p^2 = p - p^2 = p(1-p) = pq$.

### Binom dağılımı ve hedefe atış örneği

- Parametreler: $n$ = deneme sayısı, $p$ = her denemede başarı olasılığı.
- Örnek: Hedefe 5 kez atış yapılıyor. Tek atışta isabet olasılığı 0.6. Tam 3 isabet olasılığı nedir?
  - $P(X = 3) = \binom{5}{3}\,0.6^3\,0.4^2 = 10 \cdot 0.216 \cdot 0.16 = 0.3456$.
- PMF'in mantığı:
  - 3 başarı ve 2 başarısızlık farklı sıralarda gelebilir (BBBFF, BFFBB, ...). Sıralama sayısı $\binom{5}{3}$.
  - Her sıralamanın olasılığı aynı: $0.6^3 \cdot 0.4^2$.
- Beklenen değer ve varyans:
  - $X = X_1 + X_2 + \dots + X_n$. Her $X_i$ bağımsız ve özdeş Bernoulli($p$) değişkenidir.
  - $E[X] = \sum E[X_i] = np$.
  - Denemeler bağımsız olduğu için $\mathrm{Var}(X) = \sum \mathrm{Var}(X_i) = npq$.
- Hocanın notu: Gerçekte atış yaptıkça isabet olasılığı artabilir. Model bunu yok sayar ve denemeleri özdeş kabul eder.

### Quiz 1 çözümü

- Verilen birleşik olasılıklar: $P(A_1 B_1) = 0.2$, $P(A_2 B_1) = 0.1$, $P(A_3 B_1) = 0.1$, $P(A_1 B_2) = 0.1$, $P(A_2 B_2) = 0.2$, $P(A_3 B_2) = 0.3$.
- a) Toplam olasılık: $P(A_1) = \sum_{i=1}^{2} P(A_1 \cap B_i) = 0.2 + 0.1 = 0.3$. $P(A_2) = 0.3$, $P(A_3) = 0.4$.
- b) $P(B_1) = 0.4$, $P(B_2) = 0.6$.
- c) Şartlı olasılık tanımı: $P(A_1 \mid B_1) = \dfrac{0.2}{0.4} = 0.5$, $P(A_2 \mid B_1) = \dfrac{0.1}{0.4} = 0.25$.
- d) $P(A_1 \mid A_1) = \dfrac{P(A_1 \cap A_1)}{P(A_1)} = 1$. $P(A_2 \mid A_1) = \dfrac{P(\emptyset)}{P(A_1)} = 0$, çünkü $A_i$'ler ayrık çıktılardır.
  - Kafadan "1" yazanlara puan verilmedi.
- Bağımsızlık sorusu (hoca bu şıkkı iptal edeceğini söyledi):
  - $P(A_1)\,P(B_1) = 0.3 \cdot 0.4 = 0.12 \neq 0.20 = P(A_1 \cap B_1)$. Bu yüzden $A$ ve $B$ bağımsız değildir.

### Ders sonrası notlar

- Hoca derste $\mathrm{Var}(X)$'i $0.5$ buldu ve korelasyonu yanlış çıkardı. Bunu fark etti ama dersi düzeltmeden sürdürdü. Hata, kareleri olasılıklarla çarpmamaktan geliyor: $0.25 + 0.25 = 0.5$ yazıldı. Doğrusu $0.25 \cdot 0.5 + 0.25 \cdot 0.5 = 0.25$. Bu değerle $\rho \approx 0.140$ (Python ile doğrulandı).
- Hoca $\mathrm{Var}(Y)$'yi ilk denemede yanlış hesapladı. Kitaptaki değer ve doğru sonuç $1.1475$.
- Hoca çelişki ispatının sonunda bir kez "bağımsız olduklarını ispatladık" dedi, sonra düzeltti. Sonuç: $X$ ve $Y$ bağımsız değildir.
- Chebyshev örneğinde hoca sınırı sırasıyla "0.25", "0.05" ve "0.004" diye okudu. Doğru değer $4/100 = 0.04$.
- Hoca korelasyonun "minimum değeri aslında sıfır" dedi. Bu doğru değil. Korelasyon $-1$ ile $1$ arasındadır. $0$'a yakın değer zayıf doğrusal ilişki gösterir.
- Chebyshev eşitsizliği kitaplarda çoğunlukla $P(|X - \mu| \ge \varepsilon) \le \sigma^2/\varepsilon^2$ olarak verilir. "$>$" ile yazılan hâli de doğrudur, çünkü daha küçük bir olayın olasılığıdır.
- Ders sonundaki sohbet bölümünde (yaklaşık 02:46:00 sonrası) konuşma Türkçe. Altyazı bu bölümde büyük ölçüde anlamsız ve döngülü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilirsiniz. Bu ders İngilizce anlatılmıştır; altyazı da İngilizcedir.
