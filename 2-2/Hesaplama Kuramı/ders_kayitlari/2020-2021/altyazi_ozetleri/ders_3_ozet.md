# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin tarihi 23 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl anlatım yaklaşık 00:08:50'de başlar. Kaydın başı bekleme kısmıdır.
  - Hoca tabletteki not uygulamasına el yazısıyla yazıyor. Ders iki arayla üç bölüme ayrılıyor.
- Sonlu otomatlara giriş (finite automata)
  - Otomat, giriş şeridindeki (input tape) dizgiyi soldan sağa, her adımda bir sembol okuyarak işler.
  - Bütün semboller okununca makine kabul (accept) ya da ret (reject) çıktısı verir.
- Durum diyagramı
  - Durumlar (state) çemberle, geçişler (transition) okla gösterilir.
  - Başlangıç durumunu, kaynağı olmayan bir ok gösterir.
  - Çift çemberli durum kabul durumudur (accepting state). Tek çemberli durum ret durumudur.
- Örnek bir makinenin `abbaaabb` dizgisi üzerinde adım adım çalıştırılması
- Sonlu otomatın biçimsel tanımı: 5'li $(Q, \Sigma, \delta, q_0, F)$
- Geçiş fonksiyonu $\delta: Q \times \Sigma \to Q$ ve geçiş tablosu
- Tasarım örneği: tek sayıda 1 içeren ikili dizgiler
- Geçiş fonksiyonunun geçişler kümesi olarak yazılması
- Deterministik sonlu otomat (DFA): her durumda alfabedeki her sembol için tam bir geçiş
- Kabul ve ret koşulları
- Verilen makinenin dilini bulma örnekleri
- Genişletilmiş geçiş fonksiyonu $\delta^*$
- Sembol sayısı durum sayısından büyükse makinede döngü olmalıdır
- DFA'nın kabul ettiği dil $L(M)$ ve tümleyeni
- Özel diller: boş küme, bütün dizgiler, yalnızca boş dizgi
- Tasarım örnekleri: `ab` önekli dizgiler, `001` içeren ve içermeyen ikili dizgiler
- Düzenli diller (regular languages) ve düzenli olmayan diller
- Quiz duyurusu ve çalışma kâğıdı (study sheet)

## Hocanın Özellikle Vurguladığı Kısımlar

- Makine, kabul durumuna erken ulaşsa bile durmaz.
  - Bütün giriş okunana kadar devam eder. Karar, son okunan sembolden sonraki duruma göre verilir.
- Bir makinenin 5'li tanımı sorulduğunda bunu yazabilmelisiniz.
  - Diyagram insan için kolaydır. Bilgisayara verilecek gösterim biçimsel tanımdır.
- Geçiş fonksiyonu makinenin programıdır.
  - Geçişleri değiştirmek, makinenin programını değiştirmektir.
- DFA'da hiçbir geçiş atlanamaz.
  - Her durum için her sembolün ne yaptığı yazılmalıdır. Gerekirse tuzak durum (trap / dead state) eklenir.
- Tasarımda yöntem: önce dilden örnek dizgiler yazın, deseni anlayın. Sonra her durum için her sembolü tek tek ele alın.
- Tasarladığınız makineyi test edin.
  - Dile ait olan ve olmayan dizgilerle elle deneyin. Örnek: `00011001` reddedilmeli.
- Sonsuz diller için kısa desen gösterimi kullanın. Örnek: $\{a^n b \mid n \ge 0\}$.
- Durum sayısından uzun bir dizgiyi kabul eden makinede döngü vardır.
  - Hoca bunun ilerideki derslerde çok önemli olduğunu söyledi.
- Haftaya quiz var.
  - Dersin son 15 dakikasında, test biçiminde, Online YıldızEdu üzerinden.
  - Paylaşılan çalışma kâğıdının ilk 12 sorusunu çözün.

## Kısa Tekrar Notları

- Sonlu otomat: giriş şeridi + okuma kafası + durumlar + geçişler.
- Çıktı yalnızca iki türlüdür: kabul veya ret.
- 5'li tanım:
  - $Q$: durumlar kümesi
  - $\Sigma$: alfabe
  - $\delta: Q \times \Sigma \to Q$: geçiş fonksiyonu
  - $q_0 \in Q$: başlangıç durumu (küme değil, tek durum)
  - $F \subseteq Q$: kabul durumları kümesi
