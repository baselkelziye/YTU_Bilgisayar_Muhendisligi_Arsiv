# Ders 24 Çalışma Özeti

## Genel Konular

- Şifreleme (kriptoloji) ve temel kavramlar
  - Kriptoloji iki kola ayrılır: kriptografi (metni/veriyi şifreleme) ve kriptanaliz (şifrelenmiş veriyi çözme). Kodlamadan (encoding) farkı, amacın veriyi küçültmek değil güvenliği sağlamak olmasıdır.
  - Her iki durumda da veri bir $f$ fonksiyonundan geçirilir: $\text{Data}_1 \xrightarrow{f} \text{Data}_2$. Orijinale dönebilmek için $f$'nin tersi alınabilir olmalıdır (ekrandan, 00:10:00).
  - Özel anahtar (private key): anahtar yalnız iki tarafta (Alice ve Bob) bulunur. Açık anahtar (public key): anahtar ortadadır, ama taraflar ondan kendi anahtarlarını üreten bir protokol uyguladığı için başkası mesajı çözemez. Derste yalnız özel anahtarlı basit yöntemler işlendi.
- Sezar (Caesar) şifresi
  - Her harfin sayısal karşılığına sabit bir $c$ eklenir: $f(x_i) = (x_i + c) \bmod 26$ (ekrandan, 00:10:00). Anahtar $c$'dir.
  - $c = 2$ için `ABC` → `CDE`, `Z` → `B`. Çözme: $f^{-1}(x_i) = (x_i - c) \bmod 26$; sonuç negatifse 26 eklenir ($1 - 2 = -1 \to 25$, yani `B` → `Z`).
  - Küçük harf, rakam ve noktalama da kullanılacaksa ASCII yerine kendi karakter dizinizi (ör. 78 karakter) tanımlayıp mod 78'de çalışabilirsiniz; şifreleme dizideki indis üzerinden yapılır.
- Afin (affine) şifreleme
  - $f(x_i) = (a\,x_i + c) \bmod 26$; iki anahtar vardır: $a$ ve $c$ (ekrandan, 00:30:00).
  - Ters fonksiyon: $f^{-1}(x_i) = \left[a^{-1}(x_i - c)\right] \bmod 26$. Burada $a^{-1}$, $a$'nın mod 26'da çarpmaya göre tersidir: $a \cdot a^{-1} \equiv 1 \pmod{26}$.
  - Her sayının mod 26'da tersi yoktur. $2$ ile $0..25$ arası sayıların çarpımları mod 26'da yalnız çift değerler verir, 1'e hiç ulaşmaz; 2 anahtar olamaz. $3 \cdot 9 = 27 \equiv 1$, yani $3^{-1} = 9$ (ekrandan, 00:20:00 ve 00:30:00).
  - $c$ için kısıt yoktur; toplamanın tersi her zaman vardır.
  - Örnek: $a = 3$, $b = 3$ ile `ABCD` → `DGJM`, çözünce yine `ABCD`.
- Matris (koordinat) şifreleme ve frekans analizi
  - Harfler bir matrise yerleştirilir (ör. 6×5), her harf satır-sütun numarasıyla gönderilir (ör. `A` → `13`). Anahtar, iki tarafta da bulunan matristir (ekrandan, 00:35:00).
  - Zayıflığı: her harfin tek karşılığı vardır. Uzun bir şifreli metindeki sembollerin histogramı, dilin harf sıklığı histogramıyla (Türkçede en sık `A`, İngilizcede `E`) eşleştirilerek metin anahtarsız çözülebilir.
  - Çözüm: sık kullanılan harfleri matriste birden fazla hücreye serpiştirmek (bir `A` için 13, başka bir `A` için 10 ya da 28 göndermek). Böylece şifreli metnin histogramı düzgün dağılıma yaklaşır ve dil histogramıyla eşleşmez.
- Kelime şifreleme (tam kare matrisle yer değiştirme)
  - Mesaj, uzunluğundan büyük en yakın tam karelik $n \times n$ matrise bir düzende yerleştirilir, başka bir düzende okunur. `MERHABA` (7 karakter) 3×3 matrise satır satır yazılır, sütun sütun okunur: `MHAEARB` (ekrandan, 00:40:00).
  - Çözen taraf önce boş hücreleri işaretler (sondaki $n^2 - \text{length}$ hücre), sonra şifreli metni okuma düzeniyle yerleştirir, yazma düzeniyle okur.
  - Bu yöntem de çok uzun metinlerde frekans analizine açıktır.
