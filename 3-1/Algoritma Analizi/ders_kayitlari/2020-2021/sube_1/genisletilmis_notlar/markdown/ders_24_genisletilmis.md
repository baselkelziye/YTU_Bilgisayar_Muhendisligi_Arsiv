# Ders 24 Genişletilmiş Notu: Ödev Çözümleri: Seri Kazanma Olasılığı ve Levenshtein Uzaklığıyla Kelime Önerme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Yapısı
- 2. Problem 1: Seri Kazanma Olasılığı
- 3. Problem 2: Yazım Denetimi ve Kelime Önerme
- 4. Levenshtein Edit Distance Tablosunun Doldurulması
- 5. Bonus: Hesaplamayı Erken Durdurma
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Yapısı

Bu kayıt bir teori dersi değil, ödev çözüm oturumudur. Ödevin iki problemi ders slaytları üzerinden tek tek hatırlatıldı, çözümleri anlatıldı ve öğrencilerin ödevle ilgili soruları cevaplandı. Anlatım sırasında tablolar slayt üzerine elle yazılarak dolduruldu. Birinci problem dinamik programlamayla bir olasılık hesabı, ikinci problem ise ikinci ödevden tanıdık olan hash tablosu tabanlı yazım denetiminin Levenshtein uzaklığıyla genişletilmesidir.

## 2. Problem 1: Seri Kazanma Olasılığı

### 2.1 Problem tanımı

Slayttaki problem metni (ekrandan, 00:05:00):

- A ve B takımları, içlerinden biri $n$ galibiyet alana kadar maç yapacaklardır.
- A takımının bir maçı kazanma olasılığı her maç için $p$, kaybetme olasılığı ise $1-p$'dir. Dolayısıyla beraberlik ihtimali mevcut değildir.
- A takımının seriyi kazanmak için $i$ tane daha maç kazanması, B takımının da seriyi kazanmak için $j$ tane maç kazanması gereken durumda A'nın seriyi kazanma olasılığı $P(i,j)$'dir.

Örneğin yedi maçlık bir seride ($n=4$) başlangıçta iki takımın da 4 galibiyete ihtiyacı vardır; bu durum $P(4,4)$ ile ifade edilir. A bir maç kazanırsa A'nın 3 galibiyete daha ihtiyacı kalır, B'nin hâlâ 4; yeni durum $P(3,4)$ olur.

### 2.2 Yineleme bağıntısı ve sınır değerleri

Slayttaki bağıntı (ekrandan, 01:00:00):

- A takımı $p$ ihtimalle bir maç kazanırsa, A'nın seriyi kazanması için gerekli maç sayısı $i-1$ olur, B takımı ise hâlâ $j$ galibiyet elde etmelidir.
- A takımı $1-p$ ihtimalle bir maç kaybederse, A hâlâ $i$ galibiyet, B ise $j-1$ galibiyet elde etmelidir.

$$
P(i,j) = p \times P(i-1,j) + (1-p)\times P(i,j-1) \qquad \forall\, i,j > 0
$$

Bağıntı $i$ ve $j$ sıfırdan büyükken geçerlidir; çünkü biri sıfır olduğu anda seriyi kimin kazandığı bellidir:

- A takımının kazanacak maç sayısı sıfır olduğunda A seriyi kazanmıştır: $P(0,j) = 1$, $j > 0$.
- B takımının kazanacak maç sayısı sıfır olduğunda A seriyi kaybetmiştir: $P(i,0) = 0$, $i > 0$.

### 2.3 Tablonun doldurulması ($p = 0{,}4$)

Örnekte A'nın bir maçı kazanma olasılığı $p=0{,}4$, kaybetme olasılığı $q = 1-0{,}4 = 0{,}6$'dır. Önce 0. satıra ($i=0$) 1'ler, 0. sütuna ($j=0$) 0'lar yazılır. Sonra diğer gözler bağıntıyla hesaplanır. Slaytta $P(1,2)$ gözünün hesabı gösterildi (ekrandan, 00:10:00):

