# Ders 11 Çalışma Özeti

## Genel Konular

- İkili arama ağacında ekleme sırası ve dengeli ağaç
  - İkili arama ağacında ilk gelen eleman köktür ve değişmez. Yeni eleman, düğümün değerinden küçük ya da eşitse sola, büyükse sağa gider. Eşitlik iki taraftan birine konabilir.
  - Artan sırada gelen elemanlar (ekrandaki dizi: 1, 3, 4, 5, 6, 10, 16, 17, 19) bağlı liste gibi tek kollu, dengesiz bir ağaç oluşturur (ekrandan, 00:15:00).
  - Ağaç döndürülerek (kök değiştirilerek) dengeli hale getirilebilir. Slayttaki örnekte 1, 3, 4 gelince 3 kök yapılır.
- BFS ve DFS ile ızgarada kör arama
  - Hoca 5 satır, 6 sütunlu bir ızgarada (2, 1) konumundaki robotun (1, 4) hedefini aramasını tahtada çözdü (ekrandan, 00:25:00).
  - Komşu sırası: önce sağ, sonra yukarı, sonra sol, sonra aşağı. Dört komşuluk kullanıldı.
  - BFS kuyruk kullanır ve başlangıcın çevresinde halka halka genişler. DFS yığın kullanır ve bir yönde duvara çarpana kadar gider.
- Minimum kapsayan ağaç: Prim ve Kruskal
  - Kapsayan ağaç bütün düğümleri içerir, kopukluk ve çevrim içermez. Minimum kapsayan ağaçta kenar ağırlıklarının toplamı en küçüktür.
  - Prim: herhangi bir düğümden başlanır, ziyaret edilen düğümlerden çıkan en ucuz kenar eklenir, çevrim oluşturan kenar alınmaz.
  - Kruskal: kenarlar ağırlığa göre sıralanır, çevrim oluşturmayan en küçük kenar seçilir. $n$ düğüm için $n-1$ kenar seçilir. Ara adımda birden fazla kopuk ağaç (orman) oluşabilir.
- Karar ağaçları
  - Beş para bulmacası: görünüşü aynı 5 paradan biri sahte, daha ağır ya da daha hafif olabilir (ekrandan, 00:50:00).
  - Makine öğrenmesinde sınıflandırma: hava durumuna göre tenis oynanıp oynanmayacağının tahmini. Kök, en ayırt edici özellik olarak entropi ve bilgi kazancı ile seçilir.
- Ağaçlarda izomorfizm
  - İki ağaç arasında birebir ve örten bir $f: T_1 \to T_2$ eşlemesi varsa ağaçlar izomorfiktir (ekrandan, 01:00:00).
  - Kontroller: düğüm sayısı, kenar sayısı, karşılıklı düğümlerin dereceleri, kökün köke eşlenmesi, çocukların konumu (derinlik).
  - $n$ düğümlü, birbiriyle izomorfik olmayan ikili ağaç sayısı $\frac{1}{n+1}\binom{2n}{n}$'dir.
- Graflara giriş ve graf türleri
  - Graf $G = (V, E)$: boş olmayan düğüm kümesi ve kenar kümesi. Kenar iki düğüm arasındaki bağıntıyı gösterir.
  - Ayrık düğüm, paralel kenar, döngü (loop), basit graf, çoklu graf, pseudo graf, ağırlıklı graf, yönlü graf.
  - Benzerlik uygulaması: programlardan çıkarılan özelliklerle Manhattan uzaklığı hesaplanıp eşik değerine göre kenar eklenmesi.
- Özel graflar
  - Tam graf $K_n$, çevre graf $C_n$, tekerlek graf $W_n$, $n$-küp $Q_n$, iki parçalı (bipartite) graf, tam iki parçalı graf $K_{m,n}$.
