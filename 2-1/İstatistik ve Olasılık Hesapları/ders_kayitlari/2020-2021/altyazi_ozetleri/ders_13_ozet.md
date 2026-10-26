# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin tarihi 7 Ocak 2021 Perşembe. Dönemin son dersidir. Ders Zoom üzerinden işlendi.
  - Önceki dersin tekrarı Türkçe, yeni konular İngilizce anlatıldı. Final duyuruları Türkçe yapıldı.
- Tekrar: parametre tahmini, momentler yöntemi, en çok olabilirlik yöntemi
- Standart hatanın tahmini (estimation of standard errors)
  - Poisson dağılımında $\hat{\lambda} = \bar{X}$ için iki farklı standart hata tahmini
  - Bootstrap yönteminin adı geçti; konu kapsam dışı.
- Güven aralıkları (confidence intervals)
  - Nokta tahmin edicileri (point estimators) ve aralık tahmini
  - Güven düzeyi (confidence level, coverage level) ve $1-\alpha$ gösterimi
  - Normal dağılan, yansız tahmin edici için güven aralığı formülünün çıkarılması
  - Standart normal kantilleri ($z_\alpha$) ve sık kullanılan değerler
  - Popülasyon ortalaması için güven aralığı; küçük örneklemde Student $t$ dağılımı
- Final sınavı duyuruları ve kitap önerisi

## Hocanın Özellikle Vurguladığı Kısımlar

- Likelihood'u maksimize etmek için logaritmasını maksimize edin. Çözümler aynı noktada çıkar.
  - Analitik çözüm yoksa problem bir optimizasyon problemine dönüşür. O zaman gradient descent gibi iteratif yöntemler gerekir. Bu derste analitik çözümü olan problemler sorulacak.
  - Sınır noktalarını unutmayın.
- İyi bir tahmin edicinin özellikleri: yansız, tutarlı, asimptotik normal ve düşük standart hatalı.
- Nokta tahminine olasılık atanamaz, çünkü sürekli dağılımda tek bir noktanın olasılığı sıfırdır. Güvenimizi bir olasılıkla ifade etmek için aralık kurulur.
- Aynı güven düzeyini veren sonsuz sayıda aralık vardır. En iyisi en dar olanıdır.
  - Normal dağılımda bu aralık ortalama etrafında simetriktir.
- Güven aralığı formülünü kullanmak için iki şart gerekir:
  - Tahmin edici yansız olmalı.
  - Tahmin edici normal dağılmalı; veri çoksa asimptotik normal olması yeterlidir.
  - Ayrıca standart hatanın bir şekilde bulunabilmesi gerekir.
- Örneklem küçükse normal yerine Student $t$ dağılımı kullanılır.
- Final konuları bu derste anlatılan son konuya kadar. Baron'un kitabında 9.2.2'ye kadar sorumlusunuz (altyazıda "9.22" diye geçiyor).

## Kısa Tekrar Notları

- Standart hata, tahmin edicinin standart sapmasıdır. Veriden tahmin edilir.
- $\bar{X}$'in standart hatası $\sigma/\sqrt{n}$. $\sigma$ bilinmiyorsa:
  - Genel yol: $\widehat{\mathrm{SE}}(\bar{X}) = s/\sqrt{n}$.
  - Poisson'a özel yol: $\mathrm{Var}(X) = \lambda$ ve $\hat{\lambda} = \bar{X}$ olduğu için $\widehat{\mathrm{SE}}(\bar{X}) = \sqrt{\bar{X}}/\sqrt{n}$.
- Güven aralığı tanımı: $P(a \le \theta \le b) = 1 - \alpha$ ise $[a, b]$, $\theta$ için $100(1-\alpha)$%'lik güven aralığıdır.
  - Örnek: $P(1.2 \le \theta \le 1.6) = 0.95$ ise $[1.2, 1.6]$ bir %95 güven aralığıdır ($\alpha = 0.05$).
