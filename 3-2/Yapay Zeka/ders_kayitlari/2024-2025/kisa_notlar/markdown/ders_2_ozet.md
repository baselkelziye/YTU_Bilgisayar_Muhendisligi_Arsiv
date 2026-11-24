# Ders 2 Çalışma Özeti

## Genel Konular

- Arama problemlerinin temel tanımları
  - Durum uzayı (state space, arama uzayı, arama ağacı): durumları, aralarındaki geçişleri, geçiş parametrelerini ve kısıtları gösteren graf ya da ağaç.
  - Operatörler durumlar arası geçişi sağlar. Başlangıç durumu $S_0$ aramanın başladığı durumdur (kök düğüm gibi düşünülür), hedef durumu $\{G\}$ aramanın bittiği durumdur.
  - Maliyet (cost) bir operatörü uygulamanın maliyetidir. Çözüm yolu (solution path) başlangıçtan hedefe giden yoldur. En düşük maliyetli çözüm yolu optimal yoldur.
  - Durum uzayı en baştan elde hazır değildir. Arama ilerledikçe ağaç açılır, "karanlıkta ilerledikçe haritası açılan oyun" gibi.
- Arama neden zordur?
  - Dallanma sayısı $b=10$, saniyede 1000 durum işlenmesi ve durum başına 100 bayt bellek varsayımıyla derinlik $d$ arttıkça işlenen durum sayısı $\sum_{i=0}^{d} 10^i$ olur (ekrandan, 00:15:00).
  - Derinlik 2 → 111 durum, 0.1 saniye, 11 KB; derinlik 4 → 11.111 durum, 11 saniye, 1 MB; derinlik 8 → $10^8$ durum, 31 saat, 11 GB; derinlik 12 → $10^{12}$ durum, 35 yıl, 111 TB.
  - İşlemciyi $10^9$ kat hızlandırmak tam çözüm değildir; derinlik biraz daha artınca süre yine yıllara çıkar. Graf yapısında döngüler (cycle) sorunu daha da büyütür.
  - 8-bulmaca (8-puzzle) örneği: ortalama adım sayısı 22, ortalama dallanma sayısı 2,67, tekil olmayan yaklaşık 2,7 milyar durum (ekrandan, 01:25:00).
- Arama stratejilerinin değerlendirme ölçütleri (ekrandan, 00:20:00)
  - Tamlık (completeness): çözüm varsa mutlaka bulunması.
  - Zaman karmaşıklığı: aramanın alacağı süre.
  - Hafıza karmaşıklığı: arama için gereken ek bellek (problemi tanımlayan verinin kendisi değil).
  - Optimumluk: ilk bulunan çözümün en düşük maliyetli çözüm olması.
  - Parametreler: $b$ maksimum dallanma sayısı, $d$ en az maliyetli çözümün derinliği, $m$ arama uzayının maksimum derinliği (bazen $\infty$).
- Kör (bilgisiz, uninformed, blind) arama algoritmaları
  - Problemin tanımı dışında hiçbir ek bilgi kullanmazlar.
  - Enlemesine arama (BFS): kuyruk (ilk giren ilk çıkar) kullanır.
  - Derinlemesine arama (DFS): yığın (son giren ilk çıkar) kullanır.
  - Düşük maliyetli arama (Uniform Cost Search): kökten itibaren toplam maliyeti en küçük düğümü açar (öncelikli kuyruk).
  - Sınırlı derinlikte arama (depth-limited) ve artan derinlikli arama (iterative deepening).
  - İki yönlü arama (bidirectional): başlangıçtan ve hedeften aynı anda arama.
- Tekrarlayan durumlar (repeated states)
  - Daha önce görülen durumlar kontrol edilmezse algoritma döngüye girebilir ve çözüme hiç ulaşamayabilir.
- Arama algoritmalarının MATLAB benzetimi
  - Rastgele üretilen şehir ve yol haritasında BFS, DFS, UCS, A* ve en iyi ilk arama karşılaştırılır; adım sayısına göre liste (kuyruk) boyutu çizilir.
