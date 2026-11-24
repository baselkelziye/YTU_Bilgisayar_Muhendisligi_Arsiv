# Ders 18 Genişletilmiş Notu: 0-1 Sırt Çantası Probleminin Dinamik Programlama ile Çözümü ve Seçilen Eşyaların Geri İzlenmesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Örnek Problem ve Kâr Matrisi
- 2. İki Durum: Eşyayı Almak ve Alamamak
- 3. Özyinelemeli Bağıntı
- 4. Tablonun Satır Satır Doldurulması
- 5. Seçilen Eşyaların Geri İzlenmesi
- 6. Tablonun Gücü: Bütün Kombinasyonlar ve Kaba Kuvvetle Karşılaştırma
- 7. Dinamik Programlamanın Kullanım Alanları
- Örnek Sorular
- Dersin Toparlaması

## 1. Örnek Problem ve Kâr Matrisi

Ders, bir önceki oturumda başlanan 0-1 sırt çantası (0-1 knapsack) probleminin devamıdır. Problemde bir hırsız, taşıyabileceği ağırlığı sınırlı bir sırt çantasına, toplam değeri en büyük olacak eşyaları koymak ister. "0-1" adı, her eşya için yalnız iki seçenek olmasından gelir: eşya ya alınır (select) ya da ondan vazgeçilir (abandon). Hoca konuyu kavramları gözümüzün önünde tutmak için baştan bir örnek üzerinden kurdu.

### 1.1 Örnek veriler

Tahtadaki örnek (ekrandan, 00:05:00):

| Eşya (item) | Ağırlık (weight, kg) | Değer (value, lira) |
|---|---|---|
| 1 | 2 | 12 |
| 2 | 1 | 10 |
| 3 | 3 | 20 |
| 4 | 2 | 15 |

Sırt çantasının kapasitesi $W = 5$ kg'dır.

### 1.2 Eşyaları sırayla eklemek

Hoca önce sayılarla düşünmeyi önerdi (ekrandan, 00:05:00):

- 1. eşya alınırsa: $\Sigma w = 2$, $\Sigma v = 12$.
- 2. eşya da alınırsa: $\Sigma w = 3$, $\Sigma v = 22$.
- 3. eşya da alınırsa: $\Sigma w = 6$, $\Sigma v = 42$.

**Soru (hocanın sınıfa sorusu):** 1 ve 2 çantadayken 3 alınabilir mi? **Cevap (bir öğrenci):** Alınamaz, çünkü toplam ağırlık 6 kg olur. Hoca bunu doğruladı: çanta en çok 5 kg taşır, bu yüzden 1 ve 2 varken 3 eklenemez.

### 1.3 Kâr matrisi $P$

Problemin çözümü bir kâr (profit) matrisi üzerinde yapılır. Satırlar eşyaları (item, $i$), sütunlar ağırlığı ($w$) gösterir. $P[i, w]$, "ilk $i$ eşya göz önündeyken toplam ağırlık $w$ kadar olabildiğinde elde edilebilecek en büyük kazanç"tır (maximum profit) (ekrandan, 00:15:00). Örneğin 2. satır ile 4. sütunun kesişimi, 1. ve 2. eşya göz önündeyken toplam 4 kg yük için en büyük kazancı gösterir.

**Soru:** 4 eşya varken neden 5 satırlı bir matris kuruluyor? **Cevap:** Sıfırıncı satır başlangıç durumunu gösterir. Değerler ekleye ekleye hesaplanacağı için, toplama işlemine sıfırdan başlanması gibi, bir başlangıç noktasının sıfır olması gerekir. Aynı şekilde sıfırıncı sütun da 0 kg'lık durumu gösterir. Hoca bu soruyu "güzel bir soru" diye karşıladı.

## 2. İki Durum: Eşyayı Almak ve Alamamak

### 2.1 Case 1: hırsız $i$. eşyayı alır

Hırsız $i$. eşyayı alırsa yeni durum, eşya alınmadan önceki duruma eşyanın değerinin eklenmesiyle bulunur (ekrandan, 00:10:00):

$$P(i, w) = P(i-1,\, w - w_i) + v_i$$

Buradaki terimlerin anlamı şöyledir:

- $i-1$: eşya alınmadan önceki satır, yani bir önceki eşyaya kadar olan durum.
- $w - w_i$: eşya alınmadan önceki ağırlık. Eşya henüz alınmadığı için onun ağırlığı yoktur; eşya eklenince ağırlık $w$ olur.
- $v_i$: eklenen eşyanın değeri.