- $z_\alpha$: standart normal değişkenin $\alpha$ olasılıkla aştığı değer. $z_\alpha = q_{1-\alpha} = -q_\alpha = \Phi^{-1}(1-\alpha)$.
- Sık kullanılan değerler:
  - $z_{0.10} = 1.282$
  - $z_{0.05} = 1.645$
  - $z_{0.025} = 1.960$
  - $z_{0.01} = 2.326$
  - $z_{0.005} = 2.576$
- Normal ve yansız $\hat{\theta}$ için güven aralığı: $\hat{\theta} \pm z_{\alpha/2}\,\sigma(\hat{\theta})$
  - Merkez (center): $\hat{\theta}$. Pay (margin): $z_{\alpha/2}\,\sigma(\hat{\theta})$.
- Popülasyon ortalaması $\mu$ için:
  - $\sigma$ biliniyorsa: $\bar{X} \pm z_{\alpha/2}\,\sigma/\sqrt{n}$
  - $\sigma$ bilinmiyor, örneklem büyükse: $\bar{X} \pm z_{\alpha/2}\,s/\sqrt{n}$
  - $\sigma$ bilinmiyor, örneklem küçükse: $\bar{X} \pm t_{\alpha/2}\,s/\sqrt{n}$, $t$ dağılımı $n-1$ serbestlik dereceli (degrees of freedom).

## Detaylı Açıklamalar

### Tekrar (Türkçe anlatıldı)

- Elinizdeki verinin histogramı üstel dağılıma benziyorsa, hangi üstel dağılım olduğunu $\lambda$ belirler.
  - $\lambda$'yı bulursak benzer yeni veri üretebilir veya başka hesaplar yapabiliriz.
- Momentler yöntemi: popülasyon momentleri (parametreye bağlı denklemler) ile örneklem momentleri (veriden hesaplanan sayılar) eşitlenir. Bilinmeyen sayısı kadar eşitlik yazılır ve çözülür.
  - Gama örneğinde: $\alpha/\lambda = 4$ ve $\alpha/\lambda^2 = 8/3$. Genel formülde $\hat{\lambda}$ örneklem ortalaması, örneklem varyansı ve $n$ ile yazıldı. $\hat{\lambda}$ bulunduktan sonra $\hat{\alpha}$ denklemlerden biriyle bulunur.
- En çok olabilirlik: verinin olasılığını maksimize eden parametre aranır.
  - Örnek: Örneklem $(3, 5, 6)$ ise $P(X_1 = 3, X_2 = 5, X_3 = 6)$ maksimize edilir.
  - Gözlemler bağımsızsa olasılık, tek tek olasılıkların çarpımına dönüşür.
  - Poisson örneği ev ödevi olarak kalmıştı.

### Standart hatanın tahmini

- "Tahminimiz ne kadar iyi?" sorusunun bir cevabı standart hatadır. Düşük standart hata isteriz.
- Örnek: Poisson dağılımı, $P(x) = e^{-\lambda}\lambda^x/x!$, $E[X] = \mathrm{Var}(X) = \lambda$.
  - Momentler yöntemi de en çok olabilirlik de $\hat{\lambda} = \bar{X}$ verir.
  - $\mathrm{SE}(\bar{X}) = \sigma/\sqrt{n}$. $n$ bilinir ama $\sigma$ bilinmeyebilir.
  - $\sigma$ biliniyorsa doğrudan kullanılır.
  - Bilinmiyorsa iki yol vardır:
    - Genel yol: $\sigma$ yerine örneklem standart sapması $s$ kullanılır: $s/\sqrt{n}$.
    - Poisson'a özel yol: $\sigma = \sqrt{\lambda}$ ve $\lambda$ yerine tahmini $\bar{X}$ konur: $\sqrt{\bar{X}}/\sqrt{n}$.
  - Hoca hangisinin daha iyi olduğundan emin olmadığını söyledi. Birincisi daha genel, ikincisi Poisson'a özeldir. Seçim elinizdeki bilgiye bağlıdır.
