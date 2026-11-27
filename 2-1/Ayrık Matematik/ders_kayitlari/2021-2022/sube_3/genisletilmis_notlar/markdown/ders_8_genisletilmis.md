# Ders 8 Genişletilmiş Notu: Graf Teorisi: Temel Kavramlar, Özel Graflar, Euler ve Hamilton Döngüleri, Dijkstra, İzomorfizm

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Graf Nedir?
- 2. Özel Kenarlar ve Graf Türleri
- 3. Bir Problemi Grafa İndirgemek: Programların Benzerliği
- 4. Özel Graflar: Tam, Çevre, Tekerlek ve Küp Graflar
- 5. İki Parçalı (Bipartite) Graflar
- 6. Özel Grafların Düğüm ve Kenar Sayıları
- 7. Yollar ve Döngüler
- 8. Euler Döngüsü ve Königsberg Köprü Problemi
- 9. Düğüm Derecesi ve El Sıkışma Teoremi
- 10. Euler Grafı Örnekleri
- 11. Hamilton Döngüsü
- 12. Dijkstra Algoritması
- 13. Graf Modelleri ve Öncelik (Precedence) Grafı
- 14. Düzlemsel Graflar ve Euler Formülü
- 15. Graf İzomorfizmi
- 16. Ağ Topolojileri ve Graflar
- Örnek Sorular
- Dersin Toparlaması

## 1. Graf Nedir?

Bu dersle birlikte graf teorisine (graph theory) geçildi. Hoca, ağaçların da grafların bir alt kümesi olduğunu, bu yüzden önce grafların anlatılacağını söyledi. Ağaçları graflardan ayıran özellik kapalı döngüdür: graflarda kapalı döngü bulunabilir, ağaçlarda bulunmaz.

Bir graf $G$ ile gösterilir ve $G=(V,E)$ biçiminde iki kümeden oluşur. $V$ düğümler (vertex) kümesidir; düğümlere birtakım etiketler verilir. $E$ kenarlar (edge) kümesidir; her kenar iki düğümü birbirine bağlar. Slayttaki örnekte düğümler $x, v, w, y, s, u, z$ gibi harflerle adlandırılmıştı ve kenarlar $vw$, $wy$, $yz$ gibi düğüm çiftleriyle yazılıyordu.

**Kapalı döngü.** Bir düğümden çıkıp başka düğümleri dolaşarak yeniden aynı düğüme gelinebiliyorsa bu bir kapalı döngüdür. Örneğin $v$'den çıkıp $w, y, u, s$ üzerinden yeniden $v$'ye dönmek ya da $v$'den çıkıp $x, s$ üzerinden $v$'ye dönmek birer kapalı döngüdür.

**Yalıtılmış düğüm.** Grafta her düğüm bir kenarla başka bir düğüme bağlı olmak zorunda değildir. Hiçbir kenar bağlantısı olmayan, tek başına kalan düğüme yalıtılmış düğüm (isolated vertex) denir.

## 2. Özel Kenarlar ve Graf Türleri

### 2.1 Paralel kenar ve döngü

Slayttaki grafta (ekrandan, 00:20:00) $a$ ve $b$ düğümleri arasında iki kenar vardır; $d$ düğümünde ise kendisine dönen bir kenar bulunur.

- **Paralel kenar (parallel edges):** İki veya daha fazla kenar aynı düğüm çiftini bağlıyorsa bunlara paralel kenar denir. Örnekte $a$ ile $b$ iki paralel kenarla bağlıdır; $a$ ile $c$ arasında tek kenar olduğu için orada paralel kenar yoktur.
- **Döngü (loop):** Kenarın başlangıç ve bitiş noktası aynı düğümse bu kenar bir döngüdür; örnekteki $d$ düğümünde olduğu gibi.

### 2.2 Graf türleri

Hoca graf türlerini, basit graftan başlayıp her adımda bir özellik ekleyerek anlattı.

- **Basit graf (simple graph):** Yön yoktur, paralel kenar yoktur, döngü yoktur.
- **Çoklu graf (multigraph):** Basit grafa paralel kenar eklenerek elde edilir. Yön ve döngü yine yoktur. Örneğin bir basit grafta $v_1$ ile $v_2$ arasına ikinci bir kenar çizilince graf çoklu graf olur.
- **Sözde graf (pseudograph):** Çoklu grafın yetmediği durumlarda ona döngü de eklenir. Yön hâlâ yoktur. Yönsüz grafların en gelişmiş hâli budur.
- **Ağırlıklı graf (weighted graph):** Kenarlara bir değer verilmiştir. Bu değer problemin türüne göre iki şehir arasındaki kilometre, iki elektrik santrali arasındaki hattın kapasitesi, bir maliyet ya da uzunluk olabilir.
- **Yönlü graf (directed graph, digraph):** Kenarların yönü vardır. Örneğin $A$'dan $F$'ye bir yol olup $F$'den $A$'ya olmayabilir. Hoca bunu tek yönlü ve çift yönlü caddelere benzetti: ulaşım grafları yönlü graflardır.

Bu türler slaytta şöyle özetlendi (ekrandan, 00:25:00):

| Tip | Kenar | Çoklu kenara izin? | Döngüye izin? |
|---|---|---|---|
| Basit graf | Yönsüz | Hayır | Hayır |
| Çoklu graf | Yönsüz | Evet | Hayır |
| Pseudo graf | Yönsüz | Evet | Evet |
| Yönlü graf | Yönlü | Hayır | Evet |
| Yönlü çoklu graf | Yönlü | Evet | Evet |

En yalın graf yönü, paralel kenarı ve döngüsü olmayan graftır. En karmaşık hâlinde yön, paralel kenar, döngü ve kenar ağırlıkları birlikte bulunur.

## 3. Bir Problemi Grafa İndirgemek: Programların Benzerliği

Hoca, bir problemin grafa indirgenip graf üzerinde çözülebileceğini bir benzerlik örneğiyle gösterdi. Elimizde birçok bilgisayar programı olsun ve her birinden üç özellik çıkarılmış olsun: satır sayısı (lines of code), `return` sayısı ve çağrılan fonksiyon sayısı. Programların yazıldığı dil gibi başka farklar dikkate alınmaz; yalnız bu üç özelliğe bakarak programları benzerlik kümelerine ayırmak istiyoruz.

Tablo (ekrandan, 00:35:00):

| Program | Satır sayısı | `return` sayısı | Fonksiyon çağrısı |
|---|---|---|---|
| 1 | 66 | 20 | 1 |
| 2 | 41 | 10 | 2 |
| 3 | 68 | 5 | 8 |
| 4 | 90 | 34 | 5 |
| 5 | 75 | 12 | 14 |

Her program bir düğüm olur: $v_1, \dots, v_5$. Her düğümün üç özelliği vardır.

İki düğümün ne kadar benzediğini ölçmek için benzerlik (similarity) ya da benzer olmama (dissimilarity) fonksiyonları kullanılır; literatürde bunlardan onlarcası vardır. Slayttaki tanım (ekrandan, 00:30:00): her düğüm çifti $v=(p_1,p_2,p_3)$ ve $w=(q_1,q_2,q_3)$ ile gösterilsin.

$$s(v,w)=\sum_{k=1}^{3}|p_k-q_k|$$

