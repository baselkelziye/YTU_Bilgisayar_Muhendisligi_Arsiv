# Ders 24 Çalışma Özeti

## Genel Konular

- Substring (alt dizgi) arama problemi
  - $N$ uzunluklu bir metin (text) içinde $M$ uzunluklu bir desenin (pattern) geçtiği yeri bulmak. Genellikle $N \gg M$ olur; metin sonsuz uzunlukta akan bir veri de olabilir (ekrandan, 00:10:00).
  - Ekrandaki örnek: desen `NEEDLE`, metin `...INAHAYSTACKNEEDLEINAHAYSTACK...` ("samanlıkta iğne").
  - Kullanım alanları: web araması, veritabanı sorguları, intihal tespiti, adli bilişimde disk/bellek imajında imza (anahtar, URL) arama, spam e-postalardaki örüntüleri yakalama, ağ trafiğinde belirli bir örüntüyü izleme, web sayfasından bilgi çıkarımı (örneğin bir HTML sayfasında "Last Trade" ifadesinden sonra gelen değeri okumak).
- Brute force (kaba kuvvet) arama
  - Deseni metnin başına hizala, karakterleri soldan sağa karşılaştır; hepsi eşleşirse bulundu, eşleşmezse deseni bir karakter kaydır; sona gelindiyse bulunamadı (ekrandan, 00:20:00).
  - Java'daki `String.indexOf()` bu şekilde çalışır.
  - En kötü durum: veri ve örüntü tekrarlıysa $O(MN)$ karşılaştırma (örnek: `AAAAAAAAAB` içinde `AAAAB`) (ekrandan, 00:25:00).
  - Backup'lı sürüm: eşleşmeme durumunda `i ← i − j`, `j ← 0` ile metinde geri gidilir; bu yüzden akan veride son $M$ karakterin bir ön bellekte (backup) tutulması gerekir (ekrandan, 00:30:00).
- Boyer-Moore-Horspool (Horspool) algoritması
  - "Eşleşmeyen karakter sezgisi" (bad character heuristic) olarak da bilinir. Desen sağdan sola taranır; eşleşmeme olunca deseni birden fazla karakter kaydırmak amaçlanır (ekrandan, 00:35:00).
  - Kaydırma miktarı önceden hesaplanan "kötü eşleşme tablosu"ndan (bad match table, shift table) okunur.
  - Genellikle lineer zaman, en kötü durumda kuadratik.
- Bad match table oluşturma
  - Alfabedeki her karakterin değeri başta $m$ yapılır; sonra $j = 0 \ldots m-2$ için $\text{Table}[P[j]] = m - 1 - j$ yazılır. Aynı karakter tekrar ederse sağdaki geçişin değeri öncekinin üzerine yazılır.
  - Son karakter ($j = m-1$) döngüye girmez; desende başka yerde geçmiyorsa değeri $m$ kalır.
- Boyer-Moore algoritması
  - Horspool'un öncüsüdür; bad match tablosuna ek olarak "iyi son ek" (good suffix) sezgisini kullanır.
  - İki kaydırma önerisinden büyük olanı seçilir: $d = \max(d_1, d_2)$.
- Rabin-Karp algoritması
  - Metni doğrudan aramak yerine desenin "imzasını" (hash değerini) arar.
  - Hash eşleşince karakterler birebir karşılaştırılır (çakışma olabilir).
  - Kayan (rolling) hash ile her pozisyonun hash'i bir öncekinden birkaç küçük işlemle hesaplanır.
- Algoritmaların maliyet karşılaştırması (ekrandan, 02:05:00)

## Hocanın Özellikle Vurguladığı Kısımlar

- Brute force'ta neden hep bir kaydırılır?
  - Eşleşmeme sonrasında daha fazla kaydırmak, arada başlayan bir geçişin kaçırılmasına yol açabilir. Kaba kuvvet yöntemi bu yüzden birer birer ilerlemek zorundadır.
- Akan veride backup sorunu
  - Brute force geri dönüş yaptığı için son $M$ karakteri saklamak gerekir. Pratikte buna yer, zaman ya da izin olmayabilir.
  - Horspool da sağdan sola karşılaştırdığı için küçük de olsa $M$ karakterlik bir backup alanına ihtiyaç duyar.