- DFA: her $(q, \sigma)$ çifti için tam bir geçiş vardır.
- Kabul: bütün giriş okunur ve son durum $F$'tedir.
- Ret: bütün giriş okunur ve son durum $F$'te değildir.
- Tuzak durum: ret durumudur ve her sembolde kendine döner. Bu duruma giren dizgi bir daha çıkamaz.
- Başlangıç durumu kabul durumuysa makine boş dizgiyi ($\varepsilon$) kabul eder.
- $\delta^*(q, w)$: $q$ durumundan $w$ dizgisinin tamamı okununca varılan durum.
- $L(M) = \{ w \in \Sigma^* \mid \delta^*(q_0, w) \in F \}$
- $\overline{L(M)} = \{ w \in \Sigma^* \mid \delta^*(q_0, w) \notin F \}$
- Her otomat tek bir dil kabul eder. Bir dili birden çok otomat kabul edebilir.
- Düzenli dil: bir DFA'nın kabul ettiği dil. Her sonlu dil düzenlidir.
- $\{a^n b^n \mid n \ge 0\}$ düzenli değildir. Bu dil için DFA tasarlanamaz.

## Detaylı Açıklamalar

### Sonlu otomat nasıl çalışır?

Sonlu otomat, giriş şeridindeki dizgiyi okuyan mantıksal bir makinedir. Okuma kafası (read-write head) şeridin başından başlar. Her adımda bir sembol okur ve sağa kayar. Makine o anki durumuna ve okunan sembole bakarak yeni duruma geçer. Bütün semboller okununca son duruma bakılır.

Bir öğrenci, makinenin bir adımda birden çok sembol okuyup okuyamayacağını sordu. Hoca, makinenin her adımda yalnızca bir sembol okuduğunu söyledi. İki yol önerdi:

- `ab` okumayı iki ayrı geçiş olarak düşünmek.
- Alfabeye `ab` anlamına gelen yeni bir sembol eklemek (ör. `z`).

### İlk örnek makine

Alfabe $\Sigma = \{a, b\}$. Durumlar $q_0, \dots, q_5$. Başlangıç durumu $q_0$, tek kabul durumu $q_4$. Diyagram tahta karesinden alındı.

| $\delta$ | $a$ | $b$ |
| :---: | :---: | :---: |
| $q_0$ | $q_1$ | $q_5$ |
| $q_1$ | $q_5$ | $q_2$ |
| $q_2$ | $q_5$ | $q_3$ |
| $q_3$ | $q_4$ | $q_5$ |
| $q_4$ | $q_5$ | $q_5$ |
| $q_5$ | $q_5$ | $q_5$ |

- Hoca $q_5$'in kendine dönen geçişini önce çizmeyi unuttu, sonra ekledi.
- `abbaaabb` dizgisi: $q_0 \to q_1 \to q_2 \to q_3 \to q_4$. Bu noktada kabul durumundayız ama okunmamış semboller var. Sonraki `a` makineyi $q_5$'e götürür. Kalan semboller $q_5$'te döner. Son durum $q_5$, dizgi reddedilir.
- Bu makinenin dili yalnızca $\{abba\}$'dır.

### Biçimsel tanım ve geçiş tablosu

Biçimsel tanımda $q_0$ bir küme değil, tek bir durumdur. Hoca, 5'li içindeki "$q_0$" adı ile durum adı olan "$q_0$"ın farklı şeyler olduğunu vurguladı. Durumlara istediğiniz adı verebilirsiniz.

Geçiş fonksiyonu iki biçimde yazılabilir:

- Tablo olarak (yukarıdaki gibi).
- Geçişler kümesi olarak. Örnek: $\delta = \{ (q_{even}, 0, q_{even}), (q_{even}, 1, q_{odd}), (q_{odd}, 0, q_{odd}), (q_{odd}, 1, q_{even}) \}$.

### Tasarım: tek sayıda 1 içeren ikili dizgiler

$A = \{ w \mid w$ tek sayıda 1 içeren ikili dizgi $\}$. Fikir, 1'leri saymak değil, sayının tek mi çift mi olduğunu durumla tutmaktır.

- $q_{even}$: şimdiye kadar çift sayıda 1 okundu. Başlangıç durumudur.
- $q_{odd}$: tek sayıda 1 okundu. Kabul durumudur.
- 0 durumu değiştirmez. 1 iki durum arasında geçiş yaptırır.
- $M = (\{q_{even}, q_{odd}\}, \{0,1\}, \delta, q_{even}, \{q_{odd}\})$.

Bir öğrenci `01001` dizgisini denedi. Dizgide iki tane 1 var, makine $q_{even}$'da biter ve reddeder. Öğrenci "bu bir tek sayı" diye itiraz etti. Hoca, dilin ikili sayının tek olmasıyla değil, 1'lerin sayısının tek olmasıyla ilgili olduğunu açıkladı.

### Verilen makinenin dilini bulma

