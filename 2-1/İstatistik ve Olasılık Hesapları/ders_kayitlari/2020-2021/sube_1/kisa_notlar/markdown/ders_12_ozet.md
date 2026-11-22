# Ders 12 Çalışma Özeti

## Genel Konular

- Yüzdelikler (percentiles)
  - Bir önceki derste görülen $p$-kantil ($x_p$, $F_X(x_p) = p$) tanımının devamıdır. $\gamma$ (ya da $\alpha$) 0 ile 100 arasında bir sayıdır; $\gamma$-yüzdelik, $\gamma/100$-kantildir (ekrandan, 00:20:00 ve 00:25:00).
  - Örnekler: 5-yüzdelik 0,05-kantil, 99-yüzdelik 0,99-kantil, 1-yüzdelik 0,01-kantildir.
  - $\gamma_p$, $X$ popülasyonunun $\gamma$-yüzdeliği olsun. Kantil tanımından $F_X(\gamma_p) = \gamma/100$ yazılır.
- Dörttebirlikler (quartiles) ve dörttebirlik açıklığı
  - 25-yüzdelik birinci dörttebirlik $Q_1$, 50-yüzdelik ikinci dörttebirlik $Q_2$ (aynı zamanda medyan $M$), 75-yüzdelik üçüncü dörttebirlik $Q_3$'tür.
  - Dörttebirlikler PDF'in altındaki alanı dört eşit parçaya böler: $A_1 = A_2 = A_3 = A_4 = 1/4 = 0{,}25$ ve $A_1 + A_2 + A_3 + A_4 = 1$ (ekrandan, 00:40:00).
  - İntegral biçimi: $\int_{-\infty}^{Q_1} f_X(x)\,dx = 0{,}25$, $\int_{-\infty}^{Q_2} f_X(x)\,dx = 0{,}5$, $\int_{Q_1}^{Q_2} f_X(x)\,dx = 0{,}25$, $\int_{-\infty}^{Q_3} f_X(x)\,dx = 0{,}75$, $\int_{Q_1}^{Q_3} f_X(x)\,dx = 0{,}5$, $\int_{Q_2}^{Q_3} f_X(x)\,dx = 0{,}25$ (ekrandan, 00:40:00).
  - Dörttebirlikler ters CDF ile bulunur: $Q_1 = F_X^{-1}(0{,}25)$, $Q_2 = F_X^{-1}(0{,}5)$, $Q_3 = F_X^{-1}(0{,}75)$.
  - Yüzdelikler de PDF'i 100 eşit alana böler.
  - Dörttebirlik açıklığı: $IQR = Q_3 - Q_1$, verinin değişkenliğini (variability) ölçer.
- Örnek: 30 CPU süresinin dörttebirlikleri
  - Veri önce sıralanır (pratikte bir sıralama algoritmasıyla). Sıralı veri (ekrandan, 00:50:00): 9, 15, 19, 22, 24, 25, 30, 34, 35, 35, 36, 36, 37, 38, 42, 43, 46, 48, 54, 55, 56, 56, 59, 62, 69, 70, 82, 82, 89, 139.
  - $n = 30$, $p = 0{,}25$ için $np = 7{,}5$. Hocanın kuralı: $\hat{Q}_1 = X_{\mathrm{round}(np)}$.
  - $\hat{Q}_1 = X_{\mathrm{round}(7{,}5)} = X_8 = 34$, $\hat{Q}_3 = X_{\mathrm{round}(22{,}5)} = X_{23} = 59$, $\hat{Q}_2 = X_{\mathrm{round}(15)} = X_{15} = 42$ (ekrandan, 00:55:00).
