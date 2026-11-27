# Ders 13 Genişletilmiş Notu: Quiz 2 Çözümleri, İkili Arama Ağacı Tekrarı, Heap ve Heap Sort

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Quiz 2 Sorularının Üzerinden Geçiş
- 2. İkili Arama Ağacı Tekrarı
- 3. Heap Nedir?
- 4. Heap'in Dizi ile Gösterimi
- 5. Heap Oluşturma: Bottom-Up Yöntem ve MAX-HEAPIFY
- 6. En Büyük Elemanı Heap'ten Almak
- 7. Bir Düğümün Değerini Artırmak
- 8. Heap'e Eleman Eklemek ve Top-Down Oluşturma
- 9. Heap Sort
- Örnek Sorular
- Dersin Toparlaması

## 1. Quiz 2 Sorularının Üzerinden Geçiş

Dersin ilk saatinde hoca bir önceki quizin sorularını beyaz tahta üzerinde tek tek çözdü. Soruları tahtaya kopyalayamadığı için ağaçları, yığıtları ve kodları elle yeniden yazdı. Sorular şu konuları kapsıyordu: ikili arama ağacında preorder gezinti, Josephus problemi, reverse işlemli özel bir yığıtla kuyruk gerçekleme, yığıtla "casus string" çözme, doğru-yanlış soruları, döngü karmaşıklığı, farklı veri yapılarında arama karmaşıklığı, labirentteki fare problemi, bağlı liste üzerinde özyinelemeli bir fonksiyon ve dairesel kuyruğa ekleme. Her sorunun metni ve derste verilen çözümü aşağıdaki "Örnek Sorular" bölümünde ayrıntılı olarak yer alıyor. Burada yalnız çözümlerde öne çıkan kavramsal noktalar özetleniyor.

### 1.1 Preorder gezinti

Preorder (kök önde) gezintide sıra VLR'dir: önce düğüm ziyaret edilir (visit), sonra sol alt ağaç, sonra sağ alt ağaç özyinelemeli olarak gezilir. Hoca gezintiyi adım adım izledi. Bir düğümün sol ve sağ alt ağaçları bitince bir üst düğüme "geri gelinir". Kökün sağ alt ağacı da bitince gezinti tamamlanır.

### 1.2 Josephus problemi ve dairesel bağlı liste

Hoca bu sorunun derste anlatılan "Romalı problemi" (Josephus ve arkadaşlarının mağarada çember oluşturup her üçüncü kişinin elendiği hikâye) ile birebir aynı mantıkta olduğunu hatırlattı. Dairesel bağlı listeyle tutulursa eleme işlemi çok hızlı gerçeklenir: sayma, listede `next` ile ilerlemek; eleme, bir düğümü listeden çıkarmaktır.

### 1.3 Reverse işlemli yığıtla kuyruk

Yığıt LIFO (son giren ilk çıkar), kuyruk FIFO (ilk giren ilk çıkar) çalışır. Kuyruğa yeni gelen eleman en son çıkacağı için yığıtın üstüne push etmek enqueue için yeterlidir. Kuyruktan çıkması gereken eleman yığıtın dibindedir. Hoca, "$n$ tane pop yapıp geri koymak" gibi çözümlerin gereksiz olduğunu, zaten reverse işleminin verildiğini vurguladı: reverse, pop, reverse ile dequeue gerçeklenir.

### 1.4 Casus string ve yığıt

Harfler yığıta push edilir, bir rakam $k$ görülünce $k$ kez pop yapılır. Her işlem $O(1)$ olduğundan $n$ karakter için toplam $O(n)$ işlem yapılır. Hoca aynı işin dizide yapılması durumunda, her rakam için geriye doğru silme yapan iç döngüler gerekeceğini ve iç içe döngüler yüzünden mertebenin $n^2$'ye çıkabileceğini söyledi. Bu yüzden yığıt daha uygundur.

> **Ders sonrası not:** Hoca dikkatli yazılmış bir dizi çözümünün de $O(n)$'de kalabileceğini kabul etti, ama iç içe döngüler kurulduğu için $n^2$ mertebesine çıkılabileceğini söyledi. Doğru kurulmuş bir dizi çözümü (diziyi yığıt gibi kullanmak) büyük olasılıkla yine $O(n)$'dir; asıl fark, yığıtın bu çözümü doğal olarak vermesidir.

### 1.5 Çift bağlı listede silme

Çift bağlı listede bir düğümün işaretçisi varsa, `prev` ile öndekine, `next` ile arkadakine ulaşılabilir. `prev->next` ve `next->prev` bağları güncellenerek düğüm listeden çıkarılır. Hoca silmede bağların hangi sırayla koparılacağına dikkat edilmesi gerektiğini, yoksa öndeki ya da arkadaki düğüme olan bağın kaybedilebileceğini hatırlattı.

### 1.6 Labirentteki fare ve yığıt

Labirent genellikle bir matrisle modellenir: gidilebilen gözlere 1, duvarlara 0 yazılır; sol üstten girilip sağ alttan çıkılmak istenir (ekrandan, 00:35:00). Farenin hareketleri sınırlıdır: sol, sağ, yukarı, aşağı. En basit strateji ("aptal fare") her gözde hareketleri hep aynı sırayla denemektir. Yapılan her hareket yığıta konur. Çıkmaza girilince son hareketin tersi yapılarak geri gelinir ve hareket yığıttan pop edilir. Yani en son yapılan hareket ilk geri alınır; bu bir "undo" problemidir ve en uygun veri yapısı yığıttır.

**Soru:** Derin öncelikli arama mı yapacağız? **Cevap:** Hoca "yok" dedi; ama öğrencinin devamındaki açıklamasını (gidilen yolu yığıta aktarıp gidecek yol kalmayınca geri çekerek başka yol aramak) doğru mantık olarak kabul etti.

> **Ek bilgi (derste anlatılmadı):** Yığıtla yapılan bu geri izleme (backtracking) araması, çizge kuramındaki derinlik öncelikli aramanın (DFS) bir uygulamasıdır. DFS konusu büyük olasılıkla dersin ilerleyen haftalarında çizgelerle birlikte işlenecektir.

### 1.7 Bağlı listede özyineleme

`mystery` fonksiyonu önce kendini `head->next` ile çağırır, sonra `head->data`'yı yazdırır. Bu yüzden yazdırma işlemleri özyineleme geri dönerken yapılır ve liste sondan başa doğru yazılır.

### 1.8 Dairesel kuyruk

Boyutu $n$ olan dizi üzerindeki dairesel kuyrukta yeni eleman `rear + 1` gözüne eklenmelidir. Ama dizinin sonundan başa dönebilmek gerekir; en kolay yol mod almaktır: `(rear + 1) % n`.

## 2. İkili Arama Ağacı Tekrarı

Quizden sonra hoca, bir öğrencinin silme işleminin kafasında tam oturmadığını söylemesi üzerine önceki haftanın son konusu olan ikili arama ağacını slaytlar üzerinden tekrar anlattı.

### 2.1 Tanım ve arama

İkili arama ağacında verilen her düğüm için sol alt ağaç o düğümden küçük, sağ alt ağaç o düğümden büyük elemanlardan oluşur. Bu şart ağacın her alt ağacında da geçerlidir; sağlanmıyorsa ağaç ikili arama ağacı değildir.

Slayttaki ağaç (ekrandan, 00:45:00):

```text
                44
         /              \
       17                88
      /  \             /    \
   (boş)  32         65      97
         /  \       /  \
       28  (boş)  54    82
         \             /
          29         76
                       \
                        80
```

