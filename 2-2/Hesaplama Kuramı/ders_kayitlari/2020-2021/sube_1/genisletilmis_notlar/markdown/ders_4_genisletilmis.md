# Ders 4 Genişletilmiş Notu: NFA ve DFA Denkliği, NFA'dan DFA'ya Dönüşüm ve Düzenli Dillerin Kapanma Özellikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. NFA ile DFA Arasındaki Fark (Tekrar)
- 2. Otomatlar Nerede Kullanılır?
- 3. Genişletilmiş Geçiş Fonksiyonu
- 4. NFA'nın Dili ve Kabul Koşulu
- 5. Makinelerin Denkliği
- 6. Teorem: NFA'lar Düzenli Dilleri Kabul Eder
- 7. NFA'dan DFA'ya Dönüşüm
- 8. Düzenli Dillerin Kapanma Özellikleri
- 9. Kesişim ve Kartezyen Çarpım Yapısı
- 10. Düzenli İfadelere Giriş
- Örnek Sorular

## 1. NFA ile DFA Arasındaki Fark (Tekrar)

Ders, geçen hafta görülen deterministik olmayan sonlu otomatların (NFA, non-deterministic finite automaton) kısa bir tekrarıyla başlar. Temel ayrım şudur: deterministik sonlu otomatta (DFA) her durumdan çıkan geçişlerin sayısı alfabenin büyüklüğüne eşittir. NFA'da bu eşitlik aranmaz; bir durumdan bir sembol için hiç geçiş olmayabilir ya da birden fazla geçiş olabilir.

### 1.1 Çıkış Geçişlerini Saymak

Hoca bu ayrımı bir örnek üzerinde gösterir (ekrandan, 00:10:00). Alfabe $\Sigma=\{0,1\}$, durumlar $q_0, q_1, q_2$'dir. Geçişler:

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç, kabul) | $1$ | $q_1$ |
| $q_0$ | $\varepsilon$ | $q_2$ |
| $q_1$ | $0$ | $q_0$ |
| $q_1$ | $0, 1$ | $q_2$ |

Sayım yapılırken iki kural uygulanır. Birincisi, bir okun üzerinde iki sembol yazıyorsa ($0,1$ gibi) bu iki ayrı geçiş sayılır. İkincisi, $\varepsilon$ geçişi bir çıkış geçişi sayılmaz. Hoca bunu "yalnızca bir bağlantı" diye anlatır: $q_0$'dayken aynı anda $q_2$'de de bulunursunuz. Bu durumda $q_0$'dan bir, $q_1$'den üç çıkış geçişi vardır. $q_0$'daki sayı alfabenin büyüklüğüne (2) eşit olmadığı için makine NFA'dır.

Bu makinenin dili $L(M)=\{\varepsilon, 10, 1010, 101010, \dots\}=\{10\}^*$'dır. $q_2$ dile hiçbir katkı yapmaz; slaytta "gereksiz durum" (redundant state) diye işaretlidir. Slayttaki uyarı da önemlidir: başlangıç durumu $q_0$ aynı zamanda kabul durumuysa boş dizgi otomatın tanıdığı dilin elemanıdır.

### 1.2 Tek Durumlu Basit Otomatlar

Sonraki slaytta iki not yer alır (ekrandan, 00:15:00). Birincisi, $\varepsilon$ sembolü giriş şeridinde hiçbir zaman görünmez; $\varepsilon$ bir sembol değil, boş dizgidir. İkincisi, en basit iki otomat gösterilir:

- $M_1$: tek durum $q_0$, kabul durumu değil, hiç geçiş yok. $L(M_1)=\{\}$.
- $M_2$: tek durum $q_0$, kabul durumu, hiç geçiş yok. $L(M_2)=\{\varepsilon\}$.

Hoca "Bu NFA mı DFA mı?" diye sorar. Bir öğrenci DFA cevabını verir ve gerekçesini söyler: alfabe boş kümeyse ve hiç çıkış yoksa her durumdaki çıkış sayısı (0) alfabenin büyüklüğüne (0) eşittir. Hoca bu noktayı çok iyi bir gözlem olarak över ve kuralı şöyle bağlar: alfabe boşsa $M_1$ ve $M_2$ DFA'dır, alfabe boş değilse NFA'dır. Yani karar vermek için alfabenin büyüklüğüne bakmak gerekir.

### 1.3 DFA'lar NFA'ların Alt Kümesidir

Her DFA bir NFA olarak düşünülebilir, ama her NFA bir DFA değildir. Hoca bunu Türkçe de açıklar: evrendeki bütün olası DFA makinelerini bir kümeye koyduğunuzu düşünün. Bu küme, bütün NFA makinelerinden oluşan kümenin alt kümesidir.

**Soru:** Tam tersi olması gerekmez mi? DFA'da daha çok dallanma yok mu?

**Cevap:** Hayır. İkili alfabede DFA'da çıkış geçişi sayısı her durumda tam 2'dir. NFA'da 2 ile sınırlı değildir; daha fazla da olabilir, sıfır da olabilir. Bu yüzden NFA'larda daha çok olasılık vardır.

Bununla birlikte NFA ve DFA'nın gücü (power) aynıdır. Fark tasarımdadır: NFA ile daha az durum ve geçiş kullanarak daha basit bir otomat tasarlanır; DFA ile daha karmaşık bir otomat ortaya çıkar. Hoca, DFA tasarımının daha sistematik olduğunu, NFA tasarımının ise biraz daha tasarlayanın becerisine bağlı olduğunu ve herkesin farklı bir NFA tasarlayabileceğini ekler.

### 1.4 NFA ile Daha Kolay İfade

