# Ders 21 Çalışma Özeti

## Genel Konular

- Vize sınavının birinci oturumundaki soruların çözümü.
- Graf (çizge) veri yapısı: tanım, düğüm (vertex) ve kenar (edge).
- Grafların kullanım alanları.
- Temel kavramlar: self-loop, paralel kenar, multigraf, basit graf, yol (path), çevrim (cycle), bağlantılı bileşen (connected component).
- Graf türleri: yönlü/yönsüz, ağırlıklı/ağırlıksız.
- Çevrimsiz (acyclic) graf ve ağaç ilişkisi.
- Seyrek (sparse) ve yoğun (dense) graf. İki parçalı (bipartite) graf.
- Graf gösterimleri: kenar listesi, komşuluk listesi, komşuluk matrisi.
- Asgari tarama ağacı (minimum spanning tree, MST) probleminin tanımı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınav sorularında "şeytan ayrıntıda gizlidir". "En kötü durum", "tamamı aynı sayıdan oluşan", "ilk büyük değer" gibi ifadeler dikkatle okunmalıdır.
- Soruda istenenden fazlasını yazmak puan getirmez. Fazla sayı yazmak ya da yanlış ek bilgi vermek puan kaybettirebilir.
- Graf algoritmalarının karmaşıklığı $n$ ile değil, düğüm ve kenar sayısı ($V$ ve $E$) ile ifade edilir.
- Bir grafın düzlemde nasıl çizildiği önemli değildir. Aynı düğümler ve aynı bağlantılar varsa iki çizim aynı grafı gösterir.
- Ağaçlar grafların özel bir hâlidir.
- Gerçek problemlerde genelde komşuluk listesi tercih edilir. Bir düğümün komşu sayısı, toplam düğüm sayısından çok küçüktür (örneğin Facebook'ta milyarlarca kullanıcıya karşı birkaç bin arkadaş).

## Kısa Tekrar Notları

- $G = (V, E)$: $V$ düğüm kümesi, $E$ kenar kümesi. Düğümler genelde $0$'dan $V-1$'e numaralanır. `v-w`: $v$ ile $w$ arasında kenar.
- Self-loop: düğümün kendine kenarı. Paralel kenar: aynı iki düğüm arasında birden çok kenar. Paralel kenarlı graf: multigraf.
- Basit graf (simple graph): self-loop ve paralel kenar yoktur.
- Yol (path): kenarlarla bağlı düğüm dizisi. Basit yolda düğüm tekrar etmez. Uzunluk = kenar sayısı.
- Çevrim (cycle): başlangıç ve bitişi aynı olan yol. Basit çevrimde başlangıç/bitiş dışında tekrar yoktur.
- Bağlantılı bileşen: içindeki her düğüm çiftinin arasında yol olan en büyük parça. Bir graf birden çok bileşenden oluşabilir.
- Dört graf türü: yönsüz ağırlıksız, yönlü ağırlıksız, yönsüz ağırlıklı, yönlü ağırlıklı.
- Gösterimlerin karşılaştırması:

| İşlem | Kenar listesi | Komşuluk matrisi | Komşuluk listesi |
|---|---|---|---|
| Bellek | $E$ | $V^2$ | $E + V$ |
| Kenar ekleme | $1$ | $1$ | $1$ |
| `v-w` kenarı var mı? | $E$ | $1$ | $\deg(v)$ |
| $v$'nin tüm komşularını gezme | $E$ | $V$ | $\deg(v)$ |

## Detaylı Açıklamalar

### Vize birinci oturum soruları (70 puan, 55 dakika)

Soruların sırası öğrenciden öğrenciye değiştiği için aşağıdaki numaralar derste anlatılan sırayı gösterir.

Hoca, birinci oturumun okunduğunu, ikinci oturumda kopya kontrolü için benzerlik analizinin sürdüğünü söyledi. Notlar hafta sonuna kadar girilecek.

1. **Yığınla ikilik tabana çevirme.** $n = 20$ için `n > 0` iken `n % 2` yığına itilir, `n = n / 2` yapılır. Yığına sırayla 0, 0, 1, 0, 1 girer. Boşaltılırken `10100` yazılır. Kod, verilen sayının ikilik karşılığını **bulur ve ekrana yazdırır**. "Yazdırır" denmeyen cevaplardan 1 puan kırıldı.
2. **Kuyruk ve yığın.** Kuyrukta 5, 2, 1, 4 var. Hepsi kuyruktan çıkarılıp yığına itilir. Sonra yığından çıkarılıp tekrar kuyruğa eklenir. Kuyruk 4, 1, 2, 5 olur ve bu sırayla yazdırılır. En çok hata yapılan soru buydu (çoğu kişi 5, 2, 1, 4 yazdı).
3. **`x->next = x->next->next`** (x son düğüm değil). Kod, $x$'ten sonraki düğümü listeden çıkarır. $x$'i silmez. Düğüm bellekten de silinmez, yalnız listeden erişilemez olur.
4. **Max heap'ten en büyüğü silme.** Kök 38 silinir, son eleman 19 köke gelir. 19; 37 ve 35 ile karşılaştırılır, 37 yukarı çıkar. 19; 34 ve 36 ile karşılaştırılır, 36 yukarı çıkar. 19; 14 ve 17 ile karşılaştırılır, yer değişmez. Karşılaştırmaya giren sayılar: 19, 37, 35, 34, 36, 14, 17 (7 sayı). Fazla ya da yanlış taraftaki sayıları yazmak hataydı.
5. **Base condition olmayan özyineleme.** Doğru cevap: sonsuz çalışma durumu oluşur. Pratikte çağrı yığını taşar (stack overflow). Derleme hatası vermez; "base condition tanımlanmayabilir" de yanlıştır.
6. **Yalnız ilk elemanın adresini tutan tek bağlı listeyle kuyruk.** `enqueue` en kötü durumda $O(n)$ (sona kadar gidilir). `dequeue` $O(1)$. En sık hata ikisini ters yazmaktı.
7. **Tüm elemanları aynı olan dizi.** Selection sort her durumda $O(n^2)$. Insertion sort bu dizide hiç yer değiştirmez, $O(n)$.
8. **Dairesel bağlı listenin başına ekleme.** $O(1)$. Son düğümü gösteren işaretçi tutulursa başa ve sona ekleme sabit zamanda yapılır. Araya ekleme $O(n)$'dir.
9. **BST'ye en kötü durumda ekleme.** En kötü durumda ağaç bağlı listeye dönüşür: $O(n)$. Ortalama $O(\log n)$.
10. **Rastgele yazdırma/yığın sorusu.** `i = 1..5` için rastgele 1 gelirse `i` yazdırılır, 0 gelirse yığına itilir. Sonra yığın boşaltılarak yazdırılır.
    - `1 3 5 2 4` **oluşamaz**: yığına giren sayılar küçükten büyüğe girer, büyükten küçüğe çıkar. 2 ve 4 ancak `4 2` sırasıyla yazılabilir.
    - `1 3 5 4 2` **oluşabilir**.
11. **Sırasız $A_n$ ve sıralı $B_m$ dizilerinin ortak elemanları ($n \gg m$).** $A$'daki her eleman $B$'de ikili arama ile aranır: $O(n \log m)$. İki iç içe döngü ($O(nm)$) verimsizdir.
12. **BST'de "ilk büyük değer" (inorder ardıl).** Bir düğümden büyük ilk değer, sağ alt ağacın en soldaki düğümüdür. Sağ çocuğun kendisi değildir. Sınavdaki ağaçta:
    - A'dan büyük ilk değer J'dir (C değil).
    - B'nin sağ çocuğu E'nin solu boş olduğu için B'den büyük ilk değer E'dir.
    - C'den büyük ilk değer K'dir (G değil).
13. **Ağacın yüksekliği ve eklenebilecek eleman sayısı.** Ağacın yüksekliği 4'tür (kökten M'ye 4 kenar). Yükseklik 4 olan ikili ağaç en fazla $2^5 - 1 = 31$ düğüm taşır. Ağaçta 13 düğüm (A-M) var. Yükseklik bozulmadan $31 - 13 = 18$ eleman eklenebilir. Hocanın hesabı: 3. seviyede 3 boşluk + son seviyede $16 - 1 = 15$ boşluk.

