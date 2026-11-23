# Ders 12 Çalışma Özeti

## Genel Konular

- Deterministik yığıtlı otomatın (deterministic pushdown automaton, DPDA) biçimsel tanımı (ekrandan, 00:10:00)
  - DPDA bir 6'lıdır: $(Q, \Sigma, \Gamma, \delta, q_0, F)$. $Q$ durumlar, $\Sigma$ girdi alfabesi, $\Gamma$ yığıt alfabesi, $q_0 \in Q$ başlangıç durumu, $F \subseteq Q$ kabul durumlarıdır.
  - Geçiş fonksiyonu: $\delta : Q \times \Sigma_\varepsilon \times \Gamma_\varepsilon \to (Q \times \Gamma_\varepsilon) \cup \{\emptyset\}$. Girdi ve yığıt parametresi $\varepsilon$ da olabilir. Sonuç tek bir (durum, yığıta itilecek sembol) çifti ya da "böyle bir geçiş yok" anlamına gelen $\emptyset$'dir.
  - Ek koşul: her $q \in Q$, $a \in \Sigma$, $x \in \Gamma$ için $\delta(q,a,x)$, $\delta(q,a,\varepsilon)$, $\delta(q,\varepsilon,x)$ ve $\delta(q,\varepsilon,\varepsilon)$ değerlerinden tam olarak biri $\emptyset$ değildir. Bu dört durum birbirinden ayırt edilebildiği için makine $\varepsilon$-geçişleri olsa bile deterministiktir.
- İzin verilen ve verilmeyen geçişler (ekrandan, 00:20:00)
  - İzin verilir: $q_1$'den $a, b \to w_1$ ile $q_2$'ye ve $a, c \to w_2$ ile $q_3$'e; ya da $\lambda, b \to w_1$ ve $\lambda, c \to w_2$. Yığıt sembolleri ($b$ ve $c$) farklı olduğundan seçim deterministiktir.
  - İzin verilmez: aynı durum, aynı girdi ve aynı yığıt sembolüyle iki geçiş; ya da aynı durumda aynı yığıt sembolü için biri $a$ okuyan, diğeri $\lambda$ okuyan iki geçiş (ör. $a, b \to w_1$ ve $\lambda, b \to w_2$).
- Deterministik bağlamdan bağımsız dil
  - Bir $L$ dilini kabul eden bir DPDA varsa $L$ deterministik bağlamdan bağımsızdır (deterministic context-free). Örnek: $\{a^n b^n : n \ge 0\}$.
- DPDA olmayan PDA örneği: $L(M) = \{v v^R : v \in \{a,b\}^*\}$ (ekrandan, 00:25:00)
  - $q_0$ döngüsü: $a, \lambda \to a$ ve $b, \lambda \to b$; $q_0 \to q_1$: $\lambda, \lambda \to \lambda$; $q_1$ döngüsü: $a, a \to \lambda$ ve $b, b \to \lambda$; $q_1 \to q_2$ (kabul): $\lambda, \$ \to \$$.
  - $q_0$'da $a, \lambda \to a$ ile $\lambda, \lambda \to \lambda$ (ve $b, \lambda \to b$ ile $\lambda, \lambda \to \lambda$) birlikte var; tanıma göre bunlardan yalnız biri olabilirdi. Bu yüzden makine deterministik değildir. $q_1$'deki geçişlerde yığıt sembolleri farklı olduğundan sorun yoktur.
