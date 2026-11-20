# Ders 3 Çalışma Özeti

## Genel Konular

- Veri görselleştirme araçlarının tekrarı
  - Kutu grafiği (boxplot): medyan, birinci çeyrek (Q1) ve üçüncü çeyrek (Q3) gösterilir. Bıyıkların ucu verinin maksimumu değildir; aykırı değerler (outlier) ayrı işaretlenir.
  - Slaytlardaki örnek kodlar R ile verilmiştir. R, veri madenciliğinde (özellikle istatistik ağırlıklı çevrelerde) çok yaygındır; Python ve MATLAB'deki karşılıkları çok benzerdir.
  - Çubuk grafik (bar chart) ile histogram farkı: çubuk grafikte değer doğrudan eksenden okunur (ör. bir aydaki satış). Histogramda her çubuk bir aralığa (bin) düşen örnek sayısını, yani frekansı gösterir. Bin sayısı programda parametre olarak verilebilir ya da otomatik seçilir.
  - Saçılım grafiği (scatter plot): öznitelikler ikişer ikişer çizilerek pozitif, negatif korelasyon ya da korelasyonsuzluk görülür (ekrandan, 00:05:00).
- Öznitelikler arasındaki korelasyon
  - Bütün öznitelikler birbiriyle güçlü pozitif korelasyonlu çıkarsa hepsi aynı bilgiyi taşıyor demektir. Bu yüzden yüksek korelasyon her zaman iyi değildir.
- Benzerlik (similarity) ve farklılık (dissimilarity)
  - İki nesnenin (iki satır, iki vektör) ya da iki sütunun ne kadar benzediği ölçülür.
  - Farklılık çoğu zaman bir uzaklıktır (distance). Benzerlik genelde $[0,1]$ aralığındadır; farklılık ise $0$'dan sonsuza kadar değer alabilir.
- Tek öznitelik için benzerlik ve farklılık (ekrandan, 00:10:00)
  - Nominal: $p=q$ ise $d=0$, $s=1$; $p\neq q$ ise $d=1$, $s=0$.
  - Ordinal: değerler $0$'dan $n-1$'e tam sayılara eşlenir; $d=\frac{|p-q|}{n-1}$, $s=1-\frac{|p-q|}{n-1}$.
  - Aralık (interval) ya da oran (ratio): $d=|p-q|$; benzerlik $s=-d$, $s=\frac{1}{1+d}$ ya da $s=1-\frac{d-\min_d}{\max_d-\min_d}$.
- Öklid, Minkowski ve Manhattan uzaklıkları
  - Öklid uzaklığı: farkların karelerinin toplamının karekökü. Değeri $0$-$1$ aralığında olmak zorunda değildir.
  - Minkowski uzaklığı Öklid'in genellemesidir: $r=1$ Manhattan ($L_1$ normu), $r=2$ Öklid ($L_2$ normu), $r\to\infty$ limit durumu.
- Metrik olma koşulları
  - Pozitiflik, simetri ve üçgen eşitsizliği. Öklid uzaklığı üçünü de sağlar, yani bir metriktir.
  - Benzerliklerde genelde pozitiflik ($s(x,y)=1$ ancak $x=y$ iken, $0\le s\le 1$) ve simetri sağlanır, üçgen eşitsizliği genelde sağlanmaz (ekrandan, 00:15:00).
- İkili (binary) veride benzerlik: SMC ve Jaccard
  - $f_{00}, f_{01}, f_{10}, f_{11}$ sayıları üzerinden tanımlanır.
  - SMC tüm eşleşmeleri sayar; Jaccard asimetrik ikili veri içindir ve 0-0 eşleşmelerini yok sayar.
  - Jaccard katsayısı görüntü bölütlemede (ör. araba maskesi) bulunan bölge ile gerçek bölgenin örtüşmesini ölçmek için çok kullanılır.
