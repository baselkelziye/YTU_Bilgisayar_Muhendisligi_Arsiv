# Ders 9 Çalışma Özeti

## Genel Konular

- Olasılık ve istatistik ilişkisi
  - Olasılık teorisi istatistiğin "aracı"dır (vehicle). Olasılık teorisi iyi bilinmeden istatistiksel yöntemler kurulamaz, kendi algoritmalarınız tasarlanıp uygulanamaz.
  - Olasılık, olasılıklar (popülasyon) bilindiğinde bir şeyin (bir örneğin) gerçekleşme şansını sorar (ekrandan, 00:10:00).
  - "Possibility" (Türkçesi derste "olabilirlik" diye geçti) örnek uzayla güçlü bir ilişki içindedir; zar atma deneyinin olası sonuçları gibi popülasyonun kendisinden söz eder (ekrandan, 00:15:00).
  - İstatistik bir örnek çekmeyi, onu betimlemeyi ve örnekte bulunan bilgiye dayanarak popülasyon hakkında çıkarım yapmayı ister (ekrandan, 00:15:00). İstatistik için veri gerekir.
- Önceki dersten temel tanımların tekrarı (ekrandan, 00:20:00)
  - Örnek (sample): popülasyonun bir alt kümesi.
  - Değişken (variable): popülasyonun ya da örneğin her bir elemanı hakkında ilgilenilen bir özellik.
  - Veri (data): değişken için popülasyonun ya da örneğin her elemanından toplanan değerler kümesi.
  - Deney: sonuçları bir veri kümesi veren planlı etkinlik. Parametre: bütün popülasyonun sayısal özelliği (Yunan harfleri). İstatistik (statistic): örneğin sayısal özelliği (Latin harfleri).
- Veri toplama adımları
  - i) Deneyin amaçlarını tanımlamak.
  - ii) Değişkeni ve popülasyonu tanımlamak.
  - iii) Veri toplama ve ölçme şemalarını tanımlamak: örnekleme prosedürü, örnek büyüklüğü, ölçme aracı (ekrandan, 00:25:00).
  - iv) Uygun betimsel (descriptive) ya da çıkarımsal (inferential) veri analizi tekniklerini belirlemek.
- Sayım, örnekleme çerçevesi ve örnek tasarımı
  - Sayım (census): popülasyonun her elemanını karşılık gelen veriyle birlikte listeleme prosedürü (ekrandan, 00:25:00).
  - Örnekleme çerçevesi (sampling frame): örneğin çekileceği popülasyona ait elemanların listesi; popülasyonu temsil etmelidir (ekrandan, 00:30:00).
  - Örnek tasarımı (sampling plan): örnek verisini toplamak için kullanılan prosedür. İki türü var: yargısal örnekler (judgement samples) ve olasılık örnekleri (probability samples).
  - Yargısal örnekler "tipik" olma esasına göre seçilir; toplayıcının yargısının sağlamlığını yansıtır.
  - Olasılık örneklerinde elemanlar olasılık esasına göre seçilir; istatistiksel çıkarım bunu gerektirir (ekrandan, 00:35:00).
- Olasılık örneği türleri
  - Rastgele örnek: örnekleme çerçevesinden alınabilecek $n$ büyüklüğündeki her olası örneğin seçilme olasılığı eşittir; $\Pr(S_i \text{ seçilir}) = \Pr(S_j \text{ seçilir}),\ \forall i \neq j$. Rastgele sayı üreteci kullanılabilir (ekrandan, 00:40:00).
  - Sistematik örnek: çerçevedeki her $k$'ıncı eleman seçilir; ilk eleman rastgele sayı üreteciyle belirlenir. Popülasyon tekrarlıysa (periyodikse) kullanılmamalıdır (ekrandan, 00:45:00).
  - Tabakalı örnek (stratified): çerçeve bazı özelliklere göre tabakalara (strata, tekili stratum) ayrılır ve her tabakadan sabit sayıda eleman seçilir; büyük popülasyonlarda kullanılır (ekrandan, 00:50:00).
  - Kota örneği: çerçeve tabakalara ayrılır ve her tabakadan, tabakanın büyüklüğüyle orantılı sayıda eleman seçilir (ekrandan, 00:55:00).
  - Küme örneği (cluster): çerçeve tabakalara ayrılır ve tabakaların hepsinden değil, bazılarından eleman seçilir (ekrandan, 00:55:00).
