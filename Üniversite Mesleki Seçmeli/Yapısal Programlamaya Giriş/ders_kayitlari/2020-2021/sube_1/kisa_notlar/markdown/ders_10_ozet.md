# Ders 10 Çalışma Özeti

## Genel Konular

- Özyinelemeli (rekürsif) olmayan algoritmaların analizi
  - Dersin konusu: akış diyagramıyla verilen bir algoritmada, döngüler bittiğinde sayaç değişkeni $T$'nin değerinin $N$'e bağlı olarak ne olacağını bulmak.
  - Bu değer, döngü gövdesinden kaç kez geçildiğini, yani algoritmanın ne kadar çalıştığını (karmaşıklığını) gösterir.
  - Yöntem: her döngü bir toplam ($\sum$) sembolüne çevrilir; iç içe döngüler iç içe toplamlar olur. Sonra toplam kuralları ve bilinen formüllerle kapalı bir ifade bulunur.
  - Akış diyagramındaki for kutusu `i ← 1 || 1` ve altında `N` biçiminde çizilir: $i$ 1'den başlar, birer artar, $N$'e kadar (dahil) gider (ekrandan, 00:05:00).
- Tek döngü ve gövdedeki ifadenin etkisi (ekrandan, 00:10:00)
  - `T = 0`, for $i = 1..N$, gövde `T = T + 1`: $T = \sum_{i=1}^{N} 1 = N$.
  - Gövde `T = T + i`: $T = \sum_{i=1}^{N} i = \frac{N(N+1)}{2}$.
  - Gövde `T = T + 2`: $T = 2N$. Gövde `T = T + 2i`: $T = N(N+1)$.
  - `T = 1` ile başlayıp gövde `T = T + T`: $T$ her adımda iki katına çıkar (1, 2, 4, 8, 16, ...), sonuç $2^N$. Toplam yerine çarpım ($\prod$) gösterimiyle $T = \prod_{i=1}^{N} 2 = 2^N$.
- İç döngüsü $N \cdot N$'e kadar giden iki döngü (ekrandan, 00:15:00 ve 00:25:00)
  - Gövde `T = T + 1`: $\sum_{i=1}^{N}\sum_{j=1}^{N^2} 1 = \sum_{i=1}^{N} N^2 = N^3$. $N = 3$ için algoritma elle çalıştırılınca 27 çıkar.
  - Gövde `T = T + i`: iç döngüde $i$ değişmediği için toplamın dışına alınır: $\sum_{i=1}^{N} i \cdot N^2 = N^2 \cdot \frac{N(N+1)}{2} = \frac{N^3(N+1)}{2}$.
  - Gövde `T = T + j`: $j$ dışarı alınamaz. İç toplam 1'den $N^2$'ye kadar sayıların toplamıdır, $\frac{N^2(N^2+1)}{2}$. İçinde $i$ olmadığından $N$ ile çarpılır: $\frac{N^3(N^2+1)}{2}$.
- İç döngüsü $i \cdot i$'ye kadar giden iki döngü (ekrandan, 00:30:00 ve 00:35:00)
  - Gövde `T = T + 1`: iç toplam $i^2$, sonuç karelerin toplamı: $\sum_{i=1}^{N} i^2 = \frac{N(N+1)(2N+1)}{6}$.
  - Gövde `T = T + i`: $\sum_{i=1}^{N} i \cdot i^2 = \sum_{i=1}^{N} i^3 = \left(\frac{N(N+1)}{2}\right)^2$.
  - Gövde `T = T + j`: iç toplam $\frac{i^2(i^2+1)}{2}$; sonuç $\frac{1}{2}\left(\sum i^4 + \sum i^2\right)$. Burada $\sum_{i=1}^{N} i^4 = \frac{N^5}{5} + \frac{N^4}{2} + \frac{N^3}{3} - \frac{N}{30}$ formülü gerekir.
- Değişkeni iki katına çıkan while döngüsü (ekrandan, 00:45:00 ve 00:50:00)
  - `T = 0`, `i = 1`, $N$ okunur ($N = 2^k$ varsayılır); `i <= N` olduğu sürece `T = T + 1`, `i = i * 2`.
  - $N = 32$ için izleme: $i$ = 1, 2, 4, 8, 16, 32 iken içeri girilir, $T = 6$ olur. Sonuç $T = \log_2 N + 1$.
  - Gövde `T = T + i` olursa eklenen değerler $2^0, 2^1, \dots, 2^{\log_2 N}$'dir: $T = \sum_{i=0}^{\log_2 N} 2^i$.
