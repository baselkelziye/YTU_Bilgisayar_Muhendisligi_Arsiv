# Ders 14 Genişletilmiş Notu: Turing Makinesi Varyasyonları, Evrensel Turing Makinesi ve Sayılabilirlik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Turing tezi ve algoritmanın tanımı
- 2. Standart Turing makinesi ve aynı güç kavramı
- 3. Stay-option Turing makinesi (tekrar)
- 4. Çok izli şerit
- 5. Yarı sonsuz şeritli Turing makinesi
- 6. Çok şeritli Turing makinesi
- 7. Çok boyutlu Turing makinesi
- 8. Deterministik olmayan Turing makinesi
- 9. Evrensel Turing makinesi
- 10. Sayılabilir kümeler ve sayıcılar
- 11. Turing makineleri sayılabilir, diller sayılamaz
- Örnek Sorular

## 1. Turing tezi ve algoritmanın tanımı

Ders, önceki hafta görülen Turing tezinin tekrarıyla başladı. Slaytta tez şöyle yazıyor (ekrandan, 00:10:00): *Any computation carried out by mechanical means can be performed by a Turing Machine.* Yani mekanik yollarla yapılabilen her hesaplama bir Turing makinesiyle yapılabilir. Hoca bunu günlük dile şöyle çevirdi: bir bilgisayarın (örneğin önünüzdeki PC'nin) yapabildiği her hesaplamayı bir Turing makinesi de yapabilir.

> **Ders sonrası not:** Slaytta tezin yılı "1930" olarak yazıyor, altyazıda hoca "1939" der gibi duyuluyor. Turing'in makineyi tanıttığı makale büyük olasılıkla 1936 tarihlidir; tarih slayttaki gibi yaklaşık bir yıl olarak alınmalıdır.

Bu tezin tersinden bir **algoritma tanımı** çıkar: bir problem için algoritma vardır demek, o problemi çözen bir Turing makinesi vardır demektir. Derslerde algoritmalar sözde kodla (pseudocode) anlatılır; örneğin kabarcık sıralaması (bubble sort) ya da hızlı sıralama (quick sort) adım adım yazılır. Bu adımlar en alt düzeyde bir Turing makinesinin geçişlerine karşılık gelir: makine $q_1$ durumundan $q_2$ durumuna geçer, şeritten bir sembol okur, bir sembol yazar, sağa ya da sola gider. Bütün bunlar bir araya gelince bir algoritma elde edilir.

Böylece algoritmanın biçimsel (formal) bir tanımı elde edilmiş olur. Bir problem için onu çözen bir Turing makinesi yazılamıyorsa o problem çözümsüzdür; bilgisayarla çözülemez. Hoca bunun önemini şöyle açıkladı: dersin kitabında algoritmalar Turing makinesi tabanlı olarak sınıflanır (zor ama çözülebilen problemler, hiç çözülemeyen problemler gibi). Bir problemin çözülemeyeceği ispatlanabilirse insanlar ona boşuna çözüm aramaz; problemi basitleştirmeye ya da başka bir yöne çalışırlar.

## 2. Standart Turing makinesi ve aynı güç kavramı

Varyasyonlardan söz etmek için önce standart makine tanımlandı (ekrandan, 00:15:00):

- İki yönde de sonsuz bir şerit (infinite tape). Şeritte giriş dizisi vardır, gerisi boşluk ($\diamond$) sembolüdür.
- Bir okuma-yazma kafası (read-write head): bulunduğu hücredeki sembolü okur, yerine yeni bir sembol yazar, sonra sağa ya da sola gider.
- Bir kontrol birimi (control unit): durumlar ($q_1, q_2, \dots$) ve aralarındaki geçişler.
- Model deterministiktir: aynı durum ve aynı okunan sembol için tek bir geçiş vardır.

Derste bu modelin varyasyonları görüldü ve hiçbirinin standart makineden **daha güçlü olmadığı** gösterildi. Burada güç, kabul edilebilen dillerle ölçülür. Bir dil bir problem olarak da düşünülebilir; daha güçlü bir makine, standart makinenin kabul edemediği bir dili kabul edebilmeli, yani çözemediği bir problemi çözebilmelidir. Varyasyonların hiçbiri bunu yapamaz. Hız farkı ise olabilir. Hoca deterministik olmayan Turing makinelerini paralel programlamaya benzetti: paralel programlamayla seri olarak çözülemeyen yeni bir problem çözülmez, aynı problem çözülür, ama iş dağıtıldığı için daha hızlı biter.

İki makine sınıfı için **aynı güç (same power)**, iki sınıfın aynı dil kümesini kabul etmesi demektir. Örneğin $M_1$ standart sınıftan, $M_2$ stay-option sınıfından olsun; aynı güç için $L(M_1) = L(M_2)$ olmalıdır. Diller küme olduğu için eşitlik, iki yönlü alt küme ilişkisiyle gösterilir. Derste bunun yerine buna denk olan **simülasyon** yöntemi kullanıldı:

- Birinci sınıftaki makinenin yaptığı her adımı ikinci sınıftaki bir makine, kendi imkanlarıyla, belki birkaç adımda yapabiliyorsa, ikinci sınıf birinci sınıfı simüle eder denir.
- Bu durumda ikinci sınıf aynı konfigürasyonlara, dolayısıyla aynı kabul konfigürasyonuna da ulaşır.
- Simülasyon iki yönde de gösterilirse iki sınıf aynı güçtedir.

## 3. Stay-option Turing makinesi (tekrar)

İlk varyasyon önceki derste görülmüştü. Stay-option makinede kafa sağa (R) ve sola (L) gidebildiği gibi yerinde de kalabilir (S, stay). Örneğin $q_1 \xrightarrow{a \to b,\, S} q_2$ geçişi $a$ okur, $b$ yazar ve kafayı hareket ettirmez.

**Teorem:** Stay-option Turing makineleri standart Turing makineleriyle aynı güçtedir.

**1. adım: stay-option makine standart makineyi simüle eder.** Bu önemsizdir (trivial). Stay-option makinede eksik yok, fazla vardır; standart makinedeki her şey burada da vardır. Başka bir bakışla her standart makine zaten bir stay-option makinedir.

**2. adım: standart makine stay-option makineyi simüle eder** (ekrandan, 00:25:00). Fazla olan tek geçiş türü $S$ hareketli geçiştir. Kitabın yazarının önerdiği yöntem şudur: $a$ okunur, $b$ yazılır, ama yerinde kalınamadığı için kafa sola gider. Doğrudan $q_2$'ye gidilmez; yeni bir ara duruma gidilir. Oradan kafa sağa giderek $q_2$'ye geçilir. Sola gidip sağa dönünce kafa aynı hücreye gelir; yerinde kalmış olur.

| Adım | Stay-option makine | Standart makinedeki karşılığı |
|---|---|---|
| 1 | $q_1 \xrightarrow{a \to b,\, S} q_2$ | $q_1 \xrightarrow{a \to b,\, L} q_{ara}$ |
| 2 | (yok) | her şerit sembolü $x$ için $q_{ara} \xrightarrow{x \to x,\, R} q_2$ |

Burada bir incelik var: kafa sola gittiğinde orada hangi sembolün bulunduğu bilinmez ($a$, $b$, $c$ ya da başka bir şey olabilir). Bu yüzden ikinci geçiş **bütün olası şerit sembolleri** için eklenir; sembol okunur, aynen geri yazılır ve kafa sağa gider. Bu geçişler $\delta$ geçiş fonksiyonunun tablosuna eklenir. Stay-option makine tek hareketle yaptığı işi standart makine iki hareketle yapar, ama sonuç aynıdır. Simülasyon için gereken geçiş inşa edildiği için bu bir **yapıyla ispattır (proof by construction)**.

## 4. Çok izli şerit

Bu yeni bir makine değil, sonraki ispatlarda işe yarayan bir hiledir (ekrandan, 00:30:00). Çok izli şeritte (multiple track tape) şeridin birden fazla izi (track) vardır; örneğin 1. izde $\diamond\ \diamond\ a\ b\ a\ b\ \diamond$, 2. izde $\diamond\ \diamond\ b\ a\ c\ d\ \diamond$ yazılıdır ve tek bir kafa bir sütunu gösterir.

Bu makine aslında tek izli standart bir Turing makinesidir: aynı sütundaki semboller birlikte **tek bir sembol** sayılır. Kafanın gösterdiği sütundaki sembol $(a,b)$ çiftidir. Şerit alfabesi $(a,b), (b,a), (b,c), \dots$ gibi çiftlerden oluşur. Sembolün adının ne olduğu önemli değildir; istenirse $(a,b)$'ye $A_1$, $(b,a)$'ya $A_2$ gibi yeni adlar verilebilir. İki iz varsa semboller çift, üç iz varsa üçlü olur.

Geçişler bu çiftlerle yazılır. Örneğin $(b,a) \to (c,d), L$ geçişi $(b,a)$ sembolünü okur, $(c,d)$ sembolünü yazar ve sola gider. Bunun dışında her şey standart makinedeki gibidir.

## 5. Yarı sonsuz şeritli Turing makinesi

Yarı sonsuz şeritli (semi-infinite tape) makinede şerit yalnız bir yöne, diyelim sağa doğru sonsuzdur; solda bir sınır vardır. Başlangıçta kafa ilk sembolü gösterir. Kafa sınırdan sola gitmeye çalışırsa gidemez, en soldaki konumda kalır.

**Teorem:** Yarı sonsuz şeritli makineler standart Turing makineleriyle aynı güçtedir.

### 5.1 Standart makine yarı sonsuz makineyi simüle eder

Bu yönde standart makinenin yeteneği daha fazladır; yarı sonsuz makineden bir şey eksiltilmiştir. Simülasyon şöyle yapılır (ekrandan, 00:35:00):

- a. Şerit sembolleri arasında olmayan özel bir $\#$ sembolü giriş dizisinin soluna konur. Bu sembol "sınırdayız" anlamına gelir.
- b. Her duruma (çıkış geçişi olmayan durumlar hariç) $\# \to \#, R$ öz döngüsü eklenir.

Kafa herhangi bir durumda $\#$ üzerine gelirse bu geçiş hemen çalışır: $\#$ geri yazılır ve kafa sağa, yani ilk sembole döner. Böylece sola gitmeye çalışıp sınırda kalma davranışı taklit edilir.

### 5.2 Yarı sonsuz makine standart makineyi simüle eder

Bu yön daha ilginçtir. Yarı sonsuz makinede iki izli bir şerit kullanılır. Standart makinenin şeridinde ortada bir **referans noktası** seçilir. Referansın sağındaki kısım (sağ parça) üst ize doğru sırayla, solundaki kısım (sol parça) alt ize **ters sırayla** yazılır; iki izin en solunda $\#$ vardır. Örneğin standart şerit $a\ b\ c \mid d\ e$ ise ($\mid$ referans noktası), üst izde $\#\ d\ e$, alt izde $\#\ c\ b\ a$ yer alır.

Standart makinedeki her $q$ durumu için yarı sonsuz makinede iki durum açılır: $q^L$ (kafa sol parçada, yani alt izde) ve $q^R$ (kafa sağ parçada, yani üst izde). Durum sayısı ikiye katlanır.

Standart makinedeki $q_1 \xrightarrow{a \to g,\, R} q_2$ geçişi için şu geçişler eklenir (ekrandan, 00:40:00):

| Parça | Eklenen geçiş (her şerit sembolü $x$ için) |
|---|---|
| Sağ parça | $q_1^R \xrightarrow{(a,x) \to (g,x),\, R} q_2^R$ |
| Sol parça | $q_1^L \xrightarrow{(x,a) \to (x,g),\, L} q_2^L$ |

Sağ parçada üst izdeki sembol okunup yazılır ve kafa aynı yönde (sağa) gider. Sol parçada alt izdeki sembol işlenir ve kafa **ters yönde** (sola) gider, çünkü alt izde sola gitmek gerçek şeritte sağa gitmek demektir. Diğer izdeki sembol $x$ hiç değiştirilmez; hangi sembol olduğu bilinmediği için geçiş bütün $x$ değerleri için yazılır, bu yüzden çok sayıda geçiş eklenir.

**Örnek** (ekrandan, 00:45:00). Standart makinede şerit $\diamond\ a\ b\ c\ d\ e\ \diamond$, kafa $a$ üzerinde ve durum $q_1$ olsun. $a \to g, R$ uygulanınca şerit $g\ b\ c\ d\ e$ olur, kafa $b$'ye gelir, durum $q_2$ olur. Yarı sonsuz makinede alt iz $\#\ c\ b\ a$ iken $a$ yerine $g$ yazılır (alt iz $\#\ c\ b\ g$ olur), kafa alt izde sola, yani $b$'ye gider ve durum $q_2^L$ olur. Üst iz ($\#\ d\ e$) değişmez.

**Sınırdaki durum.** Hoca tahtada örneği sürdürdü: kafa sol parçada ilerleyip $c$'yi de işlediğinde $\#$ sütununa gelir. Burada artık yer yoktur; geri dönmek gerekir. Ama geri dönünce kafa artık üst iz, yani sağ parça üzerindedir; bu yüzden durumlar $L$ kopyasından $R$ kopyasına geçmelidir. Bunun için şu geçişler eklenir:

- $q^L$ durumunda $(\#,\#)$ okunursa $(\#,\#)$ geri yazılır, kafa sağa gider ve durum $q^R$ olur.
- $q^R$ durumunda $(\#,\#)$ okunursa $(\#,\#)$ geri yazılır, kafa sağa gider ve durum $q^L$ olur.

Yani $\#$ üzerinde kafa hep sağa gider; değişen yalnız durumun L/R kopyasıdır. Ekrandaki örnekte (ekrandan, 00:50:00) zaman 1'de kafa $q_1^L$ durumunda $\#$ üzerindedir; zaman 2'de kafa ilk sütuna geçmiştir ve durum $q_1^R$'dir. Artık üst izdeki $d$ işlenir; alt izdeki $c$ önemsenmez ve değişmez.

Bu eklemelerle yarı sonsuz makine standart makineyi simüle eder. İki yön de gösterildiği için yarı sonsuz ve standart makineler aynı güçtedir.

## 6. Çok şeritli Turing makinesi

Aradan sonra hoca önce yarı sonsuz ispatı kısaca tekrarladı, sonra yeni varyasyona geçti. Çok şeritli (multi-tape) Turing makinesinde tek bir kontrol birimi ve birden fazla şerit (1. şerit, 2. şerit, gerekirse 3. şerit ...) vardır. Her şerit iki yönde de sonsuzdur. Başlangıçta giriş dizisi 1. şerittedir (ekrandan, 01:05:00).

Kontrol birimi tek olduğu için bir geçişte tek bir durum değişimi ($q_1 \to q_2$) olur, ama her şerit için ayrı okuma, yazma ve hareket bilgisi gerekir. Derste verilen örnek: 1. şeritte $b$ okunup $g$ yazılır ve kafa sola gider; 2. şeritte $f$ okunup $d$ yazılır ve kafa sağa gider. Geçiş etiketi bu bilgileri sırayla içerir; örneğin $(b, f) \to (g, d), L, R$ biçiminde yazılabilir.

<!-- BELİRSİZ: Slayttaki geçiş etiketinin tam yazımı karelerde görünmüyor; yukarıdaki biçim hocanın sözlü anlatımından kurulmuştur. -->

**Teorem:** Çok şeritli makineler standart Turing makineleriyle aynı güçtedir.

**1. adım: çok şeritli makine standart makineyi simüle eder** (ekrandan, 01:10:00). Önemsizdir: yalnız 1. şerit kullanılır, diğerleri hiç kullanılmaz.

**2. adım: standart makine çok şeritli makineyi simüle eder.** Burada yine çok izli şerit hilesi kullanılır. Çok şeritli makinenin her şeridi standart makinede **bir çift ize** karşılık gelir: bir izde şeridin içeriği, altındaki izde kafanın konumu bulunur. Kafanın bulunduğu sütunda 1, diğerlerinde 0 yazılır. En solda referans noktası olarak $\#$ kullanılır; hoca, yarı sonsuz makinelerin standart makineyi simüle edebildiğini bildiğimiz için bunun yarı sonsuz bir şeritle de yapılabileceğini belirtti. Slayttaki örnek (ekrandan, 01:15:00):

| İz | Sütunlar |
|---|---|
| 1. şerit içeriği | $\#\ a\ b\ c$ |
| 1. şerit kafa konumu | $\#\ 0\ 1\ 0$ |
| 2. şerit içeriği | $\#\ e\ f\ g\ h$ |
| 2. şerit kafa konumu | $\#\ 0\ 0\ 1\ 0$ |

Çok şeritli makinenin her geçişi için standart makine şunu yapar:

1. Referans noktasına (soldaki $\#$'lere) dön.
2. 1. izde kafa konumu 1 olan sütunu bul, sembolü güncelle, 1'i sil ve kafanın yeni konumuna 1 yaz.
3. Referans noktasına dön.
4. 2. şerit için aynı işlemi yap.

Böylece çok şeritli bir makine standart makineyle simüle edilir.

### 6.1 Aynı güç, aynı hız demek değildir

Hoca, güç ile hızın bu derste farklı şeyler olduğunu vurguladı (slayt, ekrandan, 01:15:00 karesinin "sonraki slayt" alanı). $L = \{a^n b^n\}$ dilini düşünelim:

- Standart Turing makinesi bu dili $O(n^2)$ zamanda tanır: $a$'larla $b$'leri eşlemek için şeritte $O(n)$ kez gidip gelir, her gidiş-dönüş $O(n)$ adımdır.
- İki şeritli makine $O(n)$ zamanda tanır: (1) $b^n$ kısmı 2. şeride kopyalanır ($O(n)$ adım); (2) iki kafa başa alınır ve birlikte sağa ilerletilerek 1. şeritteki $a$'lar 2. şeritteki $b$'lerle karşılaştırılır ($O(n)$ adım). Sonunda 1. şeritte $a$ yerine boşluk geldiğinde 2. şeritte de boşluk olup olmadığına bakılır.

> **Hocanın vurgusu:** Bu derste hız ile güç farklı şeylerdir. Aynı güçte iki makineden biri çok daha hızlı olabilir.

## 7. Çok boyutlu Turing makinesi

Çok boyutlu (multidimensional) makinede şerit iki, üç ya da daha çok boyutludur. İki boyutlu örnekte şerit bir düzlem gibidir; kafa bu ızgaradaki bir hücreyi gösterir (ekrandan, 01:20:00). Hareketler L ve R'ye ek olarak U (yukarı) ve D (aşağı) olur. Yazılan sembollerin dışındaki her yer boşluktur. Kafanın konumu koordinatla verilir; slayttaki örnekte kafa $b$ sembolünün bulunduğu $(+2, -1)$ konumundadır.

> **Ders sonrası not:** Altyazıda hoca konumu bir yerde "+2, -3" diye söylüyor; slaytta konum $+2, -1$ olarak yazılı ve hoca da devamında $y$ koordinatını $-1$ olarak veriyor. Doğrusu $(+2,-1)$'dir.

**Teorem:** Çok boyutlu makineler standart Turing makineleriyle aynı güçtedir.

**1. adım** önemsizdir: çok boyutlu makinede tek bir satır kullanılır, yalnız L ve R hareketleriyle çalışılır; bu satır zaten standart bir makinedir.

**2. adım: standart makine iki boyutlu makineyi simüle eder** (ekrandan, 01:25:00). Standart makinede iki iz kullanılır: üst izde semboller, alt izde o sembolün koordinatları. Örnekteki $b$ için üst ize $b$, altına $\#\,2\,\#\,-1\,\#$ yazılır; koordinatlar şerit alfabesinde olmayan bir ayırıcıyla ($\#$) ayrılır. Hoca isteyen için sembol-koordinat gruplarını başka bir ayırıcıyla (örneğin $@$), koordinatları $\#$ ile ayırmanın da mümkün olduğunu, bunun önemli olmadığını söyledi. İki boyutlu makinenin izlediği her geçiş için standart makine:

1. Geçerli sembolü günceller.
2. Bir sonraki konumun koordinatlarını hesaplar.
3. Şeritte bu konumu bulur ve oraya gider.

Hoca bu ispatların hepsinin birbirine çok benzediğini, birkaç hileyle her makinenin diğerini simüle edebildiğini belirtti.

## 8. Deterministik olmayan Turing makinesi

Standart Turing makineleri deterministiktir. Deterministik olmayan (nondeterministic) makinede aynı durumda aynı sembol okunduğunda birden fazla şey yapılabilir. Slayttaki örnekte (ekrandan, 01:40:00 karesinin "sonraki slayt" alanı) $q_1$ durumunda $a$ okunduğunda iki geçiş vardır:

| Geçiş | Yazılan | Hareket | Yeni durum |
|---|---|---|---|
| $q_1 \xrightarrow{a \to b,\, L} q_2$ | $b$ | L | $q_2$ |
| $q_1 \xrightarrow{a \to c,\, R} q_3$ | $c$ | R | $q_3$ |

Hoca boş geçiş (null transition) olmadığını, yalnız aynı durum ve aynı girdi için birden çok geçiş olduğunu belirtti. Zaman 1'de şerit $\diamond\ a\ b\ c\ \diamond$, kafa $a$ üzerinde ve durum $q_1$ ise, birinci seçenekte $b$ yazılıp sola gidilir ve $q_2$'ye geçilir; ikinci seçenekte makine kendini çoğaltır, şeridin bir kopyasıyla $c$ yazıp sağa gider ve $q_3$'e geçer. Bu bir bakıma yine paralel hesaplamadır.

Kabul koşulu (ekrandan, 01:30:00): giriş $w$, başlangıç konfigürasyonundan bir son konfigürasyona giden bir hesaplama varsa kabul edilir:

$$q_0 w \overset{*}{\succ} x\, q_f\, y$$

Burada $q_0 w$ başlangıç konfigürasyonu, $q_f$ herhangi bir kabul durumu, $x q_f y$ son konfigürasyondur. Dallardan **yalnız birinin** kabul durumuna ulaşması yeterlidir.

**Teorem:** Deterministik olmayan makineler standart Turing makineleriyle aynı güçtedir.

**1. adım** önemsizdir: deterministik olmayan makine, hiçbir seçenek kullanılmazsa standart makinedir.

### 8.1 Standart makine deterministik olmayan makineyi simüle eder

Deterministik olmayan bir makinenin hesaplamaları bir ağaç oluşturur: başlangıç konfigürasyonundan sonra seçenekler dallanır, her adımda etkin makine sayısı bir ya da daha fazla olabilir. Herhangi bir dal kabul durumuna ulaşırsa makine kabul eder. Kabul etmeyen dallar ya reddederek durur ya da sonsuz döngüye girip hiç bitmez; ikisinde de o dal kabul etmemiş sayılır.

Simülasyon, bu ağaç üzerinde bir aramadır. Ağaçta arama için iki temel yaklaşım vardır:

- **Derinlik öncelikli arama (depth-first search):** bir dalda yaprağa ulaşana kadar inilir, sonra geri dönülüp sıradaki dala geçilir.
- **Genişlik öncelikli arama (breadth-first search):** önce bir düzeydeki bütün düğümlere, sonra bir alt düzeydekilere bakılır.

Hoca hangisinin kullanılması gerektiğini sordu; bir öğrencinin cevabı doğru kabul edildi (ayrıntı Örnek Sorular bölümünde). Kabul eden yoldan önce sonsuz bir yol varsa derinlik öncelikli arama o yolda takılır ve kabul eden yola hiç ulaşamaz. Bu yüzden deterministik makine bütün olası hesaplama yollarını **aynı anda, adım adım ve genişlik öncelikli** olarak simüle eder (ekrandan, 01:40:00).

Deterministik makine iki boyutlu bir şerit kullanır (iki boyutlu şeridin standart makineye denk olduğu az önce gösterildi). Her satıra bir konfigürasyon yazılır. Başlangıç konfigürasyonu için satırda $\#\ a\ b\ c\ \#$ yazılır ve durum ($q_1$) kafanın bulunduğu sütunun altındaki hücreye yazılır; konfigürasyonun sınırları $\#$ ile çizilir, geri kalan her yer boşluktur. Örneğin şerit içeriği $c\,b\,c$ ve durum $q_3$ olan bir konfigürasyon da aynı biçimde gösterilir. Makineler çoğaldıkça yeni satırlar eklenir; bir dal öldüğünde onun satırları $\#$ ile silinir, gerekirse alttaki satırlar yukarı kopyalanır.

Deterministik makinenin uyguladığı algoritma sözde kodla şöyledir:

```text
Giriş kabul edilene ya da bütün konfigürasyonlar reddedilene kadar tekrarla:
    Deterministik olmayan makinenin o anki adımındaki her konfigürasyon için:
        Birden fazla seçenek varsa:
            Konfigürasyonu çoğalt
            Kopyalarda durumu (ve şeridi) seçeneklere göre değiştir
```

Sonuç (ekrandan, 01:45:00):

- Deterministik olmayan makine girişi kabul ederse deterministik makine de kabul eder ve durur. Ancak simülasyon, kabul eden en kısa yolun uzunluğuna göre **en kötü durumda üstel zaman** alır.
- Deterministik olmayan makine girişi kabul etmezse ya bütün yollar bir durma durumuna ulaşır ve simülasyon durarak reddeder, ya da hiç bitmeyen bir yol (sonsuz döngü) varsa simülasyon hiç bitmez. İki durumda da deterministik makine reddetmiş olur (durarak ya da sonsuz döngüyü simüle ederek).

Hoca bölümü şöyle bağladı: deterministik Turing makinesi deterministik olmayan makineyi simüle edebilir, yani aynı işi yapabilir ve aynı güçtedir; ama çok daha yavaş olacaktır, çünkü deterministik olmayan makine bir tür eşzamanlılık (concurrency), paralel çalışma kullanır.

## 9. Evrensel Turing makinesi

Turing makinesi varyasyonları bittikten sonra evrensel Turing makinesine (universal Turing machine) geçildi. Şu ana kadar görülen Turing makinelerinin bir kısıtı vardır: **donanıma gömülüdürler (hardwired)**, yani yalnız tek bir programı çalıştırırlar. Gerçek bilgisayarlar ise yeniden programlanabilir; farklı programlar çalıştırabilirler. Turing makineleri bunu yapabilir mi? Cevap evettir.

Evrensel Turing makinesinin iki özelliği vardır (ekrandan, 02:05:00):

- Yeniden programlanabilir bir makinedir.
- Başka herhangi bir Turing makinesini simüle eder.

Bir Turing makinesi temelde bir algoritma ya da program olduğu için, başka her Turing makinesini simüle edebilen bir makine her programı çalıştırabilir. "Universal" evrensel demektir.

### 9.1 Girdi ve üç şeritli yapı

Evrensel makinenin girdisi, simüle edeceği makinenin **tanımı** ve o makinenin **giriş dizisidir**. Algoritma bir fonksiyon gibi düşünülürse giriş dizisi onun parametresidir; ikisinin de kodlanması gerekir. Bir yaklaşım üç şeritli makine kullanmaktır:

| Şerit | İçerik |
|---|---|
| 1 | Simüle edilen makine $M$'nin tanımı |
| 2 | $M$'nin şeridinin içeriği |
| 3 | $M$'nin o anki durumu |

### 9.2 Turing makinesinin kodlanması

Bir Turing makinesini şeride yazmanın birçok yolu vardır, ama hepsinde makine bir sembol dizisi olarak tanımlanır: **bir Turing makinesi bir dizidir**, bir algoritma bir dizidir. Derste basit bir kodlama kullanıldı (ekrandan, 02:10:00):

| Öğe | Kodlama |
|---|---|
| Semboller $a, b, c, d, \dots$ | $1, 11, 111, 1111, \dots$ |
| Durumlar $q_1, q_2, q_3, q_4, \dots$ | $1, 11, 111, 1111, \dots$ |
| Kafa hareketleri $L, R$ | $1, 11$ |

Yani semboller ve durumlar birli (unary) sayılarla yazılır: $a$ 1, $b$ 2, $c$ 3 ... gibi numaralanır ve numara birli gösterimle yazılır. Bir geçişin alanları $0$ ile ayrılır. Hoca örnek geçişi şöyle okudu: "bu iki, 2. durum; bu iki, $b$; bu bir, sol (L)". Buna göre $\delta(q_1, a) = (q_2, b, L)$ geçişi şöyle kodlanır (ara adım eklendi):

$$\underbrace{1}_{q_1}\,0\,\underbrace{1}_{a}\,0\,\underbrace{11}_{q_2}\,0\,\underbrace{11}_{b}\,0\,\underbrace{1}_{L} = 10101101101$$

<!-- BELİRSİZ: Geçiş kodlaması slaytı karelerde görünmüyor; kodlama hocanın sözlü okumasından ve kodlama tablosundan kurulmuş, birleştirme python ile denetlenmiştir. -->

Bir makinenin birden fazla geçişi olduğu için geçişler yeni bir ayırıcıyla, $00$ ile ayrılır. Böylece bütün geçiş listesi tek bir ikili diziyle gösterilir; evrensel makinenin 1. şeridinin içeriği, simüle edilen makinenin bu ikili kodlamasıdır. (Hoca slaytta şerit numaralarında bir karışıklık olduğunu düşündü, sonra slaytı doğru buldu; önemli olan 1. şeritte makinenin kodunun bulunmasıdır.)

### 9.3 Turing makinelerinin dili

Bir Turing makinesi 0-1 dizisiyle tanımlanabildiğine göre **Turing makineleri kümesi bir dildir** ve bu dilin her dizisi bir Turing makinesidir (ekrandan, 02:15:00). Slayttaki örnek:

$$L = \{\,1010110101,\ 101011101011,\ 11101011110101111,\ \dots\,\}$$

Burada ilk dizi 1. Turing makinesini, ikincisi 2. Turing makinesini gösterir. Turing makineleri kümesi algoritmalar kümesidir: ilki kabarcık sıralaması, ikincisi hızlı sıralama, bir başkası ikili ağaçlarda sezgisel bir arama olabilir. Bütün bu algoritmalar Turing makineleriyle, onlar da ikili dizilerle gösterilebilir.

## 10. Sayılabilir kümeler ve sayıcılar

Sonsuz bir küme ya sayılabilir (countable) ya da sayılamazdır (uncountable). Örneğin tam sayılar ($\dots, -1, 0, 1, 2, 3, \dots$) sonsuzdur ama sayılabilir; reel sayılar sayılamaz.

**Tanım:** Bir küme, elemanlarıyla pozitif tam sayılar arasında birebir eşleme (one-to-one correspondence) varsa sayılabilirdir. Her eleman bir pozitif tam sayıya eşlenir ve iki eleman aynı sayıya eşlenmez.

### 10.1 Çift sayılar

Çift sayılar kümesi $\{0, 2, 4, 6, 8, \dots\}$ sayılabilir. Eşleme: $n = 0, 1, 2, \dots$ için çift sayı $2n$, pozitif tam sayı $n+1$ ile eşlenir.

| $n$ | Pozitif tam sayı $n+1$ | Çift sayı $2n$ |
|---|---|---|
| 0 | 1 | 0 |
| 1 | 2 | 2 |
| 2 | 3 | 4 |
| 3 | 4 | 6 |

### 10.2 Rasyonel sayılar

Hoca bunun kendisi için de şaşırtıcı olduğunu söyledi: rasyonel sayılar da sayılabilir (ekrandan, 02:20:00). Rasyonel sayıda pay (numerator) ve payda (denominator) tam sayıdır: $\frac12, \frac34, \frac78, \dots$

Saf bir yaklaşım payı 1'e sabitleyip paydayı 1'den sonsuza artırmaktır: $\frac11, \frac12, \frac13, \dots$ Bu işe yaramaz, çünkü paydası artan sonsuz sayıda sayı olduğu için payı 2 olan sayılara hiç gelinmez.

Daha akıllıca bir sıra gerekir. Rasyonel sayılar bir tabloya yazılır: satırlarda pay (1, 2, 3, ...), sütunlarda payda (1, 2, 3, ...) sabittir. Sonra tablo köşegenler boyunca gezilir: $\frac11$, sonra $\frac12$, sonra $\frac21$, sonra $\frac13$, $\frac22$, ... (ekrandan, 02:25:00):

| Rasyonel sayı | $\frac11$ | $\frac12$ | $\frac21$ | $\frac13$ | $\frac22$ | $\dots$ |
|---|---|---|---|---|---|---|
| Pozitif tam sayı | 1 | 2 | 3 | 4 | 5 | $\dots$ |

Bu sırayla bütün rasyonel sayılara ulaşılır ve her birine bir pozitif tam sayı karşılık gelir; öyleyse rasyonel sayılar sayılabilir. Hoca bunun yapıyla ispata benzediğini, ama daha çok bir sayma yolunun tarif edilmesi olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu sırada $\frac22$ gibi $\frac11$'e eşit olan kesirler de yer alır. Birebir eşleme için büyük olasılıkla sadeleşebilen kesirler atlanır ya da her rasyonel sayının ilk görüldüğü yer alınır; bu, sayılabilirlik sonucunu değiştirmez.

### 10.3 Sayma yordamı ve sayıcı

Bir kümenin nasıl sayılacağını tarif etmek bir **sayma yordamı (enumeration procedure)**, yani bir **sayıcı (enumerator)** tarif etmektir. Bir küme için sayma yordamı tarif edilebiliyorsa o küme sayılabilirdir.

**Tanım:** $S$ bir dil ya da diziler kümesi olsun. $S$ için bir sayıcı, $S$'nin bütün dizilerini bir şeride tek tek üreten (yazdıran) bir Turing makinesidir. Sayma yordamı bir algoritma olduğu için bir Turing makinesiyle yapılabilir.

Her dizi sonludur ve sonlu zamanda üretilir. Diziler $s_1, s_2, s_3, \dots$ ise sayıcı bunları $t_1, t_2, t_3, \dots$ anlarında çıktı şeridine yazar. Hoca slaytı yorumlarken çıktıda her dizinin yanında ona karşılık gelen tam sayının ($x_i$) da yer alması gerektiğini, makinenin özel bir $q_s$ durumuna geldiğinde yazılı dizinin kümenin bir elemanı olduğu anlamına geldiğini açıkladı.

<!-- BELİRSİZ: Sayıcı tanımı slaytı karelerde görünmüyor; $x_i$ ve $q_s$ ayrıntıları hocanın slaytı sesli yorumlamasından alınmıştır. -->

Buradan şu gözlem çıkar: bir $S$ kümesi için bir sayıcı varsa küme sayılabilirdir; sayıcı, kümenin doğal sayılarla (pozitif tam sayılarla) eşlemesini tarif eder.

### 10.4 Örnek: $\{a,b,c\}^+$ sayılabilir

Amaç $S = \{a,b,c\}^+$ kümesinin sayılabilir olduğunu göstermektir; yaklaşım $S$ için bir sayıcı tarif etmektir (ekrandan, 02:30:00). Diziler $a, aa, aaa, \dots$ diye sıralanırsa işe yaramaz, çünkü içinde $b$ ya da $c$ olan bir diziye hiç gelinmez. Sayıcı uygun bir sıra vermelidir; buna bazen **kanonik sıra (canonical order)** denir. Bir yolu dizilerin uzunluğuna bakmaktır: önce uzunluğu 1 olan bütün diziler ($a, b, c$), sonra uzunluğu 2 olanlar, sonra 3, 4 ... Bu sırayla her dizi yeterli zamanda üretilir.

## 11. Turing makineleri sayılabilir, diller sayılamaz

**Teorem:** Bütün Turing makineleri kümesi sayılabilir. Bir Turing makinesi bir algoritma olduğuna göre bütün algoritmalar kümesi sayılabilir: sonsuz sayıda algoritma vardır ama sayılabilirler (1. algoritma kabarcık sıralaması, 2. hızlı sıralama, 3. derinlik öncelikli arama, 4. genişlik öncelikli arama ...).

**İspat:** Her Turing makinesi 0-1'lerden oluşan bir ikili diziyle kodlanabilir. Sayıcı bütün ikili dizileri sırayla üretir (0, 1, sonra uzunluğu 2 olanlar ...). Her dizi için bunun bir Turing makinesi tanımlayıp tanımlamadığına (geçerli bir kodlama olup olmadığına) bakılır. Tanımlıyorsa dizi çıktı şeridine yazılır, tanımlamıyorsa atlanır. Böylece sayıcı bütün Turing makinelerini yazdırır; Turing makineleri için bir sayma yordamı tarif edilmiş olur, öyleyse Turing makineleri sayılabilir.

**Daha basit ispat** (ekrandan, 02:35:00): her Turing makinesinin ikili dizisi, temsil ettiği sayıya eşlenir. Sonuç yine aynıdır: sayılabilir.

**Sayılamayan kümeler ve sonuç.** Bazı kümeler sayılamaz. Derste amaç, hiçbir Turing makinesinin kabul etmediği bir $L$ dili olduğunu göstermekti (ekrandan, 02:40:00). Bunun için Turing makinelerinin sayılabildiği bilindiğine göre bütün diller kümesinin sayılamadığını göstermek yeter. Hoca bu ispatı zaman yetmediği için atladı ve öğrencilerin evde okumasını istedi.

> **Ek bilgi (derste anlatılmadı):** Bu ispat büyük olasılıkla bir alfabe üzerindeki dillerin, bütün diziler kümesinin kuvvet kümesi olmasına ve Cantor'un köşegen yöntemine dayanır: sayılabilir sonsuz bir kümenin kuvvet kümesi sayılamaz.

Hoca sonucu hem İngilizce hem Türkçe şöyle bağladı:

- Bir Turing makinesi bir algoritmayı tarif eder. Sonsuz sayıda Turing makinesi, dolayısıyla sonsuz sayıda algoritma vardır; ama Turing makineleri sayılabilir bir kümedir.
- Bir dil bir problemi temsil eder. Bir Turing makinesi bir dili kabul ediyorsa o problemi çözüyor demektir. Problemler de sonsuzdur, ama sayılamaz.
- Algoritmalar 1, 2, 3 gibi sayılabilir; problemler ise reel sayılar gibi sayılamaz. İkisi de sonsuzdur ama problemlerin sayısı daha fazladır.

Öyleyse **çözülemeyen problemler vardır**: bilgisayarlarımızla çözemeyeceğimiz problemler olduğu teorik olarak gösterilmiştir. Turing-kabul edilebilir diller kümesinin dışında kalan diller vardır.

> **Hocanın vurgusu:** Bu dersin "üzücü sonucu" budur: algoritmaları sayabiliyoruz, problemleri sayamıyoruz; problem kümesi algoritma kümesinden çok daha büyüktür, yani bilgisayarla çözülemeyen problemler vardır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:05 ve ekrandan, 00:25:00): Standart bir Turing makinesi, stay-option makinedeki $q_1 \xrightarrow{a \to b,\, S} q_2$ geçişini nasıl simüle eder?

> **Çözüm (derste verildi):** Yeni bir ara durum eklenir. $q_1 \xrightarrow{a \to b,\, L} q_{ara}$ geçişiyle $b$ yazılıp sola gidilir; sonra her şerit sembolü $x$ için $q_{ara} \xrightarrow{x \to x,\, R} q_2$ geçişiyle sembol değiştirilmeden sağa dönülür. Kafa aynı hücreye gelmiş, yani yerinde kalmış olur.

**Soru 2** (derste sözlü, 01:37:21): Deterministik olmayan bir Turing makinesinin hesaplama ağacını simüle ederken derinlik öncelikli arama mı, genişlik öncelikli arama mı yapılmalıdır? Neden?

> **Çözüm (derste verildi):** Genişlik öncelikli arama. Bir öğrencinin cevabı ve hocanın onayı şöyleydi: kabul eden yoldan önce (ağacın solunda) sonsuz bir yol varsa derinlik öncelikli arama o yolda takılır ve kabul eden yola hiç ulaşamaz. Genişlik öncelikli aramada bütün dallar düzey düzey kontrol edildiği için sonsuz bir yola takılmadan kabul eden yola ulaşılır.

**Soru 3** (derste sözlü, 02:41:45): Turing makineleri (algoritmalar) sayılabilir, diller (problemler) sayılamaz. Bundan nasıl bir sonuç çıkar?

> **Çözüm (derste verildi):** Problem kümesi algoritma kümesinden daha büyük olduğu için bazı problemlere karşılık gelen bir algoritma (Turing makinesi) yoktur. Yani çözülemeyen problemler vardır; cevap derste bir öğrenciden geldi.

**Soru 4** (ekrandan, 02:30:00): $S = \{a,b,c\}^+$ kümesinin sayılabilir olduğunu gösteriniz.

> **Çözüm (derste verildi):** $S$ için bir sayıcı tarif edilir. Diziler uzunluk sırasıyla (kanonik sıra) üretilir: önce uzunluğu 1 olanlar ($a, b, c$), sonra uzunluğu 2 olanlar, sonra 3 ... Her dizi sonlu zamanda üretildiği ve bir pozitif tam sayıyla eşlendiği için $S$ sayılabilirdir. Yalnız $a, aa, aaa, \dots$ diye saymak işe yaramaz, çünkü $b$ ya da $c$ içeren dizilere hiç gelinmez.

## Dersin Toparlaması

Bu derste önce standart Turing makinesinin varyasyonları görüldü: stay-option, çok izli şerit (bir hile olarak), yarı sonsuz şerit, çok şeritli, çok boyutlu ve deterministik olmayan makineler. Her biri için iki yönlü simülasyonla standart makineyle aynı güçte olduğu, yani aynı dilleri kabul ettiği gösterildi. Ortak hileler; çok izli şerit, referans noktası ve sınır işareti olarak $\#$, her olası sembol $x$ için geçiş eklemek ve deterministik olmayan makine için genişlik öncelikli aramaydı. Güç ile hızın farklı olduğu da $a^n b^n$ örneği ve deterministik olmayan makinenin üstel zamanlı simülasyonuyla vurgulandı.

Dersin ikinci yarısında evrensel Turing makinesiyle bir Turing makinesinin 0-1 dizisi olarak kodlanabileceği, dolayısıyla Turing makinelerinin bir dil oluşturduğu görüldü. Sayılabilirlik kavramı çift sayılar, rasyonel sayılar ve $\{a,b,c\}^+$ örnekleriyle işlendi; sayıcı yardımıyla Turing makinelerinin sayılabilir olduğu ispatlandı. Bütün dillerin sayılamaz olduğu (ispatı okumaya bırakılarak) kabul edilince, hiçbir Turing makinesinin kabul etmediği diller, yani bilgisayarla çözülemeyen problemler olduğu sonucuna ulaşıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
