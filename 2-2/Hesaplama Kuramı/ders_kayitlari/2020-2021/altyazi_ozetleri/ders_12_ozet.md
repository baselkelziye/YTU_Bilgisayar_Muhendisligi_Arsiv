# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin tarihi 1 Haziran 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl anlatım yaklaşık 00:06:30'da başlar. Kaydın başı bekleme kısmıdır.
  - Hoca tabletteki not uygulamasına el yazısıyla yazıyor. Ders bir arayla iki bölümden oluşuyor.
- Turing makinesi (Turing machine) tekrarı
  - Giriş şeridi iki yönde sonsuzdur. Giriş dışındaki bütün hücrelerde boş sembol (blank, $\square$) vardır.
  - Okuma-yazma kafası (read-write head) başta girişin ilk sembolünü gösterir.
  - Her adımda makine bir sembol okur, bir sembol yazar ve sola (L) ya da sağa (R) gider.
- Durma (halt), kabul ve ret kuralları
  - Uygun geçiş yoksa makine o durumda durur.
  - Kabul durumlarından dışarı geçiş yoktur. Makine kabul durumuna girince durur ve kabul eder.
- Örnek: $L = \{a^n b^n : n \ge 1\}$ dilini tanıyan Turing makinesi
  - Fikir: her $a$'yı bir $b$ ile eşleştirmek. $a$ yerine $x$, $b$ yerine $y$ yazılır.
  - `aabb` girişinde anlık tanımlarla (instantaneous description) adım adım çalıştırma
- Ev çalışması: makineyi $\{a^n b^n c^n : n \ge 1\}$ dilini tanıyacak biçimde değiştirmek
- Turing makinesinin biçimsel tanımı: 7'li $M = (Q, \Sigma, \Gamma, \delta, q_0, \square, F)$
- Anlık tanım, hesaplama (computation) ve $\vdash^*$ kısaltması
- Turing makinesinin kabul ettiği dil $L(M)$
- Turing ile tanınabilir dil (Turing recognizable / Turing acceptable / recursively enumerable)
- Turing makinesiyle fonksiyon hesaplama
  - Tekli gösterim (unary representation): $n$ sayısı $n$ tane 1 ile yazılır.
  - Hesaplanabilir fonksiyon (computable function) tanımı
- Örnek: $f(x, y) = x + y$ için Turing makinesi ve $2 + 2$ üzerinde çalıştırma
- Örnek: $f(x) = 2x$ için sözde kod (pseudocode) ve Turing makinesi
- Quiz duyurusu: aynı gün 11:25'te quiz

## Hocanın Özellikle Vurguladığı Kısımlar

- Turing makinesi, bağlamdan bağımsız dillerin (context-free languages) tanıyamadığı dilleri de tanır.
  - Örnek: $a^n b^n c^n$.
- Bu derste görülen Turing makineleri deterministiktir ve boş geçiş (null / $\lambda$ transition) yoktur.
  - Deterministik olmayan Turing makineleri ileride ayrıca görülecek.
- Deterministik olsa da Turing makinesi diyagramında her sembol için geçiş çizilmez.
  - Yalnız geçişi olan semboller gösterilir. Bu, DFA diyagramından farklıdır.
- Giriş tamamen okunmak zorunda değildir.
  - Kafa sola da gidebildiği için makine girişin bir kısmına hiç dokunmadan kabul edip durabilir.
- Anlık tanımları yazarken çok dikkatli olun.
  - Hoca `aabb` örneğinde bir adımda yön karıştırdı ve hesaplamayı baştan yazdı.
- Tekli gösterim, Turing makinesiyle işlem yapmayı kolaylaştırdığı için tercih edilir.
- Bundan sonra makineler büyüdükçe durum diyagramı yerine sözde kod verilecek.
  - Sözde kodun her satırı bir Turing makinesi parçasıyla yapılabilir.
- Quiz: 5 soru, 25 dakika, soru başına 5 dakika.
  - Bütün sınavlarda o güne kadar işlenen bütün konular dahildir.

## Kısa Tekrar Notları

