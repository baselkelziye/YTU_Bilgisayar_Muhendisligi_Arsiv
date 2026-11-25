# Ders 21 Çalışma Özeti

## Genel Konular

- Rastgele sayı üreten sözde kodlarda olasılık hesabı (1. ve 2. vize soruları)
  - `rand()` 0-1 aralığında düzgün dağılımlı ondalıklı sayı üretir. İki rastgele sayı $(s_1, s_2)$ birim karede bir nokta gibi düşünülür.
  - `say/N` oranı, $N$ büyüdükçe koşulun sağlanma olasılığına yakınsar. Sonsuz sayıda olası nokta olduğu için olasılık "istenen alan / toplam alan" olarak hesaplanır; toplam alan birim karenin alanı, yani 1'dir.
  - 1. soru: koşul $s_1^2 \le s_2$ (ekrandan, 00:15:00). $s_2 = s_1^2$ eğrisinin altındaki alan $\int_0^1 x^2\,dx = 1/3$; koşulu sağlayan bölge eğrinin üstüdür, olasılık $1 - 1/3 = 2/3$.
  - 2. soru: koşul $(s_1 > 1 - s_2)$ ve $(s_2 < 0.5)$ (ekrandan, 00:20:00). İki koşulun ortak bölgesi dik kenarları $0.5$ olan bir üçgendir; olasılık $\frac{1}{2} \cdot 0.5 \cdot 0.5 = 1/8$.
  - C ile yazılan simülasyonda küçük $N$ için sonuç kararsızdır (0.70, 0.60 gibi); $N = 10^6$ için 0.66 ve 0.12 civarı değerler çıkar.
- Özyinelemeli fonksiyonları tablo ile izleme (3. ve 4. vize soruları)
  - 3. soru: `f(i,j)` fonksiyonu `i==0` ise 0, değilse `f(i/j, j)+1` döndürür; `i=82, j=3` için tamsayı bölmesiyle 82, 27, 9, 3, 1, 0 değerleri gelir ve sonuç 5 olur (ekrandan, 00:25:00).
  - 4. soru: `function(n)` önce kendini `n-1` ile çağırır, sonra `n` tane yıldız ve satır sonu yazar. `function(3)` çıktısı sırasıyla 1, 2, 3 yıldızlı satırlardır; işlem en derine inildikten sonra, geri dönüşte yapılır (ekrandan, 00:30:00).
- En uzun ardışık dizi (Longest Sequence) problemi
  - Girdi `{199, 198, 200, 1, 0, 2, 3}`, çıktı `0,1,2,3` (ekrandan, 00:35:00). Ardışık sayılar dizide karışık sırada durur.
  - Kaba kuvvet çözümü: her eleman başlangıç adayı alınır, dizide "bir fazlası" aranır, bulununca arama baştan başlar. En uzun zincirin başlangıcı ve uzunluğu tutulur, sonra aynı arama ile yazdırılır.
  - Dizi sıralı ise tek geçişte komşu elemanlara bakmak yeterlidir ($O(n)$). Sırasız diziyi önce sıralamak çözümü basitleştirir, ama karmaşıklığı sıralama algoritması belirler ($O(n \log n)$ ya da kötü bir sıralamada $O(n^2)$).
- Özyineleme ile tekrarlı dizilim ve tekrarsız kombinasyon üretme
  - Karakter kümesi `{'a',...,'g'}`, $N=7$, $K=4$ (ekrandan, 01:00:00). Her çağrı bir önek (prefix) alır, kümedeki her karakteri önekin sonuna ekleyip kendini $k-1$ ile çağırır; $k=0$ olunca önek yazdırılır.
  - Tekrarsız kombinasyonda son eklenen karakterin indisi (`LastAdded`) da gönderilir ve döngü bu indisin bir sonrasından başlar; ilk çağrı `-1` ile yapılır.
  - Özyinelemenin iteratif çözüme üstünlüğü: her çağrı kendi durumunu (önekini) saklar, geri dönüşte durum kendiliğinden bir adım geriye gider. $K$ değişken olunca iç içe döngü sayısını sabitlemek gerekmez.
- Rastgele nokta simülasyonunun görselleştirilmesi
  - Aynı rastgele nokta deneyi ekrana nokta koyan bir tarayıcı programıyla çizdirildi; nokta sayısı arttıkça 2. sorudaki üçgen bölge dolar (ekrandan, 01:30:00 ve 01:35:00).
- Proje problemine dair algoritmik ipuçları
  - $N \times N$ matriste eşleşen sayı çiftlerini birbirini kesmeyen yollarla bağlama problemi; komşuluk 4 yönlüdür (sağ, sol, yukarı, aşağı).
  - Otomatik çözüm için bağlantılı bileşen (connected component) bulma algoritmasından ve özyinelemeden yararlanılabilir; çıkmaza girince yapılan hamleleri geri almak (backtracking, matris durumlarını saklayarak geri alma) gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tamsayı bölmesi tuzağı
  - `say` ve `n` tamsayı olduğunda `say/n` tamsayı bölmesi yapar ve ondalık sonuç kaybolur. Bu yüzden işleme `1.0 *` eklenerek tür dönüşümü (typecasting) yapılır.
