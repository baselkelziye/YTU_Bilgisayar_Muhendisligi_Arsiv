# Ders 10 Çalışma Özeti

## Genel Konular

- Dersin tarihi 17 Aralık 2020 Perşembe. Ders Zoom üzerinden, İngilizce işlendi.
  - Kaydın ilk yarım saati quiz oturumudur. Öğrenciler Online YıldızEdu'da 30 dakikalık quiz'e girdi.
  - Asıl anlatım yaklaşık 00:35'te başlar.
- Önceki dersin tekrarı: örneklem ortalaması, medyan, kantiller
- Kantillerle ilgili diğer adlar
  - Yüzdelikler (percentiles)
  - Çeyrekler (quartiles): $Q_1$, $Q_2$, $Q_3$
- Ortalama ve medyana bakarak dağılımın şekli: simetrik, sağa çarpık, sola çarpık
- Merkezi eğilim ölçüleri (measures of central tendency) ve dayanıklılık (robustness)
- Yayılım ölçüleri (measures of spread)
  - Örneklem varyansı ve örneklem standart sapması; neden $n-1$'e bölündüğü
  - Standart hata (standard error)
  - Yanlılık ve standart hata kavramlarının görsel karşılaştırması
  - Çeyrekler açıklığı (interquartile range, IQR) ve aykırı değerler (outliers)
- Grafiksel istatistik
  - Histogram, kutu grafiği (box plot), zaman grafiği (time plot), saçılım grafiği (scatter plot)
  - CPU verisinin frekans ve göreli frekans histogramı

## Hocanın Özellikle Vurguladığı Kısımlar

- Yüzdelik ve çeyrek, kantilin farklı adlarıdır. Şapka ($\hat{\ }$) görürseniz değer örneklemden gelen bir tahmindir.
- Ortalama aykırı değerlerden medyana göre çok daha fazla etkilenir.
  - Çarpık dağılımda ortalama, kuyruğun uzun olduğu tarafa kayar.
- Örneklem varyansında $n$ değil, $n-1$'e bölünür. Hoca bunun nedenini merak ettiğini anlattı: $n$ kullanılırsa tahmin edici yanlı olur.
- İyi bir tahmin edici yansız, tutarlı ve asimptotik normal olmalı. Mümkünse standart hatası da düşük olmalı.
- Veriyle bir şey yapmadan önce veriyi çizip bakın. Bu öneri Baron'un kitabından geliyor.
  - Grafik; olası dağılım ailesini, aykırı değerleri, zaman eğilimlerini ve değişkenler arası ilişkileri gösterir.
- Göreli frekans histogramı, verinin olasılık dağılımı hakkında fikir verir. Hoca bunu "çok önemli" diye vurguladı.
- Aykırı değer bulunca hemen silmeyin.
  - Aykırı değer yeni bir eğilime ya da ilginç bir duruma işaret edebilir. Onu raporlayın.
  - Aykırı değerlerden çok etkilenmek istemiyorsanız dayanıklı istatistikleri (medyan, IQR) kullanın.
- İkinci vize gelecek hafta.

## Kısa Tekrar Notları

- Yüzdelik: $\gamma$-yüzdelik $\pi_\gamma$, $0.01\gamma$-kantildir. Örnek: 25. yüzdelik = 0.25-kantil.
- Çeyrekler: $Q_1 = q_{0.25}$, $Q_2 = q_{0.5}$ (medyan), $Q_3 = q_{0.75}$.
- Dağılımın şekli:
  - Simetrik: ortalama $\approx$ medyan.
  - Sağa çarpık (sağda uzun kuyruk): ortalama > medyan.
  - Sola çarpık (solda uzun kuyruk): ortalama < medyan.
- Dayanıklılık örneği:
  - $(1, 2, 3, 4, 5)$: ortalama 3, medyan 3.
  - $(1, 2, 3, 4, 500)$: ortalama 102, medyan yine 3.
