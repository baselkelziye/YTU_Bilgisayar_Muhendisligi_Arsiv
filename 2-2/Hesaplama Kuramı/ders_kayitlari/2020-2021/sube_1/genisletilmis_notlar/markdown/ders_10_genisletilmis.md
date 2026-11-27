# Ders 10 Genişletilmiş Notu: Yığıtlı Otomatlar (PDA) ve Bağlamdan Bağımsız Dillerin Kapanış Özellikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. PDA'nın Hatırlatılması: Yığıt ve Geçişler
- 2. PDA'nın Biçimsel Tanımı
- 3. Anlık Betimlemeler, Hesaplama ve PDA'nın Dili
- 4. Örnek: $a^{2n+1}b^{3n}$ için Gramer ve PDA
- 5. Bağlamdan Bağımsız Olmayan Bir Dil: $a^nb^{2n}a^{3n}$
- 6. Sonlu Bir Dil: NFA'dan PDA'ya
- 7. Bağlamdan Bağımsız Gramerden PDA'ya Doğrudan Çevirme
- 8. Kapanış Özelliği: Birleştirme (Concatenation)
- 9. Kapanış Özelliği: Birleşim (Union)
- 10. Kapanış Özelliği: Kleene Yıldızı
- 11. Kesişim ve Tümleme
- 12. Sınıf Sorusu: Üç Dilin Sınıflandırılması
- 13. Geçen Yılın Ödevinden Örnekler
- Örnek Sorular

## 1. PDA'nın Hatırlatılması: Yığıt ve Geçişler

Ders, önceki derste görülen yığıtlı otomatların (pushdown automata, PDA) kısa bir hatırlatmasıyla başlar. Önceki derste verilen gramerler PDA ile gerçeklenmişti. Hoca PDA'nın NFA ve DFA'dan farkını tek cümleyle özetler: PDA'da fazladan bir **yığıt** (stack) vardır ve durumlar arasındaki geçişler hem girdiye hem de bu yığıtın içindeki değerlere göre yapılır.

Ekrandaki geçiş şöyledir (ekrandan, 00:10:00):

$$q_1 \xrightarrow{\;a,\ w_1 \to w_2\;} q_2$$

Bu etiket şunu söyler: girdi sembolü $a$ iken ve yığıtın tepesinde $w_1$ dizgisi varsa bu geçiş geçerlidir; $w_1$ yığıttan çıkarılır (pop), yerine $w_2$ konur (push) ve makine $q_2$'ye geçer. Aynı geçiş, $\delta$ sembolüyle gösterilen geçiş fonksiyonu olarak

$$\delta(q_1, a, w_1) = \{(q_2, w_2)\}$$

diye yazılır.

### 1.1 Neden bir küme?

Hoca sağ tarafın tek bir çift değil, çiftlerden oluşan bir **küme** olduğuna dikkat çeker. Bunun nedeni PDA'ların deterministik olmamasıdır: aynı $(q_1, a, w_1)$ için makine birden çok duruma gidebilir:

$$\delta(q_1, a, w_1) = \{(q_2, w_2),\ (q_3, w_3),\ \dots\}$$

Hoca bunu iki dallı bir örnekle anlattı. Yığıtın dibinde $\$$, üstünde $w_1$ varken makine $q_1$'deyken $a$ okunur. Bir dalda makine $q_2$'ye gider ve yığıtta $w_1$'in yerini $w_2$ alır; öbür dalda $q_3$'e gider ve $w_1$'in yerini $w_3$ alır. Bu iki geçiş aynı anda (simultaneously) çalışır, yani bir sonraki adımda makine hem $q_2$'de hem $q_3$'tedir ve her dalın kendi yığıtı vardır.

> **Ek bilgi (derste anlatılmadı):** NFA'da da aynı anda birden çok durumda bulunulur; PDA'da fark, her dalın ayrı bir yığıt kopyası taşımasıdır. Deterministik PDA'lar (DPDA) bütün bağlamdan bağımsız dilleri tanıyamaz, bu yüzden "PDA" denince genelde deterministik olmayan model kastedilir.

## 2. PDA'nın Biçimsel Tanımı

Ekrandaki tanım yedi bileşenlidir (ekrandan, 00:15:00):

$$M = (Q, \Sigma, \Gamma, \delta, q_0, z, F)$$

- $Q$: durumlar kümesi ($q_1, q_2, q_3, \dots$).
- $\Sigma$: girdi alfabesi.
- $\Gamma$: yığıt alfabesi.
- $\delta$: geçiş fonksiyonu.
- $q_0$: başlangıç durumu.
- $z$: yığıt başlangıç sembolü. Hoca bunu genelde $\$$ ile gösterdiklerini söyledi; yığıtın dibini işaret eder.
- $F$: kabul (final) durumları kümesi.

## 3. Anlık Betimlemeler, Hesaplama ve PDA'nın Dili

### 3.1 $a^nb^n$ PDA'sı

Hoca anlık betimlemeleri (instantaneous descriptions) şu PDA üzerinde gösterdi (ekrandan, 00:20:00):

| Geçiş | Etiket |
|---|---|
| $q_0 \to q_1$ | $\varepsilon, \varepsilon \to \varepsilon$ |
| $q_1 \to q_1$ (döngü) | $a, \varepsilon \to a$ |
| $q_1 \to q_2$ | $b, a \to \varepsilon$ |
| $q_2 \to q_2$ (döngü) | $b, a \to \varepsilon$ |
| $q_2 \to q_3$ | $\varepsilon, \$ \to \$$ |