- Birinci kısmın ortalaması 50'nin üzerinde. Kod sorusu çalışmasa bile tasarıma göre kısmi puan verilecek.

### Duyurular

- Final ve bütünleme sınavları yüz yüze yapılacak. Bu karar şimdilik değişmedi.
- Finale girmeyen öğrenci FF alır. Senato kararıyla, yalnız dönem içi notla dersi geçmek artık mümkün değil.
- 15 Mayıs (seçimin ertesi günü) okullar tatil. Ders online olduğu için büyük ihtimalle yapılacak.
- Yeni ödev dersin ertesi günü verilecek. Dönem projesinin tanımı en geç bir sonraki hafta paylaşılacak.
- Ödevleri asistanlar değerlendiriyor. Ödev sonuçları asistanların duyurularından takip edilmeli.

### Graf nedir?

- Birbirine bağlı elemanlar kümesine graf denir. Graf teorisi matematiğin köklü bir alanıdır.
- Kullanım örnekleri:
  - İstanbul metro haritası: istasyonlar düğüm, raylar kenar.
  - İllerin sınır komşulukları. Örnek: Trakya illeri. Kenar ağırlıkları kilometre olursa İstanbul'dan Çanakkale'ye en kısa yol bulunabilir (en kısa yol problemi).
  - Yol kapasitesi ve trafikle en hızlı yol (maksimum akış problemi).
  - Protein-protein etkileşim ağları, web sayfaları arası bağlantılar ve arama motorları.
  - Elektronik devrelerde kısa devre analizi, PCB katman sayısı.
  - Zaman planlama ve tarifeler, eşleştirme problemleri (öğrenci-staj).
  - Bilgisayar ağlarında yönlendirme (routing), derleyiciler.
  - Sosyal ağlarda kanaat önderi ve bot ağı tespiti.

