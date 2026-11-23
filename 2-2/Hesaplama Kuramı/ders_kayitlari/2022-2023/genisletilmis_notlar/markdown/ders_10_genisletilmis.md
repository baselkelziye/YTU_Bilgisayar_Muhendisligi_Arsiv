# Ders 10 Genişletilmiş Notu: Gramer ile Yığıtlı Otomat Denkliği ve Bağlamdan Bağımsız Diller için Pompalama Önsavı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlamdan Bağımsız Gramerler ile Yığıtlı Otomatların Denkliği
- 2. Gramerden Yığıtlı Otomata Dönüşüm
- 3. Örnek: $abab$ Girdisinin Kabulü
- 4. Yığıtlı Otomattan Gramere Dönüşüm
- 5. Sonsuz Bağlamdan Bağımsız Diller ve Değişken Tekrarı
- 6. Değişken Tekrarı İddiası ve İspatı
- 7. $uvxyz$ Ayrışımı ve İki Gözlem
- 8. Pompalama Önsavının İfadesi ve Kullanımı
- 9. Örnek: $a^n b^n c^n$ Bağlamdan Bağımsız Değildir
- 10. Önsavı Uygularken Yapılan Hata
- 11. Örnek: $vv$ Bağlamdan Bağımsız Değildir
- Örnek Sorular

## 1. Bağlamdan Bağımsız Gramerler ile Yığıtlı Otomatların Denkliği

Ders, iki hafta önce işlenen konunun Türkçe bir tekrarıyla başladı; ikinci yarıda anlatım İngilizce sürdü. Daha önce bağlamdan bağımsız diller (context-free languages) ve gramerler, sonra yığıtlı otomatlar (pushdown automata, PDA) görülmüştü. Yığın (stack), üst üste konan şeylerdir: bir şey üste konur ve yine üstten alınır.

Temel teorem şudur: bağlamdan bağımsız gramerlerin ürettiği dillerin kümesi, yığıtlı otomatların kabul ettiği dillerin kümesine eşittir. İkisi tam olarak aynı dilleri tanımlar.

İki kümenin eşitliği ispatlanırken ispat ikiye ayrılır. Önce birinci kümenin ikincinin alt kümesi olduğu, sonra birinci kümenin ikincinin üst kümesi olduğu (ikincinin birincinin alt kümesi olduğu) gösterilir. İki yön de ispatlanınca kümelerin eşit olduğu ortaya çıkar.

## 2. Gramerden Yığıtlı Otomata Dönüşüm

Hoca bu yönün aslında çok basit olduğunu söyledi: yalnız üç durumlu bir otomat yazılır (ekrandan, 00:15:00).

| Geçiş | Etiket | Anlamı |
|---|---|---|
| $q_0 \to q_1$ | $\varepsilon, \varepsilon \to S$ | Girdiden bir şey okumadan gramerin başlangıç değişkeni $S$ yığına konur. |
| $q_1 \to q_1$ (döngü) | her $A \to w$ üretimi için $\varepsilon, A \to w$ | Yığının tepesinde $A$ varsa girdi okunmadan $A$ çıkarılır, yerine $w$ konur. |
| $q_1 \to q_1$ (döngü) | her uç sembol $a$ için $a, a \to \varepsilon$ | Girdide $a$ okunur ve yığının tepesindeki $a$ atılır; yerine bir şey konmaz. |
| $q_1 \to q_2$ | $\varepsilon, \$ \to \$$ | Girdi bitmiş ve yığında yalnız dip sembolü $\$$ kalmışsa kabul durumu $q_2$'ye geçilir. |

$q_0$ başlangıç, $q_2$ kabul durumudur. $\$$, yığının dibine erişildiğini gösteren özel bir semboldür. İlk ve son geçiş her gramer için aynıdır; gramere özgü olan, $q_1$'in döngüsüne eklenen geçişlerdir. Bu otomat gramerin üretimlerini taklit eder (simulates the productions).

## 3. Örnek: $abab$ Girdisinin Kabulü

Slayttaki gramer şudur (ekrandan, 00:20:00):

$$S \to aSTb \mid b, \qquad T \to Ta \mid \varepsilon$$

Buna karşılık gelen PDA'nın $q_1$ döngüsünde şu geçişler vardır: $\varepsilon, S \to aSTb$; $\varepsilon, S \to b$; $\varepsilon, T \to Ta$; $\varepsilon, T \to \varepsilon$; $a, a \to \varepsilon$; $b, b \to \varepsilon$.

Hoca $abab$ girdisinin hem gramerce nasıl üretildiğini hem PDA'ca nasıl kabul edildiğini adım adım gösterdi. Gramerde en soldan türetme (leftmost derivation) kullanılır; ilk adımda $S$'nin iki kuralı vardır ve girdi $a$ ile başlayıp $b$ ile bittiği için $S \to aSTb$ seçilir.

Hoca burada önemli bir noktaya dikkat çekti: yığıtlı otomat belirlenimci değildir (non-deterministic), paralel çalışabilir. $S$'nin iki kuralı aynı anda uygulanır; otomat ikiye bölünür ve her kopyanın kendi yığını olur. Girdiyi okumaya devam edemeyen, yani uygun geçişi olmayan kopya ölür; uygun geçişi olan kopya devam eder. Slayt yalnız kabul eden yolu gösterir, $S \to b$ seçen kopyanın bir süre sonra öldüğü için hiç gösterilmediğini söyledi; hoca ise bölünme fikrini faydalı bulduğunu belirtti.

Kabul eden yolun adımları aşağıdadır (Time 1 ve Time 10 ekrandan, 00:20:00 ve 00:25:00; aradaki satırlar hocanın anlatımından kuruldu, ara adım eklendi):

