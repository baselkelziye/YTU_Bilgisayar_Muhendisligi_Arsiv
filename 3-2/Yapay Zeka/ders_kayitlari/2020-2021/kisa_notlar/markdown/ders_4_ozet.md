# Ders 4 Çalışma Özeti

## Genel Konular

- Kör arama algoritmalarının tekrarı
  - Altı kör arama algoritması dört kritere göre hatırlandı: tamlık, zaman karmaşıklığı, hafıza karmaşıklığı ve optimallik (ekrandan, 00:15:00).
  - Enlemesine arama ile derinlemesine arama arasındaki tek algoritmik fark, yeni üretilen durumların dizinin sonuna (kuyruk, ilk giren ilk çıkar) ya da başına (yığın, son giren ilk çıkar) eklenmesidir.
  - Derinlemesine arama sonsuz derinlikli uzayda aşağı doğru sonsuza kadar inebileceği için tam değildir. Enlemesine arama tamdır.
  - Enlemesine arama yalnız bütün operatör maliyetleri eşitse optimaldir. Düşük maliyetli arama maliyetler farklı olsa bile optimaldir. Maliyetler eşitse ikisi aynı algoritmadır.
  - Sınırlı derinlikte arama sonsuz döngüye girmez, ama çözüm sınırın dışındaysa bulamaz. Maliyetler eşit olsa bile optimal değildir.
  - Artan derinlikli arama, enlemesine arama gibi maliyetler eşitse optimaldir, tamdır ve hafıza gereksinimi doğrusal artar.
  - Çift yönlü arama iki uçtan enlemesine arama yapar. Arama derinliği $d$'den $d/2$'ye iner; maliyet $b^d$ yerine $2\,b^{d/2}$ olur.
- `my_search.m` uygulamasının tekrarı (ekrandan, 00:20:00)
  - 12. şehirden 1. şehre yol: enlemesine 12-4-2-5-1, düşük maliyetli 12-9-15-7-1, derinlemesine 12-11-9-15-18-17-13-10-7-14-8-5-1, A* 12-9-15-7-1, ilk en iyi 12-9-15-18-1.
  - Maliyetler: dfs=314, bfs=128, ucs=110, ilk en iyi=110, A*=110. Adım sayıları: dfs=24, bfs=37, ucs=79, ilk en iyi=5, A*=6.
  - Kör algoritmaların hiçbiri o anki durumun hedefe ne kadar yakın olduğu bilgisini kullanmaz. Derinlemesine aramanın yolu bu yüzden hedefe bir yaklaşıp bir uzaklaşır.
- Sezgi (heuristic) kavramı
  - Arama algoritması, kuyruktaki durumlardan hangisinin seçileceğini belirleyen stratejidir. Şimdiye kadar seçim mekanikti (baştakini ya da sondakini al) ya da köke olan maliyete göreydi (düşük maliyetli arama).
  - Sezgi, bir durumun hedefe olan **tahmini** uzaklığıdır. Gerçek uzaklığı bilmek için hedefe giden yolu bilmek gerekir; yol bilinseydi arama yapmaya gerek kalmazdı.
  - Sezgisel algoritmalar optimal algoritmalardan daha iyi bir çözüm bulamaz. Aynı maliyette çözümü çok daha hızlı (ve daha az hafızayla) bulurlar.
  - Sezgisel arama için fazladan bir bilgi gerekir. Şehirler arası yolda bu, her şehrin hedefe kuş uçuşu mesafesidir. Bu bilgi elde edilemiyorsa kör arama kullanılmak zorundadır.
- Sezgisel arama algoritmaları (ekrandan, 00:30:00)
  - İlk en iyi arama (best-first search), A* arama, lokal arama algoritmaları (tepe tırmanma, rastgele başlangıçlı tepe tırmanma, paralel tepe tırmanma / local beam search, benzetimli tavlama, genetik algoritmalar). Bu derste ilk ikisi işlendi; lokal arama sonraki derslere kaldı.
