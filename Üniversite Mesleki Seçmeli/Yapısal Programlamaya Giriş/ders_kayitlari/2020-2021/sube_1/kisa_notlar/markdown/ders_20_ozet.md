# Ders 20 Çalışma Özeti

## Genel Konular

- Algoritma karmaşıklığının deneysel olarak ölçülmesi
  - Bir algoritmanın çalışma süresi, farklı girdi büyüklükleri ($n = 1, \dots, K$) için kod içinde ölçülebilir: algoritma çalışmadan önce bilgisayarın o anki zamanı ($t_1$), bittikten sonra yine zaman ($t_2$) alınır; $t_2 - t_1$ o $n$ için geçen süredir. Zaman `time.h` gibi kütüphanelerle alınır.
  - Elde edilen süreler bir grafik kütüphanesi olmadan da gösterilebilir: her $n$ için satır satır yıldız (`*`) bastırarak komut satırında bar grafik çizilir. Tahtadaki örnekte $n = 1, 2, 3, 4$ için 1, 4, 9, 16 yıldız vardır; bu, $n^2$ karmaşıklığını gösterir (ekrandan, 00:25:00).
  - Bellek analizi de aynı mantıkla yapılır; bu kez süre yerine her girdi büyüklüğünde kullanılan bellek miktarı ölçülür.
- Özyinelemeli (recursive) fonksiyonlar
  - Özyinelemeli fonksiyon kendini çağıran fonksiyondur. Doğrudan özyinelemede `f` fonksiyonu `f`'i çağırır; dolaylı özyinelemede `f` fonksiyonu `g`'yi, `g` de `f`'i çağırır.
  - Klasik örnek faktöriyeldir: $n! = (n-1)! \cdot n$. Faktöriyel yine faktöriyelle tanımlanır.
  - Bir özyinelemeli fonksiyonun hem kendini çağıran (özyinelemeli) hem de çağırmayan (özyinelemesiz) bir parçası olmalıdır.
- Yığın (stack) ve stack overflow
  - İşletim sisteminin programa ayırdığı bellekte fonksiyon çağrılarını yöneten stack bölümü vardır. Bir fonksiyon çağrılırken programın o anki durumu (değişkenler, kalınan satır / program counter gibi bilgiler) stack'e konur; fonksiyon bitince bu değerler geri çekilir ve program kaldığı yerden devam eder.
  - Fonksiyon kendini durmadan çağırırsa stack dolar ve taşar: buna stack overflow denir. Çok fazla sayıda iç içe çağrı da sonsuz döngü olmadan stack overflow'a yol açabilir.
- Derste akış diyagramıyla çözülen özyinelemeli fonksiyonlar
  - Faktöriyel (`fakto`), basit üs alma, iki sayının toplamı, dizinin ilk $b$ elemanının toplamı, dizide arama ve hızlı üs alma.
- Özyineleme ağacı (recursion tree) ile karmaşıklık analizi
  - Döngülü algoritmalarda karmaşıklık sigma toplamlarıyla doğrudan bulunuyordu. Özyinelemeli algoritmalarda döngü olmadığı için özyineleme ağacı kullanılır.
  - Ağacın düğümünde özyinelemesiz kısımda yapılan işlem sayısı, dallarında özyinelemeli çağrılar ($T(n-1)$, $T(n/2)$ gibi) yer alır. Ağaç sonuna kadar açılır; içindeki işlemlerin toplamı algoritmanın karmaşıklığıdır.
  - Amaç, özyinelemeli olarak verilmiş $T(n)$ bağıntısını $T$'ye bağlı olmayan bir ifadeye dönüştürmektir.
