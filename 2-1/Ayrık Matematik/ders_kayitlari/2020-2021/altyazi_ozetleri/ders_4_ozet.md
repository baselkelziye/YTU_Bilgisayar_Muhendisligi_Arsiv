# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 30 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl anlatım yaklaşık 00:08:00'de başlar. Kaydın başı yoklama, bayram tebriği ve sohbettir.
  - Bu hafta kitabın 4. bölümüne başlandı. Bölüm uzun olduğu için iki haftaya yayılacak.
- Kümeler (sets)
  - Kümenin gösterimi: liste gösterimi ve tanım (set-builder) gösterimi.
  - Sonlu (finite) ve sonsuz (infinite) kümeler, boş küme (null set), evrensel küme (universal set).
  - Eleman sayısı (cardinality).
  - Alt küme (subset), kümelerin eşitliği, öz alt küme (proper subset).
  - Kuvvet kümesi (power set) ve kuvvet kümesini bulan algoritma (bonus sorusu).
- Küme işlemleri ve Venn şemaları
  - Birleşim (union), kesişim (intersection), ayrık kümeler (disjoint sets), tümleyen (complement), fark (difference), simetrik fark (symmetric difference).
  - Küme işlemlerinin özellikleri ve Bool cebriyle benzerliği.
  - Kartezyen çarpım (Cartesian product).
  - Genelleştirilmiş birleşim ve kesişim.
  - Birleşimin eleman sayısı ve içerme-dışarma (inclusion-exclusion): iki ve üç küme.
  - Küme işlemlerinin bit dizisiyle (0/1 dizisi) programlanması.
- Diziler (sequences)
  - Artan (increasing) ve azalan (decreasing) diziler, alt dizi (subsequence).
  - Toplam ($\Sigma$) ve çarpım ($\Pi$) gösterimi.
- Dizgiler (strings) ve düzenli ifadelere (regular expressions) giriş
- Sayı sistemleri: ikilik (binary), sekizlik (octal), onaltılık (hexadecimal)
  - Taban dönüşümleri, ikilik ve onaltılık toplama.

## Hocanın Özellikle Vurguladığı Kısımlar

- Derste görülen her kavram, başka bir problemin çözümünde kullanılabilir. Hoca bunu iki örnekle gösterdi:
  - Kuvvet kümesini, doğruluk tablosu (0'dan $2^n - 1$'e ikilik sayma) ile üretmek.
  - Küme birleşimini ve kesişimini, 0/1 dizileri üzerinde OR ve AND ile bulmak.
- Ödevde "kesişimi bul" deniyorsa hazır `intersection` / `union` kütüphanesini kullanan sıfır alır.
  - Bu işlem büyük bir problemin küçük bir alt adımıysa kütüphane kullanılabilir. Hoca bunu "araba yaparken tekerleği yeniden icat etmeyin; ama sizden tekerlek isteniyorsa kendiniz yapın" diye anlattı.
- Kümenin adı büyük harf, elemanları küçük harfle yazılır. Küme sembolleri büyük-küçük harfe duyarlıdır: $X$ ile $x$ farklıdır.
- $\emptyset \neq \{\emptyset\}$. Birincisi boş kümedir. İkincisi tek elemanlı bir kümedir; elemanı boş kümedir.
- $|A|$ gösterimi küme için mutlak değer değil, eleman sayısıdır. Hoca, vizede bunu mutlak değer sanıp itiraz eden bir öğrenciyi örnek verdi.
- Kartezyen çarpımda değişme özelliği yoktur: $A \times B \neq B \times A$.
- Dersi derste dinleyin. Her şeyi vizeden önceki geceye bırakmak çok zorlar.
- Hoca derse geç gelinmesinden ve sessiz kalınmasından rahatsız olduğunu söyledi. Derse sesli katılım bekliyor.
- Hoca, öğrencilere işlerinin dışında mutlaka bir hobi ya da ilgi alanı edinmelerini, ileride ilgilendikleri alanda çevrim içi kurslar almalarını önerdi.

