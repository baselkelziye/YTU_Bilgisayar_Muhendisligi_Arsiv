# Ders 5 Genişletilmiş Notu: Bağıntılar ve Özellikleri, Bileşke, Denklik ve Sıralama Bağıntıları, Hasse Diyagramı, Kapanış ve Warshall Algoritması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağıntı Nedir?
- 2. Bağıntıların Gösterimi
- 3. Yansıma Özellikleri: Reflexive, Non-reflexive, Irreflexive
- 4. Simetri Özelliği ve Simetri Algoritması
- 5. Ters Simetri (Antisymmetry)
- 6. Geçişme (Transitivity)
- 7. Örnek: $a = b^2$ Bağıntısı
- 8. Bağıntının Tersi
- 9. Bağıntıların Bileşkesi
- 10. Sınıf Alıştırması: Altı Bağıntının Özellikleri
- 11. Geçişmeye Yeniden Bakış
- 12. Denklik Bağıntısı
- 13. Sıralama Bağıntısı
- 14. Hasse Diyagramı
- 15. Kapanış (Closure)
- 16. Warshall Algoritması
- 17. Uygulama: Kim Kiminle Konuşabilir?
- 18. Sonraki Haftalara Dair
- Örnek Sorular
- Dersin Toparlaması

## 1. Bağıntı Nedir?

Hoca derse, bugünkü konunun bağıntılar (relations) olduğunu söyleyerek başladı. Bu kavramların bir kısmı öğrencilerin daha önceden duyduğu şeylerdi. Ama Hasse diyagramı gibi daha önce görülmemiş kavramlar da gelecekti.

Elimizde iki küme olsun: $X$ ve $Y$. Bu iki kümenin kartezyen çarpımını (Cartesian product) daha önce görmüştük:

$$X \times Y = \{(x,y) \mid x \in X,\ y \in Y\}$$

Kartezyen çarpımdaki bütün elemanlar ya da bunların herhangi bir alt kümesi bir **ikili bağıntıdır** (binary relation). Yani $R \subseteq X \times Y$ ise $R$, $X$'ten $Y$'ye bir bağıntıdır. Kartezyen çarpımın tamamı da bir bağıntıdır.

Kartezyen çarpımda kaç farklı ikili yazılabileceği, iki kümenin eleman sayılarının çarpımı kadardır. Slayttaki örnekte $X = \{1,2,3\}$ ve $Y = \{a,b\}$ idi. Buradan $3 \cdot 2 = 6$ farklı ikili yazılabilir. Hocanın tek tek okuduğu bağıntı şuydu: $(1,a)$ var, $(1,b)$ var, $(2,a)$ yok, $(2,b)$ var, $(3,a)$ var, $(3,b)$ yok. Yani

$$R = \{(1,a),(1,b),(2,b),(3,a)\}$$

Bu bağıntı, 6 elemanlı kartezyen çarpımın 4 elemanlı bir alt kümesidir.

> **Ders sonrası not:** Hoca dersin başında bağıntıya birkaç kez "fonksiyon" dedi. Her fonksiyon bir bağıntıdır, ama her bağıntı fonksiyon değildir. Yukarıdaki $R$'de 1 hem $a$'ya hem $b$'ye gidiyor. Bu yüzden $R$ bir bağıntıdır ama fonksiyon değildir. Ayrıca hoca bir yerde "3 tane ikili" dedi. Okuduğu listede 4 ikili vardır.

### 1.1 Tanım Kümesi ve Değer Kümesi

Hoca bunu tahtaya iki küme çizerek hatırlattı. Soldaki $X$ kümesi, sağdaki $Y$ kümesidir. $X$'ten $Y$'ye yazılan bağıntının sol tarafına **tanım kümesi** (domain), sağ tarafına **değer kümesi** (range) denir. Hoca, Türkçelerini kullanmaya alışkın olmadığı için genelde "domain" ve "range" dediğini söyledi.

- **Tanım kümesi:** $X$'in öyle elemanlarıdır ki bir $y \in Y$ için $(x,y) \in R$ olur. Yani bağıntıdaki ikililerin birinci bileşenleridir.
- **Değer kümesi:** $Y$'nin öyle elemanlarıdır ki bir $x \in X$ için $(x,y) \in R$ olur. Yani ikililerin ikinci bileşenleridir.

Tanımdaki "bir" (for some) önemlidir. Tanım kümesindeki bir $x$'in $Y$'deki her elemanla eşleşmesi gerekmez. En az bir elemanla eşleşmesi yeter.

Hoca slayttaki bir örnek için tanım kümesinin $1$ ve $2$, değer kümesinin $a$ ve $b$ olduğunu söyledi.

<!-- BELİRSİZ: 00:12:04-00:12:20 arasında tanım ve değer kümesi sorulan bağıntının listesi altyazıda okunmuyor. Hocanın verdiği cevap ("1 ve 2", "a ve b") hangi bağıntıya ait, net değil. -->

## 2. Bağıntıların Gösterimi

Bir bağıntı üç şekilde gösterilebilir:

- **Liste olarak:** İkililer küme parantezi içinde yazılır.
- **Grafik (ok diyagramı) olarak:** Solda tanım kümesi, sağda değer kümesi çizilir. Bağıntıdaki her ikili için soldan sağa bir ok çizilir. Hocanın gösterdiği grafikteki ikililer $(1,a)$, $(1,d)$, $(2,a)$, $(2,b)$ ve $(2,c)$ idi.
- **Matris olarak:** Satırlara tanım kümesinin, sütunlara değer kümesinin elemanları yazılır. İkili bağıntıda varsa ilgili hücreye 1, yoksa 0 konur.

Hoca, grafik çizmenin zahmetli olduğunu, pratikte genelde liste gösterimini kullandığını söyledi. Ama bir özelliği kontrol eden algoritma yazılacaksa, kümeli işlemlerde en uygunu matris kullanmaktır.

Bağıntıların özellikleri neden önemlidir? Hocaya göre bazı bağıntılar belirli özelliklere sahip olacak ve bu bağıntılar üzerinde özel işlemler yapılabilecek. Bu özellikleri bir araya getiren denklik ve sıralama bağıntıları dersin ilerleyen kısmında geldi.

## 3. Yansıma Özellikleri: Reflexive, Non-reflexive, Irreflexive

Bu bölümdeki bütün özellikler, bir $A$ kümesi **üzerinde** tanımlı bağıntılar içindir. Yani tanım kümesi de değer kümesi de $A$'dır: $R \subseteq A \times A$.

### 3.1 Yansımalı (Reflexive)

Hoca "refleks yansımadır, aynada görüntüsünü almak gibi" diyerek terimi hatırlattı. Tanım:

$$R \text{ yansımalıdır} \iff \forall x \in A,\ (x,x) \in R$$

Burada "her" (for every) niceleyicisi vardır. Yani $A$'nın bütün elemanları için $(x,x)$ ikilisi bağıntıda olmalıdır.

Örnek: $A = \{a,b\}$ olsun. Yansımalı bir bağıntıda hem $(a,a)$ hem $(b,b)$ olmalıdır. Bunlardan biri eksikse bağıntı yansımalı değildir. $(a,b)$ ve $(b,a)$ ikililerinin olup olmamasının yansıma için hiçbir önemi yoktur.

### 3.2 Yansıma Algoritması

Bir bağıntının yansımalı olup olmadığını anlamak için hoca şu yolu önerdi: $A$'nın $n$ elemanı varsa bağıntı $n \times n$'lik bir $M$ matrisine yazılır. $(x,x)$ ikilileri matrisin köşegenindedir. Köşegendeki değerler toplanır. Toplam $n$'ye eşitse bağıntı yansımalıdır.

Hoca sınıfa iç içe iki döngüye ihtiyaç olup olmadığını sordu. Bir öğrenci iç döngünün $i$'ye bağlı başlaması gerektiğini söyledi. Hoca ise asıl cevabın şu olduğunu gösterdi: Köşegeni okumak için **tek döngü yeter**. Çünkü köşegen elemanı $M[i][i]$'dir ve tek bir indisle gezilir. İki döngüyle de yapılabilir, ama iki döngü kullanmak hem karmaşıklığı hem maliyeti artırır.

Hoca algoritmayı $3 \times 3$'lük bir örnekte izledi: $i = 1$ iken $M[1][1] = 1$ ise sayaç 1 olur, $i = 2$ iken sayaç 2 olur, $i = 3$ iken sayaç 3 olur, döngü biter. Sonunda sayaç $m$ ile $n$ karşılaştırılır. Köşegendeki bir değer 0 olsaydı sayaç $n$'ye ulaşmazdı ve bağıntı yansımalı olmazdı.

### 3.3 Non-reflexive ve Irreflexive

Hoca yansımalı olmayan durumu ikiye ayırdı:

- **Non-reflexive (hocanın terimi):** Bazı $x$'ler için $(x,x) \notin R$. Tanımda "bazı" (for some) vardır. Örneğin 5 elemanlı bir kümede $(a,a)$, $(b,b)$, $(e,e)$ var ama $(c,c)$ ve $(d,d)$ yok. Köşegenin bir kısmı 1, bir kısmı 0'dır.
- **Yansımasız (irreflexive):** Hiçbir $x$ için $(x,x) \in R$ değildir:

$$R \text{ yansımasızdır} \iff \forall x \in A,\ (x,x) \notin R$$

Yani köşegenin tamamı 0'dır.

