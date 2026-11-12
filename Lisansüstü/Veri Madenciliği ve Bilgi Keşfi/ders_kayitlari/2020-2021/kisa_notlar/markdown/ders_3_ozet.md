# Ders 3 Çalışma Özeti

## Genel Konular

- Zamana bağlı veri (time-dependent data)
  - Zaman serisinde tek bir öz nitelik vardır. Bu öz niteliğin değerleri sabit zaman aralıklarıyla ölçülür. Örnek: saatte bir ölçülen hava sıcaklığı.
  - Seri $X = \{t(0), t(1), \dots, t(n)\}$ biçiminde yazılır. $t(n)$ en son ölçülen değerdir (most recent value).
  - Pek çok zaman serisi probleminde amaç, önceki değerlerden $t(n+1)$ değerini tahmin etmektir (ekrandan, 00:15:30).
  - Ön işlemenin en önemli adımı bir pencere (window) ya da zaman gecikmesi (time lag) belirlemektir. Pencere, tahmini etkileyen önceki değerlerin sayısıdır. Her pencere bir örnek (sample) olur (ekrandan, 00:15:30).
  - Slayttaki örnek: 11 ölçüm $t(0) \dots t(10)$ ve pencere boyu 5. Pencere birer kaydırılarak 6 örnek üretilir. İlk örnekte giriş $t(0) \dots t(4)$, çıkış (next value) $t(5)$; son örnekte giriş $t(5) \dots t(9)$, çıkış $t(10)$.
  - Çıkış nümerik olduğu için bu bir regresyon problemidir. Bir sonraki değeri tahmin etmek için son pencere $t(6) \dots t(10)$ girilir ve $t(11)$ tahmin edilir.
  - Çıkış birkaç adım ilerisi de olabilir: $t(n-i), \dots, t(n)$ verildiğinde $t(n+j)$ tahmin edilir. Slayttaki $j = 3$ tablosunda pencere 5 iken 4 örnek oluşur: ilk örnek $t(0) \dots t(4) \rightarrow t(7)$, son örnek $t(3) \dots t(7) \rightarrow t(10)$ (ekrandan, 00:18:40).
  - Ne kadar ileri tahmin edilirse tahmin o kadar zor ve güvenilmez olur (ekrandan, 00:20:00).
  - Problem sınıflandırmaya da çevrilebilir: $t(i+1) \geq$ eşik ise $T$, $t(i+1) <$ eşik ise $F$ gibi ikili bir çıkış kullanılır. Veri hazırlama açısından önemli bir fark yoktur (ekrandan, 00:20:00).
- Aykırı değer analizi (outlier analysis)
  - Aykırı değer, verinin genel karakteristiğine uymayan değerdir. Yanlış ölçme ya da yazım hatasından doğabilir. Örnekler: veri tabanında yaşın $-1$ girilmesi (boş alanı göstermek için), çocuk sayısının 2 yerine 25 yazılması.
  - Hata kaynaklı aykırı değerler veriden temizlenir. Verinin doğasında olan aykırı değerler ise değerlendirilmelidir, çünkü test aşamasında da karşımıza çıkar.
  - Bazı problemlerde aranan şey aykırı değerin kendisidir. Örnek: kredi kartı işlemlerinde sahtecilik tespiti.
  - Çok boyutlu veride aykırı değer bulmak zordur. Bir, iki ya da üç boyutlu veride görselleştirme işe yarar; öz nitelik sayısı üçü geçince görselleştirmeyle tespit pek mümkün değildir.
  - Slayttaki iki boyutlu çizimde 7 örnek vardır; kümeden uzakta kalan $s_3$ ve $s_5$ aykırı değer olarak işaretlenmiştir (ekrandan, 00:30:00).
- Yöntem 1: Boxplot analizi (tek değişkenli, univariate)
  - Çeyrekler: $Q_1$ (25. yüzdelik), $Q_3$ (75. yüzdelik). Çeyrekler arası açıklık $IQR = Q_3 - Q_1$ (ekrandan, 00:33:30).
  - Beş sayılı özet (five number summary): min, $Q_1$, medyan $M$, $Q_3$, max.
  - Yaygın kural: $Q_3$'ün en az $1.5 \times IQR$ üstünde ya da $Q_1$'in en az $1.5 \times IQR$ altında kalan değerler aykırı kabul edilir (ekrandan, 00:33:30).
  - Her öz niteliği kendi içinde inceler. Hoca bunu yöntemin bir eksikliği olarak gösterdi.
  - Örnek (27 yaş değeri): ortalama $\approx 29.96$, $M = 25$, $Q_1 = 20$, $Q_3 = 35$, $IQR = 15$, alt sınır $-2.5$, üst sınır $57.5$. Tek aykırı değer 70'tir (ekrandan, 00:40:00 ve 00:50:00).