- Yollar, Euler ve Hamilton döngüleri
  - Euler döngüsü her kenardan bir kez geçer. Königsberg köprü problemi grafa indirgenir ve tek dereceli düğümler olduğu için çözümü yoktur.
  - Hamilton döngüsü her düğümden bir kez geçer. Gezgin satıcı problemi buna örnektir.
  - Düğüm derecesi, ayrık (isolated) ve sarkık (pendant) düğüm, el sıkışma teoremi, yönlü grafta giriş ve çıkış dereceleri.
- Grafların bilgisayarda saklanması
  - Komşuluk listesi, komşuluk matrisi, geliş (incidence) matrisi.
  - Komşuluk matrisinin $k$. kuvveti iki düğüm arasındaki $k$ uzunluklu yol sayısını verir.
- Graf uygulamaları
  - Bacon sayısı, bağlı bileşenlerin BFS/DFS ile bulunması, Dijkstra en kısa yol algoritması, öncelik grafı, düzlemsel graf, graf izomorfizmi, ağ topolojileri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağaçların oluşturulduğu gibi saklanması gerekmez
  - Hoca, ağacın döndürülerek daha dengeli ve verimli saklanabileceğini anlatmak istediğini söyledi. Slayttaki "en sağın en solu kök olur" kuralının kesin bir kural olmadığını belirtti.
- BFS ve DFS kör arama algoritmalarıdır
  - Algoritma hedefin nerede olduğunu bilmez. DFS hedefin hemen yanından geçse bile kural sırasına göre ilerler ve duvara kadar gider.
- Her eklemede çevrim kontrolü
  - Prim ve Kruskal'da her kenar eklemesinde çevrim oluşup oluşmadığına bakılır. Çevrim oluşursa ağaç olmaz.
- Euler grafının kontrolü kolaydır
  - Bütün düğüm dereceleri çiftse graf Euler grafıdır. Euler grafında Euler yolu da vardır, ama tersi her zaman doğru değildir.
- İzomorfik olmadığını göstermek daha kolaydır
  - Kontrollerden biri bozulursa graflar ya da ağaçlar izomorfik değildir. İzomorfizm için matris satır ve sütunlarının yer değiştirmesiyle eşleşme gösterilmelidir.
- Dijkstra'da yolu da saklamak gerekir
  - Maliyetle birlikte her düğüme hangi düğümden gelindiği tutulur. Bütün rotayı saklamak yerine yalnız bir önceki düğümü tutmak yeterlidir; rota geriye doğru izlenir.

## Kısa Tekrar Notları

- BFS: kuyruk, halka halka genişler. DFS: yığın, bir yönde derine gider.
- Prim düğüm seçerek, Kruskal sıralı kenar seçerek ilerler. İkisinde de çevrim yasaktır.
- $n$ düğümlü kapsayan ağacın $n-1$ kenarı vardır.
- Entropi: $H(S) = -\sum_i p_i \log_2 p_i$. 9 evet, 5 hayır için $H = 0{,}940$.
- Bilgi kazancı: $Gain(S, A) = H(S) - \sum_v \frac{|S_v|}{|S|} H(S_v)$. Rüzgar için 0,048, hava görünümü için 0,246. En yüksek kazanç kök olur.
- Basit graf: yönsüz, paralel kenarsız, döngüsüz. Çoklu graf: paralel kenar var. Pseudo graf: paralel kenar ve döngü var.
- Döngü (loop) bağıntılardaki yansıma (refleksif) özelliğine karşılık gelir.
- Kenar sayıları: $K_n$ için $\frac{n(n-1)}{2}$, $C_n$ için $n$, $W_n$ için $2n$, $K_{m,n}$ için $mn$, $Q_n$ için $n \cdot 2^{n-1}$ ($2^n$ düğüm).
- $C_6$ iki parçalıdır: $\{1,3,5\}$ ve $\{2,4,6\}$. $K_3$ iki parçalı değildir (ekrandan, 01:40:00).
- El sıkışma teoremi: $\sum_{i=1}^{n} \delta(v_i) = 2e$. Her düğümü 6 dereceli 10 düğümlü grafta 30 kenar vardır.
- Euler grafı: bütün dereceler çift. Königsberg'de dereceler 3, 3, 3, 5 olduğu için Euler döngüsü yoktur.
- Hamilton: her düğümden bir kez geçip başa dönmek. $Q_3$ Hamilton döngüsü içerir.
- Komşuluk matrisi yönsüz grafta simetriktir. Döngü yoksa köşegen sıfırdır.
- Dijkstra: başlangıçta bütün maliyetler sonsuz, kaynağınki 0. Daha kısa yol bulununca maliyet ve önceki düğüm güncellenir.
- Düzlemsel graf: kenarları kesişmeden çizilebilen graf.
- Yerel ağ topolojileri: yıldız $K_{1,n}$, halka $C_n$, hibrit $W_n$.

