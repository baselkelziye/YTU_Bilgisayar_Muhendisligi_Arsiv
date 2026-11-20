# Ders 4 Genişletilmiş Notu: Sezgisel Arama: İlk En İyi Arama ve A* Arama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kör Arama Algoritmalarının Tekrarı
- 2. Uygulama Tekrarı: my_search.m
- 3. Sezgi Nedir?
- 4. İlk En İyi Arama (Best-First Search)
- 5. A* Arama
- 6. Labirentte Yol Bulma
- 7. A*'ın Analizi ve İyimser Sezgi
- 8. 8 Taş Problemi İçin Sezgisel Kurallar
- 9. Baskınlık ve Arama Maliyetleri
- 10. Esnetilmiş Problemler ve Bir Alıştırma
- 11. A* Aramayı Dizi Tablosuyla Adım Adım İzlemek
- 12. A*'ın Optimalliğinin İspatı
- 13. İkinci Graf Üzerinde Karşılaştırma
- Örnek Sorular
- Dersin Toparlaması

## 1. Kör Arama Algoritmalarının Tekrarı

Ders, bir önceki hafta bitirilen kör arama algoritmalarının tekrarıyla başladı. Hoca altı kör arama algoritmasını (enlemesine, düşük maliyetli, derinlemesine, sınırlı derinlikte, artan derinlikli ve çift yönlü arama) ekrana getirdi (ekrandan, 00:15:00). Bu algoritmaların dört kritere göre nasıl olduğunu öğrencilere sordu: tamlık, zaman karmaşıklığı, hafıza karmaşıklığı ve optimallik.

### 1.1 Enlemesine ve derinlemesine arama

Bir öğrenci derinlemesine aramanın hafıza bakımından daha iyi, enlemesine aramanın daha kötü olduğunu hatırladı. Hoca iki algoritma arasındaki algoritmik farkı sordu ve kendisi cevapladı: elimizde bir dizi vardır. Bir düğümden üretilen yeni durumlar enlemesine aramada dizinin **sonuna**, derinlemesine aramada **başına** eklenir. Fark bu kadardır; ikisi de üretilen her durumu diziye atar.

**Soru:** Derinlemesine arama aslında yığın (stack) kullanmıyor mu?
**Cevap:** Diziyi bir yerde başa ekleme, bir yerde sona ekleme diye düşünebilirsiniz; ya da biri kuyruk (ilk giren ilk çıkar), öteki yığın (son giren ilk çıkar) diye düşünebilirsiniz. Her iki durumda da üretilen bütün durumlar ya kuyruğa ya yığına atılır. Bu açıdan bir fark yoktur.

Tamlık açısından: derinlemesine arama sonsuz bir uzayda aşağı doğru sonsuza kadar inebilir ve daha yukarıdaki düğümleri hiç açamayabilir; bu yüzden tam değildir. Enlemesine arama sırayla gittiği için çözüm varsa mutlaka bulur. Hoca "tam" kavramının pratikteki anlamını şöyle özetledi: sonsuz döngüye takılmamak.

### 1.2 Optimallik

Derinlemesine arama optimal değildir: çok derine inerken yukarıda daha iyi bir çözüm varsa onu kaçırabilir. Enlemesine arama ise bir şartla optimaldir: bütün operatör maliyetleri birbirine eşit olmalıdır. Düşük maliyetli arama (uniform cost search) kuyruğun başındakini ya da sonundakini çekmek yerine durumları köke olan maliyetlerine göre sıralar ve en düşük maliyetliyi seçer. Enlemesine aramaya çok benzer; maliyetler eşitse ikisi aynı algoritmadır. Fark şudur: maliyetler birbirinden farklıysa enlemesine arama optimal değildir, ama düşük maliyetli arama maliyetler farklı olsa da optimaldir.

### 1.3 Sınırlı derinlikte, artan derinlikli ve çift yönlü arama

Sınırlı derinlikte aramada bir derinlik sınırı belirlenir ve o sınırın içinde derinlemesine arama yapılır. Sınırın ötesi hiç açılmadığı için algoritma sonsuz döngüye girmez; derinlemesine aramadan temel farkı budur. Çözüm sınırın içindeyse mutlaka bulunur. Seçilen derinlik çözümü içermiyorsa bulunamaz; bu yüzden tam değildir. Optimal de değildir. Maliyetler eşit olsa bile, örneğin sınır 5 iken 3. derinlikte bir çözüm varsa, 5. derinlikteki bir çözüm ondan önce açılabilir.

Artan derinlikli arama derinlik sınırını sıfırdan başlatıp birer birer artırır. Bu yüzden yukarıdaki (daha düşük maliyetli) çözümü daha önce bulur. Enlemesine arama gibi, maliyetler eşitse optimaldir; maliyetler farklıysa değildir. Ayrıca tamdır. Bir öğrencinin hatırlattığı başka bir güzelliği de vardır: her sınırın içinde derinlemesine arama yapıldığı için hafıza gereksinimi doğrusal artar. Enlemesine ya da düşük maliyetli aramadaki gibi üstel artmaz.

Çift yönlü aramada iki uçtan birden enlemesine arama yapılır. $d$ derinliğinde bir çözüm varsa her iki taraf da yalnız $d/2$ derinliğe kadar arar. Süreler üstel olduğu için kazanç büyüktür: $b^d$ yerine $2\,b^{d/2}$.

## 2. Uygulama Tekrarı: my_search.m

Hoca önceki dersteki MATLAB uygulamasının sonuç ekranını yeniden açtı (ekrandan, 00:20:00). Grafikte 12. şehirden 1. şehre yol aranıyor. Algoritmaların bulduğu yollar şunlardır:

```text
breadth first yol = 12  4  2  5  1
uniform cost yol  = 12  9  15  7  1
depth first yol   = 12  11  9  15  18  17  13  10  7  14  8  5  1
astar yol         = 12  9  15  7  1
best first yol    = 12  9  15  18  1
```

Grafiğin başlığında maliyetler ve adım sayıları yazıyor: maliyetler dfs=314, bfs=128, ucs=110, bsfs (ilk en iyi)=110, as (A*)=110; adım sayıları dfs=24, bfs=37, ucs=79, bsfs=5, as=6 (ekrandan, 00:20:00).

Hoca önce yukarıdaki grafiğe bakmadan yalnız yollara bakarak ne söylenebileceğini sordu. Enlemesine aramanın bulduğu yol düşük maliyetli aramanınkinden daha iyi olamaz, en iyi ihtimalle ona eşittir. Düşük maliyetli arama ise maliyetler farklı olsa bile optimaldir; bulduğu yol en iyisidir. Derinlemesine arama optimal olmadığı için onun yolunun iyi olup olmadığı şansa bağlıdır; çok şanslıysa düşük maliyetli arama kadar iyi bir yol bulabilir, ama daha iyisini bulamaz.

Sonra yollar incelendi. Düşük maliyetli aramanın yolu (12, 9, 15, 7, 1) adım adım hedefe yaklaşır. Derinlemesine aramanın yolu ise 12'den 11'e, 9'a, 15'e, 18'e gider. 18'den hedef 1'e tek adımda gidilebilecekken algoritma 17'ye gider; sonra 13, 10, 7, 14... Hedefe bir yaklaşıp bir uzaklaşır. Derinlemesine aramanın yolunu kötü saymamızın nedeni maliyetinin yüksek olmasıdır. Bunun kaynağı da algoritmanın hedefe ne kadar yakın olduğuna dair hiçbir bilgi kullanmamasıdır. Hoca bunun derinlemesine aramaya özgü olmadığını, kör algoritmaların hiçbirinin o anki durumun hedefe yakınlığını kullanmadığını vurguladı.

Sağdaki grafikte yatay eksen adım numarasıdır, yani kuyruktan ya da yığından çekilen eleman sayısı. Dikey eksen liste boyutudur. Derinlemesine aramanın iyi tarafları burada görülür: kısa sürmüştür ve liste boyutu bir yere kadar artıp sonra sabit kalır. Diğerlerinde adım arttıkça hafıza gereksinimi de artar. A* ve ilk en iyi arama grafiğin en altında kalmıştır: ilk en iyi arama 5, A* 6 adımda hedefi bulmuştur. Optimal olan düşük maliyetli arama 110'luk yolu bulur; enlemesine arama 128'lik bir yol bulmuştur. Ama düşük maliyetli arama bunun için büyük bir bedel öder (79 adım). A* aynı yolu çok daha az adımda, dolayısıyla daha küçük bir liste boyutuyla bulur.

