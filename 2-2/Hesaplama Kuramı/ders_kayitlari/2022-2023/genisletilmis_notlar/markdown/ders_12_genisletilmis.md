# Ders 12 Genişletilmiş Notu: Deterministik Yığıtlı Otomatlar ve Turing Makinelerine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Deterministik yığıtlı otomatın biçimsel tanımı
- 2. İzin verilen ve verilmeyen geçişler
- 3. Deterministik bağlamdan bağımsız diller ve DPDA olmayan bir PDA
- 4. PDA'lar DPDA'lardan daha güçlüdür
- 5. Turing makinesine giriş
- 6. Determinizm, kısmi geçiş fonksiyonu ve durma
- 7. Turing makinesi örnekleri
- 8. Biçimsel tanım, anlık tanım ve Turing ile tanınabilir diller
- 9. Turing tezi ve algoritma
- 10. Turing makinesi türleri ve durma seçenekli makine
- Örnek Sorular

## 1. Deterministik yığıtlı otomatın biçimsel tanımı

Derste şimdiye kadar görülen yığıtlı otomatlar (pushdown automata, PDA) deterministik değildi. Bu derste, bir önceki derste başlanan deterministik yığıtlı otomatlar (deterministic pushdown automaton, DPDA) baştan ele alındı. Hoca konuya biçimsel tanımla başlamayı tercih etti, çünkü farkı en açık biçimde tanım gösterir.

Slayttaki tanım şöyledir (ekrandan, 00:10:00): Bir deterministik yığıtlı otomat $(Q, \Sigma, \Gamma, \delta, q_0, F)$ biçiminde bir 6'lıdır (6-tuple). Burada $Q$, $\Sigma$, $\Gamma$ ve $F$ sonlu kümelerdir ve:

- $Q$ durumlar kümesidir,
- $\Sigma$ girdi alfabesidir,
- $\Gamma$ yığıt alfabesidir (yığıtta kullanılabilecek semboller),
- $\delta : Q \times \Sigma_\varepsilon \times \Gamma_\varepsilon \to (Q \times \Gamma_\varepsilon) \cup \{\emptyset\}$ geçiş fonksiyonudur,
- $q_0 \in Q$ başlangıç durumudur,
- $F \subseteq Q$ kabul durumları kümesidir.

Hoca geçiş fonksiyonunu parça parça okudu. $\delta$ üç parametre alır: birincisi bir durum, ikincisi bir girdi sembolü, üçüncüsü bir yığıt sembolüdür. $\Sigma_\varepsilon$ ve $\Gamma_\varepsilon$ gösterimindeki alt indis, bu parametrelerin $\varepsilon$ de olabileceğini söyler; normalde $\varepsilon$ girdi alfabesinin elemanı değildir. Fonksiyonun sonucu bir çifttir: birinci eleman yeni durum, ikinci eleman yığıta itilecek sembol (ya da $\varepsilon$). Bütün bu çiftler kartezyen çarpımla bir küme oluşturur; fonksiyon bu kümeden bir eleman ya da ek olarak eklenmiş $\emptyset$ döndürür. $\emptyset$ "bu üçlü için geçiş yok" demektir ve çizimlerde görünmez. Anlamı PDA'dan bilinen anlamdır: makine bir durumdayken bir girdi okur, yığıttan bir sembol çeker (pop), yeni bir duruma geçer ve yığıta bir sembol iter (push).

Buraya kadar olağan PDA tanımından farklı bir şey yoktur. Fark şu ek koşuldadır: her $q \in Q$, $a \in \Sigma$ ve $x \in \Gamma$ için

$$\delta(q,a,x),\quad \delta(q,a,\varepsilon),\quad \delta(q,\varepsilon,x),\quad \delta(q,\varepsilon,\varepsilon)$$

değerlerinden tam olarak biri $\emptyset$ değildir. Yani iki tanesi tanımlı olamaz, hiçbiri tanımsız da olamaz. Dört biçim sırasıyla şudur: durum, girdi ve yığıt sembolü verilmiş; yalnız durum ve girdi verilmiş, yığıttan bir şey çekilmiyor; girdi okunmuyor, yığıttan $x$ çekiliyor; ne girdi okunuyor ne yığıttan bir şey çekiliyor. Bu dört biçim birbirinden kolayca ayırt edildiği için, $\varepsilon$-geçişleri olsa bile makine her adımda ne yapacağını bilir; "öyle mi olur, böyle mi olur" durumu yoktur. Bu yüzden deterministiktir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki tanım Sipser'in kitabındandır. Sipser'in tanımı her $(q,a,x)$ için tam olarak bir geçiş ister. Sonraki slaytlardaki çizimlerde ise geçişin hiç olmaması da kabul edilir; o çizimlerde asıl kural, aynı durumda birbiriyle çakışan iki geçiş bulunmamasıdır.

## 2. İzin verilen ve verilmeyen geçişler

Slaytta izin verilen geçişlere iki örnek vardır (ekrandan, 00:20:00):

| Örnek | $q_1$'den çıkan 1. geçiş | $q_1$'den çıkan 2. geçiş |
|---|---|---|
| Sol | $a, b \to w_1$ ile $q_2$'ye | $a, c \to w_2$ ile $q_3$'e |
| Sağ | $\lambda, b \to w_1$ ile $q_2$'ye | $\lambda, c \to w_2$ ile $q_3$'e |

