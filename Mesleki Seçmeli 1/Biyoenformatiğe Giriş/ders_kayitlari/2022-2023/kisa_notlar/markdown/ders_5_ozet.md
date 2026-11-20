# Ders 5 Çalışma Özeti

## Genel Konular

- Hizalamaların skorla karşılaştırılması
  - Ders, önceki derste sorulan iki hizalamayla açıldı: `ACGGACT` ve `ATCGGATCT` dizilerinin iki geçerli hizalaması (ekrandan, 00:10:00). Hangisinin daha iyi olduğuna karar vermek için nesnel bir ölçüt, yani bir skorlama şeması gerekir.
  - Basit şema: eşleşme $+1$, uyuşmazlık $-1$, boşluk (indel) $-1$. Daha yüksek skor daha iyi hizalama demektir; bu şemayla ikinci hizalama daha iyidir.
- Hizalama yöntemleri
  - Görsel hizalama (dot plot): nitel bir değerlendirme verir.
  - Kaba kuvvet (brute force): bütün olası hizalamaları dener (ekrandan, 00:15:00).
  - Dinamik programlama: verilen skorlama şemasına göre en iyi (optimal) hizalamayı garanti eder.
  - Kelime tabanlı yöntemler de vardır; hoca bunları "ad hoc" yöntemler olarak andı.
- Dot plot (nokta matrisi)
  - 1970'te A. J. Gibbs ve G. A. McIntyre tarafından önerilmiştir; iki amino asit ya da nükleotit dizisini karşılaştırır (ekrandan, 00:20:00).
  - Bir dizi satırlara, diğeri sütunlara yerleştirilir; iki karakter aynıysa hücre işaretlenir. Algoritma iç içe iki `for` döngüsüdür.
  - Kendisiyle karşılaştırılan dizide ana köşegen boyunca kesintisiz bir çizgi oluşur (ekrandan, 00:25:00). Köşegene paralel kısa çizgiler tekrarları, ters yöndeki çizgiler ters tekrarları (inverted repeat, ters tümleyen) gösterir.
  - Köşegendeki kopukluklar ekleme/silme bölgeleridir. Bir uygulama, işlenmiş bir mRNA içindeki kodlayan bölgelerin (ekzonların) sayısını bulmaktır (ekrandan, 00:30:00).
  - Kendi kendine karşılaştırma; tekrarlanan alt dizileri, ardışık (tandem) genleri, proteindeki tekrarlanan domainleri, düşük karmaşıklıklı bölgeleri ve kromozomlar arası benzerliği gösterir. Aynı dizinin iki farklı birleştirmesini (assembly) karşılaştırmak için de kullanılır (insan kromozomu 5 ve Y örnekleri).
  - Biyoinformatik dışında da kullanılır: intihal tespiti, yazılımın kendi kendine dot plot'u (yaklaşık 2 milyon satırlık bir telekomünikasyon yazılım modülü örneği).
- Dot plot'ta gürültü ve kayan pencere
  - Nükleik asitlerde rastgele eşleşme olasılığı 4'te 1'dir; bu rastgele eşleşmeler gürültüdür (ekrandan, 00:40:00).
  - Gürültüyü süzmek için kayan (sliding/moving) pencere kullanılır; pencere içinde eşleşen bazların yüzdesi eşik olarak belirlenir.
  - Hoca, kavramı sinyal işlemedeki kayan ortalama (moving average) ve kayan medyan filtreleriyle ilişkilendirdi.
- Dot plot'un sınırları
  - Diziler birbirine çok benzemiyorsa tek başına yeterli değildir; ekleme/silmeyle kesilen benzerliği kolayca çözemez ve en iyi hizalamayı bulmak zordur (ekrandan, 00:45:00).
- Dot plot'tan global hizalama çıkarma örneği
  - `DILVDEQ` ile `IVQDEQ` dizilerinin dot plot'u çizildi ve sağ alttan geriye doğru giderek olası bir global hizalama bulundu (ekrandan, 00:50:00).
