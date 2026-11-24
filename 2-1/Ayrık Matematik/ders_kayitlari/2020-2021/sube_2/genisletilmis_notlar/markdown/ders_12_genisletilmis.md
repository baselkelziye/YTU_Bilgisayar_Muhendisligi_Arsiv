# Ders 12 Genişletilmiş Notu: Euler Yolu, Dijkstra Tekrarı, Düzlemsel Graflar, Graf Boyama ve Kromatik Polinomlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Graf Gösterimleri: Geliş Matrisi ve Komşuluk Matrisi
- 2. Euler Yolu ve Euler Döngüsü
- 3. Dijkstra En Kısa Yol Algoritması Tekrarı
- 4. Düzlemsel Graflar, İzomorfizm ve Ağ Topolojileri
- 5. Graf Boyama ve Kromatik Sayı
- 6. Graf Boyama Uygulamaları
- 7. Kromatik Polinomlar ve Bilinen Graflar
- 8. Kenar Silme ve Birleştirme (Deletion-Contraction) Yöntemi
- 9. Ortak Nokta Yöntemi ve Polinom Çarpımı
- 10. Harita Boyama, BFS/DFS ve Görselleştirme Araçları
- 11. Kriptografiye Kısa Bir Bakış
- Örnek Sorular
- Dersin Toparlaması

## 1. Graf Gösterimleri: Geliş Matrisi ve Komşuluk Matrisi

Ders, önceki derste graf teorisine girilirken söylenmesi unutulan birkaç noktanın tekrarıyla başladı. İlki geliş (incidence) matrisidir. Hoca bu matrisin komşuluk matrisi gibi düşünülmemesi gerektiğini vurguladı. Geliş matrisinde satırlarda köşeler ($V_1, V_2, V_3, V_4$), sütunlarda kenarlar ($E_1,\dots,E_5$) bulunur. Bir köşe bir kenarın ucuysa o hücreye 1, değilse 0 yazılır. Örneğin $V_1$ yalnız $E_1$ ve $E_2$ ile ilişkiliyse $V_1$ satırında yalnız bu iki sütun 1, diğerleri 0 olur.

Komşuluk matrisinde ise hem satırlarda hem sütunlarda köşeler vardır. Hoca komşuluk matrisinin bir özelliğini hatırlattı: matrisin karesi alınırsa iki adımda, küpü alınırsa üç adımda gidilebilecek köşe çiftleri görülür.

> **Ek bilgi (derste anlatılmadı):** Daha kesin söylemek gerekirse $A^k$ matrisinin $(i,j)$ elemanı, $i$ köşesinden $j$ köşesine uzunluğu tam $k$ olan yürüyüşlerin (walk) sayısını verir. Sıfırdan farklı bir eleman, o iki köşe arasında $k$ adımlık bir geçişin var olduğunu gösterir.

## 2. Euler Yolu ve Euler Döngüsü

### 2.1 Kurallar

Hoca Euler ile ilgili kuralları tahtaya yazdı (ekrandan, 00:25:00):

- Bütün düğüm dereceleri çift olursa graf bir Euler grafıdır. Bu durumda hem Euler yolu hem Euler döngüsü vardır.
- Tek dereceli düğüm sayısı 2 ya da 0 ise Euler yolu vardır.

İkinci kuraldaki "0" durumu aslında birinci kuralı çağrıştırır: tek dereceli düğüm yoksa bütün dereceler çifttir. Tek dereceli düğümlerden söz ediliyorsa Euler yolu için bunların sayısı tam 2 olmalıdır.

Tanımlar da şöyle yazıldı:

- **Euler yolu:** Bütün kenarlardan birer kez geçerek bütün düğümler gezilir. Aynı kenardan iki kez geçilmez. Başlangıç noktasına geri gelme şartı yoktur.
- **Euler döngüsü (devresi, cycle):** Bütün kenarlardan birer kez geçerek bütün düğümler, başlangıç düğümüne geri gelecek şekilde gezilir.

### 2.2 Örnekler

İlk örnekte dört düğümlü bir graf çizildi. Kenarlar $1$–$2$, $2$–$3$, $3$–$4$ ve $4$–$2$'dir. Derecelere bakılırsa:

- $d(1)=1$, $d(2)=3$, $d(3)=2$, $d(4)=2$.

İki tek dereceli düğüm (1 ve 2) olduğu için Euler yolu şartı sağlanır. Gerçekten 1'den başlanırsa tek seçenek 2'ye gitmektir; sonra $2\to3\to4\to2$ ile bütün kenarlar birer kez kullanılır (ekrandan, 00:25:00): $1\to2\to3\to4\to2$. Ama 4'ten ya da 2'den 1'e dönülemediği için Euler döngüsü yoktur.

En basit Euler döngüsü örneği bir karedir: köşeler 1, 2, 3, 4 ve her köşenin derecesi 2'dir. Bütün dereceler çift olduğu için hem yol hem döngü vardır: $1\to2\to3\to4\to1$.

Önceki derste çizilen bir grafın dereceleri $2$, $4$, $3$, $3$ olarak sayıldı. İki tek dereceli düğüm vardır; bu yüzden Euler yolu vardır, ama bütün dereceler çift olmadığı için Euler döngüsü yoktur.

### 2.3 Euler döngülerinin sayısı

