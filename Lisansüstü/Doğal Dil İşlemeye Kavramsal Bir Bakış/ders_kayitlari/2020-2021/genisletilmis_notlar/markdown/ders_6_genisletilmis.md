# Ders 6 Genişletilmiş Notu: N-Gram Modelleri, Yumuşatma Teknikleri, Kelime Anlam Belirsizliği ve WordNet

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın. Altyazıda okunmayan slayt tablo ve formülleri, kısa not yazılırken karelerden okunan haliyle alınmıştır.

## İçindekiler

- 1. Dil Modellerine Neden İhtiyaç Var?
- 2. Bağımsız Kelimelerden N-Gram Modeline
- 3. N-Gram Türleri ve Cümle Olasılığı
- 4. Dil Modeli Beklenmedik Bir Soruyu Yanıtlar
- 5. Sıfır Olasılık, Seyrek Matris ve Yumuşatma
- 6. Sayım ve Olasılık Matrisi Örneği
- 7. Yumuşatma Parametreleri
- 8. Add-One Yumuşatma
- 9. Good-Turing
- 10. Back-Off
- 11. N-Gram ile Biçimbirimsel Belirsizlik Giderme
- 12. Kelime Anlamı ve Sense Kavramı
- 13. Kelime Anlam Belirsizliği Giderme Yaklaşımları
- 14. Lesk Algoritması
- 15. Benzerlik ve İlişki
- 16. Derlem Tabanlı Yöntemler
- 17. WordNet Nedir?
- 18. Türkçe WordNet Çalışmaları
- 19. WordNet'teki Kelime İlişkileri
- 20. WordNet'in Sayıları ve İlişkilerin Sözcük Türüne Göre Dağılımı
- 21. WordNet Üzerinden Anlamsal Benzerlik Ölçütleri

## 1. Dil Modellerine Neden İhtiyaç Var?

Ders, önceki derste yarım kalan dil modelleri (language models) konusunun kısa bir tekrarıyla başladı. Doğal dil işlemenin bütün uygulamalarında dil modeli gerekmez, ama birçoğunda gerekir. Hocanın saydığı yerler şunlardır:

- Konuşmadan metne çevirme (speech to text).
- Optik karakter tanıma (OCR).
- Yazar tanıma. Dil modeliyle yazarları ayırt eden özellikler çıkarılabilir.
- Kelime belirsizliğini giderme.

Dil modelleri istatistik tabanlıdır. Kelimelerin, belirli kalıpların ya da karakter dizilerinin olasılıkları kullanılır. Temel soru şudur: Bir cümlenin dilde karşımıza gelme olasılığı nedir?

## 2. Bağımsız Kelimelerden N-Gram Modeline

### 2.1 En kaba model

En kaba yaklaşımda bir cümlenin olasılığı, cümleyi oluşturan kelimelerin birbirinden bağımsız olasılıklarının çarpımıdır. Bu yaklaşımın en basit halinde elimizde $V$ kelimelik bir sözlük vardır. Sözlükte her kelime bir kez yer aldığı için her kelimenin olasılığı $1/V$ alınır.

Biraz daha iyisi, her kelimenin kendi olasılığını kullanmaktır. $n$ kelimelik bir cümle için:

$$P(w_1 w_2 \ldots w_n) \approx \prod_{k=1}^{n} P(w_k)$$

Hoca bunun bir sonuç verdiğini ama yeterince iyi olmadığını söyledi. Çünkü kelimeler doğal dilde birbirinden bağımsız durmaz.

> **Hocanın vurgusu:** Kelimeler doğal dilde bağımsız değildir. Bu yüzden olasılıklarını bağımsız çarpmak gerçekçi sonuç vermez.

İngilizcede "I am", "he is", "she is", "he did" gibi kullanımlarda zamirden sonra genelde yardımcı fiil gelir. "he" ve "did" kelimelerini ayrı ayrı değerlendirmek yerine birlikte geçme olasılığına bakılırsa daha gerçekçi sonuç elde edilir. N-gram modeli bu fikirle ortaya atılmıştır.

### 2.2 Geçmişe bakmak

N-gram modelinde bir kelimenin olasılığı hesaplanırken kelimenin geçmişindeki kelimelerle birlikte kullanım olasılığına bakılır. Hoca bunu dört kelimelik (ya da dört karakterlik, fark etmez) bir "A, B, C, D" dizisiyle anlattı:

- A'nın geçmişi yoktur. Kendi olasılığı alınır.
- B'nin geçmişinde A vardır. B'nin A ile birlikte gelme olasılığı hesaplanır.
- C'nin geçmişinde A ve B vardır. Burada "C metinde kaç kez geçiyor?" diye bakılmaz. "C, A ve B'den sonra kaç kez kullanılmış?" diye bakılır.
- D için aynı şekilde A, B ve C ile birlikte kullanım dikkate alınır.

Bunun genel yazımı zincir kuralıdır (chain rule). Çarpım olduğu için $\prod$ ile gösterilir:

$$P(w_1^n) = \prod_{k=1}^{n} P(w_k \mid w_1^{k-1})$$

$k=1$ için geçmiş boştur ve yalnızca $P(w_1)$ alınır.

### 2.3 Tüm geçmiş neden kullanılamaz?

Bu model güzel görünür, ama pratik değildir. Hocanın örneği şöyledir: Elimizde 10 bin kelimelik bir doküman olsun. 10.000. kelimenin olasılığını bulmak için önceki 9999 kelimeyle birlikte olasılık hesaplamak gerekir. Bunun iki sorunu vardır:

- Hesabı çok maliyetlidir.
- Aynı uzun dizinin derlemde bir daha geçmesi gerekir. Bunun için gereken derlem hayal edilemeyecek kadar büyüktür.

Bu yüzden geçmiş sınırlandırılır. Yalnız son $N-1$ kelimeye bakılır:

$$P(w_n \mid w_1^{n-1}) \approx P(w_n \mid w_{n-N+1}^{n-1})$$

> **Hocanın vurgusu:** Pratikte $N$ en fazla 5'e kadar gider. Hoca 5'i bile çok az gördüğünü söyledi. Genelde 2 ve 3 değerleriyle çok iyi sonuç alınır. $N$ değerini 4-5 yapınca olasılık değerleri biraz daha küçülür, sistem başarısı da yalnızca noktadan sonraki basamaklarda değişir.

## 3. N-Gram Türleri ve Cümle Olasılığı

$N$ değerine göre modellere şu adlar verilir:

| $N$ | Ad | Kullanılan geçmiş |
|---|---|---|
| 1 | Unigram | Yok, tek kelime |
| 2 | Bigram | Bir önceki kelime |
| 3 | Trigram | Önceki iki kelime |
| 4 | Quadgram | Önceki üç kelime |

Hoca "chasing the big dog" dizisiyle "dog" kelimesinin olasılığını örnekledi:

- Unigram: yalnız "dog".
- Bigram: "big dog".
- Trigram: "the big dog".
- Quadgram: "chasing the big dog".

$N=5$ olsaydı geçmişteki 4 kelime kullanılırdı.

### 3.1 Bigram ile cümle olasılığı

$N=2$ için cümle olasılığı şöyle yazılır:

$$P(w_1^n) \approx \prod_{k=1}^{n} P(w_k \mid w_{k-1})$$

Örnek olarak bir derlemden ikili olasılıklar çıkarılmıştır. Hocanın okuduğu değerlerden bazıları: "eat on" 0,16; "eat Indian" 0,04; "eat breakfast" 0,03. Sorulan cümle "I want to eat Chinese food" olsun:

$$P(\text{I want to eat Chinese food}) = P(\text{I} \mid \langle s \rangle)\, P(\text{want} \mid \text{I})\, P(\text{to} \mid \text{want})\, P(\text{eat} \mid \text{to})\, P(\text{Chinese} \mid \text{eat})\, P(\text{food} \mid \text{Chinese})$$

Burada $\langle s \rangle$ cümle başını gösterir. "I" kelimesinin önünde bir kelime yoktur, önünde boşluk vardır. Bu ikililerin olasılıkları derlemden bulunup çarpılır. Çıkan sonuç, bu cümlenin bu sırayla ve araya başka kelime girmeden dilde karşımıza gelme olasılığıdır.

<!-- BELİRSİZ: Slayttaki ikili olasılık listesinin tamamı ve çarpım sonucu altyazıda okunmuyor. -->