- Nicel ölçüler ve skorlama
  - Hamming mesafesi (uyuşmayan karakter sayısı) ve Levenshtein mesafesi (eklemeler, silmeler, yer değiştirmeler dahil düzenleme sayısı) hatırlatıldı.
  - Skorlamada sorulacak sorular: eşleşme ve uyuşmazlığa kaç puan verilecek, boşluğa izin verilecek mi ve nasıl puanlanacak, en iyi hizalamayı bulan algoritma hangisi, bulunan hizalama anlamlı mı (ekrandan, 02:05:00).
- Kaba kuvvet ve dinamik programlama
  - Kaba kuvvette diziler boşluklarla uzatılır ve bütün olasılıklar denenir; karmaşıklık üstel artar, pratikte kullanılamaz.
  - Dinamik programlama problemi alt problemlere bölerek çözer; ara sonuçlar bellekte tutulur. Üç adımı vardır: başlatma (initialization), matris doldurma (matrix fill), geri izleme (traceback).
- Global hizalama (Needleman-Wunsch)
  - Matris $M+1$ satır, $N+1$ sütundur (ekrandan, 02:15:00).
  - Başlatma: $S_{i,0} = i \cdot w$, $S_{0,j} = j \cdot w$ ($w$ boşluk cezası).
  - Doldurma: $S_{i,j} = \max[S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w]$ (ekrandan, 02:20:00).
  - Geri izleme her zaman sağ alt köşeden başlar.
  - Örnek: `GAATTCAGTTA` ve `GGATCGA`, eşleşme $5$, uyuşmazlık $-3$, boşluk $-4$; global skor $11$ (ekrandan, 02:25:00).
- Lokal hizalama (Smith-Waterman)
  - Global algoritmadan iki farkı vardır: ilk satır ve sütun sıfırla başlatılır; hiçbir hücre negatif olamaz, negatif değer sıfırlanır (formüle $0$ eklenir).
  - Geri izleme matristeki en büyük değerden başlar ve sıfıra ulaşınca durur. Aynı örnekte en büyük değer $14$'tür ve iki hücrede geçer (ekrandan, 02:40:00).
- Örtüşme (overlap) hizalaması
  - Yarı global (semi-global) ya da yarı lokal hizalama da denir. Başlatma lokal hizalamadaki gibi sıfırdır, doldurma global hizalamadaki gibidir; negatif değerlere izin verilir.
  - Skor en alt satır ya da en sağ sütundaki en büyük değerdir (ekrandan, 02:50:00). Bir dizinin parçalarını uç uca birleştirmek (dikiş, stitching) için kullanılır.
- BLOSUM62 ile kaba kuvvet örneği
  - `FYGNYK` ve `DGSFNW` dizileri BLOSUM62 ile, boşluk cezası $-1$ alınarak kaydırmalı olarak hizalandı (ekrandan, 03:00:00). BLOSUM62 gibi yer değiştirme matrisleri gerçek biyolojik yer değiştirme olasılıklarına dayanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hizalama kalitesi için nesnel ölçüt şarttır
  - "Hangisi daha iyi?" sorusu ancak bir skorlama şemasıyla cevaplanabilir. Şemanın biyolojik olarak uygun olup olmadığı ayrı bir konudur ve sonraki derslerde ele alınacaktır.
- Geri izlemenin nereden başladığı hizalama türünü belirler
  - Global: daima sağ alt köşe. Lokal: matristeki en büyük değer (herhangi bir yerde olabilir). Örtüşme: en alt satır ya da en sağ sütundaki en büyük değer.
  - Hoca, lokal hizalamada sağ alt köşeden başlamanın yanlış olduğunu, sınavda bu cevabın hatalı sayılacağını söyledi.
- Global, lokal ve örtüşme hizalamaları kolay karıştırılır
  - Tamamlanmış bir matrise bakarak türü bulmak için iki şeye bakılır: ilk satır/sütun sıfır mı, matriste negatif değer var mı. İlk satır/sütun sıfır ve negatif değer varsa örtüşme hizalamasıdır.
  - Eşleşme, uyuşmazlık ve boşluk parametreleri tamamlanmış matristen doldurma formülüyle geriye doğru çözülebilir.
- Hücrenin değerini hangi komşunun verdiği (ok/işaretçi) bellekte tutulmalıdır
  - Geri izleme bu işaretçilerle yapılır. Birden çok komşu aynı en büyük değeri veriyorsa hepsi saklanır; bu, aynı skorlu birden çok optimal hizalamaya yol açar.