Mutlak değer alınır, çünkü artı ve eksi farklar birbirini götürüp sıfıra yakın bir sonuç verebilir ve iki program yanlışlıkla çok benzer görünebilir. $N$ seçilen sabit bir eşik (threshold) olsun. $s(v,w)<N$ ise $v$ ile $w$ arasına kenar eklenir. $v=w$ ise ya da $v$ ile $w$ arasında bir yol varsa $v$ ile $w$ aynı sınıftadır. Hoca eşiğin deneylerle bulunduğunu, hangi alanda çalışılırsa çalışılsın en iyi sonucu veren eşik değerinin seçildiğini söyledi. Örnekte $N=25$'tir.

**Hesap.** $v_1$ ile $v_2$ için:

$$s(v_1,v_2)=|66-41|+|20-10|+|1-2|=25+10+1=36$$

Bütün çiftler (python ile kontrol edildi):

| Çift | $s$ | Çift | $s$ |
|---|---|---|---|
| $v_1,v_2$ | 36 | $v_2,v_4$ | 76 |
| $v_1,v_3$ | 24 | $v_2,v_5$ | 48 |
| $v_1,v_4$ | 42 | $v_3,v_4$ | 54 |
| $v_1,v_5$ | 30 | $v_3,v_5$ | 20 |
| $v_2,v_3$ | 38 | $v_4,v_5$ | 46 |

$25$'ten küçük olan yalnız $s(v_1,v_3)=24$ ve $s(v_3,v_5)=20$'dir. Bu yüzden grafa $v_1$-$v_3$ ve $v_3$-$v_5$ kenarları eklenir. $v_2$ ve $v_4$ hiçbir düğüme bağlanmaz, ayrı kalır.

> **Ders sonrası not:** Hoca, kenarla bağlanan $v_1, v_3, v_5$ için "bunlar birbirine benzemiyor, benzer olmayanları bir grafta topladım" dedi. Slayttaki tanıma göre kenar, benzer olmama değeri eşikten **küçük** olduğunda eklenir ve aralarında yol olan düğümler aynı sınıftadır. Benzer olmama değerinin küçük olması programların birbirine yakın olduğu anlamına gelir. Doğrusu: $v_1$, $v_3$, $v_5$ bu üç özellik açısından aynı benzerlik sınıfındadır; $v_2$ ve $v_4$ ayrı birer sınıf oluşturur.

Hoca bu örnekten şu sonucu çıkardı: bir problem grafa indirgenerek çözülebilir. İleriki slaytlarda başka problemlerin de graflarla nasıl çözüldüğü görülecektir.

## 4. Özel Graflar: Tam, Çevre, Tekerlek ve Küp Graflar

### 4.1 Tam graf $K_n$

Tam graf (complete graph) $K_n$ ile gösterilir; $n$ grafın düğüm sayısıdır. Her düğüm kendisi dışındaki bütün düğümlere bağlıysa graf tamdır. Slayttaki beş düğümlü grafta $A$ bütün düğümlere, $B$ kendisi dışındaki bütün düğümlere bağlıdır; diğer düğümler için de aynısı geçerlidir. Bu yüzden graf $K_5$'tir. Hoca $K_4$'ü dört düğümü birbirine bağlayarak, $K_3$'ü de bir üçgen olarak çizdi. Hoca $K_n$ için $n\ge 3$ koşulunu söyledi.

### 4.2 Çevre graf $C_n$

Çevre graf (cycle graph) $C_n$ ile gösterilir ve $n\ge 3$'tür. Her düğüm bir sonrakine bağlanır ve son kenarın ucu ilk düğümle aynı olur; böylece graf bir çember (kapalı döngü) oluşturur. $C_3$ üçgendir. $C_4$'te $v_1v_2$, $v_2v_3$, $v_3v_4$, $v_4v_1$ kenarları vardır. $C_6$ bir altıgendir.

Hoca $C_6$ ile $K_6$'yı karşılaştırdı: $C_6$'yı tam grafa çevirmek için her düğümü komşu olmadığı bütün düğümlere de bağlamak gerekir. Bütün köşegenler eklenince $C_6$, $K_6$ olur.

### 4.3 Tekerlek graf $W_n$

Tekerlek graf (wheel graph) $W_n$, $C_n$ grafına ek bir düğüm eklenerek elde edilir. Bu ek düğüm diğer bütün düğümlere bağlanır.

**Soru:** Mavi ile çizilen graf hangi graftır? **Cevap:** Bir öğrenci "$C_3$" dedi. Hoca bu $C_3$'ün ortasına bir düğüm koyup üç düğüme de bağladı ve bunun $W_3$ olduğunu gösterdi.

Önemli nokta: düğüm sayısı 4 olduğu hâlde merkezdeki düğüm sayılmaz ve grafa 3 düğümlü tekerlek grafı ($W_3$) denir. $W_4$ için önce $C_4$ çizilir, ortaya bir düğüm konup dört düğüme bağlanır. $W_5$ de aynı biçimde $C_5$'ten elde edilir. Ek düğüm çemberin dışına da konabilir, ama o zaman kenarlar birbirini keser ve düğüm sayısı arttıkça şekil zor okunur; bu yüzden genellikle çemberin içinde bir nokta seçilir.

### 4.4 Küp graf $Q_n$

Küp graf (n-cube) $Q_n$ diğerlerinden farklıdır: $n$ düğüm sayısını vermez. Grafın düğüm sayısı $2^n$'dir. Slayttaki tanım (ekrandan, 00:45:00): grafın düğüm noktaları $n$ uzunluğunda bit dizileriyle gösterilir ve bir düğümden diğerine geçerken aynı anda yalnız bir bitin değeri değişir.

$Q_3$ için $2^3=8$ düğüm vardır ve graf bir küp olarak çizilir. Etiketler 3 bitliktir. Hoca $000$'dan başlayıp her adımda yalnız bir biti değiştirerek dolaştı ve Gray kodlamasını hatırlattı. Slayttaki sıra:

$$000,\ 001,\ 011,\ 010,\ 110,\ 111,\ 101,\ 100,\ 000$$

Bu sırayla bütün düğümlerden bir kez geçilip başa dönülür. Hoca bunun ileride Euler ve Hamilton graflarında önemli olacağını söyledi.

- $Q_1$: $2^1=2$ düğüm, tek kenar. Etiketler $0$ ve $1$'dir.
- $Q_2$: $2^2=4$ düğüm. Dört düğüm bir kare oluşturur, yani $Q_2$ aynı zamanda $C_4$'tür. Etiketler $00, 01, 11, 10$'dur; her geçişte yalnız bir bit değişir.
- $Q_4$: $2^4=16$ düğüm. İç içe iki küp çizilir (her birinde 8 düğüm) ve iki küpün karşılıklı düğümleri birbirine bağlanır. Etiketler 16 farklı 4 bitlik Gray kodu olur.

Hoca $Q_5$'te $2^5=32$ düğüm olacağını, graf çok karmaşıklaştığı için daha ileri gitmeye gerek olmadığını söyledi.

## 5. İki Parçalı (Bipartite) Graflar

### 5.1 Tanım

Bir $G$ grafı iki parçalı (bipartite) ise düğümleri iki kümeye ayrılabilir: $G_1$ ve $G_2$. Bu iki kümenin birleşimi grafın bütün düğümlerini verir, kesişimi ise boş kümedir. Birinci kümede $m$, ikinci kümede $n$ düğüm olsun. Bölmenin tek koşulu şudur: **aynı kümede bulunan düğümler arasında hiç kenar olmamalıdır.**

