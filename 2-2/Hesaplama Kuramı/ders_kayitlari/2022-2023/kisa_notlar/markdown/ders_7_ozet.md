# Ders 7 Çalışma Özeti

## Genel Konular

- Bağlamdan bağımsız gramerlerin tekrarı
  - Bağlamdan bağımsız diller (context-free languages) düzenli dillerin üst kümesidir. $\{a^n b^n : n \ge 0\}$ ve $\{w w^R\}$ düzenli değildir ama bağlamdan bağımsızdır.
  - Bu dilleri tanımlamanın iki yolu vardır: bağlamdan bağımsız gramerler ve yığıtlı otomatlar (pushdown automata, PDA).
  - Gramer, değişkenler (variables), bitiş sembolleri (terminals), üretim kuralları (production rules) ve başlangıç değişkeninden oluşur. Kurallar yazılırken en üstteki, en soldaki değişken başlangıç değişkenidir.
  - "the dog sleeps" türetimi: $\langle sentence \rangle \Rightarrow \langle noun\_phrase \rangle \langle predicate \rangle \Rightarrow \langle noun\_phrase \rangle \langle verb \rangle \Rightarrow \langle article \rangle \langle noun \rangle \langle verb \rangle \Rightarrow the\ \langle noun \rangle \langle verb \rangle \Rightarrow the\ dog\ \langle verb \rangle \Rightarrow the\ dog\ sleeps$ (ekrandan, 00:10:00).
  - $S \to aSb \mid \varepsilon$ gramerinde $S \stackrel{*}{\Rightarrow} \varepsilon$, $S \stackrel{*}{\Rightarrow} ab$, $S \stackrel{*}{\Rightarrow} aaabbb$ yazılabilir; gramerin dili $\{a^n b^n : n \ge 0\}$'dır (ekrandan, 00:15:00). $\stackrel{*}{\Rightarrow}$, birkaç adımda üretilebildiğini gösterir; $\mid$ işareti "veya" diye okunur.
  - Gramer bir dörtlüdür: $G = (V, T, S, P)$, yani değişkenler kümesi, bitiş sembolleri kümesi, başlangıç değişkeni ve üretim kuralları kümesi.
  - Gramerin dili: $L(G) = \{ w \in T^* : S \stackrel{*}{\Rightarrow} w \}$. Bir dil, onu üreten bir bağlamdan bağımsız gramer varsa bağlamdan bağımsızdır: $L = L(G)$ (ekrandan, 00:20:00).
  - Derste tekrar edilen diğer gramerler çift uzunluklu palindromları ($w w^R$) ve eşleşen parantezleri üretir.
- Soldan ve sağdan üretim, üretim ağacı ve belirsizlik
  - Her adımda en soldaki değişken açılıyorsa soldan üretim (leftmost derivation), en sağdaki açılıyorsa sağdan üretim (rightmost derivation) olur.
  - Üretim adımları bir ağaç oluşturur: üretim ağacı (derivation tree, parse tree). Ağaç dizgenin anlamını ifade eder.
  - $E \to E + E \mid E * E \mid (E) \mid a$ gramerinde $a + a * a$ için iki farklı soldan üretim, dolayısıyla iki farklı ağaç vardır (ekrandan, 00:25:00). Bu duruma belirsizlik (ambiguity) denir. $a = 2$ alınırsa ağaçlardan biri $2 + (2 \cdot 2) = 6$, diğeri $(2 + 2) \cdot 2 = 8$ verir.
  - "if-then" / "if-then-else" kuralları da belirsizlik doğurur. Belirsizlik bazen programcının blok parantezleriyle, bazen gramer yeniden yazılarak giderilir.
  - Bazı diller doğası gereği belirsizdir (inherently ambiguous): $L = \{a^n b^n c^m\} \cup \{a^n b^m c^m\}$ dilinde $a^n b^n c^n$ dizgesinin her gramerde iki farklı üretim ağacı vardır; biri $S \to S_1$, diğeri $S \to S_2$ ile başlar (ekrandan, 00:30:00).
