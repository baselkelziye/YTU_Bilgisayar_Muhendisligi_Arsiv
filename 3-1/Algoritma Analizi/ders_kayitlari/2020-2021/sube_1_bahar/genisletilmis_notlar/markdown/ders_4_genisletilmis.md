# Ders 4 Genişletilmiş Notu: Kaba Kuvvet, Azalt ve Fethet, Böl ve Fethet ve Merge Sort Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Şimdiye kadar yapılanların özeti: problem çözme adımları ve analiz
- 2. Algoritma tasarım tekniklerine giriş: $a^n$ örneği
- 3. Kaba kuvvet (Brute Force)
- 4. Kapsamlı arama (Exhaustive Search)
- 5. Azalt ve fethet (Decrease and Conquer)
- 6. Böl ve fethet (Divide and Conquer)
- 7. Master teoremi (tekrar)
- 8. Merge Sort
- 9. Merge Sort analizi
- Örnek Sorular
- Dersin Toparlaması

## 1. Şimdiye kadar yapılanların özeti: problem çözme adımları ve analiz

Hoca bu dersten itibaren slayt yerine PowerPoint üzerinde kalemle yazarak anlatacağını söyledi. Önce o güne kadar görülenleri hem özetleyen hem de dönemin geri kalanına ışık tutan bir çerçeve çizdi (ekrandan, 00:15:00).

Algoritmalarla uğraşmanın amacı bir gerçek dünya problemini çözmektir (*to solve a real-world problem*). Bunun adımları şöyledir:

- **Problemi anlamak** (*understand the problem*): problem nedir, girdileri ve çıktıları nelerdir?
- **Kesin ya da yaklaşık çözüm ve tasarım tekniği seçimi** (*exact vs approximate solution, algorithm design technique*): bazı problemlerin kesin çözümünü veren verimli bir algoritma bugün bilinmez; o zaman en iyiye yakın (yaklaşık) bir çözüm aranır.
- **Algoritmayı tasarlamak** (*design an algorithm*): bu dersten itibaren işlenecek konular bu adımla ilgilidir.
- **Doğruluğunu kanıtlamak** (*prove correctness*): algoritma doğru sonuç veriyor mu?
- **Algoritmayı analiz etmek** (*analyze the algorithm*): şimdiye kadar görülen asimptotik analiz ve kaba (deneysel) analiz.
- **Algoritmayı kodlamak** (*code the algorithm*).

Analiz başlığı altında en iyi (best case), ortalama (average case) ve en kötü durum (worst case) incelendi. Sonuçlar asimptotik notasyonlarla yazılır: $\Omega$, $\Theta$, $O$ ve ayrıca $o$, $\omega$. Hoca ağırlığın ilk üçünde olduğunu, soruları daha çok bunlarla ilgili soracağını söyledi.

Bir algoritmanın baktığımız özellikleri şunlardır:

- Zaman verimliliği (*time efficiency*)
- Bellek verimliliği (*space efficiency*)
- Basitlik (*simplicity*)
- Genellik (*generality*)

İlk ikisi asimptotik notasyonlar ve fonksiyonlarla bilimsel biçimde ifade edilebilir.

> **Hocanın vurgusu:** Yeni bir algoritma tasarlamadan önce hem tasarım tekniklerini hem analiz tekniklerini bilmek gerekir; böylece elimizde hazır araçlar olur. Dönem boyunca her tasarım stratejisinde geliştirilen algoritmalar, öğrenilen analiz teknikleriyle analiz edilecek.

### 1.1 İteratif ve özyinelemeli analiz

Hoca, algoritmaların analizinin iki başlık altında yapıldığını hatırlattı: özyinelemeli (recursive) algoritmalar ve iteratif algoritmalar. İkisinde de önce bir **temel operasyon** (basic operation) belirlenir ve bu operasyonun kaç kez yapıldığı sayılır.

- İteratif yaklaşımda sayım genellikle bir toplam sembolüyle yapılır.
- Özyinelemeli yaklaşımda bir yineleme bağıntısı kurulur ve geriye doğru yerine koyma (backward substitution) ya da özel şartları sağlıyorsa Master teoremiyle çözülür.

Master teoremi aslında özyinelemeli bir algoritmada temel operasyonun ne kadar derinliğe kadar tekrarlanacağını söyler. Hoca örnek olarak $T(n) = 2T(n/2) + n^2$ bağıntısını verdi: her adımda $n^2$ mertebesinde iş yapılır, problem $n/2, n/4, \dots$ diye bölünerek $\log n$ derinliğe kadar iner. Amaç, temel operasyonun her derinlikte ne kadar tekrarlandığını $n = 1$'e ulaşana kadar bulmaktır.

> **Ders sonrası not:** Hoca bu örneğin sonucunu $n^2 \log n$ olarak söyledi. Seviye maliyetleri $n^2,\ 2\cdot(n/2)^2 = n^2/2,\ 4\cdot(n/4)^2 = n^2/4, \dots$ diye geometrik olarak azaldığı için toplam $\Theta(n^2)$'dir. Bölüm 7'deki Master teoremiyle de $a = 2$, $b = 2$, $d = 2$ ve $a < b^d = 4$ olduğundan $T(n) \in \Theta(n^2)$ bulunur.

## 2. Algoritma tasarım tekniklerine giriş: $a^n$ örneği

Hoca tasarım tekniklerine bir soruyla girdi: bir sayının $n$. kuvvetini, $a^n$'i hesaplayan bir algoritma nasıl tasarlanır?

**Soru:** $a^n$ nasıl hesaplanır? **Cevap (bir öğrenci):** Bir döngü içinde $n$ kez çarparız. Hoca bunu toparladı: bir başlangıç değeri tanımlanır ve $i = 1$'den $n$'e kadar `result = result * a` yapılır. İlk akla gelen çözüm budur.

Sonra şu fikri ortaya attı: $a^n$ yerine önce $a^{n/2}$ bulunsa ve bu sonucun karesi alınsa daha hızlı olmaz mı? Döngü yarıya iner, geri kalan yarıyı hesaplamaya gerek kalmaz, çünkü $a^{n/2}\cdot a^{n/2} = a^n$'dir. İki yaklaşım arasındaki bu hız farkı gibi fikirlerden yola çıkarak farklı algoritma tasarım teknikleri ortaya çıkmıştır. Bu tekniklerin bir kısmı matematikçilerden, kimyacılardan, endüstri mühendislerinden, yani farklı problemlerle uğraşan alanlardan gelmiş; bilgisayar bilimleri bunları derleyip bir sistematiğe oturtmuştur. Dersin kitabı da (Levitin, *Introduction to the Design and Analysis of Algorithms*) bu sistematiği farklı problemler üzerinde anlatır.

## 3. Kaba kuvvet (Brute Force)

### 3.1 Tanım

Kaba kuvvet, bir probleme ilk akla gelen, doğrudan yaklaşmaktır. Genellikle çok kafa yormadan ilk adımda yazılabilecek algoritmalar bu sınıftadır; temel programlama derslerinde görülen birçok algoritma böyledir. Tahtadaki tanım (ekrandan, 00:35:00):

> *Brute force is a straightforward approach to solve a problem, usually directly based on the problem statement and definitions of the concepts involved.*

Yani kaba kuvvet, problemi çözmek için akla ilk gelen "dümdüz" yaklaşımdır ve doğrudan problemin ifadesine ve kullanılan kavramların tanımlarına dayanır. Her problemin kendine göre bir doğrudan yaklaşımı vardır.

### 3.2 Yaklaşım ile algoritma farkı

