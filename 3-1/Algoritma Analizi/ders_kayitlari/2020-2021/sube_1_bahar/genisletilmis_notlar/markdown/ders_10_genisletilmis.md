# Ders 10 Genişletilmiş Notu: LCS, Açgözlü Yöntem, Graf Tekrarı, DFS, Topolojik Sıralama ve Geri İzleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. En Uzun Ortak Alt Dizi (LCS)
- 2. Açgözlü yöntem (Greedy method)
- 3. Minimum yayılan ağaç, Dijkstra ve Huffman
- 4. Graf kavramlarının tekrarı
- 5. Grafın bilgisayarda saklanması
- 6. Graf üzerinde gezinme: BFS ve DFS
- 7. DFS sözde kodları ve örnek
- 8. Topolojik sıralama
- 9. Geri izleme (Backtracking)
- 10. Graf işlemlerinin karmaşıklığı ve durum uzayı ağacı
- 11. Alt küme toplamı (Subset Sum)
- 12. N-Vezir problemi
- 13. Hamilton devresi problemi
- Örnek Sorular

## 1. En Uzun Ortak Alt Dizi (LCS)

Önceki derslerde dinamik programlamanın sırt çantası (knapsack) gibi örnekleri işlenmişti. Dinamik programlamanın son örneği olarak bu derste en uzun ortak alt dizi (Longest Common Subsequence, kısaca LCS) problemi ele alındı.

### 1.1 Problemin tanımı

İki dizgi (string) verilir. Örneğin DNA'dan alınmış iki gen dizisi düşünülebilir (ekrandan, 00:15:00):

$$X = \text{ATCTGAT}, \qquad Y = \text{TGCATA}$$

İki dizgide soldan sağa sırası korunarak eşleşen karakterler aranır. Karakterlerin bitişik olması gerekmez; yalnız sıraları korunur. Bu iki dizgide TCT, TC, A gibi birçok ortak alt dizi vardır; amaç bunların en uzununu bulmaktır. Tahtada sonuç $LCS(X, Y) = \text{TCTA}$ olarak yazıldı (uzunluk 4). Hoca bu tür bir analizin, ortak yapıyı ve bu yapıyı bozan yerleri (örneğin bir mutasyonu) bulmak için kullanılabileceğini söyledi.

> Ek bilgi (derste anlatılmadı): Bu iki dizgi için uzunluğu 4 olan başka en uzun ortak alt diziler de vardır (TCAT, TGAT); python ile yapılan kontrolde LCS uzunluğunun 4 olduğu doğrulandı.

### 1.2 Neden dinamik programlama?

Problem alt problemlere bölünebilir: dizginin tamamı yerine belli bir parçası (öneki) düşünülebilir. Kaba kuvvet (brute force) yaklaşımında karakterler soldan sağa eşleştirilmeye çalışılır: ilk A için Y'de A aranır, yoksa T'ye geçilir, T ile T eşleşir, sonra C ile C eşleşir ve böyle devam edilir. Ama dizilim biraz farklı olsa her şey baştan değişir: başta yapılan bir eşleştirme, daha sonra daha uzun bir ortak dizi oluşturabilecek bir eşleştirmeyi engelleyebilir. Hoca buna "bozucu etki" dedi. Dinamik programlama ise dizgileri alt dizgiler olarak (önce A, sonra AT, sonra ATC, ...) düşünür, sırt çantası probleminde olduğu gibi bütün alt problemlerin sonuçlarını bir LCS tablosuna yazar ve en uygun sonucu üretir.

### 1.3 Bağıntı

$X$'in $i$. karakteri $x_i$, $Y$'nin $j$. karakteri $y_j$ olsun. Veriler bir matriste saklanır (ekrandan, 00:15:00).

**Durum 1: $x_i = y_j$.** Bu karakter ortak alt diziye eklenebilir. Bir önceki durum $X$'te $i-1$, $Y$'de $j-1$'dir; onun çözümüne bir eklenir:

$$LCS[i, j] = LCS[i-1, j-1] + 1$$

**Durum 2: $x_i \ne y_j$.** Bu durumda ya $x_i$ ortak alt dizinin parçası değildir ("$x_i$ may not be part of common subsequence"), ya da $y_j$ değildir. Satırlar $i$, sütunlar $j$ ile gösterildiğinde birinci olasılık üstteki hücreye $LCS[i-1, j]$, ikincisi soldaki hücreye $LCS[i, j-1]$ karşılık gelir.

Hoca burada sınıfa hangi hücrenin alınması gerektiğini sordu. Cevap: ikisinden **büyük olanı**. Çünkü tabloya en küçük alt problemden başlanarak ilerlenir ve önceki çözümler bilinir; büyük olan değer daha uzun bir ortak alt diziyi gösterir.

**Başlangıç:** $i = 0$ ya da $j = 0$ ise, yani dizgilerden biri boşsa, değer 0'dır. Bağıntının tamamı:

$$LCS[i,j] = \begin{cases} 0 & i = 0 \text{ ya da } j = 0 \\ LCS[i-1,j-1] + 1 & i,j > 0 \text{ ve } x_i = y_j \\ \max\left(LCS[i,j-1],\ LCS[i-1,j]\right) & i,j > 0 \text{ ve } x_i \ne y_j \end{cases}$$

### 1.4 Sayısal örnek

Verilenler (ekrandan, 00:20:00 ve 00:30:00):

$$X = \langle B, A, C, D, B \rangle, \qquad Y = \langle B, D, C, B \rangle$$

Gözle bakıldığında B ile B, C ile C, sonra yine B eşleşir. İki farklı en uzun ortak alt dizi görülür: BDB ve BCB. CB ve DB de ortak alt dizidir ama daha kısadır; en uzunların uzunluğu 3'tür.

Tablonun bir kenarına $Y$, diğer kenarına $X$ yazılır (hangisinin nereye yazıldığı önemli değildir). Boş dizgi (null string) için fazladan bir satır ve bir sütun eklenir. Doldurma adımları:

- **İlk satır ve sütun.** Boş dizginin B, BD, BDC, BDCB ile (ve B, BA, BAC, ... ile) ortak uzunluğu 0'dır. Bunlar başlangıç koşullarıdır.
- **Satır B.** B ile B eşittir; çapraz hücredeki 0'a 1 eklenir: 1. Sonra B ile D eşit değildir; üst (0) ve sol (1) hücreden büyüğü olan 1 kopyalanır, ekleme yapılmaz. B ile C eşit değildir: 1. Son sütunda B ile B eşittir; çapraz hücredeki 0'a 1 eklenir: yine 1. Hoca bu B'nin burada pek etkisi olmadığını, soldan gelinse de 1 olacağını belirtti.
- **Satır A.** A, Y'deki hiçbir karakterle eşit değildir; her hücreye üst ve soldan büyüğü (1) kopyalanır. Bazı hücrelerde üst ve sol aynıdır; hangisinden alındığı, ileride bulunacak farklı alt dizileri belirler.
- **Satır C.** C ile B: 1, C ile D: 1. C ile C eşittir; çapraz hücredeki 1'e 1 eklenir: 2. C ile B eşit değildir: 2.
- **Satır D.** D ile B: 1. D ile D eşittir; çapraz 1 + 1 = 2. D ile C: üst ve sol 2, sonuç 2. D ile B: 2.
- **Satır B.** B ile B eşittir: çapraz 0 + 1 = 1. B ile D: 2. B ile C: 2. Son hücrede B ile B eşittir: çapraz 2 + 1 = **3**.