İki örnekte de iki geçişin üçlüleri yığıt sembolü ($b$ ve $c$) yüzünden farklıdır, bu yüzden seçim deterministiktir (slaytın altında "deterministic choices" yazar).

İzin verilmeyen geçişlerde ise iki durum anlatıldı. Birincisinde iki geçiş tamamen aynı üçlüyü kullanır: aynı durum, aynı girdi, aynı yığıt sembolü. Makine hangisini izleyeceğini bilemez. İkincisinde hoca özellikle "bu önemli" dedi: aynı durumda, aynı yığıt sembolü $b$ için bir geçiş $a$ okurken diğeri $\lambda$ okur. Biçimsel tanıma göre bunlardan yalnız biri bulunabilir. Girdi kısmı $a$ yerine $d$ gibi başka bir sembol olsaydı sorun olmazdı; ama $\lambda$ olamaz. Yığıt sembolleri farklıysa ($b$ ve $c$), biri $\lambda$ okusa da izin verilir.

> **Hocanın vurgusu:** Dört geçiş biçiminden tam olarak biri bulunmalıdır; aynı yığıt sembolü için hem girdi okuyan hem $\lambda$ okuyan iki geçiş DPDA'da olamaz.

Ardından $\{a^n b^n\}$ dilini kabul eden bir DPDA örneği incelendi. DPDA'lar çalışma biçimi bakımından PDA'lara çok benzer; tek fark geçiş fonksiyonundaki koşuldur. Hoca olası sorunlu yerlere baktı: $q_1$'den çıkan geçişler farklı girdiler ($a$ ve $b$) okuduğundan çakışmaz; $q_2$'de $b$ okuyan ve $\lambda$ okuyan geçişler ise yığıttan farklı semboller ($a$ ve $\$$) çektiğinden yine çakışmaz. Dolayısıyla makine deterministiktir. <!-- BELİRSİZ: bu DPDA'nın slaytı karelerde yok; geçişlerin tam listesi okunamadı, yalnız anlatım özetlendi. -->

## 3. Deterministik bağlamdan bağımsız diller ve DPDA olmayan bir PDA

Tanım: Bir $L$ dilini kabul eden bir DPDA varsa $L$ deterministik bağlamdan bağımsızdır (deterministic context-free). Örneğin $\{a^n b^n\}$ için bir DPDA verildiğinden bu dil deterministik bağlamdan bağımsızdır.

Karşı örnek olarak $L(M) = \{v v^R : v \in \{a,b\}^*\}$ dilinin PDA'sı gösterildi (ekrandan, 00:25:00). Geçişleri:

| Durum | Geçiş | Hedef |
|---|---|---|
| $q_0$ (başlangıç) | $a, \lambda \to a$ | $q_0$ |
| $q_0$ | $b, \lambda \to b$ | $q_0$ |
| $q_0$ | $\lambda, \lambda \to \lambda$ | $q_1$ |
| $q_1$ | $a, a \to \lambda$ | $q_1$ |
| $q_1$ | $b, b \to \lambda$ | $q_1$ |
| $q_1$ | $\lambda, \$ \to \$$ | $q_2$ (kabul) |

Neyin sorun çıkardığını bulmak için birden fazla geçişi olan durumlara bakılır. $q_0$'ın üç geçişi vardır. $a, \lambda \to a$ ile $b, \lambda \to b$ farklı girdiler okuduğu için çakışmaz. Ama $b, \lambda \to b$ ile $\lambda, \lambda \to \lambda$ aynı anda tanımlıdır; DPDA'da $\delta(q_0, b, \varepsilon)$ ile $\delta(q_0, \varepsilon, \varepsilon)$'den yalnız biri bulunabilirdi. Aynı durum $a, \lambda \to a$ için de geçerlidir. Makineyi deterministik olmaktan çıkarmak için tek bir çakışma yeter, ama hoca $q_1$'e de baktı: oradaki üç geçişin yığıt sembolleri ($a$, $b$, $\$$) farklı olduğu için orada sorun yoktur.

## 4. PDA'lar DPDA'lardan daha güçlüdür

### 4.1 İddia

PDA'ların DPDA'lardan güçlü olması, deterministik bağlamdan bağımsız diller kümesinin bağlamdan bağımsız diller kümesinin öz alt kümesi (strict subset) olması demektir. Her DPDA aynı zamanda bir PDA olduğundan alt küme olduğu açıktır. Eşitlik olmadığını göstermek için bağlamdan bağımsız olup hiçbir DPDA'nın kabul etmediği en az bir dil bulmak yeter.

Kullanılan dil şudur (ekrandan, 00:30:00):

$$L = \{a^n b^n\} \cup \{a^n b^{2n}\}, \qquad n \ge 0$$

Gösterilecek iki şey vardır: $L$ bağlamdan bağımsızdır; $L$ deterministik bağlamdan bağımsız değildir.

### 4.2 $L$ bağlamdan bağımsızdır

Bunu göstermenin iki yolu vardır: bir bağlamdan bağımsız gramer ya da bir PDA vermek. Burada gramer verildi. $S_1$ eşit sayıda $a$ ve $b$ üretir; sonunda $S_1$ boş dizgiyle silinir. $S_2$ her $a$ için iki $b$ üretir ve yine boş dizgiyle silinir. İki gramer "veya" ile birleştirilir:

$$S \to S_1 \mid S_2, \qquad S_1 \to a S_1 b \mid \lambda, \qquad S_2 \to a S_2 bb \mid \lambda$$

