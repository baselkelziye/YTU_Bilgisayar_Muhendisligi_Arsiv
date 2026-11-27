# Ders 6 Genişletilmiş Notu: Pompalama Önsavı (Pumping Lemma) ve Düzenli Olmayan Diller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Dersten Bağlantı: Döngüler ve Güvercin Yuvası İlkesi
- 2. Sonlu Diller Her Zaman Düzenlidir
- 3. Pompalama Önsavının Arkasındaki Fikir
- 4. Pompalama Önsavının İfadesi
- 5. Düzenli Olmadığını İspatlama Yöntemi
- 6. Örnek: $a^mb^n$ Dilinde Yanlış ve Doğru Bölme
- 7. Örnek: İlk, Orta ve Son Sembolü Aynı Olan Dizgiler
- 8. Örnek: $vv^R$ Dili
- 9. Örnek: $a^kb^l$, $k>l$ ve Sınavda Yapılan Hata
- 10. Örnek: $a^nb^lc^{n+l}$
- 11. Örnek: $a^nb^{n \bmod m}$
- 12. Sayılar Arasındaki İlişkiye Bakarak Hızlı Değerlendirme
- 13. Faktöriyel Üslü Diller
- 14. $(ab)^n$ ile $a^nb^n$ Karşılaştırması
- Örnek Sorular

## 1. Geçen Dersten Bağlantı: Döngüler ve Güvercin Yuvası İlkesi

Ders, bir önceki derste görülen iki fikrin hatırlatılmasıyla başlar. Birincisi güvercin yuvası ilkesidir (pigeonhole principle): güvercin sayısı yuva sayısından fazlaysa en az bir yuvada birden fazla güvercin vardır. İkincisi, bir NFA ya da DFA'nın içinde döngü varsa bu makinenin tanıdığı dilin sonsuz olduğudur. Bu derste bu iki fikir birleştirilerek pompalama önsavına (pumping lemma) geçilir.

Hoca önsavın amacını en başta açıkça söyler: önsav bir dilin düzenli **olmadığını** ispatlamak için kullanılır. Bir dilin düzenli olduğunu ispatlamak için kullanılmaz. İspat çelişki (contradiction) tekniğiyle yapılır: dilin düzenli olduğu varsayılır, sonra bu varsayımdan bir çelişki çıkarılır.

## 2. Sonlu Diller Her Zaman Düzenlidir

Hoca önce sınıfa bir soru sorar (ekrandan, 00:15:00): $\Sigma=\{a,b,c,d\}$ alfabesi üzerinde

$$L=\{a,\ ab,\ abc,\ d\}$$

dili düzenli midir? Bir öğrenci "düzenli, çünkü sonlu" diye cevap verir ve hoca bunu doğrular.

### 2.1 NFA'nın Kurulması

Dil sonlu olduğu için onu tanıyan bir NFA doğrudan çizilebilir. Ekrandaki makine şöyledir:

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç) | $a$ | $q_1$ (kabul) |
| $q_1$ | $b$ | $q_2$ (kabul) |
| $q_2$ | $c$ | $q_3$ (kabul) |
| $q_0$ | $d$ | $q_3$ (kabul) |

$a$ okununca $q_1$'e varılır ve $a$ dilin elemanı olduğu için $q_1$ kabul durumudur. $ab$ için $q_2$, $abc$ ve $d$ için $q_3$ kabul durumudur.

### 2.2 DFA'ya Tamamlama

