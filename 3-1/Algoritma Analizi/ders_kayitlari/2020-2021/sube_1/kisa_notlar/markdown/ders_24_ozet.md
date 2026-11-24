# Ders 24 Çalışma Özeti

## Genel Konular

- Ödev çözüm oturumu: iki ödev probleminin çözümü
  - Bu kayıt teori dersi değil, bir ödevin iki sorusunun çözümlerinin slaytlar üzerinden anlatıldığı ve öğrenci sorularının cevaplandığı bir uygulama oturumudur.
  - Problem 1 dinamik programlama ile seri kazanma olasılığı, Problem 2 hash tablosu ve Levenshtein edit distance ile yazım denetimi (kelime önerme) üzerinedir.
- Problem 1: Seri kazanma olasılığı (dinamik programlama)
  - A ve B takımları, içlerinden biri $n$ galibiyet alana kadar maç yapar. A'nın bir maçı kazanma olasılığı her maç için $p$, kaybetme olasılığı $1-p$'dir; beraberlik yoktur (ekrandan, 00:05:00).
  - $P(i,j)$: A'nın seriyi kazanmak için $i$, B'nin $j$ galibiyete daha ihtiyacı olduğu durumda A'nın seriyi kazanma olasılığıdır.
  - Yineleme bağıntısı: $P(i,j) = p \cdot P(i-1,j) + (1-p)\cdot P(i,j-1)$, $i,j>0$ için (ekrandan, 01:00:00).
  - Sınır değerleri: $P(0,j)=1$ ($j>0$), çünkü A'nın kazanacak maçı kalmamıştır; $P(i,0)=0$ ($i>0$), çünkü B seriyi almıştır.
  - $p=0{,}4$ ve $n=4$ için tablo doldurulur; sonuç $P(4,4)\approx 0{,}29$'dur (ekrandan, 00:10:00).
  - `WinSeries(n, p)` sözde kodu tabloyu satır satır doldurur ve $P[n,n]$ döndürür (ekrandan, 00:15:00).
- Problem 2: Yazım denetimi ve kelime önerme
  - Kullanıcının girdiği cümledeki her kelime sözlük hash tablosunda aranır. Bulunursa kelime doğrudur.
  - Bulunamazsa hatalı kelimeler hash tablosunda aranır. Orada varsa, daha önce kaydedilmiş doğru karşılığı okunup yazdırılır.
  - İki tabloda da yoksa sözlükte Levenshtein uzaklığı 1 olan kelimeler önerilir. Uzaklığı 1 olan kelime yoksa (ya da seçim yapılmazsa) uzaklığı 2 olanlar önerilir. Kullanıcının seçtiği doğru kelime hatalı kelimeyle birlikte hatalı kelimeler tablosuna eklenir.
  - `searchHashTable` kelimeyi bulursa 1 döndürür. Arama, büyük-küçük harf uyumu sağlandıktan sonra yapılır; boş göze (NULL) gelinirse kelime yoktur; `strcmp` 0 döndürürse kelime bulunmuştur.
  - `get_words_with_LevenshteinEditDistance` sözlükteki her kelime için uzaklığı hesaplar ve uzaklığı verilen sınıra eşit ya da küçük olan kelimeleri bir diziye ekler; hiç kelime yoksa dizi NULL kalır.
- Levenshtein edit distance tablosu
  - İki harf eşitse göz değeri çapraz (sol üst) komşudan aynen alınır. Eşit değilse üç komşunun (sol, üst, sol üst) en küçüğüne 1 eklenir.
  - Sonuç tablonun sağ alt gözüdür. HELL ile HELLO arasındaki uzaklık 1'dir (ekrandan, 00:30:00).