## 3. Sezgi Nedir?

Hoca sezgisel arama slaytlarına geçti. Arama algoritmalarında sezgi, **hedefe ne kadar yakın olduğumuza dair bir tahmin** üretmektir. Arama algoritmaları aslında kuyruktaki elemanlardan hangisinin seçileceğine dair bir stratejidir. Şimdiye kadar bu seçim ya mekanik yapıldı (en baştakini ya da en sondakini seç) ya da düşük maliyetli aramadaki gibi kökten o duruma gelmenin maliyetine göre yapıldı. Hiç kullanılmayan bilgi, durumun hedefe ne kadar yakın olabileceğidir.

Hoca neden "hedefe uzaklık" değil de "hedefe tahmini uzaklık" dediğini sordu. Köke olan uzaklık hesaplanabilir, çünkü o yolu takip ederek gelinmiştir. Hedefe olan gerçek uzaklığı hesaplamak için ise hedefe nasıl gidileceğini bilmek gerekir. Yol bilinseydi arama algoritması uygulamaya zaten gerek kalmazdı. Bu yüzden ancak bir tahmin yapılabilir; bu tahmin algoritmanın sezgisel kısmıdır.

Sezgisel arama algoritmaları slayttaki sırayla şunlardır (ekrandan, 00:30:00):

- İlk En İyi Arama (Best-first search)
- A* arama
- Lokal arama (Local search algorithms)
  - Tepe Tırmanma (Hill-climbing search)
  - Rasgele Başlangıçlı Tepe Tırmanma (Random-restart hill climbing)
  - Paralel Tepe Tırmanma (Local beam search)
  - Benzetimli Tavlama (Simulated annealing search)
  - Genetik Algoritmalar

Bu derste ilk ikisi işlendi. Hoca lokal algoritmaların şimdiye kadar görülen problemlerden çok temel bir farkı olduğunu ve sonraki derslere kaldığını söyledi.

### 3.1 Sezgisel arama bize ne kazandırır?

Romanya haritası üzerinde hoca şu soruyu sordu: Elimizde yalnız şehirler arası yol uzunlukları olsaydı (hedefe kuş uçuşu mesafeler olmasaydı), Arad'dan Bükreş'e en kısa yolu kör arama algoritmalarından biriyle bulabilir miydik? Bir öğrenci düşük maliyetli aramanın bulacağını söyledi. Doğrudur, çünkü düşük maliyetli arama maliyetler farklı olsa da optimal çözümü bulur.

O zaman neden sezgisel arama kullanılır? Sezgisel arama algoritmaları düşük maliyetli aramanın bulduğundan daha iyi bir çözüm bulamaz. Aynı maliyette bir çözümü bulurlar, ama çok daha hızlı bulurlar. Zaman azalınca hafıza da azalır; düşük maliyetli aramanın hafıza maliyeti yüksektir, çünkü uzun sürer.

> **Hocanın vurgusu:** Sezgisel arama algoritmaları daha iyi bir çözüm bulmaz, çözümü bulma hızını artırır. A şehrinden B şehrine yolu düşük maliyetli arama örneğin 10 dakikada buluyorsa, A* aynı yolu 10 saniyede bulur.

Bunun bir bedeli vardır: sezgisel arama için fazladan bir bilgi gerekir. Şehirler arası en kısa yol probleminde bu, her şehrin hedef şehre kuş uçuşu mesafesidir. Herhangi bir durumda hedefe ne kadar yakın olunduğu bilinemiyorsa sezgisel arama kullanılamaz, kör arama kullanmak zorunludur. Sezgisel yöntem problemden probleme değişir, ama hepsinin temeli hedefe yakınlığa dair bir bilgidir.

## 4. İlk En İyi Arama (Best-First Search)

### 4.1 Algoritma ve değerlendirme fonksiyonu

İlk en iyi arama ile A*'ın algoritması tamamen aynıdır; yalnız değerlendirme fonksiyonu değişir. Algoritmanın yapısı da şimdiye kadar görülen arama algoritmalarıyla aynıdır. Kuyruk kök durumla başlar; kuyruk boş değilken ve çözüm bulunmamışken kuyruktan ilk durum çekilir, hedefse bulundu işaretlenir, değilse ondan gidilebilecek tüm durumlar kuyruğa eklenir. Tek fark seçim kısmındadır: kuyruktaki durumlara bir değerlendirme fonksiyonuna göre puan verilir, durumlar bu puana göre küçükten büyüğe sıralanır ve ilki çekilir. Sıralamak yerine "kuyruktan değerlendirme fonksiyonu en düşük olan durumu çek" de denebilir; sonuç farklı olmaz.

İlk en iyi aramada değerlendirme fonksiyonu $f(n) = h(n)$'dir. $h(n)$ sezgidir (heuristic): mevcut durumun hedefe tahmini uzaklığı. Şehirler için tahmini maliyet olarak kuş uçuşu mesafe (straight line distance) kullanılabilir: dümdüz bir çizgi üzerinde gidilseydi kaç kilometre sürerdi. Algoritma her adımda kuyruktaki durumların hedefe tahmini uzaklıklarına bakar ve en küçüğünü seçer; yani her adımda **hedefe en yakın görünen** duruma ilerler. Ne kadar yol gelindiğine hiç bakmaz. Düşük maliyetli arama kökten oraya kaça gelindiğine göre seçim yapıyordu; ilk en iyi arama ise yalnız "hedefe ne kadar yakınım" sorusuna bakar.

### 4.2 Romanya haritası

Amaç Arad'dan Bükreş'e (Bucharest) en kısa yolu bulmaktır (ekrandan, 00:35:00). Haritada şehirler arası yol uzunlukları vardır; sağdaki tabloda her şehrin Bükreş'e kuş uçuşu mesafesi yazar:

| Şehir | $h_{SLD}$ | Şehir | $h_{SLD}$ |
|---|---|---|---|
| Arad | 366 | Mehadia | 241 |
| Bucharest | 0 | Neamt | 234 |
| Craiova | 160 | Oradea | 380 |
| Dobreta | 242 | Pitesti | 100 |
| Eforie | 161 | Rimnicu Vilcea | 193 |
| Fagaras | 176 | Sibiu | 253 |
| Giurgiu | 77 | Timisoara | 329 |
| Hirsova | 151 | Urziceni | 80 |
| Iasi | 226 | Vaslui | 199 |
| Lugoj | 244 | Zerind | 374 |

Kare çözünürlüğünde Pitesti satırı "10" gibi kesik görünüyor; A* örneğindeki $417=317+100$ etiketi (ekrandan, 00:50:00) bu değerin 100 olduğunu gösterir. Örnekte kullanılan yol uzunlukları: Arad-Zerind 75, Arad-Sibiu 140, Arad-Timisoara 118, Zerind-Oradea 71, Oradea-Sibiu 151, Sibiu-Fagaras 99, Sibiu-Rimnicu Vilcea 80, Rimnicu Vilcea-Pitesti 97, Rimnicu Vilcea-Craiova 146, Pitesti-Craiova 138, Fagaras-Bucharest 211, Pitesti-Bucharest 101.

Adımlar (ekrandan, 00:40:00):

1. Kuyrukta yalnız Arad (366) vardır; çekilir. Arad'dan gidilebilecek 3 yer vardır: Sibiu (253), Timisoara (329), Zerind (374).
2. En küçük değer Sibiu'nundur; Sibiu hedefe daha yakın göründüğü için seçilir. Sibiu'dan Arad, Fagaras, Oradea ve Rimnicu Vilcea'ya gidilebilir (Arad'a geri dönmek de mümkündür). Kuyrukta artık 6 eleman vardır.
3. Altı elemandan değeri en küçük olan Fagaras (176) seçilir. Fagaras'tan Sibiu'ya geri dönülebilir ya da Bükreş'e gidilebilir. Kuyrukta 7 eleman olur.
4. Bükreş'in kuş uçuşu mesafesi 0 olduğu için seçilir. Seçilen durum hedef olduğu için algoritma biter.

Bulunan yol Arad-Sibiu-Fagaras-Bükreş'tir; uzunluğu $140+99+211=450$. Bu yol optimal değildir; haritada daha iyi bir yol (Rimnicu Vilcea ve Pitesti üzerinden, 418) vardır. Dolayısıyla ilk en iyi arama optimal bir algoritma değildir. (Adımlar ve kuyruk boyutları python ile kontrol edildi.)