- Algoritmalar basittir
  - Dot plot da dinamik programlama da temelde iç içe iki `for` döngüsüdür; hoca kendi dot plot programınızı yazabileceğinizi söyledi.

## Kısa Tekrar Notları

- Basit skorlama: eşleşme $+1$, uyuşmazlık $-1$, boşluk $-1$; yüksek skor daha iyi hizalama.
- Hizalama yöntemleri: görsel (dot plot), kaba kuvvet, dinamik programlama.
- Dot plot: satır = dizi 1, sütun = dizi 2, aynı karakter = nokta. Ana köşegen kendine benzerlik; paralel çizgiler tekrar; ters yöndeki çizgiler ters tekrar; kopukluklar indel.
- Gürültü: DNA'da rastgele eşleşme olasılığı $1/4$; kayan pencere ve eşik yüzdesiyle süzülür.
- Dot plot'un sınırları: indel'le kesilen benzerliği zor çözer, optimal hizalamayı bulmak zordur.
- Kaba kuvvet üstel karmaşıklıktadır; dinamik programlama verilen skorlamaya göre optimal hizalamayı garanti eder.
- DP adımları: başlatma, matris doldurma, geri izleme.
- Needleman-Wunsch (global): $S_{i,0}=i w$, $S_{0,j}=j w$; $S_{i,j}=\max[S_{i-1,j-1}+s(a_i,b_j), S_{i,j-1}+w, S_{i-1,j}+w]$; sağ alttan geri izle.
- Smith-Waterman (lokal): ilk satır/sütun $0$; formüle $0$ eklenir; en büyük hücreden başla, $0$'da dur.
- Örtüşme: başlatma $0$, doldurma global gibi (negatif olabilir); en alt satır/en sağ sütundaki en büyük değerden başla.
- Skor fonksiyonunda en büyük değer alınır; mesafe kullanılırsa en küçük değer alınır.

## Detaylı Açıklamalar

- Skorlama şemasıyla hizalama karşılaştırma
  - `ACGGACT` ile `ATCGGATCT` için birinci hizalama `A-C-GG-ACT` / `ATCGGAT-CT`, ikinci hizalama `ATCGGATCT` / `A-CGG-ACT` biçimindedir (ekrandan, 00:10:00). Eşleşme $+1$, uyuşmazlık $-1$, boşluk $-1$ ile birinci hizalamada 5 eşleşme, 1 uyuşmazlık ve 4 boşluk vardır; ikinci hizalamanın skoru daha yüksektir, bu yüzden daha iyidir.
  - Ders sonrası not: hoca birinci hizalamanın skorunu $1$, ikincisininkini $7$ olarak söyledi (altyazıya göre). Ekrandaki hizalamalar bu şemayla python ile hesaplanınca birinci hizalama $5 - 1 - 4 = 0$, ikinci hizalama 6 eşleşme, 1 uyuşmazlık, 2 boşlukla $6 - 1 - 2 = 3$ çıkıyor. Sonuç (ikinci hizalamanın daha iyi olması) değişmez; söylenen değerler büyük olasılıkla Whisper hatası ya da farklı bir slayt sürümüdür.
- Dot plot nasıl kurulur ve okunur?
  - İki dizi de tek boyutlu karakter dizisidir. Her satır ve her sütun gezilerek $i$. satır karakteri $j$. sütun karakterine eşitse hücre işaretlenir. Örnek slaytta `ACCTGAGCTCACCTGAGTTA` dizisi kendisiyle karşılaştırıldı; ana köşegenin yanında, dizinin içindeki `ACCTGAG` tekrarına karşılık gelen paralel çizgiler ve ters yönde kısa bir çizgi (ters tekrar) görüldü (ekrandan, 00:25:00).
  - Köşegen dışındaki tek tük noktalar rastgele eşleşmelerdir. Kayan pencerede tek kalıntı yerine bir pencere boyunca karşılaştırma yapılır; penceredeki eşleşme oranı eşiği geçerse nokta konur. Hoca, gürültü azaltılmış ve azaltılmamış iki kendi kendine dot plot'u karşılaştırarak gürültünün büyük kısmının kalktığını gösterdi.
  - Kayan ortalama filtresi $n$ örneğin ortalamasını alıp pencereyi birer kaydırır; alçak geçiren filtredir (görüntü işlemede bulanıklaştırma, finansal seride yumuşatma/eğilim). Kayan medyan filtresi ortalama yerine medyanı alır. Dot plot'taki kayan pencere aynı fikirdir.