## Kısa Tekrar Notları

- Tanım gösterimi: $A = \{x \mid x = 2k+1,\ k \in \mathbb{Z},\ 0 \le k \le 3\} = \{1, 3, 5, 7\}$.
- Kapalı aralık $[0, 4]$ uçları içerir. Açık aralık $(0, 4)$ uçları içermez.
- Eleman sayısı: $|A|$ ya da $s(A)$. Tekrar eden eleman bir kez sayılır: $|\{3,3,3\}| = 1$.
- $|\{\emptyset, 2, \{1, 2\}\}| = 3$. İç kümenin elemanları ayrıca sayılmaz.
- $X \subseteq Y$: $X$'in her elemanı $Y$'dedir. $\emptyset$ her kümenin alt kümesidir.
- $X = Y \iff X \subseteq Y \text{ ve } Y \subseteq X$.
- $X \subset Y$ (öz alt küme): $X \subseteq Y$ ve $X \neq Y$.
- $|X| = n$ ise $|\mathcal{P}(X)| = 2^n$.
- Birleşim OR'a, kesişim AND'e, simetrik fark XOR'a karşılık gelir.
- $X - Y = \{x \mid x \in X \text{ ve } x \notin Y\}$.
- $X \oplus Y = (X - Y) \cup (Y - X)$.
- $|A \cup B| = |A| + |B| - |A \cap B|$.
- $|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$.
- $|A \times B| = |A| \cdot |B|$.
- Düzenli ifadede `a*`: hiç ya da istenen kadar `a`. `a+`: en az bir `a`.
- Onluk sayıyı $b$ tabanına çevirmek için $b$'ye art arda böl, kalanları sondan başa oku.
- $b$ tabanındaki sayıyı onluğa çevirmek için her basamağı $b$'nin kuvvetiyle çarpıp topla.

## Detaylı Açıklamalar

### Kümelerin gösterimi ve eleman sayısı

Küme, ayrık nesnelerden oluşan topluluktur. Liste gösterimi $A = \{1, 3, 5, 7\}$ biçimindedir. Kitaplarda ve akademik metinlerde tanım gösterimi tercih edilir:

$$A = \{x \mid x = 2k+1,\ k \in \mathbb{Z},\ 0 \le k \le 3\}$$

Bir öğrenci $k$'nin tam sayı olduğunun yazılması gerektiğini hatırlattı. Hoca da bunu doğruladı. Bu şart yazılmazsa $k$ gerçel sayı da olabilir ve küme sonsuz olur.

Sonlu ve sonsuz küme örnekleri:

- $B = \{x \mid x \in \mathbb{Z},\ 1 \le x \le 4\}$ sonludur.
- $\mathbb{Z}$ ve $S = \{x \mid x \in \mathbb{R},\ 0 \le x \le 4\}$ sonsuzdur.
- Doğal sayılar sayılabilir (countable) sonsuzdur. Gerçel sayılar sayılamaz (uncountable). 1 ile 2 arasında bile sonsuz gerçel sayı vardır.

Derste sorulan eleman sayıları:

| Küme | Eleman sayısı |
| :-- | :-: |
| $\{a, b, c\}$ | 3 |
| $\{x \in \mathbb{N} \mid 1 \le x \le 9\}$ | 9 |
| $\{3, 3, 3, 3, 3\}$ | 1 |
| $\emptyset$ | 0 |
| $\{\emptyset, 2, \{1, 2\}\}$ | 3 |

### Alt küme ve eşitlik

$X \subseteq Y$ ifadesinde açık uç büyük kümeye bakar: "$Y$, $X$'i kapsar". Matematiksel tanım:

$$X \subseteq Y \iff \forall x\ (x \in X \Rightarrow x \in Y)$$

