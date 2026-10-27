# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin tarihi 18 Aralık 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl anlatım yaklaşık 00:11:10'da başlar. Öncesinde ikinci vize duyurusu ve hocanın sınıfa konuşması var.
  - Ara yaklaşık 01:21-01:38 arasıdır.
- İkinci vize duyurusu.
- Ağaçlar bölümünün devamı
  - Kruskal algoritması ile en küçük kapsayan ağaç (minimum spanning tree).
  - Karar ağaçları (decision trees): sahte para problemi, sınıflandırma (classification).
  - Entropi (entropy) ve bilgi kazancı (information gain) ile karar ağacı kurma: "tenis oynanır mı" veri seti.
  - Ağaçlarda izomorfizm (isomorphism): köksüz, köklü ve ikili ağaçlarda.
- Yeni bölüm: Graflar (graphs)
  - Graf tanımı, düğüm (vertex) ve kenar (edge) kümeleri.
  - Yalıtılmış düğüm (isolated vertex), paralel kenar, döngü (loop).
  - Basit graf, çoklu graf (multigraph), sözde graf (pseudograph), ağırlıklı graf, yönlü graf (digraph), yönlü çoklu graf.
  - Benzerlik grafı (similarity graph): program kodlarını özelliklerine göre gruplama.
  - Özel graflar: tam graf $K_n$, çember graf $C_n$, tekerlek graf $W_n$, küp graf $Q_n$.
  - İki parçalı graf (bipartite graph) ve tam iki parçalı graf $K_{m,n}$.
  - Özel grafların düğüm ve kenar sayısı formülleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- **İkinci vize 8 Ocak 2021 Cuma günü test olarak yapılacak.**
  - Bölüm ikinci vizeler için takvim ilan etmeyecek. Bilgiyi dersin hocasından alın.
  - Sorular ağırlıklı olarak birinci vizeden sonraki konulardan gelecek. Önceki konularla ilişkili sorular da olabilir.
  - Final klasik olacak ve hemen sonraki haftalarda yapılacak.
  - İkinci vizenin test olmasının sebebi: klasik sınavları bilgisayardan okumak çok zor ve iki klasik sınav arka arkaya okunamaz.
- Kruskal'da bütün düğümlerin seçilmiş olması işin bittiğini göstermez.
  - Seçilen kenarlar birbirinden ayrı iki ağaç oluşturabilir. Bu ağaçların da bağlanması gerekir.
  - Durma koşulu: $n$ düğüm için $n-1$ kenar seçilmiş olmalı.
- Sınavda küçük graf verilse bile sonucu gözle bakıp yazmayın. Algoritmanın adımlarını gösterin.
- Karar ağacında kökten yaprağa giden bir yolda bir özellik yalnız bir kez kullanılır.
- Karar ağacının yüksekliği mümkün olduğunca küçük olmalı. Az soru sorarak sonuca ulaşmak istenir. Bu yüzden köke ve alt düğümlere konacak özellik rastgele değil, bilgi kazancına göre seçilir.
- Olasılık ile bilgi ters orantılıdır.
  - "Köpek beni ısırdı": olasılığı yüksek, taşıdığı bilgi az.
  - "Hoca köpeği ısırdı": olasılığı çok düşük, taşıdığı bilgi çok.
- Bir şeyin izomorfik olduğunu göstermek zordur. İzomorfik olmadığını göstermek kolaydır: tek bir şartın bozulduğunu bulmak yeter.
- İki komşu düğümün ortak bir komşusu varsa graf iki parçalı olamaz (üçgen oluşur).
- İki parçalı grafı bulmak için kendi algoritmanızı yazmayı deneyin. Grafı komşuluk matrisiyle ifade edin.
- Birinci vizenin ortalaması beklenenden düşük. Vizeden sonraki haftada en çok hata yapılan yerler anlatıldı. O kaydı yeniden izleyin.

## Kısa Tekrar Notları

