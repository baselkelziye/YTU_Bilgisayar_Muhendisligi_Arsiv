# Ders 6 Genişletilmiş Notu: Büyük Graf Analizi ve PageRank: Stokastik Matris, Kuvvet Yinelemesi ve Işınlanma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri: Kaynak Kitap ve Graf Verisi
- 2. Graf Verisi Örnekleri
- 3. Web'de Arama ve Sıralama İhtiyacı
- 4. PageRank'in Temel Fikirleri
- 5. Basit Özyinelemeli (Akış) Formülasyonu
- 6. Matris Formülasyonu
- 7. Özvektör Formülasyonu ve Kuvvet Yinelemesi
- 8. Rastgele Gezgin Yorumu ve Durağan Dağılım
- 9. PageRank'in Sorunları: Örümcek Tuzağı ve Çıkmaz Uç
- 10. Çözüm: Işınlanma ve Son PageRank Denklemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yeri: Kaynak Kitap ve Graf Verisi

Ders, kaynak kitap Mining of Massive Datasets'in (Leskovec, Rajaraman, Ullman) bölümlerini sırayla izliyor. Hoca her dersin başında kitabın sayfasını açıp nerede olunduğunu gösteriyor. Bu derste 5. bölüm, "Link Analysis" (bağlantı analizi) işlendi. Kitabın sayfasında her bölümün PDF'i, yazarların slaytları ve video anlatımları bulunuyor (ekrandan, 00:10:00). Hoca, kitabın ilgili bölümlerinin ve dersin sayfasına konan materyallerin takip edilmesi gerektiğini söyledi.

Dersin konusu, tek bir makineye ya da tek bir fiziksel belleğe sığmayan büyük grafların analizidir. Bu analizin bir türü bağlantı analizidir. Derste özellikle PageRank puanının nasıl hesaplandığı öğrenildi.

Hoca, dönemin başında gösterdiği büyük veri türleri slaytına döndü. Daha önce yüksek boyutlu veri (locality sensitive hashing) ve sonsuz veri, yani akış verisi konuşulmuştu. Şimdi graf verisine geçiliyor. Slaytta graf verisinin altında üç konu var: PageRank/SimRank, topluluk bulma (community detection) ve spam bulma (spam detection) (ekrandan, 00:15:00). Derste yalnız PageRank anlatıldı. Hoca, topluluk ve spam bulma için graf verisini işleyen algoritmaların kitap bölümünde bulunduğunu belirtti.

## 2. Graf Verisi Örnekleri

### 2.1 Graf, düğüm ve kenar

Her graf verisinde düğümler (node) ve kenarlar (edge) vardır. Kenarlar düğümler arasındaki bağlantılardır. Kenarın bir yönü varsa, yani bir düğümden diğerine ok varsa, graf yönlüdür (directed). Kenarın yönü yoksa graf yönsüzdür (undirected).

Hoca bunu sosyal ağlarla örnekledi. Facebook arkadaşlık grafı yönsüzdür, çünkü iki kişi arasındaki arkadaşlığı kimin başlattığı bilinmez. Twitter ise yönlüdür, çünkü kimin kimi takip ettiği, yani bağlantıyı kimin başlattığı bilinir.

### 2.2 Grafların özet bilgisi

Hoca birkaç görselleştirme gösterdi. Birincisi bir web günlüğü (blog) grafıdır; düğümler iki ayrı renkte iki kümeye ayrılmış, aralarında az sayıda kenar var. Hoca, ilgilendiğimiz şeyin bu tür büyük ölçekli veriyi işleyip böyle bir bilgi çıkarmak olduğunu söyledi. Bu özet bilgi bir görselleştirme, düğümlerin sıralaması ya da graf hakkında istatistik veren bir tablo olabilir. Kısacası büyük veriden çıkarılan işe yarar bir şeydir.

İkinci örnek atıf ağıdır ("Citation networks and Maps of science", Börner ve arkadaşları, 2012) (ekrandan, 00:20:00). Her makalenin bir kaynakça bölümü vardır. Her makale bir düğüm, kaynakçadaki her atıf bir kenar alınırsa bir graf elde edilir. Görselleştirmede her renk bir disiplindir (kimya, biyoloji, beyin araştırmaları, sosyal bilimler vb.). Hoca, disiplinlerin çoğunlukla kendi içinde birbirine atıf yaptığını, disiplinler arası çalışmanın az olduğunu yorumladı. Bu da graf verisinden çıkarılmış bir özet bilgidir.

### 2.3 Donanım düzeyinde graf: iletişim ağları

Şimdiye kadarki örnekler yazılım düzeyindeydi. Graf, donanım düzeyinden de çıkarılabilir. İnternet altyapısını sağlayan sunucular birbirine bağlıdır. Her sunucu bir düğüm, sunucular arasındaki her bağlantı bir kenar alınırsa interneti gösteren bir graf elde edilir. Bu graf üzerinde de bağlantı analizi yapılabilir.

### 2.4 Web grafı

Derste odaklanılan graf türü web grafıdır. Web, HTML sayfalarından oluşur ve her sayfada başka sayfalara giden köprüler (hyperlink) vardır. Köprüye tıklayınca bir sayfadan diğerine gidilir. Her sayfa bir düğüm, her köprü bir kenar alınınca web yapısından bir ağ oluşur. Bu ağ üzerinde bağlantı analizi yapılarak her sayfanın önemi bulunmak istenir.

## 3. Web'de Arama ve Sıralama İhtiyacı

### 3.1 Web'i düzenlemenin iki yolu

Slaytta "Web nasıl düzenlenir?" sorusu soruluyor (ekrandan, 00:25:00). Bugün web'de milyarlarca sayfa vardır ve biz belirli bir sayfayı arıyoruz.