- `Ara(25)`: 44'ten başlanır; 25 < 44 olduğu için sola, 17'ye gidilir. 25 > 17 olduğu için sağa, 32'ye gidilir. 25 < 32 olduğu için sola, 28'e gidilir. 25 < 28 olduğu için sola gidilir ve boş (NULL) görülür. Sonuç: 25 ağaçta yoktur.
- `Ara(76)`: 76 > 44 → sağa (88); 76 < 88 → sola (65); 76 > 65 → sağa (82); 76 < 82 → sola (76). Eşitlik bulundu.

Hoca aramanın neden önemli olduğunu şöyle açıkladı: düğümler aslında birer `struct` olabilir. Örneğin öğrenci numarasıyla arama yapılır, ama düğümde ad, adres, not ortalaması gibi başka bilgiler de vardır; düğüm bulununca bunlara da erişilir. Her adımda ağacın bir yarısı (sol ya da sağ) tamamen elendiği için arama $\log n$ mertebesindedir.

> **Ders sonrası not:** Hoca burada en fazla yüksekliğin $\log n$ olacağını söyledi. Bu yalnız dengeli ağaçlar için doğrudur. Dengesiz bir ikili arama ağacının yüksekliği $n$'e kadar çıkabilir; hoca bunu bölümün sonunda (2.4) kendisi de belirtti.

### 2.2 Ekleme

Ekleme de arama gibi ilerler: eklenecek değer düğümden küçükse sol alt ağaca, büyükse sağ alt ağaca "ekle" denir (özyinelemeli). İlk boş (NULL) yere gelindiğinde yeni bir düğüm yaratılır, değer içine yazılır ve düğüm döndürülür.

- 25 eklenirken 44 → 17 → 32 → 28 yolu izlenir; 28'in solu boş olduğu için 25, 28'in sol çocuğu olur.
- 75 eklenirken 44 → 88 → 65 → 82 → 76 yolu izlenir; 75 < 76 ve 76'nın solu boş olduğu için 75, 76'nın sol çocuğu olur.
- 65 eklenmeye çalışılırsa 44 → 88 → 65'te değer bulunur. Değer zaten vardır; üzerine yazmak ya da hiçbir şey yapmadan çıkmak gibi kararlar gerçeklemeye kalmıştır.

### 2.3 Silme: üç durum

**Birinci durum: yaprak düğüm.** Düğümün solu da sağı da boştur. En temiz durumdur; düğüm doğrudan silinir ve ağaçta başka düzenleme gerekmez. Örnek: 94 → 10 → 5 yoluyla bulunan 5 yaprak olduğu için doğrudan silinir.

**İkinci durum: tek çocuklu düğüm.** Örnek ağaç: 94'ün çocukları 10 ve 97; 10'un çocukları 5 ve 24; 24'ün yalnız sol çocuğu 11; 11'in yalnız sağ çocuğu 17.

