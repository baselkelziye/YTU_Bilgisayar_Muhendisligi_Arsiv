# Ders 11 Genişletilmiş Notu: BFS ve DFS, Prim ve Kruskal, Karar Ağaçları, Graf Türleri, Euler ve Hamilton Döngüleri ve Dijkstra Algoritması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İkili Arama Ağacı ve Dengeli Ağaç
- 2. BFS ve DFS ile Izgarada Kör Arama
- 3. Minimum Kapsayan Ağaç ve Prim Algoritması
- 4. Kruskal Algoritması
- 5. Karar Ağaçları
- 6. Entropi ve Bilgi Kazancı
- 7. Ağaçlarda İzomorfizm
- 8. Graflara Giriş
- 9. Graf Türleri
- 10. Graflarla Benzerlik Uygulaması
- 11. Özel Graflar
- 12. İki Parçalı Graflar
- 13. Yollar, Döngüler ve Euler Döngüsü
- 14. Düğüm Dereceleri ve El Sıkışma Teoremi
- 15. Hamilton Döngüsü
- 16. Grafların Bilgisayarda Gösterimi
- 17. Yollar, Bağlılık ve Yol Sayımı
- 18. Dijkstra En Kısa Yol Algoritması
- 19. Graf Modelleri, Düzlemsel Graf, Graf İzomorfizmi ve Ağ Topolojileri

## 1. İkili Arama Ağacı ve Dengeli Ağaç

Ders, bir önceki derste ağaçlar konusunda kalınan yerden başladı. Konu sırası şöyleydi: ağaçlar, köklü ağaçlar, ikili ağaçlar ve ikili ağaçlardan sonra ikili arama ağacı (binary search tree).

İkili arama ağacının kuralı basittir. Eklenecek yeni düğüm, bulunduğu düğümün değerinden büyükse sağa, küçük ya da eşitse sola gider. Eşitlik iki taraftan birine konabilir; bu bir tercih meselesidir. Örneğin kökte 10 varsa 9 sola, 12 sağa gider. Bu, ikili arama algoritması gibi düşünülür: her adımda ağacın yarısı elenir.

Ekrandaki örnekte "Binary Search Tree Oluşturma" başlıklı slayt ve 1, 3, 4, 5, 6, 10, 16, 17, 19 dizisi vardı (ekrandan, 00:15:00). Hoca, slayttaki örneğin aslında dengeli bir ağaç kurmaya dayandığını, bu yüzden başlığın yanıltıcı olduğunu söyledi. Normal ekleme kuralında ilk gelen eleman köktür ve bir daha değişmez. 1 köke oturur, 3 daha büyük olduğu için sağına, 4 hem 1'den hem 3'ten büyük olduğu için 3'ün sağına gider. Dizi artan sırada olduğu için ağaç tek kollu, dengesiz bir yapıya döner. Bu ağaç doğrusal bir bağlı liste gibidir ve ikili aramanın avantajı kaybolur.

Bu dengesizliği gidermek için ağaç döndürülür (rotate edilir). 1, 3, 4 geldiğinde en uygun seçenek 3'ü kök yapmaktır: kök işaretçisi değiştirilir, 1 sola, 4 sağa gelir. Böylece ağaç yine ikili arama ağacı kuralına uyar. Sonra 5 gelir ve en sağa eklenir. 6 gelince 4, 5, 6 alt ağacı yine dengesiz olur ve kendi içinde dengelenir: 5 alt ağacın köküdür, 4 solunda, 6 sağındadır. Elemanlar gelmeye devam ettikçe ağaç bir kez daha dengelenir; düğümlerin hemen hemen aynı seviyede olması için 4 kök yapılır. 10 ve 16 eklenince ağaç yeniden dengesiz olur ve kök tekrar güncellenir.

Slayttaki animasyonda kök güncellenirken genelde sağ alt ağacın en soldaki düğümü kök yapılıyor. Hoca bunun kesin bir kural olmadığını vurguladı. Asıl mesaj şudur:

> **Hocanın vurgusu:** Ağaçlar oluşturuldukları gibi saklanmak zorunda değildir. Dönüştürülerek daha düzenli ve veriyi daha verimli saklayan bir hale getirilebilirler.

Hoca daha sonra kapsayan ağaç (spanning tree), genişlik öncelikli arama (BFS) ve derinlik öncelikli arama (DFS) konularını hatırlattı. BFS kuyruk (queue), DFS yığın (stack) kullanır.

## 2. BFS ve DFS ile Izgarada Kör Arama

Hoca BFS ve DFS'yi farklı bir örnekle göstermek için tahtaya bir ızgara çizdi (ekrandan, 00:25:00). Izgaranın satırları 0'dan 4'e, sütunları 0'dan 5'e numaralıdır. Bir robot (2, 1) konumundadır ve (1, 4) konumundaki hedefe gitmek istemektedir. Konumlar (satır, sütun) olarak yazılır ve kuyruğa ya da yığına bu koordinat çiftleri eklenir.

Arama yönleri için bir kural belirlendi. Bu kural istenildiği gibi seçilebilir:

- 1: sağ
- 2: yukarı
- 3: sol
- 4: aşağı

Komşuluk sekiz yönlü değil, dört yönlüdür. Her iki algoritma da hedef hakkında hiçbir bilgi kullanmaz. Bu yüzden bunlara kör arama algoritmaları (blind search) denir.

### 2.1 BFS: Kuyrukla Arama

BFS'de bulunulan düğümün önce bütün komşuları kural sırasıyla kuyruğa eklenir, sonra düğüm ziyaret edildi (visited) olarak işaretlenir ve kuyruğun başındaki düğüme geçilir. Daha önce kuyruğa eklenmiş ya da ziyaret edilmiş bir konum tekrar eklenmez. Hoca bunun için şöyle bir gösterim önerdi: kuyruğa eklenen yere önce $-1$, ziyaret edilince $+1$ yazılabilir.

Adımlar şöyledir:

1. (2, 1) kuyruktadır. Komşuları sağ (2, 2), yukarı (1, 1), sol (2, 0), aşağı (3, 1) sırasıyla kuyruğa eklenir. (2, 1) ziyaret edildi.
2. (2, 2)'ye gidilir. Hedef değildir. Gezilmemiş komşuları (2, 3), (1, 2), (3, 2) eklenir. (2, 1) zaten ziyaret edildiği için eklenmez.
3. (1, 1)'e gidilir. (1, 2) zaten eklenmiştir. (0, 1) ve (1, 0) eklenir.
4. (2, 0)'a gidilir. Sağ ve üst komşular eklenmiştir. Alttaki (3, 0) eklenir. Solunda komşu yoktur.
5. (3, 1)'e gidilir. (3, 2) ve (3, 0) eklenmiştir. (4, 1) eklenir.

Bu noktada başlangıç noktasının çevresindeki ilk halka tamamlanmış olur. Sonra (2, 3) ziyaret edilir ve (2, 4), (1, 3), (3, 3) eklenir. (1, 2), (3, 2), (0, 1), (1, 0), (3, 0), (4, 1) ziyaret edildikçe (0, 2), (4, 2), (0, 0), (4, 0) gibi yeni konumlar eklenir. (2, 4)'e gelindiğinde (2, 5), hedef olan (1, 4) ve (3, 4) kuyruğa girer. Arama böylece halka halka genişler. Hoca örneği uzatmamak için burada kesti.

> **Ders sonrası not:** Aynı kurallarla python'da yapılan benzetimde ziyaret sırası (2, 1), (2, 2), (1, 1), (2, 0), (3, 1), (2, 3), (1, 2), (3, 2), (0, 1), (1, 0), (3, 0), (4, 1), (2, 4), (1, 3), (3, 3), (0, 2), (4, 2), (0, 0), (4, 0), (2, 5), (1, 4) çıkar. Hedef 21. ziyarette bulunur (ara adım eklendi).

### 2.2 DFS: Yığınla Arama

DFS'de de aynı yön kuralı kullanılır. Hoca önce BFS'deki gibi bütün komşuları eklemeye başladı, sonra hatasını düzeltti: derinlemesine aramada her adımda kurala göre ilk uygun komşuya gidilir ve gidilebildiği kadar o yönde ilerlenir.

1. (2, 1)'den sağa: (2, 2), (2, 3), (2, 4), (2, 5). Sağda duvar vardır.
2. (2, 5)'ten sağa gidilemez, yukarı gidilir: (1, 5).
3. (1, 5)'ten sağa gidilemez, yukarı gidilir: (0, 5).
4. (0, 5)'ten sağa ve yukarı gidilemez, sola gidilir: (0, 4), (0, 3), (0, 2), (0, 1), (0, 0).
5. (0, 0)'dan sağa (ziyaret edildi), yukarı ve sola gidilemez, aşağı gidilir.

**Soru:** (2, 4)'e gelmişken robot yukarı çıksa hedefe ulaşmaz mı? **Cevap:** Algoritma yukarı çıkması gerektiğini bilmez. Kör bir aramadır, duvara toslayana kadar kural sırasıyla gider.

(1, 5)'teyken hedef hemen solundadır, ama kural yukarıyı sola öncelediği için robot (0, 5)'e çıkar. Hoca örneği (0, 0)'dan aşağı inilen adımda bıraktı.

> **Ders sonrası not:** Benzetime devam edilirse (0, 0)'dan sonra (1, 0), (1, 1), (1, 2), (1, 3) ve (1, 4) gelir. Hedef 17. adımda bulunur (ara adım eklendi).

## 3. Minimum Kapsayan Ağaç ve Prim Algoritması

Arama işlemleri bir ağaç ya da graf üzerinde yapılır. Bütün düğümleri içeren ve bir noktadan diğerine en ucuz şekilde gitmeyi sağlayan bir yapı istenirse minimum kapsayan ağaç (minimum spanning tree) kullanılır. Graftaki kenar ağırlıkları maliyetleri gösterir: süre, para, kullanılan bellek ya da başka bir maliyet olabilir.

Slayttaki tanım şudur (ekrandan, 00:35:00): verilen ağırlıklı bir $G$ grafının minimal kapsayan ağacı, $G$'nin bütün düğümlerinden geçen bir kapsayan ağaçtır ve ağırlıklar toplamı minimumdur.

Ağaç olmanın iki şartı vardır: kopukluk olmayacak ve çevrim (cycle) olmayacak. Hoca, şekildeki çizgilerin kesişmesinin çevrim gibi görünebileceğini, ama düğümler arasındaki bağlantılara bakıldığında çevrim olmadığını gösterdi. Bir grafın birçok kapsayan ağacı olabilir; amaç ağırlık toplamı en küçük olanı bulmaktır. Bunun için iki algoritma vardır: Prim ve Kruskal.