- **İlk deneme: insanların düzenlediği web dizinleri.** Yahoo, DMOZ, LookSmart gibi dizinlerde bir kategoriden başlayıp alt kategorilere inerek aranan şeye ulaşılır.
- **İkinci deneme: web araması.** Bugün internet kullanan hemen herkes her gün bunu yapar: arama motoruna anahtar kelimeler girilir ve motor sonuçları getirir.

### 3.2 Bilgi erişim ve web'in farkı

Web arama motoru temelde bir bilgi erişim (information retrieval) motorudur. Bilgi erişim, aynı fikrin küçük bir sürümüdür ve küçük, güvenilir bir belge kümesinde çalışır (gazete makaleleri, patentler vb.). Hoca şu örneği verdi: bir şirkette binlerce PDF belgesi vardır ve bir bilgi erişim motoru sorguyla ilgili belgeleri bulur. Bu belgeler azdır ve güvenilirdir, çünkü şirket çalışanları tarafından girilir ve denetlenir.

Web ise çok büyüktür ve güvenilmez belgelerle doludur. Spam sayılabilecek sayfalar vardır: bazı kişiler, sayfaları bir sorguyla ilgili olmadığı hâlde arama sonuçlarında görünsün diye sayfa içeriğini değiştirir.

### 3.3 Web aramasının iki zorluğu

- **Kime güvenilecek?** Anahtar kelimeler girildiğinde milyonlarca sayfa sorguyla eşleşebilir. İçeriği güvenilir ve bakmaya değer, yani spam olmayan sayfalar bulunmalıdır.
- **En iyi cevap hangisi?** Güvenilir sayfalar içinde de sorguyla eşleşen çok sayfa olabilir. Biz en iyi cevabı istiyoruz.

İkisi için de sayfaları sıralamak gerekir. İyi bir sıralama yöntemi hem güvenilir sayfaları hem de sorguya en iyi uyan sayfaları listenin üst kısmına koymalıdır.

### 3.4 Bağlantı yapısına göre sıralama

Slaytta "Bütün web sayfaları eşit derecede önemli değildir" yazıyor ve bilinmeyen kişisel bir site ile stanford.edu karşılaştırılıyor (ekrandan, 00:30:00). Yanındaki küçük grafta mavi düğüm çok sayıda bağlantı alıyor, kırmızı düğüm ise yalnız bir bağlantı alıyor.

Hoca bunu şöyle açıkladı: web sayfanız önemli ve değerliyse birçok kişi ona bağlantı verir, yani sayfanızın bağlantılılığı yüksek olur. Az bağlantı alan bir sayfa ise o kadar önemli değildir ya da pek az kişi tarafından izlenir. Stanford Üniversitesi'nin sitesi, bilinmeyen bir siteye göre çok daha fazla bağlantı alır. Slaytın sonucu: "Sayfaları bağlantı yapısına göre sıralayalım."

Bağlantı analiziyle düğümlerin önemini hesaplayan birkaç algoritma vardır: PageRank, HITS, konuya özgü (topic-specific) PageRank ve web spam bulma algoritmaları. Derste yalnız PageRank incelendi.

## 4. PageRank'in Temel Fikirleri

### 4.1 Bağlantı bir oydur

Birinci fikir: her bağlantı bir oy sayılır. Bir sayfanın gelen bağlantısı (in-link) ne kadar çoksa o kadar önemlidir. Burada sayfanın verdiği değil, aldığı bağlantılara bakılır. Hoca önceki örneğe döndü: Stanford sitesi on binlerce gelen bağlantıya sahipken bilinmeyen sitenin bir tane gelen bağlantısı var. <!-- BELİRSİZ: Hocanın söylediği gelen bağlantı sayısı altyazıda bir yerde "23,000", bir yerde "23,400" diye geçiyor; bu slaytın karesi yok. --> Bağlantının içeriğine bakmadan, yalnız gelen bağlantı sayısına bakarak birincinin çok daha önemli olduğu söylenebilir, çünkü binlerce farklı site sahibi ona bağlantı vermiştir.

### 4.2 Bütün oylar eşit değildir

İkinci fikir: önemli sayfalardan gelen bağlantılar daha çok sayılır. Hoca bunu slayttaki 11 düğümlü örnekle gösterdi (ekrandan, 00:35:00). Bu grafta toplam puan 100'dür ve PageRank algoritması bu 100 puanı düğümlere dağıtır. Görselleştirmede dairenin büyüklüğü PageRank puanıyla orantılıdır; bu yalnız görsel amaçlıdır. Puanlar şöyledir:

| Düğüm | Puan | Gelen bağlantılar (slayttan) |
|---|---|---|
| B | 38,4 | C, D, E, F ve üç küçük düğüm |
| C | 34,3 | yalnız B |
| E | 8,1 | F ve üç küçük düğüm |
| D | 3,9 | E |
| F | 3,9 | E ve iki küçük düğüm |
| A | 3,3 | D |
| beş küçük düğüm | her biri 1,6 | hiç yok |

B en çok gelen bağlantıyı aldığı için en yüksek puanı alır. C ise yalnız bir bağlantı alır, ama bu bağlantı grafın en önemli düğümü B'den gelir. Bu yüzden C de çok yüksek puan alır. Hiç gelen bağlantısı olmayan küçük düğümler ise en düşük önemdedir.

> **Ders sonrası not:** Altyazıda bu yer "node G" diye geçiyor. Slaytta G adlı bir düğüm yok; tek bağlantısını B'den alan düğüm C'dir.

PageRank bu iki fikri birleştirir: çok bağlantı almak önem kazandırır ve önemli sayfalardan bağlantı almak daha çok önem kazandırır.

## 5. Basit Özyinelemeli (Akış) Formülasyonu

### 5.1 Oyları paylaştırmak

Hoca PageRank'in en basit sürümünden başlayıp daha karmaşık sürümlerine geçeceğini söyledi. Slayttaki kurallar şunlardır (ekrandan, 00:40:00):

