# Ders 5 Çalışma Özeti

## Genel Konular

- Değer indirgeme (values reduction) ve öz nitelik ayrıklaştırma (feature discretization)
  - Değer indirgeme, veri indirgeme aşamasının ikinci teknik grubudur: bir öz niteliğin alabileceği ayrık değer sayısını azaltır. Bu teknikler öz nitelik ayrıklaştırma teknikleri olarak adlandırılır (ekrandan, 00:15:00).
  - Amaç, sürekli bir sayısal öz niteliğin değerlerini az sayıda aralığa bölmek ve her aralığı ayrık bir sembolle (kategorik bir etiketle) temsil etmektir.
  - Yararları: veri tanımı sadeleşir, veri ve veri madenciliği sonuçları kolay anlaşılır, ayrık değerlerle çalışan daha fazla yöntem uygulanabilir hâle gelir.
  - Önceki derslerde görülen veri düzleştirme (data smoothing) benzer bir işlemdir: değerler sıralanır, kutulara (bin) ayrılır ve her kutu bir temsilci değerle gösterilir.
  - Kutuyu sayıyla temsil etmek istenirse ortalama, medyan ya da kutu sınırları kullanılabilir; çoğunlukla kategorik etiket kullanılacaktır.
  - "Eski usul" ayrıklaştırma elle yapılır: alan uzmanı kesim noktalarını (cut-off points) öznel olarak belirler. Örnek: 0-150 arası yaş değeri çocuk, ergen, yetişkin, orta yaş ve yaşlı gibi kategorilere bölünür (ekrandan, 00:15:00).
- ChiMerge tekniği
  - ChiMerge, bir öz nitelik için aralıkların kalitesini $\chi^2$ (ki-kare) istatistiğiyle değerlendiren otomatik bir ayrıklaştırma algoritmasıdır (ekrandan, 00:20:00).
  - Komşu (adjacent) iki aralıktaki verinin sınıf dağılımlarının benzerliğine bakar. Test, sınıfın aralıklardan bağımsız olduğunu gösterirse aralıklar birleştirilir; aksi hâlde fark istatistiksel olarak anlamlıdır ve birleştirme yapılmaz.
  - Adımlar: öz nitelik sıralanır; her değer ayrı bir başlangıç aralığında olacak biçimde aralıklar tanımlanır; tüm komşu aralık çiftleri için $\chi^2$ hesaplanır; en küçük $\chi^2$ değerine sahip çift, eşik değerin altındaysa birleştirilir; işlem birleştirme kalmayana kadar tekrarlanır.
- Olumsallık (contingency) tablosu ve $\chi^2$ testi
  - İki sınıflı ($k = 2$) problemde iki aralık için $2 \times 2$ tablo kurulur: $A_{ij}$, $i$. aralıkta $j$. sınıfa ait örnek sayısıdır (ekrandan, 00:25:00).
  - $R_i$ satır toplamı ($i$. aralıktaki örnek sayısı), $C_j$ sütun toplamı ($j$. sınıftaki örnek sayısı), $N$ toplam örnek sayısıdır.
  - Beklenen frekans: $E_{ij} = \dfrac{R_i \cdot C_j}{N}$.
  - Test: $\chi^2 = \sum_{i=1}^{2}\sum_{j=1}^{k} \dfrac{(A_{ij} - E_{ij})^2}{E_{ij}}$.
  - Eşik, $\chi^2$ dağılım tablosundan serbestlik derecesine göre seçilir; örnekte $d = 1$ için eşik $2.706$ alınmıştır.
- ChiMerge örneği (12 örnekli veri)
  - Sıralı öz nitelik değerleri ve sınıfları: 1(1), 3(2), 7(1), 8(1), 9(1), 11(2), 23(2), 37(1), 39(2), 45(1), 46(1), 59(1) (ekrandan, 00:30:00).
  - Başlangıç aralık sınırları ardışık değerlerin orta noktalarıyla tahtada belirlendi: 0, 2, 5, 7.5, 8.5, 10, 17, 30, 38, 42, 45.5, 52.5, 60 (ekrandan, 00:40:00).
  - [7.5, 8.5] ve [8.5, 10] aralıkları: $\chi^2 = 0.2 < 2.706$, birleştirilir; yeni aralık [7.5, 10] olur (ekrandan, 00:45:00).
  - [0, 7.5] ve [7.5, 10] aralıkları: $\chi^2 \approx 0.83 < 2.706$, birleştirilir.
  - Sonunda üç aralık kalır: [0, 10], [10, 42], [42, 60]. [0, 10] ile [10, 42] için $\chi^2 = 2.72 > 2.706$, birleştirme önerilmez (ekrandan, 01:05:00).