Sonuç tablosu (ekrandan, 00:30:00; python ile doğrulandı):

| | $\varnothing$ | B | D | C | B |
|---|---|---|---|---|---|
| $\varnothing$ | 0 | 0 | 0 | 0 | 0 |
| B | 0 | 1 | 1 | 1 | 1 |
| A | 0 | 1 | 1 | 1 | 1 |
| C | 0 | 1 | 1 | 2 | 2 |
| D | 0 | 1 | 2 | 2 | 2 |
| B | 0 | 1 | 2 | 2 | 3 |

Strateji özetle şuydu: eşitlikte çaprazdan bir eklendi; eşitsizlikte ekleme yapılmadı, üst ya da soldan büyüğü alındı. Olabilecek en uzun ortak alt dizinin uzunluğu 3'tür.

### 1.5 Geriye izleme: alt dizinin kendisini bulmak

Uzunluğu bulmak yetmez, alt dizinin kendisi de istenir. Bunun için sondan başa doğru gidilir (backtracking):

- Son hücredeki 3'ün üstü ve solu 2'dir; 3'ten farklı oldukları için bu değer çaprazdan 1 eklenerek gelmiştir. Demek ki son B alt diziye eklenmiştir. Çapraz hücreye (2) gidilir.
- Bu 2'nin üstü ve solu da 2'dir; burada bir şey eklenmemiştir. İki yol vardır: üste gidilirse C'nin, sola gidilirse D'nin alındığı yola girilir.
- Üstten gidilince C ile C'nin eşleştiği 2'ye gelinir; üst ve solu 1 olduğundan C eklenmiştir. Sonra 1'lerden geri gidilerek B'nin eklendiği hücreye varılır. Sonuç: **BCB**.
- Soldan gidilince D ile D'nin eşleştiği 2'ye gelinir; D eklenmiştir. Oradan yine B'ye varılır. Sonuç: **BDB**.

Böylece hem maliyet (uzunluk) hem de alt diziler bulunur. Derste bir öğrenci, hocanın bir adımda C yerine yanlış harf yazacağını fark ederek uyardı; hoca düzeltti.

### 1.6 Sözde kod

Tablo doldurulurken her hücrenin hangi durumdan geldiği bir $B$ matrisine etiket olarak yazılır (ekrandan, 00:35:00):

