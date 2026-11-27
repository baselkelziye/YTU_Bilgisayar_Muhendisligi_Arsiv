# Ders 12 Genişletilmiş Notu: Turing Makinesi Tasarım Örnekleri, Turing Tezi ve Turing Makinesi Çeşitleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Düzenli İfadeden Turing Makinesi: $0^*10(0+1)^*$
- 2. Deterministiklik Sorunu: $(a+b)^*aa(a+b)^*$
- 3. Düzenli ve Bağlamdan Bağımsız Olmayan Bir Dil: $0^{2^n}$
- 4. $0^{2^n}$ Makinesinde Hesaplama İzleri
- 5. Sıralama Yapan Turing Makinesi
- 6. $0^n1^n2^n$ İçin Sözde Kod
- 7. Turing Tezi, Algoritma ve Dil Hiyerarşisi
- 8. Turing Makinesi Çeşitleri ve Benzetim
- Örnek Sorular

## 1. Düzenli İfadeden Turing Makinesi: $0^*10(0+1)^*$

Ders, Turing makinesi tasarım örnekleriyle başlar. Önceki derste Turing makinelerinin blok diyagramları anlatılmıştı. Hoca tablete şu soruyu yazar (ekrandan, 00:05:00):

> $\Sigma=\{0,1\}$ alfabesi üzerinde $r = 0^*10(0+1)^*$ düzenli ifadesi verilsin. $r$'nin dilini kabul eden bir Turing makinesi tasarlayın. Şerit alfabesi $\Gamma=\{0,1,\$\}$'dır; $\$$ boşluğu (blank) gösterir.

### 1.1 Dilin elemanları

Önce dilin hangi dizgileri içerdiğine bakılır. Boş dizgi $\varepsilon$ dilde değildir. Tek başına $0$ da dilde değildir. $10$ dildedir; $010$, $0010$ ve "birçok $0$, sonra $10$" biçimindeki dizgiler de dildedir. $10$'dan sonra $(0+1)^*$ geldiği için $0\cdots0101$ gibi, $10$'dan sonra herhangi bir $0$-$1$ dizisi gelen uzun dizgiler de dilin elemanıdır.

### 1.2 Makine

Tasarım NFA ve DFA tasarımına benzer, ama her geçişte üç bilgi yazılır: okunan sembol, yazılan sembol ve kafanın hareketi. $a\to b,R$ etiketi "$a$ oku, $b$ yaz, sağa git" demektir. Makine şöyledir (ekrandan, 00:10:00 ve 00:15:00):

```text
-> q0 --($ -> $,R)--> q1 --(1 -> 1,R)--> q2 --(0 -> 0,R)--> ((q3))
                      q1 üzerinde döngü: 0 -> 0,R
```

Başlangıç durumu $q_0$'da boşluk okunur, yazılır ve sağa geçilir; artık dizginin içindeyiz. $q_1$'deki $0\to0,R$ döngüsü $0^*$ kısmıdır. Sonra $1$ okunup $q_2$'ye, ardından $0$ okunup $q_3$'e gidilir. $q_3$ kabul durumudur.

Peki $(0+1)^*$ kısmı nerede? Hoca burada Turing makinesinin önemli bir özelliğini vurgular: Turing makinesi kabul durumuna ulaştığında girdi doğrudan kabul edilir ve makine durur. $10$ okunduğunda dizginin geri kalanı ne olursa olsun $(0+1)^*$ ile eşleşir, yani dizgi dile girmiştir. Bu yüzden geri kalan için ayrıca durum çizilmez. Turing makinesinde kabul durumundan çıkan bir geçiş de yoktur.

### 1.3 Değişiklik: $0^*10$

Hoca ifadeyi değiştirip sorar: $r = 0^*10$ olsaydı makine nasıl olurdu? Bu durumda $10$ okunduktan sonra dizginin bitmesi gerekir. $q_3$ artık kabul durumu olmaz; ondan boşluk okunarak yeni bir kabul durumuna geçilir (ekrandan, 00:15:00):

```text
-> q0 --($ -> $,R)--> q1 --(1 -> 1,R)--> q2 --(0 -> 0,R)--> q3 --($ -> $,L)--> ((q4))
                      q1 üzerinde döngü: 0 -> 0,R
```

Hoca, $q_3$'ten sonra kalan $0$ ve $1$'ler için ayrı bir "çıkmaz durum" çizmeye gerek olmadığını da söyler: $q_3$'te boşluktan başka bir sembol okunursa tanımlı geçiş yoktur, makine durur ve dizgi kabul edilmez. Her iki makine de python ile 9 uzunluğa kadar bütün ikili dizgilerde düzenli ifadeyle karşılaştırılmış ve aynı sonucu vermiştir.

> **Ders sonrası not:** Hoca iki tasarımı karşılaştırırken döngüsüz makine için "decidable", döngülü makine için "undecidable" dedi (00:16:25). Bir durumun kendine dönen bir geçişi olması makineyi karar verilemez yapmaz. Bu makinelerde her adım kafayı sağa götürür; sonlu girdi bitince makine ya kabul eder ya da tanımlı geçiş bulamayıp durur. Yani iki makine de her girdide durur ve dillerini karar verir (decide). Her düzenli dil karar verilebilirdir.