Slaytta "NFA'lar ilginçtir çünkü dilleri DFA'lardan daha kolay ifade edebiliriz" yazar (ekrandan, 00:25:00). $\Sigma=\{a\}$ ve dil $\{a\}$ olsun:

- NFA $M_1$: $q_0 \xrightarrow{a} q_1$, kabul durumu $q_1$. $q_0$'dan bir, $q_1$'den sıfır çıkış geçişi vardır; sıfır alfabe büyüklüğüne eşit olmadığı için NFA'dır.
- DFA $M_2$: $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_2$, $q_2 \xrightarrow{a} q_2$; kabul durumu $q_1$. Her durumdan tam bir çıkış geçişi vardır.

İki makine de yalnızca $a$ dizgisini tanır, yani $L(M_1)=L(M_2)=\{a\}$. Bu yüzden denktirler.

## 2. Otomatlar Nerede Kullanılır?

Hoca, konunun neden önemli olduğunu Türkçe olarak birkaç örnekle anlatır:

- **İşlemciler:** Bir işlemcinin içinde, toplama, çarpma, sıralama gibi işleri donanım olarak yapan çok sayıda otomat vardır. Her işlem kodunun (opcode) altında transistörler üzerinde çalışan NFA ve DFA'lar bulunur; bu, işlemciyi hızlandırır.
- **Dosya arama:** Bilgisayarda "A*" gibi bir arama yazdığınızda $A$ ile başlayan bütün dosyalar listelenir. Arka planda girilen kalıp bir otomata dönüşür ve dosya adları bununla karşılaştırılır.
- **İçecek ve yiyecek otomatları:** Para atılır, fiyatı paradan küçük olan ürünler seçilebilir. Bu da NFA ya da DFA ile tasarlanabilen bir otomattır.
- **Derleyiciler:** Bir C ya da Java programı önce ayrıştırılır (parse). `while`, `if` gibi anahtar kelimeleri tanıyan otomatlar metni parçalara (token) ayırır; bu işe tokenize etme denir. Ardından bağlamdan bağımsız gramerlerle bu parçaların dizilişi denetlenir ve bir ağaç yapısı elde edilir. Bu konular sonraki derslerde görülecektir. Sonunda C için ikili (binary) dosyalar, Java için bayt kodu (byte code) üretilir.

> **Hocanın vurgusu:** NFA ve DFA, bilgisayar mühendisliğinin kalbidir. Hocaya göre üniversitede mutlaka iyi öğrenilmesi gereken üç temel alan olasılık-istatistik, hesaplama kuramı ve sinyaller-sistemler/sinyal işlemedir. Makine öğrenmesi, yapay zeka gibi konular bu temeller üzerine sonradan da kolayca öğrenilebilir.

## 3. Genişletilmiş Geçiş Fonksiyonu

### 3.1 Tanım

Genişletilmiş geçiş fonksiyonu $\delta^*$ ile gösterilir. $\delta$ tek bir sembolle yapılan geçiştir; $\delta^*$ ise bir dizginin tamamı uygulandığında nereye varıldığını söyler. NFA'da $\delta^*$'ın çıktısı tek bir durum değil, bir **durum kümesidir**.

Bu bölümdeki örneklerin hepsi aynı makine üzerindedir (ekrandan, 00:30:00 ve 00:40:00):

| Durum | Sembol | Gidilen durum(lar) |
|---|---|---|
| $q_0$ (başlangıç, kabul) | $a$ | $q_1$ |
| $q_1$ | $a$ | $q_4$, $q_5$ |
| $q_1$ | $b$ | $q_2$ |
| $q_2$ | $\varepsilon$ | $q_3$ |
| $q_3$ | $\varepsilon$ | $q_0$ |

Kabul durumları $F=\{q_0,q_5\}$'tir.

### 3.2 Adım Adım Örnekler

- $\delta^*(q_0,a)=\{q_1\}$: $q_0$'dan $a$ ile $q_1$'e gidilir.
- $\delta^*(q_0,aa)=\{q_4,q_5\}$: ilk $a$ ile $q_1$'e, ikinci $a$ ile aynı anda hem $q_4$'e hem $q_5$'e gidilir.
- $\delta^*(q_0,ab)=\{q_2,q_3,q_0\}$ (ekrandan, 00:30:00): $a$ ile $q_1$'e, $b$ ile $q_2$'ye gidilir. $q_2$'den $\varepsilon$ ile $q_3$'te, $q_3$'ten $\varepsilon$ ile $q_0$'da da bulunulur.

**Soru:** $aba$ gibi bir girişte boş dizgileri araya koyabiliyor muyuz?

**Cevap:** $ab$'den sonra $\{q_2,q_3,q_0\}$'dayız. Üçüncü sembol $a$ uygulanınca $q_2$'den $a$ ile bir yere gidilemez, bu yol ölür. $q_3$'ten de $a$ geçişi yoktur, o da ölür. $q_0$'dan $a$ ile $q_1$'e gidilir. Sonuç: $\delta^*(q_0,aba)=\{q_1\}$.

**Soru:** $q_4$ kabul durumu değilken $q_5$ nasıl kabul durumu olabilir? $aa$ girişi $q_5$ yüzünden kabul mü edilir, $q_4$ yüzünden ret mi edilir?

**Cevap:** $aa$ uygulandığında aynı anda $q_4$ ve $q_5$'te bulunuruz. Bulunduğumuz durumlardan biri kabul durumu olduğu için $aa$ kabul edilir.

### 3.3 Genel Biçim