Hoca "Euler döngülerinin sayısı kaçtır?" diye sorulabileceğini söyledi ve şu yolu anlattı: her düğümün derecesinden 1 çıkarılır, her birinin faktöriyeli alınır ve bunlar çarpılır. Kare örneğinde her derece 2 olduğu için $1!\cdot1!\cdot1!\cdot1!=1$ bulunur.

> **Ders sonrası not:** Bu çarpım büyük olasılıkla yönlü graflar için verilen BEST teoreminin bir parçasıdır. Teoremde $\prod_v(\deg^+(v)-1)!$ çarpımı ayrıca bir köke yönelen kapsayan ağaçların sayısıyla çarpılır. Çarpım tek başına genel bir sayım formülü olarak kullanılmamalıdır.

## 3. Dijkstra En Kısa Yol Algoritması Tekrarı

> **Hocanın vurgusu:** Dijkstra algoritmasını çalışın; muhtemelen sınavda çıkar.

Dijkstra algoritmasında bir başlangıçtan bir bitişe en kısa yol aranır. Ulaşılan her noktada o ana kadarki en kısa yol bilgisi güncellenir. Slayttaki graf şöyledir (ekrandan, 00:30:00):

```text
Kenarlar (ağırlıklı, yönsüz):
a-b = 2    a-c = 3
b-d = 5    b-e = 2
c-e = 5    d-e = 1
d-f = 2    e-f = 4
```

$a$'dan $f$'ye gidilecektir. Başta yalnız $a$'nın komşuları bilinir: $b$'ye 2, $c$'ye 3 birimle gidilir. $a$ ziyaret edilmiş olarak işaretlenir, sonra $b$ ve $c$ üzerinden nerelere gidilebileceğine bakılır.

- $b$ üzerinden: $d$'ye $2+5=7$ ($7ab$), $e$'ye $2+2=4$ ($4ab$).
- $c$ üzerinden: $e$'ye $3+5=8$ ($8ac$). Bu, önceki 4'ten büyük olduğu için güncellenmez. $c$'den gidilecek başka düğüm yoktur.
- $e$ üzerinden: $d$'ye $4+1=5$ bulunur; önceki 7'den küçük olduğu için güncellenir ($5abe$). $f$'ye $4+4=8$ ($8abe$).
- $d$ üzerinden: $f$'ye $5+2=7$ ($7abed$). Bu 8'den küçüktür, güncellenir.

Slayttaki tablo (ekrandan, 00:30:00):

```text
       1.   2.   3.    4.         5.     6.
a      0    -
b      M    2a   -
c      M    3a   3a    -
d      M    M    7ab   7ab        5abe
e      M    M    4ab   8ac (X)    -
f      M    M    M     M          8abe   7abed
```

$M$ henüz ulaşılamayan (sonsuz) maliyeti gösterir. Sonuç: en kısa yol $a\to b\to e\to d\to f$, toplam maliyet 7.

Hücrelerde yolun tamamını ($abed$ gibi) yazmak şart değildir. Yalnız bir önceki düğüm tutulabilir: $f$'de $7d$, $d$'de $5e$, $e$'de $4b$, $b$'de $2a$. Sondan geriye doğru izlenerek (backtrace) $f$'ye $d$'den, $d$'ye $e$'den, $e$'ye $b$'den, $b$'ye $a$'dan gelindiği bulunur. Algoritmanın sonunda hem rota hem en kısa yol maliyeti elde edilir.

> **Hocanın vurgusu:** Bu tür sorularda sık yapılan hata, yolu doğrudan çizip bırakmaktır. Bu çözüm sayılmaz. Her adımı gösteren, bu matrise benzer bir tablonun doldurulması beklenir; tabloda ya son gelinen düğümün adresi ya da yolun tamamı tutulabilir.

## 4. Düzlemsel Graflar, İzomorfizm ve Ağ Topolojileri

### 4.1 Düzlemsel (planar) graf ve Euler formülü

Bir graf, kenarları birbirini kesmeyecek şekilde çizilebiliyorsa ona düzlemsel (planar) graf denir. Düzlemsel bir grafta düğüm sayısı $v$, kenar sayısı $e$ ve yüz (bölge) sayısı $f$ arasında Euler formülü geçerlidir:

$$v-e+f=2.$$

Hoca bu konuların bu derste bir tanıtım düzeyinde kaldığını, graf teorisi ve veri yapıları derslerinde daha ayrıntılı ve algoritmik versiyonlarının görüleceğini söyledi.

### 4.2 Graf izomorfizmi

İki grafın izomorfik olması için:

- düğüm sayıları aynı olmalı,
- kenar sayıları aynı olmalı,
- düğüm dereceleri aynı olmalı,
- komşuluk matrisleri aynı olmalı ya da satır ve sütunların yer değiştirmesiyle birbirine dönüşebilmeli.

İlk üç şart kolay kontrol edilir; son şart daha zorlayıcıdır. Slayttaki örnekte iki grafın da dört düğümü, dört kenarı vardır ve bütün dereceler 2'dir. Komşuluk matrislerinde $u_2$ ile $u_4$'ün satır ve sütunları yer değiştirince matrisler eşleşir; bu yüzden graflar izomorfiktir. Bir grafta dört, diğerinde altı düğüm varsa doğrudan izomorfik değil denir. Büyük graflarda bu kontrol, komşuluk matrisini girdi olarak alan bir algoritmayla yapılır.

### 4.3 Özel tip graflar ve ağ topolojileri