### 3.1 Prim Algoritmasının Mantığı

- Herhangi bir düğümden başlanır.
- Ziyaret edilen düğümleri ziyaret edilmeyen komşularına bağlayan en ucuz kenar seçilir.
- Her yeni ekleme çevrim oluşturmamalıdır. Çevrim oluşuyorsa gereksiz bir kenar eklenmiş demektir.
- Bütün düğümler ziyaret edilince durulur.

Hoca 7 düğümlü bir graf üzerinde 5. düğümden başlayarak sözlü bir örnek anlattı. 5'in komşularından en ucuzu 200 ile 6'dır. 6'dan 700'lük kenar seçilerek 4'e, 4'ten 1'e gidildi. 1'den 1000'lik kenar çevrim oluşturacağı için alınmadı; 100, 600, 400, 1100 arasından en küçük olan 100 ile 3 seçildi. 3'ün 5'e giden kenarı çevrim oluşturur. Sonra 400 ile 7, en son 1100 yerine 900 ile 2 seçildi.

> **Ders sonrası not:** Bu sözlü anlatımda 6'dan sonra 700'lük kenar seçildi, oysa o anda ağaçtaki düğümlerden çıkan en ucuz kenar 5-3 (500) idi. Prim kuralına göre 5'ten başlanınca seçilen kenarlar 5-6 (200), 5-3 (500), 3-1 (100), 1-4 (300), 1-7 (400), 7-2 (900) olur ve toplam 2400'dür. Sözlü anlatımdaki ağacın toplamı 2600'dür (python ile kontrol edildi).

### 3.2 Maliyet Matrisiyle Prim Örneği

Slayttaki örnekte düğümler arası mesafeler bir maliyet matrisiyle verildi (ekrandan, 00:40:00). M, iki düğüm arasında doğrudan bağlantı olmadığını (sonsuz, maksimum) gösterir. Her düğümün kendisine uzaklığı 0'dır.

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| 1 | 0 | 1100 | 100 | 300 | 600 | 1000 | 400 |
| 2 | 1100 | 0 | M | M | M | M | 900 |
| 3 | 100 | M | 0 | M | 500 | M | M |
| 4 | 300 | M | M | 0 | M | 700 | M |
| 5 | 600 | M | 500 | M | 0 | 200 | M |
| 6 | 1000 | M | M | 700 | 200 | 0 | 800 |
| 7 | 400 | 900 | M | M | M | 800 | 0 |

Örneğin 2 ile 3 arasında komşuluk yoktur, bu yüzden M yazılır. Algoritma 1. düğümden başlar:

1. 1'in en küçük kenarı 100'dür. 3 seçilir.
2. Ziyaret edilenler {1, 3}. 3'ün en küçük kenarı 500, 1'in kalan en küçük kenarı 300'dür. 300 seçilir ve 4 eklenir. Hoca, algoritmanın yalnız son düğüme değil önceki düğümlerin komşularına da baktığını vurguladı.
3. Ziyaret edilenler {1, 3, 4}. Adaylar 4'ten 700, 3'ten 500, 1'den 400'dür. 400 seçilir ve 7 eklenir.
4. Adaylar 1'den 1100 ve 600, 3'ten 500, 4'ten 700, 7'den 800 ve 900'dür. 500 seçilir ve 5 eklenir.
5. 5'ten 200'lük kenarla 6 eklenir. Her eklemede çevrim kontrolü yapılır.
6. Son olarak 900'lük kenarla 2 eklenir.

Seçilen kenarlar 1-3 (100), 1-4 (300), 1-7 (400), 3-5 (500), 5-6 (200), 7-2 (900) olup toplam maliyet 2400'dür (python ile doğrulandı). Hoca bu algoritmanın gerçeklemelerinin farklı olabileceğini, örnekteki gerçeklemede bir kuyruk mantığı bulunduğunu söyledi.

### 3.3 Şehir Örneği

Hoca, Japonya'daki şehirlerin bulunduğu bir graf üzerinde Prim'in nasıl ilerlediğini gösteren bir demo da açtı. Başlangıç düğümünden 85'lik kenar seçildi, sonra ziyaret edilen bütün düğümlerin komşuları karşılaştırılarak her adımda en küçük kenar alındı. Bütün şehirlere ulaşılınca algoritma durdu. Başlangıç düğümü değişirse algoritmanın ilerleme sırası da değişir.

<!-- BELİRSİZ: Prim demosunun ekranı karelerde görünmüyor; altyazıdaki ara değerler (12, 26, 39, 59, 61, 67, 30) şehir adlarıyla tam eşleştirilemedi. Aynı şehir grafı 02:45:00 karesinde görünüyor; o kenar ağırlıklarıyla Tokushima'dan başlayan Prim python ile 85, 19, 12, 26, 39, 30, 59, 61, 65, 31, 65, 67, 30 sırasıyla toplam 589 veriyor. -->

## 4. Kruskal Algoritması

Prim'de düğüm seçilir; Kruskal'da kenar seçilir. Kruskal'ın adımları şunlardır:

- Bütün kenarlar ağırlıklarına göre sıralanır.
- En küçük ağırlıklı kenar seçilir ve iki ucundaki düğüm işaretlenir. Kenarlar seçildikçe düğümler "torbadan çıkarılır".
- Kapalı çevrim oluşturmayacak şekilde bütün düğümler bağlanana kadar devam edilir.
- $n$ düğüm varsa $n-1$ kenar seçilir.

Kruskal'da herhangi bir düğümden başlanmaz, en küçük kenardan başlanır. Slayttaki örnekte (ekrandan, 00:45:00) önce 1'lik, sonra 2'lik kenarlar seçildi, ardından 3'lük kenarlara geçildi.

Hoca burada önemli bir durumu düzeltti. Bir kenarın iki ucu da daha önce ziyaret edilmiş olabilir. Bu iki düğüm arasında henüz bir bağlantı kurulmamışsa, yani iki düğüm farklı ağaçlardaysa kenar alınabilir. İki düğüm zaten aynı ağaçtaysa kenar kapalı çevrim oluşturur ve alınmaz.

Ara adımlarda birbirinden kopuk iki ya da daha fazla ağaç oluşabilir. Bu duruma orman (forest) denir. Ormandan çıkmak için ağaçlar uygun kenarlarla birbirine bağlanır. Örnekte 3'lük ve 4'lük kenarlardan çevrim oluşturmayanlar eklendi, çevrim oluşturanlar atlandı ve bütün düğümler bağlanınca ağaç tamamlandı.

Son olarak U0-U5 düğümlü bir Kruskal demosunda önce en küçük kenar, sonra U0-U1, U1-U3 kenarları eklendi. 15'lik kenar çevrim oluşturduğu için alınmadı ve U4-U5 ile bütün düğümlere ulaşıldı.

<!-- BELİRSİZ: Kruskal demosunun kenar ağırlıkları karelerde görünmüyor. -->

## 5. Karar Ağaçları

Karar ağaçları ağaçların bir uygulamasıdır. Bir akış şeması gibi düşünülebilir: bir koşul sağlanıyorsa bir dala, sağlanmıyorsa diğer dala gidilir. Makine öğrenmesi ve yapay zekada sınıflandırma algoritmalarında kullanılır. Örneğin hava güneşliyse, sıcaklık şöyleyse, nemliyse yağmur yağacak mı gibi tahminler karar ağaçlarıyla yapılır.

### 5.1 Beş Para Bulmacası

Slayttaki problem şudur (ekrandan, 00:50:00):

- Görünüşleri birbirinin aynı olan 5 paradan biri sahtedir.
- Sahte olan para diğerlerinden daha ağır veya daha hafif olabilir.
- Karar ağacını kullanarak hangi paranın sahte olduğuna karar veriniz.
- Sahte olan para diğerlerine göre hafif midir yoksa ağır mıdır?

Sahte paranın ağır olduğu bilinseydi eşit kollu terazide en ağırı bulmak yeterdi. Ancak hafif de olabileceği için karar ağacı gerekir. Paralar $C_1, \dots, C_5$ olsun. Ağaç şöyle kurulur:

- $C_1$ ile $C_2$ tartılır.
  - Bir taraf ağır basarsa sahte para bu ikisinden biridir. Bu durumda $C_1$, $C_5$ ile karşılaştırılır.
  - Eşitse $C_1$ ve $C_2$ kesinlikle gerçektir. Bu durumda $C_3$ ile $C_4$ tartılır ve sonuca göre bir karşılaştırma daha yapılır.

Ağacın sonunda hangi paranın sahte olduğu ve ağır mı hafif mi olduğu bulunur.

### 5.2 Tenis Örneği

Makine öğrenmesinden bir örnekte havanın durumuna göre bir kişinin tenis oynayıp oynamayacağı tahmin edilir. Elde 14 gözlem vardır. Özellikler hava görünümü (outlook: sunny, overcast, rain), sıcaklık (temperature), nem (humidity) ve rüzgardır (wind: weak, strong). Hoca 15. durum için hava sunny, sıcaklık mild, nem high, rüzgar weak olduğunda sonucun ne olacağını sordu.

Bu kararı verebilmek için önce karar ağacı inşa edilmelidir. Sonuç iki değerlidir: ağacın yaprakları ya "yes" ya da "no" gösterir. Ağaç ikili ya da üçlü olabilir; bu ayrıntı tartışılmadı. Hava görünümü gibi özellikler bağımsız değişken, "play tennis" bağımlı değişkendir. Sorulan şey, her bağımsız değişkenin "yes" ve "no" dağılımını ne kadar değiştirdiğidir.

Bir slaytta özelliklerden biri kök seçilerek kurulmuş bir ağaç gösterildi (ekrandan, 00:55:00). Bu ağaçta kök nemdir:

- humidity = high (1, 2, 3, 4, 8, 12, 14) → wind
  - weak (1, 3, 4, 8) → outlook: sunny (1, 8) [NO], overcast (3) [YES], rainy (4) [YES]
  - strong (2, 12, 14) → outlook: sunny (2) [NO], overcast (12) [YES], rainy (14) [NO]
- humidity = normal (5, 6, 7, 9, 10, 11, 13) → wind
  - weak (5, 9, 10, 13) → outlook: sunny (9) [YES], overcast (13) [YES], rainy (5, 10) [YES]
  - strong (6, 7, 11) → outlook: sunny (11) [YES], overcast (7) [YES], rainy (6) [NO]