- Geometrik toplam formülü (ekrandan, 01:10:00 ve 01:15:00)
  - $T = \sum_{i=0}^{N} A^i = A^0 + A^1 + \dots + A^N$ yazılır; $T - 1 = A(A^0 + \dots + A^{N-1}) = A(T - A^N)$ olur.
  - Düzenlenince $T(A-1) = A^{N+1} - 1$, yani $T = \frac{A^{N+1}-1}{A-1}$.
  - While örneğinde $A = 2$, üst sınır $\log_2 N$: $T = 2^{\log_2 N + 1} - 1 = 2 \cdot 2^{\log_2 N} - 1 = 2N - 1$.
- $\sum_{i=0}^{N} i A^i$ toplamı (ekrandan, 01:20:00 ve 01:35:00)
  - Her iki taraf $A$ ile çarpılır ve $T - AT$ hesaplanır; aynı üslü terimler sadeleşince $T - AT = A + A^2 + \dots + A^N - N A^{N+1}$ kalır.
  - $A + \dots + A^N = \frac{A^{N+1}-1}{A-1} - 1$ olduğundan $T = \dfrac{\frac{A^{N+1}-1}{A-1} - 1 - N A^{N+1}}{1-A}$.
  - Amaç, $i$ katsayılarından kurtulup bilinen geometrik toplama ulaşmaktır.
- Koşul içeren iç içe döngü: `j mod i == 0` (ekrandan, 01:40:00 ve 01:50:00)
  - For $i = 1..N$, for $j = 1..i \cdot i$; `j mod i == 0` ise `T = T + 1`.
  - $N = 4$ izleme: $i = 1$'de $T = 1$; $i = 2$'de $j$ = 2, 4 ile $T = 3$; $i = 3$'te $j$ = 3, 6, 9 ile $T = 6$; $i = 4$'te $j$ = 4, 8, 12, 16 ile $T = 10$.
  - Her $i$ için koşul $i$ kez doğrudur: $T = \sum_{i=1}^{N} i = \frac{N(N+1)}{2}$.
  - False dalından geçiş sayısı: toplam geçiş eksi true geçişleri, $\sum_{i=1}^{N}(i^2 - i) = \frac{N(N+1)(2N+1)}{6} - \frac{N(N+1)}{2}$.
- Önce $K$'yı hesaplayan algoritmalar (ekrandan, 01:55:00, 02:10:00, 02:15:00 ve 02:20:00)
  - İlk döngü $N$ kez `K = K * 2` yapar, sonunda $K = 2^N$.
  - Sonraki iç içe döngü for $i = 1..N$, for $j = 1..K$: gövde `T = T + 1` ise $N \cdot 2^N$; gövde `T = T + i` ise $2^N \cdot \frac{N(N+1)}{2}$; gövde `T = T + j` ise $N \cdot \frac{2^N(2^N+1)}{2}$.
  - İç döngü while ise (`J = 1`; `J < K` olduğu sürece `T = T + 1`, `J = J * 2`): iç kısım $\log_2 K = \log_2 2^N = N$ kez döner, sonuç $\sum_{i=1}^{N} N = N^2$.
- Üç iç içe döngü ve başlangıcı değişen döngüler (ekrandan, 02:30:00 ve 02:35:00)
  - For $i = 1..N$, for $j = 1..i$, for $k = 1..j$, gövde `T = T + 1`: $\sum_{i=1}^{N}\sum_{j=1}^{i} j = \sum_{i=1}^{N}\frac{i(i+1)}{2} = \frac{N(N+1)(N+2)}{6}$.
  - İç döngü $j = 3..N$ ise iç toplam $N - 2$, sonuç $N(N-2)$.
  - İç döngü $j = i..N$ ise iç toplam $N - i + 1$; sonuç $N^2 - \frac{N(N+1)}{2} + N = \frac{N(N+1)}{2}$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tahmin değil, çalıştırma
  - İç döngüsü $N \cdot N$'e giden örnekte öğrenciler $N^2$, $N^3$, karelerin toplamı gibi farklı tahminler yaptı. Hoca tahmin yerine $N = 3$ alıp algoritmayı elle çalıştırmayı istedi; doğru sonuç 27, yani $N^3$ çıktı.
- İç döngüde değişmeyen değişken toplamın dışına alınır
  - Gövdedeki değer dış döngü değişkenine ($i$) bağlıysa iç toplam boyunca sabittir ve dışarı çıkarılabilir. İç döngü değişkenine ($j$) bağlıysa çıkarılamaz.