- Horspool ile Boyer-Moore farkı
  - İnternetteki kaynaklarda bu iki algoritma sık sık karıştırılır; "Horspool" diye Boyer-Moore kodu verilebilir ya da tersi.
  - Yalnız bad match tablosu kurup ona göre kaydıran kod Horspool'dur. Bad match tablosuna ek olarak good suffix tablosu kurup ikisinin büyüğü kadar kaydıran kod Boyer-Moore'dur.
- Horspool'un zayıf noktası
  - Tablo tek bir kuralla kurulduğu için bazı durumlarda kaydırma olması gerekenden az olur (örnek: `REORDER`). Yine de brute force'tan çok daha iyidir.
- Rabin-Karp'ta asal sayı seçimi
  - Mod alınan asal sayı küçük seçilirse (örneğin 7) çakışmalar artar; her çakışmada ek $M$ karakterlik kontrol gerekir. Asal sayı yeterince büyük seçilmelidir.
- Algoritma seçimi bir ödünleşimdir
  - Kimi algoritma ekstra alan ister, kimi backup ister, kimi daha hızlıdır. Problem ve çalışma ortamına göre uygun olan seçilmelidir.

## Kısa Tekrar Notları

- Brute force: en kötü durum $O(MN)$; Java `indexOf()` böyle çalışır.
- Horspool: desen sağdan sola karşılaştırılır; eşleşmezse kaydırma $\text{Table}[T[i]]$ kadar olur. Burada $T[i]$, metinde desenin son karakterinin hizasındaki karakterdir.
- Bad match table: varsayılan değer $m$; $j=0..m-2$ için $m-1-j$; en sağdaki geçiş kazanır.
- `BARBER` için: A=4, B=2, E=1, R=3, diğerleri 6 (ekrandan, 01:00:00).
- `TOOTH` için: T=1, O=2, H=5, diğerleri 5 (ekrandan, 01:15:00).
- Horspool karmaşıklığı: en kötü $O(nm)$ (örnek: metin hep `A`, desen `BAAAAA`), en iyi $O(n/m)$, ortalama $O(n)$ (ekrandan, 01:20:00).
- Boyer-Moore: $k$ = sondan eşleşen karakter sayısı; $d_1 = \max(t_1(c) - k,\ 1)$; $k=0$ ise yalnız $d_1$, $k>0$ ise $\max(d_1, d_2)$ kadar kaydır.
- Good suffix: `ABCBAB` için $d_2$: k=1 → 2, k=2..5 → 4; `BAOBAB` için $d_2$: k=1 → 2, k=2..5 → 5 (ekrandan, 01:30:00 ve 01:35:00).
- Rabin-Karp: ön işleme $O(m)$, en kötü $O(mn)$, genellikle $O(m+n)$ (ekrandan, 01:50:00).
- Kayan hash: $h_{yeni} = (h_{eski} - \text{ilk rakam} \cdot (10^{4} \bmod 97)) \cdot 10 + \text{yeni rakam} \pmod{97}$.

## Detaylı Açıklamalar

- **Brute force arama.** Desen metnin $i$. pozisyonuna hizalanır, `j` ile desen içinde ilerlenir ve `P[j] == T[i+j]` olduğu sürece `j` artırılır. `j == m` olursa desen `i` pozisyonunda bulunmuştur. Dış döngü `0..n−m` arasında döner. Birden fazla geçiş aranıyorsa ilk bulmada durulmaz, sona kadar devam edilir.
  - Derste anlatılan örnek: `ACAABC` metninde `AAB` aranır. İlk pozisyonda A eşleşir, C/A eşleşmez; bir kaydırılır. C/A eşleşmez; bir kaydırılır. Sonra A, A, B eşleşir ve desen 2. indiste bulunur.
  - Ekrandaki en kötü durum örneği (00:25:00): metin `AAAAAAAAAB` (indis 0-9), desen `AAAAB`. `i = 0..4` için her denemede dört A eşleşir, B eşleşmez; ancak `i = 5`'te desen bulunur. Her kaydırmada $M$ karşılaştırma, toplamda $M \cdot N$ mertebesinde iş yapılır.
- **Backup'lı brute force (ekrandan, 00:30:00).** Akış diyagramındaki adımlar:

```text
START
oku: N, T[N], M, P[M]
i <- 0, j <- 0
döngü (i < N ve j < M), her turda i bir artar:
    T[i] = P[j] ise  j <- j + 1
    değilse          i <- i - j ; j <- 0     (geri dönüş = backup)
j = M ise  yaz: i - M      (desenin başladığı indis)
değilse    yaz: 'yok'
STOP
```

