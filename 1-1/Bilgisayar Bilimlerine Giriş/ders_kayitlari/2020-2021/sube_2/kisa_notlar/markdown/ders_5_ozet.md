# Ders 5 Çalışma Özeti

## Genel Konular

- Aritmetik operatörler
  - Akış diyagramlarında herkesin aynı şeyi anlaması için işlemler sabit işaretlerle yazılır: toplama `+`, çıkarma `-`, çarpma `*`, bölme `/`, mod `mod` (ekrandan, 00:05:00).
  - Mod, bölmeden kalanı verir: 7 mod 2 = 1.
- İlişkisel operatörler
  - İki operand arasındaki durumu belirler: büyük, küçük, büyük eşit, küçük eşit, eşit, eşit değil.
  - Klavyede $\geq$ ve $\leq$ işareti olmadığı için büyük eşit `>=`, küçük eşit `<=` diye yazılır. Önce büyük/küçük, sonra eşit işareti gelir; `=>` ya da `=<` diye bir yazım yoktur.
  - Eşitlik `=` ile, eşit değil üzeri eğik çizgili eşit işaretiyle ($\neq$) gösterilir.
  <!-- BELİRSİZ: İlişkisel operatör slaytı karelerde yok; işaretler altyazıdaki anlatımdan alındı. -->
- Mantıksal operatörler
  - Üç temel mantıksal operatör vardır: AND (ve), OR (veya), NOT (negation, değil) (ekrandan, 00:10:00).
  - AND iki koşulun birlikte sağlanmasını ister: $x > -1$ AND $x < 5$ koşulu $x = 6$ için sağlanmaz, çünkü ikinci koşul tutmaz.
  - OR koşullardan birinin sağlanmasını yeterli sayar: $x < -1$ OR $x > 5$ koşulu $x = 6$ için sağlanır.
  - NOT aranan koşulun tersine bakar.
- Bit bazında (bitwise) operatörler
  - İki sayının karşılıklı bitlerine tek tek uygulanır. En sağdaki bit LSB (least significant bit, en düşük değerli), en soldaki MSB (most significant bit, en yüksek değerli) bittir.
  - Örnek sayılar: $A = 60 =$ `0011 1100`, $B = 13 =$ `0000 1101` (ekrandan, 00:15:00).
  - AND: iki bit de 1 ise 1. $A \,\&\, B =$ `0000 1100` (12).
  - OR: bitlerden biri 1 ise 1. $A \,|\, B =$ `0011 1101` = 61 (ekrandan, 00:20:00).
  - XOR: bitler aynıysa 0, farklıysa 1. $A$ XOR $B =$ `0011 0001` (ekrandan, 00:25:00).
  - Shift (kaydırma): bitler belirtilen yönde kaydırılır. Taşan bit kaybolur, boşalan yere her zaman 0 gelir. $A \ll 2 = 240 =$ `1111 0000`, $A \gg 3 = 7 =$ `0000 0111` (ekrandan, 00:40:00).
  - Rotate (döndürme): sağa döndürmede en sağdan çıkan bit, kaybolmak yerine en sola (MSB) yerleşir. Slayttaki 16 bitlik örnekte `0101...0101` sağa döndürülünce `1010...1010` olur (ekrandan, 00:35:00).
- Bilgisayar neden ikilik sistem kullanır?
  - Bilgisayar elektrik sinyalleriyle çalışır. Sinyal gürültü ve parazit yüzünden hiçbir zaman tam düz değildir.
  - Slayttaki örnekte 0,0–0,5 V aralığı 0, 2,8–3,3 V aralığı 1 kabul edilir; aradaki bölge emniyet bandıdır (ekrandan, 00:45:00).
  - Aynı 3,3 V içine on seviye konsaydı her seviyeye en fazla 0,33 V kalırdı; bu, emniyet bandından bile dardır ve hata iki yönden de olabilir.
  - Gerilim aralığını büyütmek (örneğin 12 V) güvenliği artırır ama seviye geçişleri yavaşlar ve geçiş süreleri eşit olmaz. Bu yüzden ikilik sistem hem gürültüye dayanıklı hem hızlıdır; gerilimler zamanla 12 V'tan 5, 3,3, 1,8 ve 1,2 V'a inmiştir.
  - ENIAC ondalık sistemi kullanıyordu; slayta göre ondalık sistemde toplama, çarpma gibi işlemler de zorlaşır.