Kabul durumları $q_0$ ve $q_3$'tür. Makine her $a$ için yığıta bir $a$ koyar, her $b$ için yığıttan bir $a$ çıkarır. Bütün $b$'ler bitince yığıtta yalnız $\$$ kalmışsa, hiçbir şey okumadan $\$$ çıkarılıp geri konur ($\varepsilon, \$\to\$$) ve kabul durumuna geçilir. Hoca bu son geçişin anlamını şöyle açıkladı: yığıtta yalnız $\$$ olduğunu görmek, yığıtın boşaldığının göstergesidir.

### 3.2 Bir hesaplama

Anlık betimleme $(q, \text{kalan girdi}, \text{yığıt})$ üçlüsüdür ve bir adım $\succ$ ile gösterilir. $aaabbb$ için hesaplama (ekrandan, 00:20:00):

$$(q_0,aaabbb,\$) \succ (q_1,aaabbb,\$) \succ (q_1,aabbb,a\$) \succ (q_1,abbb,aa\$) \succ (q_1,bbb,aaa\$)$$
$$\succ (q_2,bb,aa\$) \succ (q_2,b,a\$) \succ (q_2,\varepsilon,\$) \succ (q_3,\varepsilon,\$)$$

İlk adımda girdi değişmez, çünkü $q_0\to q_1$ geçişi $\varepsilon$ geçişidir. Sonra her $a$ okunduğunda girdi bir sembol kısalır, yığıta bir $a$ eklenir. $b$'lere gelince $q_2$'ye geçilir ve her $b$ yığıttan bir $a$ siler. Hoca tek bir adımı da örnek olarak yazdı: $(q_1, bbb, aaa\$) \succ (q_2, bb, aa\$)$.

Çok adımlı hesaplama $\succ^*$ ile gösterilir: $(q_0, aaabbb, \$) \succ^* (q_3, \varepsilon, \$)$.

### 3.3 PDA'nın dili

Genel tanım: $M$ PDA'sının dili, başlangıç durumunda, yığıtta yalnız $z$ varken başlayıp girdiyi tamamen tüketerek bir kabul durumuna ulaşılabilen dizgilerden oluşur:

$$L(M) = \{ w : (q_0, w, z) \succ^* (q_f, \varepsilon, s),\ q_f \in F \}$$

Burada $s$ yığıtta kalan herhangi bir içeriktir. Örnekteki makine için (ekrandan, 00:25:00):

$$L(M) = \{a^nb^n : n \ge 0\}$$

## 4. Örnek: $a^{2n+1}b^{3n}$ için Gramer ve PDA

### 4.1 Gramer tartışması

Tablette verilen dil (ekrandan, 00:30:00):

$$L = \{a^{2n+1}b^{3n} : n \ge 0\}$$

Hoca önce dilin gramerini sordu ve ekrana bir gramer yazdı:

$$S \to aS \mid aaAbbb, \qquad A \to aaAbb \mid \varepsilon$$

Sonra sınıfa bu gramerin dili üretip üretmediğini sordu. Sınıfla birlikte $aaabbb$ gibi dizgiler üzerinden konuşuldu; hoca $A$ kuralında üç $b$ olması gerektiğini ve $n\ge 0$ olduğu için bir de $\varepsilon$ seçeneği eklenmesi gerektiğini söyledi. Hoca $n>0$ olsaydı $\varepsilon$ seçeneğinin olmayacağını, $\ge$ olduğu için de olması gerektiğini vurguladı. Ekrandaki son hâl şudur (ekrandan, 00:35:00):

$$S \to aS \mid aaAbbb \mid \varepsilon, \qquad A \to aaAbbb \mid \varepsilon$$

> **Ders sonrası not:** Ekrana yazılan iki gramer de dili tam üretmez. $S\to aS$ kuralı $a$ sayısını serbest bırakır ($aabbb$, $aa$ gibi dilde olmayan dizgiler çıkar) ve $S\to\varepsilon$ boş dizgiyi üretir, oysa en kısa eleman $a$'dır. Doğru bir gramer $S \to aaSbbb \mid a$'dır: her $aaSbbb$ adımı $n$'yi bir artırır, $a$ ile de tek $a$ eklenir. Bu gramer python ile $|w|\le 12$ için dille karşılaştırıldı ve eşit çıktı; ekrandaki iki gramer eşit çıkmadı.

### 4.2 PDA

PDA kurulurken hoca şu sayma fikrini kullandı (ekrandan, 00:35:00 ve 00:40:00): $a$'ların ve $b$'lerin sayısını yığıtta eşitlemek için her $a$ için yığıta üç $x$ konur, her $b$ için yığıttan iki $x$ çıkarılır. İlk (tek) $a$ ayrı okunur.

| Geçiş | Etiket |
|---|---|
| $q_0 \to q_1$ | $a, \$ \to \$$ (ilk $a$ okunur, yığıt değişmez) |
| $q_1 \to q_1$ (döngü) | $a, \varepsilon \to xxx$ |
| $q_1 \to q_2$ | $b, xx \to \varepsilon$ |
| $q_2 \to q_2$ (döngü) | $b, xx \to \varepsilon$ |
| $q_2 \to q_3$ | $\varepsilon, \$ \to \$$ |