- Bonus: Hesaplamayı erken durdurma
  - Amaç, uzaklığın 2'yi aşacağı anlaşıldığında tablonun geri kalanını hesaplamamaktır. Örnek: ARTIST ile FRIED (ekrandan, 00:35:00).
  - İlk anlatımda ana köşegende (sol üstten başlayan) 2'den büyük değer görülünce durulabileceği söylendi; bu, kelime uzunlukları farklı olduğunda yanlış sonuç verir (aşağıya bakın).
  - Doğru kontrol, sağ alt köşeye (sonuç gözüne) giden köşegendir. İki kelimenin uzunluk farkı kadar kaymış bu köşegendeki bir göz 2'yi aşarsa sonuç da 2'yi aşar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Problem 1'de $i$ ve $j$, kalan (daha kazanılması gereken) maç sayılarıdır.
  - Kazanılan maç sayısıyla ileri doğru hesaplamak da aynı olasılığa ulaşabilir, ama soruda tanımlanan anlam kalan galibiyet sayısıdır. Bu yüzden sınır değerleri $P(0,j)=1$ ve $P(i,0)=0$ olur.
- Edit distance tablosunda eşit harflerde köşegendeki değer aynen alınır, eşit olmayanlarda üç komşunun en küçüğüne 1 eklenir; dönülen değer en sondaki gözdür.
- Erken durdurma için seçilen köşegen önemlidir.
  - Kare olmayan tabloda (kelime uzunlukları farklı) sol üstten başlayan köşegen sonuç gözüne ulaşmaz. ARTIST ve FRIED tablosunda (I, E) gözündeki 3 değeri görülüp durulması yanlıştı; sonuç gözüne giden köşegende o satırda hâlâ 2 vardı (ekrandan, 00:55:00).
  - Bir öğrencinin önerdiği karşı örnek (ARTIST yerine ARTIED) bu hatayı gösterdi: ARTIED ile FRIED arasındaki uzaklık 2'dir, ama ana köşegende 3 görülür.

## Kısa Tekrar Notları

- $P(i,j) = p\,P(i-1,j) + (1-p)\,P(i,j-1)$; $P(0,j)=1$, $P(i,0)=0$; sonuç $P(n,n)$.
- $p=0{,}4$, $n=4$ için $P(1,1)=0{,}4$, $P(1,2)=0{,}64$, $P(4,4)\approx 0{,}29$.
- Yazım denetimi akışı: sözlük tablosu, sonra hatalı kelimeler tablosu, sonra uzaklık 1, sonra uzaklık 2 önerileri.
- Levenshtein: eşit harf, çapraz değer; farklı harf, $1+\min(\text{sol},\text{üst},\text{çapraz})$.
- ED(HELL, HELLO) = 1; ED(ARTIST, FRIED) = 4; ED(ARTIED, FRIED) = 2.
- Erken durdurma: sonuç gözüne giden köşegende sınırı aşan değer görülürse ya da bir satırın bütün değerleri sınırı aşarsa durulabilir.

## Detaylı Açıklamalar

- **Seri kazanma olasılığı.** A'nın $i$, B'nin $j$ galibiyete ihtiyacı varken bir maç oynanır. A bu maçı $p$ olasılıkla kazanırsa durum $(i-1,j)$ olur; $1-p$ olasılıkla kaybederse durum $(i,j-1)$ olur. Bu iki olasılığın ağırlıklı toplamı $P(i,j)$'yi verir. $i=0$ ise A seriyi almıştır ($P=1$), $j=0$ ise B almıştır ($P=0$). Tabloda 0. satır 1'lerle, 0. sütun 0'larla doldurulur; diğer gözler soldan sağa, yukarıdan aşağı hesaplanır.
  - Örnek ($p=0{,}4$, $q=0{,}6$; ekrandan, 00:10:00): $P(1,1) = 0{,}4\cdot P(0,1) + 0{,}6 \cdot P(1,0) = 0{,}4\cdot 1 + 0{,}6\cdot 0 = 0{,}4$. $P(1,2) = 0{,}4\cdot P(0,2) + 0{,}6\cdot P(1,1) = 0{,}4 + 0{,}24 = 0{,}64$.
  - Tablonun tamamı ($i$ satır, $j$ sütun; ekrandaki iki basamaklı değerler):