Hocanın özeti: Köşegenin hepsi 1 ise yansımalı, hepsi 0 ise yansımasız, kimisi 1 kimisi 0 ise non-reflexive.

Bu ayrım algoritmayı da değiştirir. İlk başta "$m = n$ ise yansımalı, değilse non-reflexive" demek akla gelir. Ama "değilse" durumuna yansımasız bağıntılar da girer. Bu yüzden içeriye bir koşul daha eklenir: $m \ne 0$ ise non-reflexive, $m = 0$ ise yansımasız.

```text
m = 0
for i = 1 to n
    if M[i][i] == 1 then m = m + 1
if m == n        then "yansımalı (reflexive)"
else if m == 0   then "yansımasız (irreflexive)"
else             "non-reflexive"
```

> **Ders sonrası not:** "Non-reflexive" diye ayrı bir sınıf, Rosen gibi standart kaynaklarda büyük olasılıkla yoktur. Kaynaklarda bu durum "yansımalı değil" diye söylenir ve "yansımalı değil" ifadesi yansımasız bağıntıları da kapsar. Bu derste hocanın üçlü ayrımı kullanılıyor.

## 4. Simetri Özelliği ve Simetri Algoritması

### 4.1 Tanım

$A$ üzerindeki $R$ bağıntısının simetrik olması için:

$$(x,y) \in R \Rightarrow (y,x) \in R$$

Yani $(1,3)$ varsa $(3,1)$ de olmalıdır. Hoca simetrinin şu üç yüzünü ayrı ayrı vurguladı:

- $(x,y)$ varsa $(y,x)$ de olmalıdır.
- $(x,y)$ yoksa $(y,x)$ de olmamalıdır. Örneğin $(1,5)$ bağıntıda değilse $(5,1)$ de olmamalıdır. Bu ilk koşulla aynı şeyi söyler ama "çok saçma gibi gelebilir" diye ayrıca belirtildi.
- **Dikkat:** $x = y$ ise ikili simetriyi bozmaz. $(1,1)$'i $(x,y)$ olarak da $(y,x)$ olarak da okusanız aynı ikiliyi elde edersiniz. Kümede aynı eleman bir kez yazıldığı için $(1,1)$ tek başına simetrik koşulu sağlar.

Örneğin $(1,1)$, $(1,2)$, $(2,1)$ bulunan, $(2,3)$ ve $(3,2)$ bulunmayan bir bağıntı simetriktir. $(2,3)$ varken $(3,2)$ yoksa simetri sağlanmaz.

> **Hocanın vurgusu:** Bir özellik bütün ikililer için sağlanıp tek bir ikili için sağlanmıyorsa, o özellik yok demektir.

### 4.2 Matris Üzerinde Simetri

Hoca $a, b, c, d$ elemanlı bir matris çizdi: $(a,b)$ varken $(b,a)$ da var, $(a,c)$ yokken $(c,a)$ da yok, $(a,d)$ varken $(d,a)$ da var, $(b,c)$ varken $(c,b)$ da var, $(b,d)$ yokken $(d,b)$ da yok, $(c,d)$ ve $(d,c)$ yok. Köşegene bir şey yazmadı. Çünkü köşegende kaç tane 1 olursa olsun simetri tehlikeye girmez.

Simetriyi anlamanın yolu şudur: Matrisi köşegen boyunca katladığınızda üst üste gelen değerler aynı olmalıdır. Hoca bunu karşılıklı hücreleri tek tek eşleştirerek gösterdi.

### 4.3 Simetri Algoritması

Hoca algoritmayı sınıfla birlikte kurdu. Bir öğrenci, döngüleri yalnızca bir üçgen üzerinde döndürüp diğer üçgendeki karşılığına bakmayı önerdi. Dış döngü $i = 1$'den başlar. İç döngü $j = i+1$'den başlar ve $M[i][j]$ ile $M[j][i]$ karşılaştırılır.

Burada hoca bir uç nokta sorusu sordu: İç döngü $i+1$'den başlıyorsa ve dış döngü $n$'ye kadar giderse ne olur? $i = n$ olduğunda $j = n+1$'den başlar ve matrisin dışına çıkılır. Bu yüzden **dış döngü $n-1$'de bitmeli**, iç döngü $n$'ye kadar gitmelidir.

Karşılaştırmada eşitlik mi yoksa eşitsizlik mi kontrol edilmeli? Bir öğrencinin önerdiği gibi eşitsizlik kontrol edilir. Çünkü eşit olmayan tek bir çift bulunduğu an bağıntının simetrik olmadığı anlaşılır.

Hoca algoritmayı $4 \times 4$'lük matriste izledi. Önce bir hücreyi bilerek bozdu. $i = 1$ için $j = 2, 3, 4$ karşılaştırmaları eşit çıktı. $i = 2$ için $j = 3, 4$ eşit çıktı. $i = 3$, $j = 4$ için $M[3][4] = 0$ ama $M[4][3] = 1$ çıktı. Eşit olmadığı için "simetrik değil" sonucu verildi.

### 4.4 Algoritmanın Uç Noktaları

Hoca, aynı işi yapan dört farklı yazımı karşılaştırdı:

- **`exit` ile çıkmak:** Eşitsizlik bulununca "simetrik değil" yazıp çıkılır. Çıkılmazsa döngüler bittikten sonra bir de "simetriktir" yazılır ve iki çelişkili mesaj basılır. Ama `exit` ve `goto` gibi komutlar kullanmak iyi kodlama sayılmaz.
- **Bayrak (flag) tutmak:** Koşul bozulunca bayrak değiştirilir, döngüden sonra bayrağa bakılır. Program doğru çalışır, ama ilk adımda bozulma bulunsa bile döngüler boşuna dönmeye devam eder.
- **`while` kullanmak:** Koşul bozulduğu an döngü sınırına ulaşılmış gibi davranılır ve döngüden doğal olarak çıkılır. Hocanın önerdiği yol budur.

```text
i = 1, simetrik = doğru
while i <= n-1 and simetrik
    j = i + 1
    while j <= n and simetrik
        if M[i][j] != M[j][i] then simetrik = yanlış
        j = j + 1
    i = i + 1
if simetrik then "simetrik" else "simetrik değil"
```

> **Hocanın vurgusu:** Kod yazarken bu uç nokta problemlerini düşünmek önemlidir. Dört yazım da doğru cevabı verir ama hepsi ideal kodlama değildir.

Hoca ileride algoritmaların yürütme zamanının kod üzerinden nasıl hesaplandığını göreceklerini söyledi. Karmaşıklık $n$'ye bağlı yazılır ve $n$, $\log n$, $n^2$, $n^3$, $n!$ ya da $n^n$ olmasına göre "olayların rengi çok değişir".

## 5. Ters Simetri (Antisymmetry)

Hoca, ters simetrinin sık karıştırıldığını, kendisinin de bazen karıştırdığını söyledi. Tanım:

$$(x,y) \in R \text{ ve } (y,x) \in R \Rightarrow x = y$$

Yani bir ikili ve tersi aynı anda bağıntıda bulunuyorsa, bu ancak $x = y$ olduğunda kabul edilir. $(1,2)$ varken $(2,1)$ de varsa bağıntı simetrik olabilir ama ters simetrik değildir. $(1,2)$ varken $(2,1)$ yoksa bağıntı ters simetriktir.

$x = y$ durumu burada da özeldir. $(1,1)$ simetriyi bozmuyordu, ters simetriyi de bozmaz.

Hocanın iki örneği:

- $\{(1,1),(1,2)\}$: $(1,2)$ var, $(2,1)$ yok. Simetrik değildir. Ters simetriktir.
- $\{(1,1),(1,2),(2,1)\}$: $(1,2)$ varken $(2,1)$ de var. Simetriktir. $1 \ne 2$ olduğu için ters simetrik değildir.

Hoca, ters simetrinin de simetri algoritmasına küçük bir ekle kolayca kontrol edilebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Ters simetri için de üst üçgen gezilir. $i \ne j$ olan bir hücrede $M[i][j] = 1$ ve $M[j][i] = 1$ ise bağıntı ters simetrik değildir. Köşegene bakılmaz.

## 6. Geçişme (Transitivity)

### 6.1 Tanım

$$(x,y) \in R \text{ ve } (y,z) \in R \Rightarrow (x,z) \in R$$

Hoca "şu ikisi ortak, içtekiler" diyerek $y$'ye dikkat çekti. $(x,y)$'nin ikinci bileşeni ile $(y,z)$'nin birinci bileşeni aynı ise, dıştaki elemanlardan oluşan $(x,z)$ bağıntıda olmalıdır. $(x,y)$ ve $(y,z)$ var ama $(x,z)$ yoksa bağıntı geçişli değildir.

### 6.2 Kontrol Edilecek Zincir Yoksa

Hoca "enteresan olan kısım" dediği bir durumu gösterdi: Bağıntıda yalnızca $(x,y)$ varsa bağıntı geçişli midir? **Evet.** Çünkü geçişliliği kontrol etmek için $(x,y)$ ile birlikte $y$ ile başlayan bir $(y,z)$ bulunması gerekir. Böyle bir ikili yoksa $(x,z)$'yi aramaya gerek yoktur. Geçişliliği bozan bir şey yoktur.

Aynı mantık boş bağıntıya da uygulanır. Hoca, bu alanda kullanılan iki kitaptan birinin boş bağıntıyı geçişli saydığını, diğerinin saymadığını söyledi. Kendisi ve derste kullanılan kitap (Rosen) boş bağıntıyı **geçişli** kabul ediyor. Gerekçe: Boş bağıntıda ne $(x,y)$ ne $(y,z)$ vardır, geçişlilik koşulunu aramayı gerektiren bir durum yoktur.

