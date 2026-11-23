# Ders 10 Çalışma Özeti

## Genel Konular

- Bağlamdan bağımsız gramerler ile yığıtlı otomatların denkliği (tekrar)
  - Teorem: bağlamdan bağımsız gramerlerin ürettiği dillerin kümesi, yığıtlı otomatların (pushdown automata, PDA) kabul ettiği dillerin kümesine eşittir.
  - İki kümenin eşitliği iki yönlü ispatlanır: önce birinci kümenin ikincinin alt kümesi olduğu, sonra ikincinin birincinin alt kümesi olduğu gösterilir.
  - İspat yapıcı ispattır (proof by construction): her yön için dönüşümün adım adım nasıl yapılacağı gösterilir.
- Gramerden yığıtlı otomata dönüşüm (ekrandan, 00:15:00)
  - Üç durumlu bir PDA kurulur: $q_0$ başlangıç, $q_1$ orta durum, $q_2$ kabul durumu. Yığında başlangıçta yığın dibi sembolü $\$$ vardır.
  - $q_0 \to q_1$: $\varepsilon, \varepsilon \to S$ (girdiden bir şey okumadan başlangıç değişkeni $S$ yığına konur).
  - $q_1 \to q_2$: $\varepsilon, \$ \to \$$ (girdi bitmiş ve yığında yalnız $\$$ kalmışsa kabul durumuna geçilir).
  - $q_1$ üzerindeki döngü geçişleri: gramerdeki her $A \to w$ üretimi için $\varepsilon, A \to w$; her uç sembol $a$ için $a, a \to \varepsilon$.
  - PDA, gramerin en soldan türetmesini (leftmost derivation) taklit eder. PDA belirlenimci değildir; bir değişkenin birden çok kuralı varsa otomat paralel kopyalara ayrılır, uygun geçişi olmayan kopya ölür.
- Örnek: $S \to aSTb \mid b$, $T \to Ta \mid \varepsilon$ gramerinde $abab$ girdisi (ekrandan, 00:20:00 ve 00:25:00)
  - Türetme: $S \Rightarrow aSTb \Rightarrow abTb \Rightarrow abTab \Rightarrow abab$.
  - PDA 10 adımda girdiyi okur, yığın $\$$'a iner ve $\varepsilon, \$ \to \$$ ile $q_2$'de kabul eder.
  - Sonuç: her gramer bir PDA'ya çevrilebildiği için gramer dilleri PDA dillerinin alt kümesidir.
- Yığıtlı otomattan gramere dönüşüm
  - Sistematik ama karmaşık bir süreçtir; PDA önce birkaç adımda normal biçime getirilir, sonra gramer kuralları üretilir.
  - Adım 1: tek bir kabul durumu kalır. Birden çok kabul durumu varsa bunlar kabul olmayan duruma çevrilir ve hepsinden yeni tek kabul durumuna boş geçiş yapılır.
  - Adım 2: yeni yığın sembolleri eklenir (ekrandan, 00:30:00). Yeni başlangıç yığın sembolü $\#$, yardımcı yığın sembolü $@$, $M$'nin eski başlangıç yığın sembolü $Z$. Başta $\varepsilon, \varepsilon \to @$ ve $\varepsilon, \varepsilon \to Z$ geçişleri eklenir; eski otomat $Z$'yi hâlâ başlangıç sembolü sanır.
  - Kabulde yığında yalnız $\#$ kalması sağlanır: eski kabul durumu kabul olmayan durum olur, bir ara durumda $@$ ve $\#$ dışındaki her sembol $\varepsilon, x \to \varepsilon$ ile boşaltılır, sonra $\varepsilon, @ \to \varepsilon$ ile yeni kabul durumuna geçilir.
  - Adım 3: her geçiş ya yığına tam bir sembol ekler ya da yığından tam bir sembol çıkarır. Hem çıkaran hem ekleyen geçiş ikiye bölünür; yığına dokunmayan geçişte rastgele bir sembol eklenip hemen çıkarılır.
- PDA'dan gramer kuralları (değişkenler $A_{pq}$, $p$ ve $q$ PDA durumları)
  - Tür 1: her durum $q$ için $A_{qq} \to \varepsilon$.
  - Tür 2: her üç durum $p, q, r$ için $A_{pq} \to A_{pr} A_{rq}$ (ekrandan, 00:35:00).
  - Tür 3: $p$'den $r$'ye $a, \varepsilon \to t$ geçişi ve $s$'den $q$'ya $b, t \to \varepsilon$ geçişi varsa (aynı $t$ birinde eklenip ötekinde çıkarılıyorsa) $A_{pq} \to a A_{rs} b$.
  - Başlangıç değişkeni $A_{q_0 q_f}$ olur ($q_0$ başlangıç, $q_f$ tek kabul durumu).
  - Mekanik bir yöntem olduğu için çok sayıda değişken çıkar; elle yapmak zor, bir makine için kolaydır.