Genel olarak $q_j \in \delta^*(q_i,w)$ ise $q_i$'den $q_j$'ye etiketi $w$ olan bir yürüyüş (walk) vardır. $w=\sigma_1\sigma_2\cdots\sigma_k$ biçiminde alfabedeki sembollerin birleştirilmesidir ve uzunluğu $k$'dir. Yürüyüş boyunca semboller sırayla tüketilir; aralarda $\varepsilon$ geçişleri de kullanılabilir.

## 4. NFA'nın Dili ve Kabul Koşulu

### 4.1 Tanım

Slayttaki tanım şöyledir (ekrandan, 00:35:00): $M$'nin kabul ettiği dil

$$L(M)=\{w_1,w_2,\dots,w_n\}$$

olsun. Burada her $w_m$ için

$$\delta^*(q_0,w_m)=\{q_i,\dots,q_k,\dots,q_j\}$$

ve bu kümede bir $q_k \in F$ (kabul durumu) vardır. Dil sonlu da olabilir, sonsuz da; yani $n$ bir sayı da olabilir, sonsuz da.

Hoca tanımı Türkçe tekrar eder: Dildeki bir dizgi $q_0$'a uygulanır. Genişletilmiş geçiş sonunda bir sürü durumun üzerinde olabilirsiniz. Bu durumlardan **en az biri** kabul durumu olmalıdır ki dizgi tanınsın. Kümedeki durumların hiçbiri kabul durumu değilse dizgi makinenin dilinin elemanı değildir. Kısaca:

$$w \in L(M) \iff \delta^*(q_0,w)\cap F \neq \emptyset$$

### 4.2 Örnek Dizgiler

Bölüm 3'teki makine ($F=\{q_0,q_5\}$) üzerinde:

- $aa$: $\delta^*(q_0,aa)=\{q_4,q_5\}$. $q_4$ kabul durumu değil ama $q_5 \in F$. Kabul edilir.
- $ab$: $\delta^*(q_0,ab)=\{q_2,q_3,q_0\}$. $q_2$ ve $q_3$ kabul durumu değil, $q_0 \in F$. Kabul edilir.
- $abaa$: $ab$'den sonra $\{q_2,q_3,q_0\}$; $a$ ile yalnız $q_0$'dan $q_1$'e gidilir, $\delta^*(q_0,aba)=\{q_1\}$; son $a$ ile $\{q_4,q_5\}$. $q_5 \in F$ olduğu için kabul edilir (ekrandan, 00:40:00).
- $aba$: $\delta^*(q_0,aba)=\{q_1\}$ ve $q_1 \notin F$. Reddedilir.

Bu sonuçlar python ile doğrulandı.

> **Ders sonrası not:** Slaytta $\delta^*(q_0,abaa)=\{q_4,q_5\}$ satırının sonunda "$aaba \in L(M)$" yazıyor; hoca da sözlü olarak bir yerde "A, A, B, A" dedi. Hesaplanan dizgi $abaa$'dır ve doğrusu $abaa \in L(M)$'dir. $aaba$ ise reddedilir: $aa$'dan sonra $\{q_4,q_5\}$'teyiz ve bu durumlardan $b$ geçişi yoktur.

### 4.3 Makinenin Dili

Makinede $q_0 \to q_1 \to q_2 \to q_3 \to q_0$ biçiminde bir döngü vardır; bu döngü $ab$ okur. Bu yüzden döngü sayısınca $ab$ okunduktan sonra yine $q_0$'a dönülür ve kabul edilir: $\{ab\}^*$. Döngüden sonra $aa$ okunursa $q_5$'e varılır: $\{ab\}^*\{aa\}$. Slayttaki sonuç (ekrandan, 00:45:00):

$$L(M)=\{ab\}^* \cup \{ab\}^*\{aa\}$$

Hoca daha sonra slayta bir metin kutusu ekleyerek $L(M)=\{ab\}^*\cup\{aa\}$ yazar ve sınıfa bu iki ifadenin aynı olup olmadığını sorar. Bir öğrenci aynı olmadığını, çünkü alttaki ifadede $ab$ döngüsünden sonra $aa$'nın da alınabildiğini söyler. Hoca bir ara $\{ab\}^*\cup\{ab\}^*\{aa\}\cup\{aa\}$ biçimini de yazar, sonra $aa$'nın zaten $\{ab\}^*\{aa\}$ içinde olduğunu ($\{ab\}^*$ boş dizgiyi içerdiği için), bu yüzden üç terim yerine iki terim yazılabileceğini söyler. Hoca ayrıca her kabul durumu için ayrı bir dizgi kümesi bulunup bunların birleştirildiğini anlatır: bu makinede $q_0$ için bir küme, $q_5$ için bir küme vardır.

> **Ders sonrası not:** Hoca $\{ab\}^*\cup\{aa\}$ sadeleştirmesinin de aynı dili verdiğini söyledi. Bu doğru değildir: $abaa$ makine tarafından kabul edilir (yukarıda gösterildi), ama $\{ab\}^*\cup\{aa\}$ kümesinde yoktur. Doğru sadeleştirme $\{ab\}^*\{\varepsilon,aa\}$ ya da slayttaki $\{ab\}^*\cup\{ab\}^*\{aa\}$'dır. Python ile 8 uzunluğa kadar bütün dizgilerde kontrol edildi. Hocanın "kabul durumu sayısı kadar terim en az yazılmalı" sözü de büyük olasılıkla yalnız bir başlangıç önerisidir; genel bir kural değildir.

## 5. Makinelerin Denkliği

İki makine $M_1$ ve $M_2$ aynı dili tanıyorsa denktir: $L(M_1)=L(M_2)$.

Örnek (ekrandan, 00:50:00):