Hoca bu ağaç üzerinde örnek bir yol izledi: nem yüksekse sol dala, rüzgar güçlüyse ilgili dala, hava görünümü bulutluysa (overcast) "oynanacak" sonucuna gidilir. Karar ağacı her zaman yüzde yüz başarı vermez; en iyi (optimum) çözümü verir ama kesin çözüm (exact solution) vermez.

## 6. Entropi ve Bilgi Kazancı

Ağacın kökünün hangi özellik olacağına karar vermek için bilginin saflığı incelenir. Bu, olasılıkta görülen dağılım (distribution) kavramıyla ilgilidir ve entropi ile ölçülür. Bir veri dağılımındaki bütün değerlerin frekansları eşitse düzgün (uniform) dağılım vardır. Böyle bir durumda hangi değerin sonucu etkilediğine karar verilemez. Amaç, diğerlerine göre çok daha ayırt edici olan özelliği sayısal olarak bulmaktır. Bunun için bilgi kazancı (information gain) kullanılır.

Entropi bir dağılımın ne kadar düzenli, ne kadar homojen olduğunu ölçer:

$$H(S) = -\sum_{i} p_i \log_2 p_i$$

Bütün örnekler aynı sınıftaysa entropi 0'dır. İki sınıf eşit dağılmışsa entropi 1'dir. Diğer durumlarda 0 ile 1 arasında bir değer çıkar. Örneğin 9 artı ve 5 eksi için entropi 0,940, 7 artı ve 7 eksi için 1'dir. Sınıfların sayıları birbirine yaklaştıkça entropi artar.

> **Ders sonrası not:** Hoca entropi bire yaklaştıkça bilgi saflığının arttığını söyledi. Doğrusu tersidir: entropi 0 iken dağılım saftır (bütün örnekler aynı sınıfta), 1'e yaklaştıkça karışıklık artar.

### 6.1 Rüzgar Özelliğinin Bilgi Kazancı

Tenis örneğinde sonuç sütununda 9 "yes" ve 5 "no" vardır:

$$H(S) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} = 0{,}940$$

Rüzgar özelliğinde weak değeri 8 örnekte (6 yes, 2 no), strong değeri 6 örnekte (3 yes, 3 no) görülür:

$$H(S_{weak}) = -\frac{6}{8}\log_2\frac{6}{8} - \frac{2}{8}\log_2\frac{2}{8} = 0{,}811$$

$$H(S_{strong}) = -\frac{3}{6}\log_2\frac{3}{6} - \frac{3}{6}\log_2\frac{3}{6} = 1$$

Bilgi kazancı formülü şudur:

$$Gain(S, A) = H(S) - \sum_{v} \frac{|S_v|}{|S|} H(S_v)$$

Rüzgar için:

$$Gain(S, wind) = 0{,}940 - \frac{8}{14} \cdot 0{,}811 - \frac{6}{14} \cdot 1 = 0{,}048$$

Aynı hesap nem, sıcaklık ve hava görünümü için de yapılır. Hangisinin kazancı en yüksekse o en ayırt edici özelliktir. Hava görünümünün kazancı 0,246 ile en yüksek çıktığı için kök düğüm hava görünümü olur (değerler python ile doğrulandı).

Kökün alt dalları sunny, overcast ve rain'dir. Alt düğümler de aynı yöntemle bulunur ve bütün dallarda yapraklara ulaşılana kadar işlem tekrarlanır. Hoca sunny dalının altına nem (humidity) özelliğinin geldiğini gösterdi ve slaytta bu kısımda bir hata olduğunu söyledi. Kurulan son ağaçta, örneğin hava görünümü sunny ve nem normal olan yeni bir durum için "yes" denebilir.

<!-- BELİRSİZ: Son ağacın tamamı ve hocanın slaytta gördüğü hata karelerde görünmüyor. -->

## 7. Ağaçlarda İzomorfizm

İki ağacın bazı ortak özelliklere sahip olmasına izomorfizm (benzerlik) denir. Aynı kavram graflarda da görülecektir. Slayttaki tanım şudur (ekrandan, 01:00:00): verilen iki ağaç $T_1$ ve $T_2$ için birebir ve örten bir $f: T_1 \to T_2$ fonksiyonu varsa $T_1$ ve $T_2$ izomorfiktir; yani birbirlerine çok yakındırlar. Fonksiyonlardaki birebir ve örten özellikleri burada düğümler (vertex) üzerinde aranır. Örneğin iki ağaçta da 5 düğüm olması bir şarttır.

İzomorfizm üç seviyede düşünülür. Genel ağaçlardaki izomorfizmin alt kümesi köklü ağaçlardaki izomorfizm, onun alt kümesi de ikili ağaçlardaki izomorfizmdir. Slayttaki bir örnekte iki ağaç köklü ağaç olarak izomorfikti, ama ikili ağaç olarak izomorfik değildi; çünkü ikili ağaçta çocuğun sol mu sağ mı olduğu önemlidir.

İzomorfik olmadığını göstermek, izomorfik olduğunu göstermekten daha kolaydır. Bakılacak kurallar:

- Düğüm sayıları aynı mı?
- Kenar sayıları aynı mı?
- Karşılıklı düğümlerin dereceleri aynı mı?
- Kökten köke bir eşleme yapılabiliyor mu?
- Çocukların konumları (derinlik, yükseklik) aynı mı?

Bu kurallardan biri bozuluyorsa ağaçlar izomorfik değildir denip geçilir. Slayttaki dört ağacın her birinde 4 düğüm ve 3 kenar vardı. Köklü ağaç olarak bakıldığında izomorfik değillerdi, çünkü bazı düğümlerin derinliği 2, diğerlerininki 1'di. Köklü ağaç olarak değil de genel ağaç olarak bakılsaydı birinci ile ikinci ağaç, üçüncü ile dördüncü ağaç izomorfik olacaktı.

İkili ağaçlarda $n$ düğümlü, birbiriyle izomorfik olmayan ikili ağaç sayısı şudur ($n > 0$):

$$\frac{1}{n+1}\binom{2n}{n}$$

Slaytta birbiriyle izomorfik olmayan ikili ağaçlar gösterildi.

<!-- BELİRSİZ: Hoca bu ağaçlar için "üç tane kenar olan ağaçlar" dedi; slayttaki ağaçların düğüm sayısı karelerde görünmüyor. Formül $n=3$ düğüm için 5 verir. -->

## 8. Graflara Giriş

Hoca, son kapsamlı bölüm olarak graf teorisine geçti. Bu bir giriş dersi olduğu için konuların ayrıntıları veri yapıları ve algoritma analizi derslerinde görülecektir. Bağıntılar konusunda bağıntıların graflarla gösterilebileceği söylenmişti; burada da aynı bağlantı kurulur.

Bir $G$ grafı, boş olmayan bir $V$ köşe (düğüm, node) kümesinden ve bir $E$ kenar kümesinden oluşur. Her kenarın uç nokta denen bir ya da iki köşesi vardır. Kenar, iki köşeyi birbirine bağlayan ve aralarındaki ilişkiyi gösteren elemandır. A'dan B'ye bir bağıntı varsa bu bağıntıyı gösteren şey kenardır.

Graflar bilgisayar bilimlerinde benzerlik, farklılık, alt-üst ilişkisi gibi birçok uygulamada kullanılır. En basit örnek en kısa yol problemidir: A şehrinden B şehrine en kısa yolu algoritmayla hesaplamak için yollar ve şehirler bir grafla temsil edilir. Slaytta 4 köşeli, 5 kenarlı bir graf gösterildi. Bir örnekte X ile V arasında iki ayrı kenar vardı. Bu, iki şehir arasında birden fazla yol olduğunu ya da iki kişi arasında iki farklı akrabalık ilişkisi bulunduğunu gösterebilir. Hoca buna bir kişinin teyzesinin kızıyla evlenmesini örnek verdi: kişinin kardeşi ile bu eş arasında hem teyze çocukluğu hem de evlilik yoluyla bir akrabalık oluşur.

Kenarla ilgili temel kavramlar:

- **Kenar:** bir düğüm çiftiyle etiketlenen ve ilişki gösteren öğe.
- **Ayrık düğüm (isolated vertex):** hiçbir kenarı olmayan düğüm. Bu düğümün diğerleriyle hiçbir ilişkisi yoktur.
- **Paralel kenar:** iki ya da daha fazla kenar aynı düğüm çiftine bağlıysa bu kenarlara paralel kenar denir. Slayttaki örnekte A ile B arasındaki ve A ile D arasındaki ikişer kenar buna örnektir.
- **Döngü (loop):** başlangıç ve bitiş noktası aynı olan kenar.

**Soru:** Döngü bağıntıların hangi özelliğini gösterir? Bir öğrenci simetri olabileceğini söyledi. **Cevap:** Simetri, A'dan B'ye ilişki varsa B'den A'ya da olmasıdır. Döngü ise A'dan A'ya bir ilişkidir, yani yansıma (refleksif) özelliğini gösterir. Simetriyi görebilmek için kenarlara yön anlamı eklenmelidir; bağıntılar genellikle yönlü graflarla (digraf) gösterilir.

## 9. Graf Türleri

### 9.1 Basit, Çoklu ve Pseudo Graflar

- **Basit graf (simple graph):** yönsüz, paralel kenarı olmayan ve döngü içermeyen graftır.
- **Çoklu graf (multigraph):** basit kenarların yeterli olmadığı durumlarda kullanılır. Yönsüzdür, paralel kenarı vardır, döngü içermez. Hoca slayttaki bir ifadeyi derste düzeltti: çoklu graf döngü içermez.
- **Pseudo graf:** çoklu grafların yeterli olmadığı durumlarda kullanılır. Yönsüzdür, paralel kenarı vardır ve döngü içerir (ekrandan, 01:25:00). Yönsüz grafların en genel halidir.

Slayttaki ifadeye göre basit graflar çoklu graftır, ama çoklu graflar basit graf değildir.

**Soru:** Önceki slayttaki paralel kenar tam olarak ne demek, yukarıdaki şekilde V5, V1, V2, V4 arasında da paralel kenar var gibi görünüyor? **Cevap:** İki köşe arasında birden fazla kenar varsa bunlar paralel kenardır. Şekildeki diğer köşe çiftleri arasında böyle bir durum yoktur; yalnız bir çiftte vardır.

### 9.2 Ağırlıklı Graf