Slayttaki tanım (ekrandan, 00:35:00): özel tip graflar genellikle veri iletişimi ve paralel veri işleme uygulamalarında kullanılır. Yerel ağ (Local Area Network), bir bina içindeki bilgisayarları ve çevre birimlerini birbirine bağlar; bu ağların farklı topolojileri vardır.

- **Yıldız topoloji (star):** Bütün cihazlar merkezdeki cihaz (hub ya da switch) üzerinden birbirine bağlanır. $K_{1,n}$ tam iki parçalı (complete bipartite) graf kullanılır. Uçtaki iki bilgisayar doğrudan bağlı değildir; her biri merkezdeki cihaz üzerinden iletişim kurar.
- **Halka topoloji (ring):** Her bilgisayar yalnız bir öncekini ve bir sonrakini bilir; karşıdakine doğrudan erişemez. $C_n$ döngü grafıyla gösterilir.
- **Tekerlek (wheel):** Yıldız ve halkanın birleşimidir, $W_n$ ile gösterilir.

## 5. Graf Boyama ve Kromatik Sayı

### 5.1 Neden önemli?

Algoritmalar konusunda problemler çözülebilir (tractable) ve çözülemez (intractable) ya da NP-zor, NP-tam gibi sınıflara ayrılmıştı. Graf boyama, çözümü zor, üstel zamanda çözülebilen bir problemdir. Bilgisayar bilimlerinde algoritmik çözümlerin bu probleme ne kadar katkı sağlayabileceği çalışılmıştır. Hoca bu kısmın ortak slaytlardan çıkarıldığını, ama kendisinin anlatmayı gerekli gördüğünü belirtti.

### 5.2 Düğüm boyama ve kenar boyama

Slayttaki tanımlar (ekrandan, 00:40:00):

- **Düğüm / köşe / vertex / node boyama:** Birbirine komşu iki düğümün farklı renklerle boyanması problemidir.
- **Kenar / edge boyama:** Birbirine komşu (ortak bir düğümü olan) iki kenarın farklı renklerle boyanması problemidir.

Derste ağırlıklı olarak düğüm boyama işlendi; kenar boyamanın farklı uygulamaları olsa da graf teorisinin konusu olarak bırakıldı.

### 5.3 Permütasyon benzetmesi

Hoca düğüm boyamayı, permütasyon konusundaki bilinen bir soruyla ilişkilendirdi (ekrandan, 00:40:00):

- Rakamları birbirinden farklı kaç tane dört basamaklı sayı yazılabilir? $10\cdot9\cdot8\cdot7$, yani 10'un 4'lü permütasyonu $P(10,4)$. On basamaklı olsaydı $10!$ olurdu.
- Yalnız yan yana iki rakamın farklı olması istenirse: $10\cdot9\cdot9\cdot9$.

İkinci soru, dört düğümlü bir yol (çizgi) grafının boyanmasıdır: yan yana iki basamak komşu iki düğümdür. 10 yerine $x$ renk düşünülürse ilk düğüme $x$, sonrakilerin her birine $x-1$ renk verilebilir. Böylece bir polinom elde edilir (ekrandan, 00:40:00):

$$P(x)=x(x-1)(x-1)(x-1).$$

Bu polinom açıldığında $x^4$ ile başlar, işaretler değişerek ilerler ve sabit terim yoktur. Polinomdan en az renk sayısı şöyle bulunur: $x=0$ için sonuç 0, $x=1$ için sonuç 0'dır; $x=2$ için $P(2)=2\cdot1\cdot1\cdot1=2>0$. Demek ki bu graf en az 2 renkle boyanır ve 2 renkle 2 farklı boyama vardır: kırmızı-sarı-kırmızı-sarı ya da sarı-kırmızı-sarı-kırmızı.

Bu fonksiyona birazdan kromatik polinom denecektir. Polinom yoluyla en az renk sayısı ve o renk sayısıyla yapılabilecek farklı boyama sayısı analitik olarak bulunur.

### 5.4 Üçgen ve uç düğüm örneği

Slayttaki küçük graflarda bir üçgen ve üçgenin bir köşesine bağlı bir uç düğüm vardır. Üç köşe birbirini gördüğü için üçgene $x$, $x-1$, $x-2$ renk verilir. Uç düğüm yalnız bağlı olduğu köşeyle farklı olmak zorundadır; ona $x-1$ renk verilebilir. Hoca önce uç düğüme de $x-2$ yazıp $x(x-1)(x-2)^2$ dedi, sonra düzeltti: uç düğüm iki farklı renk alabilir, bu yüzden $x-1$ olmalıdır. Sonuç:

$$P(x)=x(x-1)^2(x-2).$$

$P(1)=0$, $P(2)=0$, $P(3)=3\cdot2^2\cdot1=12$. Yani graf en az 3 renkle ve 12 farklı şekilde boyanır. Slayttaki 12 farklı boyanmış graf bu sayıyla örtüşür (ekrandan, 00:40:00).

Hoca polinomu bu şekilde, permütasyon mantığıyla yazmanın karmaşık graflarda zor olduğunu, sınavda bu yolun istenmeyeceğini ve diğer tekniklerin (bölüm 8 ve 9) kullanılacağını söyledi.

### 5.5 Kromatik sayı

Tanım: $G$ grafının komşu iki düğümüne aynı renk atanmayacak şekilde her düğüme bir renk atanmasına graf renklendirme (graph coloring) problemi denir. Grafın renk (kromatik) sayısı, renklendirme için gereken en az renk sayısıdır ve $\chi(G)$ ile gösterilir.

