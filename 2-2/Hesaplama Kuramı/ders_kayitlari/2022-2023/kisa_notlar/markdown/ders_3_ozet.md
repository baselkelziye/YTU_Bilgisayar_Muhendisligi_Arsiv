# Ders 3 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı: diller ve dizgi işlemleri
  - Alfabe sembollerden, dizgi (string) sembol dizisinden, dil ise dizgi kümesinden oluşur. Bir hesaplama problemi ("$x$ asal mı?") bir küme üyeliği problemine ("$x \in PRIMES$ mi?") çevrilebilir.
  - Tekli (unary) sayılarda değer, 1'lerin sayısıdır (örneğin $11 = 2$, $111 = 3$).
  - Dizgi işlemleri: birleştirme (concatenation), ters çevirme, uzunluk $|w|$, boş dizgi, alt dizgi, önek, sonek, üs alma ($w^0 = \lambda$), yıldız kapanışı $\Sigma^*$ (boş dizgi dahil bütün dizgiler) ve artı kapanışı $\Sigma^+$ (boş dizgi hariç).
  - Dil işlemleri: diller küme olduğu için birleşim, kesişim, fark ve tümleyen uygulanır. Ters çevirme, birleştirme ve üs alma kümedeki her dizgiye uygulanır; $L^0 = \{\lambda\}$, $L^* = L^0 \cup L^1 \cup L^2 \cup \dots$, $L^+$ ise $\lambda$'yı dışarıda bırakır.
- Deterministik sonlu otomat (DFA)
  - Giriş şeridini soldan sağa okuyan, çıktısı yalnız "kabul" ya da "ret" olan çok sınırlı bir hesaplama modelidir.
  - Geçiş grafiğinde her daire bir durumdur. Hiçbir durumdan çıkmayan okun gösterdiği durum başlangıç durumudur. Çift daireli durumlar kabul durumlarıdır. Otomat her an tek bir durumdadır.
  - Dizginin tamamı okunduktan sonra otomat bir kabul durumundaysa dizgi kabul edilir, değilse reddedilir.
  - Tuzak durum (trap state): her sembolde kendine dönen, kabul olmayan durumdur; otomat oraya girince geri kalan girdi ne olursa olsun dizgi reddedilir.
- DFA'nın biçimsel tanımı
  - $M = (Q, \Sigma, \delta, q_0, F)$: durumlar kümesi, giriş alfabesi ($\lambda \notin \Sigma$), geçiş fonksiyonu $\delta: Q \times \Sigma \to Q$, başlangıç durumu ve kabul durumları kümesi (ekrandan, 00:45:00).
  - Geçiş fonksiyonu bir geçiş tablosu olarak yazılabilir: satırlar durumlar, sütunlar sembollerdir.
  - Genişletilmiş geçiş fonksiyonu $\delta^*: Q \times \Sigma^* \to Q$ bir dizginin tamamını okuyunca varılan durumu verir. Her $q$ için $\delta^*(q, \lambda) = q$.
- DFA'nın dili ve düzenli diller
  - $L(M) = \{ w \in \Sigma^* : \delta^*(q_0, w) \in F \}$ (ekrandan, 01:10:00). Reddedilen dil bunun tümleyenidir: $\delta^*(q_0, w) \notin F$.
  - Bir dili kabul eden bir DFA varsa o dil düzenlidir (regular). Düzenli diller ailesi, DFA'ların kabul ettiği bütün dillerdir.
  - $\{a^n b^n : n \ge 0\}$ ve tekli toplama dili düzenli değildir: DFA iki farklı sembolün sayısını sayıp eşleştiremez. İspatı ileriki derslere bırakıldı.
- Deterministik olmayan sonlu otomat (NFA)
  - Bir durumdan aynı sembolle birden fazla duruma geçilebilir. Bu durumda otomat kendini çoğaltmış gibi düşünülür: paralel hesaplama dalları oluşur.
  - Bir durumdan bir sembol için geçiş tanımlı değilse o dal o sembolde ölür (girdi tüketilemez). DFA'dan farklı olarak her sembol için geçiş yazmak gerekmez.
  - $\varepsilon$ (null) geçişleri: girdi okunmadan, okuma kafası ilerlemeden başka duruma geçilir; kaynak durum da etkin kalır.
  - NFA bir dizgiyi, girdinin tamamını tüketip kabul durumunda biten en az bir hesaplama yolu varsa kabul eder. Hiçbir yol kabul etmiyorsa (yollar ya kabul olmayan durumda biter ya da girdiyi tüketemez) reddeder.
  - Hesaplama ağacı (computation tree): bir girdi için etkin durumları adım adım dal dal çizmek, NFA'nın ne yaptığını görmeyi kolaylaştırır.