$$
P(1,2) = 0{,}4 \times P(0,2) + 0{,}6 \times P(1,1)
$$

$P(0,2)$ başlangıç değeri olarak 1'dir, ama $P(1,1)$ önce hesaplanmalıdır:

$$
P(1,1) = 0{,}4 \times P(0,1) + 0{,}6 \times P(1,0) = 0{,}4 \times 1 + 0{,}6 \times 0 = 0{,}4
$$

Yerine yazılınca:

$$
P(1,2) = 0{,}4 \times 1 + 0{,}6 \times 0{,}4 = 0{,}4 + 0{,}24 = 0{,}64
$$

Her göz bu bağıntıyla hesaplanır. A'nın seriyi kazanma olasılığı en sondaki göz, yani $P(4,4)$'tür. Tablonun tamamı (ekrandan, 00:10:00; değerler iki basamağa yuvarlanmış):

| $i \backslash j$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| 0 | | 1 | 1 | 1 | 1 |
| 1 | 0 | 0,40 | 0,64 | 0,78 | 0,87 |
| 2 | 0 | 0,16 | 0,35 | 0,52 | 0,66 |
| 3 | 0 | 0,06 | 0,18 | 0,32 | 0,46 |
| 4 | 0 | 0,03 | 0,09 | 0,18 | 0,29 |

Tablo python ile yeniden hesaplandı ve ekrandaki değerlerle uyuştu; tam değerler örneğin $P(2,2) = 0{,}352$, $P(4,4) = 0{,}28979\ldots \approx 0{,}29$'dur. Ekrandaki $j=1$ sütunu da sezgiyi gösterir: B'nin tek galibiyete ihtiyacı varken A'nın $i$ maçın hepsini kazanması gerekir, bu yüzden $P(i,1) = 0{,}4^i$ olur ($0{,}4$; $0{,}16$; $0{,}064$; $0{,}0256$). Anlatımda da "iki maçı kazanma olasılığı $0{,}4 \times 0{,}4 = 0{,}16$, sonra bir kez daha $0{,}4$ ile çarpılıyor" diye açıklandı.

> **Ders sonrası not:** Anlatımda ödevde istenen değerin $p=0{,}4$ değil, $0{,}6$ olabileceği ve o durumda sonucun $0{,}7$ civarında çıktığı hatırlandığı söylendi. Python ile $p=0{,}6$, $n=4$ için $P(4,4) = 0{,}7102$ bulunur. Ödevde hangi değerin istendiği altyazıdan kesinleşmiyor. <!-- BELİRSİZ: ödev metnindeki p değeri (0,4 ya da 0,6) ekranda görülmedi -->

### 2.4 WinSeries sözde kodu

Slayttaki algoritma (ekrandan, 00:15:00):

```text
Algoritma WinSeries(n, p)
// n galibiyetin kazanılma olasılığını hesaplar
// Input: Kazanmak için gerekli n galibiyet sayısı
//        ve takımın maçı kazanma olasılığı
// Output: Takımın seriyi kazanma olasılığı

q <- 1 - p
for j <- 1 to n do
    P[0, j] <- 1.0
for i <- 1 to n do
    P[i, 0] <- 0.0
    for j <- 1 to n do
        P[i, j] <- p * P[i - 1, j] + q * P[i, j - 1]
return P[n, n]
```

Fonksiyon kazanma olasılığı $p$'yi alır, kaybetme olasılığını $q = 1-p$ olarak hesaplar. İlk döngü 0. satırı 1'lerle doldurur; dış döngü her satırın başına 0 yazar ve iç döngü o satırın gözlerini yineleme bağıntısıyla hesaplar. Sonuç olarak $P[n,n]$ döner. Tablo satır satır doldurulduğu için bir göz hesaplanırken üstündeki ($P[i-1,j]$) ve solundaki ($P[i,j-1]$) gözler hazırdır.

> **Ek bilgi (derste anlatılmadı):** Tabloda $(n+1)^2$ göz vardır ve her biri sabit sürede hesaplanır; bu yüzden algoritmanın zaman karmaşıklığı $\Theta(n^2)$'dir.

