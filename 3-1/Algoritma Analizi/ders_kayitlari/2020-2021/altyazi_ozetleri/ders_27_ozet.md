# Ders 27 Çalışma Özeti

## Genel Konular

- Dersin tarihi 6 Ocak 2021 Çarşamba. Ders Zoom üzerinden yapıldı. Dönemin son kaydı.
  - Bu derste yeni konu anlatılmadı.
  - Ders vize sorularının çözümü, not dağılımı, dönem projesi ve final bilgilendirmesiyle geçti.
  - Kaydın 01:14'ten sonraki kısmı 4. ödevin kontrol oturumu için bekleme ve kapanıştır.
- Vize sonuçları ve düzeltmeler
  - Bir test sorusunun cevap anahtarı yanlış girilmişti. Düzeltildi, çoğu öğrencinin notu yaklaşık 4 puan arttı.
  - Test bölümünde 2 yanlış 1 doğruyu götürüyordu. Ortalama düşük olduğu için 3 yanlış 1 doğruyu götürecek şekilde yeniden hesaplandı.
- Vize test soruları: döngü sayımı, linear probing'de silme, asimptotik gösterimler, hash tablosuna yerleştirme sırası, algoritma karşılaştırma ölçütleri, ikili arama ağacına ekleme, sıralama algoritmalarının ara adımlarını tanıma.
- Vize klasik soruları: büyüme hızı karşılaştırması, rekürans çözümü, hash ile kesişim kümesi, en kısa süreyi bulma (böl ve fethet).
- Not dağılımı kesinleşti.
- Dönem projesi: kitap öneri sistemi (collaborative filtering).
- Final sınavı hakkında ilk bilgiler.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Sadece en küçüğü veya en büyüğü bulmak için dizi sıralanmaz.**
  - Vizedeki 4. soruda sınıfın yaklaşık %90'ı quicksort veya merge sort kullandı. Bu çözümler istenen çözüm değil.
  - Sıralayıp yalnızca birinciyi doğru yazdıranlar 20 üzerinden 8 aldı. Bütün listeyi yazdıranlar soruya cevap vermemiş sayıldı.
- **Hazır gördüğünüz bir böl ve fethet algoritmasını her probleme uygulamayın.** Problemin gerçekte ne istediğine bakın.
- **Sınavda kodun algoritmik kısmı, söz dizimi hatalarından daha önemlidir.** Küçük söz dizimi hataları en son bakılan yerdir ve az puan kırılır. Bu final için de geçerli.
- **Kopya:** Vizede 5-6 öğrencinin kodu çok benzer çıktı, o sorulardan sıfır aldılar. Finalde aynı durumda bütün sınava sıfır verilecek.
- Hash sorusunda hash fonksiyonu kullanılmalıydı. Hazır hash fonksiyonu kullanmak ve linear probing yerine bağlı liste (separate chaining) kullanmak puan kaybettirdi.
- Ödevler not ortalamasını kurtaran bir unsur. Not dağılımında ödev ve projeye toplam %35 ayrıldı.

## Kısa Tekrar Notları

- **Not dağılımı:** Vize %25, ödevler %25, dönem projesi %10, final %40.
- **Master teoremi:** $T(n) = a\,T(n/b) + f(n)$, $f(n) \in \Theta(n^d)$ ise:
  - $a < b^d$ ise $T(n) \in \Theta(n^d)$
  - $a = b^d$ ise $T(n) \in \Theta(n^d \log n)$
  - $a > b^d$ ise $T(n) \in \Theta(n^{\log_b a})$
- **$T(n) = 4T(n/2) + n^2$:** $a = 4$, $b = 2$, $d = 2$, $a = b^d$. Sonuç $\Theta(n^2 \log n)$.
- **$x_n = x_{n-1} + 5$, $x_1 = 0$:** Geriye doğru yerine koyma ile $x_n = 5(n-1) = 5n - 5$.
- **Böl ve fethetle en küçüğü bulma:** $C(n) = 2C(n/2) + 1$, $C(1) = 0$. Sonuç $C(n) = n - 1$ karşılaştırma.
  - Kaba kuvvet de $n - 1$ karşılaştırma yapar. Karmaşıklık aynıdır. Böl ve fethet, fonksiyon çağrısı yükü yüzünden dezavantajlıdır.
