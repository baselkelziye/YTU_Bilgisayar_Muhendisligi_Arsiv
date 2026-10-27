# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin tarihi 6 Kasım 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl anlatım yaklaşık 00:07:20'de başlar. Kaydın başı selamlaşma ve İzmir depremi (30 Ekim 2020) üzerine sohbettir.
  - Ders iki arayla üç bölüme ayrılıyor. Yaklaşık 00:54-01:08 ve 02:01-02:13 arası ara.
  - Hocanın internet bağlantısı ders boyunca birkaç kez koptu. Warshall algoritması anlatılırken ses ve görüntü gidip geldi.
- Duyurular
  - Bu ders dönemin 5. haftası. Vize 8. haftada.
  - Sayı teorisi bölümü (kitapta Bölüm 5 olarak verilen içerik) atlanacak. Zaman kalırsa son haftaya alınacak.
  - Vizeden sonra ağaçlar, çizgeler (graphs) ve sonlu durum makineleri işlenecek.
- Bağıntılar (relations)
  - Kartezyen çarpım (Cartesian product) ve ikili bağıntı (binary relation).
  - Tanım kümesi (domain) ve değer kümesi (range).
  - Bağıntının liste, grafik (ok diyagramı) ve matris ile gösterimi.
- Bağıntıların özellikleri
  - Yansıma (reflexive), "non-reflexive" ve yansımasız (irreflexive).
  - Simetri (symmetric) ve ters simetri (antisymmetric).
  - Geçişme (transitive).
  - Her özelliğin matris üzerinde kontrolü için algoritma fikri.
- Bağıntının tersi (inverse) ve bağıntıların bileşkesi (composition): $R^2$, $R^3$, $R^n$.
- Sınıf içi alıştırma: altı bağıntının özelliklerini öğrencilerle birlikte belirleme.
- Denklik bağıntısı (equivalence relation) ve sıralama bağıntısı (partial order).
- Hasse diyagramı.
- Kapanış (closure): yansıma, simetri ve geçişme kapanışı.
- Warshall algoritması ile geçişme kapanışı.
- Uygulama örneği: kişi-dil matrisi ile "kim kiminle konuşabilir" problemi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir özelliği "sağlamıyor" demek için tek bir karşı örnek yeter.
  - Bir ikili özelliği bozuyorsa diğerlerine bakmaya gerek yok. Hoca bunu dolaylı ispat (indirect proof) mantığına bağladı.
- Geçişme özelliğinde en çok hata yapılır.
  - $(x,y)$ ve $(y,z)$ varsa $(x,z)$ aranır. Bu zincir hiç oluşmuyorsa kontrol edilecek bir şey yoktur, bağıntı geçişlidir.
  - Boş bağıntı da bu yüzden geçişlidir. Hoca, kullandığı kitabın (Rosen) da böyle kabul ettiğini söyledi.
- Bir bağıntı aynı anda hem simetrik hem ters simetrik olabilir.
  - Örnek: yalnız $(x,x)$ çiftlerinden oluşan bağıntı.
  - Bu yüzden "simetrikse ters simetrik değildir" gibi genellemeler yapılamaz.
  - Kesin olan tek genelleme: yansımalı bir bağıntı yansımasız ya da "non-reflexive" olamaz.
- Vize sorusu uyarısı: "$x$ divides $y$" ifadesi "$x$, $y$'yi böler" demektir.
  - Yani $y/x$ tam sayıdır. Öğrenciler sınavda $(x,y)$ yerine $(4,1)$ gibi ters çiftler yazıp puan kaybetmiş.
  - Hoca bu tip soruların sınavda yine geleceğini söyledi.
