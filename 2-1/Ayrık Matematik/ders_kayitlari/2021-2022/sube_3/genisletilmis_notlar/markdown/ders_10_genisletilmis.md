# Ders 10 Genişletilmiş Notu: Ağaçlar: Gezinme, Huffman Kodlama, Kapsayan Ağaçlar, İzomorfizm ve Karar Ağaçları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ağaçlarda Gezinme (Tree Traversal)
- 2. Ağaçların Kullanım Alanları ve Huffman Kodlama
- 3. Kapsayan Ağaç (Spanning Tree)
- 4. DFS: Derin Öncelikli Arama
- 5. BFS: Geniş Öncelikli Arama
- 6. Minimum Kapsayan Ağaç ve Prim Algoritması
- 7. Kruskal Algoritması
- 8. Ağaçlarda İzomorfizm
- 9. Karar Ağaçları ve Beş Para Problemi
- 10. Karar Ağacı Kurmak: Entropi ve Bilgi Kazancı
- Örnek Sorular
- Dersin Toparlaması

## 1. Ağaçlarda Gezinme (Tree Traversal)

Ders, ağaçlar konusunun kaldığı yerden, ağaç üzerinde gezinmeyle başladı. Elimizde bir ağaç ve düğümlerinde birtakım değerler (etiketler) olduğunu düşünelim. Bu ağacın ikili ağaç (binary tree) olması gerekmez; herhangi bir ağaç olabilir. "Traversal" gezinmek demektir. Ağaçtaki verileri okumak istediğimizde düğümleri rastgele okuyamayız; mutlaka bir kurala göre okumamız gerekir. Bu kurallar şunlardır:

- Pre-order traversal (önden sıralı): önce kök, sonra alt ağaçlar soldan sağa.
- In-order traversal (içten sıralı): önce en soldaki alt ağaç, sonra kök, sonra diğer alt ağaçlar.
- Post-order traversal (sondan sıralı): önce alt ağaçlar soldan sağa, en son kök.
- Reverse post-order traversal (ters önden sıralı): kitaplarda geçtiği için slayta konmuş, pek kullanılmayan bir okuma.

Slaytta her yöntem için düğümleri okunma sırasına göre numaralanmış bir ikili ağaç vardı. Post-order ağacında kök 7, kökün sol alt ağacı 3 (yaprakları 1 ve 2), sağ alt ağacı 6 (yaprakları 4 ve 5) olarak numaralanmıştı; yani önce soldaki yapraklar, sonra o alt ağacın kökü, en sonda ana kök okunur. Reverse post-order ağacında ise kök 1, sol alt ağacın kökü 5 (yaprakları 7 ve 6), sağ alt ağacın kökü 2 (yaprakları 4 ve 3) idi; burada önce kök, sonra alt ağaçlar ters sırada okunur (ekrandan, 00:05:00).

### 1.1 Genel kurallar

Kökü $r$, alt ağaçları soldan sağa $T_1, T_2, \dots, T_n$ olan bir ağaç için (ekrandan, 00:10:00 ve 00:15:00):

$$\text{Pre-order: } r\,T_1\,T_2\dots T_n \qquad \text{In-order: } T_1\,r\,T_2\dots T_n \qquad \text{Post-order: } T_1\,T_2\dots T_n\,r$$

Bir alt ağaca girildiğinde aynı kural o alt ağaca yeniden uygulanır. Yani kural yinelemelidir (recursive).

### 1.2 Örnek ağaç

Derste kullanılan ağaç şöyledir (ekrandan, 00:10:00):

```text
a
├── b
│   ├── e
│   │   ├── j
│   │   └── k
│   │       ├── n
│   │       ├── o
│   │       └── p
│   └── f
├── c
└── d
    ├── g
    │   ├── l
    │   └── m
    ├── h
    └── i
```

**Pre-order.** Önce kök $a$ okunur. Sonra en soldaki alt ağaca, $b$'nin alt ağacına girilir: önce kökü $b$, sonra onun en soldaki alt ağacı olan $e$'nin alt ağacı: $e$, sonra $j$, sonra $k$ alt ağacı ($k$, $n$, $o$, $p$). $e$ bitince $b$'nin sağ çocuğu $f$ okunur. Ardından $a$'nın ikinci çocuğu $c$, sonra üçüncü çocuğu $d$'nin alt ağacı: $d$, $g$, $l$, $m$, $h$, $i$.

$$a, b, e, j, k, n, o, p, f, c, d, g, l, m, h, i$$

Derste hoca okurken $b$'nin sağ çocuğu $f$'yi önce atladı; bir öğrenci "C'den önce F var, B'nin sağ kolunu yazmadık" diye uyardı ve sıra düzeltildi.

**In-order.** Önce en soldaki alt ağaç bitirilmelidir. $a$'dan $b$'ye, $b$'den $e$'ye, $e$'den $j$'ye inilir. $j$ yapraktır, okunur; sonra kök $e$; sonra $e$'nin diğer alt ağacı $k$: onun da önce sol çocuğu $n$, sonra kök $k$, sonra $o$ ve $p$. Böylece $b$'nin sol tarafı biter, $b$ okunur, sonra $f$. $a$'nın sol alt ağacı bitince $a$ okunur, sonra $c$. Son olarak $d$ alt ağacı: önce $g$ alt ağacı ($l$, $g$, $m$), sonra $d$, sonra $h$ ve $i$.

$$j, e, n, k, o, p, b, f, a, c, l, g, m, d, h, i$$

**Post-order.** Her alt ağaçta önce çocuklar soldan sağa, en son kök okunur. $j$; sonra $k$ alt ağacının yaprakları $n, o, p$ ve kökü $k$; sonra $e$; sonra $f$ ve $b$; sonra $c$; sonra $l, m, g$, ardından $h, i, d$; en sonda $a$.

$$j, n, o, p, k, e, f, b, c, l, m, g, h, i, d, a$$

Üç okunuş python ile ağaç üzerinde yeniden üretilerek kontrol edildi.

### 1.3 Okunuştan ağaç çizmek

Hoca, bir sınav sorusunda ağacın çizilip okunuşunun istenebileceğini ya da tersine bir okunuş verilip ağacın istenebileceğini söyledi. Yalnızca "post-order okunuşu bu olan ağacı çiziniz" denirse bu bilgi yetmez. Ağacın yüksekliği, düğümlerin seviyeleri ya da hangi çocuğun hangi ebeveyne bağlı olduğu gibi ek bilgilerin de verilmesi gerekir (örneğin "kökü $d$, çocukları $g, h, i$ olan bir alt ağaç var" gibi).

### 1.4 Reverse post-order

Post-order'da önce yapraklar, sonra kök okunuyordu. Reverse post-order'da tersten gidildiği için önce kök, sonra yapraklar ters sırayla okunur ve her alt ağaçta bu kural uygulanır. Hoca bunun yaygın kullanılan bir notasyon olmadığını, üzerinde durmayacağını söyledi.

Aritmetik ifadelerin infix, prefix ve postfix gösterimleri ile bunların ağaca dönüştürülmesi önceki derslerde (algoritmalar slaytı içinde) anlatıldığı için bu derste atlandı.

## 2. Ağaçların Kullanım Alanları ve Huffman Kodlama

Ağaçların kullanım alanı çok geniştir: bir sayı dizisini sıralamak (sort), bir dizide bir sayının olup olmadığını aramak, bir sembolü/karakteri/ismi kodlamak, aritmetik işlemleri farklı notasyonlarla çözmek. Huffman ağacı bir kodlama ağacıdır.

Huffman kodları günlük hayatta kullandığımız birçok formatta vardır: JPEG resim formatı, gzip sıkıştırması ve faks. Faksla bir sayfa gönderildiğinde metin siyah-beyaz piksellerden oluşan bir resim gibi gider ve karşı tarafa kodlanarak iletilir; bu kodlamada da Huffman kodları kullanılır.

### 2.1 Kodlama ağacının okunması

Huffman ağacında yapraklar her zaman kodlanacak sembollere karşılık gelir: karakter kodlanıyorsa karakterlere, kelime kodlanıyorsa kelimelere. Kenarların üzerinde 0 ve 1 etiketleri vardır. Bir sembolün kodu, kökten o yaprağa giderken geçilen kenarların etiketleridir.

