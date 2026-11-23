# Ders 4 Genişletilmiş Notu: NFA'dan DFA'ya Dönüşüm ve Düzenli Dillerin Kapalılık Özellikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. NFA'nın DFA'dan farklarının tekrarı
- 2. Makinelerin denkliği ve NFA–DFA denklik teoremi
- 3. NFA'dan DFA'ya dönüşüm
- 4. Dönüşümün doğruluğunun ispatı
- 5. Düzenli dillerin kapalılık özellikleri
- 6. Birleşim, birleştirme ve yıldız
- 7. Ters ve tümleyen
- 8. Kesişim
- Örnek Sorular
- Dersin Toparlaması

## 1. NFA'nın DFA'dan farklarının tekrarı

Ders, önceki derste başlanan deterministik olmayan sonlu otomatların (Non-Deterministic Finite Automata, NFA) kısa bir tekrarıyla açıldı. Bu bölüm Türkçe anlatıldı; dersin geri kalanı İngilizce slaytlar üzerinden ağırlıklı olarak İngilizce işlendi.

Standart DFA'dan ilk fark şudur: NFA'da bir durumdayken aynı sembol okunduğunda birden fazla yeni duruma geçilebilir. Slayttaki örnekte $a$ okunduğunda makine hem $q_1$'e hem $q_3$'e geçiyordu. Hoca bunu, makinenin kendini çoğaltıp paralel çalışan iki makineye dönüşmesi olarak açıkladı: üst dal ayrı bir hesaplama yolu, alt dal ayrı bir hesaplama yoludur. Dallardan herhangi birinin girişi kabul etmesi, NFA'nın girişi kabul etmesi için yeterlidir.

İkinci fark null geçişi ya da $\varepsilon$ geçişidir (null / epsilon transition). DFA'larda yoktur, NFA'larda vardır; hiçbir şey okumadan durumun değişmesini sağlar (ekrandan, 00:15:00). Ekrandaki örnek: $q_0 \xrightarrow{a} q_1 \xrightarrow{\varepsilon} q_2 \xrightarrow{a} q_3$, kabul durumu $q_3$. $q_0$'da başlayıp $a$ okununca $q_1$'e geçilir ve sistem anında $q_2$'ye de geçer. Burada da paralel makine mantığı vardır: $q_2$'ye geçildiğinde $q_1$ hâlâ etkindir, yani makine kendini ikiye ayırmıştır. Sonra tekrar $a$ okununca $q_2$ $q_3$'e geçer; $q_1$'in $a$ geçişi olmadığı için o dalın hesaplaması durur, o makine "ölür". Başka örneklerde $q_1$ de $a$'yı alabilirdi; o zaman $q_1$'den devam eden hesaplama yolunun da izlenmesi gerekirdi.

Üçüncü fark, NFA'larda her durumun her sembolde nereye gittiğini göstermek zorunda olmamamızdır. Bir sembolün geçişi çizilmemişse o durum o sembolü alamaz; sembol geldiğinde o dal deaktive olur, hesaplama o noktada durur. DFA'da ise her durum için her sembolün nereye gittiği grafikte gösterilmelidir. Bu esneklik sayesinde NFA'larla daha az kalabalık çizimler yapılabilir.

Dördüncü fark, NFA'nın geçiş tablosunda ya da fonksiyonunda sonucun bir küme olmasıdır. Bir durum aynı sembolle birden fazla duruma gidebildiği için (örneğin bir $q_1$ durumu $0$ okuyunca hem $q_0$'a hem $q_2$'ye gidebiliyorsa) sonuç fonksiyonel olarak bir durum kümesiyle gösterilir.

Son olarak, DFA'larda olduğu gibi NFA'ların da dilinden söz edilir: bir NFA'nın dili, NFA'nın kabul ettiği bütün dizgileri (string, sözcük) içeren kümedir.

## 2. Makinelerin denkliği ve NFA–DFA denklik teoremi

### 2.1 Makinelerin denkliği

$M_1$ makinesi $M_2$ makinesine denktir (equivalent) ancak ve ancak

$$L(M_1) = L(M_2).$$

Yani iki makine, dilleri aynıysa, aynı dili kabul ediyorlarsa denktir. Slayttaki örnekte $M_1$ bir NFA, $M_2$ bir DFA'dır; ikisinin dili de $\{10\}^*$, yani herhangi sayıda $10$'dan oluşan dizgilerdir. Bu yüzden iki makine denktir. <!-- BELİRSİZ: M1 ve M2'nin çizimleri karede görünmüyor; dil altyazıdan alındı -->

### 2.2 Teorem: NFA'lar düzenli dilleri kabul eder

Teorem (ekrandan, 00:25:00):

