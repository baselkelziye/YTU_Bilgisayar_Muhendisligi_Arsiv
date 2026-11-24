# Ders 4 Çalışma Özeti

## Genel Konular

- Veri indirgemenin hatırlatılması
  - Veri indirgeme üç alanda yapılır: öz nitelik (sütun) indirgeme, örnek (satır) indirgeme (sample reduction) ve değer indirgeme (value reduction). En çok çalışılan ve en önemli alan öz nitelik indirgemedir; satır indirgeme için pek çalışma yapılmaz.
  - Öz nitelik indirgeme iki kola ayrılır: öz nitelik seçimi (feature selection) ve öz nitelik birleştirme (feature composition). Öz nitelik seçimi de denetimli (supervised) ve denetimsiz (unsupervised) yöntemlere ayrılır (ekrandan, 02:15:00).
  - Denetimli seçim önceki derste işlendi: sınıf etiketi varken ortalama ve varyanstan bir test değeri üretilir, değer büyüdükçe öz niteliğin ayırt ediciliği artar; öz nitelikler sıralanır, belli bir noktadan sonrakiler atılır.
  - Bu derste iki konu işlendi: etiketsiz veride entropi ölçüsüyle öz nitelik sıralama ve temel bileşen analizi (PCA). Değer indirgeme sonraki derse kaldı.
- Entropi ölçüsüyle öz nitelik sıralama (denetimsiz öz nitelik seçimi)
  - Örnekler, sınıf etiketi olmayan n boyutlu öz nitelik vektörleridir. Fikir: ilgisiz ya da gereksiz (redundant) bir öz nitelik çıkarılınca veri setinin temel özellikleri değişmez. Amaç, örnekler arasındaki ayırt ediciliği koruyarak olabildiğince çok öz nitelik atmaktır (ekrandan, 00:15:00).
  - Yöntem, uzaklıkla ters orantılı bir benzerlik ölçüsü $S$ kullanır. Öz nitelik sayısı çok olunca yöntemin karmaşıklığı belirgin biçimde artar.
- Uzaklık ve benzerlik ölçüleri
  - Veri seti $m$ örnek ve $n$ öz nitelikten oluşan bir matristir; $x_{ik}$ değerinde ilk indis örnek, ikinci indis öz nitelik numarasıdır (ekrandan, 00:30:00).
  - Sayısal öz nitelikler için Öklid uzaklığı: $D_{ij} = \sqrt{\sum_{k=1}^{n} (x_{ik} - x_{jk})^2}$.
  - Normalize Öklid uzaklığı: her öz niteliğin farkı o öz niteliğin $\max_k - \min_k$ aralığına bölünür, sonra kareler toplanıp karekök alınır (min-max normalizasyonuna benzer) (ekrandan, 00:35:00). <!-- BELİRSİZ: formülün tahtadaki tam yazımı karelerde görünmüyor; altyazıdaki anlatımdan kuruldu. -->
  - Sayısal öz niteliklerde benzerlik: $S_{ij} = e^{-\alpha D_{ij}}$, $\alpha = -(\ln 0.5)/\bar{D}$. $\bar{D}$ veri setindeki örnekler arası ortalama uzaklıktır; uygulamada sabit $\alpha = 0.5$ da kullanılmıştır (ekrandan, 00:25:00).
  - Kategorik (nominal) öz niteliklerde Hamming benzerliği: $S_{ij} = \left(\sum_{k=1}^{n} |x_{ik} = x_{jk}|\right)/n$. Eşit olan her öz nitelik 1, farklı olan 0 sayılır; toplam öz nitelik sayısına bölünür (ekrandan, 00:50:00).
- Hamming benzerlik örneği (5 örnek, 3 kategorik öz nitelik)
  - Veri: R1 = (A, X, 1), R2 = (B, Y, 2), R3 = (C, Y, 2), R4 = (B, X, 1), R5 = (C, Z, 3). F3'teki 1, 2, 3 sayıları renk gibi kategorileri temsil eden kodlardır, sayısal işlem yapılamaz (ekrandan, 00:40:00).
  - Benzerlik matrisi 5x5'tir, simetriktir, ana köşegeni 1'dir. Üst üçgen: $S_{12}=0$, $S_{13}=0$, $S_{14}=2/3$, $S_{15}=0$, $S_{23}=2/3$, $S_{24}=1/3$, $S_{25}=0$, $S_{34}=0$, $S_{35}=1/3$, $S_{45}=0$ (ekrandan, 00:40:00 ve 00:50:00).