Bir öğrenci, eşitlik tanımında neden iki yönün de yazıldığını sordu. Hocanın açıklaması: eşitliği alt küme kavramıyla tanımlamak için iki yön AND ile bağlanmalıdır. Yalnız $X \subseteq Y$ yazmak eşitliği garanti etmez; $Y$'de $X$'te olmayan elemanlar da olabilir.

### Kuvvet kümesi ve bonus sorusu

$X = \{1, 2, 3\}$ için:

$$\mathcal{P}(X) = \{\emptyset, \{1\}, \{2\}, \{3\}, \{1,2\}, \{1,3\}, \{2,3\}, \{1,2,3\}\}$$

Diğer örnekler:

- $\mathcal{P}(\emptyset) = \{\emptyset\}$, 1 elemanlı.
- $\mathcal{P}(\{a\}) = \{\emptyset, \{a\}\}$.
- $\mathcal{P}(\{\emptyset, \{\emptyset\}\}) = \{\emptyset, \{\emptyset\}, \{\{\emptyset\}\}, \{\emptyset, \{\emptyset\}\}\}$, 4 elemanlı.

**Bonus sorusu (ilk 5 kişi, aynı gün gönderilmeli):** Verilen bir kümenin kuvvet kümesini bulan algoritmayı en az kod satırıyla yazın.

- Fikir: $n$ elemanlı küme için 0'dan $2^n - 1$'e kadar sayıları ikilik tabana çevir.
- Her sayının 1 olan bitleri, o alt kümede bulunan elemanları gösterir. Hepsi 0 ise boş kümedir.
- $n = 3$ için: `000` → $\emptyset$, `001` → $\{3\}$, `010` → $\{2\}$, `011` → $\{2,3\}$, ..., `111` → $\{1,2,3\}$.
- Teslim: kodu ve ekran çıktısının görüntüsünü bir A4'e koyun. Adınızı, soyadınızı ve numaranızı yazın, hocaya gönderin.

```python
def kuvvet_kumesi(eleman):
    n = len(eleman)
    return [[eleman[i] for i in range(n) if k >> (n - 1 - i) & 1] for k in range(2 ** n)]

print(kuvvet_kumesi([1, 2, 3]))
# [[], [3], [2], [2, 3], [1], [1, 3], [1, 2], [1, 2, 3]]
```

### Küme işlemleri

| İşlem | Tanım | Bool karşılığı |
| :-- | :-- | :-- |
| Birleşim $X \cup Y$ | $\{x \mid x \in X \lor x \in Y\}$ | OR |
| Kesişim $X \cap Y$ | $\{x \mid x \in X \land x \in Y\}$ | AND |
| Tümleyen $\overline{X}$ | $\{x \in U \mid x \notin X\}$ | NOT |
| Fark $X - Y$ | $\{x \mid x \in X \land x \notin Y\}$ | $X \land \neg Y$ |
| Simetrik fark $X \oplus Y$ | $(X - Y) \cup (Y - X)$ | XOR |

Örnekler:

- $X = \{\text{Ayşe}, \text{Lale}, \text{Zeynep}\}$, $Y = \{\text{Lale}, \text{Deniz}\}$: $X \cup Y = \{\text{Ayşe}, \text{Lale}, \text{Zeynep}, \text{Deniz}\}$, $X \cap Y = \{\text{Lale}\}$.
- $X = \{1,2,3,4,5\}$, $Y = \{2,5,7,10\}$: $X - Y = \{1, 3, 4\}$.
- $\overline{\emptyset} = U$, $\overline{U} = \emptyset$.

**Ayrık kümeler.** $X \cap Y = \emptyset$ ise $X$ ve $Y$ ayrıktır.

- Tek sayılar ve çift sayılar ayrıktır.
- Tek sayılar ve asal sayılar ayrık değildir (örneğin 3).
- Çift sayılar ve asal sayılar ayrık değildir. Tek ortak eleman 2'dir.

**Özellikler.** Bool cebrindeki özdeşliklerin hepsinin küme karşılığı vardır:

- Birleşme, değişme, dağılma.
- $A \cap U = A$, $A \cup \emptyset = A$.
- $A \cup \overline{A} = U$, $A \cap \overline{A} = \emptyset$.
- $A \cup A = A$, $A \cap A = A$.
- $A \cup U = U$, $A \cap \emptyset = \emptyset$.
- Yutma: $A \cup (A \cap B) = A$, $A \cap (A \cup B) = A$. Hoca bunu Venn şemasında taramayla gösterdi.
- $\overline{\overline{A}} = A$.
- De Morgan: $\overline{A \cup B} = \overline{A} \cap \overline{B}$, $\overline{A \cap B} = \overline{A} \cup \overline{B}$.

### Kartezyen çarpım

$$A \times B = \{(a, b) \mid a \in A,\ b \in B\}$$

$A = \{\text{Celal}, \text{Lale}, \text{Lamia}\}$, $B = \{\text{Banu}, \text{Vedat}\}$ ise $A \times B$, 6 sıralı ikiliden oluşur: (Celal, Banu), (Celal, Vedat), (Lale, Banu), (Lale, Vedat), (Lamia, Banu), (Lamia, Vedat).

$B \times A$'nın da 6 elemanı vardır ama ikililerin sırası terstir. Bu yüzden iki küme eşit değildir.

### İçerme-dışarma

Soru: Bölümde 217 öğrenci var. 157 kişi 125 kodlu dersi, 145 kişi 173 kodlu dersi alıyor. 98 kişi iki dersi de alıyor. Kaç kişi iki dersten hiçbirini almıyor?

- $|A \cup B| = 157 + 145 - 98 = 204$
- Hiçbirini almayan: $217 - 204 = 13$

Venn şemasında: yalnız birinci dersi alan $157 - 98 = 59$, yalnız ikinci dersi alan $145 - 98 = 47$.

Üç kümede önce üç kümenin eleman sayıları toplanır. İkili kesişimler çıkarılır. Ortadaki $A \cap B \cap C$ bölgesi üç kez eklenip üç kez çıkarıldığı için bir kez geri eklenir.

### Küme işlemlerini bit dizisiyle programlama

Evrensel küme $U = \{x_1, \dots, x_6\}$ olsun. Her küme 6 bitlik bir diziyle gösterilir: eleman varsa 1, yoksa 0.

| | $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | $x_6$ |
| :-- | :-: | :-: | :-: | :-: | :-: | :-: |
| $A$ | 1 | 0 | 1 | 0 | 1 | 1 |
| $B$ | 0 | 1 | 1 | 0 | 0 | 1 |
| $A \cup B$ (OR) | 1 | 1 | 1 | 0 | 1 | 1 |
| $A \cap B$ (AND) | 0 | 0 | 1 | 0 | 0 | 1 |

Sonuç: $A \cup B = \{x_1, x_2, x_3, x_5, x_6\}$, $A \cap B = \{x_3, x_6\}$.

Bu yöntem, her elemanı diğer kümede tek tek aramaktan çok daha kısadır. Hoca alternatif olarak kümeleri önce sıralamayı da anlattı. Sıralı kümelerde aranan eleman geçildiği an arama durdurulabilir. Ama sıralamanın da bir maliyeti vardır (örneğin quicksort).

Bir öğrenci, dizinin gözlerine 0/1 yazmak için de bir kez arama yapmak gerekmez mi diye sordu. Hocanın cevabı: elemanın değeri doğrudan dizi indisi olarak kullanılır. 3 elemanı için dizinin 3. gözüne 1 yazılır; arama gerekmez.

### Diziler, toplam ve çarpım

- Dizi (sequence), sıralı bir listeyi gösteren ayrık yapıdır: $s_1, s_2, s_3, \dots$
- $s_n = 1/n$: $1, 1/2, 1/3, \dots$. $s_n = n^2 + 1$: $2, 5, 10, \dots$
- Artan: her $n$ için $s_n \le s_{n+1}$. Azalan: her $n$ için $s_n \ge s_{n+1}$.
  - $s_n = 4 - 2n$: $2, 0, -2, -4, \dots$ azalan.
  - $s_n = 2n - 1$: $1, 3, 5, 7, \dots$ artan.