## 4. Dil Modeli Beklenmedik Bir Soruyu Yanıtlar

Hoca şu soruyu sordu: Çin mutfağı mı daha popülerdir, İngiliz mutfağı mı? Biz bunu insan olarak deneyimle biliriz. Hemen her ülkede Çin restoranı vardır, ama İngiliz restoranına pek rastlanmaz.

Bilgisayar bu bilgiyi dil modelinden çıkarabilir. Aynı cümlenin içine bir kez "Chinese food", bir kez "British food" yazılır. Cümlenin ne olduğunun önemi yoktur. İki cümlenin bigram olasılıkları hesaplanıp karşılaştırılır.

"Chinese food" içeren cümlenin olasılığı çok daha büyük çıkar. İnternetteki kaynaklar kullanılıyorsa bunun anlamı şudur: Çin yemekleriyle ilgili çok daha fazla yayın, bilgi ve haber vardır. Buradan Çin yemeklerinin daha popüler olduğu sonucuna varılabilir. Hoca bunu, dil modelinin hiç beklenmedik bir noktada bir soruya cevap verebilmesinin örneği olarak verdi.

## 5. Sıfır Olasılık, Seyrek Matris ve Yumuşatma

### 5.1 Sıfır olasılık neden çıkar?

Bazı cümlelerin olasılığı sıfıra çok yakın ya da sıfır çıkar. Hocanın saydığı nedenler şunlardır:

- **Yazım hatası.** Bir kelime yanlış yazılmışsa başkası büyük olasılıkla aynı şekilde yanlış yazmaz. Bu yüzden derlemde geçmez ve olasılığı sıfır olur.
- **Çok nadir konular.** Bunların olasılığı da çok küçük ya da sıfır olur.

### 5.2 Seyrek matris

Sözlük boyutu $V$ olsun. Hocanın örneğinde $V$, 300 bin farklı kelimedir. $N=2$ alınırsa kelime ikililerinin frekansları için $V \times V$ boyutunda bir matris gerekir. Bu matriste "aba aba" ya da "aba abla" gibi ikililer hiç geçmez. Matrisin büyük çoğunluğu sıfırlardan oluşur. Böyle bir matrise seyrek (sparse) matris denir.

Hoca derlem büyütülerek bu sorunun çözülemeyeceğini Zipf yasası (Zipf's law) ile bağladı. Kelimeler en çok kullanılandan en aza doğru sıralandığında, her dilde çok az kullanılan kelimeler de mutlaka vardır. Yani derlem ne kadar büyük olursa olsun seyrek veri her zaman olacaktır.

> **Hocanın vurgusu:** Hiçbir derlem bütün kelime ikililerini içermez. Seyrek veri her zaman vardır.

### 5.3 Sıfırın zararı

Makine öğrenmesinde Naive Bayes gibi bazı yöntemler özelliklerin olasılıklarını çarpar. Olasılıklar 0,5; 0 ve 0,9 ise çarpım sıfır çıkar. Çünkü sıfır çarpmanın yutan elemanıdır. Sınıflandırma yapılıyorsa bu sıfır, verinin bir sınıfa yerleşmesini engeller ya da yanlış sınıfa yerleşmesine yol açar.

Sıfırlardan ve çok düşük olasılıklardan kurtulmak için yapılan işleme yumuşatma (smoothing) denir. Amaç, sıfır yerine sıfıra yakın ama sıfır olmayan bir değer vermektir.

> **Hocanın vurgusu:** Sıfırlara rastgele değer atanamaz ("sıfırsa 5 atayayım" denemez). Mantıklı bir yöntem gerekir. Yumuşatma teknikleri bunun içindir.

## 6. Sayım ve Olasılık Matrisi Örneği

Sözlük şu kelimelerden oluşsun: I, want, to, eat, Chinese, food, lunch. $N=2$ alınır. Önce derlemden her kelimenin tek başına kaç kez geçtiği (unigram sayımı), sonra ikililerin kaç kez geçtiği çıkarılır. Bigram sayımları aşağıdadır. Satır önceki kelimeyi, sütun sonraki kelimeyi gösterir.

|  | I | want | to | eat | Chinese | food | lunch |
|---|---|---|---|---|---|---|---|
| I | 8 | 1087 | 0 | 13 | 0 | 0 | 0 |
| want | 3 | 0 | 786 | 0 | 6 | 8 | 6 |
| to | 3 | 0 | 10 | 860 | 3 | 0 | 12 |
| eat | 0 | 0 | 2 | 0 | 19 | 2 | 52 |
| Chinese | 2 | 0 | 0 | 0 | 0 | 120 | 1 |
| food | 19 | 0 | 17 | 0 | 0 | 0 | 0 |
| lunch | 4 | 0 | 0 | 0 | 0 | 1 | 0 |

Unigram sayımları: I 3437, want 1215, to 3256, eat 938, Chinese 213, food 1506, lunch 459.

Tablodan iki şey görülür:

- **Sıra önemlidir.** "want I" 3 kez, "I want" 1087 kez geçmiştir. İkililerde değişme özelliği yoktur.
- **Matris seyrektir.** Çok sayıda sıfır vardır.

Hoca bir de şunu sordu: İngilizcede "I I" arka arkaya kullanılmaz, öyleyse 8 sayımı nereden geldi? Hocanın cevabı şudur: Dokümanlarda Romen rakamıyla yazılmış maddeler vardır ve "II" klavyede iki büyük "I" ile yazılınca sayıma "I I" olarak girmiş olabilir. Hoca, şu anda bunların doğruluğuyla uğraşmadıklarını da ekledi.

### 6.1 Olasılıkların hesaplanması

Bigram olasılığı, ikilinin sayımının önceki kelimenin sayımına bölünmesiyle bulunur. Bölünen kelime, olasılığı hesaplanan kelime değil, onun geçmişindeki kelimedir:

$$P(w_n \mid w_{n-1}) = \frac{C(w_{n-1} w_n)}{C(w_{n-1})}$$

**Örnek 1: "I I".**

- $C(\text{I I}) = 8$, $C(\text{I}) = 3437$.
- $P(\text{I} \mid \text{I}) = 8/3437 \approx 0{,}0023$.

**Örnek 2: "I want".**

- $C(\text{I want}) = 1087$, $C(\text{I}) = 3437$.
- $P(\text{want} \mid \text{I}) = 1087/3437 \approx 0{,}32$.

Bütün hücreler böyle hesaplanınca olasılık matrisi elde edilir. Sayım matrisi seyrekse olasılık matrisi de seyrektir.

> **Ders sonrası not:** Hoca "I I" olasılığını derste 0,023 diye okudu. Doğrusu $8/3437 \approx 0{,}0023$.

## 7. Yumuşatma Parametreleri

Yumuşatma formüllerinde üç parametre kullanılır:

- $V$: Sözlük boyutu (vocabulary size), yani farklı kelime sayısı.
- $N_T$: Derlemdeki toplam kelime sayısı. Farklı kelime sayısı değildir. On binlerce dokümanlık bir derlemin bütün kelimelerinin sayısıdır.
- $T$: O ana kadar görülmüş ayrık kelime sayısı. İşlem sırasında o ana kadar karşılaşılanları sayar. $V$ ve $N_T$ değerlerinden küçüktür.

Hoca onlarca yumuşatma tekniği olduğunu, akademik çalışmalarda daha çok kullanılan ve daha iyi sonuç veren üçünü anlatacağını söyledi: add-one, Good-Turing ve back-off.

## 8. Add-One Yumuşatma

### 8.1 Yöntem

Adından anlaşılacağı gibi sayımlara 1 eklenir. Yalnızca sıfırlara değil, bütün sayımlara eklenir: 0 olan 1, 5 olan 6 olur. Sonra bir normalizasyon katsayısıyla çarpılır.

Normalizasyon, değerleri belirli bir aralığa sıkıştırmaktır. Hocanın benzetmesi: 1000 ile 10.000 arasındaki frekansları 1 ile 100 arasına sıkıştırmak gibi düşünülebilir.

Yumuşatılmış sayım:

$$c_i' = (c_i + 1)\frac{N_T}{N_T + V}$$

Yumuşatılmış olasılık, bu değeri $N_T$'ye bölerek bulunur. $N_T$'ler sadeleşir:

$$P'(w_i) = \frac{c_i'}{N_T} = \frac{c_i + 1}{N_T + V}$$