- Turing makinesi: iki yönde sonsuz şerit, okuma-yazma kafası, durumlar, geçişler.
- Geçiş gösterimi: $a \to b, R$ demek "$a$ oku, $b$ yaz, sağa git" demek.
- Biçimsel geçiş: $\delta(q_1, a) = (q_2, b, R)$.
- 7'li tanım: $Q$ durumlar, $\Sigma$ giriş alfabesi, $\Gamma$ şerit alfabesi, $\delta$ geçiş fonksiyonu, $q_0$ başlangıç durumu, $\square$ boş sembol, $F$ kabul durumları.
- Anlık tanım: kafanın gösterdiği sembolün önüne durum yazılır. Örnek: `ca` $q_1$ `ba`.
- Kabul: makine kabul durumunda durur.
- Kabul etmeme: makine kabul olmayan bir durumda durur ya da sonsuz döngüye girer.
- $L(M) = \{ w : q_0 w \vdash^* x_1 q_f x_2,\ q_f \in F \}$.
- Bir dili tanıyan bir Turing makinesi varsa dil Turing ile tanınabilirdir (recursively enumerable).
- Tekli gösterim: 3 = `111`.
- $f$ hesaplanabilir: tanım kümesindeki her $w$ için $q_0 w \vdash^* q_f f(w)$, $q_f \in F$.
- $x + y$ makinesi: giriş `1^x 0 1^y`, çıkış `1^(x+y) 0`.
  - Ortadaki 0 yerine 1 yazılır, en sondaki 1 silinip 0 yapılır.
- $2x$ makinesi: önce bütün 1'ler `$` olur. Sonra her adımda en sağdaki `$` 1 yapılır ve sona bir 1 eklenir.

## Detaylı Açıklamalar

Turing makinesi, şimdiye kadar görülen otomatlara çok benzer: durumları, geçişleri, kabul ve ret durumları vardır. Fark, şeridin iki yönde sonsuz olması ve kafanın şeride yazıp her iki yöne gidebilmesidir.

### Turing makinesinin çalışması

- Başlangıçta giriş dizgisi şeridin ortasındadır. Kafa girişin ilk sembolünü gösterir.
- Giriş dışında her yerde boş sembol vardır.
- Her adımda makine:
  - Kafanın altındaki sembolü okur.
  - Yerine bir sembol yazar.
  - Sola ya da sağa bir hücre gider.
  - Yeni duruma geçer.
- Anlık tanım, şerit içeriğini ve o anki durumu birlikte gösterir.
  - Kafa `d` sembolünü gösteriyorsa durum `d`'nin hemen önüne yazılır.

### Durma, kabul ve ret

- Bulunulan durumdan, okunan sembol için geçiş yoksa makine durur (halt).
- Kabul durumlarından dışarı geçiş yoktur. Bu yüzden kabul durumuna giren makine durur ve girişi kabul eder.
- Kabul olmayan bir durumda duran makine girişi kabul etmez.
- Makine sonsuz döngüye girerse de girişi kabul etmez.

### Örnek: $\{a^n b^n : n \ge 1\}$

Algoritma (tahtadan):

- Tekrarla:
  - En soldaki $a$'yı $x$ ile değiştir.
  - En soldaki $b$'yi bul, $y$ ile değiştir.
- Ta ki başka $a$ ya da $b$ kalmayana kadar.
- Sonunda eşleşmemiş bir $a$ ya da $b$ kalırsa reddet.

Geçişler (tahtadaki diyagramdan, kareden doğrulandı). Kabul durumu $q_4$'tür.

| Durum | Okunan | Yazılan | Hareket | Sonraki durum | Görev |
| :---: | :---: | :---: | :---: | :---: | :--- |
| $q_0$ | $a$ | $x$ | R | $q_1$ | En soldaki $a$'yı işaretle |
| $q_0$ | $y$ | $y$ | R | $q_3$ | $a$ kalmadı, fazla $b$ var mı bak |
| $q_1$ | $a$ | $a$ | R | $q_1$ | Sağa ilerle |
| $q_1$ | $y$ | $y$ | R | $q_1$ | Sağa ilerle |
| $q_1$ | $b$ | $y$ | L | $q_2$ | En soldaki $b$'yi işaretle |
| $q_2$ | $y$ | $y$ | L | $q_2$ | Geri dön |
| $q_2$ | $a$ | $a$ | L | $q_2$ | Geri dön |
| $q_2$ | $x$ | $x$ | R | $q_0$ | Döngünün başına dön |
| $q_3$ | $y$ | $y$ | R | $q_3$ | $y$'leri geç |
| $q_3$ | $\square$ | $\square$ | L | $q_4$ | Fazla $b$ yok, kabul |

- $q_3$'te $b$ okunursa geçiş yoktur. Makine $q_3$'te durur ve reddeder; $b$'ler fazladır.
- `aabb` için doğru hesaplama:

$q_0aabb \vdash xq_1abb \vdash xaq_1bb \vdash xq_2ayb \vdash q_2xayb \vdash xq_0ayb \vdash xxq_1yb \vdash xxyq_1b \vdash xxq_2yy \vdash xq_2xyy \vdash xxq_0yy \vdash xxyq_3y \vdash xxyyq_3\square \vdash xxyq_4y$

### Ev çalışması: $\{a^n b^n c^n : n \ge 1\}$