Sayım şöyle tutar: ilk $a$'dan sonra $2n$ tane $a$ kalır ve bunlar $2n\cdot 3 = 6n$ tane $x$ koyar; $3n$ tane $b$ ise $3n \cdot 2 = 6n$ tane $x$ çıkarır. Yığıtta yalnız $\$$ kalınca $q_3$'e geçilir.

Hoca biraz sonra bir düzeltme yaptı (00:37:49 civarı): $n = 0$ için dilin elemanı $w = a$'dır ve bu dizgi okunduktan sonra makine $q_1$'de kalır. Bu yüzden $q_1$ de kabul durumu olmalıdır. Hoca bunu, $q_1$'i ayrı bir kabul durumu olarak ekleyip geri kalan zinciri kaydırarak çizdi; sonuçta iki kabul durumu vardır. (Düzeltilmiş çizimde durum adları yeniden numaralandı; ekrandaki son çizimin bütün etiketleri karelerde okunmuyor.)

<!-- BELİRSİZ: 00:37-00:39 arasındaki yeniden numaralandırılmış PDA çiziminin tam etiketleri karelerde görünmüyor; fikir altyazıdan alındı. -->

Yukarıdaki tablo ile $q_1$ kabul durumu olarak, PDA python ile $|w|\le 12$ olan bütün $\{a,b\}$ dizgileri üzerinde dille karşılaştırıldı ve doğru çıktı.

## 5. Bağlamdan Bağımsız Olmayan Bir Dil: $a^nb^{2n}a^{3n}$

Hoca ardından şu dili sordu (ekrandan, 00:40:00):

$$L = \{a^nb^{2n}a^{3n} : n \ge 0\}$$

"Bu dil için PDA tasarlanabilir mi?" sorusuna bir öğrenci desende birden fazla bağlantı olduğu için yapılamayacağını söyledi; hoca doğruladı. Bu dil bağlamdan bağımsız (CFL) değildir; bu yüzden PDA bu dili tanıyacak kadar güçlü değildir. Daha güçlü bir makine gerekir: Turing makinesi.

> **Ek bilgi (derste anlatılmadı):** Böyle dillerin bağlamdan bağımsız olmadığı, bağlamdan bağımsız diller için pompalama önsavıyla ispatlanır. Tek bir yığıt yalnız bir sayıyı "hatırlayıp" bir kez karşılaştırabilir; burada aynı $n$ üç blokla karşılaştırılmalıdır.

## 6. Sonlu Bir Dil: NFA'dan PDA'ya

Sonraki dil $a^n b^{2^n}$ biçiminde, $n$ yalnız birkaç değer alan sonlu bir dildir (ekrandan, 00:45:00). Hoca önce bir öğrenciye dilin düzenli mi bağlamdan bağımsız mı olduğunu sordu. Cevap şöyle verildi: dilin eleman sayısı sonludur ($|L| = 4$, yani $|L| < \infty$), bu yüzden dil düzenlidir. Düzenli diller bağlamdan bağımsız dillerin alt kümesi olduğu için dil aynı zamanda bağlamdan bağımsızdır.

<!-- BELİRSİZ: Dilin tam tanımı karelerde görünmüyor; altyazıya göre n değerleri ve b sayıları (n=1 için 2, n=2 için 4, n=3 için 16 (büyük olasılıkla 8) b) kesin okunamıyor. -->

Dil düzenli olduğu için doğrudan bir NFA çizilebilir: $q_0$ kabul durumudur (boş dizgi için), oradan bir $a$ ve iki $b$ ile bir kabul durumuna, iki $a$ ve dört $b$ ile başka bir kabul durumuna giden zincirler vardır (ekrandan, 00:45:00). Hoca bu NFA'yı PDA'ya çevirmenin çok basit olduğunu gösterdi: her geçiş etiketine yığıtı değiştirmeyen bir kısım eklenir, örneğin $a, \$ \to \$$ ("$\$$'ı çıkar, $\$$'ı geri koy"). Hoca daha sonraki bir örnekte bunun yerine $\varepsilon\to\varepsilon$ da yazılabileceğini söyledi.

Buradan çıkan sonuç: NFA'larla tanınan diller kümesi PDA'larla tanınan diller kümesinin alt kümesidir.

## 7. Bağlamdan Bağımsız Gramerden PDA'ya Doğrudan Çevirme

İlk aradan sonra hoca yeni bir teknik gösterdi: verilen bir bağlamdan bağımsız gramerin kurallarını kullanarak PDA'yı doğrudan kurmak.

### 7.1 Genel kalıp

Her bağlamdan bağımsız gramer şu biçimde bir PDA ile gerçeklenebilir (ekrandan, 01:05:00 ve 01:10:00):

```text
q0 --(eps, eps -> S$)--> q1 --(eps, $ -> eps)--> q2 (kabul)
q1 üzerinde döngüler:
  her kural A -> u için:   eps, A -> u
  her terminal a için:     a, a -> eps
```

Makine başta yığıta başlangıç değişkenini ve $\$$'ı koyar. Ortadaki durumda yığıtın tepesinde bir değişken varsa, girdi okumadan o değişken bir kuralın sağ tarafıyla değiştirilir. Tepede bir terminal varsa, girdideki aynı sembol okunur ve terminal yığıttan silinir. Yığıtta yalnız $\$$ kaldığında kabul durumuna geçilir. Hoca kalıbı ilk çizerken çıkış geçişinin girdisini yazmayı unuttuğunu fark edip $\varepsilon$ ekledi (01:10:44 civarı).