Normalizasyon katsayısı illa bu olmak zorunda değildir. Hoca farklı katsayılar kullanılabileceğini söyledi. Örneğin veri madenciliği ya da istatistikte görülen min-max veya z-score normalizasyonu kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Bigram için bu formül genellikle önceki kelimenin sayımıyla yazılır: $P'(w_n \mid w_{n-1}) = \dfrac{C(w_{n-1}w_n) + 1}{C(w_{n-1}) + V}$. Paydaya $V$ eklenmesinin nedeni, her satırdaki $V$ hücrenin her birine 1 eklenmiş olmasıdır. Böylece satırın olasılıkları toplamı yine 1 olur.

Add-one uygulanınca matris artık seyrek değildir. Hoca örnek olarak "lunch want" ikilisini gösterdi. Bu ikilinin hem frekansı hem olasılığı önceden sıfırdır. Yumuşatılmış tablodaki değeri ise 0,3048 olarak okudu. Böylece olasılık çarpımı gerektiğinde sonuç sıfır çıkmaz.

<!-- BELİRSİZ: 0,3048 değerinin hesaplandığı slayt tablosu altyazıda yok. Hangi parametrelerle hesaplandığı doğrulanamadı. -->

### 8.2 Sınav sorusu örneği

> **Hocanın vurgusu:** Bu örnek daha önce sınav sorusu olmuş, öğrenciler hata yapmış. Hoca aynı hata tekrar yapılmasın diye artık derste anlatıyor.

Sözlükte 7 kelime vardır: Bugün, de, her, zamanki, gibi, eve, gidiyorum. Bu 7 kelimeyle yazılabilecek bütün ikililerin sayısı $7 \times 7 = 49$ olur. Bu örnekte formüldeki $V$ yerine bu 49 kullanılır.

Hesaplanacak cümle şudur: "Bugün de her zamanki gibi gidiyorum". $N=2$ alınırsa ikililer şunlardır:

1. Bugün de
2. de her
3. her zamanki
4. zamanki gibi
5. gibi gidiyorum

**Yumuşatmadan önce.** Her ikili 1 kez geçer. Toplam 5 ikili olduğu için her ikilinin olasılığı slaytta şöyle verilmiştir:

$$P_{\text{Bugün de}} = \frac{1}{5}$$

Bütün ikililer için değer aynıdır. Hoca bunun bir uydurma örnek olduğunu, bu yüzden hepsinin aynı çıktığını söyledi.

**Add-one ile.** Slayttaki formül şudur:

$$P_i^* = \frac{C_i + 1}{N + V}$$

Burada parametreler şöyledir:

- $C_i$: İkilinin sayımı. Burada 1.
- $N$: O ana kadar karşılaşılan ikili sayısı. Burada 5.
- $V$: Sözlükteki kelimelerle yazılabilen bütün ikililer. Burada 49.

$$P_{\text{Bugün de}} = \frac{1 + 1}{5 + 49} = \frac{2}{54}$$

Cümlenin olasılığı bu beş değerin çarpımıdır. Hoca çarpımın sonucunu söylemedi (ara adım eklendi):

$$\left(\frac{2}{54}\right)^5 = \left(\frac{1}{27}\right)^5 \approx 6{,}97 \times 10^{-8}$$

Karşılaştırma için yumuşatmasız değer $(1/5)^5 = 1/3125 = 0{,}00032$ olur (ara adım eklendi). Görülen ikililerin olasılığı azalır, çünkü olasılığın bir kısmı görülmemiş ikililere dağıtılmıştır. Toplam yine 1 kalır: 5 ikili için $5 \times 2/54$, görülmemiş 44 ikili için $44 \times 1/54$, toplam $54/54$ (ara adım eklendi).

**Soru:** Tabloda "eve" kelimesi de var. Cümleye eklenince ikili sayısının 6 olması gerekmez mi?

**Cevap:** Tablodaki kelimeler sözlüktür, cümle değildir. Sözlükteki 7 kelimeyle yazılabilecek ikililer bunlardır. Cümlenin sözlükteki her kelimeyi içermesi gerekmez. "Bugün eve gidiyorum" da yazılabilirdi. Hoca sınavdaki karışıklığın da bu yüzden çıktığını söyledi. Slayta birkaç cümle daha koysaydı bu sorun yaşanmazdı.

> **Ders sonrası not:** Kısa notta belirtildiği gibi slayttaki sayım tablosunda "gibi eve" ve "eve gidiyorum" ikilileri 1, "gibi gidiyorum" ikilisi 0 görünüyor. Bu tablo aslında "Bugün de her zamanki gibi eve gidiyorum" cümlesinden (6 ikili) çıkarılmış gibi duruyor. Bu tabloya göre $P_{\text{gibi gidiyorum}}$ yumuşatmasız 0, add-one ile $\frac{0+1}{N+49}$ olmalıdır. Slayttaki $\frac{1}{5}$ ve $\frac{2}{54}$ değerleri ise bu ikili 1 kez geçmiş gibi hesaplanmıştır. Öğrencinin itirazı bu yüzden yerindedir. Böyle bir soruda sayım tablosunun hesaplanan cümleyle tutarlı olup olmadığına dikkat edin.

## 9. Good-Turing

Hoca bu yöntemi balık tutma örneğiyle anlattı. Oltayla şu balıklar tutulmuş olsun: 10 aynalı sazan (carp), 3 morina (cod), 2 tuna, 1 alabalık (trout), 1 som (salmon), 1 yılan balığı (eel). Toplam $10 + 3 + 2 + 1 + 1 + 1 = 18$ balık.

Kayıktaki diğer kişi soruyor: Bir sonraki balığın yeni bir tür olma olasılığı nedir? Örneğin lüfer gelebilir mi? Lüferin şu anki olasılığı sıfırdır. Good-Turing buna sıfır yerine anlamlı bir değer verir.

Metin dünyasındaki karşılığı şudur: Bir dokümanda 10 "medeniyet", 3 "hukuk", 2 "cumhuriyet", birer de "anayasa" ve "yargıç" gibi kelimeler olsun. Gelecek kelimenin daha önce görülmemiş bir kelime olma olasılığı nedir?

Formül şudur:

$$P(\text{yeni tür}) = \frac{\text{bir kez görülen tür sayısı}}{\text{toplam gözlem sayısı}} = \frac{3}{18}$$

Mantığı şöyle: Sıfır olan bir şey görülürse en küçük değeri 1 olur, yani en az bir kez görülmüş olur. Bu yüzden bir kez görülenlerin oranı kullanılır. Bir kez görülen türler alabalık, som ve yılan balığıdır.

> **Ek bilgi (derste anlatılmadı):** Görülmemiş olaylara $N_1/N$ kadar olasılık verilince toplamın 1'de kalması için görülen olayların sayımı da indirilir. Good-Turing'in tam biçiminde $c$ kez görülen bir olayın sayımı $c^* = (c+1)\dfrac{N_{c+1}}{N_c}$ olur. Burada $N_c$, tam $c$ kez görülen tür sayısıdır.

## 10. Back-Off

Back-off yöntemi n-gram modelini kullanır. Hoca trigram üzerinden anlattı. $w_i$ kelimesinin olasılığı $w_{i-2}$ ve $w_{i-1}$ ile birlikte hesaplanmak istenir. Bu üçlü derlemde hiç geçmemiş olabilir. Yöntem o zaman $N$ değerini bir azaltır:

- Üçlünün sayımı sıfırdan büyükse üçlü olasılık kullanılır.
- Üçlü yoksa ve ikili varsa ikili olasılık kullanılır.
- O da yoksa yalnız kelimenin kendi olasılığı kullanılır.

Formülle:

$$\hat{P}(w_i \mid w_{i-2}w_{i-1}) = \begin{cases} \tilde{P}(w_i \mid w_{i-2}w_{i-1}), & C(w_{i-2}w_{i-1}w_i) > 0 \\ \alpha_1 \tilde{P}(w_i \mid w_{i-1}), & C(w_{i-2}w_{i-1}w_i) = 0 \text{ ve } C(w_{i-1}w_i) > 0 \\ \alpha_2 \tilde{P}(w_i), & \text{diğer durumlarda} \end{cases}$$

