# Ders 19 Çalışma Özeti

## Genel Konular

- Dinamik programlamanın tekrarı ve 0/1 sırt çantası (knapsack) problemi
  - Dinamik programlamada ana problem çözülebilir alt problemlere bölünür; alt problemlerin sonuçları bir dizi ya da matriste saklanır ve sonraki adımlarda yeniden kullanılır. Özyinelemeden farkı, ara sonuçların bir yerde tutulup tekrar hesaplanmamasıdır.
  - Her dinamik programlama çözümünde bir yineleme (recurrence) bağıntısı kurulur; başlangıç (initialization) durumları ve farklı durumlar (örneğin eşya kapasiteyi aşıyorsa) bu bağıntıda ayrı ayrı yazılır.
  - Kaba kuvvetle (brute force) bütün eşya alt kümelerini denemek üstel zaman ister; tablo doldurularak bu önlenir.
  - Önceki dersten tekrar edilen bağıntı (ekrandan, 00:05:00):
    - $P[0,j] = P[i,0] = 0$
    - $P[i,w] = P[i-1,w]$, eğer $w_i > w$ ise (eşya alınmaz)
    - $P[i,w] = \max\{v_i + P[i-1, w-w_i],\ P[i-1,w]\}$, aksi halde
  - Örnek (ekrandan, 00:05:00): ağırlıklar 2, 1, 3, 2; değerler 12, 10, 20, 15; kapasite 5. Tablonun son gözü en büyük kazancı verir: 37.
- Düzenleme uzaklığı (edit distance) ve Levenshtein algoritması
  - İki kelimenin (ya da dizinin) birbirine ne kadar benzediğini ölçer. Kullanım alanları: yazım denetimi (sözlükte olmayan bir kelimeye en yakın kelimeleri önermek), arama motorlarının "bunu mu demek istediniz" önerisi, biyoinformatikte birebir aynı olmayan DNA dizilerinin karşılaştırılması, ses tanıma.
  - Ekrandaki örnekler (ekrandan, 00:15:00): "elm" için "elma" ve "elim" önerilir; "algoritm" yazılınca bir H eksik, "algoritma" yazılınca hem fazladan A var hem H eksik.
  - Snowy ile Sunny arasında birden fazla dönüşüm vardır: bir hizalamada 3 işlem (delete, change, insert), başka bir hizalamada 5 işlem gerekir. Aranan, en küçük (minimum) düzenleme uzaklığıdır.
  - İki karakter karşılaştırılınca dört durum vardır: aynıdır (copy), birinden silinmiştir (delete), birine eklenmiştir (insert), değiştirilmiştir (change).
- Edit distance için alt problem ve yineleme bağıntısı
  - $X[1..n]$ ve $Y[1..m]$ için alt problem $ED[i,j]$: $X$'in ilk $i$, $Y$'nin ilk $j$ karakteri arasındaki minimum uzaklık. Sonuç $ED[n,m]$ gözündedir; sonuçlar $(n+1)\times(m+1)$ bir matriste tutulur.
  - Bağıntı (ekrandan, 00:40:00): $ED[i,j] = \min\{ED[i-1,j]+1,\ ED[i,j-1]+1,\ ED[i-1,j-1]+diff(x_i,y_j)\}$; $diff = 0$ eğer $x_i = y_j$, aksi halde 1.
  - Başlangıç: $ED[i,0] = i$, $ED[0,j] = j$.
  - Bu derste adlandırma $X$'e göre yapılır: yukarıdan gelmek ($ED[i-1,j]$) "insertion" ($x_i$ fazladan eklenmiş), soldan gelmek ($ED[i,j-1]$) "deletion" ($y_j$'nin karşılığı $X$'ten silinmiş), çaprazdan gelmek "substitute" (copy ya da change).
- Örnek: ED("MATHS", "ARTS") (ekrandan, 00:45:00 ve 00:55:00)
  - İlk satır 0, 1, 2, 3, 4; ilk sütun 0, 1, 2, 3, 4, 5. Tablo doldurulunca sonuç 3 bulunur.
  - Geri izleme (traceback) $ED[n,m]$'den başlar ve geldiği gözlere doğru geri gidilir. Bir hizalama (ekrandan, 01:15:00): `M A _ T H S` / `_ A R T _ S`. Birden fazla geri izleme yolu, aynı uzaklıkta farklı hizalamalar verir.
  - Zaman karmaşıklığı $O(n \cdot m)$, yer karmaşıklığı $O(n \cdot m)$; $n \approx m$ ise $O(n^2)$.
