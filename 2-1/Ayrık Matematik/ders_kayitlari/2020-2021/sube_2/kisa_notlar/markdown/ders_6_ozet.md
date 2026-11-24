# Ders 6 Çalışma Özeti

## Genel Konular

- Bağıntı özellikleri üzerine örnekler (önceki bölümün kalan slaytları)
  - Yansımalı (refleksif), simetrik, ters simetrik (antisimetrik) ve geçişken (transitif) bağıntı tanımları gerçel ve tam sayılar üzerindeki örneklerle tekrar edildi.
  - Simetri tanımı: $R$ simetriktir ancak ve ancak $\forall x \forall y\,[(x,y)\in R \rightarrow (y,x)\in R]$ (ekrandan, 00:15:00).
    - Simetrik örnekler: $R_3=\{(a,b)\mid a=b \lor a=-b\}$, $R_4=\{(a,b)\mid a=b\}$, $R_6=\{(a,b)\mid a+b\le 3\}$.
    - Simetrik olmayanlar: $R_1=\{(a,b)\mid a\le b\}$ ($3\le 4$ ama $4\not\le 3$), $R_2=\{(a,b)\mid a>b\}$, $R_5=\{(a,b)\mid a=b+1\}$.
  - Bir bağıntının bir özelliği taşımadığını göstermek için tek bir aksine örnek (counterexample) yeterlidir.
  - 0-1 matris gösterimi: yansımalı bağıntıda köşegenin tamamı 1'dir; simetrik bağıntıda matris köşegene göre simetriktir. Bağıntı matrisi genel olarak simetrik olmak zorunda değildir.
  - Yönlü çizge (digraph) üzerinden özellik belirleme örnekleri.
  - Bağıntının kuvvetleri: $R^n$, $R$'nin kendisiyle $n$ kez bileşkesidir; $(x,y)\in R^n$ ancak ve ancak $R$'de $x$'ten $y$'ye $n$ uzunluğunda bir yol vardır (ekrandan, 00:25:00).
- Algoritma kavramı
  - Algoritma: bir hesaplama yapmak ya da bir problemi çözmek için sonlu (finite) ve kesin (precise) komutlar/buyruklar kümesi (ekrandan, 00:30:00).
  - Kesinlik, adımların işlemcinin ya da dilin komut kümesindeki işlemlerle ifade edilebilmesi demektir.
  - İfade biçimleri: doğal dil, sözde kod (pseudocode), akış diyagramı, programlama dili.
  - Algoritma ile problem çözüm yaklaşımı (approach) farklıdır; yaklaşımı sıralı, kesin ve sonlu adımlara dökmek algoritmadır.
  - Özellikler (ekrandan, 00:35:00): giriş, çıkış, doğruluk, sonluluk, etkililik, genellik.
- Arama algoritmaları
  - Arama problemi: $a_1,\dots,a_n$ listesinde $x$'in konumunu bulmak; yoksa 0 döndürmek (ekrandan, 00:40:00).
  - Doğrusal (linear) arama: baştan sona tek tek karşılaştırma.
  - İkili (binary) arama: sıralı dizide orta noktaya ($m=\lfloor (i+j)/2\rfloor$) bakıp arama aralığını her adımda yarıya indirme (ekrandan, 00:45:00). En kötü durumda yaklaşık $\log_2 n$ adım.
  - Sözü edilen diğer aramalar: üçlü (ternary) arama, interpolasyon araması, hash ile arama.
- Sıralama algoritmaları
  - Kabarcık (bubble) sıralama (ekrandan, 00:50:00), araya ekleme (insertion) sıralama (ekrandan, 00:55:00), seçmeli (selection) sıralama.
- Öklid algoritması ve OBEB
  - $\gcd(m,n)=\gcd(n, m \bmod n)$; ikinci sayı 0 olana kadar sürer (ekrandan, 01:00:00).
  - Diğer çözüm: ardışık tam sayı kontrol algoritması (ekrandan, 01:05:00) ve asal çarpanlara ayırma yaklaşımı.