- NFA $M_1$: $q_0 \xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$; başlangıç ve kabul durumu $q_0$. $L(M_1)=\{10\}^*$. Alfabe $\{0,1\}$ iken her durumdan yalnız bir çıkış geçişi olduğu için NFA'dır.
- DFA $M_2$: aynı iki geçiş, ek olarak $q_0 \xrightarrow{0} q_2$, $q_1 \xrightarrow{1} q_2$ ve $q_2 \xrightarrow{0,1} q_2$. Her durumdan iki çıkış geçişi vardır; $q_2$'deki döngü üzerinde iki sembol olduğu için iki geçiş sayılır. $L(M_2)=\{10\}^*$.

İki makine aynı dili tanıdığı için denktir. Python ile 8 uzunluğa kadar bütün ikili dizgilerde doğrulandı.

> **Hocanın vurgusu:** Denklik söz konusu olduğunda durum sayısına ya da geçiş sayısına bakılmaz. Yalnızca makinenin tanıdığı dile bakılır.

## 6. Teorem: NFA'lar Düzenli Dilleri Kabul Eder

### 6.1 Teoremin İfadesi

Aradan sonra hoca teoremi verir (ekrandan, 00:55:00):

$$\{\text{NFA'ların kabul ettiği diller}\} = \{\text{Düzenli diller}\}$$

Düzenli diller, DFA'ların kabul ettiği dillerdir. Teoremin anlamı, NFA'ların ve DFA'ların aynı hesaplama gücüne sahip olması, yani aynı dil kümesini kabul etmesidir.

### 6.2 İspatın Yapısı

Bir eşitliği ispatlamak için iki kapsama gösterilir (ekrandan, 01:05:00):

1. $\{\text{NFA dilleri}\} \supseteq \{\text{Düzenli diller}\}$: Her DFA zaten bir NFA'dır. Bir DFA'nın kabul ettiği her $L$ dili bir NFA tarafından da kabul edilir.
2. $\{\text{NFA dilleri}\} \subseteq \{\text{Düzenli diller}\}$: Her NFA denk bir DFA'ya dönüştürülebilir. Bir NFA'nın kabul ettiği her $L$ dili bir DFA tarafından da kabul edilir.

### 6.3 Lemma ve İspat Fikri

**Lemma:** Bir NFA $M$, bir DFA $M'$'ye dönüştürülürse $M$ ile $M'$ denktir.

**İspat:** $L(M)\subseteq L(M')$ ve $L(M')\subseteq L(M)$ gösterilmelidir. Birinci kapsama için $L(M)$'den bir $w$ seçilir ve $w\in L(M')$ olduğu gösterilir (ekrandan, 01:10:00):

- $w=\sigma_1\sigma_2\cdots\sigma_k$ olsun. NFA $M$'de $q_0$'dan başlayıp her sembolle durum değiştirerek bir kabul durumu $q_f$'ye ulaşılır. $q_f$, girişin tamamı tüketildikten sonra bulunulabilecek durumlardan biridir.
- NFA'da iki ardışık durum arasında tek bir geçiş olmak zorunda değildir: $\varepsilon$ geçişleri yüzünden bir sembolle birden fazla durum ilerlenebilir. En az geçiş sayısı birdir.
- DFA $M'$'de de $\{q_0\}$ etiketli durumdan başlanır. Her sembolden sonra DFA, NFA'nın o anda bulunabileceği bütün durumların kümesiyle etiketli duruma geçer. Son durumun etiketi $\{q_f,\dots\}$ biçimindedir; içinde $q_f$ bulunduğu için bu durum kabul durumudur. Böylece $w\in L(M')$ olur.
- Bu yapı, dizgi uzunluğu üzerinden tümevarımla kurulur: uzunluk 1 için gösterilir, $1$ ile $k$ arası için doğru varsayılıp $k+1$ için gösterilir.

Ters yön, $L(M')\subseteq L(M)$, benzer biçimde gösterilir. Böylece $L(M)=L(M')$, yani NFA ile DFA aynı dilleri tanır.

> **Hocanın vurgusu:** DFA'daki durumların "adı", NFA'nın geçişler sonucunda bulunabileceği durumların kümesidir. Durumlara istediğiniz adı verebilirsiniz; hoca örnek olarak durumlara insan adı da verilebileceğini söyler. Küme işaretlerini ad olarak görmezseniz kafanız karışır.

**Soru:** Bu örnek üzerinden NFA ile DFA'nın farkını yeniden anlatır mısınız?

**Cevap:** Bütün durumlarda, çıkan geçişlerin sayısı alfabedeki sembol sayısına eşitse makine DFA'dır. Öğrenci yalnızca başlangıç durumundan $1$ ve $0$ çıktığı için mi DFA olduğunu sorar; hoca bütün durumlara bakılması gerektiğini, örnekteki DFA'da her durumdan ikişer geçiş çıktığını söyler.

## 7. NFA'dan DFA'ya Dönüşüm

### 7.1 Örnek

Dönüştürülecek NFA $M$ (ekrandan, 01:20:00):

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç) | $a$ | $q_1$ |
| $q_1$ (kabul) | $a$ | $q_1$ |
| $q_1$ | $\varepsilon$ | $q_2$ |
| $q_2$ | $b$ | $q_0$ |

Adımlar:

1. DFA $M'$'nin başlangıç durumunun adı $\{q_0\}$'dır.
2. $\{q_0\}$'dan $a$ ile: NFA'da $q_0 \xrightarrow{a} q_1$, $\varepsilon$ ile $q_2$'de de bulunulur. Yani $\delta^*(q_0,a)=\{q_1,q_2\}$ ve DFA'da $\delta(\{q_0\},a)=\{q_1,q_2\}$ (ekrandan, 01:25:00). Bu yeni bir durumdur.
3. $\{q_0\}$'dan $b$ ile: NFA'da $q_0$'dan $b$ geçişi yoktur. DFA'da boş küme $\emptyset$ ile gösterilen tuzak duruma (trap state) gidilir.
4. $\{q_1,q_2\}$'den $a$ ile: $q_1 \xrightarrow{a} q_1$, kapanışla $q_2$ de eklenir; $q_2$'den $a$ geçişi yoktur. Sonuç yine $\{q_1,q_2\}$, yani bir döngü.
5. $\{q_1,q_2\}$'den $b$ ile: $q_2 \xrightarrow{b} q_0$. Sonuç $\{q_0\}$.
6. Tuzak durumdan her sembol yine tuzak duruma gider.

Elde edilen DFA:

| DFA durumu | $a$ | $b$ |
|---|---|---|
| $\{q_0\}$ (başlangıç) | $\{q_1,q_2\}$ | $\emptyset$ |
| $\{q_1,q_2\}$ (kabul) | $\{q_1,q_2\}$ | $\{q_0\}$ |
| $\emptyset$ (tuzak) | $\emptyset$ | $\emptyset$ |

Her durumdan $a$ ve $b$ için birer, yani ikişer çıkış geçişi vardır; makine DFA'dır. NFA'nın kabul durumu $q_1$ olduğundan, adında $q_1$ bulunan $\{q_1,q_2\}$ DFA'nın kabul durumudur. Tablo python ile alt küme yapısı çalıştırılarak doğrulandı.

<!-- BELİRSİZ: Tamamlanmış DFA'nın çizildiği slayt karelerde görünmüyor; tablo anlatımdan ve hesaplamadan kuruldu. -->

### 7.2 Genel Yöntem