- 24 silinmek istensin. 24'ün yalnız sol çocuğu vardır. Hoca bunu "tek bir soyu var, mirası bölüştürmek kolay" diye anlattı: 24 geçici bir değişkende tutulur, çocuğu (11 ve altındakiler) 24'ün ebeveynine (10'a) bağlanır, böylece alt soy başıboş kalmaz; sonra 24 `free` edilir. Sonuç: 94 → (10, 97); 10 → (5, 11); 11 → 17.
- Tümleyen durum olarak 11 silinsin (yalnız sağ çocuğu 17 var). Aynı işlem yapılır: 17, 11'in ebeveyni 24'e bağlanır ("torun dedenin nüfusuna kaydolur"), 11 `free` edilir. Sonuç: 94 → (10, 97); 10 → (5, 24); 24 → 17.

**Üçüncü durum: iki çocuklu düğüm.** Hiyerarşiyi bozmamak için iki seçenek vardır (ekrandan, 00:55:00):

- Sol alt ağaçtaki en büyük eleman bulunup düğümün yerine konur. Bu eleman soldakilerin hepsinden büyük olduğu için soldakiler küçük kalmaya devam eder; sağdakiler de zaten büyüktür.
- Sağ alt ağaçtaki en küçük eleman bulunup düğümün yerine konur. Bu eleman sağdakilerin hepsinden küçüktür; sağ alt ağaçtan geldiği için soldakilerin hepsinden de büyüktür.

Hoca örneği büyütmek için 5'in çocukları olarak 2 ve 8 ekledi ve 10'u sildi:

- Birinci seçenek: sol alt ağacın en büyüğü 8'dir. 8, 10'un yerine yazılır ve eski 8 silinir. Sonuç ağaç: 94 → (8, 97); 8 → (5, 24); 5 → 2; 24 → 11; 11 → 17. Kontrol: 8 < 94; 5 < 8 < 24; 2 < 5; 11 < 24; 17 > 11. Ağaç dengeli değildir ama ikili arama ağacı şartı korunur.
- İkinci seçenek: sağ alt ağacın en küçüğü 11'dir. 11, 10'un yerine kopyalanır. Sonra eski 11 silinir; onun tek çocuğu (17) olduğu için tek çocuk silme prosedürü uygulanır.

Slaytta şu soru yazıyordu: "Sağ alt ağaçtaki en küçük değeri içeren düğümün en fazla bir evladı olabilir. Neden?" Yani en küçük ya da en büyük eleman taşındıktan sonra silinmesi gereken düğüm her zaman ya yapraktır ya da tek çocukludur; silme özyinelemeli çağrıldığında ilk iki durumdan birine düşer.

> **Ek bilgi (derste anlatılmadı):** Sağ alt ağacın en küçük elemanı, o alt ağaçta hep sola gidilerek bulunan son düğümdür. Bu düğümün sol çocuğu olamaz; olsaydı ondan daha küçük bir eleman bulunurdu. Bu yüzden en fazla bir (sağ) çocuğu vardır.

> **Ders sonrası not:** Hoca özet yaparken bir an "sol alt soydaki küçük ya da sağ alt soydaki büyük" dedi, hemen ardından "soldaki büyük, sağdaki küçük" diye düzeltti. Doğrusu: sol alt ağacın en büyüğü ya da sağ alt ağacın en küçüğü.

Hoca slaytlardaki `find min` ve `find max` fonksiyonlarına ve silme koduna da kısaca değindi. Slayttaki silme kodu sağ alt ağaçtaki minimumu bulur; bunun yerine sol alt ağaçta `find max` da kullanılabilir.

<!-- BELİRSİZ: find min, find max ve silme kodunun slayt metni okunan karelerde görünmüyor; bu yüzden kod nota alınmadı. -->

### 2.4 Ağacın yüksekliği ve dengeleme

Slayttaki özet (ekrandan, 01:00:00):

- $N$ elemanlı bir ağaç $N$ yüksekliğe erişebilir (en kötü durumda bağlı listeye döner).
- Ekleme ve silmeler rastgele olursa ortalamada $O(\log_2 N)$ yüksekliğe sahip olur. Bunlara dengeli arama ağacı da denir.
- Arama, ekleme ve silme $O(h)$'dir ($h$: yükseklik). En kötü durum $O(n)$'dir.
- Nasıl önlenir? Dengeleme politikalarıyla: AVL, Splay, B-Tree (2-3, 2-3-4), red-black tree.

Hoca en basit dengeleme yönteminin AVL olduğunu söyledi. AVL, temel ikili arama ağacına yalnız ekleme ve silme sırasında bir denge kontrolü ekler; dengesizlik varsa çocuklar arasında kaydırma yaparak yüksekliği azaltır. Hoca bunu ders kapsamında anlatmadığını, isteyenlerin inceleyebileceğini söyledi.

## 3. Heap Nedir?

Aradan sonra haftanın yeni konusu heap'e geçildi. Hoca ilk saatte heap veri yapısını, ikinci saatte bir heap uygulaması olan heap sortu anlatacağını söyledi.

### 3.1 Binary heap ve yapısal özellik

Ders boyunca "heap" denince yalnız binary heap kastedilir. Fibonacci heap gibi aynı mantıkla ama farklı gerçeklemelerle çalışan başka heap türleri de vardır; bunlar ders kapsamında değildir.

Heap, neredeyse tam ikili ağaç (complete binary tree) şeklinde olan bir veri yapısıdır (ekrandan, 01:15:00). Complete binary tree, son düzey hariç tüm düzeylerin (level) tam dolu olduğu ve son düzeyin en soldan başlayarak dolduğu ikili ağaçtır. Bir heap her zaman bu yapıyı göstermek zorundadır; göstermiyorsa heap değildir.

### 3.2 Heap bellek alanı ile karıştırmamak

Java, Lisp gibi dillerde "heap" adıyla anılan, garbage-collected bir değişken depolama alanı vardır: değişkenler orada durur, çöp toplayıcı çalışınca kullanılmayan değişkenler temizlenip yer açılır. Java'daki "not enough heap space" hatası ve bu alanın `-Xmx` gibi bir parametreyle büyütülmesi bu bellek alanıyla ilgilidir.

> **Hocanın vurgusu:** Veri yapısı olan heap ile bu bellek alanının uzaktan yakından hiçbir ilgisi yoktur. İkisine de şans eseri aynı ad verilmiştir. (Hoca slayttaki "değildir" kelimesinin altını kırmızıyla çizdi.)

Hoca Türkçe karşılıklar konusunda da bir uyarı yaptı: heap ve stack için kullanılan "yığın" ve "yığıt" çevirileri farklı kaynaklarda birbirinin yerine kullanılabildiği için kavram karmaşası doğuyor. Bu yüzden derste İngilizce adlar (stack, heap) tercih ediliyor.

### 3.3 Heap ne işe yarar?

Heap, ikili ağaç yapısından gelen $\log n$ mertebesi sayesinde bazı işlemleri $n$ yerine $\log n$ mertebesinde yapmayı sağlar. Örneğin heap ile sıralama yapılabilir (heap sort): şimdiye kadar $n^2$ mertebesinde yapılan sıralama, en kötü durumda da $O(n \lg n)$'de yapılır (ekrandan, 01:15:00).

> **Ders sonrası not:** Hoca bir yerde "$n^2$'den $\log n$'e düşürdü" dedi; doğrusu $n^2$'den $n \log n$'edir.

### 3.4 Heap özelliği: max-heap ve min-heap

Heap'i heap yapan şey yapısal şekli değil, şu özelliktir: her düğümdeki değer, çocuklarının değerlerinden hep büyüktür ya da hep küçüktür.

İkili arama ağacında "soldakilerin hepsi küçük, sağdakilerin hepsi büyük" deniyordu. Heap'te böyle bir şey söylenmez. Tek garanti, bir düğümün çocuklarından büyük (ya da küçük) olmasıdır; iki çocuktan hangisinin büyük olduğu önemli değildir. Hoca bunu küçük bir tam ikili ağaç çizerek anlattı: bir ebeveynin çocukları 2 ve 5 olabilir, sırası önemli değildir; ama ebeveynin örneğin 8 gibi ikisinden de büyük bir değer olduğu garanti edilir. Bir üst düzeye çıkıldığında kök de çocuklarından büyüktür. Özyinelemeli olarak düşünülünce kök tüm elemanların en büyüğüdür.

- **Max-heap:** Her $i$ için $A[\text{parent}(i)] \ge A[i]$. Ebeveynler her zaman çocuklardan büyüktür ve en büyük eleman köktedir.
- **Min-heap:** Her $i$ için $A[\text{parent}(i)] \le A[i]$. Ebeveynler her zaman çocuklardan küçüktür ve en küçük eleman köktedir.

Bir algoritmanın her adımında kalan elemanların en büyüğüne erişmek gerekiyorsa max-heap kullanılır; en büyük eleman her zaman köktedir ve $O(1)$'de okunur. Kalanların en küçüğüyle ilerlemek gerekiyorsa min-heap kullanılır. Heap'in heap olarak kalmasını sağlayan özel fonksiyonların (aşağıda anlatılan) yazılması gerekir.

### 3.5 Hangisi heap? (ekrandan, 01:25:00)

Slaytta üç ağaç vardı:

```text
  (a) Max-heap          (b) Heap değil          (c) Heap değil
       10                    10                      10
      /  \                  /  \                    /  \
     5    7                5    7                  5    7
    / \   /                 \   /                 / \   /
   4   2 1                   2 1                 6   2 1
```

- (a): 10 > 5 ve 7; 5 > 4 ve 2; 7 > 1. Yapraklar zaten şartı sağlar. Tam ikili ağaçtır. Bu bir max-heap'tir. İkili arama ağacı değildir: 5'in altında 4 solda, 2 sağdadır; heap bunu garanti etmez.
- (b): Değerler şartı sağlıyor, ama 5'in sol çocuğu yokken sağ çocuğu var. Tam ikili ağaç yapısı bozulduğu için heap değildir.
- (c): Yapı (a) ile aynıdır, ama 5'in çocuğu 6, 5'ten büyüktür ($6 > 5$). Ebeveynin büyük olma şartı bozulduğu için heap değildir.

Demek ki iki şey kontrol edilir: ağacın tam ikili ağaç olması ve her ebeveynin çocuklarından büyük (max-heap) ya da küçük (min-heap) olması.

## 4. Heap'in Dizi ile Gösterimi

### 4.1 Neden dizi?

Heap'i tutmanın en kolay, en çabuk yolu dizi kullanmaktır. Ebeveyn-çocuk ilişkisi $2i$ ve $2i+1$ aritmetiğiyle kurulabildiği için heap genellikle düz bir diziyle gerçeklenir. Heap'in en fazla tutacağı eleman sayısı da genellikle sabittir. Dinamik dizi de kullanılabilir. Bağlı listeyle de yapılabilir ama `next` mantığıyla gidiş-geliş zorlaşır; ağaç düğümleriyle (sol çocuk, sağ çocuk) de kurulabilir. Derste yalnız dizi kullanılıyor.

### 4.2 İndis aritmetiği (ekrandan, 01:30:00)

Her düğüm bir dizi elemanına karşılık gelir:

- $A[1..A.\text{length}]$, $0 \le A.\text{heap\_size} \le A.\text{length}$.
- Ağacın kökü $A[1]$'dir. Hesap kolaylığı için 0. göz kullanılmaz (bazen oraya dizinin boyutu yazılır).
- $i$ gözündeki düğüm: $A[i]$; ebeveyni: $A[\lfloor i/2 \rfloor]$; sol çocuğu: $A[2i]$; sağ çocuğu: $A[2i+1]$.

Hoca örnekler verdi: 4. gözün ebeveyni $4/2 = 2$; 5. gözün ebeveyni $\lfloor 5/2 \rfloor = \lfloor 2{,}5 \rfloor = 2$. 3. gözün sol çocuğu $2 \cdot 3 = 6$, sağ çocuğu $2 \cdot 3 + 1 = 7$.

Slayttaki örnek heap:

```text
indis:  1   2   3   4   5   6   7   8   9   10
A    : 16  14  10   8   7   9   3   2   4   1

                 16(1)
              /         \
          14(2)          10(3)
         /     \        /     \
      8(4)    7(5)   9(6)    3(7)
      /  \    /
   2(8) 4(9) 1(10)
```

16'nın çocukları 2. ve 3. gözler (14, 10); 14'ün çocukları 4. ve 5. gözler (8, 7); 10'un çocukları 6. ve 7. gözler (9, 3); 8'in çocukları 8. ve 9. gözler (2, 4); 7'nin çocukları 10. ve 11. gözler olurdu, ama 11. göz yok (10 eleman var), bu yüzden 7'nin tek çocuğu (1) var.

### 4.3 Ebeveynler ilk $n/2$ gözde

Tam ikili ağaç olduğu için dizide hiç boş göz kalmaz ve ebeveyn düğümler dizinin ilk $n/2$ elemanında yer alır. 10 elemanlı örnekte $10/2 = 5$: 1-5. gözler çocuğu olan (ebeveyn) düğümler, 6-10. gözler yapraktır. Bu yüzden yalnız çocuğu olan düğümler üzerinde işlem yapmak gerekiyorsa $n/2$'ye kadar gitmek yeterlidir.

Heap yüksekliği kökün yüksekliğidir ve $\lg n$'dir. Bu yüzden heap ile yapılan bir işlemin mertebesi $\log n$, $n$ eleman için kabaca $n \log n$ olur.

### 4.4 En büyük (ya da en küçük) elemana erişim

Max-heap'te en büyük eleman köktür; çünkü kök ebeveynlerin de ebeveynidir. `heap_maximum` gibi bir fonksiyon yalnız `return A[1]` yapar; sabit zamanda, $O(1)$'de çalışır. Min-heap için `heap_minimum` de aynı şekilde `return A[1]` yapar.

## 5. Heap Oluşturma: Bottom-Up Yöntem ve MAX-HEAPIFY

Heap oluşturmanın iki yolu vardır: bottom-up ve top-down. İki yöntem aynı heap'i vermek zorunda değildir. Önemli olan ebeveynin büyük olması ve tam ikili ağaç şartının sağlanmasıdır; örneğin 8'in altında 5 ve 2'nin hangi sırayla durduğu önemli değildir.

### 5.1 Bottom-up yöntemin adımları (ekrandan, 01:40:00)

Genellikle daha sık kullanılan yöntem budur.

- **Adım 0:** Verilen sırayla veri yapısı (dizi) oluşturulur. Elemanlar karışık gelebilir.
- **Adım 1:** En son (en sağdaki) ebeveyn düğümden başlanarak heap parçası kontrol edilir ve heap haline getirilir (MAX-HEAPIFY). Heap şartı sağlanmıyorsa, şart sağlanana kadar en büyük çocukla yer değiştirilir.
- **Adım 2:** Bir önceki ebeveyn düğüm için Adım 1 işletilir.

En son ebeveyn $n/2$. düğümdür (10 elemanlı dizide 5). Sonra 4, 3, 2, 1. düğümlere bakılır. Bir düğümde yer değiştirme yapılırsa, aşağı inen değer için kontrol sürmelidir; çünkü değer daha da aşağıya gitmek zorunda kalabilir. Heapify (heap haline getirme) yaklaşımının özü budur.

```text
BUILD-MAX-HEAP(A, n)                 -> O(N)
  for i <- n/2 downto 1
      do MAX-HEAPIFY(A, i, n)

MAX-HEAPIFY(A, i, n)                 -> O(logN)
  l <- LEFT(i)
  r <- RIGHT(i)
  if l <= n and A[l] > A[i] then largest <- l else largest <- i
  if r <= n and A[r] > A[largest] then largest <- r
  if largest != i then
      exchange A[i] <-> A[largest]
      MAX-HEAPIFY(A, largest, n)
```

> **Ders sonrası not:** Karede slayttaki koşul "if largest = i then" olarak görünüyor. Doğrusu "if largest ≠ i then"dir; yer değiştirme ve özyinelemeli çağrı yalnız en büyük eleman düğümün kendisi değilse yapılır. Hoca da anlatımında "değiştirmemiz gerekiyorsa kalan kısmı tekrar heapify et" dedi.

MAX-HEAPIFY'da önce sol çocuğun, sonra sağ çocuğun düğümden (ya da o ana kadarki en büyükten) büyük olup olmadığına bakılır. İki `if` ile en büyüğün düğümün kendisi mi, sol çocuk mu, sağ çocuk mu olduğu bulunur (indis olarak tutulur).

### 5.2 MAX-HEAPIFY sezgisi (ekrandan, 01:40:00)

Hoca tahtada şu örneği çizdi: ebeveyn 7, sol çocuk 8, sağ çocuk 12; 12'nin de çocukları 10 ve 11 olsun.

- 7 ile 8 karşılaştırılır: largest = 8. Sonra 12 ile largest karşılaştırılır: 12 > 8, largest = 12.
- 7 ile 12 yer değiştirir: ebeveyn 12, çocuklar 8 ve 7 olur.
- Ama 7'nin indiği yerde çocukları 10 ve 11 vardır ve ikisi de 7'den büyüktür. MAX-HEAPIFY o alt ağaçta yeniden çağrılır: 7, 10 ve 11 arasında largest = 11; 7 ile 11 yer değiştirir. 7 gidebildiği yere kadar aşağı iner.

> **Hocanın vurgusu:** Heapify'da çocuklara bakılır, daha büyük olan varsa onunla yer değiştirilir. Ama bu yetmez; aşağı inen değerin de çocukları olabilir, onlar da gittiği yere kadar tekrar tekrar kontrol edilmelidir.

### 5.3 Örnek 1: 2, 9, 7, 6, 5, 8 (ekrandan, 01:45:00)

Dizi 6 elemanlıdır; indisler 1'den 6'ya. Son ebeveyn $6/2 = 3$. indistir.

```text
Başlangıç:        2
                /   \
               9     7
              / \   /
             6   5 8
```

- $i = 3$ (7): tek çocuğu 8. 8 > 7 olduğu için 8 yukarı, 7 aşağı. Bu parça artık heap: 8 → 7.
- $i = 2$ (9): çocukları 6 ve 5. Largest 9'un kendisi; değişiklik yok.
- $i = 1$ (2): çocukları 9 ve 8. 9 yukarı, 2 aşağı. Ama 2'nin indiği yerde çocukları 6 ve 5 var; largest 6. 6 yukarı, 2 aşağı.

```text
Sonuç:            9
                /   \
               6     8
              / \   /
             2   5 7
```

Dizi: 9, 6, 8, 2, 5, 7. Kontrol: 9 > 6 ve 8; 6 > 2 ve 5; 8 > 7.

### 5.4 Örnek 2: 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 (ekrandan, 01:50:00)

10 elemanlı dizi; indisler yine 1'den başlar. Amaç 16'yı köke taşımak, ebeveynin büyük olmasını garanti etmektir. Başlamak için çocuğa sahip son düğüm $10/2 = 5$. indistir.

```text
Başlangıç:           4
                  /     \
                 1       3
               /   \    /  \
              2    16  9    10
             / \   /
           14   8 7
```

- $i = 5$ (16): çocuğu 7. 16 daha büyük; değişiklik yok.
- $i = 4$ (2): çocukları 14 ve 8. Largest 14; 14 yukarı, 2 aşağı. 2'nin çocuğu olmadığı için bu parça bitti: 14 → (2, 8).
- $i = 3$ (3): çocukları 9 ve 10. Largest 10; 10 yukarı, 3 aşağı. Bitti.
- $i = 2$ (1): çocukları 14 ve 16. Largest 16; 16 yukarı, 1 aşağı. 1'in çocuğu 7 olduğu için MAX-HEAPIFY sürer: 7 yukarı, 1 aşağı. Bu parça 16 → (14, 7), 7 → 1 olur.
- $i = 1$ (4): çocukları 16 ve 10. 16 yukarı, 4 aşağı. 4'ün çocukları 14 ve 7: 14 yukarı, 4 aşağı. 4'ün çocukları 2 ve 8: 8 yukarı, 4 aşağı.

```text
Sonuç:              16
                  /     \
                14       10
               /  \     /  \
              8    7   9    3
             / \   /
            2   4 1
```

Dizi: 16, 14, 10, 8, 7, 9, 3, 2, 4, 1. Kontrol: 16 > 14 ve 10; 14 > 8 ve 7; 10 > 9 ve 3; 8 > 2 ve 4; 7 > 1. Yapraklara bakmaya gerek yoktur. Bu heap'in garanti ettiği şey yalnız en büyük elemanın kökte olması ve her ebeveynin çocuklarından büyük olmasıdır; dizide doğrudan kullanılabilen değer yalnız 16'dır.

Min-heapify bunun tersidir: büyüklük yerine küçüklük kontrolü yapılır; ebeveyn değeri küçük, çocuk değerleri büyük olur.

## 6. En Büyük Elemanı Heap'ten Almak

### 6.1 Algoritma (ekrandan, 01:55:00)

En büyük eleman kökte durur. Şimdi bu eleman heap'ten çıkarılıp başka bir yerde kullanılmak isteniyor; yani heap'te artık durmamalı ve heap, eleman sayısı bir azalmış olarak heap kalmaya devam etmeli.

- Heap boş olmamalı. Boş heap'ten eleman çekmek hata verir; bu yüzden önce $n \ge 1$ kontrolü yapılır.
- Kök elemanın kopyası çıkarılır: `max = A[1]`.
- Son düğüm kök düğüm yapılır: `A[1] = A[n]`.
- Bir az eleman sayısıyla MAX-HEAPIFY yapılır: `MAX_HEAPIFY(A, 1, n-1)` (heap boyutu 1 azaltılır).
- `max` değeri işlemler için çağırana döndürülür.
- Maliyet $O(\lg N)$.

Hoca son elemanı köke yazmanın heap yapısını "bilerek ve isteyerek elle bozmak" olduğunu vurguladı. Son eleman, üstündeki bütün ebeveynlerden küçük olduğu bilinen bir değerdir. Köke konunca heap bozulur; MAX-HEAPIFY bu değeri gitmesi gereken yere kadar aşağı "akıtır" ve kalanların en büyüğü yeniden köke çıkar. En kötü durumda değer yine en alta kadar iner; bu da ağaç yüksekliği kadar, yani $\log n$ mertebesinde işlemdir.

### 6.2 Örnek (ekrandan, 02:05:00)

```text
indis:  1   2   3   4   5   6   7   8   9   10
A    : 20  15   8  10   5   7   6   2   9   1

                 20
              /      \
            15         8
           /  \       / \
         10    5     7   6
        /  \   /
       2    9 1
```

Kontrol: 20 > 15 ve 8; 15 > 10 ve 5; 10 > 2 ve 9; 5 > 1; 8 > 7 ve 6. Tam ikili ağaç ve max-heap.

- 20, `max`'a kopyalanır. Son göz (1) köke yazılır, heap boyutu 9'a iner (slayttaki gösterimde 10. gözdeki 1 "heap'ten silindi", heap_size = 9).
- Kökteki 1 için MAX-HEAPIFY: 1, 15 ve 8 arasında 15 yukarı çıkar. 1, 10 ve 5 arasında 10 yukarı çıkar. 1, 2 ve 9 arasında 9 yukarı çıkar ve 1 en alta iner.

Sonuç dizisi: 15, 10, 8, 9, 5, 7, 6, 2, 1. Yeni kök 15, yani kalanların en büyüğüdür.

## 7. Bir Düğümün Değerini Artırmak

Aradan sonra hoca heap'in temel işlemlerinin heap oluşturma ve heapify olduğunu, bunların dışında en büyük elemanı almak, bir değeri değiştirmek ve eleman eklemek gibi işlemlerin de gerektiğini hatırlattı.

### 7.1 Algoritma (ekrandan, 02:10:00)

Heap'teki bir elemanın değeri değiştirilmek isteniyor (örneğin 8'i 15 yapmak).