Hocanın örneği: 1. eşya alınmışken çantada 2 kg yük ve 12 lira kazanç vardır. 2. eşya (1 kg, 10 lira) eklenince 3 kg ve 22 lira olur. Bağıntıyla:

$$P(2, 3) = P(1,\, 3 - 1) + v_2 = P(1, 2) + 10 = 12 + 10 = 22$$

Hoca aynı mantığı, kapasite yetseydi 3. eşya için de gösterdi (ekrandan, 00:10:00): $P(3, 6) = P(2, 3) + v_3$. 3. eşya 3 kg olduğu için, onu eklemeden önceki ağırlık $6 - 3 = 3$ kg'dır ve bu durumdaki kazanca 20 lira eklenir. Altıncı bir sütun olsaydı (örneğin kapasite 10 kg olsaydı) bu hücre böyle hesaplanacaktı.

### 2.2 Eşyanın alınamaması

Eşya alınamıyorsa bir önceki durumda kalınır; yapılabilecek bir şey yoktur. Örneğin 1 ve 2 çantadayken 3. eşya alınamadığı için 2. satırdaki durum korunur. Bir eşyanın alınamamasının nedeni, ağırlığının kalan kapasiteden büyük olmasıdır. Hocanın örneği: kapasite 5 kg ve çantada 3 kg yük varsa, eklenecek eşya en çok 2 kg olabilir; 8 kg'lık bir eşya alınamaz. Tablo dilinde bu koşul $w_i > w$ diye yazılır ve o zaman $P[i, w] = P[i-1, w]$ olur.

## 3. Özyinelemeli Bağıntı

İki durum ve başlangıç koşulu birleşince özyinelemeli bağıntı (recurrence) şöyle yazılır (ekrandan, 00:20:00):

$$P[i, w] = \begin{cases} 0 & i = 0 \text{ ya da } w = 0 \\ P[i-1, w] & w_i > w \\ \max\{v_i + P[i-1, w - w_i],\; P[i-1, w]\} & \text{aksi halde (otherwise)} \end{cases}$$

Tahtada ilk satır "$P[0, j] = 0$, $P[i, 0] = 0$ if $i = 0$, $j = 0$" biçiminde yazıldı: sıfırıncı satır ve sıfırıncı sütun sıfırlanır.

Üçüncü satır dersin en önemli noktasıdır. Ağırlık taşmıyorsa eşya otomatik olarak alınmaz; eşyayı almanın bir faydası varsa alınır, yoksa alınmaz. $\max$ içindeki ilk terim "alırsam", ikinci terim "almazsam" elde edilecek kazançtır.

> **Hocanın vurgusu:** Ağırlığı uyuyor diye bütün eşyaları alırsanız zarara girebilirsiniz. Belki 5 kg'lık tek bir eşya en yüksek kazancı sağlayacaktı. Alabiliyorum diye her şeyi almamak gerekir; alırsam ve almazsam kazançlarından hangisi büyükse o seçilir.

Hoca dersin sonunda bağıntının iki parçasını adlandırdı (ekrandan, 00:55:00): $w_i > w$ satırı "NOT TAKEN", yani eşyanın kesinlikle alınamadığı durumdur. "Otherwise" satırında ise karar verilir: $\max$'ın ilk terimi alınan (taken), ikinci terimi alınmayan (not taken) seçenektir.

## 4. Tablonun Satır Satır Doldurulması

Tablo, sıfırıncı satır ve sıfırıncı sütun sıfırlandıktan sonra satır satır doldurulur. Ara hesaplar tahtada yazıldığı gibi aşağıdadır (ekrandan, 00:25:00 - 00:45:00).

### 4.1 Birinci satır ($w_1 = 2$, $v_1 = 12$)

- $P(1, 1) = P(0, 1) = 0$. 1. eşya 2 kg olduğu için 1 kg'lık sınıra sığmaz; değer yukarıdan iner.
- $P(1, 2) = \max\{12 + P[0, 0],\; P[0, 2]\} = \max\{12, 0\} = 12$. Tahtada ilk terimin altına "alırsam", ikincisinin altına "almazsam" yazıldı.
- $P(1, 3) = \max\{12 + P[0, 1],\; P[0, 3]\} = \max\{12, 0\} = 12$.
- 4 ve 5 kg için de değer 12'dir. Bu satırda yalnız 1. eşya göz önünde olduğu için, ağırlık sınırı ne kadar artarsa artsın alınabilecek tek şey 12 liralık eşyadır.

