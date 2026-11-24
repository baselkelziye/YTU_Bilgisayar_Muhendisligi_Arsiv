# Ders 4 Genişletilmiş Notu: Sezgisel Arama: İlk En İyi Arama ve A* Algoritması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersin özeti: Arama problemi ve kör arama
- 2. İki yönlü arama
- 3. Kör arama algoritmalarının ortak yapısı ve tekrarlayan durumlar
- 4. my_search.m: Algoritmaların bir harita üzerinde karşılaştırılması
- 5. Sezgisel aramaya geçiş
- 6. İlk en iyi arama (Best First Search)
- 7. A* algoritması
- 8. Labirent örneği: İlk en iyi arama ve A*
- 9. 8 taş problemi için sezgisel kurallar ve baskınlık
- 10. Bir graf üzerinde algoritmaların karşılaştırılması ve A* tablo gösterimi
- 11. A*'ın optimalliğinin ispatı
- 12. Uygulama: Çok robotlu keşif
- Örnek Sorular

## 1. Önceki dersin özeti: Arama problemi ve kör arama

Ders, önceki haftanın kısa bir özetiyle başlar. Arama, bir problemin çözümünü arama süreci olarak ele alınmıştı. Görünüşte birbirinden çok farklı problemler (bir planlama problemi, bir robotu bir noktadan başka bir noktaya götürmek, nesneleri karşıya geçirmek gibi) aynı yapı içinde yazılabilir. Her problem bu yapıya indirgenemez, ama birçoğu indirgenebilir.

Bu ortak yapının parçaları şunlardır:

- **Durumlar:** Problemin her anını ifade eden gösterim. Örneğin karşıya geçirme probleminde bir durum, her nesnenin kuzeyde mi güneyde mi olduğuyla ifade edilir.
- **Operatörler:** Durumlar arasındaki geçişler; hangi durumdan hangi duruma nasıl geçildiği.
- **Kısıtlar:** Her operatör her duruma uygulanamaz. Örneğin bir ızgaranın sol üst köşesinde "yukarı git" ve "sola git" uygulanamaz, yalnız "sağa git" ve "aşağı git" uygulanabilir. Bazı durumlara ise hiç girilmemesi gerekir (yasaklı durumlar).
- **Çözüm:** Başlangıçtan hedefe götüren bir operatörler dizisi.

8'li puzzle da bu yapıya uyar; operatör, boş kareyi yukarı, aşağı, sağa ya da sola kaydırmaktır. Arama uzayları o kadar büyüktür ki bilgisayarlar ne kadar hızlanırsa hızlansın tamamen taranamazlar.

Algoritmalar şu ölçütlerle karşılaştırılır (ekrandan, 00:05:00):

- **Tamlık (completeness):** Bir çözüm varsa mutlaka bulması.
- **Zaman karmaşıklığı:** Aramanın alacağı süre.
- **Hafıza karmaşıklığı:** Arama için gereken hafıza miktarı.
- **Optimumluk:** İlk bulunan çözümün en düşük maliyetli çözüm olması.

Bu ölçümlerde $b$ en büyük dallanma sayısı (bir düğümden çıkan en fazla düğüm sayısı), $d$ en az maliyetli çözümün derinliği, $m$ arama uzayının en büyük derinliğidir (bazen $\infty$).

Önceki derste görülen kör arama algoritmaları kısaca şöyle özetlenir:

- **Enlemesine arama (BFS):** Bir liste üzerinde çalışır, ama çekilen elemanların sırası bir ağaçta seviye seviye ilerlemeye karşılık gelir. Tamdır; her adımın maliyeti eşitse optimaldir; zaman ve hafıza açısından $b^d$ mertebesinde olduğu için iyi değildir.
- **Düşük maliyetli arama (UCS):** BFS'den farkı, tüm maliyetler pozitif olduğu sürece optimal olmasıdır; maliyetlerin birbirine eşit olması gerekmez. Maliyetlerden biri negatif olsaydı algoritma toplam maliyeti düşürmek için o kenarda sürekli dönen bir loop'a girerdi; bu yüzden pozitif maliyet şartı doğal bir şarttır.
- **Derinlemesine arama (DFS):** Tam değil, optimal değil; en önemli iyi özelliği $b \cdot m$ mertebesindeki hafıza gereksinimidir.
- **Sınırlı derinlikte ve artan derinlikte arama (IDS):** Artan derinlikte arama biraz fazladan zaman harcayarak BFS ile aynı anlamda optimumluk sağlar (maliyetler eşitse) ve hafızası doğrusal kalır.

## 2. İki yönlü arama

Fikir şudur: Bir noktadan diğerine gitmek istiyoruz. Aramayı aynı anda hem başlangıçtan hem de hedeften başlatırsak ve iki arama ortada bir yerde buluşursa, toplam yol uzunluğu $d$ ise her iki tarafın yalnızca $d/2$ derinliğe inmesi yeterlidir (ekrandan, 00:10:00). İleri ve geri aramaların her biri yarım yol gider ve enlemesine arama yapılır.

Kazancın büyüklüğü slayttaki örnekle görülür:

- Verilen: $b=10$, $d=6$.
- Tek yönlü enlemesine arama: $1 + 10 + 100 + \dots + 10^6 = 1.111.111$ düğüm.
- İki yönlü arama: Her yön 3 derinliğe iner, her biri $1+10+100+1000 = 1.111$ düğüm üretir; toplam $2.222$ düğüm.

Üstteki $d$'yi yarıya indirmek çok büyük kazanç sağlar (python ile doğrulandı). Slayttaki analiz:

- Tam mı? Evet.
- Zaman: $O(b^{d/2})$.
- Hafıza: $O(b^{d/2})$.
- Optimal mi? Tüm maliyetler eşitse evet.

Kullanılabilmesinin şartı, operatörlerin her iki yönde de tanımlı olmasıdır. Bazı problemlerde durumlar arası geçişler tek yönlüdür: başlangıçtan hedefe doğru operatörler tanımlıdır, ama hedeften geriye doğru tanımlı olmayabilir. Hem başlangıçtan hedefe hem de hedeften başlangıca giden yolu bulabilecek operatörler elimizdeyse bu algoritma rahatlıkla kullanılabilir. Hafıza gereksinimi azalsa da hâlâ üsteldir; derinlemesine aramadaki gibi $b \cdot d$ değil, $b^{d/2}$'dir.

## 3. Kör arama algoritmalarının ortak yapısı ve tekrarlayan durumlar

### 3.1 Algoritmalar arasındaki tek fark

Kör arama algoritmaları birbirine çok benzer. Hocanın sorusuna bir öğrencinin verdiği cevapla netleşir: Enlemesine ve derinlemesine arama arasındaki tek fark, yeni durumların listenin neresine eklendiğidir.