### 6.3 Geçişliliğin Kodu

Hoca, geçişliliği kontrol eden kodun yansıma, simetri ve ters simetri kadar kolay olmadığını söyledi. Bunun için ilerleyen slaytlarda Warshall algoritması görülecekti (Bölüm 16).

## 7. Örnek: $a = b^2$ Bağıntısı

Soru: $A = \{1,2,3,4\}$ üzerinde $(a,b)$ ikililerinden oluşan ve $a = b^2$ koşulunu sağlayan $R$ bağıntısını yazın. Bu bağıntı hangi özellikleri sağlar?

Hoca ikilileri sırayla buldu:

- $a = 1$: $b^2 = 1$ olmalı. Yalnız $b = 1$ sağlar. $(1,1)$ yazılır.
- $a = 2$: Hiçbir $b \in A$ için $b^2 = 2$ olmaz.
- $a = 3$: Hiçbir $b \in A$ için $b^2 = 3$ olmaz.
- $a = 4$: $b = 2$ için $b^2 = 4$ olur. $(4,2)$ yazılır.

$$R = \{(1,1),(4,2)\}$$

Özellikler:

- **Yansımalı mı?** Hayır. $(1,1)$, $(2,2)$, $(3,3)$, $(4,4)$'ün hepsi olmalıydı.
- **Non-reflexive mi?** Evet. $(1,1)$ var ama $(2,2)$, $(3,3)$, $(4,4)$ yok.
- **Yansımasız mı?** Hayır, çünkü $(1,1)$ var.
- **Simetrik mi?** Hayır. $(4,2)$ var ama $(2,4)$ yok.
- **Ters simetrik mi?** Evet. $(1,1)$ eşitlikten dolayı sorun değil. $(4,2)$ varken $(2,4)$ yok.
- **Geçişli mi?** Evet. $(1,1)$'den sonra 1 ile başlayan başka ikili yok. $(4,2)$'den sonra 2 ile başlayan ikili yok. Kontrol edilecek zincir oluşmuyor.

Hoca bir karşı durum da gösterdi: Bağıntıda bir de $(2,1)$ olsaydı, $(4,2)$ ve $(2,1)$ zinciri $(4,1)$'i isterdi. $(4,1)$ olmadığı için geçişlilik sağlanmazdı.

Bu sonuçlar Python ile doğrulandı.

## 8. Bağıntının Tersi

$X$'ten $Y$'ye bir $R$ bağıntısı verilmiş olsun. Bunun tersi (inverse) $Y$'den $X$'e bir bağıntıdır ve $R^{-1}$ ile gösterilir:

$$R^{-1} = \{(y,x) \mid (x,y) \in R\}$$

Ters almak, her ikilide $x$ ile $y$'nin yer değiştirmesi demektir. Hocanın örneğinde $R = \{(1,a),(1,d),(2,a),(2,b),(2,c)\}$ idi:

$$R^{-1} = \{(a,1),(d,1),(a,2),(b,2),(c,2)\}$$

Grafik gösterimde tanım kümesi ile değer kümesi yer değiştirir. Hocanın deyişiyle, şekli 90 derece çevirdiğinizde ne oluşuyorsa tersi odur.

## 9. Bağıntıların Bileşkesi

### 9.1 Fonksiyon Bileşkesinden Bağıntı Bileşkesine

Hoca bileşkeyi (composition) ortaöğretimdeki fonksiyon bileşkesiyle ($f \circ g$, $g \circ f$) bağladı. Örneğin $f(x) = 2x + 1$ ve $g(x) = x^2$ ise $f \circ g$ yazılırken $g$, $f$'teki $x$'in yerine konur: $(f \circ g)(x) = 2x^2 + 1$.

Bağıntılarda değişken yoktur. "İçine koymak" işini geçişlilik mantığı yapar: Bir ikilinin ikinci elemanı, diğer ikilinin birinci elemanıyla aynıysa, dıştaki elemanlardan yeni bir ikili yazılır.

Bağıntının kuvvetleri şöyle tanımlanır:

$$R^1 = R, \qquad R^2 = R \circ R, \qquad R^3 = R^2 \circ R, \qquad R^n = R^{n-1} \circ R$$

Yani $n$. kuvveti bulmak için $(n-1)$. kuvvetin $R$ ile bileşkesi alınır.

### 9.2 Örnek: $R^2$ ve $R^3$

$$R = \{(1,1),(2,1),(3,2),(4,3)\}$$

**$R^2 = R \circ R$:** Hoca $R$'nin her ikilisini $R$'nin her ikilisiyle eşleştirip ortak iç eleman aradı:

- $(1,1)$ ile $(1,1)$: iç elemanlar 1 ve 1. $(1,1)$ yazılır.
- $(2,1)$ ile $(1,1)$: iç elemanlar 1 ve 1. $(2,1)$ yazılır.
- $(3,2)$ ile $(2,1)$: iç elemanlar 2 ve 2. $(3,1)$ yazılır.
- $(4,3)$ ile $(3,2)$: iç elemanlar 3 ve 3. $(4,2)$ yazılır.
- Diğer eşleşmelerde ortak iç eleman yoktur.

$$R^2 = \{(1,1),(2,1),(3,1),(4,2)\}$$

**$R^3 = R^2 \circ R$:**

- $(1,1)$ ile $(1,1)$: $(1,1)$.
- $(2,1)$ ile $(1,1)$: $(2,1)$.
- $(3,1)$ ile $(1,1)$: $(3,1)$.
- $(4,2)$ ile $(2,1)$: $(4,1)$.
- $(3,2)$ ve $(4,3)$ ile başka eşleşme çıkmaz.

$$R^3 = \{(1,1),(2,1),(3,1),(4,1)\}$$

$R^4$ istenirse $R^3$ ile $R$'nin bileşkesi alınır. Sonuçlar Python ile doğrulandı.

### 9.3 Bulanık Mantık Açıklaması

Hoca bileşke kavramının bulanık mantıkta (fuzzy logic) karşımıza çıktığını söyledi ve bulanık mantığı kısaca anlattı. Klasik mantık 0 ve 1 ile çalışır. Bulanık mantıkta bir şeyin olabilme değeri 0 ile 1 arasındadır, ama bu değerlerin toplamı 1 olmak zorunda değildir. Hocanın örneği: Bu hafta şehir dışına çıkma değeri hoca için 0,7, bir kişi için 0,5, bir başkası için 0,9. Üçünün toplamı 1'den büyüktür, ama her biri kendi içinde 1 ile sınırlıdır. Bu yüzden bu değerler olasılıktan çok, o olayı temsil etme "üyeliği" olarak düşünülür.

> **Ders sonrası not:** Bağıntı bileşkesi bulanık mantığa özgü değildir, genel bir matematik kavramıdır. Bulanık mantık bileşkeyi büyük olasılıkla genelleştirerek kullanır. Toplamın 1 olması koşulu klasik mantıkla değil olasılık dağılımlarıyla ilgilidir. Bulanık mantıktaki değerler üyelik derecesidir (membership degree), olasılık değildir.

## 10. Sınıf Alıştırması: Altı Bağıntının Özellikleri

Hoca katılımcı listesinden rastgele öğrenciler seçti ve $A = \{1,2,3,4\}$ üzerindeki altı bağıntının özelliklerini onlarla birlikte belirledi. Her bağıntıda sırayla yansıma, non-reflexive, yansımasızlık, simetri, ters simetri ve geçişme kontrol edildi.

### 10.1 Birinci Bağıntı

$$R_1 = \{(2,2),(2,3),(2,4),(3,2),(3,3),(3,4)\}$$

- **Yansıma:** $(1,1)$ yok, bu yüzden yansımalı değil. $(2,2)$ ve $(3,3)$ var, $(1,1)$ ve $(4,4)$ yok. Non-reflexive. Yansımasız değil.
- **Simetri:** $(2,3)$ için $(3,2)$ var. Ama $(2,4)$ için $(4,2)$ yok. Simetrik değil.
- **Ters simetri:** $(2,3)$ varken $(3,2)$ de var. Ters simetrik değil.
- **Geçişme:** Hoca her ikiliyi tek tek kontrol etti:
  - $(2,2)$ ile 2 ile başlayanlar: $(2,3)$ var, $(2,3)$ gerekir, var. $(2,4)$ var, $(2,4)$ gerekir, var.
  - $(2,3)$ ile 3 ile başlayanlar: $(3,2)$ ile $(2,2)$ gerekir, var. $(3,3)$ ile $(2,3)$ gerekir, var. $(3,4)$ ile $(2,4)$ gerekir, var.
  - $(2,4)$: 4 ile başlayan ikili yok.
  - $(3,2)$ ile 2 ile başlayanlar: $(3,2)$, $(3,3)$, $(3,4)$ gerekir, hepsi var.
  - $(3,3)$ ile 3 ile başlayanlar: $(3,2)$, $(3,3)$, $(3,4)$ gerekir, hepsi var.
  - $(3,4)$: 4 ile başlayan ikili yok.
  - Sonuç: Geçişli.

> **Hocanın vurgusu:** En fazla hata geçişlilikte yapılır, çünkü kontrol ederken bir şeyler gözden kaçabilir.

### 10.2 İkinci Bağıntı

$$R_2 = \{(1,1),(1,2),(2,1),(2,2),(3,3),(4,4)\}$$