- Güven aralıkları (confidence intervals) ve $Z$-prosedürüne giriş
  - Tanım: $[a, b]$ aralığı, popülasyon parametresi $\theta$'yı $1-\alpha$ olasılıkla içeriyorsa $\theta$ için $(1-\alpha)100\%$ güven aralığıdır: $\Pr(a \le \theta \le b) = 1 - \alpha$ (ekrandan, 01:10:00).
  - $1-\alpha$ güven düzeyidir (confidence level). Yaygın düzeyler %90, %95 ve %99'dur; bunlara karşılık gelen $\alpha$ değerleri 0,1, 0,05 ve 0,01'dir (ekrandan, 01:20:00).
  - Popülasyon ortalaması $\mu$ için güven aralıkları büyük örneklemlerde (en az 30) uygundur. Daha küçük örneklemlerde veri yaklaşık normal dağılıyorsa yine kullanılabilir.
  - $\bar{X} = \frac{1}{n}\sum_{i=1}^{n} X_i$ için normal dağılım varsayımı geçerliyse $\mu$'nün verilen aralıkta olma olasılığı $Z$-prosedürüyle bulunur (ekrandan, 01:25:00).
  - $Z$-prosedüründe popülasyonun $\sigma$'sı bilinir, $\mu$ bilinmez. $z$-skoru: $Z = \dfrac{\bar{X} - \mu_{\bar{X}}}{\sigma_{\bar{X}}} = \dfrac{\bar{X} - \mu}{\sqrt{\sigma^2/n}} = \dfrac{(\bar{X} - \mu)\sqrt{n}}{\sigma}$, standart normal dağılır (ekrandan, 01:35:00).
  - $E[\bar{X}] = \mu$, $\mathrm{Var}(\bar{X}) = \sigma^2/n$, $\sigma_{\bar{X}} = \sigma/\sqrt{n}$ (ekrandan, 01:40:00).
  - Kritik değer $z_\alpha$ normal tablodan $\Pr(Z > z_\alpha) = \alpha$ olacak biçimde okunur.
  - İki tek taraflı $Z$-aralığı: $\left(-\infty,\ \bar{X} + \dfrac{\sigma}{\sqrt{n}} z_\alpha\right]$ ve $\left[\bar{X} - \dfrac{\sigma}{\sqrt{n}} z_\alpha,\ \infty\right)$ (ekrandan, 01:45:00). İki taraflı aralık bu derste anlatılmadı.
- İstatistiksel çıkarım (Chapter 8) ve parametre kestirimi
  - Soru: verinin histogramı Gauss'a benziyorsa $\mu$ ve $\sigma^2$, üstel dağılıma benziyorsa $\lambda$ veriden nasıl bulunur?
  - Gauss PDF'i: $f(x) = \dfrac{1}{\sqrt{2\pi\sigma^2}}\, e^{-(x-\mu)^2/(2\sigma^2)}$ (iki parametre). Üstel PDF'i: $f_X(x) = \dfrac{1}{\lambda}\exp(-x/\lambda)$, $0 < x < \infty$ (bir parametre) (ekrandan, 02:30:00).
  - İki yöntem: momentler yöntemi (method of moments) ve en çok olabilirlik yöntemi (method of maximum likelihood).
- Momentler yöntemi
  - $k$. moment $E[X^k] = \int_{-\infty}^{\infty} x^k f_X(x)\,dx$; $E[X]$ birinci moment (ortalama) (ekrandan, 02:10:00). Bunlar PDF'ten kuramsal olarak elde edilir.
  - Örneklem momentleri veriden hesaplanır: $m_k = \frac{1}{n}\sum_{i=1}^{n} X_i^k$; $m_1 = \bar{X}$.
  - $m_k$, popülasyonun $k$. gerçek momentinin kestirimidir.
  - Merkezi moment ($k \ge 2$): $\mu'_k = E[(X - E[X])^k]$ (ekrandan, 02:20:00). Örneklem merkezi momenti: $m'_k = \frac{1}{n}\sum_{i=1}^{n} (X_i - \bar{X})^k$.
  - Yöntem: $m_1 = E[X]$, $m_2 = E[X^2]$, ..., $m_k = E[X^k]$ eşitlikleri kurulup çözülür; sol taraf veriden, sağ taraf PDF'ten gelir (ekrandan, 02:25:00).
  - Denklem sayısı PDF'teki parametre sayısına eşittir. Üstel dağılımda yalnız $m_1 = E[X]$, normal dağılımda $m_1 = E[X]$ ve $m_2 = E[X^2]$ çözülür.