- NFA'nın biçimsel tanımı ve dili
  - Yine 5'li: $M = (Q, \Sigma, \delta, q_0, F)$. Fark geçiş fonksiyonundadır: $\delta(q, x)$ bir durum kümesi döndürür ve $x$ yerine $\varepsilon$ da gelebilir.
  - $\delta^*(q_i, w)$, $q_i$'den $w$ etiketli bir yürüyüşle ulaşılabilen durumların kümesidir; her $q$ için $q \in \delta^*(q, \lambda)$.
  - $L(M) = \{ w : \delta^*(q_0, w) \text{ kümesinde en az bir kabul durumu var} \}$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Biçimsel tanımın neden gerektiği
  - Bir otomatın bir dizgiyi kabul edip etmediğine karar veren bir program yazarken durumları, alfabeyi ve geçiş fonksiyonunu tanımlamak gerekir; ispatlarda da biçimsel tanım kullanılır. Sınavlarda biçimsel tanım ya da bir parçası sorulabilir.
- Dili küme olarak yazmak
  - Otomatın dilini İngilizce ya da Türkçe tarif etmek yerine bu derste küme gösterimiyle yazmak beklenir, örneğin $\{a^n b : n \ge 0\}$.
- Tümleyen dil için DFA
  - Bir dilin tümleyenini tanıyan DFA'yı çizmek için önce özgün DFA çizilir, sonra kabul ve kabul olmayan durumlar yer değiştirilir ("001 içeren" ve "001 içermeyen" örneği).
- Hesaplama ağacı
  - Bu kısım slaytlarda yoktu; hoca NFA'ları anlamak için örnek girdilerle hesaplama ağacı çizmeyi önerdi ve bunun not alınmasını istedi. Kitapta da geçtiğini söyledi.
- NFA'larda "kabul etmek" ile "tüketmek" ayrımı
  - Bir durumun bir sembolü okuması için "consume/read" demek gerekir; "kabul" yalnız dizgi düzeyinde kullanılır.

## Kısa Tekrar Notları

- DFA: her durum ve her sembol için tam olarak bir geçiş; her an tek durum.
- Başlangıç durumu: hiçbir durumdan çıkmayan ok; kabul durumu: çift daire.
- Kabul: girdi bitince son durum $\in F$. Boş dizgi, başlangıç durumu kabul durumuysa kabul edilir.
- $\delta: Q \times \Sigma \to Q$, $\delta^*: Q \times \Sigma^* \to Q$, $\delta^*(q, \lambda) = q$.
- $L(M) = \{ w \in \Sigma^* : \delta^*(q_0, w) \in F \}$; bir DFA'nın kabul ettiği dil düzenlidir.
- Kabul durumu olmayan DFA: $L = \emptyset$. Tek durumlu, kabul eden DFA: $L = \Sigma^*$. Yalnız başlangıçta kabul, sonra tuzak: $L = \{\lambda\}$.
- $\{a^n b^n\}$ düzenli değildir; DFA sayamaz.
- NFA: bir sembolle birden çok geçiş, eksik geçiş ve $\varepsilon$-geçişi serbest; en az bir kabul eden yol yeter.
- NFA'da $\delta$ küme döndürür: $\delta(q_1, 0) = \{q_0, q_2\}$, tanımsız geçiş $\emptyset$.
- NFA'lar aynı dili çoğu zaman DFA'dan daha sade bir grafikle ifade eder.

## Detaylı Açıklamalar

