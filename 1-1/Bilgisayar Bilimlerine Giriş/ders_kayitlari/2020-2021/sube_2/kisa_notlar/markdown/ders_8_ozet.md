# Ders 8 Çalışma Özeti

## Genel Konular

- Değişkenler ve sabitler
  - Slayttaki tanıma göre değişkenler, bir programda başvurulacak ve değiştirilecek bilgiyi saklamak için kullanılır. Veriyi açıklayıcı bir adla etiketler, programı okuyan için anlaşılır kılar. Değişkeni bilgi tutan bir kap gibi düşünmek faydalıdır; tek amacı veriyi bellekte etiketleyip saklamaktır (ekrandan, 00:20:00).
  - Hoca değişkeni bellekteki bir bölgeyi etiketlemek diye açıkladı: "bu bölgedeki veriyi tamsayı, şu bölgedekini karakter, şunu gerçek sayı (floating point) olarak değerlendiriyorum" demenin yolu. Bu alanlara yeni değer yüklenebildiği için "değişken" denir.
  - Program içinde doğrudan kullanılan sayı ya da karakter bir sabittir. Karakter sabiti tek tırnakla yazılır (`'A'`). `A = 5` atamasında 5 sabit, A değişkendir.
  - Atamada sol taraf (left value, LValue) bir bellek adresi, yani bir değişken ya da adreslenebilir bir alan olmak zorundadır. Sonuç her zaman sola atanır. Sağ taraf right value (RValue) olarak geçer.
- Akış diyagramıyla problem çözme
  - Ders, basit problemlerden başlayıp karmaşıklaştırarak akış diyagramı çizme alıştırmasıdır. Çizimler hocanın tabletinde yapıldı.
  - Kullanılan gösterim (ekrandan): başla/bitir için elips (START, STOP), girdi için sol üst köşesi kesik kutu, işlem için dikdörtgen, karar için iki ucu sivri altıgen (solda F, sağda T dalı), çıktı için alt kenarı dalgalı belge şekli, döngü için `I ← başlangıç || artım` üstte, bitiş değeri altta yazılan for kutusu.
- Örnek 1: üç sayının en küçüğü
  - `a, b, c` okunur. Önce `a < b` sorulur. Doğruysa `a < c` sorulur; doğruysa sonuç `a`, yanlışsa `c`. `a < b` yanlışsa `b < c` sorulur; doğruysa sonuç `b`, yanlışsa `c` (ekrandan, 01:00:00).
  - Her yol tam iki karşılaştırmadan geçer. Eşitlik durumunda (3, 3, 3) akış yine doğru sonucu (3) verir; amaç en küçük değeri bulmaktır, hangi değişkende olduğu değil.
- Analiz (izleme) ile doğrulama
  - Çizilen akış örnek değerlerle adım adım izlenir: (1, 2, 3) için sonuç 1, (3, 3, 3) için 3, (12, 7, 5) için 5 (`c`).
  - Doğru sonuç veren bir örnek algoritmanın doğruluğunu kanıtlamaz; yanlış sonuç veren tek bir örnek ise yanlış olduğunun kesin kanıtıdır.
- Örnek 2: üçgenin türü
  - Kenarlar `a, b, c`. Kural tablosu (ekrandan, 01:05:00): `a = b` ve `a ≠ c` ise ikizkenar; `a = b` ve `b = c` ise eşkenar; `a ≠ b` ve `b ≠ c` ise çeşitkenar.
  - Bir öğrenci çeşitkenar kuralının eksik olduğunu gösterdi: `a ≠ b` ve `b ≠ c` olması `a` ile `c` hakkında bilgi vermez, `a ≠ c` de gerekir. İkizkenarın başka durumları da eklendi: `a = c, b ≠ c` ve `b = c, a ≠ b` (ekrandan, 01:15:00).
  - Matematikteki `a ≠ b ≠ c` yazımı bilgisayarda yoktur. Karşılaştırma işleci iki işlenen alır; koşullar ayrı yazılıp mantıksal olarak bağlanır: ikisi birden gerekiyorsa AND, biri yetiyorsa OR (`a ≠ b AND b ≠ c`).
  - Akış (ekrandan, 01:30:00): `b = a`? T ise `b = c`? (T: eşkenar, F: ikizkenar). F ise `b = c`? (T: ikizkenar), F ise `a = c`? (T: ikizkenar, F: çeşitkenar).