### 4.3 İlk en iyi aramanın analizi

Slayttaki analiz şöyledir (ekrandan, 00:45:00):

- **Tam mı?** Hayır, döngülere takılabilir. Örneğin hedefe aynı mesafede iki durum arasında sonsuz döngü oluşabilir.
- **Zaman:** $O(b^m)$, ancak iyi sezgisel kurallar büyük iyileşmeler sağlayabilir.
- **Hafıza:** $O(b^m)$, tüm durumlar hafızadadır.
- **Optimal mi?** Hayır.

Hoca döngü örneğini tahtaya çizerek anlattı: hedefe olan tahmini uzaklıkları aynı olan ve birbirine yolu olan iki durum düşünelim. Biri seçilince öteki kuyruğa girer ve o seçilir; ondan da ilkine yol olduğu için ilki tekrar seçilir. İki durum arasında sonsuz bir döngü oluşabilir. Zaman ve hafıza bakımından hoca şunu ekledi: bu algoritmalar enlemesine arama türünden algoritmalar olduğu için zamanı azalttığınızda hafızayı da otomatik olarak azaltırsınız.

## 5. A* Arama

### 5.1 Değerlendirme fonksiyonu

A*'da değerlendirme fonksiyonuna $h(n)$'nin yanına $g(n)$ eklenir:

$$f(n) = g(n) + h(n)$$

- $g(n)$: kökten mevcut duruma ($n$) gelişin maliyeti. Bu, düşük maliyetli aramanın kullandığı değerdir.
- $h(n)$: mevcut durumdan hedefe gidişin tahmini maliyeti.
- $f(n)$: kökten hedefe, $n$'den geçerek gidişin tahmini maliyeti.

Hoca $f(n)=g(n)$ alınırsa algoritmanın ne olacağını sordu; öğrenciler düşük maliyetli arama dedi. A*, düşük maliyetli aramanın içine $h(n)$ eklenmiş halidir. Slayttaki fikir de budur: kökten itibaren toplam maliyeti yüksek durumlara gidişi engellemek.

### 5.2 Romanya haritasında A*

Her durumun altında $f(n) = g(n) + h(n)$ yazılır (ekrandan, 00:50:00 ve 00:55:00):

1. Başlangıç: Arad $366 = 0 + 366$. Başlangıçta olunduğu için $g = 0$'dır.
2. Arad açılır: Sibiu $393 = 140 + 253$, Timisoara $447 = 118 + 329$, Zerind $449 = 75 + 374$. Sibiu'nun 140'ı Arad'dan Sibiu'ya gelmenin maliyeti, 253'ü Sibiu'dan Bükreş'e gitmenin tahmini maliyetidir. En küçük toplam 393 olduğu için Sibiu seçilir.
3. Sibiu açılır: Arad $646 = 280 + 366$, Fagaras $415 = 239 + 176$, Oradea $671 = 291 + 380$, Rimnicu Vilcea $413 = 220 + 193$. Kuyrukta 6 eleman vardır. Rimnicu Vilcea'nın 220'si Arad-Sibiu (140) ile Sibiu-Rimnicu Vilcea (80) yollarının toplamıdır. 413 en küçük değer olduğu için Rimnicu Vilcea seçilir.
4. Rimnicu Vilcea açılır: Craiova $526 = 366 + 160$, Pitesti $417 = 317 + 100$, Sibiu $553 = 300 + 253$. Kuyrukta 8 eleman vardır. En küçük değer Fagaras'ın 415'idir; Fagaras seçilir.
5. Fagaras açılır: Sibiu $591 = 338 + 253$, Bükreş $450 = 450 + 0$. Bükreş artık kuyruktadır, ama seçilmez. İlk en iyi arama kullanılsaydı Bükreş kuyruğa girdiği anda seçilirdi, çünkü o yalnız $h$'ye bakar. A*'da ise $f$, $g$'yi de içerir. 450, Arad-Sibiu-Fagaras-Bükreş yolunun uzunluğudur; ama kuyrukta 417 değerli Pitesti vardır ve oradan daha iyi bir yol bulunabilir.
6. Pitesti açılır: Bükreş $418 = 418 + 0$, Craiova $615 = 455 + 160$, Rimnicu Vilcea $607 = 414 + 193$. Kuyrukta 11 eleman vardır.
7. En küçük değer 418'li Bükreş'tir. Seçilen durum hedef olduğu için arama biter.

Bulunan yol Arad-Sibiu-Rimnicu Vilcea-Pitesti-Bükreş'tir ve maliyeti 418'dir. Bu yol optimaldir. (Adımlar ve kuyruk boyutları python ile kontrol edildi.)

### 5.3 Aynı şehrin birden fazla kopyası

Kuyrukta iki Sibiu, iki Craiova ve iki Bükreş vardır. Hoca bunların aynı şey olup olmadığını sordu. Değillerdir: aynı yere farklı yollardan gelişler farklı durumlar oluşturur. A* bu durumları birbirinden farklı değerlendirir: Bükreşlerden birinin altında 450, ötekinin altında 418; Sibiulardan birinin altında 591, ötekinin altında 553 yazar.

İlk en iyi arama kullanılsaydı iki Sibiu'nun altında ne yazardı? Bir öğrenci, Fagaras'tan sonra Bükreş'e gidileceği için iki Sibiu'nun hiç oluşmayabileceğini hatırlattı; hoca oluştuklarını varsaymasını istedi. Cevap 253'tür: ilk en iyi arama yollara hiç bakmaz, yalnız Sibiu'nun hedefe olan tahmini uzaklığını kullanır. Bu yüzden o ana kadar gelinen yol açısından daha uzun bir yolu daha kısa bir yola tercih edebilir.

**Soru:** Aynı isimli yerlerin değerleri belli. Kuyruğa eklerken önce aynı isimde bir durum var mı diye bakıp yalnız daha düşük maliyetliyi tutmak hafıza açısından yarar sağlamaz mı?
**Cevap:** Doğru, bu kontrol yapılabilir; ama kontrolün de bir maliyeti vardır. Kuyrukta 10 eleman varken sorun değildir, 100 bin eleman varken her eklemeden önce bütün diziyi taramak zor olabilir. Gerek de yoktur: büyük maliyetli kopya, diğerinin önüne hiçbir zaman geçemez. Klasik A*'da böyle bir kontrol yoktur; ama A*'ın birçok varyantı vardır ve belli durumlarda probleme özgü ek yöntemlerle hızlandırmak mümkündür. Algoritmanın optimalliği bundan etkilenmez.

## 6. Labirentte Yol Bulma

Aradan sonra hoca şehirler arası yol bulmadaki sezginin kuş uçuşu mesafe olduğunu hatırlattı ve yeni bir probleme geçti: bir labirentte $S$ noktasından $G$ noktasına gitmek (ekrandan, 01:15:00). Slayttaki mavi hücreler engellerdir. Slayt dört parçalıdır:

- a) Amaç: $S$'den başla, $G$'ye git.
- b) Tüm durumların hedefe olan Manhattan uzaklıkları ($h$).
- c) Best-First ile bulunan yol. Yalnız $h$'leri kullanır.
- d) A* ile bulunan yol. Durumlardaki etiketler $(h+g)$.

Manhattan uzaklığı, arada hiçbir engel yokmuş gibi davranarak dikey ve yatay olarak atılması gereken adım sayısıdır. Hoca bunun kuş uçuşu mesafeye benzediğini söyledi. Örneğin (b)'de bir hücrede 3 yazıyorsa oradan G'ye engel yokmuş gibi 3 adımda gidilebilir; 5 ve 7 yazan hücreler için de aynı şekilde sayılabilir.

### 6.1 İlk en iyi arama ile

$S$ çekilir. $S$'den 3 hareket yapılabilir; komşuların değerleri 6, 6 ve 8'dir. Altılardan biri seçilir; o açılınca 7 eklenir. Kuyrukta 7, 6, 8 vardır; 6 seçilir ve yeni bir 7 eklenir. Elde 7, 7, 8 kalır; yedilerden biri seçilir. Sonra 8, 8, 7 arasından 7; ondan 6 açılır; 8, 8, 6 arasından 6; sonra 5, 4, 3, 2 diye ilerlenir. Yol boyunca hiçbir zaman 8'lik hücrelere dönülmez. Algoritma hedefe doğru görünen kola girer ve optimal olmayan bir yol bulur.

