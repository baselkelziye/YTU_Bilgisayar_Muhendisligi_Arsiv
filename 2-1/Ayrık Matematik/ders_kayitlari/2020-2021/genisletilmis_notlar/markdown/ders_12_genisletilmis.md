# Ders 12 Genişletilmiş Notu: Euler ve Hamilton Çizgeleri, Dijkstra Algoritması, Çizge Modelleri, Eşyapı ve Kromatik Polinomlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çizge Türlerinin Kısa Tekrarı
- 2. Yol ve Devre
- 3. Euler Devresi ve Euler Çizgesi
- 4. Düğüm Derecesi ve Derece Teoremleri
- 5. Euler Çizgesi Alıştırmaları
- 6. Hamilton Devresi ve Hamilton Çizgesi
- 7. Dijkstra En Kısa Yol Algoritması
- 8. Çizge Modelleri
- 9. Öncelik (Precedence) Çizgesi
- 10. Düzlemsel Çizgeler ve Euler Formülü
- 11. Çizgelerde Eşyapı (İzomorfizm)
- 12. Ağ Topolojileri ve Çizge Türleri
- 13. Çizge Boyama ve Kromatik Sayı
- 14. Kromatik Polinom ve Silme-Büzme Yöntemi
- 15. Bilinen Çizgelerin Kromatik Polinomları
- 16. $K_4$ Örneği
- 17. Ortak Düğüm veya Kenarla Birleşen Çizgeler
- 18. Kromatik Polinomun Doğruluk Kontrolleri
- 19. Eski Vize Sorusu: $K_4$'ün Farklı Bir Çizimi
- 20. Son Örnek: $W_4$ Çizgesi

## 1. Çizge Türlerinin Kısa Tekrarı

Ders Zoom üzerinden yapıldı. Hoca, çizgeler (graphs) konusunu bu derste bitirip kromatik polinomlara (chromatic polynomials) başlayacağını söyledi. Kromatik polinomları, çizgelerde görülen bilgilerin üzerine kurulan, öğrencilerin daha önce hiç görmediği farklı bir konu olarak tanıttı. Normalde bu konuyu tahtada renkli tebeşirle anlattığını, bu dönem şekilleri elle tek tek renklendirerek hazırladığını belirtti.

Önce çizge türleri kısaca hatırlatıldı. Bir çizge düğümlerden (vertex) ve kenarlardan (edge) oluşur. Türleri basit çizgeden (simple graph) başlar. Ardından paralel kenarlı çizgeler, çoklu çizgeler (multigraph), sözde çizgeler (pseudograph), yönlü (directed) ve ağırlıklı (weighted) çizgeler gelir.

Özel çizge tipleri de şöyle hatırlatıldı:

- **Tam çizge (complete graph, $K_n$):** Her düğüm kendisi dışındaki bütün düğümlere bağlıdır.
- **Döngü çizgesi (cycle graph, $C_n$):** Düğümler bir çember oluşturacak biçimde birbirine bağlanır.
- **Tekerlek çizgesi (wheel graph, $W_n$):** Döngü çizgesine fazladan bir düğüm eklenir ve bu düğüm diğer bütün düğümlere bağlanır.
- **Küp çizgesi ($Q_n$):** $n$-küp çizgesinin $2^n$ düğümü vardır. Hoca bu çizgelerin yollar ve devreler konusunda tekrar karşımıza çıkacağını söyledi.
- **İki parçalı çizge (bipartite graph):** Düğümler iki kümeye öyle bölünür ki aynı kümedeki düğümler arasında kenar yoktur.
- **Tam iki parçalı çizge (complete bipartite graph, $K_{m,n}$):** İki kümenin düğümleri arasında olabilecek bütün bağlantılar vardır.

## 2. Yol ve Devre

Hoca yol (path) kavramını ekrandaki bir çizimle gösterdi. Çizimde 9 düğüm vardı. Bir yolda düğüm sayısının bir eksiği kadar kenar bulunur. Bu yüzden 9 düğümlü yolda 8 kenar sayıldı.

Yol kapalı hâle getirilirse, yani başlanan noktadan bütün düğümlerden geçilip yine başlanan noktaya dönülürse, bir devre (cycle) oluşur. Kapalı bir devrede düğüm sayısı kadar kenar vardır.

## 3. Euler Devresi ve Euler Çizgesi

Bir $G$ çizgesinde bir Euler devresi (Euler circuit) varsa o çizgeye Euler çizgesi denir. Euler devresinin amacı **her kenardan yalnız bir kez geçmektir**. Başlanan noktaya geri dönülür, yani başlangıç ve bitiş aynıdır.

> **Ders sonrası not:** Hoca tanımı verirken bir yerde "her düğümden bir kez geçerek bütün düğümleri dolaşıyorsam bu bir Euler devresidir" dedi. Doğrusu her **kenardan** bir kez geçmektir. Düğümlerden bir kez geçmek Hamilton devresinin tanımıdır. Hoca hemen sonraki örneklerde ve Hamilton kısmında doğru tanımı kullandı: "Euler'de kenarlardan bir kez geçiyorum ama düğümlere birden fazla uğrayabiliyorum."

### 3.1 Königsberg Köprü Problemi

Hoca bu konunun çok ünlü bir problemini anlattı: Königsberg köprü problemi. Bir şehirde nehirler vardır ve nehirlerin üzerine 7 köprü kurulmuştur. A, B, C ve D yerleşim bölgeleridir. Soru şudur: Her köprüden yalnız bir kez geçmek şartıyla bütün köprüleri dolaşıp başlanan noktaya dönülebilir mi? Hoca bunun gazetelerin pazar bulmacalarında görülen türden bir problem olduğunu söyledi.

<!-- BELİRSİZ: Hoca Königsberg'i "Almanya'da bir köy" diye tanıttı. -->

> **Ek bilgi (derste anlatılmadı):** Königsberg büyük olasılıkla bugünkü Kaliningrad şehridir ve problem 1736'da Euler tarafından çözülmüştür. Çizge kuramının başlangıcı olarak kabul edilir.

Problemi çözmek için durum çizgeye çevrilir:

- Yerleşim bölgeleri A, B, C, D çizgenin düğümleri olur.
- Köprüler çizgenin kenarları olur.
- A ile D arasında iki köprü vardır. Yani A-D arasında paralel kenar vardır.
- D ile C arasında da iki köprü vardır. D-C arasında da paralel kenar vardır.
- B'nin D, A ve C ile birer köprüsü vardır.

Böylece problem çok daha basit bir hâle gelir. Soru artık şudur: Her kenardan bir kez geçerek bu çizgeyi dolaşabilir miyim ve başladığım noktada bitirebilir miyim? Hoca bunun kağıt kalemle denenebileceğini, ama daha basit bir yolu olduğunu söyledi: düğüm derecelerine bakmak.

## 4. Düğüm Derecesi ve Derece Teoremleri

Yönsüz bir çizgede bir düğümün derecesi (degree), o düğüme bağlı kenarların sayısıdır. Hoca bunu önce ekrandaki A-G düğümlü bir örnek çizge üzerinde saydı ve hata yaparsa uyarılmasını istedi.

<!-- BELİRSİZ: Derece sayımı için kullanılan A-G düğümlü örnek çizge altyazıda yalnız sözlü geçiyor. Söylenen dereceler: A 4, B 3, E 4, G 3, F 4, C 4, D 6. -->

Königsberg çizgesine dönülünce dereceler şöyledir:

| Düğüm | Bağlı köprüler | Derece |
|---|---|---|
| A | A-D (2), A-B (1) | 3 |
| B | B-A, B-C, B-D | 3 |
| C | C-D (2), C-B (1) | 3 |
| D | D-A (2), D-C (2), D-B (1) | 5 |

Toplam derece $3+3+3+5 = 14 = 2 \cdot 7$ olur, yani kenar sayısının iki katıdır.

Bir çizgenin Euler çizgesi olabilmesi için **bütün düğümlerin derecesi çift olmalıdır**. Königsberg'de tek dereceli düğüm vardır. Hoca bir tek düğüm bile bu şartı sağlamıyorsa diğerlerine bakmaya gerek olmadığını vurguladı. Bu yüzden Königsberg köprü problemi bir Euler çizgesi değildir.

> **Hocanın vurgusu:** Bir tane bile tek dereceli düğüm varsa çizge Euler çizgesi değildir. Diğer düğümleri kontrol etmenize gerek yok.

> **Ders sonrası not:** Hoca Königsberg'de A'nın derecesini önce "4" diye söyledi, ardından "3 tane kenar giriyor" diye düzeltti. Köprü dağılımına göre dereceler A 3, B 3, C 3, D 5'tir. Python ile sayıldı.

> **Ek bilgi (derste anlatılmadı):** "Bütün dereceler çift" şartı, çizge **bağlantılı** (connected) ise Euler devresi için hem gerekli hem yeterlidir. Bağlantısız bir çizgede dereceler çift olsa da Euler devresi olmayabilir. Bağlantılı bir çizgede tam iki tek dereceli düğüm varsa, bu iki düğüm arasında bir Euler yolu (Euler path) vardır. Königsberg'de dört düğümün dördü de tek dereceli olduğu için Euler yolu da yoktur.

### 4.1 Yalıtılmış ve Sarkık Düğümler

- **Yalıtılmış düğüm (isolated vertex):** Hiç kenarı olmayan düğümdür, derecesi 0'dır. Hoca örnek olarak noktasal çizgeyi, yani tek başına duran bir düğümü gösterdi.
- **Sarkık düğüm (pendant vertex):** Yalnız bir kenarı olan düğümdür, derecesi 1'dir.

### 4.2 El Sıkışma Teoremi

Bir çizgede $e$ kenar ve $n$ düğüm varsa, düğüm derecelerinin toplamı kenar sayısının iki katıdır:

$$\sum_{v \in V} \deg(v) = 2e$$