### 2.5 Kazanılan maçlarla ileri doğru hesaplama

Oturumun sonunda bir öğrenci aynı soruyu kalan maçlar yerine kazanılan maçlar üzerinden kurduğunu anlattı: her kazanılan maçta ileri gidip iki takımın da 4 galibiyete ulaştığı durumu sonuç olarak almış ve yine $0{,}29$ bulmuştu. Cevap şuydu: olasılık hesabı aynıdır ve aynı sonuca ulaşılır; ama soruda $i$ ve $j$ açıkça "daha kazanılması gereken maç sayısı" olarak tanımlanmıştır. Bu tanıma göre başlangıç durumu $(4,4)$, bitiş durumları ise $i=0$ ya da $j=0$ olan gözlerdir.

## 3. Problem 2: Yazım Denetimi ve Kelime Önerme

### 3.1 Problem tanımı

İkinci problem, ikinci ödevdeki yazım denetiminin devamıdır. Kullanıcı bir cümle girer. Cümledeki her kelime, sözlük dosyasındaki (small dictionary txt) kelimelerin bir kez yerleştirildiği sözlük hash tablosunda aranır. Kelime sözlük tablosunda varsa doğrudur. Yoksa hatalı kelimeler tablosunda aranır. Hiçbirinde yoksa, sözlükte Levenshtein uzaklığı önce 1, sonra 2 olan kelimeler kullanıcıya önerilir. Kullanıcı doğru kelimeyi seçince hatalı kelime doğru karşılığıyla hatalı kelimeler tablosuna kaydedilir ve cümlenin doğru hali gösterilir.

### 3.2 searchHashTable

Tabloda arama yapılırken önce büyük-küçük harf uyumu sağlanır, sonra kelimenin hash indeksine bakılır. O indeksteki değer boşsa (NULL) kelime tabloda yoktur. Deneme sayısı tablo boyutunu aşarsa da kelime yok demektir. İndeksteki kelime aranan kelimeyle karşılaştırılır; `strcmp` iki dizgi eşitken 0 döndürdüğü için sonuç 0 ise kelime bulunmuştur ve `searchHashTable` 1 döndürür. <!-- BELİRSİZ: searchHashTable slaytı karelerde görülmedi; deneme sayısı koşulu altyazıda "M1'den büyükse" diye geçiyor -->

### 3.3 suggestWord

Slayttaki sözde kod (ekrandan, 00:20:00):

```text
suggestWord(dictionary_hashTable, wrong_hashTable, word, Mh1, Mh2):
    if(searchHashTable(dictionary_hashTable, word, Mh1, Mh2) == 1)
        kelime sözlük tablosunda bulundu
        öneri işlemi yapma
        return
    else
        if(searchHashTable(wrong_hashTable, word, Mh1, Mh2) == 0 )
            if(get_words_with_LevenshteinEditDistance(dictionary_hashTable, word, Mh1, Mh2, 1) != NULL)
                kullanıcıya uzaklığı 1 olan kelimeleri göster
                if (kullanıcı doğru kelimeyi uzaklığı 1 olan kelimelerden seçim yaparsa)
                    hatalı tablosuna ekle
                    return
            if(get_words_with_LevenshteinEditDistance(dictionary_hashTable, word, Mh1, Mh2, 2) != NULL)
                kullanıcıya uzaklığı 2 olan kelimeleri göster
                if (kullanıcı doğru kelimeyi uzaklığı 2 olan kelimelerden seçim yaparsa)
                    hatalı tablosuna ekle
                    return
                else
                    doğru kelimeler tablosunda 2 ve 2 den küçük mesafede bir kelime bulunamadı.
                    return
        else
            kelime hatalı kelimler hash tablosunda mevcut.
            Ekleme işlemi yapma
            Doğru kelimeyi tablodan oku ve print et
            return
```