<!-- BELİRSİZ: 01:04:59-01:08:58 arasında gösterilen ilk örnek gramer ("S -> AB ...") altyazıda bozuk ve karelerde görünmüyor; bu örnek nota alınmadı. -->

### 7.2 Örnek: $B \to aBb \mid \varepsilon$

Başlangıç değişkeni $B$ olan gramer (ekrandan, 01:10:00):

$$B \to aBb \mid \varepsilon$$

PDA: $q_0 \xrightarrow{\varepsilon,\varepsilon\to B\$} q_1 \xrightarrow{\varepsilon,\$\to\varepsilon} q_2$; $q_1$ üzerindeki döngüler $\varepsilon, B\to aBb$, $\varepsilon, B\to\varepsilon$, $a, a\to\varepsilon$, $b, b\to\varepsilon$. Hoca önce kuralları, sonra terminalleri döngüye ekledi.

### 7.3 Örnek: $T \to 11T0 \mid W$, $W \to 0W \mid \varepsilon$

Altyazıya göre gramer şudur:

$$T \to 11T0 \mid W, \qquad W \to 0W \mid \varepsilon$$

Başta yığıta $T\$$ konur. Döngüler: $\varepsilon, T \to 11T0$; $\varepsilon, T\to W$; $\varepsilon, W\to 0W$; $\varepsilon, W\to\varepsilon$; terminaller için $0, 0\to\varepsilon$ ve $1, 1\to\varepsilon$. Hoca bu örneğe "çok basit" dedi.

<!-- BELİRSİZ: Bu gramer karelerde görünmüyor; kurallar altyazıdan (01:11:40-01:13:22) kuruldu. -->

### 7.4 Örnek: $L = \{a^n : n > 2\}$

Dil (ekrandan, 01:15:00 ve 01:20:00):

$$L = \{a^n : n > 2\}$$

Hoca önce hangi dizgilerin dilde olduğunu yazdı: $\varepsilon \notin L$, $a \notin L$, $aa \notin L$, $aaa \in L$, $a^4 \in L$, ... Gramer:

$$S \to aaaA, \qquad A \to aA \mid \varepsilon$$

Bu dil için iki ayrı PDA gösterildi (ekrandan, 01:20:00):

1. **NFA'dan çevrilen PDA:** NFA $q_0 \xrightarrow{a} q_1 \xrightarrow{a} q_2 \xrightarrow{a} q_3$ zinciri ve $q_3$ üzerinde $a$ döngüsüdür; $q_3$ kabul durumudur. PDA'da her etikete $\varepsilon\to\varepsilon$ eklenir: $a, \varepsilon\to\varepsilon$.
2. **Gramerden kurulan PDA:** $q_0 \xrightarrow{\varepsilon,\varepsilon\to S\$} q_1 \xrightarrow{\varepsilon,\$\to\varepsilon} q_2$; $q_1$ döngüleri $\varepsilon, S\to aaaA$; $\varepsilon, A\to aA$; $\varepsilon, A\to\varepsilon$; $a, a\to\varepsilon$.

Hoca buradan şu sonucu çıkardı: bir dilin birden fazla PDA'sı olabilir; NFA'sı varsa NFA'dan, grameri varsa gramerden PDA kurulabilir.

## 8. Kapanış Özelliği: Birleştirme (Concatenation)

Hoca bağlamdan bağımsız dillerin kapanış özelliklerine geçti (önce yanlışlıkla "Turing makinelerinin" dedi, sonra düzeltti). İlk dil (ekrandan, 01:25:00):

$$L = \{a^nb^na^mb^m : m, n \ge 0\}$$

Hoca dilin bağlamdan bağımsız olup olmadığını sordu; bir öğrenci iki ayrı bağımsız desen olduğu için bağlamdan bağımsız olduğunu söyledi. Hoca gerekçeyi şöyle kurdu: $A = \{a^nb^n : n\ge 0\}$ olsun. $L$, bu dilin kendisiyle birleştirilmesidir:

$$L = A \cdot A = \{a^nb^n : n\ge 0\} \cdot \{a^kb^k : k\ge 0\}$$

İkinci dilde $n$ yerine $k$ yazmak bir şey değiştirmez, çünkü iki üs birbirinden bağımsızdır. Her iki parça için PDA vardır. Birinci PDA'nın kabul durumu ikincinin başlangıç durumuna bağlanırsa elde edilen yeni PDA $L$'yi tanır. Dolayısıyla $L$ bağlamdan bağımsızdır, çünkü iki bağlamdan bağımsız dilin birleştirilmesidir.

### 8.1 Gramer ve gramerden PDA

Gramer (ekrandan, 01:30:00):

$$S \to TZ, \qquad T \to aTb \mid \varepsilon, \qquad Z \to aZb \mid \varepsilon$$

PDA: $q_0 \xrightarrow{\varepsilon,\varepsilon\to S\$} q_1 \xrightarrow{\varepsilon,\$\to\varepsilon} q_2$; $q_1$ döngüleri $\varepsilon, S\to TZ$; $\varepsilon, T\to aTb$; $\varepsilon, T\to\varepsilon$; $\varepsilon, Z\to aZb$; $\varepsilon, Z\to\varepsilon$; $a, a\to\varepsilon$; $b, b\to\varepsilon$ (ekrandan, 01:30:00).