- Her bağlantının oyu, kaynak sayfasının önemiyle orantılıdır.
- Önemi $r_j$ olan $j$ sayfasının $n$ çıkış bağlantısı varsa her bağlantı $r_j/n$ oy alır.
- $j$ sayfasının kendi önemi, gelen bağlantılarındaki oyların toplamıdır.

Slayttaki küçük grafta kırmızı $j$ düğümüne $i$ ve $k$ düğümleri bağlantı veriyor. $i$'nin puanı $r_i$, $k$'nin puanı $r_k$'dir. $j$'nin puanını hesaplarken yalnız $j$'ye bağlantı veren düğümlerin puanları sayılır. Her düğüm puanını çıkış bağlantılarına eşit böler. $i$'nin 3 çıkış bağlantısı olduğu için $j$'ye $r_i/3$ geçer. $k$'nin 4 çıkış bağlantısı olduğu için $j$'ye $r_k/4$ geçer. Böylece:

$$r_j = \frac{r_i}{3} + \frac{r_k}{4}$$

Aynı şekilde $j$ de üç mavi düğüme bağlantı verdiği için her birine $r_j/3$ geçirir.

Genel denklem şudur: $d_i$, $i$ düğümünün çıkış bağlantısı sayısı olmak üzere

$$r_j = \sum_{i \to j} \frac{r_i}{d_i}$$

Yani $j$'ye bağlantı veren her düğümün puanı, o düğümün çıkış sayısına bölünür ve bu değerler toplanır.

### 5.2 y, a, m örneği ve denklem sistemi

Slayttaki küçük web grafının üç düğümü var: $y$, $a$ ve $m$ (ekrandan, 00:45:00). Bağlantılar şöyledir: $y$ kendine ve $a$'ya, $a$ ise $y$'ye ve $m$'ye bağlantı verir; $m$ yalnız $a$'ya bağlantı verir. Genel denklem bu grafa uygulanınca üç akış denklemi çıkar:

$$r_y = \frac{r_y}{2} + \frac{r_a}{2}, \qquad r_a = \frac{r_y}{2} + r_m, \qquad r_m = \frac{r_a}{2}$$

Hoca bunları tek tek açıkladı. $y$'nin iki çıkış bağlantısı olduğu için $r_y$ ikiye bölünür; $a$'nın da iki çıkışı olduğu için $r_a/2$ eklenir. $a$, $m$'den bir bağlantı alır; $m$'nin tek çıkışı olduğu için $r_m/1 = r_m$ eklenir; $y$'den de $r_y/2$ gelir. $m$ ise yalnız $a$'dan bağlantı alır: $r_m = r_a/2$.

Üç denklem ve üç bilinmeyen ($r_y$, $r_a$, $r_m$) var, ama sabit terim yok. Bu durumda tek bir çözüm yoktur; bütün çözümler birbirinin katıdır. Tek çözüm için ek bir kısıt gerekir: bütün PageRank puanlarının toplamı 1 olmalıdır.

$$r_y + r_a + r_m = 1$$

Bu dördüncü denklemle sistemin tek çözümü vardır (ekrandan, 00:45:00):

$$r_y = \frac{2}{5}, \qquad r_a = \frac{2}{5}, \qquad r_m = \frac{1}{5}$$

Kontrol (ara adım eklendi): $r_m = r_a/2 = 1/5$ ve $r_a = r_y/2 + r_m = 1/5 + 1/5 = 2/5$ olur. Birinci denklemden $r_y/2 = r_a/2$, yani $r_y = r_a$ çıkar. Toplam $2/5 + 2/5 + 1/5 = 1$ eder. Bu çözüm python ile doğrulandı.

Slayta göre Gauss eleme yöntemi küçük örneklerde çalışır, ama web boyutundaki büyük graflar için daha iyi bir yönteme, yeni bir formülasyona ihtiyaç vardır.

## 6. Matris Formülasyonu

### 6.1 Stokastik komşuluk matrisi

Web grafı gibi bir graf genellikle bir matrisle, komşuluk matrisiyle (adjacency matrix) gösterilir. Matrisin sütunları ilk düğümden son düğüme kadar bütün düğümlerdir; satırları da öyle. Bir düğümden diğerine bağlantı varsa ilgili hücrede sıfırdan farklı bir değer, yoksa sıfır bulunur.

Sıfırdan farklı değer, bağlantıyı veren düğümün çıkış sayısının tersidir. Slayttaki tanım şöyledir (ekrandan, 00:50:00): $i$ sayfasının $d_i$ çıkış bağlantısı olsun.

$$i \to j \text{ ise } M_{ji} = \frac{1}{d_i}, \qquad \text{değilse } M_{ji} = 0$$

Hocanın örneğinde bir düğümün üç çıkış bağlantısı var; bu yüzden o düğümün sütununda üç tane $1/3$ bulunur, geri kalan değerler sıfırdır. Bu sütunun değerleri toplanınca $1/3 + 1/3 + 1/3 = 1$ çıkar. Bu, bütün sütunlar için geçerlidir. Her sütununun toplamı 1 olan matrise stokastik matris denir; $M$ bir sütun stokastik matristir (column stochastic matrix).

### 6.2 Sıralama vektörü ve $r = M \cdot r$

Sıralama vektörü $r$, her sayfa için bir eleman taşır. $r_i$, $i$ sayfasının önem puanıdır ve $\sum_i r_i = 1$'dir.

Hoca $r = M \cdot r$ denkleminin nereden geldiğini şöyle açıkladı. $M$'nin $j$. satırına bakalım. Bu satırdaki sıfırdan farklı değerler, $j$'ye bağlantı veren düğümlerin $1/d_i$ değerleridir. $j$'nin puanını hesaplarken, $j$'ye bağlantı veren düğümlerin orantılı puanlarını toplamıştık. $j$. satır $r$ sütun vektörüyle eleman eleman çarpılıp sonuçlar toplanınca tam olarak $\sum_{i \to j} r_i/d_i$, yani $r_j$ elde edilir. Bu işlem bir eleman için yapılabiliyorsa her eleman için de yapılabilir. Böylece bütün akış denklemleri tek bir matris denklemiyle yazılır:

$$r = M \cdot r$$

Burada soldaki $r$ ve sağdaki $r$ aynı sıralama vektörüdür (sütun vektörü), $M$ ise stokastik komşuluk matrisidir.

## 7. Özvektör Formülasyonu ve Kuvvet Yinelemesi

### 7.1 Özvektör

$r = M \cdot r$ doğrusal cebirde bilinen bir denklemdir. Slayttaki notta, $Ax = \lambda x$ ise $x$'in $\lambda$ özdeğerine karşılık gelen bir özvektör olduğu yazıyor (ekrandan, 00:55:00). Burada matris bir sütun vektörüyle çarpılır ve sonuç, aynı vektörün $\lambda$ katı olur.

Bizim denklemimizde $\lambda = 1$'dir. Bu yüzden sıralama vektörü $r$, stokastik web matrisi $M$'nin bir özvektörüdür. Aslında özdeğeri 1 olan birinci, yani baş (principal) özvektörüdür. Slayta göre $M$ sütun stokastik olduğu için en büyük özdeğeri 1'dir. Slayttaki gerekçe şudur: $r$ birim uzunluktadır ve $M$'nin her sütunu 1'e toplanır, bu yüzden $Mr \le 1$'dir. Slaytın sonucu: artık $r$ verimli biçimde çözülebilir; yöntemin adı kuvvet yinelemesidir (power iteration).

> **Ek bilgi (derste anlatılmadı):** Buradaki "birim uzunluk", büyük olasılıkla $L_1$ normuna göre, yani elemanlarının toplamı 1 olacak biçimde anlaşılmalıdır. Negatif olmayan bir vektör sütun stokastik bir matrisle çarpılınca eleman toplamı korunur.

### 7.2 Kuvvet yinelemesi yöntemi

Özvektör formülasyonu üzerinde bilinen bir teknik olan kuvvet yinelemesi uygulanır ve baş özvektör, yani $r$ bulunur. Slayttaki adımlar şunlardır (ekrandan, 01:10:00): düğümleri sayfa, kenarları köprü olan $N$ düğümlü bir web grafı verilmiş olsun.

- **Başlat:** $r^{(0)} = [1/N, \dots, 1/N]^T$. Vektörün bütün elemanları $1/N$'dir; $N$ grafın toplam düğüm sayısıdır. Üç düğümlü örnekte her eleman $1/3$ olur. Slaytta satır vektör yazılıp transpozu alındığı için bu bir sütun vektörüdür.
- **Yinele:** $r^{(t+1)} = M \cdot r^{(t)}$. Eleman düzeyinde: $r_j^{(t+1)} = \sum_{i \to j} r_i^{(t)} / d_i$; $d_i$, $i$ düğümünün çıkış derecesidir.
- **Dur:** $|r^{(t+1)} - r^{(t)}|_1 < \varepsilon$ olduğunda. Burada $|x|_1 = \sum_{1 \le i \le N} |x_i|$, $L_1$ normudur; Öklid normu gibi başka bir vektör normu da kullanılabilir.

Hoca adımları şöyle anlattı: başlangıç vektörü $r^{(0)}$, $M$ ile çarpılır ve bir sonraki durum $r^{(1)}$ elde edilir. Sonra iki vektörün farkı hesaplanır. Fark küçük bir eşikten ($\varepsilon$) küçükse durulur; bu, sıralama vektörünün sabit bir değere yakınsadığı anlamına gelir. Değilse $r^{(1)}$ yeniden $M$ ile çarpılıp $r^{(2)}$, sonra $r^{(3)}$ bulunur. Her adımda farkın $\varepsilon$'dan küçük olup olmadığına bakılır.

### 7.3 Kuvvet yinelemesi örneği (y, a, m)

Hoca yöntemi aynı y, a, m grafına uyguladı. Bu grafın stokastik komşuluk matrisi şudur (satırlar ve sütunlar $y, a, m$ sırasıyla). $y$'nin iki çıkış bağlantısı var: biri kendine, biri $a$'ya; bu yüzden sütununda iki tane $1/2$ bulunur. $a$'nın da iki çıkışı var ($y$ ve $m$). $m$'nin tek çıkışı $a$'ya gider, bu yüzden değeri $1/1 = 1$'dir.

$$M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix}$$

Başlangıçta her elemana $1/3$ verilir ve vektör art arda $M$ ile çarpılır. Hocanın gösterdiği tablonun karesi yok; aşağıdaki ara değerler python ile hesaplandı (ara adım eklendi):

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 | 1/2 | 1/6 |
| 2 | 5/12 | 1/3 | 1/4 |
| 3 | 3/8 | 11/24 | 1/6 |
| ... | ... | ... | ... |
| yakınsama | 2/5 | 2/5 | 1/5 |

Son vektör bir öncekiyle hemen hemen aynı olunca vektör yakınsamış demektir ve bu değerler grafın sıralama değerleri olarak kullanılır. Her değer, o düğümün graftaki önemini gösterir. Yakınsanan değerler, 5.2'de denklem sistemiyle bulunan $2/5,\ 2/5,\ 1/5$ çözümüyle aynıdır.

## 8. Rastgele Gezgin Yorumu ve Durağan Dağılım

### 8.1 Geri tuşu olmayan tarayıcı

Şimdiye kadar PageRank hesabı önem açısından konuşuldu. Hoca aynı şeyi rastgele yürüyüş (random walk), yani rastgele web gezgini (random web surfer) açısından anlattı.