Slayttaki iki ağaç şöyledir (ekrandan, 00:20:00):

| Sembol | Sol ağaçtaki kod | Sağ ağaçtaki kod |
|---|---|---|
| a | 000 | 000 |
| r | 001 | 11 |
| c | 010 | 01 |
| t | 011 | 001 |
| e | 100 | 10 |

"rate" kelimesi sol ağaçla $001\,000\,011\,100$, sağ ağaçla $11\,000\,001\,10$ olarak kodlanır (ekrandan, 00:20:00). Sol ağaçta her sembol 3 bitle kodlanmışken sağ ağaçta kod uzunlukları farklıdır ($e$ 2 bit, $a$ 3 bit). Yani kodların hepsi aynı uzunlukta olmak zorunda değildir.

> **Hocanın vurgusu:** Huffman kodlama ağacı mutlaka ve her zaman bir ikili ağaçtır (binary tree).

### 2.2 Neden sıkıştırma sağlanır?

ASCII tablosundaki karakterler 8 bitle kodlanır. Huffman ile her karaktere 8 bit yerine daha az bit harcanabilir. Kural şudur: çok sık kullanılan sembol en az bitle, az kullanılan sembol daha fazla bitle kodlanır. Bu nedenle kodların hepsinin 8 bitten kısa olması gerekmez; seyrek bir sembolün kodu 8 bitten uzun olabilir.

Hocanın örneği: bir metinde 10.000 boşluk, 100 tane $a$ ve 5 tane $j$ olsun (ekrandan, 00:30:00).

- Hepsi 8 bitle kodlanırsa: $10.000\cdot 8 + 100\cdot 8 + 5\cdot 8 = 80.000 + 800 + 40 = 80.840$ bit.
- Boşluk 2 bit, $a$ 7 bit, $j$ 12 bitle kodlanırsa: $10.000\cdot 2 + 100\cdot 7 + 5\cdot 12 = 20.000 + 700 + 60 = 20.760$ bit.

Kodlamayla neredeyse dörtte birine inilir. Sıkıştırmak, yani bir sembolü daha az bitle ifade etmek, budur. Resim dosyasında karakterler yerine renk kodları (örneğin 0-255 arasındaki renk değerleri) kodlanır.

### 2.3 Huffman ağacının oluşturulması

Problem (ekrandan, 00:30:00): Elimizde $a, e, k, l, m$ ve $z$ sembollerinden sırasıyla 25, 14, 8, 7, 4 ve 2 adet olsun. Her bir sembol için Huffman kod değerini bulalım. Bu sayılar sembollerin sıklık (frekans) değerleridir.

**Adım 1.** Sıklıklar küçükten büyüğe sıralanır:

$$2,\ 4,\ 7,\ 8,\ 14,\ 25$$

**Adım 2.** $n$ sembol varsa dizi $2n-1$ elemana genişletilir. Burada $n=6$, yani $2\cdot 6 - 1 = 11$ eleman olacaktır. Soldan başlanarak sıradaki iki değer toplanır ve toplam, sıralamayı bozmayacak yere yerleştirilir:

- $2+4=6$: 4 ile 7 arasına girer.
- Sıradaki ikili $6$ ve $7$: $6+7=13$, 8 ile 14 arasına girer.
- Sıradaki ikili $8$ ve $13$: $21$, 14 ile 25 arasına girer.
- Sıradaki ikili $14$ ve $21$: $35$, 25'ten sonra gelir.
- Sıradaki ikili $25$ ve $35$: $60$, en sona gelir.

Sonuç dizisi (ekrandan, 00:30:00):

$$2,\ 4,\ -6,\ 7,\ 8,\ -13,\ 14,\ -21,\ 25,\ -35,\ -60$$

Slaytta toplamlar kırmızıyla yazılmıştı. Hoca, bir algoritma yazarken sayıları renkle ayırmanın mümkün olmadığını, bu yüzden toplamlardan oluşan sayıların önüne eksi konduğunu anlattı: eksi işareti, o değerin bir ara toplam olduğunu söyler.

> **Hocanın vurgusu:** Toplama işaretli değil, mutlak değerce yapılır. $-6$ ile $7$ toplanırken sonuç $1$ değil $13$ olmalıdır. İşaretli toplanırsa çıkan ağacın Huffman ağacıyla hiçbir ilgisi olmaz; elde edilen bütün kodlar yanlış olur.

> **Hocanın vurgusu:** Bir değer bir kez toplandıktan sonra tekrar kullanılmaz. Örneğin $2$ ile $4$ toplandıktan sonra "sırada 4 ile 6'yı toplayacağım" denmez; sıradaki ikili alınır.

**Eşit değerlerde yerleştirme.** Hoca ikinci bir örnek verdi: sıklıklar $1, 1, 2, 5, 7, 15$ olsun (ekrandan, 00:35:00). Altı eleman olduğu için dizi yine 11 elemana genişletilir. İlk ikili $1+1=2$'dir; ama dizide zaten bir $2$ vardır. Bu toplam $2$'nin soluna da sağına da yazılabilir, sıralama bozulmaz. Hoca, bu derste hangisinin seçildiğinin önemli olmadığını (bir veri sıkıştırma dersinde önemli olacağını), ancak bir kez sola yazıldıysa sonraki eşitliklerde de hep sola yazılması gerektiğini söyledi. Sonraki adımlar: $2+2=4$, $4+5=9$, $7+9=16$, $15+16=31$; her toplam sıralamayı bozmayacak yere yerleşir.

**Adım 3.** Genişletilmiş dizinin en sonundaki eleman ağacın kökü olur. Sonra her eksi değerin hangi iki değerin toplamından oluştuğuna bakılır. Diziyi sondan okurken önce okunan değer sol dala, sonra okunan değer sağ dala yerleştirilir. Slayttaki ifadeyle: bir sonraki $(2n-2)$. değer sol dala, $(2n-3)$. değer sağ dala yerleşir (ekrandan, 00:40:00).

- Kök $-60 = 35 + 25$: sol çocuk $-35$, sağ çocuk $25$. 25 değeri "$a$" sembolünün sıklığıdır ve bir yapraktır (artı değer, bundan dal çıkmaz). $-35$ bir ara düğümdür, ağaç bu düğüm üzerinden kurulmaya devam eder.
- $-35 = 21 + 14$: sol $-21$, sağ $14$ ($e$, yaprak).
- $-21 = 13 + 8$: sol $-13$, sağ $8$ ($k$, yaprak).
- $-13 = 7 + 6$: sol $7$ ($l$, yaprak), sağ $-6$.
- $-6 = 2 + 4$: sol $4$ ($m$), sağ $2$ ($z$). Slayttaki ağaçta $m$ solda, $z$ sağdadır (ekrandan, 00:45:00).

Ortaya çıkan ikili ağaç (ekrandan, 00:45:00):

```text
-60
├── 0: -35
│   ├── 0: -21
│   │   ├── 0: -13
│   │   │   ├── 0: 7 (l)
│   │   │   └── 1: -6
│   │   │       ├── 0: 4 (m)
│   │   │       └── 1: 2 (z)
│   │   └── 1: 8 (k)
│   └── 1: 14 (e)
└── 1: 25 (a)
```

**Adım 4.** Ağacın dallarına kodları oluşturacak 0 ve 1 değerleri yazılır: sol dal için 0, sağ dal için 1. Kodlar kökten yaprağa doğru, yani yukarıdan aşağıya okunur (ekrandan, 00:45:00):

| Sembol | Sıklık | Kod | Bit sayısı |
|---|---|---|---|
| a | 25 | 1 | 1 |
| e | 14 | 01 | 2 |
| k | 8 | 001 | 3 |
| l | 7 | 0000 | 4 |
| m | 4 | 00010 | 5 |
| z | 2 | 00011 | 5 |

### 2.4 Kazancın hesabı

8 bitle kodlansaydı (ekrandan, 00:50:00):

$$25\cdot 8 + 14\cdot 8 + 8\cdot 8 + 7\cdot 8 + 4\cdot 8 + 2\cdot 8 = 200 + 112 + 64 + 56 + 32 + 16 = 480 \text{ bit}$$

Huffman kodlarıyla:

$$25\cdot 1 + 14\cdot 2 + 8\cdot 3 + 7\cdot 4 + 4\cdot 5 + 2\cdot 5 = 25 + 28 + 24 + 28 + 20 + 10 = 135 \text{ bit}$$

480 bit yerine 135 bit harcanır; iyi bir sıkıştırma yapılmıştır. Bu sıklıklar için Huffman yönteminin verdiği en küçük toplam bit sayısının 135 olduğu python ile kontrol edildi.

### 2.5 Kodlar neden yukarıdan aşağıya okunur?

Kodlar aşağıdan yukarıya (yapraktan köke) okunsaydı şu kodlar çıkardı (ekrandan, 00:50:00): $a\to 1$, $e\to 10$, $k\to 100$, $l\to 0000$, $m\to 01000$, $z\to 11000$.

Bir kodlamayla bir metin sıkıştırılıyorsa, sıkıştırılan metnin aynı şekilde açılabilmesi gerekir. Bunun için bir sembolün kodu başka bir sembolün kodunun başlangıcını oluşturmamalıdır. Doğru (yukarıdan aşağıya) kodlarda bu sağlanır: 1 ile başlayan başka kod yoktur, 01 ile başlayan başka kod yoktur, 001 ile başlayan başka kod yoktur, 0000 ile başlayan başka kod yoktur.

Yanlış kodlarda ise $1$ bir koddur ama $10$, $100$ ve $11000$ de 1 ile başlar; $10$ bir koddur ama $100$ de 10 ile başlar. Hoca bunu "kek" kelimesiyle gösterdi: $k=100$, $e=10$, $k=100$, yani $100\,10\,100$. Açarken ilk bit $1$ okunur; 1 bir koddur ($a$). Ardından gelen $0$ ve $00$ ile başlayan uygun bir kod bulunamaz ve açma işlemi takılır. Bu yüzden Huffman ağacı okunurken kodlar her zaman yukarıdan aşağıya okunur.

> **Ek bilgi (derste anlatılmadı):** Bu özelliğe "önek (prefix) özelliği" denir ve böyle kodlara önek kodu (prefix code) adı verilir. Sembollerin hepsi yapraklarda bulunduğu için kökten yaprağa okunan hiçbir kod başka bir kodun öneki olamaz.

Hoca, Huffman algoritmasının kodunun nasıl yazılacağının algoritma dersinde anlatılacağını, bu derste ağacın nasıl oluşturulduğunu bilmenin yeterli olduğunu söyledi.

**Soru:** (Aradan sonra sohbetten okunan bir mesaj) Bir öğrenci "11" ya da "1-1" yazmıştı. **Cevap:** Başka bir öğrenci bunun $2n-1$ formülünden geldiğini, yani 6 sembol için genişletilmiş dizinin 11 elemanlı olduğunu belirtmek için yazıldığını açıkladı.

## 3. Kapsayan Ağaç (Spanning Tree)

Graflar ile ağaçlar arasındaki ilişki hatırlatıldı: ağaçlar grafların özel bir durumudur. Graflarda kapalı döngüler olabilir; ağaçlarda olamaz. Bir grafta kapalı döngü olması şart değildir, ama kapalı döngü varsa o yapı ağaç değil graftır.

Kapsayan ağacın (spanning tree) amacı, mevcut graftaki bütün düğümleri içermek kaydıyla bu düğümleri birbirine bağlayan bir yapı bulmaktır. Bir graftan çizilebilecek birçok farklı kapsayan ağaç olabilir. Örneğin bir grafta $CD$, $DF$ ve $FE$ kenarları seçildiyse kapalı döngü olmaması için $DE$ kenarı seçilmemelidir. Bütün düğümleri içerecek şekilde çizilen her alt ağaca kapsayan ağaç denir.

### 3.1 Aynı grafın farklı kapsayan ağaçları

Slaytta dört düğümlü ($A, B, C, D$) ağırlıklı bir grafın yedi farklı kapsayan ağacı vardı (ekrandan, 01:05:00). Ekrandaki kenar ağırlıklarına göre toplamları:

| Kapsayan ağaç | Kenarlar | Toplam |
|---|---|---|
| 1 | $AD=8$, $BC=1$, $DC=4$ | 13 |
| 2 | $AD=8$, $DB=3$, $BC=1$ | 12 |
| 3 | $AD=8$, $DB=3$, $DC=4$ | 15 |
| 4 | $AC=2$, $DB=3$, $BC=1$ | 6 |
| 5 | $AB=2$, $DB=3$, $BC=1$ | 6 |
| 6 | $AC=2$, $DB=3$, $BC=1$ | 6 |
| 7 | $AB=2$, $DB=3$, $BC=1$ | 6 |

<!-- BELİRSİZ: Hoca toplamları sözlü olarak "12, 13, 10, 6" gibi söyledi; altyazı bu bölümde dağınık. Tablodaki toplamlar ekrandaki ağırlıklardan hesaplanmıştır. -->

Hepimiz farklı kapsayan ağaçlar seçebiliriz. İnsan olarak "şunu şöyle bağlarım" diye rastgele çizebiliriz; ama bilgisayarda kodlamak için bunun bir algoritması olmalıdır. Kenarların ağırlıkları varsa problem şöyle kurulabilir: bu düğümler bir köydeki haneler olsun ve evler arasına yol yapılacak; her kenarın bir maliyeti var. Dört ev en az maliyetle nasıl bağlanır? Minimum kapsayan ağaç algoritması çalıştırılırsa toplamı büyük olan ağaçlar hiçbir zaman çıkmaz; en küçük toplamlı olan çıkar. Bu örnekte en küçük toplam 6'dır (python ile kontrol edildi).

Kapsayan ağaç oluşturmanın iki çok bilinen yöntemi vardır: Breadth First Search ve Depth First Search.

## 4. DFS: Derin Öncelikli Arama

DFS'de (Depth First Search, derin öncelikli arama) bir kök (başlangıç) düğümü olmalıdır. Başlangıç düğümü hikâyeye göre değişir: düğümler köydeki evlerse ve bir su deposundan evlere su bağlanacaksa başlangıç su deposudur; bir işletmeden kamyonlarla farklı şehirlere mal gönderiliyorsa başlangıç işletmedir.

Algoritma şöyle çalışır (ekrandan, 01:10:00):

- Ziyarete kök düğümden başlanır ve gidilebilecek en uzak düğüme kadar gidilir. "Derin" denmesinin sebebi budur.
- Bütün düğümler ziyaret edilene kadar işlem tekrarlanır.
- Stack (yığın) veri yapısı kullanılır.

Yığın üzerinde iki işlem yapılır: push (yığına veri koymak) ve pop (yığından veri çekmek). Yığın "son giren ilk çıkar" mantığıyla çalışır.

### 4.1 DFS örneği

Graf (ekrandan, 01:10:00): kenarlar $A\!-\!B$, $A\!-\!H$, $A\!-\!D$, $D\!-\!F$, $B\!-\!E$, $B\!-\!C$. Başlangıç düğümü $A$.

| Adım | İşlem | Stack | Çıkan | Output |
|---|---|---|---|---|
| 1 | Push(A) | A | - | A |
| 2 | Push(D) | D-A | - | D |
| 3 | Push(F) | F-D-A | - | F |
| 4 | Pop() | D-A | F | - |
| 5 | Pop() | A | D | - |
| 6 | Push(H) | H-A | - | H |
| 7 | Pop() | A | H | - |
| 8 | Push(B) | B-A | - | B |
| 9 | Push(E) | E-B-A | - | E |
| 10 | Pop() | B-A | E | - |
| 11 | Push(C) | C-B-A | - | C |
| 12 | Pop() | B-A | C | - |
| 13 | Pop() | A | B | - |
| 14 | Pop() | - | A | - |

Anlatım: $A$ yığına atılır ve ziyaret edilmiş olur. $A$'dan gidilebilecek yollar $D$, $H$ ve $B$ yönündedir; hoca saat yönünün tersine hareket ederek önce $D$'ye gitti. $D$ yığına atılır, sonra $D$'den gidilebilecek $F$. $F$'den gidilecek yol yoktur; pop ile $F$ çıkar. $D$'den de başka yol yoktur; $D$ çıkar. $A$'ya dönülür, $A$'dan $H$'ye gidilir; $H$'den yol yoktur, $H$ çıkar. Sonra $B$; $B$'den $E$ ve $C$'ye gidilebilir, soldan başlanarak önce $E$. $E$ çıkar, $B$'den $C$'ye gidilir, $C$ çıkar. $B$'den gidilecek yer kalmayınca $B$, sonra $A$ çıkar ve yığın boşalır.