- Yöntem 2: Mesafeye dayalı çözüm (çok değişkenli, multivariate)
  - Önce bütün örnek çiftleri arasındaki Öklid mesafeleri hesaplanıp bir mesafe matrisi kurulur. Bu matris $7 \times 7$, simetriktir ve köşegeni sıfırdır.
  - Mesafesi eşik değeri $d$'ye eşit ya da büyük olan örnekler "komşu olmayan" (non-neighbor) sayılır. Bir örneğin komşu olmayanlarının sayısı $p$ eşiğine eşit ya da büyükse o örnek aykırıdır. Slaytta $d \geq 3$ ve $p \geq 4$ (ekrandan, 01:12:30).
  - Örnekte $s_3$ ($p = 5$) ve $s_5$ ($p = 5$) aykırı çıkar (ekrandan, 01:30:00).
- Yöntem 3: Ortalama değere dayalı çözüm (tek değişkenli)
  - Her öz nitelik için ortalama ve standart sapma ayrı hesaplanır. Eşik: ortalama $\pm$ 2 standart sapma (ekrandan, 01:34:00).
  - Aynı 7 örnekte $x_1$ için aralık yaklaşık $[-0.29, 5.99]$, $x_2$ için $[-0.26, 6.26]$ çıkar. Hiçbir değer dışarıda değildir; aykırı değer yoktur (ekrandan, 01:40:00).
- Sınıf etiketli veride aykırı değer
  - Her sınıfın kendi merkezi (sınıf içi ortalaması) bulunur. Her örneğin kendi sınıf merkezine uzaklığına bakılır; merkeze en uzak olanlar bir eşiğe göre aykırı sayılır.
  - Sınıf etiketi yoksa bütün veri için tek bir merkez kullanılabilir.
- Veri indirgeme (data reduction)
  - Yeni slayt setinin adı "Data Mining: Data Reduction" (ekrandan, 02:05:00).
  - Bölümün hedefleri: boyutluluğun öz nitelik, örnek ve değer bazında farkı; veri indirgemenin avantajları; öz nitelik seçimi (feature selection) ve öz nitelik birleştirme (feature composition); entropiye dayalı teknik ve temel bileşen analizi (PCA); ChiMerge ve bin tabanlı teknikler (ekrandan, 02:05:00).
  - Öz nitelik çıkarma (feature extraction): ham veriden yeni öz nitelikler türetmektir. Örnekler: boy ve kilodan beden kitle indeksi; bireysel emeklilikte birikimin getirisini altın ve döviz gibi diğer yatırım araçlarının getirisiyle karşılaştıran bir öz nitelik.
  - Öz nitelik indirgeme (feature reduction) ise öz nitelik sayısı yüzlerce, doğal dil işlemede binlerce olduğunda öz nitelik sayısını azaltmaktır.
  - Düz dosya biçimindeki verinin üç boyutu vardır: sütunlar (öz nitelikler), satırlar (örnekler) ve öz nitelik değerleri. Her biri için ayrı indirgeme yapılabilir (ekrandan, 02:10:00).
  - Avantajları: hesaplama süresinde kazanç, bazen tahmin ve betimleme doğruluğunda artış, verinin daha kolay temsil edilmesi ve görselleştirilmesi.
- Veri indirgeme yöntemlerinin şeması (ekrandan, 02:20:00)
  - Feature reduction
    - Feature selection: supervised (sınıf içi ortalama ve varyansa dayalı) ve unsupervised (entropiye dayalı).
    - Feature composition: PCA.
  - Sample reduction: örnek sayısı genelde az olduğu için pek uygulanmaz; derste yöntem verilmedi.
  - Value reduction: ChiMerge tekniğiyle veri ayrıklaştırma (discretization).
