# Ders 8 Çalışma Özeti

## Genel Konular

- İki sıralı diziyi tek sıralı dizide birleştirme
  - Problem: $L1$ dizisi $m$, $L2$ dizisi $n$ elemanlı ve ikisi de küçükten büyüğe sıralı. Amaç $m+n$ elemanlı, yine sıralı bir $L3$ dizisi üretmek (ekrandan, 00:15:00).
  - Örnek: $L1 = 1, 3, 6, 9$ ve $L2 = 2, 4, 8, 10, 12$ ise $L3 = 1, 2, 3, 4, 6, 8, 9, 10, 12$ (ekrandan, 00:15:00).
  - Kötü yol: iki diziyi arka arkaya $L3$'e kopyalayıp sıralamak. $k = m+n$ denirse en hızlı sıralama algoritmalarıyla bile maliyet $k \log_2 k$ olur.
  - İyi yol: $L1$ için $i$, $L2$ için $j$ indisi tutulur. Her adımda $L1[i]$ ile $L2[j]$ karşılaştırılır; küçük olan $L3[k]$'ya yazılır ve onun indisi bir artırılır. Döngü $k = 1 \ldots m+n$ boyunca döner, maliyet $m+n$'dir.
  - Dizilerden biri bitince var olmayan elemana bakılır. Çözüm: dizilerin sonuna sonlandırıcı (sentinel) eklemek, $L1[m+1] = 10^6$, $L2[n+1] = 10^6$ (ekrandan, 00:20:00).
- Bir dizide eleman arama
  - Sırasız dizide doğrusal arama en fazla $N$ karşılaştırma ister (ekrandan, 00:35:00).
  - Sıralı dizide ikili arama (binary search) en fazla $\log_2 N$ karşılaştırma ister: her adımda ortadaki elemana bakılır ve dizinin yarısı atılır.
- Bir dizinin sıralı olup olmadığını bulma
  - Önce sıralayıp sonra karşılaştırmak $N \log_2 N + N$ tutar (ekrandan, 00:35:00).
  - Doğrudan yol: $i = 1$'den başlayıp $i < N$ ve $A[i] < A[i+1]$ olduğu sürece $i$ artırılır. Döngüden çıkınca $i = N$ ise dizi sıralıdır, değilse sıralı değildir (ekrandan, 00:40:00). Maliyet en fazla $N$'dir.
- Dizideki değerlerin sayısını bulma
  - Yalnız 1 ve 2'lerden oluşan dizide bir sayaç (`bir`) yeterlidir; 2'lerin sayısı $N - bir$ olur (ekrandan, 00:45:00).
  - 1, 2 ve 3'lerden oluşan dizide iki sayaç ve iç içe iki karar kutusu yeterlidir; 3'lerin sayısı $N - bir - iki$ olur (ekrandan, 00:50:00).
  - 1-9 arası değerlerde her değere ayrı sayaç ve ayrı `if` açmak şık değildir. İç içe iki döngü ($j = 1 \ldots 9$) $9N$ karşılaştırma yapar (ekrandan, 01:10:00).
  - En iyi çözüm (bir öğrencinin önerisi): sayaç dizisi $B$ sıfırlanır, her eleman için $B[A[i]] = B[A[i]] + 1$ yapılır. Tek döngü, maliyet $N$.
- Seçim sistemleri (sayma çözümünün uygulaması)
  - Tek oy: $A$ dizisi $V$ vatandaşın oy verdiği partiyi ($1 \ldots P$) tutar. $B[A[i]]$ artırılır, sonra $B$'nin en büyük elemanı bulunur.
  - Herkes üç partiye oy verir: $A$, 3 satır ve $V$ sütunlu bir matris olur. İç içe döngüyle $B[A[j,i]] = B[A[j,i]] + 1$ yapılır (ekrandan, 01:25:00).
  - Herkes her partiye 1-10 arası puan verir: $A[j,i]$, $i$. vatandaşın $j$. partiye verdiği puandır (ekrandan, 01:30:00). Her partinin satırı toplanır ve en büyüğü bulunur.
  - Ağırlıklı oy: her vatandaşın oyunun ağırlığı $R[i] \in (0,1)$ olarak tutulur. Güncelleme $B[A[i]] = B[A[i]] + R[i]$ olur (ekrandan, 01:45:00). Ağırlık kriterleri (yaş, gelir, eğitim) sınıfla tartışıldı.