Hoca bu değişikliği öğrencilere bıraktı. Aşağıdaki çözüm özete eklenmiştir, derste yapılmadı.

- Fikir: her turda bir $a$'yı $x$, bir $b$'yi $y$, bir $c$'yi $z$ yap.
- Geçişler:
  - $q_0$: $a \to x, R$ ile $q_1$; $y \to y, R$ ile $q_4$.
  - $q_1$: $a \to a, R$ ve $y \to y, R$ döngü; $b \to y, R$ ile $q_2$.
  - $q_2$: $b \to b, R$ ve $z \to z, R$ döngü; $c \to z, L$ ile $q_3$.
  - $q_3$: $a, b, y, z$ için aynı sembolü yazıp L döngü; $x \to x, R$ ile $q_0$.
  - $q_4$: $y \to y, R$ ve $z \to z, R$ döngü; $\square \to \square, L$ ile kabul durumu $q_5$.
- Bu makine $\{a, b, c\}$ üzerinde 9 sembole kadar bütün dizgilerde Python simülasyonuyla denendi. Yalnız $a^n b^n c^n$ ($n \ge 1$) dizgilerini kabul ediyor.

### Biçimsel tanım

- $M = (Q, \Sigma, \Gamma, \delta, q_0, \square, F)$
  - $Q$: durumlar kümesi.
  - $\Sigma$: giriş alfabesi.
  - $\Gamma$: şerit alfabesi (tape alphabet).
  - $\delta$: geçiş fonksiyonu, $\delta: Q \times \Gamma \to Q \times \Gamma \times \{L, R\}$.
  - $q_0$: başlangıç durumu.
  - $\square$: boş sembol.
  - $F$: kabul durumları.
- Hesaplama, art arda gelen anlık tanımlar listesidir.
  - Ara adımlar atlanıp $\vdash^*$ ile yazılabilir. Örnek: $q_2xayb \vdash^* xxyq_1b$ gibi.
- Başlangıç konfigürasyonu: $q_0 w$. Kafa $w$'nin ilk sembolündedir.
- Kabul edilen dil: $L(M) = \{ w : q_0 w \vdash^* x_1 q_f x_2,\ q_f \in F \}$.

### Turing ile tanınabilir diller

- $L$ dilini kabul eden bir Turing makinesi $M$ varsa $L$ Turing ile tanınabilirdir (Turing recognizable).
- Kaynaklarda aynı kavram için "Turing acceptable" ve "recursively enumerable" adları da geçer.
- Hoca, ileride bundan farklı olan Turing ile karar verilebilir dillerin (Turing decidable) görüleceğini söyledi.

### Turing makinesiyle fonksiyon hesaplama

- Fonksiyon, tanım kümesi $D$'deki her $w$'yi değer kümesindeki $f(w)$'ye götürür.
- Sayılar tekli gösterimle yazılır. Örnek: 5 = `11111`.
- Hesaplanabilir fonksiyon:
  - Tanım kümesindeki her $w$ için $q_0 w \vdash^* q_f f(w)$ olacak bir Turing makinesi vardır.
  - Sonunda kafa sonucun ilk sembolünde, makine bir kabul durumunda olmalıdır.
- Örnek: $f(x) = 2x$ için `11` girişi `1111` çıkışını vermelidir.

### Örnek: $f(x, y) = x + y$

- Giriş: `1^x 0 1^y`. Aradaki 0 ayırıcıdır.
- Çıkış: `1^(x+y) 0`. Sondaki 0, sonucun başka bir fonksiyona giriş olarak kullanılabilmesi için bırakılır.
- Fikir: ortadaki 0'ı 1 yap, en sondaki 1'i 0 yap, başa dön.

| Durum | Geçiş | Sonraki durum | Görev |
| :---: | :--- | :---: | :--- |
| $q_0$ | $1 \to 1, R$ | $q_0$ | $x$'in 1'lerini geç |
| $q_0$ | $0 \to 1, R$ | $q_1$ | Ayırıcıyı 1 yap |
| $q_1$ | $1 \to 1, R$ | $q_1$ | $y$'nin 1'lerini geç |
| $q_1$ | $\square \to \square, L$ | $q_2$ | Sona gelindi, bir geri dön |
| $q_2$ | $1 \to 0, L$ | $q_3$ | Son 1'i 0 yap |
| $q_3$ | $1 \to 1, L$ | $q_3$ | Başa dön |
| $q_3$ | $\square \to \square, R$ | $q_4$ | İlk sembole geç, kabul |

- $x = 2$, $y = 2$ için hesaplama:

$q_011011 \vdash 1q_01011 \vdash 11q_0011 \vdash 111q_111 \vdash 1111q_11 \vdash 11111q_1\square \vdash 1111q_21 \vdash 111q_310 \vdash 11q_3110 \vdash 1q_31110 \vdash q_311110 \vdash q_3\square11110 \vdash q_411110$

