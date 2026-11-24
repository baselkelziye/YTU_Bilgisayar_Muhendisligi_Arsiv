# Ders 18 Çalışma Özeti

## Genel Konular

- 0-1 sırt çantası (0-1 knapsack) probleminin örnek üzerinden kurulması
  - Örnek (ekrandan, 00:05:00): 4 eşya; ağırlıklar $w = (2, 1, 3, 2)$ kg, değerler $v = (12, 10, 20, 15)$ lira, sırt çantasının kapasitesi $W = 5$ kg.
  - Her eşyadan yalnız bir tane vardır. Her eşya için iki seçenek vardır: alınır (select) ya da vazgeçilir (abandon).
  - Eşyalar sırayla eklenince ağırlık ve değer toplanır: 1 alınırsa $\Sigma w = 2$, $\Sigma v = 12$; 2 de alınırsa $\Sigma w = 3$, $\Sigma v = 22$; 3 de alınırsa $\Sigma w = 6$, $\Sigma v = 42$. Son durum kapasiteyi aştığı için mümkün değildir.
- Kâr matrisi $P[i, w]$
  - $P[i, w]$: ilk $i$ eşya göz önündeyken toplam ağırlık sınırı $w$ olduğunda elde edilebilecek en büyük kazanç (maximum profit).
  - Satırlar eşyaları (0..4), sütunlar ağırlığı (0..5) gösterir. 0. satır ve 0. sütun başlangıç durumudur.
- Alma durumu (case 1: eşya $i$ alınır)
  - $P(i, w) = P(i-1, w - w_i) + v_i$ (ekrandan, 00:10:00): eşya alınmadan önceki satırda, eşyanın ağırlığı kadar geriye gidilir ve eşyanın değeri eklenir.
- Alamama durumu
  - Eşyanın ağırlığı mevcut ağırlık sınırından büyükse ($w_i > w$) eşya alınamaz; bir önceki satırdaki değer aynen kalır.
- Özyinelemeli bağıntı (ekrandan, 00:20:00)

  $$P[i, w] = \begin{cases} 0 & i = 0 \text{ ya da } w = 0 \\ P[i-1, w] & w_i > w \\ \max\{v_i + P[i-1, w - w_i],\; P[i-1, w]\} & \text{aksi halde} \end{cases}$$

- Tablonun satır satır doldurulması ve sonuç
  - Son tablo (ekrandan, 00:50:00) aşağıda. En büyük kazanç sağ alt hücrede: $P[4, 5] = 37$ lira.
- Seçilen eşyaların geri izlenmesi
  - Sağ alt hücreden başlanır. Hücre üstündekine eşitse eşya alınmamıştır, bir üst satıra çıkılır. Farklıysa eşya alınmıştır; bir üst satırda eşyanın ağırlığı kadar sola gidilir.
  - Örnekte 1, 2 ve 4 numaralı eşyalar seçilir: $2 + 1 + 2 = 5$ kg, $12 + 10 + 15 = 37$ lira.
- Dinamik programlamanın kullanım alanları ve sonraki konu
  - Yanlış yazılan kelimeye doğru kelime öneren yazım düzelticiler ve eski ses tanıma sistemlerindeki saklı Markov modelleri (Hidden Markov Model) dinamik programlama kullanır.
  - Sonraki konular: düzenleme uzaklığı (edit distance) ve en uzun ortak alt dizi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir eşya çantaya sığıyor diye mutlaka alınmamalıdır.
  - Sığan her şeyi almak kazancı azaltabilir. Bu yüzden "alırsam" ve "almazsam" kazançları karşılaştırılır, büyük olan seçilir.
- 0. satır ve 0. sütunun sıfır olmasının nedeni
  - Değerler ekleye ekleye hesaplanır; toplamada sıfırdan başlanması gibi, başlangıç durumunun sıfır olması gerekir. Bu yüzden 4 eşya için 5 satırlık bir tablo kurulur.
- Sonuç her zaman sağ alt hücrededir.
  - $P[n, W]$ hücresi "bütün eşyalar göz önündeyken, kapasitenin tamamı için en büyük kazanç" demektir. Ara hücreler yalnız alt problemlerin çözümüdür.
- Hangi eşyaların alındığı tablo dolarken anlaşılamaz.
  - Önce tablo bütünüyle doldurulur, sonra sağ alttan geriye doğru gidilerek seçilen eşyalar bulunur.