Ağırlıklı grafta her kenara sayısal bir değer (ağırlık) verilir (ekrandan, 01:25:00). Örneğin V1'den V5'e 5 birim, V1'den V4'e 8 birim gibi. Bu değerler iki şehir arasındaki kilometre ya da herhangi bir maliyet olabilir. Ağlarda paket taşınırken gecikmeye dayalı bir maliyet hesabı yapılır; paketin hazırlanması, sisteme yüklenmesi ve hat üzerinde yol alması gibi farklı gecikme parametreleri vardır. Maliyet yerine fayda ya da kâr oranı da yazılabilir.

### 9.3 Yönlü Graf

Yönlü grafta (directed graph, digraf) yalnız A'dan B'ye ya da F'den D'ye gibi tek yönlü ilişkiler gösterilir. Bu graflar, bağıntılarda (A, B) varken (B, A)'nın da olup olmadığını, yani simetri özelliğini incelemeye yarar. Slayttaki örnek simetri özelliğini sağlamayan bir ilişki grafıydı. Yönlü ve ağırlıklı bir grafta gidiş yönünün maliyeti ile dönüş yönünün maliyeti farklı olabilir; örneğin gidiş 6, dönüş 4 birim.

Graf türlerinin karşılaştırması:

| Tür | Kenarlar | Çoklu kenar | Döngü |
|---|---|---|---|
| Basit graf | Yönsüz | Yok | Yok |
| Çoklu graf | Yönsüz | Var | Yok |
| Pseudo graf | Yönsüz | Var | Var |
| Basit yönlü graf | Yönlü | Yok | Var |
| Yönlü çoklu graf | Yönlü | Var | Var |

Hoca bunların ezberlenecek şeyler olmadığını söyledi.

<!-- BELİRSİZ: Tablo satırları hocanın sözlü anlatımından kuruldu; slayttaki tablo karelerde görünmüyor. -->

## 10. Graflarla Benzerlik Uygulaması

Graflarla basit bir benzerlik uygulaması yapılabilir. Öğrencilerin ödev olarak gönderdiği kodlar arasındaki benzerlikten, hangi kodların birbiriyle ilişkili olduğu araştırılır. Her program için üç özellik çıkarılır: programın satır sayısı, kullanılan return sayısı ve çağrılan fonksiyon sayısı. Bu özellikler metin işleme ile hesaplanır ve bir tabloya yazılır. Her program üç boyutlu bir nokta gibi düşünülür.

Slayttaki tanım şudur (ekrandan, 01:30:00): her düğüm çifti $v = (p_1, p_2, p_3)$ ve $w = (q_1, q_2, q_3)$ ile gösterilsin. Benzer olmayan (dissimilarity) fonksiyon

$$s(v,w) = \sum_{k=1}^{3} |p_k - q_k|$$

şeklinde tanımlanır. $v$ ve $w$ gibi iki programın farklılığı $s(v,w)$ ile ölçülür. $N$ seçilen sabit bir sayı olsun. $s(v,w) < N$ ise $v$ ile $w$ arasına kenar eklenir. $v = w$ ise ya da $v$ ile $w$ arasında bir yol varsa $v$ ile $w$ aynı sınıftadır.

Hoca V1 ile V2 arasındaki farkı şöyle hesapladı:

$$s(v_1, v_2) = |66-41| + |10-20| + |2-1| = 25 + 10 + 1 = 36$$

Farkların sırası önemli değildir, çünkü mutlak değer alınır. Bu mutlak değerler toplamına Manhattan uzaklığı denir. Adı, New York'taki Manhattan'da blokların çok düzgün dizilmesinden ve bloklar arası mesafenin bu şekilde hesaplanmasından gelir. Farkların kareleri toplanıp karekök alınırsa Öklid uzaklığı elde edilir. İki boyutlu uzayda Öklid uzaklığı iki nokta arasındaki en kısa mesafeyi verir; Manhattan uzaklığı ise yatay ve dikey mesafelerin toplamıdır.

Uzaklık arttıkça benzerlik azalır; benzerlik (proximity) uzaklıkla ters orantılıdır. Örnekte V1 ile V2 arasında 36, başka bir çift arasında 24 çıktı. Eşik değeri 25 seçildi. 25'in altında kalan çiftler (V1-V3 ve V3-V5) benzer kabul edildi. Bu programlar arasında bir iş birliği olup olmadığı ayrıca kontrol edilir. Eşik değeri keyfidir ve genellikle tecrübeyle bulunur.

<!-- BELİRSİZ: Programların özellik tablosu karelerde görünmüyor; V1 ve V2'nin hangi değerlere sahip olduğu yalnız hocanın sözlü hesabından alındı. -->

## 11. Özel Graflar

### 11.1 Tam Graf $K_n$

$K_n$ grafında $n$ düğüm vardır, graf basittir ve her düğüm diğer bütün düğümlere doğrudan bir kenarla bağlıdır. Basit graf olduğu için paralel kenar içermez ve A'dan D'ye başka bir düğüm üzerinden değil doğrudan gidilir. $K_3$ bilinen üçgendir. $K_4$'te dört köşenin hepsi birbirine bağlıdır. $K_6$'da her düğüm diğer beş düğüme bağlanır ve bağlanmamış çift kalmaz.

> **Ders sonrası not:** Hoca $K_n$ için $n \ge 3$ şartından söz etti. Bu şart $C_n$ ve $W_n$ için gereklidir; $K_n$ büyük olasılıkla her $n \ge 1$ için tanımlıdır.

### 11.2 Çevre Graf $C_n$

Slayttaki tanım (ekrandan, 01:35:00): $n \ge 3$ olmak üzere $C_n$, $n$ adet düğüm ve $\{v_1,v_2\}, \{v_2,v_3\}, \dots, \{v_{n-1},v_n\}, \{v_n,v_1\}$ düğüm çiftlerinden oluşan kenarlardan meydana gelir. Hoca bunu $(a, b), (b, c), \dots, (x, a)$ diye yazdı; son düğümden başa dönülür. Düğümler arasında köşegen gibi ek doğrudan bağlantı yoktur. $C_3$ üçgen, $C_4$ kare, $C_5$ beşgen, $C_6$ altıgendir.

Hoca bu ilişkiyi bağıntılardaki geçişme (transitif) özelliğine benzetti, ama tam olarak aynı olmadığını da ekledi.

### 11.3 Tekerlek Graf $W_n$

$C_n$ grafına, bütün düğümlere bağlı bir düğüm eklenirse tekerlek grafı $W_n$ elde edilir. Ortaya bir göbek eklemek gibidir. Hoca $C_6$'nın ortasına bir düğüm ekleyip onu bütün köşelere bağlayarak $W_6$'yı çizdi.

### 11.4 $n$-Küp $Q_n$

$Q_n$ grafının düğümleri $n$ uzunluğundaki bit dizileridir; $2^n$ düğüm vardır. Bir düğümden komşusuna geçerken yalnız bir bit değişir; bu, Gray kod mantığıdır. Örneğin 000'dan bir biti değişen düğümlere geçilir. Slaytta $Q_1$, $Q_2$ ve $Q_3$ çizildi. Hiperküp, bir küpün içine başka bir küp yerleştirilmiş gibi düşünülür ve 16 düğüm, 32 kenar içerir.

> **Ders sonrası not:** Hoca hiperküpte 20 yüzey olduğunu söyledi. 4 boyutlu hiperküpün ($Q_4$) kare yüz sayısı büyük olasılıkla 24'tür.

### 11.5 Kenar ve Düğüm Sayıları

| Graf | Düğüm sayısı | Kenar sayısı |
|---|---|---|
| $K_n$ | $n$ | $\frac{n(n-1)}{2}$ |
| $C_n$ | $n$ | $n$ |
| $W_n$ | $n+1$ | $2n$ |
| $K_{m,n}$ | $m+n$ | $mn$ |
| $Q_n$ | $2^n$ | $n \cdot 2^{n-1}$ |

Hoca küp graflarla çok uğraşılmadığını, çünkü yönetmenin daha zor olduğunu söyledi.

## 12. İki Parçalı Graflar

İki parçalı (bipartite) graf, "bi" iki ve "parti" taraf anlamında, iki taraflı graftır. Toplam $m + n$ köşe iki ayrık kümeye bölünür; bir kümede $m$, diğerinde $n$ eleman vardır. Aynı küme içindeki elemanlar arasında hiçbir kenar yoktur; kenarlar yalnız bir kümeden diğerine gider.

Örneğin bir tarafta öğrenciler, diğer tarafta kulüpler olsun. Kenarlar üyelik ilişkisini gösterir. Öğrenci öğrenciye ya da kulüp kulübe üye olmaz; öğrenci kulübe üye olur. Bu ilişki iki parçalı bir graftır.

Slayttaki sorular (ekrandan, 01:40:00):

- $K_3$ iki parçalı graf mıdır? Hayır. Üçgende iki düğüm hangi tarafa konursa konsun aynı taraftaki iki düğüm birbirine bağlı kalır.
- $C_6$ iki parçalı graf mıdır? Evet: $\{1, 3, 5\}$ ve $\{2, 4, 6\}$.

Hoca $C_6$'yı çizerek gösterdi. 1'den 3'e doğrudan kenar yoktur; 1'den 2'ye ve 3'ten 2'ye kenar vardır. 4'ten 3'e var, 4'ten 2'ye yoktur. 4'ten 5'e, 6'dan 5'e ve 6'dan 1'e kenar vardır. Tek numaralılar bir tarafa, çift numaralılar diğer tarafa konunca iki parçalı graf çıkar. $C_4$ için de 1, 2, 3, 4 düğümlerinde 1 ile 4 bir tarafa, 2 ile 3 diğer tarafa konur. Hoca bu fikrin graf boyamada da kullanılacağını söyledi.

Slayttaki iki graf da test edildi. Birinci grafta F düğümü A, B, C, D ve E'ye bağlıdır. F bir tarafa, bunlar diğer tarafa konursa A ile B ve B ile C arasındaki kenarlar aynı taraf içinde kalır. Bu yüzden graf iki parçalı değildir. İkinci grafta A; G, F ve E'ye bağlıdır, B; F ve E'ye bağlıdır. A, B, C ve D bir tarafa, E, F ve G diğer tarafa konunca bütün kenarlar iki küme arasında kalır ve graf iki parçalı olur.

### 12.1 Tam İki Parçalı Graf $K_{m,n}$