Fonksiyon hem sözlük tablosunu hem hatalı kelimeler tablosunu ve denetlenecek kelimeyi alır; cümledeki her kelime bu fonksiyona tek tek gönderilir. `Mh1` ve `Mh2` parametreleri arama fonksiyonuna aktarılan hash parametreleridir. Kelime sözlükte bulunursa öneri yapılmadan dönülür. Bulunamazsa `else` dalına girilir ve kelime hatalı kelimeler tablosunda aranır. Orada da yoksa önce uzaklığı 1 olan kelimeler önerilir; kullanıcı bunlardan seçim yapmazsa uzaklığı 2 olanlar önerilir. Hatalı tabloda varsa yeni ekleme yapılmaz, kayıtlı doğru kelime okunup yazdırılır.

### 3.4 Uzaklığı 1 yoksa 2: ödev metninin yorumu

Sözde kodda uzaklığı 1 olan kelimeler gösterildikten sonra kullanıcı seçim yapmazsa 2'ye geçiliyordu. Öğrenciler ödev metninde (3. maddenin a şıkkında) uzaklığı 2 olan kelimelerin yalnız uzaklığı 1 olan kelime yoksa önerileceğinin yazdığını hatırlattı; ödev metnine bakılarak bunun doğru olduğu kabul edildi. Bu yorumda yukarıdaki ilk `if` bloğu yok sayılıp fonksiyon doğrudan sınır 2 ile çağrılabilir: `get_words_with_LevenshteinEditDistance` uzaklığı sınıra eşit ya da küçük olan kelimeleri döndürdüğü için uzaklığı 1 ve 2 olan kelimelerin hepsi gelir. Kelimeleri yalnız "2'ye eşit ya da küçük" koşuluyla göstermek de doğru kabul edilebilecek bir yaklaşım olarak anıldı.

### 3.5 get_words_with_LevenshteinEditDistance

Fonksiyon sözlük tablosundaki kelimeler için Levenshtein uzaklığını hesaplar. Hesaplanan uzaklık verilen sınırdan (örneğin 2) küçük ya da ona eşitse kelime, kelimelerin tutulduğu diziye eklenir. Dizinin başlangıç değeri NULL olduğu için hiç kelime bulunmazsa fonksiyon NULL döndürür. Kullanıcı seçimini yaptıktan sonra girdiği kelime hatalı kelimeler tablosuna eklenir; iki uzaklıkta da kelime yoksa kullanıcıya bulunamadığı bildirilir. <!-- BELİRSİZ: get_words fonksiyonunun slaytı karelerde görülmedi; anlatım altyazıdan -->

## 4. Levenshtein Edit Distance Tablosunun Doldurulması

### 4.1 Kural

Edit distance hesaplayan fonksiyonun ödevde mutlaka kullanılması gerekiyordu; nasıl çalıştığı bir tablo üzerinde gösterildi. Tablonun 0. satırı ve 0. sütunu 0, 1, 2, ... diye doludur. Diğer her göz için ilgili iki harf karşılaştırılır:

- Harfler eşitse gözün değeri sol üst çapraz komşudan (köşegenden) aynen alınır.
- Harfler eşit değilse üç komşunun (sol, üst ve sol üst) en küçük değeri bulunur ve ona 1 eklenir.

$$
D[i][j] =
\begin{cases}
D[i-1][j-1] & a_i = b_j \\
1 + \min\{D[i-1][j],\ D[i][j-1],\ D[i-1][j-1]\} & a_i \neq b_j
\end{cases}
$$

İki kelime arasındaki uzaklık tablonun en sondaki (sağ alt) gözüdür; fonksiyon bu değeri döndürür.

### 4.2 Örnek: HELL ve HELLO

Sütunlarda HELLO, satırlarda HELL vardır (ekrandan, 00:30:00). İlk satırda H ile H eşittir, köşegenden 0 gelir. H ile E farklıdır; üç komşunun en küçüğü 0 olduğu için 1 yazılır. Aynı şekilde L, L ve O için 2, 3, 4 gelir. İkinci satırda E ile H farklıdır, en küçük komşu 0 olduğu için 1 yazılır; E ile E eşittir, köşegenden 0 gelir; sonra 1, 2, 3. Üçüncü satırda L ile L eşleşmelerinde köşegenden değer gelir. Tamamlanmış tablo (ekrandaki değerler, son satırın son iki gözü python ile tamamlandı):