| Adım | Kullanılan geçiş | Okunan | Yığın (tepe solda) |
|---|---|---|---|
| 0 | başlangıç ($q_0$) | | $\$$ |
| 1 | $\varepsilon, \varepsilon \to S$ | | $S\$$ |
| 2 | $\varepsilon, S \to aSTb$ | | $aSTb\$$ |
| 3 | $a, a \to \varepsilon$ | $a$ | $STb\$$ |
| 4 | $\varepsilon, S \to b$ | | $bTb\$$ |
| 5 | $b, b \to \varepsilon$ | $b$ | $Tb\$$ |
| 6 | $\varepsilon, T \to Ta$ | | $Tab\$$ |
| 7 | $\varepsilon, T \to \varepsilon$ | | $ab\$$ |
| 8 | $a, a \to \varepsilon$ | $a$ | $b\$$ |
| 9 | $b, b \to \varepsilon$ | $b$ | $\$$ |
| 10 | $\varepsilon, \$ \to \$$ ($q_2$, kabul) | | $\$$ |

Hoca 3. adımda bir adımı atladığını fark edip düzeltti: $S$'ye geçmeden önce yığının tepesindeki $a$ ile girdideki $a$ eşleştirilmelidir. Gramer tarafındaki türetme de aynı sırayı izler (ekrandan, 00:25:00):

$$S \Rightarrow aSTb \Rightarrow abTb \Rightarrow abTab \Rightarrow abab$$

Böylece $abab$ hem gramerce üretilir hem PDA'ca kabul edilir. Slaytta yığıtlı otomatın anlık durumları da listelenmişti; hoca bunlara kendileri baktıkları için geçti.

Sonuç olarak her bağlamdan bağımsız gramer bir yığıtlı otomata çevrilebilir. Demek ki bağlamdan bağımsız gramerlerin ürettiği diller kümesi, yığıtlı otomatların kabul ettiği diller kümesinin alt kümesidir. Bu, teoremin ilk yarısıdır. Buradaki ispat yapıcı ispattır (proof by construction): dönüşümün adım adım nasıl yapılacağı gösterilir; yapılabildiği gösterildiği için doğruluğu ispatlanmış olur.

## 4. Yığıtlı Otomattan Gramere Dönüşüm

Ters yön de daha önce görülmüştü; hoca bunun çok daha karmaşık bir süreç olduğunu söyledi. Dört beş adım vardır ve her adımda öncekinden biraz daha karmaşık yeni bir yığıtlı otomat elde edilir. Yöntem sistematik olduğu için sonuç çok karmaşıktır. Hocaya göre gramerin (ya da otomatın) ne yaptığına bakıp kendiniz çizdiğinizde çoğu zaman daha basit bir sonuç elde edersiniz; ama burada her duruma uyan sistematik bir yöntem anlatılır.

Başlangıçta herhangi bir yığıtlı otomat $M$ olsun.

### 4.1 Adım 1: Tek Kabul Durumu

Birden fazla kabul durumu varsa hepsi kabul olmayan duruma çevrilir ve bunlardan yeni tek kabul durumuna doğrudan (boş) bir geçiş eklenir. Böylece otomatın tek bir kabul durumu kalır.

### 4.2 Adım 2: Yeni Yığın Sembolleri

Yığına yeni semboller eklenir (ekrandan, 00:30:00). Yığının tepeden dibe doğru görünümü şudur:

| Yığın (tepeden dibe) | Anlamı |
|---|---|
| $Z$ | $M$'nin eski başlangıç yığın sembolü |
| $@$ | yardımcı yığın sembolü (auxiliary) |
| $\#$ | yeni başlangıç yığın sembolü |

Yeni otomat $M_2$'nin başına iki durum eklenir: önce $\varepsilon, \varepsilon \to @$, sonra $\varepsilon, \varepsilon \to Z$ geçişiyle eski otomat $M_1$'in başlangıç durumuna girilir. Slaytın ifadesiyle $M_1$ hâlâ $Z$'nin başlangıç yığın sembolü olduğunu düşünür.

Kabul anında yığında yalnız $\#$ kalması istenir. Bunun için iki yeni durum eklenir ve eski kabul durumu kabul olmayan duruma çevrilir. Eski kabul durumundan bir ara duruma doğrudan geçilir. Ara durumdaki döngüde yığında ne varsa ($a$, $b$, $c$ gibi her $x$ sembolü) $\varepsilon, x \to \varepsilon$ ile tek tek kaldırılır; yalnız $@$ ve $\#$ kaldırılmaz. Sonra $\varepsilon, @ \to \varepsilon$ ile $@$ da kaldırılır ve yeni kabul durumuna geçilir. Sonunda yığında yalnız $\#$ kalır. Hoca buraya kadar gramere hiç bakılmadığını vurguladı.

### 4.3 Adım 3: Her Geçiş Tek İşlem Yapar

Her geçiş ya yığından tam bir sembol kaldırır ya da yığına tam bir sembol ekler. Bir geçiş hem bir şey kaldırıp hem bir şey ekliyorsa ikiye bölünür: önce kaldıran, sonra ekleyen bir geçiş olur. Yığına hiç dokunmayan bir geçiş varsa rastgele bir sembol yığına eklenir ve hemen ardından kaldırılır. Bu adımların sonunda elde edilen otomata $M_4$ denir. Slaytta son derece basit bir yığıtlı otomatın bütün bu işlemlerden sonra çok daha büyük bir otomata dönüştüğü gösterildi.

### 4.4 Gramer Kurallarının Üretilmesi

Artık otomata bakılarak gramer yazılır. Gramerin değişkenleri $A_{q_i q_j}$ biçimindedir; $q_i$ ve $q_j$ otomatın durumlarıdır. Üç tür kural eklenir:

- Tür 1: her durum $q$ için $A_{qq} \to \varepsilon$.
- Tür 2: her üç durum $p, q, r$ için $A_{pq} \to A_{pr} A_{rq}$ (ekrandan, 00:35:00). Yani $p$'den $q$'ya gitmek, $p$'den $r$'ye ve $r$'den $q$'ya gitmeye ayrılabilir.
- Tür 3: geçiş çiftlerinden gelen kurallar. $p$'den $r$'ye $a, \varepsilon \to t$ geçişi ve $s$'den $q$'ya $b, t \to \varepsilon$ geçişi varsa $A_{pq} \to a A_{rs} b$ eklenir.

