# Ders 5 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı: düzenli dillerin kapanış özellikleri
  - Dil bir kümedir. Düzenli diller birleşim, birleştirme (concatenation), yıldız (Kleene star), ters çevirme, tümleyen ve kesişim işlemleri altında kapalıdır: bu işlemlere düzenli diller verilirse sonuç yine düzenli bir dildir.
  - Bu özellikler ispatlanırken dilleri kabul eden DFA/NFA'ların birleşimi, birleştirmesi vb. de kurulmuştu.
- Düzenli ifadeler (regular expressions)
  - Düzenli ifadeler düzenli dilleri tarif eder. Programlamada belirli biçimdeki metinleri bulmak, eşlemek ve metinden parça çıkarmak için kullanılır.
  - $+$ "veya", $\cdot$ birleştirme, $^*$ Kleene yıldızı (sıfır ya da daha fazla tekrar), parantez gruplamadır.
  - Örnek: $(a + b \cdot c)^*$ ifadesi $\{a, bc\}^* = \{\varepsilon, a, bc, aa, abc, bca, \dots\}$ dilini tarif eder (ekrandan, 00:10:00).
- Düzenli ifadelerin özyinelemeli tanımı
  - İlkel (primitive) düzenli ifadeler: $\emptyset$, $\varepsilon$ ve tek bir sembol ($a$, $b$, ...).
  - $r_1$ ve $r_2$ düzenli ifade ise $r_1 + r_2$, $r_1 \cdot r_2$, $r_1^*$ ve $(r_1)$ de düzenli ifadedir.
  - Örnek: $(a+b\cdot c)^* \cdot (c + \emptyset)$ düzenli ifadedir; $(a + b +)$ değildir, çünkü $+$ işleminin ikinci işleneni eksiktir.
  <!-- BELİRSİZ: Geçerli/geçersiz ifade örnekleri altyazıdan kuruldu; o slaytın karesi yok. -->
- Düzenli ifadenin dili $L(r)$
  - $L(\emptyset) = \emptyset$, $L(\varepsilon) = \{\varepsilon\}$, $L(a) = \{a\}$ (ekrandan, 00:20:00).
  - $L(r_1 + r_2) = L(r_1) \cup L(r_2)$, $L(r_1 \cdot r_2) = L(r_1)L(r_2)$, $L(r_1^*) = (L(r_1))^*$, $L((r_1)) = L(r_1)$ (ekrandan, 01:05:00).
  - Örnek: $L((a+b)\cdot a^*) = \{a,b\}\{\varepsilon, a, aa, \dots\} = \{a, aa, aaa, \dots, b, ba, baa, \dots\}$ (ekrandan, 00:25:00).
- Düzenli ifade örnekleri
  - $(a+b)^*(a+bb)$: $a$ ile ya da $bb$ ile biten bütün dizgiler (ekrandan, 00:35:00).
  - $(aa)^*(bb)^*b$: $L = \{a^{2n} b^{2m} b : n, m \ge 0\}$ (ekrandan, 00:30:00).
  - $(0+1)^*00(0+1)^*$: $00$ alt dizgisini içeren bütün dizgiler.
  - $(1+01)^*(0+\varepsilon)$: $00$ alt dizgisini içermeyen bütün dizgiler (ekrandan, 00:40:00).
- Denk düzenli ifadeler
  - $L(r_1) = L(r_2)$ ise $r_1$ ve $r_2$ denktir.
  - Örnek: $r_1 = (1+01)^*(0+\varepsilon)$ ve $r_2 = (1^*011^*)^*(0+\varepsilon) + 1^*(0+\varepsilon)$ ikisi de "$00$ içermeyen dizgiler" dilini tarif eder (ekrandan, 00:55:00).