$N$ illa 3 olmak zorunda değildir. 4 ya da 5 de olabilir.

### 10.1 $\alpha$ katsayılarının görevi

Asıl istenen olasılık üçlünün olasılığıdır. İkilinin olasılığı ondan büyük, tek kelimenin olasılığı daha da büyük olur. Bu yüzden katsayılar bu değerleri küçültüp üçlünün olasılığına yaklaştırır. Tek kelimenin olasılığı daha büyük olduğu için daha küçük bir sayıyla çarpılır.

Katsayılar nereden gelir? Hoca bunları bizim önceden bilemeyeceğimizi söyledi. İki yol vardır:

- Büyük bir derlem alınır. Oranlar çıkarılır. İkilinin ve tek kelimenin üçlüye yaklaşması için hangi çarpanlar gerektiği bulunur. Bu, tek tek çiftler için değil, bütün üçlülerde yaklaşık aynı sonucu verecek biçimde yapılır.
- Bununla uğraşmak istemeyen, literatürde bu değerleri veren bir çalışmayı bulup aynı katsayıları kullanır.

### 10.2 Üç yöntemin özeti

- **Add-one:** Her sayıma 1 eklenir, normalizasyon katsayısıyla çarpılır.
- **Good-Turing:** Görülmemiş olaya, bir kez görülenlerin sayısının toplam gözleme oranı verilir.
- **Back-off:** Hangi n-gram kullanılıyorsa önce ona bakılır. Yoksa $N$ bir azaltılır. Bu, $N=1$ olana kadar sürer.

## 11. N-Gram ile Biçimbirimsel Belirsizlik Giderme

N-gram modellerinin bir başka kullanımı da biçimbirimsel (morphological) belirsizliği gidermektir. Hoca ilk haftaları hatırlattı: Biçim bilimsel analiz, kelimeyi kök ve eklerine ayırır. Araç olarak Zemberek, Porter Stemmer ve NLTK (Natural Language Toolkit) anılmıştı.

Bu araçlar bir kelimenin olabilecek bütün çözümlemelerini verir. Hangisinin doğru olduğunu söylemez. Örneğin "yüz" kelimesi fiil olabilir ("yüzmek"), isim olabilir, sayı olabilir. Kök aynıdır, tip farklıdır.

Daha önce bu sorun sentaktik analizle çözülüyordu. Cümle hangi ağaç yapısıyla analiz edilebiliyorsa, kelimenin o ağaçtaki karşılığına bakılıyordu. Elde parser yoksa bu iş n-gram modeliyle de yapılabilir.

**Örnek cümleler:**

- "Çoban bizim için sürüden bir koyun seçti." Buradaki "koyun" hayvandır, isimdir.
- "Oyuna devam etmek istiyorsanız beşer lira koyun." Buradaki "koyun" fiildir ("koymak").

Hoca "Anne çocuğunu koynunda uyutuyor" cümlesini de başka bir "koyun" kullanımı olarak andı ("koynu" biçimine dönüşür).

**Yöntem adımları:**

1. $N$ belirlenir. Hoca $N$ büyüdükçe sonucun daha kesin olacağını, ama 2 ve 3'ün yeterli olduğunu söyledi. Burada $N=2$ alınmıştır.
2. Belirsizliği giderilecek kelimeye $w_t$ denir. Burada $w_t$ = "koyun".
3. Derlemden $w_{t-1}$ ile $w_t$ ikilisinin peş peşe gelme olasılıkları çıkarılır. Örneğin "bir koyun", "lira koyun".

İki ayrı derlem hazırlanır. Birinde "koyun" hep hayvan anlamında, diğerinde hep fiil anlamında geçer. Bunlardan şu tablolar çıkar:

| Nitelik | Hayvan anlamlı "koyun" derlemi | Fiil anlamlı "koyun" derlemi |
|---|---|---|
| Fiil | 0,01 | 0,8 |
| İsim | 0,5 | 0,01 |
| Zamir | 0,01 | 0,01 |
| Sayı | 0 | 0 |
| Ünlem | 0,007 | 0,007 |
| Edat | 0,001 | 0,002 |

Yeni bir doküman gelince aynı olasılıklar onun için de çıkarılır ve hangi tabloya benzediğine bakılır:

- Kurban Bayramı ile ilgili bir dokümanda "koyun" isim olarak kullanılır. Olasılıklar ilk tabloya uyar. Sonuç: isim.
- Kumarla ilgili ("bir koydun beş aldık" gibi) bir dokümanda fiil kullanımı fazladır. Olasılıklar ikinci tabloya uyar. Sonuç: fiil.

> **Ders sonrası not:** Hoca NLTK için "Stanford Üniversitesi'nin hazırladığı" dedi. NLTK, Pennsylvania Üniversitesi'nde geliştirilmiştir. Stanford'un ayrı araç seti Stanford CoreNLP'dir. Hoca Porter Stemmer'ı da "Türkçe ve diğer diller için" diye andı. Özgün Porter Stemmer İngilizce içindir.

## 12. Kelime Anlamı ve Sense Kavramı

Aranın ardından yeni bir konuya geçildi. Şimdiye kadar kelimelere yalnızca sayısal birer varlık olarak bakıldı: bir dokümanda kaç kez geçtikleri, önceki kelimelerle birlikte kullanım sıklıkları. Yeni soru şudur: Kelimelerin anlamları bazı problemleri çözmeye yardım edebilir mi?

### 12.1 "Kalem" örneği

Hoca "kalem" deyince aklımıza masadaki kalemin geldiğini söyledi. Sözlük, bir veri tabanıdır. İçinde kelime, kelimenin anlamı ve o anlamın geçtiği örnek cümle bulunur. Bir İngiliz için "kalem" hiçbir şey çağrıştırmaz, ona "pencil" ya da "pen" demek gerekir. Yani bu, kişinin kendi diliyle ilgilidir.

"Kalem" kelimesinin sözlükte 6 anlamı vardır:

1. Yazma, çizme ve benzeri işlerde kullanılan araç: "Kalem masanın üstünde."
2. Resmî kuruluşlarda yazı işlerinin görüldüğü yer: "Kalemimiz bugün hizmet vermeyecektir." Kamu binalarındaki kalem müdürü odası buna örnektir.
3. Yontma işlerinde kullanılan ucu sivri ya da keskin araç: "oymacı kalemi".
4. Çeşit, tür: "beş kalem ilaç", "beş kalemlik fatura". Yani 5 ayrı ürün.
5. Bazı dizimlerde yazı: "kaleme almak", yani bir konu hakkında yazmak.
6. Yazar: "Peyami Safa edebiyatımızın usta kalemlerindendir."

Neden hep ilk anlam aklımıza gelir? Çünkü ilk anlam dilde en çok kullanılan ve büyük olasılıkla en önce öğrendiğimiz anlamdır.

Hocaya göre bazı kelimelerin belki tek anlamı vardır. Bazılarında iki anlam vardır ama aralarındaki farkı bir insanın bile anlaması zordur. Bilgisayara anlatmak ise çok daha zordur. Bazılarında da anlamlar açıkça farklıdır.

### 12.2 Sense

Bir kelimenin hangi anlamda kullanıldığını anlamak için cümleye, yani bağlama (context) bakmak gerekir.

**Sense (anlam):** Bağlamdaki kullanım ile kelimenin gerçek anlamı arasındaki bağlantıyı belirleyen kavramdır.

Bu bilginin gerekip gerekmediği uygulamaya bağlıdır. Metindeki "kalem" sayısını bulmak için anlamlara bakmak gerekmez. Dokümanları içeriklerine göre ayırmak için gerekebilir.

### 12.3 Yarışmalar

Kelime anlam belirsizliğini gidermek için her yıl Senseval ve SemEval yarışmaları düzenlenir. Düzenleyen kurum veri setini kendisi hazırlar. Yarışmalar önce İngilizce için başlamış, sonra başka diller için de gruplar açılmıştır. Türkçe için de vardır. Başarılı olan algoritma literatüre girebilir. Bu alanda çalışanlar burada bir araya gelir.

## 13. Kelime Anlam Belirsizliği Giderme Yaklaşımları

Kelime anlam belirsizliği giderme (word sense disambiguation, WSD) için iki sözcük seçme yaklaşımı vardır.

### 13.1 Seçilmiş sözcük yaklaşımı (lexical sample)

