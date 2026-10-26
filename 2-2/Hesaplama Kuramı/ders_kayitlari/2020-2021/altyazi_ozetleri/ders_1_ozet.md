# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 9 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl ders yaklaşık 00:04'te başlar. Hoca tahta olarak bir tablet uygulaması kullanıyor.
- Dersin tanıtımı
  - Dersin kodu BLM2502, adı Hesaplama Kuramı (Theory of Computation).
  - Ders büyük ölçüde otomatlar (automata) üzerinedir. Otomatlar teorik makinelerdir.
  - Soru şu: Bu makineler hangi problemleri çözebilir? Algoritma nedir, hesaplama (computation) nedir?
- Değerlendirme (geçici plan, tahtadan)
  - 2 ödev, her biri 15 puan.
  - 1 vize (midterm), 30 puan.
  - Final, 40 puan.
  - Vize 8. ya da 9. haftada olacak. Ders programında 9. hafta yazıyor.
- Kaynak kitap
  - Michael Sipser, *Introduction to the Theory of Computation*, 3. baskı. Tek kaynak budur.
  - Hoca not, slayt veya sunum vermeyecek. Not tutmak öğrencinin sorumluluğu.
- Dönemin konuları (geçici liste)
  - İspat türleri.
  - Deterministik ve deterministik olmayan sonlu otomatlar (DFA, NFA).
  - Bağlamdan bağımsız diller (context-free languages) ve yığın otomatları (pushdown automata).
  - Church-Turing tezi, Turing makineleri ve türleri.
  - Zaman kalırsa: karar verilebilirlik (decidability), indirgenebilirlik (reducibility), NP-tamlık (NP-completeness).
- Hesaplama kuramının üç alanı
  - Karmaşıklık kuramı (complexity theory): Bazı problemler neden zor, bazıları neden kolay?
  - Hesaplanabilirlik kuramı (computability theory): Bir problem çözülebilir mi, çözülemez mi?
  - Otomat kuramı (automata theory): Farklı hesaplama modellerinin tanımları ve özellikleri.
  - Derste sıra tersten gidecek: önce otomat kuramı, sonra hesaplanabilirlik, sonra karmaşıklık.
- Küme kuramı tekrarı
  - Bilinen kümeler, alt küme, kuvvet kümesi, birleşim, kesişim, fark, Kartezyen çarpım, tümleyen.
  - İkili bağıntı (binary relation), fonksiyon, tanım kümesi, denklik bağıntısı (equivalence relation).
- Boole mantığı
  - Değil, ve, veya, özel veya (XOR), denklik ve gerektirme (implication) işlemleri ile doğruluk tabloları.
- Teorem, ispat, aksiyom, hipotez, lemma ve sonuç (corollary) kavramları.
- İspat teknikleri
  - İspat yazma ipuçları.
  - Doğrudan ispat (direct proof).
  - Yapıcı ispat (constructive proof).
  - Olmayana ergi (proof by contradiction) bir sonraki derse kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ders İngilizce yapılacak.
  - Yabancı öğrenci olsun olmasın dil değişmez. Hoca gerekirse ara sıra Türkçe açıklama yapabilir.
- Kitaptaki bütün alıştırma ve problemleri çözün.
  - Ödev sayısı az. Dersi gerçekten öğrenmek için kitaptaki işlenen konuların bütün alıştırmalarını yapın.
- Not ve slayt verilmeyecek.
  - Kendi notunuzu tutun.
- Bir problemi "kolay" ya da "zor" diye sınıflandırabilmek çok önemli.
  - Problem kolaysa onu hızlı çözen bir algoritma yazarsınız.
  - Problem zorsa en iyi çözümü aramazsınız. Problemi değiştirir, rastgele yöntem dener ya da "yeterince iyi" bir çözüm ararsınız.
  - Bu sınıflandırma tahminle değil, matematiksel ispatla yapılır.
- Turing makineleri en önemli hesaplama modelidir.
  - Turing makinesinin çözemediği bir problemi gerçek bir bilgisayar da çözemez.
- Teoremi tam anlamadan ispata başlamayın.
  - Teoremi kendi cümlelerinizle yeniden yazın. Her ayrıntı önemlidir.
- "Ancak ve ancak" (if and only if) içeren teoremde iki yön de ispatlanır.
  - Küme eşitliğinde de iki alt küme ilişkisi ayrı ayrı ispatlanır.
- Sorularınızı sohbete yazmayın, sesli sorun.
  - Hoca yazarken sohbeti anlık takip edemiyor.

## Kısa Tekrar Notları