Bir web tarayıcısında başka bir sayfaya gitmenin iki yolu vardır: adres çubuğuna bir URL yazmak ya da sayfadaki bağlantılardan birine tıklamak. Hoca şunu düşünmemizi istedi: tarayıcıda geri tuşu ve URL yazılacak metin kutusu olmasın. O zaman bir sayfadan diğerine gitmenin tek yolu, sayfadaki bağlantılardan birine tıklamaktır. Geri gidilemez, yalnız ileri gidilir. Bağlantılı bir web grafı vardır ve gezgin bunun üzerinde rastgele yürür.

Slayttaki tanım şöyledir (ekrandan, 01:15:00):

- Herhangi bir $t$ anında gezgin bir $i$ sayfasındadır.
- $t+1$ anında gezgin, $i$'nin çıkış bağlantılarından birini düzgün rastgele (uniformly at random) seçip izler.
- $i$'den bağlantı verilen bir $j$ sayfasına varır.
- Süreç sonsuza kadar tekrarlanır.

### 8.2 Bir sayfada bulunma olasılığı

Slaytta $i_1, i_2, i_3$ sayfaları kırmızı $j$ sayfasına bağlantı veriyor. Gezgin $i_1$ sayfasındaysa $j$'ye gitme olasılığı nedir? Gezginin $t$ anında $i_1$'de bulunması için bir olasılık vardır. $i_1$'in kaç çıkış bağlantısı varsa gezgin onlardan birini seçeceği için bu olasılık $1/d_{i_1}$ ile çarpılır. Aynısı $i_2$ ve $i_3$ için de geçerlidir. Buna göre gezginin $t+1$ anında $j$ sayfasında bulunma olasılığı, önceki sayfalarda bulunma olasılıklarının o sayfaların çıkış sayılarına bölümlerinin toplamıdır:

$$r_j = \sum_{i \to j} \frac{r_i}{d_{out}(i)}$$

Bu, önem açısından yazılan formülün aynısıdır; burada yalnız olasılık açısından yorumlanır.

$p(t)$, $i$. elemanı gezginin $t$ anında $i$ sayfasında bulunma olasılığı olan vektördür. Yani $p(t)$ sayfalar üzerinde bir olasılık dağılımıdır.

**Soru:** Geri gitme tuşunu göz ardı etmeyen algoritmalar varsa, onlar da grafı yönlü olarak mı düşünüyor? **Cevap:** Rastgele gezgini konuşurken hep çıkış bağlantıları üzerinden ileri gidilir; PageRank hesabı mutlaka yönlü graf üzerinde düşünülür. Bir düğümün önemi ona gelen bağlantılardan ve bu bağlantıların öneminden hesaplanır. Bu yüzden PageRank gibi sıralama hesaplayan algoritmaların yönlü graf üzerinde çalışması gerekir. Facebook arkadaşlık grafı ya da LinkedIn bağlantı grafı gibi yönsüz graflarda kullanılamaz. Ama Facebook'ta birini takip etmek mümkündür; takip tabanlı bir graf kullanılırsa hesaplanabilir. Twitter ve web grafı üzerinde de hesaplanabilir.

### 8.3 Durağan dağılım

Gezgin $t+1$ anında nerededir? Bir bağlantıyı düzgün rastgele izlediği için (ekrandan, 01:20:00):

$$p(t+1) = M \cdot p(t)$$

Yani $r = M r$ denkleminde $r$ yerine $p(t)$ yazılır. $t$ anında gezginin her sayfada bulunma olasılığını veren vektör $M$ ile çarpılınca $t+1$ anındaki olasılıklar elde edilir.

Bu denkleme kuvvet yinelemesi uygulanırsa belirli bir yineleme sonunda öyle bir duruma ulaşılır ki

$$p(t+1) = M \cdot p(t) = p(t)$$

olur. Bu durumda $p(t)$ rastgele yürüyüşün durağan dağılımıdır (stationary distribution). Artık vektör yakınsamıştır ve değişmeyecektir. Orijinal sıralama vektörümüz de $r = M \cdot r$ denklemini sağladığı için $r$, rastgele yürüyüşün durağan dağılımıdır.

### 8.4 Markov zinciri teoremi

Bu sonucun söylenebilmesi için $M$ matrisinin belirli koşulları sağlaması gerekir. Sağlıyorsa kuvvet yinelemesiyle sonunda bulunan vektör tektir ve başta seçilen değerler ne olursa olsun hep aynı vektör çıkar. Hoca örnekle açıkladı: başlangıçta değerleri $1/N$ seçtik; farklı değerler seçseydik bile belirli bir yineleme sonunda yine aynı değere ulaşırdık, yalnız yineleme sayısı değişebilirdi. Bunu söyleyen teoreme Markov zinciri teoremi ya da rastgele yürüyüş teorisi denir.

Şimdi cevaplanması gereken sorular şunlardır:

- Kuvvet yinelemesi bu denklemde yakınsar mı?
- Yakınsıyorsa, yakınsadığı şey istediğimiz şey midir?
- Sonuçlar makul müdür?

Hoca, matrisin hangi koşulları sağlaması gerektiğini açıklamadan önce web'de PageRank sonucunu bozan sorunları anlattı.

## 9. PageRank'in Sorunları: Örümcek Tuzağı ve Çıkmaz Uç

### 9.1 Örümcek tuzağı (spider trap)

Rastgele gezgin bir düğümden başlayıp belirli sayıda adım attıktan sonra hep aynı düğüme dönüyorsa örümcek tuzağı vardır. Slayttaki örnekte $a$ ile $b$ birbirine bağlantı verir (ekrandan, 01:25:00). Gezgin $a$'dan başlarsa iki adımda hep $a$'ya döner. Bu sayı iki değil, üç ya da dört adım da olabilir; gezgin aynı düğüme dönüyorsa sorun vardır.

Bu grafta kuvvet yinelemesi uygulanınca vektör şöyle değişir (ekrandan, 01:25:00):

| Yineleme | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| $r_a$ | 1 | 0 | 1 | 0 |
| $r_b$ | 0 | 1 | 0 | 1 |