- Tablo bütün kombinasyonları saklar.
  - Kaba kuvvette $n$ eşya için $2^n$ alt küme denenir (10 eşya için 1024). Tablo, önceki olasılıkları saklayarak her aşamada "alsam ne olur, almasam ne olur" sorusunu cevaplar.
- Dinamik programlamanın mantığının iyi anlaşılması gerekir, çünkü birçok farklı alanda kullanılır.

## Kısa Tekrar Notları

- 0-1 knapsack: her eşya ya tamamen alınır ya hiç alınmaz; her eşyadan bir tane vardır.
- $P[i, w]$ = ilk $i$ eşya ile ağırlık sınırı $w$ için en büyük kazanç.
- $w_i > w$ ise: $P[i, w] = P[i-1, w]$ (kesinlikle alınmaz, "not taken").
- Aksi halde: $P[i, w] = \max\{v_i + P[i-1, w - w_i],\; P[i-1, w]\}$ (alırsam / almazsam).
- Sınır: $P[0, w] = 0$, $P[i, 0] = 0$.
- Örnek tablo sonucu: $P[4, 5] = 37$; seçilen eşyalar 1, 2, 4.
- Geri izleme: üstteki değer eşitse alınmadı (yukarı çık); farklıysa alındı (yukarı çık ve $w_i$ kadar sola git).
- Kaba kuvvet $2^n$ alt küme dener; tablo yöntemi alt problemlerin sonuçlarını saklar.

## Detaylı Açıklamalar

- **Problemin kurulması.** Derste 0-1 sırt çantası problemi bir hırsız benzetmesiyle ele alındı: hırsız, taşıyabileceği en çok 5 kg'lık bir çantaya, en değerli eşya kümesini koymak ister. Eşyalar (ekrandan, 00:05:00):

  | Eşya | Ağırlık (kg) | Değer (lira) |
  |---|---|---|
  | 1 | 2 | 12 |
  | 2 | 1 | 10 |
  | 3 | 3 | 20 |
  | 4 | 2 | 15 |

  Hoca önce eşyaları sırayla eklemenin ne demek olduğunu gösterdi. 1 alınınca çantada 2 kg ve 12 lira olur. 2 de alınınca 3 kg ve 22 lira olur. Bu durumda 3 de alınırsa toplam ağırlık 6 kg olur; bu 5 kg'lık kapasiteyi aştığı için 1 ve 2 çantadayken 3 alınamaz.

- **Alma durumu.** Hırsız $i$. eşyayı alırsa, eşyayı almadan önceki durum, bir önceki satırda ($i-1$) ve eşyanın ağırlığı kadar eksik ağırlıktaki ($w - w_i$) hücredir. Bu hücredeki kazanca eşyanın değeri eklenir: $P(i, w) = P(i-1, w - w_i) + v_i$ (ekrandan, 00:10:00). Hocanın örneği: 1. eşya alınmışken 2 kg yük ve 12 lira kazanç vardır, yani $P(1, 2) = 12$. 2. eşya (1 kg, 10 lira) eklenince $P(2, 3) = P(1, 3 - 1) + 10 = 12 + 10 = 22$ olur. Kapasite yetseydi 3. eşya için aynı mantıkla $P(3, 6) = P(2, 3) + v_3 = 22 + 20$ yazılacaktı.

- **Alamama durumu.** Eşyanın ağırlığı mevcut ağırlık sınırından büyükse eşya alınamaz ve bir önceki satırdaki durum korunur: $P[i, w] = P[i-1, w]$. Hocanın açıklamasıyla, kapasite 5 kg ve çantada 3 kg varken ancak en çok 2 kg'lık bir eşya eklenebilir; 8 kg'lık bir eşya alınamaz.

- **Bağıntı.** İki durum ve başlangıç koşulu birleşince bağıntı şöyle olur (ekrandan, 00:20:00):

  $$P[i, w] = \begin{cases} 0 & i = 0 \text{ ya da } w = 0 \\ P[i-1, w] & w_i > w \\ \max\{v_i + P[i-1, w - w_i],\; P[i-1, w]\} & \text{aksi halde} \end{cases}$$

  Üçüncü satırda eşya sığsa bile alınıp alınmayacağına karar verilir: ilk terim "alırsam", ikinci terim "almazsam" kazancıdır.