- Kolay problem: girdi büyüdükçe süre polinom olarak artar (ör. $n$, $n^2$).
  - Örnek: 1 milyon sayıyı sıralamak, telefon rehberinde isim aramak.
- Zor problem: süre üstel olarak artar (ör. $2^n$).
  - Örnek: bütün dersler için ders programı ve sınıf yerleşimi hazırlamak.
- 1930'larda, daha bilgisayarlar yokken, bazı matematik problemlerinin bilgisayarla çözülemeyeceği gösterildi.
  - Örnek: "Rastgele bir matematiksel önerme doğru mu yanlış mı?" problemi çözülemez.
- Kuvvet kümesi: $\mathcal{P}(B) = \{A \mid A \subseteq B\}$. Boş küme ve $B$'nin kendisi de içindedir.
- Kartezyen çarpım: $A \times B = \{(x, y) \mid x \in A, y \in B\}$.
- Fonksiyon $f: A \to B$: her $a \in A$ için bağıntıda ilk bileşeni $a$ olan tam olarak bir sıralı ikili vardır.
- Denklik bağıntısı üç şartı sağlar: yansıma (reflexive), simetri (symmetric), geçişme (transitive).
- Gerektirme $P \Rightarrow Q$ yalnızca $P$ doğru, $Q$ yanlış olduğunda yanlıştır.
- Aksiyom: ispatsız kabul edilen varsayım. Teorem: ispatlanmış doğru önerme.
- Lemma: başka bir teoremin ispatında kullanılan yardımcı teorem. Sonuç (corollary): bir teoremden kolayca çıkan özel durum.
- Doğrudan ispat: girdiden başlayıp adım adım sonuca gidilir.
- Yapıcı ispat: "böyle bir nesne vardır" diyen teoremde bir örnek nesne kurmak yeter.

## Detaylı Açıklamalar

Dersin ilk kısmı tanıtım ve dönem planıyla geçer. Hoca, hesaplama kuramının temel sorusunu şöyle koyar: Bilgisayar donanımı ve yazılımının matematiksel özellikleri nelerdir? Hesaplama nedir, algoritma nedir, bilgisayarların sınırları nelerdir? Amaç, gerçek bilgisayarları yansıtan biçimsel matematiksel modeller kurmaktır. Böylece gerçek bilgisayar kullanmadan bilgisayarlar hakkında matematiksel olarak düşünebiliriz.

### Karmaşıklık, hesaplanabilirlik ve otomat kuramı

- Karmaşıklık kuramı problemleri "kolay" ve "zor" diye sınıflandırır.
  - Kolay: bilgisayar problemi verimli (hızlı) çözebilir.
  - Zor: girdi büyüdükçe gereken süre o kadar hızlı artar ki bilgisayar ne kadar güçlü olursa olsun makul sürede çözemez.
  - Ders programı örneğinde girdi boyutu $n$ ders sayısıdır. $n$ küçükken problem kolaydır, $n$ büyüdükçe süre çok hızlı artar.
  - Hoca ileride ikiden fazla sınıf (ör. "çok zor") görüleceğini söyledi.
- Hesaplanabilirlik kuramı problemleri "çözülebilir" ve "çözülemez" diye sınıflandırır.
  - Çözülemeyen bir problem üzerinde çalışmak boşa zamandır. Bu yüzden sınıflandırma önemlidir.
- Otomat kuramı farklı hesaplama modellerini inceler.
  - Sonlu otomatlar metin işleme ve derleyicilerde kullanılır.
  - Bağlamdan bağımsız gramerler programlama dillerinde ve yapay zekâda kullanılır.
  - Turing makineleri gerçek bilgisayarların basit ve soyut bir modelidir. Karmaşıklık kuramı Turing makinesine dayandırılabilir.

### Küme kuramı

- Bilinen kümeler: doğal sayılar $\mathbb{N}$, tam sayılar $\mathbb{Z}$, rasyonel sayılar $\mathbb{Q}$, reel sayılar $\mathbb{R}$.
- Rasyonel sayılar: $\mathbb{Q} = \{\frac{m}{n} \mid m \in \mathbb{Z}, n \in \mathbb{Z}, n \neq 0\}$.
- Alt küme: $A$'nın her elemanı $B$'nin de elemanıysa $A \subseteq B$.
- İşlemler:
  - $A \cup B = \{x \mid x \in A \lor x \in B\}$
  - $A \cap B = \{x \mid x \in A \land x \in B\}$
  - $A - B = \{x \mid x \in A \land x \notin B\}$
  - $\overline{A} = \{x \in U \mid x \notin A\}$. Tümleyen için evrensel küme $U$ tanımlı olmalıdır.