- $k$ (yeni değer) mevcut değerden büyük-eşit olmalıdır. Değer küçülürse düğüm yerinde kalabilir; yukarı taşımaya gerek yoktur.
- $x$ düğümünün değeri $k$ yapılır. Bu da heap'i elle bozmaktır: yukarıda durması gereken bir değer aşağıda tutulmaktadır.
- Düğüm ebeveyn(ler)iyle karşılaştırılır; ebeveyninden büyük olduğu sürece ebeveyniyle yer değiştirir.
- Maliyet $O(\lg N)$: en fazla ağacın düzey sayısı kadar yer değiştirme yapılır.

Slayttaki akış şeması metne dökülünce:

```text
HEAP-INCREASE-KEY(A, i, key)
  if key >= A[i]:
      A[i] = key
      while i > 1 and A[parent(i)] < A[i]:
          A[i] <-> A[parent(i)]
          i = parent(i)
```

Hoca önce bir animasyonda bir düğümdeki 2 değerini 22 yaptı: 22 her adımda ebeveyniyle karşılaştırılıp yukarı taşındı ve sonunda köke çıktı.

<!-- BELİRSİZ: 2'nin 22 yapıldığı animasyonun hangi heap üzerinde olduğu okunan karelerde görünmüyor; altyazıda 22'nin 15 ile karşılaştırıldığı geçiyor, büyük olasılıkla 6.2'deki 20 köklü heap. -->