### 8.2 Klasik yöntemle PDA

Hoca aynı dili "klasik yöntemle", yani yığıtla sayarak da kurdu. Önce $a^nb^n$ PDA'sı:

| Geçiş | Etiket |
|---|---|
| $q_0 \to q_1$ | $\varepsilon, \varepsilon \to \$$ |
| $q_1 \to q_1$ (döngü) | $a, \varepsilon \to x$ |
| $q_1 \to q_2$ | $b, x \to \varepsilon$ |
| $q_2 \to q_2$ (döngü) | $b, x \to \varepsilon$ |
| $q_2 \to q_3$ | $\varepsilon, \$ \to \varepsilon$ |

Hoca burada da $n\ge 0$ koşuluna dikkat çekti: bu hâliyle makine boş dizgiyi tanımaz; $n\ge 0$ olduğu için başlangıç durumu da kabul durumu olmalıdır. $n > 0$ olsaydı çizim olduğu gibi doğru olurdu.

Sonra bu PDA'nın iki kopyası alınır ve birincinin kabul durumundan ikincinin başlangıç durumuna $\varepsilon,\varepsilon\to\varepsilon$ ("hiçbir şey çıkarma, hiçbir şey koyma") geçişi eklenir (ekrandan, 01:35:00). Bu PDA da aynı dili tanır; hoca iki çözümün de doğru olduğunu söyledi.

> **Hocanın vurgusu:** İki bağlamdan bağımsız dilin birleştirilmesi yine bağlamdan bağımsızdır; dolayısıyla birleştirilmiş dili tanıyan bir PDA vardır. Hoca bu sonucu "çok önemli" diye işaretledi.

## 9. Kapanış Özelliği: Birleşim (Union)

Diller (ekrandan, 01:40:00):

$$L_1 = \{a^nb^n : n\ge 0\}, \qquad L_2 = \{a^{2n}b^{3n} : n\ge 0\}$$

İkisi de bağlamdan bağımsızdır. Birleşimleri

$$L = L_1 \cup L_2 = \{a^nb^n\} \cup \{a^{2m}b^{3m}\}, \quad m, n \ge 0$$

İki dilde farklı değişken adları kullanılması gerektiğini hoca ayrıca belirtti. Gerekçe: iki dilin PDA'ları paralel çalıştırılabilir.

> **Ders sonrası not:** Hoca burada (01:39:46) "bu da düzenli bir dildir" dedi; doğrusu bağlamdan bağımsız bir dildir. $\{a^nb^n\}$ düzenli olmadığı için birleşim de düzenli değildir (büyük olasılıkla dil kayması; hemen ardından gerekçeyi bağlamdan bağımsız diller üzerinden verdi).

Gramer için yeni bir başlangıç değişkeni iki dilin gramerlerine dallanır:

$$S \to S_1 \mid S_2, \qquad S_1 \to aS_1b \mid \varepsilon, \qquad S_2 \to aaS_2bbb \mid \varepsilon$$

<!-- BELİRSİZ: Altyazıda S2 kuralı "S1B" diye bozuk yazılmış; S1 ve S2 kuralları dillerin tanımından kuruldu, karelerde görünmüyor. -->

Bu gramerden 7. bölümdeki kalıpla PDA kurulur: $q_0 \xrightarrow{\varepsilon,\varepsilon\to S\$} q_1 \to q_2$ (kabul) ve $q_1$ üzerinde her kural ve terminal için döngüler.

> **Hocanın vurgusu:** Bağlamdan bağımsız dillerin birleşimi yine bağlamdan bağımsızdır; birleşimi tanıyan PDA'lar vardır. Hoca bunu da "çok önemli" dedi.

## 10. Kapanış Özelliği: Kleene Yıldızı

Bağlamdan bağımsız diller Kleene yıldızı işlemi altında da kapalıdır: $L_1$ bağlamdan bağımsızsa $L_1^*$ de öyledir. Örnek (ekrandan, 02:05:00):

$$L_1 = \{a^nb^n : n\ge 0\}, \qquad L_1^* = \{a^nb^n : n\ge 0\}^*$$

$L_1$'in grameri $S\to aSb \mid \varepsilon$'dur. Kleene yıldızı dili kendisiyle olası bütün sayılarda birleştirmek olduğu için gramer şöyle kurulur (altyazıya göre):

$$S \to S_1S \mid \varepsilon, \qquad S_1 \to aS_1b \mid \varepsilon$$

Bu gramer python ile denetlendi; ürettiği en kısa dizgiler $\varepsilon$, $ab$, $abab$, $aabb$, $aaabbb$, $abaabb$, ... olup hepsi $a^nb^n$ bloklarının art arda gelmesidir.

### 10.1 Gramerden PDA

Kalıp aynıdır: $q_0 \xrightarrow{\varepsilon,\varepsilon\to S\$} q_1 \xrightarrow{\varepsilon,\$\to\varepsilon} q_2$; $q_1$ üzerinde kural döngüleri ve terminaller için $a, a\to\varepsilon$, $b, b\to\varepsilon$ (ekrandan, 02:10:00).

### 10.2 Klasik yöntemle PDA

