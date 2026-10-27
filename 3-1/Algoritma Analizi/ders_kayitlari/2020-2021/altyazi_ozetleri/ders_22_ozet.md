# Ders 22 Çalışma Özeti

## Genel Konular

- Dersin tarihi 16 Aralık 2020 Çarşamba. Bu, günün ikinci kaydıdır. Ders 21'deki aradan sonra uygulama saatinde devam eden kısa bir oturumdur (yaklaşık 16 dakika).
- DFS ile topolojik sıralamanın (topological sorting) tamamlanması
  - Push sırasının neden yanlış, pop (çıkarma) sırasının tersinin neden doğru olduğu.
  - Altı düğümlü ikinci örnek: yazılım kurulum sırası.
- Topolojik sıralamanın azalt ve fethet (decrease and conquer) yaklaşımıyla çözülmesi
  - Kendisine gelen kenarı olmayan (kaynak, source) düğümü seç, graftan çıkar, tekrarla.
- Döngü (cycle) olan grafta topolojik sıralama yapılamayacağının anlaşılması.

## Hocanın Özellikle Vurguladığı Kısımlar

- DFS ile topolojik sıralamada push (yığına ekleme) sırası kullanılamaz. Pop sırasının tersi kullanılır.
- Topolojik sıralama tek değildir. Sıra değişebilir, ama bulunan sıra bir çözümdür.
- Topolojik sıralama, azalt ve fethet yaklaşımına çok güzel bir örnektir.
  - Kendisine giren kenar olmayan düğüm başlangıç noktası olabilir.
  - O düğüm çıkarılınca problem küçülür. Kalan grafta yine kendisine giren kenarı olmayan düğüm aranır.
- Kendisine giren kenarı olmayan düğüm bulunamazsa grafta döngü vardır. Bu durumda verilen ders ya da yazılım listesiyle izlenebilecek bir sıra yoktur.
  - Bunu anlamak için DFS gerekmez. Her düğüme gelen kenar olup olmadığına bakmak yeterlidir.

## Kısa Tekrar Notları

- DFS tabanlı topolojik sıralama: DFS ile gez, düğümlerin yığından çıkarılma sırasını kaydet, bu sırayı ters çevir.
- Ders 21 örneği (C1 → C3, C2 → C3, C3 → C4, C3 → C5, C4 → C5):
  - Push sırası C1, C3, C4, C5, C2: geçersiz, çünkü C2, C3'ten sonra gelir.
  - Pop sırası C5, C4, C3, C1, C2. Tersi C2, C1, C3, C4, C5: geçerli.
- Altı düğümlü örnek: pop sırası C5, C6, C4, C2, C3, C1. Tersi C1, C3, C2, C4, C6, C5.
- Azalt ve fethet (kaynak silme) ile aynı örnekte sıra: C1, C2, C3, C4, C5, C6.
- Kaynak düğüm kalmamışsa graf döngü içerir, topolojik sıralama yoktur.

## Detaylı Açıklamalar

### Push sırası neden yanlış?

- Bir öğrenci, yığın dolarken C1, C3, C4, C5'in yazdırılabileceğini, yığın boşalınca C2'nin ekleneceğini söyledi. Bu sıra C1, C3, C4, C5, C2'dir.
- Ama C2, C3'ün ön koşuludur. C2 başta olmalıdır. Bu yüzden push sırası yapıyı bozar.
- Bir başka öğrenci pop sırasının tersini önerdi. Hoca bunu doğruladı:
  - Pop sırası: C5, C4, C3, C1, C2.
  - Tersi: C2, C1, C3, C4, C5. Bütün ön koşullar sağlanır.

### İkinci örnek: altı yazılım

Graf (kareden okundu): C1 → C2, C1 → C3, C2 → C4, C3 → C4, C3 → C5, C4 → C5, C4 → C6.