- Algoritma tasarım yöntemleri (ekrandan, 01:20:00)
  - Brute force, divide and conquer, decrease and conquer, transform and conquer, space-time tradeoff, greedy, dinamik programlama, iterative improvement, backtracking, branch and bound.
  - Algoritma analizinde iki ölçüt: zaman verimliliği ve bellek verimliliği.
  - Önemli problem türleri: sıralama, arama, metin işleme, çizge, kombinasyon, geometrik ve sayısal problemler.
- Temel veri yapıları (ekrandan, 01:30:00)
  - Listeler (dizi, bağlantılı liste, string), yığın (stack), kuyruk (queue), öncelikli kuyruk, çizge, ağaç, küme.
  - Bellek fiziksel olarak tek boyutludur; çok boyutlu yapılar mantıksal düzeydedir.
- Yığın uygulamaları: infix, prefix, postfix gösterimleri (ekrandan, 01:45:00)
  - Infix ifadenin iki yığınla (operand ve operatör yığını) değerlendirilmesi.
  - Prefix ve postfix ifadelerin tek yığınla değerlendirilmesi.
  - Dönüşümler: infix-postfix, infix-prefix, postfix-infix, prefix-postfix, prefix-infix, postfix-prefix.
  - Parantez dengesinin yığınla kontrolü ve bir stringin yığınla ters çevrilmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kitap slaytlarındaki hatalar
  - Yönlü çizge örneklerinin bazı açıklamalarında harfler yanlış yazılmış; örnekte görünen kenarlara göre karar verilmelidir.
  - İkinci örnekte geçişkenliği bozan durum $a\to b$, $b\to d$ varken $a\to d$ olmamasıdır.
- Simetri ve ters simetri birlikte sağlanabilir
  - Yalnız $a$'da döngü olan bir bağıntı hem simetrik hem antisimetriktir. İkisinin birlikte sağlanmadığı ya da ikisinin de sağlanmadığı durumlar da vardır.
- Algoritma ile yaklaşım farkı
  - "Matrisi baştan sona gezer, karşılaştırırım" bir yaklaşımdır. Bunu sıralı, kesin, sonlu adımlarla yazmak algoritmadır.
  - Asal çarpanlara ayırarak OBEB bulma doğrudan bir algoritma değildir, çünkü "sayının asal çarpanlarını ver" diye hazır bir komut yoktur; içinden başka bir problem çıkar.
- İkili aramanın gücü
  - 1024 elemanlı sıralı dizide en kötü durumda yaklaşık 10 karşılaştırmayla elemanın varlığı ya da yokluğu anlaşılır.
- Infix, prefix ve postfix'i ezberlemeye gerek yok
  - Operatör ortadaysa infix, öndeyse prefix, sondaysa postfix. Ağaçlardaki inorder, preorder, postorder dolaşmalarıyla aynı mantıktır.
- Operand sırası
  - Postfix değerlendirmede ilk çekilen $S_1$, ikinci çekilen $S_2$ olmak üzere $S_2 \;\text{op}\; S_1$ hesaplanır. Prefix değerlendirmede $S_1 \;\text{op}\; S_2$ hesaplanır.
  - Infix değerlendirme slaytında bölme ve çıkarmada hangi operandın solda olacağı yazılmamış; ikinci çekilen operand sola yazılmalıdır.
- Prefix ve postfix ifadelerde parantez ve operatör önceliği kontrolü gerekmez; bu yüzden derleyiciler için hesaplama kolaylaşır.

## Kısa Tekrar Notları

