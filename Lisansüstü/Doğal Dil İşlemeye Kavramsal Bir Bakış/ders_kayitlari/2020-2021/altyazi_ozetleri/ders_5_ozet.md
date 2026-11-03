# Ders 5 Çalışma Özeti

## Genel Konular

- Morfolojik analizin kısa tekrarı ve sentaktik analize (söz dizimsel analiz, syntactic analysis) geçiş.
- Kelime türleri, durak kelimeler (stop words) ve sözcük türü etiketleri (part of speech, POS).
- Penn Treebank ve Brown etiket kümeleri, Türk dilleri için etiket kümesi.
- Türkçe ile İngilizcenin söz dizimi farkları: serbest sıralı söz dizimi (free word order).
- Bağlamdan bağımsız dilbilgisi (context-free grammar, CFG) ve ağaç derlemi (treebank).
- Kural tabanlı ve olasılık tabanlı çözümleme, yukarıdan aşağı ve aşağıdan yukarı ayrıştırma (parsing).
- Bağlılık ayrıştırması (dependency parsing).
- Türkçede tümce türleri ve cümleyi öğelerine ayırma.
- Genişletilmiş geçiş ağları (Augmented Transition Network, ATN).
- Dil modellerine giriş: lemma ve kök farkı, kullanım alanları, Shannon oyunu, n-gram fikri.
- Harf dizilerinde sıfırıncı, birinci, ikinci ve üçüncü derece yaklaşımlar.
- Romance dillerinde hece örtüşmesi ve Zipf yasası.
- Cümle olasılığının hesaplanması ve n-gram modeli.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu dersin konsepti hazır araçları kullanmaktır. Morfolojik analizciyi öğrenciler yazmayacak.
- Morfolojik analiz bir kelimeye birden fazla çözüm verebilir. Hangisinin doğru olduğu bağlamdan (context) anlaşılır. Bu belirsizlik (ambiguity) sentaktik analizde çözülür.
- Tümce ile cümle, sözcük ile kelime aynı anlamdadır.
- Sık geçen bir kelime önemli demek değildir. "of" ve "in" çok sık geçer ama ayırt edici değildir.
- Stop words çoğu uygulamada atılır. Yazar tanıma (authorship) çalışmasında ise ayırt edici olabilir.
- Türkçe serbest sıralıdır. Aynı cümlenin birçok dizilişi vardır. Bu yüzden Türkçenin sentaktik çözümlemesi İngilizceden zordur.
- Kökü almak olumsuzluk ekini siler. Duygu analizinde (sentiment analysis) bu ciddi hata doğurur.
- Bağlılık ayrıştırması cümlenin öğelerini ve kelimeler arası ilişkileri verir. Hocaya göre bu çok önemlidir.
- Olasılık tabanlı çözümlemede önce en olası ağaç ya da yol denenir. Böylece çözümleme hızlanır.
- Lemma ile kök aynı şey değildir. Sözlükte bulunan kelimenin daha fazla köküne inilmez.
- Pratikte n değeri genellikle 2 ya da 3 alınır. Akademik çalışmalarda en fazla 4-5 görülür.
- Final sınavı yok. Final saatinde proje demosu yapılacak ve rapor teslim edilecek.

## Kısa Tekrar Notları

- Sentaktik analizin amaçları:
  - Anlamsal analize (semantic analysis) girdi sağlamak.
  - Kelimelerdeki belirsizlikleri çözmek.
  - Cümlenin o dile ait olup olmadığına karar vermek.
  - Cümleyi öğelerine ayırmak.
- Kelime türleri: isim (noun), belirleyici (determiner), sıfat (adjective), fiil (verb), zarf ya da belirteç (adverb), edat ya da ilgeç (preposition), bağlaç (conjunction).
- Stop words: tek başına anlam taşımayan, cümle içinde anlama katkı veren kelimeler. Türkçesi durak kelimeler ya da fonksiyonel kelimelerdir.
- POS: bir dokümanda anlamı olan en küçük birim kelimedir. Her kelimeye bir etiket atanır.
- Ağaç derlemi: bir dilin cümle yapılarını gösteren ağaçların toplandığı derlem.
- CFG: her cümleye karşılık gelen bir ağaç olmalıdır.
- Kural tabanlı çözümleme: ağaçlar sırayla denenir. Olasılık tabanlı çözümleme: en olası ağaçtan başlanır.
- ATN: durumlar (state) ve geçişlerle gösterilen ağaç derlemi. Ağaçtan farkı yalnızca gösterimdir.
- Dil modeli: bir dildeki kelime dizilerinin olasılık dağılımı. Buna istatistiksel dil modeli denir.
- Karakter n-gram: harfi önceki harflere göre tahmin eder. Kelime n-gram: kelimeyi önceki kelimelere göre tahmin eder.
- Zipf yasası: kelimelerin sıklığı, sıralarıyla ters orantılıdır.
- Bigram ile cümle olasılığı: $P(S) = P(w_1) \times P(w_2|w_1) \times \dots \times P(w_n|w_{n-1})$.

## Detaylı Açıklamalar

### Ders başı duyuruları

- Ödevler drive'a konuyor. Hoca bu gün ödevlere bakamayacağını söyledi. Yetiştiremeyenlere Cuma'ya kadar süre verdi.
- Seminer için makale seçilecek. Makale, öğrencinin proje konusuna yardımcı olacak bir konuda olmalı.
- Hoca proje konularına bakıp uygun makaleleri ödevlerin konduğu drive'a koyacak.
- Hocanın koyduğu makaleler uymuyorsa öğrenci kendi bulduğu makaleyi hocaya önerebilir. Hoca çok ağır makale seçilmesini istemiyor.
- Hoca, makaleleri koymayı unutursa bir öğrenciden kendisine hatırlatma maili atmasını istedi.
- Konu seçmeyen öğrencilerin proje konusunu seçmesi istendi.