### 1.4 Boşluk sembolü

**Soru:** Buradaki dolar işaretini boşluk olarak mı düşündük? **Cevap:** Evet. Önceki slaytlarda boşluk için baklava (elmas, $\diamond$) sembolü kullanılmıştı; burada $\$$ seçildi. Boşluk sembolü bir tanımdır: aksi söylenmedikçe dolar, baklava, $\#$ gibi istenen herhangi bir sembol seçilebilir. Hoca bir sonraki örnekte baklavayı kullanır.

## 2. Deterministiklik Sorunu: $(a+b)^*aa(a+b)^*$

İkinci örnek $r=(a+b)^*aa(a+b)^*$, yani içinde $aa$ geçen bütün $\{a,b\}$ dizgileridir (ekrandan, 00:20:00). Başlangıç yine aynıdır: $q_0 \xrightarrow{\diamond\to\diamond,R} q_1$.

Hoca önce NFA'daki gibi düşünmeyi dener: $q_1$'e $a\to a,R$ ve $b\to b,R$ döngüleri koyup ardından $aa$ için iki geçiş çizmek. Ama Turing makinesi deterministiktir. $q_1$'de $a$ okununca hem döngüde kalmak hem de $aa$'nın ilk harfi için başka bir duruma gitmek aynı anda yazılamaz. PDA ya da NFA olsaydı bu olurdu; Turing makinesinde $(a+b)^*$'ı başka bir yolla ifade etmek gerekir.

Hocanın kurduğu fikir şudur: $b$ okundukça $q_1$'de kalınır; $a$ okununca $q_2$'ye geçilir. $q_2$'de $b$ gelirse $aa$ bozulmuştur ve $q_1$'e dönülür. $q_2$'de ikinci bir $a$ gelirse $aa$ bulunmuştur ve kabul durumu $q_3$'e gidilir. Dizginin geri kalanı yine $(a+b)^*$ olduğundan kabul durumundan sonra bir şey çizilmez.

```text
-> q0 --(◇ -> ◇,R)--> q1
q1 : b -> b,R (döngü)     a -> a,R => q2
q2 : b -> b,R => q1       a -> a,R => ((q3))
```

<!-- BELİRSİZ: Son diyagram karede görünmüyor (karede yalnız ilk denemenin q1 üzerindeki a -> a,R döngüsü var); geçişler altyazıdaki anlatımdan kuruldu. -->

Bu makine python ile 9 uzunluğa kadar bütün $\{a,b\}$ dizgilerinde denenmiş, $aa$ içerenleri kabul edip diğerlerini reddettiği görülmüştür.

## 3. Düzenli ve Bağlamdan Bağımsız Olmayan Bir Dil: $0^{2^n}$

### 3.1 Dil

Üçüncü örneğin dili şudur (ekrandan, 00:25:00):

$$L = \{0^{2^n} \mid n \ge 0\}$$

Sıfırların sayısı $2^0=1$, $2^1=2$, $2^2=4$, $2^3=8$, ... olabilir. Ekrandaki örnekler:

| Dizgi | Uzunluk | $L$'de mi? |
|---|---|---|
| $\varepsilon$ | 0 | hayır |
| $0$ | 1 | evet |
| $00$ | 2 | evet |
| $000$ | 3 | hayır |
| $0000$ | 4 | evet |
| $00000$ | 5 | hayır |
| $000000$ | 6 | hayır |
| $0000000$ | 7 | hayır |
| $00000000$ | 8 | evet |

Hoca bu dilin düzenli olmadığını, bağlamdan bağımsız da olmadığını, onu ancak bir Turing makinesinin tanıyabileceğini söyler.

### 3.2 Fikir

İkinin kuvveti döngüyle elde edilir: her turda sıfır sayısı ikiye bölünür. Her turda sıfırlar teker teker taranır; biri bırakılır, biri $x$ ile işaretlenir. Böylece her turda sıfırların yarısı silinir. Bir turda sıfır sayısı tek çıkarsa (ve birden büyükse) dizgi reddedilir. Sonunda tek bir sıfır kalırsa sayı ikinin kuvvetidir ve dizgi kabul edilir. Şerit alfabesi $\Gamma=\{x,0,\diamond\}$'dir; $x$ yardımcı (auxiliary) semboldür.

### 3.3 Makinenin kuruluşu

Hoca makineyi adım adım kurar (ekrandan, 00:30:00-00:40:00):