### Temel kavramlar

- Aynı düğümler ve aynı kenarlarla farklı çizilen iki graf aynı graftır.
- Bir graf dosyada şöyle saklanabilir: önce düğüm sayısı ($V$), sonra kenar sayısı ($E$), sonra her satırda bir kenar (`0 1`, `0 2`, `0 5`, ...). Derste 13 düğüm ve 13 kenarlı bir örnek kullanıldı.
- İki düğüm arasında yol varsa bu düğümler bağlıdır (connected). Yoksa bağlı değildir.
- Örnek: Marmaray yokken Anadolu ve Avrupa yakasındaki metro hatları aynı grafın iki ayrı bileşeniydi.
- Yönlü graf (directed graph, digraph): kenarın yönü vardır. `8 → 7` kenarı varsa 7'den 8'e gidilemez.
- Ağırlıklı graf: kenarların değeri (maliyet, mesafe) vardır. Yönlü ağırlıklı grafta gidiş ve dönüş maliyeti farklı olabilir.

### Çevrimsiz graf ve ağaç

- Çevrim içermeyen grafa çevrimsiz (acyclic) graf denir.
- Derste bir grafın ağaç olması için verilen özellikler:
  - $V - 1$ kenar vardır.
  - Çevrim yoktur.
  - Bağlantılıdır (tek bileşen).
  - Herhangi bir kenarı kaldırmak grafı iki bileşene böler.
  - Herhangi bir kenar eklemek çevrim oluşturur.
  - Her düğüm çiftini tek bir basit yol bağlar.
- Örnek: 19 düğüm ve 18 kenarlı, çevrimsiz ve bağlantılı bir graf bir ağaçtır.
- İkili ağaç, en fazla iki çocuk kısıtı eklenmiş bir ağaçtır.

### Seyrek ve yoğun graf

- Olabilecek bağlantı sayısına göre çok az kenarı olan graf seyrektir (sparse). Örnek: metro ağı.
- Olabilecek bağlantıların çoğunun bulunduğu graf yoğundur (dense). Örnek: Facebook arkadaşlık ağı.
- Kitaptaki örnek: 50 düğümlü iki graf. Birinde 200 kenar (seyrek), diğerinde 1000 kenar (yoğun) var.
- Ders kapsamında çoğunlukla seyrek graflarla çalışılacak.

### İki parçalı (bipartite) graf

- Düğümler iki ayrık kümeye ($U$ ve $V$) ayrılabiliyorsa ve her kenar bir uçta $U$'dan, diğer uçta $V$'den bir düğümü bağlıyorsa graf iki parçalıdır.
- Eşleştirme problemlerinde önemlidir.

### Graf gösterimleri

- **Kenar listesi:** Kenarlar bir listede tutulur. Komşuluk sorgusu için tüm kenarları gezmek gerekir. Pek tercih edilmez.
- **Komşuluk listesi:** Her düğüm için bir dizi gözü vardır. Her göz, o düğümün komşularını tutan bir bağlı listeyi gösterir. Seyrek graflar için uygundur, $O(V + E)$ yer kaplar.
- **Komşuluk matrisi:** $V \times V$ matris. `M[u][v] = 1` ise $u$'dan $v$'ye kenar vardır.
  - Yönsüz grafta matris simetriktir.
  - Self-loop yoksa köşegen 0'dır.
  - Yönlü grafta satırdan sütuna okunur ve simetrik değildir.

Derste kullanılan yönsüz örnek (5 düğüm):

```text
Komşuluk listesi        Komşuluk matrisi
1: 2 -> 5                  1 2 3 4 5
2: 1 -> 5 -> 3 -> 4     1  0 1 0 0 1
3: 2 -> 4               2  1 0 1 1 1
4: 2 -> 5 -> 3          3  0 1 0 1 0
5: 4 -> 1 -> 2          4  0 1 1 0 1
                        5  1 1 0 1 0
```