- **Yansıma:** $(1,1)$, $(2,2)$, $(3,3)$, $(4,4)$ var. Yansımalı. Bu yüzden non-reflexive ya da yansımasız olamaz.
- **Simetri:** Simetrik.
- **Ters simetri:** $(1,2)$ ve $(2,1)$ birlikte var. Ters simetrik değil.
- **Geçişme:** $(1,1)$ ile $(1,2)$, $(1,2)$ ile $(2,1)$ ve $(2,2)$, $(2,1)$ ile $(1,1)$ ve $(1,2)$ zincirlerinin gerektirdiği ikililerin hepsi var. 3 ve 4 yalnız kendileriyle eşleşir. Geçişli.

<!-- BELİRSİZ: 01:29:15-01:29:44 arasında bağlantı koptuğu için simetri kontrolünün sözlü kısmı altyazıda yok. Sonuç ("simetrik") slayttaki işaretlerden ve Python kontrolünden alındı. -->

### 10.3 Üçüncü Bağıntı

$$R_3 = \{(2,4),(4,2)\}$$

- **Yansıma:** Köşegende hiç ikili yok. Yansımalı değil, non-reflexive değil, yansımasız.
- **Simetri:** $(2,4)$ ve $(4,2)$ birlikte var. Simetrik.
- **Ters simetri:** Bu durumda olamaz. $(2,4)$ varken $(4,2)$ olmamalıydı.
- **Geçişme:** $x = 2$, $y = 4$, $z = 2$ alınırsa $(2,4)$ ve $(4,2)$ zinciri $(2,2)$'yi ister. $(2,2)$ yok. Geçişli değil.

### 10.4 Dördüncü Bağıntı

$$R_4 = \{(1,2),(2,3),(3,4)\}$$

- **Yansıma:** Hiç $(x,x)$ yok. Yansımasız.
- **Simetri:** Hiçbir ikilinin tersi yok. Simetrik değil.
- **Ters simetri:** $(x,y)$ varken $(y,x)$ yok. Ters simetrik.
- **Geçişme:** $(1,2)$ ve $(2,3)$ zinciri $(1,3)$'ü ister. $(1,3)$ yok. Bir kez bozulduğu için diğerlerine bakmaya gerek yok. Geçişli değil.

### 10.5 Beşinci Bağıntı

$$R_5 = \{(1,1),(2,2),(3,3),(4,4)\}$$

- **Yansıma:** Yansımalı. Non-reflexive ve yansımasız değil.
- **Simetri:** Simetrik.
- **Ters simetri:** Ters simetrik. Hoca bunu "günün sorusu" olarak sordu. Bütün ikililer $(x,x)$ biçiminde olduğu için ters simetri koşulu hiçbir yerde bozulmaz.
- **Geçişme:** Geçişli.

Bu bağıntı derste önemli bir noktayı gösterdi. Dersin başında bir öğrenci "şu şu varsa şu da vardır diyebilir miyiz?" diye sormuştu. Hoca "simetrikse ters simetrik değildir" gibi genellemeler yapılamayacağını, işte bu bağıntının hem simetrik hem ters simetrik olduğunu gösterdi. Bütün elemanları $x = y$ biçiminde olan bir bağıntı iki özelliği birden sağlar.

> **Hocanın vurgusu:** Kesin yapılabilecek genelleme şudur: Bir bağıntı yansımalıysa kesinlikle non-reflexive ya da yansımasız değildir. Diğer özellikler için böyle genellemeler yapılamaz.

### 10.6 Altıncı Bağıntı

$$R_6 = \{(1,3),(1,4),(2,3),(2,4),(3,1),(3,4)\}$$

- **Yansıma:** Hiç $(x,x)$ yok. Yansımasız.
- **Simetri:** $(1,3)$ için $(3,1)$ var. Ama $(1,4)$ için $(4,1)$ yok. Simetrik değil.
- **Ters simetri:** $(1,3)$ ve $(3,1)$ birlikte var. Ters simetrik değil. Bir kez görüldüğü için diğerlerine bakmaya gerek yok.
- **Geçişme:** Öğrenci şunu buldu: $(1,3)$ ve $(3,1)$ zinciri $(1,1)$'i ister. $(1,1)$ yok. Geçişli değil.

### 10.7 Özet Tablo

| Bağıntı | Yansıma | Simetrik | Ters simetrik | Geçişli |
| :--- | :--- | :---: | :---: | :---: |
| $R_1$ | non-reflexive | hayır | hayır | evet |
| $R_2$ | yansımalı | evet | hayır | evet |
| $R_3$ | yansımasız | evet | hayır | hayır |
| $R_4$ | yansımasız | hayır | evet | hayır |
| $R_5$ | yansımalı | evet | evet | evet |
| $R_6$ | yansımasız | hayır | hayır | hayır |

Bağıntıların listesi kısa notta slayttan alınan biçimdedir. Altyazıdaki kontroller bu listelerle tutarlıdır. Bütün sonuçlar Python ile doğrulandı.

### 10.8 Dolaylı İspat Bağlantısı

Hoca alıştırmadan sonra ispat yöntemlerine geri döndü. Dolaylı ispatta (indirect proof) $p \Rightarrow q$'yu göstermek yerine $\neg q \Rightarrow \neg p$ gösterilir. Bir şeyin olmadığını göstermek, her koşulda olduğunu göstermekten daha kolay olabilir. Bağıntı özelliklerinde de böyledir: Bir özelliğin bütün ikililer için sağlandığını göstermek için hepsine bakmak gerekir, ama sağlanmadığını göstermek için tek bir karşı örnek yeter.

> **Hocanın vurgusu:** Bir özelliği bozan tek bir ikili gördüyseniz diğerlerini kontrol etmenize gerek yoktur.

## 11. Geçişmeye Yeniden Bakış

Bir öğrenci geçişliliği anlamadığını söyleyince hoca konuyu yeniden anlattı.

- Bağıntıda yalnız $(x,y)$ varsa geçişlidir.
- Boş bağıntı geçişlidir. Hiçbir şey kontrol edilmez.
- $(x,y)$ ve $(y,z)$ birlikte varsa, yani "içler uygunsa", $(x,z)$ aranır. Varsa bu zincir geçişliliği bozmaz. Yoksa bağıntı geçişli değildir.
- Bir zincir için bile koşul sağlanmıyorsa bağıntının tamamı geçişli değildir.

Hocanın örneği:

$$\{(1,1),(1,3),(3,4),(1,4)\}$$

- $(1,1)$ ile 1 ile başlayan $(1,3)$: $(1,3)$ gerekir, var. $(1,4)$ ile $(1,4)$ gerekir, var.
- $(1,3)$ ile 3 ile başlayan $(3,4)$: $(1,4)$ gerekir, var.
- $(3,4)$ ve $(1,4)$: 4 ile başlayan ikili yok.
- Sonuç: Geçişli.

Sonra hoca bağıntıya $(4,2)$ ekledi. Şimdi $(1,4)$ ve $(4,2)$ zinciri $(1,2)$'yi ister. $(1,2)$ yok. Bağıntı artık geçişli değildir.

### 11.1 Soru: Yansımalı ve Simetrik Her Bağıntı Geçişli midir?

**Soru:** Yansımalı ve simetrik olan her bağıntı geçişli midir? Kendi denediğim birkaç örnekte hep geçişli çıktı.

**Cevap:** Hoca böyle bir genelleme yapılamayacağını söyledi. Bağıntı verilirse onun özelliklerine bakılabilir. Kendisine böyle bir bağıntı verilse, onu bozacak bir örnek bulabileceğini söyledi.

> **Ders sonrası not:** Kesin cevap "hayır"dır. $\{1,2,3\}$ üzerinde $\{(1,1),(2,2),(3,3),(1,2),(2,1),(2,3),(3,2)\}$ yansımalı ve simetriktir. Ama $(1,2)$ ve $(2,3)$ zinciri $(1,3)$'ü ister ve $(1,3)$ yoktur. Bu bağıntı geçişli değildir. Python ile doğrulandı.

## 12. Denklik Bağıntısı

### 12.1 Tanım

Hoca, gördüğümüz özelliklerin bazen bir araya gelerek tek bir isim aldığını söyledi. $X$ kümesi üzerindeki bir $R$ bağıntısı **yansımalı, simetrik ve geçişli** ise buna **denklik bağıntısı** (equivalence relation) denir. Hoca gösterim şeklinin o kadar önemli olmadığını, üç özelliğin birlikte bulunmasının önemli olduğunu söyledi.

### 12.2 Örnek: $\{1,2\}$ Üzerinde Denklik Bağıntısı ve Grafı

Soru: $A = \{1,2\}$ üzerinde bir denklik bağıntısı yazın ve grafını çizin.

Hoca iki düğüm çizdi: 1 ve 2. Sonra özellikleri tek tek sağladı:

- **Yansımalı:** Her düğümde kendine dönen bir ok olmalı. $(1,1)$ ve $(2,2)$ eklenir.
- **Simetrik:** 1'den 2'ye bir yol varsa 2'den 1'e de olmalı. $(1,2)$ ve $(2,1)$ eklenir.
- **Geçişli:** $(1,2)$ ve $(2,1)$ zinciri $(1,1)$'i, $(2,1)$ ve $(1,2)$ zinciri $(2,2)$'yi ister. Bunlar yansımadan dolayı zaten var.

$$R = \{(1,1),(2,2),(1,2),(2,1)\}$$