- İlk en iyi arama (best-first search)
  - Algoritmanın yapısı önceki arama algoritmalarıyla aynıdır. Tek fark, kuyruktaki durumlara bir değerlendirme fonksiyonuna göre puan verilmesi, durumların küçükten büyüğe sıralanması ve ilkinin çekilmesidir (ya da doğrudan en küçüğü seçilir).
  - Değerlendirme fonksiyonu $f(n) = h(n)$: mevcut durumun hedefe tahmini uzaklığı. Algoritma her adımda hedefe en yakın **görünen** duruma ilerler, o ana kadar gelinen yola bakmaz.
  - Romanya örneği, Arad'dan Bükreş'e (ekrandan, 00:35:00 ve 00:40:00): Arad (366) açılır; Sibiu 253, Timisoara 329, Zerind 374 arasından Sibiu seçilir. Sonra Fagaras (176), sonra Bükreş (0) seçilir. Bulunan yol Arad-Sibiu-Fagaras-Bükreş (maliyet 450) optimal değildir.
  - Analiz (ekrandan, 00:45:00): tam değil (hedefe aynı mesafedeki iki durum arasında sonsuz döngüye girebilir), zaman $O(b^m)$ ama iyi sezgisel kurallar büyük iyileşme sağlayabilir, hafıza $O(b^m)$ (tüm durumlar hafızada), optimal değil.
- A* arama
  - $f(n) = g(n) + h(n)$. $g(n)$ kökten mevcut duruma gelişin gerçek maliyeti, $h(n)$ mevcut durumdan hedefe gidişin tahmini maliyeti, $f(n)$ ise kökten hedefe $n$'den geçerek gidişin tahmini maliyetidir.
  - $f(n) = g(n)$ alınırsa algoritma düşük maliyetli aramaya, $f(n) = h(n)$ alınırsa ilk en iyi aramaya dönüşür.
  - Romanya örneği (ekrandan, 00:50:00 ve 00:55:00): Arad $366=0+366$; Sibiu $393=140+253$; Rimnicu Vilcea $413=220+193$; Fagaras $415=239+176$; Pitesti $417=317+100$; Bükreş $418=418+0$. Fagaras açıldığında kuyruğa giren Bükreş ($450=450+0$) hemen seçilmez. Bulunan yol Arad-Sibiu-Rimnicu Vilcea-Pitesti-Bükreş (418) optimaldir.
  - Aynı şehre farklı yollardan gelişler A*'da farklı durumlardır ve farklı $f$ değerleri alır (iki Sibiu: 591 ve 553; iki Bükreş: 450 ve 418). İlk en iyi aramada ikisinin de değeri aynı olurdu (Sibiu için 253).
- Labirentte yol bulma (ekrandan, 01:15:00)
  - $S$'den $G$'ye, engeller arasından. Sezgi olarak Manhattan uzaklığı kullanılır: engeller yokmuş gibi yatay ve dikey adım sayısı.
  - İlk en iyi arama yalnız $h$'ye baktığı için hedefe doğru görünen kola girer ve optimal olmayan uzun bir yol bulur.
  - A* durumlara $h+g$ etiketi verir. Yanlış kolda $g$ büyüdükçe $f$ değerleri artar ve algoritma optimal yolu açar.
- A*'ın analizi
  - Tam: döngüye girmez, çünkü aynı yerden tekrar geçildiğinde $g(n)$ artar ve aynı durum giderek daha büyük $f$ değeri alır.
  - Zaman ve hafıza $O(b^m)$ (tüm durumlar hafızada), ama iyi sezgisel kurallar büyük iyileşme sağlar.
  - Optimal, ama değerlendirme fonksiyonuna bağlı: $h(n)$ iyimser (gerçek maliyetten küçük ya da eşit) olmalıdır.
  - Kuş uçuşu mesafe ve labirentteki Manhattan uzaklığı iyimser tahminlerdir.
