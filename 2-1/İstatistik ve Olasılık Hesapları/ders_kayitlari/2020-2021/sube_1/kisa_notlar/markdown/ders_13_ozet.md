# Ders 13 Çalışma Özeti

## Genel Konular

- Olasılık ve istatistiğin mühendislikteki yeri
  - Dersin başında iki sistemin performansını karşılaştırmak için PDF mi CDF mi kullanılacağı soruldu. Cevap CDF oldu: CDF bir aralıkta olma olasılığını verir; CDF'i daha hızlı 1'e yaklaşan sistemin performansı daha iyidir.
  - Hoca olasılık-istatistik, hesaplama kuramı, sinyal işleme ve algoritma/makine öğrenmesi derslerini mühendis ve araştırmacı için temel saydı. Makine öğrenmesi, veri madenciliği ve yapay zekanın ileri konuları olasılık-istatistik bilgisine dayanır.
- Momentler yöntemi (method of moments, MoM)
  - Varsayım: örneklem momentleri, karşılık gelen popülasyon momentlerinin iyi tahminleridir.
  - $k$. popülasyon momenti $\mu_k = E[X^k]$, $k$. örneklem momenti $m_k = \frac{1}{N}\sum_{n=1}^{N} X_n^k$.
  - Dağılımın kaç bilinmeyen parametresi varsa o kadar moment eşitlenir; bilinmeyen sayısı kadar denklem çözülür.
- Kesikli örnek: dört değerli PMF ve tek parametre $\theta$
  - $P(X=0)=\frac{2\theta}{3}$, $P(X=1)=\frac{\theta}{3}$, $P(X=2)=\frac{2(1-\theta)}{3}$, $P(X=3)=\frac{1-\theta}{3}$, $0\le\theta\le 1$ (ekrandan, 00:45:00).
  - On gözlem: $S=(3,0,2,1,3,2,1,0,2,1)$. Popülasyon ortalaması $E[X]=\frac{7-6\theta}{3}$; örneklem ortalamasına eşitlenir.
- Sürekli örnek: $f_X(x)=c(1+\theta x)$, $-1\le x\le 1$
  - Normalleştirmeden $c=\tfrac12$ bulunur; $E[X]=\theta/3$ olduğundan MoM kestiricisi örneklem ortalamasının 3 katıdır.
  - Aynı PDF için iki örneklemle $(X_1,X_2)$ en çok olabilirlik (maximum likelihood, ML) kestiricisi: $\hat\theta=-\frac{X_1+X_2}{2X_1X_2}$ (ekrandan, 01:50:00).
- Poisson dağılımı için ML kestiricisi
  - $P(X=k)=\frac{\lambda^k}{k!}e^{-\lambda}$, $k=0,1,2,\dots$
  - Bankaya belirli zaman aralıklarında gelen müşteri sayıları $0,5,1,0,6$ (ekrandan, 01:35:00). $\hat\lambda=\frac{1}{N}\sum k_n = \frac{12}{5}=2.4$.
- Veriye dağılım seçme
  - Önce histograma bakılır; Gauss'a, üstele ya da gamaya benziyorsa o aile seçilir, parametreleri veriden kestirilir.
  - Çok parametreli esnek dağılımlar her veriye uyar, ama parametre sayısı arttıkça MoM için daha çok denklem gerekir, ML hesabı da zorlaşır. Parametre sayısını küçük tutmak önemlidir.
- Z prosedürü tekrarı (önceki dersten)
  - Popülasyon varyansı $\sigma^2$ biliniyor, ortalama $\mu$ bilinmiyor. $\bar X=\frac1n\sum X_i$ kestiricidir, $\lim_{n\to\infty}\bar X=\mu$.
  - Merkezi limit teoremine göre $\bar X$ yaklaşık normaldir. $Z=\frac{\bar X-\mu}{\sigma/\sqrt n}$ standart normaldir.
  - Tek taraflı Z aralıkları $\left(-\infty,\ \bar X+\frac{\sigma}{\sqrt n}z_\alpha\right)$ ve $\left(\bar X-\frac{\sigma}{\sqrt n}z_\alpha,\ \infty\right)$; iki taraflı aralık $\bar X\pm\frac{\sigma}{\sqrt n}z_{\alpha/2}$ (ekrandan, 02:05:00).