- İkili bağıntı: $A \times B$'nin bir alt kümesidir.
- Fonksiyon: Özel bir ikili bağıntıdır.
  - Aynı $a$ iki farklı değere gidemez.
  - Farklı elemanların aynı değere gitmesi serbesttir.
  - $f(a) = b$ yazılır: "$f$, $a$'yı $b$'ye götürür" ya da "$a$'nın $f$ altındaki görüntüsü $b$'dir".
- Denklik bağıntısı: $R \subseteq A \times A$ olmalı ve şu üç şartı sağlamalı:
  - Yansıma: her $a \in A$ için $(a, a) \in R$.
  - Simetri: $(a, b) \in R$ ise $(b, a) \in R$.
  - Geçişme: $(a, b) \in R$ ve $(b, c) \in R$ ise $(a, c) \in R$.

### Kuvvet kümesi örneği (Türkçe açıklama)

Bir öğrenci kuvvet kümesini sordu. Hoca Türkçe açıkladı: Kuvvet kümesi, bir kümenin bütün alt kümelerinden oluşan kümedir. $B = \{1, 2, 3\}$ için:

$\mathcal{P}(B) = \{\emptyset, \{1\}, \{2\}, \{3\}, \{1,2\}, \{1,3\}, \{2,3\}, \{1,2,3\}\}$

Bu küme $2^3 = 8$ elemanlıdır.

### Boole mantığı

Değerler yanlış (0, F) ve doğrudur (1, T).

| $P$ | $Q$ | $P \land Q$ | $P \lor Q$ | $P \oplus Q$ | $P \Leftrightarrow Q$ | $P \Rightarrow Q$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 | 1 | 1 |

- Değil (NOT): $\neg 0 = 1$, $\neg 1 = 0$.
- XOR: argümanlar farklıysa 1.
- Denklik: XOR'un tersi. Argümanlar aynıysa 1.
- Gerektirme: "eğer koşul, o zaman sonuç" (if-then).
  - Hocanın örneği: $P$ = "çöpü çıkarırsın", $Q$ = "para alırsın".
  - Çöpü çıkardın ama para almadın: söz bozuldu, gerektirme yanlış.
  - Diğer bütün durumlarda gerektirme doğrudur.
  - İlginç durum: Çöpü çıkarmadığın hâlde para alırsan gerektirme yine doğrudur.

### Teorem, aksiyom, hipotez

- İspat, bir teoremin doğru olduğunu gösteren matematiksel önermeler dizisidir.
- Aksiyom ispatsız kabul edilen bir varsayımdır. Az sayıdadır.
  - Hocanın örneği olasılık aksiyomlarıdır. Bir olayın olasılığı negatif olmayan bir reel sayıdır. Örnek uzayın olasılığı 1'dir. Ayrık olayların birleşiminin olasılığı, olasılıkların toplamıdır.
  - Bütün olasılık kuramı bu üç aksiyomdan ispatla kurulur. Örnek: $P(\overline{A}) = 1 - P(A)$ bir aksiyom değildir, aksiyomlardan ispatlanır.
  - Hoca bunu Türkçe de anlattı: İspatlanan her teorem "araç kutusuna" eklenen yeni bir araçtır.
- Hipotez, teorem hâline gelmesi için ispat bekleyen bir varsayımdır.
- Lemma ile teorem arasındaki fark derste internetten bakılarak tartışıldı.
  - Sonuç: Ayrım büyük ölçüde düzenleme tercihidir. Lemma da teorem kadar doğrudur.

### İspat ipuçları

- Teoremi okuyup tamamen anlayın. Hoca bunun en zor kısım olduğunu söyledi.
- Bazı teoremler aslında iki ispat içerir:
  - $A \Leftrightarrow B$ için $A \Rightarrow B$ ve $B \Rightarrow A$ ayrı ayrı ispatlanır.
  - $A = B$ küme eşitliği için $A \subseteq B$ ve $B \subseteq A$ ayrı ayrı ispatlanır.
- Önce birkaç basit durumu deneyin, sonra ispatı yazın.
- İlk denemede ispatlayamazsanız endişelenmeyin. İspat bulmak zaman ve pratik ister.

### Doğrudan ispat örneği

**Teorem:** $n$ tek ve pozitif bir tam sayıysa $n^2$ de tektir.

**İspat:**
- $n$ tek olduğundan $n = 2k + 1$ yazılır. Burada $k \geq 0$ bir tam sayıdır.
- $n^2 = (2k+1)^2 = 4k^2 + 4k + 1 = 2(2k^2 + 2k) + 1$.
- $2(2k^2 + 2k)$ çifttir. Çift sayıya 1 eklenince tek sayı çıkar.
- O hâlde $n^2$ tektir.