- Kosinüs benzerliği
  - İki vektör arasındaki açının kosinüsü: iç çarpım bölü $L_2$ normlarının çarpımı. Değer $[-1,1]$ aralığındadır; aynı yöndeki vektörlerde $1$ olur.
- Pearson korelasyonu (ekrandan, 00:25:00)
  - Kovaryansın standart sapmaların çarpımına bölümüdür. $+1$ pozitif doğrusal, $-1$ negatif doğrusal ilişki, $0$ doğrusal ilişki yok demektir.
  - Yalnız doğrusal ilişkiyi yakalar; doğrusal olmayan ilişkiyi göstermez.
- Ölçü seçimi ve farklı tipteki öznitelikleri birleştirme (ekrandan, 00:30:00)
  - Ölçü seçimi veriye ve uygulamaya bağlıdır.
  - Farklı tipteki öznitelikler için her özniteliğin benzerliği $[0,1]$ aralığında hesaplanır ve gösterge değişkeni $\delta_k$ ile ağırlıklı ortalaması alınır.
- Entropi
  - Verinin ne kadar bilgi taşıdığını gösterir; ileride karar ağaçları entropi üzerine kurulacaktır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bar chart ile histogram aynı şey değildir
  - Histogramda dikey eksen frekanstır: bir aralığa kaç örnek düştüğünü gösterir.
- Özniteliklerin hepsinin birbiriyle korelasyonlu olması istenmez
  - Hepsi aynı şeyi söylüyorsa yeni bilgi taşımazlar.
- Uzaklığın metrik olması için üç koşul
  - Pozitiflik, simetri, üçgen eşitsizliği. Hoca Öklid uzaklığının bu üçünü sağladığını sınıfla birlikte göstermiştir.
- Jaccard katsayısının asimetrik ikili veride kullanılması
  - 0-0 eşleşmeleri (ör. görüntüde araba olmayan arka plan pikselleri) hesaba katılmaz; böylece benzerlik yapay olarak yüksek çıkmaz.
- Korelasyon önemlidir ama yalnız doğrusal ilişkiyi gösterir
  - Korelasyonun sıfır çıkması iki değişken arasında hiç ilişki olmadığı anlamına gelmez.
- En çok kullanılan ölçüler
  - Genelde Öklid uzaklığı; veri pozitifse (ör. metin madenciliği) kosinüs.
- Kosinüs uzaklığı metrik midir? (ders sonunda düşünülmek üzere bırakılan soru)

## Kısa Tekrar Notları

- Boxplot: medyan, Q1, Q3; bıyık ucu maksimum değildir, aykırı değerler ayrı gösterilir.
- Histogram: aralık başına frekans; bar chart: doğrudan değer.
- Nominal: aynıysa $d=0$, farklıysa $d=1$.
- Ordinal: $d=\frac{|p-q|}{n-1}$; küçük/orta/büyük = 0/1/2 ise küçük ile büyük arasında $d=1$, $s=0$.
- Öklid: $d(x,y)=\sqrt{\sum_k (x_k-y_k)^2}$.
- Minkowski: $r=1$ Manhattan ($L_1$), $r=2$ Öklid ($L_2$), $r\to\infty$ limit.
- Metrik: $d\ge 0$ ve $d=0 \iff x=y$; $d(x,y)=d(y,x)$; $d(x,z)\le d(x,y)+d(y,z)$.
- SMC $=\frac{f_{11}+f_{00}}{f_{01}+f_{10}+f_{11}+f_{00}}$; Jaccard $=\frac{f_{11}}{f_{01}+f_{10}+f_{11}}$.
- Slayt örneği: SMC $=0.7$, Jaccard $=0$ (ekrandan, 00:20:00).
- Kosinüs: $\cos(x,y)=\frac{x\cdot y}{\|x\|\,\|y\|}$; açı $0$ ise $1$ (çok benzer).
- Pearson: $\text{corr}(x,y)=\frac{s_{xy}}{s_x s_y}$; $+1$, $-1$, $0$.
- Farklı tipleri birleştirme: $\text{similarity}(x,y)=\frac{\sum_k \delta_k s_k(x,y)}{\sum_k \delta_k}$.