- $x_i = y_j$: $B[i, j]$ = `ADDXY` (karakter eklenir).
- $x_i \ne y_j$ ve üstteki büyük: $B[i-1, j]$ yönü, `SKIPX` ($X$'teki harf atlanır).
- $x_i \ne y_j$ ve soldaki büyük: $B[i, j-1]$ yönü, `SKIPY` ($Y$'deki harf atlanır).

Geriye izleme fonksiyonu $X$ dizisini, $Y$ dizisini ve $(m+1) \times (n+1)$ boyutlu $B$ matrisini (boş dizgiler dahil) alır. İndisler en sondan başlar, ikisinden biri sıfıra ulaşınca durulur (ekrandan, 00:35:00; döngü gövdesinin son iki satırı altyazıdan):

```text
FindLCS(X[1..m], Y[1..n], B[0..m, 0..n]) {
    i = m; j = n;
    while (i != 0 && j != 0) {
        switch (B[i, j]) {
            case ADDXY: add X[i] to LCS (önüne ekle); i--; j--; break;
            case SKIPX: i--; break;
            case SKIPY: j--; break;
        }
    }
}
```

Matrisi oluşturmak kolaydır: ilk satır ve ilk sütun doğrudan 0 yapılır, sonra dizgiler karakter karakter karşılaştırılarak matris doldurulur.

### 1.7 Karmaşıklık

Hoca kaba kuvvet karmaşıklığının üstel olduğunu hatırladığını söyledi. Dinamik programlamada uzunlukları $m$ ve $n$ olan dizgiler için matrisi doldurmak $\Theta(mn)$ zaman alır. Geriye izleme döngüsü her adımda $i$ ya da $j$'yi azalttığından en fazla $m + n$ adım sürer; bu $mn$'den küçük olduğu için toplam zaman $\Theta(mn)$ olur. Yer karmaşıklığı da $(m+1)(n+1)$ hücreden dolayı $\Theta(mn)$'dir. Dizgi uzunlukları yaklaşık eşitse hem zaman hem yer $\Theta(n^2)$'dir; iç içe iki döngüyle iş tamamlanır.

> **Ders sonrası not:** Hoca geriye izleme döngüsünün "$m$ ya da $n$'den hangisi büyükse o kadar" döneceğini söyledi. Her adımda yalnız biri azalabildiği için doğru üst sınır büyük olasılıkla $m + n$'dir; bu, toplam $\Theta(mn)$ sonucunu değiştirmez.

## 2. Açgözlü yöntem (Greedy method)

Hoca bu konunun bir önceki dönem anlatılmadığını ama dersin konuları arasında olduğunu belirtti. Açgözlü yöntem de dinamik programlama gibi bir problem çözme tekniğidir ve graflarda yeniden karşılaşılacaktır.

### 2.1 Tanım

Açgözlü yöntem optimizasyon problemlerinin çözümünde kullanılır (ekrandan, 00:40:00). Fark şudur: dinamik programlama **optimal çözümü** verir, açgözlü yöntem ise **uygun (feasible) çözümü** verir; bu çözüm optimal olmayabilir. "Açgözlülük", ilk bakışta tamamen kâra odaklanmak, yani en düşük maliyete ya da en yüksek kazanca yönelmektir. Ama işin sonunda optimuma ulaşılamayan durumlar olabilir.

Hoca, bir önceki derste bir öğrencinin sırt çantası için "en pahalı olanı alırım" önerisinin açgözlü bir yaklaşım olduğunu hatırlattı. Bazen en değerli eşyayı almayıp diğerlerini almak daha yüksek kâr getirir; bu dinamik programlamada görülmüştü.

### 2.2 Para bozma (change-making) problemi

20 TL en az sayıda parayla bozulmak isteniyor; 10, 5 ve 1 TL'lik birimler var. Birçok çözüm olabilir (iki 10'luk; dört 5'lik; yirmi 1'lik; bir 10'luk ve on 1'lik ...). Kaba kuvvete gerek duymadan açgözlü düşünce: en büyük birimden başla, ondan alabildiğin kadar al. Bu örnekte birimler 20'yi tam sayı katlarıyla verebildiği için açgözlü yöntem iyi sonuç verir.

Hoca, birimler birbirinin tam katı olmadığında (örneğin 7,5, 3 ve 8 liralık paralar düşünüldüğünde) açgözlü yöntemin tam (exact) ya da optimal çözümü bulamayabileceğini, yalnız uygun bir çözüm üreteceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Açgözlü para bozmanın optimal olmadığı bilinen küçük bir örnek, $\{1, 3, 4\}$ birimleriyle 6'yı bozmaktır: açgözlü yöntem $4 + 1 + 1$ (3 para) seçer, optimal çözüm ise $3 + 3$'tür (2 para).

### 2.3 Sırt çantası için açgözlü yaklaşım

Hoca bunun "yükte hafif, pahada ağır" deyiminin tam karşılığı olduğunu söyledi. Değerler $v_1, v_2, \dots, v_n$, ağırlıklar $w_1, w_2, \dots, w_n$ ve çantanın kapasitesi $C$ olsun. Her eşyanın kârlılığı (profit) hesaplanır:

$$\frac{v_1}{w_1},\ \frac{v_2}{w_2},\ \dots,\ \frac{v_n}{w_n}$$

Değer ağırlığa bölünür; böylece birim ağırlık başına değer bulunur (ağırlık değere bölünseydi en küçükler seçilmeliydi). Oranlar büyükten küçüğe sıralanır (sort by profit). En kârlı eşya önce alınır, boş yer kaldıysa sıradaki en kârlı eşya alınır ve kapasiteye bakılarak çanta doldurulmaya çalışılır.

Hoca günlük hayattan bir benzetme yaptı: beslenmede kalorisi düşük, besin değeri (örneğin proteini) yüksek yiyecekleri seçmek de aynı mantıktadır.

## 3. Minimum yayılan ağaç, Dijkstra ve Huffman

### 3.1 Yayılan ağaç

Yayılan ağaç (spanning tree), bir grafın içinden çıkarılan özel bir ağaçtır: bütün düğümlere erişir ve döngü (cycle) içermez; ağaç olması için zaten döngüsüz olmalıdır. Hoca örnek olarak bir mahalleye boru hattı döşemeyi verdi: bütün sokaklara girmek gerekmez, evlerin hepsine bağlantıyı sağlayan bazı yolları seçmek yeter.

Kenarlara $a_1, \dots, a_6$ maliyetleri verildiğinde amaç şudur (ekrandan, 00:50:00): "To minimize cost, we should select some edges from set of edges $\langle a_1, \dots, a_6 \rangle$". Bu ayrık matematikte ve veri yapılarında anlatılan iki algoritmayla çözülür: Prim ve Kruskal.

### 3.2 Kruskal

Derste bir öğrenciyle birlikte hatırlandı. **Soru:** Prim'de düğüm ağırlıkları mı kullanılıyordu? **Cevap:** İkisinde de kenarların ağırlıkları kullanılır; düğümlerin ağırlığı olmaz.

Kruskal'da kenarlar ağırlığa göre sıralanır ($a_i < a_j < \dots$). En küçük kenar seçilir ve eriştiği düğümler ziyaret edilmiş sayılır. Sonra ondan büyük ama diğerlerinden küçük kenar seçilir; seçilen kenar ağaç yapısını bozmamalı, yani döngü oluşturmamalıdır. Ara adımlarda birbirinden ayrı parçalar, yani bir orman oluşabilir; bunları tek ağaçta birleştirmek için yine uygun en küçük kenar seçilir.

### 3.3 Prim

Bir düğümden başlanır. Bu düğümden çıkan kenarlardan hangisi daha az maliyetliyse ($a_1$ mi $a_2$ mi) o seçilir. Sonra ağaca eklenen düğümlerden çıkan kenarlar arasından en küçüğü seçilir ve sürekli döngü kontrolü yapılır. Bütün düğümler ziyaret edilince ağaç oluşmuş olur.

Hoca iki algoritmada da açgözlü mantığın kullanıldığını vurguladı: en fazla bir sıralama yapılır ve en küçük seçilerek iş bitirilir. "Biraz büyüğünü seçsem ileride daha iyi sonuç bulur muyum?" diye düşünülmez. Uygulama ayrıntıları veri yapılarına ait olduğu için geçildi.

### 3.4 Dijkstra ve Huffman

En kısa yol algoritmalarından yaygın kullanılan Dijkstra da açgözlü bir yöntemdir: bir düğümden başlanır, o ana kadar görülen düğümler içinden en küçük maliyetlisi seçilir, maliyetler sürekli güncellenir ve en kısa yol iteratif olarak bulunur. Huffman kodlaması da açgözlü yöntemin bir uygulaması olarak örnek verildi.

## 4. Graf kavramlarının tekrarı

Yeni bir çözüm yöntemine geçmeden önce graflar hatırlatıldı.

### 4.1 Graf ve türleri

Graf soyut bir veri tipidir. İki kişi arasındaki bağlantı ya da bir sosyal ağdaki arkadaşlık bağlantılarının bilgisayarda kodlanıp saklanması graflarla yapılır. Graf aslında bir kümedir: köşeler (vertex) ve kenarlar (edge) kümesi. Türleri:

- **Yönlü (directed) ya da yönsüz (undirected):** yönlüde çizgilerin yönü önemlidir. Yönlü graflara kısaca digraph denir.
- **Ağırlıklı (weighted) ya da ağırlıksız:** ağırlıksızda bağlantı yalnız 0-1 ile gösterilir.
- **Tam graf (complete graph):** bir öğrenci önce "bütün düğümlerden geçen" diye tanımladı; hoca bunun bir yol tanımı olduğunu belirtti. Doğrusu: her düğümden, başka bir düğüm üzerinden geçmeden bütün düğümlere doğrudan gidilebilir. Yıldız (star) ve tekerlek (wheel) graflar gibi başka özel graflar da vardır.

> **Ders sonrası not:** Hoca tam grafın kenar sayısı için geometrideki "köşegen sayısı" formülünü, $\frac{n(n-3)}{2}$'yi hatırlattı. $n$ düğümlü tam grafın kenar sayısı $\frac{n(n-1)}{2}$'dir; $\frac{n(n-3)}{2}$ ise $n$ kenarlı bir çokgenin köşegen sayısıdır.

### 4.2 Bağlılık, ağaç ve orman

Bağlılık (connectivity), köşeler arasında bağlantının olup olmadığını gösterir. Ağaç döngüsüz özel bir graftır. Orman (forest) daha da özel bir graftır: birbirinden bağımsız birden fazla ağaçtan oluşur. **Soru:** Ormandaki her parçaya bağlı graf mı denir? **Cevap:** Her ağaç kendi içinde bağlıdır; bunlar bağlı bileşenlerdir (connected component). Ağaca bir kenar eklenip döngü oluşturulursa yapı ağaç olmaktan çıkar ve sıradan bir graf olur.

## 5. Grafın bilgisayarda saklanması

### 5.1 Komşuluk kavramı

Komşuluk (adjacency), iki düğüm arasında kenar olup olmamasıdır. Kenar varsa yön bilgisi ve ağırlık bilgisi de olabilir. Hoca örnek verdi: İstanbul'dan Ankara'ya yolun varlığı bir şeydir, yolun kilometresi başka bir şeydir; hangisinin saklanacağı probleme göre değişir.

### 5.2 Komşuluk matrisi ve komşuluk listesi

Graf bilgisayarda komşuluk matrisi (adjacency matrix) ya da komşuluk listesi (adjacency list) ile saklanır (ekrandan, 01:00:00):

- Kenarlar yoğunsa (dense) matris uygundur.
- Kenarlar seyrekse (sparse) bağlı liste kullanmak daha uygundur.

Yoğun örnekte a, b, c, d, e, f düğümleri arasında birçok kenar vardır. Matriste satır ve sütunlar düğümlerdir; bağlantı yoksa 0, varsa 1 ya da kenarın ağırlığı yazılır (örneğin a-b hücresine $x$).

Seyrek örnekte (a-b, b-d, c-d, d-f, e-f) 6 düğüm vardır. Matris $|V|^2 = 36$ hücre kaplar ama yalnız 5 kenar vardır; hoca "31 tanesi boşa gidiyor" dedi. Komşuluk listesinde ise her düğüm için ayrı bir bağlı liste başı tutulur ve her listede o düğümün komşuları (gerekirse kenar maliyetiyle) yer alır.

Yer karmaşıklıkları:

- Komşuluk matrisi: $\Theta(|V|^2)$.
- Komşuluk listesi: düğüm sayısı kadar liste başı, toplamda kenar sayısı kadar eleman: $\Theta(|V| + |E|)$. Bütün kenarlar tek bir düğümde toplansa bile toplam aynı kalır.

### 5.3 Ziyaret bilgisi

**Soru:** Bütün düğümlerin ziyaret edilip edilmediğini kontrol etmek için kaç kez ziyaret edildiği de mi saklanmalı? **Cevap:** Yalnız ziyaret edilip edilmediği yeter. Düğüm bir yapı (structure) olarak tutuluyorsa içine boolean bir alan konur; ya da düğüm sayısı kadar bir dizi açılır ve ziyaret edilmeyenler 0 ile gösterilir. İstenirse her ziyarette artırılarak kaç kez erişildiği de tutulabilir.

## 6. Graf üzerinde gezinme: BFS ve DFS

Graf birçok biçimde gezilebilir, ama sistematik bir arama için bilinen iki algoritma vardır: genişlik öncelikli arama (breadth-first search, BFS) ve derinlik öncelikli arama (depth-first search, DFS).

- **BFS:** önce genişliğine arar. Hoca bunu bir GPS'e benzetti: önce bulunduğumuz konumun çevresi taranır, sonra alan biraz daha genişletilir. Yardımcı veri yapısı kuyruktur (queue). Kuyruk FIFO ile çalışır; ekleme (enqueue) sondan, çıkarma (dequeue) baştan yapılır.
- **DFS:** derinliğine arar; gidebildiği kadar derine gider, sonra geri gelir. Yığıt (stack) kullanır; LIFO mekanizması vardır, ekleme push, çıkarma pop ile yapılır.

> **Ders sonrası not:** Tahtada iki satırın ikisi de "DFS" diye yazıldı (ekrandan, 01:20:00). Kuyruk (Queue, FIFO, Enqueue, Dequeue) yazılan satır BFS'e aittir; hoca da sözlü olarak bunu breadth-first search için söyledi.

## 7. DFS sözde kodları ve örnek

### 7.1 Sayaçlı DFS

Graf liste ya da matrisle saklanabilir. Önce bir ziyaret dizisi `Visited[0..V]` tutulur ve her düğüm 0 ile işaretlenir (ekrandan, 01:20:00; son satırlar altyazıdan):

```text
DFS(G)
    mark each vertex in Visited with 0
    count ← 0
    for each vertex v in V
        if v is marked with 0
            dfs(v)

dfs(v)
    count++; mark v with count
    for each vertex w adjacent to v
        if w is marked with 0
            dfs(w)
```

Sayaç sayesinde her düğümün kaçıncı sırada ziyaret edildiği de görülür. `dfs` kendini özyinelemeli çağırır: bir düğümün komşularından biri seçilir ve onun için her şey baştan başlar; ardından onun komşularına bakılır. Henüz bakılmamış komşular beklerken aşağıya, derine inilir. Hangi düğüme geri dönüleceği yığıtla hatırlanır.

### 7.2 Fakülte binası benzetmesi

Hoca DFS'i şöyle anlattı: tabelası olmayan bir fakülte binasına ilk kez gelip bölüm sekreterliğini arıyorsunuz. Ana kapıdan girip bir kanada dönüyorsunuz; o katta koridorun sonuna kadar bütün kapılara bakıyorsunuz, bulamayınca çıkıp diğer bölüme giriyorsunuz; böylece katın bütün bölümlerini derinlemesine geziyor, sonra ana kapıya dönüp bir üst kata çıkıyorsunuz. Bu körü körüne bir aramadır (kör arama). Geri dönmeniz gereken yerler yığıtta tutulur.

### 7.3 Örnek: A'dan G'ye yol var mı?

Yönlü graf (ekrandan, 01:25:00): A → B, A → C, A → D, B → E, B → F, C → E, C → G, E → D, E → F, G → F. Yönlü olduğundan A'dan B'ye gidilir ama B'den A'ya gidilemez. Soru, A'dan G'ye yol olup olmadığıdır (bir bağlılık problemi). A ana kapı, G bölüm sekreterliği, diğerleri ara geçişler gibi düşünülür.

- A yığıta atılır ve ziyaret edildi olarak işaretlenir. Bir öğrencinin cevabıyla: yığıta atılır çünkü geri dönmek gerekebilir ("kaybolma ihtimalimiz var").
- A'nın komşularından biri seçilir; hangisinin seçildiği önemli değildir (matriste saklanırsa sıra B, C, D olur). B seçilir, yığıta atılır.
- B'den E'ye gidilir. E'den D'ye gidilir. D'den hiçbir yere gidilemez: özyinelemeli çağrı geri döner, D yığıttan çıkarılır.
- E'ye dönülür; E'den F'ye gidilir, F işaretlenir. F'den de çıkış yoktur; F yığıttan çıkar. E'nin gidilecek yeri kalmadı; E çıkar. B'nin de kalmadı; B çıkar.
- A'ya dönülür; A'dan C'ye gidilir. C'den E'ye gidilebilir ama E işaretlidir. C'den G'ye gidilir ve hedefe ulaşılır.

Bulunan yol A → C → G'dir; yol maliyeti sorulursa üzerindeki kenar maliyetleri toplanır. Hoca yanlış bir dala girmeyi gömleğin ilk düğmesini yanlış iliklemeye benzetti: bir önceki adıma dönmek gerekir. DFS "burnunun dikine" gider: sağa sola bakmadan ilk bulunan komşuya, sonra onun komşusuna ilerler.

### 7.4 Özyinelemeli DFS ve yığıtlı DFS

Yapısal programlamadan hatırlanacağı gibi fonksiyon çağrılarında bazı bilgiler (program sayacı gibi) otomatik olarak yığıta atılır. Faktöriyelde $f(n) = n \cdot f(n-1)$ hesaplanırken önce $f(n-1)$ çözülür, sonra $n$ ile çarpılır. Özyinelemeli çağrıların bu yığıt mekanizması sayesinde DFS doğrudan yığıt kullanmadan da yazılabilir (ekrandan, 01:35:00):

```text
Recursive DFS(G, s) {
    mark s as VISITED
    for all neighbours w of s
        if w is not VISITED
            DFS(G, w)
}
```

Burada başlangıç düğümü (source node) $s$ verilir; A'dan G'ye yol arandığı için A'dan başlanır. Bir komşu seçildiğinde artık yeni başlangıç noktası o komşudur; önce bu alt graf çözülür, sonra ana problem kaldığı yerden devam eder. Hoca özyinelemeli çözümün daha kolay olduğunu söyledi.

Yığıtlı (iteratif) sürüm (ekrandan, 01:35:00; döngü kısmı altyazıdan):

```text
DFS(G, s) {
    stack.push(s);
    mark s as visited;
    while (stack is not empty) {
        v = stack.pop();
        for all neighbours w of v in G {
            if (w is not visited) {
                stack.push(w);
                mark w as visited;
            }
        }
    }
}
```

### 7.5 DFS'in özellikleri

- Veri yapısı olarak yığıt kullanır; algoritmanın kendisi yığıta ihtiyaç duyar.
- Bir düğüme birden fazla kez uğranabilir: A'dan B'ye gidilip B'den bir yere gidilemezse A'ya tekrar gelinir; yani en az iki kez uğrama durumu vardır.
- Verimlilik: komşuluk matrisiyle $\Theta(|V|^2)$, komşuluk listesiyle $\Theta(|V| + |E|)$.
- Gezinme bir ağaç biçimi oluşturur; gidebildiği kadar ileri gidip geri gelir (geri kenar, back edge).

## 8. Topolojik sıralama

### 8.1 Problem

Ön koşullu dersler örneği (ekrandan, 01:40:00): her ders bir düğümdür ve C1 → C3, C2 → C3, C3 → C4, C3 → C5, C4 → C5 kenarları vardır. C5'i alabilmek için C3'ü ve C4'ü tamamlamak gerekir; C3 hem C4'ün hem C5'in ön koşuludur. Topolojik sıralamada döngü olmamalıdır; döngü varsa çözüm yoktur. Grafta C3, C4, C5 arasında döngü varmış gibi görünür ama yoktur; ok yönlerinden biri ters olsaydı döngü olurdu.

### 8.2 DFS ile çözüm

Kendisine kenar gelmeyen (girişi olmayan) bir düğümden başlanır: C1 ya da C2. C1 ile başlanırsa (ekrandan, 01:45:00):

- C1 yığıta atılır ve işaretlenir; komşusu C3 yığıta atılır.
- C3'ün iki komşusundan C4'e gidilir, sonra C4'ün komşusu C5'e gidilir.
- C5'in gidilecek komşusu yok: C5 yığıttan çıkar. C4'ün başka komşusu yok: C4 çıkar. C3 çıkar. C1 çıkar.
- Yığıt boşalınca ziyaret edilmemiş C2 yığıta atılır; komşusu C3 zaten ziyaret edilmiştir; C2 çıkar.

Yığıttan çıkış sırası (popping-off order): C5, C4, C3, C1, C2. **Bu sıranın tersi** topolojik sıralamayı verir: C2, C1, C3, C4, C5. Önce C1 ve C2 alınır, sonra C3, sonra C4 ve C5.

C2 ile başlanırsa: C2 → C3 → C5 gidilir, C5 çıkar; C3'ten C4'e gidilir, C4'ün komşusu C5 ziyaret edildiği için C4 çıkar; sonra C3 ve C2 çıkar; yığıt boşalınca C1 eklenir ve çıkar. Çıkış sırası C5, C4, C3, C2, C1; tersi C1, C2, C3, C4, C5 olur. Topoloji yine bozulmaz. (Hoca bu ikinci izlemede çıkarma sırasını önce yanlış yazdı, sonra baştan alıp düzeltti.)

### 8.3 Azalt ve fethet ile çözüm (kaynak çıkarma)

Azalt ve fethet (decrease and conquer) yönteminde bağıntı $T(n) = 1 + T(n-1)$ biçimindeydi: bir maliyet ödenir, eleman sayısı bir küçültülür ve algoritma devam eder. Topolojik sıralamada bunun karşılığı **kaynak çıkarma algoritmasıdır (source removal algorithm)**: girişi olmayan bir düğüm seçilir, kenarlarıyla birlikte graftan çıkarılır ve kalan alt graf aynı yöntemle işlenir.

Derste a, b, c, d, e, f, g, h düğümlü bir grafla gösterildi (ekrandan, 01:50:00). Başlangıçta girişi olmayan düğümler a ve c idi. a çıkarılınca b, e, f "başıboş" kaldı; sonra b ya da e seçilebildi. Hocanın izlediği sıra: a, e, b, f, c, d (ya da g), g (ya da d), h. Bir bölümde d ile g'nin sırası seçime bağlıydı.

<!-- BELİRSİZ: Bu örnek grafın kenarlarının tamamı karelerde okunamadı (hoca tahtayı adım adım sildi); kenarlar altyazıdan da tam çıkmıyor. Karede kalan parçalar e → f, c → d, d → h, g → h oklarıdır. Sonuç sırası "a e b f c d g h" karede okunuyor. -->

Hoca bu yöntemin herhangi bir yığıta ihtiyaç duymadan problemi çözdüğünü ve DFS'e göre daha kolay olduğunu söyledi; DFS ile çözüp çıkış sırasının tersini almayı da denemeyi önerdi.

**Soru:** E yerine önce B çıkarılsaydı E ve F ayrı kalıyordu; graf bozulmuyor mu? **Cevap:** Graf bozulmaz, yeni bir graf hâline gelir. $T(n)$, $T(n-1)$'i çağırdığında $T(n)$ bozulmaz; yeni fonksiyon yeni veriyle yüklenir, eskisi kalır (Quicksort'taki animasyonda olduğu gibi). Özyinelemeli DFS de kalınan yerden devam etmeyi bu sayede sağlar. a'dan sonra b seçilse de e ve f, sonra c ve d ya da g, en sonda h gelir; sonuç değişmez. Örneğin a dersi alındıktan sonra b de e de alınabilir, ama f kesinlikle ikisinden sonra gelmelidir.