- $q_1$ başlangıç durumudur. Şeritte hiçbir şey yoksa ($\diamond$ okunursa) boş dizgi dilde olmadığı için $q_{reject}$'e gidilir.
- İlk $0$ okununca yerine $\diamond$ yazılır ve $q_2$'ye geçilir. İlk sıfırın boşlukla değiştirilmesi, kafa geri dönerken dizginin başını tanımasını sağlar.
- $q_2$'de hemen $\diamond$ gelirse yalnız bir sıfır vardı; $0\in L$ olduğu için $q_{accept}$'e gidilir.
- $q_2$'de $0$ okunursa (ikinci sıfır) $x$ yapılır ve $q_3$'e geçilir.
- $q_3$'te bir sonraki $0$ olduğu gibi bırakılır ($0\to0,R$) ve $q_4$'e geçilir; $q_4$'te bir sonraki $0$ yine $x$ yapılır ve $q_3$'e dönülür. Böylece sıfırlar sırayla "bırak, işaretle" diye ilerler.
- Kafa sağa giderken önceki turlardan kalan $x$'ler atlanır: $q_2$, $q_3$ ve $q_4$'te $x\to x,R$ döngüleri vardır.
- $q_3$'te boşluğa ulaşılırsa bu turdaki sıfır sayısı çifttir. $\diamond\to\diamond,L$ ile $q_5$'e geçilir. $q_5$'te $0\to0,L$ ve $x\to x,L$ ile başa dönülür; başta boşluk görülünce $\diamond\to\diamond,R$ ile $q_2$'ye geçilip yeni tura başlanır.
- $q_4$'te boşluğa ulaşılırsa bir sıfır eşsiz kalmıştır, sayı tektir. $\diamond\to\diamond,R$ ile $q_{reject}$'e gidilir.
- $q_2$'de yalnız $x$'ler geçilip boşluğa varılırsa geriye tek sıfır (silinen ilk sıfır) kalmıştır; dizgi kabul edilir.

Hoca kurarken bir an "hepsi $x$ ise kabul" deyip hemen düzeltir: $q_4$'te boşluğa varıldığında bir sıfır eşlenmeden kalmıştır, bu durum kabul değil red durumudur.

Tam geçiş tablosu (ekrandan, 00:40:00 ve 00:45:00):

| Durum | $0$ | $x$ | $\diamond$ |
|---|---|---|---|
| $q_1$ | $\diamond, R, q_2$ | — | $\diamond, R, q_{reject}$ |
| $q_2$ | $x, R, q_3$ | $x, R, q_2$ | $\diamond, R, q_{accept}$ |
| $q_3$ | $0, R, q_4$ | $x, R, q_3$ | $\diamond, L, q_5$ |
| $q_4$ | $x, R, q_3$ | $x, R, q_4$ | $\diamond, R, q_{reject}$ |
| $q_5$ | $0, L, q_5$ | $x, L, q_5$ | $\diamond, R, q_2$ |

Bu tablo python ile 17 uzunluğa kadar bütün $0^k$ dizgilerinde denendi: yalnız $k=1,2,4,8,16$ için kabul ediyor.

## 4. $0^{2^n}$ Makinesinde Hesaplama İzleri

Hoca makineyi iki girdide çalıştırır. Yapılandırma (configuration) yazımında durum adı, kafanın üzerinde durduğu sembolün hemen soluna yazılır. Dizginin iki yanında sonsuz sayıda boşluk vardır; $\diamond\diamond\diamond q_1 000 \diamond\diamond\cdots$ yerine kısaca $q_1 000$ yazılır.

### 4.1 $00$ (ekrandan, 00:40:00)

$$q_1 00 \succ \diamond q_2 0 \succ \diamond x q_3 \diamond \succ \diamond q_5 x \succ q_5 \diamond x \succ \diamond q_2 x \succ \diamond x q_2 \diamond \succ \diamond x \diamond q_{accept}$$

Adım adım: ilk sıfır $\diamond$ olur ($q_2$). İkinci sıfır $x$ olur ($q_3$). $q_3$ boşluk okur ve sola gider ($q_5$). Hoca burada önce kafayı yanlış yere yazar, sonra "dikkat, sola gidiyorsun" diyerek düzeltir: sola gidildiği için $x$ kafanın sağında kalır. $q_5$, $x$'i geçip baştaki boşluğa varır ve sağa dönerek $q_2$'ye geçer. $q_2$, $x$'i atlar, boşluğa varır ve kabul durumuna gider. $00$ kabul edilir.

### 4.2 $000$ (ekrandan, 00:45:00)

$$q_1 000 \succ \diamond q_2 00 \succ \diamond x q_3 0 \succ \diamond x 0 q_4 \diamond \succ q_{reject}$$

İlk sıfır $\diamond$, ikincisi $x$ olur. Üçüncü sıfır $q_3$'te olduğu gibi bırakılır ve $q_4$'e geçilir. $q_4$ boşluk okur, yani bu sıfırın eşi yoktur; $q_{reject}$'e gidilir. Red durumu bir kabul durumu olmadığından $000$ reddedilir. Her iki iz de python simülasyonuyla birebir aynı çıkmıştır.

## 5. Sıralama Yapan Turing Makinesi

### 5.1 Problem

Hoca tablete şu soruyu yazar (ekrandan, 00:50:00 ve 00:55:00):

> $\Sigma=\{a,b\}$ üzerindeki bir dizgideki sembolleri sıralayan bir Turing makinesi tasarlayın. Size $a$ ve $b$'lerden oluşan bir dizi verilecek. Tasarladığınız makine diziyi, bütün $a$'lar bütün $b$'lerden önce gelecek şekilde yeniden düzenleyecek.