Slayttaki beş düğümlü örnekte $\{A,B,C\}$ ve $\{D,E\}$ kümeleri seçilmiştir. $A$-$B$, $A$-$C$, $B$-$C$ arasında kenar yoktur; $D$-$E$ arasında da kenar yoktur. Bu yüzden graf iki parçaya ayrılabilir. $E$ birinci kümeye konamazdı, çünkü $E$'nin hem $A$ ile hem $B$ ile kenarı vardır.

### 5.2 $K_3$ ve $C_6$

Slayttaki sorular (ekrandan, 00:55:00):

- **$K_3$ iki parçalı mıdır?** $a$ bir kümeye konur. $b$, $a$'ya bağlı olduğu için onunla aynı kümeye konamaz. $c$ hem $a$'ya hem $b$'ye bağlı olduğu için hiçbir kümeye konamaz. Cevap: **Hayır.**
- **$C_6$ iki parçalı mıdır?** Düğümler $a,b,c,d,e,f$ olsun ve çember $a$-$b$-$c$-$d$-$e$-$f$-$a$ olsun. $a$ birinci kümeye konur. $b$, $a$'ya bağlı olduğu için ikinci kümeye gider. $c$'nin $a$ ile bağlantısı yoktur, birinci kümeye konur. $d$, $c$'ye bağlı olduğu için ikinci kümeye gider ($b$ ile bağlantısı yoktur). $e$'nin $a$ ve $c$ ile bağlantısı yoktur, birinci kümeye konur. $f$ hem $a$'ya hem $e$'ye bağlı olduğu için ikinci kümeye gider. Sonuç: $\{a,c,e\}$ ve $\{b,d,f\}$. Cevap: **Evet**, $C_6$ iki parçalıdır.

Hoca buradan şu sonucu çıkardı: tam graflar iki parçalı yapılamaz, çünkü her düğüm diğer bütün düğümlere bağlıdır.

> **Ek bilgi (derste anlatılmadı):** Bir graf ancak tek uzunlukta bir döngü içermiyorsa iki parçalıdır. Bu yüzden $C_n$, $n$ çiftse iki parçalı, $n$ tekse iki parçalı değildir. $K_n$ ise $n\ge 3$ için bir üçgen içerdiğinden iki parçalı olamaz.

### 5.3 Sınıfa sorulan iki graf

Hoca ekranda iki graf gösterip iki parçalı olup olmadıklarını sordu. Birinci grafta $F$ düğümü $A, B, C, D, E$'nin hepsine bağlıydı; ayrıca $A$ ile $B$, $B$ ile $C$ de bağlıydı. $F$ tek başına bir kümede kalsa bile diğerleri aynı kümede olamaz, çünkü örneğin $A$ ile $B$ arasında kenar vardır. Bu yüzden graf iki parçalı değildir. İkinci grafta hoca $G$ ile $F$'nin komşu olmadığını görüp onları bir kümeye, $A, B, C, D, E$'yi diğer kümeye koydu ve grafın iki parçalı olduğunu söyledi; ama "hata da yapabilirim" diyerek emin olmadığını belirtti.

<!-- BELİRSİZ: Bu iki grafın şekli karelerde yok; kenar listesi altyazıdan tam çıkarılamadı. İkinci grafın gerçekten iki parçalı olup olmadığı doğrulanamadı. -->

### 5.4 Tam iki parçalı graf $K_{m,n}$

Slayttaki tanım (ekrandan, 01:00:00): tam (complete) iki parçalı graf $K_{m,n}$ biçiminde gösterilir. Grafın düğümleri $m$ ve $n$ elemanlı iki alt kümeye ayrılır: $|V(G_1)|=m$, $|V(G_2)|=n$. Bir kenarın iki ucu farklı alt kümelerin elemanı olmak zorundadır. "Tam" olması, bir kümedeki **her** düğümün karşı kümedeki **her** düğüme bağlı olması demektir.

Slayttaki $K_{3,2}$'de üç düğümlü kümedeki her düğüm iki düğümlü kümedeki her düğüme bağlıdır; toplam $3\cdot 2=6$ kenar vardır. Bu kenarlardan biri eksik olsaydı graf yine iki parçalı olurdu ama tam iki parçalı olmazdı. Hoca $K_{3,3}$'te $9$, $K_{2,6}$'da $12$ kenar olacağını söyledi.

## 6. Özel Grafların Düğüm ve Kenar Sayıları

Slaytta $K_n$, $C_n$, $W_n$, $K_{m,n}$ ve $Q_n$ graflarının düğüm ve kenar sayıları formüle edildi (ekrandan, 01:05:00). Hoca her formülü küçük bir örnekle kontrol etti.

- **$K_n$:** $n$ düğüm, $\dfrac{n(n-1)}{2}$ kenar. $K_3$'te $\dfrac{3\cdot2}{2}=3$ kenar, $K_4$'te $\dfrac{4\cdot3}{2}=6$ kenar vardır.
- **$C_n$:** $n$ düğüm, $n$ kenar. Bir öğrenci $C_6$ için "$n$ olmaz mı?" diye sordu; hoca kenarları tek tek sayıp $6$ düğüm, $6$ kenar olduğunu doğruladı.
- **$W_n$:** $n+1$ düğüm (merkez dahil), $2n$ kenar. $C_n$'nin $n$ kenarına merkezden çıkan $n$ kenar eklenir. $W_6$ çizilerek doğrulandı; bir öğrenci sonucu "$2n$" olarak söyledi.
- **$K_{m,n}$:** $m+n$ düğüm, $mn$ kenar.
- **$Q_n$:** $2^n$ düğüm, $n\cdot 2^{n-1}$ kenar. $Q_1$ için $1\cdot 2^0=1$, $Q_2$ için $2\cdot 2^1=4$ kenar çıkar; ikisi de çizimlerle tutar.

> **Ek bilgi (derste anlatılmadı):** $Q_n$'in kenar formülü şöyle de görülebilir: her düğümün $n$ biti vardır ve her bit değiştirilerek bir komşuya gidilir, yani her düğümün derecesi $n$'dir. Derecelerin toplamı $n\cdot 2^n$'dir ve her kenar iki kez sayıldığı için kenar sayısı $n\cdot 2^{n-1}$ olur.

## 7. Yollar ve Döngüler

Aradan sonra hoca graflar üzerindeki yollar (path) ve döngülerden (cycle) bahsetti. Slaytta solda "path of length 7" diye bir şekil vardı: bir düğümden başlayıp diğer uca kadar 7 kenardan geçiliyordu ve yol üzerinde 8 düğüm vardı.

- $n$ uzunluğunda bir yolda $n+1$ düğüm bulunur.
- $n$ uzunluğunda bir döngüde $n$ düğüm bulunur, çünkü başlangıç ve bitiş düğümü aynıdır.

<!-- BELİRSİZ: Hoca sağdaki döngü şekli için "dokuz kenar, dokuz düğüm" diye saydı; bu şeklin karesi yok. -->

## 8. Euler Döngüsü ve Königsberg Köprü Problemi

Slayttaki tanım (ekrandan, 01:20:00): $G$ grafı içindeki Euler döngüsü (Euler cycle) basit bir çevrim olup $G$ grafı içindeki her kenardan yalnız bir kez geçilmesine izin verir. Başlangıç ve bitiş noktaları aynıysa bu bir Euler döngüsüdür.