- PDA'lar DPDA'lardan daha güçlüdür
  - Deterministik bağlamdan bağımsız diller kümesi, bağlamdan bağımsız diller kümesinin öz alt kümesidir (strict subset).
  - İspat için bağlamdan bağımsız olup deterministik bağlamdan bağımsız olmayan bir dil gösterilir: $L = \{a^n b^n\} \cup \{a^n b^{2n}\},\ n \ge 0$ (ekrandan, 00:30:00).
  - $L$ bağlamdan bağımsızdır: $S \to S_1 \mid S_2$, $S_1 \to a S_1 b \mid \lambda$, $S_2 \to a S_2 bb \mid \lambda$. <!-- BELİRSİZ: gramer slaytı karelerde yok; kurallar anlatımdan kuruldu. -->
  - $L$ deterministik değildir (olmayana ergi): bir DPDA $M$ olsaydı, $a^n b^n$ ile bir kabul durumuna varır, kalan $b^n$ ile ikinci bir kabul durumuna giderdi (ekrandan, 00:35:00). $b$'ler $c$ ile değiştirilerek $M'$ kurulur, $M$'nin kabul durumları $M'$'nün karşılık gelen kabul durumlarına $\lambda$-geçişleriyle bağlanır (ekrandan, 00:45:00 ve 00:55:00). Ortaya çıkan PDA $L \cup \{a^n b^n c^n\}$ dilini kabul eder. Oysa bu dil bağlamdan bağımsız değildir (pompalama önsavıyla gösterilir). Çelişki, $L$'nin deterministik olmadığını gösterir.
- Turing makinesine giriş (ekrandan, 01:15:00)
  - Dil hiyerarşisi: düzenli diller ⊂ bağlamdan bağımsız diller ⊂ Turing makinelerinin kabul ettiği diller. $\{a^n b^n c^n\}$ bağlamdan bağımsız değildir, ama bir Turing makinesi tarafından kabul edilir.
  - İki yönde de sonsuz bir şerit (tape) vardır; okuma-yazma kafası her adımda bir sembol okur, bir sembol yazar ve sola (L) ya da sağa (R) bir hücre gider.
  - Girdi şeritte yazılıdır; geri kalan bütün hücreler boşluk (blank, $\lozenge$) sembolüdür. Başlangıçta kafa girdinin ilk sembolündedir.
  - Geçiş gösterimi: $q_1 \xrightarrow{a \to b, R} q_2$: $q_1$'de $a$ okunursa yerine $b$ yaz, sağa git, $q_2$'ye geç (ekrandan, 01:20:00).
- Turing makinesinin özellikleri
  - Deterministiktir: aynı (durum, sembol) çifti için tek geçiş olabilir. $\lambda$-geçişi yoktur.
  - Kısmi geçiş fonksiyonu: her sembol için geçiş çizmek gerekmez (ekrandan, 01:25:00).
  - Durma (halting): izlenecek geçiş kalmayınca makine durur. Kabul durumlarından çıkan geçiş yoktur; makine kabul durumunda durursa kabul eder (ekrandan, 01:30:00), kabul olmayan bir durumda durursa reddeder. Sonsuz döngüye giren makine hiç durmaz; bu girdi de reddedilmiş sayılır.
  - Kabul için girdinin tamamını taramak gerekmez.
- Turing makinesi örnekleri
  - $a^*$ dili: $q_0$ döngüsü $a \to a, R$; $q_0 \to q_1$ (kabul): $\lozenge \to \lozenge, L$ (ekrandan, 01:35:00). $aaa$ kabul edilir; $aba$'da $q_0$ durumunda $b$ için geçiş olmadığından makine durur ve reddeder.
  - Sonsuz döngü örneği: $aba$ girdisinde makine $a$ ile $b$ arasında gidip gelir, hiç durmaz (ekrandan, 01:40:00).
  - $\{a^n b^n : n \ge 1\}$ için Turing makinesi (ekrandan, 01:45:00): döngü içinde en soldaki $a$'yı $x$, ona karşılık gelen en soldaki $b$'yi $y$ yapar; $a$ kalmayınca yalnız $y$'ler ve boşluk görülürse kabul eder.
- Biçimsel tanım, anlık tanım ve tanınabilir diller
  - Turing makinesi 7'lidir: $M = (Q, \Sigma, \Gamma, \delta, q_0, \lozenge, F)$; $\delta : Q \times \Gamma \to Q \times \Gamma \times \{L, R\}$.
  - Anlık tanım (instantaneous description): durum adı, kafanın üzerindeki sembolün hemen önüne yazılır; ör. $q_2\,xayb \succ x\,q_0\,ayb$ (ekrandan, 02:25:00). Çok adım $\overset{*}{\succ}$ ile gösterilir.
  - $L(M) = \{w : q_0 w \overset{*}{\succ} x_1\, q_f\, x_2,\ q_f \in F\}$. Bir Turing makinesinin kabul ettiği dile Turing ile tanınabilir (Turing-recognizable), Turing ile kabul edilebilir ya da özyinelemeli sayılabilir (recursively enumerable) dil denir.