- Örneklem varyansı: $s^2 = \frac{1}{n-1}\sum_{i=1}^{n}(X_i - \bar{X})^2$. Popülasyon varyansı $\sigma^2 = E[(X-\mu)^2]$'yi tahmin eder.
- Örneklem standart sapması $s = \sqrt{s^2}$, $\sigma$'yı tahmin eder.
- Standart hata: bir tahmin edicinin standart sapması. $\bar{X}$ için $\mathrm{SE}(\bar{X}) = \sigma/\sqrt{n}$.
- IQR $= Q_3 - Q_1$. Örneklem karşılığı $\widehat{\mathrm{IQR}} = \hat{Q}_3 - \hat{Q}_1$.
- Aykırı değer (Baron): $[Q_1 - 1.5\,\mathrm{IQR}, \; Q_3 + 1.5\,\mathrm{IQR}]$ aralığının dışında kalan gözlem.
- Dayanıklı istatistikler: medyan, IQR. Dayanıksız olanlar: ortalama, varyans, standart sapma.
- Histogram: veriyi sırala, kutu (bin) genişliğini ve kutuları seç, her kutudaki gözlemleri say.
  - Frekans histogramı: sayılar. Göreli frekans histogramı: sayı / $n$; toplamı 1'dir.

## Detaylı Açıklamalar

### Tekrar: örneklem kantilleri

- Örneklem $p$-kantili için: veriyi sırala, $p(n+1)$ değerini yuvarla ve o sıradaki değeri al.
- CPU verisinde ($n = 30$) $0.25 \cdot 31 = 7.75$ yuvarlanınca 8 olur. 0.25-kantil 34'tür.
- 0.5 ve 0.75 kantilleri geçen hafta ev ödevi olarak bırakılmıştı.

### Yüzdelikler ve çeyrekler

- Bunlar kantilin başka adlarıdır.
- $\gamma$-yüzdelik, $0.01\gamma$-kantildir. 25. yüzdeliği bulmak için 25'i 100'e bölüp 0.25-kantil hesaplanır.
- Yalnızca üç çeyrek vardır:
  - $Q_1$: 0.25-kantil
  - $Q_2$: 0.5-kantil, yani medyan
  - $Q_3$: 0.75-kantil
- Hepsinin popülasyon ve örneklem sürümü vardır. Örneklem sürümü şapkalı yazılır.

### Ortalama ve medyandan dağılımın şekli

- Ortalama uç değerlerden (extreme values) medyana göre daha çok etkilenir. Bu fikir hem popülasyon hem örneklem için geçerlidir.
- Simetrik dağılımda ortalama ($\mu$) ile medyan ($M$) aynıdır ya da birbirine çok yakındır.
- Bir tarafta uzun kuyruk varsa dağılım çarpıktır (skewed).
  - Ortalama kuyruk tarafına kayar, medyan daha az kayar.
  - Kuyruk sağdaysa sağa çarpık, soldaysa sola çarpık denir.

### Merkezi eğilim ölçüleri ve dayanıklılık

- Ortalama ($\mu$, tahmini $\bar{X}$) ve medyan ($M$, tahmini $\hat{M}$) dağılımın merkezini gösterir.
- Aralarındaki en büyük fark: medyan aykırı değerlere ortalamadan daha dayanıklıdır.
- Örnek:
  - $S_1 = (1, 2, 3, 4, 5)$: $\bar{X}_1 = 3$, $\hat{M}_1 = 3$.
  - $S_2 = (1, 2, 3, 4, 500)$: $\bar{X}_2 = 510/5 = 102$, $\hat{M}_2 = 3$.
  - Tek bir aykırı değer ortalamayı 3'ten 102'ye çıkarır; medyan değişmez.

### Örneklem varyansı ve standart sapma