- Gramerlerin sadeleştirilmesi (simplification)
  - Neden: ayrıştırıcı (parser) yazarken sade ya da normal biçimdeki gramer daha uygundur; gereksiz kurallar grameri anlamayı zorlaştırır.
  - Yerine koyma kuralı (substitution rule): $B \to y_1$ kuralı atılmak istenirse, sağ tarafında $B$ geçen her $A \to xBz$ kuralına $A \to x y_1 z$ seçeneği eklenir, sonra $B \to y_1$ silinir. Gramerin dili değişmez.
  - Null üretimlerin ($X \to \varepsilon$) atılması: $X$ boşalabilir (nullable) değişkendir. Yerine koyma kuralıyla $X$ yerine boş dize konur. Başlangıç değişkeninin null üretimi atılamaz.
  - Birim üretimlerin ($X \to Y$) atılması: kurallar tek tek atılır; $B \to B$ gibi kurallar ve tekrarlanan kurallar doğrudan silinir.
  - Gereksiz (useless) değişken ve üretimlerin atılması: başlangıçtan yalnız bitiş sembollerinden oluşan bir dizgeye ulaşmakta kullanılamayan değişken gereksizdir. İki aşama: önce bitiş sembolü üretebilen değişkenler bulunur, sonra bağımlılık grafiği (dependency graph) ile $S$'den ulaşılamayanlar atılır.
  - Genel sıra: null üretimler, birim üretimler, gereksiz değişkenler.
- Chomsky normal formu (CNF)
  - Her kural $A \to BC$ (iki değişken) ya da $A \to a$ (tek bitiş sembolü) biçimindedir.
  - Dönüşüm: temizlik, her bitiş sembolü $a$ için yeni $T_a \to a$ değişkeni, uzun kuralların ara değişkenlerle ikişerli parçalanması.
  - Boş dizeyi üretmeyen her bağlamdan bağımsız gramer için CNF kolayca bulunur. CNF ayrıştırma ve teorem ispatı için kullanışlıdır.
- Greibach normal formu (GNF)
  - Her kural $A \to a V_1 V_2 \cdots V_k$, $k \ge 0$ biçimindedir: başta tek bir bitiş sembolü, ardından sıfır ya da daha çok değişken.
  - Dizgeleri ayrıştırmada CNF'den daha iyidir; slayta göre bir gramerin GNF'sini bulmak zordur.
- Yığıtlı otomatlar (pushdown automata, PDA)
  - DFA/NFA gibi giriş dizgisi ve durumlardan oluşan bir kontrol birimi vardır; ek olarak bir yığıt (stack) bulunur. Yığıta yalnız en üstten eklenir (push) ve en üstten çıkarılır (pop).
  - Başlangıçta yığıtın dibinde alfabede olmayan özel bir sembol ($\$$ ya da $z$) vardır.
  - Geçiş etiketi $a, b \to c$: durum $q_1$ ise, girişten $a$ okunuyorsa ve yığıtın üstünde $b$ varsa $b$ çıkarılır, $c$ eklenir ve $q_2$'ye geçilir. $\varepsilon$ yazılan yer "okuma yok", "çıkarma yok" ya da "ekleme yok" anlamına gelir.
  - PDA'lar deterministik değildir: aynı giriş ve yığıt koşuluyla birden fazla duruma gidilebilir, giriş okumadan $\varepsilon$ geçişi yapılabilir.
  - Kabul: girişin tamamını tüketip kabul durumunda biten en az bir hesaplama dalı varsa dizge kabul edilir. Sondaki yığıt içeriği önemsizdir.
  - Örnekler: $\{a^n b^n : n \ge 0\}$ ve $\{v v^R : v \in \{a, b\}^*\}$ PDA'ları.

## Hocanın Özellikle Vurguladığı Kısımlar

- "Bu gramer neyi üretir?" sorusu
  - Gramere bakıp dili hemen görmek kolay değildir. Kağıt kalemle birkaç dizge üretip ortak özelliği bulmak gerekir.
- Belirsizliğin sakıncası
  - Programlama dillerinde bir kodun anlamının tekil olması istenir. Aynı dizgenin iki ağacı olması iki ayrı anlam demektir.