- Döngü değişkeni birer birer artmıyorsa toplam sınırı değişir
  - While örneğinde $i$ iki katına çıktığı için `T = T + i` doğrudan $\sum i$ yazılamaz. Bir öğrencinin yakaladığı gibi eklenen değerler $2^i$'dir ve indis 0'dan başlar.
- Bilinen bir formüle indirgemek
  - $\sum i A^i$ örneğinde $A$ ile çarpıp çıkarmanın amacı, katsayılardan kurtulup bilinen geometrik toplama ulaşmaktır.
- Adım adım çözmek
  - Hoca öğrencilerin doğrudan sonuca atlamasını istemedi; önce en içteki toplamın değeri, sonra dıştaki toplam bulunmalıdır.
- Kendi sorunu üretmek
  - Bu tür sorularda gövdedeki ifadeyi ya da döngü sınırlarını ($i$, $j$, $k$, $i \cdot i$ vb.) değiştirerek yeni alıştırmalar üretmek çok kolaydır.

## Kısa Tekrar Notları

- Döngü → toplam: for $i = a..b$ gövdesi $f$ ise katkı $\sum_{i=a}^{b} f$.
- $\sum_{i=1}^{N} 1 = N$, $\sum i = \frac{N(N+1)}{2}$, $\sum i^2 = \frac{N(N+1)(2N+1)}{6}$, $\sum i^3 = \left(\frac{N(N+1)}{2}\right)^2$.
- $\sum_{i=0}^{N} A^i = \frac{A^{N+1}-1}{A-1}$; $2^{\log_2 N} = N$.
- $j = a..N$ döngüsü $N - a + 1$ kez döner ($j = 3..N$ için $N-2$, $j = i..N$ için $N-i+1$).
- İki katına çıkan değişkenle $N$'e kadar giden döngü yaklaşık $\log_2 N$ kez döner (`<=` ile $N = 2^k$ için $\log_2 N + 1$).
- Koşullu döngüde true ve false geçişlerinin toplamı, koşul kutusuna toplam geçiş sayısına eşittir.
- Bu analiz özyinelemesiz algoritmalar içindir; özyinelemeli fonksiyonların analizi fonksiyonlar ve özyineleme işlendikten sonra yapılacaktır.

## Detaylı Açıklamalar