Hoca tanımdaki "approach" kelimesinin bilerek seçildiğini vurguladı (ekranda "Algorithm vs Approach" notu). Yaklaşım, problemi kafada tasarlamaktır: "$x$'i kullanıcıdan alırım, karesini hesaplarım, şöyle yaparım." Bunu bir bilgisayarda kodlanabilecek kadar ayrıntılı, belirsizliksiz (*unambiguous*) ve sonlu (*finite*) biçimde yazmak ise algoritmadır.

### 3.3 Kaba kuvvet örnekleri

Tahtada listelenen örnekler (ekrandan, 00:40:00):

1. $a^n$: $a^n = \underbrace{a \times a \times \dots \times a}_{n}$
2. $\gcd(m, n)$
3. Selection Sort, Bubble Sort, Insertion Sort
4. Linear search (sequential search)
5. String matching
6. Closest pair

#### $a^n$

$a^n$ tanımı gereği $a$'yı $n$ kez çarpmaktır ve bunu bir `for` döngüsüyle yapmak ilk akla gelendir. Oysa $a^{n/2}$'yi kendisiyle çarpmak ya da $a^{n/4}$'ü bulup dördüncü kuvvetini almak işi kısaltır. Algoritma geliştirmenin kendisi de iteratif bir süreçtir: önce kaba çözüm yazılır, sonra iyileştirilir.

#### OBEB (en büyük ortak bölen)

**Soru:** İki sayının OBEB'i nasıl bulunur? **Cevap (bir öğrenci):** İkiden başlayıp asal sayılarla bölerek, iki sayıyı aynı anda bölenleri çarparız.

Hoca buradan önemli bir noktaya geçti: "asal sayılar" dendiğinde bilgisayar bir sayının asal olduğunu nasıl anlayacak? Algoritmanın belirsizliksizlik kuralı gereği bunu da tarif etmek gerekir: bakılan sayı asal mı, ikiden sonraki asal hangisi? Bir problemle yola çıkılıp birkaç yeni problemle karşılaşılmış olur.

**Soru:** Başka bir kaba kuvvet önerisi? **Cevap (bir öğrenci):** Küçük sayıdan başlayarak bir döngü içinde bire kadar her sayıyı deneriz, ikisini de kalansız böldüğü ilk yerde dururuz.

Hoca bu cevabı doğru buldu ve toparladı (ekrandan, 00:30:00):

```text
x = min(m, n)
x'ten aşağı doğru (1'e kadar) her değeri dene:
    değer hem m'yi hem n'yi tam bölüyorsa dur, OBEB bu değerdir
```

Örnek, 6 ve 14: 6 ikisini de bölmez, 5 bölmez, 4 bölmez, 3 bölmez, 2 ikisini de böler: $\gcd(6,14) = 2$.

Örnek, 5 ve 12: 5, 4, 3, 2 bölmez, 1 böler. 1'e kadar inilmesi sayıların aralarında asal olduğunu gösterir: OBEB 1'dir. Bu yüzden aramanın 2'de değil 1'de bitmesi daha doğrudur.

Bu yöntem, ilkokulda öğretilen "en küçük asaldan başla, ikisini de bölüyorsa işaretle, bölmüyorsa bir sonraki asala geç" yönteminden daha kolay bir algoritmadır, çünkü bir sonraki asalı bulma problemi ortadan kalkar. Öklid ise daha da iyisini bulmuştur (Bölüm 5.4).

#### Sıralama

**Soru:** Kaba kuvvet sıralama algoritmalarına örnek? **Cevap (öğrenciler):** Bubble Sort, Selection Sort.

Hocaya göre Selection Sort daha kaba bir yaklaşımdır ve akla önce gelir: dizinin en küçüğü bulunup başa konur, sonra kalanların en küçüğü ikinci sıraya konur. Bubble Sort'ta 7, 3, 6, 8, 4 gibi bir dizide komşuları karşılaştırmak biraz daha geç akla gelir. Insertion Sort ise iskambil kartlarını elde doğru yere yerleştirmeye benzer ve Bubble ve Selection Sort'a göre daha iyi, daha optimize bir konumdadır.

#### Doğrusal arama

**Soru:** Arama algoritmalarından kaba kuvvet örneği? **Cevap (bir öğrenci):** Linear search.

Dizinin sıralı olup olmadığına bakılmadan ilk elemandan son elemana kadar aranır. Buna sıralı arama (sequential search) da denir.

#### String matching

Elimizde bir metin, örneğin `abcdefghj`, ve aranan bir desen, örneğin `abz` olsun. Kaba kuvvet yaklaşımında desenin ilk karakteri metnin ilk karakteriyle, eşleşiyorsa ikinci karakter ikinciyle karşılaştırılır. Uyuşmazlık olursa o konumda eşleşme yoktur ve desen bir sonraki konuma kaydırılır.

Hoca burada bir alternatif fikir de verdi: karşılaştırmaya desenin sonundan başlamak. `abz` örneğinde `a` ve `b` eşleşir, `c` ile `z` eşleşmez; baştan bakıldığında ilk iki karşılaştırma boşa gitmiş olur. Sondan bakılsaydı `c` ile `z` hemen karşılaştırılıp ileri atlanabilirdi. İstatistiksel olarak aranan kelimenin bir metinde geçme sayısı metnin kelime sayısından çok daha azdır; bu yüzden sondan bakmak birçok kelime için avantajlıdır. Bu, ileride görülecek farklı bir tekniktir.

String matching yalnız bir Word ya da PDF dosyasında arama yapmak değildir. Biyoinformatikte gen dizilimleri ya da kodlanmış protein dizilimleri birbiriyle eşleştirilir; küçük bir gen parçası bile birkaç megabaytlık bir metin, yani birkaç yüz sayfalık bir kitap kadardır. Bu büyüklükte kaba kuvvet çok zorlaşır.

Kitabın slaytındaki kaba kuvvet string matching algoritmasında dış döngü metin boyunca konumları, iç döngü desenin karakterlerini gezer; karakterler eşit olduğu sürece iç döngü devam eder, eşit değilse çıkılır ve bir sonraki konumdan devam edilir.

<!-- BELİRSİZ: Hoca en kötü durum için "n çarpı n'lik bir karşılaştırma" dedi; slayttaki verimlilik ifadesi karede okunmadı. -->

> **Ek bilgi (derste anlatılmadı):** Metin uzunluğu $n$, desen uzunluğu $m$ ise kaba kuvvet string matching en kötü durumda büyük olasılıkla $m(n-m+1)$ karakter karşılaştırması yapar, yani $O(nm)$'dir. Desenin sondan karşılaştırılıp uyuşmazlıkta ileri atlanması fikri, Boyer-Moore gibi algoritmaların temelidir.

#### En yakın nokta çifti (closest pair)

İki boyutlu düzlemde noktalar vardır ve birbirine en yakın iki nokta aranır. Hoca bunun yapay zekâ ve makine öğrenmesinde, örneğin KNN algoritmasında kullanıldığını söyledi. Kaba kuvvet çözümü: bir nokta seçilir ve bütün noktalara uzaklığına bakılır, sonra bir sonraki nokta seçilir. Bu yaklaşık $n^2$ karşılaştırma demektir. $n = 10^6$ nokta varsa $10^{12}$ karşılaştırma gerekir; veri iki değil yirmi boyutlu olsa daha da maliyetlidir.

#### Kitaptaki diğer örnekler

Hoca kitabın 3. bölüm slaytlarına da kısaca baktı: $n!$ hesabı, iki matrisin çarpımı, string matching ve Selection Sort. Selection Sort'un zamanı $n^2$ bulunmuştu; bellek açısından yalnız bir geçici (`temp`) değişkene ihtiyaç duyar. Hoca Selection Sort'un kararlı (stable) olmadığını, ancak ek kontrollerle kararlı hâle getirilebileceğini belirtti.