- **Horspool algoritması.**
  - Durum 1: Karşılaştırılan metin karakteri (c) desende yoksa desen boyu kadar kaydırılır. Örneğin `BARBER`'in son harfinin karşısına `S` gelirse 6 kaydırılır (ekrandan, 00:40:00).
  - Durum 2: c desende var ama son karakter değilse, desendeki en sağdaki geçişi c'nin hizasına gelecek kadar kaydırılır. `BARBER`'de `B` gelirse 2 kaydırılır. Soldaki B'ye göre kaydırmak bir eşleşmeyi kaçırabilir.
  - Durum 3: c desenin son karakteri ve kalan $m-1$ karakterde tekrarı yoksa desen boyu kadar kaydırılır. Derste `LEADER` örneği kullanıldı: R ve E eşleşir, D'nin karşısına `M` gelir; kaydırma son karakterin karşısındaki `R` üzerinden yapılır. `R`'nin `LEADER`'in ilk 5 harfinde tekrarı olmadığı için 6 kaydırılır.
  - Durum 4: c desenin son karakteri ve başka tekrarı da varsa, kalan $m-1$ karakter içinde c'nin en sağda geçtiği yere kadar kaydırılır (ekrandan, 00:45:00). `REORDER` örneğinde metinde `...A R...` vardır: R eşleşir, E/A eşleşmez. Desen, içindeki 3. indisteki R metindeki R'ye gelecek şekilde kaydırılır.
  - Eşleştirme sözde kodu (ekrandan, 00:50:00):

```text
ALGORITHM HorspoolMatching(P[0..m-1], T[0..n-1])
// Implements Horspool's algorithm for string matching
// Input: Pattern P[0..m-1] and text T[0..n-1]
// Output: The index of the left end of the first matching substring
//         or -1 if there are no matches
ShiftTable(P[0..m-1])   //generate Table of shifts
i <- m - 1              //position of the pattern's right end
while i <= n - 1 do
    k <- 0              //number of matched characters
    while k <= m - 1 and P[m - 1 - k] = T[i - k] do
        k <- k + 1
    if k = m
        return i - m + 1
    else i <- i + Table[T[i]]
return -1
```

  - Tablo oluşturma, altyazıdaki anlatıma göre şöyledir: önce `i = 0..size−1` için `Table[i] = m`, sonra `j = 0..m−2` için `Table[P[j]] = m − 1 − j`. <!-- BELİRSİZ: ShiftTable sözde kodunun slaytı karelerde görünmüyor; anlatım altyazıdan alındı. -->
- **Boyer-Moore.** Son karakter eşleşmezse ($k=0$) Horspool gibi davranır. $k>0$ karakter eşleştikten sonra $c$ eşleşmezse iki öneri hesaplanır (ekrandan, 01:25:00):
  - $d_1$ (bad symbol shift): $c$ tabloda yoksa desen $c$'nin bir sağına kaydırılır; varsa $t_1(c) - k$ kadar kaydırılır. Bu değer sıfır ya da negatif olabileceği için $d_1 = \max(t_1(c) - k, 1)$ alınır.
  - Ekrandaki örnekler (01:45:00): `SER` karşısında `BARBER` için R ve E eşleşir, S desende yok; desen 4 kaydırılır (Horspool R'ye göre 3 kaydırırdı). `AER` karşısında A desende var; $t_1(A) - 2 = 4 - 2 = 2$ kaydırılır.
  - $d_2$ (good suffix shift): sondan eşleşen $k$ uzunluklu son ekin desende önünde farklı bir karakterle başka bir geçişi varsa, desen bu geçiş son ekin hizasına gelecek kadar kaydırılır. Tekrarı olmayan son ekler için kaydırma, o ana kadarki en uzun tekrar eden son ekin değeriyle sınırlanır; desen boyu kadar kaydırmak eşleşme kaçırabilir.
- **Rabin-Karp.** Desenin hash'i bir kez hesaplanır. Metindeki her $m$ uzunluklu pencerenin hash'i bir öncekinden kayan hash ile bulunur. Hash'ler eşitse karakterler birebir karşılaştırılarak doğrulanır. Ekrandaki örnek (01:55:00 ve 02:00:00): $\pi$ basamaklarında `59265` aranır, $59265 \bmod 97 = 95$; pencere hash'leri sırasıyla 84, 94, 76, 18, 95'tir. Son pencerede hash tutar ve beş rakam tek tek kontrol edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