Hoca alternatif olarak yığıtla sayan $a^nb^n$ PDA'sını ($a,\varepsilon\to x$; $b,x\to\varepsilon$; $\varepsilon,\$\to\varepsilon$) aldı ve iki değişiklik yaptı (ekrandan, 02:10:00):

- $n = 0$ için boş dizgi $L_1$'in elemanı olduğundan $q_0$ da kabul durumu yapılır; böylece iki kabul durumu olur.
- Son durum $q_3$'ten başlangıç $q_0$'a bir $\varepsilon$ geri besleme (feedback) geçişi eklenir. Bu geri besleme, bir $a^nb^n$ bloğu bittikten sonra yeni bir bloğa başlamayı sağlar ve Kleene yıldızını gerçekler.

## 11. Kesişim ve Tümleme

### 11.1 Kesişim

$L_1$ ve $L_2$ bağlamdan bağımsızsa $L_1 \cap L_2$'nin bağlamdan bağımsız olması gerekmez. Örnek (ekrandan, 02:15:00):

$$L_1 = \{a^nb^nc^m : m,n\ge 0\}, \qquad L_2 = \{a^mb^nc^n : m,n\ge 0\}$$

$L_1$'de $a$ ile $b$, $L_2$'de $b$ ile $c$ eşleşir; ikisi de bağlamdan bağımsızdır. Kesişimleri ise

$$L_3 = L_1 \cap L_2 = \{a^nb^nc^n : n\ge 0\}$$

olur ve bu dil bağlamdan bağımsız değildir. Yani bağlamdan bağımsız diller kesişim altında kapalı değildir. Hoca bu sonucu da "çok önemli" diye vurguladı.

### 11.2 Tümleme

Bir dilin tümleyeni, bütün dizgilerden o dilin çıkarılmasıyla elde edilir. Hoca bağlamdan bağımsız bir dilin tümleyeninin bağlamdan bağımsız olmak zorunda olmadığını söyledi ve bir örnek kurmaya çalıştı, ancak kurduğu gerekçenin "güçlü bir iddia olmadığını" kendisi belirtti.

<!-- BELİRSİZ: 02:16-02:19 arasında tümleme için verilen örnek altyazıda bozuk ve karelerde görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Standart gerekçe De Morgan kuralıdır: $L_1 \cap L_2 = \overline{\overline{L_1} \cup \overline{L_2}}$. Bağlamdan bağımsız diller birleşim altında kapalı olduğuna göre, tümleme altında da kapalı olsalardı kesişim altında da kapalı olurlardı; bu, 11.1'deki örnekle çelişir.

## 12. Sınıf Sorusu: Üç Dilin Sınıflandırılması

Hoca tablete bir soru yazıp sınıfa sordu (ekrandan, 02:25:00). Soru ve çözüm "Örnek Sorular" bölümünde ayrıntılı verilmiştir. Çözümdeki yöntem şudur: desendeki sayılar arasındaki ilişkilere bakılır. $a^mb^n$'de $a$ ve $b$ sayıları bağımsızdır, dil düzenlidir; düzenli olduğu için bağlamdan bağımsızdır ve PDA'sı vardır. $a^nb^n$ düzenli değildir ama bağlamdan bağımsızdır. $a^nb^nc^n$ ne düzenli ne bağlamdan bağımsızdır, PDA'sı yoktur.

## 13. Geçen Yılın Ödevinden Örnekler

Dersin son bölümünde hoca bir önceki yılın ikinci ödevinden soruları tablete yükleyip sınıfla birlikte çözdü. Soruların metni ve çözümleri "Örnek Sorular" bölümündedir. Burada yalnız anlatılan yöntemler özetlenir:

- Sınıflandırma sorularında önce desendeki bağıntı sayısına bakılır. Birden fazla bağıntı varsa dil düzenli değildir ve bu pompalama önsavıyla, deseni bozarak gösterilir.
- "İlk, orta ve son karakter aynı" gibi koşullarda orta karakter önce sabitlenir, sonra sağına ve soluna birer karakter eklenerek büyütülür. Böylece orta karakter hep merkezde kalır.
- Bir gramerin en kısa dizgilerini bulmak için önce en kısa sonlanan türetmeler denenir, sonra özyinelemeli kurallar birer kez açılır.
- Bir gramerin belirsiz (ambiguous) olduğunu göstermek için aynı dizginin iki farklı en soldan türetmesi bulunur.
- Koşullardaki $\ge 1$ ile $\ge 0$ farkı gramerde $\varepsilon$ kuralının olup olmamasını belirler.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $L = \{a^{2n+1}b^{3n} : n\ge 0\}$ dilinin grameri nedir? Bu dil için bir PDA tasarlayın.

> **Çözüm:** Derste PDA şöyle kuruldu: ilk $a$ ile $q_0\to q_1$ ($a, \$\to\$$); $q_1$'de her $a$ için $a, \varepsilon\to xxx$; her $b$ için $b, xx\to\varepsilon$ ($q_1\to q_2$ ve $q_2$ döngüsü); yığıtta $\$$ kalınca $\varepsilon, \$\to\$$ ile kabul. $w = a$ için $q_1$ de kabul durumudur. Derste ekrana yazılan gramer dili tam üretmiyordu (4.1'deki ders sonrası nota bakın); doğru gramer $S\to aaSbbb \mid a$'dır (python ile denetlendi).

**Soru 2** (ekrandan, 00:40:00): $L = \{a^nb^{2n}a^{3n} : n\ge 0\}$ için bir PDA tasarlanabilir mi?