Slayttaki örnek: Her birinin derecesi 6 olan 10 düğümlü bir çizgede kaç kenar vardır?

- Derecelerin toplamı: $10 \cdot 6 = 60$.
- $2e = 60$ olduğundan $e = 60/2 = 30$.

Bu çizgede 30 kenar vardır.

### 4.3 Yönlü Çizgelerde Giriş ve Çıkış Derecesi

Yönlü bir çizgede bir kenarın başlangıç düğümü (initial vertex) ve bitiş düğümü (end vertex) vardır. Örneğin $V$'den $W$'ye giden bir kenar vardır ama tersi yoktur. Bu çizgelerde bir düğümün derecesi tek bir sayı olarak ölçülmez, iki derece ölçülür:

- **Giriş derecesi (in-degree), $\deg^-(v)$:** Düğüme giren kenar sayısı.
- **Çıkış derecesi (out-degree), $\deg^+(v)$:** Düğümden çıkan kenar sayısı.

Hoca giriş derecelerini eksi, çıkış derecelerini artı işaretiyle gösterdiğini söyledi. Uydurduğu küçük örnekte $W$ düğümüne iki kenar giriyor, bir kenar çıkıyordu. Yani $\deg^-(W) = 2$, $\deg^+(W) = 1$ idi.

Yönlü çizgeler için de bir teorem vardır. Giriş derecelerinin toplamı ile çıkış derecelerinin toplamı birbirine eşittir:

$$\sum_{v \in V} \deg^-(v) = \sum_{v \in V} \deg^+(v)$$

> **Ek bilgi (derste anlatılmadı):** Her yönlü kenar bir düğümün çıkış derecesine ve bir düğümün giriş derecesine birer katkı yapar. Bu yüzden iki toplam da kenar sayısı $e$'ye eşittir.

## 5. Euler Çizgesi Alıştırmaları

Hoca ekranda birkaç çizge gösterip her biri için iki soru sordu: Bu çizgede her kenardan bir kez geçerek dolaşmak mümkün mü? Mümkünse, bu bir Euler çizgesi mi? Önce derecelere bakılır. Sonra kenarlar oklarla izlenerek dolaşma gösterilir.

<!-- BELİRSİZ: Alıştırma çizgelerinin şekilleri altyazıda yok. Yalnız hocanın okuduğu dereceler ve dolaşmanın sonucu biliniyor. -->

- **Birinci çizge:** Dereceler 2, 4, 3, 3, 4. Tek dereceli düğüm olduğu için Euler çizgesi değildir. Hoca yine de bir düğümden başlayıp her kenardan bir kez geçerek bütün kenarları dolaştı. Fakat başladığı noktada bitiremedi. Başladığı noktada bitirseydi bir kenarı çizememiş olacaktı.
- **İkinci çizge:** Dereceler 2, 3, 2, 3. Yine Euler çizgesi değildir. Her kenardan bir kez geçerek dolaşılabildi, ama başlangıç ve bitiş noktası farklı oldu. Hoca, başlangıç ve bitiş farklıysa düğüm derecelerinin zaten çift olmadığını söyledi.
- **Üçüncü çizge:** Dereceler 2, 4, 4, 2, 4, 4. Hepsi çift olduğu için bu bir Euler çizgesidir. Hoca okları izleyerek her kenardan bir kez geçip başladığı noktaya döndü.
- **Dördüncü çizge:** Dereceler 2, 4, 4, 4, 2, 2. Hepsi çift, yani Euler çizgesidir.

Hoca şunu da ekledi: Derecelerin çift olduğunu göstermek, çizgenin Euler çizgesi olduğunu söylemeye yeter. Başlanan noktaya dönüldüğünü ayrıca çizip göstermek gerekmez. Ama soru "Euler devresini göster" diyorsa, her kenardan bir kez geçerek çizip başlanan noktaya dönmek zorunludur.

> **Ders sonrası not:** Hoca birinci ve ikinci çizge için "Euler devresi var ama Euler çizgesi değil" dedi. Rosen'daki terimlerle, her kenardan bir kez geçen ama başladığı yerde bitmeyen yürüyüş bir **Euler yoludur** (Euler path). Euler devresi tanım gereği kapalıdır. Euler devresi olan çizge zaten Euler çizgesidir. Yani doğru ifade: "Euler yolu var, Euler devresi yok, Euler çizgesi değil." Hoca da bir yerde aynı anlamda "Euler path varsa" diye söyledi. Birinci çizgedeki 2, 4, 3, 3, 4 dizisinde tam iki tek dereceli düğüm vardır. Bu, Euler yolunun neden var olduğunu açıklar.

Dersin bu kısmının özeti şöyledir:

- **Euler devresi:** Her kenardan yalnız bir kez geçilir, başlanan noktaya dönülür.
- **Euler çizgesi:** Euler devresi olan çizgedir. Bağlantılı bir çizgede bütün dereceler çiftse çizge Euler çizgesidir.
- Yönlü çizgede giriş dereceleri toplamı çıkış dereceleri toplamına eşittir.
- Derecelerin toplamı kenar sayısının iki katıdır.

## 6. Hamilton Devresi ve Hamilton Çizgesi

Her çizge Euler ya da Hamilton çizgesi değildir. Hamilton çizgesi, gezgin satıcı problemi (traveling salesman problem) ile karşımıza çıkan bir çizge türüdür. Hoca bunu algoritmalar dersinde mutlaka göreceğimizi söyledi.

Bir çizgede **her düğümden yalnız bir kez geçmek** şartıyla kapalı bir yol oluşturulabiliyorsa, bu yola Hamilton devresi (Hamilton circuit), çizgeye de Hamilton çizgesi denir. Bu sefer şart düğümler içindir. Kenarlar üzerinden geçilir, ama her düğüme bir kez uğranır. Euler'de ise kenarlardan bir kez geçiliyordu, düğümlere birden fazla uğranabiliyordu. Hoca önceki örneklerden birinde bir düğüme dört kez uğradığını hatırlattı.

> **Hocanın vurgusu:** Euler'de kenarlardan bir kez geçilir, Hamilton'da düğümlerden bir kez geçilir. Hamilton çizgesini gösteren derece gibi basit bir ipucu yoktur. Algoritmasını yazmak gerekir.

Hocanın gezgin satıcı benzetmesi şöyleydi: Bir adam kamyonetinin arkasına yatak, yorgan, battaniye, ayakkabı gibi eşyaları koymuş ve satmak için köyleri dolaşacak. Uğradığı bir köye bir daha uğramak istemiyor. Her köy bir düğümdür. Adam öyle bir güzergah çizmelidir ki her köye bir kez uğrasın ve evine dönsün. Bu sağlanabiliyorsa çizge Hamilton çizgesidir.

**Soru:** Prim ya da Kruskal algoritmasında da her düğümden bir kez geçip minimum yolu bulmaya çalışıyorduk. Bu da aynı şey değil mi? **Cevap:** Hayır. Onlarda kapalı bir çevrim oluşmaz. Adı üstünde, minimum yayılan ağaç (minimum spanning tree) bulunur ve ağaçta döngü olmamalıdır. Hamilton'da ise kapalı bir devre oluşur.

### 6.1 $Q_3$ ve Gray Kodu

Hoca daha önceki derslerde $Q_3$ küp çizgesini düğümlerine etiketler koyarak gösterdiğini ve "bu şekil ileride karşınıza çıkacak" dediğini hatırlattı. $Q_3$ bir Hamilton çizgesidir. Hoca okları izleyerek bir düğümden başladı, her düğümden bir kez geçti ve başladığı noktaya döndü. Böylece kapalı bir çevrim oluştu.

Düğüm etiketleri 3 bitlik Gray kodudur (Gray code). Bir düğümden komşusuna geçişte yalnız bir bitin yeri değişir. Hoca bunun, düğümlerden yalnız bir kez geçildiğinin bir göstergesi olduğunu söyledi. Python ile bulunan bir Hamilton devresi etiketlerle şöyledir:

$$000 \to 001 \to 011 \to 010 \to 110 \to 111 \to 101 \to 100 \to 000$$

Her adımda tam bir bit değişir ve sekiz etiketin hepsi bir kez görülür.

> **Ders sonrası not:** Hoca $Q_3$ için "bütün kenarları gezdi" dedi, sonra "özür dilerim" diye düzeltti. Hamilton devresi bütün düğümleri gezer. $Q_3$'ün 12 kenarı vardır, Hamilton devresi bunların 8'ini kullanır.

Hoca ardından $K_4$ ve $W_3$ çizgelerinin Euler mi, Hamilton mı olduğunu sordu ve kontrollerin hep bu şekilde yapılması gerektiğini söyledi. Bu sorunun cevabı derste verilmedi. Cevap "Örnek Sorular" bölümündedir.

## 7. Dijkstra En Kısa Yol Algoritması