## 9. Geri izleme (Backtracking)

Problem çözme yöntemlerinden dinamik programlama, böl ve fethet, azalt ve fethet ve açgözlü yöntem görülmüştü; sırada geri izleme vardır. Hoca bu kadar graf tekrarının bunun için yapıldığını söyledi: geri izleme doğrudan DFS kullanarak çözüm üreten algoritmalar sunar.

### 9.1 Mantık

Çözüme doğru ilerlerken öyle bir noktaya gelinir ki artık ne yapılsa çözüme ulaşılamaz. Hoca bunu "hata yapınca hatadan geri dönmek gerekir" diye anlattı: bir önceki adıma dönülür. Bunun için önceki adımın hatırlanması gerekir; yığıt ya da DFS bunu sağlar.

Soyut çizim (ekrandan, 01:55:00): bir başlangıç (start) noktasından üç farklı noktaya gidilebilir. Biri seçilir; o da başka seçeneklere götürür. Bir yerde çıkmaz sokağa (dead end) girilirse, o noktaya getiren bir önceki noktaya dönülür; orada başka seçenek varsa o denenir, yoksa bir adım daha geri gidilir. Hiç çözüm bulunamayan dallar bitince başa dönülüp diğer yola girilir ve çözüme (solution) ulaşınca işlem tamamlanır. Birden fazla çözüm de olabilir.

