# Ders 3 Çalışma Özeti

## Genel Konular

- Ders büyük ölçüde İngilizce anlatıldı, bazı açıklamalar Türkçe tekrarlandı.
  - Kayıt iki arayla üç bölümden oluşur: DFA (yaklaşık 00:04-00:52), NFA (yaklaşık 01:04-01:52), küme/dizgi işlemleri ve DFA tasarımı alıştırmaları (yaklaşık 02:07-03:00).
  - İlk iki bölümde PowerPoint slaytları, üçüncü bölümde tablette el yazısı kullanıldı.
- Dil ve sonlu otomat
  - Dil (language) bir dizgiler (string) kümesidir.
  - Bir sonlu otomatın (finite automaton) tanıdığı dile düzenli dil (regular language) denir.
  - Sonlu otomat bir dizgiyi okur ve "kabul" (accept) ya da "ret" (reject) sonucu verir.
- Sonlu otomatın 5'li tanımı: $M = (Q, \Sigma, \delta, q_0, F)$
  - $Q$: durumlar kümesi, $\Sigma$: alfabe, $\delta: Q \times \Sigma \to Q$: geçiş fonksiyonu, $q_0 \in Q$: başlangıç durumu, $F \subseteq Q$: kabul durumları kümesi (ekrandan, 00:10:00).
- Geçiş grafiği ve geçiş tablosu
  - Yalnızca `abba` dizgisini kabul eden altı durumlu DFA örneği; $q_5$ tuzak (trap) durumudur (ekrandan, 00:15:00).
  - Geçiş tablosunda başlangıç durumu bilgisi yer almaz.
- Tasarım örneği: tek sayıda 1 içeren ikili dizgiler
  - İki durum yeterlidir: $q_0$ "çift sayıda 1", $q_1$ "tek sayıda 1" (ekrandan, 00:25:00 ve 00:30:00).
- Kabul ve ret koşulları; dizgilerin adım adım işlenmesi (`abba`, `aba`, boş dizgi)
- Verilen DFA'ların dilini bulma örnekleri
  - Üç kabul durumlu makine: $\{\varepsilon, ab, abba\}$.
  - $\{a^n b : n \ge 0\}$ dilini tanıyan üç durumlu makine (ekrandan, 00:40:00).
  - Tek sembollü alfabede çift sayıda 1 içeren dizgiler.
- Genişletilmiş geçiş fonksiyonu $\delta^*: Q \times \Sigma^* \to Q$ (ekrandan, 00:45:00 ve 00:50:00)
- DFA'nın kabul ettiği dil $L(M)$ ve reddettiği dil $\overline{L(M)}$ (ekrandan, 01:10:00 ve 01:15:00)
- Deterministik olmayan sonlu otomat (NFA)
  - Geçiş fonksiyonu bir durum yerine bir durum kümesi verir: $\delta(q, x) = \{q_1, \dots, q_k\}$ (ekrandan, 01:20:00).
  - Boş geçiş ($\varepsilon$-geçişi), geçişi olmayan (ölü) dal.
  - NFA'nın kabul ve ret tanımı; $\{aa\}$, $\{ab\}^+$ ve $\{10\}^*$ dillerini tanıyan NFA örnekleri.
  - Aynı dili ($\{a\}$) tanıyan bir NFA ve bir DFA (ekrandan, 01:45:00).
- Alıştırmalar: kümelerde eleman/alt küme, birleşim, kesişim, Kartezyen çarpım, birleştirme (concatenation), kuvvet kümesi, Kleene yıldızı ve artısı, ters çevirme; $\{\varepsilon, b, ab\}$ dili için DFA tasarımı.

## Hocanın Özellikle Vurguladığı Kısımlar

- 5'li tanımı doğru yazmak
  - Hoca sınavlarda 5'li tanımın sorulduğunu ve öğrencilerin bunu yazamadığını söyledi.
  - $Q$, $\Sigma$ ve $F$ kümedir; $\delta$ bir geçiş fonksiyonudur (tablo); $q_0$ ise yalnızca bir durumun adıdır.
  - Sonlu otomatta birden fazla başlangıç durumu olamaz.
- Geçiş tablosunu kullanmak
  - Hoca, geçişleri tek tek $(q, a) \to q'$ biçiminde yazmak yerine geçiş tablosunu önerdi; makinenin davranışı tabloda daha kolay görülür.
- Bir makine yalnız bir dil tanır, bir dili birçok makine tanıyabilir.
- Başlangıç durumu kabul durumuysa boş dizgi $\varepsilon$ dilin elemanıdır.
- NFA'da kabul: girdi bitince üzerinde bulunulan durumlardan en az biri kabul durumuysa dizgi kabul edilir.
- "Hiçbir şey tanımaz" tuzağı
  - Kabul durumu olmayan bir makine "hiçbir şey tanımaz" değildir; boş dili $\emptyset$ tanır. Her makine bir dil tanır.
  - $\emptyset$ ile $\{\varepsilon\}$ farklıdır: ikincisi tek elemanlı bir kümedir.
  - Hoca, soruların genellikle "basit" görünen slaytlarda saklı olduğunu, temel kavramların iyi anlaşılması gerektiğini vurguladı.