**Königsberg köprü problemi.** Kitaplarda verilen klasik örnekte Königsberg kasabasından bir nehir geçer. $A$, $B$, $C$, $D$ kara parçalarıdır ve kara parçaları arasında yedi köprü vardır. Soru: başlangıç ve bitiş noktası aynı olmak üzere yedi köprüden yalnız birer kez geçerek başlangıç noktasına dönmek mümkün müdür? Hoca bunun bir bulmaca sorusuna benzediğini söyledi.

Problemi grafa indirgemek için kara parçaları düğüm, köprüler kenar yapılır. Slayttaki grafta $a$ ile $d$ arasında iki paralel kenar, $c$ ile $d$ arasında iki paralel kenar vardır; $b$ ise $a$, $c$ ve $d$'ye birer kenarla bağlıdır. Elle denemek sonuç vermez; problemi çözmek için düğüm derecelerini bilmek gerekir. Hoca bu yüzden önce derece kavramına geçti.

## 9. Düğüm Derecesi ve El Sıkışma Teoremi

### 9.1 Derece

Slayttaki tanım (ekrandan, 01:25:00): $v$ düğümünün derecesi $\delta(v)$ ile gösterilir ve yönsüz bir grafta düğüme gelen kenarların toplamıdır. Düğüm noktalarındaki döngü düğüm derecesine 2 kez katılır, çünkü döngü düğüme bir kez girer ve bir kez çıkar.

Slayttaki grafta kenarlar şunlardır: $ab$, $ac$ (iki paralel kenar), $ad$, $bd$, $be$, $cd$, $cf$, $de$, $df$, $dg$, $ef$, $eg$, $fg$. Dereceler:

| Düğüm | $a$ | $b$ | $c$ | $d$ | $e$ | $f$ | $g$ |
|---|---|---|---|---|---|---|---|
| Derece | 4 | 3 | 4 | 6 | 4 | 4 | 3 |

Hoca, $d$'ye bir döngü eklenseydi derecesinin 2 artacağını söyledi.

> **Ders sonrası not:** Hoca hiçbir kenarı olmayan, derecesi 0 olan düğüme "pendant" dedi. Doğrusu: derecesi 0 olan düğüm yalıtılmış (isolated) düğümdür; pendant (sarkık) düğüm derecesi 1 olan düğümdür.

### 9.2 El sıkışma teoremi

El sıkışma (handshaking) teoremi: $e$ kenarlı bir grafın düğüm derecelerinin toplamı kenar sayısının iki katına eşittir.

$$\sum_{v\in V}\delta(v)=2e$$

**Örnek 1 (derste sözlü):** Her birinin derecesi 6 olan 10 düğümlü bir grafın kaç kenarı vardır? Derecelerin toplamı $10\cdot 6=60$'tır. $60=2e$ olduğundan $e=30$ kenar vardır.

**Örnek 2 (ekrandan, 01:30:00):** Hoca beş düğümlü bir graf çizdi. Düğüm dereceleri $2, 3, 3, 3, 3$'tür. Hoca önce toplamı yanlışlıkla 15 diye yazdı, sonra yeniden sayıp 14 buldu. $14=2e$ olduğundan $e=7$'dir. Kenarlar tek tek sayılınca gerçekten 7 kenar olduğu görüldü.

### 9.3 Yönlü graflarda derece

Yönlü bir grafta bir düğüme giren ve düğümden çıkan kenarlar ayrı sayılır. Giren kenarların sayısı giriş derecesi (in-degree), çıkan kenarların sayısı çıkış derecesidir (out-degree). Hoca giren kenarları $-1$, çıkan kenarları $+1$ diye işaretledi. Çizdiği iki örnekte bütün giriş derecelerinin toplamı bütün çıkış derecelerinin toplamına eşit çıktı (birinci örnekte 3 ve 3, ikinci örnekte 6 ve 6).

> **Ders sonrası not:** Hoca "yönlü bir grafta düğümlerin giriş ve çıkış dereceleri eşit olmalı" dedi. Bu eşitlik tek tek düğümler için değil, bütün düğümler üzerinden toplam için geçerlidir: $\sum \deg^-(v)=\sum \deg^+(v)=|E|$. Tek bir düğümün giriş ve çıkış dereceleri farklı olabilir; hocanın ikinci örneğinde de öyleydi.

### 9.4 Euler grafı koşulu ve Königsberg'in cevabı

Bir $G$ grafı Euler döngüsüne sahipse Euler grafı adını alır. **Euler grafında bütün düğümlerin derecesi çifttir.** Euler grafında bir düğümden birden fazla kez geçilebilir ama her kenardan tam bir kez geçilir.

Königsberg grafında düğüm dereceleri $3, 3, 3, 5$'tir. Tek bir düğümün bile derecesi tek olsa graf Euler grafı olamaz. Bu yüzden her köprüden bir kez geçerek başa dönmek mümkün değildir; Königsberg köprü probleminin çözümü yoktur.

> **Ek bilgi (derste anlatılmadı):** Bağlı bir grafta Euler döngüsü ancak bütün düğüm dereceleri çiftse vardır. Başa dönmesi gerekmeyen Euler yolu (Euler path) ise ancak derecesi tek olan düğüm sayısı 0 ya da 2 ise vardır; tam iki tek dereceli düğüm varsa yol bu iki düğümden birinde başlar, diğerinde biter.

## 10. Euler Grafı Örnekleri

Slayttaki soru (ekrandan, 01:35:00 ve 01:40:00): "Aşağıda verilmiş olan graflardan hangilerinde her kenardan en az bir kez geçirilerek graf gezilmiştir, hangileri Euler grafıdır, eğer değilse sebebi nedir?"

Dört graf vardı:

- **Birinci graf** (çatılı ev biçimi, köşegenli): "start" ve "stop" farklı düğümlerdedir. Her kenardan bir kez geçilir ama başa dönülmez. Hoca dereceleri $3, 4, 2, 4, 3, \dots$ diye sayıp bazı düğümlerin derecesinin tek olduğunu gösterdi. Slayttaki cevap: "Path var, Euler grafı değil. Düğüm dereceleri çift değil."
- **İkinci graf** (sol alt, dörtgen ve köşegen): Bir düğümün derecesi 2, bir diğerinin 3'tür; derecesi tek bir düğüm bulunduğu için diğerlerine bakmaya gerek yoktur. Slayttaki cevap: "Path var, Euler grafı değil. Düğüm dereceleri çift değil."
- **Üçüncü graf** (sağ üst): Dereceler $2, 4, 4, 2, 4, 4$'tür. Hepsi çift olduğu için Euler grafıdır. Başlangıç ve bitiş ("start, stop") aynı düğümdedir.
- **Dördüncü graf** (sağ alt, üçgen biçimi): Dereceler $2, 4, 2, 4, 2, 4$'tür. Euler grafıdır; başlanan düğümde bitirilir.

**Soru:** Soldaki graflar için "Euler cycle var" diyoruz; ama cycle olması için başlanan yerde bitirmek gerekmiyor mu? **Cevap:** Hoca önce cycle'ı "her kenarı gezen kapalı bir çevrim, başladığın yere dönmek zorunda değilsin" diye açıkladı. Öğrenci "buna path mi diyeceğiz, cycle mı?" diye sorunca hoca "path diyelim; path var ama Euler grafı değil" dedi.