### Yapıcı ispat örneği

**Teorem:** Öyle bir rasyonel $p$ sayısı vardır ki $p = q^r$ yazılabilir ve $q$ ile $r$'nin ikisi de irrasyoneldir.

**Derste verilen ispat:**
- $q = \sqrt{2}^{\sqrt{2}}$ ve $r = \sqrt{2}$ seçilir.
- $q^r = (\sqrt{2}^{\sqrt{2}})^{\sqrt{2}} = \sqrt{2}^{\sqrt{2} \cdot \sqrt{2}} = \sqrt{2}^2 = 2$.
- 2 rasyonel bir sayıdır. Bir örnek kurulduğu için ispat biter.

Dersin sonunda bir öğrenci $q^r = 2$ hesabını sordu. Hoca Türkçe açıkladı: Üslü sayının üssü alınırken üsler çarpılır. $\sqrt{2} \cdot \sqrt{2} = 2$ olduğundan sonuç $\sqrt{2}^2 = 2$ çıkar. $q$'yu önce sayısal olarak hesaplamaya gerek yoktur.

### Ders sonrası notlar

- **Ödev puanları:** Altyazıda ödevler için "50 points each" geçiyor. Tahtada "2 homeworks → 15 pts each" yazıyor. Toplam $15 + 15 + 30 + 40 = 100$ olduğu için doğrusu 15'tir. Plan ikinci derste değişti (bkz. Ders 2).
- **Rasyonel sayı tanımı:** Tahtadaki tanımda $n \neq 0$ şartı yazılmamış. Hoca bunu sözlü olarak söyledi. Tanımda bu şart olmalıdır.
- **Kuvvet kümesi örneği:** Hoca $\{1,2,3\}$'ün alt kümelerini sayarken $\{2,3\}$'ü atladı ve $\{1,2,3\}$'ü iki kez söyledi. Doğru liste yukarıda, 8 elemanlıdır.
- **Olasılık aksiyomu 1:** Derste "sıfırdan büyük" dendi. Doğrusu: Olasılık negatif olmayan bir sayıdır, yani $P(A) \geq 0$. Olasılığı 0 olan olaylar vardır.
- **Olasılık aksiyomu 3:** Hoca önce "bağımsız (independent)" dedi, sonra kendisi düzeltti. Doğrusu: Ayrık (disjoint, karşılıklı dışlayan) olaylar için $P(\bigcup A_i) = \sum P(A_i)$. Bağımsız olaylar için böyle bir kural yoktur.
- **Denklik işlemi:** Hoca bu işlemin "özel bir adı olmadığını" söyledi. Bu işlemin adı çift yönlü koşul (biconditional) ya da "ancak ve ancak"tır. Mantık devrelerinde XNOR olarak bilinir.
- **Değer kümesi:** Hoca $B$'ye "fonksiyonun range'i" dedi. Sipser'ın kitabı da bu terimi kullanır. Birçok kaynakta $B$'ye değer kümesi (codomain) denir. Range ise çoğu zaman yalnız fiilen alınan değerlerin kümesidir (görüntü kümesi).
- **Doğrudan ispattaki $k$:** Derste $k$ için "pozitif tam sayı" dendi. $n = 1$ için $k = 0$ olur. Bu yüzden $k \geq 0$ yazılmalıdır. Benzer şekilde $2k^2 + 2k$ sıfırdan büyük değil, sıfır veya daha büyüktür. İspatın sonucu değişmez.
- **Yapıcı ispattaki eksik adım:** İspat, $q = \sqrt{2}^{\sqrt{2}}$ sayısının irrasyonel olduğunu kabul ediyor. Bu doğrudur ama kolay değildir. Gelfond-Schneider teoremine göre bu sayı aşkındır (transcendental), dolayısıyla irrasyoneldir. Bu teoremi kullanmadan bilinen klasik ispat yapıcı değildir:
  - $\sqrt{2}^{\sqrt{2}}$ rasyonelse $q = r = \sqrt{2}$ seçilir, iş biter.
  - $\sqrt{2}^{\sqrt{2}}$ irrasyonelse derste verilen seçim kullanılır.
  - Hangi durumun doğru olduğunu bilmeden teorem ispatlanmış olur. Bu yüzden bu örnek ders kitaplarında çoğu zaman yapıcı olmayan ispat örneği olarak geçer.

**Not:** Bu ders İngilizce anlatılmıştır. İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