- **İlk DFA örneği (yalnız $abba$'yı kabul eden).** Durumlar $q_0, \dots, q_5$, alfabe $\{a, b\}$, tek kabul durumu $q_4$, $q_5$ tuzak durumdur (ekrandan, 00:20:00). $abba$ okunurken sırasıyla $q_0 \to q_1 \to q_2 \to q_3 \to q_4$ izlenir ve kabul edilir. $aba$ için son durum $q_5$ olduğundan ret; boş girdi için otomat $q_0$'da kalır, $q_0$ kabul olmadığı için ret. Geçiş tablosu grafikten şöyle okunur:

  | $\delta$ | $a$ | $b$ |
  |---|---|---|
  | $q_0$ | $q_1$ | $q_5$ |
  | $q_1$ | $q_5$ | $q_2$ |
  | $q_2$ | $q_5$ | $q_3$ |
  | $q_3$ | $q_4$ | $q_5$ |
  | $q_4$ | $q_5$ | $q_5$ |
  | $q_5$ | $q_5$ | $q_5$ |

  Örnekler: $\delta^*(q_0, ab) = q_2$ (ekrandan, 00:50:00), $\delta^*(q_0, abbba) = q_5$, $\delta^*(q_1, bba) = q_4$ (python ile doğrulandı). Aynı grafikte $q_0$, $q_2$, $q_4$ kabul durumu yapılınca dil $\{\varepsilon, ab, abba\}$ olur (ekrandan, 00:30:00).

- **$\{a^n b : n \ge 0\}$ örneği.** $q_0$'da $a$ ile kendine dönüş, $b$ ile kabul durumu $q_1$'e geçiş, $q_1$'den $a$ ya da $b$ ile tuzak durum $q_2$ (ekrandan, 00:35:00). $aab$ kabul, $bab$ ret ($q_0 \xrightarrow{b} q_1 \xrightarrow{a} q_2 \xrightarrow{b} q_2$). $n = 0$ olabildiği için yalnız $b$ de kabul edilir; $n$'nin üst sınırı olmadığından dil sonsuzdur.

- **Çift sayıda 1 (tekli çift sayılar).** $\Sigma = \{1\}$, $q_0$ (başlangıç ve kabul) ile $q_1$ arasında 1 ile gidip gelinir (ekrandan, 00:40:00). Dil $EVEN = \{x : x \in \Sigma^* \text{ ve } x \text{ çift}\} = \{\varepsilon, 11, 1111, \dots\}$; boş dizgi bu tanımda çifttir.

- **"001 alt dizgisini içeren ikili dizgiler" DFA'sı** (ekrandan, 01:15:00). Durumlar o ana kadar görülen ilgili öneki temsil eder:

  | Durum | 0 | 1 |
  |---|---|---|
  | $\lambda$ (başlangıç) | $0$ | $\lambda$ |
  | $0$ | $00$ | $\lambda$ |
  | $00$ | $00$ | $001$ |
  | $001$ (kabul) | $001$ | $001$ |

  Kabul ve kabul olmayan durumlar yer değiştirince "001 içermeyen ikili dizgiler" dili, yani tümleyen elde edilir.

- **$\{awa : w \in \{a,b\}^*\}$ DFA'sı** (ekrandan, 01:20:00). $q_0 \xrightarrow{a} q_2$, $q_0 \xrightarrow{b} q_1$ (tuzak, $a,b$ ile kendine), $q_2$'de $b$ ile kendine, $q_2 \xrightarrow{a} q_3$ (kabul), $q_3$'te $a$ ile kendine, $q_3 \xrightarrow{b} q_2$. Böylece $a$ ile başlayıp $a$ ile biten, en az iki $a$ içeren dizgiler kabul edilir; en kısa örnek $aa$'dır.

- **NFA örnekleri.**
  - $\Sigma = \{a\}$; $q_0 \xrightarrow{a} q_1 \xrightarrow{a} q_2$ (kabul) ve $q_0 \xrightarrow{a} q_3$ (ekrandan, 01:30:00). $aa$ üst yolda kabul edilir, alt yol $q_3$'te girdiyi tüketemeyip durur. $a$ ve $aaa$ reddedilir. Dil $\{aa\}$.
  - $q_0 \xrightarrow{a} q_1 \xrightarrow{\varepsilon} q_2 \xrightarrow{a} q_3$ (kabul) (ekrandan, 01:40:00): dil yine $\{aa\}$.
  - $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$ (kabul), $q_2 \xrightarrow{\varepsilon} q_3 \xrightarrow{\varepsilon} q_0$ (ekrandan, 01:45:00): $ab$ okununca $q_2, q_3, q_0$ aynı anda etkindir. Dil $\{ab\}\{ab\}^*$, yani en az bir $ab$.
  - $q_0$ (başlangıç ve kabul) $\xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$, $q_1 \xrightarrow{0,1} q_2$, $q_0 \xrightarrow{\varepsilon} q_2$ (ekrandan, 02:15:00): $q_2$'den çıkış olmadığı için ölü dal gibidir. Dil $\{10\}^*$ (python ile doğrulandı).
  - $F = \{q_0, q_5\}$ olan örnek (ekrandan, 02:35:00): $\delta^*(q_0, aa) = \{q_4, q_5\}$, $\delta^*(q_0, ab) = \{q_2, q_3, q_0\}$, $\delta^*(q_0, aba) = \{q_1\}$. $aa$, $ab$, $abaa$ dilde; $aba$ dilde değil. Dil $\{ab\}^* \cup \{ab\}^*\{aa\}$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