## Detaylı Açıklamalar

- İkili arama ağacı ve denge
  - İkili arama ağacında her karşılaştırmada ağacın yarısı elenir, tıpkı ikili aramada olduğu gibi. Ancak elemanlar sıralı geldiğinde ağaç tek kollu olur ve bu avantaj kaybolur. Bu durumda kök ve alt ağaçlar döndürülerek düğümlerin hemen hemen aynı seviyede olması sağlanır. Slayttaki animasyonda 1, 3, 4 gelince 3 kök yapıldı, sonraki elemanlar geldikçe alt ağaçlar yeniden dengelendi.
- BFS ile ızgara araması
  - Başlangıç (2, 1) kuyruğa konur. Bir düğüm ziyaret edilirken önce sağ, yukarı, sol, aşağı komşularından daha önce eklenmemiş olanlar kuyruğa eklenir, sonra kuyruğun başındaki düğüme geçilir. Ziyaret sırası (2, 1), (2, 2), (1, 1), (2, 0), (3, 1), (2, 3), (1, 2), (3, 2), (0, 1), (1, 0), (3, 0), (4, 1), (2, 4), ... şeklinde başlangıcın çevresinde genişler. Hoca örneği hedefe ulaşmadan kesti.
- DFS ile ızgara araması
  - Aynı kural sırasıyla DFS her adımda ilk uygun komşuya gider: (2, 1) → (2, 2) → (2, 3) → (2, 4) → (2, 5), sonra yukarı (1, 5) → (0, 5), sonra sola (0, 4) → ... → (0, 0), sonra aşağı. Algoritma (1, 5)'teyken hedefin hemen solunda olmasına rağmen kural sırası yukarıyı öncelediği için oraya gitmez.
- Prim algoritması örneği
  - Ekrandaki 7 düğümlü maliyet matrisinde M, komşuluk olmadığını (sonsuz) gösterir (ekrandan, 00:40:00). 1. düğümden başlanınca seçilen kenarlar sırasıyla 1-3 (100), 1-4 (300), 1-7 (400), 3-5 (500), 5-6 (200), 7-2 (900) olur. Toplam maliyet 2400'dür (python ile doğrulandı).
- Kruskal algoritması
  - Kenarlar küçükten büyüğe sıralanır. En küçük kenardan başlanır. Bir kenarın iki ucu da daha önce ziyaret edilmiş olabilir; bu iki uç aynı ağaçta değilse kenar alınabilir. Aynı ağaçtaysa kenar çevrim oluşturur ve alınmaz. Ara adımlarda birbirinden kopuk ağaçlar (orman) oluşabilir; sonunda bu ağaçlar birbirine bağlanır.
