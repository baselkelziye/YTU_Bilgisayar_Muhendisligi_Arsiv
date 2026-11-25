# Ders 28 Çalışma Özeti

## Genel Konular

- Vektör ve matris çarpımı
  - İki vektörün çarpımı (skaler çarpım), aynı uzunluktaki $A$ ve $B$ vektörlerinin karşılıklı elemanlarının çarpımlarının toplamıdır: $A \cdot B = \sum_{i=1}^{N} A_i B_i$ (ekrandan, 00:20:00). İki vektörün de $N$ uzunlukta olması zorunludur.
  - Matris çarpımı bunun genelleştirilmiş hâlidir. $n \times m$ boyutlu $A$ ile $m \times p$ boyutlu $B$ çarpılabilir, çünkü $A$'nın satır uzunluğu ile $B$'nin sütun uzunluğu eşit olmalıdır. Sonuç $C$ matrisi $n \times p$ boyutludur.
  - $C$'nin $(i,j)$ elemanı, $A$'nın $i$. satırı ile $B$'nin $j$. sütununun vektör çarpımıdır.
  - Üç iç içe döngüyle yazılır (ekrandan, 00:20:00):
    - Dış döngü $i$: $n$ satır; orta döngü $j$: $p$ sütun; iç döngü $k$: $m$ eleman.
    - Her $(i,j)$ için `sum` önce sıfırlanır, iç döngüde `sum += A[i][k]*B[k][j]` yapılır, döngü bitince `C[i][j] = sum` yazılır.
  - Zaman karmaşıklığı: temel işlem olan çarpma $n \cdot m \cdot p$ kez yapılır. Kare matrislerde ($n=m=p$) bu $O(n^3)$ olur.
- Matris çarpımının kullanıldığı alanlar
  - Bilgisayar grafiği, oyun programlama, sanal/artırılmış gerçeklik, robotik, yapay zekâ ve derin öğrenme.
  - Robotik manipülatör (robot kol): eklemlerdeki hareketin uç noktada yarattığı konum değişimi $4 \times 4$ matrislerin art arda çarpımıyla hesaplanır (robot kinematiği).
  - Derin öğrenmede veriler matris biçiminde işlenir.
- Matris çarpımını hızlandırma
  - Böl ve yönet yaklaşımıyla $n^3$'ün altına inen algoritmalar vardır (Strassen algoritması). Mantık, $x^n$'i $x^{n/2}$ üzerinden $\log_2 n$ adımda hesaplamaya benzer.
  - Paralelleştirme (ölçeklenebilirlik): satır-sütun çarpımları birbirinden bağımsızdır, birden çok çekirdek ya da iş parçacığı aynı anda farklı çarpımları yapabilir. Tek işlemcide 1 dakika süren bir iş ideal durumda 2 işlemciyle 30 saniyeye, 3 işlemciyle 20 saniyeye iner. Karmaşıklık yine $n^3$'tür, değişen süredir.
- Matris zinciri çarpımında sıranın önemi
  - $A \cdot B \cdot C \cdot D$ farklı parantezlemelerle hesaplanabilir; sonuç aynıdır, ama yapılan çarpma sayısı değişir.
  - Örnek (ekrandan, 00:35:00): $A: 10 \times 30$, $B: 30 \times 5$, $C: 5 \times 60$.
    - $(AB)C$: $10 \cdot 30 \cdot 5 = 1500$, sonra $10 \cdot 5 \cdot 60 = 3000$; toplam 4500 çarpma.
    - $A(BC)$: $30 \cdot 5 \cdot 60 = 9000$, sonra $10 \cdot 30 \cdot 60 = 18000$; toplam 27000 çarpma.
  - Boyutlara bakarak çarpmadan önce sıra seçmek ucuz bir ön işlemdir ve büyük kazanç sağlar.