### 3.4 Kaba kuvvet polinom değerlendirme

Kitaptaki slayt (ekrandan, 00:45:00): $p(x) = a_n x^n + a_{n-1}x^{n-1} + \dots + a_1 x^1 + a_0$ polinomunun $x = x_0$ noktasındaki değeri bulunacak.

```text
p <- 0.0
for i <- n downto 0 do
    power <- 1
    for j <- 1 to i do        // compute x^i
        power <- power * x
    p <- p + a[i] * power
return p
```

Verimlilik: $\sum_{0 \le i \le n} i = \Theta(n^2)$ çarpma.

Burada her terimin kuvveti ayrı bir iç döngüyle sıfırdan hesaplanır; dışta da $n$ terim için ikinci bir döngü vardır. Hoca iyileştirmeyi şöyle anlattı: $x^{i-1}$ biliniyorsa $x^i$ ona bir çarpmayla ulaşılır. Kuvvetler üst üste biriktirilirse fazladan döngüye gerek kalmaz ve maliyet $n^2$'den $n$'e düşer. Kitabın bir sonraki slaytı bu iyileştirmeyi (Polynomial Evaluation: Improvement) gösterir.

### 3.5 Kaba kuvvetin güçlü ve zayıf yanları

Güçlü yanları:

- Çok geniş bir problem yelpazesine uygulanabilir.
- Basittir; düşünmesi kolaydır, çok kafa yormak gerekmez.
- Çok büyük verilerle çalışılmıyorsa makul sonuç verir.
- Sıralama gibi standart problemlere doğrudan uyarlanabilir (ör. notları sıralamak sayıları sıralamaktır).

Zayıf yanları:

- Verimli algoritmalar nadiren böyle çıkar.
- Bazıları kabul edilemez derecede yavaştır. Hoca şifre kırma örneğini verdi: $n$ karakterli bir şifrenin her karakteri 256 farklı ASCII değerinden biri olabiliyorsa $256^n$ deneme gerekir.
- Diğer tasarım teknikleri kadar yapıcı değildir.

## 4. Kapsamlı arama (Exhaustive Search)

Kapsamlı arama, kaba kuvvetin bir alt kümesi gibi düşünülebilir. Özellikle permütasyon, kombinasyon ve alt küme içeren kombinatoryal problemlerde bütün olasılıkları deneyip en iyisini seçmeye dayanır.

Hoca önce şunu sordu: şimdiye kadar görülen sıralama algoritmalarının en kötü durum karmaşıklığı en fazla neydi? Cevap $n^2$'dir. Hiçbir sıralama algoritması $2^n$ ya da $3^n$ gerektirmez; sıralama polinom zamanda çözülür. Ama bazı problemler vardır ki polinom zamanda çözülmeleri hâlâ mümkün değildir, yalnız üstel (eksponansiyel) ya da faktöriyel zamanda çözülebilirler.

### 4.1 Gezgin satıcı problemi (Traveling Salesman)

**Soru:** Gezgin satıcı problemi nedir? **Cevap (öğrenciler):** Bir noktadan başlayıp bütün düğümleri gezip başlangıç noktasında bitmek gerekir.

Hoca bunu Türkiye'nin 81 iliyle anlattı. İstanbul'dan başlayıp bütün illeri birer kez gezip İstanbul'a geri dönülecek. Karayolu değil, kuş uçuşu her ilden her ile gidilebildiği düşünülsün. İlk adımda 80, sonra 79, sonra 78 seçenek vardır; yani $80!$ farklı tur vardır ve bunların en küçük maliyetlisi aranır (ekranda: $80 \cdot 79 \cdot 78 \cdots$, $\min(80!)$; ekrandan, 00:40:00). Bir turun maliyetini hesaplamak zor değildir, ama $80!$ çok büyük bir sayıdır ve bütün dizilimleri üretmek pratikte imkânsızdır. Bu problemde kaba kuvvet ve kapsamlı arama neredeyse çözümsüz kalır.

Kitaptaki 4 şehirli örnekte (a, b, c, d) turlar tek tek listelenip uzunlukları hesaplanır. Başlangıç ve bitiş sabitlendiğinde aradaki 3 şehrin $3! = 6$ sıralaması vardır; genel olarak $(n-1)!$ mertebesinde tur çıkar. Bu problemin ilerideki bölümlerde daha hızlı çözümleri görülecektir.

<!-- BELİRSİZ: Hoca kitap örneğindeki tur uzunluklarını 17, 21, 20 olarak okudu; slayt karede görülmedi, değerler doğrulanamadı. -->

Hoca bu örnekte Hamilton devresi kavramına da değindi: A'dan başlayıp B, C, D üzerinden A'ya dönmek bir yoldur; A, C, D, B, A başka bir yoldur.

### 4.2 Sırt çantası problemi (Knapsack)

**Soru:** Knapsack problemi nedir? **Cevap (bir öğrenci):** Bir hırsızın çantasına sığacak eşyalardan en değerlisini seçmesiyle ilgili; "yükte hafif pahada ağır".

Hoca toparladı: $V$ hacimli (ya da kapasiteli) bir torba var. Hacimleri $V_1, V_2, \dots, V_n$ ve değerleri $P_1, P_2, \dots, P_n$ olan eşyalar konulacak. Torbaya sığan ve en fazla kâr veren seçim aranır. Sıralamayla çözmeye çalışılsa hangi ölçüte göre sıralanacağı belli değildir: hacme göre sıralanırsa değerler, değere göre sıralanırsa hacimler gözden kaçar. Tek tek denemek gerekir; bu bir kombinatoryal problemdir.

Kitabın örneğinde kapasite 10'dur ve bütün alt kümeler (subset) toplam ağırlıkları ve değerleriyle denenir. Toplam ağırlığı kapasiteyi aşan alt kümeler uygun (feasible) değildir; uygun olanların en değerlisi seçilir. $n$ eşya için $2^n$ alt küme vardır: 4 eşyada 16, 40 eşyada $2^{40}$ deneme gerekir. Hoca, gezgin satıcıda faktöriyel olan karmaşıklığın bu problemde üstel olduğunu belirtti.

<!-- BELİRSİZ: Hoca kitap örneğinde en iyi seçimin "2 ile 3" ve değerin 80 olduğunu söyledi; slayt karede görülmedi, eşya değerleri ve sonuç doğrulanamadı. -->

### 4.3 İş atama problemi (Assignment Problem)

Kitabın slaytı (ekrandan, 00:50:00): $n$ kişi $n$ işe, her kişiye bir iş olacak biçimde atanacak. Kişi $i$'yi iş $j$'ye atamanın maliyeti $C[i,j]$'dir. Toplam maliyeti en küçük yapan atama aranır.

| | Job 0 | Job 1 | Job 2 | Job 3 |
|---|---|---|---|---|
| Person 0 | 9 | 2 | 7 | 8 |
| Person 1 | 6 | 4 | 3 | 7 |
| Person 2 | 5 | 8 | 1 | 8 |
| Person 3 | 7 | 6 | 9 | 4 |

Algoritmik plan: bütün geçerli atamaları üret, maliyetlerini hesapla, en ucuzunu seç. Kaç atama vardır? $n!$. Problem bir maliyet matrisi üzerinden de ifade edilebilir. İş ve işçi sayısı artarsa faktöriyel karmaşıklık hızla büyür. Hoca, bu problemi çok daha hızlı çözen algoritmaların bulunduğunu, endüstri mühendislerinin kullandığı yöntemlere ve özellikle Macar algoritmasına (Hungarian method) değindi.

