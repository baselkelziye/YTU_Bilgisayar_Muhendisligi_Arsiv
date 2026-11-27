# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin konu akışı
  - Algoritma ve veri yapısı kavramları, algoritmik problem çözme, akış diyagramı ve C hatırlatması ile başlanır.
  - Sonra algoritma tasarımı, algoritma analizi, bağlı listeler, yığın (stack) ve kuyruk (queue), ağaçlar ve ikili arama ağacı, heap ve heap ile sıralama, öncelikli kuyruk, graflar ve minimum yayılımlı ağaç, böl ve yönet algoritmaları, metin (string) arama ve sıralama algoritmalarının karşılaştırılması gelir.
  - Hash tabloları bu dersin kapsamında değildir.
- Algoritma kavramı ve kökeni
  - "Algoritma" kelimesi El-Harezmi'nin adından ve Hint rakamlarıyla hesap yapmayı anlatan eserinin Latince çevirisinden ("Algoritmi de numero Indorum") gelir.
  - Tanım: bir problemi işlemlerle çözmek için izlenecek yol teorik olarak oluşturulduğunda bir algoritma tasarlanmış olur.
  - Algoritma, belirli bir problemi çözmek için art arda uygulanacak **kesin** direktiflerden oluşan **sonlu** bir kümedir. Mantıklı ve doğru tüm girdiler için **doğru** çıktıyı **sonlu bir zamanda** üretir (ekrandan, 00:45:00).
  - Örnekler: notları sıralama, iki semt arasında en kısa yolu bulma, ödevlerin sırasını planlama, web aramasında sayfaları sıralama (ranking), diş fırçalama adımları.
  - Algoritmanın bir programlama diliyle gerçeklenmiş hâline program denir.
- Algoritmanın taşıması gereken özellikler
  - Anlaşılırlık (unambiguous): adımlar, girdi ve çıktılar net ve tek anlamlıdır.
  - Girdi: sıfır ya da iyi tanımlanmış $n$ tane girdi.
  - Çıktı: en az bir iyi tanımlanmış çıktı.
  - Sonlanma: belirli bir adımdan sonra durur.
  - Yapılabilirlik (feasibility): mevcut imkânlarla ve makul sürede gerçekleştirilebilir.
  - Programlama dilinden bağımsızlık.
- Algoritmalarla çözülen problem aileleri
  - Sıralama, alt metin arama, graf problemleri (en kısa yol), kombinatoryal, geometrik ve nümerik problemler.
- Veri ve verinin bilgisayarda tutulması
  - Veri, algoritmaların işlediği en temel elemandır: sayılar, metinler, resimler (iki boyutlu sayı dizisi), sesler.
  - Aynı 32 bitlik değer farklı gösterimlerle okunabilir (ekrandan, 01:05:00):
    - İşaretsiz tamsayı: `1111573057`
    - Ham veri: `01000010010000010100001001000001`
    - BCD (dörtlü gruplar): `0100 0010 0100 0001 0100 0010 0100 0001`
    - HEX: `42 41 42 41`
    - ASCII: `B A B A`
  - Von Neumann mimarisinde program kodu ve veri aynı bellekte durur. İşlemcide anlık değerler yazmaçlarda (register) tutulur.
- Veri yapısı
  - Algoritmaların erişme, değiştirme gibi işlemlerinde kullanmak üzere bilginin saklandığı oluşumlardır (ekrandan, 01:10:00).
  - Örnekler: listeler (diziler, linkli listeler), stack, queue, hash tabloları, ağaçlar, heap ve öncelikli kuyruk, küme ve sözlük.
  - Kısaca, verinin bellekte tutulma şekli ve düzenidir.
- Neden veri yapısı gerekir?
  - Verinin etkin saklanması ve işlenmesi için. Doğru yerde kullanılan basit bir yapı bile çok etkili olabilir (ekrandan, 01:15:00).
  - Seyrek (sparse) matris örneği: $1000 \times 1000$ matriste yalnız sıfırdan farklı değerleri (satır, sütun, değer) üçlüleri olarak tutmak bellekten büyük kazanç sağlar.