- Bellek hiyerarşisi
  - CPU kodu ve veriyi RAM'den adres, veri ve kontrol yolları (bus) üzerinden alır. CPU içinde yalnız register'lar vardır; CPU ile RAM arasında L1, L2, L3 önbellek (cache) bulunur.
  - RAM uçucudur (volatile); kalıcı veri HDD ya da SSD'de tutulur. Disk RAM'den çok yavaştır.
  - Hız karşılaştırması (ekrandan, 01:00:00): 1 GHz işlemci saniyede yaklaşık $10^9$ işlem; derste örnek alınan 10 MHz RAM $10^7$; 7200 rpm disk $7200/60 = 120$ Hz $\approx 10^2$.
  - Sistemin hızı en yavaş halka (disk) ile sınırlanır: darboğaz (bottleneck).
- Dış birleştirmeli sıralama (External Merge Sort)
  - Problem: 1 GB RAM ile 9 GB veriyi sıralamak (ekrandan, 00:50:00). Veri RAM'e sığmaz.
  - Adım 1: Veri 1 GB'lık 9 parçaya bölünür. Her parça RAM'e getirilir, yerinde sıralanır (Quick Sort gibi), diske geri yazılır. Sonuçta her parça kendi içinde sıralıdır, ama dizinin tamamı sıralı değildir.
  - Adım 2: RAM 100 MB'lık bölümlere ayrılır. Her sıralı parçanın ilk 100 MB'ı RAM'e alınır (9 bölüm), kalan bölüm çıktı tamponudur.
  - 9 yollu birleştirme (merge): her bölümün başındaki elemanlar karşılaştırılır, en küçüğü çıktı tamponuna yazılır. Tampon dolunca diskin yeni bir yerine yazılır; bir bölüm boşalınca ilgili parçanın sonraki 100 MB'ı getirilir.
  - Merge Sort'un kendisi bu ilk aşamada kullanılamaz, çünkü verinin boyutu kadar ek bellek ister; yerinde sıralayan algoritmalar seçilir.
- Problem türleri: P ve NP
  - Algoritma değil, problem P ya da NP olur. Sıralama bir problemdir, Selection Sort bir algoritmadır.
  - P-type: polinom zamanlı ($n^2$, $n^3$, $n^4$ gibi) bir algoritmayla çözülebilen problem. Sıralama P'dir.
  - NP (non-deterministic polynomial): derste "polinom zamanlı bir algoritmayla çözülüp çözülmediği belli değil" diye tanımlandı (ekrandan, 01:25:00).
  - Karmaşıklık sırası (ekrandan, 01:25:00): $1 \to \log\log N \to \log N \to N \to N\log N \to N^2, N^3, N^4, \dots, N^k$ (polinom ailesi); $2^N, 3^N, k^N, N!, N^N$ (polinom olmayan aile).
- Alt küme toplamı problemi
  - Soru: $N$ sayı içinde toplamı $K$ olan bir alt küme var mı? Bu bir varlık (existence) problemidir.
  - Kaba kuvvet çözüm bütün boş olmayan alt kümeleri dener: $2^N - 1$ alt küme.
- Gezgin satıcı problemi (TSP)
  - Bütün şehirlerden geçip başlangıca dönen en kısa rota aranır. $N$ şehirde $(N-1)!$ rota vardır; Türkiye'nin 81 ili için $80!$.
  - $N!$'den $(N+1)!$'e geçince iş $N+1$ kat artar; bu yüzden donanımı hızlandırmak sorunu çözmez.