<!-- BELİRSİZ: gramer slaytı karelerde yok; kurallar anlatımdaki tariften kuruldu. -->

### 4.3 $L$ deterministik değildir

İspat olmayana ergidir (proof by contradiction). $L$'nin deterministik bağlamdan bağımsız olduğunu, yani $L$'yi kabul eden bir DPDA $M$ bulunduğunu varsayalım.

Hoca burada sınıfa bir soru sordu: $M$ neden üstte $a^n b^n$'i, altta $a^n b^{2n}$'yi kabul eden iki ayrı dalla kurulamaz? Bir öğrencinin cevabı doğruydu: iki dilin baş kısmı aynı olduğundan iki dal aynı geçişlerle başlamak zorunda kalır; bu da makineyi deterministik olmaktan çıkarır. Makine ikiye ayrılamıyorsa bu iki yapıyı seri biçimde kabul etmelidir: önce $a^n b^n$'i okuyup bir kabul durumuna varır, sonra kalan $b^n$'i okuyup ikinci bir kabul durumuna gider (ekrandan, 00:35:00):

```text
→ ( ) --a^n b^n--> (( )) --b^n--> (( ))
   |_____ a^n b^n kabul ___|
   |__________ a^n b^{2n} kabul ________|
```

Bu yapının varlığı determinizmden gelir.

Sonra şu olgu kullanılır: $\{a^n b^n c^n\}$ bağlamdan bağımsız değildir (ekrandan, 00:40:00). Slayt bunu dil hiyerarşisiyle de gösterir: düzenli diller (ör. $a^* b^*$) bağlamdan bağımsız dillerin (ör. $a^n b^n$) içindedir, $a^n b^n c^n$ ise bunların dışındadır; ispatı bağlamdan bağımsız diller için pompalama önsavıyla yapılır. Aynı şekilde $L \cup \{a^n b^n c^n\}$ de bağlamdan bağımsız değildir.

Çelişki şöyle kurulur:

1. $M$'deki $b$'ler $c$ ile değiştirilerek yeni bir DPDA $M'$ elde edilir: $L(M') = \{a^n c^n\} \cup \{a^n c^{2n}\}$ (ekrandan, 00:45:00). Hoca bunun yalnızca harf değişikliği olduğunu, bir sıkıntı yaratmadığını söyledi.
2. $M$'nin kabul durumları, $M'$'deki karşılık gelen kabul durumlarına $\lambda$-geçişleriyle bağlanır (ekrandan, 00:55:00). Bu birleşik makine bir PDA'dır.
3. Bu PDA'da $a^n b^n$ kısmı $M$'de okunur, $\lambda$-geçişiyle $M'$'ye inilir ve kalan $c^n$ orada okunur. Yani $a^n b^n c^n$ kabul edilir. $L$'deki dizgiler de $M$ kısmında kabul edilir.
4. Böylece $L \cup \{a^n b^n c^n\}$ dilini kabul eden bir PDA kurulmuş olur; bu, dilin bağlamdan bağımsız olduğunu söyler. Oysa pompalama önsavıyla bağlamdan bağımsız olmadığı gösterilebilir.

Çelişki vardır; tek varsayım $L$'yi kabul eden bir DPDA bulunduğuydu. Demek ki $L$ deterministik bağlamdan bağımsız değildir ve DPDA'lar PDA'lardan daha az güçlüdür.

## 5. Turing makinesine giriş

### 5.1 Dil hiyerarşisi ve şerit

Aradan sonra Turing makinelerine geçildi. Dil hiyerarşisinin en altında düzenli diller vardır. Düzenli olmayan dillerin bir kısmı bağlamdan bağımsızdır. Ama bağlamdan bağımsız olmayan diller de vardır ve bunların bir kısmını Turing makineleri kabul eder. Turing makinesi şimdiye kadar görülen en güçlü makinedir.

Turing makinesi diğer otomatlara benzer. Ana farklar:

- Bir şeridi (tape) vardır. Şerit hem okunur hem yazılır.
- Şerit iki yönde de sonsuzdur. Hoca bunu bugünkü bilgisayarların belleğine (RAM) benzetti.
- Kontrol biriminde olağan durumlar, geçişler, başlangıç, kabul ve red durumları bulunur.
- Okuma-yazma kafası her adımda sola ya da sağa bir hücre gider.

Her geçişte kafa bir sembol okur, bir sembol yazar ve sola ya da sağa gider.

### 5.2 Şerit örneği

Slayttaki örnek (ekrandan, 01:15:00):

| Zaman | Şerit | Kafa |
|---|---|---|
| 0 | $\ldots\ a\ b\ a\ c\ \ldots$ | ikinci $a$ üzerinde |
| 1 | $\ldots\ a\ b\ k\ c\ \ldots$ | $b$ üzerinde |

Makine $a$'yı okur, yerine $k$ yazar ve sola gider. Sonraki adımda $b$'yi okur, yerine $f$ yazar ve sağa döner.

Hoca, işlemin 0 anında mı 1 anında mı yapıldığı konusunda emin olmadığını söyledi ve büyük olasılıkla iki an arasında olduğunu belirtti.

> **Ders sonrası not:** Slaytlardaki "Time $i$" bir anlık durumu (şerit, durum, kafa konumu) gösterir. Geçiş $i$ anındaki sembolü okur ve sonucunda $i+1$ anındaki durum oluşur; yani okuma-yazma-hareket iki an arasında yapılır.