Örnekler: $w=abaabbbbabb$ için sonuç $aaaabbbbbbb$ (4 $a$, 7 $b$); $w=bbba$ için sonuç $abbb$. Hoca bu işin bir NFA, DFA ya da PDA ile yapılamayacağını, ama bir Turing makinesiyle yapılabileceğini söyler ve sınıfa düşünmeleri için ara verir.

> **Hocanın vurgusu:** Bu, güzel bir final sınavı sorusudur. Bu tür soruları çok iyi öğrenmek gerekir.

### 5.2 Kütüphane ve algoritma üzerine

Aradan sonra hoca, bir programlama dilinde bu işi nasıl yapacaklarını sorar. **Soru (hocadan):** Bunu bir programda nasıl yapardınız? **Bir öğrenci:** Selection sort kullanırdım. Hoca, sıralamayı hazır kütüphaneyle yapmanın anlaşılır olduğunu, ama kütüphane olmadan nasıl sıralanacağını soran birine cevap verilemezse algoritma geliştirme becerisinin eksik görüneceğini söyler. Yazılım geliştirmek algoritma geliştirmektir, algoritma geliştirmek için de hesaplama kuramını bilmek gerekir. Kendi yöntemini geliştiren biri daha hızlı bir sıralama bulup literatüre katkı yapabilir. İş hayatında bir projeyi çabuk bitirmek gerektiğinde kütüphane kullanılabilir; ama burada istenen mantığın kendisidir.

### 5.3 Yer değiştirme fikri

Hoca ipucunu bir örnekle verir (ekrandan, 01:10:00):

$$aababa \to aaabba \to aaabab \to aaaabb$$

Her adımda bir "$ba$" bloğu "$ab$" yapılır: bir $a$ bir adım sola, bir $b$ bir adım sağa kayar. İkinci örnek (ekrandan, 01:15:00):

$$bbba \to bbab \to babb \to abbb$$

Dizgi yalnız iki sembolden oluştuğu için bu yer değiştirme bir Turing makinesiyle kolayca yapılabilir.

### 5.4 Hangi $a$?

Hoca önce kafanın bir başa bir sona gitmesini öğütler: Turing makinesinde algoritma kurarken kafa hep dizginin başına ve sonuna götürülmelidir. Ortadan bir yerden başlanırsa konum kaybedilir; baş-son taraması daha hatasız algoritmalar verir. Bu düşünceyle önce **en sondaki** $a$'yı önceki $b$ ile değiştirmeyi dener ($aababa \to aabaab$). Sonra sınıfa "sondan mı gitmek mantıklı, baştan mı?" diye sorar ve şu sonuca varır: sondaki $a$ seçilince sorun çıkar, iki $a$ yan yana gelir ve yöntem tıkanır. Her zaman $b$'lerden sonra gelen **ilk** $a$ seçilmelidir.

Kesin algoritma şudur: $b$'lerden sonraki ilk $a$, kendisinden önceki $b$ ile yer değiştirir (bir kaydırma, shift), sonra dizginin başına dönülür. Bu tekrarlanır. $b$'lerden sonra hiç $a$ kalmadığında bütün $a$'lar baştadır ve kabul durumuna geçilir. Hoca, makineyi gerçeklemeden önce algoritmanın iyice anlaşılması gerektiğini söyler.

### 5.5 Makine

Boşluk sembolü olarak bu kez $\#$ seçilir; $\Gamma=\{a,b,\#\}$ (ekrandan, 01:20:00):

| Durum | $a$ | $b$ | $\#$ |
|---|---|---|---|
| $q_0$ | $a, L, q_0$ | $b, L, q_0$ | $\#, R, q_1$ |
| $q_1$ | $a, R, q_1$ | $b, R, q_2$ | $\#, L, q_{accept}$ |
| $q_2$ | $b, L, q_3$ | $b, R, q_2$ | $\#, L, q_{accept}$ (sözlü) |
| $q_3$ | — | $a, L, q_0$ | — |

Açıklama:

- $q_0$: sola giderek dizginin başına döner; başta boşluk görünce sağa geçip $q_1$'e girer.
- $q_1$: baştaki $a$'ları geçer. İlk $b$'de $q_2$'ye girer. Boşluk görürse dizgi boştur ya da yalnız $a$'lardan oluşur; kabul edilir.
- $q_2$: $b$'leri geçer. $b$'lerden sonraki ilk $a$ bulununca yerine $b$ yazar ve bir sola gider ($q_3$).
- $q_3$: o konumdaki $b$'yi (son $a$'dan önceki $b$) $a$ yapar, sola gider ve $q_0$ ile başa dönülür.

