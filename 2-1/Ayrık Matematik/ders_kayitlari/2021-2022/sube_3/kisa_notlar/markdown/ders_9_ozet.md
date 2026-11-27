# Ders 9 Çalışma Özeti

## Genel Konular

- Graf boyama ve kromatik sayı
  - Bir $G$ grafının her düğümüne, komşu iki düğüm aynı rengi almayacak biçimde bir renk atanmasına grafın renklendirilmesi (boyanması) denir.
  - Grafın renk sayısı (kromatik sayısı) $\chi(G)$, grafı boyamak için gereken en az renk sayısıdır. Amaç her zaman en az renkle boyamaktır; daha fazla renkle boyamak mümkün olsa da doğru cevap değildir.
  - Örnek (ekrandan, 00:20:00): ortasında bütün dış düğümlere bağlı bir düğüm bulunan kare ve altıgen biçimli graflar; ikisinde de $\chi(G)=3$.
- Kullanım alanları
  - Kurul toplantılarını planlama: kurullar düğüm, ortak üyesi olan kurullar arasındaki kenar "çakışma" demektir. Aynı renkteki kurullar aynı zamanda toplanabilir; renk sayısı gereken en az oturum sayısıdır.
  - Ders programı hazırlama: dersler çakışmayacak şekilde en az zaman dilimine yerleştirilir.
  - Örnek (ekrandan, 00:25:00): 10 düğümlü bir kurul grafı 4 renkle boyanmış, $\chi(G)=4$.
- Kromatik polinom
  - $P_G(x)$: $x$ renk varken $G$ grafının kaç farklı şekilde boyanabileceğini veren polinom.
  - Polinomu sıfırdan farklı yapan en küçük $x$ değeri kromatik sayıdır. Bu $x$ polinomda yerine konunca çıkan sayı, o kadar renkle kaç farklı boyama olduğunu verir.
- Kromatik polinomu bilinen graflar (ekrandan, 00:35:00)
  - Noktasal graf (tek düğüm): $x$.
  - Çizgisel graf ($U$ grafı, $n$ düğümlü yol): $U_n = x(x-1)^{n-1}$.
  - $Z$ grafı ya da $K$ grafı (tam graf): $K_n = \prod_{k=0}^{n-1}(x-k)$. Üçgen için $x(x-1)(x-2)$.
- Silme-birleştirme (deletion-contraction) yöntemi
  - Bilinmeyen bir graftan bir kenar silinir; ondan, silinen kenarın iki ucunun birleştirildiği graf çıkarılır: $P_G = P_{G-e} - P_{G/e}$.
  - Birleştirmede kenarlar kırılmaz; üst üste gelen kenarlar tek kenar olur.
  - İşlem, bütün parçalar bilinen graflara (noktasal, çizgisel, $K$) inene kadar sürer.
- Ortak parçadan bölme kuralı (ekrandan, 00:55:00)
  - İki graf birbirinden bir noktasal ya da çizgisel grafla ayrılıyorsa: iki parçanın polinomları çarpılır, ortak parçanın polinomuna bölünür.
- Kromatik polinomun doğruluk kuralları (ekrandan, 01:15:00)
  - Baş katsayı $a_1 = 1$; derece = düğüm sayısı; ikinci terimin katsayısı (mutlak değerce) = kenar sayısı; katsayılar toplamı $0$; işaretler $+,-,+,-,\dots$ diye gider; sabit terim yoktur.
- Ağaçlar
  - Ağaç, döngü içermeyen bağlantılı basit graftır; iki düğüm arasında tek bir yol vardır. Kök bilgisi verilmedikçe ağacın kökü yoktur; kök verilirse köklü ağaç olur.
  - Düğümün seviyesi köke olan yolun uzunluğudur; ağacın yüksekliği en büyük seviyedir.
  - Terminoloji (ekrandan, 01:35:00): parent (ana/baba), ancestor (ata), child (çocuk), descendant (torun), siblings (kardeş düğüm), terminal vertices (uç düğüm), internal vertices (ara düğüm), subtrees (alt ağaçlar).
  - Teorem (ekrandan, 01:40:00): $T$, $n$ düğümlü bir graf ise şunlar denktir: $T$ ağaçtır; $T$ bağlantılı ve döngüsüzdür; $T$ bağlantılıdır ve $n-1$ kenarı vardır; $T$ döngüsüzdür ve $n-1$ kenarı vardır.