- DFA ve NFA farkı
  - DFA'da her durumdan çıkan geçiş sayısı alfabedeki sembol sayısına eşittir; NFA'da bu zorunlu değildir.
  - Bütün DFA'lar kümesi, bütün NFA'lar kümesinin bir alt kümesidir.
- Kümelerde eleman ile alt küme karıştırılmamalı ($\{1,2,3\} \in A$ ile $\{1,2,3\} \subseteq A$ farklıdır).
- Boş kümeyle birleştirme boş küme verir: $D \cdot \emptyset = \emptyset$ ("$D$ kalır" yanlıştır).

## Kısa Tekrar Notları

- Dil = dizgiler kümesi; düzenli dil = bir sonlu otomatın tanıdığı dil.
- DFA: $M = (Q, \Sigma, \delta, q_0, F)$, $\delta: Q \times \Sigma \to Q$.
- Dizgiyi kabul etmek için bütün girdi okunmalı ve son durum kabul durumu olmalıdır.
- $\delta^*(q, w)$: $q$'dan başlayıp $w$ dizgisini okuyunca varılan durum; örn. $\delta^*(q_0, ab) = q_2$, $\delta^*(q_1, bba) = q_4$.
- $L(M) = \{ w \in \Sigma^* : \delta^*(q_0, w) \in F \}$; $\overline{L(M)} = \{ w \in \Sigma^* : \delta^*(q_0, w) \notin F \}$.
- NFA'da $\delta: Q \times (\Sigma \cup \{\varepsilon\}) \to 2^Q$; bir sembolle birden çok duruma ya da hiçbir duruma gidilebilir.
- NFA, en az bir hesaplama dizgiyi kabul ediyorsa kabul eder; hiçbir hesaplama kabul etmiyorsa reddeder.
- $\varepsilon$-geçişi: bir duruma varınca $\varepsilon$ ile bağlı durumlarda da bulunulur.
- Kabul durumu olmayan makine $\emptyset$ dilini, yalnız başlangıç durumu kabul olan tek durumlu makine $\{\varepsilon\}$ dilini tanır.
- $|\mathcal{P}(C)| = 2^{|C|}$.
- $\emptyset^* = \{\varepsilon\}$, $\{\varepsilon\}^* = \{\varepsilon\}$; bu ikisi, Kleene yıldızı sonlu olan kümelerdir.
- $X \cdot \{\varepsilon\} = X$, $X \cdot \emptyset = \emptyset$.
- $S^+ = S^* - \{\varepsilon\}$ eşitliği yalnız $\varepsilon \notin S$ iken geçerlidir; $\varepsilon \in S$ ise $S^+ = S^*$.

## Detaylı Açıklamalar

- **Sonlu otomat ve 5'li tanım.** Sonlu otomat, girdi şeridindeki dizgiyi soldan sağa okuyan bir makinedir. Her sembolde geçiş fonksiyonuna göre durum değiştirir; girdi bitince bulunduğu durum kabul durumuysa dizgiyi kabul eder. Biçimsel tanım $M = (Q, \Sigma, \delta, q_0, F)$'dir. $Q$ sonlu bir durumlar kümesi, $\Sigma$ sonlu bir alfabe, $\delta: Q \times \Sigma \to Q$ geçiş fonksiyonu, $q_0 \in Q$ başlangıç durumu, $F \subseteq Q$ kabul durumları kümesidir. Hoca geçiş fonksiyonunu "otomatın programı" olarak düşünmeyi önerdi.

- **`abba` örneği.** Durumlar $q_0, \dots, q_5$, başlangıç $q_0$, kabul durumu $q_4$'tür (ekrandan, 00:15:00). Geçiş tablosu:

| $\delta$ | a | b |
|---|---|---|
| $q_0$ | $q_1$ | $q_5$ |
| $q_1$ | $q_5$ | $q_2$ |
| $q_2$ | $q_5$ | $q_3$ |
| $q_3$ | $q_4$ | $q_5$ |
| $q_4$ | $q_5$ | $q_5$ |
| $q_5$ | $q_5$ | $q_5$ |

  `abba` için yol $q_0 \to q_1 \to q_2 \to q_3 \to q_4$ olur ve dizgi kabul edilir. `aba` için yol $q_0 \to q_1 \to q_2 \to q_5$ olur ve dizgi reddedilir (ekrandan, 00:35:00). Boş dizgide makine $q_0$'da kalır; $q_0$ kabul durumu olmadığı için reddedilir. Makinenin dili $\{abba\}$'dır: tek elemanlı bir küme de bir dildir. Aynı grafikte $q_0$, $q_2$ ve $q_4$ kabul durumu yapılırsa dil $\{\varepsilon, ab, abba\}$ olur.