> **Çözüm:** Hayır. Dil bağlamdan bağımsız değildir; PDA bu dili tanıyacak güçte değildir, Turing makinesi gerekir.

**Soru 3** (ekrandan, 01:15:00): $L = \{a^n : n > 2\}$ dilinin gramerini ve PDA'sını bulun.

> **Çözüm:** $S\to aaaA$, $A\to aA\mid\varepsilon$. NFA'dan çevrilen PDA ($a,\varepsilon\to\varepsilon$ etiketli üç adım ve kabul durumunda döngü) ya da gramerden kurulan PDA (7.4).

**Soru 4** (ekrandan, 01:25:00): $L = \{a^nb^na^mb^m : m,n\ge 0\}$ bağlamdan bağımsız mıdır?

> **Çözüm:** Evet. $L = \{a^nb^n\}\cdot\{a^kb^k\}$, iki bağlamdan bağımsız dilin birleştirilmesidir. Gramer $S\to TZ$, $T\to aTb\mid\varepsilon$, $Z\to aZb\mid\varepsilon$.

**Soru 5** (ekrandan, 02:25:00): $L_1 = \{a^mb^n : m,n\ge 0\}$, $L_2 = \{a^nb^n : n\ge 0\}$, $L_3 = \{a^nb^nc^n : n\ge 0\}$ dilleri veriliyor. Hangileri doğrudur?

- a) $L_1$ ve $L_2$'yi tanımak için PDA kullanılabilir.
- b) $L_1$ düzenli bir dildir.
- c) Üç dilin hepsi bağlamdan bağımsızdır.
- d) Üç dilin hepsinin bağlamdan bağımsız grameri vardır.

> **Çözüm:** $L_1$ düzenli, dolayısıyla bağlamdan bağımsız ve PDA'sı var. $L_2$ düzenli değil ama bağlamdan bağımsız, PDA'sı var. $L_3$ ne düzenli ne bağlamdan bağımsız, PDA'sı yok. Sonuç: a) doğru, b) doğru, c) yanlış, d) yanlış ($L_3$'ün bağlamdan bağımsız grameri yoktur).

**Soru 6** (ekrandan, 02:30:00): Aşağıdaki dilin sınıfını (düzenli, düzenli olmayan bağlamdan bağımsız, hiçbiri) belirtip ispatlayın: $L = \{w \in \{0,1\}^* : \exists k\ge 0$ ve $w$, $2k+1$'in ikilik gösterimidir (baştaki sıfırlara izin var)$\}$.

> **Çözüm (derste verilmedi):** Hoca soruyu okuyup "biraz karışık" diyerek geçti. $2k+1$ tek sayılardır; bir sayının ikilik gösterimi tek ise son biti 1'dir. Dolayısıyla $L = \{0,1\}^*1$ olur ve $(0\cup 1)^*1$ düzenli ifadesiyle tanımlandığı için dil düzenlidir.

**Soru 7** (derste sözlü, 02:30:50-02:33:40): $L = \{a^nb^nc^n\}$'nin $a^*b^*c^*$'den çıkarılmasıyla elde edilen dil hangi sınıftadır?

> **Çözüm:** Hoca dili $\{a^mb^nc^k : m\ne n \text{ veya } n\ne k\}$ diye yeniden yazdı. Desende $a$-$b$ ve $b$-$c$ olmak üzere birden fazla bağıntı olduğu için dil düzenli değildir (pompalama önsavıyla gösterilebilir). Hoca önce yanlış söylediğini belirterek düzeltti: dil bağlamdan bağımsızdır, çünkü "$m\ne n$" ve "$n\ne k$" parçalarının her biri ayrı ayrı tanınabilir ve birleşim altında kapalılık vardır.

<!-- BELİRSİZ: Bu sorunun ekrandaki tam metni karelerde görünmüyor; dil altyazıdan kuruldu. -->

**Soru 8** (ekrandan, 02:35:00): $L = \{w \in \{a,b\}^* : w$'nin ilk, orta ve son karakteri aynıdır$\}$. a) $L$'yi üreten bir bağlamdan bağımsız gramer verin. b) $L$'yi tanıyan bir PDA tasarlayın. c) $L$'nin düzenli olmadığını ispatlayın.

> **Çözüm:** a) Hoca baş ve sonu sabitleyerek başladı: $S\to aAa \mid bBb$. Ortadaki karakteri garanti etmek için $A$ doğrudan $a$ olabilir (ortası $a$ olan en kısa dizgi $aaa$); $A$'nın sağına ve soluna her olası karakter çifti eklenir: $A\to aAa \mid aAb \mid bAa \mid bAb \mid a$. $B$ için aynısı $b$ ile yapılır: $B \to aBa \mid aBb \mid bBa \mid bBb \mid b$. Hoca dizginin en az üç karakterli olması gerektiğini söyledi. Bu gramer python ile denetlendi: ürettiği dizgiler, uzunluğu tek ve en az 3 olan, ilk, orta ve son karakteri aynı bütün dizgilerle ($|w|\le 9$) birebir aynıdır. b) Hoca PDA'yı 7. bölümdeki kalıpla doğrudan bu gramerden kurdu ($\varepsilon,\varepsilon\to S\$$; her kural ve terminal için $q_1$ döngüleri; $\varepsilon,\$\to\varepsilon$). c) Başta, ortada ve sonda bağıntı olduğu için dil düzenli değildir; hoca bunun deseni bozarak pompalama önsavıyla rahatça gösterilebileceğini söyledi, ispatı ayrıntılı yazmadı.