Hoca en kısa yolu bulan algoritmalardan birini, Dijkstra algoritmasını (Dijkstra's algorithm) gösterdi. Bunu ağaçlar konusunda değil çizgelerde anlatmasının sebebi, algoritmanın bir çizge yapısında kullanılmasıdır. Algoritmanın adı, onu bulan kişinin soyadıdır. Slaytta algoritmanın sözde kodu (pseudocode) da vardı, ama hoca algoritmayı renkli çizimler üzerinden adım adım anlattı. Tahtadaki gibi olmadığı için söylediklerinin iyi dinlenmesini istedi.

### 7.1 Algoritmanın İşleyişi

- Başlangıç düğümü ya soruda verilir ya da seçilir. Hiçbir bilgi verilmemişse ve düğümler alfabetik sıralanmışsa, "işin raconu" ilk harfle başlamaktır.
- Bütün düğümler bir tabloya sıralanır. Başlangıç düğümüne 0, diğerlerine çok büyük bir sayı ($\infty$, hocanın tablosunda "M") verilir.
- Ziyaret edilmemiş düğümler arasında etiketi en küçük olan seçilir ve "gezildi" olarak işaretlenir. Gezilmiş bir düğüme bir daha gidilmez.
- Seçilen $u$ düğümünden gidilebilen her gezilmemiş $v$ komşusu için yeni uzaklık $d(u) + w(u,v)$ hesaplanır. Tabloya $\min(\text{eski değer},\ d(u)+w(u,v))$ yazılır ve hangi düğümler üzerinden gelindiği not edilir.
- Bütün düğümler gezilene kadar devam edilir.

> **Hocanın vurgusu:** Algoritmada en dikkat edilmesi gereken nokta şudur: Yeni bulduğunuz değer, tabloda önceden bulunan değerden büyükse onu almıyorsunuz. Tabloda hep en küçük değer kalır, çünkü yola hep en küçükten devam etmek zorundasınız.

### 7.2 Birinci Örnek: A'dan F'ye

Çizgenin kenarları ve ağırlıkları şöyledir:

| Kenar | Ağırlık |
|---|---|
| A-B | 2 |
| A-C | 3 |
| B-D | 5 |
| B-E | 2 |
| C-E | 5 |
| E-D | 1 |
| E-F | 4 |
| D-F | 2 |

Hoca ilk denemede adımları karıştırdı, çizimi silip baştan ve hızlı biçimde yaptı. Doğru adımlar şunlardır:

1. **A seçilir** ($d=0$). A'dan B'ye 2 ile gidilir: $B = 2$ (A üzerinden). A'dan C'ye 3 ile gidilir: $C = 3$ (A üzerinden). D, E, F hâlâ M'dir. A artık gezilmiştir.
2. **En küçük B'dir (2). B seçilir.** B'den A'ya gidilmez, çünkü A gezilmiştir. B'den D'ye: $2 + 5 = 7$, yol A-B-D. B'den E'ye: $2 + 2 = 4$, yol A-B-E. C'nin değeri 3 olarak kalır, F hâlâ M'dir.
3. **En küçük C'dir (3). C seçilir.** C'den yalnız E'ye gidilebilir: $3 + 5 = 8$. Ama E'ye zaten 4 ile (A-B-E) gelinebiliyor. $8 > 4$ olduğu için yeni değer alınmaz, E 4 olarak kalır.
4. **En küçük E'dir (4). E seçilir.** E'den B ve C'ye gidilmez, ikisi de gezilmiştir. E'den D'ye: $4 + 1 = 5$, yol A-B-E-D. $5 < 7$ olduğu için D'nin değeri 5 olur. E'den F'ye: $4 + 4 = 8$, yol A-B-E-F.
5. **En küçük D'dir (5). D seçilir.** D'den gezilmemiş tek düğüm F'dir: $5 + 2 = 7$, yol A-B-E-D-F. $7 < 8$ olduğu için F'nin değeri 7 olur.
6. **F seçilir** ($d=7$). Bütün düğümler gezilmiştir.

Sonuç tablosu şöyledir:

| Düğüm | En kısa uzaklık | Yol |
|---|---|---|
| B | 2 | A-B |
| C | 3 | A-C |
| E | 4 | A-B-E |
| D | 5 | A-B-E-D |
| F | 7 | A-B-E-D-F |

A'dan F'ye en kısa yol A-B-E-D-F'dir ve uzunluğu 7'dir. Python ile doğrulandı.

Hoca, bu yolun bütün düğümlerden geçmediğini, çünkü bunun Euler çizgesiyle bir ilgisi olmadığını söyledi. Tablo, A'dan her düğüme en kısa yolu da verir. Örneğin A'dan C'ye tek yol vardır ve minimum uzaklık 3'tür. A'dan B'ye minimum uzaklık 2'dir, B'ye yalnız A üzerinden gelinmiştir.

### 7.3 İkinci Örnek: $u_0$'dan Başlayarak

Hoca ikinci örneği, Prim ve Kruskal'ı anlatırken kullandığı animasyonlu slaytlardan gösterdi. Bu slaytlarda gezilmiş düğümler mavi, sıradaki seçilen düğüm pembe, ulaşılabilen düğümler sarı renkteydi. Bu tür demoların incelenmesini önerdi.

<!-- BELİRSİZ: Bu örneğin kenar ağırlıkları altyazıdaki anlatımdan çıkarıldı. u5-u1 kenarının ağırlığı (10) yalnız u1'in 18 değerinden geriye doğru bulundu. Slaytta başka kenarlar da olabilir. -->

Anlatımdan çıkan kenarlar: $u_0u_5 = 8$, $u_0u_4 = 16$, $u_0u_2 = 13$, $u_5u_4 = 7$, $u_5u_3 = 17$, $u_5u_2 = 11$, $u_5u_1 = 10$, $u_2u_3 = 14$, $u_4u_3 = 5$.

1. **$u_0$ seçilir.** Komşuları açılır: $u_5 = 8$, $u_4 = 16$, $u_2 = 13$.
2. **En küçük $u_5$'tir (8).** $u_4$ için $8 + 7 = 15 < 16$ olduğu için 16 iptal edilir, $u_4 = 15$ olur. $u_3$ için $8 + 17 = 25$ yazılır. $u_2$ için $8 + 11 = 19 > 13$ olduğu için 13 kalır. $u_1$ için $8 + 10 = 18$ yazılır.
3. **En küçük $u_2$'dir (13).** $u_3$ için $13 + 14 = 27 > 25$ olduğu için 25 kalır.
4. **En küçük $u_4$'tür (15).** $u_3$ için $15 + 5 = 20 < 25$ olduğu için 25 yerine 20 yazılır. $u_5$-$u_3$ kenarı (17) yoldan çıkarılır.
5. **İki aday kalır: 18 ve 20. En küçük $u_1$'dir (18).**
6. **Son olarak $u_3$ seçilir (20).**

Sonuç: $u_5 = 8$, $u_2 = 13$, $u_4 = 15$, $u_1 = 18$, $u_3 = 20$. Python ile doğrulandı.

> **Ders sonrası not:** Hoca $u_5$ adımında önce "$u_2$'ye 11 ile gidiyor, 13'ü kaldıracağım" dedi. $u_2$'ye $u_5$ üzerinden $8 + 11 = 19$ ile gelinir. $19 > 13$ olduğu için 13 kalmalıdır. Hoca bir dakika sonra bunu kendisi düzeltti: "8'e 11 eklesem 19 olur, ama 13 varsa 13'ün kalması gerekir."

Hoca, matris üzerinde nasıl yapıldıysa bu tür bütün algoritmaların aynı şekilde çalıştığını söyledi. Slayttaki bir başka örneği öğrencilerin kendilerinin çözmesini istedi.

## 8. Çizge Modelleri

Çizgeler farklı uygulamalarda, farklı bilim dallarında farklı modeller olarak kullanılır. Hoca bu bölümün asıl mesajını şöyle verdi: Bir çizgeye bir ad verildiyse, çizgeye o adın bakış açısıyla bakmak gerekir. Çizgenin kendisi sıradan bir çizgedir. Onu nasıl okuyacağımızı adı belirler.

> **Hocanın vurgusu:** Size "bu bir influence graph" ya da "bu bir precedence graph" dendiyse, çizgeyi o bakış açısıyla okumalısınız.

### 8.1 Niş Örtüşme Çizgesi (Niche Overlap Graph)

Bir ekosistemdeki farklı türleri modellemede kullanılır. Hocanın örneğinde bir grup düğüm et yiyen hayvanlar, bir grup düğüm ot yiyen hayvanlardı. Bir hayvan ise hem etçil hem otçildi ve iki grupla da bağlantılıydı. Çizgeye "niş örtüşme çizgesi" dendiğinde bunun bir ekosistemdeki canlıları gruplamak için kullanıldığını bilir ve öyle okuruz.

### 8.2 Etki Çizgesi (Influence Graph)

Grup çalışmalarında kullanılır. Hoca A, B, C, D, E düğümlü bir örnek çizdi ve bunu bir yazılım projesi grubu olarak düşünmemizi istedi:

- A, C'den, D'den ve B'den gelecek işleri bekler. A'nın görevi, bu alt çıktıları alıp bir iş yapmaktır.
- C, D'den gelecek bir işi işleyip A'ya gönderir.
- B hem A'ya hem E'ye bilgi gönderir.

Bir proje müdürü böyle bir çizgeye bakarak kimin kime ne kadar ihtiyacı olduğunu görebilir. Personel gruplarını kurabilir, iş tanımı yapabilir ve kimin çıktısının kime girdi olacağını çizge üzerinde gösterebilir.

### 8.3 Dairesel Turnuva Çizgesi (Round-Robin Tournament Graph)

Bir turnuvada her takımın hangi takımla karşılaştığını ve sonucu gösterir. Hocanın A, B, C, D örneğinde çizge şöyle okundu:

- B ile D karşılaşmış, B kazanmış.
- D ile C karşılaşmış, C kazanmış.
- C ile B karşılaşmış, C kazanmış.
- B ile A karşılaşmış, berabere kalmışlar.

<!-- BELİRSİZ: Turnuva çizgesinin tam çizimi ve beraberliğin nasıl gösterildiği (yönsüz kenar mı?) altyazıdan çıkmıyor. -->

## 9. Öncelik (Precedence) Çizgesi

Hoca bilgisayar mühendisliğini en çok ilgilendiren modelin öncelik çizgesi (precedence graph) olduğunu söyledi. "Pre" ön eki "önde gelen" demektir. Bir düğümün işini yapabilmesi, kendinden önceki düğümlere bağlıdır. Bir işlemin sonucunun, kendisinden önce gelen işlemlerin sonucuna bağlı olduğu sistemleri modellemede kullanılır. Hoca bunun etki çizgesine benzediğinin düşünülebileceğini, ama farklı olduğunu örnekle göstereceğini söyledi.

Slayttaki örnekte altı deyim (statement) vardı:

- $S_1: a := 0$
- $S_2: b := 1$
- $S_3: c := a + 1$
- $S_4: d := b + a$
- $S_5: e := d + 1$
- $S_6: e := c + d$

Hoca bu deyimlerdeki toplamaları aritmetik toplama gibi düşünmememizi, "A'dan gelen işe bir yük daha ekleniyor" gibi okumamızı istedi.

Kural şudur: Bir deyimin sağ tarafında bir değişken kullanılıyorsa, o değişkeni **sol tarafta** tanımlayan deyim bu deyimden önce gelmelidir. Bu iki deyim arasına bir kenar çizilir.

- $S_1$ ve $S_2$ başlangıç deyimleridir. İkisi de bir ilk değer alarak başlar.
- $S_3$'te $a$ kullanılır. Sol tarafında $a$ olan yalnız $S_1$'dir. $S_1 \to S_3$ çizilir.
- $S_4$'te $b$ ve $a$ kullanılır. Sol tarafında $b$ olan $S_2$, sol tarafında $a$ olan $S_1$'dir. $S_2 \to S_4$ ve $S_1 \to S_4$ çizilir.

**Soru:** $S_3$'te de $a$ var, $S_4$'ü $S_3$'e de bağlamamız gerekmez mi? **Cevap:** Hayır. Bakılan yer eşitliğin sol tarafıdır. $S_3$, $a$'yı alıp yoluna devam eden bir deyimdir, $a$'yı tanımlamaz.

- $S_5$'te $d$ kullanılır. Sol tarafında $d$ olan $S_4$'tür. $S_4 \to S_5$ çizilir.
- $S_6$'da $c$ ve $d$ kullanılır. $S_3 \to S_6$ ve $S_4 \to S_6$ çizilir.

Hoca $S_5$ ve $S_6$'da bir adım daha ileri gitti. $d$'nin içinde $b$ ve $a$ olduğu için $S_5$'e $S_2$ ve $S_1$'i de bağladı. Benzer biçimde $S_6$'ya $c$'nin içindeki $a$ için $S_1$'i de bağladı.

> **Ders sonrası not:** Öncelik çizgesinde yalnız doğrudan bağımlılık kenarları çizilir. $S_5$ yalnız $d$'yi kullanır, $d$'yi tanımlayan $S_4$'tür. $S_1$ ve $S_2$'ye olan bağımlılık zaten $S_1 \to S_4 \to S_5$ ve $S_2 \to S_4 \to S_5$ yolları üzerinden gelir. Rosen'daki aynı örnekte de çizge büyük olasılıkla yalnız doğrudan kenarlardan oluşur: $S_1 \to S_3$, $S_1 \to S_4$, $S_2 \to S_4$, $S_3 \to S_6$, $S_4 \to S_5$, $S_4 \to S_6$. Hocanın eklediği dolaylı kenarlar yanlış sayılmaz ama gereksizdir ve çizgeyi kalabalıklaştırır.

> **Ders sonrası not:** Hoca ikinci çizimde "$S_2$ de $b = 0$ ile başladı" dedi. Slayttaki deyim $b := 1$'dir. Hoca örneği ilk anlatırken başlangıç değerlerini doğru olarak "0 ve 1" diye vermişti.

Hoca bir de varsayımsal bir $S_7$ deyimi ekledi:

- $S_7: e := 5$ olsaydı, $S_7$'ye hiçbir kenar gelmezdi. $e$ burada yeni bir ilk değerle başlar. Önceki $e$'leri buna bağlamak diye bir şey yoktur.
- $S_7: e := 5 + e$ olsaydı, sol tarafında $e$ olan $S_5$ ve $S_6$, $S_7$'ye bağlanırdı.

Hoca çizimin çok karıştığını, deyimlerin yeri kenarlar az kesişecek biçimde seçilirse çizgenin çok daha şık görüneceğini söyledi.

## 10. Düzlemsel Çizgeler ve Euler Formülü

Kenarları birbirini kesmeyecek biçimde düzleme çizilebilen çizgeye düzlemsel çizge (planar graph) denir. Hoca ekranda iki kenarı kesişiyor gibi görünen bir çizge gösterdi. İki boyutlu bakınca kenarlar üst üste görünür. Ama üç boyutlu bakınca bu bir piramittir ve kenarlar hiçbir zaman kesişmez. Gözümüz bizi yanıltabilir.

> **Hocanın vurgusu:** İki kenarın kesişmesi sizi yanıltmasın. Kesişme noktasında bir düğüm çizilmemişse, kenarlar birbirinin üzerinden geçiyor demektir.

Bir çizgenin düzlemsel olup olmadığını formülle kontrol edebiliriz. $v$ düğüm sayısı, $e$ kenar sayısı, $f$ yüzey (face) sayısı olmak üzere:

$$v - e + f = 2$$

Piramit örneğinde ($K_4$):

- Düğüm sayısı $v = 4$.
- Kenar sayısı $e = 6$.
- $4 - 6 + f = 2 \Rightarrow f = 4$.

Gerçekten de piramidin bir taban yüzeyi ve üç üçgen yan yüzeyi vardır, toplam 4 yüzey. Hoca, yüzey sayısı verilen bir çizgenin düzlemsel olarak çizilip çizilemeyeceğinin de düğüm ve kenar sayıları formüle konarak görülebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** $v - e + f = 2$ formülü bağlantılı düzlemsel çizgeler için geçerlidir ve dış sonsuz bölge de bir yüzey sayılır. Formül bir çizgenin düzlemsel çizimindeki yüzey sayısını verir. Bir çizgenin düzlemsel olmadığını göstermek için ise genelde bu formülden çıkan $e \le 3v - 6$ gibi eşitsizlikler kullanılır.

## 11. Çizgelerde Eşyapı (İzomorfizm)

Hoca önce ağaçlardaki eşyapıyı (isomorphism) hatırlattı. İki ağacın eşyapılı olması için düğüm sayıları aynı, kenar sayıları aynı ve düğüm dereceleri karşılıklı aynı olmalıydı. İkili ağaç (binary tree) deniyorsa, çocukların sağa sola yerleşim yönleri de aynı olmalıydı.

Çizgelerde de durum aynıdır, sadece ek bir kontrol gerekir:

- Kenar sayıları aynı olmalıdır.
- Düğüm sayıları aynı olmalıdır.
- Düğüm dereceleri karşılıklı aynı olmalıdır.
- Düğümler arasındaki ilişkiyi gösteren komşuluk matrisleri (adjacency matrix) aynı olmalıdır.

Hoca ilk örnekte birbirine çok benzeyen iki çizgeyi kontrol etti. İkisinde de 5 düğüm ve 7 kenar vardı. Dereceler bir çizgede 4, 2, 3, 3, 2, diğerinde 4, 2, 2, 3, 3 idi. Bunlar tutuyordu, "ama iş bitmiyor" dedi. Komşuluk matrisleri de yazılmalıdır. A'dan B'ye kenar varsa 1, yoksa 0 yazılır. İki matris aynıysa çizgeler eşyapılı olabilir. Matrisler aynı değilse, satırların ve sütunların yeri değiştirilerek eşlenip eşlenemeyeceğine bakılır. Örneğin ikinci satırla dördüncü satırın ve ikinci sütunla dördüncü sütunun yeri değiştirilince matrisler aynı oluyorsa çizgeler eşyapılıdır.

### 11.1 Kare ve Kelebek

İlk bakışta biri kare, biri kelebek gibi görünen iki çizge verildi. Şekilleri benzemediği için eşit olmadıkları düşünülebilir. Kontroller şöyledir:

- İkisinde de 4 düğüm vardır.
- İkisinde de 4 kenar vardır.
- Kelebekte kenarların kesiştiği yerde düğüm yoktur. Kenarlar birbirini kesmez, üst üste geçer. Hoca şekli üç boyutlu çevirmeye çalışmamızı önerdi.
- Dereceler ikisinde de 2, 2, 2, 2'dir.

Ardından komşuluk matrisleri yazıldı. Birinci çizgede $u_1$, $u_2$ ve $u_3$'e; $u_2$, $u_1$ ve $u_4$'e; $u_3$, $u_1$ ve $u_4$'e; $u_4$ de $u_2$ ve $u_3$'e bağlıdır. İki matris ilk hâliyle aynı değildi. Bu noktada "eşyapılı değildir" denebilirdi. Ama kural, satır ve sütun değişimiyle eşlenip eşlenemeyeceğine bakmayı gerektirir.

Hoca öğrencilerin arkalarına yaslanıp hangi satırların yerini değiştirince matrislerin benzeyeceğini düşünmelerini istedi. İpucu, 1'lerin ve 0'ların dörtlü bloklar oluşturmasıydı. $u_2$ ile $u_4$'ün satırları ve sütunları yer değiştirildi. Sonuçta bir matriste dört 1 üst solda ve alt sağda, dört 0 diğer köşelerde toplandı, aynen diğer matristeki gibi. Bu yüzden iki çizge eşyapılıdır.

<!-- BELİRSİZ: İki matrisin tam hâli ve ikinci çizgenin (kelebek) düğüm etiketleri altyazıdan tam çıkmıyor. -->

> **Hocanın vurgusu:** Hangi satırın hangi satırla, hangi sütunun hangi sütunla yer değiştireceğini iyi görmelisiniz. Böylece çizgelerin eşyapılı olduğunu gösterebilirsiniz.

### 11.2 Beşgen ve Yıldız

Bir beşgen ile beş köşeli bir yıldız verildi. Hoca "bakıyorsun, hiç alakası bile yok" dedi. Ama kontroller tutar: ikisinde de 5 düğüm, 5 kenar vardır ve bütün dereceler 2'dir. Komşuluk matrisleri de aynıdır. İkisi de $C_5$'tir. Yıldızın uçlarından biri çekilip açılırsa beşgen elde edilir. Hoca burada "insanları da dış görünüşüne bakarak değerlendirmemek gerekir" benzetmesini yaptı.

### 11.3 Derecesi 1 Olan Düğüm

Bir çizgede derecesi 1 olan bir düğüm varken diğerinde hiç derecesi 1 olan düğüm yoksa, çizgeler eşyapılı değildir. Derece şartı bile sağlanmadığı için matrise bakmaya gerek yoktur.

### 11.4 Küpün Yukarıdan Görünüşü

Son örnekte iki çizge birbirine benziyordu. Hoca bunu eski teknik resim dersine benzetti: Bir cisim önden, soldan ve üstten nasıl görünüyorsa öyle çizilirdi. Sağdaki küpe yukarıdan bakılırsa soldaki çizge görülür. İki çizgede de 10 düğüm vardı, düğüm ve kenar sayıları aynıydı. Matrisler yazılırsa, gerekirse satır-sütun değişimiyle, aynı oldukları görülür. Bu iki çizge eşyapılıdır.

<!-- BELİRSİZ: Bu örnekteki çizgelerin tam yapısı altyazıdan çıkmıyor. Hoca "2, 4, 2, 4, 5, 5, 10 tane düğüm var" diye saydı. Kenar sayısı söylenmedi. -->

## 12. Ağ Topolojileri ve Çizge Türleri

Hoca ağ teknolojileri dersinde karşımıza çıkacak bazı ağ topolojilerinin aslında bildiğimiz çizgeler olduğunu gösterdi. Bir binadaki bilgisayarları bağlamak için yerel alan ağı (local area network) kuracak kişi yıldız, halka ya da hibrit topoloji arasında seçim yapar. Bunlar ağcıların terimleridir.

- **Yıldız topolojisi (star topology) = $K_{1,n}$:** Düğümler iki kümeye bölünür. Bir kümede bir düğüm, diğerinde $n$ düğüm vardır. Tek düğüm diğer kümedeki bütün düğümlere bağlıdır. Hocanın örneğinde $K_{1,8}$ vardı. Ortaya sunucu (server) konur, uç kullanıcılar ona bağlanır. Hoca bunu üniversitedeki odaların sunucuya bağlanmasına benzetti.
- **Halka topolojisi (ring topology) = $C_n$:** En ilkel olanıdır. Bir hat koptuğunda yalnız o odadaki kişi etkilenebilir. Komşu olmayan iki düğüm birbirine ancak aradaki düğümler üzerinden veri gönderir. Bir hat koptuğunda düğüm sunucuya diğer düğümlerin üzerinden dolaşarak ulaşır.
- **Hibrit topoloji (hybrid topology) = $W_n$:** Döngü çizgesinin ortasına bir düğüm konup diğer bütün düğümlere bağlanır. En sağlam yapıdır. Bir hat gitse bile düğüm sunucuya bir şekilde ulaşır. Ama en maliyetli olan da budur.

Hoca bu kısmı, gördüğümüz her şeyin başka bir bilim dalının içinde mutlaka karşımıza çıktığını hatırlatarak bitirdi.

## 13. Çizge Boyama ve Kromatik Sayı

Aradan sonra hoca tamamen farklı bir konuya geçti: çizge boyama (graph coloring) ve kromatik polinomlar. Çizge boyama algoritmalarının veri yapıları ya da algoritmalar dersinde görüleceğini, bu derste ise kromatik polinomlardan bahsedileceğini söyledi.

Bir $G$ çizgesinin her düğümüne, herhangi iki komşu düğüme aynı renk atanmayacak biçimde bir renk atanmasına çizgenin renklendirilmesi (boyanması) denir.

Hocanın günlük hayattan örnekleri şunlardır:

- **Harita:** Bir atlasta Türkiye'nin siyasi haritasında iller farklı renklerle boyanır ve komşu iller aynı renkte olmaz. Yedi coğrafi bölge için de aynısı geçerlidir. Burada düğümler şehirlerdir.
- **Araştırma grupları:** Bir fakültede 20 araştırmacı ve farklı araştırma grupları olsun. Bir kişi birden fazla grupta yer alabilir. Gruplar haftada bir toplanacaktır. Toplantılar öyle düzenlenmelidir ki aynı kişinin bulunduğu grupların toplantıları aynı saate denk gelmesin.
- **Ders programı:** Dersleri çakıştırmadan bir ders programı hazırlamak da aynı problemdir. Düğüm sayısı arttıkça çakışmalar da artar. Ders programlarında çakışma olmasının sebebi budur.

Önemli olan, çizgenin **en az** kaç renkle boyanabileceğidir. Yedi bölgeyi 7 farklı renkle, 81 ili 81 farklı renkle boyarsak iş biter. Ama bilgisayarcı için önemli olan maliyettir, yani minimum renk sayısıdır. Bir çizgeyi boyamak için gereken en az renk sayısına kromatik sayı (chromatic number) denir ve $\chi(G)$ ile gösterilir.

### 13.1 Kromatik Sayı Örnekleri

Hoca ekranda üç çizge gösterip her birinin kromatik sayısını sordu.

<!-- BELİRSİZ: Bu üç çizgenin tam şekli altyazıda yok. Açıklamalar hocanın boyama anlatımından kuruldu. -->

- **4 düğümlü çizge:** Üç düğüm kırmızı, mavi, sarı boyandı. Dördüncü düğüm üçüyle de komşu olduğu için bu üç renkten hiçbiri konamadı, yeşil kullanıldı. Bu çizge 4 renkle boyanır.
- **5 düğümlü çizge:** Bir çizgenin ortasına bir düğüm daha eklenerek elde edildi. Komşu olmayan düğümlere aynı renk verilerek kırmızı, mavi, yeşil ile boyandı. 5 düğüm vardır ama 3 renk yeter.
- **7 düğümlü çizge:** Ortadaki düğüm kırmızı yapıldı. Çevredeki düğümler sarı ve yeşil sırayla boyandı. 3 renk yeter.

Buradan çıkan sonuç şudur: Renk sayısının düğüm sayısıyla doğrudan bir ilgisi yoktur. Önemli olan düğümlerin birbiriyle ilişkisidir.

> **Ders sonrası not:** Hoca 7 düğümlü çizgeye "$K_{1,n}$" dedi. $K_{1,n}$ iki parçalı bir çizgedir ve 2 renkle boyanır: merkez bir renk, uçların hepsi başka bir renk. Hocanın boyamasında çevredeki düğümler sarı ve yeşil diye sırayla boyandığına göre bu düğümler birbirine de bağlıdır. Çizge büyük olasılıkla $W_6$ tekerlek çizgesidir. $W_6$'nın kromatik sayısı 3'tür. Python ile 1 ve 2 renkle boyama sayısının 0, 3 renkle 6 olduğu sayıldı.

Düğüm sayısı azken düğümler elle kırmızı, mavi, yeşil diye etiketlenebilir. Düğüm sayısı çok fazla olunca buna otomatik, algoritmik olarak karar vermek gerekir. Hoca bu derste algoritmayla ilgilenmeyeceklerini, yalnız minimum renk sayısını bulacaklarını söyledi. Bunun için çizgenin kromatik polinomu çıkarılır.

### 13.2 Kurullar Örneği

Bir üniversitede profesörlerden oluşan 10 farklı kurul vardır. Bir profesör birden fazla kurulda olabilir. Kurullar haftada bir toplanır. Dekandan, toplantıları en az sayıda ve en kısa sürede bitecek biçimde düzenlemesi istenir.

Bir bilgisayarcı bunu çizgeyle modeller:

- Düğümler kurullardır.
- Kenarlar akademisyenlerdir. Bir akademisyen birden fazla kurulda olabildiği için kurulları birbirine bağlar.
- Renkler toplantı zamanlarıdır.

Hocanın ekrandaki örneğinde düğümler en az 4 renkle (mavi, kırmızı, turuncu, yeşil) boyanabiliyordu. Yani hocalar çakışmadan 4 toplantıyla iş bitirilebilir. Hoca, düğüm sayısı azken bu 4 sayısının kafadan bulunabileceğini, ama çokken bulunamayacağını, bunun için polinom kurulacağını vurguladı.

<!-- BELİRSİZ: Kurullar çizgesinin yapısı altyazıda yok. -->

## 14. Kromatik Polinom ve Silme-Büzme Yöntemi

Bir $G$ çizgesinin kromatik polinomu $P_G$ ile gösterilir. $P_G(k)$, elimizde $k$ renk varken çizgenin kaç farklı biçimde uygun boyanabileceğini verir.

Polinom şöyle kullanılır. $k$ yerine sırayla 1, 2, 3, ... konur:

- $P_G(1) = 0$ çıkarsa çizge 1 renkle boyanamaz.
- $P_G(2) = 0$ çıkarsa 2 renkle de boyanamaz.
- $P_G(3) \neq 0$ çıkarsa çizge en az 3 renkle boyanır. Çıkan sayı da 3 renkle kaç değişik biçimde boyanabileceğini gösterir.

"Kaç değişik biçimde" şu demektir: Bir düğüme kırmızı, diğerine mavi, üçüncüsüne sarı denebilirdi. Ya da sarı, mavi, kırmızı denebilirdi. Bunun gibi farklı kombinasyonlar sayılır.

> **Ders sonrası not:** Hoca $P_G$'yi "G çizgesini minimum $k$ renkle renklendirmenin kaç farklı şekilde yapılacağını verir" diye tanımladı. Doğrusu: $P_G(k)$, $k$ renk varken kaç farklı uygun boyama yapılabileceğini verir ve bunu her $k$ için verir. Kromatik sayı, $P_G(k) > 0$ olan en küçük $k$'dır. Örneğin $K_4$'te $P(4) = 24$ ama $P(5) = 120$'dir. 5 renkle de boyama yapılabilir, yalnız minimum değildir.

### 14.1 Silme-Büzme Yöntemi

Polinomu çıkarmak için kullanılan yöntem silme-büzme (deletion-contraction) yöntemidir:

1. Çizgeden uygun bir kenar seçilir ve silinir.
2. Silinen kenarın iki ucundaki düğümler birleştirilir (büzülür). Hoca bunu bir kâğıdı katlamaya benzetti: Bir düğüm diğerinin üzerine gelecek biçimde çizge katlanır. Kenarlar kırılmaz, bükülmez. Üst üste gelen kenarlar tek kenar olur.
3. İki çizgenin polinomlarının farkı alınır.

$$P(G) = P(G - e) - P(G / e)$$

Burada $G - e$ kenarı silinmiş çizge, $G / e$ kenarı büzülmüş çizgedir. Hangi kenarın silineceğine biz karar veririz. En kolay çözüme götüren kenar seçilmelidir. Ortaya çıkan çizgeler tanınıyorsa polinomları yazılır. Tanınmıyorsa onlara da aynı işlem uygulanır.

> **Hocanın vurgusu:** Çizgeyi tanıdık bir çizge görene kadar parçalayın. Tanıdık çizgelerin polinomlarını, $2 \times 2 = 4$'ü bilir gibi bilmeniz lazım. Ne kadar erken tanırsanız işiniz o kadar çabuk biter.

## 15. Bilinen Çizgelerin Kromatik Polinomları

### 15.1 Noktasal Çizge

En basit çizge tek düğümden oluşur, hiç kenarı yoktur. Elimizde $x$ renk varsa bu düğüm $x$ renkten herhangi biriyle boyanabilir, çünkü hiç komşusu yoktur:

$$P = x$$

### 15.2 Çizgisel Çizge

İki düğüm ve aralarında bir kenar vardır. Birinci düğüm $x$ renkle boyanabilir. Hoca $x = 10$ örneğini verdi: Bir renk birinci düğüme kullanıldıysa, komşu düğüme 9 renk kalır. Yani:

$$P = x(x-1)$$

Bu fikir daha uzun bir çizgisel çizgeye genelleştirilir. Hocanın örneğinde birden fazla kenar art arda bağlanmıştı ve 6 kenar vardı. Birinci düğüm $x$ renkle boyanır. İkinci düğümün bir komşusu boyanmıştır, ona $x - 1$ renk kalır. Üçüncü düğümün de şu an yalnız bir komşusu boyalıdır, ona da $x - 1$ renk kalır.

> **Hocanın vurgusu:** Sakın boş bulunarak üçüncü düğüme $x-2$ demeyin. O düğümün şu an yalnız bir komşusu boyalı, ona da $x-1$ renk kalır.

Hoca bunu kırmızı, sarı, kırmızı, sarı diye sırayla boyayarak gösterdi. $x - 1$ "bir öncekinin bir eksiği" değildir. 10 renk varsa her düğüme 9 renk kalır. $n$ düğümlü çizgede birinci düğümden sonra $n - 1$ düğüm vardır ve her birine $x - 1$ renk kalır:

$$P = x(x-1)^{n-1}$$

<!-- BELİRSİZ: Hoca bu genelleşmiş çizgeye altyazıda "U grafı" dedi. Kastedilen terim çıkarılamadı. Hocanın gösterdiği şekiller düz bir yol olmayabilir; formül her n düğümlü ağaç için geçerlidir. -->

### 15.3 Tam Çizge $K_n$

Her düğüm kendisi dışındaki bütün düğümlere bağlıdır. $K_3$ (üçgen) için birinci düğüm $x$ renkle, ikinci düğüm $x-1$ renkle boyanır. Üçüncü düğümün iki komşusu vardır ve onlarla aynı renk olamaz, ona $x - 2$ renk kalır:

$$P(K_3) = x(x-1)(x-2)$$

Genel formül şudur:

$$P(K_n) = \prod_{k=0}^{n-1} (x - k) = x(x-1)(x-2)\cdots(x-n+1)$$

$K_3$ için $k = 0$'da $x$, $k = 1$'de $x - 1$, $k = 2$'de $x - 2$ gelir.

<!-- BELİRSİZ: Hoca K3 için altyazıda "Z grafı" adını da kullandı. Kastedilen ad çıkarılamadı; notta K3 (üçgen) yazıldı. -->

Bilinmesi gereken üç polinomun özeti:

| Çizge | Kromatik polinom |
|---|---|
| Noktasal çizge (tek düğüm) | $x$ |
| $n$ düğümlü çizgisel çizge | $x(x-1)^{n-1}$ |
| $K_n$ | $\prod_{k=0}^{n-1}(x-k)$ |

## 16. $K_4$ Örneği

### 16.1 Doğrudan Yazmak

Hoca ekranda bir çizge gösterdi ve bunun bir $K$ çizgesi olduğunu söyledi. "Sokaktaki insan" gibi düşünülürse: Birinci düğüm $x$, ikincisi $x - 1$, üçüncüsü iki komşusu olduğu için $x - 2$, dördüncüsü üç komşusu olduğu için $x - 3$ renkle boyanır.

Hoca burada slaytta iki hata yaptığını söyledi. Slayttaki çizimde düğümler kırmızı, mavi, kırmızı, mavi diye 2 renkle boyanabiliyordu, yani çizim $K_4$ değildi. Doğru çizimde her düğüm diğer üç düğüme bağlıdır. O zaman 2 renk yetmez.

$K_4$'ün polinomu formülden doğrudan yazılır. Ama soru polinomu istiyorsa çarpanlı hâli değil, açılmış hâli verilmelidir:

$$P(K_4) = x(x-1)(x-2)(x-3) = x^4 - 6x^3 + 11x^2 - 6x$$

Kaç renkle boyanacağı şöyle bulunur:

- $x = 1$: Çarpanlarda $x - 1$ var, sonuç 0.
- $x = 2$: Çarpanlarda $x - 2$ var, sonuç 0.
- $x = 3$: Çarpanlarda $x - 3$ var, sonuç 0.
- $x = 4$: $4 \cdot 3 \cdot 2 \cdot 1 = 24$.

Yani $K_4$ en az 4 renkle ve 4 renkle 24 farklı biçimde boyanır. Python ile bütün boyamalar sayılarak doğrulandı.

> **Ders sonrası not:** Hoca slayttaki polinomun ilk yazılan hâlinin de hatalı olduğunu söyledi. Altyazıda okunan ara çarpımlar bozuk. Doğru polinom $x^4 - 6x^3 + 11x^2 - 6x$'tir. Hoca dersin ilerleyen kısmında silme-büzmeyle de bu sonucu buldu.

### 16.2 Çarpma Kısayolu

Hoca uzun çarpımlar için bir kısayol gösterdi. Örneğin $(x-1)(x^2 - 5x + 6)$ çarpımı yapılacak olsun:

1. İşaretlere bakılmadan katsayılar alınır: $1, 5, 6$ ve $1, 1$.
2. Bu katsayılar çarpılıp kaydırılarak toplanır: $1$, $1 + 5 = 6$, $5 + 6 = 11$, $6$. Sonuç: $1, 6, 11, 6$.
3. İşaretler soldan sağa $+, -, +, -$ diye yerleştirilir.
4. En sondaki katsayının değişkeni $x$ olur, sola doğru kuvvetler artar: $x$, $x^2$, $x^3$, $x^4$.

Böylece $x^4 - 6x^3 + 11x^2 - 6x$ elde edilir. Burada $(x-2)(x-3) = x^2 - 5x + 6$'dır ve en başta bir $x$ çarpanı vardır (ara adım eklendi).

### 16.3 Silme-Büzmeyle Çözmek

Hoca, sınav heyecanıyla çizgenin $K_4$ olduğunu göremediğimizi varsaydı. O zaman çizge tanıdık çizgelere indirgenir. Düğümler 1, 2, 3, 4 diye numaralanmıştı.

**Adım 1.** 1 ile 4 arasındaki kenar silinir. Bu iki düğüm mavi yapıldı. Kalan çizge, iki üçgenin ortak bir kenarla birleştiği "elmas" çizgesidir ($K_4 - e$). Sonra 4 düğümü 1'in üzerine katlanır. 3-4 kenarı 1-3'ün, 2-4 kenarı 1-2'nin üzerine oturur. Ortaya $K_3$ çıkar:

$$P(K_4) = P(\text{elmas}) - P(K_3)$$

$K_3$ tanınır. Elmas tanınmazsa ayrıca çözülür.

**Adım 2.** Elmasta köşegen kenar silinir. Bu kenarın düğümleri mor yapıldı. Kalan çizge 4 düğümlü bir döngüdür ($C_4$). Mor düğümler üst üste katlanınca üst üste gelen kenarlar birleşir ve 3 düğümlü çizgisel çizge çıkar:

$$P(\text{elmas}) = P(C_4) - x(x-1)^2$$

**Adım 3.** $C_4$'ten bir kenar silinir. Bu kenarın düğümleri turuncu yapıldı. Kalan çizge 4 düğümlü çizgisel çizgedir. Turuncu düğümler birleştirilince $K_3$ çıkar:

$$P(C_4) = x(x-1)^3 - x(x-1)(x-2)$$

Hoca burada durdu. Noktasal çizgeye kadar inilebileceğini, ama bunun hata yapma olasılığını artıracağını söyledi.

Şimdi aşağıdan yukarı doğru hesap yapılır:

$C_4$ için ortak çarpan $x(x-1)$ alınır:

$$P(C_4) = x(x-1)\left[(x-1)^2 - (x-2)\right] = x(x-1)(x^2 - 3x + 3) = x^4 - 4x^3 + 6x^2 - 3x$$

Elmas için:

$$P(\text{elmas}) = x(x-1)(x^2 - 3x + 3) - x(x-1)^2 = x(x-1)\left[x^2 - 3x + 3 - x + 1\right] = x(x-1)(x^2 - 4x + 4)$$

$$P(\text{elmas}) = x(x-1)(x-2)^2 = x^4 - 5x^3 + 8x^2 - 4x$$

$K_4$ için:

$$P(K_4) = x(x-1)(x-2)^2 - x(x-1)(x-2) = x(x-1)(x-2)(x-3) = x^4 - 6x^3 + 11x^2 - 6x$$

Hoca bu sonucu slayttaki ilk polinomla karşılaştırınca oradaki hatayı da gördü. Doğrusu $x^4 - 6x^3 + 11x^2 - 6x$'tir. Formülü biliyorsak hemen yazarız. Bilmiyorsak böyle bölerek çözeriz. Sonra $x$ yerine 1, 2, 3 konunca 0, 4 konunca sıfırdan farklı bir değer çıkar.

Elmas polinomunun açılmasında hoca çarpma kısayolunu yine kullandı: $(x-1)(x^2 - 4x + 4)$ için katsayılar $1, 4, 4$ ve $1, 1$ çarpılınca $1, 5, 8, 4$ çıkar. İşaretlerle $x^4 - 5x^3 + 8x^2 - 4x$ olur.

C4, elmas ve $K_4$ polinomlarının üçü de Python ile bütün boyamalar sayılarak doğrulandı.

## 17. Ortak Düğüm veya Kenarla Birleşen Çizgeler

Hoca işi kolaylaştıran bir kural daha verdi. Verilen çizge bir noktadan ya da bir kenardan iki parçaya ayrılabiliyorsa, iki parçanın polinomları çarpılır ve ortak kısmın polinomuna bölünür.

Hocanın örnekleri şunlardır:

- Bir noktada birleşmiş iki çizge.
- Ortak bir kenarı olan iki üçgen (elmas).
- Bir noktada birleşmiş bir kare ve bir üçgen.

$G_1$ ile $G_2$ ortak bir $K_r$ ile birleşiyorsa:

$$P(G) = \frac{P(G_1)\,P(G_2)}{P(K_r)}$$

Ortak kısım bir noktaysa paydaya noktasal çizgenin polinomu $x$ gelir. Ortak kısım bir kenarsa paydaya çizgisel çizgenin polinomu $x(x-1)$ gelir.

Elmas iki üçgenden oluşur ve üçgenler bir kenarı ortak kullanır:

$$P(\text{elmas}) = \frac{\left[x(x-1)(x-2)\right]^2}{x(x-1)} = x(x-1)(x-2)^2$$

Bu, silme-büzmeyle bulunan sonucun aynısıdır. $x = 1$ ve $x = 2$ için 0 çıkar. $x = 3$ için $3 \cdot 2 \cdot 1 \cdot 1 = 6$ çıkar. Yani elmas en az 3 renkle ve 3 renkle 6 farklı biçimde boyanır. Python ile doğrulandı.

## 18. Kromatik Polinomun Doğruluk Kontrolleri

Hoca bulunan bir polinomun doğru olup olmadığını kontrol etmenin yollarını verdi:

- Polinomun derecesi çizgenin düğüm sayısına eşittir.
- İkinci terimin katsayısının mutlak değeri kenar sayısına eşittir.
- Baş katsayı her zaman 1'dir.
- Katsayıların işaretleri soldan sağa $+, -, +, -, \dots$ diye değişir.
- Polinomda sabit terim yoktur. Son terim $x$ ile çarpılır.
- Katsayıların toplamı 0'dır.

Diğer katsayıların neye karşılık geldiği bilinmez. Bu şartlardan biri sağlanmıyorsa bulunan polinom yanlıştır.

Elmas için kontrol: $x^4 - 5x^3 + 8x^2 - 4x$. Derece 4 ve çizgede 4 düğüm vardır. İkinci katsayı 5 ve çizgede 5 kenar vardır. Katsayıların toplamı $1 - 5 + 8 - 4 = 0$'dır.

> **Hocanın vurgusu:** Polinomu bulduktan sonra mutlaka kontrol edin. Derece, ikinci katsayı, baş katsayı, işaretler, sabit terim ve katsayılar toplamı.

> **Ders sonrası not:** "Son terim $x$ ile biter" kuralı bağlantılı çizgeler için doğrudur. $c$ bileşenli bir çizgede en küçük kuvvet $x^c$ olur. "Katsayılar toplamı 0" kuralı da çizgede en az bir kenar varsa geçerlidir. Çünkü katsayılar toplamı $P(1)$'dir ve bir kenar varsa 1 renkle boyama yapılamaz.

## 19. Eski Vize Sorusu: $K_4$'ün Farklı Bir Çizimi

Hoca bir vize sorusunu gösterdi: "Bu çizgenin kromatik polinomu nedir ve en az kaç renkle boyanır?" Cevap "4 ile de boyarız, 5 ile de boyarız" olmamalıdır.

Hoca bir kenarı söktü. Kalan çizge, ortak kenarlı iki üçgen (elmas) oldu. Söktüğü kenarın düğümlerini üst üste katladı. İki üçgen yine üst üste oturdu ve bir üçgen ($K_3$) çıktı. Elmasın iki üçgenin ortak bir kenarla birleşmesi olduğu tanınırsa, polinomu çarpıp bölerek yazılır:

$$P = \frac{\left[x(x-1)(x-2)\right]^2}{x(x-1)} - x(x-1)(x-2) = x(x-1)(x-2)\left[(x-2) - 1\right] = x(x-1)(x-2)(x-3)$$

Yine aynı sonuç çıkar, çünkü çizge de bir $K_4$'tür. Her düğüm kendi dışındaki bütün düğümlere bağlıdır. Bu görülürse polinom $\prod_{k=0}^{n-1}(x-k)$ formülünden doğrudan yazılabilirdi.

Hoca elmasın tanınmadığı durumu da anlattı. O zaman elmastan köşegen olmayan bir kenar çıkarılır. Geriye bir üçgen ve ona tek kenarla bağlı bir nokta kalır. Çıkarılan kenarın düğümleri birleştirilince bir üçgen kalır. Bunlar ayrı ayrı çözülüp yerlerine konur (ara adım eklendi):

$$P(\text{elmas}) = x(x-1)(x-2)\cdot(x-1) - x(x-1)(x-2) = x(x-1)(x-2)^2$$

<!-- BELİRSİZ: Vize sorusundaki çizgenin çizimi ve hocanın söktüğü kenar altyazıdan tam çıkmıyor. Hoca sonuç için "bu da bir K grafı" dedi. -->

## 20. Son Örnek: $W_4$ Çizgesi

Hoca son ve biraz daha zor bir örnek verdi. Çizgede 5 düğüm vardı: dört köşe düğümü ve hepsine bağlı ortada bir düğüm (5). Bu çizge bir $K$ çizgesi değildir, çünkü her düğüm diğer bütün düğümlere bağlı değildir. Örneğin 1, 4 ile; 3, 2 ile bağlı değildir. Çizgede $4$ dış, $4$ iç olmak üzere 8 kenar vardır. Bu çizge $W_4$ tekerlek çizgesidir.

**Adım 1.** 2 ile 4 arasındaki kenar koparılır ve bu iki düğüm birleştirilir. Hoca hangi kenarın koparılacağına, çizgeyi tanıdık bir çizgeye nasıl benzetebileceğine bakarak karar verdiğini söyledi. Birleştirme sonucu çıkan çizge bir $K_4$'tür. Bu artık bilinir:

$$P(W_4) = P(W_4 - e) - P(K_4)$$

**Soru:** Bize gönderdiğiniz kurala göre bu çizgeyi doğrudan parçalara bölemez miyiz? Parçalar birbirine kenarla ve noktayla bağlı. **Cevap:** Bölebilirsiniz. Ama burada üç parça var, iki değil. Hem kenarla hem noktayla bağlanan parçalar var. Birini eksik yazarsanız sonuç gider. Hata olasılığı artar, o yüzden daha ılımlı davranıp silme-büzmeyle devam ediyoruz.

<!-- BELİRSİZ: Bu soru altyazıda hocanın ağzından "bana diyebilirsiniz ki" diye aktarıldı; bir öğrencinin sorup sormadığı belli değil. -->

**Adım 2.** $W_4 - e$ tanınmaz. Ondan bir kenar daha çıkarılır. Kenarın düğümleri birleştirilince ortak kenarlı iki üçgen (elmas) çıkar. Bu tanınır. Kenar silinmiş çizge ise bir elmas ve ona tek kenarla bağlı bir noktadır.

**Adım 3.** Bu son çizgeden de o tek kenar silinir. Geriye bir elmas ve boşta kalan bir nokta kalır. Kenarın düğümleri birleştirilince yine elmas çıkar.

Hoca işlem kalabalığı olmasın diye tekrar eden elmas çizgesine $A$ adını verdi. En sonda $A$'nın yerine elmasın polinomu konur:

- Elmas ve boşta bir nokta: $A \cdot x$.
- Elmas ve ona tek kenarla bağlı nokta: $Ax - A = A(x-1)$.
- $W_4 - e$: $A(x-1) - A = A(x-2)$.

Böylece:

$$P(W_4) = A(x-2) - P(K_4), \qquad A = x(x-1)(x-2)^2$$

$$P(W_4) = x(x-1)(x-2)^3 - x(x-1)(x-2)(x-3)$$

$$P(W_4) = x(x-1)(x-2)\left[(x-2)^2 - (x-3)\right] = x(x-1)(x-2)(x^2 - 5x + 7)$$

$$P(W_4) = x^5 - 8x^4 + 24x^3 - 31x^2 + 14x$$

<!-- BELİRSİZ: Adım 2 ve 3'te silinen kenarların hangileri olduğu altyazıdan tam çıkmıyor. Ara çizgeler hocanın sözlü anlatımından ve A(x-1), A(x-2) hesabından kuruldu (ara adım eklendi). -->

Kontroller:

- 5 düğüm vardır, polinomun derecesi 5'tir.
- 8 kenar vardır (dört içeride, dört dışarıda), ikinci katsayı 8'dir.
- Sabit terim yoktur, baş katsayı 1'dir.
- İşaretler $+, -, +, -, +$ diye gider.
- Katsayılar toplamı: $14 + 24 = 38$, $38 + 1 = 39$, $39 - 8 = 31$, $31 - 31 = 0$.

Polinom doğrudur. Kaç renkle boyanacağı için $k$ yerine 1, 2, ... konur. Polinomu sıfırdan farklı yapan ilk değer kromatik sayıdır. Hoca bu değerleri slayta yazmadığını söyledi. Elle kırmızı, mavi ve sarı ile boyayarak 3 rengin yettiğini gösterdi. $P(3)$'ün değeri derste hesaplanmadı. Hesabı "Örnek Sorular" bölümündedir.

Hoca isteyenlerin, vakti olanların bir küpün kromatik polinomunu bulmayı denemesini önerdi ve "bu her babayiğidin işi değildir" dedi.

> **Hocanın vurgusu:** Dışarıda kalan noktaları kesinlikle unutmayın. Tanıdığınız çizgeleri kullanın, onları tekrar bölmeyin. Tekrar eden alt çizgelere bir değişken adı verin ($A$ gibi) ve en sonda yerine koyun. Noktasal çizgeyi, çizgisel çizgeyi ve $K$ çizgesinin formülünü bilmeniz gerekir. Bunlardan birini görene kadar çizgeyi bölün.

## Örnek Sorular

Bu derste hazır kare yoktur. Aşağıdaki sorular, hocanın derste sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:10:13): Königsberg'deki 7 köprünün her birinden bir kez geçmek şartıyla bütün köprüleri dolaşıp başlanan noktaya dönülebilir mi?