- Kruskal: kenarları küçükten büyüğe sırala; döngü oluşturmayan en küçük kenarı seç; $n-1$ kenar seçilene kadar devam et.
- Karar ağacı: her ara düğüm bir soru, her dal bir cevap, her yaprak tek bir sınıftır.
- Entropi: $E(S) = -\sum_{i=1}^{c} p_i \log_2 p_i$. $p_i$, $i$. sınıfın oranıdır.
  - Bütün örnekler aynı sınıftaysa $E = 0$.
  - İki sınıf eşit dağılmışsa $E = 1$.
- Bilgi kazancı: $\text{Gain}(S, A) = E(S) - \sum_{v \in \text{Değerler}(A)} \frac{|S_v|}{|S|} E(S_v)$.
  - En büyük kazançlı özellik düğüme konur.
  - Alt düğümlerde $S$ yerine o dala düşen örnekler kullanılır.
- Ağaçlarda izomorfizm için gerekli şartlar: aynı düğüm sayısı, aynı kenar sayısı, aynı derece dizisi. Köklü ağaçta kök köke eşlenmeli. İkili ağaçta çocukların sol/sağ konumu da aynı olmalı.
- $n$ düğümlü izomorfik olmayan ikili ağaç sayısı: $\frac{1}{n+1}\binom{2n}{n}$. $n=3$ için 5.
- Graf türleri:

| Tür | Kenar | Paralel kenar | Döngü |
| :--- | :---: | :---: | :---: |
| Basit graf | yönsüz | yok | yok |
| Çoklu graf | yönsüz | var | yok |
| Sözde graf | yönsüz | var | var |
| Yönlü graf | yönlü | yok | var |
| Yönlü çoklu graf | yönlü | var | var |

- Özel graflar:

| Graf | Tanım | Düğüm sayısı | Kenar sayısı |
| :---: | :--- | :---: | :---: |
| $K_n$ | her düğüm diğer bütün düğümlere bağlı | $n$ | $\frac{n(n-1)}{2}$ |
| $C_n$ ($n \ge 3$) | $v_1 v_2 \dots v_n v_1$ çemberi | $n$ | $n$ |
| $W_n$ ($n \ge 3$) | $C_n$ + her düğüme bağlı bir merkez | $n+1$ | $2n$ |
| $Q_n$ | etiketleri tek bitte farklı olan $n$ bitlik dizgiler bağlı | $2^n$ | $n \cdot 2^{n-1}$ |
| $K_{m,n}$ | iki parçanın her düğümü karşı parçanın her düğümüne bağlı | $m+n$ | $m \cdot n$ |

- İki parçalı graf: düğümler, aynı parçadaki iki düğüm arasında kenar olmayacak şekilde iki ayrık kümeye ayrılabilir.

## Detaylı Açıklamalar

### Kruskal algoritması

Kruskal de Prim gibi en küçük kapsayan ağacı bulur. Üç adımdır:

1. Kenarları ağırlığına göre küçükten büyüğe sırala. Eşit ağırlıklı kenarların sırası önemli değildir.
2. Sıradaki kenarı seç. Kenar döngü oluşturuyorsa alma, sonrakine geç.
3. $n$ düğümlü grafta $n-1$ kenar seçilene kadar 2. adımı tekrarla.

**Birinci örnek (7 düğüm):** Önce 1'lik kenar, sonra dört tane 2'lik kenar seçilir. 5 kenarla bütün düğümler seçilmiş görünür. Ama seçilen kenarlar iki ayrı ağaç oluşturur. 7 düğüm için 6 kenar gerekir. Bu yüzden iki ağacı bağlayan bir 3'lük kenar daha seçilir. Toplam ağırlık $1+2+2+2+2+3 = 12$.

**İkinci örnek (9 düğüm, $3 \times 3$ ızgara):** Seçilen kenarlar: 1, 2, 2, 3, 3, 3. Sonra 4'lük kenarlar denenir. Döngü oluşturan 4'lükler atlanır. Bütün düğümler seçildiğinde 7 kenar vardır ve yine iki ayrı ağaç kalır. Bunları bağlayan bir 4'lük kenar daha seçilir. 8 kenar, toplam ağırlık 22.

Bir başka demo örneğinde ($u_0, \dots, u_5$) kenarlar 5, 5, 10, 10, 15, 15, 20, 30 sırasıyla denenir. $u_2u_4$ kenarı döngü oluşturduğu için atlanır. 6 düğüm için 5 kenar seçilince algoritma biter.