- Algoritma değerlendirme ölçütleri ve yaklaşık çözüm
  - Üç ölçüt: zaman, bellek, doğruluk (accuracy). Aralarında ödünleşim (trade-off) vardır.
  - Kesin (optimal/exact) çözüm makul sürede bulunamıyorsa doğruluktan ödün verilip yaklaşık (approximate) çözüm aranır. Bu çözümler sezgisel (heuristic) yöntemlerle bulunur ve daha çok yapay zekâ derslerinde işlenir.
  - TSP için en yakın komşu sezgiseli: bir şehirden başla, her adımda ziyaret edilmemiş en yakın şehre git. Karmaşıklığı $(N-1) + (N-2) + \dots + 1 \approx N^2/2 \ll N!$, ama optimumu garanti etmez.
  - Sezgiseller yerel minimuma takılabilir; başlangıç noktası sonucu etkiler.
  - Karınca kolonisi ve genetik algoritma gibi doğadan esinlenen yöntemler de yaklaşık çözüm üretir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Matris çarpımının önemi
  - Grafik, oyun, robotik ve derin öğrenmenin temel işlemi olduğu için hızlandırılması önemlidir. $n^3$'ten $n^{2.x}$'e inmek bile, örneğin bir oyunun takılmaması için büyük fark yaratır.
- Problem ve algoritma ayrımı
  - "Selection Sort P-type'tır" demek yanlıştır; P ya da NP olan algoritma değil, problemdir.
- Karmaşıklık ile ölçülen süre ayrımı
  - Paralelleştirme örneğinde hesap karmaşıklık üzerinden değil, ölçülmüş süre üzerinden yapılır. Paralellik karmaşıklık sınıfını değiştirmez, süreyi kısaltır.
- NP'nin anlamı
  - Bugüne kadar polinom zamanlı çözüm bulunamamış olması, hiç bulunamayacağı anlamına gelmez.
- Doğruluktan ödün verme
  - Gerçek çözüm için yıllarca beklemek yerine dakikalar içinde makul bir yaklaşık çözüm bulmak tercih edilir. Hoca bunu "önemli bir konu" diye vurguladı.
- Matematik ve mantığın rolü
  - Bellek ya da zaman kullanarak iyileştirilemeyen bir algoritma, matematik ve mantık kullanılarak çok daha iyi hâle getirilebilir.

## Kısa Tekrar Notları

- $n \times m$ ile $m \times p$ matris çarpımı: $n \times p$ sonuç, $n \cdot m \cdot p$ çarpma; kare matriste $O(n^3)$.
- Matris zinciri: $(AB)C$ 4500, $A(BC)$ 27000 çarpma; boyutlara bakıp sıra seç.
- Strassen gibi böl-yönet algoritmaları üssü 3'ün altına indirir; paralellik süreyi kısaltır, karmaşıklığı değiştirmez.
- CPU ($\sim 10^9$) > RAM > disk ($\sim 10^2$); darboğaz en yavaş bileşendir.
- External Merge Sort: parçaları RAM'de yerinde sırala, sonra çok yollu birleştir; giriş/çıkış tamponları RAM'de.
- P: polinom zamanlı çözümü olan problem. NP: polinom zamanlı çözümü bilinmeyen problem (derste verilen tanım).
- Alt küme toplamı: $2^N - 1$ alt küme. TSP: $(N-1)!$ rota.
- En yakın komşu sezgiseli: $\approx N^2/2$ işlem, optimum garantisi yok, yerel minimuma takılabilir, başlangıç noktası önemli.
- Ölçütler: zaman, bellek, doğruluk; NP problemlerde doğruluktan ödün verilir.

## Detaylı Açıklamalar

- Matris çarpımı kodu derste sözde kodla yazıldı (ekrandan, 00:20:00): `for(i=1;n)`, `for(j=1;p)`, `sum=0;`, `for(k=1;m)`, `sum += A[i][k]*B[k][j]`, `end for`, `C[i][j] = sum;`. `sum`'ın her $(i,j)$ başında sıfırlanması gerekir; yoksa önceki elemanın toplamı yeni elemana eklenir. En iç döngüde $i$ sabit kalır ve $k$ satırda sağa ilerler; $B$'de $j$ sabit kalır ve $k$ sütunda aşağı iner.
  - Aşağıdaki C kodu derste yazılmadı; sözde kodun 0 tabanlı C karşılığıdır, ajan tarafından `gcc -Wall` ile derlenip $2 \times 3$ ile $3 \times 2$ matrislerle çalıştırıldı (çıktı `58 64 / 139 154`).

