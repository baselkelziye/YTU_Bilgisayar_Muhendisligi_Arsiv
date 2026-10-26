# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 30 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl anlatım yaklaşık 00:04:30'da başlar.
  - Dersin sonunda 11:35-11:50 arasında quiz yapıldı.
- Deterministik olmayan sonlu otomat (NFA, nondeterministic finite automaton)
  - DFA'dan üç farkı: aynı sembolle birden çok geçiş, boş geçiş (null / $\varepsilon$ transition), bazı geçişlerin hiç yazılmaması.
- NFA'nın biçimsel tanımı ve geçiş fonksiyonu $\delta: Q \times \Sigma \to 2^Q$
- NFA nasıl çalışır: paralel hesaplama dalları (computation)
- NFA'nın kabul ve ret koşulları
- Hesaplama ağacı (computation tree)
- NFA dil bulma örnekleri: $\{aa\}$, $(ab)^+$, $(10)^*$, $(ab)^*(aa \cup \varepsilon)$
- NFA'lar daha kolay tasarlanır ama DFA'lardan güçlü değildir
- NFA'da genişletilmiş geçiş fonksiyonu $\delta^*$ ve NFA'nın dili
- Makinelerin denkliği (equivalence)
- Teorem: NFA'ların kabul ettiği diller tam olarak düzenli dillerdir
- NFA'dan DFA'ya dönüşüme giriş (alt küme yapısı). Örnek yarım kaldı, sonraki derse bırakıldı.
- Araya MÜDEK değerlendirme görüşmesi duyurusu girdi.

## Hocanın Özellikle Vurguladığı Kısımlar

- NFA'da bir dalın kabul etmesi yeterlidir.
  - En az bir hesaplama dalı bütün girişi okuyup kabul durumunda biterse NFA dizgiyi kabul eder.
- $\varepsilon$ hiçbir zaman alfabede değildir.
  - Bu ders boyunca $\varepsilon$ (bazı kaynaklarda $\lambda$) "girdi okumadan geçiş" anlamına gelen özel bir semboldür.
- NFA'da bir sembol için geçiş yazılmamışsa o dal, o sembol gelince reddeder.
- Karmaşık NFA'larda hesaplama ağacı çizin.
  - Hoca bu yöntemi çok faydalı bulduğunu söyledi.
- NFA tasarlamak daha kolaydır ama NFA daha güçlü değildir.
  - NFA ve DFA aynı dil sınıfını, yani düzenli dilleri, kabul eder.
- Quizde geri dönüş yok.
  - Sorular karışık geliyor ve görülen soruya geri dönülemiyor. Cevabınızdan emin olmadan sonraki soruya geçmeyin.
- Dili bulmak için önce örnek dizgiler yazın. Sonra deseni küme gösterimiyle ifade edin. Bunun için çok pratik yapın.

## Kısa Tekrar Notları

- NFA 5'lisi: $M = (Q, \Sigma, \delta, q_0, F)$.
- Fark yalnızca geçiş fonksiyonundadır: $\delta: Q \times (\Sigma \cup \{\varepsilon\}) \to 2^Q$.
  - $2^Q$, $Q$'nun kuvvet kümesidir (power set). Tek hedef olsa bile sonuç küme olarak yazılır: $\{q_1\}$.
  - Geçiş yoksa sonuç $\emptyset$'dir.
- $|Q| = 3$ ise $2^Q$'da $2^3 = 8$ küme vardır.
- $\varepsilon$ geçişi: makine sembol okumadan yeni duruma da geçer. Makine "kendini çoğaltır" gibi düşünülebilir.
- NFA kabul eder: en az bir dal bütün girişi okur ve kabul durumunda biter.
- NFA reddeder: hiçbir dal kabul etmez. Bir dal iki şekilde başarısız olur:
  - Bütün giriş okunur ama dal kabul durumunda değildir.
  - Dal bir sembolü okuyamaz (o sembol için geçiş yoktur).
- $\delta^*(q_0, w)$ bir durum kümesidir. $w \in L(M)$ ancak $\delta^*(q_0, w) \cap F \neq \emptyset$ ise.
- $M_1$ ile $M_2$ denktir $\iff L(M_1) = L(M_2)$.
- Her DFA aynı zamanda bir NFA'dır.
- Alt küme yapısı: DFA'nın her durumu, NFA durumlarından oluşan bir kümedir.
- $X^+ = X X^*$: en az bir tekrar. $X^*$: sıfır ya da daha fazla tekrar.