Bu makine NFA'dır, çünkü her durumdan alfabedeki her sembol için bir geçiş yoktur. DFA'ya dönüştürmek için her durumdan dört sembolün her biri için tam bir geçiş bulunmalıdır (alfabenin büyüklüğü 4'tür). Eksik geçişler bir ölü durum $D$'ye (dead state) yönlendirilir:

| Durum | Ölü duruma giden semboller |
|---|---|
| $q_0$ | $b, c$ |
| $q_1$ | $a, c, d$ |
| $q_2$ | $a, b, d$ |
| $q_3$ | $a, b, c, d$ |
| $D$ | $a, b, c, d$ (kendine döner) |

Böylece aynı dili tanıyan hem bir NFA hem bir DFA elde edilir; dil düzenlidir.

> **Hocanın vurgusu:** Dil $L$ sonluysa $L$ düzenlidir. Sonlu bir dilin düzenli olduğunu göstermek için pompalama önsavına gerek yoktur. Önsav sonsuz diller için kullanılır.

## 3. Pompalama Önsavının Arkasındaki Fikir

### 3.1 Uzun Bir Dizginin Yürüyüşü

Slaytta önce küçük bir örnek vardır (ekrandan, 00:05:00). Dört durumlu bir DFA'da ($q_1$ başlangıç, $q_4$ kabul) uzunluğu en az 4 olan $aaaab$ dizgisi okunur. Yürüyüş $q_1 \xrightarrow{a} q_2 \xrightarrow{a} q_3 \xrightarrow{a} q_2 \xrightarrow{a} q_3 \xrightarrow{b} q_4$ biçimindedir. $q_3$ (ve $q_2$) bu yürüyüşte tekrar eder. Dizginin uzunluğu durum sayısından fazla olduğu için bir durumun tekrar etmesi kaçınılmazdır.

### 3.2 Genel Durum

Sonsuz bir düzenli dil $L$ alınır. Dil düzenli olduğu için onu tanıyan bir DFA vardır; dil sonsuz olduğu için bu DFA'da en az bir döngü vardır. DFA'nın durum sayısı $m$ olsun. Dilden uzunluğu $k>m$ olan bir $w=\sigma_1\sigma_2\cdots\sigma_k$ dizgisi alınır.

Güvercin yuvası ilkesi burada şöyle uygulanır: güvercinlerin sayısı dizginin uzunluğu, yuvaların sayısı DFA'daki durum sayısıdır. Dizgi durum sayısından uzunsa bazı durumlar birden fazla kez kullanılır, yani $w$'yu tanırken en az bir döngüden geçilir.

### 3.3 Yürüyüşün Tek Boyutlu Görünümü

Birçok durum tekrar edebilir; ilk tekrar eden durum $q$ diye alınır (ekrandan, 00:25:00). Yürüyüş düz bir çizgi gibi yazılırsa önce birbirinden farklı (unique) durumlar gelir, sonra $q$'nun ilk görülmesi, bir süre sonra $q$'nun ikinci görülmesi ve ardından kabul durumuna giden kısım gelir. Toplam geçiş sayısı $k$'dir ve $k>m$'dir.

Buna göre $w$ üç parçaya bölünür:

- $x$: başlangıç durumundan $q$'nun ilk görülmesine kadar okunan kısım,
- $y$: $q$'dan çıkıp yine $q$'ya dönen döngü kısmı,
- $z$: $q$'dan kabul durumuna kadar okunan kısım.

Böylece $w=xyz$ olur.

### 3.4 İki Gözlem

Birinci gözlem: $q$ ilk tekrar eden durum olduğu için $x$ ve $y$ okunurken ziyaret edilen durumlar (son $q$ hariç) birbirinden farklıdır. Bu yüzden

$$|xy|\le m$$

olur.

İkinci gözlem: döngü en az bir sembol içerir. Örneğin döngü $q$'dan $q$'ya tek bir sembolle dönen bir öz döngü olabilir; bu durumda $|y|=1$'dir. Genel olarak

$$|y|\ge 1$$

olur.

Hoca, $x$'in ya da $z$'nin içinde de geri dönüşler olan daha karmaşık yürüyüşler olabileceğini, ama önsav için yalnız bu basit $xyz$ biçiminin önemli olduğunu belirtir.

### 3.5 Döngüyü Sıfır, İki, Üç Kez Dönmek

$xyz$ kabul edildiğine göre başka dizgiler de kabul edilir:

- Döngü hiç dönülmezse: $xy^0z=x\varepsilon z=xz$. Başlangıçtan $q$'ya gelinir, döngüye girilmeden doğrudan kabul durumuna gidilir. Dolayısıyla $xz\in L$.
- Döngü iki kez dönülürse: $xyyz=xy^2z\in L$ (ekrandan, 00:35:00).
- Üç kez dönülürse: $xy^3z\in L$.
- Genel olarak $i$ kez dönülürse: $xy^iz\in L$.

## 4. Pompalama Önsavının İfadesi

Bu gözlemler bir araya getirilerek önsav ifade edilir:

> $L$ sonsuz bir düzenli dil olsun. Öyle bir $m$ tam sayısı (kritik uzunluk) vardır ki $|w|\ge m$ olan her $w\in L$ dizgisi
> $$w=xyz,\qquad |xy|\le m,\qquad |y|\ge 1$$
> olacak şekilde yazılabilir ve her $i=0,1,2,\dots$ için $xy^iz\in L$ olur.

Kritik uzunluk $m$, sezgisel olarak dili tanıyan DFA'nın durum sayısıdır.

> **Ders sonrası not:** Hoca konuşurken $|xy|$ için "kritik uzunluktan küçük" dedi. Slayttaki ve standart ifadede koşul $|xy|\le m$ ve $|w|\ge m$ biçimindedir.

## 5. Düzenli Olmadığını İspatlama Yöntemi

### 5.1 Adımlar

Slayttaki ispat yöntemi şöyledir:

1. Sonsuz bir $L$ dilinin düzenli olmadığını göstermek isteniyor. Önce tersi varsayılır: $L$ düzenlidir.
2. Pompalama önsavı $L$'ye uygulanır.
3. Önsav kullanılarak bir çelişki elde edilir.
4. Dolayısıyla $L$ düzenli değildir.

Hoca 3. adımın açıklamasının çok önemli olduğunu söyler (ekrandan, 00:40:00):

1. $m$, $L$ için kritik uzunluk olsun.
2. Uzunluk koşulunu sağlayan, yani $|w|\ge m$ olan belirli bir $w\in L$ seçilir.
3. $w=xyz$ yazılır.
4. Bir $i\ne 1$ için $w'=xy^iz\notin L$ olduğu gösterilir.
5. Bu bir çelişkidir, çünkü önsava göre her $i$ için $xy^iz\in L$ olmalıydı.

> **Hocanın vurgusu:** Çelişki için tek bir uygun dizgi ve tek bir $i$ değeri yeterlidir. Ama seçilen $w$ mutlaka dilin elemanı olmalıdır.

### 5.2 Klasik Örnek: $a^nb^n$

$$L=\{a^nb^n : n\ge 0\}$$

dilinin düzenli olmadığı önceki derste "onu tanıyan sonlu bir makine yoktur, gereken durum sayısı sonsuzdur" diye gösterilmişti. Şimdi aynı sonuç önsavla ispatlanır (ekrandan, 00:45:00).

- Dil sonsuzdur, önsav uygulanabilir. Çelişki için $L$ düzenli varsayılır.
- $m$ kritik uzunluk olsun. $w=a^mb^m$ seçilir: $w\in L$ ve $|w|=2m\ge m$.
- $|xy|\le m$ olduğundan $x$ ve $y$ tamamen ilk $m$ sembolün, yani $a$'ların içindedir. Bu yüzden $y=a^k$, $k\ge 1$.
- $i=2$ alınırsa $xy^2z=a^{m+k}b^m$ olur. $a$ sayısı $b$ sayısından fazladır, bu dizgi $L$'de değildir.
- Önsava göre dilde olması gerekirdi; çelişki. Dolayısıyla $L$ düzenli değildir.

Hoca yöntemi Türkçe olarak da özetler: dilden bir dizgi seçilir, üç parçaya ayrılır, sonra pompalanır. Pompalamayla elde edilen bütün dizgilerin dilin elemanı olması gerekir; en az biri eleman değilse çelişki oluşur ve dil düzenli değildir.

Aradan sonra hoca bir kez daha hatırlatır: düzenli diller NFA ve DFA'ların tanıdığı dillerdir; bir dilin düzenli olmadığı biliniyorsa o dil bu kümenin dışındadır.

> **Ders sonrası not:** Hoca bu sırada (yaklaşık 01:02:40) düzenli dillerin "düzenli olmayan dillerin alt kümesi" olduğunu söyledi. Doğrusu: düzenli diller bütün dillerin bir alt kümesidir; düzenli olmayan diller bu kümenin dışında kalan dillerdir. İki küme ayrıktır.

## 6. Örnek: $a^mb^n$ Dilinde Yanlış ve Doğru Bölme

### 6.1 Dil ve İlk Deneme

Hoca slayt dosyasını bulamayınca örnekleri tablette kendisi üretir (ekrandan, 01:10:00):

$$L=\{a^mb^n : m,n\ge 0\}$$

Dil sonsuzdur. Düzenli olup olmadığı bilinmiyormuş gibi davranılır ve düzenli olduğu varsayılır. $w=aaaabb\in L$ seçilir ve şöyle bölünür: $x=aa$, $y=aab$, $z=b$.

- $xy^0z=aab\in L$ olduğu için birinci kontrol tamam.
- $|xy|=5$; kritik uzunluk $m=6$ alınırsa $|xy|<m$.
- $|y|=3\ge 1$.

Sonra pompalanır: $xy^2z=aa\cdot aab\cdot aab\cdot b=aaaabaabb$. Bu dizgide $b$'den sonra yine $a$ geldiği için dilde değildir. Bu "çelişki"den dilin düzenli olmadığı sonucuna varılır (ekrandan, 01:15:00).

### 6.2 Hata Nerede?

Hoca sınıfa "emin misiniz?" diye sorar ve bunun yanlış bir çözüm olduğunu söyler, çünkü bu dil için NFA ve DFA vardır. Bir öğrenci $x,y,z$'nin yanlış seçilmiş olabileceğini söyler. Hoca önce kritik uzunluk seçimine dikkat çeker, sonra şunu söyler: bu tür problemlerde pompalanan kısmın uzunluğunu mümkün olduğunca küçük seçin. Burada $y$'nin uzunluğu 3 seçildi, 1 seçilebilirdi.

### 6.3 Doğru Bölme

Aynı $w=aaaabb$ için $x=aaa$, $y=a$, $z=bb$ alınır (ekrandan, 01:20:00):

- $xz=aaabb\in L$.
- $|xy|=4\le m$ ve $|xyz|=6>m$; buna göre $m=4$ ya da $m=5$ olabilir.
- $xy^2z=aaa\cdot aa\cdot bb\in L$.
- $xy^3z=aaa\cdot aaa\cdot bb\in L$.
- Genel olarak her $i$ için $xy^iz=a^{3+i}b^2\in L$.

Çelişki çıkmaz. Hoca bunun doğru uygulama olduğunu ve dilin düzenli olduğunu söyler; kritik uzunluğu seçerken çok dikkatli olunması gerektiğini vurgular.

Hatanın asıl nedeni dersin ilerleyen kısmında (Bölüm 9.3) açıkça söylenir: ilk denemede $y=aab$ hem $a$ desenini hem $b$ desenini içeriyordu.

> **Ders sonrası not:** Pompalama önsavı "böyle bir bölme vardır" der; bölmeyi ispatı yapan kişi seçemez. Bir dilin düzenli olmadığını göstermek için $|xy|\le m$ ve $|y|\ge 1$ koşullarını sağlayan **her** olası bölmede bir $i$ için $xy^iz\notin L$ olduğu gösterilmelidir. Bu yüzden 6.1'deki tek bir kötü bölme hiçbir şey ispatlamaz. Aynı nedenle 6.3'te çelişki çıkmaması da dilin düzenli olduğunu ispatlamaz; $a^mb^n$'nin düzenli olduğu, onu tanıyan bir NFA (Bölüm 9.3) ya da $a^*b^*$ düzenli ifadesiyle gösterilir. Derste "y'yi deseni bozmadan seçmek" diye anlatılan kural bu genel koşulun sezgisel bir karşılığı olarak okunmalıdır.

## 7. Örnek: İlk, Orta ve Son Sembolü Aynı Olan Dizgiler

### 7.1 Dil

$$L=\{w\in\{a,b\}^* : w \text{ dizgisinin ilk, orta ve son sembolleri aynıdır}\}$$

İspat yine dilin düzenli olduğu varsayılarak başlar (ekrandan, 01:25:00). $w\in L$ seçilecek, $w=xyz\in L$ yazılacak ve $xy^0z=xz\in L$ olacak şekilde bölünecektir.

### 7.2 Dizgi ve Bölme

Hoca önce $0$ ve $1$ ile bir örnek yazar, sonra alfabenin $\{a,b\}$ olduğunu hatırlayıp düzeltir. Seçilen dizgi (ekrandan, 01:30:00):

$$w=abaabaa\in L$$

Uzunluk 7'dir; ilk sembol $a$, ortadaki (4.) sembol $a$, son sembol $a$'dır. Bölme: $x=a$, $y=baab$, $z=aa$. Hoca $y$'yi, çıkarıldığında kalan dizgi yine dilde olacak şekilde seçtiğini belirtir.

- $|xy|=5\le m$ ve $|xyz|=7>m$; kritik uzunluk 5 ya da 6 olabilir.
- $xy^0z=xz=aaa\in L$ (ilk, orta, son hepsi $a$).
- $xyz\in L$.

### 7.3 Pompalama

$$xy^2z=a\cdot baab\cdot baab\cdot aa=abaabbaabaa$$

Bu dizginin uzunluğu 11'dir ve ortadaki 6. sembolü $b$'dir (ara adım eklendi: hoca önce yanlış konumu orta sanmış, sonra sayarak düzeltmiştir). İlk ve son sembol $a$ iken orta sembol $b$ olduğundan dizgi dilde değildir. Hoca bu çelişkiden dilin düzenli olmadığı sonucuna varır. Bu örnekte $y$ ortadan alındığı için desen (ilk-orta-son ilişkisi) bozulmadan pompalanmıştır; hoca bunu ileride iyi bir örnek olarak tekrar gösterir.

> **Ders sonrası not:** Bölüm 6'daki not burada da geçerlidir: tam bir ispat için yalnız bu bölme değil, koşulları sağlayan her bölme ele alınmalıdır. Sonucun kendisi (dilin düzenli olmaması) büyük olasılıkla doğrudur, çünkü orta sembolü bulmak dizginin uzunluğunu saymayı gerektirir.

## 8. Örnek: $vv^R$ Dili

### 8.1 Dili Anlamak

$$L=\{w\in\{a,b\}^* : w=vv^R,\ v\in\{a,b\}^*\}$$

$v^R$, $v$'nin tersidir; dolayısıyla dil, çift uzunluklu ve simetrik (palindrom) dizgilerden oluşur. Hoca örneklerle dili tanıtır (ekrandan, 01:35:00):

| Dizgi | Dilde mi? |
|---|---|
| $ab$ | Hayır |
| $aabb$ | Hayır |
| $abba$ | Evet |
| $aaaa$ | Evet |
| $aabaa$ | Hayır |
| $baab$ | Evet |
| $babbab$ | Evet |
| $baabaa$ | Hayır |

> **Hocanın vurgusu:** Bir dilin düzenli olmadığını ispatlamaya başlamadan önce dili çok iyi anlamalısınız. Önce desenini bulun.

### 8.2 Dizgi Seçimi

Hoca önce $w=a^kb^kb^ka^k$ yazar ($m$ harfi kritik uzunlukla karışmasın diye $k$ kullanır). Bu $v=a^kb^k$ ve $v^R=b^ka^k$ olduğu için dildedir ve $|w|=4k$'dır. Sonra, böyle durumlarda somut sayılarla çalışmanın daha anlaşılır olduğunu söyleyerek dört $a$, iki $b$, iki $b$, dört $a$ alır (ekrandan, 01:45:00):

$$w=aaaabbbbaaaa,\qquad |w|=12$$

### 8.3 Bölme ve Pompalama

$x=aaa$, $y=a$, $z=bbbbaaaa$ seçilir.

- $|xy|=4\le m$, $|w|=12>m$; buna göre $m$ 4 ile 11 arasında bir değer olabilir.
- $xyz\in L$.
- $xy^0z=aaabbbbaaaa$: uzunluğu 11, yani tektir; simetrik değildir ve dilde değildir.

Çelişki elde edilir, dil düzenli değildir. Hoca sezgiyi de ekler: bu dilde bir yarıdaki sembolleri sayıp diğer yarıyla karşılaştırmak gerekir; böyle ek bir sayma koşulu dili düzenli olmaktan çıkarır.

## 9. Örnek: $a^kb^l$, $k>l$ ve Sınavda Yapılan Hata

### 9.1 Dili Birlikte Kurmak

Hoca $a^kb^l$ yazıp $k$ ile $l$ arasındaki ilişkiyi sınıfa sorar. Bir öğrenci "$k$ büyüktür $l$" önerir:

$$L=\{a^kb^l : k>l\ge 0\}$$

Dili anlamak için örnekler: $a$, $aa$, $aab$, $aaa$ dildedir; $aabb$ ve $aaabbb$ dilde değildir, çünkü $a$ sayısı $b$ sayısından büyük olmalıdır (ekrandan, 01:50:00).

### 9.2 Dizgi ve İki Bölme

$$w=aaaaabb\in L,\qquad |w|=7$$

Birinci bölmede pompalanan kısım $a$'ların içinden seçilir (ekrandan, 01:55:00): $x=aaaa$, $y=a$, $z=bb$. $xz=aaaabb$ ($4>2$), $xyz$, $xy^2z$, $xy^3z$, ... hepsi dildedir; $a$ sayısı arttıkça $k>l$ koşulu bozulmaz. Bu bölmeden bir sonuç çıkmaz.

İkinci bölmede pompalanan kısım $b$'lerin içinden seçilir: $x=aaaaa$, $y=b$, $z=b$. Burada $|xy|=6$, $|w|=7$ olduğundan $m=6$'dır.

| $i$ | $xy^iz$ | $a$ sayısı | $b$ sayısı | Dilde mi? |
|---|---|---|---|---|
| 0 | $a^5b$ | 5 | 1 | Evet |
| 1 | $a^5b^2$ | 5 | 2 | Evet |
| 2 | $a^5b^3$ | 5 | 3 | Evet |
| 3 | $a^5b^4$ | 5 | 4 | Evet |
| 4 | $a^5b^5$ | 5 | 5 | Hayır |

$i=4$ için koşul bozulur; dil düzenli değildir.

> **Hocanın vurgusu:** $x,y,z$'yi oluştururken saymalara dikkat edin. Bu dilde iki sayma vardır: $a$'lar sayılır, $b$'ler sayılır ve $a$'ların sayısı $b$'lerin sayısından büyük olmalıdır. Pompalanacak kısım ya soldaki sayma bölgesinde ya sağdaki sayma bölgesinde olmalıdır.

### 9.3 En Büyük Hata

Hoca sınavda bazı öğrencilerin yaptığı bir hatayı gösterir ve bu hataya düşülmemesini ister. Aynı $w$ için $y$, $a$'larla $b$'lerin sınırından seçilir: $x=aaaa$, $y=ab$, $z=b$. $xz$ ve $xyz$ dildedir. Ama

$$xy^2z=aaaa\cdot ab\cdot ab\cdot b$$

yazılınca $b$'den sonra yine $a$ geldiği için dizgi dilde değildir ve "dil düzenli değildir" denir. Bu akıl yürütme yanlıştır.

Neden yanlış olduğu düzenli bir dille gösterilir (ekrandan, 02:00:00):

$$L_2=\{a^mb^n : m,n\ge 0\}$$

$w=aaaabb\in L_2$ için $x=aaa$, $y=ab$, $z=b$ seçilirse $xz\in L_2$, $xyz\in L_2$, ama $xy^2z=aaa\cdot abab\cdot b\notin L_2$ olur. Aynı yanlış akıl yürütmeyle $L_2$'nin de düzenli olmadığı sonucu çıkardı. Oysa $L_2$ düzenlidir; onu tanıyan bir NFA hemen çizilebilir:

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç) | $a$ | $q_0$ |
| $q_0$ | $\varepsilon$ | $q_1$ |
| $q_1$ (kabul) | $b$ | $q_1$ |

