# Ders 10 Çalışma Özeti

## Genel Konular

- Newton formülüyle karekök bulma (tekrar)
  - Bir $x$ sayısının karekökü, başlangıç tahmini $old = 1$ alınarak $new = (old + x/old)/2$ formülünün tekrar tekrar uygulanmasıyla bulunur (ekrandan, 00:35:00).
  - Örnek $x = 1024$: tahminler $512.5 \rightarrow 257.249 \rightarrow 130.xx \rightarrow 69.xx \rightarrow 42.xx \rightarrow 33.xx \rightarrow 32.xx \dots$ diye gider ve $\sqrt{1024} = 32$ değerine yaklaşır (ekrandan, 00:20:00).
  - Her adımda tahminler arasındaki fark küçülür.
- Deterministik döngü ve koşula bağlı döngü
  - Ortalama ($N$ adet sayının ortalaması) ve Fibonacci ($N$. sayı) problemlerinde adım sayısı baştan bellidir; bu yüzden `for` döngüsü kullanılır.
  - Newton yönteminde kaç adım gerekeceği baştan bilinmez; işlem, iki ardışık tahmin arasındaki fark belirli bir $\varepsilon$ değerinin altına inene kadar sürer. Böyle koşula bağlı tekrarlar `while` döngüsüyle kurulur.
- Karekök akışının kurulması
  - Girdiler: karekökü bulunacak sayı ve hassasiyeti belirleyen $\varepsilon$. $\varepsilon$ da dışarıdan okunur, akışa sabit olarak gömülmez.
  - Matematikteki mutlak değer işareti akışta `abs(...)` olarak yazılır.
  - Doğru akış (ekrandan, 01:25:00): `START` → oku `N, ε` → `old = 1`, `new = (old + N/old)/2` → `while abs(new - old) > ε` iken: `old = new`, `new = (old + N/old)/2` → yaz `N, 'karekök', new` → `STOP`.
- İlk taslak akıştaki hatalar (ekrandan, 00:40:00)
  - `new` değişkeni ilk değer verilmeden koşulda kullanılmış.
  - Koşul ters yazılmış: `< ε` değil, `> ε` olduğu sürece devam edilmeli.
  - Çıktıda okunmayan bir `N` değişkeni kullanılmış; okunan değişken `X` idi.
  - Döngü içinde yeni değerin eskisine aktarılması (`old = new`) unutulmuş.
- Akış diyagramının sekiz temel şekli
  - Start, stop, okuma, işlem, while, çıktı, for ve if (ekrandan, 01:30:00).
- Dizi kavramına giriş
  - Tek değişken (x, y) bellekte bir hücreyi temsil eder; adresler derleyici ve işletim sistemi tarafından belirlenir. Hocanın örneğinde 4 baytlık değişkenler için adresler 1000, 1004, 1008, 100C, 1010 diye artar (ekrandan, 01:40:00).
  - Dizi, birbiriyle ilişkili birden çok değeri bellekte ardışık olarak tutan değişken grubudur. `A(N)` gösterimi $N$ elemanlı $A$ dizisini ifade eder (ekrandan, 01:45:00).
  - Bir elemana `A(I)` ile erişilir; bu derste indis 1 ile $N$ arasındadır.
  - Adlandırma alışkanlığı: $N$ adet/boyut, $I, J, K$ döngü değişkeni, $X, Y, Z$ bilinmeyen değerler için kullanılır.
- Dizinin ortalaması akışı (ekrandan, 01:55:00 ve 02:00:00)
  - `N` okunur, `for I ← 1 || 1, N` ile `A(I)` elemanları tek tek okunur.
  - `ORT = 0` ilk değeri verilir, ikinci bir `for` ile `ORT = ORT + A(I)` toplanır, sonra `ORT = ORT/N` yapılıp yazdırılır.
  - Sayfa sınırı yüzünden kesilen akış içine numara yazılan bağlantı daireleriyle birleştirilir.
- Kısaltılmış dizi okuma gösterimi (ekrandan, 02:10:00)
  - Okuma kutusunda önce `N`, sonra `A(N)` yazılırsa "N okundu, sonra A dizisinin N elemanı okundu" anlamına gelir. Bu kural yalnız okuma kutusunda geçerlidir; işlem kutusunda `A(N)` dizinin $N$. elemanıdır.