Araştırmacı birden fazla anlamı olan belirli kelimeleri kendisi seçer: "kalem", "yüz", "koyun" gibi. "Yalnız şu isimler" ya da "yalnız şu fiiller" diye sınırlayabilir.

Adımlar şöyledir:

1. Küçük bir kelime grubu, sözlükteki anlamlarıyla birlikte alınır.
2. Derlemde bu kelimelerin geçtiği cümleler bulunur.
3. Bir insan her cümlede kelimenin hangi anlamda kullanıldığını etiketler.

Avantajı şudur: Az sayıda kelime olduğu için anlam tablosu etiketleyicinin önündedir. Tablo olmasa insan birkaç anlamı aklında tutar, diğerlerini yanlış etiketleyebilir. Böylece kolayca etiketli derlem elde edilir.

### 13.2 Tüm sözcük yaklaşımı (all-words)

Dildeki bütün kelimeler ve bütün anlamları ele alınır. Örneğin 300 bin kelimenin derlemde hangi anlamda geçtiği işaretlenir. Bu, büyük bir grubun yapacağı bir çalışmadır.

Başarı düşük olduğu için ek bilgi gerekir:

- Türkçe gibi sondan eklemeli dillerde kelimenin kökü.
- Kelimenin büyük harfle yazılıp yazılmadığı.
- Kelimenin cümlenin hangi öğesi olduğu.

Bu özellikler bir sınıflandırma yöntemine verilir, model kurulur, yeni gelen veri etiketlenir.

> **Hocanın vurgusu:** Çalışmaların büyük çoğunluğu seçilmiş sözcük yaklaşımıyla yapılır, başarı da daha yüksektir. Hoca tüm sözcük yaklaşımıyla yapılmış akademik çalışmaya rastlamadığını, İngilizcede de olduğunu sanmadığını söyledi. Derin öğrenmeden sonra yapılmış çalışmalar olabilir, ama literatürü taramadığını belirtti.

### 13.3 Yöntemler

Sözcük seçiminden sonra yöntemler çalıştırılır. Yöntemler kullandıkları kaynağa göre ayrılır:

- Bilgi tabanlı yöntemler. Sözlük ve kelime ağı (WordNet) kullanılır.
- Derlem tabanlı yöntemler.
- Bilgi ile derlemi birlikte kullanan melez yöntemler.
- Makine öğrenmesi yöntemleri (denetimli ve denetimsiz). Özellik olarak kelimenin cümledeki yeri, birlikte geçtiği kelimeler verilir.

## 14. Lesk Algoritması

Lesk algoritması bilgi tabanlı bir yöntemdir. Sözlük anlamının bağlamla örtüşmesine dayanır. Oxford sözlüğüyle İngilizcede başarısı %50-%70 arasındadır. Anlam sayısı az olan kelimelerde %70'e yaklaşır. 6, 7, hatta 10 anlamı olan kelimelerde %50'ye düşebilir.

### 14.1 Adımlar

1. Tümcede belirsizliği giderilecek sözcük seçilir.
2. Sözcüğün sözlükteki açıklamaları ve örnek tümceleri incelenir.
3. Tümcedeki diğer kelimelerle eşleşen sözcükler tespit edilir.
4. En çok örtüşme hangi anlamdaysa sözcüğe o anlam atanır.
5. Bazı uygulamalarda işlevsel kelimeler (function word, stop word) çıkarılır. Bunlar tek başına anlam ifade etmeyen kelimelerdir: "ve", "veya", "böylece", "için", "çünkü", "gibi".
6. Türkçe gibi sondan eklemeli dillerde kelimelerin kök ya da gövde biçimleri alınabilir.

### 14.2 "Konak" örneği

Cümle: "Eren'in konak gibi büyük evi var." Soru: "konak" hangi anlamda kullanılmıştır? Bunu insan değil, bilgisayar bulacaktır.

Cümlede "konak" ile birlikte "Eren", "gibi", "büyük", "evi" ve "var" geçer. "Konak" kelimesinin sözlükte 7 anlamı vardır:

1. Büyük ve gösterişli ev.
2. Devlet görevlilerinin resmî konutu ("vali konağı").
3. Konakçı.
4. Araba ya da hayvanla bir günde alınan yol.
5. Yolculukta geceyi geçirmek için inilen, konaklanılan yer.
6. Kundak çocuklarının başlarında görülen kepek tabakası.
7. Gözde oluşan ince tabaka.

Örtüşmeler şöyledir:

- 1. anlam: "büyük", "ev" ve "konak". 3 çakışma.
- 2. anlam: "gibi" ve "konak". 2 çakışma.
- Diğer anlamlarda çakışma 1'e iner. "Konak" kelimesi zaten her anlamda geçtiği için hepsinde en az 1 vardır.

En çok çakışma 1. anlamdadır. Öyleyse "konak" burada "büyük ve gösterişli ev" anlamındadır.

Hoca bu örnekte 5. ve 6. adımları uygulamadı. Uygulansaydı "gibi" çıkarılırdı.

Hoca ek bir sorun daha gösterdi: 2. anlamdaki "konut" kelimesi "ev" ile eş anlamlıdır. Daha başarılı sonuç için eş anlamlılar da hesaba katılmalıdır. O zaman 2. anlamın çakışması da 3 olur.

Hoca bir de kişisel bir gözlem paylaştı: Kaç yıldır Türkçe konuşmasına rağmen "konak" kelimesinin 7 anlamından yalnızca 3'ünü bildiğini söyledi. Bilinmeyen anlamlar varken bir derlemde bütün kelimeleri nasıl etiketleyecek? Tüm sözcük yaklaşımının zorluğu budur. Seçilmiş sözcüklerde anlam listesi önüne açılır ve bilinmeyen anlamlar da rahatça etiketlenir.

### 14.3 Zayıf yönler

- Sözlük açıklamalarında örnek tümcedeki sözcükler hiç geçmeyebilir. Yalnız "konak" kelimesi kalabilir.
- Birden fazla anlamda aynı sayıda örtüşme çıkabilir. Hangisinin alınacağı belli olmaz.

### 14.4 Geliştirilmiş sürümler

- **Corpus Lesk:** Örtüşmelere ağırlık verir. Çakışan kelime hedef kelimenin hemen sağında ya da solundaysa 3, iki kelime uzağındaysa 2, daha uzaktaysa 1 ile çarpılır.
- **Uyarlanmış Lesk (Adapted Lesk):** Yalnız hedef kelimenin değil, cümledeki diğer kelimelerin de sözlük tanımlarına bakar. Örneğin "Eren", "büyük" ve "ev" kelimelerinin anlamlarının "konak" anlamlarıyla örtüşüp örtüşmediği incelenir.

Hoca bunların başarıyı ne kadar artırdığı bilgisinin elinde olmadığını, bu yöntemleri kullanan makalelerde temel Lesk ile karşılaştırma bulunacağını söyledi.

## 15. Benzerlik ve İlişki

Sözlüğün dışında kullanılabilecek bir başka kaynak kelime ağıdır (WordNet). Hoca bunu şu örnekle anlattı: Su ile bardak arasındaki ilişkiye 1 ile 5 arasında puan verin. Çoğu kişi 4 ya da 5 der, kimse 1 demez. Bardak ile şemsiye için ise çoğu kişi 1 der, kimse 5 demez.

İnsan bunu günlük hayat deneyimiyle yapar. Bilgisayar bunu bilmez. Bilgisayara bu bilgiyi vermek için WordNet ortaya atılmıştır. WordNet'te kelimeler arasında olabilecek ilişkiler çıkarılmıştır. Böylece iki sözcüğün eş ya da yakın anlamlı olup olmadığı ölçülebilir, aralarındaki ilişkiler bulunabilir.

**İlişki ile benzerlik farklıdır:**

- "Akıllı" ile "aptal" arasında güçlü bir ilişki vardır. Bu bir zıtlık ilişkisidir. Ama bu iki kelime benzer değildir.
- "Benzin" ile "araba" ilişkilidir, ama benzer değildir.

Yani ilişki yüksek, benzerlik düşük olabilir. Hoca bunun tersinin de olabileceğini söyledi.

## 16. Derlem Tabanlı Yöntemler

Bu yöntemler makine öğrenmesi yöntemleridir. Etiket bilgisine göre üçe ayrılır.

### 16.1 Denetimli yöntemler (supervised)