- Parola saklama üzerine
  - Sistemler parolayı açık metin olarak değil, özetleme (hash) fonksiyonundan geçirip saklar. Bu yüzden "şifremi unuttum" dendiğinde parola hatırlatılmaz, sıfırlatılır. Parolayı açık metin olarak e-postayla geri gönderen siteler güvensizdir.
- `scanf` ile boşluklu metin okuma ve girdi tamponu
  - `%s` boşlukta (whitespace) okumayı bitirir: `yildiz teknik` girilince yalnız `yildiz` (6 karakter) alınır.
  - `%[^\n]` satır sonu görülene kadar bütün karakterleri okur; `%[^e]` ilk `e`'ye kadar okur (`yildiz teknik` → `yildiz t`, 8 karakter).
  - Dizi adı adres gibi davrandığı için string okurken `&` yazılmaz; sıradan değişkenlerde `&` zorunludur.
  - `%d` ile sayı girip Enter'a basınca `\n` girdi tamponunda kalır. Sonraki `%c` bu `\n`'yi okur ve kullanıcıya karakter girme fırsatı vermez. Çözüm: `" %c"` (başta boşluk) ya da hocanın önerdiği `fflush(stdin)`.
  - Her program üç standart akışla başlar: `stdin`, `stdout`, `stderr`.
- Bağlı listelere (linked list) giriş
  - Dizilerde elemanlar bellekte bitişiktir (contiguous). Erişim $O(1)$'dir, ama sıralı diziye eleman eklemek/silmek kaydırma (shift) gerektirir: yer arama $n$ + kaydırma $n$ ≈ $2n$; $n$ eleman eklenirse $O(n^2)$ (ekrandan, 01:25:00).
  - Çok büyük bir dizi için bellekte o kadar bitişik boş yer bulunmayabilir.
  - Bağlı listede her düğüm veri ve sonraki düğümün adresini tutar. Avantajlar: bitişik bellek gerekmez, uzunluk dinamiktir, kaydırma gerekmez. Bedeli: adres için fazladan bellek (trade-off) (ekrandan, 01:35:00).
  - Listeyi gezmek için ilk elemanı (head) bilmek gerekir; son elemanın sonraki adresi NULL'dur (dizi gerçeklemesinde $-1$).
- Dizilerle bağlı liste: `A[]` ve `PO[]`
  - `A[]` elemanları geliş sırasıyla tutar, `PO[i]` A[i]'den sonra gelecek (bir sonraki büyük) elemanın indisini tutar; `PO[0]` liste başıdır (head), sıfırıncı A hücresi boş bırakılır (ekrandan, 02:00:00).
  - Ekleme: yeni eleman `A[i]`'ye yazılır; baştan gezilip ilk büyük eleman bulunur; önceki elemanın `PO` değeri yeni elemana, yeni elemanınki bulunan elemana bağlanır. Kaydırma yoktur.
  - Silme: eleman ve ondan önceki eleman bulunur; öncekinin `PO` değeri silinenin `PO` değeri yapılır. Silinen hücre isteğe bağlı olarak $-2$ ya da 0 ile işaretlenir ($-1$ son eleman demektir).
- `struct` ve işaretçilerle bağlı liste
  - `typedef struct data { int sayi; struct data *next; } DATA;` biçiminde kendi türünden işaretçi tutan yapı tanımlanır (ekrandan, 02:20:00).
  - İşaretçi üzerinden üyeye `->` ile erişilir (`head->sayi`); değişken üzerinden `.` ile (`d1.sayi`).
  - Son elemanın `next`'i NULL yerine ilk elemanın adresi yapılırsa dairesel bağlı liste (circular linked list) olur. Hem `next` hem `prev` tutulursa çift yönlü bağlı liste (doubly linked list) olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ters fonksiyonun varlığı
  - Şifrelenen veriyi geri çözebilmek için fonksiyonun tersi olmalıdır. Afin şifrede $a$ seçilmeden önce mod 26'da tersi olup olmadığı kontrol edilmelidir.
- Frekans analizi
  - Her harfi tek bir sembole eşleyen yöntemler, metin yeterince uzunsa histogram eşleştirmesiyle anahtarsız çözülebilir. Sık harfleri çok hücreye dağıtmak bu saldırıyı zorlaştırır.