- Güven aralığı (confidence interval)
  - Tanım: $[a,b]$, $P(a\le\theta\le b)=1-\alpha$ ise $\theta$ için $(1-\alpha)100\%$ güven aralığıdır. $1-\alpha$ kapsama olasılığı (coverage probability) ya da güven düzeyidir (ekrandan, 02:20:00).
  - Genel yapım: normal dağılımlı yansız bir kestirici $\hat\theta$ standartlaştırılır, $Z=\frac{\hat\theta-\theta}{\sigma(\hat\theta)}$; $\sigma(\hat\theta)$ standart hatadır (ekrandan, 02:25:00).
  - $z_{\alpha/2}=F_Z^{-1}(1-\alpha/2)$; ters CDF kapalı biçimde yoksa tablo kullanılır.
- Ders kitabından örnek: altı ölçümle %95 güven aralığı
  - Ölçümler $2.5, 7.4, 8.0, 4.5, 7.4, 9.2$, $\sigma=2.2$; $\bar X=6.5$, $z_{0.025}=1.96$; aralık $6.5\pm1.76=[4.74,\ 8.26]$ (ekrandan, 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Momentler yöntemi gerçek hayatta nasıl kullanılır
  - Verinin dağılımı neye benziyorsa o seçilir. Parametre sayısı kadar örneklem momenti hesaplanır ve popülasyon momentlerine eşitlenir. Denklem sistemi çözülünce PDF'in bütün parametreleri bulunmuş olur.
- Logaritma gösterimi
  - Hoca matematikte $\log$ yazıldığında doğal logaritmanın (e tabanı) kastedildiğini vurguladı: $\log(x)=\log_e(x)$, $\log_{10}(x)=\frac{\log x}{\log 10}$ (ekrandan, 01:50:00). Makale okurken bu gösterim önemlidir.
- Her soru anlamlıdır
  - Hoca "aptalca soru" diye bir şey olmadığını, her sorunun bir mantığı olduğunu söyledi.
- $\bar X$ bir rastgele değişkendir
  - Popülasyon ortalaması $\mu$ sabittir. Farklı örneklemlerden hesaplanan $\bar X$ değişir. Hoca bunu farklı şehirlerden ya da semtlerden seçilen bin kişilik grupların boy ortalamalarıyla anlattı.
- Ondalık ayırıcı
  - Sayılar virgülle yazılınca liste karışır (örn. "2,5,7,4,8,0"); hoca ondalık ayırıcı olarak nokta kullanılmasını savundu.
- Aralık genişliği ve olasılık
  - Aralık büyütülürse aralıkta olma olasılığı artar, küçültülürse azalır. Güven düzeyi ile aralık genişliği arasında bir denge vardır.

## Kısa Tekrar Notları

- MoM: $\frac1N\sum X_n^k = E[X^k]$, $k=1,\dots,$ (parametre sayısı).
- Tek parametre için birinci moment yeter: $\bar X = E[X]$.
- ML: olabilirlik $L(\theta)=\prod f(X_n;\theta)$, logaritma alınır, türev sıfıra eşitlenir.
- Poisson ML kestiricisi: $\hat\lambda=\bar k$.
- $f(x)=\tfrac12(1+\theta x)$ için: MoM $\hat\theta=3\bar X$; iki örneklemle ML $\hat\theta=-\frac{X_1+X_2}{2X_1X_2}$.
- $\bar X$ yansızdır, $\mathrm{Var}(\bar X)=\sigma^2/n$.
- İki taraflı Z aralığı: $\bar X\pm z_{\alpha/2}\,\sigma/\sqrt n$; %95 için $z_{0.025}=1.96$.
- Güven düzeyi düşerse aralık daralır: aynı örnekte %90 aralığı yaklaşık $[5.02,\ 7.98]$ olur (ders sonrası hesap).

## Detaylı Açıklamalar

- **Momentler yöntemi, kesikli örnek.** On gözlem için hocanın tahtaya yazdığı toplam 16, örneklem ortalaması $16/10$ oldu. Popülasyon ortalaması $E[X]=0\cdot\frac{2\theta}{3}+1\cdot\frac{\theta}{3}+2\cdot\frac{2(1-\theta)}{3}+3\cdot\frac{1-\theta}{3}=\frac{7-6\theta}{3}$. Eşitlik $\frac{16}{10}=\frac{7-6\theta}{3}$, yani $48=70-60\theta$ (ekrandan, 00:55:00). Hoca buradan $\theta=2/3$ buldu ve PMF'i $4/9, 2/9, 2/9, 1/9$ diye yazdı.
  - **Ders sonrası not:** $48=70-60\theta$ denkleminden $\theta=22/60=11/30\approx0.367$ çıkar, $2/3$ çıkmaz. $\theta=2/3$ için $E[X]=1$ olur, $1.6$ olmaz. Ayrıca listedeki on değerin toplamı aslında 15'tir. Derste bir öğrenci de toplamın 15 olduğunu söyledi; hoca değerlerden birini 1 yapıp toplamı 16'da bıraktı. Toplam 15 alınırsa $1.5=\frac{7-6\theta}{3}$, yani $\theta=5/12\approx0.417$ olur (python ile doğrulandı).
- **Sürekli örnek.** $\int_{-1}^{1}c(1+\theta x)\,dx=\left[cx+c\theta\frac{x^2}{2}\right]_{-1}^{1}=2c=1$, yani $c=\tfrac12$. Birinci moment $E[X]=\int_{-1}^{1}x\cdot\tfrac12(1+\theta x)\,dx=\frac{\theta}{3}$. MoM eşitliği $\frac{\theta}{3}=\bar X$ olur.
  - **Ders sonrası not:** Hoca kestiriciyi $\hat\theta=\frac{1}{3N}\sum X_i$ diye yazdı (ekrandan, 01:05:00). Doğrusu $\hat\theta=3\bar X=\frac{3}{N}\sum X_i$. Bu kestirici yansızdır, çünkü $E[\hat\theta]=3E[\bar X]=3\cdot\frac{\theta}{3}=\theta$. Hocanın vardığı sonuç da "yanlılık sıfır" oldu.
- **Aynı PDF için ML.** $L(\theta)=\tfrac12(1+\theta X_1)\cdot\tfrac12(1+\theta X_2)$, $\log L=\log\tfrac14+\log(1+\theta X_1)+\log(1+\theta X_2)$. Türev $\frac{X_1}{1+\theta X_1}+\frac{X_2}{1+\theta X_2}=0$; paydalar eşitlenince $X_1+X_2+2\theta X_1X_2=0$, buradan $\hat\theta=-\frac{X_1+X_2}{2X_1X_2}$ (ekrandan, 01:15:00 ve 01:50:00). Hoca $N$ örneklemde yöntemin aynı olduğunu, yalnız denklemin zorlaştığını söyledi.
- **Poisson ve banka örneği.** $L(\lambda)=\frac{\lambda^{k_1+\dots+k_N}}{k_1!\cdots k_N!}e^{-N\lambda}$, $\log L=\left(\sum k_n\right)\log\lambda-\log(k_1!\cdots k_N!)-N\lambda$ (ekrandan, 01:40:00). Türev $\frac{\sum k_n}{\lambda}-N=0$, yani $\hat\lambda=\frac1N\sum k_n$. Ölçümler $0,5,1,0,6$ için $\hat\lambda=12/5=2.4$. Bu $\lambda$ ile rastgele sayı üretmek, bankaya gelen müşterilerin simülasyonu gibi olur.
- **Z prosedürüyle güven aralığı.** $P(-z_{\alpha/2}<Z<z_{\alpha/2})=1-\alpha$ ve $Z=\frac{\bar X-\mu}{\sigma/\sqrt n}$ yazılınca $P\!\left(\bar X-\frac{\sigma}{\sqrt n}z_{\alpha/2}<\mu<\bar X+\frac{\sigma}{\sqrt n}z_{\alpha/2}\right)=1-\alpha$ çıkar. Ölçüm tekrarlandıkça $\bar X$ değişir ve aralıklar kayar; bunların yaklaşık $(1-\alpha)$ oranı gerçek değeri kapsar. $\alpha$'yı kullanıcı seçer: $\alpha=0.1$ %90 güven demektir.
- **Kitap örneği.** $n=6$, $\bar X=39/6=6.5$, $\alpha=0.05$, $\alpha/2=0.025$, aranan kantiller $q_{0.025}=-z_{0.025}$ ve $q_{0.975}=z_{0.025}=1.96$. Yarı genişlik $1.96\cdot\frac{2.2}{\sqrt6}\approx1.76$, aralık $[4.74,\ 8.26]$. Hoca derste önce %90 aralığının daha geniş olacağını söyledi. Sonra öğrencileri sınamak için böyle dediğini, aralık küçülünce olasılığın azaldığını söyleyerek düzeltti. Python hesabı: %90 aralığı yaklaşık $[5.02,\ 7.98]$, %95 aralığından dardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