- Linear Sort with Counting
  - Temel fikir: "Benden küçük $k$ sayı varsa benim yerim $k+1$'dir." (ekrandan, 02:00:00)
  - Her $A[i]$ için kendisinden küçük eleman sayısı $K[i]$ bulunur, sonra $B[K[i]+1] = A[i]$ yapılır (ekrandan, 02:05:00).
  - Örnek: $A = 3, 1, 4, 6$ için $K = 1, 0, 2, 3$, $K+1 = 2, 1, 3, 4$ ve $B = 1, 3, 4, 6$ (ekrandan, 02:00:00).
  - Maliyet $N^2$'dir. Karşılaştırmanın yanlış (F) dalında $K[j]$ de artırılırsa iç döngü yalnız $i$'ye kadar döner ve maliyet yaklaşık $N^2/2$'ye iner.
  - Ders sonrası not: Tahtada iç döngünün üst sınırı $i$ yazıldı. $j = i$ olduğunda $A[i] > A[i]$ yanlış olur ve F dalı $K[i]$'yi gereksiz yere artırır. $A = 3, 1, 4, 6$ için bu durumda $K = 2, 1, 3, 4$ çıkar ve $B[5]$'e yazılmaya çalışılır. İç döngü $i-1$'e kadar dönmelidir; o zaman $K = 1, 0, 2, 3$ doğru çıkar (python ile denendi).
- Var/yok işaretleyerek doğrusal sıralama (derste sınıfa sorulan algoritma)
  - Önce en büyük eleman $T$ bulunur, $T$ elemanlı $K$ dizisi sıfırlanır, her eleman için $K[A[i]] = 1$ yapılır. Sonra $K$ baştan taranır, $K[i] \neq 0$ olan her $i$ sırayla $B$'ye yazılır (ekrandan, 02:15:00).
  - Örnek: $A = 6, 3, 5, 7$, $T = 7$, $K = 0, 0, 1, 0, 1, 1, 1$, $B = 3, 5, 6, 7$ (ekrandan, 02:25:00).
  - Hiç iç içe döngü yoktur; maliyet $\max(N, T)$'dir (ekrandan, 02:30:00).
  - Zayıf yanları: aynı değerden birden çok varsa tek bir taneye iner, ve $T$ büyükse çok bellek harcar (örneğin $100, 1, 2$ için 100 elemanlı dizi açılır).

## Hocanın Özellikle Vurguladığı Kısımlar

- Dizi sınırı dışına erişim
  - C, dizinin ayrılan alanının dışına (örneğin 10 elemanlı dizide 11. elemana) erişime izin verir; başka diller hata verir. Orada ne olduğu bilinmez, program bazen çalışır bazen sorun çıkarır; kararlı (stabil) olmaz.
  - Bu yüzden sıralılık kontrolünde $i < N$ koşulu $A[i] < A[i+1]$'den önce yazılır. "Ve" ile bağlı koşullarda ilk koşul yanlışsa ikincisine bakılmaz.
- Sonlandırıcı değer seçimi
  - Sonlandırıcı, dizideki her elemandan büyük olmalıdır. Elle büyük bir sayı yazmak yerine dilin alabileceği en büyük değer (`int` için `INT_MAX`) ya da dizinin maksimumundan bir fazlası kullanılır.
  - Döngü $m+n$ adımda biteceği için sonlandırıcı hiçbir zaman $L3$'e yazılmaz; sona birden fazla sonlandırıcı eklemek de sonucu bozmaz.
- Karmaşıklıkta sabit katsayılar
  - $2N$, $N/2$, $N/100$ gibi $N$'e bağlı olmayan katsayılar karmaşıklık analizinde önemsenmez; $N^2 + N$ için yalnız baskın terim $N^2$'ye bakılır. Pratikte fark vardır ama $N$ büyüdükçe önemi azalır.
- Hız ile bellek/doğruluk arasındaki takas
  - Var/yok sıralaması 1 milyon farklı sayıyı yaklaşık $10^6$ adımda sıralar; $N^2$'lik algoritma $10^{12}$ adım ister. Ama tekrar eden değerleri kaybeder ve büyük değerlerde fazla bellek ister.