## Detaylı Açıklamalar

- **Görselleştirme.** Ders, önceki derste başlanan görselleştirme slaytlarının tekrarıyla açıldı. Kutu grafiğinde kutunun ortasındaki çizgi medyan, kutunun alt ve üst kenarları Q1 ve Q3'tür. Bıyıkların ucu verinin maksimumu değildir; uç (aykırı) değerler varsa onlar ayrı noktalar olarak gösterilir. Hoca, slaytlardaki örneklerin R ile verildiğini, R'nin veri madenciliğinde ve istatistikçiler arasında popüler olduğunu, Python'daki (scikit-learn vb.) ve MATLAB'deki karşılıklarının çok benzer olduğunu söyledi; kodun ayrıntısı sorulmayacak, yalnız aşinalık için gösteriliyor. Çubuk grafik, ör. bir aydaki satışı eksenden doğrudan okutur. Histogram da çubuklarla çizilir ama dikey eksen frekanstır: her çubuk bir aralığa (bin) düşen örnek sayısını gösterir. Bin sayısı programda parametre olarak verilebilir ya da araç otomatik seçer.

- **Korelasyon ve saçılım grafiği.** Saçılım grafiğinde öznitelikler ikişer ikişer çizilir ve birbirleriyle pozitif mi, negatif mi korelasyonlu, yoksa korelasyonsuz mu oldukları görülür (ekrandan, 00:05:00: "Positively Correlated", "Negatively Correlated" ve iki "Uncorrelated" paneli). Hocanın uyarısı: öznitelikler arasında çok fazla korelasyon olmasın. Bütün öznitelikler pozitif korelasyonlu çıkarsa hepsi aynı şeyi söylüyor demektir.

- **Benzerlik ve farklılık.** Tablodaki iki satırın (iki nesne, iki vektör) ya da iki sütunun benzerliği ölçülebilir. Sınıftan gelen ilk öneri farkları almaktı; eksi değerlerin birbirini götürmemesi için farkların karesi alınıp toplanır, sonra karekökü alınır. Bu Öklid uzaklığıdır. Bir diğer öneri iç çarpımdı; bu da kosinüs benzerliğine götürür. Öznitelikler her zaman sayısal değildir; kategorik (nominal) ya da sıralı (ordinal) olabilir. Farklılık çoğu zaman uzaklık olarak ifade edilir. Benzerlik genelde $0$-$1$ aralığındadır, farklılık ise $0$'dan sonsuza kadar çıkabilir.

- **Tek öznitelik için tablo (ekrandan, 00:10:00).** $p$ ve $q$ iki nesnenin bir öznitelikteki değerleridir.