- Sınav türü sorular
  - Bir gramerin CNF ya da GNF karşılığını bulmak, gramerden null ya da birim üretimleri atmak gibi alıştırmalar sınavda çıkabilir; bu tür alıştırmaların çözülmesi tavsiye edildi.
- PDA'da paralel makineler
  - Kendini çoğaltan her makine yığıtın bir kopyasını alır; makineler yığıtı paylaşmaz. Aynı durumda olup yığıtı farklı olan iki makine farklı davranır.
- Slaytlar dışında soru çözmek
  - Yalnız slaytlara bakmak yetmez; alıştırma setleri ve kitap sonu problemleri çözülmeli.

## Kısa Tekrar Notları

- Bağlamdan bağımsız gramer: $G = (V, T, S, P)$; dil $L(G) = \{w \in T^* : S \stackrel{*}{\Rightarrow} w\}$.
- Soldan üretim: hep en soldaki değişken açılır. Sağdan üretim: hep en sağdaki.
- Bir dizgenin iki farklı üretim ağacı (ya da iki farklı soldan üretimi) varsa gramer belirsizdir.
- Doğası gereği belirsiz dil: belirsiz olmayan bir gramer yazılamaz; örnek $\{a^n b^n c^m\} \cup \{a^n b^m c^m\}$.
- Yerine koyma: $A \to xBz$, $B \to y_1$ ise $A \to xBz \mid x y_1 z$ ekle, $B \to y_1$'i sil.
- Null üretim: $X \to \varepsilon$; başlangıç değişkeninde atılamaz.
- Birim üretim: $X \to Y$; $B \to B$ ve tekrar eden kurallar doğrudan silinir.
- Gereksiz değişken: ya hiç sonlanmaz ya da $S$'den ulaşılamaz.
- Sadeleştirme sırası: null, birim, gereksiz.
- CNF: $A \to BC$ ya da $A \to a$. GNF: $A \to a V_1 \cdots V_k$, $k \ge 0$.
- CNF'ye çevirme: $T_a \to a$ ekle, uzun kuralı $A \to C_1 V_1$, $V_1 \to C_2 V_2$, ..., $V_{n-2} \to C_{n-1} C_n$ diye böl.
- PDA geçişi: $a, b \to c$ (oku, çıkar, ekle). $\varepsilon$: o işlemi yapma.
- PDA kabulü: giriş bitmiş ve en az bir dal kabul durumunda; yığıt önemsiz.
- $a^n b^n$ PDA'sı: $a$'ları yığıta koy, her $b$ için bir $a$ çıkar, dipte $\$$ görünce kabul et.
- $v v^R$ PDA'sı: ilk yarıyı yığıta koy, $\varepsilon$ geçişiyle ortayı "tahmin et", ikinci yarıyı yığıtla eşleştir.

## Detaylı Açıklamalar

- **Yerine koyma ve sadeleştirme örnekleri (ekrandan).** $S \to aB$, $A \to aaA$, $A \to abBc$, $B \to aA$, $B \to b$ gramerinde önce $B \to b$ yerine konur: $S \to aB \mid ab$, $A \to aaA$, $A \to abBc \mid abbc$, $B \to aA$ (ekrandan, 00:35:00). Sonra $B \to aA$ yerine konur: $S \to aB \mid ab \mid aaA$, $A \to aaA$, $A \to abBc \mid abbc \mid abaAc$. Artık sol tarafta $B$ olmadığı için $aB$ ve $abBc$ seçenekleri hiçbir yere varmaz, silinir (ekrandan, 00:40:00).

- **Null üretim örneği.** $S \to aMb$, $M \to aMb$, $M \to \varepsilon$ gramerinde $M$ yerine boş dize konunca $a\varepsilon b = ab$ olur: $S \to aMb \mid ab$, $M \to aMb \mid ab$ (ekrandan, 00:45:00). Bütün null üretimler atılınca bütün boşalabilir değişkenler kaybolur; yalnız başlangıç değişkeni istisnadır.