> **Ek bilgi (derste anlatılmadı):** c) için bir yol: pompalama uzunluğu $p$ iken $w = b\,a^{p}\,b\,a^{p}\,b$ alınabilir (uzunluk $2p+3$, orta karakter $b$). $|xy|\le p$ olduğundan $y$ baştaki $b$'yi ya da yalnız ilk $a$ bloğundan $j\ge 1$ tane $a$'yı içerir. İlk durumda $xz$ $a$ ile başlayıp $b$ ile biter. İkinci durumda $xy^2z$'nin uzunluğu $2p+3+j$ olur: $j$ tekse tek bir orta karakter yoktur, $j$ çiftse orta karakter ilk $a$ bloğuna kayar. Her durumda dizgi dilden çıkar.

**Soru 9** (ekrandan, 02:45:00): $G$: $S\to 1S1 \mid T$, $T\to 1X1 \mid X$, $X\to 0X0 \mid 1$. a) $L(G)$'nin en kısa dört dizgisi nedir? b) $|w| > 7$ ve $w\notin L(G)$ olan bir $w\in\{0,1\}^*$ örneği verin. c) $G$'nin belirsiz olduğunu gösterin.

> **Çözüm:** a) $S\to T\to X\to 1$ ile $1$; $X\to 0X0$ ile $010$; $T\to 1X1$ ile $111$; $X\to 0X0\to 00X00$ ile $00100$. En kısa dört dizgi $1, 010, 111, 00100$'dür (python ile doğrulandı). Hoca $1111111$'in de üretilebildiğini ama ilk dört içinde olmadığını belirtti. b) Hoca önce $S\to 1S1$'i dört kez açıp $111111111$ (uzunluk 9) dizgisini kurdu, sonra bunun dilin elemanı olduğunu, sorunun ise eleman *olmayan* bir dizgi istediğini fark etti. Gözlem: bütün kurallar sağa ve sola simetrik ekleme yapar ve orta karakter her zaman $1$'dir. Bu yüzden ortadaki karakter $0$ yapılırsa, örneğin $111101111$, dizgi dilde olmaz (python ile doğrulandı). c) $111$ dizgisinin iki türetmesi vardır: $S\Rightarrow 1S1\Rightarrow 1T1\Rightarrow 1X1\Rightarrow 111$ ve $S\Rightarrow T\Rightarrow 1X1\Rightarrow 111$. Aynı dizginin iki farklı türetmesi olduğu için $G$ belirsizdir.

**Soru 10** (ekrandan, 02:50:00): $L_2 = \{a^nc^mb^n : m,n\ge 1\}$ dilinin grameri nedir? $m\ge 0$ olsaydı ne değişirdi?

> **Çözüm:** Derste: $a$ ile $b$ sayıları eşit olacak şekilde $S\to aSb \mid Z$, ortada $c$'leri pompalayan $Z\to cZ \mid c$ yazıldı (ekranda $Z\to c$ kısmı görünüyor). $m\ge 0$ olsaydı $Z\to c$ yerine $Z\to\varepsilon$ gelirdi, çünkü $c$ sayısı sıfır olabilir.

> **Ders sonrası not:** $S\to aSb\mid Z$ kuralı $n = 0$'a da izin verir ($c$, $cc$ gibi dizgiler üretilir), oysa $n\ge 1$'dir. Doğrusu $S\to aSb \mid aZb$, $Z\to cZ\mid c$'dir (python ile $|w|\le 9$ için doğrulandı).

<!-- BELİRSİZ: 02:48:10-02:48:51 arasındaki L1 düzenli dilinin ifadesi altyazıda bozuk ("AA, A yıldız, B veya B"); karede yalnız A -> aA | ε kuralı görünüyor. 02:51:04 sonrasındaki son dil de okunamıyor. -->

## Dersin Toparlaması

Bu derste yığıtlı otomatların biçimsel tanımı, anlık betimlemeler ve PDA'nın dili tekrar edildi; $a^{2n+1}b^{3n}$ gibi sayma gerektiren bir dil için yığıta farklı sayıda sembol koyup çıkararak PDA kurmanın yolu gösterildi. Ardından her bağlamdan bağımsız gramerin, başlangıçta yığıta $S\$$ koyan, ortada kural ve terminal döngüleri bulunan ve sonda $\$$'ı çıkaran standart bir PDA ile gerçeklenebildiği görüldü. Aynı dilin hem NFA'dan hem gramerden kurulan farklı PDA'ları olabilir.

Dersin ikinci yarısı bağlamdan bağımsız dillerin kapanış özelliklerine ayrıldı: birleştirme, birleşim ve Kleene yıldızı altında kapalıdırlar; kesişim ve tümleme altında kapalı değildirler, $\{a^nb^nc^n\}$ bunun temel örneğidir. Son bölümde geçen yılın ödev soruları üzerinden dil sınıflandırma, gramer yazma, en kısa dizgileri bulma ve belirsizlik gösterme alıştırıldı. $a^nb^{2n}a^{3n}$ örneğinde değinildiği gibi, PDA'nın yetmediği diller için bir sonraki adım Turing makineleridir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