- Bir bağıntı özelliğinin sağlanmadığını göstermek için bir aksine örnek yeter.
- Yansımalı bağıntının matrisinde köşegen 1; simetrik bağıntının matrisi köşegene göre simetrik.
- $(x,y)\in R^n$ ancak ve ancak $x$'ten $y$'ye $n$ uzunluğunda yol var.
- Algoritmanın özellikleri: giriş, çıkış, doğruluk, sonluluk, etkililik, genellik.
- Arama sonucu konumdur; bulunamazsa 0 döndürülür.
- İkili arama yalnız sıralı dizide çalışır; en kötü durumda yaklaşık $\log_2 n$ adım.
- Kabarcık sıralamada her geçişin sonunda en büyük eleman sona yerleşir; takas olmayan bir geçişte durulabilir.
- Araya ekleme sıralamasında doğru konum doğrusal aramayla bulunur, aradaki elemanlar kaydırılır.
- Seçmeli sıralama $n^2$ mertebesinde karşılaştırma yapar.
- Öklid: $\gcd(60,24)=\gcd(24,12)=\gcd(12,0)=12$.
- Kuyruk FIFO (enqueue/dequeue), yığın LIFO (push/pop).
- Dizi: bitişik bellek, rastgele erişim. Bağlantılı liste: dağınık düğümler, araya ekleme kolay, rastgele erişim yok.
- Infix değerlendirme iki yığın; prefix ve postfix değerlendirme tek yığın.
- Infix'ten prefix'e doğrudan dönüşüm yerine: ifadeyi ters çevir, parantezleri çevir, postfix dönüşümü uygula, sonucu ters çevir.

## Detaylı Açıklamalar

- Bağıntı özellikleri ve yönlü çizgeler
  - Bir bağıntının yönlü çizgesinde yansımalılık her düğümde döngü (loop) olmasıdır. Simetri, her $a\to b$ kenarının karşılığı $b\to a$'nın da bulunmasıdır. Ters simetri, $a\ne b$ için $a\to b$ ve $b\to a$'nın birlikte bulunmamasıdır. Geçişkenlik, $a\to b$ ve $b\to c$ varken $a\to c$'nin de bulunmasıdır.
  - Örnek 2 (ekrandan, 00:20:00): düğümler $a,b,c,d$; kenarlar $a\to b$, $b\to d$, $d\to b$. Döngü olmadığı için yansımalı değil; $a\to b$ olup $b\to a$ olmadığı için simetrik değil; $b\to d$ ve $d\to b$ birlikte olduğu için antisimetrik değil; $a\to b$, $b\to d$ varken $a\to d$ olmadığı için geçişken değil. Slayttaki geçişkenlik açıklaması ($a\to c$, $c\to b$) hatalıdır.
  - Yalnız $a$'da döngü bulunan örnekte bağıntı yansımalı değildir ama simetrik, antisimetrik ve geçişkendir. <!-- BELİRSİZ: Örnek 1, 3 ve 4'ün kenar kümeleri karelerde yok; yalnız altyazıdan çıkarıldı. -->
- Bağıntının kuvvetleri (ekrandan, 00:25:00)
  - $R=\{(a,b),(b,c),(c,d),(d,b)\}$ için $R^2=\{(a,c),(b,d),(c,b),(d,c)\}$, $R^3=\{(a,d),(b,b),(c,c),(d,d)\}$, $R^4=R$ olur (python ile doğrulandı). Bu, matrisin kuvvetlerini almaya karşılık gelir; çizgeler konusunda yol sayısı olarak tekrar görülecektir.
- Algoritma ve özellikleri
  - Maksimum bulma örneği (ekrandan, 00:30:00): ilk eleman geçici maksimum seçilir; sıradaki eleman geçici maksimumla karşılaştırılır, büyükse atanır; son elemana kadar tekrar edilir. Bu adımlar atama, karşılaştırma ve döngü gibi işlemcide bulunan işlemlerdir, bu yüzden kesindir; sonlu sayıda adımdır, bu yüzden sonludur.
  - Sözde kodda maksimumun değeri yerine indisi de tutulabilir; indis bilindiği için değer her zaman diziden okunabilir.
  - Hoca işlem sayısını yaklaşık $2n$ olarak hesapladı: döngü $2..n$ arasında döner, her turda bir karşılaştırma ve gerekirse bir atama yapılır.
  - Genellik: aynı algoritma uygun operatörlerle tam sayılar yerine stringler ya da nesneler için de çalıştırılabilir. Sıralama algoritması öğrencileri numarasına, notuna ya da adına göre; meyveleri şeker oranına göre sıralayabilir.