- Çözülen bağıntılar
  - $T(n) = 1 + T(n-1)$: ağacın yüksekliği $n$, sonuç $O(n)$ (faktöriyel, basit üs alma).
  - $T(n) = 1 + T(n/2)$: yükseklik $\log_2 n$, sonuç $O(\log_2 n)$ (hızlı üs alma).
  - $T(n) = 1 + 2T(n/2)$: satırlarda $2^i$ tane 1 vardır, toplam $2n-1$, sonuç $O(n)$.
  - $T(n) = 2T(n/2) + n$: her satırın toplamı $n$, satır sayısı $\log_2 n$, sonuç $O(n \log_2 n)$ (merge sort ve quick sort).
  - $T(n) = 2T(n/2) + n/2$: her satırın toplamı $n/2$, sonuç $\frac{n}{2}\log_2 n$, yine $n \log n$ mertebesi.
  - $T(n) = T(n/2) + n$: satırlar $n, n/2, n/4, \dots$ diye azalır; toplam $\sum_{i} \frac{n}{2^i}$ olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Özyinelemeli ve özyinelemesiz parça birlikte olmalı
  - Yalnız $T = N \cdot \text{fakto}(N-1)$ yazılırsa $f(0) = 0 \cdot f(-1)$, $f(-1) = -1 \cdot f(-2)$ diye sonsuza gider; sonuç hiç dönmez, stack overflow olur.
  - Durma koşulunun ne olacağı ve orada hangi değerin döndürüleceği algoritmanın tasarımına bağlıdır. Faktöriyelde $N = 1$ için 1 döndürülür; buraya 0 yazılsaydı sonuç yanlış olurdu.
- Fonksiyon kendini aynı parametreyle çağırmamalı
  - $T = N \cdot \text{fakto}(N)$ yazılırsa $f(3)$ yine $f(3)$'ü çağırır; durma koşulu olsa bile stack overflow olur. Parametre her çağrıda durma koşuluna doğru küçülmelidir.
- Durma koşulu her girdiyi yakalamalı
  - `fakto(-3)` çağrılırsa $N == 1$ koşulu hiç sağlanmaz; $-3, -4, \dots$ diye gider ve stack overflow olur. Koşulun $N \le 1$ gibi tasarlanması gerekir.
- C dili bu tür hataları denetlemez
  - Programcıyı ne kadar denetlediğine göre diller alt, orta ve üst seviyeli diye ayrılır. Denetim arttıkça program güvenli ama yavaş olur; denetim azaldıkça hızlı ama programcının her şeye dikkat etmesi gerekir. C orta seviyeli bir dildir; stack overflow'u önceden uyarmaz, kod çalışınca hata alınır.