### Karar ağaçları ve sahte para problemi

Karar ağacında her ara düğümde bir soru sorulur. Cevaba göre bir dala gidilir. Yapraklarda tek bir sonuç (sınıf) kalır. Karar ağaçları ikili olmak zorunda değildir. Veri madenciliği, yapay zekâ ve doğal dil işleme derslerinde ID3, C4.5 ve rastgele orman (random forest) gibi algoritmalarla tekrar karşınıza çıkacak.

**Problem:** Görünüşü aynı 5 madeni para var. Biri sahte. Sahte para diğerlerinden ya ağır ya hafif. Terazi ile hangi paranın sahte olduğu ve ağır mı hafif mi olduğu bulunacak.

Terazinin üç sonucu vardır: sol ağır, denge, sağ ağır. Bu yüzden ağaçta her düğümden üç dal çıkar.

1. $C_1$ ile $C_2$ tartılır.
2. $C_1 > C_2$ ise sahte para bunlardan biridir. $C_1$, gerçek olduğu bilinen $C_5$ ile tartılır.
   - Denge varsa sahte $C_2$'dir ve hafiftir.
   - Denge yoksa sahte $C_1$'dir ve ağırdır.
3. $C_1 < C_2$ ise aynı yol izlenir: denge varsa $C_2$ ağır, yoksa $C_1$ hafif.
4. $C_1 = C_2$ ise sahte para $C_3$, $C_4$, $C_5$'ten biridir. $C_3$ ile $C_4$ tartılır.
   - $C_3 > C_4$ ise $C_3$ ile $C_5$ tartılır. Denge varsa $C_4$ hafif, yoksa $C_3$ ağırdır.
   - $C_3 < C_4$ ise denge varsa $C_4$ ağır, yoksa $C_3$ hafiftir.
   - $C_3 = C_4$ ise sahte $C_5$'tir. $C_1$ ile $C_5$ tartılır. $C_1$ ağır basarsa $C_5$ hafif, $C_5$ ağır basarsa $C_5$ ağırdır.

Ağaçta 10 yaprak vardır (5 para × ağır/hafif). En fazla 3 tartım yapılır.

### Sınıflandırma ve "tenis oynanır mı" veri seti

Veri setinde 14 örnek (gün) ve 4 özellik var:

- Hava durumu (outlook): güneşli (sunny), bulutlu (overcast), yağmurlu (rain).
- Sıcaklık (temperature): sıcak, ılık, serin.
- Nem (humidity): yüksek, normal.
- Rüzgâr (wind): zayıf, kuvvetli.

Sınıf etiketi: tenis oynanır (yes) veya oynanmaz (no). 9 örnek yes, 5 örnek no.

Ağaçtaki özellikler rastgele seçilirse ağaç gereğinden yüksek olabilir. Hocanın rastgele kurduğu ilk ağaçta kök nem, sonra rüzgâr, sonra hava durumuydu ve yükseklik 3'tü. Nem yüksek olan örnekler 1, 2, 3, 4, 8, 12, 14 numaralı günlerdir.

### Entropi ve bilgi kazancı

Bir olayın bilgisi olasılığıyla ters orantılıdır. Bilgi şöyle ölçülür: $I = \log_2 \frac{1}{p} = -\log_2 p$. Logaritma 2 tabanındadır, çünkü bilgi bit ile ölçülür.

Entropi, olayların olasılığı ile bilgisinin çarpımlarının toplamıdır:

$$E(S) = -\sum_{i=1}^{c} p_i \log_2 p_i$$

Logaritmalar negatif olduğu için başa eksi konur.

Örnekler:

- 10 örneğin 10'u yes: $E = -1 \cdot \log_2 1 = 0$. Veri homojendir.
- 10 örneğin 5'i yes, 5'i no: $E = -\frac{1}{2}\log_2\frac{1}{2} - \frac{1}{2}\log_2\frac{1}{2} = 1$.
- 14 örneğin 9'u yes, 5'i no: $E = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} \approx 0.940$.

Rüzgâr için bilgi kazancı:

- Zayıf: 8 örnek, 6 yes, 2 no. $E_{zayıf} = -\frac{6}{8}\log_2\frac{6}{8} - \frac{2}{8}\log_2\frac{2}{8} \approx 0.811$.
- Kuvvetli: 6 örnek, 3 yes, 3 no. $E_{kuvvetli} = 1$.
- $\text{Gain}(S, \text{wind}) = 0.940 - \frac{8}{14} \cdot 0.811 - \frac{6}{14} \cdot 1 \approx 0.048$.

Bütün özelliklerin kazançları:

| Özellik | Kazanç |
| :--- | :---: |
| Hava durumu | 0.246 |
| Nem | 0.151 |
| Rüzgâr | 0.048 |
| Sıcaklık | 0.029 |

Köke en büyük kazançlı özellik olan **hava durumu** konur:

- Bulutlu (3, 7, 12, 13): 4 yes, 0 no. Dal biter: tenis oynanır.
- Güneşli (1, 2, 8, 9, 11): 2 yes, 3 no. $E = 0.971$. Bu dalda nemin kazancı 0.971 ile en büyüktür. Nem yüksekse oynanmaz, normalse oynanır.
- Yağmurlu (4, 5, 6, 10, 14): 3 yes, 2 no. $E = 0.971$. Bu dalda rüzgârın kazancı 0.971 ile en büyüktür. Rüzgâr kuvvetliyse oynanmaz, zayıfsa oynanır.

Bu ağacın yüksekliği 2'dir. Rastgele kurulan ağaçta 3 soru gerekirken burada en fazla 2 soru yeter. Hava bulutluysa tek soru yeter.

### Ağaçlarda izomorfizm

İki ağaç arasında birebir ve örten bir eşleme, kenarları da koruyorsa ağaçlar izomorfiktir. Gerekli şartlar:

- Düğüm sayıları aynı olmalı. Bu sağlanmıyorsa diğer şartlara bakmaya gerek yoktur.
- Kenar sayıları aynı olmalı.
- Karşılıklı düğümlerin dereceleri aynı olmalı.
- Köklü ağaçta kök köke eşlenmeli.
- İkili ağaçta çocukların sol/sağ konumları da korunmalı.

Bir düğümün derecesi, o düğüme bağlı kenar sayısıdır.

Slayttaki dört ağaç (4 düğüm, 3 kenar, en tepedeki düğüm kök):

| Ağaç | Şekil | Derece dizisi |
| :---: | :--- | :---: |
| 1 | kökten üç yaprak (yıldız) | (1, 1, 1, 3) |
| 2 | kök - orta düğüm - iki yaprak | (1, 1, 1, 3) |
| 3 | kökten iki dal, biri iki uzunlukta | (1, 1, 2, 2) |
| 4 | dört düğümlü yol | (1, 1, 2, 2) |

Köklü ağaç olarak dördü de birbirinden farklıdır. Köklü olma bilgisi verilmeseydi 1 ile 2 ve 3 ile 4 kendi aralarında izomorfik olurdu.

İkili ağaçta, düğüm ve kenar sayıları aynı olsa bile, biri sola diğeri sağa dallanan iki ağaç izomorfik değildir. 3 düğümle 5 farklı ikili ağaç çizilebilir: $\frac{1}{4}\binom{6}{3} = \frac{20}{4} = 5$.

### Graf tanımı ve türleri

Graf, düğümler ve kenarlardan oluşan bir yapıdır: $G = (V, E)$. $V$ düğüm kümesi, $E$ kenar kümesidir. Kenarlar düğüm çiftleriyle yazılır: $E = \{\{v, w\}, \{w, y\}, \dots\}$.

- Yalıtılmış düğüm: hiçbir kenarı olmayan düğüm. Tek düğümlü graf "noktasal graf" diye anıldı.
- Paralel kenar: aynı iki düğüm arasında birden fazla kenar.
- Döngü (loop): bir düğümden çıkıp başka düğüme uğramadan aynı düğüme dönen kenar.
- Ağırlıklı graf: kenarlarda sayısal değerler olan graf (Prim örneğindeki gibi).
- Yönlü graf: her kenar sıralı bir düğüm çiftidir. Örnek: B'den C'ye doğrudan gidilemiyorsa B'den D'ye, D'den C'ye gidilir. Hoca bunu tek yönlü sokaklara benzetti.