Eleman sayısı arttıkça bu üç özelliği sağlayan farklı bağıntılar yazılabilir. Hangi ikililerin seçildiğine göre her kişinin yazdığı bağıntı farklı olabilir.

### 12.3 Örnek: Yalnız Köşegen

$\{1,2,3,4,5\}$ üzerinde

$$R = \{(1,1),(2,2),(3,3),(4,4),(5,5)\}$$

- Yansımalı: Bütün $(x,x)$ ikilileri var.
- Simetrik: $(x,x)$ ikilileri simetriyi bozmaz.
- Geçişli: 1 ile başlayan başka ikili yok, 2 ile başlayan başka ikili yok, vb. Zincir oluşmuyor.

Bu yüzden bir denklik bağıntısıdır. Grafında beş düğüm vardır ve her düğümde yalnız kendine dönen bir ok bulunur. Hoca, bazı yapılara genel bir isim verilmesini "siz bilgisayar mühendisliği ikinci sınıfsınız" benzetmesiyle açıkladı: Ortak özellikleri taşıyanlar bir isim altında toplanır.

**Soru:** Bu bağıntı ters simetrik de, bu önemli değil mi?

**Cevap:** Önemli değil. Denklik bağıntısı için yalnız yansıma, simetri ve geçişmeye bakılır.

### 12.4 Örnek: $\{1,2,3\}$ Üzerindeki Tam Bağıntı

$\{1,2,3\}$ üzerinde bütün ikililerden oluşan bağıntı:

$$R = \{(1,1),(2,2),(3,3),(1,2),(2,1),(1,3),(3,1),(2,3),(3,2)\}$$

Yansımalı, simetrik ve geçişlidir. Ters simetrik değildir, çünkü $(1,2)$ varken $(2,1)$, $(1,3)$ varken $(3,1)$, $(2,3)$ varken $(3,2)$ da var. Bu bir denklik bağıntısıdır.

Slaytta bir ikili $(3.2)$ diye yazılmıştı. Hoca bunun virgül olması gerektiğini, "3.2 diye bir reel sayı" olmadığını belirtti.

Hoca, slayttaki tabloda ters simetri sütununun da bulunduğunu ama denklik bağıntısı için kontrol edilmesine gerek olmadığını söyledi. Bazen bir bağıntı yansımalı, simetrik, geçişli ve ters simetrik olabilir. Ters simetrik olduğu için "denklik bağıntısı değildir" denemez. Denklik bağıntısı için ilk üç özelliğin varlığı yeterlidir.

### 12.5 Eski Vize Sorusu: $x - y = 5$

Soru: $X$ tam sayılardan oluşan bir küme olsun. $X$ üzerinde $x - y = 5$ koşulunu sağlayan $(x,y)$ ikililerinden oluşan bir $R$ bağıntısı yazın. $R$ bir denklik bağıntısı mıdır?

Hoca önce pozitif tam sayılarla düşündü. $(6,1)$ yazılabilir: $6 - 1 = 5$. $(7,2)$ yazılabilir: $7 - 2 = 5$. Böyle sonsuz sayıda ikili yazılabilir.

Ama yansıma koşulu hiçbir zaman sağlanamaz. Çünkü $(x,x)$ için $x - x = 0 \ne 5$'tir. Negatif sayılar da eklenirse sonuç değişmez. Örneğin $(1,-4)$ için $1 - (-4) = 5$'tir, ama yine hiçbir $(x,x)$ yazılamaz. Yansımalı olamadığı için bu bağıntı **denklik bağıntısı değildir**.

Hoca bir de dar bir durum gösterdi: Küme $\{1,6\}$ ve bağıntı $\{(6,1)\}$ olsun.

- Yansımasızdır, çünkü $(1,1)$ ve $(6,6)$ yok.
- Ters simetriktir, çünkü $(1,6)$ yok.
- Geçişlidir, çünkü 1 ile başlayan bir ikili yok, kontrol edilecek zincir oluşmuyor.
- Yansımalı olmadığı için denklik bağıntısı değildir.

### 12.6 Örnek: $X = \{1,2,3,4,5,6\}$

$$R = \{(1,1),(1,3),(1,5),(3,1),(3,3),(3,5),(5,1),(5,3),(5,5),(2,2),(2,6),(6,2),(6,6),(4,4)\}$$

- **Yansımalı:** $(1,1)$'den $(6,6)$'ya kadar bütün köşegen ikilileri var.
- **Simetrik:** Bir öğrencinin saydığı gibi $(1,3)$-$(3,1)$, $(1,5)$-$(5,1)$, $(3,5)$-$(5,3)$, $(2,6)$-$(6,2)$ çiftleri var.
- **Geçişli:** Hoca 1, 3, 5 ile başlayan ikilileri ve 2, 6 ile başlayan ikilileri tek tek kontrol etti. Bütün zincirlerin gerektirdiği ikililer var.

Bu bağıntı bir denklik bağıntısıdır. Python ile doğrulandı.

**Soru:** $(5,5)$ ve $(2,2)$ varken geçişlilik için $(5,2)$'nin de olması gerekmiyor mu?

**Cevap:** Hayır. $(5,5)$ ile $(2,2)$ arasında ortak iç eleman yoktur. Birincinin ikinci elemanı 5, ikincinin birinci elemanı 2'dir. Bu iki ikiliyle geçişlilik kontrol edilemez.

> **Ek bilgi (derste anlatılmadı):** Bir denklik bağıntısı kümeyi birbirine bağlı eleman gruplarına ayırır. Bu gruplara denklik sınıfları (equivalence classes) denir. Bu örnekte sınıflar $\{1,3,5\}$, $\{2,6\}$ ve $\{4\}$'tür. Her sınıfın içindeki bütün elemanlar birbiriyle bağıntılıdır, farklı sınıflardaki elemanlar bağıntılı değildir.

## 13. Sıralama Bağıntısı

### 13.1 Tanım

$X$ üzerindeki bir $R$ bağıntısı **yansımalı, ters simetrik ve geçişli** ise buna **sıralama bağıntısı** (kısmi sıralama, partial order relation) denir. Hoca, sıralama bağıntısıyla birlikte Helmut Hasse'nin geliştirdiği Hasse diyagramlarının karşımıza çıktığını söyledi.

> **Ders sonrası not:** Hoca tanımı verdikten sonra "sıralama bağıntısında transitivliğin yerine antisimetriklik" dedi. Doğrusu: Denklik bağıntısındaki **simetrinin** yerine ters simetri gelir. Geçişlilik iki bağıntıda da vardır. Hoca derste daha sonra doğru üçlüyü tekrarladı.

### 13.2 Eski Vize Sorusu: "$x$ divides $y$"

Soru: $A = \{1,2,3,4\}$ üzerinde "$x$ divides $y$" koşuluyla bir $R$ bağıntısı yazın. Bu bir sıralama bağıntısı mıdır?

Hoca bu soruyu bir yıl İngilizce sorduğunu, ertesi yıl Türkçeye "böler" diye çevirdiğini, ikisinde de itiraz geldiğini anlattı. "$x$ divides $y$", "$x$, $y$'yi böler" demektir. Yani $y / x$ bir tam sayıdır. Sınıfla birlikte ikililer yazıldı:

$$R = \{(1,1),(1,2),(1,3),(1,4),(2,2),(2,4),(3,3),(4,4)\}$$

> **Hocanın vurgusu:** Öğrencilerin sık yaptığı hata, "4 bölü 1" diye düşünüp $(1,4)$ yerine $(4,1)$ yazmaktır. Soruda "$y$ divides $x$" deseydi bu doğru olurdu. "$x$ divides $y$" dendiği için yanlıştır ve bütün sonuçları değiştirir. Hoca benzer soruların yine geleceğini söyledi.

Özellikler:

- **Yansımalı:** $(1,1)$, $(2,2)$, $(3,3)$, $(4,4)$ var.
- **Ters simetrik:** $(1,2)$ varken $(2,1)$ olamaz, çünkü 1, 2'yi tam bölüyorsa 2, 1'i tam bölmez. Aynı şekilde $(3,1)$, $(4,1)$, $(4,2)$ da yoktur.
- **Geçişli:** Hoca 1, 2, 3 ve 4 ile başlayan zincirleri hızla kontrol etti. Gerekli ikililerin hepsi var.

Bu bağıntı bir sıralama bağıntısıdır. Python ile doğrulandı.

## 14. Hasse Diyagramı

### 14.1 Fikir

Bir graf sıralama bağıntısının özelliklerini sağlıyorsa, onun sadeleştirilmiş hâline Hasse diyagramı denir. Hoca "diyagram", "çizelge" ve "graf" kelimelerinin üçünün de kullanıldığını söyledi. Bir grafın Hasse diyagramı olduğunu biliyorsanız, üzerinde yansıma, ters simetri ve geçişme özelliklerinin bulunduğunu da bilirsiniz. Diyagramda görünmeseler bile bu özellikler varmış gibi düşünülür.

### 14.2 Örnek: $a \le b$

$X = \{1,2,3,4\}$ üzerinde $a \le b$ koşuluyla bağıntı yazılır. Eşitlikten $(1,1)$, $(2,2)$, $(3,3)$, $(4,4)$ gelir. Küçüklükten $(1,2)$, $(1,3)$, $(1,4)$, $(2,3)$, $(2,4)$, $(3,4)$ gelir:

$$R = \{(1,1),(1,2),(1,3),(1,4),(2,2),(2,3),(2,4),(3,3),(3,4),(4,4)\}$$

