# Ders 10 Çalışma Özeti

## Genel Konular

- Ders ağırlıkla İngilizce anlatıldı, bazı açıklamalar Türkçe tekrar edildi. Anlatım tablette slayt ve el yazısıyla yürüdü.
  - Kayıt üç bölümden oluşur: yaklaşık 00:05:30-00:47:30, 01:01:50-01:48:45 ve 02:04:00-02:52:35. Aralarda ders arası verildi.
- Yığıtlı otomatların (PDA) hatırlatılması
  - PDA, NFA'ya bir yığıt (stack) eklenmiş hâlidir. Geçişler hem girdi sembolüne hem de yığıtın tepesindeki değere bağlıdır.
  - Geçiş etiketi $a, w_1 \to w_2$: girdi $a$ okunurken yığıttan $w_1$ çıkarılır (pop), yerine $w_2$ konur (push) (ekrandan, 00:10:00).
  - Geçiş fonksiyonu bir küme döndürür: $\delta(q_1,a,w_1)=\{(q_2,w_2)\}$. PDA'lar deterministik değildir; aynı $(q_1,a,w_1)$ için birden çok $(q_i,w_i)$ çifti olabilir ve bu dallar aynı anda çalışır.
- PDA'nın biçimsel tanımı (ekrandan, 00:15:00)
  - $M=(Q,\Sigma,\Gamma,\delta,q_0,z,F)$: durumlar, girdi alfabesi, yığıt alfabesi, geçiş fonksiyonu, başlangıç durumu, yığıt başlangıç sembolü (genelde $\$$), kabul durumları.
- Anlık betimlemeler (instantaneous descriptions) ve hesaplama
  - Bir anlık betimleme $(q, \text{kalan girdi}, \text{yığıt içeriği})$ üçlüsüdür; bir adım $\succ$ ile, çok adım $\succ^*$ ile gösterilir.
  - $a^nb^n$ PDA'sında $aaabbb$ için hesaplama: $(q_0,aaabbb,\$)\succ(q_1,aaabbb,\$)\succ(q_1,aabbb,a\$)\succ\dots\succ(q_2,\varepsilon,\$)\succ(q_3,\varepsilon,\$)$ (ekrandan, 00:20:00).
  - PDA'nın dili: $L(M)=\{w : (q_0,w,z)\succ^*(q_f,\varepsilon,s),\ q_f\in F\}$. Örnekte $L(M)=\{a^nb^n : n\ge 0\}$ (ekrandan, 00:25:00).
- Örnek: $L=\{a^{2n+1}b^{3n} : n\ge 0\}$ için gramer ve PDA (ekrandan, 00:30:00 ve 00:35:00)
  - PDA fikri: ilk $a$ ayrı okunur; sonraki her $a$ için yığıta $xxx$, her $b$ için yığıttan $xx$ çıkarılır. Böylece $2n\cdot 3 = 3n\cdot 2$ eşitliği sağlanır.
  - $n=0$ ($w=a$) için $q_1$ de kabul durumu yapılmalıdır.
- $a^nb^{2n}a^{3n}$ bağlamdan bağımsız değildir; PDA'sı yoktur, daha güçlü bir makine (Turing makinesi) gerekir (ekrandan, 00:40:00).
- Sonlu bir dil için PDA: önce NFA çizilir, sonra her geçişe yığıta dokunmayan bir etiket eklenerek PDA'ya çevrilir (ekrandan, 00:45:00).
  - Düzenli diller kümesi, bağlamdan bağımsız diller kümesinin alt kümesidir.
- Bağlamdan bağımsız gramerden (CFG) PDA'ya doğrudan çevirme
  - Genel kalıp: $q_0 \xrightarrow{\varepsilon,\varepsilon\to S\$} q_1 \xrightarrow{\varepsilon,\$\to\varepsilon} q_2$ (kabul). $q_1$ üzerinde döngüler: her kural $A\to u$ için $\varepsilon, A\to u$; her terminal $a$ için $a, a\to\varepsilon$ (ekrandan, 01:05:00 ve 01:10:00).
  - Örnekler: $B\to aBb\mid\varepsilon$; $T\to 11T0\mid W,\ W\to 0W\mid\varepsilon$; $L=\{a^n : n>2\}$ için $S\to aaaA,\ A\to aA\mid\varepsilon$ (ekrandan, 01:20:00).
  - Aynı dilin birden çok PDA'sı olabilir (NFA'dan çevrilen ve gramerden kurulan).