- **Tek sayıda 1 içeren dizgiler.** $A = \{ w \in \{0,1\}^* : w \text{ tek sayıda } 1 \text{ içerir} \}$. Her sayıyı ayrı bir durumla saymak sonlu durumla mümkün değildir; doğru yaklaşım yalnız "şimdiye kadar okunan 1'lerin sayısı çift mi tek mi" bilgisini tutmaktır (ekrandan, 00:25:00). $M = (\{q_0, q_1\}, \{0,1\}, \delta, q_0, \{q_1\})$ ve (ekrandan, 00:30:00):

| $\delta$ | 0 | 1 |
|---|---|---|
| $q_0$ | $q_0$ | $q_1$ |
| $q_1$ | $q_1$ | $q_0$ |

- **$a^n b$ makinesi.** $q_0$'da `a` ile döngü, `b` ile kabul durumu $q_1$'e geçiş, $q_1$'den her sembolle tuzak durum $q_2$'ye geçiş vardır (ekrandan, 00:40:00). `aab` kabul edilir, `bab` reddedilir. Dil $\{a^n b : n \ge 0\} = \{b, ab, aab, \dots\}$ sonsuzdur; üç durumlu bir makinenin sonsuz bir dil tanıyabilmesini döngüler sağlar.
  - Ders sonrası not: Hoca bu dili bir yerde "a ile başlayıp b ile biten" diye tanımladı. Makine `b` dizgisini de kabul eder ve `abab` gibi dizgileri reddeder; doğru tanım $\{a^n b : n \ge 0\}$'dır (python ile kontrol edildi).

- **Genişletilmiş geçiş fonksiyonu.** $\delta$ bir durum ve bir sembol alır; $\delta^*: Q \times \Sigma^* \to Q$ ise bir durum ve bir dizgi alır. $\delta^*(q, w)$, $q$'dan $w$ okunduktan sonra varılan durumdur. $w = \sigma_1 \sigma_2 \cdots \sigma_k$ ise bu, $q$'dan $q'$'ye giden bir yürüyüştür (walk). Örnekler: $\delta^*(q_0, ab) = q_2$, $\delta^*(q_1, bba) = q_4$ (ekrandan, 00:45:00 ve 00:50:00). Başlangıç durumunun $q_0$ olması gerekmez.

- **$L(M)$ ve tümleyeni.** $L(M) = \{ w \in \Sigma^* : \delta^*(q_0, w) \in F \}$, yani $q_0$'dan başlayıp kabul durumunda biten bütün dizgilerin kümesi (ekrandan, 01:10:00). Reddedilen dil tümleyendir: $\overline{L(M)} = \{ w \in \Sigma^* : \delta^*(q_0, w) \notin F \}$ (ekrandan, 01:15:00).

- **NFA.** NFA da 5'li ile tanımlanır, fakat geçiş bir durum kümesi verir. Bir sembolle aynı anda birden çok durumda bulunulabilir; bir sembol için geçiş yoksa o dal ölür. Örnekte alfabe $\{a\}$'dır; $q_0$'dan `a` ile hem $q_1$'e hem $q_3$'e gidilir, $q_1$'den `a` ile kabul durumu $q_2$'ye gidilir (ekrandan, 01:25:00). `aa` kabul edilir; `a` reddedilir ($q_1$ ve $q_3$ kabul durumu değildir); `aaa` reddedilir (üçüncü `a` hiçbir dalda okunamaz). Dil $\{aa\}$'dır.
  - NFA bir dizgiyi, her hesaplamada ya girdi bitip makine kabul olmayan bir durumdaysa ya da girdi okunamıyorsa reddeder (ekrandan, 01:30:00).
  - $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$, $q_2 \xrightarrow{\varepsilon} q_3$, $q_3 \xrightarrow{\varepsilon} q_0$ NFA'sında (kabul durumu $q_2$) `ab` ve `abab` kabul edilir; dil $\{ab\}^+$'dır (ekrandan, 01:35:00 ve 01:40:00).
  - Başlangıç durumu kabul durumu olan, $\{10\}^*$ dilini tanıyan bir NFA'da bir geçiş gereksizdir (hoca "useless" dedi).
  - Aynı dili tanıyan iki makine: NFA $M_1$ ($q_0 \xrightarrow{a} q_1$) ve DFA $M_2$ (tuzak durumlu); $L(M_1) = L(M_2) = \{a\}$ (ekrandan, 01:45:00).

- **Alıştırmalar.** $C = \{\varepsilon, aab, baa\}$, $D = \{bb, aab\}$, $E = \{\varepsilon\}$, $F = \emptyset$ (ekrandan, 02:25:00) için $D \cup C = \{\varepsilon, bb, aab, baa\}$, $C \cup F = C$, $C \cap D = \{aab\}$, $CD = \{bb, aab, aabbb, aabaab, baabb, baaaab\}$, $DF = \emptyset$, $DE = D$, $|\mathcal{P}(C)| = 8$. Ayrıntılı çözümler genişletilmiş nottadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