Tür 3'te iki geçişi birbirine bağlayan $t$ sembolüdür: birinci geçişte yığına eklenir, ikincide yığından kaldırılır. Kuralın sol tarafındaki değişkenin alt indisleri birinci geçişin ilk durumu $p$ ile ikinci geçişin son durumu $q$'dur; sağdaki değişkenin alt indisleri ise birinci geçişin son durumu $r$ ile ikinci geçişin ilk durumu $s$'dir. Değişkenin önüne birinci geçişte okunan $a$, arkasına ikinci geçişte okunan $b$ yazılır.

Son olarak başlangıç değişkeni belirlenir: $q_0$ otomatın başlangıç durumu, $q_f$ tek kabul durumudur ve $A_{q_0 q_f}$ başlangıç değişkeni yapılır. Bu değişken önceki kurallarda zaten oluşmuş olmalıdır; yalnız gramerin en başına konur.

### 4.5 Slayttaki $M_4$ Örneği

Slayttaki $M_4$ otomatının geçişleri şunlardır (ekrandan, 00:40:00):

| Kaynak | Hedef | Etiket |
|---|---|---|
| $q_0$ | $q_1$ | $\varepsilon, \varepsilon \to @$ |
| $q_1$ | $q_2$ | $\varepsilon, \varepsilon \to Z$ |
| $q_2$ | $q_2$ | $a, \varepsilon \to a$ |
| $q_2$ | $q_2$ | $b, a \to \varepsilon$ |
| $q_2$ | $q_3$ | $\varepsilon, \varepsilon \to a$ |
| $q_3$ | $q_4$ | $\varepsilon, a \to \varepsilon$ |
| $q_4$ | $q_4$ | $\varepsilon, a \to \varepsilon$ |
| $q_4$ | $q_4$ | $\varepsilon, b \to \varepsilon$ |
| $q_4$ | $q_4$ | $\varepsilon, Z \to \varepsilon$ |
| $q_4$ | $q_5$ (kabul) | $\varepsilon, @ \to \varepsilon$ |

Önce her durum için $A_{q_0q_0} \to \varepsilon$, $A_{q_1q_1} \to \varepsilon$ gibi Tür 1 kuralları, sonra bütün üçlülerden Tür 2 kuralları eklenir. Slaytta gösterilen Tür 3 kuralları şunlardır (ekrandan, 00:40:00):

$$A_{q_0q_5} \to A_{q_1q_4}, \quad A_{q_1q_4} \to A_{q_2q_4}$$

$$A_{q_2q_4} \to aA_{q_2q_4}, \quad A_{q_2q_2} \to aA_{q_2q_2}b, \quad A_{q_2q_4} \to aA_{q_2q_3}$$

$$A_{q_2q_2} \to A_{q_3q_2}b, \quad A_{q_2q_4} \to A_{q_3q_3}, \quad A_{q_2q_4} \to A_{q_3q_4}$$

Örneğin $q_0 \to q_1$ geçişinde $@$ eklenir, $q_4 \to q_5$ geçişinde $@$ kaldırılır; iki geçişte de girdi okunmadığı için $A_{q_0q_5} \to A_{q_1q_4}$ çıkar. $q_2$'deki $a, \varepsilon \to a$ döngüsü ile $q_2$'deki $b, a \to \varepsilon$ döngüsü eşleşince $A_{q_2q_2} \to aA_{q_2q_2}b$ çıkar. Hoca, yöntem mekanik olduğu için çok fazla değişken oluştuğunu, bunu kâğıt üzerinde elle yapmanın zor ama bir makine için çok kolay olduğunu söyledi.

Gramerin PDA'ya denk olduğunu ve nasıl çalıştığını gösteren bir slayt daha vardı; hoca karmaşık olduğu için onu atladı ve merak edenlerin bakabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu yapıda $A_{pq}$ değişkeninin ürettiği dizgiler, otomatı $p$ durumunda belli bir yığınla alıp $q$ durumuna aynı yığınla getiren hesaplamaların okuduğu dizgilerdir. Tür 3 kuralı, yolun başında konup sonunda alınan sembolün iki uçta eşleştiği durumu; Tür 2 kuralı ise yolun ortasında yığının ilk hâline döndüğü bir $r$ durumuna bölünmesini anlatır. Başlangıç değişkeni $A_{q_0q_f}$ bu yüzden otomatın kabul ettiği dizgileri üretir.

## 5. Sonsuz Bağlamdan Bağımsız Diller ve Değişken Tekrarı

Aradan sonra yeni konu başladı: bağlamdan bağımsız diller için yeni bir pompalama önsavı (pumping lemma).

Sonsuz bir bağlamdan bağımsız dil, sonsuz sayıda farklı dizgi üretir; istendiği kadar uzun dizgiler üretilebilir. Slayttaki örnek gramer şudur (ekrandan, 01:00:00):

$$S \to ABE \mid bBd, \quad A \to Aa \mid a, \quad B \to bSD \mid cc, \quad D \to Dd \mid d, \quad E \to eE \mid e$$

Örneğin $A \to Aa$ kuralı $A$'yı tekrar tekrar kullanmaya izin verir ve sonunda $A \to a$ ile bitirilir; bu tek başına dilin çok uzun dizgiler üretebilmesini sağlar. $D$ ve $E$ kuralları da dili sonsuz yapar.

Yeterince uzun bir dizginin türetmesine bakılır: $aabbccddee$. Türetme ağacı şöyle kurulur (ekrandan, 01:05:00):

```text
S -> A B E
  A -> A a ; A -> a           (aa)
  B -> b S D
    S -> b B d
      B -> c c                (cc)
    D -> d
  E -> e E ; E -> e           (ee)
```