| | | H | E | L | L | O |
|---|---|---|---|---|---|---|
| | 0 | 1 | 2 | 3 | 4 | 5 |
| H | 1 | 0 | 1 | 2 | 3 | 4 |
| E | 2 | 1 | 0 | 1 | 2 | 3 |
| L | 3 | 2 | 1 | 0 | 1 | 2 |
| L | 4 | 3 | 2 | 1 | 0 | 1 |

Sonuç sağ alt gözdeki 1'dir: HELL'den HELLO'ya bir harf (O) eklenerek geçilir.

## 5. Bonus: Hesaplamayı Erken Durdurma

### 5.1 Soru

Ödevdeki bonus soru şuydu: tablonun tamamını hesaplamadan, uzaklığın 2'den büyük olacağı ve kurala uymayacağı anlaşıldığı anda hesaplamayı durdurmak. Bunun nerede anlaşılacağı ARTIST (satırlar) ile FRIED (sütunlar) üzerinde incelendi (ekrandan, 00:35:00).

### 5.2 Tablonun ilk dört satırı

A satırında A hiçbir harfle eşleşmez; her göz en küçük komşu artı 1'dir: 1, 2, 3, 4, 5. R satırında F ile R farklıdır (2); R ile R eşittir, köşegenden 1 gelir; sonra 2, 3, 4. T satırı 3, 2, 2, 3, 4; I satırında I ile I eşittir ve köşegenden 2 gelir: 4, 3, 2, 3, 4 (ekrandan, 00:40:00).

| | | F | R | I | E | D |
|---|---|---|---|---|---|---|
| | 0 | 1 | 2 | 3 | 4 | 5 |
| A | 1 | 1 | 2 | 3 | 4 | 5 |
| R | 2 | 2 | 1 | 2 | 3 | 4 |
| T | 3 | 3 | 2 | 2 | 3 | 4 |
| I | 4 | 4 | 3 | 2 | 3 | 4 |
| S | 5 | 5 | 4 | 3 | 3 | 4 |
| T | 6 | 6 | 5 | 4 | 4 | 4 |

İlk anlatımda sol üstten başlayan köşegen izlendi ve I satırındaki (I, E) gözünde 3 görülünce "artık uzaklığın 2'den fazla olduğu anlaşıldı, sonraki satırı hesaplamaya gerek yok" denildi (ekrandan, 00:40:00, kırmızıyla işaretli göz). Son iki satır derste tam doldurulmadı; S satırı 5, 4, 3, 3, 4 olarak yazıldı (ekrandan, 00:45:00), T satırı ve sonuç (4) python ile tamamlandı.

### 5.3 Karşı örnek: ARTIED ve FRIED

Bir öğrenci şu itirazı getirdi: ARTIST'in son iki harfi E ve D olsaydı (ARTIED), sağ alta doğru 2'ler devam eder ve sonuç 2 çıkardı. Tablo bu haliyle dolduruldu (ekrandan, 00:40:00): E satırı 5, 4, 3, 2, 3 olur; çünkü E ile E eşittir ve köşegendeki 2 gelir. D satırının son gözünde D ile D eşittir, köşegendeki 2 gelir ve sonuç 2 çıkar. Oysa ilk kurala göre (I, E) gözündeki 3 görülüp durulacaktı; yani uzaklığı 2 olan bir kelime yanlışlıkla elenecekti.

ARTIED ile FRIED'ın tamamlanmış son iki satırı (python ile doğrulandı):

| | | F | R | I | E | D |
|---|---|---|---|---|---|---|
| E | 5 | 5 | 4 | 3 | 2 | 3 |
| D | 6 | 6 | 5 | 4 | 3 | 2 |