> **Ek bilgi (derste anlatılmadı):** Bu tablodaki $4! = 24$ atamanın hepsi denendiğinde en küçük toplam maliyet 13'tür: Person 0 → Job 1 (2), Person 1 → Job 0 (6), Person 2 → Job 2 (1), Person 3 → Job 3 (4). Bu değer bütün permütasyonlar python ile denenerek bulundu.

### 4.4 Kapsamlı arama üzerine son yorumlar

- Euler devreleri, en kısa yol ve minimum kapsayan ağaç algoritmaları, yukarıdaki problemlerin bazılarına daha hızlı alternatifler sunar; bunun karşılığında bazıları belleği biraz daha fazla kullanır.
- Kapsamlı arama çoğu zaman kesin (exact) çözüm için bilinen tek yoldur, ama uygulanabilirliği soru işaretidir. Örneğin 10 karakterli ve her karakteri 256 değer alabilen bir şifrede bütün durumları denemek mümkün olmaz.

### 4.5 Kaba kuvvet ile kapsamlı arama farkı

Ders sonunda bir öğrenci bu iki kavramın birbirine karıştığını söyledi.

**Soru:** Exhaustive search ile brute force arasındaki fark nedir? **Cevap:** Brute force genel bir tekniktir; yalnız arama algoritmalarını kapsamaz. Örneğin $a^n$'i hesaplamak bir arama değildir ama kaba kuvvetle yapılabilir. Exhaustive search ise bir arama yöntemidir: gezgin satıcı ya da knapsack problemlerinde bir arama uzayı vardır ve bunun içinden en uygun çözüm aranır. Bu yüzden exhaustive search, brute force'un bir alt kümesidir.

**Soru:** O hâlde exhaustive search algoritmalarının hepsi brute force ile mi çözülüyor? **Cevap:** Daha doğru ifade şudur: gezgin satıcı bir problemdir; exhaustive search bu probleme önerilen bir çözüm yöntemidir ve bu yöntem brute force tekniğinin bir alt kümesidir. Problem ile probleme sunulan çözüm algoritması farklı şeylerdir.

## 5. Azalt ve fethet (Decrease and Conquer)

### 5.1 Tanım ve türleri

Azalt ve fethet, problemi daha küçük boyutlu bir probleme indirgeyerek (azaltarak) çözme tekniğidir. Hoca kaba kuvvete alternatif olarak sunulan bu tekniğin üç türünü yazdı (ekrandan, 01:10:00):

- **Sabit miktarda azaltma** (*decrease by a constant*): genellikle 1.
- **Sabit çarpanla azaltma** (*decrease by a constant factor*): genellikle 2; çarpan bazen 3 ya da 5 gibi bir değer de olabilir.
- **Değişken boyutlu azaltma** (*variable size decrease*): azaltma miktarı her iterasyonda değişir.

Genel strateji:

```text
problem with size n
      |
subproblem of size n-1
      |
solution of subproblem
      |
overall solution
```

$n$ elemanlı problem $n-1$ (ya da başka bir küçük boyut) elemanlı bir alt probleme dönüştürülür, alt problemin çözümü üretilir ve bu çözüm genişletilerek bütün problemin çözümü elde edilir. Bu işlem tekrarlanır.

### 5.2 Bir azaltma ile $a^n$

$a^n = a^{n-1} \cdot a$ olduğundan $a^{n-1}$ hesaplanıp $a$ ile çarpılabilir. Bu bir azaltmadır (*decrease by one*).

Hoca öğrencilerden özyinelemeli bağıntıyı istedi. Bir özyinelemeli algoritmada bir temel durum (durma koşulu) ve sürekli tekrarlanan diğer durumlar vardır.

**Soru:** Bu problemde temel durum nedir? **Cevap (bir öğrenci):** $n$ sıfırken sonuç 1 olur. Hoca: $a^0 = 1$ olduğundan `n == 0` ise 1 döner.

**Soru:** Diğer durumlarda ne yapılır? **Cevap (bir öğrenci, biraz karışıklıktan sonra):** $f(n-1)$ çağrılıp $a$ ile çarpılır.

Hoca, fonksiyonun hem $a$'yı hem $n$'i parametre olarak alması gerektiğini belirterek bağıntıyı şöyle yazdı (ekrandan, 01:10:00):

$$f(a,n) = \begin{cases} 1, & n = 0 \\ f(a, n-1)\cdot a, & n > 0 \end{cases}$$

İz (ekrandan, 01:15:00): $f(2,3)$ hesaplanırken $n \ne 0$ olduğundan $f(2,2)\cdot 2$ çağrılır; $f(2,2)$ de $f(2,1) \cdot 2$'yi, o da $f(2,0)\cdot 2$'yi çağırır. $f(2,0)$ temel durumdur ve başka çağrı yapmadan 1 döndürür. Dönüşte $f(2,1) = 2$, $f(2,2) = 4$ ve $f(2,3) = 8$ bulunur. Azaltma her adımda sabit bir sayıyla, 1 ile yapılmıştır.

### 5.3 Sabit çarpanla azaltma ile $a^n$

Aynı problem $a^n = (a^{n/2})^2$ fikriyle de çözülebilir. Burada her adımda $n$ yarıya iner: 6 girilirse 3, sonra 1 olur. Bölen sabittir ama azalan miktar $n$'e bağlı olarak değişir.

Temel durum yine $n = 0$ için $a^0 = 1$'dir ($a \ne 0$ kabul edilir). $n$'in çift ve tek olduğu durumlar ayrı ele alınmalıdır: 8. kuvvet için 4., onun için 2., onun için 1. kuvvet bulunur ve sorun çıkmaz; ama 9 gibi tek bir sayı doğrudan ikiye bölünemez. Tahtadaki bağıntı (ekrandan, 01:15:00):

$$a^n = \begin{cases} 1, & n = 0 \\ \left(a^{n/2}\right)^2, & n \text{ çift} \\ \left(a^{(n-1)/2}\right)^2 \cdot a, & n \text{ tek} \end{cases}$$

İz, $a^7$ için: 7 tek olduğundan $(a^3)^2 \cdot a$ hesaplanır, yani $a^6\cdot a$. $a^3$ de tektir: $(a^1)^2 \cdot a$. $a^1$ tektir: $(1-1)/2 = 0$ olduğundan $(a^0)^2 \cdot a = 1 \cdot a$. Dönüşte $a^1 = a$, $a^3 = a^2\cdot a$ ve en sonda $a^7 = (a^3)^2 \cdot a$ bulunur. Hoca, bir azaltma sürümünde iki koşul yeterken bu sürümde üç koşul (`if`) gerektiğini belirtti.

İki sürüm python ile denendi: $f(2,3) = 8$, $2^7 = 128$ ve $3^{13}$ doğru hesaplanıyor.

### 5.4 Değişken boyutlu azaltma: Öklid algoritması

Değişken boyutlu azaltmanın en güzel örneği OBEB için Öklid algoritmasıdır. $m > n$ olmak üzere (ekrandan, 01:20:00):

$$\gcd(m,n) = \begin{cases} n, & m \bmod n = 0 \\ \gcd(n,\ m \bmod n), & m \bmod n \ne 0 \end{cases}$$

Hoca $m$'nin her zaman $n$'den büyük yazılması gerektiğini, ters yazılırsa algoritmanın yine çalışacağını ama bir iterasyon fazla döneceğini söyledi.

- $\gcd(12, 4) = \gcd(4, 0)$: $12 \bmod 4 = 0$ olduğundan sonuç 4.
- $\gcd(42, 4) = \gcd(4, 2) = \gcd(2, 0)$: $42 \bmod 4 = 2$, $4 \bmod 2 = 0$; sonuç 2.