İlk adımda $S \to ABE$, sonra $A \to Aa$, $B \to bSD$, $E \to eE$, ardından $A \to a$, $D \to d$, $E \to e$ kullanılır. $B$'nin içindeki $S$ için $S \to bBd$ uygulanır ve yine bir $B$ elde edilir; bu son $B$, $B \to cc$ ile bitirilir. Böylece $B$ değişkeni kökten yaprağa giden bir yolda iki kez görünür; slayt bunu "tekrar eden değişken" (repeated variable) diye işaretler.

Ağaç üç bölgeye ayrılabilir:

$$S \overset{*}{\Rightarrow} aaBee, \qquad B \overset{*}{\Rightarrow} bbBdd, \qquad B \Rightarrow cc$$

Birinci bölge $S$'den başlar ve $aa$, $B$ değişkeni ve $ee$ ile biter. İkinci bölge $B$'den başlar ve $bb$, yine $B$ değişkeni ve $dd$ ile biter. Üçüncü bölgede $B$ doğrudan $cc$ olur.

Ortadaki bölge çıkarılabilir: $S$'den $aaBee$ elde edildikten sonra $B$ doğrudan $cc$ yapılır. Bu $bb$ ve $dd$'yi atmak, yani üslerini sıfır yapmak demektir (ekrandan, 01:10:00):

$$S \overset{*}{\Rightarrow} aaBee \Rightarrow aaccee = aa(bb)^0cc(dd)^0ee \in L(G)$$

Tersine ortadaki bölge iki kez kullanılabilir; o zaman $bb$ ve $dd$ ikişer kez üretilir ve $aa(bb)^2cc(dd)^2ee$ de dilde olur. Üç kez kullanılırsa üsler 3 olur. Ortadaki bölgenin kullanılma sayısı $bb$ ve $dd$'nin üssüne eşittir. Genel kural (ekrandan, 01:15:00):

$$S \overset{*}{\Rightarrow} aa(bb)^i cc(dd)^i ee \in L(G), \quad i \ge 0$$

Özetle bir gramer ve bir dizgi verildi; dizginin bir ailenin üyesi olduğu ve bu ailede $bb$ ile $dd$'nin birlikte atılabildiği ya da istendiği kadar tekrarlanabildiği görüldü. Bu gözlem her sonsuz bağlamdan bağımsız dile uygulanabilir.

## 6. Değişken Tekrarı İddiası ve İspatı

### 6.1 Hazırlık

$L$ sonsuz bir bağlamdan bağımsız dil, $G$ de onun grameri olsun (boş dizgi dışarıda bırakılır). $G$'den birim üretimler (unit productions) ve boş üretimler (null productions) atılır; bu özellikleri taşımayan bir gramer sürümü kullanılır.

- $r$: değişken sayısı.
- $t$: herhangi bir üretimin sağ tarafının en büyük uzunluğu.

Örnek gramerde beş değişken vardır ($S, A, B, D, E$), yani $r = 5$. Sağ tarafların uzunlukları 1, 2 ve 3'tür; en büyüğü 3 olduğundan $t = 3$.

### 6.2 İddia

İddia şudur (ekrandan, 01:20:00): $w \in L(G)$ ve $|w| > t^r$ ise $w$'nin türetme ağacında kökten bir yaprağa giden ve üzerinde $G$'nin bir değişkeninin tekrar ettiği bir yol vardır.

Örnekte $t^r = 3^5 = 243$. Hoca bunu öğrencilere sordu ve cevap 243 oldu. Yani 243'ten uzun bir dizgi üretilmeye çalışılırsa değişkenlerden en az birini tekrar kullanmak gerekir. Hocanın sezgisel açıklaması şudur: değişken içeren kuralların her biri yalnız bir kez kullanılırsa ancak sınırlı uzunlukta bir dizgi elde edilir (gerçekte bu sınır daha da küçüktür); daha uzun bir dizgi için değişken içeren kurallardan birini yeniden kullanmak, yani bir değişkeni tekrar etmek gerekir.

### 6.3 Ağaç Yüksekliği (Olmayana Ergi)

Önce ağacın en az $r+2$ düzeyi olduğu, yani kullanılan kural zincirinin en az $r+2$ uzunlukta olduğu gösterilir. Bu bir alt ispattır ve yine olmayana ergi (proof by contradiction) ile yapılır: tersine, ağaçta en çok $r+1$ düzey olduğu varsayılır.

Bir düğümün en çok $t$ çocuğu olabilir (örnekte 3). Düzey düzey en çok düğüm sayısı şöyledir (ekrandan, 01:25:00):

| Düzey | En çok düğüm |
|---|---|
| 0 | $1$ |
| 1 | $t$ |
| 2 | $t^2$ (örnekte $3 \cdot 3 = 9$) |
| $i$ | $t^i$ |
| $r$ (son düzey) | $t^r$ |

Düzeyler 0'dan başladığı için $r+1$ düzeyin sonuncusu $r$. düzeydir. Son düzeydeki her düğüm bir sembol olabilir; dolayısıyla dizginin en büyük uzunluğu $t^r$ olur, yani $|w| \le t^r$. Oysa $|w| > t^r$ olduğu verilmişti. Bu çelişki, ağacın en az $r+2$ düzeyi olması gerektiğini gösterir. Hoca çelişkinin, iddianın verilen bilgisi olan $|w| > t^r$ ile ortaya çıktığını vurguladı.

### 6.4 Güvercin Yuvası İlkesi

Demek ki kökten bir yaprağa en az $r+2$ düğümlü bir yol vardır. Yol başlangıç değişkeni $V_1$ ile başlar, ondan bir $V_2$, ondan bir $V_3$ elde edilir. Uç sembol veren kural kullanılınca türetme biter, devam edilemez; bu yüzden uç sembolden önceki bütün düğümler değişkendir. Böylece yolda değişken içeren $r+1$ düğüm vardır. Ama yalnız $r$ farklı değişken vardır. $r+1$ adımı $r$ değişkene dağıtınca en az bir değişken iki kez kullanılır; buna güvercin yuvası ilkesi (pigeonhole principle) denir.