Kelimelerin hangi anlamda kullanıldığını gösteren etiketli veri gerekir. Kelimenin hangi kelimelerle birlikte kullanıldığı ve cümledeki yeri gibi bilgiler etiketle birlikte sisteme verilir. Model kurulur, test verisinin etiketi bulunur. En büyük sorun yeterli etiketli verinin olmamasıdır.

### 16.2 Yarı denetimli yöntemler (semi-supervised)

Az miktarda etiketli veri denetimli yöntem için yetmez, ama bu veriyi boşa harcamak da istemeyiz. Sistem bu az etiketle beslenir ve adım adım öğretilir. Sonuç denetimli yöntem kadar başarılı olmaz.

### 16.3 Denetimsiz yöntemler (unsupervised)

Hiç etiketli veri yoktur. Zor yöntemlerdir. Bu problemde yüksek sonuç alınamaz. Gerçek dünyada da yarı denetimli yöntemlerden daha düşük sonuç verir. Hoca işleyişi şöyle anlattı:

1. Etiketsiz dokümanlar vardır. İçlerinde birden fazla anlamı olan kelimeler geçer, ama hangi anlamda geçtikleri etiketlenmemiştir.
2. Terim-doküman matrisi çıkarılır. Her kelimenin her dokümanda kaç kez geçtiği yazılır.
3. Her kelime bir vektör olur. Vektörün uzunluğu doküman sayısıdır. Örneğin 100 doküman varsa 100 elemanlıdır.
4. Kelime vektörlerinin birbirine benzerliği ölçülür.
5. İki vektör benzerse bu kelimeler en çok aynı konulu dokümanlarda geçiyor demektir. Dokümanların konusuna bakılarak kelimelerin hangi anlamda kullanıldığı söylenebilir.

Temel fikir şudur: Bir dokümandaki kelimeler aynı konuyu anlatır. Bu yüzden birbirine yakın anlamlar taşır. Hocanın örneği: Bir dokümanda hem "koyun" hem "yüz" geçiyorsa "koyun" hayvandır, "yüz" ise deri yüzmektir. Aynı dokümanda "koyunumla denize girdim" gibi bir şey olmaz.

Bu yöntem zahmetlidir ve her zaman iyi sonuç vermez. Bu yüzden denetimsiz çalışmalar azdır.

### 16.4 Karşılaştırma

| Yöntem | Güçlü yan | Zayıf yan |
|---|---|---|
| Bilgi tabanlı | Doğruluk yüksektir, etiket bilgisi hazırdır. | Örtüşmeye dayalı olduğu için örtüşme bulunamayabilir. |
| Denetimli | Gerçekleştirme açısından diğerlerinden üstündür. | Büyük etiketli veri gerekir, kaynaklar kısıtlıdır. |
| Denetimsiz | Etiketli veri gerekmez. | Zordur ve başarısı düşüktür. |

## 17. WordNet Nedir?

WordNet (kelime ağı), bir dilin bütün kelimelerini, tanımlarını ve kelimeler arasındaki anlamsal ilişkileri içeren bir veri tabanıdır.

- İngilizce için ilk olarak Princeton Üniversitesi tarafından elle oluşturulmuştur. Hoca bunun çok meşakkatli bir süreç olduğunu vurguladı.
- Bugün 200'den fazla dili kapsar. İngilizce dışındaki dillerde bütün kelimeler için henüz tamamlanmamıştır.
- İlişkiler synset'ler (eşkümeler) arasında tanımlanır. Synset: bir kelime, o kelimenin bir anlamı ve o anlamın olabilecek ilişkileridir.
- Kullanım alanları: metin analizi, makine çevirisi, anlam belirsizliğini giderme.

### 17.1 Sözlükten farkı

Sözlükte yalnızca kelimeler, anlamları ve onlarla kurulmuş cümleler vardır. WordNet'te ise isimler, fiiller ve sıfat-zarflar için ayrı ağlar vardır. Yapı hiyerarşiktir. İngilizce WordNet yaklaşık 117 bin synset üzerinde kurulmuştur.

### 17.2 Üst kavram ve alt kavram

> **Hocanın vurgusu:** WordNet'te en sık kullanılan ilişkiler üst kavram (hypernym) ve alt kavram (hyponym) ilişkileridir.

Hoca üniversite hiyerarşisini örnek verdi: Rektörlük, fakülte, bölüm. Fakültenin üst kavramı rektörlük, bölümün üst kavramı fakültedir. Rektörlüğün alt kavramları ise fakülte ve bölümdür.

Canlılar için çizdiği hiyerarşi şöyledir:

```text
canlı
  hayvan
    memeli
      koyun
        karaman, merinos ...
      inek
      balina
      kedi
    memeli olmayan
  insan
  bitki
```

"Hayvan", "canlı" teriminin altında listelenir. Kendi altında "kedi" vardır. "Kedi", "hayvan" kelimesinin hyponym'idir. "Canlı", "hayvan" kelimesinin hypernym'idir.

WordNet bir kelimenin üst kavramlarını, alt kavramlarını, eş anlamlılarını, zıt anlamlılarını ve parça-bütün ilişkilerini birlikte tutar.

Mobilya örneği de benzerdir: Furniture (mobilya) altında bed (yatak), onun altında bunk bed (ranza) gibi daha özel kavramlar vardır. Yatak da çocuk yatağı, hasta yatağı gibi ayrılabilir. Hasta yatakları da hareket edebilen ve edemeyen diye ayrılabilir. Buradan mobilyanın ranza ve yatak içerdiği anlaşılır.

> **Ders sonrası not:** Hoca hiyerarşiyi önce doğru anlattı, sonra "fakültenin hypernym'i bölümdür" dedi. Doğrusu: bölüm, fakültenin hyponym'idir. Ayrıca rektörlük-fakülte-bölüm ilişkisi WordNet açısından aslında parça-bütün (meronymy) ilişkisine daha yakındır.

## 18. Türkçe WordNet Çalışmaları

- **KeNet:** En büyük Türkçe çalışmalardan biridir. Işık Üniversitesi'nde bir hoca ve ekibinin kurduğu Starlang Yazılım tarafından geliştirilmiştir. Hoca, o araştırmacının şu an Özyeğin Üniversitesi'nde olduğunu söyledi. Açık kaynak kodlu ve ücretsizdir. Yaklaşık 80 bin synset içerir. Yavaş yavaş geliştirilmektedir.
- **BalkaNet:** Sabancı Üniversitesi'nin yürüttüğü bir projeydi. Hocaya göre şu an erişim yok gibi görünüyor ve proje durmuş olabilir. Önceden indirmiş olanlar çalışmalarında kullanıyor olabilir.

## 19. WordNet'teki Kelime İlişkileri

Hoca bir doğal dil işleme kitabına dayandığını, bazı kavramların tam öz Türkçeye çevrilmiş olduğunu, pek öyle kullanılmasa da bilinmesinin iyi olacağını söyledi. Sonuç, neden, alt olay gibi ilişkiler de vardır, ama daha özeldir ve her kelimede olmaz. Derste en sık rastlananlar anlatıldı.

### 19.1 Alt kavram (hyponymy)

Sözcükler aynı cins ve türden olma açısından benzerlik taşır. "Kuş", "hayvan" ve "canlı" üst kavramlarının alt kavramıdır. "Bülbül", "serçe", "güvercin" ve "çalıkuşu" da "kuş" kelimesinin alt kavramlarıdır.

### 19.2 Parça-bütün (meronymy) ve bütün-parça (holonymy)

Egzoz, motor, dişli, direksiyon, cam, benzin deposu, radyatör: Bunların hepsi arabanın parçasıdır. WordNet parçaları verince bütünün araba olduğunu, arabayı verince parçalarını söyler.

Üye-bütün ilişkisi de vardır. Profesör ve doçent, fakültede bir kadrodur. Bu ilişki de iki yönde sorgulanabilir.

### 19.3 Eş anlamlılık (synonymy)

Yazılışı ve okunuşu farklı, kavramsal içeriği ve anlamsal özellikleri aynı iki sözcüktür. Örnek: "yürek" ve "kalp", "ak" ve "beyaz". WordNet'e "ak" kelimesinin eş anlamlısı sorulunca "beyaz" verir.

**Eş dizimlilik (collocation)** eş anlamlı sözcüklerin birbirinin yerine kullanılmasını engeller:

- "Anamın ak sütünü emdim" denir, "anamın beyaz sütünü emdim" denmez.
- "Kalpsiz adam" denir, "yüreksiz adam" aynı anlamda kullanılmaz.
- "Beyaz tenli" denir, "ak tenli" denmez. "Alnım ak" denir, "alnım beyaz" denmez.

Hoca bunların ileride collocation başlığıyla görüleceğini, collocation'da bir kelimenin yerine başkasının konulamayacağını söyledi. Gerçek eş anlamlılık çok azdır.

**Eş anlamlılığın dereceleri:**

- **Tam eş anlamlılık:** "üzüntü", "elem", "keder", "dert". Rahatça birbirinin yerine kullanılır.
- **Önermesel eş anlamlılık:** Bazen uyar, bazen uymaz. "Ali kaplumbağayı gördü" ile "Ali tosbağayı gördü" aynıdır. Ama teknik bir yazıda ("araştırmacılar kaplumbağaları incelerken") "kaplumbağa" kullanılması önerilir.
- **Yarı eş anlamlılık:** Tamamen aynı değildir. "Sebebiyle" yerine "nedeniyle" koymadan önce düşünmek gerekir. Bazı cümlelerde uyar, bazılarında uymaz.

**Eş anlamlılığı etkileyen diğer durumlar:**

- Farklı lehçe ve ağızlar: Hocanın örneğinde Trakya'da "ayçiçeği", Ege'de belki "günebakan".
- Olumsuz çağrışım: "adam" yerine "herif" daha argo ve olumsuzdur.
- Duygusal yük: "Devlet adamı" oturaklı ve ehil birini çağrıştırır. "Politikacı" ise bugün ayrı yarın ayrı konuşan birini çağrıştırır.
- Belirli bağlamlar.

Hoca bunların WordNet ile pek ilgisi olmadığını söyledi. WordNet yalnızca tam eş anlamlılık varsa bu bilgiyi verir.

### 19.4 Zıt anlamlılık (antonymy)

İki sözcüğün birbirine karşıt olmasıdır: "kısa-uzun", "güzel-çirkin". Türleri şöyledir:

- **Derecelendirilebilen:** "uzun-kısa", "genç-yaşlı". Bir ayıraç noktası vardır. Hocanın örneği: 1,50 metrenin altı kısa, üstü uzun; 40 yaşın altı genç, üstü yaşlı. Bu eşik kişiden kişiye değişir. Olumsuz ek karşıtlığı vermez: "kısa değil" demek "uzun" demek değildir.
- **Derecelendirilemeyen:** "ölü-canlı", "evli-bekâr". "Yüzde 70 yaşıyor, yüzde 30 öldü" denemez. Olumsuz ek karşıtlığı bozmaz: Ölü değilse canlıdır, bekâr değilse evlidir.
- **Ters (yönsel):** "sağ-sol", "itmek-çekmek".
- **Bakışımlı:** Kişiden kişiye değişir. "Doktor-hasta": Ben "doktorum Ayşe Hanım" derim, o da "hastam Banu Hanım" der. "Ahmet Ali'ye borç verdi" ile "Ali Ahmet'ten borç aldı" aynı olayı farklı bakış açılarından anlatır. İlki Ahmet'in iyiliğini, ikincisi Ali'nin zor durumda olduğunu çağrıştırır.

### 19.5 Eş seslilik

Hocanın kullandığı terim homofonidir. Yazılışları ve okunuşları aynı, anlamları farklı kelimelerdir. Örnek: "yüz". WordNet hangi anlamın hangi türde olduğunu da verir. Fiil anlamları fiil ağında, isim anlamları isim ağında yer alır.

> **Ders sonrası not:** Yazılışı ve okunuşu aynı, anlamı farklı kelimeler için kullanılan terim homonimi (homonymy) sözcüğüdür. Homofoni (homophony) yalnız okunuşun aynı olmasını anlatır. İngilizcedeki "write" ile "right" buna örnektir.

### 19.6 Çok anlamlılık (polysemy)

Bir kelimenin temel anlamını genişleterek yeni kavramlar anlatmasıdır.

- "Yüz" (insan yüzü, dıştan görünen taraf) kelimesinden "yorgan yüzü" türetilmiştir.
- "Baş" temelde vücudun üst bölümündeki organdır. Bundan türeyen anlamlar:
  - Topluluğu yöneten kişi: "devletin başı".
  - Başlangıç: "satır başı".
  - Temel: "Her şeyin başı sağlıktır."
  - En yüksek nokta: "yokuşun başı".
  - Tane: "üç baş soğan".
- "Burun" yüzdeki organdır. Coğrafyada denize doğru çıkıntı yapan kara parçasına da burun denir. Yüzdeki organa benzetilerek türetilmiştir.

### 19.7 Metafor (eğretileme)

Bir kavramı başka bir kavram üzerinden anlatmaktır.

"Borç içinde yüzmek" ifadesinde borç denize benzetilir, borcun miktarı denizin derinliğine. Deniz ne kadar derinse borç o kadar fazladır.

Öfkeyle ilgili örnekler: "kan beynine sıçramak", "içinde öfke biriktirmek", "öfke kusmak", "burnundan ateşler saçmak", "tepesinin tası atmak", "öfkeyle donmak".

Türkçeyi sonradan öğrenen biri bunları ancak toplum içinde yaşayarak anlar. Kelime kelime İngilizceye çevrilemez.

> **Hocanın vurgusu:** Dildeki en zor çözümlenen şeylerden biri metaforlardır.

## 20. WordNet'in Sayıları ve İlişkilerin Sözcük Türüne Göre Dağılımı

Hoca İngilizce için sayılar verdi, çünkü kaynaklarda genelde İngilizce bulunuyor:

- İsimler (noun): 117.097 kelime, toplam 145.104 anlam. Yani bazı isimlerin birden fazla anlamı vardır.
- Fiiller (verb): 11.488 kelime, 24 binin üzerinde anlam.
- Sıfat ve zarflar için de ayrı ağ vardır. Sayıları tabloda verildi.

<!-- BELİRSİZ: Sıfat ve zarf sayıları slaytta. Altyazıda okunmuyor. -->

Her ilişki her türde yoktur:

| Tür | İlişki | Örnek |
|---|---|---|
| İsim | Hypernym (üst kavram) | breakfast → meal |
| İsim | Hyponym (alt kavram) | meal → lunch, breakfast, dinner |
| İsim | Has-member / Member-of | crew (ekip) ↔ copilot |
| İsim | Has-part / Part-of | table → leg (masa ayağı), drawer (çekmece) |
| İsim | Antonym | leader ↔ follower |
| Fiil | Troponym | walk → uygun adım yürümek, sekerek yürümek, koşar adım yürümek |
| Fiil | Entails | snore (horlamak) → sleep (uyumak) |
| Sıfat, zarf | Antonym | yalnızca zıtlık ilişkisi |

Fiillerde iki farklı ilişki görülür. Troponym, bir eylemin nasıl yapıldığını gösteren çeşitlerini verir: Yürümenin uygun adım, sekerek, hızlı adımlarla yapılması gibi. Entail için hocanın örneği uykudur: Kabus görerek, horlayarak, konuşarak uyumak.

> **Ders sonrası not:** Hoca entailment ilişkisini troponym'in "tam tersi" olarak anlattı. WordNet'te entailment, bir eylemin başka bir eylemi gerektirmesidir: Horlamak uyumayı gerektirir. Bir eylemin çeşidini vermek ise troponym ilişkisidir. Hocanın "Hypername tam tersi olabilir. Meal'ın altları..." cümlesinde kastı hyponym ilişkisidir.

## 21. WordNet Üzerinden Anlamsal Benzerlik Ölçütleri

Amaç, insanın su ile bardak için deneyimiyle verdiği puanı bilgisayara verdirmektir. İki yaklaşım vardır:

- **Bağ sayma (edge counting):** Ağ bir ağaç gibi düşünülür. Bir kelimeden diğerine giderken kaç bağdan geçildiği sayılır. Taksonomi derinliği de kullanılır. Taksonomi derinliği, en üstteki kökten en alttaki yaprağa kadar olan mesafedir. Hocanın çiziminde bu 8'dir.
- **Bilgi içeriği (information content):** Taksonomi bilgisinin yanında derlem de kullanılır. Örneğin kelimenin derlemdeki olasılığı alınır.