Kardeşlere bakmaya gerek yoktur. Yukarı çıkan değer eski ebeveynden büyüktür; eski ebeveyn de zaten (heap olduğu için) kendi çocuklarından büyüktü. Bu yüzden yalnız ebeveynlerle karşılaştırmak yeter.

### 7.2 Kitap örneği (ekrandan, 02:15:00)

Heap: 16, 14, 10, 8, 7, 9, 3, 2, 4, 1. 9. gözdeki 4 değeri 15 yapılıyor.

```text
(a) i = 9, değer 4         (b) 4 -> 15
          16                         16
        /    \                     /    \
      14      10                 14      10
     /  \    /  \               /  \    /  \
    8    7  9    3             8    7  9    3
   / \   /                    / \   /
  2   4 1                    2  15 1

(c) 15 > 8, yer değiştir   (d) 15 > 14, yer değiştir
          16                         16
        /    \                     /    \
      14      10                 15      10
     /  \    /  \               /  \    /  \
   15    7  9    3            14    7  9    3
   / \   /                    / \   /
  2   8 1                    2   8 1
```

- 15, ebeveyni 8 ile karşılaştırılır: 15 > 8, yer değiştirirler. 8 artık çocuk, 15 ebeveyndir.
- 15, ebeveyni 14 ile karşılaştırılır: 15 > 14, yer değiştirirler.
- 15, ebeveyni 16 ile karşılaştırılır: 15 < 16, durulur. 15 artık 2. düğümdedir.