- Şimdiye kadarki özyinelemeli örnekler hız kazandırmaz
  - Faktöriyel ve basit üs almanın özyinelemeli halleri de $O(n)$'dir; döngülü halleri de $O(n)$'dir. Üstelik fonksiyon çağrılarının (stack'e koyma, geri çekme) maliyeti yüzünden özyinelemeli hal daha yavaştır. Bu örnekler yalnız özyineleme mantığını öğretmek içindir.
- Hızlı üs almada $k$'yı bir kez hesaplamak gerekir
  - $k = f(x, \lfloor p/2 \rfloor)$ bir kez hesaplanıp $k \cdot k$ kullanılırsa karmaşıklık $\log_2 n$ olur. Aynı çağrı iki kez yazılırsa ($f(\dots) \cdot f(\dots)$) bağıntı $1 + 2T(n/2)$ olur ve kazanç kaybolur, yine $O(n)$'e dönülür. "İşin güzel tarafı burası."
- Özyineleme ağacında açılan düğümün değeri
  - $T(n/2)$ açılırken düğüme $n$ değil $n/2$ yazılır; burası kritik noktadır. Yanlışlıkla yine $n$ yazılırsa sonuç yanlış çıkar.
- Kural ezberlemeye gerek yok
  - Bu bağıntıların bazı kuralları vardır, ama ağaç çizilerek ne olduğu kolayca görülür. Katsayıları değiştirip ($2$ yerine $3$, $n$ yerine $n/2$ gibi) ağaçlar çizerek el alışkanlığı kazanılmalıdır.

## Kısa Tekrar Notları

- Özyinelemeli fonksiyon = kendini çağıran fonksiyon; doğrudan ($f \to f$) ya da dolaylı ($f \to g \to f$) olabilir.
- Her özyinelemeli fonksiyonda özyinelemesiz bir durma parçası ve parametresi küçülen bir özyinelemeli parça olmalıdır.
- Sonsuz özyineleme ya da çok derin çağrı zinciri stack overflow ile sonuçlanır.
- Özyinelemede döngü (`for`, `while`) yazılmaz; döngüyü fonksiyonun kendini çağırması oluşturur.
- $f(3) \to 3 \cdot f(2) \to 2 \cdot f(1) = 1$; geri dönüşte $f(2) = 2$, $f(3) = 6$.
- $f(a,b)$: $b == 0$ ise $a$, değilse $f(a+1, b-1)$ → $a + b$ hesaplar; $f(12,4) = 16$.
- $f(\text{dizi}, b)$: $b == 1$ ise $\text{dizi}[b]$, değilse $\text{dizi}[b] + f(\text{dizi}, b-1)$ → ilk $b$ elemanın toplamı.
- $f(\text{dizi}, b, x)$: $b < 1$ ise $-1$; $\text{dizi}[b] == x$ ise $b$; değilse $f(\text{dizi}, b-1, x)$ → $x$'i arar, yerini ya da $-1$ döndürür.
- Hızlı üs alma: $p == 0$ ise 1; değilse $k = f(x, \lfloor p/2 \rfloor)$, $p$ tekse $x \cdot k \cdot k$, çiftse $k \cdot k$. Karmaşıklık $O(\log_2 n)$.
- Özyinelemesiz kısımdaki sabit sayıda işlem (1, 2, 3 fark etmez) $n$'e bağlı değildir; sabit $c$ gibi düşünülür ve 1 yazılır.
- $T(n) = 1 + T(n-1) \Rightarrow O(n)$; $T(n) = 1 + T(n/2) \Rightarrow O(\log n)$; $T(n) = 1 + 2T(n/2) \Rightarrow O(n)$; $T(n) = 2T(n/2) + n \Rightarrow O(n \log n)$.
- Ağaç yüksekliği: her adımda 1 azalan parametrede $h = n$, her adımda yarıya inen parametrede $h = \log_2 n$.
- Bazı özyinelemeli algoritmalar döngüyle de yazılabilir, ama bazılarını döngüyle yazmak çok daha zordur.

## Detaylı Açıklamalar

- Deneysel süre ölçümü
  - Örneğin bir sıralama algoritması dizinin büyüklüğü $n = 1$'den $K$'ya kadar değişecek şekilde bir döngü içinde çalıştırılır. Döngünün her adımında algoritmadan önce $t_1$, sonra $t_2$ alınır ve $t_2 - t_1$ bir süre dizisine kaydedilir. Döngü bitince bu süreler yıldızlarla çizdirilir. Grafikteki büyüme ile elle bulunan karmaşıklığın aynı olduğu böylece gösterilir. Bir öğrencinin sorusu üzerine bunun satır saymak değil, gerçek çalışma süresini ölçmek olduğu belirtildi. $n$ değerleri kullanıcıdan alınmaz; karakteristiği gösterecek kadar geniş bir aralık programcı tarafından seçilir.
- Faktöriyelin akış diyagramı
  - İlk tasarımda fonksiyon `fakto(N)`, dönüş değeri `T`, tek kutu `T = N · fakto(N-1)` ve `return` vardır; ana algoritmada `S = fakto(5)` çağrılır (ekrandan, 00:45:00). Bu tasarım $f(5) = 5 \cdot f(4)$, $f(4) = 4 \cdot f(3)$, ..., $f(1) = 1 \cdot f(0)$, $f(0) = 0 \cdot f(-1)$ diye sonsuza gider.
  - Düzeltilmiş tasarımda `N == 1` karar kutusu eklenir: doğruysa `T = 1`, yanlışsa `T = N · fakto(N-1)`; iki dal birleşip `return`'e gider (ekrandan, 00:55:00).
  - `f(3)` izlemesi: $f(3)$ stack'e konur, $f(2)$ çağrılır; $f(2)$ stack'e konur, $f(1)$ çağrılır; $f(1) = 1$ döner. $f(2)$ stack'ten çekilir, $2 \cdot 1 = 2$ bulunur; $f(3)$ çekilir, $3 \cdot 2 = 6$ bulunur.
- Basit üs alma
  - $x^n = x \cdot x \cdots x$ ($n$ tane) olduğundan $x^n = x^{n-1} \cdot x$ yazılır. Fonksiyon `üs(x, n)`: $n == 1$ ise $T = x$, değilse $T = x \cdot \text{üs}(x, n-1)$. Negatif üsle çağrılırsa $n == 1$ koşulu hiç sağlanmaz ve stack overflow olur. <!-- BELİRSİZ: Derste örnek çağrının argümanları altyazıda bozuk ("16 olur"); o anın karesi yok. -->
- Hızlı üs alma
  - Akış diyagramı (ekrandan, 01:45:00): `f(x, p)`, `p == 0` ise `T = 1`; değilse `k = f(x, ⌊p/2⌋)`, sonra `p mod 2 == 1` ise `T = x * k * k`, değilse `T = k * k`; `return`.
  - Mantık: $x^9 = x \cdot x^4 \cdot x^4$ ($p = 9$ tek), $x^{16} = x^8 \cdot x^8$ (ekrandan, 01:50:00). $p = 8$ de $p = 9$ da $\lfloor p/2 \rfloor = 4$ verir.
  - $f(x,9)$ izlemesi: $f(x,9) \to f(x,4) \to f(x,2) \to f(x,1) \to f(x,0) = 1$ (ekrandan, 01:55:00). Geri dönüşte $p = 1$ tek: $x \cdot 1 \cdot 1 = x$; $p = 2$ çift: $x \cdot x = x^2$; $p = 4$: $x^4$; $p = 9$ tek: $x \cdot x^4 \cdot x^4 = x^9$.
  - Özyinelemesiz kısımda yalnız birkaç sabit işlem (mod, en çok iki çarpma) vardır; özyinelemeli çağrı bir kez ve $p/2$ ile yapılır. Bu yüzden $T(n) = 1 + T(n/2)$ ve sonuç $\log_2 n$'dir.
- Özyineleme ağaçlarının çözümü
  - $T(n) = 1 + T(n-1)$: ağaç $1, 1, 1, \dots$ diye tek kol halinde iner; $n$ tane 1 vardır, $T(n) = n$.
  - $T(n) = 1 + T(n/2)$: $1 + T(n/2)$, $1 + 1 + T(n/4)$, ...; $\log_2 n$ tane 1 vardır.
  - $T(n) = 1 + 2T(n/2)$: satırlarda $2^0, 2^1, 2^2, \dots, 2^h$ tane 1 vardır, $h = \log_2 n$. Toplam $\sum_{i=0}^{h} 2^i = 2 \cdot 2^{\log_2 n} - 1 = 2n - 1$, yani $O(n)$.
  - $T(n) = 2T(n/2) + n$: kökte $n$, ikinci satırda iki tane $n/2$, üçüncü satırda dört tane $n/4$, dördüncü satırda sekiz tane $n/8$ vardır (ekrandan, 02:10:00). Her satırın toplamı $n$, satır sayısı $\log_2 n$; $T(n) = n \log_2 n$. Gördüğümüz diğer sıralama algoritmaları $n^2$ mertebesindeydi; $n \log n$ bundan çok daha iyidir.
  - $T(n) = 2T(n/2) + n/2$: kökte $n/2$, sonra iki tane $n/4$, dört tane $n/8$; her satırın toplamı $n/2$ olur, yükseklik değişmez: $\frac{n}{2} \log_2 n$.
  - $T(n) = T(n/2) + n$: tek kol $n, n/2, n/4, \dots, 1$; yükseklik yaklaşık $\log_2 n + 1$; toplam $\sum_{i=0}^{\log_2 n + 1} \frac{n}{2^i}$ (ekrandan, 02:20:00). Bu toplam $2n$'yi geçmez, yani $O(n)$'dir (son adım derste tamamlanmadı, hesap ders sonrası yapıldı).
- En kötü, en iyi ve ortalama durum
  - Bir öğrencinin sorusu üzerine: `if`'in bir dalında fonksiyon üç kez, öbür dalında iki kez çağrılıyorsa en kötü durum analizinde hep çok çağrılan daldan, en iyi durumda hep az çağrılan daldan geçildiği varsayılır. Ortalama durum için dallara girme olasılığı (hızlı üs almada $p$'nin tek ya da çift olması gibi) bilinmelidir; örneğin 0.3 olasılıkla iki kez, 0.7 olasılıkla bir kez çağrı gibi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