- Sınıflandırmaya giriş ve Bayes teoremi
  - Derste üç sınıflandırma yöntemi işlenecek: basit Bayes (naive Bayes), karar ağaçları ve k-en yakın komşu.
  - $X$ sınıf etiketi bilinmeyen bir örnek (test örneği), $H$ ise "$X$ belirli bir $C$ sınıfına aittir" hipotezidir. Amaç $P(H \mid X)$ sonsal (posterior) olasılığını bulmaktır (ekrandan, 01:30:00).
  - Bayes teoremi: $P(H \mid X) = \dfrac{P(X \mid H)\, P(H)}{P(X)}$.
- Naive Bayes sınıflandırıcı
  - $m$ örnekli eğitim kümesi $S$; her örnek $n$ boyutlu bir öz nitelik vektörü; $k$ sınıf $C_1, \dots, C_k$.
  - Test örneği, $P(C_i \mid X)$ en büyük olan sınıfa atanır: $P(C_i \mid X) = \dfrac{P(X \mid C_i)\, P(C_i)}{P(X)}$ (ekrandan, 01:35:00).
  - $P(X)$ tüm sınıflar için sabit olduğundan yalnız $P(X \mid C_i)\, P(C_i)$ çarpımını en büyüklemek yeterlidir. $P(C_i)$ = $C_i$ sınıfındaki eğitim örneği sayısı / $m$.
  - Öz nitelikler sınıf verildiğinde koşullu bağımsız kabul edilirse: $P(X \mid C_i) = \prod_{t=1}^{n} P(x_t \mid C_i)$.
- Kategorik öz nitelikli örnek: kredi kartı promosyon verisi
  - 10 örnek; öz nitelikler dergi promosyonu, saat promosyonu, hayat sigortası promosyonu, kredi kartı sigortası; sınıf: cinsiyet (6 erkek, 4 kadın).
  - Test örneği: $F_1$ = evet, $F_2$ = evet, $F_3$ = hayır, $F_4$ = hayır.
  - $P(X \mid \text{erkek}) = \frac{4}{6}\cdot\frac{2}{6}\cdot\frac{4}{6}\cdot\frac{4}{6} = \frac{8}{81}$; $P(X \mid \text{kadın}) = \frac{3}{4}\cdot\frac{2}{4}\cdot\frac{1}{4}\cdot\frac{3}{4} = \frac{9}{128}$ (ekrandan, 02:00:00).
    <!-- BELİRSİZ: veri tablosu karelerde görünmüyor; kadınlarda dördüncü oran (3/4) tahtadaki 9/128 sonucundan çıkarıldı. -->
  - Paylar: erkek için $\frac{8}{81}\cdot\frac{6}{10} \approx 0.0593$, kadın için $\frac{9}{128}\cdot\frac{4}{10} \approx 0.0281$; test örneği büyük olasılıkla erkektir.