Bir öğrenci de durma ölçütünü satır bazında önerdi: tablo satır satır doldurulduğuna ve her göze ya bir şey eklendiğine ya da eklenmediğine göre, bir satırın bütün gözleri sınırdan (2) büyükse orada durulmalıdır.

### 5.4 Düzeltme: sonuç gözüne giden köşegen

Hatanın kaynağı tablonun kare olmamasıydı. ARTIST 6, FRIED 5 harflidir; bu yüzden sol üstten başlayan köşegen sonuç gözüne (sağ alt) ulaşmaz. Kontrol edilmesi gereken köşegen, sonuç gözünde biten köşegendir. Bu köşegen, kelime uzunluklarının farkı kadar kaymıştır: burada bir satır aşağıdan, yani $(1,0), (2,1), (3,2), (4,3), (5,4), (6,5)$ gözlerinden geçer (ekrandan, 00:55:00, mavi çizgiler). Bir öğrencinin ifadesiyle her durumda "bir önceki" köşegene değil, harf sayılarının farkı kadar gerideki köşegene bakılır; yedi harfli bir kelimede iki adım geriye bakmak gerekirdi.

Bu köşegende I satırındaki göz (4,3) hâlâ 2'dir. Gerçekten de FRI ile ARTI arasındaki uzaklık 2'dir; I satırında 3 görülüp durmak bu yüzden yanlıştı. Bir sonraki satır hesaplanınca:

- ARTIST'te (S satırı) bu köşegendeki göz 3 olur; artık uzaklığın 2'den büyük olduğu kesindir ve durulabilir. Aynı satırda bütün gözler de 2'den büyüktür (5, 4, 3, 3, 4); satır ölçütü de burada durur.
- ARTIED'de (E satırı) bu köşegendeki göz 2 olarak kalır; hesap devam eder ve sonuç 2 çıkar. Böylece karşı örnek de doğru çalışır.

Satırın tümünü kontrol etmek ile bu köşegeni kontrol etmek bu örnekte aynı satırda durur; her durumda aynı sonuca gidip gitmediği oturumda açık bırakıldı. Bir öğrencinin, ortadaki birkaç köşegenden (en büyük uzaklığın iki katı kadar) oluşan bir bandın kontrol edilmesi gerektiği önerisi de kesinleştirilmedi.

> **Ders sonrası not:** Levenshtein tablosunda bir köşegen boyunca değerler hiç azalmaz, yani $D[i+1][j+1] \ge D[i][j]$'dir (rastgele 20 000 kelime çifti üzerinde python ile denendi, hiç aykırı örnek çıkmadı). Bu yüzden sonuç gözünde biten köşegende sınırı aşan bir değer görülürse sonuç da sınırı aşar; düzeltilmiş ölçüt doğrudur. Satır ölçütü de doğrudur: her gözün değeri bir önceki satırdaki en az bir gözün değerinden küçük olamaz, dolayısıyla satır en küçükleri azalmaz.

> **Ek bilgi (derste anlatılmadı):** Sınır $k$ iken yalnız sonuç köşegenine $k$ uzaklıktaki gözlerin hesaplanmasıyla yetinmek, "bantlı" edit distance hesabı olarak bilinir ve süreyi $O(k \cdot \min(m,n))$'ye indirir. Bant dışında kalan gözlerin değeri zaten $k$'dan büyük olacağı için sonucu değiştirmez.

### 5.5 Yalnız köşegen boyunca ilerleyen yaklaşım