- Sezgisel (heuristic) aramaya giriş
  - Sezgisellik: durum uzayı çok büyük olduğunda aramayı sınırlayan kural, strateji, hile ya da sadeleştirme.
  - En iyi ilk arama (best-first search): değerlendirme fonksiyonuna göre en "iyi" görünen düğümü açar. Açgözlü (greedy) sürümde $f(n)=h(n)$.
  - Romanya haritasında Arad'dan Bükreş'e kuş uçuşu uzaklıkla açgözlü arama örneği.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hafıza karmaşıklığı problemi tanımlamak için tutulan veri değildir
  - Algoritmanın problemi çözmek için ihtiyaç duyduğu ek bellektir. Hoca bunun sıkça yanlış anlaşıldığını belirtti.
- BFS'nin asıl sorunu bellektir
  - Zaman ve bellek $O(b^{d+1})$'dir; bir seviye daha inmek bütün yeni seviyeyi belleğe alır. Hoca "belleği çok kötü kullanan bir algoritma" dedi.
- BFS yalnız tüm adım maliyetleri eşitse optimaldir
- DFS bellek açısından doğrusaldır ama optimal değildir
  - İlk bulduğu çözüm, uğramadığı daha sığ ve ucuz bir çözümden pahalı olabilir.
- UCS'nin optimalliği pozitif maliyet şartına bağlıdır
  - Negatif kenar maliyetleri (örneğin enerjinin geri kazanıldığı durumlar) varsa optimal sonucu vermeyebilir.
- Artan derinlikli arama, DFS'nin belleğiyle BFS'nin tamlık ve optimalliğini birleştirir
  - Üst seviyeler defalarca gezilir ama ek maliyet küçüktür ($b=10$, $d=5$ için yaklaşık %11).
- Açgözlü en iyi ilk arama optimal değildir
  - Geçmiş maliyeti hesaba katmaz; döngü kontrolü yoksa takılabilir. A* hem geçmiş maliyeti hem sezgisel tahmini kullanacak.
- Yapay zekanın bakış açısı: kesin çözüme ulaşılamıyorsa en iyi bilinen yaklaşık çözümü kullanmak
  - Hoca bunu bilimin "gerçeğe yaklaşma" (approximation to the truth) doğasına benzetti.

## Kısa Tekrar Notları