Bir tarafta $m$, diğer tarafta $n$ köşe varken bir taraftaki her köşe diğer taraftaki her köşeye bağlıysa, yani toplam $m \cdot n$ kenar varsa, tam (complete) iki parçalı graf elde edilir. Örneğin $K_{3,2}$'de bir tarafta 3, diğer tarafta 2 düğüm ve toplam 6 kenar vardır. Slaytta $K_{2,3}$, $K_{3,3}$ ve $K_{2,6}$ gibi örnekler gösterildi.

## 13. Yollar, Döngüler ve Euler Döngüsü

$n$ uzunluğundaki bir yolun $n+1$ düğümü ve $n$ ardışık kenarı vardır. Örneğin tek kenarlı bir yolun iki düğümü vardır. Döngü içeren bir yol başladığı düğümde son bulur. Uzunluğu $n$ olan bir döngüde $n$ düğüm vardır; 3 uzunluklu bir döngüde 3 köşe bulunur.

### 13.1 Euler Döngüsü ve Königsberg Köprü Problemi

Slayttaki tanım (ekrandan, 01:45:00): $G$ grafı içindeki Euler döngüsü (Euler cycle), basit bir çevrim olup $G$ içindeki her kenardan sadece bir kez geçilmesine izin verir. "Bu şekli elinizi kaldırmadan çizebilir misiniz?" türünden bulmacalar Euler ve Hamilton döngüleriyle ilgilidir.

Kavram Königsberg köprü problemine dayanır. Bir şehirde yedi köprü vardır ve köprüler şehri A, B, C, D bölgelerine ayırır. Soru şudur: başlangıç ve bitiş noktası aynı olmak üzere yedi köprünün her birinden sadece bir kez geçerek başlangıç noktasına dönmek mümkün müdür? Problem grafa indirgenir: kenarlar köprüleri, düğümler bölgeleri gösterir. Ortaya çıkan grafta A ile D arasında iki, D ile C arasında iki, D ile B, A ile B ve B ile C arasında birer köprü vardır.

Euler döngüsünün varlığı düğüm derecelerine bağlıdır. Bir düğümün derecesi $\delta(v)$ ile gösterilir. Yönsüz grafta derece, düğüme gelen kenarların sayısıdır. Düğümdeki bir döngü dereceye iki kez katılır. Yönlü grafta ise gelen ve giden kenarlar ayrı ayrı sayılır; ikisinin toplamı toplam derecedir.

Hoca kendi eklediği bir alıştırmada iki grafın düğüm derecelerini saydı. Birinci grafta A'nın derecesi 2; B, C ve F'nin derecesi 4; D'nin derecesi 1'dir ve G'nin hiç kenarı yoktur (derecesi 0). İkinci grafta A'nın derecesi 4, B ve E'nin derecesi 6'dır.

<!-- BELİRSİZ: Derece alıştırmasındaki graflar karelerde görünmüyor; değerler yalnız sözlü anlatımdan alındı. -->

Bir grafın Euler grafı olması için bütün düğümlerinin derecesi çift olmalıdır. Königsberg grafında dereceler A: 3, B: 3, C: 3, D: 5'tir. Hiçbiri çift olmadığı için graf Euler grafı değildir; dolayısıyla problemin çözümü yoktur.

Hoca, elini kaldırmadan çizilen bir şekil üzerinde de dereceleri saydı. Bu şekilde başlangıç noktasına dönülebiliyordu ama bir köprüden iki kez geçmek gerekiyordu. Hoca bu örneğin Euler değil Hamilton özelliğine uyduğunu söyledi.

<!-- BELİRSİZ: Hocanın çizdiği şekil karelerde görünmüyor; Euler ve Hamilton arasındaki değerlendirme altyazıda net değil. -->

> **Hocanın vurgusu:** Euler grafının kontrolü kolaydır. Düğümlerin derecelerine bakılır; hepsi çiftse graf Euler grafıdır.

### 13.2 Euler Yolu

Euler yolu, başlangıç noktasına geri dönmeden her kenardan bir kez geçen yoldur. Hoca Euler yolunun varlığı için de düğüm dereceleriyle ilgili bir kural olduğunu, ama derste tam hatırlayamadığını söyledi: iki düğümün derecesi tek, geri kalanların çift olmalıydı.

> **Ders sonrası not:** Bağlı bir grafta tek dereceli düğüm sayısı tam olarak 2 ise Euler yolu vardır ve yol bu iki düğümde başlayıp biter. Tek dereceli düğüm yoksa Euler döngüsü vardır. Hocanın "en az iki tane tek" ifadesi "tam olarak iki" olmalıdır.

Slayttaki "Hangileri Euler grafıdır?" sorusunda bir grafın dereceleri 2, 3, 2, 3'tü. Bu graf Euler grafı değildir ama Euler yolu vardır. Başka bir grafta dereceler 2, 4, 4, 4, 4, 4, 4'tü; bu bir Euler grafıdır ve slaytta Euler döngüsü gösterildi. Bir diğer grafın dereceleri 2, 4, 4, 2, 4, 2 idi; bu da bir Euler grafıdır. Euler grafı varsa Euler yolu da vardır, ama Euler yolu varsa grafın Euler grafı olacağı söylenemez.

## 14. Düğüm Dereceleri ve El Sıkışma Teoremi

Slayttaki tanımlar (ekrandan, 01:50:00):

- Sıfır dereceli bir düğüm ayrık (isolated) olarak adlandırılır. Ayrık bir düğümden başka bir düğüme yol yoktur.
- Düğüm derecesi bir olan düğüme sarkık (pendant) denir.

**Teorem (El sıkışma, handshaking):** $e$ adet kenarlı ve $n$ adet düğümlü bir $G(V, E)$ grafının düğümlerinin dereceleri toplamı kenar sayısının iki katıdır:

$$\sum_{i=1}^{n} \delta(v_i) = 2e$$

El sıkışmada karşınızdakiyle el sıkıştıysanız onun sizinle tekrar el sıkışmasına gerek yoktur; her kenar iki düğümün derecesine katkı yapar.

**Soru:** Her birinin derecesi 6 olan 10 düğümlü bir grafın kaç kenarı vardır? **Cevap:** Dereceler toplamı $10 \cdot 6 = 60$'tır. Bu, kenar sayısının iki katı olduğu için kenar sayısı $60 / 2 = 30$'dur.

Yönlü grafta kenar $v$'den $w$'ye gidiyorsa $v$ başlangıç düğümü (initial vertex), $w$ bitiş düğümü (terminal, end vertex) olarak adlandırılır. Bir düğümde döngü varsa başlangıç ve bitiş aynıdır. Giriş derecesi (in-degree) $\delta^-(v)$ düğüme gelen kenar sayısı, çıkış derecesi (out-degree) $\delta^+(v)$ düğümden çıkan kenar sayısıdır. Bütün yönlü graflarda giriş derecelerinin toplamı ile çıkış derecelerinin toplamı birbirine eşittir.

## 15. Hamilton Döngüsü

Euler her kenardan bir kez geçmeyi şart koşar ama aynı düğümden birden fazla geçilmesine izin verir. Hamilton daha kısıtlayıcıdır: aynı düğümden iki kez geçilmez. Slayttaki tanım (ekrandan, 01:55:00): $G$ grafının üzerindeki her düğümden yalnız bir kez geçmek şartıyla kapalı bir yol oluşturabilen graflardır. Bu kapalı yol Hamilton döngüsü (Hamiltonian cycle) olarak adlandırılır. Hamilton döngüsüne sahip bir $G$ grafı Hamilton grafıdır. Slayttaki a, b, c, d, e, f, g düğümlü örnek, Hamilton olmayan bir graftır.

En bilinen örnek gezgin satıcı (traveling salesperson) problemidir. Türkiye'deki bütün illeri gezmek için bir rota belirlenir; hiçbir şehirden iki kez geçilmez ve en sonunda başlangıç noktası olan şehre (örneğin İstanbul'a) geri dönülür. İki kez uğranan tek şehir başlangıç noktasıdır.

Slayttaki bir örnekte A'dan başlayıp E, D, C, B, H, I, J üzerinden dolaşarak tekrar A'ya dönülebiliyordu; her şehirden en fazla bir kez geçiliyordu. $Q_3$ grafı da bir Hamilton döngüsü içerir: bir noktadan birer bit değiştirerek ilerlenir ve sonunda başlangıç noktasına dönülür.

## 16. Grafların Bilgisayarda Gösterimi

Bu problemleri bilgisayarda çözmek için önce grafı bir veri yapısıyla saklamak gerekir. Üç temel yöntem vardır: komşuluk listesi (adjacency list), komşuluk matrisi (adjacency matrix) ve geliş matrisi (incidence matrix).

### 16.1 Komşuluk Listesi

Her düğüm için komşuları listelenir. Örneğin A; B, C ve D'yi görür, B; A ve C'yi görür. Bu yapı bağlı listelerle ya da dizilerle gerçeklenir. Yönsüz grafta A'nın listesine B yazıldıysa B'nin listesine de A yazılmalıdır. Yönlü grafta yönlere bakılır: E'den B'ye bir kenar varsa B E'nin komşusudur, ama kenar ters yönde olmadığı için B'nin listesinde E görünmez. B'de bir döngü varsa B kendi listesinde yer alır.

### 16.2 Komşuluk Matrisi

İki düğüm arasında kenar varsa 1, yoksa 0 yazılır. 1 yerine ağırlık (örneğin 2, 6, 8) yazılırsa A'dan B'ye olan maliyet saklanmış olur. A, B, C, D sırasıyla yazılıp A'dan B'ye, C'ye, D'ye kenar varsa ilgili hücrelere 1 yazılır.

- Yönsüz grafın komşuluk matrisi simetriktir.
- Matrisin köşegeninin altı ile üstü farklıysa ve ağırlıklar varsa graf yönlü ve ağırlıklıdır; A'dan B'ye yolun maliyeti ile B'den A'ya yolun maliyeti farklıdır.
- Döngü yoksa köşegen sıfırdır.
- Kenar sayısı az, sıfır sayısı çoksa matris seyrektir (sparse). Bu durumda matris bellekte gereksiz yer tutar. Düğümlerin sırası değiştirilerek seyrek matris düzenlenebilir.

Komşuluk matrisinin karesi alınırsa, hangi düğümün hangi düğüme iki adımda (2 uzunluklu yolla) ulaşabildiği bulunur. Örneğin A'dan D'ye doğrudan kenar olmasa bile karesi alınan matriste A'dan D'ye iki uzunluklu yol olduğu görülür.

### 16.3 Geliş Matrisi

