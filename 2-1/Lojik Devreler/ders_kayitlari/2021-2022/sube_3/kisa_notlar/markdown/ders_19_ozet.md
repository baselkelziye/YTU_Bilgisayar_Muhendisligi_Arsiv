# Ders 19 Çalışma Özeti

## Genel Konular

- Kombinezonsal tümleşik devrelere giriş (MSI devreler)
  - Belirli bir işi yapan kombinezonsal devreler, yazılımdaki hazır bir fonksiyon gibi bir çipin içine konur; kullanıcı yalnız girişleri verir ve ihtiyaç duyduğu çıkışı okur. Önceki derste tasarlanan genlik karşılaştırıcı (büyüktür, küçüktür, eşittir çıkışları) buna örnektir.
  - Bu tür hazır devrelere MSI (Medium Scale Integration, orta ölçekli tümleşik devre) denir.
  - Bu bölümde sırayla işlenecek konular: aritmetik toplama/çıkarma devreleri (yarı ve tam toplayıcı, yarı ve tam çıkarıcı, toplama/çıkarma devresi), çoğullayıcılar (multiplexer, MUX, seçici), dağıtıcılar (demultiplexer, DEMUX), kod çözücüler (decoder), kodlayıcılar (encoder), aritmetik lojik birim (ALU) ve 7 segment gösterge (ekrandan, 00:05:00 ve 00:10:00).
- Yarı toplayıcı (half adder)
  - İki tek bitlik girişi ($a$, $b$) toplar; çıkışları toplam $T$ ve elde $E$'dir. Önceki basamaktan gelen eldeyi hesaba katmadığı için "yarı" toplayıcı adını alır.
  - Doğruluk tablosu: $00 \to T=0, E=0$; $01 \to 1, 0$; $10 \to 1, 0$; $11 \to 0, 1$.
  - Karnaugh haritasından $T = \bar a b + a\bar b = a \oplus b$, $E = a \cdot b$ (ekrandan, 00:15:00).
  - Devre: bir XOR ve bir AND kapısı.
- Tam toplayıcı (full adder)
  - Üç giriş vardır: elde girişi $E_g$, $a$ ve $b$. Çıkışlar toplam $T$ ve elde $E$'dir. Ara basamaklardaki toplama, önceki basamaktan gelen eldeyi de eklemeyi gerektirdiği için bu devre kullanılır.
  - Doğruluk tablosu sekiz satırdır (ekrandan, 00:15:00); $E_g = 0$ olan yarısı yarı toplayıcının aynısıdır.
  - $T = a \oplus b \oplus E_g$ (üç girişli XOR). Karnaugh haritasında 1'ler komşu değildir, bu yüzden dört mintermin toplamı kalır ve bu üç girişli XOR'un tanımıdır.
  - $E = ab + E_g(a + b)$ (ekrandan, 00:20:00).
  - Doğrudan gerçekleme: üç girişli XOR ile $T$; $ab$ için AND, $a+b$ için OR, bunun $E_g$ ile AND'i ve son bir OR ile $E$ (ekrandan, 00:25:00).
  - İki yarı toplayıcıyla gerçekleme: HA1 $a$ ile $b$'yi toplar; HA2, HA1'in toplamını $E_g$ ile toplar ve asıl $T$'yi verir. İki yarı toplayıcının eldeleri bir OR kapısında birleşerek asıl $E$'yi verir (ekrandan, 00:25:00).
- 4 bitlik paralel toplayıcı
  - Dört tam toplayıcı (TT0-TT3) yan yana dizilir. TT0'a en düşük anlamlı bitler $a_0, b_0$ girer; $E_{g0} = 0$ yapılır (ya da toprağa bağlanır).
  - Her toplayıcının elde çıkışı bir sonrakinin elde girişine bağlanır; çıkışlar $T_0 \dots T_3$ ve en sondaki elde $E_3$'tür (ekrandan, 00:30:00).
- Yarı çıkarıcı (half subtractor)
  - Girişler $a$ (eksilen) ve $b$ (çıkan), çıkışlar fark $F$ ve borç $B$'dir (ekrandan, 00:35:00).
  - $0-1$ durumunda yandaki basamaktan borç alınır: ikilik tabanda $2 - 1 = 1$, yani $F = 1$, $B = 1$.
  - $F = a \oplus b$, $B = \bar a b$.
  - $\bar a b$, bir girişi değillenmiş (girişinde kabarcık olan) AND kapısıyla çizilebilir; bu, ayrı bir NOT kapısı koymamak için kullanılan kısa gösterimdir (ekrandan, 00:40:00).