- 8 taş için sezgisel kurallar (ekrandan, 01:35:00)
  - $h_1(n)$: yerinde olmayan taşların sayısı. $h_2(n)$: taşların hedef yerlerine Manhattan uzaklıkları toplamı.
  - Başlangıç 7 2 4 / 5 _ 6 / 8 3 1, hedef _ 1 2 / 3 4 5 / 6 7 8 için $h_1(S) = 8$, $h_2(S) = 3+1+2+2+2+3+3+2 = 18$.
  - $h_1$ taşlar ışınlanabiliyormuş gibi, $h_2$ arada engel yokmuş gibi hesaplar. İkisi de iyimserdir.
- Baskınlık (dominance) (ekrandan, 01:45:00)
  - İki geçerli (iyimser) sezgisel kural için her durumda $h_2(n) \ge h_1(n)$ ise $h_2$, $h_1$'e baskındır ve arama için daha uygundur.
  - 8 taş için ortalama test edilen durum sayısı: $d=12$'de IDS 3.644.035, A*($h_1$) 227, A*($h_2$) 73 düğüm; $d=24$'te IDS "çoook", A*($h_1$) 39.135, A*($h_2$) 1.641 düğüm.
- Esnetilmiş problemler
  - Orijinal problemden daha az kısıt içeren problemlerdir. 8 taşta taş istediği yere gidebilirse $h_1$, engel olsa da istediği komşuya gidebilirse $h_2$ en kısa çözümü verir.
  - Alıştırma: yedi gözlü dizide üç siyah ve üç beyaz taş; atlama maliyeti 2, boş komşuya kayma maliyeti 1; hedef tüm beyazların siyahların solunda olması. Hangi $h$ önerilebilir?
- A* arama tablosu (ekrandan, 01:55:00 ve 02:05:00)
  - Dizinin her satırı bir zaman anıdır. Her hücre bir durumdur: o ana kadarki yol, son şehir ve $h+g$.
  - Graf: S-A 3, S-D 4, A-B 4, A-D 5, B-C 4, B-E 1, D-E 5, E-F 4, F-G 3. $h$: S 11, A 10.4, B 6.7, C 4.0, D 8.9, E 6.9, F 3.0, G 0.
  - Çekilme sırası: S, SD (12.9), SA (13.4), SAB (13.7), SABE (14.9), SABC (15), SABEF (15), SABEFG (15). Yol S-A-B-E-F-G, maliyet 15.
  - Eşit $f$ değerleri arasında seçim rastgeledir.
  - Kuyruk heap ile sıralı tutulursa en küçük eleman her seferinde arama yapmadan çekilir; güncelleme maliyeti logaritmiktir.
- A*'ın optimalliğinin ispatı (ekrandan, 02:20:00 ve 02:25:00)
  - $G$ optimal, $G_2$ optimal olmayan bir çözüm; $n$ optimal yola götüren ve kuyrukta bekleyen bir durum. $f(n) < f(G_2)$ gösterilirse $n$ her zaman $G_2$'den önce seçilir.
  - $f(G_2) = g(G_2)$ ve $f(G) = g(G)$ (çünkü $h=0$); $g(G_2) > g(G)$, dolayısıyla $f(G_2) > f(G)$.
  - $h(n) \le h^*(n)$; iki tarafa $g(n)$ eklenince $f(n) \le f(G)$; sonuç $f(n) < f(G_2)$.
- İkinci graf üzerinde karşılaştırma (02:31:41 civarı)
  - Derinlemesine 518, enlemesine ve ilk en iyi 153 maliyetli yol buldu; optimal yolu düşük maliyetli arama ve A* buldu. Adımlar: A* 7, ilk en iyi 4, düşük maliyetli 14, enlemesine ve derinlemesine 10. <!-- BELİRSİZ: Optimal yolun maliyeti altyazıda "%22 kilometre" diye geçiyor; bu ana ait kare yok. -->

## Hocanın Özellikle Vurguladığı Kısımlar

- Sezgisel arama daha iyi bir çözüm bulmaz, çözümü daha hızlı bulur
  - Optimal çözümü zaten düşük maliyetli arama bulur. A* aynı maliyette çözümü örneğin 10 dakika yerine 10 saniyede bulur.
- A*'ın optimal olması için $h$ iyimser olmalıdır
  - İyimser, gerçek maliyetten fazla tahmin etmemek demektir. Kötümser bir $h$ ile A* optimal değildir.