Vektör iki durum arasında gidip gelir, yakınsamaz. Oysa durağan dağılımı bulmak için PageRank'in belirli değerlere yakınsaması gerekir.

### 9.2 Çıkmaz uç (dead end)

Bir düğüm başka düğümlerden bağlantı alıyor ama grafa hiç bağlantı vermiyorsa o düğüm bir çıkmaz uçtur. Hocanın küçük örneğinde bir düğüm diğerine bağlantı verir, o düğüm ise geri hiçbir bağlantı vermez. Hoca, bu bağlantı kesilirse grafın indirgenebilir (reducible) olduğunu söyledi, çünkü $b$ grafın geri kalanını etkilemez.

Bu grafta başlangıç puanları 1 ve 0'dır. Kuvvet yinelemesi uygulanınca vektör $(1, 0) \to (0, 1) \to (0, 0)$ biçiminde ilerler (ara adım eklendi; $a \to b$ yönü varsayılarak python ile hesaplandı) ve sıfıra yakınsar. Yani bir şeye yakınsar ama istediğimiz şeye değil: amaç düğümlerin göreli önemini görmektir, sıfır ve sıfır ise hiçbir göreli önem vermez. <!-- BELİRSİZ: Çıkmaz uç örneğinin slaytı karede yok; ara değerler hocanın "başlangıç 1 ve 0, sonunda 0 ve 0" anlatımından kuruldu. -->

Özetle:

- **Örümcek tuzağında** vektör yakınsamaz.
- **Çıkmaz uçta** vektör sıfıra yakınsar; bu da istenen sonuç değildir.

### 9.3 y, a, m grafında örümcek tuzağı

Hoca, y, a, m grafının bir sürümüne döndü: bu sürümde $m$ yalnız kendine bağlantı verir. Gezgin $m$'ye bir kez ulaşırsa her adımda yine $m$'ye döner ve orada takılı kalır. Bu bir örümcek tuzağıdır. Kuvvet yinelemesi bu matriste bütün puanı $m$'de toplar. Python ile hesaplanan ara değerler (ara adım eklendi):

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 | 1/6 | 1/2 |
| 2 | 1/4 | 1/6 | 7/12 |
| 3 | 5/24 | 1/8 | 2/3 |
| yakınsama | 0 | 0 | 1 |

<!-- BELİRSİZ: Hocanın bu sırada gösterdiği tablonun karesi yok; altyazıda bu bölüm kısmen anlaşılmıyor. Değerler slayttaki matrisle python ile hesaplandı. -->

## 10. Çözüm: Işınlanma ve Son PageRank Denklemi

### 10.1 Örümcek tuzağı için rastgele ışınlanma

Örümcek tuzağını çözmek için gerçek tarayıcıya dönülür. Bir web sayfasındayken ya sayfadaki bağlantılardan birini izlersiniz ya da adres çubuğuna web grafındaki herhangi bir URL'yi yazıp o sayfaya atlarsınız. Bu, her düğümden diğer bütün düğümlere gizli bağlantılar eklemek demektir.

Hoca y, a, m grafında gizli bağlantıları tek tek saydı. $m$'nin kendine bir bağlantısı vardır; ona $y$'ye ve $a$'ya giden iki gizli bağlantı eklenir. $a$'nın iki bağlantısı vardır; kendine giden bir gizli bağlantı eklenir. $y$'nin de iki bağlantısı vardır (kendine ve $a$'ya); $m$'ye giden bir gizli bağlantı eklenir.

Slayttaki Google çözümü şudur (ekrandan, 01:30:00): her zaman adımında rastgele gezginin iki seçeneği vardır.

- $\beta$ olasılıkla rastgele bir bağlantıyı izler.
- $1-\beta$ olasılıkla rastgele bir sayfaya atlar (ışınlanır, teleport).
- $\beta$ için yaygın değerler 0,8 ile 0,9 arasındadır.

Hoca $\beta = 0{,}8$ örneğini verdi: gezgin yüzde 80 olasılıkla bağlantıları izler, yüzde 20 olasılıkla herhangi bir sayfaya atlar. Böylece gezgin birkaç adım içinde örümcek tuzağından çıkar.

Tek bir düğüm için denklem şöyle yazılır: ilk kısım baştaki akış denklemidir, ikinci kısım atlamayı ekler.

$$r_j = \sum_{i \to j} \beta \frac{r_i}{d_i} + (1-\beta)\frac{1}{N}$$

<!-- BELİRSİZ: Bu tek düğüm denkleminin slaytı karede yok; formül hocanın anlatımından ("beta olasılıkla mevcut bağlantıları izler, 1 eksi beta olasılıkla herhangi bir düğüme atlar") ve kaynak kitabın gösteriminden yazıldı. -->

Gezgin her an herhangi bir sayfaya atlayabildiği için artık örümcek tuzağı kalmaz.

### 10.2 Çıkmaz uç için her zaman ışınlanma

Çıkmaz uç sorununda da ışınlanma kullanılır. Slayttaki çözüm şudur (ekrandan, 01:35:00): çıkmaz uçtan 1,0 olasılıkla rastgele ışınlanma bağlantıları izlenir ve matris buna göre düzenlenir.

Slayttaki grafta $m$ hiç bağlantı vermez, yani bir çıkmaz uçtur. Bu yüzden matrisin $m$ sütunu tamamen sıfırdır ve matris stokastik değildir. Bu matrisle kuvvet yinelemesi yapılınca değerler sıfıra yakınsar; bu da göreli önem vermez. Çözüm olarak $m$'den bütün düğümlere (kendisi dahil) üç gizli bağlantı eklenir. Artık $m$'nin üç çıkışı olduğu için sütununa $1/3$, $1/3$, $1/3$ yazılır:

| | $y$ | $a$ | $m$ | | $y$ | $a$ | $m$ |
|---|---|---|---|---|---|---|---|
| $y$ | 1/2 | 1/2 | 0 | $\Rightarrow$ | 1/2 | 1/2 | 1/3 |
| $a$ | 1/2 | 0 | 0 | | 1/2 | 0 | 1/3 |
| $m$ | 0 | 1/2 | 0 | | 0 | 1/2 | 1/3 |

Artık bütün sütunların toplamı 1'dir; matris stokastik hâle gelmiştir.

### 10.3 $M$'yi stokastik yapmak: matris biçimi

Hoca bu düzeltmeyi bir matris işlemiyle yazdı. Slayttaki formül şudur (ekrandan, 01:40:00):

$$A = M + a^T \left(\frac{1}{n} e\right)$$

- $a_i = 1$, eğer $i$ düğümünün çıkış derecesi 0 ise; değilse $a_i = 0$.
- $e$, bütün elemanları 1 olan vektördür.

Hoca bunu şöyle açıkladı: $e$ bütün değerleri 1 olan bir vektördür; $\frac{1}{n}e$ ise her elemanı $1/n$ olan bir vektördür. $a$ da bir vektördür ve yalnız çıkmaz uç düğümlerde 1, diğerlerinde 0 değerini taşır. Biri $n \times 1$, diğeri $1 \times n$ boyutlu iki vektör çarpılınca $n \times n$ bir matris çıkar. Bu matriste yalnız çıkmaz uç düğümlerin sütunlarında $1/n$, diğer sütunlarda 0 bulunur. $M$'de ise çıkmaz uç sütunları tamamen sıfırdı. İki matris toplanınca çıkmaz uç sütunlarına $1/n$ yazılmış olur ve matris stokastik bir matrise dönüşür.

Slaytta düzeltilmiş matrisin akış denklemleri de veriliyor (ekrandan, 01:40:00):

$$r_y = \frac{r_y}{2} + \frac{r_a}{2} + \frac{r_m}{3}, \qquad r_a = \frac{r_y}{2} + \frac{r_m}{3}, \qquad r_m = \frac{r_a}{2} + \frac{r_m}{3}$$

### 10.4 Markov zinciri teoreminin üç koşulu

Hoca, Markov zinciri teoremine göre kuvvet yinelemesinin belirli bir yineleme sonunda mutlaka sabit bir olasılık dağılımına yakınsaması için matrisin üç koşulu sağlaması gerektiğini söyledi:

- **Stokastik:** her sütunun toplamı 1 olmalıdır.
- **İndirgenemez (irreducible):** hocanın anlatımıyla içinde çıkmaz uç sorunu olmamalıdır.
- **Periyodik olmayan (aperiodic):** hocanın anlatımıyla içinde örümcek tuzağı sorunu olmamalıdır.

Hoca örümcek tuzağını kaldırmak için atlama faktörünü eklediğini, çıkmaz uç sorununu da çıkmaz uç sütunlarına $1/n$ yazarak giderdiğini ve bu sayede matrisi aynı zamanda stokastik yaptığını özetledi. Gezgin artık istediği sayfaya geçebildiği için grafta örümcek tuzakları olsa bile onlarda kalmak zorunda değildir.

> **Ders sonrası not:** Hoca, çıkmaz uç düzeltmesinin matrisi indirgenemez, $\beta$ ışınlanmasının ise periyodik olmayan yaptığını söyledi. Kaynak kitapta büyük olasılıkla eşleştirme biraz farklıdır: çıkmaz uç düzeltmesi matrisi stokastik yapar; indirgenemezlik (her düğümden her düğüme ulaşılabilmesi) ve periyodik olmama ise rastgele ışınlanmayla sağlanır. Örümcek tuzağında puanın bir kümede toplanması aslında indirgenebilirlikle ilgilidir; $a \leftrightarrow b$ salınımı ise periyodikliğin örneğidir. Son matrisin üç koşulu birlikte sağladığı sonucu değişmez.

### 10.5 Son PageRank denklemi ve $\beta = 0{,}8$ örneği

İki düzeltme birlikte uygulanınca elde edilen matris ne örümcek tuzağı ne de çıkmaz uç sorunu taşır. Bu matris stokastik, indirgenemez ve periyodik olmayan bir matristir. Markov zinciri teoremine göre kuvvet yinelemesi bu matriste belirli bir yinelemeden sonra durağan bir olasılık dağılımı vektörüne ulaşır.

Slayttaki örnekte (ekrandan, 01:45:00) $m$ kendine bağlantı veren örümcek tuzağı düğümüdür ve $\beta = 0{,}8$'dir. Işınlanmalı matris şöyle kurulur:

$$A = 0{,}8 \cdot M + 0{,}2 \cdot \frac{1}{n}\mathbf{1}\mathbf{1}^T$$

$$M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 1 \end{pmatrix}, \qquad \frac{1}{n}\mathbf{1}\mathbf{1}^T = \begin{pmatrix} 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \end{pmatrix}$$

Örneğin $A$'nın sol üst elemanı $0{,}8 \cdot \frac{1}{2} + 0{,}2 \cdot \frac{1}{3} = \frac{2}{5} + \frac{1}{15} = \frac{7}{15}$ olur. $m$'nin kendine bağlantısı $0{,}8 \cdot 1 + 0{,}2 \cdot \frac{1}{3} = \frac{13}{15}$ olur. Bağlantı olmayan yerlerde yalnız $0{,}2 \cdot \frac{1}{3} = \frac{1}{15}$ kalır (ara adım eklendi). Sonuç:

$$A = \begin{pmatrix} 7/15 & 7/15 & 1/15 \\ 7/15 & 1/15 & 1/15 \\ 1/15 & 7/15 & 13/15 \end{pmatrix}$$

Slayttaki graf da her kenarın olasılığını gösterir: örneğin $y$'den $a$'ya $0{,}8 \cdot \frac{1}{2} + 0{,}2 \cdot \frac{1}{3}$, $y$'den $m$'ye yalnız $0{,}2 \cdot \frac{1}{3}$, $m$'den kendine $0{,}8 + 0{,}2 \cdot \frac{1}{3}$.