$P(1, 3)$ hesabında neden $P[0, 1]$'e bakıldığı derste ayrıca açıklandı. Bir öğrenci sohbet kutusundan "0'dan 3'e neden geçtik" diye sordu. Hoca şöyle açıkladı: $P(1, 3)$, 1. eşyaya kadar ve toplam 3 kg için en büyük kazançtır. 1. eşya alınırsa çantadaki yük 2 kg artar; bu yüzden eşya alınmadan önceki duruma bakmak için 2 kg geriye gidilir ($3 - 2 = 1$) ve bir önceki satıra çıkılır. Bir önceki satır sıfırıncı satırdır, yani hiç eşya olmayan durum. Böylece $P[0, 1] + 12 = 12$ bulunur.

### 4.2 İkinci satır ($w_2 = 1$, $v_2 = 10$)

$P(2, 1)$, "1. ve 2. eşya göz önündeyken 1 kg'lık yük" durumudur. 1. eşya 2 kg olduğu için bu sınırda alınamaz, ama 2. eşya alınabilir:

$$P(2, 1) = \max\{10 + P[1, 0],\; P[1, 1]\} = \max\{10, 0\} = 10$$

Tahtada ikinci terim önce $P[0, 1]$ diye yazılmıştı; bir öğrencinin uyarısıyla $P[1, 1]$ olarak düzeltildi (ekrandan, 00:30:00 ve 00:35:00). Değer iki durumda da 0 olduğu için sonuç değişmez.

$P(2, 2)$ hesabı hocanın "buna dikkat edin, bu önemli" dediği yerdir:

$$P(2, 2) = \max\{10 + P[1, 1],\; P[1, 2]\} = \max\{10 + 0,\; 12\} = 12$$

$P[1, 1]$, 2. eşya eklenmeden önce çantada 1 kg varken ($2 - 1 = 1$) 1. satırdaki kazançtır ve 0'dır, çünkü 1. eşya 1 kg'a sığmamıştı. Toplam 2 kg için ya 1. eşya (12 lira) ya 2. eşya (10 lira) alınabilir; 1. eşya daha değerli olduğu için almamak seçeneği (yukarıdan gelen 12) kazanır.

Devamı:

- $P(2, 3) = \max\{10 + P[1, 2],\; P[1, 3]\} = \max\{22, 12\} = 22$. 3 kg'lık sınırda hem 1. eşya (2 kg, 12 lira) hem 2. eşya (1 kg, 10 lira) alınabilir; en büyük kazanç 22 liradır.
- $P(2, 4) = \max\{10 + P[1, 3],\; P[1, 4]\} = \max\{22, 12\} = 22$. Tahtada ikinci terim önce $P[1, 3]$ yazılmıştı; bir öğrencinin uyarısıyla $P[1, 4]$ olarak düzeltildi (ekrandan, 00:40:00 ve 00:55:00). Almazsam terimi aynı ağırlığa bakar, bu yüzden doğrusu $P[1, 4]$'tür.
- $P(2, 5) = 22$.

Böylece 2. satırda en büyük kazanç 22 liradır: hem 1. hem 2. eşya alınabilmektedir.

### 4.3 Üçüncü satır ($w_3 = 3$, $v_3 = 20$)

3. eşya 3 kg olduğu için 1 ve 2 kg'lık sınırlarda alınamaz; bu hücrelerde bir önceki satırdaki değerler (10 ve 12) aynen iner.

$$P(3, 3) = \max\{P(2, 0) + v_3,\; P(2, 3)\} = \max\{20,\; 22\} = 22$$

Tahtada ilk terim önce $P(2, 1)$ yazılıp 30 bulunmuştu; bir öğrencinin uyarısıyla $P(2, 0)$ olarak düzeltildi ve değer 20 oldu (ekrandan, 00:40:00 ve 00:45:00). Sonuç: 3 kg'lık sınırda 3. eşyayı tek başına almanın faydası yoktur; 1. ve 2. eşyadan gelen 22 lira daha iyidir.

$$P(3, 4) = \max\{P(2, 1) + v_3,\; P(2, 4)\} = \max\{10 + 20,\; 22\} = 30$$

Burada durum değişir: 3. eşyayı almak daha kazançlıdır.