### 5.3 Girdi ve boşluk sembolü

Diğer otomatlardaki girdi dizgisi burada da vardır, ama şeridin üzerinde yazılıdır. Şerit sonsuz olduğu için girdinin sonu özel bir boşluk sembolüyle (blank) anlaşılır; slaytlarda $\lozenge$ ile gösterilir. Girdi dışındaki bütün hücrelerde boşluk olduğu varsayılır. Sağa giderken boşluğa varılırsa girdinin sonuna, sola giderken varılırsa başına gelinmiş demektir. Başlangıçta (0 anında) kafa girdinin ilk sembolündedir.

### 5.4 Geçiş gösterimi

Grafikte geçiş $q_1 \xrightarrow{a \to b,\ R} q_2$ biçiminde yazılır: okunan sembol, yazılan sembol ve yön ($L$ sol, $R$ sağ). Anlık gösterimde o anki durum adı kafanın altına yazılır (ekrandan, 01:20:00). Örnek: $q_1$ durumunda kafa $\lozenge\lozenge\, a\, b\, a\, c\, \lozenge$ şeridindeki ikinci $a$'dayken bu geçiş uygulanırsa $a$ yerine $b$ yazılır, kafa $c$'ye geçer ve durum $q_2$ olur. Aynı örneğin sola giden biçimi de gösterildi. Bir başka örnekte $q_1$'de boşluk okunup yerine $g$ yazılıyor ve sağa gidiliyor; böylece dört sembollük girdi uzatılmış olur.

## 6. Determinizm, kısmi geçiş fonksiyonu ve durma

### 6.1 Turing makineleri deterministiktir

Aynı (durum, okunan sembol) çifti için tek bir şey yapılabilir. $q_1$'den $a$ ve $b$ okuyan iki geçiş sorunsuzdur; ama $q_1$'den $a$ okuyan iki geçiş varsa makine hangisini izleyeceğini bilemez. Buna izin vermek determinizmsizliğe izin vermek olurdu. Ayrıca $\lambda$-geçişlerine izin verilmez.

### 6.2 Kısmi geçiş fonksiyonu

Slaytta (ekrandan, 01:25:00) $q_1$'den $a \to b, R$ ile $q_2$'ye ve $b \to d, L$ ile $q_3$'e giden iki geçiş vardır; kafanın üzerindeki sembol $c$ ise ve $c$ için geçiş yoktur. Slayt buna "izin verilir" der. Hoca slaytın ne demek istediğini önce sınıfa sordu, sonra şöyle yorumladı: deterministik sonlu otomatlarda her alfabe sembolü için geçiş göstermek gerekiyordu; Turing makinelerinde gerekmez. $c$ için geçiş yoksa çizilmez.

### 6.3 Durma (halting)

İzlenecek geçiş kalmayınca makine durur. Örnekler:

- $q_1$'den hiç çıkış geçişi yoksa makine $q_1$'de durur.
- $q_1$'den çıkış geçişleri var ama okunan sembol $c$ için yoksa makine yine $q_1$'de durur.

Kabul durumlarından çıkan geçiş olmaz; kabul durumuna giren geçişler olabilir (ekrandan, 01:30:00). Kabul durumuna varan makine durur ve kabul eder.

> **Hocanın vurgusu:** Durmak reddetmek demek değildir; durmak yalnızca makinenin durmasıdır. Ardından bulunulan durumun kabul durumu olup olmadığına bakılarak kabul ya da red kararı verilir.

Özetle:

- Makine durur ve kabul durumundaysa girdiyi kabul eder.
- Makine durur ve kabul durumunda değilse reddeder.
- Turing makineleri sonsuz döngüye girebilir. O zaman makine hiç durmaz ve girdi reddedilmiş sayılır.

Turing makinelerinde yeni bir özellik daha vardır: bir girdiyi kabul etmek için bütün sembollerini taramak gerekmez. Bazı sembolleri tarayıp kabul etmek mümkündür.

## 7. Turing makinesi örnekleri

### 7.1 $a^*$ dili

Alfabe $\{a, b\}$, dil herhangi sayıda $a$'dır (ekrandan, 01:35:00):

| Durum | Okunan | Yazılan, yön | Hedef |
|---|---|---|---|
| $q_0$ (başlangıç) | $a$ | $a, R$ | $q_0$ |
| $q_0$ | $\lozenge$ | $\lozenge, L$ | $q_1$ (kabul) |

$a$ okundukça aynı $a$ geri yazılır; yani $a$'ya dokunulmadan sağa geçilir. Boşluk görülünce boşluk geri yazılır, sola gidilir ve kabul durumuna geçilir.

Kabul örneği, girdi $aaa$: 0 anında $q_0$, kafa ilk $a$'da. 0, 1 ve 2 anlarında birer $a$ okunup geri yazılır ve sağa gidilir. 3 anında boşluk okunur, geri yazılır, sola gidilir ve $q_1$'e geçilir. Kabul durumuna varıldığı için makine durur ve kabul eder.

Red örneği, girdi $aba$: 0 anında $a$ okunur, sağa gidilir. 1 anında kafa $b$'dedir; $q_0$'da $b$ okuyan geçiş yoktur, makine durur. $q_0$ kabul durumu olmadığından reddeder.