- Turing tezi ve algoritma
  - Mekanik yollarla yapılabilen her hesaplama bir Turing makinesiyle yapılabilir. Bir problem için algoritma, o problemi çözen bir Turing makinesidir.
- Turing makinesi türleri ve aynı güç (ekrandan, 02:35:00)
  - Türler: durma seçenekli (stay-option), yarı sonsuz şeritli, çok boyutlu, deterministik olmayan. Hepsinin standart Turing makinesiyle aynı güçte olduğu gösterilecek.
  - İki makine sınıfının aynı güçte olması, ikisinin de aynı diller kümesini kabul etmesi demektir. İspat benzetim (simulation) ile yapılır.
  - Durma seçenekli makine: kafa $L$ ve $R$'ye ek olarak yerinde kalabilir ($S$). Standart makine durma seçenekli makinenin özel hâlidir; tersi için $q_1 \xrightarrow{a \to b, S} q_2$ geçişi, $q_1 \xrightarrow{a \to b, L}$ ara durum $\xrightarrow{x \to x, R} q_2$ ile benzetilir; bu son geçiş her şerit sembolü $x$ için eklenir (ekrandan, 02:45:00 ve 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- DPDA tanımındaki "tam olarak biri boş değil" koşulu
  - Dört geçiş biçiminden ($\delta(q,a,x)$, $\delta(q,a,\varepsilon)$, $\delta(q,\varepsilon,x)$, $\delta(q,\varepsilon,\varepsilon)$) yalnız biri bulunabilir; aynı yığıt sembolü için hem girdi okuyan hem $\lambda$ okuyan geçiş olamaz.
- Bir PDA'nın deterministik olmadığını göstermek için tek bir çakışma yeter
  - Durumları tek tek gezip birden fazla çıkışı olanlarda çakışma aranır.
- DPDA'nın $L = \{a^n b^n\} \cup \{a^n b^{2n}\}$'yi neden "seri" kabul etmek zorunda olduğu
  - İki dilin baş kısımları ($a^n b^n$) aynı olduğu için iki ayrı dal açılamaz; bu, aynı geçişleri iki kez kullanmak, yani deterministik olmamak demektir.
- Durmak reddetmek değildir
  - Makine durduktan sonra bulunduğu durumun kabul durumu olup olmadığına bakılır.
- Algoritma ile Turing makinesi aynı şeydir
  - Bir problem için algoritma var demek, o algoritmayı yürüten bir Turing makinesi var demektir. Karmaşık Turing makinelerinin grafiği çizilmez, algoritması yazılır.

## Kısa Tekrar Notları