Her adımda elde edilen bölme miktarı sürekli değiştiği için bu değişken boyutlu bir azaltmadır.

**Soru:** Mod operatörünü kullanabiliyorsak üs alırken de üs operatörünü kullanabilir miyiz? **Cevap:** Birçok programlama dilinde mod doğrudan operatör seviyesinde tanımlıdır ve yinelemeli bir işlem gerektirmez; toplama, çıkarma, çarpma, bölme gibi beşinci bir temel işlem kabul edilir. Üs alma ise (belki Python dışında) birçok dilde operatör olarak tanımlı değildir ve arka planda yinelemeli bir işlem gerektirir. Kaba kuvvetle hesaplanırsa $n$ karmaşıklıklı bir iştir; bu yüzden analizde tek işlem gibi yazılamaz.

### 5.5 Sabit çarpanla azaltma: İkili arama (Binary Search)

İkili arama, sıralı bir dizide arama alanını her adımda sabit bir çarpanla, ikiye bölerek daraltır.

**Soru:** İkili arama neden "decrease by a constant factor" örneğidir? **Cevap (bir öğrenci):** Sürekli ikiye bölüyoruz. Hoca: sürekli sabit olarak ikiye bölme yapıldığı için böyledir.

Girdi: sıralı $A[0..n-1]$ dizisi ve aranan $K$ elemanı. Çıktı: elemanın indeksi ya da böyle bir eleman yoksa $-1$ (*index or $-1$ if there is no such element*). Tahtadaki sözde kod (ekrandan, 01:25:00):

```text
l <- 0, r <- n-1
while (l <= r) {
    m = (l + r) / 2
    if K = A[m] return m;
    else if K < A[m] r <- m-1
    else l <- m+1
}
return -1;
```

<!-- BELİRSİZ: Tahtada girdi "A[0..n-2]" gibi okunuyor; hoca sözlü olarak "0'dan n-1'e kadar" dedi, notta A[0..n-1] yazıldı. -->

Sol ve sağ işaretçiler dizinin iki ucundan başlar. Orta nokta $m$ hesaplanır; $K = A[m]$ ise $m$ döndürülür. $K < A[m]$ ise sol yarıya bakılır ($r = m - 1$), değilse sağ yarıya ($l = m + 1$). Döngüden hiçbir şey döndürülmeden çıkılırsa eleman yoktur ve $-1$ döner.

**Soru:** En iyi durum karmaşıklığı nedir? **Cevap (bir öğrenci):** Şanslıysak aranan eleman ilk orta noktada bulunur. Hoca: $C_{best}(n) \in O(1)$.

Ortalama durum, bulunma ve bulunamama gibi birçok parametre içerdiği için incelenmedi.

En kötü durumda orta noktada bulunamaz, dizinin yarısı elenir, sonra kalan yarının yarısına bakılır. Bağıntı:

$$C_w(n) = C_w(\lfloor n/2 \rfloor) + 1$$

Buradaki $+1$, her adımda orta elemanla yapılan karşılaştırmadır; $n/2$ ise sabit çarpanın kendini gösterdiği yerdir. Geriye doğru yerine koymayla çözmek için $n = 2^k$ konur:

$$C_w(2^k) = C_w(2^{k-1}) + 1 = \dots = k + 1$$

$k = \log_2 n$ yerine yazılınca:

$$C_w(n) = \lfloor \log_2 n \rfloor + 1 \in O(\log n)$$

Python ile $C_w(1) = 1$ alınarak $n = 1, 2, 3, 7, 8, 16, 100$ için bağıntı ile $\lfloor\log_2 n\rfloor + 1$ formülünün aynı değeri verdiği doğrulandı.

Hoca bazı algoritmaların arama uzayını üçe ya da dörde böldüğünü, bilgisayar bilimlerinde ise genellikle ikiye bölündüğünü ekledi. Ayrıca azaltma yapılırken $a^n$ örneğinde olduğu gibi farklı durumlarda (tek/çift) farklı işlemler yapılabildiğini hatırlattı.

## 6. Böl ve fethet (Divide and Conquer)

Böl ve fethette problem, ideal olarak aynı boyutta küçük alt problemlere bölünür. Her alt problem aynı algoritmayla ayrı ayrı çözülür; yukarıda ne yapıldıysa aşağıda da aynısı yapılır. Elde edilen çözümler birleştirilerek bütün problemin çözümü bulunur. Azalt ve fethetteki "tekse şunu, çiftse bunu yap" gibi durum ayrımı burada temel değildir; her parçaya aynı işlem uygulanır.

Tahtadaki şema (ekrandan, 02:15:00):

```text
                    problem of size n
          /                 |                  \
   subproblem_1       subproblem_2    ...    subproblem_N
       n/N                n/N                    n/N
        |                  |                      |
   solution S1        solution S2            solution SN
          \                 |                  /
                  combine all solutions
```

Üç adım:

1. **Böl** (*divide*)
2. **Fethet** (*conquer*): her parçanın çözümü
3. **Birleştir** (*combine*)

Hoca bu stratejinin siyaset gibi başka alanlarda da kullanıldığını belirtti. Nasıl bölüneceği algoritmaya göre değişir. Hem azalt ve fethette hem böl ve fethette algoritmalar bir yineleme bağıntısı üzerinden analiz edilir (*recurrence relations are used to solve our problem*).

## 7. Master teoremi (tekrar)

> **Hocanın vurgusu:** Master teoremi burada çok kullanılacak. "Master teoremiyle çöz" denirse en kısa yol budur; "backward substitution ile çöz" denirse uzun uzun çözmek gerekir. Bu yüzden teoremi hatırlamak önemlidir.

Teorem (ekrandan, 01:35:00): $T(n) = a\,T(n/b) + f(n)$ ve $f(n) \in \Theta(n^d)$, $d \ge 0$ ise

$$T(n) \in \begin{cases} \Theta(n^d), & a < b^d \\ \Theta(n^d \log n), & a = b^d \\ \Theta(n^{\log_b a}), & a > b^d \end{cases}$$

$f(n)$ polinomsal bir fonksiyondur: $1, n, n^2, n^3, \dots$ ($d = 0$ ise $f(n) = 1$).

Bağıntıdaki terimlerin anlamı:

- $a$: kod içindeki özyinelemeli fonksiyon çağrısı sayısı (*function call*).
- $b$: problem uzayının kaça bölündüğü (*number of division*); $n$ eleman sayısıdır (number of instances).
- $f(n)$: her çağrıda temel operasyon için harcanan iş (*the efficiency for basic operation*).

Sezgi: her fonksiyon çağrısında $f(n)$ kadar iş yapılır. $n$ elemanlı problem ikiye bölünürse ve $f(n) = n^2$ ise ilk seviyede $n^2$, ikinci seviyede iki tane $(n/2)^2 = n^2/4$ iş vardır; bu, ikinci seviyenin toplamı olarak $2n^2/4$ eder. Bölünme bire ulaşana kadar sürer; Master teoremi, derinlik ile her seviyedeki iş arasındaki ilişkiyi kısa yoldan verir. Hoca, $d = 0$ olduğunda her çağrıdaki işin yalnız $O(1)$ olduğunu ve bu durumda genellikle üçüncü duruma, $n^{\log_b a}$ sonucuna gelindiğini söyledi.

### 7.1 Örnek: $A(n) = 2A(n/2) + 1$

Tahtadaki örnek (ekrandan, 01:35:00):

- $a = 2$ (katsayı)
- $b = 2$
- $f(n) = 1 = n^0$, yani $d = 0$