### 9.2 Örnek: {1, 2, 3} ile yazılabilecek sayılar

Permütasyon bilgisiyle her rakam bir kez kullanılırsa $3 \cdot 2 \cdot 1 = 6$ sayı olduğu bilinir; burada sayıların listesi de istenir. DFS mantığıyla: 1 seçilir, sonra 2, sonra 3; başka seçenek yoktur (çıkmaz), bir adım geri dönülür. 2'den sonra başka seçenek yoktur, bir adım daha geri dönülür. 1'den sonra 3, sonra 2 seçilir. Böylece 123 ve 132 bulunur. Sonra 2 ile başlanarak 213 ve 231, 3 ile başlanarak 312 ve 321 bulunur. Ağaçta 6 yaprak oluşur; her yaprağa giden dal bir sayıyı verir.

Hoca aynı hatırlama ihtiyacının ağaç gezinme algoritmalarında da (inorder, preorder) bulunduğunu hatırlattı: sol çocuğa gidip sonra düğümün kendisine dönmek için düğümün hatırlanması gerekir; bu da bir yığıtla, geri izlemeye benzer biçimde yapılır. Geri izlemenin arka planında DFS vardır; BFS ise bir sonraki konu olan dal ve sınır (branch and bound) tekniğinde kullanılacaktır.