- En uzun ortak alt dizi (Longest Common Subsequence, LCS)
  - Alt dizi (subsequence): kelimeden harfler, orijinal sıraları korunarak seçilir. Örnek (ekrandan, 01:25:00): "yakamoz" kelimesinden yak, yaka, yama, yaz.
  - LCS, iki dizide de aynı sırayla geçen en uzun alt dizidir. DNA örneği (ekrandan, 01:20:00): X = ATCTGAT, Y = TGCATA; ortak alt diziler TCTA ve TGAT (uzunluk 4).
  - Kaba kuvvet: $X$'in bütün alt dizileri ($2^m$ tane) denenir, üstel zaman. Dinamik programlamayla $O(n \cdot m)$.
  - Bağıntı (ekrandan, 01:35:00): $LCS[i,j] = 0$ eğer $i=0$ ya da $j=0$; $LCS[i-1,j-1]+1$ eğer $x_i = y_j$; $\max\{LCS[i,j-1], LCS[i-1,j]\}$ eğer $x_i \ne y_j$.
  - Örnek: X = BACDB, Y = BDCB için LCS uzunluğu 3; ortak alt diziler BCB ve BDB.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hangi işlemin yapıldığını tek karaktere bakarak bilemeyiz
  - $x_i \ne y_j$ olduğunda farkın insert, delete ya da change'den hangisinden geldiği yalnız o karakterlere ya da kelime uzunluklarına bakarak anlaşılamaz. Bu yüzden üç seçeneğin en küçüğü alınır; önemli olan minimum maliyettir.
- Karakterler eşitse yalnız çaprazdan gelinir
  - $x_i = y_j$ ise bir önceki durum $ED[i-1,j-1]$'dir ve maliyet 0 eklenir; yukarıdan ya da soldan gelmek 1 maliyet ekler, daha büyük olur.
- Başlangıç durumları unutulmamalı
  - Değerler üst üste eklenerek gidildiği için ilk satır ve ilk sütun doğru yazılmalıdır (edit distance'ta $i$ ve $j$, LCS'te 0).
- Yineleme bağıntısını kurmak pratik ister
  - Sınavlarda "yineleme bağıntısını yazın" diye sorulan şey budur. Hoca, bağıntıyı kurmayı öğrenmek için çok sayıda örnek çözmeyi önerdi.
- Geri izleme için iki yol
  - Matris doldurulurken her gözün nereden geldiği (ok) saklanabilir ya da sonradan değerlere bakılarak hesaplanabilir; hoca kendi tercihinin okları saklamak olduğunu söyledi.

## Kısa Tekrar Notları