- Tam çıkarıcı (full subtractor)
  - Girişler $a$, $b$ ve önceki basamaktan gelen borç girişi $B_g$; çıkışlar $F$ ve $B$'dir. $B_g$, bir önceki basamağın bu basamaktan borç alıp almadığını gösterir.
  - Doğruluk tablosu (ekrandan, 00:45:00):

    | $a$ | $b$ | $B_g$ | $F$ | $B$ |
    |---|---|---|---|---|
    | 0 | 0 | 0 | 0 | 0 |
    | 0 | 0 | 1 | 1 | 1 |
    | 0 | 1 | 0 | 1 | 1 |
    | 0 | 1 | 1 | 0 | 1 |
    | 1 | 0 | 0 | 1 | 0 |
    | 1 | 0 | 1 | 0 | 0 |
    | 1 | 1 | 0 | 0 | 0 |
    | 1 | 1 | 1 | 1 | 1 |

  - $F = a \oplus b \oplus B_g$; $B = \bar a b + \bar a B_g + b B_g = \bar a b + B_g(\bar a + b)$ (python ile doğrulandı).
- 4 bitlik çıkarıcı
  - Dört tam çıkarıcı (TÇ0-TÇ3) kullanılır. $B_{g0} = 0$'dır; her basamağın borç çıkışı bir üst basamağın borç girişine gider. Çıkışlar $F_0 \dots F_3$ ve en sondaki borç biti $B_3$'tür (ekrandan, 00:55:00).
  - Örnek: $0000 - 1111 = 0001$, son borç $B_3 = 1$ (ekrandan, 00:55:00).
- Toplama/çıkarma devresi (adder/subtractor)
  - Çıkarma, ikinci sayının ikiye tümleyeniyle toplamadır: $A - B = A + \bar B + 1$.
  - Seçim ucu $M$: $M = 0$ toplama, $M = 1$ çıkarma (ekrandan, 01:05:00).
  - $Z = M \oplus y$: $M = 0$ iken $y$ aynen geçer, $M = 1$ iken tersi geçer. Bu yüzden her $b_i$ girişine $M$ ile XOR'lanmış hali verilir.
  - $M$ ayrıca TT0'ın elde girişine ($E_{g0}$) bağlanır; böylece çıkarmada en düşük bite gereken $+1$ eklenir (ekrandan, 01:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yarı ve tam devre farkı
  - Yarı toplayıcı/çıkarıcı yalnız en düşük basamak için yeterlidir; ara basamaklarda önceki basamaktan gelen elde ya da borç da işleme girmelidir.
- Üç girişli XOR'un tanınması
  - Karnaugh haritasında hiçbir 1'in komşusu yoksa ve 1'ler "dama tahtası" düzenindeyse ifade XOR'dur; üç değişkende tek sayıda 1 olan satırlar 1 verir.
- Tam toplayıcının iki yarı toplayıcıyla kurulması
  - Önce $a + b$, sonra bu toplam ile elde girişi toplanır; iki elde OR ile birleştirilir. Hoca bu iki yapının aynı çıkışları verdiğinin simülasyonla gösterilmesini istedi.
- Borç bitinin anlamı
  - Borç biti alınan miktarı değil, yalnız borç alınıp alınmadığını gösterir.
- Bir taşla iki kuş
  - Aynı dört tam toplayıcı, $b$ girişlerindeki XOR'lar ve $E_{g0} = M$ bağlantısıyla hem toplama hem çıkarma yapar.

## Kısa Tekrar Notları

- MSI: orta ölçekli tümleşik devre; toplayıcı, çıkarıcı, MUX, DEMUX, decoder, encoder, ALU, 7 segment gösterge.
- Yarı toplayıcı: $T = a \oplus b$, $E = ab$.
- Tam toplayıcı: $T = a \oplus b \oplus E_g$, $E = ab + E_g(a+b)$.
- Tam toplayıcı = 2 yarı toplayıcı + 1 OR.
- 4 bit paralel toplayıcı: 4 tam toplayıcı, $E_{g0} = 0$, eldeler zincir halinde.
- Yarı çıkarıcı: $F = a \oplus b$, $B = \bar a b$.
- Tam çıkarıcı: $F = a \oplus b \oplus B_g$, $B = \bar a b + \bar a B_g + bB_g$.
- 4 bit çıkarıcı: 4 tam çıkarıcı, $B_{g0} = 0$, borçlar zincir halinde.
- Toplama/çıkarma devresi: $b_i \oplus M$, $E_{g0} = M$; $M=0$ toplama, $M=1$ çıkarma.