- Teorem: düzenli ifadelerin dilleri = düzenli diller
  - Küme eşitliği iki yönde ispatlanır: $\subseteq$ ve $\supseteq$.
  - 1. kısım: her düzenli ifadenin dili düzenlidir (ifadenin boyutu üzerinde tümevarım).
  - 2. kısım: her düzenli dil için bir düzenli ifade vardır (NFA'yı genelleştirilmiş geçiş grafiğine çevirip durum eleme ile, yapıcı ispat).
- Pompalama önsavına (pumping lemma) giriş
  - Bir dilin düzenli olmadığını ispatlamak için kullanılır. Örnek düzensiz diller: $\{a^n b^n : n \ge 0\}$, $\{w w^R\}$.
  - Güvercin yuvası ilkesine dayanır: uzunluğu durum sayısından büyük ya da eşit bir dizginin DFA'daki yürüyüşünde bir durum tekrar eder.
  - Önsav: sonsuz düzenli dil $L$ için bir kritik uzunluk $p$ vardır; $|w| \ge p$ olan her $w \in L$, $|xy| \le p$, $|y| \ge 1$ olacak biçimde $w = xyz$ diye yazılabilir ve her $i \ge 0$ için $xy^iz \in L$ olur (ekrandan, 02:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kleene yıldızı boş dizgiyi de eşler
  - Bir ifadenin dilinde $\varepsilon$ bulunmasını sağlayan yıldızdır. Yıldız yoksa tek bir sembol yalnız kendisini eşler; bu yüzden $L(a) = \{a\}$ içinde $\varepsilon$ yoktur.
- $(1+01)^*(0+\varepsilon)$ içindeki $\varepsilon$'un görevi
  - $\varepsilon$ olmasaydı ifade hep $0$ ile bitmek zorunda kalırdı; $\varepsilon$ sayesinde $1$ ile biten dizgiler (örneğin $1111$) de eşlenir.
- Her dil üstel gösterimle ($a^n b^m \dots$) kolayca yazılamaz
  - $(a+b)^*$ kısmı $a$ ve $b$'leri istenen sırada ve sayıda karıştırdığı için $(a+b)^*(a+bb)$ dilini $a^n b^m$ biçiminde yazmak çok zordur.
- Düzenli dilin üç gösterimi
  - Bir dil DFA, NFA ya da düzenli ifade ile tarif edilebiliyorsa düzenlidir. "Bize düzenli bir dil verildi" demek, dilin bu standart gösterimlerden biriyle verilmesi demektir.
- İki durumlu son grafikten düzenli ifade: $r = r_1^* r_2 (r_4 + r_3 r_1^* r_2)^*$
  - Hoca formülü ezberlemek yerine mantığını anlamayı önerdi: önce başlangıçtaki $r_1$ döngüsü, sonra $r_2$ ile kabul durumuna geçiş, sonra kabul durumundaki iki tür döngünün ($r_4$ ve $r_3 r_1^* r_2$) birleşiminin yıldızı.
  - $r_4$'e ayrıca yıldız gerekmez, çünkü en dıştaki yıldız onu istenen sayıda tekrarlatır.
- Pompalama önsavının ifadesi
  - Hoca önsavın tam ifadesinin bilinmesi gerektiğini söyledi.

## Kısa Tekrar Notları

- İlkel ifadeler: $\emptyset$, $\varepsilon$, $a$. İşlemler: $+$, $\cdot$, $^*$, $(\,)$.
- $L(r_1+r_2)=L(r_1)\cup L(r_2)$; $L(r_1 r_2)=L(r_1)L(r_2)$; $L(r^*)=L(r)^*$; $L((r))=L(r)$.
- Gruplama yeni bir dil üretmez.
- Denk ifadeler: dilleri aynı olan ifadeler.
- Düzenli ifade dilleri kümesi = düzenli diller kümesi.
- 1. kısım (tümevarım): taban ilkel ifadelerin NFA'ları; adım kapanış özellikleri (birleşim, birleştirme, yıldız).
- 2. kısım: NFA → tek kabul durumu → genelleştirilmiş geçiş grafiği (etiketler düzenli ifade, "$a, b$" → $a+b$) → ara durumları ele → iki durum kalınca formülü uygula.
- Durum eleme: elenen durumdan geçen her yolu (döngüler dahil) yeni bir düzenli ifade etiketi olarak ekle.
- Düzenli olmadığını göstermek için sonsuz sayıdaki NFA'ları tek tek denemek mümkün değildir; pompalama önsavı kullanılır.
- Sonlu her dil düzenlidir; dolayısıyla düzensiz bir dil sonsuzdur.
- Pompalama önsavıyla ispat: olmayana ergi. $L$ düzenli varsayılır, önsavla çelişki bulunur, $L$ düzenli değildir denir.

## Detaylı Açıklamalar

- **Düzenli ifadenin dilini bulma.** İfade, yukarıdaki dört kuralla dıştan içe parçalanır. $(a+b)\cdot a^*$ için önce birleştirme ayrılır: $L((a+b))\,L(a^*)$. Gruplama dili değiştirmediği için $L(a+b)L(a^*)$, sonra $(L(a)\cup L(b))(L(a))^*$, sonra $(\{a\}\cup\{b\})(\{a\})^*$, yani $\{a,b\}\{\varepsilon,a,aa,\dots\}$. Bu iki kümenin birleştirmesi, tek bir $a$ ya da tek bir $b$ ile başlayıp ardından istenen sayıda $a$ gelen dizgilerdir (ekrandan, 00:25:00). Hoca, düzenli ifadenin dilin elemanlarının nasıl göründüğünü bir resim gibi gösterdiğini söyledi.
- **$00$ içermeyen dizgiler.** $(1+01)^*$ kısmından gelen her $0$'ın hemen ardından bir $1$ gelir; böylece iki $0$ yan yana gelemez. Sonda en fazla bir tane $0$ eklenebilir ($0+\varepsilon$). İki ifadenin ($r_1$ ve $r_2$) aynı dili tarif ettiği ve $r_1$'in daha kısa olduğu gösterildi.
- **1. kısmın ispatı (tümevarım).** Taban: üç ilkel ifade için NFA'lar kolayca yazılır (ekrandan, 01:00:00):
  - $M_1$: tek başlangıç durumu, kabul durumu yok; $L(M_1) = \emptyset = L(\emptyset)$.
  - $M_2$: başlangıç durumu aynı zamanda kabul durumu; $L(M_2) = \{\varepsilon\} = L(\varepsilon)$.
  - $M_3$: başlangıç durumundan $a$ ile kabul durumuna tek geçiş; $L(M_3) = \{a\} = L(a)$.
  - Tümevarım hipotezi: $L(r_1)$ ve $L(r_2)$ düzenlidir. Adım: tanım gereği $L(r_1+r_2)$ birleşim, $L(r_1 r_2)$ birleştirme, $L(r_1^*)$ yıldızdır; düzenli diller bu işlemler altında kapalı olduğundan hepsi düzenlidir. $L((r_1)) = L(r_1)$ ise doğrudan hipotezden düzenlidir. NFA'lar da önceki derste görülen birleşim/birleştirme/yıldız kurulumlarıyla birleştirilebilir.
- **2. kısmın ispatı (NFA'dan düzenli ifadeye).** $L$ düzenli olduğu için onu kabul eden bir NFA $M$ vardır; tek kabul durumlu olduğu varsayılır (değilse eşdeğer tek kabul durumlu makine kurulabilir). Bu makineden etiketleri düzenli ifade olan **genelleştirilmiş geçiş grafiği** kurulur: tek sembollü geçişler aynen kalır, "$a,b$" etiketi $a+b$ olur (ekrandan, 01:15:00). Sonra başlangıç ve kabul dışındaki durumlar tek tek elenir. Ders örneğinde (ekrandan, 01:20:00) geçişler şöyledir:

  ```text
  q0 --b--> q1        q1 --a--> q0
  q1 --b--> q1 (döngü)
  q1 --a+b--> q2      q2 --b--> q2 (döngü)
  başlangıç: q0, kabul: q2
  ```

  $q_1$ elenince $q_0$ üzerinde $bb^*a$ döngüsü ve $q_0 \to q_2$ için $bb^*(a+b)$ etiketi oluşur. Sonuç: $r = (bb^*a)^*\,bb^*(a+b)\,b^*$ (ekrandan, 01:25:00). Hoca önce döngüyü $(ba)^*$ diye yazdı; bir öğrencinin uyarısıyla $q_1$'deki $b$ döngüsünün de hesaba katılması gerektiği görüldü.
- **Genel durum eleme (iki komşu).** $q_i \xrightarrow{a} q$, $q \xrightarrow{d} q_i$, $q$ üzerinde $e$ döngüsü, $q_j \xrightarrow{c} q$, $q \xrightarrow{b} q_j$ ise $q$ elenince: $q_i$ üzerinde $ae^*d$ döngüsü, $q_j$ üzerinde $ce^*b$ döngüsü, $q_i \to q_j$ için $ae^*b$, $q_j \to q_i$ için $ce^*d$ (ekrandan, 01:30:00). Üç komşu varsa yine durumdan geçen bütün yollar düşünülür.
- **Pompalama önsavının mantığı.** Ders örneğindeki 4 durumlu DFA'da $aaaab$ dizgisinin yürüyüşü $q_1 \to q_2 \to q_3 \to q_2 \to q_3 \to q_4$ olur; $q_2$ (ve $q_3$) tekrar eder (ekrandan, 02:05:00). Genel olarak $|w| \ge p$ ise yürüyüşte en az $p+1$ durum yer alır ve bir durum tekrar eder. İlk tekrar eden durum $q$ olsun: $x$ başlangıçtan $q$'nun ilk görülüşüne, $y$ iki görülüş arasına, $z$ geri kalana karşılık gelir (ekrandan, 02:20:00). $y$ bir döngü olduğu için atlanabilir ya da istenen kadar tekrar edilebilir; $xz$, $xyyz$, ... hepsi kabul edilir. $q$ ilk tekrar eden durum olduğundan $|xy| \le p$, döngü en az bir sembol içerdiğinden $|y| \ge 1$. $z$'nin biçimi önemli değildir; $x$ ve $y$'nin yollarıyla çakışabilir (ekrandan, 02:25:00).

> **Ders sonrası not:** Hoca güvercin yuvası slaytını derste "yuvalar durumlar değil, tekil geçişler olmalı" diye düzeltmeye çalıştı. Slayttaki ilk biçim de doğrudur: güvercinler yürüyüşteki durumlar ($|w|+1$ tane), yuvalar otomatın durumlarıdır ($p$ tane); $|w| \ge p$ ise $|w|+1 > p$ olur ve bir durum tekrar eder.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