- DFS adımları (C1'den başlanır, eşitlikte küçük numara seçilir):
  - Yığına C1, C2, C4, C5 eklenir. C5'in komşusu yoktur, çıkarılır.
  - C4'ün sıradaki komşusu C6 eklenir ve çıkarılır. Sonra C4 ve C2 çıkarılır.
  - C1'in ziyaret edilmemiş komşusu C3 kalmıştır. C3 eklenir, sonra C3 ve C1 çıkarılır.
- Pop sırası: C5, C6, C4, C2, C3, C1.
- Tersi, yani kurulum sırası: C1, C3, C2, C4, C6, C5.
- Python ile kontrol edildi: bu sıra bütün kenar koşullarını sağlar. Bu grafın toplam 4 geçerli topolojik sırası vardır.

### Azalt ve fethet ile topolojik sıralama

- Azalt ve fethet yaklaşımında problem, bir adımda daha küçük tek bir probleme indirilir. Böl ve fethetteki gibi ikiye bölmek gerekmez; burada her adımda bir düğüm çıkarılır.
- Adımlar:
  1. Kendisine giren kenarı olmayan bir düğüm bul. Örnekte C1. (Bir öğrencinin "baş düğüm olduğu için" cevabına hoca karşı çıktı. Graf ters çizilse bile ölçüt aynıdır: düğüme gelen kenar yoktur.)
  2. Bu düğümü sıraya yaz ve kenarlarıyla birlikte graftan çıkar.
  3. Kalan grafta yeni kaynak düğümleri bul. C1 çıkınca C2 ve C3 kaynak olur. Hoca küçük numaralı C2'yi seçti.
  4. C2 çıkınca yalnız C3 kaynak kalır. C4'ün hâlâ C3'ten gelen kenarı vardır.
  5. C3'ten sonra C4, sonra C5 ve C6 alınır.
- Sonuç: C1, C2, C3, C4, C5, C6. DFS'in verdiği sıradan farklıdır, ama bu da geçerli bir çözümdür.

### Döngülü graf

- Hoca dört düğümlü bir örnek çizdi: C1 → C3 → C4 → C2 → C1 (kareden okundu).
- Önce döngü yokken kaynak düğüm vardı. C2 → C1 kenarı eklenince her düğüme bir kenar girer.
- Azalt ve fethet ile başlanacak düğüm bulunamaz. Bu, grafta döngü olduğunu ve topolojik sıralamanın yapılamayacağını gösterir.
- Gerçek hayattaki karşılığı: bu ders programıyla ya da bu yazılım bağımlılıklarıyla izlenebilecek bir yol yoktur.

### Ders sonrası notlar

- **Azalt ve fethet tanımı:** Bir öğrenci bu yaklaşımı "problemi küçük parçalara bölüp parçaları çözmek ve birleştirmek" diye tanımladı, hoca kabul etti. Bu tanım böl ve fethetin (divide and conquer) tanımıdır. Azalt ve fethet, problemi tek bir küçük örneğe indirir. Küçültme miktarı sabit bir sayı (örneğin bir düğüm), sabit bir oran (örneğin ikili aramada yarıya) ya da değişken olabilir.
- **Neden pop sırasının tersi?** DFS bir düğümü, ondan ulaşılabilen bütün düğümler bittikten sonra yığından çıkarır. Bu yüzden $u\to v$ kenarı varsa $v$, $u$'dan önce çıkar. Sıra ters çevrilince $u$, $v$'den önce gelir.
- **DFS ile döngü tespiti:** DFS sırasında yığında hâlâ duran bir düğüme giden kenar (geri kenar, back edge) bulunursa yönlü grafta döngü vardır. Bu durumda pop sırasının tersi geçerli bir sıralama olmaz.
- **Kaynak silme yönteminin karmaşıklığı:** Her düğümün giriş derecesi (in-degree) saklanır, kaynaklar bir kuyrukta tutulursa yöntem $\Theta(|V|+|E|)$ sürede çalışır. Bu yönteme Kahn algoritması da denir.
- Altyazıda "Decrease and Concure" diye geçen terim decrease and conquer, "popping off order" diye geçen terim popping-off order (çıkarma sırası) anlamındadır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