> **Ders sonrası not:** Hoca, $b$'lerin ardından hiç $a$ kalmamışsa da boşluk okunacağını ve kabul edilmesi gerektiğini söyledi (01:20:01), ancak $q_2$'den kabul durumuna giden bu geçiş karede görünmüyor. Tabloda "(sözlü)" diye eklendi. Bu geçiş olmazsa $ab$ ya da $bbb$ gibi zaten sıralı dizgiler kabul edilmez. Makine bu geçişle birlikte python'da 9 uzunluğa kadar bütün $\{a,b\}$ dizgilerinde denendi; hepsinde doğru sıralanmış çıktı üretip kabul ediyor. $abaabbbbabb$ girdisi için şeritte $aaaabbbbbbb$ kalıyor.

## 6. $0^n1^n2^n$ İçin Sözde Kod

### 6.1 Soru ve dilin sınıfı

Son örnek bir sözde kod (implementation-level description) sorusudur (ekrandan, 01:25:00):

> $\Sigma=\{0,1,2\}$ alfabesi üzerinde $L=\{0^n1^n2^n \mid n\ge 0\}$ dilini karar veren (decide) bir Turing makinesinin sözde kodunu (implementation-level description) verin.

Hoca önce dilin bağlamdan bağımsız olup olmadığını sorar. **Soru (hocadan):** Bu dil bağlamdan bağımsız mı? **Bir öğrenci:** Değil, çünkü birden fazla bağıntı var. Hoca açıklar: desende üç örüntü (sıfırlar, birler, ikiler) vardır ve uzunlukları eşit olmalıdır. Sıfırların sayısı birlerin sayısına, sıfırların sayısı ikilerin sayısına, birlerin sayısı ikilerin sayısına eşittir; üç bağıntı vardır, dolayısıyla dil bağlamdan bağımsız değildir. İkiler olmasaydı ($0^n1^n$) tek bağıntı kalırdı ve dil bağlamdan bağımsız olurdu. **Soru (hocadan):** Birlerin sayısı sıfırların sayısının iki katı olsaydı? **Bir öğrenci:** Yine tek bağıntı var. Hoca onaylar: bu da bağlamdan bağımsızdır. Bağıntı sayısına bakarak bazı problemler hızlıca çözülebilir.

> **Ek bilgi (derste anlatılmadı):** "Bağıntı sayısı" kısa yoldan sezgi verir ama kesin bir ölçüt değildir; bir dilin bağlamdan bağımsız olmadığının kesin ispatı bağlamdan bağımsız diller için pompalama önsavıyla yapılır.

### 6.2 İlk gözlem

Dil, $0^*1^*2^*$ düzenli ifadesinin dilinin alt kümesidir (ekrandan, 01:30:00):

$$L_1 \subset L(0^*1^*2^*)$$

$L(0^*1^*2^*)$'da sıfırlar, birler ve ikiler bu sırayla gelir ama sayıları arasında bağıntı yoktur. Bu yüzden ilk iş, girdinin bu desende olup olmadığını denetlemektir; sıfırlardan, birlerden ve ikilerden sonra yeniden sıfır gelmesi gibi bir bozukluk varsa dizgi doğrudan reddedilir.

### 6.3 Sözlü algoritma

Hoca önce algoritmayı sözlü anlatır: en soldaki sıfır $x$ yapılır; sıfırlar geçilir; ilk görülen bir $x$ yapılır; birler geçilir; ilk görülen iki $x$ yapılır; ikiler geçilip dizginin sonuna varılır. Sonra ikiler, $x$'ler, birler, $x$'ler ve sıfırlar geçilerek başa dönülür. Bu tekrarlanır. Sonunda dizgide yalnız $x$'ler kalmışsa, yani sondan başa dönerken boşluğa kadar yalnız $x$ görülüyorsa, dizgi kabul edilir.

### 6.4 Yazılı sözde kod

Hoca sözde kodu tablete yazar. Önce adımları 1-9 diye numaralandırır, sonra "tekrarla" adımını 2.5 olarak araya ekler ve numaraları bir kaydırır (ekrandan, 01:35:00 ve 01:40:00). Yeniden numaralanmış hâli:

$M$ = "$w$ girdisi üzerinde:

1. Girdiyi soldan sağa tara ve $w \in L(0^*1^*2^*)$ olduğundan emin ol; değilse reddet.
2. Şerit kafasını şeridin sol ucuna ($w$'nin soluna) geri getir.
3. Şeritte hiç $0$ kalmayana kadar aşağıdakileri tekrarla:
4. En soldaki $0$'ı $x$ ile değiştir.
5. Bir $1$ görene kadar sağa tara. Hiç $1$ yoksa $w$'yi reddet.
6. En soldaki $1$'i $x$ ile değiştir.
7. Bir $2$ görene kadar sağa tara. Hiç $2$ yoksa $w$'yi reddet.
8. En soldaki $2$'yi $x$ ile değiştir.
9. Şerit kafasını sol uca geri getir ve 3. adıma git.
10. Şeritte hâlâ $1$ ya da $2$ varsa reddet; yoksa kabul et."

<!-- BELİRSİZ: 7-10. adımların karesi yok; bu adımların metni altyazıdaki anlatımdan kuruldu. -->

Her turda bir sıfır, bir bir ve bir iki $x$ yapılır; böylece üç sayı aynı anda karşılaştırılır. Sıfırlar bittiğinde hâlâ bir ya da iki kalmışsa sayılar eşit değildir. Bir tur ortasında bir ya da iki bulunamazsa da sayılar eşit değildir. Sözde kod python ile 8 uzunluğa kadar bütün $\{0,1,2\}$ dizgilerinde denendi; yalnız $0^n1^n2^n$ biçimindekileri (boş dizgi dahil) kabul ediyor.

Hoca bu sözde kodun Turing makinesi diyagramına çevrilmesini öğrencilere bırakır: bunu kendileri yapmazlarsa Turing makinesini öğrenemeyeceklerini söyler. Bir çözüm "Örnek Sorular" bölümündedir.

## 7. Turing Tezi, Algoritma ve Dil Hiyerarşisi

### 7.1 Turing tezi

Hoca slaytlara geçer (ekrandan, 01:45:00):

> **Turing tezi (1930):** Mekanik yollarla gerçekleştirilen her hesaplama bir Turing makinesiyle yapılabilir.

Hoca "bilgisayar" kelimesinin asıl karşılığının "hesaplayıcı" olduğunu söyler; İngilizcedeki "computer" kelimesi doğrudan hesaplama yapan makineyi anlatır.

### 7.2 Algoritma

Slayttaki tanım (ekrandan, 01:50:00):

> **Algoritma:** Bir problem için algoritma, o problemi çözen bir Turing makinesidir.

Bir problem için algoritma geliştirmek, o problemi çözen Turing makinesini yapmak demektir. Mekanik yapılarla bir problemi çözme yöntemleri birer algoritma sayılır ve bunlar bir Turing makinesinin hesaplama adımlarına kolayca çevrilebilir. "Bir algoritma vardır" demek, o algoritmayı yürütüp problemi çözen bir Turing makinesi vardır demektir. Turing makinesi yoksa algoritma da yoktur.

### 7.3 Dil hiyerarşisi

Hoca dil sınıflarını iç içe kümelerle çizer (ekrandan, 02:05:00):

- En içte düzenli diller: NFA, DFA ve düzenli ifadelerle ifade edilir.
- Onu kapsayan bağlamdan bağımsız diller: yığıtlı otomatlarla (PDA) gerçeklenir.
- Onu kapsayan Turing makinesinin tanıdığı diller: bunlar sözde kodlarla, yani Java, C, C++, Python, Fortran gibi bütün programlama dillerinde yazılan programlarla ifade edilir.

Hoca bu kümelerin üstüne yapay zekayı da koyar: her biri bilgiden (information) birikmiş bilgi (knowledge) üreten çok sayıda sistemin birlikte kullanılması. Bunu kurabilmek için hesaplama yapabilmek, yani Turing makineleri ve algoritmalar geliştirebilmek gerekir. Bunun yanında istatistik, olasılık, sinyal işleme, görüntü işleme, ses işleme, hesaplama kuramı ve iyi yazılım bilgisi gerekir.

## 8. Turing Makinesi Çeşitleri ve Benzetim

### 8.1 Standart model

Standart modelde sonsuz bir şerit, okuyup yazan bir kafa ve deterministik bir kontrol birimi vardır; kafa sola ya da sağa gider. Derste şimdiye kadar hep bu model kullanıldı.

### 8.2 Çeşitler

Slayttaki liste (ekrandan, 02:15:00):

- **Kalma seçeneği (stay-option):** Kafa sola ve sağa gitmenin yanında olduğu yerde de kalabilir.
- **Yarı sonsuz şerit (semi-infinite tape):** Şeridin bir başı vardır ama sonu yoktur; bir yönde sonsuzdur.
- **Çok şeritli (multitape):** Üç, dört gibi birden çok şerit vardır.
- **Çok boyutlu (multidimensional):** Kafa sola, sağa, yukarı, aşağı gidebilir ya da kalabilir.
- **Deterministik olmayan (nondeterministic).**

Bunlar klasik standart Turing makinesi değildir ve farklı Turing makinesi sınıfları oluşturur.

### 8.3 Aynı güç

İki makine sınıfı aynı dil kümesini kabul ediyorsa aynı güçtedir. Biçimsel olarak: birinci sınıftaki her $M_1$ makinesi için ikinci sınıfta $L(M_1)=L(M_2)$ olan bir $M_2$ makinesi vardır (ve tersi). Bu çeşitlerin hepsi standart Turing makinesiyle aynı güçtedir. Bunun önemli bir sonucu vardır: standart Turing makinesi için kurulan bir kuram kalma seçenekli, yarı sonsuz şeritli, çok şeritli ve diğer bütün çeşitler için de geçerlidir. Bu yüzden kuramda çeşitler yerine standart model kullanılır.

### 8.4 Benzetim tekniği

Aynı gücü ispatlamak için benzetim (simulation) kullanılır. Bir sınıfın makinesi diğer sınıfın makinesiyle benzetilir. $M_2$, $M_1$'i benzetebiliyorsa $M_2$'nin gücü $M_1$'inkinden büyük ya da eşittir. $M_1$ de $M_2$'yi benzetebiliyorsa $M_1$'in gücü $M_2$'ninkinden büyük ya da eşittir. İkisi birlikte güçlerin eşit olduğunu gösterir.

Benzetimde orijinal makinenin her yapılandırmasına benzetim makinesinde bir yapılandırma karşılık gelir: orijinal hesaplama $d_0 \succ d_1 \succ \cdots \succ d_n$ ise benzetimde $d_0' \succ^* d_1' \succ^* \cdots \succ^* d_n'$ vardır. Orijinal makinenin bir adımı benzetimde birkaç ek adımla yapılabilir; bu yüzden $\succ^*$ kullanılır. Güç, adım sayısına göre değil, kabul edilen dillere göre tanımlanır. Orijinal makine son yapılandırma $d_f$'de kabul ediyorsa benzetim makinesi de karşılık gelen $d_f'$'de kabul eder; iki makine aynı dizgileri kabul eder ve $L(M_1)=L(M_2)$ olur (ekrandan, 02:20:00).

### 8.5 Kalma seçenekli makineler

Kalma seçenekli makinede üç olası kafa hareketi vardır: sol, sağ, kal. Örneğin $q_1$'de $a$ okunur, $b$ yazılır, $q_2$'ye geçilir ve kafa yerini değiştirmez; yalnız durum ve sembol değişir. Hoca bu tür bir geçişin sol ve sağ hareketlerle, birden çok geçiş kullanılarak ifade edilebileceğini söyler ve ayrıntıyı sonraya bırakır.

> **Teorem:** Kalma seçenekli makineler standart Turing makineleriyle aynı güçtedir.

İspat iki yönden yapılacaktır: (1) kalma seçenekli makineler standart Turing makinelerini benzetir; (2) standart Turing makineleri kalma seçenekli makineleri benzetir (ekrandan, 02:25:00). Ders bu noktada biter, ispat sonraki derse kalır.

> **Ek bilgi (derste anlatılmadı):** (1) yönü kolaydır, çünkü standart makinenin her geçişi zaten kalma seçenekli makinede de vardır. (2) yönünde her "kal" geçişi iki adımla taklit edilir: sembol yazılıp ara bir duruma sağa gidilir, ara durumdan okunan sembol değiştirilmeden sola dönülür.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): $\Sigma=\{0,1\}$ üzerinde $r=0^*10(0+1)^*$ düzenli ifadesinin dilini kabul eden bir Turing makinesi tasarlayın. Şerit alfabesi $\Gamma=\{0,1,\$\}$, $\$$ boşluk sembolüdür.