$$\{\text{NFA'ların kabul ettiği diller}\} = \{\text{Düzenli diller}\}$$

Düzenli diller önceki derste DFA'ların kabul ettiği diller olarak tanımlanmıştı; sağ taraf bu yüzden "DFA'ların kabul ettiği diller" diye de okunabilir. Küme parantezleri, tek bir dilden değil, NFA'ların kabul ettiği bütün dillerin kümesinden söz edildiğini gösterir. Teoremin anlamı: NFA'lar ve DFA'lar aynı hesaplama gücüne sahiptir, aynı diller kümesini kabul ederler.

Hoca bunu problemlerin dil olarak tanımlanmasıyla bağladı. Problemler küme üyeliği olarak ifade ediliyordu; örneğin bir toplamanın geçerli olup olmadığı, önceki derslerde "toplama dili"ne üyelik olarak yazılmıştı. Teorem, NFA ile çizmek daha kolay olsa da sonunda NFA'ların DFA'lara ek bir güç vermediğini söyler. NFA bir anlamda bir kısayoldur; DFA için bir "syntactic sugar"dır.

### 2.3 İspatın yapısı

Kümelerin eşitliğini ispatlamak için iki şey gösterilmelidir: NFA dilleri kümesi düzenli diller kümesinin hem üst kümesi hem alt kümesidir.

**İspat Adım 1:** $\{\text{Düzenli diller}\} \subseteq \{\text{NFA dilleri}\}$. Bu önemsizdir. NFA yeni gösterimler ekler; DFA, NFA gösteriminin bir alt kümesini kullanır. Dolayısıyla her DFA zaten bir NFA'dır. Bir DFA'nın kabul ettiği her $L$ dili, o DFA bir NFA olduğu için bir NFA tarafından da kabul edilir.

**İspat Adım 2:** $\{\text{NFA dilleri}\} \subseteq \{\text{Düzenli diller}\}$ (ekrandan, 00:30:00). Yani bir NFA'nın kabul ettiği her $L$ dili bir DFA tarafından da kabul edilir. Bunun için önce her NFA'yı denk bir DFA'ya çeviren bir yöntem gösterilir, sonra bu dönüşümle elde edilen DFA'nın dilinin NFA'nın diliyle aynı olduğu ispatlanır.

## 3. NFA'dan DFA'ya dönüşüm

### 3.1 Örnek üzerinde dönüşüm

Ekrandaki NFA $M$ şudur (ekrandan, 00:35:00):

| Geçiş | Açıklama |
|---|---|
| $q_0 \xrightarrow{a} q_1$ | $q_0$ başlangıç durumu |
| $q_1 \xrightarrow{a} q_1$ | $q_1$ kabul durumu, kendine döngü |
| $q_1 \xrightarrow{\varepsilon} q_2$ | null geçişi |
| $q_2 \xrightarrow{b} q_0$ | geri dönüş |

Bu bir NFA'dır, çünkü bir $\varepsilon$ geçişi vardır ve $q_0$'ın $b$ okuyunca ne olacağı gösterilmemiştir.

Dönüşüm şöyle başlar: DFA'nın başlangıç durumunun etiketi bir kümedir ve bu küme NFA'nın başlangıç durumu $q_0$'ı içerir: $\{q_0\}$. Sonra iki soru sorulur, çünkü DFA'da her iki sembolün de gösterilmesi gerekir: bu durum $a$ okursa ne olur, $b$ okursa ne olur?

- $q_0$ $a$ okursa $q_1$'e gider; null geçişi yüzünden $q_2$ de etkin olur. NFA'da iki etkin durum vardır. Bu iki sonuç durumu için DFA'da tek bir durum yaratılır: $\{q_1, q_2\}$. Hoca, matematikte virgülün "ve" anlamına geldiğini hatırlattı: $q_0$ $a$ okuyunca $q_1$ ve $q_2$ etkin olur.
- $q_0$ için NFA'da $b$ geçişi yoktur, yani $b$ okuyamaz. DFA'da bu bir tuzak durum (trap state) ile ifade edilir: $\delta^*(q_0, b) = \varnothing$ (ekrandan, 00:35:00). Tuzak durumun etiketi boş kümedir; her sembolde kendine dönen döngüleri vardır ve kabul durumu değildir, bu yüzden "tuzak"tır.

Şimdi işlenmesi gereken iki yeni durum vardır: tuzak durum ve $\{q_1, q_2\}$. Her durum ve her sembol için aynı işlem tekrarlanır.

$\{q_1, q_2\}$ için $a$: kümedeki her durum için NFA'ya bakılır. $q_1$ $a$ okursa yine $q_1$'e gider ve $\varepsilon$ geçişi yüzünden $q_2$ de gelir: $\delta^*(q_1,a) = \{q_1,q_2\}$. $q_2$ $a$ okuyamaz: $\delta^*(q_2,a) = \varnothing$. Sonuç bu ikisinin birleşimidir:

$$\{q_1,q_2\} \cup \varnothing = \{q_1,q_2\}.$$

Bu etikette bir durum zaten olduğu için yeni durum eklenmez; $a$ ile $\{q_1,q_2\}$'den kendisine bir döngü çizilir.

$\{q_1, q_2\}$ için $b$: $q_2$ $b$ okuyunca $q_0$'a gider: $\delta^*(q_2,b) = \{q_0\}$, birleşim $\{q_0\}$ (ekrandan, 00:40:00). Böylece $b$ ile $\{q_0\}$'a geri dönülür.

Bu adımda hoca slaytta bir hata olduğunu düşündü ve $q_1$'in $b$ okuyamadığını, bu yüzden $\delta^*(q_1, b) = \varnothing$ olması gerektiğini söyleyerek slayta bu satırı ekledi. <!-- BELİRSİZ: slaytın düzeltmeden önceki satırı karede görünmüyor -->

**Soru:** Bu neden yanlış? $q_1$ durumundayken sonraki okunan $b$ ise $q_0$'a geçilmez mi? **Cevap:** Öyle de bakılabilir; slaytı hazırlayan da büyük olasılıkla öyle bakmıştır. Hocanın bakışı şudur: $q_1$'de $a$ okunup yine $q_1$'e gelindiğinde makine null geçişi yüzünden hemen ikiye ayrılır, birinin durumu $q_1$, diğerinin $q_2$ olur. Ayrılmış makinede $q_1$ $b$'yi okuyamaz, $q_2$ okuyabilir. Sonuç iki bakışta da aynıdır.

> **Ders sonrası not:** Slaytlardaki genişletilmiş geçiş fonksiyonu $\delta^*$, yoldaki $\varepsilon$ geçişlerini de sayar (bkz. Bölüm 4'teki kesikli ok açıklaması, ekrandan, 01:10:00). Bu tanımla $q_1 \xrightarrow{\varepsilon} q_2 \xrightarrow{b} q_0$ yolu bulunduğu için $\delta^*(q_1,b) = \{q_0\}$'dır; öğrencinin bakışı büyük olasılıkla slayttaki tanıma daha uygundur. Hocanın ayrık bakışında da birleşim $\{q_0\}$ çıktığı için elde edilen DFA değişmez.

Son olarak tuzak durum $a$ ve $b$ için kendine döner. Dönüşüm bittiğinde kabul durumları belirlenir: $q_1$ orijinal NFA'da kabul durumu olduğundan $q_1$'i içeren $\{q_1, q_2\}$ kabul durumudur. Elde edilen DFA $M'$:

| DFA durumu | $a$ | $b$ |
|---|---|---|
| $\to \{q_0\}$ | $\{q_1,q_2\}$ | $\varnothing$ |
| $\{q_1,q_2\}$ (kabul) | $\{q_1,q_2\}$ | $\{q_0\}$ |
| $\varnothing$ (tuzak) | $\varnothing$ | $\varnothing$ |

(Ders sonrası kontrol: bu tablo python ile alt küme yapısıyla yeniden kuruldu ve 8 uzunluğa kadar bütün $\{a,b\}$ dizgilerinde NFA ile DFA'nın aynı kararı verdiği görüldü.)

### 3.2 Genel prosedür

Hoca örnekteki fikri genelleştirdi:

- NFA'nın durumları $q_0, q_1, q_2, \dots$ ise, DFA'nın durumları bunların kuvvet kümesinden gelir: $\{q_0\}$, $\{q_1\}$, $\{q_0, q_1\}$ gibi bu durumları içeren kümeler DFA durumlarının etiketleridir.
- **Adım 1:** NFA'nın başlangıç durumu $q_0$ için DFA'nın başlangıç durumu yaratılır; bu durum $q_0$'ı içerir (örnekte olduğu gibi başka durumlar da içerebilir).
- **Adım 2:** Her DFA durumu $\{q_i, q_j, \dots, q_m\}$ ve her sembol $a$ için NFA'da şu hesaplanır (ekrandan, 00:50:00):

$$\delta^*(q_i,a) \cup \delta^*(q_j,a) \cup \dots \cup \delta^*(q_m,a) = \{q'_k, q'_l, \dots, q'_n\}$$

  ve DFA'ya $\delta(\{q_i,q_j,\dots,q_m\}, a) = \{q'_k, q'_l, \dots, q'_n\}$ geçişi eklenir. Bu etiket grafikte yoksa önce durum eklenir, sonra geçiş çizilir.
- **Adım 3:** Adım 2, her durum ve alfabedeki her sembol için tekrarlanır.
- **Adım 4:** NFA'nın her kabul durumu için, o durumu içeren her DFA durumu kabul durumu yapılır.

Hoca daha sonra prosedürü Türkçe olarak da özetledi: NFA $q_0$ ile başlıyorsa DFA da $q_0$'ı içeren bir küme ile temsil edilen bir durumla başlar. Her yeni DFA durumu için alfabedeki $a$, $b$, $c$ gibi her sembol alınırsa ne olacağı sorulur. Yeni bir durum oluşuyorsa çizilir ve ona geçiş yapılır; eski durumlardan biri çıkıyorsa doğrudan ona geçiş yapılır. Yeni oluşan her durum için aynı soru tekrarlanır. Bazı işlemler, örneğin bir dilin tümleyenini veren otomatı bulmak, NFA'yı önce DFA'ya çevirmeyi gerektirir.

> **Hocanın vurgusu:** NFA'yı DFA'ya çevirme prosedürü önemlidir. Sınavlarda bir NFA'yı DFA'ya çevirmeniz ya da bir DFA'nın bir NFA'ya denk olup olmadığı sorulur. Paylaşılan alıştırmalar ve Sipser'in kitabındaki alıştırmalar çalışılmalıdır.

## 4. Dönüşümün doğruluğunun ispatı

Prosedür kurulduktan sonra, NFA $M$ ile ondan elde edilen DFA $M'$'nün denk olduğu, yani $L(M) = L(M')$ olduğu ispatlanmalıdır. Diller dizgi kümeleri olduğu için iki yönlü kapsama gösterilir.

### 4.1 $L(M) \subseteq L(M')$

$w \in L(M)$ olsun, $w = a_1 a_2 \cdots a_k$. Bu, NFA'nın $q_0$'dan başlayıp $w$'nin sembollerini birer birer okuyarak $a_1$ ile bir duruma, $a_2$ ile başka bir duruma gittiği ve son sembolden sonra bir kabul durumu $q_f$'ye vardığı anlamına gelir.

NFA yolundaki oklar kesikli çizilir (ekrandan, 01:10:00). $q_i$'den $q_j$'ye $a_i$ ile giden kesikli ok, şu biçimde olası bir alt yolu gösterir:

$$q_i \xrightarrow{\varepsilon} \circ \xrightarrow{\varepsilon} \cdots \xrightarrow{\varepsilon} \circ \xrightarrow{a_i} \circ \xrightarrow{\varepsilon} \cdots \xrightarrow{\varepsilon} q_j$$

Yani geçiş doğrudan olmayabilir, sembolün öncesinde ve sonrasında null geçişleri olabilir. DFA'da $\varepsilon$ geçişi olmadığı için oradaki oklar düz çizilir.

Gösterilecek şey daha genel bir iddiadır: NFA'da $q_0, q_i, q_j, \dots, q_l, q_m$ durumlarından geçiliyorsa, DFA'da aynı sembollerle bu durumları içeren kümelerden geçilir; $\{q_0, \dots\}$, $\{q_i, \dots\}$, $\{q_j, \dots\}$ ve böyle devam eder. Son sembolden sonra varılan DFA durumu $q_f$'yi içerir ve dolayısıyla kabul durumudur. İspat okunan dizginin uzunluğu $|v|$ üzerinde tümevarımla yapılır.

**Tümevarım tabanı:** $|v| = 1$, $v = a_1$ (ekrandan, 01:15:00). NFA'da $q_0$'dan $a_1$ ile $q_i$'ye gidiliyorsa, DFA $\{q_0,\dots\}$ durumunda $a_1$ okununca $q_i$'yi içeren bir duruma gidecek biçimde kurulmuştur. Taban, $M'$'nün kuruluşu gereği doğrudur.

**Tümevarım hipotezi:** $1 \le |v| \le k$ için iddianın doğru olduğu varsayılır: NFA'da $v = a_1 \cdots a_k$ ile $q_0 \to q_i \to q_j \to \cdots \to q_c \to q_d$ yolu varsa, DFA'da $\{q_0,\dots\} \to \{q_i,\dots\} \to \cdots \to \{q_c,\dots\} \to \{q_d,\dots\}$ yolu vardır.

**Tümevarım adımı:** $|v| = k+1$, $v = a_1 a_2 \cdots a_k a_{k+1} = v' a_{k+1}$ (ekrandan, 01:20:00). $v'$ kısmı için hipotez geçerlidir: NFA'da $v'$ ile $q_d$'ye varılıyorsa DFA'da $v'$ ile $q_d$'yi içeren bir duruma varılır. NFA'da $q_d$'den $a_{k+1}$ ile $q_e$'ye gidiliyorsa, DFA o durumdan $a_{k+1}$ ile $q_e$'yi içeren bir duruma gidecek biçimde kurulmuştur. Bu da kuruluş gereği doğrudur ve ispatı tamamlar.

Sonuç: $w$ NFA'nın dilindeyse, yani $q_0$'dan başlayıp bir kabul durumunda bitiyorsa, DFA'nın başlangıç durumundan başlayınca $q_f$'yi içeren bir duruma varılır; bu durum kabul durumudur ve $w \in L(M')$'dür.

### 4.2 $L(M') \subseteq L(M)$

Bu yön aynı mantıkla, yine tümevarımla ispatlanır. Derste atlandı; evde denenmesi istendi. İki kapsama birlikte $L(M) = L(M')$ verir: her NFA denk bir DFA'ya çevrilebilir ve dilleri aynıdır.

Hoca son ispatın biraz karmaşık göründüğünü ama adım adım dikkatle izlenirse zor olmadığını söyledi.

## 5. Düzenli dillerin kapalılık özellikleri

NFA'lar ve DFA'lar düzenli dilleri kabul eder; bir dil bir NFA ya da DFA tarafından kabul ediliyorsa düzenlidir. Düzenli dillerin, problemler üzerinde çalışırken çok işe yarayan özellikleri vardır. $L_1$ ve $L_2$ düzenliyse şunlar da düzenlidir:

- Birleşim: $L_1 \cup L_2$
- Birleştirme (concatenation): $L_1 L_2$
- Yıldız: $L_1^*$
- Ters: $L_1^R$
- Tümleyen: $\overline{L_1}$
- Kesişim: $L_1 \cap L_2$

"Kapalı" (closed) şu demektir: işlem düzenli dillere uygulandığında sonuç da düzenli olur. Bu yüzden düzenli diller bu işlemler altında kapalıdır denir.

İspat yöntemi kuruluşla ispattır (proof by construction): sonuç dilini kabul eden bir NFA kurulur ve dilin o NFA tarafından kabul edildiği gösterilir. Bir dil bir NFA ya da DFA tarafından kabul ediliyorsa düzenlidir.

### 5.1 Yararlı dönüşüm: tek kabul durumu

Birden fazla kabul durumu olan bir NFA, tek kabul durumlu denk bir NFA'ya çevrilebilir (ekrandan, 01:35:00). Orijinal kabul durumları kabul olmayan yapılır, yeni bir kabul durumu eklenir ve eski kabul durumlarından bu yeni duruma null geçişleri çizilir. Ekrandaki örnekte iki kabul durumlu NFA (başlangıçtan $a$ ile birinci kabul durumuna, oradan $b$ ve $a$ ile başlangıca dönen bir döngü; başlangıçtan $b$ ile ikinci kabul durumuna) bu biçimde tek kabul durumlu NFA'ya çevrilmişti. Uç durumda NFA'nın hiç kabul durumu yoksa yine yeni bir kabul durumu eklenir, ama ona hiçbir geçiş çizilmez. Tek kabul durumu olması aşağıdaki kuruluşlarda işe yarar.

### 5.2 Örneklerde kullanılan diller

$L_1$ ve $L_2$ düzenli diller, $M_1$ ve $M_2$ onları kabul eden makineler olsun: $L(M_1) = L_1$, $L(M_2) = L_2$. Bu, dildeki herhangi bir dizgi başlangıç durumundan okunduğunda bir kabul durumunda bitildiği anlamına gelir. Örneklerde şu diller kullanıldı:

- $L_1 = \{a^n b : n \ge 0\}$: başlangıç durumunda $a$ döngüsü, $b$ ile kabul durumuna geçiş. Örneğin $aab$: iki $a$ ile döngüde kalınır, $b$ ile kabul durumuna gidilir.
- $L_2 = \{ba\}$: yalnız tek dizgisi vardır; $b$ sonra $a$ okununca kabul durumuna varılır.

İkisini de bir otomat kabul ettiği için ikisi de düzenlidir.

## 6. Birleşim, birleştirme ve yıldız

### 6.1 Birleşim

$L_1 \cup L_2$ için NFA (ekrandan, 01:40:00): yeni bir başlangıç durumu eklenir ve bu durumdan $\varepsilon$ geçişleriyle $M_1$'in ve $M_2$'nin başlangıç durumlarına gidilir. Gerisi $M_1$ ve $M_2$'nin aynen kopyalanmasıdır.

$$w \in L_1 \cup L_2 \iff w \in L_1 \text{ ya da } w \in L_2$$

$w$ birleşimdeyse ya $L_1$'dedir ya $L_2$'dedir. $L_1$'deyse, $\varepsilon$ geçişleri yüzünden dizgi hem üstte hem altta okunmaya başlar; üst dal ($M_1$) onu kabul eder, alt dalın kabul edip etmediği bilinmez. $L_1$'de değilse $L_2$'dedir ve alt dal ($M_2$) kabul eder. Her durumda dallardan biri kabul ettiği için NFA kabul eder; birleşimi kabul eden bir NFA olduğundan birleşim düzenlidir.

Örnek (ekrandan, 01:45:00): $L_1 \cup L_2 = \{a^n b\} \cup \{ba\}$ için NFA'nın $aab$'yi kabul edip etmediği izlendi. Daha hiçbir şey okunmadan, makine başlar başlamaz null geçişleri yüzünden iki dalın başlangıç durumu etkin olur; iki paralel makine vardır. İlk $a$ okununca üst makine kendi başlangıç durumuna geri döner. Alt makinenin başlangıcında $a$ geçişi yoktur; bu dal ilk $a$'dan sonra durur, ölür. Üst dal hâlâ etkindir; ikinci $a$ ile yine başlangıca döner, sonra $b$ ile kabul durumuna geçer. Girdinin tamamı tüketilmiştir ve bir kabul durumunda bulunulmaktadır; makine $aab$'yi kabul eder.

### 6.2 Birleştirme

$L_1 L_2$ için NFA (ekrandan, 01:50:00): $M_1$'in kabul durumu sıradan (kabul olmayan) duruma çevrilir ve ondan $M_2$'nin başlangıç durumuna bir null geçişi eklenir. İki NFA seri bağlanmış olur.

$$w \in L_1 L_2 \iff w = w_1 w_2,\quad w_1 \in L_1 \text{ ve } w_2 \in L_2$$

Birleştirme dilindeki her $w$ iki parçadan oluşur. $M_1$'in başlangıcından başlanınca $w_1$ parçası $M_1$'in eski kabul durumuna getirir, null geçişiyle doğrudan $M_2$'nin başlangıç durumuna geçilir. $w_2$ parçası bu başlangıçtan kabul durumuna götürür. Dolayısıyla birleştirme dilindeki her dizgi bu NFA tarafından kabul edilir ve birleştirme dili düzenlidir.

Örnek: $L_1 L_2 = \{a^n b\}\{ba\} = \{a^n b b a\}$. Bu dilden bir dizgi $aabba$'dır. İlk iki $a$ ile $M_1$'in başlangıcında kalınır, $b$ ile $M_1$'in eski kabul durumuna gelinir, $\varepsilon$ geçişiyle $M_2$'nin başlangıcına geçilir, sonraki $b$ ve $a$ ile kabul durumuna varılır. $aabba$ kabul edilir.

### 6.3 Yıldız

$L^*$ için NFA (ekrandan, 02:10:00): orijinal otomatın kabul durumu kabul olmayan duruma çevrilir ve ondan yeni bir kabul durumuna $\varepsilon$ geçişi eklenir. Bu yeni kabul durumu aynı zamanda yeni başlangıç durumudur ve ondan orijinal başlangıç durumuna da $\varepsilon$ geçişi eklenir. $L^*$'daki her dizgi bu NFA tarafından kabul edilir; bu yüzden $L^*$ düzenlidir.

Örnek: $L_1^* = \{a^n b\}^*$ için kurulan NFA'da $abaab$ izlendi; bu dizgi $ab$ ile $aab$'nin birleştirmesidir.

- Başlangıçta kabul eden yeni başlangıç durumundayız; $\varepsilon$ geçişi yüzünden hiçbir şey okumadan eski başlangıç durumu da etkindir. İki durum etkindir.
- $a$ okunur: eski başlangıç durumu $a$ döngüsüyle etkin kalır; yeni başlangıç durumu $a$'yı tüketemediği için ölür.
- $b$ okunur: eski kabul durumuna gelinir; null geçişiyle yeni başlangıç durumu, ondan da null geçişiyle eski başlangıç durumu etkinleşir. $ab$ okunduğunda üç durum birden etkindir.
- $a$ okunur: $a$'yı tüketemeyen iki durum ölür, eski başlangıç durumu $a$ okuyup kendine döner. İkinci $a$ ile yine kendine döner.
- $b$ okunur: eski kabul durumuna, null geçişleriyle yeni başlangıç durumuna ve eski başlangıç durumuna girilir; yine üç durum etkindir.

Girdinin tamamı bitmiştir ve etkin durumlardan biri kabul durumudur; dizgi kabul edilir.

> **Ek bilgi (derste anlatılmadı):** Bu kuruluşta yeni başlangıç durumunun kabul durumu olması, $L^*$'ın her zaman boş dizgi $\varepsilon$'u içermesinden kaynaklanır ($L^0 = \{\varepsilon\}$). Yeni başlangıç durumu eklemek yerine yalnız eski başlangıç durumunu kabul yapmak, başlangıca geri dönen geçişler varsa $L^*$'da olmayan bazı dizgileri de kabul ettirebilir; bu yüzden ayrı bir durum kullanılır.

## 7. Ters ve tümleyen

### 7.1 Ters

$w \in L$ ise $w^R \in L^R$'dir; $L^R$'deki bütün dizgiler orijinal dildeki dizgilerin tersleridir. $L^R$ için NFA $M'$ (ekrandan, 02:15:00):

1. Bütün geçişlerin yönü ters çevrilir.
2. Başlangıç durumu kabul durumu, kabul durumu başlangıç durumu yapılır. Orijinaldeki son kabul durumu, kabul olmayan bir başlangıç durumu olur.

Örnek: $L_1 = \{a^n b\}$ için $M_1$'den kurulan $M'_1$'de orijinal başlangıç durumu ($a$ döngüsüyle) kabul durumu olur, orijinal kabul durumu başlangıç durumu olur ve $b$ oku ters döner. Ok artık bu duruma "hiçbir yerden" geldiği için orası başlangıç durumudur. Bu NFA $L_1^R = \{b a^n\}$'i kabul eder; NFA olduğu için $L_1^R$ düzenlidir.

> **Ek bilgi (derste anlatılmadı):** Ters kuruluşu, orijinal NFA'nın tek kabul durumu olmasını varsayar; aksi hâlde ters NFA'da birden fazla başlangıç durumu gerekirdi. Bölüm 5.1'deki tek kabul durumu dönüşümü önce uygulanarak bu varsayım her zaman sağlanabilir.

### 7.2 Tümleyen

$\overline{L}$ için yeni bir otomat kurulur, ama dikkat gerekir: orijinal dili kabul eden bir **DFA** alınır; kabul durumları kabul olmayan, kabul olmayan durumlar kabul durumu yapılır. Slaytta "DFA" sözcüğü kırmızıyla vurgulanmıştır, çünkü bu yöntem NFA'larda yapılamaz.

Örnek (ekrandan, 02:20:00): $L_1 = \{a^n b\}$ için DFA $M_1$: başlangıç durumunda $a$ döngüsü, $b$ ile kabul durumuna, kabul durumundan $a,b$ ile tuzak duruma, tuzak durumda $a,b$ döngüsü. Tümleyen için $M'_1$'de yalnız kabul olma durumları yer değiştirir:

| Durum | $M_1$'de | $M'_1$'de |
|---|---|---|
| Başlangıç ($a$ döngüsü) | kabul değil | kabul |
| $b$ ile varılan durum | kabul | kabul değil |
| Tuzak durum ($a,b$ döngüsü) | kabul değil | kabul |

Tümleyen dil, alfabedeki bütün dizgilerden orijinal dilin farkıdır:

$$\overline{L_1} = \{a,b\}^* - \{a^n b\}.$$

**NFA ile neden olmaz** (karşı örnek): tek durumlu, bu durumu başlangıç olan ve kabul olmayan, hiç geçişi olmayan bir NFA $M$ düşünelim. Dili boş kümedir: $L(M) = \{\}$, hiçbir şey kabul etmez. Tümleyeni alfabeyle elde edilebilen bütün dizgilerdir: $\overline{L(M)} = \Sigma^* = \{a,b\}^*$. Ama yukarıdaki yöntemle durumu kabul durumu yapınca elde edilen $M'$ yalnız boş dizgiyi kabul eder: hiçbir şey okumadan kabul eder, bir şey okuyunca (geçiş olmadığı için) reddeder. Yani

$$L(M') = \{\varepsilon\} \ne \overline{L(M)}.$$

Bir tarafta bütün olası dizgiler, öbür tarafta yalnız boş dizgiyi içeren bir küme vardır; ikisi aynı değildir.

> **Hocanın vurgusu:** Tümleyen alırken DFA ile başladığınızdan emin olun, NFA ile değil.

> **Ek bilgi (derste anlatılmadı):** Yöntem NFA'da şu yüzden bozulur: NFA'da bir dizgi için hem kabul eden hem reddeden dallar aynı anda olabilir ya da geçiş eksikliği yüzünden bütün dallar ölebilir. Kabul ve red durumlarını yer değiştirmek bu durumları doğru tersine çevirmez. DFA'da ise her dizgi için tek ve tam tanımlı bir yol vardır; bu yüzden yer değiştirme tam olarak tümleyeni verir.

## 8. Kesişim

### 8.1 De Morgan kuralı ile

$L_1$ ve $L_2$ düzenliyse $L_1 \cap L_2$'nin de düzenli olduğu De Morgan kuralıyla doğrudan gösterilebilir (ekrandan, 02:25:00):

$$L_1 \cap L_2 = \overline{\overline{L_1} \cup \overline{L_2}}$$

İki kümenin kesişimi, tümleyenlerinin birleşiminin tümleyenine eşittir; bu bütün kümeler için geçerli bir kuraldır. Adımlar:

- $L_1$, $L_2$ düzenli.
- $\overline{L_1}$, $\overline{L_2}$ düzenli (tümleyen altında kapalılık).
- $\overline{L_1} \cup \overline{L_2}$ düzenli (birleşim altında kapalılık).
- $\overline{\overline{L_1} \cup \overline{L_2}}$ düzenli (yine tümleyen).
- De Morgan kuralına göre bu $L_1 \cap L_2$'dir; dolayısıyla kesişim düzenlidir.

Örnek: $L_1 = \{a^n b\}$ ve $L_2 = \{ab, ba\}$ düzenli; kesişimleri $L_1 \cap L_2 = \{ab\}$ de düzenlidir.

### 8.2 Çarpım DFA'sı ile

Aynı sonuç bir DFA kurarak da gösterilebilir. $M_1$, $L_1$ için; $M_2$, $L_2$ için bir DFA olsun. Kesişimi kabul eden yeni DFA $M$, $M_1$ ile $M_2$'yi paralel olarak simüle eder:

- $M_1$'deki her $q_i$ ve $M_2$'deki her $p_j$ için $M$'de $(q_i, p_j)$ etiketli bir durum vardır.
- $M_1$'de $q_1 \xrightarrow{a} q_2$ ve $M_2$'de $p_1 \xrightarrow{a} p_2$ geçişleri varsa $M$'de $(q_1,p_1) \xrightarrow{a} (q_2,p_2)$ geçişi eklenir.
- İki başlangıç durumu birleşip $(q_0, p_0)$ başlangıç durumunu oluşturur.
- $q_i$ $M_1$'de, $p_j$ ve $p_k$ $M_2$'de kabul durumuysa $(q_i, p_j)$ ve $(q_i, p_k)$ yeni kabul durumlarıdır. Her iki bileşen de kabul durumu olmalıdır (ekrandan, 02:40:00).

Kuruluş prosedürü (ekrandan, 02:35:00):

1. Başlangıç durumunu kur.
2. Her yeni durum ve her sembol için ya var olan bir duruma geçiş ekle ya da yeni bir durum yaratıp ona geçiş ekle.
3. Yeni durum eklenmeyene kadar Adım 2'yi tekrarla.
4. Kabul durumlarını belirle.

Hoca, kesişim kuruluşunun ihtiyaç da olabileceğini söyledi: iki otomatın kesişimini bulma ya da iki dilin kesişimini kabul eden otomatı bulma sorusu gelebilir; basit örneklerde DFA doğrudan yazılabilir ama her zaman böyle olmayabilir, bir kesişimin programını yazmak bile gerekebilir.

**Örnek** (ekrandan, 02:30:00): $L_1 = \{a^n b : n \ge 0\}$, $L_2 = \{a b^m : m \ge 0\}$.

$M_1$ geçişleri:

| Durum | $a$ | $b$ |
|---|---|---|
| $\to q_0$ | $q_0$ | $q_1$ |
| $q_1$ (kabul) | $q_2$ | $q_2$ |
| $q_2$ (tuzak) | $q_2$ | $q_2$ |

$M_2$ geçişleri:

| Durum | $a$ | $b$ |
|---|---|---|
| $\to p_0$ | $p_1$ | $p_2$ |
| $p_1$ (kabul) | $p_2$ | $p_1$ |
| $p_2$ (tuzak) | $p_2$ | $p_2$ |

Hoca kuruluşu slayttaki sonuçla karşılaştırarak adım adım izledi. Başlangıç $(q_0, p_0)$'dır. $a$ ile $q_0 \to q_0$, $p_0 \to p_1$; yani $(q_0, p_1)$. $b$ ile $q_0 \to q_1$, $p_0 \to p_2$; yani $(q_1, p_2)$. İki yeni durum oluştu; her biri için $a$ ve $b$'de ne olduğu sorulur. Örneğin $(q_0, p_1)$'de $a$ gelirse $q_0 \to q_0$, $p_1 \to p_2$; yeni durum $(q_0, p_2)$ oluşur. Yeni durum oluşmayana, mevcut bütün durumların her sembolde nereye gittiği çizilene kadar böyle devam edilir. Sonuç (ekrandan, 02:35:00):

| Durum | $a$ | $b$ |
|---|---|---|
| $\to (q_0,p_0)$ | $(q_0,p_1)$ | $(q_1,p_2)$ |
| $(q_0,p_1)$ | $(q_0,p_2)$ | $(q_1,p_1)$ |
| $(q_1,p_1)$ (kabul) | $(q_2,p_2)$ | $(q_2,p_1)$ |
| $(q_1,p_2)$ | $(q_2,p_2)$ | $(q_2,p_2)$ |
| $(q_0,p_2)$ | $(q_0,p_2)$ | $(q_1,p_2)$ |
| $(q_2,p_1)$ | $(q_2,p_2)$ | $(q_2,p_1)$ |
| $(q_2,p_2)$ | $(q_2,p_2)$ | $(q_2,p_2)$ |

Son adımda kabul durumları belirlenir. $q_1$ ve $p_1$ kabul durumlarıdır; ama yalnız ikisini birden içeren $(q_1, p_1)$ kabul durumu yapılır. İçinde yalnız $q_1$ ya da yalnız $p_1$ geçen çiftler kabul değildir. Bu DFA'nın dili

$$L(M) = \{a^n b\} \cap \{a b^m\} = \{ab\}.$$

(Ders sonrası kontrol: çarpım DFA'sı python ile yeniden kuruldu; erişilebilir 7 durum ve geçişleri tabloyla aynı çıktı, 6 uzunluğa kadar yalnız $ab$ kabul edildi.)

> **Hocanın vurgusu:** Kesişim DFA'sında kabul durumu, her iki bileşeni de kabul olan durumdur. Hepsinde $q_1$ olanları kabul yapmak yanlış olur.

**Soru:** Kesişim olduğu için yalnız ikisinin ortak olduğu kısım kabul olmaz mı? **Cevap:** Evet, öyle oluyor; her ikisinin kabul durumlarını içeren durum kabul durumu olarak alındı.

Hoca bu basit örnekte kesişim dilinin $\{ab\}$ olduğunu ve bunun için bütün bu düzeneğe gerek kalmadan doğrudan bir DFA yazılabileceğini de gösterdi (başlangıç, $a$ ile ara durum, $b$ ile kabul durumu); bu DFA yazılabildiği için kesişim düzenlidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00 ve 00:40:00): Geçişleri $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_1$, $q_1 \xrightarrow{\varepsilon} q_2$, $q_2 \xrightarrow{b} q_0$ olan, başlangıç durumu $q_0$ ve kabul durumu $q_1$ olan NFA $M$'yi denk bir DFA $M'$'ye çevirin.

> **Çözüm (derste verildi):** $\{q_0\} \xrightarrow{a} \{q_1,q_2\}$ ($\varepsilon$ geçişi yüzünden $q_2$ de etkin), $\{q_0\} \xrightarrow{b} \varnothing$ (tuzak). $\{q_1,q_2\} \xrightarrow{a} \{q_1,q_2\} \cup \varnothing = \{q_1,q_2\}$, $\{q_1,q_2\} \xrightarrow{b} \{q_0\}$. $\varnothing \xrightarrow{a,b} \varnothing$. $q_1$'i içerdiği için kabul durumu $\{q_1,q_2\}$'dir. Tablo Bölüm 3.1'dedir.

**Soru 2** (derste sözlü, 00:40:23): Dönüşümde $q_1$ durumundayken $b$ okunursa $q_0$'a geçilmez mi, $\delta^*(q_1,b)$ neden boş küme yazıldı?

> **Çözüm (derste verildi):** İki bakış da mümkündür; hoca $\varepsilon$ geçişinden sonra $q_1$ ve $q_2$'yi ayrı makineler olarak düşünüp $q_1$'in $b$ okuyamadığını söyledi. Birleşim her iki bakışta $\{q_0\}$ çıkar. Bölüm 3.1'deki ders sonrası nota bakın: slayttaki $\delta^*$ tanımıyla $\delta^*(q_1,b) = \{q_0\}$'dır.

**Soru 3** (ekrandan, 01:45:00): $L_1 \cup L_2 = \{a^n b\} \cup \{ba\}$ için kurulan NFA $aab$'yi kabul eder mi?

> **Çözüm (derste verildi):** Başlangıçta $\varepsilon$ geçişleriyle iki dal etkinleşir. İlk $a$'da $\{ba\}$ dalı ölür; $\{a^n b\}$ dalı $a, a$ ile döngüde kalır ve $b$ ile kabul durumuna geçer. Girdi bitmiştir ve bir kabul durumundayız: kabul eder.

**Soru 4** (derste sözlü, 01:51:04): $L_1 L_2 = \{a^n b\}\{ba\}$ için kurulan NFA $aabba$'yı kabul eder mi?

> **Çözüm (derste verildi):** $aa$ ile $M_1$'in başlangıcında kalınır, $b$ ile $M_1$'in eski kabul durumuna, $\varepsilon$ ile $M_2$'nin başlangıcına geçilir; $b$ ve $a$ ile $M_2$'nin kabul durumuna varılır. Kabul eder.

**Soru 5** (ekrandan, 02:10:00): $\{a^n b\}^*$ için kurulan NFA $abaab$'yi kabul eder mi?

> **Çözüm (derste verildi):** $abaab = ab \cdot aab$. Her $b$'den sonra $\varepsilon$ geçişleriyle eski kabul durumu, yeni başlangıç/kabul durumu ve eski başlangıç durumu birlikte etkin olur. Girdi bittiğinde etkin durumlardan biri kabul durumudur: kabul eder (adımlar Bölüm 6.3'te).

**Soru 6** (ekrandan, 02:30:00 ve 02:35:00): $L_1 = \{a^n b\}$ ve $L_2 = \{a b^m\}$ dillerinin DFA'ları verildiğinde, kesişimi kabul eden DFA'yı kurun.

> **Çözüm (derste verildi):** Çarpım DFA'sı Bölüm 8.2'deki tablodur. Tek kabul durumu $(q_1,p_1)$'dir ve $L(M) = \{ab\}$'dir.

## Dersin Toparlaması

Bu derste önce NFA'ların ve DFA'ların aynı hesaplama gücüne sahip olduğu ispatlandı: her DFA zaten bir NFA'dır ve her NFA, durumları NFA durum kümeleri olan bir DFA'ya alt küme yapısıyla çevrilebilir. Dönüşümde her küme durumu ve her sembol için üyelerin $\delta^*$ sonuçlarının birleşimi alınır, boş küme tuzak durum olur ve NFA'nın bir kabul durumunu içeren her küme kabul durumu yapılır. Dönüşümün dili koruduğu, dizgi uzunluğu üzerinde tümevarımla gösterildi. Hoca bu dönüşümün sınavlarda sorulduğunu özellikle belirtti.

Ardından düzenli dillerin birleşim, birleştirme, yıldız, ters, tümleyen ve kesişim altında kapalı olduğu, her işlem için sonuç dilini kabul eden bir NFA kurularak gösterildi. Tümleyende DFA ile başlamanın şart olduğu bir karşı örnekle vurgulandı. Kesişim hem De Morgan kuralıyla hem de iki DFA'yı paralel çalıştıran çarpım DFA'sıyla elde edildi. Hoca, paylaşılan alıştırmaların ve Sipser'in kitabındaki alıştırmaların çalışılmasını önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