> **Ders sonrası not:** Tanım gereği döngü (cycle) başladığı düğümde biter. Başladığı yere dönmeden her kenardan bir kez geçen yürüyüş Euler yoludur (Euler path), Euler döngüsü değildir. Slayttaki "Path var" ifadesi doğru terimdir.

> **Hocanın vurgusu:** Euler grafı olabilmesi için düğüm derecelerinin hepsinin çift olması gerekir; dereceler çiftse başlanan düğümde mutlaka bitirilebilir.

## 11. Hamilton Döngüsü

Euler'de her **kenardan** bir kez geçiliyordu. Hamilton'da ise her **düğümden** bir kez geçilir. $G$ grafının üzerindeki her düğümden yalnız bir kez geçmek şartıyla kapalı bir yol oluşturulabiliyorsa, yani başlanan düğüme geri dönülüyorsa, buna Hamilton döngüsü (Hamilton cycle) denir. Hamilton döngüsüne sahip grafa Hamilton grafı denir.

Hoca bunun gezgin satıcı (travelling salesperson) problemiyle ilgili olduğunu, algoritmasının veri yapıları ya da algoritmalar dersinde görüleceğini söyledi. Benzetmesi: arabasıyla köy köy dolaşıp mal satan biri, girdiği bir köye bir daha girmeden bütün köyleri dolaşıp ilk çıktığı yere dönmek ister ve bunu en az maliyetle yapmak ister. Başka bir benzetme: evler arasında kanalizasyon tesisatı kurarken iki ev arasına yalnız bir kez tesisat çekilir, çünkü birden fazla çekmek maliyeti artırır.

Euler'deki derece koşulu gibi kolay bir Hamilton koşulu yoktur; bunu bulmak için bir algoritma kurmak gerekir. Hoca slaytta bir grafın Hamilton döngüsünü gösterdi. Ayrıca daha önce görülen $Q_3$'ün bir Hamilton döngüsüne sahip olduğunu, koyu çizgilerin bütün düğümlerden birer kez geçip başa döndüğünü gösterdi. Bu döngüde bazı kenarlardan hiç geçilmez, çünkü amaç her kenardan değil her düğümden geçmektir.

## 12. Dijkstra Algoritması

Hoca bu konularla ilgili önemli bir algoritma olarak Dijkstra algoritmasını gösterdi. Slaytta sözde kodu vardı ama derste kod yazılmadığı için algoritma şekil üzerinden anlatıldı.

### 12.1 Örnek

Ağırlıklı graf (ekrandan, 01:45:00): kenarlar $ab=2$, $ac=3$, $bd=5$, $be=2$, $ce=5$, $de=1$, $df=2$, $ef=4$'tür. Düğümler birbirine en az maliyetle bağlanacaktır; hoca bunu evleri kanalizasyon ya da su borusuyla birbirine bağlamaya benzetti. Burada bir döngü oluşması gerekmez.

**Başlangıç.** Başlangıç düğümü $a$'dır ve değeri $0$'dır. Diğer düğümlere henüz yol bilinmediği için çok büyük bir değer ($M$) verilir; amaç en küçük değeri bulmak olduğu için başlangıç değeri büyük seçilir. Tabloda her hücreye "uzaklık + geçilen düğümler" yazılır; örneğin $2a$, "bu düğüme $a$'dan geçerek 2 maliyetle gelindi" demektir.

**Adım 1 ($a$ işlenir).** $a$'dan $b$'ye 2 ile, $c$'ye 3 ile gidilir: $b=2a$, $c=3a$. $d, e, f$ hâlâ $M$'dir. En küçük değer $2a$ olduğu için $b$ seçilir (ekrandan, 01:50:00).

**Adım 2 ($b$ işlenir).** $a$ işlendiği için oraya dönülmez. $d$'ye $2+5=7$ ile, $e$'ye $2+2=4$ ile gidilir: $d=7ab$, $e=4ab$. Geçici değerler arasında en küçüğü $3a$ olduğu için $c$ seçilir.

**Adım 3 ($c$ işlenir).** $c$'den yalnız $e$'ye gidilir: $3+5=8$, yani $8ac$. Ama $e$'ye daha önce $4ab$ ile gelinmiştir. Yeni yol eskisinden uzun olduğu için alınmaz; $e=4ab$ korunur.

> **Hocanın vurgusu:** Bir düğüme yeni bulunan yol eskisinden büyükse alınmaz, eski küçük değer korunur. Yeni yol daha kısaysa (örneğin 3) eskisinin yerine yazılır.

**Adım 4 ($e$ işlenir).** En küçük geçici değer $4ab$'dir, $e$ seçilir. $e$'den $d$'ye $4+1=5$ ile gidilir; bu $7$'den küçük olduğu için $d=5abe$ olur. $e$'den $f$'ye $4+4=8$ ile gidilir: $f=8abe$.

**Adım 5 ($d$ işlenir).** En küçük geçici değer $5$'tir, $d$ seçilir. $d$'den $f$'ye $5+2=7$ ile gidilir; bu $8$'den küçük olduğu için $f=7abed$ olur.

**Adım 6.** Yalnız $f$ kalır ve işlenir.

Sonuç (python ile kontrol edildi):

| Düğüm | En kısa uzaklık | Yol |
|---|---|---|
| $b$ | 2 | $a \to b$ |
| $c$ | 3 | $a \to c$ |
| $e$ | 4 | $a \to b \to e$ |
| $d$ | 5 | $a \to b \to e \to d$ |
| $f$ | 7 | $a \to b \to e \to d \to f$ |

Seçilen kenarlar $ab$, $ac$, $be$, $ed$, $df$'dir. Bazı kenarlardan hiç geçilmez ama bütün düğümler birbirine bağlanır. Hoca bu kenarların ağırlıklarını toplayıp $2+3+2+1+2=10$ buldu ve "bundan daha kısa bir bağlantı çizemezsiniz" dedi. Kenarlar silinince kalan yapı kapalı döngüsü olmayan bir ağaçtır.

> **Ders sonrası not:** Hoca, Kruskal'ı bir "en kısa yol algoritması", Dijkstra'yı ise Kruskal ve Prim gibi bir "minimum yayılan ağaç (minimum spanning tree)" algoritması olarak andı. Doğrusu: Dijkstra tek bir başlangıç düğümünden diğer düğümlere en kısa yolları bulur ve bir **en kısa yol ağacı** üretir. Kruskal ve Prim ise toplam ağırlığı en küçük olan **minimum yayılan ağacı** bulur. Bu örnekte iki ağacın toplam ağırlığı tesadüfen aynıdır (10), ama genelde en kısa yol ağacı minimum yayılan ağaç değildir.

### 12.2 Web demosu

Hoca, slayta konmuş bir web sayfasındaki Dijkstra demosunu gösterdi (ekrandan, 01:55:00). Grafta $u_0, \dots, u_5$ düğümleri vardı ve başlangıç $u_0$'dı. $u_0$'dan $u_2$'ye 13, $u_5$'e 8 ile gidiliyordu. En küçüğü 8 olduğu için $u_5$ seçildi; sonra $u_5$'in komşuları güncellendi ve bir düğüme daha önce 16 ile gelinmişken 15 bulununca eski kenar iptal edildi. Ardından sırayla $u_2$, $u_4$, $u_1$, $u_3$ işlendi. $u_4$ işlenirken $u_3$'e $15+5=20$ ile gelinebildiği için daha önceki daha uzun değer iptal edildi.