- Yeni durumlar listenin **sonuna** eklenirse enlemesine arama,
- **başına** eklenirse derinlemesine arama elde edilir (her seferinde listenin başından çekildiği varsayılır).

Düşük maliyetli aramada ise kuyruktan sabit bir uçtan çekilmez. Kuyruktaki her durumun kökten oraya gelme maliyetine bakılır ve en az maliyetli olan çekilir. Bu ona optimallik kazandırır. Uygulamada bu seçimi her adımda standart bir sıralamayla yapmak karmaşıklık açısından sorun çıkarabilir; daha verimli veri yapıları gerekebilir.

### 3.2 Tekrarlayan durumlar

Derinlemesine aramanın nasıl sonsuza gidebildiği şu örnekle gösterilir (ekrandan, 00:15:00). Yollar:

- A → D
- D → E
- E → A, F

A'dan başlayıp derinlemesine arama yapılır, hedef F'dir. Gösterimde parantez içi o ana kadar izlenen yolu, baştaki harf yolun son durumunu gösterir. Liste her adımda şöyle değişir:

```text
A
D(AD)
E(ADE)
A(ADEA)  F(ADEF)
D(ADEAD)  F(ADEF)
E(ADEADE)  F(ADEF)
A(ADEADEA)  F(ADEADEF)  F(ADEF)
D(ADEADEAD)  F(ADEADEF)  F(ADEF)
...
```

E'den hem A'ya hem F'ye gidilebilir; ikisi de eklenir. Her seferinde listenin başındaki çekildiği ve A'nın yeni durumları başa eklendiği için F hiçbir zaman çekilemez; arama sonsuza gider.

Çözüm: Yeni durumları eklemeden önce kontrol etmek, durum zaten varsa eklememek. ADE yolundayken E'den A ve F'ye gidilebilir. A bu yolun içinde zaten vardır, oradan geçilmiştir; tekrar eklemenin anlamı yoktur. F ise yolda yoktur ve eklenir (ADEF). Böylece çözüm bulunur.

### 3.3 Karşılaştırma

- **DFS:** Hafıza gereksinimi doğrusaldır; ama loop'lu ve sonsuz uzaylarda sonsuza kadar çalışabilir ve optimum çözümü garanti etmez.
- **BFS:** Optimumluk ve tamlık iyi tarafıdır; hafıza gereksinimi derinlikle üstel büyür.
- **IDS:** İkisinin güzel taraflarını birleştirir. Eksik tarafı zaman kaybıdır: Aynı düğümleri tekrar tekrar açar; bir düğüm ağaçta ne kadar yukarıdaysa o kadar çok tekrar açılır.

## 4. my_search.m: Algoritmaların bir harita üzerinde karşılaştırılması

Ders sayfasında paylaşılan bir kod, rastgele şehirler ve aralarında yollar içeren haritalar üretir ve bu haritada farklı algoritmaları çalıştırır (ekrandan, 00:20:00). Haritada örneğin 16 numaralı şehirle 5 numaralı şehir arasında 54 km'lik yol vardır. Amaç 12 numaralı şehirden 1 numaralı şehre gitmektir.

Bulunan yollar (ekrandan, 00:20:00):

| Algoritma | Yol | Maliyet | Çekilen eleman (adım) |
|---|---|---|---|
| Derinlemesine (DFS) | 12 11 9 15 18 17 13 10 7 14 8 5 1 | 314 | 24 |
| Enlemesine (BFS) | 12 4 2 5 1 | 128 | 37 |
| Düşük maliyetli (UCS) | 12 9 15 7 1 | 110 | 79 |
| İlk en iyi arama | 12 9 15 18 1 | 110 | 5 |
| A* | 12 9 15 7 1 | 110 | 6 |

### 4.1 Hangi yolun optimal olduğundan emin olabiliriz?

BFS 128 uzunluğunda bir yol bulmuştur. Bundan daha kısa bir yol olmadığı söylenemez, çünkü maliyetler eşit değildir. Enlemesine arama en az **adım** içeren çözümü bulur, en düşük **maliyetli** çözümü değil.

UCS'nin bulduğu yol için ise çok güçlü bir güvence vardır: Bulduğu yoldan daha kısa bir yol olamaz. Algoritmanın optimal olmasının önemi buradadır: Size bir çözüm geldiğinde "acaba daha iyisi var mı" diye düşünmenize gerek kalmaz. Birden fazla optimal çözüm olabilir; bu, aynı en düşük maliyete sahip iki ayrı yol olması demektir.

İlk en iyi arama ve A* da bu örnekte 110'luk optimum çözümü bulmuştur. Ama bir örnekte optimumu bulmak algoritmanın optimal olduğunu göstermez. BFS de bazı haritalarda şans eseri optimumu bulabilir; bu onun optimal olduğunu değil, şanslı olduğunu gösterir.

### 4.2 Kuyruk boyutu grafiği

Sağdaki grafikte x ekseni adım numarası, y ekseni o adımdaki kuyruk (liste) boyutudur.

- UCS 79 adım sürmüş ve kuyruğu 250'nin üzerine çıkmıştır; hafıza gereksinimi en fazla olandır.
- BFS 37 adım sürmüş, kuyruğu 100 civarına ulaşmıştır.
- DFS'nin kuyruğu önce biraz yükselir, sonra 25 civarında düzgün ve yavaş biçimde devam eder. Derinlemesine aramanın hafıza gereksiniminin düşük olduğu burada görülür.
- İlk en iyi arama ve A* çok az adımda çözüme ulaştığı için hafıza sorunu oluşmamıştır. Ama bunlar da uzun süren bir problemde çalışırsa hafızaları çok artar.

### 4.3 DFS'nin izlediği yol

DFS 12'den 11'e, oradan 9'a, 15'e, 18'e kadar hedefe doğru iyi gelir; sonra 17'ye, 13'e, 10'a, 7'ye gider ve birden 14'e sapar. Bu yola bakınca algoritmanın neyi hiç dikkate almadığı görülür: **Hedefin yakınlarında mıyım?** Kör algoritmaların hedefe yakınlığa dair bir bilgisi yoktur; hedefe yaklaşıp uzaklaşırlar.

## 5. Sezgisel aramaya geçiş

Herhangi bir durumun hedefe kaç adım ya da kaç kilometre uzakta olduğunu kesin olarak bilemeyiz. Bunu bilmek için o durumdan hedefe giden yolu bilmek gerekir; bunu bilseydik çözüm zaten elimizde olurdu.

Böyle bir bilgi olsa işimize yarardı: Çözüme ne kadar yakın olduğumuza göre hareket etmek mantıklıdır. O zaman şu soru sorulur: Hedefe yakınlığı tam olarak bilmesek de yaklaşık olarak tahmin etsek, bu işimize yarar mı?