- En çok olabilirlik yöntemi
  - Örneklem $S = (X_1, \dots, X_n)$ verilir. Parametreler, olabilirliğin logaritmasını en büyük yapan değerlerdir: $(\hat\theta_1, \dots, \hat\theta_L) = \arg\max \log \prod_{i=1}^{n} f_X(X_i) = \arg\max \sum_{i=1}^{n} \log f_X(X_i)$ (ekrandan, 02:35:00).
  - Elde edilen ifade parametrelerin bir fonksiyonudur. En büyük yapan değer, türev alınıp sıfıra eşitlenerek bulunur (ekrandan, 02:40:00).
  - Örnek: $f_X(x) = \lambda e^{-\lambda x}$, $x > 0$. $L(\lambda) = \prod_{i=1}^{n} \lambda e^{-\lambda X_i} = \lambda^n e^{-\lambda \sum X_i}$; türev sıfıra eşitlenince $n = \lambda \sum X_i$, yani $\hat\lambda = \dfrac{n}{\sum_{i=1}^{n} X_i}$ (ekrandan, 02:45:00 ve 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Momentler yönteminde denklem sayısı parametre sayısına eşittir.
  - Hoca bunu "çok çok önemli sonuç" diye kutu içine aldı. Bilinmeyen kadar denklem gerekir.
- Örneklem momenti gerçek momentin kestirimidir.
  - $m_k$ veriden, $E[X^k]$ PDF'ten gelir. Hoca bunun çok önemli olduğunu söyledi.
- Momentler yöntemi ve en çok olabilirlik yöntemi.
  - Hoca bu iki yöntemi dersin en önemli konularından biri saydı.
- İki yöntemin karşılaştırması.
  - Momentler yöntemi basittir, kolay hesaplanır ama hatası daha büyüktür. En çok olabilirlik daha doğru, hatası daha küçük kestirim verir; ama türevden çıkan denklemleri çözmek zordur. Bu yüzden pratikte momentler yöntemi sık kullanılır.
- Örneklem ortalamasının standart sapması $\sigma/\sqrt{n}$'dir.
  - $Z$-skoru bu değerle kurulur.

## Kısa Tekrar Notları

- $\gamma$-yüzdelik = $\gamma/100$-kantil; $F_X(\gamma_p) = \gamma/100$.
- $Q_1$, $Q_2 = M$, $Q_3$: 25, 50, 75-yüzdelikler; $Q_i = F_X^{-1}(0{,}25 i)$.
- Dörttebirlikler PDF altını dört eşit alana (her biri 0,25) böler.
- $IQR = Q_3 - Q_1$ değişkenlik ölçüsüdür.
- Örneklem dörttebirliği (hocanın kuralı): $\hat{Q} = X_{\mathrm{round}(np)}$; 30 CPU süresi için $\hat{Q}_1 = 34$, $\hat{Q}_2 = 42$, $\hat{Q}_3 = 59$.
- $(1-\alpha)100\%$ güven aralığı: $\Pr(a \le \theta \le b) = 1 - \alpha$; $\alpha = 0{,}1;\ 0{,}05;\ 0{,}01$ ↔ %90, %95, %99.
- $Z = (\bar{X} - \mu)\sqrt{n}/\sigma$; $E[\bar{X}] = \mu$, $\mathrm{Var}(\bar{X}) = \sigma^2/n$.
- $\Pr(Z > z_\alpha) = \alpha$; tek taraflı aralıklar $(-\infty, \bar{X} + z_\alpha\sigma/\sqrt{n}]$ ve $[\bar{X} - z_\alpha\sigma/\sqrt{n}, \infty)$.
- Momentler yöntemi: $m_k = \frac{1}{n}\sum X_i^k = E[X^k]$, parametre sayısı kadar denklem.
- En çok olabilirlik: $\arg\max \sum \log f_X(X_i)$, her parametreye göre türev sıfıra eşitlenir.
- Üstel dağılım ($\lambda e^{-\lambda x}$) için $\hat\lambda = n / \sum X_i$.

## Detaylı Açıklamalar

- **Yüzdelik ve dörttebirlik.** Bir önceki derste $p$-kantil, CDF'nin $p$ değerini aldığı nokta olarak tanımlanmıştı. Yüzdelik aynı kavramın yüzde ile ifadesidir: $\gamma$-yüzdelik $\gamma/100$-kantildir. Dörttebirlikler özel yüzdeliklerdir: 25, 50 ve 75-yüzdelikler. Hoca bunu sağa çarpık bir PDF üzerinde gösterdi: $Q_1$, $Q_2$ ve $Q_3$ noktaları eğrinin altını dört eşit alana böler ve her alan 0,25'tir. Bu yüzden $Q_1$ ters CDF'nin 0,25'teki değeri, $Q_2$ 0,5'teki değeri (medyan), $Q_3$ 0,75'teki değeridir. Yüzdelikler de aynı mantıkla PDF'i 100 eşit alana böler. $Q_3 - Q_1$ farkı (IQR), verinin ortadaki yarısının ne kadar yayıldığını gösterir.
- **Sayısal örnek.** Hoca kitaptaki gibi bir CPU süresi verisi aldı. Önce veriyi sıraladı, sonra $n = 30$ için $np = 30 \times 0{,}25 = 7{,}5$ ve $n(1-p) = 22{,}5$ değerlerini buldu. Bu sayıları yuvarlayarak $Q_1$ için 8., $Q_3$ için 23. sıralı gözlemi aldı: $Q_1 = 34$, $Q_3 = 59$. Medyan için $n \times 0{,}5 = 15$ ile 15. gözlemi aldı: $Q_2 = 42$.
  - Ders sonrası not: Hocanın ilk yazdığı sırasız veri listesinde 27 sayı var; sıralı listede bulunan 34, 46 ve bir 82 sırasız listede yazılmamış. Hesap sıralı 30 gözlemle yapıldı ve sonuçlar bu listeye göre doğrudur (python ile kontrol edildi).
  - Ders sonrası not: Hoca medyanı $X_{15} = 42$ diye buldu. Çift sayıda gözlemde medyan genellikle iki ortadaki gözlemin ortalaması alınarak hesaplanır: $(X_{15} + X_{16})/2 = (42 + 43)/2 = 42{,}5$. Ders kitabının bu örnekte büyük olasılıkla 42,5 verdiği düşünülür.
- **Güven aralığı.** Bir popülasyonun bilinmeyen bir parametresi $\theta$ (örneğin normal dağılımda $\mu$ ve $\sigma^2$) için kestirim yapıldığında, tek bir sayı yerine bir aralık verilebilir. $[a, b]$ aralığı $\theta$'yı $1 - \alpha$ olasılıkla içeriyorsa $(1-\alpha)100\%$ güven aralığıdır. Hocanın örneğinde $\alpha = 0{,}2$ için $(1 - 0{,}2)100\% = 80\%$ olur ve $\Pr(a \le \theta \le b) = 0{,}8$ yazılır; yani parametrenin değeri %80 olasılıkla $[a, b]$ içindedir.
- **$Z$-prosedürü.** $X_i$'ler için normal varsayımı geçerliyse $\bar{X}$ da normal dağılır. Popülasyonun standart sapması $\sigma$ biliniyor, ortalaması $\mu$ bilinmiyorsa $\bar{X}$ standartlaştırılır: $Z = (\bar{X} - \mu)/(\sigma/\sqrt{n})$. Hoca burada $E[\bar{X}] = \frac{1}{n}\sum E[X_i] = \frac{1}{n} n\mu = \mu$ ve $\mathrm{Var}(\bar{X}) = \frac{1}{n^2} n\sigma^2 = \sigma^2/n$ sonuçlarını yeniden türetti; buradan $\sigma_{\bar{X}} = \sigma/\sqrt{n}$ çıkar. Kritik değer $z_\alpha$, standart normal dağılımın sağ kuyruğunda $\alpha$ alan bırakan noktadır. Buna göre iki tek taraflı aralık yazıldı. İki taraflı aralık ve sayısal örnekler sonraki derse kaldı. Hoca ikinci aradan sonra güven aralıklarına sıradan biraz önce girdiğini, konuyu sonraki derste ayrıntılandıracağını söyledi.
- **Momentler yöntemi.** Verinin histogramından PDF'in biçimi tahmin edilir (Gauss, üstel, gama gibi). Geriye parametrelerin değerini bulmak kalır. Momentler yönteminde PDF'ten kuramsal momentler ($E[X], E[X^2], \dots$), veriden örneklem momentleri ($m_1, m_2, \dots$) hesaplanır ve birbirine eşitlenir. Bilinmeyen sayısı kadar denklem kurulur. Üstel dağılımın tek parametresi vardır, yalnız $m_1 = E[X]$ yeterlidir. Normal dağılımın iki bilinmeyeni ($\mu$, $\sigma^2$) vardır, $m_1 = E[X]$ ve $m_2 = E[X^2]$ birlikte çözülür. Üç parametreli bir PDF'te ilk üç örneklem momenti ilk üç gerçek momente eşitlenir. Sonuçta empirik PDF'e (histograma) en iyi uyan PDF'in parametreleri bulunmuş olur.
  - Ders sonrası not: Hoca $m_2$ ve $m_3$'e yazarken "second/third sample mean" dedi; doğrusu ikinci/üçüncü örneklem momentidir. Ayrıca İngilizce anlatımda "üç parametre varsa beş denklem gerekir" diye bir dil sürçmesi oldu, hemen ardından Türkçe olarak "beş bilinmeyen varsa beş denklem" diye düzeltti; kural her zaman bilinmeyen sayısı kadar denklemdir.
- **En çok olabilirlik yöntemi.** Örneklemdeki her gözlemin PDF'teki değeri $f_X(X_i)$ alınır; bunların çarpımı olabilirliktir. Parametreler bu çarpımın logaritmasını en büyük yapan değerlerdir; çarpımın logaritması toplamlara dönüşür. Hoca bunu ekranda "örneklemin entropisini en küçük yapan parametreler" diye de ifade etti, yani $-\log\prod f_X(X_i)$'yi en küçük yapmak ile $\log\prod f_X(X_i)$'yi en büyük yapmak aynı şeydir. Elde edilen ifade parametrelerin fonksiyonudur; bir öğrencinin de söylediği gibi türev alınıp sıfıra eşitlenerek çözülür. Birden çok parametre varsa her parametreye göre ayrı türev alınır, sıfıra eşitlenir ve ortaya çıkan denklem sistemi birlikte çözülür.
  - Üstel örnekte $L(\lambda) = \lambda^n e^{-\lambda\sum X_i}$ ifadesinin türevi hoca tarafından doğrudan (logaritma almadan) alındı: $n\lambda^{n-1}e^{-\lambda\sum X_i} + \lambda^n(-\sum X_i)e^{-\lambda\sum X_i} = 0$. Ortak çarpanlar sadeleşince $n = \lambda\sum X_i$ ve $\hat\lambda = n/\sum X_i$ bulunur. Bu sonuç, rastgele üretilmiş bir örneklemde log-olabilirliğin sayısal olarak en büyük olduğu noktayla python ile karşılaştırılıp doğrulandı.
  - Ders sonrası not: Momentler yönteminin anlatımında üstel PDF $\frac{1}{\lambda}e^{-x/\lambda}$ ($\lambda$ = ortalama), en çok olabilirlik örneğinde ise $\lambda e^{-\lambda x}$ ($\lambda$ = oran) biçiminde yazıldı. İki örnekteki $\lambda$ farklı anlamdadır; ikincisinde $\hat\lambda = 1/\bar{X}$ olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