Girdi bir NFA $M$, çıktı denk bir DFA $M'$'dir; $L(M)=L(M')$.

- NFA'nın durum kümesi $Q$ ise DFA'nın durumları $Q$'nun kuvvet kümesinden (power set) seçilir. Bu yüzden DFA çok daha karmaşık olabilir.
- **Adım 1:** Başlangıç durumu. NFA'da tek bir başlangıç durumu vardır; DFA'nın başlangıç durumunun adı $\{q_0\}$'dır.
- **Adım 2:** Her DFA durumu ve her sembol için genişletilmiş geçişle NFA'nın varabileceği durumlar bulunur ve bu küme yeni DFA durumunun adı olur. Örneğin $\{q_0\}$'dan $0$ ile NFA $q_1$ ya da $q_2$'ye gidiyorsa DFA'da $\{q_0\}\xrightarrow{0}\{q_1,q_2\}$ geçişi eklenir.
- **Adım 3:** DFA'ya eklenebilecek yeni durum kalmayana kadar Adım 2 her durum ve her sembol için tekrarlanır.
- **Adım 4:** NFA'da $q_j$ bir kabul durumuysa, adında $q_j$ bulunan her DFA durumu da kabul durumudur.

Hoca Türkçe olarak yeniden vurgular: NFA'da aynı anda birçok duruma gidilebiliyordu; önceki örnekte $aa$ ile $q_4$ ve $q_5$'e gidilmişti. DFA'ya dönüştürürken bu durumun adı $\{q_4,q_5\}$ olur. Kümeler durumların adı olunca NFA DFA'ya dönüştürülmüş olur.

## 8. Düzenli Dillerin Kapanma Özellikleri

### 8.1 Düzenli Dil ve Kapanma

Bu bölüm yeni bir slayt dosyasıyla başlar (ekrandan, 01:30:00). Dil bir dizgi kümesidir. Düzenli dil, bir NFA ya da DFA tarafından tanınan dildir. Bir dil düzenliyse onu tanıyan bir NFA ya da DFA vardır.

$L_1$ ve $L_2$ düzenli diller ise şunlar da düzenlidir:

- Birleşim: $L_1\cup L_2$
- Birleştirme (concatenation): $L_1L_2$
- Yıldız (Kleene star): $L_1^*$
- Ters çevirme (reversal): $L_1^R$, dildeki bütün dizgilerin tersi
- Tümleme (complement): $\overline{L_1}$
- Kesişim: $L_1\cap L_2$

Bu yüzden "düzenli diller bu işlemler altında kapalıdır" denir. Kapalı olmak kümenin dışına çıkılamaması demektir. Hoca tam sayılarla bir benzetme yapar: iki tam sayıyı topladığınızda yine bir tam sayı elde edersiniz, kesirli sayı elde etmezsiniz; tam sayılar toplama altında kapalıdır. Aynı biçimde düzenli dillere bu işlemler uygulandığında yine düzenli bir dil elde edilir.

### 8.2 Yararlı Dönüşüm: Tek Kabul Durumu

Slayt (ekrandan, 01:35:00) iki kabul durumlu bir NFA ve ona denk tek kabul durumlu bir NFA gösterir:

- İlk NFA: başlangıç durumu $s$'den $a$ ile kabul durumu $p$'ye, $p$'den $b$ ile $r$'ye, $r$'den $a$ ile tekrar $s$'ye; ayrıca $s$'den $b$ ile ikinci kabul durumu $t$'ye.
- Denk NFA: $p$ ve $t$ normal durum yapılır, ikisinden de boş dizgi geçişiyle yeni ve tek bir kabul durumuna gidilir.

Hoca örnek olarak $abab$'ı izler: $s\to p\to r\to s\to t$; ilk makinede $t$ kabul durumudur, ikincisinde $t$'den boş dizgiyle yeni kabul durumuna geçilir. İki makine denktir. Genel olarak birçok kabul durumu olan bir NFA'nın kabul durumları boş dizgi geçişleriyle tek bir kabul durumunda birleştirilebilir. Uç durumda hiç kabul durumu olmayan bir NFA'ya, geçişi olmayan bir kabul durumu eklenir.

Slaytta boş dizgi geçişleri $\lambda$ ile gösterilmiştir. Hoca, bazı kitaplarda boş dizgi için $\lambda$, bazılarında $\varepsilon$ kullanıldığını, ikisinin de aynı anlama geldiğini ve bütünlük için derste $\varepsilon$ kullanılacağını söyler.

### 8.3 Örnek Diller

Kapanma yapıları şu iki dil üzerinde örneklenir:

- $L_1=\{a^nb\}$, $n\ge 0$. $M_1$'in iki durumu vardır: başlangıçta $a$ döngüsü, $b$ ile kabul durumuna geçiş. Dilin örnekleri: $b$, $ab$, $aab$, $aaab$, $aaaab$, ...
- $L_2=\{ba\}$. $M_2$'nin üç durumu vardır: $b$ ve ardından $a$ ile kabul durumuna varılır. Dilde tek dizgi vardır.

### 8.4 Birleşim

$L_1\cup L_2$ için NFA (ekrandan, 01:40:00): yeni bir başlangıç durumu eklenir, buradan $M_1$'in ve $M_2$'nin başlangıç durumlarına $\varepsilon$ geçişleri çizilir. $M_1$ ve $M_2$'nin kabul durumları aynen kalır. Bu makine $L_1\cup L_2=\{a^nb\}\cup\{ba\}$ dilini tanır.

### 8.5 Birleştirme

$L_1L_2$ için $M_1$'in kabul durumu normal duruma çevrilir ve $\varepsilon$ geçişiyle $M_2$'nin başlangıç durumuna bağlanır. Toplam makine $L_1L_2=\{a^nb\}\{ba\}=\{a^nbba\}$ dilini tanır.

### 8.6 Yıldız

$L_1^*$ için $L_1$'in kendisiyle bütün olası birleştirmeleri alınır. Yapı:

- Yeni bir başlangıç durumu ve yeni bir kabul durumu eklenir.
- $M_1$'in kabul durumları normal durum yapılır ve $\varepsilon$ ile yeni kabul durumuna bağlanır.
- Bu yeni kabul durumundan $\varepsilon$ ile başlangıç durumuna dönülerek birleştirmeyi sağlayan döngü kurulur.

> **Ek bilgi (derste anlatılmadı):** $\varepsilon\in L_1^*$ olduğundan yapıda boş dizginin de kabul edilmesi gerekir. Bunun için genellikle yeni başlangıç durumundan yeni kabul durumuna doğrudan bir $\varepsilon$ geçişi de eklenir.

<!-- BELİRSİZ: Yıldız slaytındaki ε geçişlerinin tam yönleri karelerde yalnız küçük önizlemede görünüyor; anlatım altyazıdan kuruldu. -->

Örnek: $L_1^*=\{a^nb\}^*$. Bu makine bir NFA olduğu için $L_1^*$ düzenlidir.

### 8.7 Ters Çevirme

$L_1^R$ için iki adım vardır (ekrandan, 01:45:00):

1. Bütün geçişlerin yönü ters çevrilir.
2. Başlangıç durumu kabul durumu, kabul durumu başlangıç durumu yapılır.

Örnek: $M_1$, $L_1=\{a^nb\}$'yi tanır; örneğin $ab$ kabul edilir. Ters çevrilmiş makine $M_1'$, $\{ba^n\}$'yi tanır; örneğin $ba$ kabul edilir. Sembollerin sırası tersine dönmüştür. Bu yapının tek kabul durumlu bir makineye uygulanması, Bölüm 8.2'deki dönüşümün neden yararlı olduğunu gösterir.

### 8.8 Tümleme

Tümleme biraz daha zordur:

1. Verilen NFA önce mutlaka DFA'ya dönüştürülür.
2. DFA'da kabul durumları normal duruma, normal durumlar kabul durumuna çevrilir.
3. Giriş alfabesi, başlangıç durumu ve geçişler değiştirilmez; yalnızca durumların türü değişir.

Örnek (ekrandan, 01:55:00): $L_1=\{a^nb\}$ için DFA $M_1$:

| Durum | $a$ | $b$ |
|---|---|---|
| $s$ (başlangıç) | $s$ | $f$ |
| $f$ (kabul) | $t$ | $t$ |
| $t$ (tuzak) | $t$ | $t$ |

Tümleyen $\overline{L_1}=\{a,b\}^*-\{a^nb\}$ için $M_1'$'de $s$ ve $t$ kabul durumu, $f$ normal durum olur. Hoca bunu "kabul durumu normal duruma, başlangıç durumu kabul durumuna çevrilir" diye anlatır; bu örnekte tuzak durum da kabul durumu olur. Python ile 8 uzunluğa kadar bütün dizgilerde doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Durum türlerini değiştirmeden önce DFA'nın tam (her durumda her sembol için geçişi olan) olması gerekir; bu yüzden tuzak durum da çizilmelidir. Tuzak durum olmadan türler değiştirilirse tuzağa giden dizgiler tümleyende yanlışlıkla reddedilir. NFA'da durum türlerini doğrudan değiştirmek ise genellikle tümleyeni vermez; ilk adımın DFA'ya dönüşüm olmasının nedeni budur.

> **Hocanın vurgusu:** Ara sınav ve final sınavlarında genellikle bu tür sorular sorulur: bir NFA verilip tümleyenini tanıyan bir otomat tasarlamanız istenir, ya da birkaç dil verilip birleşim, kesişim, birleştirme gibi işlemlerin bileşimini tanıyan bir otomat istenir.

## 9. Kesişim ve Kartezyen Çarpım Yapısı

### 9.1 Kesişim Neden Düzenlidir?

$L_1$ ve $L_2$ düzenliyse kesişimleri de düzenlidir. Hoca önce tümleme ve birleşim üzerinden giden bir yolu kısaca anar (büyük olasılıkla De Morgan kuralı: $L_1\cap L_2=\overline{\overline{L_1}\cup\overline{L_2}}$; altyazı bu kısımda bozuk). Ardından bir örnek verir: iki dilin ortak kısmı yalnızca $ab$ ise kesişim $\{ab\}$'dir. Eleman sayısı sonlu olan bu küme düzenli bir dildir.

<!-- BELİRSİZ: Bu örnekteki L1 ve L2 dilleri karelerde görünmüyor. -->

### 9.2 Paralel Çalışan DFA

Diğer ispat doğrudan bir yapı kurmaktır:

- $L_1$ için bir DFA $M_1$, $L_2$ için bir DFA $M_2$ tasarlanır. NFA verilmişse önce DFA'ya dönüştürülür.
- Kesişimi kabul eden yeni bir DFA $M$ kurulur. $M$, $M_1$ ve $M_2$'yi aynı anda, paralel olarak çalıştırır.
- $M$'nin durumları, $M_1$ ve $M_2$'nin durumlarının Kartezyen çarpımıdır. Her durum bir çifttir: $(q_i,p_j)$, burada $q_i$ $M_1$'in, $p_j$ $M_2$'nin bir durumudur (ekrandan, 02:20:00).
- Geçişler: $M_1$'de $q_1 \xrightarrow{a} q_2$, $M_2$'de $p_1 \xrightarrow{a} p_2$ ise $M$'de $(q_1,p_1)\xrightarrow{a}(q_2,p_2)$ olur.
- Kabul durumları: $M_1$'in kabul durumu $q_i$, $M_2$'nin kabul durumları $p_j$ ve $p_k$ ise $M$'nin kabul durumları $(q_i,p_j)$ ve $(q_i,p_k)$'dir. Yani iki bileşeni de kabul durumu olan çiftler.

### 9.3 Örnek: Dokuz Durum

$M_1$'in durumları $q_0,q_1,q_2$, $M_2$'nin durumları $p_0,p_1,p_2$ ise Kartezyen çarpım şu dokuz durumu verir:

$$(q_0,p_0),(q_0,p_1),(q_0,p_2),(q_1,p_0),(q_1,p_1),(q_1,p_2),(q_2,p_0),(q_2,p_1),(q_2,p_2)$$

$3\times 3=9$ durum. Hoca bazı durumların ulaşılamaz olabileceğini, bu yüzden azaltılabileceğini, yani dokuzun bir üst sınır olduğunu söyler. Geçiş örneği: $M_1$'de $q_0$'dan $a$ ile $q_0$'a, $M_2$'de $p_0$'dan $a$ ile $p_1$'e gidiliyorsa $M$'de $(q_0,p_0)\xrightarrow{a}(q_0,p_1)$ olur. Bu biçimde DFA'nın tamamı yazılabilir.

<!-- BELİRSİZ: Bu örnekteki M1, M2 ve 9 durumlu DFA'nın geçiş tablosu karelerde görünmüyor; yalnız anlatılan tek geçiş aktarıldı. -->

## 10. Düzenli İfadelere Giriş

Dersin son dakikalarında düzenli ifadelere geçilir. Dilleri küme olarak yazabildiğimiz gibi düzenli ifadelerle de tanımlayabiliriz. Örneğin $\{a,bc\}$ kümesi iki dizgi içeren bir dildir; buna yıldız uygulanınca $\{a,bc\}^*$ elde edilir ve bu dil

$$(a+bc)^*$$

düzenli ifadesiyle betimlenir. Düzenli ifadeler dilleri betimlemek için kullanılır.

### 10.1 Özyinelemeli Tanım

Slayttaki tanım (ekrandan, 02:25:00):

- İlkel düzenli ifadeler: $\varepsilon$ ve $\alpha$ ($\alpha$ alfabeden bir sembol).
- $r_1$ ve $r_2$ düzenli ifadeler ise şunlar da düzenli ifadedir:
  - $r_1+r_2$ (birleşim, "ya da")
  - $r_1\cdot r_2$ (birleştirme)
  - $r_1^*$ (Kleene yıldızı)
  - $(r_1)$ (parantez; yalnızca öncelik içindir, $(r_1)$ ile $r_1$ aynı dili verir)

Hoca örnek olarak $a$ ya da $bc$'nin yıldızı ile $c$ ya da boş dizginin birleştirilmesinden oluşan bir ifadeyi gösterir ve bunun düzenli ifade olduğunu söyler. Sonra bir sembolün eksik olduğu, örneğin bir $+$ işaretinin bir yanının boş kaldığı ifadenin düzenli ifade olmadığını belirtir.

<!-- BELİRSİZ: Düzenli olan ve olmayan ifade örnekleri ile L(r) tanım slaytı karelerde görünmüyor; ifadeler altyazıdan tam çıkarılamadı. -->

### 10.2 Düzenli İfadenin Dili

Her düzenli ifade $r$ bir dil üretir; bu $L(r)$ ile gösterilir. Temel durumlar: boş dizginin dili $\{\varepsilon\}$, $a$ sembolünün dili $\{a\}$'dır. $+$ birleşim için, nokta birleştirme için, yıldız Kleene yıldızı için kullanılır; parantezler öncelik içindir. Hoca sonraki derste NFA, DFA ve kesişim konularında bol örnek çözüleceğini söyler.

## Örnek Sorular

**1. Çıkış geçişi sayısı** (ekrandan, 00:10:00; derste sözlü, 00:09:49)

$\Sigma=\{0,1\}$, geçişler $q_0 \xrightarrow{1} q_1$, $q_0 \xrightarrow{\varepsilon} q_2$, $q_1 \xrightarrow{0} q_0$, $q_1 \xrightarrow{0,1} q_2$ olan makinede $q_1$'den kaç çıkış geçişi vardır? Makine NFA mı DFA mı?

> **Çözüm:** $q_1$'den $0$ ile $q_0$'a bir geçiş, $0,1$ etiketli okta iki geçiş vardır; toplam üç. $q_0$'dan yalnız bir sembollü geçiş çıkar ($\varepsilon$ sayılmaz). Çıkış sayıları alfabenin büyüklüğüne (2) eşit olmadığı için makine NFA'dır. Dili $\{10\}^*$'dır.

**2. Tek durumlu makine** (ekrandan, 00:15:00; derste sözlü, 00:12:05)

Tek bir durumu olan, hiç geçişi olmayan $M_1$ ($L(M_1)=\{\}$) NFA mı DFA mı?

> **Çözüm:** Alfabe boş kümeyse her durumdaki çıkış sayısı (0) alfabenin büyüklüğüne (0) eşittir, makine DFA'dır. Alfabe boş değilse çıkış sayısı alfabe büyüklüğünden küçüktür, makine NFA'dır. Aynı değerlendirme $L(M_2)=\{\varepsilon\}$ olan tek kabul durumlu $M_2$ için de geçerlidir.

**3. Genişletilmiş geçiş** (ekrandan, 00:30:00; derste sözlü, 00:29:18)

Bölüm 3'teki makinede $\delta^*(q_0,aba)$ nedir?

> **Çözüm:** $\delta^*(q_0,ab)=\{q_2,q_3,q_0\}$. $a$ ile $q_2$ ve $q_3$'ten geçiş yoktur; $q_0\xrightarrow{a}q_1$. Sonuç $\{q_1\}$. $q_1\notin F$ olduğundan $aba$ reddedilir.

**4. Kabul** (derste sözlü, 00:34:34)

Aynı makinede $aa$ girişi $q_5$ kabul durumu olduğu için mi kabul edilir, $q_4$ kabul durumu olmadığı için mi reddedilir?

> **Çözüm:** $\delta^*(q_0,aa)=\{q_4,q_5\}$. Kümede en az bir kabul durumu ($q_5$) bulunduğu için $aa$ kabul edilir.

**5. İki dil aynı mı?** (ekrandan, 00:45:00; derste sözlü, 00:44:06)

Makinenin dili $\{ab\}^*\cup\{ab\}^*\{aa\}$ ise bu dil $\{ab\}^*\cup\{aa\}$ ile aynı mıdır?

> **Çözüm:** Aynı değildir. $abaa\in\{ab\}^*\{aa\}$ ve makine bu dizgiyi kabul eder, ama $abaa\notin\{ab\}^*\cup\{aa\}$. Doğru eşitlik $\{ab\}^*\cup\{ab\}^*\{aa\}=\{ab\}^*\{\varepsilon,aa\}$'dır. Derste bir öğrenci de aynı itirazı yaptı. Hocanın derste söylediği sonuç için Bölüm 4.3'teki ders sonrası nota bakın. Python ile doğrulandı.

**6. Denk makineler** (ekrandan, 00:50:00; derste sözlü, 00:49:27)

NFA $M_1$ ve DFA $M_2$ (Bölüm 5) denk midir?

> **Çözüm:** Evet. İkisi de $\{10\}^*$ dilini tanır. Denklikte durum ve geçiş sayısına bakılmaz.

**7. Tümleme** (ekrandan, 01:55:00)

$L_1=\{a^nb\}$ dilini tanıyan DFA verildiğinde $\overline{L_1}=\{a,b\}^*-\{a^nb\}$ dilini tanıyan otomatı tasarlayın.

> **Çözüm:** Bölüm 8.8'deki tabloda kabul durumları değiştirilir: $s$ ve $t$ kabul durumu, $f$ normal durum olur. Geçişler ve başlangıç durumu aynen kalır.

## Dersin Toparlaması

Bu derste NFA'ların tanımı tamamlanıp DFA'larla ilişkisi kuruldu. Genişletilmiş geçiş fonksiyonunun NFA'da bir durum kümesi döndürdüğü, bir dizginin bu kümede en az bir kabul durumu varsa kabul edildiği görüldü. İki makinenin aynı dili tanıyorsa denk olduğu tanımlandı ve NFA'ların kabul ettiği dillerin tam olarak düzenli diller olduğu teoremi ispatlandı. İspatın kalbi olan alt küme yapısında DFA durumları NFA durumlarının kümeleriyle adlandırılır; içinde NFA kabul durumu bulunan her küme DFA'da kabul durumudur.

İkinci bölümde düzenli dillerin birleşim, birleştirme, yıldız, ters çevirme, tümleme ve kesişim altında kapalı olduğu, her işlem için bir otomat kurularak gösterildi. Tümleme için önce DFA'ya geçmek, kesişim için iki DFA'nın Kartezyen çarpımını kurmak gerektiği vurgulandı. Ders, düzenli ifadelerin özyinelemeli tanımıyla bitti. Sonraki derste NFA, DFA ve kesişim üzerine örnekler çözüleceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