$q_0$'daki öz döngü bütün $a$'ları ($a^*$), $q_1$'deki öz döngü bütün $b$'leri okur. Hata şudur: dilde bir $a$ deseni ve bir $b$ deseni vardır; $y$ bu iki deseni karıştıracak şekilde seçilmemelidir. Bölüm 7'deki örnekte ise $y$ ortadan alınmış ve desen bozulmamıştı.

> **Hocanın vurgusu:** $y$'yi seçerken deseni (sayma düzenini) bozmayacak şekilde seçeceksiniz. $y$ ya $a$'ların sayıldığı kısımdan ya da $b$'lerin sayıldığı kısımdan oluşturulmalıdır, ikisinden birden değil. Dil içindeki bütün durumları araştırmanız gerekir.

## 10. Örnek: $a^nb^lc^{n+l}$

### 10.1 Dili Anlamak

$$L=\{a^nb^lc^{n+l} : n,l\ge 0\}$$

Hoca örneklerle deseni çıkarır (ekrandan, 02:20:00):

| Dizgi | Dilde mi? |
|---|---|
| $ac$ | Evet |
| $bc$ | Evet |
| $\varepsilon$ | Evet |
| $abc$ | Hayır |
| $abcc$ | Evet |
| $abccc$ | Hayır |
| $aabccc$ | Evet |
| $abbccc$ | Evet |
| $aaaccc$ | Evet |
| $aaacccc$ | Hayır |