- **Birim üretim örneği.** $S \to aA$, $A \to a$, $A \to B$, $B \to A$, $B \to bb$ gramerinde önce $A \to B$ atılır: $S \to aA \mid aB$, $B \to A \mid B$. $B \to B$ bilgi taşımadığı için silinir. Sonra $B \to A$ atılır: $S \to aA \mid aB \mid aA$. Tekrar eden $aA$ silinir; sonuç $S \to aA \mid aB$, $A \to a$, $B \to bb$ olur (ekrandan, 00:50:00).

- **Gereksiz üretim örneği.** $S \to aS \mid A \mid C$, $A \to a$, $B \to aa$, $C \to aCb$ grameri. Birinci aşamada bitiş sembolü üreten $A$ ve $B$ seçilir; $S \to A$ olduğu için $S$ de eklenir. $\{A, B, S\}$ dışındaki $C$'yi kullanan kurallar ($S \to C$, $C \to aCb$) silinir (ekrandan, 01:15:00). İkinci aşamada bağımlılık grafiği çizilir: $S$'den $S$'e döngü, $S$'den $A$'ya kenar vardır; bitiş sembolleri için kenar çizilmez. $B$'ye $S$'den ulaşılamaz, $B \to aa$ da silinir. Sonuç: $S \to aS \mid A$, $A \to a$; başlangıçtaki 6 kural ve 4 değişken yerine 3 kural ve 2 değişken kalır.

- **CNF dönüşüm örneği (ekrandan, 01:25:00).** $S \to ABa$, $A \to aab$, $B \to Ac$ gramerinde $T_a, T_b, T_c$ eklenir: $S \to ABT_a$, $A \to T_a T_a T_b$, $B \to AT_c$, $T_a \to a$, $T_b \to b$, $T_c \to c$. Üç değişkenli kurallar bölünür: $S \to AV_1$, $V_1 \to BT_a$, $A \to T_a V_2$, $V_2 \to T_a T_b$. Son gramerde daha çok kural vardır ama hepsi standart biçimdedir.

- **$a^n b^n$ PDA'sı (ekrandan, 02:10:00).** Geçişler:

  | Kaynak | Etiket (oku, çıkar $\to$ ekle) | Hedef |
  |---|---|---|
  | $q_0$ (başlangıç, kabul) | $\varepsilon, \varepsilon \to \varepsilon$ | $q_1$ |
  | $q_1$ | $a, \varepsilon \to a$ | $q_1$ |
  | $q_1$ | $b, a \to \varepsilon$ | $q_2$ |
  | $q_2$ | $b, a \to \varepsilon$ | $q_2$ |
  | $q_2$ | $\varepsilon, \$ \to \$$ | $q_3$ (kabul) |

  $q_0$ kabul durumudur, çünkü $n = 0$ olabilir (boş dize kabul edilir). $aaabbb$ kabul edilir: son $b$ okunduğunda yığıtta yalnız $\$$ kalır ve $q_3$'e geçilir. $aab$ reddedilir: $b$ okunduktan sonra yığıtın üstünde $a$ olduğu için $q_3$'e geçilemez, giriş $q_2$'de biter.

- **$v v^R$ PDA'sı (ekrandan, 02:30:00).** Geçişler:

  | Kaynak | Etiket | Hedef |
  |---|---|---|
  | $q_0$ (başlangıç) | $a, \varepsilon \to a$ ve $b, \varepsilon \to b$ | $q_0$ |
  | $q_0$ | $\varepsilon, \varepsilon \to \varepsilon$ | $q_1$ |
  | $q_1$ | $a, a \to \varepsilon$ ve $b, b \to \varepsilon$ | $q_1$ |
  | $q_1$ | $\varepsilon, \$ \to \$$ | $q_2$ (kabul) |

  $q_0$ ilk yarıyı yığıta koyar, $\varepsilon$ geçişi ortayı tahmin eder, $q_1$ okunan sembolü yığıtın üstüyle eşleştirir. Yığıt son giren ilk çıkar (LIFO) olduğu için ikinci yarının ilk yarının tersi olup olmadığı denetlenir. $abba$ kabul edilir; $abbb$ için kabul eden hesaplama yoktur, $abbb \notin L(M)$ (ekrandan, 02:45:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