Her basit graf aynı zamanda bir çoklu graftır. Ama paralel kenarı olan bir çoklu graf basit graf değildir.

### Benzerlik grafı

Problem: 5 program kodunu özelliklerine göre gruplamak. Özellikler: satır sayısı (lines of code), return sayısı, çağrılan fonksiyon sayısı.

| Kod | Satır | Return | Fonksiyon çağrısı |
| :---: | :---: | :---: | :---: |
| $v_1$ | 66 | 20 | 1 |
| $v_2$ | 41 | 10 | 2 |
| $v_3$ | 68 | 5 | 8 |
| $v_4$ | 90 | 34 | 5 |
| $v_5$ | 75 | 12 | 14 |

Benzer olmama (dissimilarity) fonksiyonu: $s(v, w) = \sum_{k=1}^{3} |p_k - q_k|$.

| | $v_2$ | $v_3$ | $v_4$ | $v_5$ |
| :---: | :---: | :---: | :---: | :---: |
| $v_1$ | 36 | 24 | 42 | 30 |
| $v_2$ | | 38 | 76 | 48 |
| $v_3$ | | | 54 | 20 |
| $v_4$ | | | | 46 |

Eşik değeri $N = 25$ alınır. Bu değer denemelerle belirlenir. $s(v, w) < N$ ise iki düğüm bir kenarla bağlanır. Kenarlar: $v_1v_3$ (24) ve $v_3v_5$ (20). Sonuç: $v_1, v_3, v_5$ birbirine benzeyen bir grup; $v_2$ ve $v_4$ ayrı.

### Özel graflar

- **$K_n$ (tam graf):** Her düğüm kendisi dışındaki bütün düğümlere bağlıdır. $K_4$'te 6 kenar vardır: $\frac{4 \cdot 3}{2} = 6$.
- **$C_n$ (çember graf):** Kenarlar $v_1v_2, v_2v_3, \dots, v_{n-1}v_n, v_nv_1$'dir. Kapalı bir döngü oluşturur.
- **$W_n$ (tekerlek graf):** $C_n$'ye yeni bir düğüm eklenir ve bu düğüm diğer bütün düğümlere bağlanır. Hoca bunu at arabası tekerleğine benzetti. Adındaki $n$, toplam düğüm sayısının bir eksiğidir. $W_6$ istenirse $C_6$ çizilip merkez düğüm eklenir.
- **$Q_n$ (küp graf):** $2^n$ düğüm vardır. Düğümler $n$ bitlik dizgilerle etiketlenir. Etiketleri tek bitte farklı olan düğümler bağlıdır (Gray kod mantığı). $Q_1$ tek kenar, $Q_2$ kare, $Q_3$ küptür. $Q_4$ iç içe iki küptür (hiperküp).

### İki parçalı graflar

Graf, düğümleri iki ayrık kümeye ($V_1 \cap V_2 = \emptyset$) bölünebiliyorsa ve her kenar bir kümeden diğerine gidiyorsa iki parçalıdır. Aynı kümedeki iki düğüm arasında kenar olamaz.

- $K_3$ iki parçalı değildir. 3 düğümü, aynı kümede komşu kalmayacak şekilde iki kümeye bölmek mümkün değildir.
- $C_6$ iki parçalıdır: $\{1, 3, 5\}$ ve $\{2, 4, 6\}$.
- Test sorusu örneği: bir düğüm (F) diğer bütün düğümlere bağlıysa ve diğer düğümler arasında da kenar varsa graf iki parçalı olamaz.
- Başka bir örnekte öğrenci $\{A, B, D\}$ ve $\{C, E, F, G\}$ ayırımını buldu. İki kümenin içinde de kenar yok, graf iki parçalıdır.

**Tam iki parçalı graf $K_{m,n}$:** Bir kümede $m$, diğerinde $n$ düğüm vardır. Her düğüm karşı kümedeki bütün düğümlere bağlıdır. Kenar sayısı $m \cdot n$'dir. Örnekler: $K_{2,3}$ (6 kenar), $K_{3,3}$ (9 kenar), $K_{2,6}$ (12 kenar).

