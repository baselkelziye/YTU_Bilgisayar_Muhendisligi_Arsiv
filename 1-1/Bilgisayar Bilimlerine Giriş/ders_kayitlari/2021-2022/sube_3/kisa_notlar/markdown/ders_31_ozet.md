# Ders 31 Çalışma Özeti

## Genel Konular

- Arama algoritmalarına giriş
  - Arama, bir veri grubu içinde belirli bir kaydın var olup olmadığını ve varsa yerini bulma işidir. Genelde tekrar etmeyen (unique) anahtarlar üzerinde yapılır: okul numarası, T.C. kimlik numarası, kütüphanedeki kitap kodu, banka hesap numarası gibi.
  - Veri sırasız (unsorted) ya da sıralı (sorted) saklanabilir. Derste veriler dizi üzerinde ele alındı; aramanın matris ve başka veri yapılarında da yapılabildiği belirtildi.
  - Sırasız dizide doğrusal arama (linear search) kullanılır. Sıralı dizide doğrusal arama biraz değiştirilerek kullanılabilir; ayrıca sıra bilgisi binary search, jump search, interpolation search, exponential search gibi daha verimli algoritmalara imkan verir.
- Sırasız dizide doğrusal arama (akış diyagramı)
  - Girdi: `N`, `A[N]`, aranan `X`. `I = 1` ile başlanır.
  - Döngü koşulu: `I <= N AND A[I] ≠ X`; döngü içinde yalnız `I = I + 1` yapılır (ekrandan, 00:25:00).
  - Döngüden çıkınca hangi koşul yüzünden çıkıldığı `I <= N` ile ayırt edilir: doğruysa `I` yazdırılır, yanlışsa "Not found" yazdırılır, sonra STOP.
  - Örnek dizi `5, 1, 2, 3, 6, 4` ($N = 6$): `X = 3` için 4, `X = 4` için 6 yazılır; `X = 7` için `I = 7` olunca döngü biter ve "Not found" yazılır.
- Sıralı dizide doğrusal arama
  - Soru (ekrandan, 00:30:00): "Verilen bir elemanın varsa yerini yoksa bulunmadığı bilgisini ekrana yazdıran algoritmanın akış diyagramını çiziniz (sıralı bir dizide)." Örnek dizi: `1, 3, 5, 8, 12, 25, 32`.
  - Fikir: aranan değerden büyük bir elemana gelindiğinde aramayı sürdürmeye gerek yoktur.
  - İlk tasarım: `I <= N AND Y > B[I]` sürdükçe `I = I + 1`; çıkışta `Y = B[I]` ise `I`, değilse "Not found" (ekrandan, 00:40:00). Bu tasarım aranan değer dizinin bütün elemanlarından büyükse (örneğin 35) `I = N + 1` olur ve `B[N+1]` dizinin dışına çıkar.
  - Düzeltme 1: çıkıştaki karşılaştırmaya bir koşul daha eklenir: `I <= N AND Y = B[I]`.
  - Düzeltme 2 (ek koşulsuz): döngü koşulu `I ≠ N AND Y > B[I]` yapılır, çıkışta yalnız `Y = B[I]` sorulur (ekrandan, 01:00:00). Son eleman döngüde değil, çıkıştaki kontrolde incelenir; dizinin dışına çıkılmaz.
  - Eşitlik kontrolü döngü içine de alınabilir (bulundu bayrağı gibi bir değişkenle), ama bu her turda bir kontrol daha demektir; kontrolü doğrudan `while` koşulunda yapmak daha akıllıcadır.
- İkili arama (binary search)
  - Sezgi: 1-100 arasında tutulan sayıyı "küçük/büyük" ipuçlarıyla bulma oyunu. İlk tahmin 50, "büyük" denirse 75; her adımda aralığın ortası söylenir.
  - Yalnız sıralı dizide çalışır. Örnek dizi: `1, 5, 8, 12, 25, 38, 42, 56` (ekrandan, 01:10:00).
  - Başlangıç: `bas = 1`, `son = N`, `orta = (bas + son) DIV 2`.
  - Döngü: `bas <= son AND X ≠ A[orta]` sürdükçe; `X > A[orta]` ise `bas = orta + 1`, değilse `son = orta - 1`; iki durumda da `orta = (bas + son) DIV 2` yeniden hesaplanır.
  - Çıkış: `bas <= son` ise `orta` yazdırılır, değilse "Not found" (ekrandan, 01:25:00).
  - İz sürme: `X = 42` için (bas, orta, son) = (1, 4, 8) → (5, 6, 8) → (7, 7, 8), `A[7] = 42` bulunur. `X = 43` için (8, 8, 8) adımında `A[8] = 56`, `son = 7` olur, `bas > son` olduğu için "Not found".