**Soru:** $u_5$'ten $u_3$'e $u_4$ üzerinden 7 ve 5 ile gitsek daha kısa olmaz mı? **Cevap:** Hoca, gösterilen çözümlerin doğru olduğunu söyledi ve algoritmanın her adımda yalnız seçilmiş (pembe) düğümün komşularına baktığını, daha önce işlenmiş (mavi) düğümlere geri dönülmediğini açıkladı. $u_4$ işlendiğinde $u_3$'e gerçekten $15+5=20$ ile gelinip değer güncellendi.

<!-- BELİRSİZ: Demodaki kenar ağırlıklarının hepsi karede okunamadı; ara değerler yalnız altyazıdan aktarıldı. -->

Hoca aynı sitede Prim ve Kruskal demolarının da olduğunu söyledi. Prim ve Kruskal ileride gösterilecek, Ford-Fulkerson ise gösterilmeyecek.

## 13. Graf Modelleri ve Öncelik (Precedence) Grafı

### 13.1 Graf modelleri

Hoca bazı graflara kullanıldıkları alana göre özel adlar verildiğini, grafı okurken bu adın neyi anlattığına bakmak gerektiğini söyledi.

- **Niş örtüşme grafı (niche overlap graph):** Bir ekosistemdeki farklı grupları modellemede kullanılır. Örneğin bir tarafta et yiyen hayvanlar (aslan, kaplan, kurt), öbür tarafta ot yiyen hayvanlar, ortada da hem et hem ot yiyen hayvanlar bulunur. Hoca başka örnekler de verdi: içine maya konan yiyecekler, maya konmayan yiyecekler ve ortada her iki biçimde yapılabilen yiyecekler.
- **Etki grafı (influence graph):** Grup çalışmalarında kullanılır. Örneğin dört kişilik bir proje grubunda bir kişi bitirdiği iş paketini iki kişiye gönderir, bu kişiler işlerini başka birine aktarır. Oklar "bu düğümün çıktısı şu düğümün girdisi olacak", yani "kim kimin işini bekliyor" diye okunur.
- **Round-robin turnuva grafı (round-robin tournament graph):** Turnuvaları modeller. Örneğin dört takımlı bir turnuvada iki takım arasındaki ok, okun çıktığı takımın kazandığını gösterir; ok yoksa takımlar berabere kalmıştır.
- **Öncelik grafı (precedence graph):** Bir işlemin sonucunun kendisinden önce gelen işlemlerin sonucuna bağlı olduğu sistemleri modeller. Hoca bunun bilgisayar bilimine en uygun model olduğunu söyledi: birbirini çağıran ve birbirinin sonucunu bekleyen fonksiyonlar ve prosedürler böyle bir grafla gösterilebilir.

### 13.2 Öncelik grafı örneği

Slayttaki işler (ekrandan, 02:25:00):

$$S_1\ a{:}0 \qquad S_2\ b{:}1 \qquad S_3\ c{:}a+1 \qquad S_4\ d{:}b+a \qquad S_5\ e{:}d+1 \qquad S_6\ e{:}c+d$$

Her iş (state) bir çıktı üretir. $S_1$'in çıktısı $a$'dır ve başka bir işe bağlı değildir. $S_2$'nin çıktısı $b$'dir ve o da sabit bir sayıdır. "Pre" önce demektir: her iş, kendisinden önce gelen işlere bağlıdır. Bir iş, kullandığı değeri üreten işe ve o işin bağlı olduğu işlere bağlanır.

- $S_3$ ($c=a+1$): $a$'yı kullanır; $a$ $S_1$'in çıktısıdır. $S_1 \to S_3$.
- $S_4$ ($d=b+a$): $b$ $S_2$'nin, $a$ $S_1$'in çıktısıdır. $S_2 \to S_4$, $S_1 \to S_4$. $S_3$ bağlanmaz, çünkü $S_3$'te $a$ yalnız girdi olarak kullanılır, çıktı değildir.
- $S_5$ ($e=d+1$): $d$ $S_4$'ün çıktısıdır; $S_4$ ise $b$ ve $a$'ya bağlıdır. $S_4 \to S_5$, $S_2 \to S_5$, $S_1 \to S_5$.
- $S_6$ ($e=c+d$): $c$ $S_3$'ün çıktısıdır ve $S_3$, $a$'ya yani $S_1$'e bağlıdır; $d$ $S_4$'ün çıktısıdır ve $S_4$, $S_2$ ile $S_1$'e bağlıdır. $S_3 \to S_6$, $S_1 \to S_6$, $S_4 \to S_6$, $S_2 \to S_6$.

Hoca $S_6$'yı sınıfla birlikte çizdi; $S_1$'in $S_6$'ya ne zaman bağlandığını sorduğunda bir öğrenci "$C$'yi bağlarken" diye cevap verdi. Sonuçta slayttaki grafın yönlü kenarları (ekrandan, 02:30:00):

$$S_1\to S_3,\ S_1\to S_4,\ S_1\to S_5,\ S_1\to S_6,\ S_2\to S_4,\ S_2\to S_5,\ S_2\to S_6,\ S_3\to S_6,\ S_4\to S_5,\ S_4\to S_6$$

**Ek senaryolar.** Hoca bir $S_7$ işi ekleyerek şunları anlattı:

- $S_7$'nin çıktısı yalnız sabit bir sayıya ($5$) bağlıysa $S_7$ hiçbir işe bağlanmaz, tek başına kalır.
- $S_7=5+e$ olsaydı $e$'yi üreten $S_5$ ve $S_6$'ya, onların bağlı olduğu $S_4$, $S_3$, $S_2$, $S_1$'e bağlanırdı.
- $S_7$'nin çıktısı $d$ olsa ($d=5$) ve $S_5$ ile $S_6$ da $d$'yi kullansa, $S_5$ ya da $S_6$'dan $S_7$'ye ok çizilemez. 5. ve 6. işler yapılırken 7. iş daha ortada yoktur.

> **Hocanın vurgusu:** Bir iş ancak kendisinden önce yapılmış işlere bağlanabilir. Önce yapılmış işler sonra gelen işi bekleyemez; gerekiyorsa 7. iş 5. ve 6. işlere bağlanır, tersi olmaz.

## 14. Düzlemsel Graflar ve Euler Formülü

Bir $G$ grafının kenarları birbirini kesmeyecek biçimde çizilebiliyorsa buna düzlemsel graf (planar graph) denir. Hoca slayttaki çizimi bir piramit (dörtyüzlü) gibi düşünmeyi önerdi: kesişiyormuş gibi görünen çizgi aslında arkadaki kenardır.

Slayttaki formül (ekrandan, 02:35:00): $G$ düzlemsel bir graf ise, $v$ düğüm sayısı, $e$ kenar sayısı, $f$ yüzey sayısı olmak üzere

$$v-e+f=2$$

Dörtyüzlüde $v=4$ düğüm ($a, b, c, d$), $e=6$ kenar ve $f=4$ yüzey vardır ($DAB$, $DAC$, $DCB$ ve taban $ACB$). $4-6+4=2$ olur.

> **Ders sonrası not:** Hoca formülü "düğüm sayısından kenar sayısını çıkarıp yüzey sayısını ekleyince 2 elde ediliyorsa graf düzlemseldir" diye anlattı. Slayttaki yön doğrudur: graf düzlemselse (ve bağlıysa) $v-e+f=2$ olur. Yüz sayısı ancak düzlemsel bir çizim üzerinden tanımlandığı için formül tek başına düzlemselliği kanıtlamak için kullanılamaz.