$a$'lar ve $b$'ler üzerinde sayma vardır; $c$'lerin sayısı ikisinin toplamına eşittir.

### 10.2 Dizgi ve Bölme Seçimi

$$w=a^6b^3c^9\in L$$

Ekranda iki farklı bölme renkle gösterilir: kırmızı bölmede $y$ $a$'ların içindedir; mor bölmede $x$ bütün $a$'ları kapsar ve $y$ $b$'lerle $c$'lerin sınırına yayılır. <!-- BELİRSİZ: kırmızı ve mor bölmelerdeki parçaların tam uzunlukları karede net okunmuyor. --> Hoca hangisinin doğru olduğunu sorar. Bir öğrenci kırmızıyı seçer.

**Soru:** Mor bölme seçilebilir mi? **Cevap:** Bir öğrenci seçilemeyeceğini söyler: $y$ hem $b$ hem $c$ içerdiğinden $y^2$ alınınca $bbccbbcc$ gibi bir sıra oluşur, desen hemen bozulur. Hoca bunu doğrular: deseni bozarak "eleman değildir" denemez, karar deseni bozmadan verilmelidir.

Hoca açıklar: bu dilde ya $a$'ların ya $b$'lerin sayısı artar, $c$'lerin sayısı da onlara göre artar. Aynı anda hem $b$'nin hem $c$'nin sayısını artıran bir $y$ seçmek bu düzeni karıştırır.