- Dinamik programlama = alt problemlere bölme + sonuçları tabloda saklama + yineleme bağıntısı.
- Edit distance: $ED[i,j] = \min\{ED[i-1,j]+1,\ ED[i,j-1]+1,\ ED[i-1,j-1]+diff\}$, $ED[i,0]=i$, $ED[0,j]=j$.
- ED(SNOWY, SUNNY) = 3; ED(MATHS, ARTS) = 3.
- Yukarı = insertion, sol = deletion, çapraz = copy/change (bu dersteki $X$'e göre adlandırma).
- Edit distance zaman ve yer: $O(nm)$.
- Alt dizide harflerin sırası korunur, harflerin bitişik olması gerekmez.
- LCS: eşitse $LCS[i-1,j-1]+1$, değilse $\max\{LCS[i,j-1], LCS[i-1,j]\}$; ilk satır ve sütun 0.
- LCS(BACDB, BDCB) = 3 (BCB, BDB). LCS'nin kaba kuvvet çözümü $2^m$, DP çözümü $O(nm)$.

## Detaylı Açıklamalar

- **Sırt çantası tekrarı.** Ders, önceki derste çözülen 0/1 sırt çantası probleminin hatırlatılmasıyla başladı. Bir hırsız, sırt çantasının taşıyabileceği ağırlığı aşmadan en değerli eşyaları almak ister. Bütün eşya kombinasyonlarını denemek üstel sayıda olasılık demektir. Bunun yerine $P[i,w]$ tablosu doldurulur: ilk $i$ eşya ve $w$ kapasite için en büyük kazanç. Eşya kapasiteden ağırsa alınamaz ve yukarıdaki değer kopyalanır; değilse "alırsam" ($v_i + P[i-1,w-w_i]$) ve "almazsam" ($P[i-1,w]$) seçeneklerinin büyüğü yazılır. Ekrandaki örnekte (ağırlık/değer: 2/12, 1/10, 3/20, 2/15; kapasite 5) son satır 0, 10, 15, 25, 30, 37'dir ve en büyük kazanç 37'dir (python ile doğrulandı).
  - Ders sonrası not: hoca anlatırken en büyük kapasiteyi "4 kilo" olarak söyledi; ekrandaki tabloda kapasite sütunları 0'dan 5'e kadardır ve sonuç 37, kapasite 5 için bulunmuştur.
- **Edit distance problemi.** Yazım denetleyicisi, sözlükte olmayan bir kelime gördüğünde sözlükteki kelimelerle arasındaki uzaklığı hesaplar ve uzaklığı küçük olanları önerir. Bu yüzden her kelime çifti için en küçük uzaklık gerekir; örneğin bir eşik (threshold) belirlenip uzaklığı bu eşikten küçük kelimeler önerilebilir. Aynı fikir DNA dizilerinde birebir aynı olmayan ama en çok benzeyen diziyi bulmakta ve ses tanımada kullanılır. Veri yapılarında görülen string aramadan farkı, birebir eşleşmeyen dizilerin de karşılaştırılabilmesidir.
- **Dört durum.** Snowy ve Sunny hizalandığında (ekrandan, 00:15:00) bir hizalama `S _ N O W Y` / `S U N N _ Y` biçimindedir: U'nun karşılığı yok (delete), O ile N farklı (change), W'nin karşılığı yok (insert); uzaklık 3. Başka bir hizalama `_ S N O W _ Y` / `S U N _ _ N Y` beş işlem (D, C, I, I, D) gerektirir. İkisi de geçerli dönüşümlerdir, ama aranan en küçüğüdür. Karakterlerin eşit olması (copy) dördüncü durumdur ve maliyeti yoktur.
- **Alt problem.** $X$ = EXPONENTIAL ve $Y$ = POLYNOMIAL örneğiyle (ekrandan, 00:20:00) alt problemin, iki kelimenin baştan belli bir karaktere kadar olan parçalarının uzaklığı olduğu gösterildi. Örneğin $ED[4,3]$, EXPO ile POL arasındaki uzaklıktır. Satırlar $X$'in, sütunlar $Y$'nin karakterleridir ve $ED[n,m]$ cevabı verir.
- **Üç durumun alt problemleri** (ekrandan, 00:30:00 ve 00:40:00).
  - Case 1, insertion: $x_i$'nin karşılığı yoktur; alt problem $X[1..i-1]$ ile $Y[1..j]$, yani $ED[i-1,j]$.
  - Case 2, deletion: $y_j$'nin karşılığı yoktur; alt problem $X[1..i]$ ile $Y[1..j-1]$, yani $ED[i,j-1]$.
  - Case 3, change ya da copy: $x_i$ ile $y_j$ karşılaştırılmıştır; alt problem $ED[i-1,j-1]$, maliyet $diff(x_i,y_j)$.
  - EXPO ile POL'deki O ve L farklıdır; bunun insert, delete ya da change'den hangisi olduğu bilinemez. Bu yüzden üçünün en küçüğü alınır. Maliyetlerin hepsi 1 alındı; istenirse bir işleme daha büyük maliyet verilebilir.
- **MATHS ve ARTS örneği.** İlk satırda $X$ boşken $Y$'nin harfleri birer birer eklenir (0, 1, 2, 3, 4), ilk sütunda $Y$ boşken $X$'in harfleri (0, 1, ..., 5). Tablonun tamamı (python ile doğrulandı):

```text
        -  A  R  T  S
    -   0  1  2  3  4
    M   1  1  2  3  4
    A   2  1  2  3  4
    T   3  2  2  2  3
    H   4  3  3  3  3
    S   5  4  4  4  3
```

  - M ile A farklıdır; en küçük değer çaprazdan gelir: 0 + 1 = 1. A ile A eşittir; çaprazdan maliyetsiz gelinir: $ED[1,0] + 0 = 1$. T ile T eşittir: $ED[2,2] + 0 = 2$. Son gözde S ile S eşittir: $ED[4,3] + 0 = 3$.
  - Geri izleme (ekrandan, 01:15:00): sağ alttaki 3'ten çapraz (S=S), yukarı (H insert edilmiş), çapraz (T=T), sol (R'nin karşılığı silinmiş), çapraz (A=A), yukarı (M insert edilmiş). Hizalama `M A _ T H S` / `_ A R T _ S`. Bazı gözlere iki yerden gelinebildiği için başka hizalamalar da vardır; uzaklık her zaman 3'tür.
- **LCS.** Bir kelimenin alt dizisi, harflerin orijinal sıralarının artan olması koşuluyla seçilmesiyle elde edilir; harfler bitişik olmak zorunda değildir. İki dizinin en uzun ortak alt dizisi biyoinformatikte ve görüntü işlemede (örneğin hareket benzerliği bulmada) kullanılır. İki durum vardır: $x_i = y_j$ ise ortak bir karakter daha bulunmuştur ve $LCS[i-1,j-1]+1$ yazılır (ekrandan, 01:30:00; X = ACGT, Y = GT). Farklıysa ya $x_i$ ya $y_j$ ya da ikisi birden ortak dizinin parçası değildir; bu yüzden $LCS[i-1,j]$ ve $LCS[i,j-1]$'in büyüğü alınır. BACDB ile BDCB tablosu doldurulunca son göz 3 olur.
  - Ders sonrası not: hoca sonuçları anlatırken "ortak substring" dedi; doğrusu "ortak alt dizi (subsequence)"dur, çünkü BCB ve BDB her iki dizide de bitişik değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