- Alt dizi: elemanlar ana diziden alınır ve **sıra korunur**.
  - $1, 2, 3, 4, 5$ dizisinden $1, 3, 5$ alt dizidir. $1, 5, 3$ alt dizi değildir.
  - $t_n = 2n$ ($2, 4, 6, \dots$), $s_n = n$ dizisinin alt dizisidir.

Derste çözülen toplam ve çarpım soruları (Python ile kontrol edildi):

- $\sum_{k=4}^{8} (-1)^k = 1 - 1 + 1 - 1 + 1 = 1$
- $\sum_{i=1}^{4} \sum_{j=1}^{3} ij$: içteki toplam $i + 2i + 3i = 6i$. Sonra $6(1+2+3+4) = 60$.
- $\prod_{i=1}^{3} 2i = 2 \cdot 4 \cdot 6 = 48$

### Dizgiler ve düzenli ifadeler

$X = \{a, b, c\}$ alfabesi üzerinde $\alpha = bbaccc = b^2ac^3$ bir dizgidir. Uzunluğu $|\alpha| = 6$'dır. Eleman içermeyen dizgiye boş dizgi (null string) denir ve $\lambda$ ile gösterilir.

İki dizginin birleştirilmesi (concatenation) $\alpha\beta$ yazılır. Uzunluğu $|\alpha\beta| = |\alpha| + |\beta|$'dır.

Düzenli ifadeler (regex), çok sayıda dizgiyi tek bir kalıpla tanımlar. Örnek kullanım: web sayfalarında farklı biçimlerde yazılmış e-posta adreslerini ya da telefon numaralarını bulmak.

- `a*`: hiç ($\lambda$) ya da istenen kadar `a`.
- `a+`: en az bir `a`.
- $bbaccc$ için kalıp: `b+ac+`.

Örnek: $\alpha_1 = a$, $\alpha_2 = baa$, $\alpha_3 = baccc$ dizgilerinin hepsini üreten kalıp `b*a+c*` olur.

| Dizgi | `b*a+c*` ile üretilir mi? | Neden |
| :-- | :-: | :-- |
| $a$ | Evet | `b` yok, bir `a`, `c` yok |
| $baa$ | Evet | bir `b`, iki `a` |
| $baccc$ | Evet | bir `b`, bir `a`, üç `c` |
| $cb$ | Hayır | `a` yok, sıra da yanlış |
| $acb$ | Hayır | sondaki `b` kalıpta yok |

`(a*b*c*)*` kalıbı alfabedeki bütün dizgileri üretir. Hoca bunun "tembel" bir çözüm olduğunu, genelde verilen kurallara uyan dar bir kalıp istendiğini söyledi.

### Sayı sistemleri

- Günlük hayatta 10 tabanı, lojikte 2 tabanı, assembly ve makine dilinde hata ayıklarken 16 tabanı kullanılır.
- Bir sayıdaki her rakam tabandan küçük olmalıdır. $45238$'de 8 olduğu için bu sayı en az 9 tabanındadır.
- $45238_{10} = 4 \cdot 10^4 + 5 \cdot 10^3 + 2 \cdot 10^2 + 3 \cdot 10 + 8$.

Dönüşüm örnekleri (Python ile kontrol edildi):

- $1101011_2 = 64 + 32 + 8 + 2 + 1 = 107_{10}$
- $73_{10}$: 2'ye art arda bölünür. Kalanlar sondan başa okununca $1001001_2$.
- $17_8 = 15_{10} = 1111_2$. Önce 10 tabanına, sonra 2 tabanına geçilir.
- $3A0B_{16} = 3 \cdot 16^3 + 10 \cdot 16^2 + 0 \cdot 16 + 11 = 12288 + 2560 + 0 + 11 = 14859_{10}$
- $2345_{10}$: $2345 = 146 \cdot 16 + 9$, $146 = 9 \cdot 16 + 2$. Sonuç $929_{16}$.