- Algoritma hazırlama süreci
  - Tasarım, doğrulama (validasyon), analiz (performans ve karmaşıklık), gerçekleme (kodlama), test.
- Algoritmayı ifade etmek: sözde kod (pseudo-code)
  - Yarı programlama dili, yarı konuşma dili.
  - Algoritma adı, parametreler, girdi, çıktı, gerekiyorsa ön ve son koşullar yazılır. Adımlar 1, 2, 2.1 biçiminde numaralanır.
  - Dijkstra'ya göre her algoritma üç yapıyla yazılabilir: dizilim, seçim ve döngü (ekrandan, 01:25:00).
  - Notasyon: atama `:=` ya da `←`, eşitlik kontrolü `=`, `if ... end if`, `while ... end while`, `do ... while`, `repeat ... until`, `for ... step ... end for`, indis için köşeli parantez (ekrandan, 01:30:00).
- Algoritmayı ifade etmek: akış diyagramı
  - Bileşenler: başla-bitir, okuma, bağlantılar (oklar, çemberler), işlemler, kararlar, döngüler (ekrandan, 01:35:00).
- C dilinin temelleri (hatırlatma)
  - Fonksiyon yapısı, ifade, sabit ve değişken, isimlendirme kuralları, ayrılmış kelimeler, `main` ve çıkış değeri, önişlemci, veri tipleri ve tamsayı boyutları, tip dönüşümleri, `void`, `typedef`, `sizeof`.
  - İşlem öncelikleri, aritmetik atama operatörleri, artırma ve azaltma, virgül operatörü, ilişkisel ve mantıksal operatörler, bit kaydırma, koşul operatörü `?:`, bellek operatörleri.
  - `if` ve sarkan else (dangling else), `switch`, `while`, `do-while`, `for`, `break`, `continue`, `goto`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir yöntemin algoritma sayılması için kesin, sonlu, doğru ve sonlu zamanda biten olması gerekir.
  - Sonsuz dönen ya da sonsuz zamanda sonuç veren bir çözüm algoritma değildir.
- Algoritma tasarımı programlama dilinden bağımsızdır.
  - Akış diyagramında `A++` gibi dile özel operatör kullanılmaz. `A = A + 1` yazılır (ekrandan, 01:45:00).
  - Eşitlik kontrolünde `==` ya da `===` gibi dile özel gösterimler kullanılmaz.
- Okuma bileşeninde dizinin boyutu $N$, dizinin elemanlarından önce okunmalıdır.
  - Kaç değer okunacağı bilinmeden değerler okunamaz.
  - Algoritmada kullanılan ve dışarıdan gelmesi gereken her değer bir okuma bileşeninde gösterilmelidir.
- Oklar eğri büğrü değil, düz ya da köşeli çizilir. Bağlantı çemberlerinde numaralandırmaya dikkat edilir (ekrandan, 01:40:00).
  - İç içe döngülerde çember numaraları karışırsa gerçekleştirilemeyen bir akış ortaya çıkar.
- `if` bileşeninde T ve F kolları mutlaka etiketlenir (ekrandan, 01:50:00).
  - Doğru (T) kolu zorunludur, yanlış (F) kolu isteğe bağlıdır.
  - Yalnız F kolu olan bir `if` olamaz. Koşul ters çevrilerek T koluna dönüştürülür.
  - Bütün `if`lerde T kollarının aynı tarafta olması tercih edilir.
- `for` bileşeninde ilk değer, adım ve son koşul gösterilir. Adım +1 olsa bile, özellikle geriye doğru taramada $-1$ adımı açıkça yazılmalıdır.
- `while` döngüsünün içinde koşulu değiştiren bir işlem olmalıdır. Yoksa sonsuz döngü oluşur.
- C'de pointer aritmetiği, operatör öncelikleri ve dinamik bellek ayırma konularında eksik varsa şimdiden tamamlanmalıdır.
- Okunması zor tek satırlık C ifadeleri yazılmamalıdır. `m++ * m++` gibi ifadeler derleyiciye göre farklı sonuç verebilir.
- `break`, `continue` ve `goto` sevilen akış yöntemleri değildir. Çoğu zaman tasarımda bir eksiklik olduğunu gösterir.