Kör algoritmaların en akılcısı (düşük maliyetli arama) bile yalnızca kökten itibaren ne kadar yol gidildiğine bakar; ne kadar daha yol gidileceğine hiç bakmaz. Sezgisel (heuristic) arama algoritmaları ise hedefe ne kadar yol kaldığının bir tahminini kullanır ve kalan yolu az olanı tercih eder. Sezgi kullanmak, tahmin kullanmak demektir.

my_search.m sonuçlarında kazanç açıktır: Kör algoritmalar 24-79 adım sürerken ilk en iyi arama 5, A* 6 adımda çözüme ulaşmıştır. Sezgisel algoritmalar zamandan çok büyük kazanç sağlayabilir.

Bu derste iki sezgisel arama algoritması görülür: İlk en iyi arama ve A*. Yerel arama algoritmaları farklı türden olduğu için ayrıca işlenecektir.

## 6. İlk en iyi arama (Best First Search)

### 6.1 Algoritma ve değerlendirme fonksiyonu

Algoritma diğer arama algoritmalarıyla aynıdır; tek fark kuyruktan çekerken yapılır: Kuyruktaki durumlara bir **değerlendirme fonksiyonuna** göre puan verilir ve en düşük puanlı (hedefe uzaklığı en az görünen) durum çekilir.

Değerlendirme fonksiyonu (ekrandan, 00:50:00):

$$f(n) = h(n)$$

Burada $h(n)$ (heuristic), mevcut durum $n$'nin hedefe **tahmini** uzaklığıdır. Tahmini uzaklığın nasıl hesaplanacağı problemden probleme değişir. Şehirler arası en kısa yol probleminde en basit tahmin kuş uçuşu mesafedir: $h_{SLD}(n)$, mevcut durumun hedefe kuş uçuşu mesafesi (SLD: Shortest Line Distance).

Algoritma her adımda hedefe en yakın **gözüken** duruma ilerler. Hedefe gerçekten en yakın duruma ilerleyemez, çünkü bunun için çözümü bilmesi gerekir.

### 6.2 Kuş uçuşu mesafe iyimser midir?

Hocanın sorusu: Kuş uçuşu mesafe iyimser bir tahmin midir, kötümser mi? Cevap: İyimserdir. Gerçek yol mesafesi kuş uçuşu mesafeden kısa olamaz; kuş uçuşu mesafe gerçek maliyeti her zaman olduğundan az (ya da eşit) tahmin eder.

### 6.3 Romanya haritası örneği