Slayttaki örnekler (ekrandan, 00:45:00 ve 00:50:00):

- **$K_4$ (köşegenleriyle birlikte kare):** "$\chi(G)=3$ renk mi, 4 renk mi?" Her düğüm diğer üçünü görür. Bir düğüme $x$ renk verilirse komşusu $x-1$, sonraki $x-2$, sonuncusu $x-3$ renk alır. 4 farklı renk gerekir: $\chi(K_4)=4$.
- **Kare ve merkez düğüm:** Dört köşe kare oluşturur, merkez düğüm dört köşeye bağlıdır; köşegenler köşeleri doğrudan birleştirmez. Merkeze bir renk verildikten sonra karşılıklı köşeler aynı rengi alabilir. Gereken renk sayısı 3'tür. Slaytta başta $\chi(G)=4$ yazıyordu; hoca bunun hatalı olduğunu söyleyip derste 3 olarak düzeltti (ekrandan, 00:50:00).
- **Altıgen tekerlek:** Altı köşe ve merkez düğüm; $\chi(G)=3$ (ekrandan, 00:50:00). Merkeze bir renk, çevredeki köşelere sırayla diğer iki renk verilir.

## 6. Graf Boyama Uygulamaları

### 6.1 Sınav çizelgeleme

Öğrencilerin aldığı derslere göre sınav programı yapılacaktır; aynı öğrencinin iki sınavı çakışmamalıdır. Soru: en az kaç sınav oturumu gerekir?

Önce öğrenciler üzerinden bir liste söylendi, sonra daha kısa olduğu için dersler üzerinden gidildi. Tahtaya yazılan liste (ekrandan, 00:50:00):

```text
1. ders : A, B, C, D
2. ders : A, B, X, Y
3. ders : X, A
4. ders : T, L, B
```

Dersler düğüm olur; ortak öğrencisi olan iki ders arasına kenar konur (bir öğrenci bile olsa çakışma vardır):

- 1 ve 2: ortak A, B → kenar.
- 1 ve 3: ortak A → kenar.
- 2 ve 3: ortak A, X → kenar.
- 1 ve 4: ortak B → kenar.
- 2 ve 4: ortak B → kenar.
- 3 ve 4: ortak öğrenci yok → kenar yok.

Renkler sınav saatleridir. 1 ve 2 birbirine ve 3, 4'e bağlıdır; 3 ile 4 arasında kenar yoktur. En az 3 sınav saati gerekir: 3. ve 4. derslerin sınavı aynı saatte yapılabilir, ama örneğin 1 ile 3 ya da 2 ile 3 aynı saatte yapılamaz.