## 15. Graf İzomorfizmi

İzomorfik "eş" demektir. İki grafın izomorfik olup olmadığını bazen bir düğümü çekip yerini değiştirerek görebiliriz, ama her zaman bu kadar kolay değildir. Bu yüzden şu koşullar kontrol edilir:

- Kenar sayıları aynı olmalıdır.
- Düğüm sayıları aynı olmalıdır.
- Düğüm dereceleri aynı olmalıdır.
- Düğümler arasındaki ilişkiyi gösteren komşuluk matrisleri aynı olmalıdır. Matrisler ilk bakışta aynı değilse satır ve sütunların yerleri (aynı permütasyonla) değiştirilerek aynı matris elde edilmeye çalışılır. Elde edilebiliyorsa graflar izomorfiktir.

### 15.1 Beş düğümlü ilk örnek

İlk örnekte iki grafın da 5 düğümü ve 4 kenarı vardı; dereceler de aynıydı (birer tane 4, ikişer tane 3 ve 2 diye sayıldı). Hoca birinci grafın komşuluk matrisini "$A$'dan $A$'ya kenar var mı? Yok. $A$'dan $B$'ye var..." diye yazdı ve matrislerin aynı çıkacağını, düğümlerden biri çekilince iki grafın aynı görüneceğini söyledi.

<!-- BELİRSİZ: Bu ilk örneğin şekli karelerde yok. Altyazıda 5 düğüm, 4 kenar ve 4, 3, 3, 2, 2 dereceleri birlikte geçiyor; bu sayılar el sıkışma teoremiyle tutmuyor (toplam 14, 7 kenar gerekir). Kenar sayısı ya da dereceler Whisper tarafından yanlış aktarılmış olabilir. -->

### 15.2 Kare ve çapraz çizilmiş dörtgen

Slayttaki örnek (ekrandan, 02:40:00): $u$ grafı bir karedir ($u_1u_2$, $u_1u_3$, $u_2u_4$, $u_3u_4$). $v$ grafında kenarlar $v_1v_3$, $v_1v_4$, $v_2v_3$, $v_2v_4$'tür; çizimde iki kenar birbirini keser gibi görünür. Slayttaki not: her iki grafın da 4 düğümü, 4 kenarı vardır ve her düğümün derecesi 2'dir.

Komşuluk matrisleri:

| | $u_1$ | $u_2$ | $u_3$ | $u_4$ |
|---|---|---|---|---|
| $u_1$ | 0 | 1 | 1 | 0 |
| $u_2$ | 1 | 0 | 0 | 1 |
| $u_3$ | 1 | 0 | 0 | 1 |
| $u_4$ | 0 | 1 | 1 | 0 |

| | $v_1$ | $v_2$ | $v_3$ | $v_4$ |
|---|---|---|---|---|
| $v_1$ | 0 | 0 | 1 | 1 |
| $v_2$ | 0 | 0 | 1 | 1 |
| $v_3$ | 1 | 1 | 0 | 0 |
| $v_4$ | 1 | 1 | 0 | 0 |

Matrisler aynı değildir, ama hemen pes edilmez. Hoca önce $u_2$ ile $u_3$'ü değiştirmeyi denedi, yanlış gördüğünü fark edip $u_2$ ile $u_4$'ü değiştirdi. $u$ matrisinde yalnız $u_2$ ve $u_4$ satırları değiştirildiğinde matris hâlâ $v$'ninkiyle aynı değildir. Sütunlar da aynı biçimde değiştirilince (sıra $u_1, u_4, u_3, u_2$) matris şu olur:

| | $u_1$ | $u_4$ | $u_3$ | $u_2$ |
|---|---|---|---|---|
| $u_1$ | 0 | 0 | 1 | 1 |
| $u_4$ | 0 | 0 | 1 | 1 |
| $u_3$ | 1 | 1 | 0 | 0 |
| $u_2$ | 1 | 1 | 0 | 0 |

Bu matris $v$ matrisinin aynısıdır. Bu, $v_2$ düğümünü lastik gibi çekip $v_4$'ün yerine koymak gibidir. İki graf izomorfiktir; eşleme $u_1\to v_1$, $u_4\to v_2$, $u_3\to v_3$, $u_2\to v_4$'tür (python ile kontrol edildi).

### 15.3 Beşgen ve yıldız

Bir sonraki örnekte iki graf birbiriyle hiç ilişkisiz görünüyordu. Hoca, kenarların kesiştiği yerlerde düğüm olmadığını, düğüm olsaydı çizilip adlandırılacağını hatırlattı. İki grafta da 5 düğüm ve 5 kenar vardır ve bütün dereceler 2'dir. Komşuluklar karşılaştırıldığında, örneğin $a$'nın $b$ ve $c$ ile, $b$'nin $d$ ve $a$ ile, $c$'nin $a$ ve $e$ ile bağlı olduğu iki grafta da görülür; matrisler yer değiştirme yapmadan bile aynıdır. Hoca bunu telleri kıvırarak şekil vermeye benzetti: $b$ aşağı, $d$ öbür tarafa çekilince iki şekil aynı olur.

### 15.4 İzomorfik olmayan graflar

Slayttaki üst iki graf (ekrandan, 02:45:00) birbirine benzer görünür. Hoca önce kenar sayılarının farklı olduğunu söyledi, sonra sayıp ikisinde de 6 kenar ve 5 düğüm olduğunu buldu. Ancak sağdaki grafta derecesi 1 olan bir düğüm vardır, soldaki grafta yoktur. Dereceler tutmadığı için matris çizmeye gerek kalmadan grafların izomorfik olmadığı söylenir.

Aynı slayttaki alttaki büyük grafı (sarı düğümlü) hoca soldaki başka bir grafla karşılaştırırken bir öğrenci ortadaki düğümün derecesinin 5 olduğunu, diğer grafta böyle bir düğüm görmediğini söyledi. Hoca çizimin hatalı olduğunu, orijinaline bakıp düzeltilmiş hâlini paylaşacağını söyledi.

<!-- BELİRSİZ: Bu son izomorfizm örneğinin doğru çizimi derste verilmedi. -->

## 16. Ağ Topolojileri ve Graflar

Hoca bazı özel grafların veri iletişiminde, yerel ağlarda kullanılan ağ topolojilerine karşılık geldiğini gösterdi.

- **Yıldız topolojisi (star topology):** Ortada bir sunucu, uçlarda istemciler vardır ve bütün istemciler sunucuya bağlıdır. Graf olarak bu $K_{1,n}$ tam iki parçalı grafıdır: bir kümede tek düğüm (sunucu), öbür kümede birbirine bağlı olmayan $n$ düğüm vardır. Slayttaki örnekte $n=8$'dir, yani $K_{1,8}$.
- **Halka topolojisi (ring topology):** Her cihaz diğer iki farklı cihazla bağlıdır. Bu bir $C_n$ modelidir (ekrandan, 02:50:00).
- **Hibrit topoloji (hybrid topology):** Yıldız ve halka topolojilerini birlikte kullanır; bu tekrarlılık ağın daha güvenli olmasını sağlar. $W_n$ tekerlek graf modeline karşılık gelir. Slayttaki örnek $W_6$'dır.