- Akışların verimlilik karşılaştırması
  - Üçgen akışında beş olası yol vardır: üçü 2, ikisi 3 karşılaştırmadan geçer. En iyi durum 2, en kötü 3, kaba ortalama $12/5 = 2{,}4$ karşılaştırmadır (ekrandan, 01:35:00).
  - Bir öğrencinin sayaç yöntemi (her eşit çift için `x`'i bir artırıp sonunda `x`'in değerine bakmak) her durumda 6 kontrol yapar: 3 karşılaştırma ve `x` için 3 kontrol. Bu yüzden verimli değildir.
  - İşlemlerin maliyeti aynı değildir: toplama ve çıkarma hızlıdır, artırma (increment) ve kaydırma (shift) tek adımda yapılabilir; çarpma, bölme ve karşılaştırma daha pahalıdır. Bir sayıyı ikiye bölmek yerine sağa bir kez kaydırmak aynı sonucu verir.
  - `x`'in birkaç değerine bakmak C ya da Java'da `switch` ile, arkada bir karar tablosuyla yapılabilir. Yine de sayaç yöntemi daha pahalıdır.
- Örnek 3: ATM problemi (derste quiz olarak verildi)
  - Banknotlar 200, 100, 50, 20, 10 ve 5 TL. İstenen parayı en az banknotla ödeyen akışı çizmek (ekrandan, 01:40:00).
  - Hocanın beklediği çıktı: örneğin 365 TL için bir 200'lük, bir 100'lük, bir 50'lik, bir 10'luk ve bir 5'lik. Çözüm genel olmalı, belirli bir tutara göre değil.
  - Fikir: tutar en büyük banknota tam bölünerek o banknotun adedi bulunur, kalan (mod) bir sonraki banknotla devam eder. Mod işlemi bölümü değil kalanı verir.