## Detaylı Açıklamalar

- Yarı toplayıcıda $T$'nin Karnaugh haritasında 1'ler $01$ ve $10$ hücrelerindedir; bunlar komşu olmadığı için $\bar a b + a\bar b$ kalır ve bu XOR'dur. $E$ yalnız $11$ satırında 1 olduğundan doğrudan AND'dir. Sonuçta yarı toplayıcının içinde bir XOR ve bir AND vardır.
- Tam toplayıcıda $T$ haritasında $E_g = 0$ satırında $ab = 01, 10$; $E_g = 1$ satırında $ab = 00, 11$ hücreleri 1'dir. Hiçbiri komşu olmadığı için $T = \bar E_g\bar a b + \bar E_g a\bar b + E_g\bar a\bar b + E_g ab$ yazılır; bu üç girişli XOR'un açık biçimidir. $E$ haritasında dört tane 1 vardır ve ikili gruplarla $E = ab + E_g(a+b)$ elde edilir.
- İki yarı toplayıcılı yapıda HA1 $a \oplus b$ ve $ab$ üretir; HA2 $(a \oplus b) \oplus E_g$ ile asıl toplamı ve $E_g(a \oplus b)$ ile ikinci eldeyi üretir. Asıl elde $ab + E_g(a \oplus b)$ olur; bu, $ab + E_g(a+b)$ ile aynı fonksiyondur (python ile sekiz satırda doğrulandı).
- 4 bitlik paralel toplayıcıda her basamak bir tam toplayıcıdır. En düşük basamağa gelen bir elde olmadığı için $E_{g0}$ sıfıra (toprağa) bağlanır. Her basamağın eldesi bir sonraki basamağa taşınır; dört bitin toplamı taşarsa son elde $E_3$ beşinci bit olarak okunur.
- Yarı çıkarıcıda $0 - 1$ yapılamadığı için yandaki basamaktan borç alınır; alınan borç bu basamakta ikilik tabanda 2 değerindedir ve $2 - 1 = 1$ kalır. Bu yüzden bu satırda $F = 1$ ve $B = 1$'dir. Diğer satırlarda borç gerekmez.
- Tam çıkarıcıda $B_g = 1$ ise bir alt basamak bu basamaktan borç almıştır, yani bu basamağın değeri bir azalmıştır. Örneğin $a = 0$, $b = 0$, $B_g = 1$ satırında basamak 0 iken bir azaltılmalıdır; bunun için yukarıdan borç alınır ($B = 1$) ve $2 - 1 = 1$ kalır ($F = 1$). Borç çıkışı haritada üç ikili grupla $\bar a b + \bar a B_g + bB_g$ olur; bu üç AND'in çıkışları bir OR kapısında birleştirilir.
- Ondalık benzetme: $11 - 22$ işleminde yandan borç alınır ve sonuç 100'lük döngüde geriye gidilmiş gibi $89$ olur ($11 - 22 \equiv 89 \pmod{100}$). İkilik çıkarıcıdaki son borç biti de bu "döngüden geri gitme" durumunu gösterir. $0000 - 1111$ işleminde her basamakta borç alınır; sonuç $0001$, son borç $1$'dir.
- Toplama/çıkarma devresinde $M = 1$ olunca her $b_i$ XOR ile tersine çevrilir ($\bar b_3 \bar b_2 \bar b_1 \bar b_0$) ve $E_{g0} = 1$ olduğu için en düşük bite 1 eklenir; böylece $A + \bar B + 1 = A - B$ hesaplanır. $M = 0$ iken XOR'lar $b_i$'yi değiştirmez, $E_{g0} = 0$ olur ve devre sıradan 4 bitlik toplayıcıdır.
- Ders sonrası not: Hoca yarı toplayıcıyı çizerken bir yerde "tam toplayıcı yapmak için" dedi; kastedilen yarı toplayıcıdır. Tam çıkarıcının borç çıkışını çizerken üç AND'in "üç girişli XOR ile" birleştirileceğini söyledi; ifade $\bar a b + \bar a B_g + bB_g$ olduğu için doğrusu üç girişli OR'dur. Toplama/çıkarma devresinin çiziminde en üst toplayıcının toplam çıkışı tahtada $T_2$ diye yazıldı; doğrusu $T_3$'tür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