Geliş matrisi de benzer bir matristir. Hoca bu gösterimde ağırlıkların pek kullanılmadığını, daha çok kenarların varlığının önemli olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Geliş matrisinde satırlar düğümleri, sütunlar kenarları gösterir. $v_i$ düğümü $e_j$ kenarının ucundaysa $(i, j)$ hücresine 1, değilse 0 yazılır. Yönsüz ve döngüsüz bir grafta her sütunda tam iki tane 1 bulunur.

## 17. Yollar, Bağlılık ve Yol Sayımı

Grafı bilgisayarda sakladıktan sonra birçok problem çözülebilir. Bunlardan biri bağlılık (connectivity) problemidir: grafın bütün elemanları birbirine bağlı mıdır, yoksa graf birden fazla parçadan mı oluşur?

### 17.1 Yol ve Devre Örnekleri

Slayttaki örneklerde:

- a, b, c, d basit bir yoldur (4 düğümlü). a'dan b'ye, b'den c'ye, c'den d'ye kenar vardır.
- d, e, c, a bir yol değildir; e'den c'ye kenar yoktur.
- b, c, f, e, b, 4 uzunluğunda bir devredir (circuit, kapalı çevrim).
- a, b, e, d, a, b bir yoldur, ama basit değildir; aynı kenardan tekrar geçer.

### 17.2 Ayrılık Dereceleri ve Bacon Sayısı

Hoca bu kısımdaki bazı konuları, ileride graf teorisi ve veri yapıları derslerinde görülecek problemlerden haberdar olunsun diye eklediğini söyledi. Ayrılık dereceleri (degrees of separation), yollar üzerindeki tanışıklık ve yakınlığı bir grafla yakalar. Hoca iki öğrenciyi örnek verdi: üniversiteye kadar birbirlerini tanımıyor olabilirler, ama bir tanıdık zinciriyle aralarında bir yol bulunur.

Slayttaki tanım (ekrandan, 02:05:00): Hollywood grafında iki oyuncu $a$ ve $b$, aralarında bir oyuncu zinciri varsa bağlıdır; zincirdeki her iki komşu oyuncu aynı filmde oynamıştır. Bir $c$ oyuncusunun Bacon sayısı, $c$ ile Kevin Bacon arasındaki en kısa yolun uzunluğudur. Kevin Bacon yerine başka bir oyuncu da alınabilir. Bu tür problemler veri yapıları derslerinde bazen ödev olarak verilir. Hoca, bir Türk oyuncu ile ünlü bir Hollywood oyuncusu arasındaki uzaklığın küçük çıktığını örnek verdi. Burada birebir tanışmaktan değil, aynı filmde rol almaktan söz edilir. Sosyal medyada çok takip edilen bir kişi üzerinden pek çok kişi arasındaki uzaklık 2'ye kadar düşer.

> **Ders sonrası not:** Hoca herhangi iki kişinin en fazla yedi adımda birbirine ulaştığını söyledi. Slayttaki tabloda (2011 başı) Bacon sayısı 8 olan 16 kişi görünüyor (ekrandan, 02:05:00); yani 7 bir üst sınır değildir.

Slayttaki tablo:

| Bacon sayısı | Kişi sayısı |
|---|---|
| 0 | 1 |
| 1 | 2.367 |
| 2 | 242.407 |
| 3 | 785.389 |
| 4 | 200.602 |
| 5 | 14.048 |
| 6 | 1.277 |
| 7 | 114 |
| 8 | 16 |

### 17.3 Bağlı Bileşenler

Yönsüz bir grafın bağlılığı için bağlı bileşen etiketleme (connected component labeling) kullanılır ve bunun için BFS ya da DFS çalıştırılır. Bağlı bir grafta BFS bütün düğümleri işaretler ve kuyruk (ya da yığın) boşaldığında ziyaret edilmemiş düğüm kalmaz. Bağlı olmayan bir grafta ise kuyruk boşaldığı halde ziyaret edilmemiş düğümler kalır. Bu, ikinci bir bağlı bileşen olduğunu gösterir. Slayttaki örnekte üç bağlı bileşen vardı. Bağlılık yönlü graflarda da test edilir.

### 17.4 Yol Sayımı

Normal bir komşuluk matrisinden yalnız yolun varlığı görülür. Komşuluk matrisinin kuvvetleri alınırsa iki düğüm arasında belirli uzunlukta kaç yol (walk) olduğu bulunur: $A^2$ iki uzunluklu, $A^3$ üç uzunluklu, $A^4$ dört uzunluklu yolların sayısını verir.

Slayttaki örnekte a'dan d'ye 4 uzunluklu yol sayısı sorulmuştu. $A^4$ hesaplanınca bu sayı 8 çıktı. Bu yollarda aynı kenardan gidip gelmek mümkündür; örneğin a, b, a, b, d.

<!-- BELİRSİZ: Slayttaki grafın yapısı karelerde görünmüyor. Graf a-b, a-c, b-d, c-d kenarlı 4 düğümlü bir çevre ise $A^4$'ün (a, d) elemanı python ile 8 çıkıyor. -->

Bu yollardan çok sayıda çıkar. Bir noktadan diğerine en kısa yolun nasıl bulunacağı ise ayrı bir problemdir. Bunun için birçok optimizasyon algoritması vardır; biri Dijkstra algoritmasıdır.

## 18. Dijkstra En Kısa Yol Algoritması

En kısa yoldaki "kısa", maliyet açısından olabilir: para, kilometre, zaman, gecikme ya da benzerlik. Önemli olan genel kavramdır. Dijkstra algoritmasının mantığı zor değildir. Kaynak düğümden hedef düğüme giderken en iyi duruma, yani minimum maliyete göre güncelleme yapılır:

- Başlangıçta kaynaktan ara düğümlere olan maliyet bilinmez (sonsuz kabul edilir). Kaynağın kendisine maliyeti 0'dır.
- Grafta verilen maliyetlere göre komşuların maliyeti güncellenir.
- Yeni bir düğüme geçildiğinde daha kısa maliyetli bir yol bulunursa o yol üzerinden güncelleme yapılır.
- İşlem hedef düğüme ulaşılana kadar devam eder.

Hem maliyet bilgisi tutulur hem de o maliyeti veren yol takip edilir. Hoca, bütün olası durumların kontrol edildiğini ve bu yüzden karesel bir karmaşıklık ortaya çıktığını söyledi. Daha iyi gerçeklemelerle $E \log V$ (kenar sayısı çarpı köşe sayısının logaritması) karmaşıklığına inilebilir.

> **Ders sonrası not:** Hoca karmaşıklığı kenar sayısının karesi olarak söyledi. Dijkstra'nın dizi ile basit gerçeklemesinin karmaşıklığı $O(V^2)$'dir (düğüm sayısının karesi); öncelik kuyruğu ile $O(E \log V)$ olur.

### 18.1 Altı Düğümlü Örnek

Ekrandaki grafın kenarları şunlardır (ekrandan, 02:30:00): a-b: 2, a-c: 3, b-d: 5, b-e: 2, c-e: 5, d-e: 1, d-f: 2, e-f: 4. Amaç a'dan f'ye gitmektir. Tabloda her hücrede maliyet ve o maliyeti veren yol yazılır; M sonsuz demektir.

| Düğüm | Başlangıç | a ziyaret | b ziyaret | c ziyaret |
|---|---|---|---|---|
| a | 0 | - | | |
| b | M | 2a | - | |
| c | M | 3a | 3a | - |
| d | M | M | 7ab | 7ab |
| e | M | M | 4ab | 8ac (alınmaz) |
| f | M | M | M | M |

1. İlk adımda a'dan diğer bütün düğümlere maliyet sonsuzdur, a'nın kendisine maliyeti 0'dır.
2. a ziyaret edilince b'ye 2 birimle, c'ye 3 birimle gidileceği görülür. b'ye a üzerinden gelindiği bilgisi de saklanır (2a).
3. b ziyaret edilince d'ye a-b üzerinden 7 birimle, e'ye a-b üzerinden 4 birimle ulaşılabileceği eklenir. f'ye henüz gidilemez.
4. c ziyaret edilince e'ye a-c üzerinden 8 birimlik bir yol çıkar. Bu, mevcut 4 birimden uzun olduğu için tercih edilmez. Bu kontrol, sıralama algoritmalarında her elemanın diğerleriyle karşılaştırılması gibi her adımda yapılır.
5. e ziyaret edilince d'ye a-b-e üzerinden 4 + 1 = 5 birimle gelinebildiği görülür. Önceki 7 birimlik değer geçersiz olur ve 5 kullanılır. Aynı anda f'ye a-b-e üzerinden 4 + 4 = 8 birimle gidilebileceği eklenir.
6. d ziyaret edilince f'ye d üzerinden 5 + 2 = 7 birimle gidilebildiği görülür. 7 < 8 olduğu için 8 silinir ve maliyet 7 olur.

Hedefe ulaşıldığı için algoritma durur. En kısa rota a, b, e, d, f'dir ve maliyeti 7'dir (python ile doğrulandı).

Hoca, çok sayıda düğüm olduğunda (örneğin 300 nokta) maliyetin çok arttığını ve bu durumda yapay zeka optimizasyon algoritmalarından yararlanıldığını söyledi. Bu algoritmalar önce bir yol bulur, sonra onu olabildiğince iyileştirmeye çalışır. Dijkstra'da olduğu gibi daha kısa bir rota bulunursa güncellenir; hoca bunu "kervan yolda düzülür" diye özetledi.

### 18.2 Demo: Altı Düğüm ve On Kenar

Bir demoda $u_0$'dan başlayan 6 düğümlü, 10 kenarlı bir graf kullanıldı (ekrandan, 02:35:00). Kenarlar: $u_0$-$u_5$: 8, $u_0$-$u_2$: 13, $u_0$-$u_4$: 16, $u_5$-$u_1$: 10, $u_5$-$u_4$: 7, $u_5$-$u_3$: 17, $u_5$-$u_2$: 11, $u_2$-$u_3$: 14, $u_4$-$u_3$: 5, $u_1$-$u_3$: 6.