- Sayısal öz nitelikli örnek ve Laplace düzeltmesi: araç sigortası verisi
  - Eğitim verisi (yaş, araç tipi, risk): (25, spor, düşük), (20, klasik, yüksek), (25, spor, düşük), (45, SUV, yüksek), (20, spor, yüksek), (25, SUV, yüksek). Test örneği: yaş = 23, araç = kamyon (ekrandan, 02:25:00).
  - Sayısal öz nitelik için her sınıfın ortalaması ve standart sapması hesaplanır, sınıf normal (Gauss) dağılımla temsil edilir: $g(x) = \dfrac{1}{\sqrt{2\pi}\, s}\, e^{-\frac{(x-m)^2}{2s^2}}$ (ekrandan, 02:40:00).
  - Yüksek risk: $m = 27.5$, $s = 10.31$, $P(\text{yaş}=23 \mid \text{yüksek}) \approx 0.035$. Düşük risk: $m = 25$, $s = 0$; dağılım 25'te bir dürtüye dönüşür, $P(\text{yaş}=23 \mid \text{düşük}) = 0$ (ekrandan, 02:35:00).
  - Kamyon değeri eğitim verisinde hiç yok; bu yüzden Laplace düzeltmesi uygulanır: her sayıya 1 eklenir. Yüksek: spor 2, klasik 2, SUV 3, kamyon 1 (toplam 8); düşük: spor 3, klasik 1, SUV 1, kamyon 1 (toplam 6) (ekrandan, 02:50:00).
  - $P(\text{kamyon} \mid \text{yüksek}) = 1/8$, $P(\text{kamyon} \mid \text{düşük}) = 1/6$.
  - Sonuç: yüksek için $\frac{4}{6}\cdot 0.035 \cdot \frac{1}{8} \approx 0.003$, düşük için $0$; test örneği (23, kamyon) yüksek risk sınıfındadır (ekrandan, 02:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- ChiMerge'de her iterasyonda yalnız bir birleştirme yapılır
  - Bütün komşu aralık çiftleri için $\chi^2$ hesaplanır, en küçük değeri veren çift (eşiğin altındaysa) birleştirilir.
  - Birleşen aralığın üstündeki ve altındaki komşularla olan test sonuçları değiştiği için bir sonraki iterasyonda değerler yeniden hesaplanır.
- Beklenen frekansın sıfır çıkması
  - $E_{ij} = 0$ olursa $\chi^2$ formülünde sıfıra bölme oluşur. Çözüm olarak sıfır yerine sıfıra yakın küçük bir sayı (örnekte $0.1$; $0.01$ de olabilir) kullanılır.
- Eşik esnek seçilebilir
  - Eşik $\chi^2$ dağılımından belirlenir, ama çok fazla aralık kalırsa eşik büyütülerek daha fazla birleştirme yapılabilir ve daha geniş aralıklar elde edilir.
  - Birleştirilen aralıkların içindeki örneklerin olabildiğince aynı sınıftan olması istenir; çünkü bu aralıklar sonra sınıflandırmada kullanılacaktır.
- Naive Bayes'te $P(X)$ ile bölme yapılmaz
  - Amaç yalnız sınıfları karşılaştırmaktır; $P(X)$ bütün sınıflar için aynıdır. Bu yüzden bulunan değerlerin toplamı 1 olmaz.
- Hesaplamalarda hassasiyet
  - Normal dağılımdan çıkan olasılıklar çok küçük olduğu için ara sonuçlarda virgülden sonra dört-beş basamak tutulmalı, yuvarlama yalnız nihai sonuçta yapılmalıdır.
- Standart sapmanın sıfır çıkması
  - Örnekteki düşük risk sınıfının yalnız iki (aynı) örneği olduğu için oluşmuştur; gerçek veride beklenmez. Bir öz nitelik böyle hiç ayırt edici değilse atılabilir.

## Kısa Tekrar Notları

- Değer indirgeme = sürekli öz niteliği az sayıda aralığa bölüp her aralığa bir sembol vermek.
- Elle ayrıklaştırma: kesim noktalarını alan uzmanı belirler; ChiMerge: otomatik, $\chi^2$ tabanlı.
- ChiMerge: sırala, her değere bir başlangıç aralığı ver, komşu çiftler için $\chi^2$ hesapla, en küçüğü eşiğin altındaysa birleştir, tekrarla.
- $E_{ij} = R_i C_j / N$; $\chi^2 = \sum\sum (A_{ij} - E_{ij})^2 / E_{ij}$; $d = 1$ için eşik $2.706$.
- $\chi^2$ < eşik ise birleştir, > eşik ise birleştirme.
- $E_{ij} = 0$ ise yerine küçük bir sayı (0.1) koy.
- Naive Bayes: $P(C_i \mid X) \propto P(X \mid C_i)\, P(C_i)$; öz nitelikler koşullu bağımsız kabul edilir.
- Kategorik öz nitelik: olasılıklar sayılarak bulunur.
- Sayısal öz nitelik: sınıf ortalaması ve standart sapmasıyla Gauss yoğunluğu kullanılır.
- Eğitimde hiç görülmeyen kategorik değer için Laplace düzeltmesi: her sayıya 1 ekle.

## Detaylı Açıklamalar

- Değer indirgeme, veri indirgemenin öz nitelik ve örnek indirgemeden sonraki üçüncü boyutudur. Sürekli bir sayısal öz niteliğin çok sayıda farklı değeri, az sayıda aralığa toplanır ve her aralık bir kategoriyle gösterilir. Bu, veri düzleştirmeye benzer; farkı, ChiMerge gibi yöntemlerde aralıkların sınıf etiketlerine bakılarak oluşturulmasıdır. Elle ayrıklaştırmada alan uzmanının öznel kesim noktaları kullanılır; ChiMerge ise bunu otomatik yapar.
- ChiMerge'de önce değerler sıralanır ve ardışık değerlerin orta noktaları başlangıç aralık sınırları olur. 12 örnekli derste kullanılan veride sınırlar 0, 2, 5, 7.5, 8.5, 10, 17, 30, 38, 42, 45.5, 52.5 ve 60'tır. Sonra her komşu aralık çifti için bir $2 \times 2$ olumsallık tablosu kurulur. Örneğin [7.5, 8.5] aralığında yalnız 8 (sınıf 1), [8.5, 10] aralığında yalnız 9 (sınıf 1) vardır: $A_{11} = 1$, $A_{12} = 0$, $A_{21} = 1$, $A_{22} = 0$; $R_1 = R_2 = 1$, $C_1 = 2$, $C_2 = 0$, $N = 2$. Buradan $E_{11} = E_{21} = 1$, $E_{12} = E_{22} = 0$ bulunur. Sıfır beklenen frekanslar $0.1$ alınınca $\chi^2 = 0 + 0.1 + 0 + 0.1 = 0.2$ olur. $0.2 < 2.706$ olduğu için aralıklar [7.5, 10] olarak birleştirilir.
- Sonraki bir adımda [0, 7.5] (2 örnek sınıf 1, 1 örnek sınıf 2) ve [7.5, 10] (2 örnek sınıf 1) karşılaştırılır: $C_1 = 4$, $C_2 = 1$, $N = 5$; $E = 2.4, 0.6, 1.6, 0.4$ ve $\chi^2 \approx 0.83$ çıkar, aralıklar birleştirilir. İşlemler sürdürülünce [0, 10], [10, 42] ve [42, 60] aralıkları kalır. [0, 10] ve [10, 42] için tablo $A = \begin{bmatrix} 4 & 1 \\ 1 & 3 \end{bmatrix}$, $R = (5, 4)$, $C = (5, 4)$, $N = 9$'dur. Beklenen frekanslar $25/9 \approx 2.78$, $20/9 \approx 2.22$, $20/9 \approx 2.22$, $16/9 \approx 1.78$; $\chi^2 \approx 2.72 > 2.706$ olduğundan birleştirme önerilmez.
- Naive Bayes sınıflandırıcıda test örneği için her sınıfın sonsal olasılığı Bayes teoremiyle yazılır. Payda olan $P(X)$ bütün sınıflarda aynı olduğu için hesaplanmaz; yalnız pay karşılaştırılır. Payın içindeki $P(X \mid C_i)$, öz niteliklerin sınıf verildiğinde bağımsız olduğu varsayımıyla tek tek öz nitelik olasılıklarının çarpımına ayrılır. Bu varsayım yöntemi "naive" (saf) yapan şeydir ve olasılıkların eğitim verisinden basitçe sayılarak bulunmasını sağlar.
- Kredi kartı örneğinde 6 erkek ve 4 kadın kart kullanıcısı vardır; $P(\text{erkek}) = 6/10$, $P(\text{kadın}) = 4/10$. Test örneği (evet, evet, hayır, hayır) için erkeklerde oranlar 4/6, 2/6, 4/6, 4/6, kadınlarda 3/4, 2/4, 1/4, 3/4'tür. Çarpımlar $8/81$ ve $9/128$; önsel olasılıklarla çarpınca yaklaşık $0.0593$ ve $0.0281$ elde edilir, test örneği erkek sınıfına atanır.
- Araç sigortası örneğinde yaş sayısal, araç tipi kategoriktir. Yaş için sınıf başına Gauss dağılımı kullanılır; yüksek risk sınıfında yaşlar 20, 45, 20, 25'tir, ortalama 27.5, standart sapma 10.31'dir ve $g(23) \approx 0.035$ bulunur. Düşük risk sınıfında iki örnek de 25 olduğundan standart sapma 0'dır; dağılım 25'te bir dürtü olur ve 23 için olasılık 0'dır. Araç tipinde "kamyon" eğitim verisinde hiç geçmediği için olasılığı sıfır çıkmasın diye Laplace düzeltmesi uygulanır. Sonuçta yüksek risk için pay yaklaşık $0.003$, düşük risk için $0$ olur; test örneği yüksek risklidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