Bir öğrenci tabloyu tamamen doldurmadan, harfler eşit olduğu sürece köşegen boyunca ilerleyip, farklı olduğunda üç yola dallanarak özyinelemeli bir yaklaşımla hesapladığını anlattı; en çok iki adım ilerlendiği için az işlem yapıldığını, tam tabloyla aynı sonuçları aldığını söyledi. Cevap olarak, köşegendeki bir gözü doldurmak için üç komşusuna ihtiyaç duyulduğu hatırlatıldı; öğrenci yalnız gereken gözleri hesapladığını belirtti. Her durumda aynı sonucu veriyorsa yöntemin doğru olduğu söylendi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00 ve 01:00:00): A ve B takımları, içlerinden biri $n$ galibiyet alana kadar maç yapar. A'nın bir maçı kazanma olasılığı $p$, kaybetme olasılığı $1-p$'dir. $P(i,j)$, A'nın $i$, B'nin $j$ galibiyete daha ihtiyacı varken A'nın seriyi kazanma olasılığıdır. Yineleme bağıntısını ve sınır değerlerini yazın; $p=0{,}4$, $n=4$ için $P(4,4)$'ü dinamik programlamayla hesaplayın.

> **Çözüm (derste verildi):** $P(i,j) = p\,P(i-1,j) + (1-p)\,P(i,j-1)$, $i,j>0$; $P(0,j)=1$, $P(i,0)=0$. Tablo Bölüm 2.3'tedir; $P(1,1)=0{,}4$, $P(1,2)=0{,}64$ ve $P(4,4)\approx 0{,}29$ (tam değer $0{,}2898$).

**Soru 2** (ekrandan, 00:15:00): Seri kazanma olasılığını hesaplayan `WinSeries(n, p)` algoritmasını yazın.

> **Çözüm (derste verildi):** Bölüm 2.4'teki sözde kod.

**Soru 3** (ekrandan, 00:30:00): HELL ile HELLO arasındaki Levenshtein uzaklığını tablo doldurarak bulun.

> **Çözüm (derste verildi):** Bölüm 4.2'deki tablo; sonuç 1.

**Soru 4** (ekrandan, 00:35:00; bonus): ARTIST ile FRIED için Levenshtein tablosunu doldururken, uzaklığın 2'den büyük olduğu anlaşıldığı anda hesabı durdurmak için hangi kontrol yapılmalıdır? Hangi satırda durulur?

> **Çözüm (derste verildi, oturumda düzeltildi):** Sonuç gözünde biten köşegen (uzunluk farkı kadar kaymış köşegen) kontrol edilir. I satırında bu köşegendeki değer 2'dir, durulmaz; S satırında 3 olur ve orada durulur. Tam tablo sonucu 4'tür. Sol üstten başlayan köşegene bakmak, örneğin ARTIED ile FRIED'da (uzaklık 2) yanlışlıkla erken durdurur.

**Soru 5** (derste sözlü, 00:37:23): ARTIST'in son iki harfi E ve D olsaydı (ARTIED), ana köşegenden ilerleyerek durmak doğru olur muydu?

> **Çözüm (derste verildi):** Hayır. ARTIED ile FRIED arasındaki uzaklık 2'dir, ama sol üstten başlayan köşegende I satırında 3 görülür. Bölüm 5.3 ve 5.4.

## Dersin Toparlaması

Oturumda ödevin iki problemi çözüldü. Birincisinde seri kazanma olasılığı, kalan galibiyet sayılarıyla tanımlanan $P(i,j)$ üzerinden $P(i,j) = p\,P(i-1,j) + (1-p)\,P(i,j-1)$ bağıntısı ve $P(0,j)=1$, $P(i,0)=0$ sınır değerleriyle bir tabloda hesaplandı; $p=0{,}4$ ve $n=4$ için sonuç yaklaşık $0{,}29$ çıktı. İkincisinde hash tablosu tabanlı yazım denetimi, sözlükte bulunmayan kelimeler için Levenshtein uzaklığı 1 ve 2 olan kelimeleri öneren bir akışla genişletildi ve edit distance tablosunun nasıl doldurulduğu HELL/HELLO örneğiyle gösterildi.

Bonus soruda hesabı erken durdurma tartışıldı. Öğrencilerin getirdiği karşı örnekle, kare olmayan tablolarda sol üstten başlayan köşegenin değil, sonuç gözünde biten köşegenin kontrol edilmesi gerektiği ortaya çıktı. Bu köşegende ya da bir satırın tamamında sınırı aşan değer görüldüğünde hesap güvenle kesilebilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