1. $u_0$'dan üç noktaya gidilebilir: $u_5$'e 8, $u_2$'ye 13, $u_4$'e 16 birim.
2. $u_5$ ziyaret edilir. $u_5$'e $u_0$'dan gelindiği bir bellek elemanında tutulur. $u_1$'e $8 + 10 = 18$, $u_3$'e $8 + 17 = 25$ birimle gidilebilir. $u_4$'e $8 + 7 = 15$ birimle gidilebildiği için eski 16 silinir ve 15 olur.
3. $u_2$ ziyaret edilir (13). $u_3$'e $13 + 14 = 27$ birimle gidilebilir ama 25 zaten vardır. $u_5$'e $13 + 11 = 24$ birimle gidilebilir ama 8 zaten vardır. $u_2$'den bir iyileşme çıkmaz ve $u_2$ kapatılır.
4. $u_4$ ziyaret edilir (15). $u_3$'e $15 + 5 = 20$ birimle ulaşılır; 25 yerine 20 yazılır.
5. $u_1$ ziyaret edilir (18). $u_3$'e $18 + 6 = 24$ birimle gidilebilir ama 20 zaten vardır.

Böylece $u_3$'e en kısa yol $u_0$, $u_5$, $u_4$, $u_3$ olur.

> **Ders sonrası not:** Hoca $u_0$'dan $u_3$'e gitmenin maliyetini 21 olarak söyledi. Doğrusu $8 + 7 + 5 = 20$'dir; ekranda da $u_3$'ün maliyeti olarak hesaplanan değer 25'ten 20'ye iner (python ile doğrulandı).

### 18.3 Demo: On İki Düğümlü Izgara Graf

Bir sonraki demoda a'dan l'ye en kısa yol arandı (ekrandan, 02:40:00). Düğümler üç satırda dizilidir: a, b, c, d; e, f, g, h; i, j, k, l. Kenar ağırlıkları:

- Yatay: a-b 10, b-c 2, c-d 2, e-f 6, f-g 3, g-h 10, i-j 3, j-k 2, k-l 1
- Dikey: a-e 2, b-f 3, c-g 1, d-h 9, e-i 1, f-j 2, g-k 9, h-l 5
- Çapraz: a-f 8, c-f 5, d-g 2, e-j 3, g-j 6, g-l 4

Hoca tahtada adım adım ilerledi:

1. a'dan e'ye 2, f'ye 8, b'ye 10 birimle gidilir.
2. b'den c'ye $10 + 2 = 12$ birim yazıldı.
3. e'den i'ye $2 + 1 = 3$, j'ye $2 + 3 = 5$ birim yazıldı. f'ye $2 + 6 = 8$ birim, mevcut değerle aynıdır.
4. f'den g'ye $8 + 3 = 11$ birim yazıldı. c'ye $8 + 5 = 13$ ve j'ye $8 + 2 = 10$ birim güncelleme gerektirmedi.
5. c'den d'ye $12 + 2 = 14$ birim yazıldı. g üzerinden $11 + 2 = 13$ birim daha kısa olduğu için d'nin değeri 13 oldu. g'den l'ye $11 + 4 = 15$, k'ye $11 + 9 = 20$ birim yazıldı.
6. j'den k'ye $5 + 2 = 7$ birimle gidilebildiği için k'nin değeri 7 oldu. k'den l'ye $7 + 1 = 8$ birimle gidildi ve l'nin maliyeti 8 oldu. l'den h'ye $8 + 5 = 13$ birim yazıldı.

Her düğüme hangi düğümden gelindiği de tutulur. Hoca, önceki örnekteki gibi rotanın tamamını saklamak yerine yalnız bir önceki düğümün tutulmasının yeterli olduğunu söyledi. Rota, bağlı listedeki gibi geriye doğru izlenir (backtrace). l'ye k'den, k'ye j'den, j'ye e'den, e'ye a'dan gelindiği için en kısa yol a, e, j, k, l'dir ve maliyeti 8'dir.

**Soru:** f'ye j'den gitsek daha kısa olmaz mıydı? **Cevap:** Hoca önce iki yolun da aynı çıktığını düşündü, sonra öğrencinin haklı olduğunu kabul etti. j'ye 5 birimle gelindiği için f'ye $5 + 2 = 7$ birimle gidilir. Bu güncelleme bazı maliyetleri değiştirir: g'ye $7 + 3 = 10$ birimle, c'ye g üzerinden $10 + 1 = 11$ birimle gidilir.

**Soru:** d de g üzerinden 12 birim olmuyor mu? **Cevap:** Evet, d'ye g üzerinden $10 + 2 = 12$ birimle gidilir.

Hoca, algoritmada iki iç içe döngü olduğunu ve bütün komşuluk olasılıklarının tekrar tekrar gözden geçirildiğini, bu yüzden sürecin yinelemeli (iteratif) olduğunu vurguladı.

> **Ders sonrası not:** Python ile hesaplanan en kısa mesafeler şunlardır: a 0, e 2, i 3, j 5, f 7, k 7, l 8, b 10, g 10, c 11, d 12, h 13. a'dan l'ye en kısa yol a, e, j, k, l ve maliyeti 8'dir.

### 18.4 Demo: Şehirler Arası En Kısa Yollar

Son demoda Japonya'daki 14 şehir ve 22 yoldan oluşan bir grafta Tokushima'dan diğer şehirlere en kısa yollar bulundu (ekrandan, 02:45:00). Tokushima'dan Akashi'ye 85, Okayama'ya 140 birimle gidilir. Akashi üzerinden Kakogawa'ya $85 + 19 = 104$, Osaka'ya $85 + 39 = 124$ birimle ulaşılır. Kakogawa'dan Himeji'ye $104 + 12 = 116$ birim olur. Algoritma ilerledikçe daha kısa yol bulunan şehirlerde eski yollar bırakılır. Örneğin Okayama'ya Himeji üzerinden $116 + 26 = 142$ birimle gidilebilir, ama doğrudan yol 140 olduğu için o kullanılmaz.

Ekranda bulunan sonuç maliyetleri şunlardır: Akashi 85, Kakogawa 104, Himeji 116, Osaka 124, Okayama 140, Kyoto 154, Chizu 181, Wadayama 183, Niimi 199, Tsuyama 205, Tottori 212, Fukuchiyama 213, Yonago 260. Hoca, Fukuchiyama'ya Kyoto üzerinden gitmek yerine başka bir yoldan daha kısa ulaşıldığına dikkat çekti.

> **Ders sonrası not:** Hoca Kyoto üzerinden Fukuchiyama maliyetini $154 + 74 = 223$ olarak söyledi; doğrusu 228'dir. 213'lük en kısa yol Tokushima, Akashi, Kakogawa, Himeji, Wadayama, Fukuchiyama ($116 + 67 + 30 = 213$) yoludur (python ile doğrulandı).

## 19. Graf Modelleri, Düzlemsel Graf, Graf İzomorfizmi ve Ağ Topolojileri

### 19.1 Graf Modelleri

Uygulamada kullanılan bazı graf modelleri:

- **Niş örtüşme grafları (niche overlap graphs):** bir ekosistemdeki farklı grupları modellemek için kullanılır.
- **Etki grafları (influence graphs):** hiyerarşiyi ve grup çalışmalarında kişilerin birbirini etkilemesini gösterir.
- **Round-robin grafları:** bir turnuvadaki her takımın kimle karşılaşacağını gösterir.
- **Öncelik grafları (precedence graphs):** hangi işlemin hangisinden önce gelmesi gerektiğini gösterir. Süreç madenciliğinde (process mining) işleri verimli bir sıraya dizmek için kullanılır.

Öncelik grafı örneğinde program deyimleri düğümlerdir. a'ya 0, b'ye 1 atanır. c'nin hesaplanabilmesi için a'nın değerinin atanmış olması gerekir. d'nin hesaplanması için de $S_1$ ve $S_2$ deyimlerinin önce çalışması gerekir.

<!-- BELİRSİZ: Öncelik grafındaki deyimlerin tamamı karelerde görünmüyor. -->

### 19.2 Düzlemsel Graf

Bir grafın kenarları birbirini kesmeyecek şekilde çizilebiliyorsa bu graf düzlemsel (planar) graftır. Bir kenar başka bir kenarın üzerinden geçmeyecek şekilde yeniden çizilir; örneğin A'dan B'ye giden kenar diğer kenarları kesmeyecek şekilde dışarıdan dolaştırılır. Hoca, düzlemsel graflar için düğüm sayısı, kenar sayısı ve yüzey sayısını ilişkilendiren bir Euler formülü olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Bağlı düzlemsel bir grafta düğüm sayısı $v$, kenar sayısı $e$ ve yüzey (bölge) sayısı $f$ ise $v - e + f = 2$ olur. Bu eşitlik bir düzlemsel çizim için her zaman sağlanır; bu yüzden formül bir grafın düzlemsel olmadığını göstermek için kullanılan eşitsizliklerin de temelidir.

### 19.3 Graf İzomorfizmi

İki grafın izomorfik olması için kenar sayıları, düğüm sayıları ve düğüm dereceleri aynı olmalıdır; bunların kontrolü kolaydır. Ayrıca düğümler arasındaki ilişkiyi gösteren komşuluk matrisleri de aynı olmalıdır. Burada birebir aynılık aranmaz: satır ve sütunların yer değiştirmesiyle aynı matris elde edilebiliyorsa graflar izomorfiktir.

Slayttaki örnek (ekrandan, 02:50:00): $u_1, u_2, u_3, u_4$ köşeli kare biçimli graf ile $v_1, v_2, v_3, v_4$ köşeli çapraz kesişen graf izomorfik midir? Her iki grafta da 4 düğüm, 4 kenar vardır ve her düğümün derecesi 2'dir. Komşuluk matrisleri:

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

Slayttaki çözüme göre $u_2$ ve $u_4$'ün satır ve sütunları yer değiştirirse ikinci matris elde edilir. Önce satırlar değiştirilir: $u_2$ satırı 1, 0, 0, 1 ve $u_4$ satırı 0, 1, 1, 0 yer değiştirir. Sonra aynı şey sütunlara uygulanır. Bu durumda eşleme $u_1 \to v_1$, $u_4 \to v_2$, $u_3 \to v_3$, $u_2 \to v_4$ olur ve graflar izomorfiktir (python ile doğrulandı). Sütun değişikliğini görmek her zaman kolay değildir; bir örüntü bulmak gerekir. Bunu yapan yazılımlar da vardır.

> **Hocanın vurgusu:** Böyle bir soru sorulursa çok ağır bir örnek sorulmaz.

Slayttaki diğer örneklerden birinde kenar sayıları farklı olduğu için graflar izomorfik değildi. Daha zor bir örnekte ilk üç şart sağlanıyordu ve matrisler üzerinden ayrıntılı kontrol gerekiyordu; hoca bu örneklerin alıştırma için konduğunu söyledi.

### 19.4 Ağ Topolojileri