İkilik toplama: $1 + 1 = 10_2$ (toplam 0, elde 1). $1 + 1 + 1 = 11_2$ (toplam 1, elde 1).

Onaltılık rakamlar: A = 10, B = 11, C = 12, D = 13, E = 14, F = 15.

Onaltılık toplama: $23A_{16} + 8F_{16}$:

- $A + F = 10 + 15 = 25 = 16 + 9$. 9 yaz, elde 1.
- $3 + 8 + 1 = 12 = C$.
- $2$ aşağı iner.
- Sonuç: $2C9_{16}$.

### Ders sonrası notlar

- Slayttaki genelleştirilmiş birleşim ve kesişim gösterimi $\sum_{i=1}^n A_i$ ve $\prod_{i=1}^n A_i$ biçimindedir. Hoca bunu Bool cebrindeki "OR = toplama, AND = çarpma" benzetmesiyle açıkladı. Standart gösterim $\bigcup_{i=1}^{n} A_i$ ve $\bigcap_{i=1}^{n} A_i$'dir. Sınavda ve kaynaklarda bu gösterimle karşılaşırsınız.
- Hoca $s_n = 2n - 1$ dizisi için bir yerde "azalan" dedi. Doğrusu artandır: $1, 3, 5, \dots$ Slaytta da "artan" yazıyor.
- Altyazıda azalan dizi örneği "$4 - n$" diye geçiyor. Slayttaki dizi $s_n = 4 - 2n$'dir: $2, 0, -2, -4, \dots$
- Hoca kümelerin eşitliğini bir yerde "eleman sayıları eşit demektir" diye açıkladı. İki kümenin eşit olması için aynı elemanlara sahip olmaları gerekir. Eleman sayısının eşit olması yetmez: $\{1, 2\}$ ile $\{3, 4\}$ eşit değildir.
- Öz alt küme anlatılırken yönler bir an karıştı. Doğrusu: $X \subset Y$ ise $X \subseteq Y$ ve $X \neq Y$'dir. Yani $Y$'de $X$'te olmayan en az bir eleman vardır.
- Üç kümede içerme-dışarma için hoca ortadaki bölgenin "iki kere gittiğini" söyledi. Daha kesin sayım: bu bölge önce 3 kez eklenir, ikili kesişimlerle 3 kez çıkarılır. Hiç sayılmamış olur. Bu yüzden $|A \cap B \cap C|$ bir kez eklenir.
- $A \times B \neq B \times A$ genel kuraldır. İstisnalar: $A = B$ ise ya da kümelerden biri boşsa iki çarpım eşittir.
- Hoca regex anlatırken yıldızın "hiç" durumunu "sigma, lambda, boş küme" diye andı. Doğrusu: `a*` boş dizgiyi ($\lambda$ ya da $\varepsilon$) içerir. Boş dizgi ile boş küme ($\emptyset$) farklı şeylerdir.
- $3A0B_{16}$ dönüşümünde altyazıda "2506" geçiyor. Slayttaki doğru değer $10 \cdot 16^2 = 2560$'tır.
- $1101011_2$ açılımında hoca bir basamağı "2'nin 4. kuvveti" diye okudu. Doğru sıra $2^0, 2^1, 2^2, \dots, 2^6$'dır. Sonuç 107 doğrudur.
- Sekizlik taban yalnız fen alanlarında kullanılmaz. Örneğin Unix dosya izinleri (`chmod 755`) sekizlik yazılır.
- İçerme-dışarma sorusu (13 öğrenci), toplam/çarpım soruları (1, 60, 48), taban dönüşümleri ve onaltılık toplama ($2C9_{16}$) Python ile doğrulandı. Kuvvet kümesi kodu çalıştırılıp çıktısı kontrol edildi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