- Üçüncü bir yol bootstrap yöntemidir. Bu dönem işlenmedi; ilgilenen kitaptaki ilgili bölüme bakabilir.

### Güven aralıkları

- Momentler ve en çok olabilirlik tahmin edicileri tek bir sayı verir. Bunlara nokta tahmin edicileri denir.
- $a$ ve $b$ sayıları bulup "$\theta$'nın $a$ ile $b$ arasında olma olasılığı şudur" diyebilirsek güvenimizi bir olasılıkla ifade etmiş oluruz.
- Önce olasılık seçilir, sonra bu olasılığı veren $a$ ve $b$ bulunur.
  - %99 güven istenirse aralık geniş olur. %65 güven için aralık daha dar olur.
- Kitap olasılığı $1-\alpha$ ile gösterir. Bu gösterim ileriki konularda (hipotez testleri) işleri kolaylaştırır.
- $1-\alpha$'ya güven düzeyi veya kapsama düzeyi denir.

### En iyi aralık

- Bir dağılımda alanı $1-\alpha$ olan sonsuz sayıda aralık vardır.
- İyi aralık mümkün olduğunca dar olmalıdır. Dar aralık daha kesin bir tahmin demektir.
- Olasılık genellikle ortalama etrafında yüksektir. Bu yüzden aralık ortalama etrafında kurulur.

### Normal dağılan tahmin edici için güven aralığının çıkarılması

- Varsayımlar: $\hat{\theta}$ yansızdır ($E[\hat{\theta}] = \theta$) ve normal dağılır (veya asimptotik normaldir).
- Standartlaştırma: $Z = \frac{\hat{\theta} - \theta}{\sigma(\hat{\theta})}$ standart normal dağılır.
- Standart normal simetrik olduğu için en dar aralık simetriktir.
  - Ortadaki alan $1-\alpha$, iki kuyruğun her biri $\alpha/2$'dir.
  - Sol sınır $q_{\alpha/2}$, sağ sınır $q_{1-\alpha/2} = -q_{\alpha/2}$.
  - Örnek: $\alpha = 0.05$ için sınırlar $q_{0.025}$ ve $q_{0.975}$'tir.
- $P(q_{\alpha/2} \le Z \le -q_{\alpha/2}) = 1 - \alpha$. $Z$ yerine standartlaştırılmış ifade yazılır ve $\theta$ yalnız bırakılır.
- Kitap $q$ yerine $z$ gösterimini kullanır: $z_{\alpha/2} = -q_{\alpha/2}$.
- Sonuç: $P\left(\hat{\theta} - z_{\alpha/2}\,\sigma(\hat{\theta}) \le \theta \le \hat{\theta} + z_{\alpha/2}\,\sigma(\hat{\theta})\right) = 1 - \alpha$
- Yani $[a, b] = \hat{\theta} \pm z_{\alpha/2}\,\sigma(\hat{\theta})$, $\theta$ için $100(1-\alpha)$%'lik güven aralığıdır.
  - $\hat{\theta}$ aralığın merkezi, $z_{\alpha/2}\,\sigma(\hat{\theta})$ paydır.

### Örnek: Popülasyon ortalaması için güven aralığı

- $\mu$ için yansız ve normal dağılan bir tahmin edici gerekir: $\bar{X}$.
  - $E[\bar{X}] = \mu$, yani yansız.
  - Veri yeterliyse $\bar{X}$ normal dağılır (asimptotik normal).
- Formül: $\bar{X} \pm z_{\alpha/2}\,\sigma(\bar{X})$, burada $\sigma(\bar{X}) = \sigma/\sqrt{n}$.
  - $\bar{X}$ ve $n$ veriden hesaplanır. $z_{\alpha/2}$ standart normal tablosundan okunur.
  - $\sigma$ geçmiş verilerden biliniyorsa doğrudan kullanılır.
  - Bilinmiyorsa ve örneklem büyükse $\sigma$ yerine $s$ kullanılır: $\bar{X} \pm z_{\alpha/2}\,s/\sqrt{n}$.