| Öznitelik tipi | Farklılık | Benzerlik |
|---|---|---|
| Nominal | $d=0$ ($p=q$), $d=1$ ($p\neq q$) | $s=1$ ($p=q$), $s=0$ ($p\neq q$) |
| Ordinal | $d=\frac{\lvert p-q\rvert}{n-1}$ (değerler $0..n-1$'e eşlenir, $n$ değer sayısı) | $s=1-\frac{\lvert p-q\rvert}{n-1}$ |
| Aralık/Oran | $d=\lvert p-q\rvert$ | $s=-d$, $s=\frac{1}{1+d}$ ya da $s=1-\frac{d-\min_d}{\max_d-\min_d}$ |

  Hoca ordinal durumu şu örnekle anlattı: küçük, orta, büyük değerleri $0, 1, 2$ diye numaralanır ($n=3$). Büyük ($2$) ile küçük ($0$) arasındaki fark $|2-0|=2$, $n-1=2$'ye bölününce $d=1$ olur; benzerlik $1-1=0$'dır. Hoca bu formülün zorunlu olmadığını da ekledi.

- **Öklid ve Minkowski.** Çok öznitelikli iki satır karşılaştırılırken her sütunda fark alınıp karesi alınır, toplanır ve karekökü alınır. Sonuç $0$-$1$ aralığında olmak zorunda değildir. Hoca, slayttaki dört noktalı tablodaki değerlerin bu formülle (ör. $\sqrt{(2-0)^2+(2-0)^2}$) elde edilebileceğini söyledi. <!-- BELİRSİZ: Nokta koordinat tablosunun karesi yok (yaklaşık 00:11:00); değerler doğrulanamadı. --> Minkowski uzaklığı Öklid'in genellemesidir: Öklid'de üs $2$ idi; üs $r$ olunca $d(x,y)=\left(\sum_k |x_k-y_k|^r\right)^{1/r}$ olur. $r=1$ Manhattan uzaklığıdır ($L_1$ normu): yalnız mutlak farklar toplanır, aynı değerlerde $0$, farklı değerlerde daha büyük katkı gelir. $r=2$ Öklid ($L_2$ normu), $r\to\infty$ ise limit durumudur. <!-- BELİRSİZ: Minkowski formülü anlatımdan kuruldu; slayt karesi yok. -->

- **Metrik.** Bir uzaklık şu üç özelliği sağlıyorsa metriktir: (1) pozitiflik: $d(x,y)\ge 0$ ve yalnız $x=y$ iken $d=0$; (2) simetri: $d(x,y)=d(y,x)$; (3) üçgen eşitsizliği: $d(x,z)\le d(x,y)+d(y,z)$. Sınıfla birlikte Öklid uzaklığına bakıldı: her zaman pozitif, simetrik ve üçgen eşitsizliğini sağlıyor, yani metriktir. Benzerliklerde ise genelde pozitiflik ($s(x,y)=1$ ancak $x=y$ iken, $0\le s(x,y)\le 1$) ve simetri sağlanır, üçgen eşitsizliği genelde sağlanmaz (ekrandan, 00:15:00).

- **İkili veri: SMC ve Jaccard.** İki ikili vektör için $f_{01}$ ($p=0$, $q=1$), $f_{10}$, $f_{00}$ ve $f_{11}$ sayılır. Simetrik ikili değişkende (hocanın örneği: cinsiyet) $0$ ile $1$ eşit önemdedir; SMC kullanılır: $\text{SMC}=\frac{f_{11}+f_{00}}{f_{01}+f_{10}+f_{11}+f_{00}}$. Asimetrik ikili değişkende $1$ daha önemlidir; Jaccard 0-0 eşleşmelerini almaz: $J=\frac{f_{11}}{f_{01}+f_{10}+f_{11}}$. Hoca Jaccard'ın görüntü bölütlemede yaygın olduğunu anlattı: bir araba için gerçek maske ve algoritmanın bulduğu maske karşılaştırılır. Arabanın olduğu pikseller $1$, arka plan $0$'dır. Doğru bulunan araba pikselleri (kesişim), yanlışlıkla arka plan denen araba pikselleri ve yanlışlıkla araba denen arka plan pikselleri hesaba girer; büyük arka plan (0-0) hesaba katılmaz.

- **SMC ve Jaccard örneği (ekrandan, 00:20:00).** $p = 1\,0\,0\,0\,0\,0\,0\,0\,0\,0$, $q = 0\,0\,0\,0\,0\,0\,1\,0\,0\,1$. Sayımlar: $f_{01}=2$, $f_{10}=1$, $f_{00}=7$, $f_{11}=0$. $\text{SMC}=\frac{0+7}{2+1+0+7}=0.7$, $J=\frac{0}{2+1+0}=0$. Hoca, SMC'de aynı bulunan 7 konumun toplam 10'a bölündüğünü gösterdi. Sonuçlar python ile doğrulandı.

- **Kosinüs benzerliği.** $\cos(x,y)=\frac{x\cdot y}{\|x\|\,\|y\|}$: iç çarpım, iki vektörün $L_2$ normlarının (elemanların kareleri toplamının karekökü) çarpımına bölünür. Bu, vektörleri birim vektöre çevirip iç çarpım almak demektir. Değer $-1$ ile $1$ arasındadır; vektörlerde negatif eleman varsa iç çarpım negatif çıkabilir. İki vektör aynı yöndeyse aralarındaki açı $0$, $\cos 0=1$'dir; yani $1$'e ne kadar yakınsa o kadar benzerdir.

- **Pearson korelasyonu (ekrandan, 00:25:00).** Korelasyon nesneler arasındaki doğrusal ilişkiyi ölçer:
  $\text{corr}(x,y)=\frac{s_{xy}}{s_x s_y}$, $s_{xy}=\frac{1}{n-1}\sum_{k=1}^{n}(x_k-\bar x)(y_k-\bar y)$, $s_x=\sqrt{\frac{1}{n-1}\sum_{k=1}^{n}(x_k-\bar x)^2}$, $\bar x=\frac{1}{n}\sum_{k=1}^{n}x_k$ ($y$ için de benzer).
  $+1$ pozitif doğrusal ilişki (biri artarken diğeri artar), $-1$ negatif doğrusal ilişki (biri artarken diğeri azalır), $0$ doğrusal ilişki olmadığı anlamına gelir. Araçlar ve kütüphaneler korelasyon matrisini hazır verir. Korelasyonun sıkıntısı yalnız doğrusal ilişkiyi göstermesidir: hocanın gösterdiği örnekte değişken önce azalıp sonra artıyor; aralarında güçlü bir ilişki olduğu halde korelasyon bunu göstermez. <!-- BELİRSİZ: Doğrusal olmayan örneğin slayt karesi yok (yaklaşık 00:27:00); örneğin tam biçimi doğrulanamadı. -->

- **Ölçü seçimi.** Önce veri istatistiksel olarak incelenir, aykırı değerler temizlenir, sonra öznitelikler arası benzerliğe bakılır. Hangi ölçünün kullanılacağı veriye ve uygulamaya bağlıdır. En çok Öklid uzaklığı kullanılır; veri pozitifse (ör. metin madenciliği) kosinüs tercih edilir. <!-- BELİRSİZ: Altyazıda "görüntü işleme, text mining ... ya kart uzaklık" ve "istatistikteki kareler" geçiyor; Jaccard ve bir istatistiksel ölçü kastediliyor olabilir, doğrulanamadı. -->

- **Farklı tipteki öznitelikleri birleştirme (ekrandan, 00:30:00).** Öznitelikler farklı tiplerde olabilir ama tek bir genel benzerlik gerekir. (1) Her $k$. öznitelik için $[0,1]$ aralığında $s_k(x,y)$ hesaplanır. (2) Gösterge değişkeni: $k$. öznitelik asimetrikse ve iki nesnede de değeri $0$ ise ya da nesnelerden birinde değer eksikse $\delta_k=0$, aksi halde $\delta_k=1$. (3) $\text{similarity}(x,y)=\frac{\sum_{k=1}^{n}\delta_k s_k(x,y)}{\sum_{k=1}^{n}\delta_k}$.

- **Entropi.** Entropi biraz farklı bir kavramdır: verinin ne kadar bilgi verdiğini gösterir. Karar ağaçları entropi üzerine kurulacaktır. Hoca iki vektörün içerdiği bilgiye göre ortak bilgiyi ölçen bir yaklaşımdan da kısaca söz etti. <!-- BELİRSİZ: 00:29:42-00:30:01 arası anlatım bozuk; karşılıklı bilgi (mutual information) kastediliyor olabilir. -->

- **Ders sonu sorusu.** Hoca, metrik koşullarını hatırlatarak "Kosinüs uzaklığı metrik midir?" sorusunu düşünülmek üzere bıraktı; derste cevap verilmedi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