```c
#include <stdio.h>
#define N 2
#define M 3
#define P 2
int main(void){
    int A[N][M]={{1,2,3},{4,5,6}};
    int B[M][P]={{7,8},{9,10},{11,12}};
    int C[N][P];
    int i,j,k,sum;
    for(i=0;i<N;i++){
        for(j=0;j<P;j++){
            sum=0;
            for(k=0;k<M;k++)
                sum+=A[i][k]*B[k][j];
            C[i][j]=sum;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<P;j++) printf("%d ",C[i][j]);
        printf("\n");
    }
    return 0;
}
```

- Matris zinciri örneğinde iki sıra arasında altı kattan fazla fark vardır. Bir öğrenci bu farkın boyutların birbirine yakınlığıyla açıklanıp açıklanamayacağını sordu; hoca genel bir kural vermedi, olası sıraların maliyetlerini tek tek hesaplayıp en ucuzunu seçmenin yolu olduğunu söyledi. Dört matriste olası parantezlemelerin sayısı artar; bu durumları sayıp karşılaştıran algoritmalar vardır.
- External Merge Sort'ta ilk aşamanın ardından veri "merdiven" gibidir: örneğin bir parça 2, 8, 18; diğeri 1, 4, 7; diğeri 70, 78, 98 diye kendi içinde sıralıdır (ekrandan, 00:50:00). İkinci aşama dönemin başında yazılan iki sıralı diziyi birleştirme (merge) işleminin 9 yollu hâlidir; birleştirmenin ön şartı parçaların sıralı olmasıdır. Sonunda veri diskin yeni bir yerinde sıralı durur, eski yer serbest bırakılır.
- Diziler, matrisler, bağlı listeler ve ağaçlar RAM üzerindeki veri yapılarıdır. Disk üzerinde de daha çok dengeli ağaçlara dayanan disk veri yapıları vardır (dosya organizasyonu).
- Hız örneğinde 1 GHz $= 10^9$, 10 MHz $= 10^7$ alındığında işlemci RAM'den $10^2$ kat hızlıdır; 7200 rpm $= 120$ Hz $\approx 10^2$ alındığında işlemci diskten $10^7$ kat hızlıdır. SSD'ler eski manyetik disklerden çok daha hızlıdır (derste bakılan bir örnekte okuma yaklaşık 550 MB/s, yazma 530 MB/s).
- Derste sorulan diğer sorular:
  - GPU'lar binlerce işlem elemanı içerir; grafik ve yapay zekâ matris işlemleri yoğun olduğu için GPU üzerinde çok daha hızlı çalışır. TPU (Tensor Processing Unit) daha yüksek boyutlu matris (tensör) işlemleri için tasarlanmıştır. Vektör çarpımındaki bağımsız çarpımlar donanımda tek adımda yapılabilir.
  - Isınan işlemcinin yavaşlaması, donanım ve BIOS düzeyindeki koruma mekanizmalarından kaynaklanır.
- Alt küme toplamı örneği (ekrandan, 01:35:00): $A = [4, 8, 2, -1, 5, 10, 6, 15]$, $K = 15$. Gözle bulunan alt kümeler: {10, 5}, {8, 2, 5}, {10, 6, −1}, {8, 2, 6, −1}, {10, 4, 2, −1}, {6, 4, 5}. Gözle aramak algoritma değildir; 70 bin elemanlık bir dizide işe yaramaz. Sistematik çözüm tek elemanlı ($\binom{N}{1}$), iki elemanlı ($\binom{N}{2}$, 2-sum), üç elemanlı (3-sum) ... bütün alt kümeleri dener; toplam $2^N - 1$ durum. Bir öğrenci ikilik sayaç (binary counter) önerdi: her alt küme bir ikilik sayıyla gösterilebilir; bu da $2^N$ durum demektir. Diziyi önce sıralayıp ikili arama kullanmak bir miktar iyileştirme sağlar.
- En yakın komşu sezgiseli örneği (ekrandan, 02:00:00): A–B 2, B–C 1, C–D 1, D–E 1, E–F 1, A–F 6.
  - B'den başlayan sezgisel: B C D E F A, uzunluk 10.
  - B'den başlayan daha iyi bir çözüm: B A B C D E F, uzunluk 8.
  - Optimal çözümlerden biri: A B C D E F, uzunluk 6.