Başlangıçta her elemana $1/3$ verilip kuvvet yinelemesi uygulanınca vektör şu değerlerden geçer (ekrandan, 01:45:00):

| | 0 | 1 | 2 | 3 | ... | yakınsama |
|---|---|---|---|---|---|---|
| $y$ | 1/3 | 0,33 | 0,24 | 0,26 | ... | 7/33 |
| $a$ | 1/3 | 0,20 | 0,20 | 0,18 | ... | 5/33 |
| $m$ | 1/3 | 0,46 | 0,52 | 0,56 | ... | 21/33 |

> **Ders sonrası not:** Python ile yapılan hesapta ikinci adımda $y$ değeri $0{,}24$ değil $0{,}28$ çıkar: $\frac{7}{15}\cdot\frac{1}{3} + \frac{7}{15}\cdot 0{,}20 + \frac{1}{15}\cdot 0{,}4\overline{6} = 0{,}28$. Tablonun diğer değerleri (0,20; 0,52; 0,26; 0,18; 0,56) ve yakınsama değerleri $7/33 \approx 0{,}212$, $5/33 \approx 0{,}152$, $21/33 \approx 0{,}636$ hesapla uyuşur.

Bu sonuç tam istenen şeydir, çünkü sayfaların birbirine göre önemini verir. $m$ hâlâ en önemli sayfa çıkar, çünkü kendine bağlantı verir ve $a$'dan da bağlantı alır; ama artık bütün puanı tek başına toplamaz. Bu değerlere bakarak graftaki hangi sayfanın daha önemli olduğu bulunabilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00): Akış denklemleri $r_y = r_y/2 + r_a/2$, $r_a = r_y/2 + r_m$, $r_m = r_a/2$ olan grafta, $r_y + r_a + r_m = 1$ kısıtıyla PageRank değerlerini bulun.

> **Çözüm (derste verildi):** $r_m = r_a/2$ ve birinci denklemden $r_y = r_a$ çıkar. Toplam $r_a + r_a + r_a/2 = 1$ olduğundan $r_a = 2/5$. Sonuç: $r_y = 2/5$, $r_a = 2/5$, $r_m = 1/5$.

**Soru 2** (ekrandan, 00:40:00): $j$ düğümüne, 3 çıkış bağlantısı olan $i$ ve 4 çıkış bağlantısı olan $k$ düğümleri bağlantı veriyor. $r_j$ nasıl yazılır?

> **Çözüm (derste verildi):** $r_j = r_i/3 + r_k/4$.

**Soru 3** (ekrandan, 01:25:00): $a$ ve $b$ birbirine bağlantı veriyor. Başlangıç vektörü $(r_a, r_b) = (1, 0)$ ise kuvvet yinelemesi yakınsar mı?

> **Çözüm (derste verildi):** Hayır. Vektör $(1,0) \to (0,1) \to (1,0) \to (0,1)$ biçiminde salınır. Bu bir örümcek tuzağıdır.

**Soru 4** (ekrandan, 01:45:00): $M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 1 \end{pmatrix}$ ve $\beta = 0{,}8$ için ışınlanmalı $A$ matrisini kurun ve PageRank vektörünü bulun.

> **Çözüm (derste verildi):** $A = 0{,}8M + 0{,}2 \cdot \frac{1}{3}\mathbf{1}\mathbf{1}^T$; satırlar $(7/15, 7/15, 1/15)$, $(7/15, 1/15, 1/15)$, $(1/15, 7/15, 13/15)$. Kuvvet yinelemesi $r = (7/33,\ 5/33,\ 21/33)$ değerine yakınsar (python ile doğrulandı).

**Soru 5** (derste sözlü, 01:16:53): Geri gitme tuşunu göz ardı etmeyen algoritmalarda graf yine yönlü mü düşünülür?

> **Cevap (derste verildi):** PageRank gibi sıralama algoritmaları önemi gelen bağlantılardan hesapladığı için yönlü graf üzerinde çalışır. Yönsüz graflarda (Facebook arkadaşlığı gibi) kullanılamaz; takip tabanlı graflarda, Twitter'da ve web grafında kullanılabilir.

## Dersin Toparlaması

Bu derste büyük graf verisinin analizine geçildi ve bağlantı analizinin en bilinen algoritması PageRank işlendi. Web aramasında güvenilir ve sorguya en uygun sayfaları öne çıkarmak için sayfaların sıralanması gerekir. PageRank bu sıralamayı içeriğe değil, bağlantı yapısına bakarak yapar: her bağlantı bir oydur ve önemli sayfaların oyu daha değerlidir. Bu fikir $r_j = \sum_{i \to j} r_i/d_i$ akış denklemlerine, oradan da sütun stokastik $M$ matrisiyle $r = Mr$ özvektör denklemine dönüştürüldü. Bu denklem büyük graflarda kuvvet yinelemesiyle çözülür.

Aynı denklem, geri tuşu olmayan bir tarayıcıda rastgele gezinen bir kullanıcının durağan dağılımı olarak da yorumlandı. Markov zinciri teoremine göre bu dağılımın tek olması ve başlangıçtan bağımsız olması için matris stokastik, indirgenemez ve periyodik olmayan olmalıdır. Web'deki örümcek tuzakları yakınsamayı, çıkmaz uçlar ise anlamlı sonucu bozar. İkisi de ışınlanmayla çözülür: gezgin $\beta$ olasılıkla bağlantı izler, $1-\beta$ olasılıkla rastgele bir sayfaya atlar ve çıkmaz uçtan her zaman ışınlanır. Sonuçta $A = \beta M + (1-\beta)\frac{1}{n}\mathbf{1}\mathbf{1}^T$ matrisiyle yapılan kuvvet yinelemesi, sayfaların göreli önemini veren PageRank vektörüne yakınsar.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