$$\text{Output: } A, D, F, H, B, E, C$$

Daha derin bir grafta da mantık aynıdır: başlangıçtan gidilebilecek en uca kadar inilir, sonra geri çekilerek bir üst düğümden açılan diğer yola geçilir.

## 5. BFS: Geniş Öncelikli Arama

BFS'de (Breadth First Search, geniş öncelikli arama) düğümler seviye bazında ziyaret edilir (ekrandan, 01:20:00):

- Kök düğümden başlanır ve düğümler düzey düzey ziyaret edilir.
- Bir sonraki seviyeye geçmeden önce bulunulan seviyedeki bütün düğümler ziyaret edilir.
- Queue (kuyruk) veri yapısı kullanılır. Kuyruk "ilk giren ilk çıkar" mantığıyla çalışır.

Hocanın benzetmesi: suya bir taş atıldığında taşın düştüğü yerin etrafında iç içe halkalar oluşur. Seviye, bu halkalardan her biridir. Önce başlangıç düğümü, sonra onun bir alt seviyesindeki düğümler, sonra onların bir alt seviyesi ziyaret edilerek genişlenir.

### 5.1 BFS örneği

Graf (ekrandan, 01:20:00): kenarlar $A\!-\!B$, $A\!-\!C$, $B\!-\!F$, $C\!-\!E$, $C\!-\!D$, $D\!-\!H$, $H\!-\!J$. Başlangıç $A$.

| Adım | Eklenen | Çıkan | Kuyruk | Output |
|---|---|---|---|---|
| 1 | A | - | A | A |
| 2 | B-C | A | B-C | B-C |
| 3 | F | B | C-F | F |
| 4 | E-D | C | F-E-D | E-D |
| 5 | - | F | E-D | - |
| 6 | - | E | D | - |
| 7 | H | D | H | H |
| 8 | J | H | J | J |
| 9 | - | J | - | - |

$$\text{Output: } A, B, C, F, E, D, H, J$$

Hoca tahtaya iç içe kapalı döngüleri olan bir graf da çizerek, başlangıç düğümünden aynı seviyedeki düğümlerin önce okunduğunu, sonra bir alt seviyeye geçildiğini gösterdi.

### 5.2 Hangisi ne zaman?

Hangi yöntemin daha uygun olduğu ağacın (grafın) yapısına bağlıdır. Uzun dallara sahip bir ağaçta Depth First daha uygundur. İç içe girmiş, birbirine çok bağlı graf yapılarında ise Breadth First ile graf üzerinde çok daha hızlı geçilebilir.

## 6. Minimum Kapsayan Ağaç ve Prim Algoritması

DFS ve BFS örneklerinde kenarların ağırlığı yoktu; bu yüzden "minimum" kavramı da yoktu. Grafın kenarlarında ağırlık değerleri varsa minimum kapsayan ağaç (minimal spanning tree) kullanılır.

Tanım (ekrandan, 01:25:00): Verilen ağırlıklı bir $G$ grafının minimal kapsayan ağacı, $G$ grafının bir kapsayan ağacıdır (tüm düğümlerden geçilmiştir) ve ağırlıklar toplamı da minimumdur.

Hocanın örneği: kampüsteki fakülte binaları düğümler, aralarından kablo geçebilecek yollar kenarlar ve kenar ağırlıkları metre cinsinden uzaklıklar olsun (örneğin 2,6 m, 1,8 m). Bütün binalar internete bağlanacak, ama hem işçilik hem kablo için en az para harcanmak isteniyor. Slayttaki koyu kenarlar bütün binaları bağlar ve toplamlarından daha küçüğü bulunamaz. DFS ve BFS'nin verdiği ağaçlarda böyle bir "bundan daha küçüğü olamaz" iddiası yoktur; minimum kapsayan ağaç algoritmalarında vardır.

Slayttaki altı düğümlü grafta ($A$-$F$) koyu çizilen kenarlar $AE=1{,}2$, $AF=1{,}8$, $BC=1{,}8$, $FD=1{,}9$ ve $BD=2{,}1$ olarak okunmaktadır; toplam $8{,}8$ eder (ekrandan, 01:25:00).

<!-- BELİRSİZ: Karedeki kenar etiketlerinin hangi kenara ait olduğu küçük yazı nedeniyle tam seçilemiyor; toplam bu okumaya göre python ile hesaplandı. -->

### 6.1 Prim algoritması

Hocanın hikâyesi: düğümler bir köydeki evlerdir, 1 numaralı düğüm su deposudur, kenarlar evler arasındaki ya da depo ile ev arasındaki mesafelerdir. Evler su deposuna, birbirleri üzerinden en az maliyetle bağlanacaktır.

Yedi düğüm olduğu için $7\times 7$'lik bir matris oluşturulur (ekrandan, 01:30:00):

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| 1 | 0 | 1100 | 100 | 300 | 600 | 1000 | 400 |
| 2 | 1100 | 0 | M | M | M | M | 900 |
| 3 | 100 | M | 0 | M | 500 | M | M |
| 4 | 300 | M | M | 0 | M | 700 | M |
| 5 | 600 | M | 500 | M | 0 | 200 | M |
| 6 | 1000 | M | M | 700 | 200 | 0 | 800 |
| 7 | 400 | 900 | M | M | M | 800 | 0 |

- Köşegen 0'dır; bir düğümden kendisine giden yol yoktur (ev içindeki tesisattan söz edilmiyor).
- Diğer sayılar düğümler arasındaki doğrudan mesafelerdir. Örneğin 1 ile 5 arasında doğrudan 600'lük yol vardır; 1'den 5'e 3 üzerinden de gidilebilir, ama matrise yalnızca doğrudan yollar yazılır.
- M, doğrudan kenar olmadığını gösterir (örneğin 3 ile 2, 7 ile 5 arasında). M "maksimum sayı" demektir: kullanılan veri tipinde yazılabilecek en büyük sayıdır (hoca integer için 32 bin civarı bir değer örneğini verdi). Algoritma en küçük yolları aradığı için, daha küçük bir değer dururken bu maksimum sayıyı hiçbir zaman seçmez.

Algoritmanın adımları (ekrandan, 01:30:00 ve 01:35:00):

1. Başlangıç düğümü 1'dir (inşaata su deposundan başlanır). 1'in satırındaki en küçük değer 100'dür, yani 3. düğüm. $1\!-\!3$ bağlanır. 1. ve 3. düğümlerin sütunları silinir: bu düğümlere artık tekrar bağlantı yapılmayacaktır.
2. Ağaçtaki düğümler 1 ve 3'tür. 3'ün satırındaki en küçük (silinmemiş) değer 500, 1'in satırındaki 300'dür. 300 daha küçük olduğu için $1\!-\!4$ seçilir; 4'ün sütunu silinir.
3. Ağaçta 1, 3, 4 vardır. 4'te en küçük 700, 3'te 500, 1'de 400'dür. 400 seçilir: $1\!-\!7$; 7'nin sütunu silinir.
4. Ağaçta 1, 3, 4, 7 vardır. 7'de en küçük 800, 4'te 700, 3'te 500, 1'de 500'den küçük değer yoktur (silinmiş sütunlardaki küçük sayılar seçilmez, çünkü o düğümlere zaten gidilmiştir). 500 seçilir: $3\!-\!5$; 5'in sütunu silinir.
5. Ağaçta 1, 3, 4, 5, 7 vardır. 5'in satırında 200 vardır ve diğerlerinden küçüktür. $5\!-\!6$ seçilir; 6'nın sütunu silinir.
6. Geriye yalnız 2. düğüm kalır. 7'nin satırındaki 900, diğer satırlardaki seçeneklerden küçüktür. $7\!-\!2$ seçilir.

Ortaya çıkan minimum kapsayan ağacın kenarları: $1\!-\!3$ (100), $1\!-\!4$ (300), $1\!-\!7$ (400), $3\!-\!5$ (500), $5\!-\!6$ (200), $7\!-\!2$ (900).