## Kısa Tekrar Notları

- Algoritma = kesin direktifler + sonlu adım + doğru çıktı + sonlu zaman.
- Algoritmanın özellikleri: anlaşılırlık, girdi, çıktı, sonlanma, yapılabilirlik, dilden bağımsızlık.
- Veri yapısı: verinin bellekte tutulma şekli ve düzeni.
- Seyrek matriste yalnız sıfırdan farklı değerleri tutmak bellekten tasarruf sağlar.
- Üç temel yapı: dizilim (sequence), seçim (selection), döngü (loop).
- Sözde kodda atama `:=` ya da `←`, eşitlik `=`.
- Akış diyagramında: elips başla-bitir, delikli kart okuma, dikdörtgen işlem, altıgen karar (`if` ve `while`), üç bölmeli dikdörtgen `for`.
- `while`: bilinmeyen sayıda tekrar; koşul döngü içinde değişmelidir.
- `do-while`: blok en az bir kez çalışır.
- `for`: önce expression1, sonra expression2 test edilir; doğruysa gövde, sonra expression3, sonra yeniden expression2 (ekrandan, 02:50:00).
- C isimleri harf ya da alt çizgiyle başlar; harf, rakam ve alt çizgi içerir; büyük/küçük harf duyarlıdır; ayrılmış kelime olamaz.
- ANSI C: bayt en az 8 bit, `int` en az 16 bit.
- 32 bitlik `int` aralığı $-2^{31}$ ile $2^{31}-1$ arasıdır.
- `int j=2, k=3; float f;` için `f = k/j;` sonucu `1.0`, `f = (float)k/j;` sonucu `1.5` olur.
- Kalan için ANSI kuralı: `a == (a % b) + (a / b) * b`.
- `5 << 1 = 10`, `255 >> 3 = 31`, `8 << 10 = 8192 = 2^13`.
- Sarkan else: `else` her zaman en yakın `if`e aittir.
- `switch` içinde her durumdan sonra `break` gerekir. `default` sona konmalıdır.

## Detaylı Açıklamalar

### Algoritma ve El-Harezmi

Algoritma kelimesi El-Harezmi'den gelir. 780 civarında doğduğu, Bağdat'ta yaşadığı ve Hint rakamlarıyla hesap yapma yöntemlerini anlatan bir eser yazdığı anlatıldı. Eserin Latince çevirisinde adı "Algoritmi" biçimine dönüşmüş, kelime de buradan doğmuştur.

<!-- BELİRSİZ: 00:37:37-00:37:51 arasında altyazıda boşluk var. Eserin adı ve "Algebrick kitabı" ifadesi net değil. -->

Hocanın tanımına göre her şey için algoritma olmaz. İşlem yaparak bir problemi çözmek gerektiğinde algoritma tasarımından söz edilir. Notları sıralamak, Beşiktaş ile Davutpaşa arasında trafik ve bekleme sürelerini de hesaba katarak en kısa yolu bulmak, ödevleri bir zaman planına koymak, arama motorunda sayfaları ilgiye göre sıralamak birer algoritma tasarımı problemidir. Diş fırçalama örneğinde başlangıç ve girdiler bellidir, adımlar kesin ve sonludur, sonuç (temiz dişler) sonlu sürede elde edilir.

### Veri ve veri yapısı

Algoritmaların "benzini" veridir. Resimler aslında iki boyutlu bir sayı dizisidir, sesler bir ya da iki boyutlu sayı dizileriyle gösterilir. Yani algoritmalar temelde sayılar ve metinlerle çalışır. Veri girdilerde, çıktılarda ve ara hesaplamalarda kullanılır, ama algoritmanın işleyebilmesi için düzenlenmiş olması gerekir.

Ekrandaki örnekte aynı 32 bitlik değer işaretsiz tamsayı olarak `1111573057`, onaltılık olarak `42 41 42 41`, ASCII tablosuyla `BABA` olarak okunur (ekrandan, 01:05:00). Bu dönüşüm ajan tarafından python ile doğrulandı: `0x42414241 = 1111573057`. İnsan ham bitleri anlamlandıramaz, ama dönüştürülmüş hâli üzerinde algoritma çalıştırabilir.