Çözüm (derste verildi): Bölgeler düğüm, köprüler kenar olur. Dereceler A 3, B 3, C 3, D 5'tir. Tek dereceli düğüm olduğu için çizge Euler çizgesi değildir. Bu dolaşma mümkün değildir.

**Soru 2** (derste sözlü, 00:16:07): Her birinin derecesi 6 olan 10 düğümlü bir çizgede kaç kenar vardır?

Çözüm (derste verildi): $\sum \deg(v) = 10 \cdot 6 = 60 = 2e$, buradan $e = 30$.

**Soru 3** (derste sözlü, 00:18:48 - 00:24:41): Verilen çizgelerde Euler devresi var mı, çizge bir Euler çizgesi mi?

<!-- BELİRSİZ: Çizgelerin şekilleri altyazıda yok; yalnız dereceler okunuyor. -->

Çözüm (derste verildi): Dereceler 2, 4, 3, 3, 4 ve 2, 3, 2, 3 olan çizgelerde tek dereceli düğüm vardır, Euler çizgesi değildir. Her kenardan bir kez geçilebilir ama başlangıç ve bitiş farklıdır, yani bir Euler yolu vardır. Dereceler 2, 4, 4, 2, 4, 4 ve 2, 4, 4, 4, 2, 2 olan çizgelerde bütün dereceler çifttir, ikisi de Euler çizgesidir.