Aynı dil için daha basit bir makine de verildi: alfabe yalnız $a$'dan oluşuyorsa başlangıç durumu doğrudan kabul durumudur. Makine hiçbir şey okumadan, 0 anında durur ve kabul eder; girdinin ya boş ya da yalnız $a$'lardan oluştuğu zaten bilinir.

### 7.2 Sonsuz döngü örneği

İkinci makine, herhangi sayıda $a$'dan ya da bir $b$ ile başlayıp $a$ ve $b$'lerle devam eden dizgilerden oluşan dil için verildi. Girdi $aba$ ve başlangıç durumu $q_0$ iken 0 anında $a$ okunur, geri yazılır, sağa gidilir; 1 anında $b$ okunur, geri yazılır, sola gidilir. Kafa başladığı yere döner. 2, 3, 4, 5 anlarında makine hep $q_0$ durumunda, kafa $a$ ile $b$ arasında gidip gelir (ekrandan, 01:40:00). Makine bu girdiyle hiç duramaz; başka bir girdiyle durabilir. Kabul durumuna hiç varılamadığı için bu girdi reddedilir. <!-- BELİRSİZ: makinenin grafiği karelerde yok; anlatımdan $q_0$'da $a \to a, R$ ve $b \to b, L$ geçişleri olduğu anlaşılıyor. -->

### 7.3 $\{a^n b^n : n \ge 1\}$ için Turing makinesi

Dilde en az bir $a$ ve bir $b$ bulunmalı ve sayıları eşit olmalıdır. Slayttaki makine (ekrandan, 01:45:00):

| Durum | Okunan | Yazılan, yön | Hedef |
|---|---|---|---|
| $q_0$ (başlangıç) | $a$ | $x, R$ | $q_1$ |
| $q_0$ | $y$ | $y, R$ | $q_3$ |
| $q_1$ | $a$ | $a, R$ | $q_1$ |
| $q_1$ | $y$ | $y, R$ | $q_1$ |
| $q_1$ | $b$ | $y, L$ | $q_2$ |
| $q_2$ | $a$ | $a, L$ | $q_2$ |
| $q_2$ | $y$ | $y, L$ | $q_2$ |
| $q_2$ | $x$ | $x, R$ | $q_0$ |
| $q_3$ | $y$ | $y, R$ | $q_3$ |
| $q_3$ | $\lozenge$ | $\lozenge, L$ | $q_4$ (kabul) |

Hoca, Turing makinesi grafiklerinin genelde karmaşık olduğunu, bu yüzden ileriki derslerde grafik çizmeyip yalnız temel fikri ya da algoritmayı yazacaklarını söyledi.

Girdi $aabb$ üzerinde iz (anlatımdan; python ile adım adım doğrulandı):

| Adım | Durum | Şerit | Yapılan |
|---|---|---|---|
| 0 | $q_0$ | $\underline{a}abb$ | $a \to x$, sağa |
| 1 | $q_1$ | $x\underline{a}bb$ | $a$ atlanır |
| 2 | $q_1$ | $xa\underline{b}b$ | $b \to y$, sola |
| 3 | $q_2$ | $x\underline{a}yb$ | $a$ atlanır, sola |
| 4 | $q_2$ | $\underline{x}ayb$ | $x$ görüldü, sağa, $q_0$ |
| 5 | $q_0$ | $x\underline{a}yb$ | $a \to x$, sağa |
| 6 | $q_1$ | $xx\underline{y}b$ | $y$ atlanır |
| 7 | $q_1$ | $xxy\underline{b}$ | $b \to y$, sola |
| 8 | $q_2$ | $xx\underline{y}y$ | $y$ atlanır, sola |
| 9 | $q_2$ | $x\underline{x}yy$ | $x$ görüldü, sağa, $q_0$ |
| 10 | $q_0$ | $xx\underline{y}y$ | $a$ yok, $y$ var: $q_3$ |
| 11-12 | $q_3$ | $xxy\underline{y}$, sonra boşluk | $y$'ler atlanır |
| 13 | $q_4$ | $xxyy$ | kabul |

Makine bir döngü içinde en soldaki $a$'yı $x$ yapar, en soldaki $b$'yi bulup $y$ yapar ve geri döner. $q_0$'da artık $a$ yerine $y$ görülürse bütün $a$'lar eşleşmiştir; $q_3$ $y$'leri atlar ve boşlukta kabul eder. Hoca döngüyü bir "repeat" gibi okumayı önerdi.

Reddedilen iki durum da incelendi:

- Fazla $b$ varsa (ör. $aabbb$): $q_3$ $y$'leri atlarken bir $b$ görür. $q_3$ $b$ tüketemez; makine durur ve reddeder.
- Fazla $a$ varsa (ör. $aaabb$): iki eşleşmeden sonra üçüncü $a$ $x$ yapılır, $q_1$ sağa giderken $b$ bulamaz ve boşluğa varır. $q_1$'de boşluk için geçiş yoktur; makine $q_1$'de durur ve reddeder.

Algoritma olarak: tekrar et, en soldaki $a$'yı $x$ ile değiştir, en soldaki $b$'yi bul ve $y$ ile değiştir; $a$ ya da $b$ kalmayana kadar sürdür. Artan bir $a$ ya da $b$ varsa reddet, yoksa kabul et.

Hoca son olarak bu makinenin biraz değiştirilmesiyle $\{a^n b^n c^n\}$ için de kolayca bir makine kurulabileceğini söyledi. Bu dil bağlamdan bağımsız değildir, yani hiçbir PDA onu kabul edemez; ama bir Turing makinesi kabul eder.