Hoca topolojileri karşılaştırdı. Halkada bir bağlantı koparsa döngü bozulur ve bazı düğümler arasında iletişim kesilebilir. Yıldızda bir kenar koparsa o istemci başka düğümler üzerinden sunucuya ulaşamaz, ama mesajlar hep tek bir merkez düğüm üzerinden geçer. Halkada ise bir düğümün mesajı ulaştırması için araya birçok düğüm girebilir. Tekerlekte bir bağlantı kopsa bile iletişim başka düğümler üzerinden sağlanabilir; ama yapı daha maliyetlidir. Hangi topolojinin seçileceği coğrafi duruma ve maddi imkânlara bağlıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00). Beş programın satır sayısı, `return` sayısı ve fonksiyon çağrısı sayısı şöyledir: 1: $(66,20,1)$, 2: $(41,10,2)$, 3: $(68,5,8)$, 4: $(90,34,5)$, 5: $(75,12,14)$. $s(v,w)=\sum_{k=1}^{3}|p_k-q_k|$ ve $N=25$ olmak üzere $s(v,w)<N$ ise $v$ ile $w$ arasına kenar ekleyin. Hangi programlar aynı sınıftadır?

> **Çözüm:** Bütün çiftler hesaplanır (Bölüm 3'teki tablo). Yalnız $s(v_1,v_3)=24$ ve $s(v_3,v_5)=20$ değerleri $25$'ten küçüktür. Grafta $v_1$-$v_3$ ve $v_3$-$v_5$ kenarları vardır. Sınıflar: $\{v_1,v_3,v_5\}$, $\{v_2\}$, $\{v_4\}$.

**Soru 2** (ekrandan, 00:45:00). $Q_1$ ve $Q_2$ graflarını çiziniz.

> **Çözüm:** $Q_1$: iki düğüm ($0$ ve $1$) ve aralarında tek kenar. $Q_2$: dört düğüm ($00$, $01$, $11$, $10$) bir kare oluşturur; kenarlar $00$-$01$, $01$-$11$, $11$-$10$, $10$-$00$'dır. $Q_2$ aynı zamanda $C_4$'tür.

**Soru 3** (ekrandan, 00:55:00). $K_3$ iki parçalı (bipartite) graf mıdır? $C_6$ iki parçalı graf mıdır?

> **Çözüm:** $K_3$ değildir; üç düğüm birbirine bağlı olduğu için ikisi aynı kümeye düşer. $C_6$ iki parçalıdır: $\{a,c,e\}$ ve $\{b,d,f\}$.

**Soru 4** (derste sözlü, 01:00:00 civarı). $K_{3,2}$, $K_{3,3}$ ve $K_{2,6}$ graflarında kaç kenar vardır?

> **Çözüm:** $K_{m,n}$'de $mn$ kenar vardır: $3\cdot2=6$, $3\cdot3=9$, $2\cdot6=12$.

**Soru 5** (derste sözlü, 01:28:14). Her birinin derecesi 6 olan 10 düğümlü bir grafın kaç kenarı vardır?

> **Çözüm:** El sıkışma teoremiyle $\sum\delta(v)=10\cdot6=60=2e$, buradan $e=30$.

**Soru 6** (ekrandan, 01:20:00). Königsberg köprü problemi: başlangıç ve bitiş noktası aynı olmak üzere yedi köprüden yalnız birer kez geçerek başlangıç noktasına dönmek mümkün müdür?

> **Çözüm:** Kara parçaları düğüm, köprüler kenar yapılır. Düğüm dereceleri $3, 3, 3, 5$'tir. Euler döngüsü için bütün dereceler çift olmalıdır; bu yüzden mümkün değildir.

**Soru 7** (ekrandan, 01:40:00). Verilen dört graftan hangilerinde her kenardan bir kez geçilerek graf gezilmiştir, hangileri Euler grafıdır, değilse sebebi nedir?

> **Çözüm:** Soldaki iki grafta her kenardan bir kez geçen bir yol (path) vardır ama graflar Euler grafı değildir, çünkü düğüm dereceleri çift değildir. Sağdaki iki grafta bütün düğüm dereceleri çifttir; ikisi de Euler grafıdır ve başlanan düğümde bitirilir.

**Soru 8** (ekrandan, 01:45:00). Kenarları $ab=2$, $ac=3$, $bd=5$, $be=2$, $ce=5$, $de=1$, $df=2$, $ef=4$ olan grafta $a$'dan başlayarak Dijkstra algoritmasını uygulayınız.

> **Çözüm:** Bölüm 12.1'deki adımlarla $b=2$ ($ab$), $c=3$ ($ac$), $e=4$ ($abe$), $d=5$ ($abed$), $f=7$ ($abedf$) bulunur. Seçilen kenarlar $ab$, $ac$, $be$, $ed$, $df$'dir; toplam ağırlık 10'dur.

**Soru 9** (ekrandan, 02:25:00). $S_1\,a{:}0$, $S_2\,b{:}1$, $S_3\,c{:}a+1$, $S_4\,d{:}b+a$, $S_5\,e{:}d+1$, $S_6\,e{:}c+d$ işleri için öncelik grafını çiziniz.

> **Çözüm:** Yönlü kenarlar: $S_1\to S_3$, $S_1\to S_4$, $S_1\to S_5$, $S_1\to S_6$, $S_2\to S_4$, $S_2\to S_5$, $S_2\to S_6$, $S_3\to S_6$, $S_4\to S_5$, $S_4\to S_6$.

**Soru 10** (ekrandan, 02:40:00). Kare biçimindeki $u$ grafı ile $v_1v_3$, $v_1v_4$, $v_2v_3$, $v_2v_4$ kenarlı $v$ grafı izomorfik midir?

> **Çözüm:** İkisinde de 4 düğüm, 4 kenar var ve bütün dereceler 2'dir. $u$ matrisinde $u_2$ ile $u_4$'ün satır ve sütunları değiştirilince $v$ matrisi elde edilir. Graflar izomorfiktir.

**Soru 11** (ekrandan, 02:45:00). Üstteki iki graf (5 düğüm, 6 kenar) izomorfik midir?

> **Çözüm:** Sağdaki grafta derecesi 1 olan bir düğüm vardır, soldakinde yoktur. Derece dizileri farklı olduğu için graflar izomorfik değildir.

## Dersin Toparlaması

Bu derste graf teorisinin temel kavramları işlendi. Graf, düğümler ve kenarlardan oluşan bir yapıdır; paralel kenar, döngü, yön ve ağırlık gibi özelliklere göre basit, çoklu, sözde, yönlü ve ağırlıklı graflar ayrılır. Tam graf $K_n$, çevre graf $C_n$, tekerlek graf $W_n$, küp graf $Q_n$ ve tam iki parçalı graf $K_{m,n}$ tanıtıldı, düğüm ve kenar sayıları formüle edildi. Bir problemin grafa indirgenip graf üzerinde çözülebileceği programların benzerliği ve Königsberg köprüleri örnekleriyle gösterildi. Düğüm derecesi ve el sıkışma teoremiyle Euler grafı koşulu (bütün derecelerin çift olması) kuruldu, ardından her düğümden bir kez geçen Hamilton döngüsü anlatıldı. Dijkstra algoritması bir örnek üzerinde adım adım uygulandı. Son olarak öncelik grafı, düzlemsel graflar ve Euler formülü, graf izomorfizmi ve ağ topolojilerinin graf karşılıkları işlendi.

Hoca bir sonraki derste grafların bir alt konusu olan kromatik polinomlara, ardından ağaçlara geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