**Soru 4** (derste sözlü, 00:30:30): $K_4$ ve $W_3$ birer Euler çizgesi midir? Hamilton çizgesi midir?

> **Çözüm (derste verilmedi):** $K_4$'te her düğümün derecesi 3'tür. Tek dereceli düğüm olduğu için Euler çizgesi değildir. $1 \to 2 \to 3 \to 4 \to 1$ her düğümden bir kez geçen kapalı bir devredir. Bu yüzden $K_4$ bir Hamilton çizgesidir. Rosen'daki tanımla $W_3$, $C_3$'e bir merkez eklenmiş hâldir ve $K_4$'ün aynısıdır, yani sonuç aynıdır. Hoca $W_3$'ü "dört düğüm ve ortada bir düğüm" diye tarif ettiği için kastedilen $W_4$ de olabilir. $W_4$'te dış düğümlerin derecesi 3, merkezinki 4'tür. O da Euler çizgesi değildir. Dış çemberdeki dört düğümden sırayla geçip merkeze giren ve oradan başlangıca dönen bir devre vardır, yani $W_4$ de Hamilton çizgesidir. Python ile doğrulandı.

**Soru 5** (derste sözlü, 00:32:16): Verilen ağırlıklı çizgede A'dan F'ye en kısa yol nedir?