### 7.4 Turing makinesinin gücü

Turing makinesi görülecek en güçlü makinedir. Bugünkü bilgisayarlarda yazılabilen her program bir Turing makinesiyle temsil edilebilir. Bir dili hiçbir Turing makinesi kabul etmiyorsa o dili kabul eden bir bilgisayar programı da yazılamaz. Hoca sınıfa önceki derslerde algoritmanın tanımını öğrenip öğrenmediklerini sordu ve muhtemelen "programı yazmadan önce adımlarını düşünüp yazmak" gibi biçimsel olmayan bir tarif verildiğini söyledi. Burada biçimsel bir tanım verilecektir (bkz. Bölüm 9).

## 8. Biçimsel tanım, anlık tanım ve Turing ile tanınabilir diller

### 8.1 Biçimsel tanım

Geçiş fonksiyonu bir durum ve okunan şerit sembolünü alır; sonuç yeni (ya da aynı) durum, şeride yazılan sembol ve yöndür:

$$\delta : Q \times \Gamma \to Q \times \Gamma \times \{L, R\}, \qquad \delta(q_1, a) = (q_2, b, R)$$

Turing makinesi bir 7'lidir:

$$M = (Q, \Sigma, \Gamma, \delta, q_0, \lozenge, F)$$

Bileşenler: durumlar, girdi alfabesi, şerit alfabesi, geçiş fonksiyonu, başlangıç durumu, boşluk sembolü, kabul durumları. Hoca bazı kitapların boşluk için farklı bir sembol kullandığını söyledi. Girdi alfabesi ile şerit alfabesinin farkını kitaptan bakılmasını önerdi.

> **Ders sonrası not:** Hoca girdi alfabesiyle şerit alfabesinin aynı şey olup olmadığını sordu. Aynı değildir: $\Sigma \subseteq \Gamma - \{\lozenge\}$. Şerit alfabesi girdi sembollerine ek olarak boşluk sembolünü ve makinenin çalışırken yazdığı yardımcı sembolleri (örneğin $a^n b^n$ makinesindeki $x$ ve $y$) içerir.

### 8.2 Yapılandırma ve anlık tanım

Yapılandırma (configuration) şeridin içeriği, o anki durum ve kafanın konumudur. Bu, anlık tanımla (instantaneous description) yazılır: şerit kafanın olduğu yerden bölünür, durum adı kafanın üzerindeki sembolün hemen önüne yazılır, kafanın solundaki kısım durum adından önce gelir. Boşluklar yazılmaz.

Bir hareket (move), bir anlık tanımdan diğerine geçmektir ve "verir" (yields) diye okunur (ekrandan, 02:25:00). $a^n b^n$ makinesinde 4 anında kafa $x$ üzerindeyken:

$$q_2\, xayb \succ x\, q_0\, ayb$$

Hesaplama bu hareketlerin art arda gelmesidir: $q_0\, aabb \succ x\, q_1\, abb \succ \ldots$. Aradaki tanımları göstermek yerine kısaltma kullanılır: $q_0\, aabb \overset{*}{\succ} \ldots$ "bir miktar hesaplamayla bu tanıma varılır" demektir.

Başlangıç yapılandırması: durum adı en başta, girdinin tamamı ondan sonradır: $q_0 w$.

### 8.3 Kabul edilen dil

Bir Turing makinesinin dili, başlangıç tanımından bir miktar hesaplamayla durum adı bir kabul durumu olan bir tanıma varan dizgilerdir; durumdan önce ve sonra herhangi dizgiler bulunabilir:

$$L(M) = \{ w : q_0 w \overset{*}{\succ} x_1\, q_f\, x_2,\ q_f \in F \}$$

Bir $L$ dili bir Turing makinesince kabul ediliyorsa $L$ Turing ile tanınabilir (Turing-recognizable) dildir. Aynı kavram için Turing ile kabul edilebilir (Turing-acceptable) ve özyinelemeli sayılabilir (recursively enumerable) adları da kullanılır; üçü aynı anlamdadır.

## 9. Turing tezi ve algoritma

Turing tezi: mekanik yollarla yapılan her hesaplama bir Turing makinesiyle yapılabilir. Hoca bunu bilgisayarlar üzerinden açıkladı: bellekten okumak, belleğe yazmak, yazmaçların değerlerini değiştirmek gibi bilgisayarda olan her şey bir Turing makinesiyle yapılabilir.

Bu, algoritmanın tanımını da verir: bir problem için algoritma, o problemi çözen bir Turing makinesidir. Algoritma mekanik adımları tarif eder ve bu adımlar kolayca Turing makinesi adımlarına çevrilebilir. Bu yüzden "bu problem için bir algoritma vardır" demek, o algoritmayı yürüten bir Turing makinesi vardır demektir.

> **Hocanın vurgusu:** Algoritma ile Turing makinesinin yürütülmesi aynı şeydir; bu çok önemlidir.

> **Ders sonrası not:** Hoca ders ortasında tanımı "bir algoritma, bir Turing makinesi tarafından kabul edilen bir dildir" diye söyledi. Slayttaki tanım ise "bir problem için algoritma, o problemi çözen bir Turing makinesidir" biçimindedir; algoritma bir dil değil, makinenin kendisidir.

## 10. Turing makinesi türleri ve durma seçenekli makine

### 10.1 Standart model ve aynı güç