1. **Örnek:** Başlangıç durumu kabul durumu, `ab` ile bir kabul durumuna, `abba` ile başka bir kabul durumuna gidiliyor. Diğer bütün yollar tuzak duruma gidiyor. $L = \{\varepsilon, ab, abba\}$.
2. **Örnek:** $q_0$'da `a` ile döngü, `b` ile kabul durumu $q_1$'e geçiş. $q_1$'den sonraki her sembol tuzak duruma götürür. $L = \{a^n b \mid n \ge 0\}$.
3. **Örnek:** Alfabe yalnızca $\{1\}$. İki durum arasında 1 ile gidip gelen, başlangıcı kabul durumu olan makine. $L = \{1^n \mid n$ çift$\}$. Sıfır çift sayılır, bu yüzden $\varepsilon$ da dildedir.

### Döngü gereği

Altı durumlu bir makine 12 sembollük bir dizgiyi kabul ediyorsa, okuma sırasında en az bir durum tekrar edilmiş olmalıdır. Yani makinede bir döngü vardır. Bu, ileride düzenli dillerin pompalama özelliğinin (pumping lemma) temelidir.

### Özel diller

- **Hiç kabul durumu yok:** $L(M) = \emptyset$.
- **Bütün durumlar kabul durumu:** $L(M) = \Sigma^*$.
- **Yalnızca boş dizgi:** Başlangıç durumu kabul durumu olur. Her sembol tuzak duruma gider. $L(M) = \{\varepsilon\}$.

### `ab` önekli dizgiler

$q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$, $q_2$ kabul durumu ve her sembolde kendine döner. $q_0$'da `b` ile ve $q_1$'de `a` ile tek bir tuzak duruma gidilir.

### `001` içeren ve içermeyen ikili dizgiler

Tahta karesinden alınan DFA (`001` içeren):

| $\delta$ | 0 | 1 | Anlamı |
| :---: | :---: | :---: | :--- |
| $q_0$ (başlangıç) | $q_1$ | $q_0$ | Son okunan kısımda 0 yok |
| $q_1$ | $q_2$ | $q_0$ | Son okunan `0` |
| $q_2$ | $q_2$ | $q_3$ | Son okunan `00` |
| $q_3$ (kabul) | $q_3$ | $q_3$ | `001` görüldü |

- $q_2$'de gelen her yeni 0 durumu değiştirmez, çünkü son iki sembol yine `00` olur.
- `001` **içermeyen** dizgiler için aynı makinede kabul durumları ters çevrilir: $F = \{q_0, q_1, q_2\}$, $q_3$ tuzak ret durumu olur.

### Ev çalışması: $a w a$, $w \in \{a,b\}^*$

`a` ile başlayıp `a` ile biten, en az iki sembollü dizgiler. Hoca çözümü verdi. Önce kendiniz deneyin.

| $\delta$ | $a$ | $b$ |
| :---: | :---: | :---: |
| $q_0$ (başlangıç) | $q_1$ | $q_3$ |
| $q_1$ | $q_2$ | $q_1$ |
| $q_2$ (kabul) | $q_2$ | $q_1$ |
| $q_3$ (tuzak) | $q_3$ | $q_3$ |

### Ders sonrası notlar

- Hoca geçiş tablosunu okurken bir yerde "$q_5$ goes to $q_4$" dedi. Doğrusu: $q_3$, `a` okuyunca $q_4$'e gider.
- $\{a^n b\}$ dili için hoca bir yerde "$n > 0$" dedi. Makine `b` dizgisini de kabul ettiği için doğru koşul $n \ge 0$'dır. Tahtada da $n \ge 0$ yazıyor.
- Genişletilmiş geçiş örneğinde hoca önce `CB` yazdı. Bir öğrencinin uyarısıyla `BC` olarak düzeltti.
- Döngü örneğinde hoca $q_3$'ten `b` ile iki ayrı duruma geçiş çizmişti. Öğrenci uyardı, hoca bunun DFA'da yanlış olduğunu kabul edip diyagramı düzeltti.
- `001` içermeyen dizgiler için hoca önce $q_1$'e 1 ile döngü koydu, sonra 1 gelince başa ($q_0$) dönülmesi gerektiğini söyledi. Doğrusu ikinci hâlidir. Örnek: `0101` bu dile aittir.
- Hoca DFA tanımında "her durumda her sembol için bir geçiş" dedi. Tam ifade: her durumda her sembol için **tam olarak bir** geçiş.
- Yukarıdaki tablolar (tek sayıda 1, `001` içeren/içermeyen, `ab` önek, $awa$) 8 sembole kadar bütün dizgilerde Python simülasyonuyla denendi. Hepsi beklenen dili kabul ediyor.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Ders İngilizce anlatılmıştır; altyazı da büyük ölçüde İngilizcedir.