Yönlü örnek (6 düğüm): 1 → 2, 4; 2 → 5; 3 → 5, 6; 4 → 2; 5 → 4; 6 → 6 (self-loop, matriste `M[6][6] = 1`).

- Matrisin avantajı: iki düğüm arasında kenar olup olmadığı $O(1)$'de bulunur. Listede $\deg(v)$ kadar gezmek gerekir.
- Listenin avantajı: bir düğümün komşularını gezmek $\deg(v)$ sürer; matriste $V$ sürer. Bellek de daha azdır.
- Bir öğrencinin sorusu üzerine hoca, yönlü ya da yönsüz olmanın tercihi değiştirmediğini söyledi. Yönlü graflarda komşu sayısı daha az olduğu için komşuluk listesi daha da avantajlıdır.

### Asgari tarama ağacı (minimum spanning tree)

- Problem: Bir köyün muhtarı tüm evleri yollarla birbirine bağlamak istiyor. Her yolun bir maliyeti var. Toplam maliyet en az olmalı.
- Derste 4 evli küçük örnek çizildi. Tüm yollar yapılırsa maliyet 23 birim, en ucuz bağlantı ağı ise 6 birim (1 + 2 + 3) tutuyor.
- Tanım:
  - Köy yönsüz bir graf olarak modellenir: $G = (V, E)$.
  - Her $(u, v) \in E$ kenarı için bir ağırlık $w(u, v)$ atanır.
  - Tüm düğümleri bağlayan ve $w(T) = \sum_{(u,v) \in T} w(u,v)$ değeri en küçük olan $T \subseteq E$ bulunur.
- Tüm tarama ağaçları içinde ağırlık toplamı en küçük olana asgari tarama ağacı denir.
- Slayttaki örnek: 9 düğüm, 14 kenar. MST $V - 1 = 8$ kenar içerir.
- Tüm 8'li kenar alt kümelerini denemek $\binom{14}{8} = 3003$ olasılık demektir. Bu yüzden daha akıllı algoritmalar gerekir. Algoritmalar bir sonraki derste anlatılacak.

Slayttaki örnek grafın kenarları:

| Kenar | Ağırlık | Kenar | Ağırlık |
|---|---|---|---|
| a-b | 10 | d-e | 7 |
| a-c | 12 | d-g | 8 |
| b-c | 9 | d-h | 5 |
| b-d | 8 | f-h | 6 |
| c-e | 3 | g-h | 9 |
| c-f | 1 | g-i | 2 |
| e-f | 3 | h-i | 11 |

- Slaytta işaretli MST kenarları: c-f (1), g-i (2), e-f (3), d-h (5), f-h (6), b-d (8), d-g (8), a-b (10). Toplam ağırlık 43.

### Ders sonrası notlar

- **Graf yoğunluğu:** Hoca yoğunluğu "kenara bağlı düğümlerin kenar sayısına oranı" diye tanımladı ve "log V üzeri 3.2" gibi bir eşikten söz etti; bu kısım altyazıda net değil. Yaygın tanım: yönsüz basit graf için yoğunluk $D = \dfrac{2E}{V(V-1)}$. $E$, $V^2$ mertebesine yakınsa graf yoğun; $E$, $V$ mertebesine yakınsa seyrektir.
- **Ağaç özellikleri:** Listelenen özelliklerin hepsinin aynı anda sağlanması gerekmez. Bunlar birbirine denktir. Örneğin "bağlantılı ve $V-1$ kenarlı" ya da "bağlantılı ve çevrimsiz" olmak tek başına ağaç olmak için yeterlidir.
- **"Her kenar çiftini basit bir yol bağlar":** Doğrusu "her düğüm çiftini tek bir basit yol bağlar" olmalıdır.
- **$O(VE)$:** Hoca bir yerde "kenar sayısı çarpı düğüm sayısı çarpı kenar sayısı" dedi. Doğrusu yalnız $V \cdot E$'dir.
- **MST benzersizliği:** Örnek grafta c-e ve e-f kenarlarının ikisi de 3 ağırlıklıdır. Bu yüzden birden fazla MST vardır (biri e-f yerine c-e içerir). Toplam ağırlık yine 43'tür.
- **Soru 3:** Düğümü listeden çıkarmak belleği serbest bırakmaz. C'de bellek sızıntısını önlemek için çıkarılan düğüm önce geçici bir işaretçide tutulup `free` edilmelidir. Soru yalnız kodun ne yaptığını sorduğu için bu sınavda puan getirmedi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