## Detaylı Açıklamalar

### NFA'nın DFA'dan farkları

1. **Aynı sembolle birden çok geçiş:** $q_1$'de `a` okununca hem $q_2$'ye hem $q_3$'e gidilebilir.
2. **Boş geçiş:** $q_1 \xrightarrow{\varepsilon} q_2$ ise makine $q_1$'e geldiği anda, girdi okumadan $q_2$'de de olur. İki dal paralel çalışmaya devam eder.
3. **Eksik geçiş:** $\Sigma = \{a, b\}$ iken bir durumdan yalnızca `a` geçişi yazılabilir. O dala `b` gelirse dal reddeder.

### Biçimsel tanım örneği

Tahta karesinden alınan makine: $q_0$ başlangıç ve tek kabul durumu. Geçişler: $q_0 \xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$, $q_1 \xrightarrow{0,1} q_2$, $q_0 \xrightarrow{\varepsilon} q_2$. $\Sigma = \{0, 1\}$.

| $\delta$ | 0 | 1 | $\varepsilon$ |
| :---: | :---: | :---: | :---: |
| $q_0$ | $\emptyset$ | $\{q_1\}$ | $\{q_2\}$ |
| $q_1$ | $\{q_0, q_2\}$ | $\{q_2\}$ | $\emptyset$ |
| $q_2$ | $\emptyset$ | $\emptyset$ | $\emptyset$ |

Hoca tabloya önce $\varepsilon$ sütununu koymamıştı. Bir öğrenci $\varepsilon$ geçişinin tabloda nasıl gösterileceğini sordu. Hoca, tablo verilince diyagramın çizilebilmesi için bu sütunun gerektiğini kabul edip ekledi.

### Hesaplama dalları: $\{aa\}$ örneği

Makine: $q_0 \xrightarrow{a} q_1 \xrightarrow{a} q_2$ (kabul) ve $q_0 \xrightarrow{a} q_3$.

- `aa` girişi: İlk `a`'dan sonra iki dal var: $q_1$ ve $q_3$. İkinci `a`'da $q_1$ dalı $q_2$'ye geçer ve kabul eder. $q_3$ dalı `a` okuyamaz ve reddeder. En az bir dal kabul ettiği için makine `aa`'yı kabul eder.
- `a` girişi: Dallar $q_1$ ve $q_3$'te biter. İkisi de kabul durumu değil. Makine reddeder.

### Dil bulma örnekleri

1. $q_0 \xrightarrow{a} q_1 \xrightarrow{\varepsilon} q_2 \xrightarrow{a} q_3$ ($q_3$ kabul): $L = \{aa\}$. `aaa` reddedilir, çünkü $q_3$ üçüncü `a`'yı okuyamaz.
2. $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$ (kabul), $q_2 \xrightarrow{\varepsilon} q_3 \xrightarrow{\varepsilon} q_0$: $L = (ab)^+ = \{ab, abab, \dots\}$. Başlangıç kabul durumu olmadığı için $\varepsilon$ dilde yoktur; bu yüzden $*$ değil $+$ kullanılır.
3. $q_0$ (başlangıç, kabul) $\xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$, $q_1 \xrightarrow{0} q_2$, $q_0 \xrightarrow{\varepsilon} q_2$: $L = (10)^*$. $q_2$'den çıkan geçiş yok ve kabul durumu değil. Bu durum gereksizdir (redundant); silinse dil değişmez.
4. Altı durumlu örnek (karelerden): $q_0$ başlangıç ve kabul. $q_0 \xrightarrow{a} q_1$; $q_1 \xrightarrow{a} q_4$; $q_1 \xrightarrow{a} q_5$ (kabul); $q_1 \xrightarrow{b} q_2 \xrightarrow{\varepsilon} q_3 \xrightarrow{\varepsilon} q_0$.
   - `ab` her okununca $\varepsilon$ geçişleriyle $q_0$'a dönülür. `aa` ile $q_5$'e gidilir.
   - $L = (ab)^* \{aa\} \cup (ab)^*$, yani $L = (ab)^*(aa \cup \varepsilon)$.
   - Bir öğrenci yalnızca `aa`'nın da eklenmesi gerekip gerekmediğini sordu. Hoca, $(ab)^*$'ın boş dizgiyi de içerdiğini, bu yüzden `aa`'nın zaten kapsandığını söyledi.

### NFA'lar neden kolaydır?