- Ortalama ve varyansa dayalı eğiticili öz nitelik seçimi
  - A ve B sınıfları için her öz niteliğin sınıf içi ortalaması ve varyansı hesaplanır (ekrandan, 02:23:10):
    - $SE(A-B) = \sqrt{\mathrm{var}(A)/n_1 + \mathrm{var}(B)/n_2}$
    - TEST: $|\mathrm{mean}(A) - \mathrm{mean}(B)| \,/\, SE(A-B) > \text{eşik}$
  - Test değeri büyükse öz nitelik sınıfları ayırt etmede etkindir. Bunun için ortalamalar birbirinden uzak, varyanslar küçük olmalıdır.
  - Örnekte (6 örnek, eşik 0.5) $X$ için test eşiğin altında, $Y$ için çok üstünde çıkar. $X$ indirgeme adayıdır, $Y$ tutulur (ekrandan, 02:37:20).

## Hocanın Özellikle Vurguladığı Kısımlar

- Boxplot çiziminde bıyık uçları
  - Kabul edilebilir aralığın dışında değer yoksa bıyık en uç veri değerinde kapalı çizilir. Dışarıda değer varsa uç açık bırakılır ve aykırı değer ayrıca işaretlenir. Hoca çizimde buna dikkat edilmesini istedi.
- $1.5 \times IQR$ katsayısı sabit değildir
  - Veriye göre 1, 1.5 ya da 2 seçilebilir. Çok fazla veri aykırı çıkarsa katsayı büyütülür; düzensizlik olduğu hâlde hiç aykırı çıkmıyorsa küçültülür. Sonuca bakarak karar verilir.
- Aykırı değer oranı en fazla yaklaşık %5 olmalı
  - Hoca kendi çalışmalarında verinin %5'inden fazlasını atmanın büyük kayıp olduğunu, bundan fazlasının aykırı kabul edilmemesi gerektiğini söyledi. Örnek sayısı azsa veri kaybı daha da önemlidir.
- Tek değişkenli yöntemlerde bütün örnek silinir
  - Boxplot ya da ortalama $\pm$ 2 standart sapma yönteminde tek bir öz nitelikte sınır dışı kalan değer, o örneğin tamamının veri setinden atılmasına yol açar.
- Mesafeye dayalı (çok değişkenli) çözümler daha doğrudur
  - Öz nitelikleri birlikte değerlendiren yöntemler hocaya göre daha doğru sonuç verir; tek değişkenli yöntemler de kullanılmaya devam eder.
- Aykırı değerler bir kez belirlenir
  - Aykırı değerleri attıktan sonra ortalama, medyan ve çeyrekleri yeniden hesaplayıp tekrar aykırı aramak gerekmez. Bu, veriyi sürekli aşındırır. Eşikler başta gelen veri üzerinden belirlenir.
- Öz nitelik seçimi testinin yorumu
  - Kesrin üstü (ortalama farkı) büyük, altı (varyanslar) küçük olmalıdır. Hoca "hiçbir şeyi ezbere yapmıyoruz" diyerek bu yorumun yapılabilmesinin çok önemli olduğunu söyledi.
- Öklid mesafesi
  - En çok kullanılan mesafe olduğu için örnek Öklid mesafesiyle çözüldü.

## Kısa Tekrar Notları

- Zaman serisi: tek öz nitelik, sabit aralıklı ölçümler; amaç genelde $t(n+1)$.
- Pencere boyu $w$ ve $N$ ölçümle $t(n+1)$ için $N - w$ örnek, $t(n+j)$ için $N - w - j + 1$ örnek oluşur (11 ölçüm, $w = 5$: 6 örnek; $j = 3$: 4 örnek).
- Nümerik çıkış regresyon, eşikle ikili çıkış sınıflandırmadır.
- Aykırı değer: ölçüm hatasıysa temizle, verinin doğasındaysa değerlendir; sahtecilik tespitinde aranan şey aykırı değerdir.
- Beş sayılı özet: min, $Q_1$, $M$, $Q_3$, max. $IQR = Q_3 - Q_1$.
- Aykırı: $x < Q_1 - 1.5\,IQR$ ya da $x > Q_3 + 1.5\,IQR$.
- Mesafe tabanlı: mesafe matrisi, $d \geq 3$ olan komşu olmayanları say, sayı $\geq p$ ise aykırı.
- Ortalama tabanlı: $m \pm 2s$ dışında kalan aykırı; standart sapmada $n-1$'e bölünür.
- Boxplot ve $m \pm 2s$ tek değişkenli; mesafe tabanlı çözüm çok değişkenli.
- Veri indirgemenin üç boyutu: öz nitelik, örnek, değer.
- Feature extraction yeni öz nitelik türetir; feature reduction öz nitelik sayısını azaltır.
- Feature selection mevcut öz niteliklerden değerli olanları seçer; feature composition (PCA) öz nitelikleri birleştirip yeni bir uzay kurar.
- Öz nitelik seçimi testi: $|\bar{A} - \bar{B}| / \sqrt{\mathrm{var}(A)/n_1 + \mathrm{var}(B)/n_2}$; büyükse öz nitelik değerli.
- Çok öz nitelikte test skorları büyükten küçüğe sıralanır; eşik ya da skorların birden düştüğü yer kesme noktası olur.