## 10. Graf işlemlerinin karmaşıklığı ve durum uzayı ağacı

### 10.1 Yer ve zaman

Geri izleme algoritmalarının analizinde yer ve zaman karmaşıklığı gerekir. Ağırlıklı, yönsüz bir graf örneği verildi (ekrandan, 02:10:00): A-B (5), A-C (20), A-D (10), B-C (8). Yönsüz olduğu için komşuluk matrisi simetriktir:

| | A | B | C | D |
|---|---|---|---|---|
| A | 0 | 5 | 20 | 10 |
| B | 5 | 0 | 8 | 0 |
| C | 20 | 8 | 0 | 0 |
| D | 10 | 0 | 0 | 0 |

Komşuluk listesinde A için liste şöyledir: A → [B, 5] → [C, 20] → [D, 10] → NULL. B'nin komşuları A ve C, C'nin komşuları A ve B'dir; yönsüz grafta her kenar iki listede yazılır.

- **Yer:** **Soru:** Matrisin yeri nedir? Bir öğrenci $n^2$ dedi; hoca bunun yanlış olmadığını ama parametrik olarak düğüm kümesinin kardinalitesiyle $|V|^2$ yazılmasını istedi. Liste için bir öğrenci $|V| + |E|$ dedi; doğru.
- **İki düğüm arasında kenar var mı?** Matriste ilgili hücreye bakılır; sıfırdan farklıysa bağlantı vardır. Tek seferde bulunur: $\Theta(1)$. Listede önce düğüm bulunur (1 adım), sonra o düğümün komşuları arasında diğer düğüm aranır. Bu, düğümün derecesine (degree) bağlıdır; örnekte B'nin derecesi 2, A'nınki 3'tür. En kötü durum $O(\text{degree}(v))$ olur; $+1$ sabit terim olduğu için Big-O'da yazılmaz.

### 10.2 Durum uzayı ağacı

Geri izlemede arama uzayını, yani hangi durumdan hangi duruma geçilebileceğini gösteren ağaca **durum uzayı ağacı (state space tree)** denir. Hoca örnek olarak {1, 2, 3, 4} rakamlarıyla yazılabilecek üç basamaklı tek sayılar için ağacın nasıl kurulacağını gösterdi (ekrandan, 02:15:00): 1 seçilince 2 seçilebilir; 2'den sonra son basamağa 3 yazılabilir; dal tükenince geri dönülür, başka seçenekler denenir. Son basamak çift olan dallar (örneğin 4 ile bitenler) çözüm değildir. Hoca bazı üniversite sınavı sorularının bu yolla kolayca çözülebileceğini söyledi.

<!-- BELİRSİZ: Bu örnekte hocanın anlatımı karışık (tek sayı kısıtı ile dal seçimleri tam tutarlı anlatılmadı); ağacın tamamı karede yok. Yalnız genel fikir aktarıldı. -->

## 11. Alt küme toplamı (Subset Sum)

Verilen bir sayı kümesinden, toplamı istenen bir sayıya eşit olan alt kümenin bulunup bulunamayacağı sorulur.

### 11.1 Kaba kuvvet

Bütün alt kümeler (tek elemanlılar, iki elemanlılar, ...) denenir. Kitaptaki örnek (ekrandan, 02:20:00 kenar küçük resmi; altyazı): $A = \{1, 2, 5, 6, 8\}$, $d = 9$. $2^5 = 32$ alt küme denenir ve toplamı 9 olan iki alt küme bulunur: $\{1, 2, 6\}$ ve $\{1, 8\}$ (python ile doğrulandı). Kaba kuvvetin karmaşıklığı $2^n$'dir.

### 11.2 Geri izleme

Örnek (ekrandan, 02:20:00): $S = \{3, 5, 6, 7\}$, $d = 15$. Önce sayılar sıralanır; hoca sıralamanın da bir maliyeti olduğunu ($n \log n$, örneğin Quicksort ile) ve yapılacak işlemin bundan ve $2^n$'den az olup olmadığına bakılması gerektiğini belirtti.

Kök toplam 0'dır. Her sayı için "al" (+) ve "alma" (−) dalları vardır ve DFS ile ilerlenir:

- 3 alınır: toplam 3. 5 alınır: toplam 8. 6 alınır: toplam 14. 7 alınır: toplam 21 > 15, çıkmaz. Geri dönülür; 7 alınmaz: 14, eklenecek başka sayı yok, çıkmaz.
- 14'ten 8'e geri dönülür; bu kez 6 alınmaz: toplam 8. 7 alınır: toplam **15, çözüm bulundu** ($3 + 5 + 7$). 7 alınmazsa toplam 8'de kalır, çıkmaz.
- 3'ü alıp 5'i almama dalında toplam 3'tür (bir öğrenci bu dalın 5'in alınmadığı dal olduğunu sordu; hoca doğruladı).
- 3 alınmazsa toplam 0'dır. 5 alınır: 5; 6 alınır: 11; 7 alınır: 18 olmaz. Geri dönülür; 6 alınmadan 7 alınırsa 12 olur, o da olmaz. Arama böyle sürer.

Hoca bu yolla problemin, DFS'in maliyeti düzeyinde, $2^n$'den çok daha iyi bir duruma indirgenebildiğini söyledi.

> **Ders sonrası not:** Geri izleme pratikte birçok dalı erken keser, ama alt küme toplamı için en kötü durum büyük olasılıkla hâlâ üsteldir ($O(2^n)$); kazanç ortalama ya da tipik durumdadır.

## 12. N-Vezir problemi

### 12.1 Tanım

Satrançta vezir bulunduğu yerden sekiz yöne (yatay, dikey, çapraz) gidebilir. Problem: $n \times n$ bir tahtaya $n$ vezir, birbirini tehdit etmeyecek biçimde yerleştirilmek isteniyor (ekrandan, 02:35:00).