- Bağlamdan bağımsız diller için pompalama önsavı
  - Sonsuz bir bağlamdan bağımsız dil sonsuz sayıda farklı dizgi üretir. Örnek gramer (ekrandan, 01:00:00): $S \to ABE \mid bBd$, $A \to Aa \mid a$, $B \to bSD \mid cc$, $D \to Dd \mid d$, $E \to eE \mid e$.
  - $aabbccddee$ dizgisinin türetme ağacında $B$ değişkeni bir yol üzerinde iki kez görünür (ekrandan, 01:05:00). Ağaç üç parçaya ayrılır: $S \overset{*}{\Rightarrow} aaBee$, $B \overset{*}{\Rightarrow} bbBdd$, $B \Rightarrow cc$.
  - Ortadaki parça çıkarılırsa $aa(bb)^0cc(dd)^0ee = aaccee \in L(G)$ (ekrandan, 01:10:00); $i$ kez tekrarlanırsa $aa(bb)^i cc(dd)^i ee \in L(G)$, her $i \ge 0$ için (ekrandan, 01:15:00).
- Değişken tekrarı iddiası (ekrandan, 01:20:00)
  - $G$'den birim ve boş üretimler atılır. $r$ değişken sayısı, $t$ bir üretimin sağ tarafının en büyük uzunluğu olsun. Örnekte $r = 5$, $t = 3$, $t^r = 3^5 = 243$.
  - İddia: $w \in L(G)$ ve $|w| > t^r$ ise $w$'nin türetme ağacında kökten bir yaprağa giden ve üzerinde bir değişkenin tekrar ettiği bir yol vardır.
  - İspat (olmayana ergi): ağaçta en çok $r+1$ düzey olsaydı, $i$. düzeyde en çok $t^i$ düğüm, son düzeyde ($r$. düzey) en çok $t^r$ düğüm olurdu; dizgi uzunluğu en çok $t^r$ olurdu (ekrandan, 01:25:00). Bu, $|w| > t^r$ ile çelişir; demek ki en az $r+2$ düzey vardır.
  - $r+2$ düğümlü bir yolda son düğüm uç semboldür; geriye $r+1$ değişken düğümü kalır, ama yalnız $r$ farklı değişken vardır. Güvercin yuvası ilkesiyle bir değişken tekrar eder.
- $w = uvxyz$ ayrışımı (ekrandan, 01:35:00)
  - Tekrar eden değişken $H$ olsun; alt ağacında yalnız $H$'nin tekrar ettiği en derin $H$ çifti seçilir.
  - $S \overset{*}{\Rightarrow} uHz$, $H \overset{*}{\Rightarrow} vHy$, $H \overset{*}{\Rightarrow} x$. Örnekte $u = aa$, $v = bb$, $x = cc$, $y = dd$, $z = ee$.
  - Ortadaki türetme $0, 1, 2, \dots$ kez kullanılabildiği için $u v^i x y^i z \in L(G)$, her $i \ge 0$ için.
  - Gözlem 1: $|vy| \ge 1$ (ekrandan, 01:45:00). Birim ve boş üretim olmadığı için $v$ ile $y$'den en az biri boş değildir.
  - Gözlem 2: $|vxy| \le t^{r+1}$ (ekrandan, 01:50:00). $H$'nin çocuklarının alt ağaçlarında tekrar yoktur, her birinin ürettiği dizgi en çok $t^r$ uzunluktadır; çocuk sayısı $k \le t$ olduğundan $|vxy| \le k \cdot t^r \le t \cdot t^r = t^{r+1}$.
  - Kritik uzunluk $p = t^{r+1}$ seçilir.
- Önsavın ifadesi (ekrandan, 01:55:00)
  - Her sonsuz bağlamdan bağımsız $L$ dili için öyle bir $p$ tam sayısı vardır ki $|w| \ge p$ olan her $w \in L$ dizgisi $w = uvxyz$ biçiminde, $|vxy| \le p$ ve $|vy| \ge 1$ olacak şekilde yazılabilir ve her $i \ge 0$ için $u v^i x y^i z \in L$ olur.
  - Düzenli diller için önsavda dizgi üçe ($xyz$), burada beşe ($uvxyz$) bölünür; kullanım mantığı aynıdır.