> **Ders sonrası not:** Hoca bu grafın polinomunu $x(x-1)^2(x-2)$ olarak söyledi ve önceki örnekle aynı graf çıktığını belirtti. Bu graf ise $K_4$'ten bir kenarı eksik (elmas) graftır; polinomu $x(x-1)(x-2)^2=x^4-5x^3+8x^2-4x$'tir (bölüm 9'daki slayt örneğiyle aynı). En az renk sayısı yine 3'tür, yani sonuç değişmez; 3 saatle $3\cdot2\cdot1\cdot1=6$ farklı atama vardır.

### 6.2 Kurul toplantıları

Slayttaki ikinci uygulama: bir üniversitede profesör unvanlı akademisyenlerden oluşan 10 kurul vardır, her kurul haftada bir kez toplanır ve bir akademisyen birden fazla kurulda görev alabilir. Toplantıların en kısa sürede ve çakışmasız tamamlanması için kaç farklı toplantı zamanı gerekir? Modelleme: düğümler kurullar, kenarlar ortak akademisyeni olan kurullar, renkler toplantı zamanlarıdır. Slayttaki graf için permütasyon mantığıyla ilerlenip ($x$, $x-1$, birbirini gören üçlülerde $x-2$, ...) sonucun 4 çıktığı söylendi.
<!-- BELİRSİZ: Kurul örneğinin grafı karelerde okunacak boyutta görünmüyor; yalnız sonucun 4 olduğu altyazıdan alındı. -->

## 7. Kromatik Polinomlar ve Bilinen Graflar

### 7.1 Tanım ve kullanım

$G$ grafının kromatik polinomu $P(G,x)$ (ya da $P(G,k)$), $x$ renk varken grafın kaç farklı şekilde boyanabileceğini verir. Polinom bulunduktan sonra $P(G,k)>0$ yapan $k$ değerleri aranır. Bu değerlerin en küçüğü kromatik sayıdır: örneğin $k=2$, 3 ve 4 için polinom pozitifse esas alınan 2'dir. $P(G,\chi(G))$ değeri ise en az renkle yapılabilecek farklı boyama sayısıdır. Hoca, kromatik polinom bulmanın graf büyüdükçe algoritmik karmaşıklığı artan bir problem olduğunu söyledi.

Analitik çözümde amaç, herhangi bir grafı bilinen graflar cinsinden yazmaktır.

### 7.2 Bilinen graflar

Slayttaki tablo (ekrandan, 00:55:00):

- **Noktasal graf (tek düğüm):** $P(G,x)=x$.
- **Çizgisel graf (iki düğüm, bir kenar):** $P(G,x)=x(x-1)$.
- **U grafı ($n$ düğümlü yol):** İlk düğüme $x$, diğer $n-1$ düğümün her birine $x-1$ renk verilir: $U_n=x(x-1)^{n-1}$.
- **Z grafı ya da K grafı (tam graf):** Üçgende $x$, $x-1$, $x-2$; genel olarak $K_n=\prod_{k=0}^{n-1}(x-k)=x(x-1)(x-2)\cdots(x-n+1)$.
- **Yıldız graf:** Dört yapraklı yıldızda merkeze $x$, yaprakların her birine $x-1$: $x(x-1)^4$.
- **İki parçalı (bipartite) graf:** Bir düğüm grubu bir tarafta, diğeri öbür tarafta; taraf içinde bağlantı olmadığı için bir tarafa bir renk, öbür tarafa başka renk verilir. 2 renkle boyanır.
- **Petersen grafı:** Bilinen özel bir graftır; kromatik polinomu 10. dereceden ve oldukça karmaşıktır. Hoca bu tür polinomların köklerini bulmanın çok zor noktalara gittiğini göstermek için örnek verdi.

## 8. Kenar Silme ve Birleştirme (Deletion-Contraction) Yöntemi

### 8.1 Yöntem

Karmaşık bir grafta bir kenar silinir ve silinen kenarın uç düğümleri birleştirilir; böylece graf daha basit graflar cinsinden yazılır. $u$ ve $v$ köşeleri arasında bir $e$ kenarı varsa:

- $G-e$: $e$ kenarı silinerek elde edilen graf.
- $G/e$: $u$ ile $v$ tek bir düğümde birleştirilerek elde edilen graf.

$$P(G,x)=P(G-e,x)-P(G/e,x).$$

Sezgi: $G-e$ boyamalarında $u$ ve $v$ aynı renkte de olabilir; bu boyamalar $G/e$ boyamalarına karşılık gelir ve çıkarılır. Hoca bu formülün uzun ispatları olan bir teorem olduğunu, matematiksel temellerinin derin olduğunu ve bu ders için yalnız mantığını bilmenin yeterli olduğunu söyledi.

### 8.2 Kromatik polinom özellikleri

Slayttaki özellikler (ekrandan, 01:00:00):

$$P(x)=a_0x^n-a_1x^{n-1}+a_2x^{n-2}+\dots a_nx^0$$

1. En yüksek dereceli terimin katsayısı $a_0=1$ olmalıdır (2, 3, 4 gibi olamaz).
2. Polinomun derecesi $n$, düğüm sayısını verir.
3. Polinomun 2. büyük teriminin katsayısı kenar sayısını verir (negatif çıkar, mutlak değeri alınır).
4. Katsayılar toplamı 0 olmalıdır: $P(1)=0$.
5. Katsayılar $+,-,+,-$ düzeninde olmalıdır.
6. Sabit terim olmamalıdır: $P(0)=0$.

Hoca 4. ve 5. maddenin katsayılar üzerine kural olduğunu, polinomu uzun uzun açmadan $P(1)=0$ çıkıyorsa doğru yolda olunduğunu söyledi. Kromatik sayı, $P(k)>0$ yapan en küçük $k$'dır; $P(k)$ o durumdaki farklı boyama sayısıdır.

### 8.3 Örnek: $K_4$ grafı

$K_4$'ün permütasyon mantığıyla polinomu $x(x-1)(x-2)(x-3)$'tür. Aynı sonuç deletion-contraction ile bulunur (ekrandan, 01:05:00). Köşeler 1, 2, 3, 4 olarak numaralandırılır (numaralandırma sırası önemli değildir).

```text
Adım 1: 1-3 kenarı silinir.
        P(K4) = P(K4 - e) - P(a)
        (a): 1 ile 3 birleşir -> {1,3}, 2, 4 köşeli üçgen.

Adım 2: K4 - e grafında 2-4 kenarı silinir.
        P(K4 - e) = P(kare) - P(b)
        (b): 2 ile 4 birleşir -> 1 - {2,4} - 3 yolu (3 düğüm).

Adım 3: Karede 2-3 kenarı silinir.
        P(kare) = P(c) - P(d)
        (c): 3 - 4 - 1 - 2 yolu (4 düğüm, U grafı)
        (d): 2 ile 3 birleşir -> 1, {2,3}, 4 köşeli üçgen.
```

Böylece $P(K_4)=P(c)-P(d)-P(b)-P(a)$ olur. Parçalar bilinen graflardır:

- $P(a)=P(d)=x(x-1)(x-2)$,
- $P(b)=x(x-1)^2$,
- $P(c)=x(x-1)^3$.

Yerine yazılırsa:

$$P(K_4)=x(x-1)^3-x(x-1)(x-2)-x(x-1)^2-x(x-1)(x-2)=x^4-6x^3+11x^2-6x.$$

Açılım $x(x-1)(x-2)(x-3)$ ile aynıdır. Kontrol: 4 düğüm (derece 4), 6 kenar (ikinci katsayı $-6$), işaretler $+,-,+,-$, sabit terim yok. $P(1)=P(2)=P(3)=0$; $P(4)=4\cdot3\cdot2\cdot1=24$. Demek ki $K_4$ en az 4 renkle ve 24 farklı şekilde boyanır.

**Soru:** Kenar silindikten sonra 1 ve 3 aynı renge boyanabilir mi? **Cevap:** Evet; aralarındaki kenar kalktığı için aynı rengi alabilirler. Aynı renk aldıkları boyamalar birleştirilmiş grafa ($G/e$) karşılık gelir.

> **Hocanın vurgusu:** Bu konudan sınavda (özellikle finalde) soru gelir. Deletion-contraction yöntemiyle farklı örnekler çözmekte fayda var; ama çok karmaşık graflarla abartmamak gerekir.

## 9. Ortak Nokta Yöntemi ve Polinom Çarpımı

### 9.1 Yöntem

Slayttaki ifade (ekrandan, 01:10:00): Bir graf noktasal ya da çizgisel bir graf ile ayrılırsa, kromatik polinom çarpım ve bölüm cinsinden bu ortak parçaya göre yazılabilir:

$$P(G)=\frac{P(G_1)\cdot P(G_2)}{P(G_1\cap G_2)}.$$

Ortak parça tek nokta ise bölen $x$, tek kenar (çizgisel graf) ise $x(x-1)$'dir. Hoca bunun da matematiksel temeli olan bir teorem olduğunu belirtti.

### 9.2 Örnek: elmas graf (Örnek Soru-2)

Graf, köşeleri 1, 2, 3, 4 olan bir kare ve 2 ile 4'ü birleştiren köşegenden oluşur (ekrandan, 01:10:00). 2–4 kenarı boyunca iki üçgene ayrılır: (1, 2, 4) ve (2, 3, 4). Ortak parça 2–4 çizgisel grafıdır.

$$P(G)=\frac{x(x-1)(x-2)\cdot x(x-1)(x-2)}{x(x-1)}=\frac{x^2(x-1)^2(x-2)^2}{x(x-1)}=x(x-1)(x-2)^2.$$

Sağlama (permütasyon mantığı): 4'e $x$, 1'e $x-1$, 2'ye $x-2$ (hem 1'i hem 4'ü görür), 3'e $x-2$ (2'yi ve 4'ü görür) renk verilir; sonuç yine $x(x-1)(x-2)^2$.

Açılım (ekrandan, 01:10:00 ve 01:15:00):

$$(x^2-x)(x^2-4x+4)=x^4-5x^3+8x^2-4x.$$

Kontrol: $x^4$ (4 düğüm), $5x^3$ (5 kenar), katsayılar doğru sıralı, sabit terim yok. $G(0)=G(1)=G(2)=0$, $G(3)=6$. Demek ki en az 3 renkle, $3\cdot2\cdot1=6$ farklı şekilde boyama yapılabilir.

> **Hocanın vurgusu:** Soruda "ortak nokta ile çözün" ya da "deletion-contraction ile çözün" denirse o yöntem kullanılmalıdır. Permütasyon mantığıyla doğrudan yazmak yalnız sağlama için kullanılabilir.

### 9.3 Örnek: bir noktada birleşen iki üçgen

İkinci örnekte iki üçgen tek bir ortak düğümde birleşir. Kenar silmek burada daha zahmetlidir; ortak parça noktasal grafdır. İki üçgenin polinomu da $x(x-1)(x-2)$'dir:

$$P(G)=\frac{[x(x-1)(x-2)]^2}{x}=x(x-1)^2(x-2)^2=x^5-6x^4+13x^3-12x^2+4x.$$

5 düğüm ve 6 kenar vardır; katsayılar doğru sıralıdır, sabit terim yoktur. $P(0)=P(1)=P(2)=0$, $P(3)>0$ olduğu için en az 3 renk gerekir. Hoca katsayıların (13, 12, 4 gibi) graf teorisinde başka anlamları da olabileceğini, belki keşfedilmeyi bekleyen ilişkiler olduğunu söyledi.

> **Ders sonrası not:** Hoca bu grafın 3 renkle 6 farklı şekilde boyandığını söyledi. Polinomdan $P(3)=3\cdot2^2\cdot1^2=12$ çıkar: ortak düğüme 3 renk, her üçgenin kalan iki düğümüne $2\cdot1$ seçenek, toplam $3\cdot2\cdot2=12$. Doğru sayı büyük olasılıkla 12'dir.

### 9.4 Polinom çarpımı için konvolüsyon

Ortak slaytlarda polinom çarpımı için pratik bir yol gösterildi (ekrandan, 01:15:00). Katsayıların mutlak değerleri yazılır, biri kaydırılarak çarpılır ve toplanır; işlem ayrık zamanlı sinyallerdeki konvolüsyonun aynısıdır:

```text
    1 4 4        (x^2 - 4x + 4)
    1 1          (x^2 - x)
  ---------
    1 4 4
      1 4 4
  + ---------
    1 5 8 4
```

Katsayılara sırayla $+,-,+,-$ işareti verilir: $x^4-5x^3+8x^2-4x$. Hoca aynı yolu $1\,5\,6$ ($x^2-5x+6$) ile $1\,1$ ($x^2-x$) için de gösterdi; sonuç $1\,6\,11\,6$, yani $x^4-6x^3+11x^2-6x$ ($K_4$ polinomu) olur.

### 9.5 İki yöntemin birlikte kullanıldığı örnek

Ortak slaytlardaki bir örnekte önce bir kenar silinir: $G/e$ grafı üst üste katlanınca $x(x-1)(x-2)$ polinomlu bir üçgene dönüşür. Kalan $G-e$ kısmı ortak nokta yöntemiyle çözülür. Sonuç olarak $x^4-6x^3+11x^2-6x$ bulunur: 4 köşe, 6 kenar, işaretler doğru; en az 4 renk gerekir.
<!-- BELİRSİZ: Bu örneğin grafı ve ara adımları karelerde görünmüyor; yalnız altyazıdaki sonuç aktarıldı. -->

Son olarak 8. dereceden polinomu olan daha büyük bir örnek gösterildi. Böyle polinomlarda $x$'e 0, 1, 2, ... değerleri bir programla verilerek ya da çarpanlara ayırarak en az renk sayısı bulunabilir; bu örnek sonraki derslere alıştırma olarak bırakıldı.

## 10. Harita Boyama, BFS/DFS ve Görselleştirme Araçları

### 10.1 Harita boyama problemi

Graf boyamanın çok eskiden beri çalışılan bir uygulamasıdır: komşu şehirler (bölgeler) farklı renklere boyanmak istenir. Şehirlerin komşuluk ilişkisi grafa dökülünce kromatik sayının en fazla 4 olduğu görülür; beşinci renge gerek yoktur.

> **Ek bilgi (derste anlatılmadı):** Bu sonuç Dört Renk Teoremi olarak bilinir. Düzlemsel her graf en fazla dört renkle boyanabilir; teorem büyük olasılıkla 1976'da Appel ve Haken tarafından bilgisayar destekli olarak ispatlanmıştır.

### 10.2 BFS ve DFS

Hoca önceki derste anlatılan BFS ve DFS'yi kısaca tekrar etti. BFS (genişlik öncelikli arama) kuyruk, DFS (derinlik öncelikli arama) yığın kullanır. Bir matris (ızgara) üzerinde bir noktadan diğerine aranırken BFS yayılarak ilerler: başlangıcın komşuları 2, onların komşuları 3 diye katman katman işaretlenir. DFS ise bir yönde sonuna kadar gider (1, 1, 1, 1), sonra geri dönüp diğer yolları dener.

> **Hocanın vurgusu:** BFS ve DFS'nin farkı iyi bilinmeli. "BFS ile ilerlerken üçüncü adımda kuyrukta ne vardır?", "ikinci adımda hangi düğüm ziyaret edilir?" gibi sorular test türü sınavlarda kolayca sorulabilir.

### 10.3 Görselleştirme siteleri

Hoca bir algoritma görselleştirme sitesinde Dijkstra algoritmasını çalıştırdı: graf oluşturulur, başlangıç düğümü (örneğin 0) seçilir ve maliyetlerin adım adım güncellenmesi izlenir. Aynı sitede komşuluk matrisi ve komşuluk listesi gösterimleri, yönlü ve yönsüz graflarda BFS ile topolojik sıralama gibi algoritmalar da vardır. Graf boyama algoritmalarını anlatan bir sayfada (ekrandan, 01:25:00) toplam boyama (total coloring) tanımı da görülür: düğümler ve kenarlar birlikte boyanır; komşu düğümler, komşu kenarlar ve bir kenarla uç düğümleri aynı renge boyanmaz. Gereken en az renk sayısı toplam kromatik sayı $\chi''(G)$'dir.

## 11. Kriptografiye Kısa Bir Bakış

Bir öğrenci kriptografi konusunun hangi derse ait olduğunu sordu. Hoca, ayrık matematik kitaplarında kriptografinin sayı teorisi, modüler aritmetik ve bölünebilmeden sonra temel bir giriş olarak anlatıldığını, ama bu derste algoritma analizine daha çok zaman ayrıldığı için işlenmediğini söyledi. Ardından kısa bir giriş yaptı (ekrandan, 01:30:00):

- **Afin şifreleme:** Karakterlerin sayısal karşılıkları ($x$) kullanılır; örneğin "Ali" kelimesindeki "A" harfinin karakter kodu 65'tir. $a$ ve $b$ sayıları anahtardır:
  $$y=(ax+b)\bmod 26.$$
  Alıcı aynı $a$ ve $b$ ile fonksiyonun tersini alır: $x=\dfrac{y-b}{a}$. Mod 26'da bölme yerine $a$'nın çarpmaya göre tersiyle çarpılır, yani $x=a^{-1}(y-b)\bmod 26$. $a$ ve $b$ iki kişi arasında önceden kararlaştırılır.
- **Sezar şifreleme:** $a$ olmadan, $y=x+b$. Tersine çevirmek çok kolaydır.
- **RSA:** Bir anahtar herkese açıktır; karşı taraf bundan farklı bir çözme anahtarıyla mesajı çözer. Bir anahtar şifreleme, öbürü şifre çözme içindir.

> **Ders sonrası not:** Hoca afin şifrelemeyi önce "açık anahtarlı" diye andı, sonra "gizli" dedi. Afin ve Sezar şifrelemeleri aynı gizli anahtarın iki tarafça kullanıldığı simetrik yöntemlerdir; açık anahtarlı yöntem RSA'dır. Ayrıca afin şifrede çözmenin mümkün olması için $a$'nın 26 ile aralarında asal olması gerekir.

Hoca son olarak dersin yerini anlattı: ayrık matematik eskiden olasılık, hesaplama kuramı, graf teorisi ve kriptografi gibi konuları geniş biçimde kapsıyordu; bugün bu konuların her biri ayrı bir derstir. Ayrık matematik artık programlama ve algoritmaya giriş görmüş, ama veri yapılarını henüz görmemiş öğrenciler için bir geçiş dersi işlevi görür. Sonlu durum makineleri (finite state machine) konusunun hesaplama kuramı dersinde ayrıntılı işleneceği, bu derste kısa bir giriş yapılacağı söylendi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Kenar ağırlıkları $a$–$b$=2, $a$–$c$=3, $b$–$d$=5, $b$–$e$=2, $c$–$e$=5, $d$–$e$=1, $d$–$f$=2, $e$–$f$=4 olan grafta Dijkstra algoritmasıyla $a$'dan $f$'ye en kısa yolu tablo doldurarak bulunuz.

> **Çözüm:** Tablo bölüm 3'tedir. Seçim sırası $a, b, c, e, d, f$. $e$'nin değeri $4ab$ kalır ($8ac$ güncellenmez), $d$ $7ab$'den $5abe$'ye, $f$ $8abe$'den $7abed$'ye güncellenir. En kısa yol $a\to b\to e\to d\to f$, maliyet 7.

**Soru 2** (derste sözlü, 00:25:35): Dereceleri 2, 4, 3, 3 olan grafta Euler yolu ve Euler döngüsü var mıdır?

> **Çözüm:** İki tek dereceli düğüm vardır; Euler yolu vardır. Bütün dereceler çift olmadığı için Euler döngüsü yoktur.

**Soru 3** (ekrandan, 00:45:00): $K_4$ grafının (köşegenleriyle kare) ve kareye merkez düğüm eklenmiş grafın kromatik sayısı kaçtır? $\chi(G)=3$ mü, $4$ mü?

> **Çözüm:** $K_4$'te her düğüm diğer üçüne komşudur: $\chi=4$. Merkez düğümlü karede karşılıklı köşeler aynı rengi alabilir: $\chi=3$ (ekrandan, 00:50:00).

**Soru 4** (ekrandan, 00:50:00): Altıgen tekerlek grafının kromatik sayısı kaçtır?

> **Çözüm:** Merkeze bir renk, çevredeki altı köşeye sırayla iki renk verilir: $\chi=3$.

**Soru 5** (ekrandan, 00:50:00): 1. dersi A, B, C, D; 2. dersi A, B, X, Y; 3. dersi X, A; 4. dersi T, L, B öğrencileri alıyor. Çakışma olmaması için en az kaç sınav saati gerekir?

> **Çözüm:** Kenarlar $1$–$2$, $1$–$3$, $2$–$3$, $1$–$4$, $2$–$4$. Polinom $x(x-1)(x-2)^2$; $P(1)=P(2)=0$, $P(3)=6$. En az 3 saat; 3. ve 4. derslerin sınavı aynı saatte yapılabilir.

**Soru 6** (ekrandan, 01:05:00): $K_4$ grafının kromatik polinomunu deletion-contraction yöntemiyle bulunuz; en az kaç renkle ve kaç farklı şekilde boyanır?

> **Çözüm:** $P(K_4)=P(c)-P(d)-P(b)-P(a)=x(x-1)^3-2x(x-1)(x-2)-x(x-1)^2=x^4-6x^3+11x^2-6x$. $P(4)=24$: en az 4 renk, 24 farklı boyama.

**Soru 7** (ekrandan, 01:10:00): Kare ve bir köşegenden oluşan grafın kromatik polinomunu ortak nokta yöntemiyle bulunuz. En az kaç renk gerekir, en az renkle kaç farklı boyama yapılır?

> **Çözüm:** $\dfrac{x^2(x-1)^2(x-2)^2}{x(x-1)}=x(x-1)(x-2)^2=x^4-5x^3+8x^2-4x$. $G(0)=G(1)=G(2)=0$, $G(3)=6$: en az 3 renk, 6 farklı boyama.

**Soru 8** (derste sözlü, 01:11:03): Bir noktada birleşen iki üçgenden oluşan grafın kromatik polinomunu ortak nokta yöntemiyle bulunuz.

> **Çözüm:** $\dfrac{[x(x-1)(x-2)]^2}{x}=x(x-1)^2(x-2)^2=x^5-6x^4+13x^3-12x^2+4x$. En az 3 renk; $P(3)=12$ farklı boyama (hoca derste 6 dedi, bkz. bölüm 9.3).

## Dersin Toparlaması

Bu derste graf teorisinin kalan konuları tamamlandı. Euler yolu ve döngüsü için derece şartları, Dijkstra algoritmasının tabloyla adım adım çözümü, düzlemsel graflar için $v-e+f=2$, izomorfizm şartları ve yıldız, halka, tekerlek gibi ağ topolojilerini modelleyen özel graflar tekrar edildi. Ardından graf boyamaya geçildi: komşu düğümlerin farklı renk alması kuralı, kromatik sayı $\chi(G)$ ve sınav ya da toplantı çizelgeleme gibi uygulamalar anlatıldı.

Dersin ana kısmı kromatik polinomlardı. $P(G,x)$ polinomu, $x$ renkle kaç farklı boyama yapılabileceğini verir; $P(G,k)>0$ yapan en küçük $k$ kromatik sayı, $P(G,\chi)$ ise en az renkle farklı boyama sayısıdır. Polinom, grafı bilinen graflara (nokta, çizgi, yol, tam graf) indirgeyen iki yöntemle bulunur: kenar silme ve birleştirme $P(G)=P(G-e)-P(G/e)$ ve ortak nokta yöntemi $P(G)=P(G_1)P(G_2)/P(G_1\cap G_2)$. Bulunan polinomun özellikleri (baş katsayı 1, derece = düğüm sayısı, ikinci katsayı = kenar sayısı, alternatif işaretler, sabit terim yok) sonucu kontrol etmek için kullanılır. Ders, harita boyama, BFS/DFS farkı ve öğrenci sorusu üzerine kısa bir kriptografi girişiyle kapandı; sonlu durum makinelerine sonraki derste kısa bir giriş yapılacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