- Özyinelemede en önemli şey durma koşuludur (base case)
  - Her özyinelemeli fonksiyon önce durma koşulunu kontrol eder; izleme tablosunda her çağrının parametreleri ayrı satırda yazılır ve dönüş değerleri aşağıdan yukarı toplanır.
- Fonksiyon parametresinde dizi tanımı
  - Tek boyutlu dizi parametresinde boyut yazmak gerekmez (`int Arr[]` ya da `int *Arr`). İki ve daha çok boyutlu dizilerde ilk boyut dışındaki boyutlar yazılmalıdır, çünkü derleyici bir satırı atlamak için sütun sayısını bilmek zorundadır.
  - C dizinin bittiğini kendisi kontrol etmez; sınır dışına çıkmak bellek erişim hatasına yol açabilir.
- Okunabilirlik karmaşıklığı ile işlem karmaşıklığı farklıdır
  - Özyineleme yapılacak işlem sayısını azaltmaz; kodun yazılma ve okunma karmaşıklığını azaltır. Labirentte gezinme gibi geri dönüş gerektiren problemlerde bu fark belirgindir.
- Önek dizisini değiştirmeden kopyalamak
  - Gelen öneki doğrudan değiştirmek önceki çağrıların durumunu bozar; bu yüzden yeni bir diziye `strcpy` ile kopyalanır, karakter yeni diziye eklenir.
- Karakter ekleyince dizgi sonu yeniden yazılmalı
  - `strlen` dizginin uzunluğunu verir (son indeks değil). Yeni karakter `dest[len]` konumuna yazılınca eski `'\0'` silinir; bu yüzden `dest[len+1] = '\0'` yazılmalıdır.

## Kısa Tekrar Notları

- $N$ büyükken `say/N` → olasılık = istenen alan / birim karenin alanı.
- $s_1^2 \le s_2$ → $2/3$; $(s_1 > 1-s_2) \wedge (s_2 < 0.5)$ → $1/8$.
- Eşitsizlik bölgesi çizilirken önce eşitlik çizilir, sonra bir test noktasıyla (örneğin $(0,0)$ ya da $(0,1)$) hangi tarafın istendiği bulunur.
- `f(82,3)` = 5; `function(3)` çıktısı 1, 2, 3 yıldızlı üç satır.
- Özyinelemeli çağrıdan sonra yapılan işlem geri dönüş sırasında, yani en derin çağrıdan başlayarak çalışır.
- En uzun ardışık dizi: sırasız dizide iç içe arama, sıralı dizide tek geçiş.
- $K$ uzunluklu tekrarlı dizilim sayısı $N^K$, tekrarsız kombinasyon sayısı $\binom{N}{K}$.
- Tekrarsız kombinasyon için döngü `LastAdded+1`'den başlar.

## Detaylı Açıklamalar

- **Olasılığın alan olarak hesaplanması.** Sözde kodda her adımda iki rastgele sayı üretilir ve koşul sağlanırsa sayaç artar. $N$ çok büyüdüğünde sayaç/$N$ oranı koşulun olasılığına yaklaşır. Olası sonuç sayısı sonsuz olduğu için "istenen durum / tüm durumlar" sayarak değil, alan oranıyla hesaplanır. İki değişken olduğu için uzay bir düzlem bölgesidir (üç değişkende hacim olurdu). $0 \le s_1, s_2 \le 1$ olduğundan uzay birim karedir.
  - 1. soruda $s_2 = s_1^2$ parabolü çizilir. $(s_1, s_2) = (0, 1)$ noktası $0 \le 1$ ile koşulu sağladığı için parabolün üstündeki bölge istenir. Parabol altındaki alan $A = \int_0^1 x^2 dx = 1/3$, istenen alan $B = 1 - A = 2/3$.
  - 2. soruda $s_1 = 1 - s_2$ doğrusu $(1, 0)$ ve $(0, 1)$ noktalarından geçer. $(0,0)$ noktası $0 > 1$ koşulunu sağlamadığından doğrunun üst-sağ tarafı istenir. $s_2 < 0.5$ doğrusu bu doğruyu $s_1 = 0.5$ noktasında keser. Ortak bölge dik kenarları $0.5$ olan üçgen, alanı $\frac{1}{2} \cdot \frac{1}{2} \cdot \frac{1}{2} = 1/8$.
  - Bu sonuçlar ajan tarafından Python ile $10^6$ örnekli simülasyonla da kontrol edildi (yaklaşık 0.667 ve 0.125).