- Parola güvenliği
  - E-Devlet, OBS gibi önemli sistemlerin parolalarını başka sitelerde kullanmamak gerekir; açık metin saklayan siteler büyük risk taşır.
- `%c` ve girdi tamponu
  - Önceki girişten kalan Enter, `%c` tarafından karakter olarak okunur; bu hata en çok `%c` ile ve karakter karakter okumada yaşanır.
- Dizi ile bağlı liste arasındaki trade-off
  - Diziler rastgele erişimde hızlıdır, ama ekleme/silmede kaydırma ve bitişik bellek sorunu vardır. Bağlı liste bunları çözer, ama fazladan bellek ister. Sıralı eklemede yeri aramanın $O(n)$ maliyeti iki yapıda da vardır; bağlı liste yalnız kaydırma maliyetini kaldırır.
- `PO[]` dizisini elle doldurma
  - `A[]` elemanları verildiğinde `PO[]` dizisinin, ekleme ya da silme sonrası son halinin bulunması geçmiş yılın sınav sorusu tipidir. En küçükten başlayıp her elemanın bir sonraki büyüğünün indisini yazmak yeterlidir.
- Head'i kaybetmemek
  - Listeyi `head = head->next` ile gezince döngü sonunda `head` NULL olur ve listenin başı kaybolur; başı ayrı bir işaretçide saklamak gerekir.

## Kısa Tekrar Notları

- Kriptoloji = kriptografi (şifreleme) + kriptanaliz (çözme).
- Sezar: $(x + c) \bmod 26$; çözme $(x - c) \bmod 26$, negatifse $+26$.
- Afin: $(a x + c) \bmod 26$; çözme $a^{-1}(x - c) \bmod 26$. Ders sonrası not (derste listelenmedi, python ile kontrol edildi): mod 26'da tersi olan $a$ değerleri 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25 (26 ile aralarında asal olanlar).
- $3^{-1} \equiv 9$, $2$'nin tersi yok.
- C'de `%` işlemi negatif sayıda negatif sonuç verir; mod alırken sonuç negatifse 26 eklenmelidir.
- Tek karşılıklı şifreler frekans analizine açıktır; sık harfleri çok hücreye dağıt.
- Tam kare matrisle yer değiştirme: `MERHABA` → `MHAEARB`.
- Parolalar hash ile saklanır, unutulunca sıfırlanır.
- `%s` boşlukta durur; `%[^\n]` tüm satırı okur.
- `%d` sonrası `%c` önce kalan `\n`'yi okur; `" %c"` kullan.
- Dizi: erişim $O(1)$, sıralı ekleme/silme ≈ $2n$, bitişik bellek gerekir.
- Bağlı liste: veri + sonraki adres; head ile başlanır, NULL ile biter; kaydırma yok, fazladan bellek var.
- `A[]` + `PO[]`: `PO[0]` head, `PO[i]` sonraki elemanın indisi, $-1$ son.
- Dairesel liste: son eleman ilk elemanı gösterir. Çift yönlü liste: `next` + `prev`.

## Detaylı Açıklamalar

- Sezar ve afin şifrenin C ile yazılması
  - Büyük harfli metinde her karakterden 65 (`'A'`) çıkarılarak 0-25 aralığına çekilir, işlem yapılır, mod 26 alınır ve `'A'` eklenerek yeniden harfe dönülür. Ekrandaki şifreleme satırı: `y = ((a*(x-65)+b) % 26)+'A';` (ekrandan, 00:25:00).
  - $a^{-1}$, 0'dan 25'e kadar her $i$ için `(a*i) % 26 == 1` kontrol edilerek bulunur; bulunamazsa fonksiyon $-1$ döndürür ve kullanıcıdan yeni $a$ istenir (`do ... while(inva==-1)`).
  - Metin uzunluğu `while(metin[++uzunluk]!='\0'){ }` ile tek satırda bulunur (ekrandan, 00:25:00).
  - Çözme adımı: önce 65, sonra $b$ çıkarılır, $a^{-1}$ ile çarpılır, mod 26 alınır, 65 eklenir. $x - 65 - b$ negatif olabildiği için C'de `%` sonucu negatif çıkabilir; doğru çalışması için sonuç negatifse 26 eklenmelidir. Bu düzeltmeyle yazılan sürüm `gcc -Wall` ile derlendi: $a = 3$, $b = 3$ için `ABCD` → `DGJM` → `ABCD`, `AZ` → `DA` → `AZ` (düzeltme olmadan `A` geri çözülemez).