- Popülasyon varyansı: $\mathrm{Var}(X) = \sigma^2 = E[(X - \mu)^2]$.
- Örneklem varyansında $\mu$ yerine $\bar{X}$ kullanılır ve toplam $n-1$'e bölünür.
- Neden $n$ değil?
  - $\frac{1}{n}$ kullanılırsa tahmin edici yanlı olur: beklenen değeri $\sigma^2$'ye eşit olmaz.
  - $\frac{1}{n-1}$ kullanılınca yanlılık sıfır olur. İspatı ev ödevi.
- Hocaya göre $s^2$ ve $s$ yansız, tutarlı ve asimptotik normaldir. Bu ifadenin bir kısmı için "Ders sonrası notlar"a bakın.
- Tutarlılık tekrarı: $n \to \infty$ iken hatanın seçilen bir $\varepsilon$'u aşma olasılığı sıfıra gider. Hoca tutarlılığın Chebyshev eşitsizliğinden geldiğini söyledi.

### Standart hata

- Tahminler de rastgele değişkendir. Bu yüzden onların da ortalaması ve standart sapması vardır.
- Bir tahmin edicinin standart sapmasına standart hata denir.
- Örnek: $\mathrm{SE}(\bar{X}) = \sigma/\sqrt{n}$. Ayrıca $E[\bar{X}] = \mu$.
  - Hoca bu iki sonucu öğrencilere Türkçe sorarak hatırlattı.
- İyi bir tahmin edicinin standart hatası düşük olmalıdır.

### Yanlılık ve standart hatanın görsel karşılaştırması

- Farklı örneklemlerle tekrar tekrar $\hat{\theta}$ hesapladığımızı düşünelim. Tahminler sayı doğrusunda noktalar oluşturur.
- Dört durum çizildi:
  - Tahminler birbirine yakın ama $\theta$'dan uzak: düşük standart hata, yanlı.
  - Tahminler dağınık ama merkezleri $\theta$ üzerinde: yüksek standart hata, yansız.
  - Bu ikisi "orta" durumlardır.
  - En iyi durum: tahminler birbirine yakın ve $\theta$ etrafında toplanmış (düşük standart hata, yansız).
  - En kötü durum: tahminler dağınık ve merkezleri $\theta$'dan uzak (yüksek standart hata, yanlı).

### Çeyrekler açıklığı ve aykırı değerler

- $\mathrm{IQR} = Q_3 - Q_1$. Örneklemde $\widehat{\mathrm{IQR}} = \hat{Q}_3 - \hat{Q}_1$.
- Baron'a göre aykırı değer: $Q_1$–$Q_3$ aralığının 1.5 IQR'den daha dışında kalan gözlem.
- CPU verisi örneği:
  - $\hat{Q}_1 = 34$, $\hat{Q}_3 = 59$, $\widehat{\mathrm{IQR}} = 25$, $1.5 \cdot 25 = 37.5$.
  - Üst sınır: $59 + 37.5 = 96.5$. 139 bu sınırı aşıyor, aykırı değerdir. 89 sınırın altında kalır.
  - Alt sınır: $34 - 37.5 = -3.5$. Bütün veriler bunun üstünde, solda aykırı değer yok.
- Aykırı değerle ne yapılmalı?
  - Bazıları siler, çünkü ortalama ve varyans tahminleri çok değişir.
  - Diğerleri raporlamayı önerir. Aykırı değer yeni bir eğilim olabilir. Örnek: CPU birden yavaşlamaya başladıysa sistemde bir sorun olabilir.
  - Etkilenmek istemiyorsanız medyan ve IQR kullanın.
  - IQR dayanıklıdır, çünkü hesap için veri yalnızca sıralanır ve içinden değer seçilir. Aritmetik işlem yapılmaz.

### Grafiksel istatistik ve histogram

- Grafik türleri: histogram, kutu grafiği, zaman grafiği, saçılım grafiği. Daha birçok görselleştirme vardır.
- Histogram çizme:
  - Veriyi sırala.
  - Kutu genişliğini ve kutuları seç. Bir uzlaşım belirle: alt sınır dahil, üst sınır hariç.
  - Her kutudaki gözlem sayısını say. Hoca Türkçe açıkladı: "bin" kova demek; her kovaya kaç veri düştüğünü sayıyorsunuz.