- **Tablonun doldurulması.** Hücrelerin hesabı (ekrandan, 00:25:00 - 00:55:00):
  - 1. satır ($w_1 = 2$, $v_1 = 12$): $P(1, 1) = P(0, 1) = 0$ (eşya sığmaz). $P(1, 2) = \max\{12 + P[0, 0], P[0, 2]\} = \max\{12, 0\} = 12$. $P(1, 3) = \max\{12 + P[0, 1], P[0, 3]\} = 12$. 4 ve 5 kg için de 12 olur, çünkü bu satırda yalnız 1. eşya vardır.
  - 2. satır ($w_2 = 1$, $v_2 = 10$): $P(2, 1) = \max\{10 + P[1, 0], P[1, 1]\} = 10$. $P(2, 2) = \max\{10 + P[1, 1], P[1, 2]\} = \max\{10, 12\} = 12$. $P(2, 3) = \max\{10 + P[1, 2], P[1, 3]\} = \max\{22, 12\} = 22$. $P(2, 4) = \max\{10 + P[1, 3], P[1, 4]\} = 22$. $P(2, 5) = 22$.
  - 3. satır ($w_3 = 3$, $v_3 = 20$): 1 ve 2 kg için eşya sığmaz, değerler yukarıdan iner (10, 12). $P(3, 3) = \max\{P(2, 0) + 20, P(2, 3)\} = \max\{20, 22\} = 22$. $P(3, 4) = \max\{P(2, 1) + 20, P(2, 4)\} = \max\{30, 22\} = 30$. $P(3, 5) = \max\{P(2, 2) + 20, P(2, 5)\} = \max\{32, 22\} = 32$.
  - 4. satır ($w_4 = 2$, $v_4 = 15$): $P(4, 1) = 10$. $P(4, 2) = \max\{15, 12\} = 15$. $P(4, 3) = \max\{15 + 10, 22\} = 25$. $P(4, 4) = \max\{15 + 12, 30\} = 30$. $P(4, 5) = \max\{15 + 22, 32\} = 37$.

  Son tablo (ekrandan, 00:50:00; python ile kontrol edildi):

  | $i \backslash w$ | 0 | 1 | 2 | 3 | 4 | 5 |
  |---|---|---|---|---|---|---|
  | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
  | 1 | 0 | 0 | 12 | 12 | 12 | 12 |
  | 2 | 0 | 10 | 12 | 22 | 22 | 22 |
  | 3 | 0 | 10 | 12 | 22 | 30 | 32 |
  | 4 | 0 | 10 | 15 | 25 | 30 | 37 |

- **Geri izleme.** Sağ alt hücreden ($P[4, 5] = 37$) başlanır. Üstündeki 32 farklı olduğu için 4. eşya alınmıştır; 3. satıra çıkılır ve 2 kg sola gidilir: $P[3, 3] = 22$. Üstündeki $P[2, 3]$ de 22 olduğu için 3. eşya alınmamıştır. $P[2, 3] = 22$, üstündeki 12'den farklıdır; 2. eşya alınmıştır, 1 kg sola gidilir: $P[1, 2] = 12$. Üstündeki 0'dan farklıdır; 1. eşya da alınmıştır. Sonuç: 1, 2 ve 4 numaralı eşyalar, toplam 5 kg ve 37 lira.

- **Tablonun sakladığı kombinasyonlar.** Tablo yalnız sonucu değil ara durumları da gösterir. Örneğin $P[3, 4] = 30$, 2. ve 3. eşyanın birlikte alındığı (1 + 3 = 4 kg, 10 + 20 = 30 lira) durumdur. Son satırda ise 3. eşya alınmadan daha iyi bir sonuç (37) elde edildiği görülür.

  > **Ders sonrası not:** Hoca 30 liralık bu durumu bir yerde "1 ve 3'ün alındığı durum" diye de andı; 1 ve 3 birlikte 5 kg ve 32 liradır ($P[3, 5]$). $P[3, 4] = 30$ hücresi 2. ve 3. eşyaya karşılık gelir.

  > **Ders sonrası not:** Hoca $2^n$ zamanlı problemleri "non-deterministic polynomial, polinom zamanda çözülemeyen" diye andı. NP (nondeterministic polynomial) "polinom olmayan" anlamına gelmez; polinom zamanda doğrulanabilen problemler sınıfıdır. Sırt çantası probleminin karar biçimi NP-tamdır; tablo yöntemi $O(nW)$ zamanda çalışır ve bu süre $W$'ye bağlı olduğu için büyük olasılıkla "sözde polinom" (pseudo-polynomial) diye anılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