Önce standart model tekrar edildi: iki yönde sonsuz bir şerit, okuma-yazma kafası (her adımda sola ya da sağa gider) ve deterministik bir kontrol birimi. İncelenecek türler: durma seçenekli (stay-option), yarı sonsuz (semi-infinite) şeritli, çok boyutlu ve deterministik olmayan Turing makineleri. Bu türlerin hepsinin standart makineyle aynı güçte olduğu gösterilecektir.

İki makine sınıfı aynı güçteyse, ikisi de tam olarak aynı diller kümesini kabul eder (ekrandan, 02:35:00); burada bu küme Turing ile tanınabilir dillerdir. Matematiksel olarak: birinci sınıftaki her $M_1$ için ikinci sınıfta $L(M_1) = L(M_2)$ olan bir $M_2$ vardır ve ikinci sınıftaki her $M_2$ için birinci sınıfta aynı dili kabul eden bir $M_1$ vardır.

### 10.2 Benzetim

Aynı güç benzetim (simulation) tekniğiyle ispatlanır. Bir sınıftaki $M_1$ makinesi, öteki sınıfın özellikleriyle kurulan bir $M_2$ makinesiyle benzetilir: $M_1$ bir sembol okuyup yazıyorsa $M_2$ de aynısını yapar. Daha kesin olarak, $M_2$'nin yapılandırmaları $M_1$'in yapılandırmalarına karşılık gelir; aynı ya da benzer anlık tanımlar görülür. $M_1$'de kabul durumuna varılıyorsa benzetimde de karşılık gelen bir kabul durumu vardır; böylece $L(M_1) = L(M_2)$ olur.

### 10.3 Durma seçenekli Turing makinesi

Bu türde kafa sola ve sağa gitmeye ek olarak yerinde kalabilir. Geçişte yön yerine $S$ (stay) yazılır: $q_1 \xrightarrow{a \to b,\ S} q_2$, $q_1$'de $a$ okunursa yerine $b$ yaz, yerinde kal, $q_2$'ye geç demektir.

Teorem: durma seçenekli makineler standart makinelerle aynı güçtedir. İspat iki adımdır:

1. Durma seçenekli makineler standart makineleri benzetebilir. Bu açıktır: durma seçenekli makinede standart makinenin her şeyi vardır, ek olarak $S$ hareketi vardır. Her standart makine aynı zamanda bir durma seçenekli makinedir.
2. Standart makineler durma seçenekli makineleri benzetebilir. Bunun için her $S$ geçişi yeni bir ara durumla iki geçişe bölünür (ekrandan, 02:45:00):

```text
Durma seçenekli:   q1 --(a -> b, S)--> q2

Standart benzetim: q1 --(a -> b, L)--> q_ara --(x -> x, R)--> q2
                   (ikinci geçiş her olası şerit sembolü x için eklenir)
```

$q_1$'de $a$ okunur, yerine $b$ yazılır ve sola gidilir. Kafa artık bir soldaki hücrededir ve orada alfabedeki herhangi bir sembol olabilir. Bu yüzden her olası şerit sembolü $x$ için "$x$ oku, $x$ geri yaz, sağa git, $q_2$'ye geç" geçişi eklenir. Örneğin şerit alfabesi $\{a, b\}$ ise iki geçiş gerekir: $a \to a, R$ ve $b \to b, R$. Sol ve sağ hareketli geçişler değişmez, çünkü onların standart makinede karşılığı zaten vardır.

Benzetim örneği (ekrandan, 02:50:00):

| Makine | Anlık durumlar |
|---|---|
| Durma seçenekli | 1: $\lozenge\, \underline{a}\, a b a\, \lozenge$, durum $q_1$ $\to$ 2: $\lozenge\, \underline{b}\, a b a\, \lozenge$, durum $q_2$ |
| Standart | 1: kafa ilk $a$'da, $q_1$ $\to$ 2: $a$ yerine $b$ yazılmış, kafa soldaki $\lozenge$'da, ara durum $\to$ 3: kafa yeniden $b$'de, son durum |

$a$ $b$'ye dönüşür ve kafa yerinde kalır. Standart makine aynı başlangıç ve aynı son tanıma varır; yalnız arada fazladan bir anlık tanımdan geçer. Slaytta standart makinedeki ara durum $q_2$, son durum $q_3$ diye adlandırılmıştır; bir önceki slayttaki gösterimle karşılaştırırken ara durumun yeni eklenen durum olduğuna dikkat edilmelidir. İspat burada biter.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): $L(M) = \{v v^R : v \in \{a,b\}^*\}$ için verilen PDA ($q_0$: $a, \lambda \to a$; $b, \lambda \to b$; $q_0 \to q_1$: $\lambda, \lambda \to \lambda$; $q_1$: $a, a \to \lambda$; $b, b \to \lambda$; $q_1 \to q_2$: $\lambda, \$ \to \$$) neden deterministik değildir?

> **Çözüm (derste verildi):** $q_0$'da $b, \lambda \to b$ ve $\lambda, \lambda \to \lambda$ birlikte tanımlıdır; yani $\delta(q_0, b, \varepsilon)$ ve $\delta(q_0, \varepsilon, \varepsilon)$ ikisi de boş değildir. DPDA tanımına göre bunlardan yalnız biri olabilir ($a, \lambda \to a$ için de aynı çakışma vardır). $q_1$'deki geçişlerde yığıt sembolleri farklı olduğu için sorun yoktur. Tek çakışma makineyi deterministik olmaktan çıkarmaya yeter.