### 10.3 Sonuç

$y$ yalnız $a$'lardan seçilir. Pompalanınca $a$ sayısı değişir ama $c$ sayısı değişmez; $xy^iz$ ($i\ne 1$) için $n+l$ toplamı $c$ sayısına eşit olmaz ve dizgi dilde olmaz. Dil düzenli değildir.

## 11. Örnek: $a^nb^{n \bmod m}$

### 11.1 Dil

Hoca bu soruyu "kendimiz üretiyoruz" diyerek anında kurar (ekrandan, 02:25:00):

$$L=\{a^nb^{\,n \bmod m} : n\ge 0,\ 0<m<4\}$$

Sonra işi basitleştirmek için $m=2$ alır. Bu durumda $n$ tekse $n \bmod 2=1$ ve dizgi $a^nb$; $n$ çiftse $n \bmod 2=0$ ve dizgi $a^n$ olur. Örnekler: $\varepsilon$, $ab$, $aa$, $aaab$ dildedir; $aab$ dilde değildir. <!-- BELİRSİZ: altyazıda $aaaa$ için "eleman değil" deniyor; $n=4$ için $4 \bmod 2=0$ olduğundan $aaaa$ dilde olmalıdır, büyük olasılıkla Whisper bozması. -->

### 11.2 Kapanma Özellikleriyle Düzenlilik