Veri yapısı, verinin hangi şekilde tutulacağını, elemanların birbirine nasıl bağlanacağını, erişim ve kullanma kurallarını tanımlar. Dizi indisle doğrudan erişim sağlar. Linkli liste bellekle sınırlı uzunlukta dinamik bir yapıdır. Stack, raftaki tabaklar gibi yalnız en üstteki elemana erişime izin verir.

### Seyrek matris örneği

$n = 1000$ için $n \times n$ matris bir milyon göz demektir. Problemde matrisin çoğu sıfırsa (örneğin bir milyon gözün 950 bini), bütün matris için yer ayırmak yerine yalnız sıfırdan farklı değerler (satır, sütun, değer) üçlüleri hâlinde ve birbirine bağlı olarak tutulabilir. Böylece yaklaşık %95 daha az yer kullanılır. Biri telefonda bile çalışabilecekken diğeri sunucu gerektirebilir. Slaytta örnek olarak "1. ve n. sütun ile diyagonal dışındaki değerlerin 0 olması" durumu verilmiştir (ekrandan, 01:15:00).

### Sözde kod ve akış diyagramı

Sözde kodda veri elemanlarının tanımı ve tipi gerekmez, ilk kullanımda tanımlandığı varsayılır. Ama stack ya da ağaç gibi bir veri yapısı kullanılıyorsa mutlaka tanımlanır. Değişken adları anlamlı seçilir: `toplam` yerine hangi dizinin toplamı olduğunu anlatan bir ad tercih edilir.

Slayttaki dizi toplamı örneği (ekrandan, 01:20:00):

```text
Toplam Hesapla (dizi, toplam,)
Girdi: n sayıdan oluşan dizi
Çıktı: dizi elemanlarının toplam sonucu
for i:=1 to n do
  toplam:= toplam + dizi[i]
end for
```

Akış diyagramında `if` için eşkenar dörtgen yerine altıgen tercih edilir. Hocanın anlattığına göre eşkenar dörtgen Fortran'daki üç çıkışlı (negatif, sıfır, pozitif) `if`ten kalmadır. Günümüzde yalnız doğru ve yanlış çıkışları olduğundan altıgen daha uygundur.

### C hatırlatması

C'de değişken, bellekteki bir adresin gösterimidir. Önişlemci ifadeleri `#` ile başlar ve satır sonuyla biter, sonlarına `;` konmaz (ekrandan, 02:20:00). `#include <dosya>` derleyicinin varsayılan klasörüne, `#include "dosya"` önce bulunulan klasöre bakar.

Tip dönüşümü örneği (ekrandan, 02:25:00): `int j=2, k=3; float f;` için `f = k/j;` tamsayı bölmesi yapar ve `1.0` verir. `f = (float)k/j;` ise `1.5` verir. Ajan bunu `gcc` ile derleyip doğruladı.

> **Ders sonrası not:** Hoca `f = k/j;` için sonucun "2 bölü 3 float" olduğunu söyledi. Doğrusu: `k/j` iki tamsayının bölmesi olduğu için `3/2 = 1` hesaplanır ve `f = 1.0` olur. Kesirli sonuç (`1.5`) için cast gerekir. Slaytta `int j=2; k=3;` yazılmış, hoca bunun hatalı olduğunu belirtti. Doğrusu `int j=2, k=3;` biçimindedir.

Artırma örneklerinde `j=0, m=1, n=-1` ile `m++ - --j` ifadesinin değeri 2 olur ve sonra `m` 2 olur. `m += ++j * 2` sonucunda `m = 3` olur. Ajan bunları `gcc` ile doğruladı.

> **Ders sonrası not:** Hoca `m++ * m++` ifadesinin derleyiciye göre farklı sonuç verebileceğini söyledi. C standardına göre bu ifade tanımsız davranıştır (undefined behavior), çünkü aynı değişken iki sıralama noktası arasında iki kez değiştiriliyor. Bu yüzden hiç yazılmamalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