- İyimser kurallar arasında en kötümseri (gerçeğe en yakını) seçilmelidir
  - Bütün $h$ değerleri eşit (aşırı iyimser) olursa A* düşük maliyetli aramaya dönüşür. Optimalliği bozulmaz, ama hızını kaybeder.
- Sınavlarda kuyruk (dizi) içeriği gösterimi istenir
  - Arama ağacı değil, dizinin her zaman anındaki içeriği adım adım elle yazılmalıdır. Hoca bunu elle bol bol çalışmayı önerdi.
- İspatta eşitsizlik kesin olmalıdır
  - $f(n) \le f(G_2)$ yetmez; eşitlikte rastgele seçim $G_2$'yi seçebilir. $f(n) < f(G_2)$ gösterilmelidir.
- 8 taş tablosunda asıl fark IDS ile A* arasındadır
  - $h_1$ ile $h_2$ arasındaki fark, IDS ile A* arasındaki farkın yanında küçüktür.

## Kısa Tekrar Notları

- Sezgi $h(n)$: durumun hedefe tahmini uzaklığı. Gerçek uzaklık bilinemez.
- İlk en iyi arama: $f(n)=h(n)$. Tam değil, optimal değil, zaman ve hafıza $O(b^m)$.
- A*: $f(n)=g(n)+h(n)$. Tam; $h$ iyimserse ve maliyetler pozitifse optimal.
- $f=g$ ise düşük maliyetli arama, $f=h$ ise ilk en iyi arama.
- Romanya: ilk en iyi arama 450'lik yolu, A* 418'lik optimal yolu bulur.
- Kuş uçuşu mesafe ve Manhattan uzaklığı iyimserdir.
- 8 taş: $h_1$ yerinde olmayan taş sayısı, $h_2$ Manhattan toplamı. $h_2 \ge h_1$ olduğu için $h_2$ baskındır ve daha hızlıdır.
- Esnetilmiş problemin kesin çözüm maliyeti, orijinal problem için iyimser bir sezgidir.
- A*'da aynı şehre farklı yollardan gelişler farklı durumlardır.
- A* hafıza bakımından derinlemesine arama kadar iyi değildir; az adımda bitmesi onu kurtarır.
- Optimallik ispatı: $f(G_2)>f(G)\ge f(n)$.

## Detaylı Açıklamalar

