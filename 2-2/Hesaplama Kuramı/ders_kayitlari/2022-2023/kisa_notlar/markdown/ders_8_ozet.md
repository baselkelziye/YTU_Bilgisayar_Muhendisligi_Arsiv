# Ders 8 Çalışma Özeti

## Genel Konular

- Yığıtlı otomatların (pushdown automata, PDA) tekrarı
  - PDA, sonlu otomata ek olarak bir yığıt (stack) kullanır. Yığıtın en altında başlangıçta özel bir sembol ($\$$) bulunur; bu sembol yığıtın sonuna gelindiğini gösterir.
  - Bir geçiş $a, b \to c$ biçiminde yazılır: girdiden $a$ okunur, yığıtın tepesinden $b$ çıkarılır (pop), yerine $c$ konur (push). Pop ya da push yapılmayacaksa o yere $\varepsilon$ yazılır; $\varepsilon, \varepsilon \to \varepsilon$ yığıta hiç dokunmaz.
  - PDA'lar deterministik değildir: aynı girdi ve yığıt tepesi için birden fazla duruma aynı anda geçilebilir ve $\varepsilon$-geçişlerine (girdi okumadan geçiş) izin verilir (ekrandan, 00:15:00).
  - Kabul koşulu: girdinin tamamı okunmuş olmalı ve otomat bir kabul durumunda olmalıdır. Yığıtın o anki içeriği önemli değildir.
- $L = \{v v^R : v \in \{a,b\}^*\}$ dilini kabul eden PDA (ekrandan, 00:20:00)
  - $q_0$ üzerindeki döngü ($a, \varepsilon \to a$; $b, \varepsilon \to b$) ilk yarıyı okuyup yığıta iter; yığıt sırayı tersine çevirir.
  - $q_0 \to q_1$ geçişi $\varepsilon, \varepsilon \to \varepsilon$; $q_1$ üzerindeki döngü ($a, a \to \varepsilon$; $b, b \to \varepsilon$) ikinci yarıyı yığıttakilerle eşler.
  - Yığıtta yalnız $\$$ kalınca $\varepsilon, \$ \to \$$ ile kabul durumu $q_2$'ye geçilir.
- Geçişlerde dizgi itme ve çekme
  - Bir geçişte tek sembol yerine dizgi çekilip itilebilir; örneğin $e b$ çekilip $c d f$ itilmesi. Bu bir kısaltmadır: arka planda semboller tek tek çekilir ve itilir (önce $f$, sonra $d$, en son $c$ itilir; böylece $c$ tepede olur).
- $L = \{w \in \{a,b\}^* : n_a(w) = n_b(w)\}$ dilini kabul eden PDA (ekrandan, 00:25:00)
  - Tek döngüsü olan $q_1$ ve kabul durumu $q_2$ vardır. Yığıtta $0$ bir $a$'yı, $1$ bir $b$'yi temsil eder; yani yığıta okunan sembolün kendisini itmek gerekmez.
  - Geçişler: $a, \$ \to 0\$$; $a, 0 \to 00$; $a, 1 \to \varepsilon$; $b, \$ \to 1\$$; $b, 1 \to 11$; $b, 0 \to \varepsilon$; ayrıca $q_1 \to q_2$: $\varepsilon, \$ \to \$$.
  - Fazla olan sembol yığıtta birikir; karşı sembol gelince bir tanesi silinerek eşleşir.