## Detaylı Açıklamalar

- Zaman serisinin tabloya dönüştürülmesi
  - Veri madenciliği algoritmaları satır = örnek, sütun = öz nitelik biçiminde tablo bekler. Zaman serisi ise tek bir sayı dizisidir. Pencere yöntemi bu diziyi tabloya çevirir: her satırda pencere içindeki $w$ değer giriş öz nitelikleri (slayttaki M1–M5 sütunları), pencereden sonraki değer ise çıkıştır.
  - Pencere her seferinde bir adım kaydırılır. 11 ölçüm ve pencere 5 ile 6 satır elde edilir ve bütün satırların çıkışı bilindiği için bu bir eğitim verisidir. Eğitilen model, son beş ölçümle bir sonraki değeri tahmin eder.
  - Hocanın örneği: son 5 saatin sıcaklığından 3 saat sonrasını ya da son 5 günün en yüksek sıcaklığından 3 gün sonrasını tahmin etmek. Borsa fiyatları ve BIST 100 endeksinin yönü gibi problemler de zaman serisi üzerinde çalışılır; alım-satım robotları bu tür modeller kullanır.
  - Çıkışı low, medium, high gibi sınıflara ya da eşiğe göre $T/F$'ye çevirirsek aynı tablo bir sınıflandırma problemine dönüşür.
- Boxplot örneği (ekrandan, 00:40:00)
  - Veri (sıralı): 13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30, 33, 33, 35, 35, 35, 35, 36, 40, 45, 46, 52, 70. Eleman sayısı 27, toplam 809, ortalama $809/27 \approx 29.96$.
  - Eleman sayısı tek olduğu için medyan 14. eleman, yani 25'tir. Medyanın iki yanında 13'er eleman kalır; her yarının 7. elemanı çeyrekleri verir: $Q_1 = 20$, $Q_3 = 35$.
  - $IQR = 15$, $1.5 \times IQR = 22.5$. Alt sınır $20 - 22.5 = -2.5$; en küçük değer 13 bu sınırın içinde olduğu için alt bıyık 13'te kapatılır, altta aykırı değer yoktur.
  - Üst sınır $35 + 22.5 = 57.5$; 70 bu sınırın üstündedir. Üst uç açık bırakılır ve 70 tek aykırı değer olarak işaretlenir (ekrandan, 00:50:00).
- Mesafeye dayalı örnek (ekrandan, 01:12:30 ve 01:30:00)
  - Örnekler: $s_1 = (2,4)$, $s_2 = (3,2)$, $s_3 = (1,1)$, $s_4 = (4,3)$, $s_5 = (1,6)$, $s_6 = (5,3)$, $s_7 = (4,2)$. Hoca $s_1$'i ders sırasında $(2,4)$ olarak düzeltti; slayttaki çizimde de $s_1$ bu noktadadır (ekrandan, 00:30:00).
  - Öklid mesafesi: $d(s_i, s_j) = \sqrt{\Delta x^2 + \Delta y^2}$. Örneğin $d(s_1, s_2) = \sqrt{1^2 + 2^2} = \sqrt{5}$.
  - Mesafe matrisi (üst üçgen, tahtadan):

    ```text
          s1   s2    s3    s4    s5    s6    s7
    s1    0   √5   √10    √5    √5   √10    √8
    s2         0    √5    √2   √20    √5     1
    s3               0   √13     5   √20   √10
    s4                     0   √18     1     1
    s5                           0     5     5
    s6                                 0    √2
    s7                                       0
    ```

  - $d \geq 3$ olan komşu olmayanların sayısı: $p(s_1) = 2$, $p(s_2) = 1$, $p(s_3) = 5$, $p(s_4) = 2$, $p(s_5) = 5$, $p(s_6) = 3$, $p(s_7) = 2$. $p \geq 4$ koşulunu yalnız $s_3$ ve $s_5$ sağlar; bu ikisi aykırıdır.
  - **Ders sonrası not:** Hoca sonucu toparlarken "3 ve 7. örnekler" dedi; doğrusu, kendi saydığı değerlere göre de $s_3$ ve $s_5$'tir (01:31:44).