- $1 \times 1$: tek vezir zaten çözümdür.
- $2 \times 2$: bir vezir konunca diğer üç kareye de konamaz; çözüm yok.
- $3 \times 3$: birinci vezir 6 kareyi kapatır; ikinci vezir konabilir ama üçüncüye yer kalmaz; çözüm yok.
- $4 \times 4$ ve üstü: çözüm vardır.

### 12.2 Deneme sayılarının azaltılması (8 vezir)

Tahtada dört yaklaşım karşılaştırıldı (ekrandan, 02:35:00):

1. **Kaba kuvvet:** 64 kareden 8'i seçilir: $\binom{64}{8} = 4\,426\,165\,368$ (yaklaşık 4,5 milyar deneme).
2. **Her satıra bir vezir:** her satırda $n$ seçenek, toplam $n^n$; $8^8 = 16\,777\,216$ (yaklaşık 17 milyon). Hoca bunun "milyardan milyona" bir iniş olduğunu söyledi.
3. **Her satır ve sütuna bir vezir:** ilk satırda $n$, sonra $n-1$, $n-2$, ... seçenek: $n!$; $8! = 40\,320$.
4. **Geri izleme:** durum uzayı ağacıyla 2057 deneme.

Sayılar python ile doğrulandı ($\binom{64}{8}$, $8^8$, $8!$).

### 12.3 4 × 4 için geri izleme

Önce elle denendi: birinci vezir bir kareye konunca o satır, sütun ve çaprazlar kapanır; ikinci vezir uygun bir yere konunca üçüncü satırda yer kalmayabilir. O zaman geri dönülür ve önceki vezir başka yere konur.

Durum uzayı ağacıyla (ekrandan, 02:30:00): boş tahta yığıta eklenir. Birinci vezir 1. satır 1. sütuna konur. İkinci satırda yalnız 3. sütun uygundur; ama bu durumda üçüncü satıra hiç vezir konamaz, çıkmaz. Geri dönülüp ikinci vezir 4. sütuna konur; üçüncü satırda 2. sütun uygundur ama dördüncü satıra konamaz, yine çıkmaz. Birinci veziri 1. sütunda tutan bütün seçenekler tükendiği için başa dönülür. Birinci vezir 1. satır 2. sütuna konur; ikinci vezir 2. satır 4. sütuna, üçüncü vezir 3. satır 1. sütuna, dördüncü vezir 4. satır 3. sütuna konur ve çıkmaza girmeden çözüme ulaşılır:

```text
. Q . .
. . . Q
Q . . .
. . Q .
```

> **Ek bilgi (derste anlatılmadı):** $4 \times 4$ tahtanın iki çözümü vardır: sütunlar (2, 4, 1, 3) ve onun aynadaki görüntüsü (3, 1, 4, 2); python ile doğrulandı. Hoca da "iki farklı çözümü oluyor galiba" dedi.

**Soru:** 8 × 8 için geri izlemede 2057 bulunduğu söylendi; tahta simetrik olduğuna göre çözümler simetrik çiftler hâlinde çıkmaz mı, tek sayı nasıl çıktı? **Cevap:** 2057 çözüm sayısı değil, ilk çözümün bulunduğu deneme sayısıdır; algoritma çözümü bulunca durmuştur. Bir veziri ortaya koymak çaprazlar yüzünden daha çok kareyi kapattığı için bu sayı kolayca formüle edilemez. Hoca bu sayıyı kitaptan aktardığını, bu tür sayıların deneysel olduğunu, yapay zekâ tekniklerinde de (rastgele ama bilgili arama) "şu kadar denemede bulduk" diye yöntemlerin sağlamlığının gösterildiğini söyledi.

## 13. Hamilton devresi problemi

Hamilton devresinde (Hamiltonian circuit) amaç, grafın her düğümünü **tam bir kez** dolaşıp başlangıç noktasına geri dönmektir (ekrandan, 02:40:00). Kaba kuvvetle alt kümeler üzerinden çözülebilir ama bu üstel ($2^n$ düzeyinde) bir çözümdür. Geri izlemeyle durum uzayı ağacı kurulur.

Graf yönsüzdür; düğümler a, b, c, d, e, f, kenarlar (karedeki çizimden): a-b, a-c, a-d, b-c, b-f, c-d, c-e, d-e, e-f.

- a'dan başlanır, a ve b ziyaret edildi olarak işaretlenir. b → c → d → e → f gidilir. f'den başlangıca (a) dönülemez: çıkmaz.
- f'den e'ye geri dönülür; e'nin diğer komşusu c zaten ziyaret edilmiştir. d'ye dönülür; d'nin komşuları a ve c ziyaret edilmiştir. c'ye kadar geri gelinir. Geri dönülürken ziyaret işaretleri de kaldırılır.
- c → e → d gidilir; d'den a'ya gidilebilir ama henüz ziyaret edilmemiş düğümler (f) olduğu için bu çözüm değildir. e → f dalı da çıkmazdır.
- a → b'ye geri dönülüp bu kez b → f seçilir: f → e → c → d → a. Bütün düğümler bir kez ziyaret edilip başlangıca dönülmüştür.

Bulunan Hamilton devresi:

$$a \to b \to f \to e \to c \to d \to a$$

Hoca bu problemi ilkokuldaki "şu şekli kalemi kaldırmadan çizebilir misin?" sorusuna benzetti. Geri izlemede yanlış bir yere gelindiğinde DFS ile bir üst düğüme, gerekirse onun da üstüne geri gelinir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $X = \langle B, A, C, D, B \rangle$ ve $Y = \langle B, D, C, B \rangle$ için LCS tablosunu doldurun; en uzun ortak alt dizinin uzunluğunu ve alt dizileri bulun.

> **Çözüm (derste verildi):** Tablo Bölüm 1.4'tedir. Son hücre 3'tür; geriye izlemeyle BCB ve BDB bulunur.

**Soru 2** (ekrandan, 00:15:00): $X = \text{ATCTGAT}$, $Y = \text{TGCATA}$ dizgilerinin en uzun ortak alt dizisi nedir?

> **Çözüm (derste verildi):** $LCS(X, Y) = \text{TCTA}$, uzunluk 4. (Python kontrolünde TCAT ve TGAT de 4 uzunluklu çözümlerdir.)

**Soru 3** (derste sözlü, 00:14:05): LCS'de $x_i \ne y_j$ iken üstteki $LCS[i-1, j]$ hücresi mi, soldaki $LCS[i, j-1]$ hücresi mi alınmalıdır?

> **Çözüm (derste verildi):** İkisinden büyük olanı alınır; daha uzun ortak alt diziyi o gösterir.

**Soru 4** (ekrandan, 01:25:00): Bölüm 7.3'teki yönlü grafta A'dan G'ye DFS ile yol var mı? Yığıtın değişimini gösterin.

> **Çözüm (derste verildi):** A, B, E, D ziyaret edilir; D, F, E, B yığıttan çıkar; A → C → G ile yol bulunur.

**Soru 5** (ekrandan, 01:40:00): C1 → C3, C2 → C3, C3 → C4, C3 → C5, C4 → C5 ön koşul grafının topolojik sıralamasını DFS ile bulun.

> **Çözüm (derste verildi):** Çıkış sırası C5, C4, C3, C1, C2; tersi C2, C1, C3, C4, C5.