Sonuç: 16, 15, 10, 14, 7, 9, 3, 2, 8, 1. Hâlâ tam ikili ağaçtır ve ebeveynler çocuklardan büyüktür. Hoca bunu "4 değerine sahiptim, beni büyüttüler, beslediler; heap'te yukarılara doğru çıkabildiğim yere kadar çıktım" diye anlattı. Aşağı inen 14 ve 8 için ek kontrol gerekmez; çünkü onlar zaten eski konumlarında altlarındaki düğümlerden büyüktü. Min-heap için aynı işlem küçüktür kontrolleriyle yapılır.

## 8. Heap'e Eleman Eklemek ve Top-Down Oluşturma

### 8.1 MAX-HEAP-INSERT

Değer artırma işlemi eleman eklemek için de kullanılır. Heap'te son eleman olarak yer olduğu varsayılır.

- Yeni eleman geldiği için heap boyutu bir artırılır (örneğin 8'den 9'a).
- Yeni değer doğrudan son göze yazılamaz: ya gerçekten ebeveyninden küçüktür ve heap bozulmaz, ya da ebeveyninden büyüktür ve yukarı taşınması gerekir.
- Bu yüzden önce son göze $-\infty$ (olabilecek en küçük tamsayı) yazılır. $-\infty$ hiçbir ebeveynden büyük olamayacağı için heap bozulmaz.
- Sonra HEAP-INCREASE-KEY ile bu gözün değeri yeni değere yükseltilir; değer gidebildiği kadar yukarı taşınır.

Maliyet yine $O(\log n)$'dir: değer artırma işlemine yalnız bir sabit adım eklenmiştir.

### 8.2 Top-down oluşturma (ekrandan, 02:25:00)

Bottom-up yöntemde ebeveynler ters sırada ($n/2$'den 1'e) gezilerek heapify yapılıyordu. Alternatif yöntemde elemanlar teker teker gelir ve her biri son eleman olarak eklenip yukarı taşınır. 1'den $n$'e doğru gidildiği için buna top-down denir.

```text
Bottom-Up:                       Top-Down:
BUILD-MAX-HEAP(A)                BUILD-MAX-HEAP-2(A)
1 A.heap-size = A.length         1 A.heap-size = 1
2 for i = A.length/2 downto 1    2 for i = 2 to A.length
3     MAX-HEAPIFY(A, i)          3     MAX-HEAP-INSERT(A, A[i])
```

### 8.3 İki yöntem aynı heap'i vermeyebilir

Hoca 1, 2, 3 dizisiyle iki yöntemi karşılaştırdı:

- **Bottom-up:** $n/2 = 1$; tek ebeveyn kök. Kök 1, çocukları 2 ve 3; largest 3. 3 ile 1 yer değiştirir. Sonuç dizi: 3, 2, 1.
- **Top-down:** 1 eklenir (tek eleman, değişiklik yok). 2 eklenir: önce $-\infty$, sonra 2; 2 > 1 olduğu için yer değiştirir, dizi 2, 1. 3 eklenir: önce $-\infty$, sonra 3; 3 > 2 (ebeveyni) olduğu için yer değiştirir. Sonuç dizi: 3, 1, 2.

3, 2, 1 ve 3, 1, 2 dizilerinin ikisi de geçerli max-heap'tir ama birbirine eşit değildir. Garanti edilen yalnız iki şey vardır: ebeveynlerin çocuklardan büyük olması ve yapının tam ikili ağaç olması.

Hoca iki yöntemin de her eleman için $\log n$ mertebesinde çalıştığını, $n$ eleman için de $n \log n$ mertebesinde heap yaratılabileceğini söyledi.

> **Ders sonrası not:** Slaytta BUILD-MAX-HEAP için $O(N)$ yazıyor. Bottom-up yöntemin sıkı sınırı gerçekten $O(n)$'dir; çünkü düğümlerin çoğu alt düzeylerdedir ve oralarda MAX-HEAPIFY çok kısa sürer. $n \log n$ bir üst sınırdır. Top-down yöntem ise büyük olasılıkla en kötü durumda $O(n \log n)$'dir (her ekleme köke kadar çıkabilir).

## 9. Heap Sort

### 9.1 Algoritma

Heap'in en temel kullanım alanı sıralamadır.

- Giriş dizisi $A[1..n]$ önce BUILD-MAX-HEAP ile max-heap yapılır (bottom-up, MAX-HEAPIFY çağrılarak).
- En büyük eleman $A[1]$'dedir. Bilerek heap'in son elemanıyla yer değiştirilir (heap bozulur).
- Heap boyutu bir azaltılır; son göze konan en büyük eleman artık heap'in parçası değildir ama dizide yerinde durur.
- Yeni kökte MAX-HEAPIFY çağrılır.
- Heap'te tek eleman kalana kadar sürdürülür.

Yer değiştirme $O(1)$, heapify $O(\log n)$'dir. Bu işlem $n-1$ kez yapıldığı için toplam $O(n \log n)$ olur.

> **Ek bilgi (derste anlatılmadı):** Heap sort, sıralamayı dizinin kendi içinde yapar; ek bir dizi gerektirmez (yerinde, in-place sıralama). Sıralanmış kısım dizinin sonunda büyür, heap kısmı başta küçülür.

### 9.2 Örnek 1: kitap örneği (ekrandan, 02:30:00)

Başlangıç heap'i: 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 (kontrol: 16 > 14, 10; 14 > 8, 7; 10 > 9, 3; 8 > 2, 4; 7 > 1).

Her satırda kök son elemanla yer değiştiriyor, heap boyutu azalıyor, MAX-HEAPIFY sonrası heap ve `|` işaretinin sağında sıralanmış kısım gösteriliyor:

```text
16 <-> 1, heapify: 1 -> 14 ile, 8 ile, 4 ile yer değiştirir
   14  8 10  4  7  9  3  2  1 | 16
14 <-> 1, heapify: 1 -> 10 ile, 9 ile
   10  8  9  4  7  1  3  2 | 14 16
10 <-> 2, heapify: 2 -> 9 ile, 3 ile
    9  8  3  4  7  1  2 | 10 14 16
 9 <-> 2, heapify: 2 -> 8 ile, 7 ile
    8  7  3  4  2  1 | 9 10 14 16
 8 <-> 1, heapify: 1 -> 7 ile, 4 ile
    7  4  3  1  2 | 8 9 10 14 16
 7 <-> 2, heapify: 2 -> 4 ile
    4  2  3  1 | 7 8 9 10 14 16
 4 <-> 1, heapify: 1 -> 3 ile
    3  2  1 | 4 7 8 9 10 14 16
 3 <-> 1, heapify: 1 -> 2 ile
    2  1 | 3 4 7 8 9 10 14 16
 2 <-> 1
    1 | 2 3 4 7 8 9 10 14 16
```

Sonuç: 1, 2, 3, 4, 7, 8, 9, 10, 14, 16. Hoca ilk adımda 1'in kökten 14, 8 ve 4 ile yer değiştirerek aşağı indiğini, ikinci adımda 1'in eskiden sol alt ağaçtayken bu kez sağ alt ağaca geçtiğini gösterdi; bunun bir önemi yoktur, tek garanti ebeveynlerin büyük olmasıdır. Heap boyutu azaldıkça dizinin sonundaki elemanlar hâlâ dizide durur ama heap'le bağları "koparılmış" olarak düşünülür.