Graflar, haberleşme ağlarındaki topolojileri modellemek için de kullanılır. Yerel ağda (Local Area Network) belirli bir alan içindeki bilgisayarlar farklı biçimlerde birbirine bağlanır:

- **Yıldız topoloji:** ortada bir hub ya da switch, çevrede bilgisayarlar vardır. Bir tarafta tek eleman, diğer tarafta bilgisayarlar olduğu için tam iki parçalı $K_{1,n}$ grafıdır.
- **Halka topoloji:** her bilgisayar kendinden önceki ve sonraki bilgisayarı tanır. Bu bir çevre grafıdır ($C_n$).
- **Hibrit topoloji:** tekerlek grafına ($W_n$) benzer.

Hoca, bütün bilgisayarların doğrudan birbiriyle haberleşebildiği durumlara kablosuz ağı örnek verdi.

<!-- BELİRSİZ: Hoca kablosuz ağ örneğini hibrit topoloji ve tekerlek grafıyla birlikte andı; bütün bilgisayarların doğrudan birbirine bağlı olduğu yapı $W_n$'den çok tam graf $K_n$'ye karşılık gelir. -->

## Örnek Sorular

**Soru 1** (derste tahtada, 00:19:15; ekrandan, 00:25:00): 5 satır (0-4) ve 6 sütunlu (0-5) bir ızgarada robot (2, 1) konumundadır ve (1, 4) hedefine gidecektir. Komşu sırası sağ, yukarı, sol, aşağıdır. BFS ve DFS ile arama nasıl ilerler?

> **Çözüm:** BFS kuyruk kullanır ve ziyaret sırası (2, 1), (2, 2), (1, 1), (2, 0), (3, 1), (2, 3), (1, 2), (3, 2), ... şeklinde halka halka genişler. DFS yığın kullanır ve (2, 1) → (2, 5) arasında sağa, sonra (1, 5) ve (0, 5)'e yukarı, sonra (0, 0)'a kadar sola gider ve aşağı iner. Derste iki arama da hedefe ulaşmadan bırakıldı. Python benzetiminde hedef BFS'de 21. ziyarette, DFS'de 17. adımda bulunur.

**Soru 2** (ekrandan, 00:40:00): 7 düğümlü maliyet matrisi (Bölüm 3.2'deki tablo) verilen graf için 1. düğümden başlayarak Prim algoritmasıyla minimum kapsayan ağacı bulunuz.

> **Çözüm:** Seçilen kenarlar sırasıyla 1-3 (100), 1-4 (300), 1-7 (400), 3-5 (500), 5-6 (200), 2-7 (900) olur. Toplam maliyet 2400'dür.

**Soru 3** (ekrandan, 00:50:00): Görünüşleri birbirinin aynı olan 5 paradan biri sahtedir. Sahte para diğerlerinden daha ağır veya daha hafif olabilir. Karar ağacını kullanarak hangi paranın sahte olduğuna karar veriniz. Sahte para hafif midir, ağır mıdır?

> **Çözüm (derste verilmedi):** Derste yalnız ilk karşılaştırmalar anlatıldı; ağacın tamamı şöyle kurulabilir.
>
> - $C_1$ ile $C_2$ tartılır. Eşit değilse sahte para bu ikisinden biridir ve $C_3, C_4, C_5$ gerçektir. $C_1$ ile $C_5$ tartılır: eşitse sahte $C_2$'dir (ilk tartıda $C_2$ ağır bastıysa ağır, hafif kaldıysa hafif). Eşit değilse sahte $C_1$'dir (ilk tartıdaki yönüne göre ağır ya da hafif).
> - $C_1 = C_2$ ise $C_3$ ile $C_4$ tartılır. Eşit değilse $C_3$, gerçek olduğu bilinen $C_1$ ile tartılır: eşitse sahte $C_4$, değilse sahte $C_3$'tür; ağır mı hafif mi olduğu tartının yönünden anlaşılır.
> - $C_3 = C_4$ ise sahte $C_5$'tir. $C_5$, $C_1$ ile tartılarak ağır mı hafif mi olduğu bulunur.
>
> Her durumda en fazla 3 tartı yeterlidir. 10 olası sonuç (5 para × ağır/hafif) olduğu ve iki tartıyla en fazla $3^2 = 9$ sonuç ayırt edilebildiği için 2 tartı yetmez.

**Soru 4** (ekrandan, 00:55:00; derste sözlü, 00:51:45): Tenis örneğinde 15. durumda hava görünümü sunny, sıcaklık mild, nem high, rüzgar weak'tir. Kişi tenis oynar mı?

> **Çözüm (derste verilmedi):** Ekrandaki nem kökenli ağaçta high → weak → sunny dalı (1, 8) örneklerine gider ve sonuç NO'dur. Bilgi kazancıyla kurulan ağaçta da kök hava görünümüdür ve sunny dalında nem high olduğu için sonuç büyük olasılıkla yine "no"dur. Derste sonuç açıkça söylenmedi.

**Soru 5** (ekrandan, 00:55:00 ve 00:57:20): 9 "yes" ve 5 "no" içeren veri kümesinde rüzgar özelliği weak için 6 yes, 2 no; strong için 3 yes, 3 no veriyor. Rüzgarın bilgi kazancı nedir?

> **Çözüm:** $H(S) = 0{,}940$, $H(S_{weak}) = 0{,}811$, $H(S_{strong}) = 1$. $Gain = 0{,}940 - \frac{8}{14} \cdot 0{,}811 - \frac{6}{14} \cdot 1 = 0{,}048$.

**Soru 6** (derste sözlü, 01:20:48): Graftaki döngü (loop) bağıntıların hangi özelliğini gösterir?

> **Çözüm:** Yansıma (refleksif) özelliğini. Döngü bir düğümden kendisine giden kenardır; $(a, a)$ ikilisine karşılık gelir.

**Soru 7** (ekrandan, 01:35:00): $C_4$, $C_5$, $C_6$ graflarını çiziniz.

> **Çözüm:** $C_4$ dört düğümlü bir karedir, $C_5$ beşgen, $C_6$ altıgendir. Her birinde $\{v_1,v_2\}, \dots, \{v_{n-1},v_n\}, \{v_n,v_1\}$ kenarları vardır ve köşegen yoktur.

**Soru 8** (ekrandan, 01:40:00): $K_3$ iki parçalı graf mıdır? $C_6$ iki parçalı graf mıdır?

> **Çözüm:** $K_3$ iki parçalı değildir. $C_6$ iki parçalıdır; kümeler $\{1, 3, 5\}$ ve $\{2, 4, 6\}$'dır.

**Soru 9** (ekrandan, 01:45:00): Königsberg köprü probleminde, yedi köprüden sadece bir kez geçerek başlangıç noktasına dönmek mümkün müdür?

> **Çözüm:** Graf düğüm dereceleri A: 3, B: 3, C: 3, D: 5'tir. Euler döngüsü için bütün derecelerin çift olması gerekir. Bu şart sağlanmadığı için mümkün değildir.

**Soru 10** (derste sözlü, 01:50:22): Her birinin derecesi 6 olan 10 düğümlü bir grafın kaç kenarı vardır?

> **Çözüm:** El sıkışma teoremiyle $2e = 10 \cdot 6 = 60$, yani $e = 30$.

**Soru 11** (ekrandan, 02:30:00): Bölüm 18.1'deki 6 düğümlü grafta a'dan f'ye en kısa yolu Dijkstra algoritmasıyla bulunuz.

> **Çözüm:** En kısa yol a, b, e, d, f ve maliyeti $2 + 2 + 1 + 2 = 7$'dir.

**Soru 12** (ekrandan, 02:35:00): Bölüm 18.2'deki 6 düğümlü, 10 kenarlı grafta $u_0$'dan $u_3$'e en kısa yol nedir?

> **Çözüm:** $u_0$, $u_5$, $u_4$, $u_3$; maliyet $8 + 7 + 5 = 20$.

**Soru 13** (ekrandan, 02:40:00): Bölüm 18.3'teki 12 düğümlü grafta a'dan l'ye en kısa yolu bulunuz.

> **Çözüm:** a, e, j, k, l; maliyet $2 + 3 + 2 + 1 = 8$.

**Soru 14** (ekrandan, 02:50:00): Bölüm 19.3'teki $u$ ve $v$ grafları izomorfik midir?

> **Çözüm:** Evet. Her iki grafta 4 düğüm, 4 kenar vardır ve her düğümün derecesi 2'dir. $u_2$ ve $u_4$'ün satır ve sütunları yer değiştirince $u$ grafının komşuluk matrisi $v$ grafınınkiyle aynı olur. Eşleme $u_1 \to v_1$, $u_2 \to v_4$, $u_3 \to v_3$, $u_4 \to v_2$'dir.

## Dersin Toparlaması

Ders ağaçlarla başladı ve graflarla devam etti. Önce ikili arama ağacının sıralı veride dengesiz kaldığı ve döndürmeyle dengelenebileceği gösterildi. Bir ızgara üzerinde BFS'nin kuyrukla halka halka, DFS'nin yığınla bir yönde derine ilerlediği görüldü. Minimum kapsayan ağaç için Prim (düğüm seçerek) ve Kruskal (sıralı kenar seçerek) algoritmaları ele alındı; ikisinde de her eklemede çevrim kontrolü yapılır. Karar ağaçlarında kökün entropi ve bilgi kazancıyla, en ayırt edici özellik olarak seçildiği anlatıldı. Ağaçlarda izomorfizm için düğüm sayısı, kenar sayısı, dereceler ve derinlik kontrolleri verildi.

Graflar bölümünde temel tanımlar, basit, çoklu, pseudo, ağırlıklı ve yönlü graflar, özel graflar ($K_n$, $C_n$, $W_n$, $Q_n$, $K_{m,n}$) ve iki parçalı graflar işlendi. Euler döngüsünün bütün derecelerin çift olmasına bağlı olduğu Königsberg problemiyle, Hamilton döngüsü gezgin satıcı problemiyle açıklandı. Grafların komşuluk listesi ve matrislerle saklanması, matris kuvvetleriyle yol sayımı, BFS/DFS ile bağlı bileşen bulma ve Dijkstra en kısa yol algoritması örneklerle gösterildi. Son olarak graf modelleri, düzlemsel graflar, matris satır ve sütun değişimiyle graf izomorfizmi ve ağ topolojileri ele alındı. Hoca, graf boyama ve sonlu durum makineleri konularının bir sonraki derste işleneceğini söyledi. Euler ve Hamilton ile ilgili slaytta olmayan bazı kurallara da sonraki derste değinileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