- Karar ağacı, entropi ve bilgi kazancı
  - Tenis örneğinde 14 gözlem ve 4 özellik (hava görünümü, sıcaklık, nem, rüzgar) vardır. Sınıfın entropisi 9 evet ve 5 hayır için 0,940'tır. Rüzgar özelliği zayıf (6 evet, 2 hayır, entropi 0,811) ve güçlü (3 evet, 3 hayır, entropi 1) olarak ayrılır. Bilgi kazancı $0{,}940 - \frac{8}{14} \cdot 0{,}811 - \frac{6}{14} \cdot 1 = 0{,}048$ olur. Hava görünümünün kazancı 0,246 ile en yüksektir, bu yüzden kök hava görünümüdür. Alt düğümler aynı yöntemle, yapraklar bulunana kadar seçilir.
  - Karar ağacı en iyi tahmini verir, ama her zaman yüzde yüz doğru sonuç vermez.
  - Ders sonrası not: Hoca entropi bire yaklaştıkça bilgi saflığının arttığını söyledi; doğrusu tersidir. Entropi 0 iken bütün örnekler aynı sınıftadır (saf), entropi 1 iken iki sınıf eşit dağılmıştır (en karışık).
- Graf türleri ve benzerlik uygulaması
  - Basit graf yönsüz, paralel kenarsız ve döngüsüzdür. Çoklu graf paralel kenar içerir. Pseudo graf hem paralel kenar hem döngü içerir. Ağırlıklı grafta kenarlara mesafe, maliyet, gecikme ya da kâr gibi sayısal değerler yazılır. Yönlü grafta kenarın yönü vardır ve bağıntıların simetri özelliği bu graflarda incelenir.
  - Programların satır sayısı, return sayısı ve fonksiyon çağrısı sayısı birer özellik olarak alınır. İki program arasındaki fark $s(v,w) = \sum_{k=1}^{3} |p_k - q_k|$ (Manhattan uzaklığı) ile ölçülür (ekrandan, 01:30:00). Örneğin $|66-41| + |10-20| + |2-1| = 36$. Seçilen bir eşikten küçük farka sahip programlar arasına kenar eklenir ve aynı sınıfta sayılır.
- Özel graflar
  - $K_n$'de her düğüm diğer bütün düğümlere doğrudan bağlıdır. $C_n$ ($n \ge 3$) $\{v_1,v_2\}, \dots, \{v_{n-1},v_n\}, \{v_n,v_1\}$ kenarlarından oluşur. $W_n$, $C_n$'ye ortaya bütün düğümlere bağlı bir düğüm eklenerek elde edilir. $Q_n$'nin düğümleri $n$ bitlik dizilerdir ve yalnız bir biti farklı olan düğümler komşudur (Gray kod mantığı).
  - İki parçalı grafta düğümler iki ayrık kümeye bölünür ve kenarlar yalnız iki küme arasında olur. Öğrenciler ve kulüpler arasındaki üyelik ilişkisi buna örnektir.
- Euler ve Hamilton
  - Königsberg'de bölgeler düğüm, köprüler kenar olarak alınır. A-D ve C-D arasında ikişer, D-B, A-B ve B-C arasında birer köprü vardır. Dereceler A: 3, B: 3, C: 3, D: 5 olduğu için Euler döngüsü yoktur.
  - Ders sonrası not: Hoca Euler yolu kuralını derste hatırlayamadı. Bağlı bir grafta tek dereceli düğüm sayısı tam olarak 0 ya da 2 ise Euler yolu vardır; 0 ise Euler döngüsü vardır.
- Dijkstra algoritması
  - Ekrandaki 6 düğümlü örnekte (ekrandan, 02:30:00) a'dan f'ye en kısa yol a-b-e-d-f ve maliyeti 7'dir (python ile doğrulandı). Yol bulunurken e'ye a-b üzerinden 4, a-c üzerinden 8 ile gelinebildiği görülür ve küçük olan tutulur.
  - Ders sonrası not: Hoca karmaşıklığı kenar sayısının karesi olarak söyledi. Basit gerçeklemede karmaşıklık düğüm sayısının karesi $O(V^2)$'dir; öncelik kuyruğuyla $O(E \log V)$ olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