### Morfolojik analizin tekrarı

- Biçim bilimsel analiz (morphological analysis) metni token'lara, yani kelimelere ayırır.
- Sonra kelimeyi kök ve eklerine ayırır ve eklerin türünü verir.
- Bu çıktı sentaktik analizin girdisidir. Sentaktik analiz için kelimelerin etiketlenmiş olması gerekir.
- Örnek belirsizlik: "gül" hem isim hem fiil olabilir. Doğru çözüm, cümle ağaç derlemindeki bir ağaca oturunca anlaşılır.

### Söz dizimsel analiz

- Tanım: söz dizimini oluşturan morfolojik öğeleri, hiyerarşik kurallara uyumlarına göre çözümlemek.
- Hiyerarşik kurallar, dil ve gramer konusundaki Chomsky hiyerarşisinden gelir.
  - Başlangıç sembolü $S$ vardır.
  - Türetme kuralları $P$ dilin cümle yapılarıdır.
  - Çözümleme sonunda her şey uç değişkenlere ($V_T$) iner.
- Önceki derslerde kurallarda soyut $A$, $B$ sembolleri kullanıldı. Gerçek dünyada bunların yerine nesne, tümleç, ön ad gibi dilbilgisi öğeleri ya da POS etiketleri gelir.
- Bilgisayar, morfolojik analizden geçmiş rastgele kelimeleri de "cümle" sanabilir. Bu yüzden ona dilin söz dizimi yapısı verilmelidir. Burada otomatlar ve ağaç yapıları kullanılabilir.

### Kelime türleri ve stop words

- İngilizcede belirleyiciler vardır: "the", "a", "an". Türkçede belirleyici yoktur. "Bir kitap" ifadesindeki "bir" belirleyici gibi düşünülebilir.
- Sınıflandırma, kümeleme ya da cümle vektörü çıkarmada her kelimeyi kullanmak maliyetlidir. Bazı kelimelerin ayırt ediciliği yoktur.
- İngilizce bir derlemde (corpus) sıklıklar çok yüksektir. Örneğin "of" yaklaşık 540 bin, "in" yaklaşık 331 bin kez geçer.
- Zamirler ("it", "I", "he", "you"), bağlaçlar ("and", "that", "but") ve yardımcı fiiller de çok sık geçer.
- Hocayı şaşırtan nokta: "can", "may", "will", "should" gibi kip fiilleri (modal), "have", "do", "is" gibi yardımcı fiillerden daha sık listelenmiş.
- "have" listede soru işaretiyle verilmiş. Çünkü hem yardımcı fiil hem asıl fiil olabilir.
  - Çözüm önerisi: bir zamirden ya da özneden sonra geliyorsa yardımcı fiil kabul edilebilir.
  - Yalnızca terim frekansı (TF) sayılırsa ve bu kontrol yapılmazsa önemli bilgi kaçabilir.
- Metin madenciliğinde (text mining) bu kelimeler ön işlemede (preprocessing) atılır.

### Diller arası söz dizimi farkı

- Slaytta "O kalemini tek silahı olarak görür" anlamında bir cümle Türkçe, Japonca, Korece, Fince, Çince ve İngilizce olarak verildi.
- Türkçe, Japonca ve Korecede fiil sondadır. Hoca bu dilleri Ural-Altay ailesi olarak anlattı. Hepsi sondan eklemelidir.
- Fince, Çince ve İngilizcede fiil ortadadır.
- Aynı ailedeki diller arasında:
  - Bir dilin sentaktik analiz kodu küçük değişikliklerle diğerine uyarlanabilir.
  - Makine çevirisi (derin öğrenme öncesinde) daha başarılıdır. İngilizceden Almancaya çeviri, İngilizceden Türkçeye çeviriden bu yüzden daha başarılıdır.
- Türkçede kural: özne, nesne, tümleç, yüklem. Yüklem başa gelirse buna devrik cümle denir.

### POS etiket kümeleri

- Etiketler keyfi atanmaz. İngilizce için Penn Treebank ve Brown etiket kümeleri kullanılır.
- Türkçe çalışmalarda da bu kümeler kullanılır. Ancak İngilizcede olup Türkçede olmayan etiketler vardır (ve tersi). Bu yüzden eksiklikler oluşur.
- Morfolojik analizde hangi aracı kullanırsanız kullanın (örneğin Porter stemmer), etiketler bu kümelere benzer biçimde verilir.
- Hocaya göre etiketlerin hepsini ezberlemek gerekmez. Baktıkça göz alışır. Takılınca tabloya bakılır.