- Döngüler: deterministik ve deterministik olmayan
  - Deterministik döngüde adım sayısı bellidir (ör. on sayının toplamı). Deterministik olmayan döngüde adım sayısı bilinmez, bir koşul sağlanınca durulur (ör. Newton yöntemiyle karekök: iki iterasyon arasındaki fark epsilon'dan küçük olunca durulur).
- Örnek 4: N sayının ortalaması
  - Önce kaç sayı okunacağı (`N`) okunur. Adım sayısı belli olduğu için for döngüsü kullanılır (`I ← 1 || 1`, bitiş `N`). Her adımda yeni bir `X` okunur ve `AVG = AVG + X` ile toplanır. Döngüden sonra `AVG = AVG / N` hesaplanıp yazdırılır (ekrandan, 02:20:00).
  - İlk çizimdeki hata: `AVG` döngüden önce ilklendirilmemiştir. Düzeltilmiş akışta `N` okunduktan sonra `AVG = 0` vardır (ekrandan, 02:25:00).
- Örnek 5: N. Fibonacci sayısı
  - Her sayı kendinden önceki ikisinin toplamıdır: $F_{i+1} = F_i + F_{i-1}$; 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 (ekrandan, 02:30:00).
  - Bir öğrencinin akışı: `N` okunur, `FIRST = 1`, `SEC = 1`; for döngüsü `I ← 3 || 1`, bitiş `N`; gövdede `SEC = FIRST + SEC` ve `FIRST = SEC - FIRST`; döngüden sonra `SEC` yazdırılır (ekrandan, 02:40:00).
  - `N = 8` için izleme tablosu sonucu 21 verir. `N = 1` ya da `N = 2` için döngüye hiç girilmez, sonuç 1 olur; for döngüsünün 3'ten başlatılması bu durumları ayrıca `if` ile kontrol etme ihtiyacını kaldırır.
  - Alternatif yapı üç değişkenle kaydırmadır: `c = b + a`, `a = b`, `b = c`. Toplama-çıkarma çifti yerine atama kullanılır (ekrandan, 02:55:00).
  - Hangisinin daha iyi olduğu mimariye bağlıdır: CISC'te işlenenler yazmaç-yazmaç, yazmaç-bellek, bazen bellek-bellek ya da yazmaç/bellek-sabit (immediate) olabilir; RISC'te işlem yalnız yazmaçlar arasında yapılır, bellekteki veri önce yazmaca yüklenir (load), sonra geri yazılır (store).

## Hocanın Özellikle Vurguladığı Kısımlar

- KISS (Keep It Simple / Keep It Stupidly Simple)
  - Bir çözüm tarif edilirken gereksiz karmaşa yapılmamalı; değişken adlarıyla, adım adım, kural yazar gibi anlatılmalıdır. "Biri, diğeri, öbürü" gibi belirsiz anlatım kabul edilmez.
- Akış analizle doğrulanır
  - "Ben böyle düşünüyorum" bir gerekçe değildir; akış örnek değerlerle izlenip çalıştığı gösterilmelidir. Tek bir doğru örnek yetmez, tek bir yanlış örnek çürütür.
  - Uç durumlar da denenmelidir (bütün sayıların eşit olması, Fibonacci'de `N = 1`).
- Değişken ilklendirme
  - Bir değişken sol tarafta değer almadan sağ tarafta kullanılırsa değeri belirsizdir. Ortalama örneğinde `AVG = 0` atlanırsa sonuç bozulur. Bazı diller bundan etkilenir, bazıları etkilenmez, bazılarında değişkenin nasıl tanımlandığına bağlıdır.
- Genel çözüm
  - Akış belirli bir girdiye göre değil, bütün girdiler için çalışacak şekilde çizilir (ATM'de 300 TL için değil, her tutar için).
- İşlem sırası sonucu değiştirir
  - Fibonacci gövdesinde `FIRST = SEC - FIRST` yerine `FIRST = SEC` yazmak bilgiyi kaybettirir; akış Fibonacci yerine 2'nin kuvvetlerini üretir.
- Problem tanımına güvenmek
  - "Üçgenin kenarları veriliyor" denmişse kenarların üçgen oluşturup oluşturmadığı bu aşamada kontrol edilmez. Gerçek hayatta bu tür hata durumları ayrıca ele alınır.

## Kısa Tekrar Notları

- Değişken: bellekte etiketlenmiş, değeri değiştirilebilen alan. Sabit: doğrudan yazılan değer; karakter sabiti tek tırnakla.
- Atamanın sol tarafı (LValue) adreslenebilir bir alan olmalıdır.
- En küçük sayı: `a < b` → (`a < c` ? a : c), değilse (`b < c` ? b : c). Her yol 2 karşılaştırma.
- Üçgen: eşkenar (üç kenar eşit), ikizkenar (tam iki kenar eşit, üç farklı durum), çeşitkenar (`a ≠ b`, `b ≠ c`, `a ≠ c`).
- `a ≠ b ≠ c` yazılmaz; `a ≠ b AND b ≠ c` yazılır. AND: ikisi birden; OR: biri yeter.
- Üçgen akışı: en iyi 2, en kötü 3, ortalama 2,4 karşılaştırma. Sayaç yöntemi: her durumda 6 kontrol.
- Deterministik döngü: adım sayısı belli (for). Deterministik olmayan: koşula bağlı (Newton yöntemi).
- Ortalama: `N` oku, `AVG = 0`, for `I ← 1 || 1` .. `N`: `X` oku, `AVG = AVG + X`; sonra `AVG = AVG / N`.
- Fibonacci: `FIRST = SEC = 1`, for `I ← 3 || 1` .. `N`: `SEC = FIRST + SEC`, `FIRST = SEC - FIRST`; yaz `SEC`. `N = 8` → 21.
- Alternatif: `c = b + a`, `a = b`, `b = c`.
- CISC: yazmaç ve bellek işlenenleri karışık; RISC: yalnız yazmaç-yazmaç, load/store ile bellek.

## Detaylı Açıklamalar

- **Değişkenin anlamı.** Daha önce harflerin, sayıların ve görüntülerin bilgisayarda nasıl temsil edildiği konuşulmuştu. Bellekteki bitler kendi başına bir anlam taşımaz; değişken, belli bir bellek bölgesine bir ad ve bir yorum (tamsayı, karakter, gerçek sayı) yükler. Böylece "belleğin şurasında şu var" diyebiliriz. Değişkenin içeriği program boyunca değiştirilebilir. Sabit ise programın içine doğrudan yazılmış değerdir. `A = 5` atamasında sağdaki 5 sabit, soldaki `A` değişkendir. Sol taraf mutlaka bir bellek alanı olmalıdır; derleyici hata mesajlarında bu "lvalue" diye geçer.

- **En küçük sayı akışı.** Üç sayıdan ikisi karşılaştırılır; hangi ikisi olduğu önemli değildir, sırayla gitmek için `a` ile `b` seçilir. `a < b` doğruysa `b` elenmiştir, geriye `a` ile `c` kalır; `a < c` sorusu sonucu belirler. `a < b` yanlışsa `b` en az `a` kadar küçüktür, `b < c` sorulur. Eşitlik durumunda soru "3, 3'ten küçük mü?" olur, cevap hayırdır ve akış diğer dala geçer; ama hangi dala gidilirse gidilsin bulunan değer 3'tür. Bu akış python ile 27 farklı girdi üçlüsünde (1, 2, 3 değerlerinin bütün kombinasyonları) denendi ve her durumda `min` ile aynı sonucu verdi.

- **Üçgen akışı ve mantıksal bağlaçlar.** Kural tablosu ilk yazıldığında çeşitkenar için yalnız `a ≠ b` ve `b ≠ c` vardı. Eşitsizlik geçişli değildir: `a = 3, b = 4, c = 3` için iki koşul da sağlanır ama üçgen ikizkenardır. Bu yüzden `a ≠ c` de gerekir. Bilgisayarda karşılaştırma işleci yalnız iki işlenen aldığı için matematikteki zincir yazım kullanılmaz, koşullar AND ile bağlanır. Akış dört karar kutusuyla kurulur ve python ile bütün 27 girdi üçlüsünde doğru türü verdiği kontrol edildi.

- **Karşılaştırma sayısı ve maliyet.** Akıştaki her yol ayrı ayrı sayılır: eşkenar ve iki ikizkenar yolu 2 karşılaştırma, son ikizkenar ve çeşitkenar yolu 3 karşılaştırmadır; ortalama $(2+2+2+3+3)/5 = 2{,}4$. Sayaç yöntemi kâğıt üzerinde basit görünse de her girdide üç eşitlik kontrolü ve sonra `x`'in değeri için üç kontrol yapar. Hoca, toplama ve artırma gibi işlemlerin karşılaştırma ve bölmeden çok daha ucuz olduğunu, bir sayıyı ikiye bölmek yerine sağa kaydırmanın aynı işi çok daha kısa sürede yaptığını anlattı.

> **Ders sonrası not:** Sayaç yönteminde `x` yalnız 0, 1 ya da 3 olabilir; iki eşitlik sağlanırsa üçüncüsü de kendiliğinden sağlanır, bu yüzden `x = 2` hiç oluşmaz (python ile 27 girdide kontrol edildi). Ayrıca hoca karşılaştırmanın toplamadan daha fazla işlemci çevrimi sürdüğünü söyledi; çoğu işlemcide karşılaştırma komutunun kendisi büyük olasılıkla bir çıkarma kadar hızlıdır, `if`'in asıl ek maliyeti koşullu dallanmadan gelir.

- **ATM problemi.** Amaç istenen tutarı en az sayıda banknotla ödemektir. Bir öğrencinin önerdiği fikir: tutar 200'e tam bölünerek 200'lüklerin adedi bulunur, kalan tutar (mod) 100 ile aynı işleme girer ve bu zincir 5'e kadar sürer. Hoca bu problemin akışını derste çizmedi; herkesin üzerinde çalışmasını istedi.

- **N sayının ortalaması.** Kaç sayı okunacağı bilinmediği için önce `N` okunur; bu bilgi klavyeden, dosyadan, hatta bir soketten gelebilir. Adım sayısı belli olduğu için deterministik bir döngü olan for kullanılır. Toplam, okunan sayının kendisi üzerinde değil ayrı bir `AVG` değişkeninde biriktirilir. İlk çizimde `AVG = AVG + X` satırında `AVG` ilk kez sağ tarafta göründüğü için değeri belirsizdi; döngüden önce `AVG = 0` eklenerek düzeltildi.

- **Fibonacci akışının izlenmesi.** `N = 8` için tablo (ekrandan, 02:45:00):

```text
I    FIRST   SEC
-    1       1
3    1       2
4    2       3
5    3       5
6    5       8
7    8       13
8    13      21
9    döngüden çıkılır, SEC = 21 yazdırılır
```

Bu tablo python ile aynı çıktıyı verdi. `SEC = FIRST + SEC` yeni sayıyı bulur, `FIRST = SEC - FIRST` ise bir önceki `SEC` değerini (yani eski ikinci sayıyı) geri elde eder. Bir öğrencinin önerdiği `FIRST = SEC` değişikliği iki değişkene aynı değeri yazar ve dizi 2, 4, 8, 16, ... olur. Üç değişkenli kaydırma yapısı (`c = b + a`, `a = b`, `b = c`) aynı sonucu çıkarmasız verir; python ile ilk 12 terimde iki yapının da aynı diziyi ürettiği kontrol edildi.

- **CISC ve RISC.** Hangi yapının daha hızlı olduğu donanıma bağlıdır. CISC mimarisinde bir toplama komutu yazmaçtaki ve bellekteki işlenenleri doğrudan alabilir; yazması kolaydır ama arka planda daha yavaş çalışır. RISC mimarisinde işlem yalnız yazmaçlar arasındadır: işlenenler bellekten yazmaçlara yüklenir, işlem çok hızlı yapılır, sonuç belleğe geri yazılır. Örneğin amacı bir problemin birden fazla çözümü olabileceğini ve hangisinin daha verimli olduğunun ortama göre değiştiğini göstermektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