> **Çözüm (derste verildi):** $q_0 \xrightarrow{\$\to\$,R} q_1$; $q_1$ üzerinde $0\to0,R$; $q_1 \xrightarrow{1\to1,R} q_2 \xrightarrow{0\to0,R} q_3$; $q_3$ kabul durumudur. $10$ okunduktan sonra geri kalan her şey $(0+1)^*$ ile eşleştiği için kabul durumundan sonra durum gerekmez (Bölüm 1.2).

**Soru 2** (derste sözlü, 00:11:48): Düzenli ifade $0^*10$ olsaydı makine nasıl değişirdi?

> **Çözüm (derste verildi):** $q_3$ kabul durumu olmaktan çıkar; $q_3 \xrightarrow{\$\to\$,L} q_4$ eklenir ve $q_4$ kabul durumu olur. $q_3$'te boşluktan başka sembol okunursa geçiş yoktur, dizgi kabul edilmez (Bölüm 1.3).

**Soru 3** (ekrandan, 00:20:00): $r=(a+b)^*aa(a+b)^*$ için bir Turing makinesi tasarlayın.

> **Çözüm (derste verildi, diyagram altyazıdan kuruldu):** $q_0 \xrightarrow{\diamond\to\diamond,R} q_1$; $q_1$: $b\to b,R$ döngü, $a\to a,R$ ile $q_2$; $q_2$: $b\to b,R$ ile $q_1$, $a\to a,R$ ile kabul durumu $q_3$ (Bölüm 2).

**Soru 4** (ekrandan, 00:25:00 ve 00:30:00): $L=\{0^{2^n}\mid n\ge 0\}$ dilini tanıyan bir Turing makinesi tasarlayın ($\Gamma=\{x,0,\diamond\}$). Makineyi $00$ ve $000$ girdileri için çalıştırın.

> **Çözüm (derste verildi):** Geçiş tablosu Bölüm 3.3'tedir. $00$ için $q_1 00 \succ \diamond q_2 0 \succ \diamond x q_3 \diamond \succ \diamond q_5 x \succ q_5 \diamond x \succ \diamond q_2 x \succ \diamond x q_2 \diamond \succ \diamond x \diamond q_{accept}$, kabul. $000$ için $q_1 000 \succ \diamond q_2 00 \succ \diamond x q_3 0 \succ \diamond x 0 q_4 \diamond \succ q_{reject}$, red.

**Soru 5** (ekrandan, 00:50:00 ve 00:55:00): $\Sigma=\{a,b\}$ üzerindeki bir dizgiyi, bütün $a$'lar bütün $b$'lerden önce gelecek şekilde yeniden düzenleyen bir Turing makinesi tasarlayın. Örnek: $abaabbbbabb \to aaaabbbbbbb$, $bbba\to abbb$.