- **Özyineleme izleme.** 3. soruda `main` ilk çağrıyı `f(82,3)` ile yapar. Her çağrıda `i` sıfır değilse `i/j` tamsayı bölmesiyle küçülür: 82 → 27 → 9 → 3 → 1 → 0. Altıncı çağrıda `i == 0` olduğu için 0 döner; dönüşte her seviye 1 ekler: 0+1, 1+1, 2+1, 3+1, 4+1 = 5. 4. soruda ise yazdırma özyinelemeli çağrıdan sonradır; çağrılar 3, 2, 1, 0 diye iner, 0'da durur, dönüşte önce `n=1` için bir yıldız, sonra `n=2` için iki, en son `n=3` için üç yıldız yazılır. Bu iki fonksiyon ajan tarafından C ile derlenip çalıştırıldı; çıktılar 5 ve `*`, `**`, `***` satırlarıdır.
- **En uzun ardışık dizi, kaba kuvvet.** Her `i` için `currNumber = Arr[i]`, `currSequence = 1` ile başlanır. `while` döngüsü diziyi gezer; `Arr[j]-1 == currNumber` olan eleman bulunursa `currNumber` bu elemana geçer, uzunluk artar ve `j = 0` yapılarak arama baştan başlar. `for` yerine `while` seçilmesinin nedeni, eleman bulununca aramayı baştan başlatmak ve döngüyü kendi koşulumuzla yönetmektir. En uzun zincirin uzunluğu `Max`'ta, başlangıç değeri `Start`'ta tutulur. Yazdırırken aynı arama `Start`'tan başlayarak tekrar edilir. Kod ekrandan alınmış, ajan tarafından `gcc -Wall` ile derlenip çalıştırılmıştır; `{199,198,200,1,0,2,3}` için `0 1 2 3`, derste genişletilen `{199,198,200,1,0,2,3,201,202}` için `198 199 200 201 202` verir.
  - Ders sonrası not: Derste bu çözümün $O(n^2)$ olduğu söylendi. Bulunan her elemandan sonra arama baştan başladığı için en kötü durumda (ör. dizi tamamen ardışık sayılardan oluşuyorsa) adım sayısı $O(n^3)$'e çıkar; büyük olasılıkla doğru üst sınır budur.
- **Sıralı dizide tek geçiş.** Dizi sıralıysa `Arr[i]+1 == Arr[i+1]` kontrolüyle tek geçişte ardışık bölümler bulunur; bozulma anında `currSequence > Max` ise bitiş indisi `End` ve `Max` güncellenir. Yazdırırken başlangıç `End - Max + 1` indisidir. Derste `{1,2,3,4,100,200}` için `1 2 3 4` bulundu.
  - Ders sonrası not: Derste anlatılan döngü `i < len` iken `Arr[i+1]`'i okur; `i = len-1` için bu dizinin dışına erişimdir (tanımsız davranış). Ayrıca en uzun bölüm dizinin sonundaysa döngü içinde kaydedilmez. Döngüyü `i < len-1` ile sınırlamak ve döngüden sonra son bölümü de kontrol etmek gerekir.
- **Özyinelemeli dizilim ve kombinasyon üretimi.** Yardımcı `String_concat(char *dest, char source)` fonksiyonu karakteri dizginin sonuna ekler ve sonlandırıcıyı yeniden yazar. `printAllPermutation(set, prefix, n, k)` için $k=0$ durma koşuludur; değilse her `i` için `Newprefix`'e önek kopyalanır, `set[i]` eklenir ve fonksiyon `k-1` ile çağrılır. `printAllCombinations` aynı yapıya `LastAdded` parametresini ekler; döngü `LastAdded+1`'den başlar, alt çağrıya `i` gönderilir. Kod ekrandan alınmış (01:15:00, 01:25:00), ajan tarafından derlenip çalıştırılmıştır: $7^4 = 2401$ tekrarlı dizilim (`aaaa`, `aaab`, ...) ve $\binom{7}{4} = 35$ kombinasyon (`abcd`, `abce`, ...) üretir.
  - Ders sonrası not: Slayt başlığı ilkine "tekrarlı kombinasyon", derste "tekrarlı permütasyon" dendi. Üretilen dizgiler sıralı (`aaab` ile `aaba` farklı) olduğu için matematikte bu, tekrarlı permütasyon (dizilim) sayılır; tekrarlı kombinasyon $\binom{N+K-1}{K}$ tane olurdu.
- **Statik ve global değişkenler üzerine.** Statik tanımlanan dizi ya da matrisin içeriği otomatik sıfırlanır, ama statik değişkenin başka yan etkileri de vardır ve özel kullanım alanları içindir. `memcpy` ile matris kopyalama dinamik (`malloc` ile ayrılmış) matrisler için anlatıldı.
  - Ders sonrası not: Derste sabit boyutlu matrislerde `memcpy` kullanılamayacağı söylendi. C dilinde `int A[N][N]` bellekte bitişik durduğu için `memcpy(B, A, sizeof(A))` geçerlidir; söylenen büyük olasılıkla bu derse özgü bir kısıttır, dilin kısıtı değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