- DPDA: 6'lı; her $(q, a, x)$ için dört geçiş biçiminden tam olarak biri tanımlı.
- Deterministik bağlamdan bağımsız dil: bir DPDA'nın kabul ettiği dil.
- $\{v v^R\}$ için PDA deterministik değildir ($q_0$'daki $\lambda, \lambda \to \lambda$ geçişi çakışır).
- DCFL $\subsetneq$ CFL; karşı örnek $\{a^n b^n\} \cup \{a^n b^{2n}\}$.
- İspat: $M$ ve $b \to c$ yapılmış $M'$ kabul durumlarından $\lambda$ ile bağlanır, $\{a^n b^n c^n\}$ kabul edilmiş olur; çelişki.
- Turing makinesi: iki yönde sonsuz şerit, oku-yaz-sola/sağa git, boşluk sembolü $\lozenge$.
- Deterministik, $\lambda$-geçişi yok, kısmi geçiş fonksiyonu serbest.
- Kabul: kabul durumunda durmak. Red: kabul olmayan durumda durmak ya da sonsuz döngü.
- $a^n b^n$ ($n \ge 1$) makinesi: $a \to x$, $b \to y$ eşleştir; fazla $a$ olursa $q_1$'de boşluk, fazla $b$ olursa $q_3$'te $b$ görülür ve makine reddeder.
- 7'li tanım; anlık tanım $x_1\, q\, x_2$; Turing ile tanınabilir = özyinelemeli sayılabilir.
- Durma seçenekli makine standart makineyle aynı güçtedir: $S$ hareketi bir sola, bir sağa adımla benzetilir.

## Detaylı Açıklamalar

Ders, önceki hafta başlanan deterministik yığıtlı otomatların tekrarıyla başladı. Derste görülen olağan PDA'lar deterministik değildi. DPDA'nın biçimsel tanımı da altı bileşenlidir. Fark, geçiş fonksiyonuna konan ek koşuldadır. $\delta$ fonksiyonu bir (durum, girdi ya da $\varepsilon$, yığıt sembolü ya da $\varepsilon$) üçlüsünü alır ve ya bir (durum, itilecek yığıt sembolü ya da $\varepsilon$) çifti ya da $\emptyset$ döndürür. $\emptyset$ o üçlü için geçiş olmadığı anlamına gelir; çizimde görünmez. Ek koşula göre verilen her durum, girdi sembolü ve yığıt sembolü için $\delta(q,a,x)$, $\delta(q,a,\varepsilon)$, $\delta(q,\varepsilon,x)$, $\delta(q,\varepsilon,\varepsilon)$ değerlerinden tam olarak biri boş değildir. Böylece makine her adımda ne yapacağını bilir.

İzin verilen geçiş örneklerinde aynı durumdan çıkan iki geçiş farklı yığıt sembolleri ($b$ ve $c$) kullanır, bu yüzden çakışmaz. İzin verilmeyenlerde ya üç bileşen de aynıdır ya da aynı yığıt sembolü için bir geçiş girdi okurken diğeri $\lambda$ okur. Hoca ikincisinin özellikle önemli olduğunu belirtti: girdi kısmı $a$ yerine başka bir sembol ($d$ gibi) olabilirdi, ama $\lambda$ olamaz. $\{a^n b^n\}$ için gösterilen DPDA'da da olası sorunlu yerler incelendi: aynı durumdaki geçişler farklı girdiler ($a$, $b$) ya da farklı yığıt sembolleri ($a$, $\$$) kullandığından makine deterministiktir. <!-- BELİRSİZ: a^n b^n DPDA'sının slaytı karelerde yok; geçişler yalnız anlatımdan özetlendi. -->

$\{v v^R\}$ dilinin PDA'sı deterministik değildir. $q_0$'da girdi okuyup yığıta itmeyen $\lambda, \lambda \to \lambda$ geçişi, $a, \lambda \to a$ ve $b, \lambda \to b$ geçişleriyle aynı anda tanımlıdır. Tanıma göre $\delta(q_0, b, \varepsilon)$ ile $\delta(q_0, \varepsilon, \varepsilon)$'den yalnız biri boş olmayabilirdi. $q_1$'deki üç geçişin yığıt sembolleri ($a$, $b$, $\$$) farklı olduğu için orada sorun yoktur.

Ardından PDA'ların DPDA'lardan güçlü olduğu ispatlandı. Her DPDA aynı zamanda bir PDA olduğundan deterministik bağlamdan bağımsız diller bağlamdan bağımsız dillerin alt kümesidir; eşitlik olmadığını göstermek için bir karşı örnek yeter. Seçilen dil $L = \{a^n b^n\} \cup \{a^n b^{2n}\}$'dir. $L$'nin bağlamdan bağımsız olduğu bir gramerle gösterilir: $S_1$ eşit sayıda $a$ ve $b$, $S_2$ her $a$ için iki $b$ üretir, $S \to S_1 \mid S_2$ birleşimi verir. İkinci kısım olmayana ergiyle yapılır. $L$'yi kabul eden bir DPDA $M$ varsa, $a^n b^n$ ve $a^n b^{2n}$'nin baş kısımları aynı olduğu için makine ikiye ayrılamaz. Bu yüzden önce $a^n b^n$'i okuyup bir kabul durumuna varmalı, kalan $b^n$'i okuyup ikinci bir kabul durumuna gitmelidir. $M$'deki $b$'ler $c$ yapılarak $M'$ elde edilir. $M$'nin kabul durumları $M'$'deki karşılıklarına $\lambda$-geçişleriyle bağlanınca $a^n b^n$ $M$'de, kalan $c^n$ $M'$'de okunur. Böylece yeni PDA $L \cup \{a^n b^n c^n\}$ dilini kabul eder. Bu dil bağlamdan bağımsız değildir (pompalama önsavı); ama onu kabul eden bir PDA kurulmuş olur. Çelişkinin kaynağı, $L$'yi kabul eden bir DPDA olduğu varsayımıdır.

Aradan sonra Turing makinelerine geçildi. Turing makinesi şimdiye kadar görülen en güçlü makinedir; şeridi hem okunur hem yazılır ve iki yönde sonsuzdur (hoca bunu bilgisayarların belleğine benzetti). Kontrol biriminde olağan durumlar, geçişler, başlangıç ve kabul durumları bulunur. Her geçişte kafa bir sembol okur, bir sembol yazar, sola ya da sağa gider. Örnekte şerit $abac$ iken kafa ikinci $a$ üzerindedir; makine $a$'yı okur, yerine $k$ yazar ve sola gider; sonraki adımda $b$'nin yerine $f$ yazıp sağa döner (ekrandan, 01:15:00). Girdinin sonu, girdi dışındaki bütün hücrelerde bulunan boşluk sembolüyle anlaşılır. Boşluk okunduğunda yerine başka bir sembol yazılarak girdi uzatılabilir.

Turing makineleri deterministiktir ve $\lambda$-geçişi yoktur. Kısmi geçiş fonksiyonuna izin verilir. Makine geçiş bulamayınca durur; kabul durumunda durursa kabul eder, değilse reddeder. Kabul durumlarından çıkan geçiş olmaz. Sonsuz döngü de bir red nedenidir. $a^*$ makinesi $a$'ları atlayıp boşluğu görünce kabul durumuna geçer; alfabe yalnız $a$ içeriyorsa başlangıç durumu doğrudan kabul durumu yapılabilir ve makine girdiyi hiç taramadan kabul eder. $\{a^n b^n : n \ge 1\}$ makinesinde $q_0$ $a$'yı $x$ yapar, $q_1$ $a$ ve $y$'leri atlayıp ilk $b$'yi $y$ yapar, $q_2$ sola dönüp $x$'i görünce $q_0$'a geçer. $q_0$'da $a$ yerine $y$ görülürse $q_3$ $y$'leri atlar ve boşlukta kabul durumu $q_4$'e geçer. Fazla $b$ varsa $q_3$ bir $b$ görür, fazla $a$ varsa $q_1$ boşluk görür; iki durumda da makine durur ve reddeder. Bu makine biraz değiştirilerek $\{a^n b^n c^n\}$ için de makine kurulabilir.

Son kısımda biçimsel tanım, anlık tanım ve Turing tezi işlendi. Bir dil bir Turing makinesince kabul ediliyorsa Turing ile tanınabilir (ya da özyinelemeli sayılabilir) dildir. Turing tezine göre bilgisayarlarda yapılan her mekanik işlem bir Turing makinesiyle yapılabilir; bu, algoritmanın biçimsel tanımını verir. Turing makinesi türlerinin standart makineyle aynı güçte olduğu benzetimle ispatlanır. Durma seçenekli makinede $S$ hareketi, standart makinede bir sola gidip her olası sembolü değiştirmeden geri sağa dönen ek geçişlerle benzetilir. Örnekte $q_1$ durumunda $\lozenge aaba \lozenge$ şeridinin ilk $a$'sı $b$ yapılırken kafa yerinde kalır; standart makinede aradaki fazladan bir anlık tanımla aynı sonuca varılır (ekrandan, 02:50:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