- **Linear probing'de silme:** $i$. göz "silindi" (deleted) ve $i+1$. göz "boş" (empty) ise $i$. göz boş yapılabilir. $i+1$. gözde bir eleman varsa yapılamaz, çünkü aramayı yarıda keser.

## Detaylı Açıklamalar

### Vize test soruları

- **Döngü sayımı:** Sayaç her adımda iki katına çıkan bir döngüde toplama işlemi $\log n$ kez yapılır. 8'e kadar 3 kez, 16'ya kadar 4 kez.
- **Linear probing'de silinen gözler:**
  - "$i$. adres deleted, $i+1$. adres empty ise $i$. adres empty olarak işaretlenebilir." **Doğru.** Arama zaten $i+1$'de duracaktır.
  - "$i$. adres deleted, $i+1$. adreste doğru yere yerleşmiş bir eleman varsa $i$. adres empty olarak işaretlenebilir." **Yanlış.** Arada silinmiş bir eleman var demektir. $i$ boş yapılırsa, $i$'den sonraya yerleşmiş elemanların araması yarıda kesilir.
- **$2n^3 - 7n + 1$ için hangi gösterim kullanılamaz?** $O(n^3)$, $\Theta(n^3)$, $O(n^4)$ ve $\Omega(n)$'nin hepsi geçerlidir. Cevap: "hepsi kullanılabilir".
- **Hash tablosuna yerleştirme sırası** ($h(x) = x \bmod 10$ ile uyumlu, linear probing): Doğru sıra 46, 34, 42, 23, 52, 33.
  - 46→6, 34→4, 42→2, 23→3.
  - 52→2 dolu, 3 dolu, 4 dolu, 5'e yerleşir.
  - 33→3 dolu, 4, 5, 6 dolu, 7'ye yerleşir.
- **İki algoritmayı verimlilik yönünden karşılaştırma ölçütleri:** yer karmaşıklığı, zaman karmaşıklığı, çalışma süresi, büyüme derecesi. Cevap 4. Girdi sayısı ve kod uzunluğu ölçüt değildir.
- **$n$ elemanlı ikili arama ağacına ekleme, en kötü durum:** $O(n)$. Ağaç bir tarafa yığılabilir. Bu sorunun cevap anahtarı sistemde yanlış girilmişti, puanlar düzeltildi.
- **Sıralama algoritmalarını ara adımlardan tanıma:** Birinci sütun sırasız dizi, son sütun sıralı dizi. Doğru sıra: seçmeli (selection), quick, merge, ekleme (insertion), heap.
  - **Merge sort:** Dizinin iki yarısı ayrı ayrı sıralı görünür.
  - **Insertion sort:** Baştaki kısım her adımda sıralı kalır. Geride kalan elemanlar başlangıçtaki sırasını korur.
  - **Selection sort:** Baştaki kısım en küçük elemanlardan oluşur. Ama kalan elemanların sırası değişmiştir, çünkü yer değiştirmeler (swap) olmuştur.

### Vize klasik soruları

#### 1. Büyüme hızlarının karşılaştırılması (6 puan)

- Her satıra yalnızca $O$, $\Theta$ veya $\Omega$ yazılacaktı. Farklı biçimde cevap verenler puan alamadı.
  - $n^2$ ile $n^3$: $O$.
  - İkinci satır: $\Omega$. Altyazıdan fonksiyonlar tam okunmuyor; hoca karşılaştırılan fonksiyonun $n \log n$'e göre durumu yüzünden $\Omega$ dedi.
  - $2 + \sin n$ ile $1$ (altyazıdan anlaşıldığı kadarıyla): $\Theta$. $2 + \sin n$ her zaman 1 ile 3 arasındadır, yani bir sabittir.
  - $n \log n$ ile $n^{150/100} = n^{1.5}$: $O$. Her $\varepsilon > 0$ için $\log n \in O(n^\varepsilon)$.
  - $\log(\sqrt{10}\, n)$ ile $\log(n^3)$: $\Theta$. İkisi de $\log n$'e eşdeğerdir: $\log(n^3) = 3 \log n$, $\log(\sqrt{10}\, n) = \log \sqrt{10} + \log n$.
  - $n!$ ile $(n+1)!$: $O$. $(n+1)! = (n+1) \cdot n!$, oran $n+1$ sınırsız büyür.