- Diziyi ters çevirme problemi
  - Örnek dizi: 7, 11, 44, 53, 67, 87 → 87, 67, 53, 44, 11, 7.
  - İki değerin yeri doğrudan atamayla değiştirilemez; geçici bir değişken (`TMP`) gerekir (ekrandan, 02:20:00).
  - Değiştirme işlemi $N$ adım yapılırsa dizi başa döner; yalnız dizinin yarısı kadar adım yapılmalıdır: $N = 6$ için 3, $N = 7$ için de 3 adım (ekrandan, 02:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir değişken, ilk değeri verilmeden ya da okunmadan bir işlemin sağ tarafında kullanılamaz.
  - Değeri bilinmeyen değişkenle her türlü yanlış sonuç çıkabilir; `new` ve `ORT` örneklerinde bu hata yapıldı.
- Akış diyagramında derste anlatılan gösterim esastır.
  - Farklı mühendislik alanlarında ve farklı kaynaklarda başka çizim gelenekleri vardır; internetten başka gösterimlere bakmak kafa karıştırır.
  - Öğrenilecek şekil sayısı yalnız sekizdir; while ile if karıştırılmamalıdır.
- `repeat until` yapısı kullanılmaz.
  - `repeat until` ile yapılabilen her şey `while` ile yapılabilir.
- C'de `goto`, `continue` ve `break` ileride anlatılacak ama kullanılmayacak.
  - Hocaya göre bunlar Assembly geleneğinden C'ye taşınmış, optimizasyonu bozan ifadelerdir; işlemcinin pipeline yapısının verimli çalışmasını engeller.
- Okuma (G/Ç) ile hesaplama aynı döngüde birleştirilmemelidir.
  - Okuma bir dosyadan ya da porttan da olabilir; her G/Ç işleminde süreç bekleme kuyruğuna alınır, işlemci el değiştirir. Bu ikisini aynı döngüye koymak optimizasyon sanılır ama işletim sistemi açısından gereksiz yük oluşturur.
- Her akışın yanında adım adım analiz (izleme tablosu) yapılmalıdır.
  - Değişkenlerin her adımdaki değeri yazılarak akışın çalışıp çalışmadığı görülür.
- Dizinin boyutunu tutan $N$ değişkeni döngü sayacı olarak değiştirilmemelidir; bunun için ayrı bir indis ($I$, $J$) kullanılır.

## Kısa Tekrar Notları

- Newton karekök: $old = 1$, $new = (old + x/old)/2$; fark $\varepsilon$'dan büyük olduğu sürece tekrar.
- Adım sayısı belli → `for`; koşula bağlı → `while`.
- Koşul: `abs(new - old) > ε` iken devam.
- Mutlak değer gerekir, çünkü ilk adımdan sonra tahminler azaldığından $new - old$ negatiftir.
- Döngüye girmeden önce `new` bir kez hesaplanır; döngüde önce `old = new`, sonra yeni `new` hesaplanır.
- `new` için 1 ilk değeri verilemez: `old = 1` iken fark 0 olur ve döngüye hiç girilmez.
- Çıktı kutusunda tırnak içindeki ifade sabit metindir, tırnaksız yazılan değişkendir.
- Dizi: bellekte ardışık hücreler; `A(I)`, $1 \le I \le N$.
- `for I ← 1 || 1, N`: başlangıç 1, artış 1, son değer $N$; döngüden çıkışta $I = N+1$.
- Toplam/ortalama değişkeni döngüden önce sıfırlanır.
- Yer değiştirme: `TMP = A(1)`, `A(1) = A(6)`, `A(6) = TMP`.
- Ters çevirmede yarı adım yeterlidir; tam $N$ adım diziyi eski haline getirir.

## Detaylı Açıklamalar

- **Newton yöntemi ve durma koşulu.** Hoca önce iki hafta önce anlatılan Newton formülünü hatırlattı. $x = 1024$ için ilk tahmin $old = 1$ ile $new = (1 + 1024/1)/2 = 512.5$ bulunur. Sonra bu değer eski değer olur: $(512.5 + 1024/512.5)/2 = (512.5 + 1.998)/2 = 257.249$ (ekrandan, 00:35:00). Bu böyle sürdükçe tahminler 130, 69, 42, 33 civarından geçerek 32'ye yaklaşır. Ortalama ve Fibonacci örneklerinde adım sayısı belli olduğu için `for` kullanılmıştı; burada ise iki tahmin arasındaki fark (ilk adımlarda 255, 127, 61 gibi) kabul edilebilir bir değerin, örneğin $0.001$'in altına inene kadar devam edilir. Bu yüzden döngü `while` olur. $\varepsilon$ hassasiyeti temsil eder ve parametre olarak dışarıdan okunmalıdır.
- **Taslak akış ve hataları.** Hoca tahtaya bilerek hatalı bir akış çizdi (ekrandan, 00:30:00): `X, ε` okunuyor, `old = 1` atanıyor, `abs(new - old) < ε` koşulunda `new = (old + X/old)/2` hesaplanıyor ve çıktıda `N, 'karekökü', new` yazılıyor. Öğrencilerle birlikte dört hata bulundu: `new` ilk değersiz kullanılıyor; koşul ters (fark $\varepsilon$'dan küçükse zaten istenen sağlanmıştır, çıkılmalıdır); çıktıdaki `N` hiçbir yerden gelmiyor, `X` olmalı; döngüde `old = new` aktarması yok (ekrandan, 00:40:00).
- **`new` için ilk değer tartışması.** Bir öğrenci `new` için 0 ya da 1 verilebileceğini önerdi. Hoca 1 verilirse $old = 1$ ile fark 0 olacağından döngüden hemen çıkılacağını, 0 (ya da 0.5) verilirse farkın 1 civarında kalacağını ve kullanıcının $\varepsilon$ olarak 1 girmesi hâlinde akışın yine bozulacağını gösterdi. Makul çözüm, `old = 1` atamasından hemen sonra formülü bir kez uygulayarak `new` değerini hesaplamaktır.
- **Doğru akış.** Ortak çizimle şu akış kuruldu (ekrandan, 01:25:00):

```text
START
  -> OKU: N, ε
  -> İŞLEM: old = 1
            new = (old + N/old)/2
  -> WHILE abs(new - old) > ε
       doğru kolu: İŞLEM: old = new
                          new = (old + N/old)/2
                   (koşula geri dön)
  -> ÇIKTI: N, 'karekök', new
  -> STOP
```

- **Neden mutlak değer?** İlk adımda $512.5 - 1$ pozitiftir, ama sonraki adımlarda tahminler küçüldüğü için $257.249 - 512.5$ gibi farklar negatiftir. $\varepsilon$ pozitif bir sayı olduğundan farkın mutlak değeri karşılaştırılır.
- **`while` yerine `if` ile geri dönüş.** Bir öğrenci koşulu `if` ile yazıp doğru kolunu yukarı bağlamayı önerdi. Hoca bunun `if` değil `repeat until` olduğunu, `repeat until` kullanılmadığını ve onunla yapılan her şeyin `while` ile yapılabileceğini söyledi.
- **Çıktı kutusunda sabit ve değişken.** `N, 'karekök', new` yazımında `N` ve `new` değişkendir; tırnak içindeki `'karekök'` ekrana olduğu gibi yazılacak sabit metindir. Sabit bir sayı da (hocanın örneği 1453) çıktıya yazılabilir.
- **Bellek ve dizi.** Tek değişkenler bellekte bağımsız hücrelerdir; adresler hocanın uydurduğu 1000, 1004, 1008, 100C, 1010 değerleriyle 4 baytlık hücreler olarak gösterildi. Dizi ise aynı ad altında ardışık hücrelerden oluşan bir gruptur; boyutu ($N$) bilinmelidir.
- **Dizi ortalaması.** Akışta `N` okunur, ilk `for` ile elemanlar okunur, ikinci `for` ile toplanır, toplam $N$'ye bölünür (ekrandan, 01:55:00). Öğrencilerin atladığı nokta `ORT = 0` ilk değeridir (ekrandan, 02:00:00). Bir öğrencinin "okuma ve toplama tek `for` içinde yapılamaz mı?" sorusuna hoca hayır dedi: çizimde mümkün olsa da okuma bir G/Ç işlemidir ve hesaplamayla iç içe koymak süreçlerin işlemci ile G/Ç arasında sürekli yer değiştirmesine yol açar.
- **Diziyi ters çevirme.** Bir öğrenci iç içe iki `for` önerdi: `I ← 1 || 1, N` ve içte `J ← N || -1, 1` ile `A(I) = A(J)` (ekrandan, 02:15:00). Hoca 7, 11, 44, 53, 67, 87 ile izleyip bunun çalışmadığını gösterdi: değerler birbirinin üzerine yazılıyor ve sonunda baştaki elemana 11 geliyor. Doğru yol için iki kural verildi: yer değiştirmede `TMP` kullanılmalı, değiştirme sayısı dizinin yarısı kadar olmalı. Problemin akışı sonraki derse bırakıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