> **Çözüm (derste verildi):** $b$'lerden sonraki ilk $a$, önceki $b$ ile yer değiştirir ve başa dönülür; geçiş tablosu Bölüm 5.5'tedir ($q_2$'deki $\#$ geçişi sözlü eklendi).

**Soru 6** (derste sözlü, 01:22:38 ve 01:23:43): $0^n1^n2^n$ bağlamdan bağımsız mıdır? Birlerin sayısı sıfırların sayısının iki katı olan dil ($0^n1^{2n}$) bağlamdan bağımsız mıdır?

> **Çözüm (derste verildi):** $0^n1^n2^n$'de üç bağıntı vardır, bağlamdan bağımsız değildir. $0^n1^{2n}$'de tek bağıntı vardır, bağlamdan bağımsızdır.

**Soru 7** (ekrandan, 01:25:00): $\Sigma=\{0,1,2\}$ üzerinde $L=\{0^n1^n2^n\mid n\ge 0\}$ dilini karar veren bir Turing makinesinin sözde kodunu (implementation-level description) verin.

> **Çözüm (derste verildi):** Bölüm 6.4'teki on adımlı sözde kod.

**Soru 8** (derste sözlü, 01:43:14): Soru 7'deki sözde kodu bir Turing makinesi gerçeklemesine (diyagramına) çevirin.

> **Çözüm (derste verilmedi):** Aşağıdaki makine bu not için kuruldu. Sözde koddan farklı olarak sıfırlar $x$, birler $y$, ikiler $z$ ile işaretlenir; böylece $0^*1^*2^*$ deseni denetimi ayrı bir tarama gerektirmeden işaretleme turlarının içinde yapılır. Boşluk $\diamond$'dır.
>
> | Durum | $0$ | $1$ | $2$ | $x$ | $y$ | $z$ | $\diamond$ |
> |---|---|---|---|---|---|---|---|
> | $q_0$ | $x,R,q_1$ | — | — | — | $y,R,q_4$ | — | $\diamond,R,q_{accept}$ |
> | $q_1$ | $0,R,q_1$ | $y,R,q_2$ | — | — | $y,R,q_1$ | — | — |
> | $q_2$ | — | $1,R,q_2$ | $z,L,q_3$ | — | — | $z,R,q_2$ | — |
> | $q_3$ | $0,L,q_3$ | $1,L,q_3$ | — | $x,R,q_0$ | $y,L,q_3$ | $z,L,q_3$ | — |
> | $q_4$ | — | — | — | — | $y,R,q_4$ | $z,R,q_4$ | $\diamond,R,q_{accept}$ |
>
> Tanımsız bir hücreye düşen girdi reddedilir. $q_0$ en soldaki işaretsiz $0$'ı $x$ yapar; $q_1$ ilk $1$'i, $q_2$ ilk $2$'yi işaretler; $q_3$ en sağdaki $x$'e kadar geri döner. Sıfır kalmayınca $q_4$ yalnız $y$ ve $z$ görüp boşluğa ulaşırsa kabul eder. Örnek: $001122$ için 23 adımda kabul. Makine python ile 10 uzunluğa kadar bütün $\{0,1,2\}$ dizgilerinde denendi ve yalnız $0^n1^n2^n$ biçimindekileri kabul etti.

## Dersin Toparlaması

Bu derste Turing makinesi tasarımı örneklerle çalışıldı. Düzenli ifadelerden makine kurarken NFA/DFA'ya benzer bir yol izlendi, ama iki fark öne çıktı: Turing makinesi kabul durumuna varınca durduğu için ifadenin sonundaki $(0+1)^*$ gibi kısımlar için durum gerekmez, makine deterministik olduğu için de $(a+b)^*aa(a+b)^*$ gibi ifadelerde son okunan sembol durumlarda tutulmalıdır. Ardından düzenli de bağlamdan bağımsız da olmayan $0^{2^n}$ dili için her turda sıfırların yarısını silen bir makine kuruldu ve hesaplama izleriyle denendi. Sıralama makinesinde "$ba \to ab$" yer değiştirmesi ve kafanın bir başa bir sona götürülmesi ilkesi görüldü. $0^n1^n2^n$ için de diyagram yerine sözde kod (implementation-level description) yazıldı.

Son bölümde Turing tezi (mekanik her hesaplama bir Turing makinesiyle yapılabilir) ve algoritmanın Turing makinesiyle tanımı verildi. Dil sınıfları düzenli $\subset$ bağlamdan bağımsız $\subset$ Turing makinesinin tanıdıkları diye sıralandı. Ardından Turing makinesi çeşitleri (kalma seçenekli, yarı sonsuz şeritli, çok şeritli, çok boyutlu, deterministik olmayan) ve bunların standart modelle aynı güçte olduğunun benzetimle nasıl ispatlanacağı anlatıldı. Kalma seçenekli makinelerin standart makinelerle aynı güçte olduğu teoreminin ispatı sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