- **Neden sezgi?** Kör algoritmalarda kuyruktan çekilecek durum ya sıraya göre ya da köke uzaklığa göre seçilir. `my_search.m` örneğinde derinlemesine arama 18. şehre gelip hedefe bir adım kalmışken 17'ye gider, çünkü hedefe yakınlık bilgisini kullanmaz. Sezgisel algoritmalar bu bilgiyi bir tahmin olarak kullanır. Uygulamada düşük maliyetli arama 79 adımda, A* 6 adımda aynı 110'luk yolu buldu; az adım daha küçük liste (hafıza) demektir.
- **İlk en iyi arama ve açgözlülük:** Romanya haritasında Sibiu'dan sonra Fagaras 176 ile hedefe en yakın göründüğü için açılır ve Bükreş kuyruğa girer girmez seçilir. Yol 140+99+211 = 450 olur. Oysa Rimnicu Vilcea ve Pitesti üzerinden 140+80+97+101 = 418'lik yol vardır. İlk en iyi arama "ne kadar yol geldim" bilgisini hiç kullanmadığı için bu yolu kaçırır. Kuyruktaki eleman sayıları adım adım 1, 3, 6, 7'dir.
- **A* adım adım:** Arad açılınca Sibiu (393), Timisoara (447), Zerind (449) gelir; Sibiu seçilir (kuyrukta 6 eleman). Rimnicu Vilcea 413 ile seçilir (8 eleman), sonra Fagaras 415. Fagaras'tan gelen Bükreş 450'dir, ama Pitesti 417 daha küçüktür ve önce o açılır (11 eleman). Pitesti'den gelen Bükreş 418 ile en küçük değerdir ve seçilince arama biter. Sonuç python ile kontrol edildi.
- **Kuyrukta tekrarları silmek:** Bir öğrenci aynı şehirden birden fazla varsa yalnız ucuz olanı tutmayı önerdi. Hoca bunun yapılabileceğini, ama her eklemede 100 bin elemanlık diziyi taramanın maliyetli olacağını söyledi. Pahalı kopya ucuz olanın önüne zaten geçemez. Klasik A*'da böyle bir kontrol yoktur; problemlere özgü varyantlarda olabilir.
- **Labirent:** (b) şıkkında her hücreye G'ye Manhattan uzaklığı yazılmıştır. (c) şıkkında ilk en iyi arama 6, 6, 8 komşularından 6'ları seçerek ilerler. Engelin öbür tarafında kalan hücrelerin $h$ değerleri daha büyük olduğu için optimal kol hiç açılmaz. (d) şıkkında A* hücrelere $h+g$ yazar (ör. 8+1, 6+3). Yanlış kolda $g$ büyüdükçe değerler artar (3+6, 2+7, 3+8, 4+9). Bir noktadan sonra 4+9 yerine 8+3 açılır ve algoritma G'ye giden optimal yolu bulur.
- **İyimserlik ve 8 taş:** $h_2$ için 1 taşı 3 adım uzakta görünür. Gerçekte arada başka taşlar olduğu için en az 7-8 hamle gerekir. $h_1$ değeri $k$ ise $h_2$'de $k$ tane sayı toplanır ve her biri en az 1'dir; bu yüzden her durumda $h_2 \ge h_1$. $h_2$, $h_1$'den daha kötümserdir ve gerçeğe daha yakındır. Slayttaki başka iki örnek: $h_1=1, h_2=1$ ve $h_1=5, h_2=1+1+1+2+2=7$.
- **8 taş tablosu ve enlemesine arama:** 8 taşta her hamlenin maliyeti eşittir. IDS, A*($h_1$) ve A*($h_2$) optimal çözümü bulur. Yollar farklı olabilir, ama uzunlukları ve maliyetleri aynıdır. Tabloda enlemesine arama yerine IDS olmasının nedeni hafızadır. Enlemesine arama IDS'in çektiği düğüm sayısını en fazla yarıya indirir, ama 1,8 milyon düğümü hafızada tutmak gerekir; $d=24$'te bellek yetmez.
- **8 taşta $g$:** Bir öğrencinin sorusu üzerine hoca anlattı: başlangıçtan gidilebilecek 4 durumun her birinin $g$ değeri 1, onlardan üretilenlerin değeri 2'dir. $h$ değerleri ayrıca hesaplanır.
- **A* tablosu:** Yeni durumlar dizinin sonuna eklenir; A* sıraya göre değil $f$'ye göre seçtiği için başa ya da sona eklemek fark etmez. SDS gibi döngülü durumlar (11+8) dizide bulunur ama $g$ büyük olduğu için açılmaz. SABC ve SABEF ikisi de 15'tir; hangisinin önce seçileceği rastgeledir. SABC'den yalnız geri dönüş (SABCB, 6.7+15) üretilir. Sonra SABEF açılır ve SABEFG (0+15) çekilince arama biter. Ders sırasında öğrenciler önceki slayttaki graf ile bu grafın kenar maliyetlerinin farklı olduğunu fark etti; bu yüzden iki slayttaki A* yolları farklıdır. <!-- BELİRSİZ: Önceki slayttaki (13'lük yol bulunan) grafın maliyetleri karelerde yok. -->
- **İspatın sezgisi:** $n$ ve $G_2$ aynı anda kuyruktaysa A*'ın $n$'i açması gerekir. $h(n) \le h^*(n)$ olduğu için $f(n)$, $n$'den geçen optimal yolun gerçek maliyetini aşmaz. $G_2$'nin $f$ değeri ise gerçek ve daha büyük maliyetidir. $h$ kötümser olsaydı $f(n) \le f(G)$ satırı yazılamazdı ve $G_2$ önce seçilebilirdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