- Bağlamdan bağımsız dillerin kapanış özellikleri
  - Birleştirme (concatenation): $\{a^nb^n\}\cdot\{a^kb^k\}$ bağlamdan bağımsızdır; gramer $S\to TZ$, $T\to aTb\mid\varepsilon$, $Z\to aZb\mid\varepsilon$ (ekrandan, 01:25:00 ve 01:30:00). PDA olarak birinci PDA'nın kabul durumu ikincinin başlangıcına $\varepsilon,\varepsilon\to\varepsilon$ ile bağlanır (ekrandan, 01:35:00).
  - Birleşim (union): $L_1=\{a^nb^n\}$, $L_2=\{a^{2m}b^{3m}\}$ için $L_1\cup L_2$ bağlamdan bağımsızdır; $S\to S_1\mid S_2$ kalıbıyla gramer kurulur (ekrandan, 01:40:00).
  - Kleene yıldızı: $L_1^*=\{a^nb^n\}^*$ bağlamdan bağımsızdır. Klasik PDA'da son durumdan başlangıca $\varepsilon$ geri besleme eklenir ve $q_0$ da kabul durumu yapılır (ekrandan, 02:05:00 ve 02:10:00).
  - Kesişim: kapalı değildir. $L_1=\{a^nb^nc^m\}$ ve $L_2=\{a^mb^nc^n\}$ bağlamdan bağımsızdır ama $L_1\cap L_2=\{a^nb^nc^n\}$ değildir (ekrandan, 02:15:00).
  - Tümleme: kapalı değildir; bir bağlamdan bağımsız dilin tümleyeni bağlamdan bağımsız olmak zorunda değildir.
- Geçen yılın ödev sorularından örnekler (ekrandan, 02:30:00-02:50:00): ilk, orta ve son karakteri aynı olan dizgiler için gramer ve PDA; verilen bir gramerin en kısa dört dizgisi ve belirsizliği (ambiguity); $a^nc^mb^n$ için gramer.

## Hocanın Özellikle Vurguladığı Kısımlar

- PDA'nın NFA/DFA'dan tek farkı ekstra yığıttır; geçişler yığıt içeriğine de bağlıdır.
  - Bu yüzden sayma gerektiren ($a^nb^n$ gibi) ama tek bir eşleştirme içeren diller PDA ile tanınabilir.
- Tanımdaki $\ge 0$ koşuluna dikkat edilmelidir.
  - $n\ge 0$ ise boş dizgi (ya da en kısa eleman) dile girer; gramerde $\varepsilon$ kuralı, PDA'da da başlangıç ya da ara durumun kabul durumu olması gerekir. Hoca bunu hem $a^{2n+1}b^{3n}$ hem de $a^nb^n$ PDA'larında ayrıca gösterdi.
- Desendeki bağımlılık sayısına bakarak sınıflandırma
  - $a$ ile $b$'nin sayıları bağımsızsa dil düzenlidir; tek bir eşleşme varsa bağlamdan bağımsızdır; birden fazla eşleşme ($a^nb^nc^n$ gibi) varsa bağlamdan bağımsız değildir.
- Birleştirme ve birleşim kapanış sonuçlarını hoca "çok önemli" diye işaretledi; kesişim örneğini ($a^nb^nc^n$) de ayrıca vurguladı.

## Kısa Tekrar Notları

- PDA 7'li: $(Q,\Sigma,\Gamma,\delta,q_0,z,F)$.
- Geçiş $a, w_1\to w_2$: $a$ oku, $w_1$ çıkar, $w_2$ koy.
- PDA deterministik değildir; dallar paralel çalışır.
- $a^nb^n$ PDA'sı: $a$'larda $a$ koy, $b$'lerde $a$ çıkar, sonunda $\$$ görünce kabul et.
- $a^{2n+1}b^{3n}$: doğru gramer $S\to aaSbbb\mid a$; PDA: ilk $a$, sonra her $a$ için $xxx$ koy, her $b$ için $xx$ çıkar.
- Sonlu dil düzenlidir, düzenli dil bağlamdan bağımsızdır.
- CFG'den PDA: $\varepsilon,\varepsilon\to S\$$; döngüde $\varepsilon,A\to u$ ve $a,a\to\varepsilon$; çıkışta $\varepsilon,\$\to\varepsilon$.
- Bağlamdan bağımsız diller birleşim, birleştirme ve Kleene yıldızı altında kapalıdır; kesişim ve tümleme altında kapalı değildir.
- $a^nb^nc^n$ bağlamdan bağımsız değildir.

## Detaylı Açıklamalar