- Algoritma yazarken uç noktaları (edge cases) düşünün.
  - İç içe döngüde iç döngü dış döngüye bağlıysa ($j = i+1$'den başlıyorsa) dış döngü $n-1$'de bitmeli.
  - `exit`/`goto` ile döngüden çıkmak kötü kodlamadır. Bayrak (flag) gereksiz yere döngüyü sürdürür. En iyisi `while` kullanıp koşul bozulunca çıkmaktır.
- Bu kavramlar gerçek hayatta kullanılır.
  - Örnek: trafik ya da ağ planlamasında bir yol kapandığında alternatif yol bulmak geçişme kapanışı fikrine dayanır.

## Kısa Tekrar Notları

- Bağıntı: $R \subseteq X \times Y$. $A$ üzerinde bağıntı: $R \subseteq A \times A$.
- Yansımalı (reflexive): her $x \in A$ için $(x,x) \in R$. Matrisin köşegeni tamamen 1.
- Yansımasız (irreflexive): hiçbir $x$ için $(x,x) \in R$ değil. Köşegen tamamen 0.
- "Non-reflexive" (hocanın terimi): köşegenin bir kısmı 1, bir kısmı 0. Yani ne yansımalı ne yansımasız.
- Simetrik: $(x,y) \in R \Rightarrow (y,x) \in R$. Matris köşegene göre simetrik.
- Ters simetrik (antisymmetric): $(x,y) \in R$ ve $(y,x) \in R \Rightarrow x = y$.
- Geçişli (transitive): $(x,y) \in R$ ve $(y,z) \in R \Rightarrow (x,z) \in R$.
- Ters bağıntı: $R^{-1} = \{(y,x) \mid (x,y) \in R\}$.
- Bileşke: $R^1 = R$, $R^n = R^{n-1} \circ R$.
- Denklik bağıntısı = yansımalı + simetrik + geçişli.
- Sıralama bağıntısı (kısmi sıralama, partial order) = yansımalı + ters simetrik + geçişli.
- Hasse diyagramı: sıralama bağıntısının grafından yansıma döngüleri ve geçişmeden gelen kenarlar silinerek elde edilir.
- Warshall: $W_{ij} \leftarrow W_{ij} \lor (W_{ik} \land W_{kj})$, $k$ dış döngüde. Üç iç içe döngü, $O(n^3)$ işlem.

## Detaylı Açıklamalar

### Bağıntı ve gösterimleri

- $X$ ve $Y$ iki küme olsun. Kartezyen çarpım $X \times Y = \{(x,y) \mid x \in X, y \in Y\}$.
- $X \times Y$'nin her alt kümesi $X$'ten $Y$'ye bir ikili bağıntıdır. Kartezyen çarpımın tamamı da bir bağıntıdır.
- Slayttaki örnek: $X = \{1,2,3\}$, $Y = \{a,b\}$, $R = \{(1,a),(1,b),(2,b),(3,a)\}$.
  - $X \times Y$ 6 elemanlıdır. $R$ bunların 4'ünü içerir.
- Tanım kümesi: $R$'de bir $y$ ile eşleşen bütün $x$'ler. Değer kümesi: $R$'de bir $x$ ile eşleşen bütün $y$'ler.
- Bağıntı liste olarak, ok diyagramı (graf) olarak ya da 0-1 matrisi olarak gösterilebilir. Hoca pratikte liste gösterimini tercih ediyor. Algoritma yazarken matris en uygunudur.

### Yansıma özellikleri ve köşegen algoritması

- $A = \{a,b\}$ için yansımalı bir bağıntıda hem $(a,a)$ hem $(b,b)$ olmalıdır. Diğer çiftlerin önemi yoktur.
- Algoritma: bağıntıyı $n \times n$ matrise yaz. Köşegendeki 1'leri say ($m$).
  - Köşegeni okumak için tek döngü yeter. İki döngü gereksiz yere karmaşıklığı artırır.
  - $m = n$ ise yansımalı. $m = 0$ ise yansımasız. $0 < m < n$ ise "non-reflexive".

```text
m = 0
for i = 1 to n
    if M[i][i] == 1 then m = m + 1
if m == n        then "yansımalı"
else if m == 0   then "yansımasız"
else             "non-reflexive"
```

### Simetri ve simetri algoritması

- $(x,y)$ varsa $(y,x)$ de olmalıdır. $(x,x)$ çiftleri simetriyi bozmaz.
- $(x,y)$ yoksa $(y,x)$ de olmamalıdır. Bu, ilk koşulla aynı şeyi söyler.
- Matrisi köşegen boyunca katladığınızda üst üste gelen değerler aynı olmalıdır.
- Algoritma: üst üçgeni gez, $M[i][j]$ ile $M[j][i]$'yi karşılaştır.

```text
i = 1, simetrik = doğru
while i <= n-1 and simetrik
    j = i + 1
    while j <= n and simetrik
        if M[i][j] != M[j][i] then simetrik = yanlış
        j = j + 1
    i = i + 1
```

- Dış döngü $n-1$'de bitmelidir. Yoksa $i = n$ iken $j = n+1$ olur ve matrisin dışına çıkılır.

### Ters simetri

- $(x,y)$ ve $(y,x)$ birlikte bulunuyorsa $x = y$ olmalıdır.
- $\{(1,1),(1,2)\}$: simetrik değil ($(2,1)$ yok), ters simetrik.
- $\{(1,1),(1,2),(2,1)\}$: simetrik, ters simetrik değil.

### Geçişme

- Her $(x,y)$ için $y$ ile başlayan $(y,z)$ çiftleri aranır. Her biri için $(x,z)$ olmalıdır.
- Örnek: $\{(1,1),(1,3),(3,4),(1,4)\}$ geçişlidir. Buna $(4,2)$ eklenirse $(1,4),(4,2)$ zinciri $(1,2)$'yi ister. $(1,2)$ yoksa geçişli değildir.
- Bir öğrenci "yansımalı ve simetrik her bağıntı geçişli midir?" diye sordu. Hoca bunun bağıntıya bağlı olduğunu söyledi.
  - Kesin cevap: Hayır. Karşı örnek ders sonrası notlarda.

### Örnek: $a = b^2$, $A = \{1,2,3,4\}$

- $R = \{(1,1),(4,2)\}$.
- Yansımalı değil. Yansımasız değil ($(1,1)$ var). Yani "non-reflexive".
- Simetrik değil ($(4,2)$ var, $(2,4)$ yok). Ters simetrik.
- Geçişli: $(1,1)$'den sonra 1 ile başlayan başka çift yok. $(4,2)$'den sonra 2 ile başlayan çift yok. Kontrol edilecek zincir oluşmuyor.

### Bileşke örneği

- $R = \{(1,1),(2,1),(3,2),(4,3)\}$.
- $R^2 = R \circ R = \{(1,1),(2,1),(3,1),(4,2)\}$.
- $R^3 = R^2 \circ R = \{(1,1),(2,1),(3,1),(4,1)\}$.
- Yöntem: bir çiftin ikinci elemanı diğer çiftin birinci elemanıyla aynıysa dış elemanlardan yeni çift yazılır. Örnek: $(3,2)$ ve $(2,1)$'den $(3,1)$.

### Sınıf alıştırması: $A = \{1,2,3,4\}$ üzerinde altı bağıntı

| Bağıntı | Yansıma | Simetrik | Ters simetrik | Geçişli |
| :--- | :--- | :---: | :---: | :---: |
| $\{(2,2),(2,3),(2,4),(3,2),(3,3),(3,4)\}$ | non-reflexive | hayır | hayır | evet |
| $\{(1,1),(1,2),(2,1),(2,2),(3,3),(4,4)\}$ | yansımalı | evet | hayır | evet |
| $\{(2,4),(4,2)\}$ | yansımasız | evet | hayır | hayır |
| $\{(1,2),(2,3),(3,4)\}$ | yansımasız | hayır | evet | hayır |
| $\{(1,1),(2,2),(3,3),(4,4)\}$ | yansımalı | evet | evet | evet |
| $\{(1,3),(1,4),(2,3),(2,4),(3,1),(3,4)\}$ | yansımasız | hayır | hayır | hayır |

- Bağıntılar slayt karesinden alındı. Sonuçlar Python ile doğrulandı. Derste öğrencilerle bulunan sonuçlarla aynı.
- Geçişli olmama nedenleri:
  - $\{(2,4),(4,2)\}$: $(2,4),(4,2)$ zinciri $(2,2)$'yi ister.
  - $\{(1,2),(2,3),(3,4)\}$: $(1,2),(2,3)$ zinciri $(1,3)$'ü ister.
  - Son bağıntı: $(1,3),(3,1)$ zinciri $(1,1)$'i ister.

### Denklik bağıntısı

- Yansımalı, simetrik ve geçişli bağıntıya denklik bağıntısı denir.
- Ters simetri ayrıca kontrol edilmez. Bağıntı ters simetrik de olsa, bu üç özellik varsa denklik bağıntısıdır.
- $\{1,2\}$ üzerinde örnek: $\{(1,1),(2,2),(1,2),(2,1)\}$. Grafında her düğümde döngü ve iki yönlü kenar var.
- $\{(1,1),\ldots,(5,5)\}$ (yalnız köşegen) de bir denklik bağıntısıdır.
- $\{1,2,3\}$ üzerindeki tam bağıntı $\{(1,1),(2,2),(3,3),(1,2),(2,1),(1,3),(3,1),(2,3),(3,2)\}$ denklik bağıntısıdır.
- Eski vize sorusu: tam sayılarda $x - y = 5$ koşulu.
  - $(6,1)$, $(7,2)$ gibi çiftler yazılır. Ama $(x,x)$ hiçbir zaman yazılamaz ($x - x = 0$).
  - Yansımalı olamadığı için denklik bağıntısı değildir.
- Örnek: $X = \{1,\ldots,6\}$,
  $R = \{(1,1),(1,3),(1,5),(3,1),(3,3),(3,5),(5,1),(5,3),(5,5),(2,2),(2,6),(6,2),(6,6),(4,4)\}$.
  - Yansımalı, simetrik ve geçişli. Denklik bağıntısıdır. Sınıfları: $\{1,3,5\}$, $\{2,6\}$, $\{4\}$.
  - Bir öğrenci "$(5,5)$ ve $(2,2)$ varken $(5,2)$ gerekmez mi?" diye sordu. Gerekmez. Ortak eleman yoksa zincir oluşmaz.

### Sıralama bağıntısı ve Hasse diyagramı

- Yansımalı, ters simetrik ve geçişli bağıntıya sıralama bağıntısı (partial order) denir.
- Eski vize sorusu: $A = \{1,2,3,4\}$, "$x$ divides $y$".
  - $R = \{(1,1),(1,2),(1,3),(1,4),(2,2),(2,4),(3,3),(4,4)\}$.
  - Yansımalı, ters simetrik, geçişli. Sıralama bağıntısıdır.
- Örnek: $X = \{1,2,3,4\}$, $a \le b$.
  - $R = \{(1,1),(1,2),(1,3),(1,4),(2,2),(2,3),(2,4),(3,3),(3,4),(4,4)\}$.
  - Grafından önce yansıma döngüleri silinir.
  - Sonra geçişmeden gelen kenarlar silinir: $1 \to 3$, $1 \to 4$, $2 \to 4$.
  - Kalan Hasse diyagramı: $1 \to 2 \to 3 \to 4$ zinciri.
- Hasse diyagramından eski grafa dönülebilir. Geçişme kenarları ve döngüler geri eklenir.

### Kapanış (closure)

- Bir bağıntıda bir özellik yoksa, o özelliği sağlamak için gereken en az çifti eklemeye kapanış denir.
- Yansıma kapanışı: eksik $(x,x)$ çiftleri eklenir.
- Simetri kapanışı: her $(x,y)$ için eksik $(y,x)$ eklenir.
- Geçişme kapanışı: zincirlerin istediği $(x,z)$ çiftleri, yeni zincir kalmayana kadar eklenir. Bunu elle yapmak zordur. Bilgisayarda Warshall algoritması kullanılır.

### Warshall algoritması

- Örnek bağıntı: $R = \{(b,a),(b,c),(c,a),(c,d),(d,c),(a,d)\}$. Sıra $a,b,c,d$.

```text
procedure warshall
W = M_R
for k = 1 to n
    for i = 1 to n
        for j = 1 to n
            W[i][j] = W[i][j] OR (W[i][k] AND W[k][j])
```

- Ara matrisler (satırlar $a,b,c,d$; slayttaki el yazısı matrislerle aynı, Python ile doğrulandı):

| Adım | $a$ satırı | $b$ satırı | $c$ satırı | $d$ satırı |
| :--- | :---: | :---: | :---: | :---: |
| $W_0$ | 0001 | 1010 | 1001 | 0010 |
| $W_1$ | 0001 | 1011 | 1001 | 0010 |
| $W_2$ | 0001 | 1011 | 1001 | 0010 |
| $W_3$ | 0001 | 1011 | 1001 | 1011 |
| $W_4$ | 1011 | 1011 | 1011 | 1011 |

- Eklenen çiftler: $(b,d)$, $(d,a)$, $(d,d)$, $(a,a)$, $(a,c)$, $(c,c)$.
- Hoca derste $W_2$'de değişiklik olmadığını doğru gösterdi.

### Kişi-dil matrisi

- 6 kişi ($a_1, \ldots, a_6$) ve 5 dil ($b_1, \ldots, b_5$) var. $M_\alpha$: kişi $\times$ dil matrisi.

| | $b_1$ | $b_2$ | $b_3$ | $b_4$ | $b_5$ |
| :--- | :---: | :---: | :---: | :---: | :---: |
| $a_1$ | 1 | 1 | 0 | 0 | 0 |
| $a_2$ | 1 | 1 | 0 | 0 | 0 |
| $a_3$ | 0 | 0 | 1 | 0 | 1 |
| $a_4$ | 1 | 0 | 1 | 1 | 0 |
| $a_5$ | 0 | 0 | 0 | 1 | 0 |
| $a_6$ | 0 | 1 | 1 | 0 | 0 |

- "Hangi dil kimler tarafından konuşuluyor" matrisi bunun satır-sütun çevrilmiş hâlidir.
- İkisinin (Boolean) çarpımı "kim kiminle ortak bir dil konuşur" bağıntısını verir. Bu bağıntı yansımalı ve simetriktir.
- Sonuç matrisi (Python ile):

| | $a_1$ | $a_2$ | $a_3$ | $a_4$ | $a_5$ | $a_6$ |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| $a_1$ | 1 | 1 | 0 | 1 | 0 | 1 |
| $a_2$ | 1 | 1 | 0 | 1 | 0 | 1 |
| $a_3$ | 0 | 0 | 1 | 1 | 0 | 1 |
| $a_4$ | 1 | 1 | 1 | 1 | 1 | 1 |
| $a_5$ | 0 | 0 | 0 | 1 | 1 | 0 |
| $a_6$ | 1 | 1 | 1 | 1 | 0 | 1 |

- Derste söylendiği gibi $a_1$; $a_2$, $a_4$ ve $a_6$ ile konuşabilir.

### Ders sonrası notlar

- **Bağıntı ve fonksiyon:** Hoca dersin başında bağıntıya birkaç kez "fonksiyon" dedi. Slayttaki $R = \{(1,a),(1,b),(2,b),(3,a)\}$ bir bağıntıdır ama fonksiyon değildir, çünkü 1 iki farklı elemana gidiyor. Her fonksiyon bir bağıntıdır, tersi doğru değildir.
- **"Non-reflexive" terimi:** Rosen gibi kaynaklarda ayrı bir "non-reflexive" sınıfı yoktur. Bu durum "yansımalı değil" diye söylenir. "Yansımalı değil" ifadesi yansımasız bağıntıları da kapsar. Sınavda hocanın üçlü ayrımını kullanın, ama terimin standart olmadığını bilin.
- **Sıralama bağıntısının tanımı:** Hoca bir yerde "sıralama bağıntısında geçişmenin yerine ters simetri" dedi. Doğrusu: denklik bağıntısındaki **simetrinin** yerine ters simetri gelir. Sıralama bağıntısı yansımalı, ters simetrik ve geçişlidir.
- **$a \le b$ listesi:** Hoca çiftleri sayarken $(1,2)$'yi atladı ("1,3; 1,4; 2,3; 2,4; 3,4"). $(1,2)$ de bağıntıdadır. Grafta doğru çizildi.
- **Warshall algoritması:** Algoritmanın sahibi Stephen Warshall'dır (1962), altyazıda "Marshall/Varshal" diye geçiyor. Hocanın anlattığı "yarışma" hikâyesi kaynaklarda doğrulanamadı. Algoritmayı Bernard Roy da 1959'da bağımsız olarak yayımlamıştır.
- **Warshall sonucu:** Hoca eklenen kenarları anlatırken "$a \to d$, $d \to c$ varsa $c \to a$ olmalı" dedi. Doğrusu $a \to c$ olmalı. $c \to a$ zaten başlangıç bağıntısında vardı.
- **Matrisin "tersi":** Kişi-dil örneğinde "matrisin tersi" ($M_\alpha^{-1}$) denen şey ters matris değil, devrik (transpose) matristir: $M_\alpha^T$. Çarpım da sıradan değil, Boolean çarpımdır (toplama yerine VEYA, çarpma yerine VE).
- **Bulanık mantık (fuzzy logic) açıklaması:** Bağıntı bileşkesi bulanık mantığa özgü değildir; genel bir kavramdır. Bulanık mantıkta 0-1 arasındaki değerler olasılık değil üyelik derecesidir (membership degree). Bu yüzden toplamlarının 1 olması gerekmez.
- **Yansımalı ve simetrik ama geçişli olmayan bağıntı:** $\{1,2,3\}$ üzerinde $\{(1,1),(2,2),(3,3),(1,2),(2,1),(2,3),(3,2)\}$. $(1,2),(2,3)$ zinciri $(1,3)$'ü ister ama $(1,3)$ yok. Python ile doğrulandı.
- **Boş bağıntı:** Boş bağıntı yansımasız, simetrik, ters simetrik ve geçişlidir (koşullar boş yere sağlanır). Boş olmayan bir kümede yansımalı değildir.
- Derste kullanılan bütün bağıntı örneklerinin özellikleri, $R^2$/$R^3$ ve Warshall ara matrisleri Python ile tek tek kontrol edildi. Yukarıdaki tablolar bu kontrolün sonucudur.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