> **Ders sonrası not:** Hoca ikilileri sayarken "1,3; 1,4; 2,3; 2,4; 3,4" dedi ve $(1,2)$'yi atladı. $(1,2)$ de bağıntıdadır. Hoca geçişlilik kontrolünde ve grafta $(1,2)$'yi kullandı.

Özellikler:

- Yansımalıdır, çünkü eşitlikten bütün $(x,x)$ ikilileri yazıldı.
- Ters simetriktir, çünkü $a < b$ olan ikililer yazıldığında $b < a$ olanlar yazılamaz.
- Geçişlidir. Hoca 1, 2 ve 3 ile başlayan zincirleri kontrol etti.

Bu yüzden bir sıralama bağıntısıdır.

### 14.3 Graftan Hasse Diyagramına

Hoca önce bağıntının tam grafını çizdi: dört düğüm, her düğümde kendine dönen ok ve $1 \to 2$, $1 \to 3$, $1 \to 4$, $2 \to 3$, $2 \to 4$, $3 \to 4$ okları. Sonra bu grafı iki adımda sadeleştirdi:

- **1. adım: Yansıma oklarını sil.** $(1,1)$, $(2,2)$, $(3,3)$, $(4,4)$ döngüleri kaldırılır.
- **2. adım: Geçişmeden gelen okları sil.**
  - $1 \to 2$ ve $2 \to 3$ var. Geçişmenin gerektirdiği $1 \to 3$ silinir.
  - $2 \to 3$ ve $3 \to 4$ var. Geçişmenin gerektirdiği $2 \to 4$ silinir.
  - $1 \to 3$ ve $3 \to 4$ vardı. Geçişmenin gerektirdiği $1 \to 4$ silinir.

Geriye kalan Hasse diyagramı:

$$1 \to 2 \to 3 \to 4$$

Bu, Python ile hesaplanan örtü (cover) ilişkisiyle aynıdır: $\{(1,2),(2,3),(3,4)\}$.

### 14.4 Hasse Diyagramından Grafa Dönüş

Hoca işlemin geri de yapılabileceğini gösterdi:

- Geçişme okları geri eklenir: $1 \to 2$ ve $2 \to 3$'ten $1 \to 3$; $1 \to 3$ ve $3 \to 4$'ten $1 \to 4$; $2 \to 3$ ve $3 \to 4$'ten $2 \to 4$.
- Yansıma döngüleri geri eklenir: $(1,1)$, $(2,2)$, $(3,3)$, $(4,4)$.

Sonuç ilk baştaki grafın aynısıdır.

Neden Hasse diyagramı kullanılır? Onlarca elemanlı bir kümede bağıntının grafı çok karışık olabilir. Hasse diyagramı bu grafı sade ve "pür" hâliyle gösterir. Hangi özelliklerin çıkarıldığı bilindiği için istenirse geri eklenebilir ya da eklenmeden varmış gibi düşünülebilir.

### 14.5 Ara Özet

Bir öğrenci bağlantı kesildiği için son söylenenlerin tekrarını istedi. Hoca şöyle özetledi:

- Yansımalı + simetrik + geçişli: **denklik bağıntısı**.
- Yansımalı + ters simetrik + geçişli: **sıralama bağıntısı**.
- Sıralama bağıntısının grafından yansıma ve geçişme okları kaldırılırsa: **Hasse diyagramı**.

## 15. Kapanış (Closure)

Hoca kapanışı (closure) şöyle tanımladı: Bir bağıntıda bir özellik yoksa, bağıntıyı o özelliği sağlayacak hâle getirmek. Bunun için gereken ikililer bağıntıya eklenir.

### 15.1 Yansıma Kapanışı

Küme $\{1,2,3\}$, bağıntı $\{(1,1),(3,3)\}$ olsun. $(2,2)$ eksik olduğu için bağıntı yansımalı değildir. Yansımalı yapmak çok kolaydır: $(2,2)$ eklenir.

$$\{(1,1),(2,2),(3,3)\}$$

Genel olarak, $x = y$ olan bütün eksik ikililer eklenir.

### 15.2 Simetri Kapanışı

Bağıntı $\{(1,2),(2,1),(3,1)\}$ olsun. $(3,1)$ var ama $(1,3)$ yok, bu yüzden simetrik değildir. Olmayan tersi eklenir:

$$\{(1,2),(2,1),(3,1),(1,3)\}$$

Bu bağıntı simetriktir.

### 15.3 Geçişme Kapanışı

Geçişme kapanışında zincirlerin istediği $(x,z)$ ikilileri eklenir. Ama eklenen her ikili yeni zincirler oluşturabilir. Hoca $(1,2)$, $(2,4)$, $(4,3)$ gibi ikililerle başlayıp önce $(1,4)$ ve $(2,3)$ gibi ikilileri eklemeyi gösterdi. Ardından 3 ile başlayan bir $(3,2)$ ikilisi ekleyince yeni zincirlerin $(4,2)$ ve $(2,2)$ gibi ikilileri de istediğini anlattı.

<!-- BELİRSİZ: 02:31:23-02:32:18 arasında geçişme kapanışı örneğinin başlangıç bağıntısı ve eklenen ikililerin tam listesi altyazıdan net çıkmıyor. -->

Hoca, bunu insan olarak gözle görüp yapabildiğini, ama bilgisayara yaptırmanın yansıma ve simetri kadar kolay olmadığını, algoritmanın "biraz karışık" olduğunu söyledi. Bunun için Warshall algoritması kullanılır.

## 16. Warshall Algoritması

### 16.1 Arka Plan

Hoca, bir bağıntıyı geçişli hâle getirmenin en iyi yolunu bulmak için bir yarışma düzenlendiğini ve Stephen Warshall'ın algoritmasıyla birinci olduğunu anlattı. Artık bir bağıntıda geçişlilik yoksa ve geçişli yapılmak isteniyorsa Warshall algoritması kullanılır.

> **Ders sonrası not:** Altyazıda isim "Marshall/Varshal" diye geçiyor; doğrusu Stephen Warshall'dır. Algoritma büyük olasılıkla 1962'de yayımlandı. Aynı algoritmayı Bernard Roy da büyük olasılıkla 1959'da bağımsız olarak yayımlamıştır. Hocanın anlattığı yarışma hikâyesi kaynaklarda doğrulanamadı.

### 16.2 Örnek Bağıntı

$$R = \{(b,a),(b,c),(c,a),(c,d),(d,c),(a,d)\}$$

Grafında $b \to a$, $b \to c$, $c \to a$, $c \to d$, $d \to c$ ve $a \to d$ okları vardır.

Bu bağıntı geçişli midir? Hoca grafa bakarak geçişli olmadığını gösterdi. Örneğin $b \to a$ ve $a \to d$ var, ama $b \to d$ yok. İnsan olarak böyle bakıp eksikleri tek tek eklemek mümkündür. Bilgisayarda ise Warshall algoritması kullanılır.

> **Ders sonrası not:** Hoca bir yerde "D'den C'ye var ama C'den A'ya giden direkt bir yol yok" dedi. $c \to a$ başlangıç bağıntısında vardır. Doğrusu: $d \to c$ ve $c \to a$ zinciri $d \to a$'yı ister ve $d \to a$ yoktur.

### 16.3 Matris Gösterimi

Algoritmadan önce graf matrise çevrilir. Satırlar ve sütunlar $a, b, c, d$ sırasındadır. Başlangıç matrisine $W_0$ denir. $W$ harfi Warshall'dan gelir.

$$W_0 = \begin{pmatrix} 0 & 0 & 0 & 1 \\ 1 & 0 & 1 & 0 \\ 1 & 0 & 0 & 1 \\ 0 & 0 & 1 & 0 \end{pmatrix}$$

- $a$ satırı: yalnız $a \to d$.
- $b$ satırı: $b \to a$ ve $b \to c$.
- $c$ satırı: $c \to a$ ve $c \to d$.
- $d$ satırı: $d \to c$.

### 16.4 Algoritma

```text
procedure warshall(M_R)
    W = M_R
    for k = 1 to n
        for i = 1 to n
            for j = 1 to n
                W[i][j] = W[i][j] OR (W[i][k] AND W[k][j])
    return W
```

Üç iç içe döngü vardır. Bütün işi tek satır yapar: $W[i][k]$ ile $W[k][j]$ VE'lenir, sonuç $W[i][j]$ ile VEYA'lanır ve matrise yazılır. Yani $i \to k$ ve $k \to j$ varsa $i \to j$ eklenir. İşlem sayısı $n \times n \times n = n^3$'tür. Hoca bunun "birazcık işlem maliyeti" olduğunu söyledi.

### 16.5 Adım Adım Çalıştırma

Hoca $k = 1$, $i = 1$ için ilk birkaç adımı tahtada izledi. $j = 1$ iken $W[1][1] = 0$ ve $W[1][1] = 0$ olduğu için VE'nin sonucu 0'dır, $W[1][1]$ ile VEYA'lanınca yine 0 kalır. $j = 2$ iken $W[1][1] = 0$ olduğu için sonuç yine 0'dır. Değişikliğin olduğu yerlere kadar tek tek gitmek uzun sürdüğü için hoca sonraki adımları sonuç matrisleri üzerinden gösterdi.

Her $k$ değeri için dış döngünün bir turu tamamlanınca elde edilen matrisler şunlardır (satırlar $a, b, c, d$):