Dil iki parçaya ayrılır (ekrandan, 02:30:00):

$$L_{odd}=\{a^{2k+1} : k\ge 0\},\qquad L_{even}=\{a^{2k} : k\ge 0\}$$

$$L=L_{odd}\cdot\{b\}\ \cup\ L_{even}$$

$L_{odd}$ ve $L_{even}$ düzenlidir (yalnız $a$'lardan oluşur ve tek/çift düzeni sonlu bir makineyle izlenir). Düzenli bir dilin $\{b\}$ ile birleştirmesi düzenlidir, iki düzenli dilin birleşimi de düzenlidir. Dolayısıyla $L$ düzenlidir.

### 11.3 Pompalamayla Gösterim

Hoca aynı sonucu pompalamayla da "görmek" ister, ama önce önsavın düzenli olduğunu değil, olmadığını ispatlamak için kullanıldığını yeniden hatırlatır. Tek sayıda $a$ ve bir $b$ içeren $w=aaaaab$ alınır. $y$'nin uzunluğu 2 seçilir; $xz$, $xyz$, $xy^2z$, $xy^3z$ hepsi dilde kalır, çünkü $a$ sayısının tekliği korunur.

**Soru (hocanın sınıfa sorusu):** $y$'nin uzunluğu 1 seçilebilir miydi? **Cevap:** Hayır; o zaman tek sayıdaki $a$'lar çift olur ve düzen bozulur. $y$'yi deseni bozmadan seçmek gerekir.

Çift durum için dört $a$'dan oluşan dizgi ($aaaa$) de aynı biçimde incelenir; yine uzunluğu 2 olan bir $y$ ile bütün pompalamalar dilde kalır.

> **Hocanın vurgusu:** Bir dilin düzenli olup olmadığını anlamak için sayılar arasındaki bağıntıya bakacaksınız.

> **Ders sonrası not:** Pompalamada çelişki çıkmaması dilin düzenli olduğunu ispatlamaz (Bölüm 6'daki nota bakın). Bu örnekte düzenliliğin geçerli gerekçesi 11.2'deki kapanma özellikleri gerekçesidir.

## 12. Sayılar Arasındaki İlişkiye Bakarak Hızlı Değerlendirme

Ekran paylaşımı bir süre durdurulup yeniden başlatıldıktan sonra hoca, sayılar arasındaki bağıntıya bakarak hızlı karar verme alıştırmaları yapar (ekrandan, 02:35:00).

- $L=\{a^nb^nc^n : n\ge 0\}$: $a$ ile $b$'nin sayısı eşit, $b$ ile $c$'nin sayısı eşit olmalı. Sayılar arasında bağıntı vardır; dil düzenli değildir.
- $L=\{a^nb^m : m,n\ge 0\}$: $a$ ile $b$ sayıları arasında hiçbir bağıntı yoktur; dil düzenlidir.
- $L=\{a^nb^ma^n\}$: baştaki ve sondaki $a$ sayıları eşit olmak zorundadır; dil düzenli değildir.
- Hoca bir dil daha yazıp sınıfa sorar; bir öğrencinin cevabından sonra $a$'ların sayısıyla $b$'lerin sayısı arasında bağlantı olmadığı için düzenli olduğu sonucuna varılır. <!-- BELİRSİZ: bu dilin tanımı ekranda görülmüyor, altyazıdan da çıkarılamıyor. -->

> **Ders sonrası not:** "Sayılar arasında bağıntı varsa düzenli değildir" kuralı sezgisel bir başlangıç noktasıdır, kesin bir ölçüt değildir. Örneğin $\{(ab)^n\}$ dilinde $a$ ve $b$ sayıları hep eşittir ama dil düzenlidir (Bölüm 14). Kesin karar için ispat (önsav ya da makine kurma) gerekir.

### 12.1 Ödev Niteliğinde Bırakılan Soru

Hoca şu dili yazar (ekrandan, 02:40:00):

$$L=\{a^{\,n \bmod m}\,b^{\,m \bmod n} : m,n>1\}$$

ve sınıfla birlikte birkaç değer dener. $m=n$ ise iki üs de 0 olur, $\varepsilon$ elde edilir. Ekranda $m=2, n=1$ ve $m=3, n=2$ denemeleri vardır; altyazıda $a$, $b$, $aa$, $aab$, $abb$ gibi dizgilerin üretildiği, $ab$ dizgisinin ise hiç elde edilemediği (eşitliği kabul etmiyor gibi göründüğü) konuşulur. Bir öğrenci $m$ ile $n$'den büyük olana göre iki durum ayırıp iki düzenli dilin birleşimi gibi düşündüğünü söyler. Hoca soruyu çözmeden bırakır ve düzenli olup olmadığının araştırılmasını ister. Çözüm aşağıda "Örnek Sorular" bölümündedir.

## 13. Faktöriyel Üslü Diller

### 13.1 $b^{m!}$

$$L=\{b^{m!} : m\ge 0\}$$

Hoca dilin makinesini kurmayı dener (ekrandan, 02:45:00). $0!=1$ olduğu için boş dizgi dilde değildir; ilk kabul bir $b$'den sonradır. $1!=1$, $2!=2$, $3!=6$, $4!=24$, ... Kabul edilen ardışık uzunluklar arasındaki fark sürekli büyür: 2'den sonra 6'ya kadar 4 adım, sonra 24'e kadar 18 adım atlanmalıdır. Her yeni kabul noktası için yeni durumlar gerekir; aynı durum tekrar kullanılamaz ve durum sayısı sonsuza gider. Bu yüzden onu tanıyan bir NFA ya da DFA yoktur; dil düzenli değildir.

### 13.2 $b^{m! \bmod 3}$

$$L=\{b^{\,m! \bmod 3} : m\ge 0\}$$

Hesap (ekrandan, 02:50:00):

| $m$ | $m!$ | $m! \bmod 3$ |
|---|---|---|
| 0 | 1 | 1 |
| 1 | 1 | 1 |
| 2 | 2 | 2 |
| 3 | 6 | 0 |
| 4 | 24 | 0 |
| 5 | 120 | 0 |

$m\ge 3$ için $m!$ içinde 3 çarpanı bulunduğundan kalan hep 0'dır. Hoca önce dili $\{b, bb\}$ diye yazar.

**Soru:** $3!$, $4!$, $5!$ gibi 3'ün katı olan faktöriyellerde üs 0 olduğuna göre boş dizgi de dilin elemanı olmaz mı? **Cevap:** Hoca öğrencinin haklı olduğunu söyler ve düzeltir: dilde $\varepsilon$ da vardır.

$$L=\{\varepsilon,\ b,\ bb\}$$

Dil sonludur, dolayısıyla düzenlidir. Hoca bu düzeltmeyi örnek göstererek sınavda benzer gözden kaçırmalara dikkat edilmesini ister.

## 14. $(ab)^n$ ile $a^nb^n$ Karşılaştırması

Son örnek iki dili karşılaştırır (ekrandan, 02:55:00):

$$L_1=\{(ab)^n : n\ge 0\},\qquad L_2=\{a^nb^n : n\ge 0\}$$

**Soru:** $L_1=L_2$ mi? **Cevap:** Bir öğrenci aynı olmadığını söyler: $L_1$ $ab\,ab\,ab\cdots$ biçiminde ilerler, $L_2$ önce bütün $a$'ları sonra bütün $b$'leri içerir. Ekrandaki örnekler:

- $aabb\in L_2$, $aabb\notin L_1$,
- $abab\in L_1$, $abab\notin L_2$.

Her iki dilde de $a$ ve $b$ sayıları eşittir. Ama $L_2$'de $a$ bloğunun uzunluğunu hatırlayıp $b$ bloğuyla karşılaştırmak gerekir; $L_1$'de ise yalnız $ab$ biriminin tekrar etmesi gerekir. Bu yüzden $L_1$ düzenlidir, $L_2$ düzenli değildir.

$L_1$'in makinesi hemen kurulur: başlangıç durumundan $a$ ile bir ara duruma, oradan $b$ ile kabul durumuna gidilir; kabul durumundan $\varepsilon$ ile başa dönülür. Bu bir NFA'dır, dolayısıyla $L_1$ düzenlidir. $L_2$ için böyle bir NFA çizilemez.

> **Ders sonrası not:** $n=0$ için $\varepsilon\in L_1$'dir. Derste anlatılan makinede başlangıç durumu kabul durumu değilse $\varepsilon$ kabul edilmez; başlangıç durumunun da kabul durumu yapılması (ya da başlangıçtan kabul durumuna bir $\varepsilon$ geçişi eklenmesi) gerekir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $\Sigma=\{a,b,c,d\}$ üzerinde $L=\{a, ab, abc, d\}$ düzenli midir? Bir DFA kurun.

> **Çözüm:** Dil sonlu olduğu için düzenlidir. NFA: $q_0\xrightarrow{a}q_1$, $q_1\xrightarrow{b}q_2$, $q_2\xrightarrow{c}q_3$, $q_0\xrightarrow{d}q_3$; $q_1,q_2,q_3$ kabul. DFA için eksik geçişler ölü durum $D$'ye yönlendirilir (Bölüm 2.2'deki tablo).

**Soru 2** (ekrandan, 00:45:00): Pompalama önsavıyla $L=\{a^nb^n : n\ge 0\}$ dilinin düzenli olmadığını gösterin.

> **Çözüm:** $w=a^mb^m$; $|xy|\le m$ olduğundan $y=a^k$, $k\ge 1$. $xy^2z=a^{m+k}b^m\notin L$; çelişki (Bölüm 5.2).

**Soru 3** (ekrandan, 01:10:00 ve 01:20:00): $L=\{a^mb^n : m,n\ge 0\}$ için $w=aaaabb$, $x=aa$, $y=aab$, $z=b$ bölmesiyle "dil düzenli değildir" sonucu doğru mudur?

> **Çözüm:** Hayır. $L$ düzenlidir ($a^*b^*$). $y=aab$ iki deseni karıştırır; $x=aaa$, $y=a$, $z=bb$ alınınca her $i$ için $xy^iz=a^{3+i}b^2\in L$ olur (Bölüm 6).

**Soru 4** (ekrandan, 01:25:00): İlk, orta ve son sembolü aynı olan $\{a,b\}$ dizgilerinin dili düzenli midir?

> **Çözüm:** Derste $w=abaabaa$, $x=a$, $y=baab$, $z=aa$ ile $xy^2z=abaabbaabaa$ elde edildi; orta sembol $b$ olduğu için dilde değildir. Hoca dilin düzenli olmadığı sonucuna vardı (Bölüm 7).

**Soru 5** (ekrandan, 01:35:00): $L=\{vv^R : v\in\{a,b\}^*\}$ düzenli midir?

> **Çözüm:** $w=aaaabbbbaaaa$, $x=aaa$, $y=a$; $xy^0z=aaabbbbaaaa$ tek uzunluklu olduğundan dilde değildir. Dil düzenli değildir (Bölüm 8).

**Soru 6** (derste sözlü, 01:46:28; ekrandan, 01:50:00): $L=\{a^kb^l : k>l\ge 0\}$ düzenli midir?

> **Çözüm:** $w=a^5b^2$, $y=b$ seçilince $xy^4z=a^5b^5\notin L$. Dil düzenli değildir (Bölüm 9.2).

**Soru 7** (ekrandan, 02:20:00): $L=\{a^nb^lc^{n+l}\}$ için ekrandaki iki bölmeden (kırmızı ve mor) hangisi uygundur?

> **Çözüm:** Kırmızı; $y$ yalnız $a$'lardan oluşur. Mor bölmede $y$ hem $b$ hem $c$ içerir ve pompalama deseni bozar. $y$ yalnız $a$'lardan seçilince $c$ sayısı değişmediği için çelişki çıkar; dil düzenli değildir (Bölüm 10).

**Soru 8** (ekrandan, 02:25:00 ve 02:30:00): $m=2$ için $L=\{a^nb^{n \bmod m}\}$ düzenli midir?

> **Çözüm:** $L=L_{odd}\cdot\{b\}\cup L_{even}$; düzenli dillerin birleştirme ve birleşimi düzenli olduğundan $L$ düzenlidir (Bölüm 11).

**Soru 9** (ekrandan, 02:40:00): $L=\{a^{\,n \bmod m}\,b^{\,m \bmod n} : m,n>1\}$ düzenli midir?

> **Çözüm (derste verilmedi):** $p=n \bmod m$, $q=m \bmod n$ olsun. $n<m$ ise $p=n$ ve $q<n=p$; $m<n$ ise $q=m$ ve $p<m=q$; $m=n$ ise $p=q=0$. Yani $p=q$ yalnız $p=q=0$ iken olur. Tersine, $p>q\ge 0$ ve $p\ge 2$ için $n=p$, $m=p+q$ seçilirse $a^pb^q$ elde edilir; simetrik olarak $q>p$ durumu da elde edilir. $2\le m,n<40$ aralığında python ile yapılan taramada dil $\{\varepsilon\}\cup\{a^pb^q : p\ne q\}$ kümesinden yalnız $a$ ve $b$ dizgileri çıkarılmış hâliyle örtüştü (koşul $m,n\ge 1$ olsaydı $a$ ve $b$ de dilde olurdu). Dil düzenli değildir: düzenli olsaydı, düzenli dillerin tümleme ve kesişim altında kapalı olmasından $a^*b^*\cap\overline{L}=\{a^nb^n : n\ge 1\}\cup\{a,b\}$ de düzenli olurdu; bundan sonlu sayıda dizgi çıkarılarak $\{a^nb^n : n\ge 1\}$ elde edilir ve bu dilin düzenli olmadığı bilinir. Çelişki.

**Soru 10** (ekrandan, 02:45:00): $L=\{b^{m!} : m\ge 0\}$ düzenli midir?

> **Çözüm:** Hayır. Kabul edilen ardışık uzunluklar arasındaki fark ($1, 2, 6, 24, \dots$) sınırsız büyür; sonlu sayıda durumla tanınamaz (Bölüm 13.1).

**Soru 11** (ekrandan, 02:50:00): $L=\{b^{\,m! \bmod 3} : m\ge 0\}$ düzenli midir?

> **Çözüm:** $L=\{\varepsilon, b, bb\}$; sonlu olduğu için düzenlidir (Bölüm 13.2).

**Soru 12** (ekrandan, 02:55:00): $L_1=\{(ab)^n\}$ ve $L_2=\{a^nb^n\}$ aynı mıdır? Hangisi düzenlidir?

> **Çözüm:** Aynı değildir ($aabb\in L_2\setminus L_1$, $abab\in L_1\setminus L_2$). $L_1$ düzenlidir (NFA'sı vardır), $L_2$ düzenli değildir (Bölüm 14).

## Dersin Toparlaması

Bu derste düzenli dillerin sınırını çizen ilk araç olan pompalama önsavı öğrenildi. Önce sonlu dillerin her zaman düzenli olduğu, bir NFA'nın ölü durumla DFA'ya tamamlanmasıyla gösterildi. Sonra sonsuz düzenli bir dili tanıyan DFA'da güvercin yuvası ilkesi gereği bir döngü bulunduğu, uzun bir dizginin $xyz$ diye üçe bölünebildiği ve döngünün istendiği kadar dönülebildiği görüldü; buradan $|xy|\le m$, $|y|\ge 1$ ve her $i$ için $xy^iz\in L$ koşulları çıktı. Önsavın çelişki yoluyla bir dilin düzenli olmadığını ispatlamak için kullanıldığı $a^nb^n$, $vv^R$, $a^kb^l$ ($k>l$) ve $a^nb^lc^{n+l}$ örnekleriyle uygulandı.

Dersin pratik vurgusu, dili önce örneklerle anlamak ve pompalanacak $y$ parçasını sayma desenini karıştırmadan seçmekti; $y$'nin iki deseni birden içermesi, düzenli bir dil için bile yanlışlıkla "düzenli değil" sonucuna götürür. Son bölümde sayılar arasındaki bağıntıya bakarak hızlı değerlendirme yapıldı; $a^nb^{n \bmod 2}$ gibi dillerin kapanma özellikleriyle düzenli olduğu, $b^{m!}$ dilinin düzenli olmadığı, $b^{m! \bmod 3}$ dilinin ise sonlu olduğu için düzenli olduğu gösterildi. $a^{n \bmod m}b^{m \bmod n}$ dilinin düzenli olup olmadığı bir sonraki derste çözülmek üzere bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