- Ders, basit bir döngüyle başlayıp her adımda algoritmada küçük bir değişiklik yapılarak ilerledi. İlk algoritmada $N$ okunur, `T = 0` yapılır ve $i = 1..N$ döngüsünde `T = T + 1` çalışır. Gövdeden $N$ kez geçildiği için $T = N$ olur. Bu durum lise matematiğindeki toplam gösterimiyle $\sum_{i=1}^{N} 1 = N$ diye yazıldı. Gövde `T = T + i` yapılınca $1 + 2 + \dots + N = \frac{N(N+1)}{2}$, `T = T + 2` yapılınca $2N$, `T = T + 2i` yapılınca bunun iki katı olan $N(N+1)$ bulundu (ekrandan, 00:10:00). Son değişiklikte $T$ 1'den başlatıldı ve gövde `T = T + T` yapıldı. Bu durumda $T$ her turda iki katına çıkar ($i = 1$'de 2, $i = 2$'de 4, $i = 3$'te 8, ...), sonuç $2^N$ olur. Bu toplamla değil, çarpım sembolüyle $\prod_{i=1}^{N} 2 = 2^N$ biçiminde gösterildi.
- İkinci algoritma grubunda iki iç içe for vardır: dış döngü $i = 1..N$, iç döngü $j = 1..N \cdot N$ (ekrandan, 00:15:00). Gövde `T = T + 1` olduğunda öğrencilerden $N^2$, $N^3$ ve karelerin toplamı tahminleri geldi. $N = 3$ ile elle çalıştırılınca 27 bulundu. Formülle: iç toplam $\sum_{j=1}^{N^2} 1 = N^2$, dış toplam $N$ tane $N^2$'nin toplamı, yani $N^3$ (ekrandan, 00:25:00). Gövde `T = T + i` olduğunda iç döngü dönerken $i$ değişmez; bu yüzden $\sum_{j=1}^{N^2} i = i \cdot N^2$ yazılır. $N^2$ de dış toplamın dışına alınır ve $N^2 \cdot \frac{N(N+1)}{2} = \frac{N^3(N+1)}{2}$ bulunur. Gövde `T = T + j` olduğunda ise $j$ dışarı alınamaz; iç toplam 1'den $N^2$'ye kadar olan sayıların toplamıdır, $\frac{N^2(N^2+1)}{2}$. Bu ifade $i$'ye bağlı olmadığından $N$ kez toplanması $N$ ile çarpmak demektir: $\frac{N^3(N^2+1)}{2}$.
- Üçüncü grupta iç döngü $i \cdot i$'ye kadar gider (ekrandan, 00:30:00). Gövde `T = T + 1` iken iç toplam $i^2$ olur ve sonuç $1 + 4 + 9 + 16 + \dots$, yani karelerin toplamı $\frac{N(N+1)(2N+1)}{6}$ çıkar. Gövde `T = T + i` iken $i$ dışarı alınır: $\sum i \cdot i^2 = \sum i^3 = \left(\frac{N(N+1)}{2}\right)^2$. Hoca bu formülün karelerin toplamı formülünden "daha güzel" olduğunu söyledi. Gövde `T = T + j` iken (ekrandan, 00:35:00) iç toplam 1'den $i^2$'ye kadar sayıların toplamı, $\frac{i^2(i^2+1)}{2}$ olur. $\frac{1}{2}$ dışarı alınır ve toplam $\sum i^4$ ile $\sum i^2$ olarak ikiye ayrılır. Hoca $\sum i^4$ için tahtaya $\frac{N^5}{5} + \frac{N^4}{2} + \dots$ ile başlayan ve son terimi paydası 30 olan formülü yazdı; bu formülün tam hali $\frac{N^5}{5} + \frac{N^4}{2} + \frac{N^3}{3} - \frac{N}{30}$ biçimindedir (python ile doğrulandı). Bir öğrenci $\sum i^4$'ün $\sum i^2 \cdot \sum i^2$ diye ayrılıp ayrılamayacağını sordu; hoca bunun mümkün olmadığını söyledi.
- Dördüncü algoritma bir while döngüsüdür (ekrandan, 00:45:00): `T = 0`, `i = 1`, $N$ okunur (kolaylık için $N = 2^k$, örneğin 256, 512, 1024), `i <= N` olduğu sürece `T = T + 1` ve `i = i * 2`. $N = 32$ için tablo: $i$ = 1, 2, 4, 8, 16, 32 değerlerinde gövdeye girilir, $T$ sırasıyla 1, 2, 3, 4, 5, 6 olur, $i = 64$'te döngüden çıkılır. $\log_2 32 = 5$ olduğundan sonuç $\log_2 N + 1$'dir. Sonra gövde `T = T + i` yapıldı. İlk akla gelen $\sum i$ yazmak yanlıştır, çünkü $i$ birer birer değil iki katına çıkarak ilerler. Eklenen değerler $2^0, 2^1, 2^2, \dots$ olduğundan $T = \sum_{i=0}^{\log_2 N} 2^i$ yazılır (ekrandan, 00:50:00). Burada toplamın $i$'si ile algoritmadaki $i$ farklıdır: algoritmada $i$ 1'den başlar, toplamdaki üs 0'dan başlar.
- Bu toplamı hesaplamak için genel geometrik toplam formülü türetildi (ekrandan, 01:10:00 ve 01:15:00). $T = A^0 + A^1 + \dots + A^N$ ise $T - 1 = A^1 + \dots + A^N = A(A^0 + \dots + A^{N-1})$ olur. Parantezin içi $T$'nin son terimi eksik halidir, yani $T - A^N$. Böylece $T - 1 = A(T - A^N) = AT - A^{N+1}$, $AT - T = A^{N+1} - 1$ ve $T = \frac{A^{N+1}-1}{A-1}$ bulunur. While örneğinde $A = 2$ ve üst sınır $\log_2 N$ konunca $T = 2^{\log_2 N + 1} - 1 = 2 \cdot 2^{\log_2 N} - 1 = 2N - 1$ çıkar; burada $2^{\log_2 N} = N$ özdeşliği kullanılır.
- Ardından $T = \sum_{i=0}^{N} i A^i$ problemi için on dakika süre verildi (ekrandan, 01:20:00). Bir öğrenci $\frac{2NA}{1-A}$ buldu, ancak bu ifade doğru değildir (örneğin $A = 2$, $N = 2$ için gerçek toplam 10, bu ifade $-8$ verir). Hocanın yöntemi: toplam açık yazılır, $T = 0A^0 + 1A^1 + 2A^2 + 3A^3 + \dots + (N-1)A^{N-1} + NA^N$; her iki taraf $A$ ile çarpılır, $AT = 1A^2 + 2A^3 + \dots + (N-1)A^N + NA^{N+1}$. Aynı üslü terimler alt alta çıkarılınca her birinden bir tane kalır: $T - AT = A + A^2 + \dots + A^N - NA^{N+1}$ (ekrandan, 01:35:00). Baştaki geometrik toplam, bilinen formülün 1 eksiğidir. Böylece $T(1-A) = \frac{A^{N+1}-1}{A-1} - 1 - NA^{N+1}$ ve her iki taraf $1-A$'ya bölünerek $T$ bulunur. Hoca sonucun daha da sadeleştirilebileceğini, bunu öğrencilere bıraktığını söyledi.
- Koşullu algoritmada (ekrandan, 01:40:00) for $i = 1..N$ ve for $j = 1..i \cdot i$ içinde `j mod i == 0` sorulur; doğruysa `T = T + 1`. $N = 4$ ile tablo kuruldu (ekrandan, 01:50:00): $j$ değerlerinden $i$'nin katları olanlar sayılır; $i = 2$ için 2 ve 4, $i = 3$ için 3, 6, 9, $i = 4$ için 4, 8, 12, 16. $T$ sırasıyla 1, 3, 6, 10 olur; bu ardışık sayıların toplamıdır, $T = \frac{N(N+1)}{2}$. Sonra false dalından kaç kez geçildiği soruldu. Koşul kutusuna toplam $\sum i^2$ kez gelinir; bundan true geçişleri çıkarılınca false geçişleri $\sum (i^2 - i) = \frac{N(N+1)(2N+1)}{6} - \frac{N(N+1)}{2}$ bulunur. Bu cevabı bir öğrenci verdi ve hoca doğruladı.
- $K$ değişkenli algoritmalarda (ekrandan, 01:55:00) önce `K = 1` ile başlayan bir for $N$ kez `K = K * 2` yapar ve $K = 2^N$ olur. Ardından for $i = 1..N$ ve for $j = 1..K$ ile `T = T + 1` çalışır: $\sum_{i=1}^{N}\sum_{j=1}^{2^N} 1 = N \cdot 2^N$. Gövde `T = T + i` olunca $i$ ve $2^N$ dışarı alınır: $2^N \cdot \frac{N(N+1)}{2}$. Gövde `T = T + j` olunca iç toplam 1'den $2^N$'ye kadar sayıların toplamı $\frac{2^N(2^N+1)}{2}$'dir ve $N$ ile çarpılır (ekrandan, 02:10:00).
- Son $K$ örneğinde iç döngü while'dır (ekrandan, 02:15:00): `J = 1`; `J < K` olduğu sürece `T = T + 1`, `J = J * 2`. Öğrencilerden $N$ ve $N^2$ cevapları geldi; hoca "seyirciye sorma jokeri" benzetmesiyle çoğunluğun her zaman doğru olmadığını hatırlattı. $J$ iki katına çıktığından iç döngü $\log_2 K$ kez döner; $K = 2^N$ için bu $N$'dir. Dış döngü $N$ kez döndüğünden sonuç $\sum_{i=1}^{N}\sum_{j=1}^{N} 1 = N^2$ olur (ekrandan, 02:20:00).
- Üç iç içe döngüde (for $i = 1..N$, for $j = 1..i$, for $k = 1..j$) en içteki toplam $j$, ortadaki $\frac{i(i+1)}{2}$ olur. Bunun $i$ üzerinden toplamı $\frac{N(N+1)(N+2)}{6}$'dır. Son örneklerde iç döngünün başlangıcı değiştirildi (ekrandan, 02:30:00 ve 02:35:00). $j = 3..N$ döngüsünde 1 ve 2 değerleri olmadığı için $N - 2$ tur vardır ve sonuç $N(N-2)$'dir. $j = 4..N$ için $N-3$, $j = 5..N$ için $N-4$ olduğundan genel olarak $j = i..N$ için $N - i + 1$ tur vardır. Toplam üç parçaya ayrılır: $\sum N - \sum i + \sum 1 = N^2 - \frac{N(N+1)}{2} + N = \frac{N(N+1)}{2}$.
- Dersin sonunda hoca yapılanları özetledi: döngülerin dönme sayısı ve döngü içindeki değişkenlerin değişiminin karmaşıklığa etkisi incelendi, döngülerin toplam gösterimiyle rahatça ifade edilebildiği görüldü. Bu, algoritma analizine bir giriştir. Sonuç bazen $N$'e, bazen $N^2$'ye, $\log N$'e ya da $A$ gibi başka bir parametreye bağlıdır. Özyinelemeli yapıların analizi farklıdır ve fonksiyonlar ile özyinelemeli fonksiyonlar işlendikten sonra ele alınacaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