$$100 + 300 + 400 + 500 + 200 + 900 = 2400$$

> **Ders sonrası not:** Hoca toplamı sözlü olarak "100, 300 daha 600, ... 2600" diye hesapladı; ilk adımda $100+300=400$ olmalıdır ve kenarların toplamı 2400'dür. Prim algoritması aynı matris üzerinde python ile çalıştırıldığında da aynı kenarlar ve 2400 bulundu.

Hoca, bu toplamdan daha az maliyet veren bir kapsayan ağaç oluşturulamayacağını; oluşturulursa ya kendisinin ya da çözenin hata yaptığını söyledi. Ardından internette Prim algoritmasını adım adım gösteren, düğümleri şehir adlarıyla verilmiş bir canlandırmayı da gösterdi: başlangıç şehrinden çıkan kenarlardan en küçüğü seçiliyor, yeni eklenen şehirden çıkan kenarlarla birlikte yine en küçüğü seçiliyor, aynı düğüme giden daha pahalı kenar aday listesinden düşüyordu.

## 7. Kruskal Algoritması

Kruskal, hocanın deyişiyle görülebilecek en basit algoritmalardan biridir. O da düğümleri birbirine bağlayarak minimum kapsayan ağacı bulur. Üç adımı vardır (ekrandan, 01:40:00):

- Adım 1: Graftaki en küçük ağırlık değerine sahip kenarı bul (birden fazla varsa rastgele birini seç).
- Adım 2: En küçük değere sahip bir sonraki kenarı bul, ancak kapalı bir döngü oluşturmasın. Oluşturuyorsa o kenarı alma, sıradakine geç.
- Adım 3: Graftaki her bir düğümü dolaşana kadar adım 2'yi yap.

Bütün düğümler dolaşılmalı ama düğümler birbirinden ayrı da kalmamalıdır; hepsi bir şekilde bağlı olmalıdır. Bunu kontrol etmek için: $n$ düğüm varsa mutlaka $n-1$ kenar seçilmiş olmalıdır.

### 7.1 Yedi düğümlü örnek

Bu örnekte kenar ağırlıkları küçükten büyüğe sıralanınca bir tane 1, dört tane 2, üç tane 3, bir tane 4 ve iki tane 5 vardı. Önce 1 alındı, sonra dört tane 2'nin her biri alındı; hiçbiri kapalı çevrim oluşturmadı. Bu noktada bütün düğümlere dokunulmuş gibi görünüyordu, ama graf iki ayrı parçadan oluşuyordu. Yedi düğüm için $7-1=6$ kenar gerekir; seçilen kenar sayısı 5'tir. Bu yüzden sıradaki ağırlık olan 3'lerden kapalı çevrim oluşturmayan biri alındı ve iki parça birleşti. Hoca bu durumda hangi 3'ün seçildiğinin önemli olmadığını, algoritmanın "istesen de istemesen de" minimum kapsayan ağacı verdiğini söyledi.

<!-- BELİRSİZ: Bu yedi düğümlü grafın şekli okunan karelerde yok; kenar dağılımı altyazıdan alınmıştır. Altyazıya göre seçilen ağırlıklar 1, 2, 2, 2, 2, 3 olup toplam büyük olasılıkla 12'dir. -->

### 7.2 Dokuz düğümlü örnek

Hoca tahtada dokuz düğümlü bir grafta da algoritmayı yürüttü ve slayttaki çözümü gösterdi (ekrandan, 01:45:00). Düğümler $3\times3$ düzendedir; satırlar üst (Ü), orta (O), alt (A), sütunlar sol (1), orta (2), sağ (3) ile adlandırılırsa graf kenarları şunlardır:

| Kenar | Ağırlık | Kenar | Ağırlık |
|---|---|---|---|
| Ü1-Ü2 | 5 | O1-O2 | 7 |
| Ü2-Ü3 | 4 | O2-O3 | 1 |
| Ü1-O1 | 2 | O1-A1 | 6 |
| O1-Ü2 | 3 | O1-A2 | 8 |
| Ü2-O2 | 5 | O2-A2 | 3 |
| Ü2-O3 | 6 | A2-O3 | 4 |
| Ü3-O3 | 3 | O3-A3 | 4 |
| A1-A2 | 4 | A2-A3 | 2 |

Çözümde seçilen (koyu) kenarlar: O2-O3 (1), Ü1-O1 (2), A2-A3 (2), O1-Ü2 (3), Ü3-O3 (3), O2-A2 (3), Ü2-Ü3 (4), A1-A2 (4). Dokuz düğüm için 8 kenar seçilmiştir ve toplam:

$$1 + 2 + 2 + 3 + 3 + 3 + 4 + 4 = 22$$

Kruskal algoritması bu kenar listesiyle python'da çalıştırıldığında da toplam 22 bulundu. Derste hoca kenarları seçerken bazı 4'lerin kapalı çevrim oluşturduğu için alınamadığını, bütün düğümlere dokunulduğu hâlde bir parçanın bağımsız kaldığını gösterdi ve $n-1$ kuralını hatırlattı.

<!-- BELİRSİZ: Hocanın tahtada yürüttüğü sözlü çözümde 7 kenardan sonra bir 5'lik kenar seçildiği söyleniyor; bu, slayttaki 22'lik çözümden farklı bir ağaç verir. Altyazıdan hangi kenarların seçildiği tam çıkarılamıyor. -->

### 7.3 Altı düğümlü örnek

Slayttaki bir başka örnekte kenarlar küçükten büyüğe sıralanarak önce iki tane 5, sonra iki tane 10 seçildi. Sıra 15'lere geldiğinde ilk 15 kapalı çevrim oluşturduğu için alınmadı, ikinci 15 alındı. Altı düğüm için 5 kenar seçilmiştir: $5+5+10+10+15=45$. Bu kapsayan ağacın maliyeti 45'tir ve daha küçüğü yoktur.

### 7.4 Kapalı çevrimin anlaşılması

**Soru:** (Sohbetten) Kapalı çevrimi nasıl anlayabilirim, karışık geldi. **Cevap:** Hoca, iki kenar seçildikten sonra üçüncü bir kenar bu iki kenarın uçlarını birbirine bağlıyorsa kendi içinde bir döngü oluştuğunu, o kenarın alınamayacağını çizerek gösterdi. Dört kenarın hepsi seçilirse bir kare kapanır; o durumda bu kenarlardan biri alınamaz, sıradaki ağırlık küçük olsa bile. Algoritmik olarak düşünülürse: $BD$ ve $BE$ seçilmişse $DE$ seçilmemelidir. Bu kontrol geçişlilik (transitivity) özelliği gibi yapılabilir: $D$ ile $B$ bağlı, $B$ ile $E$ bağlıysa $D$ ile $E$ zaten bağlıdır.

## 8. Ağaçlarda İzomorfizm

İzomorfizm benzerlik demektir. Graflarda izomorfizm şöyle kontrol ediliyordu: düğüm sayıları aynı, kenar sayıları aynı, düğümlerin dereceleri karşılıklı olarak aynı ve komşuluk matrisleri aynı (ya da belirli satır ve sütunların yerleri değiştirilerek eşitlenebiliyor). Aynı şey ağaçlarda da geçerlidir.

### 8.1 Köksüz ağaçlar

Slaytta iki ağaç vardı (ekrandan, 02:05:00): $T_1$ ve $T_2$ izomorfiktir; bunun için $f: T_1 \to T_2$ biçiminde bire bir ve örten bir fonksiyon bulunmalıdır. Her iki ağaçta da 5 düğüm ve 4 kenar vardır. Düğüm dereceleri: bir tane 3. dereceden, bir tane 2. dereceden ve üç tane 1. dereceden düğüm. Ağaçların köklü olup olmadığı bilgisi verilmediği için yalnızca düğüm sayısı, kenar sayısı ve düğüm derecelerine bakılır ve bu iki ağaç izomorfiktir.

### 8.2 Köklü ağaçlar

Kökleri $R_1$ ve $R_2$ olan iki köklü ağaçta da 5 düğüm, 4 kenar ve aynı derece dağılımı (bir tane 3, bir tane 2, üç tane 1) vardı. Köklü ağaçta ek olarak kökler eşleşmelidir. Hocanın benzetmesi: her iki ağacı kökünden tutup üzüm salkımı gibi sallayınca birbiriyle örtüşüyorsa (kökler üst üste gelir, kökten çıkan dallar ve onlardan çıkan dallar birbirine karşılık gelirse) bu iki köklü ağaç izomorfiktir.