$b^d = 2^0 = 1$ ve $a = 2 > 1$ olduğundan üçüncü durumdayız. Hoca önce yanlışlıkla ilk duruma bakıp kendini düzeltti ve sonucu üçüncü durumdan verdi:

$$A(n) \in \Theta(n^{\log_2 2}) = \Theta(n)$$

Hoca, azalt ve fethet için kullanılan ayrı bir Master teoremi sürümü de olduğunu, ama şimdilik böl ve fethette kullanılan bu sürümün yeterli olduğunu söyledi.

## 8. Merge Sort

Merge Sort böl ve fethet tekniğine uygun bir algoritmadır: büyük bir veriyi tek başına çözmek yerine en temel parçalara kadar böler, sonra birleştirir. Hoca bunun veri yapıları dersinde görüldüğünü hatırlattı.

### 8.1 Örnek: 8, 3, 2, 9, 7, 1, 5, 4

Kitaptaki örnek (ekrandan, 01:40:00):

```text
              8 3 2 9 7 1 5 4
           /                   \
      8 3 2 9                 7 1 5 4
      /     \                 /     \
   8 3       2 9           7 1       5 4
   / \       / \           / \       / \
  8   3     2   9         7   1     5   4
   \ /       \ /           \ /       \ /
   3 8       2 9           1 7       4 5
      \     /                 \     /
      2 3 8 9                 1 4 5 7
           \                   /
              1 2 3 4 5 7 8 9
```

Dizi önce iki eşit parçaya bölünür: 8, 3, 2, 9 ve 7, 1, 5, 4. Hâlâ yönetilebilir en küçük parçaya ulaşılmadığı için tekrar bölünür: 8, 3 / 2, 9 / 7, 1 / 5, 4. Sonra tek elemanlara inilir. Bölme sırası aslında derinlik öncelidir: önce 8, 3, 2, 9 bölünür, sonra 8, 3, sonra 8 ve 3; sağ taraf daha sonra işlenir.

En temel duruma ulaşınca birleştirme başlar: 8 ve 3 birleşip 3, 8 olur; 2 ve 9, 2, 9 olur; 7 ve 1, 1, 7 olur; 5 ve 4, 4, 5 olur. Sonra 3, 8 ile 2, 9 birleştirilip 2, 3, 8, 9; 1, 7 ile 4, 5 birleştirilip 1, 4, 5, 7 elde edilir. En sonda bütün dizi 1, 2, 3, 4, 5, 7, 8, 9 olur.

### 8.2 Yukarıdan aşağı (top-down) Merge Sort

Dizi $A[0..n-1]$, $A[0..\frac{n}{2}-1]$ ve $A[\frac{n}{2}..n-1]$ diye iki alt diziye (subarray) bölünür; bunların da alt parçaları olur (ekrandan, 01:55:00).

Tahtadaki kod (ekrandan, 01:55:00):

```c
void MS(int A[], int p, int r) {
    if (p < r) {
        q = (p + r) / 2;
        MS(A, p, q);
        MS(A, q + 1, r);
        merge(A, p, q, r);
    }
}
```

- `p` ilk indisin, `r` son indisin sınırıdır.
- `p < r` ise dizi daha bölünmemiştir; orta nokta `q` hesaplanır.
- `MS(A, p, q)` sol yarıyı, `MS(A, q + 1, r)` sağ yarıyı sıralar.
- `merge(A, p, q, r)`: A dizisinin `p..q` bölgesi ile `q+1..r` bölgesini birleştirir.

Özyinelemeli çağrının temel durumu `p < r` koşulunun sağlanmamasıdır, yani tek elemanlı parçadır.

### 8.3 Birleştirme (merge)

Birleştirmede iki sıralı alt dizi, örneğin 1, 2, 4, 8 ve 3, 5, 7, 9 tek bir sıralı diziye dönüştürülür. İlk parçanın işaretçisi `i`, ikinci parçanın işaretçisi `j`, malloc ile açılan geçici `B` dizisinin işaretçisi `k`'dır. 1 ile 3 karşılaştırılır, küçük olan `B`'ye yazılır ve ilgili işaretçi ilerletilir.

Tahtadaki kod (ekrandan, 01:55:00):

```c
merge(int A, p, q, r) {
    int i, j, k, n, *B;   // B: malloc
    while ((i <= q) && (j <= r)) {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= q) B[k++] = A[i++];
    while (j <= r) B[k++] = A[j++];
    copy(A, B);
}
```

- İlk `while`, iki parçadan biri bitene kadar döner: hangi taraftaki eleman küçükse (eşitse sol taraf) `B`'ye o yazılır.
- Sonraki iki `while`, hangi parça önce bittiyse diğerinin kalan elemanlarını `B`'nin sonuna ekler. Bunlardan yalnız biri çalışır.
- En sonda `B` dizisi `A` dizisine geri kopyalanır.

Tahtadaki kod başlangıç değerlerini ve `copy` işlemini açık yazmaz. Ajan tarafından $i = p$, $j = q + 1$, $k = 0$, $n = r - p + 1$ ile tamamlanan sürüm `gcc -Wall` ile derlenip çalıştırıldı (derste yazılmadı):

```c
#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int p, int q, int r) {
    int i = p, j = q + 1, k = 0, n = r - p + 1;
    int *B = malloc(n * sizeof(int));
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) B[k++] = A[i++];
        else              B[k++] = A[j++];
    }
    while (i <= q) B[k++] = A[i++];
    while (j <= r) B[k++] = A[j++];
    for (k = 0; k < n; k++) A[p + k] = B[k];   /* copy(A, B) */
    free(B);
}

void MS(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MS(A, p, q);
        MS(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main(void) {
    int A[] = {8, 3, 2, 9, 7, 1, 5, 4};
    MS(A, 0, 7);
    for (int i = 0; i < 8; i++) printf("%d ", A[i]);
    printf("\n");
    return 0;
}
```

Çıktı: `1 2 3 4 5 7 8 9`.

### 8.4 Çağrı izi

Hoca kodu aynı dizi üzerinde izledi (ekrandan, 01:50:00). $A = [8, 3, 2, 9, 7, 1, 5, 4]$ için $p = 0$, $r = 7$, $q = \lfloor 7/2 \rfloor = 3$:

- Önce `MS(0,3)` çağrılır; onun altındaki bütün işler bitince `MS(4,7)` çağrılır.
- `MS(0,3)`: $p = 0$, $r = 3$, $q = 1$. İçinden `MS(0,1)` ve `MS(2,3)` çağrılır.
- `MS(0,1)`: $0 < 1$ olduğundan $q = 0$; `MS(0,0)` ve `MS(1,1)` çağrılır. Bunlarda $p < r$ sağlanmaz, hemen dönülür. Sonra 0. ve 1. elemanlar, yani 8 ile 3 birleştirilir: 3, 8.
- Aynısı `MS(2,3)` için yapılır: 2, 9.
- Sonra 3, 8 ile 2, 9 birleştirilir: 2, 3, 8, 9.
- Ardından sağ yarı: $p = q + 1 = 4$, $r = 7$, $q = \lfloor 11/2 \rfloor = 5$. Aynı işlemler tek elemana ulaşana kadar sürer.

## 9. Merge Sort analizi

### 9.1 Yineleme bağıntısı ve Master teoremi

Hoca bağıntıyı koddan kurdu (ekrandan, 02:00:00). Kodda iki özyinelemeli çağrı vardır, her biri $n/2$ boyutludur. Bunların dışında yapılan temel iş birleştirmedir:

$$C(n) = 2C(n/2) + C_{merge}(n), \quad n > 1, \qquad C(1) = 0$$

$n = 1$ için $p = r = 0$'dır; $p < r$ sağlanmaz, hiçbir bölme ve birleştirme yapılmadan çıkılır. Bu yüzden $C(1) = 0$'dır.