Hoca çok sayıda ölçüt olduğunu, bazılarını anlatacağını söyledi.

### 21.1 Leacock & Chodorow (1998)

$$sim_{LC}(c_1, c_2) = -\log \frac{len(c_1, c_2)}{2L}$$

- $len(c_1, c_2)$: İki synset arasındaki en kısa yolun uzunluğu.
- $L$: Bütün taksonominin derinliği.

Ağaçta iki düğüm arasında tek yol vardır. Ama WordNet bir graf yapısıdır, bu yüzden birden fazla yol olabilir ve en kısa olanı alınır. Logaritması alınınca benzerliği veren sayısal bir değer çıkar.

### 21.2 Wu & Palmer (1994)

$$sim_{WP}(c_1, c_2) = \frac{2 \times N_3}{N_1 + N_2 + 2 \times N_3}$$

- $N_1$, $N_2$: $c_1$ ve $c_2$ synset'lerinin en yakın ortak üst synset'e olan uzaklıkları.
- $N_3$: En yakın ortak üst synset'in köke uzaklığı.

Hoca iki örnek çizdi:

**Örnek 1.** $c_1$ ve $c_2$ aynı ebeveynin çocuklarıdır. Ebeveyn de kökün bir altındadır.

- $N_1 = 1$, $N_2 = 1$, $N_3 = 1$.
- $sim = \dfrac{2 \times 1}{1 + 1 + 2 \times 1} = \dfrac{2}{4} = 0{,}5$ (hesap eklendi).

**Örnek 2.** En yakın ortak üst synset kökün kendisidir.

- $N_1 = 2$, $N_2 = 1$, $N_3 = 0$.
- $sim = \dfrac{0}{2 + 1 + 0} = 0$ (hesap eklendi).

Ortak üst synset köke ne kadar uzaksa, yani ne kadar özelse benzerlik o kadar yüksek çıkar.

### 21.3 Jiang-Conrath ve Lin

Slayttaki formüller şöyledir:

$$sim_{JC}(c_1, c_2) = 2\log(p(lcs(c_1, c_2))) - (\log(p(c_1)) + \log(p(c_2)))$$

$$sim_{L}(c_1, c_2) = \frac{2 \log(p(lcs(c_1, c_2)))}{\log(p(c_1)) + \log(p(c_2))}$$

$lcs(c_1, c_2)$ fonksiyonu en yakın ortak üst synset'i bulur (least common subsumer). Hoca iki formülün aynı parçaları kullandığını söyledi. Birincisi A ve B kısımlarının farkını, ikincisi A'nın B'ye oranını alır. A kısmı $2\log p(lcs)$, B kısmı $\log p(c_1) + \log p(c_2)$ değeridir.

> **Ders sonrası not:** Slaytta $sim_{JC}$ diye yazılan ifade aslında bir uzaklıktır. İki kavram aynıysa değer 0 çıkar, kavramlar uzaklaştıkça artar. Python ile denendi: $p(c_1)=p(c_2)=p(lcs)=0{,}1$ için sonuç 0, $p(c_1)=0{,}001$, $p(c_2)=0{,}002$, $p(lcs)=0{,}5$ için yaklaşık 11,7. Benzerlik olarak genellikle bu değerin tersi alınır. Lin ölçütü ise 0 ile 1 arasındadır ve doğrudan benzerliktir: Aynı örneklerde 1 ve yaklaşık 0,11.

### 21.4 Ölçütlerin karşılaştırılması

Hoca bir karşılaştırma çalışması anlattı. 38 kelime çifti belirlenmiş (balon-çocuk, deniz-mayo, yağmur-şemsiye, bıyık-ayna gibi). Sokaktaki insanlardan bu çiftlere 1 ile 10 arasında puan vermeleri istenmiş. Sonra aynı çiftler ölçütlere verilmiş. Ölçüt sonuçları ile insan puanları arasındaki korelasyon ölçülmüş.

| Yöntem | Tür | Korelasyon |
|---|---|---|
| Wu & Palmer 1994 | Edge Counting | 0,74 |
| Li 2003 | Edge Counting | 0,82 |
| Leacock & Chodorow 1998 | Edge Counting | 0,82 |
| Resnik 1999 | Info. Content | 0,79 |
| Lin 1998 | Info. Content | 0,82 |
| Lord 2003 | Info. Content | 0,79 |
| Jiang & Conrath 1998 | Info. Content | 0,83 |
| Tversky 1977 | Feature Based | 0,73 |
| Adapted Lesk 2002 | Feature Based | 0,37 |
| Rodriguez 2003 | Hybrid | 0,71 |

Bazı ölçütler yalnız kenar sayar, bazıları bilgi içeriğini kullanır, bazıları özellik çıkarır, melez olanlar bunları karıştırır. Li, Leacock & Chodorow, Lin ve Jiang & Conrath 0,80'in üzerindedir.

> **Ders sonrası not:** Hoca korelasyon tablosunu "100 çiftin 80'ine yakınında bilgisayar ile insan aynı benzerliği vermiş" diye yorumladı. 0,82 bir korelasyon katsayısıdır, doğru tahmin edilen çiftlerin oranı değildir. Yöntemin puanlarının insan puanlarıyla güçlü biçimde birlikte değiştiğini gösterir.

### 21.5 Uygulama

Bu ölçütlerle WordNet üzerinden anlamsal bilgi çıkarılabilir. Hocanın örneği: "Kitap", "defter", "kalem" ve "okul" birbirine çok yakınsa aynı kümede olmalıdır. Bu kelimelerin birlikte geçtiği dokümanlar aynı konudan bahsediyor demektir. Dokümanlar bu bilgiyle sınıflandırılabilir.

## Dersin Toparlaması

Dersin ilk yarısında dil modelleri tamamlandı. Kelimeler bağımsız olmadığı için n-gram modeli kullanılır, ama pratikte $N$ genelde 2 ya da 3'tür. Zipf yasası gereği hiçbir derlem bütün ikilileri içermez. Bu yüzden seyrek matrisler kaçınılmazdır ve sıfır olasılıklar yumuşatmayla giderilir. Add-one bütün sayımlara 1 ekleyip normalize eder. Good-Turing görülmemiş olaya bir kez görülenlerin oranını verir. Back-off ise sayım bulunana kadar $N$ değerini azaltır. N-gram modeli biçimbirimsel belirsizliği gidermede de kullanılır.

Dersin ikinci yarısında kelimelere sayısal varlık olarak değil, anlamlarıyla bakıldı. Kelime anlam belirsizliği giderme için seçilmiş sözcük ve tüm sözcük yaklaşımları, Lesk gibi bilgi tabanlı yöntemler ve derlem tabanlı yöntemler anlatıldı. WordNet, kelimeler arasındaki alt-üst, parça-bütün, eş anlam ve zıt anlam gibi ilişkileri tutan bir ağdır. Bu ağ üzerinde bağ sayma ve bilgi içeriğine dayalı benzerlik ölçütleri tanımlanır. Böylece insanın deneyimle verdiği benzerlik puanı bilgisayara hesaplatılabilir.

## Altyazı Terim Düzeltmeleri

Altyazıda bozuk geçen terimlerin doğru yazımları:

- "Advanced smoothing", "Erdogan smoothing": add-one smoothing.
- "Good touring": Good-Turing. "Beckhoff": back-off.
- "Zif kanunu", "zil kanunu": Zipf yasası. "Nayibahirisi": Naive Bayes.
- "LESC", "lex": Lesk. "Polise": polysemy. "Halponim": altyazıda eş anlamlılık tanımında geçiyor, doğrusu synonym.
- "KeyNet": KeNet. "Starlink yazılım": Starlang Yazılım. "Balkanet": BalkaNet.
- "Lee Kock ve Shadorov": Leacock & Chodorow. "Hu Palmer": Wu & Palmer. "Jean-Condrat": Jiang-Conrath. "li": Lin.
- "Motion information": altyazıda bilgi içeriği yaklaşımı için geçiyor. "Mutual information" anlamına gelir, ama slayttaki yöntem türü "Info. Content" olarak yazılıdır.
- Altyazıda çok anlamlılık başlığında "eş anlamlılık" geçiyor. Polysemy'nin Türkçesi çok anlamlılıktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