## Kısa Tekrar Notları

- İki sıralı dizi, iki indis ve sonlandırıcıyla $m+n$ adımda birleştirilir.
- Sırasız dizide arama $N$, sıralı dizide ikili arama $\log_2 N$ karşılaştırma ister.
- Sıralılık kontrolü: $i < N$ ve $A[i] < A[i+1]$ iken ilerle; sonunda $i = N$ ise sıralı.
- Değer sayma: $B[A[i]] = B[A[i]] + 1$ ile tek döngüde, $N$ adımda.
- Seçim problemleri aynı sayma fikrinin genellemeleridir: matris, puan toplama, ağırlıklı ($+R[i]$) oy.
- Linear Sort with Counting: $K[i]$ = $A[i]$'den küçük eleman sayısı, yer $K[i]+1$; maliyet $N^2$ (iyileştirilmiş hali $N^2/2$).
- Var/yok sıralaması: maliyet $\max(N,T)$, ama tekrarları siler ve $T$ boyutunda dizi ister.
- Sabit katsayılar karmaşıklıkta göz ardı edilir.

## Detaylı Açıklamalar

- **Birleştirme algoritmasının akışı.** Önce $m$ ve $n$, sonra $L1$ ve $L2$ okunur, $i = 1$, $j = 1$ yapılır (ekrandan, 00:15:00). $k = 1 \ldots m+n$ döngüsünde `L1[i] < L2[j]` doğruysa `L3[k] = L1[i]; i = i + 1`, yanlışsa `L3[k] = L2[j]; j = j + 1` yapılır (ekrandan, 00:20:00). Örnekte önce 1 ile 2 karşılaştırılır, 1 yazılır ve $i$ ilerler; sonra 3 ile 2 karşılaştırılır, 2 yazılır ve $j$ ilerler. Bir öğrenci kısa dizinin sonunda var olmayan elemana bakılacağını fark etti; sonlandırıcı bu sorunu çözer. Döngü $m+n$ adımda bittiği için sonlandırıcıya hiç ulaşılmaz.
- **Sıralılık kontrolünde sınır tartışması.** İndisler 1'den başlıyor. Dizi sıralıysa son karşılaştırma $A[N-1] < A[N]$'dir ve bu $i = N-1$ iken yapılır; bu yüzden döngü koşulu $i < N$, çıkıştaki test $i = N$ olur. Bir öğrenci koşulların sırasının önemli olduğunu gösterdi: $A[i] < A[i+1]$ önce yazılırsa $i = N$ iken $A[N+1]$'e erişilir. $i < N$ önce yazılınca bu erişim hiç olmaz.
- **Sayma dizisi.** 1-9 arası değerler için 9 elemanlı $B$ sıfırlanır. $A = 4, 5, 3, 4$ için sırasıyla $B[4]$, $B[5]$, $B[3]$, $B[4]$ birer artar; sonunda $B[3] = 1$, $B[4] = 2$, $B[5] = 1$ olur. Bu fikir seçim problemlerinde partilerin oylarını saymak için kullanıldı; parti sayısı $P$ ise $B$'nin boyu $P$ olur.
- **Linear Sort with Counting.** İç içe iki döngüyle $A[i] > A[j]$ ise $K[i]$ artırılır, döngüden önce $K$ sıfırlanır (ekrandan, 02:00:00). Ardından $i = 1 \ldots N$ için `B[K[i]+1] = A[i]` yapılır (ekrandan, 02:05:00). Bir öğrenci neden $+1$ yazıldığını sordu: 1'den başlayan indislerde en küçük elemanın $K$ değeri 0'dır ve yeri 1 olmalıdır; 0'dan başlayan C dizilerinde $+1$ gerekmez.
- **Var/yok sıralaması.** Hoca algoritmayı açıklamadan çizdi ve sınıfa ne yaptığını ve karmaşıklığını sordu. Doğru cevap "sıralama" ve $\max(N, T)$'dir. Bütün döngüler $N$ ya da $T$ kadar döner, hiçbiri iç içe değildir. 1'den 100'e kadar karışık sayılarda 100 adım yeterken $N^2$'lik algoritma 10.000 adım ister.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