**Soru 2** (derste sözlü, 00:36:07): $L = \{a^n b^n\} \cup \{a^n b^{2n}\}$ dilini kabul ettiği varsayılan DPDA neden üstte $a^n b^n$, altta $a^n b^{2n}$ için iki ayrı dalla kurulamaz?

> **Çözüm (derste verildi):** İki dilin baş kısmı aynıdır. İki dal aynı durumdan aynı girdi ve yığıt sembolüyle başlayan geçişler gerektirir; bu da tamamen aynı iki geçiş demektir ve makineyi deterministik olmaktan çıkarır. DPDA bu yüzden dili seri kabul etmelidir: önce $a^n b^n$ ile bir kabul durumuna, sonra kalan $b^n$ ile ikinci bir kabul durumuna.

**Soru 3** (ekrandan, 01:35:00): $q_0 \xrightarrow{a \to a, R} q_0$ ve $q_0 \xrightarrow{\lozenge \to \lozenge, L} q_1$ (kabul) makinesi $aaa$ ve $aba$ girdilerinde ne yapar?

> **Çözüm (derste verildi):** $aaa$: üç $a$ atlanır, 3 anında boşluk okunur, $q_1$'e geçilir; makine durur ve kabul eder. $aba$: 1 anında $q_0$'da $b$ okunur, geçiş yoktur; makine $q_0$'da durur ve kabul durumunda olmadığı için reddeder.

**Soru 4** (ekrandan, 01:40:00): Sonsuz döngü örneğindeki makine $aba$ girdisinde neden durmaz ve sonuç nedir?

> **Çözüm (derste verildi):** $q_0$'da $a$ okununca sağa, $b$ okununca sola gidilir. Kafa $a$ ile $b$ arasında gidip gelir, durum hep $q_0$ kalır; makine hiç durmaz. Kabul durumuna varılamadığı için girdi reddedilmiş sayılır.

**Soru 5** (ekrandan, 01:45:00; derste sözlü, 01:55:43): $\{a^n b^n : n \ge 1\}$ Turing makinesi $aabbb$ ve $aaabb$ girdilerini nasıl reddeder?

> **Çözüm (derste verildi; python ile doğrulandı):** $aabbb$: iki eşleşmeden sonra şerit $xxyyb$ olur; $q_0$ $y$ görüp $q_3$'e geçer, $q_3$ $y$'leri atlayıp $b$'ye varır. $q_3$'te $b$ için geçiş yoktur; makine durur ve reddeder. $aaabb$: iki eşleşmeden sonra şerit $xxayy$ olur; üçüncü $a$ $x$ yapılır, $q_1$ $y$'leri atlayıp boşluğa varır. $q_1$'de boşluk için geçiş yoktur; makine $q_1$'de durur ve reddeder.

**Soru 6** (ekrandan, 02:50:00): Durma seçenekli makinedeki $q_1 \xrightarrow{a \to b, S} q_2$ geçişi $\lozenge\, a a b a\, \lozenge$ şeridinin ilk $a$'sında uygulanıyor. Standart makine bunu nasıl benzetir?

> **Çözüm (derste verildi):** Standart makine $q_1 \xrightarrow{a \to b, L}$ ile $a$ yerine $b$ yazar ve soldaki $\lozenge$'a gider; ara durumda $\lozenge \to \lozenge, R$ (her olası sembol için eklenen $x \to x, R$ geçişlerinden biri) ile yeniden $b$'nin üzerine döner. Sonuç şerit $\lozenge\, b a b a\, \lozenge$, kafa ilk hücrede; durma seçenekli makinenin vardığı tanımın aynısıdır, arada yalnız bir fazladan tanım vardır.

## Dersin Toparlaması

Dersin ilk yarısında deterministik yığıtlı otomatlar biçimsel olarak tanımlandı. DPDA'da her (durum, girdi, yığıt sembolü) için dört geçiş biçiminden tam olarak biri bulunabilir. Bir DPDA'nın kabul ettiği diller deterministik bağlamdan bağımsız dillerdir. $\{a^n b^n\} \cup \{a^n b^{2n}\}$ dili bağlamdan bağımsızdır, ama hiçbir DPDA onu kabul edemez. İspatta $b$'leri $c$ yapılmış bir kopya kurulur ve iki makine $\lambda$-geçişleriyle bağlanır; böylece bağlamdan bağımsız olmayan $\{a^n b^n c^n\}$ dili de bir PDA'ya kabul ettirilmiş olurdu. Bu çelişki, PDA'ların DPDA'lardan güçlü olduğunu gösterir.

İkinci yarıda Turing makineleri tanıtıldı: iki yönde sonsuz, okunup yazılabilen bir şerit; deterministik geçişler; durma, kabul ve sonsuz döngü kavramları. $a^*$ ve $\{a^n b^n\}$ makineleri adım adım izlendi; 7'li biçimsel tanım, anlık tanım ve Turing ile tanınabilir diller verildi. Turing tezine göre algoritma, bir problemi çözen Turing makinesidir. Son olarak Turing makinesi türlerinin standart makineyle aynı güçte olduğunun benzetimle gösterileceği söylendi ve ilk tür olan durma seçenekli makine için ispat yapıldı. Sonraki derslerde öteki türlerle (yarı sonsuz şeritli, çok boyutlu, deterministik olmayan) devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