Çözüm (derste verildi): Dijkstra algoritmasıyla adımlar Bölüm 7.2'dedir. En kısa yol A-B-E-D-F, uzunluğu 7'dir. Diğer en kısa uzaklıklar B 2, C 3, E 4, D 5'tir.

**Soru 6** (derste sözlü, 01:07:16): Piramit şeklindeki çizgenin ($K_4$) kaç yüzeyi vardır?

Çözüm (derste verildi): $v - e + f = 2$ formülünde $v = 4$, $e = 6$ olduğundan $f = 4$. Bir taban ve üç yan yüzey vardır.

**Soru 7** (derste sözlü, 01:11:14): Biri kare, biri kelebek görünümlü iki çizge eşyapılı mıdır?

Çözüm (derste verildi): İkisinde de 4 düğüm, 4 kenar vardır ve bütün dereceler 2'dir. Komşuluk matrisleri ilk hâliyle farklıdır. $u_2$ ile $u_4$'ün satırları ve sütunları yer değiştirilince matrisler aynı olur. Çizgeler eşyapılıdır.

**Soru 8** (derste sözlü, 02:03:08): Verilen çizgelerin kromatik sayısı nedir?

Çözüm (derste verildi): Dört düğümün hepsi birbirine komşu olan çizge 4 renk ister. Beş düğümlü çizge 3 renkle, yedi düğümlü çizge de 3 renkle boyanır. Ayrıntı ve düzeltme Bölüm 13.1'dedir.