Yığıtlı otomat, durumlar arasındaki geçişin yalnız okunan sembole değil, yığıtın tepesindeki içeriğe de bağlı olduğu bir makinedir. Ekrandaki $q_1 \xrightarrow{a, w_1\to w_2} q_2$ geçişi, girdi $a$ iken ve yığıtın tepesinde $w_1$ varken geçerlidir: $w_1$ çıkarılır, $w_2$ konur. Bu, geçiş fonksiyonuyla $\delta(q_1,a,w_1)=\{(q_2,w_2)\}$ diye yazılır. Sonucun bir küme olması PDA'nın deterministik olmayışından gelir: aynı durum, girdi ve yığıt içeriği için makine birden çok duruma birden gidebilir. Hoca bunu iki dallı bir örnekle anlattı: $q_1$'den $a$ okununca hem $q_2$'ye (yığıtta $w_1$ yerine $w_2$) hem $q_3$'e (yığıtta $w_1$ yerine $w_3$) gidilir ve iki dal aynı anda sürer.

PDA'nın dili, başlangıç durumundan başlayıp girdiyi tamamen tüketerek bir kabul durumuna varılabilen dizgilerden oluşur. $a^nb^n$ makinesinde $q_0\to q_1$ geçişi $\varepsilon,\varepsilon\to\varepsilon$, $q_1$ döngüsü $a,\varepsilon\to a$, $q_1\to q_2$ ve $q_2$ döngüsü $b,a\to\varepsilon$, $q_2\to q_3$ geçişi ise $\varepsilon,\$\to\$$'dır (ekrandan, 00:20:00). Son geçiş yığıtta yalnız $\$$ kaldığını, yani bütün $a$'ların $b$'lerle eşleştiğini denetler. $q_0$ da kabul durumudur, çünkü $n=0$ için boş dizgi dildedir.

$L=\{a^{2n+1}b^{3n}\}$ örneğinde hoca önce gramer istedi ve tabletteki gramer üzerinde sınıfla tartıştı. Ekrana yazılan gramerler ($S\to aS\mid aaAbbb$, $A\to aaAbb\mid\varepsilon$ ve düzeltilmiş hâli $S\to aS\mid aaAbbb\mid\varepsilon$, $A\to aaAbbb\mid\varepsilon$) dili tam üretmez. Ders sonrası not: $S\to aS$ kuralı $a$ sayısını serbest bırakır ve $S\to\varepsilon$ boş dizgiyi üretir; ikisi de dilde değildir. Doğru gramer $S\to aaSbbb\mid a$'dır (python ile $|w|\le 12$ için denetlendi). PDA kısmında ise fikir doğrudur: ilk $a$ okununca $q_1$'e geçilir, $q_1$'de her $a$ için yığıta $xxx$ konur, her $b$ için yığıttan $xx$ çıkarılır, yığıtta $\$$ kalınca kabul edilir. $2n$ tane $a$ $6n$ tane $x$ koyar, $3n$ tane $b$ de $6n$ tane $x$ çıkarır. Hoca sonradan $n=0$ durumu ($w=a$) için $q_1$'i de kabul durumu yaptı; bu PDA python ile $|w|\le 12$ için denetlendi.

Gramerden PDA kurmanın genel yolu şöyledir: başlangıçta yığıta $S\$$ konur, ortadaki durumda her kural için "değişkeni çıkar, sağ tarafı koy" döngüsü, her terminal için "terminali oku ve yığıttan çıkar" döngüsü bulunur, en sonda $\$$ çıkarılıp kabul durumuna geçilir. $L=\{a^n : n>2\}$ örneğinde aynı dil için iki ayrı PDA gösterildi: NFA'dan çevrilen ($a,\varepsilon\to\varepsilon$ etiketli zincir ve döngü) ve $S\to aaaA$, $A\to aA\mid\varepsilon$ grameriyle kurulan (ekrandan, 01:20:00).

Kapanış özelliklerinde birleştirme için PDA'lar art arda bağlanır, birleşim için yeni başlangıç değişkeni iki gramere dallanır, Kleene yıldızı için PDA'nın sonundan başına geri besleme eklenir. Kesişimde ise karşı örnek vardır: $\{a^nb^nc^m\}$ ve $\{a^mb^nc^n\}$ bağlamdan bağımsızken kesişimleri $\{a^nb^nc^n\}$ değildir. Tümleme için hoca derste kesin bir karşı örnek vermedi.

<!-- BELİRSİZ: 01:04:59-01:08:58 arasındaki ilk gramer örneğinin ("S -> AB ...") kuralları altyazıda ve karelerde okunamıyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