Hoca bir yerde "en az $r+1$ düğümlü yol" deyip hemen "en az $r+2$" diye düzeltti; doğrusu $r+2$ düğümdür.

## 7. $uvxyz$ Ayrışımı ve İki Gözlem

### 7.1 Beş Parça

Tekrar eden değişkenlerden biri $H$ olsun. Birden fazla değişken tekrar edebilir; bu durumda en derindeki seçilir, öyle ki seçilen alt ağaçta yalnız $H$ tekrar etsin.

$w$ dizgisi beş parçaya bölünür: $w = uvxyz$ (ekrandan, 01:35:00). Bunların hepsi uç sembol dizgileridir.

- $S$'den başlayıp ilk $H$'ye gelinir. İlk $H$'nin solunda kalan kısım $u$, sağında kalan kısım $z$ olur.
- İlk $H$'den ikinci $H$'ye gelinir. Bu arada ikinci $H$'nin soluna üretilen kısım $v$, sağına üretilen kısım $y$ olur.
- İkinci $H$'nin alt ağacının ürettiği kısım $x$ olur.

Önceki örnekte tekrar eden değişken $B$ idi. İlk $B$'den önce $A$ vardır ve $A$'dan $aa$ elde edilir: $u = aa$. İlk $B$'den sonra $E$ vardır ve $E$'den $ee$ elde edilir: $z = ee$. Son $B$'den $cc$ çıkar: $x = cc$. İki $B$ arasında, ikinci $B$'nin solunda $bb$ ($v$), sağında $dd$ ($y$) üretilir.

Parçalar birbirinden bağımsız değildir: $u$ ile $z$ ilk $H$'nin iki yanında, $v$ ile $y$ ikinci $H$'nin iki yanında oluşur. Olası bir türetme şöyle yazılabilir:

$$S \overset{*}{\Rightarrow} uHz, \qquad H \overset{*}{\Rightarrow} vHy, \qquad H \overset{*}{\Rightarrow} x$$

Örnekte $S \overset{*}{\Rightarrow} aaBee$, $B \overset{*}{\Rightarrow} bbBdd$ ve $B \Rightarrow cc$ olur.

Ortadaki türetme ($H \overset{*}{\Rightarrow} vHy$) çıkarılırsa $v$ ve $y$ kaybolur, üsleri sıfır olur ve $uxz$ yine dildedir. İki kez kullanılırsa $v$ ve $y$'nin üssü 2 olur; $i$ kez kullanılırsa her seferinde bir $v$ ve bir $y$ eklenir ve üsleri $i$ olur. $v$ ile $y$'nin üssü hep aynıdır:

$$u v^i x y^i z \in L(G), \quad i \ge 0$$

### 7.2 Gözlem 1: $|vy| \ge 1$

Birim üretimler ve boş üretimler atıldığı için $H$'nin tekrarı arasında en az bir uç sembol üretilir (ekrandan, 01:45:00). Hoca, bu sembolün $v$'den "ve" $y$'den değil, $v$'den "ya da" $y$'den gelmesi gerektiğini vurguladı. Yani $v$ ile $y$'den en az biri boş değildir.

> **Ders sonrası not:** Hoca bu gözlemi "$v$ ile $y$'nin toplam uzunluğu birden büyük olmalı" diye söyledi; slayttaki ve doğru ifade $|vy| \ge 1$'dir.

### 7.3 Gözlem 2: $|vxy| \le t^{r+1}$

Orta parça $vxy$'nin uzunluğu sınırlıdır, çünkü alt ağaç, içinde yalnız $H$ tekrar edecek şekilde seçildi. Slayttaki gerekçe şudur (ekrandan, 01:50:00): üstteki $H$'nin çocuklarından çıkan alt ağaçlar $T_1, T_2, \dots, T_k$, bunların ürettiği dizgiler $s_1, s_2, \dots, s_k$ olsun. Bunlar art arda gelince $vxy$ olur:

$$vxy = s_1 s_2 \cdots s_k$$

Hiçbir $T_j$ alt ağacında değişken tekrar etmediği için $|s_j| \le t^r$ olur. Böylece

$$|vxy| = \sum_{j=1}^{k} |s_j| \le k \cdot t^r \le t \cdot t^r = t^{r+1}$$

Son eşitsizlikte $k \le t$ kullanılır. Hoca neden $k \le t$ olduğunu öğrencilere sordu; bir öğrenci her düğümün en fazla $t$ çocuğu olabileceğini söyledi ve hoca bunu doğruladı: $s_1$ birinci çocuktan, $s_2$ ikinci çocuktan gelir ve en fazla $t$ çocuk vardır. $t$ bir üretimin sağ tarafının en büyük uzunluğudur.

Kritik uzunluk $p = t^{r+1}$ seçilir; bu $p$, $t^r$'den büyüktür. Bu iki gözlemle pompalama önsavı elde edilir.

## 8. Pompalama Önsavının İfadesi ve Kullanımı

Önsav şimdiye kadar fark edilen her şeyi toplar (ekrandan, 01:55:00):

Her sonsuz bağlamdan bağımsız $L$ dili için öyle bir $p$ tam sayısı vardır ki $w \in L$ ve $|w| \ge p$ olan her $w$ dizgisi

$$w = uvxyz, \qquad |vxy| \le p, \qquad |vy| \ge 1$$

olacak şekilde yazılabilir ve

$$u v^i x y^i z \in L, \quad \text{her } i \ge 0 \text{ için}$$

> **Hocanın vurgusu:** Önsav uzun ama bilinmesi gerekir.