**Soru 9** (derste sözlü, eski vize sorusu, 02:42:40): Verilen çizgenin kromatik polinomu nedir ve en az kaç renkle boyanır?

Çözüm (derste verildi): Çizge $K_4$'tür. $P = x^4 - 6x^3 + 11x^2 - 6x$. $P(1) = P(2) = P(3) = 0$, $P(4) = 24$. En az 4 renkle boyanır, 4 renkle 24 farklı boyama vardır.

**Soru 10** (derste sözlü, 02:51:34): $W_4$ en az kaç renkle ve o renk sayısıyla kaç farklı biçimde boyanır?

Hoca polinomu buldu ve 3 renkle boyandığını elle gösterdi. Değerleri slayta yazmadığını söyledi.

> **Çözüm (derste verilmedi):** $P(W_4) = x(x-1)(x-2)(x^2 - 5x + 7)$. $P(1) = 0$, $P(2) = 0$. $P(3) = 3 \cdot 2 \cdot 1 \cdot (9 - 15 + 7) = 6$. $W_4$ en az 3 renkle ve 3 renkle 6 farklı biçimde boyanır. Python ile bütün boyamalar sayılarak doğrulandı.

**Soru 11** (derste sözlü, 02:52:44): Küpün kromatik polinomunu bulun ve küpün en az kaç renkle boyanacağını söyleyin.