- Arama
  - Doğrusal aramada aranan eleman bulununca durulur. 200 sayfalık kitapta 40. sayfayı baştan tek tek arayan 40 bakış yapar. En küçük ya da en büyük eleman aranıyorsa dizinin sonuna kadar gitmek gerekir.
  - İkili arama sözde kodu (ekrandan, 00:45:00): $i:=1$, $j:=n$; $i<j$ oldukça $m:=\lfloor (i+j)/2\rfloor$; $x>a_m$ ise $i:=m+1$, değilse $j:=m$. Döngüden sonra $x=a_i$ ise konum $i$, değilse 0.
  - 1-200 arası sayfalarda 40 aranırken arama aralığı her adımda yarılanır; slayttaki algoritma 8 turda 40'ı bulur (python ile doğrulandı). Doğrusal aramadaki 40 bakışa göre çok daha azdır.
  - Hoca, üçlü aramayı orta nokta yerine aralığın $2/3$'üne bakma, interpolasyon aramasını ise kitapta sayfanın yerini tahminle bulmaya benzer bir izdüşüm hesabı olarak anlattı.
- Sıralama
  - Kabarcık sıralama (ekrandan, 00:50:00): `for i := 1 to n-1`, `for j := 1 to n-i`, $a_j>a_{j+1}$ ise takas. Örnek $3,2,4,1,5$: 1. geçiş $2,3,1,4,5$; 2. geçiş $2,1,3,4,5$; 3. geçiş $1,2,3,4,5$; 4. geçişte takas olmadığı için bitirilebilir.
  - Araya ekleme sıralaması (ekrandan, 00:55:00): $j=2..n$ için $a_j$'nin doğru konumu $i$ doğrusal aramayla bulunur, $a_j$ yedeklenir ($m:=a_j$), aradaki elemanlar bir sağa kaydırılır, $a_i:=m$ yazılır. Aynı örnekte 1 geldiğinde 4, 3, 2 birer kaydırılır ve 1 başa yazılır.
  - Seçmeli sıralama her turda kalan elemanların en küçüğünü bulup başa getirir; karşılaştırma sayıları azalarak toplanır ve $n^2$ mertebesinde bir karmaşıklık çıkar.
- Öklid algoritması
  - $\gcd(60,24)$: $60 \bmod 24 = 12$, sonra $24 \bmod 12=0$, sonuç 12. $\gcd(6,12)$: ilk adımda $6 \bmod 12=6$ olduğundan $\gcd(12,6)$ olur, sonra $\gcd(6,0)=6$. Büyük sayı sağda yazılsa bile bir adım sonra yer değiştirir.
  - Ardışık tam sayı kontrolü (ekrandan, 01:05:00): küçük sayı $T$'ye atanır; $m$ ve $n$ ikisi de $T$'ye kalansız bölünene kadar $T$ birer azaltılır. 1'e inilirse sayılar aralarında asaldır.
  - Asal çarpan yaklaşımı: $x=2^3\cdot 3^2$, $y=3^3\cdot 2^2$ için ortak çarpanlar $2^2\cdot 3^2=36$ (ekrandan, 01:05:00).