| Adım | $a$ satırı | $b$ satırı | $c$ satırı | $d$ satırı | Eklenen |
| :--- | :---: | :---: | :---: | :---: | :--- |
| $W_0$ | 0001 | 1010 | 1001 | 0010 | |
| $W_1$ ($k = a$) | 0001 | 1011 | 1001 | 0010 | $(b,d)$ |
| $W_2$ ($k = b$) | 0001 | 1011 | 1001 | 0010 | yok |
| $W_3$ ($k = c$) | 0001 | 1011 | 1001 | 1011 | $(d,a)$, $(d,d)$ |
| $W_4$ ($k = d$) | 1011 | 1011 | 1011 | 1011 | $(a,a)$, $(a,c)$, $(c,c)$ |

Açıklamalar:

- $k = a$: $b \to a$ ve $a \to d$ olduğu için $b \to d$ eklenir.
- $k = b$: Hiçbir düğümden $b$'ye ok yoktur. Bu yüzden değişiklik olmaz. Hoca da bu adımda değişiklik olmadığını gösterdi.
- $k = c$: $d \to c$ ile $c \to a$'dan $d \to a$, $d \to c$ ile $c \to d$'den $d \to d$ eklenir.
- $k = d$: $a \to d$ ile $d \to a$'dan $a \to a$, $a \to d$ ile $d \to c$'den $a \to c$, $c \to d$ ile $d \to c$'den $c \to c$ eklenir.

Son matris $W_4$, bağıntının geçişme kapanışıdır. Ara matrisler ve sonuç Python ile doğrulandı.

Hoca sonuç grafında eklenen okları kontrol etti. $b \to a$ ve $a \to c$ olduğu için $b \to c$ gerekir. Bu ok başlangıçta zaten vardı.

> **Ders sonrası not:** Hoca eklenen okları anlatırken "A'dan D'ye var, D'den de C'ye varsa C'den A'ya olması lazım, C'den A buraya eklenmiş" dedi. Doğrusu: $a \to d$ ve $d \to c$ zinciri $a \to c$'yi ister ve eklenen ok $a \to c$'dir. $c \to a$ başlangıç bağıntısında zaten vardı.

<!-- BELİRSİZ: 02:36:19-02:38:47 arasında hocanın ekran paylaşımı ve bağlantısı koptu. Ara matrislerin slayttaki görünümü altyazıda okunmuyor; tablo kısa nottaki slayt matrisleri ve Python hesabıyla kuruldu. -->

### 16.6 Neden Gerekli?

Hoca geçişme kapanışının gerçek hayattaki karşılığını yol ve trafik planlamasıyla anlattı. Bir noktadan bir noktaya, oradan başka bir noktaya gidiliyor olsun. Ara yollardan birinde sorun çıkınca sürücülere alternatif bir yol önermek gerekir. Belki tek yönlü bir yol geçici olarak çift yönlü yapılacaktır. Trafik bir grafa dönüştürülür ve geçişlilik koşulunu sağlayan kenarlara bakılır. Aynı mantık ağ (network) bağlantılarında da geçerlidir: İki nokta arasındaki bağlantıda sorun olursa $A$ noktası ile $C$ noktası başka bir yoldan haberleştirilmelidir.

Hoca, sokaktaki insanın da "buradan buraya gittim, bu yol kapanırsa başka bir yol bulmam gerekir" diye düşündüğünü, ama bunun arkasında geçişlilik teorisi olduğunu bilmediğini söyledi. Öğrenilen kavramlar havada kalmamalı, gerçek problemlerin çözümünde kullanılır.

## 17. Uygulama: Kim Kiminle Konuşabilir?

Slaydın başlığı "yansıma ve simetri özelliklerini taşıyan küme içi bağıntılar" idi. Farklı ülkelerden 6 kişi ($a_1, \ldots, a_6$) ve 5 dil ($b_1, \ldots, b_5$) vardır. Hoca, her kişiye hangi dilleri konuştuğunu sorduğumuzu düşünün dedi. Örneğin $a_1$ İngilizce ve Fransızca konuşuyor.

Kişileri satıra, dilleri sütuna yazınca "kim hangi dili konuşuyor" matrisi $M_\alpha$ elde edilir (kısa nottaki slayt matrisi):

| | $b_1$ | $b_2$ | $b_3$ | $b_4$ | $b_5$ |
| :--- | :---: | :---: | :---: | :---: | :---: |
| $a_1$ | 1 | 1 | 0 | 0 | 0 |
| $a_2$ | 1 | 1 | 0 | 0 | 0 |
| $a_3$ | 0 | 0 | 1 | 0 | 1 |
| $a_4$ | 1 | 0 | 1 | 1 | 0 |
| $a_5$ | 0 | 0 | 0 | 1 | 0 |
| $a_6$ | 0 | 1 | 1 | 0 | 0 |

"Hangi dil kimler tarafından konuşuluyor" matrisi bunun satır ve sütunlarının yer değiştirmiş hâlidir. Hoca buna $M_\alpha^{-1}$ dedi.

Soru şudur: Kim kiminle, beden dilini kullanmadan, ortak bir dilde konuşabilir? Hocanın cevabı: İki matris çarpılır. Satır ve sütunu çevir, iki matrisi çarp, cevap hazır.

> **Ders sonrası not:** Burada "matrisin tersi" denen şey ters matris değil, devrik (transpose) matristir: $M_\alpha^T$. Çarpım da Boolean çarpımdır: Toplama yerine VEYA, çarpma yerine VE kullanılır. Sonuç matrisinde $(i,j)$ hücresi 1 ise $a_i$ ile $a_j$ en az bir ortak dil konuşur.

Sonuç matrisi ($M_\alpha \cdot M_\alpha^T$, Boolean, Python ile hesaplandı):

| | $a_1$ | $a_2$ | $a_3$ | $a_4$ | $a_5$ | $a_6$ |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| $a_1$ | 1 | 1 | 0 | 1 | 0 | 1 |
| $a_2$ | 1 | 1 | 0 | 1 | 0 | 1 |
| $a_3$ | 0 | 0 | 1 | 1 | 0 | 1 |
| $a_4$ | 1 | 1 | 1 | 1 | 1 | 1 |
| $a_5$ | 0 | 0 | 0 | 1 | 1 | 0 |
| $a_6$ | 1 | 1 | 1 | 1 | 0 | 1 |

Hoca köşegenin pek önemi olmadığını söyledi; herkes kendisiyle konuşur. Derste okunan sonuçlar tabloyla aynıdır: $a_1$; $a_2$, $a_4$ ve $a_6$ ile konuşabilir. $a_2$; $a_1$, $a_4$ ve $a_6$ ile konuşabilir.

Bu bağıntı yansımalı ve simetriktir. Slaydın başlığı bu yüzden "yansıma ve simetri özelliklerini taşıyan" bağıntılardır.

Hoca, bu soruya algoritma olarak sıfırdan yaklaşmanın zor olabileceğini, ama bağıntı ve matris bilgisiyle problemin "bir kerede pat diye" çözüldüğünü vurguladı. Öğrendiğimiz bilgileri nerede kullanabileceğimizi hep düşünmeliyiz.

## 18. Sonraki Haftalara Dair

Hoca bu bölümün slaytlarının bitmediğini, gelecek hafta bölümü tamamlayıp yeni bölüme geçeceklerini söyledi. Ders sonunda bir öğrenci Warshall algoritması anlatılırken bağlantı kesildiği için konuyu tam anlayamadığını söyledi. Hoca hatırlatılırsa gelecek hafta hızlıca üzerinden geçeceğini söyledi.

Konu planı:

- Sayı teorisi bölümü (öğrencilere verilen içerikte Bölüm 5) şimdilik atlanacak. Zaman kalırsa son haftaya alınacak.
- Sıradaki bölüm çok slaytlı ve farklı konular içeren bir bölüm.
- Daha sonra ağaçlar, çizgeler (graphs) ve sonlu durum makineleri (finite state machines) gelecek.
- Algoritmalar bölümünde algoritma karmaşıklığı daha ayrıntılı ele alınacak.

## Örnek Sorular

Bu derste hazır kare yoktur. Aşağıdaki sorular derste sözlü olarak sorulan ya da sınıfla birlikte çözülen sorulardır.

### Soru 1 (derste sözlü, 00:17:58)

Bir bağıntının yansımalı olup olmadığını matris üzerinden kontrol etmek için iç içe iki döngüye ihtiyaç var mıdır?

> **Çözüm:** Hayır. Yansıma için yalnız köşegen elemanları $M[i][i]$ okunur. Tek döngüyle köşegendeki 1'ler sayılır. Sayı $n$ ise yansımalı, 0 ise yansımasız, arada ise non-reflexive'dir. İki döngü de doğru sonuç verir ama karmaşıklığı ve maliyeti gereksiz yere artırır.

### Soru 2 (derste sözlü, 00:30:19)

Bir bağıntının simetrik olup olmadığını kontrol eden algoritmayı nasıl yazarsınız? İç döngü $j = i + 1$'den başlıyorsa döngü sınırları ne olmalıdır?

> **Çözüm:** Matrisin yalnız üst üçgeni gezilir ve $M[i][j] \ne M[j][i]$ olan bir hücre aranır. İç döngü $j = i+1$'den $n$'ye kadar gider. Dış döngü $n - 1$'de bitmelidir, yoksa $i = n$ iken $j = n + 1$ olur ve matrisin dışına çıkılır. Eşitsizlik bulunduğu anda döngüden çıkmak için `exit` yerine `while` döngüsü ve bir koşul değişkeni kullanılır (Bölüm 4.3-4.4).