$C_{merge}(n)$'i bulmak için en kötü durum düşünülür: birleştirilecek iki dizi 1, 3, 5 ve 2, 4, 6 gibi olsun ve elemanlar sırayla bir o diziden bir bu diziden gelsin. Bu durumda ilk döngüde $n - 1$ karşılaştırma yapılır; iki dizi de neredeyse aynı anda bittiği için kalanlar döngüsünde iş kalmaz:

$$C_{merge}(n) = n - 1$$

Sabitler ihmal edilir ve $f(n) = n = n^d$, yani $d = 1$ alınır:

$$C(n) = 2C(n/2) + n, \qquad a = 2,\ b = 2,\ d = 1$$

$a = b^d$ olduğundan ikinci durum geçerlidir:

$$C(n) = n^d \log n = n \log n \in \Theta(n \log n)$$

### 9.2 Best, worst ve average case

Hoca bu üç durumun nasıl olacağını ayrıca tartıştı (ekrandan, 02:10:00).

**Bölme tarafı:** Dizi en az iki elemanlıysa hiçbir koşula bağlı olmadan bölme yapılır; Merge Sort kendini iki kez çağırır ve bu, parçalar tek elemana inene kadar sürer. $n \to n/2 \to n/4 \to \dots \to n/2^i$ diye gider ve $n/2^i = 1$, yani $i = \log_2 n$ olduğunda bütün parçalar tek elemanlı olur. Bu derinliğe inmek best, worst ve average case'in hepsinde kaçınılmazdır: bölme kısmından $\log n$ seviye gelir.

**Birleştirme tarafı:** Her seviyede birleştirmenin maliyeti incelenir. Hoca üç dizi örneği verdi:

- 1, 2, 3, 4 ile 5, 6, 7, 8: ilk dizinin bütün elemanları daha küçüktür. İlk döngüde $n/2$ eleman aktarılır, kalan $n/2$ eleman da kalanlar döngüsünde aktarılır.

  **Soru:** 8 eleman için kaç kopyalama yapıldı? **Cevap (bir öğrenci):** 8.

- 3, 5, 7, 12 ile karışık değerli bir dizi: elemanlar karışık sırayla iki diziden alınır. Önce bir dizi biter; $n - 1$ eleman ilk döngüde, kalan bir eleman kalanlar döngüsünde kopyalanır. Yine toplam $n$ kopyalama.
- Elemanların sırayla bir diziden bir diğerinden geldiği durum: her şey ilk döngüde biter, kalanlar döngülerine hiç girilmez; yine $n$ atama yapılır.

Selection ve Bubble Sort'ta temel işlem bir karşılaştırma ve onun altındaki takastı (swap); Insertion Sort'ta ilgili yeri bulup elemanı oraya eklemekti. Merge Sort'ta ise temel iş dizinin bir parçasını yeni bir diziye kopyalamaktır ve bu iş her durumda $n$'dir. Toplam:

$$\text{(bölme derinliği) } \log n \times \text{(her seviyedeki iş) } n = \Theta(n \log n)$$

Yani Master teoremine girmeden kod üzerinden yapılan analiz de best, worst ve average case için $\Theta(n\log n)$ verir.

> **Ders sonrası not:** Hoca durumlar arasında hiçbir fark olmadığını söyledi. Bu, kopyalama (atama) sayısı için doğrudur. Karşılaştırma sayısı ise değişir: bir yarının bütün elemanları daha küçükse yalnız $n/2$ karşılaştırma yapılır, en kötü durumda $n - 1$. İki durumda da birleştirme $\Theta(n)$ olduğundan Merge Sort'un karmaşıklığı her durumda $\Theta(n \log n)$'dir.

### 9.3 Geriye doğru yerine koyma ile çözüm

Hoca aynı bağıntıyı backward substitution ile de açtı (ekrandan, 02:05:00 ve 02:15:00):

$$
\begin{aligned}
T(n) &= 2T(n/2) + n \\
&= 2\left[2T(n/4) + n/2\right] + n = 4T(n/4) + 2n \\
&= 8T(n/8) + 3n \\
&\;\;\vdots \\
&= 2^i\,T(n/2^i) + i\,n
\end{aligned}
$$

$n/2^i = 1$, yani $n = 2^i$ ve $i = \log_2 n$ olduğunda:

$$T(n) = 2^{\log_2 n}\, T(1) + n\log_2 n = n\,T(1) + n \log_2 n$$

Bazı kaynaklar $T(1) = 1$ alır; gerekçe, tek elemanlı dizide de `p < r` için bir karşılaştırma yapılmasıdır. O zaman $T(n) = n\log_2 n + n$ olur. $n\log n$, $n$'den daha hızlı büyüdüğü için $n$ terimi ihmal edilir ve sonuç yine $\Theta(n\log n)$'dir. Bu, fonksiyonların büyümesi konusunda görüldüğü gibi Big-O tanımıyla ya da limitle gösterilebilir: $\lim_{n\to\infty} \frac{n\log n}{n} = \lim_{n\to\infty} \log n = \infty$ olduğundan pay her zaman daha büyüktür. $T(1) = 0$ alınırsa ($C(1) = 0$ gibi) $n$ terimi hiç gelmez ve doğrudan $n\log_2 n$ bulunur.

Python ile $n = 2, 4, 8, 16, 32$ için bağıntı doğrudan hesaplandı: $T(1) = 0$ alınınca $n\log_2 n$, $T(1) = 1$ alınınca $n\log_2 n + n$ değerleri birebir çıktı (ör. $n = 8$: 24 ve 32).

### 9.4 Bellek karmaşıklığı

`MS` fonksiyonunun kendisi bellek harcamaz. Ama `merge` içinde $n$ elemanlı dizi için geçici olarak $n$ elemanlı yeni bir dizi açılır, işlem onun üzerinde yapılıp orijinal diziye kopyalanır. `i`, `j` gibi geçici değişkenler $n + 2$, $n + 3$ gibi sabitler ekler ve ihmal edilir (ekrandan, 02:10:00):

$$S(n) \in \Theta(n)$$

### 9.5 Zaman-bellek ödünleşimi

Selection Sort ve Bubble Sort'un karmaşıklığı $n^2$ idi. Merge Sort, bellekten geçici olarak fazladan yer kullanarak (trade-off) süreyi $n\log n$'e indirir. Ek belleğe ihtiyaç duymayan yerinde (in-place) Merge Sort algoritmaları da vardır; ilk derslerde in-place algoritma kavramı konuşulmuştu. Hoca bir sonraki derste "Merge Sort güzel bir iyileştirme yaptı ama fazla bellek kullandı; bunun alternatifi var mı?" sorusundan yola çıkarak Quick Sort'un analiz edileceğini söyledi.

## Örnek Sorular

**1. (derste sözlü, 00:19:37)** $a^n$'i hesaplayan bir algoritma nasıl tasarlanır? Daha hızlı bir yol var mıdır?

> **Çözüm (derste verilen):** Kaba kuvvet: `result = 1`, $i = 1..n$ için `result = result * a` ($n$ çarpma). Daha hızlısı $a^{n/2}$'yi bulup karesini almaktır; özyinelemeli sürüm Bölüm 5.3'tedir.

**2. (derste sözlü, 00:26:22)** İki sayının OBEB'ini kaba kuvvetle bulan bir algoritma yazınız. 6 ile 14 ve 5 ile 12 için uygulayınız.

> **Çözüm (derste verilen):** $x = \min(m,n)$'den 1'e doğru inilir, ikisini de tam bölen ilk değerde durulur. $\gcd(6,14)$: 6, 5, 4, 3 bölmez, 2 böler → 2. $\gcd(5,12)$: 5, 4, 3, 2 bölmez, 1 böler → 1 (aralarında asal).