Amaç Arad şehrinden Bükreş'e (Bucharest) gitmektir. İki bilgi vardır: Hangi şehirden hangi şehre kaç kilometrelik yol olduğu (gerçek bilgi) ve her şehrin Bükreş'e kuş uçuşu mesafesi (Bükreş'in kendisi için 0, Arad için 366). Kör algoritmalar yalnızca ilk bilgiyi kullanarak da çözüm, hatta optimum çözüm bulabilir. Sezgisel algoritmalarla azaltılmaya çalışılan şey yolun uzunluğu değil, çözümü bulmanın aldığı süredir.

> **Hocanın vurgusu:** Sezgisel algoritmaların amacı daha iyi bir yol bulmak değil, çözümü daha hızlı bulmaktır. Düşük maliyetli arama optimal yolu kesinlikle bulur; sezgisel algoritmaların farkı daha hızlı bulmalarıdır.

Kör algoritmalar yalnız yol uzunluklarını, ilk en iyi arama yalnız kuş uçuşu mesafeleri, A* ise ikisini birden kullanır.

İlk en iyi aramanın adımları (ekrandan, 00:55:00); her şehrin altındaki sayı $h$ değeridir:

1. Kuyrukta Arad (366) vardır; çekilir.
2. Arad'dan gidilebilecek üç şehir eklenir: Sibiu (253), Timisoara (329), Zerind (374). En küçük $h$ Sibiu'nundur; Sibiu çekilir.
3. Sibiu'dan Arad (366), Fagaras (176), Oradea (380), Rimnicu Vilcea (193) eklenir. Kuyrukta altı eleman vardır. Kuş uçuşu mesafeye göre en yakın görünen Fagaras'tır; Fagaras çekilir.
4. Fagaras'tan Sibiu (253) ve Bükreş (0) eklenir. Kuyrukta yedi eleman vardır. Bükreş'in Bükreş'e uzaklığı 0 olduğu için Bükreş çekilir. Bükreş hedeftir; arama biter.

Bulunan yol: Arad → Sibiu → Fagaras → Bükreş. Bu yoldan daha kısa bir çözüm vardır (sonraki bölümde A*'ın bulduğu yol); bu yüzden ilk en iyi arama optimal bir algoritma değildir. Bir algoritmanın optimal olmadığını göstermek için daha iyi bir çözümün var olduğunu göstermek yeter.

### 6.4 Analiz

- **Tam mı?** Hayır; looplara takılabilir. Çeşitli durumlar kurarak görülebilir.
- **Zaman:** $O(b^m)$; ancak iyi sezgisel kurallar büyük iyileşme sağlar.
- **Hafıza:** $O(b^m)$; tüm durumlar hafızadadır.
- **Optimal mi?** Hayır.

Güzel tarafı hızıdır. Az zamanda çözüme erişirse, zamandan kazandığı ölçüde hafızadan da kazanır.

**Soru:** Kuş uçuşu mesafeleri de düğümlere eklemek gerekiyor; bu hafıza ihtiyacını artırmıyor mu? **Cevap:** Düğüm başına tutulan bilgi biraz artar (örneğin 100 birimlik bilgi 110 olabilir). Ama düşük maliyetli aramada da düğümlerde maliyet bilgisi tutulur; hızlı çalışmak isteyen her algoritma bu tür bilgileri bir yerde tutmak zorundadır. Dolayısıyla önemli bir fazladan maliyet yoktur.

## 7. A* algoritması

### 7.1 Fikir ve değerlendirme fonksiyonu

A*'ın fikri, kökten itibaren toplam maliyeti yüksek durumlara gidişi engellemektir. İlk en iyi arama yalnızca $h(n)$'ye odaklanır: $f(n) = h(n)$. A* ise şunu kullanır:

$$f(n) = g(n) + h(n)$$

- $g(n)$: Kökten mevcut duruma gelişin maliyeti. Bu **tam bilinen** bir maliyettir; tahmin yoktur. Örneğin Arad → Sibiu → Fagaras yolu arama sırasında zaten geçilmiş yollardır, maliyetleri kesin olarak bilinir.
- $h(n)$: Mevcut durumdan hedefe **tahmini** maliyet (kaç adım, kaç kilometre).
- $f(n)$: Kökten, $n$'den geçerek hedefe gidişin tahmini maliyeti.

Böylece A*, sürekli hedefe en yakın görünen duruma atlayıp durmaz.

### 7.2 Romanya haritası örneği

Bu örnekte durumların altında $f = g + h$ yazılır (ekrandan, 01:00:00). Arad için $366 = 0 + 366$: Arad'dan başlandığı için $g=0$.

Adımlar şöyle ilerler:

1. Arad ($f=366$) açılır.
2. Sibiu ($f=393$) seçilir ve açılır; Sibiu'dan gidilebilecek dört şehir eklenir, kuyrukta altı durum olur.
3. Altı durum içinden $f$'si en küçük olan Rimnicu Vilcea seçilir; ondan gidilebilecek üç şehir eklenir, kuyrukta sekiz durum olur.
4. Fagaras seçilir; Sibiu ve Bükreş eklenir. Bu anda kuyrukta Fagaras üzerinden giden bir Bükreş vardır ($f=450$), yani başlangıçtan Bükreş'e giden bir yol elimizdedir. Ama A* onu seçmez.
5. Pitesti seçilir ($f$'si 450'den küçüktür); Pitesti'den gidilebilecek üç şehir eklenir, kuyrukta 11 durum olur.
6. 11 durum içinden, Arad → Sibiu → Rimnicu Vilcea → Pitesti → Bükreş yolunun sonundaki Bükreş seçilir; hedef olduğu için arama biter.

<!-- BELİRSİZ: Bu örneğin ara değerlerini gösteren slayt karesi yok; altyazıda yalnız 393 ("3993" diye yazılmış) ve 450 geçiyor. Aşağıdaki değerler kitaptaki standart Romanya haritasının yol uzunlukları ve kuş uçuşu mesafeleriyle python ile hesaplandı. -->

Ara adım değerleri (python ile hesaplandı): Sibiu $393 = 140 + 253$, Rimnicu Vilcea $413 = 220 + 193$, Fagaras $415 = 239 + 176$, Pitesti $417 = 317 + 100$, Fagaras üzerinden Bükreş $450 = 450 + 0$, Pitesti üzerinden Bükreş $418 = 418 + 0$.

Burada iki ayrı "Bükreş" durumu vardır: biri Arad–Sibiu–Fagaras–Bükreş, diğeri Arad–Sibiu–Rimnicu Vilcea–Pitesti–Bükreş yoludur. A*'ın ikinciyi seçmesinin sebebi onun Bükreş olması değil, $f$ değerinin kuyruktaki tüm durumlardan küçük olmasıdır.

İlk en iyi arama olsaydı, yalnız $h$'ye baktığı ve hedefin $h$ değeri her zaman 0 olduğu için, kuyruğa hedefe giden bir yol düştüğü anda onu seçerdi. A* ise $f = g + h$'ye bakar ve daha pahalı yolu seçmez.

## 8. Labirent örneği: İlk en iyi arama ve A*

### 8.1 Problem ve sezgisel fonksiyon

Bir labirentte taralı hücrelerden geçilemez. S'den başlanıp G'ye gidilecektir; operatörler sağa, sola, yukarı ve aşağı gitmektir (ekrandan, 01:05:00).

Sezgisel arama için her durumun hedefe uzaklığını tahmin eden bir fonksiyon gerekir. Şehirlerde kuş uçuşu mesafe kullanılmıştı. Burada, ortamda hiç engel yokmuş gibi en az kaç adımda gidileceği kullanılır: satır farkı + sütun farkı, yani **Manhattan uzaklığı**. G'nin hemen yanındaki hücrenin değeri 1, bir sonrakinin 2'dir; engel yokmuş gibi dört adımda gidilebilen bir hücrenin değeri 4'tür.

Slayttaki dört parça:

- (a) Ortam: S'den başla, G'ye git.
- (b) Tüm durumların hedefe Manhattan uzaklıkları ($h$).
- (c) İlk en iyi arama ile bulunan yol; yalnız $h$ değerleri kullanılır.
- (d) A* ile bulunan yol; durumlardaki etiketler $h+g$ biçimindedir.

Yuvarlak içine alınmış hücreler kuyruktan çekilmiş (açılmış) durumlardır.

### 8.2 İlk en iyi aramanın izlediği yol

S'deyken üç hamle yapılabilir; ikisinin $h$ değeri 6, birinin 8'dir. 6'lardan biri seçilir. Hoca kuyruğu adım adım şöyle tutar: Kuyrukta 6, 6, 8 vardır; bir 6 seçilince yerine 7 gelir; sonra diğer 6 açılır ve 7 eklenir; 7'ler açıldıkça 8'ler eklenir, sonra değeri 6'dan başlayıp 5, 4, 3, 2'ye inen hücreler gelir. Kuyruktaki 8'lerden küçük değerler hep bulunduğu için algoritma sürekli bu taraftan ilerler: 5, 4, 3, 2, ... Sonunda 1'e, oradan G'ye ulaşır ve uzun, dolambaçlı bir yol bulur.

**Soru:** Bu örnekte ilk en iyi aramanın kötü tarafı nedir? **Cevap:** O noktaya kadar gelmenin maliyetini hesaba katmaz. Bu yüzden daha kısa bir yol varken çok uzun yollar bulabilir.

### 8.3 A*'ın izlediği yol

A* aynı problemde önce yine o taraftan seçmeye başlar. Ama ilerledikçe $g$ değerleri belirgin biçimde artar ($h$'de çok büyük artış olmasa bile). Belli bir noktadan sonra o taraftaki toplam maliyet diğer seçeneğinkini geçer ve A* öbür taraftan devam ederek en kısa yolu bulur.

A*'ın yol değiştirmesi bir kez olmak zorunda değildir. Labirent farklı olsaydı (örneğin öbür yol da yukarı doğru uzasaydı), o yol da bir yere kadar gidildikten sonra tekrar ilk tarafa dönülebilirdi. Slaytta arama sırası değil, yalnız açılmış ve açılmamış düğümler görülür.

### 8.4 A*'ın analizi

- **Tam mı?** Evet. Ayrıca looplara takılmaz.
- **Zaman ve hafıza:** İlk en iyi aramadan çok farklı değildir; ama iyi sezgisel kurallar büyük iyileşme sağlayabilir.
- **Optimal mi?** Evet, bir şartla: $h(n)$ iyimser olmalıdır.

Loop'a takılmama konusunda: DFS ve ilk en iyi arama looplara takılabilir, BFS ve UCS takılmaz. A* bunu ek bir kontrol olmadan sağlar. İlk en iyi aramadan farklı olarak işin içine o ana kadarki toplam maliyeti, $g$'yi katar. Bir loop oluşursa $g$ artar ve o yol seçilmez. DFS'deki gibi "bu durum yolda var mı" kontrolüne gerek kalmaz.

**İyimser sezgi:** $h(n)$ tüm durumlarda gerçek maliyetten daha düşük bir değer tahmin ediyorsa $h$ iyimserdir. Kullanılan $h$ iyimserse A* optimal çözümü verir.

## 9. 8 taş problemi için sezgisel kurallar ve baskınlık

### 9.1 İki sezgisel kural

Şehirlerde kuş uçuşu mesafe, labirentte Manhattan uzaklığı kullanıldı. 8 taş probleminde kuş uçuşu mesafe gibi doğrudan bir şey yoktur; başlangıç durumundan hedef duruma kaç adımda gidileceği tahmin edilmelidir. Slayttaki iki sezgisel fonksiyon (ekrandan, 01:15:00):

- $h_1(n)$: Yerinde olmayan taşların sayısı.
- $h_2(n)$: Taşların hedefteki yerlerine uzaklıkları toplamı (yatay ve dikey hane toplamları, Manhattan uzaklığı).

Örnek (ekrandan, 01:15:00):

```text
Başlangıç (Start State)     Hedef (Goal State)
7 2 4                        _ 1 2
5 _ 6                        3 4 5
8 3 1                        6 7 8
```

- $h_1(S) = 8$: Hiçbir taş yerinde değildir.
- $h_2(S) = 3+1+2+2+2+3+3+2 = 18$: Sırasıyla 1'den 8'e kadar taşların uzaklıkları. Örneğin 7 sol üstten hedefteki yerine (alt orta) en iyi ihtimalle 3 adımda, 2 yanındaki hedef yerine 1 adımda, 4 ise 2 adımda gidebilir.

Değerler python ile doğrulandı.

### 9.2 İkisi de iyimser midir?

Hoca öğrencilere sorar. Cevap: İkisi de iyimserdir.

- $h_2$ iyimserdir: Bu durumdan hedefe, her hamlede tek taş oynatarak 18 adımda gidilebilir mi? Gidilemez. $h_2$'deki 3, 7'nin yerine üç adımda gidebileceğini söyler; ama gerçekte araya başka taşlar girdiği için üç hamlede gidemez, belki on hamle gerekir. $h_2$ aradaki taşlar yokmuş gibi hesap yapar.
- $h_1$ de iyimserdir: Her taşı olması gereken yere tek adımda götürebileceğini varsayar ve $h_2$'den de küçüktür. $h_2$ iyimserse $h_1$ haydi haydi iyimserdir.

**Soru:** İyimser, yakın olması mı demek? **Cevap:** İyimser, gerçek maliyetten daha düşük maliyet tahmin etmesi demektir. Gündelik anlamdaki gibi: İşlerin gerçekte olacağından daha az zahmetli olacağını tahmin etmek.

### 9.3 $h_1$ ile $h_2$ arasındaki ilişki

$h_2 \ge h_1$'dir. $h_2$'de her yerinde olmayan taş en az 1 katkı yapar; $h_1$ ise bu taşların sayısıdır. Bütün uzaklıklar 1 olsaydı ikisi eşit olurdu; en yakın hâlleri eşitliktir.

### 9.4 Baskınlık (dominance)

Slayttaki tanım (ekrandan, 01:25:00):

- Geçerli (iyimser) iki sezgisel kural için tüm durumlarda $h_2(n) \ge h_1(n)$ ise,
- $h_2$, $h_1$'e baskındır (dominates),
- $h_2$ arama için daha uygundur.

**Soru:** $h_2$'nin arama için daha uygun olması, $h_2$ kullanılırsa daha iyi çözüm bulunacağı anlamına mı gelir? **Cevap:** Hayır. Çözüme daha kısa sürede ulaşılır. $h_1$ ile ve $h_2$ ile bulunan çözümler maliyet açısından aynıdır; düşük maliyetli aramanın bulduğu çözümle de aynıdır.

8 taş için ortalama açılan durum sayıları (ekrandan, 01:25:00):

| Derinlik | IDS | A*($h_1$) | A*($h_2$) |
|---|---|---|---|
| $d=12$ | 3.644.035 | 227 | 73 |
| $d=24$ | çok büyük | 39.135 | 1.641 |

12 derinlik zor bir problem değildir. Tüm operatörlerin maliyeti eşit olduğu için IDS burada optimaldir, ama optimal çözümü bulana kadar kuyruktan 3,6 milyon eleman çekmiştir. 24 derinlikte IDS ile arama pratik olarak mümkün olmaz; anlamlı bir süre içinde çözüm bulunamaz. A* ile $h_1$ ve $h_2$ arasındaki fark bulunan yolda değil, çözüme kadarki bekleme süresindedir.

> **Hocanın vurgusu:** "İyi sezgisel kurallar büyük iyileşmeler sağlayabilir" ifadesinin somut karşılığı bu tablodur.

### 9.5 Siyah ve beyaz pullar problemi

Yedi hücrelik bir dizide ilk üç hücrede siyah, sonraki üç hücrede beyaz pullar vardır (bir hücre boştur). Hedef, tüm beyaz pulların tüm siyah pulların soluna geçmesidir. İki operatör vardır: Bir taş yanındaki boş yere gidebilir (maliyet 1); bir taş taşların üzerinden atlayarak boş yere gidebilir (maliyet 2). <!-- BELİRSİZ: Atlama operatörünün tam tanımı (bir ya da iki taşın üzerinden mi, maliyet atlanan taş sayısı mı) altyazıdan net çıkmıyor; slayt karesi yok. --> Bu problem için bir $h$ önerisi derste öğrencilere bırakılmıştır (bkz. Örnek Sorular).

## 10. Bir graf üzerinde algoritmaların karşılaştırılması ve A* tablo gösterimi

### 10.1 Graf

Şekil 1'de şehirler ve aralarındaki gerçek mesafeler, Şekil 2'de her şehrin hedef G'ye tahmini (sezgisel) uzaklıkları vardır (ekrandan, 01:45:00).

Yollar (ekrandan, 01:45:00):

| Kenar | Mesafe |
|---|---|
| S–A | 3 |
| S–D | 4 |
| A–B | 4 |
| A–D | 5 |
| B–C | 4 |
| B–E | 1 |
| D–E | 5 |
| E–F | 4 |
| F–G | 3 |

Tahmini uzaklıklar $h$: S 11.0, A 10.4, B 6.7, C 4.0, D 8.9, E 6.9, F 3.0, G 0.

Arama ağacında aynı harften birden fazla olabilir; bunlar farklı durumlardır. Örneğin S→A→B ile S→D→E→B ve S→D→A→B, üçü de "B" ile biter ama farklı yollardır.

- **Enlemesine arama:** S'ten başlar, her zaman baştakini çeker ve gidilebilecek durumları kuyruğun sonuna ekler. **Soru:** Bulduğu yolun optimal olduğundan emin olabilir miyiz? **Cevap:** Maliyetler aynı olsaydı evet; burada aynı olmadığı için diyemeyiz. Optimal olabilir, ama öyle olduğu söylenemez.
- **Derinlemesine arama:** Daha kısa sürer, ama bulduğu yol muhtemelen daha kötüdür. Kritik nokta, kuyruğun (yığının) boyutunun çok küçük kalmasıdır; derinlemesine aramanın hafızada tutumlu olduğu burada görülür.
- **Düşük maliyetli arama:** Maliyetler farklı olsa da optimal yolu bulur. Aynı maliyette başka bir yol olabilir, ama daha düşük maliyetli bir yol olamaz.
- **A*:** Aynı yolu yalnızca birkaç adımda bulur.

> **Ders sonrası not:** Altyazıda düşük maliyetli aramanın bulduğu yol "SDEFG" olarak geçiyor. Kenar maliyetleriyle hesaplandığında S–D–E–F–G yolunun maliyeti $4+5+4+3 = 16$'dır; S–A–B–E–F–G yolunun maliyeti ise $3+4+1+4+3 = 15$'tir. Düşük maliyetli arama ve A* (python ile çalıştırıldı) S–A–B–E–F–G yolunu (maliyet 15) bulur; A* tablosunun son satırı da bunu gösterir. Altyazıdaki ifade büyük olasılıkla bir okuma ya da Whisper hatasıdır.

### 10.2 A* tablo gösterimi

> **Hocanın vurgusu:** A*'ın adım adım çalışmasının bu tablo biçiminde gösterilmesi, sınavlarda kuyruğun içeriğini ayrıntılı çizmeniz istendiğinde beklenen gösterimdir.

Her satır bir adımdır. Her hücrede üstte yol, ortada yolun son durumu, altta iki sayı vardır. Bu slaytta sayılar $h + g$ sırasıyla yazılmıştır; ters sırada yazmak da olur, yeter ki tutarlı olsun. Her satırda seçilen (kuyruktan çekilen) durum koyu yazılmıştır. Seçilmeyenler bir alt satıra olduğu gibi kopyalanır, seçilenin yerine ondan gidilebilecek durumlar eklenir.

Tablo (ekrandan, 01:45:00); seçilen durum köşeli parantez içinde:

```text
1: [S 11+0]
2: [SD 8.9+4]  SA 10.4+3
3: [SA 10.4+3]  SDS 11+8  SDA 10.4+9  SDE 6.9+9
4: SDS 11+8  SDA 10.4+9  SDE 6.9+9  SAS 11+6  SAD 8.9+8  [SAB 6.7+7]
5: SDS 11+8  SDA 10.4+9  SDE 6.9+9  SAS 11+6  SAD 8.9+8  SABA 10.4+11
   [SABE 6.9+8]  SABC 4+11
6: SDS 11+8  SDA 10.4+9  SDE 6.9+9  SAS 11+6  SAD 8.9+8  SABA 10.4+11
   [SABC 4+11]  SABED 8.9+13  SABEB 6.7+9  SABEF 3+12
7: SDS 11+8  SDA 10.4+9  SDE 6.9+9  SAS 11+6  SAD 8.9+8  SABA 10.4+11
   SABED 8.9+13  SABEB 6.7+9  [SABEF 3+12]  SABCB 6.7+15
8: SDS 11+8  SDA 10.4+9  SDE 6.9+9  SAS 11+6  SAD 8.9+8  SABA 10.4+11
   SABCB 6.7+15  SABED 8.9+13  SABEB 6.7+9  SABEFE 6.9+16  [SABEFG 0+15]
```

Adımların açıklaması:

- S'ten gidilebilecek iki yer vardır: A ve D. SA için $10.4+3 = 13.4$, SD için $8.9+4 = 12.9$; toplamı en küçük olan SD seçilir.
- SD'den S, A ve E'ye gidilir (SDS, SDA, SDE). Kuyruktaki en küçük toplam SA'nındır ($13.4$); SA seçilir.
- SA'dan S, D ve B'ye gidilir. SAB ($6.7+7 = 13.7$) seçilir.
- SAB'den A, E ve C'ye gidilir. SABE ($6.9+8 = 14.9$) seçilir.
- SABE'den D, B ve F'ye gidilir. SABC ve SABEF'in toplamı eşittir (15); bu tabloda önce SABC seçilmiştir. SABC'den yalnız B'ye dönülebilir (SABCB, $6.7+15$).
- Sonra SABEF ($3+12 = 15$) seçilir; F'den E ve G'ye gidilir.
- SABEFG'nin toplamı $0+15 = 15$ ile en küçüktür; seçilir ve G hedef olduğu için arama biter.

Bu gösterimin güzel tarafı her şeyin net olmasıdır: Örneğin SDE'deki E ile SABE'deki E'nin farklı durumlar olduğu açıkça görülür.

Bulunan yol S–A–B–E–F–G, maliyeti 15'tir (python ile doğrulandı).

### 10.3 Labirentlerde algoritmaların karşılaştırılması

Ekranda iki labirent gösterilir; amaç bir noktadan diğerine gitmektir. A*, ilk en iyi arama, düşük maliyetli arama, enlemesine ve derinlemesine aramanın nereleri deneyip nasıl yollar bulacağı öğrencilere bırakılır. Hocanın ipuçları:

- Enlemesine arama başlangıçtan giderek genişleyen dalgalar şeklinde ilerler.
- Derinlemesine arama bir yönü tutturup ilerler, dönüp durabilir, sonsuzluğa girebilir.
- İlk en iyi arama labirentlerden birinde çok kötü çalışmaz, diğerinde daha kötü çalışır.

## 11. A*'ın optimalliğinin ispatı

A*'ın optimal olma şartı, $h$'nin gerçek maliyeti daha düşük tahmin etmesi (iyimser olması) ve tüm maliyetlerin pozitif olmasıdır (ekrandan, 01:50:00). Neden böyle olduğu şöyle gösterilir.

### 11.1 Kurulum

- Başlangıçtan (Start) bazı adımlarla $n$ durumuna, bazı adımlarla $G_2$'ye gelinebilir.
- $G$ optimal çözüm, $G_2$ suboptimal çözüm olsun; $G_2$ de bir hedeftir ama maliyeti $G$'ninkinden yüksektir.
- Kuyrukta (stack'te) $n$ (optimal yola götüren seçim) ve $G_2$ birlikte olsun.

Soru: A*, $G_2$'yi $n$'den önce açar mı (kuyruktan çeker mi)? $G_2$ ve $n$ ikisi de kuyruktayken A*'ın her zaman $n$'yi seçeceği garanti edilirse, suboptimal bir çözüm varken onu hiç çekmeyeceği için A* optimaldir. Eğer $f(n) < f(G_2)$ gösterilirse $n$, $G_2$'den önce seçilir.

Romanya örneğindeki karşılığı: Kuyrukta Fagaras üzerinden giden Bükreş (suboptimal çözüm, $G_2$) ve Pitesti (optimal çözüme götüren $n$) birlikte vardı. Algoritmanın Pitesti'yi seçeceğini garanti etmek gerekir.

### 11.2 İspat

Slayttaki adımlar (ekrandan, 01:55:00):

1. $f(G_2) = g(G_2)$, çünkü $h(G_2) = 0$.
2. $f(G) = g(G)$, çünkü $h(G) = 0$.
3. $g(G_2) > g(G)$, çünkü $G_2$ optimal değildir.
4. $f(G_2) > f(G)$, çünkü $f(G_2) = g(G_2) + h(G_2)$ ve $f(G) = g(G) + h(G)$.
5. $h(n) \le h^*(n)$; burada $h^*$ gerçek maliyettir. Bu, $h$'nin iyimser olması bilgisidir.
6. $g(n) + h(n) \le g(n) + h^*(n)$: iki tarafa da $g(n)$ eklenir.
7. $f(n) \le f(G)$, çünkü $g(n) + h(n) = f(n)$ ve $n$ optimal yol üzerinde olduğu için $g(n) + h^*(n) = f(G)$.
8. $f(n) < f(G_2)$, çünkü $f(G_2) > f(G)$.

Sonuç: $h$ iyimserse A* suboptimal bir çözüm varken onu asla açmaz, optimal çözüme götüren durumu açar. Dolayısıyla A* optimaldir.

### 11.3 Başka bir harita örneği

Yine rastgele şehirler arasında 2'den 1'e yol aranan bir örnekte A* ve düşük maliyetli arama optimal çözümü bulmuş, ilk en iyi arama ve enlemesine arama bulamamıştır; derinlemesine arama çok daha uzun bir çözüm bulmuştur. Hafıza tüketimi grafiğinde A*'ın gidişatı farklı değildir; işi çok daha az adım sürmesiyle kurtarır. A* uzun süre devam ettirilseydi hafıza açısından derinlemesine aramaya değil, enlemesine aramaya benzerdi. Az sürerse hafızası da az büyür.

## 12. Uygulama: Çok robotlu keşif

Bu bölüm, A*'ın küçük bir uygulamasıdır ve bir araştırma çalışmasına dayanır (ekrandan, 02:00:00).

Bilinmeyen bir ortamın haritası çıkarılacaktır. Elimizde başlangıç noktaları bilinen birkaç robot vardır; robotlar lazerleriyle etrafı tarayarak haritayı çıkarır. Bunun verimli yapılması gerekir: Robot rastgele dolaşırsa haritayı çıkarmak çok uzun sürer. Bir keşif stratejisi gerekir. Yaklaşımlardan biri, keşfedilmiş bölgelerle keşfedilmemiş bölgelerin sınırına gitmektir; burada kullanılan da budur.

Ekrandaki renkler:

- R robotları, H robotlara verilen hedefleri gösterir; çizgiler robotların hedefe gitmek için planladıkları yollardır.
- Turkuaz: keşfedilmiş boş alan.
- Yeşil: keşfedilmiş ve keşfedilmemiş bölgenin sınırı (sınır kuşağı); hedefler bu bloklardan seçilir.
- Sarı: henüz keşfedilmemiş duvarlar; lacivert: henüz keşfedilmemiş boşluklar.

**Tek robotla keşif algoritması:**

1. Hedefleri belirle (keşfedilmiş ile keşfedilmemiş bölgenin sınırındaki noktalar; ortamda birçok hedef olabilir).
2. Hedeflerin iyiliğini hesapla (o hedefe ne kadar hızlı varılır; bunun için oraya giden yolu bulmak gerekir, bu da A* gibi bir algoritmayla yapılır; başka kriterler de eklenebilir).
3. Hedefi seç.
4. Hedefe giden yolu bul (önce bir ön planlama, sonra A*).
5. Robotu hedefe götür.
6. Robot hedefe varınca yeni hedef ata.

**Çok robotla keşif algoritması:**

1. Hedefleri belirle.
2. Her robot için hedeflerin iyiliğini hesapla.
3. Robot-hedef eşlemesi yap.
4. Yolları bul.
5. Robotları hedeflerine götür.

Gösterilen simülasyonda robot sayısı fazlayken her robot ayrı hedefe gider; hedef sayısı azaldıkça birden fazla robot aynı hedefi seçer. Yollar uzadıkça hesaplama daha uzun sürer. Sonunda tüm ortam taranır.

Bu sistemde A* yüzlerce kez çözülür. Sezgisel algoritmalar olmasa bu tür uygulamaları çalıştırmak mümkün olmazdı; kör aramayla pratikte bir şey yapmak kolay değildir. Ancak bazı problemlerde bir durumun hedefe ne kadar uzak olduğunu tahmin etme imkânı olmayabilir; o durumda yapılabilecek tek şey kör arama algoritmalarını kullanmaktır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:17:21): Artan derinlikte arama (IDS), derinlemesine ve enlemesine aramanın iyi taraflarını birleştirir. Eksik tarafı nedir?

> **Cevap (derste verildi):** Zaman kaybı. Aynı düğümleri tekrar tekrar açar; bir düğüm ne kadar yukarıdaysa o kadar çok tekrar açılır.

**Soru 2** (ekrandan, 00:20:00): my_search.m örneğinde enlemesine arama 12'den 1'e 128 uzunluğunda bir yol (12 4 2 5 1) buldu. Bundan daha kısa bir yol olmadığını söyleyebilir miyiz? Düşük maliyetli aramanın bulduğu yol (12 9 15 7 1, maliyet 110) için ne söylenebilir?

> **Cevap (derste verildi):** BFS için söylenemez; maliyetler eşit olmadığından BFS en az adımlı çözümü bulur, en az maliyetliyi değil. UCS için söylenebilir: Tüm maliyetler pozitifse UCS optimaldir, bulduğu 110'luk yoldan daha kısa yol yoktur (aynı maliyette başka yol olabilir).

**Soru 3** (derste sözlü, 00:50:46): Kuş uçuşu mesafe iyimser bir tahmin midir, kötümser mi?

> **Cevap (derste verildi):** İyimserdir; gerçek yol mesafesi kuş uçuşu mesafeden kısa olamaz.

**Soru 4** (ekrandan, 01:05:00): Labirent örneğinde ilk en iyi aramanın kötü tarafı nedir?

> **Cevap (derste verildi):** O noktaya kadar gelmenin maliyetini ($g$) hesaba katmaz; daha kısa yol varken çok uzun yollar bulabilir.

**Soru 5** (derste sözlü, 01:12:42): A* looplara takılmamayı nasıl sağlar?

> **Cevap (derste verildi):** O ana kadarki toplam maliyeti, $g$'yi işin içine katar. Loop oluşursa $g$ artar ve o yol seçilmez; ek kontrol gerekmez.

**Soru 6** (ekrandan, 01:15:00): Başlangıç durumu 7 2 4 / 5 _ 6 / 8 3 1, hedef _ 1 2 / 3 4 5 / 6 7 8 olan 8 taş problemi için $h_1(S)$ ve $h_2(S)$ nedir? İkisi de iyimser midir?

> **Cevap (derste verildi):** $h_1(S) = 8$, $h_2(S) = 3+1+2+2+2+3+3+2 = 18$. İkisi de iyimserdir: $h_2$ taşları aradaki taşlar yokmuş gibi hareket ettirir; örneğin 7 gerçekte üç hamlede yerine gelemez. $h_1$ ise $h_2$'den de küçüktür.

**Soru 7** (derste sözlü, 01:22:23): $h_1$ ile $h_2$ arasında her zaman geçerli bir büyüklük ilişkisi var mıdır?

> **Cevap (derste verildi):** $h_2 \ge h_1$. Yerinde olmayan her taşın uzaklığı en az 1'dir; tüm uzaklıklar 1 olduğunda ikisi eşit olur.

**Soru 8** (ekrandan, 01:25:00): $h_2$'nin $h_1$'e baskın olması ve arama için daha uygun olması, $h_2$ ile daha iyi çözüm bulunacağı anlamına mı gelir?

> **Cevap (derste verildi):** Hayır. Çözüme daha kısa sürede ulaşılır; iki sezgiyle bulunan çözümlerin maliyeti aynıdır. $d=12$ için A*($h_1$) 227, A*($h_2$) 73 durum açar.

**Soru 9** (derste sözlü, 01:24:33): 8 taş probleminde tüm operatörlerin maliyeti eşitse artan derinlikte arama optimal midir?

> **Cevap (derste verildi):** Evet; maliyetler eşit olduğu için optimaldir. Ama $d=12$'de optimal çözümü bulana kadar 3,6 milyon eleman çeker.

**Soru 10** (derste sözlü, 01:27:06): Yedi hücreli dizide üç siyah, bir boş, üç beyaz pul vardır. Hedef tüm beyaz pulların siyahların soluna geçmesidir. Operatörler: Pul yanındaki boş yere gider (maliyet 1) ya da pulların üzerinden atlayarak boş yere gider (maliyet 2). Bu problem için bir sezgisel fonksiyon ($h$) önerin. <!-- BELİRSİZ: Atlama operatörünün tam tanımı altyazıdan net çıkmıyor; slayt karesi yok. -->

> **Çözüm (derste verilmedi):** Bir öneri: $h(n)$ = solunda en az bir siyah pul bulunan beyaz pulların, solundaki siyah pul sayılarının toplamı (yani "siyah solda, beyaz sağda" olan pul çiftlerinin sayısı). Hedefte bu sayı 0'dır, başlangıçta $3 \times 3 = 9$'dur. Kaydırma hamlesi pulların sırasını değiştirmez, bu sayıyı değiştirmez. Bir atlama en fazla atlanan pul sayısı kadar çiftin sırasını değiştirir. Atlamanın maliyeti en az atlanan pul sayısı kadarsa (bir pulun üzerinden atlama 1'den, iki pulun üzerinden atlama 2'den az değilse), her hamle $h$'yi en fazla maliyeti kadar azaltır; dolayısıyla $h$ hiçbir zaman gerçek maliyetten büyük olmaz, iyimserdir.

**Soru 11** (derste sözlü, 01:42:39): S, A, B, C, D, E, F, G graf örneğinde enlemesine aramanın bulduğu yolun optimal olduğundan emin olabilir miyiz?

> **Cevap (derste verildi):** Maliyetler aynı olsaydı evet; burada aynı olmadığı için diyemeyiz. Optimal olabilir, ama olduğu söylenemez.

**Soru 12** (ekrandan, 01:45:00): Aynı grafta A*'ı adım adım kuyruk tablosuyla çalıştırın.

> **Cevap (derste verildi):** Bölüm 10.2'deki tablo; bulunan yol S–A–B–E–F–G, maliyet 15.

**Soru 13** (derste sözlü, 01:48:06): Verilen iki labirentte A*, ilk en iyi arama, düşük maliyetli arama, enlemesine ve derinlemesine arama nereleri dener ve nasıl yollar bulur? <!-- BELİRSİZ: Labirentlerin ayrıntısı karede okunmuyor; yalnız slayt küçük resmi görünüyor. -->

> **Cevap:** Derste çözülmedi, öğrencilere bırakıldı. Hocanın ipuçları için Bölüm 10.3'e bakınız.

**Soru 14** (derste sözlü, 01:49:51): İyimser bir $h$ kullanılırsa A* neden optimal olur?

> **Cevap (derste verildi):** Bölüm 11'deki ispat: $f(n) \le f(G) < f(G_2)$ olduğundan optimal yola götüren $n$ her zaman suboptimal hedef $G_2$'den önce seçilir.

## Dersin Toparlaması

Ders, kör arama algoritmalarının ortak yapısının (listenin neresine eklendiği, neyin çekildiği) ve eksiklerinin üzerinden geçerek başladı: İki yönlü arama üstteki derinliği yarıya indirir; derinlemesine arama tekrarlayan durumlarda sonsuza gidebilir ve yoldaki durumları tekrar eklememekle kurtarılır. Asıl eksik, kör algoritmaların hedefe ne kadar kaldığını hiç dikkate almamasıdır. Sezgisel arama bu boşluğu bir tahminle, $h(n)$ ile doldurur. İlk en iyi arama yalnız $h(n)$'ye bakar; çok hızlıdır ama tam ve optimal değildir. A* ise $f(n) = g(n) + h(n)$ kullanır; tamdır, looplara takılmaz ve $h$ iyimserse optimaldir. İspat, optimal yola götüren bir durumun $f$ değerinin her zaman suboptimal bir hedefinkinden küçük olduğunu gösterir.

8 taş örneği, iyi bir sezginin ne kadar büyük fark yarattığını gösterir: Baskın sezgi $h_2$, aynı maliyetli çözümü $h_1$'den çok daha az durum açarak bulur ve IDS'nin milyonlarca adımına karşılık yüzler mertebesinde kalır. Çok robotlu keşif uygulaması da A*'ın gerçek sistemlerde yüzlerce kez çözülebilecek kadar hızlı olduğunu gösterir. Sonraki derste yerel arama ile devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