- Histogram, göreli frekans histogramı ve ampirik PDF
  - Histogram: eşit genişlikte dikdörtgenlerden oluşur; her dikdörtgenin yüksekliği, tanımlandığı aralıktaki eleman sayısıyla orantılıdır (ekrandan, 01:15:00).
  - Göreli frekans histogramı: her aralığın olasılığını (sayı / toplam örnek sayısı) gösterir; yükseklikler toplamı 1'dir.
  - Ampirik PDF: göreli frekanslar aralık genişliğine bölünür, böylece eğrinin altındaki alan 1 olur. Aralık olasılığı alanla (integralle) hesaplanır.
  - Yöntem: Veri → Histogram → Göreli frekans histogramı → Ampirik PDF. Bu, olasılık teorisini veri biliminde kullanmanın yoludur (ekrandan, 01:50:00).
- İstatistiksel çıkarım: parametreler ve tahmin ediciler
  - Dağılımların PDF'lerinin parametreleri vardır: Gauss için $\mu$, $\sigma^2$; üstel için $\lambda$; gama için $m$, $\Omega$.
  - Histogramı belli bir dağılım şeklinde olan veriden bu parametrelerin bulunması (tahmini) istatistiksel çıkarımın konusudur (kitapta 8. ve 9. bölümler).
  - Örnek ortalaması $\bar X$, örnek standart sapması $s$ ve örnek varyansı $s^2$, popülasyon parametreleri $\mu$, $\sigma$, $\sigma^2$'nin tahmin edicileridir (estimator); her biri rastgele örneğin bir fonksiyonudur (ekrandan, 02:30:00).
  - Örnek sayısı sonluysa tahmin hataları vardır: $e_1 = \bar X - \mu$, $e_2 = s - \sigma$, $e_3 = s^2 - \sigma^2$ (ekrandan, 02:40:00).
  - Yansız (unbiased) tahmin edici: $E[\hat\theta] = \theta$, yani hatanın beklenen değeri sıfır.
  - Tutarlı (consistent) tahmin edici: her $\varepsilon > 0$ için $\lim_{n\to\infty} \Pr(|\hat\theta - \theta| > \varepsilon) = 0$ (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri toplama çok önemlidir
  - İstatistik veriyle yapılır; veri sağlıklı ve güvenli toplanmazsa çıkarımlar da yanlış olur.
- Gözlenen frekansların göreli değerleri toplamı 1'dir
  - Göreli frekans histogramındaki bütün olasılıkların toplamının 1 çıkması "önemli bir gözlem" olarak vurgulandı.
- PDF'in en önemli özelliği
  - PDF negatif olmamalı ve altındaki toplam alan 1 olmalıdır. Artan fonksiyon olma özelliği PDF'in değil CDF'in özelliğidir.
- Empirical PDF ve istatistik örnekteki veriye göre konuşur
  - Elde 65 örnek varsa bulunan olasılıklar o örnek hakkındadır; gerçek olasılığa daha yakın sonuç için çok daha fazla örnek gerekir.
- Temel dağılımların PDF'leri ezbere bilinmeli
  - Hoca, özellikle Gauss dağılımının PDF'ini bilmeyen birinin mühendis sayılamayacağını, kesikli ve sürekli dağılımların PDF'lerinin "adınız gibi" bilinmesi gerektiğini söyledi.
- Parametreleri veriden bulmak
  - "$\mu$ ve $\sigma^2$, histogramı ya da ampirik PDF'i Gauss şeklinde olan veri için bulmamız gereken parametrelerdir" cümlesinin altını çizdi.
- Tahminde her zaman hata vardır
  - Örnek sayısı sonluyken tahmin kesin değildir; tam hata bilinmez ama olasılık teorisiyle analiz edilebilir.

## Kısa Tekrar Notları

- Olasılık: popülasyon biliniyor, örneğin şansı soruluyor. İstatistik: örnekten popülasyon hakkında çıkarım.
- Veri toplama: amaç → değişken ve popülasyon → toplama/ölçme şeması → analiz tekniği.
- Census = popülasyonun tamamını listeleme; sampling frame = örneğin çekileceği eleman listesi.
- Örnek tasarımı: yargısal (tipiklik esaslı) ya da olasılık (olasılık esaslı).
- Olasılık örnekleri: rastgele, sistematik (her $k$'ıncı), tabakalı (her tabakadan sabit sayı), kota (tabaka büyüklüğüyle orantılı), küme (tabakaların yalnız bir kısmından).
- CPU süresi örneği: 10 aralık, genişlik 14, frekanslar $1, 5, 9, 7, 4, 11, 5, 4, 8, 11$, toplam $N = 65$.
- Göreli frekans: $f_i / 65$, toplamı 1. Ampirik PDF yüksekliği: $f_i / (65 \cdot 14) = f_i / 910$.
- $\Pr(56 < X < 70) = 14 \cdot 4/910 = 4/65$; $\Pr(5 < X \le 46) = 233/910 \approx 0{,}26$.
- Aralık genişliği küçüldükçe ampirik PDF sürekli bir eğriye benzer.
- $\bar X \to \mu$, $s^2 \to \sigma^2$ ($|S| \to \infty$); sonlu örnekte $e_1, e_2, e_3$ hataları.
- Yansız: $E[\hat\theta] = \theta$. Tutarlı: $\Pr(|\hat\theta - \theta| > \varepsilon) \to 0$.

## Detaylı Açıklamalar

- Olasılık ve istatistiğin farkı
  - Ders, olasılık ile istatistik arasındaki farkla başladı. Olasılık, popülasyonun (olasılıkların) bilindiği durumda bir örneğin gerçekleşme şansıyla ilgilenir. İstatistik ise tersini yapar: bir örnek çekilir, betimlenir ve örnekteki bilgiye dayanarak popülasyon hakkında çıkarım yapılır. Hoca "possibility" (olabilirlik) ile "probability" (olasılık) kavramlarını karşılaştırdı: possibility örnek uzayla, yani popülasyonun olası sonuçlarıyla ilgilidir; probability bu olası sonuçlar bilindiğinde bir örneğin şansını sorar (ekrandan, 00:10:00 ve 00:15:00).
- Veri toplama ve örnekleme
  - Veri toplamanın dört adımı vardır: deneyin amaçlarını tanımlamak; değişkeni ve popülasyonu tanımlamak; veri toplama ve ölçme şemalarını (örnekleme prosedürü, örnek büyüklüğü, ölçme aracı) tanımlamak; uygun betimsel ya da çıkarımsal analiz tekniklerini belirlemek. Census popülasyonun her elemanını verisiyle listelemektir. Sampling frame ise örneğin çekileceği eleman listesidir ve popülasyonu temsil etmelidir.
  - Örnek tasarımı iki türlüdür. Yargısal örnekler, toplayıcının "tipik" saydığı elemanlardan oluşur ve toplayıcının yargısının ne kadar sağlam olduğunu yansıtır. Olasılık örneklerinde elemanlar olasılık esasına göre seçilir; istatistiksel çıkarım için gerekli olan budur.
  - Rastgele örnekte $n$ büyüklüğündeki her olası örneğin seçilme olasılığı eşittir. Hoca bunu üç tür elemandan oluşan bir popülasyonla açıkladı: rastgele örnekleme ile çok sayıda örnek alındığında her türden yaklaşık üçte bir oranında eleman gelir. <!-- BELİRSİZ: örnekteki toplam sayı altyazıda "900" ve "100" diye karışık geçiyor (00:40:30). -->
  - Sistematik örnekte çerçevedeki her $k$'ıncı eleman alınır; başlangıç elemanı rastgele sayı üreteciyle seçilir. Popülasyon tekrarlıysa seçilen elemanlar hep aynı tipe denk gelebileceği için bu yöntem kullanılmamalıdır.
  - Tabakalı örnek için hoca karınca yuvası örneğini verdi: milyonlarca karınca baş büyüklüğü, bacak uzunluğu, diş ve anten büyüklüğü gibi özelliklere göre tabakalara ayrılır; her tabakadan sabit sayıda (ör. uzun bacaklılardan bin, küçük antenlilerden yüz) karınca seçilir ve istatistikler bu örnekten hesaplanır.
  - Kota örneğinde seçilen sayı tabakanın büyüklüğüyle orantılıdır. Ekrandaki örnekte tabakaların büyüklükleri $500, 250, 250$'dir; 4 elemanlı kota örneği $2, 1, 1$, 40 elemanlı kota örneği $20, 10, 10$ elemandan oluşur (ekrandan, 00:55:00). Hoca sözlü olarak $750$ ve $250$ elemanlı iki tabakadan 4 elemanlı kota örneğinin $3$ ve $1$ eleman içereceğini de söyledi.
  - Küme örneğinde tabakaların yalnız bir kısmından eleman alınır. Ekrandaki örnekte üç özellikten yalnız birinci ve üçüncü özelliğe sahip gruplardan sırasıyla $200$ ve $100$ eleman alınmıştır (ör. 200 yaşlı, 100 çocuk).
- Histogram ve ampirik PDF
  - Kitaptaki örnekte CPU süreleri 9 saniye ile 139 saniye arasında ölçülmüştür. Aralıklar $[0,14), [14,28), [28,42), \dots$ olarak seçilir (ekrandan, 01:20:00). Aralıklardaki gözlem sayıları $1, 5, 9, 7, 4, 11, 5, 4, 8, 11$'dir, toplam $65$ (ekrandan, 01:25:00 ve 01:35:00).
  - Göreli frekans histogramında her yükseklik $f_i/65$ olur; toplamları 1'dir. Ampirik PDF için ayrıca aralık genişliği 14'e bölünür: yükseklikler $f_i/910$ olur ve toplam alan 1'e eşitlenir.
  - Bir aralığın olasılığı PDF'in o aralıktaki integralidir: $\Pr(56 < X < 70) = \int_{56}^{70} \frac{4}{910}\,dx = \frac{4 \cdot 14}{910} = \frac{4}{65}$.
  - Birden fazla aralığa yayılan olasılık parça parça hesaplanır: $\Pr(5 < X \le 46) = (14-5)\frac{1}{910} + (28-14)\frac{5}{910} + (42-28)\frac{9}{910} + (46-42)\frac{7}{910} = \frac{233}{910} \approx 0{,}26$ (ekrandan, 01:50:00).
  - Aralıklar daraltılırsa (ör. 0,1 ya da 0,001 genişlik) kutu sayısı artar ve ampirik PDF sürekli bir fonksiyona benzer. Bu ampirik PDF olasılık teorisiyle birlikte veri biliminde ve makine öğrenmesi algoritmalarında kullanılabilir. Hoca bu kısmın kitapta olmadığını belirtti.
- Parametre tahmini
  - Gauss benzeri bir histogram için $\mu$ ve $\sigma^2$; üstel benzeri histogram için $f_X(x) = \frac{1}{\lambda} e^{-x/\lambda}$, $0 < x < \infty$ (ekrandan, 02:20:00) PDF'indeki $\lambda$; gama benzeri histogram için $m$ (şekil parametresi) ve $\Omega$ (ortalama güç) veriden tahmin edilmelidir. Geometrik dağılım üstel dağılımın kesikli karşılığıdır.
  - Popülasyondan alınan rastgele örnek $S = (X_1, \dots, X_n)$ ile örnek ortalaması $\bar X = f_\mu(S)$, örnek standart sapması $s = f_\sigma(S)$ ve örnek varyansı $s^2 = f_{\sigma^2}(S)$ hesaplanır. Bunlar $\mu$, $\sigma$, $\sigma^2$'nin tahmin edicileridir. Örnek büyüklüğü sonsuza giderken $\bar X \to \mu$ ve $s^2 \to \sigma^2$ olur; sonlu örnekte $e_1, e_2, e_3$ hataları kalır. Dünyadaki insanların boy ortalaması örneğinde $\mu$ bilinemez; her ülkeden yüzer kişi alınarak $\bar X$ hesaplanır.
  - $\hat\theta = \theta + e$ yazılırsa $E[\hat\theta] = \theta + E[e]$ olur. Hatanın ortalaması sıfırsa ($E[\hat\theta] = \theta$) tahmin edici yansızdır. Tutarlılık için $\Pr(|\hat\theta - \theta| > \varepsilon) = 1 - \Pr(-\varepsilon < \hat\theta - \theta < \varepsilon)$ yazılır; büyük örnekte $\hat\theta$ kesinlikle $(\theta - \varepsilon, \theta + \varepsilon)$ aralığındaysa bu olasılık $1 - 1 = 0$ olur. Yani büyük bir örnekten tahmin yapıldığında mutlak tahmin hatasının $\varepsilon$'dan büyük olması olası değildir.
  - Ortalama ve varyansın örnekten nasıl tahmin edildiği bir sonraki derste işlenecektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