- Örneklem küçükse $\sigma$ doğru tahmin edilemez. Bu durumda Student $t$ dağılımı kullanılır:
  - $\bar{X} \pm t_{\alpha/2}\,s/\sqrt{n}$
  - $t_{\alpha/2}$, $n-1$ serbestlik dereceli $t$ dağılımının kritik değeridir (critical value). Değerler tablodan okunur.
  - $t$ dağılımı da normal gibi simetriktir. Ayrıntısı derste işlenmedi; kitaptan çalışılabilir.

### Final duyuruları ve kitap önerisi

- Final, Baron'un kitabında bu derste anlatılan son konuya kadar (9.2.2) olan konuları kapsıyor.
- Öğrencilere göre final sınav programında final salı günü saat 13:00'te görünüyor. Hoca bu tarihi öğrencilerle birlikte sınav programından kontrol etti. Bu derse göre salı 12 Ocak 2021'e denk gelir.
- Final yine test olacak. Hoca soru sayısı için net bir şey söylemedi; altyazıda 15–25 civarı sayılar geçiyor.
- Öğrenciler önceki sınavda geri dönüşsüz sistemi (bir soruyu geçtikten sonra geri dönememeyi) sordu. Bir öğrenci sınavdan önce kuralların açıkça belirtilmesi gerektiğini söyledi. Bu konuşmanın büyük kısmı altyazıda anlaşılmıyor. Finalin hangi düzende olacağını sınav duyurusundan kontrol edin.
- Hoca istatistiğin, özellikle veri bilimi için çok önemli olduğunu söyledi.
- Kitap önerisi: Sheldon Ross, "Introduction to Probability Models". Hoca bunu "güzel bir kitap" diye önerdi.

### Ders sonrası notlar

- Hoca standartlaştırmayı anlatırken önce "varyansına böl" dedi, sonra "standart sapmaya" diye düzeltti. Doğrusu standart sapmaya bölmektir.
- Altyazıda üst sınır kantili "Q 0.09075" diye geçiyor. Doğrusu $q_{0.975}$'tir ($0.025 + 0.95 = 0.975$).
- Hoca $\sigma$ bilinmediğinde formülü önce "$s$ bölü $n$" diye söyledi. Doğrusu $s/\sqrt{n}$'dir.
- Popülasyon ortalaması örneğinde hoca bir yerde "popülasyon ortalamasını geçmiş verilerden biliyorsak" dedi. Kastedilen popülasyon standart sapması $\sigma$'dır. $\mu$ bilinseydi aralık kurmaya gerek kalmazdı.
- Hoca "standart hatası olmayan tahmin edici isteriz" dedi. Kastedilen, standart hatası düşük tahmin edicidir.
- $z$ değerleri Python (`statistics.NormalDist().inv_cdf`) ile kontrol edildi: $z_{0.10} = 1.2816$, $z_{0.05} = 1.6449$, $z_{0.025} = 1.9600$, $z_{0.01} = 2.3263$, $z_{0.005} = 2.5758$. Hocanın değerleri doğrudur. Altyazıda $z_{0.025}$ birkaç kez tekrarlanmış ve $z_{0.10}$ ile karışmış görünüyor; doğru eşleşme yukarıdadır.
- Bootstrap yöntemi için altyazıda "chapter 10.33" geçiyor. Bölüm numarası tanıma hatası olabilir; kitabın içindekilerinden kontrol edin.
- 00:18:04–00:20:48, 02:12:44–02:16:29 ve 02:18:20–02:25:28 arasındaki Türkçe konuşmalar İngilizce modunda bozuk çevrildi; bu kısımlarda uzun döngüler var. Özette yalnızca anlaşılır kısımlar kullanıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Bu ders İngilizce anlatıldığı için altyazı da İngilizcedir.