- Kelime şifrelemenin C ile yazılması
  - `tamKare` fonksiyonu `while (i*i <= length) i++;` ile karesi uzunluğu aşan ilk $i$'yi bulur (ekrandan, 00:45:00). Uzunluk tam kareyse (ör. 9) bir büyük matris (4×4) seçilir; boş hücreler atlandığı için sonuç yine doğrudur.
  - `sifrele`: `matris[j][i] = clearText[say++]` ile sütun sütun doldurur, kalan hücrelere `'\0'` yazar, sonra `matris[i][j]` ile satır satır okuyup boş olmayanları şifreli metne ekler (ekrandan, 00:45:00).
  - Çözme: önce aynı düzende ilk `length` hücreye yer tutucu (`'0'` karakteri), kalanlara `'\0'` konur; sonra boş olmayan hücrelere şifreli metin satır satır yazılır; en son sütun sütun okunur (ekrandan, 00:50:00). `'0'` karakteri ile `'\0'` farklı şeylerdir.
- Girdi tamponu
  - `65` yazıp Enter'a basınca tampon `6`, `5`, `\n` içerir. `%d` sayıyı alır, `\n` kalır. `%d` beyaz boşlukları atladığı için sonraki `%d` etkilenmez, ama `%c` beyaz boşluğu da karakter sayar ve `\n`'yi alır. Test: `65⏎y⏎` girdisinde `scanf("%c")` 10 (`\n`) okur, `scanf(" %c")` `y` okur.
  - Ders sonrası not: Hoca tamponu temizlemenin "esas" yolunun `fflush(stdin)` olduğunu söyledi. C standardında `fflush` yalnız çıktı akışları için tanımlıdır; `fflush(stdin)` tanımsız davranıştır. Windows'un C kütüphanesinde (derste kullanılan Dev-C++ ortamı) çalışır, Linux/glibc'de güvenilir değildir. Taşınabilir yol `" %c"` ya da `while (getchar() != '\n');` döngüsüdür.
  - Ders sonrası not: Hoca `%s`'nin boşluğu `\0` gibi algıladığını söyledi. Doğrusu: `%s` beyaz boşlukta okumayı durdurur, okuduğu kısmın sonuna `\0` ekler, kalan karakterler tamponda bekler.
- Dizilerle bağlı liste örnekleri
  - Ekrandaki örnek: `A = [_, 2, 5, 4, 8, 1]`, `PO = [5, 3, 4, 2, -1, 1]`. 7 eklenince `A[6] = 7`, `PO[2]` 4'ten 6'ya değişir, `PO[6] = 4` olur (ekrandan, 02:00:00). Sıralı gezinti: 1, 2, 4, 5, 7, 8.
  - Programla gösterilen örnek: elemanlar `1, 5, 9, 3, 4` girilince `PO = [1, 4, 3, -1, 5, 2]` (ekrandan, 02:05:00).
  - Silme örneği: elemanlar `2, 6, 1, 4, 9`, sonra 3 eklenir, 4 silinir. Sonuç: `PO[0] = 3` (1), 1 → indis 1 (2), 2 → indis 6 (3), 3 → indis 2 (6), 6 → indis 5 (9), 9 → $-1$.
  - Ekrandaki `elemanEkle` ve `elemanSil` fonksiyonlarına göre yazılan tam program `gcc -Wall` ile derlendi ve üç örnek de aynı sonucu verdi. Dizi boyutu 10 olduğundan $N \ge 9$ girilirse dizi sınırı aşılır (tanımsız davranış).
- `struct` ile bağlı liste
  - `d1..d4` düğümleri `head = &d2; d2.next = &d1; d1.next = &d4; d4.next = &d3; d3.next = NULL;` ile bağlanır; `while(head != NULL)` döngüsü `2143` yazar (ekrandan, 02:25:00). Döngüden sonra `head` NULL olduğu için ikinci aynı döngü hiçbir şey yazmaz.
  - `d3.next = &d2` yapılıp `head` yeniden `&d2`'ye alınınca liste dairesel olur. Bir tur gezmek için NULL kontrolü yerine "başa dönene kadar" kontrolü yapılır; `do ... while(head != &d2)` kullanılır. Derste son çıktı `2 1 4 3 2` oldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