- Örnek ispat 1: $L = \{a^n b^n c^n : n \ge 0\}$ bağlamdan bağımsız değildir (ekrandan, 02:15:00)
  - $L$'nin bağlamdan bağımsız olduğu varsayılır, $p$ kritik uzunluk olsun ve $w = a^p b^p c^p$ seçilir ($|w| = 3p \ge p$).
  - $vxy$'nin $w$ içindeki bütün olası yerleri incelenir: yalnız $a^p$, yalnız $b^p$ ya da yalnız $c^p$ içinde olması; $a^p$ ile $b^p$'yi örtmesi (alt durumlar: $v$ yalnız $a$, $y$ yalnız $b$; $v$ hem $a$ hem $b$; $y$ hem $a$ hem $b$); $b^p$ ile $c^p$'yi örtmesi; üçünü birden örtmesi.
  - Her durumda yukarı pompalama ($i = 2$) ya sembol sayılarını eşitsiz yapar ya da $a^n b^n c^n$ biçimini bozar. Üç bloğu birden örtmek $|vxy| \le p$ yüzünden imkânsızdır (ekrandan, 02:30:00).
- Örnek ispat 2: $L = \{vv : v \in \{a,b\}^*\}$ bağlamdan bağımsız değildir (ekrandan, 02:40:00)
  - Kritik uzunluk $m$ ile gösterilir; $w = a^m b^m a^m b^m$ seçilir.
  - $vxy$ ilk $a^m$ içindeyse $v = a^{k_1}$, $y = a^{k_2}$, $k_1 + k_2 \ge 1$; pompalanınca $a^{m+k_1+k_2} b^m a^m b^m \notin L$.
  - Blok sınırlarını örten durumlarda da pompalanan dizgi iki eş yarıya bölünemez. $vxy$ üç bloğu örtemez, çünkü $|vxy| \le m$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Pompalama önsavını ezberlemek gerekir
  - Hoca önsavın uzun olduğunu ama bilinmesi gerektiğini söyledi.
- $p$'ye sayı verilmez
  - Hoca, öğrencilerin $p = 5$ gibi bir sayı alıp ispatı o sayıyla yapmasını kabul etmediğini söyledi. $p$ sembol olarak kalmalı, ispat her $p$ değeri için geçerli olmalıdır.
- Bütün durumlar incelenmelidir
  - Önsav dizginin bazı bölünüşlerini değil, bütün bölünüşlerini kapsar; ispatta $vxy$'nin bütün olası yerleri tek tek gösterilmeli ve her birinde çelişkiye ulaşılmalıdır.
- Bağlamdan bağımsız olmama ispatı sınav konusu olabilir
  - Hoca, bir dilin düzenli ya da bağlamdan bağımsız olmadığını pompalama önsavıyla ispatlama sorusunu test değil açık uçlu ispat olarak sorabileceğini söyledi. Kitaplarda ve internette bağlamdan bağımsız olmayan diller bulup ispatlamayı alıştırma olarak önerdi.
- Sistematik yöntem ile sezgisel çizim
  - PDA'dan gramere sistematik yöntem çok karmaşık sonuç verir; gramerin ne yaptığı görülürse daha basit bir otomat elle çizilebilir.

## Kısa Tekrar Notları

- Bağlamdan bağımsız gramer dilleri = PDA dilleri; ispat iki yönlü ve yapıcıdır.
- Gramer → PDA: üç durum; $\varepsilon,\varepsilon \to S$; $q_1$ döngüsünde $\varepsilon, A \to w$ ve $a, a \to \varepsilon$; $\varepsilon, \$ \to \$$ ile kabul.
- PDA → gramer: tek kabul durumu, $\#$ ve $@$ ile yığın düzeni, her geçiş tek ekleme ya da tek çıkarma; sonra $A_{qq} \to \varepsilon$, $A_{pq} \to A_{pr}A_{rq}$, $A_{pq} \to a A_{rs} b$; başlangıç $A_{q_0 q_f}$.
- $|w| > t^r$ ise türetme ağacında bir yolda bir değişken tekrar eder (güvercin yuvası).
- Önsav: $|w| \ge p$ ise $w = uvxyz$, $|vxy| \le p$, $|vy| \ge 1$, her $i \ge 0$ için $uv^ixy^iz \in L$.
- Kullanım: dilin bağlamdan bağımsız olduğunu varsay, $p$'ye bağlı bir $w$ seç, $vxy$'nin bütün yerlerinde çelişki göster.
- $a^n b^n c^n$ ve $vv$ bağlamdan bağımsız değildir; $a^n b^n$ ve $ww^R$ bağlamdan bağımsızdır (ekrandan, 02:45:00).

## Detaylı Açıklamalar