### Soru 3 (derste sözlü, 00:47:20)

$A = \{1,2,3,4\}$ üzerinde $a = b^2$ koşuluyla $(a,b)$ ikililerinden oluşan bağıntıyı yazın. Hangi özellikleri sağlar?

> **Çözüm:** $R = \{(1,1),(4,2)\}$. Non-reflexive (yansımalı da yansımasız da değil), simetrik değil, ters simetrik, geçişli (Bölüm 7).

### Soru 4 (derste sözlü, 01:10:55)

Yansımalı ve simetrik olan her bağıntı geçişli midir?

> **Çözüm (derste verilmedi):** Hayır. Hoca derste genelleme yapılamayacağını söyledi ama karşı örnek vermedi. $\{1,2,3\}$ üzerinde $\{(1,1),(2,2),(3,3),(1,2),(2,1),(2,3),(3,2)\}$ yansımalı ve simetriktir. $(1,2)$ ve $(2,3)$ zinciri $(1,3)$'ü ister, $(1,3)$ yoktur. Bağıntı geçişli değildir. Python ile doğrulandı.

### Soru 5 (derste sözlü, 01:21:12)

$A = \{1,2,3,4\}$ üzerindeki şu bağıntıların yansıma, simetri, ters simetri ve geçişme özelliklerini belirleyin:

- $R_1 = \{(2,2),(2,3),(2,4),(3,2),(3,3),(3,4)\}$
- $R_2 = \{(1,1),(1,2),(2,1),(2,2),(3,3),(4,4)\}$
- $R_3 = \{(2,4),(4,2)\}$
- $R_4 = \{(1,2),(2,3),(3,4)\}$
- $R_5 = \{(1,1),(2,2),(3,3),(4,4)\}$
- $R_6 = \{(1,3),(1,4),(2,3),(2,4),(3,1),(3,4)\}$

> **Çözüm:** Derste öğrencilerle birlikte çözüldü. Sonuçlar Bölüm 10.7'deki tablodadır. $R_1$: non-reflexive, geçişli. $R_2$: yansımalı, simetrik, geçişli. $R_3$: yansımasız, simetrik, geçişli değil ($(2,2)$ eksik). $R_4$: yansımasız, ters simetrik, geçişli değil ($(1,3)$ eksik). $R_5$: yansımalı, simetrik, ters simetrik, geçişli. $R_6$: yansımasız, hiçbir diğer özelliği yok ($(1,1)$ eksik olduğu için geçişli değil).

### Soru 6 (derste sözlü, 01:42:22)

$\{(1,1),(1,3),(3,4),(1,4)\}$ geçişli midir? Bağıntıya $(4,2)$ eklenirse ne olur?

> **Çözüm:** İlk bağıntı geçişlidir. $(1,1)$-$(1,3)$, $(1,1)$-$(1,4)$ ve $(1,3)$-$(3,4)$ zincirlerinin istediği $(1,3)$, $(1,4)$, $(1,4)$ ikilileri vardır. $(4,2)$ eklenince $(1,4)$ ve $(4,2)$ zinciri $(1,2)$'yi ister. $(1,2)$ yoktur, bağıntı geçişli olmaz.

### Soru 7 (derste sözlü, 01:45:43)

$A = \{1,2\}$ üzerinde bir denklik bağıntısı yazın ve grafını çizin.

> **Çözüm:** $R = \{(1,1),(2,2),(1,2),(2,1)\}$. Grafta iki düğüm vardır, her düğümde kendine dönen bir ok ve iki düğüm arasında iki yönlü ok bulunur (Bölüm 12.2).

### Soru 8 (derste sözlü, 01:50:10)

$\{1,2,3\}$ üzerinde $\{(1,1),(2,2),(3,3),(1,2),(2,1),(1,3),(3,1),(2,3),(3,2)\}$ bir denklik bağıntısı mıdır?

> **Çözüm:** Evet. Yansımalı, simetrik ve geçişlidir. Ters simetrik değildir ama denklik bağıntısı için ters simetriye bakılmaz.

### Soru 9 (eski vize sorusu, derste sözlü, 01:53:32)

Tam sayılar üzerinde $x - y = 5$ koşuluyla yazılan $R$ bağıntısı bir denklik bağıntısı mıdır?

> **Çözüm:** Hayır. $(6,1)$, $(7,2)$, $(1,-4)$ gibi ikililer yazılabilir. Ama $x - x = 0 \ne 5$ olduğu için hiçbir $(x,x)$ yazılamaz. Bağıntı yansımalı olamaz, bu yüzden denklik bağıntısı değildir.

### Soru 10 (derste sözlü, 01:58:08 ve 02:00:11)

$X = \{1,\ldots,6\}$ üzerinde $R = \{(1,1),(1,3),(1,5),(3,1),(3,3),(3,5),(5,1),(5,3),(5,5),(2,2),(2,6),(6,2),(6,6),(4,4)\}$ bir denklik bağıntısı mıdır? Geçişlilik için $(5,2)$ gerekir mi?

> **Çözüm:** Yansımalı, simetrik ve geçişlidir, bu yüzden denklik bağıntısıdır. $(5,2)$ gerekmez. $(5,5)$ ile $(2,2)$ arasında ortak iç eleman olmadığı için bu iki ikili bir zincir oluşturmaz.

### Soru 11 (eski vize sorusu, derste sözlü, 02:15:09)

$A = \{1,2,3,4\}$ üzerinde "$x$ divides $y$" bağıntısını yazın. Bu bir sıralama bağıntısı mıdır?

> **Çözüm:** $R = \{(1,1),(1,2),(1,3),(1,4),(2,2),(2,4),(3,3),(4,4)\}$. Yansımalı, ters simetrik ve geçişlidir. Sıralama bağıntısıdır. $(4,1)$ gibi ters ikililer yazmak hatadır (Bölüm 13.2).

### Soru 12 (derste sözlü, 02:20:59)

$X = \{1,2,3,4\}$ üzerinde $a \le b$ bağıntısını yazın, sıralama bağıntısı olduğunu gösterin ve Hasse diyagramını çizin.

> **Çözüm:** $R = \{(1,1),(1,2),(1,3),(1,4),(2,2),(2,3),(2,4),(3,3),(3,4),(4,4)\}$. Yansımalı, ters simetrik ve geçişlidir. Yansıma döngüleri ve geçişmeden gelen $1 \to 3$, $1 \to 4$, $2 \to 4$ okları silinince Hasse diyagramı $1 \to 2 \to 3 \to 4$ olur.

### Soru 13 (derste sözlü, 02:33:42)

$R = \{(b,a),(b,c),(c,a),(c,d),(d,c),(a,d)\}$ geçişli midir? Değilse Warshall algoritmasıyla geçişme kapanışını bulun.

> **Çözüm:** Geçişli değildir; örneğin $b \to a$ ve $a \to d$ var, $b \to d$ yok. Warshall algoritması sırasıyla $(b,d)$; hiçbir şey; $(d,a)$, $(d,d)$; $(a,a)$, $(a,c)$, $(c,c)$ ekler. Sonuç matrisinin $a$, $b$, $c$, $d$ satırlarının dördü de $1011$'dir (Bölüm 16.5).

### Soru 14 (derste sözlü, 02:46:48)

6 kişinin hangi dilleri konuştuğu biliniyor. Kim kiminle ortak bir dilde konuşabilir?

> **Çözüm:** Kişi-dil matrisi $M_\alpha$ ile devriği $M_\alpha^T$'nin Boolean çarpımı alınır. Sonuç matrisinde 1 olan hücreler ortak dil konuşan kişileri gösterir. Derste okunan sonuç: $a_1$; $a_2$, $a_4$, $a_6$ ile, $a_2$; $a_1$, $a_4$, $a_6$ ile konuşabilir (Bölüm 17).

## Dersin Toparlaması

Bu derste bağıntılar ayrıntılı olarak işlendi. Bağıntı, kartezyen çarpımın bir alt kümesi olarak tanımlandı ve liste, ok diyagramı ve matris ile gösterildi. Bir küme üzerindeki bağıntılar için dört temel özellik görüldü: yansıma (yansımalı, non-reflexive, yansımasız), simetri, ters simetri ve geçişme. Her özellik için matris üzerinden algoritma fikri konuşuldu ve algoritmalarda uç noktaların önemi vurgulandı. Bir özelliğin yokluğunu göstermek için tek bir karşı örneğin yettiği, geçişlilikte kontrol edilecek zincir yoksa bağıntının geçişli sayıldığı özellikle anlatıldı. Bağıntının tersi ve bileşkesi ($R^2$, $R^3$) örnekle hesaplandı. Altı bağıntılık bir sınıf alıştırması, bir bağıntının hem simetrik hem ters simetrik olabileceğini gösterdi.

Dersin ikinci yarısında özellikler bir araya getirildi. Yansımalı, simetrik ve geçişli bağıntılar denklik bağıntısı; yansımalı, ters simetrik ve geçişli bağıntılar sıralama bağıntısıdır. Sıralama bağıntısının grafı, yansıma ve geçişme okları silinerek Hasse diyagramına indirgendi. Eksik bir özelliği eklemeye kapanış dendi. Geçişme kapanışı için Warshall algoritması $O(n^3)$ işlemle adım adım çalıştırıldı. Son olarak, kişi-dil matrisiyle "kim kiminle konuşabilir" problemi matris çarpımına indirgendi. Gelecek hafta bu bölüm tamamlanacak ve yeni bölüme geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