- CPU verisi, kutu genişliği 14:

| Kutu | Sayı |
| :---: | :---: |
| $[0, 14)$ | 1 |
| $[14, 28)$ | 5 |
| $[28, 42)$ | 8 |
| $[42, 56)$ | 6 |
| $[56, 70)$ | 5 |
| $[70, 84)$ | 3 |
| $[84, 98)$ | 1 |
| $[98, 112)$ | 0 |
| $[112, 126)$ | 0 |
| $[126, 140)$ | 1 |

- Frekans histogramında yükseklik sayıdır. Göreli frekans histogramında sayı $n = 30$'a bölünür: $1/30$, $5/30$, ...
  - Göreli frekansların toplamı 1'dir. Bu yüzden histogram bir olasılık dağılımına benzer; çubuklar olasılıkları tahmin eder.
- CPU histogramından çıkan sonuçlar:
  - Dağılım simetrik değil, sağa çarpık.
  - 139 açıkça aykırı görünüyor. IQR hesaplamadan da fark edilir.
  - Aykırı değer dışında veri homojen: kutular boş değil, sayılar önce artıp sonra azalıyor.
  - İyi bir model gama dağılımı olabilir. Sonra gamanın $\alpha$ ve $\lambda$ parametreleri tahmin edilebilir.

### Duyurular

- Baron'un 8. bölümünün sonuna yaklaşıldı. Gelecek hafta muhtemelen 10. bölüme geçilecek.
- Gelecek hafta ikinci vize var.

### Ders sonrası notlar

- Hoca aykırı değer tanımında iki kez "$Q_1$–$Q_2$ aralığı" ve "$Q_2$'den $Q_1$'i çıkar" dedi. Doğrusu $Q_1$–$Q_3$ aralığı ve $\mathrm{IQR} = Q_3 - Q_1$'dir.
- Histogramda hoca $[28, 42)$ kutusu için 9 gözlem dedi. Python ile sayım: bu kutuda 8 gözlem var (30, 34, 35, 35, 36, 36, 37, 38). 42, bir sonraki kutuya düşer. Bütün sayılar yukarıdaki tabloda; toplamları 30'dur.
- Son kutudaki değer altyazıda "135" ve "125" diye geçiyor. Veride bu değer 139'dur.
- Hoca $s$ ve $s^2$'nin ikisinin de yansız olduğunu söyledi. $s^2$ yansızdır ama $s$ değildir.
  - Karekök doğrusal olmadığı için $E[s] < \sigma$ olur (Jensen eşitsizliği).
  - Yanlılık $n$ büyüdükçe sıfıra gider; $s$ tutarlıdır.
- Hoca "$1/n$ kullanılırsa $n \to \infty$ iken fark sıfıra gitmez" dedi. Bu doğru değil.
  - $1/n$ ile hesaplanan varyansın beklenen değeri $\frac{n-1}{n}\sigma^2$'dir. Yanlılık $-\sigma^2/n$ olur ve $n \to \infty$ iken sıfıra gider.
  - Yani bu tahmin edici yanlıdır ama asimptotik olarak yansız ve tutarlıdır. $n-1$'e bölmek, sonlu $n$ için yanlılığı tamamen kaldırır.
- İkinci vize tarihi: 9. derste vize 17 Aralık olarak duyurulmuştu. Bu kayıtta 17 Aralık'ta bir quiz yapıldı ve hoca ikinci vizenin gelecek hafta olduğunu söyledi. 11. kayıt (24 Aralık) bir sınav oturumudur.
- Ara verme saati altyazıda "3.30 a.m." gibi bozuk geçiyor. Ders öğleden sonra yapıldığı için bu bir tanıma hatasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Bu ders İngilizce anlatıldığı için altyazı da İngilizcedir.