| $i \backslash j$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| 0 | | 1 | 1 | 1 | 1 |
| 1 | 0 | 0,40 | 0,64 | 0,78 | 0,87 |
| 2 | 0 | 0,16 | 0,35 | 0,52 | 0,66 |
| 3 | 0 | 0,06 | 0,18 | 0,32 | 0,46 |
| 4 | 0 | 0,03 | 0,09 | 0,18 | 0,29 |

  - Değerler python ile doğrulandı; $P(4,4) = 0{,}2898$ olur.
- **WinSeries sözde kodu** (ekrandan, 00:15:00):

```text
Algoritma WinSeries(n, p)
// n galibiyetin kazanılma olasılığını hesaplar
// Input: Kazanmak için gerekli n galibiyet sayısı ve takımın maçı kazanma olasılığı
// Output: Takımın seriyi kazanma olasılığı
q <- 1 - p
for j <- 1 to n do
    P[0, j] <- 1.0
for i <- 1 to n do
    P[i, 0] <- 0.0
    for j <- 1 to n do
        P[i, j] <- p * P[i-1, j] + q * P[i, j-1]
return P[n, n]
```

- **Kelime önerme (suggestWord) akışı** (ekrandan, 00:20:00): Fonksiyon sözlük tablosunu, hatalı kelimeler tablosunu, kelimeyi ve iki hash fonksiyonu parametresini (`Mh1`, `Mh2`) alır. Kelime sözlükte varsa öneri yapılmaz. Yoksa ve hatalı kelimeler tablosunda da yoksa önce uzaklığı 1, sonra uzaklığı 2 olan kelimeler gösterilir; kullanıcı seçim yaparsa hatalı tabloya eklenir. Uzaklığı 2 ve daha küçük kelime de yoksa kullanıcıya bulunamadığı bildirilir. Kelime hatalı tabloda varsa ekleme yapılmaz, doğru karşılığı tablodan okunup yazdırılır.
  - Ödev metnine göre uzaklığı 2 olan kelimeler yalnız uzaklığı 1 olan kelime yoksa önerilir. Bu durumda yalnız sınır 2 ile çağrı yapılıp uzaklığı 2'ye eşit ya da küçük kelimelerin listelenmesi de aynı amaca hizmet eder.
- **Levenshtein örneği HELL ve HELLO** (ekrandan, 00:30:00): sütunlar HELLO, satırlar HELL. Son satır 4, 3, 2, 1, 0, 1 olur; sonuç 1'dir (bir O eklenir).
- **Erken durdurma.** Levenshtein tablosunda bir köşegen boyunca değer azalmaz. Bu yüzden sonuç gözüne giden köşegende sınırı aşan bir değer görülürse sonuç da sınırı aşar ve hesap kesilebilir. ARTIST (satırlar) ve FRIED (sütunlar) tablosunda bu köşegen $(1,0),(2,1),(3,2),(4,3),(5,4),(6,5)$ gözlerinden geçer; 4. satırda (4,3) gözü hâlâ 2'dir, 5. satırda (5,4) gözü 3 olur ve orada durulabilir. Sonuç 4'tür. Bir öğrencinin önerdiği satır kontrolü (bir satırın bütün değerleri sınırdan büyükse dur) da geçerli bir ölçüttür; bu örnekte o da 5. satırda durur.

| | | F | R | I | E | D |
|---|---|---|---|---|---|---|
| | 0 | 1 | 2 | 3 | 4 | 5 |
| A | 1 | 1 | 2 | 3 | 4 | 5 |
| R | 2 | 2 | 1 | 2 | 3 | 4 |
| T | 3 | 3 | 2 | 2 | 3 | 4 |
| I | 4 | 4 | 3 | 2 | 3 | 4 |
| S | 5 | 5 | 4 | 3 | 3 | 4 |
| T | 6 | 6 | 5 | 4 | 4 | 4 |

  - İlk dört satır ekrandandır (00:45:00); son iki satır ve köşegen monotonluğu python ile doğrulandı. Derste S satırı 5, 4, 3, 3, 4 olarak dolduruldu (ekrandan, 00:45:00); son satır tamamlanmadı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