- Bilginin eşlenmesi (mapping)
  - Bellekte yalnız 0 ve 1 vardır; harf, sayı, resim gibi her veri tipi için bir eşleme gerekir. Aynı veri tipi için farklı eşlemeler olabilir: ASCII, EBCDIC, UTF (ekrandan, 00:50:00).
  - ASCII tablosunda `A` = 65, `Z` = 90, `a` = 97, `0` karakteri = 48, `9` = 57. 0–31 arası kontrol karakterleridir (start of heading, start of text, end of text, end of transmission, acknowledgement vb.); eski metin tabanlı seri haberleşmede kullanılırdı.
  - ASCII İngiliz alfabesini kapsar; Türkçe karakterleri içermez. Günümüzde UTF-8 kullanıldığı için karakter karmaşası yaşanmaz.
- Negatif sayılar
  - Bire göre tümleyen (1's complement): MSB işaret bitidir (0 pozitif, 1 negatif); sayının bütün bitleri ters çevrilir. $11 =$ `0000 1011`, $-11 =$ `1111 0100` (ekrandan, 00:55:00).
  - Bire göre tümleyende sıfırın iki gösterimi vardır. İkiye göre tümleyende (2's complement) bu sorun yoktur: önce bire göre tümleyen alınır, sonra 1 eklenir. Günümüzde ikiye göre tümleyen kullanılır.
- Kesirli sayılar (IEEE kayan nokta)
  - IEEE standardı 32 ya da 64 bitlik alanı üç parçaya böler: en solda işaret biti (0 pozitif, 1 negatif), sonra üs (exponent), sonra mantis (mantissa).
  - Mantis bitlerinin ağırlıkları $2^{-1}, 2^{-2}, 2^{-3}, \dots$ yani $1/2, 1/4, 1/8, 1/16, \dots$ biçiminde gider.
  <!-- BELİRSİZ: Kayan nokta slaytı karelerde yok; parça sırası ve bit sayıları altyazıdan alındı. Hocanın "üs tam kısmı, mantis kesir kısmı gösterir" anlatımı için Detaylı Açıklamalar'daki ders sonrası nota bakın. -->
- Bit, nibble, byte, word
  - 4 bit = nibble, 8 bit = byte, 16 bit = word, 32 bit = long word, 64 bit = very long word (ekrandan, 01:15:00).
- Bellek organizasyonu ve endian
  - Bellek byte'lardan oluşur. Mimari kaç bitse doğal olarak o kadar bitle çalışır.
  - Bir byte'tan uzun verinin belleğe yerleşimi için iki yöntem vardır. `0x0001020304050607` örneğinde big endian'da en düşük adrese (a) en yüksek anlamlı byte `00`, little endian'da en düşük adrese en düşük anlamlı byte `07` yazılır (ekrandan, 01:20:00).
  - Intel mimarisi little endian, PowerPC big endian kullanır. Ağ üzerinden veri gönderirken veri ağın düzenine çevrilir, alınca da yerel düzene geri çevrilir.
- Algoritma
  - Algoritma, bir işi yapmak için adım adım yapılacakları tarif eden yapıdır. Kökü Harezmî'ye dayanır. Günlük hayattaki en iyi örneği yemek tarifidir.
  - Slayttaki tanım: algoritma iyi tanımlanmış, belirsizlik içermeyen komutlar dizisidir; sonlanmalı ve bir sonuç üretmelidir; iyi tanımlanmış bir "komut diline" dayanır (ekrandan, 01:25:00).
  - Algoritma programlama diline bağlı değildir. Programcının işi, problemin çözümünü bilgisayarın anlayacağı biçimde ifade etmektir.
  - Elle toplama örneği (123456 + 789001 = 912457) tarif edilirken uç durumlar (en soldaki basamak) ve genellik (iki sayıdan fazlası) gözden kaçabilir.
- Algoritma tasarımı ve analizi
  - George Polya'nın problem çözmede dört adımı: problemi anla, plan yap, planı uygula, çözümü incele (ekrandan, 01:40:00).
  - Örnek: bir oda dolusu insan içinde en yaşlıyı bulmak. Varsayımlar: herkes gerçek doğum gününü söyler, aynı gün doğanlar aynı yaştadır, birden fazla en yaşlı varsa biri yeterlidir.
  - Birinci tasarım (sıralı): bir kâğıt elden ele dolaşır; daha yaşlı olan önceki adı çizip kendi adını yazar. $n$ kişi için $n$ adım gerekir.
  - İkinci tasarım (paralel): herkes eşiyle karşılaştırır, kalanlar yeniden eşleşir. Her adımda aday sayısı yarıya iner; adım sayısı $\log_2 n$ civarındadır (100 kişi için 7 adım).
  - Karmaşıklık iki türlüdür: işlem (zaman) karmaşıklığı ve alan karmaşıklığı. Big O gibi gösterimler veri yapıları ve algoritmalar dersinde görülür.
- Arama algoritmaları
  - Sıralı arama (sequential search): liste baştan sona tek tek incelenir. Aranan varsa bulunacağı garantidir, ama çok büyük veritabanlarında pratik değildir. En kötü durumda (worst case) bütün listeye bakılır (ekrandan, 01:50:00).
  - İkili arama (binary search): yalnız sıralı veride kullanılır. Telefon rehberinde ortadan açmak gibi her adımda arama alanının yarısı elenir; 500.000 kayıtta iki adımda 375.000 kayıt elenir.
- Newton'un karekök algoritması
  - Başlangıç tahmini 1'dir; tahmin yeterince yakın olana kadar şu formül tekrarlanır (ekrandan, 01:55:00):
    - $\text{yeni} = \dfrac{\text{eski} + N/\text{eski}}{2}$
  - Durma koşulu: ardışık iki tahmin arasındaki fark bir $\varepsilon$ değerinden küçük olunca durulur. $N = 1024$ için tahminler 512,5; 257,249...; 130,6...; 69,2...; 42,0...; 33,19...; 32,021...; 32,0000071...; 32,0000000000008; 32 diye gider.
- Akış diyagramları
  - Başla/Bitir (Start/Stop) elips içinde yazılır. Her akışın tek bir başlangıcı ve tek bir bitişi olur. Start ile Stop, Begin ile End eşleşir.
  - Girdi (input) kutusu sol üst köşesi kesik dikdörtgendir (delikli karta benzer). Değişkenler virgülle ayrılır; dizi okunacaksa önce eleman sayısı N, sonra `A(N)` yazılır (ekrandan, 02:05:00).
  - Oklar akış yönünü gösterir ve düz ya da dik açılı çizilir; eğri ok kabul edilmez. Sayfa yetmezse numaralı daireler (bağlantı noktası) kullanılır, ama az olmalıdır (ekrandan, 02:10:00).
  - İşlem kutusu dikdörtgendir (örn. `A = A + 1`). Bütün kutulara üstten girilir, alttan çıkılır. İfadeler programlama dilinden bağımsız, dersin başındaki operatörlerle yazılır.
  - IF altıgen içinde yazılır; T ve F kolları mutlaka etiketlenir ve iki kol bir noktada birleşir. Her IF'in True kolu olmalıdır, False kolu isteğe bağlıdır (ekrandan, 02:15:00).
  - FOR döngüsü kutusunda başlangıç değeri (`J ← 1`), artım (`1`) ve son değer (`N`) yazılır (ekrandan, 02:20:00).
  - WHILE döngüsü koşula göre tekrar eder; döngü içinde koşuldaki değişkeni değiştiren bir işlem olmalıdır, yoksa döngüden çıkılamaz.
- Sözde kod (pseudocode)
  - Algoritmayı insanın okuyabileceği yönergeler ile programlama komutlarını karıştırarak ifade etmenin başka bir yoludur. Kesin bir standardı yoktur; girdiler ve çıktılar tanımlanmalı, satırları numaralamak iyi bir fikirdir (ekrandan, 02:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Operatörlerin standart yazımı
  - Akışlarda tuhaf semboller kullanılmamalı; herkes aynı işaretleri kullanmalıdır. Büyük eşit `>=` yazılır, `=>` yazılmaz.
- İkilik sistemde düşünme refleksi
  - `0011 1100` OR `0000 1101` işleminde iki sayı yalnız en sağdaki bitte farklıdır; sonuç hemen 60 + 1 = 61 diye görülebilmelidir. Rastgele sayılar seçip onaltılık ve ikilik sistemler arasında çevirerek pratik yapılmalıdır.
  - Ondalık düşünüp ikilik sonuç üretmeye çalışmak, İngilizce soruyu önce Türkçeye çevirip cevaplamak gibidir; ikilik sistemde doğrudan düşünmek öğrenilmelidir.
- Shift sınırı
  - Sayı 8 bit diye tanımlandıysa 9. bit yoktur; taşan bit kaybolur. Boşalan yere her zaman 0 gelir ("uzay boşluğu" teknik terim değildir, hocanın benzetmesidir).
  - Sola kaydırma 2 ile çarpma, sağa kaydırma 2'ye tam sayı bölmedir.
- İkilik sistemin nedeni
  - Gürültüye karşı dayanıklılık, hız ve basitlik. Hoca bunun akılda kalmasını istedi.
- Algoritma tarifinde netlik
  - Bilgisayara "sırala" gibi tarif edilmemiş bir adım verilemez. Tarif uç durumları ve genel durumu kapsamalıdır.
  - Soruya odaklanmak gerekir: "en yaşlı ya da en genç" sorusunda ikisini birden bulmaya çalışmak problemi gereksiz yere karmaşıklaştırır. İşin zorluğu ile yöntemin karmaşıklığı orantılı olmalıdır.
- Akış diyagramı kuralları
  - Her akış tek noktada bitmelidir. Oklar düz ya da dik açılı olmalıdır; eğri oklu akış kabul edilmez.
  - IF'in iki kolu birleşmelidir. İki kolda aynı işlem yapılıyorsa koşul gereksizdir (temel mantık hatası).
  - True kolu boş bırakılıp iş False koluna konmamalıdır; koşul ters çevrilip iş True koluna konmalıdır.
  - Bu derste kullanılacak semboller hocanın gösterdiği sembollerdir; diğer mühendislik alanlarındaki farklı semboller kullanılmamalıdır.

## Kısa Tekrar Notları

- Aritmetik: `+ - * / mod`. İlişkisel: `> < >= <= =` ve $\neq$. Mantıksal: AND, OR, NOT.
- 60 = `0011 1100`, 13 = `0000 1101`. AND = `0000 1100`, OR = `0011 1101` (61), XOR = `0011 0001`.
- $60 \ll 1 = 120$, $60 \ll 2 = 240$; $60 \gg 1 = 30$, $60 \gg 2 = 15$, $60 \gg 3 = 7$.
- Rotate: dışarı çıkan bit öbür uca girer.
- İkilik sistem: güvenli gerilim bantları, gürültüye dayanıklılık, hız.
- ASCII: A = 65, a = 97, '0' = 48; 0–31 kontrol karakterleri.
- 1's complement: bitleri ters çevir, sıfırın iki gösterimi olur. 2's complement: 1's complement + 1.
- IEEE kayan nokta: işaret + üs + mantis.
- Nibble 4, byte 8, word 16, long word 32, very long word 64 bit.
- Little endian: en düşük adrese en düşük anlamlı byte (Intel). Big endian: en düşük adrese en yüksek anlamlı byte (PowerPC).
- Polya: anla, planla, uygula, incele.
- Sıralı arama $n$ adım; ikili arama sıralı veri ister, $\log_2 n$ adım.
- Newton: $\text{yeni} = (\text{eski} + N/\text{eski})/2$, başlangıç 1, fark $< \varepsilon$ olunca dur.
- Akış: elips Start/Stop, köşesi kesik girdi kutusu, dikdörtgen işlem, altıgen IF (T/F etiketli, kollar birleşir), FOR kutusu (başlangıç, artım, son), WHILE, numaralı daire bağlantılar.

## Detaylı Açıklamalar

- **Bitwise işlemler.** Bitwise operatörler sayıyı bir bütün olarak değil, karşılıklı bitler halinde işler. 60 ile 13 AND'lenince sağdan başlayarak 0·1 = 0, 0·0 = 0, 1·1 = 1, 1·1 = 1, kalan bitler 0 olur ve sonuç `0000 1100` çıkar. OR'da tek fark en sağdaki bittir; 60 olan sayı 61 olur. XOR'da aynı bitler 0, farklı bitler 1 verir; hoca XOR'u "1'lerin sayısını çifte tamamlayan bit" diye de anlattı ve simetrik şifrelemede ve bilgisayar ağlarında çok kullanıldığını söyledi. Shift'te taşan bit kaybolur, boşalan yere 0 gelir. Bu yüzden sola kaydırma 2 ile çarpmadır (60 → 120 → 240), sağa kaydırma ise 2'ye tam sayı bölmedir (60 → 30 → 15 → 7; 7,5 olamaz, çünkü bitlerde kesir yoktur). 8 bitlik sayıda üç kez sola kaydırmada en soldaki 1 kaybolur: `1110 0000`. Rotate'te çıkan bit kaybolmaz, öbür uçtan geri girer; hoca bu operatörün daha çok assembly programlamada kullanılacağını söyledi.
- **Gerilim seviyeleri.** Slayttaki grafikte 0 için 0,0–0,5 V, 1 için 2,8–3,3 V kabul edilir. Sinyal elektromanyetik etkiler ve iletim yolunun durumu yüzünden hep biraz dalgalıdır, ama bantların içinde kaldıkça doğru okunur. Ondalık sistemde aynı aralığa on seviye sığdırmak her seviyeyi yaklaşık 0,33 V'a indirir; altıyı göndermek isterken sinyal biraz düşerse beş, biraz yükselirse yedi okunur. İkilik sistemde 0 en kötü ihtimalle 1, 1 en kötü ihtimalle 0 olur; başka değer yoktur. Seviye sayısı arttıkça geçiş süreleri de eşit olmaz ve senkronizasyon kayar.
- **Negatif sayılar.** Bire göre tümleyende 11 (`0000 1011`) sayısının bütün bitleri ters çevrilerek $-11$ (`1111 0100`) bulunur. Bu yöntemde hem `0000 0000` hem `1111 1111` sıfırı gösterir; bu tutarsızlıktır. İkiye göre tümleyende bire göre tümleyene 1 eklenir ve sıfırın tek gösterimi kalır.
  - **Ders sonrası not:** Hoca $-11$'i sesli okurken "1111100" dedi; slayttaki doğru değer `1111 0100`'dür.
  - **Ders sonrası not:** Hoca kayan nokta sayılarda üssün "sayının tam kısmını", mantisin "kesirli kısmını" gösterdiğini söyledi. IEEE 754'te üs, sayının 2'nin hangi kuvvetiyle ölçekleneceğini gösterir; mantis ise sayının anlamlı basamaklarını (significand) tutar. Tam ve kesir kısmı doğrudan bu iki alana ayrılmaz. Hoca mantis ağırlıklarını önce $1/2, 1/4, 1/8, 1/16$ diye doğru okudu, sonra "$2^{-1}, 2^{-2}, 2^{-4}, 2^{-8}$" dedi; doğrusu $2^{-1}, 2^{-2}, 2^{-3}, 2^{-4}$'tür.
  - **Ders sonrası not:** Hoca ASCII'nin 8 bitlik olduğunu ve tablonun 256'ya kadar gittiğini söyledi. Standart ASCII 7 bittir (0–127); 8 bitlik genişletilmiş tablolar 0–255 arasındadır. Hoca UTF-8 için "iki byte'lık" dedi; UTF-8 karakter başına 1 ile 4 byte arasında değişen uzunlukta bir kodlamadır.
- **Bellek ve endian.** Hoca 8 bitlik mimaride adreslerin 0, 1, 2, ..., 16 bitlikte 0, 2, 4, ..., 32 bitlikte 0, 4, 8, ... diye gittiğini anlattı. Little endian'da `0x0001020304050607` sayısının `07` byte'ı a adresine, `06` a+1'e yazılır ve böyle devam eder; big endian'da a adresine `00` yazılır.
  - **Ders sonrası not:** Günümüz mimarilerinin çoğu byte adreslemelidir; her byte'ın kendi adresi vardır. Hocanın anlattığı 0, 2, 4 ya da 0, 4, 8 sırası, word ya da long word boyutunda hizalı erişimlerin adresleri olarak düşünülmelidir.
  - **Ders sonrası not:** Slayttaki little endian tablosunda `03` iki kez yazılmış, `00` yok. Doğru sıra a'dan a+7'ye `07 06 05 04 03 02 01 00`'dır.
- **Algoritma tarifinde uç durum.** Elle toplama yöntemini tarif eden bir öğrenci birler basamağını toplayıp 10'dan büyükse eldeyi bir sonraki basamağa aktarmayı anlattı. Hoca iki eksik gösterdi: en soldaki basamakta elde varsa ne yapılacağı (uç durum) atlanmıştı, tarif de yalnız iki sayının toplamında çalışıyordu (elde en fazla 1 kabul edilmişti). İyi bir algoritma anlaşılır olmalı, uç durumlarda da çalışmalı ve genel olmalıdır.
- **En yaşlıyı bulma.** Sıralı tasarımda kâğıt herkesin elinden geçtiği için $n$ kişide $n$ adım gerekir. Paralel tasarımda her sırada kişiler kendi aralarında en yaşlıyı bulur, sonra kalanlar karşılaştırılır; her adımda aday sayısı yarıya iner. 100 kişilik sınıfta 128'e yuvarlayınca yaklaşık 7 adım yeter. Bu fark algoritmanın işlem karmaşıklığıdır: sıralı çözüm $n$, paralel çözüm $\log_2 n$ mertebesindedir.
- **Arama.** Sıralı aramada aranan kayıt (örneğin bir kimlik numarası) bulunana ya da liste bitene kadar devam edilir. Kayıt listede yoksa bunu anlamak için bütün liste taranır; bu en kötü durumdur. İkili aramada veri sıralı olmalıdır. Rehberde ortadan açılıp aranan harfin hangi yarıda olduğuna bakılır ve diğer yarı elenir.
- **Newton yöntemi.** $N = 1024$ için ilk adım $(1 + 1024/1)/2 = 512{,}5$, ikinci adım $(512{,}5 + 1024/512{,}5)/2 \approx 257{,}249$'dur. Her adımda yeni tahminle eski tahmin arasındaki farka bakılır; ilk adımlarda fark çok büyüktür (yaklaşık 511, 255, 127). $\varepsilon$ ne kadar küçük seçilirse sonuç o kadar hassas olur.
  - **Ders sonrası not:** Slaytta üçüncü tahmin `130.16480157022683` yazıyor; python ile hesaplanan değer `130.61480157022683`'tür (iki rakamın yeri değişmiş). Diğer değerler doğrudur.
  - **Ders sonrası not:** Hoca $\varepsilon = 0{,}01$ ile sonucun 32,0000071... civarında kalacağını söyledi. "Yeni ile eski arasındaki fark $< \varepsilon$ olunca dur" kuralıyla 32,0214 → 32,0000071648 adımındaki fark (0,0214) hâlâ 0,01'den büyüktür; algoritma bir adım daha gider ve 32,0000000000008'de durur (python ile kontrol edildi).
- **Akış diyagramlarında IF.** Slayttaki örnekte A = B koşulunun hem T hem F kolunda `A = A + 1` vardır. Hoca bunun bilerek konduğunu söyledi: iki kolda aynı iş yapılıyorsa koşul gereksizdir. İç içe IF'te önce içteki IF'in kolları birleştirilir, sonra bu birleşme noktası dıştaki IF'in diğer koluyla birleştirilir.
- **FOR ve WHILE.** FOR kutusunda `J ← 1` başlangıç, çift çizgiyle ayrılmış `1` artım, alttaki `N` son değerdir. J = 1 ile başlanır, gövde (`A = A + 1`) çalışır, J bir artar; J, N'yi geçince döngüden çıkılır, yani gövde $N$ kez çalışır. Kaç adım gideceği belli olan işlerde (10 elemanın ortalaması gibi) FOR kullanılır. Koşula bağlı tekrarda WHILE kullanılır; gövdede koşul değişkenini değiştiren bir işlem yoksa döngü sonsuza kadar sürer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