- Dot plot'tan global hizalama (`DILVDEQ` / `IVQDEQ`)
  - Sağ alt köşedeki Q-Q eşleşmesinden başlanıp köşegen boyunca E-E ve D-D'ye çıkılır. Sonra yukarı gidilir (üstteki dizide boşluk), V-V eşleşmesine geçilir, sola gidilir (alttaki dizide boşluk), I-I eşleşmesine gelinir ve en başta D bir boşlukla eşlenir (ekrandan, 00:50:00). Bu yolla elde edilen hizalama:

    ```text
    D I L V - D E Q
    - I - V Q D E Q
    ```

  <!-- BELİRSİZ: Son hizalamanın tam hali karede görünmüyor; hizalama, 00:50:00 karesindeki oklar ve hocanın anlatımından kuruldu. -->
- Global hizalama örneği
  - Diziler `GAATTCAGTTA` (sütunlar, 11) ve `GGATCGA` (satırlar, 7); matris $8 \times 12$'dir. İlk satır $0, -4, -8, \dots, -44$, ilk sütun $0, -4, \dots, -28$ olur. İlk iç hücre için G-G eşleşmesi: $\max(0+5, -4-4, -4-4) = 5$; bu değer köşegenden geldiği için köşegen işaretçisi saklanır.
  - Doldurulan matrisin sağ alt hücresi $11$'dir ve global hizalama skorudur (ekrandan, 02:25:00; python ile doğrulandı). Geri izlemeyle bulunan hizalama (ekrandan, 02:30:00):

    ```text
    G A A T T C A G T T A
    G G A - T C - G - - A
    ```

  - Kontrol: 6 eşleşme ($30$), 1 uyuşmazlık ($-3$), 4 boşluk ($-16$); $30 - 3 - 16 = 11$.
- Lokal hizalama örneği
  - Aynı diziler ve skorlarla lokal matriste en büyük değer $14$'tür ve iki hücrede geçer (G-G ve A-A hücreleri). Alttaki $14$'ten geri izlemede bir hücrede iki yol vardır; iki optimal lokal hizalama elde edilir (ekrandan, 02:45:00):

    ```text
    G A A T T C - A        G A A T T C - A
    G G A T - C G A        G G A - T C G A
    ```

  - Her ikisi de 5 eşleşme, 1 uyuşmazlık, 2 boşlukla $25 - 3 - 8 = 14$ skorludur (python ile doğrulandı). Diğer $14$'ten de başlanabilirdi; bu örnekte ikiden fazla optimal lokal hizalama vardır.
- Örtüşme hizalaması örneği
  - Eşleşme $4$, uyuşmazlık $-1$, boşluk $-5$ ile iki dizi hizalandı; başlatma $0$, doldurma global gibi yapıldı ve en büyük değer en alt satır/en sağ sütunda arandı. Hoca iki dizinin büyük olasılıkla aynı dizinin parçaları olduğunu söyledi. <!-- BELİRSİZ: bu örneğin dizileri ve sonuç hizalaması karelerde görünmüyor (02:50:00 ve 02:55:00 kareleri formül slaytlarıdır). -->
- BLOSUM62 ile kaba kuvvet örneği
  - `FYGNYK` ve `DGSFNW` hiç örtüşmeden yan yana konunca 12 boşluk vardır ve skor $-12$'dir. Diziler birer kaydırılarak her konumun skoru hesaplanır. Hoca sırasıyla $-12, -11, -13, -8, -10, 5, -14, -2, -7, -4, -9, -9, -12$ değerlerini okudu (altyazıda eksi işaretleri düşmüş; değerler python ile doğrulandı). En iyi skor $5$'tir:

    ```text
    F Y G N Y K -
    - D G S F N W
    ```

  - Skor: Y/D $-3$, G/G $6$, N/S $1$, Y/F $3$, K/N $0$, iki uç boşluk $-2$; toplam $5$. <!-- BELİRSİZ: En iyi hizalamanın ekrandaki hali karelerde görünmüyor; hizalama python hesabından kuruldu. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