- İkili ağaçlar (binary tree)
  - Her düğümden en fazla iki kenar (çocuk) çıkar; sol çocuk ve sağ çocuk ayrılır.
  - Matematiksel ifadelerin gösterimi (ekrandan, 01:45:00): $a-b$, $a-b/c$, $(a-b)*c$ ağaçları.
  - $n$ düğümle çizilebilecek farklı ikili ağaç sayısı: 0 düğümde boş ağaç, 1 düğümde 1, 2 düğümde 2, 3 düğümde 5.
  - Tam ikili ağaç (ekrandan, 01:55:00): $t$ uç düğüm varsa $\lg t \le h$; $i$ ara düğüm varsa $i+1$ uç düğüm ve $2i+1$ toplam düğüm vardır.
- Dengeli ağaç (ekrandan, 02:05:00)
  - Yüksekliği $h$ olan bir ağacın yapraklarının seviyesi $h$ ya da $h-1$ ise dengeli ağaçtır; yani köke en uzak ve en yakın uç düğümlerin seviye farkı en fazla 1'dir.
- İkili arama ağaçları (binary search tree)
  - Düğümün solundaki veri o düğümdekinden küçük, sağındaki büyüktür.
  - Kelime örneği (ekrandan, 02:00:00): "Computers are an important technological tool".
  - Sıralı sayı dizisini dengeli ağaca yerleştirme (ekrandan, 02:35:00) ve ağacı diziye yerleştirme: kök indisi 1, $i$ indisli düğümün sol çocuğu $2i$, sağ çocuğu $2i+1$ (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- En az renk sayısı sorulur
  - Bir grafı daha çok renkle boyamak mümkündür, ama "kaç renkle boyanır" sorusunun cevabı her zaman en az renk sayısıdır.
- Hangi kenar silinmeli?
  - Kesin bir algoritma yoktur; ama rastgele de değildir. Grafı tanınan bir grafa (çizgisel, $K$ ya da noktasal) en hızlı indirecek kenar seçilir. Grafın $K$ grafı olduğunu ya da içinde tanınan parçalar bulunduğunu ne kadar erken görürseniz işlem o kadar kısalır.
- Farklı kesme sıraları farklı ara adımlar verebilir
  - Sonuçta bulunan en az renk sayısı ve boyama sayısı aynı olur; kontrol kuralları her zaman sağlanmalıdır.
- Katsayılarla hızlı çarpma
  - Polinomları çarparken işaretler bir kenara bırakılıp yalnız katsayılar kaydırarak çarpılıp toplanır; işaretler sonra $+,-,+,-$ diye yerleştirilir. Bu yol daha az hata yaptırır.
- Kök bilgisi
  - Kök verilmedikçe seviye ve yükseklik söylenemez.
- Çizime aldanmamak
  - Bir ağaç, düğümler aynı hizada görünecek şekilde çizilebilir; seviyeler kenar sayılarak bulunmalıdır.

## Kısa Tekrar Notları

- $\chi(G)$: komşuları farklı renkte olacak şekilde en az renk sayısı.
- Noktasal: $x$; çizgisel: $x(x-1)^{n-1}$; $K_n$: $x(x-1)\cdots(x-n+1)$.
- $P_G = P_{G-e} - P_{G/e}$.
- İki parça bir nokta ya da kenarda birleşiyorsa: $P_G = P_{G_1}\,P_{G_2} / P_{\text{ortak}}$.
- $K_4$: $x^4-6x^3+11x^2-6x$; $x=4$ için $24$.
- Bir köşegenli kare: $x^4-5x^3+8x^2-4x = x(x-1)(x-2)^2$; 3 renk, 6 şekilde.
- Kare ($C_4$): $x(x-1)(x^2-3x+3)$.
- Kontrol: baş katsayı 1, derece = düğüm sayısı, ikinci katsayı = kenar sayısı, katsayılar toplamı 0, işaretler dönüşümlü, sabit terim yok.
- Ağaç: bağlantılı, döngüsüz, $n$ düğüm ve $n-1$ kenar.
- Seviye: köke uzaklık; yükseklik: en büyük seviye.
- Tam ikili ağaçta: $i$ ara düğüm → $i+1$ uç düğüm, $2i+1$ toplam düğüm; $\lg t \le h$.
- Dengeli ağaç: yaprak seviyeleri $h$ ya da $h-1$.
- İkili arama ağacı: küçük sola, büyük sağa. Dizi gösteriminde sol çocuk $2i$, sağ çocuk $2i+1$.

## Detaylı Açıklamalar

- **Kromatik polinomun anlamı.** $P_G(x)$, elde $x$ renk varken grafın kaç farklı geçerli boyaması olduğunu sayar. Tek düğüm $x$ farklı şekilde boyanır. İki düğümlü çizgisel grafta ilk düğüm $x$, komşusu kalan $x-1$ renkle boyanır. Yolda her yeni düğümün yalnız bir boyanmış komşusu olduğu için hep $x-1$ seçenek kalır: $U_n = x(x-1)^{n-1}$ ($U_2 = x(x-1)$, $U_3 = x(x-1)^2$, $U_7 = x(x-1)^6$). Tam grafta her yeni düğüm daha önce boyanan bütün düğümlere komşu olduğundan seçenekler $x, x-1, x-2, \dots$ diye azalır.
- **$K_4$ örneği (ekrandan, 00:40:00).** $K_4 = x(x-1)(x-2)(x-3) = (x^2-x)(x^2-5x+6) = x^4-6x^3+11x^2-6x$. Hızlı çarpma: $1\,5\,6$ ile $1\,1$ katsayıları kaydırılarak çarpılıp toplanır, $1\,6\,11\,6$ elde edilir; işaretler $+,-,+,-$ ve son terim $x$ olur. $x=1,2,3$ için değer 0'dır (çarpanlardan biri sıfırlanır), $x=4$ için $24$. Yani graf en az 4 renkle ve 4 renkle 24 farklı şekilde boyanır.
- **Silme-birleştirme ile $K_4$ (ekrandan, 00:50:00).** $K_4$'ten 1-4 kenarı silinir; kalan graftan 1 ile 4'ün birleştirildiği üçgen çıkarılır. Kalan bir köşegenli kareden 2-3 kenarı silinir: kare ($C_4$) eksi 2 ile 3'ün birleştirildiği üç düğümlü yol. Kareden 2-4 kenarı silinir: dört düğümlü yol eksi üçgen, yani $x(x-1)^3 - x(x-1)(x-2) = x(x-1)(x^2-3x+3)$. Geri yerine konunca bir köşegenli kare $x^4-5x^3+8x^2-4x$, $K_4$ ise $x^4-6x^3+11x^2-6x$ çıkar.
- **Ortak parçadan bölme (ekrandan, 01:00:00).** Bir köşegenli kare, ortak kenarı paylaşan iki üçgendir: $\dfrac{[x(x-1)(x-2)]^2}{x(x-1)} = (x^2-x)(x^2-4x+4) = x^4-5x^3+8x^2-4x$. $x=0,1,2$ için 0; $x=3$ için $3\cdot2\cdot1\cdot1 = 6$. Graf 3 renkle 6 farklı şekilde boyanır. İki üçgen ortak bir noktada birleşiyorsa üçgenlerin çarpımı noktasal grafa ($x$) bölünür; bir üçgenle bir çizgi ortak noktada birleşiyorsa da aynı yol izlenir.
- **Merkez düğümlü kare (ekrandan, 01:25:00).** Dış kenarları 1-2, 2-4, 4-3, 3-1 olan ve 5. düğümü hepsine bağlı graf. 2-4 silinince çıkarılan parça $K_4$ olur. Kalan graftan 1-2 silinir ve çıkarılan parça iki üçgenin ortak kenarda birleştiği $A$ grafıdır. En sonda yalnız 5'e bağlı 2. düğümün kenarı silinir: $A\cdot x - A = A(x-1)$. Buradan $A(x-1) - A = A(x-2)$ ve sonuç $A(x-2) - K_4 = x^5-8x^4+24x^3-31x^2+14x$. Kontrol: 5 düğüm, 8 kenar, işaretler dönüşümlü, sabit terim yok, $1+24+14 = 8+31 = 39$ olduğundan katsayılar toplamı 0.
- **Ağaçların temel kavramları.** Bir grafta bütün kapalı döngüler silinirse ağaç elde edilir. Köklü ağaç, sapından tutulmuş bir üzüm salkımı gibi düşünülebilir: sap kök, taneler düğümlerdir. Uç düğümden dal çıkmaz; ara düğümden dal çıkar; kök de dal çıktığı için ara düğümdür. Bir düğümün çocuklarının çocukları torun sayılır; aynı ebeveynden çıkan düğümler kardeştir. Teoreme göre 10 düğümlü bir ağaçta 9 kenar vardır.
- **İfade ağaçları.** İşleç kökte, işlenenler çocuklardadır. $a-b/c$'de önce $b/c$ yapılır, bu yüzden kökteki $-$'nin sağ çocuğu $/$ olur. $(a-b)*c$'de kök $*$, sol çocuk $a-b$ alt ağacı, sağ çocuk $c$'dir.
- **İkili arama ağacında arama.** Kökten başlanır; aranan değer düğümdekinden küçükse sola, büyükse sağa gidilir. Boş bir dala varılırsa değer yoktur; istenirse o noktaya eklenir. Dizi gösteriminde kök 1. gözdedir; $i$. gözdeki düğümün sol çocuğu $2i$, sağ çocuğu $2i+1$. gözdedir, boş gözlere 0 yazılır.

<!-- BELİRSİZ: 01:26:28'deki 8 düğümlü, 12 kenarlı örnek grafın şekli ve polinomu kareden okunamadı; nota alınmadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