Önsava göre uzun bir dizgi bu uzunluk kısıtlarıyla beşe bölünebilir; $v$ ile $y$'den yalnız biri boş olabilir, ikisi birden boş olamaz. $v$ ve $y$'nin üssü istenildiği gibi değiştirilebilir ve elde edilen dizgiler yine dilde kalır. Aşağı pompalamada (pump down) $i = 0$ alınır, $v$ ile $y$ atılır ve $uxz$ elde edilir; yukarı pompalamada (pump up) $i = 2, 3, 10$ gibi değerler alınır.

Önsav, bir dilin bağlamdan bağımsız **olmadığını** ispatlamak için kullanılır. Olmayana ergi için dilin bağlamdan bağımsız olduğu varsayılır. Sonra yeterince uzun bir $w$ seçilir ve bu kısıtlara uyan bütün olası $uvxyz$ bölünüşleri incelenir; hiçbir bölünüşün işe yaramadığı gösterilir.

Hoca düzenli diller için öğrenilen pompalama önsavıyla benzerliği vurguladı: mantık aynıdır, kullanım neredeyse aynıdır. Tek fark, düzenli diller için önsavda $w$ üç parçaya ($xyz$), burada beş parçaya ($uvxyz$) bölünür.

## 9. Örnek: $a^n b^n c^n$ Bağlamdan Bağımsız Değildir

$L = \{a^n b^n c^n : n \ge 0\}$ dilinin bağlamdan bağımsız olmadığı ispatlanır (ekrandan, 02:15:00).

Olmayana ergi için $L$'nin bağlamdan bağımsız olduğu varsayılır. $L$ sonsuz ve bağlamdan bağımsız olduğu için önsav uygulanabilir. $p$ önsavın kritik uzunluğu olsun. Önsav, uzunluğu $p$ ya da daha fazla olan her dizgiye uygulanabildiği için

$$w = a^p b^p c^p$$

seçilir. Uzunluğu $3p \ge p$'dir ve dilin biçimine uyduğu için dildedir. Önsava göre $w = uvxyz$, $|vxy| \le p$, $|vy| \ge 1$ olacak şekilde bölünebilmeli ve her $i$ için $uv^ixy^iz$ dilde olmalıdır. Orta parça $vxy$'nin bütün olası yerleri incelenir; hiçbirinin işe yaramaması gerekir.

### 9.1 Durum 1: $vxy$ yalnız $a^p$ içinde

$vxy$ ilk bölgedeyse $v = a^{k_1}$, $y = a^{k_2}$ olur ve $|vy| \ge 1$ olduğu için $k_1 + k_2 \ge 1$. Yukarı pompalanınca ($i = 2$) iki $v$ ve iki $y$ gelir; $a$ sayısı $p + k_1 + k_2$ olur:

$$uv^2xy^2z = a^{p+k_1+k_2} b^p c^p$$

$k_1 + k_2 \ge 1$ olduğundan $a$ sayısı $b$ ve $c$ sayısından fazladır; dizgi dilde değildir. Önsava göre dilde olmalıydı; çelişki.

### 9.2 Durum 2 ve Durum 3: $vxy$ yalnız $b^p$ ya da yalnız $c^p$ içinde