$L = \{a\}$ dili için NFA tek geçişle yazılır: $q_0 \xrightarrow{a} q_1$ (kabul). DFA'da ise $q_0$'da `b`, $q_1$'de `a` ve `b` geçişleri de yazılmalıdır. Bunun için ayrıca bir tuzak durum gerekir. NFA kuralları daha esnektir. Ama kabul edilebilen diller kümesi aynıdır.

### Teorem: NFA'lar düzenli dilleri kabul eder

$\mathcal{L}_{NFA} = \mathcal{L}_{DFA}$ eşitliği iki alt küme ilişkisiyle ispatlanır:

1. $\mathcal{L}_{DFA} \subseteq \mathcal{L}_{NFA}$: Her DFA aynı zamanda bir NFA'dır. Bu kısım açıktır.
2. $\mathcal{L}_{NFA} \subseteq \mathcal{L}_{DFA}$: Her NFA, aynı dili kabul eden bir DFA'ya dönüştürülebilir. Hoca bu kısmın ispatını atladı, kitaptan okunmasını istedi.

### NFA'dan DFA'ya dönüşüm örneği (yarım kaldı)

NFA: $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_1$, $q_1 \xrightarrow{\varepsilon} q_2$, $q_2 \xrightarrow{b} q_0$. Kabul durumu bu derste henüz işaretlenmedi.

DFA'nın durumlarına NFA durum kümelerinin adı verilir. Başlangıç durumu $\{q_0\}$'dır.

| DFA durumu | $a$ | $b$ |
| :---: | :---: | :---: |
| $\{q_0\}$ | $\{q_1, q_2\}$ | $\emptyset$ |
| $\{q_1, q_2\}$ | $\{q_1, q_2\}$ | $\{q_0\}$ |
| $\emptyset$ (tuzak) | $\emptyset$ | $\emptyset$ |

- Derste yalnızca ilk satır yapıldı. $\{q_1, q_2\}$ satırı bu özete eklenmiştir.
- $q_1$'e gelindiğinde $\varepsilon$ geçişiyle $q_2$'ye de gidildiği için hedef küme $\{q_1, q_2\}$'dir.
- DFA'nın kabul durumları, NFA kabul durumlarından en az birini içeren kümelerdir.
- Hoca örneğe gelecek hafta devam edeceğini söyledi.

### Duyurular

- Quiz: 30 Mart 2021, 11:35-11:50, Online YıldızEdu, test. Geriye dönüş yok.
- Ders arasında bölümden bir öğretim üyesi MÜDEK akreditasyon görüşmelerini duyurdu. İkinci sınıf öğrencilerinin 12:10-12:30 arasındaki değerlendirici görüşmesine STD Yıldız e-postalarıyla davet edildiğini söyledi ve katılım istedi.

### Ders sonrası notlar

- Hoca bir yerde "NFA'ların kabul ettiği diller, NFA'ların kabul ettiği dillerle aynıdır" dedi. Kastedilen: NFA'ların kabul ettiği diller DFA'ların kabul ettiği dillerle aynıdır.
- Hoca bir yerde "every DFA can be converted to an equivalent DFA" dedi, sonra düzeltti. Doğrusu: her NFA'nın denk bir DFA'sı vardır.
- $\{aa\}$ örneğinde ilk adımdaki dallar önce yanlışlıkla "$q_1$ ve $q_2$" diye söylendi. Doğrusu $q_1$ ve $q_3$'tür.
- NFA'nın dilinin biçimsel tanımında hoca önce $w_0, \dots, w_n$ ve $w_m$ indekslerini karıştırdı. Öğrenci uyarınca $0 \le m \le n$ koşulunu ekledi. Daha temiz tanım: $L(M) = \{ w \in \Sigma^* \mid \delta^*(q_0, w) \cap F \neq \emptyset \}$.
- Alt küme yapısında başlangıç durumu, $q_0$'dan $\varepsilon$ geçişleriyle ulaşılabilen bütün durumların kümesidir ($\varepsilon$-kapanışı, epsilon closure). Bu örnekte $q_0$'dan $\varepsilon$ geçişi olmadığı için küme $\{q_0\}$'dır.
- $(ab)^*(aa \cup \varepsilon)$ ifadesinin hocanın verdiği $(ab)^*\{aa\} \cup (ab)^*$ ile aynı dili verdiği, 8 sembole kadar bütün dizgilerde Python ile denendi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Ders İngilizce anlatılmıştır; altyazı da büyük ölçüde İngilizcedir.