| Etiket | Anlamı |
|---|---|
| CC | Sıralama bağlacı (coordinating conjunction) |
| JJ | Sıfat (adjective) |
| JJR | Sıfatın karşılaştırma hâli (comparative) |
| JJS | Sıfatın üstünlük hâli (superlative) |
| MD | Kip fiili (modal) |
| NN | Tekil isim |
| NNS | Çoğul isim |
| NNP | Tekil özel isim |
| NNPS | Çoğul özel isim |
| POS | İyelik eki ('s) |
| VB | Fiil, yalın hâl |
| VBD | Fiil, geçmiş zaman (past tense) |
| VBG | Fiil, -ing hâli |
| VBN | Fiil, üçüncü hâl (past participle) |
| VBZ | Fiil, üçüncü tekil şahıs, geniş zaman |

- Zamirler için de etiket vardır. Hoca bunu "PP" olarak gösterdi. "Benimki, seninki" gibi sahiplik bildiren zamirlere ek bir işaret konur.
- Noktalama gibi özel işaretler için de etiketler vardır.
- CFG kurallarında artık $A$, $B$ yerine bu etiketler yazılır. Örneğin bir cümle kuralı NN ve onu izleyen bir etiketten oluşabilir.
- Türk dilleri için ayrı bir etiket kümesi geliştirilmiştir. Slaytta Türkçe, Tatarca, Başkurtça, Kazakça gibi diller için sütunlar vardır.
  - Örneğin yönelme eki (dative) için etiket vardır. İngilizcede böyle ekler yoktur.
  - Sayılar, kişiler, zamanlar ve soru ekleri için de etiketler vardır.
  - Hocanın gözlemi: Türkçe çalışmalarda bile çoğunlukla İngilizce etiketler kullanılıyor. Eksik etiket olursa araştırmacı kendi etiketini ekliyor.

### Türkçe ile İngilizcenin farkları

- İngilizcede tanımlık ("the", "a", "an") vardır. Türkçede yoktur.
- İngilizcede ön edatlar (preposition: "of", "in", "by") vardır. Türkçede bu iş eklerle ve son edatlarla yapılır.
- İngilizcede sıfat derecelendirmesi ekle yapılır ("-er", "-est"). Türkçede ayrı kelime eklenir: "büyük top", "çok büyük top", "daha büyük top", "kocaman top". Zarflarda da durum aynıdır.
- İngilizcede "up", "off" gibi fiil parçacıkları vardır. Türkçede yoktur.
- Türkçe fiiller kurallıdır ama içinde hem kişi hem zaman bilgisi taşır. Örneğin "okuyor" kelimesinde "o" kişisi ve zaman bilgisi vardır. Bu yüzden Türkçe fiili çözümlemek İngilizceden çok daha zordur.
- Türkçe eklemeli bir dildir. Yapım eki çok fazladır. Bir kökten çok farklı kelimeler türetilebilir.
- Türkçe serbest sıralı söz dizimine sahiptir. Kelimelerin yeri değişse de anlam bozulmaz:
  - "Ben kıza çiçek verdim."
  - "Kıza çiçeği ben verdim."
  - "Ben çiçeği kıza verdim."
  - "Çiçeği kıza ben verdim."
  - "Kıza ben verdim çiçeği."
- Bu yüzden aynı cümle için birçok ağaç gerekir.
- İngilizcede sıra çok kısıtlıdır. "She saw him" cümlesi "the tall woman", "the fat man with red beard" gibi genişletilebilir ama kelimelerin yeri değiştirilemez.
- Türkçede de yer değiştirmenin anlamı değiştirdiği durumlar vardır:
  - "Sınavı zor yetiştirdim": "zor" fiili niteler, zarftır. Süre yetmemiştir.
  - "Zor sınavı yetiştirdim": "zor" ismi niteler, sıfattır. Sorular zordur.

### Sentaktik analizin problemleri

- Bir kelime birden fazla sınıfa girebilir. İngilizcede "this":
  - "This is a nice day.": zamir.
  - "This day is nice.": belirleyici.
  - "You can go this far.": zarf.
- Türkçede de durum aynıdır. Basit bir kural: kelime ismin önündeyse sıfat, fiilin önündeyse zarftır.
- Sözcük öbekleri farklı kalıplarda olabilir: ad (isim) tamlaması, ön ad (sıfat) tamlaması, eylem tümcesi, ad tümcesi.
- Slayttaki istatistiğe göre dünya dillerinde özne-nesne-yüklem dizilişi yaklaşık %46 oranındadır.
- Tümceler anlamlarına göre olumlu, olumsuz, bildirme, soru, emir, istek ve ünlem tümceleri olabilir.
- Olumsuzluk eki örneği:
  - "Öğretmen bana şunu yapmamamı söyledi."
  - Köke indirgenince "yapmamamı" kelimesi "yap" olur. Olumsuzluk eki kaybolur.
  - Sözlük (lexicon) tabanlı duygu analizinde cümle bu yüzden yanlış sınıflanır.
  - Çözüm: morfolojik analizde olumsuzluk eki ("-ma", "-me") görülürse kelime yalnızca kök olarak alınmamalı.

### Çözümleme yaklaşımları

- En klasik yöntem bağlamdan bağımsız dilbilgisidir (CFG). Kural tabanlıdır.
- Slaytta diğer dilbilgisi modelleri de geçti: sözcüksel işlevsel dilbilgisi (Lexical Functional Grammar), ulamsal dilbilgisi (Categorial Grammar), başsözcüğe dayalı öbek yapısal dilbilgisi (Head-driven Phrase Structure Grammar), bağlılık dilbilgisi (Dependency Grammar). Hoca CFG'yi referans alarak ilerledi.
- Chomsky hiyerarşisinin tekrarı:
  - Tür 0: kısıtsızdır. Kuralların iki tarafına istenen sayıda sembol yazılabilir. Turing makinesiyle gerçekleştirilenler buradadır.
  - Tür 1: sol taraftaki sembol sayısı sağ taraftakinden küçük ya da ona eşittir.
  - Tür 2: bağlamdan bağımsız dilbilgisidir.
  - Tür 3: düzenli dillerdir.
- CFG, bir cümle ile o cümlenin söz dizimini gösteren ağaç arasındaki ilişkiyi belirler. Her cümle, ağaç derlemindeki bir ağaca oturmalıdır.

### Olasılık tabanlı çözümleme

- Bir cümle yapısını derlemdeki birden fazla ağaç çözebilir. Her ağacın bir olasılığı vardır.
- Örnek: özne-nesne-yüklem yapısındaki bir cümleyi $T_1$ ağacı %40, $T_{15}$ ağacı %60 olasılıkla çözüyor.
- Önce en olası ağaç denenir. Cümle oturursa hem çözümleme bitmiştir hem de cümle o dile aittir.
- Oturmazsa sonraki ağaca geçilir.
- Örnek: "Sınavı zor yetiştirdim" ve "Zor sınavı yetiştirdim". "zor" sıfatsa bir ağaç, zarfsa başka bir ağaç cümleyi çözer.
- Hiçbir ağaç çözemezse kelimelerde yazım hatası olabilir. İki seçenek vardır:
  - Ön işlemede hatalı kelimeleri düzeltmek. Bu da bir maliyettir.
  - Cümleyi "çözümlenemedi" diye ayırmak, sonra bakıp düzeltmek ve yeniden ağaca vermek.

### Bağlılık ayrıştırması (dependency parsing)

- Sentaktik analizin en önemli parçalarından biridir.
- İngilizce için açık kaynak araçlar vardır. Python kütüphanelerinde bulunur.
- Türkçe için akademik çalışmalar vardır ama kullanılan Zemberek'te yoktur.
  - Bu araçlar genelde açık kaynak sunulmuyor. Akademik kullanım için imzalı izin formu dolduruluyor (ticari kullanmayacağım diye).
  - Teknik Üniversite'den Gülşen Hoca'nın doktora tezi Türkçe çözümleme üzerinedir. Bir pipeline oluşturup öğrencilere web üzerinden açmıştır. Ancak cümleyi gönderip sonucu beklemek zaman kaybı olduğu için pek tercih edilmez.
- Örnek cümle: "Bu okuldaki öğrencilerin en akıllısı şurada duran küçük kızdır."
  - Morfolojik analiz her kelimenin kökünü, ekini ve etiketini verir. Örneğin "okul-da-ki": bulunma hâli ("-da"), ardından "-ki" eki kelimeyi sıfat yapar.
  - Sentaktik analiz cümleyi derlemdeki bir ağaca oturtur. Bütün kelimeler yapraklara yerleşir.
  - Bağlılık ayrıştırması dile ait kurallarla kelimeleri birbirine bağlar:
    - "-ki" eki önündeki ismi niteler.
    - Sıfat önündeki ismi niteler: "küçük" kelimesi "kız" kelimesini niteler.
    - "duran" kelimesindeki "-an" eki "kız" kelimesini niteler.
    - "kızdır" kelimesi "kızmak" fiili de olabilir. Ancak önünde sıfat olduğu için isimdir. Bu yüzden yüklem "kızdır" olur.
  - Bu ilişkiler bilinirse 5N1K soruları cevaplanabilir: "Öğrencilerin en akıllısı kimdir?", "Nerede duruyor?", "Neredeki öğrencilerin en akıllısı?".
- Cümlenin öğeleri (özne, nesne, tümleç, yüklem, zarf tümleci) bağlılık ayrıştırmasından elde edilir.

### Türkçede tümce türleri

- Gösterim: $TT$ temel tümce, $YT$ yan tümcedir. Bir cümle yalnızca temel tümceden ya da birkaç yan tümce ve bir temel tümceden oluşabilir.

| Tür | Örnek | Açıklama |
|---|---|---|
| Basit tümce | Çocuk duvarı boyadı. | Özne "çocuk", nesne "duvarı", yüklem "boyadı". |
| Ortak öğesiz birleşik tümce | Çocuk duvarı boyarken adam geldi. | Özneler farklı. "Çocuk duvarı boyarken" yan cümlesi "geldi" yükleminin zarf tümlecidir. |
| Ortak öğeli birleşik tümce | Çocuk duvarı boyarken elini boyadı. | "Çocuk" iki tümcenin de ortak öznesidir. |
| Ortak özneli bağımlı sıralı tümce | Çocuk duvarı boyadı ve gitti. | İki tümce "ve" ile bağlanır. Özne ortaktır. İkinci tümcede gizli öznedir. |
| Ortak nesneli bağımlı sıralı tümce | Parayı ben kazanıyorum, eşim harcıyor. | Özneler farklı, nesne "para" ortaktır. |
| Birden fazla ortak öğeli tümce | Çocuk evde oyun oynarken televizyon izliyor. | İki tümcenin öznesi de "çocuk". |
| Sıralı (bağımsız) tümceler | Bahar geldi, çiçekler açtı. | Tümceler birbirinden bağımsızdır. |
| Girişik tümce | Atatürk "Çalışmayan insan yükselemez." diyor. | Tırnak içindeki tümce nesnedir. Çözümlemesi en zor yapıdır. |

- Hocaya göre girişik tümceler karmaşık görünse de sorun değildir. Ağaç derleminde bu yapıyı çözen bir ağaç varsa öğeler kolayca etiketlenir.
- Tümcede yüklem mutlaka vardır. Özne gizli olabilir. Örneğin "Geldim" kelimesi hem kişiyi hem zamanı taşır. Öznesi gizlidir.
- Öğeleri bulmak için hangi soruların sorulacağı ve hangi sırayla bakılacağı slaytta verildi. Kaynak, Eşref Hoca'nın kitabıdır.
  - Önce ad öbekleri aranır: tek isim mi, ön ad (örneğin "büyük kırmızı ev") var mı?
  - Çoğul eki, iyelik eki, yalın hâl kontrol edilir.
  - Sonra yüklem bulunur: çekimli eylem mi, ek eylem mi, birleşik eylem mi?

### Öğelere ayırmanın blok diyagramı

```
Metin
  -> cümlelere ve kelimelere ayırma
  -> biçim bilimsel çözümleme
  -> belirsizlik giderme ve ön işleme
  -> ad tamlamaları, ön ad tamlamaları, ilgeç öbekleri, belirteç öbekleri
  -> yüklemin belirlenmesi
  -> öğelerine ayrılmış (etiketlenmiş) metin
```

- Ön işleme örneği: "ıspanak" kelimesi Türkçe karakter kullanılmadan "ispanak" yazılmışsa morfolojik analiz çözemez. Önce Türkçe karakter düzeltmesi yapılır.
- Belirsizlik giderme: biçim bilimsel çözümleme birden fazla sonuç verdiyse hangisinin alınacağına karar verilir.

### Ağaç derlemi ve sözlükler

- Kurallardan ağaçlar oluşturulur. Örnek kurallar:

```
S  -> NP VP
S  -> Aux NP VP
S  -> VP
NP -> Det Nominal
NP -> ProperNoun
VP -> Verb NP
VP -> Verb
Nominal -> Noun
```

- Ağaçların yapraklarına sözlüklerdeki (lexicon) kelimeler gelir: isim sözlüğü, fiil sözlüğü (İngilizcede düzenli ve düzensiz fiiller ayrı), belirleyici sözlüğü, yardımcı fiil sözlüğü, özel isim sözlüğü.

### Yukarıdan aşağı ayrıştırma örneği

- Cümle: "Does this flight include a meal?"
- `S -> NP VP` ağacında `NP -> Det Nominal` açılır. "does" belirleyici sözlüğünde yok. Bu ağaç olmaz.
- `NP -> ProperNoun` denenir. "does" özel isimler sözlüğünde de yok.
- `S -> Aux NP VP` ağacına geçilir. "does" yardımcı fiil sözlüğünde var. Yerleşir.
- "this" belirleyici, "flight" isim, "include" fiil, "a" belirleyici, "meal" isimdir. Hepsi yerleşir.
- Cümle bu ağaca oturduğu için çözümlenmiştir. Ardından bağlılık ayrıştırmasıyla anlamsal bilgi çıkarılabilir.

### Aşağıdan yukarı ayrıştırma örneği

- Cümle: "Book that flight."
- "book" hem isim hem fiil sözlüğünde var. Bu bir belirsizliktir.
- Önce "book" isim alınır:
  - "that" belirleyici, "flight" isimdir. `Det Nominal` birleşip NP olur.
  - Geriye "book" (Nominal) ve NP kalır. Bunları birleştirip S yapan bir kural yok.
- "book" fiil alınır:
  - `Verb NP` birleşip VP olur.
  - `S -> VP` kuralı vardır. S'ye ulaşılır. Cümle İngilizcedir.
- Yani belirsizlik ağaçta ilerlerken çözülmüş olur.

### Genişletilmiş geçiş ağları (ATN)

- Ağaç derlemi illa ağaç olarak gösterilmez. Genişletilmiş geçiş ağları da kullanılır (Augmented Transition Network, ATN ya da ATNG).
- Görsel olarak blok şemaya benzer. Dallanan ağaçlara göre daha derli topludur.
- Durumlar öznenin, yüklemin vb. kontrol edildiği yerlerdir. Bir durumdan sonrakine geçmek için soldaki durumun koşulu sağlanmalıdır.
- Slayttaki örnek ağ:

```
q1 --abb--> q2 --ε--> q3 --a--> q4 (final)
q3 --aa--> q1
q1 --b---> q4 (final)
```

- Tanınabilen metinler: "abba", "abbaaabba", "abbaab", "b". Tanınamayanlar: "abbab", "baab".
- "abbaaabba" çözümü:
  - "abb" ile $q_1 \to q_2$, ε ile $q_3$.
  - Burada "a" ile $q_4$ final durumuna gidilirse girdi bitmemiş olur. Bu yol yanlış.
  - "aa" ile $q_1$ durumuna dönülür. Yeniden "abb" ile $q_2$, ε ile $q_3$, "a" ile $q_4$.
  - Hem final durumuna gelinir hem girdi biter. Metin tanınır.
- "baab": "b" ile $q_1 \to q_4$ gidilir. $q_4$ durumundan çıkış yoktur ve girdi bitmemiştir. Metin tanınmaz.

### ATN ile Türkçe cümle örneği: "Ali camı kırdı"

- Token'lara ayrılır ve morfolojik analize gönderilir: "Ali" isim, "cam" isim + "-ı" nesne eki, "kır" fiil + "-dı" zaman eki.
- "kır" kelimesi "çimlik alan" anlamında isim de olabilir. Ağaçta ilerlerken doğrusu anlaşılır.
- Adımlar:
  - İlk okunan öğenin özne olması beklenir. "Ali" isim sözlüğünde var. Özne alt ağı final durumuna gelir. Özne tamam.
  - "camı" kelimesi için iki yol vardır: yüklem ya da nesne.
  - Yüklem yolu: "cam" fiil sözlüğünde yok. Bu yol başarısız olur.
  - Nesne yolu: "cam" isim sözlüğünde, "-ı" nesne ekleri sözlüğünde var. Nesne tamam.
  - "kırdı": "kır" fiil sözlüğünde, "-dı" zaman ekleri sözlüğünde var. Yüklem tamam.
  - Final durumuna gelinir ve girdi biter. Cümle çözümlenmiştir.
- Olasılık kullanımı: Türkçede özneden sonra nesne gelme olasılığı örneğin %80, yüklem gelme olasılığı %15 ise önce nesne yolu denenir. Bu oranlar hocanın verdiği varsayımsal örnektir.
- ATN döngüye (loop) izin verir. Bir ismin önüne kaç sıfat geleceği bilinmez: "yırtık kırmızı büyük top". Her sıfatta aynı duruma dönülür. İsim gelince durulur.

### Tam örnek: cümlenin hiyerarşik yapısı

- Cümle: "Ahmet'in babası beyaz şirin koyunu araba ile köye getirdi."
- Ön işleme: yanlış yazılmış kelimeler düzeltilir ("sirin", "koy" gibi). Noktalama atılır. Türkçe karakter sorunları giderilir.
- Morfolojik analiz kökleri, ekleri ve etiketleri verir.
- Slayttaki etiketler: `<İ>` isim, `<TE>` tamlayan eki, `<TNE>` tamlanan eki, `<S>` sıfat, `<NE>` nesne eki, `<DE>` yönelme (dolaylı tümleç) eki, `<F>` fiil, `<ZE>` zaman eki. "ile" kelimesinin etiketi `<DZ>` olarak verilmiş. Hoca bu kısaltmanın açılımını hatırlamadı.
- Kurallar ve ağaç:

```
Ahmet<İ> in<TE>        -> <T>
baba<İ> sı<TNE>        -> <TN>
<T> <TN>               -> <İG>  -> Özne:          Ahmet'in babası
beyaz<S> şirin<S>      -> <S>
<S> koyun<İ>           -> <SG>
<SG> u<NE>             -> <SN>  -> Nesne:         beyaz şirin koyunu
araba<İ> ile<DZ>       -> <ZT>  -> Zarf tümleci:  araba ile
köy<İG> e<DE>          -> <DT>  -> Dolaylı tümleç: köye
getir<F> di<ZE>        -> <Y>   -> Yüklem:        getirdi
```

- Cümle ağaca oturduğu için öğelerine ayrılmıştır. Bu çıktı anlamsal analize girdi olur.

### Soru cevaplama örneği

- Cümle: "Türkiye'nin başkenti Ankara'dır." Soru: "Türkiye'nin başkenti neresidir?"
- Birinci yol: bağlılık ayrıştırması üzerinden gitmek. Daha zahmetli ve zaman alıcıdır.
- İkinci yol: örüntü (pattern) tabanlı, daha kurallı yöntem.
  - "Nere" sorusu bir yer (location), yani özel isim arar.
  - Aranan özel isim "başkent" kelimesinin yakınında olmalıdır.
  - "Türkiye'nin başkenti Ankara'dır", "Ankara Türkiye'nin başkentidir", "Başkent olan Ankara" gibi cümleler toplanır. Ankara ile başkentin birlikte geçtiği örüntüler çıkarılır.
  - Soru gelince bu örüntülere uyan dokümanlardan cevap çekilir.

### Dil modelleri

- Bilgisayar okuduğunu insan gibi anlayamaz. İnsan kelimenin hangi nesneye karşılık geldiğini bilir. Çok anlamlı kelimenin anlamını bağlamdan çıkarır. Deneyimleriyle kafasında bir model kurar.
- Bilgisayara bu modeller verilmelidir. Bunlardan biri dil modelidir.
- Tanım: bir dildeki kelimelerin sıralanışının olasılık dağılımı, o dilin istatistiksel dil modelidir.
- Karakterlerin ve kelimelerin kullanım sıklıkları ile iki, üç, ..., $n$ kelimenin art arda gelme sıklıkları dil modelini oluşturur.

### Lemma (başsözcük) ve kök farkı

- Lemma, Türkçede başsözcük olarak çevrilir. Sözlükteki madde başı kelimedir. Bundan türetilenlere sözcükbirim denir.
- Örnek: "göz", "gözlük", "gözlükçü". Üçünün de kökü "göz" kelimesidir.
- Köke inilirse anlam kaybolur. "Gözlük" kelimesi gözle ilgili bambaşka bir şeydir. Göz sayılmak istenirse yine hata yapılır.
- Kural: kelime aldığı ekle sözlükte varsa daha fazla köküne inilmez. Buna lemmatization denir.
- İngilizcede durum kolaydır: "read", "reads", "reading" için kök "read" kelimesidir. "-s" ve "-ing" anlamı değiştirmez.
- Türkçede isim soylu bir kelimeye 24 farklı çekim eki, fiil soylu bir kelimeye 46 çekim eki gelebilir. Çekim ekleri anlamı değiştirmez.
- Bütün çekimli hâlleri sözlükte tutmak mantıklı değildir. Bu yüzden ekler ayrılır.
- Türkçede lemma olarak kullanılabilecek yaklaşık 70 bin kelime vardır.

### Dil modellerinin kullanım alanları

- Konuşma tanıma (speech to text): şiveli "celiyorum" yazıya "celiyorum" olarak geçer. Morfolojik analiz bunu çözemez. Dil modeli bunun "geliyorum" olduğunu bulur.
- El yazısı tanıma (handwriting recognition): kâğıda kalemle yazılmış yazıdaki belirsiz harfler (S mi Z mi) dil modeliyle tahmin edilir.
- Yazım düzeltme (spelling correction): klavyede yanlış tuşa basılarak yazılan kelimeler düzeltilir.
- Makine çevirisi (machine translation).
- Optik karakter tanıma (OCR): taranan metin resim olur, OCR onu metne çevirir. "m" harfinin "in", "u" harfinin "ii" okunması, "t" ile "l" harflerinin karışması gibi hatalar görülür. Hocaya göre günümüz OCR araçları çok başarılıdır.
- Woody Allen örneği (slayt):
  - Veznedara "I have a gub" yazan bir not verilir.
  - "gub" İngilizcede anlamlı bir kelime değildir.
  - Aday kelimeler "gun", "gum", "Gus" ve "gull" olabilir.
  - "gun" kelimesinin banka ile ilişki olasılığı daha yüksektir. Bu yüzden "gub", "gun" olarak alınır.
  - Veznedar bunu beden dilinden anlar. Bilgisayar ise dil modeliyle anlar.

### Shannon oyunu

- Bir harf verilir ve sonraki harf tahmin edilir. İlk harf "W" ise İngilizcede kalan 25 harften hangisi gelir?
- Kimse "J" ya da "K" demez. Akla en olası harfler gelir.
- Cümle başında "W" varsa genelde soru kelimesi gelir: "what", "when", "who", "which", "why".
- "Wh" verilince aday harfler "a", "e", "o", "y" olur. 26 harf 4 harfe iner.
- "What" geldikten sonra boşluk gelir. Ardından genelde bir yardımcı fiil gelir.
- Karakter n-gram modeli (character n-gram): harf, kendinden önceki harflere göre tahmin edilir.
- Kelime n-gram modeli (word n-gram): kelime, kendinden önceki kelimelere göre tahmin edilir. Örneğin "what" kelimesinden sonra "do" gelebilir.

### Harf dizilerinde yaklaşım dereceleri

| Derece | Yöntem | Sonuç |
|---|---|---|
| Sıfırıncı derece (zero-order approximation) | Torbadan harfler eşit olasılıkla, birbirinden bağımsız çekilir. | Tamamen anlamsız dizi. |
| Birinci derece (first-order) | Harfler bağımsız ama torbada dildeki sıklıklarına göre bulunur (Scrabble ya da Kelimelik oyunundaki gibi). | Sesli-sessiz dağılımı iyileşir ama hâlâ anlamsız. |
| İkinci derece (second-order) | Her harf, bir önceki harfe göre en olası harf seçilir. | "and", "to be", "best", "dream" gibi kelimeler görünür. |
| Üçüncü derece (third-order) | Her harf, önceki iki harfe göre seçilir. Örneğin "wh" sonrası en olası "e", "he" sonrası "y". | "when", "last", "no", "demonstration", "recognition" gibi kelimeler oluşur. |

- Derece arttıkça çıkan kelimeler dile ait olur. Cümlenin anlamı değil, dilin yapısı yakalanır.
- $n$ değeri teorik olarak sonsuz olabilir ama mantıklı değildir. Pratikte en fazla 20'ye kadar kullanılabileceği gösterilmiştir. 20 kullanan çalışma yoktur.
- Sebep: bir kelimenin geçmişindeki 20 kelimeyle birlikte geçme olasılığı sıfıra çok yakındır. Naive Bayes gibi olasılık çarpan yöntemlerde sonuç neredeyse sıfır olur.

### Romance dillerinde hece örtüşmesi

- Hint-Avrupa dillerinde trigram sıklıklarına bakılmış. İlk sıralarda "ion" gibi ortak trigram'lar çıkmış. Hocaya göre "ion" Türkçede ilk 100 trigram'a bile girmez.
- Sonra Romance dillerinde heceler incelenmiş. Her dilin en sık ilk $k$ hecesinin diğer dillerde de bulunma yüzdesi:

| Dil | 100 | 200 | 300 | 400 | 500 | 561 | Hece türü (type) | Hece sayısı (token) |
|---|---|---|---|---|---|---|---|---|
| Latince | %72 | %86 | %92 | %95 | %98 | %100 | 561 | 3922 |
| Rumence | %63 | %74 | %80 | %84 | %87 | %90 | 1243 | 6591 |
| İtalyanca | %75 | %85 | %91 | %94 | %96 | %97 | 803 | 7937 |
| Portekizce | %69 | %84 | %91 | %95 | %97 | %98 | 693 | 6152 |
| İspanyolca | %73 | %87 | %93 | %96 | %98 | %99 | 672 | 7477 |
| Katalanca | %62 | %77 | %84 | %88 | %92 | %93 | 967 | 5624 |
| Fransızca | %48 | %61 | %67 | %72 | %76 | %78 | 1738 | 5691 |

- Latince hepsiyle örtüşür, çünkü hepsi Latinceden türemiştir.
- İtalyanca, Portekizce ve İspanyolca çok benzer. Bu dillerden birini bilen diğerini kolay anlar ve öğrenir.
- Fransızca diğerlerinden daha farklıdır.

### Zipf yasası

- George Zipf ortaya atmıştır.
- Bir dildeki kelimelerin kullanım sırası ile sıklığı arasında ilişki vardır.
- Bu yalnızca dillerde değil, doğada da geçerlidir: göllerin derinlikleri, dağların yükseklikleri sıralanınca aynı eğri çıkar.
- Örnek: en sık kelime 100 kez geçiyorsa:
  - 2. sıradaki kelime yaklaşık $100/2 = 50$ kez,
  - 3. sıradaki yaklaşık $100/3$ kez,
  - 10. sıradaki yaklaşık $100/10 = 10$ kez geçer.
- Değerler tam değil, yaklaşıktır (50 yerine 47-52 gibi).
- Slayttaki formüller:
  - $n(r) \propto \frac{1}{r^\alpha}$: $r$. sıradaki kelimenin sıklığı. $\alpha$ sabit bir değerdir.
  - $f(n) \propto \frac{1}{n^\gamma}$.
  - $\alpha$ deneme ile bulunur. Her dil için $\alpha$ değerleri zaten çıkarılmıştır.
- Eğrinin bölgeleri:
  - Baştaki bölge: işlevsel sözcükler (stop words): "ve", "veya", "that", "which", "and", "or", "the". Çok sık geçerler.
  - Orta bölge: ana sözcükler.
  - Kuyruk: seyrek kullanılan sözcükler.
- Türkçenin Sıklık Sözlüğü grafiği de aynı eğriyi verir. Diller arasında eğrinin şekli biraz değişir ama hepsi Zipf yasasına uyar.
- Bir dilin derleminde yalnızca karakter sıklıkları sıralansa bile aynı dağılım görülür.

### Cümle olasılığı ve n-gram modeli

- Sıfır-gram (zero-gram) yaklaşımı:
  - Hiçbir kelime bir öncekine bağlı değildir.
  - Sözlük boyutu $V$ (Türkçe için yaklaşık 70 bin) ise her kelimenin olasılığı $1/V$ olur.
  - Cümlenin olasılığı bu değerlerin çarpımıdır. Kelime sayısı arttıkça olasılık hızla küçülür.
  - Aynı cümlenin tekrar gelmesi ancak kopyala-yapıştırla olur. Bu yüzden bu yaklaşımla iş yapılmaz.
- Slayttaki "kesin" yaklaşım: her kelimenin olasılığı frekansına bağlıdır ve diğer kelimelerden bağımsızdır:

$$P(S) = P(w_1) \times P(w_2) \times \dots \times P(w_n)$$

- Slayttaki "en kesin" yaklaşım (n-gram): her kelimenin olasılığı önceki kelimelere bağlıdır.
- Tam geçmişle yazılırsa:

$$P(w_1 w_2 w_3 w_4) = P(w_1) \times P(w_2|w_1) \times P(w_3|w_1 w_2) \times P(w_4|w_1 w_2 w_3)$$

- $P(w_2|w_1)$: $w_2$ kelimesinin $w_1$ kelimesinden sonra gelme olasılığı. $w_2$ başka kelimelerden sonra geliyorsa onların olasılıkları farklıdır.
- Sorun: bazı edebi metinlerde bir cümle bir paragraf kadar uzundur. 50 kelimelik bir cümlede son kelime için 49 kelimelik geçmiş gerekir. Bu mantıklı değildir.
- Bu yüzden $n$ belirlenir. $n = 2$ (bigram) için:

$$P(w_1 w_2 w_3 w_4) \approx P(w_1) \times P(w_2|w_1) \times P(w_3|w_2) \times P(w_4|w_3)$$

- Yani tüm geçmişe değil, yalnızca $n-1$ önceki kelimeye bakılır.

### Sonraki ders ve sınav duyuruları

- Gelecek hafta: Markov modelleri ve örnekler, düzeltme (smoothing) ve belirsizlik giderme algoritması.
- Final sınavı yapılmayacak. Final saatinde öğrenciler projelerinin demosunu gösterecek ve raporlarını drive'a koyacak. Süre yetmezse aynı gün akşam saatlerinde devam edilecek.
- Vize yapılacak. Tarih, üniversitenin sınav modülünü ne zaman açtığına bağlı. Genelde 8. hafta civarı. Hoca değiştirme yetkisi olursa tarihin öğrencilerle birlikte belirleneceğini söyledi.

### Ders sonrası notlar

- Hoca "okuyor" kelimesi için "geniş zaman" dedi. "Okuyor" şimdiki zamandır. Geniş zaman hâli "okur" olur.
- "Çocuk evde oyun oynarken televizyon izliyor" örneğinde hoca "ortak nesnem çocuk" dedi. Doğrusu "çocuk" kelimesinin iki tümcenin ortak öznesi olmasıdır.
- Hoca Fince, Çince ve İngilizceyi birlikte gösterip "Hint-Avrupa dilleri galiba" dedi. Bu üçünden yalnızca İngilizce Hint-Avrupa dilidir. Fince Ural (Fin-Ugor) ailesinden, Çince Çin-Tibet ailesindendir. Japonca ve Korecenin Altay ailesine bağlanması da dilbilimde tartışmalıdır.
- Slaytta $\gamma = 1 + \frac{1}{n^\alpha}$ yazıyor. Zipf yasasının literatürdeki bilinen biçiminde bu ilişki $\gamma = 1 + \frac{1}{\alpha}$ şeklindedir. Slayttaki ifade büyük olasılıkla yazım hatasıdır.
- Altyazıda Woody Allen örneği "I have gap" olarak geçiyor. Slayttaki doğru örnek "I have a gub" ifadesidir.
- Altyazıda "Romanca" geçen dil, slayttaki tabloda "Romanian" yani Rumencedir.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