- Bilgi kuramında entropi
  - Olası sonuçları $x_1, \dots, x_n$ ve olasılıkları $P(x_i)$ olan ayrık rastgele değişken için $H(X) = -\sum_{i=1}^{n} P(x_i)\log_2 P(x_i)$.
  - Entropi küresel (global) bir ölçüdür: düzenli yapılarda (ordered configuration) düşük, düzensiz yapılarda (disordered configuration) yüksektir (ekrandan, 00:55:00).
  - 6 kırmızı ve 6 mavi top: $p_1 = p_2 = 1/2$, $H = 1$ bit (en düzensiz yapı) (ekrandan, 01:00:00).
  - Yalnız kırmızı toplar: $p_1 = 1$, $p_2 = 0$, $H = 0$ (tam düzenli yapı) (ekrandan, 01:10:00).
  - İki sonuçlu durumda $H$-$p$ grafiği $p=0$ ve $p=1$'de 0, $p=1/2$'de 1 değerini alan simetrik bir tepe (yarım daireye benzer) biçimindedir.
  - Dört renk, her renkten 3 top: $p_i = 1/4$, $H = 2$ bit (ekrandan, 01:15:00). Sekiz sonuçta en büyük entropi 3 bittir.
  - $\log_2$ kullanılınca birim bittir.
- Etiketsiz veri için entropi ve sıralama algoritması
  - Sınıf etiketi olmadığı için olasılık yerine benzerlik kullanılır: $E = -\sum_{i=1}^{N-1}\sum_{j=i+1}^{N}\left(S_{ij}\log S_{ij} + (1-S_{ij})\log(1-S_{ij})\right)$. Toplam, benzerlik matrisinin ana köşegen üstündeki üçgenini dolaşır; $1-S_{ij}$ benzemezliktir (dissimilarity) (ekrandan, 00:55:00 ve 01:40:00).
  - Adımlar (ardışık geriye doğru sıralama, sequential backward ranking) (ekrandan, 01:50:00):
    - 1) Tam öz nitelik kümesi $F$ ile başla.
    - 2) Her $f \in F$ için $f$'yi çıkarıp $F_f$ alt kümesini elde et; $E_F$ ile $E_{F_f}$ arasındaki farkı bul. Örnekte $(E_F - E_{F-F1})$, $(E_F - E_{F-F2})$, $(E_F - E_{F-F3})$ karşılaştırılır.
    - 3) Farkı en küçük yapan $f_k$ seçilir.
    - 4) $F = F - \{f_k\}$; $f_k$ sıralı listenin en altına konur.
    - 5) $F$'de tek öz nitelik kalana kadar 2-4 tekrarlanır.
- Öz nitelik birleştirme (feature composition) ve PCA
  - Seçimde var olan öz niteliklerden bazıları tutulur; birleştirmede ise öz nitelikler dönüştürülür ve yeni, birleşik öz nitelikler tanımlanır. Bu yüzden asıl öz niteliklerin anlamı (örneğin doktor için kan değeri, kalp atış hızı) kaybolur.
  - PCA sınıf etiketi gerektirmeyen denetimsiz bir yöntemdir.
- İstatistik altyapısı
  - Ortalama $\bar{X} = \sum X_i / n$. [0 8 12 20] ve [8 9 11 12] kümelerinin ortalaması 10'dur ama yayılımları farklıdır (ekrandan, 02:00:00).
  - Standart sapma $s = \sqrt{\sum (X_i - \bar{X})^2/(n-1)}$; varyans bunun karesidir.
  - Kovaryans: $cov(X,Y) = \sum (X_i-\bar{X})(Y_i-\bar{Y})/(n-1)$; $cov(X,X)$ varyanstır (ekrandan, 02:05:00).
  - Çalışma saati-not örneği: 12 öğrenci, ortalama saat 13.92, ortalama not 62.42; kovaryans pozitif, yani çok çalışan yüksek not alma eğilimindedir (ekrandan, 02:10:00).
  - Üç boyutlu veride kovaryans matrisi 3x3, kare ve simetriktir ($cov(x,y)=cov(y,x)$); ana köşegeninde varyanslar bulunur.