$$P(3, 5) = \max\{P(2, 2) + v_3,\; P(2, 5)\} = \max\{12 + 20,\; 22\} = 32$$

### 4.4 Dördüncü satır ($w_4 = 2$, $v_4 = 15$)

- $P(4, 1) = P(3, 1) = 10$ (eşya 1 kg'a sığmaz).
- $P(4, 2) = \max\{15 + P(3, 0),\; P(3, 2)\} = \max\{15, 12\} = 15$.
- $P(4, 3) = \max\{15 + P(3, 1),\; P(3, 3)\} = \max\{25, 22\} = 25$.
- $P(4, 4) = \max\{15 + P(3, 2),\; P(3, 4)\} = \max\{27, 30\} = 30$.
- $P(4, 5) = \max\{15 + P(3, 3),\; P(3, 5)\} = \max\{37, 32\} = 37$.

### 4.5 Son tablo

Hocanın temiz sayfaya yeniden yazdığı tablo (ekrandan, 00:50:00; python ile kontrol edildi):

| $i \backslash w$ | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 | 10 | 15 | 25 | 30 | 37 |

Sırt çantasına konabilecek eşyaların en büyük toplam değeri 37 liradır (tahtada "37 TL" diye işaretlendi).

**Soru:** 37'nin sağ alt köşede çıkması bir tesadüf mü, yoksa en büyük değer hep sağ altta mı bulunur? **Cevap:** En büyük değer her zaman sağ alt hücrededir. Bu hücre "4. eşya, 5 kg için en büyük kazanç", yani bütün eşyaların göz önünde olduğu ve kapasitenin tamamının kullanılabildiği son durumdur. Örneğin 2. satır 4. sütun yalnız "2. eşyaya kadar, 4 kg için" kazancı, 3. satır 3. sütun "3. eşyaya kadar, 3 kg için" kazancı gösterir. Bize son eşyada, en büyük ağırlıktaki kazanç gerektiği için sonuç en son satırın en son sütunundadır; aradaki bir hücreden bu bilinemez.

## 5. Seçilen Eşyaların Geri İzlenmesi

Tablo en büyük kazancı verir, ama hangi eşyaların alındığını doğrudan göstermez. Hoca bunun tablo oluşturulurken anlaşılmasının karmaşık olduğunu, önce tablonun bütünüyle doldurulup sonra geriye doğru gidilmesi gerektiğini söyledi.

### 5.1 Kural

Geri izleme $n$. satır ve $W$. sütundaki hücreden, yani en büyük kazancın bulunduğu hücreden başlar.

- Değer üstteki hücreyle aynıysa değer dümdüz yukarıdan gelmiştir; $i$. eşya alınmamıştır. Bir üst satıra çıkılır, sütun değişmez.
- Değer üstteki hücreden farklıysa değer çapraz olarak, yukarıda ve soldaki bir hücreden gelmiştir; $i$. eşya alınmıştır. Bir üst satıra çıkılır ve eşyanın ağırlığı kadar sola gidilir.

### 5.2 Örnekte geri izleme

Adımlar (son tablo üzerinde, ekrandan, 00:50:00 ve 00:55:00):

1. $P[4, 5] = 37$; üstündeki $P[3, 5] = 32$ farklıdır. 4. eşya alınmıştır. 4. eşya 2 kg olduğu için 2 kg geriye gidilir: $P[3, 3] = 22$.
2. $P[3, 3] = 22$; üstündeki $P[2, 3] = 22$ aynıdır, değer olduğu gibi inmiştir. 3. eşya alınmamıştır. $P[2, 3]$'e çıkılır.
3. $P[2, 3] = 22$; üstündeki $P[1, 3] = 12$ farklıdır. 2. eşya alınmıştır. 2. eşya 1 kg olduğu için 1 kg geriye gidilir: $P[1, 2] = 12$.
4. $P[1, 2] = 12$; üstündeki $P[0, 2] = 0$ farklıdır. 1. eşya da alınmıştır. Sıfırıncı satır başlangıç durumu olduğu için burada ayrıca bakmaya gerek yoktur.

Sonuç: 1, 2 ve 4 numaralı eşyalar alınır. Kontrol: $2 + 1 + 2 = 5$ kg, $12 + 10 + 15 = 37$ lira. Bütün alt kümeler denenerek de en iyi kümenin {1, 2, 4} ve değerin 37 olduğu doğrulandı (python ile kontrol edildi).

**Soru:** Eşya numaralarıyla ilgili bir kural yoksa, 4. eşyadan iki tane ve 2. eşyadan bir tane alınsa hem ağırlık sağlanmaz mı, hem de daha iyi bir değer bulunmaz mı? **Cevap:** Hayır, her eşyadan yalnız bir tane vardır. Aynı ağırlıkta ve aynı değerde ikinci bir eşya olsaydı, onu listeye ayrı bir eşya olarak eklemek gerekirdi. Tablodaki eşyalar, önümüzde alınabilecek bütün eşyaların ağırlıkları ve fiyatlarıdır.

## 6. Tablonun Gücü: Bütün Kombinasyonlar ve Kaba Kuvvetle Karşılaştırma

Hoca, tablonun bütün kombinasyonları görmeyi sağladığını vurguladı: 4. eşya alınsa ne olur, alınmasa ne olur; 4. eşya varken 2. alınsa ne olur, 3. alınsa ne olur; 1. eşya varken 2. eşya alınmış mı alınmamış mı. Bunların hepsi tablodan geriye doğru gidilerek görülebilir.

Kaba kuvvet (brute force) yaklaşımında her eşya için al ya da alma seçeneği olduğundan $2^n$ kombinasyon denenmelidir; örneğin 10 eşya için 1024 alt küme. Tablo biçiminde ise önceki olasılıklar saklanmış olur ve her aşamada "3. eşyayı alsam ne olur, almasam ne olur" sorusu cevaplanır.

Hoca bunu tablodaki bir örnekle gösterdi (ekrandan, 00:55:00): $P[3, 4] = 30$, 3. eşyanın alındığı bir durumdur; burada 2. ve 3. eşya birlikte alınmış, 30 lira kazanılmıştır. 4 kg'lık sınırda 3. eşyayı almak hâlâ daha iyidir ($P[3, 4] = 30 > P[2, 4] = 22$). Ama son aşamada (4. satır) 3. eşya alınmadan 37 liralık daha iyi bir sonuç elde edildiği görülür. Böylece son aşamada bütün olasılıklar değerlendirilmiş olur.

> **Ders sonrası not:** Hoca 30 liralık durumu bir yerde "1 ve 3'ün alındığı durum" diye de andı. 1. ve 3. eşya birlikte 5 kg ve 32 liradır ($P[3, 5]$); $P[3, 4] = 30$ hücresi 2. ve 3. eşyaya (1 + 3 = 4 kg, 10 + 20 = 30 lira) karşılık gelir.

> **Ders sonrası not:** Hoca $2^n$ zamanlı problemleri "non-deterministic polynomial, polinom zamanda çözülemeyen, gerçek zamanda çözülemeyen algoritmalar" diye andı. NP (nondeterministic polynomial) "polinom olmayan" anlamına gelmez; NP, çözümü polinom zamanda doğrulanabilen karar problemlerinin sınıfıdır. 0-1 sırt çantası probleminin karar biçimi NP-tamdır.

> **Ek bilgi (derste anlatılmadı):** Tablo $(n+1) \times (W+1)$ hücreden oluşur ve her hücre sabit zamanda hesaplanır; bu yüzden yöntem $O(nW)$ zaman ve yer kullanır. Bu süre girdi boyutunda değil, kapasitenin sayısal değerinde polinomdur; bu tür algoritmalara sözde polinom (pseudo-polynomial) zamanlı denir.

> **Hocanın vurgusu:** Dinamik programlamada önemli olan, bütün durumları bir tablo üzerinde görüp değerlendirebilmektir. Yöntemin avantajı budur.

## 7. Dinamik Programlamanın Kullanım Alanları

Hoca tabloyu doldurmaya başlamadan önce dinamik programlamanın mantığının neden iyi anlaşılması gerektiğini anlattı: yaklaşım çok farklı alanlarda kullanılır.

- **Doğal dil işleme:** bir kelime yanlış yazıldığında doğru kelimeyi öneren düzelticiler dinamik programlama kullanır.
- **Ses tanıma:** eski ses tanıma yöntemleri saklı Markov modeli (Hidden Markov Model) kullanırdı; bu da tamamen dinamik programlamadır.

Dersin sonunda bir sonraki konunun da bu uygulamalarla ilgili olacağı söylendi: düzenleme uzaklığı (edit distance) ve en uzun ortak alt dizi (longest common subsequence). Hocanın ön gösterimi: sözlükte olan "kalem" kelimesi hızlı yazılırken yanlış yazıldığında sistem bunu hemen "kalem" diye düzeltir. Bu düzeltmeyi yapabilmek için yanlış yazılmış kelimenin ne olabileceğini bulmak gerekir; bunun için kullanılan yaklaşımlar bir sonraki derste anlatılacaktır.

> **Ek bilgi (derste anlatılmadı):** Düzenleme uzaklığı, bir kelimeyi diğerine dönüştürmek için gereken en az ekleme, silme ve değiştirme işlemi sayısıdır. Bu da sırt çantasındaki gibi bir tablo üzerinde, her hücrenin daha küçük alt problemlerden hesaplandığı bir dinamik programlama ile bulunur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00 ve 00:20:00): Ağırlıkları $(2, 1, 3, 2)$ kg, değerleri $(12, 10, 20, 15)$ lira olan 4 eşya ve 5 kg kapasiteli bir sırt çantası veriliyor. Her eşyadan bir tane vardır. 0-1 sırt çantası problemini dinamik programlama ile çözün: kâr tablosunu doldurun, en büyük kazancı ve seçilen eşyaları bulun.