- Gramerden PDA'ya dönüşümde PDA, en soldan türetmeyi yığında yürütür. Yığının tepesinde bir değişken varsa girdiden bir şey okumadan o değişken bir kuralın sağ tarafıyla değiştirilir; tepede bir uç sembol varsa girdideki sembolle eşleştirilip yığından atılır. $abab$ örneğinde PDA önce $S$'yi koyar, $S$'yi $aSTb$ ile değiştirir, $a$'yı okur, $S$'yi $b$ ile değiştirir, $b$'yi okur, $T$'yi $Ta$ ile, sonra $T$'yi $\varepsilon$ ile değiştirir, kalan $a$ ve $b$'yi okur. Girdi bittiğinde yığında yalnız $\$$ kalır ve otomat $q_2$'ye geçer. Hoca, PDA'nın belirlenimci olmadığını, $S \to b$ seçeneğini deneyen kopyanın ilk adımda girdiyle uyuşmadığı için öldüğünü, slaytın yalnız kabul eden yolu gösterdiğini belirtti.
- PDA'dan gramere dönüşümde değişkenler $A_{pq}$ biçimindedir; alt indisler PDA'nın iki durumudur. Tür 3 kuralda bir sembolü yığına koyan geçiş ile aynı sembolü yığından alan geçiş eşleştirilir; aradaki yol $A_{rs}$ ile, okunan $a$ ve $b$ ise değişkenin iki yanındaki uç sembollerle temsil edilir. Slayttaki $M_4$ örneğinde (ekrandan, 00:40:00) $q_0$'da $@$ konup $q_4 \to q_5$'te çıkarıldığı için $A_{q_0q_5} \to A_{q_1q_4}$, $q_1$'de $Z$ konup $q_4$'te çıkarıldığı için $A_{q_1q_4} \to A_{q_2q_4}$ elde edilir; $a$ sembolünün konup alındığı geçiş çiftlerinden $A_{q_2q_2} \to aA_{q_2q_2}b$, $A_{q_2q_4} \to aA_{q_2q_3}$, $A_{q_2q_4} \to aA_{q_2q_4}$, $A_{q_2q_2} \to A_{q_3q_2}b$, $A_{q_2q_4} \to A_{q_3q_3}$, $A_{q_2q_4} \to A_{q_3q_4}$ gelir. Hoca, gramerin PDA'ya denk olduğunu gösteren slaydı karmaşık olduğu için atladı.
- Pompalama önsavının ispatı iki parçalıdır. Önce $|w| > t^r$ olduğunda türetme ağacının yüksekliğinin en az $r+2$ düzey olduğu, sonra bu yolda $r+1$ değişken düğümü bulunduğu ve yalnız $r$ değişken olduğu için güvercin yuvası ilkesiyle bir değişkenin tekrar ettiği gösterilir. Tekrar eden $H$ değişkeninin iki görünüşü dizgiyi beş parçaya böler; iki $H$ arasındaki türetme silinebilir ya da çoğaltılabilir. Birim ve boş üretim olmadığından bu ara türetme en az bir uç sembol ekler ($|vy| \ge 1$); en derin tekrar seçildiği için orta parça da sınırlıdır ($|vxy| \le t^{r+1}$).
- $a^n b^n c^n$ ispatında örneğin $vxy$ yalnız $a^p$ içindeyse $v = a^{k_1}$, $y = a^{k_2}$ ve $k_1 + k_2 \ge 1$ olur; $i = 2$ için dizgi $a^{p+k_1+k_2} b^p c^p$ olur ve $a$ sayısı $b$ ile $c$ sayısından fazladır. $v$ yalnız $a$, $y$ yalnız $b$ içeriyorsa pompalama $a$ ya da $b$ sayısını artırır ama $c$ sayısı $p$'de kalır. $v$ hem $a$ hem $b$ içeriyorsa $v^2$ içinde $b$'den sonra yine $a$ gelir ve dizgi $a^n b^n c^n$ biçiminde değildir. Bütün durumlarda çelişki çıktığı için varsayım yanlıştır.
- Ders sonrası not: Hoca birkaç yerde eşitsizlikleri karıştırdı. 01:44:45'te "$v$ ile $y$'nin toplam uzunluğu birden büyük olmalı" dedi; doğrusu $|vy| \ge 1$. 02:13:59'da "$|vy| \le 1$" deyip hemen $\ge 1$ diye düzeltti. 02:24:07'de alt durum 2 için "ne $k_1$ ne $k_2$ birden büyük" dedi; doğrusu $k_1 \ge 1$ ve $k_2 \ge 1$ (ikisi de sıfırdan farklı). 02:28:05'te pompalanan dizgideki $a$ sayısını "$p + 2k_1 + k_2$" diye okudu; $uv^2xy^2z$'de $a$ sayısı $p + k_1$'dir, asıl sorun dizginin biçiminin bozulmasıdır.
- Ders sonrası not: İki örnek, küçük $p$ değerleri ($p = 1, \dots, 6$) için bütün $uvxyz$ bölünüşleri denenerek python ile kontrol edildi: her bölünüşte $i = 0$ ya da $i = 2$ için dizgi dilin dışına çıkıyor. Bu yalnız bir sağlamadır, ispatın yerini tutmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