İlk en iyi aramanın kötü tarafı burada açıkça görülür: ne kadar yol gidildiğine hiç bakmaz. Optimal çözüme götürebilecek bir yol vardır, ama oradaki hücrelerin $h$ değerleri hiçbir zaman öbür kolun $h$ değerlerinden küçük olmadığı için o yol hiç açılmaz.

### 6.2 A* ile

A* ile her hücrede iki sayı vardır. Örneğin bir hücredeki "8+1"de 8 Manhattan uzaklığı ($h$), 1 ise $S$'den oraya kaç adımda gelindiği ($g$); "6+3"te 6 G'ye Manhattan uzaklığı, 3 S'den oraya atılan adım sayısıdır. Biri kesin bilinen bir değer, öteki tahmindir.

A* de önce hedefe doğru görünen kolu açar. Ama o kolda ilerledikçe $g$ büyür: değerler 3+6, 2+7, 3+8, 4+9 diye artar. Bir noktadan sonra 4+9'u açmak yerine 8+3'ü açmayı tercih eder. Öbür taraftan her zaman 4+9'dan daha küçük değerler elde edilir ve algoritma G'ye giden optimal yolu bulur. İlk en iyi aramada $h$ değerleri hep küçük kalıyordu, çünkü yalnız $h$'ye bakılıyordu. A*'da $h$'ler küçük olsa da $g$'ler büyüdüğü için yanlış kol bir noktada açılmaz olur.

<!-- BELİRSİZ: Labirentin tam hücre değerleri ve iki algoritmanın bulduğu yolların hücre hücre dökümü karede küçük; yukarıdaki sayılar hocanın sözlü anlatımından alındı. -->

## 7. A*'ın Analizi ve İyimser Sezgi

### 7.1 Analiz

Hoca slayttaki analizi okudu (slayt "A*'ın Analizi"):

- **Tam mı?** Evet, döngülere takılmaz. Tam olmak sonsuz döngüye girmemek demektir.
- **Zaman ve hafıza:** üstel; ancak iyi sezgisel kurallar büyük iyileşmeler sağlayabilir.
- **Optimal mi?** Evet, ama değerlendirme fonksiyonuna bağlıdır.

Hoca neden ilk en iyi aramanın döngüye takıldığını ama A*'ın takılmadığını sordu. Bir öğrenci her adımda kökten gelen uzaklığın arttığını söyledi. Doğrudur: bir döngüye girildiğinde yalnız $h$'ye bakan ilk en iyi aramada değerler hep aynı kalır. A*'da ise aynı yerden bir kez daha geçildiğinde $g(n)$ artar. Romanya örneğinde birden fazla Bükreş ve Sibiu vardı ve altlarındaki değerler hep farklıydı. Aynı yere farklı yollardan gelinse ya da bir döngüde aynı yerden tekrar tekrar geçilse bile, büyüyen değerler yüzünden bu durumlar kuyruktan hiçbir zaman çekilmez.

### 7.2 İyimser sezgi

A*'ın optimal olması için $h(n)$'nin **iyimser** olması gerekir. Bir öğrenci toplamın en küçüğünün mü alınması gerektiğini sordu; hoca bunun ayrı bir şey olduğunu, algoritmanın zaten $f$'ye göre en küçüğü aldığını, burada $h$ fonksiyonunun kendisinden bahsettiğini söyledi.

İyimser tahmin gerçekten daha küçük bir tahmindir. Hoca şöyle anlattı: bir şehirdesiniz ve başka bir şehre olan $h$'yi hesaplıyorsunuz. Oraya gerçekte iki saatte gidebiliyorsanız, iki saatten uzun bir tahmin yapmayacaksınız; bir saat, yarım saat diyeceksiniz. $h$ iyimserse A* optimaldir. $h$ kötümserse A* optimal bir algoritma değildir.

> **Hocanın vurgusu:** A*'ın optimal olabilmesi için $h$'nin iyimser olması şarttır. Bunu aklınızda tutun.

Kuş uçuşu mesafe (straight line distance) kesinlikle iyimserdir: "en iyi ihtimalle dümdüz gidersem" denir. Labirentteki Manhattan uzaklığı da iyimserdir: arada hiç engel yokmuş gibi hareket edilir. Örneğin labirentte bir hücreden hedefe "2 adım" denmişken, gerçekte engelin etrafından dolaşmak gerektiği için yol 2'den çok daha uzundur. Manhattan uzaklığı gerçeğe göre oldukça düşük bir tahmindir.

## 8. 8 Taş Problemi İçin Sezgisel Kurallar

Her problem için ayrı bir sezgisel fonksiyon tasarlamak gerekir; A*'ın gereksinimi budur. Daha önce görülen 8 taş problemi için iki sezgisel kural tanımlandı (ekrandan, 01:35:00):

- $h_1(n)$ = Yerinde olmayan taşların sayısı
- $h_2(n)$ = Taşların hedefteki yerlerine uzaklıkları toplamı (yatay ve dikey hane toplamları, Manhattan distance)

Başlangıç ve hedef durumları ("_" boş haneyi gösterir):

```text
Başlangıç (Start)    Hedef (Goal)
  7 2 4                _ 1 2
  5 _ 6                3 4 5
  8 3 1                6 7 8
```

$h_1(S)$: Başlangıç ile hedef arasında yerinde olan hiç taş yoktur, dolayısıyla $h_1(S) = 8$.

$h_2(S)$: Taşlar 1'den 8'e sırayla incelenir. 1'in olması gereken yere Manhattan uzaklığı 3 adımdır; 2 olması gereken yerin bir yanındadır, uzaklığı 1'dir; 3 için 2, 4 için 2, 5 için 2, 6 için 3 adım gerekir. Slayttaki toplam:

$$h_2(S) = 3+1+2+2+2+3+3+2 = 18$$