- Zaman karmaşıklığı (en kötü durum)
  - Doğrusal arama: bulunursa $O(N)$, bulunamazsa $N + 1$ kontrol (ekrandan, 01:30:00).
  - İkili arama: bulunursa $O(\log_2 N)$, bulunamazsa $\log_2 N + 1$. $N = 100$ için yaklaşık 7, $N = 1000$ için yaklaşık 10 adım.
  - İç içe iki döngü genelde $N^2$ demektir; $N^2$, $N^3$ gibi karmaşıklıklardan kaçınılır. $\log_2 N$ çok verimli, $N$ de tatmin edicidir.
- Özel durumlar
  - Sırasız matriste arama: bütün matris satır satır, her satırda bütün sütunlar gezilerek yapılır.
  - Tekrarlı elemanlar (örneğin bir değerin kaç kez geçtiği): sırasız dizide sonuna kadar gidilmesi gerektiği için `for`; sıralı dizide (`1, 2, 3, 3, 4, 5, 5`) aranan değer geçilince durulabileceği için `while` uygundur.
  - Sırasız diziye ikili arama uygulamak için önce sıralamak gerekir. Karşılaştırmalı sıralamanın en iyi maliyeti $O(N \log N)$ olduğundan toplam karmaşıklık $O(N \log N)$ olur.
- Doğrudan adresleme ve hash tablosu
  - Değeri kendi indisinde saklamak (direct address table) çok hızlı erişim verir ama yer israfına yol açar.
  - Hash tablosunda bir hash fonksiyonu değeri bir göze yerleştirir. Örnek: mod 13 ile 1 → 1, 7 → 7, 8 → 8, 15 → 2, 22 → 9 (ekrandan, 01:35:00).
  - Aynı adrese düşen değerler belli bir kurala göre başka gözlere yazılır. Bu yöntemler aramayı $O(1)$ düzeyine indirebilir; yer karmaşıklığı yüksek olduğu için her zaman kullanılamaz.
- Jump search
  - Sıralı dizide belirli adımlarla atlanarak (örneğin `1, 5, 8, 12, 96, 172, 251, 255, 3000`) aranan değerin bulunduğu aralık bulunur, sonra o aralıkta doğrusal arama yapılır (ekrandan, 01:45:00).
  - En uygun atlama boyu $\sqrt{N}$, karmaşıklık $O(\sqrt{N})$: doğrusal aramadan hızlı, ikili aramadan yavaş.

## Hocanın Özellikle Vurguladığı Kısımlar

- Arama için `for` değil `while`
  - Elemanın nerede bulunacağı bilinmez; bulunduktan sonra kalan (belki milyonlarca) kayda bakmak boşa iştir. Bu yüzden döngü koşulunda hem "dizinin sonu" hem "eleman bulundu mu" kontrolü olan `while` kullanılır.
- Akış diyagramı çizim hataları
  - Döngü ve karar kutularından çıkan doğru/yanlış kolları doğru yere bağlanmalıdır; bir kolu rastgele STOP'a ya da döngünün içine bağlamak yaygın ve puan kaybettiren bir hatadır.
- Döngüden çıkınca çıkış nedenini ayırt etmek
  - İki koşullu bir `while`'dan çıkınca hangi koşulun bozulduğu bilinmez; bu, çıkışta ayrı bir karar kutusuyla ayırt edilir.
- Dizinin dışına çıkma
  - Sıralı aramada aranan değer bütün elemanlardan büyükse ilk tasarım `B[N+1]`'e bakar. Tasarım her durum için (ilk eleman, son eleman, aradaki olmayan değer, en büyükten büyük değer) iz sürülerek test edilmelidir.
- İkili aramadaki belirgin hata
  - Karşılaştırma `A[I]` ile değil `A[orta]` ile yapılmalıdır; algoritmada `I` diye bir değişken yoktur. `orta`, `bas` ya da `son` değiştiği için her iki kolda da güncellenir.

## Kısa Tekrar Notları