**Soru:** En büyük değeri kopardığımızda onun yerine ne yazıyoruz? Orası boş kalmayacağına göre... **Cevap:** Son değer yazılır; yani 1 ile 16 yer değiştirir. Kasıtlı olarak ebeveynlerinden küçük olduğu bilinen bir değer, yani son eleman seçilir. Başka bir eleman da yazılabilirdi, ama o zaman her seferinde hangisinin yazılacağına karar vermek için ek kontroller gerekirdi; varsayım olarak hep son elemanla yer değiştirmek bu sorunu ortadan kaldırır.

### 9.3 Örnek 2: 2, 9, 7, 6, 5, 8 (ekrandan, 02:45:00)

Hoca bu örneği önce doğrudan dizi üzerinde, sonra ağaç çizerek gösterdi. İlk üç eleman (2, 9, 7) ebeveyn, son üç eleman yapraktır.

**Aşama 1 (heap oluşturma):** $n/2 = 3$'ten başlanır.

```text
2 9 7 6 5 8     i = 3: 7'nin çocuğu 8, yer değiştir
2 9 8 6 5 7     i = 2: 9'un çocukları 6 ve 5, değişiklik yok
2 9 8 6 5 7     i = 1: 2'nin çocukları 9 ve 8, 9 ile yer değiştir
9 2 8 6 5 7     2'nin yeni çocukları 6 ve 5, 6 ile yer değiştir
9 6 8 2 5 7     heap hazır
```

Kontrol: 9 > 6 ve 8; 6 > 2 ve 5; 8 > 7. Hoca burada heap'in aslında yalnız bellekteki bir dizinin sayısal organizasyonu olduğunu, ağaç şeklinin bu organizasyonu anlamayı kolaylaştıran bir gösterim olduğunu vurguladı.

**Aşama 2 (kök/max değiştirme):** `|` işaretinin sağı sıralanmış kısımdır.

```text
9 6 8 2 5 7
7 6 8 2 5 | 9     9 <-> 7; 7'nin çocukları 6 ve 8, 8 ile yer değiştir
8 6 7 2 5 | 9
5 6 7 2 | 8 9     8 <-> 5; 5'in çocukları 6 ve 7, 7 ile yer değiştir
7 6 5 2 | 8 9
2 6 5 | 7 8 9     7 <-> 2; 2'nin çocukları 6 ve 5, 6 ile yer değiştir
6 2 5 | 7 8 9
5 2 | 6 7 8 9     6 <-> 5; 5 > 2, değişiklik yok
5 2 | 6 7 8 9
2 | 5 6 7 8 9     5 <-> 2; tek eleman kaldı
```

Sonuç: 2, 5, 6, 7, 8, 9. Kontrol: $2 < 5 < 6 < 7 < 8 < 9$. Hoca kontrolü önce "büyüktür" diye okudu, hemen "küçüktür" diye düzeltti.

### 9.4 Karmaşıklık özeti

Heap'in özelliklerini kullanarak iç içe iki döngülü $O(n^2)$ sıralamalardan $O(n \log n)$'e inilir. Her eleman için yer değiştirmeden sonra en fazla $\log n$ işlem yapılır; $n$ eleman için toplam $n \log n$ işlemle sıralama tamamlanır.

## Örnek Sorular

### Soru 1 (ekrandan, 00:10:00)

Aşağıdaki ikili arama ağacını preorder (kök önde) olarak gezin.

```text
              25
           /      \
         19        37
        /  \         \
       5    22        44
        \   /        /  \
         8 20       41   50
```

**Çözüm (derste verildi):** VLR sırasıyla: 25 (1), 19 (2), 5 (3), 8 (4), 22 (5), 20 (6), 37 (7), 44 (8), 41 (9), 50 (10). Cevap: 25, 19, 5, 8, 22, 20, 37, 44, 41, 50.

### Soru 2 (derste sözlü, 00:11:18)

21 kişilik bir sınıfta öğrenciler çember şeklinde dizilmiştir. 1. öğrenciden başlanarak her 3. öğrenci elenir; son kalan iki öğrenci sınıf başkanı ve yardımcısı seçilir. Bu iki öğrenci kimdir?

**Çözüm (derste verildi):** Josephus problemidir; dairesel bağlı listeyle kolayca çözülür. Önce 3, 6, 9, ... elenir ve sayma çember üzerinde sürer. Son kalan iki öğrenci 2 ve 16 numaralılardır (python simülasyonuyla doğrulandı).

### Soru 3 (ekrandan, 00:15:00)

Elimizde push, pop ve reverse işlemleri olan özel bir yığıt var. Reverse işlemi yığıttaki sırayı ters çevirir (dipten üste 1, 2, 3 olan yığıt 3, 2, 1 olur). Yalnız bu yığıtı kullanarak bir kuyruk en verimli nasıl gerçeklenir?

**Çözüm (derste verildi):**

- enqueue(x): `push(x)`. Kuyruğa en son gelen en son çıkacağı için yığıtın üstüne konur.
- dequeue(): `reverse(); pop(); reverse();`. Örneğin dipten üste 1, 2, 3, 4 olan yığıt reverse ile 4, 3, 2, 1 olur; pop ile kuyruğun başındaki 1 alınır; ikinci reverse ile 2, 3, 4 haline geri dönülür. Sonraki push (5) doğru yere, sona gelir.

### Soru 4 (ekrandan, 00:20:00)

`abcde2fgh1ijk0lmn3oprs1` biçimindeki casus kodu çözülürken her rakam $k$, kendisinden önce kalan son $k$ harfin silineceğini gösterir. Verilen kod için hangi veri yapısının kullanılması uygundur? Fonksiyon çalışırken toplam kaç push ve kaç pop yapılır? Silmelerden sonra kaç karakter kalır?

**Çözüm (derste verildi):** Uygun veri yapısı yığıttır. Harfler push edilir, rakam $k$ için $k$ kez pop yapılır.

```text
a b c d e  push        -> a b c d e
2          pop, pop     -> a b c
f g h      push        -> a b c f g h
1          pop          -> a b c f g
i j k      push        -> a b c f g i j k
0          (pop yok)    -> a b c f g i j k
l m n      push        -> a b c f g i j k l m n
3          pop x3       -> a b c f g i j k
o p r s    push        -> a b c f g i j k o p r s
1          pop          -> a b c f g i j k o p r
```

Kalan: `abcfgijkopr`, 11 karakter. Push sayısı harf sayısı kadardır: 18. Ara pop'lar $2+1+0+3+1 = 7$, sonda kalan 11 karakter de pop edilerek okunur; toplam 18 pop. Yığıttan okununca karakterler ters sırada (r, p, o, k, ..., c, b, a) çıkar, ters çevrilerek okunur. Her işlem $O(1)$ olduğu için toplam süre $O(n)$'dir (python ile doğrulandı).

> **Ders sonrası not:** Hoca "18 tane rakam var" dedi; doğrusu 18 harftir. Push edilen karakterler harflerdir.

### Soru 5 (derste sözlü, 00:23:13)

Doğru mu yanlış mı?

- (a) Derleyiciler bazı işlemler için ağaç yapısı kullanabilir.
- (b) Derleyiciler yığıt yapısını kullanabilir.
- (c) Dosya sistemleri ikili ağaç yapısından faydalanır.
- (d) Çift bağlı listede yer alan herhangi bir elemanı silmek için silinecek elemanın adres bilgisi yeterlidir.
- (e) $n$ elemanlı sıralı bir diziye yeni bir eleman eklendiğinde insertion sort da bubble sort da en kötü durumda $O(n)$'de sıralar.

**Çözüm (derste verildi):**