Durum 1'e benzer. Yukarı pompalanınca $b$'ler (ya da $c$'ler) diğer iki sembolden fazla olur; dil üç sembolden tam olarak aynı sayıda istediği için dizgi dilde değildir.

### 9.3 Durum 4: $vxy$, $a^p$ ile $b^p$'yi örtüyor

$vxy$ biraz $a$ biraz $b$ içerir. Alt durumlara ayrılır.

**Alt durum 1:** $v$ yalnız $a$, $y$ yalnız $b$ içerir; $x$'te hem $a$ hem $b$ olabilir. $|vy| \ge 1$ olduğundan $vy$ içinde en az bir $a$ ya da en az bir $b$ vardır. Yukarı pompalanınca $a$ ya da $b$ sayısı artar, ama $c$ sayısı $p$'de kalır. Böylece $c$ sayısı $a$ ya da $b$ sayısından az olur; dizgi dilde değildir, çelişki.

**Alt durum 2:** $v$ hem $a$ hem $b$, $y$ yalnız $b$ içerir (ekrandan, 02:25:00). $v = a^{k_1} b^{k_2}$, $y = b^{k_3}$ yazılır. Varsayım gereği $v$ hem $a$ hem $b$ içerdiği için $k_1 \ge 1$ ve $k_2 \ge 1$'dir. Hoca bu noktayı ilk bakışta göremediğini söyleyip öğrencilere sordu ve gerekçenin varsayımın kendisi olduğu sonucuna vardı. $k_3$ için bir şey söylenemez; $v$ boş olmadığından $y$ boş olabilir.

Yukarı pompalanınca iki $v$ yan yana gelir: $a^{k_1} b^{k_2} a^{k_1} b^{k_2}$. Bu durumda bazı $a$'lar, bazı $b$'ler, sonra yine bazı $a$'lar gelir. $a$'lar homojen bir blok olmalıydı; $a$'ların arasında $b$ olamaz. Dizgi artık $a^n b^n c^n$ biçiminde değildir; sembol sayıları da eşit değildir, çünkü $a$ sayısı artmış ama $c$ sayısı $p$'de kalmıştır. Çelişki.

> **Ders sonrası not:** Hoca bu durumda "ne $k_1$ ne $k_2$ birden büyük" dedi; doğrusu $k_1 \ge 1$ ve $k_2 \ge 1$'dir. Ayrıca pompalanan dizgideki $a$ sayısını "$p + 2k_1 + k_2$" diye okudu; $uv^2xy^2z$'deki $a$ sayısı $p + k_1$'dir. İspat için asıl önemli olan biçimin bozulmasıdır.

**Alt durum 3:** $y$ hem $a$ hem $b$, $v$ yalnız $a$ içerir. Önceki alt durumlara benzer şekilde çelişki çıkar.

### 9.4 Durum 5: $vxy$, $b^p$ ile $c^p$'yi örtüyor

Durum 4'e benzer şekilde alt durumlarla incelenir ve her alt durumda çelişki çıkar. <!-- BELİRSİZ: Altyazı 02:29:13 civarında bozuk; durum 5'in ayrıntısı altyazıdan okunamadı, slaytlardaki genel sıra izlenmiştir. -->

### 9.5 Durum 6: $vxy$ üç bloğu birden örtüyor

$vxy$ bir $a$'dan başlayıp bir $c$'de bitebilir mi? Bu imkânsızdır (ekrandan, 02:30:00). Bunun için $vxy$'nin bütün $b^p$ bloğunu içermesi gerekir; bu da $|vxy| \ge p + 2$ demektir, oysa $|vxy| \le p$.

Bütün durumlarda ve alt durumlarda çelişki elde edildi; önsav uygulanamadı. Demek ki baştaki varsayım yanlıştır ve $L$ bağlamdan bağımsız değildir.

## 10. Önsavı Uygularken Yapılan Hata

Hoca yaklaşımı Türkçe olarak özetledi. Düzenli diller için pompalama önsavı bir dilin düzenli olmadığını, bağlamdan bağımsız diller için pompalama önsavı da bir dilin bağlamdan bağımsız olmadığını ispatlamak için kullanılır. Önce dilin bağlamdan bağımsız olduğu varsayılır ve önsav uygulanmaya çalışılır. Dizgi beşe bölünür; ortadaki üçlü $vxy$ farklı yerlere gelince ne olacağı tek tek incelenir, bütün olasılıklar denenir. Bütün olasılıklarda çelişkiye ulaşılırsa ispat tamamlanır.

> **Hocanın vurgusu:** Öğrencilerin sık yaptığı bir hata, $p$'ye sayı vermektir ("$p = 5$ alalım" gibi) ve ispatı o sayıyla yapmaktır. Hoca bunu kabul etmediğini söyledi. $p$, $p$ olarak kalmalıdır; ispat yeterince uzun her $p$ değeri için önsavın uygulanamayacağını göstermelidir. Bu yüzden $p$ 3, 5 ya da 6 gibi bir sayı alınamaz.

## 11. Örnek: $vv$ Bağlamdan Bağımsız Değildir

$L = \{vv : v \in \{a,b\}^*\}$ dilinin bağlamdan bağımsız olmadığı ispatlanır (ekrandan, 02:40:00). Burada kritik uzunluk $p$ yerine $m$ ile gösterilir.

Olmayana ergi için $L$'nin bağlamdan bağımsız olduğu varsayılır. Uzunluğu en az $m$ olan iyi bir seçim şudur:

$$w = a^m b^m a^m b^m$$

Bu dizgi $v = a^m b^m$ için $vv$ biçimindedir, dolayısıyla dildedir. Önsava göre $w = uvxyz$, $|vxy| \le m$, $|vy| \ge 1$ olacak şekilde bölünebilmeli ve yukarı ya da aşağı pompalanan dizgiler dilde olmalıdır. Yine $vxy$'nin bütün olası yerleri incelenir.

**Durum 1: $vxy$ ilk $a^m$ içinde.** Pompalanan parçalar $v$ ve $y$ olduğu için onlara bakılır: $v = a^{k_1}$, $y = a^{k_2}$; $k_1$ ve $k_2$ bilinmez ama $k_1 + k_2 \ge 1$, yani en az biri sıfırdan farklıdır. Yukarı pompalanınca ilk $a$ bloğu $m + k_1 + k_2$, yani en az $m+1$ uzunlukta olur:

$$uv^2xy^2z = a^{m+k_1+k_2} b^m a^m b^m$$

Dizginin iki yarısı artık aynı olamaz; dil aynı dizginin iki kez yazılmasını istediği için dizgi dilde değildir, çelişki.

**Durum 2: $vxy$ ilk $a^m$ ile ilk $b^m$'nin sınırında; $v = a^{k_1}$, $y = b^{k_2}$.** $k_1 + k_2 \ge 1$'dir. Yukarı pompalanınca ilk $a$ bloğu ya da ilk $b$ bloğu $m$'den uzun olur; dizgi dilde değildir.

**Durum 3: $v$ ilk $a^m b^m$ sınırını örtüyor, $y$ yalnız $b$ içeriyor.** Varsayım gereği $v$ hem $a$ hem $b$ içerdiğinden iki üs de sıfırdan farklıdır. Yukarı pompalanınca elde edilen dizgi dilde değildir.

**Durum 4: $y$ hem $a$ hem $b$ içeriyor.** Durum 3'e benzer, çelişki çıkar.

Diğer durumlar da benzerdir: $vxy$ tamamen ilk $b$ bloğunda, ikinci $a$ bloğunda ya da son $b$ bloğunda ise Durum 1'e; $b$ ile $a$ ya da ikinci $a$ ile $b$ sınırını örtüyorsa Durum 2, 3, 4'e benzer çelişkiler çıkar. $vxy$ üç ya da daha fazla bloğu örtemez, çünkü $|vxy| \le m$'dir ve aradaki bütün bir blok $m$ uzunluktadır. Bütün durumlarda çelişki çıktığı için $L$ bağlamdan bağımsız değildir.

> **Ders sonrası not:** Hoca Durum 2'de "$k_1 + k_2$ birden büyük" dedi; doğrusu $k_1 + k_2 \ge 1$'dir. İki örnek, $p$ (ya da $m$) için 1'den 6'ya kadar değerlerde bütün $uvxyz$ bölünüşleri denenerek python ile sağlandı: her bölünüşte $i = 0$ ya da $i = 2$ için dizgi dilin dışına çıkıyor. Bu yalnız bir sağlamadır, genel ispatın yerini tutmaz.

Slaytın sonunda bağlamdan bağımsız olmayan dillerin bir özeti gösterildi (ekrandan, 02:45:00): $\{a^n b^n c^n : n \ge 0\}$, $\{ww : w \in \{a,b\}^*\}$ ve $\{a^{n!} : n \ge 0\}$ bağlamdan bağımsız değildir; $\{a^n b^n : n \ge 0\}$ ve $\{ww^R : w \in \{a,b\}^*\}$ ise bağlamdan bağımsızdır. Hoca bir örnek daha olduğunu ama o gün için bu kadarının yeterli olduğunu, örneklere sonraki derslerde devam edileceğini söyledi.

> **Hocanın vurgusu:** Bir dilin düzenli ya da bağlamdan bağımsız olmadığını pompalama önsavıyla ispatlama sorusu test olarak değil, açık uçlu ispat olarak sorulabilir. Hoca kitaplarda ve internette bağlamdan bağımsız olmayan diller bulup önsavla ispatlamayı ve bütün durumları göstermeyi alıştırma olarak önerdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:19:08): Örnek gramerde $r = 5$ değişken ve en uzun sağ taraf $t = 3$ ise $t^r$ kaçtır?