- Sırasız dizi: doğrusal arama, `I <= N AND A[I] ≠ X`, çıkışta `I <= N` kontrolü.
- Sıralı dizi doğrusal arama: `I ≠ N AND Y > B[I]`, çıkışta `Y = B[I]`.
- İkili arama: `bas`, `son`, `orta = (bas + son) DIV 2`; sağa gidince `bas = orta + 1`, sola gidince `son = orta - 1`.
- Karmaşıklık: doğrusal $O(N)$ (bulunamazsa $N+1$), ikili $O(\log_2 N)$ (bulunamazsa $\log_2 N + 1$), jump $O(\sqrt{N})$, hash $O(1)$.
- Sırala + ikili ara: $O(N \log N)$.
- Tekrarlı değer sayma: sırasızda `for`, sıralıda `while`.
- 1'den başlayan indiste son indis `N`, 0'dan başlayan indiste `N - 1` olur.

## Detaylı Açıklamalar

Derste önce sırasız bir dizide aranan elemanın yerini bulan doğrusal arama akış diyagramı birlikte çizildi. Öğrencilerden gelen "`for` kullanalım" önerisine karşı hoca, elemanın ilk adımda da son adımda da bulunabileceğini, bulunduktan sonra kalan kayıtlara bakmanın gereksiz olduğunu ve bu yüzden `while` kullanılması gerektiğini anlattı. Döngü koşulunda iki kontrol vardır: `I <= N` dizinin sonuna gelinip gelinmediğini, `A[I] ≠ X` elemanın bulunup bulunmadığını söyler. Döngü içinde yalnız `I` artırılır. Döngüden çıkıldığında hangi koşul yüzünden çıkıldığı bilinmediği için `I <= N` yeniden sorulur. En kötü durumda eleman bulunursa $N$ kontrol, bulunamazsa son olarak dizinin bittiğini anlamak için bir kontrol daha, yani $N + 1$ kontrol yapılır.

Sıralı dizide aranan değerden büyük bir elemana gelindiğinde aramayı bırakmak mümkündür. İlk tasarımda döngü `I <= N AND Y > B[I]` koşuluyla kuruldu ve çıkışta `Y = B[I]` soruldu. 1, 32, 4 ve 9 gibi değerlerde tasarım doğru çalışır; ama 35 arandığında `I` 8 olur ve dizide olmayan `B[8]`'e bakılır. Bu iki yolla düzeltildi: çıkıştaki karara `I <= N` eklemek ya da döngü koşulunu `I ≠ N AND Y > B[I]` yapmak. İkinci yolda son eleman hiçbir zaman döngüde karşılaştırılmaz, çıkıştaki tek eşitlik kontrolünde incelenir; böylece dizinin dışına çıkılmaz.

İkili aramada her turda ya `bas` ya `son` değişir, dolayısıyla `orta` da değişir. Döngü `bas <= son AND X ≠ A[orta]` koşuluyla sürer. Döngüden eleman bulunduğu için çıkılmışsa `bas <= son` hala doğrudur ve `orta` yazdırılır; aralık boşaldığı için çıkılmışsa "Not found" yazdırılır. Hoca tahtada önce bilerek `A[I]` yazdı ve öğrencilerden hatayı bulmalarını istedi; doğrusu `A[orta]`'dır. 8 elemanlı örnekte 42, üç adımda bulunur; 43 için `bas = 8`, `son = 7` olur ve arama başarısız biter.

Karmaşıklık kısmında doğrusal ve ikili aramanın en kötü durumları karşılaştırıldı: 1000 elemanda doğrusal arama 1000, ikili arama yaklaşık 10 kontrol yapar. Ardından tekrarlı değerler, sırasız matriste arama, sıralamanın maliyeti, doğrudan adresleme, hash tablosu ve jump search kısaca anlatıldı. Hash yöntemleri ve karmaşıklık ilerideki derslerde ayrıntılı görülecek konular olarak anıldı.

Ders sonunda antrenman sorusu olarak 8 sütunlu, ikili tümleyen (işaretli tam sayı) sayılar saklayan bir 0/1 matrisinin her satırını onluk değere çeviren algoritma verildi. Tahtada 3. satır `01111111` = 127, 4. satır `10001000` = −120 (önce bire göre tümleyen `01110111`, sonra 1 eklenerek `01111000` = 120), 5. satır `00000001` = 1 olarak hesaplandı (ekrandan, 01:40:00). Önerilen yaklaşım: satırın işaretsiz değeri hesaplanır, en soldaki bit 1 ise değerden 256 çıkarılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