- Derste gösterilen yayımlanmış bir çalışmada Türkiye'nin 81 ili için karınca kolonisi algoritması 1000 adımda yaklaşık 9966 km'lik, genetik algoritma 11739 km'lik bir rota buldu; ikisinin arama süresi yaklaşık 15 dakikaydı (ekrandan, 02:10:00). İki yöntem de optimumu garanti etmez; hangisinin daha iyi olduğu probleme göre değişir. Bu yöntemler rastgelelik içerdiği için her çalıştırmada farklı sonuç verebilir; karşılaştırma için çok sayıda (hocaya göre en az 30-35) deney gerekir.
- Önerilen kaynaklar: Donald Knuth, *The Art of Computer Programming*; Robert Sedgewick ve Kevin Wayne, *Algorithms* (4. baskı, çevrimiçi kod ve animasyonlarıyla); doğadan esinlenen algoritmalar için *Clever Algorithms* (ekrandan, 02:15:00 ve 02:20:00).
- Ders sonrası notlar:
  - Hoca böl-yönet matris çarpımının karmaşıklığını "yaklaşık $n^{2.6}$" dedi. Strassen algoritması $n^{\log_2 7} \approx n^{2.81}$'dir; daha sonraki algoritmalar üssü yaklaşık 2.37'ye kadar indirmiştir.
  - Hoca "6 faktöriyel 127, 840 gibi" dedi; doğrusu $6! = 720$, $7! = 5040$.
  - NP'nin standart tanımı, bir çözümün polinom zamanda doğrulanabildiği (ya da deterministik olmayan bir makinede polinom zamanda çözülebildiği) problemlerdir. Derste verilen "polinom zamanda çözülüp çözülmediği belli değil" ifadesi bu sınıfın sezgisel bir açıklamasıdır; P de NP'nin içindedir.
  - Hoca alt küme toplamının kodla çözümünün $N!$'e çıktığını söyledi. Bütün $\binom{N}{r}$ terimlerinin toplamı $2^N - 1$'dir; kaba kuvvet çözüm $O(N \cdot 2^N)$'dir, yani üstel ama $N!$ değil.
  - Örnek dizide 15 de bulunduğu için {15} tek elemanlı alt kümesi de çözümdür; python ile kontrol edildiğinde toplamı 15 olan 7 alt küme vardır.
  - Hoca SSD'yi "dinamik RAM" tabanlı diye anlattı; SSD'ler büyük olasılıkla NAND flash bellek kullanır, DRAM yalnız bazı SSD'lerde önbellek olarak bulunur.
  - Derste RAM için örnek alınan 10 MHz bugünkü bellekler için düşüktür (DDR4/DDR5 bellekler birkaç bin MT/s hızındadır); bir öğrenci de bunu belirtti. Oranlar yalnız büyüklük mertebesini göstermek içindir.
  - Hoca bir yerde işlemciler için "belki 40 GHz" dedi; bugünkü işlemcilerin saat hızı büyük olasılıkla birkaç GHz düzeyindedir, toplam işlem gücü çekirdek ve iş parçacığı sayısıyla artar.
  - Quick Sort'un ortalama karmaşıklığı $n \log n$, en kötü durumu $n^2$'dir; Merge Sort her durumda $n \log n$'dir ama $O(n)$ ek bellek ister.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