### Ders sonrası notlar

- **Ford-Fulkerson:** Hoca slayttaki bağlantılar arasında Ford-Fulkerson'ı en küçük kapsayan ağaç yöntemi gibi andı. Ford-Fulkerson bir en büyük akış (maximum flow) algoritmasıdır. En küçük kapsayan ağaç için bilinen algoritmalar Prim, Kruskal ve Borůvka'dır.
- **Sahte para dalları:** Hoca bir dalı anlatırken "$C_1$ ile $C_5$ dengedeyse sahte $C_2$, çünkü $C_2$ ağır" dedi. $C_1 > C_2$ dalında denge varsa sahte para $C_2$'dir ve **hafiftir**. Doğru dallar yukarıda yazıldı.
- **Bilgi kazancı tablosu:** Hoca sıcaklık için "0.29" dedi. Doğru değer 0.029'dur. Hoca bir an "en büyük rüzgâr" dedi, sonra hava durumu olarak düzeltti. En büyük kazanç hava durumundadır (0.246).
- **Sistem entropisi:** Uygulama sırasında hoca sistemin entropisini "0.97" diye hatırladı. 9 yes, 5 no için doğru değer 0.940'tır. 0.97, güneşli ve yağmurlu dallarının entropisidir.
- **Dal üyeleri:** Hoca güneşli günleri "1, 8, 9, 11" diye saydı. Doğrusu 1, 2, 8, 9, 11'dir (5 örnek). Bulutlu günler 3, 7, 12, 13'tür.
- **Entropinin üst sınırı:** "Entropi 0 ile 1 arasındadır" ifadesi iki sınıf için doğrudur. $c$ sınıfta en büyük entropi $\log_2 c$'dir. Hoca ayrıca bir an "sadece yes varsa entropi 1" dedi, sonra 0 olarak düzeltti. Tek sınıflı veride entropi her zaman 0'dır.
- **Köksüz ağaçlarda izomorfizm:** Hoca "kök bilgisi yoksa düğüm ve kenar sayısına bakıp izomorfik dersiniz" dedi. Bu şartlar gereklidir ama yeterli değildir. Aynı düğüm sayılı her ağacın kenar sayısı zaten $n-1$'dir. Örneğin 4 düğümlü yıldız ile 4 düğümlü yol aynı düğüm ve kenar sayısına sahiptir ama izomorfik değildir. Derece dizisi de yalnız gerekli bir şarttır.
- **$K_n$ için $n$ sınırı:** Hoca "$n \ge 3$ olmalı, 2 düğümlü graf $K$ grafı olamaz" dedi. $K_1$ (tek düğüm) ve $K_2$ (tek kenar) da tam graftır. $n \ge 3$ şartı $C_n$ ve $W_n$ içindir. Hoca ayrıca "$n$ düğüm derecesini gösterir" dedi. $n$ düğüm sayısıdır. $K_n$'de her düğümün derecesi $n-1$'dir.
- **Tam graf ve iki parçalılık:** "Tam graf iki parçalı olamaz" ifadesi $n \ge 3$ için doğrudur. $K_1$ ve $K_2$ iki parçalıdır. Genel kural: graf ancak ve ancak tek uzunlukta çember içermiyorsa iki parçalıdır. Bu yüzden $C_n$, $n$ çift ise iki parçalıdır.
- **Kruskal ve Prim:** Hoca Kruskal'ı "Prim algoritmasının devamı" diye anlattı. İkisi aynı problemi çözen ayrı algoritmalardır. Prim tek bir ağacı büyütür. Kruskal ise ayrı ağaçlar (orman) oluşturup bunları birleştirir. Bu yüzden Kruskal'da ara adımlarda birden fazla ağaç görülmesi normaldir.
- **Kontrol:** Kruskal örneklerinin toplamları (12 ve 22), entropi ve bilgi kazancı değerleri, alt dalların kazançları, benzerlik tablosu ve Catalan sayıları Python ile doğrulandı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