- Algoritma tasarım yöntemleri
  - Brute force: bütün olasılıkları tek tek denemek (1'den 100'e kadar toplamayı döngüyle yapmak gibi).
  - Divide and conquer: veriyi parçalara bölüp küçük parçaların çözümlerini birleştirmek (merge sort, quicksort).
  - Decrease and conquer: problemi $n$, $n-1$, $n-2$ diye küçülterek çözmek.
  - Transform and conquer: bilinen bir algoritmaya uyacak şekilde veriyi dönüştürmek. Örnek (ekrandan, 01:20:00): yalnız minimum bulan bir fonksiyonla maksimum bulmak için elemanlar negatife çevrilir; $3,6,8,2$ için $-3,-6,-8,-2$'nin minimumu $-8$, işareti çevrilince maksimum 8 bulunur.
  - Space-time tradeoff: zamandan ya da bellekten ödün vererek çözmek. Greedy: tam çözümü garanti etmeden iyi bir çözüm bulmak. Dinamik programlama: kesin optimum çözüm. Iterative improvement, backtracking, branch and bound diğer yöntemlerdir.
  - Sayısal problemlere örnek: Fourier dönüşümünün $n^2$ karmaşıklığı FFT ile $n\log n$'e indirilmiştir.
- Veri yapıları
  - Veriye hızlı erişmek için verinin bellekte uygun düzenlenmesi gerekir. 100 öğrencinin notu için 100 ayrı değişken yerine 100 elemanlı dizi, iki not için $100\times 2$ matris kullanılır.
  - Dizide elemanlar bitişiktir; büyük bir dizi için bellekte yeterli bitişik yer olmayabilir. Bağlantılı listede her düğüm veriyi ve sonraki düğümün adresini tutar; son düğüm null gösterir. Araya ekleme bağlantıları değiştirerek yapılır, ama rastgele erişim yoktur. Son düğümü gösteren yardımcı bir işaretçi tutularak sona ekleme hızlandırılabilir.
  - Kuyrukta ekleme sondan (enqueue), çıkarma baştan (dequeue) yapılır; işletim sistemindeki işlem kuyruğu bir örnektir. İçeriğe göre araya ekleme yapılan yapı öncelikli kuyruktur; heap bunun bir gerçeklemesidir.
  - Yığında ekleme (push) ve çıkarma (pop) yalnız üstten yapılır; üst üste konmuş tabaklar gibi. Fonksiyon çağrılarında dönüş bilgilerinin saklanması (stack pointer) ve matematiksel ifadelerin değerlendirilmesi uygulamalarıdır.
- Yığın ile ifade değerlendirme
  - Infix örneği (ekrandan, 01:55:00): $2*(5*(3+6))/15-2$. Kapama parantezi gelince açma parantezine kadar işlem yapılır: $6+3=9$, $9*5=45$. Eksi gelince daha yüksek öncelikli bölme ve çarpma işlenir: $45/15=3$, $3*2=6$. Sonda $6-2=4$.
  - Prefix örneği (ekrandan, 02:15:00): $-\;/\;*\;20\;*\;50\;+\;3\;6\;300\;2$, yani $20*(50*(3+6))/300-2$. Sağdan sola: $3+6=9$, $50*9=450$, $20*450=9000$, $9000/300=30$, $30-2=28$.
  - Postfix örneği (ekrandan, 02:20:00): `2536+**5/2-` için $3+6=9$, $5*9=45$, $2*45=90$, $90/5=18$, $18-2=16$.
  - Infix-postfix (ekrandan, 02:25:00): `A+B*(C^D-E)` → `ABCD^E-*+`.
  - Infix-prefix (ekrandan, 02:30:00): ters çevir `)E-D^C(*B+A`, parantezleri çevir `(E-D^C)*B+A`, postfix sonucu `EDC^-B*A+`, bunu ters çevir: `+A*B-^CDE`.
  - Postfix-infix (ekrandan, 02:35:00): `ABC/-AK/L-*` → $((A-(B/C))*((A/K)-L))$.
  - Prefix-postfix (ekrandan, 02:40:00): `*-A/BC-/AKL` sağdan sola okunur → `ABC/-AK/L-*`.
  - Postfix-prefix (ekrandan, 02:45:00): soldan sağa okunur, operatör gelince `op S2 S1` yazılır; `AB+` → `+AB`.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