**3. (derste sözlü, 00:37:35)** Şimdiye kadar görülen sıralama algoritmalarının en kötü durumdaki karmaşıklığı en fazla nedir? Bu problemler hangi zaman sınıfındadır?

> **Çözüm (derste verilen):** $n^2$; sıralama polinom zamanda çözülür. Gezgin satıcı ($\approx (n-1)!$) ve knapsack ($2^n$) gibi problemlerin kapsamlı arama çözümleri ise faktöriyel ya da üsteldir.

**4. (derste sözlü, 01:07:15)** $a^n$'i bir azaltma (decrease by one) yöntemiyle hesaplayan özyinelemeli bağıntıyı yazınız ve $f(2,3)$'ü izleyiniz.

> **Çözüm (derste verilen):** $f(a,0) = 1$; $f(a,n) = f(a,n-1)\cdot a$, $n > 0$. $f(2,3) = f(2,2)\cdot 2 = (f(2,1)\cdot 2)\cdot 2 = ((f(2,0)\cdot 2)\cdot 2)\cdot 2 = 8$.

**5. (ekrandan, 01:20:00)** Öklid algoritmasıyla $\gcd(12,4)$ ve $\gcd(42,4)$'ü bulunuz.

> **Çözüm (derste verilen):** $\gcd(12,4) = \gcd(4,0) \to 4$. $\gcd(42,4) = \gcd(4,2) = \gcd(2,0) \to 2$.

**6. (derste sözlü, 01:22:00)** İkili aramanın en iyi ve en kötü durum karmaşıklığını bulunuz.

> **Çözüm (derste verilen):** $C_{best}(n) \in O(1)$. $C_w(n) = C_w(\lfloor n/2\rfloor) + 1$; $n = 2^k$ için $C_w = k + 1$, yani $C_w(n) = \lfloor\log_2 n\rfloor + 1 \in O(\log n)$.

**7. (ekrandan, 01:35:00)** $A(n) = 2A(n/2) + 1$ bağıntısını Master teoremiyle çözünüz.

> **Çözüm (derste verilen):** $a = 2$, $b = 2$, $d = 0$; $a > b^d = 1$ → $A(n) \in \Theta(n^{\log_2 2}) = \Theta(n)$.

**8. (derste sözlü, 02:01:04)** 1, 2, 3, 4 ve 5, 6, 7, 8 dizileri birleştirilirken kaç kopyalama işlemi yapılır?

> **Çözüm (derste verilen):** 8 (genel olarak $n$). İlk döngüde 4, kalanlar döngüsünde 4 eleman geçici diziye kopyalanır.

**9. (ekrandan, 02:00:00)** Merge Sort için $C(n) = 2C(n/2) + C_{merge}(n)$, $C(1) = 0$ bağıntısını çözünüz; bellek karmaşıklığını bulunuz.

> **Çözüm (derste verilen):** En kötü durumda $C_{merge}(n) = n - 1 \approx n$, $d = 1$; $a = 2 = b^d$ → $C(n) \in \Theta(n\log n)$. Backward substitution ile $T(n) = 2^iT(n/2^i) + in$, $i = \log_2 n$ → $n\,T(1) + n\log_2 n \in \Theta(n\log n)$. Bellek: geçici dizi nedeniyle $S(n) \in \Theta(n)$.

**10. (ekrandan, 02:20:00)** Ödev sorusu (Merge Sort algoritmalarının karşılaştırılması):

1. Aşağıdaki algoritmaları C dilinde, tek bir C dosyası içinde, her algoritma için ilgili ve gerekli fonksiyonlarla kodlayınız (yalnız `main` fonksiyonu içine yazılmış kod kabul edilmez).
2. Bu algoritmaların bellek ve zaman karmaşıklığını asimptotik notasyonlarla elde edip açıklayınız. En iyi ve en kötü durum senaryolarını ayrı ayrı değerlendiriniz.
   - A. Mergesort (recursive)
   - B. in-place mergesort
   - C. İteratif mergesort
3. Kodladığınız algoritmaları $N = 10^3, 10^4, 10^5, 10^6, 10^7, 10^8$ ve $10^9$ elemanlı rastgele ve tersten sıralı diziler için kaba analiz (çalışma süresi ölçümü) ile deneyip sonuçları bir tabloda gösteriniz ve yorumlayınız.
4. Madde 3'te elde edilen kaba analiz sonuçlarının asimptotik analizle uyumlu olup olmadığını yorumlayınız.

> **Çözüm (derste verilmedi):** Kuramsal kısım için kısa bir çerçeve: (A) Özyinelemeli Merge Sort her durumda $\Theta(n\log n)$ zaman, geçici dizi için $\Theta(n)$ ek bellek ve $\Theta(\log n)$ özyineleme yığını kullanır (Bölüm 9). (C) İteratif (aşağıdan yukarı) Merge Sort, genişliği 1, 2, 4, … olan parçaları birleştirerek $\lceil\log_2 n\rceil$ geçişte çalışır; zaman yine her durumda $\Theta(n\log n)$, ek bellek $\Theta(n)$'dir, özyineleme yığını yoktur. (B) Yerinde Merge Sort'un karmaşıklığı uygulamaya bağlıdır: büyük olasılıkla en yaygın basit sürüm, birleştirmede elemanları kaydırarak yer açar; bu sürümde birleştirme en kötü durumda $\Theta(n^2)$, toplam en kötü durum $O(n^2)$ olur, ek bellek ise $O(1)$'dir (yığın hariç). Bu basit sürümde iki yarı zaten sıralıysa birleştirmede kaydırma yapılmaz ve en iyi durum $\Theta(n\log n)$ olur; tersten sıralı dizide ise her birleştirmede çok sayıda kaydırma gerektiği için yavaşlar. Ölçüm kısmı (madde 3-4) deneyseldir ve sonuçlar makineye göre değişir.

## Dersin Toparlaması

Ders, önceki haftalarda görülen asimptotik analiz araçlarının kısa bir tekrarıyla başladı: bir problemi çözme adımları, best/average/worst case ve zaman ile bellek verimliliği. Ardından algoritma tasarımına geçildi. Kaba kuvvet, problemin tanımından doğrudan çıkan düz yaklaşım olarak tanımlandı; $a^n$, OBEB, basit sıralamalar, doğrusal arama, string matching, polinom değerlendirme ve en yakın çift bu tekniğin örnekleriydi. Kaba kuvvetin bir alt kümesi olan kapsamlı arama ise gezgin satıcı, knapsack ve iş atama gibi kombinatoryal problemlerde faktöriyel ya da üstel maliyete yol açtı. Azalt ve fethet ile problem bir azaltma ($a^n = a^{n-1}a$), sabit çarpanla azaltma ($a^n = (a^{n/2})^2$, ikili arama) ve değişken boyutlu azaltma (Öklid) yoluyla küçültüldü.

Böl ve fethette problem eşit parçalara bölünüp her parçaya aynı algoritma uygulandı ve çözümler birleştirildi. Master teoremi hatırlatıldı ve Merge Sort bu çerçevede incelendi: $C(n) = 2C(n/2) + (n-1)$ bağıntısı hem Master teoremiyle hem geriye doğru yerine koymayla $\Theta(n\log n)$ verdi ve bu sonuç her durumda geçerli. Bunun karşılığında $\Theta(n)$ ek bellek harcanıyor. Bir sonraki derste, bu bellek maliyeti olmadan benzer hız sağlayan bir alternatif olarak Quick Sort analiz edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