### 8.3 İkili ağaçlar

Aynı ağaçlar kökü $R_1$ ve $R_2$ olan ikili ağaçlar (binary tree) olarak verilirse durum değişir. Birinde alt ağaç sola doğru, diğerinde sağa doğru gelişmişse, düğüm, kenar ve derece sayıları aynı olsa bile bunlar ikili ağaç olarak izomorfik değildir. İkili ağaçlarda izomorfizm aranıyorsa ağaçların aynı yönde ilerlemesi gerekir.

### 8.4 İzomorfizm olmadığını göstermek

Slayttaki ifade (ekrandan, 02:10:00): Çoğu zaman iki ağaçta izomorfizm olmadığını göstermek, izomorfizm olduğunu göstermekten daha kolaydır. İzomorfizm olduğunu göstermek için bütün şartlar kontrol edilmelidir; olmadığını göstermek için tek bir şartın bozulduğunu göstermek yeter. İki ağaç arasında izomorfizm için beklenen şartlar:

- Düğüm sayıları aynı olmalı.
- Kenar sayıları aynı olmalı.
- Karşılıklı düğümlerin dereceleri aynı olmalı.
- Kökten köke eşleme yapılmalı (köklü ağaç).
- Çocukların (child-leaf) pozisyonları aynı olmalı (ikili ağaç).

### 8.5 Örnek: dört düğümlü ağaçlar

Hoca, en tepedeki düğümün kök kabul edildiği dört ağaç için izomorfizm olup olmadığını sordu. Hepsinde 4 düğüm ve 3 kenar vardır, ancak derece dizileri farklıdır; bu yüzden hepsi birbiriyle izomorfik değildir. Hoca yalnızca iki çiftin kendi aralarında izomorfik olduğunu söyleyebileceğini belirtti. İkili ağaç olarak sorulduğunda ise ikili ağaç olan iki ağacın, yönleri farklı olduğu için ikili ağaç olarak izomorfik olmadığını söyledi. Bir ağaç ise ikili ağaç değildir, çünkü ikili ağaçta bir düğümden en fazla iki kenar çıkabilir.

<!-- BELİRSİZ: Bu dört ağacın şekli okunan karelerde yok; hangi ağaçların hangi derece dizisine sahip olduğu altyazıdan net çıkmıyor. -->

### 8.6 Üç düğümlü farklı ikili ağaç sayısı

$n$ düğümlü kaç farklı ikili ağaç (izomorfik olmayan) yazılabileceği soruldu. $n = 3$ için hocanın hesabı:

$$\frac{\binom{2n}{n}}{n+1} = \frac{\binom{6}{3}}{4} = \frac{6!}{3!\,(6-3)!\cdot 4} = \frac{20}{4} = 5$$

Üç düğüme sahip 5 farklı ikili ağaç vardır. Bunların düğüm sayıları, kenar sayıları ve dereceleri aynı olsa bile, ikili ağaç olarak aynı çocuklara ve alt ağaçlara sahip olmadıkları için izomorfik değildirler.

> **Ek bilgi (derste anlatılmadı):** $\frac{1}{n+1}\binom{2n}{n}$ sayıları Catalan sayıları olarak bilinir: $n = 1, 2, 3, 4$ için $1, 2, 5, 14$. Üç düğümlü 5 ikili ağaç; kök-sol-sol, kök-sol-sağ, kök-sağ-sol, kök-sağ-sağ biçimindeki dört zincir ile kökün iki çocuğu olduğu dengeli ağaçtır.

## 9. Karar Ağaçları ve Beş Para Problemi

Ağaçların bir başka kullanım alanı karar ağaçlarıdır (decision trees). Günlük hayatta farkında olmadan çok sık karar ağacı kullanırız. Örneğin elimizdeki parayla yaz tatiline çıkıp çıkamayacağımıza karar veririz; çıkabiliyorsak pansiyonda kalıp kalamayacağımıza, hangi bölgeye gideceğimize, gittiğimiz yerde şehir merkezine mi sahile mi yakın kalacağımıza karar veririz. Sürekli bir soru sorup cevabına göre dallanıyorsak bir karar ağacı oluşturmuşuz demektir.

### 9.1 Beş para problemi

Problem (ekrandan, 02:15:00):

- Görünüşleri birbirinin aynı olan 5 paradan biri sahtedir.
- Sahte olan para diğerlerinden daha ağır veya daha hafif olabilir.
- Karar ağacını kullanarak hangi paranın sahte olduğuna karar veriniz.
- Sahte olan para diğerlerine göre hafif midir yoksa ağır mıdır?

Paralar $C_1, \dots, C_5$ ile gösterilir. Amaç, en az sayıda tartı yaparak sahte parayı ve ağır/hafif olduğunu bulmaktır. Her tartının üç sonucu olabilir: sol taraf ağır, denge ya da sağ taraf ağır. Bu yüzden ağacın her iç düğümünden üç dal çıkar.

Karar ağacı (ekrandan, 02:20:00; H ağır, L hafif demektir):

```text
C1 : C2
├── C1 ağır  -> C1 : C5
│              ├── C1 ağır  -> C1 sahte, ağır (C1,H)
│              └── denge    -> C2 sahte, hafif (C2,L)
├── denge    -> C3 : C4
│              ├── C3 ağır  -> C3 : C5
│              │              ├── C3 ağır -> C3 sahte, ağır (C3,H)
│              │              └── denge   -> C4 sahte, hafif (C4,L)
│              ├── C4 ağır  -> C3 : C5
│              │              ├── C3 hafif -> C3 sahte, hafif (C3,L)
│              │              └── denge    -> C4 sahte, ağır (C4,H)
│              └── denge    -> C5 : C1
│                             ├── C5 hafif -> C5 sahte, hafif
│                             └── C5 ağır  -> C5 sahte, ağır
└── C2 ağır  -> C1 : C5
               ├── C1 hafif -> C1 sahte, hafif (C1,L)
               └── denge    -> C2 sahte, ağır (C2,H)
```

Slaytta orta dalın "C4 ağır" ve "denge" kolları boş bırakılmıştı; bu kollar hocanın sözlü anlatımından kurulmuştur (ara adım eklendi).

Anlatımın mantığı:

- $C_1$ ile $C_2$ tartılır. Denge varsa ikisi de sahte değildir. Denge yoksa sahte para bu ikisinden biridir, ama hangisi olduğu bilinmez; bu durumda $C_3$, $C_4$, $C_5$ sahte değildir.
- $C_1$ ağır bastıysa $C_1$ sahte olmayan bir parayla, örneğin $C_5$ ile tartılır. $C_1$ yine ağırsa sahte para $C_1$'dir ve ağırdır. Denge varsa $C_1$ sağlamdır; ilk tartıdaki dengesizliğe $C_2$ sebep olmuştur ve $C_2$ hafiftir.
- $C_2$ ağır bastıysa aynı mantıkla: $C_1$ ile $C_5$ dengedeyse $C_2$ sahte ve ağırdır; değilse $C_1$ sahte ve hafiftir.
- $C_1$ ile $C_2$ dengedeyse sahte para $C_3$, $C_4$, $C_5$'ten biridir. $C_3$ ile $C_4$ tartılır. Bunlar da dengedeyse sahte para $C_5$'tir; $C_5$ sağlam bir parayla (örneğin $C_1$) karşılaştırılarak ağır mı hafif mi olduğu bulunur. $C_3$ ile $C_4$ dengede değilse biri sahtedir; $C_3$, sağlam $C_5$ ile tartılır.

Bu ağaçla sahte parayı bulmak için en kötü durumda 3, en iyi durumda 2 tartı gerekir.

Hoca anlatım sırasında birkaç kez dalları karıştırıp düzeltti ve öğrencilerin ağaca tekrar bakarak rahatlıkla anlayabileceğini söyledi. Burada amaç, bir şeye karar vermek için ağaç kullanmaktır.

## 10. Karar Ağacı Kurmak: Entropi ve Bilgi Kazancı