- Doğrusal cebir altyapısı: öz değer ve öz vektör
  - Kare matris $A$ için $Au = \lambda u$ ise $u$ öz vektör, $\lambda$ öz değerdir. $(A-\lambda I)u = 0$ ve $\det(A - \lambda I) = 0$ ile $\lambda$ bulunur, sonra $u$ hesaplanır.
  - Örnek $A = \begin{pmatrix}2&1\\1&2\end{pmatrix}$: $\lambda^2 - 4\lambda + 3 = 0$, $\lambda_1 = 3$, $\lambda_2 = 1$; $u_1 = (1, 1)^T$ ($x=y$), $u_2 = (1, -1)^T$ ($x=-y$). Vektörün yönü önemlidir, tam değerleri değil (ekrandan, 02:20:00 ve 02:25:00).
- PCA adımları
  - 1) Veriyi al (örnekte 10 örnek, 2 boyut: x, y).
  - 2) Her sütunun ortalamasını çıkar (adjusted data); bu, veri merkezini orijine kaydırmaktır.
  - 3) 2x2 kovaryans matrisini hesapla.
  - 4) Kovaryans matrisinin öz değer ve öz vektörlerini hesapla; öz vektörler matrisin sütunlarıdır.
  - 5) Veriyi öz vektörlerin tanımladığı yeni koordinat düzlemine ($u_1, u_2$) taşı: her örneğin eksenlere izdüşümü (projection) alınır (ekrandan, 02:45:00 ve 02:50:00).
  - Dönüşüm: $(10\times2)$ adjusted data $\times$ $[u_1\ u_2]$ $=$ $(10\times2)$ transformed data (ekrandan, 03:00:00). Bu adımda yalnız dönüşüm yapılır, indirgeme yapılmaz.
  - İndirgeme öz değerlere bakılarak yapılır: öz değer, o eksendeki yayılımı gösterir. Örnekte küçük öz değer 0.04 civarı, büyük öz değer 1.2 civarıdır; yayılımın en büyük olduğu eksen seçilir ve iki boyut bire iner.
  - Çok boyutlu veride öz değerler büyükten küçüğe sıralanır; $(\lambda_1 + \dots + \lambda_k)/(\lambda_1 + \dots + \lambda_n) \ge 0.95$ olana kadar bileşen eklenir (ekrandan, 03:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Entropi karar ağaçlarında da kullanılacaktır
  - Düzenli ve düzensiz yapının anlamı ve entropinin neden düşük ya da yüksek çıktığı şimdiden iyi anlaşılmalıdır.
- Sonuç sayısına göre en büyük entropiyi bilmek
  - 2 sonuçta 1 bit, 4 sonuçta 2 bit, 8 sonuçta 3 bit. Hesap sonucunu kontrol etmek için bu bilinmelidir.
- Bütün sınıf olasılıkları eşitken entropi en büyüktür
  - Bu yalnız iki sınıf için değil, her sınıf sayısı için geçerlidir.
- Benzerlik ölçümü veri madenciliğinde pek çok yerde gerekir
  - Özellikle kümeleme (clustering) konusunda başka benzerlik ölçüleri de anlatılacaktır; Hamming en basitidir.
- Denetimsiz yöntemde olasılık yerine benzerlik kullanılır
  - Sınıf etiketi olmadığından sınıf olasılıkları bilinmez; entropi formülü benzerlikle yeniden yazılır.
- PCA'da matris çarpımıyla dönüşüm ve öz değerlerle karar
  - Hoca dönüşüm matris çarpımının mutlaka not edilmesini istedi; hangi öz vektörlerin kullanılacağının ipucu öz değerdedir. PCA'nın mantığını anlamak çok önemlidir.

## Kısa Tekrar Notları

- Öz nitelik indirgeme = seçim (supervised: ortalama-varyans; unsupervised: entropi) + birleştirme (PCA).
- Hamming benzerliği: eşleşen öz nitelik sayısı / öz nitelik sayısı.
- Benzerlik matrisi $m \times m$, simetrik, köşegeni 1.
- $H = -\sum p_i \log_2 p_i$; eşit olasılıkta en büyük ($\log_2$ sonuç sayısı), tek sınıfta 0.
- Etiketsiz entropi: $E = -\sum_{i<j} [S_{ij}\log S_{ij} + (1-S_{ij})\log(1-S_{ij})]$.
- Sıralama: her öz niteliği tek tek çıkar, entropi farkı en küçük olanı listenin en altına koy, tek öz nitelik kalana kadar tekrarla.
- Kovaryans matrisi kare ve simetrik; köşegeni varyans.
- $\det(A-\lambda I)=0$ ile öz değer, $Au=\lambda u$ ile öz vektör.
- PCA: ortalamayı çıkar, kovaryans, öz değer/öz vektör, izdüşüm; öz değer oranı $\ge 0.95$ olana kadar bileşen seç.

## Detaylı Açıklamalar

- Denetimsiz öz nitelik sıralamanın mantığı: bir öz nitelik çıkarıldığında veri setinin "düzeni" pek değişmiyorsa o öz nitelik gereksizdir. Düzen, örnekler arası benzerliklerden hesaplanan entropiyle ölçülür. Tam küme ile bir öz nitelik çıkarılmış alt kümenin entropisi birbirine çok yakınsa, alt küme tam kümeyi yeterince temsil eder. Bu yüzden farkı en küçük yapan öz nitelik en değersizdir ve sıralı listenin en altına gider. İşlem kalan öz niteliklerle (artık "tam küme" onlardır) tekrarlanır; örnekte F1 çıkarılırsa yeni küme {F2, F3} olur ve karşılaştırma bu ikisiyle sürer.
- Hamming benzerlik örneğinde iki örnek karşılıklı öz nitelikleri tek tek karşılaştırılarak incelenir. R1 = (A, X, 1) ile R4 = (B, X, 1) yalnız F1'de ayrıldığı için $S_{14} = 2/3$; R2 = (B, Y, 2) ile R3 = (C, Y, 2) aynı nedenle $2/3$; R2 ile R4 yalnız F1'de eşleşir, $1/3$; R3 ile R5 yalnız F1'de (C) eşleşir, $1/3$. Diğer çiftlerde eşleşme yoktur. Matris simetrik olduğundan yalnız üst üçgen hesaplanır; bu üst üçgen doğrudan entropi formülünde kullanılır.
- Entropi örnekleri: iki eşit olasılıkta $H = -(\tfrac12\log_2\tfrac12 + \tfrac12\log_2\tfrac12) = -(\tfrac12(-1) + \tfrac12(-1)) = 1$. Tek sınıfta $H = -(1\cdot\log_2 1 + 0\cdot\log_2 0) = 0$; $\log_2 1 = \log_2 2^0 = 0$ ve $0\cdot\log_2 0$ terimi 0 kabul edilir. Dört eşit olasılıkta $H = -4\cdot\tfrac14\log_2\tfrac14 = -\log_2 2^{-2} = 2$ bit.
- PCA'nın sezgisi: ortalaması çıkarılmış 10 noktalık veri, orijinden geçen çapraz bir şerit boyunca uzanır. Bir öz vektör bu şeridin yönünü (yayılımın en büyük olduğu yön), diğeri ona dik yönü gösterir. Noktalar bu iki eksene izdüşürülünce şerit yönündeki koordinatlar geniş bir aralığa yayılır, dik yöndekiler sıfır çevresinde küçük kalır. Küçük yayılımlı eksen atılınca bilgi kaybı azdır. Matematikte bu, adjusted data matrisinin her satırının öz vektörlerle çarpılmasıdır.
- Bileşen sayısı seçimi örneği: 5 boyutlu veride en büyük öz değer tek başına toplamın %85'ini veriyorsa eşik (%95) aşılmamıştır. İkinci öz değer 0.11 katkıyla oranı %96'ya çıkarırsa iki bileşen yeterlidir; veri $u_1$ ve $u_2$ üzerine izdüşürülür, $u_3$, $u_4$, $u_5$ kullanılmaz. İndirgenmiş veri asıl verinin %96'sını temsil eder.
- Ders sonrası not: Ekranda gösterilen çalışma saati-not tablosunda çarpımlar toplamı 1149.89 ve kovaryans 104.54 yazıyor (ekrandan, 02:10:00). Aynı veriyle python hesabı toplamı yaklaşık 1352.42, kovaryansı $1352.42/11 \approx 122.95$ veriyor; tablodaki toplam satırı büyük olasılıkla kaynak belgedeki bir yazım hatasıdır. Kovaryansın pozitif olduğu sonucu değişmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