- $b$: dallanma sayısı, $d$: en sığ (en az maliyetli) çözümün derinliği, $m$: maksimum derinlik.
- BFS: tam (b sonluysa), zaman ve bellek $O(b^{d+1})$, adım maliyetleri eşitse optimal. Kuyruk.
- DFS: sonsuz derinlikte ya da döngüde tam değil (sonlu uzayda ve tekrar kontrolüyle tam), zaman $O(b^m)$, bellek $O(bm)$, optimal değil. Yığın.
- UCS: maliyete göre sıralı öncelikli kuyruk; tam ve pozitif maliyetlerde optimal; yaklaşık $O(b^d)$ zaman ve bellek.
- Sınırlı derinlik ($l$): tam değil (çözüm $l$'den derindeyse bulunamaz), optimal değil, zaman $O(b^l)$.
- Artan derinlik: tam, eşit maliyette optimal, zaman $O(b^d)$, bellek $O(bd)$.
- İki yönlü arama: $O(b^{d/2})$ zaman ve bellek, eşit maliyetlerde optimal; pek kullanılmaz.
- BFS'den DFS'ye geçmek yalnız belleği iyileştirir, optimalliği kaybettirir.
- Artan derinlikli aramada DFS yerine BFS kullanmak kötü fikirdir: bellek kötüleşir, zaman ve optimallikte kazanç yoktur.
- Açgözlü en iyi ilk arama: $f(n)=h(n)$, $h_{SLD}$ kuş uçuşu uzaklık; tam değil, optimal değil, zaman ve bellek $O(b^m)$.

## Detaylı Açıklamalar

- **BFS örneği (ekrandan, 00:35:00).** Ağaç: 1'in çocukları 2 ve 3; 2'nin 4 ve 5; 3'ün 6 ve 7; 4'ün 8 ve 9; 5'in 10 ve 11. Hedef 6. Kuyruk sırasıyla (1), (2 3), (3 4 5), (4 5 6 7), (5 6 7 8 9), (6 7 8 9 10 11) olur ve 6 kuyruktan çekildiğinde bulunur. Durum açma sırası 1, 2, 3, 4, 5, 6'dır; çözüm yolu ise 1, 3, 6'dır. Hoca bu ikisinin farklı şeyler olduğunu vurguladı.
- **DFS örneği.** Aynı ağaçta liste yığın gibi kullanılır, son eklenen ilk çekilir. Derste anlatılan sıra: 1, 2, 5, 11, 10, 4, 9, 8, 3, 7, 6. Liste ağacın derinliğine doğru sınırlı kalır, BFS'deki gibi bütün bir seviye belleğe alınmaz.
- **UCS örneği (ekrandan, 00:50:00).** Kenarlar: A-B 1, A-C 4, A-D 15, B-F 10, C-E 5, E-F 1, D-F 1. Hedef F.
  - B,C,D: min(1, 4, 15) = 1 → B açılır.
  - F,C,D: min(10+1, 4, 15) = 4 → C açılır.
  - F,E,D: min(11, 4+5, 15) = 9 → E açılır.
  - F,F,D: min(11, 9+1, 15) = 10 → F çekilir, hedef bulundu. Yol A-C-E-F, maliyet 10 (python ile doğrulandı).
  - F kuyruğa iki kez girer (11 ve 10 maliyetle); ilk çekilen F en ucuzudur.
- **Artan derinlikli aramanın ek maliyeti.** Sınırlı derinlikli arama $d$ derinliğe kadar $b^0+b^1+\dots+b^d$ düğüme bakar. Artan derinlikte kök $d+1$ kez, birinci seviye $d$ kez, ..., son seviye bir kez gezilir. $b=10$, $d=5$ için 111.111'e karşı 123.456 düğüm, yani yaklaşık %11 fazlalık (python ile doğrulandı). Hoca farklı $b$ ve $d$ değerleri için bu oranın nasıl değiştiğinin incelenmesini önerdi.
- **Tekrarlayan durumlar.** A'dan D'ye, D'den E'ye, E'den A'ya ve F'ye geçilen bir grafta, A'dan başlayan DFS hedef F iken E'den A'yı tekrar listeye eklerse A-D-E-A döngüsüne girer. Çözüm: bir düğüme uğrandıysa işaretlemek, listede ya da yolda zaten varsa yeniden eklememek. Slaytta "tekrarlayan durumları fark etmemek doğrusal bir problemi üssel bir probleme çevirebilir" denir (ekrandan, 01:05:00).
- **Genel ağaç arama yapısı (ekrandan, 01:10:00).** Fringe (sınır listesi) başlangıç düğümüyle doldurulur; döngüde boşsa başarısızlık döner, öndeki düğüm çekilir, hedefse döner, değilse açılıp çocukları listeye eklenir. Stratejiyi belirleyen şey düğüm açma sırasıdır.
- **MATLAB benzetimi (ekrandan, 01:35:00).** Rastgele üretilen yaklaşık 18 şehirlik haritada algoritmalar çalıştırılıp adım sayısına göre liste boyutu çizildi. UCS en çok adımı ve en büyük listeyi kullanır ama optimal sonucu verir. DFS'nin listesi bir yere kadar artıp sonra yatay kalır (doğrusal bellek). DFS'nin bulduğu yolun hedefe yaklaşıp sonra saptığı görüldü; bu, optimal olmadığının göstergesidir.
- **Olası dünyalar (ekrandan, 01:40:00).** Her gün iki seçenekli bir karar verilirse 32 gün sonra $2^{32}\approx 4{,}3$ milyar olası dünyadan birinde yaşarız. Bu, durum uzayının ne kadar hızlı büyüdüğünü anlatan bir örnektir.
- **Açgözlü en iyi ilk arama, Romanya örneği (ekrandan, 01:55:00).** Bükreş'e kuş uçuşu uzaklıklar: Arad 366, Sibiu 253, Timisoara 329, Zerind 374, Fagaras 176, Bükreş 0. Arad'dan Sibiu (253) seçilir, Sibiu'dan Fagaras (176), Fagaras'tan Bükreş (0). Bulunan yol Arad-Sibiu-Fagaras-Bükreş'tir. Hocanın gösterdiği optimal yol $140+80+97+101=418$ maliyetlidir (büyük olasılıkla Arad-Sibiu-Rimnicu Vilcea-Pitesti-Bükreş) ve daha kısadır; UCS bunu bulurdu.
  - Ders sonrası not: hoca bulunan yolun maliyetini "140 + 99 + 213" diye söyledi; ders kitabındaki haritada Fagaras-Bükreş büyük olasılıkla 211'dir, yani toplam 450 olur. Her iki durumda da 418'den büyüktür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