#### 2. Rekürans bağıntıları

- **a)** $x_n = x_{n-1} + 5$ ($n > 1$), $x_1 = 0$. Geriye doğru yerine koyma:
  - $x_n = x_{n-1} + 5 = x_{n-2} + 2 \cdot 5 = x_{n-3} + 3 \cdot 5 = \dots = x_{n-i} + 5i$
  - $i = n - 1$ alınır: $x_n = x_1 + 5(n-1) = 5n - 5$.
- **b)** $T(n) = 4T(n/2) + n^2$, $T(1) = 1$. Master teoremiyle $\Theta(n^2 \log n)$.
  - Soruda $n^2$ yazıyordu. Bir öğrenci $2n$ olarak okuduğunu söyledi. Hoca bunu kontrol edeceğini söyledi.

#### 3. Hash ile iki kümenin kesişimi (C kodu)

- Birinci dizinin elemanları linear probing kullanan bir hash tablosuna yerleştirilecekti.
- İkinci dizinin her elemanı aynı hash fonksiyonuyla bu tabloda aranacaktı.
- Dikkat edilmesi gerekenler:
  - Tablo boyutu için bir asal sayı seçmek.
  - Yerleştirirken tablonun dolu olup olmadığını kontrol etmek. En sık yapılan hata buydu.
  - Ararken boş göz görene kadar ilerlemek ve her gözde elemanın aranan değere eşit olup olmadığına bakmak.
  - Bütün tablo dolaşılıp eleman bulunamazsa, döngüden hangi sebeple çıkıldığını kontrol etmek.
- Sınavın en iyi çözülen sorusu buydu.

#### 4. En kısa sürede koşanı bulma (20 puan)

- $n$ yarışmacının bitirme süreleri (saat, dakika, saniye) veriliyor. Altın madalyayı kimin kazandığı soruluyor.
- Bu bir en küçüğü bulma problemidir. Süreler saniyeye çevrilir, en küçük olan bulunur.
- Yarışmacı bilgileri bir `struct` içinde tutulmalıydı. `struct` kullanmayanlardan puan kırıldı.
- Hocanın gösterdiği böl ve fethet çözümü (en küçüğün indisini döndürür):

```c
int min_index(Runner a[], int l, int r) {
    if (l == r)
        return l;
    int m = (l + r) / 2;
    int t1 = min_index(a, l, m);
    int t2 = min_index(a, m + 1, r);
    return (a[t1].seconds <= a[t2].seconds) ? t1 : t2;
}
/* çağrı: min_index(a, 0, n - 1) */
```

- Karşılaştırma sayısı:
  - $C(n) = 2C(n/2) + 1$ ($n > 1$), $C(1) = 0$.
  - $n = 2^k$ alınır: $C(2^k) = 2^i C(2^{k-i}) + 2^{i-1} + \dots + 2 + 1$.
  - $i = k$ için $C(n) = 2^k \cdot 0 + 2^k - 1 = n - 1$.
- **c) Kaba kuvvet yerine böl ve fethet kullanmak avantaj mıdır?** Hayır. İkisi de $n - 1$ karşılaştırma yapar. Böl ve fethet özyinelemeli fonksiyon çağrılarının yükünü (function call overhead) taşıdığı için dezavantajlıdır.

### Not dağılımı

- Diğer grubun hocasıyla görüşülerek öğrenci önerisi de dikkate alındı. Kesinleşen dağılım:
  - Vize %25
  - Ödevler %25
  - Dönem projesi %10
  - Final %40
- Hoca örnek verdi: Vizeden 12 alan bir öğrenci ödevlerden 100, 100, 100 ve 120 almış.

### Dönem projesi: kitap öneri sistemi

- Proje dokümanı kareden alındı. İşbirlikçi filtre (collaborative filtering) yöntemiyle bir kişiye yeni kitap öneren bir sistem tasarlanacak. Sistemin 3 bölümü var:
  1. **Benzerlik hesabı:** İki okuyucunun benzerliği Pearson katsayısıyla hesaplanır. $P$, iki okuyucunun da okuduğu kitaplar; $\bar{r}_a$, $a$'nın okuduğu kitapların puan ortalaması:

$$sim(a,b) = \frac{\sum_{p \in P} (r_{a,p} - \bar{r}_a)(r_{b,p} - \bar{r}_b)}{\sqrt{\sum_{p \in P} (r_{a,p} - \bar{r}_a)^2}\ \sqrt{\sum_{p \in P} (r_{b,p} - \bar{r}_b)^2}}$$

  - Benzerlik $-1$ ile $+1$ arasındadır.
  2. **En benzer $k$ kişi:** Verilen bir $k$ için okuyucuya en benzeyen $k$ okuyucu bulunur. Bütün elemanları sıralamaktan daha verimli bir yol kullanılmalıdır.
  3. **Kitap önerme:** $N$, en benzer $k$ kişi olsun. Okuyucunun okumadığı her kitap için tahmini puan hesaplanır, en yüksek puanlı kitap önerilir:

$$pred(a,p) = \bar{r}_a + \frac{\sum_{b \in N} sim(a,b)\,(r_{b,p} - \bar{r}_b)}{\sum_{b \in N} sim(a,b)}$$

- **Testler:** `recommend.xls` dosyasında her satır bir okuyucunun 8 kitaba verdiği puanlar. U1-U20 okuyucularının puanları kullanılarak NU1-NU5 okuyucularına öneri yapılacak ($k = 3$).
- Dosyayı doğrudan okumak şart değil. Veriler koda alınabilir veya dosya CSV'ye çevrilebilir.
- Hoca projenin sistemli çalışılırsa 2-3 günde yapılabileceğini söyledi. İsteyen olursa proje sorularını cevaplamak için ayrı bir saat ayarlanabilir.

### Final bilgilendirmesi

- Kesin plan henüz yapılmadı. Hocanın tahmini:
  - İki bölümlü olacak: bir klasik, bir test kısmı. Boşluk doldurma soruları olabilir.
  - Test soruları geri dönülemeyecek şekilde ayarlanabilir.
  - Klasik sorular parça parça verilebilir: Bir soru belirli bir sürede çözülüp yüklenir, sonra ikinci soruya geçilir.
  - Süre konusunda daha dikkatli planlama yapılacak.
- Öğrenci önerileri:
  - Geri dönülemeyen sorularda yanlışların doğruları götürmemesi. Hoca dengeli değerlendireceğini söyledi.
  - Her soru için zorluk derecesi veya ayrılacak süre bilgisi verilmesi. Hoca bunu iyi bir öneri olarak kabul etti.
- Klasik sorularda cevabı kaydetmeden başka soruya geçince cevap kaybolabiliyor. Bu uzaktan eğitim sisteminin bir sorunu. Kaydetmeye dikkat edin.
- Bahar döneminin çevrim içi olup olmayacağı henüz belli değil.

### Ders sonrası notlar

- **Master teoremi formülü:** Hoca $a = b^d$ durumunun sonucunu derste hatırlayamadı, doğrudan cevabı yazdı. Formül: $a = b^d$ ise $T(n) \in \Theta(n^d \log n)$. "Kısa Tekrar Notları"nda üç durum da var.
- **"Sequential sort":** Hoca bir yerde selection sort'a "sequential sort" dedi. Doğru ad seçmeli sıralama (selection sort).
- **Pearson ve tahmin formülü:** Dokümandaki tahmin formülünün paydasında $\sum sim(a,b)$ var. Benzerlikler negatif olabildiği için literatürde payda genellikle $\sum |sim(a,b)|$ olarak alınır. Negatif benzerlikli komşular varsa payda sıfıra yaklaşabilir veya işaret değiştirebilir. Pratikte en benzer $k$ kişinin benzerlikleri genelde pozitif olur.
- **En benzer $k$ kişi:** Bütün diziyi sıralamak $O(n \log n)$'dir. $k$ küçükse $k$ kez en büyüğü seçmek $O(kn)$, $k$ boyutlu bir min-heap kullanmak $O(n \log k)$ sürer. Hızlı seçim (quickselect) ile ortalama $O(n)$'de de bulunabilir.
- **$\Omega(n)$ ifadesi:** $2n^3 - 7n + 1 \in \Omega(n)$ doğrudur ama zayıf bir alt sınırdır. En sıkı alt sınır $\Omega(n^3)$'tür.
- **Altyazı hataları:** "Mertzort" merge sort, "Insurgent Sort" insertion sort, "Quake Sort" quick sort, "Divide and Confure/Concur" divide and conquer, "Yusos" USİS demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