> **Çözüm:** $t^r = 3^5 = 243$. Derste bir öğrenci 243 diye cevapladı. Bu uzunluktan uzun her dizginin türetme ağacında bir değişken tekrar eder.

**Soru 2** (derste sözlü, 01:50:31): $|vxy| \le k \cdot t^r \le t \cdot t^r$ eşitsizliğinde $k$ neden $t$'den büyük olamaz?

> **Çözüm:** $k$, üstteki $H$ düğümünün çocuk sayısıdır. Bir düğümün çocukları tek bir üretimin sağ tarafından gelir ve sağ tarafın uzunluğu en çok $t$'dir; dolayısıyla $k \le t$. Derste bir öğrenci bu cevabı verdi, hoca doğruladı.

**Soru 3** (derste sözlü, 02:24:31): $a^p b^p c^p$ ispatında alt durum 2'de ($v = a^{k_1} b^{k_2}$, $y = b^{k_3}$) neden $k_1$ ve $k_2$ sıfırdan farklıdır?

> **Çözüm:** Alt durumun varsayımı $v$'nin hem $a$ hem $b$ içermesidir; bu yüzden $k_1 \ge 1$ ve $k_2 \ge 1$. $k_3$ için bir şey söylenemez; $|vy| \ge 1$ koşulu $v$ boş olmadığı için zaten sağlanır, $y$ boş olabilir.

**Soru 4** (ekrandan, 02:15:00): $L = \{a^n b^n c^n : n \ge 0\}$ dilinin bağlamdan bağımsız olmadığını pompalama önsavıyla ispatlayın.

> **Çözüm:** Derste verildi; bkz. Bölüm 9. $w = a^p b^p c^p$ seçilir; $vxy$ yalnız bir blokta ise pompalama o bloğun sayısını artırır, iki bloğu örtüyorsa üçüncü bloğun sayısı sabit kalır ya da biçim bozulur; üç bloğu örtmek $|vxy| \le p$ yüzünden imkânsızdır.

**Soru 5** (ekrandan, 02:40:00): $L = \{vv : v \in \{a,b\}^*\}$ dilinin bağlamdan bağımsız olmadığını pompalama önsavıyla ispatlayın.

> **Çözüm:** Derste verildi; bkz. Bölüm 11. $w = a^m b^m a^m b^m$ seçilir ve $vxy$'nin bütün yerlerinde pompalanan dizginin iki eş yarıya bölünemediği gösterilir.

**Soru 6** (ekrandan, 02:45:00): $L = \{a^{n!} : n \ge 0\}$ dilinin bağlamdan bağımsız olmadığını gösterin.

> **Çözüm (derste verilmedi):** $L$'nin bağlamdan bağımsız olduğunu varsayalım ve $p$ kritik uzunluk olsun ($p \ge 2$ alınabilir). $w = a^{p!}$ seçilir; $|w| = p! \ge p$. Dizgide yalnız $a$ olduğu için $vy = a^k$ yazılır; $|vy| \ge 1$ ve $|vxy| \le p$ olduğundan $1 \le k \le p$. Yukarı pompalanınca $uv^2xy^2z = a^{p!+k}$ olur. $p! < p! + k \le p! + p < p! + p \cdot p! = (p+1)!$ olduğu için $p! + k$ iki ardışık faktöriyel arasında kalır ve hiçbir sayının faktöriyeli değildir. Dizgi dilde değildir; çelişki. Demek ki $L$ bağlamdan bağımsız değildir.

## Dersin Toparlaması

Dersin ilk yarısında bağlamdan bağımsız gramerlerle yığıtlı otomatların denkliği tekrar edildi. Gramerden PDA'ya dönüşüm üç durumlu bir otomatla yapılır ve otomat en soldan türetmeyi yığında taklit eder; $abab$ örneğinde bu adım adım izlendi. PDA'dan gramere dönüşüm ise otomatı tek kabul durumlu, yığını düzenli ve her geçişi tek ekleme ya da tek çıkarma yapan bir biçime getirip $A_{pq}$ değişkenleriyle üç tür kural üreten sistematik ama karmaşık bir yöntemdir.

İkinci yarıda bağlamdan bağımsız diller için pompalama önsavı türetme ağaçlarından elde edildi. Yeterince uzun bir dizginin türetme ağacında güvercin yuvası ilkesiyle bir değişken tekrar eder; bu tekrar dizgiyi $uvxyz$ diye beşe böler ve $v$ ile $y$ birlikte pompalanabilir. Önsav, $a^n b^n c^n$ ve $vv$ dillerinin bağlamdan bağımsız olmadığını ispatlamak için kullanıldı. İspatta $p$'ye sayı verilmemesi ve $vxy$'nin bütün olası yerlerinin incelenmesi gerekir. $a^{n!}$ gibi başka örneklere sonraki derslerde devam edileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