- (a) Doğru. Örneğin aritmetik işlemlerde ya da çağrı ağaçlarını tutmak için.
- (b) Doğru. Fonksiyon çağrı yığıtı (function call stack).
- (c) Yanlış. Dosya sistemleri ağaç kullanır ama çok çocuklu ağaç kullanır; doğrudan ikili ağaçla gerçeklenmez. "İkili" kelimesi hızlı okurken gözden kaçabilir.
- (d) Doğru. Düğümün `prev` ve `next` alanlarıyla öndekine ve arkadakine ulaşılır; tek işaretçiyle silme ve dört bağın güncellenmesi yapılabilir.
- (e) Yanlış. Örnek: 2, 4, 6, 8, 10 dizisinin sonuna 1 gelsin. Insertion sort 1'i karşılaştırıp yer değiştirerek beş adımda başa taşır, $O(n)$. Bubble sort ise her geçişte 1'i yalnız bir göz sola taşıyabilir; bu yüzden $n$ mertebesinde geçiş gerekir ve karmaşıklık $O(n^2)$ olur.

Cevap anahtarı: D, D, Y, D, Y.

### Soru 6 (ekrandan/derste sözlü, 00:28:10)

```c
for (k = 1; k < n; k = k * 2)
    sum++;
```

Bu döngüde toplam kaç kez toplama işlemi yapılır? Şıklar: $n$, $n/2$, $\log n$, $n \cdot n$, hiçbiri.

**Çözüm (derste verildi):** $k$ değerleri 1, 2, 4, 8, ... diye ikiyle çarpılarak büyür; $n$'e ulaşana kadar $\log n$ mertebesinde adım atılır. Cevap: $\log n$ (C şıkkı).

### Soru 7 (derste sözlü, 00:29:49)

Aşağıdaki senaryolarda uygun olan en iyi algoritmayla en kötü durum karmaşıklığı sırasıyla nedir?

- Sırasız dizide verilen bir elemanın yerini bulmak.
- Sıralı dizide verilen bir elemanın yerini bulmak.
- Sıralı bağlı listede verilen bir elemanın yerini bulmak.
- Sıralı çift yönlü bağlı listede verilen bir elemanın yerini bulmak.

**Çözüm (derste verildi):**

- Sırasız dizi: $O(n)$. Teker teker bakmak en iyisidir. Önce sıralamak $n \log n$, sonra aramak ek maliyet getirir.
- Sıralı dizi: $O(\log n)$. İkili arama (binary search) kullanılır.
- Sıralı bağlı liste: $O(n)$. İndis bilgisi olmadığı için ikili arama kullanılamaz. Hem `head` hem `tail` tutulsa da orta noktayı bulmak için her seferinde $n/2$ kez `next` yapmak gerekir.
- Sıralı çift yönlü bağlı liste: $O(n)$. Çift yönlü olmak aramada bir avantaj getirmez; yine bir uçtan başlayıp teker teker ilerlenir.

Soru sıralama istemiyordu; her senaryonun karmaşıklığı soruluyordu.

### Soru 8 (derste sözlü, 00:32:49)

Labirentte çıkışı arayan fare problemi için en uygun veri yapısı nedir? Neden?

**Çözüm (derste verildi):** Yığıt. Fare her adımda hareketleri (sol, sağ, yukarı, aşağı) aynı sırayla dener ve yaptığı hareketi yığıta koyar. Çıkmaza girince son hareketin tersini yaparak geri gelir ve hareketi yığıttan pop eder. En son yapılan hareketin ilk geri alınması gerektiği için bu bir "undo" problemidir; yığıt bunu doğal olarak sağlar.

### Soru 9 (ekrandan, 00:40:00)

Aşağıdaki fonksiyon, `head` 2 → 4 → 6 → 8 → NULL listesinin başını gösterirken ne yazdırır? Fonksiyon genel olarak ne yapar?

```c
void mystery(struct node* head){
  if (head==NULL) return;
  mystery(head->next);

  printf("%d ", head->data);
}
```

**Çözüm (derste verildi):** Fonksiyon önce `head->next` ile kendini çağırır; NULL'a gelinene kadar 2, 4, 6, 8 düğümleri için çağrılar birikir. NULL'da `return` edilir. Geri dönüşte her çağrı kendi `printf` satırını işletir: önce 8, sonra 6, 4, 2. Çıktı: `8 6 4 2`. Fonksiyon bağlı listenin bütün düğümlerinin değerlerini sondan başa doğru yazdırır.

Fonksiyon, `struct node` tanımı ve 2, 4, 6, 8 listesini kuran bir `main` eklenerek `gcc -Wall` ile derlenip çalıştırıldı; çıktı `8 6 4 2` oldu (`main` derste yazılmadı).

### Soru 10 (derste sözlü, 00:41:23)

$n$ elemanlı bir dizi üzerinde gerçeklenmiş dairesel kuyrukta yalnız son elemanı gösteren `rear` verilmiştir. Yeni gelen eleman hangi indise eklenir?

**Çözüm (derste verildi):** `(rear + 1) % n`. Mantık olarak bir sonraki göz `rear + 1`'dir; ama yapı dairesel olduğu için dizinin sonundan başa dönmek gerekir. Mod $n$ almak bunu sağlar. Hedef gözde değer olup olmadığını düşünmeye gerek yoktur; soru yalnız sonraki gözü istiyor.

### Soru 11 (ekrandan, 01:25:00)

Aşağıdaki üç ağaçtan hangileri heap'tir? (Ağaçlar 3.5'te verildi.)

**Çözüm (derste verildi):** (a) max-heap'tir. (b) heap değildir: 5'in sol çocuğu yokken sağ çocuğu var, tam ikili ağaç değil. (c) heap değildir: 5'in çocuğu 6, ebeveyninden büyük ($6 > 5$).

### Soru 12 (ekrandan, 02:45:00)

2, 9, 7, 6, 5, 8 dizisini heap sort ile sıralayın.

**Çözüm (derste verildi):** Aşama 1'de heap 9, 6, 8, 2, 5, 7 olarak kurulur; aşama 2'de kök her adımda son elemanla yer değiştirilip heapify edilir. Sonuç: 2, 5, 6, 7, 8, 9 (adımlar 9.3'te; python ile doğrulandı).

## Dersin Toparlaması

Dersin ilk bölümünde quiz soruları üzerinden önceki haftaların konuları pekiştirildi: ağaç gezintisi, Josephus problemi ve dairesel bağlı liste, yığıtın kuyruk gerçeklemede, kod çözmede ve labirentte geri izlemede kullanımı, çift bağlı listede silme, döngü ve arama karmaşıklıkları, dairesel kuyruk. Ardından ikili arama ağacında arama, ekleme ve üç durumlu silme tekrar edildi ve dengesiz ağaçların $O(n)$'e kadar kötüleşebileceği, AVL gibi dengeleme politikalarının bunu önlediği hatırlatıldı.

Haftanın asıl konusu heap'ti. Heap, tam ikili ağaç yapısında olan ve her ebeveynin çocuklarından büyük (max-heap) ya da küçük (min-heap) olmasını garanti eden bir veri yapısıdır; dizide 1. gözden başlayarak $i/2$, $2i$ ve $2i+1$ aritmetiğiyle tutulur. MAX-HEAPIFY, BUILD-MAX-HEAP (bottom-up), en büyük elemanı alma, değer artırma ve eleman ekleme (top-down oluşturma) işlemleri işlendi; bu işlemlerin $\log n$ mertebesinde olması, heap sortun en kötü durumda da $O(n \log n)$ ile sıralama yapmasını sağlar.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