Beş para örneğinde neden $C_2$ yerine $C_5$ seçilmediği sorulabilir; orada seçim rastgele yapılmıştı. Oysa karar verirken hangi sorunun önce sorulacağının bir kuralı vardır.

### 10.1 Tenis veri seti

Elimizde 14 günlük bir veri seti ve 4 özellik olsun:

- Outlook (havanın durumu): sunny (güneşli), overcast (parçalı bulutlu), rainy (yağmurlu).
- Temperature (ısı): hot (sıcak), mild (ılık), cool (serin).
- Humidity (nem): high (yüksek), normal.
- Wind (rüzgâr): weak (zayıf), strong (kuvvetli).

Her gün için bu özelliklerin aldığı değerlere bakılarak dışarıda tenis oynanıp oynanamayacağına (yes/no) karar verilmiştir. Örneğin 1. gün hava güneşli, sıcak, nem yüksek ve rüzgâr zayıftır; sonuç "tenis oynanamaz"dır. Amaç, veri setinde olmayan bir durum geldiğinde de karar verebilecek bir karar ağacı kurmaktır.

> **Ders sonrası not:** Hoca 4 değişken için $2^4 = 16$ farklı durum olacağını söyledi. Bu, özelliklerin her biri iki değerli olsaydı doğru olurdu; burada outlook ve temperature üçer, humidity ve wind ikişer değer aldığı için olası durum sayısı büyük olasılıkla $3\cdot 3\cdot 2\cdot 2 = 36$'dır.

### 10.2 Rastgele kurulan ağaç

Hoca önce hiçbir formül kullanmadan, özellikleri kafasına göre yerleştirerek bir ağaç kurdu. Köke humidity konur (ekrandan, 02:25:00): nem high olan örnekler 1, 2, 3, 4, 8, 12, 14; normal olanlar 5, 6, 7, 9, 10, 11, 13.

Nem yüksek dalının altına rüzgâr konur: rüzgâr zayıf olanlar 1, 3, 4, 8; kuvvetli olanlar 2, 12, 14. Nem normal dalının altına da rüzgâr konur. Nem yüksek ve rüzgâr zayıf dalının altına outlook konur: 1 ve 8. örnekler güneşli, 3. örnek parçalı bulutlu, 4. örnek yağmurludur. Sınıflarına bakınca 3 ve 4 "yes", 1 ve 8 "no"dur.

Ağaç, yapraklara gelen örneklerin hepsi aynı etikete sahip olana kadar açılır. Bu ağaçta sıcaklık hiç kullanılmamıştır, yani sıcaklığa bakmadan karar verilebilmektedir. Ancak en fazla üç soru sorulmuştur (nem, rüzgâr, outlook). İdeal olan, en az soruyla karara ulaşan ağacı kurmaktır.

### 10.3 Entropi

En az soruyu sormak için bilgi kazancı (information gain) ve onun dayandığı entropi kavramı kullanılır. Entropinin sözlük anlamı karmaşıklık, karışıklıktır. Tenis örneğinde iki durum vardır: tenis oynamak (artı) ve oynamamak (eksi). Hoca, sınıf sayısı ikiden fazla olabilir diye bir benzetme yaptı: bir dersten yüksek notla geçmek, şartlı geçmek, kalmak ve devamsızlıktan kalmak gibi dört durum olsaydı entropi dört terim için hesaplanırdı.

İki sınıflı entropi (ekrandan, 02:30:00):

$$\mathrm{Entropy}(S) = -p_{+}\log_2 p_{+} - p_{-}\log_2 p_{-}$$

Bir olayın olasılığı, o olasılığın 2 tabanında logaritmasıyla çarpılır. 0 ile 1 arasındaki bir sayının logaritması negatif olduğu için başına eksi konur.

Veri setinde 9 "yes", 5 "no" vardır:

$$E(S) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} \approx 0{,}940$$

- Bütün örnekler aynı sınıfa ait ise $E(S)=0$ (homojen). Örneğin 14 örneğin 14'ü de "yes" olsaydı $\frac{14}{14}\log_2 1 = 0$ olurdu.
- Bütün örnekler sınıflara eşit dağılmış ise $E(S)=1$ (heterojen): $E([7+,7-]) = 1$.
- Arada kalan dağılımlar 0 ile 1 arasında değer alır. Slayttaki grafikte entropi, $p_{+}$'ya göre 0'da ve 1'de sıfır, $0{,}5$'te en yüksek (1) olan bir eğridir (ekrandan, 02:30:00).

> **Ders sonrası not:** Hoca, entropi ne kadar büyük çıkarsa elimizdeki verilerle sorulan soruya o kadar iyi cevap verilebileceğini söyledi. Doğrusu tersidir: entropi belirsizliğin ölçüsüdür. Entropi 0 iken bütün örnekler aynı sınıftadır ve karar kesindir; 1 iken sınıflar tamamen karışıktır. Karar ağacında, bölme sonrasında entropiyi en çok azaltan (bilgi kazancı en büyük olan) özellik seçilir.

### 10.4 Bilgi kazancı

Her özellik için kazanç (gain) hesaplanır ve kazancı en büyük olan özellik köke yazılır:

$$\mathrm{Gain}(S, A) = E(S) - \sum_{v \in \mathrm{Values}(A)} \frac{|S_v|}{|S|}\, E(S_v)$$

Sistemin entropisinden, özelliğin her değerinin olasılığı ile o değere düşen örneklerin entropisinin çarpımlarının toplamı çıkarılır.

**Rüzgâr için örnek** (ekrandan, 02:35:00). Rüzgâr weak olan 8 örneğin 6'sı yes, 2'si no; strong olan 6 örneğin 3'ü yes, 3'ü no:

$$E(S_{weak}) = -\frac{6}{8}\log_2\frac{6}{8} - \frac{2}{8}\log_2\frac{2}{8} \approx 0{,}811, \qquad E(S_{strong}) = -\frac{3}{6}\log_2\frac{3}{6} - \frac{3}{6}\log_2\frac{3}{6} = 1$$

$$\mathrm{Gain}(S,\text{wind}) = 0{,}940 - \frac{8}{14}(0{,}811) - \frac{6}{14}(1{,}0) \approx 0{,}048$$

Değerler python ile kontrol edildi. Aynı hesap humidity, temperature ve outlook için de yapılır.

> **Ek bilgi (derste anlatılmadı):** Slaytlardaki örnek numaralarına göre bu veri seti büyük olasılıkla Quinlan'ın klasik "PlayTennis" veri setidir. Bu veri setinde kazançlar yaklaşık olarak outlook için 0,247, humidity için 0,152, wind için 0,048, temperature için 0,029 çıkar; bu yüzden köke outlook konur.

### 10.5 Ağacın tamamlanması

Kök outlook olunca örnekler şöyle dağılır (ekrandan, 02:40:00):

- Sunny: örnekler 1, 2, 8, 9, 11; $[2+, 3-]$.
- Overcast: örnekler 3, 7, 12, 13; $[4+, 0-]$. Hepsi "yes" olduğu için doğrudan yaprak olur.
- Rainy: örnekler 4, 5, 6, 10, 14; $[3+, 2-]$.

Overcast ise hiçbir ek soru sormadan "tenis oynanır" cevabı verilir. Sunny ve rainy dallarında cevap hem yes hem no olduğu için bir soru daha gerekir. Bu sefer sistemin entropisi yerine sunny dalının entropisi kullanılır:

$$E(S_{sunny}) = -\frac{2}{5}\log_2\frac{2}{5} - \frac{3}{5}\log_2\frac{3}{5} \approx 0{,}971$$

Sunny altında humidity, temperature ve wind için kazanç hesaplanır. Humidity high olan sunny örnekleri 1, 2, 8 ($[0+,3-]$), normal olanlar 9, 11'dir ($[2+,0-]$). İki dal da saf olduğu için kazanç sunny'nin entropisine, yaklaşık $0{,}97$'ye eşittir ve en büyük kazanç budur. Sunny altına humidity konur: high ise "no", normal ise "yes". Aynı işlem rainy için yapılınca altına wind gelir; rüzgârın durumuna göre "yes" ya da "no" denir.

Sonuç ağacı:

```text
outlook
├── sunny    -> humidity
│              ├── high   -> NO
│              └── normal -> YES
├── overcast -> YES
└── rainy    -> wind
               ├── weak   -> YES
               └── strong -> NO
```