**Soru 6** (derste sözlü, 02:09:51 ve 02:11:05): Ağırlıklı yönsüz bir grafın komşuluk matrisi ve komşuluk listesiyle yer karmaşıklığı nedir? İki düğüm arasında kenar olup olmadığını kontrol etmenin zaman karmaşıklığı nedir?

> **Çözüm (derste verildi):** Yer: matris $\Theta(|V|^2)$, liste $\Theta(|V| + |E|)$. Kenar sorgusu: matris $\Theta(1)$, liste $O(\text{degree}(v))$.

**Soru 7** (ekrandan, 02:20:00): $S = \{3, 5, 6, 7\}$ ve $d = 15$ için alt küme toplamı problemini geri izlemeyle çözün.

> **Çözüm (derste verildi):** $3 + 5 + 7 = 15$. Python ile kontrol edildiğinde toplamı 15 olan tek alt küme $\{3, 5, 7\}$'dir.

**Soru 8** (ekrandan, 02:35:00): 4-vezir problemini geri izlemeyle çözün.

> **Çözüm (derste verildi):** Satır 1 sütun 2, satır 2 sütun 4, satır 3 sütun 1, satır 4 sütun 3.

**Soru 9** (ekrandan, 02:40:00): Bölüm 13'teki grafta a'dan başlayan bir Hamilton devresi bulun.

> **Çözüm (derste verildi):** $a \to b \to f \to e \to c \to d \to a$.

**Soru 10** (derste sözlü, 02:45:58; quiz sorusu): Sırt çantası problemini dinamik programlama ve açgözlü yöntemle çözen bir C programı yazın. Tek bir C dosyasında iki ayrı fonksiyon olacak; her yöntem için maksimum kazanç ve alınan eşyalar (örneğin 3. eşya, 5. eşya) bulunacak. Veriler bir metin dosyasından okunacak: ilk satırda çantanın alabileceği en büyük ağırlık, sonraki her satırda eşyanın kimliği (ID), ağırlığı ve değeri. Eşya sayısı dosyaya göre değişebilmeli.

> **Çözüm (derste verilmedi):** Aşağıdaki program ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve iki küçük girdiyle çalıştırıldı. Birinci girdide (kapasite 5; eşyalar (ağırlık, değer): (2, 12), (1, 10), (3, 20), (2, 15)) iki yöntem de 37 verdi (eşyalar 1, 2, 4). İkinci girdide (kapasite 50; (10, 60), (20, 100), (30, 120)) dinamik programlama 220 (eşyalar 2, 3), açgözlü yöntem 160 (eşyalar 1, 2) verdi; açgözlü yöntemin optimal olmayabileceği burada görülür.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct { int id, w, v; } Item;

int dpKnapsack(Item *it, int n, int C, int *secilen) {
    int i, j;
    int **V = malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) V[i] = calloc(C + 1, sizeof(int));
    for (i = 1; i <= n; i++)
        for (j = 0; j <= C; j++) {
            V[i][j] = V[i - 1][j];
            if (it[i - 1].w <= j && V[i - 1][j - it[i - 1].w] + it[i - 1].v > V[i][j])
                V[i][j] = V[i - 1][j - it[i - 1].w] + it[i - 1].v;
        }
    int best = V[n][C];
    for (i = n, j = C; i > 0; i--) {          /* geriye izleme */
        secilen[i - 1] = (V[i][j] != V[i - 1][j]);
        if (secilen[i - 1]) j -= it[i - 1].w;
    }
    for (i = 0; i <= n; i++) free(V[i]);
    free(V);
    return best;
}

static int oranKarsilastir(const void *a, const void *b) {
    const Item *x = a, *y = b;
    long l = (long)y->v * x->w, r = (long)x->v * y->w;  /* v/w azalan */
    return (l > r) - (l < r);
}

int greedyKnapsack(Item *it, int n, int C, int *secilen) {
    Item *s = malloc(n * sizeof(Item));
    int i, kalan = C, top = 0;
    for (i = 0; i < n; i++) { s[i] = it[i]; secilen[i] = 0; }
    qsort(s, n, sizeof(Item), oranKarsilastir);
    for (i = 0; i < n; i++)
        if (s[i].w <= kalan) {
            kalan -= s[i].w; top += s[i].v;
            for (int k = 0; k < n; k++) if (it[k].id == s[i].id) secilen[k] = 1;
        }
    free(s);
    return top;
}

int main(int argc, char **argv) {
    FILE *f = fopen(argc > 1 ? argv[1] : "input.txt", "r");
    if (!f) { perror("input"); return 1; }
    int C, n = 0, cap = 8;
    Item *it = malloc(cap * sizeof(Item));
    if (fscanf(f, "%d", &C) != 1) return 1;
    while (fscanf(f, "%d %d %d", &it[n].id, &it[n].w, &it[n].v) == 3)
        if (++n == cap) it = realloc(it, (cap *= 2) * sizeof(Item));
    fclose(f);
    int *sec = malloc(n * sizeof(int)), i;
    printf("DP: %d ->", dpKnapsack(it, n, C, sec));
    for (i = 0; i < n; i++) if (sec[i]) printf(" %d", it[i].id);
    printf("\nGreedy: %d ->", greedyKnapsack(it, n, C, sec));
    for (i = 0; i < n; i++) if (sec[i]) printf(" %d", it[i].id);
    printf("\n");
    free(sec); free(it);
    return 0;
}
```

Dinamik programlama kısmı $V[i][j] = \max(V[i-1][j],\ V[i-1][j - w_i] + v_i)$ bağıntısını kullanır ve $\Theta(nC)$ zaman ile yer ister; açgözlü kısım $v_i / w_i$ oranına göre sıralama nedeniyle $O(n \log n)$'dir.

## Dersin Toparlaması

Ders, dinamik programlamanın son örneği olan en uzun ortak alt dizi problemiyle başladı: iki dizginin önekleri bir tabloda karşılaştırıldı, eşitlikte çapraz hücreye bir eklendi, eşitsizlikte üst ve sol hücreden büyüğü alındı; alt dizinin kendisi tablodan geriye izlenerek bulundu ve çözüm $\Theta(mn)$ zaman ile yer istedi. Ardından açgözlü yöntem tanıtıldı: her adımda o an en kârlı seçimi yapan, uygun ama her zaman optimal olmayan bir yöntemdir. Para bozma, sırt çantası (kârlılık oranına göre), Prim, Kruskal, Dijkstra ve Huffman bu yöntemin örnekleri olarak anıldı.

Dersin ikinci yarısında graflar, saklama biçimleri (matris ve liste) ve gezinme algoritmaları (BFS ve DFS) tekrar edildi. DFS ile ve azalt ve fethet (kaynak çıkarma) ile topolojik sıralama yapıldı. Son olarak DFS'e dayanan geri izleme yöntemi; durum uzayı ağacı, alt küme toplamı, N-vezir ve Hamilton devresi örnekleriyle anlatıldı. Bir sonraki konu, BFS'e dayanan dal ve sınır (branch and bound) yöntemidir; ardından dizgi eşleştirme algoritmaları, NP-tamlık ve alt sınır gibi konular gelecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