<!-- BELİRSİZ: Hoca "şu küp" dedi; ekranda hangi küp çizgesinin olduğu altyazıdan çıkmıyor. Çözüm Q3 için verildi. -->

> **Çözüm (derste verilmedi):** $Q_3$ için 8 düğüm ve 12 kenar vardır. Python ile bütün boyamalar sayılarak polinom şöyle bulundu: $P(Q_3) = x^8 - 12x^7 + 66x^6 - 214x^5 + 441x^4 - 572x^3 + 423x^2 - 133x$. Kontroller tutar: derece 8 = düğüm sayısı, ikinci katsayı 12 = kenar sayısı, katsayılar toplamı 0. $P(1) = 0$ ve $P(2) = 2$ olduğu için $Q_3$ en az 2 renkle ve 2 renkle 2 farklı biçimde boyanır. Gray kodu etiketlerinde 1'lerin sayısı tek olan düğümler bir renge, çift olanlar diğer renge boyanır.

## Dersin Toparlaması

Bu derste çizgeler konusu tamamlandı. Önce yol ve devre kavramlarından Euler ve Hamilton çizgelerine geçildi. Euler devresinde her kenardan, Hamilton devresinde her düğümden bir kez geçilir. Euler çizgesi için düğüm derecelerinin çift olması yeterli bir testtir. Hamilton için böyle basit bir test yoktur. Ardından Dijkstra algoritmasıyla bir başlangıç düğümünden diğer düğümlere en kısa yollar bulundu. Tabloda her zaman en küçük değerin kaldığı vurgulandı. Niş örtüşme, etki, dairesel turnuva ve öncelik çizgeleriyle bir çizgenin adının onu nasıl okuyacağımızı belirlediği görüldü. Düzlemsel çizgelerde Euler formülü, eşyapıda da düğüm, kenar, derece ve komşuluk matrisi kontrolleri işlendi. Ağ topolojilerinin aslında $K_{1,n}$, $C_n$ ve $W_n$ olduğu gösterildi.

Dersin ikinci yarısında çizge boyama ve kromatik polinomlar anlatıldı. Kromatik polinom, silme-büzme yöntemiyle çizge noktasal çizge, çizgisel çizge ya da $K_n$ gibi tanıdık çizgelere bölünerek bulunur. Ortak nokta veya kenarla birleşen çizgelerde polinomlar çarpılıp ortak kısmın polinomuna bölünür. Bulunan polinom derece, ikinci katsayı, işaretler ve katsayılar toplamıyla kontrol edilir. Polinomu sıfırdan farklı yapan en küçük renk sayısı kromatik sayıdır. Hoca bir sonraki konunun sonlu durum makineleri olacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