Rastgele kurulan ağacın derinliği 3'tü; en fazla üç soru sorarak cevaba ulaşılıyordu. Kazanç hesaplanıp daha fazla bilgi veren özellikler üste yerleştirilince en fazla iki soruyla cevap bulunur. Sıcaklık hiç kullanılmamıştır; bu veri seti için önemli bir özellik değildir.

Hoca, bu hesapların adım adım ve kalemle izlendiğinde karışık olmadığını söyledi. Sınav zamanında bu hesapların uzun sürdüğünü, bu yüzden sorulsa bile bu kadar çok özellikli bir sorunun gelmeyeceğini ekledi. Entropiyle yapılan şey, hangi sorunun önce sorulacağına karar vermektir: doğru soru önce sorulursa tek cevapla karara varılabilir; yanlış soru sorulursa ardından başka sorular da sormak gerekir. Amaç, yaprakların her birinde tek bir sınıfın bilgisinin olmasıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00). Kökü $a$ olan aşağıdaki ağacın pre-order, in-order ve post-order okunuşlarını yazınız: $a$'nın çocukları $b, c, d$; $b$'nin çocukları $e, f$; $e$'nin çocukları $j, k$; $k$'nın çocukları $n, o, p$; $d$'nin çocukları $g, h, i$; $g$'nin çocukları $l, m$.

> **Çözüm:** Pre-order $a, b, e, j, k, n, o, p, f, c, d, g, l, m, h, i$. In-order $j, e, n, k, o, p, b, f, a, c, l, g, m, d, h, i$. Post-order $j, n, o, p, k, e, f, b, c, l, m, g, h, i, d, a$. (Derste sözlü çözüldü; sonuçlar python ile kontrol edildi.)

**Soru 2** (ekrandan, 00:20:00). Verilen iki Huffman ağacına göre "rate" kelimesini kodlayınız.

> **Çözüm:** Sol ağaçta $r=001$, $a=000$, $t=011$, $e=100$; kod $001\,000\,011\,100$. Sağ ağaçta $r=11$, $a=000$, $t=001$, $e=10$; kod $11\,000\,001\,10$.

**Soru 3** (ekrandan, 00:30:00). Elimizde $a, e, k, l, m$ ve $z$ sembollerinden sırasıyla 25, 14, 8, 7, 4 ve 2 adet olsun. Her bir sembol için Huffman kod değerini bulalım.

> **Çözüm:** Genişletilmiş dizi $2, 4, -6, 7, 8, -13, 14, -21, 25, -35, -60$. Kodlar $a\to1$, $e\to01$, $k\to001$, $l\to0000$, $m\to00010$, $z\to00011$. 8 bitlik kodlamada 480 bit, Huffman ile 135 bit gerekir (Bölüm 2.3-2.4).

**Soru 4** (ekrandan, 00:35:00). Sıklıkları $1, 1, 2, 5, 7, 15$ olan altı sembol için genişletilmiş diziyi oluşturunuz.

> **Çözüm:** İkililer $(1,1)\to2$, $(2,2)\to4$, $(4,5)\to9$, $(7,9)\to16$, $(15,16)\to31$. Toplam $2$, eşit değerin soluna yazılırsa dizi $1, 1, -2, 2, -4, 5, 7, -9, 15, -16, -31$ olur (11 eleman). Toplamı eşit değerin sağına yazmak da geçerlidir; seçilen kural sonraki eşitliklerde de aynı uygulanmalıdır. Dizinin son hâli derste ekrana yazılmadı; burada anlatılan adımlardan kuruldu (ara adım eklendi).

**Soru 5** (ekrandan, 01:10:00). Kenarları $A\!-\!B$, $A\!-\!H$, $A\!-\!D$, $D\!-\!F$, $B\!-\!E$, $B\!-\!C$ olan grafta $A$'dan başlayarak DFS uygulayınız.

> **Çözüm:** Çıktı $A, D, F, H, B, E, C$ (yığın adımları Bölüm 4.1'deki tabloda).

**Soru 6** (ekrandan, 01:20:00). Kenarları $A\!-\!B$, $A\!-\!C$, $B\!-\!F$, $C\!-\!E$, $C\!-\!D$, $D\!-\!H$, $H\!-\!J$ olan grafta $A$'dan başlayarak BFS uygulayınız.

> **Çözüm:** Çıktı $A, B, C, F, E, D, H, J$ (kuyruk adımları Bölüm 5.1'deki tabloda).

**Soru 7** (ekrandan, 01:30:00). Bölüm 6.1'deki $7\times7$ maliyet matrisiyle verilen grafın minimum kapsayan ağacını Prim algoritmasıyla 1. düğümden başlayarak bulunuz.

> **Çözüm:** Kenarlar sırasıyla $1\!-\!3$ (100), $1\!-\!4$ (300), $1\!-\!7$ (400), $3\!-\!5$ (500), $5\!-\!6$ (200), $7\!-\!2$ (900). Toplam maliyet 2400 (python ile kontrol edildi; derste sözlü olarak 2600 denmişti).

**Soru 8** (ekrandan, 01:45:00). Bölüm 7.2'deki dokuz düğümlü grafın minimum kapsayan ağacını Kruskal algoritmasıyla bulunuz.

> **Çözüm:** Seçilen ağırlıklar $1, 2, 2, 3, 3, 3, 4, 4$; 8 kenar, toplam 22.

**Soru 9** (derste sözlü, 02:11:45). 3 düğümlü kaç farklı (izomorfik olmayan) ikili ağaç yazılabilir?

> **Çözüm:** $\binom{6}{3}/4 = 20/4 = 5$.

**Soru 10** (ekrandan, 02:15:00). Görünüşleri birbirinin aynı olan 5 paradan biri sahtedir. Sahte olan para diğerlerinden daha ağır veya daha hafif olabilir. Karar ağacını kullanarak hangi paranın sahte olduğuna karar veriniz. Sahte olan para diğerlerine göre hafif midir yoksa ağır mıdır?

> **Çözüm:** Bölüm 9.1'deki karar ağacı; en kötü durumda 3 tartı gerekir.

**Soru 11** (ekrandan, 02:35:00). 9 yes, 5 no örneği olan tenis veri setinde rüzgâr weak için $[6+,2-]$, strong için $[3+,3-]$ ise $\mathrm{Gain}(S,\text{wind})$ nedir?

> **Çözüm:** $E(S)\approx0{,}940$, $E(S_{weak})\approx0{,}811$, $E(S_{strong})=1$; $\mathrm{Gain} = 0{,}940 - \frac{8}{14}\cdot0{,}811 - \frac{6}{14}\cdot1 \approx 0{,}048$.

## Dersin Toparlaması

Bu derste ağaçlar konusu tamamlandı. Önce ağaçta gezinmenin üç temel yolu olan pre-order, in-order ve post-order okunuşları, her alt ağaca aynı kuralın yinelemeli uygulanmasıyla örnek bir ağaç üzerinde çalışıldı. Ardından ağaçların bir uygulaması olarak Huffman kodlama işlendi: sıklıkların sıralanması, dizinin $2n-1$ elemana genişletilmesi, eksi işaretli ara toplamlarla ikili ağacın kurulması ve kodların kökten yaprağa okunması. Kodların yukarıdan aşağıya okunmasının, hiçbir kodun başka bir kodun başlangıcı olmamasını ve böylece sıkıştırılan verinin geri açılabilmesini sağladığı gösterildi.

Daha sonra bir grafın bütün düğümlerini döngüsüz bağlayan kapsayan ağaç kavramı tanıtıldı. Ağırlıksız graflarda yığın kullanan DFS ve kuyruk kullanan BFS, ağırlıklı graflarda ise minimum kapsayan ağacı bulan Prim (maliyet matrisi üzerinde) ve Kruskal (kenarları sıralayıp döngü oluşturmayanları seçerek, $n-1$ kenarda durarak) algoritmaları örneklerle çözüldü. Ağaçlarda izomorfizmin köksüz, köklü ve ikili ağaçlar için hangi şartlara bağlı olduğu anlatıldı. Son olarak karar ağaçları; beş para problemi ve tenis veri seti üzerinden entropi ve bilgi kazancıyla en az soruyla karar veren ağacın nasıl kurulacağı gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