(Değerler python ile kontrol edildi; 7 ve 8 taşlarının uzaklıkları 3 ve 2'dir.) Slaytta başka iki durum için de değerler verilmiştir: birinde $h_1=1$, $h_2=1$; ötekinde $h_1=5$, $h_2=1+1+1+2+2=7$.

### 8.1 $h_1$ ve $h_2$ iyimser mi?

Hoca öğrencilere iki kuralın da iyimser olup olmadığını sordu. Bir öğrenci $h_2$'nin uzaklıkları art arda topladığı için fazla göründüğünü söyledi. Hoca iyimserliğin ölçütünü hatırlattı: gerçeğe göre daha küçük bir şey tahmin ediyor mu? $h_1$, taşlar ışınlanabiliyormuş gibi bir uzaklık hesaplar; kaç taş yerinde değilse o kadar adımda oralara gidilebilirmiş gibi. $h_2$ ise arada hiç engel yokmuş gibi gidilebileceğini varsayar.

Örneğin 1 taşı için "3 adımda gidebilir" dendi. Gerçekte 1 oraya 3 adımda gidemez: önce 6'yı kenara çekmek, sonra diğer taşları kaydırmak gerekir; en az yedi sekiz adım vardır. Yani $h_2$ gerçeğe göre daha fazla değil, daha az söyler. Başlangıçtan hedefe 18 adımda gitmek mümkün değildir. Sonuç: $h_1$ ve $h_2$ ikisi de iyimserdir.

### 8.2 Hangisi daha iyimser?

$h_1$ daha iyimserdir. Hoca $h_2$'nin her durumda $h_1$'den büyük ya da eşit olup olmadığını sordu ve gerekçesini birlikte kurdular: $h_1$'de yazan sayı kaçsa $h_2$'de o kadar sayı toplanır. Örneğin $h_1 = 5$ ise $h_2$'de 5 sayı toplanır. Bu sayılar en iyi ihtimalle 1 olabilir; 0 olamazlar, çünkü 0 olan taş zaten yerindedir ve sayılmaz. Dolayısıyla $h_1 = 8$ ise 8 tane en az 1 olan sayının toplamı en az 8'dir. $h_2$ ile $h_1$'den küçük bir değer elde etmek mümkün değildir:

$$h_2(n) \ge h_1(n)$$

Yani $h_2$, $h_1$'den daha kötümserdir ve gerçeğe daha yakındır.

## 9. Baskınlık ve Arama Maliyetleri

Slayttaki tanım (ekrandan, 01:45:00): geçerli (yani iyimser) iki sezgisel kural için tüm durumlarda $h_2(n) \ge h_1(n)$ ise $h_2$ baskındır ($h_2$ dominates $h_1$) ve $h_2$ arama için daha uygundur. Neden daha uygundur? Çünkü $h_2$ gerçeği $h_1$'den daha iyi tahmin eder.

> **Hocanın vurgusu:** A*'ın optimal olması için sezgisel kural iyimser olmalıdır. Ama elinizde birden fazla iyimser kural varsa bunların içinden **en kötümserini**, yani gerçeğe en yakınını kullanmak daha mantıklıdır. Gerçeğe daha yakın tahmin, çözümün daha kısa sürede bulunması demektir.

Slayttaki 8 taş arama maliyetleri (test edilen durum sayısı ortalaması) (ekrandan, 01:45:00):

| Çözüm derinliği | IDS | A*($h_1$) | A*($h_2$) |
|---|---|---|---|
| $d=12$ | 3.644.035 düğüm | 227 düğüm | 73 düğüm |
| $d=24$ | "çoook" düğüm | 39.135 düğüm | 1.641 düğüm |

Bu sayılar kuyruğun büyüklüğü değil, çözüm bulunana kadar kuyruktan çekilen eleman sayısıdır. Hoca $h_1$ ile $h_2$ arasındaki farkın belki o kadar önemli olmadığını, asıl farkın IDS ile A* arasında olduğunu vurguladı. $d=24$'te IDS'i süper bilgisayarda bile çalıştırmak pratikte mümkün değildir; bitmez. A*'ın iki sürümü ise oldukça yapılabilir durumdadır.

### 9.1 Bulunan çözümler aynı mı?

Hoca $d=12$ için şunu sordu: IDS bir çözüm bulur mu? Bulur, daha uzun sürede. Bu çözüm optimal midir? IDS maliyetler eşitse optimaldir (şehirler arası yolda optimal değildi). 8 taşta boş haneyi sağa, sola, yukarı ya da aşağı hareket ettirmenin maliyeti hep bir adımdır; maliyetler eşittir. Bu yüzden IDS optimal çözümü bulur; A*($h_1$) ve A*($h_2$) de optimal çözümü bulur.

Üç algoritmanın bulduğu yollar aynı olabilir de olmayabilir de. Ama kesinlikle aynı olan şey maliyetleridir. Her adımın maliyeti aynı olduğu için maliyet adım sayısına dönüşür; dolayısıyla yolların uzunlukları da aynıdır. İçerikleri farklı olabilir. Maliyetler farklı olsaydı adım sayısına bakarak maliyet kestirilemezdi. Kritik olan, bu çözümleri bulmak için harcanan sürelerin çok farklı olmasıdır.

### 9.2 Tabloda neden enlemesine arama yok?

Hoca tabloda enlemesine arama ya da düşük maliyetli arama yerine neden IDS yazıldığını sordu; onlar da burada optimaldir. Bir öğrenci üstel bir durumda daha karmaşık olabileceğini söyledi. Hoca karmaşıklık yönünden durumu şöyle açıkladı: IDS optimalliği sağlamak için fazladan arama yapar (üst seviyeleri tekrar tekrar açar). Bu yüzden enlemesine arama IDS'ten daha fazla düğüm çekmez; belki yarısı kadar, 1,8 milyon civarı çeker. IDS'in en maliyetli kısmı son katmandır ve son katmandaki düğümler yalnız bir kez açılır; üst katmanlar daha çok açılır ama sayıları az olduğu için etkileri en fazla iki kat civarındadır. Yani enlemesine arama 3,6 milyonu 18 bine ya da bine indiremez.

Asıl sorun **hafızadır**. Enlemesine arama 1,8 milyon düğümü açarken tutması gereken hafıza öyle boyutlara ulaşır ki bilgisayarda tutmak çok zordur. $d=24$'te bellek ne kadar büyük olursa olsun yetmez. Bu yüzden tabloda IDS vardır.

**Soru:** 8 taş probleminde $g(n)$'yi nasıl belirliyoruz?
**Cevap:** Başlangıç durumundan gidilebilecek kaç durum var? Dört. Bu dört durumun her birinin köke uzaklığı 1'dir. Her birinden yine birkaç durum çıkar; onların köke uzaklığı 2 olur. $h(n)$'ler ayrıca hesaplanır.

## 10. Esnetilmiş Problemler ve Bir Alıştırma

### 10.1 Esnetilmiş problemler

Orijinal problemden daha az kısıt içeren problemlere esnetilmiş (relaxed) problemler denir. Sezgisel kuralları üretmek için problem teorik olarak esnetilir:

- 8 taşta bir taş istediği yere gidebilir dersek, $h_1(n)$ en kısa çözümü verir.
- 8 taşta bir taş istediği komşusuna gidebilir (engel olsa da) dersek, $h_2(n)$ en kısa çözümü verir.

> **Ek bilgi (derste anlatılmadı):** Esnetilmiş problem orijinal problemin bütün hamlelerine ve ek hamlelere izin verdiği için, esnetilmiş problemin en kısa çözümü orijinal problemin en kısa çözümünden uzun olamaz. Bu yüzden esnetilmiş problemin kesin çözüm maliyeti, orijinal problem için iyimser (kabul edilebilir) bir sezgidir.

### 10.2 Alıştırma: yedi gözlü dizi

Hoca bir problemi egzersiz olarak bıraktı. Yedi gözlü bir dizi vardır. Dizinin soldaki ilk üç gözüne siyah (B), sonraki üç gözüne beyaz (W) taşlar konmuştur. Operatörler:

- Bir taş, yanındaki taşın diğer yanı boşsa onun üzerinden atlayabilir. Maliyeti 2'dir.
- Bir taş yanındaki boş yere gidebilir. Maliyeti 1'dir.

Hedef: tüm beyaz taşların siyah taşların solunda olması. Slayttaki soru, bu problem için hangi $h$ önerilerinin olabileceğidir. <!-- BELİRSİZ: Bu slaytın karesi yok. Boş gözün başlangıçta en sağda olduğu (BBBWWW_) altyazıdan çıkarıldı; altyazıda "V" ve "B" olarak geçen harflerin slayttaki gösterimi doğrulanamadı. --> Çözüm önerisi "Örnek Sorular" bölümündedir.

## 11. A* Aramayı Dizi Tablosuyla Adım Adım İzlemek

### 11.1 Aynı problem, farklı algoritmalar

Hoca klasik şehirler arası yol problemine döndü. Şekil 1'de şehirler arası yollar, Şekil 2'de her şehrin hedef $G$'ye tahmini uzaklığı vardır. Enlemesine aramada yığının (dizinin) içeriği hızla büyür; derinlemesine aramada çözüm bulunana kadar çok fazla eleman birikmez. İki algoritma farklı yollar bulmuştur.

**Soru:** Enlemesine aramanın bulduğu çözüm optimaldir diyebilir miyiz?
**Cevap (bir öğrenci):** Diyemeyiz, maliyetler eşit değil. Hoca onayladı. Düşük maliyetli aramanın bulduğu sonuç ise optimaldir, çünkü maliyetler farklı olsa da optimal sonuç bulur. Bu grafikte düşük maliyetli arama S-D-E-F-G yolunu bulmuştur; bu yolu bulan diğer algoritmaların yolu da optimaldir. Düşük maliyetli aramanın hafıza gereksinimi oldukça büyüktür. A*'da ise bellek çok küçüktür ve oldukça az adımda sonuca ulaşılır.

<!-- BELİRSİZ: Bu karşılaştırma slaytlarının (enlemesine, derinlemesine, düşük maliyetli arama ağaçları) karesi yok. Bu slaytlardaki graf ile aşağıdaki tablo slaytının grafı aynı değildir; ders sırasında öğrenciler kenar maliyetlerinin farklı olduğunu fark etti (02:09:52). -->

> **Hocanın vurgusu:** Sınavlarda genelde bu gösterimi istiyorum: ağaç gösterimi değil, dizinin (yığının) içeriğinin adım adım gösterimi. Bunu elle gerçekten yapın. Bir yerde "dizinin içeriğini göstererek arama algoritmasını ilerletin" gibi bir şey görürseniz bunu yapmalısınız.

### 11.2 Tablonun okunuşu

Tablodaki her satır **aynı dizinin** farklı zamanlardaki halidir: $t=1$ anındaki hali birinci satır, $t=2$ anındaki hali ikinci satır vb. Elde bir matris yoktur, bir dizi vardır. Satır sayısı kuyruktan kaç eleman çekildiğini gösterir; bu örnekte sekizinci çekilen düğüm hedeftir ve A* orada durur. Dizinin boyutu da tabloda görülür. Hoca A*'ın bellek yönetimi açısından derinlemesine arama kadar iyi olmadığını, gereken adım sayısı büyüdükçe belleğin de büyüdüğünü, ama çok fazla adıma ihtiyaç duymadığı için kurtardığını söyledi. A*'ın çok sayıda varyantı vardır; ders kapsamında onlara girilmedi.

Her hücre bir durumu gösterir. Örneğin "SDE / E / 6.9+9" hücresi: S'den D'ye, D'den E'ye giden yol (SDE); bu yolun son bulunduğu yer E; altında $h+g$. 6.9, E'nin hedefe tahmini uzaklığıdır; 9 ise S-D-E yolunun uzunluğudur ($4+5$). Birden fazla E olabilir (S-A-D-E, S-A-B-E gibi); bunlar farklı durumlardır ve A*'da farklı değerler alırlar.

### 11.3 Graf ve sezgi değerleri

Slayttaki graf (ekrandan, 01:55:00):

```text
Kenarlar: S-A 3, S-D 4, A-B 4, A-D 5, B-C 4, B-E 1,
          D-E 5, E-F 4, F-G 3
h (G'ye tahmini uzaklık): S 11.0, A 10.4, B 6.7, C 4.0,
          D 8.9, E 6.9, F 3.0, G 0
```

### 11.4 Adım adım

Hücrelerde $h+g$ yazılıdır; seçilen durum kalın gösterilmiştir (ekrandan, 01:55:00 ve 02:05:00).

1. $t=1$: Başlangıç durumu kuyruğa atılır: S, $11+0$. 11, S'nin hedefe tahmini uzaklığıdır; 0, kök kendisi olduğu için S'den S'ye uzaklıktır. Kuyrukta yalnız S vardır ve çekilir.
2. $t=2$: S'den A ve D'ye gidilebilir: SA $10.4+3$, SD $8.9+4$. 10.4 A'nın, 8.9 D'nin G'ye tahmini uzaklığıdır; 3 ve 4 S'den A'ya ve D'ye gitmenin maliyetleridir. $13.4 > 12.9$ olduğu için SD seçilir.
3. $t=3$: D'den S'ye geri dönülebilir, A'ya ya da E'ye gidilebilir: SDS $11+8$, SDA $10.4+9$, SDE $6.9+9$. SA zaten dizide kalır. Yeni durumları başa ya da sona eklemek A* için fark etmez, çünkü A* sıraya göre değil $f$'ye göre seçer; kolaylık olsun diye sona eklenmiştir. SDS'deki S ile baştaki S farklıdır: biri $11+0$, öteki $11+8$; 8, S'den D'ye ve D'den tekrar S'ye gitmenin maliyetidir. Bu bir döngüdür ve eklense de açılmayacağı umulur. Dört eleman arasından en küçük SA ($13.4$) seçilir.
4. $t=4$: SA'dan S, D ve B'ye gidilebilir: SAS $11+6$, SAD $8.9+8$, SAB $6.7+7$. Altı eleman arasından en küçük SAB ($13.7$) seçilir.
5. $t=5$: B'den A'ya dönülebilir, E'ye ya da C'ye gidilebilir: SABA $10.4+11$, SABE $6.9+8$, SABC $4+11$. Sekiz eleman arasından en küçük SABE ($14.9$) seçilir.
6. $t=6$: E'den D'ye, B'ye ya da F'ye gidilebilir: SABED $8.9+13$, SABEB $6.7+9$, SABEF $3+12$. On eleman vardır. SABC ($4+11=15$) seçilir.
7. $t=7$: C'den yalnız geri dönüş vardır: SABCB $6.7+15$. Şimdi SABEF ($3+12=15$) seçilir.
8. $t=8$: F'den E'ye dönülebilir ya da G'ye gidilebilir: SABEFE $6.9+16$, SABEFG $0+15$. En küçük SABEFG ($15$) seçilir. G hedef olduğu için arama biter.

Durumun içinde yol tutulduğu için hedef çekildiği anda yol da eldedir: S-A-B-E-F-G, maliyet $3+4+1+4+3 = 15$. Bu yol kullanıcıya çözüm olarak döndürülür. (Çekilme sırası ve yol python ile kontrol edildi; bu grafikte düşük maliyetli arama da aynı 15'lik yolu bulur.) Hoca bu tür problemleri kendiniz tanımlayıp disiplinli bir şekilde elle çözmenizi önerdi.

### 11.5 Eşit değerler ve kuyruk yapısı

**Soru:** C noktasından geri dönülüyor ve SABCB 15'ti. Bu değer 15'ten küçük, örneğin 14 olsaydı, G bulunmadığı halde yine onu mu alacaktık? İçinde döngü olabilir.
**Cevap:** Çekebilir; bu çok büyük bir sorun değildir. Hoca bunun üzerine SABC ile SABEF'in ikisinin de 15 olduğunu gösterip neden SABC'nin seçildiğini sordu. Öğrenciler daha uzun yol olduğunu, önceki seçimin dalından geldiğini ya da önce görüldüğünü tahmin etti. Cevap: rastgele. İki durum aynı değere sahipse hangisinin daha iyi bir yere götüreceğine dair hiçbir bilgi yoktur; ikisi de 15'tir. Yapılacak tek şey rastgele seçimdir.

**Soru:** Her seferinde en düşük maliyetliyi kuyruğun içinde arayarak mı buluyoruz?
**Cevap:** Ya kuyruk sürekli sıralı tutulur, ya da her ekleme sonrası en küçüğü aranır. Her seferinde sıralamanın maliyeti yüksektir. Bunun yerine heap yapısı kullanmak iyi bir yoldur: heap sıralamadaki (heapsort) gibi en küçük eleman hep en baştadır ve doğrudan çekilir. İçeride ayrıca arama yapmaya gerek kalmaz; heap'i güncellemek gerekir, ama bunun maliyeti logaritmiktir (iki tabanında).

Bir öğrenci, en küçük aranırken aynı noktaya gelen daha maliyetli kopyaların da elenebileceğini söyledi. Hoca bunların genelde implementasyon konusu olduğunu, kuyruğun heap ile tutulduğunu yineledi.

### 11.6 Bir soru slaytı

Hoca bir sonraki slayttaki soruyu deneme için bıraktı: verilen labirentlerde A*, ilk en iyi arama, düşük maliyetli arama, enlemesine ve derinlemesine arama nereleri dener ve nasıl yollar bulur? Bunu elle ya da kod yazarak deneyebilirsiniz. (Soru "Örnek Sorular" bölümündedir.)

### 11.7 İki slayt arasındaki fark

Arada bir öğrenci, bir önceki slayttaki A* yolu ile tablodaki A* yolunun farklı olduğunu sordu. Hoca önceki slayta bakınca A*'ın orada $13+0$ ile G'ye ulaştığını gördü. Öğrenciler iki grafta maliyetlerin farklı olduğunu belirtti (birinde B ile E arası 1 alınmış). Hoca iki problemin aynı olmadığını, aynı problem olsaydı daha uzun bir çözümün bulunmaması gerektiğini söyledi: tablodaki yol 15, öbür slayttaki 13'tür ve maliyetler farklıdır.

## 12. A*'ın Optimalliğinin İspatı

### 12.1 Ne gösterilecek?

Şimdiye kadar A*'ın optimal olduğu söylendi ve örneklerde optimal çözümü bulduğu görüldü. Şart da söylendi: $h$ iyimser olmalıdır. Şimdi bunun neden yettiği gösterilir.

Slayttaki şekilde bir başlangıç durumu, bir $n$ durumu, bir $G$ ve bir $G_2$ vardır (ekrandan, 02:20:00):

- $G$ optimal, $G_2$ suboptimal (optimal olmayan) bir çözüm olsun.
- Yığında (dizide) $n$ (optimal yola götüren seçim) ve $G_2$ var.
- A*, $G_2$'yi $n$'den önce açar mı (yığından çeker mi)?
- Eğer $f(n) < f(G_2)$ olduğunu gösterirsek $n$, $G_2$'den önce seçilir.

A* $n$ varken $G_2$'yi seçerse optimal değildir. Bu yüzden her zaman $n$'in seçileceğini garanti etmek gerekir. Gösterilmesi gereken eşitsizlik kesin olmalıdır:

> **Hocanın vurgusu:** $f(n) \le f(G_2)$ değil, $f(n) < f(G_2)$ gösterilmelidir. Eşitlik durumunda seçim rastgele olduğu için $n$ yerine $G_2$ seçilebilir.

Slayttaki teorem: A* optimaldir, eğer $h$ gerçek maliyeti daha düşük tahmin ediyorsa (iyimserse) ve tüm maliyetler pozitifse. Maliyetlerin pozitif olması şartı bütün algoritmalarda vardır; negatif maliyetlerle hiçbir algoritma optimal çözümü bulamaz. Kritik kısım iyimserlik şartıdır.

### 12.2 İspat

Slayttaki satırlar ve gerekçeleri (ekrandan, 02:25:00):

| Satır | Gerekçe |
|---|---|
| $f(G_2) = g(G_2)$ | $h(G_2) = 0$ olduğundan |
| $f(G) = g(G)$ | $h(G) = 0$ olduğundan |
| $g(G_2) > g(G)$ | $G_2$ optimal değil |
| $f(G_2) > f(G)$ | $f(G_2)=g(G_2)+h(G_2)$ ve $f(G)=g(G)+h(G)$ |
| $h(n) \le h^*(n)$ | $h^*$ gerçek maliyet |
| $g(n) + h(n) \le g(n) + h^*(n)$ | iki tarafa da $g(n)$ ekle |
| $f(n) \le f(G)$ | $g(n)+h(n)=f(n)$ ve $g(n)+h^*(n)=f(G)$ |
| $f(n) < f(G_2)$ | $f(G_2) > f(G)$ olduğundan |

Hoca satırları tek tek açıkladı:

1. $G_2$ bir çözümdür, dolayısıyla hedefe tahmini uzaklığı $h(G_2) = 0$'dır. Bu yüzden $f(G_2) = g(G_2) + h(G_2) = g(G_2)$.
2. Aynı şekilde $f(G) = g(G)$.
3. $G_2$ optimal olmadığı için $g(G_2) > g(G)$ kesindir.
4. Sol tarafa $h(G_2)$, sağ tarafa $h(G)$ eklenirse (ikisi de 0) $f(G_2) > f(G)$ elde edilir. Bu bir kenarda durur.
5. $h(n)$ iyimser sezgidir. $h^*(n)$ ise gerçek maliyettir: $n$'den $G$'ye giden gerçek bir yol vardır (zaten bulunacak olan yol) ve bu yolun gerçek maliyeti $h^*(n)$'dir. İyimserlik, $h(n)$'nin her zaman $h^*(n)$'den küçük ya da eşit olması demektir.
6. İki tarafa da $g(n)$ eklenir. $g(n) + h(n) = f(n)$'dir. $g(n) + h^*(n)$ ise başlangıçtan $n$'ye gelmenin gerçek maliyeti ile $n$'den $G$'ye gitmenin gerçek maliyetinin toplamıdır, yani $n$'den geçen bütün yolun maliyetidir: $f(G)$. Böylece $f(n) \le f(G)$.
7. $f(G_2) > f(G)$ bilindiği için sağ taraftaki $f(G)$ yerine ondan daha büyük olan $f(G_2)$ yazılabilir ve eşitsizlik kesinleşir: $f(n) < f(G_2)$.

Gösterilmek istenen buydu. Optimal olmayan bir çözüm ve optimal çözüme götüren bir durum aynı anda kuyruktayken A* her zaman optimale götüren durumu açar. Bunu sağlayan satır $h(n) \le h^*(n)$ satırıdır. Bu satır tersine dönerse, yani $h$ kötümser olursa, $f(n) \le f(G)$ yazılamaz ve A* $G_2$'yi seçebilir. Bu yüzden sezginin mutlaka iyimser olması gerekir.

### 12.3 Aşırı iyimserlik

Bu, ne kadar iyimser o kadar iyi demek değildir; iyimserler arasında daha kötümser olan daha iyiydi. Hoca bir düşünce deneyi yaptı: aşırı derecede iyimser bir sezgi, her durumun hedefe tahmini uzaklığını aynı varsayar. Algoritma hâlâ optimal çözümü bulur mu?

$f(n) = g(n) + h(n)$'dir ve bütün $h$'ler eşitse algoritma yalnız $g(n)$'ye göre çalışır. Bir öğrenci bulamayacağını söyledi; hoca düzeltti: yalnız $g$'ye göre çalışan algoritma düşük maliyetli aramadır ($f(n) = g(n)$) ve optimaldir. Bütün $h$'ler çok iyimser olsa da (hepsi tek adımda oraya varacağını tahmin etse de) A* düşük maliyetli aramaya dönüşür. Optimalliğinden bir şey kaybetmez, ama **hızını** kaybeder; çünkü hangi durumun daha yakın, hangisinin daha uzak olduğunu ayırt edemez. İyimser olup gerçeğe daha yakın bir sezgi seçmek çözümü bulma hızını oldukça artırır.

## 13. İkinci Graf Üzerinde Karşılaştırma

Son olarak `my_search.m` benzeri başka bir graf üzerinde aynı algoritmaların sonuçlarına bakıldı. Hoca yine önce yalnız yollara bakarak soruları sordu. Enlemesine aramanın yolu düşük maliyetli aramanınkinden iyi olamaz, çünkü optimal bir algoritma değildir. Düşük maliyetli aramanın yolundan daha iyi bir yol bulunamaz. Aynısı A* için de söylenebilir. A* ve düşük maliyetli aramanın yolları optimal olduğundan emin olunan iki yoldur. Burada ikisi aynı yolu bulmuştur; farklı da olabilirlerdi, çünkü birden fazla optimal yol olabilir. Enlemesine aramanın ve ilk en iyi aramanın yollarından daha iyi bir yol ise olabilir, çünkü bu algoritmalar optimal değildir.

Grafikteki sonuçlar (hocanın okuduğu değerler): derinlemesine arama 518'lik, enlemesine arama 153'lük, ilk en iyi arama 153'lük bir yol bulmuştur. Optimal yolu düşük maliyetli arama ve A* bulmuştur. <!-- BELİRSİZ: Optimal yolun maliyeti altyazıda "%22 kilometre" olarak geçiyor (02:31:41); bu ana ait kare yok, değer doğrulanamadı. --> Adım sayıları: A* 7, ilk en iyi arama 4, düşük maliyetli arama 14, enlemesine arama 10, derinlemesine arama 10. En fazla adımı düşük maliyetli arama atmış ve bu yüzden hafıza gereksinimi de artmıştır. İlk en iyi arama en az adımda biter, ama çok aceleci bir algoritmadır: hedefe yakın bir şey görünce hemen oraya atlar ve optimal yolu bulamaz.

Hoca A*'ın bir uygulaması olan "robotlarla keşif" konusunu (birden fazla robotun bir ortamı taraması) sonraki derse bıraktı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:42): Aynı problem için enlemesine arama, düşük maliyetli arama ve derinlemesine aramanın bulduğu yollar veriliyor. Grafa bakmadan şu sorulara cevap verin: Enlemesine aramanın yolu düşük maliyetli aramanınkinden daha iyi olabilir mi? Düşük maliyetli aramanın yolu enlemesine aramanınkinden daha iyi olabilir mi?

> **Çözüm (derste verildi):** Enlemesine aramanın yolu düşük maliyetli aramanınkinden daha iyi olamaz; en iyi ihtimalle eşit olur. Düşük maliyetli aramanın yolu daha iyi olabilir, çünkü düşük maliyetli arama maliyetler farklı olsa bile optimaldir. Derinlemesine aramanın yolunun kalitesi şansa bağlıdır; düşük maliyetli aramadan daha iyi olamaz.

**Soru 2** (derste sözlü, 00:34:38): Yalnız şehirler arası yol uzunlukları biliniyorsa (kuş uçuşu mesafeler yoksa) Arad'dan Bükreş'e en kısa yolu hangi kör algoritma optimal olarak bulur? Sezgisel arama bu yoldan daha iyi bir yol bulabilir mi?

> **Çözüm (derste verildi):** Düşük maliyetli arama; maliyetler farklı olsa da optimaldir. Sezgisel arama daha iyi bir yol bulamaz, aynı maliyetteki yolu çok daha kısa sürede (ve daha az hafızayla) bulur.

**Soru 3** (ekrandan, 00:40:00 ve 00:55:00): Romanya haritasında Arad'dan Bükreş'e ilk en iyi arama ve A* ile hangi yollar bulunur? Her adımda kuyrukta kaç eleman vardır?

> **Çözüm (derste verildi):** İlk en iyi arama: Arad (366) → Sibiu (253) → Fagaras (176) → Bükreş (0); yol uzunluğu 450, optimal değil. Kuyruk boyutları açılımlardan sonra 3, 6, 7. A*: Arad $366$ → Sibiu $393=140+253$ → Rimnicu Vilcea $413=220+193$ → Fagaras $415=239+176$ → Pitesti $417=317+100$ → Bükreş $418=418+0$; yol Arad-Sibiu-Rimnicu Vilcea-Pitesti-Bükreş, maliyet 418, optimal. Kuyruk boyutları açılımlardan sonra 3, 6, 8, 9, 11. (python ile kontrol edildi)

**Soru 4** (derste sözlü, 00:52:47): A* örneğinde iki Sibiu'nun altında 591 ve 553 yazıyor. İlk en iyi arama kullanılsaydı iki Sibiu'nun altında ne yazardı?

> **Çözüm (derste verildi):** İkisinin altında da 253 yazardı. İlk en iyi arama yalnız durumun hedefe tahmini uzaklığına bakar, hangi yoldan gelindiğini kullanmaz.

**Soru 5** (ekrandan, 01:35:00): Başlangıç durumu 7 2 4 / 5 _ 6 / 8 3 1 ve hedef durumu _ 1 2 / 3 4 5 / 6 7 8 olan 8 taş problemi için $h_1(S)$ (yerinde olmayan taş sayısı) ve $h_2(S)$ (Manhattan uzaklıkları toplamı) nedir?

> **Çözüm (derste verildi):** $h_1(S) = 8$ (yerinde olan hiç taş yok). $h_2(S) = 3+1+2+2+2+3+3+2 = 18$. (python ile kontrol edildi)

**Soru 6** (derste sözlü, 01:36:45): $h_1$ ve $h_2$ iyimser midir? Hangisi daha iyimserdir? $h_2$ her durumda $h_1$'den büyük ya da eşit midir?

> **Çözüm (derste verildi):** İkisi de iyimserdir: $h_1$ taşlar ışınlanabiliyormuş, $h_2$ arada engel yokmuş gibi hesaplar; ikisi de gerçek hamle sayısından fazlasını söylemez. $h_1$ daha iyimserdir. $h_1 = k$ ise $h_2$'de her biri en az 1 olan $k$ sayı toplanır; bu yüzden her durumda $h_2 \ge h_1$'dir. $h_2$ baskındır ve arama için daha uygundur.

**Soru 7** (derste sözlü, 01:44:18): 8 taş için $d=12$'de IDS, A*($h_1$) ve A*($h_2$) çözüm bulur. Bu çözümler optimal midir? Üçünün bulduğu çözümlerde kesinlikle aynı olan nedir?

> **Çözüm (derste verildi):** 8 taşta her hamlenin maliyeti eşit olduğu için IDS optimaldir; $h_1$ ve $h_2$ iyimser olduğu için A*'ın iki sürümü de optimaldir. Yollar farklı olabilir, ama maliyetleri ve dolayısıyla uzunlukları (adım sayıları) aynıdır.

**Soru 8** (derste sözlü, 01:47:01): Karşılaştırma tablosunda neden enlemesine arama yerine IDS kullanılmıştır?

> **Çözüm (derste verildi):** Enlemesine arama IDS'in çektiği düğüm sayısını en fazla yarıya indirebilir. Ama o kadar düğümü hafızada tutmak gerekir; $d=24$ gibi derinliklerde hiçbir bellek yetmez. Sorun hafızadır.

**Soru 9** (derste sözlü, 01:51:21): Yedi gözlü bir dizinin soldaki üç gözünde siyah (B), sonraki üç gözünde beyaz (W) taş vardır. Bir taş yanındaki taşın diğer yanı boşsa onun üzerinden atlayabilir (maliyet 2) ya da yanındaki boş yere gidebilir (maliyet 1). Hedef tüm beyazların siyahların solunda olmasıdır. Bu problem için $h$ önerileri neler olabilir? <!-- BELİRSİZ: Slaytın karesi yok; başlangıçta boş gözün en sağda olduğu altyazıdan çıkarıldı. -->

> **Çözüm (derste verilmedi):** Kayma hamlesi taşların birbirine göre sırasını değiştirmez. Atlama hamlesi ise yalnız bir taşın üzerinden geçtiği için sıradaki "siyahın sağında kalan beyaz" çiftlerinin sayısını (ters sıralı çift sayısını) en fazla 1 azaltır ve maliyeti 2'dir. Bu yüzden $h_a(n) = 2 \times (\text{bir siyahın sağında kalan beyaz–siyah çiftlerinin sayısı})$ iyimserdir. Daha basit bir öneri, solunda en az bir siyah bulunan beyaz taşların sayısıdır ($h_b$); bu da iyimserdir, ama $h_a \ge h_b$ olduğu için $h_a$ baskındır. Başlangıç BBBWWW_ için $h_a = 2 \times 9 = 18$, $h_b = 3$; gerçek en küçük maliyet 24'tür. İki kuralın 140 durumun hepsinde gerçek maliyeti aşmadığı python ile (tüm durumlar üzerinde Dijkstra) kontrol edildi.

**Soru 10** (ekrandan, 01:55:00): Aşağıdaki grafta S'den G'ye A* aramayı, dizinin içeriğini her adımda göstererek çalıştırın. Kenarlar: S-A 3, S-D 4, A-B 4, A-D 5, B-C 4, B-E 1, D-E 5, E-F 4, F-G 3. $h$: S 11.0, A 10.4, B 6.7, C 4.0, D 8.9, E 6.9, F 3.0, G 0.

> **Çözüm (derste verildi):** Çekilme sırası (değerler $h+g$): S $11+0$; SD $8.9+4$; SA $10.4+3$; SAB $6.7+7$; SABE $6.9+8$; SABC $4+11$; SABEF $3+12$; SABEFG $0+15$. SABC ile SABEF eşit (15) olduğu için aralarındaki seçim rastgeledir. Bulunan yol S-A-B-E-F-G, maliyet 15. Adımların tam dizi içeriği 11.4 bölümündedir. (python ile kontrol edildi)

**Soru 11** (derste sözlü, 02:09:11; slayt "Bir Soru"): Verilen labirentlerde A*, ilk en iyi arama, düşük maliyetli arama, enlemesine ve derinlemesine arama nereleri dener? Nasıl yollar bulur? <!-- BELİRSİZ: Slayt yalnız küçük önizlemede göründü; labirent şekilleri okunamadı. Derste çözülmedi; şekil olmadan çözüm verilmedi. -->

**Soru 12** (derste sözlü, 02:28:20): Her durumun hedefe tahmini uzaklığını aynı kabul eden aşırı iyimser bir sezgiyle A* hâlâ optimal çözümü bulur mu?

> **Çözüm (derste verildi):** Bulur. Bütün $h$'ler eşitse seçim yalnız $g(n)$'ye göre yapılır ve A* düşük maliyetli aramaya dönüşür. Optimallik korunur, ama hız kaybedilir.

## Dersin Toparlaması

Bu derste kör arama algoritmalarının eksik kaldığı nokta, yani hedefe yakınlık bilgisini hiç kullanmamaları, sezgi kavramıyla giderildi. Sezgi $h(n)$, bir durumun hedefe tahmini uzaklığıdır. İlk en iyi arama yalnız $h(n)$'ye bakar. Hızlıdır ama açgözlüdür: Romanya haritasında 450'lik, labirentte uzun bir yol bulur; döngülere de takılabilir. A* ise kökten gelinen gerçek maliyeti de hesaba katar ($f = g + h$). Döngülere takılmaz ve $h$ iyimser olduğu sürece optimal çözümü bulur. Bunun nedeni ispatta görüldü: iyimser $h$ sayesinde optimal yola götüren durumun $f$ değeri, optimal olmayan bir hedefin $f$ değerinden kesin olarak küçüktür.

Sezgisel arama optimal algoritmalardan daha iyi çözüm bulmaz; aynı çözümü çok daha az adım ve hafızayla bulur. 8 taşta $d=12$ için IDS 3,6 milyon düğüm çekerken A*($h_2$) 73 düğüm çeker. İyimser kurallar arasında gerçeğe en yakın olan (baskın olan) seçilmelidir; esnetilmiş problemler bu tür kurallar üretmenin bir yoludur. Sonraki derste A*'ın robotlarla keşif uygulamasıyla başlanacak, ardından lokal arama algoritmalarına geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