- Ortalama $\pm$ 2 standart sapma örneği (ekrandan, 01:40:00)
  - $x_1 = (2, 3, 1, 4, 1, 5, 4)$, $x_2 = (4, 2, 1, 3, 6, 3, 2)$. Ortalamalar $m_1 \approx 2.85$ (tam değer $20/7 \approx 2.857$), $m_2 = 3$.
  - Standart sapma $s = \sqrt{\sum_{i=1}^{7}(x_i - m)^2 / 6}$ ile $s_1 \approx 1.57$, $s_2 \approx 1.63$.
  - $x_1$ için aralık $2.85 \pm 2 \cdot 1.57 \Rightarrow [-0.29,\; 5.99]$; $x_2$ için $3 \pm 2 \cdot 1.63 \Rightarrow [-0.26,\; 6.26]$. Hiçbir değer sınır dışında değildir, aykırı değer bulunmaz.
  - Daha hassas bir analiz için katsayı 2 yerine 1.5 alınabilir; bazen 3 de kullanılır.
  - Hoca, $s_5$'in $x_2$ değeri 6 yerine 6.9 olsaydı yalnız bu boyut yüzünden bütün örneğin silineceğini hatırlattı.
- Sınıf etiketiyle çözüm
  - Derste sorulan soruya gelen cevaplardan PCA'nın sınıf etiketi kullanmadığı ve daha çok öz nitelik azaltmak için kullanıldığı belirtildi. Hocanın önerisi: her sınıfın merkezini bulmak, her örneğin kendi sınıf merkezine uzaklığını hesaplamak ve bir mesafe eşiğine göre en uzak örnekleri aykırı saymak. Birden fazla yöntemin sonucunu birleştirmek (örneğin kesişim kümesine bakmak) da mantıklı bir yol olarak kabul edildi.
- Öz nitelik seçimi örneği (ekrandan, 02:25:10 ve 02:37:20)
  - Veri: A sınıfı $(0.3, 0.7)$, $(0.6, 0.6)$, $(0.5, 0.5)$; B sınıfı $(0.2, 0.9)$, $(0.7, 0.7)$, $(0.4, 0.9)$. Eşik 0.5.
  - $X$: $\bar{X}_A = 0.4667$, $\bar{X}_B = 0.4333$; ortalamalar çok yakın, B'nin varyansı büyük, dağılımlar iç içe geçer.
  - $Y$: $\bar{Y}_A = 0.6$, $\bar{Y}_B = 0.8333$; ortalamalar ayrık, varyanslar küçük.
  - Slayttaki sonuçlar: $X$ için test $0.0735 < 0.5$, $Y$ için $2.6667 > 0.5$. $X$ indirgeme adayıdır, $Y$ ayırt edici olduğu için tutulur.
  - **Ders sonrası not:** Slaytta $\mathrm{var}(X_B) = 0.6333$ yazıyor; doğrusu $0.0633$'tür. Buna göre $SE(X_A - X_B) \approx 0.1700$ ve $X$ için test $\approx 0.196$ olur. $Y$ için kesin değerler $SE \approx 0.0882$, test $\approx 2.646$'dır. Sonuç değişmez: $X$ eşiğin altında, $Y$ üstündedir.
  - Gerçek veride 50–100 öz nitelik için bu test yapılır, skorlar büyükten küçüğe sıralanır, düşük skorlu öz nitelikler veri setinden atılır.
  - Öğrencinin Linear Discriminant Analysis benzerliği sorusuna hoca, LDA'da da sınıf içi ve sınıflar arası varyans kavramlarının kullanıldığını, burada ise öz nitelik bazında bir karşılaştırma yapıldığını ve amacın öz nitelik seçimi olduğunu söyledi. Yöntem sınıf etiketli veri gerektirir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