- PDA'nın biçimsel tanımı (ekrandan, 00:35:00)
  - $M = (Q, \Sigma, \Gamma, \delta, q_0, z, F)$: durumlar, girdi alfabesi, yığıt alfabesi, geçiş fonksiyonu, başlangıç durumu, yığıt başlangıç sembolü, kabul durumları.
  - Geçiş fonksiyonu: $\delta(q_1, a, w_1) = \{(q_2, w_2), (q_3, w_3)\}$. Sonuç bir kümedir, çünkü PDA deterministik değildir (NFA'daki gibi).
- Anlık tanım (instantaneous description)
  - Bir anı üçlü olarak gösterir: (o anki durum, kalan girdi, yığıt içeriği). Örneğin $(q_1, bbb, aaa\$)$.
  - Bir adım $\succ$ ile, sıfır ya da daha çok adım $\overset{*}{\succ}$ ile yazılır.
- PDA'nın dili
  - $L(M) = \{w : (q_0, w, z) \overset{*}{\succ} (q_f, \varepsilon, s),\ q_f \in F\}$. Yığıtta kalan $s$ önemli değildir.
  - Örnek PDA (ekrandan, 00:45:00) için $(q_0, a^n b^n, \$) \overset{*}{\succ} (q_3, \varepsilon, \$)$ olduğundan $L(M) = \{a^n b^n : n \ge 0\}$.
- Teorem: PDA'ların kabul ettiği diller ile bağlamdan bağımsız gramerlerin ürettiği diller aynı kümedir
  - İki kümenin eşitliği iki yönde ispatlanır: birinci küme ikincinin alt kümesidir ve üst kümesidir. İspat yapıcıdır (by construction).
- Adım 1: Bağlamdan bağımsız gramerden PDA'ya dönüşüm (ekrandan, 01:00:00)
  - Geçiş grafiği her zaman aynıdır: $q_0 \xrightarrow{\varepsilon, \varepsilon \to S} q_1 \xrightarrow{\varepsilon, \$ \to \$} q_2$, $q_2$ kabul durumu.
  - Gramerdeki her $A \to w$ kuralı için $q_1$ döngüsüne $\varepsilon, A \to w$ eklenir.
  - Gramerdeki her uç sembol (terminal) $a$ için $q_1$ döngüsüne $a, a \to \varepsilon$ eklenir.
  - Bu PDA, gramerin en soldan türetmelerini (leftmost derivation) taklit eder.
- Adım 2: PDA'dan bağlamdan bağımsız gramere dönüşüm
  - Önce PDA dört adımda değiştirilir: tek kabul durumu; yeni yığıt başlangıç sembolü $\#$; kabulde yığıtta yalnız $\#$ kalması; her geçişin ya yalnız push ya da yalnız pop yapması. Sonuç $M_4$'tür ve $\#$ hiçbir geçişte kullanılmaz (ekrandan, 01:45:00).
  - Sonra her durum çifti $(p, q)$ için $A_{pq}$ değişkeni tanımlanır ve üç tür kural eklenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- PDA'da kabul için yalnız iki şeye bakılır
  - Girdi tamamen tüketilmiş mi ve otomat kabul durumunda mı? Yığıtın boş olup olmadığı önemli değildir.
- PDA'nın deterministik olmayışı
  - Hem bir geçiş kuralının birden fazla sonucu olabilmesi hem de $\varepsilon$-geçişleri PDA'yı deterministik olmayan yapar. Bu yüzden geçiş fonksiyonunun sonucu bir kümedir.
- Yığıta okunan sembolü itmek zorunlu değildir
  - $n_a = n_b$ örneğinde $a$ için $0$, $b$ için $1$ itildi. Yığıta ne konacağı tasarımcıya kalmıştır.
- Biçimsel tanımı ezberlemek gerekmez
  - Ama PDA kullanan bir program yazılırsa bu yedi bileşenin programın başında tanımlanması gerekir.
- Gramerden PDA'ya dönüşümde grafik hep aynıdır
  - Değişen yalnız $q_1$ üzerindeki döngüye eklenen geçişlerdir. Gramer kuralı ile geçiş birebir karşılık gelir: $A \to w$ kuralı $\varepsilon, A \to w$ geçişi olur.
- PDA'dan gramere dönüşüm uzun ama mekanik bir işlemdir
  - Büyük bir otomatta çok sayıda kural çıkar; $\varepsilon$ girdili geçişler de hesaba katılmalıdır.

## Kısa Tekrar Notları

- Geçiş $a, b \to c$: $a$ oku, $b$ çek, $c$ it. $\varepsilon$ "hiçbir şey" demektir.
- Kabul: girdi bitti ve kabul durumundayız; yığıt önemli değil.
- Dizgi itmede en sağdaki sembol önce itilir, en soldaki tepede kalır.
- $M = (Q, \Sigma, \Gamma, \delta, q_0, z, F)$; $\delta(q, a, w) \subseteq Q \times \Gamma^*$ biçiminde bir kümedir.
- Anlık tanım: (durum, kalan girdi, yığıt). $\succ$ bir adım, $\overset{*}{\succ}$ çok adım.
- $L(M) = \{w : (q_0, w, z) \overset{*}{\succ} (q_f, \varepsilon, s)\}$.
- CFG → PDA: $q_0 \xrightarrow{\varepsilon,\varepsilon\to S} q_1 \xrightarrow{\varepsilon,\$\to\$} q_2$; $q_1$ döngüsüne her kural için $\varepsilon, A \to w$, her uç sembol için $a, a \to \varepsilon$.
- CFG → PDA dönüşümü en soldan türetmeyi taklit eder: okunan girdi + yığıt içeriği (\$ hariç) = türetmenin o anki cümle biçimi.
- PDA → CFG ön hazırlığı: (1) tek kabul durumu, (2) yeni taban sembolü $\#$ ve yardımcı $@$, (3) kabulde yığıtta yalnız $\#$, (4) her geçiş ya push ya pop.
- PDA → CFG kuralları: $A_{qq} \to \varepsilon$; $A_{pq} \to A_{pr} A_{rq}$; aynı sembolü iten ve çeken geçiş çiftleri için $A_{pq} \to a A_{rs} b$; başlangıç değişkeni $A_{q_0 q_f}$.
- Sonuç: PDA'lar ile bağlamdan bağımsız gramerler aynı dil sınıfını tanımlar.

## Detaylı Açıklamalar

- **PDA'nın çalışması ve kabul.** PDA, NFA'ya bir yığıt eklenmiş hâli gibi düşünülebilir. Her geçişte girdiden bir sembol (ya da hiçbir şey) okunur ve yığıtın tepesine bakılır. Geçişin gerçekleşmesi için hem doğru girdi sembolü okunmalı hem de yığıtın tepesinde beklenen sembol bulunmalıdır. $v v^R$ örneğinde ilk döngü okuduğu her sembolü yığıta iter; yığıt son giren ilk çıkar (LIFO) çalıştığı için ikinci yarı okunurken yığıttan çıkan semboller ilk yarının tersidir. İkinci döngü, okunan sembolle yığıtın tepesindeki aynıysa onu çeker. Sonunda yığıtta yalnız $\$$ kalmışsa girdinin ikinci yarısı ilk yarının tersiyle eşleşmiş demektir ve kabul edilir. Örneğin ikinci yarıda $a$ gelmesi gereken yerde $b$ gelirse geçiş yapılamaz ve dizgi reddedilir.
- **$n_a(w) = n_b(w)$ örneğinin izlenmesi.** Slayttaki girdi $abbbaa$'dır (ekrandan, 00:30:00). Başlangıçta yığıtta $\$$ vardır ve $\varepsilon, \$ \to \$$ geçişi sayesinde hiçbir şey okunmadan $q_2$ de etkindir; bu yüzden boş dizgi kabul edilir. Sonra: $a$ okunur, tepe $\$$ olduğu için $0\$$ itilir; $b$ okunur, tepe $0$ olduğu için $0$ silinir (bir $a$ bir $b$ ile eşleşti); $b$ okunur, tepe $\$$ olduğu için $1\$$ itilir; $b$ okunur, tepe $1$ olduğu için $11$ itilir, yığıt $11\$$ olur; iki $a$ okunur, her biri bir $1$ siler. Girdi bitince yığıtta yalnız $\$$ kalır, $\varepsilon$-geçişiyle $q_2$'ye geçilir ve dizgi kabul edilir. Üç $b$ okunduğu hâlde yığıtta iki $1$ bulunması, ilk $b$'nin ilk $a$ ile eşleşmiş olmasındandır.
- **Anlık tanım ve hesaplama.** Her adım için resim çizmek yerine (durum, kalan girdi, yığıt) üçlüsü yazılır. $a^n b^n$ PDA'sında (ekrandan, 00:40:00) $aaabbb$ için hesaplama şöyledir: $(q_0, aaabbb, \$) \succ (q_1, aaabbb, \$) \succ (q_1, aabbb, a\$) \succ (q_1, abbb, aa\$) \succ (q_1, bbb, aaa\$) \succ (q_2, bb, aa\$) \succ (q_2, b, a\$) \succ (q_2, \varepsilon, \$) \succ (q_3, \varepsilon, \$)$. Bu dizi makinenin bir dalının nasıl çalıştığını gösterir. Yalnız başlangıç ve bitiş önemliyse $(q_0, aaabbb, \$) \overset{*}{\succ} (q_3, \varepsilon, \$)$ yazılır.
- **Gramerden PDA'ya dönüşüm örneği.** Gramer $S \to aSTb \mid b$, $T \to Ta \mid \varepsilon$ (ekrandan, 01:05:00). PDA'nın $q_1$ döngüsünde $\varepsilon, S \to aSTb$; $\varepsilon, S \to b$; $\varepsilon, T \to Ta$; $\varepsilon, T \to \varepsilon$; $a, a \to \varepsilon$; $b, b \to \varepsilon$ geçişleri bulunur. Girdi $abab$ için: başta $S$ itilir ve $q_1$'e geçilir. Yığıt tepesinde $S$ varken iki kural da uygulanır ve makine iki kopyaya ayrılır: biri yığıtı $aSTb\$$, öteki $b\$$ yapar. İlk okunacak sembol $a$ olduğu için tepesinde $b$ olan kopya ölür (ekrandan, 01:25:00). $a$ okunup çekilir; tepe yine $S$ olur, bu kez $S \to b$ seçilen kopya yaşar ve $b$ okunup çekilir. Tepe $T$ iken $T \to Ta$ seçilir, $a$ okunup çekilir; ardından $T \to \varepsilon$ ile $T$ silinir ve son $b$ okunup çekilir. Yığıtta yalnız $\$$ kalınca $q_2$'ye geçilip kabul edilir. Bu adımlar en soldan türetme $S \Rightarrow aSTb \Rightarrow abTb \Rightarrow abTab \Rightarrow abab$'a karşılık gelir (ekrandan, 01:30:00).
- **Neden en soldan türetme?** Herhangi bir anda, PDA'nın o ana kadar okuduğu girdi kısmı ile yığıt içeriği ($\$$ hariç) yan yana yazılınca türetmenin o adımdaki cümle biçimi elde edilir (ekrandan, 01:10:00). Değişken kuralı uygulanınca türetmede $xAy \Rightarrow x\sigma_i \cdots \sigma_j B z y$ olur; PDA'da yığıt $Ay\$$ iken $A$ çekilip $\sigma_i \cdots \sigma_j B z$ itilir. Ardından yığıtın tepesindeki uç semboller girdiyle tek tek eşleşip çekilir ($\sigma_i, \sigma_i \to \varepsilon$); gramer bu adımlarda bir şey yapmaz (ekrandan, 01:15:00). Tepeye yeniden bir değişken ($B$) gelince bir sonraki değişken kuralı uygulanır. Böylece $G$'nin $w$'yi üretmesi ile PDA'nın $w$'yi kabul etmesi denk olur: $L(G) = L(M)$.
- **PDA'nın değiştirilmesi.** (1) Birden çok kabul durumu varsa hepsi sıradan duruma çevrilir ve her birinden yeni bir $q_f$'ye $\varepsilon$-geçişi konur ($M_1$). (2) Başa iki yeni durum eklenir: ilki yardımcı sembol $@$'yi, ikincisi eski taban sembolü $Z$'yi iter; yığıt tepeden aşağı $Z, @, \#$ olur. $M_1$ hâlâ $Z$'yi taban sanır ve $Z$'nin altına inmez (ekrandan, 01:40:00) ($M_2$). (3) Eski kabul durumundan yeni bir duruma $\varepsilon$-geçişi konur; bu durumdaki döngü $@$ ve $\#$ dışındaki her $x$ yığıt sembolünü çeker ($\varepsilon, x \to \varepsilon$); son olarak $\varepsilon, @ \to \varepsilon$ ile yeni kabul durumuna geçilir; yığıtta yalnız $\#$ kalır ($M_3$). (4) Hem çeken hem iten bir geçiş, araya yeni bir durum konarak önce çeken sonra iten iki geçişe bölünür. Ne çeken ne iten bir geçiş de araya yeni durum konarak, önce yığıt alfabesinden bir sembolü iten, sonra aynı sembolü çeken iki geçişe bölünür ($M_4$).
- **Gramer kuralları.** $M_4$'ün her durum çifti $p, q$ için $A_{pq}$ değişkeni vardır. Birinci tür: her durum $q$ için $A_{qq} \to \varepsilon$. İkinci tür: her üç durum $p, q, r$ için $A_{pq} \to A_{pr} A_{rq}$; $p$'den $q$'ya $r$ üzerinden gitmek gibi düşünülebilir ve $r = p$ ya da $r = q$ durumları da eklenir, bu yüzden büyük bir otomatta çok sayıda kural çıkar. Üçüncü tür: $p \xrightarrow{a, \varepsilon \to t} r$ ve $s \xrightarrow{b, t \to \varepsilon} q$ gibi aynı $t$ sembolünü iten ve çeken her geçiş çifti için $A_{pq} \to a A_{rs} b$ (ekrandan, 01:50:00). Başlangıç değişkeni $A_{q_0 q_f}$'dir. Örnek $M_4$ için üçüncü tür kurallar: $A_{q_0q_5} \to A_{q_1q_4}$, $A_{q_1q_4} \to A_{q_2q_4}$, $A_{q_2q_4} \to aA_{q_2q_4}$, $A_{q_2q_2} \to aA_{q_2q_2}b$, $A_{q_2q_4} \to aA_{q_2q_3}$, $A_{q_2q_2} \to A_{q_3q_2}b$, $A_{q_2q_4} \to A_{q_3q_3}$, $A_{q_2q_4} \to A_{q_3q_4}$ (ekrandan, 01:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