- Sonuç `11110`, yani $4$. Makine 0 ile 4 arasındaki bütün $x, y$ çiftlerinde Python simülasyonuyla denendi; hepsinde `1^(x+y) 0` çıktı.

### Örnek: $f(x) = 2x$

Sözde kod (tahtadan):

- Her 1'i `$` ile değiştir.
- Tekrarla:
  - En sağdaki `$`'ı bul, 1 ile değiştir.
  - Sağ uca git, bir 1 ekle.
- Ta ki `$` kalmayana kadar.

Turing makinesi (tahtadaki diyagramdan). Kabul durumu $q_3$'tür. Hoca $1 \to R$ yazımını "1 oku, 1 yaz, sağa git" kısaltması olarak tanıttı.

| Durum | Geçiş | Sonraki durum | Görev |
| :---: | :--- | :---: | :--- |
| $q_0$ | $1 \to \$, R$ | $q_0$ | Bütün 1'leri `$` yap |
| $q_0$ | $\square \to \square, L$ | $q_1$ | Sona gelindi |
| $q_1$ | $1 \to 1, L$ | $q_1$ | En sağdaki `$`'ı ara |
| $q_1$ | $\$ \to 1, R$ | $q_2$ | `$`'ı 1 yap |
| $q_2$ | $1 \to 1, R$ | $q_2$ | Sağ uca git |
| $q_2$ | $\square \to 1, L$ | $q_1$ | Sona 1 ekle |
| $q_1$ | $\square \to \square, R$ | $q_3$ | `$` kalmadı, kabul |

- `11` girişi için hesaplama:

$q_011 \vdash \$q_01 \vdash \$\$q_0\square \vdash \$q_1\$ \vdash \$1q_2\square \vdash \$q_111 \vdash q_1\$11 \vdash 1q_211 \vdash 11q_21 \vdash 111q_2\square \vdash 11q_111 \vdash 1q_1111 \vdash q_11111 \vdash q_1\square1111 \vdash q_31111$

- Hoca bu çalıştırmayı öğrencilere bıraktı. Makine 1'den 5'e kadar $x$ değerlerinde denendi; hepsinde $2x$ tane 1 üretiyor.

### Quiz ve dönem duyuruları

- Quiz aynı gün 11:25'te yapıldı. 5 soru, 25 dakika.
- Quiz başlangıçta öğrencilere görünmedi; hoca yayınlamayı unuttuğunu fark edip yayınladı.
- Bütün sınavlarda işlenen bütün konular dahildir.
- Gelecek hafta dönemin son dersidir.

### Ders sonrası notlar

- Hoca durma kurallarını özetlerken iki kez "kabul durumunda durursa" dedi. İkincisi sürçmedir: makine kabul **olmayan** bir durumda durursa girişi reddeder.
- Hoca sonsuz döngü için "makine reddeder" dedi. Bu derste kullanılan tanıma göre doğru sonuç şudur: girişi kabul etmez. Sipser'ın dilinde sonsuz döngüye giren makine ne kabul ne ret eder; yalnızca durmaz. Bu ayrım, tanınabilir (recognizable) ve karar verilebilir (decidable) diller arasındaki farkın temelidir.
- Hoca dili "$n$ birden büyük" diye okudu ama tahtada $n \ge 1$ yazıyor. Verdiği örnekler (`ab`) de $n \ge 1$ ile uyumludur.
- `aabb` hesaplamasında hoca 00:30-00:32 arasında $q_2$'den sonra yönü karıştırıp "$q_0$" yazdı, sonra kendisi düzeltti. Doğru sıra yukarıdaki tablodadır: $xq_2ayb \vdash q_2xayb \vdash xq_0ayb$.
- Bu dersteki 7'li tanım ($\square$ ve $F$ içeren), iki yönde sonsuz şerit ve $x + y$, $2x$ örnekleri Linz'in *An Introduction to Formal Languages and Automata* kitabındaki gösterimle aynıdır. Sipser'da 7'li tanım farklıdır: $(Q, \Sigma, \Gamma, \delta, q_0, q_{accept}, q_{reject})$; şerit tek yönde sonsuzdur. Sınavda hocanın gösterimini kullanın.
- Altyazıdaki "drink machines" ve "string machine" ifadeleri "Turing machines" demektir. "Sankar Kauru" anlamsız bir altyazı hatasıdır.
- `aabb`, $x + y$ ve $2x$ makineleri ile ev çalışması çözümü Python ile simüle edilerek doğrulandı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Ders İngilizce anlatılmıştır; altyazı da büyük ölçüde İngilizcedir.