> **Çözüm (derste verildi):** Bağıntı $P[i, w] = P[i-1, w]$ ($w_i > w$ ise), aksi halde $P[i, w] = \max\{v_i + P[i-1, w - w_i], P[i-1, w]\}$; sıfırıncı satır ve sütun 0. Tablonun son satırı $0, 10, 15, 25, 30, 37$ olur (tam tablo Bölüm 4.5'te). En büyük kazanç $P[4, 5] = 37$ liradır. Sağ alttan geri izlenince 4. eşya alınmış (37 ≠ 32), 3. eşya alınmamış (22 = 22), 2. eşya alınmış (22 ≠ 12), 1. eşya alınmış (12 ≠ 0) bulunur: {1, 2, 4}, 5 kg, 37 lira.

**Soru 2** (derste sözlü, 00:04:08): 1. ve 2. eşya çantadayken 3. eşya alınabilir mi?

> **Çözüm (derste verildi):** Alınamaz. 1 ve 2 birlikte 3 kg'dır; 3. eşya (3 kg) eklenirse toplam 6 kg olur ve 5 kg'lık kapasite aşılır.

**Soru 3** (derste sözlü, 00:46:16): Tabloda en büyük değer hep sağ alt hücrede mi bulunur?

> **Çözüm (derste verildi):** Evet. $P[n, W]$, bütün eşyalar göz önündeyken kapasitenin tamamı için en büyük kazançtır. Diğer hücreler yalnız daha az eşya ya da daha küçük ağırlık sınırı için alt problemlerin çözümleridir.

**Soru 4** (derste sözlü, 00:52:42): 4. eşyadan iki tane ve 2. eşyadan bir tane alınarak daha iyi bir değer bulunamaz mı?

> **Çözüm (derste verildi):** Hayır. 0-1 sırt çantasında her eşyadan yalnız bir tane vardır. Aynı eşyadan ikinci bir tane olsaydı listeye ayrı bir eşya olarak eklenmesi gerekirdi.

## Dersin Toparlaması

Bu derste 0-1 sırt çantası problemi dinamik programlama ile baştan sona çözüldü. Her eşya için iki durum vardır: eşya ağırlık sınırını aşıyorsa kesinlikle alınmaz ve bir önceki satırdaki değer korunur; sığıyorsa "alırsam" ($v_i + P[i-1, w - w_i]$) ve "almazsam" ($P[i-1, w]$) kazançlarından büyük olanı seçilir. Sıfırıncı satır ve sütun başlangıç durumu olarak sıfırlanır. Örnek tablo satır satır doldurularak en büyük kazancın sağ alt hücrede 37 lira olduğu bulundu; sonra sağ alttan geriye doğru gidilerek 1, 2 ve 4 numaralı eşyaların seçildiği gösterildi. Tablo, kaba kuvvetin $2^n$ alt kümesini tek tek denemek yerine alt problemlerin sonuçlarını saklayarak bütün kombinasyonları değerlendirir.

Dinamik programlamanın yazım düzelticilerden ses tanımaya kadar geniş bir kullanım alanı vardır. Sonraki derste bu uygulamalarla ilgili iki problem ele alınacaktır: düzenleme uzaklığı (edit distance) ve en uzun ortak alt dizi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
